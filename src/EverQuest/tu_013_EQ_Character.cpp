// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 13: a hint from compare/tumap.py.
// EQ_Character (EQ_Character.cpp in the earlier sibling decomp): stats, resists, skills, HP/mana/endurance,
// creation tables.
// CostOwner_guess, CostRollOwner_guess, DynamicPropertyOwner_guess, CharacterStats_guess and kin are views
// of it over the profile LookupResult_guess (race +0x1198, class +0x119C, level +0x11A4, mana +0x11A8,
// endurance +0x11AC, base HP +0x11B0). GetRandom_guess (0x4106A3) is really TotalSpellAffects.
#include <winsock2.h>
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/bounded_array.h"
#include "titanium/slots.h"
#include "titanium/classes.h"
#include "titanium/skills.h"
#include "titanium/spell_effects.h"
#include "titanium/opcodes.h"
#include <setjmp.h>

#define g_lookupMode_guess EQ_GLOBAL(int, 0x00923D58)

struct LookupTail_guess {
    int value_11b4_guess;
    int value_11b8_guess;
    int dynamic_value_11bc_guess;
    int dynamic_value_11c0_guess;
    int intel_11c4_guess;
    int agi_11c8_guess;
    int wis_11cc_guess;
    char padding_11d0_guess[4];
    unsigned int third_value_guess;
    int fourth_value_guess;
    int fifth_value_guess;
    int sixth_value_guess;
    int value_11e4_guess;
    int value_11e8_guess;
    int value_11ec_guess;
    int value_11f0_guess;
    char padding_11f4_guess[0x24];
    int seventh_value_guess;
    int eighth_value_guess;
};
struct LookupResult_guess {
    char padding_0000_guess[0x10];
    int initial_values_guess[31];
    char padding_008c_guess[0xee4];
    BoundedArray_guess<int, 100> values_f70_guess;
    BoundedArray_guess<int, 25> values1100_guess;
    char padding_1164_guess[0x34];
    int database_string_id_guess;
    unsigned char state_guess;
    char padding_119d_guess[3];
    int value_11a0_guess;
    int level_11a4_guess;
    int allowed_value_11a8_guess;
    int first_value_guess;
    int second_value_guess;
    LookupTail_guess tail_guess;
    char padding_1220_guess[4];
    int value_1224_guess;
    char padding_1228_guess[0x20];
    int value_1248_guess;
    int value_124c_guess;
    int value_1250_guess;
    int value_1254_guess;
    int value_1258_guess;
    int queried_value_guess;
    char padding_1260_guess[0xc];
    int value_126c_guess;
    int value_1270_guess;
    char padding_1274_guess[4];
    int value_1278_guess;
    int value_127c_guess;
    char padding_1280_guess[0xc];
    // EXTERNAL: TITANIUM 0x005FE720 LookupResult_guess::LookupResult_guess
    LookupResult_guess();
    // EXTERNAL: TITANIUM 0x005FB8C0 LookupResult_guess::GetComputedFloat_guess
    float GetComputedFloat_guess();
    // EXTERNAL: TITANIUM 0x005FBA90 LookupResult_guess::GetValue1240_guess
    int GetValue1240_guess();
};

struct CostCandidate_guess;

struct LookupService_guess {
    int unused_guess;
    // EXTERNAL: TITANIUM 0x005EC220 LookupService_guess::Find_guess
    LookupResult_guess* Find_guess();
};

struct LookupStatusObject_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual struct LookupCurrentValue_guess* GetCurrentObject_guess();
    LookupService_guess lookup_guess;
    int GetStatus_guess();
    // EXTERNAL: TITANIUM 0x0040E722 LookupStatusObject_guess::GetSkill_guess
    int GetSkill_guess(unsigned char mode_guess);
};

struct LookupCurrentValue_guess {
    // EXTERNAL: TITANIUM 0x005ED510 LookupCurrentValue_guess::GetValue_guess
    unsigned char GetValue_guess();
};

struct LookupGateState_guess {
    char padding_0000_guess[0x244];
    unsigned char state_guess;
};

struct LookupCategory_guess {
    // EXTERNAL: TITANIUM 0x0044A335 LookupCategory_guess::IsEnabled_guess
    int IsEnabled_guess(unsigned char state_guess);
    // EXTERNAL: TITANIUM 0x0044A2E4 LookupCategory_guess::GetModeCount_guess
    int GetModeCount_guess(unsigned char state_guess);
};

// Race id to its row in the race tables: 1-12 stay, Iksar (128) 13, Vah Shir (130) 14, Froglok (330) 15,
// anything else 16. Callers pass a 0-based race index plus 1.
// FUNCTION: TITANIUM 0x004167B2
int __cdecl MapLookupValue_guess(int value_guess) {
    if (value_guess < 13) {
        return value_guess;
    }
    switch (value_guess) {
    case 128:
        return 13;
    case 130:
        return 14;
    case 330:
        return 15;
    default:
        return 16;
    }
}

// Profile +0x1224, or 3 without a profile. Only 0 lets Skill_guess and HasSkill (0x41B0DE) apply the
// class and level caps.
// FUNCTION: TITANIUM 0x004167E2
int LookupStatusObject_guess::GetStatus_guess() {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    if (result_guess != 0) {
        return result_guess->value_1224_guess;
    }
    return 3;
}

int __cdecl MapDynamicValue_guess(int value_guess);

// Deity id to a 1-based bit index for item deity masks: 396 (Agnostic) is 1, 201 and up count from 2.
// FUNCTION: TITANIUM 0x004167F9
int __cdecl MapDynamicValue_guess(int value_guess) {
    if (value_guess == 0x18c) {
        return 1;
    }
    return value_guess - 199;
}

// Allocates and constructs a character profile (0x128C bytes).
// FUNCTION: TITANIUM 0x0041687A
LookupResult_guess* __cdecl FUN_0041687a_guess() {
    return new LookupResult_guess;
}

// Spell-school skill to its Specialize skill: Abjuration, Alteration, Conjuration, Divination and Evocation
// give 43-47; any other skill 0.
// FUNCTION: TITANIUM 0x004168BD
int __cdecl normal_to_special_guess(int value_guess) {
    switch (value_guess) {
    case 4:
        return 0x2b;
    case 5:
        return 0x2c;
    case 14:
        return 0x2d;
    case 18:
        return 0x2e;
    case 24:
        return 0x2f;
    default:
        return 0;
    }
}

// `value_guess` * `factor_guess` / 300; the part of the factor above 255 counts half.
// FUNCTION: TITANIUM 0x004168EF
int __cdecl ScaleValue_guess(int value_guess, int factor_guess) {
    if (factor_guess > 0xff) {
        factor_guess = (factor_guess - 0xff) / 2 + 0xff;
    }
    return value_guess * factor_guess / 300;
}

// Average of four stat fields; above 100 it grows by (avg*3 - 300)/2, after the part above 200 is halved.
// FUNCTION: TITANIUM 0x0041691B
int __cdecl AdjustAverage_guess(int first_guess, int second_guess, int third_guess, int fourth_guess) {
    int value_guess = (first_guess + second_guess + third_guess + fourth_guess) / 4;
    if (value_guess > 100) {
        if (value_guess > 200) {
            value_guess += (value_guess - 200) / -2;
        }
        value_guess += (value_guess * 3 - 300) / 2;
    }
    return value_guess;
}

struct CostOffset_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct CostEntity_guess;

struct CostThreshold_guess {
    char padding_0000_guess[0xad];
    unsigned char state_00ad_guess;
    char padding_00ae_guess[0x22];
    unsigned int deadline_guess;
    char padding_00d4_guess[0x88];
    CostEntity_guess* linked_entity_guess;
    char padding_0160_guess[0xe38];
    int value_0f98_guess;
    char padding_0f9c_guess[0x98];
    int value_1034_guess;
    char padding_1038_guess[0x28];
    int value_1060_guess;
};

struct CostOwner_guess;
struct DamagePc_guess;
struct DamageBuff_guess;
struct DamageTarget_guess;
struct DamageRecord_guess;

struct CostEntity_guess {
    char padding_0000_guess[0x2c];
    float multiplier_guess;
    char padding_0030_guess[0x18];
    float reset_value_guess;
    char padding_004c_guess[0x15c];
    CostThreshold_guess* threshold_guess;
    char padding_01ac_guess[6];
    unsigned char linkdead_01b2_guess;
    char padding_01b3_guess[3];
    unsigned char flag_01b6_guess;
    char padding_01b7_guess[0x4d];
    int value_0204_guess;
    char padding_0208_guess[0x10];
    CostOwner_guess* owner_guess;
    char padding_021c_guess[0x28];
    unsigned char state_guess;
    char padding_0245_guess[7];
    unsigned char level_guess;
    char padding_024d_guess[4];
    unsigned char stand_state_guess;
    unsigned char playerClass_0252_guess;
    char padding_0253_guess[3];
    unsigned char gm_0256_guess;
    char padding_0257_guess[1];
    int spawn_id_guess;
    char padding_025c_guess[4];
    int race_0260_guess;
    char padding_0264_guess[0x10];
    int updated_value_0274_guess;
    char padding_0278_guess[0xc];
    int cached_value_guess;
    // EXTERNAL: TITANIUM 0x0047C2FB CostEntity_guess::GetPcClient_guess
    DamagePc_guess* GetPcClient_guess();
    // EXTERNAL: TITANIUM 0x00484DF5 CostEntity_guess::KnockedOut_guess
    void KnockedOut_guess();
};

struct CostCandidatePart_guess {
    int unused_guess;
    int flag_index_guess;
};

struct CostTotalOwner_guess;

struct CostCandidate_guess {
    char padding_0000_guess[0xc280];
    void* vftable_c280_guess;  // the EQ_Character1 subobject (types.h EQ_PC +0xC280) starts here
    CostCandidatePart_guess* part_guess;
    char padding_c288_guess[0x104];
    unsigned char state_flags_guess[1];
    // EXTERNAL: TITANIUM 0x005ED510 CostCandidate_guess::GetCurrentValue_guess
    unsigned char GetCurrentValue_guess();
    // EXTERNAL: TITANIUM 0x005ED550 CostCandidate_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005ED570 CostCandidate_guess::SetValue_guess
    void SetValue_guess(int value_guess);
    CostTotalOwner_guess* Character1_guess() {
        return reinterpret_cast<CostTotalOwner_guess*>(&vftable_c280_guess);
    }
};

struct CostDynamicBase_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual CostCandidate_guess* GetCandidate_guess();
};

struct CostDynamicBlock_guess : CostDynamicBase_guess, LookupService_guess {
};

struct CostDynamicBlockView_guess {
    CostDynamicBase_guess base_guess;
    LookupService_guess lookup_guess;
    // EXTERNAL: TITANIUM 0x0040E722 CostDynamicBlockView_guess::GetSkill_guess
    int GetSkill_guess(int index_guess);
};

struct CostDynamicFindBlock_guess {
    CostDynamicBase_guess base_guess;
    LookupService_guess lookup_guess;
};

struct QueryTarget_guess {
    // EXTERNAL: TITANIUM 0x005E0860 QueryTarget_guess::Check_guess
    int Check_guess(int first_guess, int second_guess, int mode_guess);
};

struct CostModifier_guess {
    int unused_guess;
    int value_guess;
};

struct CostTarget_guess {
    char padding_0000_guess[0x30];
    int value_0030_guess;
    char padding_0034_guess[0xbc];
    int value_00f0_guess;
};

struct CostRegistry_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 CostRegistry_guess::GetTarget_guess
    CostTarget_guess* GetTarget_guess(int index_guess);
};

#define g_costRegistry_guess EQ_GLOBAL(CostRegistry_guess*, 0x00985CC8)

// EXTERNAL: TITANIUM 0x0044A448 GetSkillCap_guess
int __cdecl GetSkillCap_guess(int maximum_guess, unsigned char state_guess, int index_guess,
                                        CostCandidate_guess* candidate_guess);
// EXTERNAL: TITANIUM 0x0044D0D0 CheckModifier_guess
char __cdecl CheckModifier_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0044A273 IsSkillClampedTo252_guess
int __cdecl IsSkillClampedTo252_guess(int index_guess);

struct DynamicPropertyProxy_guess;

struct CostOwner_guess {
    char padding_0000_guess[4];
    CostOffset_guess* offset_holder_guess;
    CostEntity_guess* pSpawn_0008_guess;
    int value_000c_guess;
    int value_0010_guess;
    int scale_guess;
    char padding_0018_guess[0xc];
    int level_0024_guess;
    char padding_0028_guess[8];
    int dispatch_value_guess;
    int value_0034_guess;
    int value_0038_guess;
    char padding_003c_guess[4];
    int value_0040_guess;
    char padding_0044_guess[4];
    int value_0048_guess;
    char padding_004c_guess[4];
    int bonus_guess;
    char padding_0054_guess[0x14];
    int value_0068_guess;
    char padding_006c_guess[4];
    int value_0070_guess;
    char padding_0074_guess[0x40];
    int value_00b4_guess;
    char padding_00b8_guess[0x48];
    unsigned char flag_0100_guess[0x184];
    int cached_value_guess;

    // EXTERNAL: TITANIUM 0x0040E934 CostOwner_guess::FindBuff_guess
    struct DamageBuff_guess* FindBuff_guess(int attrib_guess, int* index_guess);
    // EXTERNAL: TITANIUM 0x0040E934 CostOwner_guess::FindModifier_guess
    CostModifier_guess* FindModifier_guess(int id_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x00411F2F CostOwner_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(struct DamageBuff_guess* buff_guess);
    // EXTERNAL: TITANIUM 0x0040D933 CostOwner_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();
    // EXTERNAL: TITANIUM 0x00411F3D CostOwner_guess::ApplySpell_guess
    void ApplySpell_guess(int kind_guess, int spell_guess, int zero_guess, struct DamageTarget_guess target_guess,
                          int last_guess);
    // EXTERNAL: TITANIUM 0x0040F8A0 CostOwner_guess::Stun_guess
    void Stun_guess(int value_guess);
    int TakeDamage_guess(int damage_guess, struct DamageRecord_guess* record_guess, char notify_guess,
                         int unused4_guess, char mode_guess, int unused6_guess);
    void TakeEnvironmentalDamage_guess();
    bool CanISeeInvis_guess();

    // EXTERNAL: TITANIUM 0x004106A3 CostOwner_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
    int Max_HP_guess(int mode_guess);
    int Str_guess();
    int CheckQuery_guess(QueryTarget_guess* target_guess);
    int basesave_magic_guess();
    int save_magic_guess();
    int basesave_fire_guess();
    int save_fire_guess();
    int Cur_HP(int mode_guess);
    int Sta_guess();
    void StunMe_guess(unsigned int duration_guess, int second_guess, int third_guess);
    int Skill_guess(int kind_guess);
    int InnateSkillLevel_guess(unsigned char value_guess, unsigned char unused_guess);
    int defense_agility_bonus_guess();
    int TakeFallDamage_guess(float value_guess);
    int compute_defense_guess();
    void ProcessDrunkenness_guess();
    char CheckDualWield_guess(int unused_guess);
    float encum_factor_guess();
    int CalculateWeight_guess();
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return reinterpret_cast<char*>(&offset_holder_guess) + offset_holder_guess->vbaseOffset_0004_guess;
    }
    CostDynamicBlock_guess* BaseBlock_guess() {
        return reinterpret_cast<CostDynamicBlock_guess*>(VirtualBase_guess());
    }
    CostDynamicFindBlock_guess* BaseFindBlock_guess() {
        return reinterpret_cast<CostDynamicFindBlock_guess*>(VirtualBase_guess());
    }
    DynamicPropertyProxy_guess* BaseProxy_guess() {
        return reinterpret_cast<DynamicPropertyProxy_guess*>(VirtualBase_guess());
    }
};

struct CostOwnerDispatch_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual int Dispatch_guess(int value_guess, int kind_guess);
};

struct CostChanceOwnerView_guess : CostOwnerDispatch_guess, virtual CostDynamicBlock_guess {
    char CanDoubleAttack_guess(int first_guess, int second_guess);
};

struct CostRollOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual int Slot04_guess(int value_guess, int kind_guess);
    CostOffset_guess* offset_holder_guess;
    CostEntity_guess* entity_guess;
    char padding_000c_guess[8];
    int unused_0014_guess;
    int first_value_guess;
    int second_value_guess;
    int intel_0020_guess;
    char padding_0024_guess[4];
    int wis_0028_guess;
    char padding_002c_guess[8];
    int value_0034_guess;
    char padding_0038_guess[8];
    int value_0040_guess;
    int basesave_cold_guess();
    int basesave_disease_guess();
    int save_disease_guess();
    int save_cold_guess();
    int Cha_guess();
    int Dex_guess();
    int Int_guess();
    int Wis_guess();
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return reinterpret_cast<char*>(&offset_holder_guess) + offset_holder_guess->vbaseOffset_0004_guess;
    }
    CostDynamicBlock_guess* BaseBlock_guess() {
        return reinterpret_cast<CostDynamicBlock_guess*>(VirtualBase_guess());
    }
};

#define g_costEnabled_guess EQ_GLOBAL(int, 0x009859EC)

struct CandidateBonusService_guess {
    // EXTERNAL: TITANIUM 0x004B4E35 CandidateBonusService_guess::GetHealthBonus_guess
    int GetHealthBonus_guess(CostCandidate_guess* candidate_guess);
    // EXTERNAL: TITANIUM 0x004B4F25 CandidateBonusService_guess::GetOffenseBonus_guess
    int GetOffenseBonus_guess(CostCandidate_guess* candidate_guess);
};

// Max_HP (name from the earlier sibling decomp): profile base HP (0x5FB8C0) plus that base scaled by the +0x14 stat
// (ScaleValue_guess), the item HP field (+0x50), SPA 69 TotalHP and, when flagged (0x40), the 0x9859EC
// GetHealthBonus_guess. `mode_guess` is the spawn type: a player (0) also gets SPA 214 MaxHPChange, in
// hundredths of a percent, and +5. Stored on the spawn (+0x284) and capped at 10,000,000:
// `reinterpret_cast<int>(EQ_ARRAY(char, 0x00989680))` is that constant, not an address.
// FUNCTION: TITANIUM 0x00416963
int CostOwner_guess::Max_HP_guess(int mode_guess) {
    CostDynamicBlock_guess* first_block_guess = BaseBlock_guess();
    int converted_guess = static_cast<int>(first_block_guess->Find_guess()->GetComputedFloat_guess());
    int result_guess = ScaleValue_guess(converted_guess, scale_guess);
    result_guess += bonus_guess;
    result_guess += converted_guess;
    int zero_guess = converted_guess - converted_guess;

    if (mode_guess == zero_guess) {
        int random_guess = TotalSpellAffects_guess(0xd6, 1, zero_guess, 1);
        result_guess += random_guess * result_guess / 10000;
    }

    if (pSpawn_0008_guess != reinterpret_cast<CostEntity_guess*>(zero_guess) && pSpawn_0008_guess->state_guess == 0) {
        CostCandidate_guess* candidate_guess = BaseBlock_guess()->GetCandidate_guess();
        CandidateBonusService_guess* bonus_service_guess =
            reinterpret_cast<CandidateBonusService_guess*>(g_costEnabled_guess);
        if (bonus_service_guess != reinterpret_cast<CandidateBonusService_guess*>(zero_guess) &&
            candidate_guess != reinterpret_cast<CostCandidate_guess*>(zero_guess) &&
            (candidate_guess->state_flags_guess[candidate_guess->part_guess->flag_index_guess] & 0x40) != 0) {
            result_guess += bonus_service_guess->GetHealthBonus_guess(candidate_guess);
        }
    }

    result_guess += TotalSpellAffects_guess(0x45, 1, zero_guess, 1);
    if (mode_guess == zero_guess) {
        result_guess += 5;
    }
    if (pSpawn_0008_guess != reinterpret_cast<CostEntity_guess*>(zero_guess)) {
        pSpawn_0008_guess->cached_value_guess = result_guess;
    }
    if (result_guess > reinterpret_cast<int>(EQ_ARRAY(char, 0x00989680))) {
        result_guess = reinterpret_cast<int>(EQ_ARRAY(char, 0x00989680));
    }
    return result_guess;
}

struct CostSource_guess {
    // EXTERNAL: TITANIUM 0x005E03D0 CostSource_guess::Load_guess
    void Load_guess(int* first_guess, int* second_guess, int* third_guess, int* fourth_guess,
                    int* fifth_guess, int flag_guess);
};

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int first_guess, int last_guess);

struct PropertyProxy_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual CostCandidate_guess* GetOwner_guess();
    LookupService_guess lookup_guess;
    void SetFirst_guess(int value_guess);
    void SetSecond_guess(int value_guess);
    void SetThird_guess(int value_guess);
    void AddThird_guess(int value_guess);
    void SetFourth_guess(int value_guess);
    void AddFourth_guess(int value_guess);
    void SetFifth_guess(int value_guess);
    void AddFifth_guess(int value_guess);
    void SetSixth_guess(int value_guess);
    void AddSixth_guess(int value_guess);
    void SetSeventh_guess(int value_guess);
    void SetEighth_guess(int value_guess);
    void SetArrayValue_guess(unsigned int index_guess, int value_guess);
};

struct ProfileHolder_guess : PropertyProxy_guess {
    LookupResult_guess* GetProfile_guess() {
        return lookup_guess.Find_guess();
    }
};

struct StatSourceRelated_guess {
    char padding_0000_guess[4];
    LookupService_guess lookup_guess;
    char padding_0008_guess[0x1058];
    int enabled_guess;
};

struct StatSource_guess {
    char padding_0000_guess[0x1a8];
    StatSourceRelated_guess* related_guess;
    char padding_01ac_guess[0x98];
    unsigned char state_guess;
    // EXTERNAL: TITANIUM 0x00479D99 StatSource_guess::Adjust_guess
    unsigned char Adjust_guess(int value_guess);
};

struct CharacterStatsHead_guess {
    virtual void Slot00_guess();
};

struct CharacterStats_guess : CharacterStatsHead_guess, virtual ProfileHolder_guess {
    virtual void Slot00_guess();
    StatSource_guess* source_guess;
    int value_000c_guess;
    int value_0010_guess;
    int value_0014_guess;
    char padding_0018_guess[4];
    int value_001c_guess;
    char padding_0020_guess[4];
    int value_0024_guess;
    char padding_0028_guess[0x58 - 0x28];
    int value_0058_guess;
    char padding_005c_guess[0xa4 - 0x5c];
    int value_00a4_guess;
    // EXTERNAL: TITANIUM 0x004106A3 CharacterStats_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int affect_guess, bool includeAlt_guess, int subindex_guess, bool includeItems_guess);
    // EXTERNAL: TITANIUM 0x0040E9C7 CharacterStats_guess::GetBuffLevelBySpell_guess
    char GetBuffLevelBySpell_guess(int value_guess);
    int Max_Endurance();
    int Cur_Endurance_guess();
    int compute_tohit_guess(unsigned char mode_guess);
    int offense_guess(unsigned char stat_guess);
};

// Profile base endurance (0x5FBA90) plus base * AdjustAverage_guess of the stat fields +0x24, +0x1C, +0x14
// and +0x10 / 200, SPA 190 EndurancePool and the item endurance field +0x58; never below 0.
// FUNCTION: TITANIUM 0x00416A40
// @early-stop: budget, diff ndiff=2
int CharacterStats_guess::Max_Endurance() {
    int base_guess = GetProfile_guess()->GetValue1240_guess();
    int average_guess = AdjustAverage_guess(value_0024_guess, value_001c_guess, value_0014_guess, value_0010_guess);
    int spell_guess = TotalSpellAffects_guess(0xbe, true, 0, true);
    int result_guess = average_guess * base_guess / 200 + base_guess + spell_guess + value_0058_guess;
    if (result_guess < 0) {
        result_guess = 0;
    }
    return result_guess;
}

struct CostTally_guess {
    char padding_0000_guess[0x30];
    int value_0030_guess;
    int value_0034_guess;
    int value_0038_guess;
    int value_003c_guess;
    int value_0040_guess;
    int SumScaled_guess(CostSource_guess* source_guess, int unused_guess);
};

// Sums the five values CostSource_guess::Load_guess (0x5E03D0) gives, probably a weapon's elemental damage,
// each against this character's matching resist field (+0x30..+0x40, as in the save_* functions below):
// a field above 200 blocks it; otherwise it keeps (rand(0, 200) - field)% when that is 1-99, all of it at
// 100 or more, and nothing at 0 or less.
// FUNCTION: TITANIUM 0x00416AA6
int CostTally_guess::SumScaled_guess(CostSource_guess* source_guess, int unused_guess) {
    int value_0038_guess, value_0034_guess, value_0030_guess, value_0040_guess, value_003c_guess;
    value_0038_guess = value_0034_guess = value_0030_guess = value_0040_guess = value_003c_guess = 0;
    if (source_guess != 0) {
        source_guess->Load_guess(&value_0038_guess, &value_0034_guess, &value_0030_guess,
                                 &value_003c_guess, &value_0040_guess, 1);
        if (value_0038_guess != 0) {
            if (this->value_0038_guess < 0xc9) {
                int difference_guess = RandomRange_guess(0, 200) - this->value_0038_guess;
                if (difference_guess >= 1) {
                    if (difference_guess < 100) {
                        value_0038_guess = difference_guess * value_0038_guess / 100;
                    }
                } else {
                    value_0038_guess = 0;
                }
            } else {
                value_0038_guess = 0;
            }
        }
        if (value_0034_guess != 0) {
            if (this->value_0034_guess < 0xc9) {
                int difference_guess = RandomRange_guess(0, 200) - this->value_0034_guess;
                if (difference_guess >= 1) {
                    if (difference_guess < 100) {
                        value_0034_guess = difference_guess * value_0034_guess / 100;
                    }
                } else {
                    value_0034_guess = 0;
                }
            } else {
                value_0034_guess = 0;
            }
        }
        if (value_0030_guess != 0) {
            if (this->value_0030_guess < 0xc9) {
                int difference_guess = RandomRange_guess(0, 200) - this->value_0030_guess;
                if (difference_guess >= 1) {
                    if (difference_guess < 100) {
                        value_0030_guess = difference_guess * value_0030_guess / 100;
                    }
                } else {
                    value_0030_guess = 0;
                }
            } else {
                value_0030_guess = 0;
            }
        }
        if (value_003c_guess != 0) {
            if (this->value_003c_guess < 0xc9) {
                int difference_guess = RandomRange_guess(0, 200) - this->value_003c_guess;
                if (difference_guess >= 1) {
                    if (difference_guess < 100) {
                        value_003c_guess = difference_guess * value_003c_guess / 100;
                    }
                } else {
                    value_003c_guess = 0;
                }
            } else {
                value_003c_guess = 0;
            }
        }
        if (value_0040_guess != 0) {
            if (this->value_0040_guess < 0xc9) {
                int difference_guess = RandomRange_guess(0, 200) - this->value_0040_guess;
                if (difference_guess >= 1) {
                    if (difference_guess < 100) {
                        value_0040_guess = difference_guess * value_0040_guess / 100;
                    }
                } else {
                    value_0040_guess = 0;
                }
            } else {
                value_0040_guess = 0;
            }
        }
    }
    return value_003c_guess + value_0040_guess + value_0030_guess + value_0034_guess +
           value_0038_guess;
}

struct LookupOffset_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct DynamicPropertyProxy_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual struct DynamicPropertyWidget_guess* GetWidget_guess();
    LookupService_guess lookup_guess;
    char padding_0008_guess[0xf8];
    int property_value_guess;
    unsigned char flag_0104_guess;
    // EXTERNAL: TITANIUM 0x0040E722 DynamicPropertyProxy_guess::GetSkill_guess
    int GetSkill_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0040E2A8 DynamicPropertyProxy_guess::AddField11A8_guess
    void AddField11A8_guess(int value_guess);
    LookupResult_guess* FindResult_guess() {
        return lookup_guess.Find_guess();
    }
    // EXTERNAL: TITANIUM 0x0040E2BD DynamicPropertyProxy_guess::Update_guess
    void Update_guess(int value_guess);
};

struct DynamicPropertyWidget_guess {
    // EXTERNAL: TITANIUM 0x004BB01D DynamicPropertyWidget_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005ED840 DynamicPropertyWidget_guess::FUN_005ed840_guess
    char FUN_005ed840_guess();
    // EXTERNAL: TITANIUM 0x005ED4B0 DynamicPropertyWidget_guess::GetDeity_guess
    int GetDeity_guess();
    int GetDynamicBitMask_guess();
};

// This character's deity (0x5ED4B0, probably) as an item deity-mask bit.
// FUNCTION: TITANIUM 0x0041680E
// @early-stop: budget, diff ndiff=3
int DynamicPropertyWidget_guess::GetDynamicBitMask_guess() {
    return 1 << (MapDynamicValue_guess(GetDeity_guess()) - 1);
}

struct LookupOption_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 LookupOption_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC8B0 LookupOption_guess::GetStateFlags_guess
    int GetStateFlags_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005EC990 LookupOption_guess::GetFeatureFlags_guess
    int GetFeatureFlags_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005EC920 LookupOption_guess::GetSelectionFlags_guess
    int GetSelectionFlags_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005ECC00 LookupOption_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECAA0 LookupOption_guess::GetMaximum_guess
    int GetMaximum_guess(int index_guess);
};

struct DynamicPropertyThreshold_guess {
    char padding_0000_guess[0xac];
    unsigned char state_guess;
    char padding_00ad_guess[0x7b];
    unsigned int next_time_guess;
    char padding_012c_guess[0x27];
    unsigned char charges_guess;
};

struct ChargeSink_guess;

struct DynamicPropertyInput_guess {
    char padding_0000_guess[0x1a8];
    DynamicPropertyThreshold_guess* threshold_guess;
    char padding_01ac_guess[0x98];
    unsigned char type_0244_guess;
    char padding_0245_guess[0xb];
    unsigned char hide_mode_guess;
    char padding_0251_guess[7];
    unsigned short spawn_id_guess;
    // EXTERNAL: TITANIUM 0x0047C10D DynamicPropertyInput_guess::SetState_guess
    void SetState_guess(unsigned char state_guess);
    // EXTERNAL: TITANIUM 0x00480409 DynamicPropertyInput_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
    // EXTERNAL: TITANIUM 0x0047C08E DynamicPropertyInput_guess::GetObject_guess
    ChargeSink_guess* GetObject_guess();
};

struct ChargeSink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Notify_guess(unsigned char kind_guess, int first_guess, int second_guess,
                              float scale_guess, int flag_guess);
};

struct ChargeRecord_guess {
    unsigned short spawn_id_guess;
    unsigned char type_guess;
    unsigned char value_guess;
};

#define g_chargeTarget_guess EQ_GLOBAL(DynamicPropertyInput_guess*, 0x00905D04)
#define g_chargeSkip_guess EQ_GLOBAL(DynamicPropertyInput_guess*, 0x00905CF8)

struct PropertyFilter_guess {
    // EXTERNAL: TITANIUM 0x005F6C40 PropertyFilter_guess::Check_guess
    char Check_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F6D00 PropertyFilter_guess::CheckFirst_guess
    char CheckFirst_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F6CC0 PropertyFilter_guess::CheckSecond_guess
    char CheckSecond_guess(int value_guess);
};

#define g_propertyFilter_guess EQ_GLOBAL(PropertyFilter_guess*, 0x00905CC0)

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    char* getString(int id_guess, int zero_guess, int channel_guess, int state_guess);
};

struct FactorTextSink_guess {
    // EXTERNAL: TITANIUM 0x004982C6 FactorTextSink_guess::dsp_chat
    void dsp_chat(char* text_guess);
};

#define g_factorState_guess EQ_GLOBAL(int, 0x0092387C)
#define g_factorTextTable_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_factorTextSink_guess EQ_GLOBAL(FactorTextSink_guess*, 0x00988DF0)
#define g_factorProperty_guess EQ_GLOBAL(int, 0x00924470)

struct FactorDynamic_guess {
    char padding_0000_guess[8];
    LookupService_guess lookup_guess;
    char padding_000c_guess[0x104];
    char flag_0110_guess;
};

struct DynamicPropertyBoundProxy_guess {
    char padding_0000_guess[4];
    LookupService_guess lookup_guess;
    // EXTERNAL: TITANIUM 0x0040E293 DynamicPropertyBoundProxy_guess::SetAllowedValue_guess
    void SetAllowedValue_guess(int value_guess);
};

struct IndexedPropertyProxy_guess;

struct DynamicPropertyOwner_guess {
    int unused_guess;
    union {
        LookupOffset_guess* offset_holder_guess;
        char table_bytes_guess[1];
    };
    DynamicPropertyInput_guess* input_guess;
    char padding_000c_guess[0x30];
    int value_003c_guess;
    char padding_0040_guess[8];
    int value_0048_guess;
    char padding_004c_guess[0x50];
    int value_009c_guess;
    DynamicPropertyProxy_guess* GetTable_guess() {
        return reinterpret_cast<DynamicPropertyProxy_guess*>(
            &table_bytes_guess[offset_holder_guess->vbaseOffset_0004_guess]);
    }
    int GetClassRaceACBonus_guess(int level_guess);
    void AddEncodedValue_guess(int value_guess);
    int GetQueriedValue_guess();
    int basesave_poison_guess();
    char* RaceName_guess(int index_guess);
    void ShowRingString_guess(int index_guess);
    int IsSpellcaster_guess();
    bool CanBreathe_guess();
    void ApplyEnduranceUpkeep_guess();
    bool IsIntCaster_guess();
    int HasSpell_guess(int value_guess);
    int CanUseItem_guess(LookupOption_guess* option_guess, int unused_guess);
    __int64 GetEncodedValue_guess();
    void ApplyEncodedValue_guess(int value_guess);
    void ConsumeCharge_guess();
    int save_poison_guess();
    char CanWorship_guess(int skill_guess, int column_guess, int row_guess);
    int CalculateScaledValue_guess(struct QueryMode_guess* mode_guess, int value_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x00411F2F DynamicPropertyOwner_guess::Finish_guess
    void Finish_guess(int value_guess);
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return &table_bytes_guess[offset_holder_guess->vbaseOffset_0004_guess];
    }
    IndexedPropertyProxy_guess* BaseIndexedProxy_guess() {
        return reinterpret_cast<IndexedPropertyProxy_guess*>(VirtualBase_guess());
    }
    PropertyProxy_guess* BasePropertyProxy_guess() {
        return reinterpret_cast<PropertyProxy_guess*>(VirtualBase_guess());
    }
};

struct DynamicPropertyBoundOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual int GetAllowedValue_guess();
    union {
        LookupOffset_guess* offset_holder_guess;
        char table_bytes_guess[1];
    };
    CostEntity_guess* entity_guess;
    char padding_000c_guess[0xa0];
    int value_00ac_guess;
    int Cur_Mana_guess();
    DynamicPropertyProxy_guess* GetTable_guess() {
        return reinterpret_cast<DynamicPropertyProxy_guess*>(
            &table_bytes_guess[offset_holder_guess->vbaseOffset_0004_guess]);
    }
    LookupResult_guess* ResolveResult_guess() {
        DynamicPropertyProxy_guess* table_guess = GetTable_guess();
        return table_guess->lookup_guess.Find_guess();
    }
    void RegenMana_guess();
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return &table_bytes_guess[offset_holder_guess->vbaseOffset_0004_guess];
    }
    DynamicPropertyBoundProxy_guess* BaseBoundProxy_guess() {
        return reinterpret_cast<DynamicPropertyBoundProxy_guess*>(VirtualBase_guess());
    }
};

// The profile dword at +0x125C.
// FUNCTION: TITANIUM 0x00416C13
int DynamicPropertyOwner_guess::GetQueriedValue_guess() {
    DynamicPropertyProxy_guess* proxy_guess = GetTable_guess();
    return proxy_guess->lookup_guess.Find_guess()->queried_value_guess;
}

#define g_stringCounter_guess EQ_GLOBAL(int, 0x0079DB10)
#define g_stringRing_guess EQ_ARRAY(char, 0x0079D890)

// Class name (ClassName in the earlier sibling decomp). Classes 1-16 are copied into the next of ten 64-byte ring
// buffers (0x79D890), so several names can be live at once; GM trainers (20-35), Banker (40), Merchant
// (41) and Guild Banker (66) return the string-table text itself; anything else string 0x5CC. Each class
// name id (0x5DE + 4 * (class - 1)) is followed by the three title ids KunarkClass_guess uses.
// FUNCTION: TITANIUM 0x00416C2C
char* ClassName_guess(int id_guess) {
    int slot_guess = g_stringCounter_guess % 10;
    char* buf_guess = g_stringRing_guess + slot_guess * 0x40;
    g_stringCounter_guess++;
    switch (id_guess) {
    case 1:
        strcpy(buf_guess, pStringTable->getString(0x5de, 0));
        break;
    case 2:
        strcpy(buf_guess, pStringTable->getString(0x5e2, 0));
        break;
    case 3:
        strcpy(buf_guess, pStringTable->getString(0x5e6, 0));
        break;
    case 5:
        strcpy(buf_guess, pStringTable->getString(0x5ea, 0));
        break;
    case 4:
        strcpy(buf_guess, pStringTable->getString(0x5ee, 0));
        break;
    case 6:
        strcpy(buf_guess, pStringTable->getString(0x5f2, 0));
        break;
    case 7:
        strcpy(buf_guess, pStringTable->getString(0x5f6, 0));
        break;
    case 8:
        strcpy(buf_guess, pStringTable->getString(0x5fa, 0));
        break;
    case 9:
        strcpy(buf_guess, pStringTable->getString(0x5fe, 0));
        break;
    case 10:
        strcpy(buf_guess, pStringTable->getString(0x602, 0));
        break;
    case 11:
        strcpy(buf_guess, pStringTable->getString(0x606, 0));
        break;
    case 12:
        strcpy(buf_guess, pStringTable->getString(0x60a, 0));
        break;
    case 13:
        strcpy(buf_guess, pStringTable->getString(0x60e, 0));
        break;
    case 14:
        strcpy(buf_guess, pStringTable->getString(0x612, 0));
        break;
    case 15:
        strcpy(buf_guess, pStringTable->getString(0x616, 0));
        break;
    case 16:
        strcpy(buf_guess, pStringTable->getString(0x169f, 0));
        break;
    case 0x14:
        return pStringTable->getString(0x5cf, 0);
    case 0x15:
        return pStringTable->getString(0x5d0, 0);
    case 0x16:
        return pStringTable->getString(0x5d1, 0);
    case 0x18:
        return pStringTable->getString(0x5d2, 0);
    case 0x17:
        return pStringTable->getString(0x5d3, 0);
    case 0x19:
        return pStringTable->getString(0x5d4, 0);
    case 0x1a:
        return pStringTable->getString(0x5d5, 0);
    case 0x1b:
        return pStringTable->getString(0x5d6, 0);
    case 0x1c:
        return pStringTable->getString(0x5d7, 0);
    case 0x1d:
        return pStringTable->getString(0x5d8, 0);
    case 0x1e:
        return pStringTable->getString(0x5d9, 0);
    case 0x1f:
        return pStringTable->getString(0x5da, 0);
    case 0x20:
        return pStringTable->getString(0x5db, 0);
    case 0x21:
        return pStringTable->getString(0x5dc, 0);
    case 0x22:
        return pStringTable->getString(0x5dd, 0);
    case 0x23:
        return pStringTable->getString(0x16a0, 0);
    case 0x28:
        return pStringTable->getString(0x5ce, 0);
    case 0x29:
        return pStringTable->getString(0x5cd, 0);
    case 0x42:
        return pStringTable->getString(0x17de, 0);
    default:
        return pStringTable->getString(0x5cc, 0);
    }
    return buf_guess;
}

struct SkillTable_guess {
    char HumanCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char BarbarianCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char EruditeCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char ElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char HighElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char DarkElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
};

// EXTERNAL: TITANIUM 0x00576670 HasArchive_guess
char __cdecl HasArchive_guess(const char* name_guess);

struct TableSelector_guess {
    char CheckClass_guess(int kind_guess, int column_guess);
};

// Whether a race may take a class at creation (CheckClass in the earlier sibling decomp): `kind_guess` is the
// race id - 1, `column_guess` the class - 1. Erudite (2) Shadow Knights and Necromancers (4, 10) also
// need the archive at 0x640F90 (paineel.s3d in the older client). Table 0x694F50, 16 classes per race row.
// FUNCTION: TITANIUM 0x00416E9C
// @early-stop: budget, diff ndiff=3
char TableSelector_guess::CheckClass_guess(int kind_guess, int column_guess) {
    if (kind_guess == 2 && (column_guess == 4 || column_guess == 10)) {
        char archive_guess = HasArchive_guess(EQ_ARRAY(char, 0x00640F90));
        if (archive_guess == 0) {
            return archive_guess;
        }
    }
    return EQ_ARRAY(char, 0x00694F50)[MapLookupValue_guess(kind_guess + 1) * 0x10 + column_guess];
}

// Deity tables for character creation, one per race (HumanCanWorship .. VahShirCanWorship in the earlier sibling
// decomp): row = deity index, column = class - 1; CanWorship (0x419E83) dispatches on race. PvP ruleset 4
// (0x923D58, g_pvpRulesetCopy_guess there) closes row 0. The fake-match setjmp blocks only force an
// EBP frame.
// Human: ruleset 4 adds row 15, column 6.
// FUNCTION: TITANIUM 0x00416EDB
char SkillTable_guess::HumanCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    if (g_lookupMode_guess == 4) {
        if (row_guess == 0xf) {
            if (column_guess == 6) {
                return 1;
            }
        } else if (row_guess == 0) {
            return 0;
        }
    }
    return EQ_ARRAY(char, 0x00695060)[row_guess * 0x10 + column_guess];
}

// Barbarian: ruleset 4 adds row 7, columns 0 and 9.
// FUNCTION: TITANIUM 0x00416F17
char SkillTable_guess::BarbarianCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    if (g_lookupMode_guess == 4) {
        if (row_guess == 7) {
            if (column_guess == 0 || column_guess == 9) {
                return 1;
            }
        } else if (row_guess == 0) {
            return 0;
        }
    }
    return EQ_ARRAY(char, 0x00695170)[row_guess * 0x10 + column_guess];
}

// Erudite: row 3 also needs the 0x640F90 archive.
// FUNCTION: TITANIUM 0x00416F59
char SkillTable_guess::EruditeCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    unsigned char row_copy_guess = row_guess;
    if (row_copy_guess != 3 || HasArchive_guess(EQ_ARRAY(char, 0x00640F90))) {
        if (g_lookupMode_guess == 4) {
            if (row_copy_guess == 0) {
                return 0;
            }
            return EQ_ARRAY(char, 0x00695280)[row_copy_guess * 0xe + column_guess];
        }
        return EQ_ARRAY(char, 0x00695280)[row_copy_guess * 0xe + column_guess];
    }
    return 0;
}

// Wood Elf (ElfCanWorship); ruleset 4 also closes row 16.
// FUNCTION: TITANIUM 0x00416F99
char SkillTable_guess::ElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && (row_guess == 0 || row_guess == 0x10)) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695370)[row_guess * 0xe + column_guess];
}

// High Elf (HighElfCanWorship).
// FUNCTION: TITANIUM 0x00416FCB
char SkillTable_guess::HighElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695460)[row_guess * 0xe + column_guess];
}

// Dark Elf (DarkElfCanWorship).
// FUNCTION: TITANIUM 0x00416FF7
char SkillTable_guess::DarkElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695550)[row_guess * 0xe + column_guess];
}

struct TableLookup_guess {
    char DwarfCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char TrollCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char OgreCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char HalfElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char HalflingCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char GnomeCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char IksarCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char VahShirCanWorship_guess(unsigned char column_guess, unsigned char row_guess);
    char CityCanStart_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
};

// Half Elf: ruleset 2 allows only row 14.
// FUNCTION: TITANIUM 0x00417023
char TableLookup_guess::HalfElfCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    if (g_lookupMode_guess == 2) {
        return row_guess == 0xe;
    }
    if (g_lookupMode_guess == 4) {
        if (row_guess == 0) {
            return 0;
        }
        return EQ_ARRAY(char, 0x00695640)[row_guess * 0xe + column_guess];
    }
    return EQ_ARRAY(char, 0x00695640)[row_guess * 0xe + column_guess];
}

// Dwarf (DwarfCanWorship).
// FUNCTION: TITANIUM 0x0041705E
char TableLookup_guess::DwarfCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695730)[row_guess * 0x10 + column_guess];
}

// Troll (TrollCanWorship).
// FUNCTION: TITANIUM 0x0041708A
char TableLookup_guess::TrollCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695840)[row_guess * 0x10 + column_guess];
}

// Ogre (OgreCanWorship).
// FUNCTION: TITANIUM 0x004170B6
char TableLookup_guess::OgreCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695950)[row_guess * 0x10 + column_guess];
}

// Halfling: ruleset 4 also closes row 16.
// FUNCTION: TITANIUM 0x004170E2
char TableLookup_guess::HalflingCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && (row_guess == 0 || row_guess == 0x10)) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695A60)[row_guess * 0xe + column_guess];
}

// Gnome (GnomeCanWorship).
// FUNCTION: TITANIUM 0x00417114
char TableLookup_guess::GnomeCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695B50)[row_guess * 0x0e + column_guess];
}

// Iksar (IksarCanWorship); its rows are 15 wide.
// FUNCTION: TITANIUM 0x00417140
char TableLookup_guess::IksarCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
    }
    if (g_lookupMode_guess == 4 && row_guess == 0) {
        return 0;
    }
    return EQ_ARRAY(char, 0x00695C40)[row_guess * 0x0f + column_guess];
}

// Vah Shir: outside ruleset 4 only row 0, no table.
// FUNCTION: TITANIUM 0x0041716C
char TableLookup_guess::VahShirCanWorship_guess(unsigned char column_guess, unsigned char row_guess) {
    if (g_lookupMode_guess == 4) {
        if (row_guess == 0) {
            return 0;
        }
        return EQ_ARRAY(char, 0x00695D40)[row_guess * 0x10 + column_guess];
    }
    return row_guess == 0;
}

// Whether a new character may start in city `first_guess` (CityCanStart in the earlier sibling decomp): `second_guess`
// is the race id - 1, `third_guess` the class, `fourth_guess` the deity. Iksar, Vah Shir and Froglok have
// one city each (12, 13, 14); Human and Half Elf carry class/deity exceptions and the ruleset 2/4 rules;
// then table 0x695F60, 12 cities per race.
// FUNCTION: TITANIUM 0x004171A1
// @early-stop: budget, structural ndiff=209
char TableLookup_guess::CityCanStart_guess(int first_guess, int second_guess, int third_guess, int fourth_guess) {
    switch (second_guess + 1) {
    case 0x80:
        return first_guess == 0xc;
    case 0x82:
        return first_guess == 0xd;
    case 0x14a:
        return first_guess == 0xe;
    }
    if (first_guess > 0xb) {
        return 0;
    }
    if (second_guess + 1 == 1) {
        if (first_guess != 4 &&
            (third_guess == 6 || third_guess == 7 || third_guess == 4 ||
             (fourth_guess == 6 && third_guess == 0xa))) {
            return 0;
        }
        if (first_guess != 1 &&
            (third_guess == 1 || third_guess == 8 || third_guess == 5 ||
             (fourth_guess == 6 &&
              ((g_lookupMode_guess == 4 && third_guess == 0xf) || third_guess == 0)))) {
            return 0;
        }
        if ((fourth_guess == 5 || fourth_guess == 3) && first_guess != 1) {
            return 0;
        }
    }
    if (second_guess + 1 == 7) {
        if (g_lookupMode_guess == 2 && first_guess != 9 && first_guess != 0xa) {
            return 0;
        }
        if (first_guess != 4 && (third_guess == 4 || third_guess == 6 || third_guess == 7)) {
            return 0;
        }
        if (first_guess != 1 && (third_guess == 1 || third_guess == 5 || third_guess == 8)) {
            return 0;
        }
        if (fourth_guess == 3 &&
            ((first_guess != 1 && first_guess != 9) || (first_guess == 9 && third_guess != 0xe))) {
            return 0;
        }
        if (first_guess != 9 && third_guess == 0xe && (fourth_guess == 0 || fourth_guess == 8)) {
            return 0;
        }
        if (fourth_guess == 5 && third_guess == 0xe && first_guess != 9 && first_guess != 1) {
            return 0;
        }
        if (fourth_guess == 2 && third_guess == 0xe) {
            if (first_guess != 0xa) {
                return 0;
            }
        } else if (first_guess == 0xa) {
            return 0;
        }
    }
    return EQ_ARRAY(char, 0x00695f60)[second_guess * 0xc + first_guess];
}

#include "titanium/layouts/core.h"
#include "titanium/wnd/CBandolierWnd.h"
#include "titanium/wnd/CCompassWnd.h"
#include "titanium/wnd/CPotionBeltWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CDynamicZoneWnd.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CSkillsWnd.h"
#include "titanium/wnd/CTrackingWnd.h"

struct ValueData_guess {
    char padding_0000_guess[0x104];
    int value_guess;
};

struct ValueChecker_guess {
    // EXTERNAL: TITANIUM 0x005F6D00 ValueChecker_guess::Check_guess
    char Check_guess(int value_guess);
};

struct ActiveState_guess {
    // EXTERNAL: TITANIUM 0x004903C2 ActiveState_guess::IsActive_guess
    char IsActive_guess();
};

struct ActiveStateLink_guess {
    char padding_0000_guess[0xf94];
    ActiveState_guess* state_guess;
};

struct ActiveStateOwner_guess {
    char padding_0000_guess[0x1a8];
    ActiveStateLink_guess* link_guess;
};

struct ValueOwner_guess {
    int unused_guess;
    VBTable* vbaseOffset_0004_guess;
    bool IsActiveFor_guess(ActiveStateOwner_guess* owner_guess);
};

#define g_valueChecker_guess EQ_GLOBAL(ValueChecker_guess*, 0x00905CC0)

// Race base value of stat `column_guess` (0-6) from byte table 0x695FE9, 7 per race row; ClassMin
// (0x419DFD) reads it as `base_guess`.
// FUNCTION: TITANIUM 0x00417355
// @early-stop: budget, diff ndiff=3
char __stdcall GetTableEntry_guess(int value_guess, unsigned char column_guess) {
    int row_guess = MapLookupValue_guess(value_guess + 1);
    return EQ_ARRAY(char, 0x00695FE9)[row_guess * 7 + column_guess];
}

// True when the global checker (0x00905CC0) accepts this object's value and `owner`'s linked state
// reports itself active; the bazaar window uses it.
// FUNCTION: TITANIUM 0x00417373
// @early-stop: budget, structural ndiff=10
bool ValueOwner_guess::IsActiveFor_guess(ActiveStateOwner_guess* owner_guess) {
    ValueData_guess* data_guess = reinterpret_cast<ValueData_guess*>(
        &reinterpret_cast<unsigned char*>(this)[vbaseOffset_0004_guess->vbase_offset]);
    if (g_valueChecker_guess->Check_guess(data_guess->value_guess) == 0 || owner_guess == 0 ||
        owner_guess->link_guess == 0 || owner_guess->link_guess->state_guess == 0) {
        return false;
    }
    return owner_guess->link_guess->state_guess->IsActive_guess() != 0;
}

struct PlayerSearchOwner_guess {
    int padding_0000_guess[2];
    EQPlayer* player_guess;
    EQPlayer* FindClosest_guess(int mode_guess, unsigned int first_id_guess,
        unsigned int second_id_guess, unsigned int third_id_guess, unsigned int fourth_id_guess);
};

struct DistanceService_guess {
    // EXTERNAL: TITANIUM 0x00439BD1 DistanceService_guess::SimpleDistance_guess
    float SimpleDistance_guess(float first_y_guess, float first_x_guess, float first_z_guess,
        float second_y_guess, float second_x_guess, float second_z_guess, float flag_guess);
};

struct ActorInfoSearch_guess {
    int padding_0000_guess[0x160 / 4];
    int rider_0160_guess;
};

#define g_spawnList_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)
#define g_distanceService_guess EQ_GLOBAL(DistanceService_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00401B28 FindSpawnByID_guess
EQPlayer* __cdecl FindSpawnByID_guess(unsigned int id_guess);

// Nearest spawn within 10000: `mode_guess` 0 looks at corpses (types 2 and 3); 1 at NPCs of one of the four
// body types that no player owns (and whose actor info +0x160 is 0).
// FUNCTION: TITANIUM 0x00417669
// @early-stop: budget, structural ndiff=86
EQPlayer* PlayerSearchOwner_guess::FindClosest_guess(int mode_guess, unsigned int first_id_guess,
    unsigned int second_id_guess, unsigned int third_id_guess, unsigned int fourth_id_guess) {
    EQPlayer* result_guess = 0;
    float closest_guess = 10000.0f;
    if (player_guess == 0) {
        return 0;
    }
    if (mode_guess == 0) {
        for (EQPlayer* candidate_guess = g_spawnList_guess; candidate_guess != 0;
            candidate_guess = candidate_guess->pNext) {
            if (candidate_guess->Type == 2 || candidate_guess->Type == 3) {
                float distance_guess = g_distanceService_guess->SimpleDistance_guess(
                    player_guess->Y, player_guess->X, player_guess->Z,
                    candidate_guess->Y, candidate_guess->X, candidate_guess->Z, 0.0f);
                if (distance_guess < closest_guess) {
                    closest_guess = distance_guess;
                    result_guess = candidate_guess;
                }
            }
        }
    } else if (mode_guess == 1) {
        for (EQPlayer* candidate_guess = g_spawnList_guess; candidate_guess != 0;
            candidate_guess = candidate_guess->pNext) {
            if (candidate_guess->Type == 1 && candidate_guess->pActorInfo != 0 &&
                static_cast<ActorInfoSearch_guess*>(candidate_guess->pActorInfo)->rider_0160_guess == 0 &&
                (candidate_guess->BodyType == first_id_guess || candidate_guess->BodyType == second_id_guess ||
                 candidate_guess->BodyType == third_id_guess || candidate_guess->BodyType == fourth_id_guess)) {
                unsigned int master_id_guess = candidate_guess->MasterID;
                if (master_id_guess != player_guess->SpawnID) {
                    EQPlayer* master_guess = 0;
                    if (master_id_guess != 0) {
                        master_guess = FindSpawnByID_guess(master_id_guess);
                    }
                    if (master_guess == 0 || master_guess->Type != 0) {
                        float distance_guess = g_distanceService_guess->SimpleDistance_guess(
                            player_guess->Y, player_guess->X, player_guess->Z,
                            candidate_guess->Y, candidate_guess->X, candidate_guess->Z, 0.0f);
                        if (distance_guess < closest_guess) {
                            closest_guess = distance_guess;
                            result_guess = candidate_guess;
                        }
                    }
                }
            }
        }
    }
    return result_guess;
}

struct CallerObject_guess {
    int ReturnZero_guess(int first_guess, int second_guess, int third_guess);
};

struct RefreshService_guess {
    char padding_0000_guess[0x10];
    unsigned char flag_0010_guess;
    char padding_0011_guess[0x137];
    unsigned int tick_guess;
    // EXTERNAL: TITANIUM 0x00438FDF RefreshService_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00438FC2 RefreshService_guess::Notify_guess
    void Notify_guess(int value_guess);
};

struct FlagTarget_guess {
    char padding_0000_guess[0xd0];
    int flag_guess;
};

struct FlagContainer_guess {
    char padding_0000_guess[0x1a8];
    FlagTarget_guess* target_guess;
};

struct FlagOffset_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct ResetObject_guess {
    char padding_0000_guess[4];
    FlagOffset_guess* vbaseOffset_0004_guess;
    FlagContainer_guess* container_guess;
    void UnStunMe_guess();
};

struct LookupCheckService_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 LookupCheckService_guess::Check_guess
    int Check_guess(int value_guess);
};

struct StringTableView2_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView2_guess::getString
    void* getString(int code_guess, int value_guess, int line_guess, int flag_guess);
};

struct ErrorReporter_guess {
    // EXTERNAL: TITANIUM 0x004982C6 ErrorReporter_guess::dsp_chat
    void dsp_chat(void* message_guess);
    // EXTERNAL: TITANIUM 0x004A1CE4 ErrorReporter_guess::CancelSneakHide
    void CancelSneakHide();
};

struct MessageSource_guess {
    char padding_0000_guess[0x244];
    unsigned char ready_guess;
    char padding_0245_guess[0x13];
    int record_id_guess;
};

struct MessageObject_guess {
    char padding_0000_guess[8];
    MessageSource_guess* source_guess;
    // EXTERNAL: TITANIUM 0x0040E7AC MessageObject_guess::GetBuff_guess
    const void* GetBuff_guess(int id_guess);
    void NotifyPCAffectChange_guess(int id_guess, int value_guess);
};

struct MessageRecord_guess {
    int record_id_guess;
    int bytes_guess[5];
    int id_guess;
    int value_guess;
};

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);
extern "C" void* __cdecl memcpy(void* destination_guess, const void* source_guess, unsigned int size_guess);

#define g_refreshService_guess EQ_GLOBAL(RefreshService_guess*, 0x00905D24)
#define g_lookupCheckService_guess EQ_GLOBAL(LookupCheckService_guess, 0x009248E0)
#define g_errorFactory_guess EQ_GLOBAL(StringTableView2_guess*, 0x00905CB0)
#define g_errorReporter_guess EQ_GLOBAL(ErrorReporter_guess*, 0x00988DF0)

// Ends a stun (the opposite of StunMe, 0x417839): clears the stun end time (+0x1A8 -> +0xD0)
// and flag and, unless check 0x1A of 0x9248E0 passes, prints string 0x30C0.
// FUNCTION: TITANIUM 0x00417948
void ResetObject_guess::UnStunMe_guess() {
    g_refreshService_guess->Refresh_guess();
    container_guess->target_guess->flag_guess = 0;
    reinterpret_cast<unsigned char*>(this)[vbaseOffset_0004_guess->vbaseOffset_0004_guess + 0x100] = 0;
    if (g_lookupCheckService_guess.Check_guess(0x1a) == 0) {
        void* message_guess = g_errorFactory_guess->getString(0x30c0, 0, 0x154, 1);
        g_errorReporter_guess->dsp_chat(message_guess);
    }
}

// Sends OP_Buff for buff slot `id_guess` while the spawn is a player: spawn id (+0x258), the 20-byte buff,
// the slot and `value_guess` (1 = fade), EQEmu's SpellBuffPacket layout.
// FUNCTION: TITANIUM 0x004179AA
void MessageObject_guess::NotifyPCAffectChange_guess(int id_guess, int value_guess) {
    MessageRecord_guess record_guess;
    memset(&record_guess, 0, 0x20);
    MessageSource_guess* source = source_guess;
    if (source != 0 && source->ready_guess == 0) {
        record_guess.record_id_guess = source->record_id_guess;
        record_guess.value_guess = value_guess;
        memcpy(record_guess.bytes_guess, GetBuff_guess(id_guess), 0x14);
        record_guess.id_guess = id_guess;
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Buff, &record_guess, 0x20, 1);
    }
}

struct SourceChild_guess {
    char padding_0000_guess[0x155];
    unsigned char value_0155_guess;
};

struct SourceRoot_guess {
    char padding_0000_guess[0x1a8];
    SourceChild_guess* child_guess;
    char padding_01ac_guess[0xa4];
    unsigned char hideMode_0250_guess;
    char padding_0251_guess[7];
    unsigned short spawnId_0258_guess;

    // EXTERNAL: TITANIUM 0x00480409 SourceRoot_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x0047C10D SourceRoot_guess::Clear_guess
    void Clear_guess(int mode_guess);
};

struct StateRecord_guess {
    unsigned short value_guess;
    unsigned short tag_guess;
    unsigned int flag_guess;
};

struct NotifyOwner_guess {
    char padding_0000_guess[8];
    SourceRoot_guess* pSpawn_0008_guess;
    // EXTERNAL: TITANIUM 0x0040E934 NotifyOwner_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int id_guess, int* out_guess);
    // EXTERNAL: TITANIUM 0x00411F2F NotifyOwner_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(int result_guess);
    void RemoveInvisibility_guess(int flag_guess);
};

// Breaks invisibility. `flag_guess` first clears +0x1A8 -> +0x155. With the spawn's +0x250 state set, it
// removes every invisibility buff (SPA 12, 28, 29, 314-316) with OP_Buff fades, sends OP_SpawnAppearance
// type 3 (invisible) with the new state and refreshes visibility (UpdatePlayerVisibility_guess).
// FUNCTION: TITANIUM 0x00417A1D
void NotifyOwner_guess::RemoveInvisibility_guess(int flag_guess) {
    if (pSpawn_0008_guess == 0) {
        return;
    }
    if (flag_guess != 0 && pSpawn_0008_guess->child_guess != 0) {
        pSpawn_0008_guess->child_guess->value_0155_guess = 0;
    }
    if (pSpawn_0008_guess->hideMode_0250_guess == 0) {
        return;
    }
    pSpawn_0008_guess->Clear_guess(0);
    RemovePCAffect_guess(FindBuffWithEffect_guess(0xc, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    RemovePCAffect_guess(FindBuffWithEffect_guess(0x1c, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    RemovePCAffect_guess(FindBuffWithEffect_guess(0x1d, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    RemovePCAffect_guess(FindBuffWithEffect_guess(0x13a, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    RemovePCAffect_guess(FindBuffWithEffect_guess(0x13b, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    RemovePCAffect_guess(FindBuffWithEffect_guess(0x13c, &flag_guess));
    if (flag_guess != -1) {
        reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(flag_guess, 1);
    }
    StateRecord_guess record_guess;
    record_guess.value_guess = pSpawn_0008_guess->spawnId_0258_guess;
    record_guess.tag_guess = 3;
    record_guess.flag_guess = pSpawn_0008_guess->hideMode_0250_guess;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_SpawnAppearance, &record_guess, 8, 1);
    g_errorReporter_guess->CancelSneakHide();
    pSpawn_0008_guess->Finish_guess();
}

// Empty member body emits the zero return and callee cleanup.
// FUNCTION: TITANIUM 0x00417834
int CallerObject_guess::ReturnZero_guess(int first_guess, int second_guess, int third_guess) {
    return 0;
}

// EXTERNAL: TITANIUM 0x0046D655 GetCurrentTime_guess
unsigned int __cdecl GetCurrentTime_guess();

// Stuns for `duration_guess` ms (StunMe in the earlier sibling decomp). Nothing under Divine Aura (SPA 40); a stun
// under 1 s is ignored for NPCs and lengthened to 1 s for players. Only when no stun runs: sets the end
// time and flag, stops the spawn (+0x48 speed, and its linked spawn's) and, unless check 0x1A of 0x9248E0
// passes, prints string 0x30BF. The SPA 229 total is read and thrown away.
// FUNCTION: TITANIUM 0x00417839
void CostOwner_guess::StunMe_guess(unsigned int duration_guess, int second_guess, int third_guess) {
    if (pSpawn_0008_guess == 0 || pSpawn_0008_guess->threshold_guess == 0) {
        return;
    }
    if (TotalSpellAffects_guess(0x28, 1, 0, 1) > 0) {
        return;
    }
    TotalSpellAffects_guess(0xe5, 1, 0, 1);
    if (duration_guess < 1000) {
        if (pSpawn_0008_guess == 0) {
            return;
        }
        if (pSpawn_0008_guess->state_guess != 0) {
            return;
        }
        duration_guess = 1000;
    }
    if (pSpawn_0008_guess->threshold_guess->deadline_guess == 0) {
        unsigned int deadline_guess = GetCurrentTime_guess() + duration_guess;
        if (pSpawn_0008_guess->threshold_guess->deadline_guess < deadline_guess) {
            pSpawn_0008_guess->threshold_guess->deadline_guess = deadline_guess;
        }
        flag_0100_guess[offset_holder_guess->vbaseOffset_0004_guess] = 1;
        g_refreshService_guess->Notify_guess(0x17);
        pSpawn_0008_guess->reset_value_guess = 0.0f;
        CostEntity_guess* linked_entity_guess = pSpawn_0008_guess->threshold_guess->linked_entity_guess;
        if (linked_entity_guess != 0) {
            linked_entity_guess->reset_value_guess = 0.0f;
        }
        if (g_lookupCheckService_guess.Check_guess(0x1a) == 0) {
            void* message_guess = g_errorFactory_guess->getString(0x30bf, 0, 0x154, 1);
            g_errorReporter_guess->dsp_chat(message_guess);
        }
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct AllocatedObject_guess {
    // EXTERNAL: TITANIUM 0x0041682F AllocatedObject_guess::Initialize_guess
    void Initialize_guess();
    // EXTERNAL: TITANIUM 0x005FA2C0 AllocatedObject_guess::Finish_guess
    void Finish_guess();
    void* Complete_guess(unsigned char flag);
};

struct Service_guess {
    // EXTERNAL: TITANIUM 0x0060CE70 Service_guess::GetOne_guess
    void* GetOne_guess();
    // EXTERNAL: TITANIUM 0x0060CEA0 Service_guess::GetTwo_guess
    void* GetTwo_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0060CED0 Service_guess::GetThree_guess
    void* GetThree_guess(int first_guess, int second_guess);
};

// EXTERNAL: TITANIUM 0x0041002F InitializeOne_guess
void __cdecl InitializeOne_guess();
// EXTERNAL: TITANIUM 0x0040FEAA InitializeThree_guess
void __cdecl InitializeThree_guess();

struct WrapperObject_guess {
    char padding_c4_guess[0xc4];
    Service_guess service_guess;
    char padding_c8_guess[3];
    unsigned char first_flag_guess;
    char padding_d0_guess[7];
    unsigned char second_flag_guess;

    void* GetOne_guess();
    void* GetTwo_guess(int first_guess, int second_guess);
    void* GetThree_guess(int first_guess, int second_guess);
};

// Pass-throughs to the service at +0xC4; GetTwo_guess and GetThree_guess first run their one-time
// initializers (0x41002F, 0x40FEAA) while the flags +0xC8 / +0xD0 are clear.
// FUNCTION: TITANIUM 0x00417B9C
void* WrapperObject_guess::GetOne_guess() {
    return service_guess.GetOne_guess();
}

// Lookup through the effect-total service at +0xC4, building the totals once first (0x0041002F, flag
// +0xC8).
// FUNCTION: TITANIUM 0x00417BA7
void* WrapperObject_guess::GetTwo_guess(int first_guess, int second_guess) {
    if (first_flag_guess == 0) {
        InitializeOne_guess();
    }
    return service_guess.GetTwo_guess(first_guess, second_guess);
}

// Lookup through the effect-total service at +0xC4, adding the owned AA effects once first
// (0x0040FEAA, flag +0xD0).
// FUNCTION: TITANIUM 0x00417BCF
void* WrapperObject_guess::GetThree_guess(int first_guess, int second_guess) {
    if (second_flag_guess == 0) {
        InitializeThree_guess();
    }
    return service_guess.GetThree_guess(first_guess, second_guess);
}

struct ValueChainLeaf_guess {
    char padding_0000_guess[0x48];
    float value_guess;
};

struct ValueChainMiddle_guess {
    char padding_0000_guess[0x15c];
    ValueChainLeaf_guess* leaf_guess;
};

struct ValueChainRoot_guess {
    char padding_0000_guess[0x1a8];
    ValueChainMiddle_guess* middle_guess;
};

#define g_valueCheckDisabled_guess EQ_GLOBAL(unsigned char, 0x009858C7)

struct ValueChainOwner_guess {
    char padding_0000_guess[8];
    ValueChainRoot_guess* root_guess;
    char IsLeafZero_guess();
};

// True when the spawn's ActorInfo (spawn +0x1A8) has an object at +0x15C whose float +0x48 is 0, unless
// the byte at 0x009858C7 is set. Mana regeneration (0x0041E361) treats it like sitting: the meditate skill
// bonus applies.
// FUNCTION: TITANIUM 0x00417BF7
char ValueChainOwner_guess::IsLeafZero_guess() {
    if (root_guess != 0) {
        ValueChainMiddle_guess* middle_guess = root_guess->middle_guess;
        if (middle_guess != 0 && g_valueCheckDisabled_guess == 0) {
            ValueChainLeaf_guess* leaf_guess = middle_guess->leaf_guess;
            if (leaf_guess != 0 && leaf_guess->value_guess == 0.0f) {
                return 1;
            }
        }
    }
    return 0;
}

struct SlotIndexMapper_guess {
    int GetIndex_guess(int value_guess);
};

// Combat-ability skill to its slot 0-8: Bash 0, Backstab 1, then Dragon Punch, Eagle Strike, Flying Kick,
// Kick, Round Kick, Tiger Claw, Frenzy; -1 otherwise. Accumulate_guess (0x41B6B7) sums item mods for the
// same nine skills.
// FUNCTION: TITANIUM 0x00417C33
int SlotIndexMapper_guess::GetIndex_guess(int value_guess) {
    switch (value_guess) {
    case 8:
        return 1;
    case 10:
        return 0;
    case 0x15:
        return 2;
    case 0x17:
        return 3;
    case 0x1a:
        return 4;
    case 0x1e:
        return 5;
    case 0x26:
        return 6;
    case 0x34:
        return 7;
    case 0x4a:
        return 8;
    default:
        return -1;
    }
}

struct AddressedObject_guess {
    char* GetOwner_guess();
    void Dispatch_guess();
};

// Owner of the member at +0xD8.
// FUNCTION: TITANIUM 0x00417CAC
char* AddressedObject_guess::GetOwner_guess() {
    return reinterpret_cast<char*>(this) - 0xd8;
}

struct ArrayOwner_guess {
    char padding_0000_guess[0x730];
    int values_guess[0x200];
    char padding_0f30_guess[0x40];
    int indexed_values_guess[0x64];
    int GetValue_guess(unsigned int index_guess);
    void SetIndexedValue_guess(unsigned int index_guess, int value_guess);
};

struct IndexedPropertyProxy_guess {
    char padding_0000_guess[4];
    LookupService_guess lookup_guess;
    int GetValue_guess(unsigned int index_guess);
    void SetValue_guess(unsigned int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0040E75C IndexedPropertyProxy_guess::Write1100_guess
    void Write1100_guess(int index_guess, int value_guess);
    LookupResult_guess* Data_guess() { return lookup_guess.Find_guess(); }
};

// Profile setters and adders: First is current endurance (+0x11AC), Second the base HP (+0x11B0), Third to
// Sixth platinum, gold, silver and copper on the person (+0x11D4-0x11E0); Seventh/Eighth +0x1218/+0x121C.
// FUNCTION: TITANIUM 0x00417CB3
void PropertyProxy_guess::SetFirst_guess(int value_guess) {
    lookup_guess.Find_guess()->first_value_guess = value_guess;
}

// Sets base HP (profile +0x11B0).
// FUNCTION: TITANIUM 0x00417CC8
void PropertyProxy_guess::SetSecond_guess(int value_guess) {
    lookup_guess.Find_guess()->second_value_guess = value_guess;
}

// Sets the platinum carried (profile +0x11D4).
// FUNCTION: TITANIUM 0x00417CDD
void PropertyProxy_guess::SetThird_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.third_value_guess = value_guess;
}

// Adds `value` to the platinum carried (profile +0x11D4).
// FUNCTION: TITANIUM 0x00417CF2
void PropertyProxy_guess::AddThird_guess(int value_guess) {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    result_guess->tail_guess.third_value_guess = result_guess->tail_guess.third_value_guess + value_guess;
}

// Sets the gold carried (profile +0x11D8).
// FUNCTION: TITANIUM 0x00417D07
void PropertyProxy_guess::SetFourth_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.fourth_value_guess = value_guess;
}

// Adds `value` to the gold carried (profile +0x11D8).
// FUNCTION: TITANIUM 0x00417D1C
void PropertyProxy_guess::AddFourth_guess(int value_guess) {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    result_guess->tail_guess.fourth_value_guess = result_guess->tail_guess.fourth_value_guess + value_guess;
}

// Sets the silver carried (profile +0x11DC).
// FUNCTION: TITANIUM 0x00417D31
void PropertyProxy_guess::SetFifth_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.fifth_value_guess = value_guess;
}

// Adds `value` to the silver carried (profile +0x11DC).
// FUNCTION: TITANIUM 0x00417D46
void PropertyProxy_guess::AddFifth_guess(int value_guess) {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    result_guess->tail_guess.fifth_value_guess = result_guess->tail_guess.fifth_value_guess + value_guess;
}

// Sets the copper carried (profile +0x11E0).
// FUNCTION: TITANIUM 0x00417D5B
void PropertyProxy_guess::SetSixth_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.sixth_value_guess = value_guess;
}

// Adds `value` to the copper carried (profile +0x11E0).
// FUNCTION: TITANIUM 0x00417D70
void PropertyProxy_guess::AddSixth_guess(int value_guess) {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    result_guess->tail_guess.sixth_value_guess = result_guess->tail_guess.sixth_value_guess + value_guess;
}

// Sets the profile dword at +0x1218.
// FUNCTION: TITANIUM 0x00417D85
void PropertyProxy_guess::SetSeventh_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.seventh_value_guess = value_guess;
}

// Sets the profile dword at +0x121C.
// FUNCTION: TITANIUM 0x00417D9A
void PropertyProxy_guess::SetEighth_guess(int value_guess) {
    lookup_guess.Find_guess()->tail_guess.eighth_value_guess = value_guess;
}

// False for the non-casters Warrior, Monk, Rogue and Berserker (IsSpellcaster in the earlier sibling decomp).
// FUNCTION: TITANIUM 0x00417DAF
int DynamicPropertyOwner_guess::IsSpellcaster_guess() {
    DynamicPropertyProxy_guess* proxy_guess = GetTable_guess();
    int state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
    switch (state_guess) {
    case 1:
        return 0;
    case 7:
        return 0;
    case 9:
        return 0;
    case 16:
        return 0;
    default:
        return 1;
    }
}

struct CostUpdateView_guess {
    int unused_guess;
    CostOffset_guess* offset_holder_guess;
    CostEntity_guess* entity_guess;
    char padding_000c_guess[0x44];
    int stored_value_guess;
    void ResetCur_HP_guess(int mode_guess);
    void ModifyCurHP_guess(int value_guess, int unused_guess);
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return reinterpret_cast<char*>(&offset_holder_guess) + offset_holder_guess->vbaseOffset_0004_guess;
    }
    PropertyProxy_guess* BasePropertyProxy_guess() {
        return reinterpret_cast<PropertyProxy_guess*>(VirtualBase_guess());
    }
};

// Sets base HP to Max_HP minus the item HP field (+0x50), so current HP equals the maximum
// (ResetCur_HP in the earlier sibling decomp).
// FUNCTION: TITANIUM 0x00417DE0
void CostUpdateView_guess::ResetCur_HP_guess(int mode_guess) {
    int previous_guess = stored_value_guess;
    int computed_guess = reinterpret_cast<CostOwner_guess*>(this)->Max_HP_guess(mode_guess);
    BasePropertyProxy_guess()->SetSecond_guess(computed_guess - previous_guess);
}

// Base HP (+0x11B0) plus the item HP field (+0x50), written to the spawn (+0x274). Above Max_HP the base is
// reset (ResetCur_HP_guess) and the maximum returned; capped at 10,000,000.
// FUNCTION: TITANIUM 0x00417E07
int CostOwner_guess::Cur_HP(int mode_guess) {
    int bonus_guess = this->bonus_guess;
    DynamicPropertyProxy_guess* proxy_guess = BaseProxy_guess();
    int value_guess = proxy_guess->lookup_guess.Find_guess()->second_value_guess;
    value_guess += bonus_guess;
    if (pSpawn_0008_guess != 0) {
        pSpawn_0008_guess->updated_value_0274_guess = value_guess;
    }
    int computed_guess = Max_HP_guess(mode_guess);
    if (value_guess > computed_guess) {
        reinterpret_cast<CostUpdateView_guess*>(this)->ResetCur_HP_guess(mode_guess);
        value_guess = computed_guess;
    }
    if (value_guess > 10000000) {
        value_guess = 10000000;
    }
    return value_guess;
}

// Current endurance (+0x11AC), cut to Max_Endurance and raised to 0.
// FUNCTION: TITANIUM 0x00417E67
int CharacterStats_guess::Cur_Endurance_guess() {
    int computed_guess = Max_Endurance();
    LookupResult_guess* result_guess = GetProfile_guess();
    if (result_guess->first_value_guess > computed_guess) {
        PropertyProxy_guess::SetFirst_guess(computed_guess);
    } else if (GetProfile_guess()->first_value_guess < 0) {
        GetProfile_guess()->first_value_guess = 0;
    }
    return GetProfile_guess()->first_value_guess;
}

// Current mana (+0x11A8), cut to the virtual GetAllowedValue_guess maximum and raised to 0
// (Cur_Mana in the earlier sibling decomp).
// FUNCTION: TITANIUM 0x00417EE7
int DynamicPropertyBoundOwner_guess::Cur_Mana_guess() {
    int allowed_guess = GetAllowedValue_guess();
    DynamicPropertyBoundProxy_guess* first_proxy_guess = BaseBoundProxy_guess();
    if (first_proxy_guess->lookup_guess.Find_guess()->allowed_value_11a8_guess > allowed_guess) {
        BaseBoundProxy_guess()->SetAllowedValue_guess(allowed_guess);
    } else {
        DynamicPropertyBoundProxy_guess* second_proxy_guess = reinterpret_cast<DynamicPropertyBoundProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (second_proxy_guess->lookup_guess.Find_guess()->allowed_value_11a8_guess < 0) {
            DynamicPropertyBoundProxy_guess* third_proxy_guess = reinterpret_cast<DynamicPropertyBoundProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            third_proxy_guess->lookup_guess.Find_guess()->allowed_value_11a8_guess = 0;
        }
    }
    DynamicPropertyBoundProxy_guess* final_proxy_guess = BaseBoundProxy_guess();
    return final_proxy_guess->lookup_guess.Find_guess()->allowed_value_11a8_guess;
}

// True for the int casters Necromancer, Wizard, Magician and Enchanter (IsIntCaster in the earlier sibling decomp).
// FUNCTION: TITANIUM 0x00417F67
bool DynamicPropertyOwner_guess::IsIntCaster_guess() {
    DynamicPropertyProxy_guess* proxy_guess = GetTable_guess();
    unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
    return state_guess >= 0xb && state_guess <= 0xe;
}

#define PROPERTY_RESULT_guess (GetTable_guess()->lookup_guess.Find_guess())
#define g_advanceCostScale_guess EQ_GLOBAL(double, 0x00640FD0)
#define g_advanceCostLimit_guess EQ_GLOBAL(double, 0x00640FC8)
#define g_advanceCostFactor_guess EQ_GLOBAL(double, 0x00640FA0)
#define g_advanceCostFloor_guess EQ_GLOBAL(double, 0x00640FC0)
#define g_advanceCostFinalA_guess EQ_GLOBAL(double, 0x00640FB8)
#define g_advanceCostFinalB_guess EQ_GLOBAL(double, 0x00640FB0)
#define g_advanceCostLevelOffset_guess EQ_GLOBAL(double, 0x00640FA8)
#define g_advanceCostUnit_guess EQ_GLOBAL(double, 0x00640E40)

// Class and race AC bonus (EQEmu Client::GetClassRaceACBonus has the same terms); `agi_guess` is
// really AGI. Monk: full bonus while carried weight (+0x48) is under a level-based soft cap, shrinking to
// the hard cap, a penalty above it. Rogue (level 30+, AGI over 75) and Beastlord (level 11+): up to 12
// and 16, scaled by AGI. Iksar: level clamped to 10-35.
// Both arms of each `< 30` test give level + 5, as decompiled.
// FUNCTION: TITANIUM 0x00417F8E
// @early-stop: budget, structural ndiff=146
int DynamicPropertyOwner_guess::GetClassRaceACBonus_guess(int agi_guess) {
    int second_value_guess;
    int result_guess = 0;
    int value_guess;
    if (PROPERTY_RESULT_guess->state_guess == 7) {
        int threshold_guess;
        threshold_guess = 14;
        agi_guess = 30;
        if (PROPERTY_RESULT_guess->level_11a4_guess > 14) {
            agi_guess = 32;
            threshold_guess = 15;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 29) {
            agi_guess = 34;
            threshold_guess = 16;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 44) {
            agi_guess = 36;
            threshold_guess = 17;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 50) {
            agi_guess = 38;
            threshold_guess = 18;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 54) {
            agi_guess = 40;
            threshold_guess = 20;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 59) {
            agi_guess = 45;
            threshold_guess = 24;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 61) {
            agi_guess = 47;
            threshold_guess = 24;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 63) {
            agi_guess = 50;
            threshold_guess = 24;
        }
        if (PROPERTY_RESULT_guess->level_11a4_guess > 64) {
            agi_guess = 53;
            threshold_guess = 24;
        }
        if (PROPERTY_RESULT_guess->state_guess == 7) {
            value_guess = value_0048_guess;
            if (value_guess < agi_guess - 1) {
                double p_guess = (PROPERTY_RESULT_guess->level_11a4_guess < 30)
                    ? (double)(PROPERTY_RESULT_guess->level_11a4_guess + 5)
                    : (double)(PROPERTY_RESULT_guess->level_11a4_guess + 5);
                if (value_guess > threshold_guess) {
                    double t_guess = (double)(value_guess - threshold_guess) * g_advanceCostScale_guess;
                    if (t_guess > g_advanceCostLimit_guess) {
                        t_guess = g_advanceCostLimit_guess;
                    }
                    p_guess = p_guess * ((g_advanceCostLimit_guess - t_guess) * g_advanceCostFactor_guess);
                    if (p_guess < g_advanceCostFloor_guess) {
                        p_guess = 0.0;
                    }
                }
                result_guess = (int)(p_guess * g_advanceCostFinalA_guess * g_advanceCostFinalB_guess);
            }
        }
        second_value_guess = value_0048_guess;
        if (second_value_guess > agi_guess + 1) {
            double p_guess = (PROPERTY_RESULT_guess->level_11a4_guess < 30)
                ? (double)(PROPERTY_RESULT_guess->level_11a4_guess + 5)
                : (double)(PROPERTY_RESULT_guess->level_11a4_guess + 5);
            double d_guess = (double)second_value_guess - ((double)agi_guess - g_advanceCostLevelOffset_guess);
            double t_guess = d_guess * g_advanceCostFactor_guess;
            if (t_guess > g_advanceCostUnit_guess) {
                t_guess = g_advanceCostUnit_guess;
            }
            result_guess -= (int)(p_guess * g_advanceCostFinalA_guess * g_advanceCostFinalB_guess * t_guess);
        }
    } else if (PROPERTY_RESULT_guess->state_guess == 9) {
        if (agi_guess > 0x4b && PROPERTY_RESULT_guess->level_11a4_guess > 0x1d) {
            result_guess = PROPERTY_RESULT_guess->level_11a4_guess - 0x1a;
            if (agi_guess > 0x4f) {
                if (agi_guess < 0x55) {
                    result_guess = result_guess * 2;
                } else if (agi_guess < 0x5a) {
                    result_guess = result_guess * 3;
                } else if (agi_guess < 100) {
                    result_guess = result_guess * 4;
                } else {
                    result_guess = result_guess * 5;
                }
            }
            result_guess = result_guess / 4;
            if (result_guess > 12) {
                result_guess = 12;
            }
        }
    } else if (PROPERTY_RESULT_guess->state_guess == 15) {
        if (PROPERTY_RESULT_guess->level_11a4_guess > 10) {
            result_guess = PROPERTY_RESULT_guess->level_11a4_guess - 6;
            if (agi_guess > 0x4f) {
                if (agi_guess < 0x55) {
                    result_guess = result_guess * 2;
                } else if (agi_guess < 0x5a) {
                    result_guess = result_guess * 3;
                } else if (agi_guess < 100) {
                    result_guess = result_guess * 4;
                } else {
                    result_guess = result_guess * 5;
                }
            }
            result_guess = result_guess / 5;
            if (result_guess > 16) {
                result_guess = 16;
            }
        }
    }
    if (PROPERTY_RESULT_guess->database_string_id_guess == 0x80) {
        int bonus_guess = PROPERTY_RESULT_guess->level_11a4_guess;
        if (bonus_guess > 0x23) {
            bonus_guess = 0x23;
        }
        if (bonus_guess < 10) {
            bonus_guess = 10;
        }
        result_guess += bonus_guess;
    }
    return result_guess;
}

#undef PROPERTY_RESULT_guess
#undef g_advanceCostScale_guess
#undef g_advanceCostLimit_guess
#undef g_advanceCostFactor_guess
#undef g_advanceCostFloor_guess
#undef g_advanceCostFinalA_guess
#undef g_advanceCostFinalB_guess
#undef g_advanceCostLevelOffset_guess
#undef g_advanceCostUnit_guess

// AC from agility (defense_agility_bonus in the earlier sibling decomp); +0x24 is the AGI field. Below 40 a penalty
// (to -25 at 0); 61-74 a small bonus; above 74 a bonus scaled 35/55/70/80 at levels <7, <20, <40, 40+.
// FUNCTION: TITANIUM 0x00418424
// @early-stop: budget, structural ndiff=42
int CostOwner_guess::defense_agility_bonus_guess() {
    int level_guess = level_0024_guess;
    if (level_guess < 0x28) {
        return (level_guess - 0x28) * 0x19 / 0x28;
    }
    if (level_guess > 0x4a) {
        int difference_guess = 0xc8 - level_guess;
        if (difference_guess < 0) {
            difference_guess = 0;
        }
        int scale_guess;
        DynamicPropertyProxy_guess* first_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (first_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess < 7) {
            scale_guess = 0x23;
        } else {
            DynamicPropertyProxy_guess* second_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (second_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess < 0x14) {
                scale_guess = 0x37;
            } else {
                DynamicPropertyProxy_guess* third_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                if (third_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess < 0x28) {
                    scale_guess = 0x46;
                } else {
                    scale_guess = 0x50;
                }
            }
        }
        return ((scale_guess - difference_guess / 5) * 2) / 3;
    }
    if (level_guess <= 0x3c) {
        return 0;
    }
    return ((0x1c - (0xc8 - level_guess) / 5) * 2) / 3;
}

// Racial innate skill level, 0, 50, 100 or 125 (InnateSkillLevel in the earlier sibling decomp); the race
// parameter is unused, the profile's race decides. Halfling Sneak, Wood Elf Forage, Dark Elf Hide, Dwarf Sense Heading,
// Gnome Tinkering, Iksar Forage and Swimming 100, Vah Shir Safe Fall and Sneak, Froglok Swimming 125.
// Races 81, 112, 77, 98 and 94 share them (probably NPC citizen models of those races).
// FUNCTION: TITANIUM 0x004184F4
// @early-stop: budget, structural ndiff=31
int CostOwner_guess::InnateSkillLevel_guess(unsigned char value_guess, unsigned char unused_guess) {
    unsigned char result_guess = 0;
    if (value_guess >= 0x64) {
        return 0;
    }

    DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int database_string_id_guess = proxy_guess->lookup_guess.Find_guess()->database_string_id_guess;
    switch (database_string_id_guess) {
    case 0x51:
    case 0xb:
        if (value_guess == 0x2a) {
            result_guess = 0x32;
        }
        break;
    case 4:
    case 0x70:
        if (value_guess == 0x1b) {
            result_guess = 0x32;
        }
        break;
    case 6:
    case 0x4d:
    case 0x62:
        if (value_guess == 0x1d) {
            result_guess = 0x32;
        }
        break;
    case 8:
    case 0x5e:
        if (value_guess == 0x28) {
            result_guess = 0x32;
        }
        break;
    case 0xc:
        if (value_guess == 0x39) {
            result_guess = 0x32;
        }
        break;
    case 0x80:
        if (value_guess == 0x1b) {
            result_guess = 0x32;
        } else if (value_guess == 0x32) {
            result_guess = 0x64;
        }
        break;
    case 0x82:
        if (value_guess != 0x27) {
            if (value_guess == 0x2a) {
                result_guess = 0x32;
            }
        } else {
            result_guess = 0x32;
        }
        break;
    case 0x14a:
        if (value_guess == 0x32) {
            result_guess = 0x7d;
        }
        break;
    }
    return result_guess;
}

// Passes the race and profile +0x11A0 to `target_guess`'s check (0x5E0860, mode 1); 0 without a target
// or spawn.
// FUNCTION: TITANIUM 0x004185B1
int CostOwner_guess::CheckQuery_guess(QueryTarget_guess* target_guess) {
    if (target_guess == 0 || pSpawn_0008_guess == 0) {
        return 0;
    }
    DynamicPropertyProxy_guess* proxy_guess = BaseProxy_guess();
    int value_guess = proxy_guess->lookup_guess.Find_guess()->value_11a0_guess;
    proxy_guess = BaseProxy_guess();
    int database_string_id_guess = proxy_guess->lookup_guess.Find_guess()->database_string_id_guess;
    return target_guess->Check_guess(database_string_id_guess, value_guess, 1);
}

// Resists, as basesave_* and save_* in the earlier sibling decomp. Base: the profile value (+0x1248 magic, +0x124C
// fire, +0x1250 cold, +0x1254 disease, +0x1258 poison), set by race, +10 for NPCs above level 24. Save:
// the base plus the resist SPA, SPA 111 ResistAll, the item field and class bonuses for players, capped
// by the slot-4 virtual (kind 7-11).
// Base magic: Erudite, Dwarf and Froglok 30.
// FUNCTION: TITANIUM 0x00418608
int CostOwner_guess::basesave_magic_guess() {
    DynamicPropertyProxy_guess* proxy_guess = BaseProxy_guess();
    int value_guess = proxy_guess->lookup_guess.Find_guess()->value_1248_guess;
    proxy_guess = BaseProxy_guess();
    if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 3) {
        value_guess = 0x1e;
    } else {
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 8) {
            value_guess = 0x1e;
        } else {
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 0x14a) {
                value_guess = 0x1e;
            }
        }
    }
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 1) {
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x18) {
            value_guess += 10;
        }
    }
    return value_guess;
}
struct CostOwnerDispatchPrimary_guess {
    virtual void Slot00_guess();
};

struct CostOwnerDispatchView_guess : CostOwnerDispatchPrimary_guess, virtual DynamicPropertyProxy_guess {
    CostEntity_guess* entity_guess;
    char padding_000c_guess[8];
    int scale_guess;
    char padding_0018_guess[0x18];
    int dispatch_value_guess;
    char padding_0034_guess[0x1c];
    int bonus_guess;

    int save_magic_guess();
};

// Magic save: Warriors and Berserkers add level/2.
// FUNCTION: TITANIUM 0x004186AE
// @early-stop: budget, diff ndiff=6
int CostOwner_guess::save_magic_guess() {
    unsigned int random_guess;
    int adjusted_guess = basesave_magic_guess();
    random_guess = TotalSpellAffects_guess(0x32, 1, 0, 1);
    random_guess += TotalSpellAffects_guess(0x6f, 1, 0, 1);
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        CostOwnerDispatchView_guess* view_guess = reinterpret_cast<CostOwnerDispatchView_guess*>(this);
        if (static_cast<DynamicPropertyProxy_guess*>(view_guess)->FindResult_guess()->state_guess == 1 ||
            static_cast<DynamicPropertyProxy_guess*>(view_guess)->FindResult_guess()->state_guess == 0x10) {
            adjusted_guess +=
                static_cast<DynamicPropertyProxy_guess*>(view_guess)->FindResult_guess()->level_11a4_guess / 2;
        }
    }
    int value_guess = dispatch_value_guess + adjusted_guess + random_guess;
    return reinterpret_cast<CostOwnerDispatch_guess*>(this)->Dispatch_guess(value_guess, 7);
}

// Base fire: Troll 5, Iksar +5.
// FUNCTION: TITANIUM 0x00418756
int CostOwner_guess::basesave_fire_guess() {
    DynamicPropertyProxy_guess* proxy_guess = BaseProxy_guess();
    int value_guess = proxy_guess->lookup_guess.Find_guess()->value_124c_guess;
    proxy_guess = BaseProxy_guess();
    if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 9) {
        value_guess = 5;
    }
    proxy_guess = BaseProxy_guess();
    if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 0x80) {
        value_guess += 5;
    }
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 1) {
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x18) {
            value_guess += 10;
        }
    }
    return value_guess;
}

// Fire save: Monk +8, Ranger +4, more past 49.
// FUNCTION: TITANIUM 0x004187E4
int CostOwner_guess::save_fire_guess() {
    int value_guess = basesave_fire_guess();
    int random_guess = TotalSpellAffects_guess(0x2e, 1, 0, 1);
    random_guess += TotalSpellAffects_guess(0x6f, 1, 0, 1);
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->state_guess == 7) {
            value_guess += 8;
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                value_guess += proxy_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->state_guess == 4) {
            value_guess += 4;
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                value_guess += proxy_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
    }
    int result_guess = value_0038_guess + random_guess;
    result_guess += value_guess;
    return reinterpret_cast<CostOwnerDispatch_guess*>(this)->Dispatch_guess(result_guess, 9);
}

// Base cold: Barbarian 35, Iksar -10.
// FUNCTION: TITANIUM 0x004188EF
int CostRollOwner_guess::basesave_cold_guess() {
    CostDynamicBlock_guess* block_guess = BaseBlock_guess();
    int value_guess = block_guess->Find_guess()->value_1250_guess;
    block_guess = BaseBlock_guess();
    if (block_guess->Find_guess()->database_string_id_guess == 2) {
        value_guess = 0x23;
    }
    block_guess = BaseBlock_guess();
    if (block_guess->Find_guess()->database_string_id_guess == 0x80) {
        value_guess -= 10;
    }
    if (entity_guess != 0 && entity_guess->state_guess == 1) {
        block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->Find_guess()->level_11a4_guess > 0x18) {
            value_guess += 10;
        }
    }
    return value_guess;
}

// Cold save: Ranger and Beastlord +4, more past 49.
// FUNCTION: TITANIUM 0x0041897D
int CostRollOwner_guess::save_cold_guess() {
    int base_guess = basesave_cold_guess();
    int adjusted_guess = base_guess;
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int random_guess = owner_guess->TotalSpellAffects_guess(0x2f, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(0x6f, 1, 0, 1);
    if (entity_guess != 0 && entity_guess->state_guess == 0) {
        CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->Find_guess()->state_guess == 4 ||
            (block_guess = BaseBlock_guess(),
             block_guess->Find_guess()->state_guess == 0xf)) {
            adjusted_guess = base_guess + 4;
            block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (block_guess->Find_guess()->level_11a4_guess > 0x31) {
                block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                adjusted_guess += block_guess->Find_guess()->level_11a4_guess - 0x31;
            }
        }
    }
    int dispatch_guess = value_0034_guess;
    dispatch_guess += random_guess;
    dispatch_guess += adjusted_guess;
    return Slot04_guess(dispatch_guess, 8);
}

// Base disease: Halfling 20, Erudite 10; Monks gain past 50.
// FUNCTION: TITANIUM 0x00418A40
int CostRollOwner_guess::basesave_disease_guess() {
    CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int value_guess = block_guess->Find_guess()->value_1254_guess;
    block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    if (block_guess->Find_guess()->database_string_id_guess == 0xb) {
        value_guess = 0x14;
    }
    block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    if (block_guess->Find_guess()->database_string_id_guess == 3) {
        value_guess = 10;
    }
    block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    if (block_guess->Find_guess()->state_guess == 7) {
        block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->Find_guess()->level_11a4_guess > 0x32) {
            block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            value_guess = value_guess - 0x32 + block_guess->Find_guess()->level_11a4_guess;
        }
    }
    return value_guess;
}

// Disease save: Paladin +8, Beastlord and Shadow Knight +4.
// FUNCTION: TITANIUM 0x00418AEF
int CostRollOwner_guess::save_disease_guess() {
    int base_guess = basesave_disease_guess();
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int random_guess = owner_guess->TotalSpellAffects_guess(0x31, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(0x6f, 1, 0, 1);
    int& dispatch_guess = base_guess;
    if (entity_guess != 0 && entity_guess->state_guess == 0) {
        CostDynamicFindBlock_guess* block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->lookup_guess.Find_guess()->state_guess == 3) {
            block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            dispatch_guess += 8;
            if (block_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                dispatch_guess += block_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
        block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->lookup_guess.Find_guess()->state_guess == 0xf) {
            block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            dispatch_guess += 4;
            if (block_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                dispatch_guess += block_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
        block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (block_guess->lookup_guess.Find_guess()->state_guess == 5) {
            block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            dispatch_guess += 4;
            if (block_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                dispatch_guess += block_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
    }
    int total_guess = value_0040_guess + random_guess;
    total_guess += dispatch_guess;
    return Slot04_guess(total_guess, 0xb);
}

// Base poison: Halfling and Dwarf 20, Froglok 30; Monks gain past 50.
// FUNCTION: TITANIUM 0x00418C4F
int DynamicPropertyOwner_guess::basesave_poison_guess() {
    DynamicPropertyProxy_guess* proxy_guess;
    proxy_guess = GetTable_guess();
    int value_guess = proxy_guess->lookup_guess.Find_guess()->value_1258_guess;
    proxy_guess = GetTable_guess();
    if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 0xb) {
        value_guess = 0x14;
    } else {
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 8) {
            value_guess = 0x14;
        }
    }
    proxy_guess = GetTable_guess();
    if (proxy_guess->lookup_guess.Find_guess()->database_string_id_guess == 0x14a) {
        value_guess = 0x1e;
    }
    proxy_guess = GetTable_guess();
    if (proxy_guess->lookup_guess.Find_guess()->state_guess == 7) {
        proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x32) {
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            value_guess += proxy_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x32;
        }
    }
    return value_guess;
}

// Poison save: Rogue +8, Shadow Knight +4, more past 49.
// FUNCTION: TITANIUM 0x00418D1C
int DynamicPropertyOwner_guess::save_poison_guess() {
    int calculated_guess = basesave_poison_guess();
    int random_guess = reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x30, 1, 0, 1);
    random_guess += reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x6f, 1, 0, 1);
    if (input_guess != 0 && input_guess->type_0244_guess == 0) {
        PropertyProxy_guess* proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->state_guess == 9) {
            calculated_guess += 8;
            proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                calculated_guess += proxy_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
        proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->lookup_guess.Find_guess()->state_guess == 5) {
            calculated_guess += 4;
            proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x31) {
                proxy_guess = reinterpret_cast<PropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                calculated_guess += proxy_guess->lookup_guess.Find_guess()->level_11a4_guess - 0x31;
            }
        }
    }
    int value_guess = value_003c_guess + random_guess + calculated_guess;
    return reinterpret_cast<CostOwnerDispatch_guess*>(this)->Dispatch_guess(value_guess, 10);
}

struct DynamicValueOwner_guess {
    int unused_guess;
    LookupOffset_guess* offset_holder_guess;
    DynamicPropertyInput_guess* input_guess;
    char padding_000c_guess[0x38];
    int base_value_guess;
    int GetAdjustedValue_guess();
};

// The queried value plus a level bonus for players (spawn type 0): level / 3, and 3 more per level above
// 50; the base at `base_value_guess` is added on top.
// FUNCTION: TITANIUM 0x00418E27
int DynamicValueOwner_guess::GetAdjustedValue_guess() {
    int value_guess = reinterpret_cast<DynamicPropertyOwner_guess*>(this)->GetQueriedValue_guess();
    if (input_guess != 0 && input_guess->type_0244_guess == 0) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        LookupResult_guess* queried_guess = proxy_guess->lookup_guess.Find_guess();
        if (queried_guess->level_11a4_guess > 0x32) {
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            int amount_guess = proxy_guess->lookup_guess.Find_guess()->level_11a4_guess;
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            queried_guess = proxy_guess->lookup_guess.Find_guess();
            value_guess = amount_guess / 3 + value_guess;
            value_guess += (queried_guess->level_11a4_guess - 0x32) * 3;
        } else {
            proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            queried_guess = proxy_guess->lookup_guess.Find_guess();
            value_guess += queried_guess->level_11a4_guess / 3;
        }
    }
    return base_value_guess + value_guess;
}

// Stats, as Str/Sta/Cha/Dex/Int/Wis in the earlier sibling decomp: profile base (+0x11B4..+0x11CC) + the item field
// + the stat SPA + SPA 159 AllStats, capped by the slot-4 virtual (kind = stat). Intoxication (0x5ED550)
// above 55 raises STR and STA and lowers DEX by (drunk - 40)/16; any intoxication scales INT and WIS down.
// STR (kind 0); sober with actor info +0x1060 set, level/10 + 9 more.
// FUNCTION: TITANIUM 0x00418EBF
int CostOwner_guess::Str_guess() {
    int bonus_guess = 0;
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        CostCandidate_guess* candidate_guess = block_guess->GetCandidate_guess();
        if (candidate_guess->GetValue_guess() > 0x37) {
            int value_guess = candidate_guess->GetValue_guess();
            value_guess = (value_guess - 0x28) / 0x10;
            if (value_guess > 0) {
                bonus_guess = value_guess;
            }
        } else if (pSpawn_0008_guess->threshold_guess != 0 &&
                   pSpawn_0008_guess->threshold_guess->value_1060_guess != 0) {
            CostDynamicFindBlock_guess* find_block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            bonus_guess = find_block_guess->lookup_guess.Find_guess()->level_11a4_guess / 10 + 9;
        }
    }

    int random_guess = TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += TotalSpellAffects_guess(4, 1, 0, 1);
    CostDynamicFindBlock_guess* find_block_guess = BaseFindBlock_guess();
    LookupResult_guess* result_guess = find_block_guess->lookup_guess.Find_guess();
    int value_guess = result_guess->tail_guess.value_11b4_guess + value_0010_guess;
    value_guess += random_guess;
    value_guess += bonus_guess;
    return reinterpret_cast<CostOwnerDispatch_guess*>(this)->Dispatch_guess(value_guess, 0);
}

struct DatabaseStringManager_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DatabaseStringManager_guess::GetString_guess
    char* GetString_guess(int index_guess, int category_guess, int flags_guess);
};

#define g_databaseStringManager_guess EQ_GLOBAL(DatabaseStringManager_guess*, 0x00850398)

// EXTERNAL: TITANIUM 0x00576FA0 CopyBounded_guess
void __cdecl CopyBounded_guess(char* destination_guess, const char* source_guess, int length_guess);

// STA (kind 1).
// FUNCTION: TITANIUM 0x00418F95
int CostOwner_guess::Sta_guess() {
    int bonus_guess = 0;
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        CostCandidate_guess* candidate_guess = block_guess->GetCandidate_guess();
        if (candidate_guess->GetValue_guess() > 0x37) {
            int value_guess = candidate_guess->GetValue_guess();
            value_guess = (value_guess - 0x28) / 0x10;
            if (value_guess > 0) {
                bonus_guess = value_guess;
            }
        }
    }

    int random_guess = TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += TotalSpellAffects_guess(7, 1, 0, 1);
    CostDynamicFindBlock_guess* find_block_guess = BaseFindBlock_guess();
    LookupResult_guess* result_guess = find_block_guess->lookup_guess.Find_guess();
    int value_guess = result_guess->tail_guess.value_11b8_guess + scale_guess;
    value_guess += random_guess;
    value_guess += bonus_guess;
    return reinterpret_cast<CostOwnerDispatch_guess*>(this)->Dispatch_guess(value_guess, 1);
}

// CHA (kind 6); no intoxication term.
// FUNCTION: TITANIUM 0x00419030
int CostRollOwner_guess::Cha_guess() {
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int random_guess = owner_guess->TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(10, 1, 0, 1);
    CostDynamicBlock_guess* block_guess = BaseBlock_guess();
    int result_guess = block_guess->Find_guess()->tail_guess.dynamic_value_11bc_guess +
                       first_value_guess + random_guess;
    return Slot04_guess(result_guess, 6);
}

// DEX (kind 3).
// FUNCTION: TITANIUM 0x00419081
int CostRollOwner_guess::Dex_guess() {
    int adjustment_guess = 0;
    if (entity_guess != 0 && entity_guess->state_guess == 0) {
        CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        CostCandidate_guess* candidate_guess = block_guess->GetCandidate_guess();
        int value_guess = candidate_guess->GetValue_guess();
        if (value_guess > 0x37) {
            value_guess = candidate_guess->GetValue_guess();
            value_guess = (value_guess - 0x28) / 0x10;
            if (value_guess > 0) {
                adjustment_guess = -value_guess;
            }
        }
    }
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int random_guess = owner_guess->TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(5, 1, 0, 1);
    CostDynamicBlock_guess* block_guess = BaseBlock_guess();
    int result_guess = block_guess->Find_guess()->tail_guess.dynamic_value_11c0_guess +
                       second_value_guess + random_guess + adjustment_guess;
    return Slot04_guess(result_guess, 3);
}

// INT (kind 5).
// FUNCTION: TITANIUM 0x0041911E
int CostRollOwner_guess::Int_guess() {
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int value_guess;
    int random_guess;
    random_guess = owner_guess->TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(8, 1, 0, 1);
    CostDynamicFindBlock_guess* find_block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    value_guess = find_block_guess->lookup_guess.Find_guess()->tail_guess.intel_11c4_guess +
                  intel_0020_guess + random_guess;

    if (entity_guess != 0 && entity_guess->state_guess == 0) {
        CostCandidate_guess* candidate_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->base_guess.GetCandidate_guess();
        if (candidate_guess->GetValue_guess() != 0) {
            double original_guess = static_cast<double>(value_guess);
            double factor_guess = EQ_GLOBAL(double, 0x00640e40) -
                                  candidate_guess->GetValue_guess() * EQ_GLOBAL(double, 0x00640fe0);
            if (factor_guess < EQ_GLOBAL(double, 0x00640fd8)) {
                factor_guess = EQ_GLOBAL(double, 0x00640fd8);
            }
            value_guess = static_cast<int>(factor_guess * original_guess);
        }
    }

    return Slot04_guess(value_guess, 5);
}

// WIS (kind 4).
// FUNCTION: TITANIUM 0x004191E4
int CostRollOwner_guess::Wis_guess() {
    CostOwner_guess* owner_guess = reinterpret_cast<CostOwner_guess*>(this);
    int random_guess = owner_guess->TotalSpellAffects_guess(0x9f, 1, 0, 1);
    random_guess += owner_guess->TotalSpellAffects_guess(9, 1, 0, 1);
    CostDynamicFindBlock_guess* find_block_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int value_guess = find_block_guess->lookup_guess.Find_guess()->tail_guess.wis_11cc_guess +
                      wis_0028_guess + random_guess;

    if (entity_guess != 0 && entity_guess->state_guess == 0) {
        CostCandidate_guess* candidate_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                   ->base_guess.GetCandidate_guess();
        if (candidate_guess->GetValue_guess() != 0) {
            double original_guess = static_cast<double>(value_guess);
            double factor_guess = EQ_GLOBAL(double, 0x00640e40) -
                                  candidate_guess->GetValue_guess() * EQ_GLOBAL(double, 0x00640fe0);
            if (factor_guess < EQ_GLOBAL(double, 0x00640fd8)) {
                factor_guess = EQ_GLOBAL(double, 0x00640fd8);
            }
            value_guess = static_cast<int>(factor_guess * original_guess);
        }
    }

    return Slot04_guess(value_guess, 4);
}

// Whether this character can use an item (tu_149 and tu_172 call it CanUse/CanEquip). A container
// (0x5ECCC0) always can; otherwise the class mask must hold this class, the deity mask be empty or hold
// this deity, the race mask hold this race (or the item type be 20), and the required level (0x5ECAA0)
// not exceed this level.
// FUNCTION: TITANIUM 0x004192AA
// @early-stop: tiebreak, diff ndiff=1
int DynamicPropertyOwner_guess::CanUseItem_guess(LookupOption_guess* option_guess,
                                                      int unused_guess) {
    int count_guess = 0;
    DynamicPropertyWidget_guess* widget_guess =
        reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
            ->GetWidget_guess();
    DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int mapped_guess = MapLookupValue_guess(
        proxy_guess->lookup_guess.Find_guess()->database_string_id_guess);
    if (option_guess->GetItemClass_guess() != 0) {
        return 1;
    }

    DynamicPropertyProxy_guess* state_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    unsigned char state_guess = state_proxy_guess->lookup_guess.Find_guess()->state_guess;
    if ((option_guess->GetStateFlags_guess(1, 0) & (1 << (state_guess - 1))) != 0) {
        count_guess = 1;
    }
    if (option_guess->GetFeatureFlags_guess(1, 0) == 0) {
        ++count_guess;
    } else {
        int dynamic_mask_guess = widget_guess->GetDynamicBitMask_guess();
        if ((dynamic_mask_guess & option_guess->GetFeatureFlags_guess(1, 0)) != 0) {
            ++count_guess;
        }
    }
    if ((option_guess->GetSelectionFlags_guess(1, 0) & (1 << (mapped_guess - 1))) != 0 ||
        option_guess->GetItemType_guess() == 0x14) {
        ++count_guess;
    }

    DynamicPropertyProxy_guess* level_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int current_value_guess = level_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess;
    if (option_guess->GetMaximum_guess(1) > current_value_guess) {
        count_guess = 0;
    }
    return count_guess == 3;
}

// Movement factor (encum_factor in the earlier sibling decomp): 0.5 or 0.75 when HP is low (ratio and absolute limits
// 0x640FEC/0x63F554, 0x640FE8/0x640E20) above level 3. Carried weight (+0x48) above +0x10 cuts it further;
// string 0x3068 prints once on becoming encumbered, 0x3067 on recovering (state 0x92387C). In that branch
// the 0x905CC0 checks on 0x924470 can force 1.0.
// FUNCTION: TITANIUM 0x004193C5
// @early-stop: budget, structural ndiff=21
float CostOwner_guess::encum_factor_guess() {
    float base_value_guess = static_cast<float>(value_0048_guess);
    float current_value_guess = static_cast<float>(value_0010_guess);
    float factor_guess = 1.0f;
    if (pSpawn_0008_guess == 0 || pSpawn_0008_guess->threshold_guess == 0) {
        return EQ_GLOBAL(float, 0x0063F4D0);
    }

    float first_value_guess = static_cast<float>(Cur_HP(pSpawn_0008_guess->state_guess));
    float second_value_guess = static_cast<float>(Max_HP_guess(pSpawn_0008_guess->state_guess));
    int state_limit_guess = reinterpret_cast<FactorDynamic_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess)
                                ->flag_0110_guess
                                ? 0
                                : 3;
    if (first_value_guess < second_value_guess &&
        reinterpret_cast<FactorDynamic_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess)
                ->lookup_guess.Find_guess()->level_11a4_guess > state_limit_guess) {
        float ratio_guess = first_value_guess / second_value_guess;
        if (ratio_guess < EQ_GLOBAL(float, 0x00640FEC) &&
            first_value_guess < EQ_GLOBAL(float, 0x0063F554)) {
            factor_guess = 0.5f;
        } else if (ratio_guess < EQ_GLOBAL(float, 0x00640FE8) &&
                   first_value_guess < EQ_GLOBAL(float, 0x00640E20)) {
            factor_guess = 0.75f;
        }
    }

    if (base_value_guess <= current_value_guess) {
        if (g_factorState_guess < 0) {
            g_factorState_guess = 0;
        } else if (g_factorState_guess != 1) {
            return factor_guess;
        } else {
            g_factorTextSink_guess->dsp_chat(
                g_factorTextTable_guess->getString(0x3067, 0, 0xd, g_factorState_guess));
        }
        g_factorState_guess = 0;
    } else {
        if (g_factorState_guess < 0 || g_factorState_guess == 0) {
            g_factorState_guess = 1;
            g_factorTextSink_guess->dsp_chat(
                g_factorTextTable_guess->getString(0x3068, 0, 0xd, 1));
        }
        if (current_value_guess != 0.0f) {
            if (base_value_guess > current_value_guess) {
                factor_guess -= (base_value_guess - current_value_guess) /
                                (current_value_guess + current_value_guess);
            }
            if (factor_guess < 0.0f) {
                factor_guess = 0.0f;
            }
            if (g_propertyFilter_guess->CheckFirst_guess(g_factorProperty_guess) != 0) {
                factor_guess = 1.0f;
            }
            if (g_propertyFilter_guess->CheckSecond_guess(g_factorProperty_guess) != 0) {
                return 1.0f;
            }
            return factor_guess;
        }
    }
    return factor_guess;
}

// Race name (database string category 11), -1 meaning this character's race, in a 24-byte static buffer
// (0x79DB14). RaceName in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x004195B8
char* DynamicPropertyOwner_guess::RaceName_guess(int index_guess) {
    if (index_guess == -1) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        index_guess = proxy_guess->lookup_guess.Find_guess()->database_string_id_guess;
    }
    CopyBounded_guess(EQ_ARRAY(char, 0x0079DB14),
                      g_databaseStringManager_guess->GetString_guess(index_guess, 0xb, 0), 0x18);
    return EQ_ARRAY(char, 0x0079DB14);
}

// Class name (ClassName_guess), -1 meaning this character's class. Declared void here, so the text
// pointer is probably just left in EAX for callers.
// FUNCTION: TITANIUM 0x00419601
void DynamicPropertyOwner_guess::ShowRingString_guess(int index_guess) {
    if (index_guess == -1) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        ClassName_guess(proxy_guess->lookup_guess.Find_guess()->state_guess);
    } else {
        ClassName_guess(index_guess);
    }
}

// Owner with the proxy as a virtual base: vbptr at +4, input at +8.
struct DynamicPropertyVBBase_guess {
    int unused_guess;
};

struct DynamicPropertyVBOwner_guess : DynamicPropertyVBBase_guess, virtual DynamicPropertyProxy_guess {
    DynamicPropertyInput_guess* input_guess;
    char* KunarkClass_guess(int index_guess, int level_guess, int unused_guess, char flag_guess);
};

// Class title above level 50 unless `flag_guess`: titles for 51-54, 55-59, 60-64, then 65-69 (0x167B+) and
// 70+ (0x1719+); otherwise the class name, as ClassName_guess but in the static buffer 0x79DB2C.
// -1 takes this character's level and class; the 0x5ED4B0 value read there is unused.
// FUNCTION: TITANIUM 0x00419631
char* DynamicPropertyVBOwner_guess::KunarkClass_guess(int index_guess, int level_guess, int unused_guess,
                                                         char flag_guess) {
    if (index_guess == -1) {
        level_guess = FindResult_guess()->level_11a4_guess;
        if (input_guess != 0 && input_guess->type_0244_guess == 0) {
            GetWidget_guess()->GetDeity_guess();
        }
        index_guess = FindResult_guess()->state_guess;
    }
    char* buf_guess = EQ_ARRAY(char, 0x0079DB2C);
    // From level 51 each class has a title per band: 51-54, 55-59, 60-64, 65-69 and 70 on.
    if (level_guess >= 51 && flag_guess == 0) {
        switch (index_guess) {
        case 16:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x16a1, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x16a2, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x16a3, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x16a4, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1719, 0));
            break;
        case 1:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5df, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5e0, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5e1, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x167b, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171a, 0));
            break;
        case 2:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5e3, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5e4, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5e5, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x167c, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171b, 0));
            break;
        case 3:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5e7, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5e8, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5e9, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x167d, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171c, 0));
            break;
        case 5:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5eb, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5ec, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5ed, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x167e, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171d, 0));
            break;
        case 4:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5ef, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5f0, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5f1, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x167f, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171e, 0));
            break;
        case 6:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5f3, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5f4, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5f5, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1680, 0));
            else strcpy(buf_guess, pStringTable->getString(0x171f, 0));
            break;
        case 7:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5f7, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5f8, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5f9, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1681, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1720, 0));
            break;
        case 8:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5fb, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x5fc, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x5fd, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1682, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1721, 0));
            break;
        case 9:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x5ff, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x600, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x601, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1683, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1722, 0));
            break;
        case 10:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x603, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x604, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x605, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1684, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1723, 0));
            break;
        case 11:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x607, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x608, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x609, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1685, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1724, 0));
            break;
        case 12:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x60b, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x60c, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x60d, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1686, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1725, 0));
            break;
        case 13:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x60f, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x610, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x611, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1687, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1726, 0));
            break;
        case 14:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x613, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x614, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x615, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1688, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1727, 0));
            break;
        case 15:
            if (level_guess < 55) strcpy(buf_guess, pStringTable->getString(0x617, 0));
            else if (level_guess < 60) strcpy(buf_guess, pStringTable->getString(0x618, 0));
            else if (level_guess < 65) strcpy(buf_guess, pStringTable->getString(0x619, 0));
            else if (level_guess < 70) strcpy(buf_guess, pStringTable->getString(0x1689, 0));
            else strcpy(buf_guess, pStringTable->getString(0x1728, 0));
            break;
        default:
            strcpy(buf_guess, pStringTable->getString(0x5cc, 0));
            break;
        }
        return buf_guess;
    }
    switch (index_guess) {
    case 1: strcpy(buf_guess, pStringTable->getString(0x5de, 0)); break;
    case 2: strcpy(buf_guess, pStringTable->getString(0x5e2, 0)); break;
    case 3: strcpy(buf_guess, pStringTable->getString(0x5e6, 0)); break;
    case 5: strcpy(buf_guess, pStringTable->getString(0x5ea, 0)); break;
    case 4: strcpy(buf_guess, pStringTable->getString(0x5ee, 0)); break;
    case 6: strcpy(buf_guess, pStringTable->getString(0x5f2, 0)); break;
    case 7: strcpy(buf_guess, pStringTable->getString(0x5f6, 0)); break;
    case 8: strcpy(buf_guess, pStringTable->getString(0x5fa, 0)); break;
    case 9: strcpy(buf_guess, pStringTable->getString(0x5fe, 0)); break;
    case 10: strcpy(buf_guess, pStringTable->getString(0x602, 0)); break;
    case 11: strcpy(buf_guess, pStringTable->getString(0x606, 0)); break;
    case 12: strcpy(buf_guess, pStringTable->getString(0x60a, 0)); break;
    case 13: strcpy(buf_guess, pStringTable->getString(0x60e, 0)); break;
    case 14: strcpy(buf_guess, pStringTable->getString(0x612, 0)); break;
    case 15: strcpy(buf_guess, pStringTable->getString(0x616, 0)); break;
    case 16: strcpy(buf_guess, pStringTable->getString(0x169f, 0)); break;
    case 0x29: return pStringTable->getString(0x5cd, 0);
    case 0x28: return pStringTable->getString(0x5ce, 0);
    case 0x14: return pStringTable->getString(0x5cf, 0);
    case 0x15: return pStringTable->getString(0x5d0, 0);
    case 0x16: return pStringTable->getString(0x5d1, 0);
    case 0x18: return pStringTable->getString(0x5d2, 0);
    case 0x17: return pStringTable->getString(0x5d3, 0);
    case 0x19: return pStringTable->getString(0x5d4, 0);
    case 0x1a: return pStringTable->getString(0x5d5, 0);
    case 0x1b: return pStringTable->getString(0x5d6, 0);
    case 0x1c: return pStringTable->getString(0x5d7, 0);
    case 0x1d: return pStringTable->getString(0x5d8, 0);
    case 0x1e: return pStringTable->getString(0x5d9, 0);
    case 0x1f: return pStringTable->getString(0x5da, 0);
    case 0x20: return pStringTable->getString(0x5db, 0);
    case 0x21: return pStringTable->getString(0x5dc, 0);
    case 0x22: return pStringTable->getString(0x5dd, 0);
    case 0x23: return pStringTable->getString(0x16a0, 0);
    default: strcpy(buf_guess, pStringTable->getString(0x5cc, 0)); break;
    }
    return buf_guess;
}

// EXTERNAL: TITANIUM 0x00574110 LogFailure_guess
void __cdecl LogFailure_guess(const char* message_guess, ...);

// EXTERNAL: TITANIUM 0x00417355 ClassMinBase_guess
unsigned char __stdcall ClassMinBase_guess(int race_guess, int attr_guess);

#define g_classMinTable_guess EQ_ARRAY(int, 0x00694DA0)

struct ClassMinOwner_guess {
    int unused_guess;
    char ClassMin_guess(int cclass_guess, int race_guess, int attr_guess);
};

// ClassMin (its own log text): the class's entry for stat `attr_guess` (0-6) in table 0x694DA0,
// 16 classes per stat, for `race_guess` = race id - 1 (0-11, 127, 129, 329); 0 when out of range.
// Adding and then subtracting the race base only tests that the entry is positive.
// FUNCTION: TITANIUM 0x00419DFD
char ClassMinOwner_guess::ClassMin_guess(int cclass_guess, int race_guess, int attr_guess) {
    if (cclass_guess < 0 || cclass_guess > 0xf) {
        LogFailure_guess("cclass (%d) out of range in ClassMin()!\n", cclass_guess);
        return 0;
    }
    if (race_guess < 0 ||
        (race_guess > 0xb && race_guess != 0x7f && race_guess != 0x81 && race_guess != 0x149)) {
        LogFailure_guess("selRace (%d) out of range in ClassMin()!\n", race_guess);
        return 0;
    }
    if ((unsigned char)attr_guess > 6) {
        LogFailure_guess("attr (%d) out of range in ClassMin()!\n", (unsigned char)attr_guess);
        return 0;
    }
    int base_guess = ClassMinBase_guess(race_guess, attr_guess);
    int value_guess = g_classMinTable_guess[(unsigned char)attr_guess * 16 + cclass_guess];
    if (value_guess != 0) {
        value_guess += base_guess;
        if (value_guess > base_guess) {
            char result_guess = (char)value_guess;
            result_guess -= base_guess;
            return result_guess;
        }
    }
    return 0;
}

// Whether a race and class may worship deity row `row_guess` (CanWorship by its callees); -1 takes
// this character's race and class. Dispatches to the race tables above; Froglok (330) reads 0x695E50
// inline; other races get 0.
// FUNCTION: TITANIUM 0x00419E83
char DynamicPropertyOwner_guess::CanWorship_guess(int race_guess, int class_guess, int row_guess) {
    if (race_guess == -1) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        race_guess = proxy_guess->lookup_guess.Find_guess()->database_string_id_guess;
    }
    unsigned char column;
    if (class_guess == -1) {
        DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        column = proxy_guess->lookup_guess.Find_guess()->state_guess - 1;
    } else {
        column = static_cast<unsigned char>(class_guess);
    }
    switch (race_guess) {
    case 1:
        return reinterpret_cast<SkillTable_guess*>(this)->HumanCanWorship_guess(column, row_guess);
    case 2:
        return reinterpret_cast<SkillTable_guess*>(this)->BarbarianCanWorship_guess(column, row_guess);
    case 3:
        return reinterpret_cast<SkillTable_guess*>(this)->EruditeCanWorship_guess(column, row_guess);
    case 4:
        return reinterpret_cast<SkillTable_guess*>(this)->ElfCanWorship_guess(column, row_guess);
    case 5:
        return reinterpret_cast<SkillTable_guess*>(this)->HighElfCanWorship_guess(column, row_guess);
    case 6:
        return reinterpret_cast<SkillTable_guess*>(this)->DarkElfCanWorship_guess(column, row_guess);
    case 7:
        return reinterpret_cast<TableLookup_guess*>(this)->HalfElfCanWorship_guess(column, row_guess);
    case 8:
        return reinterpret_cast<TableLookup_guess*>(this)->DwarfCanWorship_guess(column, row_guess);
    case 9:
        return reinterpret_cast<TableLookup_guess*>(this)->TrollCanWorship_guess(column, row_guess);
    case 10:
        return reinterpret_cast<TableLookup_guess*>(this)->OgreCanWorship_guess(column, row_guess);
    case 11:
        return reinterpret_cast<TableLookup_guess*>(this)->HalflingCanWorship_guess(column, row_guess);
    case 12:
        return reinterpret_cast<TableLookup_guess*>(this)->GnomeCanWorship_guess(column, row_guess);
    case 0x80:
        return reinterpret_cast<TableLookup_guess*>(this)->IksarCanWorship_guess(column, row_guess);
    case 0x82:
        return reinterpret_cast<TableLookup_guess*>(this)->VahShirCanWorship_guess(column, row_guess);
    case 0x14a:
        return EQ_ARRAY(char, 0x00695E50)[static_cast<unsigned char>(row_guess) * 0x10 + column];
    default:
        return 0;
    }
}

// A countdown on the spawn's +0x1A8 -> +0x153 counter, one step per second while standing (+0x251 = 100):
// counts 6-2 play OP_Animation (speed 12) 43, 6, 5, 7, 2 (Monks 43, 1, 0x2F, 0x2D, 0x2E). Without a target,
// or targeting oneself, string 0x3193 prints instead and the counter clears, as it does in any other state.
// FUNCTION: TITANIUM 0x0041A037
// @early-stop: budget, structural ndiff=76
void DynamicPropertyOwner_guess::ConsumeCharge_guess() {
    ChargeRecord_guess record_guess;
    if (input_guess != 0) {
        if (input_guess->type_0244_guess == 0) {
            if (input_guess->padding_0251_guess[0] == 'd') {
                if (input_guess->threshold_guess->charges_guess < 1) {
                    return;
                }
                if (g_refreshService_guess->tick_guess < input_guess->threshold_guess->next_time_guess) {
                    return;
                }
                if (g_chargeTarget_guess == 0 || g_chargeTarget_guess == input_guess ||
                    g_chargeTarget_guess == g_chargeSkip_guess) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3193, 0), 0x10e, true);
                } else if (input_guess->threshold_guess->charges_guess != 1) {
                    switch (input_guess->threshold_guess->charges_guess) {
                    case 2:
                        record_guess.value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                       ->lookup_guess.Find_guess()->state_guess == 7 ? 0x2e : 2;
                        break;
                    case 3:
                        record_guess.value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                       ->lookup_guess.Find_guess()->state_guess == 7 ? 0x2d : 7;
                        break;
                    case 4:
                        record_guess.value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                       ->lookup_guess.Find_guess()->state_guess == 7 ? 0x2f : 5;
                        break;
                    case 5:
                        record_guess.value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                       ->lookup_guess.Find_guess()->state_guess == 7 ? 1 : 6;
                        break;
                    case 6:
                        reinterpret_cast<DynamicPropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->lookup_guess.Find_guess();
                        record_guess.value_guess = '+';
                        break;
                    default:
                        return;
                    }
                    input_guess->threshold_guess->charges_guess--;
                    input_guess->threshold_guess->next_time_guess = g_refreshService_guess->tick_guess + 1000;
                    record_guess.spawn_id_guess = input_guess->spawn_id_guess;
                    record_guess.type_guess = 0xc;
                    input_guess->GetObject_guess()->Notify_guess(record_guess.value_guess, 1, 0, 1.2f, 1);
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Animation, &record_guess, 4, 1);
                    return;
                }
                input_guess->threshold_guess->next_time_guess = 0;
            }
        }
        input_guess->threshold_guess->charges_guess = 0;
    }
}

// Coins on the person as copper: platinum*1000 + gold*100 + silver*10 + copper, in 64 bits.
// FUNCTION: TITANIUM 0x0041A259
__int64 DynamicPropertyOwner_guess::GetEncodedValue_guess() {
    DynamicPropertyProxy_guess* third_proxy_guess = GetTable_guess();
    int third_guess = third_proxy_guess->lookup_guess.Find_guess()->tail_guess.third_value_guess;
    DynamicPropertyProxy_guess* fourth_proxy_guess = GetTable_guess();
    int fourth_guess = fourth_proxy_guess->lookup_guess.Find_guess()->tail_guess.fourth_value_guess;
    DynamicPropertyProxy_guess* fifth_proxy_guess = GetTable_guess();
    int fifth_guess = fifth_proxy_guess->lookup_guess.Find_guess()->tail_guess.fifth_value_guess;
    DynamicPropertyProxy_guess* sixth_proxy_guess = GetTable_guess();
    LookupResult_guess* result_guess = sixth_proxy_guess->lookup_guess.Find_guess();
    return ((((__int64)third_guess * 10 + fourth_guess) * 10 + fifth_guess) * 10 +
            result_guess->tail_guess.sixth_value_guess);
}

// Pays `value_guess` copper: the total minus it, re-split into platinum, gold, silver and copper. It does
// not check that enough is on hand.
// FUNCTION: TITANIUM 0x0041A316
void DynamicPropertyOwner_guess::ApplyEncodedValue_guess(int value_guess) {
    __int64 difference_guess = GetEncodedValue_guess() - value_guess;
    BasePropertyProxy_guess()->SetThird_guess(static_cast<int>(difference_guess / 1000));
    BasePropertyProxy_guess()->SetFourth_guess(static_cast<int>((difference_guess % 1000) / 100));
    BasePropertyProxy_guess()->SetFifth_guess(static_cast<int>((difference_guess % 100) / 10));
    BasePropertyProxy_guess()->SetSixth_guess(static_cast<int>(difference_guess % 10));
}

// Adds `value_guess` copper as platinum, gold, silver and copper, with no carry between coin types.
// FUNCTION: TITANIUM 0x0041A3C5
void DynamicPropertyOwner_guess::AddEncodedValue_guess(int value_guess) {
    int thousands_guess = value_guess / 1000;
    value_guess -= thousands_guess * 1000;
    int hundreds_guess = value_guess / 100;
    value_guess -= hundreds_guess * 100;
    int tens_guess = value_guess / 10;
    BasePropertyProxy_guess()->AddThird_guess(thousands_guess);
    BasePropertyProxy_guess()->AddFourth_guess(hundreds_guess);
    BasePropertyProxy_guess()->AddFifth_guess(tens_guess);
    BasePropertyProxy_guess()->AddSixth_guess(value_guess - tens_guess * 10);
}

#define g_characterOwner_guess EQ_GLOBAL(DynamicPropertyWidget_guess*, 0x00905D00)
#define g_unknownFlag_guess EQ_GLOBAL(unsigned char, 0x009239DC)

struct HideModeRecord_guess {
    unsigned short spawn_id_guess;
    unsigned short type_guess;
    unsigned int state_guess;
};

struct CharacterPrefix_guess {
    virtual void PSlot00_guess();
};

struct CharacterBase_guess : EQ_CharacterProfile_guess {
    virtual void VSlot00_guess();
    virtual void VSlot01_guess();
    virtual void VSlot02_guess();
    virtual void VSlot03_guess();
    virtual void VSlot04_guess();
    virtual void VSlot05_guess();
    virtual void VSlot06_guess();
    virtual void VSlot07_guess();
    virtual void VSlot08_guess();
    virtual void VSlot09_guess();
    virtual void VSlot0a_guess();
    virtual void VSlot0b_guess();
    virtual void VSlot0c_guess();
    virtual void VSlot0d_guess();
    virtual void VSlot0e_guess();
    virtual void VSlot0f_guess();
    virtual DynamicPropertyWidget_guess* GetOwner_guess();
};

struct CharacterObject_guess : CharacterPrefix_guess, virtual CharacterBase_guess {
    DynamicPropertyInput_guess* input_guess;
    char padding_00c_guess[0xf8];
    // EXTERNAL: TITANIUM 0x0040E934 CharacterObject_guess::FindBuffWithEffect_guess
    void* FindBuffWithEffect_guess(int value_guess, int* index_guess);
    // EXTERNAL: TITANIUM 0x00411F2F CharacterObject_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(void* entry_guess);
    void UpdateInvisibility_guess();
};

struct PcData_guess {
    char padding_0000_guess[0xc280];
    CharacterObject_guess character_guess;
};

#define g_pcData_guess EQ_GLOBAL(PcData_guess*, 0x00905D00)

// Works out the spawn's invisibility (+0x250: 1 invisible, 2 vs animals, 3 vs undead) from 0x5ED840 (0x9239DC
// keeps it) and the SPA 12/314, 29/316 and 28/315 buffs; Bankers and Merchants are skipped. On a change it
// drops the other kinds' buffs (OP_Buff fades) and sends OP_SpawnAppearance type 3.
// FUNCTION: TITANIUM 0x0041A44A
void CharacterObject_guess::UpdateInvisibility_guess() {
    HideModeRecord_guess record_guess;
    int index_guess;
    DynamicPropertyInput_guess* input = input_guess;
    if (input != 0) {
        unsigned char previous_guess = input->hide_mode_guess;
        input->SetState_guess(0);
        if (reinterpret_cast<LookupResult_guess*>(static_cast<CharacterBase_guess*>(this)->GetCharInfo2())
                ->state_guess >= 0x28) {
            if (reinterpret_cast<LookupResult_guess*>(static_cast<CharacterBase_guess*>(this)->GetCharInfo2())
                    ->state_guess <= 0x29) {
                return;
            }
        }
        if (g_characterOwner_guess->FUN_005ed840_guess()) {
            g_unknownFlag_guess = 1;
        }
        if (g_unknownFlag_guess != 0) {
            input_guess->SetState_guess(1);
        }
        if (input_guess->hide_mode_guess == 0) {
            if (input_guess->type_0244_guess == 0 &&
                static_cast<CharacterBase_guess*>(this)->GetOwner_guess()->FUN_005ed840_guess()) {
                input_guess->SetState_guess(1);
            } else if (reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0xc, 1, 0, 1) > 0 ||
                       reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x13a, 1, 0, 1) > 0) {
                input_guess->SetState_guess(1);
            } else if (reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x1c, 1, 0, 1) > 0 ||
                       reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x13b, 1, 0, 1) > 0) {
                input_guess->SetState_guess(3);
            } else if (reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x1d, 1, 0, 1) > 0 ||
                       reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x13c, 1, 0, 1) > 0) {
                input_guess->SetState_guess(2);
            }
        }
        if (input_guess->hide_mode_guess != previous_guess) {
            record_guess.spawn_id_guess = input_guess->spawn_id_guess;
            record_guess.type_guess = 3;
            record_guess.state_guess = input_guess->hide_mode_guess;
            if (input_guess->hide_mode_guess != 1) {
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0xc, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0x13a, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
            }
            if (input_guess->hide_mode_guess != 3) {
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0x1c, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0x13b, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
            }
            if (input_guess->hide_mode_guess != 2) {
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0x1d, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_pcData_guess->character_guess.RemovePCAffect_guess(
                    g_pcData_guess->character_guess.FindBuffWithEffect_guess(0x13c, &index_guess));
                if (index_guess != -1) {
                    reinterpret_cast<MessageObject_guess*>(this)->NotifyPCAffectChange_guess(index_guess, 1);
                }
            }
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_SpawnAppearance, &record_guess, 8, 1);
        }
        input_guess->UpdatePlayerVisibility_guess();
    }
}

// Breathing is automatic when +0x1A8 -> +0xAC is below 5 and the 0x905CC0 check on +0x104 fails; otherwise
// only races 24, 35 and 74 or SPA 14 WaterBreathing allow it.
// FUNCTION: TITANIUM 0x0041A753
bool DynamicPropertyOwner_guess::CanBreathe_guess() {
    int selected_guess = 0;
    if (g_propertyFilter_guess->Check_guess(
            GetTable_guess()->property_value_guess)) {
        ++selected_guess;
    }
    bool allowed_guess;
    if ((input_guess->threshold_guess->state_guess < 5 && selected_guess == 0) ||
        GetTable_guess()->FindResult_guess()->database_string_id_guess == 0x4a ||
        GetTable_guess()->FindResult_guess()->database_string_id_guess == 0x18 ||
        GetTable_guess()->FindResult_guess()->database_string_id_guess == 0x23) {
        allowed_guess = true;
    } else {
        allowed_guess = reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0xe, 1, 0, 1) > 0;
    }
    return allowed_guess;
}

// Takes the endurance upkeep (+0x9C); when endurance goes below 0 it is set to 0 and a player's running
// discipline (GetDisciplineEffect_guess) is removed (RemovePCAffect_guess).
// FUNCTION: TITANIUM 0x0041A7F8
void DynamicPropertyOwner_guess::ApplyEnduranceUpkeep_guess() {
    GetTable_guess()->Update_guess(-value_009c_guess);
    if (GetTable_guess()->FindResult_guess()->first_value_guess < 0) {
        GetTable_guess()->FindResult_guess()->first_value_guess = 0;
        if (input_guess != 0 && input_guess->type_0244_guess == 0) {
            DynamicPropertyWidget_guess* widget_guess = GetTable_guess()->GetWidget_guess();
            Finish_guess(widget_guess->GetValue_guess());
        }
    }
}

// __stdcall. Clamps a player's `*value_guess` to 1..cap by level and class: priests (Cleric, Druid, Shaman),
// int casters and the rest get 9/6/10 below level 10, 12/10/14 at 10-19, 20/12/30 at 20-29, 26/18/60 at
// 30-39 and 80/40/200 from 40. NPCs pass untouched; always returns 0.
// FUNCTION: TITANIUM 0x0041A877
int __stdcall ApplyLevelDamageCap_guess(DynamicPropertyOwner_guess* owner_guess, int* value_guess, int unused_guess) {
    if (owner_guess->input_guess == 0) {
        return 0;
    }
    if (owner_guess->input_guess->type_0244_guess != 0) {
        return 0;
    }
    int limit_guess;
    DynamicPropertyProxy_guess* proxy_guess = owner_guess->GetTable_guess();
    if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x27) {
        proxy_guess = owner_guess->GetTable_guess();
        unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
        if (state_guess == 2 || state_guess == 6 || state_guess == 10) {
            limit_guess = 0x50;
        } else if (state_guess <= 10 || state_guess > 14) {
            limit_guess = 200;
        } else {
            limit_guess = 0x28;
        }
    } else {
        proxy_guess = owner_guess->GetTable_guess();
        if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x1d) {
            proxy_guess = owner_guess->GetTable_guess();
            unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
            if (state_guess == 2 || state_guess == 6 || state_guess == 10) {
                limit_guess = 0x1a;
            } else if (state_guess <= 10 || state_guess > 14) {
                limit_guess = 0x3c;
            } else {
                limit_guess = 0x12;
            }
        } else {
            proxy_guess = owner_guess->GetTable_guess();
            if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 0x13) {
                proxy_guess = owner_guess->GetTable_guess();
                unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
                if (state_guess == 2 || state_guess == 6 || state_guess == 10) {
                    limit_guess = 0x14;
                } else if (state_guess <= 10 || state_guess > 14) {
                    limit_guess = 0x1e;
                } else {
                    limit_guess = 0xc;
                }
            } else {
                proxy_guess = owner_guess->GetTable_guess();
                if (proxy_guess->lookup_guess.Find_guess()->level_11a4_guess > 9) {
                    proxy_guess = owner_guess->GetTable_guess();
                    unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
                    if (state_guess == 2 || state_guess == 6 || state_guess == 10) {
                        limit_guess = 0xc;
                    } else if (state_guess <= 10 || state_guess > 14) {
                        limit_guess = 0xe;
                    } else {
                        limit_guess = 10;
                    }
                } else {
                    proxy_guess = owner_guess->GetTable_guess();
                    unsigned char state_guess = proxy_guess->lookup_guess.Find_guess()->state_guess;
                    if (state_guess == 2 || state_guess == 6 || state_guess == 10) {
                        limit_guess = 9;
                    } else if (state_guess > 10 && state_guess <= 14) {
                        limit_guess = 6;
                    } else {
                        limit_guess = 10;
                    }
                }
            }
        }
    }
    // Keep the value between 1 and the state's limit.
    if (*value_guess < 1) {
        *value_guess = 1;
    }
    if (*value_guess > limit_guess) {
        *value_guess = limit_guess;
    }
    return 0;
}

struct RankValues_guess {
    BoundedArray_guess<int, 9> values;

    void Copy_guess(const RankValues_guess& source);
};

// Copies the nine values of `source`.
// FUNCTION: TITANIUM 0x0041A9FF
// @early-stop: budget, structural ndiff=19
void RankValues_guess::Copy_guess(const RankValues_guess& source) {
    for (unsigned int i = 0; i < 9; ++i) {
        values[i] = source.values.data[i];
    }
}

// Bounds-checked profile arrays (__debugbreak on overflow): the 512-entry spell book (+0x730, probably),
// the 100 skills (+0xF70) and the 31 inventory pointers (+0x10, slots 0-30).
// Spell book entry.
// FUNCTION: TITANIUM 0x0041AA26
int ArrayOwner_guess::GetValue_guess(unsigned int index_guess) {
    if (index_guess >= 0x200) {
        __debugbreak();
    }
    return values_guess[index_guess];
}

// Sets a skill.
// FUNCTION: TITANIUM 0x0041AA3C
void ArrayOwner_guess::SetIndexedValue_guess(unsigned int index_guess, int value_guess) {
    if (index_guess >= 0x64) {
        __debugbreak();
    }
    indexed_values_guess[index_guess] = value_guess;
}

// Spell book entry, through the profile.
// FUNCTION: TITANIUM 0x0041AA54
int IndexedPropertyProxy_guess::GetValue_guess(unsigned int index_guess) {
    return reinterpret_cast<ArrayOwner_guess*>(lookup_guess.Find_guess())->GetValue_guess(index_guess);
}

// Sets a skill, through the profile.
// FUNCTION: TITANIUM 0x0041AA6A
void IndexedPropertyProxy_guess::SetValue_guess(unsigned int index_guess, int value_guess) {
    reinterpret_cast<ArrayOwner_guess*>(lookup_guess.Find_guess())->SetIndexedValue_guess(index_guess, value_guess);
}

// Sets an inventory slot pointer.
// FUNCTION: TITANIUM 0x0041AA84
void PropertyProxy_guess::SetArrayValue_guess(unsigned int index_guess, int value_guess) {
    LookupResult_guess* result_guess = lookup_guess.Find_guess();
    unsigned int index = index_guess;
    int* values = result_guess->initial_values_guess;
    if (index >= 31) {
        __debugbreak();
    }
    values[index] = value_guess;
}

// Deleting destructor of the member at +0xD8: runs its two cleanup steps and frees the outer block when
// `flag` bit 0 is set.
// FUNCTION: TITANIUM 0x0041AAA3
void* AllocatedObject_guess::Complete_guess(unsigned char flag) {
    char* allocation = reinterpret_cast<char*>(this) - 0xd8;
    AllocatedObject_guess* object = reinterpret_cast<AllocatedObject_guess*>(allocation + 0xd8);
    object->Initialize_guess();
    object->Finish_guess();
    if (flag & 1) {
        free(allocation);
    }
    return allocation;
}

struct RankState_guess {
    int field_0000;
    int field_0004;
    int field_0008;
    char field_000c;
    char pad_000d[3];
    int field_0010;
    int field_0014;
    int field_0018;
    int field_001c;
    int field_0020;
    int field_0024;
    int field_0028;
    int field_002c;
    int field_0030;
    int field_0034;
    int field_0038;
    int field_003c;
    int field_0040;
    int field_0044;
    int field_0048;
    int field_004c;
    int field_0050;
    int field_0054;
    int field_0058;
    int field_005c;
    int field_0060;
    int field_0064;
    int field_0068;
    int field_006c;
    int field_0070;
    int field_0074;
    BoundedArray_guess<int, 9> values_0078;
    int field_009c;
    int field_00a0;
    int field_00a4;
    int field_00a8;
    int field_00ac;
    int field_00b0;
    int field_00b4;
    int field_00b8;
    int field_00bc;
    char field_00c0;
    char field_00c1;

    void Reset_guess();
};

// Clears the item-stat summary that Accumulate_guess (0x41B6B7) fills.
// FUNCTION: TITANIUM 0x0041AAD4
void RankState_guess::Reset_guess() {
    field_0008 = 0;
    field_000c = 0;
    field_0010 = 0;
    field_0014 = 0;
    field_0018 = 0;
    field_001c = 0;
    field_0020 = 0;
    field_0024 = 0;
    field_0028 = 0;
    field_002c = 0;
    field_0030 = 0;
    field_0034 = 0;
    field_0038 = 0;
    field_003c = 0;
    field_0040 = 0;
    field_0044 = 0;
    field_0048 = 0;
    field_004c = 0;
    field_0050 = 0;
    field_0054 = 0;
    field_005c = 0;
    field_0060 = 0;
    field_0064 = 0;
    field_0068 = 0;
    field_006c = 0;
    field_00a0 = 0;
    field_0070 = 0;
    field_0074 = 0;
    field_00a4 = 0;
    field_00a8 = 0;
    field_00ac = 0;
    field_00b0 = 0;
    field_00b4 = 0;
    field_00b8 = 0;
    field_00bc = 0;
    for (int i = 0; i < 9; ++i) {
        values_0078[i] = 0;
    }
    field_009c = 0;
    field_00c0 = 0;
    field_00c1 = 0;
}

// Adds `value_guess` to base HP (ModifyCurHP in the earlier sibling decomp), clamped to -32768..10,000,000, for any
// spawn but an NPC; resets it to Max_HP when the result overshoots.
// FUNCTION: TITANIUM 0x0041AB7E
void CostUpdateView_guess::ModifyCurHP_guess(int value_guess, int unused_guess) {
    int computed_guess = 0;
    if (value_guess != 0) {
        if (entity_guess != 0) {
            computed_guess = reinterpret_cast<CostOwner_guess*>(this)->Max_HP_guess(entity_guess->state_guess);
        }
        if (entity_guess != 0 && entity_guess->state_guess == 0) {
            reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(0);
        }
        if (entity_guess != 0) {
            reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(entity_guess->state_guess);
        }
        if (entity_guess == 0 || entity_guess->state_guess != 1) {
            DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            int value = proxy_guess->lookup_guess.Find_guess()->second_value_guess + value_guess;
            if (10000000.0 < (double)value) {
                value = 10000000;
            }
            if (value < -0x8000) {
                value = -0x8000;
            }
            reinterpret_cast<PropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->SetSecond_guess(value);
            if (entity_guess != 0 &&
                reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(entity_guess->state_guess) >
                    computed_guess) {
                ResetCur_HP_guess(entity_guess->state_guess);
            }
        }
    }
}

struct RankOffset_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct ItemInstance_guess;

struct InventorySlots_guess {
    char padding_0000_guess[4];
    // EXTERNAL: TITANIUM 0x0040CC50 InventorySlots_guess::GetEntry_guess
    ItemInstance_guess* GetEntry_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x0040CC6B InventorySlots_guess::GetSmallEntry_guess
    ItemInstance_guess* GetSmallEntry_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x005FA3D0 InventorySlots_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0041AA84 InventorySlots_guess::SetArrayValue_guess
    void SetArrayValue_guess(unsigned int index_guess, int value_guess);
};

struct ItemInstance_guess {
    virtual void Release_guess(int flag_guess);
    char padding_0004_guess[0x44];
    int chargesOrStackCount_0048_guess;
    // EXTERNAL: TITANIUM 0x005ECCC0 ItemInstance_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0130 ItemInstance_guess::FUN_005e0130_guess
    int FUN_005e0130_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0E00 ItemInstance_guess::FUN_005e0e00_guess
    int FUN_005e0e00_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 ItemInstance_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC760 ItemInstance_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005DFD00 ItemInstance_guess::Matches_guess
    char Matches_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E2F90 ItemInstance_guess::GetRankFor_guess
    int GetRankFor_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005E3210 ItemInstance_guess::GetRankForValue_guess
    int GetRankForValue_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x005E0D40 ItemInstance_guess::GetRank_guess
    int GetRank_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ItemInstance_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 ItemInstance_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 ItemInstance_guess::GetEntry_guess
    ItemInstance_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC660 ItemInstance_guess::DeleteSubentry_guess
    void DeleteSubentry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0BF0 ItemInstance_guess::HasValue240_guess
    int HasValue240_guess();
    // EXTERNAL: TITANIUM 0x005E0AA0 ItemInstance_guess::HasFlag12f_guess
    int HasFlag12f_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E04C0 ItemInstance_guess::GetRecommendedLevel_guess
    int GetRecommendedLevel_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E2350 ItemInstance_guess::GetRankValue_guess
    int GetRankValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0540 ItemInstance_guess::GetContextValue_guess
    int GetContextValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0190 ItemInstance_guess::HasContextFlag_guess
    int HasContextFlag_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0230 ItemInstance_guess::GetContextCount_guess
    int GetContextCount_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E02D0 ItemInstance_guess::HasContextValue_guess
    int HasContextValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0350 ItemInstance_guess::HasAlternateContextValue_guess
    int HasAlternateContextValue_guess(int value_guess);
};

struct RankTimer_guess {
    char padding_0000_guess[0x5c];
    unsigned int last_guess;
    char padding_0060_guess[0xfc];
    int value_015c_guess;
};

struct RankStore_guess {
    char padding_0000_guess[0x1a8];
    RankTimer_guess* timer_01a8_guess;
    char padding_01ac_guess[0x98];
    unsigned char type_0244_guess;
    char padding_0245_guess[0x0c];
    unsigned char mode_0251_guess;
    char padding_0252_guess;
    unsigned char light_0253_guess;
    char padding_0254_guess[2];
    unsigned char gm_0256_guess;
    // EXTERNAL: TITANIUM 0x00479396 RankStore_guess::IsLocked_guess
    int IsLocked_guess();
    // EXTERNAL: TITANIUM 0x0048083A RankStore_guess::SetStat_guess
    void SetStat_guess(int value_guess, const char* text_guess, int flag_guess);
};

struct RankMessage_guess {
    int value_guess;
    int first_guess;
    int second_guess;
};

struct InventoryView_guess {
    int unused_guess;
    RankOffset_guess* offset_holder_guess;
    RankStore_guess* store_guess;
    char value_000c_guess;
    // EXTERNAL: TITANIUM 0x004106A3 InventoryView_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int value_guess, int count_guess, int min_guess, int max_guess);
    // EXTERNAL: TITANIUM 0x0041DE8E InventoryView_guess::AutoConsume_guess
    int AutoConsume_guess(char which_guess);
    // EXTERNAL: TITANIUM 0x0041AAD4 InventoryView_guess::Prepare_guess
    void Prepare_guess();
    void ProcessHungerandThirst_guess(int now_guess);
    void DoLight_guess(int param_guess);
    char FindItemByType_guess(int value_guess, int* index_guess, int* subindex_guess);
    char FindItemById_guess(int value_guess, int* index_guess, int* subindex_guess, char mode_guess);
    int GetValue_guess(int value_guess);
    int CountItem_guess(int value_guess);
    char HasCountAtLeast_guess(int value_guess, int threshold_guess);
    int GetFoodDrinkStatus_guess();
    char RemoveOneItem_guess(int index_guess, int value_guess);
    // The virtual base (types.h EQ_CharacterBase_guess) = the vbptr's address (+4) + its table offset.
    char* VirtualBase_guess() {
        return reinterpret_cast<char*>(&offset_holder_guess) + offset_holder_guess->vbaseOffset_0004_guess;
    }
    InventorySlots_guess* BaseRankTable_guess() {
        return reinterpret_cast<InventorySlots_guess*>(VirtualBase_guess());
    }
};

struct RankHost_guess {
    void* vftable_guess;
    int value_0004_guess;
    RankOffset_guess* offset_holder_guess;
    char padding_000c_guess[0xc280];
    unsigned char flag_c28c_guess;
};

struct RankSlot_guess {
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
    virtual RankHost_guess* Slot16_guess();
};

struct ContextSubCheck_guess {
    int unused_guess;
    RankOffset_guess* offset_holder_guess;
    char HasItemId_guess(int count_guess);
};

// Bandolier check: true when one of the 31 inventory slots (rank table at this +offset +4) holds an item
// that 0x005DFD00 matches with the argument, which is really the item id (named a count). The bandolier
// window shows a row green when this holds, red when not.
// FUNCTION: TITANIUM 0x0041BABC
char ContextSubCheck_guess::HasItemId_guess(int count_guess) {
    for (int i = 0; i < 31; ++i) {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->GetEntry_guess(i) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(i)->Matches_guess(count_guess)) {
                return 1;
            }
        }
    }
    return 0;
}

// Carried weight: items in slots 0-30 (0x5E0130), bag contents cut by the bag's weight reduction
// (0x5E0E00), and coins on the person and cursor (+0x11D4-0x11F0). Items 17201-17230 in general slots 22-29
// (three bands of ten) cut coin weight by 10% per step. SPA 221 Packrat lowers the total; capped at
// 0x641090, and 0 below 0x63F4CC.
// FUNCTION: TITANIUM 0x0041BB06
// @early-stop: budget, structural ndiff=46
int CostOwner_guess::CalculateWeight_guess() {
    float total_guess = 0.0f;
    int index_guess = 0;
    do {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0) {
            total_guess += reinterpret_cast<InventorySlots_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                               ->GetEntry_guess(index_guess)
                               ->FUN_005e0130_guess(1) * EQ_GLOBAL(float, 0x00640e38);
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemClass_guess() == 1) {
                float weight_guess = EQ_GLOBAL(float, 0x00640e20) -
                                     reinterpret_cast<InventorySlots_guess*>(
                                         reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                         ->GetEntry_guess(index_guess)
                                         ->FUN_005e0e00_guess();
                int subindex_guess = 0;
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess)
                        ->GetCount_guess() > 0) {
                    do {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->GetEntry_guess(subindex_guess) != 0) {
                            total_guess +=
                                (reinterpret_cast<InventorySlots_guess*>(
                                     reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                     ->GetEntry_guess(index_guess)
                                     ->GetEntry_guess(subindex_guess)
                                     ->FUN_005e0130_guess(1) * EQ_GLOBAL(float, 0x00640e38)) *
                                (weight_guess * EQ_GLOBAL(float, 0x00640038));
                        }
                        ++subindex_guess;
                    } while (subindex_guess <
                             reinterpret_cast<InventorySlots_guess*>(
                                 reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                 ->GetEntry_guess(index_guess)
                                 ->GetCount_guess());
                }
            }
        }
        ++index_guess;
    } while (index_guess < 0x1f);

    int maximum_guess = 0;
    int value_11d4_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.third_value_guess;
    int value_11d8_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.fourth_value_guess;
    int value_11dc_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.fifth_value_guess;
    int value_11e0_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.sixth_value_guess;
    int value_11e4_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.value_11e4_guess;
    int value_11e8_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.value_11e8_guess;
    int value_11ec_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.value_11ec_guess;
    int value_11f0_guess = reinterpret_cast<LookupService_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                               ->Find_guess()
                               ->tail_guess.value_11f0_guess;
    int sum_guess = value_11f0_guess + value_11ec_guess + value_11e8_guess + value_11e4_guess +
                    value_11e0_guess + value_11dc_guess + value_11d8_guess + value_11d4_guess;
    float base_guess = static_cast<float>(sum_guess) * EQ_GLOBAL(float, 0x00641094);

    index_guess = 0x16;
    do {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() > 0x4330 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() < 0x433b) {
            int value_guess =
                (reinterpret_cast<InventorySlots_guess*>(
                     reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                     ->GetEntry_guess(index_guess)
                     ->GetItemId_guess() -
                 0x4330) *
                10;
            if (maximum_guess < value_guess) {
                maximum_guess = value_guess;
            }
        }
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() > 0x433a &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() < 0x4345) {
            int value_guess =
                (reinterpret_cast<InventorySlots_guess*>(
                     reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                     ->GetEntry_guess(index_guess)
                     ->GetItemId_guess() -
                 0x433a) *
                10;
            if (maximum_guess < value_guess) {
                maximum_guess = value_guess;
            }
        }
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() > 0x4344 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemId_guess() < 0x434f) {
            int value_guess =
                (reinterpret_cast<InventorySlots_guess*>(
                     reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                     ->GetEntry_guess(index_guess)
                     ->GetItemId_guess() -
                 0x4344) *
                10;
            if (maximum_guess < value_guess) {
                maximum_guess = value_guess;
            }
        }
        ++index_guess;
    } while (index_guess < 0x1e);

    if (maximum_guess > 0 && maximum_guess <= 100) {
        base_guess = static_cast<float>(100 - maximum_guess) * base_guess * EQ_GLOBAL(float, 0x00640038);
    }
    total_guess += base_guess;
    float result_guess = static_cast<float>(TotalSpellAffects_guess(0xdd, 1, 0, 1)) * total_guess *
                         EQ_GLOBAL(float, 0x00640038);
    result_guess = total_guess - result_guess;
    if (result_guess > EQ_GLOBAL(float, 0x00641090)) {
        result_guess = EQ_GLOBAL(float, 0x00641090);
    }
    if (result_guess < EQ_GLOBAL(float, 0x0063f4cc)) {
        result_guess = 0.0f;
    }
    return static_cast<int>(result_guess);
}

// The spawn's light (+0x253): the brightest light (0x5E0D40) of the non-container items in slots 0-30.
// FUNCTION: TITANIUM 0x0041AC65
void InventoryView_guess::DoLight_guess(int param_guess) {
    unsigned char rank_guess = 0;
    for (int index_guess = 0; index_guess < 0x1f; ++index_guess) {
        if (BaseRankTable_guess()->GetEntry_guess(index_guess) != 0) {
            if (BaseRankTable_guess()->GetEntry_guess(index_guess)
                    ->GetItemClass_guess() == 0) {
                if (BaseRankTable_guess()->GetEntry_guess(index_guess)
                        ->GetRank_guess() > rank_guess) {
                    rank_guess = BaseRankTable_guess()->GetEntry_guess(index_guess)
                                     ->GetRank_guess();
                }
            }
        }
    }
    store_guess->light_0253_guess = rank_guess;
}

// Skill value: the raw skill (0x40E722). For a non-GM player (spawn +0x256) with GetStatus_guess 0 it is cut
// to GetSkillCap_guess at an effective level (up to level + 2, from 0x5ED510), but not below the racial
// innate level (InnateSkillLevel_guess). Then SPA 122 ReduceSkill (percent, when the buff's spell names this
// skill), the best worn-item skill mod (slots 0-21) and, for Pick Lock, lockpicks (item type 12) on the
// cursor. Capped at 252 when CheckMaximum_guess says so.
// FUNCTION: TITANIUM 0x0041ACE9
// @early-stop: budget, structural ndiff=69
int CostOwner_guess::Skill_guess(int index_guess) {
    int value_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                          reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                          ->GetSkill_guess(index_guess);
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0 && pSpawn_0008_guess->gm_0256_guess == 0) {
        if (reinterpret_cast<LookupStatusObject_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetStatus_guess() == 0) {
            value_guess = reinterpret_cast<int>(reinterpret_cast<CostDynamicBlockView_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->base_guess.GetCandidate_guess());
            CostDynamicBlockView_guess* maximum_block_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            int maximum_guess = maximum_block_guess->lookup_guess.Find_guess()->level_11a4_guess;
            int threshold_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                                      reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                      ->lookup_guess.Find_guess()->level_11a4_guess;
            if (threshold_guess < reinterpret_cast<CostCandidate_guess*>(value_guess)->GetCurrentValue_guess()) {
                maximum_block_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
                maximum_guess = maximum_block_guess->lookup_guess.Find_guess()->level_11a4_guess;
                if (reinterpret_cast<CostCandidate_guess*>(value_guess)->GetCurrentValue_guess() < maximum_guess + 2) {
                    maximum_guess = reinterpret_cast<CostCandidate_guess*>(value_guess)->GetCurrentValue_guess();
                } else {
                    maximum_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                        ->lookup_guess.Find_guess()->level_11a4_guess + 2;
                }
            }
            value_guess = GetSkillCap_guess(
                maximum_guess,
                reinterpret_cast<CostDynamicBlockView_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->lookup_guess.Find_guess()->state_guess,
                index_guess, reinterpret_cast<CostCandidate_guess*>(value_guess));
            if (reinterpret_cast<CostDynamicBlockView_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetSkill_guess(index_guess) < value_guess) {
                value_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                                  reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                  ->GetSkill_guess(index_guess);
            }
            int related_value_guess = InnateSkillLevel_guess(
                index_guess,
                reinterpret_cast<CostDynamicBlockView_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->lookup_guess.Find_guess()->database_string_id_guess);
            if (value_guess <= related_value_guess) {
                value_guess = related_value_guess;
            }
        }
    }
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        CostModifier_guess* modifier_guess = FindModifier_guess(0x7a, 0);
        if (modifier_guess != 0 && CheckModifier_guess(modifier_guess->value_guess) != 0) {
            CostTarget_guess* target_guess = g_costRegistry_guess->GetTarget_guess(modifier_guess->value_guess);
            if (target_guess != 0 && target_guess->value_0030_guess == index_guess &&
                target_guess->value_00f0_guess > 0 && target_guess->value_00f0_guess < 0x65) {
                value_guess = ((100 - target_guess->value_00f0_guess) * value_guess) / 100;
            }
        }
    }
    int bonus_guess = 0;
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->state_guess == 0) {
        for (int slot_guess = 0; slot_guess < InvSlot_EquipmentCount; ++slot_guess) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(slot_guess) != 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(slot_guess)->GetItemClass_guess() == 0) {
                    int candidate_value_guess = reinterpret_cast<InventorySlots_guess*>(
                                                    reinterpret_cast<int>(this) +
                                                    offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                    ->GetEntry_guess(slot_guess)
                                                    ->GetRankForValue_guess(index_guess, value_guess, 1);
                    if (candidate_value_guess != 0 && bonus_guess < candidate_value_guess) {
                        bonus_guess = candidate_value_guess;
                    }
                }
            }
        }
        if (bonus_guess != 0) {
            value_guess += bonus_guess;
        }
        if (index_guess == 0x23) {
            LookupResult_guess* result_guess = reinterpret_cast<CostDynamicBlockView_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->lookup_guess.Find_guess();
            if (result_guess->initial_values_guess[30] != 0) {
                ItemInstance_guess* entry_guess = reinterpret_cast<ItemInstance_guess*>(
                    reinterpret_cast<CostDynamicBlockView_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->lookup_guess.Find_guess()->initial_values_guess[30]);
                int rank_guess = entry_guess->GetRankForValue_guess(index_guess, value_guess, 1);
                ItemInstance_guess* category_guess = reinterpret_cast<ItemInstance_guess*>(
                    reinterpret_cast<CostDynamicBlockView_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->lookup_guess.Find_guess()->initial_values_guess[30]);
                int category_value_guess = category_guess->GetValue_guess();
                if (category_value_guess == 0xc && rank_guess != 0) {
                    value_guess += rank_guess;
                }
            }
        }
    }
    if (value_guess > 0xfc && IsSkillClampedTo252_guess(index_guess) != 0) {
        value_guess = 0xfc;
    }
    return value_guess;
}

// True when spell `value_guess` is in the spell book (HasSpell in the earlier sibling decomp).
// FUNCTION: TITANIUM 0x0041AFE5
int DynamicPropertyOwner_guess::HasSpell_guess(int value_guess) {
    int index_guess = 0;
    do {
        if (BaseIndexedProxy_guess()->GetValue_guess(index_guess) == value_guess) {
            return 1;
        }
        ++index_guess;
    } while (index_guess < 0x200);
    return 0;
}

struct RankMaxOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual ItemInstance_guess* Slot05_guess(int index_guess);
    RankOffset_guess* offset_holder_guess;
    int GetMaxRank_guess();
};

struct RankSourceState_guess {
    char padding_0000_guess[0x244];
    char ready_guess;
};

struct RankEntryStats_guess {
    // EXTERNAL: TITANIUM 0x005E1710 RankEntryStats_guess::Acc01_guess
    int Acc01_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E17F0 RankEntryStats_guess::Acc02_guess
    int Acc02_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1B70 RankEntryStats_guess::Acc03_guess
    int Acc03_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E18D0 RankEntryStats_guess::Acc04_guess
    int Acc04_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1C50 RankEntryStats_guess::Acc05_guess
    int Acc05_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E19B0 RankEntryStats_guess::Acc06_guess
    int Acc06_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1A90 RankEntryStats_guess::Acc07_guess
    int Acc07_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1D30 RankEntryStats_guess::Acc08_guess
    int Acc08_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E20B0 RankEntryStats_guess::Acc09_guess
    int Acc09_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1E10 RankEntryStats_guess::Acc10_guess
    int Acc10_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1EF0 RankEntryStats_guess::Acc11_guess
    int Acc11_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1FD0 RankEntryStats_guess::Acc12_guess
    int Acc12_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2190 RankEntryStats_guess::Acc13_guess
    int Acc13_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2270 RankEntryStats_guess::Acc14_guess
    int Acc14_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1200 RankEntryStats_guess::Acc15_guess
    int Acc15_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2B30 RankEntryStats_guess::Acc16_guess
    int Acc16_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2430 RankEntryStats_guess::Acc17_guess
    int Acc17_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2510 RankEntryStats_guess::Acc18_guess
    int Acc18_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E25F0 RankEntryStats_guess::Acc19_guess
    int Acc19_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E26D0 RankEntryStats_guess::Acc20_guess
    int Acc20_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E27A0 RankEntryStats_guess::Acc21_guess
    int Acc21_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2880 RankEntryStats_guess::Acc22_guess
    int Acc22_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2960 RankEntryStats_guess::Acc23_guess
    int Acc23_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2A40 RankEntryStats_guess::Acc24_guess
    int Acc24_guess(int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2C10 RankEntryStats_guess::Acc25_guess
    int Acc25_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2CF0 RankEntryStats_guess::Acc26_guess
    int Acc26_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2DD0 RankEntryStats_guess::Acc27_guess
    int Acc27_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2EB0 RankEntryStats_guess::Acc28_guess
    int Acc28_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E3080 RankEntryStats_guess::Acc29_guess
    int Acc29_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E14C0 RankEntryStats_guess::Acc30_guess
    int Acc30_guess(int flag_guess);
};

struct RankSummaryOwner_guess {
    int unused_guess;
    RankOffset_guess* offset_holder_guess;
    RankSourceState_guess* source_guess;
    char padding_000c_guess[4];
    int value_0010_guess;
    int value_0014_guess;
    int value_0018_guess;
    int value_001c_guess;
    int value_0020_guess;
    int value_0024_guess;
    int value_0028_guess;
    char padding_002c_guess[4];
    int value_0030_guess;
    int value_0034_guess;
    int value_0038_guess;
    int value_003c_guess;
    int value_0040_guess;
    char padding_0044_guess[0xc];
    int value_0050_guess;
    int value_0054_guess;
    int value_0058_guess;
    int value_005c_guess;
    int value_0060_guess;
    int value_0064_guess;
    int value_0068_guess;
    int value_006c_guess;
    int value_0070_guess;
    int value_0074_guess;
    int value_0078_guess;
    int value_007c_guess;
    int value_0080_guess;
    int value_0084_guess;
    int value_0088_guess;
    int value_008c_guess;
    int value_0090_guess;
    int value_0094_guess;
    int value_0098_guess;
    char padding_009c_guess[4];
    int value_00a0_guess;
    InventorySlots_guess* Table_guess() {
        return reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    }
    void Accumulate_guess(int value_guess);
};

struct LookupGate_guess {
    int unused_guess;
    RankOffset_guess* offset_holder_guess;
    LookupGateState_guess* state_guess;
    // EXTERNAL: TITANIUM 0x004184F4 LookupGate_guess::InnateSkillLevel_guess
    int InnateSkillLevel_guess(unsigned char mode_guess, int database_string_id_guess);
    int HasSkill_guess(unsigned char mode_guess);
    int HasSkillChecked_guess(unsigned char mode_guess);
};

// Whether this character has skill `mode_guess` (< 100; HasSkill in the earlier sibling decomp). Tinkering is
// Gnome-only; NPCs and GetStatus_guess != 0 use the raw skill. Otherwise the 0x851200 skill table decides: from the
// level the class learns it (effective level as in Skill_guess) the answer is at least 1; else only learned
// points or the racial innate level (InnateSkillLevel_guess) count.
// FUNCTION: TITANIUM 0x0041B0DE
// @early-stop: budget, structural ndiff=128
int LookupGate_guess::HasSkill_guess(unsigned char mode_guess) {
    if (mode_guess >= 100) {
        return 0;
    }

    if (mode_guess == 0x39 &&
        reinterpret_cast<LookupStatusObject_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->lookup_guess.Find_guess()->database_string_id_guess != 0xc) {
        return 0;
    }

    if (state_guess != 0 && state_guess->state_guess == 1) {
        return reinterpret_cast<LookupStatusObject_guess*>(
                   reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
            ->GetSkill_guess(mode_guess);
    }
    if (reinterpret_cast<LookupStatusObject_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
            ->GetStatus_guess() != 0) {
        return reinterpret_cast<LookupStatusObject_guess*>(
                   reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
            ->GetSkill_guess(mode_guess);
    }

    int limit_guess = reinterpret_cast<LookupStatusObject_guess*>(
                          reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                          ->lookup_guess.Find_guess()->level_11a4_guess;
    if (state_guess != 0 && state_guess->state_guess == 0) {
        LookupCurrentValue_guess* current_object_guess =
            reinterpret_cast<LookupStatusObject_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetCurrentObject_guess();
        int current_limit_guess = reinterpret_cast<LookupStatusObject_guess*>(
                                     reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                     ->lookup_guess.Find_guess()->level_11a4_guess;
        int current_guess = static_cast<int>(current_object_guess->GetValue_guess());
        if (current_limit_guess < current_guess) {
            current_limit_guess = reinterpret_cast<LookupStatusObject_guess*>(
                                      reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                      ->lookup_guess.Find_guess()->level_11a4_guess;
            current_guess = static_cast<int>(current_object_guess->GetValue_guess());
            if (current_guess < current_limit_guess + 2) {
                limit_guess = current_object_guess->GetValue_guess();
            } else {
                limit_guess = reinterpret_cast<LookupStatusObject_guess*>(
                                  reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                  ->lookup_guess.Find_guess()->level_11a4_guess + 2;
            }
        }
    }

    LookupStatusObject_guess* status_object_guess = reinterpret_cast<LookupStatusObject_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    LookupResult_guess* check_result_guess = status_object_guess->lookup_guess.Find_guess();
    int result_guess = InnateSkillLevel_guess(mode_guess, check_result_guess->database_string_id_guess);
    LookupResult_guess* state_result_guess = status_object_guess->lookup_guess.Find_guess();
    unsigned char state_value_guess = state_result_guess->state_guess;
    LookupCategory_guess* category_guess = EQ_ARRAY(LookupCategory_guess*, 0x00851200)[mode_guess];
    if (category_guess->IsEnabled_guess(state_value_guess) == 0) {
        return result_guess;
    }
    if (reinterpret_cast<LookupStatusObject_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetSkill_guess(mode_guess) == 0 &&
        category_guess->GetModeCount_guess(status_object_guess->lookup_guess.Find_guess()->state_guess) > 1) {
        return result_guess;
    }

    int mode_count_guess = category_guess->GetModeCount_guess(
        status_object_guess->lookup_guess.Find_guess()->state_guess);
    if (limit_guess < mode_count_guess) {
        if (reinterpret_cast<LookupStatusObject_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetSkill_guess(mode_guess) < 1) {
            result_guess = 0;
        }
    } else if (reinterpret_cast<LookupStatusObject_guess*>(
                   reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                   ->GetSkill_guess(mode_guess) < 1) {
        result_guess = 1;
    } else {
        result_guess = reinterpret_cast<LookupStatusObject_guess*>(
                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                           ->GetSkill_guess(mode_guess);
    }
    return result_guess;
}

// Defense AC (compute_defense in the earlier sibling decomp): GetSkill_guess (agility) + Defense skill * 400/225
// + the +0x68 field; a player's intoxication (half of it above 0x641080) scales it down. At least 1.
// FUNCTION: TITANIUM 0x0041B016
int CostOwner_guess::compute_defense_guess() {
    if (this == 0 || pSpawn_0008_guess == 0) {
        return 0;
    }
    int kind_guess = Skill_guess(0xf);
    if (kind_guess < 0) {
        kind_guess = 0;
    }
    int result_guess = defense_agility_bonus_guess() + kind_guess * 400 / 225 + value_0068_guess;
    if (pSpawn_0008_guess->state_guess == 0) {
        CostCandidate_guess* candidate_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->base_guess.GetCandidate_guess();
        int half_guess = candidate_guess->GetValue_guess() / 2;
        if (static_cast<double>(half_guess) > EQ_GLOBAL(double, 0x00641080)) {
            double factor_guess = (EQ_GLOBAL(double, 0x00641078) - static_cast<double>(half_guess)) *
                                  EQ_GLOBAL(double, 0x00640fa0);
            if (factor_guess > EQ_GLOBAL(double, 0x00640e40)) {
                factor_guess = 1.0;
            }
            result_guess = static_cast<int>(static_cast<double>(result_guess) * factor_guess);
        }
    }
    if (result_guess < 1) {
        result_guess = 1;
    }
    return result_guess;
}

// Best 0x5E2F90 value (probably haste) over worn slots 0-20, five more item slots and the two the slot-5
// virtual gives, capped at 100 (10 below level 26); returned + 100, or 0 when there is none.
// FUNCTION: TITANIUM 0x0041B30D
int RankMaxOwner_guess::GetMaxRank_guess() {
    int limit_guess = 100;
    int max_guess = 0;
    int zero_guess = 0;
    LookupStatusObject_guess* status_guess = reinterpret_cast<LookupStatusObject_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    LookupResult_guess* result_guess = status_guess->lookup_guess.Find_guess();
    if (result_guess->level_11a4_guess < 0x1a) {
        limit_guess = 10;
    }
    for (int index_guess = 0; index_guess < 0x15; ++index_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->GetRankFor_guess(1, zero_guess) > max_guess) {
                max_guess = reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->GetRankFor_guess(1, zero_guess);
            }
        }
    }
    for (int index_guess = 0; index_guess < 5; ++index_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetSmallEntry_guess(index_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetSmallEntry_guess(index_guess)
                    ->GetItemClass_guess() == 0) {
                if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetSmallEntry_guess(index_guess)
                                    ->GetRankFor_guess(1, zero_guess) > max_guess) {
                    max_guess = reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetSmallEntry_guess(index_guess)
                                    ->GetRankFor_guess(1, zero_guess);
                }
            }
        }
    }
    for (int slot_guess = zero_guess; slot_guess < 2; ++slot_guess) {
        ItemInstance_guess* entry_guess = Slot05_guess(slot_guess);
        if (entry_guess != reinterpret_cast<ItemInstance_guess*>(zero_guess)) {
            if (entry_guess->GetItemClass_guess() == 0) {
                if (entry_guess->GetRankFor_guess(1, zero_guess) > max_guess) {
                    max_guess = entry_guess->GetRankFor_guess(1, zero_guess);
                }
            }
        }
    }
    if (max_guess > limit_guess) {
        max_guess = limit_guess;
    }
    if (max_guess != zero_guess) {
        return max_guess + 100;
    }
    return 0;
}

struct CostCandidateStatus_guess {
    char padding_0000_guess[8];
    // EXTERNAL: TITANIUM 0x0040E934 CostCandidateStatus_guess::FindBuffWithEffect_guess
    int FindBuffWithEffect_guess(int id_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x00411F2F CostCandidateStatus_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(int message_guess);
};

struct CostCandidateRequestTail_guess {
    char padding_0000_guess[0x15c];
    int ready_guess;
};

struct CostCandidateRequest_guess {
    char padding_0000_guess[0x1a8];
    CostCandidateRequestTail_guess* tail_guess;
};

struct CostCandidateRuntimePrefix_guess {
    char padding_0000_guess[8];
};

struct CostCandidateRuntime_guess : CostCandidateRuntimePrefix_guess, virtual CostDynamicFindBlock_guess {
    char padding_000c_guess[0xc274];
    CostCandidateStatus_guess status_guess;
    CostCandidateRequest_guess* request_guess;
    unsigned char ready_guess;
};

struct CostLookupValue_guess {
    char padding_0000_guess[0x1078];
    int value_guess;
};

struct CostThresholdRuntime_guess {
    char padding_0000_guess[0x88];
    int counter_guess;
    int unused_008c_guess;
    int count_guess;
    float factor_guess;
};

struct CostEntityRuntime_guess {
    char padding_0000_guess[0x3c];
    float minimum_guess;
    float maximum_guess;
};

struct CostScaleValue_guess {
    char padding_0000_guess[0x40];
    float value_guess;
};

struct CostUIController_guess {
    // EXTERNAL: TITANIUM 0x00438FC2 CostUIController_guess::SetShortTimer_guess
    void SetShortTimer_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00438FDF CostUIController_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x004392DE CostUIController_guess::Reset_guess
    void Reset_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00440F51 CostUIController_guess::Apply_guess
    void Apply_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x004649B1 UpdateCostMessage_guess
void __cdecl UpdateCostMessage_guess(CostCandidateStatus_guess* status_guess,
                                     int message_id_guess,
                                     int message_type_guess,
                                     int zero_guess);

#define g_costUIController_guess EQ_GLOBAL(CostUIController_guess*, 0x00905D24)
#define g_cameras_guess EQ_ARRAY(CostScaleValue_guess*, 0x009254FC)

// One sobering tick: intoxication (0x5ED550) drops by 1; at or above Alcohol Tolerance/2 + 50 (max 150) it
// prints string 0x2374. Under 40 the drunk effect (+0x1A8 -> +0x88..+0x94) stops; above it it grows with
// intoxication; above 69 0x440F51 runs (probably a blur); from 100 spawn +0x3C/+0x40 are kept nonzero.
// FUNCTION: TITANIUM 0x0041B46C
// @early-stop: budget, structural ndiff=61
void CostOwner_guess::ProcessDrunkenness_guess() {
    CostDynamicFindBlock_guess* dynamic_guess = reinterpret_cast<CostDynamicFindBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    CostCandidate_guess* candidate_guess = dynamic_guess->base_guess.GetCandidate_guess();
    CostCandidateRuntime_guess* candidate_runtime_guess =
        reinterpret_cast<CostCandidateRuntime_guess*>(candidate_guess);

    if (candidate_guess != 0 && candidate_runtime_guess->request_guess != 0) {
        if (candidate_guess->GetValue_guess() > 0) {
            candidate_guess->SetValue_guess(candidate_guess->GetValue_guess() - 1);
            candidate_runtime_guess->ready_guess = 1;

            CostCandidateRequestTail_guess* request_tail_guess =
                candidate_runtime_guess->request_guess->tail_guess;
            if (request_tail_guess != 0 && request_tail_guess->ready_guess != 0) {
                int limit_guess;
                CostLookupValue_guess* lookup_value_guess = reinterpret_cast<CostLookupValue_guess*>(
                    candidate_runtime_guess->lookup_guess.Find_guess());
                limit_guess = lookup_value_guess->value_guess / 2 + 0x32;
                if (limit_guess > 0x96) {
                    limit_guess = 0x96;
                } else {
                    lookup_value_guess = reinterpret_cast<CostLookupValue_guess*>(
                        candidate_runtime_guess->lookup_guess.Find_guess());
                    limit_guess = lookup_value_guess->value_guess / 2 + 0x32;
                }
                if (candidate_guess->GetValue_guess() >= limit_guess) {
                    UpdateCostMessage_guess(&candidate_runtime_guess->status_guess,
                                            0x2374,
                                            0xd,
                                            (candidate_runtime_guess->status_guess.RemovePCAffect_guess(
                                                 candidate_runtime_guess->status_guess.FindBuffWithEffect_guess(0x71, 0)),
                                             0));
                }
            }

            CostThresholdRuntime_guess* threshold_guess =
                reinterpret_cast<CostThresholdRuntime_guess*>(pSpawn_0008_guess->threshold_guess);
            if (candidate_guess->GetValue_guess() < 0x28) {
                threshold_guess->counter_guess = -1;
                threshold_guess->factor_guess = 0.35f;
                threshold_guess->count_guess = 1;
                g_costUIController_guess->Clear_guess();
            } else {
                if (threshold_guess->counter_guess == -1) {
                    threshold_guess->counter_guess = 0;
                }
                threshold_guess->factor_guess =
                    static_cast<float>(candidate_guess->GetValue_guess() >> 2) * 0.01f + 0.35f;
                threshold_guess->count_guess = (candidate_guess->GetValue_guess() >> 3) + 1;
                g_costUIController_guess->SetShortTimer_guess(0x17);
            }
        }

        if (candidate_guess->GetValue_guess() > 0x45) {
            g_costUIController_guess->Reset_guess(0);
            float scale_guess =
                g_cameras_guess[EQ_GLOBAL(int, 0x00850CCC)]->value_guess;
            int value_guess = candidate_guess->GetValue_guess();
            g_costUIController_guess->Apply_guess(value_guess - 0x46 + static_cast<int>(scale_guess));
        }

        if (candidate_guess->GetValue_guess() > 99) {
            CostEntityRuntime_guess* entity_runtime_guess =
                reinterpret_cast<CostEntityRuntime_guess*>(pSpawn_0008_guess);
            if (entity_runtime_guess->minimum_guess == 0.0f) {
                entity_runtime_guess->minimum_guess = 0.001f;
            }
            if (entity_runtime_guess->maximum_guess == 0.0f) {
                entity_runtime_guess->maximum_guess = 0.001f;
            }
        }
    }
}

// Adds one item's stat bonuses to this summary: the first item of type `value_guess` (0x5ECC00) in general
// slots 22-29 or in a bag there, skipped for an NPC (+0x244 = 1). The last nine sums are the skill mods
// for the SlotIndexMapper_guess skills, Bash to Frenzy.
// FUNCTION: TITANIUM 0x0041B6B7
void RankSummaryOwner_guess::Accumulate_guess(int value_guess) {
    RankEntryStats_guess* entry_guess = 0;
    bool found_guess = false;
    if (source_guess == 0 || source_guess->ready_guess != 1) {
        for (int slot_guess = InvSlot_General1; slot_guess <= InvSlot_General8; ++slot_guess) {
            if (found_guess) {
                break;
            }
            if (Table_guess()->GetEntry_guess(slot_guess) != 0 &&
                Table_guess()->GetEntry_guess(slot_guess)->GetItemClass_guess() == 0) {
                if (Table_guess()->GetEntry_guess(slot_guess)->GetValue_guess() == value_guess) {
                    entry_guess = reinterpret_cast<RankEntryStats_guess*>(Table_guess()->GetEntry_guess(slot_guess));
                    found_guess = true;
                    break;
                }
            } else if (Table_guess()->GetEntry_guess(slot_guess) != 0 &&
                       Table_guess()->GetEntry_guess(slot_guess)->GetItemClass_guess() == 1) {
                int index_guess = 0;
                if (Table_guess()->GetEntry_guess(slot_guess)->GetCount_guess() > 0) {
                    do {
                        if (Table_guess()->GetEntry_guess(slot_guess)->GetEntry_guess(index_guess) != 0 &&
                            Table_guess()->GetEntry_guess(slot_guess)->GetEntry_guess(index_guess)->GetItemClass_guess() == 0 &&
                            Table_guess()->GetEntry_guess(slot_guess)->GetEntry_guess(index_guess)->GetValue_guess() ==
                                value_guess) {
                            entry_guess = reinterpret_cast<RankEntryStats_guess*>(
                                Table_guess()->GetEntry_guess(slot_guess)->GetEntry_guess(index_guess));
                            found_guess = true;
                            break;
                        }
                        ++index_guess;
                    } while (index_guess < Table_guess()->GetEntry_guess(slot_guess)->GetCount_guess());
                }
            }
        }
    }
    if (found_guess) {
        if (entry_guess != 0) {
            value_0010_guess += entry_guess->Acc01_guess(0);
            value_0014_guess += entry_guess->Acc02_guess(0);
            value_0018_guess += entry_guess->Acc03_guess(0);
            value_001c_guess += entry_guess->Acc04_guess(0);
            value_0020_guess += entry_guess->Acc05_guess(0);
            value_0024_guess += entry_guess->Acc06_guess(0);
            value_0028_guess += entry_guess->Acc07_guess(0);
            value_0030_guess += entry_guess->Acc08_guess(0);
            value_0034_guess += entry_guess->Acc09_guess(0);
            value_0038_guess += entry_guess->Acc10_guess(0);
            value_003c_guess += entry_guess->Acc11_guess(0);
            value_0040_guess += entry_guess->Acc12_guess(0);
            value_0050_guess += entry_guess->Acc13_guess(0);
            value_0054_guess += entry_guess->Acc14_guess(0);
            value_0058_guess += entry_guess->Acc15_guess(0);
            value_005c_guess += entry_guess->Acc16_guess(0);
            value_0060_guess += entry_guess->Acc17_guess(1);
            value_0064_guess += entry_guess->Acc18_guess(1);
            value_0068_guess += entry_guess->Acc19_guess(1);
            value_006c_guess += entry_guess->Acc20_guess(1);
            value_00a0_guess += entry_guess->Acc21_guess(1);
            value_0070_guess += entry_guess->Acc22_guess(1);
            value_0074_guess += entry_guess->Acc23_guess(1);
            value_0078_guess += entry_guess->Acc24_guess(10, 1);
            value_007c_guess += entry_guess->Acc24_guess(8, 1);
            value_0080_guess += entry_guess->Acc24_guess(0x15, 1);
            value_0084_guess += entry_guess->Acc24_guess(0x17, 1);
            value_0088_guess += entry_guess->Acc24_guess(0x1a, 1);
            value_008c_guess += entry_guess->Acc24_guess(0x1e, 1);
            value_0090_guess += entry_guess->Acc24_guess(0x26, 1);
            value_0094_guess += entry_guess->Acc24_guess(0x34, 1);
            value_0098_guess += entry_guess->Acc24_guess(0x4a, 1);
        }
    }
}

struct LabelBuilder_guess {
    // EXTERNAL: TITANIUM 0x00419631 LabelBuilder_guess::KunarkClass_guess
    const char* KunarkClass_guess(int first_guess, int second_guess, int third_guess, int flag_guess);
    char* BuildLabel_guess(int first_guess, int second_guess, int third_guess);
};

// Class title and name for level `second_guess`: above 50 the title, then the name between the strings at
// 0x64109C and 0x641098 (probably " (" and ")"); else the name alone. Static buffer 0x79DB48.
// FUNCTION: TITANIUM 0x0041BF2B
char* LabelBuilder_guess::BuildLabel_guess(int first_guess, int second_guess, int third_guess) {
    char* buf_guess = EQ_ARRAY(char, 0x0079DB48);
    strcpy(buf_guess, KunarkClass_guess(first_guess, second_guess, third_guess, 0));
    if (second_guess > 0x32) {
        strcat(buf_guess, EQ_ARRAY(char, 0x0064109C));
        strcat(buf_guess, KunarkClass_guess(first_guess, second_guess, third_guess, 1));
        strcat(buf_guess, EQ_ARRAY(char, 0x00641098));
    }
    return buf_guess;
}

#define g_classTable_guess EQ_GLOBAL(int*, 0x00851254)

struct ClassResetHead_guess {
    int unused_guess;
};

struct ClassReset_guess : ClassResetHead_guess, virtual IndexedPropertyProxy_guess {
    // EXTERNAL: TITANIUM 0x004184F4 ClassReset_guess::InnateSkillLevel_guess
    int InnateSkillLevel_guess(int skill_guess, int class_guess);
    void InitInnates_guess(unsigned int class_guess, unsigned int kind_guess);
};

// InitInnates (a Lantern name): clears the 25 innate-ability flags (0xFF = lacks it), then
// grants them by race (`race_guess`) and class (`class_guess`). At level 1 (+0x11a4) racial skills
// start at their cap (Gnome Tinkering, Halfling Sneak and Hide, Iksar Swimming and Forage ...) and the
// class's first weapon skill at 5 (+0xF70 is the skill array). Innates used elsewhere: 5 Harm Touch,
// 6 infravision, 7 Lay on Hands, 10 regeneration, 11 Slam, 13 ultravision. Iksar also patch three entries
// of 0x851254.
// FUNCTION: TITANIUM 0x0041BF92
// @early-stop: budget, structural ndiff=89
void ClassReset_guess::InitInnates_guess(unsigned int race_guess, unsigned int class_guess) {
    for (int i = 0; i < 25; ++i) {
        Write1100_guess(i, 0xff);
    }
    Data_guess()->values1100_guess[14] = 0;
    Data_guess()->values1100_guess[15] = 0;
    if (race_guess == 0x80 || Data_guess()->database_string_id_guess == 0x80) {
        g_classTable_guess[0] = 0x3664;
        g_classTable_guess[0x4d] = 0x6c;
        g_classTable_guess[0x4e] = 0x6d;
    } else {
        g_classTable_guess[0] = 0x363a;
        g_classTable_guess[0x4d] = 0x8a;
        g_classTable_guess[0x4e] = 0x8b;
    }
    // By race: several race ids share a case, and the cases fall through to collect shared innates;
    // level-1 racial skills start at their cap.
    switch (race_guess) {
    case 7:
    case 8:
    case 0x5e:
        Data_guess()->values1100_guess[6] = 0;
        break;
    case 0x1b:
    case 0x20:
    case 0x21:
    case 0x3c:
    case 0x41:
    case 0x45:
    case 0x46:
    case 0x55:
    case 0x75:
    case 0x76:
    case 0x7a:
    case 0x7b:
    case 0x16f:
        Data_guess()->values1100_guess[13] = 0;
        break;
    case 0xc:
        Data_guess()->values1100_guess[6] = 0;
        Data_guess()->values1100_guess[8] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x39, InnateSkillLevel_guess(0x39, race_guess));
        }
        break;
    case 2:
    case 0x5a:
        Data_guess()->values1100_guess[11] = 0;
        break;
    case 0xb:
    case 0x51:
        Data_guess()->values1100_guess[6] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x2a, InnateSkillLevel_guess(0x2a, race_guess));
            SetValue_guess(0x1d, InnateSkillLevel_guess(0x1d, race_guess));
        }
        break;
    case 9:
    case 0x5c:
        Data_guess()->values1100_guess[10] = 0;
        Data_guess()->values1100_guess[11] = 0;
        Data_guess()->values1100_guess[6] = 0;
        break;
    case 4:
    case 0x70:
        Data_guess()->values1100_guess[6] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x1b, InnateSkillLevel_guess(0x1b, race_guess));
            SetValue_guess(0x1d, InnateSkillLevel_guess(0x1d, race_guess));
        }
        break;
    case 5:
    case 0x6a:
        Data_guess()->values1100_guess[6] = 0;
    case 3:
    case 0x4e:
        Data_guess()->values1100_guess[8] = 0;
        break;
    case 6:
    case 0x4d:
    case 0x62:
        Data_guess()->values1100_guess[13] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x1d, InnateSkillLevel_guess(0x1d, race_guess));
        }
        break;
    case 10:
    case 0x5d:
        Data_guess()->values1100_guess[6] = 0;
        Data_guess()->values1100_guess[11] = 0;
        Data_guess()->values1100_guess[9] = 0;
        Data_guess()->values1100_guess[2] = 0;
        break;
    case 0x14a:
        Data_guess()->values1100_guess[13] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x32, InnateSkillLevel_guess(0x32, race_guess));
        }
        break;
    case 0x82:
        Data_guess()->values1100_guess[6] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x2a, InnateSkillLevel_guess(0x2a, race_guess));
            SetValue_guess(0x27, InnateSkillLevel_guess(0x27, race_guess));
        }
        break;
    case 0x80:
        Data_guess()->values1100_guess[10] = 0;
        Data_guess()->values1100_guess[6] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            SetValue_guess(0x32, InnateSkillLevel_guess(0x32, race_guess));
            SetValue_guess(0x1b, InnateSkillLevel_guess(0x1b, race_guess));
        }
        break;
    case 1:
    case 0x2c:
    case 0x37:
    case 0x43:
    case 0x47:
        break;
    default:
        Data_guess()->values1100_guess[6] = 0;
        break;
    }
    // By class (1-16): class innates, and at level 1 the starting skills.
    switch (class_guess) {
    case 3:
        Data_guess()->values1100_guess[7] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[1] = 5;
        }
        break;
    case 5:
        Data_guess()->values1100_guess[5] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[1] = 5;
        }
        break;
    case 6:
        Data_guess()->values1100_guess[4] = 0;
    case 2:
    case 10:
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[0] = 5;
        }
        break;
    case 9:
        Data_guess()->values1100_guess[12] = 0;
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[0x24] = 5;
        }
        break;
    case 4:
        Data_guess()->values1100_guess[1] = 0;
    case 1:
    case 8:
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[1] = 5;
        }
        break;
    case 7:
        Data_guess()->values1100_guess[12] = 0;
        Data_guess()->values1100_guess[1] = 0;
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[0x1c] = 5;
        }
        break;
    case 0x10:
        if (Data_guess()->level_11a4_guess == 1) {
            Data_guess()->values_f70_guess[3] = 5;
            Data_guess()->values_f70_guess[0x33] = 5;
        }
        break;
    }
}

struct QueryMode_guess {
    // EXTERNAL: TITANIUM 0x005E04C0 QueryMode_guess::GetRecommendedLevel_guess
    int GetRecommendedLevel_guess(int mode_guess);
    // EXTERNAL: TITANIUM 0x005E0AA0 QueryMode_guess::GetInputLimit_guess
    int GetInputLimit_guess(int mode_guess);
};

// EXTERNAL: TITANIUM 0x0060FAC0 SetRoundedValue_guess
void __cdecl SetRoundedValue_guess(double value_guess);

// EXTERNAL: TITANIUM 0x0060E98C GetRoundedValue_guess
int __cdecl GetRoundedValue_guess();

// Scales an item stat for a wearer below the item's level: value * level / the item's level (probably the
// recommended level), rounded, at least 1. Items without one compare the wearer's skill `index_guess` with
// the item's skill instead. NPCs (type_0244_guess 1) get the full value. Also declared, in this file, as
// CostTotalOwner_guess::ApplyRank_guess.
// FUNCTION: TITANIUM 0x0041C7C1
// @early-stop: budget, structural ndiff=31
int DynamicPropertyOwner_guess::CalculateScaledValue_guess(QueryMode_guess* mode_guess, int value_guess, int index_guess) {
    int result_guess = value_guess;
    if (input_guess == 0 || mode_guess == 0) {
        return result_guess;
    }
    if (result_guess <= 0) {
        return result_guess;
    }
    int one_guess = 1;
    if (input_guess->type_0244_guess != one_guess) {
            float ratio_guess;
            int use_fallback_guess = 1;
            if (mode_guess->GetRecommendedLevel_guess(one_guess) != 0) {
                int found_value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                            ->FindResult_guess()->level_11a4_guess;
                int current_limit_guess = mode_guess->GetRecommendedLevel_guess(one_guess);
                if (found_value_guess < current_limit_guess) {
                    int ratio_numerator_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                    ->FindResult_guess()->level_11a4_guess;
                    ratio_guess = static_cast<float>(ratio_numerator_guess) /
                                  static_cast<float>(mode_guess->GetRecommendedLevel_guess(one_guess));
                    use_fallback_guess = 0;
                }
            }
            if (use_fallback_guess != 0) {
                if (mode_guess->GetInputLimit_guess(one_guess) == 0) {
                    return result_guess;
                }
                if (reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(index_guess) >=
                    mode_guess->GetInputLimit_guess(one_guess)) {
                    return result_guess;
                }
                int property_value_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                               ->GetSkill_guess(index_guess);
                if (property_value_guess < 1) {
                    property_value_guess = 1;
                }
                ratio_guess = static_cast<float>(property_value_guess) /
                              static_cast<float>(mode_guess->GetInputLimit_guess(one_guess));
            }

            SetRoundedValue_guess(static_cast<double>(static_cast<float>(result_guess) * ratio_guess + 0.5f));
            result_guess = GetRoundedValue_guess();
            if (result_guess < 1) {
                result_guess = 1;
            }
            return result_guess;
    }
    return value_guess;
}

// HasSkill: ids 100 and up are abilities, not skills, and always read false.
// FUNCTION: TITANIUM 0x0041C8F4
int LookupGate_guess::HasSkillChecked_guess(unsigned char mode_guess) {
    int result_guess = 0;
    if (mode_guess < 100) {
        result_guess = HasSkill_guess(mode_guess);
    }
    return result_guess;
}

#pragma pack(push, 1)
struct DamageRecord_guess {
    unsigned short target_guess;
    unsigned short source_guess;
    char padding_0004_guess[6];
    int value_000a_guess;
    int value_000e_guess;
    int value_0012_guess;
    unsigned char type_guess;
    char padding_0017_guess[4];
    short spell_guess;
    char padding_001d_guess;
    unsigned char flags_guess;
};

struct DamageAdjustment_guess {
    unsigned short target_guess;
    unsigned short source_guess;
    unsigned short value_0004_guess;
    int damage_0006_guess;
    float value_000a_guess;
    float value_000e_guess;
    float value_0012_guess;
    unsigned char type_guess;
    int value_0017_guess;
    short spell_guess;
    char value_001d_guess;
    unsigned char flags_guess;
};

struct DamageCharInfoView_guess {
    char padding_0000_guess[0x100c];
    int value_100c_guess;
};

struct DamagePacket_guess {
    unsigned short target_guess;
    unsigned short source_guess;
    unsigned char type_guess;
    short spell_guess;
    int damage_guess;
    int value_000a_guess;
    int value_000e_guess;
    int value_0012_guess;
};
#pragma pack(pop)

struct DamageBuff_guess {
    int unused_guess;
    int spell_guess;
    int unused_0008_guess;
    int counter_guess;
};

struct DamageTarget_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
};

struct DamageSpell_guess {
    char padding_0000_guess[0x30];
    BoundedArray_guess<int, 12> base_guess;
    BoundedArray_guess<int, 12> max_guess;
    char padding_0090_guess[0x90];
    BoundedArray_guess<int, 12> attrib_guess;
    // EXTERNAL: TITANIUM 0x0044E77B DamageSpell_guess::FindAffectSlot_guess
    unsigned char FindAffectSlot_guess(int attrib_guess);
};

struct DamageSpellManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 DamageSpellManager_guess::GetSpell_guess
    DamageSpell_guess* GetSpell_guess(int id_guess);
};

struct DamagePcPrefix_guess {
    char padding_0000_guess[0xc280];
};

struct DamagePc_guess : DamagePcPrefix_guess, CostOwner_guess {
};

struct DamageDispatch_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void OnDeath_guess(DamageRecord_guess* record_guess, int damage_guess);
};

// EXTERNAL: TITANIUM 0x00401B28 GetSpawn_guess
CostEntity_guess* __cdecl GetSpawn_guess(unsigned int id_guess);
// EXTERNAL: TITANIUM 0x00465750 IsWeaponAttackDamageType_guess
int __cdecl IsWeaponAttackDamageType_guess(DamageRecord_guess* record_guess);
// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpell_guess
char __cdecl IsValidSpell_guess(int spell_guess);
// EXTERNAL: TITANIUM 0x0060F81E Abs_guess
int __cdecl Abs_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
char* __cdecl FormatText_guess(char* out_guess, int id_guess, const char* a1, const char* a2, const char* a3,
                               const char* a4, const char* a5, const char* a6, const char* a7, const char* a8,
                               const char* a9);
struct HitReporter_guess {
    // EXTERNAL: TITANIUM 0x004A56E3 HitReporter_guess::ReportSuccessfulHit_guess
    void ReportSuccessfulHit_guess(DamagePacket_guess* packet_guess, unsigned char first_guess, int second_guess);
};
#define g_hitReporter_guess EQ_GLOBAL(HitReporter_guess*, 0x00988DF0)

#define g_damageSpellManager_guess EQ_GLOBAL(DamageSpellManager_guess*, 0x00985CC8)
#define g_damagePc_guess EQ_GLOBAL(DamagePc_guess*, 0x00905D00)
#define g_damageCaster_guess EQ_GLOBAL(CostEntity_guess*, 0x00905D04)
#define g_lastDamageSource_guess EQ_GLOBAL(unsigned int, 0x00923848)
#define g_damageQuiet_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_damageMuted_guess EQ_GLOBAL(int, 0x00923884)
#define DAMAGE_CHARINFO_guess                                                                              \
    (reinterpret_cast<LookupResult_guess*>(                                                                \
        static_cast<CharacterBase_guess*>(reinterpret_cast<CharacterObject_guess*>(this))->GetCharInfo2()))

// Applies one hit to this character; returns the damage taken, -5 when immune (DivineAura, SPA 40, unless
// spell 982 or a Teleport2 spell) and -6 when absorbed. Non-melee hits are announced in chat. Mez (SPA 31)
// breaks; SpinTarget (64) may wear off;
// NegateAttacks (163), Rune (55; AbsorbMagicAtt 78 for spell damage, type 231) and MitigateMeleeDamage
// (162) soak it; then HP, knock-out, death at -10 - DelayDeath (SPA 328; 0 for NPCs) and OP_Damage
// (CombatDamage_Struct, 0x17 bytes). The player's own environmental hits (types 244, 246, 250-253) are
// sent first as OP_EnvDamage. The DamageShield (59) and ReverseDS (121) blocks compute values and drop them.
// Bash (type 10) and level 55+ warrior kicks (30) may stun anyone but Ogres (races 10, 93): 1d100 under
// 55 - the attacker's StunBashChance (SPA 231) only interrupts the cast (80%, Stun_guess(1));
// otherwise FrontalStunResist (293; string 5753), StunResist (195; string 9077) or a 2 s stun.
// FUNCTION: TITANIUM 0x0041C905
// @early-stop: budget, structural ndiff=372
int CostOwner_guess::TakeDamage_guess(int damage_guess, DamageRecord_guess* record_guess, char notify_guess,
                                      int unused4_guess, char mode_guess, int unused6_guess) {
    DamageTarget_guess target_guess;
    DamagePacket_guess packet_guess;
    char text_guess[256];
    int threshold_guess = 0;
    int hp_guess = 0;

    // No damage is processed for a frozen spawn (StandState 0x66), a linkdead one (+0x1B2), one with +0x1B6
    // set, or a character in state 4.
    if (pSpawn_0008_guess == 0 || pSpawn_0008_guess->stand_state_guess == 'f' || pSpawn_0008_guess->linkdead_01b2_guess != 0 ||
        flag_0100_guess[offset_holder_guess->vbaseOffset_0004_guess] == 4 || pSpawn_0008_guess->flag_01b6_guess != 0) {
        return 0;
    }

    CostEntity_guess* attacker_guess = GetSpawn_guess(record_guess->source_guess);
    int spell_guess = record_guess->spell_guess;
    int special_guess = 0;
    if (spell_guess != -1 && g_damageSpellManager_guess->GetSpell_guess(spell_guess)->attrib_guess.data[0] == 0x91) {
        special_guess = 1;
    }
    // Divine Aura (SPA 40) turns the hit into -5 (invulnerable), except for spell 982 (Cazic Touch), spells
    // whose first effect is 145 (Teleport2), and calls with mode 0.
    if (TotalSpellAffects_guess(0x28, 1, 0, 1) > 0 && spell_guess != 0x3d6 && special_guess == 0 && mode_guess != 0) {
        damage_guess = -5;
    }
    if (pSpawn_0008_guess != 0) {
        if (pSpawn_0008_guess->state_guess == 1) {
            threshold_guess = 0;
        } else {
            // Already dead: NPCs below 0, players below -10 minus DelayDeath (SPA 328).
            threshold_guess = -10 - TotalSpellAffects_guess(0x148, 1, 0, 1);
        }
    }
    if (pSpawn_0008_guess != 0 && Cur_HP(pSpawn_0008_guess->state_guess) < threshold_guess) {
        return 0;
    }
    if (damage_guess <= 0) {
        return damage_guess;
    }

    if (pSpawn_0008_guess != 0 && this == g_damagePc_guess) {
        unsigned char type_guess = record_guess->type_guess;
        if (type_guess == 0xf4 || type_guess == 0xf6 || (type_guess > 0xf9 && type_guess < 0xfe)) {
            // Environmental damage to us (types 0xF4, 0xF6, 0xFA-0xFD) is reported as OP_EnvDamage (0x31B3).
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_EnvDamage, record_guess, 0x1f, 1);
        }
    }

    if (IsWeaponAttackDamageType_guess(record_guess) == 0) {
        // Not a melee skill type (0x00465750 says so): "You were hit by non-melee for %1 damage."
        FormatText_guess(text_guess, 0x30c1, _itoa(damage_guess, EQ_ARRAY(char, 0x0099DB00), 10), 0, 0, 0, 0, 0,
                         0, 0, 0);
        pEverQuest->dsp_chat(text_guess, 0x11b, 1);
    }

    // Any damage breaks mez: every Mez (SPA 31) buff goes.
    DamageBuff_guess* buff_guess = FindBuff_guess(0x1f, 0);
    if (buff_guess != 0) {
        int count_guess = 0;
        do {
            RemovePCAffect_guess(buff_guess);
            buff_guess = FindBuff_guess(0x1f, 0);
        } while (count_guess++ <= GetMaxBuffs_guess() && buff_guess != 0);
    }

    // SpinTarget (SPA 64): any damage ends the spin with chance 1 in N. Spell 303 (Whirl till you hurl): N is
    // 1 above level 39 (the three tests above 49, 44 and 39 all give 1 in the binary), 2 above 30, 12 above
    // 24, else 10. Spell 619 (Dyn`s Dizzying Draught): 20. Others: 10.
    DamageBuff_guess* rune_guess = FindBuff_guess(0x40, 0);
    if (rune_guess != 0) {
        int chance_guess = 10;
        if (rune_guess->spell_guess == 0x12f) {
            if (DAMAGE_CHARINFO_guess->level_11a4_guess > 0x31 || DAMAGE_CHARINFO_guess->level_11a4_guess > 0x2c ||
                DAMAGE_CHARINFO_guess->level_11a4_guess > 0x27) {
                chance_guess = 1;
            } else if (DAMAGE_CHARINFO_guess->level_11a4_guess > 0x1e) {
                chance_guess = 2;
            } else if (DAMAGE_CHARINFO_guess->level_11a4_guess > 0x18) {
                chance_guess = 12;
            }
        } else if (rune_guess->spell_guess == 0x26b) {
            chance_guess = 20;
        }
        if (RandomRange_guess(0, chance_guess - 1) == 0) {
            RemovePCAffect_guess(rune_guess);
            reinterpret_cast<ResetObject_guess*>(this)->UnStunMe_guess();
        }
    }

    if (record_guess->type_guess != 0xfc && record_guess->type_guess != 0xfb && record_guess->type_guess != 0xfa &&
        mode_guess == 1 && damage_guess < 100000) {
        // NegateAttacks (SPA 163): one charge absorbs the whole hit (-6) when mode is 1, the type is not
        // 0xFA-0xFC and the damage is under 100000.
        DamageBuff_guess* charge_guess = FindBuff_guess(0xa3, 0);
        if (charge_guess != 0) {
            charge_guess->counter_guess--;
            damage_guess = -6;
            if (charge_guess->counter_guess < 1) {
                RemovePCAffect_guess(charge_guess);
            }
        }
    }

    // DamageShield (SPA 59) on a melee hit from someone else (not type 0x33): the client only works out the
    // difference and drops it (as in the binary).
    DamageBuff_guess* reflect_guess = FindBuff_guess(0x3b, 0);
    if (reflect_guess != 0 && record_guess->source_guess > 0 &&
        record_guess->source_guess != pSpawn_0008_guess->spawn_id_guess && IsWeaponAttackDamageType_guess(record_guess) != 0 &&
        record_guess->type_guess != 0x33 && IsValidSpell_guess(reflect_guess->spell_guess) &&
        g_damageSpellManager_guess->GetSpell_guess(reflect_guess->spell_guess) != 0) {
        int diff_guess = TotalSpellAffects_guess(0x3b, 1, 0, 1) - value_00b4_guess;
        if (diff_guess < 0) {
            Abs_guess(diff_guess);
            if (attacker_guess != 0 && (record_guess->flags_guess & 2) != 0 && attacker_guess->owner_guess != 0) {
                // Kept from the server: the damage-shield difference and the attacker's MitigateDamageShield
                // (SPA 305) are computed and thrown away, as in the binary. Nothing is sent or applied here.
                attacker_guess->owner_guess->TotalSpellAffects_guess(0x131, 1, 0, 1);
            }
        }
    }

    if (attacker_guess != 0) {
        CostOwner_guess* owner_guess = attacker_guess->owner_guess;
        if (owner_guess != 0) {
            // ReverseDS (SPA 121) on the attacker: same tests, and its total is also unused.
            DamageBuff_guess* proc_guess = owner_guess->FindBuff_guess(0x79, 0);
            if (proc_guess != 0 && record_guess->source_guess > 0 &&
                record_guess->source_guess != pSpawn_0008_guess->spawn_id_guess &&
                IsWeaponAttackDamageType_guess(record_guess) != 0 && record_guess->type_guess != 0x33 &&
                IsValidSpell_guess(proc_guess->spell_guess) &&
                g_damageSpellManager_guess->GetSpell_guess(proc_guess->spell_guess) != 0 &&
                owner_guess->TotalSpellAffects_guess(0x79, 1, 0, 1) < 0) {
                Abs_guess(owner_guess->TotalSpellAffects_guess(0x79, 1, 0, 1));
            }
        }
    }

    if (record_guess->type_guess != 0xfc && record_guess->type_guess != 0xfb && record_guess->type_guess != 0xfa &&
        mode_guess == 1) {
        // Each rune soaks what it can; a spent one fires its CastOnRuneFadeEffect (SPA 333) spell.
        for (;;) {
            DamageBuff_guess* shield_guess = FindBuff_guess(0x37, 0);
            if (shield_guess == 0 && record_guess->type_guess == 0xe7) {
                // Spell damage (type 0xE7) falls back to AbsorbMagicAtt (SPA 78) when no Rune (SPA 55) buff
                // is left.
                shield_guess = FindBuff_guess(0x4e, 0);
            }
            if (shield_guess == 0 || damage_guess <= 0) {
                break;
            }
            int remaining_guess = shield_guess->counter_guess - damage_guess;
            if (remaining_guess < -0x7fff) {
                remaining_guess = -0x7fff;
            }
            shield_guess->counter_guess = remaining_guess;
            if (remaining_guess < 1) {
                damage_guess = Abs_guess(remaining_guess);
                if (IsValidSpell_guess(shield_guess->spell_guess)) {
                    DamageSpell_guess* spell_data_guess =
                        g_damageSpellManager_guess->GetSpell_guess(shield_guess->spell_guess);
                    if (spell_data_guess != 0) {
                        for (int i = 0; i < 12; i++) {
                            if (spell_data_guess->attrib_guess[i] == 0x14d) {
                                int trigger_guess = spell_data_guess->base_guess[i];
                                if (IsValidSpell_guess(trigger_guess)) {
                                    target_guess.first_guess = 0;
                                    target_guess.second_guess = -1;
                                    target_guess.third_guess = -1;
                                    target_guess.fourth_guess = 0;
                                    g_damageCaster_guess = pSpawn_0008_guess;
                                    ApplySpell_guess(10, trigger_guess, 0, target_guess, 0);
                                }
                            }
                        }
                    }
                }
                RemovePCAffect_guess(shield_guess);
            } else {
                damage_guess = -6;
            }
        }
    }

    // MitigateMeleeDamage (SPA 162) absorbs base percent of a melee hit, at most the spell's max and what is
    // left in the buff's pool.
    if (damage_guess > 0 && TotalSpellAffects_guess(0xa2, 1, 0, 1) != 0 && mode_guess != 0 &&
        record_guess->type_guess != 0xfc && record_guess->type_guess != 0xfb && record_guess->type_guess != 0xfa &&
        record_guess->type_guess != 0xe7 && mode_guess == 1) {
        DamageBuff_guess* ward_guess = FindBuff_guess(0xa2, 0);
        if (ward_guess != 0) {
            DamageSpell_guess* ward_spell_guess = g_damageSpellManager_guess->GetSpell_guess(ward_guess->spell_guess);
            if (ward_spell_guess != 0) {
                int slot_guess = ward_spell_guess->FindAffectSlot_guess(0xa2) - 1;
                int absorbed_guess = Abs_guess(ward_spell_guess->base_guess[slot_guess] * damage_guess / 100);
                if (ward_spell_guess->max_guess[slot_guess] > 0 &&
                    ward_spell_guess->max_guess[slot_guess] < absorbed_guess) {
                    absorbed_guess = ward_spell_guess->max_guess[slot_guess];
                }
                if (ward_guess->counter_guess < absorbed_guess) {
                    absorbed_guess = ward_guess->counter_guess;
                }
                ward_guess->counter_guess -= absorbed_guess;
                if (ward_guess->counter_guess < 1) {
                    RemovePCAffect_guess(ward_guess);
                }
                damage_guess -= absorbed_guess;
                if (damage_guess == 0) {
                    damage_guess = -6;
                }
            }
        }
    }

    // Take the hit off HP unless it was absorbed (-6). For spell damage the attacker is passed along.
    if (damage_guess != -6) {
        reinterpret_cast<CostUpdateView_guess*>(this)->ModifyCurHP_guess(
            -damage_guess, record_guess->type_guess == 0xe7 ? reinterpret_cast<int>(attacker_guess) : 0);
    }

    if (pSpawn_0008_guess != 0) {
        hp_guess = Cur_HP(pSpawn_0008_guess->state_guess);
        pSpawn_0008_guess->updated_value_0274_guess = hp_guess;
        pSpawn_0008_guess->cached_value_guess = Max_HP_guess(pSpawn_0008_guess->state_guess);
    }
    if (hp_guess < 1 && pSpawn_0008_guess != 0 &&
        // At 0 HP or less while still in a state below 3: the spawn's knock-out handler runs (state 3 =
        // unconscious).
        static_cast<char>(flag_0100_guess[offset_holder_guess->vbaseOffset_0004_guess]) < 3) {
        pSpawn_0008_guess->KnockedOut_guess();
    }

    if (hp_guess > 0) {
        int penalty_guess = 0;
        int check_guess = 0;
        if (record_guess->type_guess == 10) {
            if (attacker_guess != 0 && attacker_guess->state_guess == 0 && attacker_guess->owner_guess != 0) {
                penalty_guess = attacker_guess->GetPcClient_guess()->TotalSpellAffects_guess(0xe7, 1, 0, 1);
            }
            check_guess = 1;
        }
        if (attacker_guess != 0 && record_guess->type_guess == 0x1e && attacker_guess->level_guess > 0x36 &&
            attacker_guess->playerClass_0252_guess == 1) {
            check_guess = 1;
        }
        if (check_guess != 0 && DAMAGE_CHARINFO_guess->database_string_id_guess != 10 && attacker_guess != 0 &&
            DAMAGE_CHARINFO_guess->database_string_id_guess != 0x5d) {
            // Stun roll, 1-100. At or below 55 minus the attacker's StunBashChance (and below 99) the blow
            // only interrupts a cast in progress, 8 times in 10, and not spells 859-1023. Above it:
            // FrontalStunResist (SPA 293, "You avoid the stunning blow."), then StunResist (SPA 195) plus
            // +0x70 ("You shake off the stun effect!"), else a 2 s stun.
            int limit_guess = 0x37 - penalty_guess;
            int roll_guess = RandomRange_guess(0, 100);
            if (roll_guess < 1) {
                roll_guess = 1;
            }
            if (roll_guess < 99 && roll_guess <= limit_guess) {
                if (RandomRange_guess(0, 9) > 1) {
                    int stun_guess = pSpawn_0008_guess->threshold_guess->value_0f98_guess;
                    if (stun_guess != -1 && (stun_guess < 0x35b || stun_guess > 0x3ff)) {
                        Stun_guess(1);
                    }
                }
            } else if (TotalSpellAffects_guess(0x125, 1, 0, 1) >= RandomRange_guess(1, 100)) {
                UpdateCostMessage_guess(reinterpret_cast<CostCandidateStatus_guess*>(this), 0x1679, 10, 0);
            } else if (TotalSpellAffects_guess(0xc3, 1, 0, 1) + value_0070_guess > RandomRange_guess(0, 100)) {
                UpdateCostMessage_guess(reinterpret_cast<CostCandidateStatus_guess*>(this), 0x2375, 10, 0);
            } else {
                StunMe_guess(2000, 0, attacker_guess->state_guess == 0);
            }
        }
    }

    // Fatal hits go to the death handler instead of the normal report.
    if (hp_guess <= threshold_guess) {
        reinterpret_cast<DamageDispatch_guess*>(this)->OnDeath_guess(record_guess, damage_guess);
        return damage_guess;
    }
    if (record_guess->source_guess == record_guess->target_guess && pSpawn_0008_guess != 0 &&
        // An NPC's non-spell hit on itself above 5000 is not reported.
        pSpawn_0008_guess->state_guess == 1 && !IsValidSpell_guess(record_guess->spell_guess) && damage_guess > 5000) {
        notify_guess = 0;
    }
    // The hit goes to the zone as OP_Damage (0x5C78, 0x17 bytes) unless muted, and to ReportSuccessfulHit. An
    // NPC's own non-spell hit on itself over 5000 is not reported.
    if (notify_guess != 0) {
        g_lastDamageSource_guess = record_guess->source_guess;
        packet_guess.target_guess = record_guess->target_guess;
        packet_guess.source_guess = record_guess->source_guess;
        packet_guess.type_guess = record_guess->type_guess;
        packet_guess.spell_guess = record_guess->spell_guess;
        packet_guess.damage_guess = damage_guess;
        packet_guess.value_000a_guess = record_guess->value_000a_guess;
        packet_guess.value_000e_guess = record_guess->value_000e_guess;
        packet_guess.value_0012_guess = record_guess->value_0012_guess;
        if (g_damageQuiet_guess == 0 && g_damageMuted_guess == 0) {
            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Damage, &packet_guess, 0x17, 1);
        }
        g_hitReporter_guess->ReportSuccessfulHit_guess(&packet_guess, 1, 0);
    }
    return damage_guess;
}

struct CostStatusService_guess {
    // EXTERNAL: TITANIUM 0x005F6DC0 CostStatusService_guess::Check_guess
    char Check_guess(int value_guess);
};

struct CostRandomLookup_guess {
    int unused_guess;
    LookupService_guess lookup_guess;
};

// Applies the vision SPAs to the innate flags and returns whether SeeInvis (SPA 13) is on: UltraVision (66)
// grants innate 13 and InfraVision (65) innate 6; without the SPA, races lacking the innate lose it again.
// GetRandom_guess is TotalSpellAffects (0x4106A3, misnamed): nothing here is random.
// FUNCTION: TITANIUM 0x0041D3C6
bool CostOwner_guess::CanISeeInvis_guess() {
    bool result_guess = TotalSpellAffects_guess(0xd, 1, 0, 1) > 0;
    if (TotalSpellAffects_guess(0x42, 1, 0, 1) > 0) {
        CostRandomLookup_guess* proxy_guess = reinterpret_cast<CostRandomLookup_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        proxy_guess->lookup_guess.Find_guess()->values1100_guess[13] = 0;
    } else if (pSpawn_0008_guess != 0) {
        if (pSpawn_0008_guess->race_0260_guess != 6 && pSpawn_0008_guess->race_0260_guess != 0x82 &&
            pSpawn_0008_guess->race_0260_guess != 0x14a) {
            CostRandomLookup_guess* proxy_guess = reinterpret_cast<CostRandomLookup_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            proxy_guess->lookup_guess.Find_guess()->values1100_guess[13] = 0xff;
        }
    }
    if (TotalSpellAffects_guess(0x41, 1, 0, 1) > 0) {
        CostRandomLookup_guess* proxy_guess = reinterpret_cast<CostRandomLookup_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        proxy_guess->lookup_guess.Find_guess()->values1100_guess[6] = 0;
    } else if (pSpawn_0008_guess != 0) {
        if (pSpawn_0008_guess->race_0260_guess == 6 || pSpawn_0008_guess->race_0260_guess == 1 ||
            pSpawn_0008_guess->race_0260_guess == 3 || pSpawn_0008_guess->race_0260_guess == 2) {
            CostRandomLookup_guess* proxy_guess = reinterpret_cast<CostRandomLookup_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            proxy_guess->lookup_guess.Find_guess()->values1100_guess[6] = 0xff;
        }
    }
    return result_guess;
}

// Once a second (DoPassageOfTime_guess): damage from the region under the player, through TakeDamage_guess.
// Region types 3 and 7 burn as lava (type 250): 50 minus resist +0x38 / 3, at least 10; some values of the
// spawn's +0x204 raise the base to 100-200, and 200 switches to resist +0x40 and type 244. Types 4 and 8
// deal 50 minus resist +0x34 / 3 (type 246).
// FUNCTION: TITANIUM 0x0041D4BA
// @early-stop: budget, structural ndiff=71
void CostOwner_guess::TakeEnvironmentalDamage_guess() {
    DamageAdjustment_guess event_guess;
    CostEntity_guess* target_guess = pSpawn_0008_guess;
    int damage_guess = 0;
    int type_guess = 0xfa;
    event_guess.flags_guess = 0;
    unsigned char state_guess = target_guess->threshold_guess->state_00ad_guess;

    if (state_guess < 3 || state_guess == 5) {
        return;
    }

    if (state_guess == 3 || state_guess == 7) {
        int index_guess = target_guess->value_0204_guess;
        int amount_guess = value_0038_guess;
        int divisor_guess = 3;
        int minimum_guess = 10;
        damage_guess = 0x32;
        if (index_guess < 0x117) {
            if (index_guess == 0x116) {
                divisor_guess = 5;
                minimum_guess = 0x19;
                damage_guess = 100;
            } else if (index_guess == 0x6c) {
                damage_guess = 200;
            } else if (index_guess == 0xc8) {
                amount_guess = value_0040_guess;
                type_guess = 0xf4;
                damage_guess = 100;
            } else if (index_guess == 0xd4 || index_guess == 0xd9) {
                damage_guess = 200;
            }
        } else if (index_guess == 0x155) {
            damage_guess = 100;
        } else if (index_guess == 0x156) {
            damage_guess = 0x96;
        } else if (index_guess == 0x157) {
            damage_guess = 200;
        }
        damage_guess -= amount_guess / divisor_guess;
        if (damage_guess < minimum_guess) {
            damage_guess = minimum_guess;
        }
    }

    if (state_guess == 4 || state_guess == 8) {
        type_guess = 0xf6;
        damage_guess = 0x32 - value_0034_guess / 3;
        if (damage_guess < 10) {
            damage_guess = 10;
        }
    }

    if (damage_guess > 0) {
        event_guess.target_guess = static_cast<unsigned short>(target_guess->spawn_id_guess);
        event_guess.source_guess = 0;
        event_guess.value_0004_guess = 0;
        event_guess.damage_0006_guess = damage_guess;
        event_guess.value_000a_guess = 0.0f;
        event_guess.value_000e_guess = 0.0f;
        event_guess.value_0012_guess = 0.0f;
        event_guess.type_guess = static_cast<unsigned char>(type_guess);
        event_guess.spell_guess = -1;
        TakeDamage_guess(damage_guess, reinterpret_cast<DamageRecord_guess*>(&event_guess), 1, 0, 1, 1);
    }
}

// Inventory helpers. InventoryView_guess is the character's inventory, with misnamed members: InventorySlots_guess
// holds the 31 top-level slots (0-21 worn, 22-29 general, 30 cursor) and ItemInstance_guess is an item.
// IsBlocked_guess means container, GetValue_guess is the item type, GetKey_guess the item id,
// GetCount_guess the bag size, HasWeightedValue_guess stackable, +0x48 the stack count.
// Bag slot ids are 31 + slot * 10 + index (251-340 for the general slots and cursor).
// First item of item type `value_guess`, in slot order, looking inside bags; bags themselves never match.
// FUNCTION: TITANIUM 0x0041D616
char InventoryView_guess::FindItemByType_guess(int value_guess, int* index_guess, int* subindex_guess) {
    if (index_guess != 0) {
        *index_guess = -1;
    }
    if (subindex_guess != 0) {
        *subindex_guess = -1;
    }
    for (int outer_guess = 0; outer_guess < 0x1f; ++outer_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(outer_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetItemClass_guess() == 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetValue_guess() == value_guess) {
                    if (index_guess != 0) {
                        *index_guess = outer_guess;
                    }
                    return 1;
                }
            } else if (reinterpret_cast<InventorySlots_guess*>(
                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                           ->GetEntry_guess(outer_guess)
                           ->GetItemClass_guess() == 1) {
                for (int inner_guess = 0;
                     inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                       reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                       ->GetEntry_guess(outer_guess)
                                       ->GetCount_guess();
                     ++inner_guess) {
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess) != 0) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess)
                                ->GetItemClass_guess() == 0) {
                            if (reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(outer_guess)
                                    ->GetEntry_guess(inner_guess)
                                    ->GetValue_guess() == value_guess) {
                                if (index_guess != 0) {
                                    *index_guess = outer_guess;
                                }
                                if (subindex_guess != 0) {
                                    *subindex_guess = inner_guess;
                                }
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// First item with item id `value_guess`, bags included; `mode_guess` != 0 searches from the cursor down.
// FUNCTION: TITANIUM 0x0041D773
char InventoryView_guess::FindItemById_guess(int value_guess, int* index_guess, int* subindex_guess, char mode_guess) {
    if (index_guess != 0) {
        *index_guess = -1;
    }
    if (subindex_guess != 0) {
        *subindex_guess = -1;
    }
    if (mode_guess == 0) {
        for (int outer_guess = 0; outer_guess < 0x1f; ++outer_guess) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess) != 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetItemId_guess() == value_guess) {
                    if (index_guess != 0) {
                        *index_guess = outer_guess;
                    }
                    return 1;
                }
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetItemClass_guess() == 1) {
                    for (int inner_guess = 0;
                         inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                           ->GetEntry_guess(outer_guess)
                                           ->GetCount_guess();
                         ++inner_guess) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess) != 0 &&
                            reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess)
                                ->GetItemId_guess() == value_guess) {
                            if (index_guess != 0) {
                                *index_guess = outer_guess;
                            }
                            if (subindex_guess != 0) {
                                *subindex_guess = inner_guess;
                            }
                            return 1;
                        }
                    }
                }
            }
        }
    } else {
        for (int outer_guess = 0x1e; outer_guess >= 0; --outer_guess) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess) != 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetItemId_guess() == value_guess) {
                    if (index_guess != 0) {
                        *index_guess = outer_guess;
                    }
                    return 1;
                }
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetItemClass_guess() == 1) {
                    for (int inner_guess = 0;
                         inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                           ->GetEntry_guess(outer_guess)
                                           ->GetCount_guess();
                         ++inner_guess) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess) != 0 &&
                            reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess)
                                ->GetItemId_guess() == value_guess) {
                            if (index_guess != 0) {
                                *index_guess = outer_guess;
                            }
                            if (subindex_guess != 0) {
                                *subindex_guess = inner_guess;
                            }
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// How many of item id `value_guess` the character carries: a stack counts its size, a matching bag 1.
// FUNCTION: TITANIUM 0x0041D986
int InventoryView_guess::CountItem_guess(int value_guess) {
    int result_guess = 0;
    for (int outer_guess = 0; outer_guess < 0x1f; ++outer_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(outer_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetItemClass_guess() == 1) {
                if (value_guess == reinterpret_cast<InventorySlots_guess*>(
                                       reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                       ->GetEntry_guess(outer_guess)
                                       ->GetItemId_guess()) {
                    ++result_guess;
                } else {
                    for (int inner_guess = 0;
                         inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                           ->GetEntry_guess(outer_guess)
                                           ->GetCount_guess();
                         ++inner_guess) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess) != 0) {
                            if (reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(outer_guess)
                                    ->GetEntry_guess(inner_guess)
                                    ->GetItemId_guess() == value_guess) {
                                if (reinterpret_cast<InventorySlots_guess*>(
                                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                        ->GetEntry_guess(outer_guess)
                                        ->GetEntry_guess(inner_guess)
                                        ->GetItemClass_guess() == 0 &&
                                    reinterpret_cast<InventorySlots_guess*>(
                                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                        ->GetEntry_guess(outer_guess)
                                        ->GetEntry_guess(inner_guess)
                                        ->IsStackable_guess() != 0) {
                                    result_guess += reinterpret_cast<InventorySlots_guess*>(
                                                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                        ->GetEntry_guess(outer_guess)
                                                        ->GetEntry_guess(inner_guess)
                                                        ->chargesOrStackCount_0048_guess;
                                } else {
                                    ++result_guess;
                                }
                            }
                        }
                    }
                }
            } else if (reinterpret_cast<InventorySlots_guess*>(
                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                           ->GetEntry_guess(outer_guess)
                           ->GetItemId_guess() == value_guess) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetItemClass_guess() == 0 &&
                    reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->IsStackable_guess() != 0) {
                    result_guess += reinterpret_cast<InventorySlots_guess*>(
                                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                        ->GetEntry_guess(outer_guess)
                                        ->chargesOrStackCount_0048_guess;
                } else {
                    ++result_guess;
                }
            }
        }
    }
    return result_guess;
}

// Removes one item: item id `value_guess` (searched from the cursor down) or, when that is -1, the first
// item of type `index_guess`. A stack loses one (OP_DeleteItem); anything else is deleted and sent as
// OP_MoveItem to slot -1. An emptied head, primary or secondary slot (2, 13, 14) clears its visible model
// (material 0, 7, 8); an emptied cursor (30) clears CDisplay +0x10. +0xC marks the inventory changed.
// FUNCTION: TITANIUM 0x0041DB52
char InventoryView_guess::RemoveOneItem_guess(int index_guess, int value_guess) {
    int subindex_guess;
    RankMessage_guess message_guess;
    char result_guess;
    if (value_guess != -1) {
        result_guess = FindItemById_guess(value_guess, &index_guess, &subindex_guess, 1);
    } else {
        result_guess = FindItemByType_guess(index_guess, &index_guess, &subindex_guess);
    }
    if (result_guess) {
        if (subindex_guess != -1) {
            int subindex_value_guess = subindex_guess;
            ItemInstance_guess* entry_guess = reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->GetEntry_guess(index_guess);
            if (entry_guess != 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess)
                        ->GetItemClass_guess() == 1) {
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess)
                            ->GetEntry_guess(subindex_value_guess) != 0) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->GetEntry_guess(subindex_value_guess)
                                ->IsStackable_guess()) {
                            message_guess.first_guess = -1;
                            message_guess.second_guess = -1;
                            message_guess.value_guess = index_guess * 10 + subindex_value_guess + 0x1f;
                            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_DeleteItem, &message_guess, 0xc, 1);
                            if (reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(index_guess)
                                    ->GetEntry_guess(subindex_value_guess)
                                    ->chargesOrStackCount_0048_guess <= 1) {
                                reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(index_guess)
                                    ->DeleteSubentry_guess(subindex_value_guess);
                            } else {
                                ItemInstance_guess* subentry_guess = reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(index_guess)
                                    ->GetEntry_guess(subindex_value_guess);
                                --subentry_guess->chargesOrStackCount_0048_guess;
                            }
                        } else {
                            reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->DeleteSubentry_guess(subindex_value_guess);
                            message_guess.first_guess = -1;
                            message_guess.second_guess = 0;
                            message_guess.value_guess = index_guess * 10 + subindex_value_guess + 0x1f;
                            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_MoveItem, &message_guess, 0xc, 1);
                        }
                    }
                }
            }
        } else {
            ItemInstance_guess* entry_guess = reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->GetEntry_guess(index_guess);
            if (entry_guess != 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess)
                        ->IsStackable_guess()) {
                    message_guess.first_guess = -1;
                    message_guess.second_guess = -1;
                    message_guess.value_guess = index_guess;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_DeleteItem, &message_guess, 0xc, 1);
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess)
                            ->chargesOrStackCount_0048_guess <= 1) {
                        ItemInstance_guess* removed_guess = reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess);
                        if (removed_guess != 0) {
                            removed_guess->Release_guess(1);
                        }
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->SetArrayValue_guess(index_guess, 0);
                        switch (index_guess) {
                        case 2:
                            store_guess->SetStat_guess(0, EQ_ARRAY(char, 0x006410A8), 0);
                            break;
                        case 0xd:
                            store_guess->SetStat_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
                            break;
                        case 0xe:
                            store_guess->SetStat_guess(8, EQ_ARRAY(char, 0x006410A8), 0);
                            break;
                        case 0x1e:
                            g_refreshService_guess->flag_0010_guess = 0;
                            break;
                        }
                    } else {
                        ItemInstance_guess* outer_entry_guess = reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess);
                        --outer_entry_guess->chargesOrStackCount_0048_guess;
                    }
                } else {
                    ItemInstance_guess* removed_guess = reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess);
                    if (removed_guess != 0) {
                        removed_guess->Release_guess(1);
                    }
                    reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->SetArrayValue_guess(index_guess, 0);
                    message_guess.first_guess = -1;
                    message_guess.value_guess = index_guess;
                    message_guess.second_guess = 0;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_MoveItem, &message_guess, 0xc, 1);
                    switch (index_guess) {
                    case 2:
                        store_guess->SetStat_guess(0, EQ_ARRAY(char, 0x006410A8), 0);
                        break;
                    case 0xd:
                        store_guess->SetStat_guess(7, EQ_ARRAY(char, 0x006410A8), 0);
                        break;
                    case 0xe:
                        store_guess->SetStat_guess(8, EQ_ARRAY(char, 0x006410A8), 0);
                        break;
                    case 0x1e:
                        g_refreshService_guess->flag_0010_guess = 0;
                        break;
                    }
                }
            }
        }
    }
    value_000c_guess = 1;
    return result_guess;
}

// Item at a Titanium slot id: 0-30 directly, 251-340 inside the bag in slot (id - 31) / 10; else null.
// FUNCTION: TITANIUM 0x0041DE16
// @early-stop: budget, structural ndiff=15
int InventoryView_guess::GetValue_guess(int value_guess) {
    int index_guess;
    int remainder_guess;
    if (value_guess >= 0) {
        if (value_guess <= 30) {
            return reinterpret_cast<int>(
                reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(value_guess));
        }
    } else {
        if (value_guess <= 30) {
            return 0;
        }
    }
    int adjusted_guess = value_guess - 31;
    index_guess = adjusted_guess / 10;
    remainder_guess = adjusted_guess % 10;
    if (index_guess < 0 || index_guess >= 31) {
        return 0;
    }
    ItemInstance_guess* entry_guess =
        reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
            ->GetEntry_guess(index_guess);
    if (entry_guess != 0 && entry_guess->GetItemClass_guess() == 1 &&
        remainder_guess < entry_guess->GetCount_guess()) {
        return reinterpret_cast<int>(entry_guess->GetEntry_guess(remainder_guess));
    }
    return 0;
}

// Auto-eat: uses one food (`mode_guess` != 0, item type 14) or drink (type 15) from general slots 22-29 or
// their bags, then OP_Consume (Consume_Struct: slot, auto_consumed -1, type 1 food or 2 drink).
// Returns 1 when something was consumed.
// FUNCTION: TITANIUM 0x0041DE8E
// @early-stop: budget, structural ndiff=66
int InventoryView_guess::AutoConsume_guess(char mode_guess) {
    reinterpret_cast<CostDynamicBase_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->GetCandidate_guess();
    int record_guess[4];
    int outer_guess = 0x16;
    do {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess) != 0 &&
            reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetItemClass_guess() == 0) {
            int value_guess = reinterpret_cast<InventorySlots_guess*>(
                                  reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                  ->GetEntry_guess(outer_guess)
                                  ->GetValue_guess();
            if (mode_guess != 0) {
                if (value_guess == 0xe) {
                    record_guess[1] = -1;
                    record_guess[2] = -1;
                    record_guess[0] = outer_guess;
                    record_guess[3] = 1;
                    ItemInstance_guess* selected_guess = reinterpret_cast<InventorySlots_guess*>(
                                                          reinterpret_cast<int>(this) +
                                                          offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                          ->GetEntry_guess(outer_guess);
                    if (selected_guess->chargesOrStackCount_0048_guess == 1) {
                        ItemInstance_guess* entry_guess = reinterpret_cast<InventorySlots_guess*>(
                                                           reinterpret_cast<int>(this) +
                                                           offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                           ->GetEntry_guess(outer_guess);
                        if (entry_guess != 0) {
                            entry_guess->Release_guess(1);
                        }
                        reinterpret_cast<PropertyProxy_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->SetArrayValue_guess(outer_guess, 0);
                    } else {
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->chargesOrStackCount_0048_guess -= 1;
                    }
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Consume, record_guess, 0x10, 1);
                    return 1;
                }
            } else if (value_guess == 0xf) {
                record_guess[1] = -1;
                record_guess[2] = -1;
                record_guess[0] = outer_guess;
                record_guess[3] = 2;
                ItemInstance_guess* selected_guess = reinterpret_cast<InventorySlots_guess*>(
                                                      reinterpret_cast<int>(this) +
                                                      offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                      ->GetEntry_guess(outer_guess);
                if (selected_guess->chargesOrStackCount_0048_guess == 1) {
                    ItemInstance_guess* entry_guess = reinterpret_cast<InventorySlots_guess*>(
                                                       reinterpret_cast<int>(this) +
                                                       offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                       ->GetEntry_guess(outer_guess);
                    if (entry_guess != 0) {
                        entry_guess->Release_guess(1);
                    }
                    reinterpret_cast<PropertyProxy_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->SetArrayValue_guess(outer_guess, 0);
                } else {
                    reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->chargesOrStackCount_0048_guess -= 1;
                }
                EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Consume, record_guess, 0x10, 1);
                return 1;
            }
        } else {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess) == 0) {
                continue;
            }
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetItemClass_guess() != 1) {
                continue;
            }
            int inner_guess = 0;
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetCount_guess() > 0) {
                do {
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess) == 0) {
                        continue;
                    }
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess)
                            ->GetItemClass_guess() != 0) {
                        continue;
                    }
                    int value_guess = reinterpret_cast<InventorySlots_guess*>(
                                          reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                          ->GetEntry_guess(outer_guess)
                                          ->GetEntry_guess(inner_guess)
                                          ->GetValue_guess();
                    if (mode_guess != 0) {
                        if (value_guess != 0xe) {
                            continue;
                        }
                        record_guess[3] = 1;
                    } else {
                        if (value_guess != 0xf) {
                            continue;
                        }
                        record_guess[3] = 2;
                    }
                    record_guess[1] = -1;
                    record_guess[2] = -1;
                    record_guess[0] = inner_guess + 0x1f + outer_guess * 10;
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess)
                            ->chargesOrStackCount_0048_guess == 1) {
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->DeleteSubentry_guess(inner_guess);
                    } else {
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess)
                            ->chargesOrStackCount_0048_guess -= 1;
                    }
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Consume, record_guess, 0x10, 1);
                    return 1;
                } while (++inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                             reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                             ->GetEntry_guess(outer_guess)
                                             ->GetCount_guess());
            }
        }
    } while (++outer_guess <= 0x1d);
    return 0;
}

// Supplies left in the general slots, as ProcessHungerandThirst_guess's message key: 1 out of food, 2 low on
// food (one item), plus 4 out of drink or 8 low on drink.
// FUNCTION: TITANIUM 0x0041E146
int InventoryView_guess::GetFoodDrinkStatus_guess() {
    int first_total_guess = 0;
    int second_total_guess = 0;
    int result_guess = 0;
    for (int outer_guess = 0x16; outer_guess <= 0x1d; ++outer_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(outer_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(outer_guess)
                    ->GetItemClass_guess() == 0) {
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetValue_guess() == 0xe) {
                    first_total_guess += reinterpret_cast<InventorySlots_guess*>(
                                             reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                             ->GetEntry_guess(outer_guess)
                                             ->chargesOrStackCount_0048_guess;
                }
                if (reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(outer_guess)
                        ->GetValue_guess() == 0xf) {
                    second_total_guess += reinterpret_cast<InventorySlots_guess*>(
                                              reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                              ->GetEntry_guess(outer_guess)
                                              ->chargesOrStackCount_0048_guess;
                }
            } else if (reinterpret_cast<InventorySlots_guess*>(
                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                           ->GetEntry_guess(outer_guess)
                           ->GetItemClass_guess() == 1) {
                for (int inner_guess = 0;
                     inner_guess < reinterpret_cast<InventorySlots_guess*>(
                                       reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                       ->GetEntry_guess(outer_guess)
                                       ->GetCount_guess();
                     ++inner_guess) {
                    if (reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(outer_guess)
                            ->GetEntry_guess(inner_guess) != 0) {
                        if (reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(outer_guess)
                                ->GetEntry_guess(inner_guess)
                                ->GetItemClass_guess() == 0) {
                            if (reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(outer_guess)
                                    ->GetEntry_guess(inner_guess)
                                    ->GetValue_guess() == 0xe) {
                                first_total_guess += reinterpret_cast<InventorySlots_guess*>(
                                                         reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                         ->GetEntry_guess(outer_guess)
                                                         ->GetEntry_guess(inner_guess)
                                                         ->chargesOrStackCount_0048_guess;
                            }
                            if (reinterpret_cast<InventorySlots_guess*>(
                                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                    ->GetEntry_guess(outer_guess)
                                    ->GetEntry_guess(inner_guess)
                                    ->GetValue_guess() == 0xf) {
                                second_total_guess += reinterpret_cast<InventorySlots_guess*>(
                                                          reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                          ->GetEntry_guess(outer_guess)
                                                          ->GetEntry_guess(inner_guess)
                                                          ->chargesOrStackCount_0048_guess;
                            }
                        }
                    }
                }
            }
        }
    }
    if (first_total_guess == 0) {
        result_guess = 1;
    } else if (first_total_guess < 2) {
        result_guess = 2;
    }
    if (second_total_guess == 0) {
        result_guess += 4;
    } else if (second_total_guess < 2) {
        result_guess += 8;
    }
    return result_guess;
}

#define g_chatBusy_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_chatHold_guess EQ_GLOBAL(int, 0x00923884)
#define g_noticeA_guess EQ_GLOBAL(int, 0x009248D4)
#define g_noticeB_guess EQ_GLOBAL(int, 0x009248D0)

// ProcessHungerandThirst (a Lantern name), each frame from DoPassageOfTime_guess. Profile tail values
// 7 and 8 are thirst and hunger: GMs (+0x256) stay at 32000, and the Hunger SPA (115) holds both at 3500+.
// Every 46 s (92 s for monks, longer with Metabolism, SPA 233) a value under 3000 makes the character
// drink or eat (AutoConsume_guess); with nothing to use it prints 'You are thirsty' or 'hungry' (12484-12487,
// the mount lines when mounted). Without SPA 115 it then warns about supplies (strings 12488-12495).
// FUNCTION: TITANIUM 0x00420F51
// @early-stop: budget, structural ndiff=182
void InventoryView_guess::ProcessHungerandThirst_guess(int now_guess) {
    RankHost_guess* host_guess;
    int flag_guess = 0;
    if (store_guess == 0) {
        return;
    }
    if (store_guess->type_0244_guess != 0) {
        return;
    }
    host_guess = reinterpret_cast<RankSlot_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)->Slot16_guess();
    if (host_guess == 0) {
        return;
    }
    if (store_guess->mode_0251_guess == 'f') {
        return;
    }
    if (store_guess->gm_0256_guess != 0) {
        reinterpret_cast<LookupResult_guess*>(
            reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                            host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                ->GetCharInfo2())
            ->tail_guess.seventh_value_guess = 32000;
        reinterpret_cast<LookupResult_guess*>(
            reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                            host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                ->GetCharInfo2())
            ->tail_guess.eighth_value_guess = 32000;
        return;
    }
    if (TotalSpellAffects_guess(0x73, 1, 0, 1) != 0) {
        if (reinterpret_cast<LookupResult_guess*>(
                reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->GetCharInfo2())
                ->tail_guess.seventh_value_guess < 0xdac) {
            reinterpret_cast<LookupResult_guess*>(
                reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->GetCharInfo2())
                ->tail_guess.seventh_value_guess = 0xdac;
        }
        if (reinterpret_cast<LookupResult_guess*>(
                reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->GetCharInfo2())
                ->tail_guess.eighth_value_guess < 0xdac) {
            reinterpret_cast<LookupResult_guess*>(
                reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->GetCharInfo2())
                ->tail_guess.eighth_value_guess = 0xdac;
        }
    }
    if (store_guess->IsLocked_guess() == 0) {
        if (store_guess->timer_01a8_guess != 0 && store_guess->timer_01a8_guess->value_015c_guess != 0) {
            flag_guess = 1;
        }
        int limit_guess = 46000;
        if (reinterpret_cast<LookupResult_guess*>(
                reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(this) +
                                                offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetCharInfo2())
                ->state_guess == 7) {
            limit_guess = 92000;
        }
        unsigned int threshold_guess =
            limit_guess + (unsigned int)(TotalSpellAffects_guess(0xe9, 1, 0, 1) * limit_guess) / 100;
        if (g_chatBusy_guess == 0 && g_chatHold_guess == 0 &&
            (unsigned int)(now_guess - store_guess->timer_01a8_guess->last_guess) > threshold_guess) {
            if (reinterpret_cast<LookupResult_guess*>(
                    reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                    host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->GetCharInfo2())
                    ->tail_guess.seventh_value_guess < 3000 &&
                g_noticeA_guess == 0 && g_noticeB_guess == 0) {
                if (AutoConsume_guess(0) == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(flag_guess != 0 ? 0x30c4 : 0x30c5, 0), 0x111, 1);
                } else {
                    host_guess->flag_c28c_guess = 1;
                }
            }
            if (reinterpret_cast<LookupResult_guess*>(
                    reinterpret_cast<EQ_Character*>(reinterpret_cast<int>(host_guess) +
                                                    host_guess->offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->GetCharInfo2())
                    ->tail_guess.eighth_value_guess < 3000 &&
                g_noticeA_guess == 0 && g_noticeB_guess == 0) {
                if (AutoConsume_guess(1) == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(flag_guess != 0 ? 0x30c6 : 0x30c7, 0), 0x111, 1);
                } else {
                    host_guess->flag_c28c_guess = 1;
                }
            }
            store_guess->timer_01a8_guess->last_guess = GetCurrentTime_guess();
        if (TotalSpellAffects_guess(0x73, 1, 0, 1) == 0) {
            int message_guess;
            switch (GetFoodDrinkStatus_guess()) {
            case 1:
                message_guess = 0x30c8;
                break;
            case 2:
                message_guess = 0x30c9;
                break;
            default:
                return;
            case 4:
                message_guess = 0x30ca;
                break;
            case 5:
                message_guess = 0x30cb;
                break;
            case 6:
                message_guess = 0x30cc;
                break;
            case 8:
                message_guess = 0x30cd;
                break;
            case 9:
                message_guess = 0x30ce;
                break;
            case 10:
                message_guess = 0x30cf;
            }
            pEverQuest->dsp_chat(pStringTable->getString(message_guess, 0), 0x111, 1);
        }
        }
    }
}

#define g_manaUpdateFlag_guess EQ_GLOBAL(unsigned char, 0x00905CA8)
#define g_manaScale_guess EQ_GLOBAL(float, 0x00640E20)
#define g_manaRate_guess EQ_GLOBAL(float, 0x00640038)
#define g_manaBase_guess EQ_GLOBAL(double, 0x006410A0)

// Mana regeneration tick, only below max mana: base regen (+0x1270 standing, +0x126C sitting;
// none at 0 hunger or thirst), plus 1-2 and Meditate / 15 when sitting with Meditate (31), not for bards;
// newbie rules (0x905CA8) below level 21 add 10 sitting or 6; then CurrentMana (SPA 15), levels 62 and 64,
// and item mana regen capped at 15 + ItemManaRegenCapIncrease (SPA 318).
// At most 65, scaled by the spawn's rate.
// FUNCTION: TITANIUM 0x0041E361
void DynamicPropertyBoundOwner_guess::RegenMana_guess() {
    if (GetTable_guess()->GetWidget_guess() == 0) {
        return;
    }
    int total_guess = 0;
    int allowed_guess = GetAllowedValue_guess();
    if (Cur_Mana_guess() < allowed_guess) {
        if (entity_guess->state_guess == 0) {
            if (ResolveResult_guess()->tail_guess.eighth_value_guess == 0 ||
                ResolveResult_guess()->tail_guess.seventh_value_guess == 0) {
                total_guess = 0;
            } else {
                total_guess = ResolveResult_guess()->value_1270_guess;
                if (reinterpret_cast<ValueChainOwner_guess*>(this)->IsLeafZero_guess() ||
                    entity_guess->stand_state_guess == 'n') {
                    total_guess = ResolveResult_guess()->value_126c_guess;
                    if (ResolveResult_guess()->state_guess != 8) {
                        if (reinterpret_cast<LookupGate_guess*>(this)->HasSkill_guess(0x1f) != 0) {
                            int kind_guess = reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0x1f);
                            ++total_guess;
                            if (kind_guess > 1) {
                                ++total_guess;
                            }
                            if (kind_guess > 0xe) {
                                total_guess += kind_guess / 0xf;
                            }
                        }
                    }
                }
            }
            if (g_manaUpdateFlag_guess != 0 &&
                ResolveResult_guess()->level_11a4_guess < 0x15) {
                if (GetTable_guess()->flag_0104_guess == 'n') {
                    total_guess += 10;
                } else {
                    total_guess += 6;
                }
            }
            total_guess += reinterpret_cast<int>(
                reinterpret_cast<WrapperObject_guess*>(this)->GetThree_guess(0xf, 0));
            if (entity_guess != 0 && entity_guess->state_guess == 0) {
                if (ResolveResult_guess()->level_11a4_guess > 0x3d) {
                    ++total_guess;
                }
                if (ResolveResult_guess()->level_11a4_guess > 0x3f) {
                    ++total_guess;
                }
            }
            if (reinterpret_cast<NotifyOwner_guess*>(this)->FindBuffWithEffect_guess(0x65, 0) != 0) {
                ++total_guess;
            }
            int value_guess = reinterpret_cast<int>(
                reinterpret_cast<WrapperObject_guess*>(this)->GetTwo_guess(0xf, 0));
            value_guess += value_00ac_guess;
            int limit_guess = reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x13e, 1, 0, 1) + 0xf;
            if (value_guess > limit_guess) {
                value_guess = limit_guess;
            }
            if (value_guess != 0) {
                total_guess += value_guess;
            }
        } else {
            GetTable_guess()->Slot0b_guess();
        }
        if (total_guess > 0x41) {
            total_guess = 0x41;
        }
        if (entity_guess != 0) {
            total_guess = (int)((float)total_guess * entity_guess->multiplier_guess * g_manaRate_guess *
                                    g_manaScale_guess +
                                g_manaBase_guess);
        }
        GetTable_guess()->AddField11A8_guess(total_guess);
        if (total_guess < 0) {
            Cur_Mana_guess();
        }
    }
}

// True when the character carries at least `threshold` of item `value` (0x0041D986); the cast code
// checks spell components with it.
// FUNCTION: TITANIUM 0x00424058
char InventoryView_guess::HasCountAtLeast_guess(int value_guess, int threshold_guess) {
    return threshold_guess <= CountItem_guess(value_guess);
}

// Inventory reset: Prepare_guess, then the slot array is cleared.
// FUNCTION: TITANIUM 0x0041E7DC
void AddressedObject_guess::Dispatch_guess() {
    reinterpret_cast<InventoryView_guess*>(GetOwner_guess())->Prepare_guess();
    reinterpret_cast<InventorySlots_guess*>(
        reinterpret_cast<int>(GetOwner_guess()) +
        reinterpret_cast<InventoryView_guess*>(GetOwner_guess())->offset_holder_guess->vbaseOffset_0004_guess + 4)
        ->Clear_guess();
}

struct CharVBase_guess {
    virtual ~CharVBase_guess();
    virtual void Slot01_guess();
    char pad_0004_guess[0x148];
    // EXTERNAL: TITANIUM 0x005FB460 CharVBase_guess::Copy_guess
    void Copy_guess(const CharVBase_guess& source_guess);
    // EXTERNAL: TITANIUM 0x005FB0D0 ??0CharVBase_guess@@QAE@XZ
    CharVBase_guess();
};

struct CharSub_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x0060CB40 CharSub_guess::Copy_guess
    void Copy_guess(const CharSub_guess& source_guess);
    // EXTERNAL: TITANIUM 0x0060D010 ??0CharSub_guess@@QAE@XZ
    CharSub_guess();
    // EXTERNAL: TITANIUM 0x0060D020 ??1CharSub_guess@@QAE@XZ
    ~CharSub_guess();
};

struct CharVBaseTable_guess {
    int unused_guess;
    int offset_guess;
};

struct Character1VbPtr_guess {
    int unused_guess;
    CharVBaseTable_guess* vbtable_guess;
};

#define g_scaleTableReady_guess EQ_GLOBAL(int, 0x0079D86C)
#define g_scaleTable_guess EQ_ARRAY(double, 0x0079D7C8)

// EXTERNAL: TITANIUM 0x00640F78 ??_7Character1_guess@@6B0@@
// EXTERNAL: TITANIUM 0x00640F30 ??_7Character1_guess@@6BCharVBase_guess@@@
struct Character1_guess : virtual CharVBase_guess {
    Character1_guess();
    ~Character1_guess();
    virtual void Slot01_guess();
    virtual void OwnSlot00_guess();
    EQPlayer* player_0008_guess;
    unsigned char field_000c_guess;
    char pad_000d_guess[3];
    int fields_0010_guess[26];
    RankValues_guess rank_values_0078_guess;
    int fields_009c_guess[5];
    char pad_00b0_guess[4];
    int fields_00b4_guess[3];
    unsigned char field_00c0_guess;
    unsigned char field_00c1_guess;
    char pad_00c2_guess[2];
    CharSub_guess sub_00c4_guess;
    void Copy_guess(const Character1_guess& source_guess);
};

// FUNCTION: TITANIUM 0x0041682F
Character1_guess::~Character1_guess() {
    if (player_0008_guess != 0) {
        player_0008_guess->pCharInfo = 0;
    }
}

// Character assignment: the virtual base first, then every own field, the rank values (+0x78) and the
// sub-object at +0xC4.
// FUNCTION: TITANIUM 0x0041E5B8
void Character1_guess::Copy_guess(const Character1_guess& source_guess) {
    reinterpret_cast<CharVBase_guess*>(reinterpret_cast<int>(this) +
                                       reinterpret_cast<Character1VbPtr_guess*>(this)->vbtable_guess->offset_guess +
                                       4)
        ->Copy_guess(
        *static_cast<const CharVBase_guess*>(&source_guess));
    field_000c_guess = source_guess.field_000c_guess;
    fields_0010_guess[0] = source_guess.fields_0010_guess[0];
    fields_0010_guess[1] = source_guess.fields_0010_guess[1];
    fields_0010_guess[2] = source_guess.fields_0010_guess[2];
    fields_0010_guess[3] = source_guess.fields_0010_guess[3];
    fields_0010_guess[4] = source_guess.fields_0010_guess[4];
    fields_0010_guess[5] = source_guess.fields_0010_guess[5];
    fields_0010_guess[6] = source_guess.fields_0010_guess[6];
    fields_0010_guess[7] = source_guess.fields_0010_guess[7];
    fields_0010_guess[8] = source_guess.fields_0010_guess[8];
    fields_0010_guess[9] = source_guess.fields_0010_guess[9];
    fields_0010_guess[10] = source_guess.fields_0010_guess[10];
    fields_0010_guess[11] = source_guess.fields_0010_guess[11];
    fields_0010_guess[12] = source_guess.fields_0010_guess[12];
    fields_0010_guess[13] = source_guess.fields_0010_guess[13];
    fields_0010_guess[14] = source_guess.fields_0010_guess[14];
    fields_0010_guess[15] = source_guess.fields_0010_guess[15];
    fields_0010_guess[16] = source_guess.fields_0010_guess[16];
    fields_0010_guess[17] = source_guess.fields_0010_guess[17];
    fields_0010_guess[18] = source_guess.fields_0010_guess[18];
    fields_0010_guess[19] = source_guess.fields_0010_guess[19];
    fields_0010_guess[20] = source_guess.fields_0010_guess[20];
    fields_0010_guess[21] = source_guess.fields_0010_guess[21];
    fields_0010_guess[22] = source_guess.fields_0010_guess[22];
    fields_0010_guess[23] = source_guess.fields_0010_guess[23];
    fields_0010_guess[24] = source_guess.fields_0010_guess[24];
    fields_0010_guess[25] = source_guess.fields_0010_guess[25];
    rank_values_0078_guess.Copy_guess(source_guess.rank_values_0078_guess);
    fields_009c_guess[0] = source_guess.fields_009c_guess[0];
    fields_009c_guess[1] = source_guess.fields_009c_guess[1];
    fields_009c_guess[2] = source_guess.fields_009c_guess[2];
    fields_009c_guess[3] = source_guess.fields_009c_guess[3];
    fields_009c_guess[4] = source_guess.fields_009c_guess[4];
    fields_00b4_guess[0] = source_guess.fields_00b4_guess[0];
    fields_00b4_guess[1] = source_guess.fields_00b4_guess[1];
    fields_00b4_guess[2] = source_guess.fields_00b4_guess[2];
    field_00c0_guess = source_guess.field_00c0_guess;
    sub_00c4_guess.Copy_guess(source_guess.sub_00c4_guess);
    field_00c1_guess = source_guess.field_00c1_guess;
}

// Fills the shared table 0x79D7C8 once with 0.1, 0.2 ... 2.0.
// FUNCTION: TITANIUM 0x0041E71F
Character1_guess::Character1_guess() {
    reinterpret_cast<RankState_guess*>(this)->Reset_guess();
    if (g_scaleTableReady_guess == 0) {
        for (int i = 0; i < 20; i++) {
            g_scaleTable_guess[i] = (i + 1.0) * 0.1;
        }
        g_scaleTableReady_guess = 1;
    }
    player_0008_guess = 0;
    field_00c0_guess = 0;
}

struct CostTotalOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual ItemInstance_guess* Slot05_guess(int index_guess);
    LookupOffset_guess* offset_holder_guess;
    DynamicPropertyInput_guess* input_guess;
    char padding_000c_guess[0x18];
    int value_0024_guess;
    // EXTERNAL: TITANIUM 0x00417F67 CostTotalOwner_guess::IsIntCaster_guess
    int IsIntCaster_guess();
    // EXTERNAL: TITANIUM 0x00417F8E CostTotalOwner_guess::GetClassRaceACBonus_guess
    int GetClassRaceACBonus_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041C7C1 CostTotalOwner_guess::ApplyRank_guess
    int ApplyRank_guess(ItemInstance_guess* entry_guess, int rank_guess, int adjusted_guess);
    int ArmorClass_guess(char flag_guess);
    unsigned char GetSkillBaseDamage_guess(unsigned int kind_guess, struct CostApplyContext_guess* context_guess);
};

// Armour class as shown to the player: base (+0x1278) plus the AC of worn slots 0-20 (scaled
// below the item's level) and of the 5- and 2-entry extra item lists, x4/3 unless IsIntCaster_guess
// (probably the caster test). Players below level 50 are capped at level * 6 + 25 unless `flag_guess`. Then
// Defense (15) / 3 and the ArmorClass SPA (1) / 4 (/2 and /3 for IsIntCaster_guess), and an AGI term.
// FUNCTION: TITANIUM 0x0041E800
int CostTotalOwner_guess::ArmorClass_guess(char flag_guess) {
    DynamicPropertyProxy_guess* proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int total_guess = proxy_guess->lookup_guess.Find_guess()->value_1278_guess;
    int saved_guess = value_0024_guess;
    int index_guess;
    for (index_guess = 0; index_guess < 0x15; ++index_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetEntry_guess(index_guess) != 0) {
            if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                    ->GetEntry_guess(index_guess)
                    ->GetItemClass_guess() == 0) {
                if (index_guess == 0xe &&
                    reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess)
                            ->GetValue_guess() == 8) {
                    reinterpret_cast<InventorySlots_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess)
                        ->GetRankValue_guess(1);
                }
                if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                        ->GetEntry_guess(index_guess)
                        ->HasValue240_guess() != 0 ||
                    (reinterpret_cast<InventorySlots_guess*>(
                         reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                             ->GetEntry_guess(index_guess)
                             ->HasFlag12f_guess(1) == 0 &&
                     reinterpret_cast<InventorySlots_guess*>(
                         reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                             ->GetEntry_guess(index_guess)
                             ->GetRecommendedLevel_guess(1) == 0)) {
                    total_guess += reinterpret_cast<InventorySlots_guess*>(
                                       reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                       ->GetEntry_guess(index_guess)
                                       ->GetRankValue_guess(1);
                } else if (input_guess != 0) {
                    total_guess += ApplyRank_guess(
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess),
                        reinterpret_cast<InventorySlots_guess*>(
                            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                            ->GetEntry_guess(index_guess)
                            ->GetRankValue_guess(1),
                        reinterpret_cast<StatSource_guess*>(input_guess)->Adjust_guess(
                            reinterpret_cast<InventorySlots_guess*>(
                                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                ->GetEntry_guess(index_guess)
                                ->GetValue_guess()));
                }
            }
        }
    }
    for (index_guess = 0; index_guess < 5; ++index_guess) {
        if (reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                ->GetSmallEntry_guess(index_guess) != 0) {
            total_guess += reinterpret_cast<InventorySlots_guess*>(
                               reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                               ->GetSmallEntry_guess(index_guess)
                               ->GetRankValue_guess(1);
        }
    }
    for (index_guess = 0; index_guess < 2; ++index_guess) {
        ItemInstance_guess* entry_guess = Slot05_guess(index_guess);
        if (entry_guess != 0) {
            total_guess += entry_guess->GetRankValue_guess(1);
        }
    }
    if (IsIntCaster_guess() == 0) {
        total_guess = total_guess * 4 / 3;
    }
    if (flag_guess == 0 && input_guess != 0 && input_guess->type_0244_guess == 0) {
        DynamicPropertyProxy_guess* limit_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (limit_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess < 0x32) {
            limit_proxy_guess = reinterpret_cast<DynamicPropertyProxy_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            int limit_guess = limit_proxy_guess->lookup_guess.Find_guess()->level_11a4_guess * 6 + 0x19;
            if (total_guess > limit_guess) {
                total_guess = limit_guess;
            }
        }
    }
    total_guess += GetClassRaceACBonus_guess(saved_guess);
    if (total_guess < 0) {
        total_guess = 0;
    }
    if (IsIntCaster_guess() != 0) {
        total_guess += reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0xf) / 2;
        total_guess += reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(1, 1, 0, 1) / 3;
    } else {
        total_guess += reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0xf) / 3;
        total_guess += reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(1, 1, 0, 1) / 4;
    }
    if (saved_guess > 0x46) {
        total_guess += saved_guess / 0x14;
    }
    if (total_guess < 0) {
        total_guess = 0;
    }
    return total_guess;
}

// Dual-wield roll for an off-hand swing: needs Dual Wield (22) and no two-hander in the primary slot (item
// types 1, 4, 35, the set UseSkill_guess checks for TwoHandBash). Succeeds when 1d375 <= skill + level +
// Ambidexterity (SPA 276), raised by DualWieldChance (176) percent.
// FUNCTION: TITANIUM 0x0041EDAC
char CostOwner_guess::CheckDualWield_guess(int unused_guess) {
    if (reinterpret_cast<LookupGate_guess*>(this)->HasSkill_guess(0x16) == 0) {
        return 0;
    }
    CostDynamicBlock_guess* block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    LookupResult_guess* result_guess = block_guess->Find_guess();
    int* values_guess = result_guess->initial_values_guess;
    ItemInstance_guess* entry_guess = reinterpret_cast<ItemInstance_guess*>(values_guess[13]);
    if (entry_guess != 0 && entry_guess->GetItemClass_guess() == 0) {
        int value_guess = entry_guess->GetValue_guess();
        if (value_guess == 1 || value_guess == 4 || value_guess == 0x23) {
            return 0;
        }
    }
    int roll_guess = TotalSpellAffects_guess(0x114, 1, 0, 1);
    int range_guess = RandomRange_guess(1, 0x177);
    CostDynamicBlock_guess* second_block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    int base_guess = second_block_guess->Find_guess()->level_11a4_guess;
    int total_guess = Skill_guess(0x16) + base_guess + roll_guess;
    int bonus_guess = TotalSpellAffects_guess(0xb0, 1, 0, 1);
    if (bonus_guess != 0) {
        total_guess += bonus_guess * total_guess / 100;
    }
    return range_guess <= total_guess;
}

// Double-attack roll: needs Double Attack (20) or GiveDoubleAttack (SPA 225); 1d500 <= skill + level +
// SPA 225 * 5, raised by DoubleAttackChance (177) percent. Monks and rangers (classes 7, 4) never get it
// while their actor's +0x1034 is set.
// FUNCTION: TITANIUM 0x0041EE86
// @early-stop: budget, structural ndiff=27
char CostChanceOwnerView_guess::CanDoubleAttack_guess(int first_guess, int second_guess) {
    int total_guess = 0;
    if ((Find_guess()->state_guess == 7 || Find_guess()->state_guess == 4) &&
        reinterpret_cast<CostOwner_guess*>(this)->pSpawn_0008_guess != 0 &&
        reinterpret_cast<CostOwner_guess*>(this)->pSpawn_0008_guess->threshold_guess != 0 &&
        reinterpret_cast<CostOwner_guess*>(this)->pSpawn_0008_guess->threshold_guess->value_1034_guess != 0) {
        return 0;
    }

    int dispatch_guess = reinterpret_cast<LookupGate_guess*>(this)->HasSkill_guess(0x14);
    if (dispatch_guess == 0) {
        if (reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0xe1, 1, dispatch_guess, 1) == 0) {
            return 0;
        }
    } else {
        int base_guess = Find_guess()->level_11a4_guess;
        total_guess = reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0x14) + base_guess;
    }

    total_guess += reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0xe1, 1, 0, 1) * 500 / 100;
    int bonus_guess = reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0xb1, 1, 0, 1);
    if (bonus_guess != 0) {
        total_guess += bonus_guess * total_guess / 100;
    }
    return RandomRange_guess(1, 500) <= total_guess;
}

// To-hit rating: Offense (33) + 7 plus weapon skill `mode_guess`, at least 1. For players, a large
// GetOwner_guess()->GetValue_guess() (over 2 * the double at 0x641080) scales it down.
// FUNCTION: TITANIUM 0x0041EAB3
// @early-stop: budget, structural ndiff=8
int CharacterStats_guess::compute_tohit_guess(unsigned char mode_guess) {
    if (this == 0) {
        return 0;
    }

    int result_guess = reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0x21) + 7;
    if (reinterpret_cast<LookupGate_guess*>(this)->HasSkillChecked_guess(mode_guess) != 0) {
        result_guess += reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(mode_guess & 0xff);
    }

    if (source_guess->state_guess == 0) {
        int value_guess = static_cast<ProfileHolder_guess*>(this)->GetOwner_guess()->GetValue_guess();
        int half_guess = value_guess / 2;
        if (static_cast<double>(half_guess) > EQ_GLOBAL(double, 0x00641080)) {
            double factor_guess = (EQ_GLOBAL(double, 0x00641078) - static_cast<double>(half_guess)) *
                                  EQ_GLOBAL(double, 0x00640fa0);
            if (factor_guess > EQ_GLOBAL(double, 0x00640e40)) {
                factor_guess = 1.0;
            }
            result_guess = static_cast<int>(result_guess * factor_guess);
        } else if (source_guess->related_guess != 0 &&
                   source_guess->related_guess->enabled_guess != 0) {
            result_guess += (static_cast<ProfileHolder_guess*>(this)->lookup_guess.Find_guess()->level_11a4_guess * 2) / 5;
        }
    }

    if (result_guess < 1) {
        result_guess = 1;
    }
    return result_guess;
}

// Attack rating (offense in the earlier sibling decomp). Weapon skill (`stat_guess` 0xFF: the primary weapon's, else
// Hand to Hand), (STR - 75) * 2 / 3 above 75 (DEX for Archery and Throwing), the ATK SPA (2), item ATK capped at
// 250 + ItemAttackCapIncrease (SPA 341), and rangers above level 54 add level * 4 - 216. Spell 2434
// moves 100 ATK from the spell side to the capped item side.
// FUNCTION: TITANIUM 0x0041EBB3
int CharacterStats_guess::offense_guess(unsigned char stat_guess) {
    int limit_guess;
    int result_guess = 0;
    int option_guess = 0;
    limit_guess = TotalSpellAffects_guess(0x155, true, 0, true) + 250;
    if (stat_guess == 0xff) {
        int* values_guess = GetProfile_guess()->initial_values_guess;
        if (values_guess[13] != 0) {
            values_guess = GetProfile_guess()->initial_values_guess;
            if (reinterpret_cast<ItemInstance_guess*>(values_guess[13])->GetItemClass_guess() == 0) {
                values_guess = GetProfile_guess()->initial_values_guess;
                stat_guess = source_guess->Adjust_guess(
                    reinterpret_cast<ItemInstance_guess*>(values_guess[13])->GetValue_guess());
            } else {
                stat_guess = 0x1c;
            }
        } else {
            stat_guess = 0x1c;
        }
    }
    if (reinterpret_cast<LookupGate_guess*>(this)->HasSkillChecked_guess(stat_guess) != 0) {
        result_guess = reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(stat_guess);
    }
    int stat_value_guess = (stat_guess == 7 || stat_guess == 0x33) ? value_001c_guess : value_0010_guess;
    if (stat_value_guess >= 0x4b) {
        option_guess = (stat_value_guess * 2 - 0x96) / 3;
    }
    result_guess += option_guess;
    int affected_guess = TotalSpellAffects_guess(2, false, 0, true);
    int add_guess = reinterpret_cast<int>(reinterpret_cast<WrapperObject_guess*>(this)->GetTwo_guess(2, 0));
    if (GetBuffLevelBySpell_guess(0x982)) {
        add_guess += 100;
        affected_guess -= 100;
    }
    add_guess += value_00a4_guess;
    GetProfile_guess();
    if (add_guess > limit_guess) {
        add_guess = limit_guess;
    }
    result_guess += affected_guess + add_guess;
    if (source_guess != 0 && source_guess->state_guess == 0) {
        CostCandidate_guess* candidate_guess = GetOwner_guess();
        if (g_costEnabled_guess != 0 &&
            (candidate_guess->state_flags_guess[candidate_guess->part_guess->flag_index_guess] & 0x40) != 0) {
            result_guess += reinterpret_cast<CandidateBonusService_guess*>(g_costEnabled_guess)
                                ->GetOffenseBonus_guess(candidate_guess);
        }
    }
    if (GetProfile_guess()->state_guess == 4) {
        if (GetProfile_guess()->level_11a4_guess > 0x36) {
            result_guess += GetProfile_guess()->level_11a4_guess * 4 - 0xd8;
        }
    }
    result_guess += GetProfile_guess()->value_127c_guess;
    if (result_guess < 1) {
        result_guess = 1;
    }
    return result_guess;
}

struct CostApplyContext_guess {
    char padding_0000_guess[0x218];
    CostTally_guess* tally_guess;
};

struct CostTallyLookupHead_guess {
    int unused_guess;
    LookupOffset_guess* offset_holder_guess;
};

struct CostKindRecord_guess {
    char padding_0000_guess[0x130];
    unsigned char value_guess;
};

struct CostUseLimit_guess {
    char padding_0000_guess[0x107c];
    int active_guess;
};

struct CostLookupProxyHead_guess {
    int unused_guess;
};

struct CostLookupProxy_guess : CostLookupProxyHead_guess, LookupService_guess {
};

#define g_costKindTable_guess EQ_ARRAY(CostKindRecord_guess*, 0x00851200)

// GetSkillBaseDamage (a Lantern name): the skill table's base damage (0x851200, +0x130), +1 at skill
// 25, 75, 125 and 175. Hand to Hand (28) and Frenzy (74) instead grow with level for monks (class 7; 9 with
// item 10652, probably the monk epic, in the hands slot above level 50) and beastlords (15). Bash adds
// level / 5 + 2, capped by the shield's AC; Kick is x4 while actor +0x107C is set;
// Backstab (8) is the primary
// weapon's damage plus extra damage terms, times a factor of the
// Backstab skill (floats 0x6410B8, 0x6410B4); an NPC without a weapon uses 3.
// FUNCTION: TITANIUM 0x0041EF86
// @early-stop: budget, structural ndiff=210
unsigned char CostTotalOwner_guess::GetSkillBaseDamage_guess(
    unsigned int kind_guess, CostApplyContext_guess* context_guess) {
    if (reinterpret_cast<LookupGate_guess*>(this)->HasSkillChecked_guess(kind_guess) == 0) {
        return 0;
    }
    int lookup_values_offset_guess = offsetof(LookupResult_guess, initial_values_guess);
    unsigned char value_guess = g_costKindTable_guess[static_cast<unsigned char>(kind_guess)]->value_guess;
    // Hand to Hand (28) and Frenzy (74) for a monk (class 7): level / 5 + 2 over the table base,
    // capped at 13, then +1 from level 50 and +1 from level 63. Every other skill (the else) gets +1
    // at skill 25, 75, 125 and 175.
    if (static_cast<unsigned char>(kind_guess) == 0x1c ||
        static_cast<unsigned char>(kind_guess) == 0x4a) {
        CostLookupProxy_guess* proxy_guess = reinterpret_cast<CostLookupProxy_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        if (proxy_guess->Find_guess()->state_guess == 7) {
            int level_guess = reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                                  ->Find_guess()
                                  ->level_11a4_guess;
            value_guess += level_guess / 5 + 2;
            if (value_guess > 13) {
                value_guess = 13;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x31) {
                ++value_guess;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x3e) {
                ++value_guess;
            }
            if (reinterpret_cast<int*>(reinterpret_cast<int>(
                    reinterpret_cast<LookupService_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->Find_guess()) +
                                       lookup_values_offset_guess)[12] != 0 &&
                reinterpret_cast<ItemInstance_guess*>(reinterpret_cast<int*>(reinterpret_cast<int>(
                    reinterpret_cast<LookupService_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->Find_guess()) +
                                                                  lookup_values_offset_guess)[12])
                        ->GetItemId_guess() ==
                    0x299c &&
                reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->Find_guess()
                        ->level_11a4_guess > 0x32) {
                // Item 10652 in the hands slot (equipment entry 12) above level 50 sets it to 9.
                value_guess = 9;
            }
        } else if (reinterpret_cast<LookupService_guess*>(
                       reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                       ->Find_guess()
                       ->state_guess == 0x0f) {
            int level_guess = reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                                  ->Find_guess()
                                  ->level_11a4_guess;
            // Beastlord (class 15): level / 6 + 2 over the base, capped at 12, +1 from level 50.
            value_guess += level_guess / 6 + 2;
            if (value_guess > 0x0c) {
                value_guess = 0x0c;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x31) {
                ++value_guess;
            }
        }
    } else {
        if (reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(
                static_cast<unsigned char>(kind_guess)) >= 0x19) {
            ++value_guess;
        }
        if (reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(
                static_cast<unsigned char>(kind_guess)) >= 0x4b) {
            ++value_guess;
        }
        if (reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(
                static_cast<unsigned char>(kind_guess)) >= 0x7d) {
            ++value_guess;
        }
        if (reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(
                static_cast<unsigned char>(kind_guess)) >= 0xaf) {
            ++value_guess;
        }
    }

    // Frenzy with a primary weapon (equipment entry 13): + (level - 15) from level 16, capped at 23,
    // then +2 above level 50, +1 above 54 and +1 above 59.
    if (static_cast<unsigned char>(kind_guess) == 0x4a) {
        if (reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                ->Find_guess()
                ->initial_values_guess[13] != 0) {
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x0f) {
                value_guess += static_cast<unsigned char>(
                    reinterpret_cast<LookupService_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                        ->Find_guess()
                        ->level_11a4_guess -
                    0x0f);
            }
            if (value_guess > 0x17) {
                value_guess = 0x17;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x32) {
                value_guess += 2;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess > 0x36) {
                ++value_guess;
            }
            if (reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                    ->Find_guess()
                    ->level_11a4_guess <= 0x3b) {
                return value_guess;
            }
            ++value_guess;
            return value_guess;
        }
    // Bash (10): with a shield (item type 8) in the secondary slot (equipment entry 14), + level / 5
    // + 2, but no more than the shield's AC (rank-adjusted when the item has rank flags); without
    // one, the base alone.
    } else if (static_cast<unsigned char>(kind_guess) == 0x0a) {
        ItemInstance_guess* first_entry_guess = reinterpret_cast<ItemInstance_guess*>(
            reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                ->Find_guess()
                ->initial_values_guess[14]);
        if (first_entry_guess == 0) {
            return value_guess;
        }
        if (reinterpret_cast<ItemInstance_guess*>(reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                                                     ->Find_guess()
                                                     ->initial_values_guess[14])
                ->GetValue_guess() != 8) {
            return value_guess;
        }
        ItemInstance_guess* entry_guess = reinterpret_cast<ItemInstance_guess*>(
            reinterpret_cast<LookupService_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                ->Find_guess()
                ->initial_values_guess[14]);
        int rank_guess = entry_guess->GetRankValue_guess(1);
        value_guess += reinterpret_cast<LookupService_guess*>(
                           reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                           ->Find_guess()
                           ->level_11a4_guess /
                       5 +
                   2;
        if (entry_guess->HasFlag12f_guess(1) != 0 || entry_guess->GetRecommendedLevel_guess(1) != 0) {
            rank_guess = ApplyRank_guess(entry_guess, entry_guess->GetRankValue_guess(1),
                                         entry_guess->GetValue_guess());
        }
        if (value_guess <= rank_guess) {
            return value_guess;
        }
        return static_cast<unsigned char>(rank_guess);
    // Kick (30) is four times the base while the flag at +0x107C is set.
    } else if (static_cast<unsigned char>(kind_guess) == 0x1e && input_guess != 0 &&
               reinterpret_cast<CostUseLimit_guess*>(input_guess->threshold_guess)->active_guess != 0) {
        return static_cast<unsigned char>(value_guess << 2);
    }

    // Backstab (8): only with input_guess, and only a player with a primary weapon or an NPC (+0x244
    // type 1). The weapon's damage replaces the base, then the context's tally adds its bonus terms.
    if (static_cast<unsigned char>(kind_guess) == 8) {
    if (input_guess == 0) {
        return value_guess;
    }
    if ((reinterpret_cast<LookupService_guess*>(
             reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
             ->Find_guess()
             ->initial_values_guess[13] == 0 ||
         input_guess->type_0244_guess != 0) &&
        input_guess->type_0244_guess != 1) {
        return value_guess;
    }

    ItemInstance_guess* entry_guess = reinterpret_cast<ItemInstance_guess*>(
        reinterpret_cast<LookupService_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
            ->Find_guess()
            ->initial_values_guess[13]);
    if (entry_guess != 0) {
        value_guess = static_cast<unsigned char>(entry_guess->GetContextValue_guess(1));
        if (entry_guess->HasFlag12f_guess(1) != 0 || entry_guess->GetRecommendedLevel_guess(1) != 0) {
            CostCandidate_guess* candidate_guess = reinterpret_cast<CostDynamicBase_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4)
                                                           ->GetCandidate_guess();
            if (candidate_guess != 0) {
                value_guess = static_cast<unsigned char>(candidate_guess->Character1_guess()->ApplyRank_guess(
                                                                     entry_guess,
                                                                     entry_guess->GetContextValue_guess(1),
                                                                     entry_guess->GetValue_guess()));
            }
        }

        if (context_guess != 0 && entry_guess->HasContextFlag_guess(1) != 0 &&
            entry_guess->GetContextCount_guess(1) > 0 && context_guess->tally_guess != 0) {
            CostTally_guess* tally_guess = context_guess->tally_guess;
            value_guess += tally_guess->SumScaled_guess(
                reinterpret_cast<CostSource_guess*>(entry_guess),
                reinterpret_cast<LookupService_guess*>(
                    reinterpret_cast<int>(tally_guess) +
                    reinterpret_cast<CostTallyLookupHead_guess*>(tally_guess)
                            ->offset_holder_guess->vbaseOffset_0004_guess +
                    8)
                    ->Find_guess()
                    ->level_11a4_guess);
        }
        if (context_guess != 0 &&
            (entry_guess->HasContextValue_guess(1) != 0 ||
             entry_guess->HasAlternateContextValue_guess(1) != 0) &&
            context_guess->tally_guess != 0) {
            value_guess += reinterpret_cast<CostOwner_guess*>(context_guess->tally_guess)
                               ->CheckQuery_guess(reinterpret_cast<QueryTarget_guess*>(entry_guess));
        }
    } else {
        // An NPC without a primary weapon backstabs for 3.
        value_guess = 3;
    }
    } else {
        return value_guess;
    }

    // Backstab scales with the Backstab skill: damage * (skill * 0.02 + 2).
    return static_cast<unsigned char>(static_cast<int>(
        (static_cast<float>(reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(8)) *
             EQ_GLOBAL(float, 0x006410b8) +
         EQ_GLOBAL(float, 0x006410b4)) *
        static_cast<int>(value_guess)));
}

struct RankTotalsOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual int Apply_guess(int value_guess, int kind_guess);
    virtual ItemInstance_guess* Slot05_guess(int index_guess);
    RankOffset_guess* offset_holder_guess;
    StatSource_guess* source_guess;
    char enabled_guess;
    char pad_000d_guess[3];
    int str_0010_guess;
    int sta_0014_guess;
    int value_0018_guess;
    int dex_001c_guess;
    int intel_0020_guess;
    int agi_0024_guess;
    int wis_0028_guess;
    int armorClass_002c_guess;
    int saveMagic_0030_guess;
    int saveCold_0034_guess;
    int saveFire_0038_guess;
    int savePoison_003c_guess;
    int saveDisease_0040_guess;
    int value_0044_guess;
    int weight_0048_guess;
    int value_004c_guess;
    int value_0050_guess;
    int value_0054_guess;
    int value_0058_guess;
    int value_005c_guess;
    int value_0060_guess;
    int value_0064_guess;
    int value_0068_guess;
    int value_006c_guess;
    int value_0070_guess;
    int value_0074_guess;
    BoundedArray_guess<int, 9> values_0078_guess;
    int value_009c_guess;
    int value_00a0_guess;
    int value_00a4_guess;
    int value_00a8_guess;
    int value_00ac_guess;
    int value_00b0_guess;
    int value_00b4_guess;
    int itemHaste_00b8_guess;
    int value_00bc_guess;
    InventorySlots_guess* Table_guess() {
        return reinterpret_cast<InventorySlots_guess*>(reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
    }
    int Agi_guess();
    void Recalculate_guess();
};

// AGI (Recalculate_guess stores it at +0x24): base (+0x11C8) + items + AGI (SPA 6) + AllStats
// (SPA 159), less (v - 40) / 16 once GetCandidate_guess()->GetValue_guess() passes 55, times
// encum_factor_guess, then the stat cap (Apply_guess kind 2).
// FUNCTION: TITANIUM 0x0041BA05
int RankTotalsOwner_guess::Agi_guess() {
    int total_guess;
    {
        int adjustment_guess = 0;
        if (source_guess != 0 && source_guess->state_guess == 0) {
            CostDynamicBlock_guess* dynamic_guess = reinterpret_cast<CostDynamicBlock_guess*>(
                reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
            CostCandidate_guess* candidate_guess = dynamic_guess->GetCandidate_guess();
            if (candidate_guess->GetValue_guess() > 0x37) {
                int steps_guess = (candidate_guess->GetValue_guess() - 0x28) / 0x10;
                if (steps_guess > 0) {
                    adjustment_guess = -steps_guess;
                }
            }
        }
        int random_guess = reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(0x9f, 1, 0, 1) +
                           reinterpret_cast<CostOwner_guess*>(this)->TotalSpellAffects_guess(6, 1, 0, 1);
        CostDynamicBlock_guess* lookup_block_guess = reinterpret_cast<CostDynamicBlock_guess*>(
            reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 4);
        LookupResult_guess* result_guess = lookup_block_guess->Find_guess();
        total_guess = result_guess->tail_guess.agi_11c8_guess + agi_0024_guess + random_guess +
                      adjustment_guess;
    }
    int scaled_guess = static_cast<int>(
        reinterpret_cast<CostOwner_guess*>(this)->encum_factor_guess() * total_guess);
    return Apply_guess(scaled_guess, 2);
}

// Sums every stat of one entry into the totals; F wraps each raw value.
#define RANK_ADD_ALL_GUESS(s, F) \
    str_0010_guess += F(s->Acc01_guess(1)); \
    sta_0014_guess += F(s->Acc02_guess(1)); \
    value_0018_guess += F(s->Acc03_guess(1)); \
    dex_001c_guess += F(s->Acc04_guess(1)); \
    intel_0020_guess += F(s->Acc05_guess(1)); \
    agi_0024_guess += F(s->Acc06_guess(1)); \
    wis_0028_guess += F(s->Acc07_guess(1)); \
    saveMagic_0030_guess += F(s->Acc08_guess(1)); \
    saveCold_0034_guess += F(s->Acc09_guess(1)); \
    saveFire_0038_guess += F(s->Acc10_guess(1)); \
    savePoison_003c_guess += F(s->Acc11_guess(1)); \
    saveDisease_0040_guess += F(s->Acc12_guess(1)); \
    value_0050_guess += F(s->Acc13_guess(1)); \
    value_0054_guess += F(s->Acc14_guess(1)); \
    value_0058_guess += F(s->Acc15_guess(1)); \
    value_005c_guess += F(s->Acc16_guess(1)); \
    value_0060_guess += F(s->Acc17_guess(1)); \
    value_0064_guess += F(s->Acc18_guess(1)); \
    value_0068_guess += F(s->Acc19_guess(1)); \
    value_006c_guess += F(s->Acc20_guess(1)); \
    value_0070_guess += F(s->Acc22_guess(1)); \
    value_00a0_guess += F(s->Acc21_guess(1)); \
    value_0074_guess += F(s->Acc23_guess(1)); \
    value_00a4_guess += F(s->Acc25_guess(1)); \
    value_00a8_guess += F(s->Acc26_guess(1)); \
    value_00ac_guess += F(s->Acc27_guess(1)); \
    value_00b0_guess += F(s->Acc28_guess(1)); \
    value_00b4_guess += F(s->Acc29_guess(1)); \
    value_00bc_guess += F(s->Acc30_guess(1)); \
    values_0078_guess[0] += F(s->Acc24_guess(10, 1)); \
    values_0078_guess[1] += F(s->Acc24_guess(8, 1)); \
    values_0078_guess[2] += F(s->Acc24_guess(0x15, 1)); \
    values_0078_guess[3] += F(s->Acc24_guess(0x17, 1)); \
    values_0078_guess[4] += F(s->Acc24_guess(0x1a, 1)); \
    values_0078_guess[5] += F(s->Acc24_guess(0x1e, 1)); \
    values_0078_guess[6] += F(s->Acc24_guess(0x26, 1)); \
    values_0078_guess[7] += F(s->Acc24_guess(0x34, 1)); \
    values_0078_guess[8] += F(s->Acc24_guess(0x4a, 1));
#define RANK_RAW_GUESS(v) (v)
#define RANK_APPLY_GUESS(v)                                                                 \
    reinterpret_cast<CostTotalOwner_guess*>(this)->ApplyRank_guess(                         \
        reinterpret_cast<ItemInstance_guess*>(stats_guess), v,                                 \
        source_guess->Adjust_guess(reinterpret_cast<ItemInstance_guess*>(stats_guess)->GetValue_guess()))

struct SkillActor_guess {
    char padding_0000_guess[0xad];
    unsigned char flag_00ad_guess;
    char padding_00ae_guess[0x5e];
    unsigned int ready_time_010c_guess;
    char padding_0110_guess[0x10];
    unsigned int time_0120_guess;
    char padding_0124_guess[4];
    int value_0128_guess;
    char padding_012c_guess[0x26];
    unsigned char flag_0152_guess;
    unsigned char value_0153_guess;
    char padding_0154_guess[8];
    int value_015c_guess;
};

struct SkillPlayer_guess : EQPlayer {
    SkillActor_guess* Actor_guess() {
        return static_cast<SkillActor_guess*>(pActorInfo);
    }
    // EXTERNAL: TITANIUM 0x00483556 SkillPlayer_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047C10D SkillPlayer_guess::SetHideMode_guess
    void SetHideMode_guess(unsigned char mode_guess);
    // EXTERNAL: TITANIUM 0x0047994F SkillPlayer_guess::NotOnSameDeity_guess
    int NotOnSameDeity_guess(EQPlayer* other_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0047ED9C SkillPlayer_guess::CanIHit_guess
    char CanIHit_guess(EQPlayer* other_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x00480409 SkillPlayer_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
    // EXTERNAL: TITANIUM 0x0047C08E SkillPlayer_guess::GetObject_guess
    ChargeSink_guess* GetObject_guess();
    // EXTERNAL: TITANIUM 0x0048083A SkillPlayer_guess::SetStat_guess
    void SetStat_guess(int value_guess, const char* text_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0048297B SkillPlayer_guess::DoAttack
    void DoAttack(int kind_guess, unsigned char skill_guess, EQPlayer* target_guess);
};

struct SkillDisplay_guess {
    char padding_0000_guess[0x148];
    unsigned int time_0148_guess;
    // EXTERNAL: TITANIUM 0x00439D16 SkillDisplay_guess::PlayerDistance_guess
    float PlayerDistance_guess(EQPlayer* first_guess, EQPlayer* second_guess, float extra_guess);
};

struct SkillInfo_guess {
    int unused_guess;
    int reuse_time_guess;
    char padding_0008_guess[2];
    unsigned char kind_000a_guess;
};

struct SkillCharInfo_guess {
    char padding_0000_guess[0x10];
    BoundedArray_guess<ItemInstance_guess*, 31> items_guess;
    char padding_008c_guess[0xee4];
    BoundedArray_guess<int, 100> skills_guess;
    BoundedArray_guess<int, 25> innates_guess;
};

struct SkillItem_guess {
    // EXTERNAL: TITANIUM 0x005E0F00 SkillItem_guess::GetName_guess
    const char* GetName_guess();
};

struct SkillPcHead_guess {
    char padding_0000_guess[0xc280];
    // EXTERNAL: TITANIUM 0x005ED860 SkillPcHead_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED820 SkillPcHead_guess::FUN_005ed820_guess
    void FUN_005ed820_guess(int value_guess);
};

struct SkillPc_guess : SkillPcHead_guess, NotifyOwner_guess {
    MessageObject_guess* Messages_guess() {
        return reinterpret_cast<MessageObject_guess*>(static_cast<NotifyOwner_guess*>(this));
    }
};

struct SkillVBase_guess : EQ_CharacterProfile_guess {
    virtual void VSlot00_guess();
    virtual void VSlot01_guess();
    virtual void VSlot02_guess();
    virtual void VSlot03_guess();
    virtual void VSlot04_guess();
    virtual void VSlot05_guess();
    virtual void VSlot06_guess();
    virtual void VSlot07_guess();
    virtual void VSlot08_guess();
    virtual void VSlot09_guess();
    virtual void VSlot0a_guess();
    virtual void VSlot0b_guess();
    virtual void VSlot0c_guess();
    virtual void VSlot0d_guess();
    virtual void VSlot0e_guess();
    virtual void VSlot0f_guess();
    virtual SkillPc_guess* GetOwner_guess();
    char padding_000c_guess[0xf0];
    unsigned char field_00fc_guess;
    char padding_00fd_guess[7];
    unsigned char stand_state_0104_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 SkillVBase_guess::GetItem_guess
    SkillItem_guess* GetItem_guess(unsigned int index_guess);
};

struct SkillUserPrefix_guess {
    virtual void PSlot00_guess();
};

struct SkillSpellTarget_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    SkillSpellTarget_guess() : first_guess(0), second_guess(-1), third_guess(-1), fourth_guess(0) {
    }
};

struct SkillUser_guess : SkillUserPrefix_guess, virtual SkillVBase_guess {
    SkillPlayer_guess* player_guess;
    SkillVBase_guess* Base_guess() {
        return this;
    }
    // EXTERNAL: TITANIUM 0x0040E934 SkillUser_guess::FindBuffWithEffect_guess
    void* FindBuffWithEffect_guess(int id_guess, int* index_guess);
    // EXTERNAL: TITANIUM 0x004106A3 SkillUser_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int affect_guess, int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00411F3D SkillUser_guess::ApplySpell_guess
    void ApplySpell_guess(int kind_guess, int spell_guess, int zero_guess, SkillSpellTarget_guess target_guess,
                          int last_guess);
    void UseSkill_guess(unsigned char skill_guess, EQPlayer* unused_guess);
};

struct SkillSoundObject_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A SkillSoundObject_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049994C SkillSoundObject_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value_guess);
};

struct SkillEverQuest_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 SkillEverQuest_guess::trimName_guess
    const char* trimName_guess(const char* name_guess);
};

struct SkillAttackPacket_guess {
    unsigned int target_id_guess;
    unsigned int source_id_guess;
    int skill_value_guess;
    unsigned char unknown_000c_guess;
    char padding_000d_guess[3];
    int unknown_0010_guess;
    char name_guess[0x800];
};

struct SkillRecord10_guess {
    unsigned int source_id_guess;
    unsigned int target_id_guess;
    int skill_value_guess;
    unsigned char unknown_000c_guess;
};

struct SkillRecord0c_guess {
    unsigned int source_id_guess;
    unsigned int value_guess;
    unsigned char unknown_0008_guess;
};

struct SkillRecord08_guess {
    unsigned int target_id_guess;
    int value_guess;
};

// EXTERNAL: TITANIUM 0x00469DD8 do_inspect_guess
void __cdecl do_inspect_guess(int first_guess, int second_guess);
// EXTERNAL: TITANIUM 0x00469E6C do_open_guess
void __cdecl do_open_guess(int first_guess, int second_guess);
// EXTERNAL: TITANIUM 0x004649B1 SkillMessage_guess
void __cdecl SkillMessage_guess(NotifyOwner_guess* owner_guess, int id_guess, int color_guess, int zero_guess);
// EXTERNAL: TITANIUM 0x0046DC2E SkillFormatMessage_guess
void __cdecl SkillFormatMessage_guess(SkillUser_guess* user_guess, int id_guess, int color_guess, const char* a1,
                                      const char* a2, const char* a3, const char* a4, const char* a5,
                                      const char* a6, const char* a7, const char* a8, const char* a9,
                                      const char* a10);
// EXTERNAL: TITANIUM 0x0046595A get_melee_range
float __cdecl get_melee_range(EQPlayer* first_guess, EQPlayer* second_guess);
// EXTERNAL: TITANIUM 0x00464E25 GetTextureSlot_guess
int __cdecl GetTextureSlot_guess(int slot_guess);

#define g_skillTarget_guess EQ_GLOBAL(SkillPlayer_guess*, 0x00905D04)
#define g_skillSelf_guess EQ_GLOBAL(SkillPlayer_guess*, 0x00905CE4)
#define g_skillOther_guess EQ_GLOBAL(SkillPlayer_guess*, 0x00905CF8)
#define g_skillPc_guess EQ_GLOBAL(SkillPc_guess*, 0x00905D00)
#define g_skillDisplay_guess EQ_GLOBAL(SkillDisplay_guess*, 0x00905D24)
#define g_skillEverQuest_guess EQ_GLOBAL(SkillEverQuest_guess*, 0x00988DF0)
#define g_skillInfo_guess EQ_ARRAY(SkillInfo_guess*, 0x00851200)
#define g_skillTimers_guess EQ_ARRAY(int, 0x0092447C)
#define g_skillReady_guess EQ_ARRAY(unsigned char, 0x0092460C)
#define g_skillSoundObject_guess EQ_GLOBAL(SkillSoundObject_guess, 0x00923770)
#define g_skillState_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_skillStateTimer_guess EQ_GLOBAL(int, 0x00923CD4)
#define g_skillStartY_guess EQ_GLOBAL(int, 0x009239C4)
#define g_skillStartX_guess EQ_GLOBAL(int, 0x009239C8)
#define g_skillStartZ_guess EQ_GLOBAL(int, 0x009239CC)
#define g_skillServerMode_guess EQ_GLOBAL(int, 0x00900478)
#define g_skillAttackReady_guess EQ_GLOBAL(unsigned char, 0x00924672)
#define g_skillConnection_guess EQ_ARRAY(char, 0x00905CA0)

// Skill button or ability key (EQ_Character::UseSkill in the earlier sibling decomp). Combat skills
// (table kind 2) and Bash or Slam (111, innate 11) attack through DoAttack; Bash needs a shield, a two-hander with
// TwoHandBash (SPA 226) or primary item 11050, 10099 or 14383. Other skills arm their reuse timer (0x92447C, less
// ReduceSkillTimer, SPA 227, in seconds; Begging and Pick Pockets share it) and send their OP_; Bind Wound and Forage
// failures restore it. Against an LDoN chest (class 62) Disarm Traps, Pick Lock and Sense Traps send 0x41B9, 0x069D
// and 0x07A8 (not in EQEmu's list; Pick Lock does nothing on other targets). Tracking sends 0x6177.
// On a mount (or SummonHorse, SPA 113) only 11 skills work. 105 and 107 cast spells 88 and 87 (Harm
// Touch and Lay on Hands in spells_us.txt; innates 5 and 7); 114 and 115 are /inspect and /open.
// FUNCTION: TITANIUM 0x0041F4A0
// @early-stop: budget, structural ndiff=754
void SkillUser_guess::UseSkill_guess(unsigned char skill_guess, EQPlayer* unused_guess) {
    SkillRecord10_guess record10_guess;
    SkillRecord0c_guess record0c_guess;
    SkillRecord08_guess record08_guess;
    unsigned int target_id_guess;
    HideModeRecord_guess hide_guess;
    int saved_guess;
    SkillAttackPacket_guess packet_guess;
    char text_guess[256];
    char direction_guess[32];
    memset(&packet_guess, 0, sizeof(packet_guess));
    if (player_guess == 0) {
        return;
    }
    if (reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(0) < 1) {
        return;
    }
    if (skill_guess < 100 && reinterpret_cast<LookupGate_guess*>(this)->HasSkillChecked_guess(skill_guess) == 0) {
        return;
    }
    if (player_guess->StandState == 'f') {
        pEverQuest->dsp_chat(pStringTable->getString(0x3050, 0), 0xd, true);
        return;
    }
    if (player_guess->Actor_guess() != 0 &&
        // Mounted (a ride at +0x15C or a SummonHorse buff): only these skills work, others say 0x3069.
        (player_guess->Actor_guess()->value_015c_guess != 0 || FindBuffWithEffect_guess(0x71, 0) != 0)) {
        switch (skill_guess) {
        case SkillTracking:
        case SkillBash:
        case SkillDisarm:
        case SkillKick:
        case SkillMend:
        case SkillSenseHeading:
        case SkillFishing:
        case SkillIntimidation:
        case SkillTaunt:
        case 0x69:
        case 0x6b:
            break;
        default:
            pEverQuest->dsp_chat(pStringTable->getString(0x3069, 0), 0xd, true);
            return;
        }
    }
    SkillPlayer_guess* target_guess = g_skillTarget_guess;
    // Ids above 100 are abilities: Harm Touch (0x69) and Lay on Hands (0x6B) are handled at the end. Combat
    // skills (kind 2) and the innate slam (0x6F) become an attack; bash needs a shield, a two-hand-bash
    // weapon (TwoHandBash with item types 1, 4, 35) or one of three items, else 0x306A.
    if (skill_guess != 0x6b && skill_guess != 0x69) {
        if (skill_guess == 0x72) {
            do_inspect_guess(0, 0);
        } else if (skill_guess == 0x73) {
            do_open_guess(0, 0);
        } else if (skill_guess == 0x6f || g_skillInfo_guess[skill_guess]->kind_000a_guess == 2) {
            g_skillAttackReady_guess = 0;
            switch (skill_guess) {
            case SkillKick:
            case SkillBackstab:
            case SkillDragonPunch:
            case SkillEagleStrike:
            case SkillFlyingKick:
            case SkillRoundKick:
            case SkillTigerClaw:
            case SkillFrenzy:
                break;
            case SkillBash:
                if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary] != 0 && player_guess != 0 && player_guess->Actor_guess() != 0 &&
                    TotalSpellAffects_guess(SPA_TwoHandBash, 1, 0, 1) != 0) {
                    if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetValue_guess() == 1 ||
                        reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetValue_guess() == 4 ||
                        reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetValue_guess() == 0x23) {
                        player_guess->DoAttack(100, 10, g_skillTarget_guess);
                        return;
                    }
                }
                if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Secondary] != 0 && reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Secondary]->GetItemClass_guess() == 0 &&
                    reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Secondary]->GetValue_guess() == 8) {
                    break;
                }
                if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary] != 0) {
                    if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetItemId_guess() == 0x2b2a ||
                        reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetItemId_guess() == 0x2773 ||
                        reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Primary]->GetItemId_guess() == 0x382f) {
                        break;
                    }
                }
                pEverQuest->dsp_chat(pStringTable->getString(0x306a, 0), 0x10e, true);
                return;
            case 0x6f:
                if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->innates_guess[11] == 0xff) {
                    return;
                }
                player_guess->DoAttack(100, 10, g_skillTarget_guess);
                return;
            default:
                return;
            }
            player_guess->DoAttack(100, skill_guess, g_skillTarget_guess);
            return;
        }
        // Reuse timers: the skill must be ready, ReduceSkillTimer shortens the wait, begging and pick pockets
        // share one timer, mend and hide wait their full reuse time.
        saved_guess = g_skillTimers_guess[skill_guess];
        if ((skill_guess != SkillSneak || player_guess->Sneak == 0) &&
            (skill_guess != SkillHide || g_unknownFlag_guess == 0)) {
            if (g_skillReady_guess[skill_guess] == 0) {
                return;
            }
            int modifier_guess = TotalSpellAffects_guess(SPA_ReduceSkillTimer, 1, skill_guess, 1);
            if (skill_guess != SkillMend && skill_guess != SkillHide) {
                if (skill_guess != SkillBegging && skill_guess != SkillPickPockets) {
                    g_skillTimers_guess[skill_guess] = g_skillDisplay_guess->time_0148_guess - modifier_guess * 1000;
                } else {
                    int ready_time_guess = g_skillDisplay_guess->time_0148_guess - modifier_guess * 1000;
                    g_skillTimers_guess[0x30] = ready_time_guess;
                    g_skillTimers_guess[0x43] = ready_time_guess;
                    g_skillReady_guess[0x30] = 0;
                    g_skillReady_guess[0x43] = 0;
                }
            } else {
                g_skillTimers_guess[skill_guess] = g_skillInfo_guess[skill_guess]->reuse_time_guess -
                                                   modifier_guess * 1000 + g_skillDisplay_guess->time_0148_guess;
            }
            g_skillReady_guess[skill_guess] = 0;
        }
        switch (skill_guess) {
        // Each skill sends its own request; feign death (OP_FeignDeath 0x7489), bind wound (OP_Bind_Wound
        // 0x601D), pick pockets (OP_PickPocket 0x2AD8) and begging (OP_Begging 0x13E7) carry data, hide and
        // sneak also change our appearance (OP_SpawnAppearance 0x7C32).
        case SkillFeignDeath:
            player_guess->ChangePosition_guess(0x73);
            if (player_guess == g_skillSelf_guess) {
                g_skillSoundObject_guess.SetAutoAttack_guess(0);
                g_skillSoundObject_guess.SetAutoFire_guess(0);
            }
            record0c_guess.source_id_guess = player_guess->SpawnID;
            record0c_guess.value_guess = g_lastDamageSource_guess;
            record0c_guess.unknown_0008_guess = 0;
            EQSendMessage(g_skillConnection_guess, OP_FeignDeath, &record0c_guess, 0xc, 1);
            return;
        case SkillDisarmTraps:
            if (g_skillTarget_guess != 0 && g_skillTarget_guess->Class == Class_LDoNTreasure) {
                EQSendMessage(g_skillConnection_guess, 0x41b9, 0, 0, 1);
            } else {
                EQSendMessage(g_skillConnection_guess, OP_DisarmTraps, 0, 0, 1);
            }
            return;
        case SkillDisarm:
            if (g_skillTarget_guess == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3080, 0), 0x10e, true);
                return;
            }
            if (g_skillTarget_guess == player_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3081, 0), 0x10e, true);
                return;
            }
            if (g_skillDisplay_guess->PlayerDistance_guess(player_guess, g_skillTarget_guess, 0.0f) > 15.0f) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3082, 0), 0x10e, true);
                return;
            }
            if (g_skillTarget_guess->Type > 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3083, 0), 0x10e, true);
                return;
            }
            if (!player_guess->CanIHit_guess(g_skillTarget_guess, 0.0f)) {
                return;
            }
            if (player_guess->HideMode != 0) {
                int index_guess;
                player_guess->SetHideMode_guess(0);
                hide_guess.spawn_id_guess = static_cast<unsigned short>(player_guess->SpawnID);
                hide_guess.type_guess = 3;
                hide_guess.state_guess = player_guess->HideMode;
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0xc, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x1c, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x1d, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x13a, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x13b, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x13c, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x5e, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                g_skillPc_guess->RemovePCAffect_guess(g_skillPc_guess->FindBuffWithEffect_guess(0x138, &index_guess));
                if (index_guess != -1) {
                    g_skillPc_guess->Messages_guess()->NotifyPCAffectChange_guess(index_guess, 1);
                }
                EQSendMessage(g_skillConnection_guess, OP_SpawnAppearance, &hide_guess, 8, 1);
                g_skillSelf_guess->UpdatePlayerVisibility_guess();
            }
            record10_guess.source_id_guess = player_guess->SpawnID;
            record10_guess.target_id_guess = g_skillTarget_guess->SpawnID;
            record10_guess.skill_value_guess = reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->skills_guess[SkillDisarm];
            record10_guess.unknown_000c_guess = 0xff;
            EQSendMessage(g_skillConnection_guess, OP_Disarm, &record10_guess, 0x10, 1);
            return;
        case SkillBindWound:
            if (g_skillState_guess == SkillBindWound) {
                return;
            }
            if (target_guess == 0 || target_guess->Type != 0) {
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x90, 0x10e, 0);
            } else if (g_skillServerMode_guess == 4 && player_guess->NotOnSameDeity_guess(target_guess, 0) != 0) {
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x91, 0x10e, 0);
            } else if (!reinterpret_cast<InventoryView_guess*>(this)->FindItemByType_guess(0x12, 0, 0)) {
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x92, 0x10e, 0);
            } else {
                if (target_guess->Type != 0) {
                    return;
                }
                if (g_skillDisplay_guess->PlayerDistance_guess(player_guess, target_guess, 0.0f) < 15.0f) {
                    ++g_noticeA_guess;
                    ++g_noticeB_guess;
                    record08_guess.target_id_guess = target_guess->SpawnID;
                    record08_guess.value_guess = 0;
                    EQSendMessage(g_skillConnection_guess, OP_Bind_Wound, &record08_guess, 8, 1);
                    if (player_guess->StandState == 'd') {
                        player_guess->ChangePosition_guess(0x69);
                    }
                    if (target_guess == g_skillSelf_guess) {
                        strcpy(text_guess, pStringTable->getString(0x3094, 0));
                    } else {
                        FormatText_guess(text_guess, 0x3095, target_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    pEverQuest->dsp_chat(text_guess, 0x10e, true);
                    return;
                }
                SkillFormatMessage_guess(this, 0x1a4, 0x10e, target_guess->Name, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            g_skillTimers_guess[skill_guess] = saved_guess;
            g_skillReady_guess[skill_guess] = 1;
            return;
        case SkillForage:
            if (Base_guess()->stand_state_0104_guess != 'd') {
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x95, 0x10e, 0);
            } else if (g_valueCheckDisabled_guess != 0) {
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x94, 0x10e, 0);
            } else {
                EQSendMessage(g_skillConnection_guess, OP_Forage, 0, 0, 1);
                return;
            }
            g_skillTimers_guess[skill_guess] = saved_guess;
            g_skillReady_guess[skill_guess] = 1;
            return;
        case SkillPickLock:
            if (g_skillTarget_guess != 0 && g_skillTarget_guess->Class == Class_LDoNTreasure) {
                EQSendMessage(g_skillConnection_guess, 0x69d, 0, 0, 1);
            }
            return;
        case SkillMend:
            EQSendMessage(g_skillConnection_guess, OP_Mend, 0, 0, 1);
            return;
        case SkillHide:
            if (g_skillState_guess == SkillHide) {
                g_unknownFlag_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x307f, 0), 0x10e, true);
                if (player_guess != 0 && player_guess->Type == 0) {
                    Base_guess()->GetOwner_guess()->FUN_005ed860_guess(0);
                }
                reinterpret_cast<CharacterObject_guess*>(this)->UpdateInvisibility_guess();
                g_skillState_guess = -1;
                return;
            }
            if (g_valueCheckDisabled_guess != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3087, 0), 0x10e, true);
                return;
            }
            {
                double limit_guess = 0.001;
                int value_guess = reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0x1d);
                if (value_guess > 0x32) {
                    limit_guess = (value_guess - 0x32) * 0.001 * 0.5;
                    if (limit_guess > 0.5) {
                        limit_guess = 0.5;
                    }
                }
                if (player_guess->SpeedY < -limit_guess || player_guess->SpeedY > limit_guess ||
                    player_guess->SpeedX < -limit_guess || player_guess->SpeedX > limit_guess ||
                    player_guess->SpeedZ < -limit_guess || player_guess->SpeedZ > limit_guess) {
                    int chance_guess = TotalSpellAffects_guess(SPA_NimbleEvasion, 1, 0, 1);
                    if (RandomRange_guess(1, 100) >= chance_guess) {
                        pEverQuest->dsp_chat(pStringTable->getString(0x3088, 0), 0x10e, true);
                        return;
                    }
                }
            }
            g_skillState_guess = SkillHide;
            g_skillStateTimer_guess = 0;
            g_skillStartY_guess = static_cast<int>(player_guess->Y);
            g_skillStartX_guess = static_cast<int>(player_guess->X);
            g_skillStartZ_guess = static_cast<int>(player_guess->Z);
            g_unknownFlag_guess = 1;
            if (player_guess != 0 && player_guess->Type == 0) {
                Base_guess()->GetOwner_guess()->FUN_005ed860_guess(1);
            }
            EQSendMessage(g_skillConnection_guess, OP_Hide, 0, 0, 1);
            pEverQuest->dsp_chat(pStringTable->getString(0x3089, 0), 0x10e, true);
            reinterpret_cast<CharacterObject_guess*>(this)->UpdateInvisibility_guess();
            return;
        // Sense heading: one of eight compass words (0x308B-0x3092) from our heading, after a skill check.
        case SkillSenseHeading: {
            int heading_guess = static_cast<int>(player_guess->Heading);
            int roll_guess = RandomRange_guess(1, 100);
            if (roll_guess <= 7) {
                roll_guess = 0;
            }
            if (roll_guess <= reinterpret_cast<CostOwner_guess*>(this)->Skill_guess(0x28) &&
                roll_guess <= 0x5f) {
                if (pinstCCompassWnd_guess != 0) {
                    pinstCCompassWnd_guess->Reset_guess();
                }
                strcpy(direction_guess, "");
                if (heading_guess >= 0x1e0) {
                    strcpy(direction_guess, pStringTable->getString(0x308b, 0));
                } else if (heading_guess > 0x1a0) {
                    strcpy(direction_guess, pStringTable->getString(0x308c, 0));
                } else if (heading_guess > 0x160) {
                    strcpy(direction_guess, pStringTable->getString(0x308d, 0));
                } else if (heading_guess > 0x120) {
                    strcpy(direction_guess, pStringTable->getString(0x308e, 0));
                } else if (heading_guess > 0xe0) {
                    strcpy(direction_guess, pStringTable->getString(0x308f, 0));
                } else if (heading_guess > 0xa0) {
                    strcpy(direction_guess, pStringTable->getString(0x3090, 0));
                } else if (heading_guess > 0x60) {
                    strcpy(direction_guess, pStringTable->getString(0x3091, 0));
                } else if (heading_guess > 0x20) {
                    strcpy(direction_guess, pStringTable->getString(0x3092, 0));
                } else if (heading_guess >= 0) {
                    strcpy(direction_guess, pStringTable->getString(0x308b, 0));
                }
                FormatText_guess(text_guess, 0x3093, direction_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(text_guess, 0x10e, true);
                EQSendMessage(g_skillConnection_guess, OP_SenseHeading, 0, 0, 1);
                return;
            }
            pEverQuest->dsp_chat(pStringTable->getString(0x308a, 0), 0x10e, true);
            return;
        }
        case SkillFishing:
            if (player_guess->Actor_guess()->flag_0152_guess != 0) {
                if (player_guess->Type != 0) {
                    return;
                }
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x9c, 0x10e, 0);
                return;
            }
            if (player_guess->Actor_guess()->flag_00ad_guess != 0) {
                if (player_guess->Type != 0) {
                    return;
                }
                SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                SkillMessage_guess(owner_guess, 0x9d, 0x10e, 0);
                return;
            }
            if (player_guess->Type == 0) {
                if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->items_guess[InvSlot_Cursor] != 0) {
                    SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    SkillMessage_guess(owner_guess, 0x9e, 0x10e, 0);
                    return;
                }
                if (g_valueCheckDisabled_guess != 0) {
                    SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    SkillMessage_guess(owner_guess, 0x9f, 0x10e, 0);
                    return;
                }
                int slot_guess;
                int sub_guess;
                if (!reinterpret_cast<InventoryView_guess*>(this)->FindItemByType_guess(0x24, &slot_guess, &sub_guess)) {
                    SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    SkillMessage_guess(owner_guess, 0xa0, 0x10e, 0);
                    return;
                }
                if (sub_guess == -1 && (slot_guess == InvSlot_Primary || slot_guess == InvSlot_Secondary)) {
                    if (!reinterpret_cast<InventoryView_guess*>(this)->FindItemByType_guess(0x25, 0, 0)) {
                        SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                        SkillMessage_guess(owner_guess, 0xa2, 0x10e, 0);
                        return;
                    }
                    if (player_guess != 0) {
                        player_guess->SetStat_guess(GetTextureSlot_guess(slot_guess),
                                                    Base_guess()->GetItem_guess(slot_guess)->GetName_guess(), 0);
                    }
                    SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    SkillMessage_guess(owner_guess, 0xa3, 0x10e, 0);
                    g_skillState_guess = SkillFishing;
                    g_skillStateTimer_guess = 0;
                    g_skillStartY_guess = static_cast<int>(player_guess->Y);
                    g_skillStartX_guess = static_cast<int>(player_guess->X);
                    g_skillStartZ_guess = static_cast<int>(player_guess->Z);
                } else {
                    SkillPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    SkillMessage_guess(owner_guess, 0xa1, 0x10e, 0);
                    return;
                }
            }
            if (Base_guess()->stand_state_0104_guess == 'd') {
                ChargeRecord_guess record_guess;
                record_guess.spawn_id_guess = static_cast<unsigned short>(player_guess->SpawnID);
                record_guess.value_guess = 5;
                record_guess.type_guess = 5;
                player_guess->GetObject_guess()->Notify_guess(record_guess.value_guess, 1, 0, 0.5f, 1);
                EQSendMessage(g_skillConnection_guess, OP_Animation, &record_guess, 4, 1);
            }
            player_guess->Actor_guess()->time_0120_guess = GetCurrentTime_guess() + 2000;
            player_guess->Actor_guess()->flag_0152_guess = 1;
            EQSendMessage(g_skillConnection_guess, OP_Fishing, 0, 0, 1);
            return;
        case SkillTracking:
            if (pinstCTrackingWnd_guess->dShow == 0) {
                pinstCTrackingWnd_guess->Show(1, 1);
            } else {
                pinstCTrackingWnd_guess->RequestTrackList_guess();
            }
            EQSendMessage(g_skillConnection_guess, 0x6177, 0, 0, 1);
            return;
        case SkillPickPockets: {
            if (g_skillTarget_guess == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3075, 0), 0x10e, true);
                return;
            }
            if (g_skillTarget_guess->GM != 0) {
                return;
            }
            unsigned char type_guess = g_skillTarget_guess->Type;
            if (type_guess >= 2) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3076, 0), 0x10e, true);
                return;
            }
            if (Base_guess()->field_00fc_guess == 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3077, 0), 0x10e, true);
                return;
            }
            if (g_valueCheckDisabled_guess != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3078, 0), 0x10e, true);
                return;
            }
            if (type_guess == 0) {
                if (g_skillTarget_guess == player_guess) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3079, 0), 0x10e, true);
                    return;
                }
                if (g_skillTarget_guess->PvPFlag == 0 && g_skillServerMode_guess != 4) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x307a, 0), 0x10e, true);
                    return;
                }
                if (player_guess->PvPFlag == 0 && g_skillServerMode_guess != 4) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x307b, 0), 0x10e, true);
                    return;
                }
            }
            if (g_skillServerMode_guess == 4 && type_guess == 0) {
                if (g_skillTarget_guess->NotOnSameDeity_guess(player_guess, 0) == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x307c, 0), 0x10e, true);
                    return;
                }
                unsigned char level_guess = g_skillTarget_guess->Level;
                int difference_guess = level_guess - player_guess->Level;
                if (difference_guess < -5 || difference_guess > 5 || level_guess < 6) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x307d, 0), 0x10e, true);
                    return;
                }
            }
            if (g_skillDisplay_guess->PlayerDistance_guess(player_guess, g_skillTarget_guess, 0.0f) > 15.0f) {
                pEverQuest->dsp_chat(pStringTable->getString(0x307e, 0), 0x10e, true);
                return;
            }
            packet_guess.target_id_guess = g_skillTarget_guess->SpawnID;
            packet_guess.source_id_guess = player_guess->SpawnID;
            packet_guess.skill_value_guess = reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->skills_guess[SkillPickPockets];
            packet_guess.unknown_000c_guess = 0xff;
            packet_guess.unknown_0010_guess = 0;
            strcpy(packet_guess.name_guess, "");
            ++g_noticeB_guess;
            EQSendMessage(g_skillConnection_guess, OP_PickPocket, &packet_guess, 0x12, 1);
            Base_guess()->GetOwner_guess()->RemoveInvisibility_guess(0);
            return;
        }
        case SkillSneak:
            if (player_guess->Sneak != 0) {
                player_guess->Sneak = 0;
                if (player_guess != 0 && player_guess->Type == 0) {
                    Base_guess()->GetOwner_guess()->FUN_005ed820_guess(0);
                }
                hide_guess.spawn_id_guess = static_cast<unsigned short>(player_guess->SpawnID);
                hide_guess.type_guess = 0xf;
                hide_guess.state_guess = 0;
                EQSendMessage(g_skillConnection_guess, OP_SpawnAppearance, &hide_guess, 8, 1);
                pEverQuest->dsp_chat(pStringTable->getString(0x3032, 0), 0x10e, true);
                return;
            }
            if (g_valueCheckDisabled_guess != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3084, 0), 0x10e, true);
            } else {
                EQSendMessage(g_skillConnection_guess, OP_Sneak, 0, 0, 1);
                pEverQuest->dsp_chat(pStringTable->getString(0x3086, 0), 0x10e, true);
            }
            return;
        case SkillSenseTraps:
            if (g_skillTarget_guess != 0 && g_skillTarget_guess->Class == Class_LDoNTreasure) {
                EQSendMessage(g_skillConnection_guess, 0x7a8, 0, 0, 1);
            } else {
                EQSendMessage(g_skillConnection_guess, OP_SenseTraps, 0, 0, 1);
            }
            return;
        case SkillTaunt: {
            if (g_skillTarget_guess == 0 || g_skillTarget_guess->Type != 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x306b, 0), 0x10e, true);
                return;
            }
            float distance_guess = g_skillDisplay_guess->PlayerDistance_guess(player_guess, g_skillTarget_guess, 0.0f);
            if (get_melee_range(player_guess, g_skillTarget_guess) < distance_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x182, 0), 0x10e, true);
                return;
            }
            if (g_skillTarget_guess->IsABoat != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x306c, 0), 0x10e, true);
                return;
            }
            FormatText_guess(text_guess, 0x306d, g_skillEverQuest_guess->trimName_guess(g_skillTarget_guess->Name),
                             0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(text_guess, 0x10e, true);
            target_id_guess = g_skillTarget_guess->SpawnID;
            EQSendMessage(g_skillConnection_guess, OP_Taunt, &target_id_guess, 4, 1);
            return;
        }
        case SkillIntimidation:
            if (g_skillTarget_guess == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x306e, 0), 0x10e, true);
                player_guess->Actor_guess()->value_0128_guess = 0;
                player_guess->Actor_guess()->value_0153_guess = 0;
                return;
            }
            if (g_skillTarget_guess != g_skillSelf_guess && g_skillTarget_guess != g_skillOther_guess) {
                if (g_skillSelf_guess->StandState != 'd') {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3070, 0), 0x10e, true);
                    player_guess->Actor_guess()->value_0128_guess = 0;
                    player_guess->Actor_guess()->value_0153_guess = 0;
                } else {
                    player_guess->Actor_guess()->value_0153_guess = 6;
                    EQSendMessage(g_skillConnection_guess, OP_InstillDoubt, 0, 0, 1);
                }
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x3193, 0), 0x10e, true);
                player_guess->Actor_guess()->value_0128_guess = 0;
                player_guess->Actor_guess()->value_0153_guess = 0;
            }
            return;
        case SkillBegging:
            if (g_skillTarget_guess == 0 || g_skillTarget_guess->Type != 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3071, 0), 0x10e, true);
                return;
            }
            if (g_valueCheckDisabled_guess != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3072, 0), 0x10e, true);
                return;
            }
            if (g_skillDisplay_guess->PlayerDistance_guess(player_guess, g_skillTarget_guess, 0.0f) > 15.0f) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3073, 0), 0x10e, true);
                return;
            }
            if (player_guess->HideMode != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3074, 0), 0x10e, true);
                return;
            }
            packet_guess.target_id_guess = g_skillTarget_guess->SpawnID;
            packet_guess.source_id_guess = player_guess->SpawnID;
            packet_guess.skill_value_guess = reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->skills_guess[SkillBegging];
            packet_guess.unknown_000c_guess = 0xff;
            packet_guess.unknown_0010_guess = 0;
            strcpy(packet_guess.name_guess, "");
            ++g_noticeB_guess;
            EQSendMessage(g_skillConnection_guess, OP_Begging, &packet_guess, 0x12, 1);
            return;
        }
    } else {
        switch (skill_guess) {
        case 0x6b:
            if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->innates_guess[7] == 0xff) {
                return;
            }
            if (g_noticeB_guess != 0) {
                return;
            }
            if (g_noticeA_guess != 0) {
                return;
            }
            if (g_skillDisplay_guess->time_0148_guess < player_guess->Actor_guess()->ready_time_010c_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2efd, 0), 0x10e, true);
                return;
            }
            if (target_guess == 0) {
                return;
            }
            if (target_guess->Type > 1) {
                return;
            }
            {
                SkillSpellTarget_guess spell_target_guess;
                // Lay on Hands (innate 7) and, below, Harm Touch (innate 5) cast spells 87 and 88 from
                // ability slot 9 on a player or NPC target once the ability timer allows (0x2EFD).
                ApplySpell_guess(9, 0x57, 0, spell_target_guess, 0);
            }
            return;
        case 0x69:
            if (reinterpret_cast<SkillCharInfo_guess*>(Base_guess()->GetCharInfo2())->innates_guess[5] == 0xff) {
                return;
            }
            if (g_noticeB_guess != 0) {
                return;
            }
            if (g_noticeA_guess != 0) {
                return;
            }
            if (g_skillDisplay_guess->time_0148_guess < player_guess->Actor_guess()->ready_time_010c_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2efd, 0), 0x10e, true);
                return;
            }
            if (target_guess == 0) {
                return;
            }
            if (target_guess->Type > 1) {
                return;
            }
            {
                SkillSpellTarget_guess spell_target_guess;
                ApplySpell_guess(9, 0x58, 0, spell_target_guess, 0);
            }
            return;
        }
    }
}


// Fall damage: d = `value_guess` + 0.01 * +0x48 - 1.5, damage = k * d * d (k at 0x6410C8), 20000 from d 9.
// Safe Fall (39) takes off the skill plus ReduceFallDamage (SPA 228) percent of it and sends
// OP_SafeFallSuccess. Under 200 is ignored while the actor's linked_entity_guess is set, and all of it when
// 0x905CC0's Check_guess(0x924470) is true (probably a zone flag).
// Applied through TakeDamage_guess as type 252.
// FUNCTION: TITANIUM 0x00420DEC
// @early-stop: budget, structural ndiff=5
int CostOwner_guess::TakeFallDamage_guess(float value_guess) {
    int result_guess = 0;
    DamageAdjustment_guess record_guess;
    record_guess.flags_guess = 0;

    float adjusted_guess = static_cast<float>(value_0048_guess) * 0.01f + value_guess - 1.5f;
    if (adjusted_guess >= 9.0f) {
        result_guess = 20000;
    } else if (adjusted_guess > 0.0f) {
            result_guess = static_cast<int>(EQ_GLOBAL(float, 0x006410C8) * adjusted_guess * adjusted_guess);
            if (result_guess > 0) {
                if (reinterpret_cast<LookupGate_guess*>(this)->HasSkill_guess(0x27) != 0) {
                    CHARINFO2* char_info_guess = reinterpret_cast<EQ_CharacterProfile_guess*>(
                        reinterpret_cast<int>(this) + offset_holder_guess->vbaseOffset_0004_guess + 8)
                                                     ->GetCharInfo2();
                    int info_value_guess =
                        reinterpret_cast<DamageCharInfoView_guess*>(char_info_guess)->value_100c_guess;
                    int random_guess = TotalSpellAffects_guess(0xe4, 1, 0, 1);
                    result_guess += -info_value_guess - random_guess * info_value_guess / 100;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_SafeFallSuccess, 0, 0, 1);
                }
            }
            if (result_guess <= 0) {
                result_guess = 0;
            }
    }

    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->threshold_guess != 0 &&
        pSpawn_0008_guess->threshold_guess->linked_entity_guess != 0 && result_guess < 200) {
        result_guess = 0;
    }
    if (reinterpret_cast<CostStatusService_guess*>(EQ_GLOBAL(int, 0x00905CC0))
            ->Check_guess(EQ_GLOBAL(int, 0x00924470)) != 0) {
        result_guess = 0;
    }
    if (result_guess > 0) {
        record_guess.target_guess = static_cast<unsigned short>(pSpawn_0008_guess->spawn_id_guess);
        record_guess.source_guess = 0;
        record_guess.value_0004_guess = 0;
        record_guess.damage_0006_guess = result_guess;
        record_guess.value_000a_guess = 0.0f;
        record_guess.value_000e_guess = 0.0f;
        record_guess.value_0012_guess = 0.0f;
        record_guess.type_guess = 0xfc;
        record_guess.spell_guess = -1;
        result_guess = TakeDamage_guess(result_guess, reinterpret_cast<DamageRecord_guess*>(&record_guess), 1, 0, 1, 1);
    }
    return result_guess;
}

// Rebuilds the item stat totals when `enabled_guess` (dirty) is set: worn slots 0-20 (scaled below the
// item's level), then the 5- and 2-entry extra item lists. The item mods are capped at 35, 30, 100 and 150
// (Combat Effects, item +0x218, at 100; item +0x23C at 150), then
// STR to WIS, AC (+0x2C) and the rest are recomputed and the
// stats windows refreshed.
// FUNCTION: TITANIUM 0x004212B3
void RankTotalsOwner_guess::Recalculate_guess() {
    if (enabled_guess == 0) {
        return;
    }
    str_0010_guess = 0;
    sta_0014_guess = 0;
    value_0018_guess = 0;
    dex_001c_guess = 0;
    intel_0020_guess = 0;
    agi_0024_guess = 0;
    wis_0028_guess = 0;
    saveMagic_0030_guess = 0;
    saveCold_0034_guess = 0;
    saveFire_0038_guess = 0;
    savePoison_003c_guess = 0;
    saveDisease_0040_guess = 0;
    value_0044_guess = 0;
    value_0050_guess = 0;
    value_0054_guess = 0;
    value_0058_guess = 0;
    value_005c_guess = 0;
    value_0060_guess = 0;
    value_0064_guess = 0;
    value_0068_guess = 0;
    value_006c_guess = 0;
    value_0070_guess = 0;
    value_00a0_guess = 0;
    value_0074_guess = 0;
    value_00a4_guess = 0;
    value_00a8_guess = 0;
    value_00ac_guess = 0;
    value_00b0_guess = 0;
    value_00b4_guess = 0;
    itemHaste_00b8_guess = 0;
    value_00bc_guess = 0;
    for (int i = 0; i < 9; ++i) {
        values_0078_guess[i] = 0;
    }
    int index_guess;
    for (index_guess = 0; index_guess < 0x15; ++index_guess) {
        if (Table_guess()->GetEntry_guess(index_guess) == 0) {
            continue;
        }
        if (Table_guess()->GetEntry_guess(index_guess)->GetItemClass_guess() != 0) {
            continue;
        }
        ItemInstance_guess* entry_guess = Table_guess()->GetEntry_guess(index_guess);
        RankEntryStats_guess* stats_guess = reinterpret_cast<RankEntryStats_guess*>(entry_guess);
        if (entry_guess->HasValue240_guess() == 0 &&
            (entry_guess->HasFlag12f_guess(1) != 0 || entry_guess->GetRecommendedLevel_guess(1) != 0)) {
            if (source_guess != 0) {
                RANK_ADD_ALL_GUESS(stats_guess, RANK_APPLY_GUESS)
            }
        } else {
            RANK_ADD_ALL_GUESS(stats_guess, RANK_RAW_GUESS)
        }
    }
    for (int small_guess = 0; small_guess < 5; ++small_guess) {
        if (Table_guess()->GetSmallEntry_guess(small_guess) != 0 &&
            Table_guess()->GetSmallEntry_guess(small_guess)->GetItemClass_guess() == 0) {
            RankEntryStats_guess* stats_guess =
                reinterpret_cast<RankEntryStats_guess*>(Table_guess()->GetSmallEntry_guess(small_guess));
            RANK_ADD_ALL_GUESS(stats_guess, RANK_RAW_GUESS)
        }
    }
    for (int slot_guess = 0; slot_guess < 2; ++slot_guess) {
        ItemInstance_guess* entry_guess = Slot05_guess(slot_guess);
        if (entry_guess != 0 && entry_guess->GetItemClass_guess() == 0) {
            RankEntryStats_guess* stats_guess = reinterpret_cast<RankEntryStats_guess*>(entry_guess);
            RANK_ADD_ALL_GUESS(stats_guess, RANK_RAW_GUESS)
        }
    }
    reinterpret_cast<RankSummaryOwner_guess*>(this)->Accumulate_guess(0xe);
    reinterpret_cast<RankSummaryOwner_guess*>(this)->Accumulate_guess(0xf);
    if (value_0050_guess < 0) {
        value_0050_guess = 0;
    }
    if (value_0060_guess > 35) {
        value_0060_guess = 35;
    }
    if (value_0064_guess > 35) {
        value_0064_guess = 35;
    }
    if (value_0070_guess > 35) {
        value_0070_guess = 35;
    }
    if (value_0074_guess > 35) {
        value_0074_guess = 35;
    }
    if (value_00a0_guess > 35) {
        value_00a0_guess = 35;
    }
    if (value_00b4_guess > 30) {
        value_00b4_guess = 30;
    }
    if (value_0068_guess > 100) {
        value_0068_guess = 100;
    }
    if (value_006c_guess > 150) {
        value_006c_guess = 150;
    }
    if (value_005c_guess > 100) {
        value_005c_guess = 100;
    }
    itemHaste_00b8_guess = reinterpret_cast<RankMaxOwner_guess*>(this)->GetMaxRank_guess();
    str_0010_guess = reinterpret_cast<CostOwner_guess*>(this)->Str_guess();
    sta_0014_guess = reinterpret_cast<CostOwner_guess*>(this)->Sta_guess();
    value_0018_guess = reinterpret_cast<CostRollOwner_guess*>(this)->Cha_guess();
    dex_001c_guess = reinterpret_cast<CostRollOwner_guess*>(this)->Dex_guess();
    intel_0020_guess = reinterpret_cast<CostRollOwner_guess*>(this)->Int_guess();
    wis_0028_guess = reinterpret_cast<CostRollOwner_guess*>(this)->Wis_guess();
    saveMagic_0030_guess = reinterpret_cast<CostOwner_guess*>(this)->save_magic_guess();
    saveCold_0034_guess = reinterpret_cast<CostRollOwner_guess*>(this)->save_cold_guess();
    saveFire_0038_guess = reinterpret_cast<CostOwner_guess*>(this)->save_fire_guess();
    savePoison_003c_guess = reinterpret_cast<DynamicPropertyOwner_guess*>(this)->save_poison_guess();
    saveDisease_0040_guess = reinterpret_cast<CostRollOwner_guess*>(this)->save_disease_guess();
    value_0044_guess = reinterpret_cast<DynamicValueOwner_guess*>(this)->GetAdjustedValue_guess();
    weight_0048_guess = reinterpret_cast<CostOwner_guess*>(this)->CalculateWeight_guess();
    agi_0024_guess = Agi_guess();
    armorClass_002c_guess = reinterpret_cast<CostTotalOwner_guess*>(this)->ArmorClass_guess(1);
    if (pinstCPotionBeltWnd_guess != 0) {
        pinstCPotionBeltWnd_guess->Refresh_guess();
    }
    if (pinstCBandolierWnd_guess != 0) {
        pinstCBandolierWnd_guess->RefreshRows_guess();
    }
    if (pinstCSkillsWnd_guess != 0) {
        pinstCSkillsWnd_guess->Run_554e50_guess();
    }
    if (pinstCInventoryWnd_guess != 0) {
        pinstCInventoryWnd_guess->dirty_guess = 1;
    }
    enabled_guess = 0;
}

struct TickUser_guess;
struct TickPc_guess;
struct TickPlayer_guess;
struct TickCooldownOwner_guess;

struct TickItemInfo_guess {
    char padding_0000_guess[0x12d];
    unsigned char delay_012d_guess;
    char padding_012e_guess[6];
    unsigned char type_0134_guess;
};

struct TickItem_guess {
    // EXTERNAL: TITANIUM 0x005E0E90 TickItem_guess::GetDelay_guess
    int GetDelay_guess();
    // EXTERNAL: TITANIUM 0x005E1640 TickItem_guess::IsWeapon_guess
    char IsWeapon_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 TickItem_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 TickItem_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005EC620 TickItem_guess::Bind_guess
    void Bind_guess(TickItemInfo_guess* info_guess);
};

struct TickCharInfo_guess {
    char padding_0000_guess[0x10];
    BoundedArray_guess<TickItem_guess*, 31> items_guess;
    char padding_008c_guess[0xee4];
    BoundedArray_guess<int, 100> skills_guess;
    BoundedArray_guess<int, 25> innates_guess;
    char padding_1164_guess[0x38];
    unsigned char class_119c_guess;
    char padding_119d_guess[7];
    int level_11a4_guess;
    char padding_11a8_guess[0x70];
    int value_1218_guess;
    int value_121c_guess;
    int value_1220_guess;
    // EXTERNAL: TITANIUM 0x005FBAB0 TickCharInfo_guess::GetBaseRegen_guess
    int GetBaseRegen_guess();
};

struct TickTargetRef_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    // EXTERNAL: TITANIUM 0x004B76A6 TickTargetRef_guess::Find_guess
    TickItem_guess** Find_guess(TickUser_guess* user_guess);
};

struct TickActor_guess {
    char padding_0000_guess[0x54];
    unsigned int time_0054_guess;
    unsigned int time_0058_guess;
    char padding_005c_guess[4];
    unsigned int time_0060_guess;
    char padding_0064_guess[4];
    int value_0068_guess;
    char padding_006c_guess[4];
    unsigned int time_0070_guess;
    unsigned int time_0074_guess;
    unsigned int time_0078_guess;
    char padding_007c_guess[0x21];
    unsigned char state_009d_guess;
    char padding_009e_guess[0x32];
    unsigned int time_00d0_guess;
    unsigned int time_00d4_guess;
    unsigned int time_00d8_guess;
    unsigned int time_00dc_guess;
    char padding_00e0_guess[4];
    unsigned int time_00e4_guess;
    char padding_00e8_guess[0x2c];
    unsigned int time_0114_guess;
    int value_0118_guess;
    char padding_011c_guess[4];
    unsigned int time_0120_guess;
    char padding_0124_guess[0x2e];
    unsigned char flag_0152_guess;
    char padding_0153_guess[2];
    unsigned char flag_0155_guess;
    char padding_0156_guess[2];
    TickPlayer_guess* boat_0158_guess;
    TickPlayer_guess* mount_015c_guess;
    TickPlayer_guess* link_0160_guess;
    char padding_0164_guess[0xe34];
    int spell_0f98_guess;
    unsigned char slot_0f9c_guess;
    char padding_0f9d_guess[3];
    int value_0fa0_guess;
    char padding_0fa4_guess[0xa4];
    TickItem_guess* item_1048_guess;
    unsigned char flag_104c_guess;
    char padding_104d_guess[3];
    TickTargetRef_guess target_1050_guess;
    char padding_1060_guess[8];
    int value_1068_guess;
};

struct TickPlayer_guess : EQPlayer {
    TickActor_guess* Actor_guess() {
        return static_cast<TickActor_guess*>(pActorInfo);
    }
    // EXTERNAL: TITANIUM 0x00484D8D TickPlayer_guess::GetConscious_guess
    void GetConscious_guess();
    // EXTERNAL: TITANIUM 0x00484DF5 TickPlayer_guess::KnockedOut_guess
    void KnockedOut_guess();
    // EXTERNAL: TITANIUM 0x0047F01E TickPlayer_guess::ModifyAttackSpeed_guess
    unsigned int ModifyAttackSpeed_guess(int value_guess, int flag_guess);
};

struct TickName_guess {
    char text_guess[0x40];
    // EXTERNAL: TITANIUM 0x0040E25C TickName_guess::Set_guess
    void Set_guess(const char* name_guess);
};

struct TickVBase_guess : EQ_CharacterProfile_guess {
    virtual void V00_guess();
    virtual void V01_guess();
    virtual void V02_guess();
    virtual void V03_guess();
    virtual void V04_guess();
    virtual void V05_guess();
    virtual void V06_guess();
    virtual void V07_guess();
    virtual void V08_guess();
    virtual void V09_guess();
    virtual void V0a_guess();
    virtual void V0b_guess();
    virtual void V0c_guess();
    virtual TickCooldownOwner_guess* GetCooldownOwner_guess();
    virtual void V0e_guess();
    virtual void V0f_guess();
    virtual TickPc_guess* GetOwner_guess();
    char padding_000c_guess[0x30];
    char name_003c_guess[0x40];
    char padding_007c_guess[0x40];
    TickName_guess pet_name_00bc_guess;
    signed char state_00fc_guess;
    char padding_00fd_guess[7];
    unsigned char stand_state_0104_guess;
    char padding_0105_guess[3];
    unsigned char flags_0108_guess;
    TickCharInfo_guess* Info_guess() {
        return reinterpret_cast<TickCharInfo_guess*>(GetCharInfo2());
    }
    // EXTERNAL: TITANIUM 0x0040E2BD TickVBase_guess::FUN_0040e2bd_guess
    void FUN_0040e2bd_guess(int value_guess);
};

struct TickUserPrefix_guess {
    virtual void P00_guess();
    virtual void P01_guess();
    virtual void P02_guess();
    virtual void OnDamage_guess(DamageAdjustment_guess* record_guess, int flag_guess);
};

struct TickBuff_guess {
    unsigned char type_guess;
    char padding_0001_guess[3];
    int spell_guess;
};

struct TickSpell_guess {
    char padding_0000_guess[0x1c];
    unsigned int value_001c_guess;
    char padding_0020_guess[0xc];
    int value_002c_guess;
    char padding_0030_guess[0x1c4];
    int value_01f4_guess;
    // EXTERNAL: TITANIUM 0x0044E755 TickSpell_guess::GetSpellLevelNeeded_guess
    unsigned char GetSpellLevelNeeded_guess(int value_guess);
};

struct TickSpellManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 TickSpellManager_guess::GetSpell_guess
    TickSpell_guess* GetSpell_guess(int id_guess);
};

struct TickUser_guess : TickUserPrefix_guess, virtual TickVBase_guess {
    TickPlayer_guess* player_guess;
    unsigned char flag_000c_guess;
    char padding_000d_guess[0x9b];
    int value_00a8_guess;
    char padding_00ac_guess[0x1c];
    unsigned char flag_00c8_guess;
    TickVBase_guess* Base_guess() {
        TickVBase_guess& base_guess = *this;
        return &base_guess;
    }
    // EXTERNAL: TITANIUM 0x004106A3 TickUser_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int affect_guess, int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00410FDB TickUser_guess::ApplyMovementModifier_guess
    void ApplyMovementModifier_guess(int value_guess);
    void ProcessFishing_guess();
    // EXTERNAL: TITANIUM 0x00413AE4 TickUser_guess::ProcessAffects_guess
    unsigned int ProcessAffects_guess();
    // EXTERNAL: TITANIUM 0x0040D933 TickUser_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();
    // EXTERNAL: TITANIUM 0x0040E7AC TickUser_guess::GetBuff_guess
    TickBuff_guess* GetBuff_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0041188E TickUser_guess::CastingRequirementsMet_guess
    char CastingRequirementsMet_guess(int spell_guess);
    // EXTERNAL: TITANIUM 0x0040F8A0 TickUser_guess::FUN_0040f8a0_guess
    void FUN_0040f8a0_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040DB49 TickUser_guess::FUN_0040db49_guess
    char FUN_0040db49_guess(unsigned char slot_guess, int spell_guess, TickItem_guess** item_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0040DB0B TickUser_guess::IsBardSong_guess
    int IsBardSong_guess(TickSpell_guess* spell_guess, unsigned char class_guess);
    bool DoPassageOfTime_guess();
};

struct TickPcPrefix_guess {
    virtual void Q00_guess();
    int field_0004_guess;
};

struct TickPcFirst_guess : TickPcPrefix_guess, virtual TickVBase_guess {
    char padding_000c_guess[0xe14];
    int counter_0e20_guess;
    char padding_0e24_guess[0xb45c];
    TickVBase_guess* Profile_guess() {
        TickVBase_guess& base_guess = *this;
        return &base_guess;
    }
    // EXTERNAL: TITANIUM 0x004BAB19 TickPcFirst_guess::IsInGroup_guess
    bool IsInGroup_guess();
    // EXTERNAL: TITANIUM 0x004BB226 TickPcFirst_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x005ED860 TickPcFirst_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004BDB3C TickPcFirst_guess::ProcessAirSupply_guess
    void ProcessAirSupply_guess();
    // EXTERNAL: TITANIUM 0x004BB618 TickPcFirst_guess::ProcessFatigue_guess
    void ProcessFatigue_guess();
};

struct TickPc_guess : TickPcFirst_guess, TickUser_guess {
    TickUser_guess* User_guess() {
        TickUser_guess& user_guess = *this;
        return &user_guess;
    }
};

struct TickDisplay_guess {
    char padding_0000_guess[0x148];
    unsigned int time_0148_guess;
    // EXTERNAL: TITANIUM 0x00443DBC TickDisplay_guess::ReloadUI
    void ReloadUI(int value_guess);
    // EXTERNAL: TITANIUM 0x00438FDF TickDisplay_guess::UpdateSoundEnvironment_guess
    void UpdateSoundEnvironment_guess();
};

struct TickWndB_guess {
    // EXTERNAL: TITANIUM 0x00469DD7 TickWndB_guess::NoOp_guess
    void NoOp_guess();
};

struct TickHotbarPage_guess {
    char padding_0000_guess[0x168];
    int type_0168_guess;
    int index_016c_guess;
    char text_0170_guess[0x40];
    int value_01b0_guess;
};

struct TickHotbar_guess {
    TickHotbarPage_guess* page_guess;
    // EXTERNAL: TITANIUM 0x00469DD7 TickHotbar_guess::NoOp_guess
    void NoOp_guess();
};

struct TickSound_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A TickSound_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049994C TickSound_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value_guess);
};

struct TickKeyState_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 TickKeyState_guess::Check_guess
    int Check_guess(int value_guess);
};

struct TickCooldown_guess {
    // EXTERNAL: TITANIUM 0x00434111 TickCooldown_guess::TickTributeTimers_guess
    void TickTributeTimers_guess(TickCooldownOwner_guess* owner_guess, int amount_guess);
};

struct TickExit_guess {
    // EXTERNAL: TITANIUM 0x00424FB5 TickExit_guess::WaitForDisconnect_guess
    void WaitForDisconnect_guess(int connection_guess, int delay_guess);
};

struct TickBonus_guess {
    // EXTERNAL: TITANIUM 0x004B4ED1 TickBonus_guess::GetRegenBonus_guess
    int GetRegenBonus_guess(TickPc_guess* pc_guess);
};

struct TickTargetState_guess {
    char padding_0000_guess[0xf8];
    unsigned int target_id_00f8_guess;
};

struct TickSkillInfo_guess {
    int unused_guess;
    unsigned int reuse_time_guess;
};

struct TickRecord8_guess {
    int value_guess;
    int unused_guess;
};

struct TickLookupA_guess {
    // EXTERNAL: TITANIUM 0x0040C059 TickLookupA_guess::Find_guess
    const char* Find_guess(int index_guess);
};

struct TickLookupB_guess {
    // EXTERNAL: TITANIUM 0x005FF6E0 TickLookupB_guess::Find_guess
    const char* Find_guess(int index_guess);
};

struct TickListA_guess {
    char padding_0000_guess[0x284];
    TickLookupA_guess* lookup_0284_guess;
};

struct TickListB_guess {
    char padding_0000_guess[0x284];
    TickLookupB_guess* lookup_0284_guess;
};

struct TickEverQuest_guess {
    char padding_0000_guess[0xc];
    TickListA_guess list_000c_guess;
    char padding_0294_guess[0x31c];
    TickListB_guess list_05b0_guess;
    // EXTERNAL: TITANIUM 0x00492EC2 TickEverQuest_guess::trimName_guess
    const char* trimName_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004A1350 TickEverQuest_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00498B78 TickEverQuest_guess::FUN_00498b78_guess
    void FUN_00498b78_guess(EQPlayer* player_guess, const char* text_guess);
};

struct TickSocial_guess {
    char name_guess[0x10];
    char lines_guess[5][0x100];
    char color_guess;
};
typedef TickSocial_guess TickSocialRow_guess[12];

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int first_guess, int second_guess, int third_guess);
// EXTERNAL: TITANIUM 0x004C94AE TickGetTargetState_guess
TickTargetState_guess* __cdecl TickGetTargetState_guess();
// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float y1_guess, float x1_guess, float y2_guess, float x2_guess);
// EXTERNAL: TITANIUM 0x0060F6D4 TickSin_guess
double __cdecl TickSin_guess(double angle_guess);
// EXTERNAL: TITANIUM 0x0060F784 TickCos_guess
double __cdecl TickCos_guess(double angle_guess);
// EXTERNAL: TITANIUM 0x004805E9 UpdateAllPlayersVisibility_guess
void __cdecl UpdateAllPlayersVisibility_guess();
// EXTERNAL: TITANIUM 0x00576E80 TickClientTime_guess
unsigned int __cdecl TickClientTime_guess();

#define g_tickGuard_guess EQ_GLOBAL(unsigned int, 0x0079DB9C)
#define g_tickLastMode_guess EQ_GLOBAL(unsigned int, 0x0079DB98)
#define g_tickLastTarget_guess EQ_GLOBAL(TickPlayer_guess*, 0x0079DB94)
#define g_tickLastFlagA_guess EQ_GLOBAL(unsigned char, 0x0079DB92)
#define g_tickLastFlagB_guess EQ_GLOBAL(unsigned char, 0x0079DB91)
#define g_tickLastFlagC_guess EQ_GLOBAL(unsigned char, 0x0079DB90)
#define g_tickLastCamp_guess EQ_GLOBAL(unsigned int, 0x0079DB8C)
#define g_tickPetSent_guess EQ_GLOBAL(int, 0x0079DB88)
#define g_tickPetMisses_guess EQ_GLOBAL(int, 0x0079D870)
#define g_tickLastSocial_guess EQ_GLOBAL(unsigned int, 0x0079D868)
#define g_tickExit_guess EQ_GLOBAL(TickExit_guess*, 0x0079DBD8)
#define g_tickMode_guess EQ_GLOBAL(unsigned char, 0x009237B4)
#define g_tickResync_guess EQ_GLOBAL(unsigned char, 0x00988C77)
#define g_tickResyncArg_guess EQ_GLOBAL(unsigned char, 0x00988C78)
#define g_tickConnection_guess EQ_ARRAY(char, 0x00905CA0)
#define g_tickConnectionValue_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_tickDisplay_guess EQ_GLOBAL(TickDisplay_guess*, 0x00905D24)
#define pinstCInvSlotMgr_guess EQ_GLOBAL(TickWndB_guess*, 0x00850CB8)
#define pinstCChatManager_guess EQ_GLOBAL(TickHotbar_guess*, 0x009917E4)
#define g_tickAttackOn_guess EQ_GLOBAL(unsigned char, 0x009858C7)
#define g_tickRangedOn_guess EQ_GLOBAL(unsigned char, 0x009858C8)
#define g_tickPrimaryReady_guess EQ_GLOBAL(unsigned char, 0x00924670)
#define g_tickSecondaryReady_guess EQ_GLOBAL(unsigned char, 0x00924671)
#define g_tickCounter_guess EQ_GLOBAL(unsigned char, 0x00924673)
#define g_tickTarget_guess EQ_GLOBAL(TickPlayer_guess*, 0x00905D04)
#define g_tickLocal_guess EQ_GLOBAL(TickPlayer_guess*, 0x00905CE4)
#define g_tickOther_guess EQ_GLOBAL(TickPlayer_guess*, 0x00905CF8)
#define g_tickSound_guess EQ_GLOBAL(TickSound_guess, 0x00923770)
#define g_tickLastMinute_guess EQ_GLOBAL(unsigned int, 0x00923834)
#define g_tickPendingTime_guess EQ_GLOBAL(unsigned int, 0x00923864)
#define g_tickPendingValue_guess EQ_GLOBAL(int, 0x00923868)
#define g_tickCampTime_guess EQ_GLOBAL(unsigned int, 0x00923994)
#define g_tickNoticeA_guess EQ_GLOBAL(int, 0x009248D4)
#define g_tickNoticeB_guess EQ_GLOBAL(int, 0x009248D0)
#define g_tickKeyState_guess EQ_GLOBAL(TickKeyState_guess, 0x009248E0)
#define g_tickDefaultInfo_guess EQ_GLOBAL(TickItemInfo_guess*, 0x00903E34)
#define g_tickDefaultItem_guess EQ_GLOBAL(TickItem_guess*, 0x00903E30)
#define g_tickSkillInfo_guess EQ_ARRAY(TickSkillInfo_guess*, 0x00851200)
#define g_tickSkillTimers_guess EQ_ARRAY(unsigned int, 0x0092447C)
#define g_tickSkillReady_guess EQ_ARRAY(unsigned char, 0x0092460C)
#define g_tickHiding_guess EQ_GLOBAL(unsigned char, 0x009239DC)
#define g_tickSkillState_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_tickSkillEnd_guess EQ_GLOBAL(unsigned int, 0x00923CCC)
#define g_tickSkillLast_guess EQ_GLOBAL(unsigned int, 0x00923CD0)
#define g_tickSkillTarget_guess EQ_GLOBAL(TickPlayer_guess*, 0x00923CD4)
#define g_tickPc_guess EQ_GLOBAL(TickPc_guess*, 0x00905D00)
#define g_tickEverQuest_guess EQ_GLOBAL(TickEverQuest_guess*, 0x00988DF0)
#define g_tickStartY_guess EQ_GLOBAL(int, 0x009239C4)
#define g_tickStartX_guess EQ_GLOBAL(int, 0x009239C8)
#define g_tickStartZ_guess EQ_GLOBAL(int, 0x009239CC)
#define g_tickCampTarget_guess EQ_GLOBAL(int, 0x00905D28)
#define g_tickGameState_guess EQ_GLOBAL(int, 0x00923D94)
#define g_tickExiting_guess EQ_GLOBAL(unsigned char, 0x00923D7B)
#define g_tickNumberText_guess EQ_ARRAY(char, 0x0099DB00)
#define g_tickCooldown_guess EQ_GLOBAL(TickCooldown_guess, 0x00850350)
#define g_tickDirtyA_guess EQ_GLOBAL(unsigned char, 0x00923D79)
#define g_tickDirtyB_guess EQ_GLOBAL(unsigned char, 0x00923D78)
#define g_tickEmptyName_guess EQ_ARRAY(char, 0x0063F53F)
#define g_tickSpells_guess EQ_GLOBAL(TickSpellManager_guess*, 0x00985CC8)
#define g_tickNewbieRules_guess EQ_GLOBAL(unsigned char, 0x00905CA8)
#define g_tickBonus_guess EQ_GLOBAL(TickBonus_guess*, 0x009859EC)
#define g_tickFlag923798_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_tickValue923884_guess EQ_GLOBAL(int, 0x00923884)
#define g_tickSocialState_guess EQ_GLOBAL(int, 0x00694D8C)
#define g_tickSocialPause_guess EQ_GLOBAL(short, 0x00694D8E)
#define g_tickChatValue_guess EQ_GLOBAL(int, 0x009237F0)
#define g_tickChatMode_guess EQ_GLOBAL(unsigned char, 0x009237EC)
#define g_tickChatText_guess EQ_ARRAY(char, 0x009237F4)
#define g_tickSocials_guess EQ_ARRAY(TickSocialRow_guess, 0x0095D4D4)
#define g_tickSeparator_guess EQ_ARRAY(char, 0x0063F9EC)
#define g_tickHalfCircle_guess EQ_GLOBAL(float, 0x00641140)
#define g_tickFullCircle_guess EQ_GLOBAL(float, 0x0064113C)
#define g_tickHeadingScaleA_guess EQ_GLOBAL(float, 0x00641138)
#define g_tickHeadingScaleB_guess EQ_GLOBAL(float, 0x00641134)
#define g_tickHeadingBase_guess EQ_GLOBAL(float, 0x00641130)
#define g_tickScale640e20_guess EQ_GLOBAL(float, 0x00640E20)
#define g_tickScale640038_guess EQ_GLOBAL(float, 0x00640038)
#define g_tickRound6410a0_guess EQ_GLOBAL(double, 0x006410A0)
#define g_tickTurnA_guess EQ_GLOBAL(float, 0x0064112C)
#define g_tickTurnB_guess EQ_GLOBAL(float, 0x00641128)
#define g_tickTurnC_guess EQ_GLOBAL(float, 0x00641124)
#define g_tickTurnD_guess EQ_GLOBAL(float, 0x00641120)
#define g_tickRestScale_guess EQ_GLOBAL(double, 0x006410F0)
#define g_tickRestBonus_guess EQ_GLOBAL(double, 0x006410E8)
#define g_tickRestFirst_guess EQ_GLOBAL(float, 0x006410D0)

// The standing regeneration formula; each level read is its own profile lookup.
#define TICK_REST_FORMULA_GUESS(v)                                \
    if (Base_guess()->Info_guess()->level_11a4_guess >= 0x32) {   \
        ++v;                                                      \
    }                                                             \
    if (Base_guess()->Info_guess()->level_11a4_guess >= 0x37) {   \
        ++v;                                                      \
    }                                                             \
    v = v * 2;

struct TickMovementClock_guess {
    char padding_0000_guess[0x148];
    unsigned int tick_guess;
    // EXTERNAL: TITANIUM 0x00439F26 TickMovementClock_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float first_guess, float second_guess, float third_guess);
    // EXTERNAL: TITANIUM 0x0043D64B TickMovementClock_guess::FindGroundHeight_guess
    float FindGroundHeight_guess(float first_guess, float second_guess, float third_guess);
    // EXTERNAL: TITANIUM 0x0043A292 TickMovementClock_guess::GetEnvironment_guess
    unsigned char GetEnvironment_guess(float first_guess, float second_guess, float third_guess,
                                    int mode_guess);
    // EXTERNAL: TITANIUM 0x004395E2 TickMovementClock_guess::PlaySoundAtLocation_guess
    void PlaySoundAtLocation_guess(float first_guess, float second_guess, float third_guess, int mode_guess);
};

struct TickMovementState_guess {
    char padding_0000_guess[0x120];
    unsigned int next_update_guess;
    char padding_0124_guess[0x2e];
    unsigned char state_guess;
};

struct TickDirectionService_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float GetRotation_guess(float heading_guess);
    virtual float GetForward_guess(float heading_guess);
};

// EXTERNAL: TITANIUM 0x0049AB78 DoParticleEffect_guess
void __cdecl DoParticleEffect_guess(int type_guess, const char* text_guess, int color_guess,
                                EQPlayer* player_guess, int first_guess, int second_guess,
                                float* point_guess, int fourth_guess, int duration_guess);

#define g_tickMovementMode_guess EQ_GLOBAL(int, 0x00923CC4)
#define g_tickMovementClock_guess EQ_GLOBAL(TickMovementClock_guess*, 0x00905D24)
#define g_tickDirectionService_guess EQ_GLOBAL(TickDirectionService_guess*, 0x0099E374)

// Fishing in progress (actor +0x152), once a second: moving stops it (string 165). State 1 casts 16-32
// units ahead; if that spot is within 30 of the player's height and in a region other than 0, 3 or 7 (3 and
// 7 are lava), a splash plays there and state 6 waits 9 s. Anything else ends fishing.
// FUNCTION: TITANIUM 0x004173BF
// @early-stop: budget, structural ndiff=74
void TickUser_guess::ProcessFishing_guess() {
    if (player_guess != 0 && player_guess->pActorInfo != 0) {
        if (fabs((double)player_guess->SpeedRun) > 0.01) {
            if (g_tickMovementMode_guess == 0x37) {
                g_tickMovementMode_guess = -1;
            }
            reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->state_guess = 0;
            pEverQuest->dsp_chat(pStringTable->getString(0xa5, 0), 0x10e, true);
            return;
        }
        if (g_tickMovementClock_guess->tick_guess >=
            reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->next_update_guess) {
            switch (reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->state_guess) {
            case 1: {
                float random_guess = (float)RandomRange_guess(0x10, 0x20);
                float first_guess = player_guess->Y;
                float candidate_first_guess =
                    first_guess + random_guess *
                                      g_tickDirectionService_guess->GetForward_guess(
                                          player_guess->Heading);
                float second_base_guess = player_guess->X;
                float candidate_second_guess =
                    second_base_guess + random_guess *
                                            g_tickDirectionService_guess->GetRotation_guess(
                                                player_guess->Heading);
                float candidate_z_guess = g_tickMovementClock_guess->GetFloorHeight_guess(
                                              candidate_first_guess, candidate_second_guess,
                                              player_guess->Z) +
                                          3.0f;
                float minimum_z_guess = player_guess->Z - 100.0f;
                if (candidate_z_guess < minimum_z_guess) {
                    candidate_z_guess = minimum_z_guess;
                }
                float ground_z_guess = g_tickMovementClock_guess->FindGroundHeight_guess(
                    candidate_first_guess, candidate_second_guess, candidate_z_guess);
                if (fabs((double)(player_guess->Z - ground_z_guess)) <= 30.0) {
                    unsigned char ground_type_guess = g_tickMovementClock_guess->GetEnvironment_guess(
                        candidate_first_guess, candidate_second_guess, candidate_z_guess, 0);
                    if (ground_type_guess != 0 && ground_type_guess != 3 && ground_type_guess != 7) {
                        if (ground_z_guess != -1.0e27f) {
                            float point_guess[3];
                            point_guess[0] = candidate_first_guess;
                            point_guess[1] = candidate_second_guess;
                            point_guess[2] = ground_z_guess;
                            DoParticleEffect_guess(2, EQ_ARRAY(char, 0x0087AD00), 0x3d, player_guess,
                                               0, 0, point_guess, 0, 500);
                            g_tickMovementClock_guess->PlaySoundAtLocation_guess(
                                candidate_first_guess, candidate_second_guess, ground_z_guess, 99);
                        }
                        reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->state_guess = 6;
                        reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)
                            ->next_update_guess = GetCurrentTime_guess() + 9000;
                        return;
                    }
                }
                break;
            }
            case 2:
            case 3:
            case 4:
            case 5:
                reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->state_guess = 0;
                return;
            }
            if (g_tickMovementMode_guess == 0x37) {
                g_tickMovementMode_guess = -1;
            }
            reinterpret_cast<TickMovementState_guess*>(player_guess->pActorInfo)->state_guess = 0;
        }
    }
}

// Character upkeep, each frame. Always: run mode (OP_SetRunMode), target changes (OP_TargetMouse; body
// types 11, 60, 65 and 67 are dropped), OP_AutoAttack and OP_AutoAttack2, OP_AutoFire, weapon and skill
// ready flags, the poison timer (OP_ApplyPoison after 10 s or ReduceApplyPoisonTime, SPA 234), Tracking,
// Hide, camping, socials. Each second: movement SPAs, air, region damage, fishing, the boat (OP_BoardBoat
// and OP_LeaveBoat; the actor's boat_0158_guess). Each 6 s: buffs, HP regen (item part capped at 30, more
// above level 60 and with SPA 317), endurance, mana; a periodic call there (0x004A1350) sits behind a byte
// counter tested against 300, so it never runs: an original bug, confirmed in the binary. Then hunger, death
// and, offline only, finishing a spell cast.
// A UI reload first sends 0x6BC1 (the name) and 0x4E31 (EQEmu's OP_PetBuffWindow, here with the time).
// FUNCTION: TITANIUM 0x00422198
// @early-stop: budget, structural ndiff=1062
bool TickUser_guess::DoPassageOfTime_guess() {
    char saved_text_guess[64];
    char current_text_guess[64];
    char direction_guess[16];
    char text_guess[512];
    char command_guess[128];
    unsigned int id_guess;

    if ((g_tickGuard_guess & 1) == 0) {
        g_tickGuard_guess |= 1;
        g_tickLastMode_guess = g_tickMode_guess;
    }
    float turn_guess = 0.0f;
    int pet_gone_guess = 0;
    int alive_guess = 1;
    int killer_guess = 0;
    int hp_before_guess = 0;
    unsigned int now_guess = GetCurrentTime_guess();

    // A pending UI reload (g_tickResync_guess) runs ReloadUI first; then our name goes out as 0x6BC1 and the
    // time as OP_PetBuffWindow (0x4E31).
    if (g_tickResync_guess != 0) {
        g_tickDisplay_guess->ReloadUI(g_tickResyncArg_guess);
        g_tickResync_guess = 0;
        char* name_guess = Base_guess()->name_003c_guess;
        EQSendMessage(g_tickConnection_guess, 0x6bc1, name_guess, strlen(name_guess) + 1, 1);
        EQSendMessage(g_tickConnection_guess, OP_PetBuffWindow, &now_guess, 4, 1);
    }
    pinstCContainerMgr_guess->Process_guess();
    pinstCInvSlotMgr_guess->NoOp_guess();
    pinstCChatManager_guess->NoOp_guess();
    if (g_tickAttackOn_guess != 0 && g_tickPrimaryReady_guess != 0) {
        g_tickPrimaryReady_guess = 0;
        g_tickSecondaryReady_guess = 0;
        player_guess->Actor_guess()->time_0060_guess = GetCurrentTime_guess();
        player_guess->Actor_guess()->time_00dc_guess = GetCurrentTime_guess();
        player_guess->Actor_guess()->time_00e4_guess = GetCurrentTime_guess();
    }
    // State changes are reported once each: the run mode (OP_SetRunMode 0x4ABA; a mode above 1 goes out as 0
    // there and its real value as 0x2BAF once a minute), the target (OP_TargetMouse 0x6C47), auto-attack
    // (OP_AutoAttack 0x5E55 and OP_AutoAttack2 0x0701) and ranged attack (OP_AutoFire 0x6C53).
    if (g_tickLastMode_guess != g_tickMode_guess) {
        unsigned int mode_guess;
        g_tickLastMode_guess = g_tickMode_guess;
        mode_guess = g_tickMode_guess;
        if (g_tickMode_guess > 1) {
            mode_guess = 0;
        }
        EQSendMessage(g_tickConnection_guess, OP_SetRunMode, &mode_guess, 4, 1);
    }

    if (g_tickTarget_guess != g_tickLastTarget_guess) {
        // New target while auto-attacking at level 10 or lower, more than 2 levels above us: once per target
        // id, context tip 32 is shown and auto-attack and auto-fire are switched off, unless we are grouped
        // (0x004BAB19) and the target is a group member (0x004BB226).
        if (g_tickTarget_guess != 0 && g_tickAttackOn_guess != 0 && g_tickLocal_guess->Level <= 10 &&
            g_tickTarget_guess->Level - g_tickLocal_guess->Level > 2) {
            id_guess = g_tickTarget_guess->SpawnID;
            if (id_guess != TickGetTargetState_guess()->target_id_00f8_guess) {
                if (!Base_guess()->GetOwner_guess()->IsInGroup_guess() ||
                    Base_guess()->GetOwner_guess()->IsAGroupMember_guess(g_tickTarget_guess->Name) == 0) {
                    id_guess = g_tickTarget_guess->SpawnID;
                    TickGetTargetState_guess()->target_id_00f8_guess = id_guess;
                    if (pinstCTipWndCONTEXT_guess != 0) {
                        pinstCTipWndCONTEXT_guess->selectTip_guess(0x20, 0);
                    }
                    g_tickSound_guess.SetAutoAttack_guess(0);
                    g_tickSound_guess.SetAutoFire_guess(0);
                }
            }
        }
        if (g_tickTarget_guess != g_tickLastTarget_guess) {
            if (g_tickTarget_guess != 0) {
                unsigned int body_guess = g_tickTarget_guess->BodyType;
                // Body types 11, 60, 65 and 67 cannot be targeted: the target is cleared. A spawn whose actor
                // has a link at +0x160 is swapped for that spawn before its id is sent.
                if (body_guess == 0xb || body_guess == 0x41 || body_guess == 0x43 || body_guess == 0x3c) {
                    g_tickTarget_guess = 0;
                    id_guess = 0;
                } else {
                    if (g_tickTarget_guess->Actor_guess() != 0 &&
                        g_tickTarget_guess->Actor_guess()->link_0160_guess != 0) {
                        g_tickTarget_guess = g_tickTarget_guess->Actor_guess()->link_0160_guess;
                    }
                    id_guess = g_tickTarget_guess->SpawnID;
                }
            } else {
                id_guess = 0;
            }
            g_tickLastTarget_guess = g_tickTarget_guess;
            EQSendMessage(g_tickConnection_guess, OP_TargetMouse, &id_guess, 4, 1);
            if (pinstCDynamicZoneWnd_guess != 0) {
                pinstCDynamicZoneWnd_guess->Update_4FF11E_guess();
            }
        }
    }
    if (g_tickAttackOn_guess != g_tickLastFlagA_guess) {
        g_tickLastFlagA_guess = g_tickAttackOn_guess;
        id_guess = g_tickAttackOn_guess;
        EQSendMessage(g_tickConnection_guess, OP_AutoAttack, &id_guess, 4, 1);
    }
    if (g_tickAttackOn_guess != g_tickLastFlagB_guess) {
        g_tickLastFlagB_guess = g_tickAttackOn_guess;
        id_guess = g_tickAttackOn_guess;
        EQSendMessage(g_tickConnection_guess, OP_AutoAttack2, &id_guess, 4, 1);
    }
    if (g_tickRangedOn_guess != g_tickLastFlagC_guess) {
        g_tickLastFlagC_guess = g_tickRangedOn_guess;
        EQSendMessage(g_tickConnection_guess, OP_AutoFire, &g_tickLastFlagC_guess, 1, 1);
    }
    if (now_guess - g_tickLastMinute_guess > 60000) {
        g_tickLastMinute_guess = now_guess;
        ++Base_guess()->GetOwner_guess()->counter_0e20_guess;
        if (g_tickMode_guess > 1) {
            EQSendMessage(g_tickConnection_guess, 0x2baf, &g_tickMode_guess, 1, 1);
        }
    }

    DamageAdjustment_guess record_guess;
    record_guess.flags_guess = 0;
    if (player_guess != 0 && player_guess->Type == 0 && player_guess->Actor_guess() != 0 &&
        player_guess->Actor_guess()->mount_015c_guess != 0 &&
        player_guess->Actor_guess()->mount_015c_guess->SpeedRun == 0.0f) {
        player_guess->Actor_guess()->value_1068_guess = 1;
    }
    reinterpret_cast<RankTotalsOwner_guess*>(this)->Recalculate_guess();
    if (Base_guess()->state_00fc_guess == 4) {
        return true;
    }
    if (player_guess == 0) {
        return true;
    }
    if (player_guess->pActorInfo == 0) {
        return true;
    }
    TickPc_guess* pc_guess = Base_guess()->GetOwner_guess();
    if (pc_guess == 0) {
        return true;
    }
    if (fabs(pc_guess->player_guess->SpeedRun) > 0.001f) {
        pc_guess->player_guess->Actor_guess()->flag_0155_guess = 0;
    }
    // A poison being applied finishes with OP_ApplyPoison (0xC2C) after ReduceApplyPoisonTime (SPA 234) ms,
    // or 10 s when that is 0; not while camping.
    if (g_tickPendingTime_guess != 0 && g_tickCampTime_guess == 0 && g_tickNoticeA_guess == 0 &&
        g_tickNoticeB_guess == 0) {
        unsigned int limit_guess = TotalSpellAffects_guess(0xea, 1, 0, 1);
        if (limit_guess == 0) {
            limit_guess = 10000;
        }
        if (g_tickPendingTime_guess > now_guess) {
            g_tickPendingTime_guess = now_guess;
        }
        if (now_guess - g_tickPendingTime_guess > limit_guess) {
            TickRecord8_guess pending_guess;
            pending_guess.value_guess = g_tickPendingValue_guess;
            g_tickNoticeA_guess = 1;
            g_tickNoticeB_guess = 1;
            EQSendMessage(g_tickConnection_guess, OP_ApplyPoison, &pending_guess, 8, 1);
            g_tickPendingTime_guess = 0;
            g_tickPendingValue_guess = 0;
        }
    }
    if (player_guess->Type == 0) {
        unsigned int* timer_guess = &player_guess->Actor_guess()->time_00d0_guess;
        if (*timer_guess != 0 && now_guess > *timer_guess) {
            *timer_guess = 0;
            if (TotalSpellAffects_guess(SPA_Mez, 1, 0, 1) == 0) {
                Base_guess()->state_00fc_guess = 0;
            }
            if (g_tickKeyState_guess.Check_guess(0x1a) == 0) {
                // The stun timer (actor +0xD0) has run out: state back to 0 unless a Mez (SPA 31) holds, "You
                // are unstunned." Below, HP decides between waking up (state 3 with HP above 0) and the
                // knock-out (HP 0 or less).
                pEverQuest->dsp_chat(pStringTable->getString(0x30d2, 0), 0x154, true);
            }
            g_tickDisplay_guess->UpdateSoundEnvironment_guess();
        }
        int hp_guess = reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(0);
        if (hp_guess > 0 && Base_guess()->state_00fc_guess == 3) {
            player_guess->GetConscious_guess();
        }
        if (hp_guess < 1 && Base_guess()->state_00fc_guess < 3) {
            player_guess->KnockedOut_guess();
        }
    }

    if (player_guess != 0) {
        // Not standing with auto-attack on: command 10 is run and refuses. Then the ready flags for primary
        // and secondary swings, the skill buttons and the shared combat-skill byte (0x00924672) are set as
        // their timers run out.
        if (player_guess->StandState != 'd' && g_tickAttackOn_guess != 0) {
            // Auto-attack is on but we are not standing: run command 10 (the attack key) through ExecuteCmd,
            // which refuses and says why.
            ExecuteCmd(10, 1, 0);
        }
        unsigned int delay_guess = 0;
        // Swing timers. An empty hand uses a stand-in item of type 0x16 whose "delay" is a skill id (28, hand
        // to hand): for that type the delay is the skill's reuse time, otherwise item delay x 100 ms;
        // 0x0047F01E applies haste. Primary is ready once the time since actor +0x60 reaches it; while actor
        // +0x9D is 11 and a ranged delay exists, the ranged delay is used instead.
        TickItem_guess* item_guess = Base_guess()->Info_guess()->items_guess[InvSlot_Primary];
        if (item_guess != 0 && item_guess->GetDelay_guess() < 1) {
            item_guess = 0;
        }
        if (item_guess == 0) {
            g_tickDefaultInfo_guess->type_0134_guess = 0x16;
            g_tickDefaultInfo_guess->delay_012d_guess = 0x1c;
            g_tickDefaultItem_guess->Bind_guess(g_tickDefaultInfo_guess);
            item_guess = g_tickDefaultItem_guess;
        }
        if (item_guess != 0 && (item_guess->IsWeapon_guess() || item_guess->GetItemType_guess() == 0xd ||
                                item_guess->GetItemType_guess() == 0x16)) {
            int base_guess;
            if (item_guess->GetItemType_guess() == 0x16) {
                base_guess = g_tickSkillInfo_guess[item_guess->GetDelay_guess()]->reuse_time_guess;
            } else {
                base_guess = item_guess->GetDelay_guess() * 100;
            }
            delay_guess = player_guess->ModifyAttackSpeed_guess(base_guess, 0);
        }

        item_guess = Base_guess()->Info_guess()->items_guess[InvSlot_Range];
        if (item_guess != 0 && item_guess->GetDelay_guess() < 1) {
            item_guess = 0;
        }
        unsigned int ranged_delay_guess = 0;
        if (item_guess != 0 && (item_guess->IsWeapon_guess() || item_guess->GetItemType_guess() == 0xd ||
                                item_guess->GetItemType_guess() == 0x16)) {
            if (item_guess->GetItemType_guess() == 0x16) {
                ranged_delay_guess = g_tickSkillInfo_guess[item_guess->GetDelay_guess()]->reuse_time_guess;
            } else {
                ranged_delay_guess = item_guess->GetDelay_guess() * 100;
            }
            ranged_delay_guess =
                player_guess->ModifyAttackSpeed_guess(ranged_delay_guess, item_guess->GetItemType_guess() == 5 ? 1 : 0);
        }
        unsigned int since_guess = now_guess - player_guess->Actor_guess()->time_0060_guess;
        if (player_guess->Actor_guess()->state_009d_guess == 0xb && ranged_delay_guess != 0) {
            delay_guess = ranged_delay_guess;
        }
        if (since_guess >= delay_guess && g_tickPrimaryReady_guess == 0) {
            g_tickPrimaryReady_guess = 1;
        }

        // Skill buttons become ready again: Mend (32) and Hide (29) at a stored time, the rest once their
        // reuse time has passed; Sneak (42) not while sneaking, Bind Wound (9) one second later than its
        // timer.
        for (int skill_guess = 0; skill_guess < 0x4a; ++skill_guess) {
            if (skill_guess == SkillMend) {
                if (now_guess >= g_tickSkillTimers_guess[SkillMend] && g_tickSkillReady_guess[SkillMend] == 0) {
                    g_tickSkillReady_guess[SkillMend] = 1;
                }
            } else if (skill_guess == SkillHide) {
                if (now_guess >= g_tickSkillTimers_guess[SkillHide] && g_tickSkillReady_guess[SkillHide] == 0 &&
                    g_tickHiding_guess == 0) {
                    g_tickSkillReady_guess[SkillHide] = 1;
                }
            } else {
                unsigned int used_guess = g_tickSkillTimers_guess[skill_guess];
                unsigned int elapsed_guess;
                if (used_guess != 0xffffffff && used_guess >= now_guess) {
                    elapsed_guess = 0;
                } else {
                    elapsed_guess = now_guess - used_guess;
                }
                unsigned int reuse_guess = g_tickSkillInfo_guess[skill_guess]->reuse_time_guess;
                if (elapsed_guess > reuse_guess && g_tickSkillReady_guess[skill_guess] == 0 &&
                    (skill_guess != SkillSneak || player_guess->Sneak == 0)) {
                    if (skill_guess == SkillBindWound) {
                        if (elapsed_guess > reuse_guess + 1000) {
                            g_tickSkillReady_guess[SkillBindWound] = 1;
                        }
                    } else {
                        g_tickSkillReady_guess[skill_guess] = 1;
                    }
                }
            }
        }

        item_guess = Base_guess()->Info_guess()->items_guess[InvSlot_Secondary];
        if (item_guess != 0 && item_guess->GetDelay_guess() < 1) {
            item_guess = 0;
        }
        if (item_guess == 0) {
            g_tickDefaultInfo_guess->type_0134_guess = 0x16;
            g_tickDefaultInfo_guess->delay_012d_guess = 0x1c;
            g_tickDefaultItem_guess->Bind_guess(g_tickDefaultInfo_guess);
            item_guess = g_tickDefaultItem_guess;
        }
        if (item_guess != 0 && (item_guess->IsWeapon_guess() || item_guess->GetItemType_guess() == 0xd ||
                                item_guess->GetItemType_guess() == 0x16)) {
            int base_guess;
            if (item_guess->GetItemType_guess() == 0x16) {
                base_guess = g_tickSkillInfo_guess[item_guess->GetDelay_guess()]->reuse_time_guess;
            } else {
                base_guess = item_guess->GetDelay_guess() * 100;
            }
            delay_guess = player_guess->ModifyAttackSpeed_guess(base_guess, 0);
        }
        if (now_guess - player_guess->Actor_guess()->time_00dc_guess >= delay_guess) {
            g_tickSecondaryReady_guess = 1;
        }

        item_guess = Base_guess()->Info_guess()->items_guess[InvSlot_Range];
        if (item_guess != 0) {
            if (item_guess->GetDelay_guess() < 1) {
                g_tickDefaultInfo_guess->type_0134_guess = 0x16;
                g_tickDefaultInfo_guess->delay_012d_guess = 0x1c;
                g_tickDefaultItem_guess->Bind_guess(g_tickDefaultInfo_guess);
                item_guess = g_tickDefaultItem_guess;
            }
            if (item_guess != 0 && (item_guess->IsWeapon_guess() || item_guess->GetItemType_guess() == 0xd ||
                                    item_guess->GetItemType_guess() == 0x16)) {
                if (item_guess->GetItemType_guess() == 0x16) {
                    delay_guess = g_tickSkillInfo_guess[item_guess->GetDelay_guess()]->reuse_time_guess;
                } else {
                    delay_guess = item_guess->GetDelay_guess() * 100;
                }
                // The hasted ranged delay computed here is not used (as in the binary). The test below sets
                // 0x00924672, the shared ready byte of the kind-2 combat skills (Kick, Bash...; do_skill
                // clears it), once the time since actor +0x114 reaches the hasted delay at +0x118. The code's
                // name g_tickRangedReady_guess is wrong.
                player_guess->ModifyAttackSpeed_guess(delay_guess, item_guess->GetItemType_guess() == 5 ? 1 : 0);
            }
        }
        if (now_guess - player_guess->Actor_guess()->time_0114_guess >=
            player_guess->ModifyAttackSpeed_guess(player_guess->Actor_guess()->value_0118_guess, 0)) {
            g_skillAttackReady_guess = 1;
        }
    }

    // Tracking (skill 53): the direction to the tracked spawn, 0x30D3 when it is gone.
    if (g_tickSkillState_guess == 0x35) {
        TickPlayer_guess* tracked_guess = g_tickSkillTarget_guess;
        if (tracked_guess == 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x30d3, 0), 0x10e, true);
            g_tickSkillState_guess = -1;
        } else {
            if (g_tickDisplay_guess->time_0148_guess - g_tickSkillLast_guess > 2000) {
                g_tickSkillLast_guess = g_tickDisplay_guess->time_0148_guess;
                RandomRange_guess(1, 100);
                if (g_tickPc_guess->Profile_guess()->Info_guess()->skills_guess[0x35] >= 0) {
                    float player_x_guess = player_guess->X;
                    float player_y_guess = player_guess->Y;
                    float heading_to_guess =
                        get_bearing_guess(player_y_guess, player_x_guess, tracked_guess->Y, tracked_guess->X);
                    float heading_guess = player_guess->Heading;
                    if (heading_to_guess == heading_guess) {
                        turn_guess = 0.0f;
                    } else if (heading_to_guess > heading_guess) {
                        turn_guess = heading_to_guess - heading_guess;
                        if (turn_guess > g_tickHalfCircle_guess) {
                            turn_guess = g_tickFullCircle_guess - heading_to_guess + heading_guess;
                        }
                    } else if (heading_guess > heading_to_guess) {
                        turn_guess = heading_guess - heading_to_guess;
                        if (turn_guess > g_tickHalfCircle_guess) {
                            turn_guess = g_tickFullCircle_guess - heading_guess + heading_to_guess;
                        }
                    }
                    float angle_guess = player_guess->Heading * g_tickHeadingScaleA_guess *
                                            g_tickHeadingScaleB_guess +
                                        g_tickHeadingBase_guess;
                    float sin_guess = TickSin_guess(angle_guess) * g_tickScale640e20_guess;
                    float cos_guess = TickCos_guess(angle_guess) * g_tickScale640e20_guess;
                    float delta_y_guess = tracked_guess->Y - player_guess->Y;
                    float delta_x_guess = tracked_guess->X - player_guess->X;
                    if (delta_x_guess * cos_guess + delta_y_guess * sin_guess < 0.0f) {
                        strcpy(direction_guess, pStringTable->getString(0x3182, 0));
                    } else {
                        strcpy(direction_guess, pStringTable->getString(0x3183, 0));
                    }
                    const char* tracked_name_guess = g_tickEverQuest_guess->trimName_guess(tracked_guess->Name);
                    if (turn_guess >= 0.0f && turn_guess <= g_tickTurnA_guess) {
                        FormatText_guess(text_guess, 0x3184, tracked_name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    } else if (turn_guess > g_tickTurnA_guess && turn_guess <= g_tickTurnB_guess) {
                        FormatText_guess(text_guess, 0x3185, tracked_name_guess, direction_guess, 0, 0, 0, 0, 0, 0,
                                         0);
                    } else if (turn_guess > g_tickTurnB_guess && turn_guess <= g_tickTurnC_guess) {
                        FormatText_guess(text_guess, 0x3186, tracked_name_guess, direction_guess, 0, 0, 0, 0, 0, 0,
                                         0);
                    } else if (turn_guess > g_tickTurnC_guess && turn_guess <= g_tickTurnD_guess) {
                        FormatText_guess(text_guess, 0x3187, tracked_name_guess, direction_guess, 0, 0, 0, 0, 0, 0,
                                         0);
                    } else if (turn_guess > g_tickTurnD_guess && turn_guess <= g_tickHalfCircle_guess) {
                        FormatText_guess(text_guess, 0x3188, tracked_name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    pEverQuest->dsp_chat(text_guess, 0x10e, true);
                }
            }
            if (g_tickDisplay_guess->time_0148_guess > g_tickSkillEnd_guess) {
                g_tickSkillState_guess = -1;
                g_tickSkillTarget_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x3189, 0), 0x10e, true);
            }
        }
    }

    // Hiding (skill 29) breaks when we move from where it started ("You have moved and are no longer
    // hidden!!"), except for a sneaking rogue.
    if (g_tickHiding_guess != 0 || g_tickSkillState_guess == 0x1d) {
        TickPlayer_guess* self_guess = player_guess;
        if (g_tickStartY_guess != static_cast<int>(self_guess->Y) ||
            g_tickStartX_guess != static_cast<int>(self_guess->X) ||
            Abs_guess(g_tickStartZ_guess - static_cast<int>(self_guess->Z)) > 5) {
            if (Base_guess()->Info_guess()->class_119c_guess != Class_Rogue || player_guess == 0 ||
                player_guess->Sneak == 0) {
                if (g_tickSkillState_guess == SkillHide) {
                    g_tickSkillState_guess = -1;
                }
                g_tickHiding_guess = 0;
                if (player_guess != 0 && player_guess->Type == 0) {
                    Base_guess()->GetOwner_guess()->FUN_005ed860_guess(0);
                }
                reinterpret_cast<CharacterObject_guess*>(this)->UpdateInvisibility_guess();
                pEverQuest->dsp_chat(pStringTable->getString(0x318a, 0), 0x10e, true);
            }
        }
    }

    // Camping: standing up cancels it (0x318B); when the timer runs out the client logs out (OP_Logout
    // 0x61FF).
    if (g_tickCampTime_guess != 0) {
        if (player_guess != 0 ? player_guess->StandState != 'n' : Base_guess()->state_00fc_guess > 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x318b, 0), 0x111, true);
            g_tickCampTime_guess = 0;
            g_tickCampTarget_guess = 0;
        }
        unsigned int camp_guess = g_tickCampTime_guess;
        if (camp_guess != 0) {
            if (now_guess >= camp_guess) {
                // Camp done: game state 8, OP_Logout, then up to 3 s for the connection to close.
                LogFailure_guess("*** EXITING: I have completed camping.\n");
                g_tickGameState_guess = 8;
                EQSendMessage(g_tickConnection_guess, OP_Logout, 0, 0, 1);
                g_tickExit_guess->WaitForDisconnect_guess(g_tickConnectionValue_guess, 3000);
                g_tickExiting_guess = 1;
                return true;
            }
            unsigned int previous_guess = g_tickLastCamp_guess;
            g_tickLastCamp_guess = (camp_guess - now_guess) / 1000;
            if (g_tickLastCamp_guess != 0 && previous_guess != g_tickLastCamp_guess &&
                g_tickLastCamp_guess % 5 == 0) {
                FormatText_guess(text_guess, 0x318c, _itoa(g_tickLastCamp_guess, g_tickNumberText_guess, 10), 0, 0,
                                 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(text_guess, 0x111, true);
            }
        }
    }

    // Every second: cooldowns, movement speed from Root and MovementSpeed effects, and the boat being ridden
    // (+0x158, not a pet): its name goes out as OP_BoardBoat (0x4298) when we board, OP_LeaveBoat (0x67C9)
    // once it has been gone for two checks.
    if (now_guess - player_guess->Actor_guess()->time_0054_guess > 1000) {
        TickActor_guess* actor_guess = player_guess->Actor_guess();
        int elapsed_guess = now_guess - actor_guess->time_0054_guess;
        actor_guess->time_0054_guess = now_guess;
        if (player_guess->Type == 0) {
            reinterpret_cast<DynamicPropertyOwner_guess*>(this)->ApplyEnduranceUpkeep_guess();
            g_tickCooldown_guess.TickTributeTimers_guess(Base_guess()->GetCooldownOwner_guess(), elapsed_guess);
            int affect_guess = TotalSpellAffects_guess(SPA_Root, 1, 0, 1);
            if (affect_guess >= 0) {
                affect_guess = TotalSpellAffects_guess(SPA_MovementSpeed, 1, 0, 1);
            }
            ApplyMovementModifier_guess(affect_guess);
            UpdateAllPlayersVisibility_guess();
            g_tickDirtyA_guess = 1;
            if (g_tickOther_guess != g_tickLocal_guess) {
                g_tickDirtyB_guess = 1;
            }
            pc_guess->ProcessAirSupply_guess();
            reinterpret_cast<CostOwner_guess*>(this)->TakeEnvironmentalDamage_guess();
            reinterpret_cast<DynamicPropertyOwner_guess*>(this)->ConsumeCharge_guess();
            if (player_guess == 0) {
                return true;
            }
            if (player_guess->pActorInfo == 0) {
                return true;
            }
            if (player_guess->Actor_guess()->flag_0152_guess != 0) {
                ProcessFishing_guess();
            }
            TickPlayer_guess* pet_guess = player_guess->Actor_guess()->boat_0158_guess;
            if (pet_guess == 0) {
                ++g_tickPetMisses_guess;
                if (g_tickPetMisses_guess >= 2) {
                    g_tickPetMisses_guess = 0;
                    pet_gone_guess = 1;
                    Base_guess()->pet_name_00bc_guess.Set_guess(g_tickEmptyName_guess);
                }
            } else {
                Base_guess()->pet_name_00bc_guess.Set_guess(pet_guess->Name);
                g_tickPetMisses_guess = 0;
            }
            if (player_guess->Actor_guess()->boat_0158_guess == 0) {
                if (pet_gone_guess != 0) {
                    if (g_tickPetSent_guess != 0) {
                        EQSendMessage(g_tickConnection_guess, OP_LeaveBoat, 0, 0, 1);
                    }
                    g_tickPetSent_guess = 0;
                }
            } else {
                if (g_tickPetSent_guess == 0) {
                    char* pet_name_guess = player_guess->Actor_guess()->boat_0158_guess->Name;
                    EQSendMessage(g_tickConnection_guess, OP_BoardBoat, pet_name_guess, strlen(pet_name_guess) + 4, 1);
                }
                g_tickPetSent_guess = 1;
            }
        }
    }

    if (player_guess == 0) {
        return true;
    }
    if (player_guess->pActorInfo == 0) {
        return true;
    }
    // Every 6 s, the buff tick: effects run (FUN_00413ae4_guess returns the attacker of a fatal DoT) and HP,
    // mana and endurance regenerate.
    if (now_guess - player_guess->Actor_guess()->time_0058_guess > 6000) {
        reinterpret_cast<CostOwner_guess*>(this)->ProcessDrunkenness_guess();
        hp_before_guess = reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(player_guess->Type);
        alive_guess = hp_before_guess >= 1;
        unsigned int attacker_guess = ProcessAffects_guess();
        EQPlayer* spawn_guess = reinterpret_cast<EQPlayer*>(GetSpawn_guess(attacker_guess));
        if (player_guess == 0) {
            return true;
        }
        if (player_guess->pActorInfo == 0) {
            return true;
        }
        if (spawn_guess != 0 && spawn_guess->Type == 0) {
            killer_guess = attacker_guess;
        }
        if (player_guess->Type == 0) {
            ++g_tickCounter_guess;
            if (g_tickCounter_guess > 300) {
                // Dead code in the original: the counter is one byte in the binary (inc byte; movzx; cmp
                // 300), so it never passes 300 and this call never happens.
                g_tickEverQuest_guess->SavePC_guess(1, 1, 0xf);
            }
            pc_guess->ProcessFatigue_guess();
            int regen_guess = reinterpret_cast<int>(reinterpret_cast<WrapperObject_guess*>(this)->GetTwo_guess(0, 0)) +
                              value_00a8_guess;
            int extra_guess = reinterpret_cast<int>(reinterpret_cast<WrapperObject_guess*>(this)->GetThree_guess(0, 0));
            int cap_guess = 0x1e;
            if (Base_guess()->Info_guess()->level_11a4_guess > 0x3c) {
                cap_guess = Base_guess()->Info_guess()->level_11a4_guess - 0x1e;
            }
            if (Base_guess()->Info_guess()->level_11a4_guess > 0x41) {
                cap_guess += Base_guess()->Info_guess()->level_11a4_guess - 0x41;
            }
            cap_guess += TotalSpellAffects_guess(SPA_ItemHPRegenCapIncrease, 1, 0, 1);
            if (regen_guess > cap_guess) {
                regen_guess = cap_guess;
            }
            int total_guess = extra_guess + regen_guess;
            reinterpret_cast<CostUpdateView_guess*>(this)->ModifyCurHP_guess(total_guess, 0);
            unsigned char type_guess = player_guess->Type;
            int maximum_guess = reinterpret_cast<CostOwner_guess*>(this)->Max_HP_guess(type_guess);
            if (reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(type_guess) < maximum_guess) {
                int rest_guess = Base_guess()->Info_guess()->GetBaseRegen_guess();
                if (Base_guess()->stand_state_0104_guess == 'n') {
                    if (Base_guess()->Info_guess()->level_11a4_guess >= 0x32) {
                        ++rest_guess;
                        if (Base_guess()->Info_guess()->level_11a4_guess >= 0x41) {
                            ++rest_guess;
                        }
                    }
                    if (g_tickDisplay_guess->time_0148_guess - player_guess->Actor_guess()->time_0070_guess > 60000) {
                        bool clean_guess = true;
                        for (int buff_guess = 0; buff_guess < GetMaxBuffs_guess(); ++buff_guess) {
                            TickBuff_guess* entry_guess = GetBuff_guess(buff_guess);
                            if (entry_guess->type_guess != 0) {
                                int spell_id_guess = entry_guess->spell_guess;
                                if (IsValidSpell_guess(spell_id_guess)) {
                                    TickSpell_guess* spell_guess = g_tickSpells_guess->GetSpell_guess(spell_id_guess);
                                    if (spell_guess != 0 && spell_guess->value_01f4_guess == 0x2e) {
                                        clean_guess = false;
                                    }
                                }
                            }
                        }
                        if (clean_guess) {
                            int minutes_guess = (g_tickDisplay_guess->time_0148_guess -
                                                 player_guess->Actor_guess()->time_0070_guess) /
                                                60000;
                            if (static_cast<unsigned int>(minutes_guess) > 9) {
                                minutes_guess = 9;
                            }
                            if (minutes_guess == 1) {
                                if (Base_guess()->Info_guess()->innates_guess[10] != 0xff) {
                                    TICK_REST_FORMULA_GUESS(rest_guess)
                                } else {
                                    rest_guess = static_cast<int>(rest_guess * g_tickRestFirst_guess);
                                }
                            } else {
                                rest_guess = static_cast<int>(minutes_guess * g_tickRestScale_guess * rest_guess);
                                if (Base_guess()->Info_guess()->innates_guess[10] != 0xff) {
                                    rest_guess = static_cast<int>(rest_guess * g_tickRestBonus_guess);
                                }
                            }
                        } else if (Base_guess()->Info_guess()->innates_guess[10] != 0xff) {
                            TICK_REST_FORMULA_GUESS(rest_guess)
                        }
                    } else if (Base_guess()->Info_guess()->innates_guess[10] != 0xff) {
                        TICK_REST_FORMULA_GUESS(rest_guess)
                    }
                } else if (Base_guess()->Info_guess()->innates_guess[10] != 0xff) {
                    TICK_REST_FORMULA_GUESS(rest_guess)
                }
                if (g_tickNewbieRules_guess != 0 && Base_guess()->Info_guess()->level_11a4_guess < 0x15) {
                    rest_guess = Base_guess()->stand_state_0104_guess == 'n' ? 10 : 6;
                }
                if (pc_guess->Profile_guess()->Info_guess()->value_121c_guess == 0 ||
                    pc_guess->Profile_guess()->Info_guess()->value_1218_guess == 0) {
                    rest_guess = 0;
                }
                if (player_guess != 0 && player_guess->Type == 0) {
                    TickPc_guess* owner_guess = Base_guess()->GetOwner_guess();
                    if (g_tickBonus_guess != 0 && (owner_guess->User_guess()->Base_guess()->flags_0108_guess & 0x40)) {
                        rest_guess += g_tickBonus_guess->GetRegenBonus_guess(owner_guess);
                    }
                }
                if (pc_guess->Profile_guess()->state_00fc_guess == 3) {
                    if (reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(player_guess->Type) < -5 ||
                        rest_guess < 1) {
                        rest_guess = -1;
                        // Unconscious and either below -5 HP or not regenerating: lose 1 HP per tick, "You
                        // are bleeding to death!"
                        pEverQuest->dsp_chat(pStringTable->getString(0x318d, 0), 0xd, true);
                    }
                }
                TickPlayer_guess* self_guess = player_guess;
                if (self_guess != 0) {
                    rest_guess = static_cast<int>(rest_guess * self_guess->field_024 * g_tickScale640e20_guess *
                                                      g_tickScale640038_guess +
                                                  g_tickRound6410a0_guess);
                }
                if (self_guess->Type == 0 && rest_guess + total_guess == 0 &&
                    reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(0) <= 0) {
                    --rest_guess;
                }
                if (rest_guess != 0) {
                    reinterpret_cast<CostUpdateView_guess*>(this)->ModifyCurHP_guess(rest_guess, 0);
                }
                if (reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(player_guess->Type) > 0 &&
                    Base_guess()->state_00fc_guess == 3) {
                    player_guess->GetConscious_guess();
                }
            }
        }
        Base_guess()->FUN_0040e2bd_guess(
            reinterpret_cast<int>(reinterpret_cast<WrapperObject_guess*>(this)->GetThree_guess(0xbd, 0)));
        reinterpret_cast<CharacterStats_guess*>(this)->Cur_Endurance_guess();
        reinterpret_cast<DynamicPropertyBoundOwner_guess*>(this)->RegenMana_guess();
        player_guess->Actor_guess()->time_0058_guess = GetCurrentTime_guess();
    }

    // Every 18 s +0x1220 drops by one, and every minute two flags reset.
    if (now_guess - player_guess->Actor_guess()->time_0074_guess > 18000) {
        if (Base_guess()->Info_guess()->value_1220_guess > 0 && player_guess != 0 &&
            player_guess->pActorInfo != 0) {
            unsigned int client_time_guess = TickClientTime_guess();
            unsigned int* last_guess = &player_guess->Actor_guess()->time_00d4_guess;
            if (client_time_guess - *last_guess > 300) {
                *last_guess = now_guess;
                --Base_guess()->Info_guess()->value_1220_guess;
            }
        }
        player_guess->Actor_guess()->time_0074_guess = GetCurrentTime_guess();
    }
    if (now_guess - player_guess->Actor_guess()->time_0078_guess > 60000) {
        flag_000c_guess = 1;
        flag_00c8_guess = 0;
        player_guess->Actor_guess()->time_0078_guess = GetCurrentTime_guess();
    }
    reinterpret_cast<InventoryView_guess*>(this)->ProcessHungerandThirst_guess(now_guess);

    // Death check (online only, and not while actor +0x68 is set): HP below -10 minus DelayDeath makes a
    // damage record for ourselves, type 0xE7 with the killer when we were alive before this tick, else 0x17.
    if (g_tickFlag923798_guess == 0 && g_tickValue923884_guess == 0) {
        int threshold_guess = -10 - pc_guess->User_guess()->TotalSpellAffects_guess(SPA_DelayDeath, 1, 0, 1);
        int hp_guess = reinterpret_cast<CostOwner_guess*>(this)->Cur_HP(player_guess->Type);
        if (hp_guess < threshold_guess && player_guess->Actor_guess()->value_0068_guess == 0) {
            record_guess.target_guess = static_cast<unsigned short>(player_guess->SpawnID);
            int damage_guess = hp_before_guess - hp_guess;
            record_guess.source_guess = 0;
            record_guess.value_0004_guess = 0;
            if (damage_guess < -32767) {
                damage_guess = -32767;
            }
            if (damage_guess > 32767) {
                damage_guess = 32767;
            }
            record_guess.spell_guess = -1;
            record_guess.value_000a_guess = 0.0f;
            record_guess.damage_0006_guess = damage_guess;
            record_guess.value_000e_guess = 0.0f;
            record_guess.type_guess = 0x17;
            record_guess.value_0012_guess = 0.0f;
            if (alive_guess != 0) {
                record_guess.source_guess = static_cast<unsigned short>(killer_guess);
                record_guess.type_guess = 0xe7;
            }
            OnDamage_guess(&record_guess, 0);
            if (player_guess == 0) {
                return true;
            }
        }
    }

    if (player_guess == 0) {
        return true;
    }
    if (player_guess->pActorInfo == 0) {
        return true;
    }
    // Only when running without a server (0x00923798 or 0x00923884 set): a cast whose time is up is finished
    // here: reagents and channeling (CastingRequirementsMet_guess), then the spell is cast.
    if (player_guess->Actor_guess()->spell_0f98_guess != -1 &&
        now_guess > player_guess->Actor_guess()->time_00d8_guess &&
        (g_tickFlag923798_guess != 0 || g_tickValue923884_guess != 0)) {
        int found_guess = 0;
        TickTargetRef_guess target_guess = player_guess->Actor_guess()->target_1050_guess;
        bool cast_guess = false;
        if (CastingRequirementsMet_guess(player_guess->Actor_guess()->spell_0f98_guess)) {
            if (player_guess->Actor_guess()->item_1048_guess != 0 && target_guess.Find_guess(this) != 0) {
                TickItem_guess* found_item_guess = *target_guess.Find_guess(this);
                if (found_item_guess != 0 && found_item_guess->GetItemClass_guess() == 0 &&
                    found_item_guess == player_guess->Actor_guess()->item_1048_guess) {
                    found_guess = 1;
                }
            }
            char result_guess;
            if (player_guess->Actor_guess()->item_1048_guess != 0) {
                if (found_guess == 0) {
                    FUN_0040f8a0_guess(1);
                    player_guess->Actor_guess()->time_00d8_guess = 0;
                    player_guess->Actor_guess()->item_1048_guess = 0;
                    player_guess->Actor_guess()->flag_104c_guess = 0;
                    player_guess->Actor_guess()->spell_0f98_guess = -1;
                    TickTargetRef_guess* reset_guess = &player_guess->Actor_guess()->target_1050_guess;
                    reset_guess->second_guess = -1;
                    reset_guess->third_guess = -1;
                    reset_guess->first_guess = 0;
                    reset_guess->fourth_guess = 0;
                    return true;
                }
                TickActor_guess* caster_guess = player_guess->Actor_guess();
                result_guess = FUN_0040db49_guess(caster_guess->slot_0f9c_guess, caster_guess->spell_0f98_guess,
                                                  target_guess.Find_guess(this), caster_guess->value_0fa0_guess);
            } else {
                TickActor_guess* caster_guess = player_guess->Actor_guess();
                result_guess = FUN_0040db49_guess(caster_guess->slot_0f9c_guess, caster_guess->spell_0f98_guess, 0,
                                                  caster_guess->value_0fa0_guess);
            }
            if (result_guess) {
                cast_guess = true;
            }
            if (player_guess == 0) {
                return true;
            }
            if (player_guess->pActorInfo == 0) {
                return true;
            }
            player_guess->Actor_guess()->item_1048_guess = 0;
            TickTargetRef_guess* clear_guess = &player_guess->Actor_guess()->target_1050_guess;
            clear_guess->second_guess = -1;
            clear_guess->third_guess = -1;
            clear_guess->first_guess = 0;
            clear_guess->fourth_guess = 0;
            if (Base_guess()->Info_guess()->class_119c_guess == Class_Bard &&
                IsValidSpell_guess(player_guess->Actor_guess()->spell_0f98_guess)) {
                TickSpell_guess* spell_guess =
                    g_tickSpells_guess->GetSpell_guess(player_guess->Actor_guess()->spell_0f98_guess);
                if (spell_guess != 0 && spell_guess->value_002c_guess != 0 &&
                    spell_guess->GetSpellLevelNeeded_guess(8) < 0xff) {
                    FUN_0040f8a0_guess(1);
                }
            }
        }
        player_guess->Actor_guess()->time_00d8_guess = 0;
        if (IsBardSong_guess(g_tickSpells_guess->GetSpell_guess(player_guess->Actor_guess()->spell_0f98_guess),
                               Base_guess()->Info_guess()->class_119c_guess) != 0) {
            if (!cast_guess) {
                FUN_0040f8a0_guess(1);
            } else {
                TickActor_guess* caster_guess = player_guess->Actor_guess();
                TickSpell_guess* spell_guess = g_tickSpells_guess->GetSpell_guess(caster_guess->spell_0f98_guess);
                caster_guess->time_00d8_guess = g_tickDisplay_guess->time_0148_guess + 6000;
                if (spell_guess != 0 && spell_guess->value_001c_guess > 0) {
                    FUN_0040f8a0_guess(0);
                }
            }
        } else {
            FUN_0040f8a0_guess(0);
        }
    }

    // A running social (macro) executes one line per 100 ms; /pause lines wait.
    if (g_tickSocialState_guess == -1) {
        return true;
    }
    int saved_value_guess = g_tickChatValue_guess;
    unsigned char saved_mode_guess = g_tickChatMode_guess;
    if (saved_mode_guess == 7 || saved_mode_guess == 0x13 || saved_mode_guess == 0x14) {
        strcpy(saved_text_guess, g_tickChatText_guess);
    }
    int chat_value_guess = g_tickChatValue_guess;
    int chat_index_guess = 1;
    int chat_mode_guess = g_tickChatMode_guess;
    current_text_guess[0] = 0;
    if (pinstCChatManager_guess != 0 && pinstCChatManager_guess->page_guess != 0) {
        TickHotbarPage_guess* page_guess = pinstCChatManager_guess->page_guess;
        chat_value_guess = page_guess->value_01b0_guess;
        chat_mode_guess = page_guess->type_0168_guess;
        chat_index_guess = page_guess->index_016c_guess;
        strcpy(current_text_guess, page_guess->text_0170_guess);
    }
    g_tickChatValue_guess = chat_value_guess;
    g_tickChatMode_guess = static_cast<unsigned char>(chat_mode_guess);
    if (chat_mode_guess == 7) {
        strcpy(g_tickChatText_guess, current_text_guess);
    } else if (chat_mode_guess == 0x13) {
        TickListA_guess* list_guess = &g_tickEverQuest_guess->list_000c_guess;
        if (list_guess != 0 && list_guess->lookup_0284_guess != 0) {
            const char* found_text_guess = list_guess->lookup_0284_guess->Find_guess(chat_index_guess);
            if (found_text_guess != 0) {
                strcpy(g_tickChatText_guess, found_text_guess);
            }
        }
    } else if (chat_mode_guess == 0x14) {
        TickListB_guess* list_guess = &g_tickEverQuest_guess->list_05b0_guess;
        if (list_guess != 0 && list_guess->lookup_0284_guess != 0) {
            const char* found_text_guess = list_guess->lookup_0284_guess->Find_guess(chat_index_guess);
            if (found_text_guess != 0) {
                strcpy(g_tickChatText_guess, found_text_guess);
            }
        }
    }

    int pause_guess = g_tickSocialPause_guess;
    int line_guess = g_tickSocialState_guess & 7;
    // The running social is packed in one int: bits 0-2 the next line (0-4), bits 3-15 the social id, the
    // rest the pause left.
    int social_guess = (g_tickSocialState_guess >> 3) & 0x1fff;
    if (now_guess - g_tickLastSocial_guess > 100) {
        g_tickLastSocial_guess = now_guess;
        bool store_guess = true;
        if (pause_guess > 0) {
            --pause_guess;
        } else if (social_guess >= 0x78) {
            // Social ids 120 and up are AA hotkeys: "/alternateadv act <n - 120>".
            wsprintfA(command_guess, "%s %s %d", pStringTable->getString(0x3773, 0),
                      pStringTable->getString(0x33d9, 0), social_guess - 0x78);
            g_tickEverQuest_guess->FUN_00498b78_guess(g_tickLocal_guess, command_guess);
            store_guess = false;
        } else {
            TickSocial_guess* entry_guess = &g_tickSocials_guess[social_guess / 12][social_guess % 12];
            do {
                if (strlen(entry_guess->lines_guess[line_guess]) >= 1) {
                    break;
                }
                ++line_guess;
            } while (line_guess <= 4);
            if (line_guess < 5) {
                char* line_text_guess = entry_guess->lines_guess[line_guess];
                // Only "/pau" is compared, but the number is read at offset 7, after "/pause ".
                if (_strnicmp(line_text_guess, "/pause", 4) == 0) {
                    pause_guess = atoi(line_text_guess + 7);
                    if (pause_guess > 600) {
                        // A pause is 1-600 steps of 100 ms. Text after a comma on the same line is run at
                        // once.
                        pause_guess = 600;
                    }
                    if (pause_guess < 1) {
                        pause_guess = 1;
                    }
                    char* rest_text_guess = strstr(line_text_guess, g_tickSeparator_guess);
                    if (rest_text_guess != 0 && strlen(rest_text_guess) > 1) {
                        g_tickEverQuest_guess->FUN_00498b78_guess(g_tickLocal_guess, rest_text_guess + 1);
                    }
                } else {
                    pause_guess = 1;
                    g_tickEverQuest_guess->FUN_00498b78_guess(g_tickLocal_guess, line_text_guess);
                }
                ++line_guess;
            }
        }
        if (store_guess && line_guess <= 4) {
            if (pause_guess < 0) {
                pause_guess = 0;
            }
            if (social_guess >= 0 && line_guess >= 0) {
                g_tickSocialState_guess = (((pause_guess << 13) | social_guess) << 3) | line_guess;
            } else {
                g_tickSocialState_guess = -1;
            }
        } else {
            g_tickSocialState_guess = -1;
        }
    }
    g_tickChatValue_guess = saved_value_guess;
    g_tickChatMode_guess = saved_mode_guess;
    if (saved_mode_guess == 7 || saved_mode_guess == 0x13 || saved_mode_guess == 0x14) {
        strcpy(g_tickChatText_guess, saved_text_guess);
    }
    return true;
}

