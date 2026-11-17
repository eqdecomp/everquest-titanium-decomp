// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 85: a hint from compare/tumap.py.
// Two unrelated pieces. The PvP-point currency object (PvpCurrency_guess, made at 0x985C94 by tu_029) and the
// parser of RecommendedDrivers.txt, which VideoDriverCheck_guess::LoadRecommended_guess (tu_030) reads at
// start-up. RecommendedDrivers_guess is that driver table; DeviceRangeArray_guess (final BarterManager_guess)
// is only its plain array of 24-byte device ranges here, not a barter manager.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <string.h>
#include <stdio.h>
#include "titanium/wnd/CTipWnd.h"

extern "C" int __cdecl _fgetc(FILE* stream);
extern "C" int __cdecl _isspace(int character);
extern "C" int __cdecl _ungetc(int character, FILE* stream);

// EXTERNAL: TITANIUM 0x0064BF88 ??_7PvpCurrency_guess@@6B@
struct PvpCurrency_guess {
    virtual void Slot00_guess();
    int field04;
    int field08;
    union {
        char field0c[8];
        struct {
            int field0c_value;
            int field10;
        };
    };
    union {
        char field14[8];
        struct {
            int field14_value;
            int field18;
        };
    };

    ~PvpCurrency_guess() ;
    PvpCurrency_guess();
    void CopyGlobalFields_guess();
    void InitializeStrings_guess();
};

struct GlobalObject_guess {
    char pad00[0xEB4];
    int valueEB4_guess;
    int valueEB8_guess;
};

struct StringTableView_guess {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::getString
    int getString(unsigned long id, bool* flags);
};

#define g_stringTable_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_globalObject_guess EQ_GLOBAL(GlobalObject_guess*, 0x00905D00)

// Empty PvP currency destructor.
// FUNCTION: TITANIUM 0x004C39DE
PvpCurrency_guess::~PvpCurrency_guess()  {
}

// Currency name, string 5939 ("PvP"); declared void here, but the string is probably returned in eax.
// FUNCTION: TITANIUM 0x004C39F7
void __cdecl GetPvpCurrencyName_guess() {
    g_stringTable_guess->getString(0x1733, 0);
}

// Copies the PvP points from pCharData +0xEB4 (available) and +0xEB8 (total, tu_202's names).
// FUNCTION: TITANIUM 0x004C3A0A
void PvpCurrency_guess::CopyGlobalFields_guess() {
    field04 = g_globalObject_guess->valueEB4_guess;
    field08 = g_globalObject_guess->valueEB8_guess;
}

// Shows context tip 0x30 in the tip window (0x9928E0) when it exists.
// FUNCTION: TITANIUM 0x004C3A27
void __cdecl ShowPvpCurrencyTip_guess() {
    CTipWnd_guess* object = pinstCTipWndCONTEXT_guess;
    if (object != 0) {
        object->selectTip_guess(0x30, 0);
    }
}

// String id of the PvP purchase prompt: `value_guess` is the quantity, `comparison_guess` the price.
// One item: 5933 ("1 PvP point") or 5934 ("points"). Several: 5947 ("points each") at price 1, else
// 5948 ("point each"): singular and plural are swapped there; kept as the client has it.
// FUNCTION: TITANIUM 0x004C3A3B
int __stdcall GetPvpPurchasePromptId_guess(int value_guess, int comparison_guess) {
    if (value_guess == 1) {
        return (comparison_guess != 1) + 0x172d;
    }
    return (comparison_guess != 1) + 0x173b;
}

// All four currency names are string 5939 ("PvP").
// FUNCTION: TITANIUM 0x004C3A63
void PvpCurrency_guess::InitializeStrings_guess() {
    field0c_value = g_stringTable_guess->getString(0x1733, 0);
    field10 = g_stringTable_guess->getString(0x1733, 0);
    field14_value = g_stringTable_guess->getString(0x1733, 0);
    field18 = g_stringTable_guess->getString(0x1733, 0);
}

// PvP currency holder constructor: +4, +8 and the two 8-byte count blocks zeroed (made at 0x00985C94).
// FUNCTION: TITANIUM 0x004C3AB3
PvpCurrency_guess::PvpCurrency_guess() {
    field04 = 0;
    field08 = 0;
    memset(field0c, 0, 8);
    memset(field14, 0, 8);
}

// Skips whitespace in `stream`, putting back the first other character.
// FUNCTION: TITANIUM 0x004C3AE5
void __stdcall SkipWhitespace_guess(FILE* stream) {
    int character = _fgetc(stream);
    while (character != -1 && _isspace(character)) {
        character = _fgetc(stream);
    }
    if (character != -1) {
        _ungetc(character, stream);
    }
}

// Reads up to and including the next newline (or EOF).
// FUNCTION: TITANIUM 0x004C3B2C
// @early-stop: budget, structural ndiff=3
void __stdcall ClearLine_guess(FILE* stream) {
    int character = _fgetc(stream);
    while (character != -1) {
        if (character == '\n') {
            break;
        }
        character = _fgetc(stream);
    }
}

struct E18_guess {
    char bytes[0x18];
};

struct Throw_guess {
    // EXTERNAL: TITANIUM 0x00405492 Throw_guess::Fail
    __declspec(noreturn) void Fail();
};

struct DeviceRangeArray_guess : Throw_guess {
    int count;
    E18_guess* items;
    int capacity;
    unsigned char state;

    E18_guess& Get(int index);
    void Reserve_guess(int requested);
    void ReserveDoubled_guess(int requested);
    void Set_guess(int index, const E18_guess& value);
    DeviceRangeArray_guess* AssignFrom_guess(const DeviceRangeArray_guess& other);
    DeviceRangeArray_guess(const DeviceRangeArray_guess& other);

    // EXTERNAL: TITANIUM 0x0050F3F6 DeviceRangeArray_guess::Reset_guess
    void Reset_guess();
};

struct Record_guess {
    int field00_guess;
    CXStr field04_guess;
    DeviceRangeArray_guess field08_guess;

    // EXTERNAL: TITANIUM 0x004C3DDD Record_guess::Record_guess
    Record_guess();
    // EXTERNAL: TITANIUM 0x00445E51 Record_guess::~Record_guess
    ~Record_guess();
    // EXTERNAL: TITANIUM 0x00445E65 Record_guess::VectorDeletingDestructor_guess
    void VectorDeletingDestructor_guess(unsigned int flags);
    Record_guess(const Record_guess& other);
    Record_guess* AssignFrom_guess(const Record_guess& other);
};

struct RecordTempRef_guess {
    int value_guess;

    // EXTERNAL: TITANIUM 0x004482FB RecordTempRef_guess::Clear_guess
    void Clear_guess();
};

struct RecordTempCollection_guess {
    int count_guess;
    Record_guess* items_guess;
    int capacity_guess;
    unsigned char state_guess;

    // EXTERNAL: TITANIUM 0x0050F3F6 RecordTempCollection_guess::Reset_guess
    void Reset_guess();
};

struct RecordTemp_guess {
    int field00_guess;
    RecordTempRef_guess field04_guess;
    RecordTempCollection_guess field08_guess;

    RecordTemp_guess() {
        field04_guess.value_guess = 0;
        field08_guess.count_guess = 0;
        field08_guess.items_guess = 0;
        field08_guess.capacity_guess = 0;
        field08_guess.state_guess = 1;
    }

    ~RecordTemp_guess() {
        field08_guess.Reset_guess();
        field04_guess.Clear_guess();
    }
};

struct E18Values_guess {
    unsigned int low_guess;
    unsigned int high_guess;
    unsigned int values_guess[4];
};

// by-value copy of a record, destroyed inline
struct RecordCopy_guess {
    int field00_guess;
    RecordTempRef_guess field04_guess;
    DeviceRangeArray_guess field08_guess;

    // EXTERNAL: TITANIUM 0x004C3D96 RecordCopy_guess::RecordCopy_guess
    RecordCopy_guess(const Record_guess& other);
    ~RecordCopy_guess() {
        field08_guess.Reset_guess();
        field04_guess.Clear_guess();
    }
};

struct RecommendedDrivers_guess {
    int count_guess;
    Record_guess* items_guess;
    int capacity_guess;
    unsigned char state_guess;

    unsigned char FindValue_guess(int key_guess, unsigned int value_guess, int valueIndex_guess,
        unsigned int* outputValue_guess, char** outputText_guess);

    void ReserveDoubled_guess(int requested);
    void Set_guess(int index, const Record_guess& value);
    int ReadChar_guess(FILE* stream);
    int PeekChar_guess(FILE* stream);
    unsigned char ReadPayload_guess(FILE* stream, unsigned int* values);
    unsigned char ReadValues_guess(FILE* stream, unsigned int* values);
    void SkipLine_guess(FILE* stream);
    unsigned char ReadRecord_guess(FILE* stream, Record_guess* record);
    void Load_guess(const char* path);
};

// Device range `index` (24 bytes) of the RecommendedDrivers.txt table; out of range fails and traps.
// FUNCTION: TITANIUM 0x004C3B3E
E18_guess& DeviceRangeArray_guess::Get(int index) {
    if (index < count && index >= 0 && items != 0) {
        return items[index];
    }
    Fail();
    __debugbreak();
}

// EXTERNAL: TITANIUM 0x0060E985 operator_new
void* __cdecl operator_new(unsigned int size);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

// EXTERNAL: TITANIUM 0x0060D682 _free
void __cdecl _free(void* memory);

// Grows the array to exactly `requested` entries; on allocation failure it is emptied and `state` 0
// marks it bad.
// FUNCTION: TITANIUM 0x004C3B60
void DeviceRangeArray_guess::Reserve_guess(int requested) {
    E18_guess* allocated;
    int i;
    if (requested != 0 && (requested > count || items == 0)) {
        allocated = (E18_guess*)operator_new(requested * 0x18);
        if (allocated != 0) {
            if (items != 0) {
                i = 0;
                if (i < count) {
                    do {
                        allocated[i] = items[i];
                        ++i;
                    } while (i < count);
                }
            }
            _free(items);
            items = allocated;
            capacity = requested;
        } else {
            _free(items);
            items = 0;
            capacity = 0;
            state = 0;
        }
    }
}

// Array assignment: empties this one, then copies the count and every device range of `other`.
// FUNCTION: TITANIUM 0x004C3BE4
DeviceRangeArray_guess* DeviceRangeArray_guess::AssignFrom_guess(const DeviceRangeArray_guess& other) {
    if (this != &other) {
        Reset_guess();
        if (other.count != 0) {
            Reserve_guess(other.count);
            if (items != 0) {
                int i = 0;
                if (i < other.count) {
                    do {
                        items[i] = other.items[i];
                        ++i;
                    } while (i < other.count);
                }
            }
            count = other.count;
        }
    }
    return this;
}

// Like Reserve_guess, but allocates 2 * `requested` + 8 entries to amortise appends.
// FUNCTION: TITANIUM 0x004C3C38
void DeviceRangeArray_guess::ReserveDoubled_guess(int requested) {
    E18_guess* allocated;
    int i;
    if (requested != 0 && (requested > capacity || items == 0)) {
        allocated = (E18_guess*)operator_new((requested * 2 + 8) * sizeof(E18_guess));
        if (allocated != 0) {
            if (items != 0) {
                i = 0;
                if (i < count) {
                    do {
                        allocated[i] = items[i];
                        ++i;
                    } while (i < count);
                }
            }
            _free(items);
            items = allocated;
            capacity = requested * 2 + 8;
        } else {
            _free(items);
            items = 0;
            capacity = 0;
            state = 0;
        }
    }
}

// Next non-blank character.
// FUNCTION: TITANIUM 0x004C3CC2
int RecommendedDrivers_guess::ReadChar_guess(FILE* stream) {
    SkipWhitespace_guess(stream);
    return _fgetc(stream);
}

// Array copy constructor: every device range of `other`.
// FUNCTION: TITANIUM 0x004C3CD8
DeviceRangeArray_guess::DeviceRangeArray_guess(const DeviceRangeArray_guess& other) {
    items = 0;
    count = 0;
    capacity = 0;
    if (other.count != 0) {
        Reserve_guess(other.count);
        if (items != 0) {
            int i = 0;
            if (i < other.count) {
                do {
                    items[i] = other.items[i];
                    ++i;
                } while (i < other.count);
            }
        }
        count = other.count;
    }
}

// Stores `value` at `index`, growing the array (and count) when `index` is past the end.
// FUNCTION: TITANIUM 0x004C3D2D
void DeviceRangeArray_guess::Set_guess(int index, const E18_guess& value) {
    if (index >= 0) {
        if (index >= count) {
            ReserveDoubled_guess(index + 1);
            if (items != 0) {
                count = index + 1;
            }
        }
        if (items != 0) {
            items[index] = value;
        }
    }
}

// Driver record assignment: the dword at +0, the text at +4 and the device range array at +8.
// FUNCTION: TITANIUM 0x004C3D6B
Record_guess* Record_guess::AssignFrom_guess(const Record_guess& other) {
    field00_guess = other.field00_guess;
    field04_guess = other.field04_guess;
    field08_guess.AssignFrom_guess(other.field08_guess);
    return this;
}

// Driver record copy constructor: the dword at +0, the text at +4 and the device range array at +8.
// FUNCTION: TITANIUM 0x004C3D96
Record_guess::Record_guess(const Record_guess& other)
    : field00_guess(other.field00_guess),
      field04_guess(other.field04_guess),
      field08_guess(other.field08_guess) {
}

// Next non-blank character, left in the stream.
// FUNCTION: TITANIUM 0x004C3DF2
int RecommendedDrivers_guess::PeekChar_guess(FILE* stream) {
    int character = ReadChar_guess(stream);
    _ungetc(character, stream);
    return character;
}

// Grows the driver record array to 2 * requested + 8, assigning the live records over; if the allocation
// fails the array is freed and left empty.
// FUNCTION: TITANIUM 0x004C3E10
void RecommendedDrivers_guess::ReserveDoubled_guess(int requested) {
    Record_guess* allocated;
    int i;
    if (requested != 0 && (requested > capacity_guess || items_guess == 0)) {
        allocated = new Record_guess[requested * 2 + 8];
        if (allocated != 0) {
            if (items_guess != 0) {
                i = 0;
                if (i < count_guess) {
                    do {
                        allocated[i].AssignFrom_guess(items_guess[i]);
                        ++i;
                    } while (i < count_guess);
                }
            }
            if (items_guess != 0) {
                items_guess->VectorDeletingDestructor_guess(3);
            }
            items_guess = allocated;
            capacity_guess = requested * 2 + 8;
        } else {
            if (items_guess != 0) {
                items_guess->VectorDeletingDestructor_guess(3);
            }
            items_guess = 0;
            capacity_guess = 0;
            state_guess = 0;
        }
    }
}

// Recommended driver for the card: the record with vendor `key_guess` whose device range holds
// `value_guess` gives version slot `valueIndex_guess` (the OS index) and the record's download URL.
// The outer loop doesn't stop on a hit, so with duplicate vendor records the last match wins.
// Each record is copied by value per iteration; that copy is original code.
// FUNCTION: TITANIUM 0x004C3EF3
unsigned char RecommendedDrivers_guess::FindValue_guess(int key_guess, unsigned int value_guess,
    int valueIndex_guess, unsigned int* outputValue_guess, char** outputText_guess) {
    unsigned char found_guess = 0;
    int recordCount_guess = count_guess;
    for (int recordIndex_guess = 0; recordIndex_guess < recordCount_guess; recordIndex_guess++) {
        RecordCopy_guess record_guess((Record_guess&)((DeviceRangeArray_guess*)this)->Get(recordIndex_guess));
        if (record_guess.field00_guess == key_guess) {
            int itemCount_guess = record_guess.field08_guess.count;
            for (int itemIndex_guess = 0; itemIndex_guess < itemCount_guess; itemIndex_guess++) {
                E18Values_guess item_guess = *(E18Values_guess*)&record_guess.field08_guess.Get(itemIndex_guess);
                if (item_guess.low_guess <= value_guess && value_guess <= item_guess.high_guess) {
                    *outputValue_guess = item_guess.values_guess[valueIndex_guess];
                    *outputText_guess = (char*)*(CXStr*)&record_guess.field04_guess;
                    found_guess = 1;
                    break;
                }
            }
        }
    }
    return found_guess;
}

// Parses `{a}`, `{a,b}` or `{a,b,c,d}` into values[2..5], the driver version per OS index (0 Win9x,
// 1 ME, 2 2000, 3 XP/2003; VideoDriverCheck_guess::GetWindowsVersion_guess): one value covers all, two split
// 9x/ME from 2000/XP. Three values, or more than four, fail the entry.
// FUNCTION: TITANIUM 0x004C3FC2
unsigned char RecommendedDrivers_guess::ReadPayload_guess(FILE* stream_guess, unsigned int* values_guess) {
    unsigned char success_guess = 0;
    unsigned int count_guess = 0;
    int parsed_guess[4];
    if (ReadChar_guess(stream_guess) == '{') {
        do {
            fscanf(stream_guess, "%d", &parsed_guess[count_guess]);
            ++count_guess;
            if (PeekChar_guess(stream_guess) != ',') {
                break;
            }
            ReadChar_guess(stream_guess);
        } while (count_guess < 4);
        if (ReadChar_guess(stream_guess) == '}' && count_guess > 0) {
            success_guess = 1;
            switch (count_guess) {
            case 1:
                values_guess[2] = parsed_guess[0];
                values_guess[3] = parsed_guess[0];
                values_guess[4] = parsed_guess[0];
                values_guess[5] = parsed_guess[0];
                break;
            case 2:
                values_guess[2] = parsed_guess[0];
                values_guess[3] = parsed_guess[0];
                values_guess[4] = parsed_guess[1];
                values_guess[5] = parsed_guess[1];
                break;
            case 4:
                values_guess[2] = parsed_guess[0];
                values_guess[3] = parsed_guess[1];
                values_guess[4] = parsed_guess[2];
                values_guess[5] = parsed_guess[3];
                break;
            default:
                success_guess = 0;
                break;
            }
        }
    }
    return success_guess;
}

// SetElementIdx for the driver records (an int, a string and a collection): assigns `value` at `index`
// (0x004C3D6B), first growing the array to 2n + 8 (0x004C3E10) and the length to index + 1 when needed.
// Negative indexes are ignored, and so is the store when the allocation failed.
// FUNCTION: TITANIUM 0x004C408D
void RecommendedDrivers_guess::Set_guess(int index, const Record_guess& value) {
    if (index >= 0) {
        if (index >= count_guess) {
            ReserveDoubled_guess(index + 1);
            if (items_guess != 0) {
                count_guess = index + 1;
            }
        }
        if (items_guess != 0) {
            items_guess[index].AssignFrom_guess(value);
        }
    }
}

// One device entry: `<hex>` or `<hex>-<hex>` (values[0..1], the device-id range, inclusive)
// followed by its version payload. The stream parameter doubles as the scratch for the first id.
// FUNCTION: TITANIUM 0x004C40CB
unsigned char RecommendedDrivers_guess::ReadValues_guess(FILE* stream_guess, unsigned int* values_guess) {
    FILE* file_guess = stream_guess;
    unsigned int second_guess;
    unsigned char result_guess = 0;
    if (fscanf(file_guess, "%x", (unsigned int*)&stream_guess) == 1) {
        if (PeekChar_guess(file_guess) == '-') {
            ReadChar_guess(file_guess);
            fscanf(file_guess, "%x", &second_guess);
        } else {
            second_guess = (unsigned int)stream_guess;
        }
        values_guess[0] = (unsigned int)stream_guess;
        values_guess[1] = second_guess;
        result_guess = ReadPayload_guess(file_guess, values_guess);
    }
    return result_guess;
}

// Skips a ';' comment line. Only 7 bytes sit before ClearLine_guess, so the original probably
// shares that loop; this body is the early-stop approximation.
// FUNCTION: TITANIUM 0x004C3B25
// @early-stop: budget, structural ndiff=11
void RecommendedDrivers_guess::SkipLine_guess(FILE* stream) {
    int character = ReadChar_guess(stream);
    while (character != -1) {
        if (character == '\n') {
            break;
        }
        character = _fgetc(stream);
    }
}

// One record: `<vendor hex> <url> {` then device entries until one fails to parse, then `}`.
// Succeeds only with at least one entry and the closing brace; the name buffer is 512 bytes, unchecked.
// FUNCTION: TITANIUM 0x004C4143
unsigned char RecommendedDrivers_guess::ReadRecord_guess(FILE* stream, Record_guess* record) {
    unsigned char result = 0;
    while (PeekChar_guess(stream) == ';') {
        SkipLine_guess(stream);
    }
    int id;
    char name[512];
    // %s has no width: a token over 511 characters overflows `name`.
    if (fscanf(stream, "%x %s", &id, name) == 2) {
        record->field00_guess = id;
        record->field04_guess = name;
        if (ReadChar_guess(stream) == '{') {
            bool more = true;
            do {
                unsigned int values[6];
                if (ReadValues_guess(stream, values)) {
                    record->field08_guess.Set_guess(record->field08_guess.count, *(E18_guess*)values);
                    result = 1;
                } else {
                    more = false;
                }
            } while (more);
            if (ReadChar_guess(stream) != '}') {
                result = 0;
            }
        }
    }
    return result;
}

// Appends every record of `path` until the first malformed one; a missing file leaves the table empty.
// FUNCTION: TITANIUM 0x004C4228
// @early-stop: budget, diff ndiff=3
void RecommendedDrivers_guess::Load_guess(const char* path) {
    FILE* file = fopen(path, "r");
    if (file != 0) {
        bool more = true;
        do {
            RecordTemp_guess record;
            if (ReadRecord_guess(file, (Record_guess*)&record)) {
                Set_guess(count_guess, *(Record_guess*)&record);
            } else {
                more = false;
            }
        } while (more);
        fclose(file);
    }
}

