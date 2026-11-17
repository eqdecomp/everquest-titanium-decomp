// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 137: a hint from compare/tumap.py.
// CBugReportWnd (screen "BugReportWindow", vtables 0x651820/0x651818): the /bug form, sent as OP_Bug in
// EQEmu's 0x2220-byte BugReport_Struct. Owner_guess, BugReportWnd_guess and Notifier_guess (its dialog
// base at +0x15C) are all this window; g_settings_guess (0x905CE4) is the local player.
#include "titanium/core_decls.h"
#include "titanium/opcodes.h"

struct Base_guess {
    char pad_000[0x15c];
    // EXTERNAL: TITANIUM 0x005A3100 ??1Base_guess@@QAE@XZ
    ~Base_guess();
};

struct Sub_guess {
    virtual void Slot00_guess();
    virtual ~Sub_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 Sub_guess::Reset_guess
    void Reset_guess(int value);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7Sub_guess@@6B@

struct Member19c_guess {
    // EXTERNAL: TITANIUM 0x004482FB ??1Member19c_guess@@QAE@XZ
    ~Member19c_guess();
};

struct Helper_guess {
    Sub_guess component;   // 0x15c
    ~Helper_guess() {}
};

// A CXStr-shaped local with no constructor: the callee fills it, so nothing is zeroed first.
struct Str_guess {
    CStrRep* Ptr;
    ~Str_guess() {
        if (Ptr != 0) {
            FreeRep(Ptr);
        }
        Ptr = 0;
    }
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(CStrRep* rep);
    // EXTERNAL: TITANIUM 0x004D95D0 Str_guess::IsEmpty_guess
    bool IsEmpty_guess();
    // EXTERNAL: TITANIUM 0x00572300 ??BStr_guess@@QAEPADXZ
    operator char*();
    // EXTERNAL: TITANIUM 0x00573710 Str_guess::ToFloat_guess
    float ToFloat_guess();
};

struct Interface_guess {
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
    virtual void Slot63_guess(const CXStr& value_guess);
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
    virtual Str_guess Slot76_guess();
    // EXTERNAL: TITANIUM 0x004D22D7 Interface_guess::GetText_guess
    Str_guess GetText_guess();
};

struct EQPlayerView_guess {
    char pad_000[0x30];
    float value30_guess;
    float value34_guess;
    float value38_guess;
    char pad_3c[0x10];
    float value4c_guess;
};

#define g_settings_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)

struct Owner_guess : Base_guess, Helper_guess {
    Interface_guess* interface_160;    // 0x160
    Interface_guess* interface_164;    // 0x164
    Interface_guess* interface_168;    // 0x168
    char pad_16c[0x30];                // 0x16c
    Member19c_guess member_19c;        // 0x19c
    char pad_19d[0x7];                 // 0x19d
    int value_1a4;                     // 0x1a4
    ~Owner_guess();
    Owner_guess* Delete_guess(unsigned char flags);
    void UpdateLocation_guess();
};

/* ---- CBugReportWnd::CBugReportWnd(CXWnd*) (0x004E9980) ----------------------------------------------
 * Two bases: CSidlScreenWnd at +0 and the one-slot notification interface at +0x15C (own vtable
 * 0x0063FD9C, virtual dtor). Layout: include/titanium/types.h CBugReportWnd (0x1A8). */

#include "titanium/layouts/ui.h"

struct SidlBase_guess {
    char pad_004[0x60];                     // 0x004..0x063
    unsigned int windowStyle_064;           // 0x064 (CXWnd::WindowStyle)
    char pad_068[0xbc];                     // 0x068..0x123
    CScreenPieceTemplate* sidlPiece_124;      // 0x124 (CSidlScreenWnd::SidlPiece)
    char pad_128[0x34];                     // 0x128..0x15b
    virtual void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A3850 ??0SidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    SidlBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlBase_guess@@UAE@XZ
    virtual ~SidlBase_guess();
};

struct Notifier_guess {
    virtual void Slot00_guess(int id_guess, unsigned char flags_guess, int data_guess);
    virtual ~Notifier_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 Notifier_guess::Reset_guess
    void Reset_guess(int value);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7Notifier_guess@@6B@

struct EditWnd_guess {
    char pad_000[0x66];                     // 0x000..0x065
    unsigned char flags_066;                // 0x066
    // EXTERNAL: TITANIUM 0x004D7EBC ?SetMaxChars_guess@EditWnd_guess@@QAEXH@Z
    void SetMaxChars_guess(int maxChars);
};

struct BugTypeList_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 BugTypeList_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 BugTypeList_guess::Add_guess
    void Add_guess(const CXStr& text);
    // EXTERNAL: TITANIUM 0x0059C360 BugTypeList_guess::Finish_guess
    void Finish_guess(int index);
    // EXTERNAL: TITANIUM 0x0059C3A0 BugTypeList_guess::GetCurChoice_guess
    int GetCurChoice_guess();
};

struct BugTypeEntry_guess {
    int categoryId_0000_guess;                           // 0x000
    int nameId_004;                         // 0x004
    int promptId_008;                       // 0x008
};

// EXTERNAL: TITANIUM 0x00651820 ??_7BugReportWnd_guess@@6BSidlBase_guess@@@
// EXTERNAL: TITANIUM 0x00651818 ??_7BugReportWnd_guess@@6BNotifier_guess@@@
struct BugReportWnd_guess : SidlBase_guess, Notifier_guess {
    Interface_guess* interface_160;         // 0x160 LocX
    Interface_guess* interface_164;         // 0x164 LocY
    Interface_guess* interface_168;         // 0x168 LocZ
    Interface_guess* interface_16c;         // 0x16c LocationButton
    CXWnd* interface_170;                   // 0x170 Edit
    CXWnd* interface_174;                   // 0x174 Prompt
    Interface_guess* interface_178;         // 0x178 DupButton
    Interface_guess* interface_17c;         // 0x17c CrashButton
    Interface_guess* interface_180;         // 0x180 TargetButton
    Interface_guess* interface_184;         // 0x184 FlagsButton
    Interface_guess* interface_188;         // 0x188 TargetName
    Interface_guess* interface_18c;         // 0x18c CancelButton
    Interface_guess* interface_190;         // 0x190 SendButton
    BugTypeList_guess* interface_194;       // 0x194 BugTypes
    int targetId_0198_guess;                          // 0x198
    CXStr targetName_019c_guess;            // 0x19c
    bool flag_1a0;                          // 0x1a0
    char pad_1a1[0x3];                      // 0x1a1
    int heading_01a4_guess;                          // 0x1a4
    BugReportWnd_guess(CXWnd* parent);
    bool AboutToShow_guess();
    void SendBugReport_guess(bool flag);
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
};

#define g_fontIndex_guess EQ_GLOBAL(int, 0x00923D74)
#define g_bugTypes_guess EQ_ARRAY(BugTypeEntry_guess, 0x00791158)
#define g_bugTypeCount_guess EQ_GLOBAL(int, 0x007911DC)

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D750 memset
void* __cdecl memset(void* dest, int value, unsigned int count);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* dest, const char* source);
// EXTERNAL: TITANIUM 0x0060E460 strcat
char* __cdecl strcat(char* dest, const char* source);
// EXTERNAL: TITANIUM 0x0060E620 strncpy
char* __cdecl strncpy(char* dest, const char* source, unsigned int count);
// EXTERNAL: TITANIUM 0x0060D970 strlen
unsigned int __cdecl strlen(const char* text);
// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* dest, const char* source, int count);
// EXTERNAL: TITANIUM 0x00574A30 TextLimit_guess
void __cdecl TextLimit_guess(char* text, int limit);

struct Pending_guess {
    // EXTERNAL: TITANIUM 0x005AEF50 Pending_guess::Test_guess
    bool Test_guess();
};
#define pinstCXWndManager_guess EQ_GLOBAL(Pending_guess*, 0x0099D3EC)

struct SysInfo_guess {
    char pad_000[0x30];
    const char* cpu_030;
    const char* video_034;
    int driver_038;
    int driver_03c;
    int driver_040;
    int driver_044;
};
#define g_sysInfo_guess EQ_GLOBAL(SysInfo_guess*, 0x0099E354)

// Character object (pCharData): 8 bytes of non-virtual base, vbptr at +8, the virtual base at +0xC384.
struct PcBase_guess {
    void* vftable_000;
    int field_004;
};
struct CharVBase_guess {
    char pad_000[0x3C];
    char name_03C[0x40];
    char pad_07C[0x14C - 0x7C];
};
struct PcView_guess : PcBase_guess, virtual CharVBase_guess {
    char pad_00C[0xE20 - 0x0C];
    int field_E20;
    char pad_E24[0xC384 - 0xE24];
};
#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)

// Bug report packet, 0x2220 bytes, sent with opcode 0x7AC2.
struct BugReport_guess {
    char bugType_000[0x40];
    char charName_040[0x40];
    char pad_080[0x20];
    char uiPath_00a0_guess[0x80];
    float x_120;
    float y_124;
    float z_128;
    int heading_012c_guess;
    int zero_130;
    int timePlayed_0134_guess;
    char pad_138[0x8];
    int targetId_0140_guess;
    char pad_144[0x8C];
    unsigned int notFound_1D0;
    char target_1D4[0x40];
    int optionalInfoMask_0214_guess;
    char str_218[0x402];
    char str_61A[0x402];
    char text_A1C[0x402];
    char pad_E1E[0x400];
    char systemInfo_121e_guess[0x1002];
};

// Current target spawn (DAT_00905D04): name at +0x120, bool at +0x244, id at +0x258.
struct TargetSpawn_guess {
    char pad_000[0x120];
    char name_120[0x124];
    char flag_244;
    char pad_245[0x258 - 0x245];
    int id_258;
};
#define g_target_guess EQ_GLOBAL(TargetSpawn_guess*, 0x00905D04)

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestText_guess::Store_guess
    char* Store_guess(const char* text);
};
#define g_everQuest_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)
#define g_flag_9254ee_guess EQ_GLOBAL(char, 0x009254EE)

// Location button: copies the player's position (+0x30-+0x38) into LocX/Y/Z and the heading (+0x4C)
// into +0x1A4 for the report.
// FUNCTION: TITANIUM 0x004E9825
void Owner_guess::UpdateLocation_guess() {
    char buf[20];
    if (interface_160 != 0) {
        sprintf(buf, EQ_ARRAY(char, 0x0063F53C), (int)g_settings_guess->value30_guess);
        interface_160->Slot63_guess(buf);
    }
    if (interface_164 != 0) {
        sprintf(buf, EQ_ARRAY(char, 0x0063F53C), (int)g_settings_guess->value34_guess);
        interface_164->Slot63_guess(buf);
    }
    if (interface_168 != 0) {
        sprintf(buf, EQ_ARRAY(char, 0x0063F53C), (int)g_settings_guess->value38_guess);
        interface_168->Slot63_guess(buf);
    }
    value_1a4 = (int)g_settings_guess->value4c_guess;
}

// CBugReportWnd constructor: binds the controls, fills the category combo from the table at 0x791158
// (name and prompt string ids) and shows the default category's prompt.
// FUNCTION: TITANIUM 0x004E9980
BugReportWnd_guess::BugReportWnd_guess(CXWnd* parent)
    : SidlBase_guess(parent, "BugReportWindow", -257, 1, 0) {
    interface_160 = 0;
    interface_164 = 0;
    interface_168 = 0;
    interface_170 = 0;
    interface_174 = 0;
    interface_178 = 0;
    interface_17c = 0;
    interface_180 = 0;
    interface_184 = 0;
    interface_18c = 0;
    interface_190 = 0;
    interface_194 = 0;
    interface_188 = 0;
    interface_16c = 0;
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        interface_170 = ((CSidlScreenWnd*)this)->GetChildItem("Edit");
        interface_174 = ((CSidlScreenWnd*)this)->GetChildItem("Prompt");
        interface_194 = (BugTypeList_guess*)((CSidlScreenWnd*)this)->GetChildItem("BugTypes");
        interface_178 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("DupButton");
        interface_17c = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("CrashButton");
        interface_180 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("TargetButton");
        interface_184 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("FlagsButton");
        interface_188 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("TargetName");
        interface_18c = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("CancelButton");
        interface_190 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("SendButton");
        interface_160 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("LocX");
        interface_164 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("LocY");
        interface_168 = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("LocZ");
        interface_16c = (Interface_guess*)((CSidlScreenWnd*)this)->GetChildItem("LocationButton");
        if (interface_170 != 0) {
            ((EditWnd_guess*)interface_170)->flags_066 |= 4;
            if (g_fontIndex_guess != 0) {
                // 341 characters for a non-English client (0x923D74 is the language index), else 1023;
                // probably a multi-byte allowance in the same 1 KB buffer.
                ((EditWnd_guess*)interface_170)->SetMaxChars_guess(0x155);
            } else {
                ((EditWnd_guess*)interface_170)->SetMaxChars_guess(0x3ff);
            }
        }
        int selected = 0;
        if (interface_194 != 0) {
            interface_194->Reset_guess();
            for (int i = 0; i < g_bugTypeCount_guess; ++i) {
                interface_194->Add_guess(pStringTable->getString(g_bugTypes_guess[i].nameId_004, 0));
                // +0 is the entry's category id; the entry with id 0 is the default.
                if (g_bugTypes_guess[i].categoryId_0000_guess == 0) {
                    selected = i;
                }
            }
            interface_194->Finish_guess(selected);
        }
        if (interface_174 != 0) {
            ((CStmlWnd*)interface_174)->SetSTMLText(
                pStringTable->getString(g_bugTypes_guess[selected].promptId_008, 0), 1, 0);
        }
    }
}

// Scalar deleting destructor of the bug report window (vtable 0x651820 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x004E9E62
Owner_guess* Owner_guess::Delete_guess(unsigned char flags) {
    this->~Owner_guess();
    if (flags & 1)
        free(this);
    return this;
}

// Destructor of the bug report window: destroys the string at +0x19C, expires any confirmation dialogs
// its dialog-owner part (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd
// destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004E9E7E
Owner_guess::~Owner_guess() {
}

// CBugReportWnd::Activate (vtable slot 49): refreshes the location and clears the four option boxes and
// the target name.
// FUNCTION: TITANIUM 0x004E9ED8
bool BugReportWnd_guess::AboutToShow_guess() {
    ((Owner_guess*)this)->UpdateLocation_guess();
    if (interface_17c != 0) {
        ((CButtonWnd*)interface_17c)->SetCheck(false);
    }
    if (interface_178 != 0) {
        ((CButtonWnd*)interface_178)->SetCheck(false);
    }
    if (interface_184 != 0) {
        ((CButtonWnd*)interface_184)->SetCheck(false);
    }
    if (interface_180 != 0) {
        ((CButtonWnd*)interface_180)->SetCheck(false);
    }
    if (interface_188 != 0) {
        interface_188->Slot63_guess(EQ_ARRAY(char, 0x0063F53F));
    }
    return true;
}

// Sends the report (`flag`: append the CPU, video card and driver line). Empty text only prints string
// 0x22B0; otherwise string 0x22AE after sending. Closes the window either way.
// FUNCTION: TITANIUM 0x004E9F7A
void BugReportWnd_guess::SendBugReport_guess(bool flag) {
    Str_guess edit = ((Interface_guess*)interface_170)->Slot76_guess();
    char sysinfo[0x2800];
    BugReport_guess pkt;
    if (!edit.IsEmpty_guess()) {
        memset(&pkt, 0, 0x2220);
        strcpy(pkt.charName_040, g_pcView_guess->name_03C);
        pkt.pad_080[0] = 0;
        pkt.target_1D4[0] = 0;
        pkt.str_218[0] = 0;
        pkt.str_61A[0] = 0;
        int bugIdx = 0;
        if (interface_194 != 0) {
            // The selected row's category id, then that id's name: rows and ids need not match.
            bugIdx = g_bugTypes_guess[interface_194->GetCurChoice_guess()].categoryId_0000_guess;
        }
        strcpy(pkt.bugType_000, pStringTable->getString(g_bugTypes_guess[bugIdx].nameId_004, 0));
        pkt.x_120 = 0.0f;
        pkt.y_124 = 0.0f;
        pkt.z_128 = 0.0f;
        pkt.x_120 = interface_160->GetText_guess().ToFloat_guess();
        pkt.y_124 = interface_164->GetText_guess().ToFloat_guess();
        pkt.z_128 = interface_168->GetText_guess().ToFloat_guess();
        pkt.heading_012c_guess = heading_01a4_guess;
        pkt.zero_130 = 0;
        // time_played (EQEmu); +0x12C above is the heading.
        pkt.timePlayed_0134_guess = g_pcView_guess->field_E20;
        pkt.optionalInfoMask_0214_guess = 0;
        // optional_info_mask: 1 can duplicate, 2 crash, 4 target info, 8 character flags. The
        // buttons are used without the null checks Activate makes.
        if (((CButtonWnd*)interface_17c)->Checked) {
            pkt.optionalInfoMask_0214_guess = 2;
        }
        if (((CButtonWnd*)interface_178)->Checked) {
            pkt.optionalInfoMask_0214_guess |= 1;
        }
        if (((CButtonWnd*)interface_184)->Checked) {
            pkt.optionalInfoMask_0214_guess |= 8;
        }
        char targetChecked = ((CButtonWnd*)interface_180)->Checked;
        if (targetChecked != 0) {
            pkt.optionalInfoMask_0214_guess |= 4;
            pkt.targetId_0140_guess = targetId_0198_guess;
            strcpy(pkt.target_1D4, targetName_019c_guess);
        }
        // ui_path: the current UI skin path.
        steve_strncpy_guess(pkt.uiPath_00a0_guess, EQ_ARRAY(char, 0x00850990), 0x80);
        unsigned int notFound = 0;
        // EQEmu's unknown_0464: 1 when the window manager check (0x5AEF50, maybe IsAllValid) fails.
        if (!pinstCXWndManager_guess->Test_guess()) {
            notFound = 1;
        }
        pkt.notFound_1D0 = notFound;
        strncpy(pkt.text_A1C, edit, 0x402);
        pkt.text_A1C[0x401] = 0;
        TextLimit_guess(pkt.text_A1C, 0x400);
        pkt.systemInfo_121e_guess[0] = 0;
        if (flag) {
            sprintf(sysinfo, "CPU %s; Video Card: %s; Driver %d.%d.%d.%04d",
                    g_sysInfo_guess->cpu_030, g_sysInfo_guess->video_034,
                    g_sysInfo_guess->driver_038, g_sysInfo_guess->driver_03c,
                    g_sysInfo_guess->driver_040, g_sysInfo_guess->driver_044);
            unsigned int len = strlen(sysinfo);
            if (len >= 0x1000) {
                sysinfo[0xfff] = 0;
            }
            strcat(pkt.systemInfo_121e_guess, sysinfo);
            // Result unused (as original).
            strlen(sysinfo);
        }
        EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_Bug, &pkt, 0x2220, 1);
        {
            CXStr tmp(EQ_ARRAY(char, 0x0063F53F));
            ((Interface_guess*)interface_170)->Slot63_guess(tmp);
        }
        pEverQuest->dsp_chat(pStringTable->getString(0x22ae, 0), 0xf, 1);
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x22b0, 0), 0xf, 1);
    }
    ((Interface_guess*)this)->Slot34_guess();
}

// Category change shows its prompt; Cancel prints string 0x22AF and closes; Target stores the target's id
// and name; Send sends with system info when 0x9254EE is 1, else asks first (string 0x1AA3, 60 s dialog).
// FUNCTION: TITANIUM 0x004EA38B
int BugReportWnd_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if (sender == (CXWnd*)interface_194) {
            int sel = interface_194->GetCurChoice_guess();
            if (interface_174 != 0) {
                ((CStmlWnd*)interface_174)->SetSTMLText(
                    pStringTable->getString(g_bugTypes_guess[sel].promptId_008, 0), 1, 0);
            }
            return 0;
        }
        if (sender == (CXWnd*)interface_18c) {
            pEverQuest->dsp_chat(pStringTable->getString(0x22af, 0), 0xf, 1);
            ((Interface_guess*)this)->Slot34_guess();
            return 0;
        }
        if (sender == (CXWnd*)interface_16c) {
            ((Owner_guess*)this)->UpdateLocation_guess();
            return 0;
        }
        if (sender == (CXWnd*)interface_180) {
            char targetChecked = ((CButtonWnd*)interface_180)->Checked;
            if (targetChecked != 0) {
                if (g_target_guess != 0) {
                    targetId_0198_guess = g_target_guess->id_258;
                    targetName_019c_guess = g_target_guess->name_120;
                    flag_1a0 = g_target_guess->flag_244 == 0;
                    if (interface_188 != 0) {
                        CXStr tmp(g_everQuest_guess->Store_guess(g_target_guess->name_120));
                        interface_188->Slot63_guess(tmp);
                    }
                } else {
                    ((CButtonWnd*)interface_180)->SetCheck(false);
                }
            } else if (interface_188 != 0) {
                interface_188->Slot63_guess(EQ_ARRAY(char, 0x0063F53F));
            }
        } else if (sender == (CXWnd*)interface_190) {
            if (g_flag_9254ee_guess == 1) {
                SendBugReport_guess(true);
            } else {
                pConfirmationDialogPool_guess->Activate(
                    static_cast<Notifier_guess*>(this), 100,
                    pStringTable->getString(0x1aa3, 0), 0xc, 60000, 0, 0);
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// Confirmation answer for dialog 100: sends, with the system info only when the answer has bit 1 or 4
// set (probably yes).
// FUNCTION: TITANIUM 0x004EA36D
// @early-stop: unknown, structural ndiff=6
void Notifier_guess::Slot00_guess(int id_guess, unsigned char flags_guess, int data_guess) {
    if (id_guess == 100) {
        ((BugReportWnd_guess&)(*this)).SendBugReport_guess((flags_guess & 5) != 0);
    }
}
