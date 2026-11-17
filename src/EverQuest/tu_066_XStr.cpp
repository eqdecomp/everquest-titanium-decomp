// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 66: a hint from compare/tumap.py.
// Radiant crystal currency for the point merchants: its name, purchase-confirm and not-enough string ids, and
// a holder for the crystal counts. tu_014 is the Charity copy, tu_001 the Adventure one.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <string.h>

// EXTERNAL: TITANIUM 0x0064AFA8 ??_7Object_guess@@6B@
struct Object_guess {
    virtual void RefreshCounts_guess();
    unsigned int field4;
    unsigned int field8;
    char fieldC[8];
    char field14[8];

    Object_guess();
};

struct EQ_CharacterTail_guess : EQ_Character {
    unsigned char pad_00C[0xFAC - 0x00C];
    unsigned int field_FAC;
    unsigned int field_FB0;
};

// Refcounted string, first dword is the data pointer.
struct Str_guess {
    char* data_guess;   // 0x00

    // EXTERNAL: TITANIUM 0x00407D68 ??0Str_guess@@QAE@ABU0@@Z
    Str_guess(const Str_guess& s);
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* s);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
    }
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* p);
    // EXTERNAL: TITANIUM 0x00572C10 Str_guess::Append_guess
    void Append_guess(const Str_guess& s);
};

// String 5945, "Radiant".
// FUNCTION: TITANIUM 0x004B13EC
void GetRadiantCurrencyName_guess() {
    pStringTable->getString(0x1739, 0);
}

// Refreshes the two counts from the character (+0xFAC, +0xFB0); probably current and career radiant crystals
// (EQEmu currentRadCrystals, careerRadCrystals).
// FUNCTION: TITANIUM 0x004B13FF
void Object_guess::RefreshCounts_guess() {
    field4 = static_cast<EQ_CharacterTail_guess*>(pCharData)->field_FAC;
    field8 = static_cast<EQ_CharacterTail_guess*>(pCharData)->field_FB0;
}

// Purchase-confirm string id: 5953/5954 when `first_guess` is 1, else 5955/5956; `second_guess` 1 takes
// the first id of the pair. What the two arguments mean is the callers' business (not traced).
// FUNCTION: TITANIUM 0x004B141C
int __stdcall GetRadiantPurchaseConfirmId_guess(int first_guess, int second_guess) {
    if (first_guess == 1) {
        return (second_guess != 1) + 0x1741;
    }
    return (second_guess != 1) + 0x1743;
}

// Not-enough-crystals string: 0 when `second_guess` is set (no message), else 5964 ("Crystal") for a price of
// 1 and 5963 ("Crystals") otherwise.
// FUNCTION: TITANIUM 0x004B1444
int __stdcall GetRadiantInsufficientMsgId_guess(int first_guess, bool second_guess, int unused_guess) {
    if (!second_guess) {
        return first_guess == 1 ? 0x174c : 0x174b;
    }
    return 0;
}

// String 5961, "Radiant Crystals Available".
// FUNCTION: TITANIUM 0x004B1460
void GetRadiantAvailableLabel_guess() {
    pStringTable->getString(0x1749, 0);
}

// `a` + `b` as a new string (operator+ on the refcounted string).
// FUNCTION: TITANIUM 0x004B1357
Str_guess Make_guess(const Str_guess& a, const char* b) {
    Str_guess tmp(a);
    tmp.Append_guess(Str_guess(b));
    return tmp;
}

// Radiant Crystal currency holder constructor: +4, +8 and the two 8-byte count blocks zeroed; the
// in-game UI creates it once (0x0098593C).
// FUNCTION: TITANIUM 0x004B1473
Object_guess::Object_guess() {
    field4 = 0;
    field8 = 0;
    memset(fieldC, 0, sizeof(fieldC));
    memset(field14, 0, sizeof(field14));
}

