// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 208: a hint from compare/tumap.py.
// CServerListWnd ("ServerListWnd"; CServerListWnd_guess and Object_guess): a list of servers, each In use or
// Available (strings 0x17FC/0x17FB), from the 0x7510 reply (EQEmu calls 0x7510 OP_MoveLogRequest; tu_042's
// case 0x7510 loads it here). Record_guess/E38_guess are one 0x38-byte entry: in use +4, short name +5,
// long name +0x15.
#include "titanium/types.h"
#include <string.h>

struct E38_guess {
    char pad_0000[0x04];
    unsigned char inUse_0004_guess;   // 0x04
    char text_0005[0x10];       // 0x05
    char text_0015[0x23];       // 0x15
};

struct Throw_guess {
    // EXTERNAL: TITANIUM 0x00405492 Throw_guess::Fail
    __declspec(noreturn) void Fail();
};

struct Ce_guess : Throw_guess {
    int count;
    E38_guess* data;
    E38_guess& Get(int index);
};

// EXTERNAL: TITANIUM 0x0060D682 Free_guess
void __cdecl Free_guess(void* memory);

// 0x168 of the controller: Ce_guess's count and data, then capacity and flag.
struct Controller_buffer_guess : Ce_guess {
    int capacity;                       // 0x8
    unsigned char flag;                 // 0xc
    Controller_buffer_guess() {
        data = 0;
        count = 0;
        capacity = 0;
        flag = 1;
    }
    ~Controller_buffer_guess() {
        if (data != 0) {
            Free_guess(data);
        }
        data = 0;
    }
};

struct Child_guess {
    // EXTERNAL: TITANIUM 0x0050F3F6 Child_guess::Clear_guess
    void Clear_guess();
};

struct Record_guess {
    unsigned int words[14];
};

struct Record_list_guess {
    int count;
    Record_guess records[1];
};

struct Buffer_guess {
    int count;
    Record_guess* records;
    int capacity;
    unsigned char flag;
    void Grow_guess(int requested);
    void Set_guess(int index, const Record_guess* value);
};

struct Object_guess {
    char pad_0000[0x168];
    Child_guess child;

    // EXTERNAL: TITANIUM 0x005A3100 Object_guess::Finish_guess
    void Finish_guess();
    Object_guess* Release_guess(unsigned char flags);
    void Cleanup_guess();
    void SetServerList_guess(Record_list_guess* source);
    // EXTERNAL: TITANIUM 0x00553292 Object_guess::FillList_guess
    void FillList_guess();
};

struct Entity_guess {
    // EXTERNAL: TITANIUM 0x00597BE0 Entity_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 Entity_guess::GetItemData
    int GetItemData(int index);
    char pad_0000[0x5d];
    unsigned char state_05d; // 0x5d
};

struct SidlPiece_guess {
    unsigned int pad_000[0x60 / 4];
    unsigned int field_060;             // 0x60
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct ServerListBox_guess : CListWnd {
    char pad_140[0x159 - 0x140];
    unsigned char field_159;            // 0x159
    char pad_15a[0x15c - 0x15a];
    unsigned char field_15c;            // 0x15c
    char pad_15d[0x160 - 0x15d];
    unsigned int field_160;             // 0x160
    char pad_164[0x16c - 0x164];
    unsigned int field_16c;             // 0x16c

    void Setup_guess() {
        field_159 = 1;
        field_160 = 0x10;
    }
};

// EXTERNAL: TITANIUM 0x0065C698 ??_7CServerListWnd_guess@@6B@
struct CServerListWnd_guess : CSidlScreenWndBase {
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

    Entity_guess* field_15c;    // 0x15c
    Entity_guess* field_160;    // 0x160
    Entity_guess* field_164;    // 0x164
    Controller_buffer_guess field_168;  // 0x168
    unsigned char field_178;    // 0x178

    CServerListWnd_guess(CXWnd* parent);
    void FillList_guess();
    bool Select_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CServerListWnd_guess::WndNotification
    int WndNotification(Entity_guess* selected, int mode, int extra);
    int WndNotification_guess(Entity_guess* selected, int mode, int extra);
};

struct Message_guess {
    unsigned char flag;   // 0x00
    char text[0x40];      // 0x01
};

struct WindowVtable_guess {
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
};

struct ListItems_guess : CListWnd {
    // EXTERNAL: TITANIUM 0x0059B3E0 ListItems_guess::SetItemColor_guess
    void SetItemColor_guess(int index, int column, unsigned long color);
};

// EXTERNAL: TITANIUM 0x00576FA0 CopyBounded_guess
void __cdecl CopyBounded_guess(char* destination, const char* source, int count);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060E985 Allocate_guess
void* __cdecl Allocate_guess(unsigned int size);

// Server list: returns the 0x38-byte server entry at index `i`; an index out of range (or no storage)
// throws (0x00405492). The list fill and the Select button read entries through it.
// FUNCTION: TITANIUM 0x005531E4
E38_guess& Ce_guess::Get(int i) {
    if (i < count && i >= 0 && data) return data[i];
    Fail();
}

// Grows to `requested`+4 entries; the buffer is 0x70 bytes per 0x38-byte entry and records twice the
// count (the ArrayClass pattern of tu_105).
// FUNCTION: TITANIUM 0x00553205
void Buffer_guess::Grow_guess(int requested) {
    if (requested != 0 && (requested > capacity || records == 0)) {
        int newCount = requested + 4;
        Record_guess* replacement = (Record_guess*)Allocate_guess(newCount * 0x70);
        if (replacement != 0) {
            if (records != 0) {
                int i = 0;
                if (count > 0) {
                    do {
                        replacement[i] = records[i];
                        ++i;
                    } while (i < count);
                }
            }
            Free_guess(records);
            records = replacement;
            capacity = newCount * 2;
        } else {
            Free_guess(records);
            records = 0;
            capacity = 0;
            flag = 0;
        }
    }
}

// Server list window constructor: finds SL_ServerList (colours, 16-pixel rows), SL_SelectButton and
// SL_DisregardButton.
// FUNCTION: TITANIUM 0x00553500
CServerListWnd_guess::CServerListWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "ServerListWnd", 0xfffffeff, 2, 0) {
    if (SidlPiece != 0) {
        field_164 = 0;
        ((CSidlScreenWnd*)this)->WindowStyle |= ((SidlPiece_guess*)SidlPiece)->field_060 | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        field_15c = (Entity_guess*)((CSidlScreenWnd*)this)->GetChildItem("SL_ServerList");
        if (field_15c != 0) {
            ((ServerListBox_guess*)field_15c)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ServerListBox_guess*)field_15c)->SetColumnJustification(0, 0);
            ((ServerListBox_guess*)field_15c)->SetColumnJustification(1, 1);
            ((ServerListBox_guess*)field_15c)->field_16c = 0xff8aa3ff;
            ((ServerListBox_guess*)field_15c)->field_15c = 1;
            ((ServerListBox_guess*)field_15c)->Setup_guess();
        }
        field_160 = (Entity_guess*)((CSidlScreenWnd*)this)->GetChildItem("SL_SelectButton");
        field_164 = (Entity_guess*)((CSidlScreenWnd*)this)->GetChildItem("SL_DisregardButton");
        field_178 = 0;
    }
}

// Lists the servers: long name, then In use in red or Available in green.
// FUNCTION: TITANIUM 0x00553292
// @early-stop: budget, diff ndiff=71
void CServerListWnd_guess::FillList_guess() {
    if (field_15c != 0) {
        int i = 0;
        ((WindowVtable_guess*)field_15c)->Slot76_guess();
        char* text_17fc = pStringTable->getString(0x17fc, 0);
        char* text_17fb = pStringTable->getString(0x17fb, 0);
        if (field_168.count > 0) {
            do {
                int line;
                line = ((CListWnd*)field_15c)->AddString(
                    CXStr(field_168.Get(i).text_0015), 0xffffffff, i, 0);
                ((CListWnd*)field_15c)->SetItemText(
                    line, 1,
                    CXStr(field_168.Get(i).inUse_0004_guess != 0 ? text_17fc
                                                          : text_17fb));
                ((ListItems_guess*)field_15c)->SetItemColor_guess(
                    line, 1,
                    field_168.Get(i).inUse_0004_guess != 0 ? 0xffff0000 : 0xff00ff00);
                ++i;
            } while (i < field_168.count);
        }
    }
}

// SL_SelectButton sends the chosen server's short name (opcode 0x3905, flag 1, 0x41 bytes; no EQEmu
// Titanium name), SL_DisregardButton sends flag 0; both close. A list click enables Select.
// FUNCTION: TITANIUM 0x005533CF
int CServerListWnd_guess::WndNotification_guess(Entity_guess* selected, int mode, int extra) {
    if (mode == 1) {
        Message_guess message;
        if (selected == field_160) {
            int index = field_15c->GetCurSel();
            if (index != -1) {
                int value = field_15c->GetItemData(index);
                memset(&message, 0, sizeof(message));
                message.flag = 1;
                CopyBounded_guess(message.text, field_168.Get(value).text_0005, 0x40);
                EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0x3905, &message, 0x41, 1);
            }
            Slot34_guess();
            return 1;
        }
        if (selected == field_164) {
            memset(&message, 0, sizeof(message));
            message.flag = 0;
            EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0x3905, &message, 0x41, 1);
            Slot34_guess();
            return 1;
        }
        if (selected == field_15c && field_15c != 0) {
            field_160->state_05d = (unsigned char)(field_15c->GetCurSel() != -1);
        }
    }
    return WndNotification(selected, mode, extra);
}

// Stores a 0x38-byte record at `index`, growing the array (0x00553205) and its count when the index is
// past the end; negative indexes are ignored.
// FUNCTION: TITANIUM 0x005534C3
void Buffer_guess::Set_guess(int index, const Record_guess* value) {
    if (index >= 0) {
        if (index >= count) {
            int requested = index + 1;
            Grow_guess(requested);
            if (records != 0) {
                count = requested;
            }
        }
        if (records != 0) {
            records[index] = *value;
        }
    }
}

// On show: Select starts disabled and the list is refilled.
// FUNCTION: TITANIUM 0x005536B6
bool CServerListWnd_guess::Select_guess() {
    if (field_160 != 0) {
        field_160->state_05d = 0;
    }
    FillList_guess();
    return 1;
}

// Scalar deleting destructor of the server list window (vtable 0x65C698 slot 1): destroys it
// (0x005536E8) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x005536CC
Object_guess* Object_guess::Release_guess(unsigned char flags) {
    Cleanup_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the server list window: frees the server entry array (+0x168, 0x0050F3F6), then runs
// the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x005536E8
void Object_guess::Cleanup_guess() {
    child.Clear_guess();
    Finish_guess();
}

// Copies the reply's entries (a count, then 0x38-byte records) and refills the list.
// FUNCTION: TITANIUM 0x005536FE
void Object_guess::SetServerList_guess(Record_list_guess* source) {
    child.Clear_guess();
    int i = 0;
    if (0 < source->count) {
        Record_guess* record = source->records;
        do {
            Buffer_guess* buffer = (Buffer_guess*)&child;
            buffer->Set_guess(buffer->count, record);
            ++record;
            ++i;
        } while (i < source->count);
    }
    FillList_guess();
}
