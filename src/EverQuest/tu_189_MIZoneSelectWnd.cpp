// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 189: a hint from compare/tumap.py.
// CMIZoneSelectWnd (screen "MIZoneSelectWnd", vtable 0x658ED8, pointer 0x991D64): pick one of up to 10
// instances of a zone within 10 seconds. ZoneRows_guess, NetThing_guess and CMiniDockFrameWnd_guess are views
// of it; CListWnd and the 0x230 widget are its ZoneList (CListWnd).
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct NetThing_guess {
    char pad_0000[0x19c];
    int field_19c;                // 0x19C
    int field_1a0;                // 0x1A0
    char pad_01a4[0x8c];          // 0x1A4
    CListWnd* connection; // 0x230
    void Send_guess();
};

struct Msg_guess {
    int field_0;
    int field_4;
    int field_8;
};

struct MiniDockChild_guess {
    // EXTERNAL: TITANIUM 0x004482FB ??1MiniDockChild_guess@@QAE@XZ
    ~MiniDockChild_guess();
};

struct CFrameWnd_guess {
    char pad_0000[0x244];
    // EXTERNAL: TITANIUM 0x005A3100 ??1CFrameWnd_guess@@QAE@XZ
    ~CFrameWnd_guess();
};

struct CMiniDockFrameWnd_guess : CFrameWnd_guess {
    MiniDockChild_guess child_244; // 0x244
    ~CMiniDockFrameWnd_guess();
    void* ScalarDeletingDestructor_guess(unsigned int flags);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

#define g_connection_guess EQ_ARRAY(char, 0x00905CA0)
#define g_digits_guess EQ_ARRAY(char, 0x0099DB00)
#define g_seconds_guess EQ_ARRAY(char, 0x00659008)

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
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual void Slot76_guess();
    virtual void Slot77_guess();
    virtual void Slot78_guess();
};

struct ZoneInfo_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneInfo_guess::GetName_guess
    void GetName_guess(int zone_id, char* name, int flag);
};
#define g_zoneInfo_guess EQ_GLOBAL(ZoneInfo_guess*, 0x00905CC0)

struct ZoneRow_guess {
    int pad_000;
    int zone_id_004;
    int value_008;
};

struct ZoneRows_guess {
    char pad_0000[0x1a4];
    int count_1a4;                // 0x1A4
    char pad_1a8[0x10];
    ZoneRow_guess rows_1b8[1];    // 0x1B8, 12 bytes each
    char pad_1c4[0x230 - 0x1c4];
    Widget_guess* list_230;       // 0x230
    void FillZoneList_guess();
};

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* digits, int radix);

struct Sink_guess {
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
    virtual void Slot63_guess(CXStr* text);
};

/* ---- MIZoneSelectWnd::MIZoneSelectWnd(CXWnd*) (0x00539260) -------------------------------- */

struct ZoneListFields_guess {
    char pad_000[0x66];
    unsigned char flags_066;               // 0x066
    char pad_067[0x154 - 0x067];
    int field_154;                         // 0x154
    char pad_158[0x15c - 0x158];
    unsigned char field_15c;               // 0x15C
    char pad_15d[0x16c - 0x15d];
    int color_16c;                         // 0x16C
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct SelectButtonWnd_guess {
    // EXTERNAL: TITANIUM 0x004D22D7 SelectButtonWnd_guess::GetText_guess
    CXStr GetText_guess();
};

// EXTERNAL: TITANIUM 0x00658ED8 ??_7CMIZoneSelectWnd_guess@@6B@
struct CMIZoneSelectWnd_guess : CSidlScreenWndBase {
    char pad_15c[0xd4];
    CListWnd* zoneList_230;                // 0x230 ZoneList
    SelectButtonWnd_guess* selectButton_234; // 0x234 SelectButton
    CXWnd* cancelButton_238;               // 0x238 CancelButton
    int field_23c;                         // 0x23C
    int deadline_0240_guess;                         // 0x240
    CXStr text_244;                        // 0x244
    CMIZoneSelectWnd_guess(CXWnd* parent);
    void UpdateCountdown_guess();
    void SetData_guess(const void* data);
};

// EXTERNAL: TITANIUM 0x0060DA00 memcpy
void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
// EXTERNAL: TITANIUM 0x0060ECBC _time32
long __cdecl _time32(long* time);

// Binds ZoneList, SelectButton and CancelButton and keeps the button's caption for the countdown.
// FUNCTION: TITANIUM 0x00539260
CMIZoneSelectWnd_guess::CMIZoneSelectWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "MIZoneSelectWnd") {
    zoneList_230 = 0;
    selectButton_234 = 0;
    cancelButton_238 = 0;
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        zoneList_230 = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("ZoneList");
        selectButton_234 =
            (SelectButtonWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("SelectButton");
        cancelButton_238 = ((CSidlScreenWnd*)this)->GetChildItem("CancelButton");
        if (zoneList_230 != 0) {
            zoneList_230->SetColors(-1, 0xffffff00, 0xff808080);
            zoneList_230->SetColumnJustification(0, 0);
            zoneList_230->SetColumnJustification(1, 1);
            // Light blue (ARGB) at list +0x16C, probably the selection highlight.
            ((ZoneListFields_guess*)zoneList_230)->color_16c = 0xff8aa3ff;
            ((ZoneListFields_guess*)zoneList_230)->field_15c = 1;
            ((ZoneListFields_guess*)zoneList_230)->flags_066 |= 4;
            ((ZoneListFields_guess*)zoneList_230)->field_154 = 1;
        }
        if (selectButton_234 != 0) {
            text_244 = selectButton_234->GetText_guess();
        }
        field_23c = 0;
        deadline_0240_guess = 0;
    }
}

// Refills ZoneList from the server's rows (+0x1B8, 12 bytes each, count +0x1A4): full zone name, then a
// number in column 1, probably the instance's player count.
// FUNCTION: TITANIUM 0x00539441
void ZoneRows_guess::FillZoneList_guess() {
    if (list_230 != 0) {
        list_230->Slot76_guess();
        char zone_name[256];
        int i = 0;
        if (count_1a4 > 0) {
            do {
                g_zoneInfo_guess->GetName_guess(rows_1b8[i].zone_id_004, zone_name, 1);
                int row;
                {
                    CXStr name(zone_name);
                    row = ((CListWnd*)list_230)->AddString(name, 0xffffffff, i, 0);
                }
                {
                    CXStr value(_itoa(rows_1b8[i].value_008, g_digits_guess, 10));
                    ((CListWnd*)list_230)->SetItemText(row, 1, value);
                }
                ++i;
            } while (i < count_1a4);
        }
        list_230->Slot78_guess();
    }
}

// Shows the seconds left (deadline +0x240) after the Select button's caption.
// FUNCTION: TITANIUM 0x005395A7
void CMIZoneSelectWnd_guess::UpdateCountdown_guess() {
    if (zoneList_230 != 0) {
        // The selection is read and discarded (kept as compiled).
        zoneList_230->GetCurSel();
    }
    if (selectButton_234 != 0) {
        int remaining = deadline_0240_guess - _time32(0);
        CXStr text(text_244);
        text += g_seconds_guess;
        text += _itoa(remaining, g_digits_guess, 10);
        ((Sink_guess*)selectButton_234)->Slot63_guess(&text);
    }
}

// Select: sends the chosen row's item data with the two ids the server sent (+0x19C, +0x1A0),
// message 0xDFE (12 bytes; not in EQEmu's Titanium table).
// FUNCTION: TITANIUM 0x0053964C
void NetThing_guess::Send_guess() {
    if (connection != 0) {
        int index = connection->GetCurSel();
        if (index != -1) {
            int value = connection->GetItemData(index);
            Msg_guess msg;
            msg.field_4 = field_1a0;
            msg.field_0 = field_19c;
            msg.field_8 = value;
            EQSendMessage(g_connection_guess, 0xdfe, &msg, 0xc, 1);
        }
    }
}

// Scalar deleting destructor of CMIZoneSelectWnd.
// FUNCTION: TITANIUM 0x005396A7
void* CMiniDockFrameWnd_guess::ScalarDeletingDestructor_guess(unsigned int flags) {
    this->~CMiniDockFrameWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// CMIZoneSelectWnd::~CMIZoneSelectWnd: frees the caption CXStr at +0x244, then CSidlScreenWnd.
// FUNCTION: TITANIUM 0x005396C3
CMiniDockFrameWnd_guess::~CMiniDockFrameWnd_guess() {
}

// Server message 0x161C (via 0x454DD7): copies the 0xD4-byte zone list, starts a 10 s deadline and
// refreshes; the caller then shows the window.
// FUNCTION: TITANIUM 0x005396FB
void CMIZoneSelectWnd_guess::SetData_guess(const void* data) {
    memcpy(pad_15c, data, 0xd4);
    deadline_0240_guess = _time32(0) + 10;
    ((ZoneRows_guess*)this)->FillZoneList_guess();
    UpdateCountdown_guess();
}
