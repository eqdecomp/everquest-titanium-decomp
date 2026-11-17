// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 222: a hint from compare/tumap.py.
// The task template picker, CTaskTemplateSelectWnd ("TaskTemplateSelectWnd"): pick a premade character
// template (class, level, stats, abilities, equipment) for a task, from a required and an optional list. Its
// messages (0x64D7, 0x67C6, 0x7135, 0x729C, 0x4EDB) have no EQEmu Titanium names. CTaskTemplateSelectWnd_guess is
// the window; Browser_guess and Picker_guess are views of it.
#include "titanium/types.h"

struct Entries_guess {
    char pad_0000[0x11c];
    int count_guess; // 0x11c
    char pad_0120[0x34];
    int field154_guess; // 0x154
    unsigned char flag158_guess; // 0x158
    char pad_0159[0x13];
    unsigned int color_16c_guess; // 0x16c
    // EXTERNAL: TITANIUM 0x00597BE0 Entries_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 Entries_guess::GetItemData
    int GetItemData(int index);
    // EXTERNAL: TITANIUM 0x00597C20 Entries_guess::SetCurSel
    void SetCurSel(int index);
    // EXTERNAL: TITANIUM 0x0059B9D0 Entries_guess::AddString
    int AddString(const CXStr& text_guess, unsigned long color_guess, unsigned int data_guess, const CTextureAnimation* icon_guess);
    // EXTERNAL: TITANIUM 0x0059B360 Entries_guess::SetItemText
    void SetItemText(int row_guess, int column_guess, const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x00598620 Entries_guess::SetItemData
    void SetItemData(int row_guess, unsigned int data_guess);
};

struct LayoutRoot_guess {
    char pad_0000[4];
    // EXTERNAL: TITANIUM 0x00572300 LayoutRoot_guess::GetLayout_guess
    int GetLayout_guess(const char* name);
};

struct WidgetBase_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess(const CXStr& text_guess);
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(int layout_guess);

    char pad_0004[0x154];
    void* owner_158_guess; // 0x158
    char pad_015c[0x10];
    int flag_16c_guess; // 0x16c
    // EXTERNAL: TITANIUM 0x0059D080 WidgetBase_guess::SetFlag_guess
    void SetFlag_guess(int flag_guess);
};

struct Widget_guess : WidgetBase_guess {
    virtual void SetLayout_guess(int layout);
};

struct Pane_guess : WidgetBase_guess {
    virtual void Slot74_guess(); virtual void Slot75_guess(); virtual void Slot76_guess();
    virtual void Slot77_guess(); virtual void Slot78_guess();
};

struct Browser_guess {
    char pad_0000[0x164];
    Entries_guess* entries; // 0x164
    char pad_0168[4];
    CStmlWnd* stml_guess; // 0x16c
    char pad_0170[0x14];
    WidgetBase_guess* w184_guess; // 0x184

    void ShowAbilityInfo_guess();
    void Check_guess(int value);
};

struct Timer_guess {
    virtual void Destroy_guess(int flags_guess);
    char pad_0004[0x29];
    unsigned char flag_2d_guess; // 0x2d
    char pad_002e[0x1e];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0Timer_guess@@QAE@XZ
    Timer_guess();
    // EXTERNAL: TITANIUM 0x005B1730 Timer_guess::Restart_guess
    void Restart_guess(int zero);
    // EXTERNAL: TITANIUM 0x004DBB3B Timer_guess::Start_guess
    void Start_guess(void* anim_guess);
};

struct Controller_guess {
    char pad_0000[0x64];
    Timer_guess* timer_guess; // 0x64
};

struct Point_guess {
    int x_guess;
    int y_guess;
    Point_guess(int x, int y) : x_guess(x), y_guess(y) {}
};

struct StatsPane_guess {
    char pad_0000[0x20];
    Point_guess pos_20_guess; // 0x20
    char pad_0028[0x3c];
    unsigned int style_64_guess; // 0x64
    // EXTERNAL: TITANIUM 0x005A2490 StatsPane_guess::GetChild_guess
    Controller_guess* GetChild_guess(const CXStr& name_guess);
};

struct TaskPart_guess {
    char pad_0000[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0TaskPart_guess@@QAE@XZ
    TaskPart_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B TaskPart_guess::Start_guess
    void Start_guess(void* anim_guess);
    // EXTERNAL: TITANIUM 0x005B1EB0 ??1TaskPart_guess@@QAE@XZ
    ~TaskPart_guess();
    // EXTERNAL: TITANIUM 0x005B1AB0 TaskPart_guess::Attach_guess
    void Attach_guess(int value_guess);
};

struct TaskBase_guess {
    // EXTERNAL: TITANIUM 0x005A3900 ??0TaskBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    TaskBase_guess(CXWnd* parent_guess, const CXStr& screen_guess);
    // EXTERNAL: TITANIUM 0x005A3100 ??1TaskBase_guess@@UAE@XZ
    virtual ~TaskBase_guess();
};

struct RowInfo_guess {
    int id_guess; // 0x0
    int count_guess; // 0x4
    int limit_guess; // 0x8
    char pad_000c[4];
    bool enabled_guess; // 0x10
    char name_guess[1]; // 0x11
};

struct RowList_guess {
    int count_guess; // 0x0
    RowInfo_guess* rows_guess; // 0x4
    // EXTERNAL: TITANIUM 0x00432806 RowList_guess::GetRow_guess
    RowInfo_guess* GetRow_guess(int index_guess);
};

struct TaskState_guess {
    char pad_0000[0x2820];
    RowList_guess rows_guess; // 0x2820
    char pad_2828[8];
    char flag_2830_guess; // 0x2830
};

struct Clock_guess {
    char pad_0000[0x148];
    unsigned int tick_guess; // 0x148
};

struct Gadget_guess {
    char pad_0000[0x5d];
    unsigned char flag_5d_guess; // 0x5d
};

// EXTERNAL: TITANIUM 0x0065D968 ??_7CTaskTemplateSelectWnd_guess@@6B@
struct CTaskTemplateSelectWnd_guess : TaskBase_guess {
    char pad_0004[0x60];
    unsigned int style_64_guess; // 0x64
    char pad_0068[0xb8];
    LayoutRoot_guess layouts_guess; // 0x120
    void* sidlPiece_guess; // 0x124
    char pad_0128[0x30];
    int field_158_guess; // 0x158
    Entries_guess* firstEntries_guess; // 0x15c
    Entries_guess* secondEntries_guess; // 0x160
    Pane_guess* w164_guess; // 0x164
    Pane_guess* w168_guess; // 0x168
    CStmlWnd* stml_guess; // 0x16c
    Gadget_guess* gadget_guess; // 0x170
    char pad_0174[4];
    union {
        struct {
            Widget_guess* dataListLayout_guess; // 0x178
            Widget_guess* topLayout_guess; // 0x17c
            Widget_guess* selectionLayout_guess; // 0x180
        };
        Widget_guess* layouts_178_guess[3]; // 0x178
    };
    WidgetBase_guess* w184_guess; // 0x184
    TaskPart_guess part_guess; // 0x188
    WidgetBase_guess* row_guess[12]; // 0x1d4
    StatsPane_guess* statsPane_guess; // 0x204
    Controller_guess* controller_guess; // 0x208
    unsigned int tick_guess; // 0x20C

    CTaskTemplateSelectWnd_guess(CXWnd* parent_guess);
    virtual ~CTaskTemplateSelectWnd_guess();
    CTaskTemplateSelectWnd_guess* Delete_guess(unsigned char flags_guess);
    // EXTERNAL: TITANIUM 0x005A0E50 CTaskTemplateSelectWnd_guess::OnProcessFrame
    void OnProcessFrame();
    void OnTimer_guess();
    void ConfigureTemplateLayouts_guess();
    void ConfigureLayouts_guess();
    void ResetWidgets_guess();
    void AddRow_guess(RowInfo_guess* row_guess, bool flag_guess);
    int CurrentValue_guess();
    void RemoveValue_guess(int value);
    void RebuildLists_guess();
    void UpdateAcceptButton_guess();
    int GetOwnTemplateId_guess();
    char IsTemplateSelectable_guess(int value_guess);
    void ShowTemplate_guess();
    void NotifyAndUpdate_guess();
    char AboutToShow_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// Task template window destructor: deletes the controller's timer, if any, and clears the pointer.
// FUNCTION: TITANIUM 0x0055C55A
CTaskTemplateSelectWnd_guess::~CTaskTemplateSelectWnd_guess()
{
    if (controller_guess != 0) {
        Timer_guess* timer = controller_guess->timer_guess;
        if (timer != 0) {
            timer->Destroy_guess(1);
            controller_guess->timer_guess = 0;
        }
    }
}

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)
#define g_dashText_guess EQ_ARRAY(char, 0x0065AE40)
#define g_selectText_guess EQ_ARRAY(char, 0x0065DA88)
#define g_blankText_guess EQ_ARRAY(char, 0x0064DA6C)
#define g_countFormat_guess EQ_ARRAY(char, 0x0063F53C)

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* output_guess, const char* format_guess, ...);

struct LookupNode_guess {
    char name_guess[0x40];
    int value_guess; // 0x40
    char pad_0044[4];
    LookupNode_guess* next_guess; // 0x48
};

struct LookupList_guess {
    char pad_0000[0xb26b8];
    LookupNode_guess* first_guess; // 0xb26b8

    LookupNode_guess* Find_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x0043268C LookupList_guess::CountValue_guess
    int CountValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004322D2 LookupList_guess::GetTaskState_guess
    TaskState_guess* GetTaskState_guess(int index_guess, int category_guess, char allowEmpty_guess);
};

#include "titanium/layouts/core.h"

struct LookupRoot_guess {
    char pad_0000[8];
    VBTable* branch_guess; // 0x8
    char pad_000c[0x38];
    char name_guess[1]; // 0x44
};

#define g_lookupRoot_guess EQ_GLOBAL(LookupRoot_guess*, 0x00905D00)
#define g_lookupList_guess EQ_GLOBAL(LookupList_guess, 0x0079DC78)

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(char* first_guess, char* second_guess);

// Member entry by name (case-insensitive), or 0.
// FUNCTION: TITANIUM 0x0055C529
LookupNode_guess* LookupList_guess::Find_guess(char* name_guess)
{
    if (name_guess != 0) {
        LookupNode_guess* node_guess = first_guess;
        while (node_guess != 0) {
            if (__stricmp(node_guess->name_guess, name_guess) == 0) {
                return node_guess;
            }
            node_guess = node_guess->next_guess;
        }
    }
    return 0;
}

// Adds a template row to the required list (count > 0) or the optional one. Colours: green for the player's
// own pick, grey when disabled or its limit is taken, red while fewer than the required count are taken, else
// white. The second column shows how many are left.
// FUNCTION: TITANIUM 0x0055C5BE
void CTaskTemplateSelectWnd_guess::AddRow_guess(RowInfo_guess* row_guess, bool flag_guess)
{
    int index_guess = g_lookupList_guess.CountValue_guess(row_guess->id_guess);
    bool second_guess = row_guess->count_guess > 0;
    int color_guess;
    if (flag_guess) {
        color_guess = 0xff00ff00;
    } else if (!row_guess->enabled_guess || (row_guess->limit_guess > 0 && index_guess >= row_guess->limit_guess)) {
        color_guess = 0xff808080;
    } else {
        color_guess = index_guess < row_guess->count_guess ? 0xffff0000 : 0xffffffff;
    }
    CXStr text_guess(g_blankText_guess);
    if (row_guess->limit_guess > 0) {
        FormatString_guess(&text_guess, g_countFormat_guess, row_guess->limit_guess - index_guess);
    }
    Entries_guess* list_guess = second_guess ? secondEntries_guess : firstEntries_guess;
    if (list_guess != 0) {
        int newRow_guess = list_guess->AddString(g_emptyText_guess, color_guess, 0, 0);
        list_guess->SetItemText(newRow_guess, 0, row_guess->name_guess);
        list_guess->SetItemText(newRow_guess, 1, text_guess);
        list_guess->SetItemData(newRow_guess, row_guess->id_guess);
    }
}

// Blanks the description and icon and resets the stat labels ("select" for class, dashes for the rest).
// FUNCTION: TITANIUM 0x0055C71C
void CTaskTemplateSelectWnd_guess::ResetWidgets_guess()
{
    if (stml_guess != 0) {
        stml_guess->SetSTMLText(CXStr(g_emptyText_guess), false, 0);
    }
    if (w184_guess != 0) {
        w184_guess->Slot48_guess(0, 1);
    }
    if (row_guess[0] != 0) {
        CXStr text(g_selectText_guess);
        row_guess[0]->Slot63_guess(text);
    }
    if (row_guess[1] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[1]->Slot63_guess(text);
    }
    if (row_guess[2] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[2]->Slot63_guess(text);
    }
    if (row_guess[3] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[3]->Slot63_guess(text);
    }
    if (row_guess[4] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[4]->Slot63_guess(text);
    }
    if (row_guess[5] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[5]->Slot63_guess(text);
    }
    if (row_guess[6] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[6]->Slot63_guess(text);
    }
    if (row_guess[7] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[7]->Slot63_guess(text);
    }
    if (row_guess[8] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[8]->Slot63_guess(text);
    }
    if (row_guess[9] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[9]->Slot63_guess(text);
    }
    if (row_guess[10] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[10]->Slot63_guess(text);
    }
    if (row_guess[11] != 0) {
        CXStr text(g_dashText_guess);
        row_guess[11]->Slot63_guess(text);
    }
    if (w164_guess != 0) {
        w164_guess->Slot76_guess();
    }
    if (w168_guess != 0) {
        w168_guess->Slot76_guess();
    }
    if (gadget_guess != 0) {
        gadget_guess->flag_5d_guess = 0;
    }
}

// Restarts the class animation every 5 seconds.
// FUNCTION: TITANIUM 0x0055CAA3
void CTaskTemplateSelectWnd_guess::OnTimer_guess()
{
    Controller_guess* controller = controller_guess;
    if (controller != 0 && controller->timer_guess != 0) {
        if (g_clock_guess->tick_guess > tick_guess) {
            tick_guess = g_clock_guess->tick_guess + 5000;
            controller->timer_guess->Restart_guess(0);
        }
    }
    OnProcessFrame();
}

// Loads the three list layouts by name (TaskTemplateDataListLayout, TopLayout, SelectionLayout).
// FUNCTION: TITANIUM 0x0055CAE6
void CTaskTemplateSelectWnd_guess::ConfigureTemplateLayouts_guess()
{
    if (dataListLayout_guess != 0) {
        dataListLayout_guess->Slot73_guess(layouts_guess.GetLayout_guess("TaskTemplateDataListLayout"));
    }
    if (topLayout_guess != 0) {
        topLayout_guess->Slot73_guess(layouts_guess.GetLayout_guess("TaskTemplateTopLayout"));
    }
    if (selectionLayout_guess != 0) {
        selectionLayout_guess->Slot73_guess(layouts_guess.GetLayout_guess("TaskTemplateSelectionLayout"));
    }
}

// Saves the same three layouts (the pair of ConfigureTemplateLayouts_guess).
// FUNCTION: TITANIUM 0x0055CB6E
void CTaskTemplateSelectWnd_guess::ConfigureLayouts_guess()
{
    if (dataListLayout_guess != 0) {
        dataListLayout_guess->SetLayout_guess(layouts_guess.GetLayout_guess("TaskTemplateDataListLayout"));
    }
    if (topLayout_guess != 0) {
        topLayout_guess->SetLayout_guess(layouts_guess.GetLayout_guess("TaskTemplateTopLayout"));
    }
    if (selectionLayout_guess != 0) {
        selectionLayout_guess->SetLayout_guess(layouts_guess.GetLayout_guess("TaskTemplateSelectionLayout"));
    }
}

// Template id selected in the optional list, else in the required list, else 0.
// FUNCTION: TITANIUM 0x0055CBF6
int CTaskTemplateSelectWnd_guess::CurrentValue_guess()
{
    int value = 0;
    if (firstEntries_guess != 0 && firstEntries_guess->GetCurSel() >= 0) {
        value = firstEntries_guess->GetItemData(firstEntries_guess->GetCurSel());
    } else if (secondEntries_guess != 0 && secondEntries_guess->GetCurSel() >= 0) {
        value = secondEntries_guess->GetItemData(secondEntries_guess->GetCurSel());
    }
    return value;
}

// Removes the first row whose value (0x00597ED0) is `value`, searching the first list and then the
// second; only that one row goes.
// FUNCTION: TITANIUM 0x0055CC53
void CTaskTemplateSelectWnd_guess::RemoveValue_guess(int value)
{
    int list = 0;
    do {
        int index = 0;
        Entries_guess* entries;
        if (list == 0) {
            entries = firstEntries_guess;
        } else {
            entries = secondEntries_guess;
        }
        if (entries != 0 && entries->count_guess > 0) {
            do {
                if (entries->GetItemData(index) == value) {
                    entries->SetCurSel(index);
                    return;
                }
                ++index;
            } while (index < entries->count_guess);
        }
        ++list;
    } while (list < 2);
}

// Scalar deleting destructor of the task template window (vtable 0x65D968 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0055CCB2
CTaskTemplateSelectWnd_guess* CTaskTemplateSelectWnd_guess::Delete_guess(unsigned char flags_guess)
{
    this->CTaskTemplateSelectWnd_guess::~CTaskTemplateSelectWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// True when template `value_guess` is enabled and its limit is not yet taken.
// FUNCTION: TITANIUM 0x0055CCD6
char CTaskTemplateSelectWnd_guess::IsTemplateSelectable_guess(int value_guess)
{
    for (int list_guess = 0; list_guess < 1; ++list_guess) {
        TaskState_guess* state_guess = g_lookupList_guess.GetTaskState_guess(list_guess, 1, 1);
        if (state_guess != 0) {
            int count_guess = state_guess->rows_guess.count_guess;
            for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
                if (state_guess->rows_guess.GetRow_guess(index_guess)->id_guess == value_guess) {
                    int index = g_lookupList_guess.CountValue_guess(
                        state_guess->rows_guess.GetRow_guess(index_guess)->id_guess);
                    if (state_guess->rows_guess.GetRow_guess(index_guess)->enabled_guess == 0) {
                        return 0;
                    }
                    if (state_guess->rows_guess.GetRow_guess(index_guess)->limit_guess > 0 &&
                        index >= state_guess->rows_guess.GetRow_guess(index_guess)->limit_guess) {
                        return 0;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}

struct TaskInfo_guess {
    char pad_0000[0x14];
    int nameId_guess; // 0x14
    char pad_0018[0x28];
    int seconds_guess; // 0x40
};

struct TaskInfoTable_guess {
    // EXTERNAL: TITANIUM 0x00447D07 TaskInfoTable_guess::GetAltAbility
    TaskInfo_guess* GetAltAbility(int id_guess);
    // EXTERNAL: TITANIUM 0x00447D5B TaskInfoTable_guess::GetAbilityReqs_guess
    void GetAbilityReqs_guess(char* buffer_guess, TaskInfo_guess* info_guess);
};

struct DbStrings_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DbStrings_guess::GetString_guess
    char* GetString_guess(int id_guess, int kind_guess, int flag_guess);
};

#define g_taskInfoTable_guess EQ_GLOBAL(TaskInfoTable_guess*, 0x008511D8)
#define g_dbStrings_guess EQ_GLOBAL(DbStrings_guess*, 0x00850398)
#define g_brText_guess EQ_ARRAY(char, 0x0064DD5C)
#define g_timeFormat_guess EQ_ARRAY(char, 0x0064751C)

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* buffer_guess, const char* format_guess, ...);

struct TaskRequest_guess {
    int pad_00_guess;
    int pad_04_guess;
    int selected_guess; // 0x8
    int id_guess; // 0xc
};

// Description of the selected ability: string 3109 "Type: Activated, OnProcessFrame_guess Time:" with
// h:mm:ss, or 3110 for
// a passive one, plus its requirements (GetAbilityReqs_guess). Unknown abilities are requested with message
// 0x7135.
// FUNCTION: TITANIUM 0x0055CE86
void Browser_guess::ShowAbilityInfo_guess()
{
    if (stml_guess == 0) {
        return;
    }
    stml_guess->SetSTMLText(CXStr(g_emptyText_guess), true, 0);
    if (w184_guess != 0) {
        w184_guess->Slot48_guess(0, 1);
    }
    if (entries == 0) {
        return;
    }
    int id_guess = entries->GetItemData(entries->GetCurSel());
    TaskInfo_guess* info_guess = g_taskInfoTable_guess->GetAltAbility(id_guess);
    if (info_guess != 0) {
        CXStr text_guess;
        char buffer_guess[0x400];
        unsigned int total_guess = info_guess->seconds_guess;
        if (info_guess->seconds_guess > 0) {
            unsigned int hours_guess = total_guess / 3600;
            unsigned int seconds_guess = total_guess % 60;
            unsigned int minutes_guess = (total_guess / 60) % 60;
            text_guess += pStringTable->getString(0xc25, 0);
            sprintf(buffer_guess, g_timeFormat_guess, hours_guess, minutes_guess, seconds_guess);
            text_guess += buffer_guess;
        } else {
            text_guess += pStringTable->getString(0xc26, 0);
        }
        text_guess += g_brText_guess;
        g_taskInfoTable_guess->GetAbilityReqs_guess(buffer_guess, info_guess);
        text_guess += buffer_guess;
        text_guess += g_brText_guess;
        int nameId_guess = info_guess->nameId_guess;
        text_guess += g_dbStrings_guess->GetString_guess(nameId_guess, 4, 0);
        stml_guess->SetSTMLText(text_guess, true, 0);
    } else {
        TaskRequest_guess request_guess;
        request_guess.selected_guess = ((CTaskTemplateSelectWnd_guess*)this)->CurrentValue_guess();
        request_guess.id_guess = id_guess;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x7135, &request_guess, sizeof(request_guess), 1);
    }
}

// Template id the player already picked (looked up by the player's name), or 0.
// FUNCTION: TITANIUM 0x0055D0B1
int CTaskTemplateSelectWnd_guess::GetOwnTemplateId_guess()
{
    int value = 0;
    LookupRoot_guess* root = g_lookupRoot_guess;
    if (root != 0) {
        LookupNode_guess* node = g_lookupList_guess.Find_guess(
            (char*)root + root->branch_guess->vbase_offset + 0x44);
        if (node != 0) {
            value = node->value_guess;
        }
    }
    return value;
}

// Rebuilds both lists from the task's template rows, marking the player's pick, then drops the current
// selection's row.
// FUNCTION: TITANIUM 0x0055D0DD
void CTaskTemplateSelectWnd_guess::RebuildLists_guess()
{
    int value_guess = CurrentValue_guess();
    int id_guess = GetOwnTemplateId_guess();
    if (firstEntries_guess != 0) {
        ((Pane_guess*)firstEntries_guess)->Slot76_guess();
    }
    if (secondEntries_guess != 0) {
        ((Pane_guess*)secondEntries_guess)->Slot76_guess();
    }
    TaskState_guess* state_guess = g_lookupList_guess.GetTaskState_guess(0, 1, 1);
    if (state_guess != 0) {
        int count_guess = state_guess->rows_guess.count_guess;
        if (count_guess > 0) {
            for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
                bool selected_guess = state_guess->rows_guess.GetRow_guess(index_guess)->id_guess == id_guess;
                AddRow_guess(state_guess->rows_guess.GetRow_guess(index_guess), selected_guess);
            }
        }
    }
    RemoveValue_guess(value_guess);
}

// Accept is enabled for a selectable template; once the player has picked, only while the task is not locked
// (+0x2830).
// FUNCTION: TITANIUM 0x0055D185
void CTaskTemplateSelectWnd_guess::UpdateAcceptButton_guess()
{
    char flag_guess = IsTemplateSelectable_guess(CurrentValue_guess());
    if (flag_guess != 0 && g_lookupRoot_guess != 0) {
        LookupNode_guess* node_guess = g_lookupList_guess.Find_guess(
            &g_lookupRoot_guess->name_guess[g_lookupRoot_guess->branch_guess->vbase_offset]);
        if (node_guess != 0 && node_guess->value_guess != 0) {
            TaskState_guess* state_guess = g_lookupList_guess.GetTaskState_guess(0, 1, 1);
            if (state_guess != 0) {
                flag_guess = state_guess->flag_2830_guess == 0;
            }
        }
    }
    if (gadget_guess != 0) {
        gadget_guess->flag_5d_guess = flag_guess;
    }
}

// Task template window: when the selected row of the abilities list (+0x164) is ability `value`,
// redraws its description (0x0055CE86). The task dispatcher calls it when ability info arrives.
// FUNCTION: TITANIUM 0x0055D1F3
void Browser_guess::Check_guess(int value)
{
    if (entries != 0) {
        if (entries->GetItemData(entries->GetCurSel()) == value) {
            ShowAbilityInfo_guess();
        }
    }
}

struct Item_guess {
    char pad_0000[8];
    int value_guess; // 0x8
};

struct MatchNode_guess {
    char pad_0000[4];
    int field4_guess; // 0x4
    int field8_guess; // 0x8
    CXStr text_guess; // 0xc
    CXStr first_guess; // 0x10
    CXStr second_guess; // 0x14
};

struct Match_guess {
    // EXTERNAL: TITANIUM 0x00490D40 Match_guess::FindCachedItem_guess
    MatchNode_guess* FindCachedItem_guess(int value_guess);
};

#define g_match_guess EQ_GLOBAL(Match_guess, 0x00903EA0)

struct ListWnd_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059CE00 ListWnd_guess::Probe_guess
    bool Probe_guess();
};

struct Picker_guess {
    char pad_0000[0x168];
    ListWnd_guess* list_guess; // 0x168
    CStmlWnd* stml_guess; // 0x16c
    char pad_0170[0x14];
    WidgetBase_guess* w184_guess; // 0x184
    TaskPart_guess part_guess; // 0x188

    void ShowEquipmentInfo_guess();
    void OnSelect_guess(Item_guess* item_guess);
};

// Shows the selected equipment item's description from the item cache; an uncached item is requested with
// message 0x67C6 (item id, template id).
// FUNCTION: TITANIUM 0x0055CD7B
void Picker_guess::ShowEquipmentInfo_guess()
{
    if (stml_guess != 0) {
        stml_guess->SetSTMLText(CXStr(g_emptyText_guess), true, 0);
        if (list_guess != 0) {
            ((CTaskTemplateSelectWnd_guess*)this)->CurrentValue_guess();
            int value_guess = list_guess->GetItemData(list_guess->GetCurSel());
            MatchNode_guess* node_guess = g_match_guess.FindCachedItem_guess(value_guess);
            if (node_guess != 0) {
                stml_guess->SetSTMLText(CXStr(node_guess->text_guess), true, 0);
                if (w184_guess != 0) {
                    w184_guess->Slot48_guess(1, 1);
                    w184_guess->SetFlag_guess(1);
                    w184_guess->flag_16c_guess = 0;
                    w184_guess->owner_158_guess = &part_guess;
                    part_guess.Attach_guess(node_guess->field4_guess);
                }
            } else {
                TaskRequest_guess request_guess;
                request_guess.id_guess = value_guess;
                request_guess.selected_guess = ((CTaskTemplateSelectWnd_guess*)this)->CurrentValue_guess();
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x67c6, &request_guess, sizeof(request_guess), 1);
            }
        }
    }
}

// Reply to the description request (0x67C6) that 0x0055CD7B sends for an uncached template: once the task
// dispatcher has cached the text, redraws the description if the list is the window manager's current
// window (0x0059CE00) and that template is still selected.
// FUNCTION: TITANIUM 0x0055D222
void Picker_guess::OnSelect_guess(Item_guess* item_guess)
{
    if (list_guess != 0 && item_guess != 0 && g_match_guess.FindCachedItem_guess(item_guess->value_guess) != 0 &&
        list_guess != 0 && list_guess->Probe_guess()) {
        if (list_guess->GetItemData(list_guess->GetCurSel()) == item_guess->value_guess) {
            ShowEquipmentInfo_guess();
        }
    }
}

struct Entry1_guess {
    int value_guess; // 0x0
    int id_guess;    // 0x4
};

struct Entry2_guess {
    int value_guess;     // 0x0
    char name_guess[1];  // 0x4
};

struct NodeList_guess {
    char pad_0000[0x10];
    // EXTERNAL: TITANIUM 0x004466FA NodeList_guess::First_guess
    void* First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A NodeList_guess::Next_guess
    void* Next_guess(void* iter_guess);
};

struct Rec_guess {
    char pad_0000[0x44];
    char name_guess[1];           // 0x44
    char pad_0045[0xfec - 0x45];
    int classIndex_0fec_guess;                // 0xfec
    char pad_0ff0[4];
    int level_0ff4_guess;                // 0xff4
    char pad_0ff8[4];
    int ffc_guess;                // 0xffc
    int f1000_guess;              // 0x1000
    int f1004_guess;
    int f1008_guess;
    int f100c_guess;
    int f1010_guess;
    int f1014_guess;
    int f1018_guess;
    int f101c_guess;
    int f1020_guess;              // 0x1020
    char pad_1024[4];
    NodeList_guess list1_guess;   // 0x1028
    NodeList_guess list2_guess;   // 0x1038
};

struct RecTable_guess {
    // EXTERNAL: TITANIUM 0x004C9733 RecTable_guess::Find_guess
    Rec_guess* Find_guess(int value_guess);
};
#define g_recTable_guess EQ_GLOBAL(RecTable_guess*, 0x00985CEC)

struct AnimMgr_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 AnimMgr_guess::Find_guess
    void* Find_guess(const CXStr& name_guess);
};
#define g_animMgr_guess EQ_GLOBAL(AnimMgr_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x00416C2C ClassName_guess
char* __cdecl ClassName_guess(int id_guess);

struct ReqBuf_guess {
    char pad_0000[8];
    int value_guess;        // 0x8
    char pad_000c[4];
    char text_guess[0x1000]; // 0x10
    // EXTERNAL: TITANIUM 0x004321CB ReqBuf_guess::ReqBuf_guess
    ReqBuf_guess();
};

// Fills the stat labels, the abilities and equipment lists and the class animation (A_ClassAnim<class>) for
// the selected template; a template not cached yet is asked
// for instead with OP_AnnoyingZoneUnknown (0x729C, 0x1010 bytes, id at +8); the dispatcher hands the
// reply on the same opcode to 0x00433887.
// FUNCTION: TITANIUM 0x0055D283
void CTaskTemplateSelectWnd_guess::ShowTemplate_guess()
{
    ResetWidgets_guess();
    int value_guess = CurrentValue_guess();
    Rec_guess* rec_guess = g_recTable_guess->Find_guess(value_guess);
    // A cached template: class name, level and the stats HP to WIS as numbers.
    if (rec_guess != 0) {
    CXStr label_guess;
    if (row_guess[0] != 0) {
        CXStr text_guess(ClassName_guess(rec_guess->classIndex_0fec_guess));
        row_guess[0]->Slot63_guess(text_guess);
    }
    FormatString_guess(&label_guess, "level %d", rec_guess->level_0ff4_guess);
    if (row_guess[1] != 0) {
        row_guess[1]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->ffc_guess);
    if (row_guess[2] != 0) {
        row_guess[2]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1000_guess);
    if (row_guess[3] != 0) {
        row_guess[3]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1004_guess);
    if (row_guess[4] != 0) {
        row_guess[4]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1008_guess);
    if (row_guess[5] != 0) {
        row_guess[5]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f100c_guess);
    if (row_guess[6] != 0) {
        row_guess[6]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1010_guess);
    if (row_guess[7] != 0) {
        row_guess[7]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1014_guess);
    if (row_guess[8] != 0) {
        row_guess[8]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1018_guess);
    if (row_guess[9] != 0) {
        row_guess[9]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f101c_guess);
    if (row_guess[10] != 0) {
        row_guess[10]->Slot63_guess(label_guess);
    }
    FormatString_guess(&label_guess, g_countFormat_guess, rec_guess->f1020_guess);
    if (row_guess[11] != 0) {
        row_guess[11]->Slot63_guess(label_guess);
    }
    // Abilities and equipment lists, the description, then A_ClassAnim%02d by class.
    if (w164_guess != 0) {
        void* iter_guess = rec_guess->list1_guess.First_guess();
        while (iter_guess != 0) {
            Entry1_guess* entry_guess = *(Entry1_guess**)iter_guess;
            int row_index = 0;
            {
                CXStr text_guess(g_dbStrings_guess->GetString_guess(entry_guess->id_guess, 1, 0));
                row_index = ((Entries_guess*)w164_guess)->AddString(text_guess, -1, 0, 0);
            }
            ((Entries_guess*)w164_guess)->SetItemData(row_index, entry_guess->value_guess);
            iter_guess = rec_guess->list1_guess.Next_guess(iter_guess);
        }
        ((Entries_guess*)w164_guess)->field154_guess = 0;
        ((Entries_guess*)w164_guess)->flag158_guess = 1;
        w164_guess->Slot78_guess();
    }
    if (w168_guess != 0) {
        void* iter_guess = rec_guess->list2_guess.First_guess();
        while (iter_guess != 0) {
            Entry2_guess* entry_guess = *(Entry2_guess**)iter_guess;
            int row_index = 0;
            {
                CXStr empty_guess(g_emptyText_guess);
                row_index = ((Entries_guess*)w168_guess)->AddString(empty_guess, -1, 0, 0);
            }
            ((Entries_guess*)w168_guess)->SetItemData(row_index, entry_guess->value_guess);
            {
                CXStr name_guess(entry_guess->name_guess);
                ((Entries_guess*)w168_guess)->SetItemText(row_index, 0, name_guess);
            }
            iter_guess = rec_guess->list2_guess.Next_guess(iter_guess);
        }
    }
    if (stml_guess != 0) {
        if (w168_guess != 0 && ((ListWnd_guess*)w168_guess)->Probe_guess()) {
            ((Picker_guess*)this)->ShowEquipmentInfo_guess();
        } else if (w168_guess != 0 && ((ListWnd_guess*)w168_guess)->Probe_guess()) {
            ((Browser_guess*)this)->ShowAbilityInfo_guess();
        } else {
            stml_guess->SetSTMLText(CXStr(rec_guess->name_guess), true, 0);
        }
    }
    if (controller_guess != 0 && controller_guess->timer_guess != 0) {
        CXStr anim_guess;
        FormatString_guess(&anim_guess, "A_ClassAnim%02d", rec_guess->classIndex_0fec_guess);
        void* anim_ptr = g_animMgr_guess->Find_guess(anim_guess);
        if (anim_ptr != 0) {
            controller_guess->timer_guess->Start_guess(anim_ptr);
            controller_guess->timer_guess->flag_2d_guess = 0;
        }
    }
    if (gadget_guess != 0) {
        gadget_guess->flag_5d_guess = 1;
    }
    } else {
        ReqBuf_guess buf_guess;
        buf_guess.value_guess = value_guess;
        EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x729c, &buf_guess, 0x1010, 1);
    }
}

// Task template window: rebuilds both template lists (0x0055D0DD) and redraws the selected template
// (0x0055D283). Called when a task is cancelled, when its description arrives and when the shared-task
// entries change.
// FUNCTION: TITANIUM 0x0055D8BA
void CTaskTemplateSelectWnd_guess::NotifyAndUpdate_guess()
{
    RebuildLists_guess();
    ShowTemplate_guess();
}

// CTaskTemplateSelectWnd constructor ("TaskTemplateSelectWnd"): the optional and required template lists,
// the abilities and equipment lists, the twelve stat labels and the class animation in the stats pane.
// FUNCTION: TITANIUM 0x0055D8CA
CTaskTemplateSelectWnd_guess::CTaskTemplateSelectWnd_guess(CXWnd* parent_guess)
    : TaskBase_guess(parent_guess, "TaskTemplateSelectWnd")
{
    stml_guess = 0;
    firstEntries_guess = 0;
    secondEntries_guess = 0;
    w164_guess = 0;
    w168_guess = 0;
    gadget_guess = 0;
    w184_guess = 0;
    row_guess[0] = 0;
    row_guess[1] = 0;
    row_guess[2] = 0;
    row_guess[3] = 0;
    row_guess[4] = 0;
    row_guess[5] = 0;
    row_guess[6] = 0;
    row_guess[7] = 0;
    row_guess[8] = 0;
    row_guess[9] = 0;
    row_guess[10] = 0;
    row_guess[11] = 0;
    statsPane_guess = 0;
    controller_guess = 0;
    tick_guess = 0;
    for (int i = 0; i < 3; i++) {
        layouts_178_guess[i] = 0;
    }
    if (sidlPiece_guess == 0) {
        return;
    }
    style_64_guess |= 0x10000;
    field_158_guess = 0x47;
    CSidlScreenWnd* sidl_guess = (CSidlScreenWnd*)this;
    sidl_guess->CreateChildrenFromSidl();
    stml_guess = (CStmlWnd*)sidl_guess->GetChildItem("TaskTemplateSelectDescription");
    firstEntries_guess = (Entries_guess*)sidl_guess->GetChildItem("TaskTemplateSelectListOptional");
    secondEntries_guess = (Entries_guess*)sidl_guess->GetChildItem("TaskTemplateSelectListRequired");
    w164_guess = (Pane_guess*)sidl_guess->GetChildItem("TaskTemplateSelectAbilitiesList");
    w168_guess = (Pane_guess*)sidl_guess->GetChildItem("TaskTemplateSelectEquipmentList");
    w184_guess = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_IconButton");
    gadget_guess = (Gadget_guess*)sidl_guess->GetChildItem("TaskTemplateSelectAcceptButton");
    row_guess[0] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatClassValueLabel");
    row_guess[1] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatLevelValueLabel");
    row_guess[2] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatHitPointsValueLabel");
    row_guess[3] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatManaValueLabel");
    row_guess[4] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatEnduranceValueLabel");
    row_guess[5] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatStrengthValueLabel");
    row_guess[6] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatStaminaValueLabel");
    row_guess[7] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatCharismaValueLabel");
    row_guess[8] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatDexterityValueLabel");
    row_guess[9] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatIntelligenceValueLabel");
    row_guess[10] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatAgilityValueLabel");
    row_guess[11] = (WidgetBase_guess*)sidl_guess->GetChildItem("TaskTemplate_StatWisdomValueLabel");
    statsPane_guess = (StatsPane_guess*)sidl_guess->GetChildItem("TaskTemplateStatsPane");
    dataListLayout_guess = (Widget_guess*)sidl_guess->GetChildItem("TaskTemplateDataListLayout");
    topLayout_guess = (Widget_guess*)sidl_guess->GetChildItem("TaskTemplateTopLayout");
    selectionLayout_guess = (Widget_guess*)sidl_guess->GetChildItem("TaskTemplateSelectListLayout");
    if (statsPane_guess != 0) {
        controller_guess = statsPane_guess->GetChild_guess("TaskTemplate_StatClassAnim");
        statsPane_guess->style_64_guess &= ~0x800;
        if (controller_guess != 0) {
            controller_guess->timer_guess = new Timer_guess;
        }
    }
    // List colours as in the progression window (tu_200) except the third, 0xFF808080 here against 0xFF324080
    // there; abilities and equipment get style 0x40000.
    if (firstEntries_guess != 0) {
        ((CListWnd*)firstEntries_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        firstEntries_guess->color_16c_guess = 0xff8aa3ff;
    }
    if (secondEntries_guess != 0) {
        ((CListWnd*)secondEntries_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        secondEntries_guess->color_16c_guess = 0xff8aa3ff;
    }
    if (w164_guess != 0) {
        ((CListWnd*)w164_guess)->WindowStyle |= 0x40000;
        ((CListWnd*)w164_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        w164_guess->flag_16c_guess = 0xff8aa3ff;
    }
    if (w168_guess != 0) {
        ((CListWnd*)w168_guess)->WindowStyle |= 0x40000;
        ((CListWnd*)w168_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        w168_guess->flag_16c_guess = 0xff8aa3ff;
    }
    if (statsPane_guess != 0) {
        statsPane_guess->pos_20_guess = Point_guess(0x6c, 0);
    }
    if (gadget_guess != 0) {
        gadget_guess->flag_5d_guess = 0;
    }
    void* anim_guess = g_animMgr_guess->Find_guess("A_DragItem");
    if (anim_guess != 0) {
        part_guess.Start_guess(anim_guess);
    }
    // Item icon from a copy of A_DragItem, then the layouts are sized.
    ConfigureTemplateLayouts_guess();
}

// On open: sends message 0x64D7 (8 bytes), rebuilds the lists and adjusts the selection around the player's
// own pick.
// FUNCTION: TITANIUM 0x0055E061
char CTaskTemplateSelectWnd_guess::AboutToShow_guess()
{
    int buffer_guess[2];
    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x64d7, buffer_guess, 8, 1);
    RebuildLists_guess();
    char found_guess = 0;
    int list_guess = 0;
    do {
        if (found_guess != 0) {
            break;
        }
        Entries_guess* entries_guess;
        if (list_guess == 0) {
            entries_guess = firstEntries_guess;
        } else {
            entries_guess = secondEntries_guess;
        }
        if (entries_guess != 0) {
            entries_guess->SetCurSel(0);
            int value_guess = GetOwnTemplateId_guess();
            if (value_guess != 0) {
                int count_guess = entries_guess->count_guess;
                for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
                    if (entries_guess->GetItemData(index_guess) == value_guess) {
                        entries_guess->SetCurSel(index_guess);
                        found_guess = 1;
                        break;
                    }
                }
            }
        }
        ++list_guess;
    } while (list_guess < 2);
    ShowTemplate_guess();
    return 1;
}

struct ModeActions_guess {
    // EXTERNAL: TITANIUM 0x005B9670 ModeActions_guess::SetText_guess
    void SetText_guess(const char* first_guess, const char* second_guess);
};

struct ModeRoot_guess {
    char padding_0000_guess[0x160];
    ModeActions_guess* field160_guess;
};

struct ModeProvider_guess {
    // EXTERNAL: TITANIUM 0x004F288C ModeProvider_guess::GetActiveChatWindow_guess
    ModeRoot_guess* GetActiveChatWindow_guess();
};

#define pinstCChatManager_guess EQ_GLOBAL(ModeProvider_guess*, 0x009917E4)

// List clicks keep one selection across both lists and refresh the stats; Accept sends message 0x4EDB with
// the template id.
// FUNCTION: TITANIUM 0x0055E113
int CTaskTemplateSelectWnd_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess)
{
    if (message_guess == 1) {
        if (sender_guess == (CXWnd*)firstEntries_guess || sender_guess == (CXWnd*)secondEntries_guess) {
            Entries_guess* other_guess = firstEntries_guess;
            if (sender_guess == (CXWnd*)other_guess) {
                other_guess = secondEntries_guess;
            }
            if (other_guess != 0) {
                ((CListWnd*)other_guess)->ClearAllSel();
            }
            ShowTemplate_guess();
            UpdateAcceptButton_guess();
        } else if (sender_guess == (CXWnd*)w164_guess) {
            ((Browser_guess*)this)->ShowAbilityInfo_guess();
        } else if (sender_guess == (CXWnd*)w168_guess) {
            ((Picker_guess*)this)->ShowEquipmentInfo_guess();
        } else if (sender_guess == (CXWnd*)gadget_guess) {
            int value_guess = CurrentValue_guess();
            if (value_guess != 0) {
                int buffer_guess[3];
                buffer_guess[2] = value_guess;
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x4edb, buffer_guess, 12, 1);
            }
        } else if (sender_guess == (CXWnd*)w184_guess) {
            CurrentValue_guess();
            if (w168_guess != 0) {
                int cur_guess = ((CListWnd*)w168_guess)->GetCurSel();
                int value_guess = (int)((CListWnd*)w168_guess)->GetItemData(cur_guess);
                MatchNode_guess* node_guess = g_match_guess.FindCachedItem_guess(value_guess);
                if (node_guess != 0 && node_guess->field8_guess == 0) {
                    ModeActions_guess* actions_guess = pinstCChatManager_guess->GetActiveChatWindow_guess()->field160_guess;
                    if (actions_guess != 0) {
                        actions_guess->SetText_guess(node_guess->second_guess, node_guess->first_guess);
                        ((CXWnd*)actions_guess)->SetFocus();
                    }
                }
            }
        }
    } else if (message_guess == 3) {
        if (sender_guess == (CXWnd*)w168_guess) {
            ((Picker_guess*)this)->ShowEquipmentInfo_guess();
        } else if (sender_guess == (CXWnd*)w164_guess) {
            ((Browser_guess*)this)->ShowAbilityInfo_guess();
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}
