// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 212: a hint from compare/tumap.py.
// The Skills window, CSkillsWnd ("SkillsWindow"), and the skill picker CSkillsSelectWnd. Skill ids: 0-99
// skills (table at 0x851200); in the Skills window 100-131 are languages, in the picker 100-131 are innate
// abilities and 132-231 probably combat abilities. Rank text per skill comes from the custom map at 0x991FA8,
// else from 11 value brackets.
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct FUN_00553dce_guess_interface {
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
    virtual void Slot0A_guess();
    virtual void Slot0B_guess();
    virtual void Slot0C_guess();
    virtual void Slot0D_guess();
    virtual void Slot0E_guess();
    virtual void Slot0F_guess();
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
    virtual void Slot1A_guess();
    virtual void Slot1B_guess();
    virtual void Slot1C_guess();
    virtual void Slot1D_guess();
    virtual void Slot1E_guess();
    virtual void Slot1F_guess();
    virtual void Slot20_guess(int value1, int value2, int value3);
};

struct HashTableInitView_guess {
    // EXTERNAL: TITANIUM 0x0042F092 HashTableInitView_guess::FUN_0042f092_guess
    void FUN_0042f092_guess(int value);
    HashTableInitView_guess* ReturnThis_guess();
};

struct FUN_005543d8_guess_object {
    void* vtable;
};

struct CSkillsWndDtorView_guess {
    // EXTERNAL: TITANIUM 0x005543D8 ??1CSkillsWndDtorView_guess@@UAE@XZ
    virtual ~CSkillsWndDtorView_guess();
    void* DeleteThis_guess(unsigned char flags);
};

struct CSkillsSelectWndView_guess {
    void* vtable;
    char pad_4[0x158];
    int field_15c;
    char pad_160[4];
    int field_164;
    // EXTERNAL: TITANIUM 0x005A2230 CSkillsSelectWndView_guess::WndNotification
    int WndNotification(int value1, int value2, int value3);
    void Destroy_guess();
    void* DeleteThis_guess(unsigned char flags);
    void WndNotification_guess(int value1, int value2, int value3);
};

struct FUN_00554437_guess_member : CXStr {
    // EXTERNAL: TITANIUM 0x004482FB ??1FUN_00554437_guess_member@@QAE@XZ
    ~FUN_00554437_guess_member();
};

struct SkillRowInfo_guess {
    FUN_00554437_guess_member name_0000_guess;      // 0x00 (CXStr)
    FUN_00554437_guess_member valueText_0004_guess;      // 0x04 (CXStr)
    unsigned int skillValue_0008_guess;             // 0x08
    unsigned int field_c_guess;             // 0x0C
    ~SkillRowInfo_guess();
};

struct FUN_0055446c_guess_string {
    int field_0;
    int field_4;
    // EXTERNAL: TITANIUM 0x00572300 FUN_0055446c_guess_string::GetString_guess
    const char* GetString_guess();
};

struct FUN_0055446c_guess_argument {
    int field_0;
    FUN_0055446c_guess_string field_4;
    FUN_0055446c_guess_string field_c;
    int field_14;
};

struct CSkillsWndSortView_guess {
    void CompareNumericCells_guess(FUN_0055446c_guess_argument* argument);
};

struct FUN_005544af_guess_node {
    int field_0;
    unsigned int key;
    FUN_005544af_guess_node* next;
};

struct IntKeyHashTable_guess {
    FUN_005544af_guess_node** buckets;
    int bucketCount;
    int threshold;
    int count;
    void Rehash_guess(int requested);
};

struct FUN_005543e3_guess_entry {
    int field_0;
    unsigned int field_4;
    unsigned char field_8;
    unsigned char field_9;
    unsigned char field_a;
    // EXTERNAL: TITANIUM 0x0044A335 FUN_005543e3_guess_entry::FUN_0044a335_guess
    int FUN_0044a335_guess(unsigned int level);
    // EXTERNAL: TITANIUM 0x0044A2E4 FUN_005543e3_guess_entry::FUN_0044a2e4_guess
    int FUN_0044a2e4_guess(unsigned int level);
};

struct FUN_005543e3_guess_target {
    char pad_0[0x5d];
    unsigned char enabled_005d_guess;
};

struct CSkillsWndSelectionView_guess {
    char pad_0[0x15c];
    int field_15c;
    char pad_160[8];
    CListWnd* field_168;
    char pad_16c[4];
    FUN_005543e3_guess_target* field_170;
    void UpdateHotKeyButton_guess();
};

#define g_entries_851200_guess EQ_ARRAY(FUN_005543e3_guess_entry*, 0x00851200)

// EXTERNAL: TITANIUM 0x0042429E NextPrimeCandidate_guess
int __cdecl NextPrimeCandidate_guess(int requested);

// EXTERNAL: TITANIUM 0x0060E985 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* memory);

struct FUN_0055419c_guess_member {
    int field_0;
    FUN_0055419c_guess_member() : field_0(0) {}
    // EXTERNAL: TITANIUM 0x00571F70 FUN_0055419c_guess_member::Initialize_guess
    void Initialize_guess(int value);
    ~FUN_0055419c_guess_member() { field_0 = 0; }
};

struct SkillRankText_guess {
    int field_0;
    int field_4;
    FUN_0055419c_guess_member field_8;
    SkillRankText_guess(int value1, int value2, int value3);
    // EXTERNAL: TITANIUM 0x0060D071 ??2SkillRankText_guess@@SAPAXI@Z
    static void* operator new(unsigned int size_guess);
};

// EXTERNAL: TITANIUM 0x0060E3A3 _atol
extern "C" long __cdecl atol(const char* text);

// Destructor of the skill picker window (CSkillsSelectWnd, vtable 0x65C958): clears +0x15C, then runs
// the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00553DAE
void CSkillsSelectWndView_guess::Destroy_guess() {
    field_15c = 0;
    vtable = &EQ_GLOBAL(char, 0x0065C958);
    return ((CSidlScreenWnd*)(FUN_005543d8_guess_object*)this)->~CSidlScreenWnd();
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Scalar deleting destructor of the skill picker window (vtable 0x65C958 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00553EDE
void* CSkillsSelectWndView_guess::DeleteThis_guess(unsigned char flags) {
    Destroy_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// A click on the watched list (field_164) goes to the owner at field_15c; everything else to the
// base class.
// FUNCTION: TITANIUM 0x00553DCE
void CSkillsSelectWndView_guess::WndNotification_guess(int value1, int value2, int value3) {
    if (value2 == 1 && value1 == field_164 && field_15c != 0) {
        ((FUN_00553dce_guess_interface*)field_15c)->Slot20_guess(value1, 1, value3);
    } else {
        WndNotification(value1, value2, value3);
    }
}

struct SkillsSelectString_guess : CXStr {
    // EXTERNAL: TITANIUM 0x004D95D0 SkillsSelectString_guess::IsEmpty_guess
    bool IsEmpty_guess();
};

struct CSkillsSelectWnd_guess {
    char pad_0[0x15c];
    int field_15c_guess;                    // 0x15C
    int field_160_guess;                    // 0x160
    CListWnd* list_164_guess;               // 0x164
    int skillMask_0168_guess;                    // 0x168
    // EXTERNAL: TITANIUM 0x00553F90 CSkillsSelectWnd_guess::FillList_guess
    void FillList_guess(int value_guess);
    SkillsSelectString_guess GetSkillName_guess(int skillId);
    void AddSkill_guess(int skillId);
    void Refresh_guess();
    bool AboutToShow_guess();
};

struct SkillsSelectGlobal_guess {
    // EXTERNAL: TITANIUM 0x00492874 SkillsSelectGlobal_guess::GetInnateDesc_guess
    char* GetInnateDesc_guess(int value);
    // EXTERNAL: TITANIUM 0x00492595 SkillsSelectGlobal_guess::GetLangDesc_guess
    const char* GetLangDesc_guess(unsigned int value);
};

struct SkillsSelectCharData_guess {
    // EXTERNAL: TITANIUM 0x005F0A00 SkillsSelectCharData_guess::FUN_005f0a00_guess
    int FUN_005f0a00_guess(int index);
};

struct SkillsSelectEntity_guess {
    char pad_0[0x208];
    const char* field_208_guess;            // 0x208
};

struct SkillsSelectManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 SkillsSelectManager_guess::GetSpell_guess
    SkillsSelectEntity_guess* GetSpell_guess(int index);
};

// Name for picker id `skillId`: skill string, innate ability (GetInnateDesc_guess), or for 132-231 the name
// of the ability's spell; empty otherwise.
// FUNCTION: TITANIUM 0x00553E0F
SkillsSelectString_guess CSkillsSelectWnd_guess::GetSkillName_guess(int skillId) {
    SkillsSelectString_guess name;
    if (skillId >= 0 && skillId < 100) {
        name.CXStr::operator=(pStringTable->getString(g_entries_851200_guess[skillId]->field_0, 0));
    } else if (skillId >= 100 && skillId < 0x84) {
        name.CXStr::operator=(EQ_GLOBAL(SkillsSelectGlobal_guess*, 0x00988DF0)->GetInnateDesc_guess(skillId - 100));
    } else if (skillId >= 0x84 && skillId < 0xe8) {
        int index = EQ_GLOBAL(SkillsSelectCharData_guess*, 0x00905D00)->FUN_005f0a00_guess(skillId - 0x84);
        SkillsSelectEntity_guess* entity = EQ_GLOBAL(SkillsSelectManager_guess*, 0x00985CC8)->GetSpell_guess(index);
        if (entity != 0) {
            name.CXStr::operator=(entity->field_208_guess);
        }
    }
    return name;
}

// Adds skill `skillId` to the select list under its name (0x00553E0F) with the id as item data, when the
// skill has a name; +0x160 counts the rows.
// FUNCTION: TITANIUM 0x00553EFA
void CSkillsSelectWnd_guess::AddSkill_guess(int skillId) {
    SkillsSelectString_guess unused;
    SkillsSelectString_guess name = GetSkillName_guess(skillId);
    if (!name.IsEmpty_guess()) {
        int index = list_164_guess->AddString(name, 0xffffffff, 0, 0);
        list_164_guess->SetItemData(index, skillId);
        ++field_160_guess;
    }
}

struct SkillsContextAction_guess {
    // EXTERNAL: TITANIUM 0x0041B0DE SkillsContextAction_guess::HasSkill_guess
    int HasSkill_guess(int mode_guess);
};

struct CHARINFO2 {
    char pad_0000[0x1114];
    int field_1114;
    char pad_1118[4];
    int field_111c;
    char pad_1120[0xc];
    int field_112c;
    char pad_1130[8];
    int field_1138;
    int field_113c;
};

struct SkillsCharacterBase_guess : EQ_Character {
    CHARINFO2* GetInfo_guess() { return GetCharInfo2(); }
};

struct SkillsCharPrefix_guess {
    int field_0_guess;
    int field_4_guess;
};

struct SkillsCharacter_guess : SkillsCharPrefix_guess, virtual SkillsCharacterBase_guess {
    char pad_00c[0xc280 - 0xc];
    SkillsContextAction_guess context_c280_guess;
};

#define g_skillsCharacter_guess EQ_GLOBAL(SkillsCharacter_guess*, 0x00905D00)

struct SkillsSelectList_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
    virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
    virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
    virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
    virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
    virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
    virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess(); virtual void Slot3F_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
    virtual void Slot4C_guess();
};

// Fills the picker for `mask`: bit 0 usable skills without the second table flag, bit 1 those with it, then
// the innates the character has (info bytes not 0xFF), bit 4 abilities 132-231. Remembers the mask for
// refreshes.
// FUNCTION: TITANIUM 0x00553F90
// @early-stop: budget, structural ndiff=71
void CSkillsSelectWnd_guess::FillList_guess(int mask) {
    CSkillsSelectWnd_guess* self = this;
    if ((mask & 0x13) != 0) {
        reinterpret_cast<SkillsSelectList_guess*>(self->list_164_guess)->Slot4C_guess();

        unsigned int both = mask & 3;
        unsigned int one = mask & 1;
        for (int skill = 0; skill < 100; ++skill) {
            bool selected = false;
            if (one != 0) {
                selected = g_skillsCharacter_guess->context_c280_guess.HasSkill_guess(skill) != 0 &&
                    g_entries_851200_guess[skill]->field_9 != 0 &&
                    g_entries_851200_guess[skill]->field_a == 0;
            }
            if ((mask & 2) != 0) {
                selected = selected || (g_skillsCharacter_guess->context_c280_guess.HasSkill_guess(skill) != 0 &&
                    g_entries_851200_guess[skill]->field_9 != 0 &&
                    g_entries_851200_guess[skill]->field_a != 0);
            }
            if (selected) {
                self->AddSkill_guess(skill);
            }
        }

        if (both != 0 && g_skillsCharacter_guess->GetInfo_guess()->field_112c != 0xff) {
            self->AddSkill_guess(0x6f);
        }
        if (both != 0 && g_skillsCharacter_guess->GetInfo_guess()->field_111c != 0xff) {
            self->AddSkill_guess(0x6b);
        }
        if (both != 0 && g_skillsCharacter_guess->GetInfo_guess()->field_1114 != 0xff) {
            self->AddSkill_guess(0x69);
        }
        if (one != 0 && g_skillsCharacter_guess->GetInfo_guess()->field_1138 != 0xff) {
            self->AddSkill_guess(0x72);
        }
        if (one != 0 && g_skillsCharacter_guess->GetInfo_guess()->field_113c != 0xff) {
            self->AddSkill_guess(0x73);
        }
        if ((mask & 0x10) != 0) {
            for (int skill = 0x84; skill < 0xe8; ++skill) {
                int value = EQ_GLOBAL(SkillsSelectCharData_guess*, 0x00905D00)->FUN_005f0a00_guess(skill - 0x84);
                if (value > 0 && EQ_GLOBAL(SkillsSelectManager_guess*, 0x00985CC8)->GetSpell_guess(value) != 0) {
                    self->AddSkill_guess(skill);
                }
            }
        }
        self->skillMask_0168_guess = mask;
    }
}

// First open fills the picker with every kind (mask 0x13).
// FUNCTION: TITANIUM 0x0055417D
bool CSkillsSelectWnd_guess::AboutToShow_guess() {
    if (skillMask_0168_guess == 0) {
        FillList_guess(0x13);
    }
    return true;
}

// Skill picker window (0x850BB8): refills its list for the remembered mask (+0x168, 0x00553F90). A
// server message handler (0x00455D86) calls it after updating the character.
// FUNCTION: TITANIUM 0x00554190
void CSkillsSelectWnd_guess::Refresh_guess() {
    FillList_guess(skillMask_0168_guess);
}

// Destructor of a skills row record: destroys its two strings (+4 and +0). The row add and refresh
// routines (0x00554B07, 0x00554C2D) use temporary rows.
// FUNCTION: TITANIUM 0x00554437
SkillRowInfo_guess::~SkillRowInfo_guess() {
}

// List sort callback: compares two cells as numbers (atol) into -1/0/1.
// FUNCTION: TITANIUM 0x0055446C
void CSkillsWndSortView_guess::CompareNumericCells_guess(FUN_0055446c_guess_argument* argument) {
    if (argument != 0) {
        long first = atol(argument->field_4.GetString_guess());
        long second = atol(argument->field_c.GetString_guess());
        if (first < second) {
            argument->field_14 = -1;
        } else {
            argument->field_14 = first > second;
        }
    }
}

// Rehashes the table into a new bucket array of 0x0042429E(`requested`) buckets (odd; prime squares can
// pass): every node is relinked at the head of bucket key % count, `count` recounts the non-empty buckets,
// and the old array is freed.
// FUNCTION: TITANIUM 0x005544AF
void IntKeyHashTable_guess::Rehash_guess(int requested) {
    FUN_005544af_guess_node** oldBuckets = buckets;
    int oldCount = bucketCount;
    bucketCount = NextPrimeCandidate_guess(requested);
    buckets = (FUN_005544af_guess_node**)operator new(bucketCount * 4);
    memset(buckets, 0, bucketCount * 4);
    count = 0;
    if (threshold > 0 && ((requested = 0), oldCount > 0)) {
        do {
            FUN_005544af_guess_node* node = oldBuckets[requested];
            while (node != 0) {
                FUN_005544af_guess_node* current = node;
                unsigned int hash = current->key;
                FUN_005544af_guess_node** link = &node->next;
                node = *link;
                hash %= (unsigned int)bucketCount;
                FUN_005544af_guess_node* head = buckets[hash];
                if (head == 0) {
                    *link = 0;
                    buckets[hash] = current;
                    ++count;
                } else {
                    *link = head;
                    buckets[hash] = current;
                }
            }
            ++requested;
        } while (requested < oldCount);
    }
    _free(oldBuckets);
}

// Custom rank text entry: skill id, minimum value, text.
// FUNCTION: TITANIUM 0x0055419C
SkillRankText_guess::SkillRankText_guess(int value1, int value2, int value3) {
    field_0 = value1;
    field_4 = value2;
    field_8.Initialize_guess(value3);
}

// OP_UpdateAA with no payload.
// FUNCTION: TITANIUM 0x005541DB
void __cdecl RequestUpdateAA_guess() {
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), OP_UpdateAA, 0, 0, 1);
}

// Local polymorphic base for the window ctor: 0x5A3900 is CSidlScreenWnd's (CXWnd*, const CXStr&) ctor.
struct SkillsWindowBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1SkillsWindowBase_guess@@UAE@XZ
    virtual ~SkillsWindowBase_guess();
    char pad_004_guess[0x120];
    void* sidlPiece_124_guess;              // 0x124
    char pad_128_guess[0x30];
    // EXTERNAL: TITANIUM 0x005A3900 ??0SkillsWindowBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    SkillsWindowBase_guess(CXWnd* parent, const CXStr& screen);
};

struct SkillsList_guess : CListWnd {
    char pad_140_guess[0x154 - 0x140];
    int field_154_guess;                    // 0x154
    char pad_158_guess[0x159 - 0x158];
    unsigned char field_159_guess;          // 0x159
    char pad_15a_guess[0x15c - 0x15a];
    unsigned char field_15c_guess;          // 0x15C
    char pad_15d_guess[0x160 - 0x15d];
    int field_160_guess;                    // 0x160
    char pad_164_guess[0x16c - 0x164];
    unsigned int field_16c_guess;           // 0x16C

    // EXTERNAL: TITANIUM 0x0059B3E0 SkillsList_guess::SetItemColor_guess
    void SetItemColor_guess(int index, int column, unsigned long color);
    // EXTERNAL: TITANIUM 0x0059B360 SkillsList_guess::SetItemText
    void SetItemText(int index, int column, const CXStr& text);

    void Setup_guess() {
        field_159_guess = 1;
        field_160_guess = 0x10;
    }
};

// EXTERNAL: TITANIUM 0x0065CB50 ??_7CSkillsWnd_guess@@6B@
struct CSkillsWnd_guess : SkillsWindowBase_guess {
    int field_158_guess;                    // 0x158
    int field_15c_guess;                    // 0x15C
    int field_160_guess;                    // 0x160
    int rowCount_0164_guess;                    // 0x164
    SkillsList_guess* list_168_guess;       // 0x168
    CXWnd* done_16c_guess;                  // 0x16C
    CXWnd* hotKey_170_guess;                // 0x170

    CSkillsWnd_guess(CXWnd* parent);
    bool GetSkillRowInfo_guess(int skillId, SkillRowInfo_guess* row);
    void AddRow_guess(int skillId);
    void UpdateRow_guess(int index);
};

// EXTERNAL: TITANIUM 0x0060B580 WriteUIError_guess
void __cdecl WriteUIError_guess(const char* message);

// Binds SkillList (name, rank, value columns), DoneButton and MakeHotKeyButton (disabled until a skill is
// picked).
// FUNCTION: TITANIUM 0x005541F4
CSkillsWnd_guess::CSkillsWnd_guess(CXWnd* parent)
    : SkillsWindowBase_guess(parent, "SkillsWindow") {
    if (sidlPiece_124_guess != 0) {
        ((CSidlScreenWnd*)this)->WindowStyle |= 0x10000;
        field_158_guess = 0xf;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        list_168_guess = (SkillsList_guess*)((CSidlScreenWnd*)this)->GetChildItem("SkillList");
        if (list_168_guess == 0) {
            WriteUIError_guess("SkillsWindow error: could not find child 'SkillList'");
        } else {
            list_168_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            list_168_guess->SetColumnJustification(0, 0);
            list_168_guess->SetColumnJustification(1, 1);
            list_168_guess->SetColumnJustification(2, 1);
            list_168_guess->Setup_guess();
            list_168_guess->field_16c_guess = 0xff8aa3ff;
            list_168_guess->field_15c_guess = 1;
            list_168_guess->WindowStyle |= 0x40000;
            list_168_guess->field_154_guess = 0;
        }
        done_16c_guess = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        hotKey_170_guess = ((CSidlScreenWnd*)this)->GetChildItem("MakeHotKeyButton");
        if (hotKey_170_guess != 0) {
            hotKey_170_guess->Enabled = 0;
        }
        rowCount_0164_guess = 0;
        field_15c_guess = 0;
        field_160_guess = 0;
    }
}

// Destructor of the Skills window (vtable 0x65CB50): restores its vtable and runs the CSidlScreenWnd
// destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x005543D8
void __fastcall DestroySkillsWnd_guess(FUN_005543d8_guess_object* self) {
    self->vtable = &EQ_GLOBAL(char, 0x0065CB50);
    ((CSidlScreenWnd*)self)->~CSidlScreenWnd();
}

// MakeHotKey is enabled for an activatable skill (table +4 > 0) other than SkillHandtoHand.
// FUNCTION: TITANIUM 0x005543E3
void CSkillsWndSelectionView_guess::UpdateHotKeyButton_guess() {
    if (field_15c >= 0 && field_168 != 0) {
        int index = field_168->GetItemData(field_15c);
        if (index < 100 && g_entries_851200_guess[index]->field_4 > 0 && field_170 != 0 && index != 0x1c) {
            field_170->enabled_005d_guess = 1;
        } else if (field_170 != 0) {
            field_170->enabled_005d_guess = 0;
        }
    }
}

struct Str_guess {
    char* data_guess;   // 0x00

    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571F70 Str_guess::Assign_guess
    void Assign_guess(const Str_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* data_guess);

    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
    }
};

struct FUN_00554557_guess_item {
    int field0_guess;
    int field4_guess;
    Str_guess field8_guess;
};

struct FUN_00554557_guess_list {
    int count_guess;
    int field_4_guess;
    int field_8_guess;
    bool field_c_guess;
    FUN_00554557_guess_list() {
        field_4_guess = 0;
        count_guess = 0;
        field_8_guess = 0;
        field_c_guess = true;
    }
    // EXTERNAL: TITANIUM 0x0060D071 ??2FUN_00554557_guess_list@@SAPAXI@Z
    static void* operator new(unsigned int size_guess);
    // EXTERNAL: TITANIUM 0x004EB905 FUN_00554557_guess_list::At_guess
    FUN_00554557_guess_item* At_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0050319B FUN_00554557_guess_list::Set_guess
    void Set_guess(int index_guess, int* value_guess);
};

struct FUN_00554557_guess_entry {
    FUN_00554557_guess_list* list_guess;
};

struct SkillRankTextMap_guess {
    // EXTERNAL: TITANIUM 0x004FF9C9 SkillRankTextMap_guess::Find_guess
    FUN_00554557_guess_entry* Find_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x00447C66 SkillRankTextMap_guess::Insert_guess
    void Insert_guess(FUN_00554557_guess_entry* source_guess, unsigned int hash_guess);
    Str_guess Get_guess(int key_guess, int threshold_guess);
    void Add_guess(int key_guess, int id_guess, int value_guess);
};

// Custom rank text for skill `key_guess` at value `threshold_guess`: the last entry whose minimum is
// 1..threshold.
// FUNCTION: TITANIUM 0x00554557
Str_guess SkillRankTextMap_guess::Get_guess(int key_guess, int threshold_guess) {
    Str_guess result_guess(EQ_ARRAY(char, 0x0063F53F));
    FUN_00554557_guess_entry* entry_guess = Find_guess(key_guess);
    if (entry_guess != 0) {
        int count_guess = entry_guess->list_guess->count_guess;
        for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
            FUN_00554557_guess_item* item_guess = entry_guess->list_guess->At_guess(i_guess);
            if (item_guess->field4_guess <= threshold_guess && item_guess->field4_guess > 0) {
                result_guess.Assign_guess(item_guess->field8_guess);
            }
        }
    }
    return result_guess;
}

// Scalar deleting destructor of the Skills window (vtable 0x65CB50 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x005545FA
void* CSkillsWndDtorView_guess::DeleteThis_guess(unsigned char flags) {
    this->CSkillsWndDtorView_guess::~CSkillsWndDtorView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

struct FUN_00554616_guess_list {
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();
    char pad_004[0x150];
    void* field_154;
    char field_158;
    // EXTERNAL: TITANIUM 0x00597BE0 FUN_00554616_guess_list::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 FUN_00554616_guess_list::GetItemData
    int GetItemData(int index);
};

struct CSkillsWndView_guess {
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
    char pad_004[0x158];
    int field_15c;
    char pad_160[8];
    FUN_00554616_guess_list* field_168;
    void* field_16c;
    void* field_170;
    int Notify_guess(void* sender, int message, void* data);
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    int getString(unsigned long id, bool* mode);
};

struct FUN_00554616_guess_client {
    // EXTERNAL: TITANIUM 0x004FD91E FUN_00554616_guess_client::Report_guess
    void Report_guess(int first, int second, int third, int fourth, int fifth);
};

#define g_stringTable_00554616_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define pinstCCursorAttachment_guess EQ_GLOBAL(FUN_00554616_guess_client*, 0x00850C24)

// Done closes; MakeHotKey creates a type-11 (skill) hotkey for the selected skill; a list click selects.
// Message 0xF sorts the list.
// FUNCTION: TITANIUM 0x00554616
int CSkillsWndView_guess::Notify_guess(void* sender, int message, void* data) {
    if (message == 1) {
        if (sender == field_16c) {
            Slot34_guess();
            return 1;
        }
        if (sender == field_170) {
            if (field_15c < 0) {
                return 1;
            }
            if (field_168 == 0) {
                return 1;
            }
            int index = field_168->GetItemData(field_15c);
            if (index < 100) {
                pinstCCursorAttachment_guess->Report_guess(0, 0xb, index,
                    g_stringTable_00554616_guess->getString(
                        g_entries_851200_guess[index]->field_0, 0), -1);
            }
        } else if (sender == field_168) {
            field_15c = field_168->GetCurSel();
            ((CSkillsWndSelectionView_guess*)this)->UpdateHotKeyButton_guess();
            return 1;
        }
    } else if (message == 0xf) {
        if (sender == field_168) {
            if (field_168->field_154 == data) {
                field_168->field_158 = field_168->field_158 == 0;
            } else {
                field_168->field_154 = data;
                field_168->field_158 = 1;
            }
            field_168->Slot78_guess();
            return 1;
        }
    } else if (message == 0x10 && sender == field_168 && *(int*)data == 2) {
        ((CSkillsWndSortView_guess*)this)->CompareNumericCells_guess((FUN_0055446c_guess_argument*)data);
        return 1;
    }
    return ((CSkillsSelectWndView_guess*)this)->WndNotification((int)sender, message, (int)data);
}

// Constructor of the custom skill rank text map (0x991FA8): a hash table with 100 buckets requested
// (0x0042F092, rounded up to 101). Made by the CEverQuest constructor (0x004A3341).
// FUNCTION: TITANIUM 0x0055474C
HashTableInitView_guess* HashTableInitView_guess::ReturnThis_guess() {
    FUN_0042f092_guess(100);
    return this;
}

struct SkillsWindowSkillValue_guess {
    // EXTERNAL: TITANIUM 0x0040E722 SkillsWindowSkillValue_guess::GetSkill_guess
    int GetSkill_guess(int skillId);
};

struct SkillsWindowSkillCap_guess {
    // EXTERNAL: TITANIUM 0x0041ACE9 SkillsWindowSkillCap_guess::Skill_guess
    int Skill_guess(int skillId);
};

struct SkillsWindowSkillBytes_guess {
    char pad_000_guess[0x0C];
    unsigned char values_guess[0x20];
};

struct SkillsWindowCharInfo_guess {
    char pad_000_guess[0x119C];
    unsigned char level_guess;
    char pad_119D_guess[7];
    int maximum_guess;
};

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* buffer, int messageId, const char* value,
    int arg4, int arg5, int arg6, int arg7, int arg8, int arg9, int arg10, int arg11);

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* output, const char* format, ...);

// Row data for `skillId`: name, rank text, base value (field_8) and the value shown (field_c, Skill_guess).
// Languages 100-131 use the language bytes. A skill at 0 that the class can learn but not yet use shows
// "LEVEL: %1" (string 2161) with the level it opens at. An out-of-range language index hits an int 3
// (__debugbreak).
// FUNCTION: TITANIUM 0x0055475A
// @early-stop: budget, structural ndiff=100
bool CSkillsWnd_guess::GetSkillRowInfo_guess(int skillId, SkillRowInfo_guess* row) {
    char messageBuffer_guess[1024];
    bool result_guess = false;
    unsigned int skillIndex_guess;
    EQ_PC* character_guess;

    do {
        if (skillId < 100) {
            row->name_0000_guess.CXStr::operator=(pStringTable->getString(g_entries_851200_guess[skillId]->field_0, 0));
            character_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
            row->skillValue_0008_guess = ((SkillsWindowSkillValue_guess*)&character_guess->Character)->GetSkill_guess(skillId);
            row->field_c_guess = ((SkillsWindowSkillCap_guess*)&character_guess->vftable_C280)->Skill_guess(skillId);
        } else {
            if (skillId >= 0x84) {
                break;
            }
            skillIndex_guess = (unsigned int)(skillId - 100);
            row->name_0000_guess.CXStr::operator=(EQ_GLOBAL(SkillsSelectGlobal_guess*, 0x00988DF0)->GetLangDesc_guess(skillIndex_guess));
            character_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
            if (skillIndex_guess < 0x20) {
                row->skillValue_0008_guess = ((SkillsWindowSkillBytes_guess*)&character_guess->Character)->values_guess[skillIndex_guess];
            } else {
                __debugbreak();
            }
            character_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
            if (skillIndex_guess < 0x20) {
                row->field_c_guess = ((SkillsWindowSkillBytes_guess*)&character_guess->Character)->values_guess[skillIndex_guess];
            } else {
                __debugbreak();
            }
        }

        result_guess = true;
        int category_guess = 0;
        while (category_guess < 11 && row->skillValue_0008_guess > EQ_ARRAY(unsigned int, 0x0065CAA0)[category_guess]) {
            ++category_guess;
        }
        if (category_guess == 9 && skillId > 99 && row->skillValue_0008_guess == 100) {
            category_guess = 10;
        }

        bool overrideText_guess = false;
        if (row->skillValue_0008_guess == 0 && skillId < 100) {
            EQ_PC* statusCharacter_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
            EQ_CharacterProfile_guess* profile_guess = (EQ_CharacterProfile_guess*)&statusCharacter_guess->Character.list;
            if (g_entries_851200_guess[skillId]->FUN_0044a335_guess(
                    ((SkillsWindowCharInfo_guess*)profile_guess->GetCharInfo2())->level_guess) != 0) {
                statusCharacter_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
                profile_guess = (EQ_CharacterProfile_guess*)&statusCharacter_guess->Character.list;
                unsigned char level_guess = ((SkillsWindowCharInfo_guess*)profile_guess->GetCharInfo2())->level_guess;
                statusCharacter_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
                profile_guess = (EQ_CharacterProfile_guess*)&statusCharacter_guess->Character.list;
                int maximum_guess = ((SkillsWindowCharInfo_guess*)profile_guess->GetCharInfo2())->maximum_guess;
                if (maximum_guess < g_entries_851200_guess[skillId]->FUN_0044a2e4_guess(level_guess)) {
                    statusCharacter_guess = EQ_GLOBAL(EQ_PC*, 0x00905D00);
                    profile_guess = (EQ_CharacterProfile_guess*)&statusCharacter_guess->Character.list;
                    FUN_0046da4a_guess(messageBuffer_guess, 0x871,
                        _itoa(g_entries_851200_guess[skillId]->FUN_0044a2e4_guess(
                            ((SkillsWindowCharInfo_guess*)profile_guess->GetCharInfo2())->level_guess),
                            EQ_ARRAY(char, 0x0099DB00), 10),
                        0, 0, 0, 0, 0, 0, 0, 0);
                    FormatString_guess(&row->valueText_0004_guess, messageBuffer_guess);
                    overrideText_guess = true;
                }
            }
        }

        if (!overrideText_guess) {
            Str_guess skillText_guess = EQ_GLOBAL(SkillRankTextMap_guess*, 0x00991FA8)->Get_guess(
                skillId, row->skillValue_0008_guess);
            if (skillText_guess.data_guess != 0 && ((CStrRep*)skillText_guess.data_guess)->length > 0) {
                row->valueText_0004_guess.CXStr::operator=(*(CXStr*)&skillText_guess);
            } else {
                row->valueText_0004_guess.CXStr::operator=(pStringTable->getString(
                    EQ_ARRAY(int, 0x0065CACC)[category_guess], 0));
            }
        }
    } while (0);
    return result_guess;
}

// Adds a custom rank text for skill `key_guess` unless that id is already listed.
// FUNCTION: TITANIUM 0x00554A08
// @early-stop: budget, diff ndiff=3
void SkillRankTextMap_guess::Add_guess(int key_guess, int id_guess, int value_guess) {
    FUN_00554557_guess_entry holder_guess;
    FUN_00554557_guess_entry* entry_guess = Find_guess(key_guess);
    if (entry_guess == 0) {
        holder_guess.list_guess = new FUN_00554557_guess_list;
        entry_guess = &holder_guess;
        Insert_guess(entry_guess, key_guess);
    }
    int count_guess = entry_guess->list_guess->count_guess;
    for (int i_guess = 0; i_guess < count_guess; ++i_guess) {
        if (entry_guess->list_guess->At_guess(i_guess)->field4_guess == id_guess) {
            return;
        }
    }
    key_guess = (int)new SkillRankText_guess(key_guess, id_guess, value_guess);
    entry_guess->list_guess->Set_guess(entry_guess->list_guess->count_guess, &key_guess);
}

struct FUN_00554ac1_guess_array {
    int count;
    // EXTERNAL: TITANIUM 0x00564298 FUN_00554ac1_guess_array::DeleteElement_guess
    void DeleteElement_guess(int index);
    // EXTERNAL: TITANIUM 0x0050F3F6 FUN_00554ac1_guess_array::Clear_guess
    void Clear_guess();
};

struct FUN_00554ac1_guess_entry {
    FUN_00554ac1_guess_array* array;
};

struct SkillRankTextMapView_guess {
    // EXTERNAL: TITANIUM 0x004466FA SkillRankTextMapView_guess::Begin_guess
    FUN_00554ac1_guess_entry* Begin_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A SkillRankTextMapView_guess::Next_guess
    FUN_00554ac1_guess_entry* Next_guess(FUN_00554ac1_guess_entry* entry);
    // EXTERNAL: TITANIUM 0x0048F513 SkillRankTextMapView_guess::Finish_guess
    void Finish_guess();
    void ClearAll_guess();
};

// Empties the map: for every entry deletes all elements of its array, then clears and frees the array;
// finally frees all hash nodes (0x0048F513).
// FUNCTION: TITANIUM 0x00554AC1
void SkillRankTextMapView_guess::ClearAll_guess() {
    FUN_00554ac1_guess_entry* entry = Begin_guess();
    while (entry != 0) {
        FUN_00554ac1_guess_array* array = entry->array;
        entry = Next_guess(entry);
        while (array->count != 0) {
            array->DeleteElement_guess(0);
        }
        array->Clear_guess();
        free(array);
    }
    Finish_guess();
}

#define g_countFormat_guess EQ_ARRAY(char, 0x0063F53C)

struct PcStatusPrefix_guess {
    void* vftable_guess;                    // 0x00
    int field_04_guess;                     // 0x04
};

struct StatusBase_guess {
    int unused_guess;
    // EXTERNAL: TITANIUM 0x004167E2 StatusBase_guess::GetStatus_guess
    int GetStatus_guess();
};

// pCharData: the status object is a virtual base at +0xC384, reached through the vbptr at +8.
struct PcStatusView_guess : PcStatusPrefix_guess, virtual StatusBase_guess {
    unsigned char pad_0C_guess[0xC384 - 0x0C];
};

#define g_pcStatus_guess EQ_GLOBAL(PcStatusView_guess*, 0x00905D00)

// Adds the row, skipped when a status check is on and the shown value is 0. The value turns red when below
// the base value and green when above.
// FUNCTION: TITANIUM 0x00554B07
void CSkillsWnd_guess::AddRow_guess(int skillId) {
    SkillRowInfo_guess row;
    if (GetSkillRowInfo_guess(skillId, &row)) {
        if (g_pcStatus_guess != 0 && g_pcStatus_guess->GetStatus_guess() != 0 && row.field_c_guess <= 0) {
            return;
        }
        CXStr text;
        int index = list_168_guess->AddString(row.name_0000_guess, 0xffffffff, 0, 0);
        text = row.valueText_0004_guess;
        list_168_guess->SetItemText(index, 1, text);
        FormatString_guess(&text, g_countFormat_guess, row.field_c_guess);
        list_168_guess->SetItemText(index, 2, text);
        unsigned int color = 0xffffffff;
        if (row.skillValue_0008_guess > row.field_c_guess) {
            color = 0xffff0000;
        } else if (row.skillValue_0008_guess < row.field_c_guess) {
            color = 0xff00ff00;
        }
        list_168_guess->SetItemColor_guess(index, 2, color);
        list_168_guess->SetItemData(index, skillId);
        ++rowCount_0164_guess;
    }
}

// Refreshes row `index` in place, same text and colours as AddRow_guess.
// FUNCTION: TITANIUM 0x00554C2D
void CSkillsWnd_guess::UpdateRow_guess(int index) {
    if (list_168_guess != 0 && index >= 0 && index < rowCount_0164_guess) {
        int skillId = (int)list_168_guess->GetItemData(index);
        if (skillId >= 0) {
            SkillRowInfo_guess row;
            if (GetSkillRowInfo_guess(skillId, &row)) {
                CXStr text;
                text = row.name_0000_guess;
                list_168_guess->SetItemText(index, 0, text);
                text = row.valueText_0004_guess;
                list_168_guess->SetItemText(index, 1, text);
                FormatString_guess(&text, g_countFormat_guess, row.field_c_guess);
                list_168_guess->SetItemText(index, 2, text);
                unsigned int color = 0xffffffff;
                if (row.skillValue_0008_guess > row.field_c_guess) {
                    color = 0xffff0000;
                } else if (row.skillValue_0008_guess < row.field_c_guess) {
                    color = 0xff00ff00;
                }
                list_168_guess->SetItemColor_guess(index, 2, color);
                list_168_guess->SetItemData(index, skillId);
                // Counts the row again; kept as decompiled (bug or decomp error).
                ++rowCount_0164_guess;
            }
        }
    }
}

