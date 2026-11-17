// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 1: a hint from compare/tumap.py.
// Adventure-point currency adapter for merchant windows: its name ("Adventure"), the spend notice and the
// purchase prompts. tu_064 is the same set for Ebon Crystals; the profile count lives at pCharData +0x103C.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/wnd/CTipWnd.h"

// Layout from the constructor: flag at +0, a at +4, a CXStr at +8, b and c at +0xC and +0x10, d at +0x14.
struct T4013E2_guess {
    char flag_guess;
    int a_guess;
    CXStr s_guess;
    int b_guess;
    int c_guess;
    int d_guess;
    T4013E2_guess(const CXStr& arg, int v);
};

// `v` goes into both +0xC and +0x10; +0x14 starts at -1 (no index yet).
// FUNCTION: TITANIUM 0x004013E2
T4013E2_guess::T4013E2_guess(const CXStr& arg, int v) {
    a_guess = 0;
    flag_guess = 1;
    s_guess = arg;
    d_guess = -1;
    c_guess = v;
    b_guess = v;
}

// EXTERNAL: TITANIUM 0x0063F4F0 ??_7T401429@@6B@
struct T401429 { virtual ~T401429(); };

// Empty virtual destructor (vtable 0x0063F4F0).
// FUNCTION: TITANIUM 0x00401429
T401429::~T401429() {}

// String 5940 "Adventure"; the looked-up text is discarded here (the caller reads the table's result).
// FUNCTION: TITANIUM 0x00401450
void GetAdventureCurrencyName_guess() {
    pStringTable->getString(0x1734, 0);
}

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* dest, int id_guess, const char* text,
                                int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11);

// Object behind pCharData: the count sits at +0x103C (layout unknown).
struct CharDataCount_guess {
    unsigned int pad_0000[0x103C / 4];
    unsigned int count_103C_guess;
};

// this: a small record with a count at +4.
struct Sync_guess {
    unsigned int pad_00_guess;
    unsigned int previousAdventurePoints_04_guess;
    void ReportPointsSpent_guess();
};

// When the adventure-point count (pCharData +0x103C) dropped since the last call, prints
// "You have spent %1 Adventure point(s)." (strings 8543/8544, chat colour 0x114), then remembers the count.
// FUNCTION: TITANIUM 0x00401463
void Sync_guess::ReportPointsSpent_guess() {
    char buf[128];
    if (previousAdventurePoints_04_guess > ((CharDataCount_guess*)pCharData)->count_103C_guess) {
        char text[12];
        unsigned int n = previousAdventurePoints_04_guess - ((CharDataCount_guess*)pCharData)->count_103C_guess;
        sprintf(text, "%d", n);
        FUN_0046da4a_guess(buf, (n != 1) + 0x215f, text, 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buf, 0x114, 1);
    }
    previousAdventurePoints_04_guess = ((CharDataCount_guess*)pCharData)->count_103C_guess;
}

// Shows context tip 0x25 (adventure points) in the tip window (0x9928E0) when it exists; tu_064 shows tip
// 0x40 for Ebon Crystals.
// FUNCTION: TITANIUM 0x004014FC
void ShowAdventureCurrencyTip_guess() {
    CTipWnd_guess* dispatcher = pinstCTipWndCONTEXT_guess;
    if (dispatcher != 0) {
        dispatcher->selectTip_guess(0x25, 0);
    }
}

struct IndexRecord_guess {
    int value_guess;
    int pad_04_guess[4];
};

struct IndexData_guess {
    int pad_0000_guess[0x1058 / 4];
    IndexRecord_guess records_guess[1];
};

// Field 0 of record `index_guess` in a table of 20-byte records at pCharData +0x1058.
// FUNCTION: TITANIUM 0x00401510
int __stdcall FUN_00401510_guess(int index_guess) {
    return EQ_GLOBAL(IndexData_guess*, 0x00905D00)->records_guess[index_guess].value_guess;
}

// Purchase prompt id: selector 1 is a single item (5862/5863, point/points), else a stack (5931/5932).
// For stacks the per-item word is swapped: state 1 picks "points each", others "point each".
// FUNCTION: TITANIUM 0x00401527
int __stdcall GetAdventurePurchaseConfirmId_guess(int selector_guess, int state_guess) {
    if (selector_guess == 1) {
        return (state_guess != 1) + 0x16e6;
    }
    return (state_guess != 1) + 0x172b;
}
