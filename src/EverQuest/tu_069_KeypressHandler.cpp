// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 69: a hint from compare/tumap.py.
// Two unrelated halves: item helpers (container restriction strings, no-drop and container checks, a
// '|'-separated record parser, OP_ReadBook) and the key-map table: 0x10B commands with a primary and an
// alternate key each, loaded from and saved to the KeyMaps INI section as KEYMAPPING_<command>_<1|2>.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"

#define g_buffer_guess EQ_GLOBAL(void*, 0x0098599C)

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

#include "titanium/layouts/shared_classes.h"
#include "titanium/wnd/CBookWnd.h"
#include "titanium/wnd/CNoteWnd.h"

#include "titanium/core_decls.h"
struct StateFlag_guess {
    char pad_guess[0x90];
    int value_guess;

    bool SetOpen_guess();
    bool ClearOpen_guess();
};

struct ResetBlock_guess {
    char pad_guess[0x858];
    char data_guess[0x10b];

    void Reset_guess();
};

struct Entry_guess {
    int value_guess; // 0x0

    // EXTERNAL: TITANIUM 0x005BA220 Entry_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x005BA2D0 Entry_guess::Initialize_guess
    void Initialize_guess(int value);
    // EXTERNAL: TITANIUM 0x005BA300 Entry_guess::Code_guess
    unsigned int Code_guess(const char* section, const char* text);
};

// EXTERNAL: TITANIUM 0x00401000 vector_constructor_iterator_guess
void __stdcall vector_constructor_iterator_guess(void* destination, unsigned int size, int count,
                                                 void (Entry_guess::*constructor)());

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message);

struct EntryPair_guess {
    Entry_guess first_guess[0x10b];
    Entry_guess second_guess[0x10b];

    void Reset_guess();
};

struct ErrorHandler_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 ErrorHandler_guess::Report_guess
    int Report_guess(int code, int detail);
};

struct StateConsumer_guess {
    int Apply_guess(float amount, int option);

    // EXTERNAL: TITANIUM 0x005E0620 StateConsumer_guess::CheckFirst_guess
    int CheckFirst_guess(int option);

    // EXTERNAL: TITANIUM 0x005E06A0 StateConsumer_guess::CheckSecond_guess
    int CheckSecond_guess(int option);

    // EXTERNAL: TITANIUM 0x005E0800 StateConsumer_guess::CheckThird_guess
    int CheckThird_guess(int option);

    // EXTERNAL: TITANIUM 0x005E1690 StateConsumer_guess::Process_guess
    int Process_guess(float amount, int option);
};

struct Counter_guess {
    // EXTERNAL: TITANIUM 0x005DFCE0 Counter_guess::Count_guess
    int Count_guess();

    int FormatMoneyText_guess(int unused, int multiplier);
};

// EXTERNAL: TITANIUM 0x005769E0 ParseBuffer_guess
int __cdecl ParseBuffer_guess(const char* input, char* output, int size, int option, int mode);

extern "C" long __cdecl strtol(const char* input, char** end, int radix);
// EXTERNAL: TITANIUM 0x0060E3A3 _atol
extern "C" long __cdecl atol(const char* input);

extern "C" double __cdecl atof(const char* input);

struct Callback_guess {
    void Dispatch_guess();

    // EXTERNAL: TITANIUM 0x005DFE50 Callback_guess::InitializeBuffer_guess
    void InitializeBuffer_guess(char* buffer);

    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(char* buffer);
};

struct Metadata_guess {
    char pad_guess[0x134];
    char type_guess;
    char pad2_guess[0x2f];
    int value_guess;
};

struct MetadataOwner_guess {
    char pad_guess[0x1c];
    Metadata_guess* metadata_guess;

    int GetContainerRestrictionId_guess();
};

// EXTERNAL: TITANIUM 0x0046DAAF CopperToMoneyText_guess
int __cdecl CopperToMoneyText_guess(int value);

#define g_errorHandler_guess EQ_GLOBAL(ErrorHandler_guess*, 0x00905CB0)

struct ErrorHandlerFull_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 ErrorHandlerFull_guess::Report_guess
    int Report_guess(int code, int unused, int width, int mode);
};

struct MessageWindow_guess {
    // EXTERNAL: TITANIUM 0x004982C6 MessageWindow_guess::Show_guess
    void Show_guess(int message);
    // EXTERNAL: TITANIUM 0x00498436 MessageWindow_guess::dsp_chat
    int dsp_chat(int message);
};

// EXTERNAL: TITANIUM 0x005E3EF0 QueryState_guess
int __stdcall QueryState_guess(char state, int value);

#define g_errorHandlerFull_guess EQ_GLOBAL(ErrorHandlerFull_guess*, 0x00905CB0)
#define g_messageWindow_guess EQ_GLOBAL(MessageWindow_guess*, 0x00988DF0)

struct Owned_guess {
    // EXTERNAL: TITANIUM 0x005D7230 Owned_guess::~Owned_guess
    ~Owned_guess();
};

// EXTERNAL: TITANIUM 0x005ACF60 ShouldCleanup_guess
int __cdecl ShouldCleanup_guess();

// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
void __cdecl operator delete(void* memory);

struct Key_guess {
    int code_guess; // 0x0

    // EXTERNAL: TITANIUM 0x005BA4B0 Key_guess::Key_guess
    Key_guess(int code);
    // EXTERNAL: TITANIUM 0x005BA250 Key_guess::Lookup_guess
    int Lookup_guess(int flag);
    // EXTERNAL: TITANIUM 0x005BA250 Key_guess::Current_guess
    int Current_guess();
};

struct KeyState_guess {
    // EXTERNAL: TITANIUM 0x005BA290 KeyState_guess::Matches_guess
    int Matches_guess(const Key_guess* key);
};

struct KeyObject_guess {
    // EXTERNAL: TITANIUM 0x005AE430 KeyObject_guess::Find_guess
    int Find_guess(int handle);
};

#define pinstCXWndManager_guess EQ_GLOBAL(KeyObject_guess*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x004619CD ExecuteCmd
void __cdecl ExecuteCmd(int index, int one, unsigned int flags);

struct Str_guess {
    char* data_guess; // 0x0

    Str_guess() : data_guess(0) {}
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& other);

    // EXTERNAL: TITANIUM 0x00572E00 Str_guess::Append_guess
    void Append_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00572C10 Str_guess::AppendText_guess
    void AppendText_guess(const Str_guess& text);
    // EXTERNAL: TITANIUM 0x005724C0 ??0Str_guess@@QAE@HHH@Z
    Str_guess(int value, int flag, int width);
    // EXTERNAL: TITANIUM 0x00572300 Str_guess::Get_guess
    const char* Get_guess() const;
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* data);

    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

// EXTERNAL: TITANIUM 0x00461992 GetMappableCommandName_guess
char* __cdecl GetMappableCommandName_guess(int key);

// EXTERNAL: TITANIUM 0x0049156D readKeyMapFromIni_guess
int __cdecl readKeyMapFromIni_guess(int key, int flag);

// EXTERNAL: TITANIUM 0x004914F6 ClearKeyMapIniEntry_guess
void __cdecl ClearKeyMapIniEntry_guess(int key, int flag);

struct ParseBlock_guess {
    char data_guess[0x2c4];

    // EXTERNAL: TITANIUM 0x00601F60 ParseBlock_guess::ParseBlock_guess
    ParseBlock_guess();

    // EXTERNAL: TITANIUM 0x00602030 ParseBlock_guess::Parse_guess
    void Parse_guess(char* input);
};

struct SettingsLoader_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual int Create_guess(char* input);

    char pad00_guess[0x18];
    int result_guess[10];
    long value48_guess;
    long value4c_guess;
    char pad50_guess[4];
    long value54_guess;
    long value58_guess;
    long value5c_guess;
    char enabled_guess;
    char pad61_guess[3];
    long value64_guess;
    long value68_guess;
    char pad6c_guess[4];
    double value70_guess;
    int value78_guess;
    long value7c_guess;
    __int64 value80_guess;
    long value88_guess;
    long value8c_guess;
    char pad90_guess[8];
    long value98_guess;
    long value9c_guess;
    long valuea0_guess;

    // EXTERNAL: TITANIUM 0x005EC620 SettingsLoader_guess::Install_guess
    void Install_guess(ParseBlock_guess* block);

    void Load_guess(const char* input);
};

// EXTERNAL: TITANIUM 0x00408E74 ParseBoolField_guess
int __cdecl ParseBoolField_guess(const char* input, void* output, int option);

// Reads the next field up to `option` (the separator) as a double; returns the characters used.
// FUNCTION: TITANIUM 0x004B1BBB
int __cdecl ParseNumericValue_guess(const char* input, double* output, int option) {
    char buffer[0x800];
    buffer[0] = '\0';
    int result = ParseBuffer_guess(input, buffer, 0x800, option, 1);
    *output = atof(buffer);
    return result;
}

// Fills a 0x7D00-byte buffer (0x005DFE50) and passes it to the object's virtual slot 6.
// FUNCTION: TITANIUM 0x004B1C10
void Callback_guess::Dispatch_guess() {
    char buffer[0x7d00];
    this->InitializeBuffer_guess(buffer);
    Slot06_guess(buffer);
}

// Container restriction label for type-'6' item data: string 9134 "Armor Only" onward by restriction, 0 for
// none.
// FUNCTION: TITANIUM 0x004B1C4D
int MetadataOwner_guess::GetContainerRestrictionId_guess() {
    if (metadata_guess->type_guess == '6') {
        switch (metadata_guess->value_guess) {
        case 0:
            return 0;
        case 1:
            return 0x23ae;
        case 2:
            return 0x23af;
        case 3:
            return 0x23b0;
        case 4:
            return 0x23b1;
        case 5:
            return 0x23b2;
        case 6:
            return 0x23b3;
        case 7:
            return 0x23b4;
        case 8:
            return 0x23bc;
        case 9:
            return 0x23b5;
        case 10:
            return 0x23b6;
        case 11:
            return 0x23b7;
        case 12:
            return 0x23b8;
        case 13:
            return 0x23b9;
        }
    }
    return 0;
}

// Sets the flag at +0x90 when it is 0; true when it changed.
// FUNCTION: TITANIUM 0x004B1CF4
bool StateFlag_guess::SetOpen_guess() {
    if (value_guess == 0) {
        value_guess = 1;
        return true;
    }
    return false;
}

// Clears the flag at +0x90 when it is 1; true when it changed.
// FUNCTION: TITANIUM 0x004B1D0B
bool StateFlag_guess::ClearOpen_guess() {
    if (value_guess == 1) {
        value_guess = 0;
        return true;
    }
    return false;
}

// Money text for `amount` when all three checks pass, else string 2408 " absolutely nothing".
// FUNCTION: TITANIUM 0x004B1D1F
int StateConsumer_guess::Apply_guess(float amount, int option) {
    if (CheckFirst_guess(1) != 0 && CheckSecond_guess(1) != 0 && CheckThird_guess(1) > 0) {
        return CopperToMoneyText_guess(Process_guess(amount, option));
    }
    return g_errorHandler_guess->Report_guess(0x968, 0);
}

// Money text for count x `multiplier`, or string 2413 when the count is 0 or less.
// FUNCTION: TITANIUM 0x004B1D79
int Counter_guess::FormatMoneyText_guess(int unused, int multiplier) {
    if (Count_guess() <= 0) {
        return g_errorHandler_guess->Report_guess(0x96d, 0);
    }
    return CopperToMoneyText_guess(Count_guess() * multiplier);
}

struct EventData_guess {
    char pad_guess[0xd5];
    char modeA_guess;
    char pad2_guess[0xc2];
    char primary_guess[0xb4];
    char mode_guess;
    char state_guess;
    char secondary_guess[1];
};

struct EventOwner_guess {
    char pad_guess[0x1c];
    EventData_guess* data_guess;

    // EXTERNAL: TITANIUM 0x005ECCC0 EventOwner_guess::GetItemClass_guess
    int GetItemClass_guess();

    // EXTERNAL: TITANIUM 0x005E0E30 EventOwner_guess::State_guess
    char State_guess();

    void SendReadBook_guess(char action);
};


struct EventMessage_guess {
    char action_guess;
    char state_guess;
    char text_guess[0x3fe];
};

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source);

extern "C" unsigned int __cdecl strlen(const char* text);

// Sends OP_ReadBook: `action`, a state byte (0 or 1 in mode 2, else 2) and the NUL-terminated book text
// name. In mode 2 it first closes the note window (0x850BA4, state 0) or the book window (0x850BA8, state
// 1) and sends only when that window's handler succeeds.
// FUNCTION: TITANIUM 0x004B1DB0
// @early-stop: budget, diff ndiff=8
void EventOwner_guess::SendReadBook_guess(char action) {
    EventMessage_guess message;
    message.action_guess = action;
    char success;
    unsigned int length;

    if (GetItemClass_guess() == 2 && State_guess() == 0) {
        message.state_guess = State_guess();
        pinstCNoteWnd_guess->Deactivate();
        success = pinstCNoteWnd_guess->SetId_guess(this);
        CopyText_guess(message.text_guess, data_guess->secondary_guess);
        length = strlen(data_guess->secondary_guess);
    } else if (GetItemClass_guess() == 2 && State_guess() == 1) {
        message.state_guess = State_guess();
        pinstCBookWnd_guess->Deactivate();
        success = pinstCBookWnd_guess->SelectBook_guess(this);
        CopyText_guess(message.text_guess, data_guess->secondary_guess);
        length = strlen(data_guess->secondary_guess);
    } else {
        if (data_guess->primary_guess[0] == 0) {
            return;
        }
        message.state_guess = 2;
        CopyText_guess(message.text_guess, data_guess->primary_guess);
        length = strlen(data_guess->primary_guess);
        success = 1;
    }

    char* end = &message.text_guess[length];
    *end++ = 0;
    if (success != 0) {
        char* start = &message.action_guess;
        EQSendMessage(&EQ_GLOBAL(int, 0x00905CA0), OP_ReadBook, start, end - start, 1);
    }
}

// Item move check; failure shows string 12921 or 12922 (no-drop item, or a container holding one). A `value`
// of 0 or 666 (0x29A) skips the message.
// FUNCTION: TITANIUM 0x004B1EE3
char __stdcall CanDrop_guess(int value) {
    int zero = 0;
    char state;
    if (EQ_GLOBAL(int, 0x00923D5C) != 0) {
        state = 1;
    } else {
        state = (char)zero;
        if (EQ_GLOBAL(int, 0x00923D58) == 6) {
            state = 1;
        }
    }

    int result = QueryState_guess(state, value);
    switch (result - zero) {
    default:
        return (char)zero;
    case 2:
        if (value == zero || value == 0x29a) {
            return (char)zero;
        }
        g_messageWindow_guess->Show_guess(g_errorHandlerFull_guess->Report_guess(0x327a, zero, 0xf, 1));
        return (char)zero;
    case 1:
        if (value == zero || value == 0x29a) {
            return (char)zero;
        }
        g_messageWindow_guess->Show_guess(g_errorHandlerFull_guess->Report_guess(0x3279, zero, 0xf, 1));
        return (char)zero;
    case 0:
        return 1;
    }
}

struct ItemListBase_guess {
    // EXTERNAL: TITANIUM 0x005EC720 ItemListBase_guess::~ItemListBase_guess
    virtual ~ItemListBase_guess();
    // EXTERNAL: TITANIUM 0x005ECE20 ItemListBase_guess::ItemListBase_guess
    ItemListBase_guess();
    // EXTERNAL: TITANIUM 0x005ECE60 ItemListBase_guess::GetState_guess
    int GetState_guess(int value);
    char pad_004[0x18];
    Owned_guess* owned_guess; // 0x1c
    char pad_020[0x28];
    int field_48_guess; // 0x48
    char pad_04c[0x5c];
};

// EXTERNAL: TITANIUM 0x00644780 ??_7EQ_Item_guess@@6B@
struct EQ_Item_guess : ItemListBase_guess {
    virtual ~EQ_Item_guess();
    // EXTERNAL: TITANIUM 0x004B212A EQ_Item_guess::Load_guess
    void Load_guess(int arg);
    // EXTERNAL: TITANIUM 0x005EC690 EQ_Item_guess::Ready_guess
    bool Ready_guess();
    // EXTERNAL: TITANIUM 0x005EC760 EQ_Item_guess::IsStackable_guess
    bool IsStackable_guess();
    int CanPlaceInContainer_guess(int value, int option);
};

// Container placement check: 1 when allowed, else shows the reason, strings 12933-12936 (containers in
// containers, too big, quiver arrows only, bandolier ammo only).
// FUNCTION: TITANIUM 0x004B1F6C
// @early-stop: budget, structural ndiff=23
int EQ_Item_guess::CanPlaceInContainer_guess(int value, int option) {
    int result;
    int message = 0;
    result = GetState_guess(value);

    switch (result) {
    case 1:
        return 1;
    case 2:
        message = 0x3285;
        result = 0;
        break;
    case 3:
        message = 0x3286;
        result = 0;
        break;
    case 4:
        message = 0x3287;
        result = 0;
        break;
    case 5:
        message = 0x3288;
        result = 0;
        break;
    default:
        result -= 5;
        break;
    }

    if (option != 0 && message != 0) {
        result = g_messageWindow_guess->dsp_chat(g_errorHandler_guess->Report_guess(message, 0));
    }
    return result & 0xffffff00;
}

// Reads the next field as an integer, hex when it starts with "0x"; stored as 64-bit but parsed with
// strtol/atol, so values above 32 bits are lost.
// FUNCTION: TITANIUM 0x004B1FD5
int __cdecl ParseInt64_guess(const char* input, __int64* output, int option) {
    char buffer[0x800];
    buffer[0] = '\0';
    int result = ParseBuffer_guess(input, buffer, 0x800, option, 1);
    long value;
    if (buffer[0] == '0' && buffer[1] == 'x') {
        value = strtol(buffer, 0, 0x10);
    } else {
        value = atol(buffer);
    }
    *output = value;
    return result;
}

// Reads the next field of `input` up to the delimiter `option` (callers pass '|') through 0x005769E0 and
// stores it as a long: hex after a leading "0x", else decimal. Returns the chars consumed, so the caller
// can step its cursor.
// FUNCTION: TITANIUM 0x004B2056
int __cdecl ParseLong_guess(const char* input, long* output, int option) {
    char buffer[0x800];
    buffer[0] = '\0';
    int result = ParseBuffer_guess(input, buffer, 0x800, option, 1);
    long value;
    if (buffer[0] == '0' && buffer[1] == 'x') {
        value = strtol(buffer, 0, 0x10);
    } else {
        value = atol(buffer);
    }
    *output = value;
    return result;
}

// Item destructor (vtable 0x00644780): deletes the owned object at +0x1C (0x005D7230), if any, then
// runs the base destructor (0x005EC720). 0x005ACF60 only reads that pointer.
// FUNCTION: TITANIUM 0x004B20D3
EQ_Item_guess::~EQ_Item_guess() {
    if (ShouldCleanup_guess()) {
        delete owned_guess;
        owned_guess = 0;
    }
}

// Parses a '|'-separated text record (probably the item record) into the object's fields; the second block is
// read only when its flag field is set.
// FUNCTION: TITANIUM 0x004B212A
void SettingsLoader_guess::Load_guess(const char* input) {
    char buffer[10000];
    const char* cursor = input;

    cursor += ParseLong_guess(cursor, &value48_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value7c_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value4c_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value88_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value8c_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value98_guess, 0x7c);
    cursor += ParseInt64_guess(cursor, &value80_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value54_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value58_guess, 0x7c);
    cursor += ParseLong_guess(cursor, &value5c_guess, 0x7c);
    cursor += ParseBoolField_guess(cursor, &enabled_guess, 0x7c);

    if (enabled_guess != 0) {
        cursor += ParseLong_guess(cursor, &value64_guess, 0x7c);
        cursor += ParseLong_guess(cursor, &value68_guess, 0x7c);
        cursor += ParseNumericValue_guess(cursor, &value70_guess, 0x7c);
        cursor += ParseBoolField_guess(cursor, &value78_guess, 0x7c);
        cursor += ParseLong_guess(cursor, &value9c_guess, 0x7c);
        cursor += ParseLong_guess(cursor, &valuea0_guess, 0x7c);
    }

    ParseBlock_guess* block = new ParseBlock_guess;
    cursor += ParseBuffer_guess(cursor, buffer, 10000, 0x7c, 1);
    block->Parse_guess(buffer);
    Install_guess(block);

    for (int index = 0; index < 10; ++index) {
        result_guess[index] = 0;
        cursor += ParseBuffer_guess(cursor, buffer, 10000, 0x7c, 1);
        if (buffer[0] != 0) {
            result_guess[index] = Create_guess(buffer);
        }
    }
}

// Builds the object from its text record; returns 0 when it does not parse. A valid one with count 0 gets
// count 1.
// FUNCTION: TITANIUM 0x004B232E
EQ_Item_guess* CreateItemList_guess(int arg) {
    if (arg != 0) {
        EQ_Item_guess* list = new EQ_Item_guess;
        list->Load_guess(arg);
        if (list != 0) {
            if (list->Ready_guess()) {
                if (list->IsStackable_guess() && list->field_48_guess <= 0) {
                    list->field_48_guess = 1;
                }
                return list;
            }
            delete list;
        }
    }
    return 0;
}

// Keys that cannot be bound: both Shift, Ctrl, Alt and Windows keys, Enter, '/', and two shifted combos
// (0x1000001C Shift+Enter, 0x1000000F Shift+Tab).
// FUNCTION: TITANIUM 0x004B2467
bool __stdcall IsUnbindableKey_guess(KeyState_guess* state) {
    static Key_guess keys[12] = {0x2a, 0x36, 0x1d, 0x9d, 0x38, 0xb8, 0xdb, 0xdc, 0x1c, 0x35, 0x1000001c, 0x1000000f};
    bool found = false;
    for (Key_guess* key = keys; (int)key < (int)(keys + 12); ++key) {
        if (state->Matches_guess(key)) {
            found = true;
            break;
        }
    }
    return found;
}

// INI key name "KEYMAPPING_<command>_<index+1>".
// FUNCTION: TITANIUM 0x004B2565
Str_guess __stdcall KeyMappingName_guess(int key, int index) {
    Str_guess text;
    text.Append_guess("KEYMAPPING_");
    text.Append_guess(GetMappableCommandName_guess(key));
    text.Append_guess(EQ_ARRAY(char, 0x0063FE48));
    text.AppendText_guess(Str_guess(index + 1, 1, 0x20));
    return text;
}

// Address of command `index`'s primary key in the key map (+0, one per command).
// FUNCTION: TITANIUM 0x004B244F
int* PointerTable_guess::First_guess(int index) {
    return &first_guess[index];
}

// Address of command `index`'s alternate key in the key map (+0x42C, after the 0x10B primary keys).
// FUNCTION: TITANIUM 0x004B2459
int* PointerTable_guess::Second_guess(int index) {
    return &second_guess[index];
}

// Clears both binding tables (primary and alternate, 0x10B each).
// FUNCTION: TITANIUM 0x004B2613
void EntryPair_guess::Reset_guess() {
    Entry_guess* entry = first_guess;
    int count = 0x10b;
    do {
        entry->Initialize_guess(0);
        (entry + 0x10b)->Initialize_guess(0);
        ++entry;
        --count;
    } while (count != 0);
}

#define g_keyMapMode_guess EQ_GLOBAL(int, 0x00923D74)

#pragma pack(push, 1)
struct KeyMap_guess {
    int slot_guess[0x216];      // 0x0 .. 0x858
    char pressed_guess[0x10b]; // 0x858

    KeyMap_guess();
    void LoadAll_guess();
    void Init_guess();
    bool AttachKeyToEqCommand(int* source, int index);
    bool AttachAltKeyToEqCommand(int* source, int index);
    bool HandleKeyDown(Key_guess* key);
    bool HandleKeyUp(Key_guess* key);
};
#pragma pack(pop)

// Runs every command bound (primary or alternate) to `key` that is not already down; true when the key was
// used.
// FUNCTION: TITANIUM 0x004B23C4
bool KeyMap_guess::HandleKeyDown(Key_guess* key) {
    bool pressed = false;
    if (pinstCXWndManager_guess->Find_guess(key->Lookup_guess(1)) != 0) {
        for (int pass = 0; pass < 2; ++pass) {
            for (int index = 0; index < 0x10b; ++index) {
                if (((KeyState_guess*)&slot_guess[pass * 0x10b + index])->Matches_guess(key) != 0 &&
                    pressed_guess[index] == 0) {
                    ExecuteCmd(index, 1, 0);
                    pressed_guess[index] = 1;
                    pressed = true;
                }
            }
        }
    } else {
        pressed = true;
    }
    return pressed;
}

// Releases every down command bound to `key`'s base key, ignoring modifiers, so a release always ends the
// command.
// FUNCTION: TITANIUM 0x004B263B
// @early-stop: budget, diff ndiff=2
bool KeyMap_guess::HandleKeyUp(Key_guess* key) {
    bool state_guess = false;
    bool reset_guess = false;
    if (pinstCXWndManager_guess->Find_guess(key->Lookup_guess(0)) == 0) {
        state_guess = true;
    }

    unsigned int index_guess = 0;
    int* current_slot_guess = this->slot_guess;
    for (; index_guess < 0x10b; ++index_guess, ++current_slot_guess) {
        if (pressed_guess[index_guess] == 1) {
            Key_guess* key_slot_guess = (Key_guess*)current_slot_guess;
            if (key_slot_guess->Current_guess() == key->Current_guess() ||
                key->Current_guess() == ((Key_guess*)(current_slot_guess + 0x10b))->Current_guess()) {
                ExecuteCmd(index_guess, 0, 0);
                pressed_guess[index_guess] = 0;
                reset_guess = true;
            }
        }
    }
    return state_guess || reset_guess;
}

// The built-in default bindings, one per command slot: DirectInput scan codes,
// with bit 30 (0x40000000) for Shift, 29 for Ctrl and 28 for Alt.
// FUNCTION: TITANIUM 0x004B26F0
void KeyMap_guess::Init_guess() {
    // Default key bindings. slot_guess[n] is command n's primary key and slot_guess[0x10B + n] its alternate
    // (the two passes the key lookup above walks). Codes are DirectInput scan codes (0x39 space, 0x48 up,
    // 0x50 down, 0x4B left, 0x4D right) with modifier flags in bits 28-30 (Alt, Ctrl, Shift).
    ((EntryPair_guess*)this)->Reset_guess();
    {
        Key_guess key(0x45);
        slot_guess[0] = key.code_guess;
    }
    {
        Key_guess key(0x39);
        slot_guess[1] = key.code_guess;
    }
    {
        Key_guess key(0x48);
        slot_guess[2] = key.code_guess;
    }
    {
        Key_guess key(0x50);
        slot_guess[3] = key.code_guess;
    }
    {
        Key_guess key(0x4d);
        slot_guess[4] = key.code_guess;
    }
    {
        Key_guess key(0x4b);
        slot_guess[5] = key.code_guess;
    }
    {
        Key_guess key(0x58);
        slot_guess[8] = key.code_guess;
    }
    {
        Key_guess key(200);
        slot_guess[269] = key.code_guess;
    }
    {
        Key_guess key(0xd0);
        slot_guess[270] = key.code_guess;
    }
    {
        Key_guess key(0xcb);
        slot_guess[272] = key.code_guess;
    }
    {
        Key_guess key(0xcd);
        slot_guess[271] = key.code_guess;
    }
    {
        Key_guess key(0x10);
        slot_guess[10] = key.code_guess;
    }
    {
        Key_guess key(0x2e);
        slot_guess[11] = key.code_guess;
    }
    {
        Key_guess key(0x20);
        slot_guess[12] = key.code_guess;
    }
    {
        Key_guess key(0x23);
        slot_guess[13] = key.code_guess;
    }
    {
        Key_guess key(0x17);
        slot_guess[14] = key.code_guess;
    }
    {
        Key_guess key(0x14);
        slot_guess[15] = key.code_guess;
    }
    {
        Key_guess key(0x16);
        slot_guess[16] = key.code_guess;
    }
    {
        Key_guess key(0x20000002);
        slot_guess[204] = key.code_guess;
    }
    {
        Key_guess key(0x20000003);
        slot_guess[205] = key.code_guess;
    }
    {
        Key_guess key(0x20000004);
        slot_guess[206] = key.code_guess;
    }
    {
        Key_guess key(0x20000005);
        slot_guess[207] = key.code_guess;
    }
    {
        Key_guess key(0x20000006);
        slot_guess[208] = key.code_guess;
    }
    {
        Key_guess key(0x20000007);
        slot_guess[209] = key.code_guess;
    }
    {
        Key_guess key(0x20000008);
        slot_guess[210] = key.code_guess;
    }
    {
        Key_guess key(0x20000009);
        slot_guess[211] = key.code_guess;
    }
    {
        Key_guess key(0x2000001e);
        slot_guess[130] = key.code_guess;
    }
    {
        Key_guess key(0x20000030);
        slot_guess[129] = key.code_guess;
    }
    {
        Key_guess key(0x2000002e);
        slot_guess[131] = key.code_guess;
    }
    {
        Key_guess key(0x20000018);
        slot_guess[132] = key.code_guess;
    }
    {
        Key_guess key(0x20000032);
        slot_guess[133] = key.code_guess;
    }
    {
        Key_guess key(0x20000011);
        slot_guess[134] = key.code_guess;
    }
    {
        Key_guess key(0x20000017);
        slot_guess[135] = key.code_guess;
    }
    {
        Key_guess key(0x20000020);
        slot_guess[136] = key.code_guess;
    }
    {
        Key_guess key(0x2000002d);
        slot_guess[137] = key.code_guess;
    }
    {
        Key_guess key(0x2000001f);
        slot_guess[138] = key.code_guess;
    }
    {
        Key_guess key(0x20000013);
        slot_guess[139] = key.code_guess;
    }
    {
        Key_guess key(0x28);
        slot_guess[148] = key.code_guess;
    }
    {
        Key_guess key(0x40000027);
        slot_guess[149] = key.code_guess;
    }
    {
        Key_guess key(0x27);
        slot_guess[249] = key.code_guess;
    }
    {
        Key_guess key(0x4000000c);
        slot_guess[140] = key.code_guess;
    }
    {
        Key_guess key(0x4000000d);
        slot_guess[141] = key.code_guess;
    }
    {
        Key_guess key(0x49);
        slot_guess[17] = key.code_guess;
    }
    {
        Key_guess key(0x51);
        slot_guess[18] = key.code_guess;
    }
    {
        Key_guess key(0x4c);
        slot_guess[19] = key.code_guess;
    }
    {
        Key_guess key(0x47);
        slot_guess[20] = key.code_guess;
    }
    {
        Key_guess key(0x4f);
        slot_guess[21] = key.code_guess;
    }
    {
        Key_guess key(0x43);
        slot_guess[22] = key.code_guess;
    }
    {
        Key_guess key(0x44);
        slot_guess[23] = key.code_guess;
    }
    {
        Key_guess key(0x50000013);
        slot_guess[185] = key.code_guess;
    }
    {
        Key_guess key(0x1000001c);
        slot_guess[257] = key.code_guess;
    }
    {
        Key_guess key(0xc9);
        slot_guess[284] = key.code_guess;
    }
    {
        Key_guess key(0xd1);
        slot_guess[285] = key.code_guess;
    }
    {
        Key_guess key(199);
        slot_guess[286] = key.code_guess;
    }
    {
        Key_guess key(0xd2);
        slot_guess[287] = key.code_guess;
    }
    {
        Key_guess key(0xd3);
        slot_guess[288] = key.code_guess;
    }
    {
        Key_guess key(0x10000048);
        slot_guess[177] = key.code_guess;
    }
    {
        Key_guess key(0x10000050);
        slot_guess[178] = key.code_guess;
    }
    {
        Key_guess key(0x1000004d);
        slot_guess[179] = key.code_guess;
    }
    {
        Key_guess key(0x1000004b);
        slot_guess[180] = key.code_guess;
    }
    {
        Key_guess key(0x10000049);
        slot_guess[181] = key.code_guess;
    }
    {
        Key_guess key(0x10000051);
        slot_guess[182] = key.code_guess;
    }
    {
        Key_guess key(0x100000c8);
        slot_guess[444] = key.code_guess;
    }
    {
        Key_guess key(0x100000d0);
        slot_guess[445] = key.code_guess;
    }
    {
        Key_guess key(0x100000cd);
        slot_guess[446] = key.code_guess;
    }
    {
        Key_guess key(0x100000cb);
        slot_guess[447] = key.code_guess;
    }
    {
        Key_guess key(0x100000c9);
        slot_guess[448] = key.code_guess;
    }
    {
        Key_guess key(0x100000d1);
        slot_guess[449] = key.code_guess;
    }
    {
        Key_guess key(0x3b);
        slot_guess[24] = key.code_guess;
    }
    {
        Key_guess key(0x3c);
        slot_guess[25] = key.code_guess;
    }
    {
        Key_guess key(0x3d);
        slot_guess[26] = key.code_guess;
    }
    {
        Key_guess key(0x3e);
        slot_guess[27] = key.code_guess;
    }
    {
        Key_guess key(0x3f);
        slot_guess[28] = key.code_guess;
    }
    {
        Key_guess key(0x40);
        slot_guess[29] = key.code_guess;
    }
    {
        Key_guess key(0x41);
        slot_guess[30] = key.code_guess;
    }
    {
        Key_guess key(0x42);
        slot_guess[32] = key.code_guess;
    }
    {
        Key_guess key(0x29);
        slot_guess[299] = key.code_guess;
    }
    {
        Key_guess key(2);
        slot_guess[35] = key.code_guess;
    }
    {
        Key_guess key(3);
        slot_guess[36] = key.code_guess;
    }
    {
        Key_guess key(4);
        slot_guess[37] = key.code_guess;
    }
    {
        Key_guess key(5);
        slot_guess[38] = key.code_guess;
    }
    {
        Key_guess key(6);
        slot_guess[39] = key.code_guess;
    }
    {
        Key_guess key(7);
        slot_guess[40] = key.code_guess;
    }
    {
        Key_guess key(8);
        slot_guess[41] = key.code_guess;
    }
    {
        Key_guess key(9);
        slot_guess[42] = key.code_guess;
    }
    {
        Key_guess key(10);
        slot_guess[43] = key.code_guess;
    }
    {
        Key_guess key(0xb);
        slot_guess[44] = key.code_guess;
    }
    {
        Key_guess key(0x40000002);
        slot_guess[75] = key.code_guess;
    }
    {
        Key_guess key(0x40000003);
        slot_guess[76] = key.code_guess;
    }
    {
        Key_guess key(0x40000004);
        slot_guess[77] = key.code_guess;
    }
    {
        Key_guess key(0x40000005);
        slot_guess[78] = key.code_guess;
    }
    {
        Key_guess key(0x40000006);
        slot_guess[79] = key.code_guess;
    }
    {
        Key_guess key(0x40000007);
        slot_guess[80] = key.code_guess;
    }
    {
        Key_guess key(0x40000008);
        slot_guess[81] = key.code_guess;
    }
    {
        Key_guess key(0x40000009);
        slot_guess[82] = key.code_guess;
    }
    {
        Key_guess key(0x4000000a);
        slot_guess[83] = key.code_guess;
    }
    {
        Key_guess key(0x4000000b);
        slot_guess[84] = key.code_guess;
    }
    {
        Key_guess key(0x10000002);
        slot_guess[115] = key.code_guess;
    }
    {
        Key_guess key(0x10000003);
        slot_guess[116] = key.code_guess;
    }
    {
        Key_guess key(0x10000004);
        slot_guess[117] = key.code_guess;
    }
    {
        Key_guess key(0x10000005);
        slot_guess[118] = key.code_guess;
    }
    {
        Key_guess key(0x10000006);
        slot_guess[119] = key.code_guess;
    }
    {
        Key_guess key(0x10000007);
        slot_guess[120] = key.code_guess;
    }
    {
        Key_guess key(0x10000008);
        slot_guess[121] = key.code_guess;
    }
    {
        Key_guess key(0x10000009);
        slot_guess[122] = key.code_guess;
    }
    {
        Key_guess key(0x1000000a);
        slot_guess[123] = key.code_guess;
    }
    {
        Key_guess key(0x4000001f);
        slot_guess[217] = key.code_guess;
    }
    {
        Key_guess key(0x1c);
        slot_guess[256] = key.code_guess;
    }
    {
        Key_guess key(0x40000048);
        slot_guess[144] = key.code_guess;
    }
    {
        Key_guess key(0x40000050);
        slot_guess[145] = key.code_guess;
    }
    {
        Key_guess key(0x400000c8);
        slot_guess[411] = key.code_guess;
    }
    {
        Key_guess key(0x400000d0);
        slot_guess[412] = key.code_guess;
    }
    {
        Key_guess key(0x40000049);
        slot_guess[146] = key.code_guess;
    }
    {
        Key_guess key(0x40000051);
        slot_guess[147] = key.code_guess;
    }
    {
        Key_guess key(0x400000c9);
        slot_guess[413] = key.code_guess;
    }
    {
        Key_guess key(0x400000d1);
        slot_guess[414] = key.code_guess;
    }
    {
        Key_guess key(0x13);
        slot_guess[124] = key.code_guess;
    }
    {
        Key_guess key(0xf);
        slot_guess[125] = key.code_guess;
    }
    {
        Key_guess key(0x4000000f);
        slot_guess[126] = key.code_guess;
    }
    {
        Key_guess key(0x20000014);
        slot_guess[166] = key.code_guess;
    }
    {
        Key_guess key(0x35);
        slot_guess[250] = key.code_guess;
    }
    {
        Key_guess key(0x57);
        slot_guess[34] = key.code_guess;
    }
    {
        Key_guess key(0x4a);
        slot_guess[143] = key.code_guess;
    }
    {
        Key_guess key(0x4e);
        slot_guess[142] = key.code_guess;
    }
    {
        Key_guess key(0xf);
        slot_guess[128] = key.code_guess;
    }
    {
        Key_guess key(0x1000001e);
        slot_guess[173] = key.code_guess;
    }
    {
        Key_guess key(0x10000030);
        slot_guess[155] = key.code_guess;
    }
    {
        Key_guess key(0x1000002e);
        slot_guess[212] = key.code_guess;
    }
    {
        Key_guess key(0x10000020);
        slot_guess[174] = key.code_guess;
    }
    {
        Key_guess key(0x10000012);
        slot_guess[184] = key.code_guess;
    }
    {
        Key_guess key(0x10000021);
        slot_guess[167] = key.code_guess;
    }
    {
        Key_guess key(0x10000022);
        slot_guess[188] = key.code_guess;
    }
    {
        Key_guess key(0x10000023);
        slot_guess[156] = key.code_guess;
    }
    {
        Key_guess key(0x10000017);
        slot_guess[165] = key.code_guess;
    }
    {
        Key_guess key(0x10000024);
        slot_guess[183] = key.code_guess;
    }
    {
        Key_guess key(0x10000025);
        slot_guess[176] = key.code_guess;
    }
    {
        Key_guess key(0x10000026);
        slot_guess[150] = key.code_guess;
    }
    {
        Key_guess key(0x10000032);
        slot_guess[163] = key.code_guess;
    }
    {
        Key_guess key(0x10000031);
        slot_guess[186] = key.code_guess;
    }
    {
        Key_guess key(0x10000018);
        slot_guess[169] = key.code_guess;
    }
    {
        Key_guess key(0x10000019);
        slot_guess[152] = key.code_guess;
    }
    {
        Key_guess key(0x10000010);
        slot_guess[215] = key.code_guess;
    }
    {
        Key_guess key(0x10000013);
        slot_guess[175] = key.code_guess;
    }
    {
        Key_guess key(0x1000001f);
        slot_guess[154] = key.code_guess;
    }
    {
        Key_guess key(0x10000014);
        slot_guess[153] = key.code_guess;
    }
    {
        Key_guess key(0x10000016);
        slot_guess[203] = key.code_guess;
    }
    {
        Key_guess key(0x1000002f);
        slot_guess[198] = key.code_guess;
    }
    {
        Key_guess key(0x10000011);
        slot_guess[171] = key.code_guess;
    }
    {
        Key_guess key(0x10000015);
        slot_guess[151] = key.code_guess;
    }
    {
        Key_guess key(0x1000002c);
        slot_guess[213] = key.code_guess;
    }
    {
        Key_guess key(0x1000003b);
        slot_guess[168] = key.code_guess;
    }
    {
        Key_guess key(0x20000021);
        slot_guess[201] = key.code_guess;
    }
    {
        Key_guess key(0x20000019);
        slot_guess[214] = key.code_guess;
    }
    {
        Key_guess key(0x20000012);
        slot_guess[161] = key.code_guess;
    }
    {
        Key_guess key(0x20000031);
        slot_guess[162] = key.code_guess;
    }
    {
        Key_guess key(0x2000002f);
        slot_guess[218] = key.code_guess;
    }
    {
        Key_guess key(0x40000014);
        slot_guess[219] = key.code_guess;
    }
    {
        Key_guess key(0x26);
        slot_guess[202] = key.code_guess;
    }
    {
        Key_guess key(0x19);
        slot_guess[216] = key.code_guess;
    }
    {
        Key_guess key(0x2f);
        slot_guess[164] = key.code_guess;
    }
    {
        Key_guess key(0xe);
        slot_guess[187] = key.code_guess;
    }
    {
        Key_guess key(0x32);
        slot_guess[454] = key.code_guess;
    }
    {
        Key_guess key(1);
        slot_guess[199] = key.code_guess;
    }
    {
        Key_guess key(1);
        slot_guess[200] = key.code_guess;
    }
    {
        Key_guess key(0x30);
        slot_guess[225] = key.code_guess;
    }
    {
        Key_guess key(0x40000019);
        slot_guess[224] = key.code_guess;
    }
    {
        Key_guess key(0xd0);
        slot_guess[261] = key.code_guess;
    }
    {
        Key_guess key(200);
        slot_guess[262] = key.code_guess;
    }
    {
        Key_guess key(1);
        slot_guess[263] = key.code_guess;
    }
    {
        Key_guess key(0x1c);
        slot_guess[264] = key.code_guess;
    }
    {
        Key_guess key(0x9c);
        slot_guess[531] = key.code_guess;
    }
    {
        Key_guess key(1);
        slot_guess[266] = key.code_guess;
    }
    {
        Key_guess key(0x21);
        slot_guess[232] = key.code_guess;
    }
    {
        Key_guess key(0x30000021);
        slot_guess[246] = key.code_guess;
    }
    {
        Key_guess key(0x2c);
        slot_guess[233] = key.code_guess;
    }
    {
        Key_guess key(0x22);
        slot_guess[234] = key.code_guess;
    }
    {
        Key_guess key(0x1000002d);
        slot_guess[238] = key.code_guess;
    }
    // Keyboard mode 3 (0x00923D74) moves three bindings: command 148 to key 0x92, 140 and 141 to
    // Shift+0x1A / Shift+0x1B. Language 3 is Japanese (font tag "jp", code page 932); 0x92 is the
    // Japanese keyboard's colon key.
    if (g_keyMapMode_guess == 3) {
        {
            Key_guess key(0x92);
            slot_guess[148] = key.code_guess;
        }
        {
            Key_guess key(0x4000001a);
            slot_guess[140] = key.code_guess;
        }
        {
            Key_guess key(0x4000001b);
            slot_guess[141] = key.code_guess;
        }
    }
}

// Clears the 0x10B per-command bytes at +0x858 of the key map; the game loop does it after flushing the
// mouse and keyboard.
// FUNCTION: TITANIUM 0x004B3569
void ResetBlock_guess::Reset_guess() {
    unsigned int count = 0x10b;
    char* p = data_guess;
    while (count != 0) {
        *p++ = 0;
        --count;
    }
}

struct KeyDispatcher_guess {
    // EXTERNAL: TITANIUM 0x004AE514 KeyDispatcher_guess::Apply_guess
    void Apply_guess(int code);
    // EXTERNAL: TITANIUM 0x004AE7C4 KeyDispatcher_guess::Note_guess
    void Note_guess(const char* section, const char* text);
};
#define g_keyDispatcher_guess EQ_GLOBAL(KeyDispatcher_guess*, 0x00988DF0)

struct IniConfig_guess {
    // EXTERNAL: TITANIUM 0x004AE64C IniConfig_guess::ReadClientIniInt_guess
    int ReadClientIniInt_guess(const char* section, const char* key, int defaultValue);
};
#define g_iniConfig_guess EQ_GLOBAL(IniConfig_guess*, 0x00988DF0)

struct KeyMapStore_guess {
    char Bind_guess(int key, int mode, Entry_guess* entry);
    void SaveKeymapping(int key, Entry_guess* entry, int index);
    void Note_guess(int key, int index);
    void NoteAll_guess();
    bool Load_guess(int key, int index, Entry_guess* entry);
};

// Reads the binding for command `key` from KeyMaps; false when absent (-1).
// FUNCTION: TITANIUM 0x004B357C
bool KeyMapStore_guess::Load_guess(int key, int index, Entry_guess* entry) {
    bool result = false;
    int value = g_iniConfig_guess->ReadClientIniInt_guess("KeyMaps", KeyMappingName_guess(key, index).Get_guess(), -1);
    if (value != -1) {
        entry->Initialize_guess(value);
        result = true;
    }
    return result;
}

// Writes key binding `entry` (its code, 0x005BA300) to eqclient.ini [KeyMaps] as
// KEYMAPPING_<command>_<index+1> (0x004AE514).
// FUNCTION: TITANIUM 0x004B35F1
void KeyMapStore_guess::SaveKeymapping(int key, Entry_guess* entry, int index) {
    g_keyDispatcher_guess->Apply_guess(entry->Code_guess("KeyMaps", KeyMappingName_guess(key, index).Get_guess()));
}

// Deletes KEYMAPPING_<command>_<index+1> from eqclient.ini [KeyMaps] (0x004AE7C4).
// FUNCTION: TITANIUM 0x004B3652
void KeyMapStore_guess::Note_guess(int key, int index) {
    g_keyDispatcher_guess->Note_guess("KeyMaps", KeyMappingName_guess(key, index).Get_guess());
}

// Takes a binding from the older key-map INI entry (readKeyMapFromIni_guess), clears that entry and saves it
// in the new KeyMaps format; -1 there means unbound.
// FUNCTION: TITANIUM 0x004B36AA
char KeyMapStore_guess::Bind_guess(int key, int mode, Entry_guess* entry) {
    char result = 0;
    bool flag = mode == 1;
    int value = readKeyMapFromIni_guess(key, flag);
    if (value > 0) {
        entry->Initialize_guess(value);
        result = 1;
    } else if (value == -1) {
        entry->Initialize_guess(0);
        result = 1;
    }
    ClearKeyMapIniEntry_guess(key, flag);
    if (result != 0) {
        this->SaveKeymapping(key, entry, mode);
    }
    return result;
}

// Frees the key map (0x0098599C) and clears the pointer; the client shutdown calls it.
// FUNCTION: TITANIUM 0x004B3709
void ClearBuffer_guess() {
    if (g_buffer_guess != 0) {
        free(g_buffer_guess);
    }
    g_buffer_guess = 0;
}

// Binds `source` as the primary key of command `index` and saves it, unless it is a key that cannot be bound.
// FUNCTION: TITANIUM 0x004B3721
bool KeyMap_guess::AttachKeyToEqCommand(int* source, int index) {
    bool stored = false;
    if (!IsUnbindableKey_guess((KeyState_guess*)source)) {
        slot_guess[index] = *source;
        ((KeyMapStore_guess*)this)->SaveKeymapping(index, (Entry_guess*)source, 0);
        stored = true;
    }
    return stored;
}

// Same for the alternate key.
// FUNCTION: TITANIUM 0x004B3754
bool KeyMap_guess::AttachAltKeyToEqCommand(int* source, int index) {
    bool stored = false;
    if (!IsUnbindableKey_guess((KeyState_guess*)source)) {
        slot_guess[index + 0x10b] = *source;
        ((KeyMapStore_guess*)this)->SaveKeymapping(index, (Entry_guess*)source, 1);
        stored = true;
    }
    return stored;
}

// Deletes both KeyMaps entries for the first 0xF7 commands.
// FUNCTION: TITANIUM 0x004B378B
void KeyMapStore_guess::NoteAll_guess() {
    for (unsigned int key = 0; key < 0xf7; ++key) {
        Note_guess(key, 0);
        Note_guess(key, 1);
    }
}

// Loads the saved bindings over the defaults for the first 0xF7 commands, old INI entries first.
// FUNCTION: TITANIUM 0x004B37B1
void KeyMap_guess::LoadAll_guess() {
    Entry_guess entry;
    entry.Clear_guess();
    for (unsigned int key = 0; key < 0xf7; ++key) {
        for (unsigned int mode = 0; mode < 2; ++mode) {
            if (((KeyMapStore_guess*)this)->Bind_guess(key, mode, &entry) ||
                ((KeyMapStore_guess*)this)->Load_guess(key, mode, &entry)) {
                slot_guess[key + mode * 0x10b] = entry.value_guess;
            }
        }
    }
}

// Builds the key map: 0x216 cleared slots (0x10B commands, primary and alternate key each), the default
// keys (0x004B26F0), then the stored bindings over them (0x004B37B1); no command starts out pressed.
// FUNCTION: TITANIUM 0x004B381A
KeyMap_guess::KeyMap_guess() {
    vector_constructor_iterator_guess(this, 4, 0x216, &Entry_guess::Clear_guess);
    FUN_00574110_guess("Initializing keypress handler.");
    Init_guess();
    LoadAll_guess();
    for (int i = 0; i < 0x10b; ++i) {
        pressed_guess[i] = 0;
    }
}

// Creates the key map (0x0098599C); the client startup calls it before loading the keyboard tables.
// FUNCTION: TITANIUM 0x004B385E
void CreateKeyMap_guess() {
    g_buffer_guess = new KeyMap_guess();
}
