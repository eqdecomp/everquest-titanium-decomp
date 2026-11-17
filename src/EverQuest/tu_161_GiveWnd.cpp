// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 161: a hint from compare/tumap.py.
// CGiveWnd (screen "GiveWnd", vtable 0x654CF8): the four item slots and coin buttons for giving to an NPC.
// Widget_guess, TargetObject_guess and DestructOwner_guess are views of it. g_managerA_guess (0x850C50) is
// CTradeWnd, which does the actual trade; g_managerB_guess (0x9928E0) the tip-of-the-day/context-tip window.
#include "titanium/types.h"
#include <stdio.h>
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CTradeWnd.h"

struct Node_guess {
    // EXTERNAL: TITANIUM 0x005DFC40 Node_guess::Active_guess
    char Active_guess();
    // EXTERNAL: TITANIUM 0x005E0D00 Node_guess::CheckA_guess
    char CheckA_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0CC0 Node_guess::CheckB_guess
    char CheckB_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 Node_guess::CheckC_guess
    int CheckC_guess(int index_guess);
};

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(unsigned int address_guess, unsigned int type_guess,
        char* text_guess, unsigned int size_guess, unsigned int timeout_guess,
        void* data_guess, int zero_guess);
};

struct ItemData_guess {
    char pad_00[0x10];
    int* value_10;
};

struct Entry_guess {
    char pad_000[0x140];
    ItemData_guess* invSlot_0140_guess;
    // EXTERNAL: TITANIUM 0x0059FEC0 Entry_guess::IsReallyVisible
    unsigned char IsReallyVisible();
    // EXTERNAL: TITANIUM 0x0059D960 Entry_guess::GetScreenRect
    void* GetScreenRect(int* output);
    // EXTERNAL: TITANIUM 0x005A02F0 Entry_guess::Build_guess
    void Build_guess(int* output);
};

struct WindowData_guess {
    int id_00;
    int first_04;
    int second_08;
    int unk_0c;
    int outputX_10;
    int outputY_14;
    // EXTERNAL: TITANIUM 0x004D9160 WindowData_guess::Assign_guess
    void Assign_guess(int* buffer, void* value);
};

struct ScratchFrame_guess {
    int local_40[4];
    int local_30[4];
    WindowData_guess data;
    int remaining;
};

struct Widget_guess {
    char pad_000[0x5c];
    char flag_5c;
    char pad_05d[5];
    char flag_62;
    char pad_063[0x17c - 0x63];
    Entry_guess* entries_17c[4];
    // EXTERNAL: TITANIUM 0x005A1880 Widget_guess::OnShow
    void OnShow();
    void OnActive_guess();
    int PostDraw_guess();
    void OnGiveButton_guess();
};

struct DestructBase_guess {
    char pad_000[0x15c];
    // EXTERNAL: TITANIUM 0x005A3100 ??1DestructBase_guess@@QAE@XZ
    ~DestructBase_guess();
};

struct DestructSub_guess {
    virtual void Slot00_guess();
    virtual ~DestructSub_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 DestructSub_guess::Reset_guess
    void Reset_guess(int value);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7DestructSub_guess@@6B@

struct DestructOwner_guess : DestructBase_guess {
    char storage_15c[4];
    ~DestructOwner_guess();
    void* Delete_guess(unsigned char flags);
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_deliveryManager2_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)

struct TextBase_guess {
    char pad_000[0x120];
    char text_120[1];
};

struct LookupManager_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 LookupManager_guess::Find_guess
    const char* Find_guess(const char* text_guess);
};

#define g_textBase_guess EQ_GLOBAL(TextBase_guess*, 0x00905CE0)
#define g_lookupManager_guess EQ_GLOBAL(LookupManager_guess*, 0x00988DF0)

struct QueryInterface_guess {
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
    virtual void Get_guess(void* output_guess);
};

struct TargetObject_guess {
    char pad_000[0x160];
    QueryInterface_guess* money_0160_guess[4];
    char pad_170[8];
    QueryInterface_guess* npcName_0178_guess;
    void UpdateGiveDisplay_guess();
};

// Mac: CGiveWnd::UpdateGiveDisplay. Shows the NPC's trimmed name (spawn 0x905CE0 +0x120) and the four coin
// amounts the trade holds (CTradeWnd +0x1E4, platinum to copper).
// FUNCTION: TITANIUM 0x00507310
void TargetObject_guess::UpdateGiveDisplay_guess() {
    if (g_textBase_guess != 0 && npcName_0178_guess != 0) {
        CXStr initial(g_lookupManager_guess->Find_guess(g_textBase_guess->text_120));
        npcName_0178_guess->Get_guess(&initial);
    }
    int remaining = 4;
    int index = 0;
    do {
        if (money_0160_guess[index] != 0) {
            char text[256];
            sprintf(text, "%d", pinstCTradeWnd_guess->coins_guess[index]);
            CXStr formatted(text);
            money_0160_guess[index]->Get_guess(&formatted);
        }
        ++index;
        --remaining;
    } while (remaining != 0);
}

// EXTERNAL: TITANIUM 0x00507310 UpdateGiveDisplay_guess
void UpdateGiveDisplay_guess();

struct GiveAnimation_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 GiveAnimation_guess::SetFrame_guess
    void SetFrame_guess(int frame);
};

struct GiveSlotWnd_guess {
    char pad_000[0x12c];
    GiveAnimation_guess* animation_12c;
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// OnShow: shown (+0x5C) asks the tip window for context tip 20, probably the give tip; hidden while
// CTradeWnd +0x236 is set closes the trade.
// FUNCTION: TITANIUM 0x0050720C
void Widget_guess::OnActive_guess() {
    if (flag_5c != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            // Context tip 20 (tip window mode 1 ids 0-0x48).
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x14, 0);
        }
    } else {
        if (pinstCTradeWnd_guess != 0 && pinstCTradeWnd_guess->active_guess != 0) {
            pinstCTradeWnd_guess->Deactivate_guess();
        }
    }
    OnShow();
}

// PostDraw: while a modifier key is held (keyboard flags 0x0C) and +0x62 is set, draws the tooltip of every
// visible item slot that holds an item, near its top-right corner.
// FUNCTION: TITANIUM 0x00507249
int Widget_guess::PostDraw_guess() {
    unsigned char state = pinstCXWndManager_guess->GetKeyboardFlags();
    if ((state & 0x0c) != 0 && flag_62 != 0) {
        ScratchFrame_guess scratch;
        scratch.data.outputX_10 = 0;
        scratch.data.outputY_14 = 0;
        scratch.data.unk_0c = 0;
        scratch.data.second_08 = 0;
        scratch.data.first_04 = 0;
        scratch.data.id_00 = 0;
        int firstId = -1;
        Entry_guess** entry = entries_17c;
        scratch.remaining = 4;
        do {
            if (*entry != 0 && (*entry)->IsReallyVisible() != 0) {
                int* valuePointer = (*entry)->invSlot_0140_guess->value_10;
                int value = valuePointer != 0 ? *valuePointer : 0;
                if (value != 0) {
                    void* fetched = (*entry)->GetScreenRect(scratch.local_30);
                    scratch.data.Assign_guess(scratch.local_40, fetched);
                    if (firstId == -1) {
                        firstId = scratch.data.id_00;
                    }
                    scratch.data.outputX_10 = scratch.data.second_08 - 5;
                    if (scratch.data.id_00 == firstId) {
                        scratch.data.outputY_14 = scratch.data.first_04 + 2;
                    } else {
                        // Slots outside the first filled slot's column sit 22 px lower (compares left edges).
                        scratch.data.outputY_14 = scratch.data.first_04 + 0x16;
                    }
                    (*entry)->Build_guess(&scratch.data.outputX_10);
                }
            }
            ++entry;
            --scratch.remaining;
        } while (scratch.remaining != 0);
    }
    return 0;
}

struct GiveSidlTemplate_guess {
    char pad_000[0x60];
    unsigned int style_060;                 // 0x060
};

struct GiveNotifier_guess {
    // EXTERNAL: TITANIUM 0x005482A0 GiveNotifier_guess::Reset_guess
    void Reset_guess(int value);
    virtual void Slot00_guess();
    virtual ~GiveNotifier_guess() {
        Reset_guess(-1);
    }
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7GiveNotifier_guess@@6B@

struct GiveSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1GiveSidlBase_guess@@UAE@XZ
    virtual ~GiveSidlBase_guess();
    char pad_004[0x60];
    unsigned int windowStyle_064;           // 0x064
    char pad_068[0xbc];
    GiveSidlTemplate_guess* sidlPiece_124;  // 0x124
    char pad_128[0x30];
    int field_158;                          // 0x158
    // EXTERNAL: TITANIUM 0x005A2230 GiveSidlBase_guess::WndNotification
    int WndNotification(CXWnd* sender_guess, int message_guess,
        void* data_guess);
    // EXTERNAL: TITANIUM 0x005A3900 ??0GiveSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    GiveSidlBase_guess(CXWnd* parent, const CXStr& screen);
};

// EXTERNAL: TITANIUM 0x00654CF8 ??_7GiveWnd_guess@@6BGiveSidlBase_guess@@@
// EXTERNAL: TITANIUM 0x00654E18 ??_7GiveWnd_guess@@6BGiveNotifier_guess@@@
struct GiveWnd_guess : GiveSidlBase_guess, GiveNotifier_guess {
    CXWnd* money_160[4];
    CXWnd* give_170;
    CXWnd* cancel_174;
    CXWnd* npcName_178;
    CXWnd* itemSlot_17c[4];
    void Callback_guess(int event_guess, unsigned char flags_guess,
        int unused_guess);
    GiveWnd_guess(CXWnd* parent);
    char AboutToShow_guess();
    int Notification_guess(CXWnd* sender_guess, int message_guess,
        void* data_guess);
};

// Confirmation callback: a yes (flags & 5) to the augment warning (dialog type 0x7A) accepts the trade.
// FUNCTION: TITANIUM 0x0050750F
void GiveWnd_guess::Callback_guess(int event_guess, unsigned char flags_guess,
    int unused_guess) {
    if (event_guess == 0x7a && (flags_guess & 5) != 0) {
        pinstCTradeWnd_guess->ClickedTradeButton_guess();
    }
}

// Mac: CGiveWnd::CGiveWnd. Binds GVW_MyMoney0-3, the Give and Cancel buttons, the NPC name label and
// GVW_MyItemSlot0-3.
// FUNCTION: TITANIUM 0x0050752B
GiveWnd_guess::GiveWnd_guess(CXWnd* parent)
    : GiveSidlBase_guess(parent, "GiveWnd") {
    for (int i = 0; i < 4; ++i) {
        itemSlot_17c[i] = 0;
    }
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060 | 0x10000;
        field_158 = 0x14;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        for (int i = 0; i < 4; ++i) {
            char name[512];
            sprintf(name, "GVW_MyMoney%d", i);
            money_160[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        give_170 = ((CSidlScreenWnd*)this)->GetChildItem("GVW_Give_Button");
        cancel_174 = ((CSidlScreenWnd*)this)->GetChildItem("GVW_Cancel_Button");
        npcName_178 = ((CSidlScreenWnd*)this)->GetChildItem("GVW_NPCName");
        for (int i = 0; i < 4; ++i) {
            char name[512];
            sprintf(name, "GVW_MyItemSlot%d", i);
            itemSlot_17c[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
    }
}

// Give button: if any given item (0x5DFC40 false) has a filled augment slot (10 checked), asks first;
// otherwise accepts the trade (OP_TradeAcceptClick) at once.
// FUNCTION: TITANIUM 0x00507434
void Widget_guess::OnGiveButton_guess() {
    unsigned char found = 0;
    int remaining = 4;
    Entry_guess** entry = entries_17c;
    do {
        Entry_guess* e = *entry;
        if (e != 0) {
            ItemData_guess* data = e->invSlot_0140_guess;
            if (data != 0) {
                int* valuePointer = data->value_10;
                Node_guess* node = valuePointer != 0
                    ? reinterpret_cast<Node_guess*>(*valuePointer) : 0;
                if (node != 0 && node->Active_guess() == 0) {
                    for (int i = 0; i < 10; ++i) {
                        if (node->CheckA_guess(i) != 0
                            && node->CheckB_guess(i) != 0
                            && node->CheckC_guess(i) != 0) {
                            found = 1;
                            break;
                        }
                    }
                }
            }
        }
        ++entry;
        --remaining;
    } while (remaining != 0);
    if (found != 0) {
        g_deliveryManager2_guess->Activate(
            this != 0 ? (unsigned int)this + 0x15c : 0, 0x7a,
            // String 8877, "give augmented items ... augments will be lost"; dialog type 0x7A, 10 s, answered
            // in Callback_guess.
            pStringTable->getString(0x22ad, 0),
            0xc, 10000, 0, 0);
        return;
    }
    pinstCTradeWnd_guess->ClickedTradeButton_guess();
}

// Scalar deleting destructor of CGiveWnd.
// FUNCTION: TITANIUM 0x0050775C
void* DestructOwner_guess::Delete_guess(unsigned char flags) {
    this->DestructOwner_guess::~DestructOwner_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// CGiveWnd::~CGiveWnd: tears down the dialog-callback base at +0x15C, then CSidlScreenWnd.
// FUNCTION: TITANIUM 0x00507778
DestructOwner_guess::~DestructOwner_guess() {
    DestructSub_guess* p = this ? reinterpret_cast<DestructSub_guess*>(storage_15c) : 0;
    p->DestructSub_guess::~DestructSub_guess();
}

// Activate (vtable slot 49): refreshes the display and resets the four item slots' animations to no frame.
// FUNCTION: TITANIUM 0x005077BE
char GiveWnd_guess::AboutToShow_guess() {
    UpdateGiveDisplay_guess();
    int remaining = 4;
    CXWnd** slot = itemSlot_17c;
    do {
        if (*slot != 0) {
            GiveSlotWnd_guess* wnd = reinterpret_cast<GiveSlotWnd_guess*>(*slot);
            wnd->animation_12c->SetFrame_guess(-1);
        }
        ++slot;
    } while (--remaining != 0);
    return 1;
}

// WndNotification: Cancel cancels the trade (OP_CancelTrade), Give runs the augment check, a coin button
// moves the cursor's coins into that trade slot.
// FUNCTION: TITANIUM 0x005077EE
int GiveWnd_guess::Notification_guess(CXWnd* sender_guess, int message_guess,
    void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == cancel_174) {
            pinstCTradeWnd_guess->ClickedCancelButton_guess();
            return 0;
        }
        if (sender_guess == give_170) {
            ((Widget_guess*)this)->OnGiveButton_guess();
            return 0;
        }
        int index_guess = 0;
        CXWnd** money_guess = money_160;
        do {
            if (sender_guess == *money_guess) {
                pinstCTradeWnd_guess->ClickedMoneyButton_guess(index_guess);
                return 0;
            }
            ++index_guess;
            ++money_guess;
        } while (index_guess < 4);
    }
    return GiveSidlBase_guess::WndNotification(sender_guess, message_guess,
        data_guess);
}

