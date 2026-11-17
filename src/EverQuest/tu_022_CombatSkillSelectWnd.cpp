// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 22: a hint from compare/tumap.py.
// Actor collision callbacks, then the Combat Skill Select window (screen "CombatSkillSelectWnd", vtable
// 0x641898): a sortable list of the 100 combat-ability slots, a description box and Make Hotkey.
// CCombatSkillSelectWnd_guess, SkillNotifyWnd_guess, TimerText_guess, FeatureHost_guess, TargetOwner_guess,
// State_guess and Initializer_guess are all views of that window.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct Initializer_guess {
    void* vtable_guess;
    // EXTERNAL: TITANIUM 0x005A3100 Initializer_guess::Initialize_guess
    void Initialize_guess();
    void SetVtableAndInitialize_guess();
    void* Delete_guess(unsigned char flags);
};

struct InitializerCall_guess {
    // EXTERNAL: TITANIUM 0x0042D15C InitializerCall_guess::Run_guess
    void Run_guess();
};

struct PredicateObject_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual char* GetBytes_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual int GetState_guess();
    virtual void Slot09_guess();
    virtual float Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual int GetFlags_guess();
};

struct ByteSequence_guess {
    // EXTERNAL: TITANIUM 0x004903F1 ByteSequence_guess::IsReady_guess
    char IsReady_guess();
};

struct TargetStatus_guess {
    char pad_0_guess[0x150];
    unsigned char field_150_guess;
    char pad_151_guess[0xe43];
    char* field_f94_guess;
};

struct TargetInner_guess {
    TargetStatus_guess* status_guess;
};

struct TargetData_guess {
    unsigned char kind_guess;
    char pad_1_guess[0x1a7];
    TargetInner_guess inner_guess;
    // EXTERNAL: TITANIUM 0x0047F7DC TargetData_guess::Refresh_guess
    void Refresh_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct State_guess {
    char pad_0_guess[0x15c];
    int field_15c_guess;
    int field_160_guess;
    int field_164_guess;
    int field_168_guess;
    int field_16c_guess;
    int field_170_guess;
    void Clear_guess();
};

struct TargetChild_guess {
    char pad_0_guess[0x66];
    unsigned char flags_guess;
    char pad_67_guess[0xED];
    int field_154_guess;
    char pad_158_guess;
    unsigned char field_159_guess;
    char pad_15a_guess[2];
    unsigned char field_15c_guess;
    char pad_15d_guess[3];
    int field_160_guess;
    char pad_164_guess[8];
    int field_16c_guess;
    // EXTERNAL: TITANIUM 0x00597C60 TargetChild_guess::SetColors
    void SetColors(int first, int second, int third);
};

struct TargetOther_guess {
    char pad_0_guess[0x5D];
    unsigned char enabled_005d_guess;
};

struct TargetOwner_guess {
    char pad_0_guess[0x168];
    TargetChild_guess* child_guess;
    int pad_16c_guess;
    TargetOther_guess* other_guess;
    int field_174_guess;
    int field_178_guess;
    void SetupList_guess();
};

struct AdjustedBase_guess {
    // EXTERNAL: TITANIUM 0x004482FB AdjustedBase_guess::Target_guess
    void Target_guess();
};

struct AdjustedObject_guess {
    int pad_0_guess;
    AdjustedBase_guess base_guess;
    void Thunk_guess();
};

struct VectorElement_guess {
    int value_0_guess;
    int value_4_guess;
    int value_8_guess;
    // EXTERNAL: TITANIUM 0x0042D14E VectorElement_guess::VectorElement_guess
    VectorElement_guess();
    // EXTERNAL: TITANIUM 0x0042D3A8 VectorElement_guess::~VectorElement_guess
    ~VectorElement_guess();
    // EXTERNAL: TITANIUM 0x0042D3A8 VectorElement_guess::Destroy_guess
    void Destroy_guess();
    void* DeleteVector_guess(unsigned char flags);
};

struct CopyObject_guess;

struct BufferOwner_guess {
    int count_guess;
    VectorElement_guess* elements_guess;
    int capacity_guess;
    unsigned char field_c_guess;
    void Clear_guess();
    void ClearAlias_guess();
    void Resize_guess(int requested_guess);
    void SetElement_guess(int index_guess, CopyObject_guess* value_guess);
};

struct FirstManager_guess {
    // EXTERNAL: TITANIUM 0x005F0A00 FirstManager_guess::GetValue_guess
    int GetValue_guess(int value);
};

struct SecondManager_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 SecondManager_guess::GetSpell_guess
    int GetSpell_guess(int value);
};

struct CopyMiddle_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571F70 CopyMiddle_guess::Copy_guess
    void Copy_guess(const CopyMiddle_guess* other);
};

struct CopyObject_guess {
    int field_0_guess;
    CopyMiddle_guess field_4_guess;
    int field_8_guess;
    CopyObject_guess* Copy_guess(CopyObject_guess* other);
};

#define g_firstManager_guess EQ_GLOBAL(FirstManager_guess*, 0x00905D00)
#define g_secondManager_guess EQ_GLOBAL(SecondManager_guess*, 0x00985CC8)
#define g_callbackEnabled_guess EQ_GLOBAL(unsigned char, 0x009237B5)
#define g_currentPredicate_guess EQ_GLOBAL(PredicateObject_guess*, 0x00850CC8)

struct FrameClock_guess {
    char pad_0_guess[0x148];
    unsigned int now_guess;
};
#define g_frameClock_guess EQ_GLOBAL(FrameClock_guess*, 0x00905D24)

// Collision hit callback of the player sweep (tu_055): records what was hit in the mover's status
// (+0x150): a small type code, or the actor's kind byte (3 spawn, 5 door); a door that opens on bump
// (0x4903F1) goes to +0xF94 and 0x47F7DC runs. Returns 1 if it blocks; flag-4 actors, the actor at
// 0x850CC8 (probably the mover's own) and kind 1 never do.
// FUNCTION: TITANIUM 0x0042CDB1
int __cdecl RecordCollisionHit_guess(PredicateObject_guess* object, char* input) {
    int result = 0;
    char* target = 0;
    if ((object->GetFlags_guess() & 4) != 0) {
        return 0;
    }
    if (*input == 3) {
        target = input;
    }
    if (g_callbackEnabled_guess == 0) {
        return 0;
    }
    char* bytes = object->GetBytes_guess();
    if (object != g_currentPredicate_guess) {
        if ((unsigned int)bytes < 0x11) {
            result = 1;
            ((TargetData_guess*)target)->inner_guess.status_guess->field_150_guess = (unsigned char)bytes;
        } else if (*bytes == 1) {
            ((TargetData_guess*)target)->inner_guess.status_guess->field_150_guess = 1;
        } else {
            result = 1;
            TargetStatus_guess** status = &((TargetData_guess*)target)->inner_guess.status_guess;
            (*status)->field_150_guess = (unsigned char)*bytes;
            if (*bytes == 5 && ((ByteSequence_guess*)bytes)->IsReady_guess()) {
                (*status)->field_f94_guess = bytes;
                ((TargetData_guess*)target)->Refresh_guess();
            }
        }
    }
    return result;
}

struct ByteFlag_guess {
    // EXTERNAL: TITANIUM 0x00490370 ByteFlag_guess::Check_guess
    char Check_guess();
};

struct PredicateHolder_guess;

struct PredicateOwner_guess {
    char pad_0_guess[0x1a8];
    PredicateHolder_guess* holder_guess;
};

struct PredicateHolder_guess {
    PredicateObject_guess* object_guess;
    char pad_4_guess[0x158];
    PredicateOwner_guess* left_guess;
    PredicateOwner_guess* right_guess;
};

// Collision filter, false = pass through: flag-1 actors, kind 1, the mover itself and its two linked
// actors (+0x15C/+0x160, probably mount and rider), doors 0x490370 calls open, and actors in a state
// other than 0 or 1 with a nonzero slot-10 value.
// FUNCTION: TITANIUM 0x0042D05F
int __cdecl CanCollideWith_guess(PredicateObject_guess* object, PredicateOwner_guess* owner) {
    if ((object->GetFlags_guess() & 1) != 0) {
        return false;
    }
    int state = object->GetState_guess();
    char* bytes = object->GetBytes_guess();
    if ((unsigned int)bytes > 0x10) {
        switch (*(unsigned char*)bytes) {
        case 1:
            return false;
        case 3:
            if (owner != 0) {
                PredicateHolder_guess* holder = owner->holder_guess;
                if (object == holder->object_guess) {
                    return false;
                }
                if (holder->left_guess != 0 && object == holder->left_guess->holder_guess->object_guess) {
                    return false;
                }
                if (holder->right_guess != 0 && object == holder->right_guess->holder_guess->object_guess) {
                    return false;
                }
            }
            break;
        case 5:
            return ((ByteFlag_guess*)bytes)->Check_guess() != 0;
        }
    }
    if (state != 0 && state != 1 && object->Slot10_guess() != 0.0f) {
        return false;
    }
    return true;
}

// Filter of the upward ray test in tu_029: ignores doors and state-2 actors.
// FUNCTION: TITANIUM 0x0042D123
int __cdecl CheckPredicate_guess(PredicateObject_guess* object) {
    if (object->GetState_guess() == 2) {
        return 0;
    }
    char* bytes = object->GetBytes_guess();
    if (bytes <= (char*)0x10 || *bytes != 5) {
        return 1;
    }
    return 0;
}

// The window's dtor: resets the vtable, then CSidlScreenWnd's.
// FUNCTION: TITANIUM 0x0042D15C
void Initializer_guess::SetVtableAndInitialize_guess() {
    vtable_guess = (void*)&EQ_GLOBAL(void*, 0x00641898);
    Initialize_guess();
}

// Zeroes the child pointers (+0x15C to +0x170) before SIDL setup.
// FUNCTION: TITANIUM 0x0042D226
void State_guess::Clear_guess() {
    field_15c_guess = 0;
    field_160_guess = 0;
    field_164_guess = 0;
    field_168_guess = 0;
    field_16c_guess = 0;
    field_170_guess = 0;
}

// Sets up the ability list (colours, row height 0x10, sortable) and disables Make Hotkey (+0x170).
// FUNCTION: TITANIUM 0x0042D314
void TargetOwner_guess::SetupList_guess() {
    field_178_guess = 0;
    if (child_guess != 0) {
        child_guess->flags_guess |= 0x20;
        child_guess->SetColors(-1, 0xffffff00, 0xff808080);
        child_guess->field_16c_guess = 0xff8aa3ff;
        TargetChild_guess* child = child_guess;
        child->field_159_guess = 1;
        child->field_160_guess = 0x10;
        child_guess->field_15c_guess = 1;
        child_guess->flags_guess |= 0x4;
        child_guess->field_154_guess = 5;
    }
    if (other_guess != 0) {
        other_guess->enabled_005d_guess = 0;
    }
    field_174_guess = 0;
}

// Destructor of a 12-byte ability list record (int, string, int): releases the string at +4
// (0x004482FB).
// FUNCTION: TITANIUM 0x0042D3A8
void AdjustedObject_guess::Thunk_guess() {
    base_guess.Target_guess();
}

// Spell record of combat-ability slot `value` (0-99): pCharData maps the slot to a spell id (0x5F0A00),
// the spell manager (0x985CC8) gives the record; 0 for an empty slot.
// FUNCTION: TITANIUM 0x0042D3B0
int __stdcall GetCombatAbilitySpell_guess(int value) {
    int result = 0;
    int index = g_firstManager_guess->GetValue_guess(value);
    if (index > 0) {
        result = g_secondManager_guess->GetSpell_guess(index);
    }
    return result;
}

struct Str_guess {
    int data_guess;
    Str_guess() : data_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 Str_guess::Str_guess
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABUSkillWindowName_guess@@@Z
    Str_guess(const struct SkillWindowName_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::Release_guess
    void Release_guess(int data_guess);
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::GetText_guess
    const char* GetText_guess();
    ~Str_guess() {
        if (data_guess != 0) {
            Release_guess(data_guess);
        }
    }
};

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(Str_guess* text_guess, const char* format_guess,
                                ...);

struct Client_022_guess {
    // EXTERNAL: TITANIUM 0x004FD36C Client_022_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int type_guess);
    // EXTERNAL: TITANIUM 0x004FD91E Client_022_guess::Report_guess
    void Report_guess(int first_guess, int second_guess, int third_guess,
                      const char* text_guess, int fifth_guess);
};

#define pinstCCursorAttachment_guess EQ_GLOBAL(Client_022_guess*, 0x00850C24)

struct TimerText_guess {
    Str_guess FormatDuration_guess(int seconds_guess);
    void MakeHotkey_guess(int id_guess, Str_guess text_guess);
    void AddAbilityRow_guess(int key_guess);
};

struct SkillWindowName_guess {
    int data_guess;
    // EXTERNAL: TITANIUM 0x00571E00 SkillWindowName_guess::SkillWindowName_guess
    SkillWindowName_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 SkillWindowName_guess::Release_guess
    void Release_guess(int data_guess);
    ~SkillWindowName_guess() {
        if (data_guess != 0) {
            Release_guess(data_guess);
        }
        data_guess = 0;
    }
};

struct SkillWindowBase_guess {
    virtual void Slot00_guess();
    virtual ~SkillWindowBase_guess() {}
    // EXTERNAL: TITANIUM 0x005A3900 SkillWindowBase_guess::SkillWindowBase_guess
    SkillWindowBase_guess(int argument_guess,
                          const SkillWindowName_guess& name_guess);
};

// EXTERNAL: TITANIUM 0x00641898 ??_7CCombatSkillSelectWnd_guess@@6B@
struct CCombatSkillSelectWnd_guess : public SkillWindowBase_guess {
    virtual void Slot00_guess();
    char pad_4_guess[0x120];
    int field_124_guess;
    char pad_128_guess[0x34];
    int field_15c_guess;
    int field_160_guess;
    int field_164_guess;
    int skillSelectorList_0168_guess;
    int skillDescriptionStmlBox_016c_guess;
    int makeHotkeyButton_0170_guess;
    int pad_174_guess;
    int lastUpdateTime_0178_guess;
    // EXTERNAL: TITANIUM 0x005A1E10 CCombatSkillSelectWnd_guess::GetChildItem
    int GetChildItem(const Str_guess& name_guess);
    void InitializeSkills_guess();
    void OnProcessFrame_guess();
    CCombatSkillSelectWnd_guess(int argument_guess);
};

// Finds the window's children: CSSW_SkillSelectorList (+0x168), CSSW_SkillDescriptionStmlBox (+0x16C)
// and CSSW_MakeHotkeyButton (+0x170).
// FUNCTION: TITANIUM 0x0042D24D
void CCombatSkillSelectWnd_guess::InitializeSkills_guess() {
    skillSelectorList_0168_guess = GetChildItem("CSSW_SkillSelectorList");
    skillDescriptionStmlBox_016c_guess = GetChildItem("CSSW_SkillDescriptionStmlBox");
    makeHotkeyButton_0170_guess = GetChildItem("CSSW_MakeHotkeyButton");
}

// OnProcessFrame: twice a second, with no row selected, disables Make Hotkey and clears the description.
// FUNCTION: TITANIUM 0x0042D167
void CCombatSkillSelectWnd_guess::OnProcessFrame_guess() {
    unsigned char shown_guess = ((CXWnd*)this)->Show;
    if (shown_guess != 0 && g_frameClock_guess->now_guess > lastUpdateTime_0178_guess + 500U) {
        if (skillSelectorList_0168_guess != 0) {
            if (((CListWnd*)skillSelectorList_0168_guess)->GetCurSel() == -1) {
                if (makeHotkeyButton_0170_guess != 0) {
                    ((CXWnd*)makeHotkeyButton_0170_guess)->Enabled = 0;
                }
                if (skillDescriptionStmlBox_016c_guess != 0) {
                    CXStr text;
                    ((CStmlWnd*)skillDescriptionStmlBox_016c_guess)->SetSTMLText(text, true, 0);
                }
            }
        }
        lastUpdateTime_0178_guess = g_frameClock_guess->now_guess;
    }
    ((CXWnd*)this)->OnProcessFrame();
}

// Formats a duration in seconds as H:MM:SS, hours unpadded (3725 -> "1:02:05"). 0x0042D827 uses it for the
// reuse-left and recast columns of the ability list.
// FUNCTION: TITANIUM 0x0042D3DA
Str_guess TimerText_guess::FormatDuration_guess(int seconds_guess) {
    Str_guess text_guess;
    int hours_guess = seconds_guess / 3600;
    int minutes_guess = seconds_guess % 3600 / 60;
    FormatString_guess(&text_guess, "%d:%02d:%02d", hours_guess, minutes_guess,
                       seconds_guess % 60);
    return text_guess;
}

// Make Hotkey: puts ability `id_guess`, labelled `text_guess`, on the cursor (CCursorAttachment type 0xC,
// combat ability). Nothing here is a duration.
// FUNCTION: TITANIUM 0x0042D462
void TimerText_guess::MakeHotkey_guess(int id_guess, Str_guess text_guess) {
    if (id_guess != -1) {
        if (pinstCCursorAttachment_guess->IsOkToActivate_guess(0xc)) {
            pinstCCursorAttachment_guess->Report_guess(0, 0xc, id_guess,
                                             text_guess.GetText_guess(), -1);
        }
    }
}

// Ability list record assignment: the int, the string and the second int.
// FUNCTION: TITANIUM 0x0042D5B4
CopyObject_guess* CopyObject_guess::Copy_guess(CopyObject_guess* other) {
    field_0_guess = other->field_0_guess;
    field_4_guess.Copy_guess(&other->field_4_guess);
    field_8_guess = other->field_8_guess;
    return this;
}

typedef void (VectorElement_guess::*VectorDtor_guess)();

// EXTERNAL: TITANIUM 0x0060D682 free_vector_guess
void __cdecl free_vector_guess(void* memory);

// EXTERNAL: TITANIUM 0x0060D6E5 eh_vector_destructor_iterator_guess
void __stdcall eh_vector_destructor_iterator_guess(void* array, unsigned int elementSize, int count, VectorDtor_guess destructor);

// Compiler vector deleting destructor for 12-byte ability records: with flag 2 the whole array (count
// in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x0042D5D9
void* VectorElement_guess::DeleteVector_guess(unsigned char flags) {
    void* allocation;
    if ((flags & 2) != 0) {
        int* header = ((int*)this) - 1;
        eh_vector_destructor_iterator_guess(this, 0xc, *header, &VectorElement_guess::Destroy_guess);
        if ((flags & 1) != 0) {
            free_vector_guess(header);
        }
        allocation = header;
    } else {
        Destroy_guess();
        if ((flags & 1) != 0) {
            free(this);
        }
        allocation = this;
    }
    return allocation;
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

// Grows the element array to 2 * requested + 8, copying the live elements over; if the allocation fails
// the array is freed and left empty.
// FUNCTION: TITANIUM 0x0042D624
void BufferOwner_guess::Resize_guess(int requested_guess) {
    if (requested_guess == 0 ||
        (requested_guess <= capacity_guess && elements_guess != 0)) {
        return;
    }

    int new_capacity_guess = requested_guess * 2 + 8;
    VectorElement_guess* new_elements_guess =
        new VectorElement_guess[new_capacity_guess];

    if (new_elements_guess != 0) {
        if (elements_guess != 0) {
            for (int index_guess = 0; index_guess < count_guess;
                 ++index_guess) {
                ((CopyObject_guess*)new_elements_guess)[index_guess]
                    .Copy_guess(&((CopyObject_guess*)elements_guess)[index_guess]);
            }
        }
        if (elements_guess != 0) {
            elements_guess->DeleteVector_guess(3);
        }
        elements_guess = new_elements_guess;
        capacity_guess = new_capacity_guess;
    } else {
        if (elements_guess != 0) {
            elements_guess->DeleteVector_guess(3);
        }
        elements_guess = 0;
        capacity_guess = 0;
        field_c_guess = 0;
    }
}

// EXTERNAL: TITANIUM 0x005A25B0 RefreshSkillWindow_guess
void __cdecl RefreshSkillWindow_guess();

// The window's ctor. Not CCharacterSelect::Deactivate (Mac match).
// FUNCTION: TITANIUM 0x0042D707
CCombatSkillSelectWnd_guess::CCombatSkillSelectWnd_guess(int argument_guess)
    : SkillWindowBase_guess(argument_guess, "CombatSkillSelectWnd") {
    ((State_guess*)this)->Clear_guess();
    if (field_124_guess != 0) {
        RefreshSkillWindow_guess();
        InitializeSkills_guess();
        ((TargetOwner_guess*)this)->SetupList_guess();
    }
}

// Scalar deleting destructor of the Combat Skill Select window (0x0042D15C; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0042D78B
void* Initializer_guess::Delete_guess(unsigned char flags) {
    ((InitializerCall_guess*)this)->Run_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// ArrayClass SetElementIdx for 12-byte records (int, string, int): stores a copy at `index`, first growing
// the array (0x0042D624) and the length to index + 1 when needed. Negative indexes are ignored, and so is
// the store when the allocation failed.
// FUNCTION: TITANIUM 0x0042D7A7
void BufferOwner_guess::SetElement_guess(int index_guess, CopyObject_guess* value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= count_guess) {
            Resize_guess(index_guess + 1);
            if (elements_guess != 0) {
                count_guess = index_guess + 1;
            }
        }
        if (elements_guess != 0) {
            ((CopyObject_guess*)elements_guess)[index_guess].Copy_guess(value_guess);
        }
    }
}

// Frees the record array (vector delete) and zeroes the pointer, capacity and count.
// FUNCTION: TITANIUM 0x0042D7E5
void BufferOwner_guess::Clear_guess() {
    if (elements_guess != 0) {
        elements_guess->DeleteVector_guess(3);
    }
    elements_guess = 0;
    capacity_guess = 0;
    count_guess = 0;
}

// Frees the record array (0x0042D7E5).
// FUNCTION: TITANIUM 0x0042D822
void BufferOwner_guess::ClearAlias_guess() {
    Clear_guess();
}

// Lookup result of 0x0042D3B0: the fields this function reads.
struct Record_022_guess {
    char pad_0_guess[0x1C];
    unsigned int field_1C_guess;
    char pad_20_guess[0x180 - 0x20];
    unsigned char field_180_guess;
    char pad_181_guess[0x1BC - 0x181];
    int field_1BC_guess;
    char pad_1C0_guess[0x1C8 - 0x1C0];
    int field_1C8_guess;
    char pad_1CC_guess[0x208 - 0x1CC];
    char* field_208_guess;
    // EXTERNAL: TITANIUM 0x0044E755 Record_022_guess::Compute_guess
    unsigned char Compute_guess(unsigned char value_guess);
};

// GetCharInfo2 result: the two fields read here.
struct CharInfo_022_guess {
    char pad_0_guess[0x119C];
    unsigned char classId_119c_guess;
    char pad_119D_guess[0x11A4 - 0x119D];
    int field_11A4_guess;
};

struct PcPrefix_022_guess {
    void* vftable_guess;
    int field_04_guess;
};

struct PcView_022_guess : PcPrefix_022_guess, virtual EQ_Character {
};
#define g_pcView_022_guess EQ_GLOBAL(PcView_022_guess*, 0x00905D00)

// Object at 0x00905D00 + 0xC280.
struct CharLookup_022_guess {
    // EXTERNAL: TITANIUM 0x0040EBC3 CharLookup_022_guess::SpellDuration_guess
    int SpellDuration_guess(Record_022_guess* record_guess, int value_guess, int flag_guess);
};

struct CharTable_022_guess {
    char pad_0_guess[0xC280];
    CharLookup_022_guess lookup_guess;
};
#define g_charTable_022_guess EQ_GLOBAL(CharTable_022_guess*, 0x00905D00)

// FUNCTION-local row buffer: BufferOwner plus the tail fields the fill reads.
struct Rows_022_guess : BufferOwner_guess {
    int target_guess;            // +0x10: key + 0x84
    int tag_guess;               // +0x14: -1
    unsigned char flag_a_guess;  // +0x18
    unsigned char flag_b_guess;  // +0x19
    Rows_022_guess() {
        elements_guess = 0;
        count_guess = 0;
        capacity_guess = 0;
        field_c_guess = 1;
        target_guess = 0;
        tag_guess = -1;
        flag_a_guess = 0;
        flag_b_guess = 1;
    }
    ~Rows_022_guess() {
        Clear_guess();
    }
};

// this+0x168
struct RowHost_022_guess {
    // EXTERNAL: TITANIUM 0x0059B800 RowHost_022_guess::Fill_guess
    void Fill_guess(Rows_022_guess* rows_guess);
};

struct TimerOwner_022_guess {
    char pad_0_guess[0x168];
    RowHost_022_guess* host_guess;
};

// CopyObject-shaped entry: int, CXStr, int.
struct Entry_022_guess {
    int field_0_guess;
    CXStr text_guess;
    int field_8_guess;
    Entry_022_guess() : text_guess() {
        field_8_guess = -1;
        field_0_guess = 0;
    }
};

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_022_guess
void __cdecl FormatCXStr_022_guess(CXStr* text_guess, const char* format_guess, ...);

// Adds the row for ability slot `key_guess`: name, level for the player's class (0x44E755 on charinfo
// +0x119C), +0x1BC and +0x1C8 (probably mana and endurance), target text, reuse left, recast time.
// FUNCTION: TITANIUM 0x0042D827
// @early-stop: budget, structural ndiff=19
void TimerText_guess::AddAbilityRow_guess(int key_guess) {
    TimerOwner_022_guess* owner_guess = (TimerOwner_022_guess*)this;
    if (owner_guess->host_guess != 0) {
        Record_022_guess* record_guess = (Record_022_guess*)GetCombatAbilitySpell_guess(key_guess);
        if (record_guess != 0) {
            Rows_022_guess rows_guess;
            Entry_022_guess a_guess;
            Entry_022_guess b_guess;
            Entry_022_guess c_guess;
            Entry_022_guess d_guess;
            Entry_022_guess e_guess;
            Entry_022_guess f_guess;
            Entry_022_guess g_guess;

            a_guess.text_guess = record_guess->field_208_guess;
            CharInfo_022_guess* info_guess = (CharInfo_022_guess*)g_pcView_022_guess->GetCharInfo2();
            FormatCXStr_022_guess(&b_guess.text_guess, "%d",
                                  record_guess->Compute_guess(info_guess->classId_119c_guess));
            FormatCXStr_022_guess(&c_guess.text_guess, "%d", record_guess->field_1BC_guess);
            FormatCXStr_022_guess(&d_guess.text_guess, "%d", record_guess->field_1C8_guess);

            if (record_guess->field_180_guess == 6) {
                // Target type 6 is self, 41 probably group (EQ spell target types).
                e_guess.text_guess = pStringTable->getString(0x1AA0, 0);
            } else if (record_guess->field_180_guess == ')') {
                e_guess.text_guess = pStringTable->getString(0x1AA1, 0);
            } else {
                e_guess.text_guess = pStringTable->getString(0x1AA2, 0);
            }

            info_guess = (CharInfo_022_guess*)g_pcView_022_guess->GetCharInfo2();
            int found_guess = g_charTable_022_guess->lookup_guess.SpellDuration_guess(
                record_guess, info_guess->field_11A4_guess, 0);
            {
                // Reuse left in 6 s ticks (0x40EBC3, probably a timer lookup); next, recast in ms.
                Str_guess tmp_guess = FormatDuration_guess(found_guess * 6);
                f_guess.text_guess = *(CXStr*)&tmp_guess;
            }
            {
                Str_guess tmp_guess = FormatDuration_guess(record_guess->field_1C_guess / 1000);
                g_guess.text_guess = *(CXStr*)&tmp_guess;
            }

            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&a_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&b_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&c_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&d_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&e_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&f_guess);
            rows_guess.SetElement_guess(rows_guess.count_guess, (CopyObject_guess*)&g_guess);

            // Row data = slot + 0x84, the combat-ability id base tu_146 uses too.
            rows_guess.target_guess = key_guess + 0x84;
            owner_guess->host_guess->Fill_guess(&rows_guess);
        }
    }
}

struct FeatureObject_guess {
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
};

struct FeatureHost_guess {
    char pad_0_guess[0x168];
    FeatureObject_guess* feature_guess;
    char pad_16c_guess[8];
    int field_174_guess;
    // EXTERNAL: TITANIUM 0x0042D827 FeatureHost_guess::AddAbilityRow_guess
    void AddAbilityRow_guess(int index_guess);
    void RefreshList_guess();
    void SetAndRun_guess(int value_guess);
};

// Refills the list from all 100 ability slots.
// FUNCTION: TITANIUM 0x0042DAF2
void FeatureHost_guess::RefreshList_guess() {
    if (feature_guess != 0) {
        feature_guess->Slot76_guess();
        for (int i = 0; i < 100; ++i) {
            AddAbilityRow_guess(i);
        }
        feature_guess->Slot78_guess();
    }
}

// Stores view `value_guess` (0 or 1, chosen on the +0x15C control) and refills.
// FUNCTION: TITANIUM 0x0042DB37
void FeatureHost_guess::SetAndRun_guess(int value_guess) {
    field_174_guess = value_guess;
    RefreshList_guess();
}

struct SkillList_guess : public FeatureObject_guess {
    char pad_4_guess[0x150];
    int field_154_guess;
    unsigned char field_158_guess;
    // EXTERNAL: TITANIUM 0x00597BE0 SkillList_guess::GetCurSel_guess
    int GetCurSel_guess();
    // EXTERNAL: TITANIUM 0x00597ED0 SkillList_guess::GetItemData_guess
    int GetItemData_guess(int row_guess);
    // EXTERNAL: TITANIUM 0x00597F10 SkillList_guess::GetItemText_guess
    Str_guess GetItemText_guess(int row_guess, int column_guess);
    // EXTERNAL: TITANIUM 0x00597F10 SkillList_guess::GetItemName_guess
    SkillWindowName_guess GetItemName_guess(int row_guess, int column_guess);
};

struct NotifyBase_guess {
    // EXTERNAL: TITANIUM 0x005A2230 NotifyBase_guess::WndNotification_guess
    int WndNotification_guess(void* sender_guess, int message_guess, void* data_guess);
};

struct SkillNotifyWnd_guess : public NotifyBase_guess {
    char pad_0_guess[0x15c];
    void* field_15c_guess;
    int field_160_guess;
    int field_164_guess;
    SkillList_guess* list_guess;
    int field_16c_guess;
    TargetOther_guess* button_guess;
    int field_174_guess;
    void ShowAbilityDescription_guess(int skill_guess);
    void CompareTimeCells_guess(int* data_guess);
    // EXTERNAL: TITANIUM 0x0055446C SkillNotifyWnd_guess::CompareNumericCells_guess
    void CompareNumericCells_guess(int* data_guess);
    int WndNotification_guess(void* sender_guess, int message_guess, void* data_guess);
};

// Time text source: GetText at 0x00572300 on the members at +4 and +0xC.
struct TimeText_022_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00572300 TimeText_022_guess::GetText_guess
    const char* GetText_guess();
};

struct TimePair_022_guess {
    int pad_0_guess;
    TimeText_022_guess first_guess;
    int pad_8_guess;
    TimeText_022_guess second_guess;
    int pad_10_guess;
    int result_guess;
};

#define g_timeFormat_022_guess EQ_ARRAY(char, 0x00641A18)
// EXTERNAL: TITANIUM 0x00610837 sscanf
extern "C" int __cdecl sscanf(const char* input, const char* format, ...);

// EXTERNAL: TITANIUM 0x00475855 FormatSpellDescription_guess
void __cdecl FormatSpellDescription_guess(char* output, int value);

struct ParseContext_022_guess {
    int value_guess;
    int mode_guess;
    int flags_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ParseContext_022_guess::Parse_guess
    void Parse_guess(const char* text);
};

struct CStmlWndView_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 CStmlWndView_guess::SetSTMLText
    void SetSTMLText(ParseContext_022_guess context_guess);
};

// Sort compare for the h:mm:ss columns (sort kinds 5 and 6): -1, 0 or 1.
// FUNCTION: TITANIUM 0x0042D4C7
// @early-stop: budget, diff ndiff=13
void SkillNotifyWnd_guess::CompareTimeCells_guess(int* data_guess) {
    const char* format_guess;
    TimePair_022_guess* object_guess = (TimePair_022_guess*)data_guess;
    if (object_guess != 0) {
        int minute1_guess;
        int second1_guess;
        int hour2_guess;
        int minute2_guess;
        int second2_guess;
        format_guess = g_timeFormat_022_guess;
        sscanf(object_guess->first_guess.GetText_guess(), format_guess,
            &data_guess, &minute1_guess, &second1_guess);
        sscanf(object_guess->second_guess.GetText_guess(), format_guess,
            &hour2_guess, &minute2_guess, &second2_guess);
        int first_guess = (((int)data_guess) * 60 + minute1_guess) * 60 + second1_guess;
        int second_guess = (hour2_guess * 60 + minute2_guess) * 60 + second2_guess;
        if (first_guess < second_guess) {
            object_guess->result_guess = -1;
        } else {
            object_guess->result_guess = first_guess > second_guess;
        }
    }
}

// Shows ability `skill_guess`'s description (0x475855 formats the spell text) in the STML box.
// FUNCTION: TITANIUM 0x0042D54F
// @early-stop: budget, structural ndiff=34
void SkillNotifyWnd_guess::ShowAbilityDescription_guess(int skill_guess) {
    if (field_16c_guess != 0) {
        char text_guess[512];
        int value_guess = GetCombatAbilitySpell_guess(skill_guess);
        FormatSpellDescription_guess(text_guess, value_guess);
        ParseContext_022_guess context_guess;
        context_guess.value_guess = value_guess;
        context_guess.mode_guess = 1;
        context_guess.flags_guess = 0;
        context_guess.Parse_guess(text_guess);
        ((CStmlWndView_guess*)field_16c_guess)->SetSTMLText(context_guess);
    }
}

// Make Hotkey picks up the selected ability; a row click shows its description and enables the button;
// a double-click (4) picks the row up; 0xF sorts by column (same column flips the order); 0x10 compares
// for the sort (kinds 1-3 by 0x55446C, 5-6 as times).
// FUNCTION: TITANIUM 0x0042DB49
int SkillNotifyWnd_guess::WndNotification_guess(void* sender_guess, int message_guess, void* data_guess) {
    if (sender_guess != 0) {
        if (message_guess == 1) {
            if (sender_guess == button_guess) {
                if (list_guess != 0) {
                    int row_guess = list_guess->GetCurSel_guess();
                    if (row_guess > -1) {
                        int value_guess = list_guess->GetItemData_guess(row_guess);
                        Str_guess text_guess = list_guess->GetItemText_guess(row_guess, 0);
                        ((TimerText_guess*)this)->MakeHotkey_guess(value_guess, text_guess);
                    }
                }
            } else if (sender_guess == list_guess) {
                ShowAbilityDescription_guess(list_guess->GetItemData_guess((int)data_guess) - 0x84);
                if (button_guess != 0) {
                    button_guess->enabled_005d_guess = 1;
                }
            } else if (sender_guess == field_15c_guess) {
                int id_guess = ((int*)data_guess)[2];
                if (id_guess == field_160_guess && field_174_guess != 0) {
                    ((FeatureHost_guess*)this)->SetAndRun_guess(0);
                } else if (id_guess == field_164_guess && field_174_guess != 1) {
                    ((FeatureHost_guess*)this)->SetAndRun_guess(1);
                }
            }
        } else if (message_guess == 4) {
            if (sender_guess == list_guess) {
                int value_guess = list_guess->GetItemData_guess((int)data_guess);
                SkillWindowName_guess text_guess = list_guess->GetItemName_guess((int)data_guess, 0);
                ((TimerText_guess*)this)->MakeHotkey_guess(value_guess, text_guess);
            }
        } else if (message_guess == 0xf) {
            if (sender_guess == list_guess) {
                int& column_guess = list_guess->field_154_guess;
                if (column_guess == (int)data_guess) {
                    list_guess->field_158_guess = !list_guess->field_158_guess;
                } else {
                    column_guess = (int)data_guess;
                    list_guess->field_158_guess = 1;
                }
                list_guess->Slot78_guess();
            }
        } else if (message_guess == 0x10) {
            if (sender_guess == list_guess) {
                int* values_guess = (int*)data_guess;
                int kind_guess = *values_guess;
                if (kind_guess == 1 || kind_guess == 2 || kind_guess == 3) {
                    CompareNumericCells_guess(values_guess);
                } else if (kind_guess == 5 || kind_guess == 6) {
                    CompareTimeCells_guess(values_guess);
                }
            }
        }
    }
    return NotifyBase_guess::WndNotification_guess(sender_guess, message_guess, data_guess);
}

