// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 192: a hint from compare/tumap.py.
// COptionsWnd (screen OptionsWindow): the General, Display, Mouse, Keyboard, Chat, Color and Mail
// pages, their refreshers, WndNotification handlers and key-binding capture. Route_guess, Settings_guess,
// TimedOwner_guess, EntryList_guess and the other small structs are views of OptionsWnd_guess; its ctor
// names every offset. The getters/setters on 0x0099D3EC (StatSource_guess, CDisplayView_guess) are the window
// fade delay, fade duration, window alpha and fade-to-alpha. 0x00988DF0 (g_iniConfig_guess) is pEverQuest.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>

// EXTERNAL: TITANIUM 0x00438CF7 SetColors_guess
void __cdecl SetColors_guess(int user_guess, int text_guess, int green_guess, int blue_guess);
// EXTERNAL: TITANIUM 0x00438BD4 GetDefaultUserDefinedColor_guess
void __cdecl GetDefaultUserDefinedColor_guess(int user_guess, int* text_guess, int* green_guess, int* blue_guess);

struct TextColors_guess {
    char padding_guess[0xAB4];
    int pendingIndex_guess;     // +0xAB4
    int alternateIndex_guess;   // +0xAB8
    int selectedIndex_guess;    // +0xABC
    CListWnd* active_guess;     // +0xAC0
    void SetColorOptions_guess(int user_guess, int text_guess, int green_guess, int blue_guess);
    void RestoreDefaultColors_guess();
    int ColorPageWndNotification_guess(int index_guess, int event_guess, unsigned int value_guess);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x0060E460 AppendText_guess
void __cdecl AppendText_guess(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x0060BEB0 WriteIniText_guess
void __cdecl WriteIniText_guess(const char* section_guess, const char* key_guess, const char* value_guess, const char* file_guess);

#define g_colorSuffix_guess EQ_ARRAY(char, 0x0064240C)
#define g_colorFormat_guess EQ_ARRAY(char, 0x0063F53C)
#define g_eqClientIni_guess EQ_ARRAY(char, 0x006412E4)
#define g_textColors_guess EQ_ARRAY(char, 0x00642400)
#define g_colorGreen_guess EQ_ARRAY(char, 0x006423F8)
#define g_colorBlue_guess EQ_ARRAY(char, 0x006423F0)

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x004C0ADC fmodf_guess
float __cdecl fmodf_guess(float first_guess, float second_guess);
// EXTERNAL: TITANIUM 0x0060FAC0 FUN_0060fac0_guess
double __cdecl FUN_0060fac0_guess(double value_guess);
// EXTERNAL: TITANIUM 0x00612B00 FUN_00612b00_guess
double __cdecl FUN_00612b00_guess(double value_guess);

// Destructor view of CNoteWnd, truncated at 0x164 (the full CNoteWnd in types.h is 0x56C).
// Vtable 0x00659210 is stored by the ctor 0x0053AB19 in tu_191. The base is core_decls'
// CSidlScreenWnd (dtor 0x005A3100), not the polymorphic CSidlScreenWndBase: the dtors here store no vtable.
struct CNoteWnd_guess : CSidlScreenWnd {
    /*0x15C*/ char pad_15C_guess[0x4];
    /*0x160*/ CXStr text_guess;
    ~CNoteWnd_guess();
    CNoteWnd_guess* Delete_guess(unsigned int flags_guess);
};

struct Inner_guess {
    // EXTERNAL: TITANIUM 0x005BC3A0 Inner_guess::Invoke_guess
    void Invoke_guess(int value_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x005BCD10 Inner_guess::Process_guess
    void Process_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005BCB90 Inner_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005BB140 Inner_guess::SetCheck
    void SetCheck(bool value_guess);
};

struct StateOwner_guess {
    char padding_guess[0x2B8];
    Inner_guess* first_guess;
    Inner_guess* second_guess;
    Inner_guess* third_guess;
    Inner_guess* fourth_guess;
    Inner_guess* fifth_guess;
    Inner_guess* sixth_guess;
    void RefreshMousePage_guess();
};

struct ActionInterface_guess {
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
    virtual void Slot48_guess(char value_guess, int enabled_guess);
};

struct ActionOwner_guess {
    char padding_guess[0x228];
    ActionInterface_guess* first_guess;
    ActionInterface_guess* second_guess;
    void UpdateAction_guess(char value_guess);
};

struct Outer_guess {
    char padding_guess[0x160];
    Inner_guess* inner_guess;
    void Dispatch_guess(int value_guess);
};

struct DockFrame_guess {
    char padding_guess[0xA9C];
    int firstState_guess;
    int secondState_guess;
    bool IsCapturingKey_guess();
};

struct Entry_guess {
    char* text_guess;
    int value_guess;
    // EXTERNAL: TITANIUM 0x0044830F Entry_guess::~Entry_guess
    ~Entry_guess();
    // EXTERNAL: TITANIUM 0x00571FC0 Entry_guess::SetText_guess
    void SetText_guess(char* text_guess);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7EntrySubfield_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z
struct EntrySubfield_guess {
    // EXTERNAL: TITANIUM 0x005482A0 EntrySubfield_guess::Finalize_guess
    void Finalize_guess(int flags_guess);
    virtual ~EntrySubfield_guess() {
        Finalize_guess(-1);
    }
};

struct EntrySubobject_guess {
    EntrySubfield_guess subfield_guess;
};

struct EntryList_guess : CSidlScreenWnd, EntrySubobject_guess {
    char secondPadding_guess[0x178];
    struct ResultList_guess* results_guess;  // +0x2D8
    struct EntryRows_guess* list_guess;      // +0x2DC
    char thirdPadding_guess[0x4];
    Entry_guess entries_guess[0xF7];
    void ReloadKeyList_guess();
    void Update_guess();
    void SetEntry_guess(int index_guess, int id_guess, int value_guess);
    void InitializeEntries_guess();
    ~EntryList_guess();
    EntryList_guess* Delete_guess(unsigned int flags_guess);
};

struct UpdateBase_guess {
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
};

struct UpdateTarget_guess : UpdateBase_guess {
    virtual void Dispatch_guess(Inner_guess* value_guess, int code_guess, int result_guess);
    char padding_guess[0x2C8];
    Inner_guess* inner_guess;
    void Update_guess();
};

#define g_updateValue_guess EQ_GLOBAL(int, 0x00924990)
#define g_stateOne_guess EQ_GLOBAL(int, 0x00924994)
#define g_stateTwo_guess EQ_GLOBAL(int, 0x00924998)
#define g_stateThree_guess EQ_GLOBAL(int, 0x0092499C)
#define g_stateFour_guess EQ_GLOBAL(int, 0x009254BC)
#define g_stateFive_guess EQ_GLOBAL(char, 0x00923878)

struct Str_guess {
    char* data_guess;
    Str_guess() : data_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct RowList_guess {
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
    // EXTERNAL: TITANIUM 0x0059B9D0 RowList_guess::AddString
    int AddString(const Str_guess& text_guess, int index_guess,
                       int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x0059B360 RowList_guess::SetItemText
    void SetItemText(int row_guess, int column_guess, const Str_guess& text_guess);
};

struct RowEntry_guess {
    int index_guess;  // +0x00
    int textId_guess; // +0x04
    int flag_guess;   // +0x08
};

#define g_rowCount_guess EQ_GLOBAL(int, 0x00793CB4)
#define g_rowEntries_guess EQ_ARRAY(RowEntry_guess, 0x00793B70)
#define g_rowSource_guess EQ_GLOBAL(void*, 0x00905CE4)
#define g_altRowCount_guess EQ_GLOBAL(int, 0x007940B4)
#define g_altRowEntries_guess EQ_ARRAY(RowEntry_guess, 0x00793CB8)

struct RowWindow_guess {
    char padding_guess[0xAA8];
    RowList_guess* rows_guess; // +0xAA8
    void RefreshRows_guess();
};

struct RowHost_guess {
    char padding_guess[0xAC0];
    RowList_guess* rows_guess; // +0xAC0
    void RebuildRows_guess();
};

struct TextService_guess {
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
    virtual char* Lookup_guess(int id_guess, int zero_guess);
};

#define g_textService_guess EQ_GLOBAL(TextService_guess*, 0x0099E360)
#define g_textId_guess EQ_GLOBAL(int, 0x00923D74)
#define g_refreshA_guess EQ_GLOBAL(int, 0x00924988)
#define g_refreshB_guess EQ_GLOBAL(int, 0x00924980)
#define g_refreshC_guess EQ_GLOBAL(int, 0x00924984)

struct Panel_guess {
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
    virtual void SetText_guess(Str_guess& text_guess);
};

struct PaneOwner_guess {
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
    virtual void Dispatch_guess(Inner_guess* value_guess, int code_guess, int result_guess);
    char padding_guess[0x1C4];
    Inner_guess* first_guess;   // +0x1C8
    int gap1_guess;             // +0x1CC
    Inner_guess* second_guess;  // +0x1D0
    int gap2_guess;             // +0x1D4
    Inner_guess* third_guess;   // +0x1D8
    char gap3_guess[0xC];       // +0x1DC
    Panel_guess* panel_guess;   // +0x1E8
    void Refresh_guess();
};

// Scalar deleting destructor. The class is not MFC's CMiniDockFrameWnd: its base dtor 0x005A3100 is
// CSidlScreenWnd's, as for OptionsWnd_guess.
// FUNCTION: TITANIUM 0x0053AC2B
CNoteWnd_guess* CNoteWnd_guess::Delete_guess(unsigned int flags_guess) {
    this->~CNoteWnd_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Destructor of the note window (vtable 0x659210, ctor 0x0053AB19): destroys its text string (+0x160),
// then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0053AC47
CNoteWnd_guess::~CNoteWnd_guess() {
}

// True while a key binding is being captured: the edited row and column (+0xA9C, +0xAA0) are set.
// FUNCTION: TITANIUM 0x0053AC7F
bool DockFrame_guess::IsCapturingKey_guess() {
    return firstState_guess != -1 && secondState_guess != -1;
}

// Rounds half up: ceil when the fraction is at least 0.5, else floor.
// FUNCTION: TITANIUM 0x0053AC98
int __cdecl RoundToInt_guess(float value_guess) {
    float fraction_guess = fmodf_guess(value_guess, 1.0f);
    if (fraction_guess >= 0.5f) {
        return (int)FUN_00612b00_guess(value_guess);
    }
    return (int)FUN_0060fac0_guess(value_guess);
}

// Switches the page tabs (OPTW_OptionsSubwindows, +0x160) to page `value_guess`.
// FUNCTION: TITANIUM 0x0053ACDF
void Outer_guess::Dispatch_guess(int value_guess) {
    inner_guess->Invoke_guess(value_guess, 0);
}

#define g_listA_guess EQ_GLOBAL(int, 0x009254CC)
#define g_flagA_guess EQ_GLOBAL(int, 0x00924978)
#define g_flagB_guess EQ_GLOBAL(int, 0x0092497C)
#define g_flagC_guess EQ_GLOBAL(int, 0x0092496C)
#define g_modeA_guess EQ_GLOBAL(int, 0x00924964)
#define g_boolRef_guess EQ_GLOBAL(bool*, 0x00985CE4)
#define g_charRoot_guess EQ_GLOBAL(CharRoot_guess*, 0x00905D00)
#define g_charSource_guess EQ_GLOBAL(CharSource_guess*, 0x00905CE4)
#define g_scale_guess EQ_GLOBAL(float, 0x00924950)
#define g_valueB_guess EQ_GLOBAL(int, 0x009249AC)
#define g_valueC_guess EQ_GLOBAL(int, 0x009254C8)
#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x0099D3EC)
#define g_levelA_guess EQ_GLOBAL(float, 0x00985810)
#define g_levelB_guess EQ_GLOBAL(float, 0x00985818)
#define g_levelC_guess EQ_GLOBAL(float, 0x00985820)
#define g_levelD_guess EQ_GLOBAL(float, 0x00985828)
#define g_levelE_guess EQ_GLOBAL(float, 0x00985830)
#define g_levelF_guess EQ_GLOBAL(float, 0x00985838)
#define g_percentA_guess EQ_GLOBAL(float, 0x00985814)
#define g_percentB_guess EQ_GLOBAL(float, 0x00985824)
#define g_percentC_guess EQ_GLOBAL(float, 0x00985834)
#define g_slotTable_guess EQ_ARRAY(int, 0x00793B4C)
#define g_slotKeyA_guess EQ_GLOBAL(int, 0x0098581C)
#define g_slotKeyB_guess EQ_GLOBAL(int, 0x0098583C)

struct CharRoot_guess {
    char pad_guess[0x1A5C];
    bool flag_guess;  // +0x1A5C
};

struct CharSource_guess {
    char pad_guess[0x1B8];
    bool flag_guess;  // +0x1B8
};

struct Clock_guess {
    // EXTERNAL: TITANIUM 0x005AE2E0 Clock_guess::Ticks_guess
    unsigned int Ticks_guess();
    // EXTERNAL: TITANIUM 0x005AE2C0 Clock_guess::Rate_guess
    int Rate_guess();
    // EXTERNAL: TITANIUM 0x005AE300 Clock_guess::Byte1_guess
    unsigned char Byte1_guess();
    // EXTERNAL: TITANIUM 0x005AE320 Clock_guess::Byte2_guess
    unsigned char Byte2_guess();
};

struct Level_guess {
    // EXTERNAL: TITANIUM 0x0059C360 Level_guess::Set_guess
    void Set_guess(int value_guess);
};

struct Settings_guess {
    char pad0_guess[0x1F0];
    Level_guess* level1F0_guess;  // +0x1F0
    char pad1_guess[0x0C];
    Inner_guess* ptr200_guess;    // +0x200
    Inner_guess* ptr204_guess;    // +0x204
    Inner_guess* ptr208_guess;    // +0x208
    Inner_guess* ptr20c_guess;    // +0x20C
    Inner_guess* ptr210_guess;    // +0x210
    Inner_guess* ptr214_guess;    // +0x214
    char pad2_guess[0x04];
    Inner_guess* ptr21c_guess;    // +0x21C
    char pad3_guess[0x10];
    Level_guess* level230_guess;  // +0x230
    Inner_guess* ptr234_guess;    // +0x234
    char pad4_guess[0x04];
    Inner_guess* ptr23c_guess;    // +0x23C
    char pad5_guess[0x04];
    Inner_guess* ptr244_guess;    // +0x244
    char pad6_guess[0x04];
    Inner_guess* ptr24c_guess;    // +0x24C
    char pad7_guess[0x0C];
    Inner_guess* ptr25c_guess;    // +0x25C
    char pad8_guess[0x04];
    Level_guess* level264_guess;  // +0x264
    Level_guess* level268_guess;  // +0x268
    Level_guess* level26c_guess;  // +0x26C
    Inner_guess* ptr270_guess;    // +0x270
    char pad9_guess[0x04];
    Level_guess* level278_guess;  // +0x278
    Level_guess* level27c_guess;  // +0x27C
    Inner_guess* ptr280_guess;    // +0x280
    char pad10_guess[0x04];
    Level_guess* level288_guess;  // +0x288
    Level_guess* level28c_guess;  // +0x28C
    Level_guess* level290_guess;  // +0x290
    Inner_guess* ptr294_guess;    // +0x294
    void Refresh_guess();
};


// General page: current-font label from the font manager (0x0099E360, slot 31, font index 0x00923D74)
// and the realism, music and sound sliders. Message 0xE (slider changed) to itself updates the labels.
// FUNCTION: TITANIUM 0x0053ACF3
void PaneOwner_guess::Refresh_guess() {
    if (panel_guess != 0) {
        Str_guess text_guess(g_textService_guess->Lookup_guess(g_textId_guess, 0));
        panel_guess->SetText_guess(text_guess);
    }
    if (first_guess != 0) {
        first_guess->Process_guess(g_refreshA_guess);
        Dispatch_guess(first_guess, 0xE, first_guess->GetValue_guess());
    }
    if (second_guess != 0) {
        second_guess->Process_guess(g_refreshB_guess);
        Dispatch_guess(second_guess, 0xE, second_guess->GetValue_guess());
    }
    if (third_guess != 0) {
        third_guess->Process_guess(g_refreshC_guess);
        Dispatch_guess(third_guess, 0xE, third_guess->GetValue_guess());
    }
}

// Stat getters on the object at 0x0099D3EC.
struct StatSource_guess {
    // EXTERNAL: TITANIUM 0x005AE2E0 StatSource_guess::GetA_guess
    unsigned int GetA_guess();
    // EXTERNAL: TITANIUM 0x005AE2C0 StatSource_guess::GetB_guess
    unsigned int GetB_guess();
    // EXTERNAL: TITANIUM 0x005AE300 StatSource_guess::GetC_guess
    unsigned char GetC_guess();
    // EXTERNAL: TITANIUM 0x005AE320 StatSource_guess::GetD_guess
    unsigned char GetD_guess();
    // EXTERNAL: TITANIUM 0x005AED70 StatSource_guess::SetA_guess
    void SetA_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005AECE0 StatSource_guess::SetB_guess
    void SetB_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005AEE00 StatSource_guess::SetC_guess
    void SetC_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x005AEEA0 StatSource_guess::SetD_guess
    void SetD_guess(int value_guess);
};

struct Pane29C_guess {
    char gap_guess[0x5D];
    char flag_guess;            // +0x5D
};

struct Options_guess {
    char gap_guess[0x124];
    int enabled_guess;          // +0x124
};

#define g_statSource_guess EQ_GLOBAL(StatSource_guess*, 0x0099D3EC)
#define g_options_guess EQ_GLOBAL(Options_guess*, 0x00850C7C)
#define g_floatA_guess EQ_GLOBAL(float, 0x00924950)
#define g_dispatchA_guess EQ_GLOBAL(int, 0x009249AC)
#define g_dispatchB_guess EQ_GLOBAL(int, 0x009254C4)
#define g_dispatchC_guess EQ_GLOBAL(int, 0x009254C8)
#define g_scaleA_guess EQ_GLOBAL(float, 0x00985814)
#define g_scaleB_guess EQ_GLOBAL(float, 0x00985824)
#define g_scaleC_guess EQ_GLOBAL(float, 0x00985834)

struct PaneOwnerWide_guess : PaneOwner_guess {
    char pad0_guess[0x28];
    Inner_guess* inner214_guess;        // +0x214
    char pad1_guess[4];
    Inner_guess* inner21C_guess;        // +0x21C
    char pad2_guess[0x14];
    Inner_guess* inner234_guess;        // +0x234
    char pad3_guess[4];
    Inner_guess* inner23C_guess;        // +0x23C
    char pad4_guess[4];
    Inner_guess* inner244_guess;        // +0x244
    char pad5_guess[4];
    Inner_guess* inner24C_guess;        // +0x24C
    char pad6_guess[4];
    Inner_guess* inner254_guess;        // +0x254
    char pad7_guess[4];
    Inner_guess* inner25C_guess;        // +0x25C
    char pad8_guess[0x10];
    Inner_guess* inner270_guess;        // +0x270
    char pad9_guess[0xC];
    Inner_guess* inner280_guess;        // +0x280
    char pad10_guess[0x10];
    Inner_guess* inner294_guess;        // +0x294
    char pad11_guess[4];
    Pane29C_guess* pane29C_guess;       // +0x29C
    void RefreshAll_guess();
};

// Display page sliders: clip plane, gamma (1-based), fade delay and duration (500 ms steps), window
// alpha (26-255), fade-to-alpha, max FPS (10 + n), LOD bias and the three particle opacities in percent.
// Without the advanced-display window (0x00850C7C) or its SIDL piece, ODP_AdvancedButton's +0x5D is
// cleared, probably disabling it.
// FUNCTION: TITANIUM 0x0053ADFC
void PaneOwnerWide_guess::RefreshAll_guess() {
    if ((g_options_guess == 0 || g_options_guess->enabled_guess == 0) && pane29C_guess != 0) {
        pane29C_guess->flag_guess = 0;
    }
    if (inner21C_guess != 0) {
        inner21C_guess->Process_guess(g_dispatchA_guess);
        Dispatch_guess(inner21C_guess, 0xE, inner21C_guess->GetValue_guess());
    }
    if (inner214_guess != 0) {
        inner214_guess->Process_guess((int)g_floatA_guess - 1);
        Dispatch_guess(inner214_guess, 0xE, inner214_guess->GetValue_guess());
    }
    if (inner234_guess != 0) {
        inner234_guess->Process_guess(g_statSource_guess->GetA_guess() / 500);
        Dispatch_guess(inner234_guess, 0xE, inner234_guess->GetValue_guess());
    }
    if (inner23C_guess != 0) {
        inner23C_guess->Process_guess((g_statSource_guess->GetB_guess() - 500) / 500);
        Dispatch_guess(inner23C_guess, 0xE, inner23C_guess->GetValue_guess());
    }
    if (inner244_guess != 0) {
        inner244_guess->Process_guess(g_statSource_guess->GetC_guess() - 0x1A);
        Dispatch_guess(inner244_guess, 0xE, inner244_guess->GetValue_guess());
    }
    if (inner24C_guess != 0) {
        inner24C_guess->Process_guess(g_statSource_guess->GetD_guess());
        Dispatch_guess(inner24C_guess, 0xE, inner24C_guess->GetValue_guess());
    }
    if (inner254_guess != 0) {
        inner254_guess->Process_guess(g_dispatchB_guess - 10);
        Dispatch_guess(inner254_guess, 0xE, inner254_guess->GetValue_guess());
    }
    if (inner25C_guess != 0) {
        inner25C_guess->Process_guess(g_dispatchC_guess);
        Dispatch_guess(inner25C_guess, 0xE, inner25C_guess->GetValue_guess());
    }
    if (inner270_guess != 0) {
        inner270_guess->Process_guess(RoundToInt_guess(g_scaleA_guess * 100.0));
        Dispatch_guess(inner270_guess, 0xE, inner270_guess->GetValue_guess());
    }
    if (inner280_guess != 0) {
        inner280_guess->Process_guess(RoundToInt_guess(g_scaleB_guess * 100.0));
        Dispatch_guess(inner280_guess, 0xE, inner280_guess->GetValue_guess());
    }
    if (inner294_guess != 0) {
        inner294_guess->Process_guess(RoundToInt_guess(g_scaleC_guess * 100.0));
        Dispatch_guess(inner294_guess, 0xE, inner294_guess->GetValue_guess());
    }
}

// Mouse sensitivity slider (+0x2CC) from the 1-8 setting, with the label update.
// FUNCTION: TITANIUM 0x0053B0DF
void UpdateTarget_guess::Update_guess() {
    if (inner_guess != 0) {
        inner_guess->Process_guess(g_updateValue_guess - 1);
        Dispatch_guess(inner_guess, 0xE, inner_guess->GetValue_guess());
    }
}

// Chat page: refills FilterList (+0xAA8) from the filter table 0x00793B70 (12-byte rows: id, string id,
// hidden). Empty without a local player.
// FUNCTION: TITANIUM 0x0053B11A
void RowWindow_guess::RefreshRows_guess() {
    if (rows_guess != 0) {
        rows_guess->Slot76_guess();
        for (int i = 0; i < g_rowCount_guess; ++i) {
            if (g_rowSource_guess != 0 && g_rowEntries_guess[i].flag_guess == 0) {
                Str_guess text(pStringTable->getString(
                    g_rowEntries_guess[i].textId_guess, 0));
                rows_guess->AddString(
                    text, -1, g_rowEntries_guess[i].index_guess, 0);
            }
        }
    }
}

// Color page: refills ColorChooseList (+0xAC0) from the user-colour table 0x00793CB8. Item data is the
// row id - 0x100; column 1 gets string 0x17F6, the sample text RefreshColorSamples paints.
// FUNCTION: TITANIUM 0x0053B1CA
void RowHost_guess::RebuildRows_guess() {
    if (rows_guess != 0) {
        rows_guess->Slot76_guess();
        for (int i = 0; i < g_altRowCount_guess; ++i) {
            RowEntry_guess* entry = &g_altRowEntries_guess[i];
            if (g_rowSource_guess != 0 && entry->flag_guess == 0) {
                int row;
                {
                    Str_guess text(pStringTable->getString(entry->textId_guess, 0));
                    row = rows_guess->AddString(text, -1, entry->index_guess - 0x100, 0);
                }
                Str_guess value(pStringTable->getString(0x17F6, 0));
                rows_guess->SetItemText(row, 1, value);
            }
        }
    }
}

// Display page controls from their globals: name and target-ring checkboxes, LOD (0x0092496C), show
// helm (pCharData +0x1A5C, else the local player +0x1B8), load-screen and sky combos, then the particle
// combos. Density 0/0.25/0.5/1.0 and near clip 2/4/6/8 become combo rows 0-3; a cast filter is its
// index in the 8-entry table 0x00793B4C (7 when not found). The sliders mirror RefreshAll_guess.
// FUNCTION: TITANIUM 0x0053B846
// @early-stop: budget, structural ndiff=156
void Settings_guess::Refresh_guess() {
    if (ptr200_guess != 0) {
        ptr200_guess->SetCheck(g_flagA_guess == 1);
    }
    if (ptr204_guess != 0) {
        ptr204_guess->SetCheck(g_flagB_guess == 1);
    }
    if (ptr208_guess != 0 && g_boolRef_guess != 0) {
        ptr208_guess->SetCheck(*g_boolRef_guess);
    }
    if (ptr20c_guess != 0) {
        ptr20c_guess->SetCheck(g_flagC_guess == 1);
    }
    if (ptr210_guess != 0) {
        bool value_guess = true;
        if (g_charRoot_guess != 0) {
            value_guess = g_charRoot_guess->flag_guess;
        } else if (g_charSource_guess != 0) {
            value_guess = g_charSource_guess->flag_guess;
        }
        ptr210_guess->SetCheck(value_guess);
    }
    if (level1F0_guess != 0) {
        level1F0_guess->Set_guess(g_listA_guess);
    }
    if (level230_guess != 0) {
        int mode_guess;
        switch (g_modeA_guess) {
        case 0:
            mode_guess = 0;
            break;
        case 1:
            mode_guess = 1;
            break;
        case 2:
            mode_guess = 2;
            break;
        default:
            mode_guess = 0;
            break;
        }
        level230_guess->Set_guess(mode_guess);
    }
    if (level268_guess != 0) {
        int level_guess;
        if (g_levelB_guess <= 2.0f) {
            level_guess = 0;
        } else if (g_levelB_guess <= 4.0f) {
            level_guess = 1;
        } else if (g_levelB_guess <= 6.0f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level268_guess->Set_guess(level_guess);
    }
    if (level264_guess != 0) {
        int level_guess;
        if (g_levelA_guess <= 0.0f) {
            level_guess = 0;
        } else if (g_levelA_guess <= 0.25f) {
            level_guess = 1;
        } else if (g_levelA_guess <= 0.5f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level264_guess->Set_guess(level_guess);
    }
    if (level26c_guess != 0) {
        int slot_guess = 7;
        for (int i_guess = 0; i_guess < 8; ++i_guess) {
            if (g_slotTable_guess[i_guess] == g_slotKeyA_guess) {
                slot_guess = i_guess;
                break;
            }
        }
        level26c_guess->Set_guess(slot_guess);
    }
    if (level27c_guess != 0) {
        int level_guess;
        if (g_levelD_guess <= 2.0f) {
            level_guess = 0;
        } else if (g_levelD_guess <= 4.0f) {
            level_guess = 1;
        } else if (g_levelD_guess <= 6.0f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level27c_guess->Set_guess(level_guess);
    }
    if (level278_guess != 0) {
        int level_guess;
        if (g_levelC_guess <= 0.0f) {
            level_guess = 0;
        } else if (g_levelC_guess <= 0.25f) {
            level_guess = 1;
        } else if (g_levelC_guess <= 0.5f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level278_guess->Set_guess(level_guess);
    }
    if (level28c_guess != 0) {
        int level_guess;
        if (g_levelF_guess <= 2.0f) {
            level_guess = 0;
        } else if (g_levelF_guess <= 4.0f) {
            level_guess = 1;
        } else if (g_levelF_guess <= 6.0f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level28c_guess->Set_guess(level_guess);
    }
    if (level288_guess != 0) {
        int level_guess;
        if (g_levelE_guess <= 0.0f) {
            level_guess = 0;
        } else if (g_levelE_guess <= 0.25f) {
            level_guess = 1;
        } else if (g_levelE_guess <= 0.5f) {
            level_guess = 2;
        } else {
            level_guess = 3;
        }
        level288_guess->Set_guess(level_guess);
    }
    if (level290_guess != 0) {
        int slot_guess = 7;
        for (int i_guess = 0; i_guess < 8; ++i_guess) {
            if (g_slotTable_guess[i_guess] == g_slotKeyB_guess) {
                slot_guess = i_guess;
                break;
            }
        }
        level290_guess->Set_guess(slot_guess);
    }
    if (ptr214_guess != 0) {
        ptr214_guess->Process_guess((int)g_scale_guess - 1);
    }
    if (ptr21c_guess != 0) {
        ptr21c_guess->Process_guess(g_valueB_guess);
    }
    if (ptr234_guess != 0) {
        unsigned int ticks_guess = g_clock_guess->Ticks_guess();
        ptr234_guess->Process_guess(ticks_guess / 500);
    }
    if (ptr23c_guess != 0) {
        int ticks_guess = g_clock_guess->Rate_guess();
        ptr23c_guess->Process_guess((ticks_guess - 500U) / 500);
    }
    if (ptr244_guess != 0) {
        ptr244_guess->Process_guess((int)g_clock_guess->Byte1_guess() - 0x1a);
    }
    if (ptr24c_guess != 0) {
        ptr24c_guess->Process_guess(g_clock_guess->Byte2_guess());
    }
    if (ptr25c_guess != 0) {
        ptr25c_guess->Process_guess(g_valueC_guess);
    }
    if (ptr270_guess != 0) {
        int value_guess = RoundToInt_guess(g_percentA_guess * 100.0);
        ptr270_guess->Process_guess(value_guess);
    }
    if (ptr280_guess != 0) {
        int value_guess = RoundToInt_guess(g_percentB_guess * 100.0);
        ptr280_guess->Process_guess(value_guess);
    }
    if (ptr294_guess != 0) {
        int value_guess = RoundToInt_guess(g_percentC_guess * 100.0);
        ptr294_guess->Process_guess(value_guess);
    }
}

// Mouse page: invert Y, look spring, mouse look, wheel zoom and handedness checkboxes, sensitivity slider.
// FUNCTION: TITANIUM 0x0053BCF0
void StateOwner_guess::RefreshMousePage_guess() {
    if (first_guess != 0) {
        first_guess->SetCheck(g_stateOne_guess == 1);
    }
    if (second_guess != 0) {
        second_guess->SetCheck(g_stateTwo_guess == 1);
    }
    if (third_guess != 0) {
        third_guess->SetCheck(g_stateThree_guess == 1);
    }
    if (fourth_guess != 0) {
        fourth_guess->SetCheck(g_stateFour_guess == 1);
    }
    if (fifth_guess != 0) {
        fifth_guess->SetCheck(g_stateFive_guess == 1);
    }
    if (sixth_guess != 0) {
        sixth_guess->Process_guess(g_updateValue_guess - 1);
    }
}

struct ChannelTable_guess {
    // EXTERNAL: TITANIUM 0x0060CA30 ChannelTable_guess::Find_guess
    int Find_guess(int id_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x0060CA60 ChannelTable_guess::Count_guess
    int Count_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0060CA70 ChannelTable_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0060CAC0 ChannelTable_guess::SetValue_guess
    void SetValue_guess(int index_guess, int value_guess);
};

#define g_channelTable_guess EQ_GLOBAL(ChannelTable_guess, 0x009248E0)

struct ResultList_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 ResultList_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 ResultList_guess::Add_guess
    void Add_guess(const CXStr* text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 ResultList_guess::Finish_guess
    void Finish_guess(int value_guess);
};

struct ChannelPanel_guess {
    char padding_guess[0xAA8];
    CListWnd* list_guess;             // +0xAA8
    union {
        ResultList_guess* results_guess;  // +0xAAC (ApplyChannel)
        CXWnd* button_guess;              // +0xAAC (Refresh)
    };
    void Refresh_guess();
    int ChatPageWndNotification_guess(void* target_guess, int count_guess, int id_guess);
};

// Chat page: column 1 of each filter row shows the name of its current choice; FilterComboBox (+0xAAC)
// is enabled only while a row is selected.
// FUNCTION: TITANIUM 0x0053BD8D
void ChannelPanel_guess::Refresh_guess() {
    if (list_guess != 0) {
        int count_guess = list_guess->ItemsCount;
        int i = 0;
        if (0 < count_guess) {
            do {
                {
                    unsigned int id_guess = list_guess->GetItemData(i);
                    int name_guess = g_channelTable_guess.Find_guess(
                        id_guess, g_channelTable_guess.GetValue_guess(id_guess));
                    CXStr text(pStringTable->getString(name_guess, 0));
                    list_guess->SetItemText(i, 1, text);
                }
                ++i;
            } while (i < list_guess->ItemsCount);
        }
        if (button_guess != 0) {
            button_guess->Enabled = list_guess->GetCurSel() != -1;
        }
    }
}

// Key command `index_guess` (0-246): display name (string id) and filter-category mask.
// FUNCTION: TITANIUM 0x0053BF04
void EntryList_guess::SetEntry_guess(int index_guess, int id_guess, int value_guess) {
    if (index_guess >= 0 && index_guess < 0xF7) {
        entries_guess[index_guess].SetText_guess(pStringTable->getString(id_guess, 0));
        entries_guess[index_guess].value_guess = value_guess;
    }
}

// Slot 48 (probably CXWnd::Show) on ODP_SetWindowedButton with the 0x0099E38C +4 flag and on
// ODP_SetFullscreenButton with its inverse. tu_023's /fullscreen treats that flag as fullscreen, so
// IsWindowed_guess is probably the wrong way round and each button shows only when it would change mode.
// FUNCTION: TITANIUM 0x0053CA42
void ActionOwner_guess::UpdateAction_guess(char value_guess) {
    if (first_guess != 0 && second_guess != 0) {
        second_guess->Slot48_guess(value_guess, 1);
        first_guess->Slot48_guess(value_guess == 0, 1);
    }
}

struct OptionPage_guess;

struct IniConfig_guess {
    // EXTERNAL: TITANIUM 0x004AEC1A IniConfig_guess::WriteChannels_guess
    void WriteChannels_guess(int channel_guess);
    // EXTERNAL: TITANIUM 0x004966EE IniConfig_guess::send_update_filters_guess
    void send_update_filters_guess();
    // EXTERNAL: TITANIUM 0x00495250 IniConfig_guess::GetOptionPage_guess
    OptionPage_guess* GetOptionPage_guess();
    // EXTERNAL: TITANIUM 0x004AE514 IniConfig_guess::WriteInt_guess
    void WriteInt_guess(int value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE55F IniConfig_guess::WriteFloat_guess
    void WriteFloat_guess(float value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE5AF IniConfig_guess::WriteBool_guess
    void WriteBool_guess(unsigned char value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE82A IniConfig_guess::WriteMainBool_guess
    void WriteMainBool_guess(unsigned char value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE848 IniConfig_guess::WriteCharIniString_guess
    void WriteCharIniString_guess(const char* value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x00496731 IniConfig_guess::SendAutoSplit_guess
    void SendAutoSplit_guess();
    // EXTERNAL: TITANIUM 0x004A1350 IniConfig_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int reason_guess);
};

#define g_iniConfig_guess EQ_GLOBAL(IniConfig_guess*, 0x00988DF0)

// Chat page WndNotification (message 1 = click): picking in FilterComboBox sets the selected filter's
// choice and saves it (WriteChannels_guess); clicking a FilterList row fills the combo with that filter's
// choices. Here `count_guess` is the message and `id_guess` the combo index.
// FUNCTION: TITANIUM 0x0053CC29
int ChannelPanel_guess::ChatPageWndNotification_guess(void* target_guess, int count_guess, int id_guess) {
    bool done_guess = false;
    if (count_guess == 1) {
        if (target_guess == results_guess && list_guess != 0) {
            int item_guess = list_guess->GetCurSel();
            if (item_guess != -1) {
                item_guess = list_guess->GetItemData(item_guess);
                if (item_guess != -1) {
                    g_channelTable_guess.SetValue_guess(item_guess, id_guess);
                    g_iniConfig_guess->WriteChannels_guess(item_guess);
                    Refresh_guess();
                    done_guess = true;
                }
            }
        }
        if (target_guess == list_guess && list_guess != 0) {
            int sel_guess = list_guess->GetCurSel();
            if (sel_guess != -1) {
                id_guess = list_guess->GetItemData(sel_guess);
                if (id_guess != -1 && results_guess != 0) {
                    count_guess = g_channelTable_guess.Count_guess(id_guess);
                    results_guess->Reset_guess();
                    for (int i = 0; i < count_guess; ++i) {
                        CXStr text_guess(pStringTable->getString(g_channelTable_guess.Find_guess(id_guess, i), 0));
                        results_guess->Add_guess(&text_guess);
                    }
                    results_guess->Finish_guess(g_channelTable_guess.GetValue_guess(id_guess));
                }
            }
        }
        if (done_guess) {
            g_iniConfig_guess->send_update_filters_guess();
        }
    }
    return 0;
}

// Sets user colour `user_guess` (0-based) and saves it to .\eqclient.ini as [TextColors]
// User_<n>_Red, _Green and _Blue (n 1-based).
// FUNCTION: TITANIUM 0x0053CFBA
void TextColors_guess::SetColorOptions_guess(int user_guess, int text_guess, int green_guess, int blue_guess) {
    char userName_guess[16];
    char colorKey_guess[32];
    char value_guess[16];

    SetColors_guess(user_guess, text_guess, green_guess, blue_guess);

    sprintf(userName_guess, "User_%d_", user_guess + 1);
    CopyText_guess(colorKey_guess, userName_guess);
    AppendText_guess(colorKey_guess, g_colorSuffix_guess);
    sprintf(value_guess, g_colorFormat_guess, text_guess);
    WriteIniText_guess(g_textColors_guess, colorKey_guess, value_guess, g_eqClientIni_guess);

    CopyText_guess(colorKey_guess, userName_guess);
    AppendText_guess(colorKey_guess, "Green");
    sprintf(value_guess, g_colorFormat_guess, green_guess);
    WriteIniText_guess(g_textColors_guess, colorKey_guess, value_guess, g_eqClientIni_guess);

    CopyText_guess(colorKey_guess, userName_guess);
    AppendText_guess(colorKey_guess, g_colorBlue_guess);
    sprintf(value_guess, g_colorFormat_guess, blue_guess);
    WriteIniText_guess(g_textColors_guess, colorKey_guess, value_guess, g_eqClientIni_guess);
}

// Restores all 86 user colours (0x56) to their defaults and saves them; the Yes answer to the
// UserColorDefault confirmation (dialog id 101).
// FUNCTION: TITANIUM 0x0053D0B9
void TextColors_guess::RestoreDefaultColors_guess() {
    int blue_guess;
    int green_guess;
    int text_guess;
    int user_guess = 0;

    do {
        GetDefaultUserDefinedColor_guess(user_guess, &text_guess, &green_guess, &blue_guess);
        SetColorOptions_guess(user_guess, text_guess, green_guess, blue_guess);
        ++user_guess;
    } while (user_guess < 0x56);
}

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(Str_guess* text_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060BF20 FUN_0060bf20_guess
void __cdecl FUN_0060bf20_guess(const char* section, const char* key, const char* value);

#define g_valueFormat_guess EQ_ARRAY(char, 0x0063F53C)

struct BagOptions_guess {
    char padding_guess[0x2A0];
    unsigned int statC_guess;   // +0x2A0
    unsigned int statD_guess;   // +0x2A4
    int statA_guess;            // +0x2A8
    int statB_guess;            // +0x2AC
    int tick_guess;             // +0x2B0
    void WriteBagFadeSetting_guess(int value_guess, int option_guess);
    int RefreshDisplayPage_guess();
};

// Copies one window-fade setting to the bag windows' INI sections: option 0 Delay, 1 Duration, 2 Alpha,
// 3 FadeToAlpha. Sections: BagInv1-8, BagBank1-8, BagTrade1-16, then the world and view-PC bags.
// FUNCTION: TITANIUM 0x0053D0F5
void BagOptions_guess::WriteBagFadeSetting_guess(int value_guess, int option_guess) {
    Str_guess bag_guess;
    Str_guess text_guess;

    FormatString_guess(&text_guess, g_valueFormat_guess, value_guess);
    for (int bank_guess = 0; bank_guess < 6; ++bank_guess) {
        for (int slot_guess = 0; slot_guess < 16; ++slot_guess) {
            if (bank_guess == 0) {
                if (slot_guess == 8) {
                    break;
                }
                FormatString_guess(&bag_guess, "BagInv%d", slot_guess + 1);
            } else if (bank_guess == 1) {
                if (slot_guess == 8) {
                    break;
                }
                FormatString_guess(&bag_guess, "BagBank%d", slot_guess + 1);
            } else if (bank_guess == 2) {
                FormatString_guess(&bag_guess, "BagTrade%d", slot_guess + 1);
            } else if (bank_guess == 3) {
                if (slot_guess == 8) {
                    break;
                }
                // The world and view-PC sections get a fixed number (4, 5, 6) instead of the slot, so each
                // is written eight times and the other numbers are never updated: kept as in the original.
                FormatString_guess(&bag_guess, "BagWorld%d", 4);
            } else if (bank_guess == 4) {
                if (slot_guess == 8) {
                    break;
                }
                FormatString_guess(&bag_guess, "BagViewPC%d", 5);
            } else if (bank_guess == 5) {
                if (slot_guess == 8) {
                    break;
                }
                FormatString_guess(&bag_guess, "BagViewPCBank%d", 6);
            }
            switch (option_guess) {
            case 3:
                FUN_0060bf20_guess(bag_guess.GetText_guess(), "FadeToAlpha", text_guess.GetText_guess());
                break;
            case 2:
                FUN_0060bf20_guess(bag_guess.GetText_guess(), "Alpha", text_guess.GetText_guess());
                break;
            case 1:
                FUN_0060bf20_guess(bag_guess.GetText_guess(), "Duration", text_guess.GetText_guess());
                break;
            case 0:
                FUN_0060bf20_guess(bag_guess.GetText_guess(), "Delay", text_guess.GetText_guess());
                break;
            }
        }
    }
}

struct GlobalStatus_guess {
    // EXTERNAL: TITANIUM 0x00434495 GlobalStatus_guess::IsTributeAvailable_guess
    char IsTributeAvailable_guess();
};

#define g_globalStatus_guess EQ_ARRAY(GlobalStatus_guess, 0x00850350)
#define g_enableExtraEntries_guess EQ_GLOBAL(int, 0x009247B0)
#define g_enableEntryC6_guess EQ_GLOBAL(int, 0x009247A4)
#define g_enableEntryCA_guess EQ_GLOBAL(int, 0x009247A8)
#define g_enableEntryD7DA_guess EQ_GLOBAL(int, 0x009247AC)

// Fills the key-command table: command index, name string id, category mask. The masks match the filter
// combo's rows in EntryList_guess::Update_guess (1, 2, 4 ... 0x400; 0x800 for row 12). Commands
// 0x23-0x72 are two 10-name groups repeated under masks 0x80-0x400
// (HOT1_1-HOT4_10 and HOTPAGE1_1-HOTPAGE4_10 in the command-name table at 0x00789908; bank n under
// mask 0x80 << (n - 1)). Five
// optional groups depend on feature flags (0x009247A4-0x009247B0) and 0x00850350's IsTributeAvailable_guess.
// FUNCTION: TITANIUM 0x0053D265
void EntryList_guess::InitializeEntries_guess() {
    // The keyboard page's list: key-map command id (as in ExecuteCmd), its name string, and a bit mask
    // of the category lists it shows in (1, 2, 4, 8 ... 0x400; 0x44 means two lists).
    SetEntry_guess(2, 0x1964, 1);
    SetEntry_guess(3, 0x1965, 1);
    SetEntry_guess(5, 0x1967, 1);
    SetEntry_guess(4, 0x1966, 1);
    SetEntry_guess(6, 0xff9, 1);
    SetEntry_guess(7, 0xffa, 1);
    SetEntry_guess(0, 0x1968, 1);
    SetEntry_guess(1, 0x1969, 1);
    SetEntry_guess(0xc, 0x196a, 1);
    SetEntry_guess(0x11, 0x196b, 1);
    SetEntry_guess(0x12, 0x196c, 1);
    SetEntry_guess(0x13, 0x196d, 1);
    SetEntry_guess(10, 0x196e, 2);
    SetEntry_guess(0x10, 0x196f, 2);
    SetEntry_guess(0xb, 0x1970, 2);
    SetEntry_guess(0x86, 0x1971, 2);
    SetEntry_guess(0x87, 0x1972, 2);
    SetEntry_guess(0x88, 0x1973, 2);
    SetEntry_guess(0x89, 0x1974, 2);
    SetEntry_guess(0x8a, 0x1975, 2);
    SetEntry_guess(0x8b, 0x1976, 2);
    SetEntry_guess(0x18, 0x198f, 8);
    SetEntry_guess(0x19, 0x1990, 8);
    SetEntry_guess(0x1a, 0x1991, 8);
    SetEntry_guess(0x1b, 0x1992, 8);
    SetEntry_guess(0x1c, 0x1993, 8);
    SetEntry_guess(0x1d, 0x1994, 8);
    SetEntry_guess(0x1e, 0x1995, 8);
    SetEntry_guess(0x1f, 0x33f8, 8);
    SetEntry_guess(0x20, 0x1996, 8);
    SetEntry_guess(0x21, 0x33f9, 8);
    SetEntry_guess(0x80, 0x1997, 8);
    SetEntry_guess(0xbe, 0xfcb, 8);
    SetEntry_guess(0x90, 0x197b, 0x20);
    SetEntry_guess(0x91, 0x197c, 0x20);
    SetEntry_guess(0x92, 0x197d, 0x20);
    SetEntry_guess(0x93, 0x197e, 0x20);
    SetEntry_guess(0x94, 0x197f, 0x20);
    SetEntry_guess(0x95, 0x1980, 0x20);
    SetEntry_guess(0xd, 0x1981, 0x20);
    SetEntry_guess(0xf, 0x1982, 0x20);
    SetEntry_guess(0x7c, 0x1984, 0x20);
    SetEntry_guess(0x7d, 0x1985, 0x20);
    SetEntry_guess(0x7e, 0x1986, 0x20);
    SetEntry_guess(0xa6, 0x1983, 0x28);
    SetEntry_guess(0x8e, 0x1987, 0x20);
    SetEntry_guess(0x16, 0x1988, 0x10);
    SetEntry_guess(0xc0, 0x251c, 0x10);
    SetEntry_guess(0xc1, 0x251d, 0x10);
    SetEntry_guess(0xc2, 0x251e, 0x10);
    SetEntry_guess(0xc3, 0x251f, 0x10);
    SetEntry_guess(0xc4, 0x2520, 0x10);
    SetEntry_guess(0xc5, 0x2521, 0x10);
    SetEntry_guess(0x14, 0x1989, 0x10);
    SetEntry_guess(0x15, 0x198a, 0x10);
    SetEntry_guess(0xb1, 0x1a24, 0x10);
    SetEntry_guess(0xb2, 0x1a25, 0x10);
    SetEntry_guess(0xb4, 0x1a27, 0x10);
    SetEntry_guess(0xb3, 0x1a26, 0x10);
    SetEntry_guess(0xb5, 0x1a28, 0x10);
    SetEntry_guess(0xb6, 0x1a29, 0x10);
    SetEntry_guess(8, 0x198b, 0x11);
    SetEntry_guess(9, 0x1a72, 1);
    SetEntry_guess(0x8c, 0x198c, 0x10);
    SetEntry_guess(0x8d, 0x198d, 0x10);
    SetEntry_guess(0x8f, 0x198e, 0x10);
    SetEntry_guess(0x23, 0x1998, 0x80);
    SetEntry_guess(0x24, 0x1999, 0x80);
    SetEntry_guess(0x25, 0x199a, 0x80);
    SetEntry_guess(0x26, 0x199b, 0x80);
    SetEntry_guess(0x27, 0x199c, 0x80);
    SetEntry_guess(0x28, 0x199d, 0x80);
    SetEntry_guess(0x29, 0x199e, 0x80);
    SetEntry_guess(0x2a, 0x199f, 0x80);
    SetEntry_guess(0x2b, 0x19a0, 0x80);
    SetEntry_guess(0x2c, 0x19a1, 0x80);
    SetEntry_guess(0x2d, 0x1998, 0x100);
    SetEntry_guess(0x2e, 0x1999, 0x100);
    SetEntry_guess(0x2f, 0x199a, 0x100);
    SetEntry_guess(0x30, 0x199b, 0x100);
    SetEntry_guess(0x31, 0x199c, 0x100);
    SetEntry_guess(0x32, 0x199d, 0x100);
    SetEntry_guess(0x33, 0x199e, 0x100);
    SetEntry_guess(0x34, 0x199f, 0x100);
    SetEntry_guess(0x35, 0x19a0, 0x100);
    SetEntry_guess(0x36, 0x19a1, 0x100);
    SetEntry_guess(0x37, 0x1998, 0x200);
    SetEntry_guess(0x38, 0x1999, 0x200);
    SetEntry_guess(0x39, 0x199a, 0x200);
    SetEntry_guess(0x3a, 0x199b, 0x200);
    SetEntry_guess(0x3b, 0x199c, 0x200);
    SetEntry_guess(0x3c, 0x199d, 0x200);
    SetEntry_guess(0x3d, 0x199e, 0x200);
    SetEntry_guess(0x3e, 0x199f, 0x200);
    SetEntry_guess(0x3f, 0x19a0, 0x200);
    SetEntry_guess(0x40, 0x19a1, 0x200);
    SetEntry_guess(0x41, 0x1998, 0x400);
    SetEntry_guess(0x42, 0x1999, 0x400);
    SetEntry_guess(0x43, 0x199a, 0x400);
    SetEntry_guess(0x44, 0x199b, 0x400);
    SetEntry_guess(0x45, 0x199c, 0x400);
    SetEntry_guess(0x46, 0x199d, 0x400);
    SetEntry_guess(0x47, 0x199e, 0x400);
    SetEntry_guess(0x48, 0x199f, 0x400);
    SetEntry_guess(0x49, 0x19a0, 0x400);
    SetEntry_guess(0x4a, 0x19a1, 0x400);
    SetEntry_guess(0x4b, 0x19a2, 0x80);
    SetEntry_guess(0x4c, 0x19a3, 0x80);
    SetEntry_guess(0x4d, 0x19a4, 0x80);
    SetEntry_guess(0x4e, 0x19a5, 0x80);
    SetEntry_guess(0x4f, 0x19a6, 0x80);
    SetEntry_guess(0x50, 0x19a7, 0x80);
    SetEntry_guess(0x51, 0x19a8, 0x80);
    SetEntry_guess(0x52, 0x19a9, 0x80);
    SetEntry_guess(0x53, 0x19aa, 0x80);
    SetEntry_guess(0x54, 0x19ab, 0x80);
    SetEntry_guess(0x55, 0x19a2, 0x100);
    SetEntry_guess(0x56, 0x19a3, 0x100);
    SetEntry_guess(0x57, 0x19a4, 0x100);
    SetEntry_guess(0x58, 0x19a5, 0x100);
    SetEntry_guess(0x59, 0x19a6, 0x100);
    SetEntry_guess(0x5a, 0x19a7, 0x100);
    SetEntry_guess(0x5b, 0x19a8, 0x100);
    SetEntry_guess(0x5c, 0x19a9, 0x100);
    SetEntry_guess(0x5d, 0x19aa, 0x100);
    SetEntry_guess(0x5e, 0x19ab, 0x100);
    SetEntry_guess(0x5f, 0x19a2, 0x200);
    SetEntry_guess(0x60, 0x19a3, 0x200);
    SetEntry_guess(0x61, 0x19a4, 0x200);
    SetEntry_guess(0x62, 0x19a5, 0x200);
    SetEntry_guess(99, 0x19a6, 0x200);
    SetEntry_guess(100, 0x19a7, 0x200);
    SetEntry_guess(0x65, 0x19a8, 0x200);
    SetEntry_guess(0x66, 0x19a9, 0x200);
    SetEntry_guess(0x67, 0x19aa, 0x200);
    SetEntry_guess(0x68, 0x19ab, 0x200);
    SetEntry_guess(0x69, 0x19a2, 0x400);
    SetEntry_guess(0x6a, 0x19a3, 0x400);
    SetEntry_guess(0x6b, 0x19a4, 0x400);
    SetEntry_guess(0x6c, 0x19a5, 0x400);
    SetEntry_guess(0x6d, 0x19a6, 0x400);
    SetEntry_guess(0x6e, 0x19a7, 0x400);
    SetEntry_guess(0x6f, 0x19a8, 0x400);
    SetEntry_guess(0x70, 0x19a9, 0x400);
    SetEntry_guess(0x71, 0x19aa, 0x400);
    SetEntry_guess(0x72, 0x19ab, 0x400);
    SetEntry_guess(0x73, 0x19ac, 4);
    SetEntry_guess(0x74, 0x19ad, 4);
    SetEntry_guess(0x75, 0x19ae, 4);
    SetEntry_guess(0x76, 0x19af, 4);
    SetEntry_guess(0x77, 0x19b0, 4);
    SetEntry_guess(0x78, 0x19b1, 4);
    SetEntry_guess(0x79, 0x19b2, 4);
    SetEntry_guess(0x7a, 0x19b3, 4);
    SetEntry_guess(0x7b, 0x244c, 4);
    SetEntry_guess(0xd9, 0xde7, 4);
    SetEntry_guess(0xa3, 0x19b4, 0x40);
    SetEntry_guess(0xa9, 0x19c9, 0x40);
    SetEntry_guess(0xe, 0x19b9, 0x40);
    SetEntry_guess(0x9c, 0x19bb, 0xc0);
    SetEntry_guess(0x9d, 0x1829, 0x140);
    SetEntry_guess(0x9e, 0x182a, 0x240);
    SetEntry_guess(0x9f, 0x182b, 0x440);
    SetEntry_guess(0x9b, 0x19bc, 0x40);
    SetEntry_guess(0xb8, 0x234a, 0x40);
    SetEntry_guess(0xa7, 0x19c7, 0x40);
    SetEntry_guess(0x81, 0x19be, 0x44);
    SetEntry_guess(0x9a, 0x19ba, 0x44);
    SetEntry_guess(0xa8, 0x19c8, 0x40);
    SetEntry_guess(0xa4, 0x19bf, 0x40);
    SetEntry_guess(0xa5, 0x19c0, 0x40);
    SetEntry_guess(0xad, 0x19d0, 0x40);
    SetEntry_guess(0x97, 0x19c1, 0x40);
    SetEntry_guess(0x98, 0x19c2, 0x40);
    SetEntry_guess(0x99, 0x19c3, 0x40);
    SetEntry_guess(0xab, 0x19cb, 0x40);
    SetEntry_guess(0xae, 0xc48, 0x40);
    SetEntry_guess(0x22, 0x19bd, 0x40);
    SetEntry_guess(0xaf, 0x13f3, 0x40);
    SetEntry_guess(0xb0, 0xc4e, 0x40);
    SetEntry_guess(0xba, 0xc6d, 0x40);
    SetEntry_guess(0xb7, 0xc6f, 0x40);
    SetEntry_guess(0xbb, 0x1a34, 0x40);
    SetEntry_guess(0xbc, 0xc70, 0x40);
    SetEntry_guess(0xbd, 0x1a3c, 0x40);
    SetEntry_guess(0xc9, 0x1a7a, 0x40);
    SetEntry_guess(0x82, 0x19b6, 0x40);
    SetEntry_guess(0x83, 0x19b7, 0x40);
    SetEntry_guess(0x84, 0x19b8, 0x40);
    SetEntry_guess(0x85, 0x19b5, 0x40);
    SetEntry_guess(0x17, 0xc51, 0x40);
    SetEntry_guess(0xb9, 0x1a2d, 0x40);
    SetEntry_guess(0xbf, 0xca5, 0x40);
    SetEntry_guess(0xd4, 0x1a91, 0x40);
    SetEntry_guess(0xcc, 0x1a92, 2);
    SetEntry_guess(0xcd, 0x1a93, 2);
    SetEntry_guess(0xce, 0x1a94, 2);
    SetEntry_guess(0xcf, 0x1a95, 2);
    SetEntry_guess(0xd0, 0x1a96, 2);
    SetEntry_guess(0xd1, 0x1a97, 2);
    SetEntry_guess(0xd2, 0x1a98, 2);
    SetEntry_guess(0xd3, 0x1a99, 2);
    // Commands of later expansions are listed only when the account flags at 0x009247A4..0x009247B0 allow
    // them.
    if (g_enableExtraEntries_guess != 0) {
        SetEntry_guess(0xdc, 0x2484, 2);
        SetEntry_guess(0xdd, 0x2485, 2);
        SetEntry_guess(0xde, 0x2486, 2);
        SetEntry_guess(0xdf, 0x2487, 2);
        SetEntry_guess(0xe0, 0x2488, 0x40);
        SetEntry_guess(0xe1, 0x2489, 0x40);
    }
    SetEntry_guess(0xd6, 0x16e9, 0x40);
    SetEntry_guess(0xdb, 0xded, 0x40);
    SetEntry_guess(0xe6, 0xff4, 0x40);
    SetEntry_guess(0xe7, 0xff8, 0x40);
    SetEntry_guess(0xd5, 0xdca, 0x40);
    SetEntry_guess(0xe2, 0x17f3, 2);
    SetEntry_guess(0xe3, 0x17f2, 2);
    if (g_enableEntryC6_guess != 0) {
        SetEntry_guess(0xc6, 0x213c, 0x40);
    }
    if (g_globalStatus_guess->IsTributeAvailable_guess() != 0) {
        SetEntry_guess(0xcb, 0xd7c, 0x40);
    }
    if (g_enableEntryCA_guess != 0) {
        SetEntry_guess(0xca, 0x2182, 0x40);
    }
    if (g_enableEntryD7DA_guess != 0) {
        SetEntry_guess(0xd7, 0xd9c, 0x40);
        SetEntry_guess(0xda, 0x178b, 0x40);
    }
    SetEntry_guess(0xd8, 0x2295, 0x40);
    SetEntry_guess(0xa1, 0x1194, 0x40);
}

// EXTERNAL: TITANIUM 0x0053B846 FUN_0053b846_guess
void __cdecl FUN_0053b846_guess();

// Display page refresh; every 10th call (every 20 s, see TimedOwner_guess::OnProcessFrame_guess) a changed
// fade setting is also copied to the bag windows' INI sections (BagOptions_guess::Apply_guess).
// FUNCTION: TITANIUM 0x0053E0F5
int BagOptions_guess::RefreshDisplayPage_guess() {
    FUN_0053b846_guess();
    ++tick_guess;
    if (tick_guess >= 10) {
        if (g_statSource_guess->GetC_guess() != statC_guess) {
            statC_guess = g_statSource_guess->GetC_guess();
            WriteBagFadeSetting_guess(statC_guess, 2);
        }
        if (g_statSource_guess->GetD_guess() != statD_guess) {
            statD_guess = g_statSource_guess->GetD_guess();
            WriteBagFadeSetting_guess(statD_guess, 3);
        }
        if (g_statSource_guess->GetA_guess() != statA_guess) {
            statA_guess = g_statSource_guess->GetA_guess();
            WriteBagFadeSetting_guess(statA_guess, 0);
        }
        if (g_statSource_guess->GetB_guess() != statB_guess) {
            statB_guess = g_statSource_guess->GetB_guess();
            WriteBagFadeSetting_guess(statB_guess, 1);
        }
        tick_guess = 0;
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0053E1D9 FindKeyConflict_guess
char __stdcall FindKeyConflict_guess(int value_guess, int zero_guess);

#define g_pointerTable_guess EQ_GLOBAL(PointerTable_guess*, 0x0098599C)

#include "titanium/layouts/shared_classes.h"
#include "titanium/wnd/CLoadskinWnd.h"
#include "titanium/wnd/CSystemInfoDialogBox.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CPetInfoWnd.h"
#include "titanium/wnd/CVideoModesWnd.h"

struct SlotValue_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x005BA220 SlotValue_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x005BA250 SlotValue_guess::IsSet_guess
    int IsSet_guess();
    // EXTERNAL: TITANIUM 0x005BA290 SlotValue_guess::Matches_guess
    int Matches_guess(const SlotValue_guess* other_guess);
    // EXTERNAL: TITANIUM 0x005BA560 SlotValue_guess::ToString_guess
    CXStr ToString_guess();
};

struct SlotRow_guess {
    int code_guess;     // +0x0
    int unused_guess;   // +0x4
};

struct RowKey_guess {
    int value_guess;    // +0x0
    bool flag_guess;    // +0x4
};

struct SlotTable_guess {
    char pad_guess[0x2E8];
    SlotRow_guess rows_guess[0xF7];   // +0x2E8

    char FindKeyConflict_guess(RowKey_guess* key_guess, RowKey_guess* out_guess);
};

// Key-binding conflict: true when the key of command `key_guess->value_guess` (primary when the flag is set,
// else alternate; key manager 0x0098599C) is also bound to another command or column. The other one goes
// to `out_guess`.
// FUNCTION: TITANIUM 0x0053E1D9
char SlotTable_guess::FindKeyConflict_guess(RowKey_guess* key_guess, RowKey_guess* out_guess) {
    char found_guess = 0;
    SlotValue_guess left_guess;
    SlotValue_guess right_guess;
    left_guess.Clear_guess();
    right_guess.Clear_guess();
    if (rows_guess[key_guess->value_guess].code_guess != 0) {
        if (key_guess->flag_guess) {
            left_guess.value_guess = *g_pointerTable_guess->First_guess(key_guess->value_guess);
        } else {
            left_guess.value_guess = *g_pointerTable_guess->Second_guess(key_guess->value_guess);
        }
        if (left_guess.IsSet_guess() != 0) {
            for (int i = 0; i < 0xF7; ++i) {
                if (rows_guess[i].code_guess != 0) {
                    for (int j = 0; j < 2; ++j) {
                        bool first_guess;
                        if (j == 0) {
                            right_guess.value_guess = *g_pointerTable_guess->First_guess(i);
                            first_guess = true;
                        } else {
                            right_guess.value_guess = *g_pointerTable_guess->Second_guess(i);
                            first_guess = false;
                        }
                        if (left_guess.Matches_guess(&right_guess) != 0 &&
                            (key_guess->value_guess != i || key_guess->flag_guess != first_guess)) {
                            if (out_guess != 0) {
                                out_guess->value_guess = i;
                                out_guess->flag_guess = first_guess;
                            }
                            found_guess = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    return found_guess;
}

struct ChildNode_guess;

struct TimedOwner_guess {
    char padding_guess[0x160];
    ChildNode_guess* child_guess;   // +0x160
    int key164_guess;               // +0x164
    char gap168_guess[0x1EC - 0x168];
    int key1ec_guess;               // +0x1EC
    char gap1f0_guess[0x2B4 - 0x1F0];
    int key2b4_guess;               // +0x2B4
    char gap2b8_guess[0x2D4 - 0x2B8];
    int key2d4_guess;               // +0x2D4
    char gap2d8_guess[0xAA4 - 0x2D8];
    int keyaa4_guess;               // +0xAA4
    char gapaa8_guess[0xAB0 - 0xAA8];
    int keyab0_guess;               // +0xAB0
    char gapab4_guess[0xABC - 0xAB4];
    CXWnd* target_guess;            // +0xABC
    CListWnd* list_guess;           // +0xAC0
    char gapac4_guess[0xAE4 - 0xAC4];
    unsigned int last_guess;        // +0xAE4
    // EXTERNAL: TITANIUM 0x0053B573 TimedOwner_guess::RefreshGeneralPage_guess
    void RefreshGeneralPage_guess();
    void RefreshColorSamples_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 TimedOwner_guess::OnProcessFrame
    void OnProcessFrame();
    int RefreshPage_guess(int value_guess);
    void OnProcessFrame_guess();
};

struct Widget_guess {
    // EXTERNAL: TITANIUM 0x005BB140 Widget_guess::SetCheck
    void SetCheck(bool value_guess);
    // EXTERNAL: TITANIUM 0x005BCD10 Widget_guess::Process_guess
    void Process_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0059C360 Widget_guess::SetCurSel_guess
    void SetCurSel_guess(int index_guess);
};

struct FlagPanel_guess {
    char padding_guess[0x168];
    Widget_guess* f168_guess;
    Widget_guess* f16c_guess;
    Widget_guess* f170_guess;
    Widget_guess* f174_guess;
    Widget_guess* f178_guess;
    Widget_guess* f17c_guess;
    Widget_guess* f180_guess;
    Widget_guess* f184_guess;
    Widget_guess* f188_guess;
    Widget_guess* f18c_guess;
    Widget_guess* f190_guess;
    Widget_guess* f194_guess;
    void* pad198_guess;
    Widget_guess* f19c_guess;
    Widget_guess* f1a0_guess;
    Widget_guess* f1a4_guess;
    Widget_guess* f1a8_guess;
    Widget_guess* f1ac_guess;
    Widget_guess* f1b0_guess;
    Widget_guess* f1b4_guess;
    Widget_guess* f1b8_guess;
    Widget_guess* f1bc_guess;
    Widget_guess* f1c0_guess;
    Widget_guess* f1c4_guess;
    Widget_guess* f1c8_guess;
    void* pad1CC_guess;
    Widget_guess* f1d0_guess;
    void* pad1D4_guess;
    Widget_guess* f1d8_guess;
    void RefreshGeneralPage_guess();
};

struct CharNode_guess {
    char padding_guess[4];
    int vbaseOffset_0004_guess;
};

struct CharData_guess {
    char padding_guess[8];
    CharNode_guess* node_guess;
    char padding2_guess[0x120 - 0x0C];
    unsigned char table_guess[0x1A21 - 0x120];
    unsigned char field1A21_guess;
    unsigned char field1A22_guess;
    unsigned char field1A23_guess;
};

#define g_charData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)
#define g_panelOne_guess EQ_GLOBAL(int, 0x009249A0)
#define g_panelTwo_guess EQ_GLOBAL(int, 0x00924960)
#define g_panelState_guess EQ_GLOBAL(int, 0x00924954)
#define g_panelFlagA_guess EQ_GLOBAL(int, 0x009254B0)
#define g_panelFlagB_guess EQ_GLOBAL(int, 0x009254B4)
#define g_panelFlagC_guess EQ_GLOBAL(int, 0x009254B8)
#define g_panelCount_guess EQ_GLOBAL(int, 0x009248D8)
#define g_panelMode_guess EQ_GLOBAL(int, 0x0092495C)
#define g_panelSelect_guess EQ_GLOBAL(int, 0x009254DC)
#define g_panelValueA_guess EQ_GLOBAL(int, 0x00924988)
#define g_panelValueB_guess EQ_GLOBAL(int, 0x00924980)
#define g_panelValueC_guess EQ_GLOBAL(int, 0x00924984)
#define g_byte254EC_guess EQ_GLOBAL(unsigned char, 0x009254EC)
#define g_byte254ED_guess EQ_GLOBAL(unsigned char, 0x009254ED)
#define g_byte254EE_guess EQ_GLOBAL(unsigned char, 0x009254EE)
#define g_byte254EF_guess EQ_GLOBAL(unsigned char, 0x009254EF)
#define g_byte254F4_guess EQ_GLOBAL(unsigned char, 0x009254F4)
#define g_byte254F6_guess EQ_GLOBAL(unsigned char, 0x009254F6)
#define g_byte254F7_guess EQ_GLOBAL(unsigned char, 0x009254F7)
#define g_byte254F8_guess EQ_GLOBAL(unsigned char, 0x009254F8)

// General page controls from their globals. Anonymous and roleplaying share 0x00924954 (bit 0 anon,
// bit 1 roleplay); fast destroy, guild invites and the confirm boxes are 0/1 ints; loot autosplit is a
// pCharData byte; the three auto-consent boxes are pCharData +0x1A21-0x1A23. Trade combo rows 0-2 hold
// settings 2, 1, 0; item dropping row 2 means -1.
// FUNCTION: TITANIUM 0x0053B573
// @early-stop: budget, structural ndiff=104
void FlagPanel_guess::RefreshGeneralPage_guess() {
    int one_guess = 0;
    int zero_guess = 0;
    ++one_guess;
    if (f168_guess != 0) {
        f168_guess->SetCheck(g_panelOne_guess == one_guess);
    }
    if (f16c_guess != 0) {
        f16c_guess->SetCheck(g_panelTwo_guess == one_guess);
    }
    if (f170_guess != 0) {
        f170_guess->SetCheck(g_charData_guess->table_guess[g_charData_guess->node_guess->vbaseOffset_0004_guess]);
    }
    if (f174_guess != 0) {
        f174_guess->SetCheck(g_panelState_guess == one_guess || g_panelState_guess == 3);
    }
    if (f178_guess != 0) {
        f178_guess->SetCheck(g_panelState_guess == 2 || g_panelState_guess == 3);
    }
    if (f17c_guess != 0) {
        f17c_guess->SetCheck(g_panelFlagA_guess == one_guess);
    }
    if (f180_guess != 0) {
        f180_guess->SetCheck(g_panelFlagB_guess == one_guess);
    }
    if (f184_guess != 0) {
        f184_guess->SetCheck(g_panelFlagC_guess == one_guess);
    }
    if (f19c_guess != 0) {
        f19c_guess->SetCheck(g_byte254EE_guess);
    }
    if (f1a0_guess != 0) {
        f1a0_guess->SetCheck(g_byte254EF_guess);
    }
    if (f188_guess != 0) {
        f188_guess->SetCheck(pinstCPetInfoWnd_guess != 0 && pinstCPetInfoWnd_guess->field_305_guess != zero_guess);
    }
    if (f18c_guess != 0) {
        f18c_guess->SetCheck(g_byte254EC_guess);
    }
    if (f190_guess != 0) {
        f190_guess->SetCheck(g_panelCount_guess != zero_guess);
    }
    if (f194_guess != 0) {
        f194_guess->SetCheck(g_byte254ED_guess);
    }
    if (f1a4_guess != 0) {
        f1a4_guess->SetCheck(g_byte254F4_guess);
    }
    if (f1a8_guess != 0) {
        f1a8_guess->SetCheck(g_byte254F6_guess);
    }
    if (f1ac_guess != 0) {
        f1ac_guess->SetCheck(g_byte254F7_guess);
    }
    if (f1b0_guess != 0) {
        f1b0_guess->SetCheck(g_byte254F8_guess);
    }
    if (f1b4_guess != 0) {
        f1b4_guess->SetCheck(g_charData_guess->field1A21_guess);
    }
    if (f1b8_guess != 0) {
        f1b8_guess->SetCheck(g_charData_guess->field1A22_guess);
    }
    if (f1bc_guess != 0) {
        f1bc_guess->SetCheck(g_charData_guess->field1A23_guess);
    }
    if (f1c0_guess != 0) {
        int mode_guess;
        if (g_panelMode_guess == zero_guess) {
            mode_guess = 2;
        } else if (g_panelMode_guess == one_guess) {
            mode_guess = one_guess;
        } else {
            mode_guess = zero_guess;
        }
        f1c0_guess->SetCurSel_guess(mode_guess);
    }
    if (f1c4_guess != 0) {
        int select_guess;
        if (g_panelSelect_guess == -1) {
            select_guess = 2;
        } else if (g_panelSelect_guess == zero_guess || g_panelSelect_guess != one_guess) {
            select_guess = zero_guess;
        } else {
            select_guess = one_guess;
        }
        f1c4_guess->SetCurSel_guess(select_guess);
    }
    if (f1c8_guess != 0) {
        f1c8_guess->Process_guess(g_panelValueA_guess);
    }
    if (f1d0_guess != 0) {
        f1d0_guess->Process_guess(g_panelValueB_guess);
    }
    if (f1d8_guess != 0) {
        f1d8_guess->Process_guess(g_panelValueC_guess);
    }
}

struct ListOption_guess {
    // EXTERNAL: TITANIUM 0x005980B0 ListOption_guess::GetOption_guess
    int GetOption_guess(int index_guess, int option_guess);
};

struct SelectionSink_guess {
    // EXTERNAL: TITANIUM 0x004F898E SelectionSink_guess::Activate_guess
    void Activate_guess(TextColors_guess* owner_guess, int value_guess);
};

#define g_selectionSink_guess EQ_GLOBAL(SelectionSink_guess*, 0x00850C0C)
#define pinstCOptionsWnd_guess EQ_GLOBAL(int, 0x00850C14)

// Color page WndNotification. `index_guess` is the sender: UserColorChange (+0xABC) opens the colour
// picker (0x00850C0C) for the selected row, UserColorDefault (+0xAB8) asks to restore the defaults
// (string 0x19CA, dialog id 101). Message 0x20 is the picker's answer, 0x00RRGGBB.
// FUNCTION: TITANIUM 0x0053E2BB
// @early-stop: budget, structural ndiff=25
int TextColors_guess::ColorPageWndNotification_guess(int index_guess, int event_guess, unsigned int value_guess) {
    if (event_guess == 1) {
        if (index_guess == selectedIndex_guess) {
            if (active_guess != 0) {
                int current_guess = active_guess->GetCurSel();
                if (current_guess != -1) {
                    pendingIndex_guess = active_guess->GetItemData(current_guess);
                    int option_guess = ((ListOption_guess*)active_guess)->GetOption_guess(current_guess, 1);
                    g_selectionSink_guess->Activate_guess(this, option_guess);
                }
            }
        } else if (index_guess == alternateIndex_guess) {
            pConfirmationDialogPool_guess->Activate(
                (void*)(pinstCOptionsWnd_guess != 0 ? pinstCOptionsWnd_guess + 0x15c : 0),
                0x65, pStringTable->getString(0x19ca, 0), 0xc, 0x4e20, 0, 1);
        }
    } else if (event_guess == 0x20 && pendingIndex_guess != -1) {
        unsigned int packed_guess = value_guess;
        SetColorOptions_guess(pendingIndex_guess, (packed_guess >> 16) & 0xff,
                              (packed_guess >> 8) & 0xff, packed_guess & 0xff);
        pendingIndex_guess = -1;
    }
    return 0;
}

// Refreshes page `value_guess` (a page window): General, Display, Mouse, Chat or Color; the Keyboard page
// needs nothing. -1 for an unknown page.
// FUNCTION: TITANIUM 0x0053E3A6
int TimedOwner_guess::RefreshPage_guess(int value_guess) {
    if (value_guess == key164_guess) {
        RefreshGeneralPage_guess();
    } else if (value_guess == key1ec_guess) {
        ((BagOptions_guess*)this)->RefreshDisplayPage_guess();
    } else if (value_guess == key2b4_guess) {
        ((StateOwner_guess*)this)->RefreshMousePage_guess();
    } else if (value_guess == key2d4_guess) {
        return 0;
    } else if (value_guess == keyaa4_guess) {
        ((ChannelPanel_guess*)this)->Refresh_guess();
    } else if (value_guess == keyab0_guess) {
        RefreshColorSamples_guess();
    } else {
        return -1;
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x00438BA7 GetUserDefinedColor
unsigned int __cdecl GetUserDefinedColor(int index_guess);

struct ListColors_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059B3E0 ListColors_guess::SetValue_guess
    void SetValue_guess(int index_guess, int flag_guess, unsigned int color_guess);
};

// Color page: paints each row's sample in its user colour, COLORREF (0x00BBGGRR) turned into ARGB.
// Black is shown as white. UserColorChange (+0xABC) is enabled only while a row is selected.
// FUNCTION: TITANIUM 0x0053BE5E
// @early-stop: budget, structural ndiff=46
void TimedOwner_guess::RefreshColorSamples_guess() {
    int index_guess = 0;
    if (list_guess != 0) {
        for (; index_guess < list_guess->ItemsCount; ++index_guess) {
            int value_guess = list_guess->GetItemData(index_guess);
            unsigned int color_guess = (GetUserDefinedColor(value_guess) & 0xFF) | 0xFFFFFF00;
            color_guess <<= 8;
            color_guess |= (GetUserDefinedColor(value_guess) >> 8) & 0xFF;
            color_guess <<= 8;
            color_guess |= (GetUserDefinedColor(value_guess) >> 16) & 0xFF;
            if (color_guess == 0xFF000000) {
                color_guess = 0xFFFFFFFF;
            }
            ((ListColors_guess*)list_guess)->SetValue_guess(index_guess, 1, color_guess);
        }
        if (target_guess != 0) {
            target_guess->Enabled = list_guess->GetCurSel() != -1;
        }
    }
}

// Text colour for a binding cell: red (0xFFFF0000) when FindKeyConflict_guess finds a conflict, else white
// (-1). Declared __stdcall but used as ListOwner_guess::GetKeyConflictColor_guess (match shape).
// FUNCTION: TITANIUM 0x0053F00F
int __stdcall GetKeyConflictColor_guess(int value_guess) {
    int result_guess = -1;
    if (FindKeyConflict_guess(value_guess, 0) != 0) {
        result_guess = 0xffff0000;
    }
    return result_guess;
}

struct RowValue_guess {
    unsigned int value_guess;  // +0x00
    bool flag_guess;           // +0x04
};

struct CellList_guess {
    // EXTERNAL: TITANIUM 0x0059B3E0 CellList_guess::SetCell_guess
    void SetCell_guess(int index_guess, int column_guess, int value_guess);
};

struct ListOwner_guess {
    char padding_guess[0x2DC];
    CListWnd* list_guess;      // +0x2DC
    // EXTERNAL: TITANIUM 0x0053F00F ListOwner_guess::GetKeyConflictColor_guess
    int GetKeyConflictColor_guess(int* value_guess);
    void ColorKeyConflicts_guess();
};

// Keyboard page: recolours the primary (column 1) and alternate (column 2) binding of every row, so
// conflicting keys show red.
// FUNCTION: TITANIUM 0x0053F02D
void ListOwner_guess::ColorKeyConflicts_guess() {
    RowValue_guess cleared_guess;
    RowValue_guess set_guess;
    int count_guess = list_guess->ItemsCount;
    if (count_guess > 0) {
        set_guess.flag_guess = true;
        cleared_guess.flag_guess = false;
        for (int i = 0; i < count_guess; ++i) {
            unsigned int data_guess = list_guess->GetItemData(i);
            set_guess.value_guess = data_guess;
            ((CellList_guess*)list_guess)->SetCell_guess(i, 1, GetKeyConflictColor_guess((int*)&set_guess));
            cleared_guess.value_guess = data_guess;
            ((CellList_guess*)list_guess)->SetCell_guess(i, 2, GetKeyConflictColor_guess((int*)&cleared_guess));
        }
    }
}

struct RowCell_guess {
    int field00_guess;
    CXStr text_guess;
    int field08_guess;
    RowCell_guess() {
        field08_guess = -1;
        field00_guess = 0;
    }
};

struct RowData_guess {
    int field00_guess;
    int field04_guess;
    int field08_guess;
    unsigned char field0c_guess;
    int index_guess;
    int field14_guess;
    unsigned char field18_guess;
    unsigned char field19_guess;
    RowData_guess() {
        field04_guess = 0;
        field00_guess = 0;
        field08_guess = 0;
        field0c_guess = 1;
        index_guess = 0;
        field14_guess = -1;
        field18_guess = 0;
        field19_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0042D7A7 RowData_guess::Append_guess
    void Append_guess(int owner_guess, RowCell_guess* cell_guess);
    // EXTERNAL: TITANIUM 0x0042D7E5 RowData_guess::~RowData_guess
    ~RowData_guess();
};

struct EntryRows_guess : RowList_guess {
    // EXTERNAL: TITANIUM 0x0059B800 EntryRows_guess::AddRow_guess
    void AddRow_guess(RowData_guess* row_guess);
};

struct ResultSelection_guess {
    // EXTERNAL: TITANIUM 0x0059C3A0 ResultSelection_guess::GetCurChoice_guess
    int GetCurChoice_guess();
};

// Scalar deleting destructor of the window as seen through EntryList_guess.
// FUNCTION: TITANIUM 0x005418BF
EntryList_guess* EntryList_guess::Delete_guess(unsigned int flags_guess) {
    this->~EntryList_guess();
    if (flags_guess & 1) {
        free(this);
    }
    return this;
}

// Destructor of the options window (vtable 0x659F60): destroys the 0xF7 key-command entries (+0x2E4, 8
// bytes each), expires every confirmation dialog its dialog-owner part (+0x15C) opened (0x005482A0, all
// messages), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x005418DB
EntryList_guess::~EntryList_guess() {
}

// EXTERNAL: TITANIUM 0x0059DD30 FUN_0059dd30_guess
char __cdecl FUN_0059dd30_guess();
struct ChildNode_guess {
    // EXTERNAL: TITANIUM 0x005BC390 ChildNode_guess::Get_guess
    int Get_guess();
};

struct DisplayClock_guess {
    char padding_guess[0x148];
    unsigned int tick_guess;    // +0x148
    char padding2_guess[0x2D2C - 0x14C];
    unsigned char field2D2C_guess;  // +0x2D2C
    // EXTERNAL: TITANIUM 0x004382FC DisplayClock_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00439A93 DisplayClock_guess::SetPCNameSpriteState_guess
    void SetPCNameSpriteState_guess(int show_guess);
    // EXTERNAL: TITANIUM 0x00439AC7 DisplayClock_guess::SetNPCNameSpriteState_guess
    void SetNPCNameSpriteState_guess(int show_guess);
    // EXTERNAL: TITANIUM 0x0043DD14 DisplayClock_guess::UpdateItemSlot_guess
    void UpdateItemSlot_guess(void* pc_guess, int kind_guess, int first_guess, int second_guess);
};

#define g_display_guess EQ_GLOBAL(DisplayClock_guess*, 0x00905D24)

// OnProcessFrame: while visible, refreshes the shown page every 2000 ms (CDisplay's clock +0x148), then
// runs the base CXWnd::OnProcessFrame (0x005A0E50).
// FUNCTION: TITANIUM 0x0053F0A7
void TimedOwner_guess::OnProcessFrame_guess() {
    if (FUN_0059dd30_guess() != 0 && g_display_guess->tick_guess > last_guess + 2000U) {
        if (child_guess != 0) {
            RefreshPage_guess(child_guess->Get_guess());
        }
        last_guess = g_display_guess->tick_guess;
    }
    OnProcessFrame();
}

struct StateGate_guess {
    char padding_guess[0x2D4];
    int state_guess;  // +0x2D4
    int gap2D8_guess;
    CListWnd* list_guess;       // +0x2DC
    char gap2E0_guess[0xA9C - 0x2E0];
    int editRow_guess;          // +0xA9C
    int editColumn_guess;       // +0xAA0
    void CancelKeyCapture_guess();
    int Check_guess(int value_guess);
    int Check_guess(int value_guess, int first_guess, int second_guess, int third_guess);
    int CaptureKeyBinding_guess(int first_guess, int second_guess, int third_guess);
};

// Key event passed by value (8 bytes), flags at +0x00.
struct KeyEvent_guess {
    unsigned int flags_guess;   // +0x00
    int pad_guess;              // +0x04
    // EXTERNAL: TITANIUM 0x005BA230 KeyEvent_guess::Set_guess
    void Set_guess(int key_guess, bool control_guess, bool shift_guess, bool alt_guess);
    // EXTERNAL: TITANIUM 0x005BA250 KeyEvent_guess::GetKey_guess
    int GetKey_guess();
    // EXTERNAL: TITANIUM 0x005BA2D0 KeyEvent_guess::Initialize_guess
    void Initialize_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005BA560 KeyEvent_guess::Format_guess
    Str_guess* Format_guess(Str_guess* text_guess);
};

struct KeyMap_guess {
    // EXTERNAL: TITANIUM 0x004B3721 KeyMap_guess::AttachKeyToEqCommand
    bool AttachKeyToEqCommand(KeyEvent_guess* source_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x004B3754 KeyMap_guess::AttachAltKeyToEqCommand
    bool AttachAltKeyToEqCommand(KeyEvent_guess* source_guess, int index_guess);
};

#define g_keyMap_guess EQ_GLOBAL(KeyMap_guess*, 0x0098599C)

struct KeyTarget_guess {
    char padding_guess[0x2DC];
    CListWnd* list_guess;       // +0x2DC
    char gap_guess[0xA9C - 0x2E0];
    int first_guess;            // +0xA9C
    int state_guess;            // +0xAA0
};

struct FormatText_guess {
    char* data_guess;
    ~FormatText_guess() {
        if (data_guess != 0) {
            ((Str_guess*)this)->FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

// Cancels key capture: puts the edited cell's binding text back and recolours the list.
// FUNCTION: TITANIUM 0x0053F0FC
void StateGate_guess::CancelKeyCapture_guess() {
    if (((DockFrame_guess*)this)->IsCapturingKey_guess() && list_guess != 0) {
        unsigned int data_guess = list_guess->GetItemData(editRow_guess);
        if (editColumn_guess == 1) {
            list_guess->SetItemText(editRow_guess, 1,
                ((SlotValue_guess*)g_pointerTable_guess->First_guess(data_guess))->ToString_guess());
        } else if (editColumn_guess == 2) {
            list_guess->SetItemText(editRow_guess, 2,
                ((SlotValue_guess*)g_pointerTable_guess->Second_guess(data_guess))->ToString_guess());
        }
        editRow_guess = -1;
        editColumn_guess = -1;
        ((ListOwner_guess*)this)->ColorKeyConflicts_guess();
    }
}

// The key pressed during capture. Shift, Ctrl and Alt alone (scan codes 0x2A/0x36, 0x1D/0x9D,
// 0x38/0xB8) are ignored and Escape (1) clears the binding. Commands above 0xE8 can't be rebound;
// column 1 stores the primary key, 2 the alternate. `flags_guess` is the KeyCombo passed by value.
// FUNCTION: TITANIUM 0x0053F5B0
// @early-stop: budget, structural ndiff=28
int StateGate_guess::CaptureKeyBinding_guess(int key_guess, int flags_guess, int pad_guess) {
    KeyEvent_guess& event_guess = *(KeyEvent_guess*)&flags_guess;
    int result_guess = -1;
    if (!((DockFrame_guess*)this)->IsCapturingKey_guess() || ((KeyTarget_guess*)this)->list_guess == 0) {
        return result_guess;
    }
    unsigned int eventFlags_guess = event_guess.flags_guess;
    event_guess.Set_guess(key_guess, eventFlags_guess & 1, (eventFlags_guess >> 1) & 1, (eventFlags_guess >> 2) & 1);
    if (event_guess.GetKey_guess() == 0x2a || event_guess.GetKey_guess() == 0x36 ||
        event_guess.GetKey_guess() == 0x1d || event_guess.GetKey_guess() == 0x9d ||
        event_guess.GetKey_guess() == 0x38 || event_guess.GetKey_guess() == 0xb8) {
        return result_guess;
    }
    if (event_guess.GetKey_guess() == 1) {
        event_guess.Initialize_guess(0);
    }
    int item_guess = ((KeyTarget_guess*)this)->list_guess->GetItemData(((KeyTarget_guess*)this)->first_guess);
    if (item_guess > 0xe8) {
        ((StateGate_guess*)this)->CancelKeyCapture_guess();
        return 0;
    }
    bool stored_guess;
    if (((KeyTarget_guess*)this)->state_guess == 1) {
        stored_guess = g_keyMap_guess->AttachKeyToEqCommand(&event_guess, item_guess);
    } else if (((KeyTarget_guess*)this)->state_guess == 2) {
        stored_guess = g_keyMap_guess->AttachAltKeyToEqCommand(&event_guess, item_guess);
    } else {
        ((StateGate_guess*)this)->CancelKeyCapture_guess();
        return 0;
    }
    if (!stored_guess) {
        ((StateGate_guess*)this)->CancelKeyCapture_guess();
        return 0;
    }
    {
        FormatText_guess text_guess;
        ((RowList_guess*)((KeyTarget_guess*)this)->list_guess)->SetItemText(
            ((KeyTarget_guess*)this)->first_guess, ((KeyTarget_guess*)this)->state_guess,
            *event_guess.Format_guess((Str_guess*)&text_guess));
    }
    g_display_guess->Refresh_guess();
    ((KeyTarget_guess*)this)->first_guess = -1;
    ((KeyTarget_guess*)this)->state_guess = -1;
    ((ListOwner_guess*)this)->ColorKeyConflicts_guess();
    return 0;
}

// Reloads the key-command table, puts the filter combo on row 0 and relists.
// FUNCTION: TITANIUM 0x0053F795
void EntryList_guess::ReloadKeyList_guess() {
    InitializeEntries_guess();
    if (results_guess) {
        results_guess->Finish_guess(0);
    }
    Update_guess();
}

// Cancels key capture when `value_guess` is the Keyboard page.
// FUNCTION: TITANIUM 0x0053F8C1
int StateGate_guess::Check_guess(int value_guess) {
    if (value_guess == state_guess) {
        CancelKeyCapture_guess();
        return 0;
    }
    return -1;
}

// Passes a key press to CaptureKeyBinding_guess when `value_guess` is the Keyboard page; -1 otherwise.
// FUNCTION: TITANIUM 0x0053F89E
int StateGate_guess::Check_guess(int value_guess, int first_guess, int second_guess, int third_guess) {
    int result_guess = -1;
    if (value_guess == state_guess) {
        result_guess = CaptureKeyBinding_guess(first_guess, second_guess, third_guess);
    }
    return result_guess;
}

struct ChildOwner_guess {
    char padding_guess[0x160];
    ChildNode_guess* child_guess;  // +0x160
    char AboutToHide_guess();
    int Check_guess(int first_guess, int second_guess, int third_guess);
};

// AboutToHide (vtable slot 50 of the options window): cancels key capture if the Keyboard page is shown;
// always true.
// FUNCTION: TITANIUM 0x00541942
char ChildOwner_guess::AboutToHide_guess() {
    if (child_guess != 0) {
        ((StateGate_guess*)this)->Check_guess(child_guess->Get_guess());
    }
    return 1;
}

#define g_routeWnd_guess EQ_GLOBAL(int, 0x00850C0C)

struct RouteInfo_guess {
    int first_guess;   // +0x00
    int second_guess;  // +0x04
    int id_guess;      // +0x08
    int payload_guess; // +0x0C
};

struct RouteWnd_guess {
    char padding_guess[0x28];
    int owner_guess;  // +0x28
};

struct MailSinkSlots_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
};

struct MailSink_guess : MailSinkSlots_guess {
    char addressBookPadding_guess[0x228];
    CXStr addressBookFilter_guess;
    virtual void Slot63_guess(const CXStr* text_guess);
    void SetAddressBook_guess(const CXStr& text_guess) {
        Slot63_guess(&text_guess);
    }
};

struct OptionLabel_guess : MailSinkSlots_guess {
    virtual void SetText_guess(const CXStr* text_guess);
};

struct OptionWindow_guess : MailSinkSlots_guess {
};

struct RenderSlots_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess();
    virtual void SetGamma_guess(float value_guess);                       // slot 27
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void SetEnvironmentDensity_guess(float value_guess);          // slot 37
    virtual void SetEnvironmentOpacity_guess(float value_guess);          // slot 38
    virtual void SetActorDensity_guess(float value_guess);                // slot 39
    virtual void SetActorOpacity_guess(float value_guess);                // slot 40
    virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void SetLodBias_guess(float value_guess);                     // slot 48
};

struct TargetIndicator_guess {
    // EXTERNAL: TITANIUM 0x004C8143 TargetIndicator_guess::SetEnabled_guess
    void SetEnabled_guess(unsigned char show_guess);
};

struct SelfSpawn_guess {
    char padding_guess[0x1B8];
    unsigned char field1B8_guess;       // +0x1B8
    char padding2_guess[0x258 - 0x1B9];
    unsigned short id258_guess;         // +0x258
};

struct CharInfoPart_guess {
    char padding_guess[8];
    int value_guess;                    // +0x08
    int Get_guess() { return value_guess; }
};

struct CharInfoView_guess {
    char padding_guess[0x10];
    CharInfoPart_guess part_guess;      // +0x10
};

struct PcHead_guess {
    virtual void Slot00_guess();
    int field4_guess;
};

// pCharData seen through its vbptr at +8 (types.h, EQ_PC).
struct PcView_guess : PcHead_guess, virtual EQ_Character {
    char padding_guess[0x1A5C - 0xC];
    unsigned char field1A5C_guess;      // +0x1A5C
};

struct OptionPacket_guess {
    unsigned short id_guess;
    unsigned short code_guess;
    int value_guess;
};

// EXTERNAL: TITANIUM 0x0046C7A7 setLOD_guess
void __cdecl setLOD_guess(int value_guess);
// EXTERNAL: TITANIUM 0x004CE72D ReinitMouse_guess
void __cdecl ReinitMouse_guess();

#define g_loadScreenMode_guess EQ_GLOBAL(int, 0x009254CC)
#define g_showPCNames_guess EQ_GLOBAL(int, 0x00924978)
#define g_showNPCNames_guess EQ_GLOBAL(int, 0x0092497C)
#define g_show3dTarget_guess EQ_GLOBAL(int, 0x009254C0)
#define g_option2496C_guess EQ_GLOBAL(int, 0x0092496C)
#define g_option24964_guess EQ_GLOBAL(int, 0x00924964)
#define g_flag23C3C_guess EQ_GLOBAL(char, 0x00923C3C)
#define g_targetIndicator_guess EQ_GLOBAL(TargetIndicator_guess*, 0x00985CE4)
#define g_selfSpawn_guess EQ_GLOBAL(SelfSpawn_guess*, 0x00905CE4)
#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)
#define g_connection_guess EQ_ARRAY(char, 0x00905CA0)
#define g_optionWindowB_guess EQ_GLOBAL(OptionWindow_guess*, 0x00850C7C)
#define g_spellDensity_guess EQ_GLOBAL(float, 0x00985810)
#define g_spellNearClip_guess EQ_GLOBAL(float, 0x00985818)
#define g_spellCastFilter_guess EQ_GLOBAL(int, 0x0098581C)
#define g_envDensity_guess EQ_GLOBAL(float, 0x00985820)
#define g_envNearClip_guess EQ_GLOBAL(float, 0x00985828)
#define g_actorDensity_guess EQ_GLOBAL(float, 0x00985830)
#define g_actorNearClip_guess EQ_GLOBAL(float, 0x00985838)
#define g_actorCastFilter_guess EQ_GLOBAL(int, 0x0098583C)
#define g_castFilters_guess EQ_ARRAY(int, 0x00793B4C)
#define g_render364_guess EQ_GLOBAL(RenderSlots_guess*, 0x0099E364)
#define g_render368_guess EQ_GLOBAL(RenderSlots_guess*, 0x0099E368)
#define g_render36C_guess EQ_GLOBAL(RenderSlots_guess*, 0x0099E36C)
#define g_fogScale_guess EQ_GLOBAL(float, 0x009254D0)
#define g_frameDelay_guess EQ_GLOBAL(int, 0x00790114)
#define g_lodScale_guess EQ_GLOBAL(float, 0x00642D70)
#define g_lodBase_guess EQ_GLOBAL(float, 0x00659374)
#define g_key4AC34_guess EQ_ARRAY(char, 0x0064AC34)
#define g_key4AC48_guess EQ_ARRAY(char, 0x0064AC48)
#define g_lowText_guess EQ_ARRAY(char, 0x006594A4)

struct MailManagerSlots_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
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
};

struct MailManager_guess : MailManagerSlots_guess {
    virtual void Slot72_guess(void* wnd_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x005024B7 MailManager_guess::HasSelection_guess
    int HasSelection_guess();
    // EXTERNAL: TITANIUM 0x00502AA1 MailManager_guess::Fill_guess
    void Fill_guess(CXStr* text_guess, int zero_guess);
};

#define pinstCFileSelectionWnd_guess EQ_GLOBAL(MailManager_guess*, 0x00850C84)
#define g_trueText_guess EQ_ARRAY(char, 0x00645EB4)
#define g_falseText_guess EQ_ARRAY(char, 0x006410A8)

// EXTERNAL: TITANIUM 0x0060BF60 FUN_0060bf60_guess
void __cdecl FUN_0060bf60_guess(const char* section_guess, const char* key_guess, const char* value_guess);

struct OptionSub_guess {
    // EXTERNAL: TITANIUM 0x0042CB80 OptionSub_guess::Matches_guess
    unsigned char Matches_guess(const char* text_guess);
};

struct OptionPage_guess {
    char padding_guess[0x60];
    OptionSub_guess sub_guess;
    char gap_guess[0x94 - 0x61];
    char flag_guess;
    // EXTERNAL: TITANIUM 0x0042846B OptionPage_guess::ApplyForward_guess
    void ApplyForward_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004250F4 OptionPage_guess::ApplyChat_guess
    void ApplyChat_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00425101 OptionPage_guess::ApplyAudio_guess
    void ApplyAudio_guess(int value_guess);
};

struct MailOptionBox_guess {
    Widget_guess flagOwner_guess;
    char padding_guess[0x127];
    char checked_guess;
};

struct SliderBase_guess {
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
};

struct Slider_guess : SliderBase_guess {
    virtual void SetText_guess(Str_guess* text_guess);
};

struct Route_guess {
    char pad0_guess[0x160];
    int key_guess;             // +0x160
    int fwdKey_guess;          // +0x164
    CButtonWnd* destroyBox_guess;             // +0x168
    CButtonWnd* guildInvitesBox_guess;        // +0x16C
    CButtonWnd* lootAutosplitBox_0170_guess;            // +0x170
    CButtonWnd* anonBox_guess;                // +0x174
    CButtonWnd* roleplayBox_guess;            // +0x178
    CButtonWnd* aaNoConfirmBox_guess;         // +0x17C
    CButtonWnd* pointMerchantBox_guess;       // +0x180
    CButtonWnd* leadershipBox_guess;          // +0x184
    CButtonWnd* popupOnPetBox_guess;          // +0x188
    CButtonWnd* envSoundsBox_guess;           // +0x18C
    CButtonWnd* combatMusicBox_guess;         // +0x190
    CButtonWnd* contextMenusBox_guess;        // +0x194
    int button198_guess;                      // +0x198
    CButtonWnd* systemInfoButton_019c_guess;      // +0x19C
    CButtonWnd* leftClickBox_guess;           // +0x1A0
    CButtonWnd* tellWindowsBox_guess;         // +0x1A4
    CButtonWnd* autoDuckBox_guess;            // +0x1A8
    CButtonWnd* autoStandBox_guess;           // +0x1AC
    CButtonWnd* autojoinBox_guess;            // +0x1B0
    CButtonWnd* charOptionABox_guess;         // +0x1B4
    CButtonWnd* charOptionBBox_guess;         // +0x1B8
    CButtonWnd* charOptionCBox_guess;         // +0x1BC
    int tradeCombo_guess;                     // +0x1C0
    int safeDropCombo_guess;                  // +0x1C4
    int realismSlider_guess;                  // +0x1C8
    OptionLabel_guess* realismLabel_guess;    // +0x1CC
    int musicSlider_guess;                    // +0x1D0
    OptionLabel_guess* musicLabel_guess;      // +0x1D4
    int soundSlider_guess;                    // +0x1D8
    OptionLabel_guess* soundLabel_guess;      // +0x1DC
    int fontCombo_guess;                      // +0x1E0
    struct FontCombo_guess* fontBox_guess;    // +0x1E4
    OptionLabel_guess* fontLabel_guess;       // +0x1E8
    int id_guess;              // +0x1EC
    ResultSelection_guess* loadScreen_guess;  // +0x1F0
    int id4_guess;             // +0x1F4
    int id8_guess;             // +0x1F8
    int idC_guess;             // +0x1FC
    CButtonWnd* pcNames_guess;                // +0x200
    CButtonWnd* npcNames_guess;               // +0x204
    CButtonWnd* targetIndicator_guess;        // +0x208
    CButtonWnd* levelOfDetailBox_020c_guess;                 // +0x20C
    CButtonWnd* showHelmBox_0210_guess;                 // +0x210
    int gammaSlider_guess;                    // +0x214
    OptionLabel_guess* gammaLabel_guess;      // +0x218
    int clipSlider_guess;                     // +0x21C
    OptionLabel_guess* clipLabel_guess;       // +0x220
    int button224_guess;                      // +0x224
    int button228_guess;                      // +0x228
    int button22C_guess;                      // +0x22C
    int combo230_guess;                       // +0x230
    int slider234_guess;                      // +0x234
    OptionLabel_guess* label238_guess;        // +0x238
    int slider23C_guess;                      // +0x23C
    OptionLabel_guess* label240_guess;        // +0x240
    int slider244_guess;                      // +0x244
    OptionLabel_guess* label248_guess;        // +0x248
    int slider24C_guess;                      // +0x24C
    OptionLabel_guess* label250_guess;        // +0x250
    int maxFpsSlider_guess;                   // +0x254
    OptionLabel_guess* maxFpsLabel_guess;     // +0x258
    int lodSlider_guess;                      // +0x25C
    OptionLabel_guess* lodLabel_guess;        // +0x260
    int spellDensity_guess;                   // +0x264
    int spellNearClip_guess;                  // +0x268
    int spellCastFilter_guess;                // +0x26C
    int spellOpacity_guess;                   // +0x270
    OptionLabel_guess* spellOpacityLabel_guess;  // +0x274
    int envDensity_guess;                     // +0x278
    int envNearClip_guess;                    // +0x27C
    int envOpacity_guess;                     // +0x280
    OptionLabel_guess* envOpacityLabel_guess; // +0x284
    int actorDensity_guess;                   // +0x288
    int actorNearClip_guess;                  // +0x28C
    int actorCastFilter_guess;                // +0x290
    int actorOpacity_guess;                   // +0x294
    OptionLabel_guess* actorOpacityLabel_guess;  // +0x298
    int button29C_guess;                      // +0x29C
    char gap3_guess[0x2B4 - 0x2A0];
    int value2B4_guess;        // +0x2B4
    CButtonWnd* inverseMouse_guess;             // +0x2B8
    CButtonWnd* lookSpring_guess;               // +0x2BC
    CButtonWnd* mouseActive_guess;              // +0x2C0
    CButtonWnd* wheelZoom_guess;                // +0x2C4
    CButtonWnd* rightHanded_guess;              // +0x2C8
    int sensitivityWnd_guess;                   // +0x2CC
    Slider_guess* sensitivity_guess;            // +0x2D0
    int state_guess;           // +0x2D4
    int results2D8_guess;      // +0x2D8
    int list2DC_guess;         // +0x2DC
    int third2E0_guess;        // +0x2E0
    char gap5_guess[0xAA4 - 0x2E4];
    int channel_guess;         // +0xAA4
    char gap6_guess[0xAB0 - 0xAA8];
    int owner_guess;           // +0xAB0
    int owner_flag_guess;      // +0xAB4
    char gap7_guess[0xAC4 - 0xAB8];
    int tail_guess;            // +0xAC4
    MailSink_guess* sink_guess;               // +0xAC8
    unsigned char addressFlag_guess;          // +0xACC
    void* panel_guess;                        // +0xAD0
    MailOptionBox_guess* forwardBox_guess;    // +0xAD4
    MailOptionBox_guess* chatBox_guess;       // +0xAD8
    MailOptionBox_guess* audioBox_guess;      // +0xADC
    MailOptionBox_guess* deleteBox_guess;     // +0xAE0

    int GeneralPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    int DisplayPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    void MousePageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    // EXTERNAL: TITANIUM 0x0053F47D Route_guess::KeyboardPageWndNotification_guess
    int KeyboardPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    // EXTERNAL: TITANIUM 0x0053E2BB Route_guess::ColorPageWndNotification_guess
    void ColorPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    int MailPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    int Forward_guess(int owner_guess, int wnd_guess, int msg_guess, int info_guess);
    // EXTERNAL: TITANIUM 0x005A2230 Route_guess::WndNotification
    int WndNotification(int wnd_guess, int msg_guess, int info_guess);
    int WndNotification_guess(int wnd_guess, int msg_guess, int info_guess);
    // EXTERNAL: TITANIUM 0x0059EDF0 Route_guess::SetFocus
    void SetFocus();
    // EXTERNAL: TITANIUM 0x0053AC7F Route_guess::IsCapturingKey_guess
    bool IsCapturingKey_guess();
    void LoadAddressBook_guess();
};

struct ItemCount_guess {
    // EXTERNAL: TITANIUM 0x00597C00 ItemCount_guess::Count_guess
    int Count_guess();
};

struct IniSettings_guess {
    // EXTERNAL: TITANIUM 0x004AE514 IniSettings_guess::SetInt_guess
    void SetInt_guess(int value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE5AF IniSettings_guess::Set_guess
    void Set_guess(bool value_guess, const char* section_guess, const char* key_guess);
};

#define g_inverseMouse_guess EQ_GLOBAL(char, 0x00923840)
#define g_mouseActive_guess EQ_GLOBAL(char, 0x009237B8)
#define g_mouseSensitivity_guess EQ_GLOBAL(int, 0x009237DC)
#define g_iniSettings_guess EQ_GLOBAL(IniSettings_guess*, 0x00988DF0)

// Mouse page WndNotification: checkboxes on click (1), the sensitivity slider on 0xE. The slider's
// 8 ticks are 0-100% on the label and setting 1-8 in [Options] MouseSensitivity.
// FUNCTION: TITANIUM 0x0053CA86
// @early-stop: budget, structural ndiff=50
void Route_guess::MousePageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess) {
    if (msg_guess == 1) {
        if (wnd_guess == (int)inverseMouse_guess) {
            g_iniSettings_guess->SetInt_guess(
                g_stateOne_guess = (g_inverseMouse_guess =
                    (*(const unsigned char*)&inverseMouse_guess->Checked != 0)),
                "Options", "InverseMouse");
        } else if (wnd_guess == (int)lookSpring_guess) {
            bool on_guess = lookSpring_guess->Checked;
            g_stateTwo_guess = on_guess;
            g_iniSettings_guess->SetInt_guess(on_guess, "Options", "LookSpring");
        } else if (wnd_guess == (int)mouseActive_guess) {
            bool on_guess = mouseActive_guess->Checked;
            g_mouseActive_guess = (char)on_guess;
            g_stateThree_guess = on_guess;
            g_iniSettings_guess->SetInt_guess(on_guess, "Options", "MouseActive");
        } else if (wnd_guess == (int)wheelZoom_guess) {
            bool on_guess = wheelZoom_guess->Checked;
            g_stateFour_guess = on_guess;
            g_iniSettings_guess->SetInt_guess(on_guess, "Options", "MouseWheelZoom");
        } else if (wnd_guess == (int)rightHanded_guess) {
            bool on_guess = rightHanded_guess->Checked;
            g_stateFive_guess = (char)on_guess;
            g_iniSettings_guess->Set_guess(on_guess, "Options", "MouseRightHanded");
        }
    } else if (msg_guess == 0xE && wnd_guess == sensitivityWnd_guess) {
        Str_guess text_guess;
        FormatString_guess(&text_guess, "%d %c", (info_guess * 100) / 7, '%');
        if (sensitivity_guess != 0) {
            sensitivity_guess->SetText_guess(&text_guess);
        }
        g_mouseSensitivity_guess = g_updateValue_guess = info_guess + 1;
        g_iniSettings_guess->SetInt_guess(g_updateValue_guess, "Options", "MouseSensitivity");
    }
}

// Routes a notification by the sender's page (`owner_guess`): General, Display (and its three particle
// sub-pages), Mouse, Keyboard, Chat, Color, Mail. The Mail page also gets message 0x22 from any sender,
// the file dialog's answer.
// FUNCTION: TITANIUM 0x0053F7B6
int Route_guess::Forward_guess(int owner_guess, int wnd_guess, int msg_guess, int info_guess) {
    if (owner_guess == fwdKey_guess) {
        GeneralPageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    } else if (owner_guess == id_guess || owner_guess == id4_guess || owner_guess == id8_guess ||
               owner_guess == idC_guess) {
        DisplayPageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    } else if (owner_guess == value2B4_guess) {
        MousePageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    } else if (owner_guess == state_guess) {
        KeyboardPageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    } else if (owner_guess == channel_guess) {
        ((ChannelPanel_guess*)this)->ChatPageWndNotification_guess((void*)wnd_guess, msg_guess, info_guess);
    } else if (owner_guess == this->owner_guess) {
        ColorPageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    } else {
        if (owner_guess != tail_guess && msg_guess != 0x22) {
            return -1;
        }
        MailPageWndNotification_guess(wnd_guess, msg_guess, info_guess);
    }
    return 0;
}

// Mail page WndNotification: the four checkboxes save to [MailOptions] as "1"/"0"; FileDialogButton opens the
// file dialog (the file selection window 0x00850C84, vtable slot 72). Message 0x22 with a path stores it as
// the address book and in PathToAddressBookField.
// FUNCTION: TITANIUM 0x0053CD93
// @early-stop: budget, structural ndiff=20
int Route_guess::MailPageWndNotification_guess(int wnd_guess, int message_guess, int info_guess) {
    OptionPage_guess* page_guess = 0;
    if (g_iniConfig_guess != 0) {
        page_guess = g_iniConfig_guess->GetOptionPage_guess();
    }
    if (message_guess == 1) {
        char checked_guess;
        if (wnd_guess == (int)forwardBox_guess) {
            checked_guess = forwardBox_guess->checked_guess;
            *(char*)&message_guess = checked_guess;
            FUN_0060bf60_guess("MailOptions", "ForwardingToEmailAddressInStationAccount",
                               checked_guess != 0 ? g_trueText_guess : g_falseText_guess);
            if (page_guess != 0) {
                page_guess->ApplyForward_guess(message_guess);
            }
        } else if (wnd_guess == (int)chatBox_guess) {
            checked_guess = chatBox_guess->checked_guess;
            *(char*)&message_guess = checked_guess;
            FUN_0060bf60_guess("MailOptions", "NewMailNotificationInChatWindow",
                               checked_guess != 0 ? g_trueText_guess : g_falseText_guess);
            if (page_guess != 0) {
                page_guess->ApplyChat_guess(message_guess);
            }
        } else if (wnd_guess == (int)audioBox_guess) {
            checked_guess = audioBox_guess->checked_guess;
            *(char*)&message_guess = checked_guess;
            FUN_0060bf60_guess("MailOptions", "NewMailAudioNotification",
                               checked_guess != 0 ? g_trueText_guess : g_falseText_guess);
            if (page_guess != 0) {
                page_guess->ApplyAudio_guess(message_guess);
            }
        } else if (wnd_guess == (int)deleteBox_guess) {
            checked_guess = deleteBox_guess->checked_guess;
            FUN_0060bf60_guess("MailOptions", "ConfirmDeletionFromAddressBook",
                               checked_guess != 0 ? g_trueText_guess : g_falseText_guess);
            if (page_guess != 0) {
                page_guess->flag_guess = checked_guess;
            }
        } else if (wnd_guess == (int)panel_guess) {
            pinstCFileSelectionWnd_guess->Slot72_guess(this, 0);
        }
    } else if (message_guess == 0x22 && *(const char*)info_guess != 0 && pinstCFileSelectionWnd_guess != 0) {
        if (pinstCFileSelectionWnd_guess->HasSelection_guess() == 1) {
            CXStr value_guess;
            pinstCFileSelectionWnd_guess->Fill_guess(&value_guess, 0);
            if (sink_guess != 0) {
                sink_guess->Slot63_guess(&value_guess);
            }
            FUN_0060bf60_guess("MailOptions", "AddressBook", value_guess);
            if (page_guess != 0) {
                addressFlag_guess = page_guess->sub_guess.Matches_guess(value_guess);
            }
        }
    }
    return 0;
}

// A click on the page tabs cancels any key capture and, for the Display (6) or Keyboard (7) page, shows
// context tip 6 or 7 in the tip window (0x009928E0). The colour picker's 0x20 goes to the Color page while a
// colour is pending; the rest is routed by the sender's parent (+0x28), then falls back to the base handler
// (0x005A2230).
// FUNCTION: TITANIUM 0x00541960
int Route_guess::WndNotification_guess(int wnd_guess, int msg_guess, int info_guess) {
    RouteInfo_guess* info = (RouteInfo_guess*)info_guess;
    if (wnd_guess == key_guess && msg_guess == 1) {
        ((StateGate_guess*)this)->Check_guess(info->payload_guess);
        if (info->id_guess == id_guess) {
            if (pinstCTipWndCONTEXT_guess == 0) {
                return 0;
            }
            pinstCTipWndCONTEXT_guess->selectTip_guess(6, 0);
        } else {
            if (info->id_guess != state_guess) {
                return 0;
            }
            if (pinstCTipWndCONTEXT_guess == 0) {
                return 0;
            }
            pinstCTipWndCONTEXT_guess->selectTip_guess(7, 0);
        }
        return 0;
    }
    int result = -1;
    if (wnd_guess == g_routeWnd_guess && msg_guess == 0x20) {
        if (owner_flag_guess != -1) {
            result = Forward_guess(owner_guess, wnd_guess, msg_guess, info_guess);
        }
    } else if (wnd_guess != 0) {
        int wnd_owner_guess = ((RouteWnd_guess*)wnd_guess)->owner_guess;
        result = Forward_guess(wnd_owner_guess, wnd_guess, msg_guess, info_guess);
    }
    if (result >= 0) {
        return result;
    }
    return WndNotification(wnd_guess, msg_guess, info_guess);
}

// Key messages: to CaptureKeyBinding_guess when the Keyboard page is shown; -1 otherwise.
// FUNCTION: TITANIUM 0x00541A0E
int ChildOwner_guess::Check_guess(int first_guess, int second_guess, int third_guess) {
    int result_guess = -1;
    if (child_guess != 0) {
        int value_guess = child_guess->Get_guess();
        result_guess = ((StateGate_guess*)this)->Check_guess(value_guess, first_guess, second_guess, third_guess);
    }
    return result_guess;
}


struct SetupA_guess {
    // EXTERNAL: TITANIUM 0x004B26F0 SetupA_guess::StepA_guess
    void StepA_guess();
    // EXTERNAL: TITANIUM 0x004B378B SetupA_guess::StepB_guess
    void StepB_guess();
};

struct SetupB_guess {
    // EXTERNAL: TITANIUM 0x004382FC SetupB_guess::Finish_guess
    void Finish_guess();
};

#define g_setupA_guess EQ_GLOBAL(SetupA_guess*, 0x0098599C)
#define g_setupB_guess EQ_GLOBAL(SetupB_guess*, 0x00905D24)

struct Rebuild_guess {
    // EXTERNAL: TITANIUM 0x0053F1F4 Rebuild_guess::Update_guess
    void Update_guess();
    void RestoreDefaultKeys_guess();
};

struct RebuildCallbackPrefix_guess {
    Rebuild_guess rebuild_guess;
    char padding_guess[0x15A];
};

struct RebuildCallback_guess {
    void OnConfirmationResult_guess(int event_guess, unsigned char flags_guess, int unused_guess);
};

struct RebuildCallbackOwner_guess : RebuildCallbackPrefix_guess, RebuildCallback_guess {
};

// Restores the default key bindings (key manager 0x004B26F0, 0x004B378B), relists them and lets CDisplay
// reload them (0x004382FC). The Yes answer to OKP_DefaultKeysButton's confirmation (dialog id 100).
// FUNCTION: TITANIUM 0x0053F451
void Rebuild_guess::RestoreDefaultKeys_guess() {
    g_setupA_guess->StepA_guess();
    g_setupA_guess->StepB_guess();
    Update_guess();
    g_setupB_guess->Finish_guess();
}

// Confirmation-dialog result: id 100 restores the default keys, 101 the default colours, when the
// answer's flags have bit 0 or 2 (probably Yes or OK).
// FUNCTION: TITANIUM 0x0053F760
// @early-stop: budget, structural ndiff=13
void RebuildCallback_guess::OnConfirmationResult_guess(int event_guess, unsigned char flags_guess, int unused_guess) {
    switch (event_guess) {
    case 101:
        if ((flags_guess & 5) != 0) {
            RebuildCallbackOwner_guess& owner_guess = static_cast<RebuildCallbackOwner_guess&>(*this);
            ((TextColors_guess*)&owner_guess)->RestoreDefaultColors_guess();
        }
        break;
    case 100:
        if ((flags_guess & 5) != 0) {
            RebuildCallbackOwner_guess& owner_guess = static_cast<RebuildCallbackOwner_guess&>(*this);
            owner_guess.RebuildCallbackPrefix_guess::rebuild_guess.RestoreDefaultKeys_guess();
        }
        break;
    }
}

// Relists key commands whose category mask matches the filter combo's row (row 11 and others: all,
// 0x7FF); each row holds name, primary and alternate key, with the command index as item data.
// FUNCTION: TITANIUM 0x0053F1F4
void EntryList_guess::Update_guess() {
    if (results_guess != 0) {
        int mask_guess;
        switch (((ResultSelection_guess*)results_guess)->GetCurChoice_guess()) {
        case 0: mask_guess = 1; break;
        case 1: mask_guess = 2; break;
        case 2: mask_guess = 4; break;
        case 3: mask_guess = 8; break;
        case 4: mask_guess = 0x10; break;
        case 5: mask_guess = 0x20; break;
        case 6: mask_guess = 0x40; break;
        case 7: mask_guess = 0x80; break;
        case 8: mask_guess = 0x100; break;
        case 9: mask_guess = 0x200; break;
        case 10: mask_guess = 0x400; break;
        case 12: mask_guess = 0x800; break;
        default: mask_guess = 0x7FF; break;
        }
        list_guess->Slot76_guess();
        for (int i = 0; i < 0xF7; ++i) {
            if (entries_guess[i].value_guess & mask_guess) {
                RowData_guess row_guess;
                RowCell_guess name_guess;
                RowCell_guess first_guess;
                RowCell_guess second_guess;
                name_guess.text_guess = *(CXStr*)&entries_guess[i].text_guess;
                first_guess.text_guess =
                    ((SlotValue_guess*)g_pointerTable_guess->First_guess(i))->ToString_guess();
                second_guess.text_guess =
                    ((SlotValue_guess*)g_pointerTable_guess->Second_guess(i))->ToString_guess();
                row_guess.Append_guess(row_guess.field00_guess, &name_guess);
                row_guess.Append_guess(row_guess.field00_guess, &first_guess);
                row_guess.Append_guess(row_guess.field00_guess, &second_guess);
                row_guess.index_guess = i;
                list_guess->AddRow_guess(&row_guess);
            }
        }
    }
    ((ListOwner_guess*)this)->ColorKeyConflicts_guess();
}

// Keyboard page WndNotification: the filter combo relists; a click on a binding cell starts capture
// (that cell shows string 0x19C6 until a key arrives); OKP_DefaultKeysButton asks to restore the
// defaults (string 0x19CA, dialog id 100, 20 s).
// FUNCTION: TITANIUM 0x0053F47D
int Route_guess::KeyboardPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess) {
    if (msg_guess == 1) {
        if (wnd_guess == results2D8_guess) {
            ((EntryList_guess*)this)->Update_guess();
        } else if (wnd_guess == list2DC_guess) {
            if (((Route_guess*)this)->IsCapturingKey_guess()) {
                ((StateGate_guess*)this)->CancelKeyCapture_guess();
            }
            ((DockFrame_guess*)this)->firstState_guess = info_guess;
            int count_guess = ((ItemCount_guess*)((EntryList_guess*)this)->list_guess)->Count_guess();
            ((DockFrame_guess*)this)->secondState_guess = count_guess;
            if (count_guess > 0) {
                ((CellList_guess*)((EntryList_guess*)this)->list_guess)->SetCell_guess(
                    ((DockFrame_guess*)this)->firstState_guess, count_guess, -1);
                {
                    Str_guess text_guess(pStringTable->getString(0x19c6, 0));
                    ((RowList_guess*)((EntryList_guess*)this)->list_guess)->SetItemText(
                        ((DockFrame_guess*)this)->firstState_guess, ((DockFrame_guess*)this)->secondState_guess,
                        text_guess);
                }
                ((Route_guess*)this)->SetFocus();
            }
        } else if (wnd_guess == third2E0_guess) {
            pConfirmationDialogPool_guess->Activate(
                pinstCOptionsWnd_guess != 0 ? (void*)(pinstCOptionsWnd_guess + 0x15c) : 0,
                100, pStringTable->getString(0x19ca, 0), 0xc, 20000, 0, 1);
        }
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(CXStr* output_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060BFA0 FUN_0060bfa0_guess
void __cdecl FUN_0060bfa0_guess(const char* section_guess, const char* key_guess,
                                const char* default_guess, char* output_guess, unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060C030 FUN_0060c030_guess
int __cdecl FUN_0060c030_guess(const char* section_guess, const char* key_guess, int default_guess);

// Mail page from [MailOptions]: the address-book path (default <cwd>\userdata\AddressBook.txt) goes
// into PathToAddressBookField, which gets "/\:~" as its +0x22C string (probably the characters it
// refuses); then the four checkboxes, each also passed to pEverQuest's option page (0x00495250).
// FUNCTION: TITANIUM 0x0053B2DE
// @early-stop: budget, structural ndiff=22
void Route_guess::LoadAddressBook_guess() {
    OptionPage_guess* optionPage_guess = 0;
    if (g_iniConfig_guess != 0) {
        optionPage_guess = g_iniConfig_guess->GetOptionPage_guess();
    }

    char currentDirectory_guess[0x400];
    GetCurrentDirectoryA(0x3ff, currentDirectory_guess);

    CXStr addressBookPath_guess;
    FUN_005738b0_guess(&addressBookPath_guess, "%s\\userdata\\AddressBook.txt", currentDirectory_guess);
    char addressBookText_guess[0x100];
    FUN_0060bfa0_guess("MailOptions", "AddressBook", addressBookPath_guess, addressBookText_guess, 0xff);

    if (sink_guess != 0) {
        sink_guess->addressBookFilter_guess = CXStr("/\\:~");
        sink_guess->SetAddressBook_guess(CXStr(addressBookText_guess));
    }
    if (optionPage_guess != 0) {
        addressFlag_guess = optionPage_guess->sub_guess.Matches_guess(addressBookText_guess);
    }

    int value_guess = FUN_0060c030_guess(
        "MailOptions", "ForwardingToEmailAddressInStationAccount", 0);
    if (forwardBox_guess != 0) {
        forwardBox_guess->flagOwner_guess.SetCheck(value_guess != 0);
    }
    if (optionPage_guess != 0) {
        optionPage_guess->ApplyForward_guess(value_guess != 0);
    }

    value_guess = FUN_0060c030_guess("MailOptions", "NewMailNotificationInChatWindow", 0);
    if (chatBox_guess != 0) {
        chatBox_guess->flagOwner_guess.SetCheck(value_guess != 0);
    }
    if (optionPage_guess != 0) {
        optionPage_guess->ApplyChat_guess(value_guess != 0);
    }

    value_guess = FUN_0060c030_guess("MailOptions", "NewMailAudioNotification", 1);
    if (audioBox_guess != 0) {
        audioBox_guess->flagOwner_guess.SetCheck(value_guess != 0);
    }
    if (optionPage_guess != 0) {
        optionPage_guess->ApplyAudio_guess(value_guess != 0);
    }

    value_guess = FUN_0060c030_guess("MailOptions", "ConfirmDeletionFromAddressBook", 1);
    if (deleteBox_guess != 0) {
        deleteBox_guess->flagOwner_guess.SetCheck(value_guess != 0);
    }
    if (optionPage_guess != 0) {
        optionPage_guess->flag_guess = value_guess != 0;
    }
}

// Display page WndNotification. Checkboxes and combos save to [Options] or [Defaults] and apply at once;
// Show Helm sends OP_SpawnAppearance type 0x2B (AT_ShowHelm) for the local player; the fullscreen and
// windowed buttons both call ReinitMouse_guess. Sliders (message 0xE) set gamma (0.5 + n/10), clip
// plane and fog scale, the window fades on 0x0099D3EC, max FPS (frame delay 1000 / fps), LOD bias and
// the particle opacities. 0x0064AC34 and 0x0064AC48 are the INI keys "LoD" and "Sky".
// FUNCTION: TITANIUM 0x0053E405
// @early-stop: budget, structural ndiff=223
int Route_guess::DisplayPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess) {
    // Display page clicks: each control applies its setting at once and saves it ([Options] or [Defaults]).
    if (msg_guess == 1) {
        if (wnd_guess == (int)loadScreen_guess) {
            g_loadScreenMode_guess = loadScreen_guess->GetCurChoice_guess();
            g_iniConfig_guess->WriteInt_guess(g_loadScreenMode_guess, "Options", "LoadScreenMode");
        } else if (wnd_guess == (int)pcNames_guess) {
            if (pcNames_guess->Checked) {
                g_showPCNames_guess = 1;
                g_display_guess->SetPCNameSpriteState_guess(1);
            } else {
                g_showPCNames_guess = 0;
                g_display_guess->SetPCNameSpriteState_guess(0);
            }
            g_iniConfig_guess->WriteInt_guess(g_showPCNames_guess, "Options", "PCNames");
        } else if (wnd_guess == (int)npcNames_guess) {
            if (npcNames_guess->Checked) {
                g_showNPCNames_guess = 1;
                g_display_guess->SetNPCNameSpriteState_guess(1);
            } else {
                g_showNPCNames_guess = 0;
                g_display_guess->SetNPCNameSpriteState_guess(0);
            }
            g_iniConfig_guess->WriteInt_guess(g_showNPCNames_guess, "Options", "NPCNames");
        } else if (wnd_guess == (int)targetIndicator_guess) {
            unsigned char show_guess;
            if (targetIndicator_guess->Checked) {
                g_show3dTarget_guess = 1;
                show_guess = 1;
            } else {
                g_show3dTarget_guess = 0;
                show_guess = 0;
            }
            if (g_targetIndicator_guess != 0) {
                g_targetIndicator_guess->SetEnabled_guess(show_guess);
            }
            g_iniConfig_guess->WriteBool_guess(show_guess, "Options", "Show3dTargetIndicator");
        } else if (wnd_guess == (int)levelOfDetailBox_020c_guess) {
            if (levelOfDetailBox_020c_guess->Checked) {
                g_option2496C_guess = 1;
                setLOD_guess(1);
            } else {
                g_option2496C_guess = 0;
                setLOD_guess(0);
            }
            g_iniConfig_guess->WriteInt_guess(g_option2496C_guess, "Options", g_key4AC34_guess);
        } else if (wnd_guess == (int)showHelmBox_0210_guess) {
            char checked_guess = showHelmBox_0210_guess->Checked;
            OptionPacket_guess packet_guess;
            // Show helm goes to the zone as OP_SpawnAppearance (0x7C32) type 0x2B, and the head slot is
            // redrawn.
            packet_guess.code_guess = 0x2B;
            packet_guess.id_guess = g_selfSpawn_guess->id258_guess;
            packet_guess.value_guess = checked_guess != 0;
            if (g_pcView_guess != 0) {
                g_pcView_guess->field1A5C_guess = checked_guess;
                if (checked_guess == 1) {
                    g_selfSpawn_guess->field1B8_guess = checked_guess;
                    EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
                    g_display_guess->UpdateItemSlot_guess(
                        g_pcView_guess, 2,
                        ((CharInfoView_guess*)g_pcView_guess->GetCharInfo2())->part_guess.Get_guess(), 0);
                } else {
                    g_display_guess->UpdateItemSlot_guess(
                        g_pcView_guess, 2, 0,
                        ((CharInfoView_guess*)g_pcView_guess->GetCharInfo2())->part_guess.Get_guess());
                    EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
                    g_selfSpawn_guess->field1B8_guess = 0;
                }
            }
        } else if (wnd_guess == button224_guess) {
            pinstCVideoModesWnd_guess->Activate();
        } else if (wnd_guess == button29C_guess && g_optionWindowB_guess != 0) {
            g_optionWindowB_guess->Slot33_guess();
        } else if (wnd_guess == button22C_guess || wnd_guess == button228_guess) {
            ReinitMouse_guess();
        } else if (wnd_guess == combo230_guess) {
            if (info_guess == 0) {
                g_option24964_guess = 0;
                g_display_guess->field2D2C_guess = 0;
            } else if (info_guess == 1) {
                g_option24964_guess = 1;
                g_display_guess->field2D2C_guess = g_flag23C3C_guess != 0;
            } else if (info_guess == 2) {
                g_option24964_guess = 2;
                g_display_guess->field2D2C_guess = g_flag23C3C_guess != 0;
            }
            g_iniConfig_guess->WriteInt_guess(g_option24964_guess, "Options", g_key4AC48_guess);
        } else if (wnd_guess == spellDensity_guess) {
            if (info_guess == 0) {
                g_spellDensity_guess = 0.0f;
            } else if (info_guess == 1) {
                g_spellDensity_guess = 0.25f;
            } else if (info_guess == 2) {
                g_spellDensity_guess = 0.5f;
            } else if (info_guess == 3) {
                g_spellDensity_guess = 1.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_spellDensity_guess, "Defaults", "SpellParticleDensity");
        } else if (wnd_guess == spellCastFilter_guess) {
            g_spellCastFilter_guess = g_castFilters_guess[info_guess];
            g_iniConfig_guess->WriteInt_guess(g_spellCastFilter_guess, "Defaults", "SpellParticleCastFilter");
        } else if (wnd_guess == spellNearClip_guess) {
            if (info_guess == 0) {
                g_spellNearClip_guess = 2.0f;
            } else if (info_guess == 1) {
                g_spellNearClip_guess = 4.0f;
            } else if (info_guess == 2) {
                g_spellNearClip_guess = 6.0f;
            } else if (info_guess == 3) {
                g_spellNearClip_guess = 8.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_spellNearClip_guess, "Defaults", "SpellParticleNearClipPlane");
        } else if (wnd_guess == envDensity_guess) {
            if (info_guess == 0) {
                g_envDensity_guess = 0.0f;
            } else if (info_guess == 1) {
                g_envDensity_guess = 0.25f;
            } else if (info_guess == 2) {
                g_envDensity_guess = 0.5f;
            } else if (info_guess == 3) {
                g_envDensity_guess = 1.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_envDensity_guess, "Defaults", "EnvironmentParticleDensity");
            g_render36C_guess->SetEnvironmentDensity_guess(g_envDensity_guess);
        } else if (wnd_guess == envNearClip_guess) {
            if (info_guess == 0) {
                g_envNearClip_guess = 2.0f;
            } else if (info_guess == 1) {
                g_envNearClip_guess = 4.0f;
            } else if (info_guess == 2) {
                g_envNearClip_guess = 6.0f;
            } else if (info_guess == 3) {
                g_envNearClip_guess = 8.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_envNearClip_guess, "Defaults", "EnvironmentParticleNearClipPlane");
        } else if (wnd_guess == actorDensity_guess) {
            if (info_guess == 0) {
                g_actorDensity_guess = 0.0f;
            } else if (info_guess == 1) {
                g_actorDensity_guess = 0.25f;
            } else if (info_guess == 2) {
                g_actorDensity_guess = 0.5f;
            } else if (info_guess == 3) {
                g_actorDensity_guess = 1.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_actorDensity_guess, "Defaults", "ActorParticleDensity");
            g_render36C_guess->SetActorDensity_guess(g_actorDensity_guess);
        } else if (wnd_guess == actorCastFilter_guess) {
            g_actorCastFilter_guess = g_castFilters_guess[info_guess];
            g_iniConfig_guess->WriteInt_guess(g_actorCastFilter_guess, "Defaults", "ActorParticleCastFilter");
        } else if (wnd_guess == actorNearClip_guess) {
            if (info_guess == 0) {
                g_actorNearClip_guess = 2.0f;
            } else if (info_guess == 1) {
                g_actorNearClip_guess = 4.0f;
            } else if (info_guess == 2) {
                g_actorNearClip_guess = 6.0f;
            } else if (info_guess == 3) {
                g_actorNearClip_guess = 8.0f;
            }
            g_iniConfig_guess->WriteFloat_guess(g_actorNearClip_guess, "Defaults", "ActorParticleNearClipPlane");
        }
    // Slider moves: the label shows the value (mostly as a percent) and the setting is saved; the LOD slider
    // has named steps.
    } else if (msg_guess == 0xE) {
        if (wnd_guess == gammaSlider_guess) {
            int value_guess = info_guess;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", value_guess * 100 / 19, '%');
            if (gammaLabel_guess != 0) {
                gammaLabel_guess->SetText_guess(&text_guess);
            }
            g_floatA_guess = (float)(value_guess + 1);
            g_render364_guess->SetGamma_guess(g_floatA_guess * 0.1f + 0.5f);
            g_iniConfig_guess->WriteInt_guess((int)g_floatA_guess, "Defaults", "Gamma");
        } else if (wnd_guess == clipSlider_guess) {
            int value_guess = info_guess;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", value_guess * 100 / 20, '%');
            if (clipLabel_guess != 0) {
                clipLabel_guess->SetText_guess(&text_guess);
            }
            g_fogScale_guess = info_guess * 0.2f;
            g_dispatchA_guess = value_guess;
            if (g_fogScale_guess < 0.1f) {
                g_fogScale_guess = 0.1f;
            }
            g_iniConfig_guess->WriteInt_guess(value_guess, "Options", "ClipPlane");
            g_iniConfig_guess->WriteFloat_guess(g_fogScale_guess, "Options", "FogScale");
        } else if (wnd_guess == slider234_guess) {
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%.1f", info_guess * 0.5f);
            if (label238_guess != 0) {
                label238_guess->SetText_guess(&text_guess);
            }
            g_statSource_guess->SetA_guess(info_guess * 500);
        } else if (wnd_guess == slider23C_guess) {
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%.1f", info_guess * 0.5f + 0.5f);
            if (label240_guess != 0) {
                label240_guess->SetText_guess(&text_guess);
            }
            g_statSource_guess->SetB_guess((info_guess + 1) * 500);
        } else if (wnd_guess == slider244_guess) {
            unsigned char value_guess = info_guess + 0x1A;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", (info_guess + 0x1A) * 100 / 255, '%');
            if (label248_guess != 0) {
                label248_guess->SetText_guess(&text_guess);
            }
            g_statSource_guess->SetC_guess(value_guess);
        } else if (wnd_guess == slider24C_guess) {
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", info_guess * 100 / 255, '%');
            if (label250_guess != 0) {
                label250_guess->SetText_guess(&text_guess);
            }
            g_statSource_guess->SetD_guess(info_guess);
        } else if (wnd_guess == maxFpsSlider_guess) {
            int fps_guess = info_guess + 10;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, g_valueFormat_guess, fps_guess);
            if (maxFpsLabel_guess != 0) {
                maxFpsLabel_guess->SetText_guess(&text_guess);
            }
            g_dispatchB_guess = fps_guess;
            if (fps_guess > 0) {
                g_frameDelay_guess = 1000 / fps_guess;
            }
            g_iniConfig_guess->WriteInt_guess(fps_guess, "Options", "MaxFPS");
        } else if (wnd_guess == lodSlider_guess) {
            CXStr text_guess;
            switch (info_guess) {
            case 0: case 1: case 2: case 3: case 4:
                text_guess = "Very Low";
                break;
            case 5: case 6: case 7: case 8: case 9:
                text_guess = g_lowText_guess;
                break;
            case 11: case 12: case 13: case 14: case 15:
                text_guess = "High";
                break;
            case 16: case 17: case 18: case 19: case 20:
                text_guess = "Very High";
                break;
            default:
                text_guess = "Normal";
                break;
            }
            if (lodLabel_guess != 0) {
                lodLabel_guess->SetText_guess(&text_guess);
            }
            g_dispatchC_guess = info_guess;
            g_render368_guess->SetLodBias_guess(info_guess * g_lodScale_guess + g_lodBase_guess);
            g_iniConfig_guess->WriteInt_guess(g_dispatchC_guess, "Options", "LODBias");
        } else if (wnd_guess == spellOpacity_guess) {
            CXStr text_guess;
            float opacity_guess = info_guess * 0.01f;
            FUN_005738b0_guess(&text_guess, "%d %c", info_guess, '%');
            if (spellOpacityLabel_guess != 0) {
                spellOpacityLabel_guess->SetText_guess(&text_guess);
            }
            g_scaleA_guess = opacity_guess;
            g_iniConfig_guess->WriteFloat_guess(opacity_guess, "Defaults", "SpellParticleOpacity");
        } else if (wnd_guess == envOpacity_guess) {
            CXStr text_guess;
            float opacity_guess = info_guess * 0.01f;
            FUN_005738b0_guess(&text_guess, "%d %c", info_guess, '%');
            if (envOpacityLabel_guess != 0) {
                envOpacityLabel_guess->SetText_guess(&text_guess);
            }
            g_scaleB_guess = opacity_guess;
            g_iniConfig_guess->WriteFloat_guess(opacity_guess, "Defaults", "EnvironmentParticleOpacity");
            g_render36C_guess->SetEnvironmentOpacity_guess(opacity_guess);
        } else if (wnd_guess == actorOpacity_guess) {
            CXStr text_guess;
            float opacity_guess = info_guess * 0.01f;
            FUN_005738b0_guess(&text_guess, "%d %c", info_guess, '%');
            if (actorOpacityLabel_guess != 0) {
                actorOpacityLabel_guess->SetText_guess(&text_guess);
            }
            g_scaleC_guess = opacity_guess;
            g_iniConfig_guess->WriteFloat_guess(opacity_guess, "Defaults", "ActorParticleOpacity");
            g_render36C_guess->SetActorOpacity_guess(opacity_guess);
        }
    }
    return 0;
}

struct FontCombo_guess {
    // EXTERNAL: TITANIUM 0x0059C3B0 FontCombo_guess::GetChoiceText_guess
    CXStr GetChoiceText_guess();
};

struct FontService_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void SetFont_guess(int index_guess, int size_guess, const char* name_guess);   // slot 30
};

struct CharOptions_guess {
    virtual void Slot00_guess();
    virtual void SetOptionA_guess(int value_guess);   // slot 1
    virtual void SetOptionB_guess(int value_guess);   // slot 2
    virtual void SetOptionC_guess(int value_guess);   // slot 3
    int field4_guess;
    CharNode_guess* node_guess;                       // +0x08
    char padding_guess[0x120 - 0x0C];
    unsigned char table_guess[0xE24 - 0x120];         // +0x120
    unsigned char fieldE24_guess;                     // +0xE24
    char padding2_guess[0x1A21 - 0xE25];
    unsigned char field1A21_guess;                    // +0x1A21
    unsigned char field1A22_guess;                    // +0x1A22
    unsigned char field1A23_guess;                    // +0x1A23
};

struct SpawnState_guess {
    char padding_guess[0x258];
    unsigned short id258_guess;                       // +0x258
    char padding2_guess[0x264 - 0x25A];
    int value264_guess;                               // +0x264
    // EXTERNAL: TITANIUM 0x0047AA0B SpawnState_guess::SetNameSpriteTint
    void SetNameSpriteTint();
};

struct SoundManager_guess {
    // EXTERNAL: TITANIUM 0x0044B050 SoundManager_guess::SetEnvSounds_guess
    void SetEnvSounds_guess(unsigned char mute_guess);
    // EXTERNAL: TITANIUM 0x0044A71F SoundManager_guess::SetRealism_guess
    void SetRealism_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x0044A776 SoundManager_guess::SetMusicVolume_guess
    void SetMusicVolume_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x0044A753 SoundManager_guess::SetWaveVolume_guess
    void SetWaveVolume_guess(float value_guess);
};

struct ChatLayout_guess {
    // EXTERNAL: TITANIUM 0x00424642 ChatLayout_guess::UpdateAutoJoinChannels_guess
    void UpdateAutoJoinChannels_guess(CharOptions_guess* character_guess);
};

// EXTERNAL: TITANIUM 0x004685BA do_fastdrop_guess
void __cdecl do_fastdrop_guess(SpawnState_guess* spawn_guess, const char* text_guess);

#define g_fontService_guess EQ_GLOBAL(FontService_guess*, 0x0099E360)
#define g_fontNames_guess EQ_ARRAY(char*, 0x00799830)
#define g_charOptions_guess EQ_GLOBAL(CharOptions_guess*, 0x00905D00)
#define g_spawnState_guess EQ_GLOBAL(SpawnState_guess*, 0x00905CE4)
#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)
#define g_chatLayout_guess EQ_GLOBAL(ChatLayout_guess*, 0x0079DBD4)
#define g_playerUpdate_guess EQ_GLOBAL(int, 0x00923D94)

// General page WndNotification. Anonymous and roleplaying add or remove their bit in 0x00924954 and send
// it as OP_SpawnAppearance type 0x15 (AT_Anon); the auto-consent boxes send types 0x28-0x2A (group,
// raid, guild consent). Most boxes echo a string-table line (chat colour 0x111) and save to the INI.
// OGP_LoadSkinButton (+0x198) opens 0x00850BD8; OGP_SystemInfoButton (+0x19C) opens the system-info
// dialog (0x009927D0) when checked, else turns SendSystemInfo off. Route_guess's anonFlagBox_guess
// (+0x170) is really OGP_LootAutosplitCheckbox (strings 0x2F04/0x2F05).
// FUNCTION: TITANIUM 0x0053BF46
int Route_guess::GeneralPageWndNotification_guess(int wnd_guess, int msg_guess, int info_guess) {
    char buffer_guess[0x100];
    OptionPacket_guess packet_guess;
    // General page clicks: font, item destroy, guild invites, anonymous and roleplay, sounds, context menus,
    // tell windows, the no-confirm boxes, trade and item-drop combos. Anything the zone must know (anonymous,
    // roleplay and three more toggles) also goes out as OP_SpawnAppearance (0x7C32).
    if (msg_guess == 1) {
        if (wnd_guess == fontCombo_guess) {
            if (fontBox_guess != 0) {
                CXStr text_guess = fontBox_guess->GetChoiceText_guess();
                g_fontService_guess->SetFont_guess(g_textId_guess, -1, text_guess);
                sprintf(buffer_guess, "Font.%s.0", g_fontNames_guess[g_textId_guess]);
                g_iniConfig_guess->WriteCharIniString_guess(text_guess, "Fonts", buffer_guess);
                if (fontLabel_guess != 0) {
                    fontLabel_guess->SetText_guess(&text_guess);
                }
            }
        } else if (wnd_guess == (int)destroyBox_guess) {
            if (destroyBox_guess->Checked) {
                g_panelOne_guess = 1;
                pEverQuest->dsp_chat(pStringTable->getString(0x2F00, 0), 15, true);
            } else {
                g_panelOne_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x2EFF, 0), 15, true);
            }
            g_iniConfig_guess->WriteInt_guess(g_panelOne_guess, "Options", "Destroy");
        } else if (wnd_guess == (int)guildInvitesBox_guess) {
            g_panelTwo_guess = guildInvitesBox_guess->Checked ? 1 : 0;
            g_iniConfig_guess->WriteInt_guess(g_panelTwo_guess, "Options", "GuildInvites");
        } else if (wnd_guess == (int)lootAutosplitBox_0170_guess) {
            if (lootAutosplitBox_0170_guess->Checked) {
                g_charOptions_guess->table_guess[g_charOptions_guess->node_guess->vbaseOffset_0004_guess] = 1;
            } else {
                g_charOptions_guess->table_guess[g_charOptions_guess->node_guess->vbaseOffset_0004_guess] = 0;
            }
            if (g_charOptions_guess->table_guess[g_charOptions_guess->node_guess->vbaseOffset_0004_guess]) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2F04, 0), 0x111, true);
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x2F05, 0), 0x111, true);
            }
            g_iniConfig_guess->SendAutoSplit_guess();
        } else if (wnd_guess == (int)anonBox_guess) {
            if (anonBox_guess->Checked) {
                g_panelState_guess++;
                pEverQuest->dsp_chat(pStringTable->getString(0x2F02, 0), 0x111, true);
            } else {
                g_panelState_guess--;
                pEverQuest->dsp_chat(pStringTable->getString(0x2F03, 0), 0x111, true);
            }
            g_spawnState_guess->value264_guess = g_panelState_guess;
            packet_guess.code_guess = 0x15;
            packet_guess.id_guess = g_spawnState_guess->id258_guess;
            packet_guess.value_guess = g_spawnState_guess->value264_guess;
            EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
            g_charOptions_guess->fieldE24_guess = (unsigned char)g_spawnState_guess->value264_guess;
            g_playerUpdate_guess = 5;
            g_iniConfig_guess->SavePC_guess(0, 1, 0x12);
            g_iniConfig_guess->WriteInt_guess(g_panelState_guess, "Options", "Anonymous");
        } else if (wnd_guess == (int)popupOnPetBox_guess && pinstCPetInfoWnd_guess != 0) {
            pinstCPetInfoWnd_guess->SetShownPopup_guess(popupOnPetBox_guess->Checked);
        } else if (wnd_guess == (int)envSoundsBox_guess) {
            g_byte254EC_guess = envSoundsBox_guess->Checked;
            g_soundManager_guess->SetEnvSounds_guess(g_byte254EC_guess == 0);
            g_iniConfig_guess->WriteBool_guess(g_byte254EC_guess, "Defaults", "EnvSounds");
        } else if (wnd_guess == (int)combatMusicBox_guess) {
            g_panelCount_guess = combatMusicBox_guess->Checked;
            g_iniConfig_guess->WriteBool_guess(g_panelCount_guess != 0, "Defaults", "CombatMusic");
        } else if (wnd_guess == (int)contextMenusBox_guess) {
            g_byte254ED_guess = contextMenusBox_guess->Checked;
            g_iniConfig_guess->WriteMainBool_guess(g_byte254ED_guess, "Main", "ContextMenus");
        } else if (wnd_guess == (int)tellWindowsBox_guess) {
            g_byte254F4_guess = tellWindowsBox_guess->Checked;
            g_iniConfig_guess->WriteMainBool_guess(g_byte254F4_guess, "Main", "UseTellWindows");
        } else if (wnd_guess == (int)roleplayBox_guess) {
            if (roleplayBox_guess->Checked) {
                g_panelState_guess += 2;
                pEverQuest->dsp_chat(pStringTable->getString(0x33B1, 0), 0x111, true);
            } else {
                g_panelState_guess -= 2;
                pEverQuest->dsp_chat(pStringTable->getString(0x33B2, 0), 0x111, true);
            }
            g_spawnState_guess->value264_guess = g_panelState_guess;
            packet_guess.code_guess = 0x15;
            packet_guess.id_guess = g_spawnState_guess->id258_guess;
            packet_guess.value_guess = g_spawnState_guess->value264_guess;
            EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
            g_charOptions_guess->fieldE24_guess = (unsigned char)g_spawnState_guess->value264_guess;
            g_playerUpdate_guess = 5;
            g_iniConfig_guess->SavePC_guess(0, 1, 10);
            g_spawnState_guess->SetNameSpriteTint();
            g_iniConfig_guess->WriteInt_guess(g_panelState_guess, "Options", "Anonymous");
        } else if (wnd_guess == (int)aaNoConfirmBox_guess) {
            if (aaNoConfirmBox_guess->Checked) {
                g_panelFlagA_guess = 1;
                pEverQuest->dsp_chat(pStringTable->getString(0xFC8, 0), 0x111, true);
            } else {
                g_panelFlagA_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0xFC7, 0), 0x111, true);
            }
            g_iniConfig_guess->WriteInt_guess(g_panelFlagA_guess, "Options", "AANoConfirm");
        } else if (wnd_guess == (int)pointMerchantBox_guess) {
            if (pointMerchantBox_guess->Checked) {
                g_panelFlagB_guess = 1;
                pEverQuest->dsp_chat(pStringTable->getString(0x216B, 0), 0x111, true);
            } else {
                g_panelFlagB_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x216A, 0), 0x111, true);
            }
            g_iniConfig_guess->WriteInt_guess(g_panelFlagB_guess, "Options", "pointMerchantNoConfirm");
        } else if (wnd_guess == (int)leadershipBox_guess) {
            if (leadershipBox_guess->Checked) {
                g_panelFlagC_guess = 1;
                pEverQuest->dsp_chat(pStringTable->getString(0x2185, 0), 0x111, true);
            } else {
                g_panelFlagC_guess = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x2184, 0), 0x111, true);
            }
            g_iniConfig_guess->WriteInt_guess(g_panelFlagC_guess, "Options", "LeadershipNoConfirm");
        } else if (wnd_guess == button198_guess) {
            pinstCLoadskinWnd_guess->Activate();
        } else if (wnd_guess == (int)systemInfoButton_019c_guess) {
            if (systemInfoButton_019c_guess->Checked) {
                if (pinstCSystemInfoDialogBox_guess != 0) {
                    pinstCSystemInfoDialogBox_guess->Activate();
                }
            } else {
                g_byte254EE_guess = 0;
                g_iniConfig_guess->WriteBool_guess(g_byte254EE_guess, "Defaults", "SendSystemInfo");
            }
        } else if (wnd_guess == (int)leftClickBox_guess) {
            g_byte254EF_guess = leftClickBox_guess->Checked;
            g_iniConfig_guess->WriteBool_guess(g_byte254EF_guess, "Defaults", "LeftClickTargetHelp");
        } else if (wnd_guess == (int)autoDuckBox_guess) {
            g_byte254F6_guess = autoDuckBox_guess->Checked;
            g_iniConfig_guess->WriteBool_guess(g_byte254F6_guess, "Defaults", "AllowAutoDuck");
        } else if (wnd_guess == (int)autoStandBox_guess) {
            g_byte254F7_guess = autoStandBox_guess->Checked;
            g_iniConfig_guess->WriteBool_guess(g_byte254F7_guess, "Defaults", "AllowAutoStand");
        } else if (wnd_guess == (int)autojoinBox_guess) {
            g_byte254F8_guess = autojoinBox_guess->Checked;
            g_iniConfig_guess->WriteBool_guess(g_byte254F8_guess, "Defaults", "AutojoinHelp");
            g_chatLayout_guess->UpdateAutoJoinChannels_guess(g_charOptions_guess);
        } else if (wnd_guess == (int)charOptionABox_guess) {
            if (charOptionABox_guess->Checked) {
                g_charOptions_guess->SetOptionA_guess(1);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F40, 0), 0x111, true);
            } else {
                g_charOptions_guess->SetOptionA_guess(0);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F41, 0), 0x111, true);
            }
            packet_guess.code_guess = 0x28;
            packet_guess.id_guess = g_spawnState_guess->id258_guess;
            packet_guess.value_guess = g_charOptions_guess->field1A21_guess != 0;
            EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
        } else if (wnd_guess == (int)charOptionBBox_guess) {
            if (charOptionBBox_guess->Checked) {
                g_charOptions_guess->SetOptionB_guess(1);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F42, 0), 0x111, true);
            } else {
                g_charOptions_guess->SetOptionB_guess(0);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F43, 0), 0x111, true);
            }
            packet_guess.code_guess = 0x29;
            packet_guess.id_guess = g_spawnState_guess->id258_guess;
            packet_guess.value_guess = g_charOptions_guess->field1A22_guess != 0;
            EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
        } else if (wnd_guess == (int)charOptionCBox_guess) {
            if (charOptionCBox_guess->Checked) {
                g_charOptions_guess->SetOptionC_guess(1);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F44, 0), 0x111, true);
            } else {
                g_charOptions_guess->SetOptionC_guess(0);
                pEverQuest->dsp_chat(pStringTable->getString(0x1F45, 0), 0x111, true);
            }
            packet_guess.code_guess = 0x2A;
            packet_guess.id_guess = g_spawnState_guess->id258_guess;
            packet_guess.value_guess = g_charOptions_guess->field1A23_guess != 0;
            EQSendMessage(g_connection_guess, OP_SpawnAppearance, &packet_guess, 8, 1);
        } else if (wnd_guess == tradeCombo_guess) {
            if (info_guess == 0) {
                g_panelMode_guess = 2;
            } else if (info_guess == 1) {
                g_panelMode_guess = 1;
            } else if (info_guess == 2) {
                g_panelMode_guess = 0;
            }
            g_iniConfig_guess->WriteInt_guess(g_panelMode_guess, "Options", "Trade");
        } else if (wnd_guess == safeDropCombo_guess) {
            if (info_guess == 0) {
                do_fastdrop_guess(g_spawnState_guess, pStringTable->getString(0x3292, 0));
            } else if (info_guess == 1) {
                do_fastdrop_guess(g_spawnState_guess, pStringTable->getString(0x3293, 0));
            } else {
                do_fastdrop_guess(g_spawnState_guess, pStringTable->getString(0x32BD, 0));
            }
            g_iniConfig_guess->WriteInt_guess(g_panelSelect_guess, "Options", "NoSafeDrop");
        }
    // Sliders: sound realism, music and sound volume.
    } else if (msg_guess == 0xE) {
        if (wnd_guess == realismSlider_guess) {
            int percent_guess = info_guess * 100 / 20;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", percent_guess, '%');
            if (realismLabel_guess != 0) {
                realismLabel_guess->SetText_guess(&text_guess);
            }
            g_panelValueA_guess = info_guess;
            g_soundManager_guess->SetRealism_guess(percent_guess * 0.01f);
            g_iniConfig_guess->WriteInt_guess(g_panelValueA_guess, "Options", "Realism");
        } else if (wnd_guess == musicSlider_guess) {
            int percent_guess = info_guess * 100 / 20;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", percent_guess, '%');
            if (musicLabel_guess != 0) {
                musicLabel_guess->SetText_guess(&text_guess);
            }
            g_panelValueB_guess = info_guess;
            g_soundManager_guess->SetMusicVolume_guess(percent_guess * 0.01f);
            g_iniConfig_guess->WriteInt_guess(g_panelValueB_guess, "Defaults", "Music");
        } else if (wnd_guess == soundSlider_guess) {
            int percent_guess = info_guess * 100 / 20;
            CXStr text_guess;
            FUN_005738b0_guess(&text_guess, "%d %c", percent_guess, '%');
            if (soundLabel_guess != 0) {
                soundLabel_guess->SetText_guess(&text_guess);
            }
            g_panelValueC_guess = info_guess;
            g_soundManager_guess->SetWaveVolume_guess(percent_guess * 0.01f);
            g_iniConfig_guess->WriteInt_guess(g_panelValueC_guess, "Defaults", "SoundVolume");
        }
    }
    return 0;
}

struct OptionsPiece_guess {
    char padding_guess[0x60];
    unsigned int style_guess;  // +0x60
};

// Local polymorphic base for the window ctor: 0x005A3850 is CSidlScreenWnd's 5-argument ctor.
struct OptionsBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1OptionsBase_guess@@UAE@XZ
    virtual ~OptionsBase_guess();
    char pad004_guess[0x60];
    unsigned int style_guess;         // +0x64
    char pad068_guess[0x24];
    unsigned char field8c_guess;      // +0x8C
    char pad08d_guess[0x97];
    OptionsPiece_guess* piece_guess;  // +0x124
    char pad128_guess[0x34];
    // EXTERNAL: TITANIUM 0x005A3850 ??0OptionsBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    OptionsBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int version_guess, char* block_guess);
    // EXTERNAL: TITANIUM 0x0059DD20 OptionsBase_guess::FUN_0059dd20_guess
    void FUN_0059dd20_guess();
};

struct OptionsCombo_guess {
    // EXTERNAL: TITANIUM 0x0059C330 OptionsCombo_guess::SetColors_guess
    void SetColors_guess(unsigned long first_guess, unsigned long second_guess, unsigned long third_guess);
    // EXTERNAL: TITANIUM 0x0059C8D0 OptionsCombo_guess::InsertChoice_guess
    void InsertChoice_guess(const CXStr& text_guess);
};

struct OptionsSlider_guess {
    // EXTERNAL: TITANIUM 0x005BD180 OptionsSlider_guess::SetNumTicks_guess
    void SetNumTicks_guess(int count_guess);
};

struct OptionsEdit_guess {
    // EXTERNAL: TITANIUM 0x005B7EA0 OptionsEdit_guess::FUN_005b7ea0_guess
    void FUN_005b7ea0_guess(int value_guess);
};

struct OptionsList_guess : CListWnd {
    char pad140_guess[0x1C];
    unsigned char field15c_guess;  // +0x15C
    char pad15d_guess[0xF];
    unsigned int color16c_guess;   // +0x16C
    void RemoveStyle_guess(unsigned int style_guess) { WindowStyle &= ~style_guess; }
};

struct OptionsKeyEntry_guess {
    CXStr text_guess;
    int value_guess;
    // EXTERNAL: TITANIUM 0x0053ACD9 OptionsKeyEntry_guess::OptionsKeyEntry_guess
    OptionsKeyEntry_guess();
    // EXTERNAL: TITANIUM 0x0044830F OptionsKeyEntry_guess::~OptionsKeyEntry_guess
    ~OptionsKeyEntry_guess();
};

struct OptionsFontNames_guess {
    int count_guess;        // +0x00
    int field04_guess;
    int mask_guess;         // +0x08
    int shift_guess;        // +0x0C
    CXStr** blocks_guess;   // +0x10
};

struct OptionsVideo_guess {
    char pad00_guess[4];
    char windowed_guess;    // +0x04
    char IsWindowed_guess() { return windowed_guess; }
};

#define g_optionsFontNames_guess EQ_GLOBAL(OptionsFontNames_guess, 0x00988E10)
#define g_optionsVideo_guess EQ_GLOBAL(OptionsVideo_guess*, 0x0099E38C)

// EXTERNAL: TITANIUM 0x0060E2B9 ??_L@YGXPAXIHP6EX0@Z1@Z
// EXTERNAL: TITANIUM 0x00659F60 ??_7OptionsWnd_guess@@6BOptionsBase_guess@@@
// EXTERNAL: TITANIUM 0x0065A080 ??_7OptionsWnd_guess@@6BEntrySubfield_guess@@@
struct OptionsWnd_guess : OptionsBase_guess, EntrySubfield_guess {
    CXWnd* subwindows_guess;              // +0x160
    CSidlScreenWnd* generalPage_guess;    // +0x164
    CXWnd* w168_guess;
    CXWnd* w16c_guess;
    CXWnd* w170_guess;
    CXWnd* w174_guess;
    CXWnd* w178_guess;
    CXWnd* w17c_guess;
    CXWnd* w180_guess;
    CXWnd* w184_guess;
    CXWnd* w188_guess;
    CXWnd* w18c_guess;
    CXWnd* w190_guess;
    CXWnd* w194_guess;
    CXWnd* w198_guess;
    CXWnd* w19c_guess;
    CXWnd* w1a0_guess;
    CXWnd* w1a4_guess;
    CXWnd* w1a8_guess;
    CXWnd* w1ac_guess;
    CXWnd* w1b0_guess;
    CXWnd* w1b4_guess;
    CXWnd* w1b8_guess;
    CXWnd* w1bc_guess;
    OptionsCombo_guess* playerTradeCombobox_01c0_guess;
    OptionsCombo_guess* itemDroppingCombobox_01c4_guess;
    OptionsSlider_guess* s1c8_guess;
    CXWnd* w1cc_guess;
    OptionsSlider_guess* s1d0_guess;
    CXWnd* w1d4_guess;
    OptionsSlider_guess* s1d8_guess;
    CXWnd* w1dc_guess;
    CXWnd* w1e0_guess;
    OptionsCombo_guess* fontSelector_01e4_guess;
    CXWnd* w1e8_guess;
    CSidlScreenWnd* displayPage_guess;    // +0x1EC
    CXWnd* w1f0_guess;
    CSidlScreenWnd* spellPage_guess;      // +0x1F4
    CSidlScreenWnd* envPage_guess;        // +0x1F8
    CSidlScreenWnd* actorPage_guess;      // +0x1FC
    CXWnd* w200_guess;
    CXWnd* w204_guess;
    CXWnd* w208_guess;
    CXWnd* w20c_guess;
    CXWnd* w210_guess;
    OptionsSlider_guess* s214_guess;
    CXWnd* w218_guess;
    OptionsSlider_guess* s21c_guess;
    CXWnd* w220_guess;
    CXWnd* w224_guess;
    CXWnd* w228_guess;
    CXWnd* w22c_guess;
    OptionsCombo_guess* skyCombobox_0230_guess;
    OptionsSlider_guess* s234_guess;
    CXWnd* w238_guess;
    OptionsSlider_guess* s23c_guess;
    CXWnd* w240_guess;
    OptionsSlider_guess* s244_guess;
    CXWnd* w248_guess;
    OptionsSlider_guess* s24c_guess;
    CXWnd* w250_guess;
    OptionsSlider_guess* s254_guess;
    CXWnd* w258_guess;
    OptionsSlider_guess* s25c_guess;
    CXWnd* w260_guess;
    OptionsCombo_guess* spellParticlesDensityCombobox_0264_guess;
    OptionsCombo_guess* spellParticlesNearClipCombobox_0268_guess;
    OptionsCombo_guess* spellParticlesFilterCombobox_026c_guess;
    OptionsSlider_guess* s270_guess;
    CXWnd* w274_guess;
    OptionsCombo_guess* environmentParticlesDensityCombobox_0278_guess;
    OptionsCombo_guess* environmentParticlesNearClipCombobox_027c_guess;
    OptionsSlider_guess* s280_guess;
    CXWnd* w284_guess;
    OptionsCombo_guess* actorParticlesDensityCombobox_0288_guess;
    OptionsCombo_guess* actorParticlesNearClipCombobox_028c_guess;
    OptionsCombo_guess* actorParticlesFilterCombobox_0290_guess;
    OptionsSlider_guess* s294_guess;
    CXWnd* w298_guess;
    CXWnd* w29c_guess;
    int field2a0_guess;
    int field2a4_guess;
    unsigned int field2a8_guess;
    int field2ac_guess;
    int field2b0_guess;
    CSidlScreenWnd* mousePage_guess;      // +0x2B4
    CXWnd* w2b8_guess;
    CXWnd* w2bc_guess;
    CXWnd* w2c0_guess;
    CXWnd* w2c4_guess;
    CXWnd* w2c8_guess;
    OptionsSlider_guess* s2cc_guess;
    CXWnd* w2d0_guess;
    CSidlScreenWnd* keyboardPage_guess;   // +0x2D4
    OptionsCombo_guess* keyboardFilterCombobox_02d8_guess;
    OptionsList_guess* keyList_guess;     // +0x2DC
    CXWnd* w2e0_guess;
    OptionsKeyEntry_guess entries_guess[0xF7];  // +0x2E4
    int fielda9c_guess;
    int fieldaa0_guess;
    CSidlScreenWnd* chatPage_guess;       // +0xAA4
    OptionsList_guess* filterList_guess;  // +0xAA8
    OptionsCombo_guess* caac_guess;
    CSidlScreenWnd* colorPage_guess;      // +0xAB0
    int fieldab4_guess;
    CXWnd* wab8_guess;
    CXWnd* wabc_guess;
    OptionsList_guess* colorList_guess;   // +0xAC0
    CXWnd* mailPage_guess;                // +0xAC4
    OptionsEdit_guess* pathEdit_guess;    // +0xAC8
    int fieldacc_guess;
    CXWnd* wad0_guess;
    CXWnd* wad4_guess;
    CXWnd* wad8_guess;
    CXWnd* wadc_guess;
    CXWnd* wae0_guess;
    unsigned int tick_guess;              // +0xAE4
    OptionsWnd_guess(CXWnd* parent_guess);
    virtual ~OptionsWnd_guess();
};

// Screen OptionsWindow: finds every page and control by SIDL name, then fills them from the current
// settings. Combos get colours white/yellow/grey; slider tick counts set each range (0x15 = 21 steps
// for 0-100% in 5% steps, 0xE6 for alpha 26-255, 0x5B for 10-100 FPS, 0x65 for 0-100% opacity).
// FUNCTION: TITANIUM 0x0053F8DC
OptionsWnd_guess::OptionsWnd_guess(CXWnd* parent_guess)
    : OptionsBase_guess(parent_guess, "OptionsWindow", -1, 3, 0), subwindows_guess(0) {
    w168_guess = 0;
    w16c_guess = 0;
    w170_guess = 0;
    w174_guess = 0;
    w178_guess = 0;
    w188_guess = 0;
    w18c_guess = 0;
    w190_guess = 0;
    w194_guess = 0;
    w1a4_guess = 0;
    w198_guess = 0;
    w17c_guess = 0;
    w180_guess = 0;
    w184_guess = 0;
    playerTradeCombobox_01c0_guess = 0;
    itemDroppingCombobox_01c4_guess = 0;
    s1c8_guess = 0;
    w1cc_guess = 0;
    s1d0_guess = 0;
    w1d4_guess = 0;
    s1d8_guess = 0;
    w1dc_guess = 0;
    w19c_guess = 0;
    w1a0_guess = 0;
    w1a8_guess = 0;
    w1ac_guess = 0;
    w1b0_guess = 0;
    w1b4_guess = 0;
    w1b8_guess = 0;
    w1bc_guess = 0;
    w228_guess = 0;
    w22c_guess = 0;
    w1e0_guess = 0;
    fontSelector_01e4_guess = 0;
    w1e8_guess = 0;
    if (piece_guess != 0) {
        style_guess |= piece_guess->style_guess | 0x800;
        field8c_guess = 0x11;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        // Every control is looked up by its SIDL name, page by page: general, display (with the spell,
        // environment and actor particle sub-pages), mouse, keyboard, chat, colour, mail.
        subwindows_guess = ((CSidlScreenWnd*)this)->GetChildItem("OPTW_OptionsSubwindows");
        generalPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsGeneralPage");
        if (generalPage_guess != 0) {
            w168_guess = generalPage_guess->GetChildItem("OGP_FastItemDestroyCheckbox");
            w16c_guess = generalPage_guess->GetChildItem("OGP_GuildInvitesCheckbox");
            w170_guess = generalPage_guess->GetChildItem("OGP_LootAutosplitCheckbox");
            w174_guess = generalPage_guess->GetChildItem("OGP_AnonymousCheckbox");
            w178_guess = generalPage_guess->GetChildItem("OGP_RoleplayingCheckbox");
            w188_guess = generalPage_guess->GetChildItem("OGP_PetWindowPopupCheckbox");
            w18c_guess = generalPage_guess->GetChildItem("OGP_EnvSoundsCheckbox");
            w190_guess = generalPage_guess->GetChildItem("OGP_CombatMusicCheckbox");
            w194_guess = generalPage_guess->GetChildItem("OGP_AllowContextMenusCheckbox");
            w1a4_guess = generalPage_guess->GetChildItem("OGP_UseTellWindowsCheckbox");
            w198_guess = generalPage_guess->GetChildItem("OGP_LoadSkinButton");
            w19c_guess = generalPage_guess->GetChildItem("OGP_SystemInfoButton");
            w17c_guess = generalPage_guess->GetChildItem("OGP_AANoConfirmCheckbox");
            w180_guess = generalPage_guess->GetChildItem("OGP_AdvMerchantNoConfirmCheckbox");
            w184_guess = generalPage_guess->GetChildItem("OGP_LeadershipNoConfirmCheckbox");
            w1a0_guess = generalPage_guess->GetChildItem("OGP_LeftClickHelpText");
            w1a8_guess = generalPage_guess->GetChildItem("OGP_AllowAutoDuckCheckbox");
            w1ac_guess = generalPage_guess->GetChildItem("OGP_AllowAutoStandCheckbox");
            w1b0_guess = generalPage_guess->GetChildItem("OGP_Autojoin");
            w1b4_guess = generalPage_guess->GetChildItem("OGP_AutoConsentGroupCheckbox");
            w1b8_guess = generalPage_guess->GetChildItem("OGP_AutoConsentRaidCheckbox");
            w1bc_guess = generalPage_guess->GetChildItem("OGP_AutoConsentGuildCheckbox");
            playerTradeCombobox_01c0_guess = (OptionsCombo_guess*)generalPage_guess->GetChildItem("OGP_PlayerTradeCombobox");
            itemDroppingCombobox_01c4_guess = (OptionsCombo_guess*)generalPage_guess->GetChildItem("OGP_ItemDroppingCombobox");
            s1c8_guess = (OptionsSlider_guess*)generalPage_guess->GetChildItem("OGP_SoundRealismSlider");
            w1cc_guess = generalPage_guess->GetChildItem("OGP_SoundRealismValueLabel");
            s1d0_guess = (OptionsSlider_guess*)generalPage_guess->GetChildItem("OGP_MusicVolumeSlider");
            w1d4_guess = generalPage_guess->GetChildItem("OGP_MusicVolumeValueLabel");
            s1d8_guess = (OptionsSlider_guess*)generalPage_guess->GetChildItem("OGP_SoundVolumeSlider");
            w1dc_guess = generalPage_guess->GetChildItem("OGP_SoundVolumeValueLabel");
            w1e0_guess = generalPage_guess->GetChildItem("OGP_ChangeFont");
            fontSelector_01e4_guess = (OptionsCombo_guess*)generalPage_guess->GetChildItem("OGP_FontSelector");
            w1e8_guess = generalPage_guess->GetChildItem("OGP_CurrentFont");
        }
        if (fontSelector_01e4_guess != 0) {
            fontSelector_01e4_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
            for (int i = 0; i < g_optionsFontNames_guess.count_guess; i++) {
                fontSelector_01e4_guess->InsertChoice_guess(
                    g_optionsFontNames_guess.blocks_guess[i >> g_optionsFontNames_guess.shift_guess][i & g_optionsFontNames_guess.mask_guess]);
            }
        }
        if (playerTradeCombobox_01c0_guess != 0) {
            playerTradeCombobox_01c0_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (itemDroppingCombobox_01c4_guess != 0) {
            itemDroppingCombobox_01c4_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (s1c8_guess != 0) {
            s1c8_guess->SetNumTicks_guess(0x15);
        }
        if (s1d0_guess != 0) {
            s1d0_guess->SetNumTicks_guess(0x15);
        }
        if (s1d8_guess != 0) {
            s1d8_guess->SetNumTicks_guess(0x15);
        }
        displayPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsDisplayPage");
        if (displayPage_guess != 0) {
            spellPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("SpellParticlesPage");
            envPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("EnvironmentParticlesPage");
            actorPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("ActorParticlesPage");
            w1f0_guess = ((CSidlScreenWnd*)this)->GetChildItem("ODP_LoadScreenCombobox");
            w200_guess = displayPage_guess->GetChildItem("ODP_PCNamesCheckbox");
            w204_guess = displayPage_guess->GetChildItem("ODP_NPCNamesCheckbox");
            w208_guess = displayPage_guess->GetChildItem("ODP_ShowTargetRingCheckbox");
            w20c_guess = displayPage_guess->GetChildItem("ODP_LevelOfDetailCheckbox");
            w210_guess = displayPage_guess->GetChildItem("ODP_ShowHelmCheckbox");
            s214_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_GammaSlider");
            w218_guess = displayPage_guess->GetChildItem("ODP_GammaValueLabel");
            s21c_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_ClipPlaneSlider");
            w220_guess = displayPage_guess->GetChildItem("ODP_ClipPlaneValueLabel");
            w224_guess = displayPage_guess->GetChildItem("ODP_VideoModesButton");
            w228_guess = displayPage_guess->GetChildItem("ODP_SetFullscreenButton");
            w22c_guess = displayPage_guess->GetChildItem("ODP_SetWindowedButton");
            ((ActionOwner_guess*)this)->UpdateAction_guess(g_optionsVideo_guess->IsWindowed_guess());
            skyCombobox_0230_guess = (OptionsCombo_guess*)displayPage_guess->GetChildItem("ODP_SkyCombobox");
            s234_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_FadeDelaySlider");
            w238_guess = displayPage_guess->GetChildItem("ODP_FadeDelayValueLabel");
            s23c_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_FadeDurationSlider");
            w240_guess = displayPage_guess->GetChildItem("ODP_FadeDurationValueLabel");
            s244_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_WindowAlphaSlider");
            w248_guess = displayPage_guess->GetChildItem("ODP_WindowAlphaValueLabel");
            s24c_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_FadeToAlphaSlider");
            w250_guess = displayPage_guess->GetChildItem("ODP_FadeToAlphaValueLabel");
            s254_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_MaxFPSSlider");
            w258_guess = displayPage_guess->GetChildItem("ODP_MaxFPSSliderValueLabel");
            s25c_guess = (OptionsSlider_guess*)displayPage_guess->GetChildItem("ODP_LODBiasSlider");
            w260_guess = displayPage_guess->GetChildItem("ODP_LODBiasSliderValueLabel");
            if (spellPage_guess != 0) {
                spellParticlesDensityCombobox_0264_guess = (OptionsCombo_guess*)spellPage_guess->GetChildItem("ODP_SpellParticlesDensityCombobox");
                spellParticlesNearClipCombobox_0268_guess = (OptionsCombo_guess*)spellPage_guess->GetChildItem("ODP_SpellParticlesNearClipCombobox");
                spellParticlesFilterCombobox_026c_guess = (OptionsCombo_guess*)spellPage_guess->GetChildItem("ODP_SpellParticlesFilterCombobox");
                s270_guess = (OptionsSlider_guess*)spellPage_guess->GetChildItem("ODP_SpellParticlesOpacitySlider");
                w274_guess = spellPage_guess->GetChildItem("ODP_SpellParticlesOpacityValueLabel");
            } else {
                spellParticlesDensityCombobox_0264_guess = 0;
                spellParticlesNearClipCombobox_0268_guess = 0;
                spellParticlesFilterCombobox_026c_guess = 0;
                s270_guess = 0;
                w274_guess = 0;
            }
            if (envPage_guess != 0) {
                environmentParticlesDensityCombobox_0278_guess = (OptionsCombo_guess*)envPage_guess->GetChildItem("ODP_EnvironmentParticlesDensityCombobox");
                environmentParticlesNearClipCombobox_027c_guess = (OptionsCombo_guess*)envPage_guess->GetChildItem("ODP_EnvironmentParticlesNearClipCombobox");
                s280_guess = (OptionsSlider_guess*)envPage_guess->GetChildItem("ODP_EnvironmentParticlesOpacitySlider");
                w284_guess = envPage_guess->GetChildItem("ODP_EnvironmentParticlesOpacityValueLabel");
            } else {
                environmentParticlesDensityCombobox_0278_guess = 0;
                environmentParticlesNearClipCombobox_027c_guess = 0;
                s280_guess = 0;
                w284_guess = 0;
            }
            if (actorPage_guess != 0) {
                actorParticlesDensityCombobox_0288_guess = (OptionsCombo_guess*)actorPage_guess->GetChildItem("ODP_ActorParticlesDensityCombobox");
                actorParticlesNearClipCombobox_028c_guess = (OptionsCombo_guess*)actorPage_guess->GetChildItem("ODP_ActorParticlesNearClipCombobox");
                actorParticlesFilterCombobox_0290_guess = (OptionsCombo_guess*)actorPage_guess->GetChildItem("ODP_ActorParticlesFilterCombobox");
                s294_guess = (OptionsSlider_guess*)actorPage_guess->GetChildItem("ODP_ActorParticlesOpacitySlider");
                w298_guess = actorPage_guess->GetChildItem("ODP_ActorParticlesOpacityValueLabel");
            } else {
                actorParticlesDensityCombobox_0288_guess = 0;
                actorParticlesNearClipCombobox_028c_guess = 0;
                actorParticlesFilterCombobox_0290_guess = 0;
                s294_guess = 0;
                w298_guess = 0;
            }
            w29c_guess = displayPage_guess->GetChildItem("ODP_AdvancedButton");
        } else {
            w1f0_guess = 0;
            w200_guess = 0;
            w204_guess = 0;
            w208_guess = 0;
            w20c_guess = 0;
            w210_guess = 0;
            s214_guess = 0;
            w218_guess = 0;
            s21c_guess = 0;
            w220_guess = 0;
            w224_guess = 0;
            w22c_guess = 0;
            w228_guess = 0;
            skyCombobox_0230_guess = 0;
            s234_guess = 0;
            w238_guess = 0;
            s23c_guess = 0;
            w240_guess = 0;
            s244_guess = 0;
            w248_guess = 0;
            s24c_guess = 0;
            w250_guess = 0;
            s254_guess = 0;
            w258_guess = 0;
            s25c_guess = 0;
            w260_guess = 0;
            spellParticlesDensityCombobox_0264_guess = 0;
            spellParticlesFilterCombobox_026c_guess = 0;
            spellParticlesNearClipCombobox_0268_guess = 0;
            s270_guess = 0;
            w274_guess = 0;
            environmentParticlesDensityCombobox_0278_guess = 0;
            environmentParticlesNearClipCombobox_027c_guess = 0;
            s280_guess = 0;
            w284_guess = 0;
            actorParticlesDensityCombobox_0288_guess = 0;
            actorParticlesFilterCombobox_0290_guess = 0;
            actorParticlesNearClipCombobox_028c_guess = 0;
            s294_guess = 0;
            w298_guess = 0;
            w29c_guess = 0;
        }
        if (skyCombobox_0230_guess != 0) {
            skyCombobox_0230_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (spellParticlesDensityCombobox_0264_guess != 0) {
            spellParticlesDensityCombobox_0264_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (spellParticlesFilterCombobox_026c_guess != 0) {
            spellParticlesFilterCombobox_026c_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (spellParticlesNearClipCombobox_0268_guess != 0) {
            spellParticlesNearClipCombobox_0268_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (environmentParticlesDensityCombobox_0278_guess != 0) {
            environmentParticlesDensityCombobox_0278_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (environmentParticlesNearClipCombobox_027c_guess != 0) {
            environmentParticlesNearClipCombobox_027c_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (actorParticlesDensityCombobox_0288_guess != 0) {
            actorParticlesDensityCombobox_0288_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (actorParticlesFilterCombobox_0290_guess != 0) {
            actorParticlesFilterCombobox_0290_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (actorParticlesNearClipCombobox_028c_guess != 0) {
            actorParticlesNearClipCombobox_028c_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (s214_guess != 0) {
            s214_guess->SetNumTicks_guess(0x14);
        }
        if (s21c_guess != 0) {
            s21c_guess->SetNumTicks_guess(0x15);
        }
        if (s234_guess != 0) {
            s234_guess->SetNumTicks_guess(0x15);
        }
        if (s23c_guess != 0) {
            s23c_guess->SetNumTicks_guess(0x14);
        }
        if (s244_guess != 0) {
            s244_guess->SetNumTicks_guess(0xE6);
        }
        if (s24c_guess != 0) {
            s24c_guess->SetNumTicks_guess(0x100);
        }
        if (s254_guess != 0) {
            s254_guess->SetNumTicks_guess(0x5B);
        }
        if (s25c_guess != 0) {
            s25c_guess->SetNumTicks_guess(0x15);
        }
        if (s270_guess != 0) {
            s270_guess->SetNumTicks_guess(0x65);
        }
        if (s280_guess != 0) {
            s280_guess->SetNumTicks_guess(0x65);
        }
        if (s294_guess != 0) {
            s294_guess->SetNumTicks_guess(0x65);
        }
        field2a8_guess = g_clock_guess->Ticks_guess();
        field2ac_guess = g_clock_guess->Rate_guess();
        field2a0_guess = g_clock_guess->Byte1_guess();
        field2a4_guess = g_clock_guess->Byte2_guess();
        field2b0_guess = 0;
        mousePage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsMousePage");
        if (mousePage_guess != 0) {
            w2b8_guess = mousePage_guess->GetChildItem("OMP_InvertYAxisCheckbox");
            w2bc_guess = mousePage_guess->GetChildItem("OMP_LookSpringCheckbox");
            w2c0_guess = mousePage_guess->GetChildItem("OMP_MouseLookCheckbox");
            w2c4_guess = mousePage_guess->GetChildItem("OMP_MouseWheelZoomCheckbox");
            w2c8_guess = mousePage_guess->GetChildItem("OMP_MouseHandedness");
            s2cc_guess = (OptionsSlider_guess*)mousePage_guess->GetChildItem("OMP_MouseSensitivitySlider");
            w2d0_guess = mousePage_guess->GetChildItem("OMP_MouseSensitivityValueLabel");
        } else {
            w2b8_guess = 0;
            w2bc_guess = 0;
            w2c0_guess = 0;
            s2cc_guess = 0;
            w2d0_guess = 0;
            w2c4_guess = 0;
            w2c8_guess = 0;
        }
        if (s2cc_guess != 0) {
            s2cc_guess->SetNumTicks_guess(8);
        }
        keyboardPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsKeyboardPage");
        if (keyboardPage_guess != 0) {
            keyboardFilterCombobox_02d8_guess = (OptionsCombo_guess*)keyboardPage_guess->GetChildItem("OKP_KeyboardFilterCombobox");
            // 0xFF8AA3FF below is the selected row's highlight (+0x16C), as on the chat and colour lists.
            keyList_guess = (OptionsList_guess*)keyboardPage_guess->GetChildItem("OKP_KeyboardAssignmentList");
            w2e0_guess = keyboardPage_guess->GetChildItem("OKP_DefaultKeysButton");
        } else {
            keyboardFilterCombobox_02d8_guess = 0;
            keyList_guess = 0;
            w2e0_guess = 0;
        }
        if (keyboardFilterCombobox_02d8_guess != 0) {
            keyboardFilterCombobox_02d8_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (keyList_guess != 0) {
            keyList_guess->RemoveStyle_guess(0x10000);
        }
        if (keyList_guess != 0) {
            keyList_guess->color16c_guess = 0xFF8AA3FF;
        }
        for (int j = 0; j < 0xF7; j++) {
            entries_guess[j].value_guess = 0;
        }
        fielda9c_guess = -1;
        fieldaa0_guess = -1;
        chatPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsChatPage");
        if (chatPage_guess != 0) {
            filterList_guess = (OptionsList_guess*)chatPage_guess->GetChildItem("FilterList");
            caac_guess = (OptionsCombo_guess*)chatPage_guess->GetChildItem("FilterComboBox");
        } else {
            filterList_guess = 0;
            caac_guess = 0;
        }
        if (caac_guess != 0) {
            caac_guess->SetColors_guess(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
        }
        if (filterList_guess != 0) {
            filterList_guess->SetColors(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
            filterList_guess->SetColumnJustification(0, 0);
            filterList_guess->SetColumnJustification(1, 1);
            filterList_guess->color16c_guess = 0xFF8AA3FF;
            filterList_guess->field15c_guess = 1;
        }
        colorPage_guess = (CSidlScreenWnd*)((CSidlScreenWnd*)this)->GetChildItem("OptionsColorPage");
        if (colorPage_guess != 0) {
            colorList_guess = (OptionsList_guess*)colorPage_guess->GetChildItem("ColorChooseList");
            wabc_guess = colorPage_guess->GetChildItem("UserColorChange");
            wab8_guess = colorPage_guess->GetChildItem("UserColorDefault");
            if (colorList_guess != 0) {
                colorList_guess->SetColors(0xFFFFFFFF, 0xFFFFFF00, 0xFF808080);
                colorList_guess->SetColumnJustification(0, 0);
                colorList_guess->SetColumnJustification(1, 1);
                colorList_guess->color16c_guess = 0xFF8AA3FF;
                colorList_guess->field15c_guess = 1;
            }
        } else {
            colorList_guess = 0;
            wabc_guess = 0;
            wab8_guess = 0;
        }
        fieldab4_guess = -1;
        // Then the pages are filled from the current settings, including the key list
        // (InitializeEntries_guess) and the address book.
        mailPage_guess = ((CSidlScreenWnd*)this)->GetChildItem("OptionsMailPage");
        pathEdit_guess = (OptionsEdit_guess*)((CSidlScreenWnd*)this)->GetChildItem("PathToAddressBookField");
        if (pathEdit_guess != 0) {
            pathEdit_guess->FUN_005b7ea0_guess(0);
        }
        wad0_guess = ((CSidlScreenWnd*)this)->GetChildItem("FileDialogButton");
        wad4_guess = ((CSidlScreenWnd*)this)->GetChildItem("MailForwardingCheckbox");
        wad8_guess = ((CSidlScreenWnd*)this)->GetChildItem("NewMailNotificationCheckbox");
        wadc_guess = ((CSidlScreenWnd*)this)->GetChildItem("NewMailAudioNotificationCheckbox");
        wae0_guess = ((CSidlScreenWnd*)this)->GetChildItem("AddressBookConfirmDeletionCheckbox");
        ((PaneOwner_guess*)this)->Refresh_guess();
        ((PaneOwnerWide_guess*)this)->RefreshAll_guess();
        ((UpdateTarget_guess*)this)->Update_guess();
        ((RowWindow_guess*)this)->RefreshRows_guess();
        ((RowHost_guess*)this)->RebuildRows_guess();
        ((EntryList_guess*)this)->ReloadKeyList_guess();
        ((EntryList_guess*)this)->InitializeEntries_guess();
        ((Route_guess*)this)->LoadAddressBook_guess();
        ((FlagPanel_guess*)this)->RefreshGeneralPage_guess();
        ((Settings_guess*)this)->Refresh_guess();
        ((StateOwner_guess*)this)->RefreshMousePage_guess();
        ((ChannelPanel_guess*)this)->Refresh_guess();
        ((TimedOwner_guess*)this)->RefreshColorSamples_guess();
        FUN_0059dd20_guess();
        tick_guess = g_display_guess->tick_guess;
    }
}
