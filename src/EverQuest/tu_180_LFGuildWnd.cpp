// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 180: a hint from compare/tumap.py.
// CLFGuildWnd (screen "LFGuildWnd"), the guild finder: tabs for your own looking-for-guild entry (PLFG_*),
// your guild's looking-for-players entry (GLFP_*), guild search (PSFG_*) and player search (GSFP_*). Every
// request is OP_LFGuild 0x1858 with a type: 0 own entry, 1 guild entry, 3 player search, 4 guild search.
// Nearly every _guess class here is a view of this window.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"

// EXTERNAL: TITANIUM 0x00657680 ??_7Object_guess@@6B@
struct EmptyMember_guess {
    ~EmptyMember_guess() {}
};

struct Object_guess {
    EmptyMember_guess member_guess;
    virtual ~Object_guess();
    Object_guess* Delete_guess(unsigned char flags);
    // EXTERNAL: TITANIUM 0x005A3100 Object_guess::Initialize_guess
    void Initialize_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct EmptyTarget_guess {
    // EXTERNAL: TITANIUM 0x004482FB EmptyTarget_guess::Run_guess
    void Run_guess();
};

struct Adjusted_guess {
    void At40_guess();
    void At54_guess();
};

struct ResetFirst_guess {
    unsigned char field00_guess;
    char gap_0001_0040_guess[0x3f];
    unsigned char field40_guess;
    char gap_0041_0240_guess[0x1ff];
    unsigned int field240_guess;
    unsigned int field244_guess;
    unsigned int field248_guess;
    unsigned int field24c_guess;
    unsigned char field250_guess;
    unsigned int field254_guess;
    unsigned int field258_guess;
    ResetFirst_guess();
};

struct ResetSecond_guess {
    unsigned int field00_guess;
    unsigned char field04_guess;
    char gap_0005_0204_guess[0x1ff];
    unsigned int field204_guess;
    unsigned int field208_guess;
    unsigned int field20c_guess;
    unsigned int field210_guess;
    unsigned int field214_guess;
    unsigned char field218_guess;
    unsigned int field21c_guess;
    unsigned char field220_guess;
    char gap_0224_0260_guess[0x3c];
    ResetSecond_guess();
};

struct StringValue_guess {
    char* value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0StringValue_guess@@QAE@PBD@Z
    StringValue_guess(const char* value);
    // EXTERNAL: TITANIUM 0x00407D68 ??0StringValue_guess@@QAE@ABU0@@Z
    StringValue_guess(const StringValue_guess& value);
    // EXTERNAL: TITANIUM 0x00571D00 StringValue_guess::Release_guess
    void Release_guess(char* value);
    // EXTERNAL: TITANIUM 0x00572300 StringValue_guess::Get_guess
    const char* Get_guess();
    ~StringValue_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
        value_guess = 0;
    }
};

struct PcCharInfo_guess {
    char pad_0000_119c_guess[0x119c];
    unsigned char field_119c_guess;   // 0x119c
    char pad_119d_11a4_guess[0x11a4 - 0x119d];
    int field_11a4_guess;             // 0x11a4
};

struct PcPrefix_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    int field_004_guess;
    // EXTERNAL: TITANIUM 0x005ED790 PcPrefix_guess::GetValue_guess
    int GetValue_guess();
};

struct Character_guess : EQ_Character {
    PcCharInfo_guess* Profile_guess() { return reinterpret_cast<PcCharInfo_guess*>(GetCharInfo2()); }
};

struct PcProfile_guess : PcPrefix_guess, virtual Character_guess {
};

#define g_pc_guess EQ_GLOBAL(PcProfile_guess*, 0x00905D00)

struct StatusSource_guess {
    // EXTERNAL: TITANIUM 0x0059C3A0 StatusSource_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C360 StatusSource_guess::Set_guess
    void Set_guess(int value_guess);
};

struct StringProvider_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess();
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual StringValue_guess Get_guess();
};

struct RefreshTarget_guess {
    char gap_0000_01a0_guess[0x1a0];
    char text_01a0_guess[0x20c];
    int result_03ac_guess;
    char gap_03b0_0654_guess[0x2a4];
    StatusSource_guess* status_0654_guess;
    StringProvider_guess* provider_0658_guess;
    void Refresh_guess();
};

// EXTERNAL: TITANIUM 0x0060ACA0 FUN_0060aca0_guess
StringValue_guess __cdecl FUN_0060aca0_guess(const StringValue_guess& value);
// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// Constructor of the guild finder's player entry buffer (the type-0 record): empties the strings at +0
// and +0x40 and zeroes the fields +0x240..+0x258. The window constructor and PLFG On/Off/Update use it.
// FUNCTION: TITANIUM 0x00527B82
ResetFirst_guess::ResetFirst_guess() {
    field00_guess = 0;
    field40_guess = 0;
    field24c_guess = 0;
    field248_guess = 0;
    field244_guess = 0;
    field240_guess = 0;
    field250_guess = 0;
    field254_guess = 0;
    field258_guess = 0;
}

// Constructor of the guild finder's guild entry buffer (the type-1 record): zeroes the dword at +0, the
// string at +4 and the fields +0x204..+0x220. The window constructor and GLFP On/Off/Update use it.
// FUNCTION: TITANIUM 0x00527BB6
ResetSecond_guess::ResetSecond_guess() {
    field00_guess = 0;
    field220_guess = 0;
    field04_guess = 0;
    field214_guess = 0;
    field210_guess = 0;
    field20c_guess = 0;
    field208_guess = 0;
    field204_guess = 0;
    field218_guess = 0;
    field21c_guess = 0;
}

// Destructor of the guild finder window (vtable 0x657680): restores its vtable and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x00527BF0
Object_guess::~Object_guess() {
    Initialize_guess();
}

// Destructor of a 0x48-byte player result record: destroys its string at +0x40 (0x004482FB). Used by
// the record vector delete (0x005293E5) and the OP_LFGuild reply handler.
// FUNCTION: TITANIUM 0x00527C02
void Adjusted_guess::At40_guess() {
    reinterpret_cast<EmptyTarget_guess*>(reinterpret_cast<char*>(this) + 0x40)->Run_guess();
}

// Destructor of a 0x58-byte guild result record: destroys its string at +0x54 (0x004482FB). Used by the
// record vector delete (0x00529430) and the OP_LFGuild reply handler.
// FUNCTION: TITANIUM 0x00527C11
void Adjusted_guess::At54_guess() {
    reinterpret_cast<EmptyTarget_guess*>(reinterpret_cast<char*>(this) + 0x54)->Run_guess();
}

// Copies your entry from the page: time zone (combo index - 1, so -1 is none) and comment.
// FUNCTION: TITANIUM 0x00527F1E
void RefreshTarget_guess::Refresh_guess() {
    result_03ac_guess = -1;
    if (status_0654_guess != 0) {
        result_03ac_guess = status_0654_guess->GetCurChoice_guess() - 1;
    }
    text_01a0_guess[0] = 0;
    if (provider_0658_guess != 0) {
        StringValue_guess returned_guess = provider_0658_guess->Get_guess();
        StringValue_guess copied_guess = FUN_0060aca0_guess(returned_guess);
        FUN_0060e450_guess(text_01a0_guess, copied_guess.Get_guess());
    }
}

struct FlagElement_guess {
    char gap_0000_0128_guess[0x128];
    unsigned char field128_guess;
    // EXTERNAL: TITANIUM 0x005BB140 FlagElement_guess::SetCheck
    void SetCheck(bool value);
};

struct State_guess {
    virtual void RefreshCounts_guess();
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
    char gap_0004_0154_guess[0x150];
    int field154_guess;
    unsigned char field158_guess;
};

struct FlagHandler_guess {
    void Apply_guess(FlagElement_guess** elements, unsigned int mask);
    unsigned int BuildMask_guess(FlagElement_guess** elements);
    void Select_guess(State_guess* state, int value);
};

struct UpdateOwner_guess {
    char gap_0000_03c0_guess[0x3c0];
    char text_03c0_guess[0x200];
    int value_05c0_guess;
    int value_05c4_guess;
    unsigned int value_05c8_guess;
    int value_05cc_guess;
    int value_05d0_guess;
    char gap_05d4_0670_guess[0x9c];
    FlagElement_guess* elements_0670_guess[16];
    char gap_06b0_06b8_guess[8];
    StringProvider_guess* provider_06b8_guess;
    StringProvider_guess* provider_06bc_guess;
    StatusSource_guess* status_06c0_guess;
    StringProvider_guess* provider_06c4_guess;
    StringProvider_guess* provider_06c8_guess;
    void Update_guess();
};

struct TimedFlag_guess {
    char gap_0000_005d_guess[0x5d];
    unsigned char enabled_005d_guess;
};

struct TimedOwner_guess {
    char gap_0000_061c_guess[0x61c];
    int timestamp_guess;
    char gap_0620_06f0_guess[0xd0];
    TimedFlag_guess* first_guess;
    char gap_06f4_0758_guess[0x64];
    TimedFlag_guess* second_guess;
    void UpdateFirst_guess();
    void UpdateSecond_guess();
};

struct TimerTarget_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
    virtual void Slot48_guess(unsigned char first_guess, int second_guess);
    virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess(); virtual void Slot52_guess();
    virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess(); virtual void Slot60_guess();
    virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void SetText_guess(StringValue_guess& enabled_005d_guess);

    char gap_0004_005d_guess[0x59];
    unsigned char enabled_005d_guess;  // 0x5d
};

struct TimerConfig_guess {
    char gap_0000_0e0c_guess[0xe0c];
    int field_0e0c_guess;          // 0xe0c
    unsigned char field_0e10_guess;  // 0xe10
};

struct TimerSource_guess {
    // EXTERNAL: TITANIUM 0x005BC390 TimerSource_guess::Get_guess
    int Get_guess();
};

struct Slot63Target_guess;

struct TimerState_guess {
    char gap_0000_0160_guess[0x160];
    union {
        struct {
            char source_0160_guess[0x25c];
            char source_03bc_guess[0x260];
            char gap_061c_0630_guess[0x14];
            int time_0630_guess;
            int field_0634_guess;
            TimerSource_guess* source_0638_guess;
            int field_063c_guess;
            int field_0640_guess;
            int field_0644_guess;
            int field_0648_guess;
            char gap_064c_065c_guess[0x10];
            TimerTarget_guess* target_065c_guess;
            TimerTarget_guess* target_0660_guess;
            TimerTarget_guess* target_0664_guess;
            char gap_0668_0670_guess[8];
            FlagElement_guess* elements_0670_guess[16];
            int value_06b0_guess;
            int value_06b4_guess;
            char gap_06b8_06cc_guess[0x14];
            TimerTarget_guess* target_06cc_guess;
            TimerTarget_guess* target_06d0_guess;
            TimerTarget_guess* target_06d4_guess;
        };
        struct {
            char gap_0160_03b0_guess[0x250];
            unsigned char value_03b0_guess;
            char gap_03b1_05d4_guess[0x5d4 - 0x3b1];
            unsigned char value_05d4_guess;
        };
        struct {
            char gap_0160_01a0_guess[0x40];
            char text_01a0_guess[0x20c];
            int result_03ac_guess;
            unsigned char refresh_value_03b0_guess;
            char gap_03b1_03b8_guess[7];
            int time_03b8_guess;
            char gap_03bc_0630_guess[0x0630 - 0x03bc];
            int refresh_time_0630_guess;
            char gap_0634_0650_guess[0x1c];
            Slot63Target_guess* target_0650_guess;
            StatusSource_guess* status_0654_guess;
            Slot63Target_guess* target_0658_guess;
            char gap_065c_0668_guess[0xc];
            Slot63Target_guess* target_0668_guess;
        };
        struct {
            char gap_0160_03c0_update_guess[0x260];
            char text_03c0_update_guess[0x200];
            int field_05c0_update_guess;
            int field_05c4_update_guess;
            unsigned int field_05c8_update_guess;
            int field_05cc_update_guess;
            int field_05d0_update_guess;
            unsigned char value_05d4_update_guess;
            char gap_05d5_05d8_update_guess[3];
            int field_05d8_update_guess;
            char gap_05dc_0630_update_guess[0x54];
            int time_0630_update_guess;
            char gap_0634_0670_update_guess[0x3c];
            FlagElement_guess* elements_0670_update_guess[16];
            char gap_06b0_06b8_update_guess[8];
            TimerTarget_guess* target_06b8_update_guess;
            TimerTarget_guess* target_06bc_update_guess;
            StatusSource_guess* status_06c0_update_guess;
            TimerTarget_guess* target_06c4_update_guess;
            TimerTarget_guess* target_06c8_update_guess;
            char gap_06cc_06d8_update_guess[0xc];
            TimerTarget_guess* target_06d8_update_guess;
        };
    };

    void Refresh_guess();
    void Update_0052805e_guess();
    void Update_005280e0_guess();
    void Step2_guess();
    void Reset_00529b96_guess();
    void Dispatch_guess();
    void Reset_guess();
    int HandleFirst_guess(TimerTarget_guess* target_guess, int action_guess, int unused_guess);
    int HandleSecond_guess(TimerTarget_guess* target_guess, int action_guess, int unused_guess);
};

#define g_timerConfig_guess EQ_GLOBAL(TimerConfig_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* destination_guess, int string_id_guess, ...);

#define g_messageConnection_guess EQ_GLOBAL(int, 0x00905CA0)

// EXTERNAL: TITANIUM 0x0060ECBC Time_guess
int __cdecl Time_guess(int* value);

// Sets the 16 class check boxes from a mask. Bit i + 1 is check box i of the alphabetical list in
// Initialize_guess (BRD, BST, BER ... WIZ), not class id i + 1.
// FUNCTION: TITANIUM 0x00527FCC
void FlagHandler_guess::Apply_guess(FlagElement_guess** elements, unsigned int mask) {
    int i = 0;
    do {
        if (elements[i] != 0) {
            elements[i]->SetCheck((mask & (1 << (i + 1))) != 0);
        }
        ++i;
    } while (i < 16);
}

// The class mask of the checked boxes (bit layout as in Apply_guess).
// FUNCTION: TITANIUM 0x00527FFB
unsigned int FlagHandler_guess::BuildMask_guess(FlagElement_guess** elements) {
    unsigned int result = 0;
    int i = 0;
    do {
        FlagElement_guess* element = elements[i];
        if (element != 0 && element->field128_guess != 0) {
            result |= 1 << (i + 1);
        }
        ++i;
    } while (i < 16);
    return result;
}

// Column header click: sort by that column; the same column again flips the direction.
// FUNCTION: TITANIUM 0x00528028
void FlagHandler_guess::Select_guess(State_guess* state, int value) {
    if (state->field154_guess == value) {
        state->field158_guess = !state->field158_guess;
    } else {
        state->field154_guess = value;
        state->field158_guess = 1;
    }
    state->Slot78_guess();
}

// Your entry's buttons: On while unlisted, Off and Update while listed.
// FUNCTION: TITANIUM 0x0052805E
void TimerState_guess::Update_0052805e_guess() {
    unsigned char value_guess = value_03b0_guess;
    bool disabled_guess = value_guess != 1;
    if (target_065c_guess != 0) {
        target_065c_guess->Slot48_guess(disabled_guess, 1);
    }
    if (target_0660_guess != 0) {
        target_0660_guess->enabled_005d_guess = value_guess;
    }
    if (target_0664_guess != 0) {
        target_0664_guess->Slot48_guess(!disabled_guess, 1);
        // Update waits 2.5 s after the last send.
        target_0664_guess->enabled_005d_guess = FUN_0046d655_guess() > time_0630_guess + 2500;
    }
}

// The guild entry's buttons, as for your own entry, but only for a member of a guild whose rank is above 0
// (pCharData +0xE0C and +0xE10, probably guild id and rank; likely officers only).
// FUNCTION: TITANIUM 0x005280E0
void TimerState_guess::Update_005280e0_guess() {
    bool enabled_guess = g_timerConfig_guess->field_0e0c_guess != -1 && g_timerConfig_guess->field_0e10_guess > 0;
    unsigned char value_guess = value_05d4_guess;
    bool disabled_guess = value_guess != 1;
    bool both_guess = value_guess != 0 && enabled_guess;
    if (target_06cc_guess != 0) {
        target_06cc_guess->Slot48_guess(disabled_guess, 1);
        target_06cc_guess->enabled_005d_guess = enabled_guess;
    }
    if (target_06d0_guess != 0) {
        target_06d0_guess->enabled_005d_guess = both_guess;
    }
    if (target_06d4_guess != 0) {
        target_06d4_guess->Slot48_guess(!disabled_guess, 1);
        target_06d4_guess->enabled_005d_guess = FUN_0046d655_guess() > time_0630_guess + 2500 && enabled_guess;
    }
}

// PSFG_SearchButton is enabled 10 seconds after the last guild search.
// FUNCTION: TITANIUM 0x005281A4
void TimedOwner_guess::UpdateFirst_guess() {
    unsigned char enabled = 0;
    if (Time_guess(0) > timestamp_guess + 10) {
        ++enabled;
    }
    TimedFlag_guess* target = first_guess;
    if (target != 0) {
        target->enabled_005d_guess = enabled;
    }
}

// GSFP_SearchButton is enabled 10 seconds after the last player search.
// FUNCTION: TITANIUM 0x005281D1
void TimedOwner_guess::UpdateSecond_guess() {
    unsigned char enabled = 0;
    if (Time_guess(0) > timestamp_guess + 10) {
        ++enabled;
    }
    TimedFlag_guess* target = second_guess;
    if (target != 0) {
        target->enabled_005d_guess = enabled;
    }
}

struct Record_guess {
    char text_guess[0x40];
    int output_guess;
    unsigned int key_guess;
};

struct RecordValues_guess {
    // EXTERNAL: TITANIUM 0x0059B9D0 RecordValues_guess::AddString
    int AddString(StringValue_guess* value, int index, const char* text, int flags);
    // EXTERNAL: TITANIUM 0x0059B360 RecordValues_guess::SetItemText
    void SetItemText(int value, int index, void* destination);
};

struct RecordOwner_guess {
    char gap_0000_0628_guess[0x628];
    Record_guess* records_guess;
    int count_guess;
    char gap_0630_06f4_guess[0xc4];
    RecordValues_guess* values_guess;
    void Populate_guess();
};

struct ResourceObject_guess {
    // EXTERNAL: TITANIUM 0x0059C8D0 ResourceObject_guess::Apply_guess
    void Apply_guess(StringValue_guess* value);
    // EXTERNAL: TITANIUM 0x0059C360 ResourceObject_guess::Finish_guess
    void Finish_guess(int flags);
};

struct ResourceBatch_guess {
    void Load_guess(ResourceObject_guess* object);
};

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

struct RecordEntry58_guess {
    char text_guess[0x40];        // 0x00
    int level_0040_guess;           // 0x40
    char text44_guess[8];         // 0x44
    int number4c_guess;           // 0x4c
    unsigned int key_guess;       // 0x50
    int output_guess;             // 0x54
};

struct RecordTable_guess {
    char gap_0000_0620_guess[0x620];
    RecordEntry58_guess* entries_guess;   // 0x620
    int count_guess;                      // 0x624
    char gap_0628_075c_guess[0x134];
    RecordValues_guess* values_guess;     // 0x75c
    void Populate_guess();
};

// Fills GSFP_SearchResultList: name, level, class, AA count, time zone and comment.
// FUNCTION: TITANIUM 0x00527C19
void RecordTable_guess::Populate_guess() {
    if (values_guess != 0) {
        int i = 0;
        if (count_guess > 0) {
            do {
                int value;
                {
                    StringValue_guess text(entries_guess[i].text_guess);
                    value = values_guess->AddString(&text, -1, entries_guess[i].text_guess, 0);
                }
                {
                    StringValue_guess text(__itoa(entries_guess[i].level_0040_guess, EQ_ARRAY(char, 0x0099DB00), 10));
                    values_guess->SetItemText(value, 1, &text);
                }
                {
                    StringValue_guess text(entries_guess[i].text44_guess);
                    values_guess->SetItemText(value, 2, &text);
                }
                {
                    StringValue_guess text(__itoa(entries_guess[i].number4c_guess, EQ_ARRAY(char, 0x0099DB00), 10));
                    values_guess->SetItemText(value, 3, &text);
                }
                {
                    StringValue_guess text(pStringTable->getString(
                        EQ_ARRAY(unsigned int, 0x00792F34)[entries_guess[i].key_guess], 0));
                    values_guess->SetItemText(value, 4, &text);
                }
                values_guess->SetItemText(value, 5, &entries_guess[i].output_guess);
                ++i;
            } while (i < count_guess);
        }
    }
}

// Fills PSFG_SearchResultList: guild name, time zone and comment.
// FUNCTION: TITANIUM 0x00527E0F
void RecordOwner_guess::Populate_guess() {
    if (values_guess != 0) {
        int i = 0;
        if (count_guess > 0) {
            do {
                int value;
                {
                    StringValue_guess text(records_guess[i].text_guess);
                    value = values_guess->AddString(&text, -1, records_guess[i].text_guess, 0);
                }
                {
                    StringValue_guess text(pStringTable->getString(
                        EQ_ARRAY(unsigned int, 0x00792F34)[records_guess[i].key_guess], 0));
                    values_guess->SetItemText(value, 1, &text);
                }
                values_guess->SetItemText(value, 2, &records_guess[i].output_guess);
                ++i;
            } while (i < count_guess);
        }
    }
}

// Fills a time-zone combo with the 25 names at 0x792F30-0x792F90; their index - 1 is the zone, -1 none.
// FUNCTION: TITANIUM 0x005281FE
void ResourceBatch_guess::Load_guess(ResourceObject_guess* object) {
    const unsigned int* entry = EQ_ARRAY(unsigned int, 0x00792F30);
    do {
        {
            StringValue_guess value(pStringTable->getString(*entry, 0));
            object->Apply_guess(&value);
        }
        ++entry;
    } while ((int)entry <= (int)EQ_ARRAY(unsigned int, 0x00792F90));
    object->Finish_guess(0);
}

struct ChildControl_guess : ResourceObject_guess {
    char gap_0000_0066_guess[0x66];
    unsigned char flags_0066_guess;
    char gap_0067_0154_guess[0xed];
    unsigned int field_0154_guess;
    char gap_0158_015c_guess[4];
    unsigned char field_015c_guess;
    char gap_015d_016c_guess[0xf];
    unsigned int field_016c_guess;
    char gap_0170_0230_guess[0xc0];
    int field_0230_guess;
    // EXTERNAL: TITANIUM 0x004D7EBC ChildControl_guess::SetMaxChars_guess
    void SetMaxChars_guess(int mode);
    // EXTERNAL: TITANIUM 0x00597C60 ChildControl_guess::SetColors
    void SetColors(int column, unsigned int first, unsigned int second);
    // EXTERNAL: TITANIUM 0x005982E0 ChildControl_guess::SetColumnJustification
    void SetColumnJustification(int column, int value);
    // EXTERNAL: TITANIUM 0x0059C3E0 ChildControl_guess::Reset_guess
    void Reset_guess();
};

struct LfguildPage_guess : ResourceBatch_guess {
    char gap_0000_0638_guess[0x638];
    ChildControl_guess* tabWindow_0638_guess;
    ChildControl_guess* playerGuildPage_063c_guess;
    ChildControl_guess* guildPlayerPage_0640_guess;
    ChildControl_guess* searchGuildPage_0644_guess;
    ChildControl_guess* searchPlayerPage_0648_guess;
    ChildControl_guess* playerGuildPage_064c_guess;
    ChildControl_guess* playerGuildLevel_0650_guess;
    ChildControl_guess* playerGuildTimeZone_0654_guess;
    ChildControl_guess* playerGuildComment_0658_guess;
    ChildControl_guess* playerGuildOn_065c_guess;
    ChildControl_guess* playerGuildOff_0660_guess;
    ChildControl_guess* playerGuildUpdate_0664_guess;
    ChildControl_guess* playerGuildExpire_0668_guess;
    ChildControl_guess* guildPlayerPage_066c_guess;
    ChildControl_guess* guildRoles_0670_guess[16];
    ChildControl_guess* guildSelectAll_06b0_guess;
    ChildControl_guess* guildDeselectAll_06b4_guess;
    ChildControl_guess* guildLevelMin_06b8_guess;
    ChildControl_guess* guildLevelMax_06bc_guess;
    ChildControl_guess* guildTimeZone_06c0_guess;
    ChildControl_guess* guildAACount_06c4_guess;
    ChildControl_guess* guildComment_06c8_guess;
    ChildControl_guess* guildOn_06cc_guess;
    ChildControl_guess* guildOff_06d0_guess;
    ChildControl_guess* guildUpdate_06d4_guess;
    ChildControl_guess* guildExpire_06d8_guess;
    ChildControl_guess* searchGuildPage_06dc_guess;
    ChildControl_guess* searchGuildLevel_06e0_guess;
    ChildControl_guess* searchGuildClass_06e4_guess;
    ChildControl_guess* searchGuildTimeZone_06e8_guess;
    ChildControl_guess* searchGuildAACount_06ec_guess;
    ChildControl_guess* searchGuildButton_06f0_guess;
    ChildControl_guess* searchGuildResults_06f4_guess;
    ChildControl_guess* searchGuildComment_06f8_guess;
    ChildControl_guess* searchPlayerPage_06fc_guess;
    ChildControl_guess* searchPlayerRoles_0700_guess[16];
    ChildControl_guess* searchPlayerSelectAll_0740_guess;
    ChildControl_guess* searchPlayerDeselectAll_0744_guess;
    ChildControl_guess* searchPlayerLevelMin_0748_guess;
    ChildControl_guess* searchPlayerLevelMax_074c_guess;
    ChildControl_guess* searchPlayerTimeZone_0750_guess;
    ChildControl_guess* searchPlayerAACount_0754_guess;
    ChildControl_guess* searchPlayerButton_0758_guess;
    ChildControl_guess* searchPlayerResults_075c_guess;
    ChildControl_guess* searchPlayerComment_0760_guess;
    // EXTERNAL: TITANIUM 0x005A1E10 LfguildPage_guess::GetChildItem
    ChildControl_guess* GetChildItem(StringValue_guess* name);
    void Initialize_guess();
};

// Looks up the controls of the four guild finder pages (PLFG_, GLFP_, PSFG_ and GSFP_ prefixes) and sets
// them up: time-zone combos filled (0x005281FE), the class combo from the class-name table, length limits
// on the edit boxes, and colours and columns for both search result lists.
// FUNCTION: TITANIUM 0x00528273
// @early-stop: budget, structural ndiff=93
void LfguildPage_guess::Initialize_guess() {
    memset(&playerGuildPage_064c_guess, 0, 0x20);
    memset(&guildPlayerPage_066c_guess, 0, 0x70);
    memset(&searchGuildPage_06dc_guess, 0, 0x20);
    memset(&searchPlayerPage_06fc_guess, 0, 0x68);
    char nameBuffer[256];
    {
        StringValue_guess name("LFGUILD_TabWindow");
        tabWindow_0638_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("LFGUILD_PlayerLFGuildPage");
        playerGuildPage_064c_guess = GetChildItem(&name);
        playerGuildPage_063c_guess = playerGuildPage_064c_guess;
    }
    {
        StringValue_guess name("PLFG_LevelClassLabel");
        playerGuildLevel_0650_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_TimeZoneCombo");
        playerGuildTimeZone_0654_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_CommentsEdit");
        playerGuildComment_0658_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_OnButton");
        playerGuildOn_065c_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_OffButton");
        playerGuildOff_0660_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_UpdateButton");
        playerGuildUpdate_0664_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PLFG_ExpireLabel");
        playerGuildExpire_0668_guess = GetChildItem(&name);
    }
    if (playerGuildTimeZone_0654_guess != 0) {
        Load_guess(playerGuildTimeZone_0654_guess);
    }
    if (playerGuildComment_0658_guess != 0) {
        // SetEditMode_guess is 0x004D7EBC, the maximum text length: 256 for comments, 2 for levels, 4 for
        // AA counts.
        playerGuildComment_0658_guess->SetMaxChars_guess(0x100);
    }
    const char* roleNames[16] = {
        EQ_ARRAY(char, 0x00657A70), EQ_ARRAY(char, 0x00657A6C),
        EQ_ARRAY(char, 0x00648AFC), EQ_ARRAY(char, 0x00657A68),
        EQ_ARRAY(char, 0x00648B68), EQ_ARRAY(char, 0x00657A64),
        EQ_ARRAY(char, 0x00657A60), EQ_ARRAY(char, 0x00657A5C),
        EQ_ARRAY(char, 0x00657A58), EQ_ARRAY(char, 0x00657A54),
        EQ_ARRAY(char, 0x00657A50), EQ_ARRAY(char, 0x00657A4C),
        EQ_ARRAY(char, 0x00648760), EQ_ARRAY(char, 0x00648CD0),
        EQ_ARRAY(char, 0x00657A48), EQ_ARRAY(char, 0x00657A44)
    };
    {
        StringValue_guess name("LFGUILD_GuildLFPlayerPage");
        guildPlayerPage_066c_guess = GetChildItem(&name);
        guildPlayerPage_0640_guess = guildPlayerPage_066c_guess;
    }
    int index = 0;
    ChildControl_guess** role = guildRoles_0670_guess;
    do {
        // One check box per class, in the alphabetical order of the abbreviations above.
        sprintf(nameBuffer, "GLFP_%sCheckbox", roleNames[index]);
        {
            StringValue_guess name(nameBuffer);
            *role = GetChildItem(&name);
        }
        ++index;
        ++role;
    } while (index < 16);
    {
        StringValue_guess name("GLFP_SelectAllRolesButton");
        guildSelectAll_06b0_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_DeselectAllRolesButton");
        guildDeselectAll_06b4_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_LevelRangeMinEditbox");
        guildLevelMin_06b8_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_LevelRangeMaxEditbox");
        guildLevelMax_06bc_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_MinAACountEdit");
        guildAACount_06c4_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_TimeZoneCombo");
        guildTimeZone_06c0_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_CommentsEdit");
        guildComment_06c8_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_OnButton");
        guildOn_06cc_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_OffButton");
        guildOff_06d0_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_UpdateButton");
        guildUpdate_06d4_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GLFP_ExpireLabel");
        guildExpire_06d8_guess = GetChildItem(&name);
    }
    if (guildTimeZone_06c0_guess != 0) {
        Load_guess(guildTimeZone_06c0_guess);
    }
    if (guildComment_06c8_guess != 0) {
        guildComment_06c8_guess->SetMaxChars_guess(0x100);
    }
    if (guildLevelMin_06b8_guess != 0) {
        guildLevelMin_06b8_guess->SetMaxChars_guess(2);
        guildLevelMin_06b8_guess->field_0230_guess = 3;
    }
    if (guildLevelMax_06bc_guess != 0) {
        guildLevelMax_06bc_guess->SetMaxChars_guess(2);
        guildLevelMax_06bc_guess->field_0230_guess = 3;
    }
    if (guildAACount_06c4_guess != 0) {
        guildAACount_06c4_guess->SetMaxChars_guess(4);
        guildAACount_06c4_guess->field_0230_guess = 3;
    }
    {
        StringValue_guess name("LFGUILD_SearchGuildsPage");
        searchGuildPage_06dc_guess = GetChildItem(&name);
        searchGuildPage_0644_guess = searchGuildPage_06dc_guess;
    }
    {
        StringValue_guess name("PSFG_LevelEdit");
        searchGuildLevel_06e0_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_ClassCombo");
        searchGuildClass_06e4_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_AACountEdit");
        searchGuildAACount_06ec_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_TimeZoneCombo");
        searchGuildTimeZone_06e8_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_SearchButton");
        searchGuildButton_06f0_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_SearchResultList");
        searchGuildResults_06f4_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("PSFG_Comment");
        searchGuildComment_06f8_guess = GetChildItem(&name);
    }
    if (searchGuildClass_06e4_guess != 0) {
        searchGuildClass_06e4_guess->Reset_guess();
        // The class names in class-id order (1-16), so combo index = class - 1.
        unsigned int* stringId = EQ_ARRAY(unsigned int, 0x00792EF0);
        do {
            StringValue_guess value(pStringTable->getString(*stringId, 0));
            searchGuildClass_06e4_guess->Apply_guess(&value);
            ++stringId;
        } while ((int)stringId < (int)EQ_ARRAY(unsigned int, 0x00792F30));
        searchGuildClass_06e4_guess->Finish_guess(1);
    }
    if (searchGuildTimeZone_06e8_guess != 0) {
        Load_guess(searchGuildTimeZone_06e8_guess);
    }
    if (searchGuildAACount_06ec_guess != 0) {
        searchGuildAACount_06ec_guess->SetMaxChars_guess(4);
        searchGuildAACount_06ec_guess->field_0230_guess = 3;
    }
    if (searchGuildLevel_06e0_guess != 0) {
        searchGuildLevel_06e0_guess->SetMaxChars_guess(2);
        searchGuildLevel_06e0_guess->field_0230_guess = 3;
    }
    if (searchGuildResults_06f4_guess != 0) {
        searchGuildResults_06f4_guess->SetColors(-1, 0xffffff00, 0xff808080);
        searchGuildResults_06f4_guess->field_016c_guess = 0xff8aa3ff;
        searchGuildResults_06f4_guess->field_015c_guess = 1;
        searchGuildResults_06f4_guess->flags_0066_guess |= 4;
        searchGuildResults_06f4_guess->field_0154_guess = 0;
        searchGuildResults_06f4_guess->SetColumnJustification(0, 0);
        searchGuildResults_06f4_guess->SetColumnJustification(1, 0);
        searchGuildResults_06f4_guess->SetColumnJustification(2, 0);
    }
    {
        StringValue_guess name("LFGUILD_SearchPlayersPage");
        searchPlayerPage_06fc_guess = GetChildItem(&name);
        searchPlayerPage_0648_guess = searchPlayerPage_06fc_guess;
    }
    index = 0;
    role = searchPlayerRoles_0700_guess;
    do {
        sprintf(nameBuffer, "GSFP_%sCheckbox", roleNames[index]);
        {
            StringValue_guess name(nameBuffer);
            *role = GetChildItem(&name);
        }
        ++index;
        ++role;
    } while (index < 16);
    {
        StringValue_guess name("GSFP_SelectAllRolesButton");
        searchPlayerSelectAll_0740_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_DeselectAllRolesButton");
        searchPlayerDeselectAll_0744_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_LevelRangeMinEditbox");
        searchPlayerLevelMin_0748_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_LevelRangeMaxEditbox");
        searchPlayerLevelMax_074c_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_MinAACountEdit");
        searchPlayerAACount_0754_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_TimeZoneCombo");
        searchPlayerTimeZone_0750_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_SearchButton");
        searchPlayerButton_0758_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_SearchResultList");
        searchPlayerResults_075c_guess = GetChildItem(&name);
    }
    {
        StringValue_guess name("GSFP_Comment");
        searchPlayerComment_0760_guess = GetChildItem(&name);
    }
    if (searchPlayerTimeZone_0750_guess != 0) {
        Load_guess(searchPlayerTimeZone_0750_guess);
    }
    if (searchPlayerLevelMin_0748_guess != 0) {
        searchPlayerLevelMin_0748_guess->SetMaxChars_guess(2);
        searchPlayerLevelMin_0748_guess->field_0230_guess = 3;
    }
    if (searchPlayerLevelMax_074c_guess != 0) {
        searchPlayerLevelMax_074c_guess->SetMaxChars_guess(2);
        searchPlayerLevelMax_074c_guess->field_0230_guess = 3;
    }
    if (searchPlayerAACount_0754_guess != 0) {
        searchPlayerAACount_0754_guess->SetMaxChars_guess(4);
        searchPlayerAACount_0754_guess->field_0230_guess = 3;
    }
    if (searchPlayerResults_075c_guess != 0) {
        searchPlayerResults_075c_guess->SetColors(-1, 0xffffff00, 0xff808080);
        searchPlayerResults_075c_guess->field_016c_guess = 0xff8aa3ff;
        searchPlayerResults_075c_guess->field_015c_guess = 1;
        searchPlayerResults_075c_guess->flags_0066_guess |= 4;
        searchPlayerResults_075c_guess->field_0154_guess = 0;
        searchPlayerResults_075c_guess->SetColumnJustification(0, 0);
        searchPlayerResults_075c_guess->SetColumnJustification(1, 1);
        searchPlayerResults_075c_guess->SetColumnJustification(2, 1);
        searchPlayerResults_075c_guess->SetColumnJustification(3, 1);
        searchPlayerResults_075c_guess->SetColumnJustification(4, 0);
        searchPlayerResults_075c_guess->SetColumnJustification(5, 0);
    }
}

// Local polymorphic copy of the CSidlScreenWnd base (ctor 0x005A3850), 0x15C bytes with the two fields.
struct SidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0SidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    SidlBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlBase_guess@@UAE@XZ
    virtual ~SidlBase_guess();
    char pad_0004[0x60];
    union {
        unsigned int style_0064;      // CXWnd WindowStyle
        struct {
            char pad_0064[2];
            unsigned char flags_0066;
        };
    };
    char pad_0068[0x124 - 0x68];
    void* piece_0124;                 // CSidlScreenWnd SidlPiece
    char pad_0128[0x158 - 0x128];
    int field_0158;
};

struct SidlPiece_guess {
    char pad_0000[0x60];
    unsigned int field_0060;
};

// EXTERNAL: TITANIUM 0x00657680 ??_7LFGuildWnd_guess@@6B@
struct LFGuildWnd_guess : SidlBase_guess {
    int field_015c;
    ResetFirst_guess first_0160;      // 0x160..0x3bb
    ResetSecond_guess second_03bc;    // 0x3bc..0x61b
    int field_061c[6];
    int field_0634;
    char pad_0638[0x14];
    char buf_064c[0x20];
    char buf_066c[0x70];
    char buf_06dc[0x20];
    char buf_06fc[0x68];

    LFGuildWnd_guess(CXWnd* parent);
};

// Guild finder window constructor: clears the control pointers and page buffers, builds the children from
// the screen definition and looks them up (0x00528273).
// FUNCTION: TITANIUM 0x0052929B
// @early-stop: budget, structural ndiff=7
LFGuildWnd_guess::LFGuildWnd_guess(CXWnd* parent)
    : SidlBase_guess(parent, "LFGuildWnd", -1, 1, 0) {
    field_0634 = 0;
    field_015c = 0;
    first_0160.field40_guess = 0;
    second_03bc.field04_guess = 0;
    field_061c[0] = 0;
    field_061c[1] = 0;
    field_061c[2] = 0;
    field_061c[3] = 0;
    field_061c[4] = 0;
    field_061c[5] = 0;
    memset(buf_064c, 0, 0x20);
    memset(buf_066c, 0, 0x70);
    memset(buf_06dc, 0, 0x20);
    memset(buf_06fc, 0, 0x68);
    flags_0066 |= 1;
    field_0158 = 0x3d;
    if (piece_0124 != 0) {
        style_0064 = ((SidlPiece_guess*)piece_0124)->field_0060 | style_0064 | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        reinterpret_cast<LfguildPage_guess*>(this)->Initialize_guess();
    }
}

// Copies the guild entry from the page: time zone, comment, level range (default 0-70), AA minimum and the
// class mask.
// FUNCTION: TITANIUM 0x005299E8
void UpdateOwner_guess::Update_guess() {
    value_05d0_guess = -1;
    if (status_06c0_guess != 0) {
        value_05d0_guess = status_06c0_guess->GetCurChoice_guess() - 1;
    }
    text_03c0_guess[0] = 0;
    if (provider_06c8_guess != 0) {
        StringValue_guess returned_guess = provider_06c8_guess->Get_guess();
        StringValue_guess copied_guess = FUN_0060aca0_guess(returned_guess);
        FUN_0060e450_guess(text_03c0_guess, copied_guess.Get_guess());
    }
    value_05c0_guess = 0;
    if (provider_06b8_guess != 0) {
        int parsed_guess = atoi(provider_06b8_guess->Get_guess().Get_guess());
        value_05c0_guess = parsed_guess;
    }
    value_05c4_guess = 0x46;
    if (provider_06bc_guess != 0) {
        int parsed_guess = atoi(provider_06bc_guess->Get_guess().Get_guess());
        value_05c4_guess = parsed_guess;
    }
    value_05cc_guess = 0;
    if (provider_06c4_guess != 0) {
        int parsed_guess = atoi(provider_06c4_guess->Get_guess().Get_guess());
        value_05cc_guess = parsed_guess;
    }
    value_05c8_guess = reinterpret_cast<FlagHandler_guess*>(this)->BuildMask_guess(elements_0670_guess);
}

// Scalar deleting destructor of the guild finder window (vtable 0x657680 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x005293C9
Object_guess* Object_guess::Delete_guess(unsigned char flags) {
    this->Object_guess::~Object_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x0060D6E5 eh_vector_destructor_iterator_guess
void __stdcall eh_vector_destructor_iterator_guess(
    void* elements, unsigned int size, int count,
    void (Adjusted_guess::*destructor)());

struct Vector48_guess {
    void* Delete_guess(unsigned char flags);
};

struct Vector58_guess {
    void* Delete_guess(unsigned char flags);
};

// Compiler vector deleting destructor for 0x48-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x005293E5
void* Vector48_guess::Delete_guess(unsigned char flags) {
    if (flags & 2) {
        unsigned int* prefix = reinterpret_cast<unsigned int*>(this) - 1;
        eh_vector_destructor_iterator_guess(this, 0x48, *prefix, &Adjusted_guess::At40_guess);
        if (flags & 1) {
            ::operator delete[](prefix);
        }
        return prefix;
    }
    void (Adjusted_guess::*at40_guess)() = &Adjusted_guess::At40_guess;
    (reinterpret_cast<Adjusted_guess*>(this)->*at40_guess)();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Compiler vector deleting destructor for 0x58-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x00529430
void* Vector58_guess::Delete_guess(unsigned char flags) {
    if (flags & 2) {
        unsigned int* prefix = reinterpret_cast<unsigned int*>(this) - 1;
        eh_vector_destructor_iterator_guess(this, 0x58, *prefix, &Adjusted_guess::At54_guess);
        if (flags & 1) {
            ::operator delete[](prefix);
        }
        return prefix;
    }
    void (Adjusted_guess::*at54_guess)() = &Adjusted_guess::At54_guess;
    (reinterpret_cast<Adjusted_guess*>(this)->*at54_guess)();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Shows the guild entry from the server: time zone, comment, expiry, level range (1-70 when unlisted), AA
// minimum and classes (all when unlisted).
// FUNCTION: TITANIUM 0x005296FA
// @early-stop: budget, diff ndiff=3
void TimerState_guess::Step2_guess() {
    if (status_06c0_update_guess != 0) {
        int value_guess = value_05d4_update_guess != 0 ? field_05d0_update_guess + 1 : 0;
        status_06c0_update_guess->Set_guess(value_guess);
    }
    if (target_06c8_update_guess != 0) {
        StringValue_guess text_guess(value_05d4_update_guess != 0
            ? text_03c0_update_guess : EQ_ARRAY(const char, 0x0063F53F));
        target_06c8_update_guess->SetText_guess(text_guess);
    }
    if (target_06d8_update_guess != 0) {
        char text_buffer_guess[0x400];
        long time_guess;
        text_buffer_guess[0] = 0;
        if (value_05d4_update_guess != 0) {
            // A guild entry expires 30 days after it was posted (string 0x17CF).
            time_guess = field_05d8_update_guess + 0x278d00;
            FUN_0046da4a_guess(text_buffer_guess, 0x17cf,
                ctime(&time_guess), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        target_06d8_update_guess->Slot48_guess(value_05d4_update_guess, 1);
        StringValue_guess text_guess(text_buffer_guess);
        target_06d8_update_guess->SetText_guess(text_guess);
    }
    if (target_06b8_update_guess != 0) {
        int value_guess = value_05d4_update_guess != 0 ? field_05c0_update_guess : 1;
        StringValue_guess text_guess(__itoa(value_guess, EQ_ARRAY(char, 0x0099DB00), 10));
        target_06b8_update_guess->SetText_guess(text_guess);
    }
    if (target_06bc_update_guess != 0) {
        int value_guess = value_05d4_update_guess != 0 ? field_05c4_update_guess : 0x46;
        StringValue_guess text_guess(__itoa(value_guess, EQ_ARRAY(char, 0x0099DB00), 10));
        target_06bc_update_guess->SetText_guess(text_guess);
    }
    if (target_06c4_update_guess != 0) {
        int value_guess = value_05d4_update_guess != 0 ? field_05cc_update_guess : 0;
        StringValue_guess text_guess(__itoa(value_guess, EQ_ARRAY(char, 0x0099DB00), 10));
        target_06c4_update_guess->SetText_guess(text_guess);
    }
    int mask_guess = value_05d4_update_guess != 0 ? field_05c8_update_guess : -1;
    reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0670_update_guess, mask_guess);
    time_0630_update_guess = FUN_0046d655_guess();
    Update_005280e0_guess();
}

// Guild finder window (0x991C40): clears the flag at +0x5D4 and redisplays the guild entry
// (0x005296FA). The guild member list handler (0x0040AF04) calls it after a new roster arrives.
// FUNCTION: TITANIUM 0x00529B96
void TimerState_guess::Reset_00529b96_guess() {
    value_05d4_guess = 0;
    Step2_guess();
}

struct DeleteTargetA_guess {
    // EXTERNAL: TITANIUM 0x005293E5 DeleteTargetA_guess::DeleteVector_guess
    void DeleteVector_guess(int flags);
};

struct DeleteTargetB_guess {
    // EXTERNAL: TITANIUM 0x00529430 DeleteTargetB_guess::DeleteVector_guess
    void DeleteVector_guess(int flags);
};

struct Slot76Target_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess();
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual void Slot76_guess();
};

struct CStmlWndView_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 CStmlWndView_guess::SetSTMLText
    void SetSTMLText(StringValue_guess value, int first, int second);
};

struct Slot63Target_guess;

struct ResetOwnerA_guess {
    char gap_0000_0628_guess[0x628];
    DeleteTargetA_guess* target_0628_guess;
    char gap_062c_06e0_guess[0x6e0 - 0x62c];
    Slot63Target_guess* target_06e0_guess;     // 0x6e0
    ResourceObject_guess* target_06e4_guess;   // 0x6e4
    ResourceObject_guess* target_06e8_guess;   // 0x6e8
    Slot63Target_guess* target_06ec_guess;     // 0x6ec
    char gap_06f0_06f4_guess[4];
    Slot76Target_guess* target_06f4_guess;
    CStmlWndView_guess* sink_06f8_guess;
    void Reset_guess();
    void Step3_guess();
};

struct ResetOwnerB_guess {
    char gap_0000_0620_guess[0x620];
    DeleteTargetB_guess* target_0620_guess;
    char gap_0624_0700_guess[0x700 - 0x624];
    FlagElement_guess* elements_0700_guess[16];
    char gap_0740_075c_guess[0x75c - 0x740];
    Slot76Target_guess* target_075c_guess;
    CStmlWndView_guess* sink_0760_guess;
    void Reset_guess();
};

// Clears the guild search results and comment.
// FUNCTION: TITANIUM 0x00529BA2
void ResetOwnerA_guess::Reset_guess() {
    if (target_0628_guess != 0) {
        target_0628_guess->DeleteVector_guess(3);
        target_0628_guess = 0;
    }
    if (target_06f4_guess != 0) {
        target_06f4_guess->Slot76_guess();
    }
    if (sink_06f8_guess != 0) {
        sink_06f8_guess->SetSTMLText(EQ_ARRAY(char, 0x0063F53F), 1, 0);
    }
}

// Clears the player search results and comment and checks every class.
// FUNCTION: TITANIUM 0x00529BFC
void ResetOwnerB_guess::Reset_guess() {
    if (target_0620_guess != 0) {
        target_0620_guess->DeleteVector_guess(3);
        target_0620_guess = 0;
    }
    if (target_075c_guess != 0) {
        target_075c_guess->Slot76_guess();
    }
    if (sink_0760_guess != 0) {
        sink_0760_guess->SetSTMLText(EQ_ARRAY(char, 0x0063F53F), 1, 0);
    }
    reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0700_guess, 0xffffffff);
}

// Updates the buttons of the tab that is showing (+0x634 against the four page pointers at +0x63C).
// FUNCTION: TITANIUM 0x00529C66
void TimerState_guess::Dispatch_guess() {
    int value = field_0634_guess;
    if (value == field_063c_guess) {
        Update_0052805e_guess();
        return;
    }
    if (value == field_0640_guess) {
        Update_005280e0_guess();
        return;
    }
    if (value == field_0644_guess) {
        reinterpret_cast<TimedOwner_guess*>(this)->UpdateFirst_guess();
        return;
    }
    if (value == field_0648_guess) {
        reinterpret_cast<TimedOwner_guess*>(this)->UpdateSecond_guess();
        return;
    }
}

struct Slot63Target_guess {
    virtual void RefreshCounts_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
    virtual void Slot48_guess(unsigned char first_guess, int second_guess); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(const StringValue_guess& value);
};

// Shows your entry from the server: time zone, comment, "level class AA" (string 0x17E8; profile +0x11A4
// level, +0x119C class) and the expiry.
// FUNCTION: TITANIUM 0x0052947B
// @early-stop: budget, diff ndiff=3
void TimerState_guess::Refresh_guess() {
    long timestamp_guess;

    if (status_0654_guess != 0) {
        status_0654_guess->Set_guess(
            value_03b0_guess != 0 ? result_03ac_guess + 1 : 0);
    }

    if (target_0658_guess != 0) {
        StringValue_guess value_guess(value_03b0_guess != 0 ? text_01a0_guess :
            EQ_ARRAY(char, 0x0063F53F));
        target_0658_guess->Slot63_guess(value_guess);
    }

    char text_buffer_guess[0x400];
    if (target_0650_guess != 0) {
        unsigned char language_guess = g_pc_guess->Profile_guess()->field_119c_guess;
        int count_guess = g_pc_guess->Profile_guess()->field_11a4_guess;
        FUN_0046da4a_guess(text_buffer_guess, 0x17e8,
            _itoa(count_guess, EQ_ARRAY(char, 0x0099DB00), 10),
            pStringTable->getString(
                EQ_ARRAY(unsigned int, 0x00792EEC)[language_guess], 0),
            _itoa(g_pc_guess->GetValue_guess(), EQ_ARRAY(char, 0x0099DAE0), 10),
            0, 0, 0, 0, 0, 0);
        StringValue_guess value_guess(text_buffer_guess);
        target_0650_guess->Slot63_guess(value_guess);
    }

    if (target_0668_guess != 0) {
        text_buffer_guess[0] = 0;
        if (value_03b0_guess != 0) {
            // Your own entry expires 7 days after it was posted.
            timestamp_guess = time_03b8_guess + 0x93a80;
            FUN_0046da4a_guess(text_buffer_guess, 0x17cf,
                ctime(&timestamp_guess), 0, 0, 0, 0, 0, 0, 0, 0);
        }
        target_0668_guess->Slot48_guess(value_03b0_guess, 1);
        StringValue_guess value_guess(text_buffer_guess);
        target_0668_guess->Slot63_guess(value_guess);
    }

    time_0630_guess = FUN_0046d655_guess();
    Update_0052805e_guess();
}

// Guild search defaults: your level, class and AA count, any time zone.
// FUNCTION: TITANIUM 0x00529CA1
void ResetOwnerA_guess::Step3_guess() {
    Reset_guess();
    if (target_06e4_guess != 0) {
        target_06e4_guess->Finish_guess(
            reinterpret_cast<PcCharInfo_guess*>(g_pc_guess->Profile_guess())->field_119c_guess - 1);
    }
    if (target_06e8_guess != 0) {
        target_06e8_guess->Finish_guess(0);
    }
    if (target_06ec_guess != 0) {
        StringValue_guess text_guess(__itoa(g_pc_guess->GetValue_guess(), EQ_ARRAY(char, 0x0099DB00), 10));
        target_06ec_guess->Slot63_guess(text_guess);
    }
    if (target_06e0_guess != 0) {
        int value_guess = reinterpret_cast<PcCharInfo_guess*>(g_pc_guess->Profile_guess())->field_11a4_guess;
        StringValue_guess text_guess(__itoa(value_guess, EQ_ARRAY(char, 0x0099DB00), 10));
        target_06e0_guess->Slot63_guess(text_guess);
    }
}

struct ResetOwnerC_guess {
    char gap_0000_0700_guess[0x700];
    FlagElement_guess* elements_0700_guess[16];
    char gap_0740_0748_guess[0x8];
    Slot63Target_guess* target_0748_guess;
    Slot63Target_guess* target_074c_guess;
    ResourceObject_guess* resource_0750_guess;
    Slot63Target_guess* target_0754_guess;
    void Reset_guess();
};

// Player search defaults: levels 1-70, AA minimum 0, every class.
// FUNCTION: TITANIUM 0x00529DC8
void ResetOwnerC_guess::Reset_guess() {
    reinterpret_cast<ResetOwnerB_guess*>(this)->Reset_guess();
    if (resource_0750_guess != 0) {
        resource_0750_guess->Finish_guess(0);
    }
    if (target_0754_guess != 0) {
        StringValue_guess text_guess(EQ_ARRAY(char, 0x006410A8));
        target_0754_guess->Slot63_guess(text_guess);
    }
    if (target_0748_guess != 0) {
        StringValue_guess text_guess(EQ_ARRAY(char, 0x00645EB4));
        target_0748_guess->Slot63_guess(text_guess);
    }
    if (target_074c_guess != 0) {
        StringValue_guess text_guess(EQ_ARRAY(char, 0x00650DF4));
        target_074c_guess->Slot63_guess(text_guess);
    }
    reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0700_guess, 0xffffffff);
}

// Reads which tab shows and updates its buttons.
// FUNCTION: TITANIUM 0x00529ECE
void TimerState_guess::Reset_guess() {
    field_0634_guess = source_0638_guess->Get_guess();
    Dispatch_guess();
}

struct BuffEntry48_guess {
    char text_guess[0x40];
    CXStr text40_guess;
    int value44_guess;
    // EXTERNAL: TITANIUM 0x00527BFB BuffEntry48_guess::BuffEntry48_guess
    BuffEntry48_guess();
    // EXTERNAL: TITANIUM 0x00527C02 BuffEntry48_guess::~BuffEntry48_guess
    ~BuffEntry48_guess();
};

struct BuffRecord58_guess {
    char text_guess[0x40];
    int number40_guess;
    char text44_guess[8];
    int number4c_guess;
    int key_guess;
    CXStr text54_guess;
    // EXTERNAL: TITANIUM 0x00527C0A BuffRecord58_guess::BuffRecord58_guess
    BuffRecord58_guess();
    // EXTERNAL: TITANIUM 0x00527C11 BuffRecord58_guess::~BuffRecord58_guess
    ~BuffRecord58_guess();
};

struct BuffLoadMessage_guess {
    int type_guess;
    int field04_guess;
    union {
        char buffer_guess[0x264];
        struct {
            int count_guess;
            char data_guess[0x260];
        } entries_guess;
    };
};

struct BuffWindow_guess {
    void* vftable_guess;
    char gap_004_05c_guess[0x58];
    unsigned char show_05c_guess;
    char gap_05d_160_guess[0x160 - 0x5d];
    char buffer_160_guess[0x25c];
    char buffer_3bc_guess[0x260];
    char gap_61c_620_guess[4];
    BuffRecord58_guess* records_0620_guess;
    int count_0624_guess;
    BuffEntry48_guess* records_0628_guess;
    int count_062c_guess;
    void HandleMessage_guess(int unused_guess, const BuffLoadMessage_guess* message_guess,
        int unused2_guess);
};

// EXTERNAL: TITANIUM 0x004657FB FilterBadWords_guess
void __cdecl FilterBadWords_guess(const char* source_guess, char* destination_guess);

// BuffWindow_guess is misnamed: this is the OP_LFGuild reply handler. Type 0 is your own entry (0x25C bytes), 1 your
// guild's (0x260), 3 player results, 4 guild results, 6 opens the window. Results are packed records of
// zero-terminated strings and ints; a chat line (string 0x17D0) gives the count.
// FUNCTION: TITANIUM 0x00529EEA
// @early-stop: budget, diff ndiff=57
void BuffWindow_guess::HandleMessage_guess(int unused_guess,
    const BuffLoadMessage_guess* message_guess, int unused2_guess) {
    char text_guess[0x1000];
    char buffer3_guess[0x400];
    char buffer4_guess[0x400];
    switch (message_guess->type_guess) {
    case 4: {
        const char* data_guess = message_guess->entries_guess.data_guess;
        reinterpret_cast<ResetOwnerA_guess*>(this)->Reset_guess();
        records_0628_guess = new BuffEntry48_guess[message_guess->entries_guess.count_guess];
        count_062c_guess = message_guess->entries_guess.count_guess;
        int i = 0;
        if (message_guess->entries_guess.count_guess > 0) {
            do {
                BuffEntry48_guess& entry_guess = records_0628_guess[i];
                strcpy(entry_guess.text_guess, data_guess);
                data_guess += strlen(data_guess) + 1;
                entry_guess.value44_guess = *(const int*)data_guess;
                data_guess += 4;
                FilterBadWords_guess(data_guess, text_guess);
                entry_guess.text40_guess = text_guess;
                data_guess += strlen(data_guess) + 1;
                ++i;
            } while (i < message_guess->entries_guess.count_guess);
        }
        reinterpret_cast<RecordOwner_guess*>(this)->Populate_guess();
        FUN_0046da4a_guess(buffer4_guess, 0x17d0,
            _itoa(message_guess->entries_guess.count_guess, EQ_ARRAY(char, 0x0099DB00), 10),
            0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer4_guess, 0, 1);
        break;
    }
    case 3: {
        const char* data_guess = message_guess->entries_guess.data_guess;
        reinterpret_cast<ResetOwnerB_guess*>(this)->Reset_guess();
        records_0620_guess = new BuffRecord58_guess[message_guess->entries_guess.count_guess];
        count_0624_guess = message_guess->entries_guess.count_guess;
        int i = 0;
        if (message_guess->entries_guess.count_guess > 0) {
            do {
                BuffRecord58_guess& entry_guess = records_0620_guess[i];
                strcpy(entry_guess.text_guess, data_guess);
                data_guess += strlen(data_guess) + 1;
                entry_guess.number40_guess = *(const int*)data_guess;
                data_guess += 4;
                strcpy(entry_guess.text44_guess, pStringTable->getString(
                    EQ_ARRAY(unsigned int, 0x00792EEC)[*(const int*)data_guess],
                    0));
                data_guess += 4;
                entry_guess.number4c_guess = *(const int*)data_guess;
                data_guess += 4;
                entry_guess.key_guess = *(const int*)data_guess;
                data_guess += 4;
                FilterBadWords_guess(data_guess, text_guess);
                entry_guess.text54_guess = text_guess;
                data_guess += strlen(data_guess) + 1;
                // Time zones -1 to 23; anything else becomes -1.
                if (entry_guess.key_guess < -1 || entry_guess.key_guess > 0x17) {
                    entry_guess.key_guess = -1;
                }
                ++i;
            } while (i < message_guess->entries_guess.count_guess);
        }
        reinterpret_cast<RecordTable_guess*>(this)->Populate_guess();
        FUN_0046da4a_guess(buffer3_guess, 0x17d0,
            _itoa(message_guess->entries_guess.count_guess, EQ_ARRAY(char, 0x0099DB00), 10),
            0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer3_guess, 0, 1);
        break;
    }
    case 1:
        memcpy(buffer_3bc_guess, message_guess->buffer_guess, 0x260);
        if (show_05c_guess) {
            reinterpret_cast<TimerState_guess*>(this)->Step2_guess();
        }
        break;
    case 0:
        memcpy(buffer_160_guess, message_guess->buffer_guess, 0x25c);
        if (show_05c_guess) {
            reinterpret_cast<TimerState_guess*>(this)->Refresh_guess();
        }
        break;
    case 6:
        reinterpret_cast<TimerTarget_guess*>(this)->Slot48_guess(true, 1);
        break;
    }
}

// PLFG On, Off and Update: sends your entry (type 0) with the listed flag set to match.
// FUNCTION: TITANIUM 0x0052A2BF
int TimerState_guess::HandleFirst_guess(TimerTarget_guess* target_guess, int action_guess, int unused_guess) {
    if (action_guess == 1) {
        if (target_guess == target_065c_guess) {
            value_03b0_guess = 1;
        } else if (target_guess == target_0660_guess) {
            value_03b0_guess = 0;
        } else if (target_guess != target_0664_guess) {
            return -1;
        } else {
            value_03b0_guess = 1;
        }

        ResetFirst_guess buffer_guess;
        int messageData_guess[2];
        messageData_guess[0] = 0;
        reinterpret_cast<RefreshTarget_guess*>(this)->Refresh_guess();
        memcpy(&buffer_guess, source_0160_guess, 0x25c);
        EQSendMessage(&g_messageConnection_guess, OP_LFGuild, messageData_guess, 0x264, 1);
        time_0630_guess = FUN_0046d655_guess();
        Dispatch_guess();
        return 0;
    }
    return -1;
}

// GLFP On, Off and Update send the guild entry (type 1); select all and deselect all set the classes.
// FUNCTION: TITANIUM 0x0052A37F
// @early-stop: budget, structural ndiff=24
int TimerState_guess::HandleSecond_guess(TimerTarget_guess* target_guess, int action_guess, int unused_guess) {
    if (action_guess == 1) {
        if (target_guess == target_06cc_guess) {
            value_05d4_guess = 1;
        } else if (target_guess == target_06d0_guess) {
            value_05d4_guess = 0;
        } else if (target_guess == target_06d4_guess) {
            value_05d4_guess = 1;
        } else {
            unsigned int mask_guess;
            if (target_guess == reinterpret_cast<TimerTarget_guess*>(value_06b0_guess)) {
                mask_guess = 0xffffffff;
            } else if (target_guess == reinterpret_cast<TimerTarget_guess*>(value_06b4_guess)) {
                mask_guess = 0;
            } else {
                Dispatch_guess();
                return 0;
            }
            reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0670_guess, mask_guess);
            Dispatch_guess();
            return 0;
        }

        ResetSecond_guess buffer_guess;
        int messageData_guess[2];
        messageData_guess[0] = 1;
        reinterpret_cast<UpdateOwner_guess*>(this)->Update_guess();
        memcpy(&buffer_guess, source_03bc_guess, 0x260);
        EQSendMessage(&g_messageConnection_guess, OP_LFGuild, messageData_guess, 0x268, 1);
        time_0630_guess = FUN_0046d655_guess();
        Dispatch_guess();
        return 0;
    }
    return -1;
}

struct Buff_guess {
    char gap_0000_0040_guess[0x40];
    StringValue_guess text_40_guess;   // 0x40
    int value_44_guess;                // 0x44
};

struct CListWndView_guess {
    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView_guess::GetItemData
    Buff_guess* GetItemData(int index_guess);
};

struct BuffSort_guess {
    int mode_guess;        // 0x00
    int pad_guess;         // 0x04
    char* first_guess;     // 0x08
    int pad2_guess;        // 0x0c
    char* second_guess;    // 0x10
    int result_guess;      // 0x14
};

struct BuffMessage_guess {
    int type_guess;        // 0x00
    int pad_guess;         // 0x04
    int first_guess;       // 0x08
    int second_guess;      // 0x0c
    int third_guess;       // 0x10
    int fourth_guess;      // 0x14
};

// EXTERNAL: TITANIUM 0x00574460 FUN_00574460_guess
int __cdecl FUN_00574460_guess(const char* first_guess, const char* second_guess);

struct TimerNotify_guess {
    char gap_0000_061c_guess[0x61c];
    int timestamp_guess;                        // 0x61c
    char gap_0620_06e0_guess[0x6e0 - 0x620];
    StringProvider_guess* provider_06e0_guess;  // 0x6e0
    StatusSource_guess* status_06e4_guess;      // 0x6e4
    StatusSource_guess* status_06e8_guess;      // 0x6e8
    StringProvider_guess* provider_06ec_guess;  // 0x6ec
    TimerTarget_guess* state_06f0_guess;        // 0x6f0
    CListWndView_guess* list_06f4_guess;            // 0x6f4
    CStmlWndView_guess* sink_06f8_guess;                // 0x6f8
    int WndNotification_guess(TimerTarget_guess* sender_guess, unsigned int message_guess,
        void* data_guess);
};

// Guild search tab: a result shows its comment in PSFG_Comment; PSFG_SearchButton sends type 4 {level, AA
// count, time zone, class}. Notification 0x10 asks how two rows compare: name, time zone, comment.
// FUNCTION: TITANIUM 0x0052A46C
int TimerNotify_guess::WndNotification_guess(TimerTarget_guess* sender_guess,
    unsigned int message_guess, void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == reinterpret_cast<TimerTarget_guess*>(list_06f4_guess)) {
            Buff_guess* buff_guess =
                list_06f4_guess->GetItemData(list_06f4_guess->GetCurSel());
            if (buff_guess != 0 && sink_06f8_guess != 0) {
                StringValue_guess value_guess = FUN_0060aca0_guess(buff_guess->text_40_guess);
                sink_06f8_guess->SetSTMLText(value_guess, 1, 0);
            }
        }
        if (sender_guess == state_06f0_guess) {
            BuffMessage_guess message_data_guess;
            message_data_guess.type_guess = 4;
            message_data_guess.second_guess = 0;
            if (provider_06ec_guess != 0) {
                message_data_guess.second_guess = atoi(provider_06ec_guess->Get_guess().Get_guess());
            }
            message_data_guess.first_guess = 0;
            if (provider_06e0_guess != 0) {
                message_data_guess.first_guess = atoi(provider_06e0_guess->Get_guess().Get_guess());
            }
            message_data_guess.fourth_guess = 0;
            if (status_06e4_guess != 0) {
                message_data_guess.fourth_guess = status_06e4_guess->GetCurChoice_guess() + 1;
            }
            message_data_guess.third_guess = -1;
            if (status_06e8_guess != 0) {
                message_data_guess.third_guess = status_06e8_guess->GetCurChoice_guess() - 1;
            }
            EQSendMessage(&g_messageConnection_guess, OP_LFGuild,
                reinterpret_cast<int*>(&message_data_guess), 0x18, 1);
            timestamp_guess = Time_guess(0);
            reinterpret_cast<ResetOwnerA_guess*>(this)->Reset_guess();
            reinterpret_cast<TimerState_guess*>(this)->Dispatch_guess();
        }
    } else if (message_guess == 0xf) {
        if (sender_guess == reinterpret_cast<TimerTarget_guess*>(list_06f4_guess)) {
            reinterpret_cast<FlagHandler_guess*>(this)->Select_guess(
                reinterpret_cast<State_guess*>(list_06f4_guess), (int)data_guess);
            return 1;
        }
    } else if (message_guess == 0x10 &&
               sender_guess == reinterpret_cast<TimerTarget_guess*>(list_06f4_guess)) {
        BuffSort_guess* sort_guess = reinterpret_cast<BuffSort_guess*>(data_guess);
        int mode_guess = sort_guess->mode_guess;
        char* first_guess = sort_guess->first_guess;
        char* second_guess = sort_guess->second_guess;
        switch (mode_guess) {
        case 0:
            sort_guess->result_guess = FUN_00574460_guess(first_guess, second_guess);
            break;
        case 1: {
            int difference_guess = reinterpret_cast<Buff_guess*>(first_guess)->value_44_guess -
                                   reinterpret_cast<Buff_guess*>(second_guess)->value_44_guess;
            sort_guess->result_guess = difference_guess < 0 ? -1 : (difference_guess > 0);
            break;
        }
        case 2:
            sort_guess->result_guess = FUN_00574460_guess(
                reinterpret_cast<Buff_guess*>(first_guess)->text_40_guess.Get_guess(),
                reinterpret_cast<Buff_guess*>(second_guess)->text_40_guess.Get_guess());
            break;
        }
    }
    return -1;
}

struct Entry54_guess {
    char gap_0000_0054_guess[0x54];
    StringValue_guess text_54_guess;   // 0x54
};

struct CListWndView2_guess {
    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView2_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 CListWndView2_guess::GetItemData
    Entry54_guess* GetItemData(int index_guess);
};

struct EntrySort_guess {
    int mode_guess;                      // 0x00
    StringValue_guess first_text_guess;  // 0x04
    RecordEntry58_guess* first_guess;    // 0x08
    StringValue_guess second_text_guess; // 0x0c
    RecordEntry58_guess* second_guess;   // 0x10
    int result_guess;                    // 0x14
};

struct EntryMessage_guess {
    int type_guess;          // 0x00
    int pad_guess;           // 0x04
    int value_08_guess;      // 0x08
    int value_0c_guess;      // 0x0c
    int value_10_guess;      // 0x10
    int value_14_guess;      // 0x14
    unsigned int mask_guess; // 0x18
};

struct EntryNotify_guess {
    char gap_0000_061c_guess[0x61c];
    int timestamp_guess;                        // 0x61c
    char gap_0620_0700_guess[0x700 - 0x620];
    FlagElement_guess* elements_0700_guess[16]; // 0x700
    TimerTarget_guess* button_0740_guess;       // 0x740
    TimerTarget_guess* button_0744_guess;       // 0x744
    StringProvider_guess* provider_0748_guess;  // 0x748
    StringProvider_guess* provider_074c_guess;  // 0x74c
    StatusSource_guess* status_0750_guess;      // 0x750
    StringProvider_guess* provider_0754_guess;  // 0x754
    TimerTarget_guess* button_0758_guess;       // 0x758
    CListWndView2_guess* list_075c_guess;           // 0x75c
    CStmlWndView_guess* sink_0760_guess;                // 0x760
    int WndNotification_guess(TimerTarget_guess* sender_guess, unsigned int message_guess,
        void* data_guess);
};

// Player search tab: a result shows its comment; GSFP_SearchButton sends type 3 {level min, level max, AA
// minimum, time zone, class mask}. Notification 0x10 compares two rows for the column sort.
// FUNCTION: TITANIUM 0x0052A68C
int EntryNotify_guess::WndNotification_guess(TimerTarget_guess* sender_guess,
    unsigned int message_guess, void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == reinterpret_cast<TimerTarget_guess*>(list_075c_guess)) {
            Entry54_guess* entry_guess =
                list_075c_guess->GetItemData(list_075c_guess->GetCurSel());
            if (entry_guess != 0 && sink_0760_guess != 0) {
                StringValue_guess value_guess = FUN_0060aca0_guess(entry_guess->text_54_guess);
                sink_0760_guess->SetSTMLText(value_guess, 1, 0);
            }
        } else if (sender_guess == button_0740_guess) {
            reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0700_guess, 0xffffffff);
        } else if (sender_guess == button_0744_guess) {
            reinterpret_cast<FlagHandler_guess*>(this)->Apply_guess(elements_0700_guess, 0);
        } else if (sender_guess == button_0758_guess) {
            EntryMessage_guess message_data_guess;
            message_data_guess.type_guess = 3;
            message_data_guess.value_10_guess = 0;
            if (provider_0754_guess != 0) {
                message_data_guess.value_10_guess = atoi(provider_0754_guess->Get_guess().Get_guess());
            }
            message_data_guess.value_08_guess = 0;
            if (provider_0748_guess != 0) {
                message_data_guess.value_08_guess = atoi(provider_0748_guess->Get_guess().Get_guess());
            }
            message_data_guess.value_0c_guess = 0;
            if (provider_074c_guess != 0) {
                message_data_guess.value_0c_guess = atoi(provider_074c_guess->Get_guess().Get_guess());
            }
            message_data_guess.mask_guess =
                reinterpret_cast<FlagHandler_guess*>(this)->BuildMask_guess(elements_0700_guess);
            message_data_guess.value_14_guess = -1;
            if (status_0750_guess != 0) {
                message_data_guess.value_14_guess = status_0750_guess->GetCurChoice_guess() - 1;
            }
            EQSendMessage(&g_messageConnection_guess, OP_LFGuild,
                reinterpret_cast<int*>(&message_data_guess), 0x1c, 1);
            timestamp_guess = Time_guess(0);
            reinterpret_cast<ResetOwnerB_guess*>(this)->Reset_guess();
            reinterpret_cast<TimerState_guess*>(this)->Dispatch_guess();
        }
    } else if (message_guess == 0xf) {
        if (sender_guess == reinterpret_cast<TimerTarget_guess*>(list_075c_guess)) {
            reinterpret_cast<FlagHandler_guess*>(this)->Select_guess(
                reinterpret_cast<State_guess*>(list_075c_guess), (int)data_guess);
            return 1;
        }
    } else if (message_guess == 0x10 &&
               sender_guess == reinterpret_cast<TimerTarget_guess*>(list_075c_guess)) {
        EntrySort_guess* sort_guess = reinterpret_cast<EntrySort_guess*>(data_guess);
        int mode_guess = sort_guess->mode_guess;
        RecordEntry58_guess* first_guess = sort_guess->first_guess;
        RecordEntry58_guess* second_guess = sort_guess->second_guess;
        int difference_guess;
        switch (mode_guess) {
        case 0:
        case 2:
        case 5:
            sort_guess->result_guess = FUN_00574460_guess(
                sort_guess->first_text_guess.Get_guess(), sort_guess->second_text_guess.Get_guess());
            break;
        case 1:
            difference_guess = first_guess->level_0040_guess - second_guess->level_0040_guess;
            sort_guess->result_guess = difference_guess < 0 ? -1 : (difference_guess > 0);
            break;
        case 3:
            difference_guess = first_guess->number4c_guess - second_guess->number4c_guess;
            sort_guess->result_guess = difference_guess < 0 ? -1 : (difference_guess > 0);
            break;
        case 4:
            difference_guess = (int)first_guess->key_guess - (int)second_guess->key_guess;
            sort_guess->result_guess = difference_guess < 0 ? -1 : (difference_guess > 0);
            break;
        }
    }
    return -1;
}

