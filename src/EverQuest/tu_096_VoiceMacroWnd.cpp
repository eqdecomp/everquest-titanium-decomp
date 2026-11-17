// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 96: a hint from compare/tumap.py.
// CVoiceMacroWnd (screen "VoiceMacroWnd"): the voice macro list with Play, Tell, Group and Raid buttons
// for /vplay, /vtell, /vgroup and /vraid. CVoiceMacroWndView_guess is the same class seen from its
// destructor; g_iterator_guess (0x985D90) is the voice macro manager: macro list, mute flag (+0x10), play.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CTipWnd.h"

struct CVoiceMacroWndView_guess {
    void* vtable;
    void Destruct_guess();
    CVoiceMacroWndView_guess* ScalarDeletingDestructor_guess(unsigned char flags);
    // EXTERNAL: TITANIUM 0x004CBB10 ??1CVoiceMacroWndView_guess@@QAE@XZ
    ~CVoiceMacroWndView_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x005A3100 FUN_005a3100_guess
void __cdecl FUN_005a3100_guess();

// FUNCTION: TITANIUM 0x004CBB10
void CVoiceMacroWndView_guess::Destruct_guess() {
    vtable = &EQ_GLOBAL(char, 0x0064C638);
    FUN_005a3100_guess();
}

// Scalar deleting destructor: frees the window when bit 0 of `flags` is set.
// FUNCTION: TITANIUM 0x004CBE25
CVoiceMacroWndView_guess* CVoiceMacroWndView_guess::ScalarDeletingDestructor_guess(unsigned char flags) {
    this->CVoiceMacroWndView_guess::~CVoiceMacroWndView_guess();
    if (flags & 1)
        free(this);
    return this;
}

struct Cbb1bChild_guess {
    char pad[0x5d];
    unsigned char enabled_005d_guess;
};

struct CXStr_guess {
    void* value;

    // EXTERNAL: TITANIUM 0x00571E00 CXStr_guess::CXStr_guess
    CXStr_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00571D00 CXStr_guess::Release_guess
    void Release_guess(void* value);

    ~CXStr_guess() {
        if (value != 0)
            Release_guess(value);
        value = 0;
    }
};

struct Controller_guess {
    virtual void slot_0_guess() = 0;
    virtual void slot_1_guess() = 0;
    virtual void slot_2_guess() = 0;
    virtual void slot_3_guess() = 0;
    virtual void slot_4_guess() = 0;
    virtual void slot_5_guess() = 0;
    virtual void slot_6_guess() = 0;
    virtual void slot_7_guess() = 0;
    virtual void slot_8_guess() = 0;
    virtual void slot_9_guess() = 0;
    virtual void slot_10_guess() = 0;
    virtual void slot_11_guess() = 0;
    virtual void slot_12_guess() = 0;
    virtual void slot_13_guess() = 0;
    virtual void slot_14_guess() = 0;
    virtual void slot_15_guess() = 0;
    virtual void slot_16_guess() = 0;
    virtual void slot_17_guess() = 0;
    virtual void slot_18_guess() = 0;
    virtual void slot_19_guess() = 0;
    virtual void slot_20_guess() = 0;
    virtual void slot_21_guess() = 0;
    virtual void slot_22_guess() = 0;
    virtual void slot_23_guess() = 0;
    virtual void slot_24_guess() = 0;
    virtual void slot_25_guess() = 0;
    virtual void slot_26_guess() = 0;
    virtual void slot_27_guess() = 0;
    virtual void slot_28_guess() = 0;
    virtual void slot_29_guess() = 0;
    virtual void slot_30_guess() = 0;
    virtual void slot_31_guess() = 0;
    virtual void slot_32_guess() = 0;
    virtual void slot_33_guess() = 0;
    virtual void slot_34_guess() = 0;
    virtual void slot_35_guess() = 0;
    virtual void slot_36_guess() = 0;
    virtual void slot_37_guess() = 0;
    virtual void slot_38_guess() = 0;
    virtual void slot_39_guess() = 0;
    virtual void slot_40_guess() = 0;
    virtual void slot_41_guess() = 0;
    virtual void slot_42_guess() = 0;
    virtual void slot_43_guess() = 0;
    virtual void slot_44_guess() = 0;
    virtual void slot_45_guess() = 0;
    virtual void slot_46_guess() = 0;
    virtual void slot_47_guess() = 0;
    virtual void slot_48_guess() = 0;
    virtual void slot_49_guess() = 0;
    virtual void slot_50_guess() = 0;
    virtual void slot_51_guess() = 0;
    virtual void slot_52_guess() = 0;
    virtual void slot_53_guess() = 0;
    virtual void slot_54_guess() = 0;
    virtual void slot_55_guess() = 0;
    virtual void slot_56_guess() = 0;
    virtual void slot_57_guess() = 0;
    virtual void slot_58_guess() = 0;
    virtual void slot_59_guess() = 0;
    virtual void slot_60_guess() = 0;
    virtual void slot_61_guess() = 0;
    virtual void slot_62_guess() = 0;
    virtual void slot_63_guess() = 0;
    virtual void slot_64_guess() = 0;
    virtual void slot_65_guess() = 0;
    virtual void slot_66_guess() = 0;
    virtual void slot_67_guess() = 0;
    virtual void slot_68_guess() = 0;
    virtual void slot_69_guess() = 0;
    virtual void slot_70_guess() = 0;
    virtual void slot_71_guess() = 0;
    virtual void slot_72_guess() = 0;
    virtual void slot_73_guess() = 0;
    virtual void slot_74_guess() = 0;
    virtual void slot_75_guess() = 0;
    virtual void Start_guess() = 0;
    virtual void slot_77_guess() = 0;
    virtual void Finish_guess() = 0;

    char pad_004[0x62];
    unsigned char flags_066;            // 0x066
    char pad_067[0xED];
    int sortColumn_0154_guess;
    unsigned char sortAscending_0158_guess;
    char pad_159[3];
    unsigned char value_15c;            // 0x15c
    char pad_15d[0xF];
    unsigned int value_16c;             // 0x16c

    // EXTERNAL: TITANIUM 0x00597C60 Controller_guess::SetColors_guess
    void SetColors_guess(int a, unsigned int b, unsigned int c);
    // EXTERNAL: TITANIUM 0x005982E0 Controller_guess::SetColumnJustification_guess
    void SetColumnJustification_guess(int column, int justify);
    // EXTERNAL: TITANIUM 0x0059B9D0 Controller_guess::Lookup_guess
    unsigned int Lookup_guess(CXStr_guess* text, int index, int id, int flags);
    // EXTERNAL: TITANIUM 0x0059B360 Controller_guess::SetItem_guess
    void SetItem_guess(unsigned int item, int mode, CXStr_guess* text);
};

struct ItemNode_guess;

struct VoiceMacroManager_guess {
    char pad_000[0x10];
    unsigned char muted_0010_guess;            // 0x010
    // EXTERNAL: TITANIUM 0x004466FA VoiceMacroManager_guess::First_guess
    ItemNode_guess* First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A VoiceMacroManager_guess::Next_guess
    void* Next_guess(void* node);
    // EXTERNAL: TITANIUM 0x004CB2B7 VoiceMacroManager_guess::CheckState_guess
    int CheckState_guess();
    // EXTERNAL: TITANIUM 0x004CB2CB VoiceMacroManager_guess::HasMacro_guess
    char HasMacro_guess(unsigned int id);
    // EXTERNAL: TITANIUM 0x004CB42F VoiceMacroManager_guess::SetTarget_guess
    void SetTarget_guess(unsigned int id, int flags);
};

#define g_iterator_guess EQ_GLOBAL(VoiceMacroManager_guess*, 0x00985D90)

struct ItemNode_guess {
    void* item;
};

struct Item_guess {
    int id;
    char pad_004[0x20];
    char text[16];
};

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination, const char* format, ...);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* destination, int radix);
struct CXWnd_guess;

struct CXStrExt_guess : CXStr {
    // EXTERNAL: TITANIUM 0x004647E6 CXStrExt_guess::Format_guess
    CXStr& Format_guess(CXStr* value, int column, int index);
};

struct CEverQuestExt_guess : CEverQuest {
    // EXTERNAL: TITANIUM 0x004AE82A CEverQuestExt_guess::SetMacroState_guess
    void SetMacroState_guess(unsigned int value, const char* category, const char* name);
};

// EXTERNAL: TITANIUM 0x0046BC70 SetSocial_guess
int __cdecl SetSocial_guess(const char* first, const char* second, int a3, int a4);

// EXTERNAL: TITANIUM 0x0046E708 do_vtell_guess
void __cdecl do_vtell_guess(void* target, const char* text);
// EXTERNAL: TITANIUM 0x0046E87D do_vgroup_guess
void __cdecl do_vgroup_guess(void* target, const char* text);
// EXTERNAL: TITANIUM 0x0046E9C2 do_vraid_guess
void __cdecl do_vraid_guess(void* target, const char* text);

// Window base (CSidlScreenWnd, 0x15C bytes).
struct Cbb1bBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1Cbb1bBase_guess@@UAE@XZ
    virtual ~Cbb1bBase_guess();
    char pad_004[0x62];
    unsigned char flags_066;            // 0x066 (CXWnd flags)
    char pad_067[0xBD];
    void* sidlPiece_124;                // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_128[0x30];
    int value_158_guess;                // 0x158
    // EXTERNAL: TITANIUM 0x005A3850 Cbb1bBase_guess::Cbb1bBase_guess
    Cbb1bBase_guess(CXWnd_guess* parent, const CXStr_guess& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A25B0 Cbb1bBase_guess::CreateChildrenFromSidl_guess
    void CreateChildrenFromSidl_guess();
    // EXTERNAL: TITANIUM 0x005A1E10 Cbb1bBase_guess::GetChildItem_guess
    CXWnd_guess* GetChildItem_guess(const CXStr_guess& name);
};

// EXTERNAL: TITANIUM 0x0064C638 ??_7CVoiceMacroWnd_guess@@6B@
struct CVoiceMacroWnd_guess : Cbb1bBase_guess {
    Controller_guess* macroList_guess;       // 0x15c MacroList
    Cbb1bChild_guess* playButton_guess;            // 0x160 PlayButton
    Cbb1bChild_guess* tellButton_guess;           // 0x164 TellButton
    Cbb1bChild_guess* groupButton_guess;            // 0x168 GroupButton
    Cbb1bChild_guess* raidButton_guess;           // 0x16c RaidButton
    CXWnd_guess* closeButton_170;       // 0x170 CloseButton
    CXWnd_guess* muteButton_174;        // 0x174 MuteButton
    int sortColumn_0178_guess;
    unsigned char sortAscending_017c_guess;
    CVoiceMacroWnd_guess(CXWnd_guess* parent);
    void SetButtonsEnabled_guess(unsigned char value);
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
    void RefreshMacroList_guess();
    char AboutToShow_guess();
};

// Sets byte +0x5D, probably the enabled flag, on the four action buttons: 0 until a macro is selected.
// FUNCTION: TITANIUM 0x004CBB1B
void CVoiceMacroWnd_guess::SetButtonsEnabled_guess(unsigned char value) {
    if (playButton_guess != 0)
        playButton_guess->enabled_005d_guess = value;
    if (tellButton_guess != 0)
        tellButton_guess->enabled_005d_guess = value;
    if (groupButton_guess != 0)
        groupButton_guess->enabled_005d_guess = value;
    if (raidButton_guess != 0)
        raidButton_guess->enabled_005d_guess = value;
}

struct ButtonWnd_guess {
    // EXTERNAL: TITANIUM 0x005BB140 ButtonWnd_guess::SetCheck
    void SetCheck(unsigned char checked);
};

struct MacroGlobal_guess {
    // EXTERNAL: TITANIUM 0x004AE919 MacroGlobal_guess::Lookup_guess
    unsigned char Lookup_guess(const char* section, const char* key, int defaultValue, int flag);
};

// Builds the window from SIDL. List colours: 0xFFFFFF00 yellow and 0xFF808080 grey (SetColors_guess),
// 0xFF8AA3FF light blue at +0x16C. Mute is read from the ini section "VoiceMacro". 0x38 is
// probably the window's id; Activate_guess passes the same value.
// FUNCTION: TITANIUM 0x004CBB56
// @early-stop: budget, diff ndiff=1
CVoiceMacroWnd_guess::CVoiceMacroWnd_guess(CXWnd_guess* parent)
    : Cbb1bBase_guess(parent, "VoiceMacroWnd", -1, 1, 0) {
    macroList_guess = 0;
    playButton_guess = 0;
    tellButton_guess = 0;
    groupButton_guess = 0;
    raidButton_guess = 0;
    closeButton_170 = 0;
    sortColumn_0178_guess = 0;
    sortAscending_017c_guess = 1;
    if (sidlPiece_124 != 0) {
        flags_066 |= 1;
        value_158_guess = 0x38;
        CreateChildrenFromSidl_guess();
        macroList_guess = (Controller_guess*)GetChildItem_guess("MacroList");
        playButton_guess = (Cbb1bChild_guess*)GetChildItem_guess("PlayButton");
        tellButton_guess = (Cbb1bChild_guess*)GetChildItem_guess("TellButton");
        groupButton_guess = (Cbb1bChild_guess*)GetChildItem_guess("GroupButton");
        raidButton_guess = (Cbb1bChild_guess*)GetChildItem_guess("RaidButton");
        muteButton_174 = GetChildItem_guess("MuteButton");
        closeButton_170 = GetChildItem_guess("CloseButton");
        if (macroList_guess != 0) {
            macroList_guess->SetColors_guess(-1, 0xffffff00, 0xff808080);
            macroList_guess->SetColumnJustification_guess(0, 1);
            macroList_guess->SetColumnJustification_guess(1, 0);
            macroList_guess->value_16c = 0xff8aa3ff;
            macroList_guess->value_15c = 1;
            macroList_guess->flags_066 |= 4;
        }
        unsigned char mute = EQ_GLOBAL(MacroGlobal_guess*, 0x00988DF0)->Lookup_guess("VoiceMacro", "Mute", 0, 1);
        if (muteButton_174 != 0) {
            ((ButtonWnd_guess*)muteButton_174)->SetCheck(mute);
            EQ_GLOBAL(VoiceMacroManager_guess*, 0x00985D90)->muted_0010_guess = mute;
        }
        SetButtonsEnabled_guess(0);
    }
}

struct Cbb1bSlots_guess {
    virtual void slot_00_guess() = 0;
    virtual void slot_01_guess() = 0;
    virtual void slot_02_guess() = 0;
    virtual void slot_03_guess() = 0;
    virtual void slot_04_guess() = 0;
    virtual void slot_05_guess() = 0;
    virtual void slot_06_guess() = 0;
    virtual void slot_07_guess() = 0;
    virtual void slot_08_guess() = 0;
    virtual void slot_09_guess() = 0;
    virtual void slot_10_guess() = 0;
    virtual void slot_11_guess() = 0;
    virtual void slot_12_guess() = 0;
    virtual void slot_13_guess() = 0;
    virtual void slot_14_guess() = 0;
    virtual void slot_15_guess() = 0;
    virtual void slot_16_guess() = 0;
    virtual void slot_17_guess() = 0;
    virtual void slot_18_guess() = 0;
    virtual void slot_19_guess() = 0;
    virtual void slot_20_guess() = 0;
    virtual void slot_21_guess() = 0;
    virtual void slot_22_guess() = 0;
    virtual void slot_23_guess() = 0;
    virtual void slot_24_guess() = 0;
    virtual void slot_25_guess() = 0;
    virtual void slot_26_guess() = 0;
    virtual void slot_27_guess() = 0;
    virtual void slot_28_guess() = 0;
    virtual void slot_29_guess() = 0;
    virtual void slot_30_guess() = 0;
    virtual void slot_31_guess() = 0;
    virtual void slot_32_guess() = 0;
    virtual void slot_33_guess() = 0;
    virtual void slot_34_guess() = 0;
    virtual void slot_35_guess() = 0;
    virtual void slot_36_guess() = 0;
    virtual void slot_37_guess() = 0;
    virtual void slot_38_guess() = 0;
    virtual void slot_39_guess() = 0;
    virtual void slot_40_guess() = 0;
    virtual void slot_41_guess() = 0;
    virtual void slot_42_guess() = 0;
    virtual void slot_43_guess() = 0;
    virtual void slot_44_guess() = 0;
    virtual void slot_45_guess() = 0;
    virtual void slot_46_guess() = 0;
    virtual void slot_47_guess() = 0;
    virtual void slot_48_guess(int first, int second) = 0;
};

// Message 0x0F, a list column click: the list sorts by it (+0x154 column, +0x158 ascending, as in tu_022);
// the same column again flips the order.
// Message 0x17, a button dragged off: makes a hotbutton running /vplay, /vtell <target>, /vgroup or /vraid
// (strings 6013-6016) with the macro id, then reports 13282 (created) or 13283 (error).
// Message 1, a click: list selection enables the buttons; Play hands the id to the manager,
// Tell needs a PC target (else string 6019), Group and Raid send to the group or raid;
// Mute is saved to the ini.
// FUNCTION: TITANIUM 0x004CBE41
// @early-stop: unknown, structural ndiff=134
int CVoiceMacroWnd_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    if (message == 0x0f) {
        int value = (int)data;
        if (sender == (CXWnd*)macroList_guess) {
            if (sortColumn_0178_guess == value)
                sortAscending_017c_guess ^= 1;
            else
                sortAscending_017c_guess = 1;
            sortColumn_0178_guess = value;
            macroList_guess->sortColumn_0154_guess = value;
            macroList_guess->sortAscending_0158_guess = sortAscending_017c_guess;
            macroList_guess->Finish_guess();
            return 0;
        }
    } else if (message == 0x17) {
        CXStr result;
        CXStr text;
        int index = ((CListWnd*)macroList_guess)->GetCurSel();
        if (index == -1)
            return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);

        int valueText = ((CListWnd*)macroList_guess)->GetItemData(index);
        int releaseValue = 0;
        if (sender == (CXWnd*)playButton_guess) {
            text = pStringTable->getString(0x177d, 0);
            text += &EQ_GLOBAL(char, 0x0063FE10);
            text += _itoa(valueText, &EQ_GLOBAL(char, 0x0099DB00), 10);
            result = ((CXStrExt_guess*)&text)->Format_guess((CXStr*)&valueText, 1, -1);
            releaseValue = 1;
        } else if (sender == (CXWnd*)tellButton_guess) {
            if (pinstTarget == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x1783, 0), 0x0f, true);
                return 0;
            }
            text = pStringTable->getString(0x177e, 0);
            text += &EQ_GLOBAL(char, 0x0063FE10);
            result = text;
            text += pinstTarget->Name;
            text += &EQ_GLOBAL(char, 0x0063FE10);
            text += _itoa(valueText, &EQ_GLOBAL(char, 0x0099DB00), 10);
            result += _itoa(valueText, &EQ_GLOBAL(char, 0x0099DB00), 10);
        } else if (sender == (CXWnd*)groupButton_guess) {
            text = pStringTable->getString(0x177f, 0);
            text += &EQ_GLOBAL(char, 0x0063FE10);
            text += _itoa(valueText, &EQ_GLOBAL(char, 0x0099DB00), 10);
            result = ((CXStrExt_guess*)&text)->Format_guess((CXStr*)&valueText, 1, -1);
            releaseValue = 1;
        } else if (sender == (CXWnd*)raidButton_guess) {
            text = pStringTable->getString(0x1780, 0);
            text += &EQ_GLOBAL(char, 0x0063FE10);
            text += _itoa(valueText, &EQ_GLOBAL(char, 0x0099DB00), 10);
            result = ((CXStrExt_guess*)&text)->Format_guess((CXStr*)&valueText, 1, -1);
            releaseValue = 1;
        }

        if (releaseValue != 0 && valueText != 0)
            ((CXStr*)&valueText)->FreeRep((CStrRep*)valueText);
        int length = text.Ptr != 0 ? text.Ptr->length : 0;
        if (length > 0) {
            int comparison = SetSocial_guess(result, text, 0, -1);
            pEverQuest->dsp_chat(pStringTable->getString(comparison < 0 ? 0x33e3 : 0x33e2, 0));
        }
    } else if (message == 1) {
        if (sender == (CXWnd*)macroList_guess) {
            SetButtonsEnabled_guess(1);
            return 0;
        }
        if (sender == (CXWnd*)closeButton_170) {
            ((Cbb1bSlots_guess*)this)->slot_48_guess(0, 1);
            return 0;
        }
        if (sender == (CXWnd*)muteButton_174) {
            g_iterator_guess->muted_0010_guess = ((CButtonWnd*)muteButton_174)->Checked;
            ((CEverQuestExt_guess*)pEverQuest)->SetMacroState_guess(
                ((CButtonWnd*)muteButton_174)->Checked, "VoiceMacro", "Mute");
            return 0;
        }
        if (sender == (CXWnd*)playButton_guess) {
            int index = ((CListWnd*)macroList_guess)->GetCurSel();
            unsigned int value = ((CListWnd*)macroList_guess)->GetItemData(index);
            if (g_iterator_guess->HasMacro_guess(value) != 0)
                g_iterator_guess->SetTarget_guess(value, -1);
            return 0;
        }
        if (sender == (CXWnd*)tellButton_guess) {
            if (pinstTarget == 0 || pinstTarget->Type != 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x1783, 0), 0x0f, true);
            } else {
                char buffer[0x400];
                int index = ((CListWnd*)macroList_guess)->GetCurSel();
                unsigned int value = ((CListWnd*)macroList_guess)->GetItemData(index);
                // The drag branch above only checks for a target; the click needs a PC (spawn type 0).
                sprintf(buffer, "%s %d", pinstTarget->Name, value);
                do_vtell_guess(EQ_GLOBAL(void*, 0x00905CE4), buffer);
            }
            return 0;
        }
        if (sender == (CXWnd*)groupButton_guess) {
            char buffer[0x400];
            int index = ((CListWnd*)macroList_guess)->GetCurSel();
            unsigned int value = ((CListWnd*)macroList_guess)->GetItemData(index);
            sprintf(buffer, "%d", value);
            do_vgroup_guess(EQ_GLOBAL(void*, 0x00905CE4), buffer);
            return 0;
        }
        if (sender == (CXWnd*)raidButton_guess) {
            char buffer[0x400];
            int index = ((CListWnd*)macroList_guess)->GetCurSel();
            unsigned int value = ((CListWnd*)macroList_guess)->GetItemData(index);
            sprintf(buffer, "%d", value);
            do_vraid_guess(EQ_GLOBAL(void*, 0x00905CE4), buffer);
            return 0;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// Refills the list from the voice macro manager: column 0 the id ("%03d"), column 1 the macro text;
// keeps the sort column and direction.
// FUNCTION: TITANIUM 0x004CC488
void CVoiceMacroWnd_guess::RefreshMacroList_guess() {
    char id_buffer[12];

    if (macroList_guess != 0) {
        macroList_guess->Start_guess();
        VoiceMacroManager_guess* iterator = EQ_GLOBAL(VoiceMacroManager_guess*, 0x00985D90);
        ItemNode_guess* node = iterator->First_guess();
        while (node != 0) {
            Item_guess* item = (Item_guess*)node->item;
            sprintf(id_buffer, "%03d", item->id);
            unsigned int item_index;
            {
                CXStr_guess id_text(id_buffer);
                item_index = macroList_guess->Lookup_guess(&id_text, -1, item->id, 0);
            }
            {
                CXStr_guess item_text(item->text);
                macroList_guess->SetItem_guess(item_index, 1, &item_text);
            }
            node = (ItemNode_guess*)iterator->Next_guess(node);
        }
        macroList_guess->sortColumn_0154_guess = sortColumn_0178_guess;
        macroList_guess->sortAscending_0158_guess = sortAscending_017c_guess;
        macroList_guess->Finish_guess();
    }
    SetButtonsEnabled_guess(0);
}

// AboutToShow (vtable slot 49): the window opens only while the voice macro manager (0x985D90) check is
// non-zero; then it refreshes the list and shows context tip 0x38 in the tip window (0x9928E0).
// FUNCTION: TITANIUM 0x004CC5CE
char CVoiceMacroWnd_guess::AboutToShow_guess() {
    char state = g_iterator_guess->CheckState_guess();
    if (state != 0) {
        RefreshMacroList_guess();
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x38, 0);
    }
    return state;
}
