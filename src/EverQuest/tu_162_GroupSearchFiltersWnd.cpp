// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 162: a hint from compare/tumap.py.
// The group search filters window (GroupSearchFiltersWnd, GSFW_ widgets): ignore/friends player filters,
// excluded and desired guild lists, and the exclusive-search box, kept in the [ADDITIONALFILTERS] section of
// the
// per-character ini. Widgets: +0x15C ignore, +0x160 friends, +0x164/+0x168 excluded guilds box and list,
// +0x17C/+0x180 desired guilds box and list, +0x16C/+0x184 the guild-name combos, +0x194 exclusive search.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct Callback_guess {
    char pad_004[0x60];
    unsigned int WindowStyle; // 0x64, window style
    char pad_068[0x11C - 0x68];
    Callback_guess* child_11c; // 0x11c
    char pad_120[0x128 - 0x120];
    unsigned char flag_128; // 0x128
    char pad_129[0x154 - 0x129];
    int field_154; // 0x154

    // EXTERNAL: TITANIUM 0x0059C330 Callback_guess::Foo_guess
    void Foo_guess(int a, int b, int c);
    // EXTERNAL: TITANIUM 0x0059C360 Callback_guess::Bar_guess
    void Bar_guess(int value);
    // EXTERNAL: TITANIUM 0x0059C8D0 Callback_guess::Baz_guess
    void Baz_guess(const CXStr& text);

    // EXTERNAL: TITANIUM 0x00597BE0 Callback_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x0059BB00 Callback_guess::ApplyValue_guess
    void ApplyValue_guess(int value);

    // EXTERNAL: TITANIUM 0x005BB140 Callback_guess::Notify_guess
    void Notify_guess(int value);

    // EXTERNAL: TITANIUM 0x0059C3B0 Callback_guess::GetSelectedText_guess
    CXStr GetSelectedText_guess();

    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot75_guess() = 0;
    virtual void Slot76_guess() = 0;
};

struct DispatchBase_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot75_guess() = 0;
    virtual void Slot76_guess() = 0;
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x00655080 ??_7CGroupSearchFiltersWnd_guess@@6B@


struct CGroupSearchFiltersWnd_guess : CSidlScreenWndBase {
    Callback_guess* callback_15c; // 0x15c
    Callback_guess* callback_160; // 0x160
    Callback_guess* callback_164; // 0x164
    Callback_guess* callback_168; // 0x168
    Callback_guess* callback_16c; // 0x16c
    Callback_guess* callback_170; // 0x170
    Callback_guess* callback_174; // 0x174
    Callback_guess* callback_178; // 0x178
    Callback_guess* callback_17c; // 0x17c
    Callback_guess* callback_180; // 0x180
    Callback_guess* callback_184; // 0x184
    Callback_guess* callback_188; // 0x188
    Callback_guess* callback_18c; // 0x18c
    Callback_guess* callback_190; // 0x190
    Callback_guess* callback_194; // 0x194

    CGroupSearchFiltersWnd_guess(CXWnd* parent);
    bool LoadFilterSettings_guess();

    void GetWidgets_guess();
    // EXTERNAL: TITANIUM 0x005A1E10 CGroupSearchFiltersWnd_guess::GetChildItem_guess
    Callback_guess* GetChildItem_guess(const CXStr& name);

    void ClearCallbacks_guess();
    void RebuildLists_guess();
    unsigned char IsExclusiveSearch_guess();
    unsigned char ReadFlag17C_guess();
    unsigned char ReadFlag15C_guess();
    unsigned char ReadFlag160_guess();
    unsigned char ReadFlag164_guess();
    void UncheckFriendsList_guess();
    void UncheckIgnoreList_guess();
    void UncheckDesiredGuilds_guess();
    void UncheckExcludedGuilds_guess();
    void AddExcludedGuild_guess();
    void RemoveExcludedGuild_guess();
    void RemoveAllExcludedGuilds_guess();
    void AddDesiredGuild_guess();
    void RemoveDesiredGuild_guess();
    void RemoveAllDesiredGuilds_guess();
    unsigned char IsGuildExcluded_guess(const char* name);
    unsigned char IsGuildDesired_guess(const char* name);
    unsigned char IsFilteredOut_guess(int value, const char* name);
    // EXTERNAL: TITANIUM 0x0050818A CGroupSearchFiltersWnd_guess::IsPlayerIgnored_guess
    char IsPlayerIgnored_guess(int value);
    // EXTERNAL: TITANIUM 0x005081A1 CGroupSearchFiltersWnd_guess::IsPlayerFriend_guess
    char IsPlayerFriend_guess(int value);
    void WriteFilters_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CGroupSearchFiltersWnd_guess::DefaultMessage_guess
    int DefaultMessage_guess(Callback_guess* widget, int message, int data);
    int DispatchMessage_guess(Callback_guess* widget, int message, int data);
};

struct Registry_guess {
    // EXTERNAL: TITANIUM 0x0049297B Registry_guess::BeingIgnored_guess
    int BeingIgnored_guess(int value);
    // EXTERNAL: TITANIUM 0x004929AC Registry_guess::IsFriend_guess
    int IsFriend_guess(int value);
};

#define g_registry_guess EQ_GLOBAL(Registry_guess*, 0x00988DF0)

struct ItemEntry_guess {
    void* ptr_00; // 0x00

    // EXTERNAL: TITANIUM 0x00571D00 ItemEntry_guess::FreeRep
    void FreeRep(void* p);

    ~ItemEntry_guess() {
        if (ptr_00 != 0) {
            FreeRep(ptr_00);
        }
        ptr_00 = 0;
    }

    // EXTERNAL: TITANIUM 0x00572300 ItemEntry_guess::GetName_guess
    const char* GetName_guess();
};

struct ItemList_guess {
    char pad_000[0x11c];
    int count_11c; // 0x11c

    // EXTERNAL: TITANIUM 0x00597F10 ItemList_guess::GetAt_guess
    ItemEntry_guess GetAt_guess(int index, int flag);
};

struct NameTable_guess {
    // EXTERNAL: TITANIUM 0x0040A77A NameTable_guess::IsGuildValid_guess
    bool IsGuildValid_guess(int index);
    // EXTERNAL: TITANIUM 0x0040AC55 NameTable_guess::Lookup_guess
    const char* Lookup_guess(int index);
};

#define g_nameTable_guess EQ_GLOBAL(NameTable_guess, 0x00905D38)

// EXTERNAL: TITANIUM 0x00574460 CompareName_guess
int CompareName_guess(const char* a, const char* b);
// EXTERNAL: TITANIUM 0x0055955C GetCustomIniFilename_guess
const char* __cdecl GetCustomIniFilename_guess();
// EXTERNAL: TITANIUM 0x0060BE20 FUN_0060be20_guess
int __cdecl FUN_0060be20_guess(const char* section, const char* key, int defaultValue, const char* profile);
// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section, const char* key, const char* defaultValue,
                                char* value, int size, const char* profile);
// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section, const char* key, const char* value, const char* filename);

// Reads the modes (player: 1 ignore list, 2 friends list; guild: 1 excluded, 2 desired) and the
// GUILDEXCLUDED<n> / GUILDDESIRED<n> lists, which end at the first "*NULL*". False without a character ini.
// FUNCTION: TITANIUM 0x0050854A
// @early-stop: budget, structural ndiff=86
bool CGroupSearchFiltersWnd_guess::LoadFilterSettings_guess() {
    char key[32];
    char value[64];
    int playerMode;
    const char* profile = GetCustomIniFilename_guess();
    if (profile != 0) {
        playerMode = FUN_0060be20_guess("ADDITIONALFILTERS", "FilterByPlayerMode", 1,
                                      GetCustomIniFilename_guess());
        int guildMode = FUN_0060be20_guess("ADDITIONALFILTERS", "FilterByGuildMode", 0,
                                          GetCustomIniFilename_guess());
        int exclusiveMode = FUN_0060be20_guess("ADDITIONALFILTERS", "FilterByExclusiveSearch", 0,
                                              GetCustomIniFilename_guess());

        if (callback_160 != 0 && callback_15c != 0) {
            ((CButtonWnd*)callback_160)->SetCheck(playerMode == 2);
            ((CButtonWnd*)callback_15c)->SetCheck(playerMode == 1);
        }
        if (callback_17c != 0 && callback_164 != 0) {
            ((CButtonWnd*)callback_17c)->SetCheck(guildMode == 2);
            ((CButtonWnd*)callback_164)->SetCheck(guildMode == 1);
        }
        if (callback_194 != 0) {
            ((CButtonWnd*)callback_194)->SetCheck(exclusiveMode == 1);
        }

        int index = 0;
        if (callback_168 != 0) {
            while (true) {
                sprintf(key, "GUILDEXCLUDED%d", index);
                FUN_0060be50_guess("ADDITIONALFILTERS", key, "*NULL*", value, 0x40,
                                  GetCustomIniFilename_guess());
                if (strcmp(value, "*NULL*") == 0) {
                    break;
                }
                CXStr text(value);
                ((CListWnd*)callback_168)->AddString(text, 0xffffffff, 0, 0);
                ++index;
            }
        }

        index = 0;
        if (callback_180 != 0) {
            while (true) {
                sprintf(key, "GUILDDESIRED%d", index);
                FUN_0060be50_guess("ADDITIONALFILTERS", key, "*NULL*", value, 0x40,
                                  GetCustomIniFilename_guess());
                if (strcmp(value, "*NULL*") == 0) {
                    break;
                }
                CXStr text(value);
                ((CListWnd*)callback_180)->AddString(text, 0xffffffff, 0, 0);
                ++index;
            }
        }
        return true;
    }
    return false;
}

// Style 0x800 is added to the SIDL style; the lists are filled and the saved filters loaded.
// FUNCTION: TITANIUM 0x0050876B
CGroupSearchFiltersWnd_guess::CGroupSearchFiltersWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "GroupSearchFiltersWnd", -1, 1, 0) {
    ClearCallbacks_guess();
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        GetWidgets_guess();
        RebuildLists_guess();
        LoadFilterSettings_guess();
    }
}

// Clears the 15 control pointers that 0x005078B2 fills.
// FUNCTION: TITANIUM 0x00507855
void CGroupSearchFiltersWnd_guess::ClearCallbacks_guess() {
    callback_15c = 0;
    callback_160 = 0;
    callback_164 = 0;
    callback_168 = 0;
    callback_16c = 0;
    callback_170 = 0;
    callback_174 = 0;
    callback_178 = 0;
    callback_17c = 0;
    callback_180 = 0;
    callback_184 = 0;
    callback_188 = 0;
    callback_18c = 0;
    callback_190 = 0;
    callback_194 = 0;
}

// Looks up the group search filter window's 15 GSFW_ controls: the ignore and friends list check boxes,
// the excluded and desired guild lists with their name combos and add/remove buttons, and the exclusion
// search check box.
// FUNCTION: TITANIUM 0x005078B2
void CGroupSearchFiltersWnd_guess::GetWidgets_guess() {
    {
        CXStr name("GSFW_UseIgnoreListCheckbox");
        callback_15c = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_UseFriendsListCheckbox");
        callback_160 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_ExcludedGuildsCheckbox");
        callback_164 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_ExcludedGuildsList");
        callback_168 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_GuildNamesToExcludeSelectionCombo");
        callback_16c = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_RemoveExcludedGuildButton");
        callback_170 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_RemoveAllExcludedGuildButton");
        callback_174 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_AddExcludedGuildButton");
        callback_178 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_DesiredGuildsCheckbox");
        callback_17c = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_DesiredGuildsList");
        callback_180 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_GuildNamesToDesireSelectionCombo");
        callback_184 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_RemoveDesiredGuildButton");
        callback_188 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_RemoveAllDesiredGuildButton");
        callback_18c = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_AddDesiredGuildButton");
        callback_190 = GetChildItem_guess(name);
    }
    {
        CXStr name("GSFW_ExclusionSearchCheckbox");
        callback_194 = GetChildItem_guess(name);
    }
}

// Fills both guild combos from the guild-name table (ids 0-1499 that are set) and gives the combos and lists
// their colours (yellow text, grey highlight).
// FUNCTION: TITANIUM 0x00507C1B
void CGroupSearchFiltersWnd_guess::RebuildLists_guess() {
    if (callback_16c != 0) {
        callback_16c->Foo_guess(-1, 0xffffff00, 0xff808080);
        callback_16c->child_11c->WindowStyle |= 0x40000;
        callback_16c->child_11c->field_154 = 0;
        callback_16c->child_11c->Slot76_guess();
    }
    if (callback_184 != 0) {
        callback_184->Foo_guess(-1, 0xffffff00, 0xff808080);
        callback_184->child_11c->WindowStyle |= 0x40000;
        callback_184->child_11c->field_154 = 0;
        callback_184->child_11c->Slot76_guess();
    }
    for (int i = 0; i < 0x5dc; ++i) {
        if (callback_16c != 0) {
            if (g_nameTable_guess.IsGuildValid_guess(i)) {
                CXStr name(g_nameTable_guess.Lookup_guess(i));
                callback_16c->Baz_guess(name);
            }
        }
        if (callback_184 != 0) {
            if (g_nameTable_guess.IsGuildValid_guess(i)) {
                CXStr name(g_nameTable_guess.Lookup_guess(i));
                callback_184->Baz_guess(name);
            }
        }
    }
    if (callback_16c != 0) {
        callback_16c->Bar_guess(0);
    }
    if (callback_184 != 0) {
        callback_184->Bar_guess(0);
    }
    if (callback_168 != 0) {
        reinterpret_cast<CListWnd*>(callback_168)->SetColors(-1, 0xffffff00, 0xff808080);
        callback_168->WindowStyle |= 0x40000;
        callback_168->WindowStyle &= 0xffdfffff;
        callback_168->field_154 = 0;
        callback_168->Slot76_guess();
    }
    if (callback_180 != 0) {
        reinterpret_cast<CListWnd*>(callback_180)->SetColors(-1, 0xffffff00, 0xff808080);
        callback_180->WindowStyle |= 0x40000;
        callback_180->WindowStyle &= 0xffdfffff;
        callback_180->field_154 = 0;
        callback_180->Slot76_guess();
    }
}

// Whether "exclusive search" (+0x194) is checked.
// FUNCTION: TITANIUM 0x00507E5B
unsigned char CGroupSearchFiltersWnd_guess::IsExclusiveSearch_guess() {
    Callback_guess* callback = callback_194;
    unsigned char result = 0;
    if (callback != 0) {
        result = callback->flag_128;
    }
    return result;
}

// The paired check boxes exclude each other: each of these four unchecks the partner of the box just clicked.
// Unchecks "use friends list".
// FUNCTION: TITANIUM 0x00507E6E
void CGroupSearchFiltersWnd_guess::UncheckFriendsList_guess() {
    if (callback_160 != 0) {
        callback_160->Notify_guess(0);
    }
}

// Unchecks "use ignore list".
// FUNCTION: TITANIUM 0x00507E80
void CGroupSearchFiltersWnd_guess::UncheckIgnoreList_guess() {
    if (callback_15c != 0) {
        callback_15c->Notify_guess(0);
    }
}

// Unchecks "desired guilds".
// FUNCTION: TITANIUM 0x00507E92
void CGroupSearchFiltersWnd_guess::UncheckDesiredGuilds_guess() {
    if (callback_17c != 0) {
        callback_17c->Notify_guess(0);
    }
}

// Unchecks "excluded guilds".
// FUNCTION: TITANIUM 0x00507EA4
void CGroupSearchFiltersWnd_guess::UncheckExcludedGuilds_guess() {
    if (callback_164 != 0) {
        callback_164->Notify_guess(0);
    }
}

// Adds the guild picked in the exclude combo to the excluded list, unless it is already there.
// FUNCTION: TITANIUM 0x00507EB6
void CGroupSearchFiltersWnd_guess::AddExcludedGuild_guess() {
    if (callback_16c != 0 && callback_168 != 0) {
        const char* selected = callback_16c->GetSelectedText_guess();
        int count = reinterpret_cast<ItemList_guess*>(callback_168)->count_11c;
        for (int i = 0; i < count; ++i) {
            unsigned char match = CompareName_guess(selected, reinterpret_cast<CListWnd*>(callback_168)->GetItemText(i, 0)) == 0;
            if (match) {
                return;
            }
        }
        reinterpret_cast<CListWnd*>(callback_168)->AddString(selected, 0xffffffff, 0, 0);
    }
}

// Removes the selected excluded guild.
// FUNCTION: TITANIUM 0x00507FC6
void CGroupSearchFiltersWnd_guess::RemoveExcludedGuild_guess() {
    if (callback_168 != 0) {
        int value = callback_168->GetValue_guess();
        callback_168->ApplyValue_guess(value);
    }
}

// Clears the excluded-guild list.
// FUNCTION: TITANIUM 0x00507FE2
void CGroupSearchFiltersWnd_guess::RemoveAllExcludedGuilds_guess() {
    if (callback_168 != 0) {
        callback_168->Slot76_guess();
    }
}

// Adds the guild picked in the desire combo to the desired list, unless it is already there.
// FUNCTION: TITANIUM 0x00507FFA
void CGroupSearchFiltersWnd_guess::AddDesiredGuild_guess() {
    if (callback_184 != 0 && callback_180 != 0) {
        const char* selected = callback_184->GetSelectedText_guess();
        int count = reinterpret_cast<ItemList_guess*>(callback_180)->count_11c;
        for (int i = 0; i < count; ++i) {
            unsigned char match = CompareName_guess(selected, reinterpret_cast<ItemList_guess*>(callback_180)->GetAt_guess(i, 0).GetName_guess()) == 0;
            if (match) {
                return;
            }
        }
        reinterpret_cast<CListWnd*>(callback_180)->AddString(selected, 0xffffffff, 0, 0);
    }
}

// Removes the selected desired guild.
// FUNCTION: TITANIUM 0x0050810A
void CGroupSearchFiltersWnd_guess::RemoveDesiredGuild_guess() {
    if (callback_180 != 0) {
        int value = callback_180->GetValue_guess();
        callback_180->ApplyValue_guess(value);
    }
}

// Clears the desired-guild list.
// FUNCTION: TITANIUM 0x00508126
void CGroupSearchFiltersWnd_guess::RemoveAllDesiredGuilds_guess() {
    if (callback_180 != 0) {
        callback_180->Slot76_guess();
    }
}

// "Use ignore list" is checked.
// FUNCTION: TITANIUM 0x0050813E
unsigned char CGroupSearchFiltersWnd_guess::ReadFlag15C_guess() {
    Callback_guess* callback = callback_15c;
    unsigned char result = 0;
    if (callback != 0) {
        result = callback->flag_128;
    }
    return result;
}

// "Use friends list" is checked.
// FUNCTION: TITANIUM 0x00508151
unsigned char CGroupSearchFiltersWnd_guess::ReadFlag160_guess() {
    Callback_guess* callback = callback_160;
    unsigned char result = 0;
    if (callback != 0) {
        result = callback->flag_128;
    }
    return result;
}

// "Excluded guilds" is checked.
// FUNCTION: TITANIUM 0x00508164
unsigned char CGroupSearchFiltersWnd_guess::ReadFlag164_guess() {
    Callback_guess* callback = callback_164;
    unsigned char result = 0;
    if (callback != 0) {
        result = callback->flag_128;
    }
    return result;
}

// "Desired guilds" is checked.
// FUNCTION: TITANIUM 0x00508177
unsigned char CGroupSearchFiltersWnd_guess::ReadFlag17C_guess() {
    Callback_guess* callback = callback_17c;
    unsigned char result = 0;
    if (callback != 0) {
        result = callback->flag_128;
    }
    return result;
}

// Whether player `value` is on your ignore list (pEverQuest, 0x0049297B). One of the group search
// filter tests (0x00508955).
// FUNCTION: TITANIUM 0x0050818A
char __stdcall IsPlayerIgnored_guess(int value) {
    return g_registry_guess->BeingIgnored_guess(value) != 0;
}

// Whether player `value` is on your friends list (pEverQuest, 0x004929AC). One of the group search
// filter tests (0x00508955).
// FUNCTION: TITANIUM 0x005081A1
char __stdcall IsPlayerFriend_guess(int value) {
    return g_registry_guess->IsFriend_guess(value) != 0;
}

// Whether `name` is in the excluded-guild list.
// FUNCTION: TITANIUM 0x005081B8
unsigned char CGroupSearchFiltersWnd_guess::IsGuildExcluded_guess(const char* name) {
    ItemList_guess* list = reinterpret_cast<ItemList_guess*>(callback_168);
    unsigned char found = 0;
    if (list != 0) {
        int count = list->count_11c;
        for (int i = 0; i < count; ++i) {
            unsigned char match = CompareName_guess(name, reinterpret_cast<ItemList_guess*>(callback_168)->GetAt_guess(i, 0).GetName_guess()) == 0;
            if (match) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

// Whether `name` is in the desired-guild list.
// FUNCTION: TITANIUM 0x00508254
unsigned char CGroupSearchFiltersWnd_guess::IsGuildDesired_guess(const char* name) {
    ItemList_guess* list = reinterpret_cast<ItemList_guess*>(callback_180);
    unsigned char found = 0;
    if (list != 0) {
        int count = list->count_11c;
        for (int i = 0; i < count; ++i) {
            unsigned char match = CompareName_guess(name, reinterpret_cast<ItemList_guess*>(callback_180)->GetAt_guess(i, 0).GetName_guess()) == 0;
            if (match) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

// Saves the modes and both lists; each list gets a "*NULL*" entry after its last guild to end it.
// FUNCTION: TITANIUM 0x005082F0
void CGroupSearchFiltersWnd_guess::WriteFilters_guess() {
    if (GetCustomIniFilename_guess() != 0) {
        char value[32];
        char key[32];
        int playerMode = 0;
        int guildMode = 0;
        int exclusive = 0;
        if (ReadFlag160_guess()) {
            playerMode = 2;
        } else if (ReadFlag15C_guess()) {
            playerMode = 1;
        }
        if (ReadFlag164_guess()) {
            guildMode = 1;
        } else if (ReadFlag17C_guess()) {
            guildMode = 2;
        }
        if (IsExclusiveSearch_guess()) {
            exclusive = 1;
        }
        _itoa(playerMode, value, 10);
        FUN_0060beb0_guess("ADDITIONALFILTERS", "FilterByPlayerMode", value, GetCustomIniFilename_guess());
        _itoa(guildMode, value, 10);
        FUN_0060beb0_guess("ADDITIONALFILTERS", "FilterByGuildMode", value, GetCustomIniFilename_guess());
        _itoa(exclusive, value, 10);
        FUN_0060beb0_guess("ADDITIONALFILTERS", "FilterByExclusiveSearch", value, GetCustomIniFilename_guess());
        if (callback_168 != 0) {
            int count = reinterpret_cast<ItemList_guess*>(callback_168)->count_11c;
            int i = 0;
            if (count >= 0) {
                do {
                    sprintf(key, "GUILDEXCLUDED%d", i);
                    if (i < count) {
                        FUN_0060beb0_guess("ADDITIONALFILTERS", key, reinterpret_cast<CListWnd*>(callback_168)->GetItemText(i, 0), GetCustomIniFilename_guess());
                    } else {
                        FUN_0060beb0_guess("ADDITIONALFILTERS", key, "*NULL*", GetCustomIniFilename_guess());
                    }
                    ++i;
                } while (i <= count);
            }
        }
        if (callback_180 != 0) {
            int count = reinterpret_cast<ItemList_guess*>(callback_180)->count_11c;
            int i = 0;
            if (count >= 0) {
                do {
                    sprintf(key, "GUILDDESIRED%d", i);
                    if (i < count) {
                        FUN_0060beb0_guess("ADDITIONALFILTERS", key, reinterpret_cast<CListWnd*>(callback_180)->GetItemText(i, 0), GetCustomIniFilename_guess());
                    } else {
                        FUN_0060beb0_guess("ADDITIONALFILTERS", key, "*NULL*", GetCustomIniFilename_guess());
                    }
                    ++i;
                } while (i <= count);
            }
        }
    }
}

// Any click (message 1) on a filter widget saves the filters afterwards. The empty branch for the
// exclusive-search box is deliberate: it only saves.
// FUNCTION: TITANIUM 0x00508840
// @early-stop: unknown, structural ndiff=45
int CGroupSearchFiltersWnd_guess::DispatchMessage_guess(Callback_guess* widget, int message, int data) {
    int result = 0;
    if (widget == callback_15c && message == 1) {
        UncheckFriendsList_guess();
    } else if (widget == callback_160 && message == 1) {
        UncheckIgnoreList_guess();
    } else if (widget == callback_164 && message == 1) {
        UncheckDesiredGuilds_guess();
    } else if (widget == callback_170 && message == 1) {
        RemoveExcludedGuild_guess();
    } else if (widget == callback_174 && message == 1) {
        RemoveAllExcludedGuilds_guess();
    } else if (widget == callback_178 && message == 1) {
        AddExcludedGuild_guess();
    } else if (widget == callback_17c && message == 1) {
        UncheckExcludedGuilds_guess();
    } else if (widget == callback_188 && message == 1) {
        RemoveDesiredGuild_guess();
    } else if (widget == callback_18c && message == 1) {
        RemoveAllDesiredGuilds_guess();
    } else if (widget == callback_190 && message == 1) {
        AddDesiredGuild_guess();
    } else if (widget == callback_194 && message == 1) {
    }
    else {
        result = DefaultMessage_guess(widget, message, data);
        return result;
    }
    WriteFilters_guess();
    return result;
}

// True when the player should be filtered out of the search: ignored, not a friend, in an excluded guild, or
// not in a desired guild, by whichever boxes are checked. Each later test overwrites the earlier result, so a
// guild test decides alone when a player test is also on.
// FUNCTION: TITANIUM 0x00508955
unsigned char CGroupSearchFiltersWnd_guess::IsFilteredOut_guess(int value, const char* name) {
    unsigned char result = 0;
    if (ReadFlag15C_guess()) {
        result = IsPlayerIgnored_guess(value);
    }
    if (ReadFlag160_guess()) {
        result = !IsPlayerFriend_guess(value);
    }
    if (name != 0) {
        if (ReadFlag164_guess()) {
            result = IsGuildExcluded_guess(name);
        }
        if (ReadFlag17C_guess()) {
            result = !IsGuildDesired_guess(name);
        }
    }
    return result;
}
