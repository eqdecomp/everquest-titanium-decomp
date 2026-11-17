// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 14: a hint from compare/tumap.py.
// Charity point currency for the point merchants (strings 5938, 5949-5952), the sibling of tu_066 (Radiant)
// and tu_001 (Adventure), plus a few unrelated small callbacks.
#include "titanium/types.h"
#include "titanium/wnd/CTipWnd.h"

struct Thing_guess {
    char* vtable;
};

#define g_vtableAddress_guess EQ_GLOBAL(char, 0x00641158)

struct EQCharacterTail_guess : EQ_Character {
    unsigned int pad_000C[(0x0FA4 - 0x000C) / 4];
    unsigned int value_0FA4;
    unsigned int value_0FA8;
};

struct SettingsSink_guess {
    void* vtable;
    unsigned int value_04;
    unsigned int value_08;
    void CopySettings_guess();
};

struct StringFields_guess {
    void* vtable;
    unsigned int value_04;
    unsigned int value_08;
    char* value_0C;
    char* value_10;
    char* value_14;
    char* value_18;
    void InitializeStrings_guess();
};

#define g_charDataTail_guess EQ_GLOBAL(EQCharacterTail_guess*, 0x00905D00)

// Points the object at its vtable (0x641158); the rest of the constructor is elsewhere.
// FUNCTION: TITANIUM 0x00424073
void __fastcall InitializeThing_guess(Thing_guess* self) {
    self->vtable = &g_vtableAddress_guess;
}

// String 5938, "Charity"; the name for the currency label.
// FUNCTION: TITANIUM 0x00424090
void LookupCharityLabel_guess() {
    pStringTable->getString(0x1732, 0);
}

// Copies the two charity counts from the character (+0xFA4, +0xFA8); probably current and career, like the
// crystal pairs in tu_066.
// FUNCTION: TITANIUM 0x004240A3
void SettingsSink_guess::CopySettings_guess() {
    value_04 = g_charDataTail_guess->value_0FA4;
    value_08 = g_charDataTail_guess->value_0FA8;
}

// Shows context tip 63 (0x3F) in the tip window (0x9928E0) when it exists.
// FUNCTION: TITANIUM 0x004240C0
void ContextCallback_guess() {
    CTipWnd_guess* context = pinstCTipWndCONTEXT_guess;
    if (context != 0) {
        context->selectTip_guess(0x3F, 0);
    }
}

// Fills all four label strings with 5938, "Charity".
// FUNCTION: TITANIUM 0x00424102
void StringFields_guess::InitializeStrings_guess() {
    value_0C = pStringTable->getString(0x1732, 0);
    value_10 = pStringTable->getString(0x1732, 0);
    value_14 = pStringTable->getString(0x1732, 0);
    value_18 = pStringTable->getString(0x1732, 0);
}

// Purchase-confirm string: 5949/5950 for a single item (`firstValue_guess` 1), 5951/5952 for a stack;
// `secondValue_guess` 1 picks the singular form.
// FUNCTION: TITANIUM 0x004240DA
int __stdcall GetCharityPurchaseConfirmId_guess(int firstValue_guess, int secondValue_guess) {
    if (firstValue_guess == 1) {
        return (secondValue_guess != 1) + 0x173D;
    }
    return (secondValue_guess != 1) + 0x173F;
}

