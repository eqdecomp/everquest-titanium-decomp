// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Split from tumap object 54 at its high/medium confidence break (0x489060..0x489840): compiled with
// FindRecord (0x488BD6) out of sight, 0x4892F2 keeps its 0xC frame (the call's out-pointers may escape).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <stdio.h>
#include <string.h>

// EXTERNAL: TITANIUM 0x00486ECB FUN_00486ecb_guess
int __cdecl FUN_00486ecb_guess(char* name_guess);
// EXTERNAL: TITANIUM 0x00488F2B FindAnimationTrack_guess
int __cdecl FindAnimationTrack_guess(int value_guess, int mode_guess, int group_guess,
	int part_guess, int index_guess);

#define g_offset_guess EQ_GLOBAL(int, 0x0066D248)
#define g_groupCount_guess EQ_GLOBAL(int, 0x0066D250)

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* fmt_guess, ...);

struct ValidationState_guess
{
	char pad_guess[0x251];
	unsigned char mode_guess;
};

struct Validator_guess
{
	char pad_guess[4];
	ValidationState_guess* state_guess;
	// EXTERNAL: TITANIUM 0x00485F20 Validator_guess::CheckValue_guess
	char CheckValue_guess(int value);
	// EXTERNAL: TITANIUM 0x0048895A Validator_guess::FUN_0048895a
	char FUN_0048895a(int value);
	char FUN_004868a4_guess(unsigned char* value_guess, int unused_guess);
};

struct Layer_guess
{
	virtual void Slot00_guess(float first_guess, int second_guess) = 0;
	virtual void Slot01_guess() = 0;
	virtual void Slot02_guess(int first_guess, float second_guess, int third_guess,
		int fourth_guess, float fifth_guess) = 0;
	virtual void Slot03_guess(int first_guess, float second_guess, int third_guess,
		int fourth_guess) = 0;
	virtual void Slot04_guess() = 0;
	virtual void Slot05_guess(int value_guess) = 0;
	virtual void Slot06_guess() = 0;
	virtual char Slot07_guess() = 0;
	virtual void Slot08_guess() = 0;
	virtual void Slot09_guess() = 0;
	virtual void Slot10_guess() = 0;
	virtual void Slot11_guess(int value_guess) = 0;
};

struct Row_guess
{
	int value_0000_guess[5];
};

struct Manager_guess
{
	virtual void Slot00_guess() = 0;
	virtual void Slot01_guess() = 0;
	virtual void Slot02_guess() = 0;
	virtual void Slot03_guess() = 0;
	virtual void Slot04_guess() = 0;
	virtual void Slot05_guess() = 0;
	virtual void Slot06_guess() = 0;
	virtual void Slot07_guess() = 0;
	virtual void Slot08_guess() = 0;
	virtual void Slot09_guess() = 0;
	virtual void Slot10_guess() = 0;
	virtual void Slot11_guess() = 0;
	virtual void Slot12_guess() = 0;
	virtual void Slot13_guess() = 0;
	virtual void Slot14_guess() = 0;
	virtual void Slot15_guess() = 0;
	virtual void Slot16_guess() = 0;
	virtual void Slot17_guess() = 0;
	virtual void Slot18_guess() = 0;
	virtual void Slot19_guess() = 0;
	virtual void Slot20_guess() = 0;
	virtual void Slot21_guess() = 0;
	virtual void Slot22_guess() = 0;
	virtual void Slot23_guess() = 0;
	virtual void Slot24_guess() = 0;
	virtual void Slot25_guess() = 0;
	virtual void Slot26_guess() = 0;
	virtual void Slot27_guess() = 0;
	virtual void Slot28_guess() = 0;
	virtual void Slot29_guess() = 0;
	virtual void Slot30_guess() = 0;
	virtual void Slot31_guess() = 0;
	virtual void Slot32_guess() = 0;
	virtual void Slot33_guess() = 0;
	virtual void Slot34_guess() = 0;
	virtual void Slot35_guess() = 0;
	virtual void Slot36_guess() = 0;
	virtual void Slot37_guess() = 0;
	virtual void Slot38_guess() = 0;
	virtual void Slot39_guess() = 0;
	virtual void Slot40_guess() = 0;
	virtual void Slot41_guess() = 0;
	virtual void Slot42_guess() = 0;
	virtual void Slot43_guess() = 0;
	virtual void Slot44_guess() = 0;
	virtual void Slot45_guess() = 0;
	virtual void Slot46_guess() = 0;
	virtual void Slot47_guess() = 0;
	virtual void Slot48_guess() = 0;
	virtual void Slot49_guess() = 0;
	virtual void Slot50_guess() = 0;
	virtual void Slot51_guess() = 0;
	virtual void Slot52_guess() = 0;
	virtual void Slot53_guess() = 0;
	virtual void Slot54_guess() = 0;
	virtual void Slot55_guess() = 0;
	virtual void Slot56_guess() = 0;
	virtual void Slot57_guess() = 0;
	virtual void Slot58_guess() = 0;
	virtual void Slot59_guess() = 0;
	virtual void Slot60_guess() = 0;
	virtual void Slot61_guess() = 0;
	virtual void Slot62_guess() = 0;
	virtual void Slot63_guess() = 0;
	virtual void Slot64_guess() = 0;
	virtual void Slot65_guess() = 0;
	virtual void Slot66_guess() = 0;
	virtual void Slot67_guess() = 0;
	virtual void Slot68_guess() = 0;
	virtual void Slot69_guess() = 0;
	virtual void Slot70_guess() = 0;
	virtual void Slot71_guess() = 0;
	virtual void Slot72_guess() = 0;
	virtual void Slot73_guess() = 0;
	virtual void Slot74_guess() = 0;
	virtual void Slot75_guess() = 0;
	virtual void Slot76_guess() = 0;
	virtual void Slot77_guess() = 0;
	virtual void Slot78_guess() = 0;
	virtual void Slot79_guess() = 0;
	virtual void Slot80_guess() = 0;
	virtual void Slot81_guess() = 0;
	virtual void Slot82_guess(int (*callback_guess)(char*), int value_guess, int flag_guess) = 0;
	virtual void Slot83_guess() = 0;
	virtual void Slot84_guess() = 0;
	virtual void Slot85_guess() = 0;
	virtual void Slot86_guess() = 0;
	virtual void Slot87_guess() = 0;
	virtual void Slot88_guess() = 0;
	virtual void Slot89_guess() = 0;
	virtual void Slot90_guess() = 0;
	virtual void Slot91_guess() = 0;
	virtual void Slot92_guess() = 0;
	virtual int Pick_guess(int which_guess) = 0;
	virtual void Slot94_guess(int kind_guess, Row_guess* row_guess, char* name_guess,
		float first_guess, int second_guess, int third_guess, float fourth_guess) = 0;
	virtual void Slot95_guess() = 0;
	virtual void Slot96_guess() = 0;
	virtual void Slot97_guess() = 0;
	virtual void Slot98_guess() = 0;
	virtual void Slot99_guess() = 0;
	virtual void Slot100_guess() = 0;
	virtual void Slot101_guess() = 0;
	virtual void Slot102_guess() = 0;
	virtual void Slot103_guess(int first_guess, int second_guess, int third_guess,
		Layer_guess* layer_guess, int fourth_guess) = 0;
	virtual void Slot104_guess(int kind_guess, int index_guess) = 0;
	virtual void Slot105_guess(int event_guess, int value_guess, int zero_guess) = 0;
	virtual void Slot106_guess(int value_guess) = 0;
};

struct PickTables_guess
{
	char pad_0000_guess[0x2c];
	int** tables_02c_guess;
	char pad_0030_guess[0x50 - 0x30];
	int value_050_guess;
};

struct State_guess
{
	Manager_guess* manager_0000_guess;
	unsigned char pad_0004_guess[0xac - 0x4];
	unsigned char headEnvironment_00ac_guess;
	unsigned char level_00ad_guess;
	unsigned char level_00ae_guess;
	unsigned char pad_00af_guess[0xbc - 0xaf];
	float value_00bc_guess;
	unsigned char pad_00c0_guess[0xc4 - 0xc0];
	float value_00c4_guess;
	unsigned char pad_00c8_guess[0x12c - 0xc8];
	PickTables_guess* tables_12c_guess;
	int value_0130_guess;
	int currentAnimation_0134_guess;
	int value_0138_guess;
	int value_013c_guess;
	int value_0140_guess;
	int value_0144_guess;
	int value_0148_guess;
	int value_014c_guess;
	unsigned char mode_0150_guess;
	char pad_0151_guess[0x154 - 0x151];
	int value_0154_guess;
	int value_0158_guess;
	int mount_015c_guess;
	char pad_0160_guess[0x1a0 - 0x160];
	int value_01a0_guess;
	int value_01a4_guess;
	int value_01a8_guess;
	int lastUpdateTime_01ac_guess;
	char pad_01b0_guess[0xf20 - 0x1b0];
	int value_0f20_guess;
	int value_0f24_guess;
	int value_0f28_guess;
	int value_0f2c_guess;
	char pad_0f30_guess[0xf48 - 0xf30];
	int value_0f48_guess;
	int value_0f4c_guess;
	int value_0f50_guess;
	char pad_0f54_guess[4];
	int value_0f58_guess;
	int value_0f5c_guess;
	int value_0f60_guess;
	int value_0f64_guess;
	int value_0f68_guess;
	char pad_0f6c_guess[4];
	int value_0f70_guess;
	int value_0f74_guess;
	int primaryItemType_0f78_guess;
	int secondaryItemType_0f7c_guess;
	char pad_0f80_guess[0xf88 - 0xf80];
	int value_0f88_guess;
	char pad_0f8c_guess[0xfb8 - 0xf8c];
	int value_0fb8_guess;
	char pad_0fbc_guess[0xfd4 - 0xfbc];
	int value_0fd4_guess;
	// EXTERNAL: TITANIUM 0x0048F019 State_guess::Forward_guess
	char Forward_guess();
};

struct Probe_guess
{
	float x_guess;
	float y_guess;
	float z_guess;
	float w_guess;
	// EXTERNAL: TITANIUM 0x00435B36 Probe_guess::FUN_00435b36_guess
	float FUN_00435b36_guess();
};

struct Vec_guess
{
	float pad_0000_guess[3];
	Probe_guess coordinates_000c_guess;
};

struct Owner_guess
{
	unsigned char pad_0000_guess[0x30];
	Vec_guess vec_0030_guess;
	unsigned char pad_004c_guess[0x58 - 0x4c];
	float value_0058_guess;
	unsigned char pad_005c_guess[0x1a8 - 0x5c];
	State_guess* pActorInfo_01a8_guess;
	unsigned char pad_01ac_guess[0x1b1 - 0x1ac];
	unsigned char flag_01b1_guess;
	unsigned char pad_01b2_guess[0x230 - 0x1b2];
	float runSpeed_0230_guess;
	unsigned char pad_0234_guess[0x244 - 0x234];
	unsigned char type_0244_guess;
	unsigned char pad_0245_guess[0x24e - 0x245];
	unsigned char mode_024e_guess;
	unsigned char pad_024f_guess[0x251 - 0x24f];
	unsigned char standState_0251_guess;
	unsigned char playerClass_0252_guess;
	unsigned char pad_0253_guess[0x25c - 0x253];
	int masterId_025c_guess;
	int race_0260_guess;
	char pad_0264_guess[0x270 - 0x264];
	int bodyType_0270_guess;
	int hpCurrent_0274_guess;
	// EXTERNAL: TITANIUM 0x0047BFD0 Owner_guess::IsHorseRace_guess
	bool IsHorseRace_guess();
	// EXTERNAL: TITANIUM 0x0047C2CD Owner_guess::Calc_guess
	float Calc_guess();
	// EXTERNAL: TITANIUM 0x00479E02 Owner_guess::LegalPlayerRace_guess
	int LegalPlayerRace_guess(int race_guess);
	// EXTERNAL: TITANIUM 0x00479F75 Owner_guess::SetCurrentLoopSound_guess
	void SetCurrentLoopSound_guess(int sound_guess);
	// EXTERNAL: TITANIUM 0x00479EE8 Owner_guess::PlaySound_guess
	void PlaySound_guess(int sound_guess);
	// EXTERNAL: TITANIUM 0x0047C007 Owner_guess::HasPlayerState_guess
	char HasPlayerState_guess(int flag_guess);
};

struct TrackSet_guess
{
	int variantTracks[8][4];
	int variantCounts[8];
	int sounds_0a0_guess[8][4];
	unsigned char state_120_guess;
	// EXTERNAL: TITANIUM 0x00451965 TrackSet_guess::TrackSet_guess
	TrackSet_guess();
};

struct TrackOwner_guess
{
	char pad_0000_guess[0x2c];
	TrackSet_guess** sets_02c_guess;
	int count_030_guess;
	char pad_0034_guess[0x50 - 0x34];
	int total_050_guess;
};

struct Actor_guess
{
	virtual void Slot00_guess() = 0;
	virtual void Slot01_guess() = 0;
	virtual void Slot02_guess() = 0;
	virtual void Slot03_guess() = 0;
	virtual void Slot04_guess() = 0;
	virtual void Slot05_guess() = 0;
	virtual void Slot06_guess() = 0;
	virtual void Slot07_guess() = 0;
	virtual void Slot08_guess() = 0;
	virtual void Slot09_guess() = 0;
	virtual void Slot10_guess() = 0;
	virtual void Slot11_guess() = 0;
	virtual void Slot12_guess() = 0;
	virtual void Slot13_guess() = 0;
	virtual void Slot14_guess() = 0;
	virtual void Slot15_guess() = 0;
	virtual void Slot16_guess() = 0;
	virtual void Slot17_guess() = 0;
	virtual void Slot18_guess() = 0;
	virtual void Slot19_guess() = 0;
	virtual void Slot20_guess() = 0;
	virtual void Slot21_guess() = 0;
	virtual void Slot22_guess() = 0;
	virtual void Slot23_guess() = 0;
	virtual void Slot24_guess() = 0;
	virtual void Slot25_guess() = 0;
	virtual void Slot26_guess() = 0;
	virtual void Slot27_guess() = 0;
	virtual void Slot28_guess() = 0;
	virtual void Slot29_guess() = 0;
	virtual void Slot30_guess() = 0;
	virtual void Slot31_guess() = 0;
	virtual void Slot32_guess() = 0;
	virtual void Slot33_guess() = 0;
	virtual void Slot34_guess() = 0;
	virtual void Slot35_guess() = 0;
	virtual void Slot36_guess() = 0;
	virtual void Slot37_guess() = 0;
	virtual void Slot38_guess() = 0;
	virtual void Slot39_guess() = 0;
	virtual void Slot40_guess() = 0;
	virtual void Slot41_guess() = 0;
	virtual void Slot42_guess() = 0;
	virtual void Slot43_guess() = 0;
	virtual void Slot44_guess() = 0;
	virtual void Slot45_guess() = 0;
	virtual void Slot46_guess() = 0;
	virtual void Slot47_guess() = 0;
	virtual void Slot48_guess() = 0;
	virtual void Slot49_guess() = 0;
	virtual void Slot50_guess() = 0;
	virtual void Slot51_guess() = 0;
	virtual void Slot52_guess() = 0;
	virtual void Slot53_guess() = 0;
	virtual void Slot54_guess() = 0;
	virtual void Slot55_guess() = 0;
	virtual void Slot56_guess() = 0;
	virtual void Slot57_guess() = 0;
	virtual void Slot58_guess() = 0;
	virtual void Slot59_guess() = 0;
	virtual void Slot60_guess() = 0;
	virtual void Slot61_guess() = 0;
	virtual void Slot62_guess() = 0;
	virtual void Slot63_guess() = 0;
	virtual void Slot64_guess() = 0;
	virtual void Slot65_guess() = 0;
	virtual void Slot66_guess() = 0;
	virtual void Slot67_guess() = 0;
	virtual void Slot68_guess() = 0;
	virtual void Slot69_guess() = 0;
	virtual int TrackCount_guess() = 0;
};

struct Mapper_guess
{
	virtual void Slot00_guess() = 0;
	virtual void Slot01_guess() = 0;
	virtual void Slot02_guess(unsigned short kind_guess, int first_guess, int second_guess,
		float scale_guess, int third_guess) = 0;
	virtual void Slot03_guess() = 0;
	virtual int Index_guess(int value_guess) = 0;
	virtual void Slot05_guess() = 0;
	virtual void Slot06_guess() = 0;
	virtual void Slot07_guess() = 0;
	virtual void Slot08_guess() = 0;
	virtual void Slot09_guess() = 0;
	virtual void Slot10_guess() = 0;
	virtual void Slot11_guess() = 0;
	virtual void Slot12_guess() = 0;
	virtual void Slot13_guess() = 0;
	virtual char Slot14_guess(int value_guess) = 0;
	virtual char Ready_guess() = 0;
	Owner_guess* owner_0004_guess;
	char flag_0008_guess;
	char pad_0009_guess[3];
	Layer_guess* second_000c_guess;
	Layer_guess* first_0010_guess;
	// EXTERNAL: TITANIUM 0x00485EB7 Mapper_guess::GetAnimBlendTime_guess
	float GetAnimBlendTime_guess(int first_guess, int second_guess);
	// EXTERNAL: TITANIUM 0x00488377 Mapper_guess::FUN_00488377_guess
	void FUN_00488377_guess(int first_kind_guess, int second_kind_guess, int index_guess,
		int value4_guess, int value5_guess, int value6_guess, int value7_guess, float value8_guess);
	// EXTERNAL: TITANIUM 0x00488128 Mapper_guess::FUN_00488128_guess
	void FUN_00488128_guess(int kind_guess, int index_guess, int value4_guess,
		int value5_guess, int value6_guess, int value7_guess, float value8_guess);
	// EXTERNAL: TITANIUM 0x00488676 Mapper_guess::FUN_00488676_guess
	void FUN_00488676_guess(int kind_guess, int count_guess, int index_guess, int value5_guess,
		int value6_guess, int value7_guess, int value8_guess, float value9_guess);
	void UpdateMovementAnimation_guess();
	char FUN_00486f3d_guess();
	void FUN_00486f60_guess();
	void UpdateIdleAnimation_guess(int value_guess);
	void UpdateAnimation_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x00488BD6 Mapper_guess::FUN_00488bd6_guess
	char FUN_00488bd6_guess(int table_guess, int* first_guess, int* second_guess);
	// EXTERNAL: TITANIUM 0x00485FD6 Mapper_guess::SelectMode_guess
	int SelectMode_guess(int key_guess);
	// EXTERNAL: TITANIUM 0x00485F57 Mapper_guess::RemapAnimationKey_guess
	int RemapAnimationKey_guess(int key_guess, int record_guess);
	// EXTERNAL: TITANIUM 0x00485E69 Mapper_guess::PickRandomVariant_guess
	int PickRandomVariant_guess(int table_guess, int record_guess);
	void PlayAnimationVariant_guess(int id_guess, int unused_guess, int kind_guess, float scale_guess);
	// EXTERNAL: TITANIUM 0x00488974 Mapper_guess::PlayAnimation_guess
	void PlayAnimation_guess(int kind_guess, int flag_guess, int value_guess,
		float scale_guess, int zero_guess);
	// EXTERNAL: TITANIUM 0x004860A3 Mapper_guess::PlayAnimationSound_guess
	void PlayAnimationSound_guess(int first_guess, int second_guess, int third_guess,
		int fourth_guess);
	void FUN_00489060_guess();
	void InitAnimationTracks_guess(TrackOwner_guess* owner_guess, Actor_guess* actor_guess);
	int FUN_004891e9_guess(int first_guess, int second_guess, int third_guess,
		int fourth_guess, int fifth_guess, int sixth_guess, char seventh_guess);
	char FUN_0048960d_guess(unsigned short first_guess, int unused_guess, int flag_guess,
		float scale_guess, int final_guess);
	// EXTERNAL: TITANIUM 0x00485EDC Mapper_guess::FUN_00485edc_guess
	char FUN_00485edc_guess(int first_guess, int second_guess);
};

struct TableRow_guess
{
	int value_000_guess;
	int pad_004_guess[2];
	int kind_00c_guess;
	int pad_010_guess[5];
};

#define g_rowTable_guess EQ_ARRAY(TableRow_guess, 0x00692538)

#define g_nameTable_guess EQ_ARRAY(char*, 0x0069254C)
#define g_nameParts_guess EQ_ARRAY(char, 0x006932F8)

// EXTERNAL: TITANIUM 0x0048C879 GetRaceModelTag_guess
void __cdecl GetRaceModelTag_guess(char* output_guess, int value_guess, int mode_guess);

// Binds the model's tracks: filters out head/arm/neck, then looks up every animation x 8 parts x 4 variants.
// FUNCTION: TITANIUM 0x00489060
void Mapper_guess::FUN_00489060_guess()
{
	PickTables_guess* tables_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess;
	if (tables_guess == 0)
		return;
	owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot82_guess(FUN_00486ecb_guess,
		tables_guess->value_050_guess, 1);
	first_0010_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(0);
	second_000c_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(1);
	for (int group_guess = 0; group_guess < g_groupCount_guess; group_guess++)
	{
		if (owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[group_guess] != 0)
		{
			for (int part_guess = 0; part_guess < 8; part_guess++)
			{
				for (int index_guess = 0; index_guess < 4; index_guess++)
				{
					int value_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[group_guess][part_guess * 4 + index_guess];
					if (value_guess != 0)
					{
						if (first_0010_guess != 0)
							first_0010_guess->Slot05_guess(value_guess);
						if (second_000c_guess != 0)
							second_000c_guess->Slot05_guess(owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[group_guess][part_guess * 4 + index_guess]);
					}
				}
			}
		}
	}
	if (tables_guess->tables_02c_guess[0x6e - g_offset_guess] != 0 &&
		tables_guess->tables_02c_guess[0x6e - g_offset_guess][0] != 0)
	{
		PlayAnimation_guess(0x6e, 0, 0, 1.0f, 0);
		if (owner_0004_guess->type_0244_guess < 2)
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot106_guess(0x12c);
		owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot17_guess();
	}
}

// Whether animation (first, second) may replace (third, fourth) on layer `sixth_guess`: 2 no layer, 3 same
// animation. For class 62 ('>', LDoN treasure) 0x91 counts as 0x92.
// FUNCTION: TITANIUM 0x004891E9
int Mapper_guess::FUN_004891e9_guess(int first_guess, int second_guess, int third_guess,
	int fourth_guess, int fifth_guess, int sixth_guess, char seventh_guess)
{
	Layer_guess* layer_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(sixth_guess);
	if (layer_guess == 0)
		return 2;
	if (owner_0004_guess->playerClass_0252_guess == '>')
	{
		if (third_guess == 0x91 - g_offset_guess)
			third_guess = 0x92;
		else if (first_guess == 0x91 - g_offset_guess)
			first_guess = 0x92;
	}
	if (first_guess == third_guess && second_guess == fourth_guess)
		return 3;
	if (third_guess == 0xfe)
		return 2;
	if (first_guess == 0x92 - g_offset_guess)
		return 2;
	if (seventh_guess == 2)
		return 2;
	int kind_guess = g_rowTable_guess[third_guess].kind_00c_guess;
	if (third_guess == 0x92 - g_offset_guess && owner_0004_guess->standState_0251_guess != 's' &&
		owner_0004_guess->type_0244_guess < 2)
		kind_guess = 3;
	if (kind_guess == 1)
		return 0;
	if (layer_guess->Slot07_guess() == 0)
	{
		if (kind_guess != 3)
			return 1;
		if (g_rowTable_guess[third_guess].value_000_guess > g_rowTable_guess[first_guess].value_000_guess &&
			((Validator_guess*)this)->FUN_0048895a(third_guess) == 0)
			return 1;
		if (FUN_00485edc_guess(third_guess, first_guess) == 0)
			return 1;
	}
	return 2;
}

// Starts a random variant of animation `id_guess` on both layers (with `scale_guess` and `kind_guess`)
// and records it as the layer-0 animation.
// FUNCTION: TITANIUM 0x004892F2
void Mapper_guess::PlayAnimationVariant_guess(int id_guess, int unused_guess, int kind_guess,
	float scale_guess)
{
	int table_guess = Index_guess((unsigned short)id_guess);
	int row_guess = 0;
	id_guess = 0;
	if (!FUN_00488bd6_guess(table_guess, &row_guess, &id_guess))
		return;

	int random_guess = PickRandomVariant_guess(row_guess, id_guess);
	int* values_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[row_guess];
	int value_guess = values_guess[random_guess + id_guess * 4];
	Layer_guess* first_guess =
		(Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(0);
	Layer_guess* second_guess =
		(Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(1);
	if (first_guess != 0)
		first_guess->Slot02_guess(value_guess, scale_guess, kind_guess,
			EQ_ARRAY(int, 0x00692548)[table_guess * 9], 0.0f);
	if (second_guess != 0)
		second_guess->Slot02_guess(value_guess, scale_guess, kind_guess,
			EQ_ARRAY(int, 0x00692548)[table_guess * 9], 0.0f);
	owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess = table_guess + g_offset_guess;
}

struct SoundEntry_guess
{
	char name_000_guess[0x18];
	int sound_018_guess;
};

struct SoundNode_guess
{
	SoundEntry_guess* entry_000_guess;
	int key_004_guess;
	SoundNode_guess* next_008_guess;
};

struct SoundTable_guess
{
	// EXTERNAL: TITANIUM 0x004FF9C9 SoundTable_guess::Find_guess
	SoundNode_guess* Find_guess(unsigned int hash_guess);
	// EXTERNAL: TITANIUM 0x0047C397 SoundTable_guess::FindNext_guess
	SoundNode_guess* FindNext_guess(SoundNode_guess* node_guess);
};

struct SoundManager_guess
{
	// EXTERNAL: TITANIUM 0x0044BEA0 SoundManager_guess::WaveLoadById_guess
	void WaveLoadById_guess(int sound_guess, char flag_guess);
	// EXTERNAL: TITANIUM 0x0044A516 SoundManager_guess::IsMuted_guess
	char IsMuted_guess(int sound_guess);
};

#define g_soundTable_guess EQ_GLOBAL(SoundTable_guess, 0x00903E60)
#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)
// EXTERNAL: TITANIUM 0x0042E3B4 Hash_guess
int __cdecl Hash_guess(const char* text_guess);

// Creates the per-group track sets and fills them from the actor's tracks; logs "actor is NULL in
// InitAnimationTracks()!".
// FUNCTION: TITANIUM 0x004893EB
void Mapper_guess::InitAnimationTracks_guess(TrackOwner_guess* owner_guess, Actor_guess* actor_guess)
{
	if (actor_guess == 0)
	{
		Log_guess("actor is NULL in InitAnimationTracks()!\n");
		return;
	}
	if (owner_0004_guess->pActorInfo_01a8_guess == 0 || actor_guess->TrackCount_guess() < 1)
		return;
	owner_guess->count_030_guess = actor_guess->TrackCount_guess();
	for (int group_guess = 0; group_guess < g_groupCount_guess; group_guess++)
	{
		if (owner_guess->sets_02c_guess[group_guess] == 0)
			owner_guess->sets_02c_guess[group_guess] = new TrackSet_guess;
		for (int part_guess = 0; part_guess < 6; part_guess++)
		{
			for (int index_guess = 0; index_guess < 4; index_guess++)
			{
				unsigned char mode_guess = owner_0004_guess->mode_024e_guess;
				int value_guess = owner_0004_guess->race_0260_guess;
				int track_guess = FindAnimationTrack_guess(value_guess, mode_guess,
					group_guess, part_guess, index_guess);
				if (track_guess == 0)
					continue;
				owner_guess->sets_02c_guess[group_guess]->state_120_guess = 2;
				owner_guess->sets_02c_guess[group_guess]->variantTracks[part_guess][index_guess] = track_guess;
				owner_guess->sets_02c_guess[group_guess]->variantCounts[part_guess]++;
				owner_guess->total_050_guess++;
				char name_guess[32];
				char key_guess[32];
				GetRaceModelTag_guess(name_guess, owner_0004_guess->race_0260_guess,
					owner_0004_guess->mode_024e_guess);
				sprintf(key_guess, "%s_%s_%d_%s",
					g_nameTable_guess[group_guess * 9], g_nameParts_guess + part_guess * 3,
					index_guess + 1, name_guess);
				for (SoundNode_guess* node_guess = g_soundTable_guess.Find_guess(Hash_guess(key_guess));
					node_guess != 0; node_guess = g_soundTable_guess.FindNext_guess(node_guess))
				{
					if (strcmp(node_guess->entry_000_guess->name_000_guess, key_guess) == 0)
					{
						owner_guess->sets_02c_guess[group_guess]->sounds_0a0_guess[part_guess][index_guess] =
							node_guess->entry_000_guess->sound_018_guess;
						g_soundManager_guess->WaveLoadById_guess(node_guess->entry_000_guess->sound_018_guess, 1);
					}
				}
			}
		}
	}
}

// Starts animation `first_guess` (a class-62 (LDoN treasure) spawn with the 0x647CA8 state plays 0x91); falls
// back to row 0x4F when the model lacks it.
// FUNCTION: TITANIUM 0x0048960D
// @early-stop: budget, structural ndiff=13
char Mapper_guess::FUN_0048960d_guess(unsigned short first_guess, int unused_guess,
	int flag_guess, float scale_guess, int final_guess)
{
	if (owner_0004_guess->playerClass_0252_guess == '>' &&
		owner_0004_guess->HasPlayerState_guess(EQ_GLOBAL(int, 0x00647CA8)))
		first_guess = 0x91;

	int kind_guess = Index_guess(first_guess);
	int row_guess = 0x4f;
	int id_guess = 0;
	if (kind_guess == 0x79 - g_offset_guess && (unsigned char)flag_guess != 0)
	{
		kind_guess = 0x78 - g_offset_guess;
		flag_guess &= 0xffffff00;
	}
	if (!FUN_00488bd6_guess(kind_guess, &row_guess, &id_guess))
		return 0;

	int previous_guess = owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess;
	if (kind_guess == 0x69 - g_offset_guess && row_guess == 0x68 - g_offset_guess)
		flag_guess = (flag_guess & 0xffffff00) | 1;
	int random_guess = PickRandomVariant_guess(row_guess, id_guess);
	int* values_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[row_guess];
	int value_guess = values_guess[random_guess + id_guess * 4];
	int result_guess = FUN_004891e9_guess(row_guess, id_guess,
		Index_guess(owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess),
		owner_0004_guess->pActorInfo_01a8_guess->value_0148_guess,
		Index_guess(owner_0004_guess->pActorInfo_01a8_guess->value_0138_guess), 0, final_guess);
	if (EQ_ARRAY(int, 0x00692530)[row_guess * 9] == 1 &&
		EQ_ARRAY(int, 0x00692530)[Index_guess(owner_0004_guess->pActorInfo_01a8_guess->value_013c_guess) * 9] == 2)
	{
		FUN_00488128_guess(result_guess, row_guess, id_guess, random_guess,
			value_guess, flag_guess, scale_guess);
	}
	else
	{
		owner_0004_guess->pActorInfo_01a8_guess->value_0140_guess = row_guess + g_offset_guess;
		int next_guess = FUN_004891e9_guess(row_guess, id_guess,
			Index_guess(owner_0004_guess->pActorInfo_01a8_guess->value_013c_guess),
			owner_0004_guess->pActorInfo_01a8_guess->value_0144_guess,
			Index_guess(owner_0004_guess->pActorInfo_01a8_guess->value_0140_guess), 1, final_guess);
		if (EQ_ARRAY(int, 0x00692530)[row_guess * 9] == 2)
			FUN_00488377_guess(result_guess, next_guess, row_guess, id_guess,
				random_guess, value_guess, flag_guess, scale_guess);
		else
			FUN_00488676_guess(result_guess, next_guess, row_guess, id_guess,
				random_guess, value_guess, flag_guess, scale_guess);
	}
	PlayAnimationSound_guess(previous_guess, owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess,
		owner_0004_guess->pActorInfo_01a8_guess->value_0148_guess,
		owner_0004_guess->pActorInfo_01a8_guess->value_014c_guess);
	return 0;
}

