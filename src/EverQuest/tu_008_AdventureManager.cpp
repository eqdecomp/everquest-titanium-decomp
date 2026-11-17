// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 8: a hint from compare/tumap.py.
// Client side of LDoN adventures. AdventureManager_guess is the adventure state behind the request
// window 0x009913D4; 0x009913F0 is the statistics window and 0x009913B8 the leaderboard window.
// value4_guess is the state: 0 idle, 1 request sent, 2 offer to accept, 3 entry countdown (firstValue_guess,
// seconds), 4 completion countdown (secondValue_guess), 5 error. g_rootState_guess is CDisplay (+0x148 = ms).
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CAdventureLeaderboardWnd.h"
#include "titanium/wnd/CAdventureStatsWnd.h"
#include "titanium/wnd/CPointMerchantWnd.h"
#include "titanium/wnd/CAdventureRequestWnd.h"

#define g_objectVtable_guess EQ_GLOBAL(int, 0x0063FD9C)
#define g_voidConnection_guess EQ_GLOBAL(int, 0x00905CA0)

struct Object_guess {
    void* vtable_guess;
    // EXTERNAL: TITANIUM 0x005482A0 Object_guess::Initialize_guess
    void Initialize_guess(int value);
    void Reset_guess();
};

// Restores the base vtable (0x0063FD9C) and unregisters the object (0x005482A0 with -1).
// FUNCTION: TITANIUM 0x004082BA
void Object_guess::Reset_guess() {
    vtable_guess = &g_objectVtable_guess;
    Initialize_guess(-1);
}

struct Row_guess {
    char reserved[5];
    char value;
    char reserved2[0x3a];
};

struct Table_guess {
    Row_guess rows[5];
    int GetGroupSize_guess();
};

struct RootState_guess {
    char reserved[0x148];
    int value_guess;
    // EXTERNAL: TITANIUM 0x00439D16 RootState_guess::PlayerDistance_guess
    float PlayerDistance_guess(void* source, int value, float threshold);
};

#define g_rootState_guess EQ_GLOBAL(RootState_guess*, 0x00905D24)


struct Message_guess {
    char reserved0[4];
    int mode_guess;
    int value_guess;
};

struct Spell_guess {
    char reserved0[0x120];
    char name_guess[0x138];
    int value258_guess;
};

struct TextStore_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 TextStore_guess::Store_guess
    char* Store_guess(const char* text);
};

#define g_textStore_guess EQ_GLOBAL(TextStore_guess*, 0x00988DF0)

struct TimerUpdate_guess {
    char reserved0[4];
    char text4_guess[0x800];
    int value804_guess;
    int value808_guess;
    int value80c_guess;
    float value810_guess;
    float value814_guess;
    float value818_guess;
    char flag81c_guess;
};

struct AdventureManager_guess {
    char reserved0[4];
    int value4_guess;
    char value8_guess[0x40];
    char value48_guess[0x400];
    char value448_guess;
    char reserved449[3];
    int value44c_guess;
    int firstValue_guess;
    int secondValue_guess;
    int rootStateValue_guess;
    int rootValue_guess;
    int state_guess;
    int value464_guess;
    int value468_guess;
    char value46c_guess;
    char reserved46d[3];
    float value470_guess;
    float value474_guess;
    float value478_guess;
    Spell_guess* value47c_guess;

    void SetMode_guess(int value);
    void ResetMode_guess();
    void UpdateCallbacks_guess();
    void OnCallback_guess();
    void AcceptAdventure_guess();
    void DeclineAdventure_guess();
    void Handle_OP_AdventureInfo_guess(const char* text);
    void Handle_OP_AdventureDetails_guess(const char* text);
    void SetTextMode5_guess(const char* text);
    void SetFirst_guess(int value);
    void SetSecond_guess(int value);
    void RequestAdventureInfo_guess(Spell_guess* spell);
    void OnModeChanged_guess();
    void HandleAdventureTimer_guess(Message_guess* message);
    void RequestAdventure_guess(int first, int second);
    void Handle_OP_AdventureData_guess(TimerUpdate_guess* update);
    void Tick_guess();
    void OnEvent_guess(int sender, unsigned int msg, char* data, int extra);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyString_guess
void __cdecl CopyString_guess(char* destination, const char* source);

// Group size counting the player: filled member rows (of 5) up to the first empty one, plus one.
// FUNCTION: TITANIUM 0x004082C8
int Table_guess::GetGroupSize_guess() {
    int count = 0;
    Row_guess* row = rows;
    do {
        if (row->value == 0) {
            break;
        }
        ++count;
        ++row;
    } while (count < 5);
    return count + 1;
}

// Per-frame update. In states 1-2, every 500 ms, closes the window when the recruiter is gone or the
// player (0x00905CE4) is over 30 units away. In states 3-4 counts the deadline down a second at a time,
// carrying leftover ms in state_guess.
// FUNCTION: TITANIUM 0x004082DF
// @early-stop: budget, diff ndiff=20
void AdventureManager_guess::Tick_guess() {
    if (pinstCAdventureRequestWnd_guess != 0) {
        if (pinstCAdventureRequestWnd_guess->IsVisible_guess() && (value4_guess == 1 || value4_guess == 2)) {
            if ((unsigned)g_rootState_guess->value_guess > (unsigned)rootStateValue_guess + 500) {
                rootStateValue_guess = g_rootState_guess->value_guess;
                if (value47c_guess == 0 ||
                    g_rootState_guess->PlayerDistance_guess(value47c_guess, EQ_GLOBAL(int, 0x00905CE4), 1.0f) > 30.0f) {
                    pinstCAdventureRequestWnd_guess->Deactivate();
                    pinstCAdventureRequestWnd_guess->StoreIniVis();
                }
            }
        }
        int mode = value4_guess;
        if (mode == 3 || mode == 4) {
            int now = g_rootState_guess->value_guess;
            int elapsed = now;
            elapsed -= rootValue_guess;
            rootValue_guess = now;
            state_guess += elapsed;
            if (state_guess >= 1000) {
                if (mode == 3) {
                    firstValue_guess += state_guess / -1000;
                    if (firstValue_guess < 0) {
                        firstValue_guess = 0;
                    }
                    pinstCAdventureRequestWnd_guess->FormatTime_guess(firstValue_guess);
                } else if (mode == 4) {
                    secondValue_guess += state_guess / -1000;
                    if (secondValue_guess < 0) {
                        secondValue_guess = 0;
                    }
                    pinstCAdventureRequestWnd_guess->FormatSecondTime_guess(secondValue_guess);
                }
                state_guess %= 1000;
            }
        }
    }
}

// Sets the state and tells the window. State 0 also forgets the recruiter and dungeon location and resets
// the texts (0x0063F53F is ""; string 0x2151: not assigned to an adventure).
// States 1-2 restart the 500 ms range check.
// FUNCTION: TITANIUM 0x00408410
void AdventureManager_guess::SetMode_guess(int value) {
    value4_guess = value;
    switch (value) {
    case 1:
        rootStateValue_guess = g_rootState_guess->value_guess;
        break;
    case 2:
        rootStateValue_guess = g_rootState_guess->value_guess;
        break;
    case 0:
        value47c_guess = 0;
        CopyString_guess(value8_guess, EQ_ARRAY(char, 0x0063F53F));
        CopyString_guess(value48_guess, pStringTable->getString(0x2151, 0));
        value470_guess = -1.0f;
        value474_guess = -1.0f;
        value478_guess = -1.0f;
        value464_guess = 0;
        value468_guess = 0;
        value44c_guess = 1;
        value46c_guess = 0;
        break;
    }
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->SetMode_guess(value);
    }
}

// Pushes every field the request window shows.
// FUNCTION: TITANIUM 0x004084BA
void AdventureManager_guess::UpdateCallbacks_guess() {
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->SetMode_guess(value4_guess);
        pinstCAdventureRequestWnd_guess->Apply_4d6986_guess(value8_guess);
        pinstCAdventureRequestWnd_guess->ApplyLogged_guess(value48_guess);
        pinstCAdventureRequestWnd_guess->UpdateTimerValues_guess(value464_guess, value468_guess);
        pinstCAdventureRequestWnd_guess->AdventureRequestSetRiskLevel_guess(value44c_guess);
    }
}

// Starts the entry countdown at `value` seconds.
// FUNCTION: TITANIUM 0x00408517
void AdventureManager_guess::SetFirst_guess(int value) {
    state_guess = 0;
    firstValue_guess = value;
    rootValue_guess = g_rootState_guess->value_guess;
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->FormatTime_guess(value);
    }
}

// Starts the completion countdown at `value` seconds.
// FUNCTION: TITANIUM 0x0040854D
void AdventureManager_guess::SetSecond_guess(int value) {
    state_guess = 0;
    secondValue_guess = value;
    rootValue_guess = g_rootState_guess->value_guess;
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->FormatSecondTime_guess(value);
    }
}

// Toggles the request window: closes it if open, else fills and opens it.
// FUNCTION: TITANIUM 0x00408583
void AdventureManager_guess::OnCallback_guess() {
    if (pinstCAdventureRequestWnd_guess != 0) {
        if (pinstCAdventureRequestWnd_guess->IsVisible_guess()) {
            pinstCAdventureRequestWnd_guess->Deactivate();
        } else {
            UpdateCallbacks_guess();
            pinstCAdventureRequestWnd_guess->Activate();
        }
        pinstCAdventureRequestWnd_guess->StoreIniVis();
    }
}

// Accepts the offered adventure: OP_LDoNButton with byte 1.
// FUNCTION: TITANIUM 0x00408616
void AdventureManager_guess::AcceptAdventure_guess() {
    value448_guess = 1;
    EQSendMessage(&g_voidConnection_guess, OP_LDoNButton, &value448_guess, 1, 1);
    SetMode_guess(0);
}

// Declines the offered adventure: OP_LDoNButton with byte 0.
// FUNCTION: TITANIUM 0x00408644
void AdventureManager_guess::DeclineAdventure_guess() {
    value448_guess = 0;
    EQSendMessage(&g_voidConnection_guess, OP_LDoNButton, &value448_guess, 1, 1);
    SetMode_guess(0);
}

// Opens a request from a recruiter NPC (`spell` is a spawn, misnamed): keeps its name and sends its spawn id
// (+0x258) as OP_AdventureInfoRequest. Only from idle or the error state.
// FUNCTION: TITANIUM 0x00408672
void AdventureManager_guess::RequestAdventureInfo_guess(Spell_guess* spawn) {
    if ((value4_guess == 0 || value4_guess == 5) && spawn != 0) {
        SetMode_guess(0);
        value47c_guess = spawn;
        CopyString_guess(value8_guess, g_textStore_guess->Store_guess(spawn->name_guess));
        int value = value47c_guess->value258_guess;
        EQSendMessage(&g_voidConnection_guess, OP_AdventureInfoRequest, &value, 4, 1);
        if (pinstCAdventureRequestWnd_guess != 0) {
            pinstCAdventureRequestWnd_guess->Apply_4d6986_guess(value8_guess);
        }
    }
}

// Recruiter text while the request is pending (state 1).
// FUNCTION: TITANIUM 0x004086F8
void AdventureManager_guess::Handle_OP_AdventureInfo_guess(const char* text) {
    CopyString_guess(value48_guess, text);
    SetMode_guess(1);
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->ApplyLogged_guess(value48_guess);
        pinstCAdventureRequestWnd_guess->Activate();
        pinstCAdventureRequestWnd_guess->StoreIniVis();
    }
}

// OP_AdventureDetails: the offer text, waiting for accept or decline (state 2).
// FUNCTION: TITANIUM 0x00408742
void AdventureManager_guess::Handle_OP_AdventureDetails_guess(const char* text) {
    CopyString_guess(value48_guess, text);
    SetMode_guess(2);
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->ApplyLogged_guess(value48_guess);
        pinstCAdventureRequestWnd_guess->Activate();
        pinstCAdventureRequestWnd_guess->StoreIniVis();
    }
}

// Error text (state 5); also the refusals in Apply_guess.
// FUNCTION: TITANIUM 0x0040878C
void AdventureManager_guess::SetTextMode5_guess(const char* text) {
    CopyString_guess(value48_guess, text);
    SetMode_guess(5);
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->Apply_4d6a4b_guess(value48_guess);
        pinstCAdventureRequestWnd_guess->Activate();
        pinstCAdventureRequestWnd_guess->StoreIniVis();
    }
}

// OP_LeaveAdventure, no payload.
// FUNCTION: TITANIUM 0x004087D6
void __cdecl SendLeaveAdventure_guess() {
    EQSendMessage(&g_voidConnection_guess, OP_LeaveAdventure, 0, 0, 1);
}

// Text, then a running entry (+0x804) or completion (+0x808) timer in seconds; when +0x81c is set, the
// dungeon entrance (x, y, z; -1 when unknown), marked on the compass (string 0xd2a).
// FUNCTION: TITANIUM 0x004087EF
void AdventureManager_guess::Handle_OP_AdventureData_guess(TimerUpdate_guess* update) {
    value44c_guess = update->value80c_guess;
    CopyString_guess(value48_guess, update->text4_guess);
    if (pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->AdventureRequestSetRiskLevel_guess(update->value80c_guess);
        pinstCAdventureRequestWnd_guess->ApplyLogged_guess(value48_guess);
    }
    if (value4_guess == 0 && pinstCAdventureRequestWnd_guess != 0) {
        pinstCAdventureRequestWnd_guess->Activate();
        pinstCAdventureRequestWnd_guess->StoreIniVis();
    }
    if (update->value804_guess != 0) {
        if (pinstCAdventureRequestWnd_guess != 0) {
            pinstCAdventureRequestWnd_guess->ClearSecondCountdown_guess();
        }
        SetFirst_guess(update->value804_guess);
        SetMode_guess(3);
    } else {
        if (update->value808_guess != 0) {
            if (pinstCAdventureRequestWnd_guess != 0) {
                pinstCAdventureRequestWnd_guess->ClearFirstCountdown_guess();
            }
            SetSecond_guess(update->value808_guess);
            SetMode_guess(4);
        }
    }
    if (update->flag81c_guess != 0) {
        value46c_guess = 1;
        value470_guess = update->value810_guess;
        value474_guess = update->value814_guess;
        value478_guess = update->value818_guess;
        pEverQuest->dsp_chat(pStringTable->getString(0xd2a, 0), 0xf, 1);
    } else {
        value46c_guess = 0;
        value470_guess = -1.0f;
        value474_guess = -1.0f;
        value478_guess = -1.0f;
    }
}

struct TimerValues_guess {
    char reserved[4];
    int mode_guess;
    char reserved2[0x45c];
    int firstValue_guess;
    int secondValue_guess;

    void Handle_OP_AdventureUpdate_guess(int* values);
};

// EXTERNAL: TITANIUM 0x0063FDA8 ??_7RenderState_guess@@6B@
struct RenderState_guess {
    virtual void RefreshCounts_guess();
    char reserved0[0x448];
    int value44c_guess;
    int value450_guess;
    int value454_guess;
    char reserved458[0x0c];
    int value464_guess;
    int value468_guess;
    char value46c_guess;
    char reserved46d[3];
    float value470_guess;
    float value474_guess;
    float value478_guess;
    int value47c_guess;

    RenderState_guess();
};

// TimerValues_guess is another view of AdventureManager_guess (mode_guess is value4_guess): the two values
// land in value464_guess/value468_guess, which the window shows only in state 4.
// FUNCTION: TITANIUM 0x00408923
void TimerValues_guess::Handle_OP_AdventureUpdate_guess(int* values) {
    firstValue_guess = values[0];
    secondValue_guess = values[1];
    if (pinstCAdventureRequestWnd_guess != 0 && mode_guess == 4) {
        pinstCAdventureRequestWnd_guess->UpdateTimerValues_guess(firstValue_guess, secondValue_guess);
    }
}

// Timer packet 0x49a5 (no EQEmu name): mode 1 restarts the entry countdown, mode 2 the completion one.
// FUNCTION: TITANIUM 0x00408959
void AdventureManager_guess::HandleAdventureTimer_guess(Message_guess* message) {
    if (message->mode_guess == 1) {
        if (pinstCAdventureRequestWnd_guess != 0) {
            pinstCAdventureRequestWnd_guess->ClearSecondCountdown_guess();
        }
        SetFirst_guess(message->value_guess);
        SetMode_guess(3);
    } else {
        if (message->mode_guess != 2) {
            return;
        }
        if (pinstCAdventureRequestWnd_guess != 0) {
            pinstCAdventureRequestWnd_guess->ClearFirstCountdown_guess();
        }
        SetSecond_guess(message->value_guess);
        SetMode_guess(4);
    }
}




struct Manager_guess {
    // EXTERNAL: TITANIUM 0x0044A537 Manager_guess::WavePlay_guess
    void WavePlay_guess(int id, int zero);
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00851390)

struct InitObject_guess {
    // EXTERNAL: TITANIUM 0x0040812F InitObject_guess::DisplayText
    void DisplayText(const char* name, int kind, int limit, int v14, int v18, int v1C, int v20);
};

// EXTERNAL: TITANIUM 0x00407DC9 GetOrCreateInitObject_guess
InitObject_guess* __cdecl GetOrCreateInitObject_guess();
// EXTERNAL: TITANIUM 0x00467441 FormatText_guess
void __cdecl FormatText_guess(char* out, const char* format, char** args, int width, int precision);

struct CharBlock_guess {
    char reserved0[0x102c];
    int value102c_guess;
    int value1030_guess;
    int value1034_guess;
    int value1038_guess;
    int value103c_guess;
    char reserved1040[8];
    char data1048_guess[0x78];
};

#define g_charBlock_guess EQ_GLOBAL(CharBlock_guess*, 0x00905D00)

// Adventure message handler. OP_AdventureFinish: data[0] win or lose, data[1] points (string 0x2154 is
// the one-point text, 0x1410 the plural); an on-screen banner (0x2152 win, 0x2153 lose) and sound 0x8d or
// 0x8c. OP_AdventurePointsUpdate: five point counters and 0x78 bytes of stats into pCharData (+0x102c).
// 0xff1 is an error string id; 0x16c6 resets to idle. Leaderboard and stats replies go to their windows.
// FUNCTION: TITANIUM 0x004089B2
// @early-stop: budget, structural ndiff=53
void AdventureManager_guess::OnEvent_guess(int sender, unsigned int msg, char* data, int extra) {
    int id;
    char* args[2];
    char buf[512];
    char numBuf[20];

    switch (msg) {
    case OP_AdventureFinish:
        if (*data != 0) {
            _itoa(((int*)data)[1], numBuf, 10);
            args[0] = numBuf;
            char** formatArgs = args;
            int width = -1;
            int precision = 0;
            FormatText_guess(buf, pStringTable->getString(((int*)data)[1] == 1 ? 0x2154 : 0x1410, 0), formatArgs, width, precision);
            pEverQuest->dsp_chat(buf);
            const char* text = pStringTable->getString(0x2152, 0);
            GetOrCreateInitObject_guess()->DisplayText(text, 0xf, 0xa, 0xcc, 0x1f4, 0x1f4, 0x2328);
            g_manager_guess->WavePlay_guess(0x8d, 0);
        } else {
            const char* text = pStringTable->getString(0x2153, 0);
            GetOrCreateInitObject_guess()->DisplayText(text, 0xd, 0xa, 0xcc, 0x1f4, 0x1f4, 0x2328);
            g_manager_guess->WavePlay_guess(0x8c, 0);
        }
        SetMode_guess(0);
        if (pinstCAdventureRequestWnd_guess != 0) {
            pinstCAdventureRequestWnd_guess->Deactivate();
            pinstCAdventureRequestWnd_guess->StoreIniVis();
        }
        break;
    case OP_AdventureData:
        Handle_OP_AdventureData_guess((TimerUpdate_guess*)data);
        break;
    case OP_AdventureLeaderboardReply:
        if (pinstCAdventureLeaderboardWnd_guess != 0) {
            pinstCAdventureLeaderboardWnd_guess->Handle_OP_AdventureLeaderboardReply_guess(sender, msg, data, extra);
        }
        break;
    case 0xff1:
        SetTextMode5_guess(pStringTable->getString(*(int*)data, 0));
        break;
    case 0x16c6:
        SetMode_guess(0);
        break;
    case OP_AdventureInfo:
        Handle_OP_AdventureInfo_guess(data);
        break;
    case OP_AdventureDetails:
        Handle_OP_AdventureDetails_guess(data);
        break;
    case OP_AdventurePointsUpdate:
        g_charBlock_guess->value103c_guess = ((int*)data)[0];
        g_charBlock_guess->value1034_guess = ((int*)data)[3];
        g_charBlock_guess->value1038_guess = ((int*)data)[4];
        g_charBlock_guess->value102c_guess = ((int*)data)[1];
        g_charBlock_guess->value1030_guess = ((int*)data)[2];
        memcpy(g_charBlock_guess->data1048_guess, data + 0x14, 0x78);
        if (pinstCPointMerchantWnd_guess != 0) {
            pinstCPointMerchantWnd_guess->refreshStatus_guess();
        }
        if (pinstCAdventureStatsWnd_guess != 0) {
            pinstCAdventureStatsWnd_guess->Send_guess();
        }
        break;
    case 0x49a5:
        HandleAdventureTimer_guess((Message_guess*)data);
        break;
    case OP_AdventureStatsReply:
        if (pinstCAdventureStatsWnd_guess != 0) {
            pinstCAdventureStatsWnd_guess->Handle_OP_AdventureStatsReply_guess(sender, msg, data, extra);
        }
        break;
    case OP_AdventureUpdate:
        ((TimerValues_guess*)this)->Handle_OP_AdventureUpdate_guess((int*)data);
        break;
    }
}

// Confirmation-dialog callback: dialog 100 (leave the adventure?) answered yes (flags & 5).
// FUNCTION: TITANIUM 0x00408CAC
void __stdcall ConfirmLeaveAdventure_guess(int dialogId_guess, char flags_guess, int unused_guess) {
    if (dialogId_guess == 100 && (flags_guess & 5) != 0) {
        SendLeaveAdventure_guess();
    }
}

// Probably the constructor of the same object: the field layout of AdventureManager_guess, vtable 0x0063FDA8.
// FUNCTION: TITANIUM 0x00408CC2
RenderState_guess::RenderState_guess()
    : value470_guess(-1.0f), value474_guess(-1.0f) {
    value478_guess = -1.0f;
    value450_guess = 0;
    value454_guess = 0;
    value464_guess = 0;
    value468_guess = 0;
    value44c_guess = 1;
    value47c_guess = 0;
    value46c_guess = 0;
}

// Puts the adventure state back to 0 (no adventure; 0x00408410); the client startup calls it.
// FUNCTION: TITANIUM 0x00408D13
void AdventureManager_guess::ResetMode_guess() {
    SetMode_guess(0);
}

struct Panel_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 Panel_guess::IsInRaid_guess
    bool IsInRaid_guess();
    // EXTERNAL: TITANIUM 0x0042FD00 Panel_guess::IsRaidLeader_guess
    bool IsRaidLeader_guess();
};

struct CharRoot_guess {
    char reserved0[8];
    struct VBTable* ref8_guess;
    char reserved10[0x38];
    char name44_guess[1];
};

#include "titanium/layouts/core.h"

#define g_charRoot_guess EQ_GLOBAL(CharRoot_guess*, 0x00905D00)

// The request button. With a countdown running it asks to leave instead (dialog 100, string 0x213F).
// Otherwise a raid leader, or a group leader (name at 0x009043A4) with 2+ in the group, sends
// OP_AdventureRequest {first, recruiter id, second}. Refusals: 0x1405 no group, 0x1407 not the group
// leader, 0x1411 in a raid but not its leader. Check1_guess (0x0042FCC2) is probably "in a raid".
// FUNCTION: TITANIUM 0x00408D1B
void AdventureManager_guess::RequestAdventure_guess(int first, int second) {
    if (value4_guess == 3 || value4_guess == 4) {
        pConfirmationDialogPool_guess->Activate(this, 100, pStringTable->getString(0x213F, 0), 0xc, -1, 0, 1);
        return;
    }
    Panel_guess* panel = EQ_ARRAY(Panel_guess, 0x0091D708);
    if (!panel->IsInRaid_guess() || panel->IsRaidLeader_guess()) {
        if (!panel->IsInRaid_guess() && EQ_ARRAY(Table_guess, 0x00904248)->GetGroupSize_guess() < 2) {
            SetTextMode5_guess(pStringTable->getString(0x1405, 0));
            return;
        }
        if (panel->IsInRaid_guess() ||
            _stricmp(EQ_ARRAY(char, 0x009043A4), g_charRoot_guess->name44_guess + g_charRoot_guess->ref8_guess->vbase_offset) == 0) {
            Spell_guess* spell = value47c_guess;
            value44c_guess = first;
            int msg[3];
            msg[0] = first;
            msg[2] = second;
            if (spell != 0) {
                msg[1] = spell->value258_guess;
            } else {
                msg[1] = 0;
            }
            EQSendMessage(&g_voidConnection_guess, OP_AdventureRequest, msg, 0xc, 1);
            SetMode_guess(0);
            if (pinstCAdventureRequestWnd_guess != 0) {
                pinstCAdventureRequestWnd_guess->AdventureRequestSetRiskLevel_guess(first);
                if (pinstCAdventureRequestWnd_guess != 0) {
                    pinstCAdventureRequestWnd_guess->AdventureRequestSetAdventureTypeChoice_guess(second);
                }
            }
            value47c_guess = spell;
            return;
        }
        SetTextMode5_guess(pStringTable->getString(0x1407, 0));
        return;
    }
    SetTextMode5_guess(pStringTable->getString(0x1411, 0));
}

// Window closed: a pending offer (state 2) is declined; states 1 and 5 just go back to idle.
// FUNCTION: TITANIUM 0x004085CC
void AdventureManager_guess::OnModeChanged_guess() {
    if (value4_guess == 2) {
        value448_guess = 0;
        EQSendMessage(&g_voidConnection_guess, OP_LDoNButton, &value448_guess, 1, 1);
        SetMode_guess(0);
    }
    if (value4_guess == 1 || value4_guess == 5) {
        SetMode_guess(0);
    }
}

