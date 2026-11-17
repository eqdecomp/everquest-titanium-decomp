// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 176: a hint from compare/tumap.py.
// CJournalCatWnd (screen "JournalCatWnd"), the journal's category editor: CJournalCatWnd_guess is the window and
// CJournalNPCWnd_guess is CJournalNPCWnd (0x850CA4, tu_177), whose journal data keeps the category records
// (Record_guess: id, 16-byte name, 256-byte description). The first function is CItemExpTransferWnd's
// WndNotification (CItemExpTransferWnd_guess = tu_175's CJournalCatWnd_guess), filed here by address.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/wnd/CTipWnd.h"

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(const char* file_guess, const char* key_guess, const char* def_guess, char* out_guess, int size_guess, int mode_guess);

// EXTERNAL: TITANIUM 0x0060BF20 ApplySettingAlt_guess
void __cdecl ApplySettingAlt_guess(const char* file_guess, const char* key_guess, const char* value_guess);

typedef int (__cdecl *Compare_guess)(const void*, const void*);

// EXTERNAL: TITANIUM 0x0060EE40 _qsort
void __cdecl _qsort(void* base_guess, unsigned int count_guess, unsigned int size_guess, Compare_guess compare_guess);

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory_guess);

struct Member_guess {
    int capacity_guess;   // 0x0
    void* data_guess;     // 0x4
    int unknown_guess;    // 0x8
    unsigned char valid_guess; // 0xc
    Member_guess() {
        data_guess = 0;
        capacity_guess = 0;
        unknown_guess = 0;
        valid_guess = 1;
    }
    ~Member_guess() ;
    // EXTERNAL: TITANIUM 0x0050F3F6 Member_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0050319B Member_guess::SetAt_guess
    void SetAt_guess(int index_guess, int* value_guess);
    // EXTERNAL: TITANIUM 0x004EB924 Member_guess::At_guess
    int& At_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00405492 Member_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
};

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3100 Base_guess::~Base_guess
    virtual ~Base_guess() ;
    // EXTERNAL: TITANIUM 0x005A3900 ??0Base_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    Base_guess(CXWnd* parent_guess, const CXStr& screen_guess);
};

struct CategoryList_guess : CListWnd {
    char pad_140_guess[0x15c - 0x140];
    unsigned char field_15c_guess;   // 0x15c
    char pad_15d_guess[0x16c - 0x15d];
    unsigned int color_16c_guess;    // 0x16c
    // EXTERNAL: TITANIUM 0x0059BB50 CategoryList_guess::GetSelectedIndices_guess
    void GetSelectedIndices_guess(void* indices_guess);
    // EXTERNAL: TITANIUM 0x0059B360 CategoryList_guess::SetItemText
    void SetItemText(int index_guess, int column_guess, const CXStr& text_guess);
};

struct EditWnd_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x004D7EBC EditWnd_guess::SetMaxChars_guess
    void SetMaxChars_guess(int count_guess);
};

// Edit box virtual slots: slot 63 (0xFC) sets the text.
struct EditSlots_guess {
    virtual void S00_guess(); virtual void S01_guess(); virtual void S02_guess(); virtual void S03_guess();
    virtual void S04_guess(); virtual void S05_guess(); virtual void S06_guess(); virtual void S07_guess();
    virtual void S08_guess(); virtual void S09_guess(); virtual void S10_guess(); virtual void S11_guess();
    virtual void S12_guess(); virtual void S13_guess(); virtual void S14_guess(); virtual void S15_guess();
    virtual void S16_guess(); virtual void S17_guess(); virtual void S18_guess(); virtual void S19_guess();
    virtual void S20_guess(); virtual void S21_guess(); virtual void S22_guess(); virtual void S23_guess();
    virtual void S24_guess(); virtual void S25_guess(); virtual void S26_guess(); virtual void S27_guess();
    virtual void S28_guess(); virtual void S29_guess(); virtual void S30_guess(); virtual void S31_guess();
    virtual void S32_guess(); virtual void S33_guess(); virtual void S34_guess(); virtual void S35_guess();
    virtual void S36_guess(); virtual void S37_guess(); virtual void S38_guess(); virtual void S39_guess();
    virtual void S40_guess(); virtual void S41_guess(); virtual void S42_guess(); virtual void S43_guess();
    virtual void S44_guess(); virtual void S45_guess(); virtual void S46_guess(); virtual void S47_guess();
    virtual void S48_guess(); virtual void S49_guess(); virtual void S50_guess(); virtual void S51_guess();
    virtual void S52_guess(); virtual void S53_guess(); virtual void S54_guess(); virtual void S55_guess();
    virtual void S56_guess(); virtual void S57_guess(); virtual void S58_guess(); virtual void S59_guess();
    virtual void S60_guess(); virtual void S61_guess(); virtual void S62_guess();
    virtual void SetText_guess(const CXStr& text_guess);
    virtual void S64_guess(); virtual void S65_guess(); virtual void S66_guess(); virtual void S67_guess();
    virtual void S68_guess(); virtual void S69_guess(); virtual void S70_guess(); virtual void S71_guess();
    virtual void S72_guess(); virtual void S73_guess(); virtual void S74_guess(); virtual void S75_guess();
    virtual CXStr GetText_guess();
};

// EXTERNAL: TITANIUM 0x00656DC0 ??_7CJournalCatWnd_guess@@6B@
// 0x140: ini file name (a CXStr, constructed by the base).
struct Store_guess {
    char pad_guess[0x20];
};

struct CJournalCatWnd_guess : Base_guess {
    char pad0_guess[0x58];
    char state_guess;
    char pad1_guess[0x64 - 0x5d];
    unsigned int windowStyle_guess;  // 0x64
    char pad2_guess[0x124 - 0x68];
    void* sidlPiece_guess;     // 0x124
    char pad3_guess[0x140 - 0x128];
    Store_guess store_guess;   // 0x140
    CategoryList_guess* categoryList_guess;  // 0x160
    CXWnd* deleteButton_guess;     // 0x164
    CXWnd* addButton_guess;        // 0x168
    CXWnd* updateButton_guess;     // 0x16c
    EditWnd_guess* nameInput_guess;  // 0x170
    EditWnd_guess* descInput_guess;  // 0x174
    CXWnd* defaultChooser_guess;   // 0x178
    int selectedCategory_017c_guess;       // 0x17c
    int defaultCategory_0180_guess;       // 0x180
    int count_guess;          // 0x184
    Member_guess member_guess; // 0x188
    int sortColumn_0198_guess;       // 0x198
    unsigned char sortAscending_019c_guess; // 0x19c
    CJournalCatWnd_guess(CXWnd* parent_guess);
    void ClearControls_guess();
    void Reload_guess(bool flag_guess);
    void FillControls_guess(bool flag_guess);
    void ShowRecord_guess(int index_guess);
    void UpdateButtons_guess();
    unsigned char Reset_guess();
    void* Destroy_guess(unsigned char flags_guess);
    void CopyCategories_guess();
    void OnShow_guess();
    void LoadDefaultCategory_guess();
    void SaveDefaultCategory_guess();
    void SortCategories_guess(int column_guess, char ascending_guess);
    int WndNotification_guess(CXWnd* target_guess, int command_guess, int data_guess);
    // EXTERNAL: TITANIUM 0x005A2230 CJournalCatWnd_guess::WndNotification
    int WndNotification(CXWnd* target_guess, unsigned int command_guess, unsigned int data_guess);
    // EXTERNAL: TITANIUM 0x005A1880 CJournalCatWnd_guess::OnShow
    void OnShow();
    virtual ~CJournalCatWnd_guess() ;
};


struct ValueArray_guess {
    char pad_0000_guess[0x80c];
    int* values_080c_guess;    // 0x80c
    char pad_0810_guess[4];
    int count_0814_guess;      // 0x814
    // EXTERNAL: TITANIUM 0x0042E972 ValueArray_guess::GetValues_guess
    int* GetValues_guess();
    // EXTERNAL: TITANIUM 0x0042E871 ValueArray_guess::RemoveCategory_guess
    void RemoveCategory_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0042E929 ValueArray_guess::FindCategoryByName_guess
    int FindCategoryByName_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x0042EF4B ValueArray_guess::SetCategory_guess
    void SetCategory_guess(const char* name_guess, const char* text_guess, int id_guess);
};

struct CComboWnd_guess;
struct Selected_guess;

struct CJournalNPCWnd_guess {
    char pad_0000_guess[0x160];
    ValueArray_guess* array_160_guess;  // 0x160
    char pad_164_guess[0x180 - 0x164];
    Selected_guess* selected_180_guess; // 0x180
    char pad_184_guess[0x1a0 - 0x184];
    int chosen_1a0_guess;               // 0x1a0
    char pad_1a4_guess[0x1dc - 0x1a4];
    CComboWnd_guess* combo_1dc_guess;    // 0x1dc
    CComboWnd_guess* combo_1e0_guess;    // 0x1e0
    void FillCategoryCombos_guess();
    // EXTERNAL: TITANIUM 0x00524F87 CJournalNPCWnd_guess::Refresh_guess
    void Refresh_guess(int flag_guess);
};

#define pinstCJournalNPCWnd_guess EQ_GLOBAL(CJournalNPCWnd_guess*, 0x00850ca4)

struct Record_guess {
    int id_0000_guess;         // 0x0
    char name_guess[0x10];     // 0x4, text inline
    char text_guess[0x100];    // 0x14, text inline
};

// Slot 76 (0x130) is the list's virtual clear.
struct ListSlots_guess {
    virtual void S00_guess(); virtual void S01_guess(); virtual void S02_guess(); virtual void S03_guess();
    virtual void S04_guess(); virtual void S05_guess(); virtual void S06_guess(); virtual void S07_guess();
    virtual void S08_guess(); virtual void S09_guess(); virtual void S10_guess(); virtual void S11_guess();
    virtual void S12_guess(); virtual void S13_guess(); virtual void S14_guess(); virtual void S15_guess();
    virtual void S16_guess(); virtual void S17_guess(); virtual void S18_guess(); virtual void S19_guess();
    virtual void S20_guess(); virtual void S21_guess(); virtual void S22_guess(); virtual void S23_guess();
    virtual void S24_guess(); virtual void S25_guess(); virtual void S26_guess(); virtual void S27_guess();
    virtual void S28_guess(); virtual void S29_guess(); virtual void S30_guess(); virtual void S31_guess();
    virtual void S32_guess(); virtual void S33_guess(); virtual void S34_guess(); virtual void S35_guess();
    virtual void S36_guess(); virtual void S37_guess(); virtual void S38_guess(); virtual void S39_guess();
    virtual void S40_guess(); virtual void S41_guess(); virtual void S42_guess(); virtual void S43_guess();
    virtual void S44_guess(); virtual void S45_guess(); virtual void S46_guess(); virtual void S47_guess();
    virtual void S48_guess(); virtual void S49_guess(); virtual void S50_guess(); virtual void S51_guess();
    virtual void S52_guess(); virtual void S53_guess(); virtual void S54_guess(); virtual void S55_guess();
    virtual void S56_guess(); virtual void S57_guess(); virtual void S58_guess(); virtual void S59_guess();
    virtual void S60_guess(); virtual void S61_guess(); virtual void S62_guess(); virtual void S63_guess();
    virtual void S64_guess(); virtual void S65_guess(); virtual void S66_guess(); virtual void S67_guess();
    virtual void S68_guess(); virtual void S69_guess(); virtual void S70_guess(); virtual void S71_guess();
    virtual void S72_guess(); virtual void S73_guess(); virtual void S74_guess(); virtual void S75_guess();
    virtual void S76_guess();
};

// Combo box: list at +0x11C, insert/select helpers.
struct CComboWnd_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x0059C3A0 CComboWnd_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C3B0 CComboWnd_guess::GetText_guess
    CXStr GetText_guess();
    // EXTERNAL: TITANIUM 0x0059C3E0 CComboWnd_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 CComboWnd_guess::AddChoice_guess
    void AddChoice_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 CComboWnd_guess::SetCurSel_guess
    void SetCurSel_guess(int index_guess);
};

struct CXStrView_guess {
    // EXTERNAL: TITANIUM 0x00573B10 CXStrView_guess::Compare_guess
    int Compare_guess(const CXStr& other_guess, bool nocase_guess);
};

struct SelectedIndices_guess {
    int count_guess;
    int unknown_04_guess;
    unsigned int mask_guess;
    unsigned int shift_guess;
    int** pages_guess;
    int unknown_14_guess[2];
    // EXTERNAL: TITANIUM 0x0047C3AF SelectedIndices_guess::SelectedIndices_guess
    SelectedIndices_guess(int growth_guess);
    // EXTERNAL: TITANIUM 0x00406E7E SelectedIndices_guess::~SelectedIndices_guess
    ~SelectedIndices_guess();
};

// EXTERNAL: TITANIUM 0x00522A9B CompareA_guess
int __cdecl CompareA_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x00522AB7 CompareB_guess
int __cdecl CompareB_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x00522AD5 CompareC_guess
int __cdecl CompareC_guess(const void*, const void*);
// EXTERNAL: TITANIUM 0x00522AF1 CompareD_guess
int __cdecl CompareD_guess(const void*, const void*);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// The ItemExpTransferWnd object of tu_175: CSidlScreenWnd (0x15c) then a dialog
// action subobject (its vtable at 0x15c), then the two icon id pairs.
struct DialogAction_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};

struct Element_guess {
    char pad_000_guess[0x60];
    unsigned char active_060_guess;  // 0x60
    char pad_061_guess[0x80 - 0x61];
    int first_080_guess;             // 0x80
    int second_084_guess;            // 0x84
};

struct ElementCollection_guess {
    // EXTERNAL: TITANIUM 0x0041DE16 ElementCollection_guess::GetItemBySlot_guess
    Element_guess* GetItemBySlot_guess(int index_guess);
};

struct CharDataRoot_guess {
    char pad_0000_guess[0xc280];
    ElementCollection_guess elementCollection_guess;  // 0xc280
};

struct CompareManager_guess {
    // EXTERNAL: TITANIUM 0x004BE2FC CompareManager_guess::FindItemByKey_guess
    int FindItemByKey_guess(int first_guess, int second_guess, int zero_guess);
};

struct PickManager_guess {
    // EXTERNAL: TITANIUM 0x005219F6 PickManager_guess::SetRaw_guess
    void SetRaw_guess(int first_guess, unsigned int key_guess);
};

struct MessageSender_guess {
    // EXTERNAL: TITANIUM 0x0051DE5D MessageSender_guess::RequestEvolvingFinalResult_guess
    void RequestEvolvingFinalResult_guess(const char* text_guess);
};

struct FlagTarget_guess {
    char pad_000_guess[0x5d];
    unsigned char flag_guess;  // 0x5d
};

// EXTERNAL: TITANIUM 0x00475CE4 do_autoinventory_guess
void __cdecl do_autoinventory_guess(void* object_guess, int value_guess);

// EXTERNAL: TITANIUM 0x004B2056 ParseToken_guess
int __cdecl ParseToken_guess(const char* text_guess, char* output_guess, int delimiter_guess);

#define g_charDataRoot_guess EQ_GLOBAL(CharDataRoot_guess*, 0x00905D00)
#define g_compareManager_guess EQ_GLOBAL(CompareManager_guess*, 0x00905D00)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_pickManager_guess EQ_GLOBAL(PickManager_guess*, 0x00991B88)
#define g_messageSender_guess EQ_GLOBAL(MessageSender_guess*, 0x00991B88)
#define g_notifyObject_guess EQ_GLOBAL(void*, 0x00905CE4)

struct CItemExpTransferWnd_guess : CSidlScreenWnd {
    DialogAction_guess dialog_guess;      // 0x15c
    int unknown_160_guess;                // 0x160
    int pad_164_guess;                    // 0x164
    int first_x_guess;                    // 0x168
    int first_y_guess;                    // 0x16c
    int second_x_guess;                   // 0x170
    int second_y_guess;                   // 0x174
    int reset_a_guess;                    // 0x178
    int reset_b_guess;                    // 0x17c
    int reset_c_guess;                    // 0x180
    int reset_d_guess;                    // 0x184
    unsigned char ready_guess;            // 0x188
    char pad_189_guess[0x194 - 0x189];
    FlagTarget_guess* flag_target_guess;  // 0x194
    CXWnd* clear_198_guess;               // 0x198
    CXWnd* clear_19c_guess;               // 0x19c
    // EXTERNAL: TITANIUM 0x0052254F CItemExpTransferWnd_guess::UpdateItems_guess
    void UpdateItems_guess();
    int WndNotification_guess(CXWnd* sender_guess, int type_guess, char* payload_guess);
};

// Destructor of the client's growable array: frees the element buffer and zeroes the pointer, capacity
// and count. Shared by many owners (window lists, compass markers, menu nodes, rule sets).
// FUNCTION: TITANIUM 0x0050F3F6
Member_guess::~Member_guess() {
    if (data_guess != 0) {
        FreeArray_guess(data_guess);
    }
    data_guess = 0;
    unknown_guess = 0;
    capacity_guess = 0;
}

// CItemExpTransferWnd::WndNotification. Clicking FromItemIcon or ToItemIcon takes the cursor item (slot 30)
// by its id pair (+0x80/+0x84) and frees the other side if it held the same item; TransferButton asks for
// confirmation. Type 3 on an icon opens that item's display window; a type 0x1B link starting "1^" goes
// out as message 0x7E61 kind 4 (0x51DE5D, tu_174).
// FUNCTION: TITANIUM 0x00522798
// @early-stop: budget, structural ndiff=121
int CItemExpTransferWnd_guess::WndNotification_guess(CXWnd* sender_guess, int type_guess, char* payload_guess) {
    if (type_guess == 1) {
        if (sender_guess == clear_198_guess) {
            Element_guess* element_guess = g_charDataRoot_guess->elementCollection_guess.GetItemBySlot_guess(0x1e);
            first_x_guess = -1;
            first_y_guess = -1;
            if (element_guess == 0) {
                reset_a_guess = -2;
                reset_b_guess = -1;
            } else if (element_guess->active_060_guess != 0) {
                first_x_guess = element_guess->first_080_guess;
                first_y_guess = element_guess->second_084_guess;
                if (first_x_guess == second_x_guess && first_y_guess == second_y_guess) {
                    second_x_guess = -1;
                    second_y_guess = -1;
                    reset_c_guess = -2;
                    reset_d_guess = -1;
                }
            }
        } else if (sender_guess == clear_19c_guess) {
            Element_guess* element_guess = g_charDataRoot_guess->elementCollection_guess.GetItemBySlot_guess(0x1e);
            second_x_guess = -1;
            second_y_guess = -1;
            if (element_guess == 0) {
                reset_c_guess = -2;
                reset_d_guess = -1;
            } else if (element_guess->active_060_guess != 0) {
                second_x_guess = element_guess->first_080_guess;
                second_y_guess = element_guess->second_084_guess;
                if (first_x_guess == second_x_guess && first_y_guess == second_y_guess) {
                    first_x_guess = -1;
                    first_y_guess = -1;
                    reset_a_guess = -2;
                    reset_b_guess = -1;
                }
            }
        } else if (sender_guess == (CXWnd*)flag_target_guess) {
            pConfirmationDialogPool_guess->Activate(&dialog_guess, 0x64,
                // Yes/No prompt (mask 0xC), 10 s timeout, message id 100; tu_175's Handle_guess
                // gets the answer.
                pStringTable->getString(0x1804, 0), 0xc, 10000, 0, 1);
            if (flag_target_guess != 0) {
                flag_target_guess->flag_guess = 0;
            }
            return 0;
        } else {
            return CSidlScreenWnd::WndNotification(sender_guess, type_guess, payload_guess);
        }
        UpdateItems_guess();
        do_autoinventory_guess(g_notifyObject_guess, 0);
        return 0;
    } else if (type_guess == 3) {
        int first_guess;
        int second_guess;
        if (sender_guess == clear_198_guess) {
            first_guess = first_x_guess;
            second_guess = first_y_guess;
        } else if (sender_guess == clear_19c_guess) {
            first_guess = second_x_guess;
            second_guess = second_y_guess;
        } else {
            return CSidlScreenWnd::WndNotification(sender_guess, type_guess, payload_guess);
        }
        if ((first_guess & second_guess) != 0xffffffff) {
            int compared_guess = g_compareManager_guess->FindItemByKey_guess(first_guess, second_guess, 0);
            if (compared_guess != 0) {
                unsigned int flags_guess = pinstCXWndManager_guess->GetKeyboardFlags();
                g_pickManager_guess->SetRaw_guess(compared_guess, ~flags_guess & 1);
            }
        }
    } else if (type_guess == 0x1b) {
        unsigned int value_guess;
        int offset_guess = ParseToken_guess(payload_guess, (char*)&value_guess, 0x5e);
        if (value_guess == 1) {
            g_messageSender_guess->RequestEvolvingFinalResult_guess(payload_guess + offset_guess);
        }
    }
    return CSidlScreenWnd::WndNotification(sender_guess, type_guess, payload_guess);
}

// Empties the controls: category list, DefaultChooser, NameInput and DescInput.
// FUNCTION: TITANIUM 0x005229CA
void CJournalCatWnd_guess::ClearControls_guess() {
    selectedCategory_017c_guess = 0;
    if (categoryList_guess != 0) {
        categoryList_guess->ClearAllSel();
        ((ListSlots_guess*)categoryList_guess)->S76_guess();
    }
    if (defaultChooser_guess != 0) {
        ((CComboWnd_guess*)defaultChooser_guess)->Clear_guess();
    }
    if (nameInput_guess != 0) {
        CXStr empty_guess(EQ_ARRAY(char, 0x0063F53F));
        ((EditSlots_guess*)nameInput_guess)->SetText_guess(empty_guess);
    }
    if (descInput_guess != 0) {
        CXStr empty_guess(EQ_ARRAY(char, 0x0063F53F));
        ((EditSlots_guess*)descInput_guess)->SetText_guess(empty_guess);
    }
}

// Reads DefaultCategory (a category id, -1 none) from the UI INI file.
// FUNCTION: TITANIUM 0x00522B0F
void CJournalCatWnd_guess::LoadDefaultCategory_guess() {
    char category_guess[256];
    char text_guess[256];
    if (NewUIINI() != 0) {
        sprintf(category_guess, "%s", EQ_ARRAY(char, 0x00656D80));
        LoadStringFromUIIniFile_guess(*(const CXStr*)&store_guess, "DefaultCategory", category_guess, text_guess, 0x1ff, 1);
        defaultCategory_0180_guess = atoi(text_guess);
    }
}

// Writes DefaultCategory to the UI INI file.
// FUNCTION: TITANIUM 0x00522B90
void CJournalCatWnd_guess::SaveDefaultCategory_guess() {
    char text_guess[256];
    if (NewUIINI() != 0) {
        sprintf(text_guess, "%d", defaultCategory_0180_guess);
        ApplySettingAlt_guess(*(const CXStr*)&store_guess, "DefaultCategory", text_guess);
    }
}

// Fills NameInput and DescInput from local record `index_guess` (-1 clears them).
// FUNCTION: TITANIUM 0x00522BF2
void CJournalCatWnd_guess::ShowRecord_guess(int index_guess) {
    if (nameInput_guess != 0) {
        const char* text_guess = index_guess == -1 ? EQ_ARRAY(char, 0x0063F53F) : ((Record_guess*)member_guess.At_guess(index_guess))->name_guess;
        CXStr name_guess(text_guess);
        ((EditSlots_guess*)nameInput_guess)->SetText_guess(name_guess);
    }
    if (descInput_guess != 0) {
        const char* text_guess = index_guess == -1 ? EQ_ARRAY(char, 0x0063F53F) : ((Record_guess*)member_guess.At_guess(index_guess))->text_guess;
        CXStr desc_guess(text_guess);
        ((EditSlots_guess*)descInput_guess)->SetText_guess(desc_guess);
    }
}

// Fills CategoryList (name, description) from the local records, keeping the selection when `flag_guess`,
// then rebuilds DefaultChooser: a string 0x4C0 entry plus every journal category, current text kept.
// FUNCTION: TITANIUM 0x00522CCB
void CJournalCatWnd_guess::FillControls_guess(bool flag_guess) {
    int sel_guess = -1;
    if (flag_guess && categoryList_guess != 0) {
        sel_guess = categoryList_guess->GetCurSel();
    }
    if (categoryList_guess != 0) {
        categoryList_guess->ClearAllSel();
        ((ListSlots_guess*)categoryList_guess)->S76_guess();
        for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
            int row_guess = categoryList_guess->AddString(
                ((Record_guess*)member_guess.At_guess(i_guess))->name_guess, 0xffffffff, 0, 0);
            categoryList_guess->SetItemText(row_guess, 1,
                ((Record_guess*)member_guess.At_guess(i_guess))->text_guess);
        }
        categoryList_guess->SetCurSel(sel_guess);
        ShowRecord_guess(sel_guess);
    }
    if (defaultChooser_guess != 0) {
        CXStr current_guess = ((CComboWnd_guess*)defaultChooser_guess)->GetText_guess();
        sel_guess = 0;
        int value_count_guess = pinstCJournalNPCWnd_guess->array_160_guess->count_0814_guess;
        int* values_guess = pinstCJournalNPCWnd_guess->array_160_guess->GetValues_guess();
        ((CComboWnd_guess*)defaultChooser_guess)->Clear_guess();
        ((CComboWnd_guess*)defaultChooser_guess)->AddChoice_guess(pStringTable->getString(0x4c0, 0));
        for (int j_guess = 0; j_guess < value_count_guess; ++j_guess) {
            ((CComboWnd_guess*)defaultChooser_guess)->AddChoice_guess(((Record_guess*)values_guess[j_guess])->name_guess);
            bool same_guess = ((CXStrView_guess*)&current_guess)->Compare_guess(((Record_guess*)values_guess[j_guess])->name_guess, false) == 0;
            if (same_guess) {
                sel_guess = j_guess + 1;
            }
        }
        ((CComboWnd_guess*)defaultChooser_guess)->SetCurSel_guess(sel_guess);
    }
}

// Sorts the local records: column 1 by description, else by name; `ascending_guess` picks the comparer pair.
// FUNCTION: TITANIUM 0x00522F43
void CJournalCatWnd_guess::SortCategories_guess(int column_guess, char ascending_guess) {
    Compare_guess compare_guess;
    switch (column_guess) {
    case 1:
        compare_guess = CompareC_guess;
        if (ascending_guess == 0) {
            compare_guess = CompareD_guess;
        }
        break;
    default:
        if (ascending_guess != 0) {
            compare_guess = CompareA_guess;
        } else {
            compare_guess = CompareB_guess;
        }
        break;
    }
    if (count_guess > 0) {
        Member_guess& list_guess = member_guess;
        if (list_guess.capacity_guess <= 0 || list_guess.data_guess == 0) {
            list_guess.Fail_guess();
        }
        _qsort(list_guess.data_guess, count_guess, 4, compare_guess);
    }
}

// Journal category window constructor: finds the buttons, DefaultChooser, CategoryList (colours set) and
// the name and description inputs (15 and 255 characters), then reads DefaultCategory from the UI INI
// (0x00522B0F).
// FUNCTION: TITANIUM 0x00522FA4
CJournalCatWnd_guess::CJournalCatWnd_guess(CXWnd* parent_guess) : Base_guess(parent_guess, "JournalCatWnd") {
    defaultCategory_0180_guess = -1;
    categoryList_guess = 0;
    deleteButton_guess = 0;
    addButton_guess = 0;
    updateButton_guess = 0;
    nameInput_guess = 0;
    descInput_guess = 0;
    defaultChooser_guess = 0;
    sortColumn_0198_guess = 0;
    sortAscending_019c_guess = 1;
    count_guess = 0;
    selectedCategory_017c_guess = 0;
    if (sidlPiece_guess != 0) {
        windowStyle_guess |= 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        deleteButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        addButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("AddButton");
        updateButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("UpdateButton");
        defaultChooser_guess = ((CSidlScreenWnd*)this)->GetChildItem("DefaultChooser");
        categoryList_guess = (CategoryList_guess*)((CSidlScreenWnd*)this)->GetChildItem("CategoryList");
        nameInput_guess = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("NameInput");
        descInput_guess = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("DescInput");
        if (categoryList_guess != 0) {
            categoryList_guess->SetColors(-1, 0xffffff00, 0xff808080);
            categoryList_guess->color_16c_guess = 0xff8aa3ff;
            categoryList_guess->field_15c_guess = 1;
            categoryList_guess->WindowStyle |= 0x20000;
        }
        if (nameInput_guess != 0) {
            // Category names are 15 characters, descriptions 255 (the Record_guess buffers less the NUL).
            nameInput_guess->SetMaxChars_guess(0xf);
        }
        if (descInput_guess != 0) {
            descInput_guess->SetMaxChars_guess(0xff);
        }
        LoadDefaultCategory_guess();
    }
}

// Destructor of the journal category window (vtable 0x656DC0): frees the array at +0x188 (0x0050F3F6),
// then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00523262
CJournalCatWnd_guess::~CJournalCatWnd_guess()  {
}

// Reloads the categories: copy, sort by the saved column, fill the controls, update the buttons.
// FUNCTION: TITANIUM 0x005233D8
void CJournalCatWnd_guess::Reload_guess(bool flag_guess) {
    CopyCategories_guess();
    SortCategories_guess(sortColumn_0198_guess, sortAscending_019c_guess);
    FillControls_guess(flag_guess);
    UpdateButtons_guess();
}

// Clears the controls and reloads; always returns 1.
// FUNCTION: TITANIUM 0x0052340C
unsigned char CJournalCatWnd_guess::Reset_guess() {
    ClearControls_guess();
    Reload_guess(0);
    return 1;
}

// Scalar deleting destructor of the journal category window (vtable 0x656DC0 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00523350
void* CJournalCatWnd_guess::Destroy_guess(unsigned char flags_guess) {
    this->CJournalCatWnd_guess::~CJournalCatWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Copies the journal's category pointers into the local list (+0x188).
// FUNCTION: TITANIUM 0x0052336C
void CJournalCatWnd_guess::CopyCategories_guess() {
    int value_guess;
    int* values_guess;
    int index_guess;
    ValueArray_guess* array_guess = pinstCJournalNPCWnd_guess->array_160_guess;
    count_guess = 0;
    int total_guess = array_guess->count_0814_guess;
    values_guess = array_guess->GetValues_guess();
    member_guess.Clear_guess();
    index_guess = 0;
    if (total_guess > 0) {
        do {
            value_guess = values_guess[index_guess];
            member_guess.SetAt_guess(member_guess.capacity_guess, &value_guess);
            ++count_guess;
            ++index_guess;
        } while (index_guess < total_guess);
    }
}

// Length of a returned CXStr temporary (0 when empty).
static inline int TextLength_guess(const CXStr& text_guess) {
    return text_guess.Ptr != 0 ? text_guess.Ptr->length : 0;
}

// Button states: Delete needs a selected row, Update a chosen record (+0x17C), Add a non-empty name.
// FUNCTION: TITANIUM 0x0052327E
void CJournalCatWnd_guess::UpdateButtons_guess() {
    if (deleteButton_guess != 0) {
        CategoryList_guess* list_guess = categoryList_guess;
        if (list_guess != 0) {
            SelectedIndices_guess indices_guess(0x20);
            list_guess->GetSelectedIndices_guess(&indices_guess);
            CXWnd* button_guess = deleteButton_guess;
            button_guess->Enabled = indices_guess.count_guess > 0;
        }
    }
    if (updateButton_guess != 0) {
        updateButton_guess->Enabled = selectedCategory_017c_guess != 0;
    }
    if (addButton_guess != 0) {
        bool flag_guess = false;
        if (nameInput_guess != 0) {
            flag_guess = TextLength_guess(((EditSlots_guess*)nameInput_guess)->GetText_guess()) > 0;
        }
        addButton_guess->Enabled = flag_guess;
    }
}

// WndNotification. Clicks: the list loads the row into the edit boxes, DefaultChooser saves the default,
// Delete removes the selected categories, Add creates one (unless the name exists), Update rewrites the
// chosen record; the last three refresh CJournalNPCWnd. 0xF sorts by the clicked column (again = reverse);
// 0xE, probably an edit change, updates the buttons.
// FUNCTION: TITANIUM 0x00523421
// @early-stop: tiebreak, structural ndiff=93
int CJournalCatWnd_guess::WndNotification_guess(CXWnd* target_guess, int command_guess, int data_guess) {
    ValueArray_guess* array_guess = pinstCJournalNPCWnd_guess->array_160_guess;
    if (command_guess == 1) {
        CategoryList_guess* list_guess = categoryList_guess;
        if (target_guess == list_guess) {
            int index_guess = list_guess->GetCurSel();
            selectedCategory_017c_guess = index_guess != -1 ? member_guess.At_guess(index_guess) : 0;
            ShowRecord_guess(index_guess);
            UpdateButtons_guess();
            return 0;
        } else if (target_guess == defaultChooser_guess) {
            int index_guess = ((CComboWnd_guess*)defaultChooser_guess)->GetCurChoice_guess();
            if (index_guess == 0) {
                defaultCategory_0180_guess = -1;
            } else {
                // Combo entries follow the journal's order but this indexes the sorted local copy: after a
                // sort the saved default can be the wrong category.
                defaultCategory_0180_guess = ((Record_guess*)member_guess.At_guess(index_guess - 1))->id_0000_guess;
            }
            SaveDefaultCategory_guess();
            return 0;
        } else if (target_guess == deleteButton_guess) {
            SelectedIndices_guess indices_guess(0x20);
            if (list_guess != 0) {
                list_guess->GetSelectedIndices_guess(&indices_guess);
                for (int i_guess = 0; i_guess < indices_guess.count_guess; ++i_guess) {
                    int row_guess = indices_guess.pages_guess[i_guess >> indices_guess.shift_guess]
                        [i_guess & indices_guess.mask_guess];
                    int id_guess = ((Record_guess*)member_guess.At_guess(row_guess))->id_0000_guess;
                    array_guess->RemoveCategory_guess(id_guess);
                }
                Reload_guess(false);
                pinstCJournalNPCWnd_guess->Refresh_guess(1);
            }
            return 0;
        } else if (target_guess == addButton_guess) {
            CXStr name_guess("Blank");
            CXStr text_guess;
            if (nameInput_guess != 0) {
                name_guess = ((EditSlots_guess*)nameInput_guess)->GetText_guess();
            }
            if (descInput_guess != 0) {
                text_guess = ((EditSlots_guess*)descInput_guess)->GetText_guess();
            }
            if (array_guess->FindCategoryByName_guess((const char*)name_guess) != 0) {
                pConfirmationDialogPool_guess->Activate(0, 0xb,
                    // Error: a category with this name already exists (probably; string 0xC6E).
                    pStringTable->getString(0xc6e, 0), 1, 4000, 0, 0);
            } else {
                array_guess->SetCategory_guess((const char*)name_guess, (const char*)text_guess, -1);
                Reload_guess(false);
                pinstCJournalNPCWnd_guess->FillCategoryCombos_guess();
            }
            return 0;
        } else if (target_guess == updateButton_guess) {
            CXStr name_guess("Blank");
            CXStr text_guess;
            if (nameInput_guess != 0) {
                name_guess = ((EditSlots_guess*)nameInput_guess)->GetText_guess();
            }
            if (descInput_guess != 0) {
                text_guess = ((EditSlots_guess*)descInput_guess)->GetText_guess();
            }
            if (selectedCategory_017c_guess != 0) {
                Record_guess* record_guess = (Record_guess*)selectedCategory_017c_guess;
                strncpy(record_guess->name_guess, (const char*)name_guess, 0xf);
                record_guess->name_guess[0xf] = 0;
                strncpy(record_guess->text_guess, (const char*)text_guess, 0xff);
                record_guess->text_guess[0xff] = 0;
                Reload_guess(true);
                pinstCJournalNPCWnd_guess->FillCategoryCombos_guess();
            }
            return 0;
        }
    } else if (command_guess == 0xf) {
        unsigned int selected_guess = data_guess == 1;
        bool ascending_guess;
        if (sortColumn_0198_guess == (int)selected_guess) {
            ascending_guess = sortAscending_019c_guess == 0;
        } else {
            ascending_guess = true;
        }
        sortColumn_0198_guess = selected_guess;
        sortAscending_019c_guess = ascending_guess;
        SortCategories_guess(selected_guess, ascending_guess);
        FillControls_guess(true);
        return 0;
    } else if (command_guess == 0xe) {
        UpdateButtons_guess();
        return 0;
    }
    return WndNotification(target_guess, command_guess, data_guess);
}

// Show hook: opening the window pops context tip 14 (tu_228's ShowTipWindow on 0x9928E0).
// FUNCTION: TITANIUM 0x0052382B
void CJournalCatWnd_guess::OnShow_guess() {
    if (state_guess != 0 && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0xe, 0);
    }
    OnShow();
}

// 0x180: object with an int id at +0x14.
struct Selected_guess {
    char pad_0000_guess[0x14];
    int id_14_guess;
};

// CJournalNPCWnd: refills its two category combos, the filter (string 0x3395 first, then every category)
// and the selected entry's category (string 0x4C0 first, selecting the entry's id at +0x14).
// FUNCTION: TITANIUM 0x0052384F
// @early-stop: budget, diff ndiff=15
void CJournalNPCWnd_guess::FillCategoryCombos_guess() {
    int count_guess = array_160_guess->count_0814_guess;
    int* values_guess = array_160_guess->GetValues_guess();
    int i_guess;
    i_guess = 0;
    if (combo_1dc_guess != 0) {
        combo_1dc_guess->Clear_guess();
        combo_1dc_guess->AddChoice_guess(pStringTable->getString(0x3395, 0));
        if (count_guess > 0) {
            do {
                combo_1dc_guess->AddChoice_guess(((Record_guess*)values_guess[i_guess])->name_guess);
                ++i_guess;
            } while (i_guess < count_guess);
        }
        combo_1dc_guess->SetCurSel_guess(chosen_1a0_guess + 1);
    }
    int sel_guess = -1;
    int id_guess = -1;
    if (selected_180_guess != 0) {
        id_guess = selected_180_guess->id_14_guess;
    }
    i_guess = 0;
    if (combo_1e0_guess != 0) {
        combo_1e0_guess->Clear_guess();
        combo_1e0_guess->AddChoice_guess(pStringTable->getString(0x4c0, 0));
        if (count_guess > 0) {
            do {
                combo_1e0_guess->AddChoice_guess(((Record_guess*)values_guess[i_guess])->name_guess);
                if (((Record_guess*)values_guess[i_guess])->id_0000_guess == id_guess) {
                    sel_guess = i_guess;
                }
                ++i_guess;
            } while (i_guess < count_guess);
        }
        combo_1e0_guess->SetCurSel_guess(sel_guess + 1);
    }
}

