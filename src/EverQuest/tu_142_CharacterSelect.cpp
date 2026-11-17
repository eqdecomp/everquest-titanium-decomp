// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 142: a hint from compare/tumap.py.
// The character select window (sidl "CharacterSelectWindow"; CCharacterSelect in the earlier sibling decomp);
// CCharacterSelectView_guess is a view of it. pEverQuest+0x39410 holds the OP_SendCharInfo payload (EQEmu
// CharacterSelect_Struct: race +0x39410, deity +0x39750, Go Home +0x39778, Tutorial +0x39782, zone +0x397D4, names
// +0x39810, gender +0x39A90, level +0x39AAE; 8 of its 10 slots used). Empty slots are named "<none>".
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>
#include "titanium/wnd/CSystemInfoDialogBox.h"

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0060E450 CopyBuffer_guess
void __cdecl CopyBuffer_guess(char* buffer_guess, const char* value_guess);

// EXTERNAL: TITANIUM 0x0046199E SetCommandEnabled_guess
void __cdecl SetCommandEnabled_guess(int state_guess, int value_guess);

// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section_guess, const char* key_guess,
	const char* value_guess, char* buffer_guess, int size_guess, const char* file_guess);

// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section_guess, const char* key_guess,
	const char* value_guess, const char* file_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
int __cdecl atoi(const char* text_guess);

struct BufferOwner_guess {
	char unknown_0000_guess[0x19c];
	char buffer_guess;

	void SetBuffer_guess(const char* value_guess);
	char* GetBuffer_guess();
};

struct NameFields_guess {
	char unknown_0000_guess[0x39750];
	int mappedIds_guess[8];
	char unknown_39770_guess[0xa0];
	char names_guess[8][0x40];
};

struct NameStorage_guess {
	union {
		NameFields_guess fields_guess;
		int words_guess[0xe684];
	};
};

struct ChildState_guess {
	char unknown_0000_guess[0x5d];
	char enabled_guess;
	// EXTERNAL: TITANIUM 0x005BB140 ChildState_guess::SetCheck
	void SetCheck(int value_guess);
};

struct Settings_guess {
	// EXTERNAL: TITANIUM 0x00493978 Settings_guess::SetupCharSelectCamera_guess
	void SetupCharSelectCamera_guess();
	// EXTERNAL: TITANIUM 0x004AE721 Settings_guess::GetInt_guess
	int GetInt_guess(const char* section_guess, const char* key_guess, int default_guess);
	// EXTERNAL: TITANIUM 0x00493BEA Settings_guess::SendSystemInfo_guess
	void SendSystemInfo_guess();
	// EXTERNAL: TITANIUM 0x004AE5AF Settings_guess::Set_guess
	void Set_guess(unsigned char value_guess, const char* key_guess, const char* text_guess);
};

struct GlobalState_guess {
	char unknown_0000_guess[0x204];
	int value_guess;
};

struct SidlPiece_guess {
	char unknown_0000_guess[0x60];
	unsigned int flags_0060_guess;
};

struct CharacterCreatePrimary_guess {
	// EXTERNAL: TITANIUM 0x005A3900 ??0CharacterCreatePrimary_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
	CharacterCreatePrimary_guess(CXWnd* parent_guess, const CXStr& screen_guess);
	virtual ~CharacterCreatePrimary_guess();
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
	char unknown_0004_guess[0x58];
	char show_005c_guess;
	char unknown_005d_guess[7];
	unsigned int style_0064_guess;
	char unknown_0068_guess[0xbc];
	SidlPiece_guess* sidlPiece_0124_guess;
	char unknown_0128_guess[0x34];
	// EXTERNAL: TITANIUM 0x005A25B0 CharacterCreatePrimary_guess::CreateChildrenFromSidl
	void CreateChildrenFromSidl();
	// EXTERNAL: TITANIUM 0x005A1E10 CharacterCreatePrimary_guess::GetChildItem
	CXWnd* GetChildItem(const CXStr& name_guess);
	// EXTERNAL: TITANIUM 0x005A1D40 CharacterCreatePrimary_guess::EnableIniStorage
	void EnableIniStorage(int enable_guess, char* name_guess);
};

struct NamedChild_guess;
struct OwnedChild_guess;
struct ChildOwner_guess {
	OwnedChild_guess* child_guess;
};

struct CharacterCreateSecondary_guess {
	// EXTERNAL: TITANIUM 0x005482A0 CharacterCreateSecondary_guess::Shutdown_guess
	void Shutdown_guess(int value_guess);
	virtual ~CharacterCreateSecondary_guess() { Shutdown_guess(-1); }
	CXWnd* exploreButton_guess;
	union {
		ChildState_guess* child_guess;
		CXWnd* rotateButton_guess;
	};
	NamedChild_guess* children_guess[8];
	CXWnd* enterButton_guess;
	CXWnd* deleteButton_guess;
	CXWnd* quitButton_guess;
	CXWnd* tutorialButton_guess;
	CXWnd* goHomeButton_guess;
	char name_019c_guess[0x40];
	ChildOwner_guess owner_guess;
	char flag_1e0_guess;
	char rotate_guess;
	char flag_1e2_guess;
	char flag_1e3_guess;
	char flag_1e4_guess;
	char unknown_01e5_guess[3];
	int value_1e8_guess;
	int value_1ec_guess;
	int value_1f0_guess;
	int value_1f4_guess;
	char flag_1f8_guess;
	virtual void OnConfirmation_guess(int event_guess, unsigned char flags_guess, int unused_guess);
};

struct OwnedChild_guess {
	virtual void Slot00_guess();
	virtual void Slot01_guess(int value_guess);
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
};

struct NamedChild_guess {
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
	virtual void Slot63_guess(const CXStr& text_guess);
};

// EXTERNAL: TITANIUM 0x00652738 ??_7CCharacterSelectView_guess@@6BCharacterCreatePrimary_guess@@@
// EXTERNAL: TITANIUM 0x00652734 ??_7CCharacterSelectView_guess@@6BCharacterCreateSecondary_guess@@@
// EXTERNAL: TITANIUM 0x0063FD9C ??_7CharacterCreateSecondary_guess@@6B@
// EXTERNAL: TITANIUM 0x005A3100 ??1CharacterCreatePrimary_guess@@UAE@XZ
struct CCharacterSelectView_guess : CharacterCreatePrimary_guess, CharacterCreateSecondary_guess {
	virtual ~CCharacterSelectView_guess();
	CCharacterSelectView_guess(CXWnd* parent_guess);
	bool AboutToHide_guess();
	void DespawnOtherCharacters_guess();
	// EXTERNAL: TITANIUM 0x004F1A03 CCharacterSelectView_guess::SelectCharacter_guess
	void SelectCharacter_guess(int selection_guess, int enabled_guess);
	void Initialize_guess();
	void* Delete_guess(unsigned char flags_guess);
	void LeaveExplorationMode_guess();
	void UpdateChildNames_guess();
	// EXTERNAL: TITANIUM 0x005A0650 CCharacterSelectView_guess::ResetChild_guess
	void ResetChild_guess();
	bool AboutToShow_guess();
	void SpawnOtherCharacters_guess();
	void EnterExplorationMode_guess();
	void Enter_guess();
	// EXTERNAL: TITANIUM 0x005A1880 CCharacterSelectView_guess::OnShow
	void OnShow();
	void Slot35_guess();
	int WndNotification_guess(int target_guess, int mode_guess, int unused_guess);
	void OnConfirmation_guess(int event_guess, unsigned char flags_guess, int unused_guess);
};

struct CConfirmationDialogPoolView_guess {
	// EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
	void Activate(unsigned int address_guess, int type_guess, const char* message_guess,
		int first_guess, int second_guess, int third_guess, int fourth_guess);
};

// EXTERNAL: TITANIUM 0x00493430 RemoveCharacterOptionFile_guess
void __stdcall RemoveCharacterOptionFile_guess(char* buffer_guess);

// EXTERNAL: TITANIUM 0x00479908 WhatDeityAlliance_guess
int __cdecl WhatDeityAlliance_guess(int value_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess, const char* text_guess,
	int zero1_guess, int zero2_guess, int zero3_guess, int zero4_guess, int zero5_guess,
	int zero6_guess, int zero7_guess, int zero8_guess);

// Deletes the explore-mode helper (ExploreMode_guess) through its virtual slot 1.
// FUNCTION: TITANIUM 0x004F0C12
CCharacterSelectView_guess::~CCharacterSelectView_guess()
{
	OwnedChild_guess** child_guess = &owner_guess.child_guess;
	if (*child_guess != 0) {
		(*child_guess)->Slot01_guess(1);
		*child_guess = 0;
	}
}

// Fresh state: no selection (-1), Rotate from eqclient.ini CharCreateRotateOn, and the preview player
// (pinstLocalPlayer) parked in zone 190.
// FUNCTION: TITANIUM 0x004F0C7F
void CCharacterSelectView_guess::Initialize_guess()
{
	int setting_guess = EQ_GLOBAL(Settings_guess*, 0x00988DF0)->GetInt_guess(
		"Defaults", "CharCreateRotateOn", 0);
	this->rotate_guess = (char)setting_guess;
	this->flag_1e2_guess = 0;
	if (this->child_guess != 0) {
		this->child_guess->SetCheck(setting_guess);
	}
	this->value_1e8_guess = -1;
	this->value_1ec_guess = 0;
	this->value_1f0_guess = 0;
	this->value_1f4_guess = 0;
	this->flag_1f8_guess = 0;
	this->flag_1e3_guess = 0;
	this->flag_1e4_guess = 0;
	GlobalState_guess* state_guess = EQ_GLOBAL(GlobalState_guess*, 0x00905CE4);
	if (state_guess != 0) {
		state_guess->value_guess = 0xbe;
	}
}

// Character select window AboutToHide (vtable 0x652738 slot 50): expires every confirmation dialog it
// opened (the delete and Go Home boxes; 0x005482A0 with -1); never vetoes.
// FUNCTION: TITANIUM 0x004F0CF8
bool CCharacterSelectView_guess::AboutToHide_guess()
{
	CharacterCreateSecondary_guess::Shutdown_guess(-1);
	return true;
}

// Character select window: stores `value` as the remembered character name (+0x19C). Character creation
// stores the new character's name here once the server approves it (0x004EFEF1), so the selection
// returns to it.
// FUNCTION: TITANIUM 0x004F0D08
void BufferOwner_guess::SetBuffer_guess(const char* value_guess)
{
	CopyBuffer_guess(&buffer_guess, value_guess);
}

// Character select window: returns the remembered character name (+0x19C). The char select loop sends
// it with Enter World (opcode 0x7CBA) when it is longer than 3 characters.
// FUNCTION: TITANIUM 0x004F0D1D
char* BufferOwner_guess::GetBuffer_guess()
{
	return &buffer_guess;
}

struct StateFlags_guess {
	char unknown_0000_guess[0x160];
	ChildState_guess* first_guess;
	int unknown_0164_guess;
	ChildState_guess* states_guess[8];
	ChildState_guess* state_188_guess;
	ChildState_guess* state_18c_guess;
	int unknown_0190_guess;
	ChildState_guess* state_194_guess;
	ChildState_guess* state_198_guess;
	char unknown_019c_guess[0x4c];
	int selection_guess;
	void EnableButtons_guess(char enabled_guess);
};

// Enables or disables the buttons, e.g. while a confirmation box is open. Tutorial and Go Home come back
// only when the selected character has them (CharacterSelect_Struct Tutorial/GoHome) and the OP_LogServer
// flag 0x923D66 is clear.
// FUNCTION: TITANIUM 0x004F0D24
void StateFlags_guess::EnableButtons_guess(char enabled_guess)
{
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		if (states_guess[index_guess] != 0) {
			states_guess[index_guess]->enabled_guess = enabled_guess;
		}
	}
	if (first_guess != 0) {
		first_guess->enabled_guess = enabled_guess;
	}
	if (state_194_guess != 0) {
		char value_guess;
		if (enabled_guess != 0 && EQ_GLOBAL(char, 0x00923D66) == 0 &&
			selection_guess != -1 &&
			*((char*)selection_guess + EQ_GLOBAL(int, 0x00988DF0) + 0x39782) != 0) {
			value_guess = 1;
		} else {
			value_guess = 0;
		}
		state_194_guess->enabled_guess = value_guess;
	}
	if (state_188_guess != 0) {
		state_188_guess->enabled_guess = enabled_guess;
	}
	if (state_18c_guess != 0) {
		state_18c_guess->enabled_guess = enabled_guess;
	}
	if (state_198_guess != 0) {
		char value_guess;
		if (enabled_guess != 0 && EQ_GLOBAL(char, 0x00923D66) == 0 &&
			selection_guess != -1 &&
			*((char*)selection_guess + EQ_GLOBAL(int, 0x00988DF0) + 0x39778) != 0) {
			value_guess = 1;
		} else {
			value_guess = 0;
		}
		state_198_guess->enabled_guess = value_guess;
	}
}

struct StateHolder_guess {
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
	char unknown_0004_guess[0x184];
	ChildState_guess* childState_guess;
	char unknown_018c_guess[0x5c];
	int range_guess;
	int state_guess;
	void SetExploreCommandsEnabled_guess(int value_guess);
	void Quit_guess();
	int IsInRange_guess();
	void DeleteCharacter_guess();
	void CheckDeityAlliances_guess();
};

// Turns the explore-mode movement commands on or off: FORWARD, BACK, RIGHT, LEFT, PITCHUP, PITCHDOWN
// (command ids 2-5, 17, 18).
// FUNCTION: TITANIUM 0x004F0DE5
void StateHolder_guess::SetExploreCommandsEnabled_guess(int value_guess)
{
	SetCommandEnabled_guess(2, value_guess);
	SetCommandEnabled_guess(3, value_guess);
	SetCommandEnabled_guess(5, value_guess);
	SetCommandEnabled_guess(4, value_guess);
	SetCommandEnabled_guess(0x11, value_guess);
	SetCommandEnabled_guess(0x12, value_guess);
}

// Quit button: +0x1EC = 1, then virtual slot 34 as in Enter_guess.
// FUNCTION: TITANIUM 0x004F0E21
void StateHolder_guess::Quit_guess()
{
	state_guess = 1;
	Slot34_guess();
}

// True when a character is selected (slot 0-7).
// FUNCTION: TITANIUM 0x004F0E33
int StateHolder_guess::IsInRange_guess()
{
	return range_guess >= 0 && range_guess < 8;
}

struct NameTable_guess {
	int IsCharacterSlotEmpty_guess(int index_guess);
	int CountPresent_guess();
};

// Whether character slot `index` is empty: its name in the OP_SendCharInfo copy (pEverQuest +0x39810,
// 0x40 bytes each) is "<none>".
// FUNCTION: TITANIUM 0x004F0E49
int NameTable_guess::IsCharacterSlotEmpty_guess(int index_guess)
{
	return strcmp(EQ_GLOBAL(char*, 0x00988DF0) + index_guess * 0x40 + 0x39810, "<none>") == 0;
}

// Number of the 8 character slots holding a character (0x004F0E49). The char select loop (0x004A9EBF,
// 0x004AA92B) checks it.
// FUNCTION: TITANIUM 0x004F0E72
int NameTable_guess::CountPresent_guess()
{
	int count_guess = 0;
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		if (!IsCharacterSlotEmpty_guess(index_guess)) {
			++count_guess;
		}
	}
	return count_guess;
}

// After the delete confirmation: removes the character's name_world.opt file, then sends OP_DeleteCharacter
// with the name (NUL included) and sets 0x923880.
// FUNCTION: TITANIUM 0x004F0E94
void StateHolder_guess::DeleteCharacter_guess()
{
	RemoveCharacterOptionFile_guess(EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[range_guess]);
	unsigned int size_guess = (unsigned int)strlen(EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[range_guess]) + 1;
	EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_DeleteCharacter,
		EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[range_guess], size_guess, 1);
	EQ_GLOBAL(int, 0x00923880) = 1;
}

// On servers of type 4 (0x900478, from OP_LogServer; probably deity-team PvP), all characters must share
// one deity alliance (WhatDeityAlliance_guess): otherwise string 601 is shown and Enter World disabled.
// FUNCTION: TITANIUM 0x004F0F08
// @early-stop: unknown, diff ndiff=7
void StateHolder_guess::CheckDeityAlliances_guess()
{
	if (EQ_GLOBAL(int, 0x00900478) != 4) {
		return;
	}
	unsigned int first_guess = 0;
	int index_guess = 0;
	for (; index_guess < 8; ++index_guess) {
		if (strcmp(EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[index_guess], "<none>") != 0) {
			int mapped_guess = WhatDeityAlliance_guess(
				EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.mappedIds_guess[index_guess]);
			if (first_guess == 0) {
				first_guess = mapped_guess;
			} else if (first_guess != mapped_guess) {
				EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)->Activate(
				EQ_GLOBAL(unsigned int, 0x00850B9C) != 0
					? EQ_GLOBAL(unsigned int, 0x00850B9C) + 0x15c
					: 0, 0xb,
					pStringTable->getString(0x259, 0),
					1, -1, 0, 1);
				childState_guess->enabled_guess = 0;
				return;
			}
		}
	}
}

// Labels Char1-8_Button with the names; empty slots get string 1947.
// FUNCTION: TITANIUM 0x004F0FB5
void CCharacterSelectView_guess::UpdateChildNames_guess()
{
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		if (children_guess[index_guess] != 0) {
			if (((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess) != 0) {
				CXStr text_guess(pStringTable->getString(0x79b, 0));
				children_guess[index_guess]->Slot63_guess(text_guess);
			} else {
				CXStr text_guess(EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[index_guess]);
				children_guess[index_guess]->Slot63_guess(text_guess);
			}
		}
	}
	((StateHolder_guess*)this)->CheckDeityAlliances_guess();
}

struct ObjectState_guess {
	char unknown_0000_guess[0x30];
	int value_0030_guess;
	float value_0034_guess;
	float value_0038_guess;
	char unknown_003c_guess[0x10];
	int value_004c_guess;
	// EXTERNAL: TITANIUM 0x004797D5 ObjectState_guess::Attach_guess
	void Attach_guess(void* state_guess);
	// EXTERNAL: TITANIUM 0x00479E37 ObjectState_guess::PlaceOnFloor_guess
	void PlaceOnFloor_guess();
	// EXTERNAL: TITANIUM 0x0048A945 ObjectState_guess::Finish_guess
	void Finish_guess();
};

struct StateManager_guess {
	char unknown_0000_guess[5];
	char flag_0005_guess;
	char unknown_0006_guess[0x2872];
	int value_2878_guess;
	// EXTERNAL: TITANIUM 0x004459E5 StateManager_guess::SetDayPeriod_guess
	void SetDayPeriod_guess(int first_guess, int second_guess);
	// EXTERNAL: TITANIUM 0x004437E5 StateManager_guess::SetSunLight_guess
	void SetSunLight_guess();
	// EXTERNAL: TITANIUM 0x004392DE StateManager_guess::SetCameraMode_guess
	void SetCameraMode_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x004395C4 StateManager_guess::DeleteLight_guess
	void DeleteLight_guess(void* item_guess);
	// EXTERNAL: TITANIUM 0x0043C84B StateManager_guess::Attach_guess
	void Attach_guess(void* object_guess);
	// EXTERNAL: TITANIUM 0x0043910D StateManager_guess::Assign_guess
	void Assign_guess(void* item_guess);
	// EXTERNAL: TITANIUM 0x004426FB StateManager_guess::SetupCharacterViewCamera_guess
	void SetupCharacterViewCamera_guess(int value_guess);
};

struct GlobalOptions_guess {
	char unknown_0000_guess[0x48];
	float value_0048_guess;
	char unknown_004c_guess[0x0c];
	float value_0058_guess;
	char unknown_005c_guess[0x1f6];
	unsigned char flag_0252_guess;
};

struct StateEntry_guess {
	int value_0000_guess;
	float value_0004_guess;
	float value_0008_guess;
	int value_000c_guess;
};

struct StateSetup_guess {
	void PlaceAtExploreSpot_guess(int index_guess, ObjectState_guess* object_guess);
};

// Despawns the other characters, zeroes the preview player's +0x48 and +0x58, and re-selects the current
// character.
// FUNCTION: TITANIUM 0x004F18FF
void CCharacterSelectView_guess::LeaveExplorationMode_guess()
{
	if (owner_guess.child_guess != 0) {
		owner_guess.child_guess->Slot34_guess();
	}
	DespawnOtherCharacters_guess();
	flag_1e2_guess = 0;
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->flag_0005_guess = 0;
	if (EQ_GLOBAL(GlobalOptions_guess*, 0x00905CE4) != 0) {
		EQ_GLOBAL(GlobalOptions_guess*, 0x00905CE4)->value_0058_guess = 0.0f;
		EQ_GLOBAL(GlobalOptions_guess*, 0x00905CE4)->value_0048_guess = 0.0f;
	}
	int selection_guess = value_1e8_guess;
	EQ_GLOBAL(Settings_guess*, 0x00988DF0)->SetupCharSelectCamera_guess();
	Slot48_guess(1, 1);
	SelectCharacter_guess(selection_guess, 1);
	((StateHolder_guess*)this)->SetExploreCommandsEnabled_guess(0);
}

// Moves a select-screen player to the preview spot (0x9917BC-0x9917C8, 1 unit up), then CDisplay's
// Configure_guess(12) and Refresh_guess, probably to re-aim the camera.
// FUNCTION: TITANIUM 0x004F109D
void __stdcall PlaceAtPreviewSpot_guess(ObjectState_guess* object_guess, char complete_guess,
	int unused_guess)
{
	int state_guess = EQ_GLOBAL(int, 0x009917BC);
	float value_guess = EQ_GLOBAL(float, 0x009917C4) + 1.0f;
	object_guess->value_0034_guess = EQ_GLOBAL(float, 0x009917C0);
	object_guess->value_0030_guess = state_guess;
	object_guess->value_0038_guess = value_guess;
	object_guess->value_004c_guess = EQ_GLOBAL(int, 0x009917C8);
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->SetDayPeriod_guess(0xc, 0);
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->SetSunLight_guess();
	if (complete_guess != 0) {
		object_guess->PlaceOnFloor_guess();
	}
}

// Stands character `index_guess` on its explore-mode spot: one of 8 in a ring (table 0x791E58, 16-byte
// entries with the position and heading).
// FUNCTION: TITANIUM 0x004F10F6
void StateSetup_guess::PlaceAtExploreSpot_guess(int index_guess, ObjectState_guess* object_guess)
{
	GlobalOptions_guess* options_guess = EQ_GLOBAL(GlobalOptions_guess*, 0x00905CE4);
	PlaceAtPreviewSpot_guess(object_guess, 0, options_guess->flag_0252_guess);
	object_guess->value_0038_guess += 4.0f;
	float value_guess = EQ_ARRAY(StateEntry_guess, 0x00791E58)[index_guess].value_0008_guess + 1.0f;
	float previous_guess = EQ_ARRAY(StateEntry_guess, 0x00791E58)[index_guess].value_0004_guess;
	object_guess->value_0030_guess = EQ_ARRAY(StateEntry_guess, 0x00791E58)[index_guess].value_0000_guess;
	object_guess->value_0034_guess = previous_guess;
	object_guess->value_0038_guess = value_guess;
	object_guess->value_004c_guess = EQ_ARRAY(StateEntry_guess, 0x00791E58)[index_guess].value_000c_guess;
	object_guess->Attach_guess(EQ_GLOBAL(void*, 0x00905CE4));
	object_guess->PlaceOnFloor_guess();
	object_guess->Finish_guess();
}

// Scalar deleting destructor.
// FUNCTION: TITANIUM 0x004F14D4
void* CCharacterSelectView_guess::Delete_guess(unsigned char flags_guess)
{
	this->CCharacterSelectView_guess::~CCharacterSelectView_guess();
	if ((flags_guess & 1) != 0) {
		free(this);
	}
	return this;
}

struct ExploreMode_guess : OwnedChild_guess {
	// EXTERNAL: TITANIUM 0x004FFFD0 ExploreMode_guess::ExploreMode_guess
	ExploreMode_guess(int value_guess);
	char unknown_0004_guess[0x160];
};

struct ButtonVirtuals_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
	virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
	virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
	virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
	virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(int first_guess, int second_guess);
};

// Finds the buttons by sidl name (Explore, Rotate, Enter_World, Delete, Quit, Tutorial, Go_Home,
// Char1-8). Tutorial and Go Home are hidden when the OP_LogServer flag 0x923D66 is set.
// FUNCTION: TITANIUM 0x004F116C
// @early-stop: budget, structural ndiff=18
CCharacterSelectView_guess::CCharacterSelectView_guess(CXWnd* parent_guess)
	: CharacterCreatePrimary_guess(parent_guess, "CharacterSelectWindow")
{
	child_guess = 0;
	owner_guess.child_guess = 0;
	tutorialButton_guess = 0;
	enterButton_guess = 0;
	goHomeButton_guess = 0;
	deleteButton_guess = 0;
	quitButton_guess = 0;
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		children_guess[index_guess] = 0;
	}
	flag_1e2_guess = 0;
	flag_1e0_guess = 1;
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		children_guess[index_guess] = 0;
	}
	if (sidlPiece_0124_guess != 0) {
		style_0064_guess |= sidlPiece_0124_guess->flags_0060_guess | 0x800;
		CreateChildrenFromSidl();
		exploreButton_guess = GetChildItem("Explore_Button");
		rotateButton_guess = GetChildItem("Rotate_Button");
		enterButton_guess = GetChildItem("Enter_World_Button");
		deleteButton_guess = GetChildItem("Delete_Button");
		quitButton_guess = GetChildItem("Quit_Button");
		tutorialButton_guess = GetChildItem("Tutorial_Button");
		goHomeButton_guess = GetChildItem("Go_Home_Button");
		int count_guess = 0;
		NamedChild_guess** slot_guess = children_guess;
		char name_guess[0x100];
		do {
			++count_guess;
			sprintf(name_guess, "Char%d_Button", count_guess);
			*slot_guess = (NamedChild_guess*)GetChildItem(name_guess);
			++slot_guess;
		} while (count_guess < 8);
		if (EQ_GLOBAL(char, 0x00923D66) != 0) {
			if (goHomeButton_guess != 0) {
				((ButtonVirtuals_guess*)goHomeButton_guess)->Slot48_guess(0, 1);
			}
			if (tutorialButton_guess != 0) {
				((ButtonVirtuals_guess*)tutorialButton_guess)->Slot48_guess(0, 1);
			}
		}
		EnableIniStorage(0, 0);
		name_019c_guess[0] = 0;
		Initialize_guess();
		owner_guess.child_guess = new ExploreMode_guess(0);
	}
}

struct ResourceHolder_guess {
	int unknown_0000_guess;
	void* item_guess;
};

struct ResourceGlobal_guess {
	char unknown_0000_guess[0x1a8];
	ResourceHolder_guess* holder_guess;
};

// Enter World: sets +0x1F0 and calls virtual slot 34 (probably closes the window). +0x1F4 marks a
// tutorial entry, +0x1F8 (set by the caller) a Go Home entry; the 0x923D66 flag makes every entry a
// tutorial entry.
// FUNCTION: TITANIUM 0x004F14F0
void CCharacterSelectView_guess::Enter_guess()
{
	if (pinstCSystemInfoDialogBox_guess == 0 ||
		pinstCSystemInfoDialogBox_guess->IsVisible_guess() == 0) {
		if (EQ_GLOBAL(char, 0x009254EE) != 0) {
			EQ_GLOBAL(Settings_guess*, 0x00988DF0)->SendSystemInfo_guess();
		}
		if (((StateHolder_guess*)this)->IsInRange_guess()) {
			if (EQ_GLOBAL(ResourceGlobal_guess*, 0x00905CE4)->holder_guess->item_guess != 0) {
				EQ_GLOBAL(StateManager_guess*, 0x00905D24)->DeleteLight_guess(
					EQ_GLOBAL(ResourceGlobal_guess*, 0x00905CE4)->holder_guess->item_guess);
				EQ_GLOBAL(ResourceGlobal_guess*, 0x00905CE4)->holder_guess->item_guess = 0;
			}
			EQ_GLOBAL(float, 0x009254D0) = (float)EQ_GLOBAL(int, 0x009249AC) * 0.2f;
			if (EQ_GLOBAL(float, 0x009254D0) < 0.1f) {
				EQ_GLOBAL(float, 0x009254D0) = 0.1f;
			}
			value_1f0_guess = 1;
			if (EQ_GLOBAL(char, 0x00923D66) != 0) {
				value_1f4_guess = 1;
			}
			this->Slot34_guess();
		}
	}
}

// Confirmation box answers (button bits 5 = yes, probably): 101 is Go Home, 100 is Delete.
// FUNCTION: TITANIUM 0x004F18C3
void CCharacterSelectView_guess::OnConfirmation_guess(int event_guess,
	unsigned char flags_guess, int unused_guess)
{
	switch (event_guess) {
	case 101:
		if ((flags_guess & 5) != 0) {
			flag_1f8_guess = 1;
			Enter_guess();
		}
		break;
	case 100:
		if ((flags_guess & 5) != 0) {
			((StateHolder_guess*)this)->DeleteCharacter_guess();
		}
		break;
	}
}

struct ChildSlot_guess {
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess();
	virtual void Slot05_guess(int value_guess);
};

struct ChildHolder_guess {
	int unknown_0000_guess;
	ChildSlot_guess* slot_guess;
};

struct StateChild_guess {
	// EXTERNAL: TITANIUM 0x004850A0 StateChild_guess::StateChild_guess
	StateChild_guess(int zero_guess, unsigned char first_guess, int second_guess,
		unsigned char third_guess, const char* name_guess);
	// EXTERNAL: TITANIUM 0x0047E619 StateChild_guess::CreateUserLight_guess
	ChildSlot_guess* CreateUserLight_guess(int value_guess, int count_guess);
	// EXTERNAL: TITANIUM 0x0047C3EF StateChild_guess::SetName_guess
	void SetName_guess(const char* name_guess);
	// EXTERNAL: TITANIUM 0x0047A741 StateChild_guess::SetRace_guess
	void SetRace_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x0047D776 StateChild_guess::RefreshNameSprite_guess
	void RefreshNameSprite_guess();
	char unknown_0000_guess[0x1a8];
	ChildHolder_guess* holder_guess;
	char unknown_01ac_guess[0x58];
	int value_0204_guess;
	char unknown_0208_guess[0x41];
	unsigned char byte_0249_guess;
	char unknown_024a_guess[2];
	unsigned char level_024c_guess;
	char unknown_024d_guess[5];
	unsigned char byte_0252_guess;
	char unknown_0253_guess[0x2d];
	unsigned int deity_0280_guess;
	char unknown_0284_guess[0xc4];
};

struct CreateSlots_guess {
	char unknown_0000_guess[0x39410];
	int ints_39410_guess[8];
	char unknown_39430_guess[0x39438 - 0x39430];
	int ints_39438_guess[9];
	char unknown_3945c_guess[0x395b4 - 0x3945c];
	int ints_395b4_guess[9];
	char unknown_395d8_guess[0x3971c - 0x395d8];
	int ints_3971c_guess;
	char unknown_39720_guess[0x397a0 - 0x39720];
	int ints_397a0_guess;
	char unknown_397a4_guess[0x397d4 - 0x397a4];
	int ints_397d4_guess[8];
	char unknown_397f4_guess[8];
	unsigned char bytes_397fc_guess[8];
	char unknown_39804_guess[0xc];
	char names_guess[8][0x40];
	char unknown_39a10_guess[0x80];
	unsigned char bytes_39a90_guess[8];
	char unknown_39a98_guess[0x16];
	unsigned char bytes_39aae_guess[8];
	// EXTERNAL: TITANIUM 0x00493512 CreateSlots_guess::Attach_guess
	void Attach_guess(StateChild_guess* child_guess, int index_guess, int flag_guess);
};

// Explore mode: spawns every other character on its ring spot with its race, class, gender, level and
// zone.
// FUNCTION: TITANIUM 0x004F15B0
void CCharacterSelectView_guess::SpawnOtherCharacters_guess()
{
	for (int index_guess = 0; index_guess < 8; ++index_guess) {
		if (index_guess != value_1e8_guess) {
			if (((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess) == 0) {
				StateChild_guess* child_guess = new StateChild_guess(0,
					EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_39a90_guess[index_guess],
					EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_39410_guess[index_guess],
					EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_397fc_guess[index_guess],
					EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->names_guess[index_guess]);
				child_guess->level_024c_guess = EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_39aae_guess[index_guess];
				child_guess->value_0204_guess = EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_397d4_guess[index_guess];
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->Attach_guess(child_guess, index_guess, 1);
				child_guess->holder_guess->slot_guess = child_guess->CreateUserLight_guess(
					EQ_GLOBAL(StateManager_guess*, 0x00905D24)->value_2878_guess, 0x14);
				child_guess->holder_guess->slot_guess->Slot05_guess(1);
				((StateSetup_guess*)this)->PlaceAtExploreSpot_guess(index_guess, (ObjectState_guess*)child_guess);
			}
		}
	}
}

struct PlayerOps_guess {
	// EXTERNAL: TITANIUM 0x0047A741 PlayerOps_guess::SetRace_guess
	void SetRace_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x004798D7 PlayerOps_guess::GetActorTag_guess
	void GetActorTag_guess(char* buffer_guess);
	// EXTERNAL: TITANIUM 0x0047A3EB PlayerOps_guess::SetArmorType_guess
	void SetArmorType_guess(int index_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x0047A406 PlayerOps_guess::SetArmorTint_guess
	void SetArmorTint_guess(int index_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x0047DEC4 PlayerOps_guess::SwapFace_guess
	void SwapFace_guess(int face_guess, int value_guess);
	// EXTERNAL: TITANIUM 0x0047FA9E PlayerOps_guess::SetHeights_guess
	void SetHeights_guess();
	// EXTERNAL: TITANIUM 0x0047CC37 PlayerOps_guess::SetSounds_guess
	void SetSounds_guess();
};

struct AppearanceObj_guess {
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
	virtual void Slot20_guess(float value_guess, int flag_guess);
};

struct ActorInfo_guess {
	AppearanceObj_guess* pAppearance_guess;     // 0x00
	char unknown_0004_guess[0x64];
	int value_0068_guess;                       // 0x68
	char unknown_006c_guess[0xc4 - 0x6c];
	float value_00c4_guess;                     // 0xc4
	char unknown_00c8_guess[0x10c0 - 0xc8];
	// EXTERNAL: TITANIUM 0x0048F023 ActorInfo_guess::ActorInfo_guess
	ActorInfo_guess(const char* name_guess);
	// EXTERNAL: TITANIUM 0x0048F4A4 ActorInfo_guess::~ActorInfo_guess
	~ActorInfo_guess();
	// EXTERNAL: TITANIUM 0x0048F019 ActorInfo_guess::IsReady_guess
	char IsReady_guess();
};

struct NameResource_guess {
	// EXTERNAL: TITANIUM 0x004849B2 NameResource_guess::~NameResource_guess
	~NameResource_guess();
};

// EXTERNAL: TITANIUM 0x0047C88E FindNameResource_guess
void* __cdecl FindNameResource_guess(const char* name_guess);

// Deletes the players SpawnOtherCharacters_guess spawned (found by name), never the preview player.
// FUNCTION: TITANIUM 0x004F16CD
// @early-stop: budget, diff ndiff=13
void CCharacterSelectView_guess::DespawnOtherCharacters_guess()
{
	int index_guess = 0;
	int offset_guess = 0;
	if (EQ_GLOBAL(int, 0x00905CC4) != 0) {
		do {
			if (index_guess != value_1e8_guess &&
				!((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess)) {
				NameResource_guess* resource_guess = (NameResource_guess*)FindNameResource_guess(
					EQ_GLOBAL(char*, 0x00988DF0) + 0x39810 + offset_guess);
				if (resource_guess != 0 &&
					resource_guess != EQ_GLOBAL(NameResource_guess*, 0x00905CE4)) {
					delete resource_guess;
				}
			}
			offset_guess += 0x40;
			++index_guess;
		} while (offset_guess < 0x200);
	}
}

// Gives a select-screen player a new gender, class and face: the actor definition is rebuilt
// (GetActorTag_guess + "_ACTORDEF") and the 9 visible equipment slots are emptied. The preview player
// is also re-attached to the camera.
// FUNCTION: TITANIUM 0x004F1733
void __stdcall RebuildPlayerActor_guess(EQPlayer* player_guess, unsigned char gender_guess, int level_guess,
	unsigned char face_guess, unsigned char class_guess)
{
	char name_guess[32];
	player_guess->Gender = gender_guess;
	((PlayerOps_guess*)player_guess)->SetRace_guess(level_guess + 1);
	player_guess->Class = class_guess;
	((PlayerOps_guess*)player_guess)->GetActorTag_guess(name_guess);
	strcat(name_guess, "_ACTORDEF");
	ActorInfo_guess* old_guess = (ActorInfo_guess*)player_guess->pActorInfo;
	player_guess->FaceHair = face_guess;
	if (old_guess != 0) {
		delete old_guess;
	}
	ActorInfo_guess* info_guess = new ActorInfo_guess(name_guess);
	player_guess->pActorInfo = info_guess;
	player_guess->AvatarHeight = -1.0f;
	((PlayerOps_guess*)player_guess)->SetHeights_guess();
	((PlayerOps_guess*)player_guess)->SetSounds_guess();
	((ActorInfo_guess*)player_guess->pActorInfo)->value_0068_guess = 0;
	for (int i_guess = 0; i_guess < 9; ++i_guess) {
		((PlayerOps_guess*)player_guess)->SetArmorType_guess(i_guess, 0);
		((PlayerOps_guess*)player_guess)->SetArmorTint_guess(i_guess, 0);
	}
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->Attach_guess(player_guess);
	((ActorInfo_guess*)player_guess->pActorInfo)->value_0068_guess = 0;
	((PlayerOps_guess*)player_guess)->SwapFace_guess(player_guess->FaceHair, 0);
	if (((ActorInfo_guess*)player_guess->pActorInfo)->pAppearance_guess != 0 &&
		((ActorInfo_guess*)player_guess->pActorInfo)->IsReady_guess() != 0) {
		player_guess->AvatarHeight = -1.0f;
		((PlayerOps_guess*)player_guess)->SetHeights_guess();
		ActorInfo_guess* info_guess = (ActorInfo_guess*)player_guess->pActorInfo;
		info_guess->pAppearance_guess->Slot20_guess(info_guess->value_00c4_guess, 1);
	}
	if (player_guess == EQ_GLOBAL(EQPlayer*, 0x00905CE4)) {
		((ObjectState_guess*)player_guess)->PlaceOnFloor_guess();
		((ObjectState_guess*)player_guess)->Finish_guess();
		EQ_GLOBAL(StateManager_guess*, 0x00905D24)->Assign_guess(
			((ActorInfo_guess*)player_guess->pActorInfo)->pAppearance_guess);
		EQ_GLOBAL(StateManager_guess*, 0x00905D24)->SetupCharacterViewCamera_guess(0);
	}
}

// CCharacterSelect AboutToShow (vtable slot 49, the pre-show hook; true lets the window show): resets,
// labels the buttons and leaves explore mode.
// FUNCTION: TITANIUM 0x004F1979
bool CCharacterSelectView_guess::AboutToShow_guess()
{
	Initialize_guess();
	UpdateChildNames_guess();
	ResetChild_guess();
	if (flag_1e2_guess != 0) {
		LeaveExplorationMode_guess();
	}
	return true;
}

// Explore mode on: the other characters appear and the movement commands are enabled.
// FUNCTION: TITANIUM 0x004F19A3
void CCharacterSelectView_guess::EnterExplorationMode_guess()
{
	if (flag_1e2_guess != 0) {
		LeaveExplorationMode_guess();
	}
	flag_1e2_guess = 1;
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->flag_0005_guess = 1;
	EQ_GLOBAL(StateManager_guess*, 0x00905D24)->SetCameraMode_guess(0);
	SpawnOtherCharacters_guess();
	Slot48_guess(0, 1);
	if (owner_guess.child_guess != 0) {
		owner_guess.child_guess->Slot33_guess();
	}
	((StateHolder_guess*)this)->SetExploreCommandsEnabled_guess(1);
}

// `selection_guess` is a slot, or 1000 next, 1001 previous, 1002 restore (the remembered name, else
// eqclient.ini LastCharSel). Then dresses the preview player as that character; with no character it
// shows string 4000 as a level-1 Human Warrior.
// FUNCTION: TITANIUM 0x004F1A03
// @early-stop: budget, structural ndiff=39
void CCharacterSelectView_guess::SelectCharacter_guess(int selection_guess, int enabled_guess)
{
	char was_active_guess = flag_1e2_guess;
	if (was_active_guess != 0) {
		LeaveExplorationMode_guess();
	}
	if (children_guess[0] == 0) {
		return;
	}
	if (((ChildState_guess*)children_guess[0])->enabled_guess == 0) {
		return;
	}
	int index_guess = selection_guess;
	if (selection_guess == 0x3e8) {
		index_guess = value_1e8_guess + 1;
		if (index_guess >= 8 || index_guess < 0 ||
			((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess) != 0) {
			index_guess = 0;
		}
	} else if (selection_guess == 0x3e9) {
		index_guess = value_1e8_guess - 1;
		if (index_guess >= 8) {
			index_guess = 0;
		} else if (index_guess < 0) {
			index_guess = 7;
			while (((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess) != 0) {
				--index_guess;
				if (index_guess < 0) {
					index_guess = 0;
					break;
				}
			}
		}
	} else if (selection_guess == 0x3ea) {
		if (name_019c_guess[0] != 0) {
			index_guess = 0;
			int scan_guess = 0;
			for (NamedChild_guess** first_guess = &children_guess[scan_guess];
				scan_guess < 8; ++scan_guess, ++first_guess) {
				if (*first_guess != 0 &&
					((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(scan_guess) == 0 &&
					strcmp(EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[scan_guess],
						name_019c_guess) == 0) {
					index_guess = scan_guess;
					break;
				}
			}
		} else {
			char value_guess[32];
			// An invalid LastCharSel is cleared from the ini.
			FUN_0060be50_guess("Defaults", "LastCharSel", "*NULL*", value_guess, 0x20,
				".\\eqclient.ini");
			if (value_guess[0] != '*') {
				index_guess = atoi(value_guess);
				if (index_guess < 0 || index_guess >= 8 ||
					((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(index_guess) != 0) {
					index_guess = 0;
					FUN_0060beb0_guess("Defaults", "LastCharSel", "", ".\\eqclient.ini");
				}
			} else {
				index_guess = 0;
				FUN_0060beb0_guess("Defaults", "LastCharSel", "", ".\\eqclient.ini");
			}
		}
	}
	if (index_guess == 0 && ((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(0) != 0) {
		index_guess = -1;
	}
	value_1e8_guess = index_guess;
	for (int child_index_guess = 0; child_index_guess < 8; ++child_index_guess) {
		if (children_guess[child_index_guess] != 0) {
			((ChildState_guess*)children_guess[child_index_guess])->SetCheck(
				child_index_guess == value_1e8_guess);
		}
	}
	if (EQ_GLOBAL(StateChild_guess*, 0x00905CE4) != 0 && enabled_guess != 0) {
		if (((StateHolder_guess*)this)->IsInRange_guess()) {
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->SetName_guess(
				EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[value_1e8_guess]);
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->byte_0252_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_397fc_guess[value_1e8_guess];
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->level_024c_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_39aae_guess[value_1e8_guess];
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->deity_0280_guess =
				EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.mappedIds_guess[value_1e8_guess];
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->value_0204_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_397d4_guess[value_1e8_guess];
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->Attach_guess(
				EQ_GLOBAL(StateChild_guess*, 0x00905CE4), value_1e8_guess, 1);
			value_1f4_guess = 0;
			flag_1f8_guess = 0;
		} else {
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->SetName_guess(
				pStringTable->getString(4000, 0));
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_39410_guess[0] = 1;
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_397fc_guess[0] = 1;
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_39aae_guess[0] = 1;
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_397d4_guess[0] = 1;
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_397a0_guess |= -1;
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_3971c_guess |= -1;
			for (int slot_index_guess = 0; slot_index_guess < 9; ++slot_index_guess) {
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_395b4_guess[slot_index_guess] = 0;
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_39438_guess[slot_index_guess] = 0;
			}
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->byte_0252_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_397fc_guess[0];
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->level_024c_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->bytes_39aae_guess[0];
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->SetRace_guess(3);
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->byte_0249_guess = 1;
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->RefreshNameSprite_guess();
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->value_0204_guess =
				EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->ints_397d4_guess[0];
			EQ_GLOBAL(CreateSlots_guess*, 0x00988DF0)->Attach_guess(
				EQ_GLOBAL(StateChild_guess*, 0x00905CE4), 0, 1);
		}
		if (EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->holder_guess->slot_guess == 0) {
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->holder_guess->slot_guess =
				EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->CreateUserLight_guess(
					EQ_GLOBAL(StateManager_guess*, 0x00905D24)->value_2878_guess, 0x4b);
			EQ_GLOBAL(StateChild_guess*, 0x00905CE4)->holder_guess->slot_guess->Slot05_guess(1);
		}
		PlaceAtPreviewSpot_guess((ObjectState_guess*)EQ_GLOBAL(StateChild_guess*, 0x00905CE4), 1, -1);
		if (was_active_guess != 0) {
			EnterExplorationMode_guess();
		}
	}
}

// Restores the last selection when show_005c_guess is set, then Finish_guess (0x5A1880, window base code).
// FUNCTION: TITANIUM 0x004F1E5E
void CCharacterSelectView_guess::Slot35_guess()
{
	if (show_005c_guess != 0) {
		SelectCharacter_guess(0x3ea, 1);
	}
	OnShow();
}

// Button clicks (mode 1). Delete and Go Home open confirmation boxes 100 and 101 (strings 9065 and 6137
// with the name; answered in HandleEvent_guess) and disable the buttons. Rotate toggles and saves
// CharCreateRotateOn; an empty Char button sets +0x1E4, probably to open character creation.
// FUNCTION: TITANIUM 0x004F1F72
int CCharacterSelectView_guess::WndNotification_guess(int target_guess, int mode_guess, int unused_guess)
{
	char buffer_guess[512];
	if (mode_guess != 1) {
		return 0;
	}
	StateFlags_guess* flags_guess = (StateFlags_guess*)this;
	if (target_guess == (int)flags_guess->state_188_guess) {
		Enter_guess();
		return 0;
	}
	if (target_guess == (int)flags_guess->state_18c_guess) {
		FormatText_guess(buffer_guess, 0x2369,
			EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[value_1e8_guess],
			0, 0, 0, 0, 0, 0, 0, 0);
		EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)->Activate(
			EQ_GLOBAL(unsigned int, 0x00850B9C) != 0
				? EQ_GLOBAL(unsigned int, 0x00850B9C) + 0x15c
				: 0,
			100, buffer_guess, 0xc, 10000, 0, 1);
		flags_guess->EnableButtons_guess(0);
		return 0;
	} else if (target_guess == flags_guess->unknown_0190_guess) {
		((StateHolder_guess*)this)->Quit_guess();
		return 0;
	} else if (target_guess == (int)flags_guess->first_guess) {
		if (flag_1e2_guess == 0) {
			EnterExplorationMode_guess();
		} else {
			LeaveExplorationMode_guess();
		}
		return 0;
	} else if (target_guess == (int)flags_guess->state_194_guess) {
		value_1f4_guess = 1;
		Enter_guess();
	} else if (target_guess == (int)flags_guess->state_198_guess) {
		FormatText_guess(buffer_guess, 0x17f9,
			EQ_GLOBAL(NameStorage_guess*, 0x00988DF0)->fields_guess.names_guess[value_1e8_guess],
			0, 0, 0, 0, 0, 0, 0, 0);
		EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)->Activate(
			EQ_GLOBAL(unsigned int, 0x00850B9C) != 0
				? EQ_GLOBAL(unsigned int, 0x00850B9C) + 0x15c
				: 0,
			101, buffer_guess, 0xc, 10000, 0, 1);
		flags_guess->EnableButtons_guess(0);
	} else if (target_guess == flags_guess->unknown_0164_guess) {
		unsigned char* flag_guess = (unsigned char*)&rotate_guess;
		*flag_guess ^= 1;
		EQ_GLOBAL(Settings_guess*, 0x00988DF0)->Set_guess(*flag_guess,
			"Defaults", "CharCreateRotateOn");
		return 0;
	} else {
		for (mode_guess = 0; mode_guess < 8; ++mode_guess) {
			if (target_guess == (int)flags_guess->states_guess[mode_guess]) {
				if (((NameTable_guess*)this)->IsCharacterSlotEmpty_guess(mode_guess) != 0) {
					flag_1e4_guess = 1;
				} else {
					SelectCharacter_guess(mode_guess, 1);
				}
			}
		}
	}
	return 0;
}

