// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 213: a hint from compare/tumap.py.
// The tail of the Skills window (row fill, per-skill refresh, the custom skill-title list) and the social
// editor, CSocialEditWnd ("SocialEditWnd"). Socials live in a client table at 0x95D4D4: 12 buttons per
// page, 0x511 bytes each (name, five 256-byte lines, colour index); saved by SaveSocials_guess.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CTipWnd.h"

struct FUN_00554d6c_guess {
    // EXTERNAL: TITANIUM 0x00554AC1 FUN_00554d6c_guess::FUN_00554ac1_guess
    void FUN_00554ac1_guess();
    // EXTERNAL: TITANIUM 0x004C9745 FUN_00554d6c_guess::FUN_004c9745_guess
    void FUN_004c9745_guess();
    void Run_guess();
};

struct ColorItem_guess {
    char pad_000[0x7c];
    unsigned int color;
};

struct CSocialEditWndView_guess {
    char pad_000[0x15c];
    int row_guess;
    int column_guess;
    int selectedIndex;
    char pad_168[8];
    ColorItem_guess* entries[20];
    ColorItem_guess* active;
    struct Holder_guess* children_guess[5];
    void SetSelected_guess(int index);
    unsigned int GetColor_guess(int index);
    void Run_guess();
};

struct CSkillsWndRowsView_guess {
    char pad_000[0x164];
    int count_guess;
    int enabled_guess;
    // EXTERNAL: TITANIUM 0x00554C2D CSkillsWndRowsView_guess::FUN_00554c2d_guess
    void FUN_00554c2d_guess(int index);
    void Run_guess();
};

struct CSkillsWndSkillView_guess {
    char pad_000[0x164];
    int count_guess;
    CListWnd* list_guess;
    // EXTERNAL: TITANIUM 0x0059DD30 CSkillsWndSkillView_guess::IsReady_guess
    char IsReady_guess();
    // EXTERNAL: TITANIUM 0x00554C2D CSkillsWndSkillView_guess::FUN_00554c2d_guess
    void FUN_00554c2d_guess(int index);
    void Run_guess(int target);
};

struct CheckScope_guess {
    // EXTERNAL: TITANIUM 0x0041B0DE CheckScope_guess::HasSkill_guess
    int HasSkill_guess(int index);
};

struct FlagOffset_guess {
    char pad_000[4];
    unsigned int offset_guess;
};

#define VIRTUAL_SLOT(n) virtual void Slot##n##_guess();
struct SubObject_guess {
    VIRTUAL_SLOT(0) VIRTUAL_SLOT(1) VIRTUAL_SLOT(2) VIRTUAL_SLOT(3)
    VIRTUAL_SLOT(4) VIRTUAL_SLOT(5) VIRTUAL_SLOT(6) VIRTUAL_SLOT(7)
    VIRTUAL_SLOT(8) VIRTUAL_SLOT(9) VIRTUAL_SLOT(10) VIRTUAL_SLOT(11)
    VIRTUAL_SLOT(12) VIRTUAL_SLOT(13) VIRTUAL_SLOT(14) VIRTUAL_SLOT(15)
    VIRTUAL_SLOT(16) VIRTUAL_SLOT(17) VIRTUAL_SLOT(18) VIRTUAL_SLOT(19)
    VIRTUAL_SLOT(20) VIRTUAL_SLOT(21) VIRTUAL_SLOT(22) VIRTUAL_SLOT(23)
    VIRTUAL_SLOT(24) VIRTUAL_SLOT(25) VIRTUAL_SLOT(26) VIRTUAL_SLOT(27)
    VIRTUAL_SLOT(28) VIRTUAL_SLOT(29) VIRTUAL_SLOT(30) VIRTUAL_SLOT(31)
    VIRTUAL_SLOT(32) VIRTUAL_SLOT(33) VIRTUAL_SLOT(34) VIRTUAL_SLOT(35)
    VIRTUAL_SLOT(36) VIRTUAL_SLOT(37) VIRTUAL_SLOT(38) VIRTUAL_SLOT(39)
    VIRTUAL_SLOT(40) VIRTUAL_SLOT(41) VIRTUAL_SLOT(42) VIRTUAL_SLOT(43)
    VIRTUAL_SLOT(44) VIRTUAL_SLOT(45) VIRTUAL_SLOT(46) VIRTUAL_SLOT(47)
    VIRTUAL_SLOT(48) VIRTUAL_SLOT(49) VIRTUAL_SLOT(50) VIRTUAL_SLOT(51)
    VIRTUAL_SLOT(52) VIRTUAL_SLOT(53) VIRTUAL_SLOT(54) VIRTUAL_SLOT(55)
    VIRTUAL_SLOT(56) VIRTUAL_SLOT(57) VIRTUAL_SLOT(58) VIRTUAL_SLOT(59)
    VIRTUAL_SLOT(60) VIRTUAL_SLOT(61) VIRTUAL_SLOT(62) VIRTUAL_SLOT(63)
    VIRTUAL_SLOT(64) VIRTUAL_SLOT(65) VIRTUAL_SLOT(66) VIRTUAL_SLOT(67)
    VIRTUAL_SLOT(68) VIRTUAL_SLOT(69) VIRTUAL_SLOT(70) VIRTUAL_SLOT(71)
    VIRTUAL_SLOT(72) VIRTUAL_SLOT(73) VIRTUAL_SLOT(74) VIRTUAL_SLOT(75)
    virtual void Slot76_guess();
    VIRTUAL_SLOT(77)
    virtual void Slot78_guess();
};
#undef VIRTUAL_SLOT

struct FunctionGlobal_guess {
    char pad_000[8];
    FlagOffset_guess* flagOffset_guess;
    char pad_00c[8];
    unsigned char flagData_guess[1];
    char pad_015[0xc280 - 0x15];
    CheckScope_guess checkScope_guess;
};

#define g_00905d00_guess EQ_GLOBAL(FunctionGlobal_guess*, 0x00905D00)

struct CSkillsWndListView_guess {
    char pad_000[0x168];
    SubObject_guess* subObject_guess;
    // EXTERNAL: TITANIUM 0x00554B07 CSkillsWndListView_guess::FUN_00554b07_guess
    void FUN_00554b07_guess(int index);
    char AboutToShow_guess();
};


struct CSkillsWndShowView_guess {
    char pad_000[0x5c];
    char enabled_guess;
    // EXTERNAL: TITANIUM 0x005A1880 CSkillsWndShowView_guess::OnShow
    void OnShow();
    void Run_guess();
};

struct CXWndView_guess {
    // EXTERNAL: TITANIUM 0x0059EDF0 CXWndView_guess::SetFocus
    void SetFocus();
};

struct CSocialEditWndFocusView_guess {
    char pad_000[0x1c0];
    CXWndView_guess* fallback_guess;
    CXWndView_guess* entries_guess[5];
    int Run_guess(CXWndView_guess* target);
};

// Destructor of the custom skill rank text map (0x991FA8): empties it (0x00554AC1), then frees the hash
// storage (0x004C9745). Run in the client teardown (0x00497395).
// FUNCTION: TITANIUM 0x00554D6C
void FUN_00554d6c_guess::Run_guess() {
    FUN_00554ac1_guess();
    FUN_004c9745_guess();
}

// Fills the list: one row per skill id 0-99 the character has, then ids 100-131 for the languages it knows
// (non-zero language bytes; GetLangDesc_guess names them in tu_212). List updates are bracketed by
// Slot76/Slot78 (probably begin/end update).
// FUNCTION: TITANIUM 0x00554D7C
// @early-stop: unknown, structural ndiff=27
char CSkillsWndListView_guess::AboutToShow_guess() {
    if (subObject_guess != 0) {
        subObject_guess->Slot76_guess();
    }
    int index = 0;
    do {
        if (g_00905d00_guess->checkScope_guess.HasSkill_guess(index) != 0) {
            FUN_00554b07_guess(index);
        }
        ++index;
    } while (index < 100);
    index = 0;
    do {
        if (g_00905d00_guess->flagData_guess[
                g_00905d00_guess->flagOffset_guess->offset_guess + index] != 0) {
            FUN_00554b07_guess(index + 100);
        }
        ++index;
    } while (index < 32);
    if (subObject_guess != 0) {
        subObject_guess->Slot78_guess();
    }
    return 1;
}

// Refreshes the row whose skill id is `target`, if the list is ready.
// FUNCTION: TITANIUM 0x00554E07
void CSkillsWndSkillView_guess::Run_guess(int target) {
    int index = 0;
    if (list_guess != 0 && IsReady_guess() != 0 && count_guess > 0) {
        do {
            if (list_guess->GetItemData(index) == target) {
                FUN_00554c2d_guess(index);
                return;
            }
            ++index;
        } while (index < count_guess);
    }
}

// Skills window: refreshes every row in place (0x00554C2D) when the window is built (+0x168). Called
// after the item stat totals are rebuilt, after OP_CustomTitles and when the window is shown.
// FUNCTION: TITANIUM 0x00554E50
void CSkillsWndRowsView_guess::Run_guess() {
    int index = 0;
    if (enabled_guess != 0 && count_guess > 0) {
        do {
            FUN_00554c2d_guess(index);
            ++index;
        } while (index < count_guess);
    }
}

// On show: refreshes every row and shows context tip 15 (0x0F) in the tip window (0x9928E0), as tu_014 does
// with tip 0x3F.
// FUNCTION: TITANIUM 0x00554F9E
void CSkillsWndShowView_guess::Run_guess() {
    if (enabled_guess != 0) {
        ((CSkillsWndRowsView_guess*)this)->Run_guess();
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0xf, 0);
        }
    }
    return OnShow();
}

// Focus goes to the matching child, or to the fallback control.
// FUNCTION: TITANIUM 0x00554FC7
int CSocialEditWndFocusView_guess::Run_guess(CXWndView_guess* target) {
    int index = 0;
    do {
        if (target == entries_guess[index]) {
            if (entries_guess[index] != 0) {
                entries_guess[index]->SetFocus();
            }
            return 0;
        }
        ++index;
    } while (index < 5);
    if (target == fallback_guess && fallback_guess != 0) {
        fallback_guess->SetFocus();
    }
    return 0;
}

struct Str_guess {
    void* data_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text);
    // EXTERNAL: TITANIUM 0x005722D0 Str_guess::Initialize_guess
    void Initialize_guess(int value);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(void* p);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct CSkillsWndTitlesView_guess {
    // EXTERNAL: TITANIUM 0x00554AC1 CSkillsWndTitlesView_guess::FUN_00554ac1_guess
    void FUN_00554ac1_guess();
    // EXTERNAL: TITANIUM 0x00554A08 CSkillsWndTitlesView_guess::FUN_00554a08_guess
    void FUN_00554a08_guess(int first_guess, int second_guess, Str_guess* name_guess);
    void Run_guess(int data_guess);
};

// EXTERNAL: TITANIUM 0x0060DA00 memcpy
void* __cdecl memcpy(void* dest, const void* src, unsigned int count);
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);
#define pinstCSkillsWnd_guess EQ_GLOBAL(CSkillsWndRowsView_guess*, 0x00850BB4)

// OP_CustomTitles payload: count, then per entry two ints and a NUL-terminated title; each goes to the
// skill-title map (FUN_00554a08_guess). Clears the map first.
// FUNCTION: TITANIUM 0x00554E7A
void CSkillsWndTitlesView_guess::Run_guess(int data_guess) {
    FUN_00554ac1_guess();
    if (data_guess != 0) {
        int first = 0;
        int second = 0;
        int count = 0;
        char buf[0x400];
        int* p = (int*)data_guess;
        memcpy(&count, p, 4);
        p++;
        while (p != 0) {
            if (count <= 0) {
                break;
            }
            memcpy(&first, p, 4);
            p++;
            if (p == 0) {
                break;
            }
            memcpy(&second, p, 4);
            p++;
            if (p == 0) {
                break;
            }
            char* text = (char*)p;
            // Server text is used as the format string, into a 1 KB buffer (original bug, kept).
            int length = sprintf(buf, text);
            text += length + 1;
            p = (int*)text;
            {
                Str_guess name(buf);
                FUN_00554a08_guess(first, second, &name);
            }
            --count;
        }
    }
    if (pinstCSkillsWnd_guess != 0) {
        pinstCSkillsWnd_guess->Run_guess();
    }
}

struct Holder_guess {
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
    virtual void Slot48_guess(int arg1, int arg2);
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
    virtual void GetName_guess(Str_guess* out);
};

struct TextWnd_guess : Holder_guess {
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
    virtual CXStr GetText_guess();
};

struct CSocialEditWndClearView_guess {
    char pad_000[0x1c0];
    Holder_guess* owner_guess;
    Holder_guess* items_guess[5];
    void Run_guess();
};

struct CSocialEditWndActivateView_guess : Holder_guess {
    char pad_004[0x158];
    int row_guess;
    int column_guess;
    int selectedIndex_guess;
    void Run_guess(int value);
};

struct SidlPiece_guess {
    char pad_000[0x60];
    unsigned int style_060;                 // 0x060
};

struct SocialSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1SocialSidlBase_guess@@UAE@XZ
    virtual ~SocialSidlBase_guess();
    char pad_004[0x60];
    unsigned int windowStyle_064;           // 0x064
    char pad_068[0x24];
    unsigned char field_08c;                // 0x08C
    char pad_08d[0x97];
    SidlPiece_guess* sidlPiece_124;         // 0x124
    char pad_128[0x34];
    // EXTERNAL: TITANIUM 0x005A3900 ??0SocialSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    SocialSidlBase_guess(CXWnd* parent, const CXStr& screen);
    // EXTERNAL: TITANIUM 0x005A2230 SocialSidlBase_guess::WndNotification
    int WndNotification(CXWnd* sender, int message, void* data);
};

struct EditWnd_guess {
    // EXTERNAL: TITANIUM 0x004D7EBC ?SetMaxChars_guess@EditWnd_guess@@QAEXH@Z
    void SetMaxChars_guess(int max_guess);
};

struct ButtonWnd_guess {
    char pad_000[0x1c];
    void* owner_1c;                         // 0x01C
};

// EXTERNAL: TITANIUM 0x0065CCF0 ??_7CSocialEditWnd_guess@@6B@
struct CSocialEditWnd_guess : SocialSidlBase_guess {
    int page_015c_guess;                          // 0x15C
    int slot_0160_guess;                          // 0x160
    int field_164;                          // 0x164
    CXWnd* acceptButton_168;                // 0x168 SEW_Accept_Button
    CXWnd* clearButton_16c;                 // 0x16C SEW_Clear_Button
    CXWnd* tcButtons_170[20];               // 0x170 SEW_TC0..19Button
    CXWnd* nameInput_1c0;                   // 0x1C0 SEW_NameInput
    CXWnd* lineInputs_1c4[5];               // 0x1C4 SEW_Line0..4Input
    CSocialEditWnd_guess(CXWnd* parent);
    void ClickedAccept_guess();
    int WndNotification_guess(CXWnd* sender, int message, void* data);
};

struct EverQuestSave_guess {
    // EXTERNAL: TITANIUM 0x004B03B1 EverQuestSave_guess::SaveSocials_guess
    void SaveSocials_guess();
};

// Clicks (message 1): Accept saves, Clear empties the fields, SEW_TC0-19 pick the text colour.
// FUNCTION: TITANIUM 0x0055561A
int CSocialEditWnd_guess::WndNotification_guess(CXWnd* sender, int message, void* data) {
    if (message == 1) {
        if (sender == acceptButton_168) {
            ClickedAccept_guess();
            return 0;
        }
        if (sender == clearButton_16c) {
            ((CSocialEditWndClearView_guess*)this)->Run_guess();
            return 0;
        }
        if (sender != 0) {
            int index = 0;
            do {
                if (tcButtons_170[index] == sender) {
                    ((CSocialEditWndView_guess*)this)->SetSelected_guess(index);
                    return 0;
                }
                ++index;
            } while (index < 20);
        }
    }
    return ((SocialSidlBase_guess*)this)->WndNotification(sender, message, data);
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* dest, const char* src);

// Accept: copies the name and five lines into the social being edited (page field_15c, button
// field_160), stores the colour, marks the slot used, saves socials and closes the window.
// FUNCTION: TITANIUM 0x00555003
// @early-stop: budget, diff ndiff=14
void CSocialEditWnd_guess::ClickedAccept_guess() {
    if (nameInput_1c0 != 0) {
        strcpy(EQ_ARRAY(char, 0x0095D4D4) + (slot_0160_guess + page_015c_guess * 12) * 0x511,
               ((TextWnd_guess*)nameInput_1c0)->GetText_guess());
    }
    CXWnd** item;
    int offset;
    offset = 0;
    item = lineInputs_1c4;
    do {
        if (*item != 0) {
            strcpy(EQ_ARRAY(char, 0x0095D4E4) + (slot_0160_guess + page_015c_guess * 12) * 0x511 + offset,
                   ((TextWnd_guess*)*item)->GetText_guess());
        }
        offset += 0x100;
        ++item;
    } while (offset < 0x500);
    EQ_ARRAY(char, 0x0095D9E4)[(slot_0160_guess + page_015c_guess * 12) * 0x511] = (char)field_164;
    EQ_ARRAY(char, 0x0095D45C)[slot_0160_guess + page_015c_guess * 12] = 1;
    ((EverQuestSave_guess*)pEverQuest)->SaveSocials_guess();
    ((Holder_guess*)this)->Slot34_guess();
}

// Clear: empties the name and the five line inputs; the stored social is untouched until Accept.
// FUNCTION: TITANIUM 0x00555146
void CSocialEditWndClearView_guess::Run_guess() {
    if (owner_guess != 0) {
        Str_guess s(EQ_ARRAY(char, 0x0063F53F));
        owner_guess->GetName_guess(&s);
    }
    Holder_guess** slot = items_guess;
    int i = 5;
    do {
        if (*slot != 0) {
            Str_guess t(EQ_ARRAY(char, 0x0063F53F));
            (*slot)->GetName_guess(&t);
        }
        ++slot;
        --i;
    } while (i != 0);
}

// Selects text colour `index` (0-19) and shows it on the name input.
// FUNCTION: TITANIUM 0x005551F5
void CSocialEditWndView_guess::SetSelected_guess(int index) {
    if (index >= 0 && index < 20 && active != 0) {
        active->color = entries[index]->color;
        selectedIndex = index;
    }
}

// Colour of colour button `index`; grey 0xFF606060 when the index or button is missing.
// FUNCTION: TITANIUM 0x00555224
unsigned int CSocialEditWndView_guess::GetColor_guess(int index) {
    unsigned int color = 0xff606060;
    if (index >= 0 && index < 20 && entries[index] != 0) {
        color = entries[index]->color;
    }
    return color;
}

// Loads the edited social (row * 12 + column) into the name, line and colour controls.
// FUNCTION: TITANIUM 0x00555247
void CSocialEditWndView_guess::Run_guess() {
    Str_guess name(EQ_ARRAY(char, 0x0095D4D4) + (column_guess + row_guess * 12) * 0x511);
    name.Initialize_guess(1);
    if (active != 0) {
        ((Holder_guess*)active)->GetName_guess(&name);
    }
    Holder_guess** item = children_guess;
    int offset = 0;
    do {
        if (*item != 0) {
            Str_guess itemName(EQ_ARRAY(char, 0x0095D4E4) + (column_guess + row_guess * 12) * 0x511 + offset);
            (*item)->GetName_guess(&itemName);
        }
        offset += 0x100;
        ++item;
    } while (offset < 0x500);
    char selected = EQ_ARRAY(char, 0x0095D9E4)[(column_guess + row_guess * 12) * 0x511];
    selectedIndex = selected;
    SetSelected_guess(selected);
}

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);
// EXTERNAL: TITANIUM 0x004AE49C IsDoubleByteLanguage_guess
char __cdecl IsDoubleByteLanguage_guess(int value_guess);
#define g_fontIndex_guess EQ_GLOBAL(int, 0x00923D74)

// Name input holds 8 characters, 5 when FUN_004ae49c_guess accepts the font index (probably a wide or large
// font); each line holds 255.
// FUNCTION: TITANIUM 0x00555363
CSocialEditWnd_guess::CSocialEditWnd_guess(CXWnd* parent) : SocialSidlBase_guess(parent, "SocialEditWnd") {
    slot_0160_guess = 0;
    page_015c_guess = 0;
    field_164 = 0;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060;
        field_08c = 0x44;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        acceptButton_168 = ((CSidlScreenWnd*)this)->GetChildItem("SEW_Accept_Button");
        clearButton_16c = ((CSidlScreenWnd*)this)->GetChildItem("SEW_Clear_Button");
        nameInput_1c0 = ((CSidlScreenWnd*)this)->GetChildItem("SEW_NameInput");
        char maxChars = 8;
        if (IsDoubleByteLanguage_guess(g_fontIndex_guess)) {
            maxChars = 5;
        }
        if (nameInput_1c0 != 0) {
            ((EditWnd_guess*)nameInput_1c0)->SetMaxChars_guess(maxChars);
        }
        int i;
        char name[0x100];
        for (i = 0; i < 5; ++i) {
            sprintf(name, "SEW_Line%dInput", i);
            lineInputs_1c4[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            if (lineInputs_1c4[i] != 0) {
                ((EditWnd_guess*)lineInputs_1c4[i])->SetMaxChars_guess(0xff);
            }
        }
        for (i = 0; i < 20; ++i) {
            sprintf(name, "SEW_TC%dButton", i);
            tcButtons_170[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            if (tcButtons_170[i] != 0) {
                ((ButtonWnd_guess*)tcButtons_170[i])->owner_1c = this;
            }
        }
    }
}

struct CSidlScreenWndDtorView_guess {
    void* Run_guess(unsigned char freeMemory);
};

// EXTERNAL: TITANIUM 0x0055222A DestroySidlScreenWnd_guess
void __cdecl DestroySidlScreenWnd_guess();
// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Shared scalar deleting destructor (slot 1 of 35 CXWnd-family vtables): runs the CSidlScreenWnd
// destructor through thunk 0x0055222A and frees the window when flag 1 is set.
// FUNCTION: TITANIUM 0x005555C5
void* CSidlScreenWndDtorView_guess::Run_guess(unsigned char deleteFlags) {
    DestroySidlScreenWnd_guess();
    if ((deleteFlags & 1) != 0) {
        free(this);
    }
    return this;
}

// Opens the editor on social `value`: page value / 12, button value % 12.
// FUNCTION: TITANIUM 0x005555E1
void CSocialEditWndActivateView_guess::Run_guess(int value) {
    selectedIndex_guess = 0;
    row_guess = value / 12;
    column_guess = value % 12;
    ((CSocialEditWndView_guess*)this)->Run_guess();
    Slot48_guess(1, 1);
}

