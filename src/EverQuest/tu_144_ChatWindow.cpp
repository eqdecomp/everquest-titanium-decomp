// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 144: a hint from compare/tumap.py.
// CChatWindow ("ChatWindow": CWChatInput +0x160, CWChatOutput +0x164). CChatWindowView_guess and Object_guess are
// both CChatWindow; CChatManager_guess is CChatManager (0x9917E4), CEverQuestView_guess CEverQuest. Per window: default
// send channel +0x168 (8 say, 7 tell, 2 group, 0 guild, 5 OOC, 4 auction, 3 shout, 0x13 numbered channel,
// 0xF probably raid), language +0x1B0, main-window flag +0x1B4, 40-line input history at +0x1B8.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <setjmp.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "titanium/wnd/CTextEntryWnd.h"

// EXTERNAL: TITANIUM 0x0060E450 strcpy
// EXTERNAL: TITANIUM 0x0060F520 strchr
// EXTERNAL: TITANIUM 0x0060D750 memset
// EXTERNAL: TITANIUM 0x006220E9 _itoa
// EXTERNAL: TITANIUM 0x0060D5EB sprintf

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct CChatManager_guess {
    int slots_guess[34]; // 0x000
    int count_guess; // 0x088
    char unknown_08c_guess[0x18C];
    int fade_218_guess[8]; // 0x218

    // EXTERNAL: TITANIUM 0x004F5728 CChatManager_guess::Prepare_guess
    void Prepare_guess(void* object);
    // EXTERNAL: TITANIUM 0x004F2B4A CChatManager_guess::Function_2b4a_guess
    void Function_2b4a_guess(void* object);
    // EXTERNAL: TITANIUM 0x004F2859 CChatManager_guess::Function_2859_guess
    void Function_2859_guess(void* object);
    // EXTERNAL: TITANIUM 0x004F2B70 CChatManager_guess::Update_guess
    void Update_guess(void* object);
    // EXTERNAL: TITANIUM 0x004F288C CChatManager_guess::GetActiveChatWindow_guess
    struct Object_guess* GetActiveChatWindow_guess();
    // EXTERNAL: TITANIUM 0x004F5C21 CChatManager_guess::Cycle_guess
    void Cycle_guess();
    // EXTERNAL: TITANIUM 0x004F2B97 CChatManager_guess::SetDefault_guess
    void SetDefault_guess(void* window);
    // EXTERNAL: TITANIUM 0x004F28A1 CChatManager_guess::SetChannelMap_guess
    void SetChannelMap_guess(int channel, void* window);
    // EXTERNAL: TITANIUM 0x004F2B2F CChatManager_guess::GetChannelMap_guess
    void* GetChannelMap_guess(int channel);
    // EXTERNAL: TITANIUM 0x004F28BC CChatManager_guess::ClearChannel_guess
    void ClearChannel_guess(int channel);
    // EXTERNAL: TITANIUM 0x004F2BBE CChatManager_guess::GetRGBAFromIndex
    int GetRGBAFromIndex(int color);
};

struct ChannelList_guess {
    // EXTERNAL: TITANIUM 0x0040C059 ChannelList_guess::Name_guess
    char* Name_guess(int index);
};

struct ChatService_guess {
    // EXTERNAL: TITANIUM 0x005FF6E0 ChatService_guess::Name_guess
    char* Name_guess(int index);
};

struct CEverQuestView_guess {
    char unknown_000_guess[0x290];
    ChannelList_guess* channels_290_guess; // 0x290
    char unknown_294_guess[0x5A0];
    ChatService_guess* service_834_guess; // 0x834

    // EXTERNAL: TITANIUM 0x00498B78 CEverQuestView_guess::InterpretCmd_guess
    void InterpretCmd_guess(void* player, char* text);
    // EXTERNAL: TITANIUM 0x00496AEF CEverQuestView_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x00494051 CEverQuestView_guess::SetChatInputFocus_guess
    void SetChatInputFocus_guess(int value);
};
#define g_global_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)

struct ScreenPos_guess {
    int field_00_guess;
    int field_04_guess;
    int field_08_guess;
    int field_0c_guess;
};

struct Str_guess {
    int field_00_guess;

    Str_guess() : field_00_guess(0) {}

    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& value);
    ~Str_guess() {
        if (field_00_guess != 0) {
            FreeRep(field_00_guess);
        }
        field_00_guess = 0;
    }

    // EXTERNAL: TITANIUM 0x00571E00 Str_guess::Str_guess
    Str_guess(const char* text);

    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(int value);

    // EXTERNAL: TITANIUM 0x00571F70 Str_guess::Assign_guess
    Str_guess& Assign_guess(const Str_guess& value);
    // EXTERNAL: TITANIUM 0x00572C10 Str_guess::Set_guess
    Str_guess& Set_guess(const CXStr& value);
    // EXTERNAL: TITANIUM 0x00572E00 Str_guess::Append_guess
    Str_guess& Append_guess(const char* text);
};

// EXTERNAL: TITANIUM 0x005A40F0 BuildText_guess
Str_guess __cdecl BuildText_guess(int value);
// EXTERNAL: TITANIUM 0x0042E3D9 DecorateText_guess
Str_guess __cdecl DecorateText_guess(const char* format, const Str_guess& value);
// EXTERNAL: TITANIUM 0x004B1357 MakeText_guess
Str_guess __cdecl MakeText_guess(const Str_guess& value, const char* format);

struct Entry_guess {
    char unknown_00_guess[8];
    int count_guess;
};

struct EntrySlot_guess {
    Entry_guess* value_guess; // 0x0

    // EXTERNAL: TITANIUM 0x0053ACD9 EntrySlot_guess::EntrySlot_guess
    EntrySlot_guess();
    // EXTERNAL: TITANIUM 0x004482FB EntrySlot_guess::~EntrySlot_guess
    ~EntrySlot_guess();

    Entry_guess** operator&() { return &value_guess; }
};

struct FlagSource_guess {
    char unknown_000_guess[0x60];
    unsigned flags_060_guess;
};

struct WindowBase_guess {
    virtual void RefreshCounts_guess() {}

    char unknown_004_guess[0x14];
    char field_018_guess;
    char unknown_019_guess[0x4b];
    unsigned flags_064_guess;
    char unknown_068_guess[0xb4];
    Str_guess text_11c_guess;

    // EXTERNAL: TITANIUM 0x005A3900 WindowBase_guess::WindowBase_guess
    WindowBase_guess(int value, const Str_guess& name);
};

struct Widget_guess {
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
    virtual void Slot62_guess(int value);
    virtual void Slot63_guess(void* value);
    virtual void Slot64_guess(int value);
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
    virtual void Slot76_guess(int value);

    // EXTERNAL: TITANIUM 0x0059D860 Widget_guess::GetScreenPos_guess
    ScreenPos_guess* GetScreenPos_guess(ScreenPos_guess* out);
    // EXTERNAL: TITANIUM 0x0059CE00 Widget_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x005A8B00 Widget_guess::SetSTMLText
    void SetSTMLText(Str_guess value, int first, int second);
    // EXTERNAL: TITANIUM 0x005AC670 Widget_guess::Reset_guess
    void Reset_guess();

    char unknown_004_guess[0x15]; // 0x004
    char field_019_guess;
    char unknown_01a_guess[0x4a];
    unsigned flags_064_guess; // 0x064
    char unknown_068_guess[0x14];
    int field_07c_guess;
    char unknown_080_guess[0x88];
    int field_108_guess;           // 0x108
    int field_10c_guess;           // 0x10C
    // EXTERNAL: TITANIUM 0x005AC2A0 Widget_guess::GetText_guess
    void GetText_guess(int* output, Str_guess value);
    // EXTERNAL: TITANIUM 0x004D7EBC Widget_guess::SetMaxChars_guess
    void SetMaxChars_guess(int value);
};

struct WidgetTarget_guess : Widget_guess {
    char unknown_110_guess[0x64];
    int field_174_guess;
    char unknown_178_guess[0x48];
    int field_1c0_guess;
};

struct Sub_guess {
    // EXTERNAL: TITANIUM 0x004EB924 Sub_guess::At_guess
    int* At_guess(int value);
};

struct Inner_guess {
    char unknown_00_guess[0x74];
    int mouse_x_74_guess; // 0x74
    int mouse_y_78_guess; // 0x78
    char unknown_7c_guess[0x78];
    Sub_guess sub_f4_guess; // 0xF4
};

struct Root_guess {
    Inner_guess* inner_guess; // 0x00
};
#define g_root_guess EQ_GLOBAL(Root_guess*, 0x0099D334)

struct Object_guess {
    char unknown_000[0x11C];
    Str_guess text_11c_guess;
    char unknown_120_guess[0x30];
    int field_150_guess;
    char unknown_154_guess[8];
    CChatManager_guess* component;
    Widget_guess* widget_160; // 0x160
    Widget_guess* widget_164; // 0x164
    char unknown_168_guess[0x50];
    Entry_guess* entries_1b8_guess[40]; // 0x1B8
    int historyWriteIndex_0258_guess;
    int historyIndex_025c_guess;
    int chatFont_0260_guess;
    int field_264_guess;

    // EXTERNAL: TITANIUM 0x0059D080 Object_guess::Set_guess
    void Set_guess(int value);

    // EXTERNAL: TITANIUM 0x004D22D7 Object_guess::Default_guess
    void Default_guess(int value);
    // EXTERNAL: TITANIUM 0x0059EDF0 Object_guess::SetFocus
    void SetFocus();
    // EXTERNAL: TITANIUM 0x005A0E50 Object_guess::OnProcessFrame
    void OnProcessFrame();

    Str_guess GetSTMLText();
    int OnSetFocus_guess(int unused);
    void HandleRButtonDown_guess(int first, int second);
    void Function_6cc9_guess();
    void HistoryUp_guess();
    void HistoryDown_guess();
    int GetWindowTextA_guess(int value);
    void ScrollChatWindowUp_guess();
    void ScrollChatWindowDown_guess();
    void SetChatFont_guess(int value);
    // EXTERNAL: TITANIUM 0x005A1E80 Object_guess::FinishUpdate_guess
    void FinishUpdate_guess(int first, int second);
};

struct CXStrEx_guess : CXStr {
    // EXTERNAL: TITANIUM 0x004D95D0 CXStrEx_guess::IsEmpty_guess
    bool IsEmpty_guess() const;
    // EXTERNAL: TITANIUM 0x005722D0 CXStrEx_guess::Convert_guess
    void Convert_guess(int encoding);
    // EXTERNAL: TITANIUM 0x00571590 CXStrEx_guess::CharAt_guess
    char CharAt_guess(int index) const;
    // EXTERNAL: TITANIUM 0x00572130 CXStrEx_guess::Delete_guess
    void Delete_guess(int index, int count);
    // EXTERNAL: TITANIUM 0x004CC626 CXStrEx_guess::First_guess
    char First_guess(int index) const;
    // EXTERNAL: TITANIUM 0x00572650 CXStrEx_guess::Compare_guess
    int Compare_guess(const CXStr& other) const;
    // EXTERNAL: TITANIUM 0x00573F00 CXStrEx_guess::Find_guess
    int Find_guess(const CXStr& text, int first, int second) const;
};

// Virtual slots of the child windows (0xFC set text, 0x130 get text).
struct VWnd_guess {
    virtual void V00_guess(); virtual void V01_guess(); virtual void V02_guess(); virtual void V03_guess();
    virtual void V04_guess(); virtual void V05_guess(); virtual void V06_guess(); virtual void V07_guess();
    virtual void V08_guess(); virtual void V09_guess(); virtual void V10_guess(); virtual void V11_guess();
    virtual void V12_guess(); virtual void V13_guess(); virtual void V14_guess(); virtual void V15_guess();
    virtual void V16_guess(); virtual void V17_guess(); virtual void V18_guess(); virtual void V19_guess();
    virtual void V20_guess(); virtual void V21_guess(); virtual void V22_guess(); virtual void V23_guess();
    virtual void V24_guess(); virtual void V25_guess(); virtual void V26_guess(); virtual void V27_guess();
    virtual void V28_guess(); virtual void V29_guess(); virtual void V30_guess(); virtual void V31_guess();
    virtual void V32_guess(); virtual void V33_guess(); virtual void V34_guess(); virtual void V35_guess();
    virtual void V36_guess(); virtual void V37_guess(); virtual void V38_guess(); virtual void V39_guess();
    virtual void V40_guess(); virtual void V41_guess(); virtual void V42_guess(); virtual void V43_guess();
    virtual void V44_guess(); virtual void V45_guess(); virtual void V46_guess(); virtual void V47_guess();
    virtual void V48_guess(); virtual void V49_guess(); virtual void V50_guess(); virtual void V51_guess();
    virtual void V52_guess(); virtual void V53_guess(); virtual void V54_guess(); virtual void V55_guess();
    virtual void V56_guess(); virtual void V57_guess(); virtual void V58_guess(); virtual void V59_guess();
    virtual void V60_guess(); virtual void V61_guess(); virtual void V62_guess();
    virtual void SetWindowText_guess(const CXStr& text); // 0xFC
    virtual void V64_guess(); virtual void V65_guess(); virtual void V66_guess(); virtual void V67_guess();
    virtual void V68_guess(); virtual void V69_guess(); virtual void V70_guess(); virtual void V71_guess();
    virtual void V72_guess(); virtual void V73_guess(); virtual void V74_guess(); virtual void V75_guess();
    virtual CXStrEx_guess GetWindowText_guess() const; // 0x130

    char unknown_004_guess[0x24];
    CXWnd* parent_028_guess; // 0x28
};

struct ContextMenu_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x00599070 ContextMenu_guess::ItemAt_guess
    int ItemAt_guess(int* point);
    // EXTERNAL: TITANIUM 0x00560D80 ContextMenu_guess::GetEntryText_guess
    CXStr GetEntryText_guess();
};

struct ChatLink_guess {
    char unknown_00_guess[0x1C];
    unsigned flags_1c_guess; // 0x1C
    char unknown_20_guess[0xC];
};

#define pinstCChatManager_guess EQ_GLOBAL(CChatManager_guess*, 0x009917E4)

#define g_chat_channel_guess EQ_GLOBAL(unsigned char, 0x009237EC)
#define g_chat_language_guess EQ_GLOBAL(int, 0x009237F0)
#define g_chat_target_guess EQ_ARRAY(char, 0x009237F4)
#define g_number_buffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x0046D3A3 ParseItemLink_guess
int __cdecl ParseItemLink_guess(char* text, ChatLink_guess* link);
// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
void __cdecl FormatString_guess(char* out, int id, char* a1, char* a2, char* a3, char* a4,
                                char* a5, char* a6, char* a7, char* a8, char* a9);
// EXTERNAL: TITANIUM 0x0060BEB0 WriteIniString_guess
void __cdecl WriteIniString_guess(char* section, char* key, char* value, char* file);

struct CChatWindowView_guess : WindowBase_guess {
    virtual void RefreshCounts_guess() {}
    virtual void S01_guess(int value); virtual void S02_guess(); virtual void S03_guess(); virtual void S04_guess();
    virtual void S05_guess(); virtual void S06_guess(); virtual void S07_guess(); virtual void S08_guess();
    virtual void S09_guess(); virtual void S10_guess(); virtual void S11_guess(); virtual void S12_guess();
    virtual void S13_guess(); virtual void S14_guess(); virtual void S15_guess(); virtual void S16_guess();
    virtual void S17_guess(); virtual void S18_guess(); virtual void S19_guess(); virtual void S20_guess();
    virtual void S21_guess(); virtual void S22_guess(); virtual void S23_guess(); virtual void S24_guess();
    virtual void S25_guess(); virtual void S26_guess(); virtual void S27_guess(); virtual void S28_guess();
    virtual void S29_guess(); virtual void S30_guess(); virtual void S31_guess();
    virtual int WndNotification_guess(CXWnd* sender, unsigned int message, void* data); // 0x80
    virtual void S33_guess(); virtual void S34_guess(); virtual void S35_guess(); virtual void S36_guess();
    virtual void S37_guess(); virtual void S38_guess(); virtual void S39_guess(); virtual void S40_guess();
    virtual void S41_guess(); virtual void S42_guess(); virtual void S43_guess(); virtual void S44_guess();
    virtual void S45_guess(); virtual void S46_guess(); virtual void S47_guess();
    virtual void Show_guess(int show, int bringToTop); // 0xC0
    virtual void S49_guess(); virtual void S50_guess(); virtual void S51_guess(); virtual void S52_guess();
    virtual void S53_guess(); virtual void S54_guess(); virtual void S55_guess(); virtual void S56_guess();
    virtual void S57_guess(); virtual void S58_guess(); virtual void S59_guess(); virtual void S60_guess();
    virtual void S61_guess(); virtual void S62_guess();
    virtual void SetWindowText_guess(const CXStr& text); // 0xFC

    void AddOutputText_guess(CXStr text, int color);
    void Deactivate_guess();
    void AddHistory_guess(CXStrEx_guess text);
    // EXTERNAL: TITANIUM 0x004D22D7 CChatWindowView_guess::GetText_guess
    CXStr GetText_guess();

    // EXTERNAL: TITANIUM 0x00652B20 ??_7CChatWindowView_guess@@6B@

    char unknown_120_guess[4];
    FlagSource_guess* field_124_guess;
    char unknown_128_guess[0x28];
    int field_150_guess;
    char unknown_154_guess[8];
    CChatManager_guess* component;
    WidgetTarget_guess* widget_160;
    WidgetTarget_guess* widget_164;
    int channel_0168_guess;
    int field_16c_guess;
    char tellTarget_0170_guess;
    char unknown_171_guess[3];
    int field_174_guess;
    char unknown_178_guess[0x38];
    int language_01b0_guess;
    char field_1b4_guess;
    char field_1b5_guess;
    char unknown_1b6_guess[2];
    EntrySlot_guess entries_1b8_guess[40];
    int historyWriteIndex_0258_guess;
    int historyIndex_025c_guess;
    int field_260_guess;
    int field_264_guess;

    // EXTERNAL: TITANIUM 0x005A25B0 CChatWindowView_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A1E10 CChatWindowView_guess::GetChildItem
    WidgetTarget_guess* GetChildItem(const Str_guess* name);

    CChatWindowView_guess(int value);
};

struct Action_guess {
    // EXTERNAL: TITANIUM 0x005BFF70 Action_guess::Apply_guess
    void Apply_guess(int value, bool current, int flags);
};

struct Registry_guess {
    // EXTERNAL: TITANIUM 0x004DAFEA Registry_guess::Find_guess
    Action_guess* Find_guess(int index);
};

#define pinstCContextMenuManager_guess EQ_GLOBAL(Registry_guess*, 0x0099D414)

// Appends `text` to CWChatOutput in chat colour `color` (an STML colour tag from
// CChatManager::GetRGBAFromIndex); keeps the view at the bottom only if it was there.
// FUNCTION: TITANIUM 0x004F6A90
// @early-stop: budget, structural ndiff=8
void CChatWindowView_guess::AddOutputText_guess(CXStr text, int color) {
    int output;
    Str_guess result;
    char send = 1;
    if (widget_164 != 0) {
        if (widget_164->field_10c_guess != widget_164->field_108_guess) {
            send = 0;
        }
        result.Assign_guess(MakeText_guess(
            DecorateText_guess(
                EQ_ARRAY(char, 0x0064AF8C),
                BuildText_guess(component->GetRGBAFromIndex(color))),
            EQ_ARRAY(char, 0x00641684)));
        result.Set_guess(text);
        result.Append_guess(EQ_ARRAY(char, 0x0064AF80));
        widget_164->GetText_guess(&output, result);
        if (send == 1) {
            int offset = widget_164->field_108_guess;
            widget_164->Slot64_guess(offset);
        }
    }
}

// CChatWindow::Deactivate (vtable slot 34): a window other than the main one leaves the chat manager's
// channel maps and is destroyed (vtable slot 1).
// FUNCTION: TITANIUM 0x004F6BF0
void CChatWindowView_guess::Deactivate_guess() {
    if (field_1b4_guess == 0) {
        if (component != 0) {
            component->Function_2b4a_guess(this);
            component->slots_guess[33] = 0;
            component->Function_2859_guess(this);
        }
        S01_guess(1);
    }
}

// CChatWindow::HandleRButtonDown: before the base opens the context menu (+0x150), ticks its
// "default window" item (+0x264) when this is the manager's default window.
// FUNCTION: TITANIUM 0x004F6C2C
void Object_guess::HandleRButtonDown_guess(int first, int second) {
    if (field_150_guess > -1 && component != 0) {
        component->Prepare_guess(this);
        int value = field_264_guess;
        if (value != -1) {
            Action_guess* action = pinstCContextMenuManager_guess->Find_guess(field_150_guess);
            int index = component->count_guess;
            int slot;
            if (index != -1) {
                slot = component->slots_guess[index];
            } else {
                slot = 0;
            }
            if (slot == (int)this) {
                action->Apply_guess(value, 1, 0);
            } else {
                action->Apply_guess(value, 0, 0);
            }
        }
    }
    FinishUpdate_guess(first, second);
}

// CStmlWnd::GetSTMLText: returns the STML text (+0x11C); applied here to CWChatOutput.
// FUNCTION: TITANIUM 0x004F6895
Str_guess Object_guess::GetSTMLText() {
    return text_11c_guess;
}

// CChatWindow::OnSetFocus: makes this the manager's active window and brings it to the top.
// FUNCTION: TITANIUM 0x004F6CA7
int Object_guess::OnSetFocus_guess(int unused) {
    if (component != 0) {
        component->Update_guess(this);
    }
    Set_guess(1);
    return 0;
}

// OnProcessFrame: keeps CEverQuest's typing state (0x496AEF/0x494051) in step with whether CWChatInput
// has the focus, and gives the focus back to the window when CWChatOutput takes it.
// FUNCTION: TITANIUM 0x004F6CC9
void Object_guess::Function_6cc9_guess() {
    if (g_global_guess->Check_guess()) {
        if (component != 0 && component->GetActiveChatWindow_guess() == this &&
            widget_160 != 0 && !widget_160->Check_guess()) {
            g_global_guess->SetChatInputFocus_guess(1);
        }
    } else {
        if (widget_160 != 0 && widget_160->Check_guess()) {
            if (component != 0) {
                component->Update_guess(this);
            }
            g_global_guess->SetChatInputFocus_guess(0);
        }
    }

    if (widget_164 != 0 && widget_164->Check_guess()) {
        SetFocus();
    }
    OnProcessFrame();
}

// Up arrow: shows the previous non-empty history line in CWChatInput.
// FUNCTION: TITANIUM 0x004F6D57
void Object_guess::HistoryUp_guess() {
    int index = historyIndex_025c_guess - 1;
    if (index < 0) {
        index = 0x27;
    }
    if (index != historyWriteIndex_0258_guess) {
        Entry_guess** entry = &entries_1b8_guess[index];
        int count = *entry != 0 ? (*entry)->count_guess : 0;
        if (count > 0) {
            if (widget_160 != 0) {
                widget_160->Slot63_guess(entry);
            }
            historyIndex_025c_guess = index;
        }
    }
}

// Down arrow: shows the next history line, or empties the input past the newest.
// FUNCTION: TITANIUM 0x004F6DA3
void Object_guess::HistoryDown_guess() {
    if (historyIndex_025c_guess == historyWriteIndex_0258_guess) {
        if (widget_160 != 0) {
            Str_guess text(EQ_ARRAY(char, 0x0063F53F));
            widget_160->Slot63_guess(&text);
        }
    } else {
        int index = historyIndex_025c_guess + 1;
        if (index >= 0x28) {
            index = 0;
        }
        if (index == historyWriteIndex_0258_guess) {
            if (widget_160 != 0) {
                Str_guess text(EQ_ARRAY(char, 0x0063F53F));
                widget_160->Slot63_guess(&text);
            }
            historyIndex_025c_guess = index;
        } else {
            Entry_guess** entry = &entries_1b8_guess[index];
            int count = *entry != 0 ? (*entry)->count_guess : 0;
            if (count > 0) {
                if (widget_160 != 0) {
                    widget_160->Slot63_guess(entry);
                }
                historyIndex_025c_guess = index;
            }
        }
    }
}

// Stores a sent line in the 40-line ring unless it is empty, repeats the last line, or starts with the
// 4-character string 0x3771. Compare_guess is CXStr::operator== and Find_guess CXStr::CompareN (names.tsv).
// FUNCTION: TITANIUM 0x004F6EA1
void CChatWindowView_guess::AddHistory_guess(CXStrEx_guess text) {
    text.Convert_guess(1);
    CXStr prefix(pStringTable->getString(0x3771, 0));
    static_cast<CXStrEx_guess&>(prefix).Convert_guess(1);
    int index = historyWriteIndex_0258_guess - 1;
    if (index < 0) {
        index = 0x27;
    }
    if (((CXStrEx_guess*)&entries_1b8_guess[index])->Compare_guess(text) == 0) {
        int length = text.Ptr != 0 ? text.Ptr->length : 0;
        if (length <= 0 || text.Find_guess(prefix, 4, 0) == 0) {
            return;
        }
        *(CXStr*)&entries_1b8_guess[historyWriteIndex_0258_guess++] = text;
        if (historyWriteIndex_0258_guess >= 0x28) {
            historyWriteIndex_0258_guess = 0;
        }
    }
    historyIndex_025c_guess = historyWriteIndex_0258_guess;
}

// GetWindowText for the chat window: the input box's text, else the window's own; the CXStr comes back
// through the hidden `value` pointer.
// FUNCTION: TITANIUM 0x004F6F9E
int Object_guess::GetWindowTextA_guess(int value) {
    int result = 0;
    // fake match: setjmp forces EBP frame
    if (0) {
        jmp_buf buffer_guess;
        setjmp(buffer_guess);
        int* address_guess = &result;
    }
    if (widget_160 != 0) {
        widget_160->Slot76_guess(value);
    } else {
        Default_guess(value);
    }
    return value;
}

// Page Up: scrolls the output up one view less 8 pixels.
// FUNCTION: TITANIUM 0x004F6FCE
void Object_guess::ScrollChatWindowUp_guess() {
    if (widget_164 != 0) {
        ScreenPos_guess pos;
        ScreenPos_guess* p = widget_164->GetScreenPos_guess(&pos);
        widget_164->Slot64_guess(
            widget_164->field_10c_guess - p->field_0c_guess + p->field_04_guess + 8);
    }
}

// Page Down: scrolls the output down one view less 8 pixels.
// FUNCTION: TITANIUM 0x004F7008
void Object_guess::ScrollChatWindowDown_guess() {
    if (widget_164 != 0) {
        ScreenPos_guess pos;
        ScreenPos_guess* p = widget_164->GetScreenPos_guess(&pos);
        widget_164->Slot64_guess(
            widget_164->field_10c_guess - p->field_04_guess + p->field_0c_guess - 8);
    }
}

// Compiler-generated vector destructor helper name.
// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z

struct ObjectBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ObjectBase_guess::~ObjectBase_guess
    ~ObjectBase_guess();
};

struct ObjectDtor_guess : ObjectBase_guess {
    char unknown_000_guess[0x1B8];
    EntrySlot_guess entries_guess[40]; // 0x1B8

    ~ObjectDtor_guess();
    void* ScalarDeletingDtor_guess(unsigned flags);
};

// Chat window constructor: finds CWChatInput (text limit through 0x004D7EBC: 512, or 170 when the
// language id at 0x923D74 is not 0) and CWChatOutput, empties the 40-line input history and starts on the
// say channel (+0x168 = 8).
// FUNCTION: TITANIUM 0x004F68B3
CChatWindowView_guess::CChatWindowView_guess(int value)
    : WindowBase_guess(value, "ChatWindow") {
    if (field_124_guess != 0) {
        flags_064_guess |= field_124_guess->flags_060_guess | 0x800;
        field_018_guess = 0;
        CreateChildrenFromSidl();

        {
            Str_guess name("CWChatInput");
            widget_160 = GetChildItem(&name);
        }
        if (widget_160 != 0) {
            widget_160->flags_064_guess |= 0x800c0;
            widget_160->field_07c_guess = -1;
            if (EQ_GLOBAL(int, 0x00923D74) == 0) {
                // Input limit 512 characters, or 170 when the flag at 0x923D74 is set.
                widget_160->SetMaxChars_guess(0x200);
            } else {
                widget_160->SetMaxChars_guess(0xaa);
            }
        }

        {
            Str_guess name("CWChatOutput");
            widget_164 = GetChildItem(&name);
        }
        if (widget_164 != 0) {
            // Probably the output's line limit.
            widget_164->field_1c0_guess = 400;
            widget_164->field_019_guess = 1;
            if (EQ_GLOBAL(int, 0x00923D74) == 0) {
                widget_164->field_174_guess = -2;
            }
        }

        int count = 0x28;
        EntrySlot_guess* slot = entries_1b8_guess;
        do {
            slot->~EntrySlot_guess();
            ++slot;
            --count;
        } while (count != 0);

        field_16c_guess = -1;
        field_264_guess = -1;
        historyWriteIndex_0258_guess = 0;
        historyIndex_025c_guess = 0;
        field_1b4_guess = 0;
        field_1b5_guess = 0;
        language_01b0_guess = 0;
        channel_0168_guess = 8;
        tellTarget_0170_guess = 0;
        field_260_guess = 3;
    }
}

// Scalar deleting destructor of a chat window (vtable 0x652B20 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x004F7091
void* ObjectDtor_guess::ScalarDeletingDtor_guess(unsigned flags) {
    this->~ObjectDtor_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Destructor of a chat window: destroys the 40-line input history strings (+0x1B8), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004F70AD
ObjectDtor_guess::~ObjectDtor_guess() {
}

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// WndNotification. 10: the main window cannot be closed (shown again). 0x21: the rename dialog's text
// becomes the title. 0x1B: a link click in the output. 6: Enter sends the input. 0x16: Up/Down keys walk
// the history. 0x14: context-menu commands, by menu id (data).
// FUNCTION: TITANIUM 0x004F70EF
// @early-stop: budget, structural ndiff=358
int CChatWindowView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    int point[2];
    if (message == 10) {
        if (field_1b4_guess == 1) {
            Show_guess(1, 1);
            return 0;
        }
    } else if (message == 0x21) {
        if ((int)data == 1) {
            CXStr text = ((ContextMenu_guess*)sender)->GetEntryText_guess();
            SetWindowText_guess(text);
        }
        return 0;
    // Item link clicked: sends OP_ItemLinkClick with flag 4, plus 2 with shift held.
    } else if (message == 0x1b) {
        if (sender == (CXWnd*)widget_164) {
            ChatLink_guess link;
            memset(&link, 0, sizeof(link));
            if (ParseItemLink_guess((char*)data, &link) == 0) {
                link.flags_1c_guess |= 4;
                if (pinstCXWndManager_guess->GetKeyboardFlags() & 1) {
                    link.flags_1c_guess |= 2;
                }
                EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_ItemLinkClick, &link, sizeof(link), 1);
            }
        }
    } else if (message == 6) {
        if (sender == (CXWnd*)widget_160 && widget_160 != 0) {
            AddHistory_guess(((VWnd_guess*)widget_160)->GetWindowText_guess());
            int saved_channel = g_chat_channel_guess;
            int saved_language = g_chat_language_guess;
            char saved_target[0x40];
            // Sends with this window's channel, language and target, then restores the global ones
            // (0x9237EC channel, 0x9237F0 language, 0x9237F4 tell or channel name).
            if (saved_channel == 7 || saved_channel == 0x13 || saved_channel == 0x14) {
                strcpy(saved_target, g_chat_target_guess);
            }
            g_chat_language_guess = language_01b0_guess;
            g_chat_channel_guess = (unsigned char)channel_0168_guess;
            if (channel_0168_guess == 7) {
                strcpy(g_chat_target_guess, &tellTarget_0170_guess);
            } else if (channel_0168_guess == 0x13) {
                if (g_global_guess->channels_290_guess != 0) {
                    char* name = g_global_guess->channels_290_guess->Name_guess(field_16c_guess);
                    if (name != 0) {
                        strcpy(g_chat_target_guess, name);
                    }
                }
            } else if (channel_0168_guess == 0x14) {
                if (g_global_guess->service_834_guess != 0) {
                    char* name = g_global_guess->service_834_guess->Name_guess(field_16c_guess);
                    if (name != 0) {
                        strcpy(g_chat_target_guess, name);
                    }
                }
            }
            bool has_text = !((VWnd_guess*)widget_160)->GetWindowText_guess().IsEmpty_guess();
            if (has_text) {
                CXStrEx_guess text = ((VWnd_guess*)widget_160)->GetWindowText_guess();
                text.Convert_guess(0);
                char line[0x2000];
                strcpy(line, ((VWnd_guess*)widget_160)->GetWindowText_guess());
                g_global_guess->InterpretCmd_guess(EQ_GLOBAL(void*, 0x00905CE4), line);
                ((VWnd_guess*)widget_160)->SetWindowText_guess(CXStr(line));
            }
            g_chat_language_guess = saved_language;
            g_chat_channel_guess = (unsigned char)saved_channel;
            if (g_chat_channel_guess == 7 || g_chat_channel_guess == 0x13 || g_chat_channel_guess == 0x14) {
                strcpy(g_chat_target_guess, saved_target);
            }
            ((VWnd_guess*)widget_160)->SetWindowText_guess(CXStr(EQ_ARRAY(char, 0x0063F53F)));
            ((VWnd_guess*)widget_160)->parent_028_guess->SetFocus();
            return 0;
        }
    } else if (message == 0x16) {
        if (sender == (CXWnd*)widget_160 && widget_160 != 0) {
            int* key = (int*)data;
            // DIK_UP (200) and DIK_DOWN (0xD0), on key down.
            if (key[1] == 200 && (key[0] & 1)) {
                ((Object_guess*)this)->HistoryUp_guess();
            } else if (key[1] == 0xd0 && (key[0] & 1)) {
                ((Object_guess*)this)->HistoryDown_guess();
            }
            return 0;
        }
    } else if (message == 0x14) {
        point[0] = g_root_guess->inner_guess->mouse_x_74_guess;
        point[1] = g_root_guess->inner_guess->mouse_y_78_guess;
        ContextMenu_guess* menu = (ContextMenu_guess*)sender;
        int index = menu->ItemAt_guess(point);
        int id = (int)data;
        // 0x2A cycles the active window; 0x2D flips bit 0 of the output's style.
        if (id == 0x2a) {
            component->Cycle_guess();
        } else if (id == 0x2d) {
            widget_164->flags_064_guess ^= 1;
            ((Action_guess*)menu)->Apply_guess(index, (widget_164->flags_064_guess & 1) != 0, 0);
        // Rename: input dialog with string 0xC45, 15 characters.
        } else if (id == 0x2c) {
            pinstCTextEntryWnd_guess->Activate_guess(this, 0, pStringTable->getString(0xc45, 0), 1, 0xf,
                                             GetText_guess());
        // Toggles this as the default window (strings 0x3AA2 off, 0x3AA3 on).
        } else if (id == 0x2b) {
            int current = component->count_guess;
            void* window = current != -1 ? (void*)component->slots_guess[current] : 0;
            if (window == this) {
                component->count_guess = -1;
                AddOutputText_guess(pStringTable->getString(0x3aa2, 0), 10);
                ((Action_guess*)sender)->Apply_guess(index, 0, 0);
            } else {
                component->SetDefault_guess(this);
                AddOutputText_guess(pStringTable->getString(0x3aa3, 0), 10);
                ((Action_guess*)sender)->Apply_guess(index, 1, 0);
            }
        // 300-331: language; the main window also saves DefaultLanguage.
        } else if (id >= 300 && id < 0x14c) {
            int language = id - 300;
            language_01b0_guess = language;
            if (field_1b4_guess == 1) {
                g_chat_language_guess = language;
                sprintf((char*)point, EQ_ARRAY(char, 0x0063F53C), language);
                WriteIniString_guess("Defaults", "DefaultLanguage", (char*)point, ".\\eqclient.ini");
            }
            ((Action_guess*)menu)->Apply_guess(index, 1, 1);
            char text[0x200];
            if (index != -1) {
                FormatString_guess(text, 0xc3d, ((ContextMenu_guess*)sender)->GetItemText(index, 1),
                                   0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                FormatString_guess(text, 0xc3d, _itoa(language, g_number_buffer_guess, 10),
                                   0, 0, 0, 0, 0, 0, 0, 0);
            }
            AddOutputText_guess(text, 10);
        // 0x9A-0x9D: filter presets that move every listed channel here (strings 0x1798-0x179B).
        } else if (id >= 0x9a && id <= 0x9d) {
            for (int i = 0; i < ((ContextMenu_guess*)sender)->ItemsCount; i++) {
                int item = ((ContextMenu_guess*)sender)->GetItemData(i);
                if (item < 0x9a || item > 0x9d) {
                    if (item >= 100 && item <= 0x99) {
                        component->SetChannelMap_guess(item - 100, this);
                        ((Action_guess*)sender)->Apply_guess(i, 1, 0);
                    }
                }
            }
            int string_id = -1;
            switch (id) {
            case 0x9a:
                string_id = 0x1798;
                break;
            case 0x9b:
                string_id = 0x1799;
                break;
            case 0x9c:
                string_id = 0x179a;
                break;
            case 0x9d:
                string_id = 0x179b;
                break;
            }
            AddOutputText_guess(pStringTable->getString(string_id, 0), 10);
        // 100-153: shows or stops channel id-100 in this window.
        } else if (id >= 100 && id <= 0x99) {
            int channel = (int)data - 100;
            CXStr text;
            if (index != -1) {
                text = ((ContextMenu_guess*)sender)->GetItemText(index, 1);
            } else {
                char buffer[0x100];
                FormatString_guess(buffer, 0xc3e, _itoa(channel, g_number_buffer_guess, 10),
                                   0, 0, 0, 0, 0, 0, 0, 0);
                text += buffer;
            }
            text += EQ_ARRAY(char, 0x0063FE10);
            if (component->GetChannelMap_guess(channel) != this) {
                component->SetChannelMap_guess(channel, this);
                text += pStringTable->getString(0xc3f, 0);
                AddOutputText_guess(text, 10);
                ((Action_guess*)sender)->Apply_guess(index, 1, 0);
            } else {
                component->ClearChannel_guess(channel);
                text += pStringTable->getString(0xc40, 0);
                AddOutputText_guess(text, 10);
                ((Action_guess*)sender)->Apply_guess(index, 0, 0);
            }
        // 200-217: default send channel.
        } else if (id >= 200 && id <= 0xd9) {
            CXStr text;
            if (index != -1) {
                text = ((ContextMenu_guess*)sender)->GetItemText(index, 1);
            } else {
                char buffer[0x100];
                FormatString_guess(buffer, 0xc41, _itoa(id - 200, g_number_buffer_guess, 10),
                                   0, 0, 0, 0, 0, 0, 0, 0);
                text += buffer;
            }
            switch (id) {
            case 200:
                channel_0168_guess = 8;
                break;
            case 0xc9:
                channel_0168_guess = 7;
                // Tell target "a": a placeholder name, original behaviour.
                tellTarget_0170_guess = 'a';
                unknown_171_guess[0] = 0;
                break;
            case 0xca:
                channel_0168_guess = 2;
                break;
            case 0xcb:
                channel_0168_guess = 0;
                break;
            case 0xcc:
                channel_0168_guess = 5;
                break;
            case 0xcd:
                channel_0168_guess = 4;
                break;
            case 0xce:
                channel_0168_guess = 3;
                break;
            case 0xcf:
            case 0xd0:
            case 0xd1:
            case 0xd2:
            case 0xd3:
            case 0xd4:
            case 0xd5:
            case 0xd6:
            case 0xd7:
            case 0xd8:
                channel_0168_guess = 0x13;
                field_16c_guess = id - 0xcf;
                break;
            case 0xd9:
                channel_0168_guess = 0xf;
                break;
            }
            ((Action_guess*)sender)->Apply_guess(index, 1, 1);
            text += pStringTable->getString(0xc42, 0);
            AddOutputText_guess(text, 10);
        // 0x1CC-0x1CE: one value for all eight +0x218 settings (strings 0x179C-0x179E).
        } else if (id >= 0x1cc && id <= 0x1ce) {
            for (int i = 0; i < 8; i++) {
                pinstCChatManager_guess->fade_218_guess[i] = id - 0x1cc;
            }
            int string_id = -1;
            if (id == 0x1cc) {
                string_id = 0x179c;
            } else if (id == 0x1cd) {
                string_id = 0x179d;
            } else if (id == 0x1ce) {
                string_id = 0x179e;
            }
            AddOutputText_guess(pStringTable->getString(string_id, 0), 10);
        // 400-0x1C4: per-category value 0-2 for six categories, printed with its name.
        } else if (id >= 400 && id <= 0x1c4) {
            int string_id = -1;
            int value_id = -1;
            switch (id) {
            case 400:
                pinstCChatManager_guess->fade_218_guess[0] = 0;
                string_id = 0x3aba;
                value_id = 0x3aa6;
                break;
            case 0x191:
                pinstCChatManager_guess->fade_218_guess[0] = 1;
                string_id = 0x3abb;
                value_id = 0x3aa6;
                break;
            case 0x192:
                pinstCChatManager_guess->fade_218_guess[0] = 2;
                string_id = 0x3abc;
                value_id = 0x3aa6;
                break;
            case 0x19a:
                pinstCChatManager_guess->fade_218_guess[1] = 0;
                string_id = 0x3aba;
                value_id = 0x3aa7;
                break;
            case 0x19b:
                pinstCChatManager_guess->fade_218_guess[1] = 1;
                string_id = 0x3abb;
                value_id = 0x3aa7;
                break;
            case 0x19c:
                pinstCChatManager_guess->fade_218_guess[1] = 2;
                string_id = 0x3abd;
                value_id = 0x3aa7;
                break;
            case 0x1a4:
                pinstCChatManager_guess->fade_218_guess[2] = 0;
                string_id = 0x3aba;
                value_id = 0x3aa8;
                break;
            case 0x1a5:
                pinstCChatManager_guess->fade_218_guess[2] = 1;
                string_id = 0x3abb;
                value_id = 0x3aa8;
                break;
            case 0x1a6:
                pinstCChatManager_guess->fade_218_guess[2] = 2;
                string_id = 0x3abc;
                value_id = 0x3aa8;
                break;
            case 0x1ae:
                pinstCChatManager_guess->fade_218_guess[3] = 0;
                string_id = 0x3aba;
                value_id = 0x3aa9;
                break;
            case 0x1af:
                pinstCChatManager_guess->fade_218_guess[3] = 1;
                string_id = 0x3abb;
                value_id = 0x3aa9;
                break;
            case 0x1b0:
                pinstCChatManager_guess->fade_218_guess[3] = 2;
                string_id = 0x3abd;
                value_id = 0x3aa9;
                break;
            case 0x1b8:
                pinstCChatManager_guess->fade_218_guess[4] = 0;
                string_id = 0x3aba;
                value_id = 0x3aaa;
                break;
            case 0x1b9:
                pinstCChatManager_guess->fade_218_guess[4] = 1;
                string_id = 0x3abb;
                value_id = 0x3aaa;
                break;
            case 0x1ba:
                pinstCChatManager_guess->fade_218_guess[4] = 2;
                string_id = 0x3abc;
                value_id = 0x3aaa;
                break;
            case 0x1c2:
                pinstCChatManager_guess->fade_218_guess[5] = 0;
                string_id = 0x3aba;
                value_id = 0x3aab;
                break;
            case 0x1c3:
                pinstCChatManager_guess->fade_218_guess[5] = 1;
                string_id = 0x3abb;
                value_id = 0x3aab;
                break;
            case 0x1c4:
                pinstCChatManager_guess->fade_218_guess[5] = 2;
                string_id = 0x3abd;
                value_id = 0x3aab;
                break;
            }
            char line[0x100];
            sprintf(line, "%s %s", pStringTable->getString(value_id, 0),
                    pStringTable->getString(string_id, 0));
            pEverQuest->dsp_chat(line);
        // 500-749: types a command for the clicked menu text into the active window's input.
        } else if ((id > 499 && id < 0x226) || (id > 0x289 && id < 0x2ee) ||
                   (id > 0x225 && id < 0x28a)) {
            Object_guess* window = pinstCChatManager_guess->GetActiveChatWindow_guess();
            CXStr command = ((ContextMenu_guess*)sender)->GetItemText(index, 1);
            CXStrEx_guess& name = static_cast<CXStrEx_guess&>(command);
            char prefix = '/';
            if (strchr(name, '.') != 0) {
                if (name.CharAt_guess(0) == '.') {
                    name.Delete_guess(0, 1);
                }
                prefix = ';';
            }
            if (name.First_guess(0) == '[' || name.First_guess(0) == ';') {
                prefix = name.First_guess(0);
                name.Delete_guess(0, 1);
            }
            char line[0x100];
            sprintf(line, "%c%s %s ", prefix, pStringTable->getString(0x3696, 0) + 1, (char*)name);
            ((CXWnd*)window->widget_160)->SetFocus();
            ((VWnd_guess*)window->widget_160)->SetWindowText_guess(CXStr(line));
            g_global_guess->SetChatInputFocus_guess(0);
            return 0;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// Sets the output font to size `value` (+0x260) from the window manager's font list, then re-lays out the
// text and scrolls to the end.
// FUNCTION: TITANIUM 0x004F7FC6
void Object_guess::SetChatFont_guess(int value) {
    chatFont_0260_guess = value;
    if (widget_164 != 0) {
        Str_guess text = ((Object_guess*)widget_164)->GetSTMLText();
        Inner_guess* inner = g_root_guess->inner_guess;
        int slot = *inner->sub_f4_guess.At_guess(value);
        widget_164->Slot62_guess(slot);
        widget_164->SetSTMLText(text, 1, 0);
        widget_164->Reset_guess();
        int offset = widget_164->field_108_guess;
        widget_164->Slot64_guess(offset);
    }
}
