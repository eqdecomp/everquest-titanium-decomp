// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 226: a hint from compare/tumap.py.
// The ticket (petition) window, CTicketWindow (screen "TicketWindow"): knowledge-base search, new-ticket
// and open-ticket pages plus a help page. The *Owner_guess, CTicketWindow_guess, TicketView_guess and Holder_guess
// structs are views of it; topics come from a 1000-entry table at 0x985CF0. Its messages 0x7584, 0x2151
// and 0x5186 are not in EQEmu's Titanium list.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CTicketCommentWnd.h"

extern "C" unsigned int __cdecl strlen(const char* text_guess);
extern "C" int __cdecl strcmp(const char* first_guess, const char* second_guess);
// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
extern "C" int __cdecl _sprintf(char* destination_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060E3A3 _atol
extern "C" long __cdecl _atol(const char* text_guess);
// EXTERNAL: TITANIUM 0x0060E620 _strncpy
extern "C" char* __cdecl _strncpy(char* destination_guess, const char* source_guess, unsigned int count_guess);

#define g_text_guess EQ_ARRAY(char, 0x0063F53F)

struct TextTemp_guess;

struct Widget_guess {
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
    virtual void Invoke_guess();
    // EXTERNAL: TITANIUM 0x0059B9D0 Widget_guess::Prepare_guess
    void Prepare_guess(TextTemp_guess* text_guess, int first_guess, int second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x0059B360 Widget_guess::SetItem_guess
    void SetItem_guess(int row_guess, int column_guess, TextTemp_guess* text_guess);
    // EXTERNAL: TITANIUM 0x0059B3E0 Widget_guess::ClearItem_guess
    void ClearItem_guess(int row_guess, int column_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x00598580 Widget_guess::Refresh_guess
    void Refresh_guess();
};

struct Str_guess {
    int p_guess;
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    ~Str_guess();
};

struct Sink_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 Sink_guess::SetSTMLText
    void SetSTMLText(Str_guess text_guess, int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005AC2A0 Sink_guess::Append_guess
    void Append_guess(int* link_guess, Str_guess text_guess);
};

struct ToggleSink_guess {
    // EXTERNAL: TITANIUM 0x005BC840 ToggleSink_guess::Set_guess
    void Set_guess(int value_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x005BC4B0 ToggleSink_guess::Clear_guess
    void Clear_guess(int value_guess);
};

struct ToggleOwner_guess {
    char pad_0000_guess[0x160];
    ToggleSink_guess* sink_guess;  // 0x160
    char pad_0164_guess[0x46c];
    int value0_guess;  // 0x5d0
    int value1_guess;  // 0x5d4
    int value2_guess;  // 0x5d8
    char pad_05dc_guess[4];
    int saved0_guess;  // 0x5e0
    int saved1_guess;  // 0x5e4
    int saved2_guess;  // 0x5e8

    void Toggle_guess(char enabled_guess);
};

struct ItemRecord_guess {
    char name_guess[0x41];
    char label_guess[0x101];
    short percent_guess;
};

struct TimedTarget_guess {
    char pad_0000_guess[0x5d];
    char value_guess;  // 0x5d
};

struct TimedSource_guess {
    // EXTERNAL: TITANIUM 0x005A4CD0 TimedSource_guess::Get_guess
    char Get_guess();
    // EXTERNAL: TITANIUM 0x005A8C30 TimedSource_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x005A9060 TimedSource_guess::Set_guess
    void Set_guess(const CXStr& text_guess, int first_guess, int second_guess);
};

struct TimedOwner_guess {
    char pad_0000_guess[0x164];
    TimedSource_guess* source_guess;  // 0x164
    TimedTarget_guess* target_guess;  // 0x168
    char pad_016c_guess[0xc];
    int last_guess;  // 0x178

    // EXTERNAL: TITANIUM 0x0059DD30 TimedOwner_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 TimedOwner_guess::OnProcessFrame
    void OnProcessFrame();
    void OnProcessFrame_guess();
};

struct TimeGlobal_guess {
    char pad_0000_guess[0x148];
    int time_guess;  // 0x148
};

#define g_timeGlobal_guess EQ_GLOBAL(TimeGlobal_guess*, 0x00905D24)

struct TicketRecord_guess;

struct ActivateCell_guess;

struct Owner2_guess {
    char pad_0000_guess[0x594];
    ActivateCell_guess* kbNewTicketButton_guess;   // 0x594
    ActivateCell_guess* ntSubmitButton_guess;      // 0x598
    char pad_59c_guess[0x10];
    ActivateCell_guess* ntTopicCombobox_guess;     // 0x5ac
    ActivateCell_guess* ntSubtopicCombobox_guess;  // 0x5b0
    ActivateCell_guess* ntCommentsBox_guess;       // 0x5b4
    ActivateCell_guess* ntInstructionsBox_guess;   // 0x5b8
    ActivateCell_guess* ntBeginButton_guess;       // 0x5bc
    Widget_guess* widget_guess;
    char pad_5c4_guess[4];
    Sink_guess* receiver_guess;
    char pad_5cc_guess[0x20];
    char field_5ec_guess;  // 0x5ec
    char field_5ed_guess;  // 0x5ed
    char field_5ee_guess;
    char field_5ef_guess;  // 0x5ef

    void ClearKBResults_guess();
    void ClearKBArticle_guess();
    void ShowKBArticle_guess(char* text_guess);
    void ShowKBResults_guess(ItemRecord_guess* records_guess);

    void EnableNewTicket_guess(char enabled_guess);
    void ShowTicket_guess(struct TicketRecord_guess* record_guess);
    void ShowTicketThunk_guess(struct TicketRecord_guess* record_guess);
};

struct TicketUiOwner_guess {
    char pad_0000_guess[0x5c0];
    void* firstList_guess;
    void* secondList_guess;

    // EXTERNAL: TITANIUM 0x005A1EF0 TicketUiOwner_guess::LoadIniListWnd
    void LoadIniListWnd(void* list_guess, const char* name_guess);
    char LoadIniInfo_guess();
};

struct Owner_guess {
    char pad_0000_guess[0x5c4];
    Widget_guess* widget_guess;
    int field_5c8_guess;
    Sink_guess* receiver_guess;
    char pad_5d0_guess[0x1e];
    unsigned char flag_guess;

    void ClearTicketList_guess();
    void ClearTicketComments_guess();
    void ShowTicketDetail_guess();
};

struct FlagCell_guess {
    char pad_0000_guess[0x5d];
    char enabled_005d_guess;
};

struct FlagOwner_guess {
    char pad_0000_guess[0x59c];
    FlagCell_guess* first_guess;
    FlagCell_guess* second_guess;
    char pad_05a4_guess[0x48];
    char flag_guess;

    void EnableTicketButtons_guess(char enabled_guess);
};

struct FlagTargetOwner_guess {
    char pad_0000_guess[0x58c];
    FlagCell_guess* first_guess;
    FlagCell_guess* second_guess;
    char pad_0594_guess[0x10];
    FlagCell_guess* third_guess;
    char pad_05a8_guess[0x18];
    FlagCell_guess* fourth_guess;

    void EnableKBSearch_guess(char enabled_guess);
};

struct LocalText_guess {
    void* owner_guess;
    int enabled_guess;
    int zero_guess;
    Owner_guess* context_guess;
    LocalText_guess* self_guess;

    // EXTERNAL: TITANIUM 0x00571E00 LocalText_guess::SetText_guess
    void SetText_guess(const char* text_guess);
};

struct IndexedCallback_guess {
    // EXTERNAL: TITANIUM 0x005BC460 IndexedCallback_guess::Execute_guess
    void Execute_guess(int value_guess, int flag_guess);
};

struct IndexedOwner_guess {
    char pad_0000_guess[0x160];
    IndexedCallback_guess* callback_guess;
    char pad_0164_guess[0x478];
    int entries_guess[4];

    void ShowPage_guess(int index_guess);
};

struct SearchRecord_guess {
    char name_guess[0x100];
    int key_guess;
    int category_guess;
};

struct SearchKey_guess {
    int value_guess;
    char pad_0004_guess[0x104];
};

struct TicketTopicTable_guess {
    char pad_0000_guess[0xe9a8];
    union {
        SearchRecord_guess records_guess[1000];
        struct {
            char pad_0000_guess[0x100];
            SearchKey_guess keys_guess[1000];
        } lookup_guess;
    };
};

struct SearchStatus_guess {
    char pad_0000_guess;
    char active_guess;
};

#define g_ticketUiEnabled_guess EQ_GLOBAL(char, 0x00923D64)
#define g_searchStatus_guess EQ_GLOBAL(SearchStatus_guess*, 0x00985CF0)

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    int getString(int id_guess, int index_guess);
};

struct SearchOwner_guess {
    int GetTopicId_guess(const char* name_guess);
    int GetTopicName_guess(int key_guess);
};

struct SubCategoryList_guess;

struct SubCategoryOwner_guess {
    char pad_0000_guess[0x5ac];
    SubCategoryList_guess* source_guess;
    SubCategoryList_guess* list_guess;

    void FillSubtopics_guess();
    void ShowCategories_guess();
};

struct Payload_guess;

struct TextTemp_guess {
    struct Payload_guess* value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 TextTemp_guess::TextTemp_guess
    TextTemp_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 TextTemp_guess::Release_guess
    void Release_guess(Payload_guess* value_guess);
    // EXTERNAL: TITANIUM 0x00572300 TextTemp_guess::GetText_guess
    char* GetText_guess();
    ~TextTemp_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
        value_guess = 0;
    }
};

struct SubCategoryList_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 SubCategoryList_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 SubCategoryList_guess::Add_guess
    void Add_guess(const TextTemp_guess& text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 SubCategoryList_guess::Finish_guess
    void Finish_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0059C3B0 SubCategoryList_guess::Get_guess
    TextTemp_guess Get_guess();
};

struct Payload_guess {
    char pad_0000_guess[8];
    int count_guess;
};

struct Packet_guess {
    int type_guess;
    long value_guess;
    char text_guess[0xfa1];
};

struct NetworkContext_guess {
    char pad_0000_guess[0x11c];
    int count_guess;

    bool HasCount_guess() {
        return count_guess > 0;
    }

    // EXTERNAL: TITANIUM 0x00597F10 NetworkContext_guess::BuildText_guess
    TextTemp_guess BuildText_guess(int first_guess, int second_guess);
};

struct NetworkOwner_guess {
    char pad_0000_guess[0x5c4];
    NetworkContext_guess* context_guess;

    void AddComment_guess(TextTemp_guess text_guess);
};

#define g_networkGlobal_guess EQ_ARRAY(int, 0x00905CA0)

struct TextSink_guess {
    // EXTERNAL: TITANIUM 0x005A9060 TextSink_guess::Set_guess
    void Set_guess(TextTemp_guess& text_guess, int first_guess, int second_guess);
};

struct TextOwner_guess {
    char pad_0000_guess[0x164];
    TextSink_guess* sink_guess;
    char pad_0168_guess[0x14];
    char value_17c_guess;

    void ShowHelpPage_guess(const char* text_guess);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyByte_guess
void __cdecl CopyByte_guess(char* destination_guess, const char* source_guess);

#define g_searchData_guess EQ_GLOBAL(TicketTopicTable_guess*, 0x00985CF0)
#define g_stringTable_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

// Inserts the knowledge-base, new-ticket and open-tickets pages into the tab box, or removes them.
// FUNCTION: TITANIUM 0x0056115A
void ToggleOwner_guess::Toggle_guess(char enabled_guess) {
    if (enabled_guess != 0) {
        saved0_guess = value0_guess;
        saved1_guess = value1_guess;
        saved2_guess = value2_guess;
        sink_guess->Set_guess(value0_guess, -1);
        sink_guess->Set_guess(value1_guess, -1);
        sink_guess->Set_guess(value2_guess, -1);
    } else {
        saved0_guess = 0;
        saved1_guess = 0;
        saved2_guess = 0;
        sink_guess->Clear_guess(value2_guess);
        sink_guess->Clear_guess(value1_guess);
        sink_guess->Clear_guess(value0_guess);
    }
}

// LoadIniInfo override: with the ticket UI on (0x923D64), restores both lists and, unless the topic
// table is loaded, requests it (message 0x7584). Its 4-byte payload is a local that is never set.
// FUNCTION: TITANIUM 0x00561204
char TicketUiOwner_guess::LoadIniInfo_guess() {
    if (g_ticketUiEnabled_guess != 0) {
        LoadIniListWnd(firstList_guess, "TicketWndKBResultsList");
        LoadIniListWnd(secondList_guess, "TicketWndOTTicketList");
        if (g_searchStatus_guess->active_guess == 0) {
            int request_guess;
            EQSendMessage(g_networkGlobal_guess, 0x7584, (Packet_guess*)&request_guess, 4, 1);
        }
    }
    return 1;
}

// OnProcessFrame: every 250 ms enables the help Back button when the help page can go back.
// FUNCTION: TITANIUM 0x00561290
void TimedOwner_guess::OnProcessFrame_guess() {
    if (Check_guess()) {
        int now_guess = g_timeGlobal_guess->time_guess;
        if (now_guess - last_guess > 250) {
            if (target_guess != 0 && source_guess != 0) {
                target_guess->value_guess = source_guess->Get_guess();
            }
            last_guess = now_guess;
        }
    }
    return OnProcessFrame();
}

// Shows page `index_guess`: 0 help, 1 knowledge base, 2 new ticket, 3 open tickets.
// FUNCTION: TITANIUM 0x005612E7
void IndexedOwner_guess::ShowPage_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < 4) {
        int value_guess = entries_guess[index_guess];
        if (value_guess != 0) {
            callback_guess->Execute_guess(value_guess, 1);
        }
    }
}

// Remembers help page `text_guess` (+0x17C, 1 KB) and hands it to HPDisplay, probably to load it.
// FUNCTION: TITANIUM 0x00561310
void TextOwner_guess::ShowHelpPage_guess(const char* text_guess) {
    CopyByte_guess(&value_17c_guess, text_guess);
    if (sink_guess != 0) {
        TextTemp_guess text_copy_guess(text_guess);
        sink_guess->Set_guess(text_copy_guess, 0, 0);
    }
}

// Adds comment `text_guess` to the selected open ticket (message 0x2151, 0xFAC bytes: ticket id from
// column 0, up to 4000 characters). The first word of the packet is never set.
// FUNCTION: TITANIUM 0x0056137C
// @early-stop: budget, structural ndiff=9
void NetworkOwner_guess::AddComment_guess(TextTemp_guess text_guess) {
    if (context_guess->count_guess > 0) {
        int count_guess = 0;
        if (text_guess.value_guess != 0) {
            count_guess = text_guess.value_guess->count_guess;
        }
        if (count_guess > 0) {
            Packet_guess packet_guess;
            {
                packet_guess.value_guess = _atol(context_guess->BuildText_guess(0, 0).GetText_guess());
            }
            _strncpy(packet_guess.text_guess, text_guess.GetText_guess(), 0xfa1);
            EQSendMessage(g_networkGlobal_guess, 0x2151, &packet_guess, 0xfac, 1);
        }
    }
}

// Empties the KB results list.
// FUNCTION: TITANIUM 0x0056146F
void Owner2_guess::ClearKBResults_guess() {
    if (widget_guess != 0) {
        widget_guess->Refresh_guess();
        widget_guess->Invoke_guess();
    }
}

// Clears the KB article box.
// FUNCTION: TITANIUM 0x0056148E
void Owner2_guess::ClearKBArticle_guess() {
    if (receiver_guess != 0) {
        receiver_guess->SetSTMLText(g_text_guess, 1, 0);
    }
}

// Empties the open-ticket list.
// FUNCTION: TITANIUM 0x005614BE
void Owner_guess::ClearTicketList_guess() {
    if (widget_guess != 0) {
        widget_guess->Refresh_guess();
        widget_guess->Invoke_guess();
    }
}

// Clears the open-ticket comments box.
// FUNCTION: TITANIUM 0x005614DD
void Owner_guess::ClearTicketComments_guess() {
    if (receiver_guess != 0) {
        receiver_guess->SetSTMLText(g_text_guess, 1, 0);
    }
}

// The next ticket shown includes its original text (+0x5EE).
// FUNCTION: TITANIUM 0x0056150D
void Owner_guess::ShowTicketDetail_guess() {
    flag_guess = 1;
}

// Enables Delete and Add Comment (+0x59C, +0x5A0) if `enabled_guess` and a ticket is shown.
// FUNCTION: TITANIUM 0x005616DE
void FlagOwner_guess::EnableTicketButtons_guess(char enabled_guess) {
    if (first_guess != 0) {
        first_guess->enabled_005d_guess = enabled_guess != 0 && flag_guess != 0;
    }
    if (second_guess != 0) {
        second_guess->enabled_005d_guess = enabled_guess != 0 && flag_guess != 0;
    }
}

// Enables the KB search controls. kbStringInput (+0x5A4) is set twice and kbArticleInput (+0x5A8)
// never: an original slip, kept for the match. The last one is the results list.
// FUNCTION: TITANIUM 0x00561727
void FlagTargetOwner_guess::EnableKBSearch_guess(char enabled_guess) {
    if (first_guess != 0) {
        first_guess->enabled_005d_guess = enabled_guess;
    }
    if (second_guess != 0) {
        second_guess->enabled_005d_guess = enabled_guess;
    }
    if (third_guess != 0) {
        third_guess->enabled_005d_guess = enabled_guess;
    }
    if (third_guess != 0) {
        third_guess->enabled_005d_guess = enabled_guess;
    }
    if (fourth_guess != 0) {
        fourth_guess->enabled_005d_guess = enabled_guess;
    }
}

// Fills the subtopic combo with the topics under the selected topic.
// FUNCTION: TITANIUM 0x00561B34
void SubCategoryOwner_guess::FillSubtopics_guess() {
    if (list_guess != 0) {
        int count_guess = 1;
        list_guess->Reset_guess();
        TextTemp_guess current_guess = source_guess->Get_guess();
        int selected_guess = -1;
        {
            TextTemp_guess prompt_guess("Select Sub-Category");
            list_guess->Add_guess(prompt_guess);
        }
        for (int index_guess = 0; index_guess < 1000; ++index_guess) {
            if (g_searchData_guess->records_guess[index_guess].key_guess != 0) {
                if (strcmp(current_guess.GetText_guess(), g_searchData_guess->records_guess[index_guess].name_guess) == 0) {
                    selected_guess = g_searchData_guess->records_guess[index_guess].key_guess;
                }
                if (g_searchData_guess->records_guess[index_guess].category_guess == selected_guess) {
                    {
                        const TextTemp_guess& label_guess = TextTemp_guess(g_searchData_guess->records_guess[index_guess].name_guess);
                        list_guess->Add_guess(label_guess);
                    }
                    ++count_guess;
                }
            }
        }
        if (count_guess > 0) {
            list_guess->Finish_guess(0);
        }
    }
}

// Topic id by name, 0 if none. Walks the topic table; the Mac match BadWord is probably a look-alike.
// FUNCTION: TITANIUM 0x00561C72
int SearchOwner_guess::GetTopicId_guess(const char* name_guess) {
    if (name_guess != 0 && strlen(name_guess) != 0) {
        for (int index_guess = 0; index_guess < 1000; ++index_guess) {
            if (strcmp(g_searchData_guess->records_guess[index_guess].name_guess, name_guess) == 0) {
                return g_searchData_guess->records_guess[index_guess].key_guess;
            }
        }
    }
    return 0;
}

// Topic name by id, else string 0x2299.
// FUNCTION: TITANIUM 0x00561CD0
int SearchOwner_guess::GetTopicName_guess(int key_guess) {
    if (key_guess != 0) {
        TicketTopicTable_guess* data_guess = g_searchData_guess;
        int index_guess = 0;
        SearchKey_guess* current_guess = data_guess->lookup_guess.keys_guess;
        do {
            if (current_guess->value_guess == key_guess) {
                return (int)&data_guess->records_guess[index_guess];
            }
            ++index_guess;
            ++current_guess;
        } while (index_guess < 1000);
    }
    return g_stringTable_guess->getString(0x2299, 0);
}

struct PacketHead_guess {
    int type_guess;
    long value_guess;
};

struct ConfigOwner_guess {
    char pad_0000_guess[0x468];
    NetworkContext_guess* context_guess;  // 0x468
    char pad_046c_guess[4];
    Sink_guess* receiver_guess;  // 0x470

    void OnDeleteConfirm_guess(int first_guess, int flags_guess, int second_guess);
};

// Enclosing object: ConfigOwner sits 0x15c bytes into it.
struct ConfigLead_guess {
    char pad_0000_guess[0x15c];
};

struct ConfigHost_guess : ConfigLead_guess, ConfigOwner_guess {
};

// Delete-confirmation result (`this` is the notifier base at +0x15C): on OK or Yes sends message 0x5186
// with the selected ticket id, disables Delete and Add Comment and shows string 0x2290.
// FUNCTION: TITANIUM 0x00561A72
void ConfigOwner_guess::OnDeleteConfirm_guess(int first_guess, int flags_guess, int second_guess) {
    if ((flags_guess & 5) != 0) {
        PacketHead_guess packet_guess;
        {
            packet_guess.value_guess = _atol(context_guess->BuildText_guess(0, 0).GetText_guess());
        }
        EQSendMessage(g_networkGlobal_guess, 0x5186, reinterpret_cast<Packet_guess*>(&packet_guess), 8, 1);
        reinterpret_cast<FlagOwner_guess*>(static_cast<ConfigHost_guess*>(this))->EnableTicketButtons_guess(0);
        if (receiver_guess != 0) {
            receiver_guess->SetSTMLText(Str_guess(reinterpret_cast<const char*>(g_stringTable_guess->getString(0x2290, 0))), 1, 0);
        }
    }
}

// Shows up to 20 KB search hits (match %, title, +0x41 text) and string 0x2293, or 0x2281 for none.
// FUNCTION: TITANIUM 0x00562FED
// @early-stop: budget, structural ndiff=33
void Owner2_guess::ShowKBResults_guess(ItemRecord_guess* records_guess) {
    ItemRecord_guess* record_guess = records_guess;
    int zero_guess = 0;
    ClearKBResults_guess();
    if (record_guess != 0) {
        ClearKBArticle_guess();
        if (widget_guess != 0) {
            int active_count_guess = zero_guess;
            for (int index_guess = zero_guess; index_guess < 20; ++index_guess, ++record_guess) {
                if (record_guess->name_guess[0] != zero_guess) {
                    ++active_count_guess;
                    {
                        TextTemp_guess empty_guess(g_text_guess);
                        widget_guess->Prepare_guess(&empty_guess, -1, zero_guess, zero_guess);
                    }
                    char percent_text_guess[16];
                    _sprintf(percent_text_guess, "%d%%", record_guess->percent_guess);
                    {
                        TextTemp_guess percent_guess(percent_text_guess);
                        widget_guess->SetItem_guess(index_guess, zero_guess, &percent_guess);
                    }
                    widget_guess->ClearItem_guess(index_guess, zero_guess, -1);
                    {
                        TextTemp_guess label_guess(record_guess->name_guess);
                        widget_guess->SetItem_guess(index_guess, 1, &label_guess);
                    }
                    widget_guess->ClearItem_guess(index_guess, 1, -1);
                    {
                        TextTemp_guess label_guess(record_guess->label_guess);
                        widget_guess->SetItem_guess(index_guess, 2, &label_guess);
                    }
                    widget_guess->ClearItem_guess(index_guess, 2, -1);
                }
            }
            receiver_guess->SetSTMLText(
                (const char*)g_stringTable_guess->getString(
                    active_count_guess == zero_guess ? 0x2281 : 0x2293, zero_guess),
                1, 0);
        }
        ((FlagTargetOwner_guess*)this)->EnableKBSearch_guess(1);
    }
}

// Shows a KB article: title in yellow and body (+0xFF), or string 0x2282 if empty; then lets the player
// open a new ticket unless one is shown.
// FUNCTION: TITANIUM 0x005631F4
void Owner2_guess::ShowKBArticle_guess(char* text_guess) {
    int link_guess[2];
    ClearKBArticle_guess();
    if (text_guess == 0 || (text_guess[0] == 0 && text_guess[0xff] == 0)) {
        receiver_guess->Append_guess(link_guess, pStringTable->getString(0x2282, 0));
    } else {
        receiver_guess->Append_guess(link_guess, "<c \"#ffff00\">");
        receiver_guess->Append_guess(link_guess, text_guess);
        receiver_guess->Append_guess(link_guess, "</c><br><br><c \"#ffffff\">");
        receiver_guess->Append_guess(link_guess, text_guess + 0xff);
        receiver_guess->Append_guess(link_guess, "</c>");
    }
    field_5ed_guess = 1;
    ((FlagTargetOwner_guess*)this)->EnableKBSearch_guess(1);
    if (field_5ec_guess == 0) {
        EnableNewTicket_guess(1);
    }
}

// Fills the topic combo with the top-level topics (category 0), then the subtopics.
// FUNCTION: TITANIUM 0x005632FB
void SubCategoryOwner_guess::ShowCategories_guess() {
    int zero_guess = 0;
    int count_guess;
    if (source_guess != 0) {
        count_guess = 1;
        source_guess->Reset_guess();
        {
            TextTemp_guess prompt_guess("Select Category");
            source_guess->Add_guess(prompt_guess);
        }
        for (int index_guess = 0; index_guess < 1000; ++index_guess) {
            if (g_searchData_guess->records_guess[index_guess].key_guess != zero_guess &&
                g_searchData_guess->records_guess[index_guess].category_guess == zero_guess) {
                {
                    TextTemp_guess label_guess(g_searchData_guess->records_guess[index_guess].name_guess);
                    source_guess->Add_guess(label_guess);
                }
                ++count_guess;
            }
        }
        if (count_guess > zero_guess) {
            source_guess->Finish_guess(0);
            FillSubtopics_guess();
        }
    }
}

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int count_guess);

struct TicketPiece_guess {
    char pad_000_guess[0x60];
    unsigned int style_060_guess;
};

struct TicketBase_guess {
    char pad_004_guess[0x60];
    unsigned int windowStyle_064_guess;
    char pad_068_guess[0x124 - 0x68];
    TicketPiece_guess* sidlPiece_124_guess;
    char pad_128_guess[0x15c - 0x128];
    // EXTERNAL: TITANIUM 0x005A3850 ??0TicketBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    TicketBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int iniVersion_guess,
                     char* blockName_guess);
    // EXTERNAL: TITANIUM 0x005A3100 TicketBase_guess::~TicketBase_guess
    virtual ~TicketBase_guess();
    // EXTERNAL: TITANIUM 0x0059DD20 TicketBase_guess::Finish_guess
    void Finish_guess();
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7TicketNotifier_guess@@6B@
struct TicketNotifier_guess {
    // EXTERNAL: TITANIUM 0x005482A0 TicketNotifier_guess::Reset_guess
    void Reset_guess(int value_guess);
    virtual void Slot00_guess();
    virtual ~TicketNotifier_guess() {
        Reset_guess(-1);
    }
};

struct TicketChild_guess {
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
    virtual int FillSubtopics_guess(bool show_guess, bool flag_guess);
};

struct TicketList_guess : CListWnd {
    char pad_140_guess[0x15c - 0x140];
    unsigned char flag_15c_guess;
    char pad_15d_guess[0x16c - 0x15d];
    unsigned int color_16c_guess;
};

struct TicketEdit_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x004D7EBC TicketEdit_guess::SetMaxChars_guess
    void SetMaxChars_guess(int count_guess);
};

#define g_ticketPagesInline_guess EQ_GLOBAL(char, 0x00923D64)

// EXTERNAL: TITANIUM 0x0065E6B8 ??_7CTicketWindow_guess@@6BTicketBase_guess@@@
// EXTERNAL: TITANIUM 0x0065E6B4 ??_7CTicketWindow_guess@@6BTicketNotifier_guess@@@
struct CTicketWindow_guess : TicketBase_guess, TicketNotifier_guess {
    ToggleSink_guess* subwindows_160_guess;
    CXWnd* hpDisplay_164_guess;
    CXWnd* hpBackButton_168_guess;
    CXWnd* hpContents_16c_guess;
    CXWnd* hpTipsButton_170_guess;
    CXStr text_174_guess;
    int field_178_guess;
    char text_17c_guess[0x400];
    CXWnd* helpPage_57c_guess;
    CXWnd* kbDoneButton_580_guess;
    CXWnd* ntDoneButton_584_guess;
    CXWnd* otDoneButton_588_guess;
    CXWnd* kbStringSearchButton_58c_guess;
    CXWnd* kbArticleSearchButton_590_guess;
    CXWnd* kbNewTicketButton_594_guess;
    TicketChild_guess* ntSubmitButton_598_guess;
    CXWnd* otDeleteButton_59c_guess;
    CXWnd* otAddCommentButton_5a0_guess;
    CXWnd* kbStringInput_5a4_guess;
    CXWnd* kbArticleInput_5a8_guess;
    CXWnd* ntTopicCombobox_5ac_guess;
    CXWnd* ntSubtopicCombobox_5b0_guess;
    TicketEdit_guess* ntCommentsBox_5b4_guess;
    TicketChild_guess* ntInstructionsBox_5b8_guess;
    CXWnd* ntBeginButton_5bc_guess;
    TicketList_guess* kbResultsList_5c0_guess;
    TicketList_guess* otTicketList_5c4_guess;
    CXWnd* kbArticleBox_5c8_guess;
    CXWnd* otCommentsBox_5cc_guess;
    CXWnd* kbPage_5d0_guess;
    CXWnd* ntPage_5d4_guess;
    CXWnd* otPage_5d8_guess;
    CXWnd* pages_5dc_guess[4];
    char flag_5ec_guess;
    char flag_5ed_guess;
    char flag_5ee_guess;
    char flag_5ef_guess;

    bool StoreIniInfo_guess();
    // EXTERNAL: TITANIUM 0x005A1FE0 CTicketWindow_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(TicketList_guess* list_guess, const char* name_guess);
    CTicketWindow_guess(CXWnd* parent_guess);
    ~CTicketWindow_guess();
};

// StoreIniInfo side: saves both lists' columns.
// FUNCTION: TITANIUM 0x0056125E
bool CTicketWindow_guess::StoreIniInfo_guess() {
    if (g_ticketPagesInline_guess != 0) {
        StoreIniListWnd_guess(kbResultsList_5c0_guess, "TicketWndKBResultsList");
        StoreIniListWnd_guess(otTicketList_5c4_guess, "TicketWndOTTicketList");
    }
    return true;
}

// The window's ctor. The pages are tabs only with the ticket UI on (0x923D64); else they are removed.
// FUNCTION: TITANIUM 0x005633E9
CTicketWindow_guess::CTicketWindow_guess(CXWnd* parent_guess)
    : TicketBase_guess(parent_guess, "TicketWindow", 0xfffffdff, 1, 0), subwindows_160_guess(0) {
    kbDoneButton_580_guess = 0;
    ntDoneButton_584_guess = 0;
    otDoneButton_588_guess = 0;
    kbStringSearchButton_58c_guess = 0;
    kbArticleSearchButton_590_guess = 0;
    kbNewTicketButton_594_guess = 0;
    ntSubmitButton_598_guess = 0;
    otDeleteButton_59c_guess = 0;
    otAddCommentButton_5a0_guess = 0;
    kbStringInput_5a4_guess = 0;
    kbArticleInput_5a8_guess = 0;
    ntTopicCombobox_5ac_guess = 0;
    ntSubtopicCombobox_5b0_guess = 0;
    kbResultsList_5c0_guess = 0;
    otTicketList_5c4_guess = 0;
    kbArticleBox_5c8_guess = 0;
    ntCommentsBox_5b4_guess = 0;
    ntInstructionsBox_5b8_guess = 0;
    otCommentsBox_5cc_guess = 0;
    hpDisplay_164_guess = 0;
    hpBackButton_168_guess = 0;
    hpContents_16c_guess = 0;
    hpTipsButton_170_guess = 0;
    for (int page_guess = 0; page_guess < 4; ++page_guess) {
        pages_5dc_guess[page_guess] = 0;
    }
    if (sidlPiece_124_guess != 0) {
        windowStyle_064_guess |= sidlPiece_124_guess->style_060_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        subwindows_160_guess = (ToggleSink_guess*)((CSidlScreenWnd*)this)->GetChildItem("TicketWindow_Subwindows");
        kbPage_5d0_guess = ((CSidlScreenWnd*)this)->GetChildItem("KnowledgeBasePage");
        if (kbPage_5d0_guess != 0) {
            kbDoneButton_580_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBDoneButton");
            kbStringSearchButton_58c_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBStringSearchButton");
            kbArticleSearchButton_590_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBArticleSearchButton");
            kbNewTicketButton_594_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBNewTicketButton");
            kbStringInput_5a4_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBStringInput");
            kbArticleInput_5a8_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBArticleInput");
            kbResultsList_5c0_guess = (TicketList_guess*)((CSidlScreenWnd*)this)->GetChildItem("TW_KBResultsList");
            kbArticleBox_5c8_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_KBArticleBox");
            if (kbNewTicketButton_594_guess != 0) {
                kbNewTicketButton_594_guess->Enabled = 0;
            }
            if (kbResultsList_5c0_guess != 0) {
                kbResultsList_5c0_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
                kbResultsList_5c0_guess->color_16c_guess = 0xff8aa3ff;
                kbResultsList_5c0_guess->flag_15c_guess = 1;
                kbResultsList_5c0_guess->SetColumnJustification(0, 1);
                kbResultsList_5c0_guess->SetColumnJustification(1, 1);
                kbResultsList_5c0_guess->SetColumnJustification(2, 0);
            }
            if (g_ticketPagesInline_guess != 0) {
                pages_5dc_guess[1] = kbPage_5d0_guess;
            } else {
                subwindows_160_guess->Clear_guess((int)kbPage_5d0_guess);
            }
        }
        ntPage_5d4_guess = ((CSidlScreenWnd*)this)->GetChildItem("NewTicketPage");
        if (ntPage_5d4_guess != 0) {
            ntDoneButton_584_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_NTDoneButton");
            ntSubmitButton_598_guess = (TicketChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("TW_NTSubmitButton");
            ntSubmitButton_598_guess->FillSubtopics_guess(0, 1);
            ntTopicCombobox_5ac_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_NTTopicCombobox");
            if (ntTopicCombobox_5ac_guess != 0) {
                ((SubCategoryOwner_guess*)this)->ShowCategories_guess();
            }
            if (ntSubtopicCombobox_5b0_guess != 0) {
                ((SubCategoryOwner_guess*)this)->FillSubtopics_guess();
            }
            // Assigned only now; the fills above ran while it was 0, so the subtopic combo starts empty.
            ntSubtopicCombobox_5b0_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_NTSubtopicCombobox");
            ntCommentsBox_5b4_guess = (TicketEdit_guess*)((CSidlScreenWnd*)this)->GetChildItem("TW_NTCommentsBox");
            if (ntCommentsBox_5b4_guess != 0) {
                // The comment size message 0x2151 carries.
                ntCommentsBox_5b4_guess->SetMaxChars_guess(4000);
            }
            ntInstructionsBox_5b8_guess =
                (TicketChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("TW_NTInstructionsBox");
            if (ntInstructionsBox_5b8_guess != 0) {
                ((CStmlWnd*)ntInstructionsBox_5b8_guess)->SetSTMLText(pStringTable->getString(0x229a, 0), 1, 0);
                ntInstructionsBox_5b8_guess->FillSubtopics_guess(0, 1);
            }
            ntBeginButton_5bc_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_NTBeginButton");
            ((Owner2_guess*)this)->EnableNewTicket_guess(0);
            if (g_ticketPagesInline_guess != 0) {
                pages_5dc_guess[2] = ntPage_5d4_guess;
            } else {
                subwindows_160_guess->Clear_guess((int)ntPage_5d4_guess);
            }
        }
        otPage_5d8_guess = ((CSidlScreenWnd*)this)->GetChildItem("OpenTicketsPage");
        if (otPage_5d8_guess != 0) {
            otDoneButton_588_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_OTDoneButton");
            otDeleteButton_59c_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_OTDeleteButton");
            otAddCommentButton_5a0_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_OTAddCommentButton");
            otTicketList_5c4_guess = (TicketList_guess*)((CSidlScreenWnd*)this)->GetChildItem("TW_OTTicketList");
            otCommentsBox_5cc_guess = ((CSidlScreenWnd*)this)->GetChildItem("TW_OTCommentsBox");
            if (otTicketList_5c4_guess != 0) {
                otTicketList_5c4_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
                otTicketList_5c4_guess->color_16c_guess = 0xff8aa3ff;
                otTicketList_5c4_guess->flag_15c_guess = 1;
                otTicketList_5c4_guess->SetColumnJustification(0, 1);
                otTicketList_5c4_guess->SetColumnJustification(1, 1);
                otTicketList_5c4_guess->SetColumnJustification(2, 1);
                otTicketList_5c4_guess->SetColumnJustification(3, 1);
                otTicketList_5c4_guess->SetColumnJustification(4, 1);
            }
            if (g_ticketPagesInline_guess != 0) {
                pages_5dc_guess[3] = otPage_5d8_guess;
            } else {
                subwindows_160_guess->Clear_guess((int)otPage_5d8_guess);
            }
        }
        helpPage_57c_guess = ((CSidlScreenWnd*)this)->GetChildItem("HelpPage");
        pages_5dc_guess[0] = helpPage_57c_guess;
        if (helpPage_57c_guess != 0) {
            hpDisplay_164_guess = ((CSidlScreenWnd*)this)->GetChildItem("HPDisplay");
            hpBackButton_168_guess = ((CSidlScreenWnd*)this)->GetChildItem("HPBackButton");
            hpContents_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("HPContents");
            hpTipsButton_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("HPTipsButton");
            if (hpBackButton_168_guess != 0) {
                hpBackButton_168_guess->Enabled = 0;
            }
        }
        text_17c_guess[0] = 0;
        field_178_guess = 0;
        flag_5ec_guess = 0;
        flag_5ed_guess = 0;
        flag_5ee_guess = 0;
        flag_5ef_guess = 0;
        Finish_guess();
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct HolderBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1HolderBase_guess@@QAE@XZ
    ~HolderBase_guess();
    char pad_000_guess[0x15c];
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7HolderNotifier_guess@@6B@
struct HolderNotifier_guess {
    virtual void Slot00_guess();
    ~HolderNotifier_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 HolderNotifier_guess::Reset_guess
    void Reset_guess(int value_guess);
    char pad_004_guess[0x14];
};

struct HolderLink_guess {
    HolderNotifier_guess notifier_guess;
};

struct Holder_guess : HolderBase_guess, HolderLink_guess {
    CXStr text_174_guess;
    ~Holder_guess();
    void* Delete_guess(unsigned char flags_guess);
};

// CTicketWindow's deleting dtor; 0x563DCB is the dtor (notifier at +0x15C, CXStr at +0x174).
// FUNCTION: TITANIUM 0x00563DAF
void* Holder_guess::Delete_guess(unsigned char flags_guess) {
    this->Holder_guess::~Holder_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the GM ticket window (vtable 0x65E6B8): destroys the string at +0x174, expires every
// confirmation dialog its dialog-owner part (+0x15C) opened (0x005482A0, all messages), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00563DCB
Holder_guess::~Holder_guess() {
}

// EXTERNAL: TITANIUM 0x00612227 localtime
extern "C" struct tm* __cdecl localtime(const long* time_guess);
// EXTERNAL: TITANIUM 0x00612DC0 asctime
extern "C" char* __cdecl asctime(const struct tm* time_guess);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* text_guess, int radix_guess);

#define g_ticketSpacer_guess EQ_ARRAY(char, 0x00656A94)

struct TicketEntry_guess {
    int id_guess;                // 0x00
    char pad_004_guess[0xc];
    __int64 time_guess;          // 0x10
    char comment_guess[0xfa1];   // 0x18
    char author_guess[0x47];     // 0xfb9
};

struct TicketRecord_guess {
    int id_guess;                // 0x00
    char pad_004_guess[4];
    __int64 created_guess;       // 0x08
    __int64 updated_guess;       // 0x10
    char subject_guess[0x44];    // 0x18
    int topic_guess;             // 0x5c
    int subtopic_guess;          // 0x60
    int status_guess;            // 0x64
    char text_guess[0xfa8];      // 0x68
    TicketEntry_guess entries_guess[10];  // 0x1010
};

struct StmlPos_guess {
    int x_guess;
    int y_guess;
    StmlPos_guess(const StmlPos_guess& other_guess);
};

struct TicketStml_guess {
    // EXTERNAL: TITANIUM 0x005AC2A0 TicketStml_guess::Append_guess
    StmlPos_guess Append_guess(CXStr text_guess);
};


struct TicketView_guess {
    char pad_000_guess[0x160];
    IndexedCallback_guess* subwindows_guess;  // 0x160
    char pad_164_guess[0x5a0 - 0x164];
    FlagCell_guess* addComment_guess;         // 0x5a0
    char pad_5a4_guess[0x5c4 - 0x5a4];
    Widget_guess* list_guess;                 // 0x5c4
    int pad_5c8_guess;
    TicketStml_guess* comments_guess;         // 0x5cc
    int kbPage_guess;                         // 0x5d0
    int ntPage_guess;                         // 0x5d4
    int otPage_guess;                         // 0x5d8
    char pad_5dc_guess[0x10];
    char shown_guess;                         // 0x5ec
    char field_5ed_guess;                     // 0x5ed
    char detail_guess;                        // 0x5ee
};

// Shows ticket `record_guess` on the open-tickets page: one row (id, last update, subject, topic/subtopic,
// status), the original text if +0x5EE, then up to 10 comments, oldest first. No ticket: back to the KB
// page with string 0x2280.
// FUNCTION: TITANIUM 0x00562710
// @early-stop: budget, diff ndiff=28
void Owner2_guess::ShowTicket_guess(TicketRecord_guess* record_guess) {
    TicketView_guess* view_guess = (TicketView_guess*)this;
    int other_guess;
    char id_text_guess[16];
    char status_text_guess[16];
    char number_guess[16];
    char topic_text_guess[64];
    char time_text_guess[64];
    char subject_text_guess[64];
    if (record_guess != 0 && record_guess->id_guess != 0) {
        ((Owner_guess*)this)->ClearTicketList_guess();
        ((Owner_guess*)this)->ClearTicketComments_guess();
        if (view_guess->list_guess != 0) {
            {
                TextTemp_guess empty_guess(g_text_guess);
                view_guess->list_guess->Prepare_guess(&empty_guess, -1, 0, 0);
            }
            _sprintf(id_text_guess, "%d", record_guess->id_guess);
            {
                TextTemp_guess text_guess(id_text_guess);
                view_guess->list_guess->SetItem_guess(0, 0, &text_guess);
            }
            view_guess->list_guess->ClearItem_guess(0, 0, -1);
            _sprintf(time_text_guess, "%s", asctime(localtime((long*)&record_guess->updated_guess)));
            {
                TextTemp_guess text_guess(time_text_guess);
                view_guess->list_guess->SetItem_guess(0, 1, &text_guess);
            }
            view_guess->list_guess->ClearItem_guess(0, 1, -1);
            _strncpy(subject_text_guess, record_guess->subject_guess, 0x40);
            {
                TextTemp_guess text_guess(subject_text_guess);
                view_guess->list_guess->SetItem_guess(0, 2, &text_guess);
            }
            view_guess->list_guess->ClearItem_guess(0, 2, -1);
            _sprintf(topic_text_guess, "%s/%s", ((SearchOwner_guess*)this)->GetTopicName_guess(record_guess->topic_guess),
                     ((SearchOwner_guess*)this)->GetTopicName_guess(record_guess->subtopic_guess));
            {
                TextTemp_guess text_guess(topic_text_guess);
                view_guess->list_guess->SetItem_guess(0, 3, &text_guess);
            }
            view_guess->list_guess->ClearItem_guess(0, 3, -1);
            int status_guess = record_guess->status_guess;
            char* status_name_guess;
            if (status_guess == 0) {
                status_name_guess = pStringTable->getString(0x227a, 0);
            } else if (status_guess == 2) {
                status_name_guess = pStringTable->getString(0x2296, 0);
            } else if (status_guess == 3) {
                status_name_guess = pStringTable->getString(0x2297, 0);
            } else if (status_guess == 4) {
                status_name_guess = pStringTable->getString(0x2298, 0);
            } else {
                status_name_guess = pStringTable->getString(0x227c, 0);
            }
            _sprintf(status_text_guess, "%s", status_name_guess);
            {
                TextTemp_guess text_guess(status_text_guess);
                view_guess->list_guess->SetItem_guess(0, 4, &text_guess);
            }
            view_guess->list_guess->ClearItem_guess(0, 4, -1);
            view_guess->shown_guess = 1;
        }
        if (view_guess->comments_guess != 0) {
            int count_guess = 0;
            if (view_guess->detail_guess != 0) {
                view_guess->comments_guess->Append_guess("<c \"#ffff00\">");
                view_guess->comments_guess->Append_guess(pStringTable->getString(0x227d, 0));
                view_guess->comments_guess->Append_guess("<br>------------------------------<br>");
                view_guess->comments_guess->Append_guess(asctime(localtime((long*)&record_guess->created_guess)));
                view_guess->comments_guess->Append_guess("</c><br><c \"#ffffff\">");
                view_guess->comments_guess->Append_guess(record_guess->text_guess);
                view_guess->comments_guess->Append_guess("</c><br><br><br>");
            }
            int order_guess[10];
            int index_guess;
            for (index_guess = 0; index_guess < 10; ++index_guess) {
                order_guess[index_guess] = index_guess;
            }
            for (index_guess = 1; index_guess < 10; ++index_guess) {
                for (other_guess = 0; other_guess < index_guess; ++other_guess) {
                    if (record_guess->entries_guess[order_guess[other_guess]].id_guess == 0 ||
                        record_guess->entries_guess[order_guess[index_guess]].time_guess <
                            record_guess->entries_guess[order_guess[other_guess]].time_guess) {
                        int swap_guess = order_guess[index_guess];
                        order_guess[index_guess] = order_guess[other_guess];
                        order_guess[other_guess] = swap_guess;
                    }
                }
            }
            for (index_guess = 0; index_guess < 10; ++index_guess) {
                if (record_guess->entries_guess[order_guess[index_guess]].id_guess != 0) {
                    if (count_guess == 0) {
                        view_guess->comments_guess->Append_guess("<c \"#ffff00\">");
                        view_guess->comments_guess->Append_guess(pStringTable->getString(0x2291, 0));
                        view_guess->comments_guess->Append_guess("<br>------------------------------<br>");
                    }
                    ++count_guess;
                    view_guess->comments_guess->Append_guess("<c \"#ffff00\">");
                    view_guess->comments_guess->Append_guess(pStringTable->getString(0x2292, 0));
                    view_guess->comments_guess->Append_guess(g_ticketSpacer_guess);
                    view_guess->comments_guess->Append_guess(
                        _itoa(record_guess->entries_guess[order_guess[index_guess]].id_guess, number_guess, 10));
                    view_guess->comments_guess->Append_guess("<br>");
                    view_guess->comments_guess->Append_guess(asctime(
                        localtime((long*)&record_guess->entries_guess[order_guess[index_guess]].time_guess)));
                    view_guess->comments_guess->Append_guess("<br>");
                    view_guess->comments_guess->Append_guess(
                        record_guess->entries_guess[order_guess[index_guess]].author_guess);
                    view_guess->comments_guess->Append_guess(":  </c><c \"#ffffff\">");
                    view_guess->comments_guess->Append_guess(
                        record_guess->entries_guess[order_guess[index_guess]].comment_guess);
                    view_guess->comments_guess->Append_guess("</c><br><br>");
                }
            }
            if (count_guess == 0) {
                view_guess->comments_guess->Append_guess("<c \"#ffff00\">");
                view_guess->comments_guess->Append_guess(
                    pStringTable->getString(view_guess->detail_guess != 0 ? 0x227e : 0x227f, 0));
                view_guess->comments_guess->Append_guess("</c>");
            }
        }
        EnableNewTicket_guess(0);
        ((FlagOwner_guess*)this)->EnableTicketButtons_guess(1);
        int status_guess = record_guess->status_guess;
        // Status 4 or 5, probably closed: no more comments, and 0x99288C is told (slot 0x88).
        if (status_guess == 4 || status_guess == 5) {
            if (view_guess->addComment_guess != 0) {
                view_guess->addComment_guess->enabled_005d_guess = 0;
            }
            if (pinstCTicketCommentWnd_guess != 0) {
                pinstCTicketCommentWnd_guess->Deactivate();
            }
        } else if (view_guess->addComment_guess != 0) {
            view_guess->addComment_guess->enabled_005d_guess = 1;
        }
        if (view_guess->subwindows_guess != 0) {
            view_guess->subwindows_guess->Execute_guess(view_guess->otPage_guess, 1);
        }
    } else {
        ((Owner_guess*)this)->ClearTicketList_guess();
        ((Owner_guess*)this)->ClearTicketComments_guess();
        view_guess->detail_guess = 0;
        view_guess->shown_guess = 0;
        view_guess->field_5ed_guess = 0;
        EnableNewTicket_guess(0);
        ((FlagOwner_guess*)this)->EnableTicketButtons_guess(0);
        if (view_guess->subwindows_guess != 0) {
            view_guess->subwindows_guess->Execute_guess(view_guess->kbPage_guess, 1);
        }
        if (view_guess->comments_guess != 0) {
            ((CStmlWnd*)view_guess->comments_guess)->SetSTMLText(pStringTable->getString(0x2280, 0), 1, 0);
        }
    }
}

// Ticket window, second entry: tail call to the open-tickets page display (0x00562710) for `record`.
// The ticket data code (0x004C9B4B) pushes the current ticket through it.
// FUNCTION: TITANIUM 0x00563E25
void Owner2_guess::ShowTicketThunk_guess(TicketRecord_guess* record_guess) {
    ShowTicket_guess(record_guess);
}

struct TicketCommentWnd_guess {
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
    char pad_0004_guess[0x158];
    Payload_guess* field15c_guess;
    Payload_guess* field160_guess;
    struct RouteSource_guess* field164_guess;

    int WndNotification_guess(Payload_guess* text_guess, int first_guess, int second_guess);
};

struct RouteTemp_guess {
    Payload_guess* value_guess;
};

struct RouteSource_guess {
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
    virtual void Slot63_guess(const TextTemp_guess& text_guess);
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
    virtual void Invoke_guess(RouteTemp_guess* out_guess);
};

#define g_netOwner_guess EQ_GLOBAL(NetworkOwner_guess*, 0x009928A8)

// WndNotification of the add-comment popup (+0x15C OK, +0x160 Cancel, +0x164 edit box): OK sends the
// text through the ticket window (0x9928A8) and clears the box; both close it.
// FUNCTION: TITANIUM 0x005610B1
// @early-stop: budget, diff ndiff=17
int TicketCommentWnd_guess::WndNotification_guess(Payload_guess* text_guess, int first_guess, int second_guess) {
    if (text_guess != field160_guess) {
        if (text_guess != field15c_guess) {
            return 0;
        }
        if (g_netOwner_guess != 0 && field164_guess != 0) {
            RouteTemp_guess piece_guess = { (Payload_guess*)field164_guess };
            field164_guess->Invoke_guess(&piece_guess);
            g_netOwner_guess->AddComment_guess(*(TextTemp_guess*)&piece_guess);
            TextTemp_guess label_guess(g_text_guess);
            field164_guess->Slot63_guess(label_guess);
        }
    }
    Slot34_guess();
    return 0;
}

// Slot 48 is 0x0C0, slot 63 is 0x0FC; enabled byte at 0x5d.
struct ActivateCell_guess {
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
    virtual int FillSubtopics_guess(bool show_guess, bool flag_guess);
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
    virtual void SetText_guess(const CXStr& text_guess);
    char pad_004_guess[0x59];
    char enabled_guess;  // 0x5d
};

// Enables or disables the new-ticket controls. Off also disables (not hides) Begin and Submit and fills the
// comments box with string 0x2283 (a ticket is shown) or 0x2284 (no article read yet); on hides the comments
// box and Submit and shows the instructions and Begin. Both extras need the comments box.
// FUNCTION: TITANIUM 0x00561515
// @early-stop: tiebreak, diff ndiff=100
void Owner2_guess::EnableNewTicket_guess(char enabled_guess) {
    if (ntSubmitButton_guess != 0) {
        ntSubmitButton_guess->enabled_guess = enabled_guess;
    }
    if (ntTopicCombobox_guess != 0) {
        ntTopicCombobox_guess->enabled_guess = enabled_guess;
    }
    if (ntSubtopicCombobox_guess != 0) {
        ntSubtopicCombobox_guess->enabled_guess = enabled_guess;
    }
    if (kbNewTicketButton_guess != 0) {
        kbNewTicketButton_guess->enabled_guess = enabled_guess;
    }
    if (ntCommentsBox_guess != 0) {
        {
            CXStr empty_guess(g_text_guess);
            ntCommentsBox_guess->SetText_guess(empty_guess);
        }
        ntCommentsBox_guess->enabled_guess = enabled_guess;
        if (enabled_guess == 0) {
            if (ntBeginButton_guess != 0) {
                ntBeginButton_guess->enabled_guess = enabled_guess;
            }
            if (ntSubmitButton_guess != 0) {
                ntSubmitButton_guess->enabled_guess = 0;
            }
            if (field_5ec_guess != 0) {
                ntCommentsBox_guess->SetText_guess(CXStr(pStringTable->getString(0x2283, 0)));
            } else if (field_5ed_guess == 0) {
                ntCommentsBox_guess->SetText_guess(CXStr(pStringTable->getString(0x2284, 0)));
            }
        } else {
            field_5ef_guess = 1;
            ntCommentsBox_guess->FillSubtopics_guess(0, 1);
            if (ntInstructionsBox_guess != 0) {
                ntInstructionsBox_guess->FillSubtopics_guess(1, 1);
            }
            if (ntBeginButton_guess != 0) {
                ntBeginButton_guess->FillSubtopics_guess(1, 1);
                ntBeginButton_guess->enabled_guess = 1;
            }
            if (ntSubmitButton_guess != 0) {
                ntSubmitButton_guess->FillSubtopics_guess(0, 1);
            }
        }
    }
}


struct TicketValuePacket_guess {
    int type_guess;
    int value_guess;
};

struct TicketReportPacket_guess {
    char pad_0000_guess[0x14];
    char class_name_guess[0x10];
    char race_name_guess[0x10];
    char zone_name_guess[0x20];
    int level_guess;
    char guild_name_guess[0x20];
    unsigned int topic_guess;
    unsigned int subtopic_guess;
    char text_guess[0xfa0];
    int tail_guess;
};

struct TicketSendPacket_guess {
    int type_guess;
    int mode_guess;
    char text_guess[0x40];
    int tail_guess;
};

#define TICKET_CONTROL_SLOT(n) virtual void Slot##n##_guess();
struct TicketEventControl_guess {
    TICKET_CONTROL_SLOT(00)
    TICKET_CONTROL_SLOT(01)
    TICKET_CONTROL_SLOT(02)
    TICKET_CONTROL_SLOT(03)
    TICKET_CONTROL_SLOT(04)
    TICKET_CONTROL_SLOT(05)
    TICKET_CONTROL_SLOT(06)
    TICKET_CONTROL_SLOT(07)
    TICKET_CONTROL_SLOT(08)
    TICKET_CONTROL_SLOT(09)
    TICKET_CONTROL_SLOT(10)
    TICKET_CONTROL_SLOT(11)
    TICKET_CONTROL_SLOT(12)
    TICKET_CONTROL_SLOT(13)
    TICKET_CONTROL_SLOT(14)
    TICKET_CONTROL_SLOT(15)
    TICKET_CONTROL_SLOT(16)
    TICKET_CONTROL_SLOT(17)
    TICKET_CONTROL_SLOT(18)
    TICKET_CONTROL_SLOT(19)
    TICKET_CONTROL_SLOT(20)
    TICKET_CONTROL_SLOT(21)
    TICKET_CONTROL_SLOT(22)
    TICKET_CONTROL_SLOT(23)
    TICKET_CONTROL_SLOT(24)
    TICKET_CONTROL_SLOT(25)
    TICKET_CONTROL_SLOT(26)
    TICKET_CONTROL_SLOT(27)
    TICKET_CONTROL_SLOT(28)
    TICKET_CONTROL_SLOT(29)
    TICKET_CONTROL_SLOT(30)
    TICKET_CONTROL_SLOT(31)
    TICKET_CONTROL_SLOT(32)
    TICKET_CONTROL_SLOT(33)
    TICKET_CONTROL_SLOT(34)
    TICKET_CONTROL_SLOT(35)
    TICKET_CONTROL_SLOT(36)
    TICKET_CONTROL_SLOT(37)
    TICKET_CONTROL_SLOT(38)
    TICKET_CONTROL_SLOT(39)
    TICKET_CONTROL_SLOT(40)
    TICKET_CONTROL_SLOT(41)
    TICKET_CONTROL_SLOT(42)
    TICKET_CONTROL_SLOT(43)
    TICKET_CONTROL_SLOT(44)
    TICKET_CONTROL_SLOT(45)
    TICKET_CONTROL_SLOT(46)
    TICKET_CONTROL_SLOT(47)
    virtual int Show_guess(bool show_guess, bool flag_guess);
    TICKET_CONTROL_SLOT(49)
    TICKET_CONTROL_SLOT(50)
    TICKET_CONTROL_SLOT(51)
    TICKET_CONTROL_SLOT(52)
    TICKET_CONTROL_SLOT(53)
    TICKET_CONTROL_SLOT(54)
    TICKET_CONTROL_SLOT(55)
    TICKET_CONTROL_SLOT(56)
    TICKET_CONTROL_SLOT(57)
    TICKET_CONTROL_SLOT(58)
    TICKET_CONTROL_SLOT(59)
    TICKET_CONTROL_SLOT(60)
    TICKET_CONTROL_SLOT(61)
    TICKET_CONTROL_SLOT(62)
    virtual void SetText_guess(const CXStr& text_guess);
    TICKET_CONTROL_SLOT(64)
    TICKET_CONTROL_SLOT(65)
    TICKET_CONTROL_SLOT(66)
    TICKET_CONTROL_SLOT(67)
    TICKET_CONTROL_SLOT(68)
    TICKET_CONTROL_SLOT(69)
    TICKET_CONTROL_SLOT(70)
    TICKET_CONTROL_SLOT(71)
    TICKET_CONTROL_SLOT(72)
    TICKET_CONTROL_SLOT(73)
    TICKET_CONTROL_SLOT(74)
    TICKET_CONTROL_SLOT(75)
    virtual CXStr GetText_guess();
    char pad_0004_guess[0x59];
    char enabled_guess;
};
#undef TICKET_CONTROL_SLOT

// Fields read from the profile returned by GetCharInfo2 (the full CHARINFO2 is not declared yet).
struct TicketDataPlayer_guess {
    char pad_0000_guess[0x1198];
    int race_guess;                          // 0x1198
    unsigned char class_guess;              // 0x119c
    char pad_119d_guess[7];
    int level_guess;                         // 0x11a4
};

struct TicketDataBase_guess : EQ_CharacterProfile_guess {
    virtual void Slot00_guess();
    char pad_000c_guess[0xf4];
    unsigned int zone_instance_guess; // 0x100: virtual base ZoneInstance
};

struct TicketRootPrefix_guess {
    virtual void Slot00_guess();
    int unknown_0004_guess;
};

struct TicketDataRoot_guess : TicketRootPrefix_guess, virtual TicketDataBase_guess {
};

#define g_ticketDataRoot_guess EQ_GLOBAL(TicketDataRoot_guess*, 0x00905D00)

struct TicketProfile_guess {
    char pad_0000_guess[0x120];
    char text_guess[0x20];
};

struct TicketNameTable_guess {
    // EXTERNAL: TITANIUM 0x0049273D TicketNameTable_guess::GetRaceName_guess
    char* GetRaceName_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00491E5B TicketNameTable_guess::GetClassName_guess
    char* GetClassName_guess(int value_guess);
};

struct TicketRecordTable_guess {
    // EXTERNAL: TITANIUM 0x0043A6BF TicketRecordTable_guess::GetZoneRecord_guess
    char* GetZoneRecord_guess(int index_guess);
};

struct TicketNotifySource_guess {
    char pad_0000_guess[0x15c];
    int value_guess;
};

#define TICKET_OWNER_SLOT(n) virtual void Slot##n##_guess();
struct TicketEventOwner_guess {
    TICKET_OWNER_SLOT(00)
    TICKET_OWNER_SLOT(01)
    TICKET_OWNER_SLOT(02)
    TICKET_OWNER_SLOT(03)
    TICKET_OWNER_SLOT(04)
    TICKET_OWNER_SLOT(05)
    TICKET_OWNER_SLOT(06)
    TICKET_OWNER_SLOT(07)
    TICKET_OWNER_SLOT(08)
    TICKET_OWNER_SLOT(09)
    TICKET_OWNER_SLOT(10)
    TICKET_OWNER_SLOT(11)
    TICKET_OWNER_SLOT(12)
    TICKET_OWNER_SLOT(13)
    TICKET_OWNER_SLOT(14)
    TICKET_OWNER_SLOT(15)
    TICKET_OWNER_SLOT(16)
    TICKET_OWNER_SLOT(17)
    TICKET_OWNER_SLOT(18)
    TICKET_OWNER_SLOT(19)
    TICKET_OWNER_SLOT(20)
    TICKET_OWNER_SLOT(21)
    TICKET_OWNER_SLOT(22)
    TICKET_OWNER_SLOT(23)
    TICKET_OWNER_SLOT(24)
    TICKET_OWNER_SLOT(25)
    TICKET_OWNER_SLOT(26)
    TICKET_OWNER_SLOT(27)
    TICKET_OWNER_SLOT(28)
    TICKET_OWNER_SLOT(29)
    TICKET_OWNER_SLOT(30)
    TICKET_OWNER_SLOT(31)
    TICKET_OWNER_SLOT(32)
    TICKET_OWNER_SLOT(33)
    TICKET_OWNER_SLOT(34)
    char pad_0004_guess[0x15c];
    IndexedCallback_guess* callback_0160_guess;
    TimedSource_guess* source_0164_guess;
    TimedTarget_guess* target_0168_guess;
    void* sender_016c_guess;
    void* sender_0170_guess;
    char pad_0174_guess[8];
    char source_text_017c_guess[0x404];
    void* sender_0580_guess;
    void* sender_0584_guess;
    void* sender_0588_guess;
    void* sender_058c_guess;
    void* sender_0590_guess;
    TicketEventControl_guess* control_0594_guess;
    TicketEventControl_guess* control_0598_guess;
    void* sender_059c_guess;
    void* sender_05a0_guess;
    TicketEventControl_guess* control_05a4_guess;
    TicketEventControl_guess* control_05a8_guess;
    SubCategoryList_guess* source_05ac_guess;
    SubCategoryList_guess* source_05b0_guess;
    TicketEventControl_guess* control_05b4_guess;
    TicketEventControl_guess* control_05b8_guess;
    TicketEventControl_guess* control_05bc_guess;
    CListWnd* list_05c0_guess;
    CListWnd* list_05c4_guess;
    Sink_guess* receiver_05c8_guess;
    char pad_05cc_guess[8];
    int callback_value_05d4_guess;
    char pad_05d8_guess[0x14];
    char flag_05ec_guess;
    char flag_05ed_guess;
    char flag_05ee_guess;
    char flag_05ef_guess;

    int WndNotification_guess(void* sender_guess, int message_guess, void* data_guess);
};
#undef TICKET_OWNER_SLOT

struct TicketContext_source_guess;

#define g_ticketProfile_guess EQ_GLOBAL(TicketProfile_guess*, 0x00905D04)
#define g_ticketNameTable_guess EQ_GLOBAL(TicketNameTable_guess*, 0x00988DF0)
#define g_ticketRecordTable_guess EQ_GLOBAL(TicketRecordTable_guess*, 0x00905CC0)
#define g_ticketNotifySource_guess EQ_GLOBAL(TicketNotifySource_guess*, 0x009928A8)
#define g_ticketFormat_guess EQ_ARRAY(char, 0x0064CE78)

// FUNCTION: TITANIUM 0x00561D1E
// @early-stop: three virtual-base/profile adjustments combine two LEAs into one (701/704 instructions).
int TicketEventOwner_guess::WndNotification_guess(
    void* sender_guess, int message_guess, void* data_guess) {
    TicketReportPacket_guess report_guess;
    char current_text_guess[0x80];
    char incoming_text_guess[0x80];
    TicketSendPacket_guess send_packet_guess;

    if ((sender_guess == sender_058c_guess && message_guess == 1) ||
        (sender_guess == control_05a4_guess && message_guess == 6)) {
        if (strlen(control_05a4_guess->GetText_guess()) > 0) {
            send_packet_guess.mode_guess = 0;
            _strncpy(send_packet_guess.text_guess, control_05a4_guess->GetText_guess(), 0x40);
            EQSendMessage(g_networkGlobal_guess, 0x2aec,
                              reinterpret_cast<Packet_guess*>(&send_packet_guess), 0x4c, 1);
            reinterpret_cast<FlagTargetOwner_guess*>(this)->EnableKBSearch_guess(0);
            reinterpret_cast<CStmlWnd*>(receiver_05c8_guess)->SetSTMLText(CXStr(pStringTable->getString(0x2276, 0)), 1, 0);
        }
    } else if ((sender_guess == sender_0590_guess && message_guess == 6) ||
               (sender_guess == control_05a8_guess && message_guess == 6)) {
        if (strlen(control_05a8_guess->GetText_guess()) > 0) {
            send_packet_guess.mode_guess = 1;
            _strncpy(send_packet_guess.text_guess, control_05a8_guess->GetText_guess(), 0x40);
            EQSendMessage(g_networkGlobal_guess, 0x2aec,
                              reinterpret_cast<Packet_guess*>(&send_packet_guess), 0x4c, 1);
            reinterpret_cast<FlagTargetOwner_guess*>(this)->EnableKBSearch_guess(0);
            reinterpret_cast<CStmlWnd*>(receiver_05c8_guess)->SetSTMLText(CXStr(pStringTable->getString(0x2277, 0)), 1, 0);
        }
    } else if (message_guess == 1) {
        if (sender_guess != callback_0160_guess) {
            if (sender_guess == sender_0580_guess ||
                sender_guess == sender_0584_guess ||
                sender_guess == sender_0588_guess) {
                Slot34_guess();
            } else if (sender_guess == control_0598_guess) {
                if (strlen(control_05b4_guess->GetText_guess()) > 0 && flag_05ef_guess == 0) {
                    report_guess.topic_guess = reinterpret_cast<SearchOwner_guess*>(this)->GetTopicId_guess(
                        source_05ac_guess->Get_guess().GetText_guess());
                    report_guess.subtopic_guess = reinterpret_cast<SearchOwner_guess*>(this)->GetTopicId_guess(
                        source_05b0_guess->Get_guess().GetText_guess());
                    if (report_guess.topic_guess > 0 && report_guess.subtopic_guess > 0) {
                        int race_guess = reinterpret_cast<TicketDataPlayer_guess*>(g_ticketDataRoot_guess->GetCharInfo2())->race_guess;
                        _strncpy(report_guess.race_name_guess,
                                g_ticketNameTable_guess->GetRaceName_guess(race_guess), 0x10);
                        unsigned char class_guess = reinterpret_cast<TicketDataPlayer_guess*>(g_ticketDataRoot_guess->GetCharInfo2())->class_guess;
                        _strncpy(report_guess.class_name_guess,
                                g_ticketNameTable_guess->GetClassName_guess(class_guess), 0x10);
                        unsigned int zone_guess = g_ticketDataRoot_guess->zone_instance_guess;
                        _strncpy(report_guess.zone_name_guess,
                                g_ticketRecordTable_guess->GetZoneRecord_guess(zone_guess) + 0x10, 0x20);
                        report_guess.level_guess = reinterpret_cast<TicketDataPlayer_guess*>(g_ticketDataRoot_guess->GetCharInfo2())->level_guess;
                        if (g_ticketProfile_guess != 0) {
                            _strncpy(report_guess.guild_name_guess, g_ticketProfile_guess->text_guess, 0x20);
                        }
                        _strncpy(report_guess.text_guess, control_05b4_guess->GetText_guess(), 4000);
                        EQSendMessage(g_networkGlobal_guess, 0x73cb,
                                          reinterpret_cast<Packet_guess*>(&report_guess), 0x1024, 1);
                        reinterpret_cast<Owner2_guess*>(this)->EnableNewTicket_guess(0);
                        if (control_05b4_guess != 0) {
                            CXStr sent_text_guess(pStringTable->getString(0x2278, 0));
                            control_05b4_guess->SetText_guess(sent_text_guess);
                        }
                    } else {
                        pConfirmationDialogPool_guess->Activate(
                            0, 0xb, pStringTable->getString(0x1427, 0), 1, -1, 0, 1);
                    }
                }
            } else if (sender_guess == sender_059c_guess) {
                if (list_05c4_guess->ItemsCount > 0) {
                    pConfirmationDialogPool_guess->Activate(
                        g_ticketNotifySource_guess != 0 ? &g_ticketNotifySource_guess->value_guess : 0, 100, pStringTable->getString(0x2279, 0), 0xc, -1, 0, 1);
                }
            } else if (sender_guess == sender_05a0_guess) {
                if (pinstCTicketCommentWnd_guess != 0) {
                    pinstCTicketCommentWnd_guess->Activate();
                    pinstCTicketCommentWnd_guess->BringToTop(1);
                }
            } else if (sender_guess == control_0594_guess) {
                if (flag_05ed_guess != 0 && flag_05ec_guess == 0) {
                    reinterpret_cast<Owner2_guess*>(this)->EnableNewTicket_guess(1);
                }
                if (callback_0160_guess != 0) {
                    callback_0160_guess->Execute_guess(callback_value_05d4_guess, 1);
                }
            } else if (sender_guess == source_05ac_guess) {
                reinterpret_cast<SubCategoryOwner_guess*>(this)->FillSubtopics_guess();
            } else if (sender_guess == control_05bc_guess) {
                if (control_05b8_guess != 0) {
                    control_05b8_guess->Show_guess(0, 1);
                }
                if (control_05b4_guess != 0) {
                    {
                        CXStr instructions_guess(pStringTable->getString(0x2294, 0));
                        control_05b4_guess->SetText_guess(instructions_guess);
                    }
                    control_05b4_guess->Show_guess(1, 1);
                }
                flag_05ef_guess = 1;
                control_05bc_guess->enabled_guess = 0;
                control_05bc_guess->Show_guess(0, 1);
                if (control_0598_guess != 0) {
                    control_0598_guess->enabled_guess = 0;
                    control_0598_guess->Show_guess(1, 1);
                }
            } else if (sender_guess == target_0168_guess) {
                if (source_0164_guess != 0) {
                    source_0164_guess->Update_guess();
                }
                if (target_0168_guess != 0 && source_0164_guess != 0) {
                    target_0168_guess->value_guess = source_0164_guess->Get_guess();
                }
            } else if (sender_guess == sender_0170_guess) {
                if (pinstCTipWndOFDAY_guess != 0) {
                    pinstCTipWndOFDAY_guess->selectTip_guess(-1, 1);
                    pinstCTipWndOFDAY_guess->EnableAllTips_guess();
                }
                if (pinstCTipWndCONTEXT_guess != 0) {
                    pinstCTipWndCONTEXT_guess->EnableAllTips_guess();
                }
            } else if (sender_guess == sender_016c_guess && source_0164_guess != 0) {
                CXStr source_text_guess(source_text_017c_guess);
                source_0164_guess->Set_guess(source_text_guess, 0, 0);
                return 0;
            }
        }
    } else if (message_guess == 4) {
        if (sender_guess == list_05c0_guess) {
            int selected_guess = list_05c0_guess->GetCurSel();
            if (selected_guess >= 0) {
                send_packet_guess.mode_guess = 1;
                _strncpy(send_packet_guess.text_guess,
                        static_cast<char*>(list_05c0_guess->GetItemText(selected_guess, 1)), 0x40);
                EQSendMessage(g_networkGlobal_guess, 0x2aec,
                                  reinterpret_cast<Packet_guess*>(&send_packet_guess), 0x4c, 1);
                reinterpret_cast<FlagTargetOwner_guess*>(this)->EnableKBSearch_guess(0);
                reinterpret_cast<CStmlWnd*>(receiver_05c8_guess)->SetSTMLText(CXStr(pStringTable->getString(0x2277, 0)), 1, 0);
            }
        } else if (sender_guess == list_05c4_guess && list_05c4_guess->ItemsCount > 0) {
            TicketValuePacket_guess value_packet_guess;
            value_packet_guess.value_guess = _atol(
                static_cast<char*>(list_05c4_guess->GetItemText(0, 0)));
            EQSendMessage(g_networkGlobal_guess, 0x4758,
                              reinterpret_cast<Packet_guess*>(&value_packet_guess), 8, 1);
            flag_05ee_guess = 1;
        }
    } else if (sender_guess == control_05b4_guess &&
               message_guess == 0xe && flag_05ef_guess != 0) {
        flag_05ef_guess = 0;
        if (control_0598_guess != 0) {
            control_0598_guess->enabled_guess = 1;
        }
        if (control_05b4_guess != 0) {
            _strncpy(incoming_text_guess, control_05b4_guess->GetText_guess(), 0x80);
            _strncpy(current_text_guess, pStringTable->getString(0x2294, 0), 0x80);
            unsigned int current_length_guess = strlen(current_text_guess);
            unsigned int incoming_length_guess = strlen(incoming_text_guess);
            if (incoming_length_guess > current_length_guess) {
                char* incoming_guess = incoming_text_guess;
                if (*incoming_guess != 0) {
                    char* current_guess = current_text_guess;
                    while (*incoming_guess != 0) {
                        if (*current_guess == 0 || *incoming_guess != *current_guess) {
                            char typed_guess[2];
                            _sprintf(typed_guess, g_ticketFormat_guess,
                                    *incoming_guess);
                            CXStr typed_text_guess(typed_guess);
                            control_05b4_guess->SetText_guess(typed_text_guess);
                            return 0;
                        }
                        ++incoming_guess;
                        ++current_guess;
                    }
                }
            } else {
                CXStr empty_text_guess(g_text_guess);
                control_05b4_guess->SetText_guess(empty_text_guess);
            }
        }
    } else {
        return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(static_cast<CXWnd*>(sender_guess), message_guess, data_guess);
    }
    return 0;
}

