// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 230: a hint from compare/tumap.py.
// The Tracking window (TrackingWnd): the OP_Track reply fills up to 1000 entries
// (spawn, distance, original index, flags), which are filtered by con colour, sorted and listed. Entry flags:
// 1 hidden, 2 player, 4 player's pet; con 0x10 red, 0x20 yellow, 0x40 white, 0x80 blue, 0x100 green,
// 0x200 light blue. Thing_guess, Finder_guess and Callback_guess::OnDone_guess are views of
// CTrackingWnd_guess.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CChatManager.h"

#define g_voidConnection_guess EQ_ARRAY(int, 0x00905CA0)

// OP_TrackTarget with a spawn id; 0 stops tracking.
// FUNCTION: TITANIUM 0x005660CC
void __stdcall SendTrackTarget_guess(int argument)
{
    EQSendMessage(g_voidConnection_guess, OP_TrackTarget, &argument, 4, 1);
}

#define g_trackState_guess EQ_GLOBAL(int, 0x00923CC4)

struct Callback_guess {
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

    // EXTERNAL: TITANIUM 0x005A3100 ??1Callback_guess@@UAE@XZ
    virtual ~Callback_guess();

    // EXTERNAL: TITANIUM 0x005A3900 Callback_guess::Callback_guess
    Callback_guess(CXWnd* parent_guess, const CXStr& name_guess);

    void OnDone_guess();
};

// Done button: a track still marked pending (0x35 at 0x923CC4, set by Track) is cancelled with
// OP_TrackTarget 0, then the window closes (vtable slot 34).
// FUNCTION: TITANIUM 0x00566312
void Callback_guess::OnDone_guess() {
    if (g_trackState_guess == 0x35) {
        g_trackState_guess |= -1;
        SendTrackTarget_guess(0);
    }
    Slot34_guess();
}

struct Record_guess {
    int field0_guess; // 0x0
    float field4_guess; // 0x4
    int field8_guess; // 0x8
    int fieldc_guess; // 0xC
};

struct Thing_guess {
    Record_guess prefix_guess[22]; // 0x0
    Record_guess records_guess[64]; // 0x160
    void ClearEntry_guess(int index_guess);
    int GetEntryColor_guess(int index_guess);
};

// Empties entry `index_guess`: no spawn, original index -1, no flags, distance -1.
// FUNCTION: TITANIUM 0x00566337
void Thing_guess::ClearEntry_guess(int index_guess) {
    prefix_guess[index_guess + 22].field0_guess = 0;
    records_guess[index_guess].field8_guess |= -1;
    records_guess[index_guess].fieldc_guess = 0;
    records_guess[index_guess].field4_guess = -1.0f;
}

#define g_stateLookupEnabled_guess EQ_GLOBAL(char, 0x009043A4)
#define g_stateLookupLabels_guess EQ_ARRAY(char, 0x0090424D)
#define g_stateLookupValues_guess EQ_ARRAY(int, 0x00904390)

// The entry's list colour: user colour index by con (0x0E green, 0x12 light blue, 0x10 blue, 0x0A white,
// 0x0F yellow, 0x0D red), or for players 0x0C when they are in one of the 5 group slots (0x90424D,
// 0x904390) and 7 otherwise; GetRGBAFromIndex turns it into a colour.
// FUNCTION: TITANIUM 0x005660EA
// @early-stop: budget, structural ndiff=14
int Thing_guess::GetEntryColor_guess(int index_guess) {
    unsigned int value_guess = records_guess[index_guess].fieldc_guess;
    char signedValue_guess = (char)value_guess;
    if ((value_guess & 2) == 0) {
        if ((value_guess & 0x100) != 0) {
            value_guess = 0x0E;
        } else {
            if ((signedValue_guess >> 7) != 0) {
                value_guess = 0x10;
            } else if ((value_guess & 0x200) != 0) {
                value_guess = 0x12;
            } else if ((value_guess & 0x40) != 0) {
                value_guess = 0x0A;
            } else {
                int signedInteger_guess = signedValue_guess;
                value_guess = ((signedInteger_guess & 0x20U) | 0xD0) >> 4;
            }
        }
    } else {
        bool matched_guess = false;
        if (g_stateLookupEnabled_guess != 0) {
            int* valuePointer_guess = g_stateLookupValues_guess;
            char* label_guess = g_stateLookupLabels_guess;
            do {
                if (*label_guess != 0 && *valuePointer_guess != 0 &&
                    *valuePointer_guess == records_guess[index_guess].field0_guess)
                    matched_guess = true;
                label_guess += 0x40;
                ++valuePointer_guess;
            } while ((int)label_guess < (int)(g_stateLookupLabels_guess + 0x140));
        }
        if (matched_guess)
            value_guess = 0x0C;
        else
            value_guess = 7;
    }
    return pinstCChatManager_guess->GetRGBAFromIndex(value_guess);
}

struct CXStr;

struct ListSlots_guess {
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
    virtual void Slot76_guess();
};

struct List_guess : ListSlots_guess {
    char prefix_guess[0x118];
    int count_guess; // 0x11c
    int* values_guess; // 0x120

    // EXTERNAL: TITANIUM 0x00598580 List_guess::ClearAllSel
    void ClearAllSel();

    // EXTERNAL: TITANIUM 0x0059B9D0 List_guess::AddString
    int AddString(const CXStr& text_guess, unsigned long value_guess, unsigned int index_guess, const CTextureAnimation* flag_guess);

    // EXTERNAL: TITANIUM 0x00597BE0 List_guess::GetCurSel
    int GetCurSel();

    // EXTERNAL: TITANIUM 0x00597ED0 List_guess::GetItemData
    int GetItemData(int index_guess);

    // EXTERNAL: TITANIUM 0x0059C130 List_guess::Remove_guess
    void Remove_guess(int index_guess);

    // EXTERNAL: TITANIUM 0x00597C20 List_guess::SetCurSel
    void SetCurSel(int index_guess);
};

struct Finder_guess {
    char prefix_guess[0x3ff0];
    List_guess* list_guess; // 0x3ff0

    int FindListRow_guess(int value_guess);
    void RemoveFromListWndByData_guess(int value_guess);
};

// List row whose item data is entry `value_guess`, or -1.
// FUNCTION: TITANIUM 0x00566365
int Finder_guess::FindListRow_guess(int value_guess) {
    if (list_guess != 0) {
        int count_guess = list_guess->count_guess;
        for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
            if (list_guess->GetItemData(index_guess) == value_guess)
                return index_guess;
        }
    }
    return -1;
}

struct ModeRecord_guess {
    char prefix_guess[0x119c];
    unsigned char mode_guess; // 0x119c
    char padding_guess[7];
    int level_guess; // 0x11a4
};

struct ModeList_guess {
    int field0_guess; // 0x0

    // EXTERNAL: TITANIUM 0x005EC220 ModeList_guess::GetCharInfo2
    ModeRecord_guess* GetCharInfo2();
};

struct ModeBase_guess {
    int field0_guess; // 0x0
};

struct ModeBaseWithList_guess : ModeBase_guess, ModeList_guess {
};

struct ModeRootPrefix_guess {
    int field0_guess; // 0x0
    int field4_guess; // 0x4
};

struct ModeRoot_guess : ModeRootPrefix_guess, virtual ModeBaseWithList_guess {
};

#define g_modeRoot_guess EQ_GLOBAL(ModeRoot_guess*, 0x00905D00)
#define g_trackSortMode_guess EQ_GLOBAL(int, 0x00923CAC)

union NotifyFlags_guess {
    int all_guess;
    unsigned char bits_guess;
};

#define g_trackFilterBits_guess EQ_GLOBAL(NotifyFlags_guess, 0x00923CB0)

struct Control_guess {
    char prefix_guess[0x5d];
    unsigned char state_guess; // 0x5d

    // EXTERNAL: TITANIUM 0x0059C360 Control_guess::Notify_guess
    void Notify_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x005BB140 Control_guess::SetCheck
    void SetCheck(int value_guess);
};

struct Target_guess {
    char prefix_guess[0x120];
    int field120_guess; // 0x120
    char prefix124_guess[0x120]; // 0x124
    unsigned char field244_guess; // 0x244
    char prefix245_guess[7]; // 0x245
    unsigned char field24c_guess; // 0x24c
    char prefix24d_guess[0xb]; // 0x24d
    int field258_guess; // 0x258
    int field25c_guess; // 0x25c
};

struct Entry_guess {
    Target_guess* target_guess; // 0x0
    float field4_guess; // 0x4
    int field8_guess; // 0x8
    int fieldc_guess; // 0xC
};

struct MessageBuffer_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 MessageBuffer_guess::Store_guess
    char* Store_guess(void* source_guess);

    // EXTERNAL: TITANIUM 0x004982C6 MessageBuffer_guess::dsp_chat
    void dsp_chat(const char* text_guess, int id_guess, bool flag_guess);
};

#define g_messageBuffer_guess EQ_GLOBAL(MessageBuffer_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* buffer_guess, int format_guess, ...);

// EXTERNAL: TITANIUM 0x00471607 do_trackfilter_guess
void __cdecl do_trackfilter_guess(int unused_guess, char* text_guess);

// EXTERNAL: TITANIUM 0x0047137E do_tracksort_guess
void __cdecl do_tracksort_guess(int unused_guess, char* text_guess);

// EXTERNAL: TITANIUM 0x00468781 do_trackplayers_guess
void __cdecl do_trackplayers_guess(int unused_guess, char* text_guess);

#define g_callbackTarget_guess EQ_GLOBAL(Target_guess*, 0x00923CD4)
#define g_callbackTimer_guess EQ_GLOBAL(unsigned int, 0x00923CC8)
#define g_callbackDeadline_guess EQ_GLOBAL(unsigned int, 0x00923CCC)
#define g_callbackFlag_guess EQ_GLOBAL(int, 0x00923CD0)

// EXTERNAL: TITANIUM 0x0065EE68 ??_7CTrackingWnd_guess@@6B@
struct CTrackingWnd_guess : Callback_guess {
    CTrackingWnd_guess(CXWnd* parent_guess);

    char prefix_guess[0x158];
    int field15c_guess; // 0x15c
    Entry_guess entries_guess[1000]; // 0x160
    Entry_guess scratch_guess; // 0x3fe0
    List_guess* list_guess; // 0x3ff0
    Control_guess* control3ff4_guess; // 0x3ff4
    Control_guess* control3ff8_guess; // 0x3ff8
    Control_guess* control3ffc_guess; // 0x3ffc
    Control_guess* control4000_guess; // 0x4000
    Control_guess* control4004_guess; // 0x4004
    Control_guess* control4008_guess; // 0x4008
    Control_guess* control400c_guess; // 0x400c
    Control_guess* control4010_guess; // 0x4010
    Control_guess* control4014_guess; // 0x4014
    Control_guess* control4018_guess; // 0x4018

    // EXTERNAL: TITANIUM 0x005660CC CTrackingWnd_guess::SendTrackTarget_guess
    void SendTrackTarget_guess(int value_guess);

    // EXTERNAL: TITANIUM 0x005A2230 CTrackingWnd_guess::WndNotification
    void WndNotification(Control_guess* sender_guess, int kind_guess, int value_guess);

    void WndNotification_guess(Control_guess* sender_guess, int kind_guess, int value_guess);

    void ClearAndNotify_guess();
    void RequestTrackList_guess();
    bool Reset_guess();
    void UpdateTrackingControls_guess();
    void OnProcessFrame_guess();
    void RemoveSpawn_guess(Target_guess* target_guess);
    void HandleTrackReply_guess(struct Source_guess* source_guess, int count_guess);

    // EXTERNAL: TITANIUM 0x00566CE6 CTrackingWnd_guess::SortTrackingList_guess
    void SortTrackingList_guess(char value_guess);

    void ApplyTrackingFilters_guess(char flag_guess);

    // EXTERNAL: TITANIUM 0x00566194 CTrackingWnd_guess::RefreshTrackingList_guess
    void RefreshTrackingList_guess(bool flag_guess);

    // EXTERNAL: TITANIUM 0x005A0E50 CTrackingWnd_guess::OnProcessFrame
    void OnProcessFrame();
};

struct TimerState_guess {
    char prefix_guess[0x148];
    unsigned int tick_guess; // 0x148
};

#define g_timerState_guess EQ_GLOBAL(TimerState_guess*, 0x00905D24)

// Refills TRW_TrackingList with the entries not hidden (flag 1), coloured by GetEntryColor_guess; a player's
// pet gets a ':' prefix. With `flag_guess` the selected spawn (id +0x258) stays selected.
// FUNCTION: TITANIUM 0x00566194
// @early-stop: budget, diff ndiff=24
void CTrackingWnd_guess::RefreshTrackingList_guess(bool flag_guess) {
    char buffer_guess[80];
    int index_guess;

    if (list_guess != 0) {
        int selected_guess = -1;
        if (flag_guess) {
            index_guess = list_guess->GetCurSel();
            if (index_guess >= 0)
                selected_guess = list_guess->GetItemData(index_guess);
        }
        list_guess->ClearAllSel();
        list_guess->Slot76_guess();

        index_guess = 0;
        while (index_guess < 1000) {
            Entry_guess* entry_guess = &entries_guess[index_guess];
            if (entry_guess->target_guess != 0 && (entry_guess->fieldc_guess & 1) == 0) {
                int value_guess = ((Thing_guess*)this)->GetEntryColor_guess(index_guess);
                if ((entry_guess->fieldc_guess & 4) != 0) {
                    strcpy(buffer_guess, EQ_ARRAY(char, 0x00641584));
                    strcat(buffer_guess, g_messageBuffer_guess->Store_guess(&entry_guess->target_guess->field120_guess));
                } else {
                    strcpy(buffer_guess, g_messageBuffer_guess->Store_guess(&entry_guess->target_guess->field120_guess));
                }

                int result_guess = list_guess->AddString(CXStr(buffer_guess), value_guess, index_guess, 0);

                if (selected_guess >= 0) {
                    Entry_guess* selected_entry_guess = &entries_guess[selected_guess];
                    if (selected_entry_guess->target_guess != 0 &&
                        entry_guess->target_guess->field258_guess == selected_entry_guess->target_guess->field258_guess)
                        list_guess->SetCurSel(result_guess);
                }
            }
            ++index_guess;
        }
    }
}

// Sorts the entries in place by the sort combobox (0x923CAC): 0 normal (back to server order by the
// original index), 1 distance, 3 reverse distance, 2 consider (highest level first), 4 reverse consider;
// consider modes only move NPCs. Only a class 4 (Ranger) character sorts; everyone else gets server order.
// FUNCTION: TITANIUM 0x00566CE6
// @early-stop: budget, structural ndiff=273
void CTrackingWnd_guess::SortTrackingList_guess(char notify_guess) {
    int sortMode_guess = 0;
    if (g_modeRoot_guess != 0 &&
        g_modeRoot_guess->GetCharInfo2()->mode_guess == 4)
        sortMode_guess = g_trackSortMode_guess;

    Entry_guess* current_guess = entries_guess;
    int index_guess = 1;
    do {
        if (sortMode_guess == 0) {
            int targetIndex_guess = index_guess - 1;
            while (current_guess->field8_guess != targetIndex_guess) {
                int entryIndex_guess = current_guess->field8_guess;
                if (entryIndex_guess == -1)
                    break;
                Entry_guess* entry_guess = &entries_guess[entryIndex_guess];
                scratch_guess = *entry_guess;
                *entry_guess = *current_guess;
                *current_guess = scratch_guess;
            }
        } else if (sortMode_guess == 1) {
            if (index_guess < 1000) {
                int remaining_guess = 1000 - index_guess;
                Entry_guess* next_guess = current_guess + 1;
                do {
                    if (-0.0001f <= next_guess->field4_guess &&
                        next_guess->field4_guess < current_guess->field4_guess) {
                        scratch_guess = *current_guess;
                        *current_guess = *next_guess;
                        *next_guess = scratch_guess;
                    }
                    --remaining_guess;
                    ++next_guess;
                } while (remaining_guess != 0);
            }
        } else if (sortMode_guess == 3) {
            if (index_guess < 1000) {
                int remaining_guess = 1000 - index_guess;
                Entry_guess* next_guess = current_guess + 1;
                do {
                    if (-0.0001f <= next_guess->field4_guess &&
                        current_guess->field4_guess < next_guess->field4_guess) {
                        scratch_guess = *current_guess;
                        *current_guess = *next_guess;
                        *next_guess = scratch_guess;
                    }
                    --remaining_guess;
                    ++next_guess;
                } while (remaining_guess != 0);
            }
        } else if (sortMode_guess == 2) {
            if (current_guess->target_guess != 0 &&
                current_guess->target_guess->field244_guess == 1 && index_guess < 1000) {
                int scanIndex_guess = index_guess;
                Entry_guess* next_guess = current_guess + 1;
                while (scanIndex_guess < 1000) {
                    if (next_guess->target_guess != 0) {
                        if (next_guess->target_guess->field244_guess != 1) {
                            scratch_guess = *current_guess;
                            *current_guess = entries_guess[scanIndex_guess];
                            entries_guess[scanIndex_guess] = scratch_guess;
                            break;
                        }
                        if (current_guess->target_guess->field24c_guess <
                            next_guess->target_guess->field24c_guess) {
                            scratch_guess = *current_guess;
                            *current_guess = *next_guess;
                            *next_guess = scratch_guess;
                        }
                    }
                    ++scanIndex_guess;
                    ++next_guess;
                }
            }
        } else if (sortMode_guess == 4) {
            if (current_guess->target_guess != 0 &&
                current_guess->target_guess->field244_guess == 1 && index_guess < 1000) {
                int scanIndex_guess = index_guess;
                Entry_guess* next_guess = current_guess + 1;
                while (scanIndex_guess < 1000) {
                    if (next_guess->target_guess != 0) {
                        if (next_guess->target_guess->field244_guess != 1) {
                            scratch_guess = *current_guess;
                            *current_guess = entries_guess[scanIndex_guess];
                            entries_guess[scanIndex_guess] = scratch_guess;
                            break;
                        }
                        if (next_guess->target_guess->field24c_guess <
                            current_guess->target_guess->field24c_guess) {
                            scratch_guess = *current_guess;
                            *current_guess = *next_guess;
                            *next_guess = scratch_guess;
                        }
                    }
                    ++scanIndex_guess;
                    ++next_guess;
                }
            }
        }

        ++current_guess;
        ++index_guess;
    } while (index_guess - 1 < 1000);

    if (notify_guess != 0)
        RefreshTrackingList_guess(0);
}

// EXTERNAL: TITANIUM 0x0059DD30 IsPanelActive_guess
char __cdecl IsPanelActive_guess();

struct SidlPiece_guess {
    char prefix_guess[0x60];
    unsigned int flags60_guess; // 0x60
};

struct WndBytes_guess {
    char prefix_guess[0x66];
    unsigned char flags66_guess; // 0x66
};

struct Combo_guess {
    // EXTERNAL: TITANIUM 0x0059C330 Combo_guess::SetColors_guess
    void SetColors_guess(int a_guess, unsigned long b_guess, unsigned long c_guess);

    // EXTERNAL: TITANIUM 0x0059C8D0 Combo_guess::AddString_guess
    void AddString_guess(const CXStr& text_guess);
};

// Builds TrackingWnd: sort choices normal/distance/consider/rdistance/rconsider (strings 13120,
// 13144-13147), track players off/on/Group (12946, 12947, 13148), six con filter buttons, and empties all
// 1001 entries (the loop's `<= 1000` also clears the scratch entry after the array).
// FUNCTION: TITANIUM 0x005663A4
CTrackingWnd_guess::CTrackingWnd_guess(CXWnd* parent_guess)
    : Callback_guess(parent_guess, "TrackingWnd") {
    if (((CSidlScreenWnd*)this)->SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->WindowStyle |=
            ((SidlPiece_guess*)((CSidlScreenWnd*)this)->SidlPiece)->flags60_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();

        list_guess = (List_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_TrackingList");
        if (list_guess != 0) {
            ((WndBytes_guess*)list_guess)->flags66_guess &= 0xdf;
            ((CListWnd*)list_guess)->SetColors(0xffffffff, 0xff8aa3ff, 0xff808080);
        }
        control4014_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_TrackPlayersCombobox");
        control4018_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_TrackSortCombobox");

        if (control4018_guess != 0) {
            ((Combo_guess*)control4018_guess)->SetColors_guess(-1, 0xffffff00, 0xff808080);
            ((Combo_guess*)control4018_guess)->AddString_guess(pStringTable->getString(0x3340, 0));
            ((Combo_guess*)control4018_guess)->AddString_guess(pStringTable->getString(0x3358, 0));
            ((Combo_guess*)control4018_guess)->AddString_guess(pStringTable->getString(0x3359, 0));
            ((Combo_guess*)control4018_guess)->AddString_guess(pStringTable->getString(0x335a, 0));
            ((Combo_guess*)control4018_guess)->AddString_guess(pStringTable->getString(0x335b, 0));
        }
        if (control4014_guess != 0) {
            ((Combo_guess*)control4014_guess)->SetColors_guess(-1, 0xffffff00, 0xff808080);
            ((Combo_guess*)control4014_guess)->AddString_guess(pStringTable->getString(0x3292, 0));
            ((Combo_guess*)control4014_guess)->AddString_guess(pStringTable->getString(0x3293, 0));
            ((Combo_guess*)control4014_guess)->AddString_guess(pStringTable->getString(0x335c, 0));
        }

        control3ff4_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_TrackButton");
        control3ff8_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterRedButton");
        control3ffc_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterYellowButton");
        control4000_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterWhiteButton");
        control4004_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterBlueButton");
        control4008_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterLightBlueButton");
        control400c_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("TRW_FilterGreenButton");
        control4010_guess = (Control_guess*)((CSidlScreenWnd*)this)->GetChildItem("DoneButton");

        for (int index_guess = 0; index_guess <= 1000; ++index_guess)
            ((Thing_guess*)this)->ClearEntry_guess(index_guess);
    }
}

// Track: sends OP_TrackTarget for the selected spawn, remembers it with a 6-minute (360000 ms) deadline,
// prints "You begin tracking %1." (string 12040, chat colour 270) and closes. The filter buttons, sort and
// players comboboxes run the slash-command handlers with one-letter arguments: do_trackfilter_guess
// R/Y/W/B/L/G, do_tracksort_guess N/D/C/RD/RC, do_trackplayers_guess off/on/Group.
// FUNCTION: TITANIUM 0x005668FA
void CTrackingWnd_guess::WndNotification_guess(Control_guess* sender_guess, int kind_guess, int value_guess) {
    char buffer_guess[512];

    if (kind_guess == 1) {
        if (sender_guess == control4010_guess)
            OnDone_guess();

        if (sender_guess == control3ff4_guess) {
            if (list_guess != 0) {
                int current_guess = list_guess->GetCurSel();
                if (current_guess >= 0) {
                    int index_guess = list_guess->GetItemData(current_guess);
                    Entry_guess* entry_guess = &entries_guess[index_guess];
                    if (entry_guess->target_guess != 0) {
                        g_trackState_guess = 0x35;
                        g_callbackTarget_guess = entry_guess->target_guess;
                        SendTrackTarget_guess(entry_guess->target_guess->field258_guess);

                        g_callbackTimer_guess = g_timerState_guess->tick_guess;
                        g_callbackDeadline_guess = g_callbackTimer_guess + 360000;
                        g_callbackFlag_guess = 0;

                        FUN_0046da4a_guess(buffer_guess, 0x2f08,
                            g_messageBuffer_guess->Store_guess(&g_callbackTarget_guess->field120_guess),
                            0, 0, 0, 0, 0, 0, 0, 0);
                        g_messageBuffer_guess->dsp_chat(buffer_guess, 0x10e, 1);
                        Slot34_guess();
                    }
                }
            }
        }
        else if (sender_guess == control3ff8_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x006479F4));
        else if (sender_guess == control3ffc_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x00646EA4));
        else if (sender_guess == control4000_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x00641BA0));
        else if (sender_guess == control4004_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x00647A38));
        else if (sender_guess == control4008_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x00647A50));
        else if (sender_guess == control400c_guess)
            do_trackfilter_guess(0, EQ_ARRAY(char, 0x00647A88));
        else if (sender_guess == control4018_guess) {
            if (value_guess == 0)
                do_tracksort_guess(0, EQ_ARRAY(char, 0x0064790C));
            else if (value_guess == 1)
                do_tracksort_guess(0, EQ_ARRAY(char, 0x00647A44));
            else if (value_guess == 2)
                do_tracksort_guess(0, EQ_ARRAY(char, 0x0063F584));
            else if (value_guess == 3)
                do_tracksort_guess(0, EQ_ARRAY(char, 0x0065EF98));
            else if (value_guess == 4)
                do_tracksort_guess(0, EQ_ARRAY(char, 0x0065EF94));
        }
        else if (sender_guess == control4014_guess) {
            if (value_guess == 0)
                do_trackplayers_guess(0, pStringTable->getString(0x3292, 0));
            else if (value_guess == 1)
                do_trackplayers_guess(0, pStringTable->getString(0x3293, 0));
            else if (value_guess == 2)
                do_trackplayers_guess(0, pStringTable->getString(0x335c, 0));
        }
    }
    WndNotification(sender_guess, kind_guess, value_guess);
}

// Shows the saved settings in the controls: sort (0x923CAC), track players (0x923CA8) and the six filter
// bits at 0x923CB0 (1 green, 2 blue, 4 white, 8 yellow, 0x10 red, 0x20 light blue). Non-rangers get sort
// and filters reset to 0 and those controls disabled.
// FUNCTION: TITANIUM 0x00566B1F
void CTrackingWnd_guess::UpdateTrackingControls_guess() {
    if (control4018_guess != 0) {
        if (g_modeRoot_guess == 0) {
            g_trackSortMode_guess = 0;
            g_trackFilterBits_guess.all_guess = 0;
        } else {
            ModeBaseWithList_guess* modeBase_guess = g_modeRoot_guess;
            if (modeBase_guess->GetCharInfo2()->mode_guess != 4) {
                g_trackSortMode_guess = 0;
                g_trackFilterBits_guess.all_guess = 0;
            }
        }
        control4018_guess->Notify_guess(g_trackSortMode_guess);
    }
    if (control4014_guess != 0)
        control4014_guess->Notify_guess(EQ_GLOBAL(int, 0x00923CA8));
    if (control400c_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 1)
            control400c_guess->SetCheck(1);
        else
            control400c_guess->SetCheck(0);
    }
    if (control4004_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 2)
            control4004_guess->SetCheck(1);
        else
            control4004_guess->SetCheck(0);
    }
    if (control4000_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 4)
            control4000_guess->SetCheck(1);
        else
            control4000_guess->SetCheck(0);
    }
    if (control3ffc_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 8)
            control3ffc_guess->SetCheck(1);
        else
            control3ffc_guess->SetCheck(0);
    }
    if (control3ff8_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 0x10)
            control3ff8_guess->SetCheck(1);
        else
            control3ff8_guess->SetCheck(0);
    }
    if (control4008_guess != 0) {
        if (g_trackFilterBits_guess.bits_guess & 0x20)
            control4008_guess->SetCheck(1);
        else
            control4008_guess->SetCheck(0);
    }

    if (g_modeRoot_guess == 0) {
        if (control4018_guess != 0)
            control4018_guess->state_guess = 0;
        if (control3ff8_guess != 0)
            control3ff8_guess->state_guess = 0;
        if (control3ffc_guess != 0)
            control3ffc_guess->state_guess = 0;
        if (control4000_guess != 0)
            control4000_guess->state_guess = 0;
        if (control4004_guess != 0)
            control4004_guess->state_guess = 0;
        if (control4008_guess != 0)
            control4008_guess->state_guess = 0;
        if (control400c_guess != 0)
            control400c_guess->state_guess = 0;
    } else {
        ModeBaseWithList_guess* modeBase_guess = g_modeRoot_guess;
        if (modeBase_guess->GetCharInfo2()->mode_guess != 4) {
            if (control4018_guess != 0)
                control4018_guess->state_guess = 0;
            if (control3ff8_guess != 0)
                control3ff8_guess->state_guess = 0;
            if (control3ffc_guess != 0)
                control3ffc_guess->state_guess = 0;
            if (control4000_guess != 0)
                control4000_guess->state_guess = 0;
            if (control4004_guess != 0)
                control4004_guess->state_guess = 0;
            if (control4008_guess != 0)
                control4008_guess->state_guess = 0;
            if (control400c_guess != 0)
                control400c_guess->state_guess = 0;
        }
    }
}

// EXTERNAL: TITANIUM 0x00566337 ClearEntry_guess
void __stdcall ClearEntry_guess(int index_guess);

// EXTERNAL: TITANIUM 0x00566194 RefreshTrackingList_guess
void __stdcall RefreshTrackingList_guess(int value_guess);

// Empties every entry and the list, then asks the server for a new track list (OP_Track, no payload).
// FUNCTION: TITANIUM 0x00566CB3
void CTrackingWnd_guess::RequestTrackList_guess() {
    for (int index_guess = 0; index_guess < 1000; ++index_guess)
        ClearEntry_guess(index_guess);
    ::RefreshTrackingList_guess(0);
    EQSendMessage(g_voidConnection_guess, OP_Track, 0, 0, 1);
}

struct Slot_guess {
    char active_guess; // 0x0
    char padding_guess[0x3f];
};

#define g_slots_guess EQ_ARRAY(Slot_guess, 0x0090424D)
#define g_slotTargets_guess EQ_ARRAY(Target_guess*, 0x00904390)
#define g_slotsUsed_guess EQ_GLOBAL(char, 0x009043A4)
#define g_trackPlayersMode_guess EQ_GLOBAL(int, 0x00923CA8)

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
Target_guess* __cdecl FUN_00401b28_guess(int id_guess);

// Sets each entry's con flag from the level difference, and hides it (flag 1) when a ranger's NPC filter
// matches or the track-players setting excludes a player (0 off: all, 2 Group: those not in the group).
// The green line is 3/4 of the player's level up to 60, level - 15 above. Green spawns within 5 levels of it
// are light blue; the band narrows by one below player level 55, 41 and 31 each, and is gone below 8.
// FUNCTION: TITANIUM 0x00566FE6
// @early-stop: budget, structural ndiff=79
void CTrackingWnd_guess::ApplyTrackingFilters_guess(char flag_guess) {
    for (int index_guess = 0; index_guess < 1000; ++index_guess) {
        Entry_guess* entry_guess = &entries_guess[index_guess];
        if (entry_guess->target_guess == 0)
            continue;

        entry_guess->fieldc_guess = 0;
        int level_guess = 1;
        int hit_guess = 0;
        if (g_modeRoot_guess != 0) {
            ModeBaseWithList_guess* modeBase_guess = g_modeRoot_guess;
            level_guess = modeBase_guess->GetCharInfo2()->level_guess;
        }

        int diff_guess = entry_guess->target_guess->field24c_guess - level_guess;
        int threshold_guess;
        if (level_guess <= 0x3c)
            threshold_guess = (level_guess * 3) / 4;
        else
            threshold_guess = level_guess - 15;

        if (threshold_guess > entry_guess->target_guess->field24c_guess && diff_guess < -3) {
            entry_guess->fieldc_guess |= 0x100;
            int gap_guess = entry_guess->target_guess->field24c_guess - threshold_guess;
            if (level_guess < 0x37)
                --gap_guess;
            if (level_guess < 0x29)
                --gap_guess;
            if (level_guess < 0x1f)
                --gap_guess;
            if (gap_guess >= -5 && level_guess >= 8)
                entry_guess->fieldc_guess = 0x200;
        } else if (diff_guess < 0) {
            entry_guess->fieldc_guess |= 0x80;
        } else if (diff_guess == 0) {
            entry_guess->fieldc_guess |= 0x40;
        } else if (diff_guess < 3) {
            entry_guess->fieldc_guess |= 0x20;
        } else {
            entry_guess->fieldc_guess |= 0x10;
        }

        if (g_modeRoot_guess != 0) {
            ModeBaseWithList_guess* modeBase_guess = g_modeRoot_guess;
            if (modeBase_guess->GetCharInfo2()->mode_guess == 4 && entry_guess->target_guess->field244_guess == 1) {
                unsigned char bits_guess = g_trackFilterBits_guess.bits_guess;
                if (((bits_guess & 1) != 0 && (entry_guess->fieldc_guess & 0x100) != 0) ||
                    ((bits_guess & 2) != 0 && (entry_guess->fieldc_guess & 0x80) != 0) ||
                    ((bits_guess & 4) != 0 && (entry_guess->fieldc_guess & 0x40) != 0) ||
                    ((bits_guess & 8) != 0 && (entry_guess->fieldc_guess & 0x20) != 0) ||
                    ((bits_guess & 0x10) != 0 && (entry_guess->fieldc_guess & 0x10) != 0) ||
                    ((bits_guess & 0x20) != 0 && (entry_guess->fieldc_guess & 0x200) != 0))
                    hit_guess = true;
            }
        }

        if (entry_guess->target_guess->field244_guess == 0) {
            entry_guess->fieldc_guess |= 2;
            if (g_trackPlayersMode_guess == 0) {
                hit_guess = true;
            } else if (g_trackPlayersMode_guess == 1) {
                hit_guess = false;
            } else if (g_trackPlayersMode_guess == 2) {
                bool found_guess = false;
                if (g_slotsUsed_guess != 0) {
                    for (int slot_guess = 0; slot_guess < 5; ++slot_guess) {
                        if (g_slots_guess[slot_guess].active_guess != 0 && g_slotTargets_guess[slot_guess] != 0 &&
                            g_slotTargets_guess[slot_guess] == entry_guess->target_guess) {
                            found_guess = true;
                            break;
                        }
                    }
                }
                if (!found_guess)
                    hit_guess = true;
            }
        }

        if (entry_guess->target_guess->field25c_guess != 0) {
            Target_guess* other_guess = FUN_00401b28_guess(entry_guess->target_guess->field25c_guess);
            if (other_guess != 0 && other_guess->field244_guess != 1)
                entry_guess->fieldc_guess |= 4;
        }
        if (hit_guess)
            entry_guess->fieldc_guess |= 1;
    }
    if (flag_guess != 0)
        RefreshTrackingList_guess(0);
}

// Removes entry `value_guess`'s row from the list and restores the previous selection.
// FUNCTION: TITANIUM 0x005671CE
void Finder_guess::RemoveFromListWndByData_guess(int value_guess) {
    int selected_value_guess = -1;
    if (list_guess != 0) {
        int selected_index_guess = list_guess->GetCurSel();
        if (selected_index_guess >= 0)
            selected_value_guess = list_guess->GetItemData(selected_index_guess);

        int index_guess = FindListRow_guess(value_guess);
        if (index_guess >= 0)
            list_guess->Remove_guess(index_guess);

        if (selected_value_guess >= 0) {
            index_guess = FindListRow_guess(selected_value_guess);
            if (index_guess >= 0)
                list_guess->SetCurSel(index_guess);
        }
    }
}

// Resets the 500 ms refresh timer (+0x15C) and redraws the controls at once.
// FUNCTION: TITANIUM 0x00567232
void CTrackingWnd_guess::ClearAndNotify_guess() {
    field15c_guess = 0;
    UpdateTrackingControls_guess();
}

// Probably the activate hook: refreshes the controls and asks for a new track list.
// FUNCTION: TITANIUM 0x0056723E
bool CTrackingWnd_guess::Reset_guess() {
    ClearAndNotify_guess();
    RequestTrackList_guess();
    return true;
}

// Redraws the controls every 500 ms while the window is active.
// FUNCTION: TITANIUM 0x00567251
void CTrackingWnd_guess::OnProcessFrame_guess() {
    if (IsPanelActive_guess()) {
        unsigned int* field_guess = (unsigned int*)&field15c_guess;
        unsigned int tick_guess = g_timerState_guess->tick_guess;
        if (tick_guess >= *field_guess) {
            *field_guess = tick_guess + 500;
            UpdateTrackingControls_guess();
        }
    }
    OnProcessFrame();
}


struct Source_guess {
    unsigned short id_guess; // 0x0
    unsigned short pad_guess;
    float value_guess; // 0x4
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
Target_guess* __cdecl FUN_00401b28_guess(int id_guess);

// OP_Track reply: `count_guess` records of (spawn id, distance); spawns not known locally are skipped and
// anything past 1000 is dropped. Then sort, filter and fill the list.
// FUNCTION: TITANIUM 0x0056728A
void CTrackingWnd_guess::HandleTrackReply_guess(Source_guess* source_guess, int count_guess) {
    int index_guess = 0;
    if (count_guess > 0) {
        Entry_guess* entry_guess = entries_guess;
        do {
            if (index_guess >= 1000)
                break;
            Target_guess* target_guess = FUN_00401b28_guess(source_guess[index_guess].id_guess);
            if (target_guess != 0) {
                entry_guess->field4_guess = source_guess[index_guess].value_guess;
                entry_guess->target_guess = target_guess;
                entry_guess->field8_guess = index_guess;
            }
            ++index_guess;
            ++entry_guess;
        } while (index_guess < count_guess);
    }
    SortTrackingList_guess(0);
    ApplyTrackingFilters_guess(0);
    RefreshTrackingList_guess(0);
}

// A despawned spawn: empties its entry and removes its row.
// FUNCTION: TITANIUM 0x005672F6
// @early-stop: unknown, diff ndiff=13
void CTrackingWnd_guess::RemoveSpawn_guess(Target_guess* target_guess) {
    if (IsPanelActive_guess()) {
        for (int index_guess = 0; index_guess < 1000; ++index_guess) {
            if (entries_guess[index_guess].target_guess == target_guess) {
                ((Thing_guess*)this)->ClearEntry_guess(index_guess);
                if (IsPanelActive_guess())
                    ((Finder_guess*)this)->RemoveFromListWndByData_guess(index_guess);
                break;
            }
        }
    }
}
