// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 217: a hint from compare/tumap.py.
// Helpers behind the SIDL "EQType" labels and gauges: GetLabelFromEQ fills a label's text for its EQType
// number and GetGaugeValueFromEQ a gauge's fill (0-1000, tenths of a percent); plus the UI ini paths, the
// window-button tooltips and target selection by gauge type.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"

typedef int (__stdcall *ShellExecuteA_guess)(void*, const char*, const char*,
    const char*, const char*, int);

struct WindowManager_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 WindowManager_guess::IsReady_guess
    unsigned char IsReady_guess();
};

struct TextTarget_guess {
};

struct Str_guess {
    int p;
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text);
    ~Str_guess();
};

struct ModeManager_guess {
    // EXTERNAL: TITANIUM 0x00564E7E ModeManager_guess::Apply
    void Apply(TextTarget_guess* target, int mode);
};

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060E450_guess
void __cdecl FUN_0060E450_guess(const char* first_guess,
    const char* second_guess);

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(int target_guess, const char* text_guess,
    ...);

// EXTERNAL: TITANIUM 0x00438BA7 GetUserDefinedColor
unsigned int __cdecl GetUserDefinedColor(int index_guess);

struct TextProcessor_guess {
    // EXTERNAL: TITANIUM 0x00571FC0 TextProcessor_guess::Process_guess
    void Process_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x004482FB TextProcessor_guess::Clear_guess
    void Clear_guess();
};

struct Selected_guess;

struct Buff_guess {
    int pad_00000_guess;
    int spell_4_guess;
};

struct Spell_guess {
    char pad_00000_guess[0x208];
    const char* name_208_guess;
};

struct DataInner_guess {
    // EXTERNAL: TITANIUM 0x0041B016 DataInner_guess::GetValue_guess
    int GetValue_guess();

    // EXTERNAL: TITANIUM 0x0041EAB3 DataInner_guess::compute_tohit_guess
    int compute_tohit_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041EBB3 DataInner_guess::offense_guess
    int offense_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040EBC3 DataInner_guess::SpellDuration_guess
    int SpellDuration_guess(int a_guess, int b_guess, int c_guess);

    // EXTERNAL: TITANIUM 0x0040E7AC DataInner_guess::GetBuff_guess
    Buff_guess* GetBuff_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00419631 DataInner_guess::KunarkClass_guess
    const char* KunarkClass_guess(int a_guess, int b_guess, int c_guess,
        int d_guess);
    // EXTERNAL: TITANIUM 0x00417BCF DataInner_guess::GetBonus_guess
    int GetBonus_guess(int kind_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00418C4F DataInner_guess::basesave_poison_guess
    int basesave_poison_guess();
    // EXTERNAL: TITANIUM 0x00418A40 DataInner_guess::basesave_disease_guess
    int basesave_disease_guess();
    // EXTERNAL: TITANIUM 0x00418756 DataInner_guess::basesave_fire_guess
    int basesave_fire_guess();
    // EXTERNAL: TITANIUM 0x004188EF DataInner_guess::basesave_cold_guess
    int basesave_cold_guess();
    // EXTERNAL: TITANIUM 0x00418608 DataInner_guess::basesave_magic_guess
    int basesave_magic_guess();
    // EXTERNAL: TITANIUM 0x00417E07 DataInner_guess::Cur_HP
    int Cur_HP(int flag_guess);
    // EXTERNAL: TITANIUM 0x00416963 DataInner_guess::Max_HP_guess
    int Max_HP_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x004106A3 DataInner_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int kind_guess, int a_guess, int b_guess,
        int c_guess);
    // EXTERNAL: TITANIUM 0x00417EE7 DataInner_guess::Cur_Mana_guess
    int Cur_Mana_guess();
    // EXTERNAL: TITANIUM 0x00417E67 DataInner_guess::Cur_Endurance_guess
    int Cur_Endurance_guess();
    // EXTERNAL: TITANIUM 0x00416A40 DataInner_guess::Max_Endurance
    int Max_Endurance();
    // EXTERNAL: TITANIUM 0x004C9C1E DataInner_guess::GetLimit_guess
    int GetLimit_guess();

    virtual int Slot0_guess();
    virtual int Slot1_guess();
    virtual int GetMaxB_guess();

    int pad_00004_guess;
    Selected_guess* current_c288_guess;
    int pad_0000c_guess;
    int value_c290_guess;
    int value_c294_guess;
    int value_c298_guess;
    int value_c29c_guess;
    int value_c2a0_guess;
    int value_c2a4_guess;
    int value_c2a8_guess;
    int value_c2ac_guess;
    int value_c2b0_guess;
    int value_c2b4_guess;
    int value_c2b8_guess;
    int value_c2bc_guess;
    int value_c2c0_guess;
    int pad_c2c4_guess;
    int value_c2c8_guess;
};

struct RecordState_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 RecordState_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E1640 RecordState_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 RecordState_guess::GetItemType_guess
    int GetItemType_guess();
};

struct Record_guess {
    char pad_00000_guess[0x34];
    RecordState_guess* state_00034_guess;
};

struct RecordAccessor_guess {
    // EXTERNAL: TITANIUM 0x005EC220 RecordAccessor_guess::GetCharInfo2
    int* GetCharInfo2();
};

struct RecordPrefix_guess {
    int pad_00000_guess;
};

struct RecordSlot_guess : RecordPrefix_guess, RecordAccessor_guess {
    // EXTERNAL: TITANIUM 0x0040E705 RecordSlot_guess::GetMemorizedSpell_guess
    int GetMemorizedSpell_guess(int gem_guess);

    Record_guess* GetSelectedRecord_guess() {
        int* words_guess = GetCharInfo2();
        words_guess += 4;
        return (Record_guess*)words_guess;
    }
};

#include "titanium/layouts/core.h"


struct Entry_guess {
    int pad_00000_guess;
    int id_4_guess;
    int value_8_guess;
};

struct LookupTable_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 LookupTable_guess::GetSpell_guess
    int GetSpell_guess(int index_guess);
};

struct RecordValue_guess {
    char pad_00000_guess[0x11a4];
    int level_11a4_guess;
    char pad_011a8_guess[4];
    int value_11ac_guess;
    char pad_011b0_guess[4];
    int str_11b4_guess;
    int sta_11b8_guess;
    int cha_11bc_guess;
    int dex_11c0_guess;
    int intel_11c4_guess;
    int agi_11c8_guess;
    int wis_11cc_guess;
};

struct NamedSlot_guess {
    char pad_00000_guess[0x3c];
    char name_3c_guess[0x40];
    char name_7c_guess[0x40];
};

struct DataOwner_guess {
    char pad_00000_guess[8];
    VBPtr lookup_00008_guess;
    char pad_0000c_guess[0xe1c];
    unsigned int value_e28_guess;
    char pad_0e2c_guess;
    unsigned char value_e2d_guess;
    char pad_0e2e_guess[2];
    int value_e30_guess;
    char pad_0e34_guess[0x1c];
    unsigned int time_e50_guess;
    char pad_0e54_guess[0x1c];
    int time_e70_guess;
    int pad_0e74_guess;
    __int64 value_e78_guess;
    __int64 value_e80_guess;
    char pad_0e88_guess[8];
    double value_e90_guess;
    double value_e98_guess;
    char pad_0ea0_guess[0xb70];
    __int64 value_1a10_guess;
    char pad_1a18_guess[0xa868];
    DataInner_guess inner_c280_guess;

    // EXTERNAL: TITANIUM 0x004BB039 DataOwner_guess::IsUsingDiscipline_guess
    char IsUsingDiscipline_guess();
    // EXTERNAL: TITANIUM 0x004BB01D DataOwner_guess::GetEntry_guess
    Entry_guess* GetEntry_guess();
    // EXTERNAL: TITANIUM 0x005ED4B0 DataOwner_guess::GetDeity_guess
    int GetDeity_guess();
    // EXTERNAL: TITANIUM 0x005ED730 DataOwner_guess::GetValue5870_guess
    int GetValue5870_guess();
    // EXTERNAL: TITANIUM 0x004BC3BF DataOwner_guess::MaxAirSupply_guess
    int MaxAirSupply_guess();

    RecordSlot_guess* CurrentRecordSlot_guess() {
        return (RecordSlot_guess*)((char*)&lookup_00008_guess
            + lookup_00008_guess.table->vbase_offset);
    }
    RecordValue_guess* CurrentValues_guess() {
        return (RecordValue_guess*)CurrentRecordSlot_guess()->GetCharInfo2();
    }
};

struct ProgressData_guess;

struct ValueManager_guess {
    char pad_00000_guess[0x1A8];
    ProgressData_guess* data_01a8_guess;

    // EXTERNAL: TITANIUM 0x00479D99 ValueManager_guess::Adjust_guess
    unsigned char Adjust_guess(int value_guess);
};

struct ClientState_guess {
    char pad_00000_guess[0x39ab8];
    char enabled_guess;
    char pad_39ab9_guess;
    char address_39aba_guess;
    char pad_39abb_guess[0x1ff];
    char address_39cba_guess;
    char pad_39cbb_guess[0x1ff];
    char address_39eba_guess;

    // EXTERNAL: TITANIUM 0x004AE865 ClientState_guess::ReadDefaults_guess
    void ReadDefaults_guess(int a1_guess, int a2_guess, int a3_guess,
        int a4_guess, int a5_guess, int a6_guess);
    // EXTERNAL: TITANIUM 0x004AE8D9 ClientState_guess::UpdateDefaults_guess
    int UpdateDefaults_guess(int a1_guess, int a2_guess, int a3_guess,
        int a4_guess);
    // EXTERNAL: TITANIUM 0x0049275D ClientState_guess::GetDeityDesc
    const char* GetDeityDesc(int class_guess);
    // EXTERNAL: TITANIUM 0x00492EC2 ClientState_guess::GetDisplayName_guess
    const char* GetDisplayName_guess(const char* name_guess);
};

struct Display_guess {
    char pad_0000_guess[0x68];
    int value_68_guess;
    char pad_006c_guess[0x100];
    int id_16c_guess;
    char pad_0170_guess[0x28];
    Selected_guess* selected_198_guess;
    char pad_019c_guess[0x1c];
    unsigned char flag_1b8_guess;
    char pad_01b9_guess[0xdd7];
    int value_f90_guess;
    int pad_0f94_guess;
    int spell_f98_guess;
};

struct Selected_guess {
    unsigned char value_0000_guess;
    unsigned char value_0001_guess;
    char pad_0002_guess[0x11e];
    char name_120_guess[0x88];
    Display_guess* display_1a8_guess;
    char pad_01ac_guess[0x98];
    unsigned char type_244_guess;
    char pad_0245_guess[0xd];
    unsigned char playerClass_0252_guess;
    char pad_0253_guess[5];
    int id_258_guess;
    char pad_025c_guess[0x18];
    int hp_274_guess;
    char pad_0278_guess[0xc];
    int max_hp_284_guess;
    char pad_0288_guess[0x1c];
    char name_2a4_guess[0x40];

    // EXTERNAL: TITANIUM 0x004793B5 Selected_guess::GetName_guess
    const char* GetName_guess();
};

struct Timer_guess {
    // EXTERNAL: TITANIUM 0x004C5EA1 Timer_guess::IsRunning_guess
    int IsRunning_guess();
    // EXTERNAL: TITANIUM 0x004C5EA9 Timer_guess::GetTrackLength_guess
    int GetTrackLength_guess();
    // EXTERNAL: TITANIUM 0x004C5EB1 Timer_guess::GetTrackPosition_guess
    int GetTrackPosition_guess();
    // EXTERNAL: TITANIUM 0x004C5EDF Timer_guess::GetIndex_guess
    int GetIndex_guess();
    // EXTERNAL: TITANIUM 0x004C5EC1 Timer_guess::GetName_guess
    const char* GetName_guess(int index_guess);
};

struct Counter_guess {
    // EXTERNAL: TITANIUM 0x00435150 Counter_guess::GetCount_guess
    int GetCount_guess();
};

struct Counter2_guess {
    // EXTERNAL: TITANIUM 0x0040B27A Counter2_guess::GetCount_guess
    int GetCount_guess();
};

struct Clock_guess {
    char pad_0000_guess[0x148];
    unsigned int time_148_guess;
    // EXTERNAL: TITANIUM 0x00556B72 Clock_guess::GetSpellMemTicksLeft_guess
    int GetSpellMemTicksLeft_guess();
    // EXTERNAL: TITANIUM 0x0055697D Clock_guess::GetSpellScribeTicksLeft_guess
    int GetSpellScribeTicksLeft_guess();
};

struct ClearAt78_guess {
    char pad_0000_guess[0xf0];
    int value_f0_guess;
};

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CPetInfoWnd.h"
#include "titanium/wnd/CRespawnWnd.h"
#include "titanium/wnd/CSpellBookWnd.h"

#include "titanium/core_decls.h"
#define gDataOwner_guess EQ_GLOBAL(DataOwner_guess*, 0x00905D00)
#define gValueManager_guess EQ_GLOBAL(ValueManager_guess*, 0x00905CE4)
#define gFirstValue_guess EQ_GLOBAL(int, 0x0092379C)
#define gSecondValue_guess EQ_GLOBAL(int, 0x009237A0)
#define pinstCTipWndCONTEXT_guess EQ_GLOBAL(ModeManager_guess*, 0x009928E0)
#define gModeEnabled_guess EQ_GLOBAL(unsigned char, 0x009254ED)
#define gClientState_guess EQ_GLOBAL(ClientState_guess*, 0x00988DF0)
#define gWindowManager_guess EQ_GLOBAL(WindowManager_guess*, 0x00850C38)
#define gCurrentTarget_guess EQ_GLOBAL(Selected_guess*, 0x00905D04)
#define gDefaultTarget_guess EQ_GLOBAL(Selected_guess*, 0x00905CE4)
#define gTargetNames_guess EQ_ARRAY(MenuEntry_guess, 0x0090424D)
#define gTargetRecords_guess EQ_ARRAY(Selected_guess*, 0x00904390)
#define gLookupTable_guess EQ_GLOBAL(LookupTable_guess*, 0x00985CC8)

// EXTERNAL: TITANIUM 0x004C94AE FUN_004C94AE_guess
ClearAt78_guess* __cdecl FUN_004C94AE_guess();

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401B28_guess
Selected_guess* __cdecl FUN_00401B28_guess(int id_guess);

// EXTERNAL: TITANIUM 0x0044D0D0 IsSpellValid_guess
char __cdecl IsSpellValid_guess(int spell_guess);

// Attack rating for the inventory window: two skill-based terms * 1000 / 744, for the primary weapon's skill
// or
// skill 28 (hand to hand) when nothing usable is in hand.
// FUNCTION: TITANIUM 0x00559EB4
int __cdecl GetDisplayATK_guess() {
    int first_guess;
    int second_guess;
    if (gValueManager_guess != 0
        && gDataOwner_guess->CurrentRecordSlot_guess()
            ->GetSelectedRecord_guess()->state_00034_guess != 0
        && gDataOwner_guess->CurrentRecordSlot_guess()
            ->GetSelectedRecord_guess()->state_00034_guess
                ->GetItemClass_guess() == 0
        && gDataOwner_guess->CurrentRecordSlot_guess()
            ->GetSelectedRecord_guess()->state_00034_guess
                ->IsReady_guess() != 0) {
        int value_guess = gValueManager_guess->Adjust_guess(
            gDataOwner_guess->CurrentRecordSlot_guess()
                ->GetSelectedRecord_guess()->state_00034_guess
                ->GetItemType_guess());
        first_guess = gDataOwner_guess->inner_c280_guess
            .compute_tohit_guess(value_guess);
        second_guess = gDataOwner_guess->inner_c280_guess
            .offense_guess(value_guess);
    } else {
        DataInner_guess* inner_guess = &gDataOwner_guess->inner_c280_guess;
        first_guess = inner_guess->compute_tohit_guess(0x1C);
        second_guess = gDataOwner_guess->inner_c280_guess
            .offense_guess(0x1C);
    }
    return (first_guess + second_guess) * 1000 / 0x2E8;
}

// Opens a file or URL with the shell ("open", SW_SHOW).
// FUNCTION: TITANIUM 0x005591B1
void __cdecl OpenWithShell_guess(const char* file_guess) {
    EQ_GLOBAL(ShellExecuteA_guess, 0x0063F230)(
        EQ_GLOBAL(void*, 0x00923770), "open", file_guess, 0,
        EQ_ARRAY(char, 0x0063F53F), 5);
}

// Whether the bank window (0x850C38) exists and is open (0x0059DD30). A slot window holding a bank or
// shared-bank slot (ids 2000-2499) is enabled only while it is.
// FUNCTION: TITANIUM 0x005591D0
unsigned char __cdecl GetBankWndFlag04_guess() {
    WindowManager_guess* manager_guess = gWindowManager_guess;
    unsigned char result_guess = 0;
    if (manager_guess != 0) {
        result_guess = manager_guess->IsReady_guess();
    }
    return result_guess;
}

// Click on a gauge or label of type `kind_guess`: 1 targets yourself, 11-15 group members, 16 your pet,
// 17-21 group members' pets, 27 sends OP_TargetCommand for your target's target. The previous target is
// remembered for /target last (+0xF0 of 0x4C94AE).
// FUNCTION: TITANIUM 0x005591E2
void __cdecl SelectGaugeTarget_guess(int kind_guess) {
    Selected_guess* record_guess = 0;
    switch (kind_guess) {
    case 1:
        if (gDefaultTarget_guess != 0) {
            if (gCurrentTarget_guess != 0) {
                int value_guess = gCurrentTarget_guess->id_258_guess;
                FUN_004C94AE_guess()->value_f0_guess = value_guess;
            }
            gCurrentTarget_guess = gDefaultTarget_guess;
        }
        return;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15: {
        int index_guess = kind_guess - 11;
        if (&gTargetNames_guess[index_guess] != 0) {
            if (gTargetRecords_guess[index_guess] != 0) {
                if (gCurrentTarget_guess != 0) {
                    int value_guess = gCurrentTarget_guess->id_258_guess;
                    FUN_004C94AE_guess()->value_f0_guess = value_guess;
                }
                gCurrentTarget_guess = gTargetRecords_guess[index_guess];
                if (gDefaultTarget_guess != 0
                    && gDefaultTarget_guess->display_1a8_guess != 0) {
                    gDefaultTarget_guess->display_1a8_guess->value_f90_guess =
                        index_guess;
                }
            } else {
                gCurrentTarget_guess = 0;
            }
        }
        return;
    }
    case 16:
        record_guess = gDataOwner_guess->inner_c280_guess.current_c288_guess;
        break;
    case 17:
    case 18:
    case 19:
    case 20:
    case 21: {
        int index_guess = kind_guess - 17;
        if (gTargetNames_guess[index_guess].text_guess[0] == 0) {
            return;
        }
        record_guess = gTargetRecords_guess[index_guess];
        break;
    }
    case 27:
        if (gDefaultTarget_guess != 0
            && gDefaultTarget_guess->display_1a8_guess != 0
            && gDefaultTarget_guess->display_1a8_guess->selected_198_guess
                != 0) {
            int value_guess = gDefaultTarget_guess->display_1a8_guess
                ->selected_198_guess->id_258_guess;
            EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_TargetCommand,
                &value_guess, 4, 1);
        }
        return;
    }
    if (record_guess != 0) {
        Display_guess* display_guess = record_guess->display_1a8_guess;
        if (display_guess != 0) {
            int id_guess = display_guess->id_16c_guess;
            if (id_guess != -1) {
                Selected_guess* resolved_guess = FUN_00401B28_guess(id_guess);
                if (resolved_guess != 0) {
                    if (gCurrentTarget_guess != 0) {
                        int value_guess = gCurrentTarget_guess->id_258_guess;
                        FUN_004C94AE_guess()->value_f0_guess = value_guess;
                    }
                    gCurrentTarget_guess = resolved_guess;
                }
            }
        }
    }
}

// AC for the inventory window: (AC + bonus) * 1000 / 847.
// FUNCTION: TITANIUM 0x00559396
int __cdecl GetDisplayAC_guess() {
    DataOwner_guess* owner_guess = gDataOwner_guess;
    int stored_guess = owner_guess->inner_c280_guess.value_c2ac_guess;
    int current_guess = owner_guess->inner_c280_guess.GetValue_guess();
    return (current_guess + stored_guess) * 1000 / 0x34F;
}

// Stat colour: grey when equal to the base, green above, red below.
// FUNCTION: TITANIUM 0x005593BF
int __cdecl getComparisonColor_guess(int first_guess, int second_guess) {
    if (first_guess == second_guess) {
        return 0xFFC0C0C0;
    }
    return (first_guess > second_guess) ? 0xFF00FF00 : 0xFFFF0000;
}

// Prints a stat (capped at `limit_guess` unless -9999), caches it in `output_guess` and, when asked, colours
// it against `comparison_guess`.
// FUNCTION: TITANIUM 0x005593E8
char __cdecl updateStatValueWithColorCoding_guess(int* output_guess, int value_guess,
    int comparison_guess, int target_guess, char set_result_guess,
    int* result_guess, int limit_guess) {
    if (limit_guess != -9999 && value_guess > limit_guess) {
        value_guess = limit_guess;
    }
    FUN_005738b0_guess(target_guess, EQ_ARRAY(char, 0x0063F53C),
        value_guess);
    if (set_result_guess != 0) {
        *result_guess = getComparisonColor_guess(value_guess, comparison_guess);
    }
    *output_guess = value_guess;
    return 1;
}

// Copies the text into the label cache, then into the label.
// FUNCTION: TITANIUM 0x00559431
char __cdecl SetLabelText_guess(const char* first_guess,
    const char* second_guess, TextProcessor_guess* processor_guess,
    char* result_guess, int* color_guess) {
    FUN_0060E450_guess(first_guess, second_guess);
    processor_guess->Process_guess(first_guess);
    *result_guess = 0;
    return 1;
}

// Colour for a chat colour index: indexes over 255 are user colours (BGR swapped to ARGB, unset = 0xF0F0F0);
// the rest a fixed table, dark grey by default.
// FUNCTION: TITANIUM 0x00559456
unsigned int __cdecl convertColorIndex_guess(int index_guess) {
    if (index_guess > 0xFF) {
        unsigned int color_guess =
            GetUserDefinedColor(index_guess - 0x100);
        if (color_guess == 0) {
            color_guess = 0xF0F0F0;
        }
        return ((color_guess & 0xFF) << 16) | (color_guess & 0xFF00)
            | ((color_guess >> 16) & 0xFF) | 0xFF000000;
    }
    switch (index_guess) {
    case 0:
        return 0xFFF0F0F0;
    case 2:
        return 0xFF008000;
    case 4:
        return 0xFF000080;
    case 5:
        return 0xFFF000F0;
    case 6:
        return 0xFF808080;
    case 7:
        return 0xFFE0E0E0;
    case 10:
        return 0xFFF0F0F0;
    case 12:
        return 0xFFA0A0A0;
    case 13:
        return 0xFFF00000;
    case 14:
        return 0xFF00F000;
    case 15:
        return 0xFFF0F000;
    case 16:
        return 0xFF0000F0;
    case 18:
        return 0xFF00F0F0;
    case 20:
        return 0xFF000000;
    default:
        return 0xFF606060;
    }
}

// Inventory slot manager (0x850CB8): makes or reuses the slot object for slot window `argument`
// (0x0051A730). A slot window with a slot id calls it on creation (0x0051B649).
// FUNCTION: TITANIUM 0x00559535
int __cdecl CreateInvSlot_guess(int argument_guess) {
    return pinstCInvSlotMgr_guess->Add_guess(argument_guess);
}

// The character's UI ini (UI_<name>_<server>.ini), or null before login.
// FUNCTION: TITANIUM 0x00559545
unsigned int __cdecl NewUIINI() {
    ClientState_guess* state_guess = gClientState_guess;
    return state_guess->enabled_guess
        ? (unsigned int)&state_guess->address_39aba_guess
        : 0U;
}

// The character ini (<name>_<server>.ini), or null before login.
// FUNCTION: TITANIUM 0x0055955C
unsigned int __cdecl GetCustomIniFilename_guess() {
    ClientState_guess* state_guess = gClientState_guess;
    return state_guess->enabled_guess
        ? (unsigned int)&state_guess->address_39cba_guess
        : 0U;
}

// The Abilities_<name>_<server>.ini path, or null before login.
// FUNCTION: TITANIUM 0x00559573
unsigned int __cdecl GetAbilitiesIniFilename_guess() {
    ClientState_guess* state_guess = gClientState_guess;
    return state_guess->enabled_guess
        ? (unsigned int)&state_guess->address_39eba_guess
        : 0U;
}

// LoadStringFromUIIniFile: once the character's UI ini exists (0x00559545), reads a string setting
// through pEverQuest (0x004AE865: defaults.ini, overridden by the character ini when the last argument
// is set). Windows restore their INI settings with it.
// FUNCTION: TITANIUM 0x0055958A
void __cdecl LoadStringFromUIIniFile_guess(int a1_guess, int a2_guess, int a3_guess,
    int a4_guess, int a5_guess, int a6_guess) {
    if (NewUIINI()) {
        gClientState_guess->ReadDefaults_guess(a1_guess, a2_guess, a3_guess,
            a4_guess, a5_guess, a6_guess);
    }
}

// LoadIntFromUIIniFile: once the character's UI ini exists (0x00559545), reads an integer setting
// through pEverQuest (0x004AE8D9); 0 before that. Used for [Main] MaxItemDisplays and by the window
// library.
// FUNCTION: TITANIUM 0x005595B5
int __cdecl LoadIntFromUIIniFile_guess(int a1_guess, int a2_guess, int a3_guess,
    int a4_guess) {
    if (!NewUIINI()) {
        return 0;
    }
    return gClientState_guess->UpdateDefaults_guess(a1_guess, a2_guess,
        a3_guess, a4_guess);
}

// Writes the cached screen width and height (0x92379C, 0x9237A0; set when the display starts) to
// `first` and `second`. The cascade menus keep themselves on screen with it.
// FUNCTION: TITANIUM 0x005595DB
void __cdecl GetEQScreenRes_guess(int* first_guess, int* second_guess) {
    *first_guess = gFirstValue_guess;
    *second_guess = gSecondValue_guess;
}

// Tooltip strings for the window title-bar buttons: 6612 "Close this window".
// FUNCTION: TITANIUM 0x005595F4
Str_guess __cdecl GetCloseTextString_guess() {
    return pStringTable->getString(0x19D4, 0);
}

// 3372 "Click for help about this window."
// FUNCTION: TITANIUM 0x0055961C
Str_guess __cdecl GetHelpTextString_guess() {
    return pStringTable->getString(0x0D2C, 0);
}

// 6614 "Minimize this window".
// FUNCTION: TITANIUM 0x00559644
Str_guess __cdecl GetMinimizeTextString_guess() {
    return pStringTable->getString(0x19D6, 0);
}

// 6613 "Restore this window".
// FUNCTION: TITANIUM 0x0055966C
Str_guess __cdecl GetRestoreTextString_guess() {
    return pStringTable->getString(0x19D5, 0);
}

// Returns the [Main] ContextMenus setting (0x9254ED, read from eqclient.ini). The window library checks
// it before opening a right-click menu.
// FUNCTION: TITANIUM 0x00559694
unsigned char __cdecl GetModeEnabled_guess() {
    return gModeEnabled_guess;
}

// Shows context tip `target` in the tip window (0x9928E0, mode 1; 0x00564E7E) when that window exists.
// Called from the window library.
// FUNCTION: TITANIUM 0x0055969A
void __cdecl ApplyMode_guess(TextTarget_guess* target) {
    ModeManager_guess* manager = pinstCTipWndCONTEXT_guess;
    if (manager != 0) {
        manager->Apply(target, 1);
    }
}

struct ProgressDuration_guess {
    // EXTERNAL: TITANIUM 0x005E0D70 ProgressDuration_guess::GetDuration_guess
    unsigned int GetDuration_guess();
};

struct ProgressContext_guess {
    // EXTERNAL: TITANIUM 0x004B76A6 ProgressContext_guess::GetInventorySlot_guess
    ProgressDuration_guess** GetInventorySlot_guess(DataInner_guess* context_guess);
};

struct ProgressData_guess {
    char pad_00000_guess[0xD8];
    unsigned int value_000d8_guess;
    char pad_000dc_guess[0xF98 - 0xDC];
    int castingSpellId_00f98_guess;
    char pad_00f9c_guess[0x1048 - 0xF9C];
    ProgressDuration_guess* duration_01048_guess;
    int pad_0104c_guess;
    ProgressContext_guess context_01050_guess;
};

struct ProgressEntry_guess {
    char pad_00000_guess[0x14];
    unsigned int value_00014_guess;
};

struct ProgressLookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 ProgressLookup_guess::GetEntry_guess
    ProgressEntry_guess* GetEntry_guess(int value_guess);
};


struct ProgressStateList_guess {
    // EXTERNAL: TITANIUM 0x005EC220 ProgressStateList_guess::GetCharInfo2
    ModeContext_guess* GetCharInfo2();
};

struct ProgressTarget_guess {
    char pad_00000_guess[4];
    ProgressStateList_guess state_004_guess;
};

#define gProgressLookup_guess EQ_GLOBAL(ProgressLookup_guess*, 0x00985CC8)

// Casting bar fill: the time left of the current cast over its cast time, 0-1000; -1 when not casting.
// FUNCTION: TITANIUM 0x005596B0
// @early-stop: budget, diff ndiff=62
unsigned int __cdecl GetCastingProgress_guess() {
    unsigned int result_guess = 0xFFFFFFFF;
    do {
        if (gValueManager_guess == 0) {
            break;
        }
        if (!IsSpellValid_guess(
                gValueManager_guess->data_01a8_guess->castingSpellId_00f98_guess)) {
            break;
        }
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            break;
        }
        ProgressEntry_guess* entry_guess = gProgressLookup_guess->GetEntry_guess(
            gValueManager_guess->data_01a8_guess->castingSpellId_00f98_guess);
        if (entry_guess == 0) {
            break;
        }
        ProgressTarget_guess* target_guess =
            (ProgressTarget_guess*)owner_guess->CurrentRecordSlot_guess();
        ModeContext_guess* context_guess =
            target_guess->state_004_guess.GetCharInfo2();
        if (context_guess->class_119c_guess == 8
            && gValueManager_guess->data_01a8_guess->value_000d8_guess == 0) {
            break;
        }
        if (EQ_GLOBAL(Clock_guess*, 0x00905D24)->time_148_guess
            > gValueManager_guess->data_01a8_guess->value_000d8_guess) {
            break;
        }
        if (entry_guess->value_00014_guess == 0
            && gValueManager_guess->data_01a8_guess->duration_01048_guess == 0) {
            break;
        }
        unsigned int duration_guess;
        if (gValueManager_guess->data_01a8_guess->duration_01048_guess == 0) {
            duration_guess = entry_guess->value_00014_guess;
        } else if (gValueManager_guess->data_01a8_guess->context_01050_guess
                .GetInventorySlot_guess(gDataOwner_guess
                    ? &gDataOwner_guess->inner_c280_guess : 0) != 0
            && gValueManager_guess->data_01a8_guess->duration_01048_guess
                == *gValueManager_guess->data_01a8_guess->context_01050_guess
                    .GetInventorySlot_guess(gDataOwner_guess
                        ? &gDataOwner_guess->inner_c280_guess : 0)) {
            duration_guess = gValueManager_guess->data_01a8_guess
                ->duration_01048_guess->GetDuration_guess();
        } else {
            duration_guess = entry_guess->value_00014_guess;
        }
        if ((int)duration_guess <= 0) {
            break;
        }
        result_guess = (gValueManager_guess->data_01a8_guess
            ->value_000d8_guess
            - EQ_GLOBAL(Clock_guess*, 0x00905D24)->time_148_guess) * 1000
            / duration_guess;
        if ((int)result_guess < 0) {
            result_guess = 0;
        }
        if ((int)result_guess > 1000) {
            result_guess = 1000;
        }
    } while (0);
    return result_guess;
}

// Gauge 25: the buff entry's remaining ticks (+8) over that spell's full duration (formula 0x0040EBC3 at
// the character's level), 0-1000.
// FUNCTION: TITANIUM 0x00559838
int __cdecl GetDisciplineGaugeValue_guess() {
    if (gDataOwner_guess->IsUsingDiscipline_guess()) {
        Entry_guess* entry_guess = gDataOwner_guess->GetEntry_guess();
        if (entry_guess != 0) {
            int count_guess = gLookupTable_guess->GetSpell_guess(
                entry_guess->id_4_guess);
            if (count_guess != 0) {
                RecordSlot_guess* slot_guess =
                    gDataOwner_guess->CurrentRecordSlot_guess();
                int* record_guess = slot_guess->GetCharInfo2();
                int value_guess =
                    ((RecordValue_guess*)record_guess)->level_11a4_guess;
                int rate_guess = gDataOwner_guess->inner_c280_guess.SpellDuration_guess(
                    count_guess, value_guess, 0);
                if (rate_guess * 6 > 0) {
                    return (entry_guess->value_8_guess * 6000) / (rate_guess * 6);
                }
            }
        }
    }
    return 0;
}

// Gauge fill by type: 1 HP (also sets the name text), 2 mana, 3 endurance, 4 experience, 5 AA experience,
// 6 target HP, 7 casting, 11-15 group HP, 16-21 pets' HP, 27 target's target, 28 a countdown. Results are
// clamped to -110..1000; -1 hides the gauge, -2 means no data, -3 a non-HP target.
// FUNCTION: TITANIUM 0x005598BC
// @early-stop: unknown, structural ndiff=354
int __cdecl GetGaugeValueFromEQ(unsigned int kind_guess, int target_guess,
    char* output_guess) {
    int maximum_guess = 1000;
    int result_guess;
    // Cases are kind - 1. Ratios come out on a 0-1000 scale: value / (max * 0.001). The local player
    // is the spawn at 0x00905CE4.
    switch (kind_guess - 1) {
    case 0: {
        Selected_guess* selected_guess =
            EQ_GLOBAL(Selected_guess*, 0x00905CE4);
        if (gDataOwner_guess == 0 || selected_guess == 0) {
            return -2;
        }
        int first_guess = gDataOwner_guess->inner_c280_guess.Cur_HP(
            selected_guess->type_244_guess);
        int second_guess = gDataOwner_guess->inner_c280_guess.Max_HP_guess(
            selected_guess->type_244_guess);
        result_guess = (int)((float)first_guess
            / ((float)second_guess * EQ_GLOBAL(float, 0x00641088)));
        if (selected_guess->value_0001_guess != 0) {
            FUN_005738b0_guess(target_guess, "%s\n%s",
                selected_guess->name_120_guess,
                &selected_guess->value_0001_guess);
        } else {
            FUN_005738b0_guess(target_guess, "%s",
                selected_guess->name_120_guess);
        }
        break;
    }
    case 1: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        int first_guess = owner_guess->inner_c280_guess.Cur_Mana_guess();
        int second_guess = owner_guess->inner_c280_guess.GetMaxB_guess();
        // No max mana: casting classes (2-6, 8, 10-15) show an empty bar; Warrior, Monk, Rogue and
        // Berserker (1, 7, 9, 16) get -1, no gauge.
        if ((float)second_guess > EQ_GLOBAL(float, 0x0063F4CC)) {
            result_guess = (int)((float)first_guess
                / ((float)second_guess * EQ_GLOBAL(float, 0x00641088)));
        } else {
            Selected_guess* selected_guess =
                EQ_GLOBAL(Selected_guess*, 0x00905CE4);
            if (selected_guess == 0) {
                return -1;
            }
            unsigned char state_guess = selected_guess->playerClass_0252_guess;
            if (state_guess < 2) {
                return -1;
            }
            if (state_guess > 6 && state_guess != 8
                && (state_guess < 10 || state_guess > 15)) {
                return -1;
            }
            result_guess = 0;
        }
        break;
    }
    case 2: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        float numerator_guess = (float)owner_guess->CurrentValues_guess()
            ->value_11ac_guess;
        int denominator_guess = owner_guess->inner_c280_guess.Max_Endurance();
        if (numerator_guess > 0.0f) {
            return (int)(numerator_guess
                / ((float)denominator_guess * EQ_GLOBAL(float, 0x00641088)));
        }
        return 0;
    }
    case 3: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        // Experience: +0x1A10 times 3.0303, so 330 fills the bar. AA experience (next) does the same
        // with +0xE28 read as unsigned.
        result_guess = (int)((double)owner_guess->value_1a10_guess
            * EQ_GLOBAL(double, 0x0065D370));
        break;
    }
    case 4: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        int value_guess = (int)owner_guess->value_e28_guess;
        double adjusted_guess = (double)value_guess;
        if (value_guess < 0) {
            adjusted_guess += EQ_GLOBAL(float, 0x0063F4D8);
        }
        result_guess = (int)(adjusted_guess * EQ_GLOBAL(double, 0x0065D370));
        break;
    }
    case 5: {
        Selected_guess* selected_guess = gCurrentTarget_guess;
        if (selected_guess == 0) {
            result_guess = -1;
            break;
        }
        // Target HP: a percent bar for players and NPCs (+0x244 below 2), -3 for anything else. It
        // also sets the name text, and clears *output_guess once when +0x1B8 is set.
        if (selected_guess->type_244_guess < 2) {
            result_guess = (int)((float)selected_guess->hp_274_guess
                / ((float)selected_guess->max_hp_284_guess
                    * EQ_GLOBAL(float, 0x00641088)));
        } else {
            result_guess = -3;
        }
        const char* text_guess = gClientState_guess->GetDisplayName_guess(
            selected_guess->name_120_guess);
        ((TextProcessor_guess*)target_guess)->Process_guess(text_guess);
        Display_guess* display_guess = selected_guess->display_1a8_guess;
        if (display_guess->flag_1b8_guess != 0) {
            display_guess->flag_1b8_guess = 0;
            *output_guess = 0;
        }
        break;
    }
    case 6:
        *output_guess = 0;
        result_guess = GetCastingProgress_guess();
        break;
    case 7: {
        *output_guess = 0;
        DataOwner_guess* owner_guess = gDataOwner_guess;
        int value_guess = owner_guess->value_e30_guess;
        // Kind 8: +0xE30 as a share of the character's maximum for it, 0-1000.
        result_guess = (value_guess * 1000) / owner_guess->MaxAirSupply_guess();
        break;
    }
    case 8:
        *output_guess = 0;
        result_guess = pinstCSpellBookWnd_guess->GetSpellMemTicksLeft_guess();
        break;
    case 9:
        *output_guess = 0;
        result_guess = pinstCSpellBookWnd_guess->GetSpellScribeTicksLeft_guess();
        break;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14: {
        result_guess = -2;
        // Group members 1-5 (kinds 11-15): name from the group list; -1 for an empty slot, -2 while
        // the member's spawn is not known.
        int index_guess = kind_guess - 11;
        MenuEntry_guess* entry_guess = &gTargetNames_guess[index_guess];
        if (entry_guess->text_guess[0] == 0) {
            result_guess = -1;
            break;
        }
        Selected_guess* selected_guess = gTargetRecords_guess[index_guess];
        if (selected_guess != 0) {
            result_guess = (int)((float)selected_guess->hp_274_guess
                / ((float)selected_guess->max_hp_284_guess
                    * EQ_GLOBAL(float, 0x00641088)));
        }
        FUN_005738b0_guess(target_guess, "%s", entry_guess->text_guess);
        break;
    }
    case 15: {
        ((TextProcessor_guess*)target_guess)->Clear_guess();
        DataOwner_guess* owner_guess = gDataOwner_guess;
        Selected_guess* current_guess =
            owner_guess->inner_c280_guess.current_c288_guess;
        if (current_guess == 0) {
            result_guess = -3;
            break;
        }
        // Pet HP (kind 16): the pet id at +0x16C of your actor info; a pet's HP (+0x274) is a
        // percent, times 10 for the scale. Kinds 17-21 do the same for the group members' pets.
        int id_guess = current_guess->display_1a8_guess->id_16c_guess;
        if (id_guess == -1) {
            result_guess = -3;
            break;
        }
        Selected_guess* selected_guess = FUN_00401B28_guess(id_guess);
        if (selected_guess == 0) {
            result_guess = -3;
            break;
        }
        const char* text_guess = gClientState_guess->GetDisplayName_guess(
            selected_guess->name_120_guess);
        ((TextProcessor_guess*)target_guess)->Process_guess(text_guess);
        result_guess = selected_guess->hp_274_guess * 10;
        break;
    }
    case 16:
    case 17:
    case 18:
    case 19:
    case 20: {
        ((TextProcessor_guess*)target_guess)->Clear_guess();
        int index_guess = kind_guess - 17;
        if (gTargetNames_guess[index_guess].text_guess[0] == 0) {
            result_guess = -3;
            break;
        }
        Selected_guess* current_guess = gTargetRecords_guess[index_guess];
        if (current_guess == 0) {
            result_guess = -3;
            break;
        }
        Display_guess* display_guess = current_guess->display_1a8_guess;
        if (display_guess == 0 || display_guess->id_16c_guess == -1) {
            result_guess = -3;
            break;
        }
        Selected_guess* selected_guess =
            FUN_00401B28_guess(display_guess->id_16c_guess);
        if (selected_guess == 0) {
            result_guess = -3;
            break;
        }
        const char* text_guess = gClientState_guess->GetDisplayName_guess(
            selected_guess->name_120_guess);
        ((TextProcessor_guess*)target_guess)->Process_guess(text_guess);
        result_guess = selected_guess->hp_274_guess * 10;
        break;
    }
    case 21: {
        Timer_guess* timer_guess = *EQ_GLOBAL(Timer_guess**, 0x00851390);
        if (timer_guess == 0) {
            return 0;
        }
        int elapsed_guess = timer_guess->GetTrackLength_guess();
        // Kind 22: the sound manager's stream at 0x00851390. Once its position (0x004C5EA9, ms)
        // passes 1 s, the value from 0x004C5EB1 divided by the whole seconds played.
        if (elapsed_guess <= maximum_guess) {
            return 0;
        }
        int seconds_guess = timer_guess->GetTrackLength_guess() / maximum_guess;
        int total_guess = timer_guess->GetTrackPosition_guess();
        result_guess = total_guess / seconds_guess;
        break;
    }
    case 22: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        result_guess = (int)owner_guess->value_e90_guess;
        break;
    }
    case 23: {
        DataOwner_guess* owner_guess = gDataOwner_guess;
        if (owner_guess == 0) {
            return -2;
        }
        result_guess = (int)(owner_guess->value_e98_guess
            * EQ_GLOBAL(double, 0x006410A0));
        break;
    }
    case 24:
        *output_guess = 0;
        return 100;
    case 25:
        *output_guess = 0;
        result_guess = GetDisciplineGaugeValue_guess();
        break;
    case 26: {
        Selected_guess* parent_guess =
            EQ_GLOBAL(Selected_guess*, 0x00905CE4);
        Selected_guess* current_guess =
            parent_guess->display_1a8_guess->selected_198_guess;
        if (current_guess == 0) {
            result_guess = -1;
            break;
        }
        // Kind 27: the spawn at +0x198 of your actor info, with the same rules as the target (kind
        // 6).
        if (current_guess->type_244_guess < 2) {
            result_guess = (int)((float)current_guess->hp_274_guess
                / ((float)current_guess->max_hp_284_guess
                    * EQ_GLOBAL(float, 0x00641088)));
        } else {
            result_guess = -3;
        }
        const char* text_guess = gClientState_guess->GetDisplayName_guess(
            current_guess->name_120_guess);
        ((TextProcessor_guess*)target_guess)->Process_guess(text_guess);
        Display_guess* display_guess = current_guess->display_1a8_guess;
        if (display_guess->flag_1b8_guess != 0) {
            display_guess->flag_1b8_guess = 0;
            *output_guess = 0;
        }
        break;
    }
    case 27: {
        CRespawnWnd_guess* meter_guess = pinstCRespawnWnd_guess;
        Selected_guess* parent_guess =
            EQ_GLOBAL(Selected_guess*, 0x00905CE4);
        // Kind 28, a countdown: 1 - (now - start + 500 ms) / the meter's length (+0x168), on the
        // 0-1000 scale.
        if (meter_guess != 0 && parent_guess != 0
            && parent_guess->display_1a8_guess != 0
            && parent_guess->display_1a8_guess->value_68_guess != 0) {
            int value_guess = (int)EQ_GLOBAL(Clock_guess*, 0x00905D24)
                ->time_148_guess
                - parent_guess->display_1a8_guess->value_68_guess + 0x1F4;
            int maximum_value_guess = meter_guess->field_168_guess;
            if (value_guess > maximum_value_guess) {
                value_guess = maximum_value_guess;
            }
            result_guess = (int)((EQ_GLOBAL(float, 0x0063F4D0)
                - (float)value_guess / (float)maximum_value_guess)
                * EQ_GLOBAL(float, 0x00640DA8));
            *output_guess = 0;
        } else {
            result_guess = -1;
        }
        break;
    }
    default:
        result_guess = -2;
        break;
    }
    // Clamp to -110 .. 1000. The gauge draws -10 .. -110 on its second scale, -1 as nothing, -2 as a
    // full red bar and -3 as an empty frame.
    if (result_guess < -0x6E) {
        result_guess = -0x6E;
    } else if (result_guess > maximum_guess) {
        result_guess = maximum_guess;
    }
    return result_guess;
}

#define gLabelBuffSpells_guess EQ_ARRAY(int, 0x009924B4)
#define gLabelName_guess EQ_ARRAY(char, 0x00992048)
#define gLabelSurname_guess EQ_ARRAY(char, 0x00992088)
#define gLabelHp_guess EQ_GLOBAL(int, 0x009920C8)
#define gLabelTitle_guess EQ_ARRAY(char, 0x009920CC)
#define gLabelTargetText_guess EQ_ARRAY(char, 0x0099210C)
#define gLabelClass_guess EQ_GLOBAL(int, 0x0099214C)
#define gLabelValues_guess EQ_ARRAY(int, 0x00992150)
#define gLabelPlayerName_guess EQ_ARRAY(char, 0x009921C4)
#define gLabelPetHp_guess EQ_GLOBAL(int, 0x009922C4)
#define gLabelTargetName_guess EQ_ARRAY(char, 0x009922C8)
#define gLabelTargetHp_guess EQ_GLOBAL(int, 0x00992348)
#define gLabelGroupNames_guess EQ_ARRAY(MenuEntry_guess, 0x0099234C)
#define gLabelSpellIds_guess EQ_ARRAY(int, 0x009923B0)
#define gLabelPercents_guess EQ_ARRAY(int, 0x00992400)
#define gLabelGems_guess EQ_ARRAY(int, 0x00992580)
#define gLabelTimerName_guess EQ_ARRAY(char, 0x009925A0)
#define gLabelTimes_guess EQ_ARRAY(int, 0x009927A0)
#define gTimerSlot_guess EQ_GLOBAL(Timer_guess**, 0x00851390)
#define gClock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define gCounter_guess EQ_GLOBAL(Counter_guess, 0x00850350)
#define gCounter2_guess EQ_GLOBAL(Counter2_guess, 0x00905D38)
#define gTimer1Flag_guess EQ_GLOBAL(char, 0x00850375)
#define gTimer2Ms_guess EQ_GLOBAL(int, 0x0091D6D0)
#define gTimer2Value_guess EQ_GLOBAL(int, 0x0091D6D4)
#define gTimer2Flag_guess EQ_GLOBAL(char, 0x0091D6ED)
#define gScaleA_guess EQ_GLOBAL(double, 0x0065D3A8)
#define gScaleB_guess EQ_GLOBAL(double, 0x00640FC8)
#define gScaleC_guess EQ_GLOBAL(double, 0x006410C0)
#define gScaleD_guess EQ_GLOBAL(double, 0x0064C0C0)
#define gEmpty_guess EQ_ARRAY(char, 0x0063F53F)
#define gIntFormat_guess EQ_ARRAY(char, 0x0063F53C)

// Label text by type. Types 45-59 and 500-524 are buff names, 80-85 and 600-611 song names; the rest are
// character values (name, level, stats coloured against their base, coins, weight...), timers ("%02d:%02d")
// and counters. Unknown types print "Unknown\tLabel%d". Returns 1 when the text may have changed: the
// cached values only on a change, but many cases (gem names included) always.
// FUNCTION: TITANIUM 0x00559FB3
// @early-stop: budget, structural ndiff=483
char __cdecl GetLabelFromEQ(int label_guess, TextProcessor_guess* str_guess,
    bool* override_guess, int* color_guess) {
    char result_guess = 0;
    int index_guess = -1;
    // Label ids are the EQType numbers of the UI's label controls. Buff names: 45-59 and 500-524 are the
    // long-buff slots (the old range reaches only slot 14), 80-85 and 600-611 the short-buff slots from 25.
    if (label_guess >= 0x2d && label_guess <= 0x3b) {
        index_guess = label_guess - 0x2d;
    } else if (label_guess >= 500 && label_guess <= 0x20c) {
        index_guess = label_guess - 500;
    }
    if (index_guess != -1) {
        int spell_guess = gDataOwner_guess->inner_c280_guess
            .GetBuff_guess(index_guess)->spell_4_guess;
        if (spell_guess == -1) {
            str_guess->Clear_guess();
        } else {
            str_guess->Process_guess(((Spell_guess*)gLookupTable_guess
                ->GetSpell_guess(spell_guess))->name_208_guess);
        }
        gLabelBuffSpells_guess[index_guess] = spell_guess;
        *override_guess = false;
        return 1;
    }
    if (label_guess >= 0x50 && label_guess <= 0x55) {
        index_guess = label_guess - 0x50;
    } else if (label_guess >= 600 && label_guess <= 0x263) {
        index_guess = label_guess - 600;
    }
    if (index_guess != -1) {
        int spell_guess = gDataOwner_guess->inner_c280_guess
            .GetBuff_guess(index_guess + 0x19)->spell_4_guess;
        if (spell_guess == -1) {
            str_guess->Clear_guess();
        } else {
            str_guess->Process_guess(((Spell_guess*)gLookupTable_guess
                ->GetSpell_guess(spell_guess))->name_208_guess);
        }
        gLabelBuffSpells_guess[index_guess] = spell_guess;
        *override_guess = false;
        return 1;
    }

    DataInner_guess* inner_guess;
    Selected_guess* spawn_guess;
    Display_guess* display_guess;
    const char* text_guess;
    int percent_guess;
    int limit_guess;
    int sum_guess;
    int value_guess;
    int spell_guess;
    // 1 name, 2 level, 3 the class title for
    // the level (0x00419631, from 51), 4 class, 5 on the stats (each base plus item and spell bonus,
    // colour by the change), then HP, mana and endurance values and their "%d/%d" pairs.
    switch (label_guess) {
    case 1:
        result_guess = SetLabelText_guess(gLabelName_guess,
            ((NamedSlot_guess*)gDataOwner_guess->CurrentRecordSlot_guess())
                ->name_3c_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 2:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelHp_guess,
            gDataOwner_guess->CurrentValues_guess()->level_11a4_guess,
            gDataOwner_guess->CurrentValues_guess()->level_11a4_guess,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 3:
        result_guess = SetLabelText_guess(gLabelTitle_guess,
            gDataOwner_guess->inner_c280_guess.KunarkClass_guess(-1, 0, 0, 0),
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 4:
        result_guess = 1;
        gLabelClass_guess = gDataOwner_guess->GetDeity_guess();
        str_guess->Process_guess(gClientState_guess->GetDeityDesc(
            gDataOwner_guess->GetDeity_guess()));
        break;
    case 5:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[0],
            gDataOwner_guess->inner_c280_guess.value_c290_guess,
            gDataOwner_guess->CurrentValues_guess()->str_11b4_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(4, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 6:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[1],
            gDataOwner_guess->inner_c280_guess.value_c294_guess,
            gDataOwner_guess->CurrentValues_guess()->sta_11b8_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(7, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 7:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[2],
            gDataOwner_guess->inner_c280_guess.value_c29c_guess,
            gDataOwner_guess->CurrentValues_guess()->dex_11c0_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(5, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 8:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[3],
            gDataOwner_guess->inner_c280_guess.value_c2a4_guess,
            gDataOwner_guess->CurrentValues_guess()->agi_11c8_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(6, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 10:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[5],
            gDataOwner_guess->inner_c280_guess.value_c2a0_guess,
            gDataOwner_guess->CurrentValues_guess()->intel_11c4_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(8, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 9:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[4],
            gDataOwner_guess->inner_c280_guess.value_c2a8_guess,
            gDataOwner_guess->CurrentValues_guess()->wis_11cc_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(9, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 11:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[6],
            gDataOwner_guess->inner_c280_guess.value_c298_guess,
            gDataOwner_guess->CurrentValues_guess()->cha_11bc_guess
                + gDataOwner_guess->inner_c280_guess.GetBonus_guess(10, 0),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 12:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[7],
            gDataOwner_guess->inner_c280_guess.value_c2bc_guess,
            gDataOwner_guess->inner_c280_guess.basesave_poison_guess(),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 13:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[8],
            gDataOwner_guess->inner_c280_guess.value_c2c0_guess,
            gDataOwner_guess->inner_c280_guess.GetBonus_guess(0x31, 0)
                + gDataOwner_guess->inner_c280_guess.basesave_disease_guess(),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 14:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[9],
            gDataOwner_guess->inner_c280_guess.value_c2b8_guess,
            gDataOwner_guess->inner_c280_guess.GetBonus_guess(0x2e, 0)
                + gDataOwner_guess->inner_c280_guess.basesave_fire_guess(),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 15:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[10],
            gDataOwner_guess->inner_c280_guess.value_c2b4_guess,
            gDataOwner_guess->inner_c280_guess.GetBonus_guess(0x2f, 0)
                + gDataOwner_guess->inner_c280_guess.basesave_cold_guess(),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 16:
        *override_guess = true;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[11],
            gDataOwner_guess->inner_c280_guess.value_c2b0_guess,
            gDataOwner_guess->inner_c280_guess.GetBonus_guess(0x32, 0)
                + gDataOwner_guess->inner_c280_guess.basesave_magic_guess(),
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 17:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[12],
            gDataOwner_guess->inner_c280_guess.Cur_HP(0), 0,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 18:
        *override_guess = true;
        sum_guess = gDataOwner_guess->inner_c280_guess
                .TotalSpellAffects_guess(0x45, 1, 0, 0)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0, 1, 0, 0);
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[13],
            gDataOwner_guess->inner_c280_guess.Max_HP_guess(0),
            gDataOwner_guess->inner_c280_guess.Max_HP_guess(0) - sum_guess,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 19:
        *override_guess = false;
        percent_guess = gDataOwner_guess->inner_c280_guess.Cur_HP(0)
            * 100 / gDataOwner_guess->inner_c280_guess.Max_HP_guess(0);
        if (percent_guess < 0) {
            percent_guess = 0;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[14],
            percent_guess, 0, (int)str_guess, *override_guess, color_guess,
            100);
        return result_guess;
    case 20:
        *override_guess = false;
        percent_guess = 0;
        if (gDataOwner_guess->inner_c280_guess.GetMaxB_guess() > 0) {
            inner_guess = &gDataOwner_guess->inner_c280_guess;
            value_guess = inner_guess->Cur_Mana_guess() * 100;
            percent_guess = value_guess / inner_guess->GetMaxB_guess();
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[17],
            percent_guess, 0, (int)str_guess, *override_guess, color_guess,
            100);
        return result_guess;
    case 0x7c:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[15],
            gDataOwner_guess->inner_c280_guess.Cur_Mana_guess(), 0,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 0x7d:
        *override_guess = true;
        sum_guess = gDataOwner_guess->inner_c280_guess
                .TotalSpellAffects_guess(0x61, 1, 0, 1)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0xf, 1, 0, 1);
        inner_guess = &gDataOwner_guess->inner_c280_guess;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[16],
            inner_guess->GetMaxB_guess(),
            inner_guess->GetMaxB_guess() - sum_guess, (int)str_guess,
            *override_guess, color_guess, -9999);
        return result_guess;
    case 0x80:
        result_guess = 1;
        gLabelValues_guess[15] = gDataOwner_guess->inner_c280_guess
            .Cur_Mana_guess();
        gLabelValues_guess[16] = gDataOwner_guess->inner_c280_guess
            .GetMaxB_guess();
        FUN_005738b0_guess((int)str_guess, "%d/%d", gLabelValues_guess[15],
            gLabelValues_guess[16]);
        *override_guess = true;
        *color_guess = getComparisonColor_guess(
            gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0x61, 1, 0, 0)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0xf, 1, 0, 0),
            0);
        return result_guess;
    case 0x7e:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[18],
            gDataOwner_guess->inner_c280_guess.Cur_Endurance_guess(), 0,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 0x7f:
        *override_guess = true;
        sum_guess = gDataOwner_guess->inner_c280_guess
                .TotalSpellAffects_guess(0xbe, 1, 0, 1)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0xbd, 1, 0, 1);
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[19],
            gDataOwner_guess->inner_c280_guess.Max_Endurance(),
            gDataOwner_guess->inner_c280_guess.Max_Endurance() - sum_guess,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 0x81:
        result_guess = 1;
        gLabelValues_guess[19] = gDataOwner_guess->inner_c280_guess
            .Max_Endurance();
        gLabelValues_guess[18] = gDataOwner_guess->inner_c280_guess
            .Cur_Endurance_guess();
        FUN_005738b0_guess((int)str_guess, "%d/%d", gLabelValues_guess[18],
            gLabelValues_guess[19]);
        *override_guess = true;
        *color_guess = getComparisonColor_guess(
            gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0xbe, 1, 0, 0)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0xbd, 1, 0, 0),
            0);
        return result_guess;
    case 21:
        *override_guess = false;
        percent_guess = 0;
        if (gDataOwner_guess->inner_c280_guess.Max_Endurance() > 0) {
            percent_guess = gDataOwner_guess->inner_c280_guess.Cur_Endurance_guess()
                * 100 / gDataOwner_guess->inner_c280_guess.Max_Endurance();
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[20],
            percent_guess, 0, (int)str_guess, *override_guess, color_guess,
            100);
        return result_guess;
    case 22:
        *override_guess = true;
        value_guess = GetDisplayAC_guess();
        sum_guess = gDataOwner_guess->inner_c280_guess
                .TotalSpellAffects_guess(0x37, 1, 0, 0)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(1, 1, 0, 0);
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[21],
            value_guess, value_guess - sum_guess, (int)str_guess,
            *override_guess, color_guess, -9999);
        return result_guess;
    case 23:
        *override_guess = true;
        sum_guess = gDataOwner_guess->inner_c280_guess
            .TotalSpellAffects_guess(2, 1, 0, 0);
        value_guess = GetDisplayATK_guess();
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[22],
            value_guess, value_guess - sum_guess, (int)str_guess,
            *override_guess, color_guess, -9999);
        return result_guess;
    case 24:
        value_guess = gDataOwner_guess->inner_c280_guess.value_c2c8_guess;
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess, value_guess);
        gLabelValues_guess[23] = value_guess;
        *override_guess = true;
        *color_guess = 0xFFC0C0C0;
        result_guess = 1;
        if (value_guess > gDataOwner_guess->inner_c280_guess.GetLimit_guess()) {
            *color_guess = 0xFFFF0000;
        }
        return result_guess;
    case 25:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[24],
            gDataOwner_guess->inner_c280_guess.GetLimit_guess(), 0,
            (int)str_guess, *override_guess, color_guess, -9999);
        return result_guess;
    case 26:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[25],
            (int)(gDataOwner_guess->value_1a10_guess * gScaleA_guess), 0,
            (int)str_guess, *override_guess, color_guess, 100);
        return result_guess;
    case 27:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelValues_guess[26],
            (int)(gDataOwner_guess->value_e28_guess * gScaleA_guess), 0,
            (int)str_guess, *override_guess, color_guess, 100);
        return result_guess;
    case 0x82:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelTimes_guess[4],
            (int)(gDataOwner_guess->value_e90_guess * gScaleB_guess
                * gScaleC_guess), 0,
            (int)str_guess, *override_guess, color_guess, 100);
        return result_guess;
    case 0x83:
        *override_guess = false;
        result_guess = updateStatValueWithColorCoding_guess(&gLabelTimes_guess[5],
            (int)(gDataOwner_guess->value_e98_guess * gScaleB_guess
                * gScaleD_guess), 0,
            (int)str_guess, *override_guess, color_guess, 100);
        return result_guess;
    case 28:
        result_guess = SetLabelText_guess(gLabelPlayerName_guess,
            gCurrentTarget_guess == 0 ? gEmpty_guess
                : gClientState_guess->GetDisplayName_guess(
                    gCurrentTarget_guess->name_120_guess),
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 29:
        *override_guess = false;
        spawn_guess = gCurrentTarget_guess;
        if (spawn_guess != 0 && spawn_guess->type_244_guess < 2) {
            percent_guess = spawn_guess->hp_274_guess * 100
                / spawn_guess->max_hp_284_guess;
            limit_guess = 100;
        } else {
            percent_guess = 0;
            limit_guess = -9999;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelPetHp_guess, percent_guess,
            0, (int)str_guess, *override_guess, color_guess, limit_guess);
        return result_guess;
    case 0x44:
        *override_guess = false;
        display_guess = gDefaultTarget_guess->display_1a8_guess;
        if (display_guess != 0 && display_guess->id_16c_guess != -1
            && (spawn_guess = FUN_00401B28_guess(display_guess->id_16c_guess))
                != 0) {
            text_guess = spawn_guess->GetName_guess();
        } else {
            text_guess = gEmpty_guess;
        }
        result_guess = SetLabelText_guess(gLabelTargetName_guess, text_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 0x45:
        *override_guess = false;
        display_guess = gDefaultTarget_guess->display_1a8_guess;
        if (display_guess != 0 && display_guess->id_16c_guess != -1
            && (spawn_guess = FUN_00401B28_guess(display_guess->id_16c_guess))
                != 0) {
            percent_guess = spawn_guess->hp_274_guess * 100
                / spawn_guess->max_hp_284_guess;
            if (percent_guess < 0) {
                percent_guess = 0;
            }
            limit_guess = 100;
        } else {
            percent_guess = 0;
            limit_guess = -9999;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelTargetHp_guess, percent_guess,
            0, (int)str_guess, *override_guess, color_guess, limit_guess);
        return result_guess;
    // Group slots 1-5: names (30-34), HP percent (35-39) and their pets' HP percent (40-44); a missing member
    // shows nothing (limit -9999).
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
        index_guess = label_guess - 0x1e;
        result_guess = SetLabelText_guess(
            gLabelGroupNames_guess[index_guess].text_guess,
            gTargetRecords_guess[index_guess] == 0
                ? gEmpty_guess
                : gTargetNames_guess[index_guess].text_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
        *override_guess = false;
        spawn_guess = gTargetRecords_guess[label_guess - 0x23];
        if (spawn_guess != 0) {
            percent_guess = spawn_guess->hp_274_guess * 100
                / spawn_guess->max_hp_284_guess;
            if (percent_guess < 0) {
                percent_guess = 0;
            }
            limit_guess = 100;
        } else {
            percent_guess = 0;
            limit_guess = -9999;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelPercents_guess[label_guess],
            percent_guess, 0, (int)str_guess, *override_guess, color_guess,
            limit_guess);
        return result_guess;
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
        *override_guess = false;
        spawn_guess = gTargetRecords_guess[label_guess - 0x28];
        if (spawn_guess != 0 && spawn_guess->display_1a8_guess != 0
            && spawn_guess->display_1a8_guess->id_16c_guess != -1
            && (spawn_guess = FUN_00401B28_guess(
                spawn_guess->display_1a8_guess->id_16c_guess)) != 0) {
            percent_guess = spawn_guess->hp_274_guess * 100
                / spawn_guess->max_hp_284_guess;
            if (percent_guess < 0) {
                percent_guess = 0;
            }
            limit_guess = 100;
        } else {
            percent_guess = 0;
            limit_guess = -9999;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelPercents_guess[label_guess],
            percent_guess, 0, (int)str_guess, *override_guess, color_guess,
            limit_guess);
        return result_guess;
    // 60-67 and 133: the spell gem names (133 is the ninth gem).
    case 0x3c:
    case 0x3d:
    case 0x3e:
    case 0x3f:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x85:
        index_guess = label_guess - 0x3c;
        if (label_guess == 0x85) {
            index_guess = 8;
        }
        spell_guess = gDataOwner_guess->CurrentRecordSlot_guess()
            ->GetMemorizedSpell_guess(index_guess);
        if (spell_guess == -1) {
            str_guess->Clear_guess();
        } else {
            str_guess->Process_guess(((Spell_guess*)gLookupTable_guess
                ->GetSpell_guess(spell_guess))->name_208_guess);
        }
        result_guess = 1;
        gLabelGems_guess[index_guess] = spell_guess;
        break;
    case 0x46:
        result_guess = 1;
        gLabelValues_guess[13] = gDataOwner_guess->inner_c280_guess
            .Max_HP_guess(0);
        gLabelValues_guess[12] = gDataOwner_guess->inner_c280_guess
            .Cur_HP(0);
        FUN_005738b0_guess((int)str_guess, "%d/%d", gLabelValues_guess[12],
            gLabelValues_guess[13]);
        *override_guess = true;
        *color_guess = getComparisonColor_guess(
            gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0x45, 1, 0, 0)
            + gDataOwner_guess->inner_c280_guess.TotalSpellAffects_guess(0, 1, 0, 0),
            0);
        return result_guess;
    case 0x47:
        result_guess = 1;
        gLabelValues_guess[27] = gDataOwner_guess->GetValue5870_guess();
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gLabelValues_guess[27]);
        break;
    case 0x48:
        result_guess = 1;
        gLabelValues_guess[28] = gDataOwner_guess->value_e2d_guess;
        FUN_005738b0_guess((int)str_guess, "%d%%", gLabelValues_guess[28]);
        break;
    case 0x49:
        result_guess = SetLabelText_guess(gLabelSurname_guess,
            ((NamedSlot_guess*)gDataOwner_guess->CurrentRecordSlot_guess())
                ->name_7c_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 0x4a:
        *override_guess = false;
        text_guess = gDefaultTarget_guess->name_2a4_guess;
        if (text_guess == 0) {
            text_guess = gEmpty_guess;
        }
        result_guess = SetLabelText_guess(gLabelTargetText_guess, text_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 0x4b:
        *override_guess = false;
        text_guess = gEmpty_guess;
        if (*gTimerSlot_guess != 0 && (*gTimerSlot_guess)->IsRunning_guess()) {
            text_guess = (*gTimerSlot_guess)->GetName_guess(
                (*gTimerSlot_guess)->GetIndex_guess());
        }
        result_guess = SetLabelText_guess(gLabelTimerName_guess, text_guess,
            str_guess, (char*)override_guess, color_guess);
        return result_guess;
    case 0x4c:
        gLabelTimes_guess[0] = 0;
        result_guess = 1;
        if (*gTimerSlot_guess != 0 && (*gTimerSlot_guess)->IsRunning_guess()) {
            gLabelTimes_guess[0] = (*gTimerSlot_guess)->GetTrackLength_guess()
                / 60000;
        }
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gLabelTimes_guess[0]);
        break;
    case 0x4d:
        gLabelTimes_guess[1] = 0;
        result_guess = 1;
        if (*gTimerSlot_guess != 0 && (*gTimerSlot_guess)->IsRunning_guess()) {
            gLabelTimes_guess[1] = (*gTimerSlot_guess)->GetTrackLength_guess()
                % 60000 / 1000;
        }
        FUN_005738b0_guess((int)str_guess, "%02d", gLabelTimes_guess[1]);
        break;
    case 0x4e:
        gLabelTimes_guess[2] = 0;
        result_guess = 1;
        if (*gTimerSlot_guess != 0 && (*gTimerSlot_guess)->IsRunning_guess()) {
            gLabelTimes_guess[2] = (*gTimerSlot_guess)->GetTrackPosition_guess()
                / 60000;
        }
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gLabelTimes_guess[2]);
        break;
    case 0x4f:
        gLabelTimes_guess[3] = 0;
        result_guess = 1;
        if (*gTimerSlot_guess != 0 && (*gTimerSlot_guess)->IsRunning_guess()) {
            gLabelTimes_guess[3] = (*gTimerSlot_guess)->GetTrackPosition_guess()
                % 60000 / 1000;
        }
        FUN_005738b0_guess((int)str_guess, "%02d", gLabelTimes_guess[3]);
        break;
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
        spell_guess = gDataOwner_guess->inner_c280_guess
            .GetBuff_guess(label_guess - 0x37)->spell_4_guess;
        if (spell_guess == -1) {
            str_guess->Clear_guess();
        } else {
            str_guess->Process_guess(((Spell_guess*)gLookupTable_guess
                ->GetSpell_guess(spell_guess))->name_208_guess);
        }
        result_guess = 1;
        gLabelSpellIds_guess[label_guess] = spell_guess;
        break;
    case 0x56: case 0x57: case 0x58: case 0x59: case 0x5a: case 0x5b:
    case 0x5c: case 0x5d: case 0x5e: case 0x5f: case 0x60: case 0x61:
    case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67:
    case 0x68: case 0x69: case 0x6a: case 0x6b: case 0x6c: case 0x6d:
    case 0x6e: case 0x6f: case 0x70: case 0x71: case 0x72: case 0x73:
        spell_guess = pinstCPetInfoWnd_guess->spells_288_guess[label_guess - 0x56];
        if (IsSpellValid_guess(spell_guess)) {
            str_guess->Process_guess(((Spell_guess*)gLookupTable_guess
                ->GetSpell_guess(spell_guess))->name_208_guess);
        } else {
            str_guess->Clear_guess();
        }
        result_guess = 1;
        gLabelSpellIds_guess[label_guess] = spell_guess;
        break;
    case 0x74:
        value_guess = (gDataOwner_guess->time_e70_guess + 500) / 1000;
        FUN_005738b0_guess((int)str_guess, "%02d:%02d", value_guess / 60,
            value_guess % 60);
        *override_guess = true;
        *color_guess = gTimer1Flag_guess ? 0xFF00FF00 : 0xFFC0C0C0;
        result_guess = 1;
        return result_guess;
    case 0x77:
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gCounter_guess.GetCount_guess());
        result_guess = 1;
        break;
    case 0x75:
        FUN_005738b0_guess((int)str_guess, "%I64d",
            gDataOwner_guess->value_e80_guess);
        result_guess = 1;
        break;
    case 0x76:
        FUN_005738b0_guess((int)str_guess, "%I64d",
            gDataOwner_guess->value_e78_guess);
        result_guess = 1;
        break;
    case 0x78:
        spawn_guess = gDefaultTarget_guess->display_1a8_guess
            ->selected_198_guess;
        *override_guess = false;
        if (spawn_guess != 0 && spawn_guess->type_244_guess < 2) {
            percent_guess = spawn_guess->hp_274_guess * 100
                / spawn_guess->max_hp_284_guess;
            limit_guess = 100;
        } else {
            percent_guess = 0;
            limit_guess = -9999;
        }
        result_guess = updateStatValueWithColorCoding_guess(&gLabelPetHp_guess, percent_guess,
            0, (int)str_guess, *override_guess, color_guess, limit_guess);
        return result_guess;
    case 0x79:
        value_guess = (gTimer2Ms_guess + 500) / 1000;
        FUN_005738b0_guess((int)str_guess, "%02d:%02d", value_guess / 60,
            value_guess % 60);
        *override_guess = true;
        *color_guess = gTimer2Flag_guess ? 0xFF00FF00 : 0xFFC0C0C0;
        result_guess = 1;
        return result_guess;
    case 0x7a:
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gTimer2Value_guess);
        result_guess = 1;
        break;
    case 0x7b:
        FUN_005738b0_guess((int)str_guess, gIntFormat_guess,
            gCounter2_guess.GetCount_guess());
        result_guess = 1;
        break;
    case 0x84: {
        unsigned int seconds_guess = 0;
        if (gDataOwner_guess->time_e50_guess > gClock_guess->time_148_guess) {
            seconds_guess = (gDataOwner_guess->time_e50_guess
                - gClock_guess->time_148_guess + 999) / 1000;
        }
        value_guess = seconds_guess;
        FUN_005738b0_guess((int)str_guess, "%02d:%02d", value_guess / 60,
            value_guess % 60);
        result_guess = 1;
        break;
    }
    case 0x86:
        *override_guess = false;
        if (gDefaultTarget_guess != 0
            && gDefaultTarget_guess->display_1a8_guess != 0) {
            spell_guess = gDefaultTarget_guess->display_1a8_guess
                ->spell_f98_guess;
            str_guess->Process_guess(IsSpellValid_guess(spell_guess)
                ? ((Spell_guess*)gLookupTable_guess->GetSpell_guess(spell_guess))
                    ->name_208_guess
                : gEmpty_guess);
        }
        result_guess = 1;
        return result_guess;
    default:
        FUN_005738b0_guess((int)str_guess, "Unknown\tLabel%d", label_guess);
        break;
    }
    *override_guess = false;
    return result_guess;
}
