// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 163: a hint from compare/tumap.py.
// The group search window (GroupSearchWnd, CGroupSearchWnd_guess; CGroupSearchWndView_guess is the same
// object): Player Info and Group Info pages (post yourself or your group) and Player List and Group List
// pages (search for players or groups), with level ranges (1-70), class filters and the filter window from
// tu_162. Searches share a 15 s countdown (0x00509765); posts are not limited.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <string.h>

struct DispatchObject_guess {
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
    virtual void Dispatch_guess();
    // EXTERNAL: TITANIUM 0x00508955 DispatchObject_guess::IsFilteredOut_guess
    char IsFilteredOut_guess(void* object, int value);
};

#define pinstCGroupSearchFiltersWnd_guess EQ_GLOBAL(DispatchObject_guess*, 0x00850BD4)

struct FixedObject_guess {
    // EXTERNAL: TITANIUM 0x0040AC55 FixedObject_guess::ReadValue_guess
    int ReadValue_guess(int value);
};

#define g_fixedObject_guess EQ_GLOBAL(FixedObject_guess, 0x00905D38)

struct TargetObject_guess {
    char text_guess[0x40];
    int value40_guess;
    int value44_guess;
    char pad_0048_guess[4];
    int value_guess;
    char pad_0050_guess[4];
};

struct TargetNotification_guess;

struct NotificationObject_guess {
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
    virtual int Slot76_guess();
    virtual void Slot77_guess();
    virtual void Notify_guess();
    char pad_0004_guess[0x150];
    int value_guess;
    char enabled_guess;
};

struct NotificationOwner_guess {
    char pad_0000_guess[0x23c];
    NotificationObject_guess* first_guess;
    char pad_0240_guess[0x14];
    NotificationObject_guess* second_guess;

    void UpdateFirst_guess(int value);
    void UpdateSecond_guess(int value);
};

struct QueueOwner_guess {
    char pad_0000_guess[0x19c];
    CButtonWnd* entries_guess[16];

    void SelectAllRoles_guess();
    void DeselectAllRoles_guess();
};

struct ResourceManager_guess {
    // EXTERNAL: TITANIUM 0x00496D39 ResourceManager_guess::SendLFGCommand_guess
    void SendLFGCommand_guess(void* data);
    // EXTERNAL: TITANIUM 0x00496D76 ResourceManager_guess::SendLFPCommand_guess
    void SendLFPCommand_guess(void* data);
    // EXTERNAL: TITANIUM 0x00496D93 ResourceManager_guess::SendLFGGetMatchesRequest_guess
    void SendLFGGetMatchesRequest_guess(void* data);
    // EXTERNAL: TITANIUM 0x00496DB0 ResourceManager_guess::SendLFPGetMatchesRequest_guess
    void SendLFPGetMatchesRequest_guess(void* data);
    // EXTERNAL: TITANIUM 0x004922D5 ResourceManager_guess::GetClassThreeLetterCode
    char* GetClassThreeLetterCode(int value_guess);
};

#define g_resourceManager_guess EQ_GLOBAL(ResourceManager_guess*, 0x00988DF0)

struct TimeOwner_guess {
    char pad_0000_guess[0x148];
    unsigned int now_guess;
};

#define g_timeOwner_guess EQ_GLOBAL(TimeOwner_guess*, 0x00905D24)

struct BufferOwner_guess {
    char pad_0000_guess[0x27c];
    char firstBuffer_guess[0x50];
    char pad_02cc_guess[0xe43c];
    char secondBuffer_guess[0x54];

    void SendLFGOff_guess();
    void SendLFPOff_guess();
};

struct SubObject_guess {
    // EXTERNAL: TITANIUM 0x005BC3A0 SubObject_guess::Apply_guess
    void Apply_guess(int value, int flags);
};

struct Object_guess {
    char pad_0000_guess[0x15c];
    SubObject_guess* subObject_guess;

    void Handle_guess(int value);
    // EXTERNAL: TITANIUM 0x005A0A80 Object_guess::Update_guess
    void Update_guess(int first, int second);
};

struct Str_guess {
    char* data_guess;

    // EXTERNAL: TITANIUM 0x00571630 Str_guess::GetLength_guess
    int GetLength_guess();
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x00571E00 Str_guess::Str_guess
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct FormatResult_guess {
    char* data_guess;
    ~FormatResult_guess() {
        if (data_guess != 0) {
            reinterpret_cast<Str_guess*>(this)->FreeRep(data_guess);
        }
    }
};

struct StringProvider_guess {
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
    virtual void Slot63_guess(const Str_guess& text_guess);
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
    virtual Str_guess Get_guess();

    char pad_0004_guess[0x124];
    int value128_guess;
    unsigned int value12c_guess;
    char pad_0130_guess[0x100];
    int value230_guess;

    // EXTERNAL: TITANIUM 0x004D7EBC StringProvider_guess::SetMaxChars_guess
    void SetMaxChars_guess(int value_guess);
};

struct CXStrProvider_guess {
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
    virtual CXStr Get_guess();
};

struct SlotObject_guess;

struct StatusObject_guess {
    char pad_0000_guess[0x128];
    char enabled_guess;
};

struct Value17cTarget_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess);
    char pad_0004_guess[0x59];
    char enabled_guess;
};

struct SharedSlot_guess {
    char pad_0000_guess[4];
    // EXTERNAL: TITANIUM 0x00571F70 SharedSlot_guess::Assign_guess
    void Assign_guess(const Str_guess& value_guess);
};

struct WindowFlags66_guess {
    char pad_0000_guess[0x66];
    unsigned char value66_guess;
};

struct ListWnd_guess : CListWnd {
    char pad_0140_guess[0x14];
    int value154_guess;
    char pad_0158_guess[4];
    unsigned char value15c_guess;
    char pad_015d_guess[0xf];
    unsigned int value16c_guess;
};

struct SearchListWnd_guess : CListWnd {
    char pad_140_guess[0x14];
    int field_154_guess;
    char pad_158_guess[4];
    unsigned char field_15c_guess;
    char pad_15d_guess[0xf];
    unsigned int color_16c_guess;
};

struct TextSource_guess {
    // EXTERNAL: TITANIUM 0x004D22D7 TextSource_guess::FUN_004d22d7_guess
    Str_guess FUN_004d22d7_guess();
    // EXTERNAL: TITANIUM 0x004D22D7 TextSource_guess::GetText_guess
    CXStr GetText_guess();
};

struct LookupSource_guess;

struct ItemEntryValues_guess {
    char pad_0050_guess[0x44];
    int value94_guess;
    int value98_guess;
    int value9c_guess;
};

struct ItemEntry_guess {
    char pad_0000_guess[0x4c];
    int value4c_guess;
    union {
        ItemEntryValues_guess values_guess;
        TargetObject_guess check_guess;
    };
    char pad_00a4_guess[0x1a4];
};

struct SlotEntry_guess {
    char pad_0000_guess[0x48];
    union {
        int bits48_guess;
        unsigned char bitBytes48_guess[4];
    };
    int count_guess;
    union {
        TargetObject_guess rows_guess[6];
        char name_guess[0x1f8];
    };
};

struct CGroupSearchWndView_guess {
    char pad_0000_guess[0x15c];
    CXWnd* value15c_guess;
    CXWnd* value160_guess;
    CXWnd* value164_guess;
    StringProvider_guess* value168_guess;
    CXWnd* value16c_guess;
    StringProvider_guess* value170_guess;
    StringProvider_guess* value174_guess;
    Value17cTarget_guess* value178_guess;
    Value17cTarget_guess* value17c_guess;
    Value17cTarget_guess* value180_guess;
    CXWnd* value184_guess;
    CXWnd* value188_guess;
    StringProvider_guess* value18c_guess;
    CXWnd* value190_guess;
    StringProvider_guess* value194_guess;
    StringProvider_guess* value198_guess;
    CXWnd* list19c_guess[16];
    CXWnd* list1dc_guess[16];
    CXWnd* value21c_guess;
    CXWnd* value220_guess;
    SlotObject_guess* value224_guess;
    SlotObject_guess* value228_guess;
    SlotObject_guess* value22c_guess;
    CXWnd* value230_guess;
    CXWnd* value234_guess;
    CXWnd* value238_guess;
    CXWnd* value23c_guess;
    CXWnd* value240_guess;
    StatusObject_guess* value244_guess;
    CXWnd* value248_guess;
    CXWnd* value24c_guess;
    CXWnd* value250_guess;
    CXWnd* value254_guess;
    CXWnd* value258_guess;
    CXWnd* value25c_guess;
    CXWnd* value260_guess;
    StatusObject_guess* value264_guess;
    CXWnd* value268_guess;
    int value26c_guess;
    int value270_guess;
    int value274_guess;
    SharedSlot_guess value278_guess;
    char pad_027c_guess[4];
    char initialized_280_guess;
    char enabled_281_guess;
    char pad_0282_guess[2];
    int length_284_guess;
    int length_288_guess;
    char text_28c_guess[0x40];
    char pad_02cc_guess[4];
    union {
        int value2d0_guess;
        int itemCount_2d0_guess;
    };
    union {
        SlotEntry_guess entries_02d4_guess[100];
        ItemEntry_guess itemEntries_2d4_guess[100];
    };
    int bits_e6f4_guess;
    char enabled_e6f8_guess;
    char state_e6f9_guess;
    char pad_e6fa_guess[2];
    int value_e6fc_guess;
    int cachedGroupSize_e700_guess;
    CXStr object_e704_guess;
    char state_e708_guess[4];
    char initialized_e70c_guess;
    char enabled_e70d_guess;
    char pad_e70e_guess[2];
    int length194_e710_guess;
    int length198_e714_guess;
    int enabledBits_e718_guess;
    char text_e71c_guess[0x40];
    char pad_e75c_guess[4];
    char enabled_e760_guess;
    char pad_e761_guess[0xb];
    unsigned int lastUpdate_e76c_guess;

    void Init_guess();
    void InitializeControls_guess();
    int GetGipLevelMin_guess();
    int GetGipLevelMax_guess();
    int GetPipLevelMin_guess();
    int GetPipLevelMax_guess();
    void SendPlayerInfo_guess();
    int CheckSlots_guess();
    void ShowSearchError_guess(int option_guess);
    void PostGroupInfo_guess();
    int CheckRange_guess();
    // EXTERNAL: TITANIUM 0x00507E5B CGroupSearchWndView_guess::IsExclusiveSearch_guess
    char IsExclusiveSearch_guess();
    void SendGroupInfo_guess();
    void SearchGroups_guess();
    void UpdatePlayerInfoLabel_guess();
    // EXTERNAL: TITANIUM 0x0050A2AA CGroupSearchWndView_guess::GetViewRange_guess
    void GetViewRange_guess(LookupSource_guess* source_guess, int* low_guess, int* high_guess);
    void InitPlayerInfoPage_guess();
    void InitGroupInfoPage_guess();
    void PostPlayerInfo_guess();
    void UpdatePlayerInfo_guess();
    void RefreshPlayerList_guess();
    void RemovePlayerInfo_guess();
    void RemoveGroupInfo_guess();
    void RemoveInfoOnGroupChange_guess();
    void NotifyObject_guess(TargetNotification_guess* object_guess);
    void OnProcessFrame_guess();
    int HandleTarget_guess(void* event_guess, int arg2_guess, int arg3_guess);
    int HandlePlayerInfoPage_guess(void* event_guess, int arg2_guess, int arg3_guess);
    int HandleGroupInfoPage_guess(void* event_guess, int arg2_guess, int arg3_guess);
    int HandleEvent_guess(void* event_guess, int arg2_guess, int arg3_guess);
    void ShowGroupDetails_guess(int value_guess);
    char ApplyToRow_guess(TargetObject_guess* object_guess);
    int FillGroupDetailList_guess(SlotEntry_guess* entry_guess);
    // EXTERNAL: TITANIUM 0x0055446C CGroupSearchWndView_guess::CompareNumericCells_guess
    void CompareNumericCells_guess(int* value_guess);
    void UpdateGroupInfo_guess();
    void ProcessEntry_guess(ItemEntry_guess* entry_guess);
    void OnGroupInfoEdited_guess();
    // EXTERNAL: TITANIUM 0x005096CB CGroupSearchWndView_guess::FUN_005096cb_guess
    void FUN_005096cb_guess();
    void OnPlayerInfoEdited_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CGroupSearchWndView_guess::FUN_0059dd30_guess
    char FUN_0059dd30_guess();
    void UpdateGroupInfoLabel_guess();
    int UpdateInfoPage_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x004482FB ??1CXStr@@QAE@XZ

// EXTERNAL: TITANIUM 0x005A3100 ??1BaseObject_guess@@UAE@XZ
struct BaseObject_guess {
    virtual ~BaseObject_guess();
    // EXTERNAL: TITANIUM 0x005A3850 ??0BaseObject_guess@@QAE@PAUCXWnd@@ABUStr_guess@@HHPAD@Z
    BaseObject_guess(CXWnd* parent, const Str_guess& screen, int flags, int iniVersion, char* blockName);
};

struct SidlPiece_guess {
    char pad_0000_guess[0x60];
    unsigned int style_060_guess;
};

// EXTERNAL: TITANIUM 0x006551D0 ??_7CGroupSearchWnd_guess@@6B@
struct SlotObject_guess;
struct CGroupSearchWnd_guess : BaseObject_guess {
    char pad_0004_guess[0x60];
    unsigned int windowStyle_064;
    char pad_0068_guess[0xbc];
    SidlPiece_guess* sidlPiece_124;
    char pad_0128_guess[0x120];
    SlotObject_guess* secondControl_guess;
    char pad_024c_guess[0x1c];
    SlotObject_guess* firstControl_guess;
    char pad_026c_guess[0xc];
    CXStr object_0278_guess;
    char pad_027c_guess[0x50];
    CXStr object_02cc_guess;
    char pad_02d0_guess[0xe434];
    CXStr object_e704_guess;
    char pad_e708_guess[0x54];
    CXStr object_e75c_guess;
    char pad_e760_guess[4];
    unsigned int lastUpdate_guess;
    int remaining_guess;

    CGroupSearchWnd_guess(CXWnd* parent);
    CGroupSearchWnd_guess* Destroy_guess(unsigned char flags_guess);
    void UpdateCountdown_guess(unsigned int now_guess);
    void SetUpdateTime_guess(unsigned int now_guess);
    virtual ~CGroupSearchWnd_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// Destructor of the group search window (vtable 0x6551D0): destroys its four strings (+0xE75C, +0xE704,
// +0x2CC, +0x278), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x005089EC
CGroupSearchWnd_guess::~CGroupSearchWnd_guess() {
}

// Clears the control pointers that 0x00508B6C fills.
// FUNCTION: TITANIUM 0x00508A81
void CGroupSearchWndView_guess::Init_guess() {
    value230_guess = 0;
    value160_guess = 0;
    value164_guess = 0;
    value170_guess = 0;
    value174_guess = 0;
    value168_guess = 0;
    value16c_guess = 0;
    value178_guess = 0;
    value17c_guess = 0;
    value180_guess = 0;
    value184_guess = 0;
    value188_guess = 0;
    value18c_guess = 0;
    value194_guess = 0;
    value198_guess = 0;
    value190_guess = 0;
    value224_guess = 0;
    value228_guess = 0;
    value22c_guess = 0;
    for (int i = 0; i < 16; ++i) {
        list19c_guess[i] = 0;
        list1dc_guess[i] = 0;
    }
    value21c_guess = 0;
    value220_guess = 0;
    value234_guess = 0;
    value238_guess = 0;
    value23c_guess = 0;
    value240_guess = 0;
    value244_guess = 0;
    value248_guess = 0;
    value24c_guess = 0;
    value250_guess = 0;
    value254_guess = 0;
    value258_guess = 0;
    value25c_guess = 0;
    value260_guess = 0;
    value264_guess = 0;
    value268_guess = 0;
}

// Finds the GSW_ and PIP_/GIP_ children of both pages.
// FUNCTION: TITANIUM 0x00508B6C
void CGroupSearchWndView_guess::InitializeControls_guess() {
    value15c_guess = ((CSidlScreenWnd*)this)->GetChildItem("GSW_InfoPages");
    value160_guess = ((CSidlScreenWnd*)this)->GetChildItem("PlayerInfoPage");
    if (value160_guess != 0) {
        value164_guess = ((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_PlayerInfoLabel");
        value168_guess = (StringProvider_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_CommentsEditbox");
        value170_guess = (StringProvider_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_LevelRangeMinEditbox");
        value174_guess = (StringProvider_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_LevelRangeMaxEditbox");
        value16c_guess = ((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_AdditionalFiltersButton");
        value178_guess = (Value17cTarget_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_PostMyInfoButton");
        value17c_guess = (Value17cTarget_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_UpdateMyInfoButton");
        value180_guess = (Value17cTarget_guess*)((CSidlScreenWnd*)value160_guess)->GetChildItem("PIP_RemoveMyInfoButton");
    }
    value184_guess = ((CSidlScreenWnd*)this)->GetChildItem("GroupInfoPage");
    if (value184_guess != 0) {
        value188_guess = ((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_GroupInfoLabel");
        value194_guess = (StringProvider_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_LevelRangeMinEditbox");
        value198_guess = (StringProvider_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_LevelRangeMaxEditbox");
        value18c_guess = (StringProvider_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_CommentsEditbox");
        value190_guess = ((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_AdditionalFiltersButton");
        value224_guess = (SlotObject_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_PostOurInfoButton");
        value228_guess = (SlotObject_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_UpdateOurInfoButton");
        value22c_guess = (SlotObject_guess*)((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_RemoveOurInfoButton");
        value21c_guess = ((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_SelectAllRolesButton");
        value220_guess = ((CSidlScreenWnd*)value184_guess)->GetChildItem("GIP_DeselectAllRolesButton");

        char buffer_guess[64];
        int roleIndex_guess = 0;
        const char* roleNames_guess[16] = {
            EQ_ARRAY(char, 0x0065549C), EQ_ARRAY(char, 0x00655498),
            EQ_ARRAY(char, 0x00655494), EQ_ARRAY(char, 0x00655490),
            EQ_ARRAY(char, 0x0065548C), EQ_ARRAY(char, 0x00655488),
            EQ_ARRAY(char, 0x00655484), EQ_ARRAY(char, 0x00655480),
            EQ_ARRAY(char, 0x0065547C), EQ_ARRAY(char, 0x00655478),
            EQ_ARRAY(char, 0x00655474), EQ_ARRAY(char, 0x00655470),
            EQ_ARRAY(char, 0x0065546C), EQ_ARRAY(char, 0x00655468),
            EQ_ARRAY(char, 0x00655464), EQ_ARRAY(char, 0x00655460)
        };
        for (; roleIndex_guess < 16; ++roleIndex_guess) {
            _snprintf(buffer_guess, 0x40, "GIP_%sCheckbox", roleNames_guess[roleIndex_guess]);
            list19c_guess[roleIndex_guess] = ((CSidlScreenWnd*)value184_guess)->GetChildItem(buffer_guess);
            _snprintf(buffer_guess, 0x40, "GIP_%sLabel", roleNames_guess[roleIndex_guess]);
            list1dc_guess[roleIndex_guess] = ((CSidlScreenWnd*)value184_guess)->GetChildItem(buffer_guess);
        }
    }
    value230_guess = ((CSidlScreenWnd*)this)->GetChildItem("GSW_SearchPages");
    value234_guess = ((CSidlScreenWnd*)this)->GetChildItem("PlayerListPage");
    if (value234_guess != 0) {
        value238_guess = ((CSidlScreenWnd*)value234_guess)->GetChildItem("PLP_NumSearchResultsLabel");
        value23c_guess = ((CSidlScreenWnd*)value234_guess)->GetChildItem("PLP_PlayerSearchResultList");
        value240_guess = ((CSidlScreenWnd*)value234_guess)->GetChildItem("PLP_ShowMatchesCheckbox");
        value244_guess = (StatusObject_guess*)((CSidlScreenWnd*)value234_guess)->GetChildItem("PLP_ShowAllCheckbox");
        value248_guess = ((CSidlScreenWnd*)value234_guess)->GetChildItem("PLP_RefreshPlayerButton");
    }
    value24c_guess = ((CSidlScreenWnd*)this)->GetChildItem("GroupListPage");
    if (value24c_guess != 0) {
        value250_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_NumSearchResultsLabel");
        value254_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_PlayerSearchResultList");
        value258_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_GroupDetailList");
        value25c_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_ClassesWantedList");
        value260_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_ShowMatchesCheckbox");
        value264_guess = (StatusObject_guess*)((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_ShowAllCheckbox");
        value268_guess = ((CSidlScreenWnd*)value24c_guess)->GetChildItem("GLP_RefreshGroupsButton");
    }
}

struct SlotObject_guess {
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
    virtual void Slot48_guess(int first_guess, int second_guess);
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
    virtual void Slot63_guess(const Str_guess& text_guess);
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
    char pad_0004_guess[0x59];
    char enabled_guess;
};

struct OwnerState_guess {
    char pad_0000_guess[0x238];
    SlotObject_guess* value238_guess;
    SlotObject_guess* value23c_guess;
    char pad_0240_guess[0x10];
    SlotObject_guess* value250_guess;
    SlotObject_guess* value254_guess;
    SlotObject_guess* value258_guess;
    SlotObject_guess* value25c_guess;
    char pad_0260_guess[0x70];
    int value2d0_guess;

    void ClearGroupSearchResults_guess();
    void ClearPlayerSearchResults_guess();
};

// Clears the group search results: empties the result, group detail and classes-wanted lists (virtual
// slot 76), blanks the result count label and zeroes +0x2D0.
// FUNCTION: TITANIUM 0x0050957F
void OwnerState_guess::ClearGroupSearchResults_guess() {
    if (value254_guess != 0) {
        value254_guess->Slot76_guess();
    }
    if (value258_guess != 0) {
        value258_guess->Slot76_guess();
    }
    if (value25c_guess != 0) {
        value25c_guess->Slot76_guess();
    }
    if (value250_guess != 0) {
        Str_guess text_guess(EQ_ARRAY(char, 0x0063F53F));
        value250_guess->Slot63_guess(text_guess);
    }
    value2d0_guess = 0;
}

// Clears the player search results: empties the result list (virtual slot 76) and blanks the result count
// label.
// FUNCTION: TITANIUM 0x00509618
void OwnerState_guess::ClearPlayerSearchResults_guess() {
    if (value23c_guess != 0) {
        value23c_guess->Slot76_guess();
    }
    if (value238_guess != 0) {
        Str_guess text_guess(EQ_ARRAY(char, 0x0063F53F));
        value238_guess->Slot63_guess(text_guess);
    }
}

// Select All on the group page: checks all 16 class boxes (0x005BB140).
// FUNCTION: TITANIUM 0x00509689
void QueueOwner_guess::SelectAllRoles_guess() {
    CButtonWnd** entry = entries_guess;
    int count = 16;
    do {
        if (*entry != 0) {
            (*entry)->SetCheck(1);
        }
        ++entry;
        --count;
    } while (count != 0);
}

// Deselect All on the group page: clears all 16 class boxes (0x005BB140).
// FUNCTION: TITANIUM 0x005096AA
void QueueOwner_guess::DeselectAllRoles_guess() {
    CButtonWnd** entry = entries_guess;
    int count = 16;
    do {
        if (*entry != 0) {
            (*entry)->SetCheck(0);
        }
        ++entry;
        --count;
    } while (count != 0);
}

// Opens the group search window on tab page `value` (tab control +0x15C, 0x005BC3A0) and shows it
// (Show(1, 1)). The group window's LFG button passes 1 when you lead the group, else 0.
// FUNCTION: TITANIUM 0x00508A5A
void Object_guess::Handle_guess(int value) {
    if (subObject_guess != 0) {
        subObject_guess->Apply_guess(value, 0);
    }
    Update_guess(1, 1);
}

// Additional Filters: opens the group search filters window (0x850BD4, slot 33 Activate) when it
// exists. Both pages' event handlers call it.
// FUNCTION: TITANIUM 0x005096CB
void __cdecl Notify_guess() {
    if (pinstCGroupSearchFiltersWnd_guess != 0) {
        pinstCGroupSearchFiltersWnd_guess->Dispatch_guess();
    }
}

// Player page Remove: clears the 0x50-byte player post and sends it empty through pEverQuest
// (0x00496D39, OP_LFGCommand), which also clears your LFG flag.
// FUNCTION: TITANIUM 0x005096DE
void BufferOwner_guess::SendLFGOff_guess() {
    memset(firstBuffer_guess, 0, 0x50);
    firstBuffer_guess[4] = 0;
    g_resourceManager_guess->SendLFGCommand_guess(firstBuffer_guess);
}

// Group page Remove: clears the 0x54-byte group post and sends it empty through pEverQuest (0x00496D76,
// OP_LFPCommand).
// FUNCTION: TITANIUM 0x0050970B
void BufferOwner_guess::SendLFPOff_guess() {
    memset(secondBuffer_guess, 0, 0x54);
    secondBuffer_guess[4] = 0;
    g_resourceManager_guess->SendLFPCommand_guess(secondBuffer_guess);
}

// Whether the filters window (0x850BD4) rejects result row `object`: passes the row and the name of its
// guild (id +0x4C, 0x0040AC55) to the filter test (0x00508955); false without that window. Rejected
// players are left out of the player results and drawn red in group details.
// FUNCTION: TITANIUM 0x00509738
char CGroupSearchWndView_guess::ApplyToRow_guess(TargetObject_guess* object) {
    char result = 0;
    if (pinstCGroupSearchFiltersWnd_guess != 0) {
        int value = g_fixedObject_guess.ReadValue_guess(object->value_guess);
        result = pinstCGroupSearchFiltersWnd_guess->IsFilteredOut_guess(object, value);
    }
    return result;
}

// EXTERNAL: TITANIUM 0x005738B0 FormatText_guess
void __cdecl FormatText_guess(FormatResult_guess* output_guess, const char* format_guess, ...);

// Search button cool-down: shows "<label> (<seconds>)" and keeps both search buttons off until 15 s after the
// last search.
// FUNCTION: TITANIUM 0x00509765
void CGroupSearchWnd_guess::UpdateCountdown_guess(unsigned int now_guess) {
    unsigned int elapsed_guess = (now_guess - lastUpdate_guess) / 1000;
    if (elapsed_guess < 15) {
        remaining_guess = 15 - elapsed_guess;
    } else {
        remaining_guess = 0;
    }
    if (remaining_guess > 0) {
        FormatResult_guess text_guess = { 0 };
        if (firstControl_guess != 0) {
            FormatText_guess(&text_guess, "%s (%d)", (char*)object_0278_guess, remaining_guess);
            firstControl_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&text_guess));
            firstControl_guess->enabled_guess = 0;
        }
        if (secondControl_guess != 0) {
            FormatText_guess(&text_guess, "%s (%d)", (char*)object_e704_guess, remaining_guess);
            secondControl_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&text_guess));
            SlotObject_guess* control_guess = secondControl_guess;
            control_guess->enabled_guess = 0;
        }
    } else {
        if (firstControl_guess != 0) {
            firstControl_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&object_0278_guess));
            firstControl_guess->enabled_guess = 1;
        }
        if (secondControl_guess != 0) {
            secondControl_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&object_e704_guess));
            secondControl_guess->enabled_guess = 1;
        }
    }
}

// Column click on the group result list (+0x254): the same column flips the ascending flag (+0x158), a
// new one becomes the sort column (+0x154) ascending; then the list re-sorts (virtual slot 78).
// FUNCTION: TITANIUM 0x005098A1
void NotificationOwner_guess::UpdateFirst_guess(int value) {
    if (second_guess != 0) {
        int* valuePointer = &second_guess->value_guess;
        if (*valuePointer == value) {
            second_guess->enabled_guess = !second_guess->enabled_guess;
        } else {
            *valuePointer = value;
            second_guess->enabled_guess = 1;
        }
        second_guess->Notify_guess();
    }
}

// Column click on the player result list (+0x23C): the same column flips the ascending flag (+0x158), a
// new one becomes the sort column (+0x154) ascending; then the list re-sorts (virtual slot 78).
// FUNCTION: TITANIUM 0x005098EA
void NotificationOwner_guess::UpdateSecond_guess(int value) {
    if (first_guess != 0) {
        int* valuePointer = &first_guess->value_guess;
        if (*valuePointer == value) {
            first_guess->enabled_guess = !first_guess->enabled_guess;
        } else {
            *valuePointer = value;
            first_guess->enabled_guess = 1;
        }
        first_guess->Notify_guess();
    }
}

struct WindowSlots_guess {
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
    virtual void Slot63_guess(const CXStr& text_guess);
};

struct TargetNotification_guess {
    char pad_0000_guess[0x40];
    char text_guess[0x40];
    int value80_guess;
    int value84_guess;
    int value88_guess;
    int value8c_guess;
    int value90_guess;
};

struct TextBuilder_guess {
    int field00_guess;
    struct TextData_guess {
        char* data_guess;
        // EXTERNAL: TITANIUM 0x004482FB TextBuilder_guess::TextData_guess::~TextData_guess
        ~TextData_guess();
    } data_guess;
    int field08_guess;
    TextBuilder_guess() {
        data_guess.data_guess = 0;
        field08_guess = -1;
        field00_guess = 0;
    }
};

struct TextAggregate_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    unsigned char field0c_guess;
    int field10_guess;
    int field14_guess;
    unsigned char field18_guess;
    unsigned char field19_guess;
    TextAggregate_guess() {
        field04_guess = 0;
        field00_guess = 0;
        field08_guess = 0;
        field0c_guess = 1;
        field10_guess = 0;
        field14_guess = -1;
        field18_guess = 0;
        field19_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0042D7A7 TextAggregate_guess::Append_guess
    void Append_guess(int owner_guess, TextBuilder_guess* text_guess);
    // EXTERNAL: TITANIUM 0x0042D7E5 TextAggregate_guess::~TextAggregate_guess
    ~TextAggregate_guess();
};

struct ZoneNameService_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneNameService_guess::GetName_guess
    void GetName_guess(int id_guess, char* output_guess, int flags_guess);
};

struct ZoneLookupService_guess {
    // EXTERNAL: TITANIUM 0x004922D5 ZoneLookupService_guess::GetName_guess
    const char* GetName_guess(int id_guess);
};

struct NotificationSubmitter_guess {
    char pad_0000_guess[0x11c];
    int value11c_guess;
    // EXTERNAL: TITANIUM 0x0059B800 NotificationSubmitter_guess::Submit_guess
    void Submit_guess(TextAggregate_guess* texts_guess);
};

// EXTERNAL: TITANIUM 0x004657FB CopyTargetText_guess
void __cdecl CopyTargetText_guess(const TargetNotification_guess* source_guess, char* output_guess);
// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* output_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x005738B0 FormatTextBuilder_guess
void __cdecl FormatTextBuilder_guess(TextBuilder_guess::TextData_guess* output_guess,
    const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0046DA4A FormatLocalizedText_guess
void __cdecl FormatLocalizedText_guess(char* output_guess, int stringId_guess, const char* value_guess, ...);

#define g_zoneNameService_guess EQ_GLOBAL(ZoneNameService_guess*, 0x00905CC0)
#define g_zoneLookupService_guess EQ_GLOBAL(ZoneLookupService_guess*, 0x00988DF0)
struct WindowHolder_guess {
    char pad_0000_guess[0x160];
    WindowSlots_guess* window_guess;
};

struct ValueSource_guess {
    // EXTERNAL: TITANIUM 0x005BC390 ValueSource_guess::Get_guess
    int Get_guess();
};

// Group Info page: the class check boxes, comment box (63 characters) and the result list.
// FUNCTION: TITANIUM 0x0050A62A
// @early-stop: budget, structural ndiff=15
void CGroupSearchWndView_guess::InitGroupInfoPage_guess() {
    value_e6fc_guess = 0;
    cachedGroupSize_e700_guess = 0;
    state_e6f9_guess = 1;
    UpdateGroupInfoLabel_guess();

    int low_guess;
    int high_guess;
    GetViewRange_guess(reinterpret_cast<LookupSource_guess*>(pCharData), &low_guess, &high_guess);

    if (value194_guess != 0) {
        FormatResult_guess text_guess = { 0 };
        FormatText_guess(&text_guess, "%d", low_guess);
        value194_guess->value230_guess = 3;
        value194_guess->SetMaxChars_guess(2);
        reinterpret_cast<SlotObject_guess*>(value194_guess)->Slot63_guess(
            *reinterpret_cast<const Str_guess*>(&text_guess));
    }
    if (value198_guess != 0) {
        FormatResult_guess text_guess = { 0 };
        FormatText_guess(&text_guess, "%d", high_guess);
        value198_guess->value230_guess = 3;
        value198_guess->SetMaxChars_guess(2);
        reinterpret_cast<SlotObject_guess*>(value198_guess)->Slot63_guess(
            *reinterpret_cast<const Str_guess*>(&text_guess));
    }
    if (value18c_guess != 0) {
        value18c_guess->value12c_guess = 0x3f;
        value18c_guess->value128_guess = 0x3f;
    }
    if (value248_guess != 0) {
        object_e704_guess = reinterpret_cast<TextSource_guess*>(value248_guess)->GetText_guess();
    }
    reinterpret_cast<QueueOwner_guess*>(this)->SelectAllRoles_guess();
    if (value224_guess != 0) {
        value224_guess->enabled_guess = 1;
    }
    if (value228_guess != 0) {
        value228_guess->enabled_guess = 0;
        value228_guess->Slot48_guess(0, 1);
    }
    if (value22c_guess != 0) {
        value22c_guess->enabled_guess = 0;
    }
    if (value23c_guess != 0) {
        reinterpret_cast<CListWnd*>(value23c_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        reinterpret_cast<SearchListWnd_guess*>(value23c_guess)->color_16c_guess = 0xff8aa3ff;
        reinterpret_cast<SearchListWnd_guess*>(value23c_guess)->field_15c_guess = 1;
        reinterpret_cast<SearchListWnd_guess*>(value23c_guess)->WindowStyle |= 0x40000;
        reinterpret_cast<SearchListWnd_guess*>(value23c_guess)->field_154_guess = 1;
    }
    if (value240_guess != 0) {
        reinterpret_cast<CButtonWnd*>(value240_guess)->SetCheck(1);
    }
}

// Re-reads whichever edited control `value_guess` is (player label or group label).
// FUNCTION: TITANIUM 0x0050A846
int CGroupSearchWndView_guess::UpdateInfoPage_guess(int value_guess) {
    if (value_guess == reinterpret_cast<int>(value160_guess)) {
        UpdatePlayerInfoLabel_guess();
    } else if (value_guess == reinterpret_cast<int>(value184_guess)) {
        UpdateGroupInfoLabel_guess();
    } else if (value_guess == reinterpret_cast<int>(value234_guess)) {
        // nothing to do
    } else if (value_guess == reinterpret_cast<int>(value24c_guess)) {
        // nothing to do
    } else {
        return -1;
    }
    return 0;
}

// Refresh the countdown at most every 400 ticks.
// Every 400 ms while visible: refreshes the labels of both pages and the search cool-down.
// FUNCTION: TITANIUM 0x0050AD34
void CGroupSearchWndView_guess::OnProcessFrame_guess() {
    if (FUN_0059dd30_guess() != 0 && g_timeOwner_guess->now_guess > lastUpdate_e76c_guess + 400) {
        if (value15c_guess != 0) {
            UpdateInfoPage_guess(reinterpret_cast<ValueSource_guess*>(value15c_guess)->Get_guess());
        }
        if (value230_guess != 0) {
            UpdateInfoPage_guess(reinterpret_cast<ValueSource_guess*>(value230_guess)->Get_guess());
        }
        lastUpdate_e76c_guess = g_timeOwner_guess->now_guess;
        reinterpret_cast<CGroupSearchWnd_guess*>(this)->UpdateCountdown_guess(g_timeOwner_guess->now_guess);
    }
    reinterpret_cast<CXWnd*>(this)->OnProcessFrame();
}

// Adds one player search result row: name (+0x40), the number at +0x84, class code (0x004922D5), zone
// (string 0x861 when +0x90 is set) and the comment with bad words starred (0x004657FB). Rows the filter
// window rejects (0x00509738) are skipped unless Show All was on; then the count label (string 0x1A3D).
// FUNCTION: TITANIUM 0x0050ADB2
void CGroupSearchWndView_guess::NotifyObject_guess(TargetNotification_guess* object_guess) {
    if (object_guess == 0) {
        return;
    }
    if (value23c_guess == 0) {
        return;
    }
    if (enabled_e760_guess == 0 &&
        ApplyToRow_guess(reinterpret_cast<TargetObject_guess*>(object_guess->text_guess)) != 0) {
        return;
    }
    char reportBuffer_guess[0x100];
    char zoneBuffer_guess[0x80];
    char targetBuffer_guess[0x40];
    if (object_guess->value90_guess == 0) {
        g_zoneNameService_guess->GetName_guess(object_guess->value88_guess, zoneBuffer_guess, 1);
    } else {
        CopyText_guess(zoneBuffer_guess, pStringTable->getString(0x861, 0));
    }
    CopyTargetText_guess(object_guess, targetBuffer_guess);

    TextAggregate_guess texts_guess;
    TextBuilder_guess firstText_guess;
    TextBuilder_guess secondText_guess;
    TextBuilder_guess thirdText_guess;
    TextBuilder_guess fourthText_guess;
    TextBuilder_guess fifthText_guess;

    FormatTextBuilder_guess(&firstText_guess.data_guess, EQ_ARRAY(char, 0x0063F9FC),
        object_guess->text_guess);
    FormatTextBuilder_guess(&secondText_guess.data_guess, EQ_ARRAY(char, 0x0063F53C),
        object_guess->value84_guess);
    FormatTextBuilder_guess(&thirdText_guess.data_guess, EQ_ARRAY(char, 0x0063F9FC),
        g_zoneLookupService_guess->GetName_guess(object_guess->value80_guess));
    FormatTextBuilder_guess(&fourthText_guess.data_guess, EQ_ARRAY(char, 0x0063F9FC),
        zoneBuffer_guess);
    FormatTextBuilder_guess(&fifthText_guess.data_guess, EQ_ARRAY(char, 0x0063F9FC),
        targetBuffer_guess);
    texts_guess.Append_guess(texts_guess.field00_guess, &firstText_guess);
    texts_guess.Append_guess(texts_guess.field00_guess, &secondText_guess);
    texts_guess.Append_guess(texts_guess.field00_guess, &thirdText_guess);
    texts_guess.Append_guess(texts_guess.field00_guess, &fourthText_guess);
    texts_guess.Append_guess(texts_guess.field00_guess, &fifthText_guess);
    reinterpret_cast<NotificationSubmitter_guess*>(value23c_guess)->Submit_guess(&texts_guess);

    if (value238_guess != 0) {
        int numericValue_guess =
            reinterpret_cast<NotificationSubmitter_guess*>(value23c_guess)->value11c_guess;
        FormatLocalizedText_guess(reportBuffer_guess, 0x1a3d,
            itoa(numericValue_guess, EQ_ARRAY(char, 0x0099DB00), 10),
            0, 0, 0, 0, 0, 0, 0, 0);
        Str_guess message_guess(reportBuffer_guess);
        reinterpret_cast<WindowSlots_guess*>(value238_guess)->Slot63_guess(
            reinterpret_cast<const CXStr&>(message_guess));
    }
}

struct ActiveHolder_guess {
    // EXTERNAL: TITANIUM 0x004F288C ActiveHolder_guess::GetActiveChatWindow_guess
    WindowHolder_guess* GetActiveChatWindow_guess();
};

#define pinstCChatManager_guess EQ_GLOBAL(ActiveHolder_guess*, 0x009917E4)

struct EverQuestOwner_guess {
    // EXTERNAL: TITANIUM 0x00494051 EverQuestOwner_guess::Update_guess
    void Update_guess(int value_guess);
};

struct NameReportOwner_guess {
    void StartTell_guess(const char* name_guess);
};

// Double-clicked player: puts "/tell <name> " (string 13974) in the active chat window and focuses it.
// FUNCTION: TITANIUM 0x00509933
void NameReportOwner_guess::StartTell_guess(const char* name_guess) {
    char buffer_guess[0x100];
    if (pinstCChatManager_guess != 0) {
        WindowHolder_guess* holder_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
        if (holder_guess != 0) {
            sprintf(buffer_guess, "%s %s ", pStringTable->getString(0x3696, 0), name_guess);
            {
                CXStr text_guess(buffer_guess);
                holder_guess->window_guess->Slot63_guess(text_guess);
            }
            reinterpret_cast<CXWnd*>(holder_guess->window_guess)->SetFocus();
            reinterpret_cast<EverQuestOwner_guess*>(pEverQuest)->Update_guess(0);
        }
    }
}

// Number typed in GIP_LevelRangeMinEditbox (+0x194; 0x00571630 parses the text as an integer), 0 without
// the box.
// FUNCTION: TITANIUM 0x005099FB
int CGroupSearchWndView_guess::GetGipLevelMin_guess() {
    int result = 0;
    if (value194_guess != 0) {
        result = value194_guess->Get_guess().GetLength_guess();
    }
    return result;
}

// Number typed in GIP_LevelRangeMaxEditbox (+0x198; 0x00571630 parses the text as an integer), 0 without
// the box.
// FUNCTION: TITANIUM 0x00509A51
int CGroupSearchWndView_guess::GetGipLevelMax_guess() {
    int result = 0;
    if (value198_guess != 0) {
        result = value198_guess->Get_guess().GetLength_guess();
    }
    return result;
}

// Number typed in PIP_LevelRangeMinEditbox (+0x170; 0x00571630 parses the text as an integer), 0 without
// the box.
// FUNCTION: TITANIUM 0x00509AA7
int CGroupSearchWndView_guess::GetPipLevelMin_guess() {
    int result = 0;
    if (value170_guess != 0) {
        result = value170_guess->Get_guess().GetLength_guess();
    }
    return result;
}

// Number typed in PIP_LevelRangeMaxEditbox (+0x174; 0x00571630 parses the text as an integer), 0 without
// the box.
// FUNCTION: TITANIUM 0x00509AFD
int CGroupSearchWndView_guess::GetPipLevelMax_guess() {
    int result = 0;
    if (value174_guess != 0) {
        result = value174_guess->Get_guess().GetLength_guess();
    }
    return result;
}

// Remove My Info: sends an all-zero OP_LFGCommand (0x00496D39, which also clears the player's LFG flag),
// disables Remove and Update and enables Post.
// FUNCTION: TITANIUM 0x00509FD9
void CGroupSearchWndView_guess::RemovePlayerInfo_guess() {
    reinterpret_cast<BufferOwner_guess*>(this)->SendLFGOff_guess();
    Value17cTarget_guess* p180_guess = value180_guess;
    if (p180_guess != 0) {
        p180_guess->enabled_guess = 0;
    }
    Value17cTarget_guess* p17c_guess = value17c_guess;
    if (p17c_guess != 0) {
        p17c_guess->enabled_guess = 0;
        value17c_guess->Slot48_guess(0, 1);
    }
    Value17cTarget_guess* p178_guess = value178_guess;
    if (p178_guess != 0) {
        p178_guess->enabled_guess = 1;
        value178_guess->Slot48_guess(1, 1);
    }
}

// Remove Our Info: sends an all-zero OP_LFPCommand (0x00496D76), disables the group page's Remove and
// Update buttons and enables Post.
// FUNCTION: TITANIUM 0x0050A031
void CGroupSearchWndView_guess::RemoveGroupInfo_guess() {
    reinterpret_cast<BufferOwner_guess*>(this)->SendLFPOff_guess();
    SlotObject_guess* p22c_guess = value22c_guess;
    if (p22c_guess != 0) {
        p22c_guess->enabled_guess = 0;
    }
    SlotObject_guess* p228_guess = value228_guess;
    if (p228_guess != 0) {
        p228_guess->enabled_guess = 0;
        value228_guess->Slot48_guess(0, 1);
    }
    SlotObject_guess* p224_guess = value224_guess;
    if (p224_guess != 0) {
        p224_guess->enabled_guess = 1;
        value224_guess->Slot48_guess(1, 1);
    }
}

// Builds and sends our looking-for-group post (OP_LFGCommand through 0x00496D39): the comment (63
// characters), the player page's level range, LFG on (+0x280) and the filter window's exclusion search box
// (+0x281, 0x00507E5B). 0x0050A1DA compares later edits against this copy.
// FUNCTION: TITANIUM 0x0050A089
void CGroupSearchWndView_guess::SendPlayerInfo_guess() {
    memset(pad_027c_guess, 0, 0x50);
    if (value168_guess != 0) {
        strncpy(text_28c_guess, value168_guess->Get_guess().GetText_guess(), 0x3f);
    }
    length_284_guess = GetPipLevelMin_guess();
    length_288_guess = GetPipLevelMax_guess();
    initialized_280_guess = 1;
    if (pinstCGroupSearchFiltersWnd_guess != 0 &&
        reinterpret_cast<CGroupSearchWndView_guess*>(pinstCGroupSearchFiltersWnd_guess)->IsExclusiveSearch_guess() != 0) {
        enabled_281_guess = 1;
    } else {
        enabled_281_guess = 0;
    }
    g_resourceManager_guess->SendLFGCommand_guess(pad_027c_guess);
}

struct SlotRange_guess {
    char IsValid_guess(int index, int count);
};

struct IndexTableEntry_guess {
    char pad_0000_guess[0x128];
    char enabled_guess;
};

struct IndexTable_guess {
    char pad_0000_guess[0x19c];
    IndexTableEntry_guess* entries_guess[16];

    int GetEnabledBits_guess();

    int ClassIdForCheckBox_guess(int index);
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    void* getString(int id, int zero, int enabled, int duration, int second, int third);
};

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(int first, int type, void* text);
};

#define g_lookupObject_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_messageOwner_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)

// A level range is valid when the maximum is positive, the minimum at most 70 and not above the maximum.
// FUNCTION: TITANIUM 0x00509B53
char SlotRange_guess::IsValid_guess(int index, int count) {
    char result = 0;
    if (count > 0 && index <= 0x46 && index <= count) {
        ++result;
    }
    return result;
}

// Class id for class check box `index`: the 16 boxes run alphabetically (Bard, Beastlord, Berserker,
// Cleric, Druid, Enchanter, Magician, Monk, Necromancer, Paladin, Ranger, Rogue, Shadow Knight, Shaman,
// Warrior, Wizard). 0x0050A337 sets that bit of the class mask; out of range gives 0.
// FUNCTION: TITANIUM 0x00509B6F
int IndexTable_guess::ClassIdForCheckBox_guess(int index) {
    int values[16] = { 8, 15, 16, 2, 6, 14, 13, 7, 11, 3, 4, 9, 5, 10, 1, 12 };
    if (index < 0 || index >= 16) {
        return 0;
    }
    return values[index];
}

// Error popups (15 s): 1 "The level range you specified is invalid..." (6713), 2 "You must select at least
// one class..." (6714), 3 "You are not the group leader, so you cannot post your group." (6715).
// FUNCTION: TITANIUM 0x00509BFB
void CGroupSearchWndView_guess::ShowSearchError_guess(int option) {
    if (option != 0) {
        int id;
        switch (option) {
        case 1:
            id = 0x1a39;
            break;
        case 2:
            id = 0x1a3a;
            break;
        case 3:
            id = 0x1a3b;
            break;
        default:
            return;
        }
        void* text = g_lookupObject_guess->getString(id, 0, 1, 15000, 0, 0);
        g_messageOwner_guess->Activate(0, 0xb, text);
    }
}

// Scalar deleting destructor of the group search window (vtable 0x6551D0 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00509C4B
CGroupSearchWnd_guess* CGroupSearchWnd_guess::Destroy_guess(unsigned char flags_guess) {
    this->CGroupSearchWnd_guess::~CGroupSearchWnd_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Remembers when the last search was sent (for the 15 s cool-down).
// FUNCTION: TITANIUM 0x0050A154
void CGroupSearchWnd_guess::SetUpdateTime_guess(unsigned int now_guess) {
    lastUpdate_guess = now_guess;
    UpdateCountdown_guess(now_guess);
}

struct ActivationState_guess {
    // EXTERNAL: TITANIUM 0x004082C8 ActivationState_guess::GetGroupSize_guess
    int GetGroupSize_guess();
};

#define g_activationState_guess EQ_GLOBAL(ActivationState_guess, 0x00904248)

struct OffsetContainer_guess {
    int unused_guess;
    int vbaseOffset_0004_guess;
};

struct DynamicStringOwner_guess {
    char pad_0000_guess[8];
    OffsetContainer_guess* offsets_guess;
    char pad_000c_guess[0x38];
    char text_guess[1];
};

// EXTERNAL: TITANIUM 0x00574460 CompareText_guess
int __cdecl CompareText_guess(const char* first_guess, const char* second_guess);
// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination, const char* source, int length);

// After a group change: drops our looking-for-group post, and the group's post as well unless we lead
// the group (leader name 0x9043A4) and it is not full (0x004082C8 counts 6).
// FUNCTION: TITANIUM 0x0050A167
void CGroupSearchWndView_guess::RemoveInfoOnGroupChange_guess() {
    if (CompareText_guess(EQ_ARRAY(char, 0x009043A4),
            EQ_GLOBAL(DynamicStringOwner_guess*, 0x00905D00)->text_guess +
            EQ_GLOBAL(DynamicStringOwner_guess*, 0x00905D00)->offsets_guess->vbaseOffset_0004_guess) != 0) {
        RemovePlayerInfo_guess();
    } else {
        RemovePlayerInfo_guess();
        if (g_activationState_guess.GetGroupSize_guess() != 6) {
            return;
        }
    }
    RemoveGroupInfo_guess();
}

// Player page level range check: 1 when the range in PIP_LevelRangeMin/Max (0x00509AA7, 0x00509AFD) is
// invalid (0x00509B53), else 0. Post My Info and Update My Info refuse to send on 1.
// FUNCTION: TITANIUM 0x0050A1B1
int CGroupSearchWndView_guess::CheckRange_guess() {
    int result = 0;
    int first = GetPipLevelMin_guess();
    int second = GetPipLevelMax_guess();
    if (!reinterpret_cast<SlotRange_guess*>(this)->IsValid_guess(first, second)) {
        ++result;
    }
    return result;
}

// Enables Update My Info (+0x17C) only while the comment or level range differs from the last post
// (+0x28C, +0x284, +0x288).
// FUNCTION: TITANIUM 0x0050A1DA
// @early-stop: budget, structural ndiff=28
void CGroupSearchWndView_guess::OnPlayerInfoEdited_guess() {
    char changed_guess = 0;
    if (value168_guess != 0) {
        CXStr text_guess = reinterpret_cast<CXStrProvider_guess*>(value168_guess)->Get_guess();
        if (CompareText_guess(text_28c_guess, (const char*)text_guess) != 0) {
            changed_guess = 1;
        }
    }
    int firstLength_guess = GetPipLevelMin_guess();
    int secondLength_guess = GetPipLevelMax_guess();
    if (length_284_guess != firstLength_guess || length_288_guess != secondLength_guess) {
        changed_guess = 1;
    }
    if (changed_guess != 0) {
        if (value17c_guess == 0) {
            return;
        }
        value17c_guess->enabled_guess = 1;
    } else {
        if (value17c_guess == 0) {
            return;
        }
        value17c_guess->enabled_guess = 0;
    }
    value17c_guess->Slot48_guess(1, 1);
}

struct GetCombatAbilitySpell_guess {
    char pad_0000_guess[0x119c];
    unsigned char class_119c_guess;
    char pad_119d_guess[0x11a4 - 0x119d];
    int level_11a4_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    GetCombatAbilitySpell_guess* GetCharInfo2();
};

struct LookupHolder_guess {
    int field00_guess;
    EQ_CharacterProfileView_guess service_guess;
};

struct LookupOffsetTable_guess {
    int field00_guess;
    int vbaseOffset_0004_guess;
};

struct LookupSource_guess {
    char pad_0000_guess[8];
    LookupOffsetTable_guess* table_guess;
    char pad_000c_guess[0xe0c - 0x0c];
    int value0e0c_guess;
};

#define g_charSource_guess EQ_GLOBAL(LookupSource_guess*, 0x00905D00)

struct EverQuestTextInterface_guess {
    // EXTERNAL: TITANIUM 0x00491E5B EverQuestTextInterface_guess::GetText_guess
    char* GetText_guess(int value_guess);
};

struct TextWindowInterface_guess {
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
    virtual void SetText_guess(const CXStr& text_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
void __cdecl FormatString_guess(char* buffer_guess, int id_guess, ...);

// Player label: "I am a level %1 %2 %3" (6709) from your level, race and class.
// FUNCTION: TITANIUM 0x00509C67
// @early-stop: unknown, diff ndiff=8
void CGroupSearchWndView_guess::UpdatePlayerInfoLabel_guess() {
    char buffer_guess[0x400];
    LookupHolder_guess* holder_guess;
    if (g_charSource_guess != 0 &&
        (value26c_guess != ((holder_guess = reinterpret_cast<LookupHolder_guess*>(
              reinterpret_cast<int>(g_charSource_guess) + 8 +
              g_charSource_guess->table_guess->vbaseOffset_0004_guess)),
          holder_guess->service_guess.GetCharInfo2()->level_11a4_guess) ||
         value270_guess != ((holder_guess = reinterpret_cast<LookupHolder_guess*>(
              reinterpret_cast<int>(g_charSource_guess) + 8 +
              g_charSource_guess->table_guess->vbaseOffset_0004_guess)),
          holder_guess->service_guess.GetCharInfo2()->class_119c_guess) ||
         g_charSource_guess->value0e0c_guess != value274_guess)) {
        holder_guess = reinterpret_cast<LookupHolder_guess*>(
            reinterpret_cast<int>(g_charSource_guess) + 8 +
            g_charSource_guess->table_guess->vbaseOffset_0004_guess);
        value26c_guess = holder_guess->service_guess.GetCharInfo2()->level_11a4_guess;
        holder_guess = reinterpret_cast<LookupHolder_guess*>(
            reinterpret_cast<int>(g_charSource_guess) + 8 +
            g_charSource_guess->table_guess->vbaseOffset_0004_guess);
        value270_guess = holder_guess->service_guess.GetCharInfo2()->class_119c_guess;
        value274_guess = g_charSource_guess->value0e0c_guess;
        if (value164_guess != 0) {
            if (value274_guess != -1) {
                FormatResult_guess formatted_guess = { 0 };
                FormatText_guess(&formatted_guess,
                    EQ_ARRAY(char, 0x00655698),
                    reinterpret_cast<const char*>(g_fixedObject_guess.ReadValue_guess(value274_guess)));
                FormatString_guess(buffer_guess, 0x1a35,
                    _itoa(value26c_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    reinterpret_cast<EverQuestTextInterface_guess*>(pEverQuest)->GetText_guess(value270_guess),
                    static_cast<char*>(reinterpret_cast<CXStr&>(formatted_guess)), 0, 0, 0, 0, 0, 0);
            } else {
                FormatString_guess(buffer_guess, 0x1a35,
                    _itoa(value26c_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    reinterpret_cast<EverQuestTextInterface_guess*>(pEverQuest)->GetText_guess(value270_guess),
                    0, 0, 0, 0, 0, 0, 0);
            }
            CXStr text_guess(buffer_guess);
            reinterpret_cast<TextWindowInterface_guess*>(value164_guess)->SetText_guess(text_guess);
        }
    }
}

// Group page label: string 0x1A37 with your level (+0x11A4) and the group size (0x004082C8), redrawn only
// when one of them changed.
// FUNCTION: TITANIUM 0x00509E93
// @early-stop: budget, diff ndiff=15
void CGroupSearchWndView_guess::UpdateGroupInfoLabel_guess() {
    LookupSource_guess* source_guess = EQ_GLOBAL(LookupSource_guess*, 0x00905D00);
    if (source_guess != 0) {
        int id_guess = g_activationState_guess.GetGroupSize_guess();
        LookupHolder_guess* holder_guess = reinterpret_cast<LookupHolder_guess*>(
            reinterpret_cast<int>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
        if (holder_guess->service_guess.GetCharInfo2()->level_11a4_guess != value_e6fc_guess ||
            cachedGroupSize_e700_guess != id_guess) {
            holder_guess = reinterpret_cast<LookupHolder_guess*>(
                reinterpret_cast<int>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
            value_e6fc_guess = holder_guess->service_guess.GetCharInfo2()->level_11a4_guess;
            cachedGroupSize_e700_guess = id_guess;
            if (value188_guess != 0) {
                char buffer_guess[0x400];
                FormatString_guess(buffer_guess, 0x1a37,
                    _itoa(value_e6fc_guess, EQ_ARRAY(char, 0x0099DB00), 10),
                    _itoa(id_guess, EQ_ARRAY(char, 0x0099DAE0), 10),
                    0, 0, 0, 0, 0, 0, 0);
                Str_guess text_guess(buffer_guess);
                reinterpret_cast<SlotObject_guess*>(value188_guess)->Slot63_guess(text_guess);
            }
        }
    }
}

// EXTERNAL: TITANIUM 0x00576960 ClampLow_guess
void __cdecl ClampLow_guess(int* value_guess, int minimum_guess);
// EXTERNAL: TITANIUM 0x00576980 ClampHigh_guess
void __cdecl ClampHigh_guess(int* value_guess, int maximum_guess);

// Default level range: your level +-5, clamped to 1-70.
// FUNCTION: TITANIUM 0x0050A2AA
void __stdcall GetViewRange_guess(LookupSource_guess* source_guess, int* low_guess, int* high_guess) {
    int high;
    int low;
    low = 1;
    high = 0x46;
    if (source_guess != 0) {
        LookupHolder_guess* holder_guess = reinterpret_cast<LookupHolder_guess*>(
            reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
        low = holder_guess->service_guess.GetCharInfo2()->level_11a4_guess - 5;
        holder_guess = reinterpret_cast<LookupHolder_guess*>(
            reinterpret_cast<char*>(source_guess) + 8 + source_guess->table_guess->vbaseOffset_0004_guess);
        high = holder_guess->service_guess.GetCharInfo2()->level_11a4_guess + 5;
    }
    ClampLow_guess(&low, 1);
    ClampHigh_guess(&high, 0x46);
    if (low_guess != 0) {
        *low_guess = low;
    }
    if (high_guess != 0) {
        *high_guess = high;
    }
}

// Class bits of the checked class boxes: box i (alphabetical: Brd, Bst, Ber, ...) maps to its class id
// through 0x00509B6F's table and sets that bit.
// FUNCTION: TITANIUM 0x0050A337
int IndexTable_guess::GetEnabledBits_guess() {
    int result = 0;
    for (int i = 0; i < 16; ++i) {
        IndexTableEntry_guess* entry_guess = entries_guess[i];
        if (entry_guess != 0 && entry_guess->enabled_guess != 0) {
            int bit_guess = ClassIdForCheckBox_guess(i);
            reinterpret_cast<unsigned char*>(&result)[bit_guess >> 3] |= (unsigned char)(1 << (bit_guess & 7));
        }
    }
    return result;
}

// Player Info page: comment box (63 characters), level range boxes, the result list and its colours.
// FUNCTION: TITANIUM 0x0050A387
void CGroupSearchWndView_guess::InitPlayerInfoPage_guess() {
    value26c_guess = 0;
    value270_guess = 0;
    value274_guess = -1;
    UpdatePlayerInfoLabel_guess();
    int high_guess;
    int low_guess;
    GetViewRange_guess(EQ_GLOBAL(LookupSource_guess*, 0x00905D00), &low_guess, &high_guess);
    if (value170_guess != 0) {
        FormatResult_guess text_guess = { 0 };
        FormatText_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C), low_guess);
        value170_guess->value230_guess = 3;
        value170_guess->SetMaxChars_guess(2);
        value170_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&text_guess));
    }
    if (value174_guess != 0) {
        FormatResult_guess text_guess = { 0 };
        FormatText_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C), high_guess);
        value174_guess->value230_guess = 3;
        value174_guess->SetMaxChars_guess(2);
        value174_guess->Slot63_guess(*reinterpret_cast<const Str_guess*>(&text_guess));
    }
    StringProvider_guess* provider_guess = value168_guess;
    if (provider_guess != 0) {
        provider_guess->value12c_guess = 0x3f;
        provider_guess->value128_guess = 0x3f;
    }
    if (value268_guess != 0) {
        value278_guess.Assign_guess(reinterpret_cast<TextSource_guess*>(value268_guess)->FUN_004d22d7_guess());
    }
    if (value178_guess != 0) {
        value178_guess->enabled_guess = 1;
    }
    if (value17c_guess != 0) {
        value17c_guess->enabled_guess = 0;
        value17c_guess->Slot48_guess(0, 1);
    }
    if (value180_guess != 0) {
        value180_guess->enabled_guess = 0;
    }
    if (value254_guess != 0) {
        reinterpret_cast<ListWnd_guess*>(value254_guess)->SetColors(-1, 0xffffff00, 0xff808080);
        reinterpret_cast<ListWnd_guess*>(value254_guess)->value16c_guess = 0xff8aa3ff;
        reinterpret_cast<ListWnd_guess*>(value254_guess)->value15c_guess = 1;
        reinterpret_cast<WindowFlags66_guess*>(value254_guess)->value66_guess |= 4;
        reinterpret_cast<ListWnd_guess*>(value254_guess)->value154_guess = 1;
        value2d0_guess = 0;
    }
    if (value258_guess != 0) {
        reinterpret_cast<ListWnd_guess*>(value258_guess)->SetColors(-1, 0xffffff00, 0xff808080);
        reinterpret_cast<ListWnd_guess*>(value258_guess)->value16c_guess = 0xff8aa3ff;
        reinterpret_cast<ListWnd_guess*>(value258_guess)->value15c_guess = 1;
        value258_guess->WindowStyle &= 0xfffffffe;
    }
    if (value25c_guess != 0) {
        reinterpret_cast<ListWnd_guess*>(value25c_guess)->SetColors(-1, 0xffffff00, 0xff808080);
        value25c_guess->WindowStyle &= 0xffdefffe;
    }
    if (value260_guess != 0) {
        reinterpret_cast<CButtonWnd*>(value260_guess)->SetCheck(1);
    }
    bits_e6f4_guess = 0;
    for (int i = 0; i < 16; ++i) {
        int bit_guess = reinterpret_cast<IndexTable_guess*>(this)->ClassIdForCheckBox_guess(i);
        reinterpret_cast<unsigned char*>(&bits_e6f4_guess)[bit_guess >> 3] |= (unsigned char)(1 << (bit_guess & 7));
    }
}

// Post My Info: with a valid level range (0x0050A1B1) sends the post (0x0050A089), disables Post and
// Update and enables Remove; else shows the error popup (0x00509BFB).
// FUNCTION: TITANIUM 0x0050A882
void CGroupSearchWndView_guess::PostPlayerInfo_guess() {
    int result_guess = CheckRange_guess();
    if (result_guess == 0) {
        SendPlayerInfo_guess();
        Value17cTarget_guess*& firstTarget_guess = value178_guess;
        if (firstTarget_guess != 0) {
            firstTarget_guess->enabled_guess = 0;
            firstTarget_guess->Slot48_guess(0, 1);
        }
        Value17cTarget_guess*& secondTarget_guess = value17c_guess;
        if (secondTarget_guess != 0) {
            secondTarget_guess->enabled_guess = 0;
            secondTarget_guess->Slot48_guess(1, 1);
        }
        Value17cTarget_guess* thirdTarget_guess = value180_guess;
        if (thirdTarget_guess != 0) {
            thirdTarget_guess->enabled_guess = 1;
        }
        return;
    }
    ShowSearchError_guess(result_guess);
}

// Update My Info: with a valid level range (0x0050A1B1) re-sends the post (0x0050A089) and disables Update
// (+0x17C); else shows the error popup (0x00509BFB).
// FUNCTION: TITANIUM 0x0050A8ED
void CGroupSearchWndView_guess::UpdatePlayerInfo_guess() {
    int result_guess = CheckRange_guess();
    if (result_guess == 0) {
        SendPlayerInfo_guess();
        if (value17c_guess != 0) {
            value17c_guess->enabled_guess = 0;
        }
    } else {
        ShowSearchError_guess(result_guess);
    }
}

// Group search (the group-list refresh): sends OP_LFPGetMatchesRequest {0, min, max} with the level range
// typed on the Player Info page (+0x170/+0x174), or 1-100 when its any-level box (+0x264) is checked (kept
// at +0xE6F8). An invalid range shows error 1; the send time starts the search cool-down.
// FUNCTION: TITANIUM 0x0050A918
void CGroupSearchWndView_guess::SearchGroups_guess() {
    int first_guess;
    int second_guess;
    if (value264_guess == 0 || value264_guess->enabled_guess == 0) {
        first_guess = GetPipLevelMin_guess();
        second_guess = GetPipLevelMax_guess();
        enabled_e6f8_guess = 0;
    } else {
        first_guess = 1;
        second_guess = 100;
        enabled_e6f8_guess = 1;
    }
    if (reinterpret_cast<SlotRange_guess*>(this)->IsValid_guess(first_guess, second_guess)) {
        int values_guess[3];
        memset(values_guess, 0, 0xc);
        values_guess[1] = first_guess;
        values_guess[2] = second_guess;
        g_resourceManager_guess->SendLFPGetMatchesRequest_guess(values_guess);
        reinterpret_cast<CGroupSearchWnd_guess*>(this)->SetUpdateTime_guess(g_timeOwner_guess->now_guess);
    } else {
        ShowSearchError_guess(1);
    }
}

// Player search: OP_LFGGetMatchesRequest {0, min, max, class bits} with the group page's level range and
// class boxes, or 1-100 and every class with Show All checked (kept at +0xE760). Error 1 for a bad range,
// 2 for no class; the send time starts the search cool-down.
// FUNCTION: TITANIUM 0x0050A9B2
void CGroupSearchWndView_guess::RefreshPlayerList_guess() {
    int first_guess;
    int second_guess;
    int enabledBits_guess;
    if (value244_guess == 0 || value244_guess->enabled_guess == 0) {
        first_guess = GetGipLevelMin_guess();
        second_guess = GetGipLevelMax_guess();
        enabledBits_guess = reinterpret_cast<IndexTable_guess*>(this)->GetEnabledBits_guess();
        enabled_e760_guess = 0;
    } else {
        first_guess = 1;
        second_guess = 100;
        enabledBits_guess = -1;
        enabled_e760_guess = 1;
    }
    if (reinterpret_cast<SlotRange_guess*>(this)->IsValid_guess(first_guess, second_guess)) {
        if (enabledBits_guess != 0) {
            int values_guess[4];
            memset(values_guess, 0, 0x10);
            values_guess[1] = first_guess;
            values_guess[2] = second_guess;
            values_guess[3] = enabledBits_guess;
            g_resourceManager_guess->SendLFGGetMatchesRequest_guess(values_guess);
            reinterpret_cast<CGroupSearchWnd_guess*>(this)->SetUpdateTime_guess(g_timeOwner_guess->now_guess);
            return;
        }
        ShowSearchError_guess(2);
    } else {
        ShowSearchError_guess(1);
    }
}

// Builds and sends the group's looking-for-players post (OP_LFPCommand through 0x00496D76): comment, the
// group page's level range and class bits, LFP on (+0xE70C) and the exclusion search flag (+0xE70D).
// 0x0050AB7D compares later edits against this copy.
// FUNCTION: TITANIUM 0x0050AA6A
void CGroupSearchWndView_guess::SendGroupInfo_guess() {
    int zero_guess = 0;
    StringProvider_guess* nullProvider_guess = 0;
    CGroupSearchWndView_guess* nullObject_guess = 0;
    memset(state_e708_guess, zero_guess, 0x54);
    if (value18c_guess != nullProvider_guess) {
        strncpy(text_e71c_guess, value18c_guess->Get_guess().GetText_guess(), 0x3f);
    }
    length194_e710_guess = GetGipLevelMin_guess();
    length198_e714_guess = GetGipLevelMax_guess();
    enabledBits_e718_guess = reinterpret_cast<IndexTable_guess*>(this)->GetEnabledBits_guess();
    initialized_e70c_guess = 1;
    if (reinterpret_cast<CGroupSearchWndView_guess*>(pinstCGroupSearchFiltersWnd_guess) != nullObject_guess &&
        reinterpret_cast<CGroupSearchWndView_guess*>(pinstCGroupSearchFiltersWnd_guess)->IsExclusiveSearch_guess()) {
        enabled_e70d_guess = 1;
    } else {
        enabled_e70d_guess = zero_guess;
    }
    g_resourceManager_guess->SendLFPCommand_guess(state_e708_guess);
}

// Checks the group page before a post: 1 for an invalid level range, 2 when no class box is checked,
// else 0.
// FUNCTION: TITANIUM 0x0050AB42
int CGroupSearchWndView_guess::CheckSlots_guess() {
    int result = 0;
    int first = GetGipLevelMin_guess();
    int second = GetGipLevelMax_guess();
    if (reinterpret_cast<SlotRange_guess*>(this)->IsValid_guess(first, second)) {
        if (reinterpret_cast<IndexTable_guess*>(this)->GetEnabledBits_guess() == 0) {
            result = 2;
        }
    } else {
        result = 1;
    }
    return result;
}

// Enables Update Our Info (+0x228) only while the group comment, level range or class boxes differ from
// the last post.
// FUNCTION: TITANIUM 0x0050AB7D
// @early-stop: budget, structural ndiff=14
void CGroupSearchWndView_guess::OnGroupInfoEdited_guess() {
    char changed_guess = 0;
    if (value18c_guess != 0) {
        char textChanged_guess = CompareText_guess(
            text_e71c_guess, value18c_guess->Get_guess().GetText_guess()) != 0;
        if (textChanged_guess != 0) {
            changed_guess = 1;
        }
    }
    int length194_guess = GetGipLevelMin_guess();
    int length198_guess = GetGipLevelMax_guess();
    if (length194_e710_guess != length194_guess || length198_e714_guess != length198_guess) {
        changed_guess = 1;
    }
    if (enabledBits_e718_guess != reinterpret_cast<IndexTable_guess*>(this)->GetEnabledBits_guess()) {
        changed_guess = 1;
    }
    SlotObject_guess** controlAddress_guess = &value228_guess;
    SlotObject_guess* control_guess = *controlAddress_guess;
    if (changed_guess != 0) {
        if (control_guess == 0) {
            return;
        }
        control_guess->enabled_guess = 1;
    } else {
        if (control_guess == 0) {
            return;
        }
        control_guess->enabled_guess = 0;
    }
    (*controlAddress_guess)->Slot48_guess(1, 1);
}

// Style 0x800 is added to the SIDL style.
// FUNCTION: TITANIUM 0x0050AC61
CGroupSearchWnd_guess::CGroupSearchWnd_guess(CXWnd* parent) : BaseObject_guess(parent, "GroupSearchWnd", -1, 1, 0) {
    reinterpret_cast<CGroupSearchWndView_guess*>(this)->Init_guess();
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        reinterpret_cast<CGroupSearchWndView_guess*>(this)->InitializeControls_guess();
        reinterpret_cast<CGroupSearchWndView_guess*>(this)->InitPlayerInfoPage_guess();
        reinterpret_cast<CGroupSearchWndView_guess*>(this)->InitGroupInfoPage_guess();
        lastUpdate_guess = 0;
        remaining_guess = 0;
        reinterpret_cast<CGroupSearchWndView_guess*>(this)->lastUpdate_e76c_guess = g_timeOwner_guess->now_guess;
    }
}

// Player list page events: OnProcessFrame_guess runs the search (0x0050A9B2); on the result list a column
// click (0xF)
// sets or flips the sort (0x005098EA), message 4 starts a /tell to the row's player (0x00509933) and sort
// compares (0x10) of column 1 compare numbers (0x0055446C).
// FUNCTION: TITANIUM 0x0050B175
int CGroupSearchWndView_guess::HandleTarget_guess(void* event_guess, int arg2_guess, int arg3_guess) {
    int result_guess = 0;
    if (event_guess != 0) {
        if (event_guess == value248_guess && arg2_guess == 1) {
            RefreshPlayerList_guess();
        } else if (event_guess == value23c_guess && arg2_guess == 0xf) {
            reinterpret_cast<NotificationOwner_guess*>(this)->UpdateSecond_guess(arg3_guess);
        } else if (event_guess == value23c_guess && arg2_guess == 4) {
            reinterpret_cast<NameReportOwner_guess*>(this)->StartTell_guess(
                reinterpret_cast<CListWnd*>(value23c_guess)->GetItemText(arg3_guess, 0));
        } else if (event_guess == value23c_guess && arg2_guess == 0x10) {
            int* data_guess = reinterpret_cast<int*>(arg3_guess);
            if (*data_guess == 1) {
                CompareNumericCells_guess(data_guess);
            }
        } else {
            result_guess = -1;
        }
    }
    return result_guess;
}

// Player page events: Post, Update and Remove clicks, edits (0xE) of the comment and level boxes, and
// Additional Filters (0x005096CB); returns -1 when the sender is none of them.
// FUNCTION: TITANIUM 0x0050B0DB
int CGroupSearchWndView_guess::HandlePlayerInfoPage_guess(void* event_guess, int arg2_guess, int arg3_guess) {
    int result_guess = 0;
    if (event_guess != 0) {
        if (event_guess == value178_guess && arg2_guess == 1) {
            PostPlayerInfo_guess();
        } else if (event_guess == value17c_guess && arg2_guess == 1) {
            UpdatePlayerInfo_guess();
        } else if (event_guess == value180_guess && arg2_guess == 1) {
            RemovePlayerInfo_guess();
        } else if (event_guess == value168_guess && arg2_guess == 0xe) {
            OnPlayerInfoEdited_guess();
        } else if (event_guess == value170_guess && arg2_guess == 0xe) {
            OnPlayerInfoEdited_guess();
        } else if (event_guess == value174_guess && arg2_guess == 0xe) {
            OnPlayerInfoEdited_guess();
        } else if (event_guess == value16c_guess && arg2_guess == 1) {
            Notify_guess();
        } else {
            result_guess = -1;
        }
    }
    return result_guess;
}

// Fills the group detail list with a group result's members: name, class code (0x004922D5) and the number
// at +0x44; members the filter window rejects (0x00509738) are drawn red.
// FUNCTION: TITANIUM 0x0050B2FD
// @early-stop: budget, structural ndiff=69
int CGroupSearchWndView_guess::FillGroupDetailList_guess(SlotEntry_guess* entry_guess) {
    int result_guess = reinterpret_cast<NotificationObject_guess*>(value258_guess)->Slot76_guess();
    int index_guess = 0;
    if (index_guess < entry_guess->count_guess) {
        TargetObject_guess* row_guess = entry_guess->rows_guess;
        do {
            TextAggregate_guess texts_guess;
            TextBuilder_guess firstText_guess;
            TextBuilder_guess secondText_guess;
            TextBuilder_guess thirdText_guess;
            FormatTextBuilder_guess(&firstText_guess.data_guess,
                EQ_ARRAY(char, 0x0063F9FC), row_guess);
            char* translated_guess = g_resourceManager_guess->GetClassThreeLetterCode(
                row_guess->value40_guess);
            FormatTextBuilder_guess(&secondText_guess.data_guess,
                EQ_ARRAY(char, 0x0063F9FC), translated_guess);
            FormatTextBuilder_guess(&thirdText_guess.data_guess,
                EQ_ARRAY(char, 0x0063F53C), row_guess->value44_guess);
            texts_guess.Append_guess(texts_guess.field00_guess, &firstText_guess);
            texts_guess.Append_guess(texts_guess.field00_guess, &secondText_guess);
            texts_guess.Append_guess(texts_guess.field00_guess, &thirdText_guess);
            if (ApplyToRow_guess(row_guess)) {
                firstText_guess.field08_guess = 0xffff0000;
                secondText_guess.field08_guess = 0xffff0000;
                thirdText_guess.field08_guess = 0xffff0000;
            } else {
                firstText_guess.field08_guess = -1;
                secondText_guess.field08_guess = -1;
                thirdText_guess.field08_guess = -1;
            }
            reinterpret_cast<NotificationSubmitter_guess*>(value258_guess)->Submit_guess(
                &texts_guess);
            ++index_guess;
            ++row_guess;
        } while (index_guess < entry_guess->count_guess);
        result_guess = reinterpret_cast<int>(entry_guess);
    }
    return result_guess;
}

// Group details: "Looking for classes: " (6710) with the wanted classes, or "ANY" (6718).
// FUNCTION: TITANIUM 0x0050B46C
void CGroupSearchWndView_guess::ShowGroupDetails_guess(int value_guess) {
    char name_guess[0x40];
    if (value254_guess != 0 && value258_guess != 0) {
        steve_strncpy_guess(name_guess, reinterpret_cast<CListWnd*>(value254_guess)->GetItemText(value_guess, 0), 0x40);
        for (int index_guess = 0; index_guess < value2d0_guess; ++index_guess) {
            if (CompareText_guess(entries_02d4_guess[index_guess].name_guess, name_guess) == 0) {
                SlotEntry_guess* entry_guess = &entries_02d4_guess[index_guess];
                if (entry_guess != 0) {
                    FillGroupDetailList_guess(entry_guess);
                    if (value25c_guess != 0) {
                        CXStr text_guess(pStringTable->getString(0x1a36, 0));
                        if (entry_guess->bits48_guess == bits_e6f4_guess) {
                            text_guess += EQ_ARRAY(char, 0x0063FE10);
                            text_guess += pStringTable->getString(0x1a3e, 0);
                        } else {
                            for (int bit_guess = 0; bit_guess < 16; ++bit_guess) {
                                int mapped_guess = reinterpret_cast<IndexTable_guess*>(this)->ClassIdForCheckBox_guess(bit_guess);
                                if (((entry_guess->bitBytes48_guess[mapped_guess >> 3]) >> (mapped_guess & 7)) & 1) {
                                    text_guess += EQ_ARRAY(char, 0x0063FE10);
                                    text_guess += g_resourceManager_guess->GetClassThreeLetterCode(mapped_guess);
                                }
                            }
                        }
                        reinterpret_cast<NotificationObject_guess*>(value25c_guess)->Slot76_guess();
                        reinterpret_cast<CListWnd*>(value25c_guess)->AddString(text_guess, -1, 0, 0);
                    }
                }
                break;
            }
        }
    }
}

// Post Our Info: only solo or as group leader (else error 3); with a valid range and at least one class
// sends the post (0x0050AA6A), disables Post and Update and enables Remove.
// FUNCTION: TITANIUM 0x0050B230
void CGroupSearchWndView_guess::PostGroupInfo_guess() {
    int result_guess;
    if (g_activationState_guess.GetGroupSize_guess() == 1 ||
        CompareText_guess(EQ_ARRAY(char, 0x009043A4),
            EQ_GLOBAL(DynamicStringOwner_guess*, 0x00905D00)->text_guess +
            EQ_GLOBAL(DynamicStringOwner_guess*, 0x00905D00)->offsets_guess->vbaseOffset_0004_guess) == 0) {
        result_guess = CheckSlots_guess();
        if (result_guess == 0) {
            SendGroupInfo_guess();
            SlotObject_guess** firstControlAddress_guess = &value224_guess;
            if (*firstControlAddress_guess != 0) {
                (*firstControlAddress_guess)->enabled_guess = 0;
                (*firstControlAddress_guess)->Slot48_guess(0, 1);
            }
            SlotObject_guess** secondControlAddress_guess = &value228_guess;
            if (*secondControlAddress_guess != 0) {
                (*secondControlAddress_guess)->enabled_guess = 0;
                (*secondControlAddress_guess)->Slot48_guess(1, 1);
            }
            if (value22c_guess == 0) {
                return;
            }
            value22c_guess->enabled_guess = 1;
            return;
        }
        ShowSearchError_guess(result_guess);
    } else {
        ShowSearchError_guess(3);
    }
}


// Update Our Info: with a valid level range and at least one class (0x0050AB42) re-sends the group's post
// (0x0050AA6A) and disables Update (+0x228); else shows the error popup. Unlike Post (0x0050B230) it does
// not re-check that the player leads the group.
// FUNCTION: TITANIUM 0x0050B2D2
void CGroupSearchWndView_guess::UpdateGroupInfo_guess() {
    int result_guess = CheckSlots_guess();
    if (result_guess == 0) {
        SendGroupInfo_guess();
        if (value228_guess != 0) {
            value228_guess->enabled_guess = 0;
        }
    } else {
        ShowSearchError_guess(result_guess);
    }
}

struct FormattedText_guess {
    char* data_guess;
    // EXTERNAL: TITANIUM 0x004482FB FormattedText_guess::~FormattedText_guess
    ~FormattedText_guess();
};

struct FieldDescriptor_guess {
    int kind_guess;
    FormattedText_guess text_guess;
    int flags_guess;
};

struct RequestFlag_guess {
    char enabled_guess;
    // EXTERNAL: TITANIUM 0x004482FB RequestFlag_guess::~RequestFlag_guess
    ~RequestFlag_guess();
};

struct RequestData_guess {
    FormattedText_guess text_guess;
    int first_guess;
    int second_guess;
    RequestFlag_guess flag_guess;
    char pad_000d_guess[3];
    int third_guess;
    int fourth_guess;
    char flag18_guess;
    char flag19_guess;
    char pad_001a_guess[2];

    // EXTERNAL: TITANIUM 0x0042D7A7 RequestData_guess::AddField_guess
    void AddField_guess(char* key_guess, FieldDescriptor_guess* field_guess);
    // EXTERNAL: TITANIUM 0x0042D7E5 RequestData_guess::~RequestData_guess
    ~RequestData_guess();
};

struct RequestConsumer_guess {
    char pad_0000_guess[0x11c];
    int value11c_guess;
    // EXTERNAL: TITANIUM 0x0059B800 RequestConsumer_guess::Submit_guess
    void Submit_guess(RequestData_guess* data_guess);
};

// EXTERNAL: TITANIUM 0x004657FB BuildItemInfo_guess
void __cdecl BuildItemInfo_guess(ItemEntry_guess* entry_guess, char* output_guess);

#define g_zoneNameProvider_guess g_zoneNameService_guess

// Fills the player results; "Your search has returned %1 result(s). Double-click a player to start a /tell."
// (6717).
// FUNCTION: TITANIUM 0x0050B634
// @early-stop: budget, structural ndiff=48
void CGroupSearchWndView_guess::ProcessEntry_guess(ItemEntry_guess* entry_guess) {
    if (entry_guess != 0 && value254_guess != 0) {
        if (enabled_e6f8_guess == 0 && ApplyToRow_guess(&entry_guess->check_guess) != 0) {
            return;
        }

        char details_guess[0x40];
        char zoneName_guess[0x80];
        char localizedText_guess[0x100];
        RequestData_guess request_guess;
        g_zoneNameProvider_guess->GetName_guess(entry_guess->values_guess.value98_guess,
            zoneName_guess, 1);
        BuildItemInfo_guess(entry_guess, details_guess);

        request_guess.text_guess.data_guess = 0;
        request_guess.first_guess = 0;
        request_guess.second_guess = 0;
        request_guess.flag_guess.enabled_guess = 1;
        request_guess.third_guess = 0;
        request_guess.fourth_guess = -1;
        request_guess.flag18_guess = 0;
        request_guess.flag19_guess = 1;

        FieldDescriptor_guess firstField_guess;
        firstField_guess.kind_guess = 0;
        firstField_guess.text_guess.data_guess = 0;
        firstField_guess.flags_guess = -1;

        FieldDescriptor_guess secondField_guess;
        secondField_guess.kind_guess = 0;
        secondField_guess.text_guess.data_guess = 0;
        secondField_guess.flags_guess = -1;

        FieldDescriptor_guess thirdField_guess;
        thirdField_guess.kind_guess = 0;
        thirdField_guess.text_guess.data_guess = 0;
        thirdField_guess.flags_guess = -1;

        FieldDescriptor_guess fourthField_guess;
        fourthField_guess.kind_guess = 0;
        fourthField_guess.text_guess.data_guess = 0;
        fourthField_guess.flags_guess = -1;

        FieldDescriptor_guess fifthField_guess;
        fifthField_guess.kind_guess = 0;
        fifthField_guess.text_guess.data_guess = 0;
        fifthField_guess.flags_guess = -1;

        FormatText_guess(reinterpret_cast<FormatResult_guess*>(&firstField_guess.text_guess), EQ_ARRAY(char, 0x0063F9FC),
            &entry_guess->check_guess);
        FormatText_guess(reinterpret_cast<FormatResult_guess*>(&secondField_guess.text_guess), EQ_ARRAY(char, 0x0063F53C),
            entry_guess->value4c_guess);
        FormatText_guess(reinterpret_cast<FormatResult_guess*>(&thirdField_guess.text_guess), EQ_ARRAY(char, 0x0063F53C),
            entry_guess->values_guess.value94_guess);
        FormatText_guess(reinterpret_cast<FormatResult_guess*>(&fourthField_guess.text_guess), EQ_ARRAY(char, 0x0063F9FC), zoneName_guess);
        FormatText_guess(reinterpret_cast<FormatResult_guess*>(&fifthField_guess.text_guess), EQ_ARRAY(char, 0x0063F9FC), details_guess);

        request_guess.AddField_guess(request_guess.text_guess.data_guess, &firstField_guess);
        request_guess.AddField_guess(request_guess.text_guess.data_guess, &secondField_guess);
        request_guess.AddField_guess(request_guess.text_guess.data_guess, &thirdField_guess);
        request_guess.AddField_guess(request_guess.text_guess.data_guess, &fourthField_guess);
        request_guess.AddField_guess(request_guess.text_guess.data_guess, &fifthField_guess);
        reinterpret_cast<RequestConsumer_guess*>(value254_guess)->Submit_guess(&request_guess);

        itemEntries_2d4_guess[itemCount_2d0_guess] = *entry_guess;
        ++itemCount_2d0_guess;

        if (value250_guess != 0) {
            FormatLocalizedText_guess(localizedText_guess, 0x1A3D,
                _itoa(reinterpret_cast<RequestConsumer_guess*>(value254_guess)->value11c_guess,
                    EQ_ARRAY(char, 0x0099DB00), 10),
                0, 0, 0, 0, 0, 0, 0, 0);
            Str_guess text_guess(localizedText_guess);
            reinterpret_cast<SlotObject_guess*>(value250_guess)->Slot63_guess(text_guess);
        }
    }
}

// Group page events: Post, Update and Remove, edits of the comment and level boxes, Additional Filters,
// the class boxes, and Select All / Deselect All (0x00509689, 0x005096AA); each change re-checks Update.
// FUNCTION: TITANIUM 0x0050B94D
int CGroupSearchWndView_guess::HandleGroupInfoPage_guess(void* event_guess, int arg2_guess, int arg3_guess) {
    int result_guess = 0;
    if (event_guess != 0) {
        if (event_guess == value224_guess && arg2_guess == 1) {
            PostGroupInfo_guess();
        } else if (event_guess == value228_guess && arg2_guess == 1) {
            UpdateGroupInfo_guess();
        } else if (event_guess == value22c_guess && arg2_guess == 1) {
            RemoveGroupInfo_guess();
        }
    }
    if (event_guess == value18c_guess && arg2_guess == 0xe) {
        OnGroupInfoEdited_guess();
    } else if (event_guess == value194_guess && arg2_guess == 0xe) {
        OnGroupInfoEdited_guess();
    } else if (event_guess == value198_guess && arg2_guess == 0xe) {
        OnGroupInfoEdited_guess();
    } else if (event_guess == value190_guess && arg2_guess == 1) {
        FUN_005096cb_guess();
    // Box 2 (Ber, the Berserker box) is missing from this list, so it never re-enables Update.
    } else if ((event_guess == list19c_guess[0] || event_guess == list19c_guess[1] ||
            event_guess == list19c_guess[3] || event_guess == list19c_guess[4] ||
            event_guess == list19c_guess[5] || event_guess == list19c_guess[6] ||
            event_guess == list19c_guess[7] || event_guess == list19c_guess[8] ||
            event_guess == list19c_guess[9] || event_guess == list19c_guess[10] ||
            event_guess == list19c_guess[11] || event_guess == list19c_guess[12] ||
            event_guess == list19c_guess[13] || event_guess == list19c_guess[14] ||
            event_guess == list19c_guess[15]) && arg2_guess == 1) {
        OnGroupInfoEdited_guess();
    } else if (event_guess == value21c_guess && arg2_guess == 1) {
        reinterpret_cast<QueueOwner_guess*>(this)->SelectAllRoles_guess();
        OnGroupInfoEdited_guess();
    } else if (event_guess == value220_guess && arg2_guess == 1) {
        reinterpret_cast<QueueOwner_guess*>(this)->DeselectAllRoles_guess();
        OnGroupInfoEdited_guess();
    } else {
        result_guess = -1;
    }
    return result_guess;
}

// Group list page events: a click on Refresh Groups (+0x268) runs the group search (0x0050A918), a row
// click shows that group (0x0050B46C), a column click sorts (0x005098A1), message 4 starts a /tell, and
// sort compares (0x10) of columns 1 and 2 compare numbers (0x0055446C).
// FUNCTION: TITANIUM 0x0050BAAF
int CGroupSearchWndView_guess::HandleEvent_guess(void* event_guess, int arg2_guess, int arg3_guess) {
    int result_guess = 0;
    if (event_guess != 0) {
        if (event_guess == value268_guess && arg2_guess == 1) {
            SearchGroups_guess();
        } else if (event_guess == value254_guess && arg2_guess == 1) {
            ShowGroupDetails_guess(arg3_guess);
        } else if (event_guess == value254_guess && arg2_guess == 0xf) {
            reinterpret_cast<NotificationOwner_guess*>(this)->UpdateFirst_guess(arg3_guess);
        } else if (event_guess == value254_guess && arg2_guess == 4) {
            reinterpret_cast<NameReportOwner_guess*>(this)->StartTell_guess(
                reinterpret_cast<CListWnd*>(value254_guess)->GetItemText(arg3_guess, 0));
        } else if (event_guess == value258_guess && arg2_guess == 4) {
            reinterpret_cast<NameReportOwner_guess*>(this)->StartTell_guess(
                reinterpret_cast<CListWnd*>(value258_guess)->GetItemText(arg3_guess, 0));
        } else if (event_guess == value254_guess && arg2_guess == 0x10) {
            int* data_guess = reinterpret_cast<int*>(arg3_guess);
            if (*data_guess == 1 || *data_guess == 2) {
                CompareNumericCells_guess(data_guess);
            }
        } else {
            result_guess = -1;
        }
    }
    return result_guess;
}
