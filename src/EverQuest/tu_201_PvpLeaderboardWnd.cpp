// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 201: a hint from compare/tumap.py.
// The PvP leaderboard window (SIDL "PvpLeaderboardWnd"): asks the server for the top-100 board sorted by
// kills, points or infamy and shows a player's details on request. CPvpLeaderboardWnd_guess is its ctor view,
// CPvpLeaderboardWndView_guess the same object seen from the handlers (same offsets from +0x15C on).
// Payloads match EQEmu's PVPLeaderBoard*_Struct.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CTipWnd.h"

extern "C" {
// EXTERNAL: TITANIUM 0x0060DA00 memcpy
void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
// EXTERNAL: TITANIUM 0x0060D750 memset
void* __cdecl memset(void* dst, int value, unsigned int size);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* dst, const char* src);
// EXTERNAL: TITANIUM 0x0060D970 strlen
unsigned int __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x0060ED40 strcmp
int __cdecl strcmp(const char* a, const char* b);
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* dst, const char* format, ...);
}

// Leaderboard window controls: slot 0xFC is SetWindowText, slot 0x130 clears the list.
struct LeaderWnd_guess {
    virtual void V00(); virtual void V01(); virtual void V02(); virtual void V03();
    virtual void V04(); virtual void V05(); virtual void V06(); virtual void V07();
    virtual void V08(); virtual void V09(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33(); virtual void V34(); virtual void V35();
    virtual void V36(); virtual void V37(); virtual void V38(); virtual void V39();
    virtual void V40(); virtual void V41(); virtual void V42(); virtual void V43();
    virtual void V44(); virtual void V45(); virtual void V46(); virtual void V47();
    virtual void V48(); virtual void V49(); virtual void V50(); virtual void V51();
    virtual void V52(); virtual void V53(); virtual void V54(); virtual void V55();
    virtual void V56(); virtual void V57(); virtual void V58(); virtual void V59();
    virtual void V60(); virtual void V61(); virtual void V62();
    virtual void SetWindowText_guess(const CXStr& text);   // 0xFC
    virtual void V64(); virtual void V65(); virtual void V66(); virtual void V67();
    virtual void V68(); virtual void V69(); virtual void V70(); virtual void V71();
    virtual void V72(); virtual void V73(); virtual void V74(); virtual void V75();
    virtual void DeleteAll_guess();                        // 0x130
    // EXTERNAL: TITANIUM 0x00598580 LeaderWnd_guess::ClearAllSel
    void ClearAllSel();
    // EXTERNAL: TITANIUM 0x0059B9D0 LeaderWnd_guess::AddString
    int AddString(const CXStr& text, unsigned long color, unsigned int data, const CTextureAnimation* icon);
    // EXTERNAL: TITANIUM 0x0059B360 LeaderWnd_guess::SetItemText
    void SetItemText(int index, int column, const CXStr& text);
    // EXTERNAL: TITANIUM 0x0059B3E0 LeaderWnd_guess::SetItemColor_guess
    void SetItemColor_guess(int index, int column, unsigned long color);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_guess
void __cdecl FormatCXStr_guess(CXStr* out, const char* format, ...);

struct CharBase_guess {
    char pad[0x3c];
    char name_guess[0x40];                      // 0x3c
};
struct CharHead_guess {
    virtual void Slot00_guess();
    int field4_guess;
};
struct CharPc_guess : CharHead_guess, virtual CharBase_guess {
};
#define g_charPc_guess EQ_GLOBAL(CharPc_guess*, 0x00905D00)

struct GuildList_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 GuildList_guess::GetName_guess
    char* GetName_guess(int id);
};
#define g_guildList_guess EQ_GLOBAL(GuildList_guess, 0x00905D38)

struct EverQuestNames_guess {
    // EXTERNAL: TITANIUM 0x00491E5B EverQuestNames_guess::GetClassDesc
    char* GetClassDesc(int id);
    // EXTERNAL: TITANIUM 0x0049273D EverQuestNames_guess::GetRaceDesc
    char* GetRaceDesc(int id);
};
#define g_everQuestNames_guess EQ_GLOBAL(EverQuestNames_guess*, 0x00988DF0)

struct PvpEntry_guess {
    char name_guess[0x40];
    int kills_guess;                            // 0x40
    int deaths_guess;                           // 0x44
    int points_guess;                           // 0x48
    int infamy_guess;                           // 0x4c
};

struct PvpBoard_guess {
    int sort_guess;
    int kills_guess;                            // 0x04
    int points_guess;                           // 0x08
    int rank_guess;                             // 0x0c
    int deaths_guess;                           // 0x10
    int infamy_guess;                           // 0x14
    PvpEntry_guess entries_guess[100];          // 0x18
};

struct PvpInfo_guess {
    char name_guess[0x40];
    char lastName_guess[0x40];                  // 0x40
    int level_guess;                            // 0x80
    int race_guess;                             // 0x84
    int class_guess;                            // 0x88
    int guild_guess;                            // 0x8c
    int aa_guess;                               // 0x90
    int unknown94_guess;                        // 0x94
    int kills_guess;                            // 0x98
    int deaths_guess;                           // 0x9c
    int infamy_guess;                           // 0xa0
    int points_guess;                           // 0xa4
};

struct BaseSubobject_guess {
    // EXTERNAL: TITANIUM 0x005A3100 BaseSubobject_guess::~BaseSubobject_guess
    virtual ~BaseSubobject_guess();
    // EXTERNAL: TITANIUM 0x005A3850 BaseSubobject_guess::BaseSubobject_guess
    BaseSubobject_guess(int id, const struct CXStr& name, int flags, int mode, int reserved);
};

struct Control_guess {
    char pad[0x15c];
    char disabled_guess;                       // 0x15c
    char pad2[3];
    unsigned int color_guess;                  // 0x160
    char pad3[8];
    unsigned int textColor_guess;              // 0x16c
    // EXTERNAL: TITANIUM 0x0059C360 Control_guess::Reset_guess
    void Reset_guess(int value);
    // EXTERNAL: TITANIUM 0x0059C330 Control_guess::SetColors_guess
    void SetColors_guess(int a, int b, int c);
    // EXTERNAL: TITANIUM 0x00597C60 Control_guess::SetColors
    void SetColors(unsigned long a, unsigned long b, unsigned long c);
    // EXTERNAL: TITANIUM 0x005982E0 Control_guess::SetColumnJustification
    void SetColumnJustification(int index, int value);
};

// EXTERNAL: TITANIUM 0x0065B360 ??_7CPvpLeaderboardWnd_guess@@6B@
struct CPvpLeaderboardWnd_guess : BaseSubobject_guess {
    CPvpLeaderboardWnd_guess(int id);
    virtual ~CPvpLeaderboardWnd_guess();
    CPvpLeaderboardWnd_guess* Delete_guess(unsigned char flags);
    char pad[0x62];                            // 0x04
    char flag_guess;                           // 0x66
    char pad2[0xbd];                           // 0x67
    int initialized_guess;                     // 0x124
    char pad3[0x30];                           // 0x128
    int mode_guess;                            // 0x158
    char active_guess;                         // 0x15c
    char pad4[3];                              // 0x15d
    char pad5[4];                              // 0x160
    Control_guess* select_guess;               // 0x164
    Control_guess* list_guess;                 // 0x168
    Control_guess* rank_guess;                 // 0x16c
    Control_guess* name_guess;                 // 0x170
    Control_guess* kills_guess;                // 0x174
    Control_guess* deaths_guess;               // 0x178
    Control_guess* points_guess;               // 0x17c
    Control_guess* infamy_guess;               // 0x180
    Control_guess* refresh_guess;              // 0x184
    Control_guess* done_guess;                 // 0x188
    // EXTERNAL: TITANIUM 0x005A25B0 CPvpLeaderboardWnd_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A1E10 CPvpLeaderboardWnd_guess::GetChildItem
    Control_guess* GetChildItem(const CXStr& name);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct Peer_guess {
    char pad[0x5d];
    char enabled_005d_guess;                            // 0x5d
    // EXTERNAL: TITANIUM 0x0059C3A0 Peer_guess::GetCurChoice_guess
    int GetCurChoice_guess();
};

struct ListSelection_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x00597C00 ListSelection_guess::GetSelCount_guess
    int GetSelCount_guess();
};

struct Clock_guess {
    char pad[0x148];
    unsigned int tick_guess;                    // 0x148
};

struct CPvpLeaderboardWndView_guess {
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
    char pad[0x58];                             // 0x04
    char active;                                // 0x5c
    char pad2[0xff];                            // 0x5d
    char requestPending_015c_guess;                           // 0x15c
    char pad3[3];                               // 0x15d
    unsigned int deadline_guess;                // 0x160
    Peer_guess* sortCombobox_0164_guess;                     // 0x164
    LeaderWnd_guess* list_guess;                // 0x168
    LeaderWnd_guess* rank_guess;                // 0x16c
    LeaderWnd_guess* name_guess;                // 0x170
    LeaderWnd_guess* kills_guess;               // 0x174
    LeaderWnd_guess* deaths_guess;              // 0x178
    LeaderWnd_guess* points_guess;              // 0x17c
    LeaderWnd_guess* infamy_guess;              // 0x180
    Peer_guess* refreshButton_0184_guess;                    // 0x184
    Control_guess* done_guess;                  // 0x188
    char pad5[0x10];                            // 0x18c
    int id_guess;                               // 0x19c
    int id2_guess;                              // 0x1a0
    // EXTERNAL: TITANIUM 0x005A1880 CPvpLeaderboardWndView_guess::OnShow
    void OnShow();
    void OnShow_guess();
    void Run_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CPvpLeaderboardWndView_guess::First_guess
    char First_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CPvpLeaderboardWndView_guess::OnProcessFrame
    void OnProcessFrame();
    void Update_guess();
    void RequestLeaderboard_guess();
    void OpenAndRequest_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
    void PvPStatsWndNotification_guess(int value, int kind, int data);
    void OnServerMessage_guess(void* sender, int message, void* data, int length);
    // EXTERNAL: TITANIUM 0x005A2230 CPvpLeaderboardWndView_guess::WndNotification
    void WndNotification(int value, int kind, int data);
    bool ResetSelection_guess();
};

struct Sock_guess {
    char pad;
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_sock_guess EQ_GLOBAL(Sock_guess, 0x00905CA0)
#define pinstCPvpLeaderboardWnd_guess EQ_GLOBAL(CPvpLeaderboardWndView_guess*, 0x00991E94)

struct Registry_guess {
    int pad_guess;
    struct RegistryInner_guess* inner_guess;    // 0x04
    struct Iter_guess { void* node; Iter_guess(void* n) : node(n) {} };
    Iter_guess Begin_guess();
    // EXTERNAL: TITANIUM 0x00518D4A Registry_guess::Insert_guess
    void Insert_guess(Iter_guess where, int* const& data);
    void PushFront_guess(int* const& data) { Insert_guess(Begin_guess(), data); }
};

struct RegistryInner_guess {
    void* key_guess;
};

inline Registry_guess::Iter_guess Registry_guess::Begin_guess() { return Iter_guess(inner_guess->key_guess); }

struct Notifier_guess {
    char pad[0x15c];
    int field_guess;                            // 0x15c
    char pad2[0xb4];
    char flag_guess;                            // 0x214
    bool AboutToShow_guess();
};

#define g_counter_a_guess EQ_GLOBAL(int, 0x009248D4)
#define g_counter_b_guess EQ_GLOBAL(int, 0x009248D0)
#define g_registry_guess EQ_GLOBAL(Registry_guess*, 0x0079C120)

// AboutToShow of the progression selection window (slot 49 of vtable 0x65AE78, ctor 0x0054A413): bumps the
// counters 0x9248D4 / 0x9248D0, clears +0x214 and queues +0x15C at the front of the registry list 0x79C120
// when it exists; always true. AboutToHide (0x00549D55) undoes it.
// FUNCTION: TITANIUM 0x0054B02A
bool Notifier_guess::AboutToShow_guess() {
    g_counter_a_guess++;
    g_counter_b_guess++;
    flag_guess = 0;
    if (g_registry_guess != 0) {
        int* data = &field_guess;
        g_registry_guess->PushFront_guess(data);
    }
    return true;
}

// Binds the ten PvpLeaderboard_* children. 0x31 at +0x158 is probably the window's id (Deactivate_guess
// reports the same 0x31 to the dispatcher). The sort combobox gets yellow text; the list a light-blue header
// colour and its six columns rank, name, kills, deaths, points, infamy.
// FUNCTION: TITANIUM 0x0054B068
CPvpLeaderboardWnd_guess::CPvpLeaderboardWnd_guess(int id)
    : BaseSubobject_guess(id, "PvpLeaderboardWnd", 0xfffffdff, 1, 0) {
    select_guess = 0;
    list_guess = 0;
    rank_guess = 0;
    name_guess = 0;
    kills_guess = 0;
    deaths_guess = 0;
    points_guess = 0;
    infamy_guess = 0;
    refresh_guess = 0;
    done_guess = 0;

    if (initialized_guess != 0) {
        flag_guess |= 1;
        mode_guess = 0x31;
        CreateChildrenFromSidl();
        select_guess = GetChildItem("PvpLeaderboard_SelectCombobox");
        list_guess = GetChildItem("PvpLeaderboard_LeaderList");
        rank_guess = GetChildItem("PvpLeaderboard_YourRankLabel");
        name_guess = GetChildItem("PvpLeaderboard_YourNameLabel");
        kills_guess = GetChildItem("PvpLeaderboard_YourKillsLabel");
        deaths_guess = GetChildItem("PvpLeaderboard_YourDeathsLabel");
        points_guess = GetChildItem("PvpLeaderboard_YourPointsLabel");
        infamy_guess = GetChildItem("PvpLeaderboard_YourInfamyLabel");
        refresh_guess = GetChildItem("PvpLeaderboard_RefreshButton");
        done_guess = GetChildItem("PvpLeaderboard_DoneButton");
        active_guess = 0;
        if (select_guess != 0) {
            select_guess->Reset_guess(0);
            select_guess->SetColors_guess(-1, 0xffffff00, 0xff808080);
        }
        if (list_guess != 0) {
            list_guess->SetColors(-1, -1, 0xff808080);
            list_guess->textColor_guess = 0xff8aa3ff;
            list_guess->disabled_guess = 0;
            list_guess->SetColumnJustification(0, 1);
            list_guess->SetColumnJustification(1, 0);
            list_guess->SetColumnJustification(2, 1);
            list_guess->SetColumnJustification(3, 1);
            list_guess->SetColumnJustification(4, 1);
            list_guess->SetColumnJustification(5, 1);
        }
    }
}

// Destructor of the PvP leaderboard window (vtable 0x65B360): restores its vtable and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x0054B400
CPvpLeaderboardWnd_guess::~CPvpLeaderboardWnd_guess() {
}

// Scalar deleting destructor of the PvP leaderboard window (vtable 0x65B360 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0054B4FE
CPvpLeaderboardWnd_guess* CPvpLeaderboardWnd_guess::Delete_guess(unsigned char flags) {
    this->CPvpLeaderboardWnd_guess::~CPvpLeaderboardWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// PvP leaderboard window AboutToHide (vtable 0x65B360 slot 50): clears the list selection (+0x168,
// 0x00598580); never vetoes.
// FUNCTION: TITANIUM 0x0054B40B
bool CPvpLeaderboardWndView_guess::ResetSelection_guess() {
    if (list_guess != 0) {
        list_guess->ClearAllSel();
    }
    return true;
}

// OnShow (vtable slot 35; the code name Deactivate_guess is wrong): when shown, shows context tip 0x31 in the
// tip window (0x9928E0); then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x0054B41D
void CPvpLeaderboardWndView_guess::OnShow_guess() {
    if (active && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x31, 0);
    }
    return OnShow();
}

// Per-frame: 10 s after a request (RequestLeaderboard_guess) re-enables the sort combobox (+0x164) and the
// refresh button (+0x184); their +0x5D is the enabled flag.
// FUNCTION: TITANIUM 0x0054B441
void CPvpLeaderboardWndView_guess::Update_guess() {
    if (First_guess() != 0 && requestPending_015c_guess != 0 && g_clock_guess->tick_guess >= deadline_guess) {
        requestPending_015c_guess = 0;
        if (sortCombobox_0164_guess != 0) {
            sortCombobox_0164_guess->enabled_005d_guess = 1;
        }
        if (refreshButton_0184_guess != 0) {
            refreshButton_0184_guess->enabled_005d_guess = 1;
        }
    }
    return OnProcessFrame();
}

// Sends OP_PVPLeaderBoardRequest (4 bytes: the combobox choice, 0 kills, 1 points, 2 infamy) and disables
// the combobox and refresh button for 10 s, so the board can't be re-requested faster than that.
// FUNCTION: TITANIUM 0x0054B493
void CPvpLeaderboardWndView_guess::RequestLeaderboard_guess() {
    if (sortCombobox_0164_guess != 0) {
        int value = sortCombobox_0164_guess->GetCurChoice_guess();
        EQSendMessage(&g_sock_guess, OP_PVPLeaderBoardRequest, &value, 4, 1);
        if (refreshButton_0184_guess != 0) {
            refreshButton_0184_guess->enabled_005d_guess = 0;
        }
        sortCombobox_0164_guess->enabled_005d_guess = 0;
        requestPending_015c_guess = 1;
        deadline_guess = g_clock_guess->tick_guess + 10000;
    }
}

// Opens the window (vslot 33) and requests the board, when it is not already open.
// FUNCTION: TITANIUM 0x0054B51A
void CPvpLeaderboardWndView_guess::OpenAndRequest_guess() {
    if (!First_guess()) {
        Slot33_guess();
        return RequestLeaderboard_guess();
    }
}

// Done closes (vslot 34); a click on the combobox or OnProcessFrame_guess re-requests. Message 3 on the list
// with one
// row selected sends OP_PVPLeaderBoardDetailsRequest (0x44 bytes: 4 zero bytes, then the row's name).
// Message 10 closes too (probably the close box).
// FUNCTION: TITANIUM 0x0054B53A
// @early-stop: budget, structural ndiff=21
int CPvpLeaderboardWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if (sender == (CXWnd*)done_guess) {
            Slot34_guess();
        } else if (sender == (CXWnd*)sortCombobox_0164_guess || sender == (CXWnd*)refreshButton_0184_guess) {
            RequestLeaderboard_guess();
        }
    } else if (message == 3) {
        if (sender == (CXWnd*)list_guess) {
            if (((ListSelection_guess*)list_guess)->GetSelCount_guess() == 1) {
                char buffer[0x44];
                memset(buffer, 0, sizeof(buffer));
                int index = ((CListWnd*)list_guess)->GetCurSel();
                // Name column (1) of the selected row.
                strcpy(&buffer[4], ((CListWnd*)list_guess)->GetItemText(index, 1));
                EQSendMessage(&g_sock_guess, OP_PVPLeaderBoardDetailsRequest, buffer, sizeof(buffer), 1);
            }
            return 0;
        }
    } else if (message == 10) {
        Slot34_guess();
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// OP_PVPLeaderBoardDetailsReply (0xA8 bytes, else ignored): a type-11 confirmation dialog listing race,
// class, level, AAs, guild and PvP stats, titled "<name> <last name>".
// OP_PVPLeaderBoardReply: your own stats in the labels, then up to 100 rows; your own row is yellow.
// Tied rows share a rank. Under sort 1 and 2 the tie test compares kills with the last points/infamy value,
// so ties there are almost never found (possible original bug; this function is an early stop).
// FUNCTION: TITANIUM 0x0054B657
// @early-stop: budget, diff ndiff=90
void CPvpLeaderboardWndView_guess::OnServerMessage_guess(void* sender, int message, void* data, int length) {
    char text[12];
    char value[20];
    char rankText[12];
    char myRank[12];
    PvpInfo_guess info;
    char name[64];
    char guild[64];
    switch (message) {
    case 0x246a: {
        CXStr str;
        if (length == sizeof(PvpInfo_guess)) {
            memcpy(&info, data, sizeof(PvpInfo_guess));
            if (info.guild_guess == -1) {
                // Guild id -1: no guild.
                strcpy(guild, "None");
            } else {
                strcpy(guild, g_guildList_guess.GetName_guess(info.guild_guess));
            }
            FormatCXStr_guess(&str,
                "Race: %s <BR> Class: %s <BR> Level: %d <BR> Total AA's: %d <BR> Guild: %s <BR> Kills: %d <BR> Deaths: %d <BR> Total Points: %d <BR> Infamy: %d",
                g_everQuestNames_guess->GetRaceDesc(info.race_guess),
                g_everQuestNames_guess->GetClassDesc(info.class_guess),
                info.level_guess, info.aa_guess, guild, info.kills_guess, info.deaths_guess,
                info.points_guess, info.infamy_guess);
            LeaderWnd_guess* dialog = (LeaderWnd_guess*)pConfirmationDialogPool_guess->Activate(
                0, 0xb, (char*)str, 1, -1, 0, 1);
            if (dialog != 0) {
                FormatCXStr_guess(&str, "%s %s", info.name_guess, info.lastName_guess);
                dialog->SetWindowText_guess(str);
            }
        }
        break;
    }
    case 0x1a59: {
        PvpBoard_guess* board = (PvpBoard_guess*)data;
        if (rank_guess != 0) {
            if (board->rank_guess == 0) {
                // Rank 0: not on the board.
                sprintf(text, "---");
            } else {
                sprintf(text, "%d", board->rank_guess);
            }
            rank_guess->SetWindowText_guess(text);
        }
        if (name_guess != 0) {
            name_guess->SetWindowText_guess(g_charPc_guess->name_guess);
        }
        if (kills_guess != 0) {
            sprintf(text, "%d", board->kills_guess);
            kills_guess->SetWindowText_guess(text);
        }
        if (deaths_guess != 0) {
            sprintf(text, "%d", board->deaths_guess);
            deaths_guess->SetWindowText_guess(text);
        }
        if (points_guess != 0) {
            sprintf(text, "%d", board->points_guess);
            points_guess->SetWindowText_guess(text);
        }
        if (infamy_guess != 0) {
            sprintf(text, "%d", board->infamy_guess);
            infamy_guess->SetWindowText_guess(text);
        }
        if (list_guess != 0) {
            list_guess->ClearAllSel();
            list_guess->DeleteAll_guess();
            int rank = 1;
            float bestValue = -999.9f;
            int lastValue = -999;
            for (int i = 0; i < 100; i++) {
                PvpEntry_guess* entry = &board->entries_guess[i];
                if (strlen(entry->name_guess) > 0) {
                    unsigned long color = 0xffffffff;
                    if (strcmp(entry->name_guess, g_charPc_guess->name_guess) == 0) {
                        color = 0xffffff00;
                    }
                    list_guess->AddString("", color, 0, 0);
                    sprintf(name, "%s", entry->name_guess);
                    list_guess->SetItemText(i, 1, name);
                    list_guess->SetItemColor_guess(i, 1, color);
                    sprintf(value, "%d", entry->kills_guess);
                    list_guess->SetItemText(i, 2, value);
                    list_guess->SetItemColor_guess(i, 2, color);
                    if (board->sort_guess == 0 &&
                        ((float)entry->kills_guess != bestValue || entry->points_guess != lastValue)) {
                        bestValue = (float)entry->kills_guess;
                        rank = i + 1;
                        lastValue = entry->points_guess;
                    }
                    sprintf(value, "%d", entry->deaths_guess);
                    list_guess->SetItemText(i, 3, value);
                    list_guess->SetItemColor_guess(i, 3, color);
                    sprintf(value, "%d", entry->points_guess);
                    list_guess->SetItemText(i, 4, value);
                    list_guess->SetItemColor_guess(i, 4, color);
                    if (board->sort_guess == 1 &&
                        (bestValue != (float)entry->points_guess || entry->kills_guess != lastValue)) {
                        rank = i + 1;
                        lastValue = entry->points_guess;
                        bestValue = (float)lastValue;
                    }
                    sprintf(value, "%d", entry->infamy_guess);
                    list_guess->SetItemText(i, 5, value);
                    list_guess->SetItemColor_guess(i, 5, color);
                    if (board->sort_guess == 2 &&
                        (bestValue != (float)entry->infamy_guess || entry->kills_guess != lastValue)) {
                        rank = i + 1;
                        lastValue = entry->infamy_guess;
                        bestValue = (float)lastValue;
                    }
                    sprintf(rankText, "%d", rank);
                    list_guess->SetItemText(i, 0, rankText);
                    list_guess->SetItemColor_guess(i, 0, color);
                    if (strcmp(entry->name_guess, g_charPc_guess->name_guess) == 0) {
                        sprintf(myRank, "%d", rank);
                        rank_guess->SetWindowText_guess(myRank);
                    }
                }
            }
        }
        break;
    }
    }
}

// Shared OnProcessFrame override (slot 43 of the journal NPC, PvP stats and ticket comment window
// vtables; one body for all three): calls 0x0059DD30, ignoring the result, then the CXWnd
// OnProcessFrame (0x005A0E50).
// FUNCTION: TITANIUM 0x0054BF85
void CPvpLeaderboardWndView_guess::Run_guess() {
    First_guess();
    return OnProcessFrame();
}

// The PvP stats window's WndNotification (slot 32 of vtable 0x65B6B8, ctor 0x0054C020): a click (1) on the
// button at +0x19C opens the PvP leaderboard (0x991E94, OpenAndRequest_guess: Activate and request); the
// button at +0x1A0, or close (message 10), closes this window (slot 34). The rest goes to WndNotification.
// FUNCTION: TITANIUM 0x0054BF95
void CPvpLeaderboardWndView_guess::PvPStatsWndNotification_guess(int value, int kind, int data) {
    if (kind == 1) {
        if (value == id_guess) {
            if (pinstCPvpLeaderboardWnd_guess != 0) {
                pinstCPvpLeaderboardWnd_guess->OpenAndRequest_guess();
            }
        } else if (value == id2_guess) {
            Slot34_guess();
        }
    } else if (kind == 10) {
        Slot34_guess();
    }
    WndNotification(value, kind, data);
}

