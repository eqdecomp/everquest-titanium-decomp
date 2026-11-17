// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 164: a hint from compare/tumap.py.
// CGroupWnd, the group window ("GroupWindow" screen; Invite, Disband, Follow, Decline and LFG buttons, five
// members' pet gauges and HP labels, a "Petbars" context menu), plus the tail of tu_163's group search
// window. CGroupWndView_guess and GroupWindow_guess are two views of the same object.
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* operator new(unsigned int size);

struct Rect_guess {
    int left, top, right, bottom;
    Rect_guess(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

// 0x1A8 bytes. Ctor 0x005BFAE0 returns this.
struct CContextMenuView_guess {
    // EXTERNAL: TITANIUM 0x005BFAE0 CContextMenuView_guess::CContextMenuView_guess
    CContextMenuView_guess(int x, int y, const Rect_guess& rect);
    // EXTERNAL: TITANIUM 0x005BFCF0 CContextMenuView_guess::Named_guess
    int Named_guess(const CXStr& text, unsigned int key, int a, int b);
    // EXTERNAL: TITANIUM 0x005BFE60 CContextMenuView_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x005BFF70 CContextMenuView_guess::Send_guess
    void Send_guess(int value, unsigned char mode, int reserved);
    char pad_0000[0x1A8];
};

struct Event_guess {
    char pad_0000[0x28];
    int type; // 0x28
};

struct GlobalObject_guess {
    // EXTERNAL: TITANIUM 0x0049D7B6 GlobalObject_guess::AcceptGroupInvite_guess
    void AcceptGroupInvite_guess();
    // EXTERNAL: TITANIUM 0x0049D3CC GlobalObject_guess::Invite_guess
    void Invite_guess(int value);
    // EXTERNAL: TITANIUM 0x0049D8BD GlobalObject_guess::Disband_guess
    void Disband_guess();
};

struct Dispatcher_guess {
    char pad_0000[0x160];
    int dispatch160; // 0x160
    char pad_0164[0x20];
    int dispatch184; // 0x184
    char pad_0188[0xac];
    int dispatch234; // 0x234
    char pad_0238[0x14];
    int dispatch24c; // 0x24c
    char pad_0250[0x60];
    // EXTERNAL: TITANIUM 0x0050B0DB Dispatcher_guess::HandlePlayerInfoPage_guess
    void HandlePlayerInfoPage_guess(Event_guess* event, int arg2, int arg3);
    // EXTERNAL: TITANIUM 0x0050B94D Dispatcher_guess::HandleGroupInfoPage_guess
    void HandleGroupInfoPage_guess(Event_guess* event, int arg2, int arg3);
    // EXTERNAL: TITANIUM 0x0050B175 Dispatcher_guess::Handle234_guess
    void Handle234_guess(Event_guess* event, int arg2, int arg3);
    // EXTERNAL: TITANIUM 0x0050BAAF Dispatcher_guess::Handle24c_guess
    void Handle24c_guess(Event_guess* event, int arg2, int arg3);
    // EXTERNAL: TITANIUM 0x005A2230 Dispatcher_guess::Fallback_guess
    void Fallback_guess(Event_guess* event, int arg2, int arg3);

    int Dispatch_guess(int type, Event_guess* event, int arg2, int arg3);
    void HandleEvent_guess(Event_guess* event, int arg2, int arg3);

};

struct TargetSlot_guess {
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
    virtual void UpdatePetBarsMenuItem_guess(bool visible, int mode); // 0xc0
    // EXTERNAL: TITANIUM 0x0059DD30 TargetSlot_guess::IsReady_guess
    bool IsReady_guess();
    // EXTERNAL: TITANIUM 0x00508A5A TargetSlot_guess::Handle_guess
    void Handle_guess(int value);
    // EXTERNAL: TITANIUM 0x0059DBF0 TargetSlot_guess::SetValues_guess
    void SetValues_guess(int first, int second);
    char pad_0004_005c_guess[0x59];
    bool field_5d_guess; // 0x5d
};

#include "titanium/layouts/ui.h"

struct TargetDisplay_guess {
    char pad_0000[0x16c];
    int id_16c_guess; // 0x16c
};

struct TargetRecord_guess {
    char pad_0000[0x16c];
    char pad_016c[0x3c];
    TargetDisplay_guess* display_1a8_guess; // 0x1a8
    char pad_01ac[0x98];
    unsigned char field_244_guess; // 0x244
};

#include "titanium/layouts/core.h"
#include "titanium/wnd/CContextMenuManager.h"
#include "titanium/wnd/CGroupSearchWnd.h"

struct DataOwner_guess {
    char pad_0000_guess[8];
    union {
        VBTable* index_0008_guess; // 0x8
        char recordBytes_guess[1]; // 0x8
    };
};

struct Ini_guess {
    char pad_000[0x10];
    int contextMenuId_0150_guess; // 0x150
    char pad_014[0x08];
    TargetSlot_guess* slot15c_guess; // 0x15c
    TargetSlot_guess* slot160_guess; // 0x160
    TargetSlot_guess* slot164_guess; // 0x164
    TargetSlot_guess* slot168_guess; // 0x168
    TargetSlot_guess* slot16c_guess; // 0x16c
    // EXTERNAL: TITANIUM 0x00572300 Ini_guess::GetSection_guess
    const char* GetSection_guess();
};

struct CGroupWndView_guess {
    char pad_0000[0x140];
    Ini_guess ini_140; // 0x140
    TargetSlot_guess* slots170_guess[5]; // 0x170
    TargetSlot_guess* slots184_guess[5]; // 0x184
    TargetSlot_guess* slots198_guess[5]; // 0x198
    char pad_01ac[4];
    CContextMenuView_guess* queue; // 0x1b0
    bool mode; // 0x1b4
    char pad_01b5[3];
    int value; // 0x1b8
    bool flag_1bc_guess; // 0x1bc

    void UpdatePetBarsMenuItem_guess();
    // EXTERNAL: TITANIUM 0x005A2660 CGroupWndView_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x005A1890 CGroupWndView_guess::Update_guess
    void Update_guess();

    void CreateContextMenu_guess();
    void LoadIniInfo_guess();
    void StoreIniInfo_guess();
    void UpdateButtons_guess();
    void UpdateButtonHotkeys_guess();
    bool AboutToShow_guess();

    int WndNotification_guess(TargetSlot_guess* pWnd, int message, int data);

    // EXTERNAL: TITANIUM 0x005A2230 CGroupWndView_guess::WndNotificationBase_guess
    int WndNotificationBase_guess(TargetSlot_guess* pWnd, int message, int data);

    void SetInvitePending_guess(bool value);
};

struct SidlPiece_guess {
    char pad_0000[0x60];
    unsigned int flags_0060_guess;
};

struct SidlScreenWndCtorBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlScreenWndCtorBase_guess@@UAE@XZ
    virtual ~SidlScreenWndCtorBase_guess();
    char pad_0004[0x14];
    unsigned char field_0018_guess;
    char pad_0019[0x4b];
    unsigned int windowStyle_0064_guess;
    char pad_0068[0xbc];
    void* sidlPiece_0124_guess;
    char pad_0128[0x34];

    // EXTERNAL: TITANIUM 0x005A3850 SidlScreenWndCtorBase_guess::SidlScreenWndCtorBase_guess
    SidlScreenWndCtorBase_guess(CXWnd* parent, CXStr* screen, int flags,
                                int iniVersion, char* blockName);
};

// EXTERNAL: TITANIUM 0x00655740 ??_7GroupWindow_guess@@6B@
struct GroupWindow_guess : SidlScreenWndCtorBase_guess {
    TargetSlot_guess* inviteButton_15c_guess;
    TargetSlot_guess* disbandButton_160_guess;
    TargetSlot_guess* followButton_164_guess;
    TargetSlot_guess* declineButton_168_guess;
    TargetSlot_guess* lfgButton_16c_guess;
    TargetSlot_guess* petGauge_170_guess[5];
    TargetSlot_guess* hpLabel_184_guess[5];
    TargetSlot_guess* hpPercent_198_guess[5];
    int field_1ac_guess;
    CContextMenuView_guess* queue_1b0_guess;
    bool mode_1b4_guess;
    char pad_01b5_guess[3];
    int value_1b8_guess;
    bool flag_1bc_guess;

    GroupWindow_guess(CXWnd* parent);
};

// EXTERNAL: TITANIUM 0x00574460 CompareData_guess
int __cdecl CompareData_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
int __cdecl FUN_00401b28_guess(int id);

struct Value_guess {
    // EXTERNAL: TITANIUM 0x005BA300 Value_guess::GetValue_guess
    int GetValue_guess();
};

struct ValueTable_guess {
    // EXTERNAL: TITANIUM 0x004B2459 ValueTable_guess::GetA_guess
    Value_guess* GetA_guess(int index);
    // EXTERNAL: TITANIUM 0x004B244F ValueTable_guess::GetB_guess
    Value_guess* GetB_guess(int index);
};

#define g_valueTable_guess EQ_GLOBAL(ValueTable_guess*, 0x0098599C)

#define g_groupMemberNames_guess EQ_ARRAY(MenuEntry_guess, 0x0090424D)
#define g_groupMemberSpawns_guess EQ_ARRAY(TargetRecord_guess*, 0x00904390)
#define g_groupLeaderName_guess EQ_ARRAY(char, 0x009043A4)
#define g_dataOwner_guess EQ_GLOBAL(DataOwner_guess*, 0x00905D00)
#define g_currentTarget_guess EQ_GLOBAL(TargetRecord_guess*, 0x00905D04)
#define g_defaultTarget_guess EQ_GLOBAL(TargetRecord_guess*, 0x00905CE4)
#define g_globalObject_guess EQ_GLOBAL(GlobalObject_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* section, const char* key,
                                const char* defaultValue, char* value,
                                int size, char useDefault);

// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key,
                                const char* value);

// Group search window: picks the page handler (tu_163) whose page matches the child's parent; -1 when
// none does. The four handlers compare the child itself against that page's controls.
// FUNCTION: TITANIUM 0x0050BBD9
int Dispatcher_guess::Dispatch_guess(int type, Event_guess* event, int arg2, int arg3) {
    if (type == dispatch160) {
        HandlePlayerInfoPage_guess(event, arg2, arg3);
    } else if (type == dispatch184) {
        HandleGroupInfoPage_guess(event, arg2, arg3);
    } else if (type == dispatch234) {
        Handle234_guess(event, arg2, arg3);
    } else if (type == dispatch24c) {
        Handle24c_guess(event, arg2, arg3);
    } else {
        return -1;
    }
    return 0;
}

// The group search window's WndNotification: page handlers first, then the CSidlScreenWnd base
// (0x5A2230).
// FUNCTION: TITANIUM 0x0050BC48
void Dispatcher_guess::HandleEvent_guess(Event_guess* event, int arg2, int arg3) {
    if (event != 0) {
        int type = event->type;
        if (Dispatch_guess(type, event, arg2, arg3) >= 0) {
            return;
        }
    }
    Fallback_guess(event, arg2, arg3);
}

// Shows the key bindings on the buttons: Follow and Invite get command 0x87's, Decline and Disband
// command 0x88's (the key manager 0x98599C; probably the invite/follow and disband commands).
// FUNCTION: TITANIUM 0x0050BC7E
void CGroupWndView_guess::UpdateButtonHotkeys_guess() {
    if (ini_140.slot164_guess != 0) {
        ValueTable_guess* table = g_valueTable_guess;
        ini_140.slot164_guess->SetValues_guess(
            table->GetB_guess(0x87)->GetValue_guess(),
            g_valueTable_guess->GetA_guess(0x87)->GetValue_guess());
    }
    if (ini_140.slot15c_guess != 0) {
        ValueTable_guess* table = g_valueTable_guess;
        ini_140.slot15c_guess->SetValues_guess(
            table->GetB_guess(0x87)->GetValue_guess(),
            g_valueTable_guess->GetA_guess(0x87)->GetValue_guess());
    }
    if (ini_140.slot168_guess != 0) {
        ValueTable_guess* table = g_valueTable_guess;
        ini_140.slot168_guess->SetValues_guess(
            table->GetB_guess(0x88)->GetValue_guess(),
            g_valueTable_guess->GetA_guess(0x88)->GetValue_guess());
    }
    if (ini_140.slot160_guess != 0) {
        ValueTable_guess* table = g_valueTable_guess;
        ini_140.slot160_guess->SetValues_guess(
            table->GetB_guess(0x88)->GetValue_guess(),
            g_valueTable_guess->GetA_guess(0x88)->GetValue_guess());
    }
}

// Ticks the "Pet Display" context-menu item to match the setting.
// FUNCTION: TITANIUM 0x0050BD79
void CGroupWndView_guess::UpdatePetBarsMenuItem_guess() {
    queue->Send_guess(value, mode, 0);
}

// Reads the window's Petbars setting from the UI ini (default: the current one); T, t or 1 is true.
// The LoadIniInfo partner of StoreIniInfo_guess.
// FUNCTION: TITANIUM 0x0050BD96
void CGroupWndView_guess::LoadIniInfo_guess() {
    char defaultValue[256];
    char value[256];
    if (NewUIINI() != 0) {
        const char* text = "true";
        if (mode == 0) {
            text = "false";
        }
        _sprintf_guess(defaultValue, "%s", text);
        LoadStringFromUIIniFile_guess(ini_140.GetSection_guess(), "Petbars", defaultValue,
                           value, 0x100, 1);
        mode = value[0] == 't' || value[0] == 'T' || value[0] == '1';
        Refresh_guess();
    }
}

// Writes the Petbars setting to the UI ini.
// FUNCTION: TITANIUM 0x0050BE47
void CGroupWndView_guess::StoreIniInfo_guess() {
    char value[256];
    if (NewUIINI() != 0) {
        const char* text = "true";
        if (mode == 0) {
            text = "false";
        }
        _sprintf_guess(value, "%s", text);
        FUN_0060bf20_guess(ini_140.GetSection_guess(), "Petbars", value);
        Update_guess();
    }
}

// Button and member-row state. 0x9043A4 is the group leader's name, 0x90424D the five member names
// (0x40 each), 0x904390 their spawns. Follow/Decline show while an invite is pending (+0x1BC),
// Invite/Disband otherwise. Invite is enabled for a player target other than you when there is room
// (no group, or you lead and a member slot is empty); LFG needs that same room and the window at
// 0x991A58. A pet gauge shows only with pet bars on and the member's pet (spawn +0x1A8, id +0x16C) found.
// Spawn +0x244 (Type) == 0 is a player.
// FUNCTION: TITANIUM 0x0050BEBE
void CGroupWndView_guess::UpdateButtons_guess() {
    bool inList;
    bool isCurrent;
    isCurrent = false;
    inList = false;
    if (g_groupLeaderName_guess[0] == 0) {
        inList = true;
        if (g_currentTarget_guess != 0
            && g_currentTarget_guess->field_244_guess == 0
            && g_currentTarget_guess != g_defaultTarget_guess) {
            isCurrent = true;
        }
    } else {
        DataOwner_guess* owner = g_dataOwner_guess;
        if (CompareData_guess(g_groupLeaderName_guess,
                &owner->recordBytes_guess[
                    owner->index_0008_guess->vbase_offset + 0x3c]) == 0) {
            MenuEntry_guess* scan = g_groupMemberNames_guess;
            while ((int)scan < (int)(g_groupMemberNames_guess + 5)) {
                if (scan->text_guess[0] == 0) {
                    inList = true;
                    if (g_currentTarget_guess != 0
                        && g_currentTarget_guess->field_244_guess == 0
                        && g_currentTarget_guess != g_defaultTarget_guess) {
                        isCurrent = true;
                    }
                    break;
                }
                ++scan;
            }
        }
    }
    if (ini_140.slot164_guess != 0) {
        ini_140.slot164_guess->UpdatePetBarsMenuItem_guess(flag_1bc_guess, 1);
    }
    if (ini_140.slot168_guess != 0) {
        ini_140.slot168_guess->UpdatePetBarsMenuItem_guess(flag_1bc_guess, 1);
    }
    if (ini_140.slot160_guess != 0) {
        ini_140.slot160_guess->UpdatePetBarsMenuItem_guess(flag_1bc_guess == 0, 1);
        ini_140.slot160_guess->field_5d_guess = g_groupLeaderName_guess[0] != 0;
    }
    if (ini_140.slot15c_guess != 0) {
        ini_140.slot15c_guess->UpdatePetBarsMenuItem_guess(flag_1bc_guess == 0, 1);
        ini_140.slot15c_guess->field_5d_guess = isCurrent;
    }
    if (ini_140.slot16c_guess != 0 && pinstCGroupSearchWnd_guess != 0) {
        ini_140.slot16c_guess->UpdatePetBarsMenuItem_guess(inList, 1);
        ini_140.slot16c_guess->field_5d_guess = inList;
    } else if (ini_140.slot16c_guess != 0) {
        ini_140.slot16c_guess->UpdatePetBarsMenuItem_guess(false, 1);
    }
    TargetRecord_guess** record = g_groupMemberSpawns_guess;
    MenuEntry_guess* entry = g_groupMemberNames_guess;
    for (int i = 0; (int)entry < (int)(g_groupMemberNames_guess + 5);
         ++i, ++entry, ++record) {
        bool hasTarget = false;
        bool available = false;
        if (entry->text_guess[0] != 0) {
            TargetRecord_guess* item = *record;
            if (item != 0 && item->field_244_guess == 0) {
                available = true;
                if (item->display_1a8_guess != 0
                    && item->display_1a8_guess->id_16c_guess != -1
                    && FUN_00401b28_guess(
                           item->display_1a8_guess->id_16c_guess) != 0) {
                    hasTarget = true;
                }
            }
        }
        if (slots170_guess[i] != 0) {
            slots170_guess[i]->UpdatePetBarsMenuItem_guess(hasTarget && mode, 1);
        }
        if (slots184_guess[i] != 0) {
            slots184_guess[i]->UpdatePetBarsMenuItem_guess(available, 1);
        }
        if (slots198_guess[i] != 0) {
            slots198_guess[i]->UpdatePetBarsMenuItem_guess(available, 1);
        }
    }
}

// Button clicks (message 1): Invite and Follow (accepts the invite) go to CEverQuest, Disband and
// Decline both disband. LFG opens the LFG window (0x991A58; the flag says you lead) or closes it.
// "Pet Display" in the menu (message 0x14, item 0x32) toggles the setting. Then the base handler.
// FUNCTION: TITANIUM 0x0050C0DA
int CGroupWndView_guess::WndNotification_guess(TargetSlot_guess* pWnd, int message, int data) {
    if (message == 1) {
        if (pWnd == ini_140.slot164_guess) {
            g_globalObject_guess->AcceptGroupInvite_guess();
            return true;
        }
        if (pWnd == ini_140.slot15c_guess) {
            g_globalObject_guess->Invite_guess(0);
            return true;
        }
        if (pWnd == ini_140.slot168_guess) {
            g_globalObject_guess->Disband_guess();
            return true;
        }
        if (pWnd == ini_140.slot160_guess) {
            g_globalObject_guess->Disband_guess();
            return true;
        }
        if (pWnd == ini_140.slot16c_guess && pinstCGroupSearchWnd_guess != 0) {
            if (!pinstCGroupSearchWnd_guess->IsVisible_guess()) {
                if (g_groupLeaderName_guess[0] != 0
                    && CompareData_guess(g_groupLeaderName_guess,
                        &g_dataOwner_guess->recordBytes_guess[
                            g_dataOwner_guess->index_0008_guess->vbase_offset + 0x3c]) == 0) {
                    pinstCGroupSearchWnd_guess->Handle_guess(true);
                } else {
                    pinstCGroupSearchWnd_guess->Handle_guess(false);
                }
            } else {
                pinstCGroupSearchWnd_guess->Deactivate();
            }
        }
    } else if (message == 0x14 && data == 0x32) {
        mode ^= 1;
        UpdateButtons_guess();
        UpdatePetBarsMenuItem_guess();
    }
    return WndNotificationBase_guess(pWnd, message, data);
}

// Builds the title-bar context menu: a "Window" header (string 0x19F3; id = menu manager +0x1154 with bit
// 31 set), then "Pet Display" (string 0xC36, id 0x32); registers it with the menu manager 0x99D414.
// FUNCTION: TITANIUM 0x0050C1D9
void CGroupWndView_guess::CreateContextMenu_guess() {
    queue = 0;
    queue = new CContextMenuView_guess(0, 0, Rect_guess(0, 0, 0x32, 0xa));
    {
        CXStr name(pStringTable->getString(0x19f3, 0));
        int id = pinstCContextMenuManager_guess->field_1154_guess;
        queue->Named_guess(name, id + 0x80000000, 0, -1);
    }
    queue->Finish_guess();
    {
        CXStr name(pStringTable->getString(0xc36, 0));
        value = queue->Named_guess(name, 0x32, 0, -1);
    }
    UpdatePetBarsMenuItem_guess();
    ini_140.contextMenuId_0150_guess = pinstCContextMenuManager_guess->AddMenu_guess(queue);
}

// CGroupWnd::CGroupWnd. Pet bars start on; the three per-member arrays are cleared in one loop through
// the middle one (hpLabel[-5] is the pet gauge, hpLabel[5] the HP percent label).
// FUNCTION: TITANIUM 0x0050C317
// @early-stop: unknown, structural ndiff=35
GroupWindow_guess::GroupWindow_guess(CXWnd* parent)
    : SidlScreenWndCtorBase_guess(parent,
          const_cast<CXStr*>(&static_cast<const CXStr&>(CXStr("GroupWindow"))),
          -1, 1, 0) {
    inviteButton_15c_guess = 0;
    disbandButton_160_guess = 0;
    followButton_164_guess = 0;
    declineButton_168_guess = 0;
    lfgButton_16c_guess = 0;

    TargetSlot_guess** hpLabel = hpLabel_184_guess;
    int count = 5;
    do {
        hpLabel[-5] = 0;
        *hpLabel = 0;
        hpLabel[5] = 0;
        ++hpLabel;
        --count;
    } while (count != 0);

    if (sidlPiece_0124_guess != 0) {
        windowStyle_0064_guess |=
            static_cast<SidlPiece_guess*>(sidlPiece_0124_guess)->flags_0060_guess | 0x800;
        field_0018_guess = 0;
        reinterpret_cast<CSidlScreenWnd*>(this)->CreateChildrenFromSidl();

        {
            CXStr name("InviteButton");
            inviteButton_15c_guess = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name));
        }
        {
            CXStr name("DisbandButton");
            disbandButton_160_guess = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name));
        }
        {
            CXStr name("FollowButton");
            followButton_164_guess = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name));
        }
        {
            CXStr name("DeclineButton");
            declineButton_168_guess = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name));
        }
        {
            CXStr name("LFGButton");
            lfgButton_16c_guess = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name));
        }

        char childName[0x60];
        int i = 1;
        int remaining = 5;
        do {
            _sprintf_guess(childName, "PetGauge%d", i);
            petGauge_170_guess[i - 1] = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(CXStr(childName)));
            _sprintf_guess(childName, "HPLabel%d", i);
            hpLabel_184_guess[i - 1] = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(CXStr(childName)));
            _sprintf_guess(childName, "HPPercLabel%d", i);
            hpPercent_198_guess[i - 1] = reinterpret_cast<TargetSlot_guess*>(
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(CXStr(childName)));
            ++i;
            --remaining;
        } while (remaining != 0);

        flag_1bc_guess = false;
        field_1ac_guess = 0;
        mode_1b4_guess = true;
        reinterpret_cast<CGroupWndView_guess*>(this)->CreateContextMenu_guess();
    }
}

// Sets the invite-pending flag, which swaps Invite/Disband for Follow/Decline.
// FUNCTION: TITANIUM 0x0050C661
void CGroupWndView_guess::SetInvitePending_guess(bool value) {
    flag_1bc_guess = value;
    UpdateButtons_guess();
}

// Refreshes the buttons and their key bindings; always true.
// FUNCTION: TITANIUM 0x0050C61C
bool CGroupWndView_guess::AboutToShow_guess() {
    UpdateButtons_guess();
    UpdateButtonHotkeys_guess();
    return true;
}
