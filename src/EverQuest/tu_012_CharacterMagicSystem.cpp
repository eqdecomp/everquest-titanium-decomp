// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 12: a hint from compare/tumap.py.
// CharacterMagicSystem (CharacterMagicSystem.cpp, from the HitBySpell assert path): the character's buffs and
// spell effects. Buff slots 0-24 are the long buffs and 25-59 the short-duration/NPC ones;
// TotalSpellAffects_guess sums one spell effect (SPA) over buffs, AAs and items. Casting (CastSpell),
// stacking (FindSlot_guess), durations, effect amounts and spells landing (HitBySpell) live here.
// MagicStateA_guess is the EQPlayer; pActorInfo_01a8_guess its actor info.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/slots.h"
#include "titanium/classes.h"
#include "titanium/opcodes.h"

void __debugbreak(void);

// EXTERNAL: TITANIUM 0x0060F81E FUN_0060f81e_guess
int __cdecl FUN_0060f81e_guess(int value_guess);

struct MagicDword_guess {
    int value;
};

struct MagicEntry_guess;

struct MagicObject_guess {
    // EXTERNAL: TITANIUM 0x005F0910 MagicObject_guess::GetEntry_guess
    int GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004BAC48 MagicObject_guess::GetItemTimerValue
    unsigned int GetItemTimerValue(MagicEntry_guess* item_guess);
    // EXTERNAL: TITANIUM 0x004BB226 MagicObject_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x004BAC0D MagicObject_guess::SetItemRecastTimer_guess
    void SetItemRecastTimer_guess(MagicEntry_guess* item_guess, unsigned int first_guess,
                            unsigned int second_guess);
};

struct MagicCastRef_guess {
    int field0_guess;
    int field4_guess;
    int field8_guess;
    int fieldC_guess;
    // EXTERNAL: TITANIUM 0x004B72D7 MagicCastRef_guess::GetSlotId_guess
    int GetSlotId_guess();
    void Clear_guess() {
        field4_guess = -1;
        field8_guess = -1;
        fieldC_guess = 0;
        field0_guess = 0;
    }
};

struct MagicSpell_guess {
    char pad_00[0x14];
    unsigned int field14;
    char pad_18[0x20 - 0x18];
    unsigned int field20;
    unsigned int field24;
    char pad_28[0xf0 - 0x28];
    int valuesF0_guess[12];
    char pad_120[0x17d - 0x120];
    char field17d;
    // EXTERNAL: TITANIUM 0x0044E77B MagicSpell_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int value_guess);
};

struct MagicCheck_guess {
    int id_guess;
    float range_guess;
    char pad_08[4];
    float field0C_guess;
    float field10_guess;
    unsigned int field14_guess;
    char pad_18[4];
    int field1C_guess;
    int field20;
    unsigned int field24_guess;
    char pad_28[4];
    int field2C_guess;
    int values30_guess[12];
    int values60_guess[12];
    int values90_guess[12];
    int valuesC0_guess[4];
    int valuesD0_guess[4];
    union {
        int fieldE0_guess;
        int valuesE0_guess[4];
    };
    int valuesF0_guess[12];
    int values_120[12];
    int field150_guess;
    char pad_150[0x17d - 0x154];
    char field17d;
    char field17E_guess;
    char pad_17f;
    unsigned char field180_guess;
    char pad_181;
    char field182_guess;
    char pad_183[0x188 - 0x183];
    unsigned char field188_guess;
    char pad_189[0x191 - 0x189];
    char field191_guess;
    char field192;
    char pad_193;
    int field194_guess;
    char pad_198[0x1bc - 0x198];
    int field1BC_guess;
    char pad_1c0[4];
    unsigned char field1C4_guess;
    char pad_1c5[0x1c8 - 0x1c5];
    int field1C8_guess;
    char pad_1cc[4];
    int field1D0_guess;
    int field1D4_guess;
    char pad_1d8[0x1ec - 0x1d8];
    unsigned int field1ec_guess;
    unsigned int field1f0_guess;
    char pad_1f4[4];
    int field1F8_guess;
    char field1fc;
    char pad_1fd[0x208 - 0x1fd];
    char* field208_guess;
    char pad_20c[4];
    char* field210_guess;
    char pad_214[0x26c - 0x214];
    int field26C_guess;
    char Check_guess();
    int GetF0_guess(unsigned int index_guess) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        return valuesF0_guess[index_guess];
    }
    int Get30_guess(unsigned int index_guess) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        return values30_guess[index_guess];
    }
    int Get90_guess(unsigned int index_guess) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        return values90_guess[index_guess];
    }
    int Get60_guess(unsigned int index_guess) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        return values60_guess[index_guess];
    }
    int GetC0_guess(unsigned int index_guess) {
        if (index_guess >= 4) {
            __debugbreak();
        }
        return valuesC0_guess[index_guess];
    }
    int GetD0_guess(unsigned int index_guess) {
        if (index_guess >= 4) {
            __debugbreak();
        }
        return valuesD0_guess[index_guess];
    }
    int GetE0_guess(unsigned int index_guess) {
        if (index_guess >= 4) {
            __debugbreak();
        }
        return valuesE0_guess[index_guess];
    }
    int GetType_guess(unsigned int index_guess) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        return values_120[index_guess];
    }
    // EXTERNAL: TITANIUM 0x0044E755 MagicCheck_guess::CheckMode_guess
    unsigned char CheckMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0044D0ED MagicCheck_guess::KeepsInvisibility_guess
    char KeepsInvisibility_guess();
    // EXTERNAL: TITANIUM 0x0044D0E6 MagicCheck_guess::FUN_0044d0e6_guess
    char FUN_0044d0e6_guess();
    // EXTERNAL: TITANIUM 0x0044E77B MagicCheck_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0044E79F MagicCheck_guess::IsIllusion_guess
    int IsIllusion_guess();
};

struct MagicLookup_guess {
    char padTo48_guess[0x48];
    void* field48_guess;
    // EXTERNAL: TITANIUM 0x0040CBD6 MagicLookup_guess::GetSpell_guess
    MagicCheck_guess* GetSpell_guess(int id_guess);
};

struct MagicEntryProbe_guess {
    char active_guess;
    char casterLevel_0001_guess;
    union {
        char padTo04_guess[2];
        unsigned char scale_guess;
    };
    int id_guess;
    int unknown08_guess;
    int counters_000c_guess;
    int unknown10_guess;
};

struct MagicResult_guess {
    char padTo10_guess[0x10];
    int values10_guess[(0x550 - 0x10) / 4];
    unsigned int values550_guess[60];
    char padToF30_guess[0x8f0];
    unsigned int values_guess[16];
    unsigned int valuesF70_guess[100];
    unsigned int values1100_guess[25];
    char pad2_guess[0x1194 - 0x1164];
    unsigned char gender_1194_guess;
    char pad1198_guess[3];
    unsigned int race_1198_guess;
    unsigned char class_119c_guess;
    char pad3_guess[0x11a4 - 0x119d];
    int level_11a4_guess;
    int mana_11a8_guess;
    int field11AC_guess;
    char pad11FC_guess[0x11fc - 0x11b0];
    float field11FC_guess;
    void SetBuffCasterId_guess(unsigned int index_guess, unsigned int value_guess);
    void Set1100_guess(unsigned int index_guess, unsigned int value_guess);
};

struct MagicOffset_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct MagicList_guess {
    union {
        MagicOffset_guess* offsetHolder_guess;
        char tableBytes_guess[1];
    };
    // EXTERNAL: TITANIUM 0x005EC220 MagicList_guess::GetCharInfo2
    MagicResult_guess* GetCharInfo2();
};

struct MagicResolveContainer_guess {
    int pad_guess;
    MagicList_guess list_guess;
};

struct MagicStateA_guess;
struct CharacterMagicSystem_guess;

struct MagicPoint_guess {
    float y_guess;
    float x_guess;
};

struct MagicStateB_guess {
    char padTo08_guess[0x08];
    union {
        char name08_guess[0xc0];
        struct {
            char padToAC_guess[0xac - 0x08];
            unsigned char fieldAC_guess;
            char padToC8_guess[0xc8 - 0xad];
            float fieldC8_guess;
        };
        struct {
            char padTo48b_guess[0x48 - 0x08];
            float field48_guess;
        };
    };
    char padToD0_guess[0xd0 - 0xcc];
    int fieldD0_guess;
    char padToD8_guess[0xd8 - 0xd4];
    int fieldD8_guess;
    char padToE8_guess[0xe8 - 0xdc];
    int fieldE8_guess[9];
    int field10C_guess;
    int field110_guess;
    char padTo154_guess[0x154 - 0x114];
    unsigned char field154_guess;
    char padTo158_guess[0x158 - 0x155];
    int field158_guess;
    MagicStateA_guess* field15C_guess;
    char padTo1B0_guess[0x1b0 - 0x160];
    float field1B0_guess;
    char padToF98_guess[0xf98 - 0x1b4];
    int fieldF98_guess;
    char fieldF9C_guess;
    char padToFA0_guess[0xfa0 - 0xf9d];
    int fieldFA0_guess;
    int fieldFA4_guess;
    char padToFF8_guess[0xff8 - 0xfa8];
    float fieldFF8_guess;
    float fieldFFC_guess;
    char padTo1044_guess[0x1044 - 0x1000];
    char field1044_guess;
    char padTo1048_guess[3];
    int field1048_guess;
    char field104C_guess;
    char padTo1050_guess[3];
    MagicCastRef_guess ref1050_guess;
};

struct MagicStateA_guess {
    char padTo30_guess[0x30];
    MagicPoint_guess position_guess;
    float field38_guess;
    float field3C_guess;
    float field40_guess;
    float field44_guess;
    float speedRun_0048_guess;
    float heading_guess;
    char padTo58_guess[0x58 - 0x50];
    float field58_guess;
    char padTo120_guess[0x120 - 0x5c];
    union {
        int values120_guess[12];
        char name120_guess[0x30];
    };
    char padTo1A8_guess[0x1a8 - 0x150];
    MagicStateB_guess* pActorInfo_01a8_guess;
    char padTo1B5_guess[0x1b5 - 0x1ac];
    char isPet_01b5_guess;
    char padTo204_guess[0x204 - 0x1b6];
    int field204_guess;
    char padTo218_guess[0x218 - 0x208];
    CharacterMagicSystem_guess* pCharInfo_0218_guess;
    char padTo230_guess[0x230 - 0x21c];
    float runSpeed_0230_guess;
    char padTo238_guess[4];
    float heightOffset_0238_guess;
    float avatarHeight_023c_guess;
    char padTo244_guess[0x244 - 0x240];
    unsigned char type_0244_guess;
    char padTo24C_guess[0x24c - 0x245];
    unsigned char level_024c_guess;
    char padTo24E_guess[0x24e - 0x24d];
    unsigned char gender_024e_guess;
    char padTo250_guess;
    unsigned char hideMode_0250_guess;
    unsigned char standState_0251_guess;
    unsigned char playerClass_0252_guess;
    char padTo254_guess[0x254 - 0x253];
    unsigned char equipChest2_0254_guess;
    char padTo256_guess[0x256 - 0x255];
    unsigned char gm_0256_guess;
    char padTo258_guess[0x258 - 0x257];
    unsigned int spawnId_0258_guess;
    unsigned int masterId_025c_guess;
    char padTo260_guess[4];
    int anon_0264_guess;
    char padTo270_guess[0x270 - 0x268];
    int bodyType_0270_guess;
    int hpCurrent_0274_guess;
    char padTo284_guess[0x284 - 0x278];
    int hpMax_0284_guess;
    // EXTERNAL: TITANIUM 0x00483958 MagicStateA_guess::MountEQPlayer_guess
    void MountEQPlayer_guess(int target_guess);
    // EXTERNAL: TITANIUM 0x0047A7F3 MagicStateA_guess::CanFitIllusionRace_guess
    char CanFitIllusionRace_guess(int first_guess, unsigned char second_guess, float third_guess);
    // EXTERNAL: TITANIUM 0x0047CF4C MagicStateA_guess::IsLevitating_guess
    int IsLevitating_guess();
    // EXTERNAL: TITANIUM 0x0047E7EE MagicStateA_guess::IsInvisibleToMe_guess
    char IsInvisibleToMe_guess(MagicStateA_guess* target_guess);
    // EXTERNAL: TITANIUM 0x00483439 MagicStateA_guess::headEnvironmentChange_guess
    void headEnvironmentChange_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x0047BFBC MagicStateA_guess::Query_guess
    unsigned int Query_guess();
    // EXTERNAL: TITANIUM 0x00483556 MagicStateA_guess::Notify_guess
    void Notify_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047A64D MagicStateA_guess::SetLevitate_guess
    void SetLevitate_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00479482 MagicStateA_guess::TurnOffAutoFollow_guess
    void TurnOffAutoFollow_guess();
    // EXTERNAL: TITANIUM 0x00479E02 MagicStateA_guess::LegalPlayerRace_guess
    int LegalPlayerRace_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047E35C MagicStateA_guess::GetModelAtSpawnSpot_guess
    char GetModelAtSpawnSpot_guess(char* buffer_guess, int count_guess);
    // EXTERNAL: TITANIUM 0x0047A741 MagicStateA_guess::SetRace_guess
    void SetRace_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047FA9E MagicStateA_guess::SetHeights_guess
    void SetHeights_guess();
    // EXTERNAL: TITANIUM 0x004798D7 MagicStateA_guess::GetActorTag_guess
    void GetActorTag_guess(char* value_guess);
    // EXTERNAL: TITANIUM 0x0047C10D MagicStateA_guess::SetHideMode_guess
    void SetHideMode_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00480409 MagicStateA_guess::UpdatePlayerVisibility_guess
    void UpdatePlayerVisibility_guess();
    // EXTERNAL: TITANIUM 0x0047994F MagicStateA_guess::NotOnSameDeity_guess
    int NotOnSameDeity_guess(MagicStateA_guess* caster_guess, MagicCheck_guess* spell_guess);
    // EXTERNAL: TITANIUM 0x0047C2FB MagicStateA_guess::GetPcClient_guess
    MagicObject_guess* GetPcClient_guess();
    // EXTERNAL: TITANIUM 0x0047A018 MagicStateA_guess::FUN_0047a018_guess
    char FUN_0047a018_guess();
    // EXTERNAL: TITANIUM 0x0047E912 MagicStateA_guess::AllowedToAttack_guess
    char AllowedToAttack_guess(MagicStateA_guess* target_guess, int spellId_guess);
    // EXTERNAL: TITANIUM 0x0047BB72 MagicStateA_guess::IsPathClear_guess
    char IsPathClear_guess(float y_guess, float x_guess, float z_guess, float angle_guess,
                            float distance_guess);
    // EXTERNAL: TITANIUM 0x00479EE8 MagicStateA_guess::PlaySound_guess
    void PlaySound_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0048A0FC MagicStateA_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float y_guess, float x_guess, float z_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0048A945 MagicStateA_guess::FUN_0048a945_guess
    void FUN_0048a945_guess();
    // EXTERNAL: TITANIUM 0x00479D72 MagicStateA_guess::FUN_00479d72_guess
    void FUN_00479d72_guess();
};

struct MagicService_guess {
    // EXTERNAL: TITANIUM 0x0060CF00 MagicService_guess::HasEffect_guess
    char HasEffect_guess(int value_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0060CF40 MagicService_guess::Init_guess
    void Init_guess();
    // EXTERNAL: TITANIUM 0x0060CED0 MagicService_guess::GetThree_guess
    int GetThree_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
    // EXTERNAL: TITANIUM 0x0060CE30 MagicService_guess::Set_guess
    void Set_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0060CF30 MagicService_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0060CE70 MagicService_guess::GetValue_guess
    int GetValue_guess(int type_guess, int extra_guess);
    // EXTERNAL: TITANIUM 0x0060CEA0 MagicService_guess::GetPair_guess
    int GetPair_guess(int type_guess, int extra_guess);
    // EXTERNAL: TITANIUM 0x0060CDE0 MagicService_guess::Add_guess
    void Add_guess(int value_guess, int type_guess, int extra_guess);
    // EXTERNAL: TITANIUM 0x0060CDA0 MagicService_guess::Store_guess
    void Store_guess(int value_guess, int type_guess, int extra_guess, char flag_guess);
};

struct MagicTable_guess;
struct MagicCaster_guess;
struct MagicEntry_guess;
struct MagicPredicateObject_guess;
struct MagicHitPacket_guess;

struct Position_guess {
    char padTo30_guess[0x30];
    float x_guess;
    float y_guess;
    float z_guess;
};

struct CharacterMagicSystem_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual MagicEntry_guess* Slot05_guess(int index_guess);
    MagicList_guess list_guess;
    MagicStateA_guess* pSpawn_0008_guess;
    char ReturnTrue_guess(int first_guess, int second_guess, int third_guess, int fourth_guess);
    char IsBuffLevelBlocked_guess(MagicPredicateObject_guess* target_guess,
                         CharacterMagicSystem_guess* other_guess);
    // EXTERNAL: TITANIUM 0x0040DB0B CharacterMagicSystem_guess::IsBardSong_guess
    int IsBardSong_guess(MagicPredicateObject_guess* target_guess, int type_guess);
    void CheckState_guess(int first_guess, int second_guess);
    void Refresh_guess();
    void eqspa_locate_corpse_guess();
    // EXTERNAL: TITANIUM 0x00417669 CharacterMagicSystem_guess::FindClosest_guess
    EQPlayer* FindClosest_guess(int first_guess, int second_guess, int third_guess, int fourth_guess,
                                int fifth_guess);
    void SetFlag_guess(char value_guess);
    unsigned int GetTransformed_guess();
    void SetField11A8_guess(int value_guess);
    void AddField11A8_guess(int value_guess);
    void AddField11AC_guess(int value_guess);
    void SetBuffCasterId_guess(int first_guess, int second_guess);
    void Write1100_guess(int first_guess, int second_guess);
    int GetStateAdjustment_guess(char first_guess, char second_guess);
    int IsInRestrictedArea_guess(Position_guess* pos_guess);
    unsigned int GetMemorizedSpell_guess(unsigned int index_guess);
    unsigned int GetSkill_guess(unsigned int index_guess);
    unsigned int Read1100_guess(unsigned int index_guess);
    unsigned int GetBuffCasterId_guess(unsigned int index_guess);
    int GetAACastingTimeModifier(MagicSpell_guess* spell_guess);
    int IsReady_guess();
    unsigned int GetValue_guess(int index_guess);
    int GetBestRank_guess(int value_guess);
    char IsEntryUsable_guess(int index_guess);
    char GetStateFlag_guess();
    MagicEntryProbe_guess* GetBuff_guess(int index_guess);
    int ProcessAffects_guess();
    int CalcAffectChange_guess(MagicCheck_guess* spell_guess, unsigned char value_guess,
                           int slot_guess, MagicEntryProbe_guess* entry_guess);
    int CalcScaledAffectChange_guess(unsigned int effect_guess, MagicEntryProbe_guess* entry_guess,
                           int slot_guess, MagicCheck_guess* spell_guess);
    // EXTERNAL: TITANIUM 0x00417EE7 CharacterMagicSystem_guess::Cur_Mana_guess
    int Cur_Mana_guess();
    // EXTERNAL: TITANIUM 0x00417E67 CharacterMagicSystem_guess::Cur_Endurance_guess
    int Cur_Endurance_guess();
    // EXTERNAL: TITANIUM 0x00417948 CharacterMagicSystem_guess::UnStunMe_guess
    void UnStunMe_guess();
    // EXTERNAL: TITANIUM 0x0041AB7E CharacterMagicSystem_guess::ModifyCurHP_guess
    void ModifyCurHP_guess(int amount_guess, int zero_guess);
    void RemovePCAffectex_guess(MagicEntryProbe_guess* entryValue_guess, int send_guess);
    char IsBlockedByStackingCommand_guess(MagicCheck_guess* spell_guess, char type_guess);
    // EXTERNAL: TITANIUM 0x00411EA4 CharacterMagicSystem_guess::FUN_00411ea4_guess
    int FUN_00411ea4_guess(char ready_guess, char flag_guess, int slot_guess);
    MagicEntryProbe_guess* FindBuffSlot_guess(int spellId_guess, MagicStateA_guess* caster_guess,
                                          int* outIndex_guess, int noRemove_guess);
    // EXTERNAL: TITANIUM 0x0041BF92 CharacterMagicSystem_guess::InitInnates_guess
    void InitInnates_guess(int first_guess, unsigned char second_guess);
    // EXTERNAL: TITANIUM 0x0041A44A CharacterMagicSystem_guess::UpdateInvisibility_guess
    void UpdateInvisibility_guess();
    MagicEntryProbe_guess* FindBuffWithEffect_guess(int value_guess, int* index_guess);
    char GetBuffLevelBySpell_guess(int value_guess);
    unsigned int SpellDuration_guess(MagicSpell_guess* spell_guess, unsigned char level_guess,
                                    char flag_guess);
    int ActivateEffect_guess(MagicCaster_guess* caster_guess, int id_guess, int type_guess,
                             int unused_guess, int extra_guess);
    void RefreshFromState_guess(int value_guess);
    void InitializeThree_guess();
    void StopSpellCast_guess(char first_guess, int second_guess);
    void InitializeSpellAffects_guess();
    // EXTERNAL: TITANIUM 0x0040F8C3 CharacterMagicSystem_guess::FinishSpellAffects_guess
    void FinishSpellAffects_guess();
    // EXTERNAL: TITANIUM 0x00417B9C CharacterMagicSystem_guess::GetSpellAffect_guess
    int GetSpellAffect_guess(int affect_guess, int subindex_guess);
    // EXTERNAL: TITANIUM 0x00417BA7 CharacterMagicSystem_guess::GetAltAffect_guess
    int GetAltAffect_guess(int affect_guess, int subindex_guess);
    // EXTERNAL: TITANIUM 0x00417BCF CharacterMagicSystem_guess::GetItemAffect_guess
    int GetItemAffect_guess(int affect_guess, int subindex_guess);
    int TotalSpellAffects_guess(int affect_guess, bool includeAlt_guess, int subindex_guess, int includeItems_guess);
    char CheckCast_guess(unsigned char mode_guess, MagicPredicateObject_guess* spell_guess);
    int GetDelayFromState_guess(char first_guess, char second_guess, char third_guess);
    int GetSpellDuration_guess(MagicCheck_guess* check_guess, unsigned char amount_guess,
                           char flag_guess);
    void ApplyMovementModifier_guess(int amount_guess);
    char CastSpell(unsigned char slot_guess, int spellId_guess,
                         MagicEntry_guess** itemRef_guess, MagicCastRef_guess ref_guess,
                         int altIndex_guess);
    // EXTERNAL: TITANIUM 0x004179AA CharacterMagicSystem_guess::NotifyPCAffectChange_guess
    void NotifyPCAffectChange_guess(int index_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x004192AA CharacterMagicSystem_guess::CanUseItem_guess
    int CanUseItem_guess(MagicEntry_guess* item_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0040D738 CharacterMagicSystem_guess::GetFocusRangeModifier_guess
    int GetFocusRangeModifier_guess(MagicCheck_guess* spell_guess, int* out_guess);
    // EXTERNAL: TITANIUM 0x0040D663 CharacterMagicSystem_guess::GetFocusCastingTimeModifier
    int GetFocusCastingTimeModifier(MagicCheck_guess* spell_guess, int* out_guess);
    int GetInstrumentModifier_guess(int value_guess);
    char CastingRequirementsMet_guess(int spellId_guess);
    // EXTERNAL: TITANIUM 0x0041ACE9 CharacterMagicSystem_guess::Skill_guess
    int Skill_guess(int skill_guess);
    // EXTERNAL: TITANIUM 0x0041D773 CharacterMagicSystem_guess::FindItemById_guess
    char FindItemById_guess(int id_guess, int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00424058 CharacterMagicSystem_guess::FUN_00424058_guess
    char FUN_00424058_guess(int id_guess, int count_guess);
    // EXTERNAL: TITANIUM 0x0040D59B CharacterMagicSystem_guess::GetFocusReagentSaveChance_guess
    int GetFocusReagentSaveChance_guess(MagicCheck_guess* spell_guess, int* out_guess);
    // EXTERNAL: TITANIUM 0x0041DB52 CharacterMagicSystem_guess::RemoveOneItem_guess
    char RemoveOneItem_guess(int slot_guess, int id_guess);
    // EXTERNAL: TITANIUM 0x0041C8F4 CharacterMagicSystem_guess::HasSkillChecked_guess
    int HasSkillChecked_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x00417E07 CharacterMagicSystem_guess::Cur_HP
    void Cur_HP(int type_guess);
    // EXTERNAL: TITANIUM 0x00417834 CharacterMagicSystem_guess::FUN_00417834_guess
    int FUN_00417834_guess(int value_guess, MagicStateA_guess* caster_guess,
                           MagicCheck_guess* spell_guess);
    // EXTERNAL: TITANIUM 0x00451A94 CharacterMagicSystem_guess::FUN_00451a94_guess
    void FUN_00451a94_guess(const char* name_guess, int value_guess);
    void HitBySpell(MagicHitPacket_guess* packet_guess, int amount_guess);
    void ReapplyBuffEffects_guess(int mode_guess);
    MagicTable_guess* GetTable_guess() {
        return (MagicTable_guess*)&list_guess.tableBytes_guess[list_guess.offsetHolder_guess->vbaseOffset_0004_guess];
    }
    MagicResult_guess* ResolveResult_guess();
    char fieldC_guess;
    char padTo18_guess[0x18 - 0xd];
    int field18_guess;
    int field1C_guess;
    int field20_guess;
    char padTo28_guess[0x28 - 0x24];
    int field28_guess;
    int field2C_guess;
    char padTo9C_guess[0x9c - 0x30];
    int field9C_guess;
    char padToB8_guess[0xb8 - 0xa0];
    int fieldB8_guess;
    char padToC4_guess[0xc4 - 0xbc];
    MagicService_guess service_C4_guess;
    char padToC8_guess[0xc8 - 0xc5];
    char fieldC8_guess;
    char padToD0_guess[0xd0 - 0xc9];
    char flagD0_guess;
    char padTo100_guess[0x100 - 0xd1];
    unsigned char field100_guess;
    char padTo17D_guess[0x17d - 0x101];
    char field17D_guess;
    char padTo19B_guess[0x1d];
    char field19B_guess;
    char padTo9C64_guess[0x9ac8];
    unsigned int values9C64_guess[10000];
    char padTo138A8_guess[0x4];
    unsigned int field138A8_guess;
};

struct MagicRecord20_guess {
    unsigned int words_guess[5];
};

struct MagicRecordTable_guess {
    char pad_guess[0xa0];
    MagicRecord20_guess recordsA_guess[25];
    MagicRecord20_guess recordsB_guess[35];
    MagicRecord20_guess* GetRecordA_guess(unsigned int index_guess);
    MagicRecord20_guess* GetRecordB_guess(unsigned int index_guess);
};

struct CopyBuffer64_guess {
    char bytes_guess[64];
    char Copy_guess(const char* input_guess);
};

struct MagicPredicateObject_guess {
    char padTo20_guess[0x20];
    int field20_guess;
    char padTo2C_guess[0x2c - 0x24];
    int field2C_guess;
    char padTo17D_guess[0x17d - 0x30];
    unsigned char field17D_guess;
    char padTo180_guess[0x180 - 0x17e];
    unsigned char field180_guess;
    unsigned char field181_guess;
    unsigned char field182_guess;
    char padTo1C4_guess[0x1c4 - 0x183];
    char field1C4_guess;
    // EXTERNAL: TITANIUM 0x0044E755 MagicPredicateObject_guess::Check_guess
    unsigned char Check_guess(int value_guess);
};

struct MagicMode_guess {
    char padTo180_guess[0x180];
    unsigned char mode_guess;
    char IsAccepted_guess();
};

struct MagicEntry_guess;

struct MagicTable_guess {
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
    virtual int Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual MagicObject_guess* GetObject_guess();
    MagicList_guess service_guess;
    // EXTERNAL: TITANIUM 0x0040E2A8 MagicTable_guess::AddField11A8_guess
    void AddField11A8_guess(int value_guess);
    char padTo2C_guess[0x2c - 0x8];
    float field2C_guess;
    float field30_guess;
    float field34_guess;
    float field38_guess;
    char padToFC_guess[0xfc - 0x3c];
    unsigned char fieldFC_guess;
    char padTo100_guess[3];
    int field100_guess;
    unsigned char field104_guess;
    char padTo10C_guess[0x10c - 0x105];
    unsigned char flag10C_guess;
    char padTo114_guess[0x114 - 0x10d];
    int field114_guess;
    // EXTERNAL: TITANIUM 0x0040CC50 MagicTable_guess::GetFirst_guess
    MagicEntry_guess* GetFirst_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x0040CC6B MagicTable_guess::GetSecond_guess
    MagicEntry_guess* GetSecond_guess(unsigned int index_guess);
};

struct MagicEffect_guess {
    int type_guess;
    int offset_guess;
    int value_guess;
};

struct MagicIterator_guess {
    int active_guess;
    MagicEffect_guess* head_guess;
    int unknown08_guess;
    MagicEffect_guess* current_guess;
    // EXTERNAL: TITANIUM 0x0040CC1F MagicIterator_guess::Take_guess
    MagicEffect_guess* Take_guess();
};

struct MagicEntry_guess {
    int type_guess;
    int offset_guess;
    int value_guess;
    char pad0c_guess[0x18 - 0xc];
    int field18_guess;
    char pad1c_guess[0x58 - 0x1c];
    int field58_guess;
    MagicIterator_guess iterator_guess;
    // EXTERNAL: TITANIUM 0x005E05B0 MagicEntry_guess::GetRecastTime_guess
    unsigned int GetRecastTime_guess();
    // EXTERNAL: TITANIUM 0x005E05F0 MagicEntry_guess::FUN_005e05f0_guess
    unsigned int FUN_005e05f0_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 MagicEntry_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E1140 MagicEntry_guess::FUN_005e1140_guess
    int FUN_005e1140_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E11A0 MagicEntry_guess::FUN_005e11a0_guess
    int FUN_005e11a0_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0D70 MagicEntry_guess::FUN_005e0d70_guess
    int FUN_005e0d70_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 MagicEntry_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0BC0 MagicEntry_guess::GetField98_guess
    int GetField98_guess();
    // EXTERNAL: TITANIUM 0x005E0BF0 MagicEntry_guess::GetField240_guess
    int GetField240_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 MagicEntry_guess::GetCount_guess
    int GetCount_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E1170 MagicEntry_guess::GetRaw_guess
    int GetRaw_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 MagicEntry_guess::GetChild_guess
    MagicEntry_guess* GetChild_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E3160 MagicEntry_guess::GetRank_guess
    int GetRank_guess(int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x0044791F MagicEntry_guess::CanClassUse_guess
    char CanClassUse_guess(int index_guess);
};

struct MagicTableView_guess {
    // EXTERNAL: TITANIUM 0x00447D07 MagicTableView_guess::GetAltAbility
    MagicEntry_guess* GetAltAbility(int key_guess);
};

struct MagicNameContainer_guess {
    char padTo3C_guess[0x3c];
    char name_guess[64];
};

struct MagicMessageRouter_guess {
    // EXTERNAL: TITANIUM 0x004982C6 MagicMessageRouter_guess::dsp_chat
    void dsp_chat(const char* text_guess, int channel_guess, bool flag_guess);
    // EXTERNAL: TITANIUM 0x00494C09 MagicMessageRouter_guess::IsOkToTransact_guess
    char IsOkToTransact_guess();
    // EXTERNAL: TITANIUM 0x004A1CE4 MagicMessageRouter_guess::CancelSneakHide
    void CancelSneakHide();
    // EXTERNAL: TITANIUM 0x0049B39D MagicMessageRouter_guess::StartCasting_guess
    void StartCasting_guess(void* packet_guess);
};

struct MagicTimer_guess {
    // EXTERNAL: TITANIUM 0x0060CA90 MagicTimer_guess::Check_guess
    int Check_guess(int value_guess);
};

#define g_tableView_guess EQ_GLOBAL(MagicTableView_guess*, 0x008511D8)
#define g_magicLookup_guess EQ_GLOBAL(MagicLookup_guess*, 0x00985CC8)
#define g_magicRate_guess EQ_GLOBAL(float, 0x00640038)
#define g_magicOverride_guess EQ_GLOBAL(char, 0x009237B4)
#define g_modeCode_guess EQ_GLOBAL(int, 0x00900478)

struct MagicFloatEntry_guess {
    char pad40_guess[0x40];
    float value40_guess;
};

struct MagicSession_guess {
    // EXTERNAL: TITANIUM 0x00439AFB MagicSession_guess::TurnInfravisionEffectOff_guess
    void TurnInfravisionEffectOff_guess();
    // EXTERNAL: TITANIUM 0x00439E0F MagicSession_guess::SetViewActorByName_guess
    void SetViewActorByName_guess(int* stateValues_guess);
    // EXTERNAL: TITANIUM 0x00440F51 MagicSession_guess::FUN_00440f51_guess
    void FUN_00440f51_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00439D16 MagicSession_guess::PlayerDistance_guess
    float PlayerDistance_guess(MagicStateA_guess* first_guess, MagicStateA_guess* second_guess,
                             float third_guess);
    char padTo148_guess[0x148];
    int field148_guess;
};

#define g_magicSession_guess EQ_GLOBAL(MagicSession_guess*, 0x00905D24)
#define g_magicWorld_guess EQ_GLOBAL(MagicStateA_guess*, 0x00905CE4)
#define g_cameras_guess EQ_ARRAY(MagicFloatEntry_guess*, 0x009254FC)
#define g_magicSlotIndex_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_magicCurrent_guess EQ_GLOBAL(MagicStateA_guess*, 0x00905D04)
#define g_magicLinked_guess EQ_GLOBAL(MagicStateA_guess*, 0x00905CF8)
#define g_magicMessageRouter_guess EQ_GLOBAL(MagicMessageRouter_guess*, 0x00988DF0)
#define g_magicPredicate_guess EQ_GLOBAL(MagicPredicateObject_guess*, 0x00985CC8)
#define g_magicCountA_guess EQ_GLOBAL(int, 0x009248D4)
#define g_magicCountB_guess EQ_GLOBAL(int, 0x009248D0)
#define g_magicSendFlag_guess EQ_GLOBAL(char, 0x00923798)
#define g_magicSendCount_guess EQ_GLOBAL(int, 0x00923884)
#define g_magicLastTarget_guess EQ_GLOBAL(int, 0x00924684)
#define g_magicTimer_guess EQ_GLOBAL(MagicTimer_guess, 0x009248E0)

// EXTERNAL: TITANIUM 0x00464E9C FUN_00464e9c_guess
char __cdecl FUN_00464e9c_guess(int worldValue_guess, int system_guess, MagicCheck_guess* spell_guess);

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination_guess, const char* source_guess, int size_guess);

// EXTERNAL: TITANIUM 0x0047981D FindPlayerByPartialDisplayName_guess
int __cdecl FindPlayerByPartialDisplayName_guess(const char* name_guess, int zero_guess);

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int low_guess, int high_guess);

// EXTERNAL: TITANIUM 0x004805E9 UpdateAllPlayersVisibility_guess
void __cdecl UpdateAllPlayersVisibility_guess();

inline MagicResult_guess* CharacterMagicSystem_guess::ResolveResult_guess() {
    MagicTable_guess* table_guess = GetTable_guess();
    return table_guess->service_guess.GetCharInfo2();
}

// EXTERNAL: TITANIUM 0x00401B28 Transform_guess
int __cdecl Transform_guess(unsigned int value_guess);

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value_guess);

// EXTERNAL: TITANIUM 0x004649B1 token_string_to_client_guess
void __cdecl token_string_to_client_guess(CharacterMagicSystem_guess* system_guess, int value_guess,
                                int flag_guess, int zero_guess);

// EXTERNAL: TITANIUM 0x004168BD normal_to_special_guess
int __cdecl normal_to_special_guess(unsigned char spell_guess);

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess();

struct MagicManaAccess_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual int GetMana_guess();
};

// Throws (int 0) on a null pointer; used before unchecked copies.
// FUNCTION: TITANIUM 0x0040D830
void __cdecl Validate_guess(int value_guess) {
    if (value_guess == 0) {
        throw 0;
    }
}

// True for spell target types (+0x180) aimed at the current target: 5, 7-23, 27, 28, 30, 34, 35, 38, 39
// and 43. Casting runs the line-of-sight check (string 108) only for these, and type 6 (self) is tested
// separately.
// FUNCTION: TITANIUM 0x0040D84D
char MagicMode_guess::IsAccepted_guess() {
    switch (mode_guess) {
    case 0x05:
    case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b:
    case 0x0c: case 0x0d: case 0x0e: case 0x0f: case 0x10:
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15:
    case 0x16: case 0x17: case 0x1b: case 0x1c: case 0x1e:
    case 0x22: case 0x23: case 0x26: case 0x27: case 0x2b:
        return 1;
    default:
        return 0;
    }
}

// Copies at most 63 characters into the 64-byte buffer; false (and truncated) when the input was longer.
// FUNCTION: TITANIUM 0x0040E25C
char CopyBuffer64_guess::Copy_guess(const char* input_guess) {
    Validate_guess((int)input_guess);
    unsigned int index_guess = 0;
    do {
        char value_guess = input_guess[index_guess];
        bytes_guess[index_guess] = value_guess;
        if (value_guess == 0) {
            return 1;
        }
        ++index_guess;
    } while (index_guess < 64);
    bytes_guess[63] = 0;
    return 0;
}

// 1 when the bytes at +0x19B and +0x17D are both set (two spell-record flags), else 0.
// FUNCTION: TITANIUM 0x0040D89F
int CharacterMagicSystem_guess::IsReady_guess() {
    int result_guess = 0;
    if (field19B_guess != 0 && field17D_guess != 0) {
        result_guess = 1;
    }
    return result_guess;
}

// Value `index_guess` of the 10000-entry table at +0x9C64; out of range gives the default at +0x138A8.
// FUNCTION: TITANIUM 0x0040D8B3
unsigned int CharacterMagicSystem_guess::GetValue_guess(int index_guess) {
    if (index_guess < 0 || index_guess >= 10000) {
        return field138A8_guess;
    }
    return values9C64_guess[index_guess];
}

// The byte at +0x1044 of the character's actor info; 0 without a spawn or actor info.
// FUNCTION: TITANIUM 0x0040D8E0
char CharacterMagicSystem_guess::GetStateFlag_guess() {
    MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
    char result_guess = 0;
    if (stateValue_guess != 0 && stateValue_guess->pActorInfo_01a8_guess != 0) {
        result_guess = stateValue_guess->pActorInfo_01a8_guess->field1044_guess;
    }
    return result_guess;
}

// Sets the byte at +0x1044 of the character's actor info, when there is one.
// FUNCTION: TITANIUM 0x0040D8FA
void CharacterMagicSystem_guess::SetFlag_guess(char value_guess) {
    MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
    if (stateValue_guess != 0 && stateValue_guess->pActorInfo_01a8_guess != 0) {
        stateValue_guess->pActorInfo_01a8_guess->field1044_guess = value_guess;
    }
}

// The spawn whose id the character's spawn reports (0x0047BFBC), looked up by id (0x00401B28); 0 when
// there is none.
// FUNCTION: TITANIUM 0x0040D918
unsigned int CharacterMagicSystem_guess::GetTransformed_guess() {
    if (pSpawn_0008_guess != 0) {
        unsigned int value_guess = pSpawn_0008_guess->Query_guess();
        if (value_guess > 0) {
            return Transform_guess(value_guess);
        }
    }
    return 0;
}

// Buff slot count: 60 for NPCs (type 1), 38 for players (type 0), 25 for anything else or no spawn.
// FUNCTION: TITANIUM 0x0040D933
char __fastcall GetMaxBuffs_guess(CharacterMagicSystem_guess* system_guess) {
    if (system_guess == 0) {
        return 0x19;
    } else {
        MagicStateA_guess* stateValue_guess = system_guess->pSpawn_0008_guess;
        if (stateValue_guess == 0) {
            return 0x19;
        } else {
            unsigned char value_guess = stateValue_guess->type_0244_guess;
            if (value_guess == 1) {
                return value_guess + 0x3b;
            }
            char result_guess = value_guess != 0;
            result_guess = result_guess - 1;
            result_guess &= 0x0d;
            result_guess += 0x19;
            return result_guess;
        }
    }
}

// True for a fixed list of 26 spell ids that ProcessAffects_guess treats specially (probably no fade
// message).
// FUNCTION: TITANIUM 0x0040D95A
int __cdecl MagicIdAllowed_guess(int value_guess) {
    if (value_guess == 0x158 || value_guess == 0x163 ||
        value_guess == 0x1c4 || value_guess == 0x1c5 ||
        value_guess == 0xf2 || value_guess == 0x200 ||
        value_guess == 0x27c || value_guess == 0x653 ||
        value_guess == 0xd48 || value_guess == 0xced ||
        value_guess == 0x65f || value_guess == 0x786 ||
        value_guess == 0x792 || value_guess == 0x6e7 ||
        value_guess == 0x2e2 || value_guess == 0x6d7 ||
        value_guess == 0xe1e || value_guess == 0x1340 ||
        value_guess == 0x1341 || value_guess == 0x1342 ||
        value_guess == 0x1819 || value_guess == 0x1536 ||
        value_guess == 0x1a08 || value_guess == 0x1a09 ||
        value_guess == 0x1a4c || value_guess == 0x1a4d) {
        return 1;
    }
    return 0;
}

// True for spell ids whose casting requirements are always met (CastingRequirementsMet_guess passes them).
// FUNCTION: TITANIUM 0x0040DA3B
int __cdecl MagicValueAllowed_guess(int value_guess) {
    if (value_guess <= 0xaa6) {
        if (value_guess >= 0xaa0) {
            return 1;
        }
        if (value_guess <= 0x5bf) {
            if (value_guess == 0x5bf) {
                return 1;
            }
            if (value_guess >= 0x57) {
                if (value_guess <= 0x58) {
                    return 1;
                }
                if (value_guess == 0x1dc) {
                    return 1;
                }
                if (value_guess > 0x334) {
                    if (value_guess <= 0x337) {
                        return 1;
                    }
                    if (value_guess > 0x5b8 && value_guess <= 0x5bb) {
                        return 1;
                    }
                }
            }
        } else {
            if (value_guess >= 0x7ad) {
                if (value_guess <= 0x7ae) {
                    return 1;
                }
                if (value_guess > 0xa95) {
                    if (value_guess <= 0xa97) {
                        return 1;
                    }
                    if (value_guess > 0xa9c && value_guess <= 0xa9e) {
                        return 1;
                    }
                }
            }
        }
    } else {
        switch (value_guess) {
        case 0xb12:
        case 0xb13:
        case 0xaa9:
        case 0xad6:
        case 0xae0:
        case 0xb3c:
        case 0xb49:
        case 0xb4b:
            return 1;
        }
    }
    if (((value_guess < 0x728) || (0x75b < value_guess)) &&
        ((value_guess < 0x2f8) || (0x300 < value_guess))) {
        return 0;
    }
    return 1;
}

// 1 for a Bard song: the class argument is 8 (Bard), the spell's byte +0x1C4 is zero and its Bard level
// (0x0044E755) is 1-254, 255 meaning the class cannot use it. 0x0040EA07 skips its stacking checks for
// such songs.
// FUNCTION: TITANIUM 0x0040DB0B
int __stdcall IsBardSong_guess(MagicPredicateObject_guess* object_guess, int type_guess) {
    if (object_guess != 0 && type_guess == 8 && object_guess->field1C4_guess == 0) {
        unsigned char result_guess = object_guess->Check_guess(8);
        if (result_guess > 0 && object_guess->Check_guess(8) < 0xff) {
            return 1;
        }
    }
    return 0;
}

// Always allows (returns 1); a cast check in the character tick calls it with the gem slot and spell.
// FUNCTION: TITANIUM 0x0040DB49
char CharacterMagicSystem_guess::ReturnTrue_guess(int first_guess, int second_guess, int third_guess, int fourth_guess) {
    return 1;
}

// Buff slot count minus 13 (`first_guess`) or minus 1 (`second_guess`) for a player; 0 otherwise.
// FUNCTION: TITANIUM 0x0040DB4E
int CharacterMagicSystem_guess::GetStateAdjustment_guess(char first_guess, char second_guess) {
    MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
    if (stateValue_guess != 0 && stateValue_guess->type_0244_guess == 0) {
        if (first_guess != 0) {
            return (unsigned char)GetMaxBuffs_guess(this) - 0xd;
        }
        if (second_guess != 0) {
            return (unsigned char)GetMaxBuffs_guess(this) - 1;
        }
    }
    return 0;
}

// Plays sound 0x73 on the player (both arguments unused).
// FUNCTION: TITANIUM 0x0040DB88
void CharacterMagicSystem_guess::CheckState_guess(int first_guess, int second_guess) {
    MagicStateA_guess* currentState_guess = pSpawn_0008_guess;
    if (currentState_guess != 0) {
        currentState_guess->Notify_guess(0x73);
    }
}

// Re-sends levitate state 2 to our spawn and to the spawn linked at its ActorInfo +0x15C, if any.
// FUNCTION: TITANIUM 0x0040DB99
void CharacterMagicSystem_guess::Refresh_guess() {
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
        pSpawn_0008_guess->SetLevitate_guess(2);
        if (pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
            pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->SetLevitate_guess(2);
        }
    }
}

#define pTarget_guess EQ_GLOBAL(EQPlayer*, 0x00905D04)
#define pSpawnList_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float y1_guess, float x1_guess, float y2_guess, float x2_guess);

inline float HeadingToPoint_guess(MagicPoint_guess from_guess, MagicPoint_guess to_guess) {
    return get_bearing_guess(from_guess.y_guess, from_guess.x_guess, to_guess.y_guess, to_guess.x_guess);
}

// Locate-corpse effect: with a target, finds a corpse (spawn type 2 or 3) whose name starts with the
// target's name; without one, the closest spawn (FindClosest_guess(0, -1, -1, -1, -1)). Targets what it
// found, turns the player (and the +0x15C actor link) toward it and prints 1563 "You sense a corpse in this
// direction."; 12446 (target) or 12447 (none) when nothing is found.
// FUNCTION: TITANIUM 0x0040DBCF
void CharacterMagicSystem_guess::eqspa_locate_corpse_guess() {
    EQPlayer* found_guess;
    if (pTarget_guess != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x309d, 0), 0x108, 1);
        for (found_guess = pSpawnList_guess; found_guess != 0; found_guess = found_guess->pNext) {
            if (found_guess->Type == 2 || found_guess->Type == 3) {
                char* name_guess = pTarget_guess->Name;
                if (_strnicmp(name_guess, found_guess->Name, strlen(name_guess)) == 0) {
                    pTarget_guess = found_guess;
                    break;
                }
            }
        }
    } else {
        found_guess = FindClosest_guess(0, -1, -1, -1, -1);
    }
    if (found_guess != 0) {
        pTarget_guess = found_guess;
        MagicPoint_guess to_guess;
        to_guess.x_guess = found_guess->X;
        to_guess.y_guess = found_guess->Y;
        MagicPoint_guess from_guess;
        from_guess.x_guess = pSpawn_0008_guess->position_guess.x_guess;
        from_guess.y_guess = pSpawn_0008_guess->position_guess.y_guess;
        pSpawn_0008_guess->heading_guess = get_bearing_guess(from_guess.y_guess, from_guess.x_guess,
                                                     to_guess.y_guess, to_guess.x_guess);
        MagicStateB_guess* actor_guess = pSpawn_0008_guess->pActorInfo_01a8_guess;
        if (actor_guess != 0 && actor_guess->field15C_guess != 0) {
            pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->heading_guess = pSpawn_0008_guess->heading_guess;
        }
        pEverQuest->dsp_chat(pStringTable->getString(0x61b, 0), 0x108, 1);
    } else if (pTarget_guess != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x309e, 0), 0x121, 1);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x309f, 0), 0x121, 1);
    }
}

// True when `pos_guess` lies in a hard-coded box for the current zone (zones 224, 110, 92...), probably the
// areas where certain spells are blocked.
// FUNCTION: TITANIUM 0x0040DD2E
// @early-stop: budget, structural ndiff=178
int CharacterMagicSystem_guess::IsInRestrictedArea_guess(Position_guess* pos_guess) {
    if (pos_guess != 0) {
    int result_guess = 0;
    int zone_guess = GetTable_guess()->field100_guess;
    if (zone_guess == 0xe0) {
        result_guess = pos_guess->x_guess >= 1230.0f && pos_guess->x_guess <= 1740.0f &&
                       pos_guess->y_guess >= -450.0f && pos_guess->y_guess <= 230.0f &&
                       pos_guess->z_guess >= -10.0f && pos_guess->z_guess <= 66.0f;
    } else if (zone_guess == 0x6e) {
        result_guess = pos_guess->x_guess > 5270.0f && pos_guess->x_guess < 5365.0f &&
                       pos_guess->y_guess < 510.0f && pos_guess->y_guess > 325.0f;
    } else if (zone_guess == 0x5c) {
        result_guess = pos_guess->x_guess > -2250.0f && pos_guess->x_guess < -2100.0f &&
                       pos_guess->y_guess < 1560.0f && pos_guess->y_guess > 1180.0f;
    } else if (zone_guess == 0x4e) {
        result_guess = pos_guess->x_guess > -2250.0f && pos_guess->x_guess < -1200.0f &&
                       pos_guess->y_guess < 275.0f && pos_guess->y_guess > -550.0f;
    } else if (zone_guess == 0xd) {
        result_guess = pos_guess->x_guess > -720.0f && pos_guess->x_guess < -550.0f &&
                       pos_guess->y_guess < -73.0f && pos_guess->y_guess > -260.0f;
    } else if (zone_guess == 0x54) {
        result_guess = 1;
    } else if (zone_guess != 0x5d) {
        if (zone_guess == 0x72) {
            result_guess = (pos_guess->x_guess >= -320.0f && pos_guess->x_guess <= 535.0f &&
                            pos_guess->y_guess >= -930.0f && pos_guess->y_guess <= -200.0f &&
                            pos_guess->z_guess >= -10.0f && pos_guess->z_guess <= 60.0f) ||
                           (pos_guess->x_guess >= 535.0f && pos_guess->x_guess <= 1000.0f &&
                            pos_guess->y_guess >= -800.0f && pos_guess->y_guess <= -200.0f &&
                            pos_guess->z_guess >= -10.0f && pos_guess->z_guess <= 120.0f);
        } else if (zone_guess == 0x71) {
            result_guess = (pos_guess->x_guess >= -176.0f && pos_guess->x_guess <= 17.0f &&
                            pos_guess->y_guess >= -657.0f && pos_guess->y_guess <= -603.0f) ||
                           (pos_guess->x_guess >= -287.0f && pos_guess->x_guess <= -102.0f &&
                            pos_guess->y_guess >= 3139.0f && pos_guess->y_guess <= 3196.0f);
        } else if (zone_guess == 0x16) {
            result_guess = pos_guess->x_guess >= -1610.0f && pos_guess->x_guess <= -1310.0f &&
                           pos_guess->y_guess >= -300.0f && pos_guess->y_guess <= -100.0f;
        } else if (zone_guess == 0x22) {
            result_guess = pos_guess->x_guess >= 2650.0f && pos_guess->x_guess <= 2850.0f &&
                           pos_guess->y_guess >= 790.0f && pos_guess->y_guess <= 990.0f;
        } else if (zone_guess == 0x44) {
            result_guess = pos_guess->x_guess >= -1220.0f && pos_guess->x_guess <= -1020.0f &&
                           pos_guess->y_guess >= -2625.0f && pos_guess->y_guess <= -2425.0f;
        } else if (zone_guess == 0x1e) {
            result_guess = pos_guess->x_guess >= 1675.0f && pos_guess->x_guess <= 1875.0f &&
                           pos_guess->y_guess >= -5140.0f && pos_guess->y_guess <= -4940.0f;
        } else if (zone_guess == 0x23) {
            result_guess = pos_guess->x_guess >= -1520.0f && pos_guess->x_guess <= -1320.0f &&
                           pos_guess->y_guess >= 900.0f && pos_guess->y_guess <= 1100.0f;
        }
    } else {
        result_guess = pos_guess->x_guess > 2344.0f && pos_guess->x_guess < 3538.0f &&
                       pos_guess->y_guess < 3852.0f && pos_guess->y_guess > 2011.0f;
    }
    return result_guess;
    }
    return 0;
}

// Sets current mana (profile +0x11A8).
// FUNCTION: TITANIUM 0x0040E293
void CharacterMagicSystem_guess::SetField11A8_guess(int value_guess) {
    list_guess.GetCharInfo2()->mana_11a8_guess = value_guess;
}

// Adds `value` to current mana (profile +0x11A8), with no clamping.
// FUNCTION: TITANIUM 0x0040E2A8
void CharacterMagicSystem_guess::AddField11A8_guess(int value_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    result_guess->mana_11a8_guess = result_guess->mana_11a8_guess + value_guess;
}

// Adds `value` to current endurance (profile +0x11AC), with no clamping; ability costs pass a negative
// amount.
// FUNCTION: TITANIUM 0x0040E2BD
void CharacterMagicSystem_guess::AddField11AC_guess(int value_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    result_guess->field11AC_guess = result_guess->field11AC_guess + value_guess;
}

// Long buff record `index_guess` (0-24); int 3 when out of range.
// FUNCTION: TITANIUM 0x0040E670
// @early-stop: budget, diff ndiff=2
MagicRecord20_guess* MagicRecordTable_guess::GetRecordA_guess(unsigned int index_guess) {
    if (index_guess >= 25) {
        __debugbreak();
    }
    return &recordsA_guess[index_guess];
}

// Short buff record `index_guess` (0-34); int 3 when out of range.
// FUNCTION: TITANIUM 0x0040E687
// @early-stop: budget, diff ndiff=2
MagicRecord20_guess* MagicRecordTable_guess::GetRecordB_guess(unsigned int index_guess) {
    if (index_guess >= 35) {
        __debugbreak();
    }
    return &recordsB_guess[index_guess];
}

// Cast-time reduction for `spell_guess`, by level, not AAs: a Ranger, Shadow Knight, Paladin or Beastlord
// above level 50 casting a detrimental spell (+0x17D 0) of 3000 ms or more loses 3% per level over 50 (at
// most 15 levels). Returns the new time minus the old (0 or negative).
// FUNCTION: TITANIUM 0x0040E2D2
int CharacterMagicSystem_guess::GetAACastingTimeModifier(MagicSpell_guess* spell_guess) {
    if (pSpawn_0008_guess == 0) {
        return 0;
    }
    if (pSpawn_0008_guess->pActorInfo_01a8_guess == 0) {
        return 0;
    }
    if (spell_guess == 0) {
        return 0;
    }
    unsigned int cost_guess = spell_guess->field14;
    if (ResolveResult_guess()->level_11a4_guess > 0x32 &&
        (ResolveResult_guess()->class_119c_guess == Class_Ranger ||
         ResolveResult_guess()->class_119c_guess == Class_ShadowKnight ||
         ResolveResult_guess()->class_119c_guess == Class_Paladin ||
         ResolveResult_guess()->class_119c_guess == Class_Beastlord) &&
        cost_guess >= 3000 &&
        spell_guess->field17d == 0) {
        float level_guess = (float)(ResolveResult_guess()->level_11a4_guess - 0x32);
        if (level_guess > 15.0f) {
            level_guess = 15.0f;
        }
        float factor_guess = (100.0f - level_guess * 3.0f) * 0.01f;
        cost_guess = (unsigned int)(factor_guess * cost_guess);
    }
    return cost_guess - spell_guess->field14;
}

// Level limit on a buff from player `other_guess` landing on us (judged by our master's level when we are
// a pet); returns 1 when it is blocked. Only spell levels 1-70 (for the caster's class) count: blocked when
// the spell level is over 50 and our level is below half of it + 15, when 0x00900478 is 4 or 6 and our
// level is also more than 20 under it, or when it is over 65 and our level is below 61. 0 for self, GM or
// NPC casters and spells failing the +0x180/+0x17D/+0x20 tests; the name reads backwards.
// FUNCTION: TITANIUM 0x0040E40B
char CharacterMagicSystem_guess::IsBuffLevelBlocked_guess(MagicPredicateObject_guess* target_guess,
                                                 CharacterMagicSystem_guess* other_guess) {
    unsigned int base_guess = ResolveResult_guess()->level_11a4_guess;
    unsigned int level_guess;
    if (target_guess == 0 || other_guess == 0 || pSpawn_0008_guess == 0) {
        return 0;
    }
    MagicStateA_guess* otherState_guess = other_guess->pSpawn_0008_guess;
    if (otherState_guess == 0 || otherState_guess->gm_0256_guess != 0 ||
        otherState_guess->type_0244_guess != 0) {
        return 0;
    }
    if (target_guess->field180_guess == 6 || target_guess->field17D_guess != 1 ||
        target_guess->field20_guess == 0) {
        return 0;
    }
    if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) <= 0) {
        return 0;
    }
    if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) > 0x46) {
        return 0;
    }
    if (pSpawn_0008_guess == other_guess->pSpawn_0008_guess) {
        return 0;
    }
    if (pSpawn_0008_guess->type_0244_guess == 1 && pSpawn_0008_guess->masterId_025c_guess != 0) {
        MagicStateA_guess* found_guess =
            (MagicStateA_guess*)Transform_guess(pSpawn_0008_guess->masterId_025c_guess);
        if (found_guess != 0 && found_guess->type_0244_guess == 0) {
            level_guess = found_guess->level_024c_guess;
        } else {
            level_guess = base_guess;
        }
    } else {
        level_guess = base_guess;
    }
    unsigned char limit_guess =
        target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess);
    if ((int)level_guess < (int)((limit_guess >> 1) + 0xf)) {
        if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) > 0x32) {
            if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) <
                0xff) {
                return 1;
            }
        }
        int cap_guess = target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) <
                                0x46
                            ? target_guess->Check_guess(
                                  other_guess->ResolveResult_guess()->class_119c_guess)
                            : 0x46;
        int capLimit_guess = cap_guess - 0x14;
        if ((g_modeCode_guess == 4 || g_modeCode_guess == 6) &&
            (int)level_guess < capLimit_guess &&
            pSpawn_0008_guess != other_guess->pSpawn_0008_guess) {
            return 1;
        }
    }
    if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) > 0x41) {
        if (target_guess->Check_guess(other_guess->ResolveResult_guess()->class_119c_guess) < 0xff &&
            (int)level_guess < 0x3d) {
            return 1;
        }
    }
    return 0;
}

// Records the caster's spawn id for buff slot `index` (profile +0x550, 60 slots; larger traps).
// FUNCTION: TITANIUM 0x0040E69E
void MagicResult_guess::SetBuffCasterId_guess(unsigned int index_guess, unsigned int value_guess) {
    if (index_guess >= 60) {
        __debugbreak();
    }
    values550_guess[index_guess] = value_guess;
}

// Sets innate ability `index` (profile +0x1100, 25 entries, 0xFF none; larger traps).
// FUNCTION: TITANIUM 0x0040E6B6
void MagicResult_guess::Set1100_guess(unsigned int index_guess, unsigned int value_guess) {
    if (index_guess >= 25) {
        __debugbreak();
    }
    values1100_guess[index_guess] = value_guess;
}

// Caster's spawn id recorded for buff slot `index` (profile +0x550); the buff stacking checks compare
// it with the new caster.
// FUNCTION: TITANIUM 0x0040E6CE
unsigned int CharacterMagicSystem_guess::GetBuffCasterId_guess(unsigned int index_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    unsigned int* values_guess = result_guess->values550_guess;
    if (index_guess >= 60) {
        __debugbreak();
    }
    return values_guess[index_guess];
}

// Records the caster's spawn id for buff slot `first` (0x0040E69E).
// FUNCTION: TITANIUM 0x0040E6EB
void CharacterMagicSystem_guess::SetBuffCasterId_guess(int first_guess, int second_guess) {
    list_guess.GetCharInfo2()->SetBuffCasterId_guess(first_guess, second_guess);
}

// Spell id memorized in gem `index` (profile +0xF30, 16 gems, -1 empty; larger traps).
// FUNCTION: TITANIUM 0x0040E705
unsigned int CharacterMagicSystem_guess::GetMemorizedSpell_guess(unsigned int index_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    unsigned int* values_guess = result_guess->values_guess;
    if (index_guess >= 16) {
        __debugbreak();
    }
    return values_guess[index_guess];
}

// Skill value `index` (profile +0xF70, 100 skills; larger traps); the skills window reads it.
// FUNCTION: TITANIUM 0x0040E722
unsigned int CharacterMagicSystem_guess::GetSkill_guess(unsigned int index_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    unsigned int* values_guess = result_guess->valuesF70_guess;
    if (index_guess >= 100) {
        __debugbreak();
    }
    return values_guess[index_guess];
}

// Innate ability `index` (profile +0x1100, 25 entries, 0xFF none; larger traps).
// FUNCTION: TITANIUM 0x0040E73F
unsigned int CharacterMagicSystem_guess::Read1100_guess(unsigned int index_guess) {
    MagicResult_guess* result_guess = list_guess.GetCharInfo2();
    unsigned int* values_guess = result_guess->values1100_guess;
    if (index_guess >= 25) {
        __debugbreak();
    }
    return values_guess[index_guess];
}

// Sets innate ability `first` (0x0040E6B6); the profile load fills all 25 with it.
// FUNCTION: TITANIUM 0x0040E75C
void CharacterMagicSystem_guess::Write1100_guess(int first_guess, int second_guess) {
    list_guess.GetCharInfo2()->Set1100_guess(first_guess, second_guess);
}

// True when +0x20 is set, +0x17D and +0x192 are clear, and one of the spell's 12 effect types (+0x120) is
// 0 (hit points). The buff stacking check calls it once per spell.
// FUNCTION: TITANIUM 0x0040E776
// @early-stop: budget, structural ndiff=18
char MagicCheck_guess::Check_guess() {
    if (field192 == 0 && field17d == 0 && field20 != 0) {
        int index = 0;
        do {
            if ((unsigned)index >= 12) {
                __debugbreak();
            } else if (values_120[index] == 0) {
                return 1;
            }
            ++index;
        } while (index < 12);
    }
    return 0;
}

// Highest rank of AA `value_guess` among the 26 AA entries the character owns.
// FUNCTION: TITANIUM 0x0040E818
int CharacterMagicSystem_guess::GetBestRank_guess(int value_guess) {
    MagicEntry_guess* entries_guess[26];
    int result_guess = 0;
    for (int index_guess = 0; index_guess < 0x15; ++index_guess) {
        entries_guess[index_guess] = GetTable_guess()->GetFirst_guess(index_guess);
    }
    for (int index_guess = 0; index_guess < 5; ++index_guess) {
        entries_guess[index_guess + 0x15] = GetTable_guess()->GetSecond_guess(index_guess);
    }
    for (int index_guess = 0; index_guess < 0x1a; ++index_guess) {
        MagicEntry_guess* entry_guess = entries_guess[index_guess];
        if (entry_guess != 0) {
            if (entry_guess->GetItemClass_guess() == 0) {
                int rank_guess = entry_guess->GetRank_guess(value_guess, 1);
                if (rank_guess > result_guess) {
                    result_guess = rank_guess;
                }
            }
        }
    }
    return result_guess;
}

// True when buff slot `index_guess` holds a valid, known spell.
// FUNCTION: TITANIUM 0x0040E893
char CharacterMagicSystem_guess::IsEntryUsable_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < (int)(unsigned char)GetMaxBuffs_guess(this)) {
        if (GetBuff_guess(index_guess)->active_guess != 0 &&
            IsValidSpellIndex_guess(GetBuff_guess(index_guess)->id_guess) != 0 &&
            g_magicLookup_guess->GetSpell_guess(GetBuff_guess(index_guess)->id_guess) != 0) {
            return 1;
        }
    }
    return 0;
}

struct MagicQuery_guess {
    char padTo30_guess[0x30];
    char values30_guess[0x30];
    char padTo120_guess[0xc0];
    char values120_guess[0x30];
};

// True when effect slot `index_guess` (0-11) holds a real effect: not 254 (empty) and not a zero-base
// effect 10 (CHA, used as a placeholder).
// FUNCTION: TITANIUM 0x0040E8F0
// @early-stop: budget, diff ndiff=8
int __cdecl CheckMagic_guess(MagicQuery_guess* object_guess, unsigned int index_guess) {
    unsigned int offset_guess = index_guess * 4;
    if (index_guess >= 12) {
        __debugbreak();
    }
    if (*(int*)&object_guess->values120_guess[offset_guess] == 0xfe) {
        return 0;
    }
    if (index_guess >= 12) {
        __debugbreak();
    }
    if (*(int*)&object_guess->values120_guess[offset_guess] == 10) {
        if (index_guess >= 12) {
            __debugbreak();
        }
        if (*(int*)&object_guess->values30_guess[offset_guess] == 0) {
            return 0;
        }
    }
    return 1;
}

// First active buff whose spell has effect `value_guess`; its slot goes to `index_guess`.
// FUNCTION: TITANIUM 0x0040E934
// @early-stop: budget, structural ndiff=14
MagicEntryProbe_guess* CharacterMagicSystem_guess::FindBuffWithEffect_guess(
    int value_guess, int* index_guess) {
    if (index_guess != 0) {
        *index_guess = -1;
    }
    int entryIndex_guess = 0;
    if ((unsigned char)GetMaxBuffs_guess(this) > 0) {
        do {
            MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
            if (entry_guess->active_guess != 0) {
                MagicCheck_guess* data_guess = g_magicLookup_guess->GetSpell_guess(
                    entry_guess->id_guess);
                if (data_guess != 0) {
                    for (int valueIndex_guess = 0, byteOffset_guess = 0;
                         byteOffset_guess < 0x30;
                         ++valueIndex_guess, byteOffset_guess += 4) {
                        if ((unsigned int)byteOffset_guess >= 0x30) {
                            __debugbreak();
                        } else if (data_guess->values_120[valueIndex_guess] == 0xfe) {
                            break;
                        }
                        if ((unsigned int)byteOffset_guess >= 0x30) {
                            __debugbreak();
                        } else if (data_guess->values_120[valueIndex_guess] == value_guess) {
                            if (index_guess != 0) {
                                *index_guess = entryIndex_guess;
                            }
                            return entry_guess;
                        }
                    }
                }
            }
            ++entryIndex_guess;
        } while (entryIndex_guess < (unsigned char)GetMaxBuffs_guess(this));
    }
    return 0;
}

// Level/value of the active buff with spell id `value_guess`, or 0.
// FUNCTION: TITANIUM 0x0040E9C7
char CharacterMagicSystem_guess::GetBuffLevelBySpell_guess(int value_guess) {
    int entryIndex_guess = 0;
    if ((unsigned char)GetMaxBuffs_guess(this) > 0) {
        do {
            MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
            if (entry_guess->active_guess != 0 && entry_guess->id_guess == value_guess) {
                return entry_guess->casterLevel_0001_guess;
            }
            ++entryIndex_guess;
        } while (entryIndex_guess < (unsigned char)GetMaxBuffs_guess(this));
    }
    return 0;
}

// True when an existing buff's stacking rules block `spell_guess`; spell 2751 (0xABF) is also checked against
// itself.
// FUNCTION: TITANIUM 0x0040EA07
// @early-stop: budget, structural ndiff=154
char CharacterMagicSystem_guess::IsBlockedByStackingCommand_guess(MagicCheck_guess* spell_guess, char type_guess) {
    if (spell_guess != 0 && pSpawn_0008_guess != 0) {
        int predicate_guess = ::IsBardSong_guess((MagicPredicateObject_guess*)spell_guess,
                                                   (unsigned char)type_guess);
        if (predicate_guess == 0) {
            int entryIndex_guess = (unsigned char)type_guess & predicate_guess;
            if (GetMaxBuffs_guess(this) != 0) {
                do {
                    MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
                    int spellId_guess = entry_guess->id_guess;
                    MagicCheck_guess* data_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
                    if (data_guess != 0 &&
                        (spellId_guess != spell_guess->id_guess || spell_guess->id_guess == 0xabf)) {
                        for (int effect_guess = 0; effect_guess < 12; ++effect_guess) {
                            if ((unsigned int)effect_guess >= 12) {
                                __debugbreak();
                            }
                            if (data_guess->values_120[effect_guess] == 0xfe) {
                                break;
                            }
                            if (data_guess->values_120[effect_guess] == 0x94) {
                                int value_guess = data_guess->values30_guess[effect_guess];
                                int slot_guess = data_guess->valuesF0_guess[effect_guess];
                                if (slot_guess > 200) {
                                    slot_guess -= 0xc9;
                                }
                                int amount_guess = FUN_0060f81e_guess(data_guess->values90_guess[effect_guess]);
                                if ((unsigned int)slot_guess >= 12) {
                                    __debugbreak();
                                }
                                if (spell_guess->values_120[slot_guess] == value_guess) {
                                    int threshold_guess = spell_guess->values30_guess[slot_guess];
                                    if (spell_guess->values90_guess[slot_guess] != 0) {
                                        threshold_guess = spell_guess->values90_guess[slot_guess];
                                    }
                                    if (threshold_guess <= amount_guess) {
                                        for (int otherEffect_guess = 0; otherEffect_guess < 12;
                                             ++otherEffect_guess) {
                                            if ((unsigned int)otherEffect_guess >= 12) {
                                                __debugbreak();
                                            }
                                            if (spell_guess->values_120[otherEffect_guess] == 0x94 &&
                                                spell_guess->values30_guess[otherEffect_guess] == value_guess &&
                                                spell_guess->valuesF0_guess[otherEffect_guess] - 0xc9 ==
                                                    slot_guess) {
                                                threshold_guess =
                                                    spell_guess->values90_guess[otherEffect_guess];
                                            }
                                        }
                                        if (threshold_guess <= amount_guess) {
                                            return 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    ++entryIndex_guess;
                } while (entryIndex_guess < (int)(unsigned char)GetMaxBuffs_guess(this));
            }
        }
    }
    return 0;
}

// Duration in ticks from the spell's formula and caster level; 0xFFFFFFFF (formula 50) is permanent,
// 0xFFFFFFFE marks other special durations.
// FUNCTION: TITANIUM 0x0040EBC3
// @early-stop: budget, structural ndiff=192
unsigned int CharacterMagicSystem_guess::SpellDuration_guess(
    MagicSpell_guess* spell_guess, unsigned char level_guess, char flag_guess) {
    unsigned int result_guess = 0;
    unsigned int zero_guess = 0;
    if (spell_guess != 0) {
        unsigned int effectCount_guess = spell_guess->field20;
        unsigned int one_guess = 1;
        if (effectCount_guess != zero_guess) {
            result_guess = 0x32;
            if (effectCount_guess == 0x32) {
                return 0xffffffff;
            }
            if (effectCount_guess > 0x32) {
                if (flag_guess != 0) {
                    return 0xfffffffe;
                }
                result_guess = effectCount_guess;
                if (effectCount_guess < 200) {
                    return 0;
                }
            } else {
                switch (effectCount_guess) {
                case 1:
                    if ((level_guess & 0xfe) < 2) {
                        result_guess = one_guess;
                    } else {
                        result_guess = level_guess >> 1;
                    }
                    break;
                case 2: {
                    unsigned int half_guess = one_guess;
                    if ((level_guess & 0xfe) >= 2) {
                        half_guess = level_guess >> 1;
                    }
                    result_guess = half_guess + 5;
                    break;
                }
                case 3:
                    result_guess = (unsigned int)level_guess * 0x1e;
                    break;
                case 4:
                    break;
                case 5:
                    result_guess = 2;
                    break;
                case 6:
                    result_guess = (level_guess >> 1) + 2;
                    break;
                case 7:
                    result_guess = level_guess;
                    break;
                case 8:
                    result_guess = level_guess + 10;
                    break;
                case 9:
                    result_guess = (unsigned int)level_guess * 2 + 10;
                    break;
                case 10:
                    result_guess = (unsigned int)level_guess * 3 + 10;
                    break;
                case 11:
                    result_guess = ((unsigned int)level_guess + 3) * 0x1e;
                    break;
                case 12:
                    result_guess = level_guess >> 2;
                    if (result_guess < one_guess) {
                        result_guess = one_guess;
                    }
                    break;
                default:
                    if (flag_guess != 0) {
                        return 0xfffffffe;
                    }
                    result_guess = effectCount_guess;
                    if (effectCount_guess < 200) {
                        return 0;
                    }
                    break;
                }
            }
            if (spell_guess->field24 != 0 && spell_guess->field24 < result_guess) {
                result_guess = spell_guess->field24;
            }
        }
        for (int offset_guess = 0; offset_guess < 0x30; offset_guess += 4) {
            if ((unsigned int)offset_guess >= 0x30) {
                __debugbreak();
            } else if (spell_guess->valuesF0_guess[offset_guess / 4] == 0x6b) {
                return result_guess;
            }
            if ((unsigned int)offset_guess >= 0x30) {
                __debugbreak();
            } else if (spell_guess->valuesF0_guess[offset_guess / 4] == 0x6c) {
                return result_guess;
            }
            if ((unsigned int)offset_guess >= 0x30) {
                __debugbreak();
            } else if (spell_guess->valuesF0_guess[offset_guess / 4] == 0x78) {
                return result_guess;
            }
            if ((unsigned int)offset_guess >= 0x30) {
                __debugbreak();
            } else if (spell_guess->valuesF0_guess[offset_guess / 4] == 0x7a) {
                return result_guess;
            }
        }
        if (spell_guess->field17d != 0 && spell_guess->field20 != 0 && pSpawn_0008_guess != 0 &&
            pSpawn_0008_guess->pActorInfo_01a8_guess != 0 && spell_guess->FindAffectSlot_guess(0x3a) != 0 &&
            TotalSpellAffects_guess(0xee, one_guess, zero_guess, one_guess) != 0) {
            result_guess = 10000;
        }
    }
    return result_guess;
}

struct MagicCaster_guess {
    char padTo28_guess[0x28];
    unsigned int field28_guess;
    char padTo60_guess[0x60 - 0x2c];
    char slot60_guess[12][4];
    // EXTERNAL: TITANIUM 0x0044E77B MagicCaster_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int value_guess);
};

struct EffectRequest_guess {
    int field00_guess;
    char name04_guess[64];
    int field44_guess;
    unsigned char field48_guess;
    char field49_guess;
    unsigned char field4A_guess;
    char pad4B_guess;
    int field4C_guess;
    char field50_guess[4];
    float field54_guess;
    char padTo58_guess[0xa0 - 0x58];
    int fieldA0_guess;
    int fieldA4_guess;
};

// Starts the visual/model side of an effect (illusions, mounts with "_ACTORDEF" actors, eyes); skipped while
// zoning.
// FUNCTION: TITANIUM 0x0040ED8C
// @early-stop: budget, structural ndiff=47
int CharacterMagicSystem_guess::ActivateEffect_guess(MagicCaster_guess* caster_guess, int id_guess, int type_guess,
                                                    int unused_guess, int extra_guess) {
    int category_guess = 0;
    char buffer_guess[128];
    EffectRequest_guess req_guess;
    memset(&req_guess, 0, sizeof(req_guess));
    if (GetTable_guess()->flag10C_guess != 0) {
        return 0;
    }
    if (pSpawn_0008_guess == 0) {
        return 0;
    }
    int rate_guess = ResolveResult_guess()->gender_1194_guess;
    req_guess.field00_guess = pSpawn_0008_guess->spawnId_0258_guess;
    strcpy(req_guess.name04_guess, pSpawn_0008_guess->name120_guess);
    req_guess.fieldA4_guess = extra_guess;
    req_guess.fieldA0_guess = -1;
    req_guess.field50_guess[2] = -1;
    req_guess.field50_guess[3] = -1;
    req_guess.field50_guess[0] = -1;
    req_guess.field50_guess[1] = -1;
    req_guess.field54_guess = -1.0f;
    req_guess.field49_guess = 0;
    if (type_guess < 0xd || type_guess == 0x46 || type_guess == 0x80 || type_guess == 0x82 || type_guess == 0x14a) {
        req_guess.field48_guess = 0;
        if (caster_guess->field28_guess > 0) {
            if (caster_guess->field28_guess == 4) {
                if (rate_guess == 0) {
                    req_guess.field48_guess = 1;
                } else if (rate_guess == 1) {
                    req_guess.field48_guess = 0;
                }
            } else {
                req_guess.field48_guess = (char)caster_guess->field28_guess - 1;
            }
        } else {
            req_guess.field48_guess = rate_guess;
        }
    } else {
        req_guess.field48_guess = 2;
    }
    req_guess.field44_guess = type_guess;
    char slot_guess = caster_guess->FindAffectSlot_guess(0x3a);
    unsigned int index_guess = (int)slot_guess - 1;
    if ((int)index_guess >= 0) {
        if (index_guess >= 0xc) {
            __debugbreak();
        }
        req_guess.field49_guess = caster_guess->slot60_guess[index_guess][0];
    }
    if (id_guess == 0x597) {
        req_guess.field49_guess = 0;
        if (ResolveResult_guess()->race_1198_guess != 9 && ResolveResult_guess()->race_1198_guess != 0x80) {
            if (ResolveResult_guess()->race_1198_guess == 2) {
                req_guess.field49_guess = 2;
            }
        } else {
            req_guess.field49_guess = 1;
        }
    }
    if (id_guess == 0x11a9 || id_guess == 0x11aa || id_guess == 0x11ab) {
        int class_guess = ResolveResult_guess()->race_1198_guess;
        if (class_guess == 9) {
            req_guess.field44_guess = 0x5b;
        } else if (class_guess == 10) {
            req_guess.field44_guess = 0x2b;
        } else if (class_guess == 0x80) {
            req_guess.field44_guess = 0x164;
        } else if (class_guess == 0x82) {
            req_guess.field44_guess = 0x3f;
        }
    }
    req_guess.field4C_guess = -1;
    req_guess.field4A_guess = 0xff;
    if (req_guess.field44_guess == 0x8f) {
        category_guess = 8;
    } else if (req_guess.field44_guess == 0x8e) {
        category_guess = 7;
    }
    if (req_guess.field49_guess == 0 && pSpawn_0008_guess->LegalPlayerRace_guess(req_guess.field44_guess) != 0) {
        req_guess.field49_guess = -1;
    }
    int result_guess = 0;
    if (category_guess == 0 || pSpawn_0008_guess->GetModelAtSpawnSpot_guess(buffer_guess, category_guess) == 1) {
        if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0 && pSpawn_0008_guess->spawnId_0258_guess == 0) {
            pSpawn_0008_guess->gender_024e_guess = req_guess.field48_guess;
            pSpawn_0008_guess->SetRace_guess(req_guess.field44_guess);
            pSpawn_0008_guess->equipChest2_0254_guess = req_guess.field49_guess;
            pSpawn_0008_guess->GetActorTag_guess(
                pSpawn_0008_guess->pActorInfo_01a8_guess->name08_guess);
            strcat(pSpawn_0008_guess->pActorInfo_01a8_guess->name08_guess, "_ACTORDEF");
            pSpawn_0008_guess->avatarHeight_023c_guess = -1.0f;
            pSpawn_0008_guess->SetHeights_guess();
        }
        result_guess = 1;
    }
    return result_guess;
}

// Stops the current cast or song: sends OP_ManaChange (no payload) when needed and shows 12687 "Your song
// ends." or 12686 "Your song ends abruptly.".
// FUNCTION: TITANIUM 0x0040F06D
// @early-stop: budget, diff ndiff=9
void CharacterMagicSystem_guess::StopSpellCast_guess(char first_guess, int second_guess) {
    int reset_guess = 1;
    char buffer_guess[128];
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
        MagicCheck_guess* data_guess;
        if (IsValidSpellIndex_guess(second_guess) != 0) {
            data_guess = g_magicLookup_guess->GetSpell_guess(second_guess);
        } else {
            data_guess = 0;
        }
        int predicate_guess = IsBardSong_guess(
            (MagicPredicateObject_guess*)data_guess, ResolveResult_guess()->class_119c_guess);
        if (predicate_guess == 0) {
            reset_guess = 0;
            if (g_magicCountA_guess > 0) {
                --g_magicCountA_guess;
            } else {
                g_magicCountA_guess = 0;
            }
            if (g_magicCountB_guess > 0) {
                --g_magicCountB_guess;
            } else {
                g_magicCountB_guess = 0;
            }
            if (ResolveResult_guess()->class_119c_guess == Class_Bard) {
                if (pSpawn_0008_guess->pActorInfo_01a8_guess->field104C_guess == 0 && data_guess != 0 &&
                    data_guess->field14_guess <= 0x64) {
                    return;
                }
                if (pSpawn_0008_guess->pActorInfo_01a8_guess->field1048_guess != 0 ||
                    second_guess == pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess) {
                    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess = -1;
                    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF9C_guess = (char)0xff;
                }
                pSpawn_0008_guess->pActorInfo_01a8_guess->field104C_guess = 0;
                pSpawn_0008_guess->pActorInfo_01a8_guess->fieldD8_guess = 0;
                pSpawn_0008_guess->pActorInfo_01a8_guess->field1048_guess = 0;
                pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFA0_guess = 0;
                return;
            }
        }
        if (data_guess != 0) {
            if (first_guess == 0 && g_magicSendFlag_guess == 0 && g_magicSendCount_guess == 0) {
                EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_ManaChange, 0, 0, 1);
            }
            g_magicLastTarget_guess = -1;
            pSpawn_0008_guess->pActorInfo_01a8_guess->field104C_guess = 0;
            pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess = -1;
            pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF9C_guess = (char)0xff;
            pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFA0_guess = 0;
            pSpawn_0008_guess->pActorInfo_01a8_guess->fieldD8_guess = 0;
            if (reset_guess != 0) {
                for (second_guess = 0; second_guess < 9; ++second_guess) {
                    int usable_guess = 0;
                    if (IsValidSpellIndex_guess(
                            ((CharacterMagicSystem_guess*)GetTable_guess())->GetMemorizedSpell_guess(second_guess)) != 0) {
                        MagicCheck_guess* check_guess = g_magicLookup_guess->GetSpell_guess(
                            ((CharacterMagicSystem_guess*)GetTable_guess())->GetMemorizedSpell_guess(second_guess));
                        if (check_guess != 0 && check_guess->field1C_guess != 0) {
                            usable_guess = 1;
                        }
                    }
                    if (usable_guess == 0) {
                        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldE8_guess[second_guess] = 0;
                    }
                }
                pSpawn_0008_guess->pActorInfo_01a8_guess->field110_guess = 0;
                unsigned int id_guess = 0x318f;
                if (first_guess == 1) {
                    id_guess = 0x318e;
                }
                char* format_guess = pStringTable->getString(id_guess, 0);
                sprintf(buffer_guess, format_guess);
                if (g_magicTimer_guess.Check_guess(9) != 1) {
                    g_magicMessageRouter_guess->dsp_chat(buffer_guess, 0x108, 1);
                }
            }
        }
    }
}

// Effect amount for slot `slot_guess` at level `value_guess`, by the slot's formula (0x64, 0x65 = level / 2,
// ...).
// FUNCTION: TITANIUM 0x0040F339
// @early-stop: budget, structural ndiff=301
int CharacterMagicSystem_guess::CalcAffectChange_guess(
    MagicCheck_guess* spell_guess, unsigned char value_guess,
    int slot_guess, MagicEntryProbe_guess* entry_guess) {
    unsigned char index_guess = (unsigned char)slot_guess;
    int amount_guess = 0;

    // The result starts at the magnitude of the slot's base (+0x30); `slot_guess` holds it from here
    // on and the formula's growth (`amount_guess`) is added below.
    slot_guess = FUN_0060f81e_guess(spell_guess->Get30_guess(index_guess));

    switch (spell_guess->GetF0_guess(index_guess)) {
    // Formulas 100-105: no growth, level / 2, level, then 2, 3 and 4 times the level.
    case 0x64:
        amount_guess = 0;
        break;
    case 0x65:
        amount_guess = value_guess >> 1;
        break;
    case 0x66:
        amount_guess = value_guess;
        break;
    case 0x67:
        amount_guess = value_guess * 2;
        break;
    case 0x68:
        amount_guess = value_guess * 3;
        break;
    case 0x69:
        amount_guess = value_guess * 4;
        break;
    // 107 and 108 decay over the buff's life: 1 (2 for 108) per tick elapsed, i.e. the full duration
    // at this level minus the ticks left (+0x08). Only for a spell with a duration and a live buff
    // entry.
    case 0x6b:
    case 0x6c:
        if (spell_guess->field20 != 0 && entry_guess != 0) {
            amount_guess = (int)SpellDuration_guess((MagicSpell_guess*)spell_guess, value_guess, 0) -
                           entry_guess->unknown08_guess;
            if (spell_guess->GetF0_guess(index_guess) == 0x6c) {
                amount_guess *= 2;
            }
            if (slot_guess >= 0) {
                amount_guess = -amount_guess;
            }
        }
        break;
    case 0x6d:
        amount_guess = value_guess >> 2;
        break;
    case 0x6e:
        amount_guess = value_guess / 6;
        break;
    // 111-118 grow only above a level floor: 6, 8, 10, 15 per level over 16, 24, 34, 44 (111-114)
    // and 7, 10, 13, 20 per level over 15, 24, 34, 44 (115-118).
    case 0x6f: {
        int excess_guess = (int)value_guess - 0x10;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 6;
        }
        break;
    }
    case 0x70: {
        int excess_guess = (int)value_guess - 0x18;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 8;
        }
        break;
    }
    case 0x71: {
        int excess_guess = (int)value_guess - 0x22;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 10;
        }
        break;
    }
    case 0x72: {
        int excess_guess = (int)value_guess - 0x2c;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 15;
        }
        break;
    }
    case 0x73: {
        int excess_guess = (int)value_guess - 0x0f;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 7;
        }
        break;
    }
    case 0x74: {
        int excess_guess = (int)value_guess - 0x18;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 10;
        }
        break;
    }
    case 0x75: {
        int excess_guess = (int)value_guess - 0x22;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 13;
        }
        break;
    }
    case 0x76: {
        int excess_guess = (int)value_guess - 0x2c;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 20;
        }
        break;
    }
    case 0x77:
        amount_guess = value_guess >> 3;
        break;
    // 120 and 122 (below) decay like 107: 5 and 12 per tick elapsed.
    case 0x78:
        if (spell_guess->field20 != 0 && entry_guess != 0) {
            amount_guess = ((int)SpellDuration_guess((MagicSpell_guess*)spell_guess, value_guess, 0) -
                            entry_guess->unknown08_guess) * 5;
            if (slot_guess >= 0) {
                amount_guess = -amount_guess;
            }
        }
        break;
    case 0x79:
        amount_guess = value_guess / 3;
        break;
    case 0x7a:
        if (spell_guess->field20 != 0 && entry_guess != 0) {
            amount_guess = ((int)SpellDuration_guess((MagicSpell_guess*)spell_guess, value_guess, 0) -
                            entry_guess->unknown08_guess) * 12;
            if (slot_guess >= 0) {
                amount_guess = -amount_guess;
            }
        }
        break;
    // 123: a random growth of 1 .. max - |base|, so the result lands between the base and the max.
    case 0x7b:
        amount_guess = RandomRange_guess(
            1, spell_guess->Get90_guess(index_guess) -
                   FUN_0060f81e_guess(spell_guess->Get30_guess(index_guess)));
        break;
    // 124-132: 1, 2, 3, 4, 5, 10, 15, 20 and 25 per level above 50.
    case 0x7c: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess;
        }
        break;
    }
    case 0x7d: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 2;
        }
        break;
    }
    case 0x7e: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 3;
        }
        break;
    }
    case 0x7f: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 4;
        }
        break;
    }
    case 0x80: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 5;
        }
        break;
    }
    case 0x81: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 10;
        }
        break;
    }
    case 0x82: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 15;
        }
        break;
    }
    case 0x83: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 20;
        }
        break;
    }
    case 0x84: {
        int excess_guess = (int)value_guess - 0x32;
        if (excess_guess > 0) {
            amount_guess = excess_guess * 25;
        }
        break;
    }
    // 137: base * (1 - HP / max HP) of this spawn, so the result grows as it is hurt. 138 (next)
    // uses half the max HP at or below half health, and gives 2 * base above it.
    case 0x89:
        if (pSpawn_0008_guess != 0) {
            amount_guess = -(pSpawn_0008_guess->hpCurrent_0274_guess * slot_guess /
                             pSpawn_0008_guess->hpMax_0284_guess);
        }
        break;
    case 0x8a:
        if (pSpawn_0008_guess != 0) {
            int half_guess = pSpawn_0008_guess->hpMax_0284_guess / 2;
            amount_guess = slot_guess;
            if (half_guess >= pSpawn_0008_guess->hpCurrent_0274_guess) {
                amount_guess = -(pSpawn_0008_guess->hpCurrent_0274_guess * slot_guess / half_guess);
            }
        }
        break;
    default:
        // Formulas 1-99 (and any not listed): level times the formula number.
        amount_guess = value_guess * spell_guess->valuesF0_guess[index_guess];
        break;
    }

    // AttackSpeed (SPA 11) under 100 is a slow: growth lowers it, but not below the max (+0x90).
    // Everything else adds the growth, which the decay formulas make negative.
    if (spell_guess->GetType_guess(index_guess) == 0xb && slot_guess < 100) {
        slot_guess -= amount_guess;
        if (spell_guess->Get90_guess(index_guess) != 0) {
            int minimum_guess = spell_guess->Get90_guess(index_guess);
            if (slot_guess < minimum_guess) {
                slot_guess = minimum_guess;
            }
        }
    } else {
        slot_guess += amount_guess;
    }

    if (spell_guess->Get90_guess(index_guess) != 0) {
        // A non-zero max caps the magnitude.
        int maximum_guess = FUN_0060f81e_guess(spell_guess->Get90_guess(index_guess));
        if (slot_guess > maximum_guess) {
            slot_guess = maximum_guess;
        }
    }

    if (spell_guess->Get30_guess(index_guess) >= 0) {
        int effect_guess = spell_guess->GetF0_guess(index_guess);
        if (effect_guess >= 0) {
            return slot_guess;
        }
        if (effect_guess <= 0x84) {
            return slot_guess;
        }
    }
    // A negative base (damage, debuffs) gives a negative result.
    return -slot_guess;
}

#define g_magicScale_guess EQ_GLOBAL(float, 0x00640E38)
// CalcAffectChange_guess scaled by the buff's modifier (10 = 100%) and negated for buff type 4.
// FUNCTION: TITANIUM 0x0040F7FE
// @early-stop: budget, diff ndiff=22
int CharacterMagicSystem_guess::CalcScaledAffectChange_guess(
    unsigned int effect_guess, MagicEntryProbe_guess* entry_guess,
    int slot_guess, MagicCheck_guess* spell_guess) {
    CharacterMagicSystem_guess* system_guess = this;
    int amount_guess = CalcAffectChange_guess(
        spell_guess, entry_guess->casterLevel_0001_guess, slot_guess, entry_guess);
    if (entry_guess->scale_guess != 0x0a) {
        float scale_guess = (float)entry_guess->scale_guess * g_magicScale_guess;
        amount_guess = (int)(scale_guess * (float)amount_guess);
    }
    if (entry_guess->active_guess == 4) {
        amount_guess = -amount_guess;
    }
    MagicStateA_guess* found_guess = (MagicStateA_guess*)Transform_guess(effect_guess);
    if (found_guess != 0 && found_guess->pCharInfo_0218_guess != 0 &&
        found_guess->type_0244_guess == 0 && amount_guess < 0) {
        MagicStateA_guess* current_guess = system_guess->pSpawn_0008_guess;
        if (current_guess != 0 && current_guess->type_0244_guess == 0) {
            if (current_guess == found_guess) {
                amount_guess = amount_guess * 0x4b;
            } else {
                amount_guess = amount_guess * 0x46;
            }
            amount_guess = amount_guess / 100;
            if (amount_guess > -1) {
                amount_guess = -1;
            }
        }
    }
    return amount_guess;
}

// Stops the current cast or song (0x0040F06D) with `value` and the spell the actor is casting (+0xF98).
// FUNCTION: TITANIUM 0x0040F8A0
void CharacterMagicSystem_guess::RefreshFromState_guess(int value_guess) {
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
        StopSpellCast_guess(value_guess, pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess);
    }
}

// Adds the worn-effect spells of the 29 equipped items and their augments to the per-SPA totals (called at
// the end of InitializeSpellAffects_guess).
// FUNCTION: TITANIUM 0x0040F8C3
// @early-stop: budget, structural ndiff=390
void CharacterMagicSystem_guess::FinishSpellAffects_guess() {
    int count_guess = 0;
    int index_guess = 0;
    CharacterMagicSystem_guess* self_guess = this;
    // The 29 item slots whose worn effects count: 22 from GetFirst_guess (slots 0-21), 5 from GetSecond_guess
    // and 2 from Slot05_guess.
    MagicEntry_guess* entries_guess[29];
    do {
        entries_guess[count_guess] = self_guess->GetTable_guess()->GetFirst_guess(index_guess);
        ++count_guess;
        ++index_guess;
    // Not a "finish" in general: this adds the worn-effect spells of equipped items and their augments to the
    // totals InitializeSpellAffects built from the buffs.
    } while (index_guess < 0x16);
    index_guess = 0;
    do {
        entries_guess[count_guess] = self_guess->GetTable_guess()->GetSecond_guess(index_guess);
        ++count_guess;
        ++index_guess;
    } while (index_guess < 5);
    index_guess = 0;
    do {
        entries_guess[count_guess] = self_guess->Slot05_guess(index_guess);
        ++count_guess;
        ++index_guess;
    } while (index_guess < 2);
    // Only for players, and for NPCs that have an owner id (+0x25C). Containers and books (item class not 0)
    // are skipped.
    if (pSpawn_0008_guess != 0 && (pSpawn_0008_guess->type_0244_guess == 0 || pSpawn_0008_guess->masterId_025c_guess != 0)) {
        for (int entryIndex_guess = 0; entryIndex_guess < count_guess; ++entryIndex_guess) {
            MagicEntry_guess* top_guess = entries_guess[entryIndex_guess];
            if (top_guess == 0 || top_guess->GetItemClass_guess() != 0) {
                continue;
            }
            MagicEntry_guess* entry_guess = top_guess;
            int sub_guess = 0;
            do {
                if (entry_guess == 0 || entry_guess->GetItemClass_guess() != 0) {
                    if (sub_guess < 10) {
                        entry_guess = top_guess->GetChild_guess(sub_guess);
                    }
                } else if (entry_guess->GetField98_guess() >= 0) {
                    int firstCount_guess = entry_guess->GetCount_guess(2);
                    int secondCount_guess = entry_guess->GetCount_guess(2);
                    if (secondCount_guess >= 2) {
                        if (IsValidSpellIndex_guess(firstCount_guess) != 0) {
                            MagicCheck_guess* data_guess = g_magicLookup_guess->GetSpell_guess(firstCount_guess);
                            if (data_guess != 0 && data_guess->field20 != 0 &&
                                // Each item and its augments (children 0-9) with a worn effect whose spell
                                // has a duration; the ammo slot (21) only counts for InfraVision and
                                // UltraVision (SPA 65, 66).
                                !(entryIndex_guess == 0x15 &&
                                  !data_guess->FindAffectSlot_guess(0x42) &&
                                  !data_guess->FindAffectSlot_guess(0x41))) {
                                int level_guess = entry_guess->GetRaw_guess(2);
                                if (entry_guess->GetField240_guess() != 0) {
                                    int scale_guess = entry_guess->GetRaw_guess(2);
                                    level_guess = entry_guess->GetField98_guess() * scale_guess / 100;
                                }
                                for (unsigned int slot_guess = 0; slot_guess < 12; ++slot_guess) {
                                    int extra_guess = 0;
                                    int type_guess = data_guess->GetType_guess(slot_guess);
                                    // Key-valued SPAs (169, 183-186, 197, 216, 220, 224, 227, 247, 260, 262,
                                    // 264, 267, 268, 330) take the slot's +0x60 as their key.
                                    if (type_guess < 0xe4) {
                                        if (type_guess == 0xe3 || type_guess == 0xa9 ||
                                            (type_guess > 0xb6 && (type_guess < 0xbb || type_guess == 0xc5 ||
                                                                   type_guess == 0xd8 || type_guess == 0xdc ||
                                                                   type_guess == 0xe0))) {
                                            extra_guess = data_guess->Get60_guess(slot_guess);
                                        }
                                    } else if (type_guess == 0xf7 || type_guess == 0x104 || type_guess == 0x106 ||
                                               type_guess == 0x108 ||
                                               (type_guess > 0x10a && (type_guess < 0x10d || type_guess == 0x14a))) {
                                        extra_guess = data_guess->Get60_guess(slot_guess);
                                    }
                                    int amount_guess = CalcAffectChange_guess(
                                        data_guess, (unsigned char)level_guess, slot_guess, 0);
                                    int current_guess = service_C4_guess.GetPair_guess(
                                        data_guess->GetType_guess(slot_guess), extra_guess);
                                    // Merging into the buff totals: the same keep-one-value rules as
                                    // InitializeSpellAffects_guess; item haste (11) is capped at 110 below
                                    // level 26; DamageShield (59) adds but stops at -15; the rest add up.
                                    if (type_guess == 3 || (type_guess >= 0xa9 && type_guess <= 0xb4) ||
                                        type_guess == 0xb8 || type_guess == 0xb9 || type_guess == 0xba ||
                                        type_guess == 0xbc || type_guess == 0xc3 || type_guess == 0xc4 ||
                                        type_guess == 0xc8 || type_guess == 0x72) {
                                        if (current_guess < 0) {
                                            if (amount_guess < current_guess) {
                                                service_C4_guess.Add_guess(
                                                    amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                            }
                                        } else if (amount_guess < 0 || amount_guess > current_guess) {
                                            service_C4_guess.Add_guess(
                                                amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                        }
                                    } else if (type_guess == 0xa8 || type_guess == 0xb6 || type_guess == 0xc5) {
                                        if (current_guess > 0) {
                                            if (amount_guess > current_guess) {
                                                service_C4_guess.Add_guess(
                                                    amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                            }
                                        } else if (amount_guess > 0 || amount_guess < current_guess) {
                                            service_C4_guess.Add_guess(
                                                amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                        }
                                    } else if (type_guess == 0xb) {
                                        if (ResolveResult_guess()->level_11a4_guess < 0x1a && amount_guess > 0x6e) {
                                            amount_guess = 0x6e;
                                        }
                                        if (current_guess >= 100) {
                                            if (amount_guess < 100 || amount_guess > current_guess) {
                                                service_C4_guess.Add_guess(
                                                    amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                            }
                                        } else if (amount_guess < current_guess || current_guess == 0) {
                                            service_C4_guess.Add_guess(
                                                amount_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                        }
                                    } else if (type_guess == 0x3b) {
                                        int total_guess = current_guess + amount_guess;
                                        // Item damage shields (SPA 59) add up but stop at -15.
                                        if (total_guess < -0xf) {
                                            total_guess = -0xf;
                                        }
                                        service_C4_guess.Add_guess(
                                            total_guess, data_guess->GetType_guess(slot_guess), extra_guess);
                                    } else {
                                        service_C4_guess.Add_guess(
                                            current_guess + amount_guess,
                                            data_guess->GetType_guess(slot_guess), extra_guess);
                                    }
                                }
                            }
                        }
                    }
                    if (sub_guess < 10) {
                        entry_guess = top_guess->GetChild_guess(sub_guess);
                    }
                }
                ++sub_guess;
            } while (sub_guess <= 10);
        }
    }
}

// Collects the AA abilities the character's class can use at its level (240 AA slots).
// FUNCTION: TITANIUM 0x0040FEAA
void CharacterMagicSystem_guess::InitializeThree_guess() {
    service_C4_guess.Init_guess();
    MagicObject_guess* object_guess = GetTable_guess()->GetObject_guess();
    if (object_guess == 0) {
        flagD0_guess = 1;
    } else {
        for (int index_guess = 0; index_guess < 0xf0; ++index_guess) {
            int id_guess = object_guess->GetEntry_guess(index_guess);
            MagicEntry_guess* entry_guess = g_tableView_guess->GetAltAbility(id_guess);
            if (entry_guess != 0) {
                if (entry_guess->CanClassUse_guess(ResolveResult_guess()->class_119c_guess)) {
                    int level_guess = entry_guess->field18_guess;
                    if (level_guess <= ResolveResult_guess()->level_11a4_guess) {
                        MagicIterator_guess* iterator_guess = &entry_guess->iterator_guess;
                        iterator_guess->current_guess = iterator_guess->head_guess;
                        MagicEffect_guess* effect_guess;
                        while ((effect_guess = iterator_guess->Take_guess()) != 0) {
                            int type_guess = effect_guess->type_guess;
                            int value_guess = 0;
                            switch (type_guess) {
                            case 0xa9:
                            case 0xb7:
                            case 0xb8:
                            case 0xb9:
                            case 0xba:
                            case 0xc5:
                            case 0xd8:
                            case 0xdc:
                            case 0xe0:
                            case 0xe3:
                            case 0xf7:
                            case 0x104:
                            case 0x106:
                            case 0x108:
                            case 0x10b:
                            case 0x10c:
                            case 0x14a:
                                value_guess = effect_guess->value_guess;
                                break;
                            }
                            service_C4_guess.Set_guess(
                                service_C4_guess.GetThree_guess(type_guess, value_guess, type_guess,
                                                                value_guess) +
                                effect_guess->offset_guess);
                        }
                    }
                }
            }
        }
    }
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
        flagD0_guess = 1;
    }
}


// Rebuilds the cached effect totals from every active buff.
// FUNCTION: TITANIUM 0x0041002F
// @early-stop: budget, structural ndiff=412
void CharacterMagicSystem_guess::InitializeSpellAffects_guess() {
    // Rebuild the per-SPA totals from scratch; +0x9C sums +0x1C8 of the buffs FUN_00464e9c_guess rejects.
    service_C4_guess.Clear_guess();
    field9C_guess = 0;
    for (int entryIndex_guess = 0; entryIndex_guess < (unsigned char)GetMaxBuffs_guess(this);
         ++entryIndex_guess) {
        MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
        if (entry_guess->active_guess == 0 || IsValidSpellIndex_guess(entry_guess->id_guess) == 0) {
            continue;
        }
        MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(entry_guess->id_guess);
        if (spell_guess == 0) {
            continue;
        }
        int world_guess = 0;
        if (g_magicWorld_guess != 0) {
            world_guess = g_magicWorld_guess->field204_guess;
        }
        if (FUN_00464e9c_guess(world_guess, (int)this, spell_guess) == 0) {
            field9C_guess += spell_guess->field1C8_guess;
        }
        for (int slot_guess = 0; slot_guess < 12; ++slot_guess) {
            char flag_guess = 0;
            // Formulas 107, 108, 120, 122, 137 and 138 change over the buff's life; their totals are stored
            // flagged.
            if (spell_guess->GetF0_guess(slot_guess) == 0x6b ||
                spell_guess->GetF0_guess(slot_guess) == 0x6c ||
                spell_guess->GetF0_guess(slot_guess) == 0x78 ||
                spell_guess->GetF0_guess(slot_guess) == 0x7a ||
                spell_guess->GetF0_guess(slot_guess) == 0x89 ||
                spell_guess->GetF0_guess(slot_guess) == 0x8a) {
                flag_guess = 1;
            }
            int extra_guess = 0;
            // SPAs keyed by a second value (the slot's +0x60, e.g. a skill or spell limit) keep one total per
            // key.
            switch (spell_guess->GetType_guess(slot_guess)) {
            case 0xa9:
            case 0xb7:
            case 0xb8:
            case 0xb9:
            case 0xba:
            case 0xc5:
            case 0xd8:
            case 0xdc:
            case 0xe0:
            case 0xe3:
            case 0xf7:
            case 0x104:
            case 0x106:
            case 0x108:
            case 0x10b:
            case 0x10c:
            case 0x14a:
                extra_guess = spell_guess->Get60_guess(slot_guess);
                break;
            }
            int base_guess =
                service_C4_guess.GetValue_guess(spell_guess->GetType_guess(slot_guess), extra_guess);
            int amount_guess = CalcAffectChange_guess(spell_guess, entry_guess->casterLevel_0001_guess, slot_guess,
                                                  entry_guess);
            // How each SPA combines: attack speed (11) keeps one value around 100, a slow (under 100) beating
            // any haste; SPA 98 and 119 the highest; movement speed, 169-180, 184-186, 188, 195, 196, 200 and
            // ChangeAggro (114) keep one value, a negative beating any positive and otherwise the larger
            // magnitude; MeleeMitigation (168), HundredHands (182) and SkillDamageTaken (197) the same with a
            // positive beating any negative. Everything else adds up. A server scale other than 10 multiplies
            // first.
            if (spell_guess->GetType_guess(slot_guess) == 0xb) {
                if (base_guess < 100) {
                    if (amount_guess >= base_guess && base_guess != 0) {
                        continue;
                    }
                } else if (amount_guess >= 100 && amount_guess <= base_guess) {
                    continue;
                }
            } else if (spell_guess->GetType_guess(slot_guess) == 0x62 ||
                       spell_guess->GetType_guess(slot_guess) == 0x77) {
                if (base_guess >= amount_guess) {
                    continue;
                }
            } else {
                unsigned char scale_guess = entry_guess->scale_guess;
                if (scale_guess != 10 && scale_guess < 0x2e) {
                    amount_guess = (int)(scale_guess * g_magicScale_guess * amount_guess);
                }
                if (spell_guess->GetType_guess(slot_guess) == 3 ||
                    spell_guess->GetType_guess(slot_guess) == 0xa9 ||
                    spell_guess->GetType_guess(slot_guess) == 0xaa ||
                    spell_guess->GetType_guess(slot_guess) == 0xab ||
                    spell_guess->GetType_guess(slot_guess) == 0xac ||
                    spell_guess->GetType_guess(slot_guess) == 0xad ||
                    spell_guess->GetType_guess(slot_guess) == 0xae ||
                    spell_guess->GetType_guess(slot_guess) == 0xaf ||
                    spell_guess->GetType_guess(slot_guess) == 0xb0 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb1 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb2 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb3 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb4 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb8 ||
                    spell_guess->GetType_guess(slot_guess) == 0xb9 ||
                    spell_guess->GetType_guess(slot_guess) == 0xba ||
                    spell_guess->GetType_guess(slot_guess) == 0xbc ||
                    spell_guess->GetType_guess(slot_guess) == 0xc3 ||
                    spell_guess->GetType_guess(slot_guess) == 0xc4 ||
                    spell_guess->GetType_guess(slot_guess) == 0xc8 ||
                    spell_guess->GetType_guess(slot_guess) == 0x72) {
                    if (base_guess < 0) {
                        if (amount_guess >= base_guess) {
                            continue;
                        }
                    } else if (amount_guess >= 0 && amount_guess <= base_guess) {
                        continue;
                    }
                // MeleeMitigation (168), HundredHands (182) and SkillDamageTaken (197): one value is kept,
                // not a sum. A positive value beats any negative one, otherwise the larger magnitude wins (a
                // more negative value replaces a negative one); the group above is the mirror image.
                } else if (spell_guess->GetType_guess(slot_guess) == 0xa8 ||
                           spell_guess->GetType_guess(slot_guess) == 0xb6 ||
                           spell_guess->GetType_guess(slot_guess) == 0xc5) {
                    if (base_guess > 0) {
                        if (amount_guess <= base_guess) {
                            continue;
                        }
                    } else if (amount_guess <= 0 && amount_guess >= base_guess) {
                        continue;
                    }
                } else {
                    if (g_modeCode_guess != 0 && pSpawn_0008_guess != 0 &&
                        pSpawn_0008_guess->type_0244_guess == 0 && amount_guess < 0) {
                        // With g_modeCode_guess non-zero (the modes where players can harm players), negative
                        // resist effects (SPA 46-50) on a player are 1.5 times stronger.
                        if (spell_guess->GetType_guess(slot_guess) == 0x32 ||
                            spell_guess->GetType_guess(slot_guess) == 0x31 ||
                            spell_guess->GetType_guess(slot_guess) == 0x30 ||
                            spell_guess->GetType_guess(slot_guess) == 0x2e ||
                            spell_guess->GetType_guess(slot_guess) == 0x2f) {
                            amount_guess += amount_guess / 2;
                        }
                    }
                    int value_guess;
                    // A lifetap's own buff (active 4) subtracts. A DoT between two players hits for 75% when
                    // self-cast and 70% otherwise, at least 1.
                    if (entry_guess->active_guess == 4) {
                        value_guess = base_guess - amount_guess;
                    } else {
                        if (spell_guess->GetType_guess(slot_guess) == 0 && amount_guess < 0) {
                            MagicStateA_guess* caster_guess = (MagicStateA_guess*)Transform_guess(
                                ((CharacterMagicSystem_guess*)GetTable_guess())->GetBuffCasterId_guess(
                                    entryIndex_guess));
                            MagicStateA_guess* self_guess = pSpawn_0008_guess;
                            if (self_guess != 0 && self_guess->type_0244_guess == 0 &&
                                caster_guess != 0 && caster_guess->type_0244_guess == 0) {
                                amount_guess = (self_guess == caster_guess ? amount_guess * 75
                                                                          : amount_guess * 70) /
                                               100;
                                if (amount_guess > -1) {
                                    amount_guess = -1;
                                }
                            }
                        }
                        value_guess = base_guess + amount_guess;
                    }
                    service_C4_guess.Store_guess(value_guess, spell_guess->GetType_guess(slot_guess),
                                                 extra_guess, flag_guess);
                    continue;
                }
            }
            service_C4_guess.Store_guess(amount_guess, spell_guess->GetType_guess(slot_guess),
                                         extra_guess, flag_guess);
        }
    }
    // Then the worn item effects are merged in.
    FinishSpellAffects_guess();
    fieldC8_guess = 1;
}

struct RaceEntry_guess {
    char padTo24C_guess[0x24c];
    unsigned char field24C_guess;
};

// EXTERNAL: TITANIUM 0x00401B28 LookupRace_guess
RaceEntry_guess* __cdecl LookupRace_guess(unsigned int index_guess);

// Sum of spell effect `affect_guess` from buffs, AAs (`includeAlt_guess`) and items (`includeItems_guess`),
// with haste-style effects taking the best value instead of the sum.
// FUNCTION: TITANIUM 0x004106A3
// @early-stop: budget, diff ndiff=103
int CharacterMagicSystem_guess::TotalSpellAffects_guess(int affect_guess, bool includeAlt_guess,
                                                       int subindex_guess, int includeItems_guess) {
    int bestHaste_guess;
    int haste3_guess;
    int haste2_guess;
    int spellMax3_guess;
    int spellMin3_guess;
    int spellHaste_guess;
    int altHaste_guess;
    int alt15_guess;
    int altMin3_guess;
    int altMax3_guess;
    int itemHaste_guess;
    bestHaste_guess = 999;
    spellHaste_guess = 0;
    haste2_guess = 0;
    haste3_guess = 0;
    spellMin3_guess = 0;
    altMin3_guess = 0;
    spellMax3_guess = 0;
    altMax3_guess = 0;
    alt15_guess = 0;
    altHaste_guess = 0;
    itemHaste_guess = 999;
    if (fieldC8_guess == 0) {
        InitializeSpellAffects_guess();
    }
    int total_guess = GetSpellAffect_guess(affect_guess, subindex_guess);
    if ((char)includeItems_guess != 0) {
        total_guess += GetItemAffect_guess(affect_guess, subindex_guess);
    }
    if (affect_guess == 11) {
        bestHaste_guess = GetSpellAffect_guess(affect_guess, 0);
        spellHaste_guess = GetSpellAffect_guess(affect_guess, 0);
        haste2_guess = GetSpellAffect_guess(0x62, 0);
        haste3_guess = GetSpellAffect_guess(0x77, 0);
    } else if (affect_guess == 3) {
        spellMin3_guess = GetSpellAffect_guess(3, 0);
        spellMax3_guess = GetSpellAffect_guess(3, 0);
    }
    if (includeAlt_guess) {
        MagicStateA_guess* player_guess = pSpawn_0008_guess;
        if (player_guess != 0 && (player_guess->type_0244_guess == 0 || player_guess->masterId_025c_guess != 0)) {
            if (affect_guess == 11) {
                altHaste_guess = fieldB8_guess;
                itemHaste_guess = altHaste_guess;
            } else if (affect_guess == 3) {
                altMin3_guess = GetAltAffect_guess(3, 0);
                altMax3_guess = altMin3_guess;
            } else if (affect_guess == 15) {
                alt15_guess = GetAltAffect_guess(15, 0);
            } else {
                total_guess += GetAltAffect_guess(affect_guess, subindex_guess);
            }
        }
    }
    if (affect_guess == 15) {
        return total_guess + alt15_guess;
    }
    if (affect_guess == 3) {
        if (spellMin3_guess >= 0 && altMin3_guess >= 0) {
            if (spellMax3_guess <= 0 && altMax3_guess <= 0) {
                return 0;
            }
            if (altMax3_guess > spellMax3_guess) {
                return altMax3_guess;
            }
            return spellMax3_guess;
        }
        if (spellMin3_guess < altMin3_guess) {
            return spellMin3_guess;
        }
        return altMin3_guess;
    }
    if (affect_guess == 11) {
        if ((itemHaste_guess < bestHaste_guess && itemHaste_guess > 0) || bestHaste_guess == 0) {
            bestHaste_guess = itemHaste_guess;
        }
        if (bestHaste_guess <= 100 && bestHaste_guess > 0) {
            return bestHaste_guess;
        }
        includeItems_guess = altHaste_guess + spellHaste_guess;
        int cap_guess = ResolveResult_guess()->level_11a4_guess + 0x7d;
        if (haste3_guess > 0) {
            if (haste3_guess > 100) {
                haste3_guess -= 100;
            }
            int limit_guess;
            if (ResolveResult_guess()->level_11a4_guess > 50) {
                limit_guess = 25;
            } else {
                limit_guess = 10;
            }
            if (haste3_guess > limit_guess) {
                haste3_guess = limit_guess;
            }
            cap_guess += haste3_guess;
        }
        if (spellHaste_guess >= 100 && altHaste_guess >= 100) {
            includeItems_guess -= 100;
        }
        if (haste2_guess > 100 && ResolveResult_guess()->level_11a4_guess > 49) {
            if (haste2_guess > 110) {
                haste2_guess = 110;
            }
            if (includeItems_guess != 0) {
                includeItems_guess -= 100;
            }
            includeItems_guess += haste2_guess;
        }
        if (ResolveResult_guess()->level_11a4_guess > 50) {
            cap_guess = haste3_guess + 0xb9;
        }
        if (ResolveResult_guess()->level_11a4_guess > 59) {
            cap_guess = haste3_guess + 0xc8;
        }
        MagicStateA_guess* self_guess = pSpawn_0008_guess;
        if (self_guess != 0 && self_guess->type_0244_guess == 1) {
            if (self_guess->isPet_01b5_guess == 0) {
                cap_guess = haste3_guess + 0xfa;
            } else {
                cap_guess = ResolveResult_guess()->level_11a4_guess + haste3_guess + 0x6e;
                if (pSpawn_0008_guess->masterId_025c_guess != 0) {
                    RaceEntry_guess* race_guess = LookupRace_guess(pSpawn_0008_guess->masterId_025c_guess);
                    if (race_guess != 0) {
                        int value_guess = race_guess->field24C_guess;
                        int bonus_guess = value_guess - 0x27;
                        if (bonus_guess > 0) {
                            cap_guess += bonus_guess;
                        }
                        value_guess -= 0x3c;
                        if (value_guess > 0) {
                            cap_guess += value_guess;
                        }
                    }
                }
            }
        }
        if (includeItems_guess != 0) {
            includeItems_guess += haste3_guess;
        } else if (haste3_guess != 0) {
            includeItems_guess = haste3_guess + 100;
        }
        if (includeItems_guess > cap_guess) {
            includeItems_guess = cap_guess;
        }
        return includeItems_guess;
    }
    return total_guess;
}

// Cast check for a gem or song: can miss a note (12439 "You miss a note..."), recover (4057), or fizzle (173
// "Your spell fizzles!").
// FUNCTION: TITANIUM 0x004109DF
// @early-stop: budget, structural ndiff=120
char CharacterMagicSystem_guess::CheckCast_guess(unsigned char mode_guess,
                                                   MagicPredicateObject_guess* spell_guess) {
    unsigned char spellRank_guess = spell_guess->field181_guess;
    int success_guess = 0;
    if (pSpawn_0008_guess == 0) {
        return 0;
    }
    if (pSpawn_0008_guess->type_0244_guess != 0) {
        return 0;
    }
    if (mode_guess > 8) {
        return 0;
    }
    if (spellRank_guess == 0 && TotalSpellAffects_guess(0x70, true, 0, true) >= 0) {
        success_guess = 0x5f;
    } else {
        if (spell_guess == g_magicLookup_guess->field48_guess &&
            ResolveResult_guess()->class_119c_guess != Class_Cleric) {
            spellRank_guess = 0;
        }
        unsigned char currentMode_guess = ResolveResult_guess()->class_119c_guess;
        if (spell_guess->Check_guess(currentMode_guess) >= 0x38) {
            spellRank_guess = 0;
        }
        switch (ResolveResult_guess()->class_119c_guess) {
        case 2:
        case 6:
        case 10:
            success_guess = field28_guess;
            break;
        case 3:
        case 4:
        case 15:
            success_guess = field28_guess;
            if (spell_guess->Check_guess(ResolveResult_guess()->class_119c_guess) > 0x28) {
                spellRank_guess = 0;
            }
            break;
        case 5:
            success_guess = field20_guess;
            if (spell_guess->Check_guess(ResolveResult_guess()->class_119c_guess) > 0x28) {
                spellRank_guess = 0;
            }
            break;
        case 8:
            success_guess = (field1C_guess + field18_guess) / 2;
            if (spellRank_guess > 0xf) {
                spellRank_guess = 0xf;
            }
            break;
        case 11:
        case 12:
        case 13:
        case 14:
            success_guess = field20_guess;
            break;
        }
        if (success_guess > 0) {
            int maximumRank_guess = (int)spell_guess->Check_guess(
                ResolveResult_guess()->class_119c_guess) - 1;
            if (maximumRank_guess > 0x32) {
                maximumRank_guess = 0x32;
            }
            int spellAdjustment_guess = 0;
            if (HasSkillChecked_guess(spell_guess->field182_guess) != 0) {
                spellAdjustment_guess = Skill_guess(spell_guess->field182_guess);
                spellAdjustment_guess += TotalSpellAffects_guess(0x70, true, 0, true);
                if (spellAdjustment_guess < 0) {
                    spellAdjustment_guess = 0;
                }
            }
            int randomPenalty_guess = RandomRange_guess(0, 10);
            success_guess = ((0x12 - maximumRank_guess) * 5 + success_guess / 10) -
                (int)spellRank_guess + spellAdjustment_guess - randomPenalty_guess;
            if (ResolveResult_guess()->class_119c_guess == Class_Bard) {
                if (success_guess < 1) {
                    success_guess = 1;
                }
            } else if (success_guess < 5) {
                success_guess = 5;
            }
            if (success_guess > 0x5f) {
                success_guess = 0x5f;
            }
        }
    }
    int spellEffect_guess = normal_to_special_guess(spell_guess->field182_guess);
    int effectGuess_guess = 0;
    if (spellEffect_guess != 0) {
        effectGuess_guess = Skill_guess(spellEffect_guess);
    }
    if (effectGuess_guess > 0 && effectGuess_guess < 0xfc) {
        success_guess += effectGuess_guess / 10 + 1;
    }
    if (success_guess > 0x62) {
        success_guess = 0x62;
    }
    int successRoll_guess = number_percent_guess();
    int minimumRoll_guess;
    if (spell_guess->field1C4_guess == 0 && FindBuffWithEffect_guess(0x60, 0) != 0) {
        minimumRoll_guess = success_guess + 1;
    } else {
        if (successRoll_guess <= success_guess) {
            return 0;
        }
        if (::IsBardSong_guess(spell_guess, ResolveResult_guess()->class_119c_guess) != 0) {
            int messageRoll_guess = TotalSpellAffects_guess(0xeb, true, 0, true);
            if (number_percent_guess() <= messageRoll_guess) {
                token_string_to_client_guess(this, 0xfd9, 0x121, 0);
                successRoll_guess = success_guess;
            }
        }
        minimumRoll_guess = successRoll_guess;
    }
    if (minimumRoll_guess <= success_guess) {
        return 0;
    }
    int manaCost_guess = (spell_guess->field2C_guess * 4) / 10;
    int mana_guess = ((MagicManaAccess_guess*)this)->GetMana_guess();
    if (mana_guess / 8 < manaCost_guess) {
        manaCost_guess = mana_guess / 8;
    }
    GetTable_guess()->AddField11A8_guess(-manaCost_guess);
    if (ResolveResult_guess()->mana_11a8_guess < 0) {
        ResolveResult_guess()->mana_11a8_guess = 0;
    }
    if (::IsBardSong_guess(spell_guess, ResolveResult_guess()->class_119c_guess) == 0) {
        token_string_to_client_guess(this, 0xad, 0x121, 0);
    } else {
        g_magicMessageRouter_guess->dsp_chat(
            pStringTable->getString(0x3097, 0), 0x121, true);
    }
    return 1;
}

// EXTERNAL: TITANIUM 0x0060F81E NormalizeMagicAmount_guess
int __cdecl NormalizeMagicAmount_guess(int amount_guess);

// Buff slot count minus 2, 1 or 14 by flag, else a delay reduced by spell effect 327 (0x147).
// FUNCTION: TITANIUM 0x00410DB0
int CharacterMagicSystem_guess::GetDelayFromState_guess(char first_guess, char second_guess,
                                                        char third_guess) {
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
        if (first_guess != 0) {
            return (unsigned char)GetMaxBuffs_guess(this) - 2;
        }
        if (second_guess != 0) {
            return (unsigned char)GetMaxBuffs_guess(this) - 1;
        }
        if (third_guess != 0) {
            return (unsigned char)GetMaxBuffs_guess(this) - 0xe;
        }
        int lowA_guess = 10 - NormalizeMagicAmount_guess(
            TotalSpellAffects_guess(0x147, true, 0, true));
        int lowB_guess;
        if (lowA_guess < 0) {
            lowB_guess = 0;
        } else {
            lowB_guess = 10 - NormalizeMagicAmount_guess(
                TotalSpellAffects_guess(0x147, true, 0, true));
        }
        return (unsigned char)GetMaxBuffs_guess(this) - lowB_guess - 0xe;
    }
    return (unsigned char)GetMaxBuffs_guess(this) - 1;
}

// Buff duration in ticks: the spell's duration formula (+0x1EC) applied to caster level `amount_guess`,
// capped by the spell's max duration (+0x1F0). Formula 50 is permanent (-1); an unknown formula gives -2
// with `flag_guess`, else 0 below 200 or the formula number itself. An illusion with +0x17D set lasts 10000
// while we have an IllusionPersistence (238) effect.
// FUNCTION: TITANIUM 0x00410E5A
// @early-stop: budget, structural ndiff=86
int CharacterMagicSystem_guess::GetSpellDuration_guess(MagicCheck_guess* check_guess,
                                                  unsigned char amount_guess,
                                                  char flag_guess) {
    unsigned int value_guess = 0;
    if (check_guess == 0) {
        return value_guess;
    }

    unsigned int type_guess = check_guess->field1ec_guess;
    unsigned int one_guess = 1;
    if (type_guess != 0) {
        value_guess = 50;
        switch (type_guess) {
        case 1:
            if ((amount_guess & 0xfe) < 2) {
                value_guess = one_guess;
            } else {
                value_guess = amount_guess >> 1;
            }
            break;
        case 2: {
            unsigned int base_guess = one_guess;
            if ((amount_guess & 0xfe) >= 2) {
                base_guess = amount_guess >> 1;
            }
            value_guess = base_guess + 5;
            break;
        }
        case 3:
            value_guess = (unsigned int)amount_guess * 30;
            break;
        case 4:
            break;
        case 5:
            value_guess = 2;
            break;
        case 6:
            value_guess = (amount_guess >> 1) + 2;
            break;
        case 7:
            value_guess = amount_guess;
            break;
        case 8:
            value_guess = amount_guess + 10;
            break;
        case 9:
            value_guess = (unsigned int)amount_guess * 2 + 10;
            break;
        case 10:
            value_guess = (unsigned int)amount_guess * 3 + 10;
            break;
        case 11:
            value_guess = ((unsigned int)amount_guess + 3) * 30;
            break;
        case 12:
            value_guess = amount_guess >> 2;
            if (value_guess == 0) {
                value_guess = 1;
            }
            break;
        case 50:
            return -1;
        default:
            if (flag_guess != 0) {
                return -2;
            }
            if (type_guess < 200) {
                return 0;
            }
            value_guess = type_guess;
            break;
        }

        unsigned int limit_guess = check_guess->field1f0_guess;
        if (limit_guess != 0 && value_guess > limit_guess) {
            value_guess = limit_guess;
        }
    }

    if (check_guess->field17d != 0 && type_guess != 0 && pSpawn_0008_guess != 0 &&
        pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
        TotalSpellAffects_guess(0xee, one_guess, 0, one_guess) != 0 &&
        check_guess->FindAffectSlot_guess(0x3a) != 0) {
        value_guess = 10000;
    }
    return value_guess;
}

// Applies run-speed buffs and snares (effect 271 override) to the mount or the player; -1000 or less roots.
// FUNCTION: TITANIUM 0x00410FDB
void CharacterMagicSystem_guess::ApplyMovementModifier_guess(int amount_guess) {
    if (pSpawn_0008_guess == 0) {
        return;
    }
    if (pSpawn_0008_guess->pActorInfo_01a8_guess == 0) {
        return;
    }
    MagicStateA_guess* linkedState_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess;
    if (linkedState_guess != 0) {
        if (amount_guess > 0) {
            linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess = 0.0f;
            return;
        }
        if (amount_guess <= -1000) {
            linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess = (float)amount_guess;
            linkedState_guess->speedRun_0048_guess = 0.0f;
            linkedState_guess->field3C_guess = 0.0f;
            linkedState_guess->field40_guess = 0.0f;
            linkedState_guess->field58_guess = 0.0f;
        }
    }
    if (amount_guess <= -1000) {
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess = (float)amount_guess;
        pSpawn_0008_guess->speedRun_0048_guess = 0.0f;
        pSpawn_0008_guess->field3C_guess = 0.0f;
        pSpawn_0008_guess->field40_guess = 0.0f;
        pSpawn_0008_guess->field58_guess = 0.0f;
        pSpawn_0008_guess->TurnOffAutoFollow_guess();
        return;
    }
    if (amount_guess < -65) {
        amount_guess = -65;
    }
    float scaled_guess = (float)NormalizeMagicAmount_guess(amount_guess) * g_magicRate_guess;
    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess = scaled_guess * pSpawn_0008_guess->runSpeed_0230_guess;
    if (amount_guess < 0) {
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess =
            -pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess;
    }
    if (g_magicOverride_guess != 0 && amount_guess == 0) {
        int override_guess = TotalSpellAffects_guess(0x10f, true, 0, true);
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess = (float)override_guess * g_magicRate_guess;
    }
    if (pSpawn_0008_guess == 0) {
        return;
    }
    if (pSpawn_0008_guess->pActorInfo_01a8_guess == 0) {
        return;
    }
    linkedState_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess;
    if (linkedState_guess == 0) {
        return;
    }
    if (amount_guess < 0) {
        linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess = scaled_guess * linkedState_guess->runSpeed_0230_guess;
        linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess =
            -linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess;
        return;
    }
    linkedState_guess->pActorInfo_01a8_guess->fieldC8_guess = 0.0f;
}

// Buff slot `index_guess`: 0-24 long, 25-59 short; out of range returns slot 0.
// FUNCTION: TITANIUM 0x0040E7AC
MagicEntryProbe_guess* CharacterMagicSystem_guess::GetBuff_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < 25) {
        return (MagicEntryProbe_guess*)((MagicRecordTable_guess*)ResolveResult_guess())
            ->GetRecordA_guess(index_guess);
    }
    if (index_guess >= 25 && index_guess < 60) {
        return (MagicEntryProbe_guess*)((MagicRecordTable_guess*)ResolveResult_guess())
            ->GetRecordB_guess(index_guess - 25);
    }
    return (MagicEntryProbe_guess*)((MagicRecordTable_guess*)ResolveResult_guess())->recordsA_guess;
}

// Removes buff `entryValue_guess`: undoes its effects (illusions, levitate, mounts...) and, with
// `send_guess`, sends OP_Buff to the server.
// FUNCTION: TITANIUM 0x00411161
// @early-stop: budget, structural ndiff=283
void CharacterMagicSystem_guess::RemovePCAffectex_guess(MagicEntryProbe_guess* entryValue_guess,
                                                    int send_guess) {
    int zero_guess = 0;
    if (entryValue_guess == 0) {
        return;
    }
    int* entryWords_guess = (int*)entryValue_guess;
    MagicEntryProbe_guess* entry_guess = entryValue_guess;
    int checkValue_guess;
    if (IsValidSpellIndex_guess(entryWords_guess[1]) == zero_guess) {
        checkValue_guess = zero_guess;
    } else {
        checkValue_guess = (int)g_magicLookup_guess->GetSpell_guess(entryWords_guess[1]);
    }
    entryValue_guess = 0;
    if ((unsigned char)GetMaxBuffs_guess(this) <= zero_guess) {
        return;
    }
    while (entry_guess != GetBuff_guess((int)entryValue_guess)) {
        entryValue_guess = (MagicEntryProbe_guess*)((int)entryValue_guess + 1);
        if ((int)entryValue_guess >= (unsigned char)GetMaxBuffs_guess(this)) {
            return;
        }
    }
    if (checkValue_guess != zero_guess) {
        MagicCheck_guess* check_guess = (MagicCheck_guess*)checkValue_guess;
        int type_guess = check_guess->values_120[0];
        if (type_guess == 0x17 || type_guess == 0x16 || check_guess->field17d == 0) {
            ((CharacterMagicSystem_guess*)GetTable_guess())->GetBuffCasterId_guess((int)entryValue_guess);
        }
        if (check_guess->FindAffectSlot_guess(0x3a) != 0) {
            MagicResult_guess* result_guess = GetTable_guess()->service_guess.GetCharInfo2();
            unsigned char key_guess = result_guess->gender_1194_guess;
            result_guess = GetTable_guess()->service_guess.GetCharInfo2();
            if (pSpawn_0008_guess->CanFitIllusionRace_guess(result_guess->race_1198_guess, key_guess,
                                                -1.0f) == 0) {
                return;
            }
        }
        if (check_guess->FindAffectSlot_guess(0x9c) != 0) {
            MagicResult_guess* result_guess = GetTable_guess()->service_guess.GetCharInfo2();
            float value_guess = result_guess->field11FC_guess;
            result_guess = GetTable_guess()->service_guess.GetCharInfo2();
            unsigned char key_guess = result_guess->gender_1194_guess;
            result_guess = GetTable_guess()->service_guess.GetCharInfo2();
            if (pSpawn_0008_guess->CanFitIllusionRace_guess(result_guess->race_1198_guess, key_guess,
                                                (float)value_guess) == 0) {
                return;
            }
        }
    }

    int savedId_guess = entry_guess->id_guess;
    entry_guess->id_guess = -1;
    entry_guess->active_guess = (char)zero_guess;
    entry_guess->casterLevel_0001_guess = (char)zero_guess;
    entry_guess->unknown08_guess = zero_guess;
    entry_guess->padTo04_guess[1] = (char)zero_guess;
    entry_guess->padTo04_guess[0] = (char)zero_guess;
    entry_guess->counters_000c_guess = zero_guess;
    entry_guess->unknown10_guess = zero_guess;
    ((CharacterMagicSystem_guess*)GetTable_guess())->SetBuffCasterId_guess((int)entryValue_guess, zero_guess);
    fieldC8_guess = (char)zero_guess;
    if (checkValue_guess == zero_guess) {
        return;
    }
    if (pSpawn_0008_guess != 0) {
        for (int index_guess = 0; index_guess < 12; ++index_guess) {
            int value_guess = ((MagicCheck_guess*)checkValue_guess)->values_120[index_guess];
            if (value_guess == 0x39) {
                if (pSpawn_0008_guess->IsLevitating_guess() == zero_guess) {
                    pSpawn_0008_guess->SetLevitate_guess(zero_guess);
                    if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
                        pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
                        pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->SetLevitate_guess(zero_guess);
                    }
                }
            } else if (value_guess == 3) {
                if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
                    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess = 0.0f;
                }
                int result_guess = TotalSpellAffects_guess(99, true, zero_guess, true);
                if (result_guess >= 0) {
                    result_guess = TotalSpellAffects_guess(3, true, zero_guess, true);
                    if (result_guess != zero_guess) {
                        ApplyMovementModifier_guess(result_guess);
                    }
                } else {
                    ApplyMovementModifier_guess(result_guess);
                }
            } else if (value_guess == 0xc || (value_guess >= 0x1c && value_guess <= 0x1d) ||
                       (value_guess > 0x139 && value_guess < 0x13d)) {
                UpdateInvisibility_guess();
            } else if (value_guess == 0xd) {
                UpdateAllPlayersVisibility_guess();
                if (g_magicCurrent_guess != 0 && g_magicCurrent_guess != g_magicWorld_guess &&
                    g_magicWorld_guess->IsInvisibleToMe_guess(g_magicCurrent_guess) != 0) {
                    g_magicCurrent_guess = 0;
                }
            } else if (value_guess == 0x14) {
                if (pSpawn_0008_guess != 0) {
                    pSpawn_0008_guess->pActorInfo_01a8_guess->field154_guess = (unsigned char)zero_guess;
                }
            } else if (value_guess == 0x1f) {
                if (TotalSpellAffects_guess(0x1f, true, zero_guess, true) == zero_guess &&
                    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldD0_guess == zero_guess) {
                    field100_guess = (unsigned char)zero_guess;
                }
            } else if (value_guess == 0x41 || value_guess == 0x42) {
                if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == zero_guess) {
                    MagicResult_guess* result_guess = GetTable_guess()->service_guess.GetCharInfo2();
                    unsigned int first_guess = result_guess->values1100_guess[10];
                    result_guess = GetTable_guess()->service_guess.GetCharInfo2();
                    InitInnates_guess(pSpawn_0008_guess->anon_0264_guess, result_guess->class_119c_guess);
                    ((CharacterMagicSystem_guess*)GetTable_guess())->Write1100_guess(10, first_guess);
                    g_magicSession_guess->TurnInfravisionEffectOff_guess();
                }
            } else if (value_guess == 0x43) {
                if (g_magicLinked_guess != 0) {
                    g_magicLinked_guess->headEnvironmentChange_guess(
                        g_magicWorld_guess->pActorInfo_01a8_guess->fieldAC_guess);
                }
                if (pSpawn_0008_guess->pActorInfo_01a8_guess == 0 ||
                    (g_magicLinked_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess) == 0) {
                    g_magicLinked_guess = pSpawn_0008_guess;
                    g_magicSession_guess->SetViewActorByName_guess(pSpawn_0008_guess->values120_guess);
                }
            } else if (value_guess == 0x49) {
                g_magicSession_guess->SetViewActorByName_guess(pSpawn_0008_guess->values120_guess);
            } else if (value_guess == 0x57) {
                int index_guess = g_magicSlotIndex_guess;
                int value_guess = (int)g_cameras_guess[index_guess]->value40_guess;
                g_magicSession_guess->FUN_00440f51_guess(value_guess);
            } else if (value_guess == 99) {
                pSpawn_0008_guess->pActorInfo_01a8_guess->fieldC8_guess = 0.0f;
                int result_guess = TotalSpellAffects_guess(3, true, zero_guess, true);
                if (result_guess != zero_guess) {
                    ApplyMovementModifier_guess(result_guess);
                }
            }
        }
    }
    fieldC_guess = 1;
    if (send_guess != 0 && (int)entryValue_guess != -1) {
        int message_guess[8];
        message_guess[0] = (int)pSpawn_0008_guess->spawnId_0258_guess;
        memcpy(&message_guess[1], GetBuff_guess((int)entryValue_guess), 0x14);
        message_guess[2] = savedId_guess;
        message_guess[6] = (int)entryValue_guess;
        EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_Buff, message_guess,
                           0x20, 1);
    }
}

// Bard instrument modifier for song `value_guess`: the best of the instrument skill mods and effect 260
// (0x104) buffs; shows the instrument messages 0x195-0x198/0x10D.
// FUNCTION: TITANIUM 0x0041167C
// @early-stop: budget, structural ndiff=172
int CharacterMagicSystem_guess::GetInstrumentModifier_guess(int value_guess) {
    int extra_guess = 0;
    int local8_guess = 0;
    int amount_guess = 10;
    int result_guess = 0;
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
        MagicCheck_guess* entry_guess = 0;
        if (IsValidSpellIndex_guess(value_guess) != 0) {
            entry_guess = g_magicLookup_guess->GetSpell_guess(value_guess);
        }
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFA4_guess = 10;
        int base_guess = TotalSpellAffects_guess(0xb3, true, 0, true);
        if (base_guess != 0) {
            amount_guess = base_guess;
        }
        char kind_guess = entry_guess->field182_guess;
        if (kind_guess == '\f' || kind_guess == '1' || kind_guess == '6' || kind_guess == 'F') {
        int slot_guess;
        if (kind_guess == '\f') {
            slot_guess = 0x19;
            value_guess = 0x198;
        } else if (kind_guess == '1') {
            slot_guess = 0x18;
            value_guess = 0x197;
        } else if (kind_guess == '6') {
            slot_guess = 0x17;
            value_guess = 0x196;
        } else {
            slot_guess = 0x1a;
            value_guess = 0x195;
        }
        int rank_guess = GetBestRank_guess(slot_guess);
        if (rank_guess == 0) {
            if (entry_guess->fieldE0_guess != -1) {
                token_string_to_client_guess(this, value_guess, 0x121, 0);
                return 0;
            }
        } else {
            if (HasSkillChecked_guess(kind_guess) == 0) {
                value_guess = 0x10d;
                token_string_to_client_guess(this, value_guess, 0x121, 0);
                return 0;
            }
            if (amount_guess < rank_guess) {
                amount_guess = rank_guess;
            }
        }
        if (slot_guess > 0) {
            extra_guess = TotalSpellAffects_guess(0x104, true, slot_guess, true);
            extra_guess += TotalSpellAffects_guess(0x104, true, 0x33, true);
        }
        } else {
        local8_guess = TotalSpellAffects_guess(0x76, true, 0, true);
        if (local8_guess > 0x1c) {
            local8_guess = 0x1c;
        }
        if (amount_guess == 0) {
            extra_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFA4_guess;
        }
        extra_guess += TotalSpellAffects_guess(0x104, true, 0x32, true);
        int second_guess = TotalSpellAffects_guess(0x104, true, 0x33, true);
        int rank_guess = GetBestRank_guess(0x32);
        if (amount_guess < second_guess + rank_guess) {
            amount_guess = second_guess + rank_guess;
        }
        }
        amount_guess += local8_guess + extra_guess;
        if (amount_guess > 0x1c && entry_guess->FindAffectSlot_guess(3) != 0) {
            amount_guess = 0x1c;
        }
        int cap_guess = entry_guess->field26C_guess;
        if (cap_guess != 0 && cap_guess < amount_guess) {
            amount_guess = cap_guess;
        }
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFA4_guess = amount_guess;
        result_guess = 1;
    }
    return result_guess;
}

// Reagents, skill and instrument requirements for spell `spellId_guess`; some spells always pass
// (MagicValueAllowed_guess).
// FUNCTION: TITANIUM 0x0041188E
// @early-stop: budget, structural ndiff=213
char CharacterMagicSystem_guess::CastingRequirementsMet_guess(int spellId_guess) {
    if (IsValidSpellIndex_guess(spellId_guess) == 0) {
        return 0;
    }
    MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
    if (spell_guess == 0) {
        return 0;
    }
    // Exempt from the checks: +0x191 spells, MagicValueAllowed_guess spells, Lay on Hands / Harm Touch (87,
    // 88, 2774) while +0x48 is zero, and NPCs.
    if (spell_guess->field191_guess != 0) {
        return 1;
    }
    if (MagicValueAllowed_guess(spellId_guess) != 0) {
        return 1;
    }
    if (pSpawn_0008_guess->speedRun_0048_guess == 0.0f &&
        (spellId_guess == 0x57 || spellId_guess == 0x58 || spellId_guess == 0xad6)) {
        return 1;
    }
    if (pSpawn_0008_guess->type_0244_guess != 0) {
        return 1;
    }
    int missing_guess[55];
    int count_guess = 0;
    char failed_guess = 0;
    if (ResolveResult_guess()->class_119c_guess == Class_Bard) {
        // Bards need the song's instrument instead (GetInstrumentModifier_guess).
        if (GetInstrumentModifier_guess(spellId_guess) == 0) {
            return 0;
        }
    } else {
        if (spell_guess->field1fc == 0 && GetTable_guess()->field104_guess != 'd') {
            token_string_to_client_guess(this, 0xd5, 0x121, 0);
            return 0;
        }
        MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
        MagicStateB_guess* actor_guess = stateValue_guess->pActorInfo_01a8_guess;
        // Channeling: moved since the cast began (or knocked back) or hit (+0x114 = hits taken) means a skill
        // check, once per 3/4 hit. Channeling skill (13), plus ChannelChanceItems (SPA 344) for item casts,
        // against a roll of 1-390 scaled by ChannelChanceSpells (SPA 235); moving more than 1 unit always
        // fails. Success says 0x10E.
        float dy_guess = stateValue_guess->position_guess.y_guess - actor_guess->fieldFF8_guess;
        float dx_guess = stateValue_guess->position_guess.x_guess - actor_guess->fieldFFC_guess;
        if (actor_guess->field158_guess != 0) {
            dy_guess = stateValue_guess->field3C_guess;
            dx_guess = stateValue_guess->field40_guess;
        }
        if ((pSpawn_0008_guess->pActorInfo_01a8_guess->field158_guess == 0 &&
             (fabs(dy_guess) > 0.1 || fabs(dx_guess) > 0.1)) ||
            GetTable_guess()->field114_guess != 0) {
            if (pSpawn_0008_guess->speedRun_0048_guess != 0.0f) {
                return 0;
            }
            if (fabs(dy_guess) > 1.0) {
                return 0;
            }
            if (fabs(dx_guess) > 1.0) {
                return 0;
            }
            int tries_guess = GetTable_guess()->field114_guess * 3 / 4 + 1;
            if (tries_guess < 1) {
                tries_guess = 1;
            }
            int skill_guess = Skill_guess(0xd);
            if (pSpawn_0008_guess->pActorInfo_01a8_guess->field104C_guess != 0) {
                skill_guess += TotalSpellAffects_guess(0x158, true, 0, true);
            }
            if (skill_guess == 0) {
                return 0;
            }
            int roll_guess = RandomRange_guess(1, 0x186);
            roll_guess = TotalSpellAffects_guess(0xeb, true, 0, true) * roll_guess / 100;
            for (int try_guess = 0; try_guess < tries_guess; ++try_guess) {
                int level_guess =
                    spell_guess->CheckMode_guess(ResolveResult_guess()->class_119c_guess);
                int bonus_guess = 0;
                if (ResolveResult_guess()->level_11a4_guess > level_guess + 5) {
                    bonus_guess =
                        (ResolveResult_guess()->level_11a4_guess - level_guess) * 6 / 2 + 0x23;
                }
                int total_guess = ResolveResult_guess()->level_11a4_guess + bonus_guess + skill_guess;
                if (total_guess > 0x172) {
                    total_guess = 0x172;
                }
                if (roll_guess > total_guess && roll_guess >= 0x27) {
                    return 0;
                }
            }
            token_string_to_client_guess(this, 0x10e, 0x108, 0);
        }
    }
    if (IsBardSong_guess((MagicPredicateObject_guess*)spell_guess,
                        ResolveResult_guess()->class_119c_guess) != 0) {
        return 1;
    }
    int index_guess;
    for (index_guess = 0; index_guess < 4; ++index_guess) {
        // Focus items (+0xE0, needed but kept) must be carried, except for pet spells (SPA 33, 71, 106, 108).
        if (spell_guess->FindAffectSlot_guess(0x21) != 0 || spell_guess->FindAffectSlot_guess(0x47) != 0 ||
            spell_guess->FindAffectSlot_guess(0x6a) != 0 || spell_guess->FindAffectSlot_guess(0x6c) != 0) {
            break;
        }
        if (spell_guess->GetE0_guess(index_guess) != -1 &&
            FindItemById_guess(spell_guess->GetE0_guess(index_guess), 0, 0, 0) == 0) {
            failed_guess = 1;
            missing_guess[count_guess++] = spell_guess->GetE0_guess(index_guess);
        }
    }
    for (index_guess = 0; index_guess < 4; ++index_guess) {
        // Reagents (+0xC0 ids, +0xD0 counts) must all be there first.
        if (spell_guess->GetC0_guess(index_guess) != -1 &&
            FUN_00424058_guess(spell_guess->GetC0_guess(index_guess),
                               spell_guess->GetD0_guess(index_guess)) == 0) {
            failed_guess = 1;
            missing_guess[count_guess++] = spell_guess->GetC0_guess(index_guess);
        }
    }
    if (failed_guess == 0) {
        int* out_guess = &missing_guess[count_guess];
        bool skipped_guess = false;
        for (index_guess = 0; index_guess < 4; ++index_guess) {
            if (spell_guess->GetC0_guess(index_guess) == -1) {
                continue;
            }
            for (int n_guess = 0; n_guess < spell_guess->GetD0_guess(index_guess); ++n_guess) {
                count_guess = 0;
                int id_guess = spell_guess->GetC0_guess(index_guess);
                if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
                    ResolveResult_guess()->class_119c_guess != Class_Bard &&
                    pSpawn_0008_guess->pActorInfo_01a8_guess->field1048_guess == 0 && id_guess != 0x26eb &&
                    id_guess != 0x276c && id_guess != 0x276e) {
                    // Then they are used up; non-bards may save one reagent by the conservation chance
                    // (GetFocusReagentSaveChance_guess), not for items 9963, 10092 and 10094 or item casts.
                    int chance_guess = GetFocusReagentSaveChance_guess(spell_guess, &count_guess);
                    if (chance_guess != 0 && RandomRange_guess(1, 100) <= chance_guess &&
                        !skipped_guess) {
                        skipped_guess = true;
                        continue;
                    }
                }
                if (RemoveOneItem_guess(-1, spell_guess->GetC0_guess(index_guess)) == 0) {
                    failed_guess = 1;
                    *out_guess++ = spell_guess->GetC0_guess(index_guess);
                    break;
                }
            }
        }
        if (failed_guess == 0) {
            return 1;
        }
    }
    // Missing reagents: 0x30BD (bards only when option 9 allows it).
    if (ResolveResult_guess()->class_119c_guess != Class_Bard || g_magicTimer_guess.Check_guess(9) != 1) {
        g_magicMessageRouter_guess->dsp_chat(
            pStringTable->getString(0x30bd, 0), 0x121, true);
    }
    return 0;
}

struct Wrap411F2F_guess {
    // EXTERNAL: TITANIUM 0x00411161 Wrap411F2F_guess::RemovePCAffectex_guess
    void RemovePCAffectex_guess(MagicEntryProbe_guess* value_guess, int flag_guess);
    void RemovePCAffect_guess(int value_guess);
};

// Removes buff `value` and undoes its effects, telling the server (0x00411161 with send set).
// FUNCTION: TITANIUM 0x00411F2F
void Wrap411F2F_guess::RemovePCAffect_guess(int value_guess) {
    RemovePCAffectex_guess((MagicEntryProbe_guess*)value_guess, 1);
}

struct MagicCharData_guess {
    char padToD5C_guess[0xd5c];
    int fieldD5C_guess;
    char padToC280_guess[0xc280 - 0xd60];
    CharacterMagicSystem_guess magic_guess;
};

struct MagicZoneCheck_guess {
    // EXTERNAL: TITANIUM 0x005F6C00 MagicZoneCheck_guess::FUN_005f6c00_guess
    char FUN_005f6c00_guess(int zone_guess);
    // EXTERNAL: TITANIUM 0x005F6B90 MagicZoneCheck_guess::FUN_005f6b90_guess
    int FUN_005f6b90_guess(int zone_guess);
    // EXTERNAL: TITANIUM 0x005F6F20 MagicZoneCheck_guess::FUN_005f6f20_guess
    int FUN_005f6f20_guess(const char* name_guess);
};

struct MagicFadePacket_guess {
    short spawnId_guess;
    short type_guess;
    int value_guess;
};

struct MagicCastTimePacket_guess {
    short spawnId_guess;
    short spellId_guess;
    unsigned int time_guess;
};

struct MagicCastPacket_guess {
    int slot_guess;
    int spellId_guess;
    int ref_guess;
    int targetId_guess;
    int value_guess;
};

#define g_magicCharData_guess EQ_GLOBAL(MagicCharData_guess*, 0x00905D00)
#define g_magicZoneCheck_guess EQ_GLOBAL(MagicZoneCheck_guess*, 0x00905CC0)
#define g_magicBusy_guess EQ_GLOBAL(char, 0x0092384C)
#define g_magicStandFlag_guess EQ_GLOBAL(char, 0x009254F7)

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();

// EXTERNAL: TITANIUM 0x00476167 CastRay
int __cdecl CastRay(MagicStateA_guess* caster_guess, float y_guess, float x_guess,
                               float z_guess);

// Casts spell `spellId_guess` from gem `slot_guess` or an item: refuses while distracted (12440; 5819 for a
// combat ability), stunned (175 / 5820), already casting (12442), too low level (12443), out of sight (108);
// breaks invisibility (effects 12, 28, 29, 94, 314-316) and sends OP_CastSpell.
// FUNCTION: TITANIUM 0x00411F3D
// @early-stop: budget, structural ndiff=773
char CharacterMagicSystem_guess::CastSpell(unsigned char slot_guess, int spellId_guess,
                                                 MagicEntry_guess** itemRef_guess,
                                                 MagicCastRef_guess ref_guess,
                                                 int altIndex_guess) {
    int rangeMod_guess = 0;
    int castId_guess;
    MagicEntry_guess* item_guess;
    if (pSpawn_0008_guess == 0 || pSpawn_0008_guess->pActorInfo_01a8_guess == 0) {
        return 0;
    }
    if (pSpawn_0008_guess == g_magicWorld_guess && g_magicBusy_guess != 0) {
        return 0;
    }
    if (itemRef_guess == 0) {
        item_guess = 0;
    } else {
        item_guess = *itemRef_guess;
    }
    MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
    if (spell_guess == 0) {
        return 0;
    }
    // Casting is off right now (IsOkToTransact_guess): item clicks fail silently, spells say string 12440
    // ("too distracted to cast a spell"), combat abilities 5819 ("too distracted to use a skill"). +0x1C4
    // marks a combat ability throughout; it is the byte SPA 311 (LimitCombatSkills) tests in tu_011.
    if (g_magicMessageRouter_guess->IsOkToTransact_guess() == 0) {
        if (itemRef_guess != 0) {
            return 0;
        }
        if (spell_guess->field1C4_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x16bb, 0), 0x121, 1);
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x3098, 0), 0x121, 1);
        }
        return 0;
    }
    // Unless the spell ignores it (+0x1FC): only while standing (100; a sitting player with auto-stand gets
    // up), not under Divine Aura (SPA 40, 0xAE), not stunned (+0xFC, 0xAF).
    if (spell_guess->field1fc == 0) {
        if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->standState_0251_guess != 100) {
            if (pSpawn_0008_guess->standState_0251_guess == 0x6e && g_magicStandFlag_guess != 0) {
                pSpawn_0008_guess->Notify_guess(100);
            }
            if (pSpawn_0008_guess->standState_0251_guess != 100) {
                if (spell_guess->field1C4_guess != 0) {
                    token_string_to_client_guess(this, 300, 0x121, 0);
                } else {
                    token_string_to_client_guess(this, 0x3099, 0x121, 0);
                }
                // StandState 0x66 adds a second line: "You do not have control of yourself right now."
                if (pSpawn_0008_guess->standState_0251_guess != 0x66) {
                    return 0;
                }
                token_string_to_client_guess(this, 0x3050, 0x121, 0);
                return 0;
            }
        }
        if (TotalSpellAffects_guess(0x28, true, 0, 1) > 0) {
            token_string_to_client_guess(this, 0xae, 0x121, 0);
            return 0;
        }
        if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0 &&
            GetTable_guess()->fieldFC_guess == 1) {
            if (spell_guess->field1C4_guess != 0) {
                token_string_to_client_guess(this, 0x16bc, 0x121, 0);
            } else {
                token_string_to_client_guess(this, 0xaf, 0x121, 0);
            }
            return 0;
        }
    }
    if (item_guess != 0 && item_guess->GetRecastTime_guess() > 0 && altIndex_guess == 0 &&
        pSpawn_0008_guess->type_0244_guess == 0) {
        // The item's recast timer is still running: 0xEC.
        unsigned int now_guess = FUN_00576e80_guess();
        if (now_guess < GetTable_guess()->GetObject_guess()->GetItemTimerValue(item_guess)) {
            token_string_to_client_guess(this, 0xec, 0x121, 0);
            return 0;
        }
    }
    // Sanctuary (SPA 312) ends when we cast anything but a beneficial spell on ourselves.
    if (TotalSpellAffects_guess(0x138, true, 0, 1) != 0) {
        if (spell_guess->field17d == 0 ||
            (((MagicMode_guess*)spell_guess)->IsAccepted_guess() != 0 &&
             g_magicCurrent_guess != pSpawn_0008_guess) ||
            (((MagicMode_guess*)spell_guess)->IsAccepted_guess() == 0 &&
             spell_guess->field180_guess != 6)) {
            MagicEntryProbe_guess* entry_guess;
            while ((entry_guess = FindBuffWithEffect_guess(0x138, 0)) != 0) {
                ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)entry_guess);
            }
        }
    }
    // Casting breaks invisibility unless the spell allows it: buffs with SPA 12, 28, 29, 94 and 314-316 go,
    // on us and in pCharData's copy, and OP_SpawnAppearance (0x7C32) type 3 tells the zone we are visible.
    if (spell_guess->KeepsInvisibility_guess() != 0) {
        if (spell_guess->FUN_0044d0e6_guess() != 0 && pSpawn_0008_guess->hideMode_0250_guess != 1) {
            // 0x0044D0ED: the spell may be cast while invisible. If 0x0044D0E6 also holds it must be: string
            // 9240 ("you have not been hidden for long enough") unless +0x250 is 1.
            token_string_to_client_guess(this, 0x2418, 0x121, 0);
            return 0;
        }
    } else {
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x5e, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0xc, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x1c, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x1d, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13a, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13b, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13c, 0));
        if (pSpawn_0008_guess->hideMode_0250_guess != 0) {
            MagicFadePacket_guess fade_guess;
            int index_guess;
            pSpawn_0008_guess->SetHideMode_guess(0);
            fade_guess.spawnId_guess = (short)pSpawn_0008_guess->spawnId_0258_guess;
            fade_guess.type_guess = 3;
            fade_guess.value_guess = pSpawn_0008_guess->hideMode_0250_guess;
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0xc, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x5e, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x1c, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x1d, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x13a, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x13b, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            ((Wrap411F2F_guess*)&g_magicCharData_guess->magic_guess)->RemovePCAffect_guess(
                (int)g_magicCharData_guess->magic_guess.FindBuffWithEffect_guess(0x13c, &index_guess));
            if (index_guess != -1) {
                g_magicCharData_guess->magic_guess.NotifyPCAffectChange_guess(index_guess, 1);
            }
            EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_SpawnAppearance, &fade_guess, 8, 1);
            pSpawn_0008_guess->UpdatePlayerVisibility_guess();
        }
        g_magicMessageRouter_guess->CancelSneakHide();
    }
    if (item_guess != 0) {
        GetTable_guess()->field114_guess = 0;
        if (item_guess->GetItemClass_guess() != 0) {
            return 0;
        }
        // Item click: the item's level (0x88), worn-only (type 4, 0xB3) and equippable (type 5, 0xB5) rules,
        // its charges (0xB6), and bind effects in zones that forbid binding (0x69). `altIndex_guess` picks
        // the item's second effect.
        if (item_guess->GetItemType_guess() == 0x14) {
            return 0;
        }
        if (pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess != -1) {
            if (IsValidSpellIndex_guess(pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess) == 0) {
                return 0;
            }
            if (IsBardSong_guess((MagicPredicateObject_guess*)g_magicLookup_guess->GetSpell_guess(
                                    pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess),
                                ResolveResult_guess()->class_119c_guess) == 0) {
                return 0;
            }
        }
        if (altIndex_guess == 0 && pSpawn_0008_guess->type_0244_guess == 0) {
            int level_guess = ResolveResult_guess()->level_11a4_guess;
            if (item_guess->FUN_005e1140_guess(0) > level_guess) {
                token_string_to_client_guess(this, 0x88, 0xd, 0);
                return 0;
            }
            switch (item_guess->FUN_005e11a0_guess(0)) {
            case 4: {
                int found_guess = 0;
                for (int slotIndex_guess = 0; slotIndex_guess <= InvSlot_Ammo; ++slotIndex_guess) {
                    if (item_guess == GetTable_guess()->GetFirst_guess(slotIndex_guess)) {
                        found_guess = 1;
                    }
                }
                if (found_guess == 0) {
                    token_string_to_client_guess(this, 0xb3, 0xd, 0);
                    return 0;
                }
                break;
            }
            case 5:
                if (CanUseItem_guess(item_guess, 1) == 0) {
                    token_string_to_client_guess(this, 0xb5, 0xd, 0);
                    return 0;
                }
                break;
            }
        }
        if (IsValidSpellIndex_guess(item_guess->GetCount_guess(altIndex_guess)) == 0) {
            return 0;
        }
        spell_guess = g_magicLookup_guess->GetSpell_guess(item_guess->GetCount_guess(altIndex_guess));
        if (spell_guess == 0) {
            return 0;
        }
        castId_guess = item_guess->GetCount_guess(altIndex_guess);
        item_guess->FUN_005e1140_guess(altIndex_guess);
        if (altIndex_guess == 0 && item_guess->field58_guess == 0) {
            token_string_to_client_guess(this, 0xb6, 0x111, 0);
            return 0;
        }
        if (spell_guess->FindAffectSlot_guess(0x19) != 0 &&
            g_magicZoneCheck_guess->FUN_005f6c00_guess(GetTable_guess()->field100_guess) != 0) {
            token_string_to_client_guess(this, 0x69, 0x121, 0);
            return 0;
        }
    } else {
        if (pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess != -1 &&
            ResolveResult_guess()->class_119c_guess != Class_Bard) {
            // Gem cast: only a bard may start one while another is running (0x309A). Gems 0-8 cast the
            // memorized spell, slots 9-11 `spellId_guess` directly; 0x309B when the level is too low for the
            // class.
            pEverQuest->dsp_chat(pStringTable->getString(0x309a, 0), 0x121, 1);
            return 0;
        }
        if (slot_guess > 0xb) {
            return 0;
        }
        if (slot_guess <= 8) {
            castId_guess = ((CharacterMagicSystem_guess*)GetTable_guess())->GetMemorizedSpell_guess(slot_guess);
        } else {
            castId_guess = spellId_guess;
        }
        spell_guess = g_magicLookup_guess->GetSpell_guess(castId_guess);
        if (spell_guess == 0) {
            return 0;
        }
        if (slot_guess <= 8) {
            unsigned char class_guess = ResolveResult_guess()->class_119c_guess;
            int level_guess = ResolveResult_guess()->level_11a4_guess;
            if (spell_guess->CheckMode_guess(class_guess) > level_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(0x309b, 0), 0x121, 1);
                return 0;
            }
        }
        // Summon-item spells (SPA 32, except 2772) wait while the cursor queue holds items (0xC79).
        if (spell_guess->FindAffectSlot_guess(0x20) != 0 && spell_guess->id_guess != 0xad4 &&
            g_magicCharData_guess->fieldD5C_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0xc79, 0), 0xf, 1);
            return 0;
        }
        if (pSpawn_0008_guess != 0 && GetTable_guess()->Slot0b_guess() != 0) {
            GetTable_guess()->service_guess.GetCharInfo2();
        } else {
            GetTable_guess()->service_guess.GetCharInfo2();
            if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
                GetTable_guess()->field114_guess = 0;
            }
        }
    }
    // TemporaryPets (SPA 152) with yourself as target, unless the spell is self-only: "You must first select
    // a target" (214, or 5825 for an ability).
    if (spell_guess->FindAffectSlot_guess(0x98) != 0 && spell_guess->field180_guess != 6 &&
        g_magicCurrent_guess == pSpawn_0008_guess) {
        if (spell_guess->field1C4_guess != 0) {
            token_string_to_client_guess(this, 0x16c1, 0x121, 0);
        } else {
            token_string_to_client_guess(this, 0xd6, 0x121, 0);
        }
        return 0;
    }
    // Spells 1502 and 2716 would take +0x284 to zero or below: 0x107.
    if ((castId_guess == 0x5de || castId_guess == 0xa9c) &&
        pSpawn_0008_guess->hpMax_0284_guess + spell_guess->values30_guess[0] <= 0) {
        token_string_to_client_guess(this, 0x107, 0x121, 0);
        return 0;
    }
    if (spell_guess->field180_guess == 0xe || spell_guess->field180_guess == 0x26) {
        g_magicCurrent_guess = (MagicStateA_guess*)GetTransformed_guess();
    }
    if (((MagicMode_guess*)spell_guess)->IsAccepted_guess() != 0 && pSpawn_0008_guess != 0 &&
        g_magicCurrent_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
        if (spell_guess->field17d != 1 || spell_guess->FindAffectSlot_guess(0x1b) != 0) {
            if (g_magicCurrent_guess == 0 ||
                // Hostile targeted spells (and CancelMagic) need line of sight: string 108.
                CastRay(pSpawn_0008_guess, g_magicCurrent_guess->position_guess.y_guess,
                                   g_magicCurrent_guess->position_guess.x_guess,
                                   g_magicCurrent_guess->field38_guess) == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x6c, 0), 0x121, 1);
                return 0;
            }
        }
    }
    if (pSpawn_0008_guess == g_magicWorld_guess && pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
        // SummonHorse (SPA 113) needs three times the player's height of headroom (0xFE3).
        spell_guess->FindAffectSlot_guess(0x71) != 0 &&
        pSpawn_0008_guess->pActorInfo_01a8_guess->field1B0_guess - pSpawn_0008_guess->pActorInfo_01a8_guess->field48_guess <
            pSpawn_0008_guess->heightOffset_0238_guess * 3.0f) {
        pEverQuest->dsp_chat(pStringTable->getString(0xfe3, 0), 0x121, 1);
        return 0;
    }
    // Server mode 4 (0x00900478, deity-team PvP): a beneficial single-target spell (type 5) without
    // CancelMagic (SPA 27) on another player is refused (string 210) when NotOnSameDeity_guess puts the two
    // deities in different alliances.
    if (g_modeCode_guess == 4 && pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0 &&
        g_magicCurrent_guess != 0 && g_magicCurrent_guess->type_0244_guess == 0 &&
        spell_guess->field17d == 1 && pSpawn_0008_guess->gm_0256_guess == 0 &&
        spell_guess->field180_guess == 5 && spell_guess->FindAffectSlot_guess(0x1b) == 0 &&
        g_magicCurrent_guess->NotOnSameDeity_guess(pSpawn_0008_guess, spell_guess) != 0) {
        token_string_to_client_guess(this, 0xd2, 0x121, 0);
        return 0;
    }
    if (IsBardSong_guess((MagicPredicateObject_guess*)spell_guess,
                        ResolveResult_guess()->class_119c_guess) != 0) {
        // 0x0040DB0B is the bard-song test: class 8, not a combat ability (+0x1C4 clear) and a real spell
        // level for bards. Songs are refused only while feigning death (stand state 115) or dead (120),
        // string 212; everything else needs StandState 100 (string 213).
        if (GetTable_guess()->field104_guess == 0x73 || GetTable_guess()->field104_guess == 0x78) {
            token_string_to_client_guess(this, 0xd4, 0x121, 0);
            return 0;
        }
    } else if (spell_guess->field1fc == 0 && GetTable_guess()->field104_guess != 100) {
        token_string_to_client_guess(this, 0xd5, 0x121, 0);
        return 0;
    }
    // +0x1F8 restricts the target: 1 players only (0x16E8), 2 NPCs only (0x16F5).
    int targetType_guess = spell_guess->field1F8_guess;
    if (targetType_guess != 0) {
        if (targetType_guess == 1 && g_magicCurrent_guess != 0 &&
            g_magicCurrent_guess->type_0244_guess != 0) {
            token_string_to_client_guess(this, 0x16e8, 0x121, 0);
            return 0;
        }
        if (targetType_guess == 2 && g_magicCurrent_guess != 0 &&
            g_magicCurrent_guess->type_0244_guess != 1) {
            token_string_to_client_guess(this, 0x16f5, 0x121, 0);
            return 0;
        }
    }
    MagicStateA_guess* player_guess = pSpawn_0008_guess;
    if (player_guess == 0) {
        return 0;
    }
    if (GetTable_guess()->flag10C_guess == 0 && item_guess == 0) {
        // Mana (+0x2C) unless HPToMana (SPA 324) pays for it (199), then endurance (+0x1BC, 0x16AD).
        int mana_guess = spell_guess->field2C_guess;
        if (TotalSpellAffects_guess(0x144, true, 0, 1) == 0 && Cur_Mana_guess() < mana_guess) {
            token_string_to_client_guess(this, 199, 0x121, 0);
            return 0;
        }
        int endurance_guess = spell_guess->field1BC_guess;
        if (endurance_guess != 0 && Cur_Endurance_guess() < endurance_guess) {
            token_string_to_client_guess(this, 0x16ad, 0x121, 0);
            return 0;
        }
    }
    // Range and target checks by target type (+0x180, EQEmu's ST_ numbering). NPC casters get 1.2 times the
    // range (spell 982 unlimited); players get range plus focus, at most 5 times. String 100 is out of range.
    float range_guess;
    switch (spell_guess->field180_guess) {
    case 0:
    case 1:
        if (spell_guess->field188_guess == 3) {
            int rangeMod2_guess = 0;
            if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 1) {
                range_guess = spell_guess->range_guess * 1.2f;
                if (castId_guess == 0x3d6) {
                    range_guess = 10000.0f;
                }
            } else {
                range_guess = (float)GetFocusRangeModifier_guess(spell_guess, &rangeMod2_guess) +
                              spell_guess->range_guess;
                if (range_guess > spell_guess->range_guess * 5.0f) {
                    range_guess = spell_guess->range_guess * 5.0f;
                }
            }
            if (g_magicSession_guess->PlayerDistance_guess(g_magicCurrent_guess, player_guess,
                                                         0.0f) > range_guess) {
                token_string_to_client_guess(this, 100, 0x121, 0);
                return 0;
            }
        }
        break;
    case 6:
        if (spell_guess->FindAffectSlot_guess(0x5b) != 0) {
            if (pSpawn_0008_guess == 0 || pSpawn_0008_guess->type_0244_guess != 0) {
                return 0;
            }
            if (g_magicCurrent_guess != 0 && g_magicCurrent_guess->type_0244_guess == 0) {
                MagicObject_guess* owner_guess = g_magicCurrent_guess->GetPcClient_guess();
                if (pSpawn_0008_guess->gm_0256_guess != 0) {
                    break;
                }
                if (g_magicCurrent_guess->pCharInfo_0218_guess == 0) {
                    break;
                }
                if (owner_guess->IsAGroupMember_guess(
                        ((MagicNameContainer_guess*)GetTable_guess())->name_guess) != 0) {
                    break;
                }
            }
            token_string_to_client_guess(this, 0xd7, 0x121, 0);
            return 0;
        }
        break;
    case 7:
        if (item_guess != 0) {
            return 0;
        }
        // Target type 7 works on the cursor item (slot 30): 0xE9 when there is none.
        if (ResolveResult_guess()->values10_guess[30] == 0) {
            token_string_to_client_guess(this, 0xe9, 0x121, 0);
            return 0;
        }
        break;
    case 8:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1c: {
        if (g_magicCurrent_guess == 0) {
            token_string_to_client_guess(this, 0xd6, 0x121, 0);
            return 0;
        }
        if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 1) {
            range_guess = spell_guess->range_guess * 1.2f;
            if (castId_guess == 0x3d6) {
                range_guess = 10000.0f;
            }
        } else {
            range_guess = (float)GetFocusRangeModifier_guess(spell_guess, &rangeMod_guess) +
                          spell_guess->range_guess;
            if (range_guess > spell_guess->range_guess * 5.0f) {
                range_guess = spell_guess->range_guess * 5.0f;
            }
        }
        float targetZ_guess = g_magicCurrent_guess->field38_guess;
        float targetHeight_guess = g_magicCurrent_guess->heightOffset_0238_guess;
        float casterZ_guess = pSpawn_0008_guess->field38_guess;
        float casterHeight_guess = pSpawn_0008_guess->heightOffset_0238_guess;
        int tooHigh_guess = 0;
        // Targeted AE types (8, 21-23, 28) also refuse a target 40 or more units above or below.
        if (fabs((targetZ_guess - targetHeight_guess) - (casterZ_guess - casterHeight_guess)) >
            39.99f) {
            tooHigh_guess = 1;
        }
        if (g_magicSession_guess->PlayerDistance_guess(g_magicCurrent_guess, player_guess, 0.0f) >
                range_guess ||
            tooHigh_guess != 0) {
            token_string_to_client_guess(this, 100, 0x121, 0);
            return 0;
        }
        break;
    }
    case 0xe:
    case 0x26:
        g_magicCurrent_guess = (MagicStateA_guess*)GetTransformed_guess();
    case 5:
    case 9:
    case 0xa:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x14:
    case 0x1b:
    case 0x22:
    case 0x23:
    case 0x27:
    case 0x2b:
        if (spell_guess->field180_guess == 0x26 && g_magicCurrent_guess != 0 &&
            (g_magicCurrent_guess->type_0244_guess != 1 ||
             g_magicCurrent_guess->isPet_01b5_guess == 0)) {
            g_magicCurrent_guess = 0;
        }
        if (item_guess != 0 && item_guess->GetItemClass_guess() == 0 &&
            item_guess->GetItemType_guess() == 0x15 && item_guess->GetCount_guess(0) >= 2) {
            g_magicCurrent_guess = g_magicWorld_guess;
        }
        if (g_magicCurrent_guess == 0) {
            if (spell_guess->field1C4_guess != 0) {
                token_string_to_client_guess(this, 0x16c1, 0x121, 0);
            } else {
                token_string_to_client_guess(this, 0xd6, 0x121, 0);
            }
            return 0;
        }
        if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 1) {
            range_guess = spell_guess->range_guess * 1.2f;
            if (range_guess < 500.0f) {
                range_guess = 500.0f;
            }
            if (castId_guess == 0x3d6) {
                range_guess = 10000.0f;
            }
        } else {
            range_guess = (float)GetFocusRangeModifier_guess(spell_guess, &rangeMod_guess) +
                          spell_guess->range_guess;
            if (range_guess > spell_guess->range_guess * 5.0f) {
                range_guess = spell_guess->range_guess * 5.0f;
            }
        }
        if (g_magicSession_guess->PlayerDistance_guess(g_magicCurrent_guess, player_guess, 0.0f) >
            range_guess) {
            token_string_to_client_guess(this, 100, 0x121, 0);
            return 0;
        }
        switch (spell_guess->field180_guess) {
        case 9:
        case 0x17:
            // Body-type rules apply to player casters: 9/23 animal (body 21), 10/21 undead (3, 8, 12), 11/22
            // summoned (24, 27, 8, 28), 16 plant (25), 17-19, 27/28, 34 and 35 other bodies; 15 needs a
            // corpse, 13/20 (taps) can't target yourself, 39 players only.
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 0x15) {
                token_string_to_client_guess(this, 0xde, 0x121, 0);
                return 0;
            }
            break;
        case 0xa:
        case 0x15:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 3 &&
                g_magicCurrent_guess->bodyType_0270_guess != 8 &&
                g_magicCurrent_guess->bodyType_0270_guess != 0xc) {
                token_string_to_client_guess(this, 0xdb, 0x121, 0);
                return 0;
            }
            break;
        case 0xb:
        case 0x16:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 0x18 &&
                g_magicCurrent_guess->bodyType_0270_guess != 0x1b &&
                g_magicCurrent_guess->bodyType_0270_guess != 8 &&
                g_magicCurrent_guess->bodyType_0270_guess != 0x1c) {
                token_string_to_client_guess(this, 0xd8, 0x121, 0);
                return 0;
            }
            break;
        case 0xc:
            if (g_magicCurrent_guess->FUN_0047a018_guess() == 0) {
                token_string_to_client_guess(this, 0xda, 0x121, 0);
                return 0;
            }
            break;
        case 0xe:
            g_magicCurrent_guess = (MagicStateA_guess*)GetTransformed_guess();
            if (g_magicCurrent_guess == 0) {
                token_string_to_client_guess(this, 0xd9, 0x121, 0);
                return 0;
            }
            break;
        case 0x26:
            g_magicCurrent_guess = (MagicStateA_guess*)GetTransformed_guess();
            if (g_magicCurrent_guess != 0 && (g_magicCurrent_guess->type_0244_guess != 1 ||
                                              g_magicCurrent_guess->isPet_01b5_guess == 0)) {
                g_magicCurrent_guess = 0;
            }
            if (g_magicCurrent_guess == 0) {
                token_string_to_client_guess(this, 0xd9, 0x121, 0);
                return 0;
            }
            break;
        case 0x27:
            if (g_magicCurrent_guess->type_0244_guess != 0) {
                token_string_to_client_guess(this, 0x16e8, 0x121, 0);
                return 0;
            }
            break;
        case 0xf:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->type_0244_guess < 2) {
                token_string_to_client_guess(this, 0xdd, 0x121, 0);
                return 0;
            }
            break;
        case 0x10:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 0x19) {
                token_string_to_client_guess(this, 0xdc, 0x121, 0);
                return 0;
            }
            break;
        case 0x11:
            if (g_magicCurrent_guess->bodyType_0270_guess != 9) {
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return 0;
                }
                token_string_to_client_guess(this, 0xe1, 0x121, 0);
                return 0;
            }
            break;
        case 0x12:
            if (g_magicCurrent_guess->bodyType_0270_guess != 0x1e) {
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return 0;
                }
                token_string_to_client_guess(this, 0xe2, 0x121, 0);
                return 0;
            }
            break;
        case 0x13:
            if (g_magicCurrent_guess->bodyType_0270_guess != 0xa) {
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return 0;
                }
                token_string_to_client_guess(this, 0xe3, 0x121, 0);
                return 0;
            }
            break;
        case 0x23:
            if (g_magicCurrent_guess->bodyType_0270_guess != 0x22) {
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return 0;
                }
                token_string_to_client_guess(this, 0x23ff, 0x121, 0);
                return 0;
            }
            break;
        case 0x1b:
        case 0x1c:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 0x16) {
                token_string_to_client_guess(this, 0xdf, 0x121, 0);
                return 0;
            }
            break;
        case 0x22:
            if (pSpawn_0008_guess->type_0244_guess == 0 && g_magicCurrent_guess->bodyType_0270_guess != 0x21) {
                token_string_to_client_guess(this, 0x23ba, 0x121, 0);
                return 0;
            }
        case 0xd:
        case 0x14:
            if (g_magicCurrent_guess == pSpawn_0008_guess) {
                token_string_to_client_guess(this, 0xe0, 0x121, 0);
                return 0;
            }
            break;
        case 0x2b:
            if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0 &&
                GetTable_guess()->GetObject_guess()->IsAGroupMember_guess(
                    g_magicCurrent_guess->name120_guess) == 0) {
                if (g_magicCurrent_guess->type_0244_guess == 1 &&
                    g_magicCurrent_guess->masterId_025c_guess > 0) {
                    MagicStateA_guess* owner_guess =
                        (MagicStateA_guess*)Transform_guess(g_magicCurrent_guess->masterId_025c_guess);
                    if (owner_guess != 0 && owner_guess->type_0244_guess == 0 &&
                        GetTable_guess()->GetObject_guess()->IsAGroupMember_guess(
                            owner_guess->name120_guess) != 0) {
                        break;
                    }
                }
                token_string_to_client_guess(this, 0xc4, 0x121, 0);
                return 0;
            }
            break;
        }
        break;
    }
    if (spell_guess->field194_guess != 0 && g_magicCurrent_guess == pSpawn_0008_guess) {
        token_string_to_client_guess(this, 0xd2, 0x121, 0);
        return 0;
    }
    if (GetTable_guess()->flag10C_guess == 0 && item_guess == 0 && g_magicSendFlag_guess != 0 &&
        CheckCast_guess(slot_guess, (MagicPredicateObject_guess*)spell_guess) != 0) {
        return 0;
    }
    if (item_guess == 0) {
        // Cast time: base (+0x14) plus focus and cost adjustments, never under half the base. The begin-cast
        // is shown locally through the OP_BeginCast handler; casts over 100 ms are parked in the actor
        // (spell, gem, item) and finish later.
        unsigned int baseTime_guess = spell_guess->field14_guess;
        unsigned int castTime_guess = baseTime_guess;
        int focus_guess = 0;
        int costAdjust_guess = GetAACastingTimeModifier((MagicSpell_guess*)spell_guess);
        int adjust_guess = GetFocusCastingTimeModifier(spell_guess, &focus_guess) + costAdjust_guess;
        if (adjust_guess <= 0 && (unsigned int)-adjust_guess >= castTime_guess) {
            castTime_guess = 0;
        } else {
            castTime_guess += adjust_guess;
        }
        if (castTime_guess < baseTime_guess / 2) {
            castTime_guess = baseTime_guess / 2;
        }
        MagicCastTimePacket_guess begin_guess;
        begin_guess.spawnId_guess = (short)player_guess->spawnId_0258_guess;
        begin_guess.spellId_guess = (short)castId_guess;
        begin_guess.time_guess = castTime_guess;
        if (g_magicSendFlag_guess != 0 || g_magicSendCount_guess != 0) {
            g_magicMessageRouter_guess->StartCasting_guess(&begin_guess);
        }
        if (castTime_guess > 100) {
            player_guess->pActorInfo_01a8_guess->field1048_guess = 0;
            player_guess->pActorInfo_01a8_guess->ref1050_guess.Clear_guess();
            player_guess->pActorInfo_01a8_guess->field104C_guess = 0;
            player_guess->pActorInfo_01a8_guess->fieldD8_guess =
                g_magicSession_guess->field148_guess + castTime_guess;
            player_guess->pActorInfo_01a8_guess->fieldF98_guess = castId_guess;
            player_guess->pActorInfo_01a8_guess->fieldF9C_guess = slot_guess;
            player_guess->pActorInfo_01a8_guess->fieldFA0_guess = altIndex_guess;
            g_magicLastTarget_guess = (unsigned char)spell_guess->field17d;
        }
    // Item casts use the item's own cast time; instant items only start their recast timer.
    } else if (item_guess->FUN_005e0d70_guess() > 100 && pSpawn_0008_guess->type_0244_guess != 1) {
        int itemTime_guess = item_guess->FUN_005e0d70_guess();
        pSpawn_0008_guess->pActorInfo_01a8_guess->field104C_guess = 1;
        player_guess->pActorInfo_01a8_guess->fieldD8_guess =
            g_magicSession_guess->field148_guess + itemTime_guess;
        player_guess->pActorInfo_01a8_guess->fieldF98_guess = castId_guess;
        player_guess->pActorInfo_01a8_guess->fieldF9C_guess = slot_guess;
        player_guess->pActorInfo_01a8_guess->field1048_guess = (int)*itemRef_guess;
        player_guess->pActorInfo_01a8_guess->ref1050_guess = ref_guess;
        player_guess->pActorInfo_01a8_guess->fieldFA0_guess = altIndex_guess;
        g_magicLastTarget_guess = (unsigned char)spell_guess->field17d;
        MagicCastTimePacket_guess begin_guess;
        begin_guess.spawnId_guess = (short)player_guess->spawnId_0258_guess;
        begin_guess.spellId_guess = (short)castId_guess;
        begin_guess.time_guess = itemTime_guess;
        if (g_magicSendFlag_guess != 0 || g_magicSendCount_guess != 0) {
            g_magicMessageRouter_guess->StartCasting_guess(&begin_guess);
        }
    } else if (altIndex_guess == 0 && item_guess->GetRecastTime_guess() > 0 &&
               pSpawn_0008_guess->type_0244_guess == 0) {
        MagicTable_guess* table_guess = GetTable_guess();
        table_guess->GetObject_guess()->SetItemRecastTimer_guess(
            item_guess, item_guess->GetRecastTime_guess(), item_guess->FUN_005e05f0_guess());
    }
    if (pSpawn_0008_guess != 0) {
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFF8_guess = pSpawn_0008_guess->position_guess.y_guess;
        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldFFC_guess = pSpawn_0008_guess->position_guess.x_guess;
    }
    // OP_CastSpell (0x304B, 0x14 bytes: gem, spell, inventory slot, value, target id). Gems 0-8 and slot 9
    // lock for 10 s until the server answers; non-song casts take a pending-request count (0x009248D0/D4).
    if (g_magicSendFlag_guess == 0 && g_magicSendCount_guess == 0) {
        MagicCastPacket_guess cast_guess;
        cast_guess.slot_guess = slot_guess;
        cast_guess.spellId_guess = castId_guess;
        cast_guess.ref_guess = ref_guess.GetSlotId_guess();
        cast_guess.value_guess =
            ((CharacterMagicSystem_guess*)g_magicLookup_guess)->GetValue_guess(castId_guess);
        if (g_magicCurrent_guess == 0) {
            cast_guess.targetId_guess = 0;
        } else {
            cast_guess.targetId_guess = g_magicCurrent_guess->spawnId_0258_guess;
        }
        if (slot_guess <= 8) {
            pSpawn_0008_guess->pActorInfo_01a8_guess->fieldE8_guess[slot_guess] =
                g_magicSession_guess->field148_guess + 10000;
            pSpawn_0008_guess->pActorInfo_01a8_guess->field110_guess =
                g_magicSession_guess->field148_guess + 10000;
        }
        if (slot_guess == 9) {
            pSpawn_0008_guess->pActorInfo_01a8_guess->field10C_guess =
                g_magicSession_guess->field148_guess + 10000;
        }
        EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_CastSpell, &cast_guess, 0x14, 1);
        if (IsBardSong_guess((MagicPredicateObject_guess*)spell_guess,
                            ResolveResult_guess()->class_119c_guess) == 0) {
            ++g_magicCountA_guess;
            ++g_magicCountB_guess;
        }
    }
    return 1;
}

// Re-applies the side effects of each active buff on our own spawn (called with 1 when our EQPlayer is
// built, 0x004850A0, and with 0 after an illusion change, 0x00485873): movement speed and root, the
// blind/confuse flag, levitate, magnify vision, then the root or speed total. Mode 2 drops buffs with Eye
// of Zomm, Mez, Illusion, Bind Sight, Spin Target or effect 156, any other nonzero mode also Charm and
// Fear; illusions among them are recast, not dropped.
// FUNCTION: TITANIUM 0x0041377F
// @early-stop: budget, structural ndiff=66
void CharacterMagicSystem_guess::ReapplyBuffEffects_guess(int mode_guess) {
    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0 &&
        pSpawn_0008_guess->pActorInfo_01a8_guess != 0 && g_magicSendFlag_guess == 0) {
        ApplyMovementModifier_guess(0);
        for (int entryIndex_guess = 0;
             entryIndex_guess < (unsigned char)GetMaxBuffs_guess(this); ++entryIndex_guess) {
                MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
                if (entry_guess->active_guess != 0) {
                    int spellId_guess = entry_guess->id_guess;
                    if (IsValidSpellIndex_guess(spellId_guess) != 0) {
                        MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
                        if (spell_guess != 0) {
                            if (mode_guess != 0) {
                                char affected_guess = spell_guess->FindAffectSlot_guess(0x43);
                                // In mode 2 a matched buff skips the re-apply steps below; in the other
                                // modes a recast illusion still gets them.
                                if (mode_guess == 2) {
                                    if (affected_guess != 0 ||
                                        spell_guess->FindAffectSlot_guess(0x1f) != 0 ||
                                        spell_guess->FindAffectSlot_guess(0x3a) != 0 ||
                                        spell_guess->FindAffectSlot_guess(0x49) != 0 ||
                                        spell_guess->FindAffectSlot_guess(0x40) != 0 ||
                                        spell_guess->FindAffectSlot_guess(0x9c) != 0) {
                                        if (spell_guess->IsIllusion_guess() != 0) {
                                            char scale_guess =
                                                spell_guess->FindAffectSlot_guess(0x3a);
                                            unsigned int level_guess = ResolveResult_guess()->level_11a4_guess;
                                            int amount_guess = CalcAffectChange_guess(
                                                spell_guess, (unsigned char)level_guess,
                                                (int)scale_guess - 1, 0);
                                            ActivateEffect_guess(
                                                (MagicCaster_guess*)spell_guess, spellId_guess,
                                                amount_guess, (int)entry_guess, 0);
                                        } else {
                                            ((Wrap411F2F_guess*)this)->RemovePCAffect_guess(
                                                (int)entry_guess);
                                        }
                                        continue;
                                    }
                                } else if (affected_guess != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x1f) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x3a) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x16) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x17) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x49) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x40) != 0 ||
                                           spell_guess->FindAffectSlot_guess(0x9c) != 0) {
                                    if (spell_guess->IsIllusion_guess() == 0) {
                                        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess(
                                            (int)entry_guess);
                                        continue;
                                    } else {
                                        char scale_guess =
                                            spell_guess->FindAffectSlot_guess(0x3a);
                                        unsigned int level_guess =
                                            ResolveResult_guess()->level_11a4_guess;
                                        int amount_guess = CalcAffectChange_guess(
                                            spell_guess, (unsigned char)level_guess,
                                            (int)scale_guess - 1, 0);
                                        ActivateEffect_guess(
                                            (MagicCaster_guess*)spell_guess, spellId_guess,
                                            amount_guess, (int)entry_guess, 0);
                                    }
                                }
                            }
                            char scale_guess = spell_guess->FindAffectSlot_guess(3);
                            if (scale_guess != 0) {
                                int amount_guess = CalcAffectChange_guess(
                                    spell_guess, entry_guess->casterLevel_0001_guess,
                                    (int)scale_guess - 1, 0);
                                ApplyMovementModifier_guess(amount_guess);
                            }
                            scale_guess = spell_guess->FindAffectSlot_guess(99);
                            if (scale_guess != 0) {
                                int amount_guess = CalcAffectChange_guess(
                                    spell_guess, entry_guess->casterLevel_0001_guess,
                                    (int)scale_guess - 1, 0);
                                ApplyMovementModifier_guess(amount_guess);
                            }
                            if (spell_guess->FindAffectSlot_guess(0x22) != 0 ||
                                spell_guess->FindAffectSlot_guess(0x14) != 0) {
                                pSpawn_0008_guess->pActorInfo_01a8_guess->field154_guess = 1;
                            }
                            if (spell_guess->FindAffectSlot_guess(0x39) != 0) {
                                Refresh_guess();
                            }
                            scale_guess = spell_guess->FindAffectSlot_guess(0x57);
                            if (scale_guess != 0) {
                                int amount_guess = CalcAffectChange_guess(
                                    spell_guess, entry_guess->casterLevel_0001_guess,
                                    (int)scale_guess - 1, 0);
                                g_magicSession_guess->FUN_00440f51_guess(amount_guess);
                            }
                            if (spell_guess->FindAffectSlot_guess(0x41) != 0) {
                                ResolveResult_guess()->values1100_guess[6] = 0;
                            }
                            if (spell_guess->FindAffectSlot_guess(0x42) != 0) {
                                ResolveResult_guess()->values1100_guess[13] = 0;
                            }
                        }
                    }
                }
        }
        int remaining_guess = TotalSpellAffects_guess(99, true, 0, 1);
        if (remaining_guess >= 0) {
            remaining_guess = TotalSpellAffects_guess(3, true, 0, 1);
        }
        ApplyMovementModifier_guess(remaining_guess);
        fieldC_guess = 1;
    }
}

// Per-tick buff processing: ticks durations, fades expired buffs with their messages (12482 about to fall,
// 12483 about to look like yourself), and names eye and mount actors ("Eye_of_%s", "%s`s_Mount").
// FUNCTION: TITANIUM 0x00413AE4
// @early-stop: budget, diff ndiff=403
int CharacterMagicSystem_guess::ProcessAffects_guess() {
    int total_guess = 0;
    int entryIndex_guess = 0;
    char removeEntry_guess = 0;
    char eyeNameSource_guess[64];
    char eyeName_guess[64];
    char mountNameSource_guess[64];
    char mountName_guess[64];

    if ((unsigned char)GetMaxBuffs_guess(this) != 0) {
        do {
            MagicEntryProbe_guess* entry_guess = GetBuff_guess(entryIndex_guess);
            // Every buff slot in use (state above 1). The spell id is clamped to 9999 for the spell
            // table.
            if ((unsigned char)entry_guess->active_guess > 1) {
                MagicCheck_guess* spell_guess;
                if (IsValidSpellIndex_guess(entry_guess->id_guess) != 0) {
                    int cappedId_guess = entry_guess->id_guess;
                    if (cappedId_guess > 9999) {
                        cappedId_guess = 9999;
                    }
                    spell_guess = g_magicLookup_guess->GetSpell_guess(cappedId_guess);
                } else {
                    spell_guess = 0;
                }

                // The buff fades this pass if its ticks left (+0x08) were already 0 (the decrement
                // comes after). -1 marks a permanent buff, which is still removed unless its
                // duration formula (+0x20) is 50.
                removeEntry_guess = (char)(entry_guess->unknown08_guess == 0);
                if (entry_guess->unknown08_guess == -1 && spell_guess != 0 &&
                    spell_guess->field20 != 0x32) {
                    removeEntry_guess = 1;
                }

                if (FUN_00464e9c_guess(g_magicWorld_guess->field204_guess, (int)this,
                                      spell_guess) == 0 &&
                    entry_guess->unknown08_guess != -1 && entry_guess->unknown08_guess != 0) {
                    // One tick off the duration, except for spells the check at 0x00464E9C accepts
                    // (their buffs do not run down).
                    --entry_guess->unknown08_guess;
                }

                if (spell_guess != 0) {
                    // The spell's 12 effect slots (SPA at +0x120). HP effects only set
                    // applyGeneric_guess and are summed into total_guess; the other per-tick effects
                    // act here.
                    for (int effectIndex_guess = 0; effectIndex_guess < 12; ++effectIndex_guess) {
                        if ((unsigned int)effectIndex_guess >= 12) {
                            __debugbreak();
                        }
                        int effect_guess = spell_guess->values_120[effectIndex_guess];
                        if (service_C4_guess.HasEffect_guess(effect_guess, 0) != 0) {
                            fieldC8_guess = 0;
                        }

                        int applyGeneric_guess = 0;
                        if (effect_guess < 100) {
                            if (effect_guess != 99) {
                                if (effect_guess == 0) {
                                    applyGeneric_guess = 1;
                                } else if (effect_guess == 3) {
                                    MagicStateB_guess* stateData_guess = pSpawn_0008_guess->pActorInfo_01a8_guess;
                                    if (stateData_guess->fieldC8_guess <= 0.0f) {
                                        if ((unsigned int)effectIndex_guess >= 12) {
                                            __debugbreak();
                                        }
                                        if (spell_guess->values60_guess[effectIndex_guess] != 1 &&
                                            MagicIdAllowed_guess(entry_guess->id_guess) == 0) {
                                            continue;
                                        }
                                    } else {
                                        continue;
                                    }
                                // CurrentMana (15) per tick, not for a Bard. A drain on a spell
                                // flagged +0x17D == 1 ends the buff once mana is below the drain; an
                                // entry in state 4 has its sign flipped.
                                } else if (effect_guess == 15) {
                                    MagicResult_guess* result_guess =
                                        ((MagicResolveContainer_guess*)GetTable_guess())->list_guess.GetCharInfo2();
                                    if (result_guess->class_119c_guess != Class_Bard) {
                                        int amount_guess = CalcAffectChange_guess(
                                            spell_guess, entry_guess->casterLevel_0001_guess,
                                            effectIndex_guess, entry_guess);
                                        if (amount_guess < 0 && spell_guess->field17d == 1) {
                                            int current_guess = Cur_Mana_guess();
                                            int normalized_guess = NormalizeMagicAmount_guess(amount_guess);
                                            if (current_guess < normalized_guess) {
                                                ((Wrap411F2F_guess*)this)->RemovePCAffect_guess(
                                                    (int)entry_guess);
                                            }
                                        }
                                        if (entry_guess->active_guess == 4) {
                                            amount_guess = -amount_guess;
                                        }
                                        ((CharacterMagicSystem_guess*)GetTable_guess())->AddField11A8_guess(
                                            amount_guess);
                                        Cur_Mana_guess();
                                    }
                                // Levitate (57), Illusion (58) and SPA 156 warn in their last tick
                                // (fewer than 2 left) with strings 0x30C2 / 0x30C3; Levitate stays
                                // silent when its spell's mode-8 value is not 0xFF.
                                } else if (effect_guess == 0x39) {
                                    if (entry_guess->unknown08_guess != -1 &&
                                        entry_guess->unknown08_guess < 2) {
                                        if (IsValidSpellIndex_guess(entry_guess->id_guess) != 0) {
                                            if (g_magicLookup_guess->GetSpell_guess(
                                                    entry_guess->id_guess)->CheckMode_guess(8) != 0xff) {
                                                continue;
                                            }
                                        }
                                        g_magicMessageRouter_guess->dsp_chat(
                                            pStringTable->getString(0x30c2, 0),
                                            0x121, 1);
                                    }
                                } else if (effect_guess == 0x3a) {
                                    if (entry_guess->unknown08_guess != -1 &&
                                        entry_guess->unknown08_guess < 2) {
                                        g_magicMessageRouter_guess->dsp_chat(
                                            pStringTable->getString(0x30c3, 0),
                                            0x121, 1);
                                    }
                                // EyeOfZomm (67): find the spawn "Eye_of_<name>", stop the previous
                                // linked spawn and view through it.
                                } else if (effect_guess == 0x43) {
                                    MagicNameContainer_guess* names_guess =
                                        (MagicNameContainer_guess*)GetTable_guess();
                                    steve_strncpy_guess(eyeNameSource_guess, names_guess->name_guess, 0x19);
                                    sprintf(eyeName_guess, "Eye_of_%s", eyeNameSource_guess);
                                    int entity_guess = FindPlayerByPartialDisplayName_guess(eyeName_guess, 0);
                                    if (entity_guess != 0) {
                                        if (g_magicLinked_guess != 0) {
                                            g_magicLinked_guess->speedRun_0048_guess = 0.0f;
                                            g_magicLinked_guess->field58_guess = 0.0f;
                                        }
                                        g_magicLinked_guess = (MagicStateA_guess*)entity_guess;
                                        g_magicSession_guess->SetViewActorByName_guess(
                                            ((MagicStateA_guess*)entity_guess)->values120_guess);
                                    }
                                } else if (effect_guess == 0x4d) {
                                    eqspa_locate_corpse_guess();
                                }
                            } else {
                                MagicStateB_guess* stateData_guess = pSpawn_0008_guess->pActorInfo_01a8_guess;
                                if (stateData_guess->fieldC8_guess <= 0.0f) {
                                    if ((unsigned int)effectIndex_guess >= 12) {
                                        __debugbreak();
                                    }
                                    if (spell_guess->values60_guess[effectIndex_guess] != 1 &&
                                        MagicIdAllowed_guess(entry_guess->id_guess) == 0) {
                                        continue;
                                    }
                                }
                            }
                        } else if (effect_guess == 100) {
                            applyGeneric_guess = 1;
                        // SummonHorse (113): while not mounted (+0x15C of the actor info), mount the
                        // spawn "<name>`s_Mount".
                        } else if (effect_guess == 0x71) {
                            MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
                            if (stateValue_guess != 0 && stateValue_guess->pActorInfo_01a8_guess != 0 &&
                                stateValue_guess->pActorInfo_01a8_guess->field15C_guess == 0) {
                                MagicNameContainer_guess* names_guess =
                                    (MagicNameContainer_guess*)GetTable_guess();
                                steve_strncpy_guess(mountNameSource_guess, names_guess->name_guess, 0x19);
                                sprintf(mountName_guess, "%s`s_Mount", mountNameSource_guess);
                                int entity_guess = FindPlayerByPartialDisplayName_guess(mountName_guess, 0);
                                if (entity_guess != 0) {
                                    stateValue_guess->MountEQPlayer_guess(entity_guess);
                                }
                            }
                        } else if (effect_guess == 0x9c) {
                            if (entry_guess->unknown08_guess != -1 &&
                                entry_guess->unknown08_guess < 2) {
                                g_magicMessageRouter_guess->dsp_chat(
                                    pStringTable->getString(0x30c3, 0),
                                    0x121, 1);
                            }
                        // SPA 189: the same per-tick change and early end as mana, on the pool at
                        // +0x11AC.
                        } else if (effect_guess == 0xbd) {
                            int amount_guess = CalcAffectChange_guess(
                                spell_guess, entry_guess->casterLevel_0001_guess, effectIndex_guess, entry_guess);
                            if (amount_guess < 0 && spell_guess->field17d == 1) {
                                int current_guess = Cur_Endurance_guess();
                                int normalized_guess = NormalizeMagicAmount_guess(amount_guess);
                                if (current_guess < normalized_guess) {
                                    ((Wrap411F2F_guess*)this)->RemovePCAffect_guess(
                                        (int)entry_guess);
                                }
                            }
                            if (entry_guess->active_guess == 4) {
                                amount_guess = -amount_guess;
                            }
                            ((CharacterMagicSystem_guess*)GetTable_guess())->AddField11AC_guess(
                                amount_guess);
                            Cur_Endurance_guess();
                        // SPA 334 adds its HP change unless the spawn is a moving NPC (type 1 with
                        // run speed above 0).
                        } else if (effect_guess == 0x14e) {
                            MagicStateA_guess* stateValue_guess = pSpawn_0008_guess;
                            if (stateValue_guess == 0 || stateValue_guess->type_0244_guess != 1 ||
                                stateValue_guess->speedRun_0048_guess <= 0.0f) {
                                applyGeneric_guess = 1;
                            }
                        // SPA 343: base percent chance per tick to interrupt the spawn's current
                        // cast (+0xF98), unless that spell's +0x1FC is set.
                        } else if (effect_guess == 0x157) {
                            int chance_guess = RandomRange_guess(0, 99);
                            if ((unsigned int)effectIndex_guess >= 12) {
                                __debugbreak();
                            }
                            if (chance_guess < spell_guess->values30_guess[effectIndex_guess] &&
                                pSpawn_0008_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
                                pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess != -1) {
                                MagicCheck_guess* currentSpell_guess =
                                    g_magicLookup_guess->GetSpell_guess(
                                        pSpawn_0008_guess->pActorInfo_01a8_guess->fieldF98_guess);
                                if (currentSpell_guess != 0 && currentSpell_guess->field1fc == 0) {
                                    RefreshFromState_guess(1);
                                }
                            }
                        }

                        if (applyGeneric_guess != 0) {
                            unsigned int value_guess =
                                ((CharacterMagicSystem_guess*)GetTable_guess())->GetBuffCasterId_guess(
                                    entryIndex_guess);
                            int amount_guess = CalcScaledAffectChange_guess(
                                value_guess, entry_guess, effectIndex_guess, spell_guess);
                            total_guess += amount_guess;
                        }
                        if (pSpawn_0008_guess == 0) {
                            break;
                        }
                    }
                    if (pSpawn_0008_guess == 0) {
                        break;
                    }
                }
                if (removeEntry_guess != 0) {
                    ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)entry_guess);
                }
            }
            ++entryIndex_guess;
        } while (entryIndex_guess < (unsigned char)GetMaxBuffs_guess(this));
    }

    // The summed HP change applies once per tick. Any damage breaks a Mez (SPA 31) first.
    if (total_guess != 0) {
        if (total_guess < 0) {
            MagicEntryProbe_guess* entry_guess = FindBuffWithEffect_guess(0x1f, 0);
            if (entry_guess != 0) {
                ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)entry_guess);
                UnStunMe_guess();
            }
        }
        ((MagicResolveContainer_guess*)GetTable_guess())->list_guess.GetCharInfo2();
        ModifyCurHP_guess(total_guess, 0);
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0044CF50 IsEffectIgnoredInStacking_guess
char __cdecl IsEffectIgnoredInStacking_guess(int type_guess);

// Stacking: the buff slot spell `spellId_guess` from `caster_guess` would take (outIndex), or 0 when an
// existing buff blocks it.
// FUNCTION: TITANIUM 0x00414071
// @early-stop: budget, structural ndiff=768
MagicEntryProbe_guess* CharacterMagicSystem_guess::FindBuffSlot_guess(int spellId_guess,
                                                                  MagicStateA_guess* caster_guess,
                                                                  int* outIndex_guess,
                                                                  int noRemove_guess) {
    *outIndex_guess = -1;
    if (caster_guess == 0 || IsValidSpellIndex_guess(spellId_guess) == 0) {
        return 0;
    }
    MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
    if (spell_guess == 0) {
        return 0;
    }
    int level_guess = caster_guess->level_024c_guess;
    if (IsBardSong_guess((MagicPredicateObject_guess*)spell_guess, caster_guess->playerClass_0252_guess) != 0 &&
        caster_guess->pActorInfo_01a8_guess != 0 && caster_guess->pCharInfo_0218_guess != 0) {
        level_guess += caster_guess->pCharInfo_0218_guess->TotalSpellAffects_guess(0x110, true, 0, true);
    }
    if (caster_guess->type_0244_guess == 0 &&
        IsBlockedByStackingCommand_guess(spell_guess, caster_guess->playerClass_0252_guess) != 0) {
        return 0;
    }

    // The same spell already on: refreshed in place unless the new copy is from a lower caster level or has
    // EyeOfZomm (67), CompleteHeal (101) or SummonHorse (113), which never refresh. On an NPC hit by a
    // player, a spell with Check_guess set keeps one copy per caster (never spell 2755).
    char check_guess = spell_guess->Check_guess();
    char replace_guess = 0;
    int index_guess;
    for (index_guess = 0; index_guess < (unsigned char)GetMaxBuffs_guess(this); ++index_guess) {
        MagicEntryProbe_guess* entry_guess = GetBuff_guess(index_guess);
        if (entry_guess->active_guess == 0 || entry_guess->id_guess != spellId_guess) {
            continue;
        }
        if (pSpawn_0008_guess != 0 && caster_guess->type_0244_guess == 0 &&
            pSpawn_0008_guess->type_0244_guess == 1) {
            if (entry_guess->id_guess == 0xac3) {
                check_guess = 0;
            }
            if (check_guess != 0 &&
                caster_guess->spawnId_0258_guess !=
                    ((CharacterMagicSystem_guess*)GetTable_guess())->GetBuffCasterId_guess(index_guess)) {
                replace_guess = 1;
                continue;
            }
        }
        if (level_guess < (unsigned char)entry_guess->casterLevel_0001_guess ||
            spell_guess->FindAffectSlot_guess(0x43) != 0 ||
            spell_guess->FindAffectSlot_guess(0x65) != 0 ||
            spell_guess->FindAffectSlot_guess(0x71) != 0) {
            *outIndex_guess = -1;
            return 0;
        }
        *outIndex_guess = index_guess;
        return GetBuff_guess(index_guess);
    }

    // One copy per caster: reuse a copy whose recorded caster is gone or is this character itself (the test
    // compares with state_guess, not with the new caster), else the first free slot.
    if (check_guess != 0 && replace_guess != 0) {
        int freeIndex_guess = -1;
        for (index_guess = 0; index_guess < (unsigned char)GetMaxBuffs_guess(this); ++index_guess) {
            MagicEntryProbe_guess* entry_guess = GetBuff_guess(index_guess);
            if (entry_guess->active_guess == 0) {
                if (freeIndex_guess == -1) {
                    freeIndex_guess = index_guess;
                }
            } else if (spellId_guess == entry_guess->id_guess && pSpawn_0008_guess != 0) {
                int owner_guess = Transform_guess(
                    ((CharacterMagicSystem_guess*)GetTable_guess())->GetBuffCasterId_guess(index_guess));
                if (owner_guess == 0 || owner_guess == (int)pSpawn_0008_guess) {
                    *outIndex_guess = index_guess;
                    return GetBuff_guess(index_guess);
                }
            }
        }
        if (freeIndex_guess != -1) {
            *outIndex_guess = freeIndex_guess;
            return GetBuff_guess(freeIndex_guess);
        }
    }

    int slot_guess;
    // Stacking against every other active buff, effect slot by effect slot (0xFE ends a spell's list); buffs
    // whose spell no longer exists are cleared on the way.
    for (slot_guess = 0; slot_guess < (unsigned char)GetMaxBuffs_guess(this); ++slot_guess) {
        MagicEntryProbe_guess* entry_guess = GetBuff_guess(slot_guess);
        if (entry_guess->active_guess == 0) {
            continue;
        }
        int otherId_guess = entry_guess->id_guess;
        MagicCheck_guess* other_guess;
        if (IsValidSpellIndex_guess(otherId_guess) == 0 ||
            (other_guess = g_magicLookup_guess->GetSpell_guess(otherId_guess)) == 0) {
            entry_guess->id_guess = -1;
            entry_guess->unknown08_guess = 0;
            entry_guess->counters_000c_guess = 0;
            entry_guess->active_guess = 0;
            entry_guess->casterLevel_0001_guess = 0;
            entry_guess->padTo04_guess[0] = 0;
            continue;
        }
        // A bard's song is not checked against a non-song buff, and a beneficial non-song is not checked
        // against a beneficial song (bard level 255 means not a song).
        if (caster_guess->playerClass_0252_guess == 8 && other_guess->CheckMode_guess(8) == 0xff &&
            IsBardSong_guess((MagicPredicateObject_guess*)spell_guess,
                            caster_guess->playerClass_0252_guess) != 0) {
            continue;
        }
        if (spell_guess->field17d != 0 && other_guess->field17d != 0 &&
            other_guess->CheckMode_guess(8) > 0 && other_guess->CheckMode_guess(8) < 0xff &&
            spell_guess->CheckMode_guess(8) == 0xff) {
            continue;
        }
        unsigned char effect_guess = 0;
        do {
            if (other_guess->GetType_guess(effect_guess) == 0xfe) {
                break;
            }
            if (spell_guess->GetType_guess(effect_guess) == 0xfe) {
                break;
            }
            // Lycanthropy and Vampirism (SPA 44, 45) never land while any buff is up.
            if (spell_guess->GetType_guess(effect_guess) == 0x2c ||
                spell_guess->GetType_guess(effect_guess) == 0x2d) {
                *outIndex_guess = -1;
                return 0;
            }
            if ((other_guess->GetType_guess(effect_guess) == 0xf ||
                 other_guess->GetType_guess(effect_guess) == 0 ||
                 other_guess->GetType_guess(effect_guess) == 100 ||
                 // Only the same SPA in the same effect slot can conflict. A non-song's HP, mana, HoT or
                 // BardAEDot effect (0, 15, 100, 334) never blocks a song; IsEffectIgnoredInStacking_guess
                 // (0x0044CF50) effects always stack; a negative new HP, AC or BardAEDot value (SPA 0, 1,
                 // 334) and CHA (10) with a zero on either side are ignored.
                 other_guess->GetType_guess(effect_guess) == 0x14e) &&
                other_guess->CheckMode_guess(8) != 0xff && spell_guess->CheckMode_guess(8) == 0xff) {
                continue;
            }
            if (other_guess->GetType_guess(effect_guess) != spell_guess->GetType_guess(effect_guess)) {
                continue;
            }
            if (IsEffectIgnoredInStacking_guess(spell_guess->GetType_guess(effect_guess)) != 0) {
                continue;
            }
            int type_guess = spell_guess->GetType_guess(effect_guess);
            if (type_guess >= 0) {
                if (type_guess <= 1 || type_guess == 0x14e) {
                    if (spell_guess->Get30_guess(effect_guess) < 0) {
                        continue;
                    }
                } else if (type_guess == 10) {
                    if (spell_guess->Get30_guess(effect_guess) == 0 ||
                        other_guess->Get30_guess(effect_guess) == 0) {
                        continue;
                    }
                }
            }
            if (spell_guess->field17d != 0) {
                // A beneficial spell can't replace a detrimental one (movement speed excepted) or any
                // illusion (58, 156).
                if (other_guess->field17d == 0) {
                    if (spell_guess->GetType_guess(effect_guess) == 3) {
                        continue;
                    }
                    *outIndex_guess = -1;
                    return 0;
                }
                if (other_guess->FindAffectSlot_guess(0x3a) != 0 ||
                    other_guess->FindAffectSlot_guess(0x9c) != 0) {
                    *outIndex_guess = -1;
                    return 0;
                }
            }
            // Never replaced: CompleteHeal effects and a fixed list of spells (775-785, 1200-1250, 1900-1924,
            // 2079, 2751, 756, 757 and 5249 (the resurrection effects), 836).
            if (other_guess->GetType_guess(effect_guess) == 0x65 ||
                (otherId_guess >= 0x307 && otherId_guess <= 0x311) ||
                (otherId_guess >= 0x4b0 && otherId_guess <= 0x4e2) ||
                (otherId_guess >= 0x76c && otherId_guess <= 0x784) ||
                otherId_guess == 0x81f || otherId_guess == 0xabf || otherId_guess == 0x2f4 ||
                otherId_guess == 0x1481 || otherId_guess == 0x2f5 || otherId_guess == 0x344) {
                *outIndex_guess = -1;
                return 0;
            }
            int otherAmount_guess = CalcAffectChange_guess(other_guess, entry_guess->casterLevel_0001_guess,
                                                       effect_guess, 0);
            int newAmount_guess = CalcAffectChange_guess(spell_guess, level_guess, effect_guess, 0);
            // Spells 1620, 1816, 833 and 1814 count as negative here; the first test looks for 1814 in
            // otherId, not spellId (as in the original).
            if (spellId_guess == 0x654 || spellId_guess == 0x718 || spellId_guess == 0x341 ||
                otherId_guess == 0x716) {
                newAmount_guess = -1;
            }
            if (otherId_guess == 0x654 || otherId_guess == 0x718 || otherId_guess == 0x341 ||
                otherId_guess == 0x716) {
                otherAmount_guess = -1;
            }
            // Opposite signs: the new spell replaces the old, except movement speed (no conflict) and a heal
            // over a DoT in the HP effect (blocked).
            if ((otherAmount_guess < 0 && newAmount_guess > 0) ||
                (otherAmount_guess > 0 && newAmount_guess < 0)) {
                if (spell_guess->GetType_guess(effect_guess) == 3) {
                    continue;
                }
                if (spell_guess->GetType_guess(effect_guess) == 0 && otherAmount_guess < 0 &&
                    newAmount_guess > 0) {
                    *outIndex_guess = -1;
                    return 0;
                }
            } else {
                // Same sign: the new one must be at least as strong; attack speed (SPA 11) compares around
                // 100, below which it is a slow. Spell 836 always wins. If either spell is beneficial the
                // slot
                // is only noted and the next buff is checked; between two detrimental spells the old one is
                // removed and its slot taken.
                int better_guess = spellId_guess == 0x344;
                if (spell_guess->GetType_guess(effect_guess) == 0xb) {
                    if ((newAmount_guess < 100 && newAmount_guess <= otherAmount_guess) ||
                        (otherAmount_guess > 100 &&
                         (newAmount_guess < 100 || newAmount_guess >= otherAmount_guess))) {
                        better_guess = 1;
                    }
                } else if ((otherAmount_guess < 0 && newAmount_guess <= otherAmount_guess) ||
                           (otherAmount_guess > 0 && newAmount_guess >= otherAmount_guess)) {
                    better_guess = 1;
                }
                if (better_guess == 0) {
                    *outIndex_guess = -1;
                    return 0;
                }
                if (spell_guess->field17d != 0 || other_guess->field17d != 0) {
                    if (*outIndex_guess == -1 || GetBuff_guess(*outIndex_guess)->active_guess == 0) {
                        *outIndex_guess = slot_guess;
                    }
                    break;
                }
            }
            *outIndex_guess = slot_guess;
            if (noRemove_guess == 0 && spellId_guess != entry_guess->id_guess) {
                RemovePCAffectex_guess(GetBuff_guess(slot_guess), 0);
            }
            *outIndex_guess = FUN_00411ea4_guess(
                ((CharacterMagicSystem_guess*)spell_guess)->IsReady_guess(),
                spell_guess->field1C4_guess, slot_guess);
            return GetBuff_guess(*outIndex_guess);
        } while (++effect_guess < 12);
    }

    // No conflict decided it: take the noted slot or the first free one in this spell's slot range
    // (FUN_00411ea4_guess picks long buffs or the short/song range by IsReady_guess and +0x1C4).
    char ready_guess = ((CharacterMagicSystem_guess*)spell_guess)->IsReady_guess();
    char flag_guess = spell_guess->field1C4_guess;
    if (spell_guess->field17d == 0) {
        flag_guess = 0;
    }
    int found_guess = FUN_00411ea4_guess(ready_guess, flag_guess, -1);
    int current_guess = *outIndex_guess;
    if (current_guess == -1) {
        *outIndex_guess = found_guess;
    } else if (found_guess == -1 &&
               (current_guess < GetStateAdjustment_guess(ready_guess, flag_guess) ||
                *outIndex_guess > GetDelayFromState_guess(ready_guess, flag_guess, 0))) {
        *outIndex_guess = -1;
    }
    if (*outIndex_guess != -1) {
        if (noRemove_guess == 0 && GetBuff_guess(*outIndex_guess)->active_guess != 0 &&
            spellId_guess != GetBuff_guess(*outIndex_guess)->id_guess) {
            RemovePCAffectex_guess(GetBuff_guess(*outIndex_guess), 0);
        }
        *outIndex_guess = FUN_00411ea4_guess(ready_guess, flag_guess, slot_guess);
        return GetBuff_guess(*outIndex_guess);
    }
    // All full: a detrimental spell pushes out the first beneficial buff (only when the target's +0x256 is
    // clear).
    if (spell_guess->field17d != 0 || pSpawn_0008_guess == 0 || pSpawn_0008_guess->gm_0256_guess != 0) {
        return 0;
    }
    for (index_guess = 0; index_guess < (unsigned char)GetMaxBuffs_guess(this); ++index_guess) {
        int id_guess = GetBuff_guess(index_guess)->id_guess;
        MagicCheck_guess* found_check_guess;
        if (IsValidSpellIndex_guess(id_guess) != 0 &&
            (found_check_guess = g_magicLookup_guess->GetSpell_guess(id_guess)) != 0 &&
            found_check_guess->field17d != 0) {
            if (noRemove_guess == 0) {
                RemovePCAffectex_guess(GetBuff_guess(index_guess), 0);
            }
            *outIndex_guess = index_guess;
            *outIndex_guess = FUN_00411ea4_guess(ready_guess, flag_guess, index_guess);
            return GetBuff_guess(*outIndex_guess);
        }
    }
    return 0;
}

#pragma pack(push, 1)
struct MagicHitPacket_guess {
    short field0_guess;
    unsigned short casterId_guess;
    short level_guess;
    int scale_guess;
    char padTo0E_guess[4];
    float fieldE_guess;
    char padTo19_guess[7];
    unsigned short field19_guess;
    short spellId_guess;
};
#pragma pack(pop)

struct MagicHitRecord_guess {
    char padTo44_guess[0x44];
    char text_guess[0x100];
};

struct MagicHitPcBase_guess {
    char padTo3C_guess[0x3c];
    char name_guess[0x40];
    char padToBC_guess[0xbc - 0x7c];
    CopyBuffer64_guess bufferBC_guess;
};

struct MagicHitPcHead_guess {
    virtual void Slot00_guess();
    int field4_guess;
    MagicList_guess base8_guess;
    char padToE54_guess[0xe54 - 0xc];
    int fieldE54_guess;
    char padToC280_guess[0xc280 - 0xe58];
    MagicHitPcBase_guess* GetBase_guess() {
        return (MagicHitPcBase_guess*)&base8_guess.tableBytes_guess[base8_guess.offsetHolder_guess->vbaseOffset_0004_guess];
    }
    // EXTERNAL: TITANIUM 0x004BB226 MagicHitPcHead_guess::IsAGroupMember_guess
    int IsAGroupMember_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x005F0790 MagicHitPcHead_guess::FUN_005f0790_guess
    void FUN_005f0790_guess(int index_guess, int zone_guess);
    // EXTERNAL: TITANIUM 0x005F07F0 MagicHitPcHead_guess::FUN_005f07f0_guess
    void FUN_005f07f0_guess(int index_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x005F0850 MagicHitPcHead_guess::FUN_005f0850_guess
    void FUN_005f0850_guess(int index_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x005F08B0 MagicHitPcHead_guess::FUN_005f08b0_guess
    void FUN_005f08b0_guess(int index_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x005F08E0 MagicHitPcHead_guess::FUN_005f08e0_guess
    void FUN_005f08e0_guess(int index_guess, float value_guess);
    // EXTERNAL: TITANIUM 0x005ED550 MagicHitPcHead_guess::FUN_005ed550_guess
    int FUN_005ed550_guess();
    // EXTERNAL: TITANIUM 0x005ED570 MagicHitPcHead_guess::FUN_005ed570_guess
    void FUN_005ed570_guess(int value_guess);
};

struct MagicHitPc_guess : MagicHitPcHead_guess, CharacterMagicSystem_guess {
};

struct MagicHitItem_guess {
    // EXTERNAL: TITANIUM 0x005E0770 MagicHitItem_guess::FUN_005e0770_guess
    char FUN_005e0770_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0EE0 MagicHitItem_guess::FUN_005e0ee0_guess
    char* FUN_005e0ee0_guess();
    // EXTERNAL: TITANIUM 0x005E0E60 MagicHitItem_guess::FUN_005e0e60_guess
    int FUN_005e0e60_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 MagicHitItem_guess::GetItemClass_guess
    int GetItemClass_guess();
};

struct MagicHitRouter_guess {
    // EXTERNAL: TITANIUM 0x00492595 MagicHitRouter_guess::GetLangDesc_guess
    char* GetLangDesc_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004A1350 MagicHitRouter_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x004AB056 MagicHitRouter_guess::MoveToZone_guess
    void MoveToZone_guess(int zone_guess, const char* reason_guess, int zero_guess, int type_guess,
                            float y_guess, float x_guess, float z_guess, int heading_guess);
};

struct MagicHitFx_guess {
    // EXTERNAL: TITANIUM 0x004B70DB MagicHitFx_guess::FUN_004b70db_guess
    void FUN_004b70db_guess(MagicPoint_guess* position_guess, int type_guess);
};

struct MagicHitTrig_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float angle_guess);
    virtual float Cos_guess(float angle_guess);
};

struct MagicHitNode_guess {
    char padTo38_guess[0x38];
    float field38_guess;
    float field3C_guess;
    float field40_guess;
    // EXTERNAL: TITANIUM 0x0048FBC8 MagicHitNode_guess::GetSwitchDamage_guess
    int GetSwitchDamage_guess();
};

struct MagicHitNodeList_guess {
    // EXTERNAL: TITANIUM 0x004904FD MagicHitNodeList_guess::FUN_004904fd_guess
    int FUN_004904fd_guess();
    // EXTERNAL: TITANIUM 0x00490530 MagicHitNodeList_guess::FUN_00490530_guess
    MagicHitNode_guess* FUN_00490530_guess(int index_guess);
};

struct MagicHitSession_guess {
    // EXTERNAL: TITANIUM 0x00439BD1 MagicHitSession_guess::SimpleDistance_guess
    float SimpleDistance_guess(float y1_guess, float x1_guess, float z1_guess, float y2_guess,
                             float x2_guess, float z2_guess, float extra_guess);
};

// EXTERNAL: TITANIUM 0x00474EDD CopySpellData_guess
int __cdecl CopySpellData_guess(int spellId_guess, MagicHitRecord_guess* record_guess, int flag_guess);

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int command_guess, int first_guess, int second_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, int id_guess, const char* arg1_guess,
                                const char* arg2_guess, const char* arg3_guess, const char* arg4_guess,
                                const char* arg5_guess, const char* arg6_guess, const char* arg7_guess,
                                const char* arg8_guess, const char* arg9_guess);

// EXTERNAL: TITANIUM 0x004B718D FUN_004b718d_guess
MagicHitFx_guess* __cdecl FUN_004b718d_guess();

#define g_magicNoGround_guess EQ_GLOBAL(float, 0x00640EA0)
#define g_magicHitFlag47C_guess EQ_GLOBAL(int, 0x0090047C)
#define g_magicHitMode_guess EQ_GLOBAL(char, 0x00923B88)
#define g_magicHitState_guess EQ_GLOBAL(int, 0x00923D94)
#define g_magicHitTrig_guess EQ_GLOBAL(MagicHitTrig_guess*, 0x0099E374)
#define g_magicHitNodes_guess EQ_GLOBAL(MagicHitNodeList_guess*, 0x00903E84)
#define g_magicHitMoved_guess EQ_GLOBAL(char, 0x00923D79)
#define g_magicHitMovedLinked_guess EQ_GLOBAL(char, 0x00923D78)

// A spell landed on this character: stacking, resists, effect messages, identify (12451, 1562, 12452) and
// buff placement. A fatal case logs a disconnect (CMD_EXITGAME) line.
// FUNCTION: TITANIUM 0x00414913
// @early-stop: budget, structural ndiff=1683
void CharacterMagicSystem_guess::HitBySpell(MagicHitPacket_guess* packet_guess, int amount_guess) {
    int isType91_guess = 0;
    int searchA_guess = -1;
    int searchB_guess = -1;
    int searchC_guess = -1;
    int searchD_guess = -1;
    MagicHitRecord_guess record_guess;
    char nameBuffer_guess[80];
    char text_guess[256];
    char message_guess[188];

    if (pSpawn_0008_guess == 0) {
        return;
    }
    if (pSpawn_0008_guess->pActorInfo_01a8_guess == 0) {
        return;
    }
    int spellId_guess = packet_guess->spellId_guess;
    if (IsValidSpellIndex_guess(spellId_guess) == 0) {
        return;
    }
    MagicCheck_guess* spell_guess = g_magicLookup_guess->GetSpell_guess(spellId_guess);
    if (spell_guess == 0) {
        return;
    }
    MagicStateA_guess* caster_guess = (MagicStateA_guess*)Transform_guess(packet_guess->casterId_guess);
    if (caster_guess == 0) {
        return;
    }
    if (spell_guess->values_120[0] == 0x91) {
        isType91_guess = 1;
    }
    // Divine Aura (SPA 40) blocks everything except spell 982, effect 145 spells and spells with +0x1FC set.
    if (TotalSpellAffects_guess(0x28, true, 0, 1) > 0 && spellId_guess != 0x3d6 &&
        isType91_guess == 0 && spell_guess->field1fc == 0) {
        return;
    }
    unsigned char level_guess = caster_guess->level_024c_guess;
    if (IsBardSong_guess((MagicPredicateObject_guess*)spell_guess, caster_guess->playerClass_0252_guess) != 0 &&
        caster_guess->pActorInfo_01a8_guess != 0 && caster_guess->pCharInfo_0218_guess != 0) {
        // The effective caster level: the caster's level, plus its SPA 272 total when a bard casts a bard
        // song (0x0040DB0B, the bard-song test the code calls CanAffect_guess).
        level_guess += caster_guess->pCharInfo_0218_guess->TotalSpellAffects_guess(0x110, true, 0, 1);
    }
    if (IsBuffLevelBlocked_guess((MagicPredicateObject_guess*)spell_guess, caster_guess->pCharInfo_0218_guess) != 0) {
        if (caster_guess->playerClass_0252_guess == 8) {
            return;
        }
        // The second test with the caster's character object fails the spell with string 197 ("Your spell is
        // too powerful for your intended target."); a bard caster (class 8) gets no message.
        token_string_to_client_guess((MagicHitPc_guess*)caster_guess->GetPcClient_guess(), 0xc5, 0x121, 0);
        return;
    }
    // Spells 1252-1266 land at the level the packet carries (1-60) instead.
    if (spellId_guess >= 0x4e4 && spellId_guess <= 0x4f2 && packet_guess->level_guess > 0 &&
        packet_guess->level_guess <= 0x3c) {
        level_guess = (unsigned char)packet_guess->level_guess;
    }
    // Our own spell whose first effect is Fear (SPA 23) never lands on ourselves.
    if (caster_guess == pSpawn_0008_guess && spell_guess->values_120[0] == 0x17) {
        return;
    }
    // Alter Plane: Hate and Alter Plane: Sky (666, 674) need level 46; a player is told string 252.
    if ((spellId_guess == 0x29a || spellId_guess == 0x2a2) &&
        ResolveResult_guess()->level_11a4_guess < 0x2e) {
        if (pSpawn_0008_guess == 0) {
            return;
        }
        if (pSpawn_0008_guess->type_0244_guess != 0) {
            return;
        }
        token_string_to_client_guess(this, 0xfc, 0x121, 0);
        return;
    }
    if ((spell_guess->field180_guess == 0x14 ||
         // Player against player (target type 20, or a detrimental spell with +0x194 set): with
         // g_modeCode_guess 0 the caster is told string 210 ("That spell can not affect this target PC.") and
         // nothing lands; otherwise a group member is refused with string 2242 (IsAGroupMember_guess is the
         // group-member test).
         (spell_guess->field194_guess != 0 && spell_guess->field17d == 0)) &&
        pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0 && caster_guess->type_0244_guess == 0) {
        MagicHitPc_guess* casterPc_guess = (MagicHitPc_guess*)caster_guess->GetPcClient_guess();
        MagicHitPc_guess* ownPc_guess = (MagicHitPc_guess*)pSpawn_0008_guess->GetPcClient_guess();
        if (casterPc_guess != ownPc_guess) {
            if (g_modeCode_guess != 0) {
                if (casterPc_guess != 0 && ownPc_guess != 0 &&
                    casterPc_guess->IsAGroupMember_guess(ownPc_guess->GetBase_guess()->name_guess) != 0) {
                    token_string_to_client_guess(casterPc_guess, 0x8c2, 0x121, 0);
                    return;
                }
            } else {
                if (casterPc_guess == 0) {
                    return;
                }
                token_string_to_client_guess(casterPc_guess, 0xd2, 0x121, 0);
                return;
            }
        }
    }
    // A spell without a client record is fatal: the client exits (command 0xFD).
    if (CopySpellData_guess(spellId_guess, &record_guess, 1) == 0) {
        FUN_00574110_guess("*** DISCONNECTING: HitBySpell() is throwing a CMD_EXITGAME at %s:%lu\n",
                           // The original source path, kept from the client's assert macro.
                           "C:\\EQ\\EverQuest\\CharacterMagicSystem.cpp", 0x2fb8);
        ExecuteCmd(0xfd, 0, 0);
    }
    if ((spell_guess->field180_guess != 0xd && spell_guess->field180_guess != 0x14) ||
        caster_guess != pSpawn_0008_guess) {
        // Beneficial spells whose first effect is an invisibility (SPA 12, 28, 29, 314-316), Torpor (1576),
        // Stoicism (3694) and beneficial spells with CancelMagic (SPA 27, caster +0x256 clear) land from
        // another player only if that player is in our group (IsAGroupMember_guess); AllowedToAttack_guess is
        // the general check.
        if (spell_guess->field17d == 1 && caster_guess->type_0244_guess == 0 &&
            pSpawn_0008_guess->type_0244_guess == 0 &&
            (spell_guess->values_120[0] == 0xc || spell_guess->values_120[0] == 0x1c ||
             spell_guess->values_120[0] == 0x1d || spell_guess->values_120[0] == 0x13a ||
             spell_guess->values_120[0] == 0x13b || spell_guess->values_120[0] == 0x13c ||
             spellId_guess == 0x628 || spellId_guess == 0xe6e ||
             (spell_guess->FindAffectSlot_guess(0x1b) != 0 && caster_guess->gm_0256_guess == 0))) {
            if (GetTable_guess()->GetObject_guess()->IsAGroupMember_guess(caster_guess->name120_guess) == 0) {
                return;
            }
        }
        if (pSpawn_0008_guess->masterId_025c_guess != caster_guess->spawnId_0258_guess || spell_guess->field17d == 0) {
            if (caster_guess->AllowedToAttack_guess(pSpawn_0008_guess, spellId_guess) == 0) {
                return;
            }
        }
    }
    // A hostile spell breaks the target's invisibility: buffs with SPA 12, 28, 29 and 314-316 are removed.
    if (spell_guess->field17d == 0) {
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0xc, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x1c, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x1d, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13a, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13b, 0));
        ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)FindBuffWithEffect_guess(0x13c, 0));
    }
    MagicStateA_guess* self_guess = pSpawn_0008_guess;
    Cur_HP(self_guess->type_0244_guess);
    // No duration from the server: amount_guess here is the buff duration. Hostile spells between players use
    // the formula at +0x1EC, capped by +0x1F0 (0x00410E5A, GetSpellDuration_guess); everything else the
    // formula at +0x20 (SpellDuration_guess, 0x0040EBC3).
    if (amount_guess <= 0) {
        if (spell_guess->field17d == 0 && pSpawn_0008_guess->type_0244_guess == 0 &&
            caster_guess->type_0244_guess == 0) {
            amount_guess = GetSpellDuration_guess(spell_guess, level_guess, 0);
        } else {
            amount_guess = SpellDuration_guess((MagicSpell_guess*)spell_guess, level_guess, 0);
        }
    }
    // Screech (SPA 123): a hostile spell with this effect is cancelled when its amount plus our own SPA 123
    // total is 0 or more: "Your immunity buff protected you from the spell %1!"
    if (spell_guess->field17d == 0 && spell_guess->FindAffectSlot_guess(0x7b) != 0) {
        unsigned char effectSlot_guess = spell_guess->FindAffectSlot_guess(0x7b);
        int bonus_guess = TotalSpellAffects_guess(0x7b, true, 0, 1);
        effectSlot_guess--;
        if (CalcAffectChange_guess(spell_guess, ResolveResult_guess()->level_11a4_guess, effectSlot_guess, 0) +
                bonus_guess >= 0) {
            FUN_0046da4a_guess(message_guess, 0x30a0, spell_guess->field208_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_guess, 0x121, 1);
            return;
        }
    }

    // Instant spells (no duration): each of the 12 effect slots acts once and nothing is stored.
    if (spell_guess->field20 == 0) {
        MagicHitPc_guess* pc_guess = 0;
        if (pSpawn_0008_guess->type_0244_guess == 0) {
            pc_guess = (MagicHitPc_guess*)GetTable_guess()->GetObject_guess();
        }
        for (unsigned char slot_guess = 0; slot_guess < 12; ++slot_guess) {
            if (pSpawn_0008_guess == 0) {
                return;
            }
            unsigned int index_guess = slot_guess;
            if (CheckMagic_guess((MagicQuery_guess*)spell_guess, index_guess) == 0) {
                continue;
            }
            amount_guess = CalcAffectChange_guess(spell_guess, level_guess, slot_guess, 0);
            // Level-scaled amounts: Lay on Hands (87) above level 40 adds 44 a level unless SPA 284 sets it;
            // Harm Touch (88, 2774) loses 20 a level over 40 (at most 500), times 1.5 with buff 4520; spell
            // 742 loses 10 a level over 45 (at most 200).
            if (spellId_guess != 0xad7) {
                CharacterMagicSystem_guess* casterMagic_guess = caster_guess->pCharInfo_0218_guess;
                if (casterMagic_guess != 0 && spellId_guess == 0x57) {
                    if (caster_guess->level_024c_guess > 0x28) {
                        int override_guess = casterMagic_guess->TotalSpellAffects_guess(0x11c, true, 0, 1);
                        if (override_guess > 0) {
                            amount_guess = override_guess;
                        } else {
                            int extra_guess = (caster_guess->level_024c_guess - 0x28) * 0x2c;
                            if (extra_guess < 0) {
                                extra_guess = 0;
                            }
                            amount_guess += extra_guess;
                        }
                    }
                } else if ((spellId_guess == 0x58 || spellId_guess == 0xad6) &&
                           caster_guess->level_024c_guess > 0x28) {
                    int reduce_guess = (caster_guess->level_024c_guess - 0x28) * 20;
                    if (reduce_guess < 0) {
                        reduce_guess = 0;
                    } else if (reduce_guess > 500) {
                        reduce_guess = 500;
                    }
                    amount_guess -= reduce_guess;
                    if (casterMagic_guess != 0) {
                        int count_guess = (unsigned char)GetMaxBuffs_guess(casterMagic_guess);
                        for (int entryIndex_guess = 0; entryIndex_guess < count_guess; ++entryIndex_guess) {
                            if (casterMagic_guess->GetBuff_guess(entryIndex_guess)->id_guess == 0x11a8) {
                                amount_guess = amount_guess * 6 / 4;
                                break;
                            }
                        }
                    }
                } else if (spellId_guess == 0x2e6 && caster_guess->level_024c_guess > 0x2d) {
                    int reduce_guess = (caster_guess->level_024c_guess - 0x2d) * 10;
                    if (reduce_guess < 0) {
                        reduce_guess = 0;
                    } else if (reduce_guess > 200) {
                        reduce_guess = 200;
                    }
                    amount_guess -= reduce_guess;
                }
            }
            // The returning half of a lifetap (target types 13 and 20, cast by us) uses the packet's amount
            // (+0x19); other effects take the server's scale 1-45 (10 = unscaled).
            if ((spell_guess->field180_guess == 0x14 || spell_guess->field180_guess == 0xd) &&
                caster_guess == pSpawn_0008_guess) {
                if (spell_guess->GetType_guess(index_guess) == 0) {
                    unsigned short raw_guess = packet_guess->field19_guess;
                    amount_guess = raw_guess;
                    if (raw_guess & 0x8000) {
                        amount_guess |= 0xffff0000;
                    }
                } else {
                    amount_guess = packet_guess->field19_guess;
                }
            } else if (spell_guess->GetType_guess(index_guess) != 0x1b) {
                int scale_guess = packet_guess->scale_guess;
                if (scale_guess > 0 && scale_guess <= 0x2d && scale_guess != 10) {
                    amount_guess = (int)((float)scale_guess * g_magicScale_guess * amount_guess);
                }
            }
            if (pSpawn_0008_guess == 0) {
                return;
            }
            switch (spell_guess->GetType_guess(index_guess)) {
            // One-shot effects by SPA (EQEmu SpellEffect names): 38 DetectMagic on the cursor item, 25
            // BindAffinity, 20 Blind (negative cures), 15 CurrentMana, 42 ShadowStep, 56 TrueNorth, 51 sense
            // traps, 52 SenseDead, 53 SenseSummoned, 54 SenseAnimals, 61-62 Identify, 72 PreserveCorpse, 74
            // FeignDeath, 77 LocateCorpse, 83 and 145 teleports, 35/36/116 cure counters, 160 MakeDrunk, 189
            // CurrentEndurance.
            case 0x26:
                strcpy(text_guess, pStringTable->getString(0x30a4, 0));
                if (ResolveResult_guess()->values10_guess[30] != 0) {
                    strcpy(text_guess, pStringTable->getString(0x61a, 0));
                    if (((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                            ->GetItemClass_guess() == 0 &&
                        ((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                            ->FUN_005e0770_guess(1) != 0) {
                        strcpy(text_guess, pStringTable->getString(0x30a3, 0));
                    }
                }
                pEverQuest->dsp_chat(text_guess);
                break;
            // BindAffinity: bind point `amount - 1` (0-4) gets zone, y, x, z and heading. Zones that forbid
            // binding say 0x69; outside the allowed area 0x103. Another caster's bind skips the zone rule.
            case 0x19: {
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return;
                }
                if (pc_guess == 0) {
                    return;
                }
                amount_guess--;
                if (amount_guess < 0 || amount_guess >= 5) {
                    amount_guess = 0;
                }
                if (g_magicZoneCheck_guess->FUN_005f6c00_guess(GetTable_guess()->field100_guess) != 0) {
                    token_string_to_client_guess(this, 0x69, 0x121, 0);
                    return;
                }
                if (caster_guess != pSpawn_0008_guess && caster_guess->gm_0256_guess == 0) {
                    if (g_magicHitMode_guess != 2 && g_magicHitMode_guess != 3 &&
                        g_magicHitMode_guess != 4) {
                        if (IsInRestrictedArea_guess((Position_guess*)self_guess) == 0) {
                            token_string_to_client_guess(this, 0x103, 0x121, 0);
                            return;
                        }
                    }
                    pc_guess->FUN_005f0790_guess(amount_guess, GetTable_guess()->field100_guess);
                    pc_guess->FUN_005f07f0_guess(amount_guess, self_guess->position_guess.y_guess);
                    pc_guess->FUN_005f0850_guess(amount_guess, self_guess->position_guess.x_guess);
                    pc_guess->FUN_005f08b0_guess(amount_guess, self_guess->field38_guess);
                    pc_guess->FUN_005f08e0_guess(amount_guess, self_guess->heading_guess);
                    return;
                }
                int canBind_guess;
                if (g_magicHitFlag47C_guess == 0 && g_modeCode_guess != 6) {
                    if (g_magicHitMode_guess == 1) {
                        canBind_guess = 0;
                    } else {
                        canBind_guess =
                            g_magicZoneCheck_guess->FUN_005f6b90_guess(GetTable_guess()->field100_guess);
                        if (g_modeCode_guess == 4) {
                            canBind_guess = 1;
                        }
                    }
                } else {
                    canBind_guess = 1;
                }
                if (caster_guess->gm_0256_guess == 0 && canBind_guess != 0 &&
                    g_magicHitMode_guess != 2 && g_magicHitMode_guess != 3 &&
                    g_magicHitMode_guess != 4) {
                    if (IsInRestrictedArea_guess((Position_guess*)self_guess) == 0) {
                        token_string_to_client_guess(this, 0x103, 0x121, 0);
                        return;
                    }
                }
                pc_guess->FUN_005f0790_guess(amount_guess, GetTable_guess()->field100_guess);
                pc_guess->FUN_005f07f0_guess(amount_guess, self_guess->position_guess.y_guess);
                pc_guess->FUN_005f0850_guess(amount_guess, self_guess->position_guess.x_guess);
                pc_guess->FUN_005f08b0_guess(amount_guess, self_guess->field38_guess);
                pc_guess->FUN_005f08e0_guess(amount_guess, self_guess->heading_guess);
                g_magicHitState_guess = 7;
                ((MagicHitRouter_guess*)pEverQuest)->SavePC_guess(0, 1, 0xe);
                break;
            }
            case 0x14:
                if (amount_guess < 0) {
                    MagicEntryProbe_guess* entry_guess = FindBuffWithEffect_guess(0x14, 0);
                    if (entry_guess != 0) {
                        // Curing blindness succeeds (level - blind level + 10) * 5 percent of the time, 5-95.
                        int chance_guess =
                            (level_guess - (unsigned char)entry_guess->casterLevel_0001_guess + 10) * 5;
                        if (chance_guess < 5) {
                            chance_guess = 5;
                        } else if (chance_guess > 0x5f) {
                            chance_guess = 0x5f;
                        }
                        if (chance_guess >= number_percent_guess()) {
                            ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)entry_guess);
                        }
                    }
                }
                break;
            // CurrentMana (15): not for bards. +0x11A8 is the mana pool and is not taken below 0.
            case 0xf:
                if (ResolveResult_guess()->class_119c_guess != Class_Bard) {
                    int delta_guess = amount_guess;
                    if (delta_guess < 0 && ResolveResult_guess()->mana_11a8_guess + delta_guess < 0) {
                        delta_guess = -ResolveResult_guess()->mana_11a8_guess;
                    }
                    ((CharacterMagicSystem_guess*)GetTable_guess())->AddField11A8_guess(delta_guess);
                    Cur_Mana_guess();
                }
                break;
            // ShadowStep: up to 10001 random tries for a reachable spot 4 to range + 5 away, then the floor;
            // 0x306F when none is found.
            case 0x2a: {
                float z_guess = pSpawn_0008_guess->field38_guess;
                int tries_guess = 0;
                FUN_004b718d_guess()->FUN_004b70db_guess(&pSpawn_0008_guess->position_guess, 7);
                float newY_guess;
                float newX_guess;
                char found_guess;
                do {
                    float distance_guess =
                        (float)RandomRange_guess(4, (int)spell_guess->range_guess + 5);
                    float angle_guess = (float)RandomRange_guess(0, 0x1ff);
                    newY_guess = pSpawn_0008_guess->position_guess.y_guess +
                                 g_magicHitTrig_guess->Cos_guess(angle_guess) * distance_guess;
                    newX_guess = pSpawn_0008_guess->position_guess.x_guess +
                                 g_magicHitTrig_guess->Sin_guess(angle_guess) * distance_guess;
                    found_guess = pSpawn_0008_guess->IsPathClear_guess(newY_guess, newX_guess, z_guess,
                                                                  angle_guess, distance_guess);
                    if (found_guess != 0) {
                        break;
                    }
                    ++tries_guess;
                } while (tries_guess <= 10000);
                if (found_guess == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x306f, 0), 0x111, 1);
                    break;
                }
                self_guess->PlaySound_guess(0x89);
                pSpawn_0008_guess->position_guess.y_guess = newY_guess;
                pSpawn_0008_guess->field38_guess = z_guess;
                pSpawn_0008_guess->position_guess.x_guess = newX_guess;
                MagicTable_guess* table_guess = GetTable_guess();
                table_guess->field2C_guess = newY_guess;
                table_guess->field34_guess = z_guess;
                table_guess->field30_guess = newX_guess;
                float ground_guess = pSpawn_0008_guess->GetFloorHeightAt_guess(
                    pSpawn_0008_guess->position_guess.y_guess, pSpawn_0008_guess->position_guess.x_guess,
                    pSpawn_0008_guess->field38_guess, 1);
                if (ground_guess != g_magicNoGround_guess) {
                    pSpawn_0008_guess->pActorInfo_01a8_guess->field48_guess = ground_guess;
                    pSpawn_0008_guess->field38_guess = ground_guess + pSpawn_0008_guess->heightOffset_0238_guess;
                }
                pSpawn_0008_guess->FUN_0048a945_guess();
                break;
            }
            // TrueNorth (56): heading 0 for the spawn and its mount.
            case 0x38:
                pSpawn_0008_guess->heading_guess = 0.0f;
                pSpawn_0008_guess->field58_guess = 0.0f;
                if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0 && pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
                    MagicStateA_guess* mount_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess;
                    mount_guess->heading_guess = 0.0f;
                    mount_guess->field58_guess = 0.0f;
                }
                break;
            case 0x34:
                if (searchA_guess == -1) {
                    searchA_guess = 3;
                    searchB_guess = 8;
                    searchC_guess = 0xc;
                    strcpy(text_guess, pStringTable->getString(0x30b7, 0));
                }
            case 0x36:
                if (searchA_guess == -1) {
                    searchA_guess = 0x15;
                    strcpy(text_guess, pStringTable->getString(0x30b8, 0));
                }
            case 0x35: {
                if (searchA_guess == -1) {
                    searchA_guess = 0x1b;
                    searchB_guess = 8;
                    searchC_guess = 0x1c;
                    searchD_guess = 0x18;
                    strcpy(text_guess, pStringTable->getString(0x30b9, 0));
                }
                // Sense effects turn the player (and mount) toward the nearest match: SenseDead body types 3,
                // 8, 12; SenseAnimals 21; SenseSummoned 27, 8, 28, 24. 0x30BA when none.
                MagicStateA_guess* found_guess = (MagicStateA_guess*)FindClosest_guess(
                    1, searchA_guess, searchB_guess, searchC_guess, searchD_guess);
                if (found_guess != 0) {
                    g_magicCurrent_guess = found_guess;
                    pSpawn_0008_guess->heading_guess =
                        HeadingToPoint_guess(pSpawn_0008_guess->position_guess, found_guess->position_guess);
                    if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0) {
                        MagicStateA_guess* mount_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess;
                        if (mount_guess != 0) {
                            mount_guess->heading_guess = HeadingToPoint_guess(
                                mount_guess->position_guess, found_guess->position_guess);
                        }
                    }
                    pEverQuest->dsp_chat(text_guess, 0x108, 1);
                } else {
                    pEverQuest->dsp_chat(pStringTable->getString(0x30ba, 0), 0x121, 1);
                }
                break;
            }
            // DetectTraps: faces the nearest door-list object flagged as a trap.
            case 0x33: {
                MagicHitNode_guess* best_guess = 0;
                int count_guess = g_magicHitNodes_guess->FUN_004904fd_guess();
                for (int nodeIndex_guess = 0; nodeIndex_guess < count_guess; ++nodeIndex_guess) {
                    MagicHitNode_guess* node_guess = g_magicHitNodes_guess->FUN_00490530_guess(nodeIndex_guess);
                    if (node_guess->GetSwitchDamage_guess() != 0) {
                        if (best_guess == 0 ||
                            ((MagicHitSession_guess*)g_magicSession_guess)
                                    ->SimpleDistance_guess(pSpawn_0008_guess->position_guess.y_guess,
                                                         pSpawn_0008_guess->position_guess.x_guess,
                                                         pSpawn_0008_guess->field38_guess,
                                                         node_guess->field38_guess,
                                                         node_guess->field3C_guess,
                                                         node_guess->field40_guess, 0.0f) <
                                ((MagicHitSession_guess*)g_magicSession_guess)
                                    ->SimpleDistance_guess(pSpawn_0008_guess->position_guess.y_guess,
                                                         pSpawn_0008_guess->position_guess.x_guess,
                                                         pSpawn_0008_guess->field38_guess,
                                                         best_guess->field38_guess,
                                                         best_guess->field3C_guess,
                                                         best_guess->field40_guess, 0.0f)) {
                            best_guess = node_guess;
                        }
                    }
                }
                if (best_guess != 0) {
                    pSpawn_0008_guess->heading_guess = get_bearing_guess(
                        pSpawn_0008_guess->position_guess.y_guess, pSpawn_0008_guess->position_guess.x_guess,
                        best_guess->field38_guess, best_guess->field3C_guess);
                    if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
                        pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
                        pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->heading_guess =
                            pSpawn_0008_guess->heading_guess;
                    }
                    pEverQuest->dsp_chat(pStringTable->getString(0x30bb, 0), 0x10e, 1);
                } else {
                    pEverQuest->dsp_chat(pStringTable->getString(0x30bc, 0), 0x10e, 1);
                }
                break;
            }
            // Identify (61, 62): "Item Lore: %1." for the cursor item, with any leading ~ * # & ! marks
            // removed, and for a book (item class 2) the language it is written in.
            case 0x3d:
            case 0x3e:
                strcpy(text_guess, pStringTable->getString(0x30a4, 0));
                if (ResolveResult_guess()->values10_guess[30] != 0) {
                    strcpy(nameBuffer_guess,
                           ((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                               ->FUN_005e0ee0_guess());
                    if (nameBuffer_guess[0] != '~' && nameBuffer_guess[0] != '*' &&
                        nameBuffer_guess[0] != '#' && nameBuffer_guess[0] != '&' &&
                        nameBuffer_guess[0] != '!') {
                        FUN_0046da4a_guess(text_guess, 0x1a6d,
                                           ((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                                               ->FUN_005e0ee0_guess(),
                                           0, 0, 0, 0, 0, 0, 0, 0);
                    } else {
                        FUN_0046da4a_guess(text_guess, 0x1a6d,
                                           (nameBuffer_guess[1] == '~' || nameBuffer_guess[1] == '*' ||
                                            nameBuffer_guess[1] == '#' || nameBuffer_guess[1] == '&' ||
                                            nameBuffer_guess[1] == '!')
                                               ? &nameBuffer_guess[2]
                                               : &nameBuffer_guess[1],
                                           0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    if (((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                            ->GetItemClass_guess() == 2) {
                        FUN_0046da4a_guess(
                            record_guess.text_guess, 0x30a2,
                            ((MagicHitRouter_guess*)pEverQuest)
                                ->GetLangDesc_guess(
                                    ((MagicHitItem_guess*)ResolveResult_guess()->values10_guess[30])
                                        ->FUN_005e0e60_guess()),
                            0, 0, 0, 0, 0, 0, 0, 0);
                        pEverQuest->dsp_chat(record_guess.text_guess);
                    }
                    pEverQuest->dsp_chat(text_guess, 0x108, 1);
                }
                break;
            case 0x44:
            case 0x5b:
                break;
            // PreserveCorpse (72) needs a corpse target (type >= 2): sends message 0x4672 (no EQEmu name)
            // with its spawn id and prints "%1 looks as if it's been freshened up a bit."; without one,
            // "Nothing happens."
            case 0x48:
                if (g_magicCurrent_guess == 0 || g_magicCurrent_guess->type_0244_guess < 2) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x306f, 0), 0x111, 1);
                } else {
                    EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), 0x4672,
                                  &g_magicCurrent_guess->spawnId_0258_guess, 4, 1);
                    FUN_0046da4a_guess(text_guess, 0x30a1, g_magicCurrent_guess->name120_guess, 0, 0, 0,
                                       0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(text_guess, 0x111, 1);
                }
                break;
            // FeignDeath (74), then LocateCorpse (77): targets the corpse matching the current target's name
            // (or the nearest one) and turns us to face it.
            case 0x4a:
                CheckState_guess(spellId_guess, amount_guess);
                break;
            case 0x4d:
                eqspa_locate_corpse_guess();
                break;
            // Teleport (83, 145) to the spell's zone (+0x210) and coordinates; another zone is a zone change
            // with a portal-spell reason. Spell 1476 keeps the given z instead of dropping to the floor.
            case 0x53:
            case 0x91:
                if (pSpawn_0008_guess->type_0244_guess != 0) {
                    return;
                }
                if (pc_guess == 0) {
                    return;
                }
                if (strlen(spell_guess->field210_guess) > 0) {
                    self_guess->pActorInfo_01a8_guess->field158_guess = 0;
                    pc_guess->GetBase_guess()->bufferBC_guess.Copy_guess("");
                    float y_guess = (float)spell_guess->values30_guess[0];
                    float x_guess = (float)spell_guess->values30_guess[1];
                    float z_guess = (float)spell_guess->values30_guess[2];
                    int heading_guess = (int)(float)spell_guess->values30_guess[3];
                    self_guess->PlaySound_guess(0x89);
                    int zone_guess = g_magicZoneCheck_guess->FUN_005f6f20_guess(spell_guess->field210_guess);
                    if (GetTable_guess()->field100_guess != zone_guess) {
                        ((MagicHitRouter_guess*)pEverQuest)
                            ->MoveToZone_guess(zone_guess, "portal spell", 0, 7, y_guess, x_guess,
                                                 z_guess, heading_guess);
                    } else {
                        self_guess->position_guess.y_guess = y_guess;
                        self_guess->position_guess.x_guess = x_guess;
                        self_guess->field38_guess = z_guess;
                        FUN_004b718d_guess()->FUN_004b70db_guess(&self_guess->position_guess, 3);
                        MagicTable_guess* table_guess = GetTable_guess();
                        table_guess->field2C_guess = y_guess;
                        table_guess->field30_guess = x_guess;
                        table_guess->field34_guess = z_guess;
                        self_guess->heading_guess = (float)heading_guess;
                        GetTable_guess()->field38_guess = (float)heading_guess;
                        if (spellId_guess != 0x5c4) {
                            float ground_guess = self_guess->GetFloorHeightAt_guess(
                                self_guess->position_guess.y_guess, self_guess->position_guess.x_guess,
                                self_guess->field38_guess, 1);
                            if (ground_guess != g_magicNoGround_guess) {
                                self_guess->pActorInfo_01a8_guess->field48_guess = ground_guess;
                                self_guess->field38_guess = ground_guess + self_guess->heightOffset_0238_guess;
                            }
                        }
                        self_guess->FUN_0048a945_guess();
                    }
                }
                break;
            case 0x23:
            case 0x24:
            case 0x74:
                if (amount_guess < 0) {
                    int type_guess = spell_guess->GetType_guess(index_guess);
                    MagicEntryProbe_guess* entry_guess = FindBuffWithEffect_guess(type_guess, 0);
                    if (entry_guess != 0) {
                        MagicCheck_guess* other_guess = g_magicLookup_guess->GetSpell_guess(entry_guess->id_guess);
                        if (other_guess != 0) {
                            int otherSlot_guess;
                            for (otherSlot_guess = 0; otherSlot_guess < 12; ++otherSlot_guess) {
                                if (other_guess->GetType_guess(otherSlot_guess) == type_guess) {
                                    break;
                                }
                            }
                            CalcAffectChange_guess(other_guess, entry_guess->casterLevel_0001_guess, otherSlot_guess, 0);
                            // Disease, poison and curse counters (35, 36, 116): a negative amount comes off
                            // the counter (+0xC) of the first buff with that effect, and the buff ends at 0.
                            entry_guess->counters_000c_guess += amount_guess;
                            if (entry_guess->counters_000c_guess < 1) {
                                ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)entry_guess);
                            }
                        }
                    }
                }
                break;
            case 0xa0:
                if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
                    MagicHitPc_guess* owner_guess = (MagicHitPc_guess*)GetTable_guess()->GetObject_guess();
                    // MakeDrunk (160), players only: intoxication rises by |amount| / (Alcohol Tolerance / 50
                    // + 1), at most 200.
                    int gain_guess = FUN_0060f81e_guess(amount_guess) /
                                     ((int)ResolveResult_guess()->valuesF70_guess[66] / 50 + 1);
                    owner_guess->FUN_005ed570_guess(owner_guess->FUN_005ed550_guess() + gain_guess);
                    if (owner_guess->FUN_005ed550_guess() > 200) {
                        owner_guess->FUN_005ed570_guess(200);
                    }
                }
                break;
            // CurrentEndurance (189): +0x11AC is the endurance pool (0x0040E2BD adds to it).
            case 0xbd:
                ((CharacterMagicSystem_guess*)GetTable_guess())->AddField11AC_guess(amount_guess);
                Cur_Endurance_guess();
                break;
            }
        }
    } else {
        // Spells with a duration: FindSlot_guess picks the buff slot by the stacking rules. The entry gets
        // spell, level, amount, scale 10 (unscaled) and counters from +0x1D0/+0x1D4; active is 4 for our own
        // lifetap buff, else 2. Each effect slot then sets up its standing state.
        int outIndex_guess;
        GetBuffLevelBySpell_guess(spellId_guess);
        MagicEntryProbe_guess* entry_guess = FindBuffSlot_guess(spellId_guess, caster_guess, &outIndex_guess, 0);
        if (entry_guess != 0) {
            entry_guess->counters_000c_guess = 0;
            float scaleFactor_guess = 1.0f;
            ((CharacterMagicSystem_guess*)GetTable_guess())
                ->SetBuffCasterId_guess(outIndex_guess, caster_guess->spawnId_0258_guess);
            if ((spell_guess->field180_guess == 0xd || spell_guess->field180_guess == 0x14) &&
                caster_guess == pSpawn_0008_guess) {
                entry_guess->active_guess = 4;
            } else {
                entry_guess->active_guess = 2;
            }
            entry_guess->id_guess = spellId_guess;
            entry_guess->casterLevel_0001_guess = level_guess;
            entry_guess->unknown08_guess = amount_guess;
            entry_guess->scale_guess = 10;
            entry_guess->unknown10_guess = 0;
            entry_guess->padTo04_guess[1] = spell_guess->field17E_guess;
            if (caster_guess->type_0244_guess == 0 && caster_guess->pCharInfo_0218_guess != 0) {
                entry_guess->unknown10_guess =
                    ((MagicHitPc_guess*)caster_guess->GetPcClient_guess())->fieldE54_guess;
            }
            if (spell_guess->field1D0_guess > 0 && spell_guess->field1D4_guess > 0) {
                entry_guess->counters_000c_guess = spell_guess->field1D4_guess;
                if (spell_guess->field1D0_guess == 4 && caster_guess == pSpawn_0008_guess) {
                    entry_guess->counters_000c_guess = spell_guess->field1D4_guess + 1;
                }
            }
            fieldC8_guess = 0;
            for (unsigned char slot_guess = 0; slot_guess < 12; ++slot_guess) {
                if (pSpawn_0008_guess == 0) {
                    return;
                }
                unsigned int index_guess = slot_guess;
                if (CheckMagic_guess((MagicQuery_guess*)spell_guess, index_guess) == 0) {
                    continue;
                }
                amount_guess = CalcAffectChange_guess(spell_guess, level_guess, slot_guess, 0);
                // Bard songs (class 8) scale every effect but illusions and a few others by the instrument
                // modifier.
                if (caster_guess->playerClass_0252_guess == 8 && spell_guess->GetType_guess(index_guess) != 0x3a &&
                    spell_guess->GetType_guess(index_guess) != 0x9c &&
                    spell_guess->GetType_guess(index_guess) != 0x1e &&
                    spell_guess->GetType_guess(index_guess) != 0x11 &&
                    spell_guess->GetType_guess(index_guess) != 0x12 &&
                    spell_guess->GetType_guess(index_guess) != 0x56) {
                    int scale_guess = packet_guess->scale_guess;
                    if (scale_guess > 0 && scale_guess <= 0x2d) {
                        scaleFactor_guess = (float)scale_guess * g_magicScale_guess;
                        amount_guess = (int)((float)amount_guess * scaleFactor_guess);
                    }
                }
                switch (spell_guess->GetType_guess(index_guess)) {
                // MovementSpeed (3): takes effect at once unless a Root (99) is active.
                case 3:
                    if (scaleFactor_guess != 1.0f) {
                        entry_guess->scale_guess = (unsigned char)packet_guess->scale_guess;
                        fieldC8_guess = 0;
                    }
                    if (TotalSpellAffects_guess(99, true, 0, 1) == 0) {
                        ApplyMovementModifier_guess(TotalSpellAffects_guess(3, true, 0, 1));
                    }
                    break;
                case 0xd:
                    UpdateAllPlayersVisibility_guess();
                    break;
                case 0xc:
                case 0x1c:
                case 0x1d:
                case 0x13a:
                case 0x13b:
                case 0x13c:
                    UpdateInvisibility_guess();
                    break;
                // Charm (22) cast by ourselves stops here; Charm from others and Fear (23) call 0x00479D72 on
                // the spawn.
                case 0x16:
                    if (pSpawn_0008_guess == caster_guess) {
                        return;
                    }
                case 0x17:
                    pSpawn_0008_guess->FUN_00479d72_guess();
                    break;
                case 0x14:
                case 0x22:
                    pSpawn_0008_guess->pActorInfo_01a8_guess->field154_guess = 1;
                    break;
                // Mez: a refused mez tells the caster (0xEF or 0xF0); otherwise the target and its mount
                // stop.
                case 0x1f: {
                    int result_guess =
                        FUN_00417834_guess(spell_guess->Get90_guess(index_guess), caster_guess, spell_guess);
                    if (result_guess != 0) {
                        if (caster_guess->type_0244_guess == 0) {
                            MagicHitPc_guess* casterPc_guess =
                                (MagicHitPc_guess*)caster_guess->GetPcClient_guess();
                            if (casterPc_guess != 0) {
                                if (result_guess == 1) {
                                    token_string_to_client_guess(casterPc_guess, 0xef, 0x121, 0);
                                } else {
                                    token_string_to_client_guess(casterPc_guess, 0xf0, 0x121, 0);
                                }
                            }
                        }
                    } else {
                        if (pSpawn_0008_guess != 0) {
                            pSpawn_0008_guess->speedRun_0048_guess = 0.0f;
                            if (pSpawn_0008_guess->pActorInfo_01a8_guess != 0 &&
                                pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
                                pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->speedRun_0048_guess = 0.0f;
                            }
                        }
                        GetTable_guess()->fieldFC_guess = 1;
                    }
                    break;
                }
                // SpinTarget (64): a standing target starts to spin (+0x58 = 32).
                case 0x40:
                    if (pSpawn_0008_guess->standState_0251_guess == 100) {
                        pSpawn_0008_guess->field58_guess = 32.0f;
                    }
                    break;
                case 0x3a:
                    if (ActivateEffect_guess((MagicCaster_guess*)spell_guess, spellId_guess, amount_guess,
                                             (int)entry_guess, 0) == 0) {
                        return;
                    }
                    break;
                case 0x39:
                    Refresh_guess();
                    break;
                case 0x41:
                    ResolveResult_guess()->values1100_guess[6] = 0;
                    break;
                case 0x42:
                    ResolveResult_guess()->values1100_guess[13] = 0;
                    break;
                // Root (99): movement speed is set from the amount. The caster's SPA 244 total is only
                // logged, under the name "POP_AA_EnhancedRootOnMe".
                case 0x63:
                    if (caster_guess->pCharInfo_0218_guess != 0) {
                        FUN_00451a94_guess("POP_AA_EnhancedRootOnMe",
                                           caster_guess->pCharInfo_0218_guess->TotalSpellAffects_guess(
                                               0xf4, true, 0, 1));
                    }
                    ApplyMovementModifier_guess(amount_guess);
                    break;
                case 0x57:
                    g_magicSession_guess->FUN_00440f51_guess(amount_guess);
                    break;
                case 0x4d:
                    eqspa_locate_corpse_guess();
                    break;
                // BindSight needs a target (0xD6 and the buff is cleared without one).
                case 0x49:
                    if (g_magicCurrent_guess != 0) {
                        g_magicSession_guess->SetViewActorByName_guess(g_magicCurrent_guess->values120_guess);
                    } else {
                        token_string_to_client_guess(this, 0xd6, 0x121, 0);
                        entry_guess->id_guess = -1;
                        entry_guess->active_guess = 0;
                        entry_guess->casterLevel_0001_guess = 0;
                        entry_guess->unknown08_guess = 0;
                        entry_guess->scale_guess = 0;
                        entry_guess->counters_000c_guess = 0;
                        fieldC8_guess = 0;
                        return;
                    }
                    break;
                case 0x23:
                case 0x24:
                case 0x74:
                    if (amount_guess > 0) {
                        entry_guess->counters_000c_guess = amount_guess;
                    } else if (amount_guess < 0) {
                        // A positive amount sets this buff's counter. A negative one (a lasting cure) works
                        // one time in ten,
                        // and only when the afflicting buff's strength plus the cure is under 7: its counter
                        // drops by the cure, string 265 when that buff goes.
                        if (RandomRange_guess(1, 100) <= 10) {
                            MagicEntryProbe_guess* other_guess =
                                FindBuffWithEffect_guess(spell_guess->GetType_guess(index_guess), 0);
                            if (other_guess != 0) {
                                MagicCheck_guess* otherSpell_guess =
                                    g_magicLookup_guess->GetSpell_guess(other_guess->id_guess);
                                if (otherSpell_guess != 0) {
                                    int otherAmount_guess = CalcAffectChange_guess(
                                        otherSpell_guess, other_guess->casterLevel_0001_guess, slot_guess, 0);
                                    if (otherAmount_guess > 0 && otherAmount_guess + amount_guess < 7) {
                                        other_guess->counters_000c_guess += amount_guess;
                                        if (other_guess->counters_000c_guess < 1) {
                                            ((Wrap411F2F_guess*)this)->RemovePCAffect_guess((int)other_guess);
                                            if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
                                                token_string_to_client_guess(this, 0x109, 0x111, 0);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                // Rune (55), AbsorbMagicAtt (78) and NegateAttacks (163) start the buff's counter (+0xC) at
                // the amount; 161 and 162 (spell and melee mitigation) start it from the effect's +0x90
                // value. TakeDamage spends it.
                case 0x37:
                case 0x4e:
                case 0xa3:
                    entry_guess->counters_000c_guess = amount_guess;
                    break;
                case 0xa1:
                case 0xa2:
                    entry_guess->counters_000c_guess = spell_guess->Get90_guess(index_guess);
                    break;
                case 0x9c:
                    break;
                case 0xa0:
                    if (pSpawn_0008_guess != 0 && pSpawn_0008_guess->type_0244_guess == 0) {
                        MagicHitPc_guess* owner_guess = (MagicHitPc_guess*)GetTable_guess()->GetObject_guess();
                        amount_guess = FUN_0060f81e_guess(amount_guess) /
                                       ((int)ResolveResult_guess()->valuesF70_guess[66] / 50 + 1);
                        owner_guess->FUN_005ed570_guess(owner_guess->FUN_005ed550_guess() + amount_guess);
                        if (owner_guess->FUN_005ed550_guess() > 200) {
                            owner_guess->FUN_005ed570_guess(200);
                        }
                    }
                    break;
                // SPA 198: a one-time change of endurance (+0x11AC) when the buff lands.
                case 0xc6:
                    ((CharacterMagicSystem_guess*)GetTable_guess())->AddField11AC_guess(amount_guess);
                    Cur_Endurance_guess();
                    break;
                default:
                    if (scaleFactor_guess != 1.0f) {
                        entry_guess->scale_guess = (unsigned char)packet_guess->scale_guess;
                        fieldC8_guess = 0;
                    }
                    break;
                }
            }
        }
    }

    // Push-back (+0xC) and push-up (+0x10) along the caster's heading, applied to the mount when riding; the
    // moved flags make the next position update go out.
    if (spell_guess->field0C_guess != 0.0f || spell_guess->field10_guess != 0.0f) {
        FUN_004b718d_guess()->FUN_004b70db_guess(&pSpawn_0008_guess->position_guess, 7);
        if (pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess != 0) {
            MagicStateA_guess* mount_guess = pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess;
            mount_guess->field3C_guess =
                g_magicHitTrig_guess->Cos_guess(packet_guess->fieldE_guess) * spell_guess->field0C_guess +
                pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->field3C_guess;
            pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->field40_guess =
                g_magicHitTrig_guess->Sin_guess(packet_guess->fieldE_guess) * spell_guess->field0C_guess +
                pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->field40_guess;
            pSpawn_0008_guess->pActorInfo_01a8_guess->field15C_guess->field44_guess += spell_guess->field10_guess;
        } else {
            pSpawn_0008_guess->field3C_guess +=
                g_magicHitTrig_guess->Cos_guess(packet_guess->fieldE_guess) * spell_guess->field0C_guess;
            pSpawn_0008_guess->field40_guess +=
                g_magicHitTrig_guess->Sin_guess(packet_guess->fieldE_guess) * spell_guess->field0C_guess;
            pSpawn_0008_guess->field44_guess += spell_guess->field10_guess;
        }
        if (pSpawn_0008_guess == g_magicWorld_guess && g_magicWorld_guess != g_magicLinked_guess) {
            g_magicHitMoved_guess = 1;
        } else if (pSpawn_0008_guess == g_magicLinked_guess) {
            g_magicHitMovedLinked_guess = 1;
        }
    }
    fieldC_guess = 1;
}
