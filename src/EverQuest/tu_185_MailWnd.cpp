// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 185: a hint from compare/tumap.py.
// The mail window (MailWindow; CMailWnd_guess, Pane_guess, Combined_guess and Target_guess are views of it):
// Inbox and Deleted Items pages, the character picker, compose/reply/forward through the compose window
// (0x850BE8), and message bodies shown as STML. The mail itself is held by the mail manager that CEverQuest
// (pEverQuest, 0x988DF0) returns (0x00495250), which talks to the chat/mail server; messages are moved
// between folders by id.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <string>
#include <time.h>
#include "titanium/wnd/CMailAddressBookWnd.h"
#include "titanium/wnd/COptionsWnd.h"

struct StringCaller_guess
{
    char pad_000_guess[0x15c];
    void ClearMessageBody_guess(int target_guess);
};

struct StringOwner_guess
{
    char pad[0x20];
    const char* text;
    CXStr Get_guess();
};

struct StringKey_guess : std::string
{
    // EXTERNAL: TITANIUM 0x0052FA04 StringKey_guess::Get_guess
    int Get_guess();
};

// EXTERNAL: TITANIUM 0x004275C7 BuildString_guess
CXStr __stdcall BuildString_guess(const char* text_guess);

struct CallbackOwner_guess
{
    // EXTERNAL: TITANIUM 0x00559545 CallbackOwner_guess::NewUIINI
    int NewUIINI();
    // EXTERNAL: TITANIUM 0x005A2660 CallbackOwner_guess::LoadIniInfo
    void LoadIniInfo();
    // EXTERNAL: TITANIUM 0x005A1890 CallbackOwner_guess::StoreIniInfo
    void StoreIniInfo();
    void FirstCallback_guess();
    void SecondCallback_guess();
};

struct IntIterator_guess
{
    int* pointer_guess;

    IntIterator_guess(int* pointer) : pointer_guess(pointer)
    {
    }

    IntIterator_guess(const IntIterator_guess& other_guess)
        : pointer_guess(other_guess.pointer_guess)
    {
    }

    bool operator!=(const IntIterator_guess& other_guess) const
    {
        return pointer_guess != other_guess.pointer_guess;
    }

    int& operator*() const
    {
        return *pointer_guess;
    }

    IntIterator_guess& operator++()
    {
        ++pointer_guess;
        return *this;
    }
};

struct StateCheck_guess
{
    char pad[0x5c];
    char active;
};

struct GuardedAction_guess
{
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
    virtual void Slot32_guess(int first_guess, int second_guess, int third_guess);

    char pad[0x16c];
    StateCheck_guess* state;
    int unknown174_guess;
    int enabled;
    int unknown17c_guess;
    int action;

    // EXTERNAL: TITANIUM 0x0059D770 GuardedAction_guess::Fallback_guess
    int Fallback_guess(int id_guess, int unknown_guess, char flag_guess);
    int Perform_guess(int id_guess, int unknown_guess, char flag_guess);
};

// EXTERNAL: TITANIUM 0x0052F9C5 Cleanup_guess
void __fastcall Cleanup_guess(int object_guess);

// Clears a message body (empty STML).
// FUNCTION: TITANIUM 0x0052E770
void StringCaller_guess::ClearMessageBody_guess(int target_guess)
{
    if (target_guess != 0)
        ((CStmlWnd*)target_guess)->SetSTMLText(EQ_ARRAY(char, 0x0063F53F), 0, 0);
}

// Mail window LoadIniInfo (vtable 0x6583A0 slot 70): loads its INI settings (0x005A2660) only once the
// character's UI ini exists (0x00559545).
// FUNCTION: TITANIUM 0x0052E7E8
void CallbackOwner_guess::FirstCallback_guess()
{
    if (NewUIINI())
        LoadIniInfo();
}

// Mail window StoreIniInfo (vtable 0x6583A0 slot 71): stores its INI settings (0x005A1890) only once
// the character's UI ini exists (0x00559545).
// FUNCTION: TITANIUM 0x0052E7FE
void CallbackOwner_guess::SecondCallback_guess()
{
    if (NewUIINI())
        StoreIniInfo();
}

struct StringMethods_guess : CXStr
{
    // EXTERNAL: TITANIUM 0x00572380 StringMethods_guess::Find_guess
    char Find_guess(char character_guess, int& position_guess);
    // EXTERNAL: TITANIUM 0x00572130 StringMethods_guess::Delete_guess
    void Delete_guess(int start_guess, int length_guess);
    // EXTERNAL: TITANIUM 0x005734D0 StringMethods_guess::Append_guess
    void Append_guess(char character_guess);
    // EXTERNAL: TITANIUM 0x00573B10 StringMethods_guess::Compare_guess
    int Compare_guess(const CXStr& other_guess, int flags_guess);
};

struct StringPair_guess
{
    int unknown_000_guess;
    StringMethods_guess first_guess;  // 0x04
    int unknown_008_guess;
    StringMethods_guess second_guess; // 0x0c
    int unknown_010_guess;            // 0x10
    int result_guess;                 // 0x14
};

struct StringPairOwner_guess
{
    void CompareBySubject_guess(StringPair_guess* pair_guess);
};

// Sort helper for subjects: strips leading "RE:"/"FW:"-style prefixes (anything up to a ':' before the first
// space, repeatedly), then compares case-insensitively.
// FUNCTION: TITANIUM 0x0052E814
void StringPairOwner_guess::CompareBySubject_guess(StringPair_guess* pair_guess)
{
    if (pair_guess == 0)
        return;

    StringMethods_guess first_guess(pair_guess->first_guess);
    StringMethods_guess second_guess(pair_guess->second_guess);
    int space_guess;
    int colon_guess;

    while (first_guess.Find_guess(' ', space_guess) &&
           first_guess.Find_guess(':', colon_guess) &&
           colon_guess < space_guess)
    {
        first_guess.Delete_guess(0, colon_guess + 1);
        first_guess.Append_guess(' ');
    }
    while (second_guess.Find_guess(' ', space_guess) &&
           second_guess.Find_guess(':', colon_guess) &&
           colon_guess < space_guess)
    {
        second_guess.Delete_guess(0, colon_guess + 1);
        second_guess.Append_guess(' ');
    }
    pair_guess->result_guess = first_guess.Compare_guess(second_guess, 2);
}

// Display global: the time at +0x148 is compared with the window's next tick (+0x1B8).
struct Display_guess
{
    unsigned int pad_000_guess[0x148 / 4];
    unsigned int time_guess;   // 0x148
};

#define pDisplay_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

struct Pane_guess : CXWnd
{
    unsigned int pad_11c_guess[(0x124 - 0x11C) / 4];
    int field_124_guess;
    unsigned int pad_128_guess[(0x170 - 0x128) / 4];
    CXWnd* first_guess;        // 0x170
    CXWnd* second_guess;       // 0x174
    CListWnd* first_list_guess; // 0x178
    CXWnd* flag_17c_guess;     // 0x17C
    CXWnd* flag_180_guess;     // 0x180
    CXWnd* flag_184_guess;     // 0x184
    CXWnd* flag_188_guess;     // 0x188
    CXWnd* flag_18c_guess;     // 0x18C
    CXWnd* flag_190_guess;     // 0x190
    int first_id_guess;        // 0x194
    CListWnd* second_list_guess; // 0x198
    CXWnd* flag_19c_guess;     // 0x19C
    CXWnd* flag_1a0_guess;     // 0x1A0
    CXWnd* flag_1a4_guess;     // 0x1A4
    CXWnd* flag_1a8_guess;     // 0x1A8
    CXWnd* flag_1ac_guess;     // 0x1AC
    CXWnd* flag_1b0_guess;     // 0x1B0
    int second_id_guess;       // 0x1B4
    unsigned int next_guess;   // 0x1B8

    void FirstPass_guess();
    void SecondPass_guess();
    int Tick_guess();
};

// Every 200 ms: enables the buttons of whichever page is showing.
// FUNCTION: TITANIUM 0x0052F857
int Pane_guess::Tick_guess()
{
    if (field_124_guess == 0)
        return 0;
    if (pDisplay_guess->time_guess > next_guess)
    {
        if (first_guess->Show != 0)
            FirstPass_guess();
        else if (second_guess->Show != 0)
            SecondPass_guess();
        next_guess = pDisplay_guess->time_guess + 200;
    }
    return OnProcessFrame();
}

// Standard library: std::find over an int range (the first element equal to `value`, else `last`). The
// list refill uses it to keep the selected message ids.
// FUNCTION: TITANIUM 0x0052F8BE
IntIterator_guess __cdecl Find_guess(IntIterator_guess first_guess,
                                     IntIterator_guess last_guess,
                                     const int& value_guess)
{
    for (; first_guess != last_guess; ++first_guess)
        if (*first_guess == value_guess)
            break;
    return first_guess;
}

// Returns the C string at +0x20 as a new string (0x004275C7): the mailbox name the title "Mailbox of
// %1" is built from (0x0052FAB0).
// FUNCTION: TITANIUM 0x0052FA04
CXStr StringOwner_guess::Get_guess()
{
    return BuildString_guess(text);
}

struct CompareEntry_guess;

struct Text_guess
{
    unsigned int raw_guess[7];     // 28 bytes: buffer or pointer at +4, capacity at +0x18

    // EXTERNAL: TITANIUM 0x0040291E Text_guess::Tidy_guess
    void Tidy_guess(bool built_guess, unsigned int size_guess);
    ~Text_guess()
    {
        Tidy_guess(true, 0);
    }
    const char* CStr_guess() const
    {
        return raw_guess[6] >= 16 ? (const char*)raw_guess[1] : (const char*)&raw_guess[1];
    }
    bool empty_guess() const
    {
        return raw_guess[5] == 0;
    }
};

struct Items_guess
{
    int unknown_guess;
    char* first_guess;
    char* last_guess;

    // EXTERNAL: TITANIUM 0x0040AB88 Items_guess::Size_guess
    unsigned int Size_guess();
};

struct FeedArg_guess
{
    int value_guess;

    FeedArg_guess(int value) : value_guess(value)
    {
    }
};

struct Collection_guess
{
    char pad_000_guess[0x04];
    int* pointer_004_guess;        // 0x04
    char pad_008_guess[0x04];
    Items_guess items_guess;       // 0x0C, 28-byte entries
    char pad_018_guess[0x04];
    int field_1c_guess;            // 0x1C

    // EXTERNAL: TITANIUM 0x004259D2 Collection_guess::Find_guess
    CompareEntry_guess* Find_guess(int key_guess);
    // EXTERNAL: TITANIUM 0x00518B72 Collection_guess::Insert_guess
    void Insert_guess(int* value_guess);
    // EXTERNAL: TITANIUM 0x00428A65 Collection_guess::Commit_guess
    void Commit_guess();
    // EXTERNAL: TITANIUM 0x004275C7 Collection_guess::Item_guess
    Text_guess Item_guess(unsigned int index_guess);
    // EXTERNAL: TITANIUM 0x00518D4A Collection_guess::Feed_guess
    void Feed_guess(FeedArg_guess first_guess, int* second_guess);
    // EXTERNAL: TITANIUM 0x0042886C Collection_guess::Extract_guess
    std::string Extract_guess(int key_guess, std::string search_guess, std::string fallback_guess);
    // EXTERNAL: TITANIUM 0x00428962 Collection_guess::SelectMailbox_guess
    void SelectMailbox_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00428A6E Collection_guess::RequestBody_guess
    void RequestBody_guess(unsigned int id_guess);
    // EXTERNAL: TITANIUM 0x00428C37 Collection_guess::Move_guess
    void Move_guess(unsigned int* ids_guess, int count_guess, int folder_guess);
    // EXTERNAL: TITANIUM 0x00428E9A Collection_guess::ReportMessages_guess
    void ReportMessages_guess(int count_guess, int* values_guess);
};

struct Service_guess
{
    // EXTERNAL: TITANIUM 0x00495250 Service_guess::Get_guess
    Collection_guess* Get_guess();
    // EXTERNAL: TITANIUM 0x00495250 Service_guess::GetKey_guess
    StringKey_guess GetKey_guess();
};

#define g_service_guess EQ_GLOBAL(Service_guess*, 0x00988DF0)

struct Holder_guess
{
    // EXTERNAL: TITANIUM 0x0059C3E0 Holder_guess::Begin_guess
    void Begin_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 Holder_guess::Add_guess
    void Add_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 Holder_guess::End_guess
    void End_guess(int id_guess);
    // EXTERNAL: TITANIUM 0x0059C330 Holder_guess::SetColors_guess
    void SetColors_guess(int a, int b, int c);
    // EXTERNAL: TITANIUM 0x0059C3A0 Holder_guess::GetCurChoice_guess
    int GetCurChoice_guess();
};

struct Target_guess
{
    unsigned char pad_000[0x160];
    unsigned char field_160;
    unsigned char pad_161_guess[3];
    Holder_guess* holder_164_guess;

    char Callback_guess();
    void Refresh_guess();
};

struct RefreshOwner_guess
{
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
    virtual void Slot63_guess(CXStr* text_guess);

    void Refresh_guess();
};

struct CompareEntry_guess
{
    int unknown_000_guess;
    unsigned int date_0004_guess;
    int unknown_008_guess;
    std::string name_guess;        // 0x0C
    std::string subject_guess;     // 0x28
};

struct CompareTarget_guess
{
    char pad_000[8];
    int first_key_guess;
    int pad_00c_guess;
    int second_key_guess;
    int result;
};

struct CompareOwner_guess
{
    void CompareByDate_guess(CompareTarget_guess* target_guess);
};

struct MailTemplate_guess
{
    char pad_000[0x60];
    unsigned int style_060;
};

struct Extent_guess
{
    int x_guess;
    int y_guess;

    Extent_guess(int x, int y) : x_guess(x), y_guess(y) {}
};

struct MailWnd_guess
{
    char pad_000[0x20];
    Extent_guess extent_020;

    // EXTERNAL: TITANIUM 0x004F6895 MailWnd_guess::GetSTMLText
    CXStr GetSTMLText();
};

struct MailList_guess : MailWnd_guess
{
    char pad_028[0x3c];
    unsigned int windowStyle_064;
    char pad_068[0xec];
    int field_154;
    unsigned char field_158;
    char pad_159[3];
    unsigned char field_15c;
    char pad_15d[0xf];
    unsigned int color_16c;

    // EXTERNAL: TITANIUM 0x00597C60 MailList_guess::SetColors
    void SetColors(unsigned long a, unsigned long b, unsigned long c);
};

struct RootBase_guess
{
    virtual void Slot00_guess();
    char pad_004[0x14];
    unsigned char field_018;
    char pad_019[7];
    Extent_guess extent_020;
    char pad_028[0x3c];
    unsigned int windowStyle_064;
    char pad_068[0xbc];
    MailTemplate_guess* sidlPiece_124;
    char pad_128[0x30];
    int field_158;

    // EXTERNAL: TITANIUM 0x005A3850 ??0RootBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    RootBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 RootBase_guess::~RootBase_guess
    ~RootBase_guess();
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7InnerBase_guess@@6B@
struct InnerBase_guess
{
    virtual void Slot00_guess();
};

struct RegistryBase_guess
{
    virtual void Slot00_guess();

    // EXTERNAL: TITANIUM 0x005482A0 RegistryBase_guess::Reset_guess
    void Reset_guess(int value_guess);
};

struct RegistrySubobject_guess : RegistryBase_guess
{
    // EXTERNAL: TITANIUM 0x0063FD9C ??_7RegistrySubobject_guess@@6B@
    ~RegistrySubobject_guess()
    {
        Reset_guess(-1);
    }
};

struct CMailWnd_guess : RootBase_guess, RegistrySubobject_guess, InnerBase_guess
{
    // EXTERNAL: TITANIUM 0x006583A0 ??_7CMailWnd_guess@@6BRootBase_guess@@@
    // EXTERNAL: TITANIUM 0x006584C0 ??_7CMailWnd_guess@@6BRegistrySubobject_guess@@@
    // EXTERNAL: TITANIUM 0x0065839C ??_7CMailWnd_guess@@6BInnerBase_guess@@@
    virtual void Slot01_guess();

    CMailWnd_guess(CXWnd* parent);
    CMailWnd_guess* Delete_guess(unsigned char flags_guess);
    ~CMailWnd_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);

    Holder_guess* characterBox_164;
    CXWnd* optionsButton_168;
    CXWnd* addressBookButton_16c;
    CXWnd* inboxPage_170;
    CXWnd* trashPage_174;
    MailList_guess* inboxList_178;
    CXWnd* composeButton_17c;
    CXWnd* deleteButton_180;
    CXWnd* replyButton_184;
    CXWnd* replyAllButton_188;
    CXWnd* forwardButton_18c;
    CXWnd* reportButton_190;
    MailWnd_guess* body_194;
    MailList_guess* trashList_198;
    CXWnd* trashComposeButton_19c;
    CXWnd* trashUndeleteButton_1a0;
    CXWnd* trashReplyButton_1a4;
    CXWnd* trashReplyAllButton_1a8;
    CXWnd* trashForwardButton_1ac;
    CXWnd* trashEmptyButton_1b0;
    MailWnd_guess* trashBody_1b4;
    int unknown_1b8;
};

// EXTERNAL: TITANIUM 0x0060D0D5 Free_guess
void __cdecl Free_guess(void* memory_guess);

// ArrayClass2<int>: count at +0, chunk table at +0x10 (element i = chunks[i >> shift][i & mask])
struct ArrayClass2_guess
{
    int count_guess;               // 0x00
    int unknown_004_guess;         // 0x04
    unsigned int mask_guess;       // 0x08
    int shift_guess;               // 0x0C
    int** chunks_guess;            // 0x10
    int unknown_014_guess[2];      // 0x14

    // EXTERNAL: TITANIUM 0x0047C3AF ArrayClass2_guess::ArrayClass2_guess
    ArrayClass2_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00406E7E ArrayClass2_guess::~ArrayClass2_guess
    ~ArrayClass2_guess();
};

struct ListSelect_guess
{
    char pad_000_guess[0x11c];
    int field_11c_guess;

    // EXTERNAL: TITANIUM 0x0059BB50 ListSelect_guess::GetSelected_guess
    void GetSelected_guess(ArrayClass2_guess& selected_guess);
};

#define g_state_guess EQ_GLOBAL(StateCheck_guess*, 0x00850BE8)

// Inbox buttons: Delete/Report need a selection; Reply, Reply All and Forward exactly one message; Compose
// and the reply buttons also need the compose window idle.
// FUNCTION: TITANIUM 0x0052F636
// @early-stop: budget, structural ndiff=2
void Pane_guess::FirstPass_guess()
{
    CListWnd* list_guess = first_list_guess;
    if (list_guess != 0)
    {
        ArrayClass2_guess selected_guess(0x20);
        ((ListSelect_guess*)list_guess)->GetSelected_guess(selected_guess);
        int count_guess = selected_guess.count_guess;
        if (flag_180_guess != 0)
            flag_180_guess->Enabled = count_guess > 0;
        if (flag_17c_guess != 0)
            flag_17c_guess->Enabled = g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_184_guess != 0)
            flag_184_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_188_guess != 0)
            flag_188_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_18c_guess != 0)
            flag_18c_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_190_guess != 0)
            flag_190_guess->Enabled = count_guess > 0;
    }
}

// Deleted Items buttons: the same rules; Empty needs at least one message.
// FUNCTION: TITANIUM 0x0052F741
// @early-stop: budget, structural ndiff=2
void Pane_guess::SecondPass_guess()
{
    CListWnd* list_guess = second_list_guess;
    if (list_guess != 0)
    {
        ArrayClass2_guess selected_guess(0x20);
        ((ListSelect_guess*)list_guess)->GetSelected_guess(selected_guess);
        int count_guess = selected_guess.count_guess;
        if (flag_19c_guess != 0)
            flag_19c_guess->Enabled = g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_1a0_guess != 0)
            flag_1a0_guess->Enabled = count_guess > 0;
        if (flag_1a4_guess != 0)
            flag_1a4_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_1a8_guess != 0)
            flag_1a8_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_1ac_guess != 0)
            flag_1ac_guess->Enabled = count_guess == 1 && g_state_guess != 0 && g_state_guess->active == 0;
        if (flag_1b0_guess != 0)
            flag_1b0_guess->Enabled = 0 < ((ListSelect_guess*)second_list_guess)->field_11c_guess;
    }
}

struct Work_guess
{
    char pad_000_guess[0x1c];
    CListWnd* list_guess;          // 0x1C
    char pad_020_guess[0x38 - 0x20];
    int value_guess;               // 0x38

    void Copy_guess(int first_guess, int flags_guess, int third_guess);
};

// Work_guess sits 0x15C into the object (StringCaller_guess is 0x15C bytes)
struct Whole_guess : StringCaller_guess, Work_guess
{
};

// Mouse release on a list (flags & 5): clears the body and hands the selected message ids to the service.
// FUNCTION: TITANIUM 0x0052F8E1
// @early-stop: budget, structural ndiff=7
void Work_guess::Copy_guess(int first_guess, int flags_guess, int third_guess)
{
    if ((flags_guess & 5) != 0)
    {
        CListWnd* list = list_guess;
        int index_guess = 0;
        if (list != 0)
        {
            ArrayClass2_guess selected_guess(0x20);
            ((ListSelect_guess*)list)->GetSelected_guess(selected_guess);
            int count_guess = selected_guess.count_guess;
            list_guess->ClearAllSel();
            static_cast<StringCaller_guess*>(static_cast<Whole_guess*>(this))->ClearMessageBody_guess(value_guess);
            if (count_guess >= 0)
            {
                flags_guess = (int)new int[count_guess];
                for (; index_guess < count_guess; ++index_guess)
                    ((int*)flags_guess)[index_guess] =
                        list_guess->GetItemData(selected_guess.chunks_guess[index_guess >> selected_guess.shift_guess][index_guess & selected_guess.mask_guess]);
                if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                    g_service_guess->Get_guess()->ReportMessages_guess(count_guess, (int*)flags_guess);
                delete[] (int*)flags_guess;
            }
        }
    }
}

// Unregisters the window from the mail service.
// FUNCTION: TITANIUM 0x0052FA1E
CMailWnd_guess::~CMailWnd_guess()
{
    int value_guess;
    Collection_guess* collection_guess;

    if (g_service_guess != 0)
    {
        if (g_service_guess->Get_guess() != 0)
        {
            value_guess = (int)static_cast<InnerBase_guess*>(this);
            collection_guess = g_service_guess->Get_guess();
            collection_guess->Insert_guess(&value_guess);
        }
    }
}

// Scalar deleting destructor of the mail window (vtable 0x6583A0 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x0052FD00
CMailWnd_guess* CMailWnd_guess::Delete_guess(unsigned char flags_guess)
{
    this->~CMailWnd_guess();
    if ((flags_guess & 1) != 0)
        Free_guess(this);
    return this;
}

// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
void __cdecl FormatString_guess(char* buffer_guess, int id_guess, const char* text_guess, int a_guess, int b_guess,
                                int c_guess, int d_guess, int e_guess, int f_guess, int g_guess, int h_guess);

// Title: "Mailbox of %1" (string 4537) with the mailbox name, or "Mailbox" (4536).
// FUNCTION: TITANIUM 0x0052FAB0
// @early-stop: budget, diff ndiff=4
void RefreshOwner_guess::Refresh_guess()
{
    if (g_service_guess != 0)
    {
        if (g_service_guess->Get_guess() != 0)
        {
            StringKey_guess key_guess = g_service_guess->GetKey_guess();
            key_guess.Get_guess();
            if (key_guess.size() != 0)
            {
                char buffer_guess[128];
                FormatString_guess(buffer_guess, 0x11b9, key_guess.c_str(), 0, 0, 0, 0, 0, 0, 0, 0);
                CXStr text_guess(buffer_guess);
                Slot63_guess(&text_guess);
            }
            else
            {
                CXStr text_guess(pStringTable->getString(0x11b8, 0));
                Slot63_guess(&text_guess);
            }
        }
    }
}

// Fills the character picker from the mail service's mailbox names and selects the current one.
// FUNCTION: TITANIUM 0x0052FBB7
void Target_guess::Refresh_guess()
{
    if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
    {
        Collection_guess* collection_guess = g_service_guess->Get_guess();
        if (collection_guess != 0 && holder_164_guess != 0)
        {
            holder_164_guess->Begin_guess();
            for (unsigned int i_guess = 0; i_guess < collection_guess->items_guess.Size_guess(); ++i_guess)
            {
                holder_164_guess->Add_guess(collection_guess->Item_guess(i_guess).CStr_guess());
            }
            holder_164_guess->End_guess(collection_guess->field_1c_guess);
        }
    }
}

// Unregisters the window (+0x160) from the mail manager (pEverQuest GetMailManager, 0x00495250): 0x00518B72
// removes it from the listener list. Then 0x00428A65 (selectmailbox with the manager's +0x20). Returns 1.
// The counterpart of 0x00530F1C, which registers it.
// FUNCTION: TITANIUM 0x0052FCAA
char Target_guess::Callback_guess()
{
    if (g_service_guess != 0)
    {
        if (g_service_guess->Get_guess() != 0)
        {
            Collection_guess* collection_guess = g_service_guess->Get_guess();
            int value_guess = this != 0 ? (int)&field_160 : 0;
            collection_guess->Insert_guess(&value_guess);
            collection_guess->Commit_guess();
        }
    }
    return 1;
}

// Tail call to 0x0052F9C5, which frees a vector's buffer and zeroes its three pointers; reached only
// from exception-unwind code.
// FUNCTION: TITANIUM 0x0052FCFB
void __fastcall FUN_0052fcfb(int object_guess)
{
    Cleanup_guess(object_guess);
}

struct MailCommit_guess
{
    // EXTERNAL: TITANIUM 0x0052DE40 MailCommit_guess::Compose_guess
    void Compose_guess(const CXStr& title_guess, const CXStr& recipient_guess, const CXStr& subject_guess,
                      const CXStr& body_guess);
};

#define g_mailCommit_guess EQ_GLOBAL(MailCommit_guess*, 0x00850BE8)

// EXTERNAL: TITANIUM 0x0060B020 FUN_0060b020_guess
CXStr __cdecl FUN_0060b020_guess(int value_guess);

struct MailText_guess
{
    // EXTERNAL: TITANIUM 0x00572C10 MailText_guess::Append_guess
    void Append_guess(const CXStr& text_guess);
};

struct MailCompose_guess
{
    void Compose_guess(int mode_guess, int key_guess, int value_guess);
};

// Reply (`mode_guess` 0), Reply All (1) or Forward (2): opens the compose window with "Reply to Message"/
// "Forward Message", "RE: "/"FW: " + subject, and the old body quoted under "-------". Reply All adds the old
// To list without the sender. Fails with string 4516 (no compose window) or 4517 (message not found).
// FUNCTION: TITANIUM 0x0052FD5C
void MailCompose_guess::Compose_guess(int mode_guess, int key_guess, int value_guess)
{
    if (g_mailCommit_guess == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x11a4, 0));
        return;
    }
    CompareEntry_guess* entry_guess;
    if (pEverQuest == 0 || g_service_guess->Get_guess() == 0
        || (entry_guess = g_service_guess->Get_guess()->Find_guess(key_guess)) == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x11a5, 0));
        return;
    }
    CXStr title_guess;
    if (mode_guess == 0 || mode_guess == 1) {
        title_guess = pStringTable->getString(0x11a8, 0);
    } else {
        title_guess = pStringTable->getString(0x11a7, 0);
    }
    CXStr recipient_guess;
    if (mode_guess == 0) {
        recipient_guess = entry_guess->name_guess.c_str();
    } else if (mode_guess == 1 && pEverQuest != 0 && g_service_guess->Get_guess() != 0) {
        std::string found_guess = g_service_guess->Get_guess()->Extract_guess(key_guess, "TO", EQ_ARRAY(char, 0x0063F53F));
        if (found_guess.find(entry_guess->name_guess, 0) == std::string::npos) {
            recipient_guess = entry_guess->name_guess.c_str();
        }
        if (found_guess.size() != 0) {
            if ((recipient_guess.Ptr != 0 ? recipient_guess.Ptr->length : 0) > 0) {
                recipient_guess += ", ";
            }
            recipient_guess += found_guess.c_str();
        }
    }
    CXStr subject_guess;
    if (mode_guess == 0 || mode_guess == 1) {
        subject_guess = pStringTable->getString(0x11a9, 0);
    } else {
        subject_guess = pStringTable->getString(0x11aa, 0);
    }
    subject_guess += ": ";
    subject_guess += entry_guess->subject_guess.c_str();
    CXStr body_guess("\n\n");
    body_guess += pStringTable->getString(0x11ab, 0);
    body_guess += "\n";
    ((MailText_guess*)&body_guess)->Append_guess(FUN_0060b020_guess(value_guess));
    g_mailCommit_guess->Compose_guess(title_guess, recipient_guess, subject_guess, body_guess);
}

#define g_colorOpen_guess EQ_ARRAY(char, 0x00656738)
#define g_colorClose_guess EQ_ARRAY(char, 0x00641684)

// EXTERNAL: TITANIUM 0x005A40F0 ColorString_guess
CXStr __cdecl ColorString_guess(unsigned long color_guess);
// EXTERNAL: TITANIUM 0x0042E3D9 PrefixText_guess
CXStr __cdecl PrefixText_guess(const char* left_guess, const CXStr& right_guess);
// EXTERNAL: TITANIUM 0x004B1357 SuffixText_guess
CXStr __cdecl SuffixText_guess(const CXStr& left_guess, const char* right_guess);
// EXTERNAL: TITANIUM 0x004D9090 JoinText_guess
CXStr __cdecl JoinText_guess(const CXStr& left_guess, const CXStr& right_guess);
// EXTERNAL: TITANIUM 0x0060ACA0 EscapeText_guess
CXStr __cdecl EscapeText_guess(const CXStr& text_guess);
// EXTERNAL: TITANIUM 0x0060B410 ConvertText_guess
CXStr __cdecl ConvertText_guess(const CXStr& text_guess);
// EXTERNAL: TITANIUM 0x0060ECA3 ctime_guess
char* __cdecl ctime_guess(const long* time_guess);
// EXTERNAL: TITANIUM 0x0060D970 strlen_guess
unsigned int __cdecl strlen_guess(const char* text_guess);

struct MailView_guess
{
    void Show_guess(CStmlWnd* window_guess, CompareEntry_guess* entry_guess, std::string* body_guess,
                    std::string* note_guess, bool raw_guess);
};

struct DispatchRequest_guess
{
    int action_guess;
    void* data_guess;
    int mode_guess;
};

struct DispatchData_guess
{
    int token_guess;
    int unknown_004_guess;
    int type_guess;
};

struct DispatchString_guess
{
    char buffer_guess[0x14];
    unsigned int size_guess;
    unsigned int capacity_guess;

    // EXTERNAL: TITANIUM 0x0040291E DispatchString_guess::Tidy_guess
    void Tidy_guess(bool built_guess, unsigned int size_guess);
    ~DispatchString_guess()
    {
        Tidy_guess(true, 0);
    }
    bool empty_guess() const
    {
        return size_guess == 0;
    }
};

struct DispatchValue_guess
{
    // EXTERNAL: TITANIUM 0x00426A9F DispatchValue_guess::Value_guess
    void* Value_guess();
};

struct DispatchResult_guess
{
    // EXTERNAL: TITANIUM 0x0042886C DispatchResult_guess::Apply_guess
    void Apply_guess();
    // EXTERNAL: TITANIUM 0x00428C37 DispatchResult_guess::Check_guess
    void Check_guess();
};

struct DispatchService_guess
{
    // EXTERNAL: TITANIUM 0x00495250 DispatchService_guess::Get_guess
    Collection_guess* Get_guess();
    // EXTERNAL: TITANIUM 0x00495250 DispatchService_guess::FindValue_guess
    DispatchValue_guess* FindValue_guess(int token_guess);
    // EXTERNAL: TITANIUM 0x00495250 DispatchService_guess::ResolveString_guess
    DispatchResult_guess* ResolveString_guess(DispatchString_guess* output_guess, int token_guess,
                                               std::string first_guess, std::string second_guess);
    // EXTERNAL: TITANIUM 0x00495250 DispatchService_guess::Check_guess
    DispatchResult_guess* Check_guess(int* token_guess, int first_guess, int second_guess);
};

#define g_dispatchService_guess EQ_GLOBAL(DispatchService_guess*, 0x00988DF0)

struct DispatchRegion_guess
{
    char pad_000_guess[0x18];
    CListWnd* first_items_guess;
    char pad_01c_guess[0x18];
    CStmlWnd* first_target_guess;
    CListWnd* second_items_guess;
    char pad_03c_guess[0x18];
    CStmlWnd* second_target_guess;

    void Handle_guess(int token_guess, DispatchRequest_guess* request_guess);
};

// Message header and body as STML: From, To (only when known), Subject, Date (ctime), Status (new, unread,
// read, deleted, permanently deleted; strings 4510-4515), then the body, escaped unless `raw_guess`.
// FUNCTION: TITANIUM 0x0052F0E2
void MailView_guess::Show_guess(CStmlWnd* window_guess, CompareEntry_guess* entry_guess, std::string* body_guess,
                                std::string* note_guess, bool raw_guess)
{
    if (window_guess != 0 && entry_guess != 0)
    {
        CXStr color_guess = SuffixText_guess(PrefixText_guess(g_colorOpen_guess, ColorString_guess(0xff8aa3ff)),
                                             g_colorClose_guess);
        CXStr tail_guess("</C> ");
        CXStr text_guess;
        MailText_guess& out_guess = (MailText_guess&)text_guess;

        out_guess.Append_guess(JoinText_guess(SuffixText_guess(color_guess, pStringTable->getString(0x1199, 0)),
                                              tail_guess));
        text_guess += entry_guess->name_guess.c_str();
        text_guess += "<BR>\n";
        if (note_guess->size() != 0)
        {
            out_guess.Append_guess(JoinText_guess(SuffixText_guess(color_guess, pStringTable->getString(0x119a, 0)),
                                                  tail_guess));
            out_guess.Append_guess(EscapeText_guess(note_guess->c_str()));
            text_guess += "<BR>\n";
        }
        out_guess.Append_guess(JoinText_guess(SuffixText_guess(color_guess, pStringTable->getString(0x119b, 0)),
                                              tail_guess));
        text_guess += entry_guess->subject_guess.c_str();
        text_guess += "<BR>\n";
        out_guess.Append_guess(JoinText_guess(SuffixText_guess(color_guess, pStringTable->getString(0x119c, 0)),
                                              tail_guess));
        long time_guess = entry_guess->date_0004_guess;
        char* date_guess = ctime_guess(&time_guess);
        date_guess[strlen_guess(date_guess) - 1] = 0;
        text_guess += date_guess;
        text_guess += "<BR>\n";
        out_guess.Append_guess(JoinText_guess(SuffixText_guess(color_guess, pStringTable->getString(0x119d, 0)),
                                              tail_guess));
        switch (entry_guess->unknown_008_guess)
        {
        case 0:
            text_guess += pStringTable->getString(0x119e, 0);
            break;
        case 1:
            text_guess += pStringTable->getString(0x119f, 0);
            break;
        case 2:
            text_guess += pStringTable->getString(0x11a0, 0);
            break;
        case 3:
            text_guess += pStringTable->getString(0x11a1, 0);
            break;
        case 4:
            text_guess += pStringTable->getString(0x11a2, 0);
            break;
        default:
            text_guess += pStringTable->getString(0x11a3, 0);
            break;
        }
        text_guess += "<BR>\n<BR>\n";
        CXStr body_text_guess;
        if (raw_guess)
            body_text_guess = body_guess->c_str();
        else
            body_text_guess = EscapeText_guess(body_guess->c_str());
        body_text_guess = ConvertText_guess(body_text_guess);
        out_guess.Append_guess(body_text_guess);
        window_guess->SetSTMLText(text_guess, false, 0);
    }
}

// Date sort: 1 when the first message is newer, -1 when older, 0 for equal or missing.
// FUNCTION: TITANIUM 0x0052E925
void CompareOwner_guess::CompareByDate_guess(CompareTarget_guess* target_guess)
{
    if (target_guess != 0)
    {
        Collection_guess* collection_guess = g_service_guess->Get_guess();
        CompareEntry_guess* first_guess = collection_guess->Find_guess(target_guess->first_key_guess);
        CompareEntry_guess* second_guess = collection_guess->Find_guess(target_guess->second_key_guess);
        if (first_guess == 0 || second_guess == 0 || second_guess->date_0004_guess == first_guess->date_0004_guess)
            target_guess->result = 0;
        else
            target_guess->result = second_guess->date_0004_guess < first_guess->date_0004_guess ? 1 : -1;
    }
}

// Style 0x10800, minimum size 320 x 160; both lists sort with 0xFF8AA3FF highlights.
// FUNCTION: TITANIUM 0x0052E9C3
CMailWnd_guess::CMailWnd_guess(CXWnd* parent)
    : RootBase_guess(parent, "MailWindow", -1, 1, 0)
{
    characterBox_164 = 0;
    optionsButton_168 = 0;
    addressBookButton_16c = 0;
    inboxPage_170 = 0;
    trashPage_174 = 0;
    inboxList_178 = 0;
    composeButton_17c = 0;
    deleteButton_180 = 0;
    replyButton_184 = 0;
    replyAllButton_188 = 0;
    forwardButton_18c = 0;
    reportButton_190 = 0;
    body_194 = 0;
    trashList_198 = 0;
    trashComposeButton_19c = 0;
    trashUndeleteButton_1a0 = 0;
    trashReplyButton_1a4 = 0;
    trashReplyAllButton_1a8 = 0;
    trashForwardButton_1ac = 0;
    trashEmptyButton_1b0 = 0;
    trashBody_1b4 = 0;
    if (sidlPiece_124 != 0)
    {
        windowStyle_064 |= sidlPiece_124->style_060 | 0x10800;
        field_158 = 0x43;
        field_018 = 1;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        extent_020 = Extent_guess(0x140, 0xa0);
        characterBox_164 = (Holder_guess*)((CSidlScreenWnd*)this)->GetChildItem("CharacterBoxSelector");
        if (characterBox_164 != 0)
        {
            characterBox_164->SetColors_guess(-1, 0xffffff00, 0xff808080);
            characterBox_164->End_guess(0);
        }
        addressBookButton_16c = ((CSidlScreenWnd*)this)->GetChildItem("AddressBookButton");
        optionsButton_168 = ((CSidlScreenWnd*)this)->GetChildItem("OptionsButton");
        inboxPage_170 = ((CSidlScreenWnd*)this)->GetChildItem("InboxPage");
        trashPage_174 = ((CSidlScreenWnd*)this)->GetChildItem("TrashPage");
        inboxList_178 = (MailList_guess*)((CSidlScreenWnd*)this)->GetChildItem("InboxList");
        if (inboxList_178 != 0)
        {
            inboxList_178->field_15c = 1;
            inboxList_178->SetColors(-1, 0xffffff00, 0xff808080);
            inboxList_178->color_16c = 0xff8aa3ff;
            inboxList_178->windowStyle_064 |= 0x60000;
            inboxList_178->field_154 = 2;
            inboxList_178->field_158 = 0;
            MailWnd_guess* inboxWnd_guess = inboxList_178;
            inboxWnd_guess->extent_020 = Extent_guess(0, 0x20);
        }
        body_194 = (MailWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("Body");
        if (body_194 != 0)
        {
            body_194->extent_020 = Extent_guess(0, 0x20);
        }
        composeButton_17c = ((CSidlScreenWnd*)this)->GetChildItem("ButtonCompose");
        deleteButton_180 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonDelete");
        replyButton_184 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonReply");
        replyAllButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonReplyAll");
        forwardButton_18c = ((CSidlScreenWnd*)this)->GetChildItem("ButtonForward");
        reportButton_190 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonReport");
        // The trash page repeats the inbox controls, with Undelete and Empty in place of Delete and Report.
        trashList_198 = (MailList_guess*)((CSidlScreenWnd*)this)->GetChildItem("TrashList");
        if (trashList_198 != 0)
        {
            trashList_198->field_15c = 1;
            trashList_198->SetColors(-1, 0xffffff00, 0xff808080);
            trashList_198->color_16c = 0xff8aa3ff;
            trashList_198->windowStyle_064 |= 0x60000;
            trashList_198->field_154 = 2;
            trashList_198->field_158 = 0;
            MailWnd_guess* trashWnd_guess = trashList_198;
            trashWnd_guess->extent_020 = Extent_guess(0, 0x20);
        }
        trashBody_1b4 = (MailWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("TrashBody");
        if (trashBody_1b4 != 0)
        {
            trashBody_1b4->extent_020 = Extent_guess(0, 0x20);
        }
        trashComposeButton_19c = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashCompose");
        trashUndeleteButton_1a0 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashUndelete");
        trashReplyButton_1a4 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashReply");
        trashReplyAllButton_1a8 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashReplyAll");
        trashForwardButton_1ac = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashForward");
        trashEmptyButton_1b0 = ((CSidlScreenWnd*)this)->GetChildItem("ButtonTrashEmpty");
        unknown_1b8 = 0;
    }
}

// The Delete key (DirectInput 0xD3) while the window is active runs its bound action (delete).
// FUNCTION: TITANIUM 0x0052E79E
int GuardedAction_guess::Perform_guess(int id_guess, int unknown_guess, char flag_guess)
{
    if (flag_guess != 0 && id_guess == 0xd3 && enabled != 0 && state->active != 0)
    {
        if (action != 0)
            Slot32_guess(action, 1, 0);
        return 0;
    }
    return Fallback_guess(id_guess, unknown_guess, flag_guess);
}



struct Combined_guess : Pane_guess
{
    // EXTERNAL: TITANIUM 0x0052FAB0 Combined_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x005309D5 Combined_guess::Rebuild_guess
    void Rebuild_guess();
    void Update_guess();
    char Apply_guess();
};

struct RowEntry_guess
{
    unsigned int id_guess;
    time_t time_guess;
    int type_guess;
    std::string first_text_guess;
    std::string second_text_guess;
};

struct RowStore_guess
{
    unsigned int pad_000_guess[9];
    struct Array_guess
    {
        unsigned int pad_000_guess[3];
        RowEntry_guess** first_guess;
        unsigned int bytes_guess;
    } items_guess;

    unsigned int pad_034_guess[(0x108 - 0x38) / 4];
    int saved_first_guess;
    int saved_second_guess;
    unsigned int pad_110_guess[(0x11C - 0x110) / 4];
    int count_guess;

    // EXTERNAL: TITANIUM 0x00428A6E RowStore_guess::Select_guess
    void Select_guess(int id_guess);
};

struct RowIterator_guess
{
    RowStore_guess::Array_guess* items_guess;

    // EXTERNAL: TITANIUM 0x00425170 RowIterator_guess::Next_guess
    RowEntry_guess*& Next_guess();
    // EXTERNAL: TITANIUM 0x00425196 RowIterator_guess::More_guess
    char More_guess(const struct RowRange_guess& range_guess);
};

struct RowRange_guess
{
    RowStore_guess::Array_guess* first_guess;
    RowEntry_guess** last_guess;
};

struct RowPiece_guess
{
    int field_guess;
    CXStr text_guess;
    int length_guess;

    RowPiece_guess() : text_guess()
    {
        length_guess = -1;
        field_guess = 0;
    }
};

struct RowText_guess;

struct TextOutput_guess
{
    // EXTERNAL: TITANIUM 0x005C0CC0 TextOutput_guess::Set_guess
    void Set_guess(const CXStr& text_guess);
};

struct SelectedItems_guess
{
    int* first_guess;
    int* last_guess;
    int* end_guess;

    SelectedItems_guess() : first_guess(0), last_guess(0), end_guess(0) {}
    void Add_guess(int value_guess)
    {
        if (last_guess == end_guess)
        {
            int size_guess = first_guess == 0 ? 0 : (int)(last_guess - first_guess);
            int capacity_guess = size_guess + 8;
            int* values_guess = new int[capacity_guess];
            for (int i_guess = 0; i_guess < size_guess; ++i_guess)
                values_guess[i_guess] = first_guess[i_guess];
            delete[] first_guess;
            first_guess = values_guess;
            last_guess = values_guess + size_guess;
            end_guess = values_guess + capacity_guess;
        }
        *last_guess++ = value_guess;
    }
    // EXTERNAL: TITANIUM 0x00530918 SelectedItems_guess::Insert_guess
    void Insert_guess(const int& value_guess);
    // EXTERNAL: TITANIUM 0x0052F9C5 SelectedItems_guess::~SelectedItems_guess
    ~SelectedItems_guess();
};

struct ListDataActions_guess
{
    // EXTERNAL: TITANIUM 0x0059B800 ListDataActions_guess::Add_guess
    void Add_guess(RowText_guess* text_guess);
    // EXTERNAL: TITANIUM 0x00597C20 ListDataActions_guess::SetCurSel
    void SetCurSel(int index_guess);
};

struct ListState_guess
{
    unsigned char pad_000_guess[0x108];
    int count_guess;
    int selected_guess;
};

struct RowText_guess
{
    int field_000_guess;
    int field_004_guess;
    int field_008_guess;
    unsigned char field_00c_guess;
    unsigned char pad_00d_guess[3];
    int field_010_guess;
    int field_014_guess;
    unsigned char selected_018_guess;
    unsigned char field_019_guess;
    unsigned char pad_01a_guess[2];

    // EXTERNAL: TITANIUM 0x0042D7A7 RowText_guess::Format_guess
    void Format_guess(int first_guess, RowPiece_guess* piece_guess);
    // EXTERNAL: TITANIUM 0x0042D7E5 RowText_guess::~RowText_guess
    ~RowText_guess();
};

struct RowProvider_guess
{
    // EXTERNAL: TITANIUM 0x00495250 RowProvider_guess::Get_guess
    RowStore_guess* Get_guess();
};

struct LabelString_guess : std::string
{
    LabelString_guess(const char* text_guess) : std::string(text_guess) {}

    // EXTERNAL: TITANIUM 0x00427607 LabelString_guess::Append_guess
    void Append_guess(const char* text_guess);
};

struct ListVTable_guess
{
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
    virtual void SetCount_guess(int count_guess);
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
    virtual void Clear_guess();
};

// Adds the message ids of every selected row to `selected_guess`.
// FUNCTION: TITANIUM 0x00530958
// @early-stop: budget, structural ndiff=2
void __cdecl FillSelected_guess(CListWnd* list_guess, SelectedItems_guess* selected_guess)
{
    int index_guess = 0;
    if (list_guess == 0)
        return;

    ArrayClass2_guess rows_guess(0x20);
    ((ListSelect_guess*)list_guess)->GetSelected_guess(rows_guess);
    int count_guess = rows_guess.count_guess;
    for (; index_guess < count_guess; ++index_guess)
    {
        int value_guess = (int)list_guess->GetItemData(
            rows_guess.chunks_guess[index_guess >> rows_guess.shift_guess]
                                   [rows_guess.mask_guess & index_guess]);
        selected_guess->Insert_guess(value_guess);
    }
}

// Refills both lists from the mail service (sender, subject, date; new and unread rows styled apart), keeps
// the selection,
// and labels the tabs "Inbox [n]" / "Deleted Items [n]" (strings 4503/4504) with the unread count.
// FUNCTION: TITANIUM 0x005309D5
// @early-stop: budget, structural ndiff=188
void Combined_guess::Rebuild_guess()
{
    if (first_list_guess == 0)
        return;
    if (second_list_guess == 0)
        return;
    {
        int first_limit_guess;
        int second_limit_guess;
        SelectedItems_guess selected_guess;
        FillSelected_guess(first_list_guess, &selected_guess);
        FillSelected_guess(second_list_guess, &selected_guess);
        first_limit_guess = ((ListState_guess*)first_list_guess)->selected_guess;
        second_limit_guess = ((ListState_guess*)second_list_guess)->selected_guess;
        int first_value_guess = (int)first_list_guess->GetItemData(first_list_guess->GetCurSel());
        int second_value_guess = (int)second_list_guess->GetItemData(second_list_guess->GetCurSel());

        ((ListVTable_guess*)first_list_guess)->Clear_guess();
        ((ListVTable_guess*)second_list_guess)->Clear_guess();

        if (g_service_guess != 0)
        {
            RowStore_guess* rows_guess = ((RowProvider_guess*)g_service_guess)->Get_guess();
            if (rows_guess != 0)
            {
                int first_count_guess = 0;
                int second_count_guess = 0;
                char count_buffer_guess[12];
                RowIterator_guess iterator_guess;
                RowRange_guess range_guess;
                iterator_guess.items_guess = &rows_guess->items_guess;
                range_guess.first_guess = &rows_guess->items_guess;
                range_guess.last_guess = (RowEntry_guess**)((int)rows_guess->items_guess.first_guess
                                                            + rows_guess->items_guess.bytes_guess);
                while (iterator_guess.More_guess(range_guess))
                {
                    RowEntry_guess* row_guess = iterator_guess.Next_guess();
                    RowText_guess row_text_guess;
                    row_text_guess.field_004_guess = 0;
                    row_text_guess.field_000_guess = 0;
                    row_text_guess.field_008_guess = 0;
                    row_text_guess.field_00c_guess = 1;
                    row_text_guess.field_010_guess = 0;
                    row_text_guess.field_014_guess = -1;
                    row_text_guess.selected_018_guess = 0;
                    row_text_guess.field_019_guess = 1;
                    RowPiece_guess first_text_guess;
                    RowPiece_guess second_text_guess;
                    RowPiece_guess time_text_guess;
                    time_t timestamp_guess = row_guess->time_guess;
                    first_text_guess.text_guess = row_guess->first_text_guess.c_str();
                    second_text_guess.text_guess = row_guess->second_text_guess.c_str();
                    time_text_guess.text_guess = ctime(&timestamp_guess);

                    if (row_guess->type_guess == 0 || row_guess->type_guess == 1)
                    {
                        first_text_guess.length_guess = 0xffffc896;
                        second_text_guess.length_guess = 0xffffc896;
                        time_text_guess.length_guess = 0xffffc896;
                    }

                    row_text_guess.Format_guess(row_text_guess.field_000_guess, &first_text_guess);
                    row_text_guess.Format_guess(row_text_guess.field_000_guess, &second_text_guess);
                    row_text_guess.Format_guess(row_text_guess.field_000_guess, &time_text_guess);

                    int row_id_guess = (int)row_guess->id_guess;
                    row_text_guess.field_010_guess = row_id_guess;
                    IntIterator_guess first_item_guess(selected_guess.first_guess);
                    IntIterator_guess last_item_guess(selected_guess.last_guess);
                    IntIterator_guess found_guess = Find_guess(first_item_guess, last_item_guess, row_id_guess);
                    row_text_guess.selected_018_guess =
                        found_guess.pointer_guess != last_item_guess.pointer_guess;
                    if (row_guess->type_guess == 3)
                    {
                        ((ListDataActions_guess*)second_list_guess)->Add_guess(&row_text_guess);
                        ++second_count_guess;
                    }
                    else
                    {
                        if (row_guess->type_guess == 0 || row_guess->type_guess == 1)
                            ++first_count_guess;
                        ((ListDataActions_guess*)first_list_guess)->Add_guess(&row_text_guess);
                    }
                }

                int found_first_guess = 0;
                for (int i_guess = 0; i_guess < first_list_guess->ItemsCount; ++i_guess)
                {
                    if ((int)first_list_guess->GetItemData(i_guess) == first_value_guess)
                    {
                        ((ListDataActions_guess*)first_list_guess)->SetCurSel(i_guess);
                        rows_guess->Select_guess(first_value_guess);
                        found_first_guess = 1;
                        break;
                    }
                }
                if (found_first_guess == 0)
                    ((StringCaller_guess*)this)->ClearMessageBody_guess(first_id_guess);

                int found_second_guess = 0;
                for (int i_guess = 0; i_guess < second_list_guess->ItemsCount; ++i_guess)
                {
                    if ((int)second_list_guess->GetItemData(i_guess) == second_value_guess)
                    {
                        ((ListDataActions_guess*)second_list_guess)->SetCurSel(i_guess);
                        rows_guess->Select_guess(second_value_guess);
                        found_second_guess = 1;
                        break;
                    }
                }
                if (found_second_guess == 0)
                    ((StringCaller_guess*)this)->ClearMessageBody_guess(second_id_guess);

                int first_rows_guess = first_limit_guess;
                if (((ListState_guess*)first_list_guess)->count_guess < first_rows_guess)
                    first_rows_guess = ((ListState_guess*)first_list_guess)->count_guess;
                ((ListVTable_guess*)first_list_guess)->SetCount_guess(first_rows_guess);
                int second_rows_guess = second_limit_guess;
                if (((ListState_guess*)second_list_guess)->count_guess < second_rows_guess)
                    second_rows_guess = ((ListState_guess*)second_list_guess)->count_guess;
                ((ListVTable_guess*)second_list_guess)->SetCount_guess(second_rows_guess);

                if (first_guess != 0)
                {
                    LabelString_guess label_guess(pStringTable->getString(0x1197, 0));
                    if (first_count_guess != 0)
                    {
                        sprintf(count_buffer_guess, " [%d]", first_count_guess);
                        label_guess.Append_guess(count_buffer_guess);
                    }
                    CXStr label_text_guess(label_guess.c_str());
                    ((TextOutput_guess*)first_guess)->Set_guess(label_text_guess);
                }
                if (second_guess != 0)
                {
                    LabelString_guess label_guess(pStringTable->getString(0x1198, 0));
                    if (second_count_guess != 0)
                    {
                        sprintf(count_buffer_guess, " [%d]", second_count_guess);
                        label_guess.Append_guess(count_buffer_guess);
                    }
                    CXStr label_text_guess(label_guess.c_str());
                    ((TextOutput_guess*)second_guess)->Set_guess(label_text_guess);
                }
            }
        }
    }
}

// Full refresh of the mail window: title (0x0052FAB0), character picker (0x0052FBB7), both message
// lists (0x005309D5), then the Inbox and Deleted Items button states (0x0052F636, 0x0052F741).
// FUNCTION: TITANIUM 0x00530EF7
void Combined_guess::Update_guess()
{
    Prepare_guess();
    reinterpret_cast<Target_guess*>(this)->Refresh_guess();
    Rebuild_guess();
    FirstPass_guess();
    SecondPass_guess();
}

// Full refresh, then registers for further updates.
// FUNCTION: TITANIUM 0x00530F1C
char Combined_guess::Apply_guess()
{
    Update_guess();
    if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
    {
        int value_guess = this != 0 ? (int)&reinterpret_cast<Target_guess*>(this)->field_160 : 0;
        Collection_guess* collection_guess = g_service_guess->Get_guess();
        collection_guess->Feed_guess(FeedArg_guess(*collection_guess->pointer_004_guess), &value_guess);
    }
    return 1;
}

// Mail service callback for one message: shows its body when it is the selected row, a requesting
// note while it loads, or a service-unavailable note.
// FUNCTION: TITANIUM 0x00530F6D
// @early-stop: unknown, diff ndiff=117
void DispatchRegion_guess::Handle_guess(int token_guess, DispatchRequest_guess* request_guess)
{
    if (g_dispatchService_guess == 0)
        return;
    if ((Collection_guess*)token_guess != g_dispatchService_guess->Get_guess())
        return;
    if (request_guess == 0)
        return;

    if (request_guess->action_guess == 2)
    {
        Combined_guess* combined_guess = reinterpret_cast<Combined_guess*>((int*)this - 0x58);
        combined_guess->Prepare_guess();
        reinterpret_cast<Target_guess*>(combined_guess)->Refresh_guess();
        return;
    }
    if (request_guess->action_guess == 3)
    {
        Target_guess* target_guess = reinterpret_cast<Target_guess*>((int*)this - 0x58);
        target_guess->Refresh_guess();
        return;
    }
    if (request_guess->action_guess == 0)
    {
        Combined_guess* combined_guess = reinterpret_cast<Combined_guess*>((int*)this - 0x58);
        combined_guess->Rebuild_guess();
        combined_guess->FirstPass_guess();
        combined_guess->SecondPass_guess();
        return;
    }
    if (request_guess->action_guess != 1 || request_guess->data_guess == 0)
        return;

    DispatchData_guess* data_guess = (DispatchData_guess*)request_guess->data_guess;
    CListWnd* items_guess;
    CStmlWnd* target_guess;
    if (data_guess->type_guess == 3)
    {
        items_guess = second_items_guess;
        target_guess = second_target_guess;
    }
    else
    {
        items_guess = first_items_guess;
        target_guess = first_target_guess;
    }

    if (items_guess == 0 || target_guess == 0)
        return;

    int index_guess = items_guess->GetCurSel();
    if (index_guess < 0 || items_guess->GetItemData(index_guess) != data_guess->token_guess)
        return;

    if (request_guess->mode_guess == 2)
    {
        DispatchValue_guess* value_guess = g_dispatchService_guess->FindValue_guess(data_guess->token_guess);
        void* value_data_guess = value_guess->Value_guess();
        DispatchString_guess first_guess;
        g_dispatchService_guess->ResolveString_guess(&first_guess, data_guess->token_guess,
                                                     std::string(EQ_ARRAY(char, 0x00658534)),
                                                     std::string(EQ_ARRAY(char, 0x0063F53F)))->Apply_guess();
        DispatchString_guess second_guess;
        g_dispatchService_guess->ResolveString_guess(&second_guess, data_guess->token_guess,
                                                     std::string(EQ_ARRAY(char, 0x006584F0)),
                                                     std::string(EQ_ARRAY(char, 0x0063F53F)))->Apply_guess();
        if (value_data_guess != 0)
        {
            std::string* data_text_guess = first_guess.empty_guess() ? (std::string*)value_data_guess :
                                                                      (std::string*)&first_guess;
            ((MailView_guess*)((int*)this - 0x58))->Show_guess((CStmlWnd*)target_guess,
                                                              (CompareEntry_guess*)request_guess->data_guess,
                                                              data_text_guess,
                                                              (std::string*)&second_guess,
                                                              first_guess.empty_guess() ? 0 : 1);
        }
        if (data_guess->type_guess == 0 || data_guess->type_guess == 1)
            g_dispatchService_guess->Check_guess(&token_guess, 1, 2)->Check_guess();
        return;
    }

    if (request_guess->mode_guess == 1)
        target_guess->SetSTMLText(CXStr("Requesting Message"), true, 0);
    else
        target_guess->SetSTMLText(CXStr("Service Unavailable"), false, 0);
}

// Window vtable view: slot 0x84 activates, slot 0x138 re-sorts a list.
struct WndVirtuals_guess
{
    virtual void V00_guess(); virtual void V01_guess(); virtual void V02_guess(); virtual void V03_guess();
    virtual void V04_guess(); virtual void V05_guess(); virtual void V06_guess(); virtual void V07_guess();
    virtual void V08_guess(); virtual void V09_guess(); virtual void V10_guess(); virtual void V11_guess();
    virtual void V12_guess(); virtual void V13_guess(); virtual void V14_guess(); virtual void V15_guess();
    virtual void V16_guess(); virtual void V17_guess(); virtual void V18_guess(); virtual void V19_guess();
    virtual void V20_guess(); virtual void V21_guess(); virtual void V22_guess(); virtual void V23_guess();
    virtual void V24_guess(); virtual void V25_guess(); virtual void V26_guess(); virtual void V27_guess();
    virtual void V28_guess(); virtual void V29_guess(); virtual void V30_guess(); virtual void V31_guess();
    virtual void V32_guess();
    virtual void AboutToShow_guess();  // 0x84
    virtual void V34_guess(); virtual void V35_guess();
    virtual void V36_guess(); virtual void V37_guess(); virtual void V38_guess(); virtual void V39_guess();
    virtual void V40_guess(); virtual void V41_guess(); virtual void V42_guess(); virtual void V43_guess();
    virtual void V44_guess(); virtual void V45_guess(); virtual void V46_guess(); virtual void V47_guess();
    virtual void V48_guess(); virtual void V49_guess(); virtual void V50_guess(); virtual void V51_guess();
    virtual void V52_guess(); virtual void V53_guess(); virtual void V54_guess(); virtual void V55_guess();
    virtual void V56_guess(); virtual void V57_guess(); virtual void V58_guess(); virtual void V59_guess();
    virtual void V60_guess(); virtual void V61_guess(); virtual void V62_guess(); virtual void V63_guess();
    virtual void V64_guess(); virtual void V65_guess(); virtual void V66_guess(); virtual void V67_guess();
    virtual void V68_guess(); virtual void V69_guess(); virtual void V70_guess(); virtual void V71_guess();
    virtual void V72_guess(); virtual void V73_guess(); virtual void V74_guess(); virtual void V75_guess();
    virtual void V76_guess(); virtual void V77_guess();
    virtual void Sort_guess();      // 0x138

    // EXTERNAL: TITANIUM 0x0059D080 WndVirtuals_guess::Show_guess
    void Show_guess(int show_guess);
};


struct SortList_guess : WndVirtuals_guess
{
    char pad_004[0x150];
    int sortColumn_154;
    bool sortReverse_158;
};

struct SelArray_guess
{
    int count_000;
    int alloc_004;
    int mask_008;
    int shift_00c;
    int** blocks_010;
    int blockCount_014;
    unsigned int flag_018;
    int cursor_01c;
    // EXTERNAL: TITANIUM 0x0047C3AF SelArray_guess::Initialize_guess
    void Initialize_guess(int size);
    SelArray_guess(int size) { Initialize_guess(size); }
    // EXTERNAL: TITANIUM 0x00406E7E SelArray_guess::~SelArray_guess
    ~SelArray_guess();
    int& operator[](int index) { return blocks_010[index >> shift_00c][index & mask_008]; }
};

struct MailListWnd_guess : CListWnd
{
    // EXTERNAL: TITANIUM 0x0059BB50 MailListWnd_guess::GetSelected_guess
    void GetSelected_guess(SelArray_guess* out_guess);
};

// Buttons: Compose opens an empty composition window; Delete and Undelete move the selection between folders;
// Empty moves every deleted message to folder 4 (permanently deleted); Report asks string 4532 first. A list
// click opens the message; a column click (0xF) sorts, again on the same column reverses.
// FUNCTION: TITANIUM 0x00530065
// @early-stop: budget, structural ndiff=121
int CMailWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data)
{
    // Sort callbacks from the lists: kind 1 prepares a cell's text, kind 2 compares two rows.
    if (message == 0x10)
    {
        if (data != 0)
        {
            switch (((StringPair_guess*)data)->unknown_000_guess)
            {
            case 1:
                ((StringPairOwner_guess*)this)->CompareBySubject_guess((StringPair_guess*)data);
                break;
            case 2:
                ((CompareOwner_guess*)this)->CompareByDate_guess((CompareTarget_guess*)data);
                break;
            }
        }
    }
    else if (message == 1)
    {
        ((CXWnd*)this)->SetFocus();
        if (sender == (CXWnd*)inboxList_178 || sender == (CXWnd*)trashList_198)
        {
            MailListWnd_guess* list_guess = (MailListWnd_guess*)sender;
            int sel_guess = list_guess->GetCurSel();
            if (sel_guess >= 0)
            {
                unsigned int id_guess = list_guess->GetItemData(sel_guess);
                if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                    g_service_guess->Get_guess()->RequestBody_guess(id_guess);
            }
            else
            {
                ((StringCaller_guess*)this)->ClearMessageBody_guess(
                    sender == (CXWnd*)inboxList_178 ? (int)body_194 : (int)trashBody_1b4);
            }
            if (sender == (CXWnd*)inboxList_178)
                ((Pane_guess*)this)->FirstPass_guess();
            else
                ((Pane_guess*)this)->SecondPass_guess();
        }
        else if (sender == (CXWnd*)characterBox_164)
        {
            if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                g_service_guess->Get_guess()->SelectMailbox_guess(characterBox_164->GetCurChoice_guess());
        }
        else if (sender == addressBookButton_16c)
        {
            if (pinstCMailAddressBookWnd_guess != 0)
            {
                pinstCMailAddressBookWnd_guess->Activate();
                pinstCMailAddressBookWnd_guess->BringToTop(1);
            }
        }
        else if (sender == optionsButton_168)
        {
            if (pinstCOptionsWnd_guess != 0)
            {
                pinstCOptionsWnd_guess->Dispatch_guess(6);
                pinstCOptionsWnd_guess->Activate();
                pinstCOptionsWnd_guess->BringToTop(1);
            }
        }
        else if (sender == composeButton_17c || sender == trashComposeButton_19c)
        {
            if (g_mailCommit_guess != 0)
            {
                CXStr body_guess(EQ_ARRAY(char, 0x0063F53F));
                CXStr subject_guess(EQ_ARRAY(char, 0x0063F53F));
                CXStr recipient_guess(EQ_ARRAY(char, 0x0063F53F));
                CXStr title_guess("Compose Message");
                g_mailCommit_guess->Compose_guess(title_guess, recipient_guess, subject_guess, body_guess);
            }
        }
        else if (sender == deleteButton_180 || sender == trashUndeleteButton_1a0)
        {
            MailListWnd_guess* list_guess = sender == deleteButton_180 ? (MailListWnd_guess*)inboxList_178
                                                                       : (MailListWnd_guess*)trashList_198;
            MailWnd_guess* view_guess = sender == deleteButton_180 ? body_194 : trashBody_1b4;
            if (list_guess != 0)
            {
                SelArray_guess selected_guess(0x20);
                list_guess->GetSelected_guess(&selected_guess);
                int count_guess = selected_guess.count_000;
                list_guess->ClearAllSel();
                ((StringCaller_guess*)this)->ClearMessageBody_guess((int)view_guess);
                if (count_guess >= 0)
                {
                    unsigned int* ids_guess = new unsigned int[count_guess];
                    for (int i = 0; i < count_guess; i++)
                        ids_guess[i] = list_guess->GetItemData(selected_guess[i]);
                    if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                        g_service_guess->Get_guess()->Move_guess(ids_guess, count_guess,
                                                                 sender == deleteButton_180 ? 3 : 2);
                    delete[] ids_guess;
                    int items_guess = list_guess->ItemsCount;
                    if (items_guess > 0)
                    {
                        int next_guess = selected_guess[0];
                        if (next_guess >= items_guess)
                            next_guess = items_guess - 1;
                        list_guess->SetCurSel(next_guess);
                        if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                            g_service_guess->Get_guess()->RequestBody_guess(list_guess->GetItemData(next_guess));
                    }
                }
            }
        }
        else if (sender == replyButton_184)
        {
            if (inboxList_178 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)inboxList_178)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = body_194->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(0, ((MailListWnd_guess*)inboxList_178)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == replyAllButton_188)
        {
            if (inboxList_178 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)inboxList_178)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = body_194->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(1, ((MailListWnd_guess*)inboxList_178)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == trashReplyButton_1a4)
        {
            if (trashList_198 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)trashList_198)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = trashBody_1b4->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(0, ((MailListWnd_guess*)trashList_198)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == trashReplyAllButton_1a8)
        {
            if (trashList_198 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)trashList_198)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = trashBody_1b4->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(1, ((MailListWnd_guess*)trashList_198)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == forwardButton_18c)
        {
            if (inboxList_178 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)inboxList_178)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = body_194->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(2, ((MailListWnd_guess*)inboxList_178)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == trashForwardButton_1ac)
        {
            if (trashList_198 != 0)
            {
                int sel_guess = ((MailListWnd_guess*)trashList_198)->GetCurSel();
                if (sel_guess >= 0)
                {
                    CXStr text_guess = trashBody_1b4->GetSTMLText();
                    ((MailCompose_guess*)this)->Compose_guess(2, ((MailListWnd_guess*)trashList_198)->GetItemData(sel_guess),
                                                             (int)&text_guess);
                }
            }
        }
        else if (sender == reportButton_190)
        {
            pConfirmationDialogPool_guess->Activate(static_cast<RegistrySubobject_guess*>(this), 0,
                                                    pStringTable->getString(0x11b4, 0), 0xc, -1, 0, 0);
        }
        else if (sender == trashEmptyButton_1b0)
        {
            int count_guess;
            if (trashList_198 != 0 && (count_guess = ((MailListWnd_guess*)trashList_198)->ItemsCount) != 0)
            {
                unsigned int* ids_guess = new unsigned int[count_guess];
                for (int i = 0; i < count_guess; i++)
                    ids_guess[i] = ((MailListWnd_guess*)trashList_198)->GetItemData(i);
                if (g_service_guess != 0 && g_service_guess->Get_guess() != 0)
                    g_service_guess->Get_guess()->Move_guess(ids_guess, count_guess, 4);
                delete[] ids_guess;
            }
            ((StringCaller_guess*)this)->ClearMessageBody_guess((int)trashBody_1b4);
        }
    }
    else if (message == 4)
    {
    }
    // Column click: a new column sorts with +0x158 set, except column 2, which starts with it clear (the
    // other direction); the same column again flips it.
    else if (message == 0xf)
    {
        if ((sender == (CXWnd*)inboxList_178 || sender == (CXWnd*)trashList_198) && sender != 0)
        {
            SortList_guess* list_guess = (SortList_guess*)sender;
            if (list_guess->sortColumn_154 == (int)data)
            {
                list_guess->sortReverse_158 = !list_guess->sortReverse_158;
            }
            else
            {
                list_guess->sortColumn_154 = (int)data;
                list_guess->sortReverse_158 = (int)data != 2;
            }
            list_guess->Sort_guess();
        }
    }
    else
    {
        return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
    }
    return 0;
}
