// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 67: a hint from compare/tumap.py.
// Grammar rules for localised strings: a rule's arguments "(a|b|c)" are split into ten 1 KB slots, then a
// per-language rule picks the right form (English a/an, Korean particles after a final consonant, French
// elision, German -s/-es). GrammarRules_guess is that rule engine; mode is the language (0 English, 1 Korean,
// 4 German, 5 French).
#include "titanium/eqaddr.h"

#include "titanium/core_decls.h"
// EXTERNAL: TITANIUM 0x0064B008 ??_7GrammarRules_guess@@6B@
struct GrammarRules_guess {
    GrammarRules_guess();
    virtual ~GrammarRules_guess() ;
    char* ParseArgs_guess(char* input);
    void RuleEn1_guess(void* destination, char* input);
    void WriteCapitalizedIndefiniteArticle_guess(char* destination, char* input);
    void RuleEn3_guess(char* destination, char* first, char* second,
        char* third);
    void RuleEn4_guess(char* destination, char* first, char* second,
        char* third);
    void RuleKo1_guess(char* destination, const char* source,
        const char* consonantSuffix, const char* vowelSuffix);
    void RuleFr1_guess(char* destination, const char* source,
        const char* vowelArticle, const char* consonantArticle);
    void RuleDe1_guess(char* destination, const char* source);
    char* Resolve_guess(int mode, int type, char* destination, char* input);
    void* Delete_guess(unsigned char flags);
    void* entries[10];
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060E450 Assign_guess
void __cdecl Assign_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0046DA4A Report_guess
void __cdecl Report_guess(void* object, int code, const char* message,
    int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);

extern "C" int __cdecl _isalpha(int value);

// EXTERNAL: TITANIUM 0x00621E9C _stricmp
extern "C" int __cdecl _stricmp(const char* left, const char* right);

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
extern "C" int __cdecl atoi(const char* text);

// EXTERNAL: TITANIUM 0x00574590 DecodeText_guess
void __cdecl DecodeText_guess(const char* source, unsigned short* destination,
    int count);

// EXTERNAL: TITANIUM 0x0060E460 Append_guess
void __cdecl Append_guess(char* destination, const char* source);

#define g_consonantText_guess EQ_ARRAY(char, 0x0063FE30)
#define g_vowelText_guess EQ_ARRAY(char, 0x00647A84)
#define g_invalidText_guess EQ_ARRAY(char, 0x00645EB4)
#define g_alphaConsonantText_guess EQ_ARRAY(char, 0x00641BA8)
#define g_alphaVowelText_guess EQ_ARRAY(char, 0x0064B00C)
#define g_alphaInvalidText_guess EQ_ARRAY(char, 0x00645EB0)
#define g_alphaNumberInvalidText_guess EQ_ARRAY(char, 0x00645EAC)
#define gNumberKey_guess EQ_ARRAY(char, 0x0064B010)
#define g_esSuffix_guess EQ_ARRAY(char, 0x0064504C)
#define g_sSuffix_guess EQ_ARRAY(char, 0x0064B014)

// Ten zeroed 1 KB buffers (+4): the slots 0x004B14FF fills with the '|'-separated words of a
// "(a|b|...)" grammar group.
// FUNCTION: TITANIUM 0x004B14A5
GrammarRules_guess::GrammarRules_guess() {
    int count = 10;
    void** entry = entries;
    do {
        *entry = operator new(0x400);
        memset(*entry, 0, 0x400);
        ++entry;
        --count;
    } while (count != 0);
}

// Destructor: frees the ten argument slots.
// FUNCTION: TITANIUM 0x004B14DD
GrammarRules_guess::~GrammarRules_guess()  {
    void** entry = entries;
    int count = 10;
    do {
        free(*entry);
        *entry = 0;
        ++entry;
        --count;
    } while (count != 0);
}

// Splits "(arg|arg|...)" at `input` into the slots and returns the text after the ')'; after the 10th slot
// it stops and returns one past the cursor without looking for ')'. An argument that reaches 1024
// characters is replaced by string 2318, "Entry Deleted due to buffer overrun".
// FUNCTION: TITANIUM 0x004B14FF
char* GrammarRules_guess::ParseArgs_guess(char* input) {
    char* cursor = input + 1;
    char ch = *cursor;
    int entry = 0;
    int index = 0;
    if (ch != ')') {
        void** output = entries;
        do {
            if (ch == 0) {
                break;
            }
            while (ch != '|' && ch != ')' && ch != 0) {
                ((char*)*output)[index] = ch;
                ++index;
                ++cursor;
                if (index == 0x400) {
                    const char* message = ((StringTable*)EQ_GLOBAL(void*, 0x00905CB0))->getString(0x90e, 0);
                    Assign_guess((char*)*output, message);
                    index = 0x3ff;
                }
                ch = *cursor;
            }
            ((char*)*output)[index] = 0;
            ++entry;
            ++output;
            index = 0;
            if (*cursor == '|') {
                ++cursor;
            }
            if (entry >= 10) {
                break;
            }
            ch = *cursor;
        } while (ch != ')');
    }
    return cursor + 1;
}

// English article for the word in `input`: the consonant form (a) or the vowel form (an). A, E,
// H, I, O and U count as vowels, so "an" goes before H. A non-letter reports string 2302, "Bad syntax in
// grammar rule %1".
// FUNCTION: TITANIUM 0x004B157E
void GrammarRules_guess::RuleEn1_guess(void* destination, char* input) {
    if (_isalpha((int)*input) != 0) {
        int ch = (int)*input;
        bool consonant = false;
        if (ch <= 'a') {
            if (ch != 'a' && ch != 'A' && ch != 'E') {
                if (ch <= 'G') {
                    consonant = true;
                } else if (ch > 'I' && ch != 'O') {
                    if (ch == 'U') {
                        consonant = false;
                    } else {
                        consonant = true;
                    }
                }
            }
        } else if (ch != 'e') {
            if (ch <= 'g') {
                consonant = true;
            } else if (ch > 'i' && ch != 'o') {
                if (ch == 'u') {
                    consonant = false;
                } else {
                    consonant = true;
                }
            }
        }
        if (consonant) {
            Assign_guess((char*)destination, g_consonantText_guess);
        } else {
            Assign_guess((char*)destination, g_vowelText_guess);
        }
    } else {
        Report_guess(destination, 0x8fe, g_invalidText_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }
}

// RuleEn1_guess with the capitalised pair, A or An.
// FUNCTION: TITANIUM 0x004B160F
void GrammarRules_guess::WriteCapitalizedIndefiniteArticle_guess(char* destination, char* input) {
    if (_isalpha((int)*input) != 0) {
        int ch = (int)*input;
        bool consonant = false;
        if (ch <= 'a') {
            if (ch != 'a' && ch != 'A' && ch != 'E') {
                if (ch <= 'G') {
                    consonant = true;
                } else if (ch > 'I' && ch != 'O') {
                    if (ch == 'U') {
                        consonant = false;
                    } else {
                        consonant = true;
                    }
                }
            }
        } else if (ch != 'e') {
            if (ch <= 'g') {
                consonant = true;
            } else if (ch > 'i' && ch != 'o') {
                if (ch == 'u') {
                    consonant = false;
                } else {
                    consonant = true;
                }
            }
        }
        if (consonant) {
            Assign_guess(destination, g_alphaConsonantText_guess);
        } else {
            Assign_guess(destination, g_alphaVowelText_guess);
        }
    } else {
        Report_guess(destination, 0x8fe, g_alphaInvalidText_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }
}

// Returns `third` when `first` starts with a vowel (same vowel set as RuleEn1_guess), else `second`.
// FUNCTION: TITANIUM 0x004B16A0
void GrammarRules_guess::RuleEn3_guess(char* destination, char* first, char* second,
    char* third) {
    if (_isalpha((int)*first) != 0) {
        int ch = (int)*first;
        bool consonant = false;
        if (ch <= 'a') {
            if (ch != 'a' && ch != 'A' && ch != 'E') {
                if (ch <= 'G') {
                    consonant = true;
                } else if (ch > 'I' && ch != 'O') {
                    if (ch == 'U') {
                        consonant = false;
                    } else {
                        consonant = true;
                    }
                }
            }
        } else if (ch != 'e') {
            if (ch <= 'g') {
                consonant = true;
            } else if (ch > 'i' && ch != 'o') {
                if (ch == 'u') {
                    consonant = false;
                } else {
                    consonant = true;
                }
            }
        }
        if (consonant) {
            Assign_guess(destination, second);
        } else {
            Assign_guess(destination, third);
        }
    } else {
        Report_guess(destination, 0x8fe, g_alphaNumberInvalidText_guess,
            0, 0, 0, 0, 0, 0, 0, 0);
    }
}

// True for a precomposed Hangul syllable (U+AC00-U+D7A3) with a final consonant (jongseong index, (value -
// U+AC00) % 28, not 0).
// FUNCTION: TITANIUM 0x004B1768
int __cdecl IsKoreanSyllableWithFinalConsonant_guess(unsigned int value) {
    if (value < 0xac00 || value > 0xd7a3) {
        return 0;
    }
    value -= 0xac00;
    unsigned int quotient = value / 0x24c;
    unsigned int firstRemainder = value - quotient * 0x24c;
    int secondRemainder = firstRemainder % 0x1c;
    return secondRemainder > 0;
}

// English count rule: `second` only when `first` matches the key at 0x64B010 and is not 1, else `third`;
// probably the singular/plural choice.
// FUNCTION: TITANIUM 0x004B172E
// @early-stop: budget, diff ndiff=4
void GrammarRules_guess::RuleEn4_guess(char* destination, char* first, char* second,
    char* third) {
    if (_stricmp(first, gNumberKey_guess) != 0 || atoi(first) == 1) {
        Assign_guess(destination, third);
    } else {
        Assign_guess(destination, second);
    }
}

// Korean particle: `consonantSuffix` after a final consonant on the last syllable of `source`, else
// `vowelSuffix`.
// FUNCTION: TITANIUM 0x004B17AA
void GrammarRules_guess::RuleKo1_guess(char* destination, const char* source,
    const char* consonantSuffix, const char* vowelSuffix) {
    unsigned short text[0x100];
    DecodeText_guess(source, text, 0x100);
    int index = 0;
    do {
        if (text[index] == 0) {
            --index;
            break;
        }
        ++index;
    } while (index < 0x100);
    int consonant = IsKoreanSyllableWithFinalConsonant_guess(text[index]);
    if (consonant != 0) {
        Assign_guess(destination, consonantSuffix);
    } else {
        Assign_guess(destination, vowelSuffix);
    }
}

// Vowels for the French rule: AEIOU and the accented Latin-1 vowels (0xC0-0xFB: A, E, I and U with grave,
// acute or circumflex).
// FUNCTION: TITANIUM 0x004B181B
char __cdecl IsFrenchVowel_guess(unsigned short value) {
    switch (value) {
    case 0x41:
    case 0x45:
    case 0x49:
    case 0x4f:
    case 0x55:
    case 0x61:
    case 0x65:
    case 0x69:
    case 0x6f:
    case 0x75:
    case 0xc0:
    case 0xc2:
    case 0xc8:
    case 0xc9:
    case 0xca:
    case 0xce:
    case 0xdb:
    case 0xe0:
    case 0xe2:
    case 0xe8:
    case 0xe9:
    case 0xea:
    case 0xee:
    case 0xfb:
        return 1;
    default:
        return 0;
    }
}

// French article: the elided form before a vowel or h (l'), else `consonantArticle`. Y counts as a vowel only
// when the next letter is not one.
// FUNCTION: TITANIUM 0x004B18BF
// @early-stop: unknown, structural ndiff=31
void GrammarRules_guess::RuleFr1_guess(char* destination, const char* source,
    const char* vowelArticle, const char* consonantArticle) {
    unsigned short text[0x100];
    memset(text, 0, sizeof(text));
    DecodeText_guess(source, text, 0x100);
    const char* article;
    switch (text[0]) {
    case 'A':
    case 'E':
    case 'H':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'h':
    case 'i':
    case 'o':
    case 'u':
    case 0xc0:
    case 0xc2:
    case 0xc8:
    case 0xc9:
    case 0xca:
    case 0xce:
    case 0xdb:
    case 0xe0:
    case 0xe2:
    case 0xe8:
    case 0xe9:
    case 0xea:
    case 0xee:
    case 0xfb:
        article = vowelArticle;
        break;
    case 'Y':
    case 'y':
        article = IsFrenchVowel_guess(text[1]) == 0 ? vowelArticle
                                            : consonantArticle;
        break;
    default:
        article = consonantArticle;
        break;
    }
    Assign_guess(destination, article);
    Append_guess(destination, source);
}

// German plural suffix: "es" after s, x, z or a final "ce", else "s".
// FUNCTION: TITANIUM 0x004B19E5
void GrammarRules_guess::RuleDe1_guess(char* destination, const char* source) {
    unsigned short text[0x100];
    memset(text, 0, sizeof(text));
    DecodeText_guess(source, text, 0x100);
    int index = 0;
    do {
        if (text[index] == 0) {
            --index;
            break;
        }
        ++index;
    } while (index < 0x100);
    unsigned short last = text[index];
    switch (last) {
    case L'e':
    case L'E':
        if (index < 1 || (text[index - 1] != L'c' && text[index - 1] != L'C')) {
            break;
        }
        // fall through
    case L's':
    case L'S':
    case L'x':
    case L'X':
    case L'z':
    case L'Z':
        Assign_guess(destination, source);
        Append_guess(destination, g_esSuffix_guess);
        return;
    }
    Assign_guess(destination, source);
    Append_guess(destination, g_sSuffix_guess);
}

// Scalar deleting destructor of the grammar rule engine (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004B1AAF
void* GrammarRules_guess::Delete_guess(unsigned char flags) {
    this->GrammarRules_guess::~GrammarRules_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Runs rule `type` for language `mode` on the arguments at `input`; returns the text after them. Unknown
// pairs report string 2302.
// FUNCTION: TITANIUM 0x004B1ACB
char* GrammarRules_guess::Resolve_guess(int mode, int type, char* destination,
    char* input) {
    char* result = ParseArgs_guess(input);
    switch (mode) {
    case 0:
        switch (type) {
        case 1:
            RuleEn1_guess(destination, (char*)entries[0]);
            return result;
        case 2:
            WriteCapitalizedIndefiniteArticle_guess(destination, (char*)entries[0]);
            return result;
        case 3:
            RuleEn3_guess(destination, (char*)entries[0],
                (char*)entries[1], (char*)entries[2]);
            return result;
        case 4:
            RuleEn4_guess(destination, (char*)entries[0],
                (char*)entries[1], (char*)entries[2]);
            return result;
        }
        break;
    case 1:
        switch (type) {
        case 1:
            RuleKo1_guess(destination, (char*)entries[0],
                (char*)entries[1], (char*)entries[2]);
            return result;
        }
    // Mode 1 and 5 fall through into the next language's switch (no break), as in the original.
    case 5:
        switch (type) {
        case 1:
            RuleFr1_guess(destination, (char*)entries[0],
                (char*)entries[1], (char*)entries[2]);
            return result;
        }
    case 4:
        switch (type) {
        case 1:
            RuleDe1_guess(destination, (char*)entries[0]);
            return result;
        }
        break;
    }
    Report_guess(destination, 0x8fe, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    return result;
}

