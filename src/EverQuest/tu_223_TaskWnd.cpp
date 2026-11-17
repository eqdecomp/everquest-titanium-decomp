// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 223: a hint from compare/tumap.py.
// CTaskWnd ("TaskWnd"): active tasks (1 task, 1 shared task, 19 quests; types 0, 1, 2 as in EQEmu), quest
// history (50) and shared task members. CTaskWndView_guess, LayoutOwner_guess and Object_guess are views of
// it; Timer_guess is a task definition (+0 id, +4 title, +0x44 duration in s, +0x940 20 activities of
// 0x124), and 0x79DC78 the task manager. Rows are 0x50 bytes: index, type, task id, seconds left, title.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include <string.h>
#include <time.h>
#include "titanium/wnd/CTaskTemplateSelectWnd.h"

#define g_nameTable_guess EQ_ARRAY(const char*, 0x007948A4)

struct CompareRecord_guess {
	unsigned char pad_000[0x0c];
	int field_00c_guess;
	char text_010_guess[1];
};

struct Object_guess {
	unsigned char pad_000[0x845];
	unsigned char field_845_guess;
	unsigned char pad_846[0x46];
	unsigned char field_88c_guess;

	void RequestRefresh_guess();
};

struct PaletteEntry_guess {
	unsigned char pad_000[0x04];
	int mode_004_guess;
	unsigned char pad_008[0x04];
	unsigned int size_00c_guess;
	char text_010_guess[1];
};

struct Record_guess {
	int first_guess;
	int second_guess;
	unsigned char pad_008_guess[0x14];
	int values_01c_guess[0x14];
};

struct TaskDefinition_guess {
	int value_000_guess;
	char text_004_guess[0x40];
	int duration_044_guess;
	unsigned char pad_048_guess[0x8f8];
	struct TimerOption_guess {
		int mode_000_guess;
		unsigned char pad_004_guess[4];
		char text_008_guess[0x80];
		int id_088_guess;
		unsigned char pad_08c_guess[8];
		int maximum_094_guess;
		unsigned char pad_098_guess[0x8c];
	} options_940_guess[0x14];
};

struct Container_guess {
	unsigned char pad_000[0x11c];
	int count_11c_guess;

	// EXTERNAL: TITANIUM 0x00597ED0 Container_guess::GetRecord_guess
	Record_guess* GetRecord_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x00597ED0 Container_guess::GetItemData_guess
	unsigned int GetItemData_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x00597BE0 Container_guess::Current_guess
	int Current_guess();
	// EXTERNAL: TITANIUM 0x0059B3E0 Container_guess::SetItemColor_guess
	void SetItemColor_guess(int row_guess, int column_guess, unsigned int color_guess);
};

struct StateObject_guess {
	unsigned char pad_000[0x5d];
	unsigned char state_05d_guess;
};

struct CTaskWndView_guess {
	unsigned char pad_000[0x16c];
	Container_guess* container_16c_guess;
	unsigned char pad_170_guess[0x04];
	StateObject_guess* object_174_guess;

	char GetValues_guess(int index_guess, int* first_out_guess, int* second_out_guess);
	int AddEntry_guess(PaletteEntry_guess* entry_guess);
	void UpdateTimers_guess(unsigned int now_guess);
	void SendCancelTask_guess();
	void UpdateTime_guess(int row_guess, PaletteEntry_guess* entry_guess, unsigned int now_guess,
		TaskDefinition_guess* timer_guess, Record_guess* record_guess);
};

struct LayoutLookup_guess {
	// EXTERNAL: TITANIUM 0x00572300 LayoutLookup_guess::Find_guess
	char* Find_guess(const char* name_guess);
};

struct Element_guess {
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
	virtual void SetLayout_guess(char* text_guess);
	virtual void SetLayout2_guess(char* text_guess);
};

struct LayoutOwner_guess {
	unsigned char pad_000[0x120];
	LayoutLookup_guess lookup_120_guess;
	unsigned char pad_121[0x4b];
	void* task_16c_guess;
	void* elements_170_guess;
	unsigned char pad_174[0x08];
	Element_guess* element_17c_guess;

	// EXTERNAL: TITANIUM 0x005A1EF0 LayoutOwner_guess::LoadIniListWnd
	void LoadIniListWnd(void* value_guess, const char* name_guess);
	// EXTERNAL: TITANIUM 0x005A1FE0 LayoutOwner_guess::StoreIniListWnd_guess
	void StoreIniListWnd_guess(void* value_guess, const char* name_guess);

	void LoadIniSettings_guess();
	void StoreIniSettings_guess();
};

#define g_connection_guess EQ_GLOBAL(int, 0x00905CA0)

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();

struct WndPrimary_guess {
	unsigned char pad_004_guess[0x58];
	unsigned char show_005c_guess;
	unsigned char pad_05d_guess[0x66 - 0x5d];
	// EXTERNAL: TITANIUM 0x005A3850 ??0WndPrimary_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
	WndPrimary_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int iniVersion_guess,
		char* blockName_guess);
	unsigned char flags_066_guess;
	unsigned char pad_067_guess[0x124 - 0x67];
	void* sidlPiece_124_guess;
	unsigned char pad_128_guess[0x158 - 0x128];
	int field_158_guess;
	// EXTERNAL: TITANIUM 0x005A3100 WndPrimary_guess::~WndPrimary_guess
	virtual ~WndPrimary_guess();
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7ActionSecondary_guess@@6B@
struct ActionSecondary_guess {
	// EXTERNAL: TITANIUM 0x005482A0 ActionSecondary_guess::Reset_guess
	void Reset_guess(int value_guess);
	void OnConfirmAbandon_guess(int value_guess, unsigned char flags_guess, int ignored_guess);
	virtual void RefreshCounts_guess();
	virtual ~ActionSecondary_guess() {
		Reset_guess(-1);
	}
};

struct TextMember_guess {
	int ptr_000_guess;

	TextMember_guess() : ptr_000_guess(0) {}
	// EXTERNAL: TITANIUM 0x004482FB TextMember_guess::~TextMember_guess
	~TextMember_guess();
};

struct Pulse_guess {
	int field_000_guess;
	int field_004_guess;
	int field_008_guess;
	float y_000c_guess;
	float x_0010_guess;
	float z_0014_guess;

	// EXTERNAL: TITANIUM 0x004F9BD2 Pulse_guess::IsActive_guess
	char IsActive_guess();
	// EXTERNAL: TITANIUM 0x00446318 Pulse_guess::Pulse_guess
	Pulse_guess();
};

struct PulseController_guess {
	// EXTERNAL: TITANIUM 0x004F9DA6 PulseController_guess::Reset_guess
	void Reset_guess(Pulse_guess* pulse_guess);
	// EXTERNAL: TITANIUM 0x004FA167 PulseController_guess::AddMarker_guess
	void AddMarker_guess(Pulse_guess* pulse_guess);
};
#define pinstCCompassWnd_guess EQ_GLOBAL(PulseController_guess*, 0x00850C88)

struct PlayerInfo_guess {
	unsigned char pad_000_guess[0x30];
	float x_030_guess;
	float y_034_guess;
	float z_038_guess;
	unsigned char pad_03c_guess[0xe4];
	char name_120_guess[0x40];
	unsigned char pad_160_guess[0xb4];
	PlayerInfo_guess* next_214_guess;
	unsigned char pad_218_guess[0x2c];
	char type_0244_guess;
};
#define g_playerList_guess EQ_GLOBAL(PlayerInfo_guess*, 0x00905CC4)
#define g_zoneId_guess EQ_GLOBAL(int, 0x00924470)

// EXTERNAL: TITANIUM 0x00574790 FUN_00574790_guess
void __cdecl FUN_00574790_guess(const char* source_guess, char* destination_guess, int size_guess);
// EXTERNAL: TITANIUM 0x0060E590 FUN_0060e590_guess
int __cdecl FUN_0060e590_guess(const char* left_guess, const char* right_guess);

struct TaskInfo_guess;

// EXTERNAL: TITANIUM 0x0065DE10 ??_7CTaskWnd_guess@@6BWndPrimary_guess@@@
// EXTERNAL: TITANIUM 0x0065DE08 ??_7CTaskWnd_guess@@6BActionSecondary_guess@@@
struct CTaskWnd_guess : WndPrimary_guess, ActionSecondary_guess {
	CXWnd* subwindows_160_guess;
	CSidlScreenWnd* taskListPage_164_guess;
	CXWnd* taskDescription_168_guess;
	CXWnd* taskList_16c_guess;
	CXWnd* taskElements_170_guess;
	CXWnd* abandonButton_174_guess;
	CXWnd* monsterButton_178_guess;
	CXWnd* taskLayout_17c_guess;
	CSidlScreenWnd* questHistoryPage_180_guess;
	CXWnd* questTaskList_184_guess;
	CXWnd* questTaskElements_188_guess;
	CXWnd* questLayout_18c_guess;
	CSidlScreenWnd* sharedTaskPage_190_guess;
	CXWnd* memberList_194_guess;
	CXWnd* addPlayerButton_198_guess;
	CXWnd* removePlayerButton_19c_guess;
	CXWnd* makeLeaderButton_1a0_guess;
	unsigned char taskRows_01a4_guess[0x50];
	unsigned char questRows_01f4_guess[0x5f0];
	unsigned char sharedTaskRows_07e4_guess[0x50];
	int taskCount_0834_guess;
	int questCount_0838_guess;
	int sharedTaskCount_083c_guess;
	int sortColumn_0840_guess;
	unsigned char sortAscending_0844_guess;
	unsigned char needsRefresh_0845_guess;
	unsigned char pad_846_guess[2];
	int lastTimerUpdate_0848_guess;
	TextMember_guess text_84c_guess;
	int field_850_guess;
	Pulse_guess pulse_854_guess;
	unsigned char flag_86c_guess;
	unsigned char pad_86d_guess[0x884 - 0x86d];
	int selectedId_884_guess;
	int selectedOption_888_guess;
	unsigned char markerPending_088c_guess;

	CTaskWnd_guess(CXWnd* parent_guess);
	CTaskWnd_guess* Delete_guess(unsigned char flags_guess);
	~CTaskWnd_guess();
	void RefreshSharedTaskMembers_guess();
	void ProcessFrame_guess();
	// EXTERNAL: TITANIUM 0x0056043E CTaskWnd_guess::RefreshTasks_guess
	void RefreshTasks_guess();
	char AboutToShow_guess();
	void UpdateTaskTargetMarker_guess();
	int CollectTaskEntries_guess(void* buffer_guess, int mode_guess);
	// EXTERNAL: TITANIUM 0x0055F9A0 CTaskWnd_guess::SortTaskList_guess
	void SortTaskList_guess();
	// EXTERNAL: TITANIUM 0x0055F508 CTaskWnd_guess::FillQuestHistoryList_guess
	void FillQuestHistoryList_guess();
	// EXTERNAL: TITANIUM 0x0055F71D CTaskWnd_guess::FillTaskList_guess
	void FillTaskList_guess();
	void FillQuestHistory_guess(struct QuestHistory_guess* history_guess);
	void ShowTask_guess(struct TaskInfo_guess* task_guess, int arg_guess);
	// EXTERNAL: TITANIUM 0x0055ED77 CTaskWnd_guess::UpdateTask_guess
	void UpdateTask_guess(struct TaskInfo_guess* task_guess, Record_guess* record_guess);
	int HandleNotification_guess(CXWnd* sender_guess, int message_guess, int data_guess);
};

// Destructor of the task window (vtable 0x65DE10): destroys the string at +0x84C, expires every
// confirmation dialog its dialog-owner part (+0x15C) opened (0x005482A0, all messages), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0055E284
CTaskWnd_guess::~CTaskWnd_guess() {
}

// Task index and type of list row `index_guess`; false outside the list.
// FUNCTION: TITANIUM 0x0055E2E6
char CTaskWndView_guess::GetValues_guess(int index_guess, int* first_out_guess, int* second_out_guess) {
	char result_guess = 0;
	if (index_guess >= 0) {
		Container_guess* container_guess = container_16c_guess;
		if (index_guess < container_guess->count_11c_guess) {
			Record_guess* record_guess = container_guess->GetRecord_guess(index_guess);
			*second_out_guess = record_guess->second_guess;
			*first_out_guess = record_guess->first_guess;
			result_guess = 1;
		}
	}
	return result_guess;
}

struct QuestRecord_guess;
struct QuestEntry_guess;

// The task manager at 0x79DC78 (methods defined in tu_026; names are the definitions').
struct TaskManager_guess {
	// EXTERNAL: TITANIUM 0x0043235E TaskManager_guess::GetSlotCount_guess
	int GetSlotCount_guess(int mode_guess);
	// EXTERNAL: TITANIUM 0x00432D17 TaskManager_guess::GetRecord_guess
	Record_guess* GetRecord_guess(void* owner_guess, int first_guess, int second_guess);
	// EXTERNAL: TITANIUM 0x004322D2 TaskManager_guess::Get_guess
	TaskDefinition_guess* Get_guess(int first_guess, int second_guess, char allowEmpty_guess);
	// EXTERNAL: TITANIUM 0x004327E8 TaskManager_guess::HasPositive_guess
	char HasPositive_guess();
	// EXTERNAL: TITANIUM 0x004332E8 TaskManager_guess::BuildDescription_guess
	void BuildDescription_guess(TaskInfo_guess* task_guess, int arg_guess);
	// EXTERNAL: TITANIUM 0x00432477 TaskManager_guess::FormatActivityText_guess
	void FormatActivityText_guess(QuestRecord_guess* record_guess, char* out_guess);
	// EXTERNAL: TITANIUM 0x0043233F TaskManager_guess::At_guess
	QuestEntry_guess* At_guess(int index_guess);
};
#define g_taskManager_guess EQ_ARRAY(TaskManager_guess, 0x0079DC78)

struct SlotEntry_guess {
	int index_000_guess;
	int mode_004_guess;
	int value_008_guess;
	unsigned int size_00c_guess;
	char text_010_guess[0x40];
};

// Fills a row for every active task of type `mode_guess` (seconds left 100000000 = no limit); returns
// the count.
// FUNCTION: TITANIUM 0x0055E31A
int CTaskWnd_guess::CollectTaskEntries_guess(void* buffer_guess, int mode_guess) {
	int count_guess = 0;
	int total_guess = g_taskManager_guess->GetSlotCount_guess(mode_guess);
	int index_guess = 0;
	if (total_guess > 0) {
		int* slot_guess = (int*)buffer_guess + 3;
		do {
			Record_guess* record_guess = g_taskManager_guess->GetRecord_guess(pCharData, index_guess,
				mode_guess);
			if (record_guess->first_guess != 0) {
				TaskDefinition_guess* timer_guess = g_taskManager_guess->Get_guess(index_guess, mode_guess, 1);
				if (timer_guess != 0) {
					slot_guess[-3] = index_guess;
					slot_guess[0] = 100000000;
					slot_guess[-2] = mode_guess;
					slot_guess[-1] = timer_guess->value_000_guess;
					if (timer_guess->duration_044_guess != 0) {
						int now_guess = FUN_00576e80_guess();
						slot_guess[0] = 0;
						if (record_guess->second_guess + timer_guess->duration_044_guess > now_guess)
							slot_guess[0] = record_guess->second_guess + timer_guess->duration_044_guess - now_guess;
					}
					strcpy((char*)(slot_guess + 1), timer_guess->text_004_guess);
					count_guess++;
					slot_guess += 0x14;
				}
			}
			index_guess++;
		} while (index_guess < total_guess);
	}
	return count_guess;
}

// Points the compass window's marker (0x850C88) at the first NPC (Type 1) named by an unfinished deliver
// (1) or speak-with (4) activity of a task or shared task in this zone (0x924470), spaces read as '_';
// string 0x1793 announces a new target. The activity's zone 0 means any zone.
// FUNCTION: TITANIUM 0x0055E3E1
// @early-stop: unknown, structural ndiff=60
void CTaskWnd_guess::UpdateTaskTargetMarker_guess() {
	if (pinstCCompassWnd_guess != 0) {
		Pulse_guess* pulse_guess = &pulse_854_guess;
		int previousId_guess = 0;
		int previousOption_guess = -1;
		if (pulse_guess->IsActive_guess() != 0) {
			previousId_guess = selectedId_884_guess;
			previousOption_guess = selectedOption_888_guess;
			selectedOption_888_guess = -1;
			selectedId_884_guess = 0;
		}
		pinstCCompassWnd_guess->Reset_guess(pulse_guess);
		int mode_guess = 0;
		int row_guess = 0;
		do {
			int count_guess = g_taskManager_guess->GetSlotCount_guess(mode_guess);
			row_guess = 0;
			if (count_guess > 0) {
				do {
					Record_guess* record_guess = g_taskManager_guess->GetRecord_guess(
						pCharData, row_guess, mode_guess);
					int id_guess = record_guess->first_guess;
					if (id_guess != 0) {
						TaskDefinition_guess* timer_guess = g_taskManager_guess->Get_guess(row_guess, mode_guess, 1);
						if (timer_guess != 0) {
							int option_guess = 0;
							int* entryId_guess = &timer_guess->options_940_guess[0].id_088_guess;
							int* value_guess = record_guess->values_01c_guess;
						do {
							if ((entryId_guess[-0x22] == 4 || entryId_guess[-0x22] == 1) &&
								*value_guess < entryId_guess[3] &&
								(*entryId_guess == 0 || *entryId_guess == g_zoneId_guess)) {
								char targetName_guess[256];
								char playerName_guess[256];
								FUN_00574790_guess((const char*)(entryId_guess - 0x20), targetName_guess, 0x100);
								char* cursor_guess = targetName_guess;
								while (*cursor_guess != 0) {
									if (*cursor_guess == ' ')
										*cursor_guess = '_';
									cursor_guess++;
								}
								if (strlen(targetName_guess) > 0) {
									PlayerInfo_guess* player_guess = g_playerList_guess;
									while (player_guess != 0) {
										if (player_guess->type_0244_guess == 1) {
											FUN_00574790_guess(player_guess->name_120_guess, playerName_guess, 0x100);
											if (FUN_0060e590_guess(playerName_guess, targetName_guess) != 0)
												break;
										}
										player_guess = player_guess->next_214_guess;
									}
									if (player_guess != 0) {
										flag_86c_guess = 1;
										pulse_guess->y_000c_guess = player_guess->x_030_guess;
										pulse_guess->x_0010_guess = player_guess->y_034_guess;
										pulse_guess->z_0014_guess = player_guess->z_038_guess;
										pinstCCompassWnd_guess->AddMarker_guess(pulse_guess);
										selectedId_884_guess = id_guess;
										selectedOption_888_guess = option_guess;
										if (previousId_guess == id_guess && previousOption_guess == option_guess)
											return;
										pEverQuest->dsp_chat(pStringTable->getString(0x1793, 0), 0xf, 1);
										return;
									}
								}
							}
							option_guess++;
							entryId_guess += 0x49;
							value_guess++;
						} while (option_guess < 0x14);
					}
					}
					row_guess++;
				} while (row_guess < count_guess);
			}
			mode_guess++;
		} while (mode_guess <= 1);
	}
	markerPending_088c_guess = 0;
}

// Timer column of row `row_guess` as hh:mm:ss, string 0xD93 without a limit. Kept: the red test reads
// the task's whole duration (< 120 s), not the time left as GetColor_guess does.
// FUNCTION: TITANIUM 0x0055E645
void CTaskWndView_guess::UpdateTime_guess(int row_guess, PaletteEntry_guess* entry_guess, unsigned int now_guess,
	TaskDefinition_guess* timer_guess, Record_guess* record_guess) {
	char time_guess[256];
	unsigned int remaining_guess;
	const char* default_guess = pStringTable->getString(0xd93, 0);
	entry_guess->size_00c_guess = 100000000;
	strcpy(time_guess, default_guess);
	if (timer_guess->duration_044_guess != 0) {
		if (timer_guess->duration_044_guess < 0x78) {
			container_16c_guess->SetItemColor_guess(row_guess, 0, 0xffff0000);
			container_16c_guess->SetItemColor_guess(row_guess, 1, 0xffff0000);
			container_16c_guess->SetItemColor_guess(row_guess, 2, 0xffff0000);
		}
		entry_guess->size_00c_guess = 0;
		if (record_guess->second_guess + timer_guess->duration_044_guess > now_guess)
			entry_guess->size_00c_guess = record_guess->second_guess + timer_guess->duration_044_guess - now_guess;
		remaining_guess = entry_guess->size_00c_guess;
		sprintf(time_guess, "%02d:%02d:%02d", remaining_guess / 3600,
			(remaining_guess % 3600) / 60, remaining_guess % 60);
	}
	{
		CXStr text_guess(time_guess);
		EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)container_16c_guess)(
			row_guess, 2, text_guess);
	}
}

// Refreshes every row's timer; separator rows (data 0x40000000) are skipped.
// FUNCTION: TITANIUM 0x0055E784
void CTaskWndView_guess::UpdateTimers_guess(unsigned int now_guess) {
	if (container_16c_guess != 0) {
		int row_guess = 0;
		if (container_16c_guess->count_11c_guess > 0) {
			TaskManager_guess* table_guess = g_taskManager_guess;
			do {
				if (container_16c_guess->GetItemData_guess(row_guess) != 0x40000000) {
					Record_guess* item_guess = (Record_guess*)container_16c_guess->GetItemData_guess(row_guess);
					PaletteEntry_guess* entry_guess = (PaletteEntry_guess*)item_guess;
					Record_guess* record_guess = table_guess->GetRecord_guess(pCharData,
						item_guess->first_guess, item_guess->second_guess);
					TaskDefinition_guess* timer_guess = table_guess->Get_guess(item_guess->first_guess,
						item_guess->second_guess, 1);
					if (timer_guess != 0)
						UpdateTime_guess(row_guess, entry_guess, now_guess, timer_guess, record_guess);
				}
				row_guess++;
			} while (row_guess < container_16c_guess->count_11c_guess);
		}
	}
}

// Row colour by type: task yellow, shared task pink, quest white; red under 120 s left.
// FUNCTION: TITANIUM 0x0055E821
unsigned int __stdcall GetColor_guess(PaletteEntry_guess* entry_guess) {
	unsigned int color_guess = 0xffffffff;
	switch (entry_guess->mode_004_guess) {
	case 0:
		color_guess = 0xffdcdc80;
		break;
	case 1:
		color_guess = 0xffdc80dc;
		break;
	case 2:
		break;
	default:
		color_guess = 0xffffffff;
		break;
	}
	if (entry_guess->size_00c_guess < 0x78)
		color_guess = 0xffff0000;
	return color_guess;
}

// Adds a row (type name from 0x7948A4, title, time left) and returns its index.
// FUNCTION: TITANIUM 0x0055E850
int CTaskWndView_guess::AddEntry_guess(PaletteEntry_guess* entry_guess) {
	char time_guess[256];
	int row_guess;
	unsigned int color_guess = GetColor_guess(entry_guess);
	{
		CXStr name_guess(g_nameTable_guess[entry_guess->mode_004_guess]);
		row_guess = ((CListWnd*)container_16c_guess)->AddString(name_guess, color_guess, (unsigned int)entry_guess, 0);
	}
	{
		CXStr text_guess(entry_guess->text_010_guess);
		EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)container_16c_guess)(
			row_guess, 1, text_guess);
	}
	container_16c_guess->SetItemColor_guess(row_guess, 1, color_guess);
	if (entry_guess->size_00c_guess == 100000000) {
		strcpy(time_guess, pStringTable->getString(0xd93, 0));
	} else {
		sprintf(time_guess, "%02d:%02d:%02d", entry_guess->size_00c_guess / 3600,
			(entry_guess->size_00c_guess % 3600) / 60, entry_guess->size_00c_guess % 60);
	}
	{
		CXStr text_guess(time_guess);
		EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), (CListWnd*)container_16c_guess)(
			row_guess, 2, text_guess);
	}
	return row_guess;
}

struct TaskInfo_guess {
	unsigned char pad_000_guess[0x4c];
	char name_04c_guess[0x84c - 0x4c];
	char hasReward_84c_guess;
	unsigned char pad_84d_guess[3];
	int money_850_guess;
	int field_854_guess;
	int points_858_guess;
	unsigned char pad_85c_guess[0x8c0 - 0x85c];
	char text_8c0_guess[0x2010 - 0x8c0];
	int type_2010_guess;
	int subtype_2014_guess;
	char loaded_2018_guess;
	char show_2019_guess;
};

#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_space_guess EQ_ARRAY(char, 0x0063FDE4)
#define g_separator_guess EQ_ARRAY(char, 0x0063FE10)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, int id_guess, const char* text_guess,
	int zero1_guess, int zero2_guess, int zero3_guess, int zero4_guess, int zero5_guess,
	int zero6_guess, int zero7_guess, int zero8_guess);

// Description pane: title, then rewards (string 0xD95): money in copper split into pp/gp/sp/cp (strings
// 0x969-0x96C), string 0x8A when +0x854 is set, the reward text, and points named by string 0x22FD or
// 0x22FE (type 1, by +0x2014) or 0x4BF. The task text is loaded on first view.
// FUNCTION: TITANIUM 0x0055E9ED
void CTaskWnd_guess::ShowTask_guess(TaskInfo_guess* task_guess, int arg_guess) {
	CXStr text_guess;
	if (taskDescription_168_guess != 0) {
	if (task_guess != 0) {
		if (task_guess->show_2019_guess) {
			if (!task_guess->loaded_2018_guess)
				g_taskManager_guess->BuildDescription_guess(task_guess, arg_guess);
			text_guess = task_guess->name_04c_guess;
			text_guess += "<BR><BR>";
		}
		if (task_guess->hasReward_84c_guess) {
			text_guess += pStringTable->getString(0xd95, 0);
			int money_guess = task_guess->money_850_guess;
			if (money_guess > 0) {
				char all_guess[1024];
				char copper_guess[256];
				char platinum_guess[256];
				char gold_guess[256];
				char silver_guess[256];
				platinum_guess[0] = 0;
				int rest_guess = money_guess % 1000;
				int value_guess = money_guess / 1000;
				if (value_guess > 0) {
					FormatText_guess(platinum_guess, 0x969, _itoa(value_guess, g_itoaBuffer_guess, 10),
						0, 0, 0, 0, 0, 0, 0, 0);
					strcat(platinum_guess, g_space_guess);
				}
				value_guess = rest_guess / 100;
				gold_guess[0] = 0;
				if (value_guess > 0) {
					FormatText_guess(gold_guess, 0x96a, _itoa(value_guess, g_itoaBuffer_guess, 10),
						0, 0, 0, 0, 0, 0, 0, 0);
					strcat(gold_guess, g_space_guess);
				}
				silver_guess[0] = 0;
				value_guess = money_guess % 100 / 10;
				if (value_guess > 0) {
					FormatText_guess(silver_guess, 0x96b, _itoa(value_guess, g_itoaBuffer_guess, 10),
						0, 0, 0, 0, 0, 0, 0, 0);
					strcat(silver_guess, g_space_guess);
				}
				value_guess = money_guess % 10;
				copper_guess[0] = 0;
				if (value_guess > 0) {
					FormatText_guess(copper_guess, 0x96c, _itoa(value_guess, g_itoaBuffer_guess, 10),
						0, 0, 0, 0, 0, 0, 0, 0);
				}
				sprintf(all_guess, "%s%s%s%s", platinum_guess, gold_guess, silver_guess, copper_guess);
				text_guess += all_guess;
				text_guess += "<BR>";
			}
			if (task_guess->field_854_guess != 0) {
				text_guess += pStringTable->getString(0x8a, 0);
				text_guess += "<BR>";
			}
			if (task_guess->text_8c0_guess[0] != 0) {
				text_guess += task_guess->text_8c0_guess;
				text_guess += "<BR>";
			}
			if (task_guess->points_858_guess != 0) {
				text_guess += _itoa(task_guess->points_858_guess, g_itoaBuffer_guess, 10);
				text_guess += g_separator_guess;
				int id_guess;
				if (task_guess->type_2010_guess == 1)
					id_guess = (task_guess->subtype_2014_guess != 4) + 0x22fd;
				else
					id_guess = 0x4bf;
				text_guess += pStringTable->getString(id_guess, 0);
			}
		}
		(CXStr&)text_84c_guess = text_guess;
		((CStmlWnd*)taskDescription_168_guess)->SetSTMLText((CXStr&)text_84c_guess, 0, 0);
	} else {
		((CStmlWnd*)taskDescription_168_guess)->SetSTMLText(g_emptyText_guess, 0, 0);
	}
	}
}

// Virtual view of a window: slot 0x4C (0x130) is the list's clear.
struct ListVt_guess {
	virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
	virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
	virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
	virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess(); virtual void Slot3F_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
	virtual void Slot4C_guess();   // 0x4C (0x130)
};

struct QuestRecord_guess {
	int id_000_guess;
	unsigned char pad_004_guess[0x84];
	int zone_088_guess;
	unsigned char pad_08c_guess[0x124 - 0x8c];
};

struct QuestHistory_guess {
	unsigned char pad_000_guess[0x940];
	QuestRecord_guess records_940_guess[20];
};

struct ZoneInfo_guess {
	// EXTERNAL: TITANIUM 0x005FA1C0 ZoneInfo_guess::GetName_guess
	void GetName_guess(int zone_guess, char* name_guess, int flag_guess);
};
#define g_zoneInfo_guess EQ_GLOBAL(ZoneInfo_guess*, 0x00905CC0)

struct TaskElement_guess {
	int id_000_guess;
	unsigned char pad_004_guess[0x84];
	int zone_088_guess;
	unsigned char pad_08c_guess[8];
	int count_094_guess;
	char flag_098_guess;
	unsigned char pad_099_guess[3];
	int group_09c_guess;
	unsigned char pad_0a0_guess[0x124 - 0xa0];
};

struct TaskElementList_guess {
	unsigned char pad_000_guess[0x940];
	TaskElement_guess elements_9c8_guess[20];
};

struct TaskProgress_guess {
	unsigned char pad_000_guess[0x1c];
	int values_01c_guess[20];
};

// Element list of the selected task, grouped by step (+0x9C), a blank row between steps: description
// (first letter upper-cased, string 0x17E3 for optional ones), done/goal or string 0xD94 in green when
// done, and the zone. Hidden activities (-1) are grey with string 0xD92.
// FUNCTION: TITANIUM 0x0055ED77
// @early-stop: budget, structural ndiff=152
void CTaskWnd_guess::UpdateTask_guess(TaskInfo_guess* task_guess, Record_guess* record_guess) {
	if (taskElements_170_guess != 0) {
		((ListVt_guess*)taskElements_170_guess)->Slot4C_guess();
		if (task_guess != 0) {

	TaskElement_guess* first_guess = ((TaskElementList_guess*)task_guess)->elements_9c8_guess;
		int* values_guess = ((TaskProgress_guess*)record_guess)->values_01c_guess;
	int group_guess = 0;
	do {
		int added_guess = 0;
		TaskElement_guess* element_guess = first_guess;
		int* currentValue_guess = values_guess;
		int remaining_guess = 20;
		do {
			if (element_guess->group_09c_guess == group_guess && element_guess->id_000_guess != 0) {
				if (added_guess == 0 && group_guess != 0) {
					int header_guess;
					{
						CXStr empty_guess(g_emptyText_guess);
						header_guess = ((CListWnd*)taskElements_170_guess)->AddString(empty_guess, 0xffffffff, 0, 0);
					}
					((CListWnd*)taskElements_170_guess)->SetItemData(header_guess, 0x40000000);
				}
				++added_guess;
				unsigned int color_guess = 0xffffffff;
				char zoneName_guess[256];
				strcpy(zoneName_guess, pStringTable->getString(0x3395, 0));
				if (element_guess->id_000_guess == -1) {
					color_guess = 0xff808080;
					strcpy(zoneName_guess, pStringTable->getString(0xd92, 0));
				} else if (element_guess->count_094_guess <= *currentValue_guess) {
					color_guess = 0xff00ff00;
				}

				char formattedName_guess[256];
				g_taskManager_guess->FormatActivityText_guess(
					(QuestRecord_guess*)element_guess, formattedName_guess);
				CXStr text_guess(formattedName_guess);
				wint_t firstCharacter_guess = EQ_METHOD(1, wint_t, 0x005715D0,
					(CXStr, int), &text_guess)(0);
				if (iswlower(firstCharacter_guess))
					firstCharacter_guess = towupper(firstCharacter_guess);
				EQ_METHOD(2, void, 0x005725E0, (CXStr, int, wint_t), &text_guess)(0, firstCharacter_guess);
				if (element_guess->flag_098_guess != 0) {
					CXStr suffix_guess(pStringTable->getString(0x17e3, 0));
					EQ_METHOD(2, void, 0x00572F20, (CXStr, int, const CXStr&), &text_guess)(0, suffix_guess);
				}
				if (element_guess->zone_088_guess != 0)
					g_zoneInfo_guess->GetName_guess(element_guess->zone_088_guess, zoneName_guess, 1);

				int row_guess = ((CListWnd*)taskElements_170_guess)->AddString(text_guess, color_guess, 0, 0);
				if (element_guess->id_000_guess != -1) {
					if (color_guess == 0xff00ff00) {
						EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
							(CListWnd*)taskElements_170_guess)(row_guess, 1, pStringTable->getString(0xd94, 0));
					} else {
						char countText_guess[104];
						sprintf(countText_guess, "%d/%d", *currentValue_guess, element_guess->count_094_guess);
						CXStr countString_guess(countText_guess);
						EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
							(CListWnd*)taskElements_170_guess)(row_guess, 1, countString_guess);
					}
				}
				{
					CXStr zoneText_guess(zoneName_guess);
					EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
						(CListWnd*)taskElements_170_guess)(row_guess, 2, zoneText_guess);
				}
				((Container_guess*)taskElements_170_guess)->SetItemColor_guess(row_guess, 2, color_guess);
			}
			++element_guess;
			++currentValue_guess;
			--remaining_guess;
		} while (remaining_guess != 0);
		++group_guess;
	} while (group_guess < 20);
		}
	}
}

// EXTERNAL: TITANIUM 0x006124F6 iswlower
// EXTERNAL: TITANIUM 0x0061259E towupper

// Element list of a completed quest: every activity green and done (string 0xD94), with its zone.
// FUNCTION: TITANIUM 0x0055F192
void CTaskWnd_guess::FillQuestHistory_guess(QuestHistory_guess* history_guess) {
	char zone_guess[256];
	char name_guess[256];
	if (questTaskElements_188_guess == 0)
		return;
	((ListVt_guess*)questTaskElements_188_guess)->Slot4C_guess();
	if (history_guess == 0)
		return;
	QuestRecord_guess* record_guess = history_guess->records_940_guess;
	for (int i_guess = 0; i_guess < 20; i_guess++, record_guess++) {
		if (record_guess->id_000_guess == 0)
			continue;
		strcpy(zone_guess, pStringTable->getString(0x3395, 0));
		g_taskManager_guess->FormatActivityText_guess(record_guess, name_guess);
		CXStr text_guess(name_guess);
		wint_t ch_guess = EQ_METHOD(1, wint_t, 0x005715D0, (CXStr, int), &text_guess)(0);
		if (iswlower(ch_guess))
			ch_guess = towupper(ch_guess);
		EQ_METHOD(2, void, 0x005725E0, (CXStr, int, wint_t), &text_guess)(0, ch_guess);
		if (record_guess->zone_088_guess != 0)
			g_zoneInfo_guess->GetName_guess(record_guess->zone_088_guess, zone_guess, 1);
		int row_guess = ((CListWnd*)questTaskElements_188_guess)->AddString(text_guess, 0xff00ff00, 0, 0);
		if (record_guess->id_000_guess != -1) {
			EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
				(CListWnd*)questTaskElements_188_guess)(row_guess, 1, pStringTable->getString(0xd94, 0));
			EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
				(CListWnd*)questTaskElements_188_guess)(row_guess, 1, 0xff00ff00);
		}
		EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
			(CListWnd*)questTaskElements_188_guess)(row_guess, 2, zone_guess);
		EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
			(CListWnd*)questTaskElements_188_guess)(row_guess, 2, 0xff00ff00);
	}
}

// Row comparator: title, ascending.
// FUNCTION: TITANIUM 0x0055F3E8
int __cdecl CompareTitle_guess(CompareRecord_guess* first_guess, CompareRecord_guess* second_guess) {
	return strcmp(first_guess->text_010_guess, second_guess->text_010_guess);
}

// Row comparator: time left, ties by title. Kept: the unsigned `> 0` gives 1 for any difference and
// never -1, so this ordering is inconsistent for qsort.
// FUNCTION: TITANIUM 0x0055F412
int __cdecl CompareTimeLeft_guess(CompareRecord_guess* first_guess, CompareRecord_guess* second_guess) {
	int firstValue_guess = first_guess->field_00c_guess;
	int secondValue_guess = second_guess->field_00c_guess;
	if (firstValue_guess == secondValue_guess)
		return CompareTitle_guess(first_guess, second_guess);
	return (unsigned int)(firstValue_guess - secondValue_guess) > 0;
}

// Loads the TaskList and ElemList column settings (LoadIniListWnd) and the layout from the INI; the ctor
// calls it. StoreIniSettings_guess stores them.
// FUNCTION: TITANIUM 0x0055F44E
void LayoutOwner_guess::LoadIniSettings_guess() {
	if (task_16c_guess != 0)
		LoadIniListWnd(task_16c_guess, "TaskList");
	if (elements_170_guess != 0)
		LoadIniListWnd(elements_170_guess, "ElemList");
	if (element_17c_guess != 0)
		element_17c_guess->SetLayout_guess(lookup_120_guess.Find_guess("Layout"));
}

// StoreIniInfo side: saves TaskList and ElemList through the list INI store (0x005A1FE0) and the Layout
// setting.
// FUNCTION: TITANIUM 0x0055F4AB
void LayoutOwner_guess::StoreIniSettings_guess() {
	if (task_16c_guess != 0)
		StoreIniListWnd_guess(task_16c_guess, "TaskList");
	if (elements_170_guess != 0)
		StoreIniListWnd_guess(elements_170_guess, "ElemList");
	if (element_17c_guess != 0)
		element_17c_guess->SetLayout2_guess(lookup_120_guess.Find_guess("Layout"));
}

struct QuestEntry_guess {
	int count_000_guess;
	char name_004_guess[0x2818];
	time_t time_281c_guess;
};


// Quest history page: completed quests (type name, title, completion ctime), then the elements of the
// selected one; a selected separator row moves the selection down.
// FUNCTION: TITANIUM 0x0055F508
void CTaskWnd_guess::FillQuestHistoryList_guess() {
	if (questTaskList_184_guess == 0)
		return;
	((ListVt_guess*)questTaskList_184_guess)->Slot4C_guess();
	for (int i_guess = 0; i_guess < 50; i_guess++) {
		QuestEntry_guess* entry_guess = g_taskManager_guess->At_guess(i_guess);
		if (entry_guess->count_000_guess > 0) {
			int row_guess;
			{
				CXStr type_guess(g_nameTable_guess[2]);
				row_guess = ((CListWnd*)questTaskList_184_guess)->AddString(type_guess, 0xffffffff, 0, 0);
			}
			{
				CXStr name_guess(entry_guess->name_004_guess);
				EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
					(CListWnd*)questTaskList_184_guess)(row_guess, 1, name_guess);
			}
			EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
				(CListWnd*)questTaskList_184_guess)(row_guess, 1, 0xffffffff);
			{
				CXStr time_guess(ctime(&entry_guess->time_281c_guess));
				EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
					(CListWnd*)questTaskList_184_guess)(row_guess, 2, time_guess);
			}
			EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
				(CListWnd*)questTaskList_184_guess)(row_guess, 2, 0xffffffff);
		}
	}
	int index_guess = ((CListWnd*)questTaskList_184_guess)->GetCurSel();
	if (((CListWnd*)questTaskList_184_guess)->GetItemData(index_guess) == 0x40000000) {
		index_guess++;
		((CListWnd*)questTaskList_184_guess)->SetCurSel(index_guess);
	}
	FillQuestHistory_guess((QuestHistory_guess*)g_taskManager_guess->At_guess(index_guess));
}

// Abandons the selected task: OP_CancelTask (task index, type) and disables the abandon button.
// FUNCTION: TITANIUM 0x0055F68F
void CTaskWndView_guess::SendCancelTask_guess() {
	int first_guess;
	int second_guess;
	int index_guess = container_16c_guess->Current_guess();
	if (GetValues_guess(index_guess, &first_guess, &second_guess)) {
		int payload_guess[2];
		payload_guess[1] = second_guess;
		payload_guess[0] = first_guess;
		EQSendMessage(&g_connection_guess, OP_CancelTask, payload_guess, 8, 1);
		object_174_guess->state_05d_guess = 0;
	}
}

// Scalar deleting destructor of the task window (vtable 0x65DE10 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x0055F6EA
CTaskWnd_guess* CTaskWnd_guess::Delete_guess(unsigned char flags_guess) {
	CTaskWnd_guess::~CTaskWnd_guess();
	if ((flags_guess & 1) != 0)
		free(this);
	return this;
}

// Asks for a full refresh (+0x845) and a target-marker update (+0x88C) on the next frame.
// FUNCTION: TITANIUM 0x0055F706
void Object_guess::RequestRefresh_guess() {
	field_845_guess = 1;
	field_88c_guess = 1;
}

struct SelectionRecord_guess {
	int first_guess;
	int second_guess;
	int id_guess;
};

struct StateCount_guess {
	unsigned char pad_000_guess[0x2820];
	int count_2820_guess;
};

// Rebuilds the task list: the task, the shared task, then quests, with separator rows (data 0x40000000)
// between; keeps the selected task id selected (else row 0) and sets the abandon and monster buttons.
// FUNCTION: TITANIUM 0x0055F71D
// @early-stop: budget, structural ndiff=125
void CTaskWnd_guess::FillTaskList_guess() {
	if (taskList_16c_guess != 0) {
		int currentId_guess = -1;
		int currentRow_guess = ((Container_guess*)taskList_16c_guess)->Current_guess();
		if (currentRow_guess != -1) {
			SelectionRecord_guess* record_guess =
				(SelectionRecord_guess*)((Container_guess*)taskList_16c_guess)->GetRecord_guess(currentRow_guess);
			currentId_guess = record_guess->id_guess;
		}
		((ListVt_guess*)taskList_16c_guess)->Slot4C_guess();

		int selectedRow_guess = -1;
		int entryCount_guess = 0;
		if (taskCount_0834_guess > 0) {
			SlotEntry_guess* entry_guess = (SlotEntry_guess*)taskRows_01a4_guess;
			int index_guess = 0;
			do {
				int row_guess = ((CTaskWndView_guess*)this)->AddEntry_guess((PaletteEntry_guess*)entry_guess);
				if (entry_guess->value_008_guess == currentId_guess)
					selectedRow_guess = row_guess;
				++entryCount_guess;
				++index_guess;
				++entry_guess;
			} while (index_guess < taskCount_0834_guess);
		}

		if (sharedTaskCount_083c_guess > 0) {
			if (entryCount_guess > 0) {
				int row_guess;
				{
					CXStr separator_guess(g_emptyText_guess);
					row_guess = ((CListWnd*)taskList_16c_guess)->AddString(separator_guess, -1, 0, 0);
				}
				((CListWnd*)taskList_16c_guess)->SetItemData(row_guess, 0x40000000);
			}
			SlotEntry_guess* entry_guess = (SlotEntry_guess*)sharedTaskRows_07e4_guess;
			int index_guess = 0;
			do {
				int row_guess = ((CTaskWndView_guess*)this)->AddEntry_guess((PaletteEntry_guess*)entry_guess);
				if (entry_guess->value_008_guess == currentId_guess)
					selectedRow_guess = row_guess;
				++entryCount_guess;
				++index_guess;
				++entry_guess;
			} while (index_guess < sharedTaskCount_083c_guess);
		}

		if (questCount_0838_guess > 0) {
			if (entryCount_guess > 0) {
				int row_guess;
				{
					CXStr separator_guess(g_emptyText_guess);
					row_guess = ((CListWnd*)taskList_16c_guess)->AddString(separator_guess, -1, 0, 0);
				}
				((CListWnd*)taskList_16c_guess)->SetItemData(row_guess, 0x40000000);
			}
			SlotEntry_guess* entry_guess = (SlotEntry_guess*)questRows_01f4_guess;
			int index_guess = 0;
			do {
				int row_guess = ((CTaskWndView_guess*)this)->AddEntry_guess((PaletteEntry_guess*)entry_guess);
				if (entry_guess->value_008_guess == currentId_guess)
					selectedRow_guess = row_guess;
				++index_guess;
				++entry_guess;
			} while (index_guess < questCount_0838_guess);
		}

		if (selectedRow_guess == -1 && ((Container_guess*)taskList_16c_guess)->count_11c_guess > 0)
			selectedRow_guess = 0;
		((CListWnd*)taskList_16c_guess)->SetCurSel(selectedRow_guess);
		if (abandonButton_174_guess != 0)
			abandonButton_174_guess->Enabled = selectedRow_guess != -1;
		if (monsterButton_178_guess != 0)
			monsterButton_178_guess->Enabled = 0;

		Record_guess* selectedRecord_guess = 0;
		TaskInfo_guess* task_guess = 0;
		if (selectedRow_guess != -1) {
			SelectionRecord_guess* rowRecord_guess =
				(SelectionRecord_guess*)((Container_guess*)taskList_16c_guess)->GetRecord_guess(selectedRow_guess);
			selectedRecord_guess = g_taskManager_guess->GetRecord_guess(pCharData,
				rowRecord_guess->first_guess, rowRecord_guess->second_guess);
			task_guess = (TaskInfo_guess*)g_taskManager_guess->Get_guess(
				rowRecord_guess->first_guess, rowRecord_guess->second_guess, 1);
			if (monsterButton_178_guess != 0)
				monsterButton_178_guess->Enabled = task_guess != 0 &&
					((StateCount_guess*)task_guess)->count_2820_guess > 0;
		}
		UpdateTask_guess(task_guess, selectedRecord_guess);
		ShowTask_guess(task_guess, (int)selectedRecord_guess);
	}
}

struct SharedMember_guess {
	char name_000_guess[0x40];
	int taskId_040_guess;
	int leader_044_guess;
	SharedMember_guess* next_048_guess;
};

struct SharedTaskRecord_guess {
	int taskId_000_guess;
	unsigned char pad_004_guess[0x0d];
	char name_011_guess[0x40];
};

struct SharedTaskData_guess {
	int count_000_guess;
	SharedTaskRecord_guess* records_004_guess;
	// EXTERNAL: TITANIUM 0x00432806 SharedTaskData_guess::GetRecord_guess
	SharedTaskRecord_guess* GetRecord_guess(int index_guess);
};

struct SharedTaskState_guess {
	unsigned char pad_000_guess[0x2820];
	SharedTaskData_guess data_2820_guess;
};

// The virtual base holding the character name at +0x3C (EQ_PC layout).
struct CharNameBase_guess {
	unsigned char pad_000_guess[0x3c];
	char name_03c_guess[0x40];
};

struct CharNamePrefix_guess {
	virtual void RefreshCounts_guess();
	int field_004_guess;
};

struct CharNameProfile_guess : CharNamePrefix_guess, virtual CharNameBase_guess {
	unsigned char pad_00c_guess[0xC384 - 0x00c];
};

#define g_sharedMembers_guess EQ_GLOBAL(SharedMember_guess*, 0x00850330)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x0055F400 CompareTextRev_guess
int __cdecl CompareTextRev_guess(CompareRecord_guess* first_guess, CompareRecord_guess* second_guess);
// EXTERNAL: TITANIUM 0x0055F43C CompareRecordsRev_guess
int __cdecl CompareRecordsRev_guess(CompareRecord_guess* first_guess, CompareRecord_guess* second_guess);

// Sorts the three row arrays by title (+0x840 = 0) or time left (1), ascending when +0x844 is set,
// then rebuilds the list.
// FUNCTION: TITANIUM 0x0055F9A0
void CTaskWnd_guess::SortTaskList_guess() {
	int (__cdecl* compare_guess)(CompareRecord_guess*, CompareRecord_guess*) = 0;
	switch (sortColumn_0840_guess) {
	case 0:
		compare_guess = CompareTitle_guess;
		if (sortAscending_0844_guess == 0)
			compare_guess = CompareTextRev_guess;
		break;
	case 1:
		if (sortAscending_0844_guess != 0)
			compare_guess = CompareTimeLeft_guess;
		else
			compare_guess = CompareRecordsRev_guess;
		break;
	}
	if (taskCount_0834_guess > 1 && compare_guess != 0)
		qsort(taskRows_01a4_guess, taskCount_0834_guess, 0x50, (int (__cdecl*)(const void*, const void*))compare_guess);
	if (questCount_0838_guess > 1 && compare_guess != 0)
		qsort(questRows_01f4_guess, questCount_0838_guess, 0x50, (int (__cdecl*)(const void*, const void*))compare_guess);
	if (sharedTaskCount_083c_guess > 1 && compare_guess != 0)
		qsort(sharedTaskRows_07e4_guess, sharedTaskCount_083c_guess, 0x50, (int (__cdecl*)(const void*, const void*))compare_guess);
	FillTaskList_guess();
}

// Shared task page: members, the leader marked "Leader" in yellow, each with the shared task's title;
// add, remove and make leader are enabled only for the leader.
// FUNCTION: TITANIUM 0x0055FA4C
void CTaskWnd_guess::RefreshSharedTaskMembers_guess() {
	char result_guess = 0;
	if (memberList_194_guess != 0) {
		((ListVt_guess*)memberList_194_guess)->Slot4C_guess();
		char flag_guess = g_taskManager_guess->HasPositive_guess();
		SharedMember_guess* member_guess = g_sharedMembers_guess;
		if (member_guess != 0) {
			do {
				CXStr name_guess(member_guess != 0 ? member_guess->name_000_guess : g_emptyString_guess);
				CXStr role_guess(g_emptyString_guess);
				int color_guess = 0xffffffff;
				if (member_guess->leader_044_guess == 1) {
					role_guess = "Leader";
					color_guess = 0xffffff00;
					if (strcmp(member_guess->name_000_guess,
						((CharNameProfile_guess*)pCharData)->name_03c_guess) == 0)
						result_guess = 1;
				}
				CXStr task_guess;
				if (flag_guess && member_guess->taskId_040_guess != 0) {
					for (int i_guess = 0; i_guess < 1; i_guess++) {
						SharedTaskState_guess* state_guess =
							(SharedTaskState_guess*)g_taskManager_guess->Get_guess(i_guess, 1, 1);
						if (state_guess != 0) {
							int index_guess = 0;
							int count_guess = state_guess->data_2820_guess.count_000_guess;
							if (count_guess > 0) {
								for (; index_guess < count_guess; index_guess++) {
									if (state_guess->data_2820_guess.GetRecord_guess(index_guess)->taskId_000_guess
										== member_guess->taskId_040_guess) {
										task_guess = state_guess->data_2820_guess.GetRecord_guess(index_guess)->name_011_guess;
										break;
									}
								}
							}
							break;
						}
					}
				}
				int row_guess = ((CListWnd*)memberList_194_guess)->AddString(name_guess, color_guess, 0, 0);
				EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
					(CListWnd*)memberList_194_guess)(row_guess, 0, color_guess);
				EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
					(CListWnd*)memberList_194_guess)(row_guess, 1, role_guess);
				EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
					(CListWnd*)memberList_194_guess)(row_guess, 1, color_guess);
				EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
					(CListWnd*)memberList_194_guess)(row_guess, 2, task_guess);
				EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int),
					(CListWnd*)memberList_194_guess)(row_guess, 2, color_guess);
				member_guess = member_guess->next_048_guess;
			} while (member_guess != 0);
		}
	}
	if (addPlayerButton_198_guess != 0)
		addPlayerButton_198_guess->Enabled = result_guess;
	if (removePlayerButton_19c_guess != 0)
		removePlayerButton_19c_guess->Enabled = result_guess;
	if (makeLeaderButton_1a0_guess != 0)
		makeLeaderButton_1a0_guess->Enabled = result_guess;
}

// Window fields the ctor sets through a CListWnd pointer; the headers do not name them.
struct WndExtra_guess {
	unsigned char pad_000_guess[0x66];
	unsigned char flags_066_guess;
	unsigned char pad_067_guess[0x15c - 0x67];
	unsigned char flag_15c_guess;
	unsigned char pad_15d_guess[0x16c - 0x15d];
	unsigned int color_16c_guess;
};

// Confirmation callback: dialog 100 (abandon, opened by HandleNotification_guess) answered with flag
// 1 or 4, probably yes, sends the cancel.
// FUNCTION: TITANIUM 0x0055FC6F
// @early-stop: budget, structural ndiff=6
void ActionSecondary_guess::OnConfirmAbandon_guess(int value_guess, unsigned char flags_guess,
	int ignored_guess) {
	if (value_guess == 100 && (flags_guess & 5) != 0)
		((CTaskWndView_guess&)static_cast<CTaskWnd_guess&>(*this)).SendCancelTask_guess();
}

// Pages TaskListPage, TaskQuestHistoryPage and TaskSharedTaskPage; the marker starts far away (10000).
// FUNCTION: TITANIUM 0x0055FC8B
CTaskWnd_guess::CTaskWnd_guess(CXWnd* parent_guess)
	: WndPrimary_guess(parent_guess, "TaskWnd", 0xfffffdff, 2, 0) {
	memberList_194_guess = 0;
	taskDescription_168_guess = 0;
	taskList_16c_guess = 0;
	taskElements_170_guess = 0;
	abandonButton_174_guess = 0;
	monsterButton_178_guess = 0;
	taskLayout_17c_guess = 0;
	questTaskList_184_guess = 0;
	questTaskElements_188_guess = 0;
	questLayout_18c_guess = 0;
	sortColumn_0840_guess = 0;
	sortAscending_0844_guess = 1;
	taskCount_0834_guess = 0;
	questCount_0838_guess = 0;
	needsRefresh_0845_guess = 0;
	markerPending_088c_guess = 0;
	field_850_guess = 0;
	memset(taskRows_01a4_guess, 0, 0x50);
	memset(questRows_01f4_guess, 0, 0x5f0);
	memset(sharedTaskRows_07e4_guess, 0, 0x50);
	taskCount_0834_guess = 0;
	questCount_0838_guess = 0;
	sharedTaskCount_083c_guess = 0;
	lastTimerUpdate_0848_guess = 0;
	if (sidlPiece_124_guess != 0) {
		flags_066_guess |= 1;
		field_158_guess = 0x33;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		subwindows_160_guess = ((CSidlScreenWnd*)this)->GetChildItem("TaskSubwindows");
		taskListPage_164_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("TaskListPage");
		questHistoryPage_180_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("TaskQuestHistoryPage");
		sharedTaskPage_190_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("TaskSharedTaskPage");
		// Three tab pages: the task list (TASK_), quest history (QUEST_) and the shared task (STASK_). Buttons
		// that act on a selection start disabled.
		if (taskListPage_164_guess != 0) {
			taskDescription_168_guess = taskListPage_164_guess->GetChildItem("TASK_Description");
			taskList_16c_guess = taskListPage_164_guess->GetChildItem("TASK_TaskList");
			taskElements_170_guess = taskListPage_164_guess->GetChildItem("TASK_TaskElementList");
			abandonButton_174_guess = taskListPage_164_guess->GetChildItem("TASK_AbandonButton");
			monsterButton_178_guess = taskListPage_164_guess->GetChildItem("TASK_MonsterButton");
			taskLayout_17c_guess = taskListPage_164_guess->GetChildItem("TASK_Layout");
			if (taskList_16c_guess != 0) {
				((CListWnd*)taskList_16c_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
				((CListWnd*)taskList_16c_guess)->SetColumnJustification(0, 1);
				((CListWnd*)taskList_16c_guess)->SetColumnJustification(1, 0);
				((CListWnd*)taskList_16c_guess)->SetColumnJustification(2, 1);
				((WndExtra_guess*)taskList_16c_guess)->color_16c_guess = 0xff8aa3ff;
				((WndExtra_guess*)taskList_16c_guess)->flag_15c_guess = 1;
			}
			if (taskElements_170_guess != 0) {
				((CListWnd*)taskElements_170_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
				((CListWnd*)taskElements_170_guess)->SetColumnJustification(0, 0);
				((CListWnd*)taskElements_170_guess)->SetColumnJustification(1, 1);
				((CListWnd*)taskElements_170_guess)->SetColumnJustification(2, 0);
				((WndExtra_guess*)taskElements_170_guess)->color_16c_guess = 0xff8aa3ff;
				((WndExtra_guess*)taskElements_170_guess)->flag_15c_guess = 1;
				((WndExtra_guess*)taskElements_170_guess)->flags_066_guess &= 0xfe;
			}
			if (abandonButton_174_guess != 0) {
				abandonButton_174_guess->Enabled = 0;
			}
			if (monsterButton_178_guess != 0) {
				monsterButton_178_guess->Enabled = 0;
			}
		}
		if (questHistoryPage_180_guess != 0) {
			questTaskList_184_guess = questHistoryPage_180_guess->GetChildItem("QUEST_TaskList");
			questTaskElements_188_guess = questHistoryPage_180_guess->GetChildItem("QUEST_TaskElementList");
			questLayout_18c_guess = questHistoryPage_180_guess->GetChildItem("QUEST_Layout");
			if (questTaskList_184_guess != 0) {
				((CListWnd*)questTaskList_184_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
				((CListWnd*)questTaskList_184_guess)->SetColumnJustification(0, 1);
				((CListWnd*)questTaskList_184_guess)->SetColumnJustification(1, 0);
				((CListWnd*)questTaskList_184_guess)->SetColumnJustification(2, 0);
				((WndExtra_guess*)questTaskList_184_guess)->color_16c_guess = 0xff8aa3ff;
				((WndExtra_guess*)questTaskList_184_guess)->flag_15c_guess = 1;
			}
			if (questTaskElements_188_guess != 0) {
				((CListWnd*)questTaskElements_188_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
				((CListWnd*)questTaskElements_188_guess)->SetColumnJustification(0, 0);
				((CListWnd*)questTaskElements_188_guess)->SetColumnJustification(1, 1);
				((CListWnd*)questTaskElements_188_guess)->SetColumnJustification(2, 0);
				((WndExtra_guess*)questTaskElements_188_guess)->color_16c_guess = 0xff8aa3ff;
				((WndExtra_guess*)questTaskElements_188_guess)->flag_15c_guess = 1;
				((WndExtra_guess*)questTaskElements_188_guess)->flags_066_guess &= 0xfe;
			}
		}
		if (sharedTaskPage_190_guess != 0) {
			memberList_194_guess = sharedTaskPage_190_guess->GetChildItem("STASK_MemberList");
			addPlayerButton_198_guess = sharedTaskPage_190_guess->GetChildItem("STASK_AddPlayerButton");
			removePlayerButton_19c_guess = sharedTaskPage_190_guess->GetChildItem("STASK_RemovePlayerButton");
			makeLeaderButton_1a0_guess = sharedTaskPage_190_guess->GetChildItem("STASK_MakeLeaderButton");
			if (memberList_194_guess != 0) {
				((CListWnd*)memberList_194_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
				((CListWnd*)memberList_194_guess)->SetColumnJustification(0, 0);
				((CListWnd*)memberList_194_guess)->SetColumnJustification(1, 0);
				((WndExtra_guess*)memberList_194_guess)->color_16c_guess = 0xff8aa3ff;
				((WndExtra_guess*)memberList_194_guess)->flag_15c_guess = 1;
			}
			if (addPlayerButton_198_guess != 0) {
				addPlayerButton_198_guess->Enabled = 0;
			}
			if (removePlayerButton_19c_guess != 0) {
				removePlayerButton_19c_guess->Enabled = 0;
			}
			if (makeLeaderButton_1a0_guess != 0) {
				makeLeaderButton_1a0_guess->Enabled = 0;
			}
		}
		// The pulse state at +0x854 (150, 100 and three 10000.0 values), then the layout is saved once.
		Pulse_guess* pulse_guess = &pulse_854_guess;
		pulse_guess->field_000_guess = 0;
		pulse_guess->field_004_guess = 0x96;
		pulse_guess->field_008_guess = 0x64;
		flag_86c_guess = 0;
		pulse_guess->y_000c_guess = 10000.0f;
		pulse_guess->x_0010_guess = 10000.0f;
		pulse_guess->z_0014_guess = 10000.0f;
		((LayoutOwner_guess*)this)->LoadIniSettings_guess();
		needsRefresh_0845_guess = 1;
		markerPending_088c_guess = 1;
	}
}

// Full refresh: collects tasks (type 0), quests (2) and the shared task (1), sorts, then rebuilds the
// marker, the member list and the quest history.
// FUNCTION: TITANIUM 0x0056043E
void CTaskWnd_guess::RefreshTasks_guess() {
	memset(taskRows_01a4_guess, 0, 0x50);
	taskCount_0834_guess = CollectTaskEntries_guess(taskRows_01a4_guess, 0);
	memset(questRows_01f4_guess, 0, 0x5f0);
	questCount_0838_guess = CollectTaskEntries_guess(questRows_01f4_guess, 2);
	memset(sharedTaskRows_07e4_guess, 0, 0x50);
	sharedTaskCount_083c_guess = CollectTaskEntries_guess(sharedTaskRows_07e4_guess, 1);
	SortTaskList_guess();
	UpdateTaskTargetMarker_guess();
	RefreshSharedTaskMembers_guess();
	FillQuestHistoryList_guess();
	needsRefresh_0845_guess = 0;
}

// Refreshes, then gives the shared task's id to the window 0x99283C (+0x210) that the monster button
// toggles.
// FUNCTION: TITANIUM 0x005604D3
char CTaskWnd_guess::AboutToShow_guess() {
	RefreshTasks_guess();
	if (pinstCTaskTemplateSelectWnd_guess != 0) {
		TaskDefinition_guess* timer_guess = g_taskManager_guess->Get_guess(0, 1, 1);
		if (timer_guess != 0)
			pinstCTaskTemplateSelectWnd_guess->field_210_guess = timer_guess->value_000_guess;
	}
	return 1;
}

// While shown: a pending refresh (+0x845), else the timers once per tick of FUN_00576e80_guess (probably
// seconds); the marker is retried every frame while +0x88C is set.
// FUNCTION: TITANIUM 0x00560506
void CTaskWnd_guess::ProcessFrame_guess() {
	if (show_005c_guess != 0) {
		if (needsRefresh_0845_guess != 0) {
			RefreshTasks_guess();
		} else {
			unsigned int now_guess = FUN_00576e80_guess();
			if (now_guess > lastTimerUpdate_0848_guess) {
				((CTaskWndView_guess*)this)->UpdateTimers_guess(now_guess);
				lastTimerUpdate_0848_guess = now_guess;
			}
		}
	}
	if (markerPending_088c_guess != 0) {
		UpdateTaskTargetMarker_guess();
	}
	((CXWnd*)this)->OnProcessFrame();
}

struct SelectionItems_guess {
	int count_000_guess;
	unsigned char pad_004_guess[8];
	int shift_00c_guess;
	int** items_010_guess;
	unsigned char pad_014_guess[0x0c];

	// EXTERNAL: TITANIUM 0x0047C3AF SelectionItems_guess::SelectionItems_guess
	SelectionItems_guess(int size_guess);
	// EXTERNAL: TITANIUM 0x00406E7E SelectionItems_guess::~SelectionItems_guess
	~SelectionItems_guess();
};

struct SelectionListReader_guess {
	// EXTERNAL: TITANIUM 0x0059BB50 SelectionListReader_guess::GetSelectedItems_guess
	void GetSelectedItems_guess(SelectionItems_guess* items_guess);
};

struct InviteData_guess {
	int field_000_guess;
	int field_004_guess;
	char name_008_guess[0x40];
};

#define g_playerInfo_guess EQ_GLOBAL(PlayerInfo_guess*, 0x00905D04)

struct ParentWnd_guess {
	unsigned char pad_000_guess[0x15c];
	int field_15c_guess;
};
#define pinstCTaskWnd_guess EQ_GLOBAL(ParentWnd_guess*, 0x00992858)

struct HistoryLoadFlag_guess {
	unsigned char pad_000_guess[0x2819];
	char loaded_2819_guess;
};

struct ParsedTaskData_guess {
	unsigned int fields_000_guess[7];
	unsigned int flags_01c_guess;
	unsigned int fields_020_guess[3];
};

union TaskScratch_guess {
	ParsedTaskData_guess parsed_000_guess;
	unsigned int selectionWords_000_guess[12];
};

struct NotificationParseLocals_guess {
	ParsedTaskData_guess parsed_000_guess;
	char formatted_02c_guess[0x200];
	InviteData_guess invite_22c_guess;
};

struct NotificationSelectionLocals_guess {
	unsigned char pad_000_guess[0x10];
	unsigned char selected_010_guess[0x20];
	unsigned char pad_030_guess[0x1fc];
	InviteData_guess invite_22c_guess;
};

union NotificationLocals_guess {
	NotificationParseLocals_guess parse_guess;
	NotificationSelectionLocals_guess selection_guess;
};

// EXTERNAL: TITANIUM 0x0046D3A3 ParseItemLink_guess
int __cdecl ParseItemLink_guess(const char* text_guess, ParsedTaskData_guess* output_guess);

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Click: a task row shows it; a history row sends OP_TaskHistoryRequest unless loaded; abandon opens
// dialog 100 (string 0x2323 task, 0x2324 shared, 0x2325 quest); add player sends the target's name with
// OP_TaskAddPlayer (string 0x230E unless a PC); remove 0x37B9 and make leader 0x1B25 (both unnamed) need
// one selected member. 0xF sorts by column 1 or 2; 0x1B is a description link (OP_ItemLinkClick, Shift
// sets flag 2). `data_guess` and `message_guess` are reused as out-parameters.
// FUNCTION: TITANIUM 0x00560556
// @early-stop: budget, structural ndiff=168
int CTaskWnd_guess::HandleNotification_guess(CXWnd* sender_guess, int message_guess, int data_guess) {
	NotificationLocals_guess locals_guess;
	if (message_guess == 1) {
		if (sender_guess == taskList_16c_guess) {
			int index_guess = ((CListWnd*)taskList_16c_guess)->GetCurSel();
			if (((CListWnd*)taskList_16c_guess)->GetItemData(index_guess) == 0x40000000) {
				index_guess++;
				((CListWnd*)taskList_16c_guess)->SetCurSel(index_guess);
			}
			if (((CTaskWndView_guess*)this)->GetValues_guess(index_guess, &data_guess, &message_guess)) {
				Record_guess* record_guess = g_taskManager_guess->GetRecord_guess(pCharData,
					data_guess, message_guess);
				TaskInfo_guess* task_guess = (TaskInfo_guess*)g_taskManager_guess->Get_guess(
					data_guess, message_guess, 1);
				UpdateTask_guess(task_guess, record_guess);
				ShowTask_guess(task_guess, (int)record_guess);
				if (abandonButton_174_guess != 0)
					abandonButton_174_guess->Enabled = 1;
				if (monsterButton_178_guess != 0) {
					bool enabled_guess = false;
					if (task_guess != 0)
						enabled_guess = ((SharedTaskState_guess*)task_guess)->data_2820_guess.count_000_guess > 0;
					monsterButton_178_guess->Enabled = enabled_guess;
				}
		}
		}
		else if (sender_guess == questTaskList_184_guess) {
			message_guess = ((CListWnd*)questTaskList_184_guess)->GetCurSel();
			if (((CListWnd*)questTaskList_184_guess)->GetItemData(message_guess) == 0x40000000) {
				message_guess++;
				((CListWnd*)questTaskList_184_guess)->SetCurSel(message_guess);
			}
			QuestHistory_guess* history_guess =
				(QuestHistory_guess*)g_taskManager_guess->At_guess(message_guess);
			if (((HistoryLoadFlag_guess*)history_guess)->loaded_2819_guess == 0)
				EQSendMessage(&g_connection_guess, OP_TaskHistoryRequest, &message_guess, 4, 1);
			else
				FillQuestHistory_guess(history_guess);
		}
		else if (sender_guess == abandonButton_174_guess) {
			int index_guess = ((CListWnd*)taskList_16c_guess)->GetCurSel();
			if (((CTaskWndView_guess*)this)->GetValues_guess(index_guess, &data_guess, &message_guess)) {
				TaskDefinition_guess* task_guess = g_taskManager_guess->Get_guess(data_guess, message_guess, 1);
				const char* taskName_guess = g_emptyText_guess;
				if (task_guess != 0)
					taskName_guess = task_guess->text_004_guess;
				int textId_guess;
				if (message_guess == 0)
					textId_guess = 0x2323;
				else
					textId_guess = (message_guess != 1) + 0x2324;
				FormatText_guess(locals_guess.parse_guess.formatted_02c_guess, textId_guess, taskName_guess,
					0, 0, 0, 0, 0, 0, 0, 0);
				void* parent_guess = 0;
				if (pinstCTaskWnd_guess != 0)
					parent_guess = &pinstCTaskWnd_guess->field_15c_guess;
				pConfirmationDialogPool_guess->Activate(parent_guess, 100, locals_guess.parse_guess.formatted_02c_guess,
					0x0c, 10000, 0, 1);
			}
		}
		else if (sender_guess == monsterButton_178_guess) {
			CTaskTemplateSelectWnd_guess* window_guess = pinstCTaskTemplateSelectWnd_guess;
			if (window_guess != 0)
				window_guess->Show(window_guess->dShow == 0, 1);
		}
		else if (sender_guess == addPlayerButton_198_guess) {
			if (g_playerInfo_guess == 0 || g_playerInfo_guess->type_0244_guess != 0) {
				pEverQuest->dsp_chat(pStringTable->getString(0x230e, 0), 0xf, 1);
			} else {
				strncpy(locals_guess.selection_guess.invite_22c_guess.name_008_guess,
					g_playerInfo_guess->name_120_guess, 0x40);
				EQSendMessage(&g_connection_guess, OP_TaskAddPlayer,
					&locals_guess.selection_guess.invite_22c_guess, 0x48, 1);
			}
		}
		else if (sender_guess == removePlayerButton_19c_guess || sender_guess == makeLeaderButton_1a0_guess) {
			new (&locals_guess.selection_guess.selected_010_guess[0]) SelectionItems_guess(0x20);
			((SelectionListReader_guess*)memberList_194_guess)->GetSelectedItems_guess(
				(SelectionItems_guess*)&locals_guess.selection_guess.selected_010_guess[0]);
			if (((SelectionItems_guess*)&locals_guess.selection_guess.selected_010_guess[0])->count_000_guess == 1) {
				int selectedIndex_guess = *
					((SelectionItems_guess*)&locals_guess.selection_guess.selected_010_guess[0])->items_010_guess[
						0 >> ((SelectionItems_guess*)&locals_guess.selection_guess.selected_010_guess[0])->shift_00c_guess];
				strcpy(locals_guess.selection_guess.invite_22c_guess.name_008_guess,
					(char*)((CListWnd*)memberList_194_guess)->GetItemText(selectedIndex_guess, 0));
				if (sender_guess == removePlayerButton_19c_guess)
					EQSendMessage(&g_connection_guess, 0x37b9,
						&locals_guess.selection_guess.invite_22c_guess, 0x48, 1);
				else
					EQSendMessage(&g_connection_guess, 0x1b25,
						&locals_guess.selection_guess.invite_22c_guess, 0x48, 1);
			} else {
				if (sender_guess == removePlayerButton_19c_guess)
					pEverQuest->dsp_chat(pStringTable->getString(0x230f, 0), 0xf, 1);
				else
					pEverQuest->dsp_chat(pStringTable->getString(0x2310, 0), 0xf, 1);
			}
			((SelectionItems_guess*)&locals_guess.selection_guess.selected_010_guess[0])->~SelectionItems_guess();
		}
		return 0;
	}
	if (message_guess == 0xf) {
		if (sender_guess == taskList_16c_guess) {
			int previousGuess = sortColumn_0840_guess;
			int nextGuess = previousGuess;
			if (data_guess == 1)
				nextGuess = 0;
			else if (data_guess == 2)
				nextGuess = 1;
			if (nextGuess == previousGuess)
				sortAscending_0844_guess = !sortAscending_0844_guess;
			sortColumn_0840_guess = nextGuess;
			SortTaskList_guess();
		}
	}
	else if (message_guess == 0x1b && sender_guess == taskDescription_168_guess) {
		memset(&locals_guess.parse_guess.parsed_000_guess, 0, 0x2c);
		if (ParseItemLink_guess((const char*)data_guess, &locals_guess.parse_guess.parsed_000_guess) == 0) {
			if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0)
				locals_guess.parse_guess.parsed_000_guess.flags_01c_guess |= 2;
			EQSendMessage(&g_connection_guess, OP_ItemLinkClick,
				&locals_guess.parse_guess.parsed_000_guess, 0x2c, 1);
		}
	}
	return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, (unsigned int)message_guess, (void*)data_guess);
}

