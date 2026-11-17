#ifndef TITANIUM_MAIL_ADDRESS_BOOK_H
#define TITANIUM_MAIL_ADDRESS_BOOK_H

#include "titanium/types.h"

// Polymorphic view of CSidlScreenWnd: core_decls.h exposes a plain vfptr layout.
// The constructor and destructor need the compiler-managed primary vfptr.
struct MailSidlPiece_guess {
    char pad_guess[0x60];
    unsigned int style_guess;           // 0x60
};

struct MailScreenWndView_guess {
    virtual void Slot_guess() = 0;
    char pad18_guess[0x14];
    unsigned char flag18_guess;         // 0x18
    char pad19_guess[0x20 - 0x19];
    struct Size_guess {
        int width, height;
        Size_guess(int w, int h) : width(w), height(h) {}
    } minimum_guess;                    // 0x20
    void SetMinimum_guess(Size_guess size) { minimum_guess = size; }
    char pad28_guess[0x64 - 0x28];
    unsigned int windowStyle_guess;     // 0x64
    char pad68_guess[0x124 - 0x68];
    MailSidlPiece_guess* sidlPiece_guess;   // 0x124
    char pad128_guess[0x158 - 0x128];
    int field158_guess;                 // 0x158
    // EXTERNAL: TITANIUM 0x005A3850 ??0MailScreenWndView_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    MailScreenWndView_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 MailScreenWndView_guess::~MailScreenWndView_guess
    ~MailScreenWndView_guess();
};

// view of a child window at the offsets the ctor touches
struct MailChild_guess {
    char pad_guess[0x20];
    struct Range_guess {
        int x, y;
        Range_guess(int a, int b) : x(a), y(b) {}
    } range_guess;                      // 0x20
    char pad24_guess[0x64 - 0x28];
    union {
        unsigned int style_guess;       // 0x64
        unsigned char bytes_guess[4];   // bytes_guess[2] is 0x66
    };
    char pad68_guess[0x15c - 0x68];
    unsigned char byte15c_guess;        // 0x15c
    char pad15d_guess[0x16c - 0x15d];
    int color16c_guess;                 // 0x16c
    char pad170_guess[0x22c - 0x170];
    CXStr text22c_guess;                // 0x22c
    void SetExcluded_guess(const CXStr& text) { text22c_guess = text; }
    void AddStyle_guess(unsigned int style) { style_guess |= style; }
    void SetMinimum_guess(Range_guess size) { range_guess = size; }
    // EXTERNAL: TITANIUM 0x004D7EBC MailChild_guess::SetMaxChars_guess
    void SetMaxChars_guess(int max);
};


// EXTERNAL: TITANIUM 0x0063FD9C ??_7MailNotifier_guess@@6B@
struct MailNotifier_guess {
    virtual void NotifySlot_guess() = 0;
    MailNotifier_guess() {}
    // EXTERNAL: TITANIUM 0x005482A0 MailNotifier_guess::Reset_guess
    void Reset_guess(int value);
    ~MailNotifier_guess() { Reset_guess(-1); }
};

// EXTERNAL: TITANIUM 0x006563B8 ??_7MailManagerListener_guess@@6B@
struct MailManagerListener_guess {
    virtual void ManagerSlot_guess() = 0;
    MailManagerListener_guess() {}
};

// EXTERNAL: TITANIUM 0x00657F28 ??_7CMailAddressBookWnd_guess@@6BMailScreenWndView_guess@@@
// EXTERNAL: TITANIUM 0x00658048 ??_7CMailAddressBookWnd_guess@@6BMailNotifier_guess@@@
// EXTERNAL: TITANIUM 0x00657F20 ??_7CMailAddressBookWnd_guess@@6BMailManagerListener_guess@@@
struct CMailAddressBookWnd_guess : MailScreenWndView_guess, MailNotifier_guess, MailManagerListener_guess {
    CXWnd* slots_guess[8];               // 0x164
    unsigned char flag184_guess;
    unsigned char flag185_guess;
    CMailAddressBookWnd_guess(CXWnd* parent);
};
TITANIUM_SIZE(MailScreenWndView_guess, 0x15C);
TITANIUM_SIZE(CMailAddressBookWnd_guess, 0x188);

#endif // TITANIUM_MAIL_ADDRESS_BOOK_H
