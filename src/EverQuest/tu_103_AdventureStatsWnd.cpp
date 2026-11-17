// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 103: a hint from compare/tumap.py.
// LDoN adventure windows: the adventure request window (CAdventureRequestWnd_guess: "Request
// Adventure"/"Leave Adventure", two groups of controls greyed by mode) and AdventureStatsWnd
// (CAdventureStatsWnd_guess: per-theme wins, losses, rank, from OP_AdventureStatsReply). Theme names are
// strings 8533-8538 ("---", Deepest Guk ... Takish).
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CAdventureLeaderboardWnd.h"
#include "titanium/wnd/CTipWnd.h"


struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::Get_guess
    int Get_guess(int id, int zero);
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::FindText_guess
    const char* FindText_guess(int id, int zero);
};

#define g_textLookup_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    Base_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess() ;
};

struct Child_guess;

// EXTERNAL: TITANIUM 0x0064E878 ??_7CAdventureRequestWnd_guess@@6B@
struct CAdventureRequestWnd_guess : Base_guess {
    char padding_guess[0x58];
    char active_guess;
    char padding1_guess[0xff];
    Child_guess* first_state_guess;
    Child_guess* unused_guess;
    Child_guess* second_state_guess;
    Child_guess* third_state_guess;
    Child_guess* fourth_state_guess;
    Child_guess* first_active_guess;
    char padding2_guess[4];
    Child_guess* fifth_state_guess;
    Child_guess* sixth_state_guess;
    Child_guess* seventh_state_guess;
    Child_guess* eighth_state_guess;
    Child_guess* ninth_state_guess;
    Child_guess* tenth_state_guess;
    Child_guess* second_active_guess;
    Child_guess* third_active_guess;

    ~CAdventureRequestWnd_guess() ;
    void* Delete_guess(unsigned char flags_guess);
    void OnShow_guess();
    void UpdateFirst_guess(unsigned char active_guess, unsigned char state_guess);
    void UpdateSecond_guess(unsigned char active_guess, unsigned char state_guess);
    void ClearStates_guess();
    void SetMode_guess(int mode_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

struct Child_guess {
    char padding_guess[0x5d];
    char active_guess;
    char padding1_guess[0x1e];
    int state_guess;

    // EXTERNAL: TITANIUM 0x0059C3A0 Child_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C360 Child_guess::Action_guess
    void Action_guess(int value);
};

struct Clock_guess {
    char padding_guess[0x148];
    unsigned int tick_guess;
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_request_guess EQ_GLOBAL(int, 0x00905CA0)

// EXTERNAL: TITANIUM 0x00491125 eqlog_guess
void __cdecl eqlog_guess(const char* message_guess);

// EXTERNAL: TITANIUM 0x0064E9C0 ??_7CAdventureStatsWnd_guess@@6B@
struct CAdventureStatsWnd_guess : Base_guess {
    char padding0_guess[0x58];
    char active_guess;
    char padding1_guess[0x66 - 0x5d];
    unsigned char flags_066_guess;
    char padding1b_guess[0x124 - 0x67];
    void* sidlPiece_124_guess;
    char padding1c_guess[0x158 - 0x128];
    int field_158_guess;
    char pending_guess;
    char padding2_guess[3];
    unsigned int tick_guess;
    CListWnd* themeList_guess;
    Child_guess* auxiliary_guess;
    Child_guess* child_guess;
    Child_guess* second_callback_guess;
    Child_guess* third_callback_guess;
    int value_guess[6];
    int previous_value_guess;
    int final_value_guess;

    // EXTERNAL: TITANIUM 0x005A1CD0 CAdventureStatsWnd_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x005A1880 CAdventureStatsWnd_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CAdventureStatsWnd_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CAdventureStatsWnd_guess::Process_guess
    void Process_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CAdventureStatsWnd_guess::Complete_guess
    void Complete_guess(Child_guess* value_guess, int mode_guess, int result_guess);
    CAdventureStatsWnd_guess(CXWnd* parent);
    ~CAdventureStatsWnd_guess() ;
    void* Delete_guess(unsigned char flags_guess);
    void OnShow_guess();
    void CallbackB_guess();
    void AdventureRequestSetRiskLevel_guess(int value);
    void AdventureRequestSetAdventureTypeChoice_guess(int value);
    int Value_guess(int index);
    void Initialize_guess();
    void Send_guess();
    void AdventureRequestWndNotification_guess(int value_guess, int mode_guess, int result_guess);
    void CallbackE_guess();
    void CallbackF_guess(Child_guess* value_guess, int mode_guess, int result_guess);
    void Handle_OP_AdventureStatsReply_guess(int unused_guess, int code_guess, struct AdvStats_guess* stats_guess, int unused2_guess);    virtual void Slot02_guess();
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
    virtual void OnDone_guess();
    virtual void Slot34_guess();
};

struct EventHub_guess {
    // EXTERNAL: TITANIUM 0x00408D1B EventHub_guess::RequestAdventure_guess
    void RequestAdventure_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x00408616 EventHub_guess::AcceptAdventure_guess
    void AcceptAdventure_guess();
    // EXTERNAL: TITANIUM 0x00408644 EventHub_guess::DeclineAdventure_guess
    void DeclineAdventure_guess();
};

#define g_eventHub_guess EQ_GLOBAL(EventHub_guess, 0x009232F0)
#define pinstCAdventureStatsWnd_guess EQ_GLOBAL(CAdventureStatsWnd_guess*, 0x009913F0)

struct Str_guess {
    char* data_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* value_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::Release_guess
    void Release_guess(char* value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            Release_guess(data_guess);
        }
        data_guess = 0;
    }
};

struct StringTarget_guess {
    // EXTERNAL: TITANIUM 0x005A8BF0 StringTarget_guess::Apply_guess
    void Apply_guess(Str_guess* value_guess);
};

struct StringRelay_guess {
    char padding_guess[0x160];
    StringTarget_guess* target_guess;

    void Apply_guess(const char* value_guess);
    void ApplyLogged_guess(const char* value_guess);
};

#define g_traceEnabled_guess EQ_GLOBAL(int, 0x00924788)

struct CallInterface_guess {
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
    virtual void Slot63_guess(Str_guess* value_guess);
};

struct CallInterfaceText_guess {
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
    virtual void Slot63_guess(const Str_guess& value_guess);
};

#define g_defaultString_guess EQ_ARRAY(char, 0x0063F53F)

struct StringSinkOwner_guess {
    char padding_guess[0x17c];
    CallInterface_guess* first_interface_guess;
    CallInterface_guess* unused_interface_guess;
    CallInterface_guess* second_interface_guess;
    char padding2_guess[4];
    CallInterface_guess* timer_interface_guess;

    void ClearFirstCountdown_guess();
    void ClearSecondCountdown_guess();
    void FormatTime_guess(int time_guess);
    void FormatSecondTime_guess(int time_guess);
    void UpdateTimerValues_guess(int first_guess, int second_guess);
};

struct StringCallbackOwner_guess {
    char padding_guess[0x15c];
    CallInterface_guess* interface_guess;
    void Apply_guess(const char* value_guess);
};


// Destructor of the adventure request window: restores its vtable (0x64E878) and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x004D6886
CAdventureRequestWnd_guess::~CAdventureRequestWnd_guess()  {
}

// The adventure request window's WndNotification (slot 32 of vtable 0x64E878, ctor 0x004D642B
// "AdventureRequestWnd"; not the leaderboard). The request button sends the two combobox picks (the first +
// 1) to the adventure manager's request (0x00408D1B); two buttons accept and decline an offer
// (OP_LDoNButton 1 / 0, 0x00408616 / 0x00408644), decline also closing the window; another opens the
// adventure stats window (0x9913F0) and asks for stats. Close (message 10) closes and resets.
// FUNCTION: TITANIUM 0x004D68C2
void CAdventureStatsWnd_guess::AdventureRequestWndNotification_guess(int callback_guess, int mode_guess, int result_guess) {
    if (mode_guess == 1) {
        if (callback_guess == (int)second_callback_guess) {
            int first_guess = 1;
            int second_guess = 0;
            if (auxiliary_guess != 0) {
                first_guess = auxiliary_guess->GetCurChoice_guess() + 1;
            }
            if (child_guess != 0) {
                second_guess = child_guess->GetCurChoice_guess();
            }
            g_eventHub_guess.RequestAdventure_guess(first_guess, second_guess);
        } else if (callback_guess == (int)third_callback_guess) {
            if (pinstCAdventureStatsWnd_guess != 0) {
                pinstCAdventureStatsWnd_guess->CallbackE_guess();
            }
        } else if (callback_guess == previous_value_guess) {
            g_eventHub_guess.AcceptAdventure_guess();
        } else if (callback_guess == final_value_guess) {
            g_eventHub_guess.DeclineAdventure_guess();
            Slot34_guess();
            Reset_guess();
        }
    } else if (mode_guess == 10) {
        Slot34_guess();
        Reset_guess();
    }
    Complete_guess((Child_guess*)callback_guess, mode_guess, result_guess);
}

// Adventure request window: puts `text` in the label at +0x15C (slot 63, SetWindowText); the adventure
// manager shows the recruiter's name there (0x00408672).
// FUNCTION: TITANIUM 0x004D6986
void StringCallbackOwner_guess::Apply_guess(const char* value_guess) {
    if (interface_guess != 0) {
        Str_guess string_guess(value_guess);
        interface_guess->Slot63_guess(&string_guess);
    }
}

// Also logs the text when tracing (0x924788) is on.
// FUNCTION: TITANIUM 0x004D69DD
void StringRelay_guess::ApplyLogged_guess(const char* value_guess) {
    if (target_guess != 0) {
        Str_guess string_guess(value_guess);
        target_guess->Apply_guess(&string_guess);
    }
    if (g_traceEnabled_guess != 0) {
        eqlog_guess(value_guess);
    }
}

// Adventure request window: sets the text box at +0x160 to `text` (0x005A8BF0). Same as 0x004D69DD
// without the log line; used for mode 5 (0x0040878C).
// FUNCTION: TITANIUM 0x004D6A4B
void StringRelay_guess::Apply_guess(const char* value_guess) {
    if (target_guess != 0) {
        Str_guess string_guess(value_guess);
        target_guess->Apply_guess(&string_guess);
    }
}

// Greys (0xFF808080) or restores (-1) the request controls, and enables or disables their buttons.
// FUNCTION: TITANIUM 0x004D6DF1
void CAdventureRequestWnd_guess::UpdateFirst_guess(unsigned char active_guess, unsigned char state_guess) {
    int value_guess = state_guess != 0 ? 0xff808080 : -1;
    if (first_state_guess != 0) {
        first_state_guess->state_guess = value_guess;
    }
    if (first_active_guess != 0) {
        first_active_guess->active_guess = active_guess;
    }
    if (second_state_guess != 0) {
        second_state_guess->state_guess = value_guess;
    }
    if (third_state_guess != 0) {
        third_state_guess->active_guess = active_guess;
    }
    if (fourth_state_guess != 0) {
        fourth_state_guess->active_guess = active_guess;
    }
}

// The same for the second group (the current-adventure controls).
// FUNCTION: TITANIUM 0x004D6E4B
void CAdventureRequestWnd_guess::UpdateSecond_guess(unsigned char active_guess, unsigned char state_guess) {
    int value_guess = state_guess != 0 ? 0xff808080 : -1;
    if (fifth_state_guess != 0) {
        fifth_state_guess->state_guess = value_guess;
    }
    if (sixth_state_guess != 0) {
        sixth_state_guess->state_guess = value_guess;
    }
    if (seventh_state_guess != 0) {
        seventh_state_guess->state_guess = value_guess;
    }
    if (eighth_state_guess != 0) {
        eighth_state_guess->state_guess = value_guess;
    }
    if (ninth_state_guess != 0) {
        ninth_state_guess->state_guess = value_guess;
    }
    if (tenth_state_guess != 0) {
        tenth_state_guess->state_guess = value_guess;
    }
    if (second_active_guess != 0) {
        second_active_guess->active_guess = active_guess;
    }
    if (third_active_guess != 0) {
        third_active_guess->active_guess = active_guess;
    }
}

// Scalar deleting destructor of the adventure request window (vtable 0x64E878 slot 1): destroys it
// and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004D6EC8
void* CAdventureRequestWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->CAdventureRequestWnd_guess::~CAdventureRequestWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Mode 0: blanks the fields, shows string 8529 "You are not currently assigned to an adventure." and greys
// both
// groups.
// FUNCTION: TITANIUM 0x004D6EE4
void CAdventureRequestWnd_guess::ClearStates_guess() {
    if (first_state_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        ((CallInterface_guess*)first_state_guess)->Slot63_guess(&string_guess);
    }
    if (unused_guess != 0) {
        Str_guess string_guess((const char*)g_textLookup_guess->Get_guess(0x2151, 0));
        ((CallInterface_guess*)unused_guess)->Slot63_guess(&string_guess);
    }
    if (third_state_guess != 0) {
        third_state_guess->Action_guess(0);
    }
    if (fourth_state_guess != 0) {
        fourth_state_guess->Action_guess(0);
    }
    if (sixth_state_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        ((CallInterface_guess*)sixth_state_guess)->Slot63_guess(&string_guess);
    }
    if (eighth_state_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        ((CallInterface_guess*)eighth_state_guess)->Slot63_guess(&string_guess);
    }
    if (tenth_state_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        ((CallInterface_guess*)tenth_state_guess)->Slot63_guess(&string_guess);
    }
    UpdateFirst_guess(0, 1);
    UpdateSecond_guess(0, 1);
}

// OnShow (vtable slot 35): when the window is shown (+0x5C), shows context tip 0x27 in the tip window
// (0x9928E0); then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x004D689E
void CAdventureRequestWnd_guess::OnShow_guess() {
    if (active_guess != 0 && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x27, 0);
    }
    ((CSidlScreenWnd*)this)->OnShow();
}

// Adventure request window: selects choice `value - 1` in the first request combobox (+0x168;
// 0x0059C360). The adventure manager pushes its stored first pick (+0x44C, 1-based) here when it
// refreshes the window and after a request.
// FUNCTION: TITANIUM 0x004D6AA3
void CAdventureStatsWnd_guess::AdventureRequestSetRiskLevel_guess(int value) {
    if (auxiliary_guess != 0) {
        auxiliary_guess->Action_guess(value - 1);
    }
}

// Adventure request window: selects choice `value` in the second request combobox (+0x16C; 0x0059C360).
// The adventure manager calls it with the second pick after sending a request (0x00408D1B).
// FUNCTION: TITANIUM 0x004D6ABB
void CAdventureStatsWnd_guess::AdventureRequestSetAdventureTypeChoice_guess(int value) {
    if (child_guess != 0) {
        return child_guess->Action_guess(value);
    }
}

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* dest_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x00467441 ReplaceTokens_guess
void __cdecl ReplaceTokens_guess(char* dest_guess, const char* text_guess,
    const char** params_guess, int length_guess, int flags_guess);

// "%1 of %2" (string 8520), or blank when the total is 0.
// FUNCTION: TITANIUM 0x004D6ACD
void StringSinkOwner_guess::UpdateTimerValues_guess(int first_guess, int second_guess) {
    if (timer_interface_guess == 0) {
        return;
    }
    if (second_guess == 0) {
        Str_guess text_guess(g_defaultString_guess);
        timer_interface_guess->Slot63_guess(&text_guess);
    } else {
        char firstValue_guess[12];
        char secondValue_guess[12];
        _sprintf(firstValue_guess, "%d", first_guess);
        _sprintf(secondValue_guess, "%d", second_guess);
        const char* values_guess[2];
        values_guess[0] = firstValue_guess;
        values_guess[1] = secondValue_guess;
        char text_guess[0x34];
        ReplaceTokens_guess(text_guess, g_textLookup_guess->FindText_guess(0x2148, 0),
            values_guess, -1, 0);
        Str_guess result_guess(text_guess);
        timer_interface_guess->Slot63_guess(&result_guess);
    }
}

// Adventure request window: empties the countdown label at +0x17C (the minutes text 0x004D6C89 writes).
// The adventure manager calls it when the other countdown (+0x184, mode 4) starts.
// FUNCTION: TITANIUM 0x004D6BD9
void StringSinkOwner_guess::ClearFirstCountdown_guess() {
    if (first_interface_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        first_interface_guess->Slot63_guess(&string_guess);
    }
}

// Adventure request window: empties the countdown label at +0x184 (written by 0x004D6D3D). The
// adventure manager calls it when the +0x17C countdown (mode 3) starts.
// FUNCTION: TITANIUM 0x004D6C31
void StringSinkOwner_guess::ClearSecondCountdown_guess() {
    if (second_interface_guess != 0) {
        Str_guess string_guess(g_defaultString_guess);
        second_interface_guess->Slot63_guess(&string_guess);
    }
}

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
char* __cdecl FUN_0046da4a_guess(char* output_guess, int string_guess,
    const char* value_guess, const char* zero1_guess, const char* zero2_guess,
    const char* zero3_guess, const char* zero4_guess, const char* zero5_guess,
    const char* zero6_guess, const char* zero7_guess, const char* zero8_guess);

// Remaining time as "%1 minute(s)" (12973/12974), rounding up to whole minutes.
// FUNCTION: TITANIUM 0x004D6C89
void StringSinkOwner_guess::FormatTime_guess(int time_guess) {
    if (first_interface_guess != 0) {
        int minutes_guess = (time_guess - 1) / 60 + 1;
        char buffer_guess[0x28];
        _sprintf(buffer_guess + 0x20, "%d", minutes_guess);
        FUN_0046da4a_guess(buffer_guess, (minutes_guess != 1) + 0x32ad,
            buffer_guess + 0x20, 0, 0, 0, 0, 0, 0, 0, 0);
        Str_guess string_guess(buffer_guess);
        first_interface_guess->Slot63_guess(&string_guess);
    }
}

// The same for the second time field.
// FUNCTION: TITANIUM 0x004D6D3D
void StringSinkOwner_guess::FormatSecondTime_guess(int time_guess) {
    if (second_interface_guess != 0) {
        int minutes_guess = (time_guess - 1) / 60 + 1;
        char buffer_guess[0x28];
        _sprintf(buffer_guess + 0x20, "%d", minutes_guess);
        FUN_0046da4a_guess(buffer_guess, (minutes_guess != 1) + 0x32ad,
            buffer_guess + 0x20, 0, 0, 0, 0, 0, 0, 0, 0);
        Str_guess string_guess(buffer_guess);
        second_interface_guess->Slot63_guess(&string_guess);
    }
}

// Destructor of the adventure stats window: restores its vtable (0x64E9C0) and runs the CSidlScreenWnd
// destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x004D7229
CAdventureStatsWnd_guess::~CAdventureStatsWnd_guess()  {
}

struct FlagIndex_guess {
    char padding_guess[4];
    unsigned int vbaseOffset_0004_guess;
};

struct FlagObject_guess {
    char padding0_guess[0xc284];
    FlagIndex_guess* index_guess;
    char padding1_guess[0x104];
    unsigned char flags_guess[0x100];
};

#define g_flagObject_guess EQ_GLOBAL(FlagObject_guess*, 0x00905D00)

// Bit 5 of the character's flag byte at the index in +0xC284 (meaning unknown).
// FUNCTION: TITANIUM 0x004D7234
char FUN_004d7234_guess() {
    FlagObject_guess* object_guess = g_flagObject_guess;
    unsigned char (&flags_guess)[0x100] = object_guess->flags_guess;
    char result_guess = flags_guess[object_guess->index_guess->vbaseOffset_0004_guess] >> 5;
    result_guess &= 1;
    return result_guess;
}

// OnShow (vtable slot 35): when shown, resets the window and shows context tip 0x24 in the tip window
// (0x9928E0); then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x004D724F
void CAdventureStatsWnd_guess::OnShow_guess() {
    if (active_guess != 0) {
        Reset_guess();
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x24, 0);
        }
    }
    Finish_guess();
}

// Re-enables OnProcessFrame_guess once the 10-second cool-down set by Send_guess has passed.
// FUNCTION: TITANIUM 0x004D7278
void CAdventureStatsWnd_guess::CallbackB_guess() {
    if (Check_guess() != 0 && pending_guess != 0 && g_clock_guess->tick_guess >= tick_guess && child_guess != 0) {
        pending_guess = 0;
        child_guess->active_guess = 1;
    }
    Process_guess();
}

struct Counter_guess {
    char padding_guess[0x103c];
    int value_guess;
};

#define g_counter_guess EQ_GLOBAL(Counter_guess*, 0x00905D00)

struct StatusSink_guess {
    char padding_guess[0x168];
    CallInterface_guess* interface_guess;

    void Report_guess();
};

// Shows the available adventure points (character +0x103C).
// FUNCTION: TITANIUM 0x004D72BD
void StatusSink_guess::Report_guess() {
    if (interface_guess != 0) {
        char buffer_guess[12];
        _sprintf(buffer_guess, "%d", g_counter_guess->value_guess);
        Str_guess string_guess(buffer_guess);
        interface_guess->Slot63_guess(&string_guess);
    }
}

// Caches theme names 0-5 (strings 8533-8538).
// FUNCTION: TITANIUM 0x004D7346
void CAdventureStatsWnd_guess::Initialize_guess() {
    value_guess[0] = g_textLookup_guess->Get_guess(0x2155, 0);
    value_guess[1] = g_textLookup_guess->Get_guess(0x2156, 0);
    value_guess[2] = g_textLookup_guess->Get_guess(0x2157, 0);
    value_guess[3] = g_textLookup_guess->Get_guess(0x2158, 0);
    value_guess[4] = g_textLookup_guess->Get_guess(0x2159, 0);
    value_guess[5] = g_textLookup_guess->Get_guess(0x215a, 0);
}

// Theme name `index`; out-of-range indexes give theme 0 ("---").
// FUNCTION: TITANIUM 0x004D73D9
int CAdventureStatsWnd_guess::Value_guess(int index) {
    if (index < 0 || index > 5) {
        index = 0;
    }
    return value_guess[index];
}

// Sends OP_AdventureStatsRequest (1 byte) and disables OnProcessFrame_guess for 10 s.
// FUNCTION: TITANIUM 0x004D73F2
void CAdventureStatsWnd_guess::Send_guess() {
    char value_guess;
    EQSendMessage(&g_request_guess, OP_AdventureStatsRequest, &value_guess, 1, 1);
    if (child_guess != 0) {
        child_guess->active_guess = 0;
        pending_guess = 1;
        tick_guess = g_clock_guess->tick_guess + 10000;
    }
}

struct AdvStats_guess {
    int success_guess[6];
    int failure_guess[6];
    int best_guess[6];
    int rank_guess[6];
};

struct ThemeWeight_guess {
    int weight_guess;
    char padding_guess[0x10];
};

struct AdvChar_guess {
    char padding_guess[0x106c];
    ThemeWeight_guess themes_guess[5];
};

#define g_advChar_guess EQ_GLOBAL(AdvChar_guess*, 0x00905D00)

struct ListVirtuals_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess();
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual void DeleteAll_guess();
    // EXTERNAL: TITANIUM 0x0059B360 ListVirtuals_guess::SetItemText
    void SetItemText(int index, int column, const CXStr& text);
};

// Fills the theme list: rows 0-4 are the five themes (stats index 1-5), then a blank row and "Totals"
// (string 8539, stats index 0). Columns: best, wins, losses, win percent, rank, and the character's theme
// weight (+0x106C, 20-byte records); 0 best or rank shows "---".
// FUNCTION: TITANIUM 0x004D743F
// @early-stop: budget, structural ndiff=343
void CAdventureStatsWnd_guess::Handle_OP_AdventureStatsReply_guess(int unused_guess, int code_guess, AdvStats_guess* stats_guess, int unused2_guess) {
    // Only OP_AdventureStatsReply (0x56CD) is handled.
    if (code_guess == 0x56cd) {
        if (themeList_guess != 0) {
            int weightSum_guess = 0;
            themeList_guess->ClearAllSel();
            ((ListVirtuals_guess*)themeList_guess)->DeleteAll_guess();
            char success_guess[6][10];
            char best_guess[6][10];
            char failure_guess[6][10];
            char percent_guess[6][10];
            char rank_guess[6][10];
            char weight_guess[6][10];
            for (int i = 0; i < 5; i++) {
                // Per theme: the win percent over all runs (0 with none); the theme weights add up for the
                // totals row.
                int successes_guess = stats_guess->success_guess[i + 1];
                int failures_guess = stats_guess->failure_guess[i + 1];
                int total_guess = failures_guess + successes_guess;
                float pct_guess;
                if (total_guess == 0) {
                    pct_guess = 0.0f;
                } else {
                    pct_guess = successes_guess * 100.0 / total_guess;
                }
                int weight_guess_value = g_advChar_guess->themes_guess[i].weight_guess;
                weightSum_guess += weight_guess_value;
                _sprintf(success_guess[i], "%d", successes_guess);
                if (stats_guess->best_guess[i + 1] == 0) {
                    _sprintf(best_guess[i], "---");
                } else {
                    _sprintf(best_guess[i], "%d", stats_guess->best_guess[i + 1]);
                }
                _sprintf(failure_guess[i], "%d", failures_guess);
                _sprintf(percent_guess[i], "%3.1f%%", pct_guess);
                if (stats_guess->rank_guess[i + 1] == 0) {
                    _sprintf(rank_guess[i], "---");
                } else {
                    _sprintf(rank_guess[i], "%d", stats_guess->rank_guess[i + 1]);
                }
                _sprintf(weight_guess[i], "%d", weight_guess_value);
                {
                    CXStr text_guess((const char*)Value_guess(i + 1));
                    themeList_guess->AddString(text_guess, 0xffffffff, 0, 0);
                }
                {
                    CXStr text_guess(best_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 1, text_guess);
                }
                {
                    CXStr text_guess(success_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 2, text_guess);
                }
                {
                    CXStr text_guess(failure_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 3, text_guess);
                }
                {
                    CXStr text_guess(percent_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 4, text_guess);
                }
                {
                    CXStr text_guess(rank_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 5, text_guess);
                }
                {
                    CXStr text_guess(weight_guess[i]);
                    ((ListVirtuals_guess*)themeList_guess)->SetItemText(i, 6, text_guess);
                }
            }
            int successes_guess = stats_guess->success_guess[0];
            int failures_guess = stats_guess->failure_guess[0];
            int total_guess = failures_guess + successes_guess;
            float pct_guess;
            if (total_guess == 0) {
                pct_guess = 0.0f;
            } else {
                pct_guess = successes_guess * 100.0 / total_guess;
            }
            char totalSuccess_guess[12];
            char totalPercent_guess[12];
            char totalWeight_guess[12];
            char totalFailure_guess[12];
            char totalBest_guess[12];
            char totalRank_guess[12];
            _sprintf(totalSuccess_guess, "%d", successes_guess);
            if (stats_guess->best_guess[0] == 0) {
                _sprintf(totalBest_guess, "---");
            } else {
                _sprintf(totalBest_guess, "%d", stats_guess->best_guess[0]);
            }
            _sprintf(totalFailure_guess, "%d", failures_guess);
            _sprintf(totalPercent_guess, "%3.1f%%", pct_guess);
            if (stats_guess->rank_guess[0] == 0) {
                _sprintf(totalRank_guess, "---");
            } else {
                _sprintf(totalRank_guess, "%d", stats_guess->rank_guess[0]);
            }
            _sprintf(totalWeight_guess, "%d", weightSum_guess);
            {
                CXStr text_guess(g_defaultString_guess);
                themeList_guess->AddString(text_guess, 0xffffffff, 0, 0);
            }
            {
                // Row 6 is the totals row (string 8539), filled column by column below.
                CXStr text_guess(pStringTable->getString(0x215b, 0));
                themeList_guess->AddString(text_guess, 0xffffffff, 0, 0);
            }
            {
                CXStr text_guess(totalBest_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 1, text_guess);
            }
            {
                CXStr text_guess(totalSuccess_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 2, text_guess);
            }
            {
                CXStr text_guess(totalFailure_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 3, text_guess);
            }
            {
                CXStr text_guess(totalPercent_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 4, text_guess);
            }
            {
                CXStr text_guess(totalRank_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 5, text_guess);
            }
            {
                CXStr text_guess(totalWeight_guess);
                ((ListVirtuals_guess*)themeList_guess)->SetItemText(6, 6, text_guess);
            }
        }
        ((StatusSink_guess*)this)->Report_guess();
    }
}

#include "titanium/layouts/ui.h"

// White text on black, highlight 0xFF8AA3FF; column 0 left, 4 centred (probably), others right.
// FUNCTION: TITANIUM 0x004D7BB4
CAdventureStatsWnd_guess::CAdventureStatsWnd_guess(CXWnd* parent)
    : Base_guess(parent, "AdventureStatsWnd", 0xfffffdff, 1, 0) {
    themeList_guess = 0;
    auxiliary_guess = 0;
    child_guess = 0;
    second_callback_guess = 0;
    third_callback_guess = 0;
    if (sidlPiece_124_guess != 0) {
        flags_066_guess |= 1;
        field_158_guess = 0x24;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        themeList_guess = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("AdvStats_ThemeList");
        auxiliary_guess = (Child_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvStats_AvailableValue");
        child_guess = (Child_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvStats_RefreshButton");
        second_callback_guess = (Child_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvStats_LeaderboardButton");
        third_callback_guess = (Child_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvStats_DoneButton");
        pending_guess = 0;
        if (themeList_guess != 0) {
            themeList_guess->SetColors(0xffffffff, 0xffffffff, 0xff000000);
            ((ListFields_guess*)themeList_guess)->textColor_guess = 0xff8aa3ff;
            ((ListFields_guess*)themeList_guess)->flag_guess = 0;
            themeList_guess->SetColumnJustification(0, 0);
            themeList_guess->SetColumnJustification(1, 1);
            themeList_guess->SetColumnJustification(2, 1);
            themeList_guess->SetColumnJustification(3, 1);
            themeList_guess->SetColumnJustification(4, 2);
            themeList_guess->SetColumnJustification(5, 1);
            themeList_guess->SetColumnJustification(6, 1);
        }
        Initialize_guess();
    }
}

// Scalar deleting destructor of the adventure stats window (vtable 0x64E9C0 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004D7E15
void* CAdventureStatsWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->CAdventureStatsWnd_guess::~CAdventureStatsWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Opening the window requests fresh stats when not already active.
// FUNCTION: TITANIUM 0x004D7E31
void CAdventureStatsWnd_guess::CallbackE_guess() {
    if (Check_guess() == 0) {
        OnDone_guess();
        Send_guess();
    }
}

// OnProcessFrame_guess requests stats; Leaderboard opens the leaderboard window; Done and close (message 10)
// hide.
// FUNCTION: TITANIUM 0x004D7E51
void CAdventureStatsWnd_guess::CallbackF_guess(Child_guess* value_guess, int mode_guess, int result_guess) {
    if (mode_guess == 1) {
        if (value_guess == child_guess) {
            Send_guess();
        } else if (value_guess == second_callback_guess) {
            if (pinstCAdventureLeaderboardWnd_guess != 0) {
                pinstCAdventureLeaderboardWnd_guess->Activate_guess();
            }
        } else if (value_guess == third_callback_guess) {
            Slot34_guess();
            Reset_guess();
        }
    } else if (mode_guess == 10) {
        Slot34_guess();
        Reset_guess();
    }
    Complete_guess(value_guess, mode_guess, result_guess);
}

// Mode 0 no adventure, 1 may request, 2 assigned, 3-4 inside (button becomes "Leave Adventure", string
// 8509), 5 all greyed. The button reads "Request Adventure" (string 8500) otherwise.
// FUNCTION: TITANIUM 0x004D7084
void CAdventureRequestWnd_guess::SetMode_guess(int mode_guess) {
    if (first_active_guess != 0) {
        ((CallInterfaceText_guess*)first_active_guess)->Slot63_guess(
            (const char*)g_textLookup_guess->Get_guess(0x2134, 0));
    }
    switch (mode_guess) {
    case 0:
        ClearStates_guess();
        break;
    case 1:
        UpdateFirst_guess(1, 0);
        UpdateSecond_guess(0, 1);
        break;
    case 2:
        UpdateFirst_guess(0, 1);
        UpdateSecond_guess(1, 0);
        break;
    case 3:
        UpdateFirst_guess(0, 1);
        UpdateSecond_guess(0, 0);
        if (first_active_guess != 0) {
            ((CallInterfaceText_guess*)first_active_guess)->Slot63_guess(
                (const char*)g_textLookup_guess->Get_guess(0x213d, 0));
            first_active_guess->active_guess = 1;
        }
        break;
    case 4:
        UpdateFirst_guess(0, 1);
        UpdateSecond_guess(0, 0);
        if (first_active_guess != 0) {
            ((CallInterfaceText_guess*)first_active_guess)->Slot63_guess(
                (const char*)g_textLookup_guess->Get_guess(0x213d, 0));
            first_active_guess->active_guess = 1;
        }
        break;
    case 5:
        UpdateFirst_guess(0, 1);
        UpdateSecond_guess(0, 1);
        break;
    }
}

