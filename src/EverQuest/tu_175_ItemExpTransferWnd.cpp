// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 175: a hint from compare/tumap.py.
// CItemExpTransferWnd (screen "ItemExpTransferWnd"): moves item experience from one item to another. The From
// and To items are kept as id pairs (+0x80/+0x84 of the item), -1 = empty; the server prices the move through
// message 0x7E61 (not in EQEmu's Titanium table), 0x18 bytes: kind (2 preview, 3 confirm), both pairs.
// WndNotification (0x522798) sits in tu_176. CItemExpTransferWnd_guess is the window, DtorSub_guess its prompt owner.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <string.h>
#include <stdlib.h>
#include <new>

// EXTERNAL: TITANIUM 0x0060D970 strlen
// EXTERNAL: TITANIUM 0x006220E9 _itoa
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z

struct FlagTarget_guess {
    char pad_0[0x5d];
    unsigned char flag_guess;
};

struct ResetTarget_guess {
    char pad_0[0x16c];
    int value_guess;
};

struct ValueSource_guess {
    // EXTERNAL: TITANIUM 0x005E0F60 ValueSource_guess::GetValue_guess
    int GetValue_guess();
};

struct Str_guess {
    int p;
    Str_guess() : p(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* s);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other);
    // EXTERNAL: TITANIUM 0x00571F70 ??4Str_guess@@QAEAAU0@ABU0@@Z
    Str_guess& operator=(const Str_guess& other);
    // EXTERNAL: TITANIUM 0x005738B0 Str_guess::Format_guess
    void Format_guess(const char* fmt, ...);
    // EXTERNAL: TITANIUM 0x00572F20 Str_guess::Insert_guess
    void Insert_guess(int pos_guess, const Str_guess& text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::Release_guess
    void Release_guess(int value);
    ~Str_guess() {
        if (p != 0) {
            Release_guess(p);
        }
        p = 0;
    }
};

struct Callback_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 Callback_guess::SetSTMLText
    void SetSTMLText(Str_guess s, int a, int b);
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
    virtual void Slot63_guess(const Str_guess& text_guess);
};

struct LayoutManager_guess {
    unsigned char unknown_0000_guess[0x18];
    int state_018_guess;
    // EXTERNAL: TITANIUM 0x00572300 LayoutManager_guess::Find_guess
    void* Find_guess(const char* name_guess);
};

struct Widget_guess {
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
    virtual void Slot73_guess(void* value_guess);
    virtual void Slot74_guess(void* value_guess);
};

struct TransferPacket_guess {
    char pad_000[8];
    int first_x_guess;
    int first_y_guess;
    int second_x_guess;
    int second_y_guess;
    int compatibility_guess;
    int max_transfer_guess;
    char names_guess[1];
};

struct ItemBase_guess {
    virtual void Slot00_guess();
    char pad_004[0xa4];
    // EXTERNAL: TITANIUM 0x005ECE20 ??0ItemBase_guess@@QAE@XZ
    ItemBase_guess();
};

// EXTERNAL: TITANIUM 0x00644780 ??_7EQ_Item_guess@@6B@

struct EQ_Item_guess : ItemBase_guess {
    EQ_Item_guess() {}
    // EXTERNAL: TITANIUM 0x004B212A EQ_Item_guess::Load_guess
    void Load_guess(const char* data_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 EQ_Item_guess::GetName_guess
    const char* GetName_guess();
};

// EXTERNAL: TITANIUM 0x0051EA25 BuildItemDescription_guess
Str_guess __cdecl BuildItemDescription_guess(EQ_Item_guess* item_guess, int mode_guess);

struct Resource_guess {
    char pad_0[0x60];
    unsigned int flags_060_guess;
};

struct CXStrView_guess {
    int p;
    // EXTERNAL: TITANIUM 0x00571E00 CXStrView_guess::Initialize_guess
    void Initialize_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x00571D00 CXStrView_guess::Release_guess
    void Release_guess(int value_guess);
    CXStrView_guess(const char* name_guess) {
        Initialize_guess(name_guess);
    }
    ~CXStrView_guess() {
        if (p != 0) {
            Release_guess(p);
        }
    }
};

struct WindowBase_guess {
    virtual void Slot00_guess();
    virtual ~WindowBase_guess() {}
    char pad_004[0x14];
    unsigned char state_018_guess;
    char pad_019[0x4b];
    unsigned int flags_064_guess;
    char pad_068[0xbc];
    Resource_guess* resource_124_guess;
    char pad_128[0x18];
    LayoutManager_guess layout_140_guess;
    // EXTERNAL: TITANIUM 0x005A3850 WindowBase_guess::WindowBase_guess
    WindowBase_guess(int value_guess, const CXStrView_guess& name_guess, int mode_guess, int first_guess, int second_guess);
};

struct DtorSub_guess {
    virtual void OnConfirm_guess(int code_guess, unsigned int flags_guess, int unused_guess);
    virtual ~DtorSub_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 DtorSub_guess::Reset_guess
    void Reset_guess(int value);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7DtorSub_guess@@6B@

struct CItemExpTransferWnd_guess : WindowBase_guess, DtorSub_guess {
    int unknown_160_guess;
    char pad_164[4];
    int first_x_guess;
    int first_y_guess;
    int second_x_guess;
    int second_y_guess;
    int cachedFirstX_guess;
    int cachedFirstY_guess;
    int cachedSecondX_guess;
    int cachedSecondY_guess;
    unsigned char ready_guess;
    char pad_189[3];
    Callback_guess* clear_18c_guess;
    Callback_guess* clear_190_guess;
    FlagTarget_guess* transferButton_guess;
    ResetTarget_guess* clear_198_guess;
    ResetTarget_guess* clear_19c_guess;
    Callback_guess* clear_1a0_guess;
    Callback_guess* clear_1a4_guess;
    ResetTarget_guess* clear_1a8_guess;
    ResetTarget_guess* clear_1ac_guess;
    Widget_guess* widget_1b0_guess;

    CItemExpTransferWnd_guess(int value_guess);
    virtual void Slot00_guess();
    virtual void OnConfirm_guess(int code_guess, unsigned int flags_guess, int unused_guess);
    virtual ~CItemExpTransferWnd_guess();
    void ClearItems_guess();
    void InvalidateItem_guess(int x, int y);
    void EnableTransferButton_guess(char value);
    void ClearPreview_guess(Callback_guess* callback, ResetTarget_guess* target);
    void ClearValues_guess();
    void SetIcon_guess(ResetTarget_guess* target, ValueSource_guess* source);
    void ClearState_guess();
    char UpdateLayout_guess();
    void LoadChildren_guess();
    void HandlePreview_guess(const TransferPacket_guess* packet_guess);
    void UpdateItems_guess();
    // EXTERNAL: TITANIUM 0x005A1E10 CItemExpTransferWnd_guess::GetChildItem
    void* GetChildItem(Str_guess* name_guess);
};

// EXTERNAL: TITANIUM 0x00656C20 ??_7CItemExpTransferWnd_guess@@6BWindowBase_guess@@@
// EXTERNAL: TITANIUM 0x00656C1C ??_7CItemExpTransferWnd_guess@@6BDtorSub_guess@@@

struct GlobalHandler_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 GlobalHandler_guess::GetIcon_guess
    int GetIcon_guess(int value);
};

#define gGlobalHandler_guess EQ_GLOBAL(GlobalHandler_guess*, 0x00991910)

struct EQ_CharacterView_guess {
    // EXTERNAL: TITANIUM 0x004BE2FC EQ_CharacterView_guess::Find_guess
    ValueSource_guess* Find_guess(int first_guess, int second_guess, int zero_guess);
};

#define g_manager_guess EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)

// Called after a pick: refreshes whichever icon's item changed, clears the previews and the TransferButton,
// and with both items set asks the server for a preview (kind 2).
// FUNCTION: TITANIUM 0x0052254F
// @early-stop: unknown, diff ndiff=6
void CItemExpTransferWnd_guess::UpdateItems_guess() {
    bool changed_guess = false;
    int fx_guess = first_x_guess;
    int fy_guess = first_y_guess;
    if (fx_guess != cachedFirstX_guess || fy_guess != cachedFirstY_guess) {
        changed_guess = true;
        ValueSource_guess* source_guess = g_manager_guess->Find_guess(fx_guess, fy_guess, 0);
        SetIcon_guess(clear_198_guess, source_guess);
        if (source_guess == 0) {
            cachedFirstX_guess = -1;
            cachedFirstY_guess = -1;
        }
    }
    int sx_guess = second_x_guess;
    int sy_guess = second_y_guess;
    if (sx_guess != cachedSecondX_guess || sy_guess != cachedSecondY_guess) {
        changed_guess = true;
        ValueSource_guess* source2_guess = g_manager_guess->Find_guess(sx_guess, sy_guess, 0);
        SetIcon_guess(clear_19c_guess, source2_guess);
        if (source2_guess == 0) {
            cachedSecondX_guess = -1;
            cachedSecondY_guess = -1;
        }
    }
    if (!changed_guess) {
        return;
    }
    if (transferButton_guess != 0) {
        transferButton_guess->flag_guess = 0;
    }
    ClearPreview_guess(clear_1a0_guess, clear_1a8_guess);
    ClearPreview_guess(clear_1a4_guess, clear_1ac_guess);
    ClearValues_guess();
    int lx_guess = second_x_guess;
    int ly_guess = second_y_guess;
    if ((lx_guess & ly_guess) != -1) {
        int ax_guess = first_x_guess;
        int ay_guess = first_y_guess;
        if ((ax_guess & ay_guess) != -1) {
            int payload_guess[6];
            payload_guess[0] = 2;
            payload_guess[2] = ax_guess;
            payload_guess[3] = ay_guess;
            payload_guess[4] = lx_guess;
            payload_guess[5] = ly_guess;
            // Preview request; HandlePreview_guess gets the answer.
            EQSendMessage(EQ_ARRAY(void, 0x00905CA0), 0x7e61, payload_guess, 0x18, 1);
        }
    }
}

// If (x, y) is one of the two items, forgets what the icons show so the next pass reloads them.
// FUNCTION: TITANIUM 0x00521C1B
void CItemExpTransferWnd_guess::InvalidateItem_guess(int x, int y) {
    if ((x == first_x_guess && y == first_y_guess) ||
        (x == second_x_guess && y == second_y_guess)) {
        cachedFirstX_guess = -1;
        cachedFirstY_guess = -1;
        cachedSecondX_guess = -1;
        cachedSecondY_guess = -1;
        ready_guess = 1;
    }
}

// Enables TransferButton when `value` is 0.
// FUNCTION: TITANIUM 0x00521C68
void CItemExpTransferWnd_guess::EnableTransferButton_guess(char value) {
    if (transferButton_guess != 0) {
        transferButton_guess->flag_guess = value == 0;
    }
}

// Clears one preview: its description and its icon.
// FUNCTION: TITANIUM 0x00521C80
void CItemExpTransferWnd_guess::ClearPreview_guess(Callback_guess* callback, ResetTarget_guess* target) {
    if (callback != 0) {
        callback->SetSTMLText(EQ_ARRAY(char, 0x0063F53F), 0, 0);
    }
    if (target != 0) {
        target->value_guess = 0;
    }
}

// Clears the CompatibilityValue and MaxTransferValue texts.
// FUNCTION: TITANIUM 0x00521CB8
void CItemExpTransferWnd_guess::ClearValues_guess() {
    if (clear_18c_guess != 0) {
        Str_guess text_guess(EQ_ARRAY(char, 0x0063F53F));
        clear_18c_guess->Slot63_guess(text_guess);
    }
    if (clear_190_guess != 0) {
        Str_guess text_guess2_guess(EQ_ARRAY(char, 0x0063F53F));
        clear_190_guess->Slot63_guess(text_guess2_guess);
    }
}

// Shows `source`'s icon in `target` (0 clears it); 0x4FFBE9 maps the item's icon number.
// FUNCTION: TITANIUM 0x00521D55
void CItemExpTransferWnd_guess::SetIcon_guess(ResetTarget_guess* target, ValueSource_guess* source) {
    if (target != 0) {
        target->value_guess = 0;
    }
    if (source != 0) {
        int value_guess = source->GetValue_guess();
        value_guess = gGlobalHandler_guess->GetIcon_guess(value_guess);
        if (target != 0) {
            target->value_guess = value_guess;
        }
    }
}

// Clears the control pointers that 0x00521DCB fills.
// FUNCTION: TITANIUM 0x00521D8C
void CItemExpTransferWnd_guess::ClearState_guess() {
    clear_18c_guess = 0;
    clear_190_guess = 0;
    transferButton_guess = 0;
    clear_198_guess = 0;
    clear_19c_guess = 0;
    clear_1a0_guess = 0;
    clear_1a4_guess = 0;
    clear_1a8_guess = 0;
    clear_1ac_guess = 0;
    widget_1b0_guess = 0;
}

// Looks up the item experience transfer window's controls: the compatibility and maximum transfer values,
// the Transfer button, the From/To item icons, preview views and preview icons, and the layout.
// FUNCTION: TITANIUM 0x00521DCB
void CItemExpTransferWnd_guess::LoadChildren_guess() {
    {
        Str_guess name_guess("CompatibilityValue");
        clear_18c_guess = (Callback_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("MaxTransferValue");
        clear_190_guess = (Callback_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("TransferButton");
        transferButton_guess = (FlagTarget_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("FromItemIcon");
        clear_198_guess = (ResetTarget_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("ToItemIcon");
        clear_19c_guess = (ResetTarget_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("FromPreviewView");
        clear_1a0_guess = (Callback_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("ToPreviewView");
        clear_1a4_guess = (Callback_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("FromPreviewIcon");
        clear_1a8_guess = (ResetTarget_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("ToPreviewIcon");
        clear_1ac_guess = (ResetTarget_guess*)GetChildItem(&name_guess);
    }
    {
        Str_guess name_guess("Layout");
        widget_1b0_guess = (Widget_guess*)GetChildItem(&name_guess);
    }
}

// EXTERNAL: TITANIUM 0x005A25B0 CreateChildrenFromSidl_guess
void __cdecl CreateChildrenFromSidl_guess();

// Item experience transfer window constructor: builds the children from the screen definition
// (0x005A25B0, CreateChildrenFromSidl) and looks them up, then marks both items empty (-1 pairs).
// FUNCTION: TITANIUM 0x0052201C
CItemExpTransferWnd_guess::CItemExpTransferWnd_guess(int value_guess)
    : WindowBase_guess(value_guess, CXStrView_guess("ItemExpTransferWnd"), -257, 1, 0), DtorSub_guess() {
    ClearState_guess();
    if (resource_124_guess != 0) {
        flags_064_guess |= resource_124_guess->flags_060_guess | 0x10800;
        layout_140_guess.state_018_guess = 0x48;
        state_018_guess = 1;
        CreateChildrenFromSidl_guess();
        LoadChildren_guess();
    }
    first_x_guess = -1;
    first_y_guess = -1;
    second_x_guess = -1;
    second_y_guess = -1;
    cachedFirstX_guess = -1;
    cachedFirstY_guess = -1;
    cachedSecondX_guess = -1;
    cachedSecondY_guess = -1;
    ready_guess = 0;
    unknown_160_guess = 0;
}

struct DtorBase_guess {
    char pad_0[0x15c];
    // EXTERNAL: TITANIUM 0x005A3100 ??1DtorBase_guess@@QAE@XZ
    ~DtorBase_guess();
};

struct DtorOwner_guess : DtorBase_guess {
    char storage_15c[4];
    ~DtorOwner_guess();
    void* Delete_guess(unsigned char flags);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Scalar deleting destructor of the item experience transfer window (vtable 0x656C20 slot 1): destroys
// it and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0052210E
void* DtorOwner_guess::Delete_guess(unsigned char flags) {
    this->DtorOwner_guess::~DtorOwner_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the item experience transfer window: expires every confirmation dialog its dialog-owner
// part (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd destructor
// (0x005A3100).
// FUNCTION: TITANIUM 0x0052212A
DtorOwner_guess::~DtorOwner_guess() {
    DtorSub_guess* sub = this ? reinterpret_cast<DtorSub_guess*>(storage_15c) : 0;
    sub->DtorSub_guess::~DtorSub_guess();
}

// Forgets both items and clears every icon, preview and text.
// FUNCTION: TITANIUM 0x00522170
void CItemExpTransferWnd_guess::ClearItems_guess() {
    first_x_guess = -1;
    first_y_guess = -1;
    second_x_guess = -1;
    second_y_guess = -1;
    cachedFirstX_guess = -1;
    cachedFirstY_guess = -1;
    cachedSecondX_guess = -1;
    cachedSecondY_guess = -1;
    if (clear_198_guess != 0) {
        clear_198_guess->value_guess = 0;
    }
    if (clear_19c_guess != 0) {
        clear_19c_guess->value_guess = 0;
    }
    if (transferButton_guess != 0) {
        transferButton_guess->flag_guess = 0;
    }
    ClearPreview_guess(clear_1a0_guess, clear_1a8_guess);
    ClearPreview_guess(clear_1a4_guess, clear_1ac_guess);
    ClearValues_guess();
    if (transferButton_guess != 0) {
        transferButton_guess->flag_guess = 0;
    }
}

// Server preview for the current pair (stale replies are ignored): compatibility percent, max transfer and
// the two items as they would end up, shown as preview icons and descriptions; then TransferButton is
// enabled. The two preview items are never deleted: each reply leaks them.
// FUNCTION: TITANIUM 0x00522213
void CItemExpTransferWnd_guess::HandlePreview_guess(const TransferPacket_guess* packet_guess) {
    if (packet_guess->first_x_guess != first_x_guess || packet_guess->first_y_guess != first_y_guess ||
        packet_guess->second_x_guess != second_x_guess || packet_guess->second_y_guess != second_y_guess) {
        return;
    }
    if (clear_18c_guess != 0) {
        Str_guess text_guess;
        text_guess.Format_guess("%d%%", packet_guess->compatibility_guess);
        clear_18c_guess->Slot63_guess(text_guess);
    }
    if (clear_190_guess != 0) {
        Str_guess text_guess(_itoa(packet_guess->max_transfer_guess, EQ_ARRAY(char, 0x0099DB00), 10));
        clear_190_guess->Slot63_guess(text_guess);
    }
    EQ_Item_guess* from_guess;
    EQ_Item_guess* to_guess;
    {
        const char* data_guess = packet_guess->names_guess;
        from_guess = 0;
        if (*data_guess != 0) {
            from_guess = new EQ_Item_guess;
            from_guess->Load_guess(data_guess);
            data_guess += strlen(data_guess) + 1;
        }
        to_guess = 0;
        if (*data_guess != 0) {
            to_guess = new EQ_Item_guess;
            to_guess->Load_guess(data_guess);
            data_guess += strlen(data_guess) + 1;
        }
    }
    if (from_guess != 0 && to_guess != 0) {
    SetIcon_guess(clear_1a8_guess, (ValueSource_guess*)from_guess);
    SetIcon_guess(clear_1ac_guess, (ValueSource_guess*)to_guess);
    cachedFirstX_guess = packet_guess->first_x_guess;
    cachedFirstY_guess = packet_guess->first_y_guess;
    cachedSecondX_guess = packet_guess->second_x_guess;
    cachedSecondY_guess = packet_guess->second_y_guess;
    Str_guess html_guess;
    Str_guess line_guess;
    if (clear_1a0_guess != 0) {
        html_guess = BuildItemDescription_guess(from_guess, 0);
        line_guess.Format_guess("%s<BR>", from_guess->GetName_guess());
        html_guess.Insert_guess(0, line_guess);
        clear_1a0_guess->SetSTMLText(html_guess, 0, 0);
    }
    if (clear_1a4_guess != 0) {
        html_guess = BuildItemDescription_guess(to_guess, 0);
        line_guess.Format_guess("%s<BR>", to_guess->GetName_guess());
        html_guess.Insert_guess(0, line_guess);
        clear_1a4_guess->SetSTMLText(html_guess, 0, 0);
    }
    if (transferButton_guess != 0) {
        transferButton_guess->flag_guess = 1;
    }
    }
}

// Applies the "MainLayout" layout and clears the window; always returns 1.
// FUNCTION: TITANIUM 0x0052271B
char CItemExpTransferWnd_guess::UpdateLayout_guess() {
    if (widget_1b0_guess != 0) {
        widget_1b0_guess->Slot73_guess(layout_140_guess.Find_guess("MainLayout"));
    }
    ClearItems_guess();
    return 1;
}

// Answer to the transfer prompt (message id 100): Yes or OK (result bits 1|4) sends the confirm (kind 3)
// and empties both items; the button stays disabled after a yes, enabled after a no or a timeout.
// FUNCTION: TITANIUM 0x00522699
void CItemExpTransferWnd_guess::OnConfirm_guess(int code_guess, unsigned int flags_guess, int unused_guess) {
    if (code_guess == 100) {
        if ((flags_guess & 5) != 0) {
            int payload_guess[6];
            payload_guess[2] = first_x_guess;
            payload_guess[3] = first_y_guess;
            payload_guess[4] = second_x_guess;
            payload_guess[5] = second_y_guess;
            payload_guess[0] = 3;
            // Confirm the transfer.
            EQSendMessage(EQ_ARRAY(void, 0x00905CA0), 0x7e61, payload_guess, 0x18, 1);
            first_x_guess = -1;
            first_y_guess = -1;
            second_x_guess = -1;
            second_y_guess = -1;
            UpdateItems_guess();
        }
        EnableTransferButton_guess((flags_guess & 5) != 0);
    }
}

