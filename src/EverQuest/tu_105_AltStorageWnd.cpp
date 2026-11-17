// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 105: a hint from compare/tumap.py.
// CAltStorageWnd ("AltStorageWnd"), the Spirit Shroud item storage (string 0x182C), after CAlarmWnd's frame
// handler. Object_guess is the same window: +0x15C item list (0x58-byte entries: name, icon id +0x40, serial
// +0x48, count +0x50), +0x170 storage NPC spawn id, +0x174 session end, +0x178 TimerLabel, +0x188 ItemList.
// Requests and replies use opcode 0x58FF (no EQEmu Titanium name), sub-command in the first word.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct Embedded_guess {
    char pad_0000_000F_guess[0x10];
    char state_guess;

    // EXTERNAL: TITANIUM 0x0050F3F6 Embedded_guess::Initialize_guess
    void Initialize_guess();
};

struct Target_guess {
    char pad_0000_005C_guess[0x5D];
    char enabled_005d_guess;
};

struct CListWndView_guess {
    char pad_0000_011B_guess[0x11c];
    int active_guess;

    // EXTERNAL: TITANIUM 0x00597BE0 CListWndView_guess::GetCurSel
    int GetCurSel();

    // EXTERNAL: TITANIUM 0x00597C20 CListWndView_guess::SetCurSel
    void SetCurSel(int value);
};

struct TextService_guess {
    // EXTERNAL: TITANIUM 0x0044A537 TextService_guess::WavePlay_guess
    void WavePlay_guess(int id, int value);
};

struct TimerLabel_guess {
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
    virtual void SetText_guess(const CXStr& text);
};

struct Object_guess {
    char pad_0000_005B_guess[0x5C];
    char field_5c_guess;
    char pad_005D_015B_guess[0xFF];
    Embedded_guess embedded_guess;
    char pad_016D_016F_guess[3];
    int field_170_guess;
    int field_174_guess;
    TimerLabel_guess* timerLabel_guess;
    int pad_017C_guess;
    Target_guess* target_guess;
    int pad_0184_guess;
    CListWndView_guess* helper_guess;
    unsigned int lastCheck_guess;

    // EXTERNAL: TITANIUM 0x005A3100 Object_guess::DestroyBase_guess
    void DestroyBase_guess();

    // EXTERNAL: TITANIUM 0x005A0E50 Object_guess::OnProcessFrame
    void OnProcessFrame();
    // EXTERNAL: TITANIUM 0x0059DD30 Object_guess::Check_guess
    char Check_guess();
    void CheckAnnouncement_guess();
    void UpdateGetButton_guess();
    void OnProcessFrame_guess();
    void Start_guess(int id, char notify);
    // EXTERNAL: TITANIUM 0x004D8515 Object_guess::Refresh_guess
    void Refresh_guess();
    char ClearItems_guess();
    void DestroyMembers_guess();
    Object_guess* Delete_guess(unsigned char flags);
    void HandleMessage_guess(int unusedArg_guess, int* msg);
};

struct Element_guess {
    char bytes_guess[0x58];
};

struct ElementId_guess {
    char pad_0000_0047_guess[0x48];
    int lo_guess;
    int hi_guess;
};

struct List_guess {
    int count_guess;
    Element_guess* data_guess;
    int capacity_guess;
    char field_0c_guess;

    // EXTERNAL: TITANIUM 0x00405492 List_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();

    Element_guess& GetItem_guess(int index);
    void Remove_guess(int index);
    void Reserve_guess(int capacity);
    void SetItem_guess(int index, const Element_guess* value);
};

#define g_stateFlag_guess EQ_GLOBAL(int, 0x009248D0)
#define g_announcementPending_guess EQ_GLOBAL(unsigned char, 0x0099140C)
#define g_announcementTime_guess EQ_GLOBAL(int, 0x00991410)
#define g_announcementValue1_guess EQ_GLOBAL(int, 0x00991418)
#define g_announcementValue2_guess EQ_GLOBAL(int, 0x00991414)
#define g_textService_guess EQ_GLOBAL(TextService_guess*, 0x00851390)
#define g_announcementBuffer1_guess EQ_ARRAY(char, 0x0099DAE0)
#define g_announcementBuffer2_guess EQ_ARRAY(char, 0x0099DB00)

struct CDisplayView_guess {
    // EXTERNAL: TITANIUM 0x00439CA3 CDisplayView_guess::PlayerSimpleDistance_guess
    float PlayerSimpleDistance_guess(int index, int arg, float scale);
};

// EXTERNAL: TITANIUM 0x00401B28 Lookup_guess
int __cdecl Lookup_guess(int id);

// EXTERNAL: TITANIUM 0x0046D655 GetClock_guess
int __cdecl GetClock_guess();

// EXTERNAL: TITANIUM 0x00577000 FormatTimer_guess
void __cdecl FormatTimer_guess(char* buffer, int size, const char* format,
    int hours, int minutes, int seconds);

#define g_spellCalc_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)
#define g_spellArg_guess EQ_GLOBAL(int, 0x00905CE4)

// EXTERNAL: TITANIUM 0x00470D4F BuildMoneyText_guess
void __cdecl BuildMoneyText_guess(int a, int b, int c, int d, char* out);

// EXTERNAL: TITANIUM 0x0046DA4A FormatAnnouncement_guess
void __cdecl FormatAnnouncement_guess(char* buffer, int stringId,
    char* value1, char* value2, int arg4, int arg5, int arg6, int arg7,
    int arg8, int arg9, int arg10);

// EXTERNAL: TITANIUM 0x0060ECBC _time32
extern "C" int __cdecl _time32(int* timer);
extern "C" char* __cdecl _itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0046DA4A FormatAnnouncement_guess
void __cdecl FormatAnnouncement_guess(char* buffer, int stringId,
    char* value1, char* value2, int arg4, int arg5, int arg6, int arg7,
    int arg8, int arg9, int arg10);

// EXTERNAL: TITANIUM 0x00405492 ThrowSelf_guess
void __cdecl ThrowSelf_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060E985 Allocate_guess
void* __cdecl Allocate_guess(unsigned int size);

// EXTERNAL: TITANIUM 0x0060D682 FreeBuffer_guess
void __cdecl FreeBuffer_guess(void* memory);

// CAlarmWnd::OnProcessFrame: once the session-end time (0x991410) passes, plays
// sound 0x8D and pops up "Your session (%1 hours and %2 minutes) has ended." (0x1A1D).
// FUNCTION: TITANIUM 0x004D82FF
void Object_guess::CheckAnnouncement_guess()
{
    char buffer[1024];
    if (g_announcementPending_guess != 0) {
        int currentTime = _time32(0);
        if (currentTime > g_announcementTime_guess) {
            g_textService_guess->WavePlay_guess(0x8d, 0);
            FormatAnnouncement_guess(buffer, 0x1a1d,
                _itoa(g_announcementValue2_guess, g_announcementBuffer2_guess, 10),
                _itoa(g_announcementValue1_guess, g_announcementBuffer1_guess, 10),
                0, 0, 0, 0, 0, 0, 0);
            pConfirmationDialogPool_guess->Activate(0, 0xb, buffer, 1, -1, 0, 0);
            g_announcementPending_guess = 0;
        }
    }
    OnProcessFrame();
}

// GetButton is enabled only with a row selected and no request in flight (0x9248D0 counts them).
// FUNCTION: TITANIUM 0x004D83BD
void Object_guess::UpdateGetButton_guess()
{
    char state = 0;
    if (helper_guess != 0) {
        int result = helper_guess->GetCurSel();
        if (result == -1 || g_stateFlag_guess != 0)
            state = 0;
        else
            state = 1;
    }
    if (target_guess != 0)
        target_guess->enabled_005d_guess = state;
}

// Stored-item list of the alt storage window: returns the 0x58-byte record at `index`; an index out of
// range (or no buffer) throws (0x00405492).
// FUNCTION: TITANIUM 0x004D83F4
Element_guess& List_guess::GetItem_guess(int index)
{
    if (index < count_guess && index >= 0 && data_guess != 0)
        return data_guess[index];
    Fail_guess();
}

// Stored-item list: removes the record at `index`, shifting the later ones down; out-of-range indexes
// are ignored. The window's server-reply handler (0x004D8E35) uses it to drop the record whose id the
// server names (sub-commands 2 and 4).
// FUNCTION: TITANIUM 0x004D8415
void List_guess::Remove_guess(int index)
{
    if (index < 0 || index >= count_guess || data_guess == 0)
        return;
    for (int i = index; i < count_guess - 1; ++i)
        data_guess[i] = data_guess[i + 1];
    --count_guess;
}

// Grows to `capacity`+4 entries: the buffer is 0xB0 bytes per 0x58-byte entry and records twice the count
// (the ArrayClass pattern; tu_208 has it too).
// FUNCTION: TITANIUM 0x004D845B
void List_guess::Reserve_guess(int capacity)
{
    if (capacity == 0)
        return;
    if (capacity <= capacity_guess && data_guess != 0)
        return;

    int newCapacity = capacity + 4;
    Element_guess* newData = (Element_guess*)Allocate_guess(newCapacity * 0xB0);
    if (newData != 0) {
        if (data_guess != 0) {
            for (int i = 0; i < count_guess; ++i)
                newData[i] = data_guess[i];
        }

        FreeBuffer_guess(data_guess);
        data_guess = newData;
        capacity_guess = newCapacity * 2;
    } else {
        FreeBuffer_guess(data_guess);
        data_guess = 0;
        capacity_guess = 0;
        field_0c_guess = 0;
    }
}

// Empties the item list, drops the selection and marks the list for a redraw.
// FUNCTION: TITANIUM 0x004D84EB
char Object_guess::ClearItems_guess()
{
    embedded_guess.Initialize_guess();
    if (helper_guess != 0)
        helper_guess->SetCurSel(-1);
    embedded_guess.state_guess = 1;
    return 1;
}

// SetElementIdx for 0x58-byte records: copies `value` to `index`, first growing the array (0x004D845B) and
// the length to index + 1 when needed. Negative indexes are ignored, and so is the store when the
// allocation failed.
// FUNCTION: TITANIUM 0x004D8A78
void List_guess::SetItem_guess(int index, const Element_guess* value)
{
    if (index < 0)
        return;
    if (index >= count_guess) {
        Reserve_guess(index + 1);
        if (data_guess != 0)
            count_guess = index + 1;
    }
    if (data_guess != 0)
        data_guess[index] = *value;
}

/* ---- AltStorageWnd::AltStorageWnd(CXWnd*) (0x004D8AB5) ---------------------------------------------
 * Layout from this ctor's displacements. The ctor needs a polymorphic class with the real
 * CSidlScreenWnd base ctor/dtor, so it derives from CSidlScreenWndBase; header methods are called through the
 * CSidlScreenWnd layout view. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct AltStorageListWnd_guess : CListWnd {
    char pad_140[0x14];
    int field_154;                          // 0x154
    bool field_158_guess;                   // 0x158
    unsigned char field_159;                // 0x159
    char pad_15a[2];
    unsigned char field_15c;                // 0x15c
    char pad_15d[3];
    int field_160;                          // 0x160
    char pad_164[8];
    unsigned int color_16c;                 // 0x16c
    // EXTERNAL: TITANIUM 0x005981F0 AltStorageListWnd_guess::SetColumnWidth_guess
    void SetColumnWidth_guess(int index, int width);
    // EXTERNAL: TITANIUM 0x0059B2E0 AltStorageListWnd_guess::SetItemRef_guess
    void SetItemRef_guess(int index, int column, const CXStr& text);
    void SetRowHeight_guess(int height) {
        field_159 = 1;
        field_160 = height;
    }
};

// Member block at 0x15c: its inline ctor clears the three words and sets the flag.
struct AltStorageInner_guess {
    int field_15c_guess;                    // 0x15c
    int field_160_guess;                    // 0x160
    int field_164_guess;                    // 0x164
    unsigned char field_168_guess;          // 0x168
    AltStorageInner_guess() {
        field_160_guess = 0;
        field_15c_guess = 0;
        field_164_guess = 0;
        field_168_guess = 1;
    }
    ~AltStorageInner_guess() {
        field_15c_guess = 0;
    }
};

// EXTERNAL: TITANIUM 0x0064ED68 ??_7CAltStorageWnd_guess@@6B@
struct CAltStorageWnd_guess : CSidlScreenWndBase {
    AltStorageInner_guess inner_15c;        // 0x15c
    unsigned char field_16c;                // 0x16c
    char pad_16d[3];
    int field_170;                          // 0x170
    int field_174;                          // 0x174
    CXWnd* timerLabel_178;                  // 0x178 TimerLabel
    CXWnd* countLabel_17c;                  // 0x17c CountLabel
    CXWnd* getButton_180;                   // 0x180 GetButton
    CXWnd* doneButton_184;                  // 0x184 DoneButton
    AltStorageListWnd_guess* itemList_188;  // 0x188 ItemList
    int field_18c;                          // 0x18c
    CAltStorageWnd_guess(CXWnd* parent);
    void Refresh_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

struct RefreshSlotView_guess {
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
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(const CXStr& text);
    virtual void Slot64_guess(int value);
    virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess(); virtual void Slot68_guess();
    virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess(); virtual void Slot72_guess();
    virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
    virtual void Slot76_guess(); virtual void Slot77_guess(); virtual void Slot78_guess();
    char pad_004[0x108];
    int field_10c_guess;
};

struct RefreshElement_guess {
    char text_guess[0x40];
    int iconId_0040_guess;
    char pad_044_047_guess[4];
    __int64 serial_guess;
    int count_guess;
    char pad_054_057_guess[4];
};

struct IconCache_guess {
    // EXTERNAL: TITANIUM 0x004FFBE9 IconCache_guess::GetIcon_guess
    CXStr& GetIcon_guess(int id);
};
#define g_nameTable_guess EQ_GLOBAL(IconCache_guess*, 0x00991910)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_digits_guess EQ_ARRAY(char, 0x0099DB00)

// Refills ItemList (icon, name, count) and CountLabel, keeping the selected item by its serial and the
// scroll position.
// FUNCTION: TITANIUM 0x004D8515
// @early-stop: unknown, structural ndiff=34
void CAltStorageWnd_guess::Refresh_guess()
{
    if (itemList_188 != 0) {
        int selected = -1;
        int current = itemList_188->GetCurSel();
        if (current != -1)
            selected = ((RefreshElement_guess*)&((List_guess*)&inner_15c)->GetItem_guess(itemList_188->GetItemData(current)))->serial_guess;
        int savedPos = ((RefreshSlotView_guess*)itemList_188)->field_10c_guess;
        ((RefreshSlotView_guess*)itemList_188)->Slot76_guess();
        List_guess* items = (List_guess*)&inner_15c;
        int i = 0;
        for (; i < items->count_guess; ++i) {
            int row = itemList_188->AddString(CXStr(g_emptyString_guess), -1, i, 0);
            itemList_188->SetItemRef_guess(row, 0, g_nameTable_guess->GetIcon_guess(((RefreshElement_guess*)&items->GetItem_guess(i))->iconId_0040_guess));
            itemList_188->SetItemText(row, 1, CXStr(((RefreshElement_guess*)&items->GetItem_guess(i))->text_guess));
            itemList_188->SetItemText(row, 2, CXStr(_itoa(((RefreshElement_guess*)&items->GetItem_guess(i))->count_guess, g_digits_guess, 10)));
        }
        ((RefreshSlotView_guess*)itemList_188)->Slot78_guess();
        if (selected != -1) {
            for (int j = 0; j < itemList_188->ItemsCount; ++j) {
                if (((RefreshElement_guess*)&((List_guess*)&inner_15c)->GetItem_guess(itemList_188->GetItemData(j)))->serial_guess == selected) {
                    itemList_188->SetCurSel(j);
                    break;
                }
            }
        }
        ((RefreshSlotView_guess*)itemList_188)->Slot64_guess(savedPos);
    }
    if (countLabel_17c != 0) {
        CXStr text(_itoa(inner_15c.field_15c_guess, g_digits_guess, 10));
        ((RefreshSlotView_guess*)countLabel_17c)->Slot63_guess(text);
    }
    field_16c = 0;
}

// CAltStorageWnd: binds the SIDL children (TimerLabel, CountLabel, GetButton, DoneButton, ItemList) and
// sets up the item list's colors, column justification and 24-pixel rows.
// FUNCTION: TITANIUM 0x004D8AB5
CAltStorageWnd_guess::CAltStorageWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "AltStorageWnd", -0x101, 1, 0) {
    field_170 = -1;
    timerLabel_178 = 0;
    countLabel_17c = 0;
    getButton_180 = 0;
    doneButton_184 = 0;
    itemList_188 = 0;
    field_18c = 0;
    field_174 = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10000;
        field_158_guess = 0x11;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        timerLabel_178 = ((CSidlScreenWnd*)this)->GetChildItem("TimerLabel");
        countLabel_17c = ((CSidlScreenWnd*)this)->GetChildItem("CountLabel");
        doneButton_184 = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        getButton_180 = ((CSidlScreenWnd*)this)->GetChildItem("GetButton");
        itemList_188 = (AltStorageListWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ItemList");
        if (itemList_188 != 0) {
            itemList_188->SetColors(-1, 0xffffff00, 0xff808080);
            itemList_188->SetColumnJustification(0, 0);
            itemList_188->SetColumnJustification(1, 0);
            itemList_188->SetColumnJustification(2, 1);
            itemList_188->color_16c = 0xff8aa3ff;
            itemList_188->field_15c = 1;
            itemList_188->SetRowHeight_guess(0x18);
            itemList_188->SetColumnWidth_guess(0, 0x18);
            itemList_188->WindowStyle |= 0x40000;
            itemList_188->field_154 = 1;
        }
        field_16c = 1;
        FUN_0059db90_guess(0x14);
    }
}

struct Slot_guess {
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
    virtual void Slot48_guess(char state, int flag);
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

// OnProcessFrame: every 250 ms shows the session time left and closes the window when
// the storage NPC is gone or more than 50 units away (CDisplay::PlayerSimpleDistance).
// FUNCTION: TITANIUM 0x004D877C
// @early-stop: budget, structural ndiff=38
void Object_guess::OnProcessFrame_guess()
{
    char buffer[256];
    if (Check_guess() != 0 &&
        GetClock_guess() > lastCheck_guess + 250U) {
        if (helper_guess == 0 || (char)(helper_guess->active_guess > 0)) {
            TimerLabel_guess** timerLabel = &timerLabel_guess;
            int elapsed = field_174_guess - _time32(0);
            if (elapsed < 0)
                elapsed = 0;
            int hours = elapsed / 0xe10;
            int minutes = (elapsed % 0xe10) / 0x3c;
            int seconds = elapsed % 0x3c;
            FormatTimer_guess(buffer, 0x100,
                // "%02d:%02d:%02d".
                EQ_ARRAY(char, 0x0064DC28), hours, minutes, seconds);
            if (*timerLabel != 0) {
                CXStr text(buffer);
                (*timerLabel)->SetText_guess(text);
            }
        }
        int entry = Lookup_guess(field_170_guess);
        if (entry == 0 ||
            !(g_spellCalc_guess->PlayerSimpleDistance_guess(entry, g_spellArg_guess,
                1.0f) <= 50.0f)) {
            ((Slot_guess*)this)->Slot48_guess(0, 1);
        }
        if (embedded_guess.state_guess != 0)
            Refresh_guess();
        UpdateGetButton_guess();
        lastCheck_guess = (unsigned int)GetClock_guess();
    }
    OnProcessFrame();
}

struct ElementView_guess {
    char pad_0000_0047_guess[0x48];
    int field_48_guess;
    int field_4c_guess;
};

// Server messages (0x58FF), by msg[0]: 0 open for NPC msg[1], 1 close, 2 a Get succeeded (drop that serial,
// one request less), 3 clear, 4 drop a serial, 5 the list (session ends msg[2] s from now, msg[1] entries of
// 0x58 bytes at msg[4]), 7 "You have received %1 from your Spirit Shroud." with a coin amount.
// Case 4 widens msg[2] alone to 64 bits, so its high half is msg[2]'s sign, not msg[3].
// FUNCTION: TITANIUM 0x004D8E35
// @early-stop: budget, structural ndiff=60
void Object_guess::HandleMessage_guess(int unusedArg_guess, int* msg)
{
    __int64 key;
    char text[128];
    char buffer[1024];
    switch (msg[0]) {
    case 0:
        if (Check_guess() == 0)
            Start_guess(msg[1], 0);
        return;
    case 1:
        ((Slot_guess*)this)->Slot48_guess(0, 1);
        return;
    case 2:
        if ((msg[2] & msg[3]) != -1) {
            List_guess* list = (List_guess*)&embedded_guess;
            for (int i = 0; i < list->count_guess; ++i) {
                ElementId_guess& e = (ElementId_guess&)list->GetItem_guess(i);
                if (e.lo_guess == msg[2] && e.hi_guess == msg[3]) {
                    list->Remove_guess(i);
                    if (helper_guess != 0)
                        helper_guess->SetCurSel(-1);
                    embedded_guess.state_guess = 1;
                    break;
                }
            }
        }
        if (--g_stateFlag_guess < 0)
            g_stateFlag_guess = 0;
        return;
    case 3:
        embedded_guess.Initialize_guess();
        if (helper_guess != 0)
            helper_guess->SetCurSel(-1);
        break;
    case 4: {
        key = msg[2];
        List_guess* list = (List_guess*)&embedded_guess;
        int i;
        for (i = 0; i < list->count_guess; ++i) {
            ElementId_guess& e = (ElementId_guess&)list->GetItem_guess(i);
            if (e.lo_guess == (int)key && e.hi_guess == (int)(key >> 32))
                break;
        }
        if (i >= list->count_guess)
            return;
        list->Remove_guess(i);
        if (helper_guess != 0) {
            int state = helper_guess->GetCurSel();
            if (state != -1 && ((CListWnd*)helper_guess)->GetItemData(state) == (unsigned int)i)
                helper_guess->SetCurSel(-1);
        }
        break;
    }
    case 5: {
        if (Check_guess() == 0)
            return;
        field_174_guess = _time32(0) + msg[2];
        embedded_guess.Initialize_guess();
        List_guess* list = (List_guess*)&embedded_guess;
        Element_guess* elem = (Element_guess*)&msg[4];
        for (int i = 0; i < msg[1]; ++i) {
            list->SetItem_guess(list->count_guess, elem);
            ++elem;
        }
        break;
    }
    case 7:
        text[0] = 0;
        BuildMoneyText_guess(msg[1], msg[2], msg[3], msg[4], text);
        FormatAnnouncement_guess(buffer, 0x182c, text, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buffer, 0xf, true);
        return;
    default:
        return;
    }
    Refresh_guess();
}

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Done closes. Get asks for the selected item (0x58FF, 16 bytes: 2, unused, serial) and counts the request.
// Right-click (3) sends sub-command 6 with the serial and "Shift not held"; probably an item inspect.
// A column click (0xF) flips the list's sort order.
// FUNCTION: TITANIUM 0x004D8906
int CAltStorageWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    int payload[6];
    if (message == 1) {
        if (sender == (CXWnd*)doneButton_184) {
            ((Slot_guess*)this)->Slot48_guess(0, 1);
        } else if (sender == (CXWnd*)getButton_180 && itemList_188 != 0 && g_stateFlag_guess == 0) {
            int index = itemList_188->GetCurSel();
            if (index != -1) {
                unsigned int id = itemList_188->GetItemData(index);
                payload[2] = 2;
                ElementView_guess* item = (ElementView_guess*)&((List_guess*)&inner_15c)->GetItem_guess(id);
                payload[4] = item->field_48_guess;
                payload[5] = item->field_4c_guess;
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x58ff, &payload[2], 0x10, 1);
                g_stateFlag_guess++;
            }
        }
    } else if (message == 3) {
        if (sender == (CXWnd*)itemList_188) {
            int index = itemList_188->GetCurSel();
            if (index != -1) {
                unsigned int id = itemList_188->GetItemData(index);
                payload[0] = 6;
                ElementView_guess* item = (ElementView_guess*)&((List_guess*)&inner_15c)->GetItem_guess(id);
                payload[2] = item->field_48_guess;
                payload[3] = item->field_4c_guess;
                unsigned int flags = pinstCXWndManager_guess->GetKeyboardFlags();
                payload[4] = ~flags & 1;
                EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x58ff, payload, 0x18, 1);
            }
        }
    } else if (message == 0xf) {
        if (sender == (CXWnd*)itemList_188) {
            AltStorageListWnd_guess* list = (AltStorageListWnd_guess*)sender;
            list->field_154 = 1;
            list->field_158_guess = (list->field_158_guess == 0);
            ((Slot_guess*)list)->Slot78_guess();
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// Opens for storage NPC `id` when it is within 50 units; with `notify`, tells the server (0x58FF, 8 bytes:
// 0, id). Otherwise the window is hidden.
// FUNCTION: TITANIUM 0x004D8D48
void Object_guess::Start_guess(int id, char notify)
{
    int payload[2];
    if (field_5c_guess == 0) {
        char state = 0;
        field_170_guess = id;
        field_174_guess = _time32(0);
        int entry = Lookup_guess(field_170_guess);
        if (entry != 0) {
            float value = g_spellCalc_guess->PlayerSimpleDistance_guess(entry, g_spellArg_guess, 1.0f);
            if (value <= 50.0f) {
                state = 1;
                if (notify != 0) {
                    payload[0] = 0;
                    payload[1] = id;
                    EQSendMessage(EQ_ARRAY(int, 0x00905CA0), 0x58ff, payload, 8, 1);
                }
                if (embedded_guess.state_guess != 0)
                    Refresh_guess();
                UpdateGetButton_guess();
            }
        }
        ((Slot_guess*)this)->Slot48_guess(state, 1);
    }
}

// Scalar deleting destructor of the alt storage window (vtable 0x64ED68 slot 1): destroys it
// (0x004D8E1F) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004D8E03
Object_guess* Object_guess::Delete_guess(unsigned char flags)
{
    DestroyMembers_guess();
    if ((flags & 1) != 0)
        free(this);
    return this;
}

// Destructor of the alt storage window: frees the stored-item array (+0x15C, 0x0050F3F6), then the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004D8E1F
void Object_guess::DestroyMembers_guess()
{
    embedded_guess.Initialize_guess();
    DestroyBase_guess();
}

