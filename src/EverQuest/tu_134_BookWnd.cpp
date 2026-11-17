// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 134: a hint from compare/tumap.py.
// CBookWnd (screen "BookWindow", pinst 0x850BA8; Mac map names most functions): a two-page book filled by
// ReadBook type 1. CBookWndView_guess, Owner_004e7fdd_guess and Selection_004e83e9_guess are all views of
// CBookWnd; CXStrView_guess is CXStr (one per page, 100 pages at +0x17C).
#include "titanium/types.h"

struct CXStrView_guess {
    int value;
    // EXTERNAL: TITANIUM 0x0053ACD9 CXStrView_guess::CXStrView_guess
    CXStrView_guess();
    // EXTERNAL: TITANIUM 0x00572040 CXStrView_guess::Setup_guess
    void Setup_guess(unsigned int flags);
    // EXTERNAL: TITANIUM 0x004482FB CXStrView_guess::Run_guess
    void Run_guess();
    // EXTERNAL: TITANIUM 0x004482FB CXStrView_guess::~CXStrView_guess
    ~CXStrView_guess();
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct SlotSetup_004e84e8_guess {
    // EXTERNAL: TITANIUM 0x00572040 SlotSetup_004e84e8_guess::Setup_guess
    void Setup_guess(unsigned int flags);
};

struct SidlPiece_004e84e8_guess {
    char pad_000[0x60];
    unsigned int style_060;
};

struct Page_004e84e8_guess {
    // EXTERNAL: TITANIUM 0x005B7EA0 Page_004e84e8_guess::SetPage_guess
    void SetPage_guess(int page);
};

struct TextSource_004e7fa3_guess {
    // EXTERNAL: TITANIUM 0x005E0EC0 TextSource_004e7fa3_guess::GetText_guess
    char* GetText_guess();
};

struct Layout_004e814e_guess {
    // EXTERNAL: TITANIUM 0x005A3A60 Layout_004e814e_guess::Wrap_guess
    int Wrap_guess(CXStr& text, const CXRect* screen, const CXRect* clip,
                   int width, int flags, int extra);
};

struct PageScreenVTable_004e814e_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual CXRect Slot57_guess();
};

// EXTERNAL: TITANIUM 0x00651358 ??_7CBookWndView_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z
struct CBookWndView_guess : CSidlScreenWndBase {
    CXStr bookText_15c_guess;
    CXWnd* rightButton_160;
    CXWnd* leftButton_164;
    CXWnd* doneButton_168;
    Page_004e84e8_guess* page0_16c;
    Page_004e84e8_guess* page1_170;
    CXWnd* page0Number_174;
    CXWnd* page1Number_178;
    CXStrView_guess pages_17c_guess[100];
    int index_30c;
    unsigned char flag_310;
    char text_311[0x403];
    TextSource_004e7fa3_guess* state_714;
    CBookWndView_guess(CXWnd* parent);
    bool SelectBook_guess(TextSource_004e7fa3_guess* source);
    // EXTERNAL: TITANIUM 0x005A2490 CBookWndView_guess::ChildNumber_guess
    CXWnd* ChildNumber_guess(const CXStr& name);
    // EXTERNAL: TITANIUM 0x004E814E CBookWndView_guess::PaginateText_guess
    void PaginateText_guess();
    void SetBookText_guess(const char* text);
    void ClearPages_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                               void* data_guess);
    virtual ~CBookWndView_guess();
};

struct NotifyActionVTable_004e885a_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
};

struct FlagTarget_004e83e9_guess {
    char pad_000[0x5d];
    bool active;
};

struct Option_004e83e9_guess {
    char pad_000[8];
    int value;
};

struct OptionIterator_004e83e9_guess {
    Option_004e83e9_guess** slot;
    Option_004e83e9_guess*& operator*() {
        return *slot;
    }
};

struct OptionArray_004e83e9_guess {
    Option_004e83e9_guess* values[0x62];
    OptionIterator_004e83e9_guess begin() {
        OptionIterator_004e83e9_guess result;
        result.slot = values;
        return result;
    }
};

OptionIterator_004e83e9_guess operator+(
    OptionIterator_004e83e9_guess iterator, int index) {
    iterator.slot += index;
    return iterator;
}

struct Selection_004e83e9_guess {
    char pad_000[0x160];
    FlagTarget_004e83e9_guess* primary;
    FlagTarget_004e83e9_guess* secondary;
    char pad_168[0x1c];
    OptionArray_004e83e9_guess options;
    int current;
    void ShowButtons_guess();
    int HandleKeyboardMsg_guess(int message_guess, unsigned flags_guess, char key_guess);
    // EXTERNAL: TITANIUM 0x0059D770 Selection_004e83e9_guess::Fallback_guess
    int Fallback_guess(int message_guess, unsigned flags_guess, char key_guess);
};

// EXTERNAL: TITANIUM 0x0060E620 strncpy_guess
char* __cdecl strncpy_guess(char* destination, const char* source, unsigned int count);

#define g_flag_00923d74_guess EQ_GLOBAL(int, 0x00923D74)
#define g_delimiter_00651314_guess EQ_ARRAY(char, 0x00651314)
#define g_whitespace_0063fe10_guess EQ_ARRAY(char, 0x0063FE10)
#define g_separator_00641588_guess EQ_ARRAY(char, 0x00641588)

// EXTERNAL: TITANIUM 0x00574390 Match_574390_guess
int __cdecl Match_574390_guess(const char* text, const char* pattern);
// EXTERNAL: TITANIUM 0x005742B0 Copy_5742b0_guess
int __cdecl Copy_5742b0_guess(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x004AE49C IsDoubleByteLanguage_guess
char __cdecl IsDoubleByteLanguage_guess(int value_guess);

// Picks the book being read: the same source again clears it (returns false); otherwise copies its name
// (0x5E0EC0) as the window title (+0x311, 1023 chars) and returns true. Called from 0x4B1DB0 (tu_069).
// FUNCTION: TITANIUM 0x004E7FA3
bool CBookWndView_guess::SelectBook_guess(TextSource_004e7fa3_guess* source) {
    TextSource_004e7fa3_guess** state = &state_714;
    if (source == *state) {
        *state = 0;
        return false;
    }
    *state = source;
    strncpy_guess(text_311, source->GetText_guess(), 0x3ff);
    return true;
}

struct Interface_004e7fdd_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual void Slot13_guess();
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Slot48_guess();
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual void Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void Slot63_guess(const CXStr& value_guess);
};

struct Target_004e7fdd_guess {
    // EXTERNAL: TITANIUM 0x005BD810 Target_004e7fdd_guess::SetText_guess
    void SetText_guess(const CXStr& text);
};

struct Owner_004e7fdd_guess {
    char pad_000[0x16c];
    Interface_004e7fdd_guess* interface_16c;  // 0x16c
    Interface_004e7fdd_guess* interface_170;  // 0x170
    Target_004e7fdd_guess* target_174;        // 0x174
    Target_004e7fdd_guess* target_178;        // 0x178
    CXStr entries_17c[100];                   // 0x17c
    int index_30c;                            // 0x30c
    void Function_004e7fdd_guess();
};

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* buffer, const char* format, ...);

// CBookWnd::DisplayText (Mac): shows pages `index` and `index + 1` and their numbers (1-based).
// FUNCTION: TITANIUM 0x004E7FDD
void Owner_004e7fdd_guess::Function_004e7fdd_guess() {
    char buf[128];
    if (target_174 != 0) {
        sprintf(buf, EQ_ARRAY(char, 0x0063F53C), index_30c + 1);
        CXStr text(buf);
        target_174->SetText_guess(text);
    }
    if (target_178 != 0) {
        sprintf(buf, EQ_ARRAY(char, 0x0063F53C), index_30c + 2);
        CXStr text(buf);
        target_178->SetText_guess(text);
    }
    if (interface_16c != 0) {
        interface_16c->Slot63_guess(entries_17c[index_30c]);
    }
    if (interface_170 != 0) {
        interface_170->Slot63_guess(entries_17c[index_30c + 1]);
    }
}

// Empties all 100 pages (CXStr::~CXStr on each, which nulls the pointer, so reuse is safe).
// FUNCTION: TITANIUM 0x004E8133
void CBookWndView_guess::ClearPages_guess() {
    int remaining = 100;
    CXStrView_guess* entry = pages_17c_guess;
    do {
        entry->Run_guess();
        ++entry;
    } while (--remaining != 0);
}

// Paginates the book text (+0x15C) into at most 100 pages of 12 lines, wrapped to Page0's width with its
// font and broken at the last space (anywhere in the double-byte languages); "`" forces a line break.
// FUNCTION: TITANIUM 0x004E814E
// @early-stop: budget, structural ndiff=28
void CBookWndView_guess::PaginateText_guess() {
    char buffer[0x800];
    CXRect clip = ((CXWnd*)page0_16c)->GetClientClipRect();
    CXRect screen = ((PageScreenVTable_004e814e_guess*)page0_16c)->Slot57_guess();
    Layout_004e814e_guess* layout =
        (Layout_004e814e_guess*)((CXWnd*)page0_16c)->pad_068[0];
    // The pages are emptied twice, by this call and the loop below (harmless; the shape matches).
    ClearPages_guess();
    char* text = bookText_15c_guess;
    int row = 0;
    int remaining = 100;
    CXStrView_guess* entry = pages_17c_guess;
    do {
        entry->Run_guess();
        ++entry;
    } while (--remaining != 0);
    if (*text != 0) {
        CXStr* cell = (CXStr*)pages_17c_guess;
        do {
            if (row >= 100) {
                break;
            }
            int column = 0;
            do {
                char* end = 0;
                char* token = text;
                buffer[0] = 0;
                char* output = buffer;
                if (*token == 0) {
                    end = token;
                } else {
                    int result;
                    while (true) {
                        if (Match_574390_guess(token, g_delimiter_00651314_guess) == 0) {
                            break;
                        }
                        // Some client languages (0x923D74) break anywhere,
                        // probably those written without spaces.
                        if (IsDoubleByteLanguage_guess(g_flag_00923d74_guess) != 0 ||
                            Match_574390_guess(token, g_whitespace_0063fe10_guess) == 0) {
                            end = token;
                        }
                        int copied = Copy_5742b0_guess(output, token);
                        output += copied;
                        token += copied;
                        *output = 0;
                        {
                            CXStr wrapped(buffer);
                            result = layout->Wrap_guess(wrapped, &screen, &clip,
                                                       // Measures only: over one line means full.
                                                       field_07C_guess, 2, 0);
                        }
                        if (result > 1 || *token == 0) {
                            break;
                        }
                    }
                    if (end == 0 ||
                        Match_574390_guess(token, g_delimiter_00651314_guess) == 0 ||
                        *token == 0) {
                        end = token;
                    }
                }
                int count = end - text;
                strncpy_guess(buffer, text, count);
                buffer[count] = 0;
                *cell += buffer;
                *cell += g_separator_00641588_guess;
                text = end;
                if (*text == 0) {
                    break;
                }
                if (Match_574390_guess(token, g_delimiter_00651314_guess) == 0 ||
                    Match_574390_guess(token, g_whitespace_0063fe10_guess) == 0) {
                    text = end + 1;
                }
                ++column;
            } while (column < 12);
            ++row;
            ++cell;
        } while (*text != 0);
    }
}

// CBookWnd::ShowButtons (Mac): Right is enabled while the next pair of pages has text, Left past page 0.
// FUNCTION: TITANIUM 0x004E83E9
void Selection_004e83e9_guess::ShowButtons_guess() {
    if (primary != 0) {
        primary->active = true;
        if (current < 0x62) {
            Option_004e83e9_guess* option = *(options.begin() + current);
            int value = option != 0 ? option->value : 0;
            if (value == 0) {
                primary->active = false;
            }
        } else {
            primary->active = false;
        }
    }
    if (secondary != 0) {
        secondary->active = true;
        if (current == 0) {
            secondary->active = false;
        }
    }
}

// CBookWnd::HandleKeyboardMsg (Mac): turns two pages on key-down of scan code 0xCD (Right arrow) or
// 0xCB (Left arrow), key flags exactly 1, when that button is enabled.
// FUNCTION: TITANIUM 0x004E8444
int Selection_004e83e9_guess::HandleKeyboardMsg_guess(int message_guess, unsigned flags_guess,
                                             char key_guess) {
    bool third_guess = (flags_guess & 4) != 0;
    bool first_guess = (flags_guess & 1) != 0;
    bool second_guess = (flags_guess & 2) != 0;
    switch (message_guess) {
    case 0xcd:
        if (first_guess && !second_guess && !third_guess &&
            key_guess != 0 && primary != 0 && primary->active) {
            current += 2;
            ((Owner_004e7fdd_guess*)this)->Function_004e7fdd_guess();
            ShowButtons_guess();
            return 0;
        }
        break;
    case 0xcb:
        if (first_guess && !second_guess && !third_guess &&
            key_guess != 0 && secondary != 0 && secondary->active) {
            current -= 2;
            ((Owner_004e7fdd_guess*)this)->Function_004e7fdd_guess();
            ShowButtons_guess();
            return 0;
        }
        break;
    }
    return Fallback_guess(message_guess, flags_guess, key_guess);
}

// CBookWnd::CBookWnd: loads "BookWindow" and finds the page, page-number and turn buttons.
// FUNCTION: TITANIUM 0x004E84E8
// @early-stop: budget, structural ndiff=33
CBookWndView_guess::CBookWndView_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "BookWindow") {
    // Also the CXStr preallocation size handed to every page string.
    unsigned int flags = 0x800;
    CSidlScreenWnd* self = (CSidlScreenWnd*)this;
    if (self->SidlPiece != 0) {
        self->WindowStyle |= ((SidlPiece_004e84e8_guess*)self->SidlPiece)->style_060 | flags;
        self->CreateChildrenFromSidl();
        ((SlotSetup_004e84e8_guess*)&bookText_15c_guess)->Setup_guess(flags);
        rightButton_160 = self->GetChildItem("RightButton");
        leftButton_164 = self->GetChildItem("LeftButton");
        doneButton_168 = self->GetChildItem("DoneButton");
        page0_16c = (Page_004e84e8_guess*)self->GetChildItem("Page0");
        if (page0_16c != 0) {
            page0_16c->SetPage_guess(0);
        }
        page1_170 = (Page_004e84e8_guess*)self->GetChildItem("Page1");
        if (page1_170 != 0) {
            page1_170->SetPage_guess(0);
        }
        page0Number_174 = 0;
        page1Number_178 = 0;
        page0Number_174 = (CXWnd*)ChildNumber_guess("Page0Number");
        page1Number_178 = (CXWnd*)ChildNumber_guess("Page1Number");
        index_30c = 0;
        flag_310 = 0;
        int remaining = 100;
        CXStrView_guess* entry = pages_17c_guess;
        do {
            entry->Setup_guess(flags);
            ++entry;
        } while (--remaining != 0);
        state_714 = 0;
        text_311[0] = 0;
    }
}

// Destructor of the book window (vtable 0x651358): empties all 100 pages (0x004E8133), destroys the
// page strings (+0x17C) and the title string (+0x15C), then runs the CSidlScreenWnd destructor
// (0x005A3100).
// FUNCTION: TITANIUM 0x004E877F
CBookWndView_guess::~CBookWndView_guess() {
    ClearPages_guess();
}

// Sets the book text (ReadBook type 1, tu_042), shows the saved title and paginates.
// FUNCTION: TITANIUM 0x004E87EF
void CBookWndView_guess::SetBookText_guess(const char* text) {
    bookText_15c_guess = text;
    {
        CXStr label(text_311);
        ((Interface_004e7fdd_guess*)this)->Slot63_guess(label);
    }
    PaginateText_guess();
}

// CBookWnd::WndNotification: Done hides the window (vtable slot 34); Right and Left turn two pages.
// FUNCTION: TITANIUM 0x004E885A
int CBookWndView_guess::WndNotification_guess(CXWnd* sender_guess,
                                                   unsigned int message_guess,
                                                   void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == doneButton_168) {
            ((NotifyActionVTable_004e885a_guess*)this)->Slot34_guess();
        } else if (sender_guess == rightButton_160) {
            index_30c += 2;
            ((Owner_004e7fdd_guess*)this)->Function_004e7fdd_guess();
            ((Selection_004e83e9_guess*)this)->ShowButtons_guess();
            return 1;
        } else if (sender_guess == leftButton_164) {
            index_30c -= 2;
            ((Owner_004e7fdd_guess*)this)->Function_004e7fdd_guess();
            ((Selection_004e83e9_guess*)this)->ShowButtons_guess();
            return 1;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess,
                                                     data_guess);
}

