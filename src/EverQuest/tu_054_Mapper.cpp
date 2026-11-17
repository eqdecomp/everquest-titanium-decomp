// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 54: a hint from compare/tumap.py.
// Player animation: picks and blends animation tracks per model (keys "<anim>_<part>_<n>_<tag>"), maps models
// without their own tracks onto a shared skeleton's tag, plays the matching footstep and action sounds, and
// loads the per-model sound file. Mapper_guess is the PlayerAnimation object (owner +4 is the EQPlayer);
// animation ids index 9-int rows at 0x692530.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <stdio.h>
#include <string.h>

#define g_offset_guess EQ_GLOBAL(int, 0x0066D248)
#define g_noCode_guess EQ_GLOBAL(int, 0x0066D24C)
#define g_noCodeByte_guess EQ_GLOBAL(unsigned char, 0x0066D24C)
#define g_valueCheckDisabled_guess EQ_GLOBAL(unsigned char, 0x009858C7)

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess(void);

struct Record_guess
{
	char name_guess[0x18];
	int value_guess;
};

struct TextFileReader_guess
{
	unsigned char buf_guess[0x1000c];
	// EXTERNAL: TITANIUM 0x00576BD0 ??0TextFileReader_guess@@QAE@PBDH@Z
	TextFileReader_guess(const char* name_guess, int delim_guess);
	// EXTERNAL: TITANIUM 0x00576C50 ??1TextFileReader_guess@@QAE@XZ
	~TextFileReader_guess();
	// EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::Ok_guess
	char Ok_guess();
	// EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::Count_guess
	int Count_guess();
	// EXTERNAL: TITANIUM 0x00576CF0 TextFileReader_guess::ReadLine_guess
	void ReadLine_guess(char* buf_guess, int size_guess);
};

struct RecordTable_guess
{
	// EXTERNAL: TITANIUM 0x00447C66 RecordTable_guess::Add_guess
	void Add_guess(Record_guess*& rec_guess, unsigned hash_guess);
};

#define g_table_guess EQ_GLOBAL(RecordTable_guess, 0x00903E60)

// EXTERNAL: TITANIUM 0x0042E3B4 HashRecord_guess
unsigned __cdecl HashRecord_guess(Record_guess* rec_guess);
// EXTERNAL: TITANIUM 0x00576D20 ReadField_guess
void __cdecl ReadField_guess(char* dst_guess, int max_guess, char** cursor_guess, int delim_guess);
// EXTERNAL: TITANIUM 0x00576D80 ReadInt_guess
int __cdecl ReadInt_guess(char** cursor_guess, int delim_guess);
// EXTERNAL: TITANIUM 0x00574310 CopyField_guess
void __cdecl CopyField_guess(char* dst_guess, const char* src_guess, int size_guess);
// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* fmt_guess, ...);

struct Callback_guess
{
	virtual void Slot0_guess() = 0;
	virtual void Slot1_guess() = 0;
	virtual void Slot2_guess(int first_guess, int second_guess, int third_guess,
		float fourth_guess, int fifth_guess) = 0;
	void FUN_0048605d_guess(int first_guess, int second_guess, int third_guess,
		float fourth_guess, int fifth_guess, int unused_guess);
};

// Forwards the first five arguments to the object's virtual slot 2.
// FUNCTION: TITANIUM 0x0048605D
void Callback_guess::FUN_0048605d_guess(int first_guess, int second_guess, int third_guess,
	float fourth_guess, int fifth_guess, int unused_guess)
{
	Slot2_guess(first_guess, second_guess, third_guess, fourth_guess, fifth_guess);
}

// Animation id to table row: ids below the base offset go through the remap table at 0x693498 first; 0xFE
// (none) passes through.
// FUNCTION: TITANIUM 0x0048607C
int __stdcall FUN_0048607c_guess(int value_guess)
{
	if (value_guess == 0xfe)
	{
		value_guess = 0xfe;
	}
	else
	{
		if (value_guess < g_offset_guess)
			value_guess = EQ_ARRAY(int, 0x00693498)[value_guess];
		value_guess -= g_offset_guess;
	}
	return value_guess;
}

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
	char FUN_0048895a(int value);
	char FUN_004868a4_guess(unsigned char* value_guess, int unused_guess);
};

#define g_validationState_guess EQ_GLOBAL(ValidationState_guess*, 0x00905CE4)
#define g_validationFlag_guess EQ_GLOBAL(int, 0x00850CCC)

// True for animations 0x6E and 0x76.
// FUNCTION: TITANIUM 0x00486CFB
char __stdcall FUN_00486cfb_guess(int value_guess)
{
	return value_guess == 0x6e || value_guess == 0x76;
}

// Fallback race for animation lookups: races 11/12 use 8, 2/10 use 9, 3-7 use 1 (human), 450/451 use 440/441,
// 470 uses 420; everything else 1.
// FUNCTION: TITANIUM 0x00486D12
int __cdecl GetAnimFallbackRace_guess(int value)
{
	if (value == 0xc || value == 0xb)
		return 8;
	if (value == 0xa || value == 2)
		return 9;
	if (value == 5 || value == 6 || value == 3 || value == 7 || value == 4)
		return 1;
	if (value == 0x1c2)
		return value - 10;
	if (value == 0x1c3)
		return value - 10;
	return value == 0x1d6 ? 0x1a4 : 1;
}

// False for the races that fall back to another race's tracks (2-7, 10-12, 450, 451, 470), true otherwise.
// FUNCTION: TITANIUM 0x00486D7A
char __cdecl FUN_00486d7a_guess(int value)
{
	if (value >= 2 &&
		(value <= 7 ||
		 (value > 9 &&
		  (value <= 12 ||
		   (value > 449 && (value <= 451 || value == 470))))))
		return 0;
	return 1;
}

struct AnimationState_guess
{
	char pad_0000_guess[0x252];
	unsigned char field_0252_guess;
	char pad_0253_guess[0xd];
	int field_0260_guess;
};

struct Animator_guess
{
	char pad_0000_guess[4];
	AnimationState_guess* state_0004_guess;
	int GetAttackAnimation_guess(int value_guess, int slot_guess, int flag_guess,
		float* scale_guess, char code_guess);
};

// Animation number (0x50-0x67, or 0x87 for slot 9) for an action with item type `value_guess` in slot
// `slot_guess`; with `flag_guess` the slot decides (27 -> 0x5D, 28 -> 0x5E, else 0x51). `code_guess` 13
// picks alternates for types 0 and 1, 14 forces 0x53. A monk (class 7) with type 71 gets 0x60; an Iksar
// (race 128) turns 0x5B into 0x53 and type 21's 0x66 into 0x5B.
// FUNCTION: TITANIUM 0x00486DAD
int Animator_guess::GetAttackAnimation_guess(int value_guess, int slot_guess, int flag_guess,
	float* scale_guess, char code_guess)
{
	*scale_guess = 1.0f;
	int result_guess = 0x52;
	if (code_guess == 0x0e)
		result_guess = 0x55;
	if (slot_guess == 9)
	{
		result_guess = 0x87;
	}
	else if (flag_guess == 0)
	{
		switch (value_guess)
		{
		case 0:
			if (code_guess == 0x0d)
				result_guess = 0x51;
			else
				result_guess = 0x54;
			break;
		case 1:
			if (code_guess == 0x0d)
				result_guess = 0x50;
			else
				result_guess = 0x53;
			break;
		case 2:
			result_guess = 0x58;
			break;
		case 3:
			result_guess = 0x56;
			break;
		case 10:
			result_guess = 0x5b;
			break;
		case 0x15:
		case 0x34:
			result_guess = 0x66;
			break;
		case 0x17:
			result_guess = 0x67;
			break;
		case 0x1a:
			result_guess = 0x65;
			break;
		case 0x1c:
			result_guess = 0x5c;
			break;
		case 0x1e:
		case 0x47:
			result_guess = 0x5f;
			break;
		case 0x26:
			result_guess = 0x60;
			break;
		default:
			if (slot_guess == 0x23)
				result_guess = 0x58;
			break;
		}
	}
	else
	{
		switch (slot_guess)
		{
		case 0x1b:
			result_guess = 0x5d;
			break;
		case 0x1c:
			result_guess = 0x5e;
			break;
		default:
			result_guess = 0x51;
			break;
		}
	}
	if (value_guess == 0x47 && state_0004_guess->field_0252_guess == 7)
		result_guess = 0x60;
	else if (code_guess == 0x0e)
		result_guess = 0x53;
	if (state_0004_guess->field_0260_guess == 0x80)
	{
		if (result_guess == 0x5b)
			result_guess = 0x53;
		else if (result_guess == 0x66 && value_guess == 0x15)
			result_guess = 0x5b;
	}
	return result_guess;
}

// Track filter: drops head, arm and neck tracks and every chest track except CHEST_CHEST01.
// FUNCTION: TITANIUM 0x00486ECB
int __cdecl FUN_00486ecb_guess(char* name_guess)
{
	if (strncmp(name_guess, "CHEST", 5) == 0)
		return strcmp(name_guess, "CHEST_CHEST01") == 0;
	if (strncmp(name_guess, "HEAD", 4) != 0 &&
		strncmp(name_guess, "ARM", 3) != 0 &&
		strncmp(name_guess, "NECK", 4) != 0)
		return true;
	return false;
}

struct RuleData_guess
{
	char pad_000_guess[0x120];
	char argument_guess;
	char pad_121_guess[0x123];
	unsigned char mode_guess;
};

struct FirstPredicate_guess
{
	// EXTERNAL: TITANIUM 0x004303A6 FirstPredicate_guess::Check_guess
	char Check_guess(char* value_guess);
};

struct SecondPredicate_guess
{
	// EXTERNAL: TITANIUM 0x00485DF1 SecondPredicate_guess::Check_guess
	char Check_guess(char* value_guess);
};

struct RuleObject_guess
{
	int unknown_guess;
	RuleData_guess* data_guess;
	char FUN_004872d8_guess();
};

#define g_ruleFlags_guess EQ_GLOBAL(unsigned char, 0x0098583C)
#define g_firstPredicate_guess EQ_GLOBAL(FirstPredicate_guess, 0x0091D708)
#define g_secondPredicate_guess EQ_GLOBAL(SecondPredicate_guess, 0x00904248)
#define g_ruleData_guess EQ_GLOBAL(RuleData_guess*, 0x00905CE4)

// ActorParticleCastFilter ([Defaults], 0x0098583C, default 0x18): true when spell particles of spawn
// `data_guess` are shown. Bit 0x10 shows NPCs (bits 0x18 together show everyone), 0x08 all players, 0x04
// raid members (0x004303A6) and group, 0x02 group only (0x00485DF1); other spawn types and our own spawn
// always pass.
// FUNCTION: TITANIUM 0x004872D8
// @early-stop: budget, structural ndiff=39
char RuleObject_guess::FUN_004872d8_guess()
{
	unsigned char flags_guess = g_ruleFlags_guess;
	char result_guess = 0;
	char bit8_guess = 0;
	char bit16_guess = 0;
	char firstCheck_guess = 0;
	char anyCheck_guess = 0;

	if ((flags_guess & 0x10) != 0)
		bit16_guess = 1;
	if ((flags_guess & 0x8) != 0)
	{
		bit8_guess = 1;
		firstCheck_guess = 1;
		anyCheck_guess = 1;
		if (bit16_guess != 0)
			result_guess = 1;
	}
	else if ((flags_guess & 0x4) != 0)
	{
		firstCheck_guess = 1;
		anyCheck_guess = 1;
	}
	else if ((flags_guess & 0x2) != 0)
		anyCheck_guess = 1;

	if (result_guess == 0)
	{
		if (data_guess->mode_guess == 1)
		{
			if (bit16_guess != 0)
				result_guess = 1;
		}
		else if (data_guess->mode_guess != 0)
			result_guess = 1;
		else if (bit8_guess != 0)
			result_guess = 1;
		else if (firstCheck_guess != 0 &&
			g_firstPredicate_guess.Check_guess(&data_guess->argument_guess) != 0)
			result_guess = 1;
		else if (anyCheck_guess != 0 &&
			g_secondPredicate_guess.Check_guess(&data_guess->argument_guess) != 0)
			result_guess = 1;
		else if (data_guess == g_ruleData_guess)
			result_guess = 1;
	}

	return result_guess;
}

// Loads the '^'-separated per-model sound file (model, animation, sound...) and logs "Player Animations
// loaded %d specific sounds from file %s."
// FUNCTION: TITANIUM 0x00487FF0
// @early-stop: budget, structural ndiff=33
void __cdecl LoadAnimationSounds_guess(const char* file_guess)
{
	char line_guess[0x1000];
	char field_guess[0x100];
	char* cursor_guess;
	Record_guess* rec_guess;
	int count_guess = 0;
	TextFileReader_guess* reader_guess = 0;
	reader_guess = new TextFileReader_guess(file_guess, '^');
	if (reader_guess->Ok_guess())
	{
		while (reader_guess->Count_guess() > 0)
		{
			reader_guess->ReadLine_guess(line_guess, 0x1000);
			rec_guess = new Record_guess;
			cursor_guess = line_guess;
			ReadField_guess(field_guess, 0xff, &cursor_guess, '^');
			CopyField_guess(rec_guess->name_guess, field_guess, 0x18);
			rec_guess->value_guess = ReadInt_guess(&cursor_guess, '^');
			g_table_guess.Add_guess(rec_guess, HashRecord_guess(rec_guess));
			count_guess++;
		}
	}
	if (reader_guess != 0)
		delete reader_guess;
	Log_guess("Player Animations loaded %d specific sounds from file %s.", count_guess, file_guess);
}

// Model-code literals TKX, ELX, GNX, DWX, LIX, FAX are placeholders: their text is not in the context.
// Shared-skeleton tag for model `name_guess` ("ERO", "SIR", "HAG", "ABH" use ELF, and so on) written to
// `out_guess`; true only for humanoid models put on a player-race skeleton.
// FUNCTION: TITANIUM 0x00487387
// @early-stop: budget, structural ndiff=547
char __stdcall GetSharedSkeletonTag_guess(char* name_guess, char* out_guess, char flag_guess)
{
	char result_guess = 0;
	strcpy(out_guess, name_guess);
	// The first nine groups are humanoid models that borrow a player race's skeleton (ELF, DWM, EL, DW, OGF,
	// ELM, HU); they return true. TRK in between is a creature group and returns false.
	if (_strnicmp(name_guess, "ERO", 3) == 0 || _strnicmp(name_guess, "SIR", 3) == 0 ||
		_strnicmp(name_guess, "HAG", 3) == 0 || _strnicmp(name_guess, "ABH", 3) == 0)
	{
		out_guess[2] = 'F';
		result_guess = 1;
		out_guess[0] = 'E';
		out_guess[1] = 'L';
	}
	else if (_strnicmp(name_guess, "BRI", 3) == 0 || _strnicmp(name_guess, "COK", 3) == 0)
	{
		out_guess[0] = 'D';
		out_guess[1] = 'W';
		out_guess[2] = 'M';
		result_guess = 1;
	}
	else if (_strnicmp(name_guess, "DR2", 3) == 0 || _strnicmp(name_guess, "CCD", 3) == 0 ||
		_strnicmp(name_guess, "BWD", 3) == 0 || _strnicmp(name_guess, "PRI", 3) == 0)
	{
		out_guess[0] = 'T';
		out_guess[1] = 'R';
		out_guess[2] = 'K';
	}
	else if (_strnicmp(name_guess, "DA", 2) == 0 || _strnicmp(name_guess, "HI", 2) == 0 ||
		_strnicmp(name_guess, "HA", 2) == 0 || _strnicmp(name_guess, "HH", 2) == 0 ||
		_strnicmp(name_guess, "QC", 2) == 0 || _strnicmp(name_guess, "NG", 2) == 0 ||
		_strnicmp(name_guess, "FP", 2) == 0 || _strnicmp(name_guess, "EG", 2) == 0 ||
		_strnicmp(name_guess, "BR", 2) == 0 || _strnicmp(name_guess, "HL", 2) == 0 ||
		_strnicmp(name_guess, "ZO", 2) == 0 || _strnicmp(name_guess, "FEM", 3) == 0 ||
		_strnicmp(name_guess, "FEF", 3) == 0 || _strnicmp(name_guess, "IV", 2) == 0 ||
		_strnicmp(name_guess, "GHM", 3) == 0 || _strnicmp(name_guess, "GHF", 3) == 0 ||
		_strnicmp(name_guess, "GF", 2) == 0 || _strnicmp(name_guess, "GE", 2) == 0)
	{
		result_guess = 1;
		out_guess[0] = 'E';
		out_guess[1] = 'L';
	}
	// Humans (HU, ER), barbarians (BA) and skeletons (SKE) depend on `flag_guess`: with it they use the human
	// set, without it the elf one (BA then keeps its own).
	else if (_strnicmp(name_guess, "HU", 2) == 0 || _strnicmp(name_guess, "ER", 2) == 0)
	{
		if (flag_guess != 0)
		{
			result_guess = 1;
			out_guess[0] = 'H';
			out_guess[1] = 'U';
		}
		else
		{
			result_guess = 1;
			out_guess[0] = 'E';
			out_guess[1] = 'L';
		}
	}
	else if (_strnicmp(name_guess, "BA", 2) == 0)
	{
		if (flag_guess == 0)
		{
			result_guess = 1;
			out_guess[0] = 'E';
			out_guess[1] = 'L';
		}
	}
	else if (_strnicmp(name_guess, "GNM", 3) == 0 || _strnicmp(name_guess, "GNF", 3) == 0 ||
		_strnicmp(name_guess, "CLM", 3) == 0 || _strnicmp(name_guess, "CLF", 3) == 0 ||
		_strnicmp(name_guess, "HO", 2) == 0 || _strnicmp(name_guess, "RIM", 3) == 0 ||
		_strnicmp(name_guess, "RIF", 3) == 0 || _strnicmp(name_guess, "KAM", 3) == 0 ||
		_strnicmp(name_guess, "KAF", 3) == 0 || _strnicmp(name_guess, "KA", 2) == 0 ||
		_strnicmp(name_guess, "GD", 2) == 0 || _strnicmp(name_guess, "COM", 3) == 0 ||
		_strnicmp(name_guess, "COF", 3) == 0)
	{
		out_guess[0] = 'D';
		out_guess[1] = 'W';
		result_guess = 1;
	}
	else if (_strnicmp(name_guess, "TRM", 3) == 0 || _strnicmp(name_guess, "OG", 2) == 0 ||
		_strnicmp(name_guess, "TRF", 3) == 0 || _strnicmp(name_guess, "GRM", 3) == 0 ||
		_strnicmp(name_guess, "GRF", 3) == 0 || _strnicmp(name_guess, "OKM", 3) == 0 ||
		_strnicmp(name_guess, "OKF", 3) == 0)
	{
		out_guess[0] = 'O';
		out_guess[1] = 'G';
		out_guess[2] = 'F';
		result_guess = 1;
	}
	else if (_strnicmp(name_guess, "BGM", 3) == 0 || _strnicmp(name_guess, "TRI", 3) == 0 ||
		_strnicmp(name_guess, "ENA", 3) == 0)
	{
		out_guess[2] = 'M';
		result_guess = 1;
		out_guess[0] = 'E';
		out_guess[1] = 'L';
	}
	else if (_strnicmp(name_guess, "SKE", 3) == 0)
	{
		result_guess = 1;
		out_guess[2] = 'M';
		if (flag_guess != 0)
		{
			out_guess[0] = 'H';
			out_guess[1] = 'U';
		}
		else
		{
			out_guess[0] = 'E';
			out_guess[1] = 'L';
		}
	}
	// From here creature models borrow another creature's tracks (GNN, GOB, FRO, LIM, ...): the name is changed
	// but the result stays false, except the Iksar group (IKM).
	else if (_strnicmp(name_guess, "MIN", 3) == 0 || _strnicmp(name_guess, "CPM", 3) == 0 ||
		_strnicmp(name_guess, "YAK", 3) == 0 || _strnicmp(name_guess, "FAN", 3) == 0)
	{
		out_guess[1] = 'N';
		out_guess[0] = 'G';
		out_guess[2] = 'N';
	}
	else if (_strnicmp(name_guess, "GHU", 3) == 0)
	{
		out_guess[0] = 'G';
		out_guess[1] = 'O';
		out_guess[2] = 'B';
	}
	else if (_strnicmp(name_guess, "FRG", 3) == 0)
	{
		out_guess[0] = 'F';
		out_guess[1] = 'R';
		out_guess[2] = 'O';
	}
	else if (_strnicmp(name_guess, "LIF", 3) == 0 || _strnicmp(name_guess, "PUM", 3) == 0 ||
		_strnicmp(name_guess, "TIG", 3) == 0 || _strnicmp(name_guess, "STC", 3) == 0 ||
		_strnicmp(name_guess, "MTC", 3) == 0)
	{
		out_guess[0] = 'L';
		out_guess[1] = 'I';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "CPF", 3) == 0)
	{
		out_guess[0] = 'C';
		out_guess[1] = 'P';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "SNE", 3) == 0)
	{
		out_guess[1] = 'N';
		out_guess[0] = 'S';
		out_guess[2] = 'A';
	}
	else if (_strnicmp(name_guess, "PIF", 3) == 0)
	{
		out_guess[0] = 'F';
		out_guess[1] = 'A';
		out_guess[2] = 'F';
	}
	else if (_strnicmp(name_guess, "SKU", 3) == 0 || _strnicmp(name_guess, "ARM", 3) == 0)
	{
		out_guess[0] = 'R';
		out_guess[1] = 'A';
		out_guess[2] = 'T';
	}
	else if (_strnicmp(name_guess, "GRI", 3) == 0 || _strnicmp(name_guess, "SPH", 3) == 0 ||
		_strnicmp(name_guess, "FMO", 3) == 0)
	{
		out_guess[0] = 'D';
		out_guess[1] = 'R';
		out_guess[2] = 'K';
	}
	else if (_strnicmp(name_guess, "GOL", 3) == 0 || _strnicmp(name_guess, "GOM", 3) == 0)
	{
		out_guess[0] = 'G';
		out_guess[1] = 'I';
		out_guess[2] = 'A';
	}
	else if (_strnicmp(name_guess, "WO", 2) == 0)
	{
		out_guess[1] = 'O';
		out_guess[0] = 'W';
		out_guess[2] = 'L';
	}
	else if (_strnicmp(name_guess, "KOB", 3) == 0)
	{
		out_guess[0] = 'W';
		out_guess[1] = 'E';
		out_guess[2] = 'R';
	}
	else if (_strnicmp(name_guess, "IMP", 3) == 0 || _strnicmp(name_guess, "GAM", 3) == 0)
	{
		out_guess[0] = 'G';
		out_guess[1] = 'A';
		out_guess[2] = 'R';
	}
	else if (_strnicmp(name_guess, "BET", 3) == 0 || _strnicmp(name_guess, "SPM", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'P';
		out_guess[2] = 'I';
	}
	else if (_strnicmp(name_guess, "ICM", 3) == 0 || _strnicmp(name_guess, "ICN", 3) == 0 ||
		_strnicmp(name_guess, "ICF", 3) == 0 || _strnicmp(name_guess, "IKS", 3) == 0 ||
		_strnicmp(name_guess, "IKF", 3) == 0)
	{
		out_guess[0] = 'I';
		out_guess[1] = 'K';
		out_guess[2] = 'M';
		result_guess = 1;
	}
	else if (_strnicmp(name_guess, "BGG", 3) == 0)
	{
		out_guess[0] = 'K';
		out_guess[1] = 'G';
		out_guess[2] = 'O';
	}
	else if (_strnicmp(name_guess, "SSK", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'R';
		out_guess[2] = 'W';
	}
	else if (_strnicmp(name_guess, "IKH", 3) == 0)
	{
		out_guess[0] = 'R';
		out_guess[1] = 'E';
		out_guess[2] = 'A';
	}
	else if (_strnicmp(name_guess, "WUR", 3) == 0 || _strnicmp(name_guess, "GDR", 3) == 0)
	{
		out_guess[0] = 'D';
		out_guess[1] = 'R';
		out_guess[2] = 'A';
	}
	else if (_strnicmp(name_guess, "BTM", 3) == 0)
	{
		out_guess[0] = 'R';
		out_guess[1] = 'H';
		out_guess[2] = 'I';
	}
	else if (_strnicmp(name_guess, "SDE", 3) == 0)
	{
		out_guess[0] = 'D';
		out_guess[1] = 'M';
		out_guess[2] = 'L';
	}
	else if (_strnicmp(name_guess, "TOT", 3) == 0)
	{
		out_guess[1] = 'C';
		out_guess[0] = 'S';
		out_guess[2] = 'A';
	}
	else if (_strnicmp(name_guess, "SPC", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'P';
		out_guess[2] = 'E';
	}
	else if (_strnicmp(name_guess, "STG", 3) == 0 || _strnicmp(name_guess, "STM", 3) == 0)
	{
		out_guess[0] = 'F';
		out_guess[1] = 'S';
		out_guess[2] = 'G';
	}
	else if (_strnicmp(name_guess, "VRF", 3) == 0)
	{
		out_guess[0] = 'V';
		out_guess[1] = 'R';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "AVM", 3) == 0)
	{
		out_guess[0] = 'A';
		out_guess[1] = 'V';
		out_guess[2] = 'I';
	}
	else if (_strnicmp(name_guess, "TEM", 3) == 0)
	{
		out_guess[0] = 'T';
		out_guess[1] = 'E';
		out_guess[2] = 'N';
	}
	else if (_strnicmp(name_guess, "WAM", 3) == 0 || _strnicmp(name_guess, "WAF", 3) == 0)
	{
		out_guess[1] = 'A';
		out_guess[0] = 'W';
		out_guess[2] = 'L';
	}
	else if (_strnicmp(name_guess, "SHN", 3) == 0 || _strnicmp(name_guess, "SHF", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'H';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "GMM", 3) == 0)
	{
		out_guess[1] = 'M';
		out_guess[0] = 'G';
		out_guess[2] = 'N';
	}
	else if (_strnicmp(name_guess, "WEL", 3) == 0 || _strnicmp(name_guess, "FEL", 3) == 0)
	{
		out_guess[0] = 'A';
		out_guess[1] = 'E';
		out_guess[2] = 'L';
	}
	else if (_strnicmp(name_guess, "SDF", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'D';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "KES", 3) == 0 || _strnicmp(name_guess, "VSG", 3) == 0 ||
		_strnicmp(name_guess, "VSK", 3) == 0)
	{
		out_guess[0] = 'K';
		out_guess[1] = 'E';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "NYD", 3) == 0)
	{
		out_guess[0] = 'N';
		out_guess[1] = 'Y';
		out_guess[2] = 'M';
	}
	else if (_strnicmp(name_guess, "SPL", 3) == 0)
	{
		out_guess[0] = 'S';
		out_guess[1] = 'P';
		out_guess[2] = 'D';
	}
	else if (_strnicmp(name_guess, "FRF", 3) == 0)
	{
		out_guess[0] = 'F';
		out_guess[1] = 'R';
		out_guess[2] = 'M';
	}
	return result_guess;
}

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
	// EXTERNAL: TITANIUM 0x0047BFD0 Owner_guess::Check_guess
	bool Check_guess();
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

struct Display_guess
{
	unsigned char pad_0000_guess[5];
	unsigned char flag_0005_guess;
	unsigned char pad_0006_guess[0x148 - 0x6];
	int tick_0148_guess;
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)
#define g_player_guess EQ_GLOBAL(Owner_guess*, 0x00905CE4)

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
	void FUN_00488377_guess(int first_kind_guess, int second_kind_guess, int index_guess,
		int value4_guess, int value5_guess, int value6_guess, int value7_guess, float value8_guess);
	void FUN_00488128_guess(int kind_guess, int index_guess, int value4_guess,
		int value5_guess, int value6_guess, int value7_guess, float value8_guess);
	void FUN_00488676_guess(int kind_guess, int count_guess, int index_guess, int value5_guess,
		int value6_guess, int value7_guess, int value8_guess, float value9_guess);
	void UpdateMovementAnimation_guess();
	char FUN_00486f3d_guess();
	void FUN_00486f60_guess();
	void UpdateIdleAnimation_guess(int value_guess);
	void UpdateAnimation_guess(int value_guess);
	char FUN_00488bd6_guess(int table_guess, int* first_guess, int* second_guess);
	// EXTERNAL: TITANIUM 0x00485FD6 Mapper_guess::SelectMode_guess
	int SelectMode_guess(int key_guess);
	// EXTERNAL: TITANIUM 0x00485F57 Mapper_guess::RemapAnimationKey_guess
	int RemapAnimationKey_guess(int key_guess, int record_guess);
	// EXTERNAL: TITANIUM 0x00485E69 Mapper_guess::PickRandomVariant_guess
	int PickRandomVariant_guess(int table_guess, int record_guess);
	void PlayAnimationVariant_guess(int id_guess, int unused_guess, int kind_guess, float scale_guess);
	void PlayAnimation_guess(int kind_guess, int flag_guess, int value_guess,
		float scale_guess, int zero_guess);
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

struct Timer_guess
{
	virtual void Slot00_guess() = 0;
	virtual void Slot01_guess() = 0;
	virtual void Slot02_guess() = 0;
	virtual void Slot03_guess() = 0;
	virtual float Slot04_guess(float value_guess) = 0;
};

#define g_timer_guess EQ_GLOBAL(Timer_guess*, 0x0099E374)
#define g_noneKind_guess EQ_GLOBAL(int, 0x0066D24C)

// EXTERNAL: TITANIUM 0x00610884 FUN_00610884_guess
double __cdecl FUN_00610884_guess(double value_guess);
// EXTERNAL: TITANIUM 0x0047937C FUN_0047937c_guess
char __cdecl FUN_0047937c_guess(unsigned int value_guess);

// Animation choice while moving (probably walk, run, swim or fly from the speed and environment).
// FUNCTION: TITANIUM 0x004868EE
// @early-stop: budget, structural ndiff=277
void Mapper_guess::UpdateMovementAnimation_guess()
{
	Owner_guess* owner_guess = owner_0004_guess;
	State_guess* state_guess = owner_guess->pActorInfo_01a8_guess;
	Vec_guess* vector_guess = &owner_guess->vec_0030_guess;
	unsigned char kind_guess = g_noneKind_guess;
	char first_guess = 1;
	char second_guess = 0;
	char third_guess = 0;
	float scale_guess = 1.0f;
	state_guess->value_0130_guess = 0;

	if (state_guess->mode_0150_guess == 6)
	{
		if (vector_guess->coordinates_000c_guess.z_guess != 0.0f)
		{
			if (vector_guess->coordinates_000c_guess.z_guess < 0.0f)
				second_guess = 1;
			kind_guess = 0x7e;
			third_guess = 1;
		}
	}
	else if (vector_guess->coordinates_000c_guess.x_guess >= 0.001f ||
		vector_guess->coordinates_000c_guess.x_guess <= -0.001f ||
		vector_guess->coordinates_000c_guess.y_guess >= 0.001f ||
		vector_guess->coordinates_000c_guess.y_guess <= -0.001f)
	{
		float timer_guess = g_timer_guess->Slot04_guess(
			vector_guess->coordinates_000c_guess.x_guess * vector_guess->coordinates_000c_guess.x_guess +
			vector_guess->coordinates_000c_guess.y_guess * vector_guess->coordinates_000c_guess.y_guess);
		first_guess = 0;
		third_guess = 1;
		scale_guess = timer_guess * 0.5f + 1.0f;
		if (state_guess->level_00ad_guess >= 5)
		{
			kind_guess = 0x80;
			scale_guess = (float)(FUN_00610884_guess(
				vector_guess->coordinates_000c_guess.x_guess * vector_guess->coordinates_000c_guess.x_guess +
				(vector_guess->coordinates_000c_guess.y_guess * vector_guess->coordinates_000c_guess.y_guess +
				 vector_guess->coordinates_000c_guess.z_guess * vector_guess->coordinates_000c_guess.z_guess)) *
				2.7777777f / state_guess->value_00c4_guess);
		}
		else
		{
			if (state_guess->level_00ae_guess < 5)
			{
				float current_guess;
				if (owner_guess->Check_guess())
				{
					float difference_guess = owner_guess->runSpeed_0230_guess - owner_guess->Calc_guess();
					difference_guess *= 0.5f;
					current_guess = owner_guess->Calc_guess() + difference_guess;
				}
				else if (owner_guess->type_0244_guess == 1 &&
					FUN_0047937c_guess((unsigned int)owner_guess->race_0260_guess))
					current_guess = owner_guess->Calc_guess() * 1.4f;
				else
					current_guess = owner_guess->Calc_guess();

				kind_guess = owner_guess->standState_0251_guess == 'o' ? 0x7d : 0x68;
				if (vector_guess->coordinates_000c_guess.z_guess < state_guess->value_00bc_guess)
				{
					if (vector_guess->coordinates_000c_guess.z_guess < -3.2f)
					{
						kind_guess = 0x97;
						third_guess = 1;
					}
					else if (current_guess < vector_guess->coordinates_000c_guess.w_guess)
						kind_guess = 0x6a;
					else if (vector_guess->coordinates_000c_guess.z_guess != 0.0f)
						third_guess = 0;
				}
				else
				{
					kind_guess = 0x7b;
					first_guess = 1;
					scale_guess = 1.0f;
				}
			}
			else if (state_guess->currentAnimation_0134_guess != 0x7f && state_guess->currentAnimation_0134_guess != 0x80)
			{
				float current_guess;
				if (owner_guess->Check_guess())
				{
					float difference_guess = owner_guess->runSpeed_0230_guess - owner_guess->Calc_guess();
					difference_guess *= 0.5f;
					current_guess = owner_guess->Calc_guess() + difference_guess;
				}
				else
					current_guess = owner_guess->Calc_guess();
				kind_guess = current_guess < vector_guess->coordinates_000c_guess.w_guess ? 0x6a : 0x68;
			}

		{
			if (vector_guess->coordinates_000c_guess.w_guess < 0.0f)
			{
				if (kind_guess == 0x68)
					kind_guess = 0x69;
				else if (state_guess->currentAnimation_0134_guess != 0x80 && state_guess->currentAnimation_0134_guess != 0x7f)
					second_guess = 1;
			}
			if (kind_guess == 0x68 || kind_guess == 0x69)
				scale_guess = (float)(FUN_00610884_guess(
					vector_guess->coordinates_000c_guess.x_guess * vector_guess->coordinates_000c_guess.x_guess +
					(vector_guess->coordinates_000c_guess.y_guess * vector_guess->coordinates_000c_guess.y_guess +
					 vector_guess->coordinates_000c_guess.z_guess * vector_guess->coordinates_000c_guess.z_guess)) *
					1.4492754f / state_guess->value_00c4_guess);
			else if (kind_guess == 0x6a)
				scale_guess = (float)(FUN_00610884_guess(
					vector_guess->coordinates_000c_guess.x_guess * vector_guess->coordinates_000c_guess.x_guess +
					(vector_guess->coordinates_000c_guess.y_guess * vector_guess->coordinates_000c_guess.y_guess +
					 vector_guess->coordinates_000c_guess.z_guess * vector_guess->coordinates_000c_guess.z_guess)) *
					0.6711409f / state_guess->value_00c4_guess);
		}
	}
	}
	else
	{
		if (state_guess->level_00ad_guess >= 5)
			kind_guess = 0x7f;
		else if (state_guess->level_00ae_guess < 5)
		{
			kind_guess = 0x6e;
			float half_guess = state_guess->value_00bc_guess * 0.5f;
			first_guess = 0;
			third_guess = 1;
			if (half_guess <= vector_guess->coordinates_000c_guess.z_guess)
			{
				kind_guess = 0x7c;
				scale_guess = 1.0f;
			}
			else if (vector_guess->coordinates_000c_guess.z_guess < -2.25f)
				kind_guess = 0x97;
		}
	}

	if (kind_guess != g_noneKind_guess)
		Slot02_guess(kind_guess, first_guess, second_guess, scale_guess, third_guess);
}

#define g_pulseGate_guess EQ_GLOBAL(int, 0x00923C80)
#define g_pulseMask_guess EQ_GLOBAL(int, 0x00647CBC)

// EXTERNAL: TITANIUM 0x0046D655 GetCurrentTime_guess
unsigned int __cdecl GetCurrentTime_guess();
// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int first_guess, int last_guess);

// True while animation 0x7B or 0x7C plays.
// FUNCTION: TITANIUM 0x00486F3D
char Mapper_guess::FUN_00486f3d_guess()
{
	State_guess* state_guess = owner_0004_guess->pActorInfo_01a8_guess;
	if (state_guess != 0 &&
		(state_guess->currentAnimation_0134_guess == 0x7c || state_guess->currentAnimation_0134_guess == 0x7b))
		return 1;
	return 0;
}

// Footstep and movement sounds for the current animation, with a random roll; skipped for race 127.
// FUNCTION: TITANIUM 0x00486F60
// @early-stop: budget, structural ndiff=117
void Mapper_guess::FUN_00486f60_guess()
{
	char charge_guess = 1;
	char notify_guess = 1;
	if (owner_0004_guess->race_0260_guess == 0x7f)
		return;
	char busy_guess = owner_0004_guess->pActorInfo_01a8_guess->Forward_guess();
	if (busy_guess != 0 ? owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess == 0x92
		: owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess == 0x10)
		return;
	if (g_pulseGate_guess == 0 && owner_0004_guess->race_0260_guess != 0x1a1)
		charge_guess = false;
	unsigned char rate_guess = owner_0004_guess->type_0244_guess;
	if (rate_guess > 1)
	{
		notify_guess = false;
		charge_guess = false;
	}
	int kind_guess = owner_0004_guess->race_0260_guess;
	if (kind_guess == 0xd8)
	{
		notify_guess = false;
		charge_guess = false;
	}
	if (rate_guess == 1)
	{
		int sub_guess = owner_0004_guess->bodyType_0270_guess;
		if (sub_guess == 3 || sub_guess == 8 || sub_guess == 0xc || sub_guess == 0x18 || sub_guess == 0x1b
			|| sub_guess == 0x19 || sub_guess == 5 || sub_guess == 0x14 || sub_guess == 6 || sub_guess == 0x1c)
		{
			notify_guess = false;
			charge_guess = false;
		}
		else if (kind_guess <= 0xf6)
		{
			if (kind_guess == 0xf6 || kind_guess == 0x3d || kind_guess == 0x44 || kind_guess == 0x74
				|| kind_guess == 0x91 || kind_guess == 0xd5)
			{
				notify_guess = false;
				charge_guess = false;
			}
		}
		else if (kind_guess == 0x103 || kind_guess == 0x105 || kind_guess == 0x10f || kind_guess == 0x12e
			|| kind_guess == 0x13b)
		{
			notify_guess = false;
			charge_guess = false;
		}
	}
	else if (rate_guess == 0 && owner_0004_guess->LegalPlayerRace_guess(kind_guess) == 0)
	{
		int code_guess = owner_0004_guess->race_0260_guess;
		if (code_guess <= 0x8f)
		{
			if (code_guess >= 0x8e || code_guess == 0x14 || code_guess == 0x1b || code_guess == 0x3c
				|| code_guess == 0x52 || code_guess == 0x55 || code_guess == 0x78)
			{
				notify_guess = false;
				charge_guess = false;
			}
		}
		else if (code_guess == 0xb2 || (code_guess > 0xd0 && (code_guess <= 0xd4
			|| (code_guess > 0x15c && (code_guess <= 0x15e || code_guess == 0x16f || code_guess == 0x173)))))
		{
			notify_guess = false;
			charge_guess = false;
		}
	}
	if (!charge_guess)
	{
		if (owner_0004_guess->pActorInfo_01a8_guess->value_01a8_guess != 0)
		{
			State_guess* state_guess = owner_0004_guess->pActorInfo_01a8_guess;
			charge_guess = true;
			unsigned int elapsed_guess = GetCurrentTime_guess() - state_guess->lastUpdateTime_01ac_guess;
			if (state_guess->value_01a8_guess < elapsed_guess)
				owner_0004_guess->pActorInfo_01a8_guess->value_01a8_guess = 0;
			else
				owner_0004_guess->pActorInfo_01a8_guess->value_01a8_guess -= elapsed_guess;
		}
	}
	unsigned int now_guess = GetCurrentTime_guess();
	int roll_guess = RandomRange_guess(1, 100);
	if (notify_guess && owner_0004_guess->pActorInfo_01a8_guess->headEnvironment_00ac_guess > 4)
	{
		State_guess* state_guess = owner_0004_guess->pActorInfo_01a8_guess;
		if (now_guess - state_guess->value_01a0_guess > 5000 && roll_guess < 3 && state_guess->value_0fd4_guess != 0)
		{
			state_guess->manager_0000_guess->Slot105_guess(0x46, state_guess->value_0fd4_guess, 0);
			owner_0004_guess->pActorInfo_01a8_guess->value_01a0_guess = now_guess;
		}
	}
	else
	{
		owner_0004_guess->pActorInfo_01a8_guess->value_01a0_guess = now_guess;
		if (charge_guess)
		{
			State_guess* state_guess = owner_0004_guess->pActorInfo_01a8_guess;
			if (now_guess - state_guess->value_01a4_guess > 0x9c4 && roll_guess < 0x15 && state_guess->value_0fd4_guess != 0)
			{
				state_guess->manager_0000_guess->Slot105_guess(0x41, state_guess->value_0fd4_guess, 0);
				owner_0004_guess->pActorInfo_01a8_guess->value_01a4_guess = now_guess;
			}
		}
	}
	if (owner_0004_guess->HasPlayerState_guess(g_pulseMask_guess))
	{
		if (flag_0008_guess == 0)
		{
			flag_0008_guess = 1;
			int handle_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0fb8_guess;
			if (handle_guess != 0)
			{
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot105_guess(0x3a, handle_guess, 0);
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot105_guess(0x3c, handle_guess, 0);
			}
		}
	}
	else if (flag_0008_guess != 0)
	{
		flag_0008_guess = 0;
	}
	owner_0004_guess->pActorInfo_01a8_guess->lastUpdateTime_01ac_guess = GetCurrentTime_guess();
}

// Plays animation `index_guess` on the two body layers (rows of 36 bytes at 0x00692548; track tag from
// 0x008FFBC8 + 0x00693310[index]): `second_kind` drives layer 1 (ActorInfo +0x13C), `first_kind` layer 0
// (+0x134). A zero `second_kind` does nothing at all. Kind 2 starts it, 3 only passes value8/value7 to the
// running layer, any other nonzero kind just records the index (+0x140 or +0x138). On a layer-0 start, row
// +8 = 3 skips part track 3 and = 2 skips part track 4.
// FUNCTION: TITANIUM 0x00488377
void Mapper_guess::FUN_00488377_guess(int first_kind_guess, int second_kind_guess, int index_guess,
	int value4_guess, int value5_guess, int value6_guess, int value7_guess, float value8_guess)
{
	if (second_kind_guess == 0)
		return;
	Layer_guess* first_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(0);
	Layer_guess* second_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(1);
	float value_guess = GetAnimBlendTime_guess(index_guess,
		Index_guess(owner_0004_guess->pActorInfo_01a8_guess->value_013c_guess));
	char ready_guess = Ready_guess();
	if (second_kind_guess == 2)
	{
		owner_0004_guess->pActorInfo_01a8_guess->value_013c_guess = index_guess + g_offset_guess;
		owner_0004_guess->pActorInfo_01a8_guess->value_0144_guess = value4_guess;
		if (second_guess != 0)
		{
			second_guess->Slot02_guess(value6_guess, value8_guess, value7_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
			second_guess->Slot10_guess();
		}
		if (ready_guess != 0)
		{
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot103_guess(index_guess,
				value4_guess, value5_guess, second_guess, 0);
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(5, index_guess);
		}
	}
	else if (second_kind_guess == 3)
	{
		second_guess->Slot00_guess(value8_guess, value7_guess);
	}
	else
	{
		owner_0004_guess->pActorInfo_01a8_guess->value_0140_guess = index_guess + g_offset_guess;
	}
	value_guess = GetAnimBlendTime_guess(index_guess,
		Index_guess(owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess));
	if (first_kind_guess != 0)
	{
		if (first_kind_guess == 2)
		{
			owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess = index_guess + g_offset_guess;
			owner_0004_guess->pActorInfo_01a8_guess->value_0148_guess = value4_guess;
			owner_0004_guess->pActorInfo_01a8_guess->value_014c_guess = value5_guess;
			if (first_guess != 0)
			{
				first_guess->Slot02_guess(value6_guess, value8_guess, value7_guess,
					EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
				first_guess->Slot10_guess();
				first_guess->Slot11_guess((int)second_guess);
			}
			if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 3)
			{
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(3,
					EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
					EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value8_guess, value7_guess,
					EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
				if (ready_guess != 0)
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(3, index_guess);
			}
			if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 2)
			{
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(4,
					EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
					EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value8_guess, value7_guess,
					EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
				if (ready_guess != 0)
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(4, index_guess);
			}
		}
		else if (first_kind_guess == 3)
		{
			first_guess->Slot00_guess(value8_guess, value7_guess);
		}
		else
		{
			owner_0004_guess->pActorInfo_01a8_guess->value_0138_guess = index_guess + g_offset_guess;
		}
	}
}

// Layer 0 only (see 0x00488377): kind 3 updates the running layer; kinds 2 (start) and others (record in
// +0x138) need the current layer-0 animation's entry at 0x00692530 to be nonzero.
// FUNCTION: TITANIUM 0x00488128
void Mapper_guess::FUN_00488128_guess(int kind_guess, int index_guess, int value4_guess,
	int value5_guess, int value6_guess, int value7_guess, float value8_guess)
{
	int which_guess;
	Layer_guess* layer_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(0);
	which_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(1);
	if (layer_guess != 0 && kind_guess != 0)
	{
		if (kind_guess == 3)
		{
			layer_guess->Slot00_guess(value8_guess, value7_guess);
		}
		else if (EQ_ARRAY(int, 0x00692530)[Index_guess(owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess) * 9] != 0)
		{
			float value_guess = GetAnimBlendTime_guess(index_guess,
				Index_guess(owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess));
			if (kind_guess == 2)
			{
				owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess = index_guess + g_offset_guess;
				owner_0004_guess->pActorInfo_01a8_guess->value_0148_guess = value4_guess;
				owner_0004_guess->pActorInfo_01a8_guess->value_014c_guess = value5_guess;
				layer_guess->Slot02_guess(value6_guess, value8_guess, value7_guess,
					EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
				layer_guess->Slot11_guess(which_guess);
				char ready_guess = Ready_guess();
				if (ready_guess != 0)
				{
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot103_guess(index_guess,
						value4_guess, value5_guess, layer_guess, 0);
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(5, index_guess);
				}
				if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 3)
				{
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(3,
						EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
						EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value8_guess, value7_guess,
						EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
					if (ready_guess != 0)
					{
						owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(3, index_guess);
					}
				}
				if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 2)
				{
					owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(4,
						EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
						EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value8_guess, value7_guess,
						EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
					if (ready_guess != 0)
					{
						owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(4, index_guess);
					}
				}
			}
			else
			{
				owner_0004_guess->pActorInfo_01a8_guess->value_0138_guess = index_guess + g_offset_guess;
			}
		}
	}
}

// Both layers at once (see 0x00488377): starts animation `index_guess` only when both kinds are 2, updates
// both running layers when both are 3, else records the index in +0x138 and +0x140.
// FUNCTION: TITANIUM 0x00488676
void Mapper_guess::FUN_00488676_guess(int kind_guess, int count_guess, int index_guess,
	int value5_guess, int value6_guess, int value7_guess, int value8_guess, float value9_guess)
{
	if (kind_guess == 0 || count_guess == 0)
		return;
	Layer_guess* first_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(0);
	Layer_guess* second_guess = (Layer_guess*)owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Pick_guess(1);
	float value_guess = GetAnimBlendTime_guess(index_guess,
		Index_guess(owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess));
	if (kind_guess == 3 && count_guess == 3)
	{
		if (first_guess != 0)
			first_guess->Slot00_guess(value9_guess, value8_guess);
		if (second_guess != 0)
			second_guess->Slot00_guess(value9_guess, value8_guess);
		return;
	}
	if (kind_guess == 2 && count_guess == 2)
	{
		owner_0004_guess->pActorInfo_01a8_guess->currentAnimation_0134_guess = index_guess + g_offset_guess;
		owner_0004_guess->pActorInfo_01a8_guess->value_013c_guess = index_guess + g_offset_guess;
		owner_0004_guess->pActorInfo_01a8_guess->value_0144_guess = value5_guess;
		owner_0004_guess->pActorInfo_01a8_guess->value_0148_guess = value5_guess;
		owner_0004_guess->pActorInfo_01a8_guess->value_014c_guess = value6_guess;
		if (first_guess != 0)
		{
			first_guess->Slot02_guess(value7_guess, value9_guess, value8_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
			first_guess->Slot10_guess();
			first_guess->Slot11_guess((int)second_guess);
		}
		if (second_guess != 0)
		{
			second_guess->Slot02_guess(value7_guess, value9_guess, value8_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
			second_guess->Slot10_guess();
		}
		char ready_guess = Ready_guess();
		if (ready_guess != 0)
		{
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot103_guess(index_guess,
				value5_guess, value6_guess, second_guess, 0);
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(5, index_guess);
		}
		if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 3)
		{
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(3,
				EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
				EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value9_guess, value8_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
			if (ready_guess != 0)
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(3, index_guess);
		}
		if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 2)
		{
			owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot94_guess(4,
				EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
				EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], value9_guess, value8_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], value_guess);
			if (ready_guess != 0)
				owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess->Slot104_guess(4, index_guess);
		}
		return;
	}
	owner_0004_guess->pActorInfo_01a8_guess->value_0138_guess = index_guess + g_offset_guess;
	owner_0004_guess->pActorInfo_01a8_guess->value_0140_guess = index_guess + g_offset_guess;
}

// True for the special animation ids (0x00485F20) after adding the animation base (0x0066D248).
// FUNCTION: TITANIUM 0x0048895A
char Validator_guess::FUN_0048895a(int value)
{
	return CheckValue_guess(value + g_offset_guess) != 0;
}

// While the spawn sits (stand state 'n'): animations 'n' and 'o' become their sitting forms 'v' and 'w'
// (refused for the local player while the flag at 0x00850CCC is clear), and animations 0x82-0x84 are
// refused. Returns whether the animation may play; the idle animation picker calls it.
// FUNCTION: TITANIUM 0x004868A4
char Validator_guess::FUN_004868a4_guess(unsigned char* value_guess, int unused_guess)
{
	unsigned char code_guess = *value_guess;
	char result_guess = 1;
	if (state_guess->mode_guess == 'n')
	{
		if (code_guess == 'n' || code_guess == 'o')
		{
			if (code_guess != 'n')
				code_guess = 'w';
			else
				code_guess = 'v';
			if (state_guess == g_validationState_guess && g_validationFlag_guess == 0)
				result_guess = 0;
		}
		else if (code_guess > 0x81 && code_guess <= 0x84)
			result_guess = 0;
	}
	*value_guess = code_guess;
	return result_guess;
}

// Plays animation `kind_guess` on both track layers, picking one of its variants at random; logs "Animation
// doesn't exist for the given model!" when the model lacks it.
// FUNCTION: TITANIUM 0x00488974
void Mapper_guess::PlayAnimation_guess(int kind_guess, int flag_guess, int value_guess,
	float scale_guess, int zero_guess)
{
	int index_guess = Index_guess((unsigned short)kind_guess);
	int* records_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[index_guess];
	if (records_guess == 0 || records_guess[zero_guess * 4] == 0)
	{
		pEverQuest->dsp_chat("Animation doesn't exist for the given model!\n", 0xd, 1);
		return;
	}
	int track_guess = PickRandomVariant_guess(index_guess, zero_guess);
	int animation_value_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess->tables_02c_guess[index_guess]
		[track_guess + zero_guess * 4];
	Manager_guess* manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
	Layer_guess* first_layer_guess = (Layer_guess*)manager_guess->Pick_guess(0);
	manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
	Layer_guess* second_layer_guess = (Layer_guess*)manager_guess->Pick_guess(1);
	char ready_guess = Ready_guess();
	if (first_layer_guess != 0)
	{
		first_layer_guess->Slot10_guess();
		first_layer_guess->Slot03_guess(animation_value_guess, scale_guess, value_guess,
		((char)flag_guess == 0) * 2 + 1);
		if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 3)
		{
			manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
			manager_guess->Slot94_guess(3,
				EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
				EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], scale_guess, value_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], 100.0f);
			if (ready_guess != 0)
			{
				manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
				manager_guess->Slot104_guess(3, index_guess);
			}
		}
		if (EQ_ARRAY(int, 0x00692550)[index_guess * 9] != 2)
		{
			manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
			manager_guess->Slot94_guess(4,
				EQ_ARRAY(Row_guess, 0x008FFBC8) + EQ_ARRAY(int, 0x00693310)[index_guess],
				EQ_ARRAY(char*, 0x0069254C)[index_guess * 9], scale_guess, value_guess,
				EQ_ARRAY(int, 0x00692548)[index_guess * 9], 100.0f);
			if (ready_guess != 0)
			{
				manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
				manager_guess->Slot104_guess(4, index_guess);
			}
		}
	}
	if (second_layer_guess != 0)
	{
		second_layer_guess->Slot03_guess(animation_value_guess, scale_guess, value_guess,
			((char)flag_guess == 0) * 2 + 1);
		second_layer_guess->Slot10_guess();
		if (ready_guess != 0)
		{
			manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
			manager_guess->Slot103_guess(index_guess, zero_guess, track_guess,
				second_layer_guess, 0);
			manager_guess = owner_0004_guess->pActorInfo_01a8_guess->manager_0000_guess;
			manager_guess->Slot104_guess(5, index_guess);
		}
	}
	PlayAnimationSound_guess(0x4f, g_offset_guess + index_guess, zero_guess, track_guess);
}

struct LookupInterface_guess
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
	virtual int Lookup_guess(char* key_guess) = 0;
};

#define g_lookup_guess EQ_GLOBAL(LookupInterface_guess*, 0x0099E360)
#define g_nameTable_guess EQ_ARRAY(char*, 0x0069254C)
#define g_nameParts_guess EQ_ARRAY(char, 0x006932F8)

// EXTERNAL: TITANIUM 0x0048C879 GetRaceModelTag_guess
void __cdecl GetRaceModelTag_guess(char* output_guess, int value_guess, int mode_guess);

// FUNCTION: TITANIUM 0x00488BD6
char Mapper_guess::FUN_00488bd6_guess(int table_guess, int* first_guess, int* second_guess)
{
	while (table_guess >= 0)
	{
		if (table_guess == 0x4f - g_offset_guess)
			return 0;
		PickTables_guess* tables_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess;
		if (tables_guess == 0 || tables_guess->tables_02c_guess == 0)
			return 0;
		if (tables_guess->tables_02c_guess[table_guess] == 0)
		{
			table_guess = EQ_ARRAY(int, 0x00692534)[table_guess * 9] - g_offset_guess;
		}
		else
		{
			int category_guess = SelectMode_guess(g_offset_guess + table_guess);
			int other_guess = RemapAnimationKey_guess(table_guess, category_guess);
			if (tables_guess->tables_02c_guess[other_guess] != 0)
				table_guess = other_guess;
			int* record_guess = tables_guess->tables_02c_guess[table_guess];
			int found_guess = 0;
			if (record_guess[category_guess * 4] != 0)
			{
				*first_guess = table_guess;
				*second_guess = category_guess;
				found_guess = 1;
			}
			else if (category_guess != 0 && category_guess != 5 && record_guess[4] != 0)
			{
				*first_guess = table_guess;
				*second_guess = 1;
				found_guess = 1;
			}
			else if (record_guess[0] != 0)
			{
				*first_guess = table_guess;
				*second_guess = 0;
				found_guess = 1;
			}
			if (found_guess)
				return found_guess;
			table_guess = EQ_ARRAY(int, 0x00692534)[table_guess * 9] - g_offset_guess;
		}
	}
	return 0;
}

// Animation choice while standing still (probably sit, crouch, combat stance or an idle fidget; a 5-second
// timer gates it).
// FUNCTION: TITANIUM 0x00488CB6
// @early-stop: unknown, structural ndiff=182
void Mapper_guess::UpdateIdleAnimation_guess(int value_guess)
{
	float scale_guess = 1.0f;
	unsigned char code_guess = g_noCodeByte_guess;
	int notify_guess = 1;
	int float_flag_guess = 0;
	int update_flag_guess = 0;
	State_guess* active_guess = owner_0004_guess->pActorInfo_01a8_guess;

	if (active_guess->value_0f88_guess == 1)
	{
		code_guess = 'n';
		notify_guess = 0;
	}
	else if (owner_0004_guess->HasPlayerState_guess(g_pulseMask_guess) != 0)
	{
		code_guess = 0x81;
		notify_guess = 0;
	}
	else if (g_display_guess->tick_0148_guess == active_guess->value_0130_guess)
	{
		if (owner_0004_guess->standState_0251_guess == 'o')
		{
			code_guess = 'z';
			scale_guess = 10000.0f;
			float_flag_guess = 1;
		}
		else if (active_guess->level_00ad_guess >= 5 || active_guess->currentAnimation_0134_guess == 0x80 ||
			active_guess->currentAnimation_0134_guess == 0x7f)
		{
			code_guess = 0x7f;
			notify_guess = 0;
		}
		else
		{
			code_guess = 'n';
			float_flag_guess = 1;
			notify_guess = 0;
		}
	}
	else if (active_guess->level_00ad_guess >= 5)
	{
		code_guess = 0x7f;
		notify_guess = 0;
	}
	else if ((unsigned char)value_guess == 0)
	{
		if ((unsigned)(g_display_guess->tick_0148_guess - active_guess->value_0130_guess) < 0x1389 ||
			owner_0004_guess->standState_0251_guess == 'o')
		{
			if (owner_0004_guess->standState_0251_guess != 'o' && active_guess->currentAnimation_0134_guess != 0x80 &&
				active_guess->currentAnimation_0134_guess != 0x7f)
			{
				code_guess = 'n';
				notify_guess = 0;
			}
		}
		else
		{
			int roll_guess = number_percent_guess();
			active_guess->value_0130_guess = g_display_guess->tick_0148_guess;
			if (Slot14_guess(active_guess->currentAnimation_0134_guess) != 0 && g_valueCheckDisabled_guess == 0)
			{
				if (((owner_0004_guess->masterId_025c_guess != 0) ? 0x18 : 0) + 0x4b < roll_guess)
					code_guess = 'o';
				else
				{
					code_guess = 'n';
					notify_guess = 0;
				}
			}
		}
	}
	else if (active_guess->value_0f88_guess != 1)
	{
		if (owner_0004_guess->value_0058_guess <= EQ_GLOBAL(float, 0x0063F4CC))
		{
			if (owner_0004_guess->value_0058_guess < EQ_GLOBAL(float, 0x0063F4CC))
			{
				float_flag_guess = 1;
				if (owner_0004_guess->standState_0251_guess == 'o')
					code_guess = '}';
				else
					code_guess = 'k';
			}
		}
		else
		{
			float_flag_guess = 1;
			if (owner_0004_guess->standState_0251_guess == 'o')
			{
				code_guess = '}';
				update_flag_guess = 1;
			}
			else
				code_guess = 'l';
		}
	}
	else
	{
		code_guess = 'n';
		notify_guess = 0;
	}

	if (code_guess != g_noCode_guess)
	{
		if (((Validator_guess*)this)->FUN_004868a4_guess(&code_guess, update_flag_guess) != 0)
			Slot02_guess(code_guess, notify_guess, update_flag_guess, scale_guess, float_flag_guess);
	}
}

// Per-frame animation update: idle choice when standing still on the ground, else movement choice; then
// sounds.
// FUNCTION: TITANIUM 0x00488ECD
void Mapper_guess::UpdateAnimation_guess(int value_guess)
{
	Owner_guess* owner_guess = owner_0004_guess;
	bool ready_guess = false;
	if (owner_guess->vec_0030_guess.coordinates_000c_guess.FUN_00435b36_guess() < 0.01f &&
		owner_guess->pActorInfo_01a8_guess->mount_015c_guess == 0)
		ready_guess = true;
	if (g_display_guess->flag_0005_guess != 0)
	{
		if (ready_guess)
			UpdateIdleAnimation_guess(value_guess);
		else
			UpdateMovementAnimation_guess();
	}
	FUN_00486f60_guess();
}

// Track id for "<anim>_<part>_<n>_<model tag>", retried with the fallback race's tag (and its shared
// skeleton) when the model has none.
// FUNCTION: TITANIUM 0x00488F2B
int __cdecl FindAnimationTrack_guess(int value_guess, int mode_guess, int group_guess,
	int part_guess, int index_guess)
{
	char name_guess[16];
	char key_guess[64];
	GetRaceModelTag_guess(name_guess, value_guess, mode_guess);
	sprintf(key_guess, "%s_%s_%d_%s",
		g_nameTable_guess[group_guess * 9], g_nameParts_guess + part_guess * 3,
		index_guess + 1, name_guess);
	int result_guess = g_lookup_guess->Lookup_guess(key_guess);
	if (result_guess != 0)
		return result_guess;

	if (mode_guess == 1)
	{
		if (!FUN_00486d7a_guess(value_guess))
		{
			GetRaceModelTag_guess(name_guess, value_guess, 0);
			sprintf(key_guess, "%s_%s_%d_%s",
				g_nameTable_guess[group_guess * 9], g_nameParts_guess + part_guess * 3,
				index_guess + 1, name_guess);
			result_guess = g_lookup_guess->Lookup_guess(key_guess);
			if (result_guess != 0)
				return result_guess;
			return FindAnimationTrack_guess(GetAnimFallbackRace_guess(value_guess), 1,
				group_guess, part_guess, index_guess);
		}
		return FindAnimationTrack_guess(value_guess, 0, group_guess, part_guess, index_guess);
	}
	if (mode_guess == 0)
	{
		if (FUN_00486d7a_guess(value_guess))
			return 0;
		return FindAnimationTrack_guess(GetAnimFallbackRace_guess(value_guess), 0,
			group_guess, part_guess, index_guess);
	}
	if (mode_guess == 2)
	{
		if (FUN_00486d7a_guess(value_guess))
			return FindAnimationTrack_guess(value_guess, 0, group_guess, part_guess, index_guess);
		return FindAnimationTrack_guess(GetAnimFallbackRace_guess(value_guess), 2,
			group_guess, part_guess, index_guess);
	}
	return 0;
}

struct SoundManager_guess
{
	// EXTERNAL: TITANIUM 0x0044BEA0 SoundManager_guess::WaveLoadById_guess
	void WaveLoadById_guess(int sound_guess, char flag_guess);
	// EXTERNAL: TITANIUM 0x0044A516 SoundManager_guess::IsMuted_guess
	char IsMuted_guess(int sound_guess);
};

#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)
// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format_guess, ...);

// Animation changed from `prev_guess` to `cur_guess`: stops the loop sound and starts the action sound for
// the new animation (race-specific for some, e.g. races 60 and 367 use sound 0x1D0).
// FUNCTION: TITANIUM 0x004860A3
// @early-stop: budget, structural ndiff=191
void Mapper_guess::PlayAnimationSound_guess(int prev_guess, int cur_guess, int a_guess, int b_guess)
{
	bool changed_guess = false;
	if (cur_guess != prev_guess)
	{
		owner_0004_guess->pActorInfo_01a8_guess->value_0f70_guess = 0;
		owner_0004_guess->SetCurrentLoopSound_guess(owner_0004_guess->pActorInfo_01a8_guess->value_0f20_guess);
		changed_guess = true;
	}
	else if (cur_guess == 0x92)
		return;
	// Silent: animations 0x6E, 0x4F, 0xFE and ids below the table base, and race 127 (invisible man).
	if (cur_guess == 0x6e || cur_guess == 0x4f || cur_guess < g_offset_guess || cur_guess == 0xfe)
		return;
	int result_guess = 0;
	if (owner_0004_guess->race_0260_guess == 0x7f)
		return;
	if (owner_0004_guess == g_player_guess)
	{
		// Repeating sounds are rate-limited through actor +0xF74. Our own player: 500 ms for 0x68-0x6A and
		// 0x7D/0x7E, 550 for 0x80, 600 for 0x7F. Other spawns: 500 ms for 0x7D/0x7E; 0x7F/0x80 rate-limited for
		// player races (LegalPlayerRace_guess), otherwise played only when the race has its own step sound
		// (+0xF5C).
		if (cur_guess == 0x68 || cur_guess == 0x6a || cur_guess == 0x7d || cur_guess == 0x69 || cur_guess == 0x7e)
		{
			if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 500
				&& owner_0004_guess->flag_01b1_guess == 0)
			{
				owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
				changed_guess = true;
			}
		}
		else if (cur_guess == 0x80)
		{
			if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 0x226)
			{
				owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
				changed_guess = true;
			}
		}
		else if (cur_guess == 0x7f)
		{
			if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 0x258)
			{
				changed_guess = true;
				owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
			}
		}
	}
	else if (cur_guess == 0x7d || cur_guess == 0x7e)
	{
		if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 500
			&& owner_0004_guess->flag_01b1_guess == 0)
		{
			owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
			changed_guess = true;
		}
	}
	else if (cur_guess == 0x80)
	{
		if (owner_0004_guess->LegalPlayerRace_guess(-1) != 0)
		{
			if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 0x226)
			{
				owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
				changed_guess = true;
			}
		}
		else if (owner_0004_guess->pActorInfo_01a8_guess->value_0f5c_guess != 0)
			changed_guess = true;
	}
	else if (cur_guess == 0x7f)
	{
		if (owner_0004_guess->LegalPlayerRace_guess(-1) != 0)
		{
			if ((unsigned int)(g_display_guess->tick_0148_guess - owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess) > 0x258)
			{
				owner_0004_guess->pActorInfo_01a8_guess->value_0f74_guess = g_display_guess->tick_0148_guess;
				changed_guess = true;
			}
		}
		else if (owner_0004_guess->pActorInfo_01a8_guess->value_0f5c_guess != 0)
			changed_guess = true;
	}
	if (changed_guess)
	{
		// Default sound per animation: some pick one of four or five variants at random, some alternate (0x7E:
		// 0x60/0x61), some come from the model's sound set (+0xF20.. in the actor), and stance 5 (+0xF78) uses
		// 0x96.
		if (cur_guess == 0x6a)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
			{
				if (owner_0004_guess == g_player_guess)
					result_guess = 0x5f;
				else
				{
					result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f60_guess;
					if (result_guess != 0 && result_guess != 0x5f)
					{
						owner_0004_guess->SetCurrentLoopSound_guess(result_guess);
						result_guess = 0;
					}
				}
				if (result_guess == 0x5f)
				{
					switch (RandomRange_guess(0, 3))
					{
					case 0: result_guess = 0x5f; break;
					case 1: result_guess = 0x5e; break;
					case 2: result_guess = 0x99; break;
					case 3: result_guess = 0x9a; break;
					}
				}
			}
		}
		else if (cur_guess == 0x68 || cur_guess == 0x69)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
			{
				if (owner_0004_guess == g_player_guess)
					result_guess = 0x5d;
				else
				{
					result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f5c_guess;
					if (result_guess != 0 && result_guess != 0x5d)
					{
						owner_0004_guess->SetCurrentLoopSound_guess(result_guess);
						result_guess = 0;
					}
				}
				if (result_guess == 0x5d)
				{
					switch (RandomRange_guess(0, 3))
					{
					case 0: result_guess = 0x5d; break;
					case 1: result_guess = 0x5c; break;
					case 2: result_guess = 0x97; break;
					case 3: result_guess = 0x98; break;
					}
				}
			}
		}
		else if (cur_guess == 0x7f)
		{
			if (owner_0004_guess->LegalPlayerRace_guess(-1) != 0)
				result_guess = 0x65;
		}
		else if (cur_guess == 0x80)
		{
			if (owner_0004_guess->LegalPlayerRace_guess(-1) != 0)
				result_guess = 0x66;
		}
		else if (cur_guess == 0x6f)
		{
			if (RandomRange_guess(1, 100) < 0x32)
				owner_0004_guess->SetCurrentLoopSound_guess(owner_0004_guess->pActorInfo_01a8_guess->value_0f24_guess);
			else
				owner_0004_guess->SetCurrentLoopSound_guess(owner_0004_guess->pActorInfo_01a8_guess->value_0f28_guess);
		}
		else if (cur_guess == 0x7b || cur_guess == 0x7c)
			result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f2c_guess;
		else if (cur_guess == 0x7d)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f64_guess;
		}
		else if (cur_guess == 0x7e)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
			{
				if (owner_0004_guess->pActorInfo_01a8_guess->value_0f68_guess != 0)
				{
					owner_0004_guess->pActorInfo_01a8_guess->value_0f68_guess = 0;
					result_guess = 0x61;
				}
				else
				{
					result_guess = 0x60;
					owner_0004_guess->pActorInfo_01a8_guess->value_0f68_guess = 1;
				}
			}
		}
		else if (cur_guess == 0x79)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
			{
				int race_guess = owner_0004_guess->race_0260_guess;
				result_guess = 0x62;
				if (race_guess == 0x3c || race_guess == 0x16f)
					result_guess = 0x1d0;
			}
		}
		else if (cur_guess == 0x6d)
		{
			if (owner_0004_guess->flag_01b1_guess == 0)
				result_guess = 0x62;
		}
		else if (cur_guess == 0x91)
			result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f48_guess;
		else if (cur_guess == 0x92)
		{
			if (owner_0004_guess->type_0244_guess == 0)
			{
				if (owner_0004_guess->standState_0251_guess == 'x' || owner_0004_guess->hpCurrent_0274_guess > 0)
					result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f4c_guess;
			}
			else if (owner_0004_guess->bodyType_0270_guess < 0x41)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f4c_guess;
		}
		else if (cur_guess == 0x5f)
			result_guess = 0x7e;
		else if (cur_guess == 0x52)
		{
			result_guess = 0x7a;
			if (owner_0004_guess->pActorInfo_01a8_guess->primaryItemType_0f78_guess == 5)
				result_guess = 0x96;
		}
		else if (cur_guess == 0x56)
		{
			result_guess = 0x77;
			if (owner_0004_guess->pActorInfo_01a8_guess->primaryItemType_0f78_guess == 5)
				result_guess = 0x96;
		}
		else if (cur_guess == 0x58)
			result_guess = 0x79;
		else if (cur_guess == 0x51 || cur_guess == 0x50)
		{
			if (RandomRange_guess(1, 3) == 1 || owner_0004_guess == g_player_guess)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f50_guess;
			int stance_guess = owner_0004_guess->pActorInfo_01a8_guess->primaryItemType_0f78_guess;
			if (stance_guess == 5)
				result_guess = 0x96;
			else if (stance_guess != 0)
			{
				owner_0004_guess->PlaySound_guess(0x76);
				if (result_guess == 0x82)
					result_guess = 0;
			}
			else if (result_guess == 0)
			{
				switch (RandomRange_guess(1, 5))
				{
				case 1: result_guess = 0x7e; break;
				case 2: result_guess = 0x7a; break;
				case 3: result_guess = 0x82; break;
				case 4: result_guess = 0x81; break;
				case 5: result_guess = 0x76; break;
				}
			}
			int race_guess = owner_0004_guess->race_0260_guess;
			if (race_guess == 0x31 || race_guess == 0x7a)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f50_guess;
		}
		else if (cur_guess == 0x53)
		{
			int stance_guess = owner_0004_guess->pActorInfo_01a8_guess->secondaryItemType_0f7c_guess;
			if (stance_guess == 5)
				result_guess = 0x96;
			else if (stance_guess == 3)
				result_guess = 0x7c;
			else
				result_guess = stance_guess != 0 ? 0x76 : 0x81;
		}
		else if (cur_guess == 0x5b)
			result_guess = owner_0004_guess->pActorInfo_01a8_guess->secondaryItemType_0f7c_guess == 3 ? 0x7c : 0x77;
		else if (cur_guess == 0x5c)
		{
			if (RandomRange_guess(1, 3) == 1 || owner_0004_guess == g_player_guess)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f50_guess;
			int stance_guess = owner_0004_guess->pActorInfo_01a8_guess->primaryItemType_0f78_guess;
			if (stance_guess == 5)
				result_guess = 0x96;
			else if (stance_guess != 0)
			{
				owner_0004_guess->PlaySound_guess(0x76);
				if (result_guess == 0x82)
					result_guess = 0;
			}
			else if (result_guess == 0)
			{
				switch (RandomRange_guess(1, 5))
				{
				case 1: result_guess = 0x7e; break;
				case 2: result_guess = 0x7a; break;
				case 3: result_guess = 0x82; break;
				case 4: result_guess = 0x81; break;
				case 5: result_guess = 0x76; break;
				}
			}
		}
		else if (cur_guess == 0x5d)
			result_guess = 0x74;
		else if (cur_guess == 0x5e)
		{
			if (RandomRange_guess(1, 3) == 1 || owner_0004_guess == g_player_guess)
				result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f50_guess;
			if (owner_0004_guess->pActorInfo_01a8_guess->primaryItemType_0f78_guess != 0)
			{
				owner_0004_guess->PlaySound_guess(0x76);
				if (result_guess == 0x82)
					result_guess = 0;
			}
			else
			{
				switch (RandomRange_guess(1, 5))
				{
				case 1: result_guess = 0x7e; break;
				case 2: result_guess = 0x7a; break;
				case 3: result_guess = 0x82; break;
				case 4: result_guess = 0x81; break;
				case 5: result_guess = 0x76; break;
				}
			}
		}
		else if (cur_guess == 0x60 || cur_guess == 0x65)
			result_guess = 0x80;
		else if (cur_guess == 0x86 || cur_guess == 0x87 || cur_guess == 0x85)
			result_guess = owner_0004_guess->pActorInfo_01a8_guess->value_0f58_guess;
		else if (cur_guess == 0x66 || cur_guess == 0x67)
			result_guess = 0x82;
	}
	if (changed_guess)
	{
		// The model's own track table overrides the default (row per animation, column by `a_guess`/`b_guess`). Ids
		// below 0x20 are no sound; for the player (or what it rides) a muted sound is skipped.
		PickTables_guess* tables_guess = owner_0004_guess->pActorInfo_01a8_guess->tables_12c_guess;
		if (tables_guess != 0)
		{
			int* row_guess = tables_guess->tables_02c_guess[cur_guess - g_offset_guess];
			if (row_guess != 0)
			{
				int sound_guess = row_guess[b_guess + a_guess * 4 + 0x28];
				if (sound_guess != 0)
					result_guess = sound_guess;
			}
		}
	}
	if (result_guess < 0x20)
		result_guess = 0;
	if (owner_0004_guess == g_player_guess
		|| (int)owner_0004_guess == g_player_guess->pActorInfo_01a8_guess->mount_015c_guess)
	{
		if (result_guess == 0)
			return;
		if (g_soundManager_guess->IsMuted_guess(result_guess))
			result_guess = 0;
	}
	if (result_guess != 0 && changed_guess)
		owner_0004_guess->PlaySound_guess(result_guess);
}

