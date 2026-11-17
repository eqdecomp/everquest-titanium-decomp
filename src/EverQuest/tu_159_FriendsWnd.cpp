// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 159: a hint from compare/tumap.py.
// Two windows. CFriendsWnd (screen "FriendsWindow"): the friend and ignore lists. CGaugeWnd
// (GaugeWnd.cpp in the draw failure log, vtable 0x00654880): one HP/mana/exp-style bar.
// From 0x005046A2 on, CFriendsWnd_guess (misnamed) is a view of CGaugeWnd_guess: those are the gauge's
// methods. Friend and ignore names: 100 records of 64 bytes each from 0x0095A1B4.
#include "titanium/types.h"
#include "titanium/crt.h"
#include <windows.h>
#include "titanium/wnd/CTipWnd.h"

struct CFriendsWnd_guess;

struct GaugeTemp_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    // EXTERNAL: TITANIUM 0x004EA5BF GaugeTemp_guess::IsValid_guess
    char IsValid_guess(void* record_guess);
};

struct GaugePair_guess {
    int first_guess;
    int second_guess;
};

struct GaugeOutcome_guess {
    int state_guess;
    int result_guess;
};

struct CXRectView_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D911A CXRectView_guess::CopyTail_guess
    void CopyTail_guess(CXRectView_guess* rect_guess);
    CXRectView_guess* Intersect_guess(CXRectView_guess* result_guess,
        const CXRectView_guess* clip_guess);
};

struct GaugeTexture_guess {
    char pad_0000_guess[0x24];
    int width_guess;
    int height_guess;
    // EXTERNAL: TITANIUM 0x005B1910 GaugeTexture_guess::Draw_guess
    int Draw_guess(const CXRectView_guess* destination_guess,
        const CXRectView_guess* source_guess, unsigned int firstColor_guess,
        unsigned int secondColor_guess);
};

struct GaugeRectSource_guess {
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
    virtual CXRect GetRect_guess() const = 0;
};

struct GaugeCallback_guess {
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
    virtual int Slot32_guess(CFriendsWnd_guess* wnd_guess, int one_guess,
        GaugePair_guess* pair_guess);
};

struct GaugeListOps_guess {
    virtual void Slot00_guess() = 0;
    virtual void SetText_guess(CXStr* text_guess) = 0;
    virtual void Slot02_guess() = 0;
    virtual void DrawText_guess(int type_guess, const CXRectView_guess* rect_guess,
        const CXRectView_guess* clip_guess, int color_guess, int one_guess,
        int zero_guess) = 0;
};

struct GaugeTextureManager_guess {
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
    virtual void Release_guess(void* list_guess) = 0;
};

struct GaugeSource_guess {
    char pad_0000_guess[8];
    int kind_guess;
    char pad_000c_guess[0x80];
    int subValues_guess;
    char pad_0090_guess[0x78];
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    int fifth_guess;
    int sixth_guess;
};

struct GaugeManager_guess {
    // EXTERNAL: TITANIUM 0x005B47A0 GaugeManager_guess::Convert_guess
    int Convert_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x005591E2 SelectGaugeTarget_guess
void __cdecl SelectGaugeTarget_guess(void* value_guess);

#define g_gaugeManager_guess EQ_GLOBAL(GaugeManager_guess*, 0x0099D3F4)
#define g_gaugeTextureManager_guess EQ_GLOBAL(GaugeTextureManager_guess*, 0x0099E364)

// Four bytes of CXStr with no destructor, so GaugeWnd's empty dtor stays empty.
struct StrField_guess {
    CStrRep* ptr_guess;
    // EXTERNAL: TITANIUM 0x00573B10 StrField_guess::Compare_guess
    int Compare_guess(const StrField_guess& other_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00571F70 ??4StrField_guess@@QAEAAU0@ABUCXStr@@@Z
    StrField_guess& operator=(const CXStr& other_guess);
    // EXTERNAL: TITANIUM 0x00571F70 ??4StrField_guess@@QAEAAU0@ABU0@@Z
    StrField_guess& operator=(const StrField_guess& other_guess);
    // EXTERNAL: TITANIUM 0x004D95D0 StrField_guess::IsEmpty_guess
    char IsEmpty_guess() const;
    operator const CXStr&() const { return *reinterpret_cast<const CXStr*>(this); }
};

struct LocalText_guess : CXStr {
    LocalText_guess(const CXStr& other_guess) : CXStr(other_guess) {}
    int Length_guess() const { return Ptr != 0 ? Ptr->length : 0; }
    // EXTERNAL: TITANIUM 0x00571590 LocalText_guess::GetAt_guess
    char GetAt_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00572570 LocalText_guess::SetAt_guess
    void SetAt_guess(int index_guess, char ch_guess);
    // EXTERNAL: TITANIUM 0x005722D0 LocalText_guess::Reserve_guess
    void Reserve_guess(int flag_guess);
};

struct EditBox_guess {
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
    virtual void Slot63_guess(const CXStr& text_guess);
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
    virtual LocalText_guess Slot76_guess();
};

// EXTERNAL: TITANIUM 0x00472739 do_ignore_guess
void __cdecl do_ignore_guess(void* manager_guess, char* name_guess);
#define g_ignoreMgr_guess EQ_GLOBAL(void*, 0x00905CE4)
#define g_empty_0063f53f_guess EQ_ARRAY(char, 0x0063F53F)

#define g_flags_00792694_guess EQ_ARRAY(char, 0x00792694)
#define g_sep_0063fe10_guess EQ_ARRAY(char, 0x0063FE10)
#define g_text_006549a0_guess EQ_ARRAY(char, 0x006549A0)
#define g_text_0065499c_guess EQ_ARRAY(char, 0x0065499C)
#define g_fmt_0063f53c_guess EQ_ARRAY(char, 0x0063F53C)
#define g_logName_0063f53f_guess EQ_ARRAY(char, 0x0063F53F)
#define g_gaugeScale_00642d70_guess EQ_GLOBAL(float, 0x00642D70)
#define g_gaugeScale_00641088_guess EQ_GLOBAL(float, 0x00641088)
#define g_gaugeRate_00654998_guess EQ_GLOBAL(float, 0x00654998)
#define g_gaugeBase_0064a0c0_guess EQ_GLOBAL(float, 0x0064A0C0)
#define g_gaugeFactor_00640e20_guess EQ_GLOBAL(float, 0x00640E20)

// EXTERNAL: TITANIUM 0x005598BC GetGaugeValueFromEQ
int __cdecl GetGaugeValueFromEQ(void* data_guess, CXStr* text_guess,
    char* valid_guess);
// EXTERNAL: TITANIUM 0x0060F81E GaugeDelta_guess
int __cdecl GaugeDelta_guess(int value_guess);
// EXTERNAL: TITANIUM 0x005C0C30 GaugeLog_guess
void __cdecl GaugeLog_guess(const char* format_guess, ...);

struct SidlPiece_guess {
    char pad_0000_guess[0x60];
    unsigned int flags_0060_guess;
};

// Edit box at 0x230 (an extension of the window, not in CXWnd).
struct EditWnd_guess {
    char pad_0000_guess[0x230];
    int field_230_guess;
    // EXTERNAL: TITANIUM 0x004D7EBC EditWnd_guess::SetMaxChars_guess
    void SetMaxChars_guess(int max_guess);
};

// Byte at 0x66 of a list window; CXWnd names only the dword at 0x64.
struct ListByte_guess {
    char pad_0000_guess[0x66];
    unsigned char flag_066_guess;
};

// EXTERNAL: TITANIUM 0x00654750 ??_7CFriendsWnd_guess@@6B@
struct GaugeWndBase_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0GaugeWndBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    GaugeWndBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess,
                       int iniVersion_guess, char* blockName_guess);
    // EXTERNAL: TITANIUM 0x005A3100 GaugeWndBase_guess::~GaugeWndBase_guess
    virtual ~GaugeWndBase_guess();
};

struct CFriendsWnd_guess : GaugeWndBase_guess {
    char pad_0004_guess[0x24];
    GaugeCallback_guess* callback_guess;
    char pad_002c_guess[0x30];
    char enabled_guess;
    char pad_005d_guess[7];
    unsigned int style_064_guess;
    char pad_0068_guess[0xc];
    struct GaugeSub_guess {
        // EXTERNAL: TITANIUM 0x00571F70 CFriendsWnd_guess::GaugeSub_guess::Set_guess
        void Set_guess(int* values_guess);
        operator const CXStr&() const {
            return *reinterpret_cast<const CXStr*>(this);
        }
    } sub_guess;
    char pad_0075_guess[3];
    StrField_guess text78_guess;
    int value7c_guess;
    char pad_0080_guess[0x9c];
    union {
        void* notifyData_guess;
        int rangeCount_guess;
    };
    int value120_guess;
    SidlPiece_guess* tint_124_guess;
    char value128_guess;
    char pad_0129_guess[0xb];
    int value134_guess;
    int value138_guess;
    float value13c_guess;
    StrField_guess text140_guess;
    unsigned int value144_guess;
    int value148_guess;
    StrField_guess text14c_guess;
    int value150_guess;
    char pad_0154_guess[4];
    int value158_guess;
    int value15c_guess;
    int value160_guess;
    int value164_guess;
    int value168_guess;
    int value16c_guess;
    int value170_guess;
    int value174_guess;
    union {
        int value178_guess;
        CXWnd* addButton_guess;
    };
    int value17c_guess;
    int value180_guess;
    int value184_guess;
    CFriendsWnd_guess(CXWnd* parent_guess);
    // EXTERNAL: TITANIUM 0x005A0780 CFriendsWnd_guess::PrepareSource_guess
    void PrepareSource_guess(GaugeSource_guess* source_guess);
    // EXTERNAL: TITANIUM 0x0059D960 CFriendsWnd_guess::GetScreenRect
    void GetScreenRect(GaugeTemp_guess* temp_guess);
    void LoadFromSource_guess(GaugeSource_guess* source_guess);
    int HandleLButtonUp_guess(void* record_guess, unsigned int flags_guess);
    virtual ~CFriendsWnd_guess();
    void* Delete_guess(unsigned char flags_guess);
    void OnShow_guess();
    void AddIgnoreFromInput_guess();
    // EXTERNAL: TITANIUM 0x00503B6D CFriendsWnd_guess::AddFriendFromInput_guess
    void AddFriendFromInput_guess();
    void UpdateTooltip_guess();
    CXRectView_guess* CalcFillRect(CXRectView_guess* destination_guess,
        CXRectView_guess* source_guess, int amount_guess);
    CXRectView_guess* CalcLinesFillRect(CXRectView_guess* destination_guess,
        CXRectView_guess* source_guess, int amount_guess);
    int Draw();
    void OnProcessFrame_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
        void* data_guess);
    // EXTERNAL: TITANIUM 0x005A1880 CFriendsWnd_guess::OnShow
    void OnShow();
};


struct GaugeHandleManager_guess {
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
    virtual int Slot13_guess();
    virtual void Slot14_guess(int handle_guess);
};

#define g_handleManager_guess EQ_GLOBAL(GaugeHandleManager_guess*, 0x0099E360)

struct GaugeCleanup_guess {
    void* value_guess;
    int extra_guess;
    // EXTERNAL: TITANIUM 0x004482FB ??1GaugeCleanup_guess@@QAE@XZ
    ~GaugeCleanup_guess();
};

struct GaugeKey_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
};

struct GaugeDtorBase_guess {
    // EXTERNAL: TITANIUM 0x005A1290 GaugeDtorBase_guess::GaugeDtorBase_guess
    GaugeDtorBase_guess(void* first_guess, void* second_guess,
        GaugeKey_guess key_guess);
    // EXTERNAL: TITANIUM 0x005A0940 ??1GaugeDtorBase_guess@@UAE@XZ
    virtual ~GaugeDtorBase_guess();
};

// EXTERNAL: TITANIUM 0x00654880 ??_7CGaugeWnd_guess@@6B@
struct CGaugeWnd_guess : GaugeDtorBase_guess {
    char pad_0004_guess[0x61];
    unsigned char flag_0065_guess;
    char pad_0066_guess[0xb6];
    int value_11c_guess;
    int value_120_guess;
    int value_124_guess;
    unsigned char value_128_guess;
    char pad_0129_guess[3];
    int value_12c_guess;
    int value_130_guess;
    int value_134_guess;
    int value_138_guess;
    float value_13c_guess;
    GaugeCleanup_guess member_140_guess; // 0x140
    int value_148_guess;                 // 0x148
    GaugeCleanup_guess member_14c_guess; // 0x14c
    GaugeCleanup_guess member_154_guess; // 0x154
    int value_15c_guess;
    int value_160_guess;
    int value_164_guess;
    int value_168_guess;
    int value_16c_guess;
    int handle_170_guess;                // 0x170
    CGaugeWnd_guess(void* base_a_guess, void* base_b_guess,
        GaugeKey_guess key_guess, int arg20_guess, int arg24_guess,
        int arg28_guess, int arg2c_guess, int arg30_guess, int arg34_guess,
        int arg38_guess, int arg3c_guess, int arg40_guess,
        unsigned char arg44_guess, int arg48_guess, int arg4c_guess,
        int arg50_guess, int arg54_guess);
    virtual ~CGaugeWnd_guess();
    void* Delete_guess(unsigned char flags_guess);
};

#define gFriendsList_guess EQ_ARRAY(char, 0x0095A1B4)
#define g_records_0095bab4_guess EQ_ARRAY(char, 0x0095BAB4)
#define g_records_0095d3b4_guess EQ_ARRAY(char, 0x0095D3B4)

struct GaugeFlag_guess {
    char pad_0000_guess[0x5d];
    char flag_005d_guess;
};

struct GaugeRows_guess {
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
    // EXTERNAL: TITANIUM 0x00598580 GaugeRows_guess::ClearAllSel
    void ClearAllSel();
    // EXTERNAL: TITANIUM 0x0059B9D0 GaugeRows_guess::AddString
    int AddString(const CXStr& text_guess, int index_guess,
                       int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0059BB50 GaugeRows_guess::FUN_0059bb50_guess
    void FUN_0059bb50_guess(int* value_guess);
};

struct GaugeBuffer_guess {
    int value_guess;
    int field_004_guess;
    int mask_guess;
    int shift_guess;
    int** table_guess;
    int pad_0014_guess[2];
    // EXTERNAL: TITANIUM 0x0047C3AF GaugeBuffer_guess::GaugeBuffer_guess
    GaugeBuffer_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E GaugeBuffer_guess::~GaugeBuffer_guess
    ~GaugeBuffer_guess();
};

struct CFriendsWndView_guess {
    char pad_0000_guess[0x164];
    GaugeFlag_guess* flag164_guess;
    GaugeFlag_guess* flag168_guess;
    char pad_016c_guess[0x4];
    GaugeRows_guess* rows170_guess;
    char pad_0174_guess[0x8];
    GaugeFlag_guess* flag17c_guess;
    char pad_0180_guess[0x4];
    GaugeRows_guess* rows184_guess;
    void RefreshFriendsList_guess();
    void RefreshIgnoreList_guess();
    void UpdateButtons_guess();
    char AboutToShow_guess();
};

struct ModeOwner_guess {
    char pad_0000_guess[0x160];
    EditBox_guess* field_160_guess;
};

struct ModeHost_guess {
    // EXTERNAL: TITANIUM 0x004F288C ModeHost_guess::GetActiveChatWindow_guess
    ModeOwner_guess* GetActiveChatWindow_guess();
};

#define pinstCChatManager_guess EQ_GLOBAL(ModeHost_guess*, 0x009917E4)

struct EverQuestDispatch_guess {
    // EXTERNAL: TITANIUM 0x0049C800 EverQuestDispatch_guess::Dispatch_guess
    void Dispatch_guess(char* args_guess);
    // EXTERNAL: TITANIUM 0x00494051 EverQuestDispatch_guess::SetChatInputFocus_guess
    void SetChatInputFocus_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x0046FEFE do_friends_guess
void __cdecl do_friends_guess(void* manager_guess, char* text_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// Finds the children. Both name inputs take at most 15 characters; Add and Delete start disabled.
// FUNCTION: TITANIUM 0x005035EA
CFriendsWnd_guess::CFriendsWnd_guess(CXWnd* parent_guess)
    : GaugeWndBase_guess(parent_guess, "FriendsWindow", 0xffffffff, 1, 0) {
    value15c_guess = 0;
    value168_guess = 0;
    value164_guess = 0;
    value160_guess = 0;
    value16c_guess = 0;
    value170_guess = 0;
    value178_guess = 0;
    value17c_guess = 0;
    value180_guess = 0;
    value184_guess = 0;
    value174_guess = 0;
    if (tint_124_guess != 0) {
        style_064_guess |= tint_124_guess->flags_0060_guess | 0x10800;
        value158_guess = 0xb;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        value15c_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("AddButton");
        value160_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("WhoButton");
        value168_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        value164_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("ContactButton");
        if (value15c_guess != 0) {
            ((CXWnd*)value15c_guess)->Enabled = 0;
        }
        if (value168_guess != 0) {
            ((CXWnd*)value168_guess)->Enabled = 0;
        }
        value16c_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("NameInput");
        if (value16c_guess != 0) {
            ((EditWnd_guess*)value16c_guess)->field_230_guess = 1;
            ((EditWnd_guess*)value16c_guess)->SetMaxChars_guess(0xf);
        }
        value170_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("FriendsList");
        if (value170_guess != 0) {
            ((CListWnd*)value170_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((CListWnd*)value170_guess)->SetColumnJustification(0, 1);
            ((ListByte_guess*)value170_guess)->flag_066_guess &= 0xdf;
            ((CXWnd*)value170_guess)->WindowStyle |= 0x20000;
        }
        value178_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("IgnoreAddButton");
        value17c_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("IgnoreDeleteButton");
        if (value178_guess != 0) {
            ((CXWnd*)value178_guess)->Enabled = 0;
        }
        if (value17c_guess != 0) {
            ((CXWnd*)value17c_guess)->Enabled = 0;
        }
        value180_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("IgnoreNameInput");
        if (value180_guess != 0) {
            ((EditWnd_guess*)value180_guess)->field_230_guess = 1;
            ((EditWnd_guess*)value180_guess)->SetMaxChars_guess(0xf);
        }
        value184_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("IgnoreList");
        if (value184_guess != 0) {
            ((CListWnd*)value184_guess)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((CListWnd*)value184_guess)->SetColumnJustification(0, 1);
            ((ListByte_guess*)value184_guess)->flag_066_guess &= 0xdf;
            ((CXWnd*)value184_guess)->WindowStyle |= 0x20000;
        }
        value174_guess = (int)((CSidlScreenWnd*)this)->GetChildItem("Subwindows");
    }
}

// Destructor of the friends window (vtable 0x654750, ctor 0x005035EA): restores its vtable and runs the
// CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x00503A02
CFriendsWnd_guess::~CFriendsWnd_guess() {
}

// Refills FriendsList from the friend names; the row data is the record index.
// FUNCTION: TITANIUM 0x00503A0D
void CFriendsWndView_guess::RefreshFriendsList_guess() {
    if (rows170_guess != 0) {
        rows170_guess->ClearAllSel();
        rows170_guess->Slot76_guess();
        int index = 0;
        char* record = gFriendsList_guess;
        do {
            if (*record != 0) {
                CXStr text(record);
                rows170_guess->AddString(text, -1, index, 0);
            }
            ++index;
            record += 0x40;
        } while ((int)record < (int)g_records_0095bab4_guess);
    }
    if (flag168_guess != 0) {
        flag168_guess->flag_005d_guess = 0;
    }
}

// Refills IgnoreList from the ignore names (0x0095BAB4).
// FUNCTION: TITANIUM 0x00503AAB
void CFriendsWndView_guess::RefreshIgnoreList_guess() {
    if (rows184_guess != 0) {
        rows184_guess->ClearAllSel();
        rows184_guess->Slot76_guess();
        int index = 0;
        char* record = g_records_0095bab4_guess;
        do {
            if (*record != 0) {
                CXStr text(record);
                rows184_guess->AddString(text, -1, index, 0);
            }
            ++index;
            record += 0x40;
        } while ((int)record < (int)g_records_0095d3b4_guess);
    }
    if (flag17c_guess != 0) {
        flag17c_guess->flag_005d_guess = 0;
    }
}

// Scalar deleting destructor of the friends window (vtable 0x654750 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x00503E15
void* CFriendsWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->CFriendsWnd_guess::~CFriendsWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Show hook: when shown (+0x5C), pops context tip 0xB on CTipWnd (0x009928E0), then the base call.
// FUNCTION: TITANIUM 0x00503B49
void CFriendsWnd_guess::OnShow_guess() {
    if (this->enabled_guess != 0 && pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0xb, 0);
    }
    this->OnShow();
}

// IgnoreAddButton or Enter in IgnoreNameInput: /ignore on the typed name (do_ignore_guess toggles it),
// clears the input and refills the list. The friend twin is 0x00503B6D.
// FUNCTION: TITANIUM 0x00503CC1
// @early-stop: budget, diff ndiff=2
void CFriendsWnd_guess::AddIgnoreFromInput_guess() {
    if (value184_guess != 0 && value180_guess != 0) {
        ((CListWnd*)value184_guess)->SetCurSel(-1);
        LocalText_guess text = ((EditBox_guess*)value180_guess)->Slot76_guess();
        text.Reserve_guess(0);
        if (text.Length_guess() > 0) {
            char* name = new char[text.Length_guess() + 1];
            if (name != 0) {
                strcpy(name, text);
                do_ignore_guess(g_ignoreMgr_guess, name);
                delete[] name;
            }
            CXStr empty_guess(g_empty_0063f53f_guess);
            ((EditBox_guess*)value180_guess)->Slot63_guess(empty_guess);
        }
        ((CFriendsWndView_guess*)this)->RefreshIgnoreList_guess();
        ((CXWnd*)value184_guess)->SetFocus();
        if (addButton_guess != 0) {
            addButton_guess->Enabled =
                ((EditBox_guess*)value180_guess)->Slot76_guess().Length_guess() != 0;
        }
    }
}

// Delete buttons (and Contact) are enabled only while their list has a selection.
// FUNCTION: TITANIUM 0x00503E31
// @early-stop: budget, structural ndiff=1
void CFriendsWndView_guess::UpdateButtons_guess() {
    GaugeBuffer_guess value_guess(0x20);
    if (this->rows170_guess != 0) {
        this->rows170_guess->FUN_0059bb50_guess(&value_guess.value_guess);
        if (this->flag168_guess != 0) {
            this->flag168_guess->flag_005d_guess = value_guess.value_guess > 0;
        }
        if (this->flag164_guess != 0) {
            this->flag164_guess->flag_005d_guess = value_guess.value_guess > 0;
        }
    }
    if (this->rows184_guess != 0) {
        this->rows184_guess->FUN_0059bb50_guess(&value_guess.value_guess);
        if (this->flag17c_guess != 0) {
            this->flag17c_guess->flag_005d_guess = value_guess.value_guess > 0;
        }
    }
}

// Refills both lists and the buttons; always 1.
// FUNCTION: TITANIUM 0x00503EC6
char CFriendsWndView_guess::AboutToShow_guess() {
    this->RefreshFriendsList_guess();
    this->RefreshIgnoreList_guess();
    this->UpdateButtons_guess();
    return 1;
}

// WndNotification. 0xE (text changed) enables an Add button while its input is non-empty; 6 (Enter)
// adds the typed name; 1 (click): Subwindows refills, Add/IgnoreAdd add, Delete and IgnoreDelete run
// /friend and /ignore (both toggles) on every selected name. Who runs Who_guess on the one selected
// friend, else "friend" (string 0xC28), followed by "ALL" (0x3395). Contact puts "/tell <name> " (0x3696)
// in the chat input and focuses it.
// FUNCTION: TITANIUM 0x00503EE0
// @early-stop: unknown, structural ndiff=171
int CFriendsWnd_guess::WndNotification_guess(CXWnd* sender_guess,
    unsigned int message_guess, void* data_guess) {
    char text_guess[0x100];
    char out_guess[0x100];
    char tmp_guess[0x50];
    char rows_guess[100][0x40];

    if (message_guess == 0xe) {
        if ((int)sender_guess == value16c_guess) {
            if (value15c_guess != 0) {
                LocalText_guess text =
                    ((EditBox_guess*)value16c_guess)->Slot76_guess();
                ((GaugeFlag_guess*)value15c_guess)->flag_005d_guess =
                    text.Length_guess() != 0;
            }
            return 0;
        }
        if ((int)sender_guess == value180_guess) {
            if (value178_guess != 0) {
                LocalText_guess text =
                    ((EditBox_guess*)value180_guess)->Slot76_guess();
                ((GaugeFlag_guess*)value178_guess)->flag_005d_guess =
                    text.Length_guess() != 0;
            }
            return 0;
        }
    } else if (message_guess == 6) {
        if ((int)sender_guess == value16c_guess) {
            AddFriendFromInput_guess();
            return 1;
        }
        if ((int)sender_guess == value180_guess) {
            AddIgnoreFromInput_guess();
            return 1;
        }
    } else if (message_guess == 1) {
        if ((int)sender_guess == value174_guess) {
            ((CFriendsWndView_guess*)this)->RefreshFriendsList_guess();
            ((CFriendsWndView_guess*)this)->RefreshIgnoreList_guess();
        } else {
            if ((int)sender_guess == value160_guess) {
                text_guess[0] = 0;
                GaugeBuffer_guess count_guess(0x20);
                strcpy(text_guess, pStringTable->getString(0xc28, 0));
                if (value170_guess != 0) {
                    ((GaugeRows_guess*)value170_guess)->FUN_0059bb50_guess(
                        &count_guess.value_guess);
                    if (count_guess.value_guess == 1) {
                        CXStr item_guess = ((CListWnd*)value170_guess)->GetItemText(
                            count_guess.table_guess[0][0], 0);
                        strcpy(text_guess, (char*)item_guess);
                    }
                }
                sprintf(out_guess, "%s %s", text_guess,
                    pStringTable->getString(0x3395, 0));
                ((EverQuestDispatch_guess*)pEverQuest)->Dispatch_guess(out_guess);
                return 1;
            }
            if ((int)sender_guess == value170_guess ||
                (int)sender_guess == value184_guess) {
                ((CFriendsWndView_guess*)this)->UpdateButtons_guess();
                return 0;
            }
            if ((int)sender_guess == value15c_guess) {
                AddFriendFromInput_guess();
                return 1;
            }
            if ((int)sender_guess == value178_guess) {
                AddIgnoreFromInput_guess();
                return 1;
            }
            if ((int)sender_guess == value168_guess) {
                if (value170_guess != 0) {
                    GaugeBuffer_guess count_guess(0x20);
                    int rowCount_guess = 0;
                    ((GaugeRows_guess*)value170_guess)->FUN_0059bb50_guess(
                        &count_guess.value_guess);
                    for (int i_guess = 0; i_guess < count_guess.value_guess;
                        ++i_guess) {
                        int row_guess = count_guess.table_guess[
                            i_guess >> count_guess.shift_guess]
                            [i_guess & count_guess.mask_guess];
                        CXStr item_guess = ((CListWnd*)value170_guess)->GetItemText(
                            row_guess, 0);
                        strcpy(rows_guess[rowCount_guess], (char*)item_guess);
                        ++rowCount_guess;
                    }
                    for (int i_guess = 0; i_guess < rowCount_guess; ++i_guess) {
                        do_friends_guess(g_ignoreMgr_guess, rows_guess[i_guess]);
                    }
                    ((CFriendsWndView_guess*)this)->UpdateButtons_guess();
                    return 1;
                }
                return 1;
            }
            if ((int)sender_guess == value17c_guess) {
                if (value184_guess != 0) {
                    GaugeBuffer_guess count_guess(0x20);
                    int rowCount_guess = 0;
                    ((GaugeRows_guess*)value184_guess)->FUN_0059bb50_guess(
                        &count_guess.value_guess);
                    for (int i_guess = 0; i_guess < count_guess.value_guess;
                        ++i_guess) {
                        int row_guess = count_guess.table_guess[
                            i_guess >> count_guess.shift_guess]
                            [i_guess & count_guess.mask_guess];
                        CXStr item_guess = ((CListWnd*)value184_guess)->GetItemText(
                            row_guess, 0);
                        strcpy(rows_guess[rowCount_guess], (char*)item_guess);
                        ++rowCount_guess;
                    }
                    for (int i_guess = 0; i_guess < rowCount_guess; ++i_guess) {
                        do_ignore_guess(g_ignoreMgr_guess, rows_guess[i_guess]);
                    }
                    ((CFriendsWndView_guess*)this)->UpdateButtons_guess();
                    return 1;
                }
                return 1;
            }
            if ((int)sender_guess == value164_guess) {
                if (pinstCChatManager_guess != 0 && value170_guess != 0) {
                    ModeOwner_guess* owner_guess =
                        pinstCChatManager_guess->GetActiveChatWindow_guess();
                    if (owner_guess != 0) {
                        GaugeBuffer_guess count_guess(0x20);
                        ((GaugeRows_guess*)value170_guess)->FUN_0059bb50_guess(
                            &count_guess.value_guess);
                        if (count_guess.value_guess > 0) {
                            CXStr item_guess = ((CListWnd*)value170_guess)->GetItemText(
                                count_guess.table_guess[0][0], 0);
                            strcpy(tmp_guess, (char*)item_guess);
                            sprintf(out_guess, "%s %s ",
                                pStringTable->getString(0x3696, 0), tmp_guess);
                            CXStr name_guess(out_guess);
                            owner_guess->field_160_guess->Slot63_guess(name_guess);
                            ((CXWnd*)value170_guess)->SetFocus();
                            ((EverQuestDispatch_guess*)pEverQuest)->
                                SetChatInputFocus_guess(0);
                        }
                        return 1;
                    }
                }
                return 1;
            }
        }
    }
    return ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(
        sender_guess, message_guess, data_guess);
}

// Overlap of two rects into `result_guess`; all -1 when they do not overlap.
// FUNCTION: TITANIUM 0x0050445A
// @early-stop: budget, structural ndiff=41
CXRectView_guess* CXRectView_guess::Intersect_guess(
    CXRectView_guess* result_guess, const CXRectView_guess* clip_guess) {
    int oLeft = clip_guess->left_guess;
    int right = right_guess;
    int bottom;
    if (right < oLeft) {
        result_guess->left_guess = -1;
        result_guess->top_guess = -1;
        result_guess->right_guess = -1;
        bottom = -1;
    } else {
        int oRight = clip_guess->right_guess;
        int left = left_guess;
        if (left > oRight) {
            result_guess->left_guess = -1;
            result_guess->top_guess = -1;
            result_guess->right_guess = -1;
            bottom = -1;
        } else {
            int top = top_guess;
            int oBottom = clip_guess->bottom_guess;
            if (top > oBottom) {
                result_guess->left_guess = -1;
                result_guess->top_guess = -1;
                result_guess->right_guess = -1;
                bottom = -1;
            } else {
                bottom = bottom_guess;
                int oTop = clip_guess->top_guess;
                if (bottom < oTop) {
                    result_guess->left_guess = -1;
                    result_guess->top_guess = -1;
                    result_guess->right_guess = -1;
                    bottom = -1;
                } else {
                    if (left <= oLeft) {
                        left = oLeft;
                    }
                    if (top <= oTop) {
                        top = oTop;
                    }
                    if (right < oRight) {
                        oRight = right;
                    }
                    if (bottom >= oBottom) {
                        bottom = oBottom;
                    }
                    result_guess->left_guess = left;
                    result_guess->top_guess = top;
                    result_guess->right_guess = oRight;
                }
            }
        }
    }
    result_guess->bottom_guess = bottom;
    return result_guess;
}

// CGaugeWnd from code: template textures and tints (arguments 0x24-0x54), the gauge type in +0x11C.
// The text and value caches start empty (+0x148 = -1); +0x170 is a handle from 0x0099E360.
// FUNCTION: TITANIUM 0x005044F2
// @early-stop: budget, structural ndiff=58
CGaugeWnd_guess::CGaugeWnd_guess(void* base_a_guess, void* base_b_guess,
    GaugeKey_guess key_guess, int arg20_guess, int arg24_guess,
    int arg28_guess, int arg2c_guess, int arg30_guess, int arg34_guess,
    int arg38_guess, int arg3c_guess, int arg40_guess,
    unsigned char arg44_guess, int arg48_guess, int arg4c_guess,
    int arg50_guess, int arg54_guess)
    : GaugeDtorBase_guess(base_a_guess, base_b_guess, key_guess) {
    member_140_guess.value_guess = 0;
    member_14c_guess.value_guess = 0;
    member_154_guess.value_guess = 0;
    member_154_guess.extra_guess = 0;
    value_15c_guess = 0;
    value_160_guess = 0;
    value_164_guess = 0;
    value_168_guess = 0;
    value_16c_guess = 0;
    value_13c_guess = 0.0f;
    member_154_guess.extra_guess = arg20_guess;
    value_15c_guess = arg24_guess;
    value_160_guess = arg28_guess;
    value_164_guess = arg2c_guess;
    value_168_guess = arg30_guess;
    value_16c_guess = arg34_guess;
    value_11c_guess = arg38_guess;
    value_120_guess = arg3c_guess;
    value_124_guess = arg40_guess;
    value_128_guess = (char)arg44_guess;
    value_12c_guess = arg48_guess;
    value_130_guess = arg4c_guess;
    value_134_guess = arg50_guess;
    value_138_guess = arg54_guess;
    unsigned long tick_guess = GetTickCount();
    value_148_guess = -1;
    flag_0065_guess |= 8;
    member_140_guess.extra_guess = (int)tick_guess;
    member_14c_guess.extra_guess = -2;
    handle_170_guess = g_handleManager_guess->Slot13_guess();
}

// Gives the handle the constructor took back to the handle manager (slot 0x14).
// FUNCTION: TITANIUM 0x0050462E
CGaugeWnd_guess::~CGaugeWnd_guess() {
    g_handleManager_guess->Slot14_guess(handle_170_guess);
}

// Fill rect: `amount_guess` is in tenths of a percent (1000 = full).
// FUNCTION: TITANIUM 0x005046A2
// @early-stop: budget, structural ndiff=20
CXRectView_guess* CFriendsWnd_guess::CalcFillRect(
    CXRectView_guess* destination_guess, CXRectView_guess* source_guess,
    int amount_guess) {
    if (rangeCount_guess > 0) {
        int right_guess = source_guess->right_guess;
        int bottom_guess = source_guess->bottom_guess;
        int left_guess = source_guess->left_guess;
        int top_guess = source_guess->top_guess;
        int width_guess = right_guess - left_guess;
        float scaledWidth_guess = (float)width_guess * g_gaugeScale_00641088_guess;
        int scaled_guess = (int)(scaledWidth_guess * amount_guess);
        destination_guess->top_guess = top_guess;
        destination_guess->left_guess = left_guess;
        destination_guess->bottom_guess = bottom_guess;
        destination_guess->right_guess = scaled_guess + left_guess + 1;
        return destination_guess;
    } else {
        destination_guess->CopyTail_guess(source_guess);
        return destination_guess;
    }
}

// Lines-fill rect: progress inside the current fifth of the bar ((amount - 1) % 200), the experience
// bar's sub-bar.
// FUNCTION: TITANIUM 0x005046FE
// @early-stop: budget, diff ndiff=24
CXRectView_guess* CFriendsWnd_guess::CalcLinesFillRect(
    CXRectView_guess* destination_guess, CXRectView_guess* source_guess,
    int amount_guess) {
    if (rangeCount_guess > 0) {
        int right_guess = source_guess->right_guess;
        int bottom_guess = source_guess->bottom_guess;
        int left_guess = source_guess->left_guess;
        int top_guess = source_guess->top_guess;
        int width_guess = right_guess - left_guess;
        int remainder_guess = (amount_guess - 1) % 200;
        float scaledWidth_guess = (float)width_guess *
            g_gaugeRate_00654998_guess;
        int scaled_guess = (int)(scaledWidth_guess * remainder_guess);
        destination_guess->top_guess = top_guess;
        destination_guess->left_guess = left_guess;
        destination_guess->bottom_guess = bottom_guess;
        destination_guess->right_guess = scaled_guess + left_guess;
        return destination_guess;
    } else {
        destination_guess->CopyTail_guess(source_guess);
        return destination_guess;
    }
}

// From the screen template (type 0x18, a gauge): the text and the six textures. Draw puts
// +0x168 left and +0x16C right, so those two are the end caps; +0x158 background, +0x15C fill,
// +0x160 lines, +0x164 lines fill.
// FUNCTION: TITANIUM 0x00504769
void CFriendsWnd_guess::LoadFromSource_guess(GaugeSource_guess* source_guess) {
    this->PrepareSource_guess(source_guess);
    if (source_guess->kind_guess == 0x18) {
        this->sub_guess.Set_guess(&source_guess->subValues_guess);
        this->value158_guess = g_gaugeManager_guess->Convert_guess(source_guess->first_guess);
        this->value15c_guess = g_gaugeManager_guess->Convert_guess(source_guess->second_guess);
        this->value160_guess = g_gaugeManager_guess->Convert_guess(source_guess->third_guess);
        this->value164_guess = g_gaugeManager_guess->Convert_guess(source_guess->fourth_guess);
        this->value168_guess = g_gaugeManager_guess->Convert_guess(source_guess->sixth_guess);
        this->value16c_guess = g_gaugeManager_guess->Convert_guess(source_guess->fifth_guess);
    }
}

// Left release inside the bar: selects the gauge's target (by gauge type, +0x11C), then parent code 1.
// FUNCTION: TITANIUM 0x0050481F
int CFriendsWnd_guess::HandleLButtonUp_guess(void* record_guess, unsigned int flags_guess) {
    int result_guess = -1;
    GaugeTemp_guess temp_guess;
    GaugePair_guess pair_guess;
    this->GetScreenRect(&temp_guess);
    if (temp_guess.IsValid_guess(record_guess) != 0 &&
        (flags_guess & 0xffff0000) != 0x10000) {
        SelectGaugeTarget_guess(this->notifyData_guess);
        if (this->callback_guess != 0) {
            pair_guess.first_guess = *(int*)record_guess;
            pair_guess.second_guess = *((int*)record_guess + 1);
            if (this->callback_guess->Slot32_guess(this, 1, &pair_guess) >= 0) {
                result_guess = 0;
            }
        } else {
            result_guess = 0;
        }
    } else {
        result_guess = 0;
    }
    return result_guess;
}

// For gauge types flagged at 0x00792694: when text or value changed, the tooltip becomes the text
// (newlines as spaces) plus " <NN%>", the value rounded to a percentage ((value + 5) / 10).
// FUNCTION: TITANIUM 0x00504893
void CFriendsWnd_guess::UpdateTooltip_guess() {
    if (g_flags_00792694_guess[(int)notifyData_guess] != 0) {
        if (text140_guess.Compare_guess(text14c_guess, 0) != 0 || value148_guess != value150_guess) {
            char buf_guess[20];
            LocalText_guess text(text140_guess);
            for (int i = 0; i < text.Length_guess(); i++) {
                if (text.GetAt_guess(i) == '\n') {
                    text.SetAt_guess(i, ' ');
                }
            }
            if (value148_guess >= 0) {
                if (text.Length_guess() > 0) {
                    text += g_sep_0063fe10_guess;
                }
                text += g_text_006549a0_guess;
                sprintf(buf_guess, g_fmt_0063f53c_guess, (value148_guess + 5) / 10);
                text += buf_guess;
                text += g_text_0065499c_guess;
            }
            text78_guess = text;
            text14c_guess = text140_guess;
            value150_guess = value148_guess;
        }
    }
}

// Scalar deleting destructor of a gauge window (CGaugeWnd, vtable 0x654880 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x005049E2
void* CGaugeWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->CGaugeWnd_guess::~CGaugeWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// GetGaugeValueFromEQ gives 0-1000, -1 (draw nothing), -2 (a full bar in 0xFF800000), or -10 (full) down
// to -110 (empty), a second scale drawn in 0xFF800080. The bar slides toward a new value at 1 unit per ms
// while the text is unchanged. Draws end caps and background, the fill in its tint, the lines, the lines
// fill when +0x128 is 1 (tint at +0x124, misnamed sidlPiece_124_guess), then the text. Error numbers are
// GaugeWnd.cpp source lines.
// FUNCTION: TITANIUM 0x005049FE
// @early-stop: budget, structural ndiff=247
int CFriendsWnd_guess::Draw() {
    CXRectView_guess textureRect_guess;
    CXRectView_guess localRect_guess;
    GaugeOutcome_guess outcome_guess;
    outcome_guess.result_guess = -1;
    CXRect screenRect_guess =
        ((GaugeRectSource_guess*)this)->GetRect_guess();
    CXRect clientRect_guess = ((CXWnd*)this)->GetClientClipRect();
    CXRectView_guess drawRect_guess;
    // The bar starts at the window's top-left plus +0x134 / +0x138.
    drawRect_guess.left_guess = value134_guess + screenRect_guess.left;
    drawRect_guess.top_guess = value138_guess + screenRect_guess.top;
    drawRect_guess.right_guess = screenRect_guess.right;
    drawRect_guess.bottom_guess = screenRect_guess.bottom;

    CXStr stateText_guess;
    char valueValid_guess = 1;
    // Value for this gauge's type, and its text.
    outcome_guess.state_guess = GetGaugeValueFromEQ(notifyData_guess,
        &stateText_guess, &valueValid_guess);
    float initialValue_guess = (float)outcome_guess.state_guess;
    float currentValue_guess = (float)outcome_guess.state_guess;
    int elapsed_guess = (int)(GetTickCount() - value144_guess);
    float elapsedFloat_guess = (float)elapsed_guess;
    if (valueValid_guess != 0) {
        int remaining_guess = GaugeDelta_guess(outcome_guess.state_guess -
            (int)value13c_guess);
        // Slide (only while valueValid_guess stays set): while the text is unchanged and the gap to
        // the last drawn value (+0x13C) is larger than the ms since the last draw (+0x144), move
        // that many units toward the new value instead of jumping.
        if ((float)remaining_guess > elapsedFloat_guess) {
            if (((StrField_guess*)&stateText_guess)->Compare_guess(
                    text140_guess, 0) == 0) {
                float step_guess = elapsedFloat_guess;
                if (initialValue_guess <= value13c_guess) {
                    step_guess = -step_guess;
                }
                currentValue_guess = step_guess + value13c_guess;
            }
        }
    }

    // -1: nothing is drawn.
    if (outcome_guess.state_guess == -1) {
        outcome_guess.result_guess = 0;
    } else {
        int errorLine_guess = 0;
        // Left end cap (+0x168), the background (+0x158) from its right edge, then the right end cap
        // (+0x16C). A failed draw records the GaugeWnd.cpp line (0xA2, 0xAC, 0xBA) and stops
        // drawing.
        if (value168_guess != 0) {
            GaugeTexture_guess* texture_guess =
                (GaugeTexture_guess*)value168_guess;
            localRect_guess.left_guess = drawRect_guess.left_guess;
            localRect_guess.top_guess = drawRect_guess.top_guess;
            localRect_guess.right_guess = texture_guess->width_guess +
                drawRect_guess.left_guess;
            localRect_guess.bottom_guess = texture_guess->height_guess +
                drawRect_guess.top_guess;
            int drawResult_guess = texture_guess->Draw_guess(&localRect_guess,
                (const CXRectView_guess*)&clientRect_guess, 0xffffffff,
                0xff000000);
            drawRect_guess.left_guess = localRect_guess.right_guess;
            if (drawResult_guess < 0) {
                errorLine_guess = 0xa2;
            }
        }

        if (errorLine_guess == 0 && value158_guess != 0) {
            GaugeTexture_guess* texture_guess =
                (GaugeTexture_guess*)value158_guess;
            drawRect_guess.right_guess = drawRect_guess.left_guess +
                texture_guess->width_guess;
            drawRect_guess.bottom_guess = drawRect_guess.top_guess +
                texture_guess->height_guess;
            int drawResult_guess = texture_guess->Draw_guess(&drawRect_guess,
                (const CXRectView_guess*)&clientRect_guess, 0xffffffff,
                0xff000000);
            if (drawResult_guess < 0) {
                errorLine_guess = 0xac;
            }
        }

        if (errorLine_guess == 0 && value16c_guess != 0) {
            GaugeTexture_guess* texture_guess =
                (GaugeTexture_guess*)value16c_guess;
            localRect_guess.left_guess = drawRect_guess.right_guess;
            localRect_guess.top_guess = drawRect_guess.top_guess;
            localRect_guess.right_guess = drawRect_guess.right_guess +
                texture_guess->width_guess;
            localRect_guess.bottom_guess = drawRect_guess.top_guess +
                texture_guess->height_guess;
            int drawResult_guess = texture_guess->Draw_guess(&localRect_guess,
                (const CXRectView_guess*)&clientRect_guess, 0xffffffff,
                0xff000000);
            if (drawResult_guess < 0) {
                errorLine_guess = 0xba;
            }
        }

        // -2: a full bar in red (0xFF800000) with the lines (+0x160) over it.
        if (errorLine_guess == 0 && outcome_guess.state_guess == -2) {
            if (value15c_guess != 0) {
                CalcFillRect(&localRect_guess, &drawRect_guess, 1000);
                int drawResult_guess = ((GaugeTexture_guess*)value15c_guess)->Draw_guess(
                    &drawRect_guess,
                    localRect_guess.Intersect_guess(&textureRect_guess,
                        (const CXRectView_guess*)&clientRect_guess),
                    0xff800000, 0xff000000);
                if (drawResult_guess < 0) {
                    errorLine_guess = 0xc7;
                }
            }
            if (errorLine_guess == 0 && value160_guess != 0) {
                int drawResult_guess = ((GaugeTexture_guess*)value160_guess)->Draw_guess(
                    &drawRect_guess, (const CXRectView_guess*)&clientRect_guess,
                    0xffffffff, 0xff000000);
                if (drawResult_guess < 0) {
                    errorLine_guess = 0xd0;
                }
            }
        // -10 .. -110: the second scale, (11 + value / 10) * 100 of 1000, so -10 is full and -110
        // empty, in purple (0xFF800080); the lines fill in grey when +0x128 is 1.
        } else if (errorLine_guess == 0 && outcome_guess.state_guess < -9) {
            int amount_guess = (int)((g_gaugeBase_0064a0c0_guess -
                currentValue_guess * g_gaugeScale_00642d70_guess) *
                g_gaugeFactor_00640e20_guess);
            if (amount_guess > 0) {
                if (value15c_guess != 0) {
                    CalcFillRect(&localRect_guess, &drawRect_guess,
                        amount_guess);
                    int drawResult_guess =
                        ((GaugeTexture_guess*)value15c_guess)->Draw_guess(
                            &drawRect_guess,
                            localRect_guess.Intersect_guess(
                                &textureRect_guess,
                                (const CXRectView_guess*)&clientRect_guess),
                            0xff800080, 0xff000000);
                    if (drawResult_guess < 0) {
                        errorLine_guess = 0xe2;
                    }
                }
                if (errorLine_guess == 0 && value160_guess != 0) {
                    int drawResult_guess =
                        ((GaugeTexture_guess*)value160_guess)->Draw_guess(
                            &drawRect_guess,
                            (const CXRectView_guess*)&clientRect_guess,
                            0xffffffff, 0xff000000);
                    if (drawResult_guess < 0) {
                        errorLine_guess = 0xeb;
                    }
                }
                if (errorLine_guess == 0 && value128_guess == 1 &&
                    value164_guess != 0) {
                    CalcLinesFillRect(&localRect_guess, &drawRect_guess,
                        amount_guess);
                    int drawResult_guess =
                        ((GaugeTexture_guess*)value164_guess)->Draw_guess(
                            &drawRect_guess,
                            localRect_guess.Intersect_guess(
                                &textureRect_guess,
                                (const CXRectView_guess*)&clientRect_guess),
                            0xffc0c0c0, 0xff000000);
                    if (drawResult_guess < 0) {
                        errorLine_guess = 0xf8;
                    }
                }
            }
        // 0-1000: the fill in the gauge tint (+0x120), the lines, and when +0x128 is 1 the lines
        // fill in the tint at +0x124.
        } else if (errorLine_guess == 0 && outcome_guess.state_guess >= 0) {
            if (value15c_guess != 0) {
                int amount_guess = (int)currentValue_guess;
                CalcFillRect(&localRect_guess, &drawRect_guess,
                    amount_guess);
                int drawResult_guess =
                    ((GaugeTexture_guess*)value15c_guess)->Draw_guess(
                        &drawRect_guess,
                        localRect_guess.Intersect_guess(&textureRect_guess,
                            (const CXRectView_guess*)&clientRect_guess),
                        (unsigned int)value120_guess, 0xff000000);
                if (drawResult_guess < 0) {
                    errorLine_guess = 0x105;
                }
            }
            if (errorLine_guess == 0 && value160_guess != 0) {
                int drawResult_guess =
                    ((GaugeTexture_guess*)value160_guess)->Draw_guess(
                        &drawRect_guess,
                        (const CXRectView_guess*)&clientRect_guess,
                        0xffffffff, 0xff000000);
                if (drawResult_guess < 0) {
                    errorLine_guess = 0x10e;
                }
            }
            if (errorLine_guess == 0 && value128_guess == 1 &&
                value164_guess != 0) {
                int amount_guess = (int)currentValue_guess;
                CalcLinesFillRect(&localRect_guess, &drawRect_guess,
                    amount_guess);
                int drawResult_guess =
                    ((GaugeTexture_guess*)value164_guess)->Draw_guess(
                        &drawRect_guess,
                        localRect_guess.Intersect_guess(&textureRect_guess,
                            (const CXRectView_guess*)&clientRect_guess),
                        (unsigned int)tint_124_guess, 0xff000000);
                if (drawResult_guess < 0) {
                    errorLine_guess = 0x11b;
                }
            }
        }

        // A failed draw is logged with its source line. Otherwise the text (the default at sub_guess
        // when empty) is drawn over the bar.
        if (errorLine_guess != 0) {
            GaugeLog_guess("%s at: %s, %d\n", g_logName_0063f53f_guess,
                "C:\\EQ\\EverQuest\\GaugeWnd.cpp", errorLine_guess);
        } else {
            if (((StrField_guess*)&stateText_guess)->IsEmpty_guess() != 0) {
                stateText_guess = (const CXStr&)sub_guess;
            }
            if (((StrField_guess*)&stateText_guess)->IsEmpty_guess() == 0) {
                GaugeListOps_guess* list_guess =
                    (GaugeListOps_guess*)value170_guess;
                list_guess->SetText_guess(&stateText_guess);
                list_guess->DrawText_guess(2,
                    (const CXRectView_guess*)&drawRect_guess,
                    (const CXRectView_guess*)&clientRect_guess, value7c_guess,
                    1, 0);
                g_gaugeTextureManager_guess->Release_guess(
                    (void*)value170_guess);
            }
            outcome_guess.result_guess = 0;
        }
    }

    // Remember the drawn value, text, time and raw value for the next frame's slide.
    value13c_guess = currentValue_guess;
    text140_guess = stateText_guess;
    value144_guess = GetTickCount();
    value148_guess = outcome_guess.state_guess;
    return outcome_guess.result_guess;
}

// Per frame: refreshes the tooltip while shown, then the base.
// FUNCTION: TITANIUM 0x00504F1D
void CFriendsWnd_guess::OnProcessFrame_guess() {
    if (this->enabled_guess != 0) {
        this->UpdateTooltip_guess();
    }
    ((CXWnd*)this)->OnProcessFrame();
}
