// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 126: a hint from compare/tumap.py.
// CBandolierWnd (screen "BandolierWnd"): up to 20 named weapon sets of 4 items (primary, secondary,
// range, ammo; EQEmu Bandolier_Struct). GroupWnd_guess, Owner_guess, Panel_guess, Widget_guess, Target_guess,
// Report_guess and AutoSwap_guess are all this window. The set data and its handlers (0x4BAE54, 0x4BAEEE,
// 0x4BD3E5, 0x4BF5BA) are tu_080 code on 0x905D00; the Copy*/Element helpers copy the A_DragItem animation.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CTextEntryWnd.h"

struct RefField_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00407D68 RefField_guess::Copy_guess
    void Copy_guess(RefField_guess* source);
    // EXTERNAL: TITANIUM 0x004482FB RefField_guess::~RefField_guess
    ~RefField_guess();
};

struct CopyBlock_guess {
    char value_000_guess;
    char pad_001_guess[3];
    int value_004_guess;
    RefField_guess value_008_guess;
    int value_00C_guess;
    int value_010_guess;
    int value_014_guess;

    CopyBlock_guess* Copy_guess(CopyBlock_guess* source);
};

struct CopyTail_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x004D911A CopyTail_guess::Copy_guess
    void Copy_guess(CopyTail_guess* source);
};

struct CopyObject_guess {
    CopyBlock_guess first_guess;
    CopyTail_guess tail_guess;

    CopyObject_guess* Copy_guess(char* source);
};

struct CopyTemp_guess {
    int values_000_guess[2];
    RefField_guess value_008_guess;
    int values_00C_guess[7];
    // EXTERNAL: TITANIUM 0x004DAF9E CopyTemp_guess::CopyTemp_guess
    CopyTemp_guess(char* source);
};

// Copies all fields of `source`; the one at +8 is copied with 0x00407D68.
// FUNCTION: TITANIUM 0x004DAF67
CopyBlock_guess* CopyBlock_guess::Copy_guess(CopyBlock_guess* source) {
    value_000_guess = source->value_000_guess;
    value_004_guess = source->value_004_guess;
    value_008_guess.Copy_guess(&source->value_008_guess);
    value_00C_guess = source->value_00C_guess;
    value_010_guess = source->value_010_guess;
    value_014_guess = source->value_014_guess;
    return this;
}

// Copy constructor of a texture-animation frame's first part: the texture block (0x004DAF67, with its
// name string) and the rect at +0x18. Builds the temporary that the frame copy (0x004DB55A) assigns
// from.
// FUNCTION: TITANIUM 0x004DAF9E
CopyObject_guess* CopyObject_guess::Copy_guess(char* source) {
    first_guess.Copy_guess((CopyBlock_guess*)source);
    tail_guess.Copy_guess((CopyTail_guess*)(source + 0x18));
    return this;
}

struct Pair_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x004D9160 Pair_guess::Copy_guess
    void Copy_guess(void* destination, void* source);
};

struct Manager_guess {
    char pad_000_guess[0x18];
    Pair_guess pair_guess;
    int values_028_guess[3];
    char pad_034_guess[0x114];
    int entries_guess[1024];
    int count_guess;

    // EXTERNAL: TITANIUM 0x00435A54 Manager_guess::Initialize_guess
    void Initialize_guess(char* value);
    Manager_guess* CopyData_guess(char* value);
    Manager_guess* CopyData_guess(const CopyTemp_guess& value) {
        return CopyData_guess((char*)&value);
    }
    Manager_guess* CopyAll_guess(Manager_guess* source);
    int GetMenu_guess(int index);
};

// Assigns a frame's texture block (0x00435A54) and rect (+0x18) from `value`; returns this.
// FUNCTION: TITANIUM 0x004DAFBF
Manager_guess* Manager_guess::CopyData_guess(char* value) {
    int scratch_guess[4];
    Initialize_guess(value);
    pair_guess.Copy_guess(scratch_guess, value + 0x18);
    return this;
}

// Texture-animation frame assignment: copies the three trailing values (+0x28..+0x30), then the texture
// block and rect through a temporary (0x004DAF9E, 0x004DAFBF). The frame-list grow and copy routines
// (0x004DB9F4, 0x004DBAE8) use it per element.
// FUNCTION: TITANIUM 0x004DB55A
Manager_guess* Manager_guess::CopyAll_guess(Manager_guess* source) {
    values_028_guess[0] = source->values_028_guess[0];
    values_028_guess[1] = source->values_028_guess[1];
    values_028_guess[2] = source->values_028_guess[2];
    CopyData_guess(CopyTemp_guess((char*)source));
    return this;
}

// Context menu manager (0x99D414): returns the menu registered under id `index` (+0x148 table, count at
// +0x1148), or 0 when the id is out of range. The bandolier window uses it to enable its menu items;
// the chat manager and chat window reach their menus the same way.
// FUNCTION: TITANIUM 0x004DAFEA
int Manager_guess::GetMenu_guess(int index) {
    if (index < count_guess && index >= 0)
        return entries_guess[index];
    return 0;
}

struct OwnedEntry_guess {
    virtual ~OwnedEntry_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 FreeObject_guess
void __cdecl FreeObject_guess(void* memory_guess);

struct OwnerBase_guess {
    char pad_004_guess[0x60];
    unsigned int style_064_guess;
    char pad_068_guess[0x124 - 0x68];
    void* piece_124_guess;
    char pad_128_guess[0x158 - 0x128];
    int field_158_guess;
    // EXTERNAL: TITANIUM 0x005A3850 OwnerBase_guess::OwnerBase_guess
    OwnerBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 OwnerBase_guess::~OwnerBase_guess
    virtual ~OwnerBase_guess();
    CSidlScreenWnd* Sidl_guess() { return (CSidlScreenWnd*)this; }
};

struct DisplayButton_guess {
    char pad_000_guess[0x16C];
    OwnedEntry_guess* anim_16c_guess;
};

struct Owner_guess : OwnerBase_guess {
    CXWnd* button_15c_guess;
    CXWnd* button_160_guess;
    CXWnd* button_164_guess;
    CXWnd* button_168_guess;
    CXWnd* check_16c_guess;
    DisplayButton_guess* rows_170_guess[4];
    CListWnd* list_180_guess;
    OwnedEntry_guess* entries_184_guess[4];
    int menu_194_guess;
    char rename_198_guess;
    Owner_guess(CXWnd* parent);
    // EXTERNAL: TITANIUM 0x0064FAC8 ??_7Owner_guess@@6B@
    virtual ~Owner_guess();
    void* Delete_guess(unsigned int flags_guess);
};

// Bandolier window destructor: deletes the four A_DragItem icon animations its constructor made for
// DisplayButton0-3 (+0x184).
// FUNCTION: TITANIUM 0x004DB008
Owner_guess::~Owner_guess() {
    for (int index_guess = 0; index_guess < 4; ++index_guess) {
        if (entries_184_guess[index_guess] != 0) {
            delete entries_184_guess[index_guess];
            entries_184_guess[index_guess] = 0;
        }
    }
}

// Scalar deleting destructor of the bandolier window (vtable 0x64FAC8 slot 1): runs the destructor
// (0x004DB008) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004DB5B1
void* Owner_guess::Delete_guess(unsigned int flags_guess) {
    this->Owner_guess::~Owner_guess();
    if ((flags_guess & 1) != 0)
        FreeObject_guess(this);
    return this;
}

struct Target_guess {
    char pad_000_guess[0x198];
    char field_198_guess;
    void SetField_guess(char value);
};

struct Group_guess;

struct ContextSub_guess {
    // EXTERNAL: TITANIUM 0x0041BABC ContextSub_guess::HasItemId_guess
    char HasItemId_guess(int count_guess);
};

struct Context_guess {
    char pad_000_guess[0xC280];
    ContextSub_guess sub_c280_guess;
    // EXTERNAL: TITANIUM 0x005F0C30 Context_guess::GetGroup_guess
    Group_guess* GetGroup_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004BF5BA Context_guess::UseBandolier_guess
    void UseBandolier_guess(int index);
    // EXTERNAL: TITANIUM 0x004BAE50 Context_guess::GetBandolierCount_guess
    int GetBandolierCount_guess();
    // EXTERNAL: TITANIUM 0x005F0C30 Context_guess::GetLabel_guess
    const char* GetLabel_guess(int index);
    // EXTERNAL: TITANIUM 0x004BAE54 Context_guess::ReplaceBandolierItem_guess
    void ReplaceBandolierItem_guess(int a_guess, int b_guess, int c_guess, int* data_guess);
    // EXTERNAL: TITANIUM 0x004BAEEE Context_guess::DeleteBandolier_guess
    void DeleteBandolier_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004BEC4E Context_guess::SaveBandolier_guess
    int SaveBandolier_guess(char* name_guess);
    // EXTERNAL: TITANIUM 0x004BD3E5 Context_guess::CreateBandolier_guess
    void CreateBandolier_guess(int index_guess, char* name_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatText_guess
void __cdecl FormatText_guess(CXStr* out_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0046BC70 SetSocial_guess
int __cdecl SetSocial_guess(const char* left_guess, const char* right_guess,
    int mode_guess, int limit_guess);

struct Widget_guess {
    char pad_000_guess[0x180];
    CListWnd* source_180_guess;
    void Update_guess();
    void ShowCurrent_guess();
};

#define g_context_guess EQ_GLOBAL(Context_guess*, 0x00905D00)
#define g_text_guess EQ_ARRAY(char, 0x0063F53F)

// Add (button and menu item 2): opens the text entry window (0x850C80, tu_224) for a set name of at most
// 30 characters, prompt string 0x2483. The answer comes back as notification 0x21; with `value` 0 it
// saves the current weapons into the selected set (0x4BD3E5).
// FUNCTION: TITANIUM 0x004DB05D
void Target_guess::SetField_guess(char value) {
    if (pinstCTextEntryWnd_guess != 0) {
        field_198_guess = value;
        pinstCTextEntryWnd_guess->Activate_guess(this, 4,
            pStringTable->getString(0x2483, 0), 1, 0x1e,
            g_text_guess);
    }
}

// Use (button and menu item 1): equips the selected set (0x4BF5BA).
// FUNCTION: TITANIUM 0x004DB0A1
void Widget_guess::Update_guess() {
    if (source_180_guess != 0) {
        int index_guess = source_180_guess->GetCurSel();
        if (index_guess >= 0)
            g_context_guess->UseBandolier_guess(index_guess);
    }
}

struct Report_guess {
    void MakeHotButton_guess(int index_guess);
};

// Make hot button (menu item 4): saves a social named after the set whose text is strings 0x2459 and
// 0x245E plus the set name. SetSocial_guess (0x46BC70, tu_046) stores a social in the
// first free or same-named of the 120 slots and returns it, -1 when all are full; the chat line
// (string 0x33E2 or 0x33E3) reports which.
// FUNCTION: TITANIUM 0x004DB0C1
void Report_guess::MakeHotButton_guess(int index_guess) {
    if (index_guess >= 0 && index_guess < g_context_guess->GetBandolierCount_guess()) {
        CXStr text;
        FormatText_guess(&text, "%s %s %s",
            pStringTable->getString(0x2459, 0),
            pStringTable->getString(0x245e, 0),
            g_context_guess->GetLabel_guess(index_guess));
        int cmp_guess = SetSocial_guess(
            g_context_guess->GetLabel_guess(index_guess), text, 0, -1);
        if (cmp_guess >= 0)
            pEverQuest->dsp_chat(pStringTable->getString(0x33e2, 0));
        else
            pEverQuest->dsp_chat(pStringTable->getString(0x33e3, 0));
    }
}

struct Slot_guess {
    int count_000_guess;
    int value_004_guess;
    char text_008_guess[0x40];
};

struct Group_guess {
    char pad_000_guess[0x20];
    Slot_guess slots_020_guess[4];
};

struct Row_guess {
    char pad_000_guess[0x78];
    CXStr label_078_guess;
    int pad_07c_guess;
    int color_080_guess;
};

struct Control_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Control_guess::SetValue_guess
    void SetValue_guess(int value_guess);
};

struct Panel_guess {
    char pad_000_guess[0x170];
    Row_guess* rows_170_guess[4];
    CListWnd* source_180_guess;
    Control_guess* controls_184_guess[4];
    void RefreshRows_guess();
    void RebuildList_guess();
    void Refresh_guess(int unused_guess, int* data_guess);
    void PickAndRebuild_guess();
};

// Shows the selected set on DisplayButton0-3: icon, item name and a colour. Green means you carry the
// item (0x41BABC searches 31 inventory entries for its id), red means you don't, white is an empty slot.
// FUNCTION: TITANIUM 0x004DB1A2
void Panel_guess::RefreshRows_guess() {
    if (source_180_guess != 0) {
        int index_guess = source_180_guess->GetCurSel();
        if (index_guess >= 0) {
            for (int row_guess = 0; row_guess < 4; ++row_guess) {
                if (rows_170_guess[row_guess] != 0) {
                    // 20 sets; a selection past them shows four empty slots.
                    if (index_guess < 0x14) {
                        controls_184_guess[row_guess]->SetValue_guess(
                            g_context_guess->GetGroup_guess(index_guess)
                                // Item icon ids start at 500; the animation cell is the 0-based icon.
                                ->slots_020_guess[row_guess].value_004_guess - 500);
                        {
                            CXStr text_guess(
                                g_context_guess->GetGroup_guess(index_guess)
                                    ->slots_020_guess[row_guess].text_008_guess);
                            Row_guess* row = rows_170_guess[row_guess];
                            row->label_078_guess = text_guess;
                        }
                        if (g_context_guess->GetGroup_guess(index_guess)
                                ->slots_020_guess[row_guess].count_000_guess > 0) {
                            if (g_context_guess->sub_c280_guess.HasItemId_guess(
                                    g_context_guess->GetGroup_guess(index_guess)
                                        ->slots_020_guess[row_guess].count_000_guess) != '\0')
                                rows_170_guess[row_guess]->color_080_guess = 0xff00ff00;
                            else
                                rows_170_guess[row_guess]->color_080_guess = 0xffff0000;
                        } else {
                            rows_170_guess[row_guess]->color_080_guess = -1;
                        }
                    } else {
                        controls_184_guess[row_guess]->SetValue_guess(-1);
                        rows_170_guess[row_guess]->color_080_guess = -1;
                    }
                }
            }
        }
    }
}

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

// Refills WeaponSetList with the set names (string 0x247A for an unnamed set), keeps the selection and
// redraws the slots. Virtual slot 76 of the list clears it (probably CListWnd::DeleteAll).
// FUNCTION: TITANIUM 0x004DB2D1
void Panel_guess::RebuildList_guess() {
    if (source_180_guess != 0) {
        int selection_guess = source_180_guess->GetCurSel();
        ((ListSlots_guess*)source_180_guess)->Slot76_guess();
        for (int index_guess = 0; index_guess < g_context_guess->GetBandolierCount_guess(); ++index_guess) {
            if (*g_context_guess->GetLabel_guess(index_guess) != '\0') {
                CXStr text_guess(g_context_guess->GetLabel_guess(index_guess));
                source_180_guess->AddString(text_guess, -1, 0, 0);
            } else {
                CXStr text_guess(pStringTable->getString(0x247a, 0));
                source_180_guess->AddString(text_guess, -1, 0, 0);
            }
        }
        if (selection_guess < 0)
            selection_guess = 0;
        source_180_guess->SetCurSel(selection_guess);
        RefreshRows_guess();
    }
}

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();
// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
int __cdecl LoadStringFromUIIniFile_guess(const char* file_guess, const char* section_guess,
    const char* key_guess, char* out_guess, int size_guess, int default_guess);
// EXTERNAL: TITANIUM 0x0060BF20 IniWrite_guess
void __cdecl IniWrite_guess(const char* file_guess, const char* section_guess,
    const char* value_guess);

#define g_text6410_guess EQ_ARRAY(char, 0x006410A8)
#define g_text645_guess EQ_ARRAY(char, 0x00645EB4)

struct AutoSwap_guess {
    char pad_000_guess[0x140];
    CXStr path_140_guess;
    char pad_144_guess[0x16C - 0x144];
    CButtonWnd* check_16c_guess;

    void LoadAutoSwapSetting_guess();
    void SaveSetting_guess();
};

// Restores the AutoSwap check box from [AutoSwap] in the character INI (+0x140); a value starting with
// '1', 't' or 'T' turns it on, the default is "0".
// FUNCTION: TITANIUM 0x004DB403
void AutoSwap_guess::LoadAutoSwapSetting_guess() {
    if (check_16c_guess != 0) {
        if (NewUIINI() != 0) {
            char value_guess[512];
            char key_guess[512];
            sprintf(key_guess, "%s", g_text6410_guess);
            int ret_guess = LoadStringFromUIIniFile_guess(path_140_guess, "AutoSwap", key_guess,
                value_guess, 0x1ff, 1);
            check_16c_guess->SetCheck(value_guess[0] == '1' || value_guess[0] == 't'
                || value_guess[0] == 'T');
        }
    }
}

// Saves the AutoSwap check box to the character INI as "1" or "0".
// FUNCTION: TITANIUM 0x004DB4AA
void AutoSwap_guess::SaveSetting_guess() {
    if (NewUIINI() != 0) {
        char value_guess[256];
        sprintf(value_guess, "%s",
            (check_16c_guess != 0 && check_16c_guess->Checked) ? g_text645_guess : g_text6410_guess);
        IniWrite_guess(path_140_guess, "AutoSwap", value_guess);
    }
}

struct CopyInit_guess {
    CopyBlock_guess first_guess;
    int values_018_guess[4];
    int values_028_guess[3];

    CopyInit_guess* InitializeBase_guess();
    CopyInit_guess* InitializeAll_guess();
};

#define g_defaultCopyBlock_guess EQ_GLOBAL(CopyBlock_guess, 0x009915A0)

struct Element_guess {
    char data_guess[0x34];
    // EXTERNAL: TITANIUM 0x004DB543 Element_guess::Element_guess
    Element_guess();
    // EXTERNAL: TITANIUM 0x004D91ED Element_guess::~Element_guess
    ~Element_guess();
    // EXTERNAL: TITANIUM 0x004DB55A ??4Element_guess@@QAEAAU0@ABU0@@Z
    Element_guess& operator=(const Element_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004D91ED Element_guess::Destroy_guess
    void Destroy_guess();
    void* VectorDelete_guess(unsigned char flags_guess);
};

struct Element_guess;

struct ElementOwner_guess {
	int count_0000_guess;
	Element_guess* elements_0004_guess;
	int capacity_008_guess;
	char field_00C_guess;
	void ReallocateForCount_guess(int count_guess);
	ElementOwner_guess* Copy_guess(ElementOwner_guess* source_guess);
    void Clear_guess();
};

struct ReferenceValue_guess {
	int value_guess;
	// EXTERNAL: TITANIUM 0x00571F70 ReferenceValue_guess::Copy_guess
	void Copy_guess(ReferenceValue_guess* source_guess);
};

struct CopyState_guess {
	int value_000_guess;
	ReferenceValue_guess reference_guess;
	ElementOwner_guess entries_guess;
	int value_018_guess;
	int value_01C_guess;
	int value_020_guess;
	int value_024_guess;
	int value_028_guess;
	char value_02C_guess;
	char value_02D_guess;
	char value_02E_guess;
	char value_02F_guess;
	int value_030_guess;
	int value_034_guess;
	int value_038_guess;
	Pair_guess tail_guess;
	CopyState_guess* Copy_guess(CopyState_guess* source_guess);
};

// Default state of a frame's first part: the texture block copied from the empty default at 0x9915A0
// and a zero rect (+0x18..+0x24).
// FUNCTION: TITANIUM 0x004DB524
CopyInit_guess* CopyInit_guess::InitializeBase_guess() {
    first_guess.Copy_guess(&g_defaultCopyBlock_guess);
    values_018_guess[0] = 0;
    values_018_guess[1] = 0;
    values_018_guess[2] = 0;
    values_018_guess[3] = 0;
    return this;
}

// Default constructor of a texture-animation frame: the empty texture block and rect (0x004DB524), and
// the three trailing values zeroed. Passed as the element constructor when the frame list grows.
// FUNCTION: TITANIUM 0x004DB543
CopyInit_guess* CopyInit_guess::InitializeAll_guess() {
    InitializeBase_guess();
    values_028_guess[0] = 0;
    values_028_guess[1] = 0;
    values_028_guess[2] = 0;
    return this;
}

struct ElementAllocationPrefix_guess {
    unsigned int count_guess;
};

// EXTERNAL: TITANIUM 0x0060D6E5 VectorDestructorIterator_guess
void __stdcall VectorDestructorIterator_guess(Element_guess* first_guess,
    unsigned int size_guess, int count_guess,
    void (Element_guess::*destroy_guess)());
// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
void __cdecl FreeArray_guess(void* memory_guess);

// Bandolier update with action 4: stores the set it carries (0x4BAE54) and refills the list.
// FUNCTION: TITANIUM 0x004DB5D5
void Panel_guess::Refresh_guess(int unused_guess, int* data_guess) {
    if (data_guess[0] == 4) {
        g_context_guess->ReplaceBandolierItem_guess(data_guess[1], data_guess[2], data_guess[3],
            data_guess + 4);
        RebuildList_guess();
    }
}

// Delete (button and menu item 3): removes the selected set (0x4BAEEE sends bandolier action 1) and
// refills the list.
// FUNCTION: TITANIUM 0x004DB604
void Panel_guess::PickAndRebuild_guess() {
    if (source_180_guess != 0) {
        int index_guess = source_180_guess->GetCurSel();
        if (index_guess >= 0) {
            g_context_guess->DeleteBandolier_guess(index_guess);
            RebuildList_guess();
        }
    }
}

// MkHotButton: makes the social for the selected set.
// FUNCTION: TITANIUM 0x004DB630
void Widget_guess::ShowCurrent_guess() {
    if (source_180_guess != 0) {
        int index_guess = source_180_guess->GetCurSel();
        if (index_guess >= 0)
            ((Report_guess*)this)->MakeHotButton_guess(index_guess);
    }
}

// Compiler vector deleting destructor for 0x34-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x004DB650
void* Element_guess::VectorDelete_guess(unsigned char flags_guess) {
    if ((flags_guess & 2) != 0) {
        ElementAllocationPrefix_guess* allocation_guess =
            (ElementAllocationPrefix_guess*)this - 1;
        VectorDestructorIterator_guess(this, 0x34, allocation_guess->count_guess,
            &Element_guess::Destroy_guess);
        if ((flags_guess & 1) != 0)
            FreeArray_guess(allocation_guess);
        return allocation_guess;
    }

    Destroy_guess();
    if ((flags_guess & 1) != 0)
        FreeObject_guess(this);
    return this;
}

struct TextSource_guess {
    // EXTERNAL: TITANIUM 0x00560D80 TextSource_guess::GetEntryText_guess
    CXStr GetEntryText_guess() const;
};

struct Toggle_guess {
    // EXTERNAL: TITANIUM 0x005BFF10 Toggle_guess::Enable_guess
    void Enable_guess(int index_guess, bool enable_guess);
};

struct MousePoint_guess {
    int x_guess;
    int y_guess;
};

struct MouseState_guess {
    char pad_000_guess[0x74];
    MousePoint_guess pos_074_guess;
};

struct Registry_guess {
    // EXTERNAL: TITANIUM 0x005ADC20 Registry_guess::Popup_guess
    void Popup_guess(int id_guess, MousePoint_guess* pos_guess, CXWnd* owner_guess);
    // EXTERNAL: TITANIUM 0x005AD5A0 Registry_guess::AddMenu_guess
    int AddMenu_guess(struct ContextMenu_guess* menu_guess);
};

struct SelectMessage_guess {
    int type_guess;
    char selection_guess;
    char row_guess;
    short pad_guess;
    unsigned int flags_guess;
};

#define g_registry_guess EQ_GLOBAL(Manager_guess*, 0x0099D414)
#define g_popupRegistry_guess EQ_GLOBAL(Registry_guess*, 0x0099D414)
#define g_wndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_mouseState_guess EQ_GLOBAL(MouseState_guess*, 0x0099D3EC)
#define g_connection_guess EQ_ARRAY(char, 0x00905CA0)

struct GroupWnd_guess : CSidlScreenWnd {
    CXWnd* button_15c_guess;
    CXWnd* button_160_guess;
    CXWnd* button_164_guess;
    CXWnd* button_168_guess;
    CButtonWnd* check_16c_guess;
    CXWnd* rows_170_guess[4];
    CListWnd* list_180_guess;
    void* controls_184_guess[4];
    int entry_194_guess;
    char rename_198_guess;

    int WndNotification(CXWnd* sender, unsigned int message, void* data);
};

// Notification 1 is a left click, 3 a right click (it opens the menu). With AutoSwap checked, picking a
// set in the list equips it at once.
// FUNCTION: TITANIUM 0x004DB69B
int GroupWnd_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if (sender == check_16c_guess) {
            ((AutoSwap_guess*)this)->SaveSetting_guess();
        } else if (sender == button_15c_guess) {
            ((Target_guess*)this)->SetField_guess(0);
            return 1;
        } else if (sender == button_160_guess) {
            ((Panel_guess*)this)->PickAndRebuild_guess();
            return 1;
        } else if (sender == button_164_guess) {
            ((Widget_guess*)this)->Update_guess();
            return 1;
        } else if (sender == button_168_guess) {
            ((Widget_guess*)this)->ShowCurrent_guess();
            return 1;
        } else if (sender == list_180_guess) {
            if (check_16c_guess != 0 && check_16c_guess->Checked && list_180_guess != 0) {
                int index_guess = list_180_guess->GetCurSel();
                if (index_guess >= 0)
                    g_context_guess->UseBandolier_guess(index_guess);
            }
            ((Panel_guess*)this)->RefreshRows_guess();
            return 1;
        }
    // 0x18: a click on a DisplayButton (spell gems send the same code to cast). It sends bandolier
    // action 3 for that set and slot, with flag 2 when shift is held.
    } else if (message == 0x18) {
        for (int row_guess = 0; row_guess < 4; ++row_guess) {
            if (sender == rows_170_guess[row_guess] && list_180_guess != 0) {
                int index_guess = list_180_guess->GetCurSel();
                if (index_guess >= 0) {
                    SelectMessage_guess message_guess;
                    message_guess.flags_guess = 0;
                    if (g_wndManager_guess->GetKeyboardFlags() & 1)
                        message_guess.flags_guess |= 2;
                    message_guess.row_guess = (char)row_guess;
                    message_guess.type_guess = 3;
                    message_guess.selection_guess = (char)index_guess;
                    EQSendMessage(g_connection_guess, OP_Bandolier, &message_guess,
                        sizeof(message_guess), 1);
                }
            }
        }
    // 0x21: the text entry window's answer; data 1 means OK.
    } else if (message == 0x21) {
        if ((int)data == 1) {
            CXStr name_guess = ((TextSource_guess*)sender)->GetEntryText_guess();
            if (rename_198_guess) {
                ((Report_guess*)this)->MakeHotButton_guess(
                    g_context_guess->SaveBandolier_guess(name_guess));
            } else if (list_180_guess != 0) {
                int index_guess = list_180_guess->GetCurSel();
                if (index_guess >= 0)
                    g_context_guess->CreateBandolier_guess(index_guess, name_guess);
            }
        }
    } else if (message == 3) {
        if (sender == list_180_guess) {
            if (entry_194_guess != -1) {
                int index_guess = list_180_guess->GetCurSel();
                bool empty_guess = *g_context_guess->GetLabel_guess(index_guess) == '\0';
                Toggle_guess* toggle_guess =
                    (Toggle_guess*)g_registry_guess->GetMenu_guess(entry_194_guess);
                toggle_guess->Enable_guess(0, index_guess > -1 && !empty_guess);
                toggle_guess->Enable_guess(1, index_guess > -1 && empty_guess);
                toggle_guess->Enable_guess(2, index_guess > -1 && !empty_guess);
                toggle_guess->Enable_guess(3, index_guess > -1 && !empty_guess);
                MousePoint_guess pos_guess = g_mouseState_guess->pos_074_guess;
                g_popupRegistry_guess->Popup_guess(entry_194_guess, &pos_guess, this);
            }
            if (check_16c_guess != 0 && check_16c_guess->Checked && list_180_guess != 0) {
                int index_guess = list_180_guess->GetCurSel();
                if (index_guess >= 0)
                    g_context_guess->UseBandolier_guess(index_guess);
            }
            ((Panel_guess*)this)->RefreshRows_guess();
        }
    // 0x14: a context-menu choice; data is the item id from the constructor (1 Use, 2 Add, 3 Delete, 4 hot
    // button).
    } else if (message == 0x14) {
        if (sender == (CXWnd*)g_registry_guess->GetMenu_guess(entry_194_guess)) {
            switch ((int)data) {
            case 1:
                ((Widget_guess*)this)->Update_guess();
                break;
            case 2:
                ((Target_guess*)this)->SetField_guess(0);
                break;
            case 3:
                ((Panel_guess*)this)->PickAndRebuild_guess();
                break;
            case 4:
                ((Widget_guess*)this)->ShowCurrent_guess();
                break;
            }
            return 1;
        }
    }
    return CSidlScreenWnd::WndNotification(sender, message, data);
}

// Grows the element array: when `count_guess` exceeds the element count (+0) or nothing is allocated,
// allocates that many, copies the old elements over and frees the old block (+8 = new capacity). If the
// allocation fails the old block is freed and +4, +8 and +0xC are cleared; the count at +0 stays.
// FUNCTION: TITANIUM 0x004DB9F4
// @early-stop: unknown, structural ndiff=65
void ElementOwner_guess::ReallocateForCount_guess(int count_guess) {
    Element_guess* fresh_guess;
    int i_guess;
    if (count_guess != 0 && (count_guess > count_0000_guess || elements_0004_guess == 0)) {
        fresh_guess = new Element_guess[count_guess];
        if (fresh_guess == 0) {
            if (elements_0004_guess != 0)
                elements_0004_guess->VectorDelete_guess(3);
            elements_0004_guess = 0;
            capacity_008_guess = 0;
            field_00C_guess = 0;
        } else {
            if (elements_0004_guess != 0 && count_0000_guess > 0) {
                for (i_guess = 0; i_guess < count_0000_guess; ++i_guess)
                    fresh_guess[i_guess] = elements_0004_guess[i_guess];
            }
            if (elements_0004_guess != 0)
                elements_0004_guess->VectorDelete_guess(3);
            elements_0004_guess = fresh_guess;
            capacity_008_guess = count_guess;
        }
    }
}

// Empties a texture animation's frame list: deletes the frame array (vector delete, flag 3) and zeroes
// the pointer, count and capacity. Animation reset (0x004FD8BC) and frame-list assignment call it.
// FUNCTION: TITANIUM 0x004DBACA
void ElementOwner_guess::Clear_guess() {
    if (elements_0004_guess != 0)
		elements_0004_guess->VectorDelete_guess(3);
    elements_0004_guess = 0;
    capacity_008_guess = 0;
    count_0000_guess = 0;
}

// Array assignment: frees this array (0x004DBACA), then sizes it to `source_guess` and copies each
// element with 0x004DB55A, and the count.
// FUNCTION: TITANIUM 0x004DBAE8
ElementOwner_guess* ElementOwner_guess::Copy_guess(
	ElementOwner_guess* source_guess) {
	if (this != source_guess) {
		Clear_guess();
		if (source_guess->count_0000_guess != 0) {
			ReallocateForCount_guess(source_guess->count_0000_guess);
			if (elements_0004_guess != 0) {
				int index_guess = 0;
				if (source_guess->count_0000_guess > 0) {
					do {
						((Manager_guess*)&elements_0004_guess[index_guess])
							->CopyAll_guess((Manager_guess*)&
								source_guess->elements_0004_guess[index_guess]);
						++index_guess;
					} while (index_guess < source_guess->count_0000_guess);
				}
			}
			count_0000_guess = source_guess->count_0000_guess;
		}
	}
	return this;
}

// Copies a whole texture animation (the shape FindAnimation returns), frames included.
// FUNCTION: TITANIUM 0x004DBB3B
CopyState_guess* CopyState_guess::Copy_guess(CopyState_guess* source_guess) {
	int scratch_guess[4];
	reference_guess.Copy_guess(&source_guess->reference_guess);
	entries_guess.Copy_guess(&source_guess->entries_guess);
	value_018_guess = source_guess->value_018_guess;
	value_01C_guess = source_guess->value_01C_guess;
	value_020_guess = source_guess->value_020_guess;
	value_024_guess = source_guess->value_024_guess;
	value_028_guess = source_guess->value_028_guess;
	value_02C_guess = source_guess->value_02C_guess;
	value_02D_guess = source_guess->value_02D_guess;
	value_02E_guess = source_guess->value_02E_guess;
	value_02F_guess = source_guess->value_02F_guess;
	value_030_guess = source_guess->value_030_guess;
	value_034_guess = source_guess->value_034_guess;
	value_038_guess = source_guess->value_038_guess;
	tail_guess.Copy_guess(scratch_guess, &source_guess->tail_guess);
	return this;
}

struct Animation_guess : OwnedEntry_guess {
    char pad_004_guess[0x48];
    // EXTERNAL: TITANIUM 0x005B1D90 Animation_guess::Animation_guess
    Animation_guess();
    // EXTERNAL: TITANIUM 0x005B1AB0 Animation_guess::SetCurCell_guess
    void SetCurCell_guess(int cell_guess);
};

struct SidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 SidlManager_guess::FindAnimation_guess
    CopyState_guess* FindAnimation_guess(const CXStr& name_guess);
};

struct MenuRect_guess {
    int left, top, right, bottom;
    MenuRect_guess(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

struct ContextMenu_guess {
    char pad_000_guess[0x1A8];
    // EXTERNAL: TITANIUM 0x005BFAE0 ContextMenu_guess::ContextMenu_guess
    ContextMenu_guess(CXWnd* parent_guess, int id_guess, const MenuRect_guess& rect_guess);
    // EXTERNAL: TITANIUM 0x005BFCF0 ContextMenu_guess::AddMenuItem_guess
    int AddMenuItem_guess(const CXStr& text_guess, int id_guess, int checked_guess, int color_guess);
};

#define g_sidlManager_guess EQ_GLOBAL(SidlManager_guess*, 0x0099D3F4)

// Bandolier window constructor: finds the buttons and AutoSwapButton, gives each of the four
// DisplayButtons its own stopped copy of A_DragItem, sets up WeaponSetList and its right-click menu (ids
// 1-4), then restores the auto-swap check box from the INI (0x004DB403).
// FUNCTION: TITANIUM 0x004DBBC0
Owner_guess::Owner_guess(CXWnd* parent)
    : OwnerBase_guess(parent, "BandolierWnd", -1, 1, 0) {
    style_064_guess |= 0x10000;
    field_158_guess = 0x41;
    button_15c_guess = 0;
    button_160_guess = 0;
    button_164_guess = 0;
    button_168_guess = 0;
    check_16c_guess = 0;
    list_180_guess = 0;
    for (int i = 0; i < 4; ++i) {
        rows_170_guess[i] = 0;
        entries_184_guess[i] = 0;
    }
    if (piece_124_guess != 0) {
        Sidl_guess()->CreateChildrenFromSidl();
        button_15c_guess = Sidl_guess()->GetChildItem("AddButton");
        button_160_guess = Sidl_guess()->GetChildItem("DeleteButton");
        button_164_guess = Sidl_guess()->GetChildItem("UseButton");
        button_168_guess = Sidl_guess()->GetChildItem("MkHotButton");
        // Checked: choosing a set in the list equips it.
        check_16c_guess = Sidl_guess()->GetChildItem("AutoSwapButton");
        // Each DisplayButton gets its own copy of this animation to draw the item icon.
        CopyState_guess* anim_guess = g_sidlManager_guess->FindAnimation_guess("A_DragItem");
        for (int index_guess = 0; index_guess < 4; ++index_guess) {
            CXStr name_guess;
            FormatText_guess(&name_guess, "DisplayButton%d", index_guess);
            rows_170_guess[index_guess] =
                (DisplayButton_guess*)Sidl_guess()->GetChildItem(name_guess);
            entries_184_guess[index_guess] = new Animation_guess;
            if (anim_guess != 0) {
                ((CopyState_guess*)entries_184_guess[index_guess])->Copy_guess(anim_guess);
                ((Animation_guess*)entries_184_guess[index_guess])->SetCurCell_guess(-1);
            }
            if (rows_170_guess[index_guess] != 0)
                rows_170_guess[index_guess]->anim_16c_guess = entries_184_guess[index_guess];
        }
        list_180_guess = (CListWnd*)Sidl_guess()->GetChildItem("WeaponSetList");
        if (list_180_guess != 0) {
            list_180_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            list_180_guess->WindowStyle &= ~0x200000;
        }
        // The list's right-click menu: Use, Add, Delete, make hot button (item ids 1-4).
        ContextMenu_guess* menu_guess = new ContextMenu_guess(0, 0, MenuRect_guess(0, 0, 50, 10));
        menu_guess->AddMenuItem_guess(pStringTable->getString(0x245e, 0), 1, 0, -1);
        menu_guess->AddMenuItem_guess(pStringTable->getString(0x245a, 0), 2, 0, -1);
        menu_guess->AddMenuItem_guess(pStringTable->getString(0x245d, 0), 3, 0, -1);
        menu_guess->AddMenuItem_guess(pStringTable->getString(0x2470, 0), 4, 0, -1);
        menu_194_guess = g_popupRegistry_guess->AddMenu_guess(menu_guess);
        rename_198_guess = 0;
        ((AutoSwap_guess*)this)->LoadAutoSwapSetting_guess();
    }
}

