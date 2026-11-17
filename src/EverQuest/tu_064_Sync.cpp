// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 64: a hint from compare/tumap.py.
// Ebon Crystal currency adapter for merchant windows: its name ("Ebon"), the spend notice, purchase prompts
// and the not-enough message. tu_001 is the same set for adventure points; the count is pCharData +0xFB4.
#include "titanium/types.h"
#include "titanium/crt.h"
#include <string.h>
#include "titanium/wnd/CTipWnd.h"

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* buffer_guess, int id_guess,
                                const char* text_guess, int zero1_guess,
                                int zero2_guess, int zero3_guess, int zero4_guess,
                                int zero5_guess, int zero6_guess, int zero7_guess,
                                int zero8_guess);

struct CharData_guess {
    unsigned int pad_000[0xFB4 / 4];
    unsigned int field_FB4;    // 0xFB4
    unsigned int field_FB8;    // 0xFB8
};
#define pCharData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)

struct Thing_guess {
    void* vtable;              // 0x00
    unsigned int field_4;      // 0x04
    unsigned int field_8;      // 0x08
    unsigned char field_c[8];  // 0x0c
    unsigned char field_14[8]; // 0x14
    Thing_guess* Reset();
    void ReportCrystalsSpent_guess();
};

// Always false. A slot of the vtable at 0x0063F4F0, and also called directly at 0x00594047.
// FUNCTION: TITANIUM 0x004B11E7
char __cdecl ReturnFalse_guess(void) {
    return 0;
}

// String 5946 "Ebon"; the looked-up text is discarded here (the caller reads the table's result).
// FUNCTION: TITANIUM 0x004B1200
void __cdecl GetEbonCurrencyName_guess(void) {
    pStringTable->getString(0x173a, 0);
}

// When the Ebon Crystal count (pCharData +0xFB4) dropped since the last call, prints
// "You have spent %1 Ebon Crystal(s)." (strings 5860/5861, chat colour 0x114), then remembers +0xFB4 and
// +0xFB8 (probably the career count).
// FUNCTION: TITANIUM 0x004B1213
void Thing_guess::ReportCrystalsSpent_guess() {
    char message[128];
    if (field_4 > pCharData_guess->field_FB4) {
        char number[12];
        int behind = field_4 - pCharData_guess->field_FB4;
        sprintf(number, "%d", behind);
        FUN_0046da4a_guess(message, (behind != 1) + 0x16E4, number, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(message, 0x114, true);
    }
    field_4 = pCharData_guess->field_FB4;
    field_8 = pCharData_guess->field_FB8;
}

// Shows context tip 64 (0x40) in the tip window (0x9928E0) when it exists; tu_001 shows tip 0x25 for
// adventure points.
// FUNCTION: TITANIUM 0x004B12BA
void __cdecl ShowEbonCurrencyTip_guess(void) {
    if (pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x40, 0);
    }
}

// Purchase prompt id: `first_guess` 1 is a single item (5957/5958, Crystal/Crystals), else a stack
// (5959/5960). For stacks the per-item word comes out wrong: 1 picks 5959 "points each", others "point each".
// FUNCTION: TITANIUM 0x004B12CE
int __stdcall GetEbonPurchaseConfirmId_guess(int first_guess, int second_guess) {
    if (first_guess == 1) {
        return (second_guess != 1) + 0x1745;
    }
    return (second_guess != 1) + 0x1747;
}

// "You must have %1 Ebon Crystal(s) available...": 5966 for one crystal, 5965 for more; 0 when
// `second_guess` is set (no message).
// FUNCTION: TITANIUM 0x004B12F6
int __stdcall GetEbonInsufficientMsgId_guess(int first_guess, char second_guess,
                                  int unused_guess) {
    if (second_guess == 0) {
        return 0x174E + ((first_guess - 1) ? -1 : 0);
    }
    return 0;
}

// String 5962 "Ebon Crystals Available", the merchant window's balance label.
// FUNCTION: TITANIUM 0x004B1312
void __cdecl GetEbonAvailableLabel_guess(void) {
    pStringTable->getString(0x174A, 0);
}

// Zeroes the remembered counts and both 8-byte buffers and sets the vtable at 0x64AF20.
// FUNCTION: TITANIUM 0x004B1325
Thing_guess* Thing_guess::Reset() {
    field_4 = 0;
    field_8 = 0;
    vtable = &EQ_GLOBAL(int, 0x0064AF20);
    memset(field_c, 0, 8);
    memset(field_14, 0, 8);
    return this;
}

