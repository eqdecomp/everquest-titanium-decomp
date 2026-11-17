// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 202: a hint from compare/tumap.py.
// CPvPStatsWnd (screen "PvPStatsWnd", vtable 0x65B6B8): the player's PvP totals, last kill, last death
// and kill history from pCharData +0xEAC-0xF8C. CPvPStatsWnd_guess, Derived_guess, Base_guess and
// Window54D581_guess are all views of it; PointerArray_guess is the shared growable pointer array (tu_005, tu_016).
#include <new>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/wnd/CTipWnd.h"
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z

struct HashEntry_guess
{
    char pad_guess[0x58];        // 0x00
    unsigned int hash_guess;     // 0x58
    HashEntry_guess* next_guess; // 0x5C
};

struct HashTable_guess
{
    HashEntry_guess** buckets_guess; // 0x00
    int count_guess;                 // 0x04

    // EXTERNAL: TITANIUM 0x004466FA HashTable_guess::First_guess
    HashEntry_guess* First_guess();
    HashEntry_guess* Next_guess(HashEntry_guess* entry_guess);
};

struct PointerArray_guess
{
    int first_guess;
    int* second_guess;
    int third_guess;
    unsigned char enabled_guess;
    unsigned char pad_guess[3];

    PointerArray_guess()
    {
        second_guess = 0;
        first_guess = 0;
        third_guess = 0;
        enabled_guess = 1;
    }

    ~PointerArray_guess() ;

    // EXTERNAL: TITANIUM 0x004EB924 PointerArray_guess::Slot_guess
    struct PvpEntry_guess*& Slot_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0050319B PointerArray_guess::Set_guess
    void Set_guess(int index_guess, struct PvpEntry_guess** value_guess);
};

struct CXStrPointer_guess : CXStr
{
    CXStrPointer_guess(const char* text_guess) : CXStr(text_guess) {}
    operator CXStr*() { return this; }
};

struct PvPList_guess : CListWnd
{
    unsigned char pad_140_guess[0x1c];
    unsigned char enabled_15c_guess;
    unsigned char pad_15d_guess[0xf];
    unsigned int color_16c_guess;
};

// Local polymorphic copy of CSidlScreenWnd (ctor 0x005A3850, dtor 0x005A3100), 0x15C bytes.
struct SidlBase_guess
{
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlBase_guess@@UAE@XZ
    virtual ~SidlBase_guess();
    // EXTERNAL: TITANIUM 0x005A3850 ??0SidlBase_guess@@QAE@PAUCXWnd@@PAUCXStr@@HHPAD@Z
    SidlBase_guess(CXWnd* parent_guess, CXStr* screen_guess, int flags_guess,
        int iniVersion_guess, char* blockName_guess);
    char pad_004_guess[0x66 - 0x04];
    unsigned char style_66_guess;      // WindowStyle byte 2
    char pad_067_guess[0x124 - 0x067];
    void* sidlPiece_124_guess;         // SidlPiece
    char pad_128_guess[0x158 - 0x128];
    int field_158_guess;               // 0x158
};

// EXTERNAL: TITANIUM 0x0065B6B8 ??_7CPvPStatsWnd_guess@@6B@
struct CPvPStatsWnd_guess : SidlBase_guess
{
    PointerArray_guess member_guess;
    PvPList_guess* last_kill_list_guess;
    PvPList_guess* last_death_list_guess;
    PvPList_guess* kills_list_guess;
    CXWnd* current_streak_label_guess;
    CXWnd* kill_streak_label_guess;
    CXWnd* death_streak_label_guess;
    CXWnd* available_value_guess;
    CXWnd* total_points_label_guess;
    CXWnd* kills_label_guess;
    CXWnd* deaths_label_guess;
    CXWnd* infamy_level_label_guess;
    CXWnd* vitality_label_guess;
    CXWnd* leaderboard_button_guess;
    CXWnd* done_button_guess;

    CPvPStatsWnd_guess(CXWnd* parent_guess);
    void Refresh_guess();
};

struct Base_guess
{
    char data_guess[0x158];

    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess() ;
};

// EXTERNAL: TITANIUM 0x0065B6B8 ??_7Derived_guess@@6B@
struct Derived_guess : Base_guess
{
    PointerArray_guess member_guess;

    virtual ~Derived_guess() ;

    void* Delete_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// Empties the array: frees the data and zeroes count and capacity. Also called directly as a reset.
// FUNCTION: TITANIUM 0x0050F3F6
PointerArray_guess::~PointerArray_guess()
{
    if (second_guess != 0)
    {
        delete[] second_guess;
    }
    second_guess = 0;
    third_guess = 0;
    first_guess = 0;
}

struct Window54D581_guess
{
    char pad_guess[0x5C];
    char flag_guess;             // 0x5C

    // EXTERNAL: TITANIUM 0x0054C4CC Window54D581_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x005A1880 Window54D581_guess::OnShow
    void OnShow();
    void Update_guess();
};

// Iterator step: the next entry in the same chain, else the head of the next non-empty bucket; 0 at the end.
// FUNCTION: TITANIUM 0x0054BFEA
HashEntry_guess* HashTable_guess::Next_guess(HashEntry_guess* entry_guess)
{
    int i = entry_guess->hash_guess % count_guess;
    HashEntry_guess* n = entry_guess->next_guess;
    if (n)
        return n;
    int j = i + 1;
    if (i + 1 < count_guess)
    {
        for (; j < count_guess; ++j)
        {
            n = buckets_guess[j];
            if (n)
                return n;
        }
    }
    return 0;
}

// Builds the window from SIDL and binds its three lists and the labels.
// FUNCTION: TITANIUM 0x0054C020
CPvPStatsWnd_guess::CPvPStatsWnd_guess(CXWnd* parent_guess)
    : SidlBase_guess(parent_guess, CXStrPointer_guess("PvPStatsWnd"), -0x201, 1, 0)
{
    available_value_guess = 0;
    infamy_level_label_guess = 0;
    vitality_label_guess = 0;
    current_streak_label_guess = 0;
    kill_streak_label_guess = 0;
    death_streak_label_guess = 0;
    total_points_label_guess = 0;
    kills_label_guess = 0;
    deaths_label_guess = 0;
    last_kill_list_guess = 0;
    last_death_list_guess = 0;
    leaderboard_button_guess = 0;
    done_button_guess = 0;

    if (sidlPiece_124_guess != 0)
    {
        style_66_guess |= 1;
        // 50 is also the CTipWindow tip OnShow asks for; +0x158 is probably the window's tip id.
        field_158_guess = 0x32;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();

        {
            CXStr name_guess("PvpStats_LastKillList");
            last_kill_list_guess = static_cast<PvPList_guess*>(((CSidlScreenWnd*)this)->GetChildItem(name_guess));
        }
        last_kill_list_guess->color_16c_guess = 0xff8aa3ff;
        last_kill_list_guess->enabled_15c_guess = 1;
        last_kill_list_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);

        {
            CXStr name_guess("PvpStats_LastDeathList");
            last_death_list_guess = static_cast<PvPList_guess*>(((CSidlScreenWnd*)this)->GetChildItem(name_guess));
        }
        last_death_list_guess->color_16c_guess = 0xff8aa3ff;
        last_death_list_guess->enabled_15c_guess = 1;
        last_death_list_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);

        {
            CXStr name_guess("PvpStats_KillsList");
            kills_list_guess = static_cast<PvPList_guess*>(((CSidlScreenWnd*)this)->GetChildItem(name_guess));
        }
        kills_list_guess->color_16c_guess = 0xff8aa3ff;
        kills_list_guess->enabled_15c_guess = 1;
        kills_list_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);

        {
            CXStr name_guess("PvpStats_YourCurrentStreakLabel");
            current_streak_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourKillStreakLabel");
            kill_streak_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourDeathStreakLabel");
            death_streak_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_AvailableValue");
            available_value_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_TotalPointsLabel");
            total_points_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourKillsLabel");
            kills_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourDeathsLabel");
            deaths_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourInfamyLevelLabel");
            infamy_level_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_YourVitalityLabel");
            vitality_label_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_LeaderboardButton");
            leaderboard_button_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
        {
            CXStr name_guess("PvpStats_DoneButton");
            done_button_guess = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
        }
    }
}

// Destructor of the PvP stats window (vtable 0x65B6B8): frees its pointer array (+0x15C, 0x0050F3F6),
// then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0054C494
Derived_guess::~Derived_guess() 
{
}

// Scalar deleting destructor (names.tsv EQ_TextIO::~EQ_TextIO is a low-confidence mismatch).
// FUNCTION: TITANIUM 0x0054C4B0
void* Derived_guess::Delete_guess(unsigned char flags_guess)
{
    this->Derived_guess::~Derived_guess();
    if ((flags_guess & 1) != 0)
    {
        free(this);
    }
    return this;
}

// Virtual view of a window: slot 63 (+0xFC) sets the text, slot 76 (+0x130)
// clears a list.
struct CXWndVt_guess
{
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
    virtual void SetText_guess(const CXStr& text_guess); // 0xFC
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
    virtual void DeleteAll_guess();                        // 0x130
};

// A PvP record as the leaderboard stores it.
struct PvpEntry_guess
{
    char name_guess[0x40];      // 0x00
    int level_0040_guess;       // 0x40
    int race_guess;             // 0x44
    int class_guess;            // 0x48
    char* zone_guess;           // 0x4C
    time_t time_guess;          // 0x50
    int points_guess;           // 0x54
    unsigned int hash_guess;    // 0x58
    PvpEntry_guess* next_guess; // 0x5C
};

struct CharData_guess
{
    char pad_0000_guess[0xEAC];
    int kills_guess;            // 0xEAC
    int deaths_guess;           // 0xEB0
    int available_guess;        // 0xEB4
    int points_guess;           // 0xEB8
    int bestStreak_guess;       // 0xEBC
    int worstStreak_guess;      // 0xEC0
    int streak_guess;           // 0xEC4
    char killName_guess[0x40];  // 0xEC8
    int killLevel_guess;        // 0xF08
    int killRace_guess;         // 0xF0C
    int killClass_guess;        // 0xF10
    char* killZone_guess;       // 0xF14
    time_t killTime_guess;      // 0xF18
    int killPoints_guess;       // 0xF1C
    char deathName_guess[0x40]; // 0xF20
    int deathLevel_guess;       // 0xF60
    int deathRace_guess;        // 0xF64
    int deathClass_guess;       // 0xF68
    char* deathZone_guess;      // 0xF6C
    time_t deathTime_guess;     // 0xF70
    int deathPoints_guess;      // 0xF74
    HashTable_guess pvpTable_guess; // 0xF78
    char pad_0f80_guess[8];     // 0xF80
    int infamy_guess;           // 0xF88
    int vitality_guess;         // 0xF8C
};

#define g_charData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)

struct ZoneLookup_guess
{
    // EXTERNAL: TITANIUM 0x005F6ED0 ZoneLookup_guess::GetName_guess
    void GetName_guess(const char* zone_guess, char* output_guess);
};

#define g_zoneLookup_guess EQ_GLOBAL(ZoneLookup_guess*, 0x00905CC0)

struct EverQuestNames_guess
{
    // EXTERNAL: TITANIUM 0x0049273D EverQuestNames_guess::GetRaceDesc
    char* GetRaceDesc(int value_guess);
    // EXTERNAL: TITANIUM 0x00491E5B EverQuestNames_guess::GetClassDesc
    char* GetClassDesc(int value_guess);
};

// EXTERNAL: TITANIUM 0x0060F81E Abs_guess
int __cdecl Abs_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0054BF48 CompareEntry_guess
int __cdecl CompareEntry_guess(const void* left_guess, const void* right_guess);
// EXTERNAL: TITANIUM 0x00405492 ThrowSelf_guess
__declspec(noreturn) void __cdecl ThrowSelf_guess();

struct UpdateLocals_guess
{
    int count_guess;                 // 0x00
    PvpEntry_guess* entry_guess;     // 0x04
    PointerArray_guess* array_guess;       // 0x08
};

#define VT_guess(w) ((CXWndVt_guess*)(w))
#define LI_guess(w) ((CListWnd*)(w))
#define NAMES_guess ((EverQuestNames_guess*)pEverQuest)

// Fills the labels from pCharData, then one row each for the last kill and the last death, then the
// whole kill history. Row columns: name, level, race, class, zone, points, time.
// FUNCTION: TITANIUM 0x0054C4CC
// @early-stop: budget, structural ndiff=44
void CPvPStatsWnd_guess::Refresh_guess()
{
    char leaderName_guess[100];
    char text_guess[100];
    char column_guess[100];

    if (available_value_guess != 0)
    {
        sprintf(text_guess, "%d", g_charData_guess->available_guess);
        VT_guess(available_value_guess)->SetText_guess(text_guess);
    }
    if (total_points_label_guess != 0)
    {
        sprintf(text_guess, "Total PvP Points: %d", g_charData_guess->points_guess);
        VT_guess(total_points_label_guess)->SetText_guess(text_guess);
    }
    if (kills_label_guess != 0)
    {
        sprintf(text_guess, "Kills: %d", g_charData_guess->kills_guess);
        VT_guess(kills_label_guess)->SetText_guess(text_guess);
    }
    if (deaths_label_guess != 0)
    {
        sprintf(text_guess, "Deaths: %d", g_charData_guess->deaths_guess);
        VT_guess(deaths_label_guess)->SetText_guess(text_guess);
    }
    if (current_streak_label_guess != 0)
    {
        // One signed streak: positive counts kills, negative deaths; the worst streak is stored negative too.
        if (g_charData_guess->streak_guess >= 0)
        {
            sprintf(text_guess, "Current Kill Streak: %d", g_charData_guess->streak_guess);
        }
        else
        {
            sprintf(text_guess, "Current Death Streak: %d",
                Abs_guess(g_charData_guess->streak_guess));
        }
        VT_guess(current_streak_label_guess)->SetText_guess(text_guess);
    }
    if (kill_streak_label_guess != 0)
    {
        sprintf(text_guess, "Best Kill Streak: %d", g_charData_guess->bestStreak_guess);
        VT_guess(kill_streak_label_guess)->SetText_guess(text_guess);
    }
    if (death_streak_label_guess != 0)
    {
        sprintf(text_guess, "Worst Death Streak: %d",
            Abs_guess(g_charData_guess->worstStreak_guess));
        VT_guess(death_streak_label_guess)->SetText_guess(text_guess);
    }
    if (infamy_level_label_guess != 0)
    {
        sprintf(text_guess, "Infamy: %d", g_charData_guess->infamy_guess);
        VT_guess(infamy_level_label_guess)->SetText_guess(text_guess);
    }
    if (vitality_label_guess != 0)
    {
        sprintf(text_guess, "Vitality: %d", g_charData_guess->vitality_guess);
        VT_guess(vitality_label_guess)->SetText_guess(text_guess);
    }
    if (last_kill_list_guess != 0)
    {
        VT_guess(last_kill_list_guess)->DeleteAll_guess();
        last_kill_list_guess->AddString(EQ_ARRAY(char, 0x0063F53F), -1, 0, 0);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0] ? g_charData_guess->killName_guess : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 0, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0]
                // _itoa and the zone lookup write into the sprintf target itself, so these copies overlap
                // (kept as original; harmless with this CRT).
                ? _itoa(g_charData_guess->killLevel_guess, column_guess, 10) : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 1, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0]
                ? NAMES_guess->GetRaceDesc(g_charData_guess->killRace_guess) : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 2, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0]
                ? NAMES_guess->GetClassDesc(g_charData_guess->killClass_guess) : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 3, column_guess);
        g_zoneLookup_guess->GetName_guess(g_charData_guess->killZone_guess, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0] ? column_guess : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 4, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0]
                ? _itoa(g_charData_guess->killPoints_guess, column_guess, 10) : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 5, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->killName_guess[0]
                // ctime's trailing newline goes into the cell as is.
                ? ctime(&g_charData_guess->killTime_guess) : "N/A");
        LI_guess(last_kill_list_guess)->SetItemText(0, 6, column_guess);
    }
    if (last_death_list_guess != 0)
    {
        VT_guess(last_death_list_guess)->DeleteAll_guess();
        last_death_list_guess->AddString(EQ_ARRAY(char, 0x0063F53F), -1, 0, 0);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0] ? g_charData_guess->deathName_guess : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 0, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0]
                ? _itoa(g_charData_guess->deathLevel_guess, column_guess, 10) : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 1, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0]
                ? NAMES_guess->GetRaceDesc(g_charData_guess->deathRace_guess) : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 2, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0]
                ? NAMES_guess->GetClassDesc(g_charData_guess->deathClass_guess) : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 3, column_guess);
        g_zoneLookup_guess->GetName_guess(g_charData_guess->deathZone_guess, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0] ? column_guess : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 4, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0]
                ? _itoa(g_charData_guess->deathPoints_guess, column_guess, 10) : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 5, column_guess);
        sprintf(column_guess, "%s",
            g_charData_guess->deathName_guess[0]
                ? ctime(&g_charData_guess->deathTime_guess) : "N/A");
        LI_guess(last_death_list_guess)->SetItemText(0, 6, column_guess);
    }
    if (kills_list_guess != 0)
    {
        UpdateLocals_guess locals_guess;
        int i_guess;
        locals_guess.count_guess = 0;
        locals_guess.array_guess = &member_guess;
        // Explicit destructor call = reset of the window's array; the kill records (pCharData +0xF78) are
        // collected into it and sorted with 0x54BF48.
        locals_guess.array_guess->~PointerArray_guess();
        locals_guess.entry_guess =
            (PvpEntry_guess*)g_charData_guess->pvpTable_guess.First_guess();
        if (locals_guess.entry_guess != 0)
        {
            do
            {
                locals_guess.array_guess->Set_guess(locals_guess.array_guess->first_guess,
                    &locals_guess.entry_guess);
                ++locals_guess.count_guess;
                locals_guess.entry_guess = (PvpEntry_guess*)g_charData_guess->pvpTable_guess
                    .Next_guess((HashEntry_guess*)locals_guess.entry_guess);
            } while (locals_guess.entry_guess != 0);
            if (locals_guess.count_guess > 0)
            {
                if (locals_guess.array_guess->first_guess <= 0
                    || locals_guess.array_guess->second_guess == 0)
                {
                    // Inlined bounds check of the array access.
                    ThrowSelf_guess();
                }
                qsort(locals_guess.array_guess->second_guess, locals_guess.count_guess, 4,
                    CompareEntry_guess);
                VT_guess(kills_list_guess)->DeleteAll_guess();
                i_guess = 0;
                if (locals_guess.count_guess > 0)
                {
                    do
                    {
                        kills_list_guess->AddString(EQ_ARRAY(char, 0x0063F53F), -1, 0, 0);
                        {
                            sprintf(leaderName_guess, "%s",
                                locals_guess.array_guess->Slot_guess(i_guess)->name_guess);
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 0, value_guess);
                        }
                        {
                            sprintf(leaderName_guess, "%d",
                                locals_guess.array_guess->Slot_guess(i_guess)->level_0040_guess);
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 1, value_guess);
                        }
                        {
                            sprintf(leaderName_guess, "%s", NAMES_guess->GetRaceDesc(
                                locals_guess.array_guess->Slot_guess(i_guess)->race_guess));
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 2, value_guess);
                        }
                        {
                            sprintf(leaderName_guess, "%s", NAMES_guess->GetClassDesc(
                                locals_guess.array_guess->Slot_guess(i_guess)->class_guess));
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 3, value_guess);
                        }
                        {
                            g_zoneLookup_guess->GetName_guess(
                                locals_guess.array_guess->Slot_guess(i_guess)->zone_guess,
                                leaderName_guess);
                            sprintf(leaderName_guess, "%s", leaderName_guess);
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 4, value_guess);
                        }
                        {
                            sprintf(leaderName_guess, "%d",
                                locals_guess.array_guess->Slot_guess(i_guess)->points_guess);
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 5, value_guess);
                        }
                        {
                            sprintf(leaderName_guess, "%s",
                                ctime(&locals_guess.array_guess->Slot_guess(i_guess)->time_guess));
                            CXStr value_guess(leaderName_guess);
                            LI_guess(kills_list_guess)->SetItemText(i_guess, 6, value_guess);
                        }
                    } while (++i_guess < locals_guess.count_guess);
                }
            }
        }
    }
}

// Probably the OnShow override: when +0x5C (likely the shown flag) is set, asks the context tip window
// (0x9928E0, CTipWindow mode 1) for tip 50 and refreshes; then the base handler 0x5A1880.
// FUNCTION: TITANIUM 0x0054D581
void Window54D581_guess::Update_guess()
{
    if (flag_guess != 0)
    {
        if (pinstCTipWndCONTEXT_guess != 0)
        {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x32, 0);
        }
        Refresh_guess();
    }
    OnShow();
}

