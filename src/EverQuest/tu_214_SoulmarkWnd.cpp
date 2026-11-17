// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 214: a hint from compare/tumap.py.
// CSoulmarkWnd ("SoulmarkWnd"), the guide soulmark tool behind /inquire, /praise and /warn on a player
// name and PID. SetupText_guess, CSoulmarkWndView_guess and SetupObject_guess are all this window. A mark is
// 0x1C8 bytes: name, PID +0x40, author +0x60, GM id +0xA0, time +0xC0, kind +0xC4 (1 praise, 2 warn,
// 0 empty), text +0xC8; 12 per list. Opcodes 0x3F90, 0x128C and 0xA890 have no EQEmu Titanium name.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct SetupObject_guess {
    virtual void Slot00_guess();
    virtual ~SetupObject_guess();
    // EXTERNAL: TITANIUM 0x005A3100 SetupObject_guess::Initialize_guess
    void Initialize_guess();
    SetupObject_guess* Delete_guess(unsigned char flags);
};

struct SetupObjectCall_guess {
    // EXTERNAL: TITANIUM 0x00555A17 SetupObjectCall_guess::DestroyExternal_guess
    void DestroyExternal_guess();
};

struct Packet555BAC_guess {
    char text_guess[0x40];
    char data_guess[0x1560];
};

struct SetupText_guess {
    void SetText_guess(const char* first_guess, const char* second_guess);
    void Inquire_guess(const char* first_guess, const char* second_guess);
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
    virtual void Slot48_guess(int first_guess, int second_guess);
    char pad_guess[0x18c];
    char text_190_guess[0x100];
    char text_290_guess[0x100];
    char payload_390_guess[0x1560];

    void SendPayload_guess();
    void AddSoulmark_guess(int kind_guess, const char* first_guess,
                               const char* second_guess, const char* last_guess);
    void DoInquireCommand_guess(int token_guess);
    void DoPraiseCommand_guess(int input_guess);
    void DoWarnCommand_guess(int input_guess);
};

struct SetupTextPacket_guess {
    char text_guess[0x40];
    char flag_guess;
    char pad_guess[0x1f];
    char second_guess[0x40];
    char third_guess[0x20];
};

struct SetupMessagePacket_guess {
    char first_guess[0x40];
    char second_guess[0x20];
    char environment_guess[0x40];
    char flag_a0_guess;
    char pad_a1_guess[0x1f];
    int zero_c0_guess;
    int kind_c4_guess;
    char last_c8_guess[0x100];
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    char* getString(int key_guess);
};

struct CEverQuestView_guess {
    // EXTERNAL: TITANIUM 0x004982C6 CEverQuestView_guess::dsp_chat
    void dsp_chat(char* text_guess, int zero_guess, int severity_guess, int flag_guess);
};

#define g_environment_guess EQ_GLOBAL(char*, 0x00905CE4)
#define g_errorStrings_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_errorManager_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)
#define g_soulmarkMonths_guess EQ_ARRAY(const char*, 0x00794494)

// EXTERNAL: TITANIUM 0x005738B0 FormatCXStr_guess
void __cdecl FormatCXStr_guess(CXStr* output_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x0042DD82 GrabFirstWord_guess
char* __cdecl GrabFirstWord_guess(int token_guess, char* output_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x00576FA0 CopyBoundedText_guess
void __cdecl CopyBoundedText_guess(char* destination_guess, const char* source_guess,
                                   unsigned int size_guess);

extern "C" void* __cdecl memcpy(void* destination_guess, const void* source_guess,
                                unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct EditWnd_guess {
    // EXTERNAL: TITANIUM 0x004D7EBC ?SetMaxChars_guess@EditWnd_guess@@QAEXH@Z
    void SetMaxChars_guess(int max_guess);
};

struct ListColorWnd_guess {
    char pad_000_guess[0x16c];
    unsigned int color_16c; // 0x16c
};

// EXTERNAL: TITANIUM 0x0065CEC0 ??_7CSoulmarkWndView_guess@@6B@
// Virtual view of a CXWnd: slot 63 (+0xFC) is SetWindowTextA, slot 76 (+0x130) is the list's own.
struct CXWndVt_guess {
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
    virtual void Slot76_guess();
};

struct SoulmarkRecord_guess {
    char pad_000_guess[0xc4];
    int kind_c4_guess;
    char rest_c8_guess[0x100];
};

struct SoulmarkPacket_guess {
    char header_guess[0x40];
    SoulmarkRecord_guess records_guess[12];
};

struct CSoulmarkWndView_guess : CSidlScreenWndBase {
    CListWnd* list_15c;     // 0x15C "List"
    CXWnd* name_160;        // 0x160 "Name"
    CXWnd* pid_0164_guess;       // 0x164
    CXWnd* author_0168_guess;       // 0x168
    CXWnd* gmid_16c;        // 0x16C "GMID"
    CXWnd* date_170;        // 0x170 "Date"
    CXWnd* remove_174;      // 0x174 "Remove"
    CXWnd* edit_178;        // 0x178 "Edit"
    CXWnd* markText_17c;    // 0x17C "MarkText"
    CXWnd* markInput_180;   // 0x180 "MarkInput"
    CXWnd* praise_184;      // 0x184 "Praise"
    CXWnd* warn_188;        // 0x188 "Warn"
    CXWnd* done_18c;        // 0x18C "Done"
    char text_190[0x100];   // 0x190
    char text_290[0x100];   // 0x290
    SoulmarkRecord_guess slots_390_guess[12]; // 0x390, 12 x 0x1C8
    int entryCount_18f0_guess;   // 0x18F0
    CSoulmarkWndView_guess(CXWnd* parent);
    void Reset_guess();
    void UpdateList_guess();
    void UpdateSoulmarks_guess(SoulmarkPacket_guess* packet);
    void FillFields_guess();
};

// Soulmark window constructor: finds the name, ID, GM, GMID and date fields, the Remove, Edit, Warn,
// Praise and Done buttons, the mark text and its 250-character input, and the mark list (colours set).
// FUNCTION: TITANIUM 0x00555679
CSoulmarkWndView_guess::CSoulmarkWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "SoulmarkWnd", -1, 1, 0) {
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        name_160 = ((CSidlScreenWnd*)this)->GetChildItem("Name");
        // "ID", the player's PID; the next child is "GM", the mark's author.
        pid_0164_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065CEB4));
        author_0168_guess = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00649B28));
        gmid_16c = ((CSidlScreenWnd*)this)->GetChildItem("GMID");
        date_170 = ((CSidlScreenWnd*)this)->GetChildItem("Date");
        remove_174 = ((CSidlScreenWnd*)this)->GetChildItem("Remove");
        edit_178 = ((CSidlScreenWnd*)this)->GetChildItem("Edit");
        warn_188 = ((CSidlScreenWnd*)this)->GetChildItem("Warn");
        praise_184 = ((CSidlScreenWnd*)this)->GetChildItem("Praise");
        done_18c = ((CSidlScreenWnd*)this)->GetChildItem("Done");
        markText_17c = ((CSidlScreenWnd*)this)->GetChildItem("MarkText");
        markInput_180 = ((CSidlScreenWnd*)this)->GetChildItem("MarkInput");
        if (markInput_180 != 0) {
            // Mark text: at most 250 characters.
            ((EditWnd_guess*)markInput_180)->SetMaxChars_guess(0xfa);
        }
        list_15c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("List");
        if (list_15c != 0) {
            list_15c->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            list_15c->SetColumnJustification(0, 0);
            list_15c->SetColumnJustification(1, 0);
            ((ListColorWnd_guess*)list_15c)->color_16c = 0xff8aa3ff;
        }
        text_190[0] = 0;
        text_290[0] = 0;
    }
}

// EXTERNAL: TITANIUM 0x0065CEC0 ??_7SetupObject_guess@@6B@
// Destructor of the soulmark window (vtable 0x65CEC0): restores its vtable and runs the CSidlScreenWnd
// destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x00555A17
SetupObject_guess::~SetupObject_guess() {
    Initialize_guess();
}

// Lists the marks: date ("Jan 5, 2006") in red for a warning, green for praise, then the player name cut
// to 30 characters.
// FUNCTION: TITANIUM 0x00555A22
// @early-stop: budget, diff ndiff=10
void CSoulmarkWndView_guess::UpdateList_guess() {
    list_15c->ClearAllSel();
    ((CXWndVt_guess*)list_15c)->Slot76_guess();

    int index_guess = 0;
    if (index_guess < entryCount_18f0_guess) {
        int* record_guess = &slots_390_guess[0].kind_c4_guess;
        do {
            time_t timestamp_guess = record_guess[-1];
            struct tm* dateParts_guess = localtime(&timestamp_guess);
            CXStr date_guess;
            FormatCXStr_guess(&date_guess, "%s %d, %d",
                              g_soulmarkMonths_guess[dateParts_guess->tm_mon],
                              dateParts_guess->tm_mday, dateParts_guess->tm_year + 0x76c);
            unsigned int color_guess = record_guess[0] == 2 ? 0xffff0000 : 0xff00ff00;
            int row_guess = list_15c->AddString(date_guess, color_guess, index_guess, 0);

            char name_guess[0x64];
            strncpy(name_guess, (const char*)&record_guess[1], 0x1e);
            name_guess[0x1e] = 0;
            {
                CXStr text_guess(name_guess);
                list_15c->SetItemText(row_guess, 1, text_guess);
            }

            ++index_guess;
            record_guess += 0x72;
        } while (index_guess < entryCount_18f0_guess);
    }
}

// Remembers the player name and PID and shows the window.
// FUNCTION: TITANIUM 0x00555B74
void SetupText_guess::SetText_guess(const char* first_guess, const char* second_guess) {
    CopyText_guess(text_190_guess, first_guess);
    CopyText_guess(text_290_guess, second_guess);
    Slot48_guess(1, 1);
}

// Sends all 12 marks with our name (opcode 0x3F90, 0x15A0 bytes).
// FUNCTION: TITANIUM 0x00555BAC
void SetupText_guess::SendPayload_guess() {
    Packet555BAC_guess packet_guess;
    CopyText_guess(packet_guess.text_guess, g_environment_guess + 0x120);
    memcpy(packet_guess.data_guess, payload_390_guess, 0x1560);
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0x3f90, &packet_guess, 0x15a0, 1);
}

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag_guess
CXStr ColorTag_guess(int color_guess);

struct CXStrOps_guess {
    // EXTERNAL: TITANIUM 0x00572C10 CXStrOps_guess::Append_guess
    void Append_guess(const CXStr& text_guess);
};

// Shows the selected mark; Remove and Edit only for a filled one. The text gets a green /praise tag
// (string 0x3740) or a red /warn one (0x3741).
// FUNCTION: TITANIUM 0x00555C1E
// @early-stop: unknown, diff ndiff=7
void CSoulmarkWndView_guess::FillFields_guess() {
    int sel_guess = list_15c->GetCurSel();
    if (sel_guess == -1) {
        return;
    }
    int index_guess = (int)list_15c->GetItemData(sel_guess);
    SetupMessagePacket_guess* rec = (SetupMessagePacket_guess*)&slots_390_guess[index_guess];
    remove_174->Enabled = rec->kind_c4_guess != 0;
    edit_178->Enabled = rec->kind_c4_guess != 0;
    if (rec->kind_c4_guess == 0) {
        return;
    }
    {
        CXStr text_guess(rec->first_guess);
        ((CXWndVt_guess*)name_160)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(rec->second_guess);
        ((CXWndVt_guess*)pid_0164_guess)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(rec->environment_guess);
        ((CXWndVt_guess*)author_0168_guess)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(&rec->flag_a0_guess);
        ((CXWndVt_guess*)gmid_16c)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(ctime((time_t*)&rec->zero_c0_guess));
        ((CXWndVt_guess*)date_170)->Slot63_guess(text_guess);
    }
    CXStr text_guess("<C ");
    int color_guess = rec->kind_c4_guess == 2 ? 0xffff0000 : 0xff00ff00;
    ((CXStrOps_guess*)&text_guess)->Append_guess(ColorTag_guess(color_guess));
    text_guess += "> (";
    text_guess += pStringTable->getString(0x3740 + (rec->kind_c4_guess == 2), 0);
    text_guess += ") ";
    text_guess += rec->last_c8_guess;
    text_guess += " </C> ";
    ((CStmlWnd*)markText_17c)->SetSTMLText(text_guess, 1, 0);
}

// Empties the fields and the mark count; Name and ID go back to the last inquiry.
// FUNCTION: TITANIUM 0x00555EA6
void CSoulmarkWndView_guess::Reset_guess() {
    list_15c->Enabled = 1;
    list_15c->ClearAllSel();
    ((CXWndVt_guess*)list_15c)->Slot76_guess();
    {
        CXStr text_guess(text_190);
        ((CXWndVt_guess*)name_160)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(text_290);
        ((CXWndVt_guess*)pid_0164_guess)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(g_emptyText_guess);
        ((CXWndVt_guess*)author_0168_guess)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(g_emptyText_guess);
        ((CXWndVt_guess*)gmid_16c)->Slot63_guess(text_guess);
    }
    {
        CXStr text_guess(g_emptyText_guess);
        ((CXWndVt_guess*)date_170)->Slot63_guess(text_guess);
    }
    ((CStmlWnd*)markText_17c)->SetSTMLText(CXStr(g_emptyText_guess), 1, 0);
    {
        CXStr text_guess(g_emptyText_guess);
        ((CXWndVt_guess*)markInput_180)->Slot63_guess(text_guess);
    }
    warn_188->Enabled = 0;
    praise_184->Enabled = 0;
    edit_178->Enabled = 0;
    remove_174->Enabled = 0;
    entryCount_18f0_guess = 0;
}

// Asks for a player's marks (opcode 0x128C, 0xC0 bytes: our name, player, PID) after clearing the window;
// the reply probably arrives through UpdateSoulmarks_guess.
// FUNCTION: TITANIUM 0x00556081
void SetupText_guess::Inquire_guess(const char* first_guess, const char* second_guess) {
    SetupTextPacket_guess packet_guess;
    CopyText_guess(packet_guess.text_guess, g_environment_guess + 0x120);
    packet_guess.flag_guess = 0;
    CopyText_guess(packet_guess.second_guess, first_guess);
    CopyText_guess(packet_guess.third_guess, second_guess);
    CopyText_guess(text_190_guess, first_guess);
    CopyText_guess(text_290_guess, second_guess);
    ((CSoulmarkWndView_guess*)this)->Reset_guess();
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0x128c, &packet_guess, 0xc0, 1);
}

// Adds a mark of `kind_guess` (1 praise, 2 warn) to a player: one record, opcode 0xA890. Then shows the
// window.
// FUNCTION: TITANIUM 0x0055611C
void SetupText_guess::AddSoulmark_guess(int kind_guess, const char* first_guess,
                                             const char* second_guess, const char* last_guess) {
    SetupMessagePacket_guess packet_guess;
    CopyText_guess(packet_guess.first_guess, first_guess);
    CopyText_guess(packet_guess.second_guess, second_guess);
    CopyText_guess(packet_guess.environment_guess, g_environment_guess + 0x120);
    packet_guess.zero_c0_guess = 0;
    packet_guess.kind_c4_guess = kind_guess;
    packet_guess.flag_a0_guess = 0;
    CopyText_guess(packet_guess.last_c8_guess, last_guess);
    EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), 0xA890, &packet_guess, 0x1C8, 1);
    Slot33_guess();
}

// /inquire <name> <PID>: usage text 0x4290 when either is missing, else opens the window on them.
// FUNCTION: TITANIUM 0x005561C2
void SetupText_guess::DoInquireCommand_guess(int commandText_guess) {
    char name_guess[0x40];
    char pid_guess[0x20];
    char* remainder_guess = GrabFirstWord_guess(commandText_guess, name_guess, 0x40);
    name_guess[0x3f] = 0;
    if (name_guess[0] == 0 || remainder_guess[0] == 0) {
        g_errorManager_guess->dsp_chat(g_errorStrings_guess->getString(0x4290), 0, 0x0f, 1);
    } else {
        CopyBoundedText_guess(pid_guess, remainder_guess, 0x20);
        SetText_guess(name_guess, pid_guess);
    }
}

// /praise <name> <PID> <text>: usage text 0x4291 when a part is missing.
// FUNCTION: TITANIUM 0x00556240
void SetupText_guess::DoPraiseCommand_guess(int input_guess) {
    char payload_guess[0x100];
    char first_guess[0x40];
    char second_guess[0x20];
    char* rest_guess = GrabFirstWord_guess(input_guess, first_guess, 0x40);
    first_guess[0x3f] = 0;
    char* last_guess = GrabFirstWord_guess((int)rest_guess, second_guess, 0x20);
    second_guess[0x1f] = 0;
    if (first_guess[0] == 0 || second_guess[0] == 0 || last_guess[0] == 0) {
        g_errorManager_guess->dsp_chat(g_errorStrings_guess->getString(0x4291), 0, 0xf, 1);
    } else {
        CopyBoundedText_guess(payload_guess, last_guess, 0x100);
        AddSoulmark_guess(1, first_guess, second_guess, payload_guess);
        SetText_guess(first_guess, second_guess);
    }
}

// /warn counterpart: kind 2, usage text 0x4292.
// FUNCTION: TITANIUM 0x005562F5
void SetupText_guess::DoWarnCommand_guess(int input_guess) {
    char payload_guess[0x100];
    char first_guess[0x40];
    char second_guess[0x20];
    char* rest_guess = GrabFirstWord_guess(input_guess, first_guess, 0x40);
    first_guess[0x3f] = 0;
    char* last_guess = GrabFirstWord_guess((int)rest_guess, second_guess, 0x20);
    second_guess[0x1f] = 0;
    if (first_guess[0] == 0 || second_guess[0] == 0 || last_guess[0] == 0) {
        g_errorManager_guess->dsp_chat(g_errorStrings_guess->getString(0x4292), 0, 0xf, 1);
    } else {
        CopyBoundedText_guess(payload_guess, last_guess, 0x100);
        AddSoulmark_guess(2, first_guess, second_guess, payload_guess);
        SetText_guess(first_guess, second_guess);
    }
}

// Scalar deleting destructor of the soulmark window (vtable 0x65CEC0 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x005563AA
SetupObject_guess* SetupObject_guess::Delete_guess(unsigned char flags) {
    ((SetupObjectCall_guess*)this)->DestroyExternal_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Keeps the filled marks of a 12-slot reply, packed to the front, and refreshes the list.
// FUNCTION: TITANIUM 0x005563C6
void CSoulmarkWndView_guess::UpdateSoulmarks_guess(SoulmarkPacket_guess* packet) {
    Reset_guess();
    for (int i = 0; i < 12; i++) {
        slots_390_guess[i].kind_c4_guess = 0;
        if (packet->records_guess[i].kind_c4_guess != 0) {
            memcpy(&slots_390_guess[entryCount_18f0_guess], &packet->records_guess[i], 0x1c8);
            entryCount_18f0_guess++;
        }
    }
    UpdateList_guess();
}

