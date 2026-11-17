// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 80: a hint from compare/tumap.py.
// EQ_PC (EQ_PC.cpp): group/raid/leadership tests, discipline and reuse timers, bandolier and potion belt,
// training, money, lore checks, slot lookups, plus the EQ_PC ctor and PcBase dtor. Names follow MQ2
// eqgame.h VAs, MQ2 method signatures and EQ_PC.cpp of the earlier sibling decomp. EQ_PCView_guess is the complete
// EQ_PC; FindResult_guess/ValueBase_guess reach CHARINFO2 through the virtual base (GetCharInfo2 0x005EC220).
#include "titanium/eqaddr.h"
#include "titanium/bounded_array.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/slots.h"
#include "titanium/classes.h"
#include "titanium/skills.h"
#include "titanium/opcodes.h"
#include <stddef.h>
#include "titanium/wnd/CBandolierWnd.h"
#include "titanium/wnd/CPotionBeltWnd.h"
#include "titanium/wnd/CCursorAttachment.h"

struct PcCharacterVtordisp_guess {
    int value;
};

struct ItemInstanceView_guess;

struct State_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 State_guess::IsInRaid_guess
    bool IsInRaid_guess();

    // EXTERNAL: TITANIUM 0x004302D2 State_guess::GetMemberCount_guess
    int GetMemberCount_guess();

    // EXTERNAL: TITANIUM 0x0042FD00 State_guess::IsRaidLeader_guess
    bool IsRaidLeader_guess();

    // EXTERNAL: TITANIUM 0x004307A4 State_guess::SetTargetRaidPlayer_guess
    void SetTargetRaidPlayer_guess(int value);

    // EXTERNAL: TITANIUM 0x0042FCD9 State_guess::ClearPendingInvite_guess
    void ClearPendingInvite_guess();
};

// One bandolier item: id, icon, name[0x40] (EQEmu BandolierItem_Struct).
struct Slot_guess {
    int words[2];
    char third;
    char pad_9[0x3f];
};

struct ClearD30_guess {
    char pad_0000[0xd30];
    BoundedArray_guess<int, 2> values_d30;
    void Clear_guess();
};

struct ClearBF0_guess {
    char pad_0000[0xbf0];
    BoundedArray_guess<int, 64> values_bf0;
    void Clear_guess();
};

struct ClearC36C_guess {
    char pad_0000[0xc36c];
    BoundedArray_guess<int, 3> values_c36c;
    int first;
    int second;
    // EXTERNAL: TITANIUM 0x0045871F ClearC36C_guess::SetC354_guess
    void SetC354_guess();
    void Clear_guess();
};

struct IndexHolder_guess {
    char pad_0[4];
    int vbaseOffset_0004_guess;
};

struct EntryAction_guess {
    // EXTERNAL: TITANIUM 0x004586A5 EntryAction_guess::FUN_004586a5_guess
    void FUN_004586a5_guess(int index, int value);

    // EXTERNAL: TITANIUM 0x0041AA84 EntryAction_guess::FUN_0041aa84_guess
    void FUN_0041aa84_guess(int index, int value);
};

struct IndexedMethod_guess {
    // EXTERNAL: TITANIUM 0x004B96C3 IndexedMethod_guess::FUN_004b96c3_guess
    void FUN_004b96c3_guess(int index, int value);
};

struct Result_guess {
    char pad_0[4];
    int value_4;
};

struct PcCharacter1View_guess;
struct EQ_PCView_guess;
struct Block_guess;
struct SendText_guess;
struct EQ_ItemView_guess;
struct PcProfileView_guess;
struct RankBase_guess;

struct Quad_guess {
    char bytes_guess[16];
};

// The spawn as ProcessAirSupply_guess reads it: spawn type +0x244 (0 = PC), spawn id +0x258.
struct Actor_guess {
    char pad_0[0x244];
    unsigned char value_244;
    char pad_245[0x258 - 0x245];
    unsigned short value_258;
};

// Damage record ProcessAirSupply hands to 0x0041C905: target id, amount (+6), damage type (+0x16, 0xFB).
#pragma pack(push, 1)
struct UpgradeBenefit_guess {
    unsigned short word_0;
    unsigned short word_2;
    unsigned short word_4;
    int count_6;
    float float_a;
    float float_e;
    float float_12;
    unsigned char byte_16;
    int pad_17;
    short word_1b;
    char pad_1d;
    unsigned char flag_1e;
};
#pragma pack(pop)

// Byte view of the Inner object, indexed at run time (holder offset + 0x10d).
struct ByteView_guess {
    unsigned char bytes_guess[0x10000];
};

// The class's inline cleanup is out of line at 0x004B73EE (crt_defaults.json aliases its name).
struct PlayerTable_guess {
    int field_000;
    int size_004;
    int mask_008;
    int shift_00c;
    Block_guess** blocks_010;
    int count_014;
    int field_018;

    // EXTERNAL: TITANIUM 0x0047C3AF PlayerTable_guess::Init_guess
    void Init_guess(int capacity);
    // EXTERNAL: TITANIUM 0x004B76E3 PlayerTable_guess::FUN_004b76e3_guess
    void FUN_004b76e3_guess(int value, int* state);
    PlayerTable_guess(int capacity) { Init_guess(capacity); }
    ~PlayerTable_guess() { Clear_guess(); }
    void Clear_guess() {
        int index = 0;
        if (count_014 > 0) {
            do {
                delete[] blocks_010[index];
                index++;
            } while (index < count_014);
        }
        delete[] blocks_010;
        blocks_010 = 0;
        count_014 = 0;
        field_000 = 0;
    }
};

struct TargetPlayerTable_guess {
    int field_000;
    int size_004;
    int mask_008;
    int shift_00c;
    Block_guess** blocks_010;
    int count_014;
    int field_018;

    // EXTERNAL: TITANIUM 0x0047C3AF TargetPlayerTable_guess::Init_guess
    void Init_guess(int capacity);
    TargetPlayerTable_guess(int capacity) { Init_guess(capacity); }
    // EXTERNAL: TITANIUM 0x004B73EE TargetPlayerTable_guess::~TargetPlayerTable_guess
    ~TargetPlayerTable_guess();
    // EXTERNAL: TITANIUM 0x004B76E3 TargetPlayerTable_guess::FUN_004b76e3_guess
    void FUN_004b76e3_guess(int value, int* state);
};

struct Block_guess {
    Quad_guess head_0;

    // EXTERNAL: TITANIUM 0x004B76A6 Block_guess::GetInventorySlot_guess
    ItemInstanceView_guess** GetInventorySlot_guess(PcCharacter1View_guess* inner);
};

struct PcCharacter1View_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual int Slot02_guess();

    // EXTERNAL: TITANIUM 0x00416963 PcCharacter1View_guess::Max_HP_guess
    int Max_HP_guess(int value);

    // EXTERNAL: TITANIUM 0x00416A40 PcCharacter1View_guess::Max_Endurance
    int Max_Endurance();

    int GetSharedBankItem_guess(int index);

    int CapStat_guess(int value, int type);

    // EXTERNAL: TITANIUM 0x004106A3 PcCharacter1View_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first, int second, int third, int fourth);

    // EXTERNAL: TITANIUM 0x0040D933 PcCharacter1View_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();

    // EXTERNAL: TITANIUM 0x0040DB4E PcCharacter1View_guess::FUN_0040db4e_guess
    int FUN_0040db4e_guess(int first, int second);

    // EXTERNAL: TITANIUM 0x0041C8F4 PcCharacter1View_guess::HasSkillChecked_guess
    int HasSkillChecked_guess(unsigned int index);

    // EXTERNAL: TITANIUM 0x0040E7AC PcCharacter1View_guess::GetBuff_guess
    Result_guess* GetBuff_guess(int value);

    // EXTERNAL: TITANIUM 0x00411EA4 PcCharacter1View_guess::FUN_00411ea4_guess
    int FUN_00411ea4_guess(int first, int second, int third);

    // EXTERNAL: TITANIUM 0x00411F2F PcCharacter1View_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(Result_guess* value);

    // EXTERNAL: TITANIUM 0x004179AA PcCharacter1View_guess::NotifyPCAffectChange_guess
    void NotifyPCAffectChange_guess(int value, int flag);

    // EXTERNAL: TITANIUM 0x0041A259 PcCharacter1View_guess::FUN_0041a259_guess
    __int64 FUN_0041a259_guess();

    // EXTERNAL: TITANIUM 0x004192AA PcCharacter1View_guess::CanUseItem_guess
    int CanUseItem_guess(ItemInstanceView_guess* player, int value);

    // EXTERNAL: TITANIUM 0x00411F3D PcCharacter1View_guess::CastSpell
    char CastSpell(int kind, int zero, ItemInstanceView_guess** slot, Quad_guess blob, int flag);

    // EXTERNAL: TITANIUM 0x0041A753 PcCharacter1View_guess::CanBreathe_guess
    char CanBreathe_guess();

    // EXTERNAL: TITANIUM 0x00417E67 PcCharacter1View_guess::Cur_Endurance_guess
    void Cur_Endurance_guess();

    // EXTERNAL: TITANIUM 0x0041C905 PcCharacter1View_guess::FUN_0041c905_guess
    void FUN_0041c905_guess(int count, UpgradeBenefit_guess* update, int first, int second, int third, int fourth);

    EQ_PCView_guess* Owner_guess();  // the EQ_PC this +0xC280 subobject belongs to

    IndexHolder_guess* holder_4;
};

struct OffsetSubobject_guess {
    // EXTERNAL: TITANIUM 0x00417CC8 OffsetSubobject_guess::FUN_00417cc8_guess
    void FUN_00417cc8_guess(int value);

    // EXTERNAL: TITANIUM 0x0040E293 OffsetSubobject_guess::FUN_0040e293_guess
    void FUN_0040e293_guess(int value);

    // EXTERNAL: TITANIUM 0x00417CB3 OffsetSubobject_guess::FUN_00417cb3_guess
    void FUN_00417cb3_guess(int value);
};

struct EQ_SpellView_guess {
    char pad_0[0x1c];
    unsigned int recastTime_001c_guess;  // recast time, ms
    int durationFormula_0020_guess;  // probably the duration (0 = instant)
    char pad_24[0x17d - 0x24];
    char goodEffect_017d_guess;  // removable by the player (RemoveMyAffect)
    char pad_17e[0x180 - 0x17e];
    char targetType_0180_guess;  // probably the target type (6 = self)
    char pad_181[0x1c0 - 0x181];
    int reuseTimerIndex_01c0_guess;  // reuse timer index, 0-19
    char value_1c4;  // combat ability / discipline
    char pad_1c5[0x208 - 0x1c5];
    int name_0208_guess;  // passed with the reuse messages, probably the ability's name id
    char pad_20c[0x23c - 0x20c];
    int value_23c;  // required deity, 0 = any

    // EXTERNAL: TITANIUM 0x0044E77B EQ_SpellView_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int value);

    // EXTERNAL: TITANIUM 0x0044E755 EQ_SpellView_guess::GetSpellLevelNeeded_guess
    char GetSpellLevelNeeded_guess(int value);
};

struct SpellManagerView_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 SpellManagerView_guess::GetSpell_guess
    EQ_SpellView_guess* GetSpell_guess(int value);
};

struct Pending_guess {
    char pad_0[0x107c];
    int value_107c;
};

struct Holder_guess {
    char pad_0[0x28];
    float value_28;
    char pad_2c[0x48 - 0x2c];
    float value_48;
    char pad_4c[0x1a8 - 0x4c];
    Pending_guess* pending_1a8;
    // EXTERNAL: TITANIUM 0x0048083A Holder_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(int code, const char* text, int zero);
};

struct EQ_PCView_guess;
struct MagicEntry_guess;
struct EntryNode_guess;

struct LookupOwner_guess {
    char pad_0[0x1ac8];
    int values[9];

    int* GetValues_guess() {
        return values;
    }
};

struct MatchInfo_guess {
    char pad_0[0x48];
    int value_48;
};

struct ValueEntryMethod_guess {
    // EXTERNAL: TITANIUM 0x005EC220 ValueEntryMethod_guess::GetCharInfo2
    EQ_PCView_guess* GetCharInfo2();
};

struct ValueEntry_guess {
    char pad_0[4];
    ValueEntryMethod_guess subobject;
    char pad_5[7];
    unsigned char values_c[32];

    // EXTERNAL: TITANIUM 0x0040E2BD ValueEntry_guess::FUN_0040e2bd_guess
    void FUN_0040e2bd_guess(int value);

    // EXTERNAL: TITANIUM 0x0040E722 ValueEntry_guess::GetSkill_guess
    unsigned int GetSkill_guess(unsigned int index);

    int GetBodyTint_guess(unsigned int index);

    // EXTERNAL: TITANIUM 0x00417D70 ValueEntry_guess::AddSixth_guess
    void AddSixth_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040CC50 ValueEntry_guess::GetInventorySlot_guess
    MatchInfo_guess* GetInventorySlot_guess(int index);

    // EXTERNAL: TITANIUM 0x0040CC50 ValueEntry_guess::GetFirst_guess
    MagicEntry_guess* GetFirst_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x0040CC50 ValueEntry_guess::GetNode_guess
    EntryNode_guess* GetNode_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00434777 ValueEntry_guess::GetSlot_guess
    MagicEntry_guess** GetSlot_guess(int index_guess);
};

struct MagicEntry_guess {
    char pad_0[0x58];
    int value_58;

    // EXTERNAL: TITANIUM 0x005ECCC0 MagicEntry_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005EC650 MagicEntry_guess::GetValue_guess
    MagicEntry_guess** GetValue_guess(int index_guess);
};

struct EntryPrefix_guess {
    int value_0;
};

struct OffsetValueEntry_guess : EntryPrefix_guess, ValueEntryMethod_guess {
    // EXTERNAL: TITANIUM 0x00417D70 OffsetValueEntry_guess::AddSixth_guess
    void AddSixth_guess(int value_guess);
};

struct Target_guess {
    char pad_0[0x1b6];
    unsigned char value_1b6;  // set: no con colour (6)
    char pad_1b7[0x244 - 0x1b7];
    unsigned char value_244;  // spawn type: 0 PC, 1 NPC, 2+ corpses
    char pad_245[0x24c - 0x245];
    unsigned char value_24c;  // level
    char pad_24d[0x252 - 0x24d];
    unsigned char playerClass_0252_guess;  // class
};

// types.h EQ_CharacterBase_guess +0x108 (still inside its pad_105). Kept local: a new member in types.h moves
// tu_044 ExecuteCmd 0x004619CD (structural, ndiff 799 -> 800).
struct CharacterFlagsView_guess {
    /*0x000*/ unsigned char pad_000[0x108];
    /*0x108*/ unsigned char flags_108_guess;  // bit 0x40: Max_Mana (0x004BC454) adds the 0x004B4FE9 mana bonus
};

struct CharInfo2View_guess {
    char pad_0[0x1198];
    int race_guess;
    unsigned char classId_guess;
    char pad_119d[0x11a4 - 0x119d];
    int level_guess;
    char pad_11a8[0x11d4 - 0x11a8];
    int platinum_guess;
    int gold_guess;
    int silver_guess;
    int copper_guess;
    // 0x11E4..0x11F0: coins on the cursor, platinum to copper (DestroyHeldItemOrMoney's MoveCoin kinds 3-0).
    int value_11e4;
    int value_11e8;
    int value_11ec;
    int value_11f0;
    char pad_11f4[4];
    int practicePoints_11f8_guess;  // probably practice points: training is refused (0x327D) when 0
    char pad_11fc[0x1218 - 0x11fc];
    int thirst_guess;
    int hunger_guess;
    char pad_1220[0x1274 - 0x1220];
    int value_1274;

    // EXTERNAL: TITANIUM 0x005FBAE0 CharInfo2View_guess::FUN_005fbae0_guess
    int FUN_005fbae0_guess();
};

struct Timed_guess {
    char pad_0[0x54];
    int recastEndTime_0054_guess;

    // EXTERNAL: TITANIUM 0x005E05F0 Timed_guess::FUN_005e05f0_guess
    int FUN_005e05f0_guess();
};

struct StatRow_guess {
    int value_80;
    int value_82;
    int value_14a;
    char pad_c[0x3c - 0xc];
};

#define g_statRows_guess EQ_ARRAY(StatRow_guess, 0x0078F040)
#define g_statValues_guess EQ_ARRAY(int, 0x0078F00C)

// A positional 12-byte payload: PotionBelt {action, belt slot, item id}, MoveItem {from, to, 0}.
struct Message_guess {
    int type;
    int value;
    int unused;
};

struct SlotCopy_guess {
    int values[2];
    char text[0x40];
};

// One 0x140-byte bandolier set (EQEmu Bandolier_Struct): name[0x20], then 4 items. `active` is the
// name's first byte: an unnamed set is empty.
struct CopyBuffer_guess {
    char active;
    char pad_1[0x1f];
    SlotCopy_guess slots[4];
};

struct RecordTarget_guess {
    // EXTERNAL: TITANIUM 0x005E0F60 RecordTarget_guess::FUN_005e0f60_guess
    int FUN_005e0f60_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 RecordTarget_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 RecordTarget_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005E0F00 RecordTarget_guess::FUN_005e0f00_guess
    char* FUN_005e0f00_guess();
};

// CHARINFO2 from +0x10, where the inventory starts: +0x2C range (slot 11), +0x34 primary (13),
// +0x38 secondary (14), +0x54 ammo (21).
struct Record_guess {
    char pad_0[0x2c];
    RecordTarget_guess* value_2c;
    char pad_30[4];
    RecordTarget_guess* value_34;
    RecordTarget_guess* value_38;
    char pad_3c[0x54 - 0x3c];
    RecordTarget_guess* value_54;
};

struct RecordHost_guess {
    char pad_0[0x10];
    Record_guess sub_10;
};


// EXTERNAL: TITANIUM 0x00576FA0 FUN_00576fa0_guess
void __cdecl FUN_00576fa0_guess(char* dest_guess, const char* source_guess, int length_guess);

// EXTERNAL: TITANIUM 0x00574460 FUN_00574460_guess
int __cdecl FUN_00574460_guess(const char* first_guess, const void* second_guess);

// Item checked by GetContainerTradeskill_guess: race, class and deity bit masks.
struct ItemMasks_guess {
    // EXTERNAL: TITANIUM 0x005EC8B0 ItemMasks_guess::GetRaces_guess
    unsigned int GetRaces_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x005EC990 ItemMasks_guess::GetDeities_guess
    unsigned int GetDeities_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x005EC920 ItemMasks_guess::GetClasses_guess
    unsigned int GetClasses_guess(int first, int second);
};

// EXTERNAL: TITANIUM 0x004167B2 MapLookupValue_guess
int __cdecl MapLookupValue_guess(int value_guess);

struct Owned_guess {
    virtual void Slot00_guess(int flag_guess);
};

struct OwnedSlot_guess {
    char pad_0[0x78];
    Owned_guess* owned_78;
};

// The CHARINFO2 again: slot_10.owned_78 is inventory slot 30 (the cursor), then the cursor coins.
struct Counts_guess {
    char pad_0[0x10];
    OwnedSlot_guess slot_10;
    char pad_8c[0x11e4 - 0x8c];
    int value_11e4;
    int value_11e8;
    int value_11ec;
    int value_11f0;
};

struct GlobalFlags_guess {
    char pad_0[0x10];
    char value_10;
    char value_11;
};

// CDisplay (0x00905D24): +0x10 the cursor holds an item, +0x11 it holds coins (probably).
#define g_flags_905d24_guess EQ_GLOBAL(GlobalFlags_guess*, 0x00905D24)

// The complete EQ_PC. Fields below 0xC280 are often read on the GetCharInfo2 object cast to this view
// (skills, tints, mana), so their offsets are CHARINFO2 offsets. Slot numbers: 0-21 worn (11 range,
// 13 primary, 14 secondary, 21 ammo), 22-29 general, 30 cursor; bag contents are 31 + 10*slot + i, so
// 251-330 for the general bags (EQEmu's Titanium numbering). See GetItemSlotPointer for bank slots.
struct EQ_PCView_guess {
    char value_0;
    char pad_1[7];
    union {
        IndexHolder_guess* holder_8;
        char embedded_8[1];
    };
    char pad_c[0x14];
    Slot_guess slots_20[4];
    char pad_140[0xcf0 - 0x140];
    BoundedArray_guess<MagicEntry_guess*, 0x10> values_cf0;  // bank, 16 slots
    BoundedArray_guess<MagicEntry_guess*, 2> values_d30;  // shared bank, 2 slots (assumed)
    char pad_d38[0xe30 - 0xd38];
    int airSupplyRemaining_0e30_guess;  // air supply (ProcessAirSupply)
    char pad_e34[0xe44 - 0xe34];
    int value_e44;  // points, current (AddPoints; low confidence)
    int value_e48;  // points, lifetime total
    char pad_e4c[8];
    int value_e54;  // own spawn id, matched against the leadership delegates
    char pad_e58[0xf70 - 0xe58];
    int skills_guess[100];
    char pad_1100[0x1170 - 0x1100];
    int values_1170[9];  // body tints (GetBodyTint)
    char pad_1194[0x11a8 - 0x1194];
    int mana_guess;
    char pad_11ac[0x15b0 - 0x11ac];
    char groupMembers_guess[6][0x40];
    char groupLeader_guess;
    char pad_1731[0x1874 - 0x1731];
    int value_1874;  // group Mark NPC delegate id
    int value_1878;  // group Main Assist id
    char pad_187c[0x19b8 - 0x187c];
    int values_19b8[3];  // raid Mark NPC delegate ids
    int values_19c4[3];  // raid Main Assist ids
    char pad_19d0[0xc280 - 0x19d0];
    PcCharacter1View_guess inner_c280;  // EQ_Character1 subobject (MQ2 pCharData1)
    Holder_guess* spawn_guess;
    char value_c28c;  // set when an inventory slot changes (probably a refresh flag)
    char pad_c28d[0xc290 - 0xc28d];
    int str_guess;
    int sta_guess;
    char pad_c298[0xc2c8 - 0xc298];
    int currentWeight_guess;
    char pad_c2cc[0xc330 - 0xc2cc];
    int value_c330;
    char pad_c334[0xc33c - 0xc334];
    int value_c33c;  // AA rank that widens the potion belt
    char pad_c340[8];
    unsigned char value_c348;

    // EXTERNAL: TITANIUM 0x005F0910 EQ_PCView_guess::FUN_005f0910_guess
    int FUN_005f0910_guess(int index);

    // EXTERNAL: TITANIUM 0x005ED7B0 EQ_PCView_guess::FUN_005ed7b0_guess
    void FUN_005ed7b0_guess(int value);

    // EXTERNAL: TITANIUM 0x005ED7D0 EQ_PCView_guess::FUN_005ed7d0_guess
    void FUN_005ed7d0_guess(int value);

    // EXTERNAL: TITANIUM 0x005F0970 EQ_PCView_guess::FUN_005f0970_guess
    int FUN_005f0970_guess(int index);

    // EXTERNAL: TITANIUM 0x005F0DF0 EQ_PCView_guess::FUN_005f0df0_guess
    int FUN_005f0df0_guess(int index);

    // EXTERNAL: TITANIUM 0x005F0C30 EQ_PCView_guess::FUN_005f0c30_guess
    CopyBuffer_guess* FUN_005f0c30_guess(int index);

    // EXTERNAL: TITANIUM 0x005F0C60 EQ_PCView_guess::FUN_005f0c60_guess
    void FUN_005f0c60_guess(int index, CopyBuffer_guess* value);

    // EXTERNAL: TITANIUM 0x005F0CA0 EQ_PCView_guess::FUN_005f0ca0_guess
    void FUN_005f0ca0_guess(int index);

    // EXTERNAL: TITANIUM 0x005EE500 EQ_PCView_guess::FUN_005ee500_guess
    char FUN_005ee500_guess(int index);

    void ClearBandolierSet_guess();
    char HasAltAbility_guess(int value);
    bool IsInGroup_guess();
    bool IsInRaid_guess();
    int HasRaidOfAtLeast_guess(int value);
    bool FUN_004bab58_guess();
    char IsGroupMarkNpcDelegate_guess();
    char IsGroupMainAssist_guess();
    char IsRaidMarkNpcDelegate_guess();
    char IsRaidMainAssist_guess();

    // EXTERNAL: TITANIUM 0x005F0AE0 EQ_PCView_guess::FUN_005f0ae0_guess
    void FUN_005f0ae0_guess(int value, int unused);

    // EXTERNAL: TITANIUM 0x005F0AB0 EQ_PCView_guess::FUN_005f0ab0_guess
    unsigned int FUN_005f0ab0_guess(unsigned int index);

    // EXTERNAL: TITANIUM 0x005F0A00 EQ_PCView_guess::FUN_005f0a00_guess
    int FUN_005f0a00_guess(int index);

    // EXTERNAL: TITANIUM 0x005F0B10 EQ_PCView_guess::FUN_005f0b10_guess
    int FUN_005f0b10_guess(int value);

    // EXTERNAL: TITANIUM 0x005F0B40 EQ_PCView_guess::FUN_005f0b40_guess
    void FUN_005f0b40_guess(int value, int unused);

    // EXTERNAL: TITANIUM 0x005F0B70 EQ_PCView_guess::FUN_005f0b70_guess
    unsigned int FUN_005f0b70_guess(int index);

    // EXTERNAL: TITANIUM 0x005ED490 EQ_PCView_guess::FUN_005ed490_guess
    LookupOwner_guess* FUN_005ed490_guess();

    // EXTERNAL: TITANIUM 0x005F05E0 EQ_PCView_guess::FUN_005f05e0_guess
    int FUN_005f05e0_guess(int index);

    // EXTERNAL: TITANIUM 0x005F0BA0 EQ_PCView_guess::FUN_005f0ba0_guess
    void FUN_005f0ba0_guess(int index, int value);

    void SetDisciplineTimer_guess(int value, int unused);
    unsigned int GetDisciplineTimer_guess(unsigned int index);
    void SetItemRecastTimer_guess(Timed_guess* target, int delta, int index);
    unsigned int GetItemTimerValue(Timed_guess* target);
    char HasDiscipline_guess(int value);
    void SetLinkedReuseTimer_guess(int value, int unused);
    int GetLinkedReuseTimer_guess(int value);
    char IsSpellReuseReady_guess(int value);
    int CostToTrain_guess(int flag_guess, int unused_guess, unsigned int index_guess);
    void ProcessAirSupply_guess();
    bool AtSkillLimit_guess(int skill);
    EQ_PCView_guess* Stats_guess() { return ValueBase_guess()->subobject.GetCharInfo2(); }
    int Skill_guess(int skill) { return ValueBase_guess()->GetSkill_guess(skill); }
    int MaxAirSupply_guess();
    bool ReturnTrue_guess(int unused_guess);
    char RemoveMyAffect_guess(int value);
    void ReapplyAltAbilities_guess();
    void ReplaceBandolierItem_guess(int id_guess, int value_guess, int value2_guess, const char* text_guess);
    void DeleteBandolier_guess(int index_guess);
    int GetPotionBeltSize_guess();

    // EXTERNAL: TITANIUM 0x005F0D40 EQ_PCView_guess::FUN_005f0d40_guess
    void FUN_005f0d40_guess(int value);

    void RemovePotionBeltItem_guess(int value);

    void AddPoints_guess(int value);
    void GetDisciplineEffect_guess();
    char IsUsingDiscipline_guess();
    char IsPlayerRace_guess(int value);
    int IsAGroupMember_guess(char* name);
    int NumInParty_guess();
    int CanUseCombatAbility_guess(int value);
    void ProcessFatigue_guess();
    char DoCombatAbility(int value);
    void ResetPlayerVitals_guess(int value);
    // EXTERNAL: TITANIUM 0x005ED570 EQ_PCView_guess::FUN_005ed570_guess
    void FUN_005ed570_guess(int value);
    // EXTERNAL: TITANIUM 0x005ED8A0 EQ_PCView_guess::FUN_005ed8a0_guess
    void FUN_005ed8a0_guess(int value);
    // EXTERNAL: TITANIUM 0x005ED8E0 EQ_PCView_guess::FUN_005ed8e0_guess
    void FUN_005ed8e0_guess(int value);
    // EXTERNAL: TITANIUM 0x005F0A80 EQ_PCView_guess::FUN_005f0a80_guess
    void FUN_005f0a80_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x005F06B0 EQ_PCView_guess::FUN_005f06b0_guess
    void FUN_005f06b0_guess(int index, int value);
    int GetContainerTradeskill_guess(int kind, ItemMasks_guess* item);
    bool IsGroupLeader_guess();
    int CanLearnLanguage_guess(int index);
    int SpendMoney_guess(int value_guess);
    void PrepareForRepop_guess(int value, int unused);
    int AutoInventoryItem_guess(ItemInstanceView_guess** pp_guess, int value_guess, int unused_guess, char flag_guess);
    void CreateBandolier_guess(int param_1, char* param_2);
    int SaveBandolier_guess(char* name);
    bool BitchCanTrain_guess(int level_guess, int flag_guess, unsigned int index_guess);

    // The virtual base (types.h EQ_CharacterBase_guess, +0xC384) = the vbptr's address + its table offset.
    EQ_CharacterBase_guess* Character_guess() {
        return reinterpret_cast<EQ_CharacterBase_guess*>(reinterpret_cast<char*>(&holder_8) + holder_8->vbaseOffset_0004_guess);
    }

    PcProfileView_guess* Profile_guess() {
        return reinterpret_cast<PcProfileView_guess*>(reinterpret_cast<char*>(&holder_8) + holder_8->vbaseOffset_0004_guess);
    }
    RankBase_guess* ProfileBase_guess() {
        return reinterpret_cast<RankBase_guess*>(Profile_guess());
    }

    CharInfo2View_guess* FindResult_guess() {
        ValueEntry_guess* entry = ValueBase_guess();
        return reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2());
    }

    Counts_guess* FindCounts_guess() {
        ValueEntry_guess* entry =
            reinterpret_cast<ValueEntry_guess*>(reinterpret_cast<char*>(&holder_8) + holder_8->vbaseOffset_0004_guess);
        return reinterpret_cast<Counts_guess*>(entry->subobject.GetCharInfo2());
    }

    ValueEntry_guess* ValueBase_guess() {
        return reinterpret_cast<ValueEntry_guess*>(
            &reinterpret_cast<ByteView_guess*>(this)->bytes_guess[holder_8->vbaseOffset_0004_guess + 8]);
    }

    RecordHost_guess* FindRecord_guess() {
        return reinterpret_cast<RecordHost_guess*>(FindResult_guess());
    }

    // EXTERNAL: TITANIUM 0x0041680E EQ_PCView_guess::FUN_0041680e_guess
    int FUN_0041680e_guess();
    bool IsMyClassGuildmaster_guess(Target_guess* target);
    char FUN_004bc20b_guess(Target_guess* target);

    // EXTERNAL: TITANIUM 0x005FBA70 EQ_PCView_guess::FUN_005fba70_guess
    int FUN_005fba70_guess();
    char IsMeleeClass_guess();

    void AddToSkill_guess(unsigned int index, int value);
    char FitsEquipSlot_guess(int index, ItemInstanceView_guess* player);
    bool ConsumeSlotItem_guess(int value, int amount);
    char CanEquipItem_guess(ItemInstanceView_guess* player, int index, int value);
    bool HasGroupOfAtLeast_guess(int value);
    void EmptyPossessionSlots_guess();
    int GetArmorTint_guess(int index);
    void SetArmorTint_guess(int index, int value);
    EntryNode_guess* FindItemByKey_guess(int first_guess, int second_guess, int* index_guess);
    EntryNode_guess* NodeAt_guess(int index_guess) {
        return reinterpret_cast<ValueEntry_guess*>(&embedded_8[holder_8->vbaseOffset_0004_guess])->GetNode_guess(index_guess);
    }
    MagicEntry_guess** GetItemSlotPointer_guess(unsigned int index_guess);
    void DestroyHeldItemOrMoney();

    // EXTERNAL: TITANIUM 0x005F0CD0 EQ_PCView_guess::FUN_005f0cd0_guess
    int* FUN_005f0cd0_guess(int index);
    // EXTERNAL: TITANIUM 0x005F0D00 EQ_PCView_guess::FUN_005f0d00_guess
    void FUN_005f0d00_guess(int index, SendText_guess* text);
    void AddPotionBeltItem_guess(int index, int second);
    void UsePotionBeltItem_guess(int index);
    void UseBandolier_guess(int value);
};

inline EQ_PCView_guess* PcCharacter1View_guess::Owner_guess() {
    return reinterpret_cast<EQ_PCView_guess*>(reinterpret_cast<char*>(this) - offsetof(EQ_PCView_guess, inner_c280));
}

// FUNCTION: TITANIUM 0x004BAC86
// EQ_Character1 vtable slot 5; `this` is the +0xC280 subobject. "Shared bank" assumes the 2 entries are it.
int PcCharacter1View_guess::GetSharedBankItem_guess(int index) {
    if (index < 0 || index >= 2) {
        return 0;
    }
    EQ_PCView_guess* owner = Owner_guess();
    return owner->FUN_005f0df0_guess(index);
}

struct CallbackOwner_guess;

struct FlagHolder_guess {  // the vbtable of the +0xC280 subobject ({-4, 0x100})
    char pad_0[4];
    int base_4;               // signed displacement of the virtual base from the vbptr (not an address)
};

struct InnerCallback_guess {
    char pad_0[4];
    FlagHolder_guess* holder_4;
    char pad_8[0x20 - 0x8];
    int value_20;
    int value_24;
    int value_28;
    char pad_2c[0x54 - 0x2c];
    int value_54;

    // EXTERNAL: TITANIUM 0x004106A3 InnerCallback_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int first, int second, int third, int fourth);

    int Max_Mana();

    // The virtual base (types.h EQ_CharacterBase_guess) through this subobject's own vbptr (+4).
    EQ_CharacterBase_guess* Character_guess() {
        return reinterpret_cast<EQ_CharacterBase_guess*>(reinterpret_cast<char*>(this) + 4 + holder_4->base_4);
    }
    CallbackOwner_guess* Owner_guess();       // the EQ_PC this +0xC280 subobject belongs to
    ValueEntry_guess* OwnerValueBase_guess();  // the virtual base, through the owner's vbptr
};

struct CallbackOwner_guess {
    char pad_0[8];
    IndexHolder_guess* holder_8;  // the vbptr
};

inline CallbackOwner_guess* InnerCallback_guess::Owner_guess() {
    return reinterpret_cast<CallbackOwner_guess*>(reinterpret_cast<char*>(this) - offsetof(EQ_PCView_guess, inner_c280));
}

// -0xC278 = the owner's vbptr (+8 there). Written from `this`, not as Owner_guess() + 8: the original keeps
// `this` in esi and addresses the vbptr as [esi-0xC278] (0x004BC454 goes structural otherwise).
inline ValueEntry_guess* InnerCallback_guess::OwnerValueBase_guess() {
    return reinterpret_cast<ValueEntry_guess*>(reinterpret_cast<char*>(this) - 0xc278 + Owner_guess()->holder_8->vbaseOffset_0004_guess);
}

struct CallbackGlobal_guess {
    // EXTERNAL: TITANIUM 0x004B4FE9 CallbackGlobal_guess::GetManaBonus_guess
    int GetManaBonus_guess(CallbackOwner_guess* owner_guess);
};

#define g_callbackGlobal_guess EQ_GLOBAL(CallbackGlobal_guess*, 0x009859EC)

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    EQ_PCView_guess* GetCharInfo2(int first, int second);
};

struct PcCharacterView_guess {
    char pad_0[4];
    EQ_CharacterProfileView_guess subobject;

    void AddSkillValue_guess(int first, int second);
};

struct ObjectCall_guess {
    // EXTERNAL: TITANIUM 0x004BC581 ObjectCall_guess::AddToSkill_guess
    void AddToSkill_guess();
};

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(char* first, char* second);

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0046DC2E FormatTokenStringToClient_guess
void __cdecl FormatTokenStringToClient_guess(PcCharacter1View_guess* inner, int code, int flags, int arg,
    char* first, char* second, char* third, int a, int b, int c, int d, int e, int f);

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value);

// EXTERNAL: TITANIUM 0x004649B1 token_string_to_client_guess
void __cdecl token_string_to_client_guess(PcCharacter1View_guess* inner, int first, int second, int third);

// FUNCTION: TITANIUM 0x004BAAC6
// `this` is a bandolier set (CopyBuffer_guess), not an EQ_PC: clears the name and each item's id, icon and
// name. Only caller: CreateBandolier, on its local set.
void EQ_PCView_guess::ClearBandolierSet_guess() {
    value_0 = 0;
    int* words_end = slots_20[0].words + 2;
    int count = 4;
    do {
        words_end[-2] = 0;
        words_end[-1] = 0;
        *((char*)words_end) = 0;
        words_end += 0x12;
        --count;
    } while (count != 0);
}

// FUNCTION: TITANIUM 0x004BAAEB
// Scans the 240 AA slots (profile aa_array).
char EQ_PCView_guess::HasAltAbility_guess(int value) {
    int index = 0;
    if (value > 0) {
        do {
            if (FUN_005f0910_guess(index) == value) {
                return 1;
            }
            ++index;
        } while (index < 0xf0);
    }
    return 0;
}

// True when the character is in a group (a group leader name is set).
// FUNCTION: TITANIUM 0x004BAB19
bool EQ_PCView_guess::IsInGroup_guess() {
    return groupLeader_guess != 0;
}

// FUNCTION: TITANIUM 0x004BAB25
// The three raid tests ask the raid object at 0x0091D708; their names are low confidence.
bool EQ_PCView_guess::IsInRaid_guess() {
    return EQ_GLOBAL(State_guess, 0x0091D708).IsInRaid_guess();
}

// 1 when the player is in a raid (0x0042FCC2) of at least `value` members, else 0.
// FUNCTION: TITANIUM 0x004BAB2F
int EQ_PCView_guess::HasRaidOfAtLeast_guess(int value) {
    State_guess* state = &EQ_GLOBAL(State_guess, 0x0091D708);
    if (state->IsInRaid_guess() && state->GetMemberCount_guess() >= value) {
        return 1;
    }
    return 0;
}

// Whether the player is the raid leader (raid state 0x0091D708).
// FUNCTION: TITANIUM 0x004BAB58
bool EQ_PCView_guess::FUN_004bab58_guess() {
    return EQ_GLOBAL(State_guess, 0x0091D708).IsRaidLeader_guess();
}

// FUNCTION: TITANIUM 0x004BAB62
// Leadership delegates: own spawn id (+0xE54) against the ids sent by the server, 1 per group role and
// 3 per raid role. CheckActionAllowed accepts the leader or the delegate.
char EQ_PCView_guess::IsGroupMarkNpcDelegate_guess() {
    int expected = value_e54;
    int count = 0;
    int* value = &value_1874;
    do {
        if (expected == *value) {
            return 1;
        }
        ++count;
        ++value;
    } while (count < 1);
    return 0;
}

// True when the player's own spawn id (+0xE54) is the group Main Assist (+0x1878). Written as a one-entry
// loop like the raid checks.
// FUNCTION: TITANIUM 0x004BAB86
char EQ_PCView_guess::IsGroupMainAssist_guess() {
    int expected = value_e54;
    int count = 0;
    int* value = &value_1878;
    do {
        if (expected == *value) {
            return 1;
        }
        ++count;
        ++value;
    } while (count < 1);
    return 0;
}

// True when the player's own spawn id (+0xE54) is one of the three raid Mark NPC delegates (+0x19B8).
// FUNCTION: TITANIUM 0x004BABAA
char EQ_PCView_guess::IsRaidMarkNpcDelegate_guess() {
    int expected = value_e54;
    int count = 0;
    int* value = values_19b8;
    do {
        if (expected == *value) {
            return 1;
        }
        ++count;
        ++value;
    } while (count < 3);
    return 0;
}

// True when the player's own spawn id (+0xE54) is one of the three raid Main Assists (+0x19C4).
// FUNCTION: TITANIUM 0x004BABCE
char EQ_PCView_guess::IsRaidMainAssist_guess() {
    int expected = value_e54;
    int count = 0;
    int* value = values_19c4;
    do {
        if (expected == *value) {
            return 1;
        }
        ++count;
        ++value;
    } while (count < 3);
    return 0;
}

// FUNCTION: TITANIUM 0x004BABF2
// Three 20-entry timer arrays follow: discipline (opcode 0x53DF DisciplineTimer), item recast, and linked
// reuse (0x6A00 LinkedReuse). Values are absolute times in seconds from 0x00576E80.
void EQ_PCView_guess::SetDisciplineTimer_guess(int value, int unused) {
    if (value >= 0 && value < 0x14) {
        FUN_005f0ae0_guess(value, unused);
    }
}

// FUNCTION: TITANIUM 0x004BAC08
// No range check, unlike the setter.
unsigned int EQ_PCView_guess::GetDisciplineTimer_guess(unsigned int index) {
    return FUN_005f0ab0_guess(index);
}

// FUNCTION: TITANIUM 0x004BAC0D
// Stamps the item (+0x54) and its recast type's slot `index` with now + delta.
void EQ_PCView_guess::SetItemRecastTimer_guess(Timed_guess* target, int delta, int index) {
    int now = FUN_00576e80_guess();
    if (target != 0) {
        target->recastEndTime_0054_guess = now + delta;
    }
    if (index >= 0 && index < 0x14) {
        FUN_005f0ba0_guess(index, now + delta);
    }
}

// FUNCTION: TITANIUM 0x004BAC48
// MQ2 EQ_PC::GetItemTimerValue: the later of the item's stamp and its recast type's timer.
unsigned int EQ_PCView_guess::GetItemTimerValue(Timed_guess* target) {
    if (target != 0) {
        unsigned int value = target->recastEndTime_0054_guess;
        unsigned int result = 0;
        int index = target->FUN_005e05f0_guess();
        if (index >= 0 && index < 0x14) {
            result = FUN_005f0b70_guess(index);
        }
        if (value > result) {
            return value;
        }
        return result;
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004BACA6
// The 100 known disciplines (MQ2 CombatAbilities).
char EQ_PCView_guess::HasDiscipline_guess(int value) {
    int index = 0;
    do {
        if (FUN_005f0a00_guess(index) == value) {
            return 1;
        }
        ++index;
    } while (index < 100);
    return 0;
}

// Sets linked reuse timer `value` (0-19, CHARINFO2 +0x3CF4) to `unused`; other indexes are ignored.
// FUNCTION: TITANIUM 0x004BACCB
void EQ_PCView_guess::SetLinkedReuseTimer_guess(int value, int unused) {
    if (value >= 0 && value < 0x14) {
        FUN_005f0b40_guess(value, unused);
    }
}

// Linked reuse timer `value` (0-19, CHARINFO2 +0x3CF4); 0 for other indexes.
// FUNCTION: TITANIUM 0x004BACE1
int EQ_PCView_guess::GetLinkedReuseTimer_guess(int value) {
    if (value < 0 || value >= 0x14) {
        return 0;
    }
    return FUN_005f0b10_guess(value);
}

// FUNCTION: TITANIUM 0x004BACFB
// Not ready while the spell's linked timer runs with less than its recast (ms -> s) left.
char EQ_PCView_guess::IsSpellReuseReady_guess(int value) {
    EQ_SpellView_guess* entity = EQ_GLOBAL(SpellManagerView_guess*, 0x00985CC8)->GetSpell_guess(value);
    unsigned int now = FUN_00576e80_guess();
    if (entity == 0) {
        return 0;
    }
    int index = entity->reuseTimerIndex_01c0_guess;
    if (index > 0 && index < 0x14 && (unsigned int)GetLinkedReuseTimer_guess(index) > now &&
        (unsigned int)(GetLinkedReuseTimer_guess(index) - now) < entity->recastTime_001c_guess / 1000) {
        return 0;
    }
    return 1;
}

// FUNCTION: TITANIUM 0x004BAD65
// Also referenced from the tables at 0x00664D94/0x00664D98.
bool EQ_PCView_guess::ReturnTrue_guess(int unused_guess) {
    return true;
}

// FUNCTION: TITANIUM 0x004BAD6A
// `value` is a buff slot. Spells without the removable flag (+0x17D) get string 0x89, "You cannot remove
// this effect."
char EQ_PCView_guess::RemoveMyAffect_guess(int value) {
    Result_guess* result = 0;
    if (value >= 0) {
        if (value < (int)inner_c280.GetMaxBuffs_guess()) {
            result = inner_c280.GetBuff_guess(value);
        }
    }
    if (spawn_guess != 0 && result != 0) {
        if (IsValidSpellIndex_guess(result->value_4)) {
            EQ_SpellView_guess* entity = EQ_GLOBAL(SpellManagerView_guess*, 0x00985CC8)->GetSpell_guess(result->value_4);
            if (entity != 0) {
                if (entity->FindAffectSlot_guess(0x65) == 0 && entity->goodEffect_017d_guess != 0) {
                    inner_c280.RemovePCAffect_guess(result);
                    inner_c280.NotifyPCAffectChange_guess(value, 1);
                    return 1;
                }
            }
        }
        token_string_to_client_guess(&inner_c280, 0x89, 0xd, 0);
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004BAE1C
// Low confidence; only caller Handle_OP_RespondAA (0x004534ED).
void EQ_PCView_guess::ReapplyAltAbilities_guess() {
    int index = 0;
    FUN_005ed7b0_guess(index);
    do {
        if (FUN_005f0910_guess(index) > 0) {
            FUN_005ed7d0_guess(FUN_005f0970_guess(index));
        }
        ++index;
    } while (index < 0xf0);
}

// FUNCTION: TITANIUM 0x004BAE50
// EQEmu BANDOLIERS_SIZE.
int __cdecl GetBandolierCount_guess() {
    return 4;
}

// FUNCTION: TITANIUM 0x004BAE54
// @early-stop: budget, structural ndiff=11
// In every named set, items with id `id_guess` get the new id, icon and name.
void EQ_PCView_guess::ReplaceBandolierItem_guess(int id_guess, int value_guess, int value2_guess, const char* text_guess) {
    int index_guess = 0;
    for (;;) {
        if (index_guess >= 4) {
            break;
        }
        CopyBuffer_guess data_guess = *FUN_005f0c30_guess(index_guess);
        if (data_guess.active != 0) {
            SlotCopy_guess* slot_guess = data_guess.slots;
            int count_guess = 4;
            do {
                if (slot_guess->values[0] == id_guess) {
                    slot_guess->values[0] = value_guess;
                    slot_guess->values[1] = value2_guess;
                    FUN_00576fa0_guess(slot_guess->text, text_guess, 0x40);
                }
                ++slot_guess;
                --count_guess;
            } while (count_guess != 0);
            FUN_005f0c60_guess(index_guess, &data_guess);
        }
        ++index_guess;
    }
}

// FUNCTION: TITANIUM 0x004BAEEE
// Sends Bandolier (0x6F0C) action 1 = delete, 0x28 bytes. The < 20 check is wider than the 4 sets.
void EQ_PCView_guess::DeleteBandolier_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < 0x14) {
        FUN_005f0ca0_guess(index_guess);
        if (pinstCBandolierWnd_guess != 0) {
            pinstCBandolierWnd_guess->RebuildList_guess();
        }
        struct SendData_guess {
            int value;
            char index;
            char pad_5[0x23];
        } data_guess;
        data_guess.value = 1;
        data_guess.index = (char)index_guess;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_Bandolier, &data_guess, 0x28, 1);
    }
}

// FUNCTION: TITANIUM 0x004BAF4D
// 2 + the AA rank at +0xC33C, at most 4 (EQEmu POTION_BELT_SIZE).
int EQ_PCView_guess::GetPotionBeltSize_guess() {
    int value = value_c33c + 2;
    if (value > 4) {
        value = 4;
    }
    return value;
}

// FUNCTION: TITANIUM 0x004BAF5E
// Sends PotionBelt (0x719) action 1 = remove.
void EQ_PCView_guess::RemovePotionBeltItem_guess(int value) {
    if (value < 0 || value >= GetPotionBeltSize_guess()) {
        return;
    }
    FUN_005f0d40_guess(value);
    Message_guess message;
    message.type = 1;
    message.value = value;
    message.unused = 0;
    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_PotionBelt, &message, 0xc, 1);
    pinstCPotionBeltWnd_guess->Refresh_guess();
}

// FUNCTION: TITANIUM 0x004BAFB1
// `value_guess` is the class: cleric, paladin, ranger, druid, shaman, beastlord (2-4, 6, 10, 15) use
// `first_guess` (WIS), the rest `second_guess` (INT). Above 100, and again above 200, the stat is reshaped.
int __cdecl CalcCastingStat_guess(int value_guess, int first_guess, int second_guess) {
    int result;
    if (value_guess >= 2 && (value_guess <= 4 || value_guess == 6 || value_guess == 10 || value_guess == 15)) {
        result = first_guess;
    } else {
        result = second_guess;
    }
    if (result > 100) {
        if (result > 200) {
            result += (result - 200) / -2;
        }
        result += (result * 3 - 300) / 2;
    }
    return result;
}

// FUNCTION: TITANIUM 0x004BB006
// Low confidence; only caller the task opcode switch (case 0x1D6E). Gains also add to the lifetime total.
void EQ_PCView_guess::AddPoints_guess(int value) {
    value_e44 += value;
    if (value > 0) {
        value_e48 += value;
    }
}

// FUNCTION: TITANIUM 0x004BB01D
// Low confidence; the effect it looks up is discarded.
void EQ_PCView_guess::GetDisciplineEffect_guess() {
    int value = inner_c280.FUN_0040db4e_guess(0, 1);
    inner_c280.GetBuff_guess(value);
}

// FUNCTION: TITANIUM 0x004BB039
// DoCombatAbility prints "You are already using a discipline!" (0x16BD) when this is true.
char EQ_PCView_guess::IsUsingDiscipline_guess() {
    return inner_c280.FUN_00411ea4_guess(0, 1, -1) == -1;
}

// FUNCTION: TITANIUM 0x004BB05D
// @early-stop: budget, structural ndiff=15
// EQ_Character1 vtable slot 4 (MQ2 CapStat). Types 0-6 (stats) cap at 255 up to level 60, then at
// level*5 - 45 plus the SPA 0x106 cap raises for that stat and for all. Types 7-12 (probably resists)
// cap at 500, (level + 35) * 5 above level 65, plus SPA 0x106, with no floor; the other paths floor at 1.
int PcCharacter1View_guess::CapStat_guess(int value, int type) {
    int result;
    if (type >= 0) {
        if (type > 6) {
            if (type <= 0xc) {
                result = 500;
                EQ_PCView_guess* owner = Owner_guess();
                if (owner->FindResult_guess()->level_guess > 0x41) {
                    result = (owner->FindResult_guess()->level_guess + 0x23) * 5;
                }
                result += TotalSpellAffects_guess(0x106, 1, type, 1);
                return value > result ? result : value;
            }
        } else {
            EQ_PCView_guess* owner = Owner_guess();
            if (owner->FindResult_guess()->level_guess > 0x3c) {
                result = owner->FindResult_guess()->level_guess;
                result = TotalSpellAffects_guess(0x106, 1, type, 1) + TotalSpellAffects_guess(0x106, 1, -1, 1) + result * 5 - 0x2d;
                result = value > result ? result : value;
                if (result < 1) {
                    result = 1;
                }
                return result;
            }
        }
    }
    if (value > 0xff) {
        value = 0xff;
    }
    if (value < 1) {
        value = 1;
    }
    return value;
}

// FUNCTION: TITANIUM 0x004BB181
// Races 1-12, 128 Iksar, 130 Vah Shir, 330 Froglok; -1 tests the character's own race.
char EQ_PCView_guess::IsPlayerRace_guess(int value) {
    if (value != -1) {
        if (value <= 0xc || value == 0x80 || value == 0x82 || value == 0x14a) {
            return 1;
        }
    } else if (FindResult_guess()->race_guess <= 0xc || FindResult_guess()->race_guess == 0x80 ||
               FindResult_guess()->race_guess == 0x82 || FindResult_guess()->race_guess == 0x14a) {
        return 1;
    }
    return 0;
}

// A name pointer below 0x10 or an empty name counts as no name.
static bool IsValidName_guess(const char* name) {
    return (unsigned int)name >= 0x10 && *name != 0;
}

// FUNCTION: TITANIUM 0x004BB226
// The own name is at +0x44 of the CHARINFO2 base; a pointer below 0x10 counts as no name.
int EQ_PCView_guess::IsAGroupMember_guess(char* name) {
    if (!IsValidName_guess(name)) {
        return 0;
    }
    if (__stricmp(name, reinterpret_cast<char*>(&reinterpret_cast<ByteView_guess*>(this)->bytes_guess[holder_8->vbaseOffset_0004_guess + 0x44])) == 0) {
        return 1;
    }
    int index = 0;
    char* current = groupMembers_guess[0];
    do {
        if (__stricmp(name, current) == 0) {
            return 1;
        }
        ++index;
        current += 0x40;
    } while (index < 6);
    return 0;
}

// FUNCTION: TITANIUM 0x004BB2A1
// Self plus every non-empty member name that isn't the own name.
int EQ_PCView_guess::NumInParty_guess() {
    int result = 0;
    int count = 6;
    ++result;
    char* name = groupMembers_guess[0];
    do {
        if (*name != 0 && __stricmp(name, Character_guess()->Name) != 0) {
            ++result;
        }
        name += 0x40;
        --count;
    } while (count != 0);
    return result;
}

// FUNCTION: TITANIUM 0x004BB2DD
// 0 not a combat ability, -1 wrong class, -2 level too low, -3 wrong deity, 1 usable.
int EQ_PCView_guess::CanUseCombatAbility_guess(int value) {
    EQ_SpellView_guess* entity = EQ_GLOBAL(SpellManagerView_guess*, 0x00985CC8)->GetSpell_guess(value);
    if (entity == 0) {
        return 0;
    }
    if (entity->value_1c4 == 0) {
        return 0;
    }

    ValueEntry_guess* entry;
    entry = ValueBase_guess();
    if (entity->GetSpellLevelNeeded_guess(reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2())->classId_guess) == -1) {
        return -1;
    }

    int count;
    unsigned char current;
    entry = ValueBase_guess();
    current = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2())->classId_guess;
    entry = ValueBase_guess();
    count = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2())->level_guess;
    if ((int)(unsigned char)entity->GetSpellLevelNeeded_guess(current) > count) {
        return -2;
    }
    if (entity->value_23c == 0 || entity->value_23c == FUN_0041680e_guess()) {
        return 1;
    }
    return -3;
}

// True when the character's name equals the group leader name, ignoring case.
// FUNCTION: TITANIUM 0x004BB282
bool EQ_PCView_guess::IsGroupLeader_guess() {
    return __stricmp(Character_guess()->Name, &groupLeader_guess) == 0;
}

// FUNCTION: TITANIUM 0x004BB39D
// MQ2 EQ_Character::doCombatAbility. A pending flag on the spawn (+0x1A8, +0x107C) skips the known/usable
// test once. While the timer runs it prints 0x16AF / 0x16B0 ("You can use the ability %1 again in ...", with
// and without hours); it then compares only the seconds part of the remaining time with the recast, as the
// original does. Casts through 0x00411F3D with kind 10.
char EQ_PCView_guess::DoCombatAbility(int value) {
    char hours_text[32];
    char minutes_text[32];
    char seconds_text[16];
    bool pending_guess = false;
    if (spawn_guess != 0 && spawn_guess->pending_1a8 != 0 && spawn_guess->pending_1a8->value_107c == 1) {
        spawn_guess->pending_1a8->value_107c = 0;
        pending_guess = true;
    }
    char found_guess = HasDiscipline_guess(value);
    if ((found_guess != 0 && CanUseCombatAbility_guess(value) == 1) || pending_guess) {
        EQ_SpellView_guess* entity = EQ_GLOBAL(SpellManagerView_guess*, 0x00985CC8)->GetSpell_guess(value);
        if (entity != 0) {
            int timer_guess = entity->reuseTimerIndex_01c0_guess;
            if (FUN_005f0ab0_guess(timer_guess) > FUN_00576e80_guess()) {
                int remaining = FUN_005f0ab0_guess(timer_guess) - FUN_00576e80_guess();
                int hours = (unsigned int)remaining / 0xe10;
                remaining += hours * -0xe10;
                unsigned int minutes = (unsigned int)remaining / 60;
                unsigned int seconds = (unsigned int)remaining % 60;
                __itoa(hours, hours_text, 10);
                __itoa(minutes, minutes_text, 10);
                __itoa(seconds, seconds_text, 10);
                if (hours != 0) {
                    FormatTokenStringToClient_guess(&inner_c280, 0x16af, 0x10f, entity->name_0208_guess,
                        hours_text, minutes_text, seconds_text, 0, 0, 0, 0, 0, 0);
                } else {
                    FormatTokenStringToClient_guess(&inner_c280, 0x16b0, 0x10f, entity->name_0208_guess,
                        minutes_text, seconds_text, 0, 0, 0, 0, 0, 0, 0);
                }
                if (seconds < entity->recastTime_001c_guess / 1000) {
                    return 0;
                }
            }
            if (entity->durationFormula_0020_guess == 0 || entity->targetType_0180_guess != 6 || IsUsingDiscipline_guess() == 0) {
                Quad_guess range;
                reinterpret_cast<int*>(range.bytes_guess)[1] = -1;
                reinterpret_cast<int*>(range.bytes_guess)[2] = -1;
                reinterpret_cast<int*>(range.bytes_guess)[0] = 0;
                reinterpret_cast<int*>(range.bytes_guess)[3] = 0;
                inner_c280.CastSpell(10, value, 0, range, 0);
                return 1;
            }
            token_string_to_client_guess(&inner_c280, 0x16bd, 0x10f, 0);
        }
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004BB574
// HP, mana and endurance to their maxima (0x00416963, Max_Mana slot 2, 0x00416A40); `value` == 0 then
// zeroes the mana. Same as ResetPlayerVitals in the earlier sibling decomp.
void EQ_PCView_guess::ResetPlayerVitals_guess(int value) {
    // &embedded_8[...] (the virtual base, not Character_guess()): the binary computes the object after the
    // argument's call; an inline accessor is evaluated first (0x004BB574 goes structural).
    reinterpret_cast<OffsetSubobject_guess*>(&embedded_8[holder_8->vbaseOffset_0004_guess])->FUN_00417cc8_guess(inner_c280.Max_HP_guess(0));
    reinterpret_cast<OffsetSubobject_guess*>(&embedded_8[holder_8->vbaseOffset_0004_guess])->FUN_0040e293_guess(inner_c280.Slot02_guess());
    reinterpret_cast<OffsetSubobject_guess*>(&embedded_8[holder_8->vbaseOffset_0004_guess])->FUN_00417cb3_guess(inner_c280.Max_Endurance());

    Character_guess()->field_0FC = 0;
    Character_guess()->field_104 = 100;
    if (value == 0) {
        OffsetValueEntry_guess* entry = reinterpret_cast<OffsetValueEntry_guess*>(Character_guess());
        EQ_PCView_guess* object = entry->GetCharInfo2();
        object->mana_guess = 0;
    }
    EQ_GLOBAL(char, 0x009238E0) = 0;
    EQ_GLOBAL(int, 0x009238D8) = 0;
    EQ_GLOBAL(int, 0x009238DC) = 0;
}

// FUNCTION: TITANIUM 0x004BB618
// Low confidence (maybe endurance regen). Hunger or thirst at 0 zero the amount; running (0x009237B4) and
// carrying too much cost level/15 each. Monks (class 7) use a level table for the weight limit, not STR.
void EQ_PCView_guess::ProcessFatigue_guess() {
    ValueEntry_guess* entry_guess = ValueBase_guess();
    int delay_guess = reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())
        ->FUN_005fbae0_guess();
    bool scale_guess = false;
    bool adjust_guess = false;

    entry_guess = ValueBase_guess();
    if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->hunger_guess == 0 ||
        ((entry_guess = ValueBase_guess()),
        reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->thirst_guess == 0)) {
        delay_guess = 0;
    }
    if (EQ_GLOBAL(char, 0x009858C7) == 0 && delay_guess > 0) {
        delay_guess += delay_guess / 2;
    }
    if (EQ_GLOBAL(char, 0x009237B4) == 1 &&
        spawn_guess->value_48 != EQ_ARRAY(float, 0x0063F4CC)[0]) {
        scale_guess = true;
    }

    entry_guess = ValueBase_guess();
    if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->classId_guess == Class_Monk) {
        int limit_guess = 0x1e;
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0xe) {
            limit_guess = 0x20;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x1d) {
            limit_guess = 0x22;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x2c) {
            limit_guess = 0x24;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x32) {
            limit_guess = 0x26;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x36) {
            limit_guess = 0x28;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x3b) {
            limit_guess = 0x2d;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x3d) {
            limit_guess = 0x2f;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x3f) {
            limit_guess = 0x32;
        }
        entry_guess = ValueBase_guess();
        if (reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess > 0x40) {
            limit_guess = 0x35;
        }
        if (currentWeight_guess > limit_guess) {
            adjust_guess = true;
        }
    } else if (currentWeight_guess > str_guess) {
        adjust_guess = true;
    }

    if (scale_guess) {
        entry_guess = ValueBase_guess();
        delay_guess += reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess / -0xf;
    }
    if (adjust_guess) {
        entry_guess = ValueBase_guess();
        delay_guess += reinterpret_cast<CharInfo2View_guess*>(entry_guess->subobject.GetCharInfo2())->level_guess / -0xf;
    }
    int bonus_guess = value_c330;
    if (bonus_guess > 0xf) {
        bonus_guess = 0xf;
    }
    delay_guess += bonus_guess;
    if (spawn_guess != 0) {
        delay_guess = (int)(delay_guess * spawn_guess->value_28 + EQ_ARRAY(double, 0x006410A0)[0]);
    }
    ValueBase_guess()->FUN_0040e2bd_guess(delay_guess);
    inner_c280.Cur_Endurance_guess();
}

// FUNCTION: TITANIUM 0x004BB89C
// Container type -> tradeskill skill id, or -1: 55 fishing, 56 make poison, 57 tinkering, 58 research,
// 59 alchemy, 60 baking, 61 tailoring, 63 blacksmithing, 64 fletching, 65 brewing, 68 jewelry, 69 pottery.
// Race- or class-only containers refuse with strings 0x135-0x146 and 0x1698. The mask tests run crosswise:
// the class id meets GetRaces_guess's mask and MapLookupValue(race) GetClasses_guess's, so those two
// names (0x005EC8B0/0x005EC920) are probably swapped. Refusals: 0x1736 (first mask), 0x1737 (deity), 0x1738.
int EQ_PCView_guess::GetContainerTradeskill_guess(int kind, ItemMasks_guess* item) {
    int classIndex = MapLookupValue_guess(FindResult_guess()->race_guess);
    if (item != 0) {
        if (item->GetRaces_guess(0, 1) != 0) {
            unsigned char race = FindResult_guess()->classId_guess;
            if ((item->GetRaces_guess(0, 1) & (1 << (race - 1))) == 0) {
                token_string_to_client_guess(&inner_c280, 0x1736, 0xd, 0);
                return -1;
            }
        }
        if (item->GetDeities_guess(0, 1) != 0) {
            int deity = FUN_0041680e_guess();
            if ((deity & item->GetDeities_guess(0, 1)) == 0) {
                token_string_to_client_guess(&inner_c280, 0x1737, 0xd, 0);
                return -1;
            }
        }
        if (item->GetClasses_guess(0, 1) != 0 &&
            (item->GetClasses_guess(0, 1) & (1 << (classIndex - 1))) == 0) {
            token_string_to_client_guess(&inner_c280, 0x1738, 0xd, 0);
            return -1;
        }
    }
    switch (kind) {
    case 9:
        return 0x3b;
    case 10:
        return 0x39;
    case 12:
        return 0x38;
    case 14:
    case 15:
    case 0x36:
        return 0x3c;
    case 0x13:
        return 0x41;
    case 0x14:
        return 0x44;
    case 0x2e:
        return 0x37;
    case 0x18:
        if (FindResult_guess()->classId_guess != Class_Wizard) {
            token_string_to_client_guess(&inner_c280, 0x135, 0xd, 0);
            return -1;
        }
        return 0x3a;
    case 0x19:
        if (FindResult_guess()->classId_guess != Class_Magician) {
            token_string_to_client_guess(&inner_c280, 0x136, 0xd, 0);
            return -1;
        }
        return 0x3a;
    case 0x1a:
        if (FindResult_guess()->classId_guess != Class_Necromancer) {
            token_string_to_client_guess(&inner_c280, 0x137, 0xd, 0);
            return -1;
        }
        return 0x3a;
    case 0x1b:
        if (FindResult_guess()->classId_guess != Class_Enchanter) {
            token_string_to_client_guess(&inner_c280, 0x138, 0xd, 0);
            return -1;
        }
        return 0x3a;
    case 0x1d:
        if (FindResult_guess()->classId_guess != Class_Wizard && FindResult_guess()->classId_guess != Class_Magician &&
            FindResult_guess()->classId_guess != Class_Necromancer && FindResult_guess()->classId_guess != Class_Enchanter) {
            return -1;
        }
        // fall through
    case 11:
        return 0x3a;
    case 0x1f:
        if (FindResult_guess()->race_guess != 5) {
            token_string_to_client_guess(&inner_c280, 0x139, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x20:
        if (FindResult_guess()->race_guess != 6) {
            token_string_to_client_guess(&inner_c280, 0x13a, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x21:
        if (FindResult_guess()->race_guess != 10) {
            token_string_to_client_guess(&inner_c280, 0x13b, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x22:
        if (FindResult_guess()->race_guess != 8) {
            token_string_to_client_guess(&inner_c280, 0x13c, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x23:
        if (FindResult_guess()->race_guess != 12) {
            token_string_to_client_guess(&inner_c280, 0x13d, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x24:
        if (FindResult_guess()->race_guess != 2) {
            token_string_to_client_guess(&inner_c280, 0x13e, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x26:
        if (FindResult_guess()->race_guess != 0x80) {
            token_string_to_client_guess(&inner_c280, 0x13f, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x27:
    case 0x28:
        if (FindResult_guess()->race_guess != 1) {
            token_string_to_client_guess(&inner_c280, 0x140, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x29:
        if (FindResult_guess()->race_guess != 11) {
            token_string_to_client_guess(&inner_c280, 0x141, 0xd, 0);
            return -1;
        }
        return 0x3d;
    case 0x2a:
        if (FindResult_guess()->race_guess != 3) {
            token_string_to_client_guess(&inner_c280, 0x142, 0xd, 0);
            return -1;
        }
        return 0x3d;
    case 0x2b:
        if (FindResult_guess()->race_guess != 4) {
            token_string_to_client_guess(&inner_c280, 0x143, 0xd, 0);
            return -1;
        }
        // fall through
    case 0x10:
        return 0x3d;
    case 0x2c:
        if (FindResult_guess()->race_guess != 4) {
            token_string_to_client_guess(&inner_c280, 0x144, 0xd, 0);
            return -1;
        }
        // fall through
    case 0x12:
        return 0x40;
    case 0x2d:
        if (FindResult_guess()->race_guess != 0x80) {
            token_string_to_client_guess(&inner_c280, 0x145, 0xd, 0);
            return -1;
        }
        // fall through
    case 0x15:
    case 0x16:
        return 0x45;
    case 0x2f:
        if (FindResult_guess()->race_guess != 9) {
            token_string_to_client_guess(&inner_c280, 0x146, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x30:
        if (FindResult_guess()->race_guess != 4) {
            token_string_to_client_guess(&inner_c280, 0x147, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x31:
        if (FindResult_guess()->race_guess != 11) {
            token_string_to_client_guess(&inner_c280, 0x148, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x32:
        if (FindResult_guess()->race_guess != 3) {
            token_string_to_client_guess(&inner_c280, 0x149, 0xd, 0);
            return -1;
        }
        return 0x3f;
    case 0x34:
        if (FindResult_guess()->race_guess != 0x14a) {
            token_string_to_client_guess(&inner_c280, 0x1698, 0xd, 0);
            return -1;
        }
        // fall through
    case 0x11:
        return 0x3f;
    default:
        return -1;
    }
}

// FUNCTION: TITANIUM 0x004BBEDA
// Languages 0-24. Level thresholds per [language][race] at 0x0078F00C, 15 ints a row; the Iksar, Vah Shir
// and Froglok columns follow race 12 (0x0078F040). Necromancers, wizards, magicians and enchanters
// (11-14) learn some languages (11, 12, 17) early.
int EQ_PCView_guess::CanLearnLanguage_guess(int index) {
    int result = 0;
    if (index < 0 || index >= 0x19) {
        return false;
    }
    int threshold;
    if (FindResult_guess()->race_guess == 0x80) {
        threshold = g_statRows_guess[index].value_80;
    } else if (FindResult_guess()->race_guess == 0x82) {
        threshold = g_statRows_guess[index].value_82;
    } else if (FindResult_guess()->race_guess == 0x14a) {
        threshold = g_statRows_guess[index].value_14a;
    } else {
        threshold = g_statValues_guess[index * 0xf + FindResult_guess()->race_guess];
    }
    if (FindResult_guess()->level_guess >= threshold) {
        result = true;
    }
    if (FindResult_guess()->classId_guess == Class_Necromancer) {
        if (FindResult_guess()->level_guess >= 8 && index == 0xc) {
            result = true;
        }
        if (FindResult_guess()->level_guess >= 0x14 && index == 0x11) {
            result = true;
        }
    }
    if (FindResult_guess()->classId_guess == Class_Wizard &&
        FindResult_guess()->level_guess >= 8 && index == 0xb) {
        result = true;
    }
    if (FindResult_guess()->classId_guess == Class_Enchanter && index == 0xb) {
        result = true;
    }
    if (FindResult_guess()->classId_guess == Class_Magician &&
        FindResult_guess()->level_guess >= 8 && index == 0xb) {
        result = true;
    }
    return result;
}

// FUNCTION: TITANIUM 0x004BC0D3
// `value_guess` is in copper. Breaks the smallest coin held into ten of the next until copper covers it,
// then takes it (0x00417D70); 0 when the total money is short.
int EQ_PCView_guess::SpendMoney_guess(int value_guess) {
    if (value_guess < 0 || inner_c280.FUN_0041a259_guess() < value_guess) {
        return 0;
    }
    CharInfo2View_guess* lookup;
    while (FindResult_guess()->copper_guess < value_guess) {
        if (FindResult_guess()->silver_guess != 0) {
            lookup = FindResult_guess();
            lookup->silver_guess--;
            lookup = FindResult_guess();
            lookup->copper_guess += 10;
        } else {
            if (FindResult_guess()->gold_guess != 0) {
                lookup = FindResult_guess();
                lookup->gold_guess--;
                lookup = FindResult_guess();
                lookup->silver_guess += 10;
            } else {
                if (FindResult_guess()->platinum_guess != 0) {
                    lookup = FindResult_guess();
                    lookup->platinum_guess--;
                    lookup = FindResult_guess();
                    lookup->gold_guess += 10;
                }
            }
        }
    }
    ValueBase_guess()->AddSixth_guess(-value_guess);
    return 1;
}

// FUNCTION: TITANIUM 0x004BC20B
// @early-stop: budget, structural ndiff=104
// 0-5 by rising level difference (3 = same level, 4-5 higher, 0-2 lower); 6 = no con colour for
// corpses, the +0x1B6 flag and class 62 (probably LDoN objects). Against PCs, server types 1, 2 and 4
// (0x00900478) use flat ranges instead.
char EQ_PCView_guess::FUN_004bc20b_guess(Target_guess* target) {
    if (target->value_244 >= 2) {
        return 6;
    }
    if (target->value_1b6 != 0) {
        return 6;
    }
    if (target->playerClass_0252_guess == '>') {
        return 6;
    }

    int result = 0;
    int level = FindResult_guess()->level_guess;
    int current = target->value_24c;
    int difference = current - level;
    int threshold;
    if (FindResult_guess()->level_guess <= 0x3c) {
        threshold = (level * 3) / 4;
    } else {
        threshold = level - 0xf;
    }

    if (difference < 0) {
        if (current < threshold && difference < -3) {
            if (level > 8) {
                threshold -= current;
                if (level < 0x37) {
                    ++threshold;
                }
                if (level < 0x29) {
                    ++threshold;
                }
                if (level < 0x1f) {
                    ++threshold;
                }
                if (threshold < 1) {
                    threshold = 1;
                }
                if (threshold < 6) {
                    result = 1;
                }
            }
        } else {
            result = 2;
        }
    } else if (difference == 0) {
        result = 3;
    } else {
        result = (difference > 2) + 4;
    }

    if (target->value_244 != 0) {
        return result;
    }

    int mode = EQ_GLOBAL(int, 0x00900478);
    if (mode == 1) {
        if (difference < -4) {
            result = 0;
        } else {
            result = (difference >= 5) * 2 + 3;
        }
    } else if (mode == 2) {
        if (difference < -8) {
            result = 0;
        } else {
            result = (difference >= 9) * 2 + 3;
        }
    } else if (mode == 4) {
        if (difference < -5) {
            result = 0;
        } else if (difference < 6) {
            result = 3;
        } else {
            result = 5;
        }
    } else if (mode == 0) {
        return result;
    }

    if (current <= 5) {
        return 0;
    }
    if (level < 6) {
        return 5;
    }
    return result;
}

// FUNCTION: TITANIUM 0x004BC38C
// Guildmaster classes 20-35 are the base class + 19.
bool EQ_PCView_guess::IsMyClassGuildmaster_guess(Target_guess* target) {
    unsigned char value = target->playerClass_0252_guess;
    ValueEntry_guess* entry = ValueBase_guess();
    EQ_PCView_guess* object = entry->subobject.GetCharInfo2();
    if (value - 0x13 == reinterpret_cast<CharInfo2View_guess*>(object)->classId_guess) {
        return true;
    }
    return false;
}

// FUNCTION: TITANIUM 0x004BC3BF
// @early-stop: budget, diff ndiff=2
// (STA - 30) scaled by SPA 0xF6 (percent, 100 when absent), kept between 10 and that percent; Iksar 127,
// Froglok 256. The older client has the same STA - 30 and Iksar rules.
int EQ_PCView_guess::MaxAirSupply_guess() {
    int value = sta_guess - 0x1e;
    int scale = inner_c280.TotalSpellAffects_guess(0xf6, 1, 0, 1);
    if (scale <= 0) {
        scale = 100;
    }
    value = value * scale / 100;

    ValueEntry_guess* entry = ValueBase_guess();
    CharInfo2View_guess* object = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2());
    if (object->race_guess == 0x80) {
        return 0x7f;
    }

    entry = ValueBase_guess();
    object = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2());
    if (object->race_guess == 0x14a) {
        return 0x100;
    }

    int result = 10;
    if (value >= 10) {
        result = scale;
        if (value <= scale) {
            result = value;
        }
    }
    return result;
}

// FUNCTION: TITANIUM 0x004BC454
// MQ2 EQ_Character::Max_Mana; EQ_Character1 vtable slot 2, `this` is the +0xC280 subobject. Warriors,
// monks, rogues, berserkers (1, 7, 9, 16) and classes 40-41 have none. Base (0x005FBA70) plus the casting
// stat bonus, the +0x54 bonus and SPA 0x61 (mana pool).
int InnerCallback_guess::Max_Mana() {
    ValueEntry_guess* entry = OwnerValueBase_guess();
    unsigned char type = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2())->classId_guess;
    if (type == 1 || type == 7 || type == 9 || type == 0x10 || (type > 0x27 && type <= 0x29)) {
        return 0;
    }
    entry = OwnerValueBase_guess();
    int value = entry->subobject.GetCharInfo2()->FUN_005fba70_guess();
    entry = OwnerValueBase_guess();
    CharInfo2View_guess* lookup = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2());
    int delta = CalcCastingStat_guess(lookup->classId_guess, value_28, value_20);
    value += (delta * value) / 200;
    if (g_callbackGlobal_guess != 0 &&
        (reinterpret_cast<CharacterFlagsView_guess*>(Character_guess())->flags_108_guess & 0x40) != 0) {
        value += g_callbackGlobal_guess->GetManaBonus_guess(Owner_guess());
    }
    value += value_54;
    value += TotalSpellAffects_guess(0x61, 1, 0, 1);
    if (value < 0) {
        value = 0;
    }
    return value;
}

// FUNCTION: TITANIUM 0x004BC547
// Warrior, paladin, ranger, shadow knight, monk, bard, rogue, beastlord, berserker.
char EQ_PCView_guess::IsMeleeClass_guess() {
    ValueEntry_guess* entry = ValueBase_guess();
    CharInfo2View_guess* object = reinterpret_cast<CharInfo2View_guess*>(entry->subobject.GetCharInfo2());
    unsigned char value = object->classId_guess;
    if (value != 1 && (value <= 2 || (value > 5 && (value <= 6 || (value > 9 && (value <= 0xe || value > 16)))))) {
        return 0;
    }
    return 1;
}

// Adds `value` to skill `index` (100 skills; larger traps).
// FUNCTION: TITANIUM 0x004BC581
void EQ_PCView_guess::AddToSkill_guess(unsigned int index, int value) {
    if (index >= 100) {
        __debugbreak();
    }
    skills_guess[index] += value;
}

// Adds `second` to skill `first` of the character's profile (0x004BC581).
// FUNCTION: TITANIUM 0x004BC59B
void PcCharacterView_guess::AddSkillValue_guess(int first, int second) {
    EQ_PCView_guess* object = subobject.GetCharInfo2(first, second);
    ((ObjectCall_guess*)object)->AddToSkill_guess();
}

// Body tint `index` (9 slots at +0x1170; larger traps).
// FUNCTION: TITANIUM 0x004BC5B5
int ValueEntry_guess::GetBodyTint_guess(unsigned int index) {
    EQ_PCView_guess* object = subobject.GetCharInfo2();
    int* values = object->values_1170;
    if (index >= 9) {
        __debugbreak();
    }
    return values[index];
}

// FUNCTION: TITANIUM 0x004BC5D2
// Nulls the 2 shared-bank pointers (+0xD30); the EQ_PC ctor calls it.
void ClearD30_guess::Clear_guess() {
    for (int i = 0; i < 2; ++i) {
        values_d30[i] = 0;
    }
}

// Item views. Read by use: Valid_guess = stackable, IsBlocked_guess = item class (0 common, 1 container,
// 2 book; misnamed), GetValue_guess = item type, GetMask_guess = equip slot mask.
struct ItemInstanceView_guess {
    // EXTERNAL: TITANIUM 0x005EC760 ItemInstanceView_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ItemInstanceView_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ItemInstanceView_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECBA0 ItemInstanceView_guess::GetMask_guess
    unsigned int GetMask_guess(int value);
    // EXTERNAL: TITANIUM 0x005EC850 ItemInstanceView_guess::GetCount_guess
    int GetCount_guess(int value);
    // EXTERNAL: TITANIUM 0x005E0F60 ItemInstanceView_guess::FUN_005e0f60_guess
    int FUN_005e0f60_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 ItemInstanceView_guess::FUN_005e0ec0_guess
    const char* FUN_005e0ec0_guess();
    // EXTERNAL: TITANIUM 0x005E1640 ItemInstanceView_guess::FUN_005e1640_guess
    char FUN_005e1640_guess();
};

struct SlotInfo_guess {
    char pad_0[0x44];
    ItemInstanceView_guess* value_44;
    ItemInstanceView_guess* value_48;
};

struct PlayerCall_guess {
    virtual void Slot00_guess(int value_guess);
    virtual int Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
    virtual char Slot05_guess(EQ_ItemView_guess* entry_guess, int zero_guess);
};

struct EQ_ItemView_guess {
    // EXTERNAL: TITANIUM 0x005EC760 EQ_ItemView_guess::IsStackable_guess
    char IsStackable_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 EQ_ItemView_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 EQ_ItemView_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005EC630 EQ_ItemView_guess::GetEntry_guess
    EQ_ItemView_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0A30 EQ_ItemView_guess::IsEmpty_guess
    char IsEmpty_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E0A30 EQ_ItemView_guess::FUN_005e0a30_guess
    char FUN_005e0a30_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005EC650 EQ_ItemView_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC640 EQ_ItemView_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005EC660 EQ_ItemView_guess::ReleaseEntry_guess
    void ReleaseEntry_guess(int index_guess);
    virtual void Free_guess(int flags_guess);
    // EXTERNAL: TITANIUM 0x005E0F30 EQ_ItemView_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005EC790 EQ_ItemView_guess::CheckB_guess
    char CheckB_guess();
    // EXTERNAL: TITANIUM 0x005ACF60 EQ_ItemView_guess::GetTag_guess
    int GetTag_guess();
};

struct RankPrefix_guess {
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
    virtual void Slot0A_guess();
    virtual void Slot0B_guess();
    virtual void Slot0C_guess();
    virtual int Slot0D_guess();
    int field_004;
};

struct RankBase_guess {
    // EXTERNAL: TITANIUM 0x0040CC50 RankBase_guess::GetEntry_guess
    EQ_ItemView_guess* GetEntry_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 RankBase_guess::ClearEntry_guess
    void ClearEntry_guess(int index_guess, int value_guess);
};

struct PcProfileView_guess : RankPrefix_guess, virtual RankBase_guess {
    // EXTERNAL: TITANIUM 0x004BD6CE PcProfileView_guess::DelLoreItemDup_guess
    void DelLoreItemDup_guess(int index_guess, int subindex_guess, int key_guess, EQ_ItemView_guess* entry_guess);
    int CheckDupLoreItems_guess();
    // EXTERNAL: TITANIUM 0x00434777 PcProfileView_guess::FUN_00434777_guess
    int FUN_00434777_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 PcProfileView_guess::SetEntry_guess
    void SetEntry_guess(int index_guess, int value_guess);
    int HasLoreItem_guess(int value_guess);
    int WouldDuplicateLore_guess(EQ_ItemView_guess* entry_guess);
};

struct RankKey_guess {
    // EXTERNAL: TITANIUM 0x00601F10 RankKey_guess::Same_guess
    char Same_guess(RankKey_guess* other_guess);
};

struct RankKeyEntry_guess {
    // EXTERNAL: TITANIUM 0x005ACF60 RankKeyEntry_guess::GetKey_guess
    RankKey_guess* GetKey_guess();
};

// EXTERNAL: TITANIUM 0x00464D26 AdjustItemStackCount_guess
void __cdecl AdjustItemStackCount_guess(EQ_ItemView_guess** objectAddress, int amount);

// FUNCTION: TITANIUM 0x004BC834
// Low confidence (dispatcher case 0x5F4E, no EQEmu name). Slots up to 31 direct, else bag contents; a
// stackable item loses `amount` charges, anything else is freed and its slot cleared.
bool EQ_PCView_guess::ConsumeSlotItem_guess(int value, int amount) {
    bool result = false;
    EQ_ItemView_guess* object;
    EQ_ItemView_guess** slot;
    do {
        if (value <= 0x1f) {
            object = ProfileBase_guess()->GetEntry_guess(value);
            if (object == 0) {
                break;
            }
            slot = reinterpret_cast<EQ_ItemView_guess**>(Profile_guess()->FUN_00434777_guess(value));
        } else {
            int quotient = (value - 0x1f) / 10;
            value = (value - 0x1f) % 10;
            EQ_ItemView_guess* node = ProfileBase_guess()->GetEntry_guess(quotient);
            if (node == 0) {
                break;
            }
            if (node->GetItemClass_guess() != 1) {
                break;
            }
            if (value >= node->GetCount_guess()) {
                break;
            }
            object = node->GetEntry_guess(value);
            if (object == 0) {
                break;
            }
            slot = reinterpret_cast<EQ_ItemView_guess**>(node->GetValue_guess(value));
        }
        result = true;
        if (object->IsStackable_guess()) {
            AdjustItemStackCount_guess(slot, -amount);
        } else {
            object->Free_guess(1);
            *slot = 0;
            value_c28c = 1;
        }
    } while (0);
    return result;
}

// FUNCTION: TITANIUM 0x004BC5EB
// @early-stop: budget, structural ndiff=97
// General slots 22-29 always fit; augments (type 0x36), containers and books never equip. Range (11) and
// ammo (21) have item-type exceptions (19 throwing, 27 arrows, 28). Primary (13) and secondary (14) refuse
// two-handers (types 1, 4, 0x23) and instruments (23-26) against the other hand, CHARINFO2 +0x44/+0x48;
// secondary also needs Dual Wield (skill 22) for some items.
char EQ_PCView_guess::FitsEquipSlot_guess(int slot, ItemInstanceView_guess* who) {
    if (who == 0) {
        return 0;
    }
    if (FUN_005ee500_guess(slot) == 0) {
        return 0;
    }
    if (slot >= InvSlot_General1 && slot <= InvSlot_General8) {
        return 1;
    }
    if (who->GetItemClass_guess() == 1 || who->GetItemClass_guess() == 2 || who->GetItemType_guess() == 0x36) {
        return 0;
    }
    if (slot == InvSlot_Range) {
        if (who->GetItemType_guess() == 0x1b || who->GetItemType_guess() == 0x1c) {
            return 0;
        }
        if (who->GetCount_guess(1) > 0) {
            return 1;
        }
    } else if (slot == InvSlot_Ammo) {
        if (who->GetItemType_guess() == 0x13 || who->GetItemType_guess() == 0x1b || who->GetItemType_guess() == 0x1c) {
            return 1;
        }
    }
    int bit = 1 << slot;
    if ((bit & who->GetMask_guess(1)) == 0) {
        return 0;
    }
    if (slot == InvSlot_Primary) {
        SlotInfo_guess* info = reinterpret_cast<SlotInfo_guess*>(FindResult_guess());
        if (info->value_48 == 0) {
            return 1;
        }
        if (who->GetItemType_guess() == 1 || who->GetItemType_guess() == 4 || who->GetItemType_guess() == 0x23) {
            return 0;
        }
        SlotInfo_guess* item_info = reinterpret_cast<SlotInfo_guess*>(FindResult_guess());
        ItemInstanceView_guess* item = item_info->value_48;
        if (item->GetItemType_guess() < 0x17) {
            return 1;
        }
        if (item->GetItemType_guess() > 0x1a) {
            return 1;
        }
        return 0;
    }
    if (slot == InvSlot_Secondary) {
        if (who->GetItemType_guess() == 1 || who->GetItemType_guess() == 4 || who->GetItemType_guess() == 0x23) {
            return 0;
        }
        if (who->FUN_005e1640_guess() != 0 && inner_c280.HasSkillChecked_guess(SkillDualWield) == 0) {
            return 0;
        }
        SlotInfo_guess* info = reinterpret_cast<SlotInfo_guess*>(FindResult_guess());
        if (info->value_44 == 0) {
            return 1;
        }
        if (who->GetItemType_guess() >= 0x17 && who->GetItemType_guess() <= 0x1a) {
            return 0;
        }
        SlotInfo_guess* item_info = reinterpret_cast<SlotInfo_guess*>(FindResult_guess());
        ItemInstanceView_guess* item = item_info->value_44;
        if (item->GetItemType_guess() == 1 || item->GetItemType_guess() == 4 || item->GetItemType_guess() == 0x23) {
            return 0;
        }
        return 1;
    }
    return 1;
}

// FUNCTION: TITANIUM 0x004BC906
// Slots outside 0-21 always pass. Adds the can-use test (0x004192AA) to FitsEquipSlot. The inner
// IsBlocked_guess() != 0 test can never hold; it is original (this function matches).
char EQ_PCView_guess::CanEquipItem_guess(ItemInstanceView_guess* player, int index, int value) {
    if (player == 0 || index < 0 || index > InvSlot_Ammo) {
        return 1;
    }
    if (player->GetItemType_guess() == 0x36) {
        return 0;
    }
    if (!FitsEquipSlot_guess(index, player)) {
        return 0;
    }
    if (!inner_c280.CanUseItem_guess(player, value)) {
        return 0;
    }
    unsigned int mask = player->GetMask_guess(1);
    if ((1 << index) & mask) {
        return 1;
    }
    if (index == 0x15 || index == 0xb) {
        if (player->GetItemClass_guess() == 0) {
            if (player->GetItemClass_guess() != 0) {
                return 1;
            }
            if (index == 0x15) {
                if (player->GetItemType_guess() == 0x13) {
                    return 1;
                }
                if (player->GetItemType_guess() == 0x1b) {
                    return 1;
                }
                if (player->GetItemType_guess() == 0x1c) {
                    return 1;
                }
            } else {
                if (index != 0xb) {
                    return 1;
                }
                if (player->GetItemType_guess() == 0x1b) {
                    return 0;
                }
                if (player->GetItemType_guess() == 0x1c) {
                    return 0;
                }
                if (player->GetCount_guess(1) > 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// True when the group has at least `value` members (NumInParty).
// FUNCTION: TITANIUM 0x004BC9F8
bool EQ_PCView_guess::HasGroupOfAtLeast_guess(int value) {
    return NumInParty_guess() >= value;
}

// FUNCTION: TITANIUM 0x004BCA0B
// Nulls slots 0-30 without freeing the items (MQ2 EQ_PC::EmptyPossessionSlots).
void EQ_PCView_guess::EmptyPossessionSlots_guess() {
    int index = 0;
    do {
        reinterpret_cast<EntryAction_guess*>(Character_guess())->FUN_0041aa84_guess(index, 0);
        ++index;
    } while (index < 0x1f);
}

struct RankStorage_guess {
    char pad_0000[0xcf0];
    struct CacheByte_guess {
        EQ_ItemView_guess* GetPointer_guess() {
            return *reinterpret_cast<EQ_ItemView_guess**>(this);
        }
        void ClearPointer_guess() {
            *reinterpret_cast<EQ_ItemView_guess**>(this) = 0;
        }
    };
    BoundedArray_guess<CacheByte_guess, 0x40> cached_entries_cf0;
    char pad_d30[0xc280 - 0xd30];
    PcCharacter1View_guess inner_c280;
};

struct Display_guess {
    char pad_0[0x10];
    bool flag_10;
    char pad_11;
    char flag_12;

    // EXTERNAL: TITANIUM 0x00440F51 Display_guess::FUN_00440f51_guess
    void FUN_00440f51_guess(int value);

    // EXTERNAL: TITANIUM 0x00438FDF Display_guess::UpdateSoundEnvironment_guess
    void UpdateSoundEnvironment_guess();
};

struct Text_guess {
    // EXTERNAL: TITANIUM 0x0040E25C Text_guess::FUN_0040e25c_guess
    void FUN_0040e25c_guess(const char* text);
};

struct BaseView_guess {
    char pad_0[0xbc];
    Text_guess text_bc;
    char pad_bd[0x10c - 0xbd];
    unsigned char value_10c;
};

struct FlagView_guess {
    char pad_0[0xfa0];
    unsigned char value_fa0;
};

struct FloatHolder_guess {
    char pad_0[0x40];
    float value_40;
};

struct Sub1a8_guess {
    char pad_0[0xf90];
    int value_f90;
};

struct Engine_guess {
    char pad_0[0x1a8];
    Sub1a8_guess* sub_1a8;

    // EXTERNAL: TITANIUM 0x00479EB0 Engine_guess::SetGroupInvitePending_guess
    void SetGroupInvitePending_guess(int value);
};

struct EffectRec_guess {
    unsigned char value_0;
    unsigned char value_1;
    unsigned char value_2;
    unsigned char pad_3;
    int value_4;
    int value_8;
    int value_c;
};

struct RankSlot_guess {
    virtual void Slot00_guess(int flag);
};

struct Sub78_guess {
    char pad_0[0x78];
    int value_78;
};

struct Object10_guess {
    char pad_0[0x10];
    Sub78_guess sub_10;
};

struct Message12_guess {
    int value_0;
    int value_4;
    int value_8;
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)
#define g_byte_923798_guess EQ_GLOBAL(char, 0x00923798)
#define g_int_923884_guess EQ_GLOBAL(int, 0x00923884)

// EXTERNAL: TITANIUM 0x00464D65 SwapCombine_guess
int __cdecl SwapCombine_guess(ItemInstanceView_guess** player_guess, int value_guess, int a_guess, int b_guess);

// EXTERNAL: TITANIUM 0x00474597 UpdateLight_guess
void __cdecl UpdateLight_guess(int value_guess);

#define g_cameras_guess EQ_ARRAY(FloatHolder_guess*, 0x009254FC)

// FUNCTION: TITANIUM 0x004BCA2C
// @early-stop: budget, diff ndiff=19
// Death cleanup: buffs, vitals, raid state. At or above the corpse level (10; 80 when 0x00905CA9 or
// +0xFA0 is set; 0 on server type 6) the coins and the items in slots 0-30 go too. Ends with
// EndLootRequest (0x2316) for the loot target at 0x00905D18.
void EQ_PCView_guess::PrepareForRepop_guess(int value, int unused) {
    reinterpret_cast<BaseView_guess*>(ValueBase_guess())->text_bc.FUN_0040e25c_guess(
        EQ_ARRAY(char, 0x0063F53F));
    EQ_GLOBAL(Display_guess*, 0x00905D24)->FUN_00440f51_guess(
        (int)g_cameras_guess[EQ_GLOBAL(int, 0x00850CCC)]->value_40);
    EQ_GLOBAL(Display_guess*, 0x00905D24)->UpdateSoundEnvironment_guess();
    if (EQ_GLOBAL(char, 0x009043A4) != 0) {
        EQ_GLOBAL(char, 0x00985808) = 0;
        EQ_GLOBAL(Engine_guess*, 0x00905CE4)->sub_1a8->value_f90 = -1;
        EQ_GLOBAL(Engine_guess*, 0x00905CE4)->SetGroupInvitePending_guess(0);
    }
    if (EQ_GLOBAL(State_guess, 0x0091D708).IsInRaid_guess()) {
        EQ_GLOBAL(State_guess, 0x0091D708).SetTargetRaidPlayer_guess(0);
        EQ_GLOBAL(State_guess, 0x0091D708).ClearPendingInvite_guess();
    }
    int limit;
    PcCharacter1View_guess* inner = &inner_c280;
    int index = 0;
    if (inner->GetMaxBuffs_guess() > 0) {
        do {
            EffectRec_guess* effect = reinterpret_cast<EffectRec_guess*>(inner->GetBuff_guess(index));
            effect->value_4 = -1;
            effect->value_0 = 0;
            effect->value_2 = 0;
            effect->value_1 = 0;
            effect->value_8 = 0;
            effect->value_c = 0;
            ++index;
        } while (index < (int)inner->GetMaxBuffs_guess());
    }
    value_c348 = 0;
    ResetPlayerVitals_guess(value);
    FUN_005ed570_guess(0);
    limit = 10;
    if (EQ_GLOBAL(char, 0x00905CA9) != 0 || reinterpret_cast<FlagView_guess*>(this)->value_fa0 != 0) {
        limit = 0x50;
    }
    if (EQ_GLOBAL(int, 0x00900478) == 6) {
        limit = 0;
    }
    if (FindResult_guess()->level_guess >= limit ||
        reinterpret_cast<BaseView_guess*>(ValueBase_guess())->value_10c != 0) {
        FindResult_guess()->platinum_guess = 0;
        FindResult_guess()->gold_guess = 0;
        FindResult_guess()->silver_guess = 0;
        FindResult_guess()->copper_guess = 0;
        FindResult_guess()->value_11e4 = 0;
        FindResult_guess()->value_11e8 = 0;
        FindResult_guess()->value_11ec = 0;
        FindResult_guess()->value_11f0 = 0;
        FUN_005ed8a0_guess(0);
        FUN_005ed8e0_guess(0);
    }
    if (FindResult_guess()->level_guess >= limit) {
        for (int slot = 0; slot < 9; ++slot) {
            reinterpret_cast<EntryAction_guess*>(ValueBase_guess())->FUN_004586a5_guess(slot, -1);
        }
    }
    for (int slot = 0; slot < 10; ++slot) {
        FUN_005f0a80_guess(slot, 0);
    }
    for (int slot = 0; slot < 9; ++slot) {
        FUN_005f06b0_guess(slot, 0);
        reinterpret_cast<IndexedMethod_guess*>(ValueBase_guess())->FUN_004b96c3_guess(slot, 0);
    }
    if (FindResult_guess()->level_guess >= limit ||
        reinterpret_cast<BaseView_guess*>(ValueBase_guess())->value_10c != 0) {
        value = 0;
        do {
            EQ_ItemView_guess* entry = reinterpret_cast<RankBase_guess*>(ValueBase_guess())->GetEntry_guess(value);
            if (entry != 0) {
                if (entry->GetItemClass_guess() == 1) {
                    int sub = 0;
                    if (entry->GetCount_guess() > 0) {
                        do {
                            if (entry->GetEntry_guess(sub) != 0) {
                                if (!entry->GetEntry_guess(sub)->IsEmpty_guess(0)) {
                                    entry->ReleaseEntry_guess(sub);
                                }
                            }
                            ++sub;
                        } while (sub < entry->GetCount_guess());
                    }
                }
                if (!entry->FUN_005e0a30_guess(1)) {
                    reinterpret_cast<RankSlot_guess*>(entry)->Slot00_guess(1);
                    reinterpret_cast<EntryAction_guess*>(ValueBase_guess())->FUN_0041aa84_guess(value, 0);
                }
            }
            ++value;
        } while (value < 0x1f);
    }
    index = 0;
    do {
        FUN_005f06b0_guess(index, 0);
        reinterpret_cast<IndexedMethod_guess*>(ValueBase_guess())->FUN_004b96c3_guess(index, 0);
        ++index;
    } while (index < 9);
    if (EQ_GLOBAL(int, 0x00905D18) != 0) {
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_EndLootRequest,
            reinterpret_cast<void*>(EQ_GLOBAL(int, 0x00905D18) + 600), 4, 1);
    }
}

// FUNCTION: TITANIUM 0x004BCF0B
// @early-stop: budget, structural ndiff=35
// `value_guess` is the source slot. Order: merge into matching stacks in general slots and their bags
// (bag slots from 0xFB = 251), then the first free general slot, a free bag slot, the cursor (30). Each move
// sends MoveItem (0x420F). If nothing fits: a source >= 10000 gets the item back; otherwise 0xD2F
// ("Inventory full, and item is NO TRADE...") or 0x3289 ("...dropped to the ground!") and the item is
// dropped, sending 0xF47 (EQEmu GroundSpawn) with no payload unless 0x00923798/0x00923884 are set.
int EQ_PCView_guess::AutoInventoryItem_guess(ItemInstanceView_guess** pp_guess, int value_guess, int unused_guess, char flag_guess) {
    ItemInstanceView_guess* player_guess = *pp_guess;
    int index_guess;
    EQ_ItemView_guess* entry_guess;
    int result_guess = -1;
    int base_guess;
    Message12_guess message_guess;
    if (player_guess == 0) {
        return -1;
    }
    if (player_guess->IsStackable_guess()) {
        for (int i_guess = InvSlot_General1; i_guess <= InvSlot_General8; ++i_guess) {
            if (player_guess != 0 && ProfileBase_guess()->GetEntry_guess(i_guess) != 0) {
                if (ProfileBase_guess()->GetEntry_guess(i_guess)->IsStackable_guess()) {
                    if (SwapCombine_guess(&player_guess, Profile_guess()->FUN_00434777_guess(i_guess),
                                           value_guess, i_guess) != 0) {
                        result_guess = i_guess;
                    }
                }
            }
        }
        if (player_guess != 0) {
            if (player_guess->GetItemClass_guess() != 1) {
                index_guess = InvSlot_General1;
                int slot_guess = 0xfb;
                do {
                    int key_guess;
                    int sub_guess = 0;
                    if (player_guess != 0 && ProfileBase_guess()->GetEntry_guess(index_guess) != 0) {
                        if (ProfileBase_guess()->GetEntry_guess(index_guess)->GetItemClass_guess() == 1) {
                            entry_guess = ProfileBase_guess()->GetEntry_guess(index_guess);
                            if (0 < entry_guess->GetCount_guess()) {
                                do {
                                    if (player_guess != 0 && entry_guess->GetEntry_guess(sub_guess) != 0 &&
                                        reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot05_guess(entry_guess, 0)) {
                                        if (entry_guess->GetEntry_guess(sub_guess)->IsStackable_guess()) {
                                            key_guess = slot_guess + sub_guess;
                                            if (SwapCombine_guess(&player_guess, entry_guess->GetValue_guess(sub_guess),
                                                                   value_guess, key_guess) != 0) {
                                                result_guess = key_guess;
                                            }
                                        }
                                    }
                                    ++sub_guess;
                                } while (sub_guess < entry_guess->GetCount_guess());
                            }
                        }
                    }
                    slot_guess += 10;
                    ++index_guess;
                } while (slot_guess <= 0x141);
            }
        }
    }
    if (player_guess != 0) {
        index_guess = InvSlot_General1;
        do {
            if (player_guess != 0 && ProfileBase_guess()->GetEntry_guess(index_guess) == 0 &&
                FUN_005ee500_guess(index_guess)) {
                Profile_guess()->SetEntry_guess(index_guess,
                    reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot01_guess());
                player_guess = 0;
                message_guess.value_8 = 0;
                message_guess.value_0 = value_guess;
                message_guess.value_4 = index_guess;
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_MoveItem, &message_guess, 12, 1);
                UpdateLight_guess(Profile_guess()->Slot0D_guess());
                result_guess = index_guess;
                break;
            }
            ++index_guess;
        } while (index_guess <= InvSlot_General8);
        if (player_guess != 0) {
            if (player_guess->GetItemClass_guess() != 1) {
                index_guess = InvSlot_General1;
                base_guess = 0xfb;
                do {
                    if (player_guess != 0 && ProfileBase_guess()->GetEntry_guess(index_guess) != 0) {
                        if (ProfileBase_guess()->GetEntry_guess(index_guess)->GetItemClass_guess() == 1) {
                            entry_guess = ProfileBase_guess()->GetEntry_guess(index_guess);
                            int slot_guess = 0;
                            if (0 < entry_guess->GetCount_guess()) {
                                do {
                                    if (player_guess != 0 && entry_guess->GetEntry_guess(slot_guess) == 0 &&
                                        reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot05_guess(entry_guess, 0)) {
                                        entry_guess->SetValue_guess(slot_guess,
                                            reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot01_guess());
                                        player_guess = 0;
                                        message_guess.value_8 = 0;
                                        message_guess.value_0 = value_guess;
                                        result_guess = base_guess + slot_guess;
                                        message_guess.value_4 = result_guess;
                                        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_MoveItem, &message_guess, 12, 1);
                                    }
                                    ++slot_guess;
                                } while (slot_guess < entry_guess->GetCount_guess());
                            }
                        }
                    }
                    base_guess += 10;
                    ++index_guess;
                } while (base_guess <= 0x141);
            }
            if (player_guess != 0) {
                if (ProfileBase_guess()->GetEntry_guess(InvSlot_Cursor) == 0) {
                    Profile_guess()->SetEntry_guess(InvSlot_Cursor, (int)player_guess);
                    player_guess = 0;
                    message_guess.value_8 = 0;
                    message_guess.value_0 = value_guess;
                    message_guess.value_4 = InvSlot_Cursor;
                    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_MoveItem, &message_guess, 12, 1);
                    UpdateLight_guess(Profile_guess()->Slot0D_guess());
                    result_guess = InvSlot_Cursor;
                }
                if (player_guess != 0) {
                    if (value_guess >= 10000) {
                        *pp_guess = player_guess;
                        return 0;
                    }
                    if (reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot04_guess(0x29a) == 0 || flag_guess == 0) {
                        pEverQuest->dsp_chat(pStringTable->getString(0xd2f, 0), 15, 1);
                        return -1;
                    }
                    pEverQuest->dsp_chat(pStringTable->getString(0x3289, 0), 15, 1);
                    if (player_guess != 0) {
                        reinterpret_cast<PlayerCall_guess*>(player_guess)->Slot00_guess(1);
                    }
                    player_guess = 0;
                    if (g_byte_923798_guess == 0 && g_int_923884_guess == 0) {
                        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_GroundSpawn, 0, 0, 1);
                    }
                }
            }
        }
    }
    *pp_guess = player_guess;
    Object10_guess* object_guess = reinterpret_cast<Object10_guess*>(FindResult_guess());
    g_display_guess->flag_10 = object_guess->sub_10.value_78 != 0;
    return result_guess;
}

// FUNCTION: TITANIUM 0x004BD3E5
// @early-stop: budget, structural ndiff=58
// Set `param_1` (a set already named `param_2` wins) takes the primary, secondary, range and ammo items;
// then Bandolier (0x6F0C) action 0 with the name.
void EQ_PCView_guess::CreateBandolier_guess(int param_1, char* param_2) {
    int index = 0;
    while (index < 4) {
        if (FUN_00574460_guess(param_2, FUN_005f0c30_guess(index)) == 0) {
            param_1 = index;
            break;
        }
        ++index;
    }
    if (param_1 >= 0 && param_1 < 4) {
        CopyBuffer_guess data_guess;
        ((EQ_PCView_guess*)&data_guess)->ClearBandolierSet_guess();
        strncpy(&data_guess.active, param_2, 0x20);
        if (FindRecord_guess()->sub_10.value_34 != 0) {
            data_guess.slots[0].values[1] = FindRecord_guess()->sub_10.value_34->FUN_005e0f60_guess();
            data_guess.slots[0].values[0] = FindRecord_guess()->sub_10.value_34->GetItemId_guess();
            strcpy(data_guess.slots[0].text, FindRecord_guess()->sub_10.value_34->FUN_005e0ec0_guess());
        }
        if (FindRecord_guess()->sub_10.value_38 != 0) {
            data_guess.slots[1].values[1] = FindRecord_guess()->sub_10.value_38->FUN_005e0f60_guess();
            data_guess.slots[1].values[0] = FindRecord_guess()->sub_10.value_38->GetItemId_guess();
            strcpy(data_guess.slots[1].text, FindRecord_guess()->sub_10.value_38->FUN_005e0ec0_guess());
        }
        if (FindRecord_guess()->sub_10.value_2c != 0) {
            data_guess.slots[2].values[1] = FindRecord_guess()->sub_10.value_2c->FUN_005e0f60_guess();
            data_guess.slots[2].values[0] = FindRecord_guess()->sub_10.value_2c->GetItemId_guess();
            strcpy(data_guess.slots[2].text, FindRecord_guess()->sub_10.value_2c->FUN_005e0ec0_guess());
        }
        if (FindRecord_guess()->sub_10.value_54 != 0) {
            data_guess.slots[3].values[1] = FindRecord_guess()->sub_10.value_54->FUN_005e0f60_guess();
            data_guess.slots[3].values[0] = FindRecord_guess()->sub_10.value_54->GetItemId_guess();
            strcpy(data_guess.slots[3].text, FindRecord_guess()->sub_10.value_54->FUN_005e0ec0_guess());
        }
        FUN_005f0c60_guess(param_1, &data_guess);
        if (pinstCBandolierWnd_guess != 0) {
            pinstCBandolierWnd_guess->RebuildList_guess();
        }
        struct Packet_guess {
            int value;
            char index;
            char text_5[0x23];
        } packet_guess;
        packet_guess.value = 0;
        packet_guess.index = (char)param_1;
        strncpy(packet_guess.text_5, param_2, 0x20);
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_Bandolier, &packet_guess, 0x28, 1);
    }
}

// FUNCTION: TITANIUM 0x004BD6CE
// @early-stop: budget, structural ndiff=52
// For a lore item, deletes every other copy: slots 0-30 and their bags with string 0x66 ("Duplicate Lore
// Item deleted."), the 16 bank slots and their bags with 0x67. The bank array is declared as 0x40 one-byte
// cells, hence cache_offset steps by 4.
void PcProfileView_guess::DelLoreItemDup_guess(int index_guess, int subindex_guess, int key_guess, EQ_ItemView_guess* entry_guess) {
    if (entry_guess->CheckB_guess() != 0) {
        int index = 0;
        do {
            if (GetEntry_guess(index) != 0) {
                if (GetEntry_guess(index)->GetItemClass_guess() == 1) {
                    int subindex = 0;
                    if (GetEntry_guess(index)->GetCount_guess() > 0) {
                        do {
                            if (index != index_guess || subindex != subindex_guess) {
                                if (GetEntry_guess(index)->GetEntry_guess(subindex) != 0) {
                                    RankKey_guess* key = reinterpret_cast<RankKeyEntry_guess*>(entry_guess)->GetKey_guess();
                                    if (reinterpret_cast<RankKeyEntry_guess*>(GetEntry_guess(index)->GetEntry_guess(subindex))->GetKey_guess()->Same_guess(key) != 0) {
                                        RankStorage_guess* storage = reinterpret_cast<RankStorage_guess*>(this);
                                        token_string_to_client_guess(&storage->inner_c280, 0x66, 0xd, 0);
                                        GetEntry_guess(index)->ReleaseEntry_guess(subindex);
                                    }
                                }
                            }
                            ++subindex;
                        } while (subindex < GetEntry_guess(index)->GetCount_guess());
                    }
                }
                RankKey_guess* key = reinterpret_cast<RankKeyEntry_guess*>(entry_guess)->GetKey_guess();
                if (reinterpret_cast<RankKeyEntry_guess*>(GetEntry_guess(index))->GetKey_guess()->Same_guess(key) != 0 && index != index_guess) {
                    RankStorage_guess* storage = reinterpret_cast<RankStorage_guess*>(this);
                    token_string_to_client_guess(&storage->inner_c280, 0x66, 0xd, 0);
                    EQ_ItemView_guess* slot = GetEntry_guess(index);
                    if (slot != 0) {
                        slot->Free_guess(1);
                    }
                    ClearEntry_guess(index, 0);
                }
            }
            ++index;
        } while (index < 0x1f);

        RankStorage_guess* storage = reinterpret_cast<RankStorage_guess*>(this);
        int cache_offset = 0;
        do {
            if (storage->cached_entries_cf0[cache_offset].GetPointer_guess() != 0) {
                if (storage->cached_entries_cf0[cache_offset].GetPointer_guess()->GetItemClass_guess() == 1) {
                    index_guess = 0;
                    while (index_guess < storage->cached_entries_cf0[cache_offset].GetPointer_guess()->GetCount_guess()) {
                        if (storage->cached_entries_cf0[cache_offset].GetPointer_guess()->GetEntry_guess(index_guess) != 0) {
                            RankKey_guess* key = reinterpret_cast<RankKeyEntry_guess*>(entry_guess)->GetKey_guess();
                            if (reinterpret_cast<RankKeyEntry_guess*>(storage->cached_entries_cf0[cache_offset].GetPointer_guess()->GetEntry_guess(index_guess))->GetKey_guess()->Same_guess(key) != 0) {
                                token_string_to_client_guess(&storage->inner_c280, 0x67, 0xd, 0);
                                storage->cached_entries_cf0[cache_offset].GetPointer_guess()->ReleaseEntry_guess(index_guess);
                            }
                        }
                        ++index_guess;
                    }
                }
                RankKey_guess* key = reinterpret_cast<RankKeyEntry_guess*>(entry_guess)->GetKey_guess();
                if (reinterpret_cast<RankKeyEntry_guess*>(storage->cached_entries_cf0[cache_offset].GetPointer_guess())->GetKey_guess()->Same_guess(key) != 0) {
                    token_string_to_client_guess(&storage->inner_c280, 0x67, 0xd, 0);
                    storage->cached_entries_cf0[cache_offset].GetPointer_guess()->Free_guess(1);
                    storage->cached_entries_cf0[cache_offset].ClearPointer_guess();
                }
            }
            cache_offset += 4;
        } while (cache_offset < 0x40);
    }
}

struct Param_guess {
    // EXTERNAL: TITANIUM 0x00601EF0 Param_guess::FUN_00601ef0_guess
    char FUN_00601ef0_guess();
};

struct Effect_guess;

struct ListNode_guess {
    char pad_0[0xc];
    ListNode_guess* next_c;
    // EXTERNAL: TITANIUM 0x005D99D0 ListNode_guess::FUN_005d99d0_guess
    Effect_guess* FUN_005d99d0_guess();
};

struct Effect_guess {
    char pad_0[4];
    Effect_guess* next_4;
    // EXTERNAL: TITANIUM 0x005FE6D0 Effect_guess::FUN_005fe6d0_guess
    char FUN_005fe6d0_guess(Param_guess* param);
    // EXTERNAL: TITANIUM 0x005DFD50 Effect_guess::FUN_005dfd50_guess
    char FUN_005dfd50_guess(Param_guess* param);
};

struct EffectSlots_guess {
    char pad_0[0xcf0];
    Effect_guess* effects_cf0[16];
    char pad_d30[8];
    Effect_guess* effects_d38[36];
};

// FUNCTION: TITANIUM 0x004BCDB8
// @early-stop: budget, structural ndiff=36
// Low confidence. For a lore item def: the profile's item list, then 16 bank (+0xCF0) and 36 more
// (+0xD38) slots.
int PcProfileView_guess::HasLoreItem_guess(int value_guess) {
    Param_guess* param = reinterpret_cast<Param_guess*>(value_guess);
    if (param == 0 || !param->FUN_00601ef0_guess()) {
        return 0;
    }
    // Profile sub-object at owner+8+offset; its field_004 is the list head (owner+offset+0xc).
    PcProfileView_guess* profile = reinterpret_cast<EQ_PCView_guess*>(this)->Profile_guess();
    ListNode_guess* node = reinterpret_cast<ListNode_guess*>(profile->field_004);
    while (node != 0) {
        Effect_guess* effect = node->FUN_005d99d0_guess();
        while (effect != 0) {
            if (effect->FUN_005fe6d0_guess(param)) {
                return 1;
            }
            effect = effect->next_4;
        }
        node = node->next_c;
    }
    EffectSlots_guess* slots = reinterpret_cast<EffectSlots_guess*>(this);
    int index = 0;
    do {
        if (index >= 16) {
            __debugbreak();
        } else if (slots->effects_cf0[index] != 0 && slots->effects_cf0[index]->FUN_005dfd50_guess(param)) {
            return 1;
        }
        ++index;
    } while (index < 16);
    index = 0;
    do {
        if (index >= 36) {
            __debugbreak();
        } else if (slots->effects_d38[index] != 0 && slots->effects_d38[index]->FUN_005dfd50_guess(param)) {
            return 1;
        }
        ++index;
    } while (index < 36);
    return 0;
}

// FUNCTION: TITANIUM 0x004BCE5F
// Recurses into a container's contents, or a plain item's 5 sub-slots (probably augments), first.
int PcProfileView_guess::WouldDuplicateLore_guess(EQ_ItemView_guess* entry_guess) {
    if (entry_guess == 0) {
        return 0;
    }
    if (entry_guess->GetItemClass_guess() == 1) {
        int index = 0;
        if (entry_guess->GetCount_guess() > 0) {
            do {
                if (entry_guess->GetEntry_guess(index) != 0) {
                    if (WouldDuplicateLore_guess(entry_guess->GetEntry_guess(index)) == 1) {
                        return 1;
                    }
                }
                ++index;
            } while (index < entry_guess->GetCount_guess());
        }
    } else {
        int index = 0;
        do {
            if (entry_guess->GetEntry_guess(index) != 0) {
                if (WouldDuplicateLore_guess(entry_guess->GetEntry_guess(index)) == 1) {
                    return 1;
                }
            }
            ++index;
        } while (index < 5);
    }
    if (entry_guess->CheckB_guess() == 0) {
        return 0;
    }
    return HasLoreItem_guess(entry_guess->GetTag_guess());
}

// Runs the duplicate-lore cleanup (0x004BD6CE) for the item in each of slots 0-30 and, for a container
// (item class 1), for every item inside it first. Always returns 0.
// FUNCTION: TITANIUM 0x004BD9B8
int PcProfileView_guess::CheckDupLoreItems_guess() {
    int index = 0;
    do {
        if (GetEntry_guess(index) != 0) {
            if (GetEntry_guess(index)->GetItemClass_guess() == 1) {
                int subindex = 0;
                if (GetEntry_guess(index)->GetCount_guess() > 0) {
                    do {
                        if (GetEntry_guess(index)->GetEntry_guess(subindex) != 0) {
                            DelLoreItemDup_guess(index, subindex,
                                GetEntry_guess(index)->GetEntry_guess(subindex)->GetItemId_guess(),
                                GetEntry_guess(index)->GetEntry_guess(subindex));
                        }
                        ++subindex;
                    } while (subindex < GetEntry_guess(index)->GetCount_guess());
                }
            }
            DelLoreItemDup_guess(index, -1,
                GetEntry_guess(index)->GetItemId_guess(),
                GetEntry_guess(index));
        }
        ++index;
    } while (index < 0x1f);
    return 0;
}

// FUNCTION: TITANIUM 0x004BDAD1
// (current - 10)^3 / 100, never negative. `flag_guess` picks a language (byte table at +0x14 of the
// CHARINFO2 base) instead of a skill.
int EQ_PCView_guess::CostToTrain_guess(int flag_guess, int unused_guess, unsigned int index_guess) {
    int value_guess;
    if (flag_guess != 0) {
        unsigned char* values_guess = ValueBase_guess()->values_c;
        if (index_guess >= 0x20) {
            __debugbreak();
        }
        value_guess = values_guess[index_guess] - 10;
    } else if (inner_c280.HasSkillChecked_guess(index_guess) != 0) {
        ValueEntry_guess* entry_guess = ValueBase_guess();
        value_guess = entry_guess->GetSkill_guess(index_guess) - 10;
    } else {
        value_guess = 0;
    }
    if (value_guess < 0) {
        value_guess = 0;
    }
    return value_guess * value_guess * value_guess / 100;
}

// FUNCTION: TITANIUM 0x004BDB3C
// PCs only. Air refills while breathing (0x0041A753 == 1), else drops by one per call; at 0 the spawn takes
// drowning damage (type 0xFB) through 0x0041C905.
void EQ_PCView_guess::ProcessAirSupply_guess() {
    UpgradeBenefit_guess update;
    update.flag_1e = 0;
    if (spawn_guess == 0 || reinterpret_cast<Actor_guess*>(spawn_guess)->value_244 != 0) {
        return;
    }
    if (inner_c280.CanBreathe_guess() == 1) {
        airSupplyRemaining_0e30_guess = MaxAirSupply_guess();
    } else {
        int* counter_guess = &airSupplyRemaining_0e30_guess;
        if (*counter_guess >= 1) {
            *counter_guess = *counter_guess - 1;
        } else {
            *counter_guess = 0;
            int raw_guess = inner_c280.Max_HP_guess(reinterpret_cast<Actor_guess*>(spawn_guess)->value_244);
            int count_guess = (int)(raw_guess * EQ_GLOBAL(double, 0x0064B9A8));
            if (count_guess > 0) {
                update.word_0 = reinterpret_cast<Actor_guess*>(spawn_guess)->value_258;
                update.word_2 = 0;
                update.word_4 = 0;
                update.count_6 = count_guess;
                update.float_a = 0.0f;
                update.float_e = 0.0f;
                update.float_12 = 0.0f;
                update.byte_16 = 0xfb;
                update.word_1b = -1;
                inner_c280.FUN_0041c905_guess(count_guess, &update, 1, 0, 1, 1);
            }
        }
    }
}

// Zeroes the 64 leadership ability ranks (+0xBF0).
// FUNCTION: TITANIUM 0x004BDC13
void ClearBF0_guess::Clear_guess() {
    for (int i = 0; i < 64; ++i) {
        values_bf0[i] = 0;
    }
}

struct SkillDef_guess {
    char pad_0[0xb];
    char value_b;
};

// EXTERNAL: TITANIUM 0x0044A448 GetSkillCap_guess
int __cdecl GetSkillCap_guess(int value_guess, int kind_guess, int skill_guess, EQ_PCView_guess* object_guess);

// True when `skill` is at its cap for the character (0x0044A448's value, lowered by the rules below).
// FUNCTION: TITANIUM 0x004BDC2F
// @early-stop: budget, structural ndiff=370
// Cap from 0x0044A448 (level, class, skill). Tradeskills (60, 61, 63-65, 68, 69): only 1 + SPA 0x107 of
// them may pass 200. Spell specializations (43-47): another one above 50 caps this at 50, unless it is
// the only one and SPA 0xF8 is present; exactly one above 100 then caps it at 100.
bool EQ_PCView_guess::AtSkillLimit_guess(int skill) {
    int count50 = 0;
    int count100 = 0;
    bool flag = reinterpret_cast<InnerCallback_guess*>(&inner_c280)->TotalSpellAffects_guess(0xf8, 1, 0, 1) != 0;
    int required = GetSkillCap_guess(FindResult_guess()->level_guess, FindResult_guess()->classId_guess, skill, this);
    // Skills the table marks with +0xB clear: only Sense Heading and the tradeskills can be capped. A
    // tradeskill caps at 200 once as many other tradeskills are above 200 as TradeSkillMastery (SPA 263)
    // allows, plus one.
    if (EQ_ARRAY(SkillDef_guess*, 0x00851200)[skill]->value_b == 0) {
        switch (skill) {
        case SkillSenseHeading:
            return Skill_guess(SkillSenseHeading) >= required;
        case SkillBaking:
        case SkillTailoring:
        case SkillBlacksmithing:
        case SkillFletching:
        case SkillBrewing:
        case SkillJewelryMaking:
        case SkillPottery: {
            int count = 0;
            for (int index = 0; index < 100; ++index) {
                if (index != skill &&
                    (index == 0x3f || index == 0x3d || index == 0x45 || index == 0x44 || index == 0x40 ||
                     index == 0x3c || index == 0x41) &&
                    Skill_guess(index) > 200) {
                    count++;
                }
            }
            if (count >= reinterpret_cast<InnerCallback_guess*>(&inner_c280)->TotalSpellAffects_guess(0x107, 1, 0, 1) + 1) {
                required = 200;
            }
            return Skill_guess(skill) >= required;
        }
        default:
            return false;
        }
    }
    switch (skill) {
    case SkillSpecializeAbjure:
        if (Stats_guess()->skills_guess[0x2c] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2d] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2e] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2f] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2c] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2d] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2e] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2f] > 100) count100++;
        break;
    case SkillSpecializeAlteration:
        if (Stats_guess()->skills_guess[0x2b] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2d] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2e] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2f] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2b] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2d] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2e] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2f] > 100) count100++;
        break;
    case SkillSpecializeConjuration:
        if (Stats_guess()->skills_guess[0x2c] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2b] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2e] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2f] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2c] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2b] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2e] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2f] > 100) count100++;
        break;
    case SkillSpecializeDivination:
        if (Stats_guess()->skills_guess[0x2c] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2d] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2b] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2f] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2c] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2d] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2b] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2f] > 100) count100++;
        break;
    case SkillSpecializeEvocation:
        if (Stats_guess()->skills_guess[0x2c] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2d] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2e] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2b] > 50) count50++;
        if (Stats_guess()->skills_guess[0x2c] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2d] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2e] > 100) count100++;
        if (Stats_guess()->skills_guess[0x2b] > 100) count100++;
        break;
    default:
        return Skill_guess(skill) >= required;
    }
    // Specialisations: with another one above 50 the cap is 50, unless it is the only one and SecondaryForte
    // (SPA 248) is on; with exactly one other above 100 the cap is 100.
    if (count50 != 0 && (count50 != 1 || !flag)) {
        required = 50;
    } else if (count100 == 1) {
        required = 100;
    }
    return Skill_guess(skill) >= required;
}

// EXTERNAL: TITANIUM 0x00464983 IsTradeSkill_guess
int __cdecl IsTradeSkill_guess(int value);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output, unsigned int id, const char* text, int zero1, int zero2,
    int zero3, int zero4, int zero5, int zero6, int zero7, int zero8);

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestText_guess::trimName_guess
    char* trimName_guess(const char* text);

    // EXTERNAL: TITANIUM 0x00492595 EverQuestText_guess::GetLangDesc_guess
    int GetLangDesc_guess(unsigned int index);
};

#define g_everQuestText_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)

struct TextSource_guess {
    char pad_0[0x120];
    char text_120_guess[0x40];
};

#define g_textSource_guess EQ_GLOBAL(TextSource_guess*, 0x00905D1C)

struct Row_guess {
    int id_0;

    // EXTERNAL: TITANIUM 0x0044A335 Row_guess::FUN_0044a335_guess
    int FUN_0044a335_guess(int index);

    // EXTERNAL: TITANIUM 0x0044A2E4 Row_guess::FUN_0044a2e4_guess
    int FUN_0044a2e4_guess(int index);
};

#define g_rows_guess EQ_ARRAY(Row_guess*, 0x00851200)

// FUNCTION: TITANIUM 0x004BE271
// @early-stop: unknown, diff ndiff=7
// A worn item's tint (0x005ED490 table) overrides the body tint. Index 9 passes the first check but
// trips __debugbreak, the arrays holding 9 (bounds as compiled).
int EQ_PCView_guess::GetArmorTint_guess(int index) {
    if (index < 0 || index > 9) {
        return 0;
    }
    int* values = FUN_005ed490_guess()->GetValues_guess();
    if ((unsigned int)index >= 9) {
        __debugbreak();
    }
    if (values[index] != 0 && FUN_005f05e0_guess(index) != 0) {
        int* values_again = FUN_005ed490_guess()->GetValues_guess();
        if ((unsigned int)index >= 9) {
            __debugbreak();
        }
        return values_again[index];
    }
    return reinterpret_cast<ValueEntry_guess*>(&embedded_8[holder_8->vbaseOffset_0004_guess])
        ->GetBodyTint_guess(index);
}

// Sets armour tint `index` (0-9) through the profile's dword array (0x004B96C3); other indexes are
// ignored.
// FUNCTION: TITANIUM 0x004BE2DC
void EQ_PCView_guess::SetArmorTint_guess(int index, int value) {
    if (index >= 0 && index <= 9) {
        reinterpret_cast<IndexedMethod_guess*>(Character_guess())->FUN_004b96c3_guess(index, value);
    }
}

struct EntryNode_guess {
    char pad_0[0x80];
    int value_80_guess;
    int value_84_guess;

    // EXTERNAL: TITANIUM 0x005ECCC0 EntryNode_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005ECC30 EntryNode_guess::GetCount_guess
    int GetCount_guess();

    // EXTERNAL: TITANIUM 0x005EC630 EntryNode_guess::GetChild_guess
    EntryNode_guess* GetChild_guess(int index_guess);
};

// FUNCTION: TITANIUM 0x004BE2FC
// @early-stop: budget, diff ndiff=8
// Low confidence: matches the item's +0x80/+0x84 pair (probably its serial) in slots 0-30 and their bags;
// `index_guess` gets the slot number.
EntryNode_guess* EQ_PCView_guess::FindItemByKey_guess(int first_guess, int second_guess, int* index_guess) {
    for (int i = 0; i < 0x1f; ++i) {
        if (NodeAt_guess(i) != 0) {
            EntryNode_guess* node = NodeAt_guess(i);
            if (node->value_80_guess == first_guess && node->value_84_guess == second_guess) {
                if (index_guess != 0) {
                    *index_guess = i;
                }
                return NodeAt_guess(i);
            }
            if (NodeAt_guess(i)->GetItemClass_guess() == 1) {
                for (int j = 0; j < NodeAt_guess(i)->GetCount_guess(); ++j) {
                    if (NodeAt_guess(i)->GetChild_guess(j) != 0) {
                        EntryNode_guess* child = NodeAt_guess(i)->GetChild_guess(j);
                        if (child->value_80_guess == first_guess && child->value_84_guess == second_guess) {
                            if (index_guess != 0) {
                                *index_guess = i * 10 + 0x1f + j;
                            }
                            return NodeAt_guess(i)->GetChild_guess(j);
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// FUNCTION: TITANIUM 0x004BE443
// @early-stop: budget, structural ndiff=51
// Slot number -> item pointer: 0-30 and their bags (31+), 1000-1015 bank (+0xCF0), 1500+ shared bank
// (+0xD30), each with bags at base + 31 + 10*n + i. As written only 1501 reaches the shared array (1500
// takes the bank branch: > not >=) and the bag bounds allow one more than the arrays; this is an early
// stop, so check the binary before relying on those edges.
MagicEntry_guess** EQ_PCView_guess::GetItemSlotPointer_guess(unsigned int index_guess) {
    MagicEntry_guess** result_guess = 0;
    if (index_guess < 1000) {
        if ((int)index_guess >= 0 && (int)index_guess < 0x1f) {
            result_guess = reinterpret_cast<ValueEntry_guess*>(
                &embedded_8[holder_8->vbaseOffset_0004_guess])
                ->GetSlot_guess((int)index_guess);
        } else {
            int group_guess = ((int)index_guess - 0x1f) / 10;
            int sub_guess = ((int)index_guess - 0x1f) % 10;
            if (reinterpret_cast<ValueEntry_guess*>(
                    &embedded_8[holder_8->vbaseOffset_0004_guess])
                    ->GetFirst_guess(group_guess) != 0 &&
                reinterpret_cast<ValueEntry_guess*>(
                    &embedded_8[holder_8->vbaseOffset_0004_guess])
                    ->GetFirst_guess(group_guess)->GetItemClass_guess() == 1) {
                result_guess = reinterpret_cast<ValueEntry_guess*>(
                    &embedded_8[holder_8->vbaseOffset_0004_guess])
                    ->GetFirst_guess(group_guess)->GetValue_guess(sub_guess);
            }
        }
    } else {
        if (index_guess > 0x5dc) {
            int offset_guess = (int)index_guess - 0x5dc;
            if (offset_guess >= 0 && offset_guess < 2) {
                return &values_d30[offset_guess];
            } else {
                int group_guess = (offset_guess - 0x1f) / 10;
                index_guess = (unsigned int)((offset_guess - 0x1f) % 10);
                if (group_guess < 0 || group_guess > 2 ||
                    (int)index_guess < 0 || (int)index_guess > 10) {
                    return 0;
                }
                int lookup_guess = (offset_guess - 0x1f) / 10;
                if (values_d30[lookup_guess] != 0 &&
                    values_d30[lookup_guess]->GetItemClass_guess() == 1) {
                    result_guess = values_d30[lookup_guess]->GetValue_guess((int)index_guess);
                }
            }
        } else {
            int offset_guess = (int)index_guess - 1000;
            if (offset_guess >= 0 && offset_guess < 0x10) {
                result_guess = &values_cf0[offset_guess];
            } else {
                int group_guess = (offset_guess - 0x1f) / 10;
                index_guess = (unsigned int)((offset_guess - 0x1f) % 10);
                if (group_guess < 0 || group_guess > 0x10 ||
                    (int)index_guess < 0 || (int)index_guess > 10) {
                    return 0;
                }
                if (values_cf0[group_guess] != 0 &&
                    values_cf0[group_guess]->GetItemClass_guess() == 1) {
                    result_guess = values_cf0[group_guess]->GetValue_guess((int)index_guess);
                }
            }
        }
    }
    return result_guess;
}

// FUNCTION: TITANIUM 0x004BE5FE
// @early-stop: budget, structural ndiff=13
// A cursor item: MoveItem (0x420F) from 30 to -1, i.e. destroy. Else cursor coins: MoveCoin (0x7657) of the
// largest kind held (3 platinum .. 0 copper), 0x14 bytes.
void EQ_PCView_guess::DestroyHeldItemOrMoney() {
    OwnedSlot_guess* slot = &FindCounts_guess()->slot_10;
    if (slot->owned_78 != 0) {
        Message_guess message;
        message.value = -1;
        message.type = 0x1e;
        message.unused = 0;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_MoveItem, &message, 0xc, 1);
        g_flags_905d24_guess->value_10 = 0;
        slot = &FindCounts_guess()->slot_10;
        Owned_guess* owned = slot->owned_78;
        if (owned != 0) {
            owned->Slot00_guess(1);
        }
        slot = &FindCounts_guess()->slot_10;
        slot->owned_78 = 0;
    } else {
        if (g_flags_905d24_guess->value_11 != 0) {
            struct Packet_guess {
                int zero_0;
                int minus_one_4;
                int kind_8;
                int kind_c;
                int count_10;
            } packet;
            packet.minus_one_4 = -1;
            packet.count_10 = 0;
            packet.zero_0 = 0;
            packet.kind_8 = 0;
            if (FindCounts_guess()->value_11e4 > 0) {
                packet.kind_8 = 3;
                packet.count_10 = FindCounts_guess()->value_11e4;
            } else if (FindCounts_guess()->value_11e8 > 0) {
                packet.kind_8 = 2;
                packet.count_10 = FindCounts_guess()->value_11e8;
            } else if (FindCounts_guess()->value_11ec > 0) {
                packet.kind_8 = 1;
                packet.count_10 = FindCounts_guess()->value_11ec;
            } else if (FindCounts_guess()->value_11f0 > 0) {
                packet.kind_8 = 0;
                packet.count_10 = FindCounts_guess()->value_11f0;
            }
            if (packet.count_10 > 0) {
                packet.kind_c = packet.kind_8;
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_MoveCoin, &packet, 0x14, 1);
                g_flags_905d24_guess->value_11 = 0;
                FindCounts_guess()->value_11e4 = 0;
                FindCounts_guess()->value_11e8 = 0;
                FindCounts_guess()->value_11ec = 0;
                FindCounts_guess()->value_11f0 = 0;
            }
        }
    }
    value_c28c = 1;
}

// Clears the three dwords at +0xC36C and the two after them (+0xC378, +0xC37C), then the six at +0xC354
// (0x0045871F).
// FUNCTION: TITANIUM 0x004BE82F
void ClearC36C_guess::Clear_guess() {
    first = 0;
    second = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        values_c36c[i] = 0;
    }
    SetC354_guess();
}


/* ---- EQ_PC::EQ_PC (0x004BF2A7) ----------------------------------------------------------------------
 * Layout (0xC4D0, include/titanium/types.h EQ_PC): two bases that share one virtual base.
 * EQ_PC's only base, PcBase_guess (ctor 0x004BE859, called with the most-derived flag 0), has two bases:
 *   +0x0000 PcProfileBase_guess (0xC280): vfptr, int, vbptr (+8), ...
 *   +0xC280 PcCharacter1_guess (0x100): vfptr, vbptr (+4), ...  (MQ2 pCharData1 / EQ_Character1)
 *   +0xC380 vtordisp of the virtual base
 *   +0xC384 PcCharacter_guess (0x14C, virtual base): vfptr, the GetCharInfo2 list at +4, ...; ctor 0x005FB0D0 */

struct PcCharInfo2_guess {
    char pad_0000[0x1194];
    unsigned char gender_1194_guess;   // 0x1194
    char pad_1195[3];
    int race_1198_guess;             // 0x1198 race
    unsigned char class_119c_guess;   // 0x119c class
    char pad_119d[7];
    int level_11a4_guess;             // 0x11a4 level
    char pad_11a8[0xc];
    // 0x11B4..0x11CC: seven ints the ctor sets to 50, probably the base stats.
    int baseStr_11b4_guess;             // 0x11b4
    int baseSta_11b8_guess;             // 0x11b8
    int baseCha_11bc_guess;             // 0x11bc
    int baseDex_11c0_guess;             // 0x11c0
    int baseInt_11c4_guess;             // 0x11c4
    int baseAgi_11c8_guess;             // 0x11c8
    int baseWis_11cc_guess;             // 0x11cc
};

struct PcText32_guess {
    char buffer[0x20];
    // EXTERNAL: TITANIUM 0x00454EA9 PcText32_guess::Copy_guess
    char Copy_guess(const char* source);
};

struct PcVec3_guess {
    float y;
    float x;
    float z;
};

struct PcCharacterList_guess {
    void* list;                 // 0x04
    int key;                    // 0x08
    // EXTERNAL: TITANIUM 0x0060D5A8 PcCharacterList_guess::~PcCharacterList_guess
    ~PcCharacterList_guess();
    // EXTERNAL: TITANIUM 0x005EC220 PcCharacterList_guess::GetCharInfo2
    PcCharInfo2_guess* GetCharInfo2();
};

struct PcCharacter_guess : PcCharacterList_guess {
    // EXTERNAL: TITANIUM 0x005FA2C0 ??1PcCharacter_guess@@UAE@XZ
    virtual ~PcCharacter_guess();
    virtual void VSlot01_guess();
    virtual void VSlot02_guess();
    virtual void VSlot03_guess();
    virtual void VSlot04_guess();
    virtual void VSlot05_guess();
    virtual void VSlot06_guess();
    virtual void VSlot07_guess();
    virtual void VSlot08_guess();
    virtual void VSlot09_guess();
    virtual void VSlot10_guess();
    virtual void VSlot11_guess();
    virtual void VSlot12_guess();
    virtual void VSlot13_guess();
    virtual void VSlot14_guess();
    virtual void VSlot15_guess();
    virtual void VSlot16_guess();
    virtual void VSlot17_guess();
    char pad_00c[0x20];
    PcVec3_guess pos_02c;               // 0x02c
    float heading_038;                  // 0x038
    char name_03c[0x40];                // 0x03c
    PcText32_guess text_07c;            // 0x07c
    char pad_09c[0x60];
    unsigned char field_0fc;            // 0x0fc
    char pad_0fd[3];
    int zone_100;                       // 0x100
    unsigned char field_104;            // 0x104
    char pad_105[0x47];
    // EXTERNAL: TITANIUM 0x005FB0D0 ??0PcCharacter_guess@@QAE@XZ
    PcCharacter_guess();
    PcCharInfo2_guess* GetProfile_guess() { return GetCharInfo2(); }
    void SetPos_guess(float newY, float newX, float newZ) {
        pos_02c.y = newY;
        pos_02c.x = newX;
        pos_02c.z = newZ;
    }
    // EXTERNAL: TITANIUM 0x0040E293 PcCharacter_guess::SetField11a8_guess
    void SetField11a8_guess(int value);
    void* Delete_guess(int flags);
    int GetCompleteObject_guess();
    // EXTERNAL: TITANIUM 0x0040CC50 PcCharacter_guess::GetEntry_guess
    EQ_ItemView_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0041AA84 PcCharacter_guess::ClearEntry_guess
    void ClearEntry_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0040CC6B PcCharacter_guess::GetOtherEntry_guess
    EQ_ItemView_guess* GetOtherEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00434792 PcCharacter_guess::SetTributeItem_guess
    void SetTributeItem_guess(int index_guess, int value_guess);
};

struct PcNode10_guess {
    char pad_0[0x10];
    PcNode10_guess* next_010;
};

struct PcNodeC_guess {
    char pad_0[0xc];
    PcNodeC_guess* next_00c;
};

struct PcPrefix_guess {
    virtual void PSlot00_guess();
    virtual void PSlot01_guess();
    virtual void PSlot02_guess();
    virtual void PSlot03_guess();
    int field_004;
};

struct PcProfileBase_guess : PcPrefix_guess, virtual PcCharacter_guess {
    // EXTERNAL: TITANIUM 0x005F0F50 ??0PcProfileBase_guess@@QAE@XZ
    PcProfileBase_guess();
    // EXTERNAL: TITANIUM 0x005EE700 ??1PcProfileBase_guess@@UAE@XZ
    ~PcProfileBase_guess();
    // EXTERNAL: TITANIUM 0x005F1110 PcProfileBase_guess::VSlot03_guess
    virtual void VSlot03_guess();
    // EXTERNAL: TITANIUM 0x005F0E20 PcProfileBase_guess::SetEntry_guess
    void SetEntry_guess(int index_guess, int value_guess);
    char pad_00c[0xcf0 - 0xc];
    BoundedArray_guess<EQ_ItemView_guess*, 16> cache_cf0;   // 0xcf0
    BoundedArray_guess<EQ_ItemView_guess*, 2> cache_d30;    // 0xd30
    char pad_d38[0xe18 - 0xd38];
    int field_e18;                      // 0xe18
    char pad_e1c[0xe6c - 0xe1c];
    PcNode10_guess* head_e6c;           // 0xe6c
    char pad_e70[0x1144 - 0xe70];
    PcNodeC_guess* head_1144;           // 0x1144
    char pad_1148[0xc280 - 0x1148];
};

struct PcEffect_guess {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    char pad_3;
    int field_4;
    int field_8;
    int field_c;
};

struct PcSub0d8_guess {
    char data_guess[0x20];
    // EXTERNAL: TITANIUM 0x0041682F PcSub0d8_guess::Release_guess
    void Release_guess();
    // EXTERNAL: TITANIUM 0x0041E7DC PcSub0d8_guess::FUN_0041e7dc_guess
    void FUN_0041e7dc_guess();
};

struct PcCharacter1_guess : virtual PcCharacter_guess {
    // EXTERNAL: TITANIUM 0x0041E71F ??0PcCharacter1_guess@@QAE@XZ
    PcCharacter1_guess();
    virtual void VSlot01_guess();
    virtual void CSlot00_guess();
    virtual void CSlot01_guess();
    virtual int CSlot02_guess();
    virtual void CSlot03_guess();
    virtual void CSlot04_guess();
    virtual EQ_ItemView_guess* CSlot05_guess(int index_guess);
    void* player_008;                   // 0xc288
    unsigned char field_00c;            // 0xc28c
    char pad_00d[3];
    int field_010;                    // 0xc290
    int field_014;                    // 0xc294
    int field_018;                    // 0xc298
    int field_01c;                    // 0xc29c
    int field_020;                    // 0xc2a0
    int field_024;                    // 0xc2a4
    int field_028;                    // 0xc2a8
    int field_02c;                    // 0xc2ac
    int field_030;                    // 0xc2b0
    int field_034;                    // 0xc2b4
    int field_038;                    // 0xc2b8
    int field_03c;                    // 0xc2bc
    int field_040;                    // 0xc2c0
    int pad_044;
    int field_048;                      // 0xc2c8
    char pad_04c[0x7c];
    unsigned char field_0c8;            // 0xc348
    char pad_0c9[0xf];
    PcSub0d8_guess sub_0d8;             // 0xc358
    int field_0f8;                      // 0xc378
    int pad_0fc;
    // EXTERNAL: TITANIUM 0x0040D933 PcCharacter1_guess::GetMaxEffects_guess
    unsigned char GetMaxEffects_guess();
    // EXTERNAL: TITANIUM 0x0040E7AC PcCharacter1_guess::GetBuff_guess
    PcEffect_guess* GetBuff_guess(int index);
    // EXTERNAL: TITANIUM 0x00417DE0 PcCharacter1_guess::Recompute_guess
    void Recompute_guess(int mode);
};

struct PcBase_guess : PcProfileBase_guess, PcCharacter1_guess {
    PcBase_guess();
    virtual ~PcBase_guess();
    virtual void VSlot03_guess();
};

// EXTERNAL: TITANIUM 0x0064BA10 ??_7PcBase_guess@@6BPcPrefix_guess@@@
// EXTERNAL: TITANIUM 0x0064B9F8 ??_7PcBase_guess@@6BPcCharacter1_guess@@@
// EXTERNAL: TITANIUM 0x0064B9B0 ??_7PcBase_guess@@6BPcCharacter_guess@@@

// PcBase constructor: clears its state block (0x004BE82F).
// FUNCTION: TITANIUM 0x004BE859
PcBase_guess::PcBase_guess() {
    ((ClearC36C_guess*)this)->Clear_guess();
}

// FUNCTION: TITANIUM 0x004BE9B0
// @early-stop: budget, structural ndiff=4
// EQ_Character vtable slot 12: from the virtual base back to the complete EQ_PC (vtordisp, then the
// 0x100-byte EQ_Character1 and its +0xC284 offset).
int PcCharacter_guess::GetCompleteObject_guess() {
    PcCharacter_guess* adjusted = this;
    PcCharacterVtordisp_guess* vtordisp = ((PcCharacterVtordisp_guess*)adjusted) - 1;
    adjusted = (PcCharacter_guess*)((int)adjusted - vtordisp->value);
    adjusted = (PcCharacter_guess*)((int)adjusted - 0x100);
    return (int)adjusted - 0xc284;
}

// FUNCTION: TITANIUM 0x004BE9DC
// @early-stop: budget, structural ndiff=45
// Frees every owned item: slots 0-30, 5 more (0x0040CC6B), the 2 shared-bank items, the 16 bank items; then
// the lists at +0xE6C and +0x1144.
PcBase_guess::~PcBase_guess() {
    PcProfileBase_guess* profile = this;
    int index;
    for (index = 0; index < 0x1f; ++index) {
        if (GetEntry_guess(index) != 0) {
            EQ_ItemView_guess* entry = GetEntry_guess(index);
            if (entry != 0) {
                entry->Free_guess(1);
            }
            ClearEntry_guess(index, 0);
        }
    }
    for (index = 0; index < 5; ++index) {
        if (GetOtherEntry_guess(index) != 0) {
            EQ_ItemView_guess* entry = GetOtherEntry_guess(index);
            if (entry != 0) {
                entry->Free_guess(1);
            }
            SetTributeItem_guess(index, 0);
        }
    }
    for (index = 0; index < 2; ++index) {
        if (CSlot05_guess(index) != 0) {
            EQ_ItemView_guess* entry = CSlot05_guess(index);
            if (entry != 0) {
                entry->Free_guess(1);
            }
            profile->SetEntry_guess(index, 0);
        }
    }
    reinterpret_cast<EQ_PCView_guess*>(profile)->EmptyPossessionSlots_guess();
    for (index = 0; index < 16; ++index) {
        if (profile->cache_cf0[index] != 0) {
            EQ_ItemView_guess* entry = profile->cache_cf0[index];
            if (entry != 0) {
                entry->Free_guess(1);
            }
            profile->cache_cf0[index] = 0;
        }
    }
    for (index = 0; index < 2; ++index) {
        if (profile->cache_d30[index] != 0) {
            EQ_ItemView_guess* entry = profile->cache_d30[index];
            if (entry != 0) {
                entry->Free_guess(1);
            }
            profile->cache_d30[index] = 0;
        }
    }
    profile->PSlot00_guess();
    while (head_e6c != 0) {
        PcNode10_guess* node = head_e6c;
        head_e6c = node->next_010;
        delete node;
    }
    while (head_1144 != 0) {
        PcNodeC_guess* node = head_1144;
        head_1144 = node->next_00c;
        delete node;
    }
    sub_0d8.Release_guess();
}

// EXTERNAL: TITANIUM 0x004B85AE FindItemsById_guess
char __cdecl FindItemsById_guess(EQ_PCView_guess* object, int value, int one, int zero, PlayerTable_guess* table, int* values);

// EXTERNAL: TITANIUM 0x004B7772 FindLocationIndex_guess
int __cdecl FindLocationIndex_guess(int first, int second, int third, int fourth,
    PlayerTable_guess* table, int zero, int field);

// EXTERNAL: TITANIUM 0x004B89DE MoveMultipleItems_guess
int __cdecl MoveMultipleItems_guess(EQ_PCView_guess* object, PlayerTable_guess* table, int zero);

struct Notice_guess {
    // EXTERNAL: TITANIUM 0x0044A537 Notice_guess::WavePlay_guess
    void WavePlay_guess(int first, int second);
};

#define g_notice_guess EQ_GLOBAL(Notice_guess*, 0x00851390)
#define g_busyCount_guess EQ_GLOBAL(int, 0x009248D0)

struct SendText_guess {
    int value_guess;
    int field_4_guess;
    char name_guess[0x40];
};

// FUNCTION: TITANIUM 0x004BEC4E
// @early-stop: budget, diff ndiff=22
// The set with this name, else the first empty one; none free gives string 0x2480 ("There is no availble
// bandolier slot...", sic).
int EQ_PCView_guess::SaveBandolier_guess(char* name) {
    int index = -1;
    int i = 0;
    for (;;) {
        if (i >= 4) {
            break;
        }
        if (index == -1 && FUN_005f0c30_guess(i)->active == 0) {
            index = i;
        }
        if (FUN_00574460_guess(name, FUN_005f0c30_guess(i)) == 0) {
            index = i;
            break;
        }
        ++i;
    }
    if (index != -1) {
        CreateBandolier_guess(index, name);
    } else {
        token_string_to_client_guess(this ? &inner_c280 : 0, 0x2480, 10, 0);
    }
    return index;
}

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// FUNCTION: TITANIUM 0x004BECC9
// `second` is an item id: finds it (0x004B85AE), stores id, icon and name in belt slot `index`, then
// PotionBelt (0x719) action 0 {0, slot, id}.
void EQ_PCView_guess::AddPotionBeltItem_guess(int index, int second) {
    if (index >= 0 && index < GetPotionBeltSize_guess()) {
        PlayerTable_guess table(0x20);
        if (FindItemsById_guess(this, second, 1, 4, &table, 0)) {
            PcCharacter1View_guess* inner = this ? &inner_c280 : 0;
            ItemInstanceView_guess* player = *table.blocks_010[0 >> table.shift_00c]->GetInventorySlot_guess(inner);
            SendText_guess text;
            text.field_4_guess = 0;
            text.name_guess[0] = 0;
            text.value_guess = second;
            if (player != 0) {
                text.field_4_guess = player->FUN_005e0f60_guess();
                FUN_0060e450_guess(text.name_guess, player->FUN_005e0ec0_guess());
            }
            FUN_005f0d00_guess(index, &text);
            Message_guess message;
            message.type = 0;
            message.unused = second;
            message.value = index;
            EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_PotionBelt, &message, 0xc, 1);
        }
    }
}

// FUNCTION: TITANIUM 0x004BEDCA
// Needs the ready bit (Character1 base +0x10D bit 0) and no busy count (0x009248D0). Casts the item with
// kind 0xB; item type 0x15 (potion) also raises notice 0x95.
void EQ_PCView_guess::UsePotionBeltItem_guess(int index) {
    PcCharacter1View_guess* inner = &inner_c280;
    if ((reinterpret_cast<ByteView_guess*>(inner)->bytes_guess[inner->holder_4->vbaseOffset_0004_guess + 0x10d] & 1) != 0 &&
        g_busyCount_guess == 0 && index >= 0) {
        if (index < GetPotionBeltSize_guess()) {
            PlayerTable_guess table(0x20);
            if (FindItemsById_guess(this, *FUN_005f0cd0_guess(index), 1, 4, &table, 0)) {
                index = reinterpret_cast<int>(this ? inner : 0);
                PcCharacter1View_guess* result = reinterpret_cast<PcCharacter1View_guess*>(index);
                if (table.blocks_010[0 >> table.shift_00c]->GetInventorySlot_guess(result) != 0) {
                    if (*table.blocks_010[0 >> table.shift_00c]->GetInventorySlot_guess(result) != 0) {
                        if (inner->CastSpell(0xb, 0, table.blocks_010[0 >> table.shift_00c]->GetInventorySlot_guess(result), table.blocks_010[0 >> table.shift_00c]->head_0, 0)) {
                            if ((*table.blocks_010[0 >> table.shift_00c]->GetInventorySlot_guess(result))->GetItemType_guess() == 0x15) {
                                g_notice_guess->WavePlay_guess(0x95, 0);
                            }
                        }
                    }
                }
            }
        }
    }
}

// EXTERNAL: TITANIUM 0x0064BA90 ??_7EQ_PC_guess@@6BPcPrefix_guess@@@
// EXTERNAL: TITANIUM 0x0064BA78 ??_7EQ_PC_guess@@6BPcCharacter1_guess@@@
// EXTERNAL: TITANIUM 0x0064BA30 ??_7EQ_PC_guess@@6BPcCharacter_guess@@@
// EXTERNAL: TITANIUM 0x0064BAA8 ??_8EQ_PC_guess@@7BPcProfileBase_guess@@@
// EXTERNAL: TITANIUM 0x0064BAA0 ??_8EQ_PC_guess@@7BPcCharacter1_guess@@@
struct EQ_PC_guess : PcBase_guess {
    EQ_PC_guess();
    virtual void VSlot01_guess();
    virtual void VSlot03_guess();
};

#define g_emptyNotice_guess EQ_ARRAY(char, 0x006410A8)

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
int __cdecl FUN_00576e80_guess();

#define g_value923834_guess EQ_GLOBAL(int, 0x00923834)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

// FUNCTION: TITANIUM 0x004BEF02
// @early-stop: budget, structural ndiff=85
// Guildmaster refusals 0x327B-0x3283 ("I don't know that skill...", "...more skilled than I!"), with the
// target's name as %1; 0x327D when there are no practice points (+0x11F8). Tinkering (0x39) is for gnomes
// (race 12) only.
bool EQ_PCView_guess::BitchCanTrain_guess(int level_guess, int flag_guess, unsigned int index_guess) {
    char buf[256];
    if (index_guess == 0xffffffff) {
        FUN_0046da4a_guess(buf, 0x327b, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buf);
        return false;
    }
    if (index_guess == 0x39 && FindResult_guess()->race_guess != 0xc) {
        return false;
    }
    if (flag_guess != 0) {
        if (CanLearnLanguage_guess(index_guess) == 0) {
            FUN_0046da4a_guess(buf, 0x327c, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buf);
            return false;
        }
        if (FindResult_guess()->practicePoints_11f8_guess > 0) {
            if (index_guess >= 0x20) {
                __debugbreak();
            }
            unsigned char* bytes_guess = reinterpret_cast<ByteView_guess*>(this)->bytes_guess + holder_8->vbaseOffset_0004_guess + 0x14;
            if (bytes_guess[index_guess] == 'd') {
                FUN_0046da4a_guess(buf, 0x327e, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess),
                    g_everQuestText_guess->GetLangDesc_guess(index_guess), 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buf);
                return false;
            }
            if (index_guess >= 0x20) {
                __debugbreak();
            }
            if (bytes_guess[index_guess] < level_guess) {
                return true;
            }
            FUN_0046da4a_guess(buf, 0x327f, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buf);
            return false;
        }
        FUN_0046da4a_guess(buf, 0x327d, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buf);
        return false;
    }
    if (IsTradeSkill_guess(index_guess) != 0 &&
            (int)reinterpret_cast<ValueEntry_guess*>(&reinterpret_cast<ByteView_guess*>(this)->bytes_guess[holder_8->vbaseOffset_0004_guess + 8])->GetSkill_guess(index_guess) > 0x14) {
        token_string_to_client_guess(&inner_c280, 0x75, 0xd, 0);
        return false;
    }
    if (FindResult_guess()->practicePoints_11f8_guess > 0) {
        if (g_rows_guess[index_guess]->FUN_0044a335_guess(FindResult_guess()->classId_guess) == 0) {
            FUN_0046da4a_guess(buf, 0x3280, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buf);
            return false;
        }
        unsigned char kind_guess = FindResult_guess()->classId_guess;
        int limit_guess = FindResult_guess()->level_guess;
        if (g_rows_guess[index_guess]->FUN_0044a2e4_guess(kind_guess) > limit_guess) {
            FUN_0046da4a_guess(buf, 0x3281, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buf);
            return false;
        }
        if (AtSkillLimit_guess(index_guess)) {
            FUN_0046da4a_guess(buf, 0x3282, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess),
                (int)pStringTable->getString(g_rows_guess[index_guess]->id_0, 0), 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(buf);
            return false;
        }
        if ((int)reinterpret_cast<ValueEntry_guess*>(&reinterpret_cast<ByteView_guess*>(this)->bytes_guess[holder_8->vbaseOffset_0004_guess + 8])->GetSkill_guess(index_guess) < level_guess) {
            return true;
        }
        FUN_0046da4a_guess(buf, 0x3283, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buf);
        return false;
    }
    FUN_0046da4a_guess(buf, 0x327d, g_everQuestText_guess->trimName_guess(g_textSource_guess->text_120_guess), 0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buf);
    return false;
}

// FUNCTION: TITANIUM 0x004BF2A7
// Defaults: stats 50, level 1, race 1, class 2, position (0, 0, 9), mana = Max_Mana, buffs empty.
EQ_PC_guess::EQ_PC_guess() {
    ((EQ_PCView_guess*)this)->EmptyPossessionSlots_guess();
    ((ClearD30_guess*)this)->Clear_guess();
    GetProfile_guess()->baseStr_11b4_guess = 50;
    GetProfile_guess()->baseDex_11c0_guess = 50;
    GetProfile_guess()->baseAgi_11c8_guess = 50;
    GetProfile_guess()->baseSta_11b8_guess = 50;
    GetProfile_guess()->baseInt_11c4_guess = 50;
    GetProfile_guess()->baseWis_11cc_guess = 50;
    GetProfile_guess()->baseCha_11bc_guess = 50;
    field_010 = 0;
    field_014 = 0;
    field_018 = 0;
    field_01c = 0;
    field_020 = 0;
    field_024 = 0;
    field_028 = 0;
    field_02c = 0;
    field_030 = 0;
    field_034 = 0;
    field_038 = 0;
    field_03c = 0;
    field_040 = 0;
    field_048 = 0;
    field_00c = 1;
    GetProfile_guess()->level_11a4_guess = 1;
    text_07c.Copy_guess(g_emptyText_guess);
    field_0fc = 0;
    SetPos_guess(0.0f, 0.0f, 9.0f);
    heading_038 = 0.0f;
    g_value923834_guess = 0;
    field_e18 = FUN_00576e80_guess();
    field_104 = 100;
    GetProfile_guess()->gender_1194_guess = 0;
    GetProfile_guess()->class_119c_guess = 2;
    GetProfile_guess()->race_1198_guess = 1;
    field_0fc = 0;
    SetField11a8_guess(((InnerCallback_guess*)(PcCharacter1_guess*)this)->Max_Mana());
    for (int index = 0; index < GetMaxEffects_guess(); ++index) {
        PcEffect_guess* effect = GetBuff_guess(index);
        effect->field_4 = -1;
        effect->field_0 = 0;
        effect->field_8 = 0;
        effect->field_2 = 0;
        effect->field_1 = 0;
        effect->field_c = 0;
    }
    field_0c8 = 0;
    Recompute_guess(0);
    field_0f8 = 1;
}

// FUNCTION: TITANIUM 0x004BF5A5
// @early-stop: budget, diff ndiff=7
// EQ_PC's vtordisp thunk (`sub ecx,[ecx-4]`) into its scalar deleting dtor 0x004BF97C, written out as one
// function: EQ_PC's destructor and ~PcCharacter on the virtual base, then the complete object is freed.
void* PcCharacter_guess::Delete_guess(int flags) {
    EQ_PC_guess* object = (EQ_PC_guess*)GetCompleteObject_guess();
    object->EQ_PC_guess::~EQ_PC_guess();
    this->PcCharacter_guess::~PcCharacter_guess();
    if ((flags & 1) != 0) {
        operator delete(object);
    }
    return object;
}

// PcBase reset (virtual slot 3): the profile base's reset, the inventory reset (0x0041E7DC), then the
// state block clear (0x004BE82F).
// FUNCTION: TITANIUM 0x004BF285
void PcBase_guess::VSlot03_guess() {
    PcProfileBase_guess::VSlot03_guess();
    sub_0d8.FUN_0041e7dc_guess();
    ((ClearC36C_guess*)this)->Clear_guess();
}

struct FourValues_guess {
    int values[4];
};

struct PlayerEntry_guess {
    FourValues_guess values;
    int value48;
    int state0;
    int state1;
    int state2;
    int kind;
};

struct PlayerPacket_guess {
    int kind;
    char value;
    char padding[0x23];
};

// FUNCTION: TITANIUM 0x004BF5BA
// @early-stop: budget, structural ndiff=108
// Equips set `value`: finds its 4 items, plans moves into primary, secondary, range, ammo (13, 14, 11, 21)
// and runs them (0x004B89DE). Results 2 / 5 print 0x247E / 0x247F ("You do not have enough room to use
// this bandolier."). On success it updates the weapon models (7, 8) and sends Bandolier (0x6F0C) action 2.
void EQ_PCView_guess::UseBandolier_guess(int value) {
    PcCharacter1View_guess* inner = &inner_c280;
    if ((reinterpret_cast<ByteView_guess*>(inner)->bytes_guess[inner->holder_4->vbaseOffset_0004_guess + 0x10d] & 1) == 0 ||
        g_busyCount_guess != 0 || value < 0 || value >= 4 || FUN_005f0c30_guess(value)->active == 0) {
        return;
    }

    TargetPlayerTable_guess table(0x20);
    int state[4] = { 0, -1, -1, 2 };
    int identifiers[4] = { 0xd, 0xe, 0xb, 0x15 };
    FourValues_guess values = { 0, -1, -1, 0 };
    for (int slot = 0; slot < 4; ++slot) {
        int count = FUN_005f0c30_guess(value)->slots[slot].values[0];
        if (count > 0) {
            values.values[1] = identifiers[slot];
            FindItemsById_guess(this, FUN_005f0c30_guess(value)->slots[slot].values[0], 1, 0,
                (PlayerTable_guess*)&table, values.values);
        }
    }

    {
        PlayerEntry_guess entry;
        for (int slot = 0; slot < 4; ++slot) {
            int identifier = identifiers[slot];
            values.values[1] = identifier;
            if (ValueBase_guess()->GetInventorySlot_guess(identifier) != 0 &&
                FindLocationIndex_guess(values.values[0], values.values[1], values.values[2], values.values[3],
                    (PlayerTable_guess*)&table, 0, table.field_000) == -1) {
                entry.values = values;
                entry.value48 = ValueBase_guess()->GetInventorySlot_guess(identifier)->value_48;
                entry.state0 = state[0];
                entry.state1 = state[1];
                entry.state2 = state[2];
                entry.kind = state[3];
                table.FUN_004b76e3_guess(table.field_000, (int*)&entry);
            }
        }
    }

    int result = MoveMultipleItems_guess(this, (PlayerTable_guess*)&table, 0);
    if (result == 0) {
        if (spawn_guess != 0) {
            if (FindRecord_guess()->sub_10.value_34 == 0 && FindRecord_guess()->sub_10.value_38 == 0) {
                spawn_guess->UpdateItemSlot_guess(7, g_emptyNotice_guess, 0);
                if (FindRecord_guess()->sub_10.value_2c == 0) {
                    spawn_guess->UpdateItemSlot_guess(8, g_emptyNotice_guess, 0);
                } else {
                    spawn_guess->UpdateItemSlot_guess(8,
                        FindRecord_guess()->sub_10.value_2c->FUN_005e0f00_guess(), 0);
                }
            } else {
                if (FindRecord_guess()->sub_10.value_34 == 0) {
                    spawn_guess->UpdateItemSlot_guess(7, g_emptyNotice_guess, 0);
                } else {
                    spawn_guess->UpdateItemSlot_guess(7,
                        FindRecord_guess()->sub_10.value_34->FUN_005e0f00_guess(), 0);
                }
                if (FindRecord_guess()->sub_10.value_38 == 0) {
                    spawn_guess->UpdateItemSlot_guess(8, g_emptyNotice_guess, 0);
                } else {
                    spawn_guess->UpdateItemSlot_guess(8,
                        FindRecord_guess()->sub_10.value_38->FUN_005e0f00_guess(), 0);
                }
            }
        }
        if (pinstCBandolierWnd_guess != 0) {
            pinstCBandolierWnd_guess->RebuildList_guess();
        }
        if (pinstCCursorAttachment_guess != 0) {
            pinstCCursorAttachment_guess->Deactivate();
            g_display_guess->flag_12 = 0;
        }
        PlayerPacket_guess packet;
        packet.value = (char)value;
        packet.kind = 2;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_Bandolier, &packet, 0x28, 1);
    } else if (result == 2 || result == 5) {
        token_string_to_client_guess(this ? inner : 0, result == 2 ? 0x247e : 0x247f, 10, 0);
    }
}

// FUNCTION: TITANIUM 0x004BF94B
// GENERATED: PcBase_guess::`scalar deleting destructor'
// Slot 0 of PcBase's PcCharacter vtable, reached through the vtordisp thunk 0x004BE9D4: `this` is the virtual
// base at +0xC384; runs ~PcBase and ~PcCharacter (0x005FA2C0) there, then frees the complete object.

// FUNCTION: TITANIUM 0x004BF97C
// GENERATED: EQ_PC_guess::`scalar deleting destructor'
// The same for EQ_PC (vtordisp thunk 0x004BF5A5), through EQ_PC's destructor 0x004BF9AD.

// Destructor: jumps to the PcBase destructor (0x004BE9DC), which frees the owned items and lists.
// FUNCTION: TITANIUM 0x004BF9AD
// GENERATED: EQ_PC_guess::~EQ_PC_guess
// EQ_PC declares no destructor: the implicit one only runs ~PcBase.
