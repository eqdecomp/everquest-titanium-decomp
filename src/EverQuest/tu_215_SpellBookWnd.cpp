// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 215: a hint from compare/tumap.py.
// The spell book, SpellBookWnd ("SpellBookWnd"): 400 book slots shown 16 at a time (two pages of 8), scribing
// scrolls, memorizing into the 9 gems (OP_MemorizeSpell), swapping (OP_SwapSpell) and deleting
// (OP_DeleteSpell) book slots, spell sets, and the "<name>-Spellbook.txt" dump. Obj_guess is the window
// (SpellBookWndView_guess); author_0168_guess is the gem being memorized, field_174 the slot being scribed
// (-1 none).
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <stdio.h>
#include "titanium/wnd/CBuffWindow.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CCastSpellWnd.h"

struct Indexer_guess {
    char pad_000[4];
    int vbaseOffset_0004_guess;
};

struct Searcher_guess {
    // EXTERNAL: TITANIUM 0x0041AA54 Searcher_guess::Find_guess
    int Find_guess(int index);
    // EXTERNAL: TITANIUM 0x0040E705 Searcher_guess::GetMemorizedSpell_guess
    int GetMemorizedSpell_guess(int index);
    // EXTERNAL: TITANIUM 0x004167E2 Searcher_guess::FUN_004167e2_guess
    int FUN_004167e2_guess();
};

struct Cursor_guess;

struct Event_guess {
    // EXTERNAL: TITANIUM 0x004106A3 Event_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int opcode, int first, int second, int third);
    // EXTERNAL: TITANIUM 0x0041911E Event_guess::Int_guess
    int Int_guess();
    // EXTERNAL: TITANIUM 0x00419081 Event_guess::Dex_guess
    int Dex_guess();
    // EXTERNAL: TITANIUM 0x0041B0DE Event_guess::HasSkill_guess
    int HasSkill_guess(int value);
    // EXTERNAL: TITANIUM 0x0041AFE5 Event_guess::HasSpell_guess
    int HasSpell_guess(int value);
    // EXTERNAL: TITANIUM 0x004192AA Event_guess::CanUseItem_guess
    int CanUseItem_guess(Cursor_guess* cursor, int flag);
    // EXTERNAL: TITANIUM 0x00417DAF Event_guess::IsSpellcaster_guess
    int IsSpellcaster_guess();
};

struct State_guess {
    char pad_000[8];
    union {
        Indexer_guess* indexer_008;  // the vbptr; vbaseOffset_0004_guess = the virtual base's offset from it
        int searcher_words_008[0x309e];
    };
    Event_guess event_c280;
    // EXTERNAL: TITANIUM 0x004BAAEB State_guess::HasAltAbility_guess
    char HasAltAbility_guess(int value);
};

struct StateBase_guess {
    char pad_000[8];
};

struct SpellState_guess : StateBase_guess, virtual Searcher_guess {
    char pad_00c[0xc274];
    Event_guess event_c280;
};

#define g_state_guess EQ_GLOBAL(State_guess*, 0x00905D00)
#define g_spellState_guess EQ_GLOBAL(SpellState_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value);

// EXTERNAL: TITANIUM 0x00556E1E CanStartMemorize_guess
char __stdcall CanStartMemorize_guess(int value);

struct Label_guess;

struct SpellBookWndView_guess {
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
    char pad_004[0x58];         // 0x004
    char field_05c;             // 0x05c
    char pad_05d;              // 0x05d
    char field_05e;             // 0x05e
    char pad_05f[0xfd];         // 0x05f
    int soulmarkList_015c_guess;              // 0x15c
    int currentPage_0160_guess;              // 0x160
    int selectedSlot_0164_guess;              // 0x164
    int pendingMemorizeGem_0168_guess;              // 0x168
    int pendingSpellId_016c_guess;              // 0x16c
    int memorizeTicksLeft_0170_guess;              // 0x170
    int field_174;              // 0x174
    int field_178;              // 0x178
    char wasSittingOnActivate_017c_guess;             // 0x17c
    char pad_17d[3];            // 0x17d
    int field_180;              // 0x180
    int field_184;              // 0x184
    int memorizeMode_0188_guess;              // 0x188
    char field_18c;             // 0x18c
    char pad_18d[3];            // 0x18d
    union {
        char field_190;
        int count_190;
    };                           // 0x190
    int memorizeSetSpells_0194_guess[10];          // 0x194
    int memorizeSetCount_01bc_guess;              // 0x1bc
    int pendingBookSlot_01c0_guess;              // 0x1c0
    int pendingGem_01c4_guess;              // 0x1c4
    char pad_1c8[0x40];          // 0x1c8
    int field_208;               // 0x208
    int spellSlots_020c_guess[16];            // 0x20c
    int field_24c;               // 0x24c
    int field_250;               // 0x250
    char pad_254[0x8];           // 0x254
    int field_25c;               // 0x25c
    Label_guess* leftPageLabel_0260_guess;      // 0x260 leftPageNum
    Label_guess* rightPageLabel_0264_guess;      // 0x264 rightPageNum
    char pad_268[0x28];          // 0x268: SBW_SpellName labels, one per button (see the function below)
    char field_290;              // 0x290
    int WndNotification_guess(CXWnd* sender, unsigned int msg, void* data);
    // EXTERNAL: TITANIUM 0x00555BAC SpellBookWndView_guess::FUN_00555bac_guess
    void FUN_00555bac_guess();
    // EXTERNAL: TITANIUM 0x00555C1E SpellBookWndView_guess::FillFields_guess
    void FillFields_guess();
    // EXTERNAL: TITANIUM 0x0055611C SpellBookWndView_guess::AddSoulmark_guess
    void AddSoulmark_guess(int kind, char* first, char* second, char* text);
    // EXTERNAL: TITANIUM 0x005A1CD0 SpellBookWndView_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x00556081 SpellBookWndView_guess::Apply_guess
    void Apply_guess(char* value, char* buffer);
    // EXTERNAL: TITANIUM 0x005A1880 SpellBookWndView_guess::OnShow
    void OnShow();
    char SoulmarkAboutToShow_guess();
    void SetValues_guess(int a, int b, int c);
    void Reset_guess();
    int GetSpellScribeTicksLeft_guess();
    void AbortPending_guess();
    void ConfirmDeleteSpell_guess(int type_guess, unsigned char flags_guess, int* data_guess);
    char AboutToHide_guess();
    int GetSpellMemTicksLeft_guess();
    // EXTERNAL: TITANIUM 0x00556852 SpellBookWndView_guess::~SpellBookWndView_guess
    ~SpellBookWndView_guess();
    void* Dtor_guess(unsigned char flags);
    void Advance_guess();
    void MemorizeSet(int* values_guess, int count_guess);
    void Run_guess();
    void FUN_00556f72_guess(int spellId, SpellBookWndView_guess* object);
    char StartMemorize_guess(int spellId, int gemIndex, char flag);
    // EXTERNAL: TITANIUM 0x004FD91E SpellBookWndView_guess::FUN_004fd91e_guess
    void FUN_004fd91e_guess(int first, int second, int third, int fourth, int fifth);
    void FinishMemorize_guess(int index, int value);
    void FUN_005575e3_guess(int value);
    void HandleDeleteSpellReply_guess(int index, int mode);
    void UpdateSpellBookDisplay_guess();
    void ResetPendingSpellAction_guess();
    char AboutToShow_guess();
    // EXTERNAL: TITANIUM 0x0059EDF0 SpellBookWndView_guess::SetFocus
    void SetFocus();
    void FinishScribe_guess(int first, int second);
    void SwapSpellBookSlots_guess(int first, int second);
    void FUN_0055833b_guess(int value);
    // EXTERNAL: TITANIUM 0x0055721C SpellBookWndView_guess::StartScribe_guess
    void StartScribe_guess(int index);
    void HandleSlotClick_guess(int index);
    void HandleSwapClick_guess(int index);
    // EXTERNAL: TITANIUM 0x0059DD30 SpellBookWndView_guess::FUN_0059dd30_guess
    char FUN_0059dd30_guess();
    void SetPage_guess(int value);
    int WndNotification_guess(int value, int msg, int param4);
    int HandleKeyboardMsg_guess(int opcode, int unused_guess, char flag);
    // EXTERNAL: TITANIUM 0x004FD36C SpellBookWndView_guess::IsOkToActivate_guess
    char IsOkToActivate_guess(int value);
    char CanStartMemorize_guess(int value);
    void MemorizeSpellById_guess(int first, int second);
    int OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 SpellBookWndView_guess::OnProcessFrame
    int OnProcessFrame();
};

struct ChangePosition_guess {
    char pad_000[0x120];
    char name_0120_guess[0x131];
    char standState_0251_guess;
    char playerClass_0252_guess;
    // EXTERNAL: TITANIUM 0x00483556 ChangePosition_guess::Notify_guess
    void Notify_guess(int value);
};

struct Gate_guess {
    // EXTERNAL: TITANIUM 0x005AE970 Gate_guess::FUN_005ae970_guess
    void FUN_005ae970_guess(SpellBookWndView_guess* object);
    // EXTERNAL: TITANIUM 0x005B0610 Gate_guess::FUN_005b0610_guess
    void FUN_005b0610_guess(SpellBookWndView_guess* object);
    // EXTERNAL: TITANIUM 0x005ADF60 Gate_guess::GetKeyboardFlags
    unsigned char GetKeyboardFlags(int first, int second);
};

struct Receiver_guess {
    // EXTERNAL: TITANIUM 0x005217B6 Receiver_guess::Dispatch_guess
    void Dispatch_guess(int result, unsigned char flag);
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::Get_guess
    char* Get_guess(int id, int first, int second, int third);
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::GetWithBuffer_guess
    char* GetWithBuffer_guess(int id, int first, int second, int third, char* buffer);
};

struct Dialog_guess {
    // EXTERNAL: TITANIUM 0x004982C6 Dialog_guess::Show_guess
    void Show_guess(const char* message);
    // EXTERNAL: TITANIUM 0x004982C6 ?Show_guess@Dialog_guess@@QAEXPBDHH@Z
    void Show_guess(const char* message, int first, int second);
    // EXTERNAL: TITANIUM 0x00498436 Dialog_guess::dsp_chat
    void dsp_chat(const char* message);
};

struct SetupOffset_guess {
    char pad_000[4];
    int vbaseOffset_0004_guess;
};

struct SetupRoot_guess {
    char pad_000[8];
    union {
        SetupOffset_guess* vbtable_0008_guess;
        unsigned char region_008[0xC278];
    };
};

struct SetupObject_guess {
    // EXTERNAL: TITANIUM 0x004586A5 SetupObject_guess::Apply_guess
    void Apply_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x0045868B SetupObject_guess::Set_guess
    void Set_guess(int first, int second);
};

struct Record_guess {
    char pad_000[0x1c];
    int value_01c;
    char pad_020[0x15d];
    unsigned char field_17d;    // 0x17d
    char pad_17e[0x15];
    char field_193;             // 0x193
    char pad_194[0x30];
    char field_1c4;             // 0x1c4
    char pad_1c5[0x43];
    int name_0208_guess;
    char pad_20c[0x3c];
    int field_248;              // 0x248
    // EXTERNAL: TITANIUM 0x0044E755 Record_guess::GetSpellLevelNeeded_guess
    unsigned char GetSpellLevelNeeded_guess(int value);
    // EXTERNAL: TITANIUM 0x0044E755 Record_guess::FUN_0044e755_noarg_guess
    unsigned char FUN_0044e755_noarg_guess();
};

struct RecordSource_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 RecordSource_guess::Get_guess
    Record_guess* Get_guess(int index);
};

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(unsigned int context, unsigned int type, char* text,
                    unsigned int size, unsigned int timeout, void* data, int zero);
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct MessageTable_guess {
    char pad_000[0xe8];
    int values[400];
};

struct WorldTable_guess {
    char pad_000[0x1a8];
    MessageTable_guess* table_1a8;
};

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output, int id, int code,
                                int zero1, int zero2, int zero3, int zero4,
                                int zero5, int zero6, int zero7, int zero8);
// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_text_guess
void __cdecl FUN_0046da4a_text_guess(char* output, int id, const char* text,
                                     int zero1, int zero2, int zero3, int zero4,
                                     int zero5, int zero6, int zero7, int zero8);

struct TickSource_guess {
    char pad_000[0x148];
    int tick_148;
};

#define g_00905ce4_guess EQ_GLOBAL(ChangePosition_guess*, 0x00905CE4)
#define g_gate_guess EQ_GLOBAL(Gate_guess*, 0x0099D3EC)
#define g_receiver_guess EQ_GLOBAL(Receiver_guess*, 0x00991B88)
#define g_stringTable_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_dialog_guess EQ_GLOBAL(Dialog_guess*, 0x00988DF0)
#define g_setup_guess EQ_GLOBAL(SetupRoot_guess*, 0x00905D00)
#define g_recordSource_guess EQ_GLOBAL(RecordSource_guess*, 0x00985CC8)
#define g_delivery_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)
#define pinstCSpellBookWnd_guess EQ_GLOBAL(unsigned int, 0x00850C30)
#define pinstCCursorAttachment_guess EQ_GLOBAL(SpellBookWndView_guess*, 0x00850C24)
#define g_tickSource_guess EQ_GLOBAL(TickSource_guess*, 0x00905D24)
#define g_lastTick_guess EQ_GLOBAL(int, 0x00991FF4)
#define g_targetLastTick_guess EQ_GLOBAL(int, 0x00991FF8)
#define g_timeoutCount_guess EQ_GLOBAL(int, 0x009248D0)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)

struct Holder_guess {
    char pad_000[0x15c];
    int field_15c;
};

struct Shell_guess {
    char pad_000[0x1a8];
    Holder_guess* pane_1a8;
};

#define g_shell_guess EQ_GLOBAL(Shell_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x00555EA6 FUN_00555ea6_guess
void __cdecl FUN_00555ea6_guess();

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

#define g_connection_guess EQ_GLOBAL(int, 0x00905CA0)

// EXTERNAL: TITANIUM 0x004912B1 FUN_004912b1_guess
void __cdecl FUN_004912b1_guess(int* connection, int opcode, int* payload, int size, int flag);

// EXTERNAL: TITANIUM 0x004EB547 FUN_004eb547_guess
void __cdecl FUN_004eb547_guess(const int* values, int count);

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

struct ChainSub_guess {
    char pad_000[0x78];
    int field_078;
    int Value_guess() { return field_078; }
    Cursor_guess* Cursor_guess_ptr() { return reinterpret_cast<Cursor_guess*>(field_078); }
};

struct ChainNode_guess {
    char pad_000[0x10];
    ChainSub_guess sub_010;
    char pad_08c[0x119c - 0x8c];
    unsigned char class_119c_guess;
    char pad_11a0[4];
    int level_11a4_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    ChainNode_guess* GetCharInfo2();
};

struct SearcherSlot_guess {
    char pad_000[4];
    EQ_CharacterProfileView_guess chain_004;
};

struct Cursor_guess {
    char pad_000[0x48];
    int field_048;
    // EXTERNAL: TITANIUM 0x005ECCC0 Cursor_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 Cursor_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Cursor_guess::FUN_005ecd20_guess
    int FUN_005ecd20_guess(int a);
    // EXTERNAL: TITANIUM 0x005ECD20 Cursor_guess::FUN_005ecd20_pair_guess
    int FUN_005ecd20_pair_guess(int a, int b);
    // EXTERNAL: TITANIUM 0x005E0EC0 Cursor_guess::FUN_005e0ec0_guess
    char* FUN_005e0ec0_guess();
};

// The virtual base of pCharData (types.h EQ_CharacterBase_guess, EQ_PC +0xC384): the vbptr at +8 plus the
// vbtable's offset. A macro, not a State_guess method: the code reads g_state_guess twice (an inline method
// reads it once and moves registers: 0x005575E3 identical -> structural).
#define g_stateBase_guess (reinterpret_cast<char*>(g_state_guess) + 8 + g_state_guess->indexer_008->vbaseOffset_0004_guess)
#define g_stateSearcher_guess (reinterpret_cast<Searcher_guess*>(g_stateBase_guess))
#define g_stateSlot_guess (reinterpret_cast<SearcherSlot_guess*>(g_stateBase_guess))

// Soulmark window AboutToShow (vtable 0x65CEC0 slot 49): empties the fields (0x00555EA6), resets the
// window (0x005A1CD0), and when a name was last inquired (+0x190) asks for that player's marks again
// (0x00556081, PID +0x290); never vetoes.
// FUNCTION: TITANIUM 0x0055643D
char SpellBookWndView_guess::SoulmarkAboutToShow_guess() {
    FUN_00555ea6_guess();
    this->Update_guess();
    if (field_190 != 0) {
        Apply_guess(&field_190, &field_290);
    }
    return 1;
}

struct WndText_guess {
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
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual CXStr Slot76_guess();
    // EXTERNAL: TITANIUM 0x005B7ED0 WndText_guess::GetText_guess
    CXStr GetText_guess();
};

struct WndTextSource_guess {
    // EXTERNAL: TITANIUM 0x00560D80 WndTextSource_guess::GetEntryText_guess
    CXStr GetEntryText_guess();
    // EXTERNAL: TITANIUM 0x00560D9E WndTextSource_guess::SetText_guess
    void SetText_guess(CXStr text);
    // EXTERNAL: TITANIUM 0x00560E32 WndTextSource_guess::Activate_guess
    void Activate_guess(SpellBookWndView_guess* object, int zero, const char* text);
};

#define pinstCTextEntryWnd_guess EQ_GLOBAL(WndTextSource_guess*, 0x00850C80)

struct Row_guess {
    char pad_000[0xc8];
    char text_0c8[0x100];
};

struct Slot454_guess {
    char pad_000[0x454];
    int field_454;
};

// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* dst, const char* src);
// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z
void __cdecl operator delete[](void* p);
// EXTERNAL: TITANIUM 0x00574A30 FUN_00574a30_guess
void __cdecl FUN_00574a30_guess(const char* text);

// Edit-box and dialog messages: message 10 cancels the pending action, 0xE enables OK only with text; the
// rest goes to the base class.
// FUNCTION: TITANIUM 0x00556472
// @early-stop: unknown, structural ndiff=80
int SpellBookWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int msg, void* data) {
    if (msg == 10) {
        field_190 = 0;
        field_290 = 0;
        Update_guess();
        return 0;
    }
    if (msg == 6) {
        if (sender == reinterpret_cast<CXWnd*>(field_180)) {
            return 0;
        }
    } else if (msg == 0xE) {
        if (sender == reinterpret_cast<CXWnd*>(field_180)) {
            {
                CXStr text = reinterpret_cast<WndText_guess*>(field_180)->Slot76_guess();
                reinterpret_cast<CXWnd*>(memorizeMode_0188_guess)->Enabled =
                    (text.Ptr != 0 && text.Ptr->length != 0);
            }
            {
                CXStr text = reinterpret_cast<WndText_guess*>(field_180)->Slot76_guess();
                reinterpret_cast<CXWnd*>(field_184)->Enabled =
                    (text.Ptr != 0 && text.Ptr->length != 0);
            }
            return 0;
        }
    } else if (msg == 0x21) {
        reinterpret_cast<CXWnd*>(soulmarkList_015c_guess)->Enabled = 1;
        if (FUN_0059dd30_guess() && data != 0) {
            int sel = reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetCurSel();
            if (sel != -1) {
                Row_guess* row_ptr = reinterpret_cast<Row_guess*>(this) +
                                     (reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetItemData(sel) + 2);
                char* buf;
                {
                    CXStr name = pinstCTextEntryWnd_guess->GetEntryText_guess();
                    int len = name.Ptr != 0 ? name.Ptr->length : 0;
                    buf = new char[len + 1];
                }
                if (buf != 0) {
                    {
                        CXStr again = pinstCTextEntryWnd_guess->GetEntryText_guess();
                        strcpy(buf, (char*)again);
                    }
                    FUN_00574a30_guess(buf);
                    pinstCTextEntryWnd_guess->SetText_guess(CXStr(buf));
                    strcpy(row_ptr->text_0c8, buf);
                    delete[] buf;
                }
                FUN_00555bac_guess();
                Slot33_guess();
            }
        }
    } else if (msg == 1) {
        if (sender == reinterpret_cast<CXWnd*>(soulmarkList_015c_guess)) {
            FillFields_guess();
            return 0;
        }
        if (sender == reinterpret_cast<CXWnd*>(memorizeMode_0188_guess)) {
            CXStr text = reinterpret_cast<WndText_guess*>(field_180)->GetText_guess();
            if (text.Ptr != 0 && text.Ptr->length > 0) {
                AddSoulmark_guess(2, &field_190, &field_290, (char*)text);
            }
        } else if (sender == reinterpret_cast<CXWnd*>(field_184)) {
            CXStr text = reinterpret_cast<WndText_guess*>(field_180)->GetText_guess();
            if (text.Ptr != 0 && text.Ptr->length > 0) {
                AddSoulmark_guess(1, &field_190, &field_290, (char*)text);
            }
        } else if (sender == reinterpret_cast<CXWnd*>(field_174)) {
            int sel = reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetCurSel();
            if (sel != -1) {
                Row_guess* rows = reinterpret_cast<Row_guess*>(this);
                int row = reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetItemData(sel);
                reinterpret_cast<Slot454_guess*>(&rows[row])->field_454 = 0;
                FUN_00555bac_guess();
                Slot33_guess();
            }
        } else if (sender == reinterpret_cast<CXWnd*>(field_178)) {
            int sel = reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetCurSel();
            if (sel != -1) {
                int row = reinterpret_cast<CListWnd*>(soulmarkList_015c_guess)->GetItemData(sel) + 2;
                Row_guess* row_ptr = reinterpret_cast<Row_guess*>(this) + row;
                char* message = g_stringTable_guess->GetWithBuffer_guess(
                    0xc49, 0, 0, 0xff, row_ptr->text_0c8);
                pinstCTextEntryWnd_guess->Activate_guess(this, 0, message);
                reinterpret_cast<CXWnd*>(soulmarkList_015c_guess)->Enabled = 0;
            }
        } else if (sender == *reinterpret_cast<CXWnd**>(&field_18c)) {
            Slot34_guess();
            field_190 = 0;
            field_290 = 0;
            Update_guess();
        }
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(sender, msg, data);
}

// Show/hide: on show, context tip 1 in the tip window (0x9928E0); on hide, updates the gem
// window (0x850C2C) and stands the player up (ChangePosition_guess(100))
// if still sitting ('n') from opening the book.
// FUNCTION: TITANIUM 0x005568DB
void SpellBookWndView_guess::Run_guess() {
    if (field_05c != 0) {
        if (pinstCTipWndCONTEXT_guess != 0) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(1, 0);
        }
    } else {
        if (pinstCCastSpellWnd_guess != 0) {
            pinstCCastSpellWnd_guess->Method_guess();
        }
        if (g_00905ce4_guess->standState_0251_guess == 'n' && wasSittingOnActivate_017c_guess == 0) {
            g_00905ce4_guess->Notify_guess(100);
        }
    }
    return OnShow();
}

// Queues the next memorize: book slot `a`, gem `b`, starting `c` ms from now.
// FUNCTION: TITANIUM 0x0055692F
void SpellBookWndView_guess::SetValues_guess(int a, int b, int c) {
    pendingBookSlot_01c0_guess = a;
    pendingGem_01c4_guess = b;
    field_184 = FUN_0046d655_guess() + c;
}

// Spell book: ends a spell set memorize run: clears +0x1BC and +0x188, and closes the book (slot 34,
// Deactivate) unless +0x18C is set.
// FUNCTION: TITANIUM 0x00556959
void SpellBookWndView_guess::Reset_guess() {
    memorizeSetCount_01bc_guess = 0;
    if (field_18c == 0) {
        Slot34_guess();
    }
    memorizeMode_0188_guess = 0;
}

// Scribe progress: counts field_178 down by 3 per tick; at 0 sends OP_MemorizeSpell (book slot, spell, type 0
// = scribe) and clears the scribe state.
// FUNCTION: TITANIUM 0x0055697D
int SpellBookWndView_guess::GetSpellScribeTicksLeft_guess() {
    if (field_174 == -1) {
        return 0;
    } else {
        int tick = g_tickSource_guess->tick_148;
        if ((unsigned)(tick - g_lastTick_guess) > 1) {
            field_178 -= 3;
            g_lastTick_guess = tick;
        }
        if (field_178 <= 0) {
            ++g_timeoutCount_guess;
            int payload[4];
            payload[2] = 0;
            payload[0] = field_174;
            payload[1] = pendingSpellId_016c_guess;
            FUN_004912b1_guess(&g_connection_guess, OP_MemorizeSpell, payload, 0x10, 1);
            pendingSpellId_016c_guess = -1;
            field_174 = -1;
            field_178 = 0;
            g_lastTick_guess = 0;
            return 0;
        }
        return field_178 * 1000 / 92;
    }
}

// Cancels what is in progress: closes the cursor attachment (0x850C24) when it holds type 1 (+0x15C),
// prints string 12045 "Aborting memorization of spell." or 12044 "Aborting scribing of spell.", and resets
// the queue.
// FUNCTION: TITANIUM 0x00556A2A
void SpellBookWndView_guess::AbortPending_guess() {
    int minusOne = -1;
    selectedSlot_0164_guess = minusOne;
    if (pinstCCursorAttachment_guess->soulmarkList_015c_guess == 1) {
        pinstCCursorAttachment_guess->Slot34_guess();
    }
    int zero = 0;
    if (pendingMemorizeGem_0168_guess != minusOne) {
        g_dialog_guess->Show_guess(
            g_stringTable_guess->Get_guess(0x2f0d, zero, 0x108, 1));
        pendingMemorizeGem_0168_guess = minusOne;
    } else if (field_174 != minusOne) {
        g_dialog_guess->Show_guess(
            g_stringTable_guess->Get_guess(0x2f0c, zero, 0x108, 1));
        field_174 = minusOne;
    }
    count_190 = minusOne;
    pendingGem_01c4_guess = minusOne;
    memorizeMode_0188_guess = zero;
    field_18c = (char)zero;
    memorizeSetCount_01bc_guess = zero;
}

// OP_DeleteSpell for book slot `value` (0-399).
// FUNCTION: TITANIUM 0x00556AD9
void __stdcall SendDeleteSpell_guess(int value) {
    if (value >= 0 && value < 400) {
        int payload_guess[2];
        payload_guess[1] = 0;
        payload_guess[0] = value;
        FUN_004912b1_guess(&g_connection_guess, OP_DeleteSpell, payload_guess, 8, 1);
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* p);

// Delete confirmation callback: Yes/OK (flags & 5) on message 100 deletes the slot; the request copy is freed
// either way.
// FUNCTION: TITANIUM 0x00556B11
// @early-stop: budget, structural ndiff=3
void SpellBookWndView_guess::ConfirmDeleteSpell_guess(int type_guess, unsigned char flags_guess,
                                   int* data_guess) {
    if (type_guess == 100 && (flags_guess & 5) != 0) {
        SendDeleteSpell_guess(*data_guess);
    }
    operator delete(data_guess);
}

// Scalar deleting destructor of the spell book window (vtable 0x65D020 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00556B3C
void* SpellBookWndView_guess::Dtor_guess(unsigned char flags) {
    this->SpellBookWndView_guess::~SpellBookWndView_guess();
    if (flags & 1) {
        operator delete(this);
    }
    return this;
}

// Spell book AboutToHide (vtable 0x65D020 slot 50): calls the window manager's 0x005AE970 (0x99D3EC)
// with this window and cancels any memorize or scribe in progress (0x00556A2A); never vetoes.
// FUNCTION: TITANIUM 0x00556B58
char SpellBookWndView_guess::AboutToHide_guess() {
    g_gate_guess->FUN_005ae970_guess(this);
    AbortPending_guess();
    return 1;
}

// Memorize progress: one step every ((spell level - player level) + 5) * 100 ms, at least 100 (bards differ);
// when done, sends OP_MemorizeSpell for the gem (probably type 1, memorize).
// FUNCTION: TITANIUM 0x00556B72
// @early-stop: budget, structural ndiff=38
int SpellBookWndView_guess::GetSpellMemTicksLeft_guess() {
    if (pendingMemorizeGem_0168_guess == -1) {
        return 0;
    }

    int decrement_guess;
    int rate_guess;
    rate_guess = g_stateSlot_guess->chain_004.GetCharInfo2()->level_11a4_guess;
    decrement_guess = 1;
    int current_guess = g_stateSlot_guess->chain_004.GetCharInfo2()->class_119c_guess;
    int value_guess = g_recordSource_guess->Get_guess(pendingSpellId_016c_guess)->GetSpellLevelNeeded_guess(
        current_guess);
    int interval_guess = ((value_guess - rate_guess) + 5) * 100;
    if (interval_guess < 100) {
        interval_guess = 100;
    }

    int tick_guess = g_tickSource_guess->tick_148;
    if ((unsigned)interval_guess < (unsigned)(tick_guess - g_targetLastTick_guess)) {
        g_targetLastTick_guess = tick_guess;
        if (g_stateSlot_guess->chain_004.GetCharInfo2()->class_119c_guess == 8) {
            int first_guess = g_state_guess->event_c280.Int_guess();
            int second_guess = g_state_guess->event_c280.Dex_guess();
            decrement_guess = (first_guess + second_guess) / 30 + 1;
        }

        int scale_guess = g_state_guess->event_c280.HasSkill_guess(0x1f);
        if (scale_guess < 10) {
            scale_guess = 10;
        }
        if (scale_guess != 0) {
            if (g_stateSlot_guess->chain_004.GetCharInfo2()->class_119c_guess == 8 &&
                g_state_guess->HasAltAbility_guess(0x11e) != 0) {
                decrement_guess *= 2;
            } else {
                decrement_guess += 2 + scale_guess / 10;
            }
        }

        int* remaining_guess = &memorizeTicksLeft_0170_guess;
        *remaining_guess -= decrement_guess;
        if (*remaining_guess < 0) {
            *remaining_guess = 0;
        }
        if (*remaining_guess == 0) {
            ++g_timeoutCount_guess;
            int payload_guess[4];
            payload_guess[0] = pendingMemorizeGem_0168_guess;
            payload_guess[1] = pendingSpellId_016c_guess;
            payload_guess[2] = 1;
            FUN_004912b1_guess(&g_connection_guess, OP_MemorizeSpell, payload_guess, 0x10, 1);
            g_targetLastTick_guess = 0;
            pinstCCursorAttachment_guess->Slot34_guess();
            pendingMemorizeGem_0168_guess = -1;
            pendingSpellId_016c_guess = -1;
            return 0;
        }
    }
    return memorizeTicksLeft_0170_guess * 1000 / 92;
}

// Book slot holding spell `value`, or -1.
// FUNCTION: TITANIUM 0x00556D54
int __cdecl FindSpellBookSlot_guess(int value) {
    int result = -1;
    if (g_state_guess != 0) {
        int index;
        for (index = 0; index < 400; ++index) {
            if (g_stateSearcher_guess->Find_guess(index) == value) {
                result = index;
                break;
            }
        }
    }
    return result;
}

// Spell sets: moves to the next gem in the list whose spell is in the book (gem 9 only with AA 0x146) and
// memorizes it 1 s later; resets at the end.
// FUNCTION: TITANIUM 0x00556D93
void SpellBookWndView_guess::Advance_guess() {
    int value_guess;
    int found_guess;
    while (++count_190 < memorizeSetCount_01bc_guess) {
        value_guess = memorizeSetSpells_0194_guess[count_190];
        if (IsValidSpellIndex_guess(value_guess) != 0) {
            found_guess = FindSpellBookSlot_guess(value_guess);
            if (found_guess != -1) {
                if (g_state_guess == 0 || count_190 != 8 ||
                    g_state_guess->event_c280.TotalSpellAffects_guess(0x146, 1, 0, 1) != 0) {
                    SetValues_guess(found_guess, count_190, 1000);
                    return;
                }
            }
        }
    }
    Reset_guess();
}

// Memorize check: nothing else in progress, hands free, spell valid, not already in a gem (12052) and the
// player's level high enough (12054).
// FUNCTION: TITANIUM 0x00556E1E
// @early-stop: budget, structural ndiff=22
char SpellBookWndView_guess::CanStartMemorize_guess(int value) {
    int result = 0;
    int index = 0;
    ++result;
    if (g_timeoutCount_guess != index ||
        pinstCCursorAttachment_guess->IsOkToActivate_guess(1) == 0 ||
        pendingMemorizeGem_0168_guess != -1 || field_174 != -1) {
        return 0;
    }
    if (IsValidSpellIndex_guess(
            g_stateSearcher_guess->Find_guess(value)) != 0) {
        do {
            if (g_stateSearcher_guess->GetMemorizedSpell_guess(index) ==
                g_stateSearcher_guess->Find_guess(value)) {
                g_dialog_guess->dsp_chat(
                    pStringTable->getString(0x2f14, 0));
                result = 0;
            }
        } while (++index < 9);
        Record_guess* record = g_recordSource_guess->Get_guess(
            g_stateSearcher_guess->Find_guess(value));
        if (record == 0) {
            return result;
        }
        int current = g_stateSlot_guess->chain_004.GetCharInfo2()->level_11a4_guess;
        unsigned char limit = g_stateSlot_guess->chain_004.GetCharInfo2()->class_119c_guess;
        if (current >= record->GetSpellLevelNeeded_guess(limit)) {
            return result;
        }
        g_dialog_guess->dsp_chat(
            pStringTable->getString(0x2f16, 0));
        result = 0;
    }
    result = 0;
    return result;
}

// Spell book: puts the spell in book slot `spellId` on the cursor when the memorize check passes
// (0x00556E1E): the cursor attachment (0x850C24) takes kind 1, the clicked button's icon (`object`
// +0x16C) and the book slot (0x004FD91E). The left-click handler (0x00558016) passes page * 8 +
// button.
// FUNCTION: TITANIUM 0x00556F72
void SpellBookWndView_guess::FUN_00556f72_guess(int spellId, SpellBookWndView_guess* object) {
    if (::CanStartMemorize_guess(spellId) != 0) {
        pinstCCursorAttachment_guess->FUN_004fd91e_guess(object->pendingSpellId_016c_guess, 1, spellId, 0, -1);
    }
}

// Starts memorizing book slot `spellId` into gem `gemIndex`; refuses a duplicate (12052) and announces 12053
// "Beginning to memorize %1...".
// FUNCTION: TITANIUM 0x00556FA1
char SpellBookWndView_guess::StartMemorize_guess(int spellId, int gemIndex, char flag) {
    char message[512];
    if (g_timeoutCount_guess == 0 && pendingMemorizeGem_0168_guess == -1 && field_174 == -1) {
        if (flag != 0) {
            int spell_guess = reinterpret_cast<Searcher_guess*>(
                reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(spellId);
            if (reinterpret_cast<Searcher_guess*>(
                    reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                    g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(gemIndex) == spell_guess) {
                return 0;
            }
        } else {
            if (IsValidSpellIndex_guess(reinterpret_cast<Searcher_guess*>(
                    reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                    g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(gemIndex))) {
                return 0;
            }
        }
        for (int index = 0; index < 9; ++index) {
            if (reinterpret_cast<Searcher_guess*>(
                    reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                    g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->GetMemorizedSpell_guess(index) ==
                reinterpret_cast<Searcher_guess*>(
                    reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                    g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(spellId)) {
                g_dialog_guess->dsp_chat(
                    pStringTable->getString(0x2f14, 0));
                return 0;
            }
        }
        FUN_0046da4a_guess(message, 0x2f15,
            g_recordSource_guess->Get_guess(reinterpret_cast<Searcher_guess*>(
                reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(spellId))->name_0208_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
        g_dialog_guess->Show_guess(message, 0x108, 1);
        pendingMemorizeGem_0168_guess = gemIndex;
        pendingSpellId_016c_guess = reinterpret_cast<Searcher_guess*>(
                        reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
                        g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(spellId);
        memorizeTicksLeft_0170_guess = 0x5c;
        return 1;
    }
    return 0;
}

// Memorize finished (server): stores the gem, shows 12007 "You have finished memorizing %1.", sets the gem's
// recast time, then closes the book or continues the spell set.
// FUNCTION: TITANIUM 0x0055712B
void SpellBookWndView_guess::FinishMemorize_guess(int index, int value) {
    char message[512];
    reinterpret_cast<SetupObject_guess*>(
        reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
        g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Apply_guess(index, value);
    FUN_0046da4a_guess(message, 0x2ee7,
                       g_recordSource_guess->Get_guess(value)->name_0208_guess,
                       0, 0, 0, 0, 0, 0, 0, 0);
    g_dialog_guess->Show_guess(message, 0x108, 1);
    reinterpret_cast<WorldTable_guess*>(g_00905ce4_guess)->table_1a8->values[index] =
        g_recordSource_guess->Get_guess(value)->value_01c + 1000 +
        g_tickSource_guess->tick_148;
    if (memorizeMode_0188_guess == 1) {
        if (field_18c == 0) {
            Slot34_guess();
        }
        memorizeMode_0188_guess = 0;
    } else if (memorizeMode_0188_guess == 2) {
        Advance_guess();
    }
}

// Scribe the scroll on the cursor into empty slot `value`. Refusals: a stack (6192), slot taken (12051),
// already scribed (12050), wrong class (12047), level too low (12048); else 12049 "Beginning to scribe
// %1...".
// FUNCTION: TITANIUM 0x0055721C
// @early-stop: budget, structural ndiff=32
void SpellBookWndView_guess::StartScribe_guess(int value) {
    SpellBookWndView_guess* self = this;
    char message[512];
    if (g_timeoutCount_guess != 0) {
        return;
    }
    if (pendingMemorizeGem_0168_guess != -1) {
        return;
    }
    if (field_174 != -1) {
        return;
    }
    SearcherSlot_guess* slot = g_stateSlot_guess;
    if (slot->chain_004.GetCharInfo2()->sub_010.Value_guess() == 0) {
        return;
    }
    slot = g_stateSlot_guess;
    if (slot->chain_004.GetCharInfo2()->sub_010.Cursor_guess_ptr()->GetItemClass_guess() != 0) {
        return;
    }
    slot = g_stateSlot_guess;
    Cursor_guess* cursor = slot->chain_004.GetCharInfo2()->sub_010.Cursor_guess_ptr();
    if (cursor->GetItemType_guess() != 0x14 ||
        g_state_guess->event_c280.CanUseItem_guess(cursor, 1) == 0) {
        g_dialog_guess->dsp_chat(pStringTable->getString(0xb5, 0));
        return;
    }
    if (reinterpret_cast<Searcher_guess*>(g_stateSlot_guess)->Find_guess(value) != -1) {
        g_dialog_guess->dsp_chat(pStringTable->getString(0x2f13, 0));
        return;
    }
    if (g_state_guess->event_c280.HasSpell_guess(cursor->FUN_005ecd20_guess(4)) != 0) {
        slot = g_stateSlot_guess;
        FUN_0046da4a_text_guess(message, 0x2f12,
                                slot->chain_004.GetCharInfo2()->sub_010.Cursor_guess_ptr()
                                    ->FUN_005e0ec0_guess(),
                                0, 0, 0, 0, 0, 0, 0, 0);
        g_dialog_guess->Show_guess(message, 0x108, 1);
        return;
        }
        slot = g_stateSlot_guess;
        unsigned char b = slot->chain_004.GetCharInfo2()->class_119c_guess;
    slot = g_stateSlot_guess;
    int limit = slot->chain_004.GetCharInfo2()->level_11a4_guess;
        if ((int)g_recordSource_guess->Get_guess(cursor->FUN_005ecd20_pair_guess(4, b))
            ->FUN_0044e755_noarg_guess() <= limit) {
        slot = g_stateSlot_guess;
        char c = g_recordSource_guess->Get_guess(cursor->FUN_005ecd20_pair_guess(
                     4, slot->chain_004.GetCharInfo2()->class_119c_guess))->FUN_0044e755_noarg_guess();
        if (c != -1) {
            if (cursor->field_048 > 1) {
                FUN_0046da4a_guess(message, 0x1830, 0, 0, 0, 0, 0, 0, 0, 0, 0);
                g_dialog_guess->Show_guess(message, 0x108, 1);
                return;
            }
            int a3 = cursor->FUN_005ecd20_guess(4);
            if (g_recordSource_guess->Get_guess(a3)->field_1c4 != 0) {
                return;
            }
            self->field_174 = value;
            int a4 = cursor->FUN_005ecd20_guess(4);
            self->pendingSpellId_016c_guess = a4;
            self->field_178 = 0x5c;
            FUN_0046da4a_guess(message, 0x2f11, g_recordSource_guess->Get_guess(a4)->name_0208_guess,
                               0, 0, 0, 0, 0, 0, 0, 0);
            g_dialog_guess->Show_guess(message, 0x108, 1);
            return;
        }
        }
        slot = g_stateSlot_guess;
        char c2 = g_recordSource_guess->Get_guess(cursor->FUN_005ecd20_pair_guess(
                  4, slot->chain_004.GetCharInfo2()->class_119c_guess))->FUN_0044e755_noarg_guess();
        if (c2 == -1) {
            slot = g_stateSlot_guess;
            FUN_0046da4a_text_guess(message, 0x2f0f,
                                slot->chain_004.GetCharInfo2()->sub_010.Cursor_guess_ptr()
                                    ->FUN_005e0ec0_guess(),
                                0, 0, 0, 0, 0, 0, 0, 0);
            g_dialog_guess->Show_guess(message, 0x108, 1);
            return;
        }
        slot = g_stateSlot_guess;
        unsigned char b2 = slot->chain_004.GetCharInfo2()->class_119c_guess;
        Record_guess* nameRecord = g_recordSource_guess->Get_guess(
            cursor->FUN_005ecd20_guess(4));
        FUN_0046da4a_text_guess(message, 0x2f10,
                       __itoa(g_recordSource_guess->Get_guess(cursor->FUN_005ecd20_pair_guess(4, b2))
                                  ->FUN_0044e755_noarg_guess(),
                              g_itoaBuffer_guess, 10),
                       nameRecord->name_0208_guess, 0, 0, 0, 0, 0, 0, 0);
    g_dialog_guess->Show_guess(message, 0x108, 1);
}

// Spell info for the slot under button `value` on this page.
// FUNCTION: TITANIUM 0x005575E3
void SpellBookWndView_guess::FUN_005575e3_guess(int value) {
    int index = currentPage_0160_guess * 8 + value;
    if (index < 400) {
        int result = g_stateSearcher_guess->Find_guess(index);
        if (IsValidSpellIndex_guess(result) != 0) {
            g_receiver_guess->Dispatch_guess(
                g_stateSearcher_guess->Find_guess(index),
                !(g_gate_guess->GetKeyboardFlags(1, -1) & 1));
        }
    }
}

// Text label (SetText 0x005BD810, ret 4): takes the CXStr by address.
struct Label_guess {
    // EXTERNAL: TITANIUM 0x005BD810 Label_guess::SetText_guess
    void SetText_guess(const CXStr& text);
};

struct Button_guess {
    char pad_000[0x158];
    int field_158;              // 0x158
};

#define g_counter_guess EQ_GLOBAL(int, 0x007944C4)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// Delete reply: `mode` 1 clears slot `index` with string 4028, otherwise 4029 "That spell could not be
// removed...".
// FUNCTION: TITANIUM 0x005579C8
void SpellBookWndView_guess::HandleDeleteSpellReply_guess(int index, int mode) {
    if (mode == 1) {
        if (index >= 0 && index < 400) {
            SetupObject_guess* setup = reinterpret_cast<SetupObject_guess*>(
                &g_setup_guess->region_008[g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess]);
            setup->Set_guess(index, -1);
            UpdateSpellBookDisplay_guess();
            char* message = g_stringTable_guess->Get_guess(0xfbc, 0, 0xf, 1);
            g_dialog_guess->Show_guess(message);
            selectedSlot_0164_guess = -1;
            UpdateSpellBookDisplay_guess();
            if (pinstCCastSpellWnd_guess != 0) {
                pinstCCastSpellWnd_guess->Rebuild_guess();
            }
        }
    } else {
        char* message = g_stringTable_guess->Get_guess(0xfbd, 0, 0xf, 1);
        g_dialog_guess->Show_guess(message);
    }
}

// Page numbers (pages are 1-based) and the 16 spell buttons for the current page; the swap source is
// highlighted.
// FUNCTION: TITANIUM 0x00557655
void SpellBookWndView_guess::UpdateSpellBookDisplay_guess() {
    char buffer[32];
    if (leftPageLabel_0260_guess != 0) {
        sprintf(buffer, "%d", currentPage_0160_guess + 1);
        CXStr text(buffer);
        leftPageLabel_0260_guess->SetText_guess(text);
    }
    if (rightPageLabel_0264_guess != 0) {
        sprintf(buffer, "%d", currentPage_0160_guess + 2);
        CXStr text(buffer);
        rightPageLabel_0264_guess->SetText_guess(text);
    }
    int index = currentPage_0160_guess * 8;
    int remaining = 16;
    for (int* slot = spellSlots_020c_guess; remaining != 0; ++slot, ++index, --remaining) {
        if (*slot != 0) {
            if (index < 400 && IsValidSpellIndex_guess(g_spellState_guess->Find_guess(index))) {
                Record_guess* record = g_recordSource_guess->Get_guess(
                    g_spellState_guess->Find_guess(index));
                if (record != 0) {
                    int value = record->field_248;
                    if (value < 0) {
                        value = 0;
                    }
                    if (selectedSlot_0164_guess == index) {
                        pinstCBuffWindowNORMAL_guess->SetBuffIcon_guess(
                            reinterpret_cast<Button_guess*>(*slot), value, g_counter_guess);
                        g_counter_guess++;
                        if (g_counter_guess > 1) {
                            g_counter_guess = -1;
                        }
                    } else {
                        pinstCBuffWindowNORMAL_guess->SetBuffIcon_guess(
                            reinterpret_cast<Button_guess*>(*slot), value, record->field_17d);
                    }
                    if (slot[23] != 0) {
                        CXStr name((const char*)record->name_0208_guess);
                        reinterpret_cast<Label_guess*>(slot[23])->SetText_guess(name);
                    }
                    continue;
                }
            }
            pinstCBuffWindowNORMAL_guess->SetBuffIcon_guess(reinterpret_cast<Button_guess*>(*slot), -1, 0);
            if (slot[23] != 0) {
                CXStr empty(g_emptyString_guess);
                reinterpret_cast<Label_guess*>(slot[23])->SetText_guess(empty);
            }
            reinterpret_cast<Button_guess*>(*slot)->field_158 = field_208;
        }
    }
}

// Asks 9065 "Are you absolutely sure you want to delete %1?" for a deletable spell (+0x193).
// FUNCTION: TITANIUM 0x005578BC
void __stdcall PromptDeleteSpell_guess(int param_1) {
    char buffer_guess[1024];
    if (param_1 < 0 || param_1 >= 400) {
        return;
    }
    if (IsValidSpellIndex_guess(g_stateSearcher_guess->Find_guess(param_1)) == 0) {
        return;
    }
    Record_guess* record_guess = g_recordSource_guess->Get_guess(
        g_stateSearcher_guess->Find_guess(param_1));
    if (record_guess == 0) {
        return;
    }
    if (record_guess->field_193 == 0) {
        return;
    }
    FUN_0046da4a_guess(buffer_guess, 0x2369,
        g_recordSource_guess->Get_guess(g_stateSearcher_guess->Find_guess(param_1))->name_0208_guess,
        0, 0, 0, 0, 0, 0, 0, 0);
    int* data_guess = new int;
    *data_guess = param_1;
    g_delivery_guess->Activate(
        pinstCSpellBookWnd_guess ? pinstCSpellBookWnd_guess + 0x15c : 0,
        100, buffer_guess, 12, 10000, data_guess, 1);
}

// Writes "<level>\t<name>" for every book spell to `filename`, default "<name>-Spellbook.txt".
// FUNCTION: TITANIUM 0x00557A73
void __stdcall SaveSpellbookFile_guess(char* filename) {
    char buffer[512];
    if (filename == 0 || *filename == '\0') {
        sprintf(buffer, "%s-Spellbook.txt", g_00905ce4_guess->name_0120_guess);
        filename = buffer;
    }
    // Walks 512 slots although the book has 400.
    FILE* file = fopen(filename, "w");
    if (file != 0) {
        for (int index = 0; index < 0x200; ++index) {
            if (IsValidSpellIndex_guess(g_spellState_guess->Find_guess(index))) {
                Record_guess* record = g_recordSource_guess->Get_guess(
                    g_spellState_guess->Find_guess(index));
                if (record != 0) {
                    unsigned char flag = g_00905ce4_guess->playerClass_0252_guess;
                    fprintf(file, "%d\t%s\n",
                            record->GetSpellLevelNeeded_guess(flag),
                            record->name_0208_guess);
                }
            }
        }
        fclose(file);
    }
}

// Clears the spell book selection (+0x164-+0x178 to -1 or 0), keeps the current time (+0x180) and
// redraws the two visible pages (0x00557655).
// FUNCTION: TITANIUM 0x00557B62
void SpellBookWndView_guess::ResetPendingSpellAction_guess() {
    selectedSlot_0164_guess = -1;
    field_178 = 0;
    pendingMemorizeGem_0168_guess = -1;
    pendingSpellId_016c_guess = -1;
    field_174 = -1;
    field_180 = g_tickSource_guess->tick_148;
    UpdateSpellBookDisplay_guess();
}

struct Shell2_guess {
    // EXTERNAL: TITANIUM 0x004A2F7A Shell2_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(int value);
    // EXTERNAL: TITANIUM 0x0049994C Shell2_guess::SetAutoFire_guess
    void SetAutoFire_guess(int value);
};

struct Pending_guess {
    char pad_000[0x48];
    float value_048;
};

#define g_shell2_guess EQ_ARRAY(Shell2_guess, 0x00923770)
#define g_pending_guess EQ_GLOBAL(Pending_guess*, 0x00905CF8)
#define g_flagA_guess EQ_GLOBAL(char, 0x009858C7)
#define g_flagB_guess EQ_GLOBAL(char, 0x009858C8)

// On open: refuses while moving (12085); otherwise sits the player down and turns off auto attack (12371) and
// auto fire (279).
// FUNCTION: TITANIUM 0x00557B9A
char SpellBookWndView_guess::AboutToShow_guess() {
    if (g_state_guess->event_c280.IsSpellcaster_guess() != 0 &&
        g_stateSearcher_guess->FUN_004167e2_guess() == 0) {
        if (g_pending_guess != 0 && g_pending_guess->value_048 > 0.0f) {
            g_dialog_guess->dsp_chat(
                pStringTable->getString(0x2f35, 0));
        } else {
            char state_guess = g_00905ce4_guess->standState_0251_guess;
            if (state_guess != 'i' && state_guess != 's' && state_guess != 'f') {
                if (state_guess != 'n') {
                    wasSittingOnActivate_017c_guess = 0;
                    g_00905ce4_guess->Notify_guess(0x6e);
                    if (g_flagA_guess != 0) {
                        g_shell2_guess->SetAutoAttack_guess(0);
                        g_dialog_guess->Show_guess(
                            g_stringTable_guess->Get_guess(0x3053, 0, 0xd, 1));
                    }
                    if (g_flagB_guess != 0) {
                        g_shell2_guess->SetAutoFire_guess(0);
                        g_dialog_guess->Show_guess(
                            g_stringTable_guess->Get_guess(0x117, 0, 0xd, 1));
                    }
                } else {
                    wasSittingOnActivate_017c_guess = 1;
                }
                ResetPendingSpellAction_guess();
                g_gate_guess->FUN_005b0610_guess(this);
                SetFocus();
                return 1;
            }
        }
        if (pinstCCastSpellWnd_guess != 0) {
            pinstCCastSpellWnd_guess->Method_guess();
        }
    }
    return 0;
}

// Memorizes a spell set (up to 9 gems) one gem after another; needs free hands (string 3345).
// FUNCTION: TITANIUM 0x00557CD8
// @early-stop: budget, structural ndiff=94
void SpellBookWndView_guess::MemorizeSet(int* values_guess, int count_guess) {
    count_190 = -1;
    if (!pinstCCursorAttachment_guess->IsOkToActivate_guess(1)) {
        g_dialog_guess->Show_guess(
            g_stringTable_guess->Get_guess(0xd11, 0, 0xf, 1));
        return;
    }
    field_18c = FUN_0059dd30_guess();
    Slot33_guess();
    if (!FUN_0059dd30_guess()) {
        return;
    }
    int list_guess[9];
    int i = 0;
    while (i < 9) {
        list_guess[i] = -1;
        ++i;
    }
    memorizeMode_0188_guess = 2;
    if (count_guess > 0) {
        int* source_guess = values_guess;
        i = 0;
        do {
            int value_guess = *source_guess;
            if (reinterpret_cast<Searcher_guess*>(
                    &g_state_guess->searcher_words_008[
                        g_state_guess->indexer_008->vbaseOffset_0004_guess / 4])
                    ->GetMemorizedSpell_guess(i) == value_guess) {
                memorizeSetSpells_0194_guess[i] = -1;
            } else {
                if (value_guess != -1) {
                    list_guess[i] = i;
                }
                memorizeSetSpells_0194_guess[i] = value_guess;
                for (int j = 0; j < i; ++j) {
                    if (memorizeSetSpells_0194_guess[j] == memorizeSetSpells_0194_guess[i]) {
                        memorizeSetSpells_0194_guess[j] = -1;
                        list_guess[j] = -1;
                    }
                }
            }
            ++source_guess;
            ++i;
        } while (i < count_guess);
    }
    memorizeSetCount_01bc_guess = count_guess;
    if (count_guess > 0) {
        i = 0;
        do {
            for (int j = 0; j < 9; ++j) {
                if (i != j &&
                    reinterpret_cast<Searcher_guess*>(
                        &g_state_guess->searcher_words_008[
                            g_state_guess->indexer_008->vbaseOffset_0004_guess / 4])
                        ->GetMemorizedSpell_guess(j) == memorizeSetSpells_0194_guess[i]) {
                    list_guess[j] = j;
                }
            }
            ++i;
        } while (i < count_guess);
    }
    FUN_004eb547_guess(list_guess, 9);
    Advance_guess();
}

// Memorizes spell `first` into gem `second` after 500 ms; needs free hands (string 3345).
// FUNCTION: TITANIUM 0x00557E55
void SpellBookWndView_guess::MemorizeSpellById_guess(int first, int second) {
    if (!pinstCCursorAttachment_guess->IsOkToActivate_guess(1)) {
        g_dialog_guess->Show_guess(g_stringTable_guess->Get_guess(0xd11, 0, 0xf, 1));
    } else {
        int found = FindSpellBookSlot_guess(first);
        if (CanStartMemorize_guess(found)) {
            field_18c = FUN_0059dd30_guess();
            Slot33_guess();
            if (FUN_0059dd30_guess()) {
                memorizeMode_0188_guess = 1;
                SetValues_guess(found, second, 500);
            }
        }
    }
}

// Per frame: closes when the player can no longer read, refreshes the page, and every 200 ms cancels on hide
// and drives scribing and memorizing.
// FUNCTION: TITANIUM 0x00557EE8
int SpellBookWndView_guess::OnProcessFrame_guess() {
    if (FUN_0059dd30_guess()) {
        if (g_stateSearcher_guess->FUN_004167e2_guess() != 0) {
            Slot34_guess();
            return 1;
        }
        if (selectedSlot_0164_guess != -1) {
            UpdateSpellBookDisplay_guess();
        }
        if ((unsigned)g_tickSource_guess->tick_148 > (unsigned)field_180 + 200U) {
            if (field_05c == 0 || field_05e != 0) {
                AbortPending_guess();
            }
            if (memorizeMode_0188_guess == 0) {
                SearcherSlot_guess* slot = g_stateSlot_guess;
                if (slot->chain_004.GetCharInfo2()->sub_010.Value_guess() == 0 &&
                    field_174 != -1) {
                    AbortPending_guess();
                }
            }
            field_180 = g_tickSource_guess->tick_148;
        }
        if (pendingGem_01c4_guess != -1 && (unsigned)g_tickSource_guess->tick_148 > (unsigned)field_184 &&
            g_timeoutCount_guess == 0) {
            if (CanStartMemorize_guess(pendingBookSlot_01c0_guess)) {
                StartMemorize_guess(pendingBookSlot_01c0_guess, pendingGem_01c4_guess, 0);
                pendingGem_01c4_guess = -1;
            } else {
                pendingGem_01c4_guess = -1;
                if (memorizeMode_0188_guess == 2) {
                    Advance_guess();
                }
            }
        }
    }
    return OnProcessFrame();
}

// Scribe finished (server): stores the spell in slot `first`, shows 12006 "You have finished scribing %1.",
// refreshes the book, clears the cursor attachment (0x850C24, Deactivate) and updates the gem window
// (0x850C2C).
// FUNCTION: TITANIUM 0x005581DE
void SpellBookWndView_guess::FinishScribe_guess(int first, int second) {
    char message[512];
    reinterpret_cast<SetupObject_guess*>(
        reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
        g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Set_guess(first, second);
    FUN_0046da4a_guess(message, 0x2ee6,
                       g_recordSource_guess->Get_guess(second)->name_0208_guess,
                       0, 0, 0, 0, 0, 0, 0, 0);
    g_dialog_guess->Show_guess(message, 0x108, 1);
    UpdateSpellBookDisplay_guess();
    pinstCCursorAttachment_guess->Slot34_guess();
    if (pinstCCastSpellWnd_guess != 0) {
        pinstCCastSpellWnd_guess->Rebuild_guess();
    }
}

// Swap reply: exchanges two book slots locally (string 1388 "Swapping Spell Book Scribe slots.").
// FUNCTION: TITANIUM 0x0055828A
void SpellBookWndView_guess::SwapSpellBookSlots_guess(int first, int second) {
    if (first >= 0 && second >= 0) {
        int firstSpell = reinterpret_cast<Searcher_guess*>(
            reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
            g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(first);
        g_dialog_guess->Show_guess(g_stringTable_guess->Get_guess(0x56c, 0, 0xf, 1));
        int secondSpell = reinterpret_cast<Searcher_guess*>(
            reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
            g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Find_guess(second);
        reinterpret_cast<SetupObject_guess*>(
            reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
            g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Set_guess(first, secondSpell);
        reinterpret_cast<SetupObject_guess*>(
            reinterpret_cast<char*>(&g_setup_guess->vbtable_0008_guess) +
            g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess)->Set_guess(second, firstSpell);
        selectedSlot_0164_guess = -1;
        UpdateSpellBookDisplay_guess();
    }
}

// Spell info for the button `value` (modifier-click).
// FUNCTION: TITANIUM 0x0055833B
void SpellBookWndView_guess::FUN_0055833b_guess(int value) {
    int index = 0;
    do {
        if (value == spellSlots_020c_guess[index]) {
            FUN_005575e3_guess(index);
            return;
        }
        ++index;
    } while (index < 16);
}

// Left click on button `index`: scribes into an empty slot while a scroll is on the cursor, else starts
// memorizing.
// FUNCTION: TITANIUM 0x00558016
void SpellBookWndView_guess::HandleSlotClick_guess(int index) {
    if (g_00905ce4_guess->standState_0251_guess == 'n' || g_shell_guess->pane_1a8->field_15c != 0) {
        int key = index + currentPage_0160_guess * 8;
        if (pinstCCursorAttachment_guess->soulmarkList_015c_guess == 2) {
            int spell = reinterpret_cast<Searcher_guess*>(
                &g_setup_guess->region_008[g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Find_guess(key);
            if (IsValidSpellIndex_guess(spell) == 0) {
                StartScribe_guess(key);
            }
        } else {
            FUN_00556f72_guess(key, reinterpret_cast<SpellBookWndView_guess*>(spellSlots_020c_guess[index]));
        }
    }
}

struct Pane_guess {
    char pad_000[0x48];
    float value_048;
};

// Right click on button `index`: picks a swap source (12046, plus 4027 for a deletable spell) or, on a second
// slot, sends OP_SwapSpell (8 bytes: both slots).
// FUNCTION: TITANIUM 0x00558091
void SpellBookWndView_guess::HandleSwapClick_guess(int index) {
    if (g_00905ce4_guess->standState_0251_guess == 'n' ||
        (g_shell_guess->pane_1a8->field_15c != 0 &&
         reinterpret_cast<Pane_guess*>(g_shell_guess->pane_1a8->field_15c)->value_048 == 0.0f)) {
        int key = index + currentPage_0160_guess * 8;
        if (key == selectedSlot_0164_guess) {
            selectedSlot_0164_guess = -1;
            UpdateSpellBookDisplay_guess();
        } else if (selectedSlot_0164_guess == -1) {
            selectedSlot_0164_guess = key;
            char* message = g_stringTable_guess->Get_guess(0x2f0e, 0, 0xf, 1);
            g_dialog_guess->Show_guess(message);
            if (selectedSlot_0164_guess >= 0 && selectedSlot_0164_guess < 400) {
                if (IsValidSpellIndex_guess(reinterpret_cast<Searcher_guess*>(
                        &g_setup_guess->region_008[g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Find_guess(selectedSlot_0164_guess))) {
                    Record_guess* record = g_recordSource_guess->Get_guess(
                        reinterpret_cast<Searcher_guess*>(
                            &g_setup_guess->region_008[g_setup_guess->vbtable_0008_guess->vbaseOffset_0004_guess])->Find_guess(selectedSlot_0164_guess));
                    if (record != 0 && record->field_193 != 0) {
                        char* name = g_stringTable_guess->Get_guess(0xfbb, 0, 0xf, 1);
                        g_dialog_guess->Show_guess(name);
                    }
                }
            }
        } else {
            int payload[2];
            payload[1] = key;
            payload[0] = selectedSlot_0164_guess;
            FUN_004912b1_guess(&g_connection_guess, OP_SwapSpell, payload, 8, 1);
        }
    }
}

// Shows the spread starting at page `value` (0-48, even pages on the left).
// FUNCTION: TITANIUM 0x00558361
void SpellBookWndView_guess::SetPage_guess(int value) {
    if (FUN_0059dd30_guess()) {
        if (value < 0) {
            currentPage_0160_guess = 0;
        } else if (value > 0x30) {
            currentPage_0160_guess = 0x30;
        } else {
            currentPage_0160_guess = value;
        }
        UpdateSpellBookDisplay_guess();
    }
}

struct ForwardTargetD7_guess {
    // EXTERNAL: TITANIUM 0x0051E0EA ForwardTargetD7_guess::CloseNewestItemDisplay_guess
    void CloseNewestItemDisplay_guess();
};

#define g_forwardTargetD7_guess EQ_GLOBAL(ForwardTargetD7_guess*, 0x00991B88)
#define g_wndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Clicks: Done, modifier-click info, page up/down by two pages, the gem buttons.
// FUNCTION: TITANIUM 0x0055839E
int SpellBookWndView_guess::WndNotification_guess(int value, int msg, int param4) {
    if (msg == 1) {
        if (value == field_25c) {
            Slot34_guess();
            return 1;
        }
        if ((g_wndManager_guess->GetKeyboardFlags() & 0xc) != 0) {
            FUN_0055833b_guess(value);
            return 1;
        }
        if (value == field_250) {
            SetPage_guess(currentPage_0160_guess + 2);
            return 1;
        }
        if (value == field_24c) {
            SetPage_guess(currentPage_0160_guess - 2);
            return 1;
        }
        int index = 0;
        do {
            if (value == spellSlots_020c_guess[index]) {
                HandleSlotClick_guess(index);
                return 1;
            }
            ++index;
        } while (index < 16);
    } else if (msg == 0x18) {
        FUN_0055833b_guess(value);
        return 1;
    } else if (msg == 0x1a) {
        g_forwardTargetD7_guess->CloseNewestItemDisplay_guess();
        return 1;
    } else if (msg == 3) {
        int index = 0;
        do {
            if (value == spellSlots_020c_guess[index]) {
                HandleSwapClick_guess(index);
                return 1;
            }
            ++index;
        } while (index < 16);
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(
        reinterpret_cast<CXWnd*>(value), msg, reinterpret_cast<void*>(param4));
}

struct FlagWnd_guess {
    char pad_000[0x5d];
    char flag_05d;
};

// Key commands while the book is open: 0xCB and 0xCD turn the page back or forward when that button is
// enabled, 0xD3 is handled too.
// FUNCTION: TITANIUM 0x0055848F
// @early-stop: budget, structural ndiff=30
int SpellBookWndView_guess::HandleKeyboardMsg_guess(int opcode, int unused_guess, char flag) {
    bool handled = false;
    if (FUN_0059dd30_guess()) {
        switch (opcode) {
        case 0xcb:
            if (flag != 0 && field_24c != 0 &&
                reinterpret_cast<FlagWnd_guess*>(field_24c)->flag_05d != 0) {
                SetPage_guess(currentPage_0160_guess - 2);
                handled = true;
            }
            break;
        case 0xcd:
            if (flag != 0 && field_250 != 0 &&
                reinterpret_cast<FlagWnd_guess*>(field_250)->flag_05d != 0) {
                SetPage_guess(currentPage_0160_guess + 2);
                handled = true;
            }
            break;
        case 0xd3:
            if (flag != 0) {
                PromptDeleteSpell_guess(selectedSlot_0164_guess);
                handled = true;
            }
            break;
        }
    }
    return handled - 1;
}

struct SpellBookSidlTemplate_guess {
    char pad_000[0x60];
    unsigned int style_060;                 // 0x060
};

// CTextureAnimation (0x4C bytes): ctor 0x005B1D90, assignment 0x004DBB3B.
struct SpellBookAnimation_guess {
    char data[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0SpellBookAnimation_guess@@QAE@XZ
    SpellBookAnimation_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ??4SpellBookAnimation_guess@@QAEAAU0@ABU0@@Z
    SpellBookAnimation_guess& operator=(const SpellBookAnimation_guess& other);
};

struct SpellBookButton_guess : CXWnd {
    char pad_11c[0x50];
    SpellBookAnimation_guess* animation_16c;    // 0x16c
};

struct SpellBookSidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 SpellBookSidlManager_guess::FindAnimation_guess
    SpellBookAnimation_guess* FindAnimation_guess(const CXStr& name);
};

#define g_sidlManager_guess EQ_GLOBAL(SpellBookSidlManager_guess*, 0x0099D3F4)

/* ---- CSpellBookWnd::CSpellBookWnd(CXWnd*) (0x00558521) ---------------------------------------------
 * Layout: include/titanium/types.h CSpellBookWnd (0x2A8). Two bases: CSidlScreenWnd at +0 and the
 * one-slot notification interface at +0x15C (own vtable 0x0063FD9C, inline dtor that purges itself from
 * the 0x00991E44 table, as CEverQuest's +8 base). */

struct SpellBookSidlBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 ??1SpellBookSidlBase_guess@@UAE@XZ
    virtual ~SpellBookSidlBase_guess();
    char pad_004[0x60];
    unsigned int windowStyle_064;           // 0x064 (CXWnd::WindowStyle)
    char pad_068[0xbc];
    SpellBookSidlTemplate_guess* sidlPiece_124; // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_128[0x30];
    int field_158;                          // 0x158
    // EXTERNAL: TITANIUM 0x005A3900 ??0SpellBookSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    SpellBookSidlBase_guess(CXWnd* parent, const CXStr& screen);
    // EXTERNAL: TITANIUM 0x005A2490 SpellBookSidlBase_guess::GetChildLabel_guess
    CXWnd* GetChildLabel_guess(const CXStr& name);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7SpellBookNotifier_guess@@6B@
struct SpellBookNotifier_guess {
    virtual void Notify_guess() = 0;
    ~SpellBookNotifier_guess() { Purge_guess(-1); }
    // EXTERNAL: TITANIUM 0x005482A0 SpellBookNotifier_guess::Purge_guess
    void Purge_guess(int value);
};

// EXTERNAL: TITANIUM 0x0065D020 ??_7SpellBookWnd_guess@@6BSpellBookSidlBase_guess@@@
// EXTERNAL: TITANIUM 0x0065D018 ??_7SpellBookWnd_guess@@6BSpellBookNotifier_guess@@@
struct SpellBookWnd_guess : SpellBookSidlBase_guess, SpellBookNotifier_guess {
    int field_160;                          // 0x160
    int pad_164;
    int field_168;                          // 0x168
    int pad_16c[2];
    int field_174;                          // 0x174
    int pad_178[3];
    int field_184;                          // 0x184
    int field_188;                          // 0x188
    unsigned char field_18c;                // 0x18c
    char pad_18d[0x2f];
    int field_1bc;                          // 0x1bc
    int field_1c0;                          // 0x1c0
    int field_1c4;                          // 0x1c4
    SpellBookAnimation_guess* spellAnims_1c8[16];  // 0x1c8
    SpellBookAnimation_guess* slotAnim_208;        // 0x208 A_SpellBookSlot
    SpellBookButton_guess* spellButtons_20c[16];   // 0x20c SBW_Spell0..15
    CXWnd* pageDownButton_24c;              // 0x24c
    CXWnd* pageUpButton_250;                // 0x250
    CXWnd* memPage0Button_254;              // 0x254
    CXWnd* memPage1Button_258;              // 0x258
    CXWnd* doneButton_25c;                  // 0x25c
    CXWnd* leftPageNum_260;                 // 0x260
    CXWnd* rightPageNum_264;                // 0x264
    CXWnd* spellNames_268[16];              // 0x268 SBW_SpellName0..15
    SpellBookWnd_guess(CXWnd* parent);
    virtual ~SpellBookWnd_guess();
    virtual void Notify_guess();
};

// Binds SBW_Spell0-15, SBW_SpellName0-15, the page, MemPage and Done buttons and the page labels; loads
// A_SpellIcons and A_SpellBookSlot.
// FUNCTION: TITANIUM 0x00558521
SpellBookWnd_guess::SpellBookWnd_guess(CXWnd* parent) : SpellBookSidlBase_guess(parent, "SpellBookWnd") {
    field_168 = -1;
    field_174 = -1;
    field_1c0 = -1;
    field_1c4 = -1;
    field_184 = -1;
    field_160 = 0;
    field_188 = 0;
    field_18c = 0;
    field_1bc = 0;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_060 | 0x10000;
        field_158 = 1;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        SpellBookAnimation_guess* icons = g_sidlManager_guess->FindAnimation_guess("A_SpellIcons");
        slotAnim_208 = g_sidlManager_guess->FindAnimation_guess("A_SpellBookSlot");
        char name[0x100];
        for (int i = 0; i < 16; ++i) {
            sprintf(name, "SBW_Spell%d", i);
            spellButtons_20c[i] = (SpellBookButton_guess*)((CSidlScreenWnd*)this)->GetChildItem(name);
            spellAnims_1c8[i] = new SpellBookAnimation_guess;
            *spellAnims_1c8[i] = *icons;
            if (spellButtons_20c[i] != 0) {
                spellButtons_20c[i]->animation_16c = spellAnims_1c8[i];
            }
            sprintf(name, "SBW_SpellName%d", i);
            spellNames_268[i] = GetChildLabel_guess(name);
        }
        pageDownButton_24c = ((CSidlScreenWnd*)this)->GetChildItem("SBW_PageDown_Button");
        pageUpButton_250 = ((CSidlScreenWnd*)this)->GetChildItem("SBW_PageUp_Button");
        memPage0Button_254 = ((CSidlScreenWnd*)this)->GetChildItem("SBW_MemPage0_Button");
        memPage1Button_258 = ((CSidlScreenWnd*)this)->GetChildItem("SBW_MemPage1_Button");
        doneButton_25c = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        leftPageNum_260 = GetChildLabel_guess("SBW_LeftPageNum");
        rightPageNum_264 = GetChildLabel_guess("SBW_RightPageNum");
    }
}

// Polymorphic view of SpellBookAnimation (0x4C, no vptr), so delete calls the slot 0 dtor.
struct AnimationDeleter_guess {
    virtual ~AnimationDeleter_guess();
};

// Spell book window destructor: for each of the 16 spell buttons, detaches its icon (+0x16C) and deletes
// the matching animation copy (+0x1C8[i]).
// FUNCTION: TITANIUM 0x00556852
SpellBookWnd_guess::~SpellBookWnd_guess() {
    for (int i = 0; i < 16; ++i) {
        if (spellButtons_20c[i] != 0) {
            spellButtons_20c[i]->animation_16c = 0;
            if (spellAnims_1c8[i] != 0) {
                delete reinterpret_cast<AnimationDeleter_guess*>(spellAnims_1c8[i]);
            }
        }
    }
}
