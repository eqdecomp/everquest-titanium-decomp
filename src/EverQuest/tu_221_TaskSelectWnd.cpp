// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 221: a hint from compare/tumap.py.
// CTaskSelectWnd ("TaskSelectWnd"), the task giver's offer list. CTaskSelectWnd_guess is the window, CSidlScreenWndView_guess
// its CSidlScreenWnd base, and TaskOffer_guess/ZoneInfo_guess one offered task (0x2834 bytes: +0 task id,
// +4 title, +0x44 time limit in seconds, +0x48 duration class, +0x940 up to 20 activities of 0x124 bytes,
// +0x2019 description). Up to 40 offers.
#include "titanium/types.h"
#include "titanium/opcodes.h"

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

// Record under an element, 0x124 bytes; the id picks the slot.
struct SubRecord_guess {
    int f0_000;                   // 0x000
    int f4_004;                   // 0x004
    char text_008[0x40];          // 0x008
    char text_048[0x40];          // 0x048
    int f88_088;                  // 0x088
    int f8c_08c;                  // 0x08C
    int f90_090;                  // 0x090
    int f94_094;                  // 0x094
    unsigned char flag_098;       // 0x098
    char unknown_099[0xa4 - 0x99];
    char text_0a4[0x80];          // 0x0A4
};

struct TaskOffer_guess {
    int taskId_0000_guess;                // 0x000
    char text_004[0x40];          // 0x004, appended to the list row text
    int timeLimit_0044_guess;                 // 0x044, seconds left (0 = show the state text)
    int durationClass_0048_guess;                // 0x048, 1..3 pick the state string
    char unknown_04c[0x940 - 0x4c];
    SubRecord_guess sub_940[0x14]; // 0x940, indexed by record id
    char unknown_2010[0x2019 - 0x2010];
    char info_2019[0x800];        // 0x2019
    char unknown_2819[0x2834 - 0x2819];
    // EXTERNAL: TITANIUM 0x00432C38 TaskOffer_guess::TaskOffer_guess
    TaskOffer_guess();
    // EXTERNAL: TITANIUM 0x00432C72 TaskOffer_guess::~TaskOffer_guess
    ~TaskOffer_guess();
};

struct ZoneText_guess {
    void* rep_guess;
    // EXTERNAL: TITANIUM 0x00572300 ZoneText_guess::Ptr_guess
    char* Ptr_guess() const;
    // EXTERNAL: TITANIUM 0x00572300 ZoneText_guess::GetLayout_guess
    int GetLayout_guess(const char* name_guess);
};

struct LayoutTarget_guess {
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
    virtual void Slot73_guess(int layout_guess);
    virtual void SetLayout_guess(const char* text_guess, const char* section_guess); // 0x128
};

struct CSidlScreenWndView_guess {
    char unknown_004[0x066 - 0x4];
    unsigned char flags_066;        // 0x066
    char unknown_067[0x120 - 0x067];
    ZoneText_guess text_120;        // 0x120
    void* sidl_piece_124;           // 0x124
    char unknown_128[0x158 - 0x128];
    int field_158;                  // 0x158
    CListWnd* list_15c;             // 0x15c
    CStmlWnd* stml_160;             // 0x160
    CXWnd* acceptButton_164_guess;        // 0x164
    CXWnd* declineButton_168_guess;        // 0x168
    LayoutTarget_guess* layout_16c; // 0x16c
    int taskGiverId_170_guess;                     // 0x170
    // EXTERNAL: TITANIUM 0x005A3100 CSidlScreenWndView_guess::~CSidlScreenWndView_guess
    virtual ~CSidlScreenWndView_guess();
    // EXTERNAL: TITANIUM 0x005A3900 CSidlScreenWndView_guess::CSidlScreenWndView_guess
    CSidlScreenWndView_guess(CXWnd* parent_guess, const CXStr& screen_guess);
    // EXTERNAL: TITANIUM 0x005A1FE0 CSidlScreenWndView_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(void* item_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x005A2230 CSidlScreenWndView_guess::WndNotification
    void WndNotification(CXWnd* sender_guess, unsigned int event_guess, void* data_guess);
};

struct ZoneList_guess : CListWnd {
    char pad_140_guess[0x15c - 0x140];
    unsigned char flag_15c_guess;   // 0x15c
    char pad_160_guess[0x16c - 0x160];
    unsigned int color_16c_guess;   // 0x16c
};

// EXTERNAL: TITANIUM 0x0065D810 ??_7CTaskSelectWnd_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z
struct CTaskSelectWnd_guess : CSidlScreenWndView_guess {
    TaskOffer_guess data_174[0x28]; // 0x174
    int taskCount_64994_guess;              // 0x64994
    int field_64998;              // 0x64998
    int chosenTask_6499c_guess;               // 0x6499c
    int offerType_649a0_guess;              // 0x649a0
    int nextUpdateTime_649a4_guess;              // 0x649a4
    CTaskSelectWnd_guess(CXWnd* parent_guess);
    void RefreshAll_guess();
    void Clear_guess();
    void Refresh_guess();
    bool SendAcceptReply_guess();
    void SelectTask_guess(int item_guess);
    void FillTaskList_guess();
    void LoadTasks_guess(int* message_guess);
    void ShowDescription_guess(struct ZoneInfo_guess* info_guess);
    int OnProcessFrame_guess();
    void OnWndNotification_guess(CXWnd* sender_guess, int event_guess, void* data_guess);
    virtual ~CTaskSelectWnd_guess();
    CTaskSelectWnd_guess* Delete_guess(unsigned char flags_guess);
};

struct ZoneEventTarget_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct ZoneInfo_guess {
    char unknown_000[0x4c];
    char text_04c[0x40];            // 0x04C
    char unknown_08c[0x940 - 0x8c];
    int field_940;                  // 0x940
    char unknown_944[0x9c8 - 0x944];
    int field_9c8;                  // 0x9C8
    char unknown_9cc[0x2018 - 0x9cc];
    char flag_2018;                 // 0x2018
    char flag_2019;                 // 0x2019
};

struct Stream_guess {
    // EXTERNAL: TITANIUM 0x004332E8 Stream_guess::BuildDescription_guess
    void BuildDescription_guess(ZoneInfo_guess* info_guess, char* buffer_guess);
};
#define g_stream_guess EQ_GLOBAL(Stream_guess, 0x0079DC78)

struct EQWorldData_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 EQWorldData_guess::GetName_guess
    void GetName_guess(int zone_guess, char* name_guess, int flag_guess);
};
#define gGate_guess EQ_GLOBAL(EQWorldData_guess*, 0x00905CC0)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* destination, unsigned int capacity, const char* text,
                          int arg4_guess, int arg5_guess, int arg6_guess, int arg7_guess,
                          int arg8_guess, int arg9_guess, int arg10_guess, int arg11_guess);

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
int __cdecl FUN_00401b28_guess(int id_guess);

struct CDisplayView_guess {
    char pad_guess[0x148];
    unsigned int tick_guess;
    // EXTERNAL: TITANIUM 0x00439D16 CDisplayView_guess::PlayerDistance_guess
    float PlayerDistance_guess(int a, int b, float c);
};
#define g_clock_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)
#define g_int_905ce4_guess EQ_GLOBAL(int, 0x00905CE4)

// Every 500 ms, closes the window when the task giver is gone or more than 60 units away.
// FUNCTION: TITANIUM 0x0055BB5E
int CTaskSelectWnd_guess::OnProcessFrame_guess()
{
    if (((CSidlScreenWnd*)this)->Show != 0) {
        if (g_clock_guess->tick_guess >= (unsigned int)nextUpdateTime_649a4_guess) {
            nextUpdateTime_649a4_guess = g_clock_guess->tick_guess + 500;
            int id_guess = FUN_00401b28_guess(taskGiverId_170_guess);
            if (id_guess == 0 || g_clock_guess->PlayerDistance_guess(id_guess, g_int_905ce4_guess, 0.0f) > 60.0f) {
                ((LayoutTarget_guess*)this)->Slot34_guess();
            }
        }
    }
    return ((CSidlScreenWnd*)this)->OnProcessFrame();
}

// Shows a task's description, plus "[This task begins in <zone>]" (string 0x178D) when the first
// activity names a zone (+0x9C8).
// FUNCTION: TITANIUM 0x0055BBCC
void CTaskSelectWnd_guess::ShowDescription_guess(ZoneInfo_guess* info_guess)
{
    CXStr name_guess;
    char buffer108_guess[0x6c];
    char zone_name_guess[256];
    char text_guess[1024];

    memset(buffer108_guess, 0, 0x6c);
    if (stml_160 != 0) {
        if (info_guess != 0) {
            if (info_guess->flag_2019 != 0) {
                if (info_guess->flag_2018 == 0) {
                    g_stream_guess.BuildDescription_guess(info_guess, buffer108_guess);
                }
                name_guess = info_guess->text_04c;
            }
            if (info_guess->field_940 != -1 && info_guess->field_940 != 0 && info_guess->field_9c8 != 0) {
                gGate_guess->GetName_guess(info_guess->field_9c8, zone_name_guess, 1);
                Format_guess(text_guess, 0x178d, zone_name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                name_guess += text_guess;
            }
            stml_160->SetSTMLText(name_guess, false, 0);
        } else {
            stml_160->SetSTMLText(CXStr(g_emptyString_guess), false, 0);
        }
    }
}

// Loads the TaskList columns and the Layout setting from the ini.
// FUNCTION: TITANIUM 0x0055BD3C
void CTaskSelectWnd_guess::RefreshAll_guess()
{
    if (list_15c != 0) {
        ((CSidlScreenWnd*)this)->LoadIniListWnd(list_15c, (char*)"TaskList");
    }
    if (layout_16c != 0) {
        layout_16c->Slot73_guess(text_120.GetLayout_guess("Layout"));
    }
}

// Task select window: zeroes the 40 task offer records (+0x174, 0x2834 bytes each) and the offer count
// (+0x64994). The offer packet reader (0x0055C13B) starts with it.
// FUNCTION: TITANIUM 0x0055BD1A
void CTaskSelectWnd_guess::Clear_guess()
{
    memset(data_174, 0, sizeof(data_174));
    taskCount_64994_guess = 0;
}

// Saves the TaskList columns and the Layout setting to the ini.
// FUNCTION: TITANIUM 0x0055BD82
void CTaskSelectWnd_guess::Refresh_guess()
{
    if (list_15c != 0) {
        StoreIniListWnd_guess(list_15c, "TaskList");
    }
    if (layout_16c != 0) {
        layout_16c->SetLayout_guess(text_120.Ptr_guess(), "Layout");
    }
}

struct TaskStateMessage_guess {
    int state_guess;
    int task_guess;
    int id_guess;
};

struct TaskSelectMessage_guess {
    int unused_0_guess;
    int unused_4_guess;
    int id_guess;
    int task_guess;
};

#define g_connection_guess EQ_GLOBAL(void*, 0x00905CA0)

// Answers the offer, then saves the ini: AcceptNewTask (0x207F; 12 bytes: offer type, task id or 0 to
// decline, giver spawn id) for offer types 0 and 2, SharedTaskAcceptNew (0x194D) for type 1.
// FUNCTION: TITANIUM 0x0055BDC8
bool CTaskSelectWnd_guess::SendAcceptReply_guess()
{
    switch (offerType_649a0_guess) {
    case 0:
    case 2: {
        TaskStateMessage_guess message;
        message.task_guess = chosenTask_6499c_guess;
        message.id_guess = taskGiverId_170_guess;
        message.state_guess = offerType_649a0_guess;
        EQSendMessage(&g_connection_guess, OP_AcceptNewTask, &message, sizeof(message), 1);
        break;
    }
    case 1:
        if (chosenTask_6499c_guess != 0) {
            TaskSelectMessage_guess message;
            message.id_guess = taskGiverId_170_guess;
            message.task_guess = chosenTask_6499c_guess;
            EQSendMessage(&g_connection_guess, OP_SharedTaskAcceptNew, &message, sizeof(message), 1);
        }
        break;
    }
    Refresh_guess();
    return true;
}

// Shows offer row `item_guess` and enables Accept when it holds a task.
// FUNCTION: TITANIUM 0x0055BE44
void CTaskSelectWnd_guess::SelectTask_guess(int item_guess)
{
    TaskOffer_guess* element_guess = &data_174[list_15c->GetItemData(item_guess)];
    if (element_guess->taskId_0000_guess != 0) {
        ShowDescription_guess((ZoneInfo_guess*)element_guess);
        if (acceptButton_164_guess != 0) {
            acceptButton_164_guess->Enabled = 1;
        }
    }
}

// AcceptButton keeps the selected task id and closes; DeclineButton just closes. The answer goes out on
// close, probably through SendAcceptReply_guess.
// FUNCTION: TITANIUM 0x0055BE82
void CTaskSelectWnd_guess::OnWndNotification_guess(CXWnd* sender_guess, int event_guess, void* data_guess)
{
    if (event_guess == 1) {
        if (sender_guess == list_15c) {
            SelectTask_guess(list_15c->GetCurSel());
        } else if (sender_guess == (CXWnd*)acceptButton_164_guess) {
            int index_guess = list_15c->GetCurSel();
            if (index_guess != -1) {
                int item_guess = list_15c->GetItemData(index_guess);
                TaskOffer_guess* element_guess = &data_174[item_guess];
                int task_guess = element_guess->taskId_0000_guess;
                if (task_guess != 0) {
                    chosenTask_6499c_guess = task_guess;
                }
                ((ZoneEventTarget_guess*)this)->Slot48_guess(0, 1);
            }
        } else if (sender_guess == (CXWnd*)declineButton_168_guess) {
            ((ZoneEventTarget_guess*)this)->Slot48_guess(0, 1);
        }
    }
    CSidlScreenWndView_guess::WndNotification(sender_guess, event_guess, data_guess);
}

// Only the list's vtable slot at +0x130 is called here (slot 76).
struct TriggerListVt_guess
{
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
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual void Slot76_guess();
};

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination, const char* format, ...);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x0060D970 strlen
unsigned __cdecl strlen(const char* text_guess);
// EXTERNAL: TITANIUM 0x00574310 CopyBuffer_guess
void __cdecl CopyBuffer_guess(char* destination, const char* source, unsigned int size);

// Lists the offers: title, then the time limit as hh:mm:ss or, without one, the duration class: 1 Short,
// 2 Medium, 3 Long (strings 0x1796-0x1794), else Unlimited (0xD93).
// FUNCTION: TITANIUM 0x0055BF0E
void CTaskSelectWnd_guess::FillTaskList_guess()
{
    chosenTask_6499c_guess = 0;
    if (list_15c != 0) {
        ((TriggerListVt_guess*)list_15c)->Slot76_guess();
        for (int i = 0; i < taskCount_64994_guess; i++) {
            CXStr text_guess;
            text_guess += data_174[i].text_004;
            int row_guess = list_15c->AddString(text_guess, 0xffffffff, i, 0);
            char buf_guess[256];
            if (data_174[i].timeLimit_0044_guess == 0) {
                if (data_174[i].durationClass_0048_guess == 1) {
                    strcpy(buf_guess, pStringTable->getString(0x1796, 0));
                } else if (data_174[i].durationClass_0048_guess == 2) {
                    strcpy(buf_guess, pStringTable->getString(0x1795, 0));
                } else if (data_174[i].durationClass_0048_guess == 3) {
                    strcpy(buf_guess, pStringTable->getString(0x1794, 0));
                } else {
                    strcpy(buf_guess, pStringTable->getString(0xd93, 0));
                }
            } else {
                int hours_guess = data_174[i].timeLimit_0044_guess / 3600;
                int rem_guess = data_174[i].timeLimit_0044_guess % 3600;
                sprintf(buf_guess, "%02d:%02d:%02d", hours_guess, rem_guess / 60, data_174[i].timeLimit_0044_guess % 60);
            }
            CXStr status_guess(buf_guess);
            ((CListWnd*)list_15c)->SetItemText(row_guess, 1, status_guess);
        }
        if (list_15c->ItemsCount > 0) {
            list_15c->SetCurSel(0);
            SelectTask_guess(0);
        }
    }
}

// Reads the offer packet, probably OP_TaskSelectWindow (0x5E7C) or the shared one: count, offer type,
// giver id, then per task: id, time limit, duration class, title, description and its activities. Offers
// past 40 are dropped; an activity's index comes from the packet unchecked although sub_940 holds 20.
// FUNCTION: TITANIUM 0x0055C13B
// @early-stop: budget, structural ndiff=140
void CTaskSelectWnd_guess::LoadTasks_guess(int* message_guess)
{
    Clear_guess();
    int* cursor_guess = message_guess;
    int count_guess = cursor_guess[0];
    offerType_649a0_guess = cursor_guess[1];
    taskGiverId_170_guess = cursor_guess[2];
    cursor_guess += 3;
    for (int i = 0; i < count_guess; ++i) {
        if (i >= 40) {
            break;
        }
        TaskOffer_guess* element_guess = &data_174[i];
        element_guess->taskId_0000_guess = cursor_guess[0];
        element_guess->timeLimit_0044_guess = cursor_guess[1];
        element_guess->durationClass_0048_guess = cursor_guess[2];
        char* text_guess = (char*)(cursor_guess + 3);
        CopyBuffer_guess(element_guess->text_004, text_guess, 0x40);
        text_guess += strlen(text_guess) + 1;
        CopyBuffer_guess(element_guess->info_2019, text_guess, 0x800);
        text_guess += strlen(text_guess) + 1;
        cursor_guess = (int*)text_guess;
        int records_guess = cursor_guess[0];
        cursor_guess++;
        if (records_guess > 0) {
            do {
                SubRecord_guess* sub_guess = &element_guess->sub_940[cursor_guess[0]];
                sub_guess->f0_000 = cursor_guess[1];
                sub_guess->f4_004 = cursor_guess[2];
                text_guess = (char*)(cursor_guess + 3);
                CopyBuffer_guess(sub_guess->text_008, text_guess, 0x40);
                text_guess += strlen(text_guess) + 1;
                CopyBuffer_guess(sub_guess->text_048, text_guess, 0x40);
                text_guess += strlen(text_guess) + 1;
                cursor_guess = (int*)text_guess;
                sub_guess->f94_094 = cursor_guess[0];
                sub_guess->f8c_08c = cursor_guess[1];
                sub_guess->f90_090 = cursor_guess[2];
                sub_guess->f88_088 = cursor_guess[3];
                text_guess = (char*)(cursor_guess + 4);
                strcpy(sub_guess->text_0a4, text_guess);
                text_guess += strlen(text_guess) + 1;
                cursor_guess = (int*)text_guess;
                sub_guess->flag_098 = 0;
                records_guess--;
            } while (records_guess != 0);
        }
        taskCount_64994_guess++;
    }
    FillTaskList_guess();
}

// Task select window constructor: finds Description, TaskList (colours set), Accept (disabled), Decline
// (enabled) and Layout, then restores the list columns and layout from the INI (0x0055BD3C).
// FUNCTION: TITANIUM 0x0055C2B5
CTaskSelectWnd_guess::CTaskSelectWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndView_guess(parent_guess, "TaskSelectWnd")
{
    stml_160 = 0;
    list_15c = 0;
    acceptButton_164_guess = 0;
    declineButton_168_guess = 0;
    layout_16c = 0;
    chosenTask_6499c_guess = 0;
    offerType_649a0_guess = 0;
    nextUpdateTime_649a4_guess = 0;
    if (sidl_piece_124 != 0) {
        flags_066 |= 1;
        field_158 = 0x36;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        stml_160 = (CStmlWnd*)((CSidlScreenWnd*)this)->GetChildItem("Description");
        list_15c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("TaskList");
        acceptButton_164_guess = (CXWnd*)((CSidlScreenWnd*)this)->GetChildItem("AcceptButton");
        declineButton_168_guess = (CXWnd*)((CSidlScreenWnd*)this)->GetChildItem("DeclineButton");
        layout_16c = (LayoutTarget_guess*)((CSidlScreenWnd*)this)->GetChildItem("Layout");
        if (list_15c != 0) {
            list_15c->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            list_15c->SetColumnJustification(0, 0);
            list_15c->SetColumnJustification(1, 1);
            ((ZoneList_guess*)list_15c)->color_16c_guess = 0xff8aa3ff;
            ((ZoneList_guess*)list_15c)->flag_15c_guess = 1;
        }
        if (acceptButton_164_guess != 0) {
            acceptButton_164_guess->Enabled = 0;
        }
        if (declineButton_168_guess != 0) {
            declineButton_168_guess->Enabled = 1;
        }
        RefreshAll_guess();
    }
}

// Destructor of the task select window (vtable 0x65D810): destroys the 40 offer records (+0x174,
// 0x00432C72 on each), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0055C0F0
CTaskSelectWnd_guess::~CTaskSelectWnd_guess()
{
}

// Scalar deleting destructor of the task select window (vtable 0x65D810 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x0055C50D
CTaskSelectWnd_guess* CTaskSelectWnd_guess::Delete_guess(unsigned char flags_guess)
{
    this->CTaskSelectWnd_guess::~CTaskSelectWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}
