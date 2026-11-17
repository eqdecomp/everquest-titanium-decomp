// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 99: a hint from compare/tumap.py.
// CActionsWnd ("ActionsWindow", global 0x850C44): the four-page Actions window. CActionsWnd_guess is
// CActionsWnd: +0x160/+0x190/+0x1B0/+0x1D0 are the Main, Abilities, Combat and Socials pages, page 0-3 of
// the ACTW_ActionsSubwindows tab box (+0x15C). The g_item* globals are skill data, not items (0x851200
// is the skill table); 0x850BB8 is the skill picker (CSkillsSelectWnd) and 0x9928E0 the tip-of-the-day.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/wnd/CSocialEditWnd.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CFindLocationWnd.h"


struct CListWndView_guess;

struct Callback_guess {
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    // EXTERNAL: TITANIUM 0x00553F90 Callback_guess::FillList_guess
    void FillList_guess(int mode);
    char pad_0004_015b_guess[0x158];
    void* owner_015c_guess;
    int pad_0160_guess;
    struct CListWndView_guess* list_0164_guess;
};

#define pinstCSkillsSelectWnd_guess EQ_GLOBAL(Callback_guess*, 0x00850BB8)

struct Control_guess {
    char pad_0004_005b_guess[0x58];
    char field_005c_guess;
    char enabled_005d_guess;
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void SetValue_guess(bool value, int flags);
};

struct LookupEntry_guess {
    int pad_0000_guess;
    int pad_0004_guess;
    int value_0008_guess;
};

struct LookupTable_guess {
    // EXTERNAL: TITANIUM 0x0051A84D LookupTable_guess::FindInvSlot
    LookupEntry_guess* FindInvSlot(int key);
};

struct ValueControl_guess {
    char pad_0000_016b_guess[0x16c];
    int value_016c_guess;
    int value_0170_guess;
    int value_0174_guess;
    char pad_0178_017b_guess[4];
    int value_017c_guess;
};

struct Root_guess {
    char pad_0000_0147_guess[0x148];
    int frameTime_0148_guess;
};

#define pinstCInvSlotMgr_guess EQ_GLOBAL(LookupTable_guess*, 0x00850CB8)
#define g_root_guess EQ_GLOBAL(Root_guess*, 0x00905D24)

struct FlagOwner_guess {
    char pad_0000_0250_guess[0x251];
    char standState_0251_guess;
    // EXTERNAL: TITANIUM 0x00479EA3 FlagOwner_guess::IsGroupInvitePending_guess
    char IsGroupInvitePending_guess();
    // EXTERNAL: TITANIUM 0x0048297B FlagOwner_guess::DoAttack
    void DoAttack(int a, int b, int c);
};

#define g_flagOwner_guess EQ_GLOBAL(FlagOwner_guess*, 0x00905CE4)
#define g_runMode_guess EQ_GLOBAL(char, 0x009237B4)

struct Str_guess {
    int rep_0000_guess;
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess&);
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::Chars_guess
    char* Chars_guess(int width);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep_guess
    void FreeRep_guess(int rep);
    ~Str_guess() {
        if (rep_0000_guess != 0) {
            FreeRep_guess(rep_0000_guess);
        }
        rep_0000_guess = 0;
    }
};

struct StringOwner_guess {
    char pad_0000_0073_guess[0x74];
    Str_guess value_0074_guess;
    Str_guess get_guess();
};

// CXWnd::GetWindowTextA: a copy of the window text (+0x74).
// FUNCTION: TITANIUM 0x004D22D7
Str_guess StringOwner_guess::get_guess() {
    return value_0074_guess;
}

struct ValueSource_guess {
    // EXTERNAL: TITANIUM 0x005BC390 ValueSource_guess::getValue_guess
    int getValue_guess();
    // EXTERNAL: TITANIUM 0x005BC460 ValueSource_guess::setValue_guess
    void setValue_guess(int, int);
};

struct TextValue_guess {
    // EXTERNAL: TITANIUM 0x005BA300 TextValue_guess::toFlags_guess
    int toFlags_guess();
};

struct TextService_guess {
    // EXTERNAL: TITANIUM 0x004B2459 TextService_guess::first_guess
    TextValue_guess* first_guess(int id);
    // EXTERNAL: TITANIUM 0x004B244F TextService_guess::second_guess
    TextValue_guess* second_guess(int id, int flags);
};

struct ValueSink_guess {
    // EXTERNAL: TITANIUM 0x0059DBF0 ValueSink_guess::set_guess
    void set_guess(int flags);
};

#define g_textService_guess EQ_GLOBAL(TextService_guess*, 0x0098599C)

struct TempValue_guess;

struct PieceNode_guess {
    char pad_0000_005f_guess[0x60];
    int flags_0060_guess;
};

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 Base_guess::Base_guess
    Base_guess(void* parent, const TempValue_guess& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    ~Base_guess();
    virtual void slot00_guess();
};

struct EventMsg_guess {
    int pad_0000_guess[2];
    int value_0008_guess;
    int value_000c_guess;
};

// EXTERNAL: TITANIUM 0x0064E048 ??_7CActionsWnd_guess@@6B@
struct CActionsWnd_guess : Base_guess {
    CActionsWnd_guess(void* parent);
    // EXTERNAL: TITANIUM 0x005A25B0 CActionsWnd_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    char pad_0004_0017_guess[0x14];
    unsigned char flag_0018_guess;
    char pad_0019_0063_guess[0x4b];
    int flags_0064_guess;
    char pad_0068_0123_guess[0xbc];
    PieceNode_guess* piece_0124_guess;
    char pad_0128_015b_guess[0x34];
    ValueSource_guess* actionsSubwindows_015c_guess;
    int actionsMainPage_0160_guess;
    int whoButton_0164_guess;
    int findButton_0168_guess;
    int endFindButton_016c_guess;
    int inviteButton_0170_guess;
    int followButton_0174_guess;
    int disbandButton_0178_guess;
    int campButton_017c_guess;
    int sitButton_0180_guess;
    int standButton_0184_guess;
    int runButton_0188_guess;
    int walkButton_018c_guess;
    int actionsAbilitiesPage_0190_guess;
    int values_0194_guess[6];
    int selectedAbilitySlot_01ac_guess;
    int actionsCombatPage_01b0_guess;
    int values_01b4_guess[7];
    int actionsSocialsPage_01d0_guess;
    int socialPageRightButton_01d4_guess;
    int socialPageLeftButton_01d8_guess;
    int currentSocialPageLabel_01dc_guess;
    int values_01e0_guess[12];
    int value_0210_guess;
    int value_0214_guess;

    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void slot48_guess(int, int);

    int GetCombatPageButton_guess(int index);
    void ShowPage_guess(int type);
    void UpdateButtonLabels_guess();
    int GetMainPageButton_guess(int index);
    // EXTERNAL: TITANIUM 0x005A1E10 CActionsWnd_guess::GetChildItem
    int GetChildItem(TempValue_guess* name);
    void loadControls_guess();
    int GetCurrentPage_guess();
    void init_guess();
    void setup_guess();
    int AbilitiesPageDeactivate_guess();
    int CombatPageDeactivate_guess();
    int RedirectActivateTo_guess(int value);
    int RefreshPage_guess(int value);
    int SocialsPageWndNotification_guess(int key, int code, int extra);
    int RedirectDeactivateTo_guess(int value);
    bool OnHide_guess();
    int WndNotification_guess(int key, int flag, EventMsg_guess* msg);
    // EXTERNAL: TITANIUM 0x005A2230 CActionsWnd_guess::WndNotification
    int WndNotification(int key, int flag, EventMsg_guess* msg);
    int SocialsPageOnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x004D362C CActionsWnd_guess::MainPageWndNotification_guess
    int MainPageWndNotification_guess(int a, int b, int c);
    int AbilitiesPageWndNotification_guess(int a, int b, int c);
    int CombatPageWndNotification_guess(int a, int b, int c);
    int dispatchEvent_guess(int key, int a, int b, int c);
    int MainPageOnProcessFrame_guess();
    int AbilitiesPageOnProcessFrame_guess();
    int CombatPageOnProcessFrame_guess();
    void UpdateKeyCombos_guess();
    bool AboutToShow_guess();
};

struct TempValue_guess {
    int value_0000_guess;
    // EXTERNAL: TITANIUM 0x00571E00 TempValue_guess::TempValue_guess
    TempValue_guess(const char* value);
    // EXTERNAL: TITANIUM 0x005724C0 ??0TempValue_guess@@QAE@HHH@Z
    TempValue_guess(int value, int radix, int width);
    // EXTERNAL: TITANIUM 0x00571D00 TempValue_guess::release_guess
    void release_guess(int value);
    ~TempValue_guess() {
        if (value_0000_guess != 0) {
            release_guess(value_0000_guess);
        }
        value_0000_guess = 0;
    }
};

struct ValueTarget_guess {
    char pad_0004_007b_guess[0x78];
    int value_007c_guess;
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void slot48_guess();
    virtual void slot49_guess();
    virtual void slot50_guess();
    virtual void slot51_guess();
    virtual void slot52_guess();
    virtual void slot53_guess();
    virtual void slot54_guess();
    virtual void slot55_guess();
    virtual void slot56_guess();
    virtual void slot57_guess();
    virtual void slot58_guess();
    virtual void slot59_guess();
    virtual void slot60_guess();
    virtual void slot61_guess();
    virtual void slot62_guess();
    virtual void setValue_guess(TempValue_guess* value);
};

// The same vtable as ValueTarget_guess, with slot 63 taking the text by reference.
struct TextTarget_guess {
    virtual void slot00_guess();
    virtual void slot01_guess();
    virtual void slot02_guess();
    virtual void slot03_guess();
    virtual void slot04_guess();
    virtual void slot05_guess();
    virtual void slot06_guess();
    virtual void slot07_guess();
    virtual void slot08_guess();
    virtual void slot09_guess();
    virtual void slot10_guess();
    virtual void slot11_guess();
    virtual void slot12_guess();
    virtual void slot13_guess();
    virtual void slot14_guess();
    virtual void slot15_guess();
    virtual void slot16_guess();
    virtual void slot17_guess();
    virtual void slot18_guess();
    virtual void slot19_guess();
    virtual void slot20_guess();
    virtual void slot21_guess();
    virtual void slot22_guess();
    virtual void slot23_guess();
    virtual void slot24_guess();
    virtual void slot25_guess();
    virtual void slot26_guess();
    virtual void slot27_guess();
    virtual void slot28_guess();
    virtual void slot29_guess();
    virtual void slot30_guess();
    virtual void slot31_guess();
    virtual void slot32_guess();
    virtual void slot33_guess();
    virtual void slot34_guess();
    virtual void slot35_guess();
    virtual void slot36_guess();
    virtual void slot37_guess();
    virtual void slot38_guess();
    virtual void slot39_guess();
    virtual void slot40_guess();
    virtual void slot41_guess();
    virtual void slot42_guess();
    virtual void slot43_guess();
    virtual void slot44_guess();
    virtual void slot45_guess();
    virtual void slot46_guess();
    virtual void slot47_guess();
    virtual void slot48_guess();
    virtual void slot49_guess();
    virtual void slot50_guess();
    virtual void slot51_guess();
    virtual void slot52_guess();
    virtual void slot53_guess();
    virtual void slot54_guess();
    virtual void slot55_guess();
    virtual void slot56_guess();
    virtual void slot57_guess();
    virtual void slot58_guess();
    virtual void slot59_guess();
    virtual void slot60_guess();
    virtual void slot61_guess();
    virtual void slot62_guess();
    virtual void setText_guess(const TempValue_guess& text);
};

struct ActionStore_guess {
    // EXTERNAL: TITANIUM 0x004FD36C ActionStore_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int flag);
    // EXTERNAL: TITANIUM 0x004FD91E ActionStore_guess::Put_guess
    void Put_guess(int a, int b, int index, char* text);
};

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492874 EverQuestText_guess::getText_guess
    char* getText_guess(int key);
    // EXTERNAL: TITANIUM 0x0049C800 EverQuestText_guess::Who_guess
    void Who_guess(char* text);
    // EXTERNAL: TITANIUM 0x0049D3CC EverQuestText_guess::Invite_guess
    void Invite_guess(int value);
    // EXTERNAL: TITANIUM 0x0049D7B6 EverQuestText_guess::AcceptGroupInvite_guess
    void AcceptGroupInvite_guess();
    // EXTERNAL: TITANIUM 0x0049D8BD EverQuestText_guess::Disband_guess
    void Disband_guess();
    // EXTERNAL: TITANIUM 0x0049DDA6 EverQuestText_guess::PrepareToCamp_guess
    void PrepareToCamp_guess();
    // EXTERNAL: TITANIUM 0x0049DCFA EverQuestText_guess::ToggleSit_guess
    void ToggleSit_guess();
};

#define g_valueOffset_guess EQ_GLOBAL(signed char, 0x009839DD)
#define g_valueData_guess EQ_ARRAY(char, 0x0095D4D4)
#define g_modeData_guess EQ_ARRAY(char, 0x0095D9E4)
#define pinstCCursorAttachment_guess EQ_GLOBAL(ActionStore_guess*, 0x00850C24)
#define g_selectedIndex_guess EQ_GLOBAL(int, 0x00694D8C)
#define g_everQuestText_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)
// Skill table: 100 skill records; the first dword is the eqstr id of the skill name.
struct SkillRecord_guess {
    int nameStringId_0000_guess;
    char pad_0004_0009_guess[6];
    char type_000a_guess;
};
#define g_skillTable_guess EQ_ARRAY(SkillRecord_guess*, 0x00851200)
// Skill ids on the six ability buttons and the four combat buttons (-1 = empty, >100 = command).
#define g_abilityButtonSkills_guess EQ_ARRAY(int, 0x0095D424)
// The four combat-button skill ids are +0x1BC of the block at 0x95D258; 0x004D3C53 addresses them that way.
struct SkillButtonBlock_guess {
    char pad_0000_01bb_guess[0x1bc];
    int combatButtonSkills_01bc_guess[4];
};
#define g_combatButtonSkills_guess (EQ_GLOBAL(SkillButtonBlock_guess, 0x0095D258).combatButtonSkills_01bc_guess)
#define g_pageFlag_guess EQ_GLOBAL(char, 0x00923798)
#define g_commandText_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void ExecuteCmd(int a, int b, int c);

// Main page clicks. Invite/Follow, Sit/Stand, Run/Walk and Find/EndFind are pairs that share a spot;
// only the one shown applies. Follow accepts a pending group invite; Run sets run mode (0x9237B4 = 1).
// Notification 0x17 (probably a drag start) hands the button to 0x850C24 as an action of type 5, index =
// the command (0 who ... 5 run/walk, 12 find).
// FUNCTION: TITANIUM 0x004D362C
int CActionsWnd_guess::MainPageWndNotification_guess(int a, int b, int c) {
    int result = 0;
    if (b == 1) {
        if (a == whoButton_0164_guess) {
            if (g_pageFlag_guess == 0) {
                g_everQuestText_guess->Who_guess(g_commandText_guess);
            }
        }
        else if (a == inviteButton_0170_guess) {
            if (!g_flagOwner_guess->IsGroupInvitePending_guess()) {
                g_everQuestText_guess->Invite_guess(0);
            }
        }
        else if (a == followButton_0174_guess) {
            if (g_flagOwner_guess->IsGroupInvitePending_guess()) {
                g_everQuestText_guess->AcceptGroupInvite_guess();
            }
        }
        else if (a == disbandButton_0178_guess) {
            g_everQuestText_guess->Disband_guess();
        }
        else if (a == campButton_017c_guess) {
            g_everQuestText_guess->PrepareToCamp_guess();
        }
        else if (a == sitButton_0180_guess) {
            if (g_flagOwner_guess->standState_0251_guess != 'n') {
                g_everQuestText_guess->ToggleSit_guess();
            }
        }
        else if (a == standButton_0184_guess) {
            if (g_flagOwner_guess->standState_0251_guess == 'n') {
                g_everQuestText_guess->ToggleSit_guess();
            }
        }
        else if (a == runButton_0188_guess) {
            g_runMode_guess = 1;
        }
        else if (a == walkButton_018c_guess) {
            g_runMode_guess = 0;
        }
        else if (a == findButton_0168_guess || a == endFindButton_016c_guess) {
            ExecuteCmd(0xc9, 1, 0);
        }
        else {
            result = -1;
        }
    }
    else if (b == 0x17) {
        int mode = 5;
        if (pinstCCursorAttachment_guess->IsOkToActivate_guess(mode)) {
            if (a == whoButton_0164_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 0, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == inviteButton_0170_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 1, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == followButton_0174_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 1, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == disbandButton_0178_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 2, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == campButton_017c_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 3, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == sitButton_0180_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 4, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == standButton_0184_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 4, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == runButton_0188_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 5, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == walkButton_018c_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 5, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == findButton_0168_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 0xc, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else if (a == endFindButton_016c_guess) {
                pinstCCursorAttachment_guess->Put_guess(0, mode, 0xc, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            else {
                result = -1;
            }
        }
        else {
            result = -1;
        }
    }
    else {
        result = -1;
    }
    return result;
}

// Shows page `type` (1 Abilities, 2 Combat, 3 Socials, else Main) and activates the window.
// FUNCTION: TITANIUM 0x004D22F2
void CActionsWnd_guess::ShowPage_guess(int type) {
    ValueSource_guess* source = actionsSubwindows_015c_guess;
    if (source != 0) {
        int value;
        switch (type) {
        case 1:
            value = actionsAbilitiesPage_0190_guess;
            break;
        case 2:
            value = actionsCombatPage_01b0_guess;
            break;
        case 3:
            value = actionsSocialsPage_01d0_guess;
            break;
        default:
            value = actionsMainPage_0160_guess;
            break;
        }
        source->setValue_guess(value, 1);
    }
    slot48_guess(1, 1);
}

// Labels the buttons: the six ability and four combat-skill buttons get their skill's name (ids over 100
// are innate abilities, of which only 5, 7, 11, 14 and 15 have a name), the 12 social buttons the
// current page's social names (0x511-byte records at 0x95D4D4) and colours.
// FUNCTION: TITANIUM 0x004D2344
// @early-stop: budget, diff ndiff=88
void CActionsWnd_guess::UpdateButtonLabels_guess() {
    int i;
    int* keys = g_abilityButtonSkills_guess;
    int* slot = values_0194_guess;
    int remaining = 6;
    do {
        int key = *keys;
        if (key != -1) {
            if (key <= 100) {
                if (*slot != 0) {
                    CXStr value(pStringTable->getString(g_skillTable_guess[key]->nameStringId_0000_guess, 0));
                    ((ValueTarget_guess*)*slot)->setValue_guess((TempValue_guess*)&value);
                }
            }
            else {
                key -= 100;
                if ((key == 5 || key == 7 || key == 11 || (key > 13 && key < 16)) && *slot != 0) {
                    CXStr value(g_everQuestText_guess->getText_guess(key));
                    ((ValueTarget_guess*)*slot)->setValue_guess((TempValue_guess*)&value);
                }
            }
        }
        slot++;
        keys++;
    } while (--remaining != 0);
    keys = g_combatButtonSkills_guess;
    slot = &values_01b4_guess[2];
    remaining = 4;
    do {
        int key = *keys;
        if (key != -1) {
            if (key <= 100) {
                if (*slot != 0) {
                    CXStr value(pStringTable->getString(g_skillTable_guess[key]->nameStringId_0000_guess, 0));
                    ((ValueTarget_guess*)*slot)->setValue_guess((TempValue_guess*)&value);
                }
            }
            else {
                key -= 100;
                if ((key == 5 || key == 7 || key == 11 || (key > 13 && key < 16)) && *slot != 0) {
                    CXStr value(g_everQuestText_guess->getText_guess(key));
                    ((ValueTarget_guess*)*slot)->setValue_guess((TempValue_guess*)&value);
                }
            }
        }
        slot++;
        keys++;
    } while (--remaining != 0);
    for (i = 0; i < 12; i++) {
        if (values_01e0_guess[i] != 0) {
            {
                int tableIndex = i + g_valueOffset_guess * 12;
                CXStr value(g_valueData_guess + tableIndex * 0x511);
                ((ValueTarget_guess*)values_01e0_guess[i])->setValue_guess((TempValue_guess*)&value);
            }
            if (pinstCSocialEditWnd_guess != 0) {
                ((ValueTarget_guess*)values_01e0_guess[i])->value_007c_guess = pinstCSocialEditWnd_guess->GetColor_guess((signed char)g_modeData_guess[(i + g_valueOffset_guess * 12) * 0x511]);
            }
        }
    }
}

// The page shown: 0 Main, 1 Abilities, 2 Combat, 3 Socials.
// FUNCTION: TITANIUM 0x004D25E1
int CActionsWnd_guess::GetCurrentPage_guess() {
    int result = 0;
    int value = 0;
    if (actionsSubwindows_015c_guess != 0) {
        value = actionsSubwindows_015c_guess->getValue_guess();
    }
    if (value == actionsMainPage_0160_guess) {
        result = 0;
    }
    else if (value == actionsAbilitiesPage_0190_guess) {
        result = 1;
    }
    else if (value == actionsCombatPage_01b0_guess) {
        result = 2;
    }
    else if (value == actionsSocialsPage_01d0_guess) {
        result = 3;
    }
    return result;
}

// Gives each button the key combo bound to its keyboard command (key manager 0x98599C): 0x82-0x85 the
// four pages, 0x86-0x8B who to run/walk (a pair shares one command), 0xC9 find, 10 melee attack.
// FUNCTION: TITANIUM 0x004D262D
// @early-stop: budget, diff ndiff=60
void CActionsWnd_guess::UpdateKeyCombos_guess() {
    if (actionsMainPage_0160_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x85;
        service = g_textService_guess;
        ((ValueSink_guess*)actionsMainPage_0160_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (actionsAbilitiesPage_0190_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x82;
        service = g_textService_guess;
        ((ValueSink_guess*)actionsAbilitiesPage_0190_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (actionsCombatPage_01b0_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x83;
        service = g_textService_guess;
        ((ValueSink_guess*)actionsCombatPage_01b0_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (actionsSocialsPage_01d0_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x84;
        service = g_textService_guess;
        ((ValueSink_guess*)actionsSocialsPage_01d0_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (whoButton_0164_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x86;
        service = g_textService_guess;
        ((ValueSink_guess*)whoButton_0164_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (inviteButton_0170_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x87;
        service = g_textService_guess;
        ((ValueSink_guess*)inviteButton_0170_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (followButton_0174_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x87;
        service = g_textService_guess;
        ((ValueSink_guess*)followButton_0174_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (disbandButton_0178_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x88;
        service = g_textService_guess;
        ((ValueSink_guess*)disbandButton_0178_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (campButton_017c_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x89;
        service = g_textService_guess;
        ((ValueSink_guess*)campButton_017c_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (sitButton_0180_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x8a;
        service = g_textService_guess;
        ((ValueSink_guess*)sitButton_0180_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (standButton_0184_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x8a;
        service = g_textService_guess;
        ((ValueSink_guess*)standButton_0184_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (runButton_0188_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x8b;
        service = g_textService_guess;
        ((ValueSink_guess*)runButton_0188_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (walkButton_018c_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0x8b;
        service = g_textService_guess;
        ((ValueSink_guess*)walkButton_018c_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (findButton_0168_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0xc9;
        service = g_textService_guess;
        ((ValueSink_guess*)findButton_0168_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (endFindButton_016c_guess != 0) {
        TextService_guess* service;
        int id;
        id = 0xc9;
        service = g_textService_guess;
        ((ValueSink_guess*)endFindButton_016c_guess)->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
    if (values_01b4_guess[0] != 0) {
        TextService_guess* service;
        int id;
        id = 10;
        service = g_textService_guess;
        ((ValueSink_guess*)values_01b4_guess[0])->set_guess(
            service->second_guess(id,
                service->first_guess(id)->toFlags_guess())->toFlags_guess());
    }
}

// Combat page button `index` (0 melee, 1 range, 2-5 skills); tu_168 calls it.
// FUNCTION: TITANIUM 0x004D2A03
int CActionsWnd_guess::GetCombatPageButton_guess(int index) {
    return values_01b4_guess[index];
}

// The main-page button now shown for command `index` (0 who, 1 invite/follow, 2 disband, 3 camp,
// 4 sit/stand, 5 run/walk, 12 find); 0 for others. tu_168 calls it.
// FUNCTION: TITANIUM 0x004D2A11
int CActionsWnd_guess::GetMainPageButton_guess(int index) {
    int result = 0;
    switch (index) {
    case 0:
        result = whoButton_0164_guess;
        break;
    case 1:
        if (g_flagOwner_guess->IsGroupInvitePending_guess()) {
            result = followButton_0174_guess;
        }
        else {
            result = inviteButton_0170_guess;
        }
        break;
    case 2:
        result = disbandButton_0178_guess;
        break;
    case 3:
        result = campButton_017c_guess;
        break;
    case 4:
        if (g_flagOwner_guess->standState_0251_guess == 'n') {
            result = standButton_0184_guess;
        }
        else {
            result = sitButton_0180_guess;
        }
        break;
    case 5:
        if (g_runMode_guess == 1) {
            result = walkButton_018c_guess;
        }
        else {
            result = runButton_0188_guess;
        }
        break;
    case 12:
        if (pinstCFindLocationWnd_guess != 0 && pinstCFindLocationWnd_guess->getByte_guess()) {
            result = endFindButton_016c_guess;
        }
        else {
            result = findButton_0168_guess;
        }
        break;
    }
    return result;
}

// Clears every control pointer before the children are looked up.
// FUNCTION: TITANIUM 0x004D2ACD
void CActionsWnd_guess::init_guess() {
    actionsSubwindows_015c_guess = 0;
    actionsMainPage_0160_guess = 0;
    whoButton_0164_guess = 0;
    inviteButton_0170_guess = 0;
    followButton_0174_guess = 0;
    disbandButton_0178_guess = 0;
    campButton_017c_guess = 0;
    sitButton_0180_guess = 0;
    standButton_0184_guess = 0;
    runButton_0188_guess = 0;
    walkButton_018c_guess = 0;
    findButton_0168_guess = 0;
    endFindButton_016c_guess = 0;
    actionsAbilitiesPage_0190_guess = 0;
    for (int i = 0; i < 6; i++) {
        values_0194_guess[i] = 0;
    }
    actionsCombatPage_01b0_guess = 0;
    for (int i = 0; i < 6; i++) {
        values_01b4_guess[i] = 0;
    }
    actionsSocialsPage_01d0_guess = 0;
    socialPageRightButton_01d4_guess = 0;
    socialPageLeftButton_01d8_guess = 0;
    currentSocialPageLabel_01dc_guess = 0;
    for (int i = 0; i < 12; i++) {
        values_01e0_guess[i] = 0;
    }
}

// CActionsWnd: binds the child controls of its four pages (main, abilities, combat, socials) by SIDL name;
// the 12 social buttons are ASP_SocialButton1-12.
// FUNCTION: TITANIUM 0x004D2B6B
void CActionsWnd_guess::loadControls_guess() {
    char name[256];
    {
        TempValue_guess childName("ACTW_ActionsSubwindows");
        actionsSubwindows_015c_guess = (ValueSource_guess*)GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ActionsMainPage");
        actionsMainPage_0160_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_WhoButton");
        whoButton_0164_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_InviteButton");
        inviteButton_0170_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_FollowButton");
        followButton_0174_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_DisbandButton");
        disbandButton_0178_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_CampButton");
        campButton_017c_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_SitButton");
        sitButton_0180_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_StandButton");
        standButton_0184_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_RunButton");
        runButton_0188_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_WalkButton");
        walkButton_018c_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_FindButton");
        findButton_0168_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AMP_EndFindButton");
        endFindButton_016c_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ActionsAbilitiesPage");
        actionsAbilitiesPage_0190_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_FirstAbilityButton");
        values_0194_guess[0] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_SecondAbilityButton");
        values_0194_guess[1] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_ThirdAbilityButton");
        values_0194_guess[2] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_FourthAbilityButton");
        values_0194_guess[3] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_FifthAbilityButton");
        values_0194_guess[4] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("AAP_SixthAbilityButton");
        values_0194_guess[5] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ActionsCombatPage");
        actionsCombatPage_01b0_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_MeleeAttackButton");
        values_01b4_guess[0] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_RangeAttackButton");
        values_01b4_guess[1] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_FirstAbilityButton");
        values_01b4_guess[2] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_SecondAbilityButton");
        values_01b4_guess[3] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_ThirdAbilityButton");
        values_01b4_guess[4] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ACP_FourthAbilityButton");
        values_01b4_guess[5] = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ActionsSocialsPage");
        actionsSocialsPage_01d0_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ASP_SocialPageRightButton");
        socialPageRightButton_01d4_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ASP_SocialPageLeftButton");
        socialPageLeftButton_01d8_guess = GetChildItem(&childName);
    }
    {
        TempValue_guess childName("ASP_CurrentSocialPageLabel");
        currentSocialPageLabel_01dc_guess = GetChildItem(&childName);
    }
    for (int index = 0; index < 12; ++index) {
        sprintf(name, "ASP_SocialButton%d", index + 1);
        {
            TempValue_guess childName(name);
            values_01e0_guess[index] = GetChildItem(&childName);
        }
    }
}

// Starts with Invite, Sit, Run and Find shown (their partners hidden), no picker open, and the melee and
// range buttons drawn with entries 13 and 11 of the table at 0x850CB8 in all four button states.
// FUNCTION: TITANIUM 0x004D34B8
void CActionsWnd_guess::setup_guess() {
    if (inviteButton_0170_guess != 0) {
        ((Control_guess*)inviteButton_0170_guess)->SetValue_guess(1, 1);
    }
    if (followButton_0174_guess != 0) {
        ((Control_guess*)followButton_0174_guess)->SetValue_guess(0, 1);
    }
    if (sitButton_0180_guess != 0) {
        ((Control_guess*)sitButton_0180_guess)->SetValue_guess(1, 1);
    }
    if (standButton_0184_guess != 0) {
        ((Control_guess*)standButton_0184_guess)->SetValue_guess(0, 1);
    }
    if (runButton_0188_guess != 0) {
        ((Control_guess*)runButton_0188_guess)->SetValue_guess(1, 1);
    }
    if (walkButton_018c_guess != 0) {
        ((Control_guess*)walkButton_018c_guess)->SetValue_guess(0, 1);
    }
    if (findButton_0168_guess != 0) {
        ((Control_guess*)findButton_0168_guess)->SetValue_guess(1, 1);
    }
    if (endFindButton_016c_guess != 0) {
        ((Control_guess*)endFindButton_016c_guess)->SetValue_guess(0, 1);
    }
    selectedAbilitySlot_01ac_guess |= -1;
    if (pinstCInvSlotMgr_guess != 0) {
        LookupEntry_guess* entry = pinstCInvSlotMgr_guess->FindInvSlot(0xd);
        if (values_01b4_guess[0] != 0) {
            int* value = &entry->value_0008_guess;
            ((ValueControl_guess*)values_01b4_guess[0])->value_016c_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[0])->value_0170_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[0])->value_017c_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[0])->value_0174_guess = *value;
        }
        entry = pinstCInvSlotMgr_guess->FindInvSlot(0xb);
        if (values_01b4_guess[1] != 0) {
            int* value = &entry->value_0008_guess;
            ((ValueControl_guess*)values_01b4_guess[1])->value_016c_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[1])->value_0170_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[1])->value_0174_guess = *value;
            ((ValueControl_guess*)values_01b4_guess[1])->value_017c_guess = *value;
        }
    }
    values_01b4_guess[6] |= -1;
    value_0210_guess |= -1;
    value_0214_guess = g_root_guess->frameTime_0148_guess;
}

// Abilities page shown: tip of the day 4.
// FUNCTION: TITANIUM 0x004D399A
int AbilitiesPageActivate_guess() {
    CTipWnd_guess* manager = pinstCTipWndCONTEXT_guess;
    if (manager != 0) {
        manager->selectTip_guess(4, 0);
    }
    return 0;
}

// Abilities page hidden: closes the skill picker and forgets the slot being filled.
// FUNCTION: TITANIUM 0x004D39B0
int CActionsWnd_guess::AbilitiesPageDeactivate_guess() {
    Callback_guess* callback = pinstCSkillsSelectWnd_guess;
    if (callback != 0) {
        callback->slot34_guess();
    }
    selectedAbilitySlot_01ac_guess |= -1;
    return 0;
}

// Combat page shown: tip of the day 3.
// FUNCTION: TITANIUM 0x004D3C1D
int CombatPageActivate_guess() {
    CTipWnd_guess* manager = pinstCTipWndCONTEXT_guess;
    if (manager != 0) {
        manager->selectTip_guess(3, 0);
    }
    return 0;
}

// Combat page hidden: closes the skill picker and forgets the slot being filled.
// FUNCTION: TITANIUM 0x004D3C33
int CActionsWnd_guess::CombatPageDeactivate_guess() {
    Callback_guess* callback = pinstCSkillsSelectWnd_guess;
    if (callback != 0) {
        callback->slot34_guess();
    }
    values_01b4_guess[6] |= -1;
    return 0;
}

struct ItemLimit_guess {
    char pad_0000_010b_guess[0x10c];
    unsigned value_010c_guess;
};

struct ItemLimitOwner_guess {
    char pad_0000_01a7_guess[0x1a8];
    ItemLimit_guess* limit_01a8_guess;
};

#define g_itemMode_guess EQ_GLOBAL(char, 0x00924670)
#define g_itemFallbackMode_guess EQ_GLOBAL(char, 0x009858C8)
#define g_skillAttackReady_guess EQ_GLOBAL(char, 0x00924672)
#define g_itemFlags_guess EQ_ARRAY(char, 0x0092460C)
#define g_itemLimitOwner_guess EQ_GLOBAL(ItemLimitOwner_guess*, 0x00905CE4)

// Combat page per frame: greys the buttons whose skill is not ready (apply_guess 1 = greyed, probably).
// Melee and range are usable while 0x924670 is set and 0x9858C8 clear. Skills below 100 use the ready
// flags at 0x92460C, or 0x924672 for skill type 2; innate 111 uses 0x924672; other innates compare the
// display time with the player's reuse time (+0x1A8, +0x10C).
// FUNCTION: TITANIUM 0x004D3C53
// @early-stop: budget, diff ndiff=9
int CActionsWnd_guess::CombatPageOnProcessFrame_guess() {
    int first = values_01b4_guess[0];
    if (first != 0 && values_01b4_guess[1] != 0) {
        if (g_itemMode_guess != 0 && g_itemFallbackMode_guess == 0) {
            reinterpret_cast<CButtonWnd*>(first)->SetCheck(0);
            reinterpret_cast<CButtonWnd*>(values_01b4_guess[1])->SetCheck(0);
        }
        else {
            reinterpret_cast<CButtonWnd*>(first)->SetCheck(1);
            reinterpret_cast<CButtonWnd*>(values_01b4_guess[1])->SetCheck(1);
        }
    }

    int* item = &values_01b4_guess[2];
    int* itemId = g_combatButtonSkills_guess;
    int count = 4;
    do {
        if (*item != 0) {
            int id = *itemId;
            if (id != -1) {
                if (id < 100) {
                    SkillRecord_guess* record = g_skillTable_guess[id];
                    if (record->type_000a_guess != 2) {
                        if (g_itemFlags_guess[id] != 0) {
                            reinterpret_cast<CButtonWnd*>(*item)->SetCheck(0);
                        }
                        else {
                            reinterpret_cast<CButtonWnd*>(*item)->SetCheck(1);
                        }
                    }
                    else if (g_skillAttackReady_guess != 0) {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(0);
                    }
                    else {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(1);
                    }
                }
                else if (id == 0x6f) {
                    if (g_skillAttackReady_guess != 0) {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(0);
                    }
                    else {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(1);
                    }
                }
                else if (id == 0x72 || id == 0x73) {
                    // item[-8] is the Abilities page's button for this slot,
                    // not this page's (original; see bugs).
                    reinterpret_cast<CButtonWnd*>(item[-8])->SetCheck(0);
                }
                else {
                    if (g_root_guess->frameTime_0148_guess >=
                        g_itemLimitOwner_guess->limit_01a8_guess->value_010c_guess) {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(0);
                    }
                    else {
                        reinterpret_cast<CButtonWnd*>(*item)->SetCheck(1);
                    }
                }
            }
        }
        ++item;
        ++itemId;
    } while (--count != 0);
    return 0;
}

struct CListWndView_guess {
    // EXTERNAL: TITANIUM 0x00597F10 CListWndView_guess::GetItemText
    TempValue_guess GetItemText(int index, int column);
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView_guess::GetItemData
    int GetItemData(int index);
};

struct Refresher_guess {
    // EXTERNAL: TITANIUM 0x004B0668 Refresher_guess::refresh_guess
    void refresh_guess();
    // EXTERNAL: TITANIUM 0x004B05D6 Refresher_guess::SaveAbilities_guess
    void SaveAbilities_guess();
};

struct Skills_guess {
    // EXTERNAL: TITANIUM 0x0041F4A0 Skills_guess::use_guess
    void use_guess(unsigned char skill, int target);
};

struct Game_guess {
    char pad_0000_c27f_guess[0xc280];
    Skills_guess skills_c280_guess;
};

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void ExecuteCmd(int a, int b, int c);

#define g_refresher_guess EQ_GLOBAL(Refresher_guess*, 0x00988DF0)
#define g_game_guess EQ_GLOBAL(Game_guess*, 0x00905D00)
#define g_target_guess EQ_GLOBAL(int, 0x00905D04)
#define g_pending_guess EQ_GLOBAL(char, 0x00924670)
#define g_slotData_guess EQ_ARRAY(int, 0x0095D40C)

// Abilities page per frame: the same ready test as the combat page, for the six ability buttons;
// innates 114 and 115 are always usable.
// FUNCTION: TITANIUM 0x004D39D0
// @early-stop: budget, diff ndiff=3
int CActionsWnd_guess::AbilitiesPageOnProcessFrame_guess() {
    int* slot = values_0194_guess;
    int* value = g_abilityButtonSkills_guess;
    int count = 6;
    do {
        if (*slot != 0 && *value != -1) {
            int current = *value;
            if (current < 100) {
                if (g_skillTable_guess[current]->type_000a_guess == 2) {
                    if (g_skillAttackReady_guess == 0) {
                        ((CButtonWnd*)*slot)->SetCheck(1);
                    }
                    else {
                        ((CButtonWnd*)*slot)->SetCheck(0);
                    }
                }
                else {
                    if (g_itemFlags_guess[current] == 0) {
                        ((CButtonWnd*)*slot)->SetCheck(1);
                    }
                    else {
                        ((CButtonWnd*)*slot)->SetCheck(0);
                    }
                }
            }
            else if (current == 0x6f) {
                if (g_skillAttackReady_guess == 0) {
                    ((CButtonWnd*)*slot)->SetCheck(1);
                }
                else {
                    ((CButtonWnd*)*slot)->SetCheck(0);
                }
            }
            else if (current == 0x72 || current == 0x73) {
                ((CButtonWnd*)*slot)->SetCheck(0);
            }
            else if (g_root_guess->frameTime_0148_guess <
                g_itemLimitOwner_guess->limit_01a8_guess->value_010c_guess) {
                ((CButtonWnd*)*slot)->SetCheck(1);
            }
            else {
                ((CButtonWnd*)*slot)->SetCheck(0);
            }
        }
        slot++;
        value++;
    } while (--count);
    return 0;
}

// Abilities page clicks. A pick in the skill picker fills the waiting slot (0x95D424) and saves it. Left
// click uses the slot's skill on the target, or opens the picker (mode 3) when the slot is empty; right
// click always opens it. 0x17 hands the skill to 0x850C24 as type 11.
// FUNCTION: TITANIUM 0x004D3A64
int CActionsWnd_guess::AbilitiesPageWndNotification_guess(int a, int b, int c) {
    int result = -1;
    if (pinstCSkillsSelectWnd_guess != 0) {
        CListWndView_guess* list = pinstCSkillsSelectWnd_guess->list_0164_guess;
        if (a == (int)list && b == 1) {
            if (selectedAbilitySlot_01ac_guess != -1) {
                if (values_0194_guess[selectedAbilitySlot_01ac_guess] != 0) {
                    ((TextTarget_guess*)values_0194_guess[selectedAbilitySlot_01ac_guess])->setText_guess(list->GetItemText(c, 0));
                }
                g_abilityButtonSkills_guess[selectedAbilitySlot_01ac_guess] = list->GetItemData(c);
                g_refresher_guess->SaveAbilities_guess();
            }
            pinstCSkillsSelectWnd_guess->slot34_guess();
            selectedAbilitySlot_01ac_guess = -1;
            result = 0;
        }
        else {
            for (int i = 0; i < 6; i++) {
                if (a == values_0194_guess[i]) {
                    if (b == 1) {
                        if (g_abilityButtonSkills_guess[i] == -1) {
                            pinstCSkillsSelectWnd_guess->FillList_guess(3);
                            pinstCSkillsSelectWnd_guess->owner_015c_guess = this;
                            pinstCSkillsSelectWnd_guess->slot33_guess();
                            selectedAbilitySlot_01ac_guess = i;
                        }
                        else {
                            g_game_guess->skills_c280_guess.use_guess((unsigned char)g_abilityButtonSkills_guess[i], g_target_guess);
                        }
                    }
                    else if (b == 3) {
                        pinstCSkillsSelectWnd_guess->FillList_guess(3);
                        pinstCSkillsSelectWnd_guess->owner_015c_guess = this;
                        pinstCSkillsSelectWnd_guess->slot33_guess();
                        selectedAbilitySlot_01ac_guess = i;
                    }
                    else if (b == 0x17 && pinstCCursorAttachment_guess->IsOkToActivate_guess(0xb)) {
                        pinstCCursorAttachment_guess->Put_guess(0, 0xb, g_abilityButtonSkills_guess[i],((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
                    }
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}

// Combat page clicks: melee toggles auto attack (command 10); range fires once when the range attack is
// ready (0x924670). Skill slots 2-5 (0x95D40C) work as on the Abilities page, picker mode 2. 0x17 hands
// melee/range out as type 7, skills as type 11.
// FUNCTION: TITANIUM 0x004D3D24
int CActionsWnd_guess::CombatPageWndNotification_guess(int a, int b, int c) {
    int result = -1;
    if (pinstCSkillsSelectWnd_guess != 0) {
        CListWndView_guess* list = pinstCSkillsSelectWnd_guess->list_0164_guess;
        if (a == (int)list && b == 1) {
            if (values_01b4_guess[6] != -1) {
                if (values_01b4_guess[values_01b4_guess[6]] != 0) {
                    ((TextTarget_guess*)values_01b4_guess[values_01b4_guess[6]])->setText_guess(list->GetItemText(c, 0));
                }
                g_slotData_guess[values_01b4_guess[6]] = list->GetItemData(c);
                g_refresher_guess->refresh_guess();
            }
            pinstCSkillsSelectWnd_guess->slot34_guess();
            values_01b4_guess[6] = -1;
            result = 0;
        }
        else if (a == values_01b4_guess[0]) {
            if (b == 1) {
                ExecuteCmd(10, 1, 0);
            }
            else if (b == 0x17 && pinstCCursorAttachment_guess->IsOkToActivate_guess(7)) {
                pinstCCursorAttachment_guess->Put_guess(0, 7, 0, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            result = 0;
        }
        else if (a == values_01b4_guess[1]) {
            if (b == 1) {
                if (g_pending_guess) {
                    g_pending_guess = 0;
                    g_flagOwner_guess->DoAttack(0xb, 0, g_target_guess);
                }
            }
            else if (b == 0x17 && pinstCCursorAttachment_guess->IsOkToActivate_guess(7)) {
                pinstCCursorAttachment_guess->Put_guess(0, 7, 1, ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
            }
            result = 0;
        }
        else {
            for (int i = 2; i < 6; i++) {
                if (a == values_01b4_guess[i]) {
                    if (b == 1) {
                        if (g_slotData_guess[i] == -1) {
                            pinstCSkillsSelectWnd_guess->FillList_guess(2);
                            pinstCSkillsSelectWnd_guess->owner_015c_guess = this;
                            pinstCSkillsSelectWnd_guess->slot33_guess();
                            values_01b4_guess[6] = i;
                        }
                        else {
                            g_game_guess->skills_c280_guess.use_guess((unsigned char)g_slotData_guess[i], g_target_guess);
                        }
                    }
                    else if (b == 3) {
                        pinstCSkillsSelectWnd_guess->FillList_guess(2);
                        pinstCSkillsSelectWnd_guess->owner_015c_guess = this;
                        pinstCSkillsSelectWnd_guess->slot33_guess();
                        values_01b4_guess[6] = i;
                    }
                    else if (b == 0x17 && pinstCCursorAttachment_guess->IsOkToActivate_guess(0xb)) {
                        pinstCCursorAttachment_guess->Put_guess(0, 0xb, g_slotData_guess[i], ((StringOwner_guess*)a)->get_guess().Chars_guess(-1));
                    }
                    result = 0;
                    break;
                }
            }
        }
    }
    return result;
}

// Socials page shown: tip of the day 5.
// FUNCTION: TITANIUM 0x004D3FF5
int SocialsPageActivate_guess() {
    CTipWnd_guess* manager = pinstCTipWndCONTEXT_guess;
    if (manager != 0) {
        manager->selectTip_guess(5, 0);
    }
    return 0;
}

// Socials page per frame: relabels and recolours the 12 buttons for the current page (0x9839DD, 0-9).
// Unlike UpdateButtonLabels_guess it does not null-check the social-edit window (0x850C6C).
// FUNCTION: TITANIUM 0x004D400B
int CActionsWnd_guess::SocialsPageOnProcessFrame_guess() {
    int index;
    ValueTarget_guess** current;
    index = 0;
    current = (ValueTarget_guess**)values_01e0_guess;
    do {
        if (*current != 0) {
            {
                int tableIndex = index + g_valueOffset_guess * 12;
                TempValue_guess value(g_valueData_guess + tableIndex * 0x511);
                (*current)->setValue_guess(&value);
            }
            int modeIndex = index + g_valueOffset_guess * 12;
            (*current)->value_007c_guess =
                pinstCSocialEditWnd_guess->GetColor_guess((signed char)g_modeData_guess[modeIndex * 0x511]);
        }
        ++index;
        ++current;
    } while (index < 12);
    return 0;
}

// Socials page clicks: the arrows cycle the 10 pages (label shows 1-10). Left click runs social
// page*12+i (0x694D8C gets index*8, probably the line cursor of the running social); right click opens
// it in the social editor; 0x17 hands it to 0x850C24 as type 4.
// FUNCTION: TITANIUM 0x004D40B9
int CActionsWnd_guess::SocialsPageWndNotification_guess(int key, int code, int extra) {
    int result = -1;
    if (key == socialPageRightButton_01d4_guess && code == 1) {
        g_valueOffset_guess++;
        if (g_valueOffset_guess >= 10) {
            g_valueOffset_guess = 0;
        }
        if (currentSocialPageLabel_01dc_guess != 0) {
            ((TextTarget_guess*)currentSocialPageLabel_01dc_guess)->setText_guess(TempValue_guess(g_valueOffset_guess + 1, 2, 0x20));
        }
        result = 0;
    }
    else if (key == socialPageLeftButton_01d8_guess && code == 1) {
        g_valueOffset_guess--;
        if (g_valueOffset_guess < 0) {
            g_valueOffset_guess = 9;
        }
        if (currentSocialPageLabel_01dc_guess != 0) {
            ((TextTarget_guess*)currentSocialPageLabel_01dc_guess)->setText_guess(TempValue_guess(g_valueOffset_guess + 1, 2, 0x20));
        }
        result = 0;
    }
    else {
        for (int i = 0; i < 12; i++) {
            if (key == values_01e0_guess[i]) {
                if (code == 1) {
                    g_selectedIndex_guess = (i + g_valueOffset_guess * 12) * 8;
                }
                else if (code == 3) {
                    if (pinstCSocialEditWnd_guess != 0) {
                        pinstCSocialEditWnd_guess->Run_guess(i + g_valueOffset_guess * 12);
                    }
                }
                else if (code == 0x17) {
                    if (pinstCCursorAttachment_guess->IsOkToActivate_guess(4)) {
                        pinstCCursorAttachment_guess->Put_guess(0, 4, i + g_valueOffset_guess * 12,
                                                 ((StringOwner_guess*)key)->get_guess().Chars_guess(-1));
                    }
                }
                result = 0;
            }
        }
    }
    return result;
}

// Passes a notification to the shown page's handler; -1 when none took it.
// FUNCTION: TITANIUM 0x004D4395
int CActionsWnd_guess::dispatchEvent_guess(int key, int a, int b, int c) {
    int result = -1;
    if (key == actionsMainPage_0160_guess) {
        result = MainPageWndNotification_guess(a, b, c);
    }
    else if (key == actionsAbilitiesPage_0190_guess) {
        result = AbilitiesPageWndNotification_guess(a, b, c);
    }
    else if (key == actionsCombatPage_01b0_guess) {
        result = CombatPageWndNotification_guess(a, b, c);
    }
    else if (key == actionsSocialsPage_01d0_guess) {
        result = SocialsPageWndNotification_guess(a, b, c);
    }
    return result;
}

// ini version 1, no ini block name; flag 0x800 is added to the screen piece's window style.
// FUNCTION: TITANIUM 0x004D4277
CActionsWnd_guess::CActionsWnd_guess(void* parent) : Base_guess(parent, "ActionsWindow", -1, 1, 0) {
    actionsSubwindows_015c_guess = 0;
    init_guess();
    if (piece_0124_guess != 0) {
        flags_0064_guess |= piece_0124_guess->flags_0060_guess | 0x800;
        flag_0018_guess = 0;
        CreateChildrenFromSidl();
        loadControls_guess();
        setup_guess();
    }
}

// Page activation: Abilities, Combat and Socials each show their tip of the day; Main has none.
// FUNCTION: TITANIUM 0x004D4318
int CActionsWnd_guess::RedirectActivateTo_guess(int value) {
    if (value == actionsMainPage_0160_guess) {
        return 0;
    }
    if (value == actionsAbilitiesPage_0190_guess) {
        AbilitiesPageActivate_guess();
    }
    else if (value == actionsCombatPage_01b0_guess) {
        CombatPageActivate_guess();
    }
    else if (value == actionsSocialsPage_01d0_guess) {
        SocialsPageActivate_guess();
    }
    else {
        return -1;
    }
    return 0;
}

// Page deactivation: Abilities and Combat close the skill picker; Main and Socials do nothing.
// FUNCTION: TITANIUM 0x004D4359
int CActionsWnd_guess::RedirectDeactivateTo_guess(int value) {
    if (value == actionsMainPage_0160_guess) {
        return 0;
    }
    if (value == actionsAbilitiesPage_0190_guess) {
        AbilitiesPageDeactivate_guess();
    }
    else if (value == actionsCombatPage_01b0_guess) {
        CombatPageDeactivate_guess();
    }
    else if (value == actionsSocialsPage_01d0_guess) {
    }
    else {
        return -1;
    }
    return 0;
}

// On show: the shown page's activation, then the key combos.
// FUNCTION: TITANIUM 0x004D467F
bool CActionsWnd_guess::AboutToShow_guess() {
    if (actionsSubwindows_015c_guess != 0) {
        RedirectActivateTo_guess(actionsSubwindows_015c_guess->getValue_guess());
    }
    UpdateKeyCombos_guess();
    return true;
}

struct ModeManager_guess {
    // EXTERNAL: TITANIUM 0x0042FCC2 ModeManager_guess::first_guess
    char first_guess();
    // EXTERNAL: TITANIUM 0x0042FCF9 ModeManager_guess::second_guess
    char second_guess();
};

struct IndexNode_guess {
    int pad_0000_guess;
    int value_0004_guess;
};

struct DataBlock_guess {
    char pad_0000_0007_guess[8];
    IndexNode_guess* node_0008_guess;
    char pad_000c_0043_guess[0x38];
    char bytes_0044_guess[0x200];
};

struct StateOwner_guess {
    char pad_0000_0243_guess[0x244];
    char field_0244_guess;
};

#define g_modeManager_guess EQ_ARRAY(ModeManager_guess, 0x0091D708)
#define g_flagText_guess EQ_GLOBAL(char*, 0x00985C88)
#define g_stateOwner_guess EQ_GLOBAL(StateOwner_guess*, 0x00905D04)
#define g_dataBlock_guess EQ_GLOBAL(DataBlock_guess*, 0x00905D00)
#define g_globalFlag_guess EQ_GLOBAL(char, 0x009043A4)
#define g_stateRecords_guess EQ_ARRAY(char, 0x0090424D)
#define g_stateRecordsEnd_guess EQ_ARRAY(char, 0x0090438D)

// EXTERNAL: TITANIUM 0x00574460 compare_guess
int __cdecl compare_guess(const char* left, const char* right);

// Main page per frame. Shows Follow instead of Invite while a group invite is pending, Stand while
// sitting (stand state 'n' = 110), Walk while running, EndFind while finding (0x985C88 non-empty).
// Disband is enabled when grouped or invited, except while 0x42FCC2 and IsLocked_guess are both set.
// Invite is enabled for a player target (+0x244 == 0) that is not you, when you are not grouped, or lead
// a group (0x9043A4 = leader name) with a free member row (5 rows of 0x40 at 0x90424D).
// FUNCTION: TITANIUM 0x004D4400
// @early-stop: tiebreak, structural ndiff=103
int CActionsWnd_guess::MainPageOnProcessFrame_guess() {
    bool flag;
    if (followButton_0174_guess != 0 && inviteButton_0170_guess != 0) {
        if (g_flagOwner_guess->IsGroupInvitePending_guess() &&
            ((Control_guess*)followButton_0174_guess)->field_005c_guess == 0) {
            ((Control_guess*)followButton_0174_guess)->SetValue_guess(true, 1);
            ((Control_guess*)inviteButton_0170_guess)->SetValue_guess(false, 1);
        }
        else if (!g_flagOwner_guess->IsGroupInvitePending_guess() &&
                 ((Control_guess*)inviteButton_0170_guess)->field_005c_guess == 0) {
            ((Control_guess*)inviteButton_0170_guess)->SetValue_guess(true, 1);
            ((Control_guess*)followButton_0174_guess)->SetValue_guess(false, 1);
        }
    }
    if (sitButton_0180_guess != 0 && standButton_0184_guess != 0) {
        if (g_flagOwner_guess->standState_0251_guess == 'n' &&
            ((Control_guess*)standButton_0184_guess)->field_005c_guess == 0) {
            ((Control_guess*)standButton_0184_guess)->SetValue_guess(true, 1);
            ((Control_guess*)sitButton_0180_guess)->SetValue_guess(false, 1);
        }
        else if (g_flagOwner_guess->standState_0251_guess != 'n' &&
                 ((Control_guess*)sitButton_0180_guess)->field_005c_guess == 0) {
            ((Control_guess*)sitButton_0180_guess)->SetValue_guess(true, 1);
            ((Control_guess*)standButton_0184_guess)->SetValue_guess(false, 1);
        }
    }
    if (walkButton_018c_guess != 0 && runButton_0188_guess != 0) {
        if (g_runMode_guess == 1) {
            Control_guess* control = (Control_guess*)walkButton_018c_guess;
            if (control->field_005c_guess == 0) {
                control->SetValue_guess(true, 1);
                ((Control_guess*)runButton_0188_guess)->SetValue_guess(false, 1);
            }
        }
        else if (g_runMode_guess == 0) {
            Control_guess* control = (Control_guess*)runButton_0188_guess;
            if (control->field_005c_guess == 0) {
                control->SetValue_guess(true, 1);
                ((Control_guess*)walkButton_018c_guess)->SetValue_guess(false, 1);
            }
        }
    }
    if (findButton_0168_guess != 0 && endFindButton_016c_guess != 0) {
        if (g_flagText_guess != 0) {
            flag = 1;
            if (*g_flagText_guess == 0) {
                flag = 0;
            }
        }
        else {
            flag = 0;
        }
        ((Control_guess*)findButton_0168_guess)->SetValue_guess(flag == 0, 1);
        ((Control_guess*)endFindButton_016c_guess)->SetValue_guess(flag, 1);
    }
    if (disbandButton_0178_guess != 0) {
        Control_guess* control = (Control_guess*)disbandButton_0178_guess;
        if (g_modeManager_guess->first_guess() && g_modeManager_guess->second_guess()) {
            control->enabled_005d_guess = 0;
        }
        else if (g_globalFlag_guess != 0 || g_flagOwner_guess->IsGroupInvitePending_guess()) {
            control->enabled_005d_guess = 1;
        }
        else {
            control->enabled_005d_guess = 0;
        }
    }
    if (inviteButton_0170_guess != 0) {
        Control_guess* control = (Control_guess*)inviteButton_0170_guess;
        control->enabled_005d_guess = 0;
        if ((!g_modeManager_guess->first_guess() || !g_modeManager_guess->second_guess()) &&
            g_stateOwner_guess != 0 && g_stateOwner_guess->field_0244_guess == 0 &&
            (void*)g_stateOwner_guess != (void*)g_flagOwner_guess) {
            if (g_globalFlag_guess == 0) {
                control->enabled_005d_guess = 1;
            }
            else if (compare_guess(&g_globalFlag_guess,
                                  &g_dataBlock_guess->bytes_0044_guess[
                                      g_dataBlock_guess->node_0008_guess->value_0004_guess]) == 0) {
                char* row = g_stateRecords_guess;
                while (row < g_stateRecordsEnd_guess) {
                    if (*row == 0) {
                        control->enabled_005d_guess = 1;
                        break;
                    }
                    row += 0x40;
                }
            }
        }
    }
    return 0;
}

// On hide: the shown page's deactivation, then the skill picker closes.
// FUNCTION: TITANIUM 0x004D46A4
bool CActionsWnd_guess::OnHide_guess() {
    ValueSource_guess* source = actionsSubwindows_015c_guess;
    if (source != 0) {
        RedirectDeactivateTo_guess(source->getValue_guess());
    }
    Callback_guess* callback = pinstCSkillsSelectWnd_guess;
    if (callback != 0) {
        callback->slot34_guess();
    }
    return true;
}

// WndNotification: a tab change (1 from the tab box) deactivates the old page (msg +0xC) and activates
// the new one (+8); anything else goes to the shown page, then the CSidlScreenWnd default.
// FUNCTION: TITANIUM 0x004D46D4
int CActionsWnd_guess::WndNotification_guess(int key, int flag, EventMsg_guess* msg) {
    if (key == (int)actionsSubwindows_015c_guess && flag == 1) {
        RedirectDeactivateTo_guess(msg->value_000c_guess);
        RedirectActivateTo_guess(msg->value_0008_guess);
        return 0;
    }
    if (actionsSubwindows_015c_guess != 0) {
        int r = dispatchEvent_guess(actionsSubwindows_015c_guess->getValue_guess(), key, flag, (int)msg);
        if (r >= 0) {
            return r;
        }
    }
    return WndNotification(key, flag, msg);
}

// Per frame: runs the shown page's update.
// FUNCTION: TITANIUM 0x004D473B
int CActionsWnd_guess::RefreshPage_guess(int pageWindow) {
    if (pageWindow == actionsMainPage_0160_guess) {
        MainPageOnProcessFrame_guess();
    }
    else if (pageWindow == actionsAbilitiesPage_0190_guess) {
        AbilitiesPageOnProcessFrame_guess();
    }
    else if (pageWindow == actionsCombatPage_01b0_guess) {
        CombatPageOnProcessFrame_guess();
    }
    else if (pageWindow == actionsSocialsPage_01d0_guess) {
        SocialsPageOnProcessFrame_guess();
    }
    else {
        return -1;
    }
    return 0;
}

