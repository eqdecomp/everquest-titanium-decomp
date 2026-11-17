// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 101: a hint from compare/tumap.py.
// CAdventureLeaderboardWnd (screen "AdventureLeaderboardWnd", AdvLeaderboard_* controls, vtable 0x64E5B0):
// the LDoN leaderboard. CAdventureLeaderboardWnd_guess is that window; CComboWnd_guess is CComboWnd for the two combo boxes (and
// only a view of the two buttons); g_GlobalThing_guess (0x9928E0) is the context-tip window CTipWnd.
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    Base_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess() ;
};

struct CComboWnd_guess {
    char pad[0x5d];
    unsigned char active;

    // EXTERNAL: TITANIUM 0x0059C3A0 CComboWnd_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C360 CComboWnd_guess::SetCurSel_guess
    void SetCurSel_guess(int index);
    // EXTERNAL: TITANIUM 0x0059C330 CComboWnd_guess::SetColors_guess
    void SetColors_guess(int a, int b, int c);
};

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CTipWnd.h"

struct Timer_guess {
    char pad[0x148];
    unsigned int ticks;
};

#define g_Timer_guess EQ_GLOBAL(Timer_guess*, 0x00905D24)
#define g_Message_guess EQ_ARRAY(char, 0x00905CA0)

struct Payload_guess;

// EXTERNAL: TITANIUM 0x0064E5B0 ??_7CAdventureLeaderboardWnd_guess@@6B@
struct CAdventureLeaderboardWnd_guess : Base_guess {
    char pad[0x58];
    unsigned char active;
    char pad1[0x9];
    unsigned char flags_066;
    char pad1b[0xbd];
    void* sidlPiece_124;
    char pad1c[0x30];
    int field_158;
    unsigned char requestPending_015c_guess;
    char pad2[3];
    unsigned int cooldownEnd_0160_guess;
    CComboWnd_guess* selectCombo_0164_guess;
    CComboWnd_guess* riskCombo_0168_guess;
    CListWnd* leaderList_016c;
    CXWnd* yourRankLabel_170;
    CXWnd* yourNameLabel_174;
    CXWnd* yourSuccessLabel_178;
    CXWnd* yourFailureLabel_17c;
    CXWnd* yourPercentLabel_180;
    CComboWnd_guess* refreshButton_0184_guess;
    CComboWnd_guess* doneButton_0188_guess;

    CAdventureLeaderboardWnd_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x005A1CD0 CAdventureLeaderboardWnd_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CAdventureLeaderboardWnd_guess::CanRefresh_guess
    char CanRefresh_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CAdventureLeaderboardWnd_guess::OnProcessFrame
    void OnProcessFrame();
    void OnProcessFrame_guess();
    void SendLeaderboardRequest_guess();
    // EXTERNAL: TITANIUM 0x005A1880 CAdventureLeaderboardWnd_guess::OnShow
    void OnShow();
    virtual ~CAdventureLeaderboardWnd_guess() ;
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
    void WndNotification_guess(CComboWnd_guess* event, int type, int data);
    // EXTERNAL: TITANIUM 0x005A2230 CAdventureLeaderboardWnd_guess::WndNotification
    void WndNotification(CComboWnd_guess* event, int type, int data);
    void OnShow_guess();
    void Activate_guess();
    CAdventureLeaderboardWnd_guess* Delete_guess(unsigned char flags);
    void Handle_OP_AdventureLeaderboardReply_guess(int unused_guess, int msg, Payload_guess* data, int unused2_guess);
    bool AboutToHide_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);


// CAdventureLeaderboardWnd::CAdventureLeaderboardWnd: finds the controls; leader list columns are rank,
// name, wins, losses, percent.
// FUNCTION: TITANIUM 0x004D5770
CAdventureLeaderboardWnd_guess::CAdventureLeaderboardWnd_guess(CXWnd* parent)
    : Base_guess(parent, "AdventureLeaderboardWnd", 0xfffffdff, 1, 0) {
    selectCombo_0164_guess = 0;
    riskCombo_0168_guess = 0;
    leaderList_016c = 0;
    yourRankLabel_170 = 0;
    yourNameLabel_174 = 0;
    yourSuccessLabel_178 = 0;
    yourFailureLabel_17c = 0;
    yourPercentLabel_180 = 0;
    refreshButton_0184_guess = 0;
    doneButton_0188_guess = 0;
    if (sidlPiece_124 != 0) {
        flags_066 |= 1;
        // Window id 0x26, the context-tip id.
        field_158 = 0x26;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        selectCombo_0164_guess = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_SelectCombobox");
        riskCombo_0168_guess = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_RiskCombobox");
        leaderList_016c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_LeaderList");
        yourRankLabel_170 = ((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_YourRankLabel");
        yourNameLabel_174 = ((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_YourNameLabel");
        yourSuccessLabel_178 = ((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_YourSuccessLabel");
        yourFailureLabel_17c = ((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_YourFailureLabel");
        yourPercentLabel_180 = ((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_YourPercentLabel");
        refreshButton_0184_guess = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_RefreshButton");
        doneButton_0188_guess = (CComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("AdvLeaderboard_DoneButton");
        requestPending_015c_guess = 0;
        if (selectCombo_0164_guess != 0) {
            selectCombo_0164_guess->SetCurSel_guess(0);
            selectCombo_0164_guess->SetColors_guess(-1, 0xffffff00, 0xff808080);
        }
        if (riskCombo_0168_guess != 0) {
            riskCombo_0168_guess->SetCurSel_guess(0);
            riskCombo_0168_guess->SetColors_guess(-1, 0xffffff00, 0xff808080);
        }
        if (leaderList_016c != 0) {
            leaderList_016c->SetColors(0xffffffff, 0xffffffff, 0xff000000);
            // Light blue highlight; yellow (0xFFFFFF00) marks the player's own row in the reply.
            ((ListFields_guess*)leaderList_016c)->textColor_guess = 0xff8aa3ff;
            ((ListFields_guess*)leaderList_016c)->flag_guess = 0;
            leaderList_016c->SetColumnJustification(0, 1);
            leaderList_016c->SetColumnJustification(1, 0);
            leaderList_016c->SetColumnJustification(2, 1);
            leaderList_016c->SetColumnJustification(3, 1);
            leaderList_016c->SetColumnJustification(4, 2);
        }
    }
}

// Destructor of the adventure leaderboard window: restores its vtable (0x64E5B0) and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x004D5B22
CAdventureLeaderboardWnd_guess::~CAdventureLeaderboardWnd_guess()  {
}

// Show hook: when shown (+0x5C), pops context tip 0x26 on CTipWnd, then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x004D5B4D
void CAdventureLeaderboardWnd_guess::OnShow_guess() {
    if (active != 0) {
        Refresh_guess();
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x26, 0);
        }
    }
    return OnShow();
}

// OnProcessFrame: once the 10 s request cooldown is over, re-enables the combo boxes and Refresh.
// FUNCTION: TITANIUM 0x004D5B76
void CAdventureLeaderboardWnd_guess::OnProcessFrame_guess() {
    if (CanRefresh_guess() != 0) {
        unsigned char* pending = &requestPending_015c_guess;
        if (*pending != 0 && g_Timer_guess->ticks >= cooldownEnd_0160_guess) {
            *pending = 0;
            if (selectCombo_0164_guess != 0) {
                selectCombo_0164_guess->active = 1;
            }
            if (riskCombo_0168_guess != 0) {
                riskCombo_0168_guess->active = 1;
            }
            if (refreshButton_0184_guess != 0) {
                refreshButton_0184_guess->active = 1;
            }
        }
    }
    return OnProcessFrame();
}

// Sends AdventureLeaderboardRequest (0x230A, 12 bytes) and disables the controls for 10 s (CDisplay ms
// clock +0x148).
// FUNCTION: TITANIUM 0x004D5BD6
void CAdventureLeaderboardWnd_guess::SendLeaderboardRequest_guess() {
    if (selectCombo_0164_guess != 0 && riskCombo_0168_guess != 0) {
        int value = selectCombo_0164_guess->GetCurChoice_guess();
        int tail = riskCombo_0168_guess->GetCurChoice_guess();
        int data[3];
        // The select combo alternates the two sort orders per theme: even = by wins, odd = by percent;
        // value / 2 is the theme, the risk combo the third int.
        data[0] = value % 2;
        data[1] = value / 2;
        data[2] = tail;
        EQSendMessage(g_Message_guess, OP_AdventureLeaderboardRequest, &data[0], 0xc, 1);
        if (refreshButton_0184_guess != 0) {
            refreshButton_0184_guess->active = 0;
        }
        selectCombo_0164_guess->active = 0;
        riskCombo_0168_guess->active = 0;
        requestPending_015c_guess = 1;
        cooldownEnd_0160_guess = g_Timer_guess->ticks + 10000;
    }
    return;
}

// Scalar deleting destructor (vtable 0x64E5B0 slot 1): destroys the window and frees it when flag 1
// is set.
// FUNCTION: TITANIUM 0x004D5C7D
CAdventureLeaderboardWnd_guess* CAdventureLeaderboardWnd_guess::Delete_guess(unsigned char flags) {
    this->CAdventureLeaderboardWnd_guess::~CAdventureLeaderboardWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Opens the window if hidden (vtable slot 33) and asks the server for the current board.
// FUNCTION: TITANIUM 0x004D5C99
void CAdventureLeaderboardWnd_guess::Activate_guess() {
    if (CanRefresh_guess() == 0) {
        Slot33_guess();
        SendLeaderboardRequest_guess();
    }
}

// WndNotification: Done (click) or close (code 10) hides the window; a change in either combo box or
// Refresh sends a new request.
// FUNCTION: TITANIUM 0x004D5CB9
void CAdventureLeaderboardWnd_guess::WndNotification_guess(CComboWnd_guess* event, int type, int data) {
    if (type == 1) {
        if (event == doneButton_0188_guess) {
            Slot34_guess();
            Refresh_guess();
        } else if (event == selectCombo_0164_guess || event == riskCombo_0168_guess || event == refreshButton_0184_guess) {
            SendLeaderboardRequest_guess();
        }
    } else if (type == 10) {
        Slot34_guess();
        Refresh_guess();
    }
    // Dispatch after either event-specific action.
    WndNotification(event, type, data);
}

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" unsigned int __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x0060ED40 _strcmp
int __cdecl _strcmp(const char* first, const char* second);

// Window with a vtable: SetWindowTextA is virtual slot 63 (0xFC).
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
    virtual void AboutToHide_guess();
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
    virtual void SetWindowTextA_guess(const CXStr& text);
};

// List with a vtable: the clear is virtual slot 76 (0x130).
struct ListVirt_guess {
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
    virtual void AboutToHide_guess();
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
    virtual void Clear_guess();
    // EXTERNAL: TITANIUM 0x0059B3E0 ListVirt_guess::SetItemColor_guess
    void SetItemColor_guess(int row, int column, unsigned long color);
};

// Empties the leader list.
// FUNCTION: TITANIUM 0x004D5B2D
bool CAdventureLeaderboardWnd_guess::AboutToHide_guess() {
    if (leaderList_016c != 0) {
        leaderList_016c->ClearAllSel();
        ((ListVirt_guess*)leaderList_016c)->Clear_guess();
    }
    return true;
}

// Entry of the leaderboard payload: 0x48 bytes, the name first.
struct PayloadEntry_guess {
    char name_guess[0x40];
    int wins_0040_guess;
    int losses_0044_guess;
};

struct Payload_guess {
    int mode_guess;
    int pad_004_guess;
    int successes_guess;
    int failures_guess;
    int rank_guess;
    PayloadEntry_guess entries_guess[100];
};

// pCharData's class: the virtual base (vfptr at +0, Name at +0x3C) reached through the vbptr at +8.
struct CharDataBaseNm_guess {
    virtual void Slot00_guess();
    char pad_004_guess[0x38];
    char name_guess[0x40];
};

struct CharDataPrefixNm_guess {
    virtual void Slot00_guess();
    int field04_guess;
};

struct CharDataNm_guess : CharDataPrefixNm_guess, virtual CharDataBaseNm_guess {
};

#define g_charNm_guess EQ_GLOBAL(CharDataNm_guess*, 0x00905D00)

// Handle_OP_AdventureLeaderboardReply (0x0D0F): the player's rank, wins, losses and percent, then up to
// 100 rows of 0x48 bytes (name, wins, losses). Rank 0 prints "---".
// FUNCTION: TITANIUM 0x004D5D1D
// @early-stop: budget, structural ndiff=212
void CAdventureLeaderboardWnd_guess::Handle_OP_AdventureLeaderboardReply_guess(int unused_guess, int msg, Payload_guess* data, int unused2_guess) {
    if (msg == 0xd0f) {
        char text1c[0xc];
        char text30[0x14];
        char text3c[0xc];
        char text48[0xc];
        char text88[0x40];
        int row = 0;
        if (yourRankLabel_170 != 0) {
            if (data->rank_guess == 0) {
                sprintf(text1c, "---");
            } else {
                sprintf(text1c, "%d", data->rank_guess);
            }
            CXStr str(text1c);
            ((Text_guess*)yourRankLabel_170)->SetWindowTextA_guess(str);
        }
        if (yourNameLabel_174 != 0) {
            CXStr str(g_charNm_guess->name_guess);
            ((Text_guess*)yourNameLabel_174)->SetWindowTextA_guess(str);
        }
        if (yourSuccessLabel_178 != 0) {
            sprintf(text1c, "%d", data->successes_guess);
            CXStr str(text1c);
            ((Text_guess*)yourSuccessLabel_178)->SetWindowTextA_guess(str);
        }
        if (yourFailureLabel_17c != 0) {
            sprintf(text1c, "%d", data->failures_guess);
            CXStr str(text1c);
            ((Text_guess*)yourFailureLabel_17c)->SetWindowTextA_guess(str);
        }
        if (yourPercentLabel_180 != 0) {
            int successes = data->successes_guess;
            int total = successes + data->failures_guess;
            double pct;
            if (total == 0) {
                pct = 0.0;
            } else {
                pct = successes * 100.0 / total;
            }
            sprintf(text1c, "%3.1f%%", pct);
            CXStr str(text1c);
            ((Text_guess*)yourPercentLabel_180)->SetWindowTextA_guess(str);
        }
        if (leaderList_016c != 0) {
            leaderList_016c->ClearAllSel();
            ((ListVirt_guess*)leaderList_016c)->Clear_guess();
            int bestRow = 1;
            float bestPct = -999.9f;
            int bestValue = -999;
            int* pi = &data->entries_guess[0].wins_0040_guess;
            do {
                char* name = (char*)(pi - 0x10);
                if (strlen(name) > 0) {
                    unsigned long color = 0xffffffff;
                    if (_strcmp(name, g_charNm_guess->name_guess) == 0) {
                        color = 0xffffff00;
                    }
                    leaderList_016c->AddString("", color, 0, 0);
                    sprintf(text88, "%s", name);
                    leaderList_016c->SetItemText(row, 1, text88);
                    ((ListVirt_guess*)leaderList_016c)->SetItemColor_guess(row, 1, color);
                    sprintf(text30, "%d", *pi);
                    leaderList_016c->SetItemText(row, 2, text30);
                    ((ListVirt_guess*)leaderList_016c)->SetItemColor_guess(row, 2, color);
                    // Ties share a rank: by wins (mode 0) a new rank only when wins or losses
                    // differ; bestPct holds the win count here.
                    if (data->mode_guess == 0) {
                        int successes = *pi;
                        if (successes != (int)bestPct || pi[1] != bestValue) {
                            bestRow = row + 1;
                            bestPct = (float)successes;
                            bestValue = pi[1];
                        }
                    }
                    sprintf(text30, "%d", pi[1]);
                    leaderList_016c->SetItemText(row, 3, text30);
                    ((ListVirt_guess*)leaderList_016c)->SetItemColor_guess(row, 3, color);
                    int successes = *pi;
                    int total = successes + pi[1];
                    double exact;
                    if (total == 0) {
                        exact = 0.0;
                    } else {
                        exact = successes * 100.0 / total;
                    }
                    float pct = (float)exact;
                    sprintf(text30, "%3.1f%%", exact);
                    leaderList_016c->SetItemText(row, 4, text30);
                    ((ListVirt_guess*)leaderList_016c)->SetItemColor_guess(row, 4, color);
                    // By percent (mode 1): a new rank when the percent or the win count differs.
                    if (data->mode_guess == 1) {
                        if (pct != bestPct || *pi != bestValue) {
                            bestRow = row + 1;
                            bestPct = pct;
                            bestValue = *pi;
                        }
                    }
                    sprintf(text3c, "%d", bestRow);
                    leaderList_016c->SetItemText(row, 0, text3c);
                    ((ListVirt_guess*)leaderList_016c)->SetItemColor_guess(row, 0, color);
                    if (_strcmp(name, g_charNm_guess->name_guess) == 0) {
                        // The player's own row overrides the server's rank label, with no null test.
                        sprintf(text48, "%d", bestRow);
                        ((Text_guess*)yourRankLabel_170)->SetWindowTextA_guess(text48);
                    }
                }
                ++row;
                pi += 0x12;
            } while (row < 100);
        }
    }
}

