// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 182: a hint from compare/tumap.py.
// The corpse loot window, LootWnd ("LootWnd"): 31 item slots (LW_LootSlot0-30), loot requests and replies,
// the Broadcast and Done buttons. Interface_guess and TargetProcessor_guess are views of LootWnd_guess
// (misnamed).
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    char* getString(unsigned int id, int zero, int type, int flag);
};

struct MessageManager_guess {
    // EXTERNAL: TITANIUM 0x004982C6 MessageManager_guess::dsp_chat
    void dsp_chat(char* text);
    // EXTERNAL: TITANIUM 0x004A1350 MessageManager_guess::Reset_guess
    void Reset_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x00492EC2 MessageManager_guess::GetString_guess
    const char* GetString_guess(const char* text_guess);
};

#define g_stringManager_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_messageManager_guess EQ_GLOBAL(MessageManager_guess*, 0x00988DF0)

struct RefObject_guess {
    virtual void Release_guess(int flags);
    unsigned char pad_004[0x48];
    int key_04c_guess;
    // EXTERNAL: TITANIUM 0x005E0F30 RefObject_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E3850 RefObject_guess::GetDescription_guess
    void GetDescription_guess(char* text_guess, int size_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 RefObject_guess::GetName_guess
    const char* GetName_guess();
};

struct TextSink_guess {
    // EXTERNAL: TITANIUM 0x005B90E0 TextSink_guess::SetText_guess
    void SetText_guess(CXStr text_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x005B9670 TextSink_guess::AddEntry_guess
    void AddEntry_guess(const char* name_guess, char* text_guess);
};

struct TextRoot_guess {
    unsigned char pad_000[0x160];
    TextSink_guess* sink_160_guess;
};

struct TextRootProvider_guess {
    // EXTERNAL: TITANIUM 0x004F288C TextRootProvider_guess::GetActiveChatWindow_guess
    TextRoot_guess* GetActiveChatWindow_guess();
};

#define pinstCChatManager_guess EQ_GLOBAL(TextRootProvider_guess*, 0x009917E4)
#define g_separator_guess EQ_ARRAY(char, 0x0063FDE4)

struct OutputSink_guess;
struct ResetTarget_guess;

struct Interface_guess {
    unsigned char pad_000[0x58];
    unsigned char active_05c_guess;
    unsigned char pad_05d[0x103];
    unsigned char state_160_guess;
    unsigned char state_161_guess;
    unsigned char pad_162[0x2];
    int keys_164_guess[0x1F];
    int value_1e0_guess;
    unsigned char state_1e4_guess;
    unsigned char pad_1e5[0x3];
    RefObject_guess* objects_1e8_guess[0x1F];
    ResetTarget_guess* resetTarget_264_guess;
    struct SecondaryObject_guess* secondary_268_guess[0x1F];
    OutputSink_guess* outputSink_2e4_guess;

    // EXTERNAL: TITANIUM 0x0059DD30 Interface_guess::Query_guess
    char Query_guess();
    // EXTERNAL: TITANIUM 0x004E6109 Interface_guess::RunState_guess
    void RunState_guess(int value);
    void Handle_guess();
    void FinishLoot_guess();
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
    virtual void Slot48_guess(int first, int second);
    void AddLootItem_guess(RefObject_guess* object);
    void HandleLootItemReply_guess(int value);
    void InsertLootLinksInChat_guess();
    char CheckState_guess();
    char Activate_guess();
    void OnProcessFrame_guess();
};

struct OutputSink_guess : Interface_guess {
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
    virtual void Store_guess(CXStr* text_guess);
};

struct ResetTarget_guess : OutputSink_guess {
    virtual void Reset_guess(int value_guess);
};

struct SecondaryObject_guess {
    unsigned char pad_000[0x140];
    struct Cleanup_guess* cleanup_140_guess;
};

struct Cleanup_guess {
    // EXTERNAL: TITANIUM 0x00518E5C Cleanup_guess::Run_guess
    void Run_guess(int value);
};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005B0940 CXWndManagerView_guess::BringWndToTop
    void BringWndToTop(Interface_guess* object, int value);
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::GetKeyboardFlags
    char GetKeyboardFlags();
};

struct Value_guess {
    int value_00_guess;
    int value_04_guess;
    int value_08_guess;
    int value_0c_guess;
};

struct CXWndView_guess {
    // EXTERNAL: TITANIUM 0x0059D960 CXWndView_guess::GetValue_guess
    int GetValue_guess(Value_guess* output_guess);
};

struct DataAccess_guess {
    unsigned char pad_000[0x10];
    int* value_010_guess;
};

struct SecondaryTarget_guess {
    unsigned char pad_000[0x28];
    CXWndView_guess* source_028_guess;
    unsigned char pad_02c[0x114];
    DataAccess_guess* access_140_guess;
    // EXTERNAL: TITANIUM 0x0059D960 SecondaryTarget_guess::GetValue_guess
    int GetValue_guess(Value_guess* output_guess);
    // EXTERNAL: TITANIUM 0x005A02F0 SecondaryTarget_guess::Dispatch_guess
    void Dispatch_guess(int* position_guess);
};

struct ValuePair_guess {
    int value_00_guess;
    int value_04_guess;
    int value_08_guess;
    int value_0c_guess;
    // EXTERNAL: TITANIUM 0x004D9160 ValuePair_guess::Combine_guess
    void Combine_guess(Value_guess* first_guess, int second_guess);
};

struct Position_guess {
    int x_guess;
    int y_guess;
};

struct TargetProcessor_guess {
    unsigned char pad_000[0x62];
    unsigned char enabled_062_guess;
    unsigned char pad_063[0x205];
    SecondaryTarget_guess* objects_268_guess[0x1f];
    int PostDraw_guess();
};

struct ModeManager_guess {
    // EXTERNAL: TITANIUM 0x0044A617 ModeManager_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int mode, int value);
};

struct SystemState_guess {
    unsigned char pad_000[0x120];
    char text_120_guess[1];
    unsigned char pad_121[0x130];
    unsigned char mode_251_guess;
    // EXTERNAL: TITANIUM 0x00483556 SystemState_guess::ChangePosition_guess
    void ChangePosition_guess(int value);
};

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)
#define g_modeManager_guess EQ_GLOBAL(ModeManager_guess*, 0x00851390)
#define g_systemState_guess EQ_GLOBAL(SystemState_guess*, 0x00905CE4)
#define g_value_905d04_guess EQ_GLOBAL(int, 0x00905D04)
#define g_value_905d18_guess EQ_GLOBAL(int, 0x00905D18)
#define g_buffer_905d18_guess EQ_GLOBAL(const char*, 0x00905D18)
#define g_value_923d94_guess EQ_GLOBAL(int, 0x00923D94)
#define g_value_9248d4_guess EQ_GLOBAL(int, 0x009248D4)

#define g_count_9248d0_guess EQ_GLOBAL(int, 0x009248D0)
#define g_index_92398c_guess EQ_GLOBAL(int, 0x0092398C)

struct RuntimeState_guess;

struct ActiveFlags_guess {
    unsigned char pad_000[0x14];
    unsigned char active_014_guess;
    unsigned char pad_015[0x133];
    unsigned int time_148_guess;
    // EXTERNAL: TITANIUM 0x00439D16 ActiveFlags_guess::PlayerDistance_guess
    float PlayerDistance_guess(RuntimeState_guess* object_guess, SystemState_guess* system_guess,
                        float value_guess);
};

struct VirtualAction_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(int value_guess);
};

struct ServiceObject_guess {
    VirtualAction_guess* action_000_guess;
    unsigned char pad_004[0xec4];
    int flag_0ec8_guess;
};

struct RuntimeState_guess {
    unsigned char pad_000[0x1a8];
    ServiceObject_guess* service_1a8_guess;
    unsigned char pad_1ac[0x8c];
    float range_238_guess;
    unsigned char pad_23c[0x8];
    unsigned char type_0244_guess;
    unsigned char pad_245[0x13];
    int payload_258_guess;

    // EXTERNAL: TITANIUM 0x004793B5 RuntimeState_guess::CurrentText_guess
    const char* CurrentText_guess();
};

#define g_activeFlags_guess EQ_GLOBAL(ActiveFlags_guess*, 0x00905D24)
#define g_runtimeState_guess EQ_GLOBAL(RuntimeState_guess*, 0x00905D18)
#define g_messageBuffer_guess EQ_ARRAY(char, 0x00905CA0)

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* output_guess, const char* input_guess);
// EXTERNAL: TITANIUM 0x00621E9C _stricmp
extern "C" int __cdecl _stricmp(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x00576E80 GetClientTime_guess
int __cdecl GetClientTime_guess();

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CBazaarWnd.h"
#include "titanium/wnd/CInventoryWnd.h"

// EXTERNAL: TITANIUM 0x0063FD9C ??_7LootNotifier_guess@@6B@
struct LootNotifier_guess {
    virtual void Slot00_guess();
    virtual ~LootNotifier_guess() {}
};

struct LootWindowFields_guess {
    char pad_000[0x65];
    unsigned char field_065;
    char pad_066[0xb1 - 0x66];
    unsigned char field_0b1;
};

// EXTERNAL: TITANIUM 0x00657E48 ??_7LootWnd_guess@@6BLootNotifier_guess@@@
// EXTERNAL: TITANIUM 0x00657D28 ??_7LootWnd_guess@@6BCSidlScreenWndBase@@@
struct LootWnd_guess : CSidlScreenWndBase, LootNotifier_guess {
    unsigned char state_160_guess;
    char pad_161[3];
    int keys_164_guess[0x1F];
    int value_1e0_guess;
    char pad_1e4[4];
    RefObject_guess* objects_1e8_guess[0x1F];
    CXWnd* lootInvWnd_264_guess;
    CXWnd* slots_268_guess[0x1F];
    CXWnd* corpse_2e4_guess;
    CXWnd* done_2e8_guess;
    CXWnd* broadcast_2ec_guess;

    LootWnd_guess(CXWnd* parent);
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                             void* data_guess);
};

// Loot confirmation callback: on message 100 with Yes/OK (flags & 5) sends OP_LootItem (16-byte request) and
// counts it as pending (0x9248D0). Frees the request either way.
// FUNCTION: TITANIUM 0x0052B48E
void __stdcall ConfirmLootItem_guess(int message_guess, unsigned char flags_guess,
                                  int* data_guess) {
    if (message_guess == 100) {
        if ((flags_guess & 5) != 0) {
            ++g_count_9248d0_guess;
            EQSendMessage(g_messageBuffer_guess, OP_LootItem, data_guess, 0x10, 1);
        }
        delete data_guess;
    }
}

// On open: shows the corpse's name (trimName_guess) and resets the pending-close state; fails without a
// corpse.
// FUNCTION: TITANIUM 0x0052AE14
char Interface_guess::Activate_guess() {
    char result_guess = 0;
    if (g_buffer_905d18_guess != 0) {
        if (outputSink_2e4_guess != 0) {
            CXStr text_guess(g_messageManager_guess->GetString_guess(
                g_buffer_905d18_guess + 0x120));
            outputSink_2e4_guess->Store_guess(&text_guess);
        }
        value_1e0_guess = 0;
        state_160_guess = 0;
        if (resetTarget_264_guess != 0) {
            resetTarget_264_guess->Reset_guess(0);
        }
        state_161_guess = 1;
        result_guess = 1;
    }
    return result_guess;
}

// On close: sends OP_EndLootRequest (the corpse's spawn id) once and returns 0 to keep the window up until
// the server answers; a second call lets it close.
// FUNCTION: TITANIUM 0x0052AEB6
char Interface_guess::CheckState_guess() {
    char buffer_guess[64];
    if (g_activeFlags_guess->active_014_guess != 0 &&
        g_runtimeState_guess != 0 &&
        (g_runtimeState_guess->type_0244_guess == 2 ||
         g_runtimeState_guess->type_0244_guess == 3)) {
        CopyText_guess(buffer_guess, g_runtimeState_guess->CurrentText_guess());
        if (_stricmp(buffer_guess, g_systemState_guess->text_120_guess) != 0 &&
            g_runtimeState_guess->service_1a8_guess != 0 &&
            g_runtimeState_guess->service_1a8_guess->action_000_guess != 0) {
            g_runtimeState_guess->service_1a8_guess->flag_0ec8_guess = 1;
            g_runtimeState_guess->service_1a8_guess->action_000_guess->Slot06_guess(1);
        }
    }
    if (state_161_guess != 0) {
        if (state_160_guess == 0 && g_runtimeState_guess != 0) {
            EQSendMessage(g_messageBuffer_guess, OP_EndLootRequest,
                              &g_runtimeState_guess->payload_258_guess, 4, 1);
            state_160_guess = 1;
        }
        return 0;
    }
    return 1;
}

// Runs when the loot window is shown or hidden (+0x5C Show): on show it opens the inventory window
// (0x850C34) unless it was open, remembering which in +0x1E4, and notifies other windows; on hide it
// closes the inventory again only if this window opened it.
// FUNCTION: TITANIUM 0x0052AF98
void Interface_guess::Handle_guess() {
    if (active_05c_guess != 0) {
        state_1e4_guess = pinstCInventoryWnd_guess->IsVisible_guess();
        if (state_1e4_guess == 0) {
            pinstCInventoryWnd_guess->Activate();
        }
        pinstCXWndManager_guess->BringWndToTop(this, 1);
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x17, 0);
        }
        if (pinstCBazaarWnd_guess != 0) {
            if (pinstCBazaarWnd_guess->IsVisible_guess() != 0) {
                pinstCBazaarWnd_guess->UpdateSellItems_guess(0);
            }
        }
    } else if (state_1e4_guess == 0) {
        pinstCInventoryWnd_guess->Deactivate();
    }
    ((CSidlScreenWnd*)this)->OnShow();
}

// Ends looting: on OP_LootComplete / OP_EndLootRequest, a despawn (0x004581B7), our death (0x004A8CD5)
// and UI deactivation (0x00437BCD). Selects music 5, clears the corpse and every slot, stands the
// player up (ChangePosition_guess(100)) if still in looting stance 'i', then hides the window
// (Slot48_guess(0, 1)).
// FUNCTION: TITANIUM 0x0052B026
void Interface_guess::FinishLoot_guess() {
    g_modeManager_guess->SetMusicSelection_guess(5, 0);
    g_value_905d04_guess = 0;
    g_value_905d18_guess = 0;
    g_value_923d94_guess = 0xb;
    g_messageManager_guess->Reset_guess(0, 1, 0x15);
    for (int index_guess = 0; index_guess < 0x1f; ++index_guess) {
        if (objects_1e8_guess[index_guess] != 0) {
            objects_1e8_guess[index_guess]->Release_guess(1);
            objects_1e8_guess[index_guess] = 0;
            if (secondary_268_guess[index_guess] != 0) {
                secondary_268_guess[index_guess]->cleanup_140_guess->Run_guess(0);
            }
        }
        keys_164_guess[index_guess] = -1;
    }
    if (g_systemState_guess != 0 && g_systemState_guess->mode_251_guess == 'i') {
        g_systemState_guess->ChangePosition_guess(100);
    }
    g_value_9248d4_guess = 0;
    state_160_guess = 0;
    state_161_guess = 0;
    Slot48_guess(0, 1);
}

// With notification flags 0x0C set (probably a modifier key), draws an outline around the slots that share
// the first slot's key; the exact purpose is unclear.
// FUNCTION: TITANIUM 0x0052B0DA
int TargetProcessor_guess::PostDraw_guess() {
    char flags_guess = pinstCXWndManager_guess->GetKeyboardFlags();
    if ((flags_guess & 0x0c) == 0) {
        return 0;
    }
    if (enabled_062_guess == 0) {
        return 0;
    }

    SecondaryTarget_guess** slot_guess = objects_268_guess;
    SecondaryTarget_guess* first_guess = *slot_guess;
    int first_key_guess = -1;
    Value_guess values_guess[2];
    ValuePair_guess first_pair_guess;
    ValuePair_guess second_pair_guess;
    Position_guess position_guess;
    position_guess.x_guess = 0;
    position_guess.y_guess = 0;
    first_pair_guess.value_0c_guess = 0;
    first_pair_guess.value_08_guess = 0;
    first_pair_guess.value_04_guess = 0;
    first_pair_guess.value_00_guess = 0;
    second_pair_guess.value_0c_guess = 0;
    second_pair_guess.value_08_guess = 0;
    second_pair_guess.value_04_guess = 0;
    second_pair_guess.value_00_guess = 0;
    char has_pair_guess = 0;
    if (first_guess != 0 && first_guess->source_028_guess != 0) {
        second_pair_guess.Combine_guess(&values_guess[0],
                                        first_guess->source_028_guess->GetValue_guess(&values_guess[1]));
        has_pair_guess = 1;
    }

    int count_guess = 0x1f;
    do {
        if (*slot_guess != 0 && ((CXWnd*)(*slot_guess))->IsReallyVisible() != 0) {
            DataAccess_guess* access_guess = (*slot_guess)->access_140_guess;
            int* value_guess = access_guess->value_010_guess;
            int has_value_guess = value_guess != 0 ? *value_guess : 0;
            if (has_value_guess != 0) {
                first_pair_guess.Combine_guess(&values_guess[1],
                                               (*slot_guess)->GetValue_guess(&values_guess[0]));
                if (first_key_guess == -1) {
                    first_key_guess = first_pair_guess.value_00_guess;
                }
                position_guess.x_guess = first_pair_guess.value_08_guess - 5;
                if (first_pair_guess.value_00_guess == first_key_guess) {
                    position_guess.y_guess = first_pair_guess.value_04_guess + 2;
                } else {
                    position_guess.y_guess = first_pair_guess.value_04_guess + 0x16;
                }
                if (has_pair_guess == 0 ||
                    (position_guess.y_guess <= second_pair_guess.value_0c_guess - 0xf &&
                     position_guess.y_guess >= second_pair_guess.value_04_guess)) {
                    (*slot_guess)->Dispatch_guess(&position_guess.x_guess);
                }
            }
        }
        ++slot_guess;
        --count_guess;
    } while (count_guess != 0);
    return 0;
}

// Every 500 ms closes the window once the player is farther than 1.5 x corpse range + 20 from the corpse.
// FUNCTION: TITANIUM 0x0052B1F1
void Interface_guess::OnProcessFrame_guess() {
    if (active_05c_guess != 0) {
        if (g_activeFlags_guess->time_148_guess >= value_1e0_guess) {
            value_1e0_guess = g_activeFlags_guess->time_148_guess + 500;
            if (g_runtimeState_guess != 0) {
                float range_guess = g_runtimeState_guess->range_238_guess;
                if (g_activeFlags_guess->PlayerDistance_guess(g_runtimeState_guess,
                                                       g_systemState_guess, 0.0f) >
                    range_guess * 1.5f + 20.0f) {
                    Slot34_guess();
                }
            }
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Broadcast: writes every item's link into the current chat input, separated by g_separator_guess.
// FUNCTION: TITANIUM 0x0052B272
void Interface_guess::InsertLootLinksInChat_guess() {
    TextRoot_guess* root_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
    TextSink_guess* sink_guess = root_guess->sink_160_guess;
    if (sink_guess != 0) {
        char buffer_guess[0x100];
        int index_guess = 0;
        for (; index_guess < 0x1F; ++index_guess) {
            RefObject_guess* object_guess = objects_1e8_guess[index_guess];
            if (object_guess != 0) {
                if (index_guess != 0) {
                    sink_guess->SetText_guess(g_separator_guess, 0);
                }
                object_guess->GetDescription_guess(buffer_guess, 0x100);
                sink_guess->AddEntry_guess(object_guess->GetName_guess(),
                                           buffer_guess);
            }
        }
        ((CXWnd*)sink_guess)->SetFocus();
    }
}

// Loot window clicks: Done closes the window (virtual slot 34), Broadcast puts the corpse's items into the
// active chat input (0x0052B272); everything else goes to CSidlScreenWnd.
// FUNCTION: TITANIUM 0x0052B320
int LootWnd_guess::WndNotification_guess(CXWnd* sender_guess,
                                        unsigned int message_guess,
                                        void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == done_2e8_guess) {
            ((Interface_guess*)this)->Slot34_guess();
            return 0;
        }
        if (sender_guess == broadcast_2ec_guess) {
            ((Interface_guess*)this)->InsertLootLinksInChat_guess();
            return 0;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess,
                                                     message_guess, data_guess);
}

// Item from the server: an unknown kind is dropped with string 1366 "Got a bogus item, deleting it";
// otherwise it fills the first free slot, keyed by its corpse slot.
// FUNCTION: TITANIUM 0x0052B35F
void Interface_guess::AddLootItem_guess(RefObject_guess* object) {
    if (Query_guess() != 0 && object != 0) {
        if (object->GetItemId_guess() == 0) {
            g_messageManager_guess->dsp_chat(
                g_stringManager_guess->getString(0x556, 0, 0xd, 1));
            object->Release_guess(1);
        } else {
            for (int index_guess = 0; index_guess < 0x1F; ++index_guess) {
                if (keys_164_guess[index_guess] == -1) {
                    keys_164_guess[index_guess] = object->key_04c_guess;
                    objects_1e8_guess[index_guess] = object;
                    break;
                }
            }
        }
    }
}

// Loot reply for corpse slot `value`: one fewer pending request, time logged in a 10-entry ring (type 8). A
// negative value shows string 1370 "You may not loot that item from this corpse."; otherwise the item leaves
// its slot.
// FUNCTION: TITANIUM 0x0052B3D8
void Interface_guess::HandleLootItemReply_guess(int value) {
    if (g_count_9248d0_guess > 0) {
        --g_count_9248d0_guess;
    } else {
        g_count_9248d0_guess = 0;
    }
    ++g_index_92398c_guess;
    if (g_index_92398c_guess > 9) {
        g_index_92398c_guess = 0;
    }
    EQ_ARRAY(int, 0x00923964)[g_index_92398c_guess] = 8;
    EQ_ARRAY(int, 0x0092393C)[g_index_92398c_guess] = GetClientTime_guess();
    if (value < 0) {
        g_messageManager_guess->dsp_chat(
            g_stringManager_guess->getString(0x55a, 0, 0x111, 1));
    } else {
        for (int index_guess = 0; index_guess < 0x1F; ++index_guess) {
            if (value == keys_164_guess[index_guess]) {
                // Never true; kept as decompiled (match shape).
                if (index_guess < 0) {
                    return;
                }
                RefObject_guess* object = objects_1e8_guess[index_guess];
                if (object != 0) {
                    object->Release_guess(1);
                    objects_1e8_guess[index_guess] = 0;
                }
                break;
            }
        }
    }
}

// Loot window constructor: clears the 31 item slots, finds LW_CorpseName, Done, Broadcast, LootInvWnd and
// the slots LW_LootSlot0-30.
// FUNCTION: TITANIUM 0x0052B4C9
LootWnd_guess::LootWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "LootWnd") {
    for (int index_guess = 0; index_guess < 0x1F; ++index_guess) {
        objects_1e8_guess[index_guess] = 0;
        keys_164_guess[index_guess] = -1;
        slots_268_guess[index_guess] = 0;
    }
    corpse_2e4_guess = 0;
    lootInvWnd_264_guess = 0;
    done_2e8_guess = 0;
    broadcast_2ec_guess = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10000;
        field_158_guess = 0x17;
        field_08C_guess = 0x11;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        corpse_2e4_guess = ((CSidlScreenWnd*)this)->GetChildItem("LW_CorpseName");
        done_2e8_guess = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        broadcast_2ec_guess = ((CSidlScreenWnd*)this)->GetChildItem("BroadcastButton");
        lootInvWnd_264_guess = ((CSidlScreenWnd*)this)->GetChildItem("LootInvWnd");
        if (lootInvWnd_264_guess != 0) {
            ((LootWindowFields_guess*)lootInvWnd_264_guess)->field_0b1 = 0;
            ((LootWindowFields_guess*)lootInvWnd_264_guess)->field_065 &= 0xf7;
        }
        char name_guess[0x100];
        int index_guess;
        for (index_guess = 0; index_guess < 0x1F; ++index_guess) {
            sprintf(name_guess, "LW_LootSlot%d", index_guess);
            slots_268_guess[index_guess] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        value_1e0_guess = 0;
        state_160_guess = 0;
    }
}
