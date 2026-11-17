// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 184: a hint from compare/tumap.py.
// The EQ mail windows: CMailAddressBookWnd (instance 0x850BEC, ctor 0x52BB96 in tu_183) and
// CMailCompositionWnd ("MailCompositionWindow", instance 0x850BE8). The *View_guess classes are per-function
// views of these two. The mail manager comes from pEverQuest via 0x495250; it owns the address book and a
// listener list (+0x60) that both windows join while active.
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
#include "titanium/types.h"
#include <map>
#include <sstream>
#include <string>
#include <vector>

struct FUN_0052c94e_slot_guess {
    // EXTERNAL: TITANIUM 0x00518B72 FUN_0052c94e_slot_guess::Submit_guess
    void Submit_guess(void** value);
};

struct FUN_0052c94e_manager_guess {
    unsigned char pad_000[0x60];
    FUN_0052c94e_slot_guess slot_060;
};

struct FUN_0052c94e_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052c94e_root_guess::Get_guess
    FUN_0052c94e_manager_guess* Get_guess();
};

#define g_FUN_0052c94e_root_guess EQ_GLOBAL(FUN_0052c94e_root_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0063FD9C ??_7NotifierView_guess@@6B@
struct NotifierView_guess {
    // EXTERNAL: TITANIUM 0x005482A0 NotifierView_guess::Set_guess
    void Set_guess(int value);
    virtual void Slot_guess();
    virtual ~NotifierView_guess() { Set_guess(-1); }
};

struct SidlScreenWndView_guess {
    char reserved[0x158];
    virtual void Slot_guess();
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlScreenWndView_guess@@UAE@XZ
    virtual ~SidlScreenWndView_guess();
};

struct ManagerListenerView_guess {
    virtual void Slot00_guess();
};

// EXTERNAL: TITANIUM 0x00657F28 ??_7CMailAddressBookWnd_guess@@6BSidlScreenWndView_guess@@@
// EXTERNAL: TITANIUM 0x00658048 ??_7CMailAddressBookWnd_guess@@6BNotifierView_guess@@@
// EXTERNAL: TITANIUM 0x00657F20 ??_7CMailAddressBookWnd_guess@@6BManagerListenerView_guess@@@
// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct CMailAddressBookWnd_guess : SidlScreenWndView_guess, NotifierView_guess, ManagerListenerView_guess {
    ~CMailAddressBookWnd_guess();
    void* Delete_guess(unsigned char flags);
};

// Leaves the mail manager's listener list.
// FUNCTION: TITANIUM 0x0052C8BB
CMailAddressBookWnd_guess::~CMailAddressBookWnd_guess() {
    if (g_FUN_0052c94e_root_guess != 0) {
        if (g_FUN_0052c94e_root_guess->Get_guess() != 0) {
            FUN_0052c94e_manager_guess* manager = g_FUN_0052c94e_root_guess->Get_guess();
            void* value = static_cast<ManagerListenerView_guess*>(this);
            manager->slot_060.Submit_guess(&value);
        }
    }
}

struct CMailAddressBookWndDeactivateView_guess {
    unsigned char pad_000[0x160];
    unsigned char field_160;

    char AboutToHide_guess();
};

struct FUN_0052d20d_state_guess {
    // EXTERNAL: TITANIUM 0x0059CE00 FUN_0052d20d_state_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x0059EDF0 FUN_0052d20d_state_guess::SetFocus
    void SetFocus();
};

struct CMailCompositionWndKeyView_guess {
    unsigned char pad_000[0x168];
    FUN_0052d20d_state_guess* state_168;
    FUN_0052d20d_state_guess* state_16C;
    FUN_0052d20d_state_guess* state_170;

    // EXTERNAL: TITANIUM 0x0059D770 CMailCompositionWndKeyView_guess::Dispatch_guess
    int Dispatch_guess(int first, unsigned second, int third);
    int HandleKeyboardMsg_guess(int first, unsigned second, int third);
};

// Leaves the listener list with the notify sub-object (+0x160).
// FUNCTION: TITANIUM 0x0052C94E
char CMailAddressBookWndDeactivateView_guess::AboutToHide_guess() {
    if (g_FUN_0052c94e_root_guess != 0) {
        if (g_FUN_0052c94e_root_guess->Get_guess() != 0) {
            FUN_0052c94e_manager_guess* manager = g_FUN_0052c94e_root_guess->Get_guess();
            void* value = this != 0 ? (void*)&field_160 : 0;
            manager->slot_060.Submit_guess(&value);
        }
    }
    return 1;
}

struct FUN_0052c995_rec_guess {
    /*0x000*/ unsigned char pad_000[4];
    /*0x004*/ union {
        char buf_guess[16];
        const char* ptr_guess;
    } text_004;
    /*0x014*/ unsigned int size_014;
    /*0x018*/ unsigned int res_018;
    /*0x01C*/ unsigned char pad_01C[0x49 - 0x1C];
    /*0x049*/ unsigned char flag_049;
};

struct FUN_0052c995_node_guess {
    /*0x00*/ FUN_0052c995_node_guess* next_guess;
    /*0x04*/ FUN_0052c995_node_guess* prev_guess;
    /*0x08*/ FUN_0052c995_rec_guess* rec_guess;
};

struct FUN_0052c995_manager_guess {
    /*0x08C*/ unsigned char pad_000[0x8C];
    /*0x08C*/ FUN_0052c995_node_guess* head_guess;
};

struct FUN_0052c995_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052c995_root_guess::Get_guess
    FUN_0052c995_manager_guess* Get_guess();
};

#define g_FUN_0052c995_root_guess EQ_GLOBAL(FUN_0052c995_root_guess*, 0x00988DF0)

struct FUN_0052c995_slots_guess {
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
    virtual void Slot63_guess(const CXStr& text);
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
};

struct FUN_0052c995_vlist_guess : FUN_0052c995_slots_guess {
    virtual void Slot76_guess();
    // EXTERNAL: TITANIUM 0x0059B800 FUN_0052c995_vlist_guess::Add_guess
    void Add_guess(struct FUN_0052c995_item_guess* item);
};

struct FUN_0052c995_src_guess : FUN_0052c995_slots_guess {
    virtual CXStr Slot76_guess();
};

struct FUN_0052c995_text_guess : CXStr {
    using CXStr::operator=;
    // EXTERNAL: TITANIUM 0x00572650 FUN_0052c995_text_guess::Match_guess
    int Match_guess(const CXStr& other);
};

struct FUN_0052c995_item_guess {
    /*0x00*/ int index_guess;
    /*0x04*/ int field_004_guess;
    /*0x08*/ int field_008_guess;
    /*0x0C*/ unsigned char flag_00C_guess;
    /*0x10*/ FUN_0052c995_rec_guess* rec_guess;
    /*0x14*/ int field_014_guess;
    /*0x18*/ unsigned char flag_018_guess;
    /*0x19*/ unsigned char flag_019_guess;

    FUN_0052c995_item_guess() {
        field_014_guess = -1;
        field_004_guess = 0;
        index_guess = 0;
        field_008_guess = 0;
        flag_00C_guess = 1;
        rec_guess = 0;
        flag_018_guess = 0;
        flag_019_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0042D7A7 FUN_0052c995_item_guess::Set_guess
    void Set_guess(int index, int* value);
    // EXTERNAL: TITANIUM 0x0042D7E5 ??1FUN_0052c995_item_guess@@QAE@XZ
    ~FUN_0052c995_item_guess();
};

struct FUN_0052c995_state_guess {
    /*0x00*/ int value_guess;
    /*0x04*/ FUN_0052c995_text_guess text_guess;
    /*0x08*/ int style_guess;

    FUN_0052c995_state_guess() : style_guess(-1) {
        value_guess = 0;
    }
};

struct FUN_0052cc3b_node_guess {
    FUN_0052cc3b_node_guess* next_guess;
};

struct FUN_0052cc3b_iter_guess {
    FUN_0052cc3b_node_guess* node_guess;
};

struct FUN_0052cc3b_list_guess {
    unsigned char pad_000[4];
    FUN_0052cc3b_node_guess* head_004;

    FUN_0052cc3b_iter_guess begin_guess() {
        FUN_0052cc3b_iter_guess it;
        it.node_guess = head_004->next_guess;
        return it;
    }
    // EXTERNAL: TITANIUM 0x00518D4A FUN_0052cc3b_list_guess::Insert_guess
    void Insert_guess(FUN_0052cc3b_iter_guess where, void* const& value);
};

struct FUN_0052cc3b_manager_guess {
    unsigned char pad_000[0x60];
    FUN_0052cc3b_list_guess list_060;
};

struct FUN_0052cc3b_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052cc3b_root_guess::Get_guess
    FUN_0052cc3b_manager_guess* Get_guess();
};

#define g_FUN_0052cc3b_root_guess EQ_GLOBAL(FUN_0052cc3b_root_guess*, 0x00988DF0)

struct FUN_0052cfdf_control_guess {
    virtual void Slot00_guess(int first, int second, int third);
};

struct FUN_0052c995_prefix_guess {
    unsigned char pad_000[0x15c];
    FUN_0052cfdf_control_guess control_15c_guess;
};

struct CMailAddressBookWndNotifyView_guess {
    unsigned char field_160;
    unsigned char pad_161[3];
    void Notify_guess(int first, int* second);
};

struct CMailAddressBookWndView_guess : FUN_0052c995_prefix_guess,
                                  CMailAddressBookWndNotifyView_guess {
    /*0x164*/ CListWnd* list_164;
    /*0x168*/ struct FUN_0052cc8f_window_guess* window_168;
    /*0x16C*/ FUN_0052c995_src_guess* nameEdit_16c_guess;
    /*0x170*/ struct FUN_0052cc8f_text_guess* text_170;
    /*0x174*/ struct FUN_0052cc8f_text_guess* text_174;
    /*0x178*/ CXWnd* action_178_guess;
    /*0x17C*/ CXWnd* action_17c_guess;
    /*0x180*/ CXWnd* action_180_guess;
    /*0x184*/ unsigned char editingEntry_184_guess;
    /*0x185*/ unsigned char field_185;

    // EXTERNAL: TITANIUM 0x0052C52F CMailAddressBookWndView_guess::ShowSelectedEntry_guess
    void ShowSelectedEntry_guess();
    void RefillAddressList_guess();
    char AboutToShow_guess();
    void AddSelectedToRecipients_guess();
    void SaveEntry_guess();
    // EXTERNAL: TITANIUM 0x0052C78C CMailAddressBookWndView_guess::ClearFields_guess
    void ClearFields_guess();
    // EXTERNAL: TITANIUM 0x0052C14F CMailAddressBookWndView_guess::UpdateSendButton_guess
    void UpdateSendButton_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CMailAddressBookWndView_guess::WndNotification
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

struct FUN_0052cfdf_state_guess {
    unsigned char pad_000[0x94];
    unsigned char active_094_guess;
};

struct FUN_0052cfdf_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052cfdf_root_guess::Get_guess
    FUN_0052cfdf_state_guess* Get_guess();
};

#define g_FUN_0052cfdf_root_guess EQ_GLOBAL(FUN_0052cfdf_root_guess*, 0x00988DF0)

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    char* getString(int id, int second, int third, int fourth, int fifth, int sixth);
};

#define g_FUN_0052cfdf_string_service_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(void* owner, int type, char* message);
};

#define g_FUN_0052cfdf_dialog_pool_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)

struct FUN_0052cfdf_rep_guess {
    unsigned char pad_000[8];
    int length_008_guess;
};

// Refills the address list from the mail manager's book (+0x8C); entries with +0x49 set are drawn
// 0xFFD6B228. The selection moves to the entry named in the name field, if any.
// FUNCTION: TITANIUM 0x0052C995
void CMailAddressBookWndView_guess::RefillAddressList_guess() {
    if (g_FUN_0052c995_root_guess != 0) {
        if (g_FUN_0052c995_root_guess->Get_guess() != 0 && list_164 != 0) {
            FUN_0052c995_manager_guess* manager = g_FUN_0052c995_root_guess->Get_guess();
            int sel = list_164->GetCurSel();
            ((FUN_0052c995_vlist_guess*)list_164)->Slot76_guess();
            int index = 0;
            FUN_0052c995_node_guess* head = manager->head_guess;
            FUN_0052c995_node_guess* node = head->next_guess;
            if (node != head) {
                do {
                    FUN_0052c995_item_guess item;
                    FUN_0052c995_state_guess state;
                    state.text_guess = node->rec_guess->res_018 >= 0x10 ? node->rec_guess->text_004.ptr_guess : node->rec_guess->text_004.buf_guess;
                    state.style_guess = (node->rec_guess->flag_049 != 0 ? 0xffd6b229 : 0) - 1;
                    item.Set_guess(item.index_guess, &state.value_guess);
                    item.rec_guess = node->rec_guess;
                    int hit = state.text_guess.Match_guess(nameEdit_16c_guess->Slot76_guess());
                    if (hit != 0) {
                        sel = index;
                    }
                    ((FUN_0052c995_vlist_guess*)list_164)->Add_guess(&item);
                    node = node->next_guess;
                    index++;
                } while (node != manager->head_guess);
            }
            if (sel != -1 && list_164->ItemsCount >= 1) {
                if (sel >= list_164->ItemsCount) {
                    sel = list_164->ItemsCount - 1;
                }
                list_164->SetCurSel(sel);
            }
            ShowSelectedEntry_guess();
        }
    }
}

// Mail event 4 (probably the address book changed) refills the list.
// FUNCTION: TITANIUM 0x0052CB39
// @early-stop: budget, structural ndiff=6
void CMailAddressBookWndNotifyView_guess::Notify_guess(int first_guess, int* value_guess) {
    if (value_guess != 0 && *value_guess == 4) {
        static_cast<CMailAddressBookWndView_guess*>(this)->RefillAddressList_guess();
    }
}

// AboutToShow (vtable slot 49): refills the list and joins the listener list; the twin of the AboutToHide
// at 0x0052C94E.
// FUNCTION: TITANIUM 0x0052CC3B
char CMailAddressBookWndView_guess::AboutToShow_guess() {
    RefillAddressList_guess();
    if (g_FUN_0052cc3b_root_guess != 0) {
        if (g_FUN_0052cc3b_root_guess->Get_guess() != 0) {
            void* value = this != 0 ? (void*)&field_160 : 0;
            FUN_0052cc3b_list_guess& list = g_FUN_0052cc3b_root_guess->Get_guess()->list_060;
            list.Insert_guess(list.begin_guess(), value);
        }
    }
    return 1;
}

// Scalar deleting destructor of the mail address book window (vtable 0x657F28 slot 1, ctor 0x0052BB3E):
// destroys it and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0052CB54
void* CMailAddressBookWnd_guess::Delete_guess(unsigned char flags) {
    this->CMailAddressBookWnd_guess::~CMailAddressBookWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

struct FUN_0052d5ed_str_guess {
    CStrRep* Ptr;

    // EXTERNAL: TITANIUM 0x004D95D0 FUN_0052d5ed_str_guess::IsEmpty_guess
    bool IsEmpty_guess();

    ~FUN_0052d5ed_str_guess() {
        if (Ptr != 0)
            reinterpret_cast<CXStr*>(this)->FreeRep(Ptr);
        Ptr = 0;
    }
};

struct FUN_0052d5ed_text_guess {
    // EXTERNAL: TITANIUM 0x005B7ED0 FUN_0052d5ed_text_guess::Get_guess
    FUN_0052d5ed_str_guess* Get_guess(FUN_0052d5ed_str_guess* output);
};

struct CMailCompositionWndFrameView_guess : CSidlScreenWnd {
    unsigned char pad_15C[0xC];
    FUN_0052d5ed_text_guess* text_168;
    FUN_0052d5ed_text_guess* text_16C;
    unsigned char pad_170[4];
    CXWnd* wnd_174;

    int OnProcessFrame_guess();
};

// SendSetTitle_guess is enabled only while To and Subject have text.
// FUNCTION: TITANIUM 0x0052D5ED
// @early-stop: budget, structural ndiff=43
int CMailCompositionWndFrameView_guess::OnProcessFrame_guess() {
    if (SidlPiece == 0)
        return 0;

    char enabled;
    {
        FUN_0052d5ed_str_guess first;
        if (!text_168->Get_guess(&first)->IsEmpty_guess()) {
            FUN_0052d5ed_str_guess second;
            enabled = 1;
            if (text_16C->Get_guess(&second)->IsEmpty_guess())
                enabled = 0;
        } else {
            enabled = 0;
        }
    }

    wnd_174->Enabled = enabled;
    return OnProcessFrame();
}

struct FUN_0052d6b9_str_guess : CXStr {
    // EXTERNAL: TITANIUM 0x005734D0 FUN_0052d6b9_str_guess::TrimLeft_guess
    void TrimLeft_guess(char c);
    // EXTERNAL: TITANIUM 0x00573440 FUN_0052d6b9_str_guess::TrimRight_guess
    void TrimRight_guess(char c);
    // EXTERNAL: TITANIUM 0x004D95D0 FUN_0052d6b9_str_guess::IsEmpty_guess
    bool IsEmpty_guess();
    // EXTERNAL: TITANIUM 0x00571590 FUN_0052d6b9_str_guess::CharAt_guess
    char CharAt_guess(int index);
    // EXTERNAL: TITANIUM 0x00572570 FUN_0052d6b9_str_guess::SetChar_guess
    void SetChar_guess(int index, char value);
    // EXTERNAL: TITANIUM 0x00572650 FUN_0052d6b9_str_guess::Compare_guess
    int Compare_guess(const CXStr& other);
};

struct FUN_0052d6b9_wnd_guess {
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
    virtual void Slot63_guess(const CXStr& text);
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
    virtual FUN_0052d6b9_str_guess Slot76_guess();
    // EXTERNAL: TITANIUM 0x005BA1A0 FUN_0052d6b9_wnd_guess::SetSel_guess
    void SetSel_guess(int first, int last);
    // EXTERNAL: TITANIUM 0x0059EDF0 FUN_0052d6b9_wnd_guess::SetFocus
    void SetFocus();
};

struct CMailCompositionWndToView_guess {
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
    unsigned char pad_004[0x164];
    FUN_0052d6b9_wnd_guess* wnd_168;
    // EXTERNAL: TITANIUM 0x0059D080 CMailCompositionWndToView_guess::Flag_guess
    void Flag_guess(int on);
    void Append_guess(const char* text);
};

struct FUN_0052cc8f_str_guess : CXStr {
    // EXTERNAL: TITANIUM 0x004D95D0 FUN_0052cc8f_str_guess::IsEmpty_guess
    bool IsEmpty_guess();
    // EXTERNAL: TITANIUM 0x00572380 FUN_0052cc8f_str_guess::Find_guess
    bool Find_guess(int character, unsigned int* position);
    // EXTERNAL: TITANIUM 0x0050176F FUN_0052cc8f_str_guess::Left_guess
    FUN_0052cc8f_str_guess Left_guess(int count);
    // EXTERNAL: TITANIUM 0x00573370 FUN_0052cc8f_str_guess::Erase_guess
    void Erase_guess(int first, unsigned int count);
};

struct FUN_0052cc8f_text_guess : FUN_0052c995_slots_guess {
    virtual FUN_0052cc8f_str_guess Slot76_guess();
};

struct FUN_0052cc8f_window_guess {
    unsigned char pad_000[0x128];
    unsigned char field_128;
};

struct FUN_0052cc8f_record_guess {
    std::string source_000;
    std::vector<std::string> lines_01c;
    std::string destination_02c;
    unsigned char field_048;
    unsigned char field_049;

    // EXTERNAL: TITANIUM 0x0042BA5E FUN_0052cc8f_record_guess::FUN_0052cc8f_record_guess
    FUN_0052cc8f_record_guess(std::string source, std::vector<std::string> lines,
                              std::string destination, bool flag);
    // EXTERNAL: TITANIUM 0x0040B867 FUN_0052cc8f_record_guess::~FUN_0052cc8f_record_guess
    ~FUN_0052cc8f_record_guess();
};

struct FUN_0052cc8f_addresses_guess {
    unsigned char pad_000[0x2c];
    // EXTERNAL: TITANIUM 0x0042BE14 FUN_0052cc8f_addresses_guess::Insert_guess
    void Insert_guess(const FUN_0052cc8f_record_guess& record);
};

struct FUN_0052cc8f_manager_guess {
    unsigned char pad_000[0x60];
    FUN_0052cc8f_addresses_guess addresses_060;
};

struct FUN_0052cc8f_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052cc8f_root_guess::Get_guess
    FUN_0052cc8f_manager_guess* Get_guess();
};

#define g_FUN_0052cc8f_root_guess EQ_GLOBAL(FUN_0052cc8f_root_guess*, 0x00988DF0)
#define pinstCMailCompositionWnd_guess EQ_GLOBAL(CMailCompositionWndToView_guess*, 0x00850BE8)

// Appends the selected entry to the composition window's To field, with a leading '-' when the secret flag
// (+0x185) is on.
// FUNCTION: TITANIUM 0x0052CB70
void CMailAddressBookWndView_guess::AddSelectedToRecipients_guess() {
    if (list_164 != 0 && pinstCMailCompositionWnd_guess != 0) {
        int selection = list_164->GetCurSel();
        if (selection >= 0) {
            std::string* selected = reinterpret_cast<std::string*>(list_164->GetItemData(selection));
            if (selected != 0) {
                std::string text;
                text.reserve(selected->size() + 1);
                if (field_185 != 0) {
                    text.append(1, '-');
                }
                text.append(*selected, 0, std::string::npos);
                pinstCMailCompositionWnd_guess->Append_guess(text.c_str());
            }
        }
    }
}

// Saves the edited entry to the book: name field, one address per line of the address field, the third
// field's text and the checkbox (+0x128, stored inverted).
// FUNCTION: TITANIUM 0x0052CC8F
// @early-stop: budget, structural ndiff=20
void CMailAddressBookWndView_guess::SaveEntry_guess() {
    if (g_FUN_0052cc8f_root_guess != 0) {
        FUN_0052cc8f_manager_guess* manager = g_FUN_0052cc8f_root_guess->Get_guess();
        if (manager != 0 && nameEdit_16c_guess != 0 && text_170 != 0 && text_174 != 0 && window_168 != 0) {
            std::string source((char*)nameEdit_16c_guess->Slot76_guess());
            char flag = window_168->field_128;

            std::string destination((char*)text_174->Slot76_guess());

            std::vector<std::string> lines;
            FUN_0052cc8f_str_guess remainder = text_170->Slot76_guess();
            while (!remainder.IsEmpty_guess()) {
                unsigned int position;
                if (remainder.Find_guess('\n', &position)) {
                    FUN_0052cc8f_str_guess part = remainder.Left_guess(position);
                    remainder.Erase_guess(position + 1, 0xFFFF);
                    if (!part.IsEmpty_guess()) {
                        lines.push_back(std::string((char*)part));
                    }
                } else {
                    lines.push_back(std::string((char*)remainder));
                    if (remainder.Ptr != 0) {
                        remainder.FreeRep(remainder.Ptr);
                    }
                    remainder.Ptr = 0;
                }
            }

            FUN_0052cc8f_record_guess record(source, lines, destination, flag == 0);
            manager->addresses_060.Insert_guess(record);
        }
    }
}

// +0x178 adds the selection to To or, after an edit (+0x184), saves the entry; +0x180 starts a new one;
// +0x17C deletes, asking first (string 0x11C2) when the confirm-deletion option (+0x94) is on. Editing
// the name (0xE) drops a leading '-' and marks the entry edited. Compare_guess (0x572650) is an equality
// test, non-zero when equal.
// FUNCTION: TITANIUM 0x0052CFDF
// @early-stop: budget, structural ndiff=84
int CMailAddressBookWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    CListWnd* list_guess = list_164;
    CMailAddressBookWndView_guess* owner_guess = this;
    if (list_guess != 0 && owner_guess->nameEdit_16c_guess != 0 && owner_guess->text_170 != 0 &&
        owner_guess->text_174 != 0 && owner_guess->window_168 != 0) {
        if (sender == owner_guess->action_178_guess) {
            if (owner_guess->editingEntry_184_guess == 0) {
                owner_guess->AddSelectedToRecipients_guess();
            } else {
                owner_guess->SaveEntry_guess();
            }
            owner_guess->field_185 = 0;
            owner_guess->UpdateSendButton_guess();
        } else if (sender == owner_guess->action_180_guess) {
            owner_guess->ClearFields_guess();
        } else if (sender == owner_guess->action_17c_guess) {
            if (g_FUN_0052cfdf_root_guess != 0 &&
                g_FUN_0052cfdf_root_guess->Get_guess() != 0 &&
                g_FUN_0052cfdf_root_guess->Get_guess()->active_094_guess != 0) {
                g_FUN_0052cfdf_dialog_pool_guess->Activate(
                    &owner_guess->control_15c_guess, 0,
                    g_FUN_0052cfdf_string_service_guess->getString(0x11c2, 0, 12, -1, 0, 0));
            } else {
                owner_guess->control_15c_guess.Slot00_guess(0, 4, 0);
            }
        } else if (message == 0xe || (void*)sender == (void*)owner_guess->window_168) {
            if ((void*)sender == (void*)owner_guess->nameEdit_16c_guess) {
                CXStr selectedText = owner_guess->nameEdit_16c_guess->Slot76_guess();
                ((FUN_0052d6b9_str_guess*)&selectedText)->TrimLeft_guess(' ');
                if (selectedText.Ptr != 0 &&
                    ((FUN_0052cfdf_rep_guess*)selectedText.Ptr)->length_008_guess > 0 &&
                    ((FUN_0052d6b9_str_guess*)&selectedText)->CharAt_guess(0) == '-') {
                    ((FUN_0052d6b9_str_guess*)&selectedText)->SetChar_guess(0, ' ');
                    ((FUN_0052d6b9_str_guess*)&selectedText)->TrimLeft_guess(' ');
                }
                bool updateText_guess;
                {
                    CXStr sourceText = owner_guess->nameEdit_16c_guess->Slot76_guess();
                    updateText_guess =
                        ((FUN_0052d6b9_str_guess*)&selectedText)->Compare_guess(sourceText) == 0;
                }
                if (updateText_guess) {
                    owner_guess->nameEdit_16c_guess->Slot63_guess(selectedText);
                }
            }
            owner_guess->editingEntry_184_guess = 1;
            owner_guess->UpdateSendButton_guess();
        } else if (sender == list_guess && message == 1) {
            owner_guess->ShowSelectedEntry_guess();
        } else {
            return owner_guess->WndNotification(sender, message, data);
        }
    }
    return 0;
}

// Appends `text` to the To field (after the separator 0x63FDE4 unless empty), puts the caret at the end
// and shows the window.
// FUNCTION: TITANIUM 0x0052D6B9
void CMailCompositionWndToView_guess::Append_guess(const char* text) {
    if (wnd_168 != 0 && text != 0) {
        FUN_0052d6b9_str_guess tmp = wnd_168->Slot76_guess();
        tmp.TrimLeft_guess(' ');
        tmp.TrimRight_guess(' ');
        if (!tmp.IsEmpty_guess()) {
            tmp += EQ_ARRAY(char, 0x0063FDE4);
        }
        tmp += text;
        wnd_168->Slot63_guess(tmp);
        wnd_168->SetFocus();
        int last = tmp.Ptr != 0 ? tmp.Ptr->alloc : 0;
        wnd_168->SetSel_guess(last - 1, last - 1);
        Slot33_guess();
        Flag_guess(1);
    }
}

struct FUN_0052d1f5_target_guess {
    unsigned char pad_00[0x5D];
    bool flag_5D;
};

// Tab (DIK 0x0F, key down) moves the focus To -> Subject -> Text, Shift+Tab back; it stops at the ends.
// Other keys go to the base handler.
// FUNCTION: TITANIUM 0x0052D20D
int CMailCompositionWndKeyView_guess::HandleKeyboardMsg_guess(int first, unsigned second, int third) {
    if ((char)third == 0 || first != 0xF)
        return Dispatch_guess(first, second, third);

    if ((second & 1) == 0) {
        if (state_168->Check_guess()) {
            state_16C->SetFocus();
        } else {
            if (!state_16C->Check_guess())
                return 0;
            state_170->SetFocus();
        }
    } else {
        if (state_170->Check_guess()) {
            state_16C->SetFocus();
        } else {
            if (!state_16C->Check_guess())
                return 0;
            state_168->SetFocus();
        }
    }
    return 0;
}

struct It_guess {
    char* cur;
    It_guess() {}
    explicit It_guess(char* p) : cur(p) {}
    It_guess(const It_guess& o) : cur(o.base()) {}
    char* base() const { return cur; }
    char& operator*() const { return *cur; }
    It_guess& operator++() { ++cur; return *this; }
    bool operator==(const It_guess& r) const { return cur == r.cur; }
    bool operator!=(const It_guess& r) const { return !(*this == r); }
};

// std::find over a string's characters.
// FUNCTION: TITANIUM 0x0052D79C
std::string::iterator __cdecl Find_guess(std::string::iterator first,
                                         std::string::iterator last, const char& value) {
    for (; first != last; ++first)
        if (*first == value)
            break;
    return first;
}

struct D_guess {
    char pad[0x1c];
    int f1c;
    // EXTERNAL: TITANIUM 0x004275C7 D_guess::At_guess
    CXStr At_guess(int v);
    CXStr Get();
};

// Returns the C string at +0x1C as a new string (0x004275C7): the mail manager's current address, which
// the compose window puts in its From label (0x0052D7D7).
// FUNCTION: TITANIUM 0x0052D7BD
CXStr D_guess::Get() { return At_guess(f1c); }

struct FUN_0052d7d7_string_guess {
    unsigned int data_guess[7];
    // EXTERNAL: TITANIUM 0x0040291E FUN_0052d7d7_string_guess::_Tidy
    void _Tidy(bool tidy_guess, unsigned int reserve_guess);
    const char* CStr_guess() const {
        if (data_guess[6] >= 0x10)
            return (const char*)data_guess[1];
        return (const char*)&data_guess[1];
    }
    ~FUN_0052d7d7_string_guess() { _Tidy(true, 0); }
};

struct FUN_0052d7d7_selected_guess {
    // EXTERNAL: TITANIUM 0x0052D7BD FUN_0052d7d7_selected_guess::Get_guess
    FUN_0052d7d7_string_guess* Get_guess();
};

struct FUN_0052d7d7_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052d7d7_root_guess::Get_guess
    D_guess* Get_guess();
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052d7d7_root_guess::Get_guess_output
    FUN_0052d7d7_selected_guess* Get_guess_output(FUN_0052d7d7_string_guess* output_guess);
};

#define g_FUN_0052d7d7_root_guess EQ_GLOBAL(FUN_0052d7d7_root_guess*, 0x00988DF0)

struct CMailCompositionWndFromView_guess {
    unsigned char pad_000[0x164];
    struct FUN_0052d7d7_obj_guess* obj_164;
    void UpdateFromAddress_guess();
};

struct FUN_0052d7d7_obj_guess {
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

struct FUN_0052d940_manager_guess {
    // EXTERNAL: TITANIUM 0x00518B72 FUN_0052d940_manager_guess::Submit_guess
    void Submit_guess(void** value);
};

struct FUN_0052d940_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052d940_root_guess::Get_guess
    FUN_0052d940_manager_guess* Get_guess();
};

#define g_FUN_0052d940_root_guess EQ_GLOBAL(FUN_0052d940_root_guess*, 0x00988DF0)

struct CMailCompositionWndDeactivateView_guess : FUN_0052d6b9_wnd_guess {
    unsigned char pad_004[0x15c];
    unsigned char field_160;
    unsigned char pad_161[7];
    FUN_0052d6b9_wnd_guess* child_168;
    FUN_0052d6b9_wnd_guess* child_16c;
    FUN_0052d6b9_wnd_guess* child_170;
    char AboutToHide_guess();
};

// Sets the From label to the mail manager's current address.
// FUNCTION: TITANIUM 0x0052D7D7
// @early-stop: budget, structural ndiff=6
void CMailCompositionWndFromView_guess::UpdateFromAddress_guess() {
    if (obj_164 != 0 && g_FUN_0052d7d7_root_guess != 0) {
        if (g_FUN_0052d7d7_root_guess->Get_guess() != 0) {
            FUN_0052d7d7_string_guess output_guess;
            FUN_0052d7d7_selected_guess* selected_guess =
                g_FUN_0052d7d7_root_guess->Get_guess_output(&output_guess);
            CXStr text_guess(selected_guess->Get_guess()->CStr_guess());
            obj_164->Slot63_guess(text_guess);
        }
    }
}

struct FUN_0052d87a_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052d87a_root_guess::Get_guess
    int Get_guess();
};

#define g_FUN_0052d87a_root_guess EQ_GLOBAL(FUN_0052d87a_root_guess*, 0x00988DF0)

// Records are 0x160 bytes; the callee runs on the previous one.
struct CMailCompositionWndNotifyView_guess {
    unsigned char pad_000[0x160];
    void Check_guess(int first, int* second);
    // EXTERNAL: TITANIUM 0x0052D7D7 CMailCompositionWndNotifyView_guess::UpdateFromAddress_guess
    void UpdateFromAddress_guess();
};

// Mail event 2 from the manager refreshes the From label; `this` is the listener at +0x160, so
// `this - 1` (0x160-byte steps) is the window.
// FUNCTION: TITANIUM 0x0052D87A
void CMailCompositionWndNotifyView_guess::Check_guess(int first, int* second) {
    if (g_FUN_0052d87a_root_guess != 0) {
        if (first == g_FUN_0052d87a_root_guess->Get_guess() && second != 0 && *second == 2) {
            (this - 1)->UpdateFromAddress_guess();
        }
    }
}

struct FUN_0052d8ae_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052d8ae_root_guess::Get_guess
    FUN_0052c94e_slot_guess* Get_guess();
};

#define g_FUN_0052d8ae_root_guess EQ_GLOBAL(FUN_0052d8ae_root_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x006580F8 ??_7CMailCompositionWndDtorView_guess@@6BSidlScreenWndView_guess@@@
// EXTERNAL: TITANIUM 0x00658218 ??_7CMailCompositionWndDtorView_guess@@6BNotifierView_guess@@@
// EXTERNAL: TITANIUM 0x006580F0 ??_7CMailCompositionWndDtorView_guess@@6BManagerListenerView_guess@@@

struct CMailCompositionWndDtorView_guess : SidlScreenWndView_guess, NotifierView_guess, ManagerListenerView_guess {
    ~CMailCompositionWndDtorView_guess();
    void* Delete_guess(unsigned char flags);
};

// Leaves the mail manager's listener list.
// FUNCTION: TITANIUM 0x0052D8AE
CMailCompositionWndDtorView_guess::~CMailCompositionWndDtorView_guess() {
    if (g_FUN_0052d8ae_root_guess != 0) {
        if (g_FUN_0052d8ae_root_guess->Get_guess() != 0) {
            void* value = static_cast<ManagerListenerView_guess*>(this);
            FUN_0052c94e_slot_guess* manager = g_FUN_0052d8ae_root_guess->Get_guess();
            manager->Submit_guess(&value);
        }
    }
}

// AboutToHide (vtable slot 50): resets the title (string 0x11A6), clears To, Subject and Text, leaves the
// listener list.
// FUNCTION: TITANIUM 0x0052D940
// @early-stop: budget, structural ndiff=12
char CMailCompositionWndDeactivateView_guess::AboutToHide_guess() {
    {
        CXStr text(pStringTable->getString(0x11a6, 0));
        Slot63_guess(text);
    }

    {
        FUN_0052d6b9_wnd_guess* const& child = child_168;
        if (child != 0) {
            CXStr separator(EQ_ARRAY(char, 0x0063F53F));
            child->Slot63_guess(separator);
        }
    }
    {
        FUN_0052d6b9_wnd_guess* const& child = child_16c;
        if (child != 0) {
            CXStr separator(EQ_ARRAY(char, 0x0063F53F));
            child->Slot63_guess(separator);
        }
    }
    {
        FUN_0052d6b9_wnd_guess* const& child = child_170;
        if (child != 0) {
            CXStr separator(EQ_ARRAY(char, 0x0063F53F));
            child->Slot63_guess(separator);
        }
    }

    if (g_FUN_0052d940_root_guess != 0) {
        if (g_FUN_0052d940_root_guess->Get_guess() != 0) {
            void* value = &field_160;
            FUN_0052d940_manager_guess* manager = g_FUN_0052d940_root_guess->Get_guess();
            manager->Submit_guess(&value);
        }
    }
    return 1;
}

// Scalar deleting destructor of the mail compose window (vtable 0x6580F8 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x0052DA93
void* CMailCompositionWndDtorView_guess::Delete_guess(unsigned char flags) {
    this->CMailCompositionWndDtorView_guess::~CMailCompositionWndDtorView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

struct FUN_0052daaf_node_guess {
    /*0x00*/ FUN_0052daaf_node_guess* next_guess;
};

struct FUN_0052daaf_iter_guess {
    FUN_0052daaf_node_guess* node_guess;
    explicit FUN_0052daaf_iter_guess(FUN_0052daaf_node_guess* node) : node_guess(node) {}
};

// list<void*>: push_front via insert(begin(), value)
struct FUN_0052daaf_list_guess {
    /*0x00*/ unsigned char pad_000[4];
    /*0x04*/ FUN_0052daaf_node_guess* head_004;
    FUN_0052daaf_iter_guess begin_guess() { return FUN_0052daaf_iter_guess(head_004->next_guess); }
    // EXTERNAL: TITANIUM 0x00518D4A FUN_0052daaf_list_guess::Insert_guess
    void Insert_guess(FUN_0052daaf_iter_guess where, void* const& value);
    void push_front_guess(void* const& value) { Insert_guess(begin_guess(), value); }
};

struct FUN_0052daaf_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052daaf_root_guess::Get_guess
    FUN_0052daaf_list_guess* Get_guess();
};

#define g_FUN_0052daaf_root_guess EQ_GLOBAL(FUN_0052daaf_root_guess*, 0x00988DF0)

struct CMailCompositionWndActivateView_guess {
    unsigned char pad_000[0x160];
    unsigned char field_160;
    // EXTERNAL: TITANIUM 0x0052D7D7 CMailCompositionWndActivateView_guess::UpdateFromAddress_guess
    void UpdateFromAddress_guess();
    char AboutToShow_guess();
};

// AboutToShow (vtable slot 49): refreshes the From label and joins the listener list.
// FUNCTION: TITANIUM 0x0052DAAF
char CMailCompositionWndActivateView_guess::AboutToShow_guess() {
    UpdateFromAddress_guess();
    if (g_FUN_0052daaf_root_guess != 0) {
        if (g_FUN_0052daaf_root_guess->Get_guess() != 0) {
            void* value = this != 0 ? (void*)&field_160 : 0;
            g_FUN_0052daaf_root_guess->Get_guess()->push_front_guess(value);
        }
    }
    return 1;
}

struct FUN_0052de40_item_guess {
    unsigned char pad_000[8];
    int field_008_guess;
};

struct FUN_0052de40_slots_guess {
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
    virtual void Slot63_guess(void* value);
    // EXTERNAL: TITANIUM 0x0059EDF0 FUN_0052de40_slots_guess::SetFocus
    void SetFocus();
    // EXTERNAL: TITANIUM 0x005BA1A0 FUN_0052de40_slots_guess::SetSel_guess
    void SetSel_guess(int first, int last);
};

struct FUN_0052db00_entry_guess;

struct CMailCompositionWndCallbackView_guess {
    unsigned int parent_15c;
    unsigned char pad_160[8];
    FUN_0052de40_slots_guess* sub_168;
    FUN_0052de40_slots_guess* sub_16c;
    FUN_0052de40_slots_guess* sub_170;
    int action_174;
    int action_178;
    int action_17c;
    FUN_0052d1f5_target_guess* target_180;
    int state_184;

    void OnSyncAnswer_guess(int first_guess, unsigned char flags_guess,
                       FUN_0052db00_entry_guess* entry_guess);
};

struct FUN_0052de40_gap_guess {
    unsigned char pad_004[0x158];
};

struct CMailCompositionWndMainView_guess : FUN_0052de40_slots_guess,
                                  FUN_0052de40_gap_guess,
                                  CMailCompositionWndCallbackView_guess {

    // EXTERNAL: TITANIUM 0x0052DB00 CMailCompositionWndMainView_guess::NormalizeToField_guess
    void NormalizeToField_guess();
    void UpdateSyncButton_guess();
    // EXTERNAL: TITANIUM 0x0059D080 CMailCompositionWndMainView_guess::Flag_guess
    void Flag_guess(int on);
    void Compose_guess(void* first, FUN_0052de40_item_guess** second, FUN_0052de40_item_guess** third, void* fourth);
    void SyncWithAddressBook_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

// The sync button (+0x180) is enabled only while no address book question is open (+0x184 counts them).
// FUNCTION: TITANIUM 0x0052D1F5
void CMailCompositionWndMainView_guess::UpdateSyncButton_guess() {
    if (target_180 != 0) {
        target_180->flag_5D = (state_184 == 0);
    }
}

typedef std::map<std::string, int> FUN_0052dfbb_differences_guess;

struct FUN_0052db00_entry_guess : std::string {
    std::vector<std::string> fields_01c;
    std::string address_02c;
    unsigned char field_048;
    unsigned char field_049;
    // EXTERNAL: TITANIUM 0x0042C74B FUN_0052db00_entry_guess::FUN_0052db00_entry_guess
    FUN_0052db00_entry_guess(const std::string& text);
    // EXTERNAL: TITANIUM 0x0040B867 FUN_0052db00_entry_guess::~FUN_0052db00_entry_guess
    ~FUN_0052db00_entry_guess();
    // EXTERNAL: TITANIUM 0x0042CC75 FUN_0052db00_entry_guess::Status_guess
    int Status_guess(const FUN_0052db00_entry_guess* text) const;
    // EXTERNAL: TITANIUM 0x0042CBEA FUN_0052db00_entry_guess::Differences_guess
    FUN_0052dfbb_differences_guess Differences_guess(FUN_0052db00_entry_guess* other);
};

struct FUN_0052db00_address_list_guess {
    unsigned char pad_000[0x2c];
    // EXTERNAL: TITANIUM 0x00428534 FUN_0052db00_address_list_guess::Find_guess
    FUN_0052db00_entry_guess* Find_guess(FUN_0052db00_entry_guess* text);
    // EXTERNAL: TITANIUM 0x0042BE14 FUN_0052db00_address_list_guess::Apply_guess
    void Apply_guess(FUN_0052db00_entry_guess* text);
};

struct FUN_0052db00_manager_guess {
    unsigned char pad_000[0x60];
    FUN_0052db00_address_list_guess addresses_060;
};

struct FUN_0052db00_root_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052db00_root_guess::Get_guess
    FUN_0052db00_manager_guess* Get_guess();
};

#define g_FUN_0052db00_root_guess EQ_GLOBAL(FUN_0052db00_root_guess*, 0x00988DF0)

// Rewrites the To field: plain comma-separated names are trimmed; groups with '<' that match their book
// entry (Status_guess 0 or 4) take the book's form, the rest stay as typed after another separator.
// FUNCTION: TITANIUM 0x0052DB00
// @early-stop: tiebreak, structural ndiff=131
void CMailCompositionWndMainView_guess::NormalizeToField_guess() {
    if (g_FUN_0052db00_root_guess != 0) {
        FUN_0052db00_manager_guess* manager = g_FUN_0052db00_root_guess->Get_guess();
        if (manager != 0 && sub_168 != 0) {
            std::string source((char*)reinterpret_cast<FUN_0052d6b9_wnd_guess*>(sub_168)->Slot76_guess());
            std::ostringstream output(std::ios::out);

            bool first = true;
            std::string::iterator cursor = source.begin();
            std::string::iterator finish = source.end();
            while (cursor < finish) {
                if (first) {
                    first = output.rdbuf()->str().empty();
                }

                char comma = ',';
                std::string::iterator split = Find_guess(cursor, finish, comma);
                std::string token(std::string::const_iterator(cursor._Myptr),
                                  std::string::const_iterator(split._Myptr));
                if (token.find('<') == std::string::npos) {
                    std::string::size_type begin_text = token.find_first_not_of(' ');
                    std::string::size_type end_text = token.find_last_not_of(' ');
                    const char* separator = first ? EQ_ARRAY(char, 0x0063F53F) : EQ_ARRAY(char, 0x0063FDE4);
                    output << separator << token.substr(begin_text, end_text - begin_text + 1);
                } else {
                    FUN_0052db00_entry_guess* entry;
                    try {
                        entry = new FUN_0052db00_entry_guess(token);
                    } catch (...) {
                        entry = 0;
                    }
                    FUN_0052db00_entry_guess* existing = manager->addresses_060.Find_guess(entry);
                    int status;
                    if (existing != 0 && ((status = existing->Status_guess(entry)) == 0 || status == 4)) {
                        const char* separator = first ? EQ_ARRAY(char, 0x0063F53F) : EQ_ARRAY(char, 0x0063FDE4);
                        output << separator << static_cast<const std::string&>(*entry);
                    } else {
                        const char* separator = first ? EQ_ARRAY(char, 0x0063F53F) : EQ_ARRAY(char, 0x0063F9EC);
                        output << separator << token;
                    }
                    delete entry;
                }
                cursor = split + 1;
            }

            reinterpret_cast<FUN_0052d6b9_wnd_guess*>(sub_168)->Slot63_guess(CXStr(output.str().c_str()));
        }
    }
}

// Answer to a sync question: flag 1 or 4 (probably yes) adds or updates the entry, keeping the book's
// +0x2C text. The entry is freed either way; the last answer rewrites the To field.
// FUNCTION: TITANIUM 0x0052DF29
void CMailCompositionWndCallbackView_guess::OnSyncAnswer_guess(int first_guess, unsigned char flags_guess,
                                             FUN_0052db00_entry_guess* entry_guess) {
    if ((flags_guess & 5) != 0 && g_FUN_0052db00_root_guess != 0) {
        FUN_0052db00_manager_guess* manager_guess = g_FUN_0052db00_root_guess->Get_guess();
        if (manager_guess != 0) {
            manager_guess = g_FUN_0052db00_root_guess->Get_guess();
            FUN_0052db00_entry_guess* found_guess =
                manager_guess->addresses_060.Find_guess(entry_guess);
            if (found_guess != 0) {
                entry_guess->address_02c.assign(found_guess->address_02c, 0, std::string::npos);
            }
            manager_guess = g_FUN_0052db00_root_guess->Get_guess();
            manager_guess->addresses_060.Apply_guess(entry_guess);
        }
    }
    if (entry_guess != 0) {
        delete entry_guess;
    }
    --state_184;
    CMailCompositionWndMainView_guess* owner_guess = static_cast<CMailCompositionWndMainView_guess*>(this);
    owner_guess->UpdateSyncButton_guess();
    if (state_184 != 0)
        return;
    owner_guess->NormalizeToField_guess();
}

// Opens a message: title `first`, then To, Subject and Text; the focus goes to the first empty one of To
// and Subject, else to the text, with the caret at its start.
// FUNCTION: TITANIUM 0x0052DE40
void CMailCompositionWndMainView_guess::Compose_guess(void* first, FUN_0052de40_item_guess** second, FUN_0052de40_item_guess** third, void* fourth) {
    bool done = false;
    Slot63_guess(first);
    if (sub_168 != 0) {
        sub_168->Slot63_guess(second);
        NormalizeToField_guess();
        FUN_0052de40_item_guess* item = *second;
        int check = item != 0 ? item->field_008_guess : 0;
        if (check == 0) {
            sub_168->SetFocus();
            done = true;
        }
    }
    if (sub_16c != 0) {
        sub_16c->Slot63_guess(third);
        if (!done) {
            FUN_0052de40_item_guess* item = *third;
            int check = item != 0 ? item->field_008_guess : 0;
            if (check == 0) {
                sub_16c->SetFocus();
                done = true;
            }
        }
    }
    if (sub_170 != 0) {
        sub_170->Slot63_guess(fourth);
        sub_170->SetSel_guess(0, 0);
        if (!done) {
            sub_170->SetFocus();
        }
    }
    Slot33_guess();
    Flag_guess(1);
}

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
char* __cdecl FUN_0046da4a_guess(char* destination, int id, const char* text,
                                  int a4, int a5, int a6, int a7, int a8,
                                  int a9, int a10, int a11);

struct CConfirmationDialogPoolView2_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView2_guess::Activate
    void Activate(void* owner, int type, char* message, int size, int timeout,
                    void* data, int flags);
};

#define g_FUN_0052dfbb_dialog_pool_guess EQ_GLOBAL(CConfirmationDialogPoolView2_guess*, 0x00991E44)

// SyncWithAddressBookButton: for each '<' group in To, asks to add an unknown one (string 0x11C4) or, for a
// book entry without +0x49 that differs, lists the changes (0x11C5; 0x11C6 status bit 1, 0x11C7-0x11C9 the
// added and removed addresses). Answers go to OnSyncAnswer_guess. An entry that needs no question
// is never freed.
// FUNCTION: TITANIUM 0x0052DFBB
// @early-stop: budget, structural ndiff=178
void CMailCompositionWndMainView_guess::SyncWithAddressBook_guess() {
    if (g_FUN_0052db00_root_guess != 0) {
        FUN_0052db00_manager_guess* manager = g_FUN_0052db00_root_guess->Get_guess();
        if (manager != 0 && sub_168 != 0 && g_FUN_0052dfbb_dialog_pool_guess != 0) {
            std::string source((char*)reinterpret_cast<FUN_0052d6b9_wnd_guess*>(sub_168)->Slot76_guess());
            std::ostringstream output(std::ios::out);
            bool first = true;
            std::string::iterator cursor = source.begin();
            std::string::iterator finish = source.end();
            while (cursor < finish) {
                if (first) {
                    first = output.rdbuf()->str().empty();
                }

                char comma = ',';
                std::string::iterator split = Find_guess(cursor, finish, comma);
                std::string token(std::string::const_iterator(cursor._Myptr),
                                  std::string::const_iterator(split._Myptr));
                if (token.find('<') != std::string::npos) {
                    FUN_0052db00_entry_guess* entry = new FUN_0052db00_entry_guess(token);
                    FUN_0052db00_entry_guess* existing = manager->addresses_060.Find_guess(entry);
                    if (existing == 0) {
                        char message[0x800];
                        FUN_0046da4a_guess(message, 0x11c4, entry->c_str(),
                                           0, 0, 0, 0, 0, 0, 0, 0);
                        void* parent = this != 0 ? (void*)&parent_15c : 0;
                        g_FUN_0052dfbb_dialog_pool_guess->Activate(parent, 0, message, 0xc, -1, entry, 0);
                        ++state_184;
                        UpdateSyncButton_guess();
                    } else if (existing->field_049 == 0) {
                        int status = existing->Status_guess(entry);
                        if (status != 0 && status != 4) {
                            std::ostringstream details(std::ios::out);
                            char message[0x800];
                            FUN_0046da4a_guess(message, 0x11c5, existing->c_str(),
                                               0, 0, 0, 0, 0, 0, 0, 0);
                            details << message << EQ_ARRAY(char, 0x0065823C);
                            if ((status & 1) != 0) {
                                FUN_0046da4a_guess(message, 0x11c6, entry->c_str(),
                                                   0, 0, 0, 0, 0, 0, 0, 0);
                                details << message << EQ_ARRAY(char, 0x0065823C);
                            }
                            if ((status & 2) != 0) {
                                FUN_0052dfbb_differences_guess differences = entry->Differences_guess(existing);
                                std::string added;
                                std::string removed;
                                for (FUN_0052dfbb_differences_guess::const_iterator it = differences.begin();
                                     it != differences.end(); ++it) {
                                    if (it->second > 0) {
                                        added += EQ_ARRAY(char, 0x0063FE10);
                                        added.append(it->first, 0, std::string::npos);
                                    } else if (it->second < 0) {
                                        removed += EQ_ARRAY(char, 0x0063FE10);
                                        removed.append(it->first, 0, std::string::npos);
                                    }
                                }
                                details << pStringTable->getString(0x11c7, 0) << EQ_ARRAY(char, 0x0064DD5C);
                                if (!added.empty()) {
                                    details << pStringTable->getString(0x11c8, 0) << added << EQ_ARRAY(char, 0x00658234);
                                }
                                if (!removed.empty()) {
                                    details << pStringTable->getString(0x11c9, 0) << removed << EQ_ARRAY(char, 0x00658234);
                                }
                            }

                            void* parent = this != 0 ? (void*)&parent_15c : 0;
                            g_FUN_0052dfbb_dialog_pool_guess->Activate(
                                parent, 0, const_cast<char*>(details.str().c_str()), 0xc, -1, entry, 0);
                            ++state_184;
                            UpdateSyncButton_guess();
                        }
                    }
                }
                cursor = split + 1;
            }
        }
    }
}

struct FUN_0052e576_text_control_guess : FUN_0052de40_slots_guess {
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
    virtual CXStr GetText_guess();
};

struct MailtoLink_guess;

struct FUN_0052e576_mailroot_guess {
    // EXTERNAL: TITANIUM 0x00495250 FUN_0052e576_mailroot_guess::Get_guess
    MailtoLink_guess* Get_guess();
};

#define g_FUN_0052e576_mailroot_guess EQ_GLOBAL(FUN_0052e576_mailroot_guess*, 0x00988DF0)

struct MailtoLink_guess {
    // EXTERNAL: TITANIUM 0x0042B166 MailtoLink_guess::Send_guess
    void Send_guess(const std::string& address, const std::string& subject,
                    const std::string& message, int flags);
};

struct FUN_0052e576_state_guess {
    unsigned char pad_000[0x834];
    int ready_834;
};

#define pinstCMailAddressBookWnd_guess EQ_GLOBAL(CMailCompositionWndMainView_guess*, 0x00850BEC)

// SendSetTitle_guess: refused with string 0x11B1 while pEverQuest +0x834 is 0 (probably no mail connection),
// else sends and closes. Cancel prints 0x11AD and closes; AddressBookButton shows 0x850BEC; sync calls
// SyncWithAddressBook_guess. As decompiled, Send_guess gets the Text field (+0x170) first and To (+0x168)
// third, so its `address` and `message` names are probably swapped.
// FUNCTION: TITANIUM 0x0052E576
// @early-stop: budget, structural ndiff=60
int CMailCompositionWndMainView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    int result;
    if (message == 1) {
        unsigned int action = (unsigned int)sender;
        if (action == (unsigned int)action_174) {
            if (((FUN_0052e576_state_guess*)pEverQuest)->ready_834 == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x11b1, 0), 0xd, true);
                return 0;
            }
            if (g_FUN_0052e576_mailroot_guess->Get_guess() != 0) {
                CXStr messageText = reinterpret_cast<FUN_0052e576_text_control_guess*>(sub_170)->GetText_guess();
                std::string address((char*)messageText);
                CXStr subjectText = reinterpret_cast<FUN_0052e576_text_control_guess*>(sub_16c)->GetText_guess();
                std::string subject((char*)subjectText);
                CXStr bodyText = reinterpret_cast<FUN_0052e576_text_control_guess*>(sub_168)->GetText_guess();
                std::string body((char*)bodyText);
                g_FUN_0052e576_mailroot_guess->Get_guess()->Send_guess(address, subject, body, 0);
            }
            Slot34_guess();
        } else if (action == (unsigned int)action_178) {
            pEverQuest->dsp_chat(pStringTable->getString(0x11ad, 0));
            Slot34_guess();
        } else if (action == (unsigned int)action_17c) {
            CMailCompositionWndMainView_guess* manager = pinstCMailAddressBookWnd_guess;
            if (manager != 0) {
                manager->Slot33_guess();
                manager->Flag_guess(1);
            }
        } else if (action == (unsigned int)target_180) {
            SyncWithAddressBook_guess();
        }
    }
    result = ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(sender, message, data);
    return result;
}

struct FUN_0052d28d_sidl_guess {
    virtual ~FUN_0052d28d_sidl_guess();
    virtual void Slot01_guess();
    unsigned char pad_004[0x14];
    unsigned char field_018;
    unsigned char pad_019[0x43];
    unsigned char field_05C;
    unsigned char field_05D;
    unsigned char pad_05E[2];
    unsigned char field_060;
    unsigned char field_061;
    unsigned char field_062;
    unsigned char field_063;
    unsigned char style_064[4];
    unsigned char pad_068[0xBC];
    struct SidlPiece_guess {
        unsigned char pad_000[0x60];
        unsigned int field_060;
    } *SidlPiece;
    unsigned char pad_128[0x30];
    int field_158;

    // EXTERNAL: TITANIUM 0x005A3850 ??0FUN_0052d28d_sidl_guess@@QAE@PAUCXWnd@@PAUCXStr@@HHPAD@Z
    FUN_0052d28d_sidl_guess(CXWnd* parent, CXStr* screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1CSidlScreenWnd@@QAE@XZ
};

struct FUN_0052d28d_screen_arg_guess {
    CXStr value;
    explicit FUN_0052d28d_screen_arg_guess(const char* text) : value(text) {}
    operator CXStr*() { return &value; }
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7FUN_0052d28d_second_guess@@6B@
struct FUN_0052d28d_second_guess {
    virtual void Slot00_guess() {}
};

// EXTERNAL: TITANIUM 0x006580F8 ??_7CMailCompositionWnd_guess@@6BFUN_0052d28d_sidl_guess@@@
// EXTERNAL: TITANIUM 0x00658218 ??_7CMailCompositionWnd_guess@@6BNotifierView_guess@@@
// EXTERNAL: TITANIUM 0x006580F0 ??_7CMailCompositionWnd_guess@@6BFUN_0052d28d_second_guess@@@
struct CMailCompositionWnd_guess : FUN_0052d28d_sidl_guess,
                            NotifierView_guess,
                            FUN_0052d28d_second_guess {
    CXWnd* from_164;
    CXWnd* to_168;
    CXWnd* subject_16C;
    CXWnd* text_170;
    CXWnd* send_174;
    CXWnd* cancel_178;
    CXWnd* addressBook_17C;
    CXWnd* sync_180;
    int field_184;

    virtual void Slot01_guess() {}
    CMailCompositionWnd_guess(CXWnd* parent);
};

struct FUN_0052d28d_child_guess {
    unsigned char pad_000[0x22C];
    CXStr edit_22C;
    // EXTERNAL: TITANIUM 0x004D7EBC FUN_0052d28d_child_guess::Wait_guess
    void Wait_guess(int duration);
};

struct FUN_0052d28d_text_guess {
    unsigned char pad_000[0x66];
    unsigned char field_066;
};

// To and Text take up to 10000 characters, Subject 200 (Wait_guess is SetMaxChars, 0x4D7EBC).
// FUNCTION: TITANIUM 0x0052D28D
// @early-stop: budget, diff ndiff=33
CMailCompositionWnd_guess::CMailCompositionWnd_guess(CXWnd* parent)
    : FUN_0052d28d_sidl_guess(parent, FUN_0052d28d_screen_arg_guess("MailCompositionWindow"), -1, 1, 0),
      from_164(0), to_168(0), subject_16C(0), text_170(0),
      send_174(0), cancel_178(0), addressBook_17C(0), sync_180(0) {
    if (SidlPiece != 0) {
        *(unsigned int*)style_064 |= SidlPiece->field_060 | 0x10800;
        field_018 = 0;
        field_158 = 0x44;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();

        from_164 = ((CSidlScreenWnd*)this)->GetChildItem("FromAddressLabel");
        to_168 = ((CSidlScreenWnd*)this)->GetChildItem("ToField");
        int timeout = 10000;
        if (to_168 != 0) {
            {
                CXStr emptyText(EQ_ARRAY(char, 0x006580D0));
                ((FUN_0052d28d_child_guess*)to_168)->edit_22C = emptyText;
            }
            ((FUN_0052d28d_child_guess*)to_168)->Wait_guess(timeout);
        }
        subject_16C = ((CSidlScreenWnd*)this)->GetChildItem("SubjectField");
        if (subject_16C != 0) {
            {
                CXStr emptyText(EQ_ARRAY(char, 0x006417DC));
                ((FUN_0052d28d_child_guess*)subject_16C)->edit_22C = emptyText;
            }
            ((FUN_0052d28d_child_guess*)subject_16C)->Wait_guess(200);
        }
        text_170 = ((CSidlScreenWnd*)this)->GetChildItem("TextField");
        if (text_170 != 0) {
            ((FUN_0052d28d_child_guess*)text_170)->Wait_guess(timeout);
            ((FUN_0052d28d_text_guess*)text_170)->field_066 |= 0x1D;
        }
        send_174 = ((CSidlScreenWnd*)this)->GetChildItem("SendButton");
        cancel_178 = ((CSidlScreenWnd*)this)->GetChildItem("CancelButton");
        addressBook_17C = ((CSidlScreenWnd*)this)->GetChildItem("AddressBookButton");
        sync_180 = ((CSidlScreenWnd*)this)->GetChildItem("SyncWithAddressBookButton");
        field_184 = 0;
    }
}

