// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 24: a hint from compare/tumap.py.
// The conversation journal: NPCs you have talked to, each with dated entries (where it was said, which
// category), saved as <name>.hdr (EQJOURNAL, +CAT/+NPC/+ENTRY blocks) plus <name>.txt (one line of text per
// entry, keyed by FUN_0042e3b4_guess's hash). Journal_guess is the journal, JournalNpc_guess
// one NPC (name, zone id, 0x54 bytes), JournalEntry_guess one entry; the global 0x79DC44 maps text hashes
// to the text. The journal log strings and tu_177's JournalEntry_guess confirm it.
#include "titanium/eqaddr.h"
#include <string.h>
#include <stdio.h>

struct Lookup_004ff9c9_guess {
    // EXTERNAL: TITANIUM 0x004FF9C9 Lookup_004ff9c9_guess::Find_guess
    int* Find_guess(unsigned int key);
    // EXTERNAL: TITANIUM 0x00447C66 Lookup_004ff9c9_guess::Insert_guess
    void Insert_guess(void** value, unsigned int key);
};

#define g_journalText_guess EQ_GLOBAL(Lookup_004ff9c9_guess*, 0x0079DC44)

struct Object_0042e43a_guess {
    char flag_0000_guess;
    char unknown_0001_guess[0x3f];
    int values_0040_guess[5];

    Object_0042e43a_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 FreeAt60D0D5_guess
void __cdecl FreeAt60D0D5_guess(void* value);

// EXTERNAL: TITANIUM 0x0060D682 FreeAt60D682_guess
void __cdecl FreeAt60D682_guess(void* value);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

struct Object_0042e4ab_guess {
    char unknown_0000_guess[0x48];
    int capacity_0048_guess;
    int count_004c_guess;
    void** values_0050_guess;

    void Clear_guess();
    void Grow_guess();
};

struct Object_0042e972_guess {
    char unknown_0000_guess[0x80c];
    int value_080c_guess;

    int GetValue_guess();
};

struct JournalEntry_guess {
    int timestamp_0000_guess;
    int textHash_0004_guess;
    int x_0008_guess;
    int y_000c_guess;
    int z_0010_guess;
    int category_0014_guess;
};

struct JournalNpc_guess {
    char unknown_0000_guess[0x44];
    int maximum_0044_guess;
    char unknown_0048_guess[4];
    int count_004c_guess;
    JournalEntry_guess** records_0050_guess;

    JournalEntry_guess* GetRecordAtIndex_guess(int index);
    JournalEntry_guess* FindEntryByTextHash_guess(int value);
    JournalEntry_guess* FindEntryByCategory_guess(int value, int start);
    int AddRecord_guess(int rank_guess, float x_guess, float y_guess, float z_guess, int key_guess, int extra_guess);
    int AddRecordByName_guess(int rank_guess, float x_guess, float y_guess, float z_guess, const char* name_guess, int extra_guess);
    int FindRecordByTextFromIndex_guess(const char* text, char copied, int start);
    int RemoveRecordAtIndex_guess(int index);
    int RemoveRecordByValue_guess(int value);
    void ReplaceCategory_guess(int oldValue, int newValue);
    void RecalculateMaximum_guess();
    int ReadEntryFromFile_guess(FILE* file);
};

struct Record_0042e789_guess {
    char text_0000_guess[0x40];
    int type_0040_guess;
};

struct JournalCategory_guess;

struct Journal_guess {
    char unknown_0000_guess[0x800];
    int* values_0800_guess;
    int capacity_0804_guess;
    int count_0808_guess;
    int* values_080c_guess;
    int capacity_0810_guess;
    int count_0814_guess;

    Journal_guess();
    void GrowValues_guess();
    void GrowCategories_guess();
    JournalCategory_guess* GetOrCreateCategory_guess(int key);
    JournalCategory_guess* SetCategory_guess(char* first, char* second, int key);
    int GetValueAtIndex_guess(int index);
    Record_0042e789_guess* FindByTextAndType_guess(const char* text, int type);
    int RemoveByTextAndType_guess(const char* text, int type);
    void RemoveCategory_guess(int key);
    void Clear_guess();
    void ClearThunk_guess();
    void ReadCategoryFromFile_guess(FILE* file);
    int ReadNpcFromFile_guess(FILE* file);
    int AddNpcRecordAndEntry_guess(char* name, int key, int rank, float x, float y, float z, const char* entryName, int extra);
    int GetOrAddNpc_guess(char* name, int key);
    int SaveJournal_guess(const char* fileName);
    int LoadJournal_guess(const char* directory_guess);
};

struct Record_0042e8f3_guess {
    int key_0000_guess;
};

struct JournalCategory_guess {
    int key_0000_guess;
    char name_0004_guess;
    char unknown_0005_guess[0xf];
    char description_0014_guess;
    char unknown_0015_guess[0xff];
};

struct Record_0042e929_guess {
    char unknown_0000_guess[4];
    char text_0004_guess[1];
};

struct Object_0042e8f3_guess {
    char unknown_0000_guess[0x80c];
    Record_0042e8f3_guess** records_080c_guess;
    char unknown_0810_guess[4];
    int count_0814_guess;

    int NextFreeCategoryId_guess();
    Record_0042e8f3_guess* FindCategoryById_guess(int key);
    Record_0042e929_guess* FindCategoryByName_guess(char* text);
};

class String_0042e3d9_guess {
public:
    int value_0000_guess;

    String_0042e3d9_guess() : value_0000_guess(0) {
    }
    // EXTERNAL: TITANIUM 0x00571E00 ??0String_0042e3d9_guess@@QAE@PBD@Z
    String_0042e3d9_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00407D68 ??0String_0042e3d9_guess@@QAE@ABV0@@Z
    String_0042e3d9_guess(const String_0042e3d9_guess& source);
    // EXTERNAL: TITANIUM 0x00572C10 String_0042e3d9_guess::Append_guess
    void Append_guess(const String_0042e3d9_guess& text);
    // EXTERNAL: TITANIUM 0x00572300 String_0042e3d9_guess::CopyTo_guess
    char* CopyTo_guess();
    // EXTERNAL: TITANIUM 0x00571F70 ??4String_0042e3d9_guess@@QAEAAV0@ABV0@@Z
    String_0042e3d9_guess& operator=(const String_0042e3d9_guess& source);
    // EXTERNAL: TITANIUM 0x00571D00 String_0042e3d9_guess::FreeRep
    void FreeRep(int value);

    ~String_0042e3d9_guess() {
        if (value_0000_guess != 0) {
            FreeRep(value_0000_guess);
        }
    }
};

// EXTERNAL: TITANIUM 0x0060ED40 strcmp_guess
int __cdecl strcmp_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060E3A3 atol
long __cdecl atol(const char* text);

// EXTERNAL: TITANIUM 0x00574720 CopyText_00574720_guess
void __cdecl CopyText_00574720_guess(const char* source, char* destination, int count);

// EXTERNAL: TITANIUM 0x0060E590 CompareText_0060E590_guess
int __cdecl CompareText_0060E590_guess(const char* first, const char* second);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// Hash of a journal text line (case-sensitive; the key of the 0x79DC44 table). tu_005 has an
// upper-casing twin of the same formula.
// FUNCTION: TITANIUM 0x0042E3B4
int __cdecl HashString_guess(const char* text) {
    int hash = 0;
    char character = *text;
    while (character != 0) {
        hash = (hash >> 26) ^ (hash * 31 + (int)character);
        ++text;
        character = *text;
    }
    return hash;
}

// `first` + `second` as a new string (tu_106 names this VA Concat_guess).
// FUNCTION: TITANIUM 0x0042E3D9
String_0042e3d9_guess __cdecl FUN_0042e3d9_guess(
    const char* first, const String_0042e3d9_guess& second) {
    String_0042e3d9_guess result(first);
    result.Append_guess(second);
    return result;
}

// Empty NPC: clears the name and the five ints at +0x40 (zone id, latest time, entry array).
// FUNCTION: TITANIUM 0x0042E43A
Object_0042e43a_guess::Object_0042e43a_guess() {
    flag_0000_guess = 0;
    values_0040_guess[0] = 0;
    values_0040_guess[1] = 0;
    values_0040_guess[2] = 0;
    values_0040_guess[3] = 0;
    values_0040_guess[4] = 0;
}

// Grows the NPC's entry array: 10 slots, then doubling.
// FUNCTION: TITANIUM 0x0042E450
void Object_0042e4ab_guess::Grow_guess() {
    int capacity = capacity_0048_guess;
    if (count_004c_guess < capacity) {
        return;
    }
    int newCapacity = 10;
    if (capacity > 0) {
        newCapacity = capacity * 2;
    }
    int size = newCapacity * 4;
    void** values = (void**)operator new[](size);
    memset(values, 0, size);
    for (int index = 0; index < count_004c_guess; ++index) {
        values[index] = values_0050_guess[index];
    }
    FreeAt60D682_guess(values_0050_guess);
    values_0050_guess = values;
    capacity_0048_guess = newCapacity;
}

// Empties a journal NPC record's entry list: frees every entry pointer in the array (+0x50), then the
// array itself, and zeroes the count (+0x4C) and capacity (+0x48).
// FUNCTION: TITANIUM 0x0042E4AB
void Object_0042e4ab_guess::Clear_guess() {
    int index = 0;
    if (count_004c_guess > 0) {
        do {
            FreeAt60D0D5_guess(values_0050_guess[index]);
            ++index;
        } while (index < count_004c_guess);
    }
    FreeAt60D682_guess(values_0050_guess);
    count_004c_guess = 0;
    capacity_0048_guess = 0;
}

// NPC journal entry `index`, or 0 when out of range; the NPC journal window reads entries with it.
// FUNCTION: TITANIUM 0x0042E4DC
JournalEntry_guess* JournalNpc_guess::GetRecordAtIndex_guess(int index) {
    JournalEntry_guess* result = 0;
    if (index >= 0 && index < count_004c_guess) {
        result = records_0050_guess[index];
    }
    return result;
}

// First entry whose text hash (+4) is `value`, or 0.
// FUNCTION: TITANIUM 0x0042E4F4
JournalEntry_guess* JournalNpc_guess::FindEntryByTextHash_guess(int value) {
    int count = count_004c_guess;
    JournalEntry_guess* result = 0;
    int index = 0;
    if (count > 0) {
        JournalEntry_guess** current = records_0050_guess;
        do {
            if ((*current)->textHash_0004_guess == value) {
                result = records_0050_guess[index];
                break;
            }
            ++index;
            ++current;
        } while (index < count);
    }
    return result;
}

// First entry from `start` in category `value` (+0x14), or 0.
// FUNCTION: TITANIUM 0x0042E525
JournalEntry_guess* JournalNpc_guess::FindEntryByCategory_guess(int value, int start) {
    JournalEntry_guess* result = 0;
    int count = count_004c_guess;
    int index = start;
    if (start < count) {
        JournalEntry_guess** records = records_0050_guess;
        JournalEntry_guess** current = records + index;
        do {
            if ((*current)->category_0014_guess == value) {
                result = records[index];
                break;
            }
            ++index;
            ++current;
        } while (index < count);
    }
    return result;
}

// Adds an entry keyed by text hash `key_guess`; a repeat keeps one entry and only takes the new position
// when `rank_guess` is newer. `rank_guess` is probably the time the line was heard (saved as %08X);
// +0x44 tracks the NPC's latest. Returns 1 when a new entry was made.
// FUNCTION: TITANIUM 0x0042E55B
int JournalNpc_guess::AddRecord_guess(int rank_guess, float x_guess, float y_guess, float z_guess, int key_guess, int extra_guess) {
    JournalEntry_guess* record = FindEntryByTextHash_guess(key_guess);
    int result;
    if (record == 0) {
        record = new JournalEntry_guess();
        record->timestamp_0000_guess = rank_guess;
        record->x_0008_guess = (int)x_guess;
        record->y_000c_guess = (int)y_guess;
        record->z_0010_guess = (int)z_guess;
        record->category_0014_guess = extra_guess;
        record->textHash_0004_guess = key_guess;
        ((Object_0042e4ab_guess*)this)->Grow_guess();
        records_0050_guess[count_004c_guess++] = record;
        result = 1;
    } else {
        if (rank_guess > record->timestamp_0000_guess) {
            record->x_0008_guess = (int)x_guess;
            record->y_000c_guess = (int)y_guess;
            record->z_0010_guess = (int)z_guess;
            record->timestamp_0000_guess = rank_guess;
        }
        result = 0;
    }
    if (maximum_0044_guess < record->timestamp_0000_guess) {
        maximum_0044_guess = record->timestamp_0000_guess;
    }
    return result;
}

// Moves every entry in category `oldValue` to `newValue` (-1 when the category is deleted).
// FUNCTION: TITANIUM 0x0042E613
void JournalNpc_guess::ReplaceCategory_guess(int oldValue, int newValue) {
    for (int index = 0; index < count_004c_guess; ++index) {
        JournalEntry_guess* record = records_0050_guess[index];
        if (record->category_0014_guess == oldValue) {
            record->category_0014_guess = newValue;
        }
    }
}

// Recomputes the NPC's latest time (+0x44) as the highest entry time.
// FUNCTION: TITANIUM 0x0042E63B
void JournalNpc_guess::RecalculateMaximum_guess() {
    int maximum = 0;
    for (int index = 0; index < count_004c_guess; ++index) {
        int value = records_0050_guess[index]->timestamp_0000_guess;
        if (value > maximum) {
            maximum = value;
        }
    }
    maximum_0044_guess = maximum;
}

// Journal ctor: empties the NPC list (+0x800) and the category list (+0x80C).
// FUNCTION: TITANIUM 0x0042E660
Journal_guess::Journal_guess() {
    values_0800_guess = 0;
    capacity_0804_guess = 0;
    count_0808_guess = 0;
    values_080c_guess = 0;
    capacity_0810_guess = 0;
    count_0814_guess = 0;
}

// Grows the NPC list: 100 slots, then doubling.
// FUNCTION: TITANIUM 0x0042E689
void Journal_guess::GrowValues_guess() {
    int capacity = capacity_0804_guess;
    if (count_0808_guess < capacity) {
        return;
    }
    int newCapacity = 100;
    if (capacity > 0) {
        newCapacity = capacity * 2;
    }
    int size = newCapacity * 4;
    int* values = (int*)operator new[](size);
    memset(values, 0, size);
    for (int index = 0; index < count_0808_guess; ++index) {
        values[index] = values_0800_guess[index];
    }
    capacity_0804_guess = newCapacity;
    FreeAt60D682_guess(values_0800_guess);
    values_0800_guess = values;
}

// Grows the category list: 32 slots, then doubling.
// FUNCTION: TITANIUM 0x0042E6FA
void Journal_guess::GrowCategories_guess() {
    int capacity = capacity_0810_guess;
    if (count_0814_guess < capacity) {
        return;
    }
    int newCapacity = 32;
    if (capacity > 0) {
        newCapacity = capacity * 2;
    }
    int size = newCapacity * 4;
    int* values = (int*)operator new[](size);
    memset(values, 0, size);
    for (int index = 0; index < count_0814_guess; ++index) {
        values[index] = values_080c_guess[index];
    }
    capacity_0810_guess = newCapacity;
    FreeAt60D682_guess(values_080c_guess);
    values_080c_guess = values;
}

// NPC `index` of the journal, or 0 when out of range; the NPC journal window walks the NPCs with it.
// FUNCTION: TITANIUM 0x0042E76B
int Journal_guess::GetValueAtIndex_guess(int index) {
    int result = 0;
    if (index >= 0 && index < count_0808_guess) {
        result = values_0800_guess[index];
    }
    return result;
}

// The NPC with this exact name in zone `type`, or 0.
// FUNCTION: TITANIUM 0x0042E789
Record_0042e789_guess* Journal_guess::FindByTextAndType_guess(const char* text, int type) {
    Record_0042e789_guess* result = 0;
    int index = 0;
    if (count_0808_guess > 0) {
        do {
            Record_0042e789_guess* record = (Record_0042e789_guess*)values_0800_guess[index];
            if (record->type_0040_guess == type && strcmp_guess(text, record->text_0000_guess) == 0) {
                result = record;
                break;
            }
            ++index;
        } while (index < count_0808_guess);
    }
    return result;
}

// Finds or adds the NPC (`name`, zone `key`); returns it.
// FUNCTION: TITANIUM 0x0042E7D7
int Journal_guess::GetOrAddNpc_guess(char* name, int key) {
    Record_0042e789_guess* result = FindByTextAndType_guess(name, key);
    if (result == 0) {
        result = (Record_0042e789_guess*)new Object_0042e43a_guess;
        // Only byte 0 of the name was cleared: a 63+ char name is left unterminated.
        strncpy(result->text_0000_guess, name, 0x3f);
        result->type_0040_guess = key;
        GrowValues_guess();
        values_0800_guess[count_0808_guess] = (int)result;
        ++count_0808_guess;
    }
    return (int)result;
}

// Smallest category id not in use (gives up at 1000000).
// FUNCTION: TITANIUM 0x0042E83E
int Object_0042e8f3_guess::NextFreeCategoryId_guess() {
    int key = 0;
    do {
        int index = 0;
        if (count_0814_guess <= 0) {
            return key;
        }
        Record_0042e8f3_guess** current = records_080c_guess;
        do {
            if (key == (*current)->key_0000_guess) {
                ++key;
                break;
            }
            ++index;
            ++current;
            if (index >= count_0814_guess) {
                return key;
            }
        } while (index < count_0814_guess);
    } while (key < 1000000);
    return key;
}

// Deletes category `key`: drops it from the list and moves its entries to category -1. The record
// itself is not freed (see the early stop).
// FUNCTION: TITANIUM 0x0042E871
// @early-stop: budget, structural ndiff=45
void Journal_guess::RemoveCategory_guess(int key) {
    int index = 0;
    int* slot = values_080c_guess;
    if (count_0814_guess > 0) {
        do {
            if (*(int*)*slot == key) {
                if (index < 0) {
                    return;
                }
                for (; index < count_0814_guess - 1; ++index) {
                    values_080c_guess[index] = values_080c_guess[index + 1];
                }
                --count_0814_guess;
                for (int i = 0; i < count_0808_guess; ++i) {
                    ((JournalNpc_guess*)values_0800_guess[i])->ReplaceCategory_guess(key, -1);
                }
                return;
            }
            ++index;
            ++slot;
        } while (index < count_0814_guess);
    }
}

// Category by id, or 0. This view's +0x80C/+0x814 are the journal's category list.
// FUNCTION: TITANIUM 0x0042E8F3
Record_0042e8f3_guess* Object_0042e8f3_guess::FindCategoryById_guess(int key) {
    int count = count_0814_guess;
    Record_0042e8f3_guess* result = 0;
    int index = 0;
    if (count > 0) {
        Record_0042e8f3_guess** current = records_080c_guess;
        do {
            if ((*current)->key_0000_guess == key) {
                result = records_080c_guess[index];
                break;
            }
            ++index;
            ++current;
        } while (index < count);
    }
    return result;
}

// Category by name (+4), or 0.
// FUNCTION: TITANIUM 0x0042E929
Record_0042e929_guess* Object_0042e8f3_guess::FindCategoryByName_guess(char* text) {
    Record_0042e929_guess* result = 0;
    int index = 0;
    if (count_0814_guess > 0) {
        do {
            if (strcmp_guess(((Record_0042e929_guess*)records_080c_guess[index])->text_0004_guess, text) == 0) {
                result = (Record_0042e929_guess*)records_080c_guess[index];
                break;
            }
            ++index;
        } while (index < count_0814_guess);
    }
    return result;
}

// The journal's category array (+0x80C); the category window reads it.
// FUNCTION: TITANIUM 0x0042E972
int Object_0042e972_guess::GetValue_guess() {
    return value_080c_guess;
}

// Reads one +ENTRY block body: time (hex), x, y, z, category, text hash (hex), then skips to -ENTRY.
// -1 at end of file, else AddRecord_guess's result.
// FUNCTION: TITANIUM 0x0042E979
int JournalNpc_guess::ReadEntryFromFile_guess(FILE* file) {
    char line[0x800];
    int rank = 0;
    int key = 0;
    float x;
    float y;
    float z;
    int extra;
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    sscanf(line, "%x", &rank);
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    x = (float)atol(line);
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    y = (float)atol(line);
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    z = (float)atol(line);
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    extra = atol(line);
    if (file->_flag & 0x10) {
        return -1;
    }
    fgets(line, 0x7ff, file);
    sscanf(line, "%x", &key);
    int result = AddRecord_guess(rank, x, y, z, key, extra);
    while ((file->_flag & 0x10) == 0) {
        fgets(line, 0x7ff, file);
        if (strncmp(line, "-ENTRY", 6) == 0) {
            return result;
        }
    }
    return -1;
}

// Reads one +NPC block body: name and zone id, then skips to -NPC. The name stays "ErrorNPC" when the
// line is missing.
// FUNCTION: TITANIUM 0x0042EB29
int Journal_guess::ReadNpcFromFile_guess(FILE* file) {
    int value = 0;
    char line[0x800];
    char name[0x40];
    strcpy(name, "ErrorNPC");
    if (file->_flag & 0x10) {
        return 0;
    }
    fgets(line, 0x7ff, file);
    sscanf(line, "%[^\n", name);
    if (file->_flag & 0x10) {
        return 0;
    }
    fgets(line, 0x7ff, file);
    sscanf(line, "%d", &value);
    while ((file->_flag & 0x10) == 0) {
        fgets(line, 0x7ff, file);
        if (strncmp(line, "-NPC", 4) == 0) {
            break;
        }
    }
    return GetOrAddNpc_guess(name, value);
}

struct Object_0042f092_guess {
    int values_0000_guess[4];

    // EXTERNAL: TITANIUM 0x005544AF Object_0042f092_guess::InitializeBase_guess
    void InitializeBase_guess(int value);
    // EXTERNAL: TITANIUM 0x004C9745 Object_0042f092_guess::ReleaseData_guess
    void ReleaseData_guess();
    // EXTERNAL: TITANIUM 0x00447C66 Object_0042f092_guess::Add_guess
    void Add_guess(int* result, int key);

    Object_0042f092_guess* Initialize_guess(int value);
};

// Hash table setup; `value` is probably the bucket count (1024 for the journal text).
// FUNCTION: TITANIUM 0x0042F092
Object_0042f092_guess* Object_0042f092_guess::Initialize_guess(int value) {
    values_0000_guess[0] = 0;
    values_0000_guess[1] = 0;
    values_0000_guess[2] = 0;
    values_0000_guess[3] = 0;
    InitializeBase_guess(value);
    return this;
}

struct HashEntry_0042ec1a_guess {
    void* value_0000_guess;
    unsigned int hash_0004_guess;
    HashEntry_0042ec1a_guess* next_0008_guess;
};

struct HashTable_0042ec1a_guess {
    HashEntry_0042ec1a_guess** buckets_0000_guess;
    int bucketCount_0004_guess;

    // EXTERNAL: TITANIUM 0x004466FA HashTable_0042ec1a_guess::First_guess
    HashEntry_0042ec1a_guess* First_guess();
    HashEntry_0042ec1a_guess* Next_guess(HashEntry_0042ec1a_guess* entry);

    // EXTERNAL: TITANIUM 0x004C9745 HashTable_0042ec1a_guess::Cleanup_guess
    void Cleanup_guess();
};

struct ExportCategory_0042f146_guess {
    int value_0000_guess;
    char text_0004_guess[0x10];
    char text_0014_guess[1];
};

struct ExportNpc_0042f146_guess {
    char name_0000_guess[0x40];
    int value_0040_guess;
    char unknown_0044_guess[8];
    int count_004c_guess;
};

// EXTERNAL: TITANIUM 0x0040552D GetLanguageCodePage_guess
char* __cdecl GetLanguageCodePage_guess(char* root, char* path);

// EXTERNAL: TITANIUM 0x005749F0 FinalizePath_005749f0_guess
void __cdecl FinalizePath_005749f0_guess(char* path, char* copiedPath, char* output, int capacity);

// Next entry of the hash walk: the chain, then the next non-empty bucket.
// FUNCTION: TITANIUM 0x0042EC1A
HashEntry_0042ec1a_guess* HashTable_0042ec1a_guess::Next_guess(HashEntry_0042ec1a_guess* entry) {
    int index = entry->hash_0004_guess % bucketCount_0004_guess;
    HashEntry_0042ec1a_guess* next = entry->next_0008_guess;
    if (next) {
        return next;
    }
    int scan = index + 1;
    if (index + 1 < bucketCount_0004_guess) {
        for (; scan < bucketCount_0004_guess; ++scan) {
            next = buckets_0000_guess[scan];
            if (next) {
                return next;
            }
        }
    }
    return 0;
}

// Journal text for a hash, or 0.
// FUNCTION: TITANIUM 0x0042EC50
int __cdecl GetJournalText_guess(unsigned int key) {
    int result = 0;
    int* value = g_journalText_guess->Find_guess(key);
    if (value != 0) {
        result = *value;
    }
    return result;
}

// Index of the first entry from `start` whose text contains `text`, or -1. Unless `copied`, the search
// text goes through 0x574720 into a 127-char buffer first; each entry's text is cut to 2047 chars.
// FUNCTION: TITANIUM 0x0042EC6C
int JournalNpc_guess::FindRecordByTextFromIndex_guess(const char* text, char copied, int start) {
    char buffer[2048];
    char temporary[128];
    const char* searchText = text;
    if (copied == 0) {
        CopyText_00574720_guess(searchText, temporary, 0x7f);
        searchText = temporary;
    }
    int index = start;
    while (index < count_004c_guess) {
        int* value = g_journalText_guess->Find_guess((unsigned int)records_0050_guess[index]->textHash_0004_guess);
        if (value != 0) {
            CopyText_00574720_guess((const char*)*value, buffer, 0x7ff);
            if (CompareText_0060E590_guess(buffer, searchText) != 0) {
                return index;
            }
        }
        ++index;
    }
    return -1;
}

// AddRecord_guess by text: stores a copy of the line in the text table if its hash is new. A different
// line with the same hash reuses the stored text.
// FUNCTION: TITANIUM 0x0042ED03
int JournalNpc_guess::AddRecordByName_guess(int rank_guess, float x_guess, float y_guess, float z_guess, const char* name_guess, int extra_guess) {
    int key = HashString_guess(name_guess);
    if (g_journalText_guess->Find_guess(key) == 0) {
        void* copy = operator new[](strlen(name_guess) + 1);
        strcpy((char*)copy, name_guess);
        g_journalText_guess->Insert_guess(&copy, key);
    }
    return AddRecord_guess(rank_guess, x_guess, y_guess, z_guess, key, extra_guess);
}

// Deletes entry `index` and recomputes the NPC's latest time; returns the new count or -1.
// FUNCTION: TITANIUM 0x0042ED7F
int JournalNpc_guess::RemoveRecordAtIndex_guess(int index) {
    int result = -1;
    if (index >= 0 && index < count_004c_guess) {
        JournalEntry_guess* removed = records_0050_guess[index];
        for (int current = index + 1; current < count_004c_guess; ++current) {
            records_0050_guess[current - 1] = records_0050_guess[current];
        }
        records_0050_guess[count_004c_guess - 1] = 0;
        FreeAt60D0D5_guess(removed);
        --count_004c_guess;
        result = count_004c_guess;
    }
    RecalculateMaximum_guess();
    return result;
}

// Deletes the NPC's first entry whose text hash (+4) is `value` (0x0042ED7F); returns the new count, or
// -1 when there is none.
// FUNCTION: TITANIUM 0x0042EDD7
int JournalNpc_guess::RemoveRecordByValue_guess(int value) {
    int result = -1;
    int count = count_004c_guess;
    int index = 0;
    if (count > 0) {
        JournalEntry_guess** current = records_0050_guess;
        do {
            JournalEntry_guess* record = *current;
            if (record->textHash_0004_guess == value) {
                result = RemoveRecordAtIndex_guess(index);
                break;
            }
            ++index;
            ++current;
        } while (index < count);
    }
    return result;
}

// Category `key`, or a new one with the first free id when it is missing or `key` is -1.
// FUNCTION: TITANIUM 0x0042EEDF
JournalCategory_guess* Journal_guess::GetOrCreateCategory_guess(int key) {
    JournalCategory_guess* result = 0;
    if (key != -1) {
        result = (JournalCategory_guess*)((Object_0042e8f3_guess*)this)->FindCategoryById_guess(key);
    }
    if (key == -1 || result == 0) {
        result = new JournalCategory_guess();
        result->name_0004_guess = 0;
        result->description_0014_guess = 0;
        GrowCategories_guess();
        result->key_0000_guess = ((Object_0042e8f3_guess*)this)->NextFreeCategoryId_guess();
        ((JournalCategory_guess**)values_080c_guess)[count_0814_guess] = result;
        ++count_0814_guess;
    }
    return result;
}

// Sets a category's name (15 chars) and description (255 chars), creating it if needed.
// FUNCTION: TITANIUM 0x0042EF4B
JournalCategory_guess* Journal_guess::SetCategory_guess(char* first, char* second, int key) {
    JournalCategory_guess* record = GetOrCreateCategory_guess(key);
    strncpy(&record->name_0004_guess, first, 0xf);
    record->unknown_0005_guess[14] = 0;
    strncpy(&record->description_0014_guess, second, 0xff);
    record->unknown_0015_guess[254] = 0;
    return record;
}

// Reads one +CAT block body: id, name, description, each line without its newline.
// FUNCTION: TITANIUM 0x0042EF8C
void Journal_guess::ReadCategoryFromFile_guess(FILE* file) {
    char line[0x800];
    char text[0x100];
    char name[0x10];
    if ((file->_flag & 0x10) == 0) {
        fgets(line, 0x7ff, file);
        int key = atol(line);
        if ((file->_flag & 0x10) == 0) {
            fgets(line, 0x7ff, file);
            strncpy(name, line, 0xf);
            name[0xf] = 0;
            size_t length = strlen(name);
            if (name[length - 1] == '\n') {
                name[length - 1] = 0;
            }
            if ((file->_flag & 0x10) == 0) {
                fgets(line, 0x7ff, file);
                strncpy(text, line, 0xff);
                text[0xff] = 0;
                length = strlen(text);
                if (text[length - 1] == '\n') {
                    text[length - 1] = 0;
                }
                SetCategory_guess(name, text, key);
            }
        }
    }
}

// Deletes the NPC with this name and zone and its entries; returns the new count or -1.
// FUNCTION: TITANIUM 0x0042EE0A
int Journal_guess::RemoveByTextAndType_guess(const char* text, int type) {
    int result = -1;
    int index = 0;
    if (count_0808_guess > 0) {
        do {
            Record_0042e789_guess* record = (Record_0042e789_guess*)values_0800_guess[index];
            if (record->type_0040_guess == type && strcmp_guess(text, record->text_0000_guess) == 0) {
                for (int current = index + 1; current < count_0808_guess; ++current) {
                    values_0800_guess[current - 1] = values_0800_guess[current];
                }
                values_0800_guess[count_0808_guess - 1] = 0;
                ((Object_0042e4ab_guess*)record)->Clear_guess();
                FreeAt60D0D5_guess(record);
                --count_0808_guess;
                result = count_0808_guess;
                break;
            }
            ++index;
        } while (index < count_0808_guess);
    }
    return result;
}

// Adds an entry under NPC `name` (zone `key`), creating the NPC; 0 when nothing was added.
// FUNCTION: TITANIUM 0x0042EE9A
int Journal_guess::AddNpcRecordAndEntry_guess(char* name, int key, int rank, float x, float y, float z, const char* entryName, int extra) {
    int result = 0;
    JournalNpc_guess* records = (JournalNpc_guess*)GetOrAddNpc_guess(name, key);
    if (records != 0) {
        result = records->AddRecordByName_guess(rank, x, y, z, entryName, extra);
    }
    return result;
}

// Frees every NPC with its entries and every category; the text table is left alone.
// FUNCTION: TITANIUM 0x0042F0B1
void Journal_guess::Clear_guess() {
    int index = 0;
    if (count_0808_guess > 0) {
        do {
            int value = values_0800_guess[index];
            if (value != 0) {
                ((Object_0042e4ab_guess*)value)->Clear_guess();
                FreeAt60D0D5_guess((void*)value);
            }
            ++index;
        } while (index < count_0808_guess);
    }
    FreeAt60D682_guess(values_0800_guess);
    values_0800_guess = 0;
    index = 0;
    capacity_0804_guess = 0;
    count_0808_guess = 0;
    if (count_0814_guess > 0) {
        do {
            FreeAt60D0D5_guess((void*)values_080c_guess[index]);
            ++index;
        } while (index < count_0814_guess);
    }
    FreeAt60D682_guess(values_080c_guess);
    values_080c_guess = 0;
    capacity_0810_guess = 0;
    count_0814_guess = 0;
}

// Saves the journal to <fileName>.hdr and .txt (paths converted for the client language, 0x923D74 through
// GetLanguageCodePage_guess). -1 when either file can't be opened. The .txt gets every string in the text
// table; the table of referenced strings built on the way is thrown away unused (early stop: it may be
// decomp shape).
// FUNCTION: TITANIUM 0x0042F146
// @early-stop: budget, structural ndiff=210
int Journal_guess::SaveJournal_guess(const char* fileName) {
    String_0042e3d9_guess textPath;
    String_0042e3d9_guess headerPath;
    char headerPathBuffer[0x204];
    char textPathBuffer[0x204];
    {
        String_0042e3d9_guess suffix(".txt");
        String_0042e3d9_guess result = FUN_0042e3d9_guess(fileName, suffix);
        textPath = result;
    }
    {
        String_0042e3d9_guess suffix(".hdr");
        String_0042e3d9_guess result = FUN_0042e3d9_guess(fileName, suffix);
        headerPath = result;
    }
    char* copiedTextPath = textPath.CopyTo_guess();
    char* builtTextPath = GetLanguageCodePage_guess(
        EQ_GLOBAL(char*, 0x00923D74), copiedTextPath);
    FinalizePath_005749f0_guess(builtTextPath, copiedTextPath, textPathBuffer, 0x200);
    char* copiedHeaderPath = headerPath.CopyTo_guess();
    char* builtHeaderPath = GetLanguageCodePage_guess(
        EQ_GLOBAL(char*, 0x00923D74), copiedHeaderPath);
    FinalizePath_005749f0_guess(builtHeaderPath, copiedHeaderPath, headerPathBuffer, 0x200);

    FILE* textFile = fopen(textPathBuffer, "wt");
    if (textFile == 0) {
        return -1;
    }
    FILE* headerFile = fopen(headerPathBuffer, "wt");
    if (headerFile == 0) {
        fclose(textFile);
        return -1;
    }

    Object_0042f092_guess* exportBuffer = (Object_0042f092_guess*)operator new(0x10);
    if (exportBuffer != 0) {
        exportBuffer = exportBuffer->Initialize_guess(0x400);
    }
    // Header magic; LoadJournal_guess does not check it.
    fprintf(headerFile, "EQJOURNAL\n");

    for (int index = 0; index < count_0814_guess; ++index) {
        fprintf(headerFile, "%s\n", "+CAT");
        ExportCategory_0042f146_guess* category =
            (ExportCategory_0042f146_guess*)values_080c_guess[index];
        fprintf(headerFile, "%d\n", category->value_0000_guess);
        fprintf(headerFile, "%s\n", category->text_0004_guess);
        fprintf(headerFile, "%s\n", category->text_0014_guess);
        fprintf(headerFile, "%s\n", "-CAT");
    }

    index = 0;
    for (; index < count_0808_guess; ++index) {
        ExportNpc_0042f146_guess* npc = (ExportNpc_0042f146_guess*)values_0800_guess[index];
        fprintf(headerFile, "%s\n", "+NPC");
        fprintf(headerFile, "%s\n", npc->name_0000_guess);
        fprintf(headerFile, "%d\n", npc->value_0040_guess);
        fprintf(headerFile, "%s\n", "-NPC");
        for (int entryIndex = 0; entryIndex < npc->count_004c_guess; ++entryIndex) {
            fprintf(headerFile, "%s\n", "+ENTRY");
            JournalEntry_guess* record =
                ((JournalNpc_guess*)npc)->GetRecordAtIndex_guess(entryIndex);
            fprintf(headerFile, "%08X\n", record->timestamp_0000_guess);
            fprintf(headerFile, "%d\n", record->x_0008_guess);
            fprintf(headerFile, "%d\n", record->y_000c_guess);
            fprintf(headerFile, "%d\n", record->z_0010_guess);
            fprintf(headerFile, "%d\n", record->category_0014_guess);
            fprintf(headerFile, "%08X\n", record->textHash_0004_guess);
            fprintf(headerFile, "%s\n", "-ENTRY");
            int value = GetJournalText_guess((unsigned int)record->textHash_0004_guess);
            if (value != 0) {
                exportBuffer->Add_guess(&value, record->textHash_0004_guess);
            }
        }
    }

    HashTable_0042ec1a_guess* table = (HashTable_0042ec1a_guess*)g_journalText_guess;
    HashEntry_0042ec1a_guess* entry = table->First_guess();
    while (entry != 0) {
        fprintf(textFile, "%s\n", (char*)entry->value_0000_guess);
        entry = table->Next_guess(entry);
    }
    if (exportBuffer != 0) {
        exportBuffer->ReleaseData_guess();
        delete exportBuffer;
    }
    fclose(headerFile);
    fclose(textFile);
    return 0;
}

// Frees every NPC with its entries and every category (0x0042F0B1).
// FUNCTION: TITANIUM 0x0042F6C7
void Journal_guess::ClearThunk_guess() {
    Clear_guess();
}

// Frees every text in the current text table and the table, then installs `replacement`.
// FUNCTION: TITANIUM 0x0042F675
// @early-stop: budget, diff ndiff=14
void __cdecl ReplaceLookup_guess(Lookup_004ff9c9_guess* replacement) {
    HashTable_0042ec1a_guess* table = (HashTable_0042ec1a_guess*)g_journalText_guess;
    HashEntry_0042ec1a_guess* entry = table->First_guess();
    while (entry != 0) {
        void* value = entry->value_0000_guess;
        entry = table->Next_guess(entry);
        FreeAt60D682_guess(value);
        table = (HashTable_0042ec1a_guess*)g_journalText_guess;
    }
    if (table != 0) {
        table->Cleanup_guess();
        FreeAt60D0D5_guess(table);
    }
    g_journalText_guess = replacement;
}

// EXTERNAL: TITANIUM 0x00574110 LogText_00574110_guess
void __cdecl LogText_00574110_guess(const char* text);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_0060E450_guess
void __cdecl CopyText_0060E450_guess(char* destination, const char* source);

// Loads <directory_guess>.txt into a new text table (duplicate hashes dropped), then parses the .hdr's
// +CAT and +NPC blocks (+ENTRY inside an NPC). Logs the start and the end of the load.
// Returns -1 with no .txt (a new file is created), -2 with no .hdr; tu_177 shows a message for each.
// The loop counting each NPC's entries does nothing; probably an artefact of the early stop.
// FUNCTION: TITANIUM 0x0042F6CC
// @early-stop: unknown, structural ndiff=194
int Journal_guess::LoadJournal_guess(const char* directory_guess) {
    LogText_00574110_guess(EQ_ARRAY(char, 0x00641B78));
    String_0042e3d9_guess textPath_guess;
    String_0042e3d9_guess headerPath_guess;
    char textPathBuffer_guess[0x204];
    char headerPathBuffer_guess[0x204];
    char line_guess[0x1000];
    {
        String_0042e3d9_guess suffix_guess(EQ_ARRAY(char, 0x0063FE34));
        textPath_guess = FUN_0042e3d9_guess(directory_guess, suffix_guess);
    }
    {
        String_0042e3d9_guess suffix_guess(EQ_ARRAY(char, 0x00641B0C));
        headerPath_guess = FUN_0042e3d9_guess(directory_guess, suffix_guess);
    }
    char* copiedTextPath_guess = textPath_guess.CopyTo_guess();
    FinalizePath_005749f0_guess(
        GetLanguageCodePage_guess(EQ_GLOBAL(char*, 0x00923D74), copiedTextPath_guess),
        copiedTextPath_guess, textPathBuffer_guess, 0x200);
    char* copiedHeaderPath_guess = headerPath_guess.CopyTo_guess();
    FinalizePath_005749f0_guess(
        GetLanguageCodePage_guess(EQ_GLOBAL(char*, 0x00923D74), copiedHeaderPath_guess),
        copiedHeaderPath_guess, headerPathBuffer_guess, 0x200);

    FILE* textFile_guess = fopen(textPathBuffer_guess, EQ_ARRAY(char, 0x0063FA00));
    if (textFile_guess == 0) {
        LogText_00574110_guess(EQ_ARRAY(char, 0x00641B44));
        return -1;
    }
    FILE* headerFile_guess = fopen(headerPathBuffer_guess, EQ_ARRAY(char, 0x0063FA00));
    if (headerFile_guess == 0) {
        fclose(textFile_guess);
        LogText_00574110_guess(EQ_ARRAY(char, 0x00641B24));
        return -2;
    }

    Lookup_004ff9c9_guess* lookup_guess;
    {
        Object_0042f092_guess* allocation_guess = (Object_0042f092_guess*)operator new(0x10);
        if (allocation_guess != 0) {
            lookup_guess = (Lookup_004ff9c9_guess*)allocation_guess->Initialize_guess(0x400);
        } else {
            lookup_guess = 0;
        }
    }

    while ((textFile_guess->_flag & 0x10) == 0) {
        line_guess[0] = 0;
        fgets(line_guess, 0xfff, textFile_guess);
        int length_guess = (int)strlen(line_guess);
        if (length_guess > 1) {
            if (line_guess[length_guess - 1] == '\n') {
                --length_guess;
                line_guess[length_guess] = 0;
            }
            char* copy_guess = new char[length_guess + 1];
            CopyText_0060E450_guess(copy_guess, line_guess);
            unsigned int key_guess = (unsigned int)HashString_guess(copy_guess);
            if (lookup_guess->Find_guess(key_guess) == 0) {
                lookup_guess->Insert_guess((void**)&copy_guess, key_guess);
            } else {
                FreeAt60D682_guess(copy_guess);
            }
        }
    }

    while ((headerFile_guess->_flag & 0x10) == 0) {
        if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AF0), 4) == 0) {
            ReadCategoryFromFile_guess(headerFile_guess);
            while ((headerFile_guess->_flag & 0x10) == 0) {
                fgets(line_guess, 0xfff, headerFile_guess);
                if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AE0), 4) == 0) {
                    break;
                }
                if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AF0), 4) == 0) {
                    break;
                }
            }
        } else if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AE0), 4) == 0) {
            JournalNpc_guess* npc_guess =
                (JournalNpc_guess*)ReadNpcFromFile_guess(headerFile_guess);
            while ((headerFile_guess->_flag & 0x10) == 0) {
                fgets(line_guess, 0xfff, headerFile_guess);
                if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AE0), 4) == 0) {
                    break;
                }
                if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AF0), 4) == 0) {
                    break;
                }
                if (strncmp(line_guess, EQ_ARRAY(char, 0x00641AD8), 6) == 0) {
                    npc_guess->ReadEntryFromFile_guess(headerFile_guess);
                }
            }
        } else {
            line_guess[0] = 0;
            fgets(line_guess, 0xfff, headerFile_guess);
        }
    }

    int npcCount_guess = count_0808_guess;
    if (npcCount_guess > 0) {
        JournalNpc_guess** npcList_guess = (JournalNpc_guess**)values_0800_guess;
        do {
            int entryCount_guess = (*npcList_guess)->count_004c_guess;
            int entryIndex_guess = 0;
            if (entryCount_guess > 0) {
                do {
                    ++entryIndex_guess;
                } while (entryIndex_guess < entryCount_guess);
            }
            ++npcList_guess;
            --npcCount_guess;
        } while (npcCount_guess != 0);
    }

    ReplaceLookup_guess(lookup_guess);
    fclose(headerFile_guess);
    fclose(textFile_guess);
    LogText_00574110_guess(EQ_ARRAY(char, 0x00641B14));
    return 0;
}

