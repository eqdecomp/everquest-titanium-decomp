// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 183: a hint from compare/tumap.py.
// Two windows. CLootWnd (0x850C40, ctor 0x52B4C9) is CLootWndView_guess: 31 loot slots (slot ids, items, slot
// buttons). The rest is probably the mail address book (strings Mail To, Add, Modify, Replace at
// 0x11BE-0x11C1): CMailAddressBookWndView_guess, Pending_guess and Target_guess are views of that one window (+0x164
// entry list, +0x16C name field, +0x184 name-typed flag, +0x185 Alt held).
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/mail_address_book.h"

// EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
struct Base_guess {
    char pad[0x15c];
    ~Base_guess();
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7Component_guess@@6B@
struct Component_guess {
    // EXTERNAL: TITANIUM 0x005482A0 Component_guess::Reset_guess
    void Reset_guess(int value);
    virtual void Slot00_guess() {}
    ~Component_guess() { Reset_guess(-1); }
};

struct Helper_guess {
    Component_guess component;
    ~Helper_guess() {}
};

struct Dispatch_guess {
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
    virtual int Slot48_guess(int a, int b);
};

struct Entry_guess {
    virtual void Slot00_guess(int flags);
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value);
};

struct Sub_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Sub_guess::Release_guess
    void Release_guess(int value);
};

struct Node_guess {
    char pad_guess[0x12c];
    Sub_guess* sub_guess;
};

struct EqSoundManagerView_guess {
    // EXTERNAL: TITANIUM 0x0044A617 EqSoundManagerView_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int a, int b);
    // EXTERNAL: TITANIUM 0x0044A537 EqSoundManagerView_guess::Post_guess
    void Post_guess(int a, int b);
};

struct Pane_guess {
    char pad_guess[0x118];
    char state_guess;
    // EXTERNAL: TITANIUM 0x00417CF2 Pane_guess::SetA_guess
    void SetA_guess(int value);
    // EXTERNAL: TITANIUM 0x00417D1C Pane_guess::SetB_guess
    void SetB_guess(int value);
    // EXTERNAL: TITANIUM 0x00417D46 Pane_guess::SetC_guess
    void SetC_guess(int value);
    // EXTERNAL: TITANIUM 0x00417D70 Pane_guess::SetD_guess
    void SetD_guess(int value);
};

struct Lead_guess {
    char pad_guess[8];
};

struct Ctx_guess : Lead_guess, virtual Pane_guess {
    char gap_guess[0xc280];
    char busy_guess;
};

struct Notifier_guess {
    // EXTERNAL: TITANIUM 0x00483556 Notifier_guess::Notify_guess
    void Notify_guess(int code);
};

#define g_ui_guess EQ_GLOBAL(EqSoundManagerView_guess*, 0x00851390)
#define g_ctx_guess EQ_GLOBAL(Ctx_guess*, 0x00905D00)
#define g_notifier_guess EQ_GLOBAL(Notifier_guess*, 0x00905CE4)
#define g_flagA_guess EQ_GLOBAL(int, 0x00905D18)
#define g_flagB_guess EQ_GLOBAL(int, 0x009248D4)

struct CLootWndView_guess : Base_guess, Helper_guess {
    int padding_guess;
    int slots_guess[31];
    char gap_guess[8];
    Entry_guess* entries_guess[31];
    char gap2_guess[4];
    Node_guess* nodes_guess[31];

    ~CLootWndView_guess();
    CLootWndView_guess* Delete_guess(unsigned char flags);
    int HandleLootResponse_guess(char mode, int a, int b, int c, int d);
    void RequestLootSlot_guess(int index, char enabled);
};

struct Packet_guess {
    unsigned int words_guess[4];
};

struct Gate_guess {
    char padding_guess[0x11];
    char closed_guess;
};

struct NameMethod_guess {
    // EXTERNAL: TITANIUM 0x004793B5 NameMethod_guess::Get_guess
    const char* Get_guess();
};

struct Context_guess {
    NameMethod_guess method_guess;
    char padding_guess[0x11f];
    char name_guess[0x138];
    int value_guess;
};

struct StatusPart_guess {
    char padding_guess[0x78];
    int value_guess;
};

struct StatusPage_guess {
    char padding_guess[0x10];
    StatusPart_guess part_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    StatusPage_guess* GetCharInfo2();
};

struct StatusProxy_guess {
    int padding_guess;
    EQ_CharacterProfileView_guess method_guess;
};

#include "titanium/layouts/core.h"

union ManagerDynamic_guess {
    VBTable* holder_guess;
    char bytes_guess[0xc278];
};

struct Filter_guess {
    // EXTERNAL: TITANIUM 0x004192AA Filter_guess::Check_guess
    int Check_guess(Entry_guess* entry, int value);
};

struct Manager_guess {
    char padding_guess[8];
    ManagerDynamic_guess dynamic_guess;
    Filter_guess filter_guess;
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    int getString(int id, int zero, int width, int timeout, Packet_guess* packet, int one);
};

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(void* target, int delay, int result);
};

#define g_gate_guess EQ_GLOBAL(Gate_guess*, 0x00905D24)
#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00905D00)
#define g_context_guess EQ_GLOBAL(Context_guess*, 0x00905D18)
#define g_server_guess EQ_GLOBAL(Context_guess*, 0x00905CE4)
#define g_mode_guess EQ_GLOBAL(int, 0x009254E0)
#define g_counter_guess EQ_GLOBAL(int, 0x009248D0)
#define g_send_connection_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_lookup_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define pinstCLootWnd_guess EQ_GLOBAL(CLootWndView_guess*, 0x00850C40)
#define g_submitter_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// EXTERNAL: TITANIUM 0x00621E9C _stricmp
extern "C" int __cdecl _stricmp(const char* left, const char* right);

// EXTERNAL: TITANIUM 0x00470D4F BuildMoneyText_guess
void __cdecl BuildMoneyText_guess(int a, int b, int c, int d, char* out);
// EXTERNAL: TITANIUM 0x0046DA4A BuildMessage_guess
void __cdecl BuildMessage_guess(char* out, int code, char* text, int z1, int z2, int z3, int z4, int z5, int z6, int z7, int z8);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Scalar deleting destructor of the loot window (vtable 0x657D28 slot 1, ctor 0x0052B4C9): destroys it
// and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0052B73A
CLootWndView_guess* CLootWndView_guess::Delete_guess(unsigned char flags) {
    this->CLootWndView_guess::~CLootWndView_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Destructor of the loot window: expires every confirmation dialog its dialog-owner part (+0x15C)
// opened (0x005482A0, all messages), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0052B756
CLootWndView_guess::~CLootWndView_guess() {
}

// Answer to the loot request (EQEmu moneyOnCorpseStruct.response in `mode`): 0 someone else is looting,
// 2 not now, 4 a hostile creature is aware of you, 5 too far; each prints its string and drops the loot
// target. 1 and 3 open the window: the coins (platinum to copper) are added and announced (0x2F27 when
// split with the group, else 0x2F28), the slots cleared and the stand state set to looting ('i').
// FUNCTION: TITANIUM 0x0052B79C
int CLootWndView_guess::HandleLootResponse_guess(char mode, int a, int b, int c, int d) {
    for (int i = 0; i < 31; ++i) {
        slots_guess[i] = -1;
    }
    if (mode == 5) {
        pEverQuest->dsp_chat(pStringTable->getString(0x3066, 0), 0x111, 1);
        g_flagA_guess = 0;
        g_flagB_guess = 0;
        return -1;
    } else if (mode == 4) {
        pEverQuest->dsp_chat(pStringTable->getString(0x1422, 0), 0x111, 1);
        g_flagA_guess = 0;
        g_flagB_guess = 0;
        return -1;
    } else if (mode == 2) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2f26, 0), 0x111, 1);
        g_flagA_guess = 0;
        g_flagB_guess = 0;
        return -1;
    } else if (mode == 1 || mode == 3) {
        g_ui_guess->SetMusicSelection_guess(5, 1);
        g_ctx_guess->Pane_guess::SetA_guess(a);
        g_ctx_guess->Pane_guess::SetB_guess(b);
        g_ctx_guess->Pane_guess::SetC_guess(c);
        g_ctx_guess->Pane_guess::SetD_guess(d);
        g_ctx_guess->busy_guess = 1;
        if (a + b + c + d > 0) {
            g_ui_guess->Post_guess(0x8a, 0);
            char text[256];
            char out[256];
            text[0] = 0;
            BuildMoneyText_guess(a, b, c, d, text);
            if (g_ctx_guess->Pane_guess::state_guess != 0) {
                BuildMessage_guess(out, 0x2f27, text, 0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                BuildMessage_guess(out, 0x2f28, text, 0, 0, 0, 0, 0, 0, 0, 0);
            }
            pEverQuest->dsp_chat(out, 0x11d, 1);
        }
        for (int i = 0; i < 31; ++i) {
            if (entries_guess[i] != 0) {
                entries_guess[i]->Slot00_guess(1);
                entries_guess[i] = 0;
            }
            slots_guess[i] = -1;
            if (nodes_guess[i] != 0) {
                nodes_guess[i]->sub_guess->Release_guess(-1);
            }
        }
        g_notifier_guess->Notify_guess(0x69);
    } else if (mode == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2f29, 0), 0x111, 1);
        g_flagA_guess = 0;
        g_flagB_guess = 0;
        return -1;
    }
    return ((Dispatch_guess*)this)->Slot48_guess(1, 1);
}

// Loots slot `index` (OP_LootItem: corpse id, our spawn id, slot, auto-loot flag) and counts the request
// (0x9248D0). From someone else's corpse an item that fails the entry's check (probably NO TRADE) asks
// first (0x818, 20 s) unless option 0x9254E0 says otherwise.
// FUNCTION: TITANIUM 0x0052B9D5
// @early-stop: budget, diff ndiff=32
void CLootWndView_guess::RequestLootSlot_guess(int index, char enabled) {
    Packet_guess* packet = new Packet_guess;
    if (g_gate_guess->closed_guess == 0) {
        StatusProxy_guess* proxy = (StatusProxy_guess*)&g_manager_guess->dynamic_guess.bytes_guess[
            g_manager_guess->dynamic_guess.holder_guess->vbase_offset];
        StatusPage_guess* status = proxy->method_guess.GetCharInfo2();
        StatusPart_guess* part = &status->part_guess;
        if (part->value_guess == 0 && index >= 0 && index <= 31 && entries_guess[index] != 0) {
            if (g_mode_guess > 2 || g_mode_guess < 0) {
                g_mode_guess = 0;
            }
            packet->words_guess[0] = g_context_guess->value_guess;
            packet->words_guess[1] = g_server_guess->value_guess;
            packet->words_guess[2] = slots_guess[index];
            packet->words_guess[3] = enabled != 0;

            const char* serverName = g_server_guess->name_guess;
            const char* currentName = g_context_guess->method_guess.Get_guess();
            if (_stricmp(serverName, currentName) == 0 ||
                entries_guess[index]->Slot04_guess(0) != 0 ||
                g_mode_guess == 2 ||
                (g_mode_guess != 0 && g_manager_guess->filter_guess.Check_guess(entries_guess[index], 1) != 0)) {
                ++g_counter_guess;
                EQSendMessage(&g_send_connection_guess, OP_LootItem, packet, 0x10, 1);
            } else {
                // The 16-byte request rides along as the dialog's data.
                int result = g_lookup_guess->getString(0x818, 0, 0xc, 0x4e20, packet, 1);
                g_submitter_guess->Activate((void*)(Helper_guess*)pinstCLootWnd_guess, 100, result);
            }
        }
    }
}

struct CListWndView_guess {
    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView_guess::GetItemData
    void* GetItemData(int index);
};

struct DispatchOperation_guess {
    // EXTERNAL: TITANIUM 0x0042BF49 DispatchOperation_guess::Apply_guess
    void Apply_guess(void* item);
};

struct DispatchResult_guess {
    char pad_guess[0x60];
    DispatchOperation_guess operation_guess;
};

struct DispatchSource_guess {
    // EXTERNAL: TITANIUM 0x00495250 DispatchSource_guess::Get_guess
    DispatchResult_guess* Get_guess();
};

struct Handler_guess {
    char pad_guess[8];
    CListWndView_guess* collection_guess;
    void Execute_guess(int unused1, unsigned char flags, int unused2);
};

#define g_dispatchSource_guess EQ_GLOBAL(DispatchSource_guess*, 0x00988DF0)

// On a yes answer (flags 1 or 4), passes the selected list row to 0x42BF49 on the object CEverQuest's
// 0x495250 returns (+0x60).
// FUNCTION: TITANIUM 0x0052BB3E
void Handler_guess::Execute_guess(int unused1, unsigned char flags, int unused2) {
    if ((flags & 5) != 0 && collection_guess != 0) {
        int selected_guess = collection_guess->GetCurSel();
        if (selected_guess >= 0) {
            void* item_guess = collection_guess->GetItemData(collection_guess->GetCurSel());
            DispatchSource_guess* source_guess = g_dispatchSource_guess;
            if (source_guess != 0) {
                if (source_guess->Get_guess() != 0) {
                    DispatchResult_guess* result_guess = g_dispatchSource_guess->Get_guess();
                    result_guess->operation_guess.Apply_guess(item_guess);
                }
            }
        }
    }
}

// FUNCTION: TITANIUM 0x0052BB96
CMailAddressBookWnd_guess::CMailAddressBookWnd_guess(CXWnd* parent) : MailScreenWndView_guess(parent, "MailAddressBookWindow", -1, 1, 0) {
    slots_guess[0] = 0;
    slots_guess[1] = 0;
    slots_guess[2] = 0;
    slots_guess[3] = 0;
    slots_guess[4] = 0;
    slots_guess[5] = 0;
    slots_guess[6] = 0;
    slots_guess[7] = 0;
    if (sidlPiece_guess != 0) {
        windowStyle_guess |= sidlPiece_guess->style_guess | 0x10800;
        field158_guess = 0x45;
        flag18_guess = 1;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        slots_guess[0] = ((CSidlScreenWnd*)this)->GetChildItem("NameList");
        if (slots_guess[0] != 0) {
            ((MailChild_guess*)slots_guess[0])->byte15c_guess = 0;
            ((CListWnd*)slots_guess[0])->SetColors(-1, 0xffffff00, 0xff808080);
            ((MailChild_guess*)slots_guess[0])->color16c_guess = 0xff8aa3ff;
            ((MailChild_guess*)slots_guess[0])->SetMinimum_guess(MailChild_guess::Range_guess(100, 0x9c));
            ((MailChild_guess*)slots_guess[0])->bytes_guess[2] &= 0xdf;
        }
        slots_guess[2] = ((CSidlScreenWnd*)this)->GetChildItem("NameField");
        if (slots_guess[2] != 0) {
            ((MailChild_guess*)slots_guess[2])->SetMaxChars_guess(0x40);
            {
                CXStr excluded("\t,<>\"+");
                ((MailChild_guess*)slots_guess[2])->SetExcluded_guess(excluded);
            }
        }
        slots_guess[1] = ((CSidlScreenWnd*)this)->GetChildItem("NameFieldIsPrivateCheckbox");
        slots_guess[3] = ((CSidlScreenWnd*)this)->GetChildItem("FieldOfAddresses");
        if (slots_guess[3] != 0) {
            ((MailChild_guess*)slots_guess[3])->SetMaxChars_guess(0x400);
            {
                CXStr excluded(" \t,;:'?/\\<>~!@#$%^&*()\"{}[]+=*-");
                ((MailChild_guess*)slots_guess[3])->SetExcluded_guess(excluded);
            }
            ((MailChild_guess*)slots_guess[3])->AddStyle_guess(0x1d0000);
        }
        slots_guess[4] = ((CSidlScreenWnd*)this)->GetChildItem("NoteField");
        if (slots_guess[4] != 0) {
            ((MailChild_guess*)slots_guess[4])->SetMaxChars_guess(2000);
            ((MailChild_guess*)slots_guess[4])->AddStyle_guess(0x1d0000);
        }
        slots_guess[5] = ((CSidlScreenWnd*)this)->GetChildItem("AddModifyButton");
        slots_guess[6] = ((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        slots_guess[7] = ((CSidlScreenWnd*)this)->GetChildItem("ClearButton");
        MailChild_guess* top = (MailChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("TopInfos");
        if (top != 0) {
            top->SetMinimum_guess(MailChild_guess::Range_guess(100, 0x4e));
        }
        MailChild_guess* bottom = (MailChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("BottomInfos");
        if (bottom != 0) {
            bottom->SetMinimum_guess(MailChild_guess::Range_guess(100, 0x68));
        }
        MailChild_guess* infos = (MailChild_guess*)((CSidlScreenWnd*)this)->GetChildItem("Infos");
        if (infos != 0) {
            infos->SetMinimum_guess(MailChild_guess::Range_guess(100, 0xb6));
        }
        SetMinimum_guess(MailScreenWndView_guess::Size_guess(0x140, 0xc8));
        flag184_guess = 0;
        flag185_guess = 0;
    }
}


struct Focus_guess {
    // EXTERNAL: TITANIUM 0x0059CE00 Focus_guess::IsFocused_guess
    bool IsFocused_guess();
};

struct Pending_guess {
    char pad_guess[0x62];
    char busy_guess;
    char pad2_guess[0x164 - 0x63];
    CListWnd* list_guess;
    CButtonWnd* button_guess;
    CXWnd* first_guess;
    CXWnd* second_guess;
    CXWnd* third_guess;
    char pad3_guess[0x184 - 0x178];
    char cleared_guess;
    char altHeld_0185_guess;
    // EXTERNAL: TITANIUM 0x0052C14F Pending_guess::UpdateSendButton_guess
    void UpdateSendButton_guess();
    // EXTERNAL: TITANIUM 0x0059D770 Pending_guess::Callee_guess
    int Callee_guess(int a, unsigned int b, int c);
    int HandleKeyboardMsg_guess(int a, unsigned int b, int c);
    void OnProcessFrame_guess();
    void ShowSelectedEntry_guess();
    void ClearFields_guess();
};

struct ItemList_guess {
    char pad_guess[4];
    union {
        char* pointer_guess;
        char inline_guess[16];
    } text_guess;
    int length_guess;
    unsigned int capacity_guess;
    char pad2_guess[0x2d];
    char selected_guess;
};

struct Collection_guess {
    char pad_guess[0x11c];
    int count_guess;
    // EXTERNAL: TITANIUM 0x00597BE0 Collection_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 Collection_guess::GetItemData
    ItemList_guess* GetItemData(int index);
    // EXTERNAL: TITANIUM 0x00597F10 Collection_guess::GetItemText
    CXStr GetItemText(int index, int zero);
};

#define SLOT_GUESS(n) virtual void Slot##n##_guess() = 0
struct CurrentSource_guess {
    SLOT_GUESS(00); SLOT_GUESS(01); SLOT_GUESS(02); SLOT_GUESS(03);
    SLOT_GUESS(04); SLOT_GUESS(05); SLOT_GUESS(06); SLOT_GUESS(07);
    SLOT_GUESS(08); SLOT_GUESS(09); SLOT_GUESS(10); SLOT_GUESS(11);
    SLOT_GUESS(12); SLOT_GUESS(13); SLOT_GUESS(14); SLOT_GUESS(15);
    SLOT_GUESS(16); SLOT_GUESS(17); SLOT_GUESS(18); SLOT_GUESS(19);
    SLOT_GUESS(20); SLOT_GUESS(21); SLOT_GUESS(22); SLOT_GUESS(23);
    SLOT_GUESS(24); SLOT_GUESS(25); SLOT_GUESS(26); SLOT_GUESS(27);
    SLOT_GUESS(28); SLOT_GUESS(29); SLOT_GUESS(30); SLOT_GUESS(31);
    SLOT_GUESS(32); SLOT_GUESS(33); SLOT_GUESS(34); SLOT_GUESS(35);
    SLOT_GUESS(36); SLOT_GUESS(37); SLOT_GUESS(38); SLOT_GUESS(39);
    SLOT_GUESS(40); SLOT_GUESS(41); SLOT_GUESS(42); SLOT_GUESS(43);
    SLOT_GUESS(44); SLOT_GUESS(45); SLOT_GUESS(46); SLOT_GUESS(47);
    SLOT_GUESS(48); SLOT_GUESS(49); SLOT_GUESS(50); SLOT_GUESS(51);
    SLOT_GUESS(52); SLOT_GUESS(53); SLOT_GUESS(54); SLOT_GUESS(55);
    SLOT_GUESS(56); SLOT_GUESS(57); SLOT_GUESS(58); SLOT_GUESS(59);
    SLOT_GUESS(60); SLOT_GUESS(61); SLOT_GUESS(62); SLOT_GUESS(63);
    SLOT_GUESS(64); SLOT_GUESS(65); SLOT_GUESS(66); SLOT_GUESS(67);
    SLOT_GUESS(68); SLOT_GUESS(69); SLOT_GUESS(70); SLOT_GUESS(71);
    SLOT_GUESS(72); SLOT_GUESS(73); SLOT_GUESS(74); SLOT_GUESS(75);
    virtual CXStr Current_guess() = 0;
};

struct Display_guess {
    SLOT_GUESS(00); SLOT_GUESS(01); SLOT_GUESS(02); SLOT_GUESS(03);
    SLOT_GUESS(04); SLOT_GUESS(05); SLOT_GUESS(06); SLOT_GUESS(07);
    SLOT_GUESS(08); SLOT_GUESS(09); SLOT_GUESS(10); SLOT_GUESS(11);
    SLOT_GUESS(12); SLOT_GUESS(13); SLOT_GUESS(14); SLOT_GUESS(15);
    SLOT_GUESS(16); SLOT_GUESS(17); SLOT_GUESS(18); SLOT_GUESS(19);
    SLOT_GUESS(20); SLOT_GUESS(21); SLOT_GUESS(22); SLOT_GUESS(23);
    SLOT_GUESS(24); SLOT_GUESS(25); SLOT_GUESS(26); SLOT_GUESS(27);
    SLOT_GUESS(28); SLOT_GUESS(29); SLOT_GUESS(30); SLOT_GUESS(31);
    SLOT_GUESS(32); SLOT_GUESS(33); SLOT_GUESS(34); SLOT_GUESS(35);
    SLOT_GUESS(36); SLOT_GUESS(37); SLOT_GUESS(38); SLOT_GUESS(39);
    SLOT_GUESS(40); SLOT_GUESS(41); SLOT_GUESS(42); SLOT_GUESS(43);
    SLOT_GUESS(44); SLOT_GUESS(45); SLOT_GUESS(46); SLOT_GUESS(47);
    SLOT_GUESS(48); SLOT_GUESS(49); SLOT_GUESS(50); SLOT_GUESS(51);
    SLOT_GUESS(52); SLOT_GUESS(53); SLOT_GUESS(54); SLOT_GUESS(55);
    SLOT_GUESS(56); SLOT_GUESS(57); SLOT_GUESS(58); SLOT_GUESS(59);
    SLOT_GUESS(60); SLOT_GUESS(61); SLOT_GUESS(62);
    virtual void Update_guess(CXStr* value_guess) = 0;
    char pad_guess[0x59];
    char state_guess;
};
#undef SLOT_GUESS

struct FlagSetter_guess {
    // EXTERNAL: TITANIUM 0x005B7EA0 FlagSetter_guess::Set_guess
    void Set_guess(int value);
};

struct Status_guess {
    char pad_guess[0x5d];
    char state_guess;
};

struct Empty_guess {
    // EXTERNAL: TITANIUM 0x004D95D0 Empty_guess::IsEmpty_guess
    bool IsEmpty_guess();
};

// EXTERNAL: TITANIUM 0x00574950 Compare_guess
int __cdecl Compare_guess(char* left, char* right);
struct CMailAddressBookWndView_guess {
    char pad_guess[0x164];
    Collection_guess* collection_guess;
    Status_guess* status2_guess;
    CurrentSource_guess* currentSource_guess;
    FlagSetter_guess* setter1_guess;
    FlagSetter_guess* setter2_guess;
    Display_guess* display_guess;
    Status_guess* status_guess;
    char pad2_guess[4];
    char flag184_guess;
    char flag185_guess;
    void UpdateSendButton_guess();
};

struct Result_guess_t {
    // EXTERNAL: TITANIUM 0x004D95D0 Result_guess_t::Check_guess
    bool Check_guess();
};

#define QSLOT_GUESS(n) virtual void Slot##n##_guess() {}
struct Query_guess {
    QSLOT_GUESS(00) QSLOT_GUESS(01) QSLOT_GUESS(02) QSLOT_GUESS(03) QSLOT_GUESS(04) QSLOT_GUESS(05) QSLOT_GUESS(06) QSLOT_GUESS(07)
    QSLOT_GUESS(08) QSLOT_GUESS(09) QSLOT_GUESS(0A) QSLOT_GUESS(0B) QSLOT_GUESS(0C) QSLOT_GUESS(0D) QSLOT_GUESS(0E) QSLOT_GUESS(0F)
    QSLOT_GUESS(10) QSLOT_GUESS(11) QSLOT_GUESS(12) QSLOT_GUESS(13) QSLOT_GUESS(14) QSLOT_GUESS(15) QSLOT_GUESS(16) QSLOT_GUESS(17)
    QSLOT_GUESS(18) QSLOT_GUESS(19) QSLOT_GUESS(1A) QSLOT_GUESS(1B) QSLOT_GUESS(1C) QSLOT_GUESS(1D) QSLOT_GUESS(1E) QSLOT_GUESS(1F)
    QSLOT_GUESS(20) QSLOT_GUESS(21) QSLOT_GUESS(22) QSLOT_GUESS(23) QSLOT_GUESS(24) QSLOT_GUESS(25) QSLOT_GUESS(26) QSLOT_GUESS(27)
    QSLOT_GUESS(28) QSLOT_GUESS(29) QSLOT_GUESS(2A) QSLOT_GUESS(2B) QSLOT_GUESS(2C) QSLOT_GUESS(2D) QSLOT_GUESS(2E) QSLOT_GUESS(2F)
    QSLOT_GUESS(30) QSLOT_GUESS(31) QSLOT_GUESS(32) QSLOT_GUESS(33) QSLOT_GUESS(34) QSLOT_GUESS(35) QSLOT_GUESS(36) QSLOT_GUESS(37)
    QSLOT_GUESS(38) QSLOT_GUESS(39) QSLOT_GUESS(3A) QSLOT_GUESS(3B) QSLOT_GUESS(3C) QSLOT_GUESS(3D) QSLOT_GUESS(3E) QSLOT_GUESS(3F)
    QSLOT_GUESS(40) QSLOT_GUESS(41) QSLOT_GUESS(42) QSLOT_GUESS(43) QSLOT_GUESS(44) QSLOT_GUESS(45) QSLOT_GUESS(46) QSLOT_GUESS(47)
    QSLOT_GUESS(48) QSLOT_GUESS(49) QSLOT_GUESS(4A) QSLOT_GUESS(4B)
    virtual Result_guess_t* Slot4C_guess(int* output);
    // EXTERNAL: TITANIUM 0x0059EDF0 Query_guess::SetFocus
    void SetFocus();
};
#undef QSLOT_GUESS

struct Temp_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571D00 Temp_guess::FreeRep
    void FreeRep(int value);
};

struct Target_guess {
    char pad_guess[0x16c];
    Query_guess* first_guess;
    Query_guess* second_guess;
    Query_guess* third_guess;
    // EXTERNAL: TITANIUM 0x005A1880 Target_guess::OnShow
    void OnShow();
    void OnShow_guess();
};

// OnShow: focuses the first of the three fields whose text is empty, then the base OnShow (0x5A1880).
// FUNCTION: TITANIUM 0x0052C02F
// @early-stop: budget, diff ndiff=11
void Target_guess::OnShow_guess() {
    int cleanupMask = 0;
    bool valid;
    Temp_guess temp;

    temp.value_guess = 0;
    if (first_guess != 0) {
        Result_guess_t* result = first_guess->Slot4C_guess(&temp.value_guess);
        ++cleanupMask;
        if (result->Check_guess()) {
            valid = true;
        } else {
            valid = false;
        }
    } else {
        valid = false;
    }
    if (cleanupMask & 1) {
        cleanupMask &= ~1;
        if (temp.value_guess != 0) {
            temp.FreeRep(temp.value_guess);
        }
    }
    if (valid) {
        first_guess->SetFocus();
    } else {
        if (second_guess != 0) {
            Result_guess_t* result = second_guess->Slot4C_guess(&temp.value_guess);
            cleanupMask |= 2;
            if (result->Check_guess()) {
                valid = true;
            } else {
                valid = false;
            }
        } else {
            valid = false;
        }
        if (cleanupMask & 2) {
            cleanupMask &= ~2;
            if (temp.value_guess != 0) {
                temp.FreeRep(temp.value_guess);
            }
        }
        if (valid) {
            second_guess->SetFocus();
        } else {
            if (third_guess != 0) {
                Result_guess_t* result = third_guess->Slot4C_guess(&temp.value_guess);
                cleanupMask |= 4;
                if (result->Check_guess()) {
                    valid = true;
                } else {
                    valid = false;
                }
            } else {
                valid = false;
            }
            if (cleanupMask & 4) {
                if (temp.value_guess != 0) {
                    temp.FreeRep(temp.value_guess);
                }
            }
            if (valid) {
                third_guess->SetFocus();
            }
        }
    }
    OnShow();
}

// Labels the send button: Mail To (0x11BE), or the secret variant while Alt is held; with a name typed and +0x184
// set, Modify (0x11BF) for the selected entry's own name, Replace (0x11C1) when another entry has it, else
// Add (0x11C0). Also enables the edit fields when the selected entry allows it.
// FUNCTION: TITANIUM 0x0052C14F
// @early-stop: budget, structural ndiff=148
void CMailAddressBookWndView_guess::UpdateSendButton_guess() {
    if (collection_guess == 0 || currentSource_guess == 0 || display_guess == 0 ||
        status_guess == 0 || setter1_guess == 0 || setter2_guess == 0 || status2_guess == 0) {
        return;
    }

    int index = collection_guess->GetCurSel();
    ItemList_guess* item = index >= 0 ? collection_guess->GetItemData(index) : 0;

    CXStr current = currentSource_guess->Current_guess();
    status_guess->state_guess = (item != 0 && item->selected_guess == 0);
    CXStr message;
    if (flag185_guess == 0) {
        message = pStringTable->getString(0x11be, 0);
    } else {
        // Not from the string table.
        message = "Secret To";
    }

    char show = 0;
    if (item != 0) {
        show = !((Empty_guess*)&current)->IsEmpty_guess();
    }

    if (!((Empty_guess*)&current)->IsEmpty_guess() && flag184_guess != 0) {
        message = pStringTable->getString(0x11c0, 0);
        CXStr itemText;
        if (item != 0) {
            const char* text = item->capacity_guess < 0x10
                ? item->text_guess.inline_guess : item->text_guess.pointer_guess;
            itemText = text;
        }

        if (Compare_guess((char*)current, (char*)itemText) == 0) {
            message = pStringTable->getString(0x11bf, 0);
        } else {
            for (int row = 0; row < collection_guess->count_guess; ++row) {
                bool sameName_guess;
                {
                    CXStr candidate = collection_guess->GetItemText(row, 0);
                    sameName_guess = Compare_guess((char*)candidate, (char*)current) == 0;
                }
                if (sameName_guess) {
                    ItemList_guess* found = collection_guess->GetItemData(row);
                    message = pStringTable->getString(0x11c1, 0);
                    show = (found != 0 && found->selected_guess == 0);
                    break;
                }
            }
        }
    }

    display_guess->Update_guess(&message);
    display_guess->state_guess = show;
    setter1_guess->Set_guess(item == 0 || item->selected_guess == 0);
    setter2_guess->Set_guess(item == 0 || item->selected_guess == 0);
    status2_guess->state_guess = (item == 0 || item->selected_guess == 0);
}

// Tab (key 0x0F) moves the focus through the three fields, Shift+Tab back; Alt (0x38) down or up is kept
// in +0x185 and relabels. Everything else goes to CXWnd::HandleKeyboardMsg.
// FUNCTION: TITANIUM 0x0052C45B
int Pending_guess::HandleKeyboardMsg_guess(int a, unsigned int b, int c) {
    if (first_guess == 0 || second_guess == 0 || third_guess == 0) {
        return 0;
    }
    if ((char)c == 0 || a != 0xf) {
        if (a == 0x38) {
            altHeld_0185_guess = (char)c;
            UpdateSendButton_guess();
        }
        return Callee_guess(a, b, c);
    }
    if ((b & 1) == 0) {
        if (((Focus_guess*)first_guess)->IsFocused_guess()) {
            second_guess->SetFocus();
        } else if (((Focus_guess*)second_guess)->IsFocused_guess()) {
            third_guess->SetFocus();
        }
    } else {
        if (((Focus_guess*)second_guess)->IsFocused_guess()) {
            first_guess->SetFocus();
        } else if (((Focus_guess*)third_guess)->IsFocused_guess()) {
            second_guess->SetFocus();
        }
    }
    return 0;
}

// OnProcessFrame: clears the Alt flag (+0x185) and relabels once byte +0x62 is clear.
// FUNCTION: TITANIUM 0x0052C50A
void Pending_guess::OnProcessFrame_guess() {
    if (altHeld_0185_guess != 0 && busy_guess == 0) {
        altHeld_0185_guess = 0;
        UpdateSendButton_guess();
    }
    ((CXWnd*)this)->OnProcessFrame();
}

struct Text_guess {
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
    virtual void Slot63_guess(CXStr* value_guess);
};

#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_separator_guess EQ_ARRAY(char, 0x00641588)

// std::string layout: a 16-byte buffer (or a pointer to the text), size, capacity
struct Text24_guess {
    union {
        char buf_guess[16];
        char* ptr_guess;
    } bx_guess;
    int size_guess;
    unsigned int res_guess;

    const char* CStr_guess() const {
        return res_guess < 0x10 ? bx_guess.buf_guess : bx_guess.ptr_guess;
    }
};

struct Cell_guess {
    int pad_guess;
    Text24_guess name_guess;
};

struct Row_guess {
    int pad_guess;
    Text24_guess name_guess;
    int pad2_guess;
    Cell_guess* begin_guess;
    Cell_guess* end_guess;
    char pad3_guess[8];
    Text24_guess text_guess;
    char flag_guess;
};

// Shows the selected entry: its name, the check box (set when the entry's flag is clear), its member names
// one per line and its text.
// FUNCTION: TITANIUM 0x0052C52F
void Pending_guess::ShowSelectedEntry_guess() {
    if (list_guess != 0 && first_guess != 0 && second_guess != 0 && third_guess != 0 && button_guess != 0) {
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)first_guess)->Slot63_guess(&text);
        }
        button_guess->SetCheck(0);
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)second_guess)->Slot63_guess(&text);
        }
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)third_guess)->Slot63_guess(&text);
        }
        if (list_guess->GetCurSel() >= 0) {
            Row_guess* row = (Row_guess*)list_guess->GetItemData(list_guess->GetCurSel());
            if (row != 0) {
                {
                    CXStr text(row->name_guess.res_guess >= 0x10 ? row->name_guess.bx_guess.ptr_guess : row->name_guess.bx_guess.buf_guess);
                    ((Text_guess*)first_guess)->Slot63_guess(&text);
                }
                button_guess->SetCheck(row->flag_guess == 0);
                CXStr names;
                for (Cell_guess* cell = row->begin_guess; cell != row->end_guess; ++cell) {
                    if (!((Empty_guess*)&names)->IsEmpty_guess()) {
                        names += g_separator_guess;
                    }
                    names += cell->name_guess.res_guess >= 0x10 ? cell->name_guess.bx_guess.ptr_guess : cell->name_guess.bx_guess.buf_guess;
                }
                ((Text_guess*)second_guess)->Slot63_guess(&names);
                {
                    CXStr text(row->text_guess.res_guess >= 0x10 ? row->text_guess.bx_guess.ptr_guess : row->text_guess.bx_guess.buf_guess);
                    ((Text_guess*)third_guess)->Slot63_guess(&text);
                }
            }
        }
        cleared_guess = 0;
        UpdateSendButton_guess();
    }
}

// Drops the selection, empties the fields and focuses the first one.
// FUNCTION: TITANIUM 0x0052C78C
void Pending_guess::ClearFields_guess() {
    if (list_guess != 0 && first_guess != 0 && second_guess != 0 && third_guess != 0 && button_guess != 0) {
        list_guess->SetCurSel(-1);
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)first_guess)->Slot63_guess(&text);
        }
        button_guess->SetCheck(0);
        first_guess->SetFocus();
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)second_guess)->Slot63_guess(&text);
        }
        {
            CXStr text(g_emptyString_guess);
            ((Text_guess*)third_guess)->Slot63_guess(&text);
        }
        UpdateSendButton_guess();
    }
}

