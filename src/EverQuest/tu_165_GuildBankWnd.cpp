// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 165: a hint from compare/tumap.py.
// CGuildBankWnd ("GuildBankWnd"): the guild bank, 200 main-area and 20 deposit slots, all over OP_GuildBank.
// CGuildBankWndView_guess is a view of the same window: deposit records at +0x198, main records at +0x12C8,
// 0xDC bytes each. Actions follow EQEmu's GuildBank enum: 0 bulk list, 1 item update, 3 promote, 4 view,
// 5 deposit, 6 permissions, 7 withdraw, 8 split, 9 merge, 10 ack. Slot keys are area << 16 | slot (1 main).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>
#include <stdio.h>
#include "titanium/wnd/CQuantityWnd.h"

union PackedValue_guess {
    unsigned int whole;
    struct {
        unsigned short low;
        short high;
    } words;
};

struct LayoutManager_guess {
    unsigned char unknown_0000_guess[0x1c];
    // EXTERNAL: TITANIUM 0x00572300 LayoutManager_guess::Find_guess
    void* Find_guess(const char* name_guess);
};

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
    virtual void Slot48_guess(int value_guess, int flag_guess);
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual CXRect Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(const CXStr& text_guess);
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess(void* value_guess);
    virtual void Slot74_guess(void* value_guess);
    virtual void Slot75_guess();
    virtual void Slot76_guess();
    virtual void Slot77_guess();
    // EXTERNAL: TITANIUM 0x0054D976 Widget_guess::ArrangeSingle_guess
    void ArrangeSingle_guess(void* owner_guess, int count_guess, int flag_guess,
                             int x_guess, int y_guess, int finalFlag_guess);
    // EXTERNAL: TITANIUM 0x0054D976 Widget_guess::ArrangeWithList_guess
    void ArrangeWithList_guess(void* owner_guess, void* list_guess, int count_guess, int flag_guess,
                               int x_guess, int y_guess, int finalFlag_guess);
    // EXTERNAL: TITANIUM 0x0059DD30 Widget_guess::IsReady_guess
    char IsReady_guess();
    virtual void Slot78_guess();
};

struct MessageDispatcher_guess {
    // EXTERNAL: TITANIUM 0x0044A617 MessageDispatcher_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int kind_guess, int flags_guess);
};

struct RecordStream_guess;
struct TypeEntry_guess;
struct Record_guess;

struct SelectionTarget_guess {
    unsigned char unknown_0000_guess[0x5d];
    char active_005d_guess;
    // EXTERNAL: TITANIUM 0x0059C8D0 SelectionTarget_guess::AddString_guess
    int AddString_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 SelectionTarget_guess::SetValue_guess
    void SetValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0059C3A0 SelectionTarget_guess::GetCurChoice_guess
    int GetCurChoice_guess();
};

struct StatusTarget_guess {
    unsigned char unknown_0000_guess[0x5d];
    char active_005d_guess;
};

struct CGuildBankWndView_guess {
    unsigned char unknown_0000[0x140];
    LayoutManager_guess layout_0140_guess;
    void* itemListFirst_015c_guess;
    StatusTarget_guess* statusTarget_0160_guess;
    StatusTarget_guess* statusTarget_0164_guess;
    SelectionTarget_guess* selectionTarget_0168_guess;
    StatusTarget_guess* statusTarget_016c_guess;
    StatusTarget_guess* statusTarget_0170_guess;
    StatusTarget_guess* statusTarget_0174_guess;
    void* filterCombo_0178_guess;
    void* itemListSecond_017c_guess;
    StatusTarget_guess* statusTarget_0180_guess;
    StatusTarget_guess* statusTarget_0184_guess;
    Widget_guess* widget_0188_guess;
    Widget_guess* widget_018c_guess;
    Widget_guess* widget_0190_guess;
    unsigned char unknown_0194_guess[4];
    unsigned char depositItems_guess[0x1130];
    unsigned char mainItems_guess[0xABE0];
    unsigned char depositListDirty_guess;
    unsigned char mainListDirty_guess;
    unsigned char unknown_BEAA_guess[2];
    int depositCount_beac_guess;
    int mainCount_beb0_guess;
    unsigned int selectedSlot_beb4_guess;
    unsigned int quantityMode_beb8_guess;
    unsigned int filterMode_bebc_guess;
    unsigned char* GetItem_guess(unsigned int value_guess);
    void SendPermissionChange_guess(unsigned int unknown_guess, int kind_guess, const char* text_guess);
    void SendWithdraw_guess(unsigned int unknown_guess, int value_guess);
    void Reset_guess();
    char AboutToHide_guess();
    void MarkListDirty_guess(PackedValue_guess value);
    void SendViewItem_guess();
    // EXTERNAL: TITANIUM 0x005A1EF0 CGuildBankWndView_guess::LoadIniListWnd
    void LoadIniListWnd(void* itemList_guess, const char* name_guess);
    // EXTERNAL: TITANIUM 0x005A1FE0 CGuildBankWndView_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(void* itemList_guess, const char* name_guess);
    void DumpRecord_guess(FILE* file_guess, Record_guess* record_guess, const char* tag_guess);
    void SaveGuildBank_guess(const char* filename_guess);
    void LoadIniSettings_guess();
    void StoreIniSettings_guess();
    void ProcessRecords_guess(RecordStream_guess* stream_guess);
    void ApplySelection_guess(unsigned int value_guess);
    char MatchesFilter_guess(TypeEntry_guess* entry_guess, int mode_guess);
    char CanWithdraw_guess(TypeEntry_guess* entry_guess);
    void FillRow_guess(CListWnd* list_guess, int row_guess, TypeEntry_guess* entry_guess, bool flag_guess);
    void RefillSecondList_guess();
    void HandleMessage_guess(unsigned int unknown_guess, struct ResetMessage_guess* message_guess, int flags_guess);
    void UpdateItem_guess(unsigned int value_guess);
    void UpdateButtons_guess();
    // EXTERNAL: TITANIUM 0x0050D898 CGuildBankWndView_guess::RefillFirstList_guess
    void RefillFirstList_guess();
};

struct ResetObserver_guess : Widget_guess {
    unsigned char unknown_0004_guess[0x58];
    unsigned char active_005c_guess;
    unsigned char unknown_005d_guess[0x10b];
    CGuildBankWndView_guess* activeState_0168_guess;
    // EXTERNAL: TITANIUM 0x00560D80 ResetObserver_guess::GetEntryText_guess
    CXStr GetEntryText_guess();
    // EXTERNAL: TITANIUM 0x00560E32 ResetObserver_guess::Activate_guess
    void Activate_guess(void* owner_guess, int type_guess, const char* text_guess,
                       int zero_guess, int capacity_guess, const char* source_guess);
};

#define pinstCTextEntryWnd_guess EQ_GLOBAL(ResetObserver_guess*, 0x00850C80)

struct TypeNameOffset_guess {
    unsigned char unknown_0000_guess[4];
    unsigned int vbaseOffset_0004_guess;
};

struct TypeState_guess {
    unsigned char unknown_0000_guess[8];
    TypeNameOffset_guess* names_0008_guess;
    unsigned char unknown_000c_guess[0x38];
    char names_0044_guess[1];
    unsigned char unknown_0045_guess[0xdcf];
    unsigned char active_0e14_guess;
};

struct TypeStateTail_guess {
    // EXTERNAL: TITANIUM 0x00417A1D TypeStateTail_guess::RemoveInvisibility_guess
    void RemoveInvisibility_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041DE16 TypeStateTail_guess::GetItemBySlot_guess
    int GetItemBySlot_guess(int value_guess);
};

struct PooledObject_guess {
    virtual void Release_guess(int flags_guess);
};

struct TypeStateRoot_guess {
    unsigned char unknown_0000_guess[0xe14];
    unsigned char active_0e14_guess;
    unsigned char unknown_0e15_guess[0xb46b];
    TypeStateTail_guess tail_0c280_guess;
    unsigned char unknown_0c281_guess[0xb];
    unsigned char flag_0c28c_guess;
    // EXTERNAL: TITANIUM 0x004BE443 TypeStateRoot_guess::GetItemSlotPointer_guess
    PooledObject_guess** GetItemSlotPointer_guess(int id_guess);
};

struct LocalizationManager_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 LocalizationManager_guess::GetField_guess
    int GetField_guess(const unsigned char* source_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* buffer_guess, int id_guess, int value_guess,
                              int zero1_guess, int zero2_guess, int zero3_guess,
                              int zero4_guess, int zero5_guess, int zero6_guess,
                              int zero7_guess, int zero8_guess);

struct PopupManager_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A PopupManager_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049994C PopupManager_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value_guess);
};

struct LoginWindow_guess {
    // EXTERNAL: TITANIUM 0x005A0A80 LoginWindow_guess::ResetChildren_guess
    void ResetChildren_guess(int first_guess, int second_guess);
    void Activate_guess(const unsigned char* resource_guess);
};

#define g_localizationManager_guess EQ_GLOBAL(LocalizationManager_guess*, 0x00988DF0)
#define g_popupManager_guess EQ_GLOBAL(PopupManager_guess, 0x00923770)
#define g_extendedTypeState_guess EQ_GLOBAL(TypeStateRoot_guess*, 0x00905D00)

struct TypeEntry_guess {
    unsigned char unknown_0000_guess[8];
    int value_0008_guess;
    int value_000c_guess;
    int quantity_0010_guess;
    int kind_0014_guess;
    unsigned char unknown_0018_guess;
    unsigned char active_0019_guess;
    char text_001a_guess[0x40];
    char text_005a_guess[0x40];
    char name_009a_guess[1];
};

struct StreamOutputEntry_guess {
    int value_0000_guess;
    unsigned char unknown_0004_guess[0xd8];
};

#define g_typeState_guess EQ_GLOBAL(TypeState_guess*, 0x00905D00)

struct SelectedEntry_guess {
    unsigned char unknown_0000_guess[8];
    int value_0008_guess;
};

struct UpdateStatusFlags_guess {
    char ordinaryEntry_guess;
    char noMessages_guess;
    char stateEnabled_guess;
};

union MessagePayloadC8_guess {
    int kind_0010_guess;
    char text_0010_guess[64];
};

struct MessageC8_guess {
    int code_0000_guess;
    int unknown_0004_guess;
    unsigned int source_0008_guess;
    int value_000c_guess;
    MessagePayloadC8_guess payload_0010_guess;
    int unknown_0050_guess;
};

struct MessageC956_guess {
    int code_0000_guess;
    int unknown_0004_guess;
    unsigned int source_0008_guess;
    int value_000c_guess;
    int argument_0010_guess;
};

struct RecordStream_guess {
    unsigned char unknown_0000_guess[8];
    int firstCount_0008_guess;
    int secondCount_000c_guess;
    char records_0010_guess[1];
};

// EXTERNAL: TITANIUM 0x0050C673 IsMainAreaSlot_external_guess
int __cdecl IsMainAreaSlot_external_guess(unsigned int param_1);
// EXTERNAL: TITANIUM 0x0050C68F IsDepositAreaSlot_external_guess
int __cdecl IsDepositAreaSlot_external_guess(PackedValue_guess param_1);
// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination_guess, const char* source_guess);

struct GuildBankRoot_guess {
    unsigned char unknown_0000_guess[0x120];
    char name_0120_guess[0x100];
};

#define g_guildBankRoot_guess EQ_GLOBAL(GuildBankRoot_guess*, 0x00905CE4)
#define g_messageConnection_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_pendingGuildBankRequests_guess EQ_GLOBAL(int, 0x009248D0)

// EXTERNAL: TITANIUM 0x00577000 FUN_00577000_guess
void __cdecl FUN_00577000_guess(char* buffer_guess, int size_guess, const char* format_guess, ...);
#define g_messageDispatcher_guess EQ_GLOBAL(MessageDispatcher_guess*, 0x00851390)
#define g_guildBanker_guess EQ_GLOBAL(int, 0x00905D14)

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Marks the list that holds slot key `value` for a refill: +0xBEA9 main, +0xBEA8 deposit. The two
// "initialized" bytes are really these dirty flags (Reset_guess sets both).
// FUNCTION: TITANIUM 0x0050C840
void CGuildBankWndView_guess::MarkListDirty_guess(PackedValue_guess value) {
    if ((char)IsMainAreaSlot_external_guess(value.whole)) {
        this->mainListDirty_guess = 1;
    } else if ((char)IsDepositAreaSlot_external_guess(value)) {
        this->depositListDirty_guess = 1;
    }
}

// True for a main-area slot key (area 1 in the high word); -1 means no selection.
// FUNCTION: TITANIUM 0x0050C673
int __cdecl IsMainAreaSlot_guess(unsigned int param_1) {
    if (param_1 != 0xffffffff && (param_1 & 0xffff0000) == 0x10000) {
        return true;
    }
    return false;
}

// True for a deposit-area slot key (area 0).
// FUNCTION: TITANIUM 0x0050C68F
int __cdecl IsDepositAreaSlot_guess(PackedValue_guess param_1) {
    if (param_1.whole == 0xffffffff || (param_1.whole & 0xffff0000) != 0) {
        return 0;
    }
    return 1;
}

// The 0xDC-byte record of slot key `value_guess`; 0 for -1 and unknown areas.
// FUNCTION: TITANIUM 0x0050C873
unsigned char* CGuildBankWndView_guess::GetItem_guess(unsigned int value_guess) {
    PackedValue_guess packed_guess;
    packed_guess.whole = value_guess;
    unsigned char* result_guess = 0;
    if ((char)IsMainAreaSlot_external_guess(value_guess)) {
        result_guess = this->mainItems_guess + (value_guess & 0xffff) * 0xdc;
    } else if ((char)IsDepositAreaSlot_external_guess(packed_guess)) {
        result_guess = this->depositItems_guess + (value_guess & 0xffff) * 0xdc;
    }
    return result_guess;
}

// Action 6 (EQEmu GuildBankPermissions_Struct): sets the selected item's permission to `kind_guess`
// (0 banker only, 1 one member, named by `text_guess`, 2 public if usable, 3 public). The first argument
// is unused; each request bumps the pending count 0x9248D0, which the acks bring down.
// FUNCTION: TITANIUM 0x0050C8C4
void CGuildBankWndView_guess::SendPermissionChange_guess(unsigned int unknown_guess, int kind_guess, const char* text_guess) {
    unsigned int value_guess = this->selectedSlot_beb4_guess;
    unsigned char* selected_guess = this->GetItem_guess(value_guess);
    MessageC8_guess message_guess;
    memset(&message_guess, 0, 0x54);
    message_guess.payload_0010_guess.kind_0010_guess = kind_guess;
    message_guess.value_000c_guess = ((SelectedEntry_guess*)selected_guess)->value_0008_guess;
    message_guess.code_0000_guess = 6;
    message_guess.source_0008_guess = this->selectedSlot_beb4_guess;
    if (kind_guess == 1 && text_guess != 0) {
        FUN_0060e450_guess(message_guess.payload_0010_guess.text_0010_guess + 4, text_guess);
    }
    EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x54, 1);
    ++g_pendingGuildBankRequests_guess;
}

// Action 7: withdraws `value_guess` of the selected item (EQEmu GuildBankWithdrawItem_Struct).
// FUNCTION: TITANIUM 0x0050C956
void CGuildBankWndView_guess::SendWithdraw_guess(unsigned int unknown_guess, int value_guess) {
    unsigned int source_guess = this->selectedSlot_beb4_guess;
    unsigned char* selected_guess = this->GetItem_guess(source_guess);
    MessageC956_guess message_guess;
    if (selected_guess != 0) {
        message_guess.code_0000_guess = 7;
        message_guess.argument_0010_guess = value_guess;
        message_guess.source_0008_guess = source_guess;
        message_guess.value_000c_guess = ((SelectedEntry_guess*)selected_guess)->value_0008_guess;
        EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x14, 1);
        ++g_pendingGuildBankRequests_guess;
    }
}

struct VoidConnectionMessage_guess {
    int code_0000_guess;
    int unknown_0004_guess;
    unsigned int source_0008_guess;
    int value_000c_guess;
    int noConnection_0010_guess;
};

struct DecodedRecord_guess {
    int unknown_0000_guess;
    bool present_0004_guess;
    char unknown_0005_guess[3];
    int value_0008_guess;
    int value_000c_guess;
    int value_0010_guess;
    int value_0014_guess;
    char unknown_0018_guess;
    char unknown_0019_guess;
    char text_001a_guess[0x40];
    char text_005a_guess[0x40];
    char text_009a_guess[0x80];
};

struct RecordCodec_guess {
    int Read_guess(const int* source_guess, DecodedRecord_guess* destination_guess);
};

// Loads both lists' column settings (CSidlScreenWnd::LoadIniListWnd) and the layout from the INI;
// StoreIniSettings_guess stores them on deactivate.
// FUNCTION: TITANIUM 0x0050CC31
void CGuildBankWndView_guess::LoadIniSettings_guess() {
    if (this->itemListFirst_015c_guess != 0) {
        this->LoadIniListWnd(this->itemListFirst_015c_guess, "ItemList");
    }
    if (this->itemListSecond_017c_guess != 0) {
        this->LoadIniListWnd(this->itemListSecond_017c_guess, "ItemList");
    }
    if (this->widget_0190_guess != 0) {
        this->widget_0190_guess->Slot73_guess(this->layout_0140_guess.Find_guess("MainLayout"));
    }
}

// StoreIniInfo side: saves both item lists under ItemList through the list INI store (0x005A1FE0) and
// the MainLayout setting.
// FUNCTION: TITANIUM 0x0050CC8B
void CGuildBankWndView_guess::StoreIniSettings_guess() {
    if (this->itemListFirst_015c_guess != 0) {
        this->StoreIniListWnd_guess(this->itemListFirst_015c_guess, "ItemList");
    }
    if (this->itemListSecond_017c_guess != 0) {
        this->StoreIniListWnd_guess(this->itemListSecond_017c_guess, "ItemList");
    }
    if (this->widget_0190_guess != 0) {
        this->widget_0190_guess->Slot74_guess(this->layout_0140_guess.Find_guess("MainLayout"));
    }
}

// Action 4: asks to inspect the selected item. The last field is 1 unless keyboard flag bit 0 (probably
// Shift) is held.
// FUNCTION: TITANIUM 0x0050C9A8
void CGuildBankWndView_guess::SendViewItem_guess() {
    unsigned int source_guess = this->selectedSlot_beb4_guess;
    unsigned char* selected_guess = this->GetItem_guess(source_guess);
    if (selected_guess != 0) {
        VoidConnectionMessage_guess message_guess;
        message_guess.value_000c_guess = ((SelectedEntry_guess*)selected_guess)->value_0008_guess;
        message_guess.source_0008_guess = source_guess;
        message_guess.code_0000_guess = 4;
        message_guess.noConnection_0010_guess = ~pinstCXWndManager_guess->GetKeyboardFlags() & 1;
        EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x14, 1);
    }
}

// Decodes one bulk-list entry into a record and returns its size: present flag, then (if present)
// permission, WhoFor, donator, item id, icon, count, can-merge and usable bytes, item name, as in EQEmu
// GuildBankItemListEntry_Struct. Record: +8 item id, +0xC icon, +0x10 count, +0x14 permission,
// +0x18 can merge, +0x19 usable, +0x1A name, +0x5A donator, +0x9A WhoFor.
// FUNCTION: TITANIUM 0x0050C9FF
int RecordCodec_guess::Read_guess(const int* source_guess, DecodedRecord_guess* destination_guess) {
    bool present_guess = source_guess[0] != 0;
    destination_guess->present_0004_guess = present_guess;
    const char* cursor_guess = (const char*)(source_guess + 1);
    if (present_guess) {
        destination_guess->value_0014_guess = *(const int*)cursor_guess;
        cursor_guess += 4;
        FUN_0060e450_guess(destination_guess->text_009a_guess, cursor_guess);
        cursor_guess += strlen(cursor_guess) + 1;
        FUN_0060e450_guess(destination_guess->text_005a_guess, cursor_guess);
        cursor_guess += strlen(cursor_guess) + 1;
        destination_guess->value_0008_guess = *(const int*)cursor_guess;
        cursor_guess += 4;
        destination_guess->value_000c_guess = *(const int*)cursor_guess;
        cursor_guess += 4;
        destination_guess->value_0010_guess = *(const int*)cursor_guess;
        cursor_guess += 4;
        destination_guess->unknown_0018_guess = cursor_guess[0];
        ++cursor_guess;
        destination_guess->unknown_0019_guess = cursor_guess[0];
        ++cursor_guess;
        FUN_0060e450_guess(destination_guess->text_001a_guess, cursor_guess);
        cursor_guess += strlen(cursor_guess) + 1;
    }
    return (int)(cursor_guess - (const char*)source_guess);
}

// Button states, all off while a request is pending (0x9248D0). Deposit: fewer than 20 deposits and an
// item on the cursor (slot 30, probably); view: any selection; permission, change-member (permission 1),
// merge (+0x18) and split (count > 1): a main-area item and the banker flag (pCharData +0xE14 bit 0);
// promote: a deposit item and the banker flag. Withdraw is only switched off here (see ApplySelection_guess).
// FUNCTION: TITANIUM 0x0050CA92
// @early-stop: unknown, structural ndiff=224
void CGuildBankWndView_guess::UpdateButtons_guess() {
    char stateMode_guess;
    TypeStateRoot_guess* typeState_guess = g_extendedTypeState_guess;
    UpdateStatusFlags_guess flags_guess;
    flags_guess.noMessages_guess = g_pendingGuildBankRequests_guess == 0;
    flags_guess.stateEnabled_guess = typeState_guess->active_0e14_guess & 1;
    stateMode_guess = typeState_guess->tail_0c280_guess.GetItemBySlot_guess(0x1e) != 0;
    PackedValue_guess packed_guess;
    packed_guess.whole = this->selectedSlot_beb4_guess;
    TypeEntry_guess* entry_guess = (TypeEntry_guess*)this->GetItem_guess(packed_guess.whole);
    flags_guess.ordinaryEntry_guess = 0;
    if (entry_guess != 0) {
        flags_guess.ordinaryEntry_guess = 1;
        if (!(char)IsDepositAreaSlot_guess(packed_guess)) {
            flags_guess.ordinaryEntry_guess = 0;
        }
    }
    char specialEntry_guess = 0;
    if (entry_guess != 0 && (char)IsMainAreaSlot_guess(packed_guess.whole)) {
        specialEntry_guess = 1;
    }

    if (this->statusTarget_0180_guess != 0) {
        char active_guess = 0;
        if (this->depositCount_beac_guess < 0x14 && stateMode_guess != 0 && flags_guess.noMessages_guess) {
            active_guess = 1;
        }
        this->statusTarget_0180_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_0164_guess != 0) {
        char active_guess = 0;
        if (flags_guess.noMessages_guess && entry_guess != 0) {
            active_guess = 1;
        }
        this->statusTarget_0164_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_0160_guess != 0 && this->statusTarget_0160_guess->active_005d_guess != 0 &&
        (entry_guess == 0 || !flags_guess.noMessages_guess)) {
        this->statusTarget_0160_guess->active_005d_guess = 0;
    }
    if (this->selectionTarget_0168_guess != 0) {
        char active_guess = 0;
        if (specialEntry_guess && flags_guess.stateEnabled_guess && flags_guess.noMessages_guess) {
            active_guess = 1;
        }
        this->selectionTarget_0168_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_016c_guess != 0) {
        char active_guess = 0;
        if (flags_guess.stateEnabled_guess && flags_guess.noMessages_guess && specialEntry_guess &&
            entry_guess->kind_0014_guess == 1) {
            active_guess = 1;
        }
        this->statusTarget_016c_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_0170_guess != 0) {
        char active_guess = 0;
        if (flags_guess.stateEnabled_guess && flags_guess.noMessages_guess && specialEntry_guess &&
            entry_guess->unknown_0018_guess != 0) {
            active_guess = 1;
        }
        this->statusTarget_0170_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_0174_guess != 0) {
        char active_guess = 0;
        if (flags_guess.stateEnabled_guess && flags_guess.noMessages_guess && specialEntry_guess &&
            entry_guess->quantity_0010_guess > 1) {
            active_guess = 1;
        }
        this->statusTarget_0174_guess->active_005d_guess = active_guess;
    }
    if (this->statusTarget_0184_guess != 0) {
        char active_guess = 0;
        if (flags_guess.noMessages_guess && flags_guess.ordinaryEntry_guess &&
            flags_guess.stateEnabled_guess) {
            active_guess = 1;
        }
        this->statusTarget_0184_guess->active_005d_guess = active_guess;
    }
}

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850), 0x158 bytes.
struct BaseObject_guess {
    virtual void Slot00_guess();
    char pad_0004_guess[0x60];
    unsigned int windowStyle_0064_guess;
    char pad_0068_guess[0xbc];
    void* sidlPiece_0124_guess;
    char pad_0128_guess[0x30];
    // EXTERNAL: TITANIUM 0x005A3850 BaseObject_guess::BaseObject_guess
    BaseObject_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 BaseObject_guess::~BaseObject_guess
    ~BaseObject_guess() ;
};

// A list child as this window configures it (fields past CListWnd 0x140).
struct GuildBankList_guess : CListWnd {
    char pad_140[0x14];
    int field_154;
    char pad_158;
    unsigned char field_159;
    char pad_15a[2];
    unsigned char field_15c;
    char pad_15d[3];
    int field_160;
    char pad_164[8];
    unsigned int color_16c;
    void SetRowHeight(int height) {
        field_159 = 1;
        field_160 = height;
    }
    // EXTERNAL: TITANIUM 0x005981F0 GuildBankList_guess::SetColumnWidth_guess
    void SetColumnWidth_guess(int column, int width);
};

// EXTERNAL: TITANIUM 0x00655880 ??_7CGuildBankWnd_guess@@6B@
struct CGuildBankWnd_guess : BaseObject_guess {
    int field_158_guess;
    GuildBankList_guess* itemList_015c_guess;
    CXWnd* withdrawButton_0160_guess;
    CXWnd* viewItemButton_0164_guess;
    SelectionTarget_guess* permissionCombo_0168_guess;
    CXWnd* changeTargetButton_016c_guess;
    CXWnd* mergeButton_0170_guess;
    CXWnd* splitButton_0174_guess;
    SelectionTarget_guess* filterCombo_0178_guess;
    GuildBankList_guess* depositList_017c_guess;
    CXWnd* depositButton_0180_guess;
    CXWnd* promoteButton_0184_guess;
    CXWnd* bankCountLabel_0188_guess;
    CXWnd* depositCountLabel_018c_guess;
    CXWnd* layout_0190_guess;
    int field_0194_guess;
    unsigned char resetState_0198_guess[0xbeb4 - 0x198];
    unsigned int value_BEB4_guess;
    unsigned int value_BEB8_guess;
    unsigned int value_BEBC_guess;

    CGuildBankWnd_guess(CXWnd* parent);
    CGuildBankWnd_guess* Destroy_guess(unsigned char flags);
    int OnProcessFrame_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
    ~CGuildBankWnd_guess() ;
};

// Destructor of the guild bank window (vtable 0x655880): restores its vtable and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x0050C6A6
CGuildBankWnd_guess::~CGuildBankWnd_guess()  {}

// Clears both record arrays and marks both lists dirty.
// FUNCTION: TITANIUM 0x0050C7B3
void CGuildBankWndView_guess::Reset_guess() {
    memset(this->depositItems_guess, 0, sizeof(this->depositItems_guess));
    memset(this->mainItems_guess, 0, sizeof(this->mainItems_guess));
    this->depositListDirty_guess = 1;
    this->mainListDirty_guess = 1;
}

struct Record_guess {
    int unknown_0000_guess;
    bool present_0004_guess;
    char unknown_0005_guess[3];
    int value_0008_guess;
    int value_000c_guess;
    int value_0010_guess;
    int type_0014_guess;
    char unknown_0018_guess[2];
    char name_001a_guess[0x40];
    char text_005a_guess[0x40];
    char inlineName_009a_guess[0x40];
    char unknown_00da_guess[2];
};

#define g_stringIds_guess EQ_ARRAY(int, 0x00792A94)
// Opening the bank at banker `resource_guess` (kept in 0x905D14): prints string 0x5B9 with the banker's
// name, turns off auto attack (0x9858C7, string 0x5BA) and auto fire (0x9858C8, string 0x117), then
// shows the window. LoginWindow_guess is a misnamed view of CGuildBankWnd.
// FUNCTION: TITANIUM 0x0050C6B1
void LoginWindow_guess::Activate_guess(const unsigned char* resource_guess) {
    char buffer_guess[1024];
    g_guildBanker_guess = (int)resource_guess;
    FormatText_guess(buffer_guess, 0x5b9,
                     g_localizationManager_guess->GetField_guess(resource_guess + 0x120),
                     0, 0, 0, 0, 0, 0, 0, 0);
    pEverQuest->dsp_chat(buffer_guess);
    if (EQ_GLOBAL(char, 0x009858C7) != 0) {
        g_popupManager_guess.SetAutoAttack_guess(0);
        ((CEverQuest*)pEverQuest)->dsp_chat(
            pStringTable->getString(0x5ba, 0), 0xd, 1);
    }
    if (EQ_GLOBAL(char, 0x009858C8) != 0) {
        g_popupManager_guess.SetAutoFire_guess(0);
        ((CEverQuest*)pEverQuest)->dsp_chat(
            pStringTable->getString(0x117, 0), 0xd, 1);
    }
    g_messageDispatcher_guess->SetMusicSelection_guess(3, 1);
    g_extendedTypeState_guess->tail_0c280_guess.RemoveInvisibility_guess(0);
    this->ResetChildren_guess(1, 1);
}

// One tab-separated dump line; the permission column is the member name for permission 1, else the
// permission's string (ids at 0x792A94).
// FUNCTION: TITANIUM 0x0050C7EF
void CGuildBankWndView_guess::DumpRecord_guess(FILE* file_guess, Record_guess* record_guess, const char* tag_guess) {
    if (record_guess != 0) {
        const char* text_guess;
        if (record_guess->type_0014_guess == 1) {
            text_guess = record_guess->inlineName_009a_guess;
        } else {
            text_guess = pStringTable->getString(g_stringIds_guess[record_guess->type_0014_guess], 0);
        }
        fprintf(file_guess, "%s\t%s\t%d\t%d\t%s\n", tag_guess, record_guess->name_001a_guess,
                record_guess->value_0008_guess, record_guess->value_0010_guess, text_guess);
    }
}

// Both lists get four columns (icon, name, count, then permission or donator) and 24-pixel rows; the
// permission combo lists the four permission strings.
// FUNCTION: TITANIUM 0x0050CCE5
CGuildBankWnd_guess::CGuildBankWnd_guess(CXWnd* parent)
    : BaseObject_guess(parent, "GuildBankWnd", -1, 1, 0) {
    value_BEB4_guess = -1;
    itemList_015c_guess = 0;
    withdrawButton_0160_guess = 0;
    viewItemButton_0164_guess = 0;
    permissionCombo_0168_guess = 0;
    changeTargetButton_016c_guess = 0;
    mergeButton_0170_guess = 0;
    splitButton_0174_guess = 0;
    depositList_017c_guess = 0;
    depositButton_0180_guess = 0;
    promoteButton_0184_guess = 0;
    layout_0190_guess = 0;
    filterCombo_0178_guess = 0;
    bankCountLabel_0188_guess = 0;
    depositCountLabel_018c_guess = 0;
    field_0194_guess = 0;
    value_BEB8_guess = 0;
    value_BEBC_guess = 0;
    ((CGuildBankWndView_guess*)this)->Reset_guess();
    if (sidlPiece_0124_guess != 0) {
        windowStyle_0064_guess |= 0x10000;
        field_158_guess = 0x3e;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        itemList_015c_guess = (GuildBankList_guess*)((CSidlScreenWnd*)this)->GetChildItem("ItemList");
        withdrawButton_0160_guess = ((CSidlScreenWnd*)this)->GetChildItem("WithdrawButton");
        viewItemButton_0164_guess = ((CSidlScreenWnd*)this)->GetChildItem("ViewItemButton");
        permissionCombo_0168_guess =
            (SelectionTarget_guess*)((CSidlScreenWnd*)this)->GetChildItem("PermissionCombo");
        changeTargetButton_016c_guess = ((CSidlScreenWnd*)this)->GetChildItem("ChangeTargetButton");
        splitButton_0174_guess = ((CSidlScreenWnd*)this)->GetChildItem("SplitButton");
        mergeButton_0170_guess = ((CSidlScreenWnd*)this)->GetChildItem("MergeButton");
        filterCombo_0178_guess =
            (SelectionTarget_guess*)((CSidlScreenWnd*)this)->GetChildItem("FilterCombo");
        depositList_017c_guess = (GuildBankList_guess*)((CSidlScreenWnd*)this)->GetChildItem("DepositList");
        depositButton_0180_guess = ((CSidlScreenWnd*)this)->GetChildItem("DepositButton");
        promoteButton_0184_guess = ((CSidlScreenWnd*)this)->GetChildItem("PromoteButton");
        depositCountLabel_018c_guess = ((CSidlScreenWnd*)this)->GetChildItem("DepositCountLabel");
        bankCountLabel_0188_guess = ((CSidlScreenWnd*)this)->GetChildItem("BankCountLabel");
        layout_0190_guess = ((CSidlScreenWnd*)this)->GetChildItem("Layout");
        if (itemList_015c_guess != 0) {
            itemList_015c_guess->SetColors(-1, 0xffffff00, 0xff808080);
            itemList_015c_guess->SetColumnJustification(0, 1);
            itemList_015c_guess->SetColumnJustification(1, 0);
            itemList_015c_guess->SetColumnJustification(2, 1);
            itemList_015c_guess->SetColumnJustification(3, 0);
            itemList_015c_guess->color_16c = 0xff8aa3ff;
            itemList_015c_guess->field_15c = 1;
            itemList_015c_guess->SetRowHeight(0x18);
            itemList_015c_guess->SetColumnWidth_guess(0, 0x18);
            itemList_015c_guess->WindowStyle |= 0x40000;
            itemList_015c_guess->field_154 = 1;
        }
        if (depositList_017c_guess != 0) {
            depositList_017c_guess->SetColors(-1, 0xffffff00, 0xff808080);
            depositList_017c_guess->SetColumnJustification(0, 1);
            depositList_017c_guess->SetColumnJustification(1, 0);
            depositList_017c_guess->SetColumnJustification(2, 1);
            depositList_017c_guess->SetColumnJustification(3, 0);
            depositList_017c_guess->color_16c = 0xff8aa3ff;
            depositList_017c_guess->field_15c = 1;
            depositList_017c_guess->SetRowHeight(0x18);
            depositList_017c_guess->SetColumnWidth_guess(0, 0x18);
            depositList_017c_guess->WindowStyle |= 0x40000;
            depositList_017c_guess->field_154 = 1;
        }
        if (permissionCombo_0168_guess != 0) {
            int* id_guess = g_stringIds_guess;
            do {
                permissionCombo_0168_guess->AddString_guess(pStringTable->getString(*id_guess, 0));
                ++id_guess;
            } while ((int)id_guess < (int)EQ_ARRAY(int, 0x00792AA4));
            permissionCombo_0168_guess->SetValue_guess(0);
        }
        if (filterCombo_0178_guess != 0) {
            filterCombo_0178_guess->SetValue_guess(value_BEBC_guess);
        }
        ((CGuildBankWndView_guess*)this)->LoadIniSettings_guess();
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Scalar deleting destructor of the guild bank window (vtable 0x655880 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x0050D2BF
CGuildBankWnd_guess* CGuildBankWnd_guess::Destroy_guess(unsigned char flags) {
    this->~CGuildBankWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// AboutToHide (vtable slot 50): stores the INI settings, closes an open quantity window and forgets the
// banker (0x905D14).
// FUNCTION: TITANIUM 0x0050D2ED
char CGuildBankWndView_guess::AboutToHide_guess() {
    this->StoreIniSettings_guess();
    if (this->quantityMode_beb8_guess != 0 && pinstCQuantityWnd_guess != 0 &&
        pinstCQuantityWnd_guess->IsVisible_guess()) {
        pinstCQuantityWnd_guess->Deactivate();
    }
    g_messageDispatcher_guess->SetMusicSelection_guess(3, 0);
    g_guildBanker_guess = 0;
    return 1;
}

// Dumps the bank to `filename_guess`, by default <name>-GuildBank.txt with the player's name (0x905CE4 is
// the player spawn, +0x120 Name): main slots as Bank-001.., deposits as Deposit-01..
// FUNCTION: TITANIUM 0x0050D339
void CGuildBankWndView_guess::SaveGuildBank_guess(const char* filename_guess) {
    int index_guess;
    char path_guess[512];
    char tag_guess[256];
    if (filename_guess == 0 || *filename_guess == 0) {
        sprintf(path_guess, "%s-GuildBank.txt", g_guildBankRoot_guess->name_0120_guess);
        filename_guess = path_guess;
    }
    FILE* file_guess = fopen(filename_guess, "w");
    if (file_guess != 0) {
        fprintf(file_guess, "Location\tName\tID\tCount\tPermission\n");
        for (index_guess = 0; index_guess < 200; ++index_guess) {
            Record_guess* record_guess = &((Record_guess*)this->mainItems_guess)[index_guess];
            if (record_guess->present_0004_guess) {
                FUN_00577000_guess(tag_guess, 0x100, "Bank-%03d", index_guess + 1);
                this->DumpRecord_guess(file_guess, record_guess, tag_guess);
            }
        }
        for (index_guess = 0; index_guess < 20; ++index_guess) {
            Record_guess* record_guess = &((Record_guess*)this->depositItems_guess)[index_guess];
            if (record_guess->present_0004_guess) {
                FUN_00577000_guess(tag_guess, 0x100, "Deposit-%02d", index_guess + 1);
                this->DumpRecord_guess(file_guess, record_guess, tag_guess);
            }
        }
        fclose(file_guess);
    }
}

struct GlobalHandler_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 GlobalHandler_guess::GetIcon_guess
    int GetIcon_guess(int value_guess);
};

#define g_transform_guess EQ_GLOBAL(GlobalHandler_guess*, 0x00991910)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// Fills row `row_guess`: icon, name, count, then the donator (`flag_guess`: deposit list) or the
// permission; items the player may not withdraw are tinted 0xFFC8A0A0.
// FUNCTION: TITANIUM 0x0050D553
void CGuildBankWndView_guess::FillRow_guess(CListWnd* list_guess, int row_guess, TypeEntry_guess* entry_guess, bool flag_guess) {
    EQ_METHOD(3, void, 0x0059B2E0, (CListWnd, int, int, unsigned int), list_guess)(
        row_guess, 0, g_transform_guess->GetIcon_guess(entry_guess->value_000c_guess));
    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
        row_guess, 1, entry_guess->text_001a_guess);
    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
        row_guess, 2, _itoa(entry_guess->quantity_0010_guess, g_itoaBuffer_guess, 10));
    if (flag_guess) {
        EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(
            row_guess, 3, entry_guess->text_005a_guess);
    } else {
        unsigned int color_guess = 0xffc8a0a0;
        if (this->CanWithdraw_guess(entry_guess)) {
            color_guess = 0xffffffff;
        }
        const char* name_guess;
        if (entry_guess->kind_0014_guess == 1) {
            name_guess = entry_guess->name_009a_guess;
        } else {
            name_guess = pStringTable->getString(g_stringIds_guess[entry_guess->kind_0014_guess], 0);
        }
        EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&), list_guess)(row_guess, 3, name_guess);
        EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int), list_guess)(row_guess, 1, color_guess);
        EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int), list_guess)(row_guess, 2, color_guess);
        EQ_METHOD(3, void, 0x0059B3E0, (CListWnd, int, int, unsigned int), list_guess)(row_guess, 3, color_guess);
    }
}

// Whether the player may withdraw the item: public (3) always, public if usable (2) when +0x19 is set,
// one member (1) when it names this character; the banker flag allows everything.
// FUNCTION: TITANIUM 0x0050D465
char CGuildBankWndView_guess::CanWithdraw_guess(TypeEntry_guess* entry_guess) {
    TypeState_guess* state_guess = g_typeState_guess;
    char active_guess = state_guess->active_0e14_guess & 1;
    if (entry_guess == 0) {
        return 0;
    }

    int kind_guess = entry_guess->kind_0014_guess;
    if (kind_guess == 3) {
        active_guess = 1;
    } else if (kind_guess == 2) {
        if (active_guess != 0 || entry_guess->active_0019_guess != active_guess) {
            active_guess = 1;
        } else {
            active_guess = 0;
        }
    } else if (kind_guess == 1) {
        if (active_guess != 0 ||
            strcmp((const char*)state_guess + 0x44 +
                       state_guess->names_0008_guess->vbaseOffset_0004_guess,
                   entry_guess->name_009a_guess) == 0) {
            active_guess = 1;
        } else {
            active_guess = 0;
        }
    }
    return active_guess;
}

// Action 0 (bulk list): `stream_guess` +8 deposit count, +0xC main count, then the packed entries; each
// record keeps its slot key at +0.
// FUNCTION: TITANIUM 0x0050D4C6
void CGuildBankWndView_guess::ProcessRecords_guess(RecordStream_guess* stream_guess) {
    char* cursor_guess = stream_guess->records_0010_guess;
    this->Reset_guess();

    int index_guess = 0;
    if (stream_guess->firstCount_0008_guess > 0) {
        StreamOutputEntry_guess* entry_guess =
            (StreamOutputEntry_guess*)(this->depositItems_guess);
        do {
            entry_guess->value_0000_guess = index_guess;
            cursor_guess += ((RecordCodec_guess*)this)->Read_guess(
                (const int*)cursor_guess, (DecodedRecord_guess*)entry_guess);
            ++entry_guess;
            ++index_guess;
        } while (index_guess < stream_guess->firstCount_0008_guess);
    }

    index_guess = 0;
    if (stream_guess->secondCount_000c_guess > 0) {
        StreamOutputEntry_guess* entry_guess =
            (StreamOutputEntry_guess*)(this->mainItems_guess);
        do {
            entry_guess->value_0000_guess = index_guess + 0x10000;
            cursor_guess += ((RecordCodec_guess*)this)->Read_guess(
                (const int*)cursor_guess, (DecodedRecord_guess*)entry_guess);
            ++entry_guess;
            ++index_guess;
        } while (index_guess < stream_guess->secondCount_000c_guess);
    }
}

// FilterCombo modes: 1 banker only, 2 public, 3 public if usable, 4 withdrawable, 5 not withdrawable,
// else all.
// FUNCTION: TITANIUM 0x0050D6EB
char CGuildBankWndView_guess::MatchesFilter_guess(TypeEntry_guess* entry_guess, int mode_guess) {
    switch (mode_guess) {
    case 1:
        return entry_guess->kind_0014_guess == 0;
    case 2:
        return entry_guess->kind_0014_guess == 3;
    case 3:
        return entry_guess->kind_0014_guess == 2;
    case 4:
        return this->CanWithdraw_guess(entry_guess);
    case 5:
        return !this->CanWithdraw_guess(entry_guess);
    default:
        return 1;
    }
}

// Selects slot key `value_guess`: syncs the permission combo and the withdraw button, clears the other
// list's selection, and closes the quantity window (0x850C3C) and a name entry (0x850C80) opened here.
// FUNCTION: TITANIUM 0x0050D73E
void CGuildBankWndView_guess::ApplySelection_guess(unsigned int value_guess) {
    TypeEntry_guess* selected_guess = (TypeEntry_guess*)this->GetItem_guess(value_guess);
    if (this->selectionTarget_0168_guess != 0) {
        int selectionValue_guess = (int)selected_guess;
        if (selected_guess != 0) {
            selectionValue_guess = selected_guess->kind_0014_guess;
        }
        this->selectionTarget_0168_guess->SetValue_guess(selectionValue_guess);
    }
    if (this->statusTarget_0160_guess != 0) {
        this->statusTarget_0160_guess->active_005d_guess = this->CanWithdraw_guess(selected_guess);
    }
    PackedValue_guess packed_guess;
    packed_guess.whole = value_guess;
    if ((char)IsMainAreaSlot_external_guess(value_guess) && this->itemListSecond_017c_guess != 0) {
        ((CListWnd*)this->itemListSecond_017c_guess)->SetCurSel(-1);
    } else if ((char)IsDepositAreaSlot_external_guess(packed_guess) && this->itemListFirst_015c_guess != 0) {
        ((CListWnd*)this->itemListFirst_015c_guess)->SetCurSel(-1);
    }
    if (this->quantityMode_beb8_guess != 0 && pinstCQuantityWnd_guess != 0 &&
        pinstCQuantityWnd_guess->IsVisible_guess()) {
        pinstCQuantityWnd_guess->Deactivate();
    }
    if ((pinstCTextEntryWnd_guess->active_005c_guess ?
             pinstCTextEntryWnd_guess->activeState_0168_guess : 0) == this) {
        pinstCTextEntryWnd_guess->Slot34_guess();
    }
    this->selectedSlot_beb4_guess = value_guess;
}

// Action 1 for a present item: redraws its row in place, or marks its list dirty when it has no row.
// FUNCTION: TITANIUM 0x0050D80A
// @early-stop: budget, diff ndiff=38
void CGuildBankWndView_guess::UpdateItem_guess(unsigned int value_guess) {
    TypeEntry_guess* entry_guess = (TypeEntry_guess*)this->GetItem_guess(value_guess);
    PackedValue_guess packed_guess;
    packed_guess.whole = value_guess;
    char flag_guess = (char)IsDepositAreaSlot_external_guess(packed_guess);
    CListWnd* list_guess;
    if (flag_guess == 0) {
        list_guess = (CListWnd*)this->itemListFirst_015c_guess;
    } else {
        list_guess = (CListWnd*)this->itemListSecond_017c_guess;
    }
    if (list_guess != 0) {
        if (list_guess->ItemsCount > 0) {
            int index_guess = 0;
            do {
                if (list_guess->GetItemData(index_guess) == value_guess) {
                    this->FillRow_guess(list_guess, index_guess, entry_guess, flag_guess);
                    this->ApplySelection_guess(this->selectedSlot_beb4_guess);
                    return;
                }
                ++index_guess;
            } while (index_guess < list_guess->ItemsCount);
        }
        this->MarkListDirty_guess(packed_guess);
    }
}

// Rebuilds the main-area list (ItemList) through the filter; BankCountLabel shows string 0x17D3 with the
// free slots (200 minus all items, filtered or not).
// FUNCTION: TITANIUM 0x0050D898
// @early-stop: budget, diff ndiff=28
void CGuildBankWndView_guess::RefillFirstList_guess() {
    this->mainCount_beb0_guess = 0;
    if (this->itemListFirst_015c_guess != 0) {
        ((Widget_guess*)this->itemListFirst_015c_guess)->Slot76_guess();
        int index_guess;
        Record_guess* entry_guess;
        entry_guess = (Record_guess*)this->mainItems_guess;
        index_guess = 0;
        for (; index_guess < 200; ++index_guess, ++entry_guess) {
            if (entry_guess->present_0004_guess) {
                if (this->MatchesFilter_guess((TypeEntry_guess*)entry_guess, this->filterMode_bebc_guess)) {
                    int row_guess = ((CListWnd*)this->itemListFirst_015c_guess)->AddString(
                        CXStr(g_emptyString_guess), -1, index_guess + 0x10000, 0);
                    this->FillRow_guess((CListWnd*)this->itemListFirst_015c_guess, row_guess,
                                        (TypeEntry_guess*)entry_guess, false);
                }
                ++this->mainCount_beb0_guess;
            }
        }
    }
    if (this->widget_0188_guess != 0) {
        char buffer_guess[256];
        FormatText_guess(buffer_guess, 0x17d3,
                         (int)_itoa(200 - this->mainCount_beb0_guess, g_itoaBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
        CXStr message_guess(buffer_guess);
        this->widget_0188_guess->Slot63_guess(message_guess);
    }
    this->mainListDirty_guess = 0;
    if ((char)IsMainAreaSlot_external_guess(this->selectedSlot_beb4_guess)) {
        this->ApplySelection_guess(0xffffffff);
    }
    this->UpdateButtons_guess();
}

// Rebuilds the deposit list (DepositList); DepositCountLabel shows the free deposit slots out of 20.
// FUNCTION: TITANIUM 0x0050DA60
void CGuildBankWndView_guess::RefillSecondList_guess() {
    this->depositCount_beac_guess = 0;
    if (this->itemListSecond_017c_guess != 0) {
        ((Widget_guess*)this->itemListSecond_017c_guess)->Slot76_guess();
        int i_guess = 0;
        Record_guess* entry_guess = (Record_guess*)this->depositItems_guess;
        for (; i_guess < 20; ++i_guess, ++entry_guess) {
            if (entry_guess->present_0004_guess) {
                int row_guess = ((CListWnd*)this->itemListSecond_017c_guess)->AddString(g_emptyString_guess, -1, i_guess, 0);
                this->FillRow_guess((CListWnd*)this->itemListSecond_017c_guess, row_guess,
                                    (TypeEntry_guess*)entry_guess, true);
                ++this->depositCount_beac_guess;
            }
        }
    }
    this->depositListDirty_guess = 0;
    if (this->widget_018c_guess != 0) {
        char buffer_guess[256];
        FormatText_guess(buffer_guess, 0x17d3,
                         (int)_itoa(0x14 - this->depositCount_beac_guess, g_itoaBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
        CXStr message_guess(buffer_guess);
        this->widget_018c_guess->Slot63_guess(message_guess);
    }
    PackedValue_guess packed_guess;
    packed_guess.whole = this->selectedSlot_beb4_guess;
    if ((char)IsDepositAreaSlot_external_guess(packed_guess)) {
        this->ApplySelection_guess(0xffffffff);
    }
    this->UpdateButtons_guess();
}

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

struct Clock_guess {
    unsigned char unknown_0000_guess[0x10];
    unsigned char flag_0010_guess;
    unsigned char unknown_0011_guess[0x137];
    int tick_0148_guess;
    // EXTERNAL: TITANIUM 0x00439D16 Clock_guess::PlayerDistance_guess
    float PlayerDistance_guess(int value_guess, void* status_guess, float threshold_guess);
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)

// Message as the dispatcher passes it: kind, then a 0xDC-byte record at +8.
struct ResetMessage_guess {
    int kind_0000_guess;
    int unknown_0004_guess;
    Record_guess record_0008_guess;
};

struct SortMessage_guess {
    unsigned int kind_0000_guess;
    CXStr firstText_0004_guess;
    unsigned int firstValue_0008_guess;
    CXStr secondText_000c_guess;
    unsigned int secondValue_0010_guess;
    int result_0014_guess;
};

struct RectWork_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9160 RectWork_guess::Copy_guess
    void Copy_guess(const RectWork_guess* destination_guess, const RectWork_guess* source_guess);
    // EXTERNAL: TITANIUM 0x004DC02D RectWork_guess::CenterPoint
    RectWork_guess* CenterPoint(RectWork_guess* output_guess);
};

struct ShortMessage_guess {
    int code_0000_guess;
    int unknown_0004_guess;
    int unknown_0008_guess;
};

struct CompareMessage_guess {
    int code_0000_guess;
    int unknown_0004_guess;
    unsigned int source_0008_guess;
    int value_000c_guess;
    int argument_0010_guess;
};

// EXTERNAL: TITANIUM 0x00574460 FUN_00574460_guess
int __cdecl FUN_00574460_guess(const char* left_guess, const char* right_guess);


// Incoming OP_GuildBank by action: 10 (ack) and 5 (deposit reply) end a pending request, and a successful
// deposit (+8 == 0) deletes the cursor item (slot 30); 1 updates one slot; 0 is the bulk list.
// FUNCTION: TITANIUM 0x0050DC08
void CGuildBankWndView_guess::HandleMessage_guess(unsigned int unknown_guess, ResetMessage_guess* message_guess,
                                           int flags_guess) {
    switch (message_guess->kind_0000_guess) {
    case 10:
        if (0 < g_pendingGuildBankRequests_guess) {
            --g_pendingGuildBankRequests_guess;
        }
        break;
    case 5:
        if (message_guess->record_0008_guess.unknown_0000_guess == 0) {
            PooledObject_guess** slot_guess = g_extendedTypeState_guess->GetItemSlotPointer_guess(0x1e);
            if (*slot_guess != 0) {
                (*slot_guess)->Release_guess(1);
            }
            *slot_guess = 0;
            g_extendedTypeState_guess->flag_0c28c_guess = 1;
            g_clock_guess->flag_0010_guess = 0;
        }
        if (0 < g_pendingGuildBankRequests_guess) {
            --g_pendingGuildBankRequests_guess;
        }
        break;
    case 1: {
        Record_guess* source_guess = &message_guess->record_0008_guess;
        Record_guess* entry_guess = (Record_guess*)this->GetItem_guess(source_guess->unknown_0000_guess);
        *entry_guess = *source_guess;
        if (entry_guess->present_0004_guess == 0) {
            this->MarkListDirty_guess(*(PackedValue_guess*)&source_guess->unknown_0000_guess);
        } else {
            this->UpdateItem_guess(source_guess->unknown_0000_guess);
        }
        break;
    }
    case 0:
        this->ProcessRecords_guess((RecordStream_guess*)message_guess);
        break;
    }
}

// Every 300 ms while shown: updates the buttons, refills dirty lists, and closes the window once the
// banker is more than 20 units away.
// FUNCTION: TITANIUM 0x0050DCB6
int CGuildBankWnd_guess::OnProcessFrame_guess() {
    if (((CXWnd*)this)->Show != 0) {
        int now_guess = FUN_0046d655_guess();
        int* due_guess = &this->field_0194_guess;
        if (now_guess > *due_guess + 300) {
            *due_guess = now_guess;
            ((CGuildBankWndView_guess*)this)->UpdateButtons_guess();
            if (((CGuildBankWndView_guess*)this)->depositListDirty_guess != 0) {
                ((CGuildBankWndView_guess*)this)->RefillSecondList_guess();
            }
            if (((CGuildBankWndView_guess*)this)->mainListDirty_guess != 0) {
                ((CGuildBankWndView_guess*)this)->RefillFirstList_guess();
            }
            if (g_guildBanker_guess != 0) {
                if (g_clock_guess->PlayerDistance_guess(g_guildBanker_guess, g_guildBankRoot_guess, 1.0f) > 20.0f) {
                    ((Widget_guess*)this)->Slot48_guess(0, 1);
                }
            }
        }
    }
    return ((CXWnd*)this)->OnProcessFrame();
}

// Click (1): list rows select; deposit 5, view 4, promote 3, merge 9; withdraw 7 at once for a single
// item, else through the quantity window (mode +0xBEB8 1), as is split (mode 2, at most half the stack);
// change member and permission 1 open the name entry (string 0x17DD). 3 (probably right click) selects and
// inspects; 0xF toggles the sort column; 0x10 compares two rows by icon, name, count, permission or
// donator; 0x1F is the quantity chosen; 0x21 the entered member name. A split is sent only when the stack
// exceeds the amount + 1, so a stack of 2 offers 1 and sends nothing.
// FUNCTION: TITANIUM 0x0050DD43
// @early-stop: budget, structural ndiff=341
int CGuildBankWnd_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                                                void* data_guess) {
    CGuildBankWndView_guess* state_guess = (CGuildBankWndView_guess*)this;
    if (message_guess == 1) {
        if (sender_guess == this->itemList_015c_guess || sender_guess == this->depositList_017c_guess) {
            CListWnd* list_guess = (CListWnd*)sender_guess;
            int row_guess = list_guess->GetCurSel();
            state_guess->ApplySelection_guess(list_guess->GetItemData(row_guess));
        } else if (sender_guess == this->depositButton_0180_guess) {
            ShortMessage_guess message_guess;
            message_guess.code_0000_guess = 5;
            EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0xc, 1);
            ++g_pendingGuildBankRequests_guess;
        } else if (sender_guess == this->viewItemButton_0164_guess) {
            state_guess->SendViewItem_guess();
        } else if (sender_guess == this->promoteButton_0184_guess) {
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(state_guess->selectedSlot_beb4_guess);
            if (entry_guess != 0) {
                CompareMessage_guess message_guess;
                message_guess.code_0000_guess = 3;
                message_guess.source_0008_guess = state_guess->selectedSlot_beb4_guess;
                message_guess.value_000c_guess = entry_guess->value_0008_guess;
                message_guess.argument_0010_guess = 0;
                EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x14, 1);
                ++g_pendingGuildBankRequests_guess;
            }
        } else if (sender_guess == this->splitButton_0174_guess) {
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(state_guess->selectedSlot_beb4_guess);
            if (entry_guess != 0 && entry_guess->quantity_0010_guess >= 2) {
                RectWork_guess rectangle_guess;
                RectWork_guess center_guess;
                CXRect windowRect_guess = ((Widget_guess*)sender_guess)->Slot57_guess();
                rectangle_guess.Copy_guess(&center_guess, (const RectWork_guess*)&windowRect_guess);
                RectWork_guess* point_guess = rectangle_guess.CenterPoint(&center_guess);
                state_guess->quantityMode_beb8_guess = 2;
                pinstCQuantityWnd_guess->Function_0054d976_guess(this, entry_guess->quantity_0010_guess / 2, 1,
                                                           point_guess->left_guess, point_guess->top_guess, 1);
            }
        } else if (sender_guess == this->mergeButton_0170_guess) {
            unsigned int value_guess = state_guess->selectedSlot_beb4_guess;
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(value_guess);
            if (entry_guess != 0) {
                CompareMessage_guess message_guess;
                message_guess.code_0000_guess = 9;
                message_guess.source_0008_guess = value_guess;
                message_guess.value_000c_guess = entry_guess->value_0008_guess;
                message_guess.argument_0010_guess = 0;
                EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x14, 1);
                ++g_pendingGuildBankRequests_guess;
            }
        } else if (sender_guess == this->withdrawButton_0160_guess) {
            unsigned int value_guess = state_guess->selectedSlot_beb4_guess;
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(value_guess);
            if (entry_guess == 0 || entry_guess->quantity_0010_guess < 2) {
                state_guess->SendWithdraw_guess(value_guess, 1);
            } else {
                RectWork_guess rectangle_guess;
                RectWork_guess center_guess;
                CXRect windowRect_guess = ((Widget_guess*)sender_guess)->Slot57_guess();
                rectangle_guess.Copy_guess(&center_guess, (const RectWork_guess*)&windowRect_guess);
                RectWork_guess* point_guess = rectangle_guess.CenterPoint(&center_guess);
                state_guess->quantityMode_beb8_guess = 1;
                pinstCQuantityWnd_guess->Function_0054d976_guess(this, entry_guess->quantity_0010_guess, 1,
                                                           point_guess->left_guess, point_guess->top_guess, 1);
            }
        } else if (sender_guess == this->changeTargetButton_016c_guess) {
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(state_guess->selectedSlot_beb4_guess);
            if (entry_guess != 0) {
                pinstCTextEntryWnd_guess->Activate_guess(this, 1, pStringTable->getString(0x17dd, 0),
                                                      0, 0x40, entry_guess->name_009a_guess);
            }
        } else if (sender_guess == (CXWnd*)this->permissionCombo_0168_guess) {
            unsigned int value_guess = state_guess->selectedSlot_beb4_guess;
            if (value_guess != 0xffffffff) {
                TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(value_guess);
                int selection_guess = this->permissionCombo_0168_guess->GetCurChoice_guess();
                if (selection_guess != 1) {
                    state_guess->SendPermissionChange_guess(value_guess, selection_guess, 0);
                } else {
                    char nameCopy_guess[0x40];
                    char* name_guess = entry_guess->name_009a_guess;
                    if (*name_guess == 0) {
                        name_guess = g_typeState_guess->names_0044_guess +
                                     g_typeState_guess->names_0008_guess->vbaseOffset_0004_guess;
                        FUN_0060e450_guess(entry_guess->name_009a_guess, name_guess);
                        name_guess = entry_guess->name_009a_guess;
                    }
                    FUN_0060e450_guess(nameCopy_guess, name_guess);
                    pinstCTextEntryWnd_guess->Activate_guess(this, 1, pStringTable->getString(0x17dd, 0),
                                                          0, 0x40, nameCopy_guess);
                }
            }
        } else if (sender_guess == (CXWnd*)this->filterCombo_0178_guess) {
            state_guess->filterMode_bebc_guess = this->filterCombo_0178_guess->GetCurChoice_guess();
            state_guess->mainListDirty_guess = 1;
        }
    } else if (message_guess == 3) {
        if (sender_guess == this->itemList_015c_guess || sender_guess == this->depositList_017c_guess) {
            CListWnd* list_guess = (CListWnd*)sender_guess;
            int row_guess = list_guess->GetCurSel();
            state_guess->ApplySelection_guess(list_guess->GetItemData(row_guess));
            state_guess->SendViewItem_guess();
        }
    } else if (message_guess == 0xf) {
        if ((sender_guess == this->itemList_015c_guess || sender_guess == this->depositList_017c_guess) &&
            sender_guess != 0) {
            struct ToggleSource_guess {
                unsigned char unknown_0000_guess[0x154];
                int item_0154_guess;
                unsigned char active_0158_guess;
            };
            ToggleSource_guess* source_guess = (ToggleSource_guess*)sender_guess;
            if (source_guess->item_0154_guess == (int)data_guess) {
                source_guess->active_0158_guess = source_guess->active_0158_guess == 0;
            } else {
                source_guess->item_0154_guess = (int)data_guess;
                source_guess->active_0158_guess = 1;
            }
            ((Widget_guess*)sender_guess)->Slot78_guess();
        }
    } else if (message_guess == 0x10) {
        SortMessage_guess* sort_guess = (SortMessage_guess*)data_guess;
        TypeEntry_guess* first_guess = (TypeEntry_guess*)state_guess->GetItem_guess(sort_guess->firstValue_0008_guess);
        TypeEntry_guess* second_guess = (TypeEntry_guess*)state_guess->GetItem_guess(sort_guess->secondValue_0010_guess);
        if (sort_guess->kind_0000_guess == 0) {
            int difference_guess = first_guess->value_000c_guess - second_guess->value_000c_guess;
            sort_guess->result_0014_guess = difference_guess < 0 ? -1 : difference_guess > 0;
        } else if (sort_guess->kind_0000_guess == 1) {
            sort_guess->result_0014_guess = FUN_00574460_guess(
                sort_guess->firstText_0004_guess.operator char*(),
                sort_guess->secondText_000c_guess.operator char*());
        } else if (sort_guess->kind_0000_guess == 2) {
            int difference_guess = first_guess->quantity_0010_guess - second_guess->quantity_0010_guess;
            sort_guess->result_0014_guess = difference_guess < 0 ? -1 : difference_guess > 0;
        } else if (sort_guess->kind_0000_guess == 3) {
            if (sender_guess == this->itemList_015c_guess) {
                int difference_guess = first_guess->kind_0014_guess - second_guess->kind_0014_guess;
                sort_guess->result_0014_guess = difference_guess < 0 ? -1 : difference_guess > 0;
            } else {
                sort_guess->result_0014_guess = FUN_00574460_guess(
                    sort_guess->firstText_0004_guess.operator char*(),
                    sort_guess->secondText_000c_guess.operator char*());
            }
        }
    } else if (message_guess == 0x1f) {
        int row_guess = *(int*)data_guess;
        unsigned int value_guess = state_guess->selectedSlot_beb4_guess;
        if (value_guess != 0xffffffff) {
            TypeEntry_guess* entry_guess = (TypeEntry_guess*)state_guess->GetItem_guess(value_guess);
            if (state_guess->quantityMode_beb8_guess == 2) {
                if (entry_guess != 0 && entry_guess->quantity_0010_guess > row_guess + 1) {
                    CompareMessage_guess message_guess;
                    message_guess.code_0000_guess = 8;
                    message_guess.source_0008_guess = value_guess;
                    message_guess.value_000c_guess = entry_guess->value_0008_guess;
                    message_guess.argument_0010_guess = row_guess;
                    EQSendMessage(&g_messageConnection_guess, OP_GuildBank, &message_guess, 0x14, 1);
                    ++g_pendingGuildBankRequests_guess;
                }
            } else if (state_guess->quantityMode_beb8_guess == 1 && entry_guess != 0) {
                state_guess->SendWithdraw_guess(value_guess, row_guess);
            }
        }
    } else if (message_guess == 0x21) {
        if ((g_typeState_guess->active_0e14_guess & 1) != 0 &&
            state_guess->selectedSlot_beb4_guess != 0xffffffff &&
            this->permissionCombo_0168_guess->GetCurChoice_guess() == 1) {
            CXStr text_guess = pinstCTextEntryWnd_guess->GetEntryText_guess();
            state_guess->SendPermissionChange_guess(state_guess->selectedSlot_beb4_guess, 1, (char*)text_guess);
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess, data_guess);
}


