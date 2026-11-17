// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 98: a hint from compare/tumap.py.
// CAAWnd ("AAWindow"), the alternate advancement window: CAAWndView_guess is CAAWnd (vtable 0x64DAE0, ctor
// 0x4D0A8F per names.tsv), AAWndConfirmCallback_guess its confirmation-dialog owner at +0x15C. 11 tabs (Page1-11/List1-11)
// hold up to 50 abilities each as (ability id, list row) pairs. Abilities go through OP_AAAction (0x681,
// 16 bytes: action, ability, target, exp value). g_status_guess is pCharData; +0xE2D is the AA exp percent.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>

void __debugbreak(void);

struct EntryPair_guess {
    int first_guess;
    int second_guess;
};

struct Entry_guess {
    EntryPair_guess pairs_guess[50];

    Entry_guess* Get_guess(unsigned int index);
    // EXTERNAL: TITANIUM 0x004D0423 Entry_guess::GetExternal_guess
    Entry_guess* GetExternal_guess(unsigned int index);
    EntryPair_guess& Pair_guess(unsigned int index) {
        if (index >= 50)
            __debugbreak();
        return pairs_guess[index];
    }
};

struct CountArray_guess {
    int items_guess[11];
    int& operator[](unsigned int index) {
        if (index < 11)
            return items_guess[index];
        __debugbreak();
        return items_guess[index];
    }
};

struct TabWnd_guess {
    // EXTERNAL: TITANIUM 0x005BC4B0 TabWnd_guess::InsertPage_guess
    void InsertPage_guess(CXWnd* page_guess);
    // EXTERNAL: TITANIUM 0x005BC840 TabWnd_guess::SetPageVisible_guess
    void SetPageVisible_guess(CXWnd* page_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005BC460 TabWnd_guess::SetPage_guess
    void SetPage_guess(CXWnd* page_guess, int value_guess);
};

struct CharInfo_guess {
    char pad_0[0x11a4];
    int level_11a4_guess;
};

struct Panel_guess {
    char pad_0[0x5d];
    char flag_5d_guess;
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    const char* getString(int id_guess, int default_guess);
};

#define g_strings_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CTipWnd.h"

// A list child: colors at +0x16C, flag at +0x15C.
struct AAList_guess : CListWnd {
    char pad_140[0x154 - 0x140];
    int field_154_guess;
    unsigned char field_158_guess;
    char pad_159[0x15c - 0x159];
    unsigned char flag_15c_guess;
    char pad_15d[0x16c - 0x15d];
    unsigned int color_16c_guess;

    // EXTERNAL: TITANIUM 0x0059B360 AAList_guess::SetItemText
    void SetItemText(int index, int column, const CXStr& text);
    // EXTERNAL: TITANIUM 0x0059B3E0 AAList_guess::SetItemColor_guess
    void SetItemColor_guess(int index, int column, unsigned long color);
};

// A child window called through its vtable (slot 48 at +0xC0, called with (0, 1)).
struct AAChild_guess {
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
    virtual void Show_guess(bool show_guess, bool bringToTop_guess);
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
    virtual void SetWindowText_guess(const CXStr& text_guess);
    virtual void SetScroll_guess(int pos_guess);
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();

    char pad_4[0x5d - 4];
    unsigned char enabled_5d_guess;
    char pad_5e[0x10c - 0x5e];
    int scroll_10c_guess;
};

// Bounds-checked arrays of 11 child windows.
struct PageArray_guess {
    CXWnd* items_guess[11];
    CXWnd*& operator[](unsigned int index) {
        if (index < 11)
            return items_guess[index];
        __debugbreak();
        return items_guess[index];
    }
};

struct ListArray_guess {
    AAList_guess* items_guess[11];
    AAList_guess*& operator[](unsigned int index) {
        if (index < 11)
            return items_guess[index];
        __debugbreak();
        return items_guess[index];
    }
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7AAWndConfirmCallback_guess@@6B@
struct AAWndConfirmCallback_guess {
    // EXTERNAL: TITANIUM 0x005482A0 AAWndConfirmCallback_guess::Stop_guess
    void Stop_guess(int value);
    void OnTrainConfirm_guess(int event_guess, unsigned char flags_guess, int data_guess);
    virtual ~AAWndConfirmCallback_guess() { Stop_guess(-1); }
};

// EXTERNAL: TITANIUM 0x0064DAE0 ??_7CAAWndView_guess@@6BCSidlScreenWndBase@@@
// EXTERNAL: TITANIUM 0x0064DAD8 ??_7CAAWndView_guess@@6BAAWndConfirmCallback_guess@@@
struct CAAWndView_guess : CSidlScreenWndBase, AAWndConfirmCallback_guess {
    int listCount_160_guess;
    char flag_164_guess;
    char pad_165[0x168 - 0x165];
    CXWnd* percentLabel_168_guess;
    CXWnd* expCount_16c_guess;
    CXWnd* expGauge_170_guess;
    CXWnd* lessExpButton_174_guess;
    CXWnd* moreExpButton_178_guess;
    Panel_guess* panel_17c_guess;
    Panel_guess* hotButton_180_guess;
    AAChild_guess* loadSaveLabel_184_guess;
    AAChild_guess* loadButton_188_guess;
    AAChild_guess* saveButton_18c_guess;
    CXWnd* doneButton_190_guess;
    CXWnd* description_194_guess;
    CXWnd* currentLabel_198_guess;
    CXWnd* monsterLabel_19c_guess;
    CXWnd* totalLabel_1a0_guess;
    CXWnd* totalCount_1a4_guess;
    CXWnd* currentCount_1a8_guess;
    CXWnd* expCount_1ac_guess;
    CXWnd* subwindows_1b0_guess;
    union {
        PageArray_guess pages_1b4_guess;
        int controlIds_1b4_guess[11];
    };
    ListArray_guess lists_1e0_guess;
    CXWnd* timer_20c_guess;
    CountArray_guess counts_210_guess;
    Entry_guess entries_23c_guess[11];
    unsigned int entryIndex_136c_guess;
    unsigned int bookIndex_1370_guess;
    int points_1374_guess;
    int spent_1378_guess;
    int percent_137c_guess;
    unsigned int lastTick_1380_guess;

    CAAWndView_guess(CXWnd* parent);
    ~CAAWndView_guess();
    void Cleanup_guess() { this->CAAWndView_guess::~CAAWndView_guess(); }
    CAAWndView_guess* Destroy_guess(unsigned char destroyFlag_guess);
    void OnProcessFrame_guess();
    void UpdateTimer_guess();
    void SendTrainAbility_guess();
    void LoadAbilitySets_guess();
    // EXTERNAL: TITANIUM 0x004D024B CAAWndView_guess::SendAAExpPercent_guess
    void SendAAExpPercent_guess();
    void SaveAbilitySet_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
    // EXTERNAL: TITANIUM 0x004D06E9 CAAWndView_guess::BuildAbilityLists_guess
    void BuildAbilityLists_guess();
    // EXTERNAL: TITANIUM 0x004D1484 CAAWndView_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x004D1190 CAAWndView_guess::UpdateSelected_guess
    void UpdateSelected_guess();
    bool Activate_guess();
    void SelectAbility_guess(int id_guess);
};

struct InnerState_guess {
    // EXTERNAL: TITANIUM 0x005482A0 InnerState_guess::Stop_guess
    void Stop_guess(int value);
};


struct Window_guess {
    char pad_0[0x5c];
    char Show;
    char pad_5d[0xff];
    InnerState_guess inner_15c_guess;
    // EXTERNAL: TITANIUM 0x005A1880 Window_guess::OnShow
    void OnShow();
    void Update_guess();
};

struct IndexTable_guess {
    char pad_0_guess[0x1228];
    int count_1228_guess;
};

struct StatusHead_guess {
    int head_0_guess;
    int head_4_guess;
};

struct StatusBase_guess : EQ_Character {
    // EXTERNAL: TITANIUM 0x00447CB1 StatusBase_guess::IsStatusOneOrTwo_guess
    char IsStatusOneOrTwo_guess();
    // EXTERNAL: TITANIUM 0x004167E2 StatusBase_guess::GetStatus_guess
    int GetStatus_guess();
    int Level_guess() { return ((CharInfo_guess*)GetCharInfo2())->level_11a4_guess; }
    bool IsActive_guess() { return GetStatus_guess() == 0; }
    void Profile_guess() { GetCharInfo2(); }
};

struct Status_guess {
    char pad_0[0xe25];
    unsigned char flag_e25_guess;
    char pad_e26[0xe2d - 0xe26];
    unsigned char value_e2d_guess;

    // EXTERNAL: TITANIUM 0x005ED490 Status_guess::GetIndexTable_guess
    IndexTable_guess* GetIndexTable_guess();
    // EXTERNAL: TITANIUM 0x004BAAEB Status_guess::HasAltAbility_guess
    char HasAltAbility_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005F0BD0 Status_guess::Ready_guess
    int Ready_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ED730 Status_guess::GetPoints_guess
    int GetPoints_guess();
};

// Same object as g_status, seen through its virtual base.
struct StatusView_guess : StatusHead_guess, virtual StatusBase_guess {
};

#define g_status_guess EQ_GLOBAL(Status_guess*, 0x00905D00)
#define g_statusView_guess EQ_GLOBAL(StatusView_guess*, 0x00905D00)

struct Node_guess {
    char pad_0[4];
    char valid_4_guess;
    char pad_5[0x14 - 5];
    int field_14_guess;
    char pad_18[0x1c - 0x18];
    int cost_1c_guess;
    int field_20_guess;
    int rank_24_guess;
    char pad_28[0x40 - 0x28];
    int field_40_guess;
    char pad_44[0x4c - 0x44];
    int spent_4c_guess;
    int prev_50_guess;

    // EXTERNAL: TITANIUM 0x00447959 Node_guess::MaxRank_guess
    int MaxRank_guess();
};

struct Row_guess {
    char pad_0[0x3c];
    int field_3c_guess;
};

struct TimerRow_guess {
    char pad_0[0x40];
    int time_40_guess;
};

struct TimerLookup_guess {
    // EXTERNAL: TITANIUM 0x00447D1F TimerLookup_guess::FindOwnedBySeq_guess
    TimerRow_guess* FindOwnedBySeq_guess(Status_guess* status_guess, int field_guess);
    // EXTERNAL: TITANIUM 0x00447BE2 TimerLookup_guess::GetRemaining_guess
    void GetRemaining_guess(Status_guess* status_guess, TimerRow_guess* row_guess, int* seconds_guess);
};

struct getString {
    // EXTERNAL: TITANIUM 0x00447D07 getString::GetAltAbility
    Node_guess* GetAltAbility(int id_guess);
    // EXTERNAL: TITANIUM 0x00447D1F getString::Check_guess
    Row_guess* Check_guess(Status_guess* status_guess, int field_guess);
    // EXTERNAL: TITANIUM 0x00448122 getString::CanPurchase_guess
    char CanPurchase_guess(Status_guess* status_guess, Node_guess* node_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00447D5B getString::GetAbilityReqs_guess
    void GetAbilityReqs_guess(char* buffer_guess, Node_guess* node_guess);
};

#define g_lookup_guess EQ_GLOBAL(getString*, 0x008511D8)
#define g_timerLookup_guess EQ_GLOBAL(TimerLookup_guess*, 0x008511D8)

struct DbStrings_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DbStrings_guess::GetString_guess
    char* GetString_guess(int id_guess, int kind_guess, int flag_guess);
};

#define g_dbStrings_guess EQ_GLOBAL(DbStrings_guess*, 0x00850398)
#define g_brText_guess EQ_ARRAY(char, 0x0064DD5C)
#define g_timeFormat_guess EQ_ARRAY(char, 0x0064751C)
#define g_idFormat_guess EQ_ARRAY(char, 0x0064DD64)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

struct Clock_guess {
    char pad_0[0x148];
    unsigned int ticks_148_guess;
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00559573 GetAbilitiesIniFilename_guess
const char* __cdecl GetAbilitiesIniFilename_guess();

// EXTERNAL: TITANIUM 0x00577000 FUN_00577000_guess
void __cdecl FUN_00577000_guess(char* buffer_guess, int size_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x00559573 FUN_00559573_address_guess
unsigned int __cdecl FUN_00559573_address_guess();

// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section_guess, const char* key_guess, const char* value_guess, const char* file_guess);

// EXTERNAL: TITANIUM 0x0060BE20 FUN_0060be20_guess
int __cdecl FUN_0060be20_guess(const char* section_guess, const char* key_guess, int default_guess, const char* file_guess);

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
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(const CXStr& text_guess);
};

struct MessageGroup_guess {
    char pad_0[0x78];
    int field_78_guess;
};

struct AbilityInfo_guess {
    char pad_0[8];
    int textId_8_guess;
    int textId_c_guess;
    int stringId_10_guess;
    char pad_14[8];
    int level_1c_guess;
    MessageGroup_guess* group_20_guess;
};

struct MessageWindow_guess {
    char pad_0[0x15c];
    int field_15c_guess;
};

struct AbilityText_guess {
    // EXTERNAL: TITANIUM 0x004FD91E AbilityText_guess::Set_guess
    void Set_guess(int a_guess, int b_guess, int* text_guess, char* d_guess);
    void Set_guess(int a_guess, int b_guess, int* text_guess, char* d_guess, int e_guess);
};

struct NotificationData_guess {
    int pad_0[2];
    int selection_8_guess;
};

#define pinstCAAWnd_guess EQ_GLOBAL(MessageWindow_guess*, 0x00850BD0)
#define pinstCCursorAttachment_guess EQ_GLOBAL(AbilityText_guess*, 0x00850C24)

// EXTERNAL: TITANIUM 0x0046DA4A BuildAbilityMessage_guess
void __cdecl BuildAbilityMessage_guess(char* message_guess, int stringId_guess, const char* number_guess,
                                       const char* name_guess, int a_guess, int b_guess, int c_guess,
                                       int d_guess, int e_guess, int f_guess, int g_guess);

// AA window destructor: unregisters the observer part at +0x15C (0x005482A0 with -1), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004D01CC
CAAWndView_guess::~CAAWndView_guess() {
}

// Show hook: shown, it pops context tip 2 (0x564E7E on 0x9928E0); hidden, it expires its train prompt.
// FUNCTION: TITANIUM 0x004D0218
void Window_guess::Update_guess() {
    if (Show != 0) {
        CTipWnd_guess* manager = pinstCTipWndCONTEXT_guess;
        if (manager != 0)
            manager->selectTip_guess(2, 0);
    } else {
        inner_15c_guess.Stop_guess(-1);
    }
    OnShow();
}

// Sends the AA exp split: action 1 with the percent, or action 2 (AA exp off) at 0%.
// FUNCTION: TITANIUM 0x004D024B
void __cdecl SendAAExpPercent_guess() {
    unsigned int data[4];
    memset(data, 0, 0x10);
    if (g_status_guess->value_e2d_guess == 0) {
        data[0] = 2;
    } else {
        data[0] = 1;
        data[3] = g_status_guess->value_e2d_guess;
    }
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AAAction, data, 0x10, 1);
}

// Scalar deleting destructor of the AA window: its cleanup, then operator delete with flag 1.
// FUNCTION: TITANIUM 0x004D02A0
CAAWndView_guess* CAAWndView_guess::Destroy_guess(unsigned char destroyFlag_guess) {
    Cleanup_guess();
    if ((destroyFlag_guess & 1) != 0)
        ::operator delete(this);
    return this;
}

// Load button: reads [AbilitySets] Set<n>.ability<k> (k < 100) from the UI INI file and buys each one not
// yet owned (action 7). Only for the character kind 0x447CB1 accepts, probably monster-mission
// characters; <n> is the template number at +0x1228. Strings 0x1F56-0x1F58 report failures.
// FUNCTION: TITANIUM 0x004D02BC
void CAAWndView_guess::LoadAbilitySets_guess() {
    int count;
    const char* file;
    int loaded;
    int index;
    int value;
    char name[32];
    unsigned int data[4];

    if (g_statusView_guess->IsStatusOneOrTwo_guess()) {
        count = g_status_guess->GetIndexTable_guess()->count_1228_guess;
        if (count > 0) {
            file = GetAbilitiesIniFilename_guess();
            if (file != 0) {
                FUN_00577000_guess(name, 0x20, "Set%d.inuse", count);
                if (FUN_0060be20_guess("AbilitySets", name, 0, file) != 0) {
                    loaded = 0;
                    panel_17c_guess->flag_5d_guess = 0;
                    for (index = 0; index < 100; index++) {
                        FUN_00577000_guess(name, 0x20, "Set%d.ability%d", count, index);
                        value = FUN_0060be20_guess("AbilitySets", name, 0, file);
                        if (value > 0 && !g_status_guess->HasAltAbility_guess(value)) {
                            memset(data, 0, 0x10);
                            data[0] = 7;
                            data[1] = value;
                            EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AAAction, data, 0x10, 1);
                            loaded++;
                        }
                    }
                    if (loaded != 0) {
                        return;
                    }
                    pEverQuest->dsp_chat(g_strings_guess->getString(0x1f57, 0), 0xf, 1);
                } else {
                    pEverQuest->dsp_chat(g_strings_guess->getString(0x1f58, 0), 0xf, 1);
                }
            } else {
                pEverQuest->dsp_chat(g_strings_guess->getString(0x1f58, 0), 0xf, 1);
            }
        } else {
            pEverQuest->dsp_chat(g_strings_guess->getString(0x1f56, 0), 0xf, 1);
        }
    } else {
        pEverQuest->dsp_chat(g_strings_guess->getString(0x1f56, 0), 0xf, 1);
    }
}

// Tab `index` (0-10) of the window's 11 ability tabs; larger traps.
// FUNCTION: TITANIUM 0x004D0423
Entry_guess* Entry_guess::Get_guess(unsigned int index) {
    if (index >= 11)
        __debugbreak();
    return this + index;
}

// CAAWnd::UpdateTimer (TAKP name): shows the selected ability's reuse timer as hh:mm:ss (string 0xC27
// when ready) and enables HotButton only for abilities with a timer.
// FUNCTION: TITANIUM 0x004D0438
// @early-stop: budget, structural ndiff=90
void CAAWndView_guess::UpdateTimer_guess() {
    int seconds_guess = 0;
    unsigned int index_guess = entryIndex_136c_guess;
    bool active_guess = false;

    if (index_guess != 0xffffffff) {
        Entry_guess* entry_guess = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
        if (index_guess >= 0x32)
            __debugbreak();
        Node_guess* node_guess = g_lookup_guess->GetAltAbility(entry_guess->pairs_guess[index_guess].first_guess);
        TimerRow_guess* row_guess = 0;
        if (node_guess != 0)
            row_guess = g_timerLookup_guess->FindOwnedBySeq_guess(g_status_guess, node_guess->field_20_guess);
        if (row_guess != 0 && row_guess->time_40_guess > 0) {
            active_guess = true;
            g_timerLookup_guess->GetRemaining_guess(g_status_guess, row_guess, &seconds_guess);
            if (timer_20c_guess != 0) {
                if (seconds_guess > 0) {
                    char buffer_guess[0x200];
                    sprintf(buffer_guess, "%02d:%02d:%02d", seconds_guess / 0xe10,
                            (seconds_guess / 0x3c) % 0x3c, seconds_guess % 0x3c);
                    CXStr text_guess(buffer_guess);
                    ((WidgetBase_guess*)timer_20c_guess)->Slot63_guess(text_guess);
                } else {
                    CXStr text_guess(pStringTable->getString(0xc27, 0));
                    ((WidgetBase_guess*)timer_20c_guess)->Slot63_guess(text_guess);
                }
            }
        } else if (timer_20c_guess != 0) {
            CXStr text_guess(EQ_ARRAY(char, 0x0063F53F));
            ((WidgetBase_guess*)timer_20c_guess)->Slot63_guess(text_guess);
        }
    }

    Panel_guess* panel_guess = hotButton_180_guess;
    if (panel_guess != 0 && panel_guess->flag_5d_guess != active_guess)
        panel_guess->flag_5d_guess = active_guess;
}

// OnProcessFrame: while the selected ability's timer (0-29) is running, updates the timer every 2 s.
// FUNCTION: TITANIUM 0x004D0638
void CAAWndView_guess::OnProcessFrame_guess() {
    if (Show != 0) {
        unsigned int index = entryIndex_136c_guess;
        if ((int)index >= 0) {
            Entry_guess* entry = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
            if (index >= 0x32)
                __debugbreak();
            Node_guess* node = g_lookup_guess->GetAltAbility(entry->pairs_guess[index].first_guess);
            if (node != 0) {
                Row_guess* row = g_lookup_guess->Check_guess(g_status_guess, node->field_20_guess);
                if (row != 0) {
                    int value = row->field_3c_guess;
                    if (value >= 0 && value < 0x1e && g_status_guess->Ready_guess(value) != 0 &&
                        g_clock_guess->ticks_148_guess > lastTick_1380_guess + 2000U) {
                        UpdateTimer_guess();
                        lastTick_1380_guess = g_clock_guess->ticks_148_guess;
                    }
                }
            }
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// CAAWnd::Activate (vtable slot 49): builds the tabs on first use, then refreshes.
// FUNCTION: TITANIUM 0x004D1C9C
bool CAAWndView_guess::Activate_guess() {
    if (flag_164_guess == 0)
        BuildAbilityLists_guess();
    Refresh_guess();
    lastTick_1380_guess = g_clock_guess->ticks_148_guess;
    return true;
}

// EXTERNAL: TITANIUM 0x0059D080 FUN_0059d080_guess
void __stdcall FUN_0059d080_guess(int value_guess);

// Selects ability `id_guess`: finds its tab and row, switches to them and shows its description.
// FUNCTION: TITANIUM 0x004D1CC9
// @early-stop: budget, structural ndiff=50
void CAAWndView_guess::SelectAbility_guess(int id_guess) {
    int bookFound = -1;
    int entryFound = -1;
    FUN_0059d080_guess(1);
    int book = 0;
    if (listCount_160_guess > 0) {
        do {
            int entry = 0;
            while (true) {
                if (entry >= counts_210_guess[book])
                    break;
                Entry_guess* list = entries_23c_guess[0].GetExternal_guess(book);
                if (list->Pair_guess(entry).first_guess == id_guess) {
                    bookFound = book;
                    entryFound = entry;
                }
                entry++;
            }
            book++;
        } while (book < listCount_160_guess);
        if (bookFound >= 0) {
            bookIndex_1370_guess = bookFound;
            entryIndex_136c_guess = entryFound;
            if (lists_1e0_guess[bookIndex_1370_guess] != 0)
                lists_1e0_guess[bookIndex_1370_guess]->SetCurSel(entryIndex_136c_guess);
            ((TabWnd_guess*)subwindows_1b0_guess)->SetPage_guess(pages_1b4_guess[bookIndex_1370_guess], 1);
            UpdateSelected_guess();
            Refresh_guess();
        }
    }
}

#define g_trainFlagA_guess EQ_GLOBAL(int, 0x00924798)
#define g_trainFlagB_guess EQ_GLOBAL(int, 0x0092479C)
#define g_trainFlagC_guess EQ_GLOBAL(int, 0x009247A8)

// Refreshes everything: exp split controls (shown unless 0x4167E2 reports a status; Less/More need
// level 51+ and one of the flags at 0x924798/0x92479C/0x9247A8), the monster-set controls, rank
// "have/max" and cost per row (grey when not trainable), and the available and spent point totals.
// FUNCTION: TITANIUM 0x004D1484
// @early-stop: budget, structural ndiff=228
void CAAWndView_guess::Refresh_guess() {
    char buffer[1024];
    CXStr text;
    int level = g_statusView_guess->Level_guess();
    int scroll;
    if (lists_1e0_guess[bookIndex_1370_guess] != 0)
        scroll = ((AAChild_guess*)lists_1e0_guess[bookIndex_1370_guess])->scroll_10c_guess;
    else
        scroll = 0;
    bool active = g_statusView_guess->IsActive_guess();
    char loaded = g_statusView_guess->IsStatusOneOrTwo_guess();
    BuildAbilityLists_guess();
    if (lists_1e0_guess[bookIndex_1370_guess] != 0) {
        lists_1e0_guess[bookIndex_1370_guess]->SetCurSel(entryIndex_136c_guess);
        ((AAChild_guess*)lists_1e0_guess[bookIndex_1370_guess])->SetScroll_guess(scroll);
    }
    if (percentLabel_168_guess != 0)
        ((AAChild_guess*)percentLabel_168_guess)->Show_guess(active, true);
    if (expCount_16c_guess != 0)
        ((AAChild_guess*)expCount_16c_guess)->Show_guess(active, true);
    if (expGauge_170_guess != 0)
        ((AAChild_guess*)expGauge_170_guess)->Show_guess(active, true);
    // The AA experience split (+0xE2D, percent): Less/More work only above level 50 with one of the
    // g_trainFlagA-C flags set, and stop at 0 and 100.
    int percent = g_status_guess->value_e2d_guess;
    if (expCount_1ac_guess != 0) {
        ((AAChild_guess*)expCount_1ac_guess)->Show_guess(active, true);
        if (active && percent != percent_137c_guess) {
            percent_137c_guess = percent;
            sprintf(buffer, "%d%%", percent);
            text = buffer;
            ((AAChild_guess*)expCount_1ac_guess)->SetWindowText_guess(text);
        }
    }
    if (lessExpButton_174_guess != 0) {
        ((AAChild_guess*)lessExpButton_174_guess)->Show_guess(active, true);
        if (active)
            lessExpButton_174_guess->Enabled = percent > 0 && (unsigned char)level > 50 &&
                (g_trainFlagA_guess != 0 || g_trainFlagB_guess != 0 || g_trainFlagC_guess != 0);
    }
    if (moreExpButton_178_guess != 0) {
        ((AAChild_guess*)moreExpButton_178_guess)->Show_guess(active, true);
        if (active)
            moreExpButton_178_guess->Enabled = percent < 100 && (unsigned char)level > 50 &&
                (g_trainFlagA_guess != 0 || g_trainFlagB_guess != 0 || g_trainFlagC_guess != 0);
    }
    // In the second mode (IsStatusOneOrTwo_guess: the monster-mission form) the Monster label and the
    // load/save buttons replace the current/total counts.
    if (currentLabel_198_guess != 0)
        ((AAChild_guess*)currentLabel_198_guess)->Show_guess(!loaded, true);
    if (monsterLabel_19c_guess != 0)
        ((AAChild_guess*)monsterLabel_19c_guess)->Show_guess(loaded, true);
    if (loadSaveLabel_184_guess != 0)
        loadSaveLabel_184_guess->Show_guess(loaded, true);
    if (totalLabel_1a0_guess != 0)
        ((AAChild_guess*)totalLabel_1a0_guess)->Show_guess(!loaded, true);
    if (totalCount_1a4_guess != 0)
        ((AAChild_guess*)totalCount_1a4_guess)->Show_guess(!loaded, true);
    if (loadButton_188_guess != 0) {
        loadButton_188_guess->Show_guess(loaded, true);
        loadButton_188_guess->enabled_5d_guess = loaded;
    }
    if (saveButton_18c_guess != 0) {
        saveButton_18c_guess->Show_guess(loaded, true);
        saveButton_18c_guess->enabled_5d_guess = loaded;
    }

    int i;
    for (i = 0; i < listCount_160_guess; i++)
        ((TabWnd_guess*)subwindows_1b0_guess)->InsertPage_guess(pages_1b4_guess[i]);

    // Tabs with entries are shown; each row gets "rank/max" and the next rank's cost, white when trainable
    // and grey otherwise, while the spent total adds up the owned ranks.
    int spent = 0;
    for (i = 0; i < listCount_160_guess; i++) {
        if (counts_210_guess[i] > 0)
            ((TabWnd_guess*)subwindows_1b0_guess)->SetPageVisible_guess(pages_1b4_guess[i], -1);
        if (lists_1e0_guess[i] != 0) {
            for (int j = 0; j < counts_210_guess[i]; j++) {
                int id = entries_23c_guess[0].Get_guess(i)->Pair_guess(j).first_guess;
                int row = entries_23c_guess[0].Get_guess(i)->Pair_guess(j).second_guess;
                Node_guess* node = g_lookup_guess->GetAltAbility(id);
                if (node != 0 && node->valid_4_guess != 0) {
                    int rank = node->rank_24_guess - 1;
                    if (g_status_guess->HasAltAbility_guess(id)) {
                        rank++;
                        spent += node->spent_4c_guess;
                    } else if (g_status_guess->HasAltAbility_guess(node->prev_50_guess)) {
                        Node_guess* prev = g_lookup_guess->GetAltAbility(node->prev_50_guess);
                        if (prev != 0)
                            spent += prev->spent_4c_guess;
                    }
                    sprintf(buffer, "%d/%d", rank, node->MaxRank_guess());
                    text = buffer;
                    lists_1e0_guess[i]->SetItemText(row, 1, text);
                    int cost = node->cost_1c_guess;
                    if (rank < node->MaxRank_guess())
                        sprintf(buffer, "%d", cost);
                    else
                        sprintf(buffer, "");
                    text = buffer;
                    lists_1e0_guess[i]->SetItemText(row, 2, text);
                    if (g_lookup_guess->CanPurchase_guess(g_status_guess, node, 0)) {
                        lists_1e0_guess[i]->SetItemColor_guess(row, 0, 0xffffffff);
                        lists_1e0_guess[i]->SetItemColor_guess(row, 1, 0xffffffff);
                        lists_1e0_guess[i]->SetItemColor_guess(row, 2, 0xffffffff);
                    } else {
                        lists_1e0_guess[i]->SetItemColor_guess(row, 0, 0xffc0c0c0);
                        lists_1e0_guess[i]->SetItemColor_guess(row, 1, 0xffc0c0c0);
                        lists_1e0_guess[i]->SetItemColor_guess(row, 2, 0xffc0c0c0);
                    }
                }
            }
        }
    }

    if (counts_210_guess[bookIndex_1370_guess] == 0) {
        for (i = 0; i < listCount_160_guess; i++) {
            if (counts_210_guess[i] > 0) {
                ((TabWnd_guess*)subwindows_1b0_guess)->SetPage_guess(pages_1b4_guess[i], 1);
                bookIndex_1370_guess = i;
                break;
            }
        }
    } else if ((int)bookIndex_1370_guess >= 0 && pages_1b4_guess[bookIndex_1370_guess] != 0) {
        ((TabWnd_guess*)subwindows_1b0_guess)->SetPage_guess(pages_1b4_guess[bookIndex_1370_guess], 0);
    }

    // Available and spent points are rewritten only when they changed.
    int points = g_status_guess->GetPoints_guess();
    if (points_1374_guess != points) {
        points_1374_guess = points;
        sprintf(buffer, "%d", points);
        text = buffer;
        if (currentCount_1a8_guess != 0)
            ((AAChild_guess*)currentCount_1a8_guess)->SetWindowText_guess(text);
    }
    if (spent != spent_1378_guess) {
        spent_1378_guess = spent;
        sprintf(buffer, "%d", spent);
        text = buffer;
        if (totalCount_1a4_guess != 0)
            ((AAChild_guess*)totalCount_1a4_guess)->SetWindowText_guess(text);
    }
    UpdateSelected_guess();
}

// Trains the selected ability (action 3) and disables TrainButton until the server answers.
// FUNCTION: TITANIUM 0x004D0A0E
void CAAWndView_guess::SendTrainAbility_guess() {
    unsigned int data[4];
    memset(data, 0, 0x10);
    unsigned int index = entryIndex_136c_guess;
    data[0] = 3;
    Entry_guess* entry = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
    if (index >= 0x32)
        __debugbreak();
    data[1] = entry->pairs_guess[index].first_guess;
    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_AAAction, data, 0x10, 1);
    panel_17c_guess->flag_5d_guess = 0;
}

struct MagicEntry_guess {
    int id_guess;
    char flag_4_guess;
    char pad_5_guess[0x10 - 5];
    int nameId_guess;
    char pad_14_guess[0x30 - 0x14];
    int category_guess;
};

struct MagicTable_guess {
    // EXTERNAL: TITANIUM 0x00447D07 MagicTable_guess::GetAltAbility
    MagicEntry_guess* GetAltAbility(int key_guess);
    // EXTERNAL: TITANIUM 0x00447CF2 MagicTable_guess::Apply_guess
    void Apply_guess(MagicEntry_guess* entry_guess);
    // EXTERNAL: TITANIUM 0x00447F0B MagicTable_guess::Check_guess
    char Check_guess(Status_guess* status_guess, MagicEntry_guess* entry_guess);
};

#define g_magicTable_guess EQ_GLOBAL(MagicTable_guess*, 0x008511D8)

// Sorts every ability the character may see (ids below 10000) into its tab by category 1-11, at most 50
// per tab, and fills the lists (name from CDBStr kind 1, item data = ability id). Not a plain init.
// FUNCTION: TITANIUM 0x004D06E9
// @early-stop: unknown, structural ndiff=123
void CAAWndView_guess::BuildAbilityLists_guess() {
    if (g_status_guess != 0) {
        int n;
        flag_164_guess = 1;
        g_statusView_guess->Profile_guess();
        for (int offset = 0; offset < 11; ++offset)
            counts_210_guess[offset] = 0;

        for (int i = 0; i < 10000; ++i) {
            MagicEntry_guess* entry = g_magicTable_guess->GetAltAbility(i);
            if (entry == 0)
                continue;
            int category = entry->category_guess;
            if (category < 1 || category > 11) {
                g_magicTable_guess->Apply_guess(entry);
                continue;
            }
            if (g_magicTable_guess->Check_guess(g_status_guess, entry)) {
                int index = category - 1;
                if (counts_210_guess[index] >= 0x32) {
                    g_magicTable_guess->Apply_guess(entry);
                    continue;
                }
                if (entry->flag_4_guess != 0) {
                    unsigned int old = (unsigned int)counts_210_guess[index]++;
                    entries_23c_guess[0].Get_guess(index)->Pair_guess(old).first_guess = i;
                }
            } else if (!g_status_guess->HasAltAbility_guess(entry->id_guess)) {
                g_magicTable_guess->Apply_guess(entry);
            }
        }

        for (n = 0; n < listCount_160_guess; ++n) {
            if (lists_1e0_guess[n] != 0) {
                ((AAChild_guess*)lists_1e0_guess[n])->Slot76_guess();
                for (int j = 0; j < counts_210_guess[n]; ++j) {
                    int value = entries_23c_guess[0].Get_guess(n)->Pair_guess(j).first_guess;
                    MagicEntry_guess* obj = g_magicTable_guess->GetAltAbility(value);
                    CXStr text;
                    if (obj != 0 && obj->flag_4_guess != 0) {
                        text = g_dbStrings_guess->GetString_guess(obj->nameId_guess, 1, 0);
                        int index = lists_1e0_guess[n]->AddString(text, 0xffffffff, 0, 0);
                        entries_23c_guess[0].Get_guess(n)->Pair_guess(j).second_guess = index;
                        lists_1e0_guess[n]->SetItemData(index, value);
                    }
                }
                // Tabs 9 and 10 are re-sorted for the monster-set character kind.
                if (g_statusView_guess->IsStatusOneOrTwo_guess() && (n == 8 || n == 9)) {
                    lists_1e0_guess[n]->field_154_guess = 0;
                    lists_1e0_guess[n]->field_158_guess = 1;
                    ((AAChild_guess*)lists_1e0_guess[n])->Slot78_guess();
                    for (int k = 0; k < counts_210_guess[n]; ++k) {
                        entries_23c_guess[0].Get_guess(n)->Pair_guess(k).second_guess = k;
                        Entry_guess* row = entries_23c_guess[0].Get_guess(n);
                        row->Pair_guess(k).first_guess = lists_1e0_guess[n]->GetItemData(k);
                    }
                }
            }
        }

        points_1374_guess = -1;
        percent_137c_guess = -1;
        spent_1378_guess = -1;
    }
}

// Answer to the train prompt: Yes or OK trains.
// FUNCTION: TITANIUM 0x004D0A7A
// @early-stop: budget, structural ndiff=5
void AAWndConfirmCallback_guess::OnTrainConfirm_guess(int event_guess, unsigned char flags_guess, int data_guess) {
    if ((flags_guess & 5) != 0)
        ((CAAWndView_guess&)*this).SendTrainAbility_guess();
}

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text_guess, const char* format_guess, ...);

// CAAWnd constructor ("AAWindow"): binds the experience, train and load/save controls and, per tab,
// List%d and Page%d.
// FUNCTION: TITANIUM 0x004D0A8F
// @early-stop: budget, diff ndiff=10
CAAWndView_guess::CAAWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "AAWindow") {
    percentLabel_168_guess = 0;
    expCount_16c_guess = 0;
    expGauge_170_guess = 0;
    lessExpButton_174_guess = 0;
    moreExpButton_178_guess = 0;
    timer_20c_guess = 0;
    panel_17c_guess = 0;
    hotButton_180_guess = 0;
    loadSaveLabel_184_guess = 0;
    loadButton_188_guess = 0;
    saveButton_18c_guess = 0;
    doneButton_190_guess = 0;
    currentLabel_198_guess = 0;
    monsterLabel_19c_guess = 0;
    totalLabel_1a0_guess = 0;
    expCount_1ac_guess = 0;
    if (SidlPiece != 0) {
        WindowStyle |= 0x10800;
        field_158_guess = 2;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        listCount_160_guess = 11;
        percentLabel_168_guess = ((CSidlScreenWnd*)this)->GetChildItem("PercentLabel");
        expCount_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("ExpCount");
        expGauge_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("ExpGauge");
        lessExpButton_174_guess = ((CSidlScreenWnd*)this)->GetChildItem("LessExpButton");
        moreExpButton_178_guess = ((CSidlScreenWnd*)this)->GetChildItem("MoreExpButton");
        timer_20c_guess = ((CSidlScreenWnd*)this)->GetChildItem("Timer");
        panel_17c_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("TrainButton");
        if (panel_17c_guess != 0)
            panel_17c_guess->flag_5d_guess = 0;
        hotButton_180_guess = (Panel_guess*)((CSidlScreenWnd*)this)->GetChildItem("HotButton");
        if (hotButton_180_guess != 0)
            hotButton_180_guess->flag_5d_guess = 0;
        loadSaveLabel_184_guess = (AAChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("AAW_LoadSaveLabel");
        if (loadSaveLabel_184_guess != 0)
            loadSaveLabel_184_guess->Show_guess(0, 1);
        loadButton_188_guess = (AAChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("AAW_LoadButton");
        if (loadButton_188_guess != 0)
            loadButton_188_guess->Show_guess(0, 1);
        saveButton_18c_guess = (AAChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("AAW_SaveButton");
        if (saveButton_18c_guess != 0)
            saveButton_18c_guess->Show_guess(0, 1);
        doneButton_190_guess = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        subwindows_1b0_guess = ((CSidlScreenWnd*)this)->GetChildItem("Subwindows");
        for (int i = 0; i < listCount_160_guess; i++) {
            CXStr name;
            FormatString_guess(&name, "List%d", i + 1);
            lists_1e0_guess[i] = (AAList_guess*)((CSidlScreenWnd*)this)->GetChildItem(name);
            if (lists_1e0_guess[i] != 0) {
                lists_1e0_guess[i]->SetColors(0xffffffff, 0xffffff00, 0xff808080);
                lists_1e0_guess[i]->SetColumnJustification(0, 0);
                lists_1e0_guess[i]->SetColumnJustification(1, 1);
                lists_1e0_guess[i]->SetColumnJustification(2, 1);
                lists_1e0_guess[i]->color_16c_guess = 0xff8aa3ff;
                lists_1e0_guess[i]->flag_15c_guess = 1;
                lists_1e0_guess[i]->WindowStyle |= 0x40000;
            }
            FormatString_guess(&name, "Page%d", i + 1);
            pages_1b4_guess[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        currentLabel_198_guess = ((CSidlScreenWnd*)this)->GetChildItem("CurrentLabel");
        monsterLabel_19c_guess = ((CSidlScreenWnd*)this)->GetChildItem("MonsterLabel");
        totalLabel_1a0_guess = ((CSidlScreenWnd*)this)->GetChildItem("TotalLabel");
        description_194_guess = ((CSidlScreenWnd*)this)->GetChildItem("Description");
        totalCount_1a4_guess = ((CSidlScreenWnd*)this)->GetChildItem("TotalCount");
        currentCount_1a8_guess = ((CSidlScreenWnd*)this)->GetChildItem("CurrentCount");
        expCount_1ac_guess = ((CSidlScreenWnd*)this)->GetChildItem("ExpCount");
        entryIndex_136c_guess = 0xffffffff;
        flag_164_guess = 0;
        bookIndex_1370_guess = 0;
        BuildAbilityLists_guess();
    }
}

// CAAWnd::UpdateSelected (TAKP name): description of the selected ability (id first when pCharData +0xE25
// is set, probably a GM flag), reuse time or string 0xC26, requirements and text; string 0xC24 with
// nothing selected.
// FUNCTION: TITANIUM 0x004D1190
// @early-stop: budget, structural ndiff=106
void CAAWndView_guess::UpdateSelected_guess() {
    Node_guess* node;
    unsigned int minutes;
    int id;
    CXStr text;
    char buffer[0x400];
    unsigned int index = entryIndex_136c_guess;

    if (index != 0xffffffff) {
        Entry_guess* entry = entries_23c_guess[0].Get_guess(bookIndex_1370_guess);
        if (index >= 0x32)
            __debugbreak();
        id = entry->pairs_guess[index].first_guess;
        node = g_lookup_guess->GetAltAbility(id);
        if (node != 0) {
            if (panel_17c_guess != 0)
                panel_17c_guess->flag_5d_guess = g_lookup_guess->CanPurchase_guess(g_status_guess, node, 0) != 0;
            if (g_status_guess->flag_e25_guess != 0) {
                sprintf(buffer, g_idFormat_guess, id);
                text += buffer;
            }
            UpdateTimer_guess();
            unsigned int total = node->field_40_guess;
            if (node->field_40_guess <= 0) {
                if (hotButton_180_guess != 0)
                    hotButton_180_guess->flag_5d_guess = 0;
                text += pStringTable->getString(0xc26, 0);
                if (timer_20c_guess != 0) {
                    CXStr empty(g_emptyText_guess);
                    ((WidgetBase_guess*)timer_20c_guess)->Slot63_guess(empty);
                }
            } else {
                unsigned int hours = total / 3600;
                unsigned int seconds = total % 60;
                minutes = (total / 60) % 60;
                text += pStringTable->getString(0xc25, 0);
                sprintf(buffer, g_timeFormat_guess, hours, minutes, seconds);
                text += buffer;
            }
            text += g_brText_guess;
            g_lookup_guess->GetAbilityReqs_guess(buffer, node);
            text += buffer;
            text += g_brText_guess;
            text += g_dbStrings_guess->GetString_guess(node->field_14_guess, 4, 0);
            if (description_194_guess != 0)
                ((CStmlWnd*)description_194_guess)->SetSTMLText(text, true, 0);
        }
    } else {
        if (description_194_guess != 0)
            ((CStmlWnd*)description_194_guess)->SetSTMLText(
                CXStr(pStringTable->getString(0xc24, 0)), true, 0);
        if (panel_17c_guess != 0)
            panel_17c_guess->flag_5d_guess = 0;
        if (hotButton_180_guess != 0)
            hotButton_180_guess->flag_5d_guess = 0;
    }
}

// Save button: writes every owned ability id (up to 100) to [AbilitySets] Set<n>.ability<k>, blanks the
// rest and reports string 0x1F50.
// FUNCTION: TITANIUM 0x004D1DA1
// @early-stop: budget, diff ndiff=1
void CAAWndView_guess::SaveAbilitySet_guess() {
    int set_guess;
    unsigned int file_guess;
    int written_guess;
    int ability_guess;
    char value_guess[32];
    char key_guess[32];

    if (g_statusView_guess->IsStatusOneOrTwo_guess()) {
        set_guess = g_status_guess->GetIndexTable_guess()->count_1228_guess;
        written_guess = 0;
        if (set_guess > 0) {
            file_guess = FUN_00559573_address_guess();
            if (file_guess == 0)
                return;
            FUN_00577000_guess(key_guess, 0x20, "Set%d.inuse", set_guess);
            FUN_0060beb0_guess("AbilitySets", key_guess, EQ_ARRAY(char, 0x00645EB4), (const char*)file_guess);
            panel_17c_guess->flag_5d_guess = 0;
            for (ability_guess = 1; ability_guess < 10000; ability_guess++) {
                if (g_status_guess->HasAltAbility_guess(ability_guess) && written_guess < 100) {
                    FUN_00577000_guess(key_guess, 0x20, "Set%d.ability%d", set_guess, written_guess);
                    written_guess++;
                    FUN_00577000_guess(value_guess, 0x20, EQ_ARRAY(char, 0x0063F53C), ability_guess);
                    FUN_0060beb0_guess("AbilitySets", key_guess, value_guess, (const char*)file_guess);
                }
            }
            for (; written_guess < 100; written_guess++) {
                FUN_00577000_guess(key_guess, 0x20, "Set%d.ability%d", set_guess, written_guess);
                FUN_0060beb0_guess("AbilitySets", key_guess, 0, (const char*)file_guess);
            }
            pEverQuest->dsp_chat(g_strings_guess->getString(0x1f50, 0), 0xf, 1);
            Refresh_guess();
            return;
        }
        pEverQuest->dsp_chat(g_strings_guess->getString(0x1f56, written_guess), 0xf, 1);
        return;
    }
    pEverQuest->dsp_chat(g_strings_guess->getString(0x1f56, 0), 0xf, 1);
}

// WndNotification (clicks only). Done hides; Less/More move the AA exp split by 10%; TrainButton asks
// first unless the byte at 0x9254B0 is set; HotButton puts the ability on the cursor (0x4FD91E); Load and
// Save handle ability sets; a list row selects; a tab change clears the selection.
// The train prompt (string 0xFC9, 0xFCA for more than one point) is Yes/No, 20 s, message id 100, owned
// by the AA window's +0x15C (0x850BD0 holds that window).
// FUNCTION: TITANIUM 0x004D1F28
// @early-stop: budget, structural ndiff=167
int CAAWndView_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess) {
    CXWnd* notificationSender_guess = sender_guess;
    char number_guess[8];
    char message_guess_buffer[512];

    if (message_guess != 1)
        return ((CSidlScreenWnd*)this)->WndNotification(notificationSender_guess, message_guess, data_guess);

    if (notificationSender_guess == doneButton_190_guess) {
        ((WidgetBase_guess*)this)->Slot34_guess();
        return 1;
    }
    if (notificationSender_guess == lessExpButton_174_guess) {
        if (g_status_guess->value_e2d_guess > 0) {
            g_status_guess->value_e2d_guess -= 10;
            SendAAExpPercent_guess();
        }
        Refresh_guess();
        return 1;
    }
    if (notificationSender_guess == moreExpButton_178_guess) {
        if (g_status_guess->value_e2d_guess < 100) {
            g_status_guess->value_e2d_guess += 10;
            SendAAExpPercent_guess();
        }
        Refresh_guess();
        return 1;
    }
    if (notificationSender_guess == (CXWnd*)panel_17c_guess) {
        unsigned int index_guess = entryIndex_136c_guess;
        if ((int)index_guess >= 0) {
            if (EQ_GLOBAL(int, 0x009254B0) == 0) {
                Entry_guess* entry_guess = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
                if (index_guess >= 0x32)
                    __debugbreak();
                Node_guess* node_guess = g_lookup_guess->GetAltAbility(entry_guess->pairs_guess[index_guess].first_guess);
                if (node_guess != 0) {
                    AbilityInfo_guess* ability_guess = (AbilityInfo_guess*)node_guess;
                    int level_guess = ability_guess->level_1c_guess;
                    sprintf(number_guess, "%d", level_guess);
                    BuildAbilityMessage_guess(message_guess_buffer,
                                              (level_guess != 1) + 0xfc9,
                                              number_guess,
                                              g_dbStrings_guess->GetString_guess(ability_guess->stringId_10_guess, 1, 0),
                                              0, 0, 0, 0, 0, 0, 0);
                    pConfirmationDialogPool_guess->Activate(
                        pinstCAAWnd_guess != 0 ? &pinstCAAWnd_guess->field_15c_guess : 0,
                        100, message_guess_buffer, 0xc, 20000, 0, 1);
                }
            } else {
                SendTrainAbility_guess();
            }
        }
        return 1;
    }
    if (notificationSender_guess == (CXWnd*)hotButton_180_guess) {
        unsigned int index_guess = entryIndex_136c_guess;
        if ((int)index_guess >= 0) {
            Entry_guess* entry_guess = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
            if (index_guess >= 0x32)
                __debugbreak();
            int abilityId_guess = entry_guess->pairs_guess[index_guess].first_guess;
            CXStr text_guess;
            Node_guess* node_guess = g_lookup_guess->GetAltAbility(abilityId_guess);
            if (node_guess != 0) {
                AbilityInfo_guess* ability_guess = (AbilityInfo_guess*)node_guess;
                if (ability_guess->textId_8_guess > 0)
                    text_guess = g_dbStrings_guess->GetString_guess(ability_guess->textId_8_guess, 2, 0);
                if (ability_guess->textId_c_guess > 0) {
                    text_guess += EQ_ARRAY(char, 0x0063FE10);
                    text_guess += g_dbStrings_guess->GetString_guess(ability_guess->textId_c_guess, 3, 0);
                }
                pinstCCursorAttachment_guess->Set_guess(0, 4, &ability_guess->group_20_guess->field_78_guess,
                                               (char*)text_guess, -1);
            }
        }
        return 1;
    }

    if (notificationSender_guess == (CXWnd*)loadButton_188_guess) {
        LoadAbilitySets_guess();
    } else if (notificationSender_guess == (CXWnd*)saveButton_18c_guess) {
        SaveAbilitySet_guess();
    } else {
        ((AAWndConfirmCallback_guess*)this)->Stop_guess(-1);
        for (int listIndex_guess = 0; listIndex_guess < listCount_160_guess; ++listIndex_guess) {
            if (listIndex_guess >= 11)
                __debugbreak();
            if (notificationSender_guess == lists_1e0_guess[listIndex_guess]) {
                int selection_guess = lists_1e0_guess[listIndex_guess]->GetCurSel();
                for (int itemIndex_guess = 0; itemIndex_guess < counts_210_guess[bookIndex_1370_guess]; ++itemIndex_guess) {
                    Entry_guess* entry_guess = entries_23c_guess[0].GetExternal_guess(bookIndex_1370_guess);
                    if (itemIndex_guess >= 0x32)
                        __debugbreak();
                    if (entry_guess->pairs_guess[itemIndex_guess].second_guess == selection_guess) {
                        entryIndex_136c_guess = itemIndex_guess;
                        UpdateSelected_guess();
                        return 1;
                    }
                }
                return 1;
            }
        }
        if (notificationSender_guess == subwindows_1b0_guess) {
            int selection_guess = ((NotificationData_guess*)data_guess)->selection_8_guess;
            for (int i_guess = 0; i_guess < listCount_160_guess; ++i_guess) {
                if (i_guess >= 11)
                    __debugbreak();
                if (selection_guess == controlIds_1b4_guess[i_guess]) {
                    if (bookIndex_1370_guess >= 11)
                        __debugbreak();
                    if (lists_1e0_guess[bookIndex_1370_guess] != 0) {
                        if (bookIndex_1370_guess >= 11)
                            __debugbreak();
                        lists_1e0_guess[bookIndex_1370_guess]->SetCurSel(-1);
                        entryIndex_136c_guess = -1;
                        bookIndex_1370_guess = i_guess;
                        UpdateSelected_guess();
                        Refresh_guess();
                    }
                    return 1;
                }
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(notificationSender_guess, message_guess, data_guess);
}
