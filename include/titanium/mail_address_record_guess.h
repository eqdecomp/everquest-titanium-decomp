#ifndef TITANIUM_MAIL_ADDRESS_RECORD_GUESS_H
#define TITANIUM_MAIL_ADDRESS_RECORD_GUESS_H

#include <stddef.h>
#include <string>
#include <vector>

// The address-book record passed to 0x0042BE14 and destroyed at 0x0040B867.
// Keep the implicit destructor visible: its STL members supply the compiler's
// exception information for cleanup in the address-book loader.
struct PurgeObject_guess {
    std::string first_guess;               // 0x00: name
    std::vector<std::string> middle_guess; // 0x1C: addresses
    std::string second_guess;              // 0x2C: note
    unsigned char flag_guess;              // 0x48: public
    union {
        unsigned char flag2_guess;         // 0x49
        unsigned char enabled_guess;
        unsigned char flag49_guess;
    };

    PurgeObject_guess(std::string firstArg_guess,
                      std::vector<std::string> middleArg_guess,
                      std::string secondArg_guess, bool flagArg_guess);
    PurgeObject_guess(const PurgeObject_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004285E1 PurgeObject_guess::Refresh_guess
    void Refresh_guess();
    PurgeObject_guess* CopyFrom_guess(const PurgeObject_guess& source_guess);
};

typedef PurgeObject_guess CompoundValue_guess;

typedef char MailAddressRecord_size_guess[(sizeof(PurgeObject_guess) == 0x4C) ? 1 : -1];
typedef char MailAddressRecord_addresses_offset_guess[
    (offsetof(PurgeObject_guess, middle_guess) == 0x1C) ? 1 : -1];
typedef char MailAddressRecord_note_offset_guess[
    (offsetof(PurgeObject_guess, second_guess) == 0x2C) ? 1 : -1];
typedef char MailAddressRecord_flags_offset_guess[
    (offsetof(PurgeObject_guess, flag_guess) == 0x48) ? 1 : -1];

#endif
