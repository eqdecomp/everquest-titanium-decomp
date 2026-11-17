// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 57: a hint from compare/tumap.py.
// The race model-tag table: a chained hash of (race, gender) -> model tag ("HUM", "BOAT", "PPOINT"...), built
// once at 0x903E70 and read through GetRaceModelTag_guess (tu_029 calls it when loading actor definitions).
// RaceTagTable_guess is that table; StringRecord_guess is one 0x1C-byte entry.
#include "titanium/eqaddr.h"

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

// EXTERNAL: TITANIUM 0x0042429E NextPrimeCandidate_guess
int __cdecl NextPrimeCandidate_guess(int requested_guess);

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

struct Allocation_guess {
    void* memory;
    void Release();
};

struct HashNode_guess {
    unsigned int key;
    HashNode_guess* next;
};

struct HashTable_guess {
    HashNode_guess** buckets;
    unsigned int bucketCount;
    int count;
    unsigned int occupiedCount;
    HashTable_guess(unsigned int size);
    ~HashTable_guess();
    void Resize_guess(unsigned int size);
    void Insert(HashNode_guess* node, unsigned int key);
    HashNode_guess* Find(unsigned int key);
    HashNode_guess* FindDuplicate(HashNode_guess* node);
    void GetRaceTag_guess(char* destination, unsigned int key, unsigned int value);
    void AddText_guess(const char* source, unsigned int key, unsigned int value);
};

struct RaceTagEntry_guess {
    unsigned int unknown00[2];
    char text[12];
    unsigned int unknown14;
    unsigned int unknown18;
    RaceTagEntry_guess* Initialize_guess(const char* source, unsigned int value14, unsigned int value18);
};

// Fills an entry: tag text (+8, 12 bytes, copied by an unbounded strcpy), race (+0x14), gender (+0x18).
// FUNCTION: TITANIUM 0x0048C69F
RaceTagEntry_guess* RaceTagEntry_guess::Initialize_guess(const char* source, unsigned int value14, unsigned int value18) {
    FUN_0060e450_guess(text, source);
    unknown14 = value14;
    unknown18 = value18;
    return this;
}

// Frees the held allocation.
// FUNCTION: TITANIUM 0x0048C6C5
void Allocation_guess::Release() {
    free(memory);
}

// Pushes `node` at the front of its bucket; occupiedCount counts non-empty buckets.
// FUNCTION: TITANIUM 0x0048C6CE
void HashTable_guess::Insert(HashNode_guess* node, unsigned int key) {
    node->key = key;
    unsigned int index = key % bucketCount;
    HashNode_guess* first = buckets[index];
    if (first == 0) {
        node->next = 0;
        buckets[index] = node;
        ++occupiedCount;
    } else {
        node->next = first;
        buckets[index] = node;
    }
    ++count;
}

// First node with hash key `key` in its bucket chain, or 0.
// FUNCTION: TITANIUM 0x0048C708
HashNode_guess* HashTable_guess::Find(unsigned int key) {
    HashNode_guess* node = buckets[key % bucketCount];
    while (node != 0 && node->key != key) {
        node = node->next;
    }
    return node;
}

// Next node in the same chain with the same hash key, or 0.
// FUNCTION: TITANIUM 0x0048C72A
HashNode_guess* HashTable_guess::FindDuplicate(HashNode_guess* node) {
    unsigned int key = node->key;
    while (1) {
        node = node->next;
        if (node == 0 || node->key == key) {
            return node;
        }
    }
}

// Rehashes into NextPrimeCandidate_guess(size) buckets; chains come out reversed.
// FUNCTION: TITANIUM 0x0048C740
void HashTable_guess::Resize_guess(unsigned int size) {
    HashNode_guess** oldBuckets = buckets;
    int oldCount = bucketCount;
    bucketCount = NextPrimeCandidate_guess(size);
    buckets = (HashNode_guess**)operator new(bucketCount << 2);
    memset(buckets, 0, bucketCount << 2);
    occupiedCount = 0;
    int i;
    if (count > 0 && ((i = 0), oldCount > 0)) {
        do {
            HashNode_guess* node = oldBuckets[i];
            while (node != 0) {
                HashNode_guess* current = node;
                unsigned int key = current->key;
                HashNode_guess** link = &node->next;
                node = *link;
                unsigned int index = key % bucketCount;
                HashNode_guess* head = buckets[index];
                if (head == 0) {
                    *link = 0;
                    buckets[index] = current;
                    ++occupiedCount;
                } else {
                    *link = head;
                    buckets[index] = current;
                }
            }
            ++i;
        } while (i < oldCount);
    }
    free(oldBuckets);
}

// Copies the tag for race `key`, gender `value` (0 male, 1 female, 2 neutral) into `destination`. The hash
// key is race + gender, so entries are matched on both. Unknown races fall back to the human tags (race 1:
// the female one for gender 1, else the male one).
// FUNCTION: TITANIUM 0x0048C7E7
void HashTable_guess::GetRaceTag_guess(char* destination, unsigned int key, unsigned int value) {
    HashNode_guess* node = Find(key + value);
    while (node != 0) {
        RaceTagEntry_guess* record = (RaceTagEntry_guess*)node;
        if (record->unknown14 == key && record->unknown18 == value) {
            FUN_0060e450_guess(destination, record->text);
            return;
        }
        node = FindDuplicate(node);
    }
    if (value == 1) {
        FUN_0060e450_guess(destination, EQ_ARRAY(char, 0x006486FC));
    } else {
        FUN_0060e450_guess(destination, EQ_ARRAY(char, 0x006486F8));
    }
}

// Adds a 0x1C-byte tag record under hash key race + gender; a failed allocation passes null to Insert,
// which writes through it.
// FUNCTION: TITANIUM 0x0048C83E
void HashTable_guess::AddText_guess(const char* source, unsigned int key, unsigned int value) {
    RaceTagEntry_guess* record = (RaceTagEntry_guess*)operator new(0x1c);
    HashNode_guess* node;
    if (record != 0) {
        node = (HashNode_guess*)record->Initialize_guess(source, key, value);
    } else {
        node = 0;
    }
    Insert(node, key + value);
}

// Lookup in the global model-tag table (0x903E70).
// FUNCTION: TITANIUM 0x0048C879
void __cdecl GetRaceModelTag_guess(char* destination, unsigned int key, unsigned int value) {
    EQ_GLOBAL(HashTable_guess, 0x00903E70).GetRaceTag_guess(destination, key, value);
}

// Hash table constructor: empty, with a bucket array sized from `size` by 0x0048C740 (rounded up by
// 0x0042429E).
// FUNCTION: TITANIUM 0x0048C890
HashTable_guess::HashTable_guess(unsigned int size) {
    buckets = 0;
    bucketCount = 0;
    count = 0;
    occupiedCount = 0;
    Resize_guess(size);
}

struct RaceTagTable_guess : HashTable_guess {
    RaceTagTable_guess();
};

// Every race's model tags, one AddText_guess per (race, gender): gender 0 male, 1 female, 2 for races with a
// single model. Most tags are 3-letter strings in .rdata (0x6487xx-0x648Exx); named ones include race 72
// SHIP, 73 LAUNCH/LAUNCHM, 141 BOAT, 252 MINIPOM200 and the PPOINT ids 2253-2258. A few tags are shared on
// purpose (the same address for two races).
// FUNCTION: TITANIUM 0x0048C8AF
RaceTagTable_guess::RaceTagTable_guess() : HashTable_guess(0x32) {
    // One entry per (race id, gender: 0 male, 1 female, 2 neuter) naming the model code. Most races (384
    // of 473) have only a neuter entry, 60 have separate male and female codes, and 26 (MINIPOM200,
    // PPOINT, BOAT...) repeat one code for all three genders.
    AddText_guess("MINIPOM200", 0xfc, 0);
    AddText_guess("MINIPOM200", 0xfc, 1);
    AddText_guess("MINIPOM200", 0xfc, 2);
    AddText_guess("PPOINT", 0x8cd, 0);
    AddText_guess("PPOINT", 0x8cd, 1);
    AddText_guess("PPOINT", 0x8cd, 2);
    AddText_guess("PPOINT", 0x8ce, 0);
    AddText_guess("PPOINT", 0x8ce, 1);
    AddText_guess("PPOINT", 0x8ce, 2);
    AddText_guess("PPOINT", 0x8cf, 0);
    AddText_guess("PPOINT", 0x8cf, 1);
    AddText_guess("PPOINT", 0x8cf, 2);
    AddText_guess("PPOINT", 0x8d0, 0);
    AddText_guess("PPOINT", 0x8d0, 1);
    AddText_guess("PPOINT", 0x8d0, 2);
    AddText_guess("PPOINT", 0x8d1, 0);
    AddText_guess("PPOINT", 0x8d1, 1);
    AddText_guess("PPOINT", 0x8d1, 2);
    AddText_guess("PPOINT", 0x8d2, 0);
    AddText_guess("PPOINT", 0x8d2, 1);
    AddText_guess("PPOINT", 0x8d2, 2);
    AddText_guess("BOAT", 0x8d, 0);
    AddText_guess("BOAT", 0x8d, 1);
    AddText_guess("BOAT", 0x8d, 2);
    AddText_guess("SHIP", 0x48, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e50), 0x48, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e50), 0x48, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648e4c), 0x14a, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648258), 0x14a, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e48), 0x82, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e44), 0x82, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e40), 0x80, 0);
    AddText_guess(EQ_ARRAY(char, 0x006482c8), 0x80, 1);
    AddText_guess(EQ_ARRAY(char, 0x006486f8), 1, 0);
    AddText_guess(EQ_ARRAY(char, 0x006486fc), 1, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e3c), 3, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e38), 3, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e34), 7, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e30), 7, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e2c), 5, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e28), 5, 1);
    AddText_guess(EQ_ARRAY(char, 0x006483a0), 0xc, 0);
    AddText_guess(EQ_ARRAY(char, 0x0064839c), 0xc, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e24), 0xb, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e20), 0xb, 1);
    AddText_guess(EQ_ARRAY(char, 0x0064836c), 9, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648364), 9, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e1c), 6, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e18), 6, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e14), 2, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e10), 2, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e0c), 4, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e08), 4, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648e04), 10, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648e00), 10, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648dfc), 8, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648df8), 8, 1);
    AddText_guess("LAUNCH", 0x49, 2);
    AddText_guess("LAUNCHM", 0x49, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648de4), 0x194, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648de0), 0x31, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ddc), 0x27, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dd8), 0x28, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dd4), 0x2b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dd0), 0x47, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648dcc), 0x47, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648dc8), 0x47, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dc4), 0x2a, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648dc0), 0x2a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dbc), 0x2a, 1);
    AddText_guess(EQ_ARRAY(char, 0x006482f4), 0x11, 0);
    AddText_guess(EQ_ARRAY(char, 0x006482f8), 0x11, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648db8), 0x11, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648db4), 0xd, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648db0), 0x43, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648dac), 0x43, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648da8), 0x46, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648da4), 0x46, 1);
    AddText_guess(EQ_ARRAY(char, 0x0064833c), 0x17, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648314), 0x17, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648350), 0x37, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648da0), 0x37, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d9c), 0xf, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d98), 0xf, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d94), 0x19, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d90), 0x19, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648290), 0x44, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d8c), 0x44, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648d88), 0x44, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d84), 0x26, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648d80), 0x38, 0);
    AddText_guess(EQ_ARRAY(char, 0x0064830c), 0x38, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d7c), 0x2c, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d78), 0x2c, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d74), 0x4d, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d70), 0x4d, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d6c), 0x4e, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d68), 0x4e, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d64), 0x32, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648328), 0x32, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648398), 0x58, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d60), 0x58, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648394), 0x58, 1);
    AddText_guess(EQ_ARRAY(char, 0x0064838c), 0x51, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648388), 0x51, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d5c), 0x5a, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d58), 0x5a, 1);
    AddText_guess(EQ_ARRAY(char, 0x006482e4), 0x1d, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d54), 0x1d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648360), 0x5c, 0);
    AddText_guess(EQ_ARRAY(char, 0x0064835c), 0x5c, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648358), 0x5d, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648354), 0x5d, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648384), 0x5e, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d50), 0x5e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648380), 0x5e, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d4c), 0x62, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d48), 0x62, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d44), 0x41, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d40), 0x41, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d3c), 0x34, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d38), 0x34, 1);
    AddText_guess(EQ_ARRAY(char, 0x006483c8), 0x6a, 0);
    AddText_guess(EQ_ARRAY(char, 0x006483c4), 0x6a, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d34), 0x70, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d30), 0x70, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d2c), 0x75, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d28), 0x75, 1);
    AddText_guess(EQ_ARRAY(char, 0x006483bc), 0x20, 0);
    AddText_guess(EQ_ARRAY(char, 0x006483b8), 0x20, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d24), 0x76, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d20), 0x76, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d1c), 0x10, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d18), 0x10, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648d14), 0x10, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d10), 0x7f, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d0c), 0x7f, 1);
    AddText_guess(EQ_ARRAY(char, 0x006482d8), 0x8b, 0);
    AddText_guess(EQ_ARRAY(char, 0x006482d4), 0x8b, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482d0), 0x8b, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d08), 0x39, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d04), 0x39, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648d00), 0x93, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cfc), 0x93, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648cf8), 0x93, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cf4), 0x9c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648cf0), 0xb1, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482a0), 0xbd, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064829c), 0xbd, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648374), 0xb7, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648404), 0xb7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648370), 0xb7, 1);
    AddText_guess(EQ_ARRAY(char, 0x0064827c), 0xca, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cec), 0xca, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ce8), 0xca, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648ce4), 0xd0, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648ce0), 0xd0, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cdc), 0xd8, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cd8), 0xd8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648cd4), 0xd8, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cd0), 0xd9, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648284), 0xd9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648280), 0xd9, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648ccc), 0xe0, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648270), 0xe0, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cc8), 0xe6, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cc4), 0xe6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648cc0), 0xe6, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cbc), 0xe9, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cb8), 0xe9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648cb4), 0xe9, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648cb0), 0xf0, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648cac), 0xf0, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ca8), 0xf0, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648ca4), 0xed, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648ca0), 0xed, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c9c), 0xed, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c98), 0x14b, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c94), 0x14b, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c90), 0x14c, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c8c), 0x14c, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c88), 0x14d, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c84), 0x14d, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c80), 0x152, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c7c), 0x152, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c78), 0x153, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c74), 0x153, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c70), 0x154, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c6c), 0x154, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c68), 0x155, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c64), 0x155, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c60), 0x156, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c5c), 0x156, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c58), 0x158, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c54), 0x158, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c50), 0x15f, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c4c), 0x15f, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c48), 0x160, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c44), 0x160, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c40), 0x168, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c3c), 0x168, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c38), 0x167, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c34), 0x167, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c30), 0x16c, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c2c), 0x16c, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c28), 0x181, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648c24), 0x181, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648290), 0x182, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648d88), 0x182, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648c20), 0x25, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648344), 0x3c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648340), 0x35, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c1c), 0x18, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c18), 0x1f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c14), 0x4a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c10), 0x4b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c0c), 0x22, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c08), 0x24, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c04), 0x1a0, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648c00), 0x19f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648330), 0x21, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bfc), 0x1a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bf8), 0x15, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bf8), 0x1e, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064832c), 0x1b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bf4), 0xe, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bf0), 0x12, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482e0), 0x16, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bec), 0x45, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648be8), 0x40, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648be4), 0x3d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648320), 0x3f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648324), 0x4c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648be0), 0x4f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648244), 0x57, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bdc), 0x59, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bd8), 0x1c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648304), 0x2f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bd4), 0x36, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bd0), 0x50, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bcc), 0x52, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648308), 0x53, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648310), 0x54, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bc8), 0x55, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648300), 0x56, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bc4), 0x5b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bc0), 0x33, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bbc), 0x5f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bb8), 0x60, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bb4), 0x61, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bb0), 0x63, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648bac), 0x64, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ba8), 0x65, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ba4), 0x66, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ba0), 0x29, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b9c), 0x67, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b98), 0x68, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b94), 0x69, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b90), 0x6b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b8c), 0x6d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b88), 0x6e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b84), 0x6f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b80), 0x71, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b7c), 0x72, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b78), 0x73, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b74), 0x74, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482ec), 0x30, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b70), 0x78, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482e8), 0x2e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b6c), 0x79, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b68), 0x7a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b64), 0x7b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b60), 0x7c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b5c), 0x7d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b58), 0x7e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b54), 0x6c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b50), 0x81, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b4c), 0x83, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b48), 0x84, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b44), 0x85, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b40), 0x86, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b3c), 0x87, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b38), 0x88, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b34), 0x89, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b30), 0x8a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482c4), 0x3b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b2c), 0x2d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b28), 0x8c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b24), 0x13, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b20), 0x14, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b1c), 0x3a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b18), 0x3e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b14), 0x42, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064831c), 0x77, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b10), 0x90, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b0c), 0x91, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b08), 0x92, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b04), 0x94, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648b00), 0x95, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648418), 0x96, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064834c), 0x97, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648afc), 0x98, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648408), 0x99, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648af8), 0x9a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482c0), 0x9b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648af4), 0x9d, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482b8), 0x9e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648af0), 0x9f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648aec), 0xa0, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482cc), 0xa1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ae8), 0xa2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ae4), 0xa3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ae0), 0xa4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648adc), 0xa5, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482bc), 0xa6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ad8), 0xa7, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482fc), 0xa8, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482b0), 0xa9, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482ac), 0xaa, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ad4), 0xab, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648318), 0xac, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482a8), 0xad, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482a4), 0xae, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648348), 0xaf, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ad0), 0xb0, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648acc), 0xb2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648338), 0xb5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648334), 0xb6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648400), 0xb8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648410), 0xb9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ac8), 0xba, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648414), 0xbb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ac4), 0xbc, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ac0), 0xbe, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648abc), 0xbf, 2);
    AddText_guess(EQ_ARRAY(char, 0x006483fc), 0xc0, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064840c), 0xc1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ab8), 0xc2, 2);
    AddText_guess(EQ_ARRAY(char, 0x006483f8), 0xc3, 2);
    AddText_guess(EQ_ARRAY(char, 0x006482b4), 0xc4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ab4), 0xc5, 2);
    AddText_guess(EQ_ARRAY(char, 0x006483f4), 0xc6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648ab0), 0xc7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648aac), 0xc8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648aa8), 0xc9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648aa4), 0xcb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648aa0), 0xcc, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a9c), 0xcd, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a98), 0xce, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a94), 0xcf, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a90), 0xd1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a8c), 0xd2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648278), 0xd3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648274), 0xd4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a88), 0xd5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a84), 0xd6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a80), 0xd7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a7c), 0xda, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a78), 0xdb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a74), 0xdc, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a70), 0xdd, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a6c), 0xde, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a68), 0xdf, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a64), 0xe1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a60), 0xe2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a5c), 0xe3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a58), 0xe4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a54), 0xe5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a50), 0xe7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a4c), 0xe8, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064826c), 0xea, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a48), 0xeb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a44), 0xec, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648264), 0xee, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648268), 0xef, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a40), 0xf1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648260), 0xf2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a3c), 0xf3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a38), 0xf4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a34), 0xf5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a30), 0xf6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a2c), 0xf7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a28), 0xf8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a24), 0xf9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a20), 0xfa, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a1c), 0xfb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a18), 0xfd, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a14), 0xfe, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a10), 0xff, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a0c), 0x100, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a08), 0x101, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a04), 0x102, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648a00), 0x103, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489fc), 0x104, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489f8), 0x105, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489f4), 0x106, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489f0), 0x107, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489ec), 0x108, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489e8), 0x109, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489e4), 0x10a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489e0), 0x10b, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489dc), 0x10c, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489d8), 0x10d, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489d4), 0x10e, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489d0), 0x10f, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489cc), 0x110, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489c8), 0x111, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489c4), 0x112, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489c0), 0x113, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489bc), 0x114, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489b8), 0x115, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489b4), 0x116, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489b0), 0x117, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489ac), 0x118, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489a8), 0x119, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489a4), 0x11a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006489a0), 0x11b, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064899c), 0x11c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648998), 0x11d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648994), 0x11e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648990), 0x11f, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064898c), 0x120, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648988), 0x122, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648984), 0x121, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648980), 0x123, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064897c), 0x124, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648978), 0x125, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648974), 0x126, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648970), 0x127, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064896c), 0x128, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648968), 0x129, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648964), 0x12a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648960), 0x12b, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064895c), 0x12c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648958), 0x12d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648954), 0x12e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648950), 0x12f, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064894c), 0x130, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648948), 0x131, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648944), 0x132, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648940), 0x133, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064893c), 0x134, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648938), 0x135, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648934), 0x136, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648930), 0x137, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064892c), 0x138, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648928), 0x139, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648924), 0x13a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648920), 0x13b, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064891c), 0x13c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648918), 0x13d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648914), 0x13e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648910), 0x13f, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064890c), 0x140, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648908), 0x141, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648904), 0x144, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648900), 0x142, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488fc), 0x143, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488f8), 0x145, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488f4), 0x146, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064825c), 0x147, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488f0), 0x148, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488ec), 0x149, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488e8), 0x14e, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488e4), 0x14f, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488e0), 0x150, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488dc), 0x151, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488d8), 0x157, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488d4), 0x159, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488d0), 0x15a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488cc), 0x15b, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488c8), 0x15c, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488c4), 0x15d, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488c0), 0x15e, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488bc), 0x161, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488b8), 0x162, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488b4), 0x163, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488b0), 0x166, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648dbc), 0x164, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488ac), 0x165, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488a8), 0x169, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488a4), 0x16e, 2);
    AddText_guess(EQ_ARRAY(char, 0x006488a0), 0x16a, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064889c), 0x16b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648898), 0x16d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648894), 0x16f, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648890), 0x170, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064888c), 0x171, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648888), 0x173, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648884), 0x174, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648880), 0x175, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064887c), 0x176, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648878), 0x177, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648874), 0x172, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648870), 0x180, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064886c), 0x178, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648868), 0x179, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648864), 0x17a, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648860), 0x17b, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064885c), 0x17c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648858), 0x17d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648854), 0x17e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648850), 0x17f, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064884c), 0x183, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648848), 0x184, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648844), 0x185, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648840), 0x186, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064883c), 0x187, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648838), 0x188, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648834), 0x189, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648830), 0x18a, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064882c), 0x18b, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648828), 0x18c, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648824), 0x18e, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648820), 0x18f, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064881c), 0x190, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648818), 0x191, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648814), 0x18d, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648810), 0x192, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064880c), 0x193, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648808), 0x195, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648804), 0x196, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648800), 0x197, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487fc), 0x198, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487f8), 0x199, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487f4), 0x19a, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487fc), 0x19b, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487f0), 0x19c, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487ec), 0x19d, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487e8), 0x19e, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487e4), 0x1a1, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487e0), 0x1a2, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487dc), 0x1a3, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487d8), 0x1a4, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487d4), 0x1a5, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487d0), 0x1a6, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487cc), 0x1a7, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487c8), 0x1a8, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487c4), 0x1a9, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487c0), 0x1aa, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487bc), 0x1ab, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487b8), 0x1ac, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487b4), 0x1ad, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487b0), 0x1ae, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487ac), 0x1af, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487a8), 0x1b0, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487a4), 0x1b1, 2);
    AddText_guess(EQ_ARRAY(char, 0x006487a0), 0x1b2, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064879c), 0x1b3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648798), 0x1b4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648794), 0x1b5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648790), 0x1b6, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064878c), 0x1b7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648788), 0x1b8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648784), 0x1b9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648780), 0x1ba, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064877c), 0x1bd, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648778), 0x1be, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648774), 0x1bf, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648770), 0x1c0, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064876c), 0x1c1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648768), 0x1c2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648764), 0x1c3, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648760), 0x1c4, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064875c), 0x1c5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648758), 0x1c6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648754), 0x1c7, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648750), 0x1c8, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064874c), 0x1c9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648748), 0x1ca, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648744), 0x1cb, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648740), 0x1cc, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064873c), 0x1cd, 1);
    AddText_guess(EQ_ARRAY(char, 0x00648738), 0x1cd, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648734), 0x1ce, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648730), 0x1cf, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064872c), 0x1d0, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648728), 0x1d1, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648724), 0x1d2, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648720), 0x1d3, 2);
    AddText_guess(EQ_ARRAY(char, 0x0064871c), 0x1d4, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648718), 0x1d5, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648714), 0x1d6, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648710), 0x1d7, 1);
    AddText_guess(EQ_ARRAY(char, 0x0064870c), 0x1d7, 0);
    AddText_guess(EQ_ARRAY(char, 0x00648708), 0x1d8, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648704), 0x1d9, 2);
    AddText_guess(EQ_ARRAY(char, 0x00648700), 0x1da, 2);
}

