// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 38: a hint from compare/tumap.py.
// EQ_Spell: one spells_us.txt record (0x270 bytes), parsed from its '^' line, plus the spell effect tables
// (spells.eff: 256 entries of 0xAE8 bytes at 0x8513B8; SpellsNew.eff: 0x10C-byte records), the SPA sets for
// focus and stacking, and the built-in particle records. EQ_SpellView_guess and FUN_0044d103_owner_guess
// are views of the same EQ_Spell; SpellEffectView_guess is a spells.eff entry (SpellEffect_guess).
#include "titanium/eqaddr.h"
#include <stdio.h>

#define g_spellEffects_guess EQ_ARRAY(char, 0x008513B8)

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message, ...);

struct EQ_SpellView_guess {
    char pad_000_guess[0x208];
    void* name_0208_guess;
    void* player1_020c_guess;
    void* teleportZone_0210_guess;
    void* youCast_0214_guess;
    void* otherCasts_0218_guess;
    void* castOnYou_021c_guess;
    void* castOnOther_0220_guess;
    void* spellFades_0224_guess;
    char pad_228_guess[8];
    int spellAffectIndex_0230_guess;

    bool FUN_0044ced9_guess();
    void FreeStrings_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// True when the spells.eff index (+0x230) is 61-64; tu_053 and tu_062 test it on cast and action packets.
// FUNCTION: TITANIUM 0x0044CED9
bool EQ_SpellView_guess::FUN_0044ced9_guess() {
    return spellAffectIndex_0230_guess >= 0x3d && spellAffectIndex_0230_guess <= 0x40;
}

// Frees the eight strings ParseFromText_guess copies: the name and the seven other text fields.
// FUNCTION: TITANIUM 0x0044CEF0
void EQ_SpellView_guess::FreeStrings_guess() {
    free(name_0208_guess);
    free(player1_020c_guess);
    free(teleportZone_0210_guess);
    free(youCast_0214_guess);
    free(otherCasts_0218_guess);
    free(castOnYou_021c_guess);
    free(castOnOther_0220_guess);
    free(spellFades_0224_guess);
}

// SPAs the buff-stacking test skips: SeeInvis 13, the counters 35, 36 and 116, Levitate 57, Infra- and
// UltraVision 65-66, CurrentHPOnce 79, the focus and limit ids 124-144, the stacking commands 148-149,
// 254 Blank, and 167, 235, 286-287, 296-297, 302-303, 310-311, 335 and 348.
// FUNCTION: TITANIUM 0x0044CF50
char __cdecl IsEffectIgnoredInStacking_guess(int value) {
    if (value <= 0xa7) {
        if (value == 0xa7) return 1;
        if (value <= 0x4f) {
            return value == 0x4f || value == 0xd ||
                (value > 0x22 && (value <= 0x24 || value == 0x39 ||
                    (value > 0x40 && value <= 0x42)));
        }
        return value == 0x74 || (value > 0x7b &&
            (value <= 0x90 || (value > 0x93 && value <= 0x95)));
    } else {
        if (value <= 0x12f) {
            return value >= 0x12e || value == 0xeb || value == 0xfe ||
                (value > 0x11d && (value <= 0x11f ||
                    (value > 0x127 && value <= 0x129)));
        }
        return value >= 0x136 &&
            (value <= 0x137 || value == 0x14f || value == 0x15c);
    }
}

// Focus SPAs: 124-133 (IncreaseSpellHaste and the other Increase/Reduce foci), 167, 235, 286-287,
// 296-297, 302-303, 310, 335 and 339. tu_011 uses it to find where an AA's focus record and its limits end.
// FUNCTION: TITANIUM 0x0044D011
char __cdecl IsFocusEffect_guess(int value) {
    if (value <= 0x129) {
        if (value >= 0x128) return 1;
        if (value < 0x7c) return 0;
        if (value <= 0x85) return 1;
        if (value == 0xa7) return 1;
        if (value == 0xeb) return 1;
        if (value <= 0x11d) return 0;
        if (value <= 0x11f) return 1;
    } else {
        if (value < 0x12e) return 0;
        if (value <= 0x12f) return 1;
        if (value == 0x136) return 1;
        if (value == 0x14f) return 1;
        if (value == 0x153) return 1;
    }
    return 0;
}

// Dumps the spells.eff table (256 x 0xAE8 bytes); GetEffFiles_guess calls it when the file is missing,
// so a fresh install gets an all-empty spells.eff.
// FUNCTION: TITANIUM 0x0044D074
int __cdecl WriteSpellEffects_guess() {
    FILE* file = fopen("spells.eff", "wb");
    if (file != 0) {
        if (fwrite(g_spellEffects_guess, 0xae8, 0x100, file) != 0x100) {
            FUN_00574110_guess("Error writing spell effect table\n");
        }
        fclose(file);
        return 1;
    }
    FUN_00574110_guess("Error opening spells.eff to write\n");
    return 0;
}

template <class T, int N>
struct CheckedArray_guess {
    union {
        T data_guess[N];
        char bytes_guess[N * sizeof(T)];
    };
    T& operator[](int offset_guess) {
        if ((unsigned int)offset_guess >= (unsigned int)(N * sizeof(T))) {
            __debugbreak();
        }
        return *(T*)(bytes_guess + offset_guess);
    }
};

struct EQ_Spell_guess {
    int id_0000_guess;                 // 0x000
    float range_0004_guess;               // 0x004
    float aeRange_0008_guess;               // 0x008
    float pushBack_000c_guess;               // 0x00C
    float pushUp_0010_guess;               // 0x010
    int castTime_0014_guess;                 // 0x014
    int recoveryTime_0018_guess;                 // 0x018
    int recastTime_001c_guess;                 // 0x01C
    int durationFormula_0020_guess;                 // 0x020
    int duration_0024_guess;                 // 0x024
    int aeDuration_0028_guess;                 // 0x028
    int mana_002c_guess;                 // 0x02C
    CheckedArray_guess<int, 12> base_0030_guess;   // 0x030
    CheckedArray_guess<int, 12> base2_0060_guess;   // 0x060
    CheckedArray_guess<int, 12> max_0090_guess;   // 0x090
    CheckedArray_guess<int, 4> components_00c0_guess;    // 0x0C0
    CheckedArray_guess<int, 4> componentCounts_00d0_guess;    // 0x0D0
    CheckedArray_guess<int, 4> noExpendReagents_00e0_guess;    // 0x0E0
    CheckedArray_guess<int, 12> formula_00f0_guess;   // 0x0F0
    CheckedArray_guess<int, 12> effectIds_0120_guess;   // 0x120
    CheckedArray_guess<unsigned char, 0x24> classLevels_0150_guess; // 0x150
    int icon_0174_guess;                 // 0x174
    int memIcon_0178_guess;                 // 0x178
    char lightType_017c_guess;                // 0x17C
    char goodEffect_017d_guess;                // 0x17D
    char activated_017e_guess;                // 0x17E
    char resistType_017f_guess;                // 0x17F
    char targetType_0180_guess;                // 0x180
    char baseDifficulty_0181_guess;                // 0x181
    char skill_0182_guess;                // 0x182
    char zoneType_0183_guess;                // 0x183
    char environmentType_0184_guess;                // 0x184
    char timeOfDay_0185_guess;                // 0x185
    char castingAnim_0186_guess;                // 0x186
    char targetAnim_0187_guess;                // 0x187
    char travelType_0188_guess;                // 0x188
    char disallowSit_0189_guess;                // 0x189
    int descNum_018c_guess;                 // 0x18C
    char field_190_guess;                // 0x190
    char uninterruptable_0191_guess;                // 0x191
    char dotStackingExempt_0192_guess;                // 0x192
    char deletable_0193_guess;                // 0x193
    int recourseLink_0194_guess;                 // 0x194
    char noPartialResist_0198_guess;                // 0x198
    char field_199_guess;                // 0x199
    char field_19a_guess;                // 0x19A
    char shortBuffBox_019b_guess;                // 0x19B
    int typeDescNum_019c_guess;                 // 0x19C
    int effectDescNum_01a0_guess;                 // 0x1A0
    int field_1a4_guess;                 // 0x1A4
    char field_1a8_guess;                // 0x1A8
    char field_1a9_guess;                // 0x1A9
    char field_1aa_guess;                // 0x1AA
    int field_1ac_guess;                 // 0x1AC
    int field_1b0_guess;                 // 0x1B0
    int field_1b4_guess;                 // 0x1B4
    char field_1b8_guess;                // 0x1B8
    int field_1bc_guess;                 // 0x1BC
    int field_1c0_guess;                 // 0x1C0
    char field_1c4_guess;                // 0x1C4
    int field_1c8_guess;                 // 0x1C8
    int field_1cc_guess;                 // 0x1CC
    int field_1d0_guess;                 // 0x1D0
    int field_1d4_guess;                 // 0x1D4
    int field_1d8_guess;                 // 0x1D8
    int field_1dc_guess;                 // 0x1DC
    int field_1e0_guess;                 // 0x1E0
    int field_1e4_guess;                 // 0x1E4
    int field_1e8_guess;                 // 0x1E8
    int field_1ec_guess;                 // 0x1EC
    int field_1f0_guess;                 // 0x1F0
    int field_1f4_guess;                 // 0x1F4
    int field_1f8_guess;                 // 0x1F8
    char field_1fc_guess;                // 0x1FC
    char field_1fd_guess;                // 0x1FD
    char field_1fe_guess;                // 0x1FE
    int field_200_guess;                 // 0x200
    char field_204_guess;                // 0x204
    int name_0208_guess;                 // 0x208
    int player1_020c_guess;                 // 0x20C
    int teleportZone_0210_guess;                 // 0x210
    int youCast_0214_guess;                 // 0x214
    int otherCasts_0218_guess;                 // 0x218
    int castOnYou_021c_guess;                 // 0x21C
    int castOnOther_0220_guess;                 // 0x220
    int spellFades_0224_guess;                 // 0x224
    char field_228_guess;                // 0x228
    int spellAffect_022c_guess;                 // 0x22C
    int spellAffectIndex_0230_guess;                 // 0x230
    int spellEffect_0234_guess;                 // 0x234
    int spellAnim_0238_guess;                 // 0x238
    int deityMask_023c_guess;                 // 0x23C
    char npcNoCast_0240_guess;                // 0x240
    int field_244_guess;                 // 0x244
    int newIcon_0248_guess;                 // 0x248
    int resistDiff_024c_guess;                 // 0x24C
    int field_250_guess;                 // 0x250
    int field_254_guess;                 // 0x254
    int field_258_guess;                 // 0x258
    int field_25c_guess;                 // 0x25C
    int field_260_guess;                 // 0x260
    int field_264_guess;                 // 0x264
    char field_268_guess;                // 0x268
    char field_269_guess;                // 0x269
    char field_26a_guess;                // 0x26A
    int spellEffectIndex_026c_guess;                 // 0x26C

    char FUN_0044d0e6_guess();
    int KeepsInvisibility_guess();
    void ClearSpellData_guess();
    EQ_Spell_guess* ParseFromText_guess(char* data);

};

// True for a valid spell id (1-9999).
// FUNCTION: TITANIUM 0x0044D0D0
char __cdecl IsValidSpellIndex_guess(int value) {
    return value >= 1 && value < 10000;
}

// +0x268: tu_012 refuses such a spell (string 9240) unless the cast state's +0x250 is 1.
// FUNCTION: TITANIUM 0x0044D0E6
char EQ_Spell_guess::FUN_0044d0e6_guess() {
    return field_268_guess;
}

// True when casting the spell keeps the caster invisible (+0x268 or +0x1FC). When false, tu_012's cast
// code drops Invisibility 12, InvisVsUndead 28, InvisVsAnimals 29, NegateIfCombat 94 and 314/315
// (probably the later invisibility variants).
// FUNCTION: TITANIUM 0x0044D0ED
int EQ_Spell_guess::KeepsInvisibility_guess() {
    return field_268_guess != 0 || field_1fc_guess != 0;
}

struct SpellEffectView_guess {
    char pad_000_guess[8];
    char objects_008_guess[0x3a0 * 3];

    SpellEffectView_guess();
};

// EXTERNAL: TITANIUM 0x0044CEBD FUN_0044cebd_guess
void __cdecl FUN_0044cebd_guess(void* object);

// EXTERNAL: TITANIUM 0x00401000 vector_constructor_iterator_guess
void __stdcall vector_constructor_iterator_guess(
    void* destination, unsigned int size, int count,
    void (__cdecl *constructor)(void*));

// spells.eff entry: three 0x3A0-byte effect slots, built by 0x44CEBD.
// FUNCTION: TITANIUM 0x0044D192
SpellEffectView_guess::SpellEffectView_guess() {
    vector_constructor_iterator_guess(objects_008_guess, 0x3a0, 3,
        FUN_0044cebd_guess);
}

struct FUN_0044d1ae_record_guess {
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    float field_00c_guess;
    float field_010_guess;
    float field_014_guess;
    float field_018_guess;
    float field_01c_guess;
    float field_020_guess;
    float field_024_guess;
    float field_028_guess;
    float field_02c_guess;
    float field_030_guess;
    int field_034_guess;
    int field_038_guess;
    float field_03c_guess;
    float field_040_guess;
    float field_044_guess;
    float field_048_guess;
    float field_04c_guess;
    float field_050_guess;
    float field_054_guess;
    float field_058_guess;
    float field_05c_guess;
    float field_060_guess;
    float field_064_guess;
    int field_068_guess;
    float field_06c_guess;
    int field_070_guess;
    float field_074_guess;
    float field_078_guess;
    int field_07c_guess;
    int field_080_guess;
};

#define g_d1ae_init_test_guess EQ_GLOBAL(unsigned char, 0x008ffbc4)
#define g_d1ae_init_flags_guess EQ_GLOBAL(unsigned int, 0x008ffbc4)
#define g_d1ae_x_guess EQ_GLOBAL(float, 0x008ffbb8)
#define g_d1ae_y_guess EQ_GLOBAL(float, 0x008ffbbc)
#define g_d1ae_z_guess EQ_GLOBAL(float, 0x008ffbc0)
#define g_d1ae_records_guess EQ_ARRAY(FUN_0044d1ae_record_guess*, 0x00903ec0)
#define g_d1ae_value_a_guess EQ_GLOBAL(float, 0x00644368)
#define g_d1ae_value_b_guess EQ_GLOBAL(float, 0x00640e58)

// Builds the 7 built-in particle records (0x84 bytes each) in slots 0-6 of the 64-slot table at 0x903EC0;
// the zone loader calls it at its visual-effects step. The static (0, 0, -1) is their default
// direction.
// FUNCTION: TITANIUM 0x0044D1AE
// @early-stop: unknown, structural ndiff=204
int __cdecl CreatePartEffects_guess() {
    int index_guess;
    int sentinel_guess = -1;
    FUN_0044d1ae_record_guess* record_guess;

    // Function-local static, set once: the default direction (0, 0, -1).
    if ((g_d1ae_init_test_guess & 1) == 0) {
        g_d1ae_init_flags_guess |= 1;
        g_d1ae_x_guess = 0.0f;
        g_d1ae_z_guess = -1.0f;
        g_d1ae_y_guess = 0.0f;
    }

    // Empty all 64 slots, then fill 0-6. Every record has +0x00 = 3, +0x04 = 0x701, the default
    // direction at +0x10, +0x78 = 1.0 and +0x7C = -1; they differ in the fields noted at each slot.
    for (index_guess = 0; index_guess != 0x40; ++index_guess) {
        g_d1ae_records_guess[index_guess] = 0;
    }

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 500;
    record_guess->field_00c_guess = 0.0f;
    record_guess->field_000_guess = 3;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 3;
    record_guess->field_038_guess = 0x640;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_05c_guess = -1.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = 0.0f;
    record_guess->field_064_guess = 20.0f;
    record_guess->field_068_guess = 1000;
    record_guess->field_06c_guess = 3.0f;
    record_guess->field_078_guess = 1.0f;
    record_guess->field_070_guess = 0x14;
    record_guess->field_074_guess = 0.05f;
    record_guess->field_07c_guess = sentinel_guess;
    // Slot 0: +0x08 500, +0x34 3, +0x38 1600, +0x5C -1, 20 at +0x64 and +0x70, +0x6C 3, +0x74 0.05.
    g_d1ae_records_guess[0] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_00c_guess = 0.0f;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 1000;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 1;
    record_guess->field_038_guess = 0x640;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_05c_guess = 0.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_064_guess = 0.0f;
    record_guess->field_060_guess = 5.0f;
    record_guess->field_068_guess = 1000;
    record_guess->field_06c_guess = 3.0f;
    record_guess->field_078_guess = 1.0f;
    record_guess->field_070_guess = 2;
    record_guess->field_074_guess = 0.05f;
    record_guess->field_07c_guess = sentinel_guess;
    // Slot 1: +0x08 1000, +0x34 1, +0x5C 0, 5 at +0x60 instead of +0x64, +0x70 2.
    g_d1ae_records_guess[1] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 500;
    record_guess->field_00c_guess = 5.0f;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 3;
    record_guess->field_038_guess = 0x640;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_05c_guess = 1.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = 0.0f;
    record_guess->field_064_guess = 20.0f;
    record_guess->field_068_guess = 1000;
    record_guess->field_06c_guess = 7.0f;
    record_guess->field_078_guess = 1.0f;
    record_guess->field_070_guess = 0x14;
    record_guess->field_074_guess = 0.05f;
    record_guess->field_07c_guess = sentinel_guess;
    // Slot 2: slot 0 mirrored: +0x5C +1, with +0x0C 5 and +0x6C 7.
    g_d1ae_records_guess[2] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_00c_guess = 0.0f;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 1000;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 4;
    record_guess->field_038_guess = 5000;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_05c_guess = -1.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = 20.0f;
    record_guess->field_064_guess = 0.0f;
    record_guess->field_068_guess = 1000;
    record_guess->field_06c_guess = 7.0f;
    record_guess->field_078_guess = 1.0f;
    record_guess->field_070_guess = 2;
    record_guess->field_074_guess = 0.2f;
    record_guess->field_07c_guess = sentinel_guess;
    // Slots 3-6: +0x38 5000, +0x74 0.2. Slot 3: +0x34 4, +0x5C -1, +0x60 20, +0x6C 7, +0x70 2.
    g_d1ae_records_guess[3] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 1000;
    record_guess->field_00c_guess = 5.0f;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 4;
    record_guess->field_038_guess = 5000;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_05c_guess = 1.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = 4.0f;
    record_guess->field_068_guess = 1000;
    record_guess->field_064_guess = 0.0f;
    record_guess->field_074_guess = 0.2f;
    record_guess->field_06c_guess = 7.0f;
    record_guess->field_070_guess = 2;
    record_guess->field_07c_guess = sentinel_guess;
    record_guess->field_078_guess = 1.0f;
    // Slot 4: slot 3 mirrored: +0x5C +1, with +0x0C 5 and +0x60 4.
    g_d1ae_records_guess[4] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_00c_guess = 0.0f;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 2000;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 3;
    record_guess->field_038_guess = 5000;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_054_guess = -1.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_05c_guess = 0.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = 0.0f;
    record_guess->field_068_guess = 2000;
    record_guess->field_064_guess = g_d1ae_value_a_guess;
    record_guess->field_074_guess = 0.2f;
    record_guess->field_06c_guess = g_d1ae_value_a_guess;
    record_guess->field_070_guess = 1;
    record_guess->field_07c_guess = sentinel_guess;
    record_guess->field_078_guess = 1.0f;
    // Slot 5: slot 3 with +0x34 3, -1 at +0x54 instead of +0x5C, +0x60 0, 2000 at +0x08 and
    // +0x68, +0x64 and +0x6C from g_d1ae_value_a_guess, +0x70 1.
    g_d1ae_records_guess[5] = record_guess;

    record_guess = new FUN_0044d1ae_record_guess;
    record_guess->field_000_guess = 3;
    record_guess->field_004_guess = 0x701;
    record_guess->field_008_guess = 1000;
    record_guess->field_00c_guess = 5.0f;
    record_guess->field_010_guess = g_d1ae_x_guess;
    record_guess->field_014_guess = g_d1ae_y_guess;
    record_guess->field_018_guess = g_d1ae_z_guess;
    record_guess->field_01c_guess = 0.0f;
    record_guess->field_020_guess = 0.0f;
    record_guess->field_024_guess = 0.0f;
    record_guess->field_028_guess = 0.0f;
    record_guess->field_02c_guess = 0.0f;
    record_guess->field_030_guess = 0.0f;
    record_guess->field_034_guess = 2;
    record_guess->field_038_guess = 5000;
    record_guess->field_03c_guess = 0.0f;
    record_guess->field_040_guess = 0.0f;
    record_guess->field_044_guess = 0.0f;
    record_guess->field_048_guess = 0.0f;
    record_guess->field_04c_guess = 0.0f;
    record_guess->field_050_guess = 0.0f;
    record_guess->field_054_guess = 0.0f;
    record_guess->field_058_guess = 0.0f;
    record_guess->field_05c_guess = 1.0f;
    record_guess->field_080_guess = 0;
    record_guess->field_060_guess = g_d1ae_value_b_guess;
    record_guess->field_068_guess = 1000;
    record_guess->field_064_guess = 0.0f;
    record_guess->field_06c_guess = 7.0f;
    record_guess->field_070_guess = 2;
    record_guess->field_074_guess = 0.2f;
    record_guess->field_07c_guess = sentinel_guess;
    record_guess->field_078_guess = 1.0f;
    // Slot 6: slot 4 with +0x34 2 and +0x60 from g_d1ae_value_b_guess.
    g_d1ae_records_guess[6] = record_guess;

    return 1;
}


struct SpellEffectRecord_guess {
    int field_00_guess;
    int field_04_guess;
    int field_08_guess;
    int field_0c_guess;
};

struct SpellEffectGroup_guess {
    int header_guess;
    SpellEffectRecord_guess records_guess[4];
};

struct SpellEffectBlock_guess {
    char name_guess[0x40];
    SpellEffectGroup_guess groups_guess[3];
};

#define g_spellEffectCount_guess EQ_GLOBAL(int, 0x0085139C)
#define g_spellEffectTable_guess EQ_GLOBAL(SpellEffectBlock_guess*, 0x00851398)

// EXTERNAL: TITANIUM 0x00611D9D _filelength
long __cdecl _filelength(int handle);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x0060F317 malloc
void* __cdecl malloc(size_t size);

// Loads spells.eff (when missing, the built-in table is written out, 0x0044D074) and SpellsNew.eff
// (0x10C-byte records: a 0x40-byte name and three groups). Without SpellsNew.eff it builds two entries,
// a none entry and a blank one. -1 only when the table can't be allocated; short reads are logged, not
// fatal.
// FUNCTION: TITANIUM 0x0044D773
int __cdecl GetEffFiles_guess() {
    FILE* file = fopen("spells.eff", "rb");
    if (file != 0) {
        if (fread(g_spellEffects_guess, 0xae8, 0x100, file) != 0x100) {
            FUN_00574110_guess("Error reading spell effect table\n");
        }
        fclose(file);
    } else {
        WriteSpellEffects_guess();
    }
    FILE* newFile = fopen("SpellsNew.eff", "rb");
    if (newFile != 0) {
        unsigned int size = _filelength(newFile->_file);
        g_spellEffectCount_guess = size / 0x10c;
        g_spellEffectTable_guess = (SpellEffectBlock_guess*)malloc(size);
        if (g_spellEffectTable_guess == 0) {
            FUN_00574110_guess("Error allocating new spell effect table.\n");
            return -1;
        }
        if (fread(g_spellEffectTable_guess, size, 1, newFile) != 1) {
            FUN_00574110_guess("Error reading new spell effect table\n");
        }
        fclose(newFile);
    } else {
        g_spellEffectCount_guess = 2;
        g_spellEffectTable_guess = (SpellEffectBlock_guess*)malloc(0x218);
        strcpy(g_spellEffectTable_guess->name_guess, "None");
        for (int g = 0; g < 3; ++g) {
            g_spellEffectTable_guess->groups_guess[g].header_guess = 0;
            for (int r = 0; r < 4; ++r) {
                g_spellEffectTable_guess->groups_guess[g].records_guess[r].field_00_guess = 0;
                g_spellEffectTable_guess->groups_guess[g].records_guess[r].field_04_guess = 0;
                g_spellEffectTable_guess->groups_guess[g].records_guess[r].field_08_guess = 1;
                g_spellEffectTable_guess->groups_guess[g].records_guess[r].field_0c_guess = 0;
            }
        }
        strcpy(g_spellEffectTable_guess[1].name_guess, "Blank Spell Effect");
        for (int g = 0; g < 3; ++g) {
            g_spellEffectTable_guess[1].groups_guess[g].header_guess = 0;
            for (int r = 0; r < 4; ++r) {
                g_spellEffectTable_guess[1].groups_guess[g].records_guess[r].field_00_guess = 0;
                g_spellEffectTable_guess[1].groups_guess[g].records_guess[r].field_04_guess = 0;
                g_spellEffectTable_guess[1].groups_guess[g].records_guess[r].field_08_guess = 1;
                g_spellEffectTable_guess[1].groups_guess[g].records_guess[r].field_0c_guess = 0;
            }
        }
    }
    return 0;
}

struct FUN_0044d103_owner_guess {
    char pad_000_guess[0x28];
    unsigned int field_028_guess;
    char pad_02c_guess[0x180 - 0x2c];
    unsigned char type_180_guess;

    int GetSpellColor_guess();
};

// Display colour (ARGB) for the spell's target type (+0x180): red for most single-target types, yellow
// for 6 (probably self), green or orange for the AE types by +0x28 (under 3000 = green), blue and purple
// for the remaining AE/group types; black otherwise. tu_140 colours its spell list with it.
// FUNCTION: TITANIUM 0x0044D103
int FUN_0044d103_owner_guess::GetSpellColor_guess() {
    int value_guess = 0xff000000;
    switch (type_180_guess) {
    case 0: case 1: case 5: case 7: case 9: case 10: case 11: case 12:
    case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
    case 0x1b: case 0x22: case 0x26: case 0x2b:
        return -0x21dedf;
    case 6:
        return -0x3121d7;
    case 8: case 0x15: case 0x16: case 0x17: case 0x1c: case 0x1e:
        return field_028_guess < 3000 ? 0xFF42DE63 : 0xFFDE7B21;
    case 2: case 4: case 0x18: case 0x19: case 0x1a: case 0x1d: case 0x1f: case 0x2a:
        return -0xadbd22;
    case 3: case 0x28: case 0x29:
        value_guess = -0x63ce22;
        break;
    }
    return value_guess;
}

// Zeroes every field; ParseFromText_guess starts with it. The string pointers are not freed here.
// FUNCTION: TITANIUM 0x0044D932
// @early-stop: budget, structural ndiff=203
void EQ_Spell_guess::ClearSpellData_guess() {
    id_0000_guess = 0;
    range_0004_guess = 0.0f;
    aeRange_0008_guess = 0.0f;
    pushBack_000c_guess = 0.0f;
    pushUp_0010_guess = 0.0f;
    castTime_0014_guess = 0;
    recoveryTime_0018_guess = 0;
    recastTime_001c_guess = 0;
    durationFormula_0020_guess = 0;
    duration_0024_guess = 0;
    aeDuration_0028_guess = 0;
    mana_002c_guess = 0;
    for (int offset_guess = 0; offset_guess < 12 * 4; offset_guess += 4) {
        base_0030_guess[offset_guess] = 0;
        base2_0060_guess[offset_guess] = 0;
        max_0090_guess[offset_guess] = 0;
        formula_00f0_guess[offset_guess] = 0;
        effectIds_0120_guess[offset_guess] = 0;
    }
    for (int offset_guess = 0; offset_guess < 4 * 4; offset_guess += 4) {
        components_00c0_guess[offset_guess] = 0;
        componentCounts_00d0_guess[offset_guess] = 0;
    }
    for (int offset_guess = 0; offset_guess < 4 * 4; offset_guess += 4) {
        noExpendReagents_00e0_guess[offset_guess] = 0;
    }
    for (int offset_guess = 0; offset_guess < 0x24; ++offset_guess) {
        classLevels_0150_guess[offset_guess] = 0;
    }
    icon_0174_guess = 0;
    memIcon_0178_guess = 0;
    lightType_017c_guess = 0;
    goodEffect_017d_guess = 0;
    activated_017e_guess = 0;
    resistType_017f_guess = 0;
    targetType_0180_guess = 0;
    baseDifficulty_0181_guess = 0;
    skill_0182_guess = 0;
    zoneType_0183_guess = 0;
    environmentType_0184_guess = 0;
    timeOfDay_0185_guess = 0;
    castingAnim_0186_guess = 0;
    targetAnim_0187_guess = 0;
    travelType_0188_guess = 0;
    disallowSit_0189_guess = 0;
    descNum_018c_guess = 0;
    field_190_guess = 0;
    uninterruptable_0191_guess = 0;
    dotStackingExempt_0192_guess = 0;
    deletable_0193_guess = 0;
    recourseLink_0194_guess = 0;
    noPartialResist_0198_guess = 0;
    field_199_guess = 0;
    field_19a_guess = 0;
    shortBuffBox_019b_guess = 0;
    typeDescNum_019c_guess = 0;
    effectDescNum_01a0_guess = 0;
    field_1a4_guess = 0;
    field_1a8_guess = 0;
    field_1a9_guess = 0;
    field_1aa_guess = 0;
    field_1ac_guess = 0;
    field_1b0_guess = 0;
    field_1b4_guess = 0;
    field_1b8_guess = 0;
    field_1bc_guess = 0;
    field_1c0_guess = 0;
    field_1c4_guess = 0;
    field_1c8_guess = 0;
    field_1cc_guess = 0;
    field_1d0_guess = 0;
    field_1d4_guess = 0;
    field_1d8_guess = 0;
    field_1dc_guess = 0;
    field_1e0_guess = 0;
    field_1e4_guess = 0;
    field_1e8_guess = 0;
    field_1ec_guess = 0;
    field_1f0_guess = 0;
    field_1f4_guess = 0;
    field_1f8_guess = 0;
    field_1fc_guess = 0;
    field_1fd_guess = 0;
    field_1fe_guess = 0;
    field_200_guess = 0;
    field_204_guess = 0;
    name_0208_guess = 0;
    player1_020c_guess = 0;
    teleportZone_0210_guess = 0;
    youCast_0214_guess = 0;
    otherCasts_0218_guess = 0;
    castOnYou_021c_guess = 0;
    castOnOther_0220_guess = 0;
    spellFades_0224_guess = 0;
    spellAffect_022c_guess = 0;
    spellAffectIndex_0230_guess = 0;
    spellEffect_0234_guess = 0;
    spellAnim_0238_guess = 0;
    deityMask_023c_guess = 0;
    npcNoCast_0240_guess = 0;
    field_244_guess = 0;
    newIcon_0248_guess = 0;
    resistDiff_024c_guess = 0;
    field_250_guess = 0;
    field_254_guess = 0;
    field_258_guess = 0;
    field_25c_guess = 0;
    field_260_guess = 0;
    field_264_guess = 0;
    field_268_guess = 0;
    field_269_guess = 0;
    field_26a_guess = 0;
    field_228_guess = 0;
    spellEffectIndex_026c_guess = 0;
}

struct SpellEffectSlot_guess {
    char names_guess[3][0x20];
    char flag_60_guess;
    char pad_61_guess[0x1F];
    int ids_80_guess[3];
    int ids_8c_guess[3];
    char pad_98_guess[0x184];
    int id_21c_guess;
    char flags_220_guess[3][4];
    float vals_22c_guess[3];
    float vecs_238_guess[3][3];
    float vals_25c_guess[3];
    float vals_268_guess[3];
    int ints_274_guess[3];
    float vals_280_guess[3];
    int ints_28c_guess[3];
    float vals_298_guess[3];
    char pad_2a4_guess[0xFC];
};

struct SpellEffect_guess {
    int field_00_guess;
    int field_04_guess;
    SpellEffectSlot_guess slots_guess[3];
};

#define g_spellEffectTableFixed_guess EQ_ARRAY(SpellEffect_guess, 0x008513B8)

// EXTERNAL: TITANIUM 0x00576D80 ReadInt_guess
int __cdecl ReadInt_guess(char** cursor, int delimiter);
// EXTERNAL: TITANIUM 0x00576E00 ReadString_guess
char* __cdecl ReadString_guess(char** cursor, int delimiter);
// EXTERNAL: TITANIUM 0x00576DC0 ReadFloat_guess
float __cdecl ReadFloat_guess(char** cursor, int delimiter);
// EXTERNAL: TITANIUM 0x0060D970 strlen
size_t __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x005FF700 CopyString_guess
char* __cdecl CopyString_guess(const char* text);

// Fills the spell from one spells_us.txt line (fields in file order, '^'-separated), or with the
// unknown-spell placeholder when `data` is null; the spell table (tu_089) gives every unused id that
// placeholder. Classes go to +0x151-0x160 (+0x150 unused), the 17 deity flags to a bit mask at +0x23C.
// +0x28 is capped at 14000 unless effect slot 0 is 76 (Sentinel). +0x244 is read twice; the second
// value wins (original). Ends by resolving the spells.eff (+0x230) and SpellsNew.eff (+0x26C) entries.
// FUNCTION: TITANIUM 0x0044DBF0
// @early-stop: budget, structural ndiff=60
EQ_Spell_guess* EQ_Spell_guess::ParseFromText_guess(char* data) {
    ClearSpellData_guess();
    if (data != 0) {
        id_0000_guess = ReadInt_guess(&data, '^');
        name_0208_guess = (int)ReadString_guess(&data, '^');
        player1_020c_guess = (int)ReadString_guess(&data, '^');
        teleportZone_0210_guess = (int)ReadString_guess(&data, '^');
        youCast_0214_guess = (int)ReadString_guess(&data, '^');
        otherCasts_0218_guess = (int)ReadString_guess(&data, '^');
        castOnYou_021c_guess = (int)ReadString_guess(&data, '^');
        castOnOther_0220_guess = (int)ReadString_guess(&data, '^');
        spellFades_0224_guess = (int)ReadString_guess(&data, '^');
        range_0004_guess = ReadFloat_guess(&data, '^');
        aeRange_0008_guess = ReadFloat_guess(&data, '^');
        pushBack_000c_guess = ReadFloat_guess(&data, '^');
        pushUp_0010_guess = ReadFloat_guess(&data, '^');
        castTime_0014_guess = ReadInt_guess(&data, '^');
        recoveryTime_0018_guess = ReadInt_guess(&data, '^');
        recastTime_001c_guess = ReadInt_guess(&data, '^');
        durationFormula_0020_guess = ReadInt_guess(&data, '^');
        duration_0024_guess = ReadInt_guess(&data, '^');
        aeDuration_0028_guess = ReadInt_guess(&data, '^');
        mana_002c_guess = ReadInt_guess(&data, '^');
        int i;
        /* fake match: named array references give [ecx+esi+N] */
        CheckedArray_guess<int, 12>& a030 = base_0030_guess;
        CheckedArray_guess<int, 12>& a060 = base2_0060_guess;
        CheckedArray_guess<int, 12>& a090 = max_0090_guess;
        CheckedArray_guess<int, 4>& a0c0 = components_00c0_guess;
        CheckedArray_guess<int, 4>& a0d0 = componentCounts_00d0_guess;
        CheckedArray_guess<int, 4>& a0e0 = noExpendReagents_00e0_guess;
        CheckedArray_guess<int, 12>& a0f0 = formula_00f0_guess;
        CheckedArray_guess<int, 12>& a120 = effectIds_0120_guess;
        for (i = 0; i < 12 * 4; i += 4) a030[i] = ReadInt_guess(&data, '^');
        for (i = 0; i < 12 * 4; i += 4) a060[i] = ReadInt_guess(&data, '^');
        for (i = 0; i < 12 * 4; i += 4) a090[i] = ReadInt_guess(&data, '^');
        icon_0174_guess = ReadInt_guess(&data, '^');
        memIcon_0178_guess = ReadInt_guess(&data, '^');
        for (i = 0; i < 4 * 4; i += 4) a0c0[i] = ReadInt_guess(&data, '^');
        for (i = 0; i < 4 * 4; i += 4) a0d0[i] = ReadInt_guess(&data, '^');
        for (i = 0; i < 4 * 4; i += 4) a0e0[i] = ReadInt_guess(&data, '^');
        for (i = 0; i < 12 * 4; i += 4) a0f0[i] = ReadInt_guess(&data, '^');
        lightType_017c_guess = ReadInt_guess(&data, '^');
        goodEffect_017d_guess = ReadInt_guess(&data, '^');
        activated_017e_guess = ReadInt_guess(&data, '^');
        resistType_017f_guess = ReadInt_guess(&data, '^');
        for (i = 0; i < 12 * 4; i += 4) a120[i] = ReadInt_guess(&data, '^');
        targetType_0180_guess = ReadInt_guess(&data, '^');
        baseDifficulty_0181_guess = ReadInt_guess(&data, '^');
        skill_0182_guess = ReadInt_guess(&data, '^');
        zoneType_0183_guess = ReadInt_guess(&data, '^');
        environmentType_0184_guess = ReadInt_guess(&data, '^');
        timeOfDay_0185_guess = ReadInt_guess(&data, '^');
        for (i = 1; i <= 16; ++i) classLevels_0150_guess[i] = ReadInt_guess(&data, '^');
        castingAnim_0186_guess = ReadInt_guess(&data, '^');
        targetAnim_0187_guess = ReadInt_guess(&data, '^');
        travelType_0188_guess = ReadInt_guess(&data, '^');
        spellAffectIndex_0230_guess = ReadInt_guess(&data, '^');
        disallowSit_0189_guess = ReadInt_guess(&data, '^');
        deityMask_023c_guess = 0;
        for (i = 1; i <= 17; ++i) {
            if (ReadInt_guess(&data, '^') != 0) deityMask_023c_guess |= 1 << (i - 1);
        }
        npcNoCast_0240_guess = ReadInt_guess(&data, '^');
        field_244_guess = ReadInt_guess(&data, '^');
        newIcon_0248_guess = ReadInt_guess(&data, '^');
        spellAnim_0238_guess = ReadInt_guess(&data, '^');
        uninterruptable_0191_guess = ReadInt_guess(&data, '^') != 0;
        resistDiff_024c_guess = ReadInt_guess(&data, '^');
        dotStackingExempt_0192_guess = ReadInt_guess(&data, '^') != 0;
        deletable_0193_guess = ReadInt_guess(&data, '^') != 0;
        recourseLink_0194_guess = ReadInt_guess(&data, '^');
        noPartialResist_0198_guess = ReadInt_guess(&data, '^') != 0;
        field_19a_guess = ReadInt_guess(&data, '^') != 0;
        field_199_guess = ReadInt_guess(&data, '^') != 0;
        shortBuffBox_019b_guess = ReadInt_guess(&data, '^') != 0;
        descNum_018c_guess = ReadInt_guess(&data, '^');
        if ((unsigned int)aeDuration_0028_guess > 14000 && effectIds_0120_guess.data_guess[0] != 0x4c) {
            aeDuration_0028_guess = 14000;
        }
        typeDescNum_019c_guess = ReadInt_guess(&data, '^');
        effectDescNum_01a0_guess = ReadInt_guess(&data, '^');
        field_1a4_guess = ReadInt_guess(&data, '^');
        field_1a8_guess = ReadInt_guess(&data, '^') != 0;
        field_1a9_guess = ReadInt_guess(&data, '^') != 0;
        field_1aa_guess = ReadInt_guess(&data, '^') != 0;
        field_1ac_guess = ReadInt_guess(&data, '^');
        field_1b0_guess = ReadInt_guess(&data, '^');
        field_1b4_guess = ReadInt_guess(&data, '^');
        field_1b8_guess = ReadInt_guess(&data, '^') != 0;
        field_1bc_guess = ReadInt_guess(&data, '^');
        field_1c0_guess = ReadInt_guess(&data, '^');
        field_1c4_guess = ReadInt_guess(&data, '^') != 0;
        for (i = 0; i < 4; ++i) ReadInt_guess(&data, '^');
        field_1cc_guess = ReadInt_guess(&data, '^');
        field_1c8_guess = ReadInt_guess(&data, '^');
        field_1d0_guess = ReadInt_guess(&data, '^');
        field_1d4_guess = ReadInt_guess(&data, '^');
        field_1e0_guess = ReadInt_guess(&data, '^');
        field_1e4_guess = ReadInt_guess(&data, '^');
        field_1e8_guess = ReadInt_guess(&data, '^');
        field_1f4_guess = ReadInt_guess(&data, '^');
        field_1ec_guess = ReadInt_guess(&data, '^');
        field_1f0_guess = ReadInt_guess(&data, '^');
        field_1f8_guess = ReadInt_guess(&data, '^');
        field_1fc_guess = ReadInt_guess(&data, '^') != 0;
        field_1fd_guess = ReadInt_guess(&data, '^') != 0;
        field_1fe_guess = ReadInt_guess(&data, '^') != 0;
        field_200_guess = ReadInt_guess(&data, '^');
        field_244_guess = ReadInt_guess(&data, '^');
        field_258_guess = ReadInt_guess(&data, '^');
        field_254_guess = ReadInt_guess(&data, '^');
        field_25c_guess = ReadInt_guess(&data, '^');
        field_260_guess = ReadInt_guess(&data, '^');
        field_250_guess = ReadInt_guess(&data, '^');
        field_1d8_guess = ReadInt_guess(&data, '^');
        field_1dc_guess = ReadInt_guess(&data, '^');
        field_268_guess = ReadInt_guess(&data, '^') != 0;
        field_269_guess = ReadInt_guess(&data, '^') != 0;
        field_26a_guess = ReadInt_guess(&data, '^') != 0;
        field_228_guess = ReadInt_guess(&data, '^') != 0;
        field_190_guess = ReadInt_guess(&data, '^') != 0;
        field_264_guess = ReadInt_guess(&data, '^');
        spellEffectIndex_026c_guess = ReadInt_guess(&data, '^');
    } else {
        goodEffect_017d_guess = 1;
        components_00c0_guess.data_guess[0] = -1;
        components_00c0_guess.data_guess[1] = -1;
        components_00c0_guess.data_guess[2] = -1;
        components_00c0_guess.data_guess[3] = -1;
        noExpendReagents_00e0_guess.data_guess[0] = -1;
        noExpendReagents_00e0_guess.data_guess[1] = -1;
        noExpendReagents_00e0_guess.data_guess[2] = -1;
        noExpendReagents_00e0_guess.data_guess[3] = -1;
        aeRange_0008_guess = 0.0f;
        memIcon_0178_guess = 500;
        activated_017e_guess = 0;
        castTime_0014_guess = 1000;
        castingAnim_0186_guess = 0x2b;
        spellAffect_022c_guess = 0;
        spellAnim_0238_guess = 0;
        spellAffectIndex_0230_guess = -1;
        lightType_017c_guess = 0;
        aeDuration_0028_guess = 0;
        name_0208_guess = (int)CopyString_guess("Unknown Spell");
        player1_020c_guess = (int)CopyString_guess(" ");
        range_0004_guess = 0.0f;
        icon_0174_guess = 0x21e;
        pushBack_000c_guess = 0.0f;
        recastTime_001c_guess = 0;
        durationFormula_0020_guess = 0;
        mana_002c_guess = 0;
        resistType_017f_guess = 0;
        base_0030_guess.data_guess[0] = 0;
        formula_00f0_guess.data_guess[0] = 0;
        effectIds_0120_guess.data_guess[0] = 1;
        baseDifficulty_0181_guess = 0;
        for (int j = 0; j < 0x11; ++j) classLevels_0150_guess[j] = 0xff;
        youCast_0214_guess = (int)CopyString_guess("You cast Unknown Spell.");
        otherCasts_0218_guess = (int)CopyString_guess(" casts Unknown Spell.");
        castOnYou_021c_guess = (int)CopyString_guess("You feel bogus as an unknown spell accosts you.");
        castOnOther_0220_guess = (int)CopyString_guess(" is the victim of an unknown spell.");
        spellFades_0224_guess = (int)CopyString_guess("An unknown spell is gone.");
        goodEffect_017d_guess = 0;
        disallowSit_0189_guess = 0;
        descNum_018c_guess = 0;
        field_190_guess = 1;
        typeDescNum_019c_guess = 0;
        effectDescNum_01a0_guess = 0;
        field_1a4_guess = 0;
        field_1d0_guess = 0;
        field_1d4_guess = 0;
        field_1e0_guess = 0;
        field_1e4_guess = 0;
        field_1e8_guess = 0;
        field_1ec_guess = 0;
        field_1f0_guess = 0;
        field_1f8_guess = 0;
        field_1fd_guess = 0;
        field_1fe_guess = 0;
        field_250_guess = 0;
        field_1d8_guess = 0;
        field_1dc_guess = 0;
        field_228_guess = 0;
    }
    spellAffect_022c_guess = 0;
    if (spellAffectIndex_0230_guess >= 0 && spellAffectIndex_0230_guess < 0x100) {
        spellAffect_022c_guess = (int)&g_spellEffectTableFixed_guess[spellAffectIndex_0230_guess];
    }
    spellEffect_0234_guess = 0;
    if (spellEffectIndex_026c_guess > 0 && spellEffectIndex_026c_guess < g_spellEffectCount_guess &&
        strlen(g_spellEffectTable_guess[spellEffectIndex_026c_guess].name_guess) != 0) {
        spellEffect_0234_guess = (int)&g_spellEffectTable_guess[spellEffectIndex_026c_guess];
    }
    return this;
}

// Resets all 256 spells.eff entries (ids -1, names and vectors cleared), then GetEffFiles_guess.
// Called from the startup code in tu_062.
// FUNCTION: TITANIUM 0x0044E66E
int __cdecl LoadSpellEffects_guess() {
    FUN_00574110_guess("Loading spell effects.");
    for (int i = 0; i < 0x100; ++i) {
        g_spellEffectTableFixed_guess[i].field_00_guess = 0;
        g_spellEffectTableFixed_guess[i].field_04_guess = 0;
        for (int s = 0; s < 3; ++s) {
            g_spellEffectTableFixed_guess[i].slots_guess[s].flag_60_guess = 0;
            for (int j = 0; j < 3; ++j) {
                g_spellEffectTableFixed_guess[i].slots_guess[s].ids_80_guess[j] = -1;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vecs_238_guess[j][0] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].ids_8c_guess[j] = -1;
                g_spellEffectTableFixed_guess[i].slots_guess[s].names_guess[j][0] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vecs_238_guess[j][1] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].flags_220_guess[j][2] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].flags_220_guess[j][0] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].flags_220_guess[j][1] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vecs_238_guess[j][2] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].ints_274_guess[j] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].ints_28c_guess[j] = 0;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vals_22c_guess[j] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vals_280_guess[j] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vals_298_guess[j] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vals_25c_guess[j] = 0.0f;
                g_spellEffectTableFixed_guess[i].slots_guess[s].vals_268_guess[j] = 0.0f;
            }
            g_spellEffectTableFixed_guess[i].slots_guess[s].id_21c_guess = -1;
        }
    }
    GetEffFiles_guess();
    return 1;
}

