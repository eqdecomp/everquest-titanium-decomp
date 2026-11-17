// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 228: a hint from compare/tumap.py.
// The "TipWindow" screen in its two modes: 0 tip of the day (global 0x9928DC, tips from help\tips\totd.txt)
// and 1 context tips (0x9928E0, 73 help pages). OptionsWindow_guess, PreferenceManager_guess, ItemList_guess,
// HelpTips_guess and Owner_guess all view this window; CEverQuestView_guess is CEverQuest (INI bools).
// Tip table 0x7948B4: 0x58 bytes per tip, file name, INI key at +0x30, on flag at +0x50.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <stdio.h>
#include <string.h>
#include "titanium/wnd/CTicketWnd.h"

struct OptionState_guess {
    // EXTERNAL: TITANIUM 0x005BB140 OptionState_guess::SetCheck
    void SetCheck(bool enabled);

    char _pad_000[0x128];
    unsigned char checked_guess;
};

struct PreferenceManager_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 PreferenceManager_guess::isReady_guess
    char isReady_guess();
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
};

struct CEverQuestView_guess {
    // EXTERNAL: TITANIUM 0x004AE82A CEverQuestView_guess::setValue_guess
    void setValue_guess(unsigned char enabled, const char* section, const char* name);
    // EXTERNAL: TITANIUM 0x004AE919 CEverQuestView_guess::getValue_guess
    unsigned char getValue_guess(const char* section, const char* name, unsigned char value, unsigned char fallback);
};

struct SettingsEntry_guess {
    char name_guess[0x20];
    unsigned char enabled;
    char _pad_021[0x37];
};

struct SettingsFlagEntry_guess {
    char enabled;
    char _pad_001[0x57];
};

struct OptionsWindow_guess {
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void slot48_guess(int first, int second);

    char _pad_004[0x58];
    char showTipsEnabled_guess;
    char _pad_05d[0x103];
    CXWnd* nextTipButton_guess;
    CXWnd* closeButton_guess;
    CXWnd* historyButton_guess;
    char _pad_16c[4];
    OptionState_guess* noShowThisButton_guess;
    OptionState_guess* noShowButton_guess;
    char _pad_178[0x48];
    int mode;
    int selectedEntry;
    unsigned char tipsEnabled;
    unsigned char showTipOfDay;

    // EXTERNAL: TITANIUM 0x005A1880 OptionsWindow_guess::OnShow
    void OnShow();
    void OnShow_guess();
    void LoadTipFlags_guess();
    void UpdateCheckBoxes_guess();
    void EnableAllTips_guess();
    void AddContextTip_guess(int value);
    // EXTERNAL: TITANIUM 0x0059DD30 OptionsWindow_guess::isReady_guess
    char isReady_guess();
    // EXTERNAL: TITANIUM 0x005A05F0 OptionsWindow_guess::showSelectedTip_guess
    void showSelectedTip_guess();
    // EXTERNAL: TITANIUM 0x005644D6 OptionsWindow_guess::~OptionsWindow_guess
    ~OptionsWindow_guess();
    char selectTip_guess(int value, char allowDisabled);
    void* scalarDeletingDestructor_guess(unsigned int flags);

    // EXTERNAL: TITANIUM 0x005A2230 OptionsWindow_guess::WndNotification
    int WndNotification(CXWnd* sender, int msg, const char* extra);
    int WndNotification_guess(CXWnd* sender, int msg, const char* extra);
};

struct ModalState_guess {
    // EXTERNAL: TITANIUM 0x005F6C80 ModalState_guess::isActive_guess
    char isActive_guess(int state);
};

#define pinstCTipWndOFDAY_guess EQ_GLOBAL(PreferenceManager_guess*, 0x009928DC)
#define pinstCTipWndCONTEXT_guess EQ_GLOBAL(void*, 0x009928E0)
#define g_configSink_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)
#define g_modalState_guess EQ_GLOBAL(ModalState_guess*, 0x00905CC0)

struct Array_guess {
    int count;
    void** data;
    int capacity_guess;

    // EXTERNAL: TITANIUM 0x004EB924 Array_guess::at_guess
    void** at_guess(int index);
    // EXTERNAL: TITANIUM 0x0050F3F6 Array_guess::reset_guess
    void reset_guess();
    // EXTERNAL: TITANIUM 0x004EB943 Array_guess::grow_guess
    void grow_guess(int count);
    // EXTERNAL: TITANIUM 0x0050319B Array_guess::insertAt_guess
    void insertAt_guess(int index, void** value);

    void DeleteElement_guess(int index);
    void insert_guess(int index, void** value);
    int getCount_guess() const { return count; }
    void*& element_guess(const int& index) { return *at_guess(index); }
};

struct TipContainer_guess {
    // EXTERNAL: TITANIUM 0x005A9060 TipContainer_guess::setPage_guess
    void setPage_guess(CXStr* page_guess, int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005AC670 TipContainer_guess::refresh_guess
    void refresh_guess();
    // EXTERNAL: TITANIUM 0x004D22D7 TipContainer_guess::getText_guess
    CXStr getText_guess();
};

struct CComboWnd_guess {
    // EXTERNAL: TITANIUM 0x0059C360 CComboWnd_guess::select_guess
    void select_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0059C3E0 CComboWnd_guess::reset_guess
    void reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 CComboWnd_guess::add_guess
    void add_guess(CXStr* text_guess);
};

struct HelpTips_guess {
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void slot48_guess();
    virtual void slot49_guess();
    virtual void slot50_guess();
    virtual void slot51_guess();
    virtual void slot52_guess();
    virtual void slot53_guess();
    virtual void slot54_guess();
    virtual void slot55_guess();
    virtual void slot56_guess();
    virtual void slot57_guess();
    virtual void slot58_guess();
    virtual void slot59_guess();
    virtual void slot60_guess();
    virtual void slot61_guess();
    virtual void slot62_guess();
    virtual void showTip_guess(CXStr* text_guess);

    char _pad_004[0x158];
    TipContainer_guess* container_guess;
    char _pad_160[8];
    CComboWnd_guess* selector_guess;
    char _pad_16c[0x10];
    Array_guess categoryIndexes_guess;
    char _pad_188[4];
    Array_guess textEntries_guess;
    char _pad_198[0x2c];
    int current_guess;

    void ShowHistoryEntry_guess(int index_guess);
};

struct FourInts_guess {
    int values[4];
};

struct ItemList_guess {
    char _pad_000[0x15c];
    CStmlWnd* sink_guess;          // 0x15c
    char _pad_160[0x19c - 0x160];
    Array_guess tips_guess;          // 0x19c
    int field_1a8_guess;             // 0x1a8
    int values[5];                   // 0x1ac
    int field_1c0_guess;             // 0x1c0
    int current_guess;               // 0x1c4

    char IsRecentTip_guess(int value);
    int GetRandomTip_guess();
    void ShowTip_guess(int value);
    void LoadTipsOfTheDay_guess();
};

// EXTERNAL: TITANIUM 0x005A3100 ??1OwnerBase_guess@@UAE@XZ
struct OwnerBase_guess {
    virtual ~OwnerBase_guess();
};

struct SlotArray_guess : Array_guess {
    ~SlotArray_guess() { reset_guess(); }
};

// EXTERNAL: TITANIUM 0x0065E960 ??_7Owner_guess@@6B@
struct Owner_guess : OwnerBase_guess {
    char _pad_004[0x178];
    SlotArray_guess array17c_guess;
    char _pad_188[4];
    SlotArray_guess array18c_guess;
    char _pad_198[4];
    SlotArray_guess allocations_guess;

    void FreeTips_guess();
    ~Owner_guess();
};

// EXTERNAL: TITANIUM 0x00574A30 truncate_guess
void truncate_guess(char* text, int limit);

// Show hook (base 0x5A1880): opening the context-tip window hides the tip of the day if it is up.
// FUNCTION: TITANIUM 0x005640A5
void OptionsWindow_guess::OnShow_guess()
{
    if (showTipsEnabled_guess != 0 && pinstCTipWndOFDAY_guess != 0 &&
        pinstCTipWndCONTEXT_guess != 0 && this == pinstCTipWndCONTEXT_guess) {
        if (pinstCTipWndOFDAY_guess->isReady_guess() != 0)
            pinstCTipWndOFDAY_guess->slot34_guess();
    }
    OnShow();
}

// Syncs the check boxes with the flags: NoShowButton (+0x174) shows the mode's off switch, NoShowThisButton
// (+0x170) the current context tip's own flag.
// FUNCTION: TITANIUM 0x005640E4
void OptionsWindow_guess::UpdateCheckBoxes_guess()
{
    if (mode == 0) {
        if (noShowButton_guess == 0)
            return;
        noShowButton_guess->SetCheck(showTipOfDay == 0);
        return;
    }

    if (noShowButton_guess != 0)
        noShowButton_guess->SetCheck(tipsEnabled == 0);
    if (noShowThisButton_guess == 0)
        return;
    if (selectedEntry == -1)
        return;
    noShowThisButton_guess->SetCheck(EQ_ARRAY(SettingsFlagEntry_guess, 0x00794904)[selectedEntry].enabled == 0);
}

// Turns every tip back on and saves it: ShowTOTD in mode 0, each tip's key and ShowTips in mode 1.
// FUNCTION: TITANIUM 0x00564141
void OptionsWindow_guess::EnableAllTips_guess()
{
    if (mode == 0) {
        showTipOfDay = 1;
        g_configSink_guess->setValue_guess(1, "Tips", "ShowTOTD");
    } else {
        tipsEnabled = 1;
        SettingsEntry_guess* entry = EQ_ARRAY(SettingsEntry_guess, 0x007948E4);
        SettingsEntry_guess* end = EQ_ARRAY(SettingsEntry_guess, 0x007961FC);
        do {
            entry->enabled = 1;
            g_configSink_guess->setValue_guess(1, "Tips", (const char*)entry);
            ++entry;
        } while ((int)entry < (int)end);
        // Probably "ShowTips", the key LoadTipFlags_guess reads.
        g_configSink_guess->setValue_guess(tipsEnabled, "Tips", EQ_ARRAY(char, 0x0065E930));
    }
    UpdateCheckBoxes_guess();
}

// Reads the [Tips] flags from the INI, defaulting to on.
// FUNCTION: TITANIUM 0x00564216
void OptionsWindow_guess::LoadTipFlags_guess()
{
    tipsEnabled = g_configSink_guess->getValue_guess("Tips", "ShowTips", tipsEnabled, 1);
    if (mode == 0) {
        showTipOfDay = g_configSink_guess->getValue_guess("Tips", "ShowTOTD", showTipOfDay, 1);
    } else {
        SettingsEntry_guess* entry = EQ_ARRAY(SettingsEntry_guess, 0x007948E4);
        do {
            entry->enabled = g_configSink_guess->getValue_guess("Tips", entry->name_guess, entry->enabled, 1);
            ++entry;
        } while ((int)&entry->enabled < 0x0079621C);
    }
}

// EXTERNAL: TITANIUM 0x0060D682 free
void __cdecl free(void* memory);

// Whether tip `value` is in the five-entry recent history (+0x1AC).
// FUNCTION: TITANIUM 0x005641F4
char ItemList_guess::IsRecentTip_guess(int value)
{
    int* current = values;
    int i = 0;
    do {
        if (*current == value)
            return 1;
        ++current;
        ++i;
    } while (i < 5);
    return 0;
}

// ArrayClass element delete: shifts the tail down one. names.tsv's GetSkillLimit2 is a bad BinDiff hit.
// FUNCTION: TITANIUM 0x00564298
void Array_guess::DeleteElement_guess(int index)
{
    int index_guess = index;
    if (index_guess < 0)
        return;
    if (index_guess >= count)
        return;
    if (data == 0)
        return;

    if (index_guess < count - 1) {
        do {
            data[index_guess] = data[index_guess + 1];
            ++index_guess;
        } while (index_guess < count - 1);
    }
    --count;
}

// Frees every tip text in the tip array (+0x19C) and empties it.
// FUNCTION: TITANIUM 0x005642CB
void Owner_guess::FreeTips_guess()
{
    int index = 0;
    while (index < allocations_guess.count) {
        free(*allocations_guess.at_guess(index));
        ++index;
    }
    allocations_guess.reset_guess();
}

// EXTERNAL: TITANIUM 0x0059C3A0 GetTipOwner_guess
int __cdecl GetTipOwner_guess();

extern "C" int __cdecl rand(void);

// Random tip index, stepping past recent ones when there are more than five tips; -1 with none.
// FUNCTION: TITANIUM 0x005642F7
int ItemList_guess::GetRandomTip_guess()
{
    int count = tips_guess.count;
    if (count > 0) {
        int index = rand() % count;
        if (count > 5) {
            while (IsRecentTip_guess(index)) {
                ++index;
                if (index >= count)
                    index = 0;
            }
        }
        return index;
    }
    return -1;
}

// Shows tip `value` in Display and records it as the newest history entry.
// FUNCTION: TITANIUM 0x00564335
void ItemList_guess::ShowTip_guess(int value)
{
    if (value == -1)
        return;

    // Copies upward, so every older slot gets the previous tip: the history only ever remembers two
    // tips. Original bug (matched), keep it.
    for (int i = 1; i < 5; ++i)
        values[i] = values[i - 1];
    values[0] = value;
    current_guess = value;
    if (sink_guess != 0)
        sink_guess->SetSTMLText((const char*)*tips_guess.at_guess(value), 1, 0);
}

// Shows context history entry `index_guess`: selects it in the History combo and loads its page.
// FUNCTION: TITANIUM 0x00564397
// @early-stop: budget, structural ndiff=41
void HelpTips_guess::ShowHistoryEntry_guess(int index_guess)
{
    int zero_guess = 0;
    if (index_guess < zero_guess)
        return;
    if (index_guess >= categoryIndexes_guess.count)
        return;

    int pageIndex_guess = *(int*)categoryIndexes_guess.at_guess(index_guess);
    if (selector_guess != 0)
        selector_guess->select_guess(index_guess);
    current_guess = pageIndex_guess;

    if (container_guess != 0) {
        // Page path is help\tips\ plus the tip's file name from the tip table.
        CXStr page_guess("help\\tips\\");
        page_guess += (const char*)(EQ_ARRAY(char, 0x007948B4) + pageIndex_guess * 0x58);
        container_guess->setPage_guess(&page_guess, zero_guess, zero_guess);

        CXStr text_guess((const char*)*textEntries_guess.at_guess(index_guess));
        showTip_guess(&text_guess);
    }
}

// ArrayClass insert before `index` (append past the end).
// FUNCTION: TITANIUM 0x00564487
void Array_guess::insert_guess(int index, void** value)
{
    if (index < 0)
        return;
    if (index >= count) {
        insertAt_guess(index, value);
        return;
    }
    grow_guess(count + 1);
    if (data == 0)
        return;
    int i = count;
    while (i > index) {
        data[i] = data[i - 1];
        --i;
    }
    data[index] = *value;
    ++count;
}

// Moves context tip `value` to the top of the History combo: loads its page, titles it with the page's
// window text (else the file name), rebuilds the combo and shows entry 0.
// FUNCTION: TITANIUM 0x005646D1
// @early-stop: tiebreak, structural ndiff=76
void OptionsWindow_guess::AddContextTip_guess(int value)
{
    HelpTips_guess* tips = (HelpTips_guess*)this;
    char empty[4];
    empty[0] = 0;
    char* text = empty;
    for (int index = 0; index < tips->categoryIndexes_guess.getCount_guess(); ++index) {
        if ((int)tips->categoryIndexes_guess.element_guess(index) == value) {
            tips->categoryIndexes_guess.DeleteElement_guess(index);
            text = (char*)tips->textEntries_guess.element_guess(index);
            tips->textEntries_guess.DeleteElement_guess(index);
            break;
        }
    }
    tips->categoryIndexes_guess.insert_guess(0, (void**)&value);
    if (tips->container_guess != 0) {
        CXStr path("help\\tips\\");
        path += EQ_ARRAY(char, 0x007948B4) + value * 0x58;
        tips->container_guess->setPage_guess(&path, 0, 0);
        tips->container_guess->refresh_guess();
        CXStr cur = tips->container_guess->getText_guess();
        if (*text == 0 && (cur.Ptr ? cur.Ptr->length : 0) != 0) {
            text = new char[(cur.Ptr ? cur.Ptr->alloc : 0) + 10];
            strcpy(text, cur);
        }
    }
    if (*text == 0) {
        const char* entry = EQ_ARRAY(char, 0x007948B4) + value * 0x58;
        text = new char[strlen(entry) + 1];
        strcpy(text, entry);
    }
    tips->textEntries_guess.insert_guess(0, (void**)&text);
    if (tips->selector_guess != 0) {
        tips->selector_guess->reset_guess();
        for (int i = 0; i < tips->categoryIndexes_guess.getCount_guess(); ++i) {
            CXStr tip((const char*)*tips->textEntries_guess.at_guess(i));
            tips->selector_guess->add_guess(&tip);
        }
    }
    tips->ShowHistoryEntry_guess(0);
}

// Window destructor body: frees the tip texts and the history titles (+0x18C).
// FUNCTION: TITANIUM 0x005644D6
// @early-stop: budget, structural ndiff=16
Owner_guess::~Owner_guess()
{
    FreeTips_guess();
    for (int i = 0; i < array18c_guess.count; ++i)
        free(*array18c_guess.at_guess(i));
    array18c_guess.reset_guess();
}

// WndNotification. Clicks: NextTipButton shows a random tip, CloseButton hides, NoShowButton and
// NoShowThisButton save the mode's or the tip's flag, History shows the chosen entry. Message 1000
// (probably a link click in the page) opens help\<link> in the TicketWindow (0x9928A8, ctor 0x5633E9).
// FUNCTION: TITANIUM 0x0056455A
// @early-stop: budget, structural ndiff=10
int OptionsWindow_guess::WndNotification_guess(CXWnd* sender, int msg, const char* extra)
{
    char path[256];

    if (msg == 1) {
        if (sender == nextTipButton_guess) {
            ItemList_guess* list = (ItemList_guess*)this;
            list->ShowTip_guess(list->GetRandomTip_guess());
            return 0;
        }
        if (sender == closeButton_guess) {
            slot34_guess();
            return 0;
        }
        if (sender == (CXWnd*)noShowButton_guess) {
            if (mode == 0) {
                showTipOfDay = noShowButton_guess->checked_guess == 0;
                g_configSink_guess->setValue_guess(showTipOfDay, "Tips", "ShowTOTD");
            } else {
                tipsEnabled = noShowButton_guess->checked_guess == 0;
                g_configSink_guess->setValue_guess(tipsEnabled, "Tips", "ShowTips");
            }
        } else if (sender == (CXWnd*)noShowThisButton_guess) {
            if (selectedEntry != -1) {
                EQ_ARRAY(SettingsFlagEntry_guess, 0x00794904)[selectedEntry].enabled = noShowThisButton_guess->checked_guess == 0;
                g_configSink_guess->setValue_guess(
                    EQ_ARRAY(SettingsFlagEntry_guess, 0x00794904)[selectedEntry].enabled, "Tips",
                    EQ_ARRAY(SettingsEntry_guess, 0x007948E4)[selectedEntry].name_guess);
            }
        } else if (sender == historyButton_guess) {
            ((HelpTips_guess*)this)->ShowHistoryEntry_guess(GetTipOwner_guess());
        }
    } else if (msg == 1000 && pinstCTicketWnd_guess != 0) {
        // No length check: a link over about 250 characters overruns `path`.
        sprintf(path, "%s%s", "help\\", extra);
        pinstCTicketWnd_guess->ShowHelpPage_guess(path);
        pinstCTicketWnd_guess->ShowPage_guess(0);
        pinstCTicketWnd_guess->Activate();
    }
    return WndNotification(sender, msg, extra);
}

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

// Scalar deleting destructor of the tip window (vtable 0x65E960 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x00564E62
void* OptionsWindow_guess::scalarDeletingDestructor_guess(unsigned int flags)
{
    this->~OptionsWindow_guess();
    if ((flags & 1) != 0)
        operator delete(this);
    return this;
}

// Pops up a tip: mode 0 tip `value` (-1 random), mode 1 context tip `value` (0-72). Unless
// `allowDisabled`, a tip switched off stays hidden; returns whether the window opened.
// FUNCTION: TITANIUM 0x00564E7E
char OptionsWindow_guess::selectTip_guess(int value, char allowDisabled)
{
    if (g_modalState_guess->isActive_guess(EQ_GLOBAL(int, 0x00924470)) != 0)
        return 0;

    if (mode == 0) {
        if (allowDisabled == 0 && showTipOfDay == 0)
            return 0;
        if (value == -1)
            value = ((ItemList_guess*)this)->GetRandomTip_guess();
        else if (value >= ((ItemList_guess*)this)->tips_guess.count)
            return 0;
        ((ItemList_guess*)this)->ShowTip_guess(value);
    } else {
        // 73 entries in the context tip table.
        if (value < 0 || value >= 0x49)
            return 0;
        if (allowDisabled == 0 &&
            (tipsEnabled == 0 || EQ_ARRAY(SettingsFlagEntry_guess, 0x00794904)[value].enabled == 0))
            return 0;
        AddContextTip_guess(value);
        if (isReady_guess() == 0)
            showSelectedTip_guess();
    }
    UpdateCheckBoxes_guess();
    slot48_guess(1, 1);
    return 1;
}

// Loads the tips of the day: help\tips\totd.txt, one tip per "###" block, lines joined with <BR>, capped
// at 10239 characters; blocks of 10 characters or fewer are dropped.
// FUNCTION: TITANIUM 0x005648D8
// @early-stop: budget, diff ndiff=51
void ItemList_guess::LoadTipsOfTheDay_guess()
{
    ((Owner_guess*)this)->FreeTips_guess();

    char path[256];
    strcpy(path, "help\\tips\\");
    strcat(path, "totd.txt");
    // No file, no tips: NextTipButton then has nothing to pick.
    FILE* file = fopen(path, "rt");
    if (file == 0)
        return;

    char text[10240];
    char line[2048];
    line[1] = 0;
    fgets(line + 1, 0x7ff, file);
    while (!feof(file)) {
        text[0] = 0;
        while (!feof(file) && strncmp(line + 1, "###", 3) != 0) {
            line[1] = 0;
            fgets(line + 1, 0x7ff, file);
        }
        int total = 0;
        line[1] = 0;
        fgets(line + 1, 0x7ff, file);
        if (feof(file))
            break;
        do {
            if (strncmp(line + 1, "###", 3) == 0 || total > 0x27fe)
                break;
            int len = strlen(line + 1);
            if (line[len] == '\n')
                line[len] = 0;
            if (total + len > 0x27fe) {
                truncate_guess(line + 1, 0x27ff - total);
                len = strlen(line + 1);
            }
            strcat(text, line + 1);
            total += len;
            if (total + 4 < 0x27ff) {
                strcat(text, "<BR>");
                total += 4;
            } else {
                line[0] = 0;
                if (total > 0x27ff)
                    total = 0x27ff;
            }
            fgets(line + 1, 0x7ff, file);
        } while (!feof(file));
        if (total > 10) {
            void* tip = new char[total];
            strcpy((char*)tip, text);
            tips_guess.insertAt_guess(tips_guess.count, &tip);
        }
        while (!feof(file) && strncmp(line + 1, "###", 3) != 0) {
            line[1] = 0;
            fgets(line + 1, 0x7ff, file);
        }
    }
    fclose(file);
}

// Local polymorphic base with the CSidlScreenWnd ctor (0x005A3850), 0x15C bytes.
struct TipSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0TipSidlBase_guess@@QAE@PAUCXWnd@@PAUCXStr@@HHPAD@Z
    TipSidlBase_guess(CXWnd* parent, CXStr* screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1CSidlScreenWnd@@QAE@XZ
    virtual ~TipSidlBase_guess();
    char pad_004[0x120];
    void* sidlPiece_124;
    char pad_128[0x34];
};

struct CXStrPointer_guess {
    CXStr value_guess;

    CXStrPointer_guess(const char* text_guess) : value_guess(text_guess) {}
    operator CXStr*() { return &value_guess; }
};

struct TipArray_guess : Array_guess {
    unsigned char initialized_guess;
    char _pad_00d[3];
    ~TipArray_guess() { reset_guess(); }
};

// EXTERNAL: TITANIUM 0x0065E960 ??_7CTipWnd_guess@@6B@
struct CTipWnd_guess : TipSidlBase_guess {
    CXWnd* display_guess;             // 0x15c
    CXWnd* nextTipButton_guess;       // 0x160
    CXWnd* closeButton_guess;         // 0x164
    CXWnd* historyButton_guess;       // 0x168
    CXWnd* noShowThisLabel_guess;     // 0x16c
    CXWnd* noShowThisButton_guess;    // 0x170
    CXWnd* noShowButton_guess;        // 0x174
    int field_178_guess;              // 0x178
    TipArray_guess array_17c_guess;   // 0x17c
    TipArray_guess array_18c_guess;   // 0x18c
    TipArray_guess tips_guess;        // 0x19c
    int history_guess[5];             // 0x1ac
    int mode_guess;                   // 0x1c0
    int current_guess;                // 0x1c4
    unsigned char tipsEnabled_guess;  // 0x1c8
    unsigned char showTipOfDay_guess; // 0x1c9

    // EXTERNAL: TITANIUM 0x0059DB90 CTipWnd_guess::setWindowFlag_guess
    void setWindowFlag_guess(int value);
    CTipWnd_guess(CXWnd* parent, int mode);
};

static void InitTipArray_guess(TipArray_guess* array)
{
    array->data = 0;
    array->count = 0;
    array->capacity_guess = 0;
    array->initialized_guess = 1;
}

// Mode 0 shows NextTipButton and loads totd.txt; mode 1 shows History and the per-tip NoShowThis pair.
// FUNCTION: TITANIUM 0x00564B30
// @early-stop: budget, structural ndiff=40
CTipWnd_guess::CTipWnd_guess(CXWnd* parent, int mode)
    : TipSidlBase_guess(parent, CXStrPointer_guess("TipWindow"), 0xfffffeff, 1, 0)
{
    InitTipArray_guess(&array_17c_guess);
    InitTipArray_guess(&array_18c_guess);
    InitTipArray_guess(&tips_guess);
    current_guess = -1;

    nextTipButton_guess = 0;
    closeButton_guess = 0;
    noShowButton_guess = 0;
    noShowThisButton_guess = 0;
    display_guess = 0;
    historyButton_guess = 0;
    mode_guess = mode;
    tipsEnabled_guess = 1;
    showTipOfDay_guess = 1;

    array_17c_guess.reset_guess();
    array_18c_guess.reset_guess();
    tips_guess.reset_guess();
    for (int i = 0; i < 5; ++i)
        history_guess[i] = -1;

    if (((CSidlScreenWnd*)this)->SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        display_guess = ((CSidlScreenWnd*)this)->GetChildItem("Display");
        nextTipButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("NextTipButton");
        closeButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("CloseButton");
        noShowButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("NoShowButton");
        noShowThisLabel_guess = ((CSidlScreenWnd*)this)->GetChildItem("NoShowThisLabel");
        noShowThisButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("NoShowThisButton");
        historyButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("History");

        if (nextTipButton_guess != 0)
            ((OptionsWindow_guess*)nextTipButton_guess)->slot48_guess(mode == 0, 1);
        if (historyButton_guess != 0)
            ((OptionsWindow_guess*)historyButton_guess)->slot48_guess(mode == 1, 1);
        if (noShowThisButton_guess != 0)
            ((OptionsWindow_guess*)noShowThisButton_guess)->slot48_guess(mode == 1, 1);
        if (noShowThisLabel_guess != 0)
            ((OptionsWindow_guess*)noShowThisLabel_guess)->slot48_guess(mode == 1, 1);

        if (mode == 0) {
            tips_guess.reset_guess();
            ((ItemList_guess*)this)->LoadTipsOfTheDay_guess();
        }
        ((OptionsWindow_guess*)this)->LoadTipFlags_guess();
        setWindowFlag_guess(199);
        field_178_guess = 0;
    }
}

