// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 9: a hint from compare/tumap.py.
// The Bazaar buyer (barter) state: 50 buy lines, the welcome message and barter mode, saved to
// UserData\BART_<name>_<server>.ini and logged to Logs\btrlog_<server>_<name>.txt. Every request and reply is
// OP_Barter with a type code first (2/3 mode on/off, 5 buy line, 6 remove, 8 sold, 9 bought, 0x13
// welcome...).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct Entry_guess {
    char bytes[0x1C];
    int field_1c_guess;
    char bytes_20_guess[0x70 - 0x20];
    // EXTERNAL: TITANIUM 0x005E41E0 Entry_guess::Entry_guess
    Entry_guess();
    // EXTERNAL: TITANIUM 0x005E4260 Entry_guess::~Entry_guess
    ~Entry_guess();
    // EXTERNAL: TITANIUM 0x005E3FE0 Entry_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x005E4020 Entry_guess::FUN_005e4020
    void FUN_005e4020(void* buffer, int size);
    // EXTERNAL: TITANIUM 0x005E4290 Entry_guess::CopyData_guess
    void CopyData_guess(const void* buffer, int size);
};

struct CopyRecord_guess;
struct HandlerMessage_guess;

struct BarterManager_guess {
    Entry_guess entries[50];
    char buyerMode_15e0_guess[4];
    CXStr text_15E4_guess;
    CXStr text_15E8_guess;
    BarterManager_guess();
    ~BarterManager_guess();
    void ClearBuyLines_guess();
    int IsTestServer_guess();
    int FindFreeBuyLine_guess();
    void EndBuyerInspect_guess();
    void ClearBuyLine_guess(int index);
    void SetBuyerMode_guess(char value);
    void ToggleBuyLine_guess(int index);
    void ReportItemSold_guess(CopyRecord_guess* record, const char* name, int quantity, int money);
    void ReportItemBought_guess(CopyRecord_guess* record, const char* seller, int count, int price);
    void RemoveBuyLine_guess(int index);
    CXStr FormatPrice_guess(CStrRep* source);
    void SerializeBuyLine_guess(CopyRecord_guess* record, char* output);
    void BuildIniPath_guess();
    void SetWelcomeMessage_guess(const char* name);
    void WriteBarterLog_guess(char* text);
    CXStr FormatBuyLine_guess(Entry_guess* source);
    CXStr GetBuyLineText_guess(int index);
    void SaveBuyLines_guess(int index);
    void SetBuyLine_guess(const CopyRecord_guess* source);
    void UpdateBuyLine_guess(const CopyRecord_guess* source);
    // EXTERNAL: TITANIUM 0x00409F07 BarterManager_guess::ParseBuyLine_guess
    void ParseBuyLine_guess(char* text, Entry_guess* entry);
    void LoadBuyLines_guess();
    void Handle_OP_Barter_guess(int first_guess, HandlerMessage_guess* message_guess, int last_guess);
};

struct Message_guess {
    int type_guess;
    char data_guess[0x3a4];
};

struct BusyState_guess {
    char padding_guess[0x1074];
    int field_1074_guess;
};

struct BusyTarget_guess {
    char padding120_guess[0x120];
    char text_120_guess[1];
    char padding121_guess[0x1A8 - 0x121];
    BusyState_guess* pActorInfo_01a8_guess;
    char padding1AC_guess[0x258 - 0x1AC];
    int spawnId_0258_guess;
};

struct BusyMessage_guess {
    int type_guess;
    int value_guess;
    int extra_guess;
};

struct WelcomeMessage_guess {
    int type_guess;
    char text_guess[0x100];
};

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned size_guess);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0060E450 strcpy
char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x00574310 CopyBuffer_guess
void __cdecl CopyBuffer_guess(char* destination_guess, const char* source_guess, unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess,
                              const char* p0_guess, const char* p1_guess,
                              const char* p2_guess, const char* p3_guess,
                              const char* p4_guess, const char* p5_guess,
                              const char* p6_guess, const char* p7_guess,
                              const char* p8_guess);

// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section, const char* key, const char* value, const char* extra);

// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section, const char* key, char* default_guess,
                                char* output_guess, unsigned int size_guess, const char* file_guess);

struct AddressEntry_guess {
    int field_00_guess;
    int field_04_guess;
    int field_08_guess;
    char text_0c_guess[0x40];
};

struct IndexedEntries_guess {
    int count;
    AddressEntry_guess* data;
    int capacity_guess;
    unsigned char flag_guess;
    // EXTERNAL: TITANIUM 0x0050F3F6 IndexedEntries_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00405492 IndexedEntries_guess::ThrowSelf_guess
    __declspec(noreturn) void ThrowSelf_guess();
    void Resize_guess(int size);
    AddressEntry_guess* GetEntry_guess(int index);
    void Grow_guess(int size);
    IndexedEntries_guess* CopyFrom_guess(const IndexedEntries_guess* source);
    void SetEntry_guess(int index, const AddressEntry_guess* source);
};

struct CopyRecord_guess {
    char field_00_guess;
    char padding_01_guess[3];
    int field_04_guess;
    int field_08_guess;
    IndexedEntries_guess entries_0c_guess;
    int field_1c_guess;
    int field_20_guess;
    char field_24_guess;
    char bytes_25_guess[0x40];
    char padding_65_guess[3];
    int field_68_guess;
    int field_6c_guess;
    CopyRecord_guess* CopyFrom_guess(const CopyRecord_guess* source);
};

struct HandlerListItem_guess {
    char bytes_guess[0x4c];
};

struct HandlerMessage_guess {
    int type_guess;
    union {
        int payloadValue_0004_guess;
        char text_guess[0x40];
        struct {
            int field_04_guess;
            union {
                struct {
                    union {
                        int field_08_guess;
                        unsigned char state_guess;
                    };
                    char name_guess[0x40];
                    char payload_guess[0x3a4];
                } data_guess;
                HandlerListItem_guess list_guess[1];
            };
        } content_guess;
    };
};

struct TradeBuffer_guess {
    Entry_guess entry_guess;
    void CopyFrom_guess(const void* buffer, int size) {
        entry_guess.CopyData_guess(buffer, size);
    }
    CopyRecord_guess* AsRecord_guess() {
        return (CopyRecord_guess*)this;
    }
};

struct Feature_guess {
    // EXTERNAL: TITANIUM 0x004DF70E Feature_guess::Update_guess
    void Update_guess(int value_guess, const TradeBuffer_guess* buffer_guess);
};

struct BusyReceiver_guess {
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
    virtual int SetBusy_guess(int active, int flag);
    char padding04_guess[0x58];
    char active_5c_guess;
    char padding5d_guess[0x19c - 0x5d];
    int field_19c_guess;
    // EXTERNAL: TITANIUM 0x004DE41A BusyReceiver_guess::Receive_guess
    void Receive_guess(const TradeBuffer_guess* message);
};

struct TextAppend_guess {
    // EXTERNAL: TITANIUM 0x00572C10 TextAppend_guess::Append_guess
    void Append_guess(const CXStr& value_guess);
};

struct CharacterMoney_guess {
    // EXTERNAL: TITANIUM 0x0041A316 CharacterMoney_guess::ApplyEncodedValue_guess
    void ApplyEncodedValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0041A3C5 CharacterMoney_guess::AddEncodedValue_guess
    void AddEncodedValue_guess(int value_guess);
    char padding_guess[0xC];
    unsigned char field_0c_guess;
};

struct PcData_guess {
    char padding_guess[0xC280];
    CharacterMoney_guess character_guess;
};

struct SoundManager_guess {
    // EXTERNAL: TITANIUM 0x0044A537 SoundManager_guess::WavePlay_guess
    void WavePlay_guess(int index_guess, void* value_guess);
};

// EXTERNAL: TITANIUM 0x0060E985 operator_new_guess
void* __cdecl operator_new_guess(unsigned size_guess);

// EXTERNAL: TITANIUM 0x0060D682 _free_guess
void __cdecl _free_guess(void* pointer_guess);

// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z

#define g_messageValue_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_testMode_guess EQ_GLOBAL(int, 0x009247B0)
#define g_configText_guess EQ_ARRAY(char, 0x0095D3D4)
#define g_busyTarget_guess EQ_GLOBAL(BusyTarget_guess*, 0x00905D10)
#define pinstCBarterMerchantWnd_guess EQ_GLOBAL(BusyReceiver_guess*, 0x009915D0)
#define pinstCBarterSearchWnd_guess EQ_GLOBAL(Feature_guess*, 0x009915EC)
#define g_busyResult_guess EQ_GLOBAL(int, 0x009248D4)
#define g_busyCount_guess EQ_GLOBAL(int, 0x009248D0)
#define g_pcData_guess EQ_GLOBAL(PcData_guess*, 0x00905D00)
#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define g_caret_guess EQ_ARRAY(char, 0x0063FE10)
#define g_comma_guess EQ_ARRAY(char, 0x0063FDE4)
#define g_period_guess EQ_ARRAY(char, 0x0063FDE0)

// EXTERNAL: TITANIUM 0x00401B28 FindBusyTarget_guess
BusyTarget_guess* __cdecl FindBusyTarget_guess(int index_guess);

// EXTERNAL: TITANIUM 0x0060ACA0 CopyCXStr_guess
void __cdecl CopyCXStr_guess(CXStr* destination_guess, const CXStr* source_guess);

// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(char* first, char* second);

// EXTERNAL: TITANIUM 0x005769E0 FUN_005769e0_guess
int __cdecl FUN_005769e0_guess(char* input, char* output, unsigned size, int value, int flag);

// EXTERNAL: TITANIUM 0x0060E3A3 atol
long __cdecl atol(const char* value);

// EXTERNAL: TITANIUM 0x0040552D GetLanguageCodePage_guess
int __cdecl GetLanguageCodePage_guess(int value_guess);

// EXTERNAL: TITANIUM 0x005749F0 FUN_005749f0_guess
void __cdecl FUN_005749f0_guess(int value_guess, const char* buffer_guess,
                                char* output_guess, unsigned int size_guess);

#define g_resourceIndex_guess EQ_GLOBAL(int, 0x00923D74)
#define g_numberBuffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value_guess, char* destination_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x00576ED0 FUN_00576ed0_guess
void __cdecl FUN_00576ed0_guess(const char* path_guess);

// EXTERNAL: TITANIUM 0x0060E460 strcat
char* __cdecl strcat(char* destination_guess, const char* source_guess);

struct FILE_guess;

// EXTERNAL: TITANIUM 0x0060E887 fopen
FILE_guess* __cdecl fopen(const char* filename_guess, const char* mode_guess);

// EXTERNAL: TITANIUM 0x0060EC45 fprintf
int __cdecl fprintf(FILE_guess* file_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0060E790 fclose
int __cdecl fclose(FILE_guess* file_guess);

// EXTERNAL: TITANIUM 0x0060ECBC time
long __cdecl time(long* time_guess);

// EXTERNAL: TITANIUM 0x0060ECA3 ctime
char* __cdecl ctime(const long* time_guess);

// EXTERNAL: TITANIUM 0x0060D970 strlen
unsigned int __cdecl strlen(const char* string_guess);

#include "titanium/layouts/core.h"
#include "titanium/wnd/CBarterWnd.h"

// pCharData: the pointer at +8 is read as a VBTable*.
struct CharRoot_guess {
    char bytes_00_guess[8];
    VBTable* ref_08_guess;
};

struct EverQuestView_guess {
    // EXTERNAL: TITANIUM 0x00493B8F EverQuestView_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
};

// Reads one field up to `value` (the separator) and stores whether it is non-zero.
// FUNCTION: TITANIUM 0x00408E74
int __cdecl ParseBoolField_guess(char* input, char* output, int value) {
    char buffer[0x800];
    buffer[0] = 0;
    int result = FUN_005769e0_guess(input, buffer, sizeof(buffer), value, 1);
    *output = atol(buffer) != 0;
    return result;
}

// Barter state constructor: only empties the text at +0x15E0; the buy lines construct themselves.
// FUNCTION: TITANIUM 0x00408ECE
BarterManager_guess::BarterManager_guess() {
    buyerMode_15e0_guess[0] = 0;
}

// Empties all 50 buy lines and forgets the ini path.
// FUNCTION: TITANIUM 0x00408EFD
void BarterManager_guess::ClearBuyLines_guess() {
    Entry_guess* current = entries;
    int remaining = 0x32;
    do {
        current->Reset_guess();
        ++current;
    } while (--remaining != 0);
    text_15E8_guess = EQ_ARRAY(char, 0x0063F53F);
}

// True on the test server (flag 0x9247B0 or the server name "test").
// FUNCTION: TITANIUM 0x00408F28
int BarterManager_guess::IsTestServer_guess() {
    if (g_testMode_guess == 0) {
        if (__stricmp(g_configText_guess, "test") != 0)
            return false;
    }
    return true;
}

// Index of the first of the 50 buy lines whose first byte is 0 (unused), or -1 when all are taken.
// FUNCTION: TITANIUM 0x00408F4D
int BarterManager_guess::FindFreeBuyLine_guess() {
    Entry_guess* current = entries;
    int result = -1;
    int count = 0;
    do {
        if (current->bytes[0] == 0) {
            result = count;
            break;
        }
        ++count;
        ++current;
    } while (count < 0x32);
    return result;
}

// Stops inspecting another buyer: tells the server (OP_Barter type 0xB, 12 bytes) and drops one busy count.
// FUNCTION: TITANIUM 0x00408F64
void BarterManager_guess::EndBuyerInspect_guess() {
    if (g_busyTarget_guess != 0 && g_busyTarget_guess->pActorInfo_01a8_guess->field_1074_guess != 0) {
        BusyMessage_guess message_guess;
        message_guess.value_guess = g_busyTarget_guess->spawnId_0258_guess;
        message_guess.type_guess = 0xb;
        EQSendMessage(&g_messageValue_guess, OP_Barter, (int*)&message_guess, 0xc, 1);
        g_busyResult_guess = 0;
        g_busyTarget_guess = 0;
    }
    if (g_busyCount_guess > 0) {
        --g_busyCount_guess;
    } else {
        g_busyCount_guess = 0;
    }
}

// Empties buy line `index` and refreshes the barter window (0x004E02A8).
// FUNCTION: TITANIUM 0x00408FD3
void BarterManager_guess::ClearBuyLine_guess(int index) {
    entries[index].Reset_guess();
    pinstCBarterWnd_guess->RefreshBuyLineList_guess(0);
}

// Asks the server to turn barter mode on (2) or off (3). Only "off" takes effect at once; "on" waits for the
// server's type 2 reply.
// FUNCTION: TITANIUM 0x00408FF3
void BarterManager_guess::SetBuyerMode_guess(char value) {
    if (value != buyerMode_15e0_guess[0]) {
        int payload = value ? 2 : 3;
        EQSendMessage(&g_messageValue_guess, OP_Barter, &payload, 4, 1);
    }
    if (value == 0)
        buyerMode_15e0_guess[0] = value;
}

// In barter mode the toggled line is sent (type 5) and the local flag is restored until the server confirms.
// FUNCTION: TITANIUM 0x0040903B
void BarterManager_guess::ToggleBuyLine_guess(int index) {
    if (buyerMode_15e0_guess[0] != 0) {
        Message_guess message;
        memset(&message, 0, sizeof(message));
        entries[index].bytes[0x24] = !entries[index].bytes[0x24];
        message.type_guess = 5;
        entries[index].FUN_005e4020(message.data_guess, 0x3a4);
        EQSendMessage(&g_messageValue_guess, OP_Barter, (int*)&message, sizeof(message), 1);
        entries[index].bytes[0x24] = !entries[index].bytes[0x24];
        pinstCBarterWnd_guess->Teardown_guess();
    } else {
        entries[index].bytes[0x24] = !entries[index].bytes[0x24];
        pinstCBarterWnd_guess->RefreshBuyLineList_guess(0);
    }
}

// Copper amount as coins, largest first (platinum, gold, silver, copper); 0 still prints the copper part.
// FUNCTION: TITANIUM 0x004090FD
CXStr __cdecl FormatCoins_guess(int value) {
    CXStr text;
    if (value >= 1000) {
        int thousands = value / 1000;
        int rest = value % 1000;
        text += _itoa(thousands, g_numberBuffer_guess, 10);
        text += EQ_ARRAY(char, 0x0063FDD4);
        value = rest;
    }
    if (value >= 100) {
        int hundreds = value / 100;
        int rest = value % 100;
        text += _itoa(hundreds, g_numberBuffer_guess, 10);
        text += EQ_ARRAY(char, 0x0063FDD0);
        value = rest;
    }
    if (value >= 10) {
        int tens = value / 10;
        int rest = value % 10;
        text += _itoa(tens, g_numberBuffer_guess, 10);
        text += EQ_ARRAY(char, 0x0063FDCC);
        value = rest;
    }
    if (value > 0 || (text.Ptr ? text.Ptr->length : 0) == 0) {
        text += _itoa(value, g_numberBuffer_guess, 10);
        text += EQ_ARRAY(char, 0x0063FDC8);
    }
    return text;
}

// The price, plus "+ items" when the line also asks for trade items.
// FUNCTION: TITANIUM 0x00409226
CXStr BarterManager_guess::FormatPrice_guess(CStrRep* source) {
    CXStr text;
    text = FormatCoins_guess(source->length);
    if (source->encoding > 0)
        text += "+ items";
    return text;
}

// Array of 0x4C-byte entries.
// FUNCTION: TITANIUM 0x004092BD
void IndexedEntries_guess::Resize_guess(int size) {
    if (size != 0 && (size > count || data == 0)) {
        AddressEntry_guess* newData = (AddressEntry_guess*)operator_new_guess(size * 0x4c);
        if (newData != 0) {
            if (data != 0) {
                int index = 0;
                if (index < count) {
                    do {
                        newData[index] = data[index];
                        ++index;
                    } while (index < count);
                }
            }
            _free_guess(data);
            data = newData;
            capacity_guess = size;
        } else {
            _free_guess(data);
            data = 0;
            capacity_guess = 0;
            flag_guess = 0;
        }
    }
}

// In barter mode asks the server (type 6); otherwise removes the line at once.
// FUNCTION: TITANIUM 0x00409600
void BarterManager_guess::RemoveBuyLine_guess(int index) {
    if (buyerMode_15e0_guess[0] != 0) {
        int payload[2];
        payload[1] = index;
        payload[0] = 6;
        EQSendMessage(&g_messageValue_guess, OP_Barter, payload, 8, 1);
    } else {
        ClearBuyLine_guess(index);
    }
}

// "Buying %1 %2, offering %3 each." (string 6066).
// FUNCTION: TITANIUM 0x00409643
CXStr BarterManager_guess::FormatBuyLine_guess(Entry_guess* source) {
    char buffer[0x400];
    CopyRecord_guess* record = (CopyRecord_guess*)source;
    FormatText_guess(buffer, 0x17b2, _itoa(record->field_1c_guess, g_itoaBuffer_guess, 10),
                     record->bytes_25_guess, FormatPrice_guess((CStrRep*)record),
                     0, 0, 0, 0, 0, 0);
    return buffer;
}

// Bounds-checked element `index` of the array; an index out of range or a missing buffer throws.
// FUNCTION: TITANIUM 0x00409340
AddressEntry_guess* IndexedEntries_guess::GetEntry_guess(int index) {
    if (index < count && index >= 0 && data != 0)
        return data + index;
    ThrowSelf_guess();
}

// Allocates (size+4) * 0x98 bytes, which is 2 * (size+4) entries; the capacity it stores matches.
// FUNCTION: TITANIUM 0x00409361
void IndexedEntries_guess::Grow_guess(int size) {
    if (size != 0 && (size > capacity_guess || data == 0)) {
        int newCapacity = size + 4;
        AddressEntry_guess* newData = (AddressEntry_guess*)operator_new_guess(newCapacity * 0x98);
        if (newData != 0) {
            if (data != 0) {
                int index = 0;
                if (index < count) {
                    do {
                        newData[index] = data[index];
                        ++index;
                    } while (index < count);
                }
            }
            _free_guess(data);
            data = newData;
            capacity_guess = newCapacity * 2;
        } else {
            _free_guess(data);
            data = 0;
            capacity_guess = 0;
            flag_guess = 0;
        }
    }
}

// Destructor: empties all 50 buy lines and forgets the ini path (0x00408EFD).
// FUNCTION: TITANIUM 0x004093F1
BarterManager_guess::~BarterManager_guess() {
    ClearBuyLines_guess();
}

// Pays the sale, plays sound 0x8A and prints "You've sold <n> <item> to <buyer> for <coins>[ and the
// following: ...]." The sale is not written to the barter log, unlike a purchase.
// FUNCTION: TITANIUM 0x0040944C
// @early-stop: budget, diff ndiff=14
void BarterManager_guess::ReportItemSold_guess(CopyRecord_guess* record, const char* name, int quantity, int money) {
    g_pcData_guess->character_guess.AddEncodedValue_guess(money);
    g_pcData_guess->character_guess.field_0c_guess = 1;
    g_soundManager_guess->WavePlay_guess(0x8a, 0);
    CXStr text;
    text = "You've sold ";
    CopyRecord_guess* rec;
    const char* separator;
    char* itoaBuffer = g_itoaBuffer_guess;
    separator = EQ_ARRAY(char, 0x0063FE10);
    text += _itoa(quantity, itoaBuffer, 10);
    text += separator;
    rec = record;
    text += rec->bytes_25_guess;
    text += " to ";
    text += name;
    text += " for ";
    ((TextAppend_guess*)&text)->Append_guess(FormatCoins_guess(money));
    if (rec->entries_0c_guess.count > 0) {
        text += " and the following: ";
        for (int index = 0; index < rec->entries_0c_guess.count; ++index) {
            if (index != 0)
                text += EQ_ARRAY(char, 0x0063FDE4);
            text += _itoa(rec->entries_0c_guess.GetEntry_guess(index)->field_04_guess * quantity,
                          itoaBuffer, 10);
            text += separator;
            text += rec->entries_0c_guess.GetEntry_guess(index)->text_0c_guess;
        }
    }
    text += EQ_ARRAY(char, 0x0063FDE0);
    pEverQuest->dsp_chat(text, 0x114, 1);
}

// Appends one timestamped line; before login the name part is "prelogin".
// FUNCTION: TITANIUM 0x004096EF
void BarterManager_guess::WriteBarterLog_guess(char* text) {
    char buffer[0x200];
    char path[0x100];
    FUN_00576ed0_guess("Logs");
    strcpy(path, "Logs\\btrlog_");
    ((EverQuestView_guess*)pEverQuest)->GetServerShortName_guess(buffer);
    strcat(path, buffer);
    strcat(path, "_");
    char* name;
    if (pCharData == 0 || (name = &((CharRoot_guess*)pCharData)->bytes_00_guess[((CharRoot_guess*)pCharData)->ref_08_guess->vbase_offset + 0x44], *name == 0)) {
        strcat(path, "prelogin");
    } else {
        FUN_005749f0_guess(GetLanguageCodePage_guess(g_resourceIndex_guess), name, buffer, 0x100);
        strcat(path, buffer);
    }
    strcat(path, ".txt");
    FILE_guess* file = fopen(path, "a");
    if (file != 0) {
        long now = time(0);
        char* stamp = ctime(&now);
        unsigned int length = strlen(stamp);
        stamp[length - 1] = 0;
        fprintf(file, "[%s] ", stamp);
        fprintf(file, "%s\n", text);
        fclose(file);
    }
}

// Ini form of a line, '^'-separated: "*2^<index>^<used>" then enabled, item id, name, icon, price, quantity
// and the trade-item count, then four fields per trade item. Version 2 of the format.
// FUNCTION: TITANIUM 0x0040983E
void BarterManager_guess::SerializeBuyLine_guess(CopyRecord_guess* record, char* output) {
    int length = sprintf(output, "*%d^%d^%d^", 2, record->field_20_guess,
                         (unsigned char)record->field_00_guess);
    char* destination = output + length;
    if (record->field_00_guess != 0) {
        length = sprintf(destination, "%d^%d^%s^%d^%d^%d^%d",
                         record->field_24_guess != 0,
                         record->field_04_guess,
                         record->bytes_25_guess,
                         record->field_68_guess,
                         record->field_08_guess,
                         record->field_1c_guess,
                         record->entries_0c_guess.count);
        destination += length;
        if (record->entries_0c_guess.count > 0) {
            int index = 0;
            do {
                AddressEntry_guess* first = record->entries_0c_guess.GetEntry_guess(index);
                length = sprintf(destination, "^%d^%d^%s^%d",
                                 first->field_00_guess,
                                 record->entries_0c_guess.GetEntry_guess(index)->field_04_guess,
                                 record->entries_0c_guess.GetEntry_guess(index)->text_0c_guess,
                                 record->entries_0c_guess.GetEntry_guess(index)->field_08_guess);
                destination += length;
                ++index;
            } while (index < record->entries_0c_guess.count);
        }
    }
}

// .\UserData\BART_<name>_<server>.ini, built once.
// FUNCTION: TITANIUM 0x004098EC
void BarterManager_guess::BuildIniPath_guess() {
    char buffer[0x100];
    CStrRep* rep = ((CXStr*)&text_15E8_guess)->Ptr;
    int length = rep != 0 ? rep->length : 0;
    if (length == 0) {
        FUN_005749f0_guess(GetLanguageCodePage_guess(g_resourceIndex_guess),
                           &((CharRoot_guess*)pCharData)->bytes_00_guess[
                               ((CharRoot_guess*)pCharData)->ref_08_guess->vbase_offset + 0x44],
                           buffer, 0x100);
        ((CXStr*)&text_15E8_guess)->operator=(".\\UserData\\BART_");
        ((CXStr*)&text_15E8_guess)->operator+=(buffer);
        ((CXStr*)&text_15E8_guess)->operator+=("_");
        ((EverQuestView_guess*)pEverQuest)->GetServerShortName_guess(buffer);
        ((CXStr*)&text_15E8_guess)->operator+=(buffer);
        ((CXStr*)&text_15E8_guess)->operator+=(".ini");
    }
}

// Array assignment: clears this array, then copies the count and every element of `source`.
// FUNCTION: TITANIUM 0x004099A8
IndexedEntries_guess* IndexedEntries_guess::CopyFrom_guess(const IndexedEntries_guess* source) {
    if (this != source) {
        Clear_guess();
        if (source->count != 0) {
            Resize_guess(source->count);
            if (data != 0) {
                int index = 0;
                if (index < source->count) {
                    do {
                        data[index] = source->data[index];
                        ++index;
                    } while (index < source->count);
                }
            }
            count = source->count;
        }
    }
    return this;
}

// Stores a copy of the extra-item entry `source` at `index` of a barter buy line's list, first growing the
// array (0x00409361) and the count to index + 1 when needed. Negative indexes are ignored, and so is the
// store when the allocation failed.
// FUNCTION: TITANIUM 0x004099FC
void IndexedEntries_guess::SetEntry_guess(int index, const AddressEntry_guess* source) {
    if (index >= 0) {
        if (index >= count) {
            Grow_guess(index + 1);
            if (data != 0)
                count = index + 1;
        }
        if (data != 0)
            data[index] = *source;
    }
}

// Pays for the purchase, plays sound 0x8A, shows the bought line in the barter window and logs it.
// FUNCTION: TITANIUM 0x00409A39
// @early-stop: budget, diff ndiff=14
void BarterManager_guess::ReportItemBought_guess(CopyRecord_guess* record, const char* seller, int count,
                                          int price) {
    g_pcData_guess->character_guess.ApplyEncodedValue_guess(price);
    g_pcData_guess->character_guess.field_0c_guess = 1;
    g_soundManager_guess->WavePlay_guess(0x8a, 0);
    CXStr message;
    message = "You've bought ";
    const char* separator;
    char* itoaBuffer;
    separator = g_caret_guess;
    itoaBuffer = g_itoaBuffer_guess;
    message += _itoa(count, itoaBuffer, 10);
    message += separator;
    message += record->bytes_25_guess;
    message += " from ";
    message += seller;
    message += " for ";
    ((TextAppend_guess*)&message)->Append_guess(FormatCoins_guess(price));
    if (record->entries_0c_guess.count > 0) {
        message += " and the following: ";
        for (int index = 0; index < record->entries_0c_guess.count; ++index) {
            if (index != 0)
                message += g_comma_guess;
            message += _itoa(record->entries_0c_guess.GetEntry_guess(index)->field_04_guess * count,
                             itoaBuffer, 10);
            message += separator;
            message += record->entries_0c_guess.GetEntry_guess(index)->text_0c_guess;
        }
    }
    message += g_period_guess;
    pinstCBarterWnd_guess->AppendColoredText_guess((char*)message, 0);
    WriteBarterLog_guess((char*)message);
}

// Barter buy line assignment: copies the flags and values, the list of extra items wanted with it (+0x0C,
// 0x004099A8) and the 64-char item name at +0x25.
// FUNCTION: TITANIUM 0x00409BFD
CopyRecord_guess* CopyRecord_guess::CopyFrom_guess(const CopyRecord_guess* source) {
    field_00_guess = source->field_00_guess;
    field_04_guess = source->field_04_guess;
    field_08_guess = source->field_08_guess;
    entries_0c_guess.CopyFrom_guess(&source->entries_0c_guess);
    field_1c_guess = source->field_1c_guess;
    field_20_guess = source->field_20_guess;
    field_24_guess = source->field_24_guess;
    for (int i = 0; i < 0x40; ++i)
        bytes_25_guess[i] = source->bytes_25_guess[i];
    field_68_guess = source->field_68_guess;
    field_6c_guess = source->field_6c_guess;
    return this;
}

// Saves the welcome message (sent as type 0x13 in barter mode), shows "Buyer welcome message changed to '%1'"
// (string 6069) and logs it.
// FUNCTION: TITANIUM 0x00409C5B
void BarterManager_guess::SetWelcomeMessage_guess(const char* name) {
    char formatted_guess[0x200];
    char buffer_guess[0x100];
    CopyBuffer_guess(buffer_guess, name, 0x100);
    text_15E4_guess = buffer_guess;
    if (buyerMode_15e0_guess[0] != 0) {
        WelcomeMessage_guess message;
        message.type_guess = 0x13;
        strcpy(message.text_guess, ((CXStr*)&text_15E4_guess)->operator char*());
        EQSendMessage(&g_messageValue_guess, OP_Barter, (int*)&message, sizeof(message), 1);
    }
    FormatText_guess(formatted_guess, 0x17b5, ((CXStr*)&text_15E4_guess)->operator char*(),
                     0, 0, 0, 0, 0, 0, 0, 0);
    pinstCBarterWnd_guess->AppendColoredText_guess(formatted_guess, 0);
    WriteBarterLog_guess(formatted_guess);
    FUN_0060beb0_guess("General", "Welcome", ((CXStr*)&text_15E4_guess)->operator char*(),
                       ((CXStr*)&text_15E8_guess)->operator char*());
}

// Display text of buy line `index` ("Buying %1 %2, offering %3 each.", 0x00409643); the barter window
// lists the lines with it.
// FUNCTION: TITANIUM 0x00409D5E
CXStr BarterManager_guess::GetBuyLineText_guess(int index) {
    return FormatBuyLine_guess(&entries[index]);
}

// Saves one line (or all 50 for -1) as BuyLine00..BuyLine49 plus the welcome message.
// FUNCTION: TITANIUM 0x00409D7E
void BarterManager_guess::SaveBuyLines_guess(int index) {
    int first = 0;
    int last = 0x31;
    if (index != -1) {
        first = index;
        last = index;
    }
    BuildIniPath_guess();
    for (int i = first; i <= last; ++i) {
        char name[256];
        char output[4096];
        sprintf(name, "BuyLine%02d", i);
        output[0] = 0;
        SerializeBuyLine_guess((CopyRecord_guess*)&entries[i], output);
        FUN_0060beb0_guess("BuyLines", name, output, ((CXStr*)&text_15E8_guess)->operator char*());
    }
    FUN_0060beb0_guess("General", "Welcome", ((CXStr*)&text_15E4_guess)->operator char*(),
                       ((CXStr*)&text_15E8_guess)->operator char*());
}

// Stores a line at the index it carries (+0x20) and refreshes the window.
// FUNCTION: TITANIUM 0x00409E60
void BarterManager_guess::SetBuyLine_guess(const CopyRecord_guess* source) {
    ((CopyRecord_guess*)entries + source->field_20_guess)->CopyFrom_guess(source);
    pinstCBarterWnd_guess->RefreshBuyLineList_guess(0);
}

// In barter mode the server must confirm the change (type 5); otherwise stores it at once.
// FUNCTION: TITANIUM 0x00409E84
void BarterManager_guess::UpdateBuyLine_guess(const CopyRecord_guess* source) {
    if (buyerMode_15e0_guess[0] != 0) {
        Message_guess message;
        memset(&message, 0, sizeof(message));
        message.type_guess = 5;
        ((Entry_guess*)source)->FUN_005e4020(message.data_guess, 0x3a4);
        EQSendMessage(&g_messageValue_guess, OP_Barter, (int*)&message, sizeof(message), 1);
    } else {
        SetBuyLine_guess(source);
    }
}

// EXTERNAL: TITANIUM 0x004B2056 FUN_004b2056_guess
int __cdecl FUN_004b2056_guess(char* input, void* output, int separator);

// Parses an ini line. Old lines have no "*<version>^" prefix (version 1) and no index/used fields.
// FUNCTION: TITANIUM 0x00409F07
// @early-stop: tiebreak, diff ndiff=3
void BarterManager_guess::ParseBuyLine_guess(char* input, Entry_guess* entry) {
    CopyRecord_guess* record = (CopyRecord_guess*)entry;
    char* source = input;
    entry->Reset_guess();
    int count = 1;
    if (*source == '*') {
        ++source;
        source += FUN_004b2056_guess(source, &count, 0x5e);
    }
    record->field_00_guess = 1;
    if (count >= 2) {
        source += FUN_004b2056_guess(source, &record->field_20_guess, 0x5e);
        source += ParseBoolField_guess(source, &record->field_00_guess, 0x5e);
        if (record->field_00_guess == 0)
            return;
    }
    source += ParseBoolField_guess(source, &record->field_24_guess, 0x5e);
    source += FUN_004b2056_guess(source, &record->field_04_guess, 0x5e);
    source += FUN_005769e0_guess(source, record->bytes_25_guess, 0x40, 0x5e, 1);
    source += FUN_004b2056_guess(source, &record->field_68_guess, 0x5e);
    source += FUN_004b2056_guess(source, &record->field_08_guess, 0x5e);
    source += FUN_004b2056_guess(source, &record->field_1c_guess, 0x5e);
    source += FUN_004b2056_guess(source, &count, 0x5e);
    if (count > 0) {
        int remaining = count;
        AddressEntry_guess parsed;
        do {
            source += FUN_004b2056_guess(source, &parsed.field_00_guess, 0x5e);
            source += FUN_004b2056_guess(source, &parsed.field_04_guess, 0x5e);
            source += FUN_005769e0_guess(source, parsed.text_0c_guess, 0x40, 0x5e, 1);
            source += FUN_004b2056_guess(source, &parsed.field_08_guess, 0x5e);
            record->entries_0c_guess.SetEntry_guess(record->entries_0c_guess.count, &parsed);
        } while (--remaining != 0);
    }
}

// Loads BuyLine00..49 until the first empty key, then the welcome message.
// FUNCTION: TITANIUM 0x0040A03F
void BarterManager_guess::LoadBuyLines_guess() {
    char default_guess[0x80];
    char key_guess[0x100];
    char copy_guess[0x100];
    char output_guess[0x1000];
    default_guess[0] = 0;
    BuildIniPath_guess();
    int index = 0;
    Entry_guess* current = entries;
    do {
        current->Reset_guess();
        sprintf(key_guess, "BuyLine%02d", index);
        FUN_0060be50_guess("BuyLines", key_guess, default_guess, output_guess, 0x1000,
                           ((CXStr*)&text_15E8_guess)->operator char*());
        if (output_guess[0] == 0)
            break;
        ParseBuyLine_guess(output_guess, current);
        if (current->field_1c_guess > 0)
            current->bytes[0] = 1;
        ++index;
        ++current;
    } while (index < 0x32);
    pinstCBarterWnd_guess->RefreshBuyLineList_guess(0);
    sprintf(key_guess, "Welcome");
    FUN_0060be50_guess("General", key_guess, default_guess, output_guess, 0x1000,
                       ((CXStr*)&text_15E8_guess)->operator char*());
    CopyBuffer_guess(copy_guess, output_guess, 0x100);
    text_15E4_guess = copy_guess;
}

// Types: 0 search results, 2/3 barter mode on/off ("Barter Mode *ON*"/"*OFF*", strings 6058/6059; turning on
// resends the welcome message and every enabled line), 5 line stored, 6 line removed, 8 sold, 9 bought,
// 10/12 inspecting another buyer starts or ends, 13 that buyer's lines, 15 "%1 is browsing your Buy Lines."
// (6060), 16 a line update, 20 "%1 greets you, '%2'" (6070).
// FUNCTION: TITANIUM 0x0040A180
// @early-stop: budget, structural ndiff=131
void BarterManager_guess::Handle_OP_Barter_guess(int first_guess, HandlerMessage_guess* message_guess,
                                          int last_guess) {
    if (message_guess->type_guess < 10) {
        switch (message_guess->type_guess) {
        case 0:
            pinstCBarterWnd_guess->ClearSearchResults_guess();
            for (int index_guess = 0; index_guess < message_guess->payloadValue_0004_guess; ++index_guess)
                pinstCBarterWnd_guess->AddSearchResult_guess(
                    &message_guess->content_guess.list_guess[index_guess]);
            pinstCBarterWnd_guess->Update_guess();
            break;
        case 2: {
            pinstCBarterWnd_guess->AppendColoredText_guess(
                (char*)pStringTable->getString(0x17aa, 0), 0);
            WriteBarterLog_guess((char*)pStringTable->getString(0x17aa, 0));
            buyerMode_15e0_guess[0] = 1;
            WelcomeMessage_guess welcome_guess;
            welcome_guess.type_guess = 0x13;
            strcpy(welcome_guess.text_guess,
                   ((CXStr*)&text_15E4_guess)->operator char*());
            EQSendMessage(&g_messageValue_guess, OP_Barter,
                               (int*)&welcome_guess, 0x104, 1);
            Message_guess packet_guess;
            memset(&packet_guess, 0, 0x3a8);
            packet_guess.type_guess = 5;
            for (int index_guess = 0; index_guess < 50; ++index_guess) {
                if (entries[index_guess].bytes[0] != 0 &&
                    entries[index_guess].bytes[0x24] != 0) {
                    entries[index_guess].FUN_005e4020(packet_guess.data_guess, 0x3a4);
                    EQSendMessage(&g_messageValue_guess, OP_Barter,
                                       (int*)&packet_guess, 0x3a8, 1);
                }
            }
            break;
        }
        case 3:
            pinstCBarterWnd_guess->AppendColoredText_guess(
                (char*)pStringTable->getString(0x17ab, 0), 0);
            WriteBarterLog_guess((char*)pStringTable->getString(0x17ab, 0));
            buyerMode_15e0_guess[0] = 0;
            break;
        case 5: {
            TradeBuffer_guess record_guess;
            record_guess.CopyFrom_guess(&message_guess->payloadValue_0004_guess, 0x3a4);
            SetBuyLine_guess(record_guess.AsRecord_guess());
            break;
        }
        case 6:
            ClearBuyLine_guess(message_guess->payloadValue_0004_guess);
            break;
        case 8: {
            TradeBuffer_guess record_guess;
            record_guess.CopyFrom_guess(
                message_guess->content_guess.data_guess.payload_guess, 0x3a4);
            ReportItemSold_guess(record_guess.AsRecord_guess(),
                               message_guess->content_guess.data_guess.name_guess,
                               message_guess->payloadValue_0004_guess,
                               message_guess->content_guess.data_guess.field_08_guess);
            break;
        }
        case 9: {
            TradeBuffer_guess record_guess;
            record_guess.CopyFrom_guess(
                message_guess->content_guess.data_guess.payload_guess, 0x3a4);
            ReportItemBought_guess(record_guess.AsRecord_guess(),
                               message_guess->content_guess.data_guess.name_guess,
                               message_guess->payloadValue_0004_guess,
                               message_guess->content_guess.data_guess.field_08_guess);
            if (pinstCBarterWnd_guess != 0)
                pinstCBarterWnd_guess->RebuildInventoryList_guess();
            break;
        }
        }
        return;
    }

    switch (message_guess->type_guess) {
    case 10:
        if (message_guess->content_guess.data_guess.field_08_guess == 0) {
            g_busyResult_guess = 0;
            if (pinstCBarterMerchantWnd_guess != 0)
                pinstCBarterMerchantWnd_guess->SetBusy_guess(0, 1);
        } else if (g_busyTarget_guess == 0 && pinstCBarterMerchantWnd_guess != 0) {
            g_busyTarget_guess = FindBusyTarget_guess(message_guess->payloadValue_0004_guess);
            pinstCBarterMerchantWnd_guess->field_19c_guess = g_busyTarget_guess->spawnId_0258_guess;
            if (pinstCBarterMerchantWnd_guess->SetBusy_guess(1, 1) == -1)
                EndBuyerInspect_guess();
        } else {
            g_busyResult_guess = 0;
        }
        break;
    case 12: {
        BusyTarget_guess* target_guess = FindBusyTarget_guess(message_guess->payloadValue_0004_guess);
        if (target_guess == 0 || target_guess->pActorInfo_01a8_guess == 0 || g_pcData_guess == 0)
            break;
        target_guess->pActorInfo_01a8_guess->field_1074_guess =
            message_guess->content_guess.data_guess.state_guess;
        if (target_guess == g_busyTarget_guess && pinstCBarterMerchantWnd_guess != 0) {
            g_busyTarget_guess = 0;
            pinstCBarterMerchantWnd_guess->SetBusy_guess(0, 1);
            g_busyResult_guess = 0;
        }
        break;
    }
    case 13:
        if (pinstCBarterMerchantWnd_guess != 0 && pinstCBarterMerchantWnd_guess->active_5c_guess != 0) {
            TradeBuffer_guess record_guess;
            record_guess.CopyFrom_guess(&message_guess->payloadValue_0004_guess, 0x3a4);
            pinstCBarterMerchantWnd_guess->Receive_guess(&record_guess);
        }
        break;
    case 15: {
        char formatted_guess[0x3a4];
        FormatText_guess(formatted_guess, 0x17ac, message_guess->text_guess,
                         0, 0, 0, 0, 0, 0, 0, 0);
        pinstCBarterWnd_guess->AppendColoredText_guess(formatted_guess, 0);
        WriteBarterLog_guess(formatted_guess);
        break;
    }
    case 16: {
        TradeBuffer_guess record_guess;
        record_guess.CopyFrom_guess(
            &message_guess->content_guess.data_guess.field_08_guess, 0x3a4);
        if (pinstCBarterSearchWnd_guess != 0)
            pinstCBarterSearchWnd_guess->Update_guess(message_guess->payloadValue_0004_guess, &record_guess);
        break;
    }
    case 20:
        if (pinstCBarterMerchantWnd_guess == 0 || pinstCBarterMerchantWnd_guess->active_5c_guess == 0 ||
            g_busyTarget_guess == 0)
            break;
        {
            CXStr source_guess(message_guess->text_guess);
            CXStr copy_guess;
            CopyCXStr_guess(&copy_guess, &source_guess);
            char formatted_guess[0x3a4];
            FormatText_guess(formatted_guess, 0x17b6, g_busyTarget_guess->text_120_guess,
                             copy_guess, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(formatted_guess, 0x111, 1);
        }
        break;
    }
}

