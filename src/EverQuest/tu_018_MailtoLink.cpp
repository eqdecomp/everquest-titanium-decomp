// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 18: a hint from compare/tumap.py.
// The in-game mail client, which talks to the Universal Chat service in bracketed text commands
// ("[getheaders", "[getbody <id>", "[selectmailbox <n>", "[setmailforwarding", "[mailto"), plus the
// address book file and channel-name qualification. Most of the rest is VC7.1 STL code instantiated here
// (string, map/set trees, list, streams).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <new>
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include "titanium/mail_address_record_guess.h"

// EXTERNAL: TITANIUM 0x006731A4 ??_7Message_guess@@6B@
struct EmptyDestructor_guess {
    ~EmptyDestructor_guess() {}
};

struct Message_guess {
    virtual void Slot00_guess();
    EmptyDestructor_guess lifetime_guess;
    Message_guess* Delete_guess(unsigned char flags_guess);
    ~Message_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

struct BasicStringCopy_guess;

struct ExceptionBase_guess {
    // EXTERNAL: TITANIUM 0x004036B8 ExceptionBase_guess::ExceptionBase_guess
    ExceptionBase_guess(const char* message_guess);
    // EXTERNAL: TITANIUM 0x0040354C ??0ExceptionBase_guess@@QAE@ABUBasicStringCopy_guess@@@Z
    ExceptionBase_guess(const BasicStringCopy_guess& message_guess);
    // EXTERNAL: TITANIUM 0x00403026 ExceptionBase_guess::~ExceptionBase_guess
    virtual ~ExceptionBase_guess();
    int what_guess;                   // 0x4
    int doFree_guess;                 // 0x8
    unsigned int message_guess[7];    // 0xC
};

// EXTERNAL: TITANIUM 0x00673238 ??_7ExceptionDerived_guess@@6B@
struct ExceptionDerived_guess : ExceptionBase_guess {
    ExceptionDerived_guess(const char* message_guess);
    ExceptionDerived_guess(const BasicStringCopy_guess& message_guess)
        : ExceptionBase_guess(message_guess) {}
    ExceptionDerived_guess* Delete_guess(unsigned char flags_guess);
    virtual ~ExceptionDerived_guess();
};

struct AdjustedObject_guess {
    unsigned char byte_guess;
    // EXTERNAL: TITANIUM 0x00401C6C AdjustedObject_guess::DestroyPart_guess
    void DestroyPart_guess();
    void Destroy_guess();
    AdjustedObject_guess* Delete_guess(unsigned char flags_guess);
};

struct DeletePart64_guess {
    unsigned char field_guess;
    // EXTERNAL: TITANIUM 0x00401C6C DeletePart64_guess::~DeletePart64_guess
    ~DeletePart64_guess();
};

struct DeletePrefix64_guess : DeletePart64_guess {
    unsigned char padding_guess[0x63];
};

struct DeleteObject64_guess;

struct DeleteSecondary64_guess {
    unsigned int field_guess;
    DeleteObject64_guess* Delete_guess(unsigned char flags_guess);
};

struct DeleteObject64_guess : DeletePrefix64_guess, DeleteSecondary64_guess {
    virtual ~DeleteObject64_guess();
};

struct BufferReader_guess {
    unsigned char* data_guess;    // 0x0
    unsigned int capacity_guess;  // 0x4
    unsigned int position_guess;  // 0x8
    void CopyTo_guess(void* destination_guess, unsigned int size_guess);
};

struct BytePair_guess {
    unsigned char padding_guess[0x9c];
    unsigned char byte9c_guess;
    unsigned char byte9d_guess;
    void Set9C_guess(unsigned char value_guess);
    void Set9D_guess(unsigned char value_guess);
};

struct TreeNode_guess {
    TreeNode_guess* left_guess;    // 0x0
    TreeNode_guess* parent_guess;  // 0x4
    TreeNode_guess* right_guess;   // 0x8
    unsigned int key_guess;        // 0xC
    int value_guess;               // 0x10
    unsigned char padding_guess[0x18];
    unsigned char color_guess;     // 0x2C
    unsigned char isNil_guess;     // 0x2D
    // EXTERNAL: TITANIUM 0x0042839B TreeNode_guess::TreeNode_guess
    TreeNode_guess(TreeNode_guess* left_guess, TreeNode_guess* parent_guess,
                   TreeNode_guess* right_guess, const unsigned int& key_guess,
                   unsigned char color_guess);
};

struct TreeIter_guess {
    TreeNode_guess* node_guess;    // 0x0
    TreeIter_guess() {}
    TreeIter_guess(TreeNode_guess* node_guess) : node_guess(node_guess) {}
    TreeIter_guess(const TreeIter_guess& source_guess) : node_guess(source_guess.node_guess) {}
    // EXTERNAL: TITANIUM 0x004252FB ??FTreeIter_guess@@QAEAAU0@XZ
    TreeIter_guess& operator--();
    // EXTERNAL: TITANIUM 0x0042533A ??ETreeIter_guess@@QAEAAU0@XZ
    TreeIter_guess& operator++();
};

struct TreeInsertResult_guess {
    TreeIter_guess first_guess;    // 0x0
    bool second_guess;             // 0x4
    TreeInsertResult_guess(const TreeIter_guess& first_guess, const bool& second_guess)
        : first_guess(first_guess), second_guess(second_guess) {}
};

struct StringRecord_guess;

struct Tree_guess {
    unsigned char padding_guess[4];
    TreeNode_guess* head_guess;    // 0x4
    unsigned int size_guess;       // 0x8
    Tree_guess(const Tree_guess& source_guess);
    // EXTERNAL: TITANIUM 0x0042610D Tree_guess::Init_guess
    void Init_guess();
    void Assign_guess(const Tree_guess& source_guess);
    TreeNode_guess* Lbound_guess(const unsigned int& key_guess);
    // EXTERNAL: TITANIUM 0x0042AC08 Tree_guess::InsertNode_guess
    TreeIter_guess& InsertNode_guess(TreeIter_guess& result_guess, bool addLeft_guess,
                                     TreeNode_guess* where_guess, const unsigned int& key_guess);
    TreeNode_guess* BuyNode_guess(TreeNode_guess* head_guess, TreeNode_guess* parent_guess,
                                  TreeNode_guess* head2_guess, const unsigned int& key_guess,
                                  unsigned char color_guess);
    TreeNode_guess* Copy_guess(TreeNode_guess* source_guess, TreeNode_guess* parent_guess);
    void EraseSubtree_guess(TreeNode_guess* root_guess);
    TreeInsertResult_guess Insert_guess(const unsigned int& key_guess);
    // EXTERNAL: TITANIUM 0x0042BBB2 Tree_guess::InsertAt_guess
    TreeIter_guess InsertAt_guess(TreeNode_guess* hint_guess, const StringRecord_guess& value_guess);
    int* Subscript_guess(const unsigned int& key_guess);
};

struct StringStorage_guess {
    // EXTERNAL: TITANIUM 0x0040291E StringStorage_guess::Tidy_guess
    // fake match: throw() lever
    void Tidy_guess(bool tidy_guess, unsigned int reserve_guess) throw();
};

struct StringOwner_guess {
    int prefix_guess;
    StringStorage_guess value_guess;
    void Release_guess();
};

struct StringOwnerAt10_guess {
    unsigned char padding_guess[0x10];
    StringStorage_guess value_guess;
    void Release_guess();
};

struct DualStringOwner_guess {
    unsigned char padding0_guess[0xc];
    StringStorage_guess first_guess;       // 0xC
    unsigned char padding1_guess[0x1b];
    StringStorage_guess second_guess;      // 0x28
    void Release_guess();
};

struct RandomTag_guess {
};

inline RandomTag_guess IterCat_guess(const char*)
{
    RandomTag_guess tag_guess;
    return tag_guess;
}

struct BasicStringIterator_guess {
    char* pointer_guess;
    BasicStringIterator_guess(const BasicStringIterator_guess& source_guess)
        : pointer_guess(source_guess.pointer_guess) {}
    operator char*() const { return pointer_guess; }
};

struct BasicStringCopy_guess {
    unsigned int prefix_guess;    // 0x0
    char buffer_guess[16];        // 0x4, small-string buffer
    unsigned int length_guess;    // 0x14
    unsigned int capacity_guess; // 0x18
    // EXTERNAL: TITANIUM 0x00402505 BasicStringCopy_guess::Eos_guess
    void Eos_guess(unsigned int position_guess);
    BasicStringCopy_guess() {
        capacity_guess = 0xf;
        Eos_guess(0);
    }
    // EXTERNAL: TITANIUM 0x004032F1 BasicStringCopy_guess::BasicStringCopy_guess
    BasicStringCopy_guess(const BasicStringCopy_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00403631 ??0BasicStringCopy_guess@@QAE@PBD@Z
    BasicStringCopy_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00402902 BasicStringCopy_guess::End_guess
    BasicStringIterator_guess End_guess() const;
    // EXTERNAL: TITANIUM 0x00403174 BasicStringCopy_guess::Assign_guess
    BasicStringCopy_guess* Assign_guess(const BasicStringCopy_guess& source_guess,
                                        unsigned int position_guess, unsigned int count_guess);
    BasicStringCopy_guess(const char* first_guess, const char* last_guess);
    void Construct_guess(const char* first_guess, const char* last_guess, RandomTag_guess tag_guess);
    // EXTERNAL: TITANIUM 0x00425E74 BasicStringCopy_guess::reserve_guess
    void reserve_guess(unsigned int count_guess);
    // EXTERNAL: TITANIUM 0x00402FC6 BasicStringCopy_guess::append_guess
    BasicStringCopy_guess& append_guess(unsigned int count_guess, char char_guess);
    // EXTERNAL: TITANIUM 0x004261A1 BasicStringCopy_guess::AppendString_guess
    BasicStringCopy_guess* AppendString_guess(const BasicStringCopy_guess& text_guess,
                                               unsigned int position_guess, unsigned int count_guess);
    // EXTERNAL: TITANIUM 0x00427607 BasicStringCopy_guess::Append_guess
    BasicStringCopy_guess& Append_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00427624 BasicStringCopy_guess::Insert_guess
    BasicStringCopy_guess& Insert_guess(unsigned int position_guess, const char* text_guess);
    // EXTERNAL: TITANIUM 0x00425A32 BasicStringCopy_guess::FindString_guess
    int FindString_guess(const BasicStringCopy_guess& text_guess, unsigned int position_guess) const;
    // EXTERNAL: TITANIUM 0x00425A55 BasicStringCopy_guess::FindText_guess
    int FindText_guess(const char* text_guess, unsigned int position_guess) const;
    // EXTERNAL: TITANIUM 0x00427645 BasicStringCopy_guess::Substr_guess
    BasicStringCopy_guess Substr_guess(unsigned int position_guess, unsigned int count_guess) const;
    unsigned int Length_guess() const {
        return length_guess;
    }
    char* Begin_guess() {
        return capacity_guess >= 0x10 ? *(char**)buffer_guess : buffer_guess;
    }
    BasicStringCopy_guess& operator=(const BasicStringCopy_guess& source_guess) {
        Assign_guess(source_guess, 0, 0xffffffff);
        return *this;
    }
    ~BasicStringCopy_guess() {
        ((StringStorage_guess*)this)->Tidy_guess(true, 0);
    }
};

struct WidenBase_guess {
    // EXTERNAL: TITANIUM 0x00402CAB WidenBase_guess::Widen_guess
    char Widen_guess(char value_guess);
};

struct Stream_guess : virtual WidenBase_guess {
    unsigned char padding_guess[0x10];
};

// EXTERNAL: TITANIUM 0x00403448 FUN_00403448_guess
int __cdecl FUN_00403448_guess(Stream_guess* first_guess, Stream_guess* second_guess, char value_guess);

struct StringRecord_guess {
    unsigned int first_guess;
    BasicStringCopy_guess text_guess;
    StringRecord_guess(const unsigned int& first_guess, const BasicStringCopy_guess& text_guess);
    StringRecord_guess(const StringRecord_guess& source_guess);
};

struct BasicStringAt0_guess {
    unsigned int prefix_guess;       // 0x0
    char buffer_guess[16];           // 0x4
    unsigned int length_guess;       // 0x14
    unsigned int capacity_guess;     // 0x18
    const char* CStr_guess() const {
        return capacity_guess >= 0x10 ? *(const char**)buffer_guess : buffer_guess;
    }
    // EXTERNAL: TITANIUM 0x00402E5E ??0BasicStringAt0_guess@@QAE@XZ
    BasicStringAt0_guess();
    // EXTERNAL: TITANIUM 0x004032F1 ??0BasicStringAt0_guess@@QAE@ABU0@@Z
    BasicStringAt0_guess(const BasicStringAt0_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00403174 BasicStringAt0_guess::Assign_guess
    BasicStringAt0_guess* Assign_guess(const BasicStringAt0_guess& source_guess,
                                       unsigned int position_guess, unsigned int count_guess);
    // EXTERNAL: TITANIUM 0x0040291E BasicStringAt0_guess::Tidy_guess
    void Tidy_guess(bool tidy_guess, unsigned int reserve_guess);
    ~BasicStringAt0_guess() {
        Tidy_guess(true, 0);
    }
};

struct DualStringRecord_guess {
    unsigned int firstValue_guess;     // 0x0
    unsigned int secondValue_guess;    // 0x4
    unsigned int thirdValue_guess;     // 0x8
    BasicStringAt0_guess firstText_guess;  // 0xc
    BasicStringAt0_guess secondText_guess; // 0x28
    DualStringRecord_guess* CopyFrom_guess(const DualStringRecord_guess& source_guess);
};

struct ExtensionPolicy_guess {
    // EXTERNAL: TITANIUM 0x0049297B ExtensionPolicy_guess::Check_guess
    int Check_guess(const char* text_guess);
};

#define g_extensionPolicy_guess EQ_GLOBAL(ExtensionPolicy_guess*, 0x00988DF0)

struct PathString_guess {
    unsigned int prefix_guess;
    char buffer_guess[16];
    unsigned int length_guess;
    unsigned int capacity_guess;
    // EXTERNAL: TITANIUM 0x00403631 PathString_guess::PathString_guess
    PathString_guess(const char* text_guess);
    PathString_guess() {}
    unsigned int Rfind_guess(const char* text_guess, unsigned int position_guess,
                             unsigned int count_guess) const;
    // EXTERNAL: TITANIUM 0x00425491 PathString_guess::Find_guess
    int Find_guess(const char* text_guess, unsigned int position_guess, unsigned int count_guess) const;
    PathString_guess Substr_guess(unsigned int position_guess, unsigned int count_guess) const;
    const char* CStr_guess() const {
        return capacity_guess >= 0x10 ? *(const char**)buffer_guess : buffer_guess;
    }
    ~PathString_guess() {
        ((StringStorage_guess*)this)->Tidy_guess(true, 0);
    }
};

struct ExtensionCheck_guess {
    bool Check_guess(const char* path_guess);
};

struct MailSender_guess {
    // EXTERNAL: TITANIUM 0x005FF560 MailSender_guess::Send_guess
    void Send_guess(const char* text_guess);
};

struct MailHost_guess {
    unsigned char padding_guess[0x834];
    MailSender_guess* sender_guess;    // 0x834
};

#define g_mailHost_guess EQ_GLOBAL(MailHost_guess*, 0x00988DF0)

struct Collection_guess {
    std::list<int> first_guess;                  // 0x00
    std::vector<std::string> mailboxes_guess;    // 0x0C
    unsigned int selected_guess;                 // 0x1C
    int value20_guess;                           // 0x20
    void SelectMailbox_guess(unsigned int index_guess);
    void Commit_guess();
};

// Reads `size_guess` bytes from the buffer; a read past the end copies nothing and does not advance.
// FUNCTION: TITANIUM 0x004250AA
void BufferReader_guess::CopyTo_guess(void* destination_guess, unsigned int size_guess)
{
    if (position_guess + size_guess <= capacity_guess) {
        memcpy(destination_guess, data_guess + position_guess, size_guess);
        position_guess += size_guess;
    }
}

// Returns 1.
// FUNCTION: TITANIUM 0x004250F0
int __cdecl ReturnOne_guess()
{
    return 1;
}

// Sets the byte at +0x9C; the options window calls it.
// FUNCTION: TITANIUM 0x004250F4
void BytePair_guess::Set9C_guess(unsigned char value_guess)
{
    this->byte9c_guess = value_guess;
}

// Sets the byte at +0x9D; the options window calls it.
// FUNCTION: TITANIUM 0x00425101
void BytePair_guess::Set9D_guess(unsigned char value_guess)
{
    this->byte9d_guess = value_guess;
}

// Next space-separated token of `text_guess`, or a "quoted" one; false at the end of the text.
// FUNCTION: TITANIUM 0x0042510E
bool __cdecl GetNextToken_guess(const char* text_guess, const char** first_guess, const char** last_guess)
{
    char delimiter_guess = ' ';
    while (*text_guess == ' ') {
        ++text_guess;
    }
    if (*text_guess == '\0') {
        return 0;
    }
    *first_guess = text_guess;
    if (*text_guess == '"') {
        delimiter_guess = '"';
        *first_guess = text_guess + 1;
    }
    *last_guess = *first_guess;
    while (*text_guess != '\0') {
        ++text_guess;
        if (*text_guess == delimiter_guess) {
            *last_guess = text_guess;
            break;
        }
    }
    return *last_guess != *first_guess;
}

// std::find for chars: the first position in [first, last) holding `*target`, else `last`.
// FUNCTION: TITANIUM 0x00425370
char* __cdecl FindChar_guess(char* first_guess, char* last_guess, const char* target_guess)
{
    if (first_guess != last_guess) {
        char value_guess = *target_guess;
        do {
            if (*first_guess == value_guess) {
                return first_guess;
            }
            ++first_guess;
        } while (first_guess != last_guess);
    }
    return first_guess;
}

struct ListNode_guess {
    ListNode_guess* next_guess;   // 0x0
    ListNode_guess* prev_guess;   // 0x4
    int value_guess;              // 0x8
};

struct IterBase_guess {
};

struct ListIter_guess : IterBase_guess {
    ListNode_guess* node_guess;   // 0x0
    ListIter_guess(ListNode_guess* node_guess) : node_guess(node_guess) {}
    ListIter_guess& operator++() {
        node_guess = node_guess->next_guess;
        return *this;
    }
    bool operator!=(const ListIter_guess& other_guess) const {
        return node_guess != other_guess.node_guess;
    }
    int& operator*() const { return node_guess->value_guess; }
};

// Lower bound in the tree keyed by unsigned int: the first node whose key is not below `key`, else the
// head (end).
// FUNCTION: TITANIUM 0x004256F0
TreeNode_guess* Tree_guess::Lbound_guess(const unsigned int& key_guess)
{
    TreeNode_guess* prev_guess = head_guess;
    TreeNode_guess* node_guess = prev_guess->parent_guess;
    while (node_guess->isNil_guess == 0) {
        if (node_guess->key_guess < key_guess) {
            node_guess = node_guess->right_guess;
        } else {
            prev_guess = node_guess;
            node_guess = node_guess->left_guess;
        }
    }
    return prev_guess;
}

// Standard library: std::find over a list of ints.
// FUNCTION: TITANIUM 0x00425768
ListIter_guess __cdecl FindListValue_guess(ListIter_guess first_guess, ListIter_guess last_guess,
                                          const int& value_guess)
{
    for (; first_guess != last_guess; ++first_guess) {
        if (*first_guess == value_guess) {
            break;
        }
    }
    return first_guess;
}

// std::count for chars: how many chars in [first, last) equal `*target`. The channel name qualifier
// 0x0042A439 counts periods with it.
// FUNCTION: TITANIUM 0x0042578B
int __cdecl CountChar_guess(const char* first_guess, const char* last_guess, const char* target_guess)
{
    int count_guess = 0;
    if (first_guess != last_guess) {
        char value_guess = *target_guess;
        do {
            if (*first_guess == value_guess) {
                ++count_guess;
            }
            ++first_guess;
        } while (first_guess != last_guess);
    }
    return count_guess;
}

// Standard library: std::replace of one char by another in [first, last); channel names use it to turn
// spaces into underscores.
// FUNCTION: TITANIUM 0x004257AA
void __cdecl ReplaceChar_guess(char* first_guess, char* last_guess, const char* target_guess,
                                const char* replacement_guess)
{
    for (; first_guess != last_guess; ++first_guess) {
        if (*first_guess == *target_guess) {
            *first_guess = *replacement_guess;
        }
    }
}

struct CollectionEntry_guess {
    int unknown_000_guess;   // 0x0
    int value004_guess;      // 0x4
    int status_guess;        // 0x8
    std::string sender_guess;    // 0xC
    std::string subject_guess;   // 0x28
};

struct CollectionIterator_guess {
    void* array_000_guess;   // 0x0
    int index_004_guess;     // 0x4
    CollectionIterator_guess() {}
    CollectionIterator_guess(void* array_guess, int index_guess)
        : array_000_guess(array_guess), index_004_guess(index_guess) {}
    // EXTERNAL: TITANIUM 0x00425170 CollectionIterator_guess::Deref_guess
    CollectionEntry_guess*& Deref_guess() const;
    // EXTERNAL: TITANIUM 0x00491002 CollectionIterator_guess::Equals_guess
    bool Equals_guess(const CollectionIterator_guess& other_guess) const;
    // EXTERNAL: TITANIUM 0x00425196 CollectionIterator_guess::Less_guess
    bool Less_guess(const CollectionIterator_guess& other_guess) const;
};

struct DualStringCtor_guess;

struct CollectionState_guess {
    unsigned char padding_guess[0xc];
    int first_guess;         // 0xC
    int count_guess;         // 0x10
    // EXTERNAL: TITANIUM 0x00426DC3 CollectionState_guess::Erase_guess
    CollectionIterator_guess Erase_guess(CollectionIterator_guess where_guess);
    // EXTERNAL: TITANIUM 0x0042AA48 CollectionState_guess::Insert_guess
    void Insert_guess(DualStringCtor_guess*& item_guess);
    CollectionIterator_guess Begin_guess() {
        return CollectionIterator_guess(this, first_guess);
    }
    CollectionIterator_guess End_guess() {
        return CollectionIterator_guess(this, first_guess + count_guess);
    }
};

struct CollectionRoot_guess {
    unsigned char padding_guess[0x24];
    CollectionState_guess state_guess;
    CollectionEntry_guess* Find_guess(int value_guess);
};

struct MailStatusTable_guess {
    unsigned char padding_guess[0x24];
    CollectionState_guess state_guess;   // 0x24
    unsigned char padding1_guess[0x18];  // 0x38
    unsigned char pending_guess;         // 0x50
    unsigned char padding2_guess[3];
    int value54_guess;
    int value58_guess;
    int value5c_guess;
    void ReportMessages_guess(int count_guess, const unsigned int* ids_guess);
    // EXTERNAL: TITANIUM 0x00402D37 MailStatusTable_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    void SetStatuses_guess(const unsigned int* ids_guess, int count_guess, int status_guess);
};

struct MessageInfoRoot_guess {
    unsigned char padding_guess[8];
    void* messageInfo_guess;       // 0x8
};

struct MessageInfoOffset_guess {
    int value000_guess;
    int vbaseOffset_0004_guess;           // 0x4
};

#define g_messageInfoRoot_guess EQ_GLOBAL(MessageInfoRoot_guess*, 0x00905D00)

// First mail header in [first, last) with message id `value_guess`.
// FUNCTION: TITANIUM 0x004257CA
CollectionIterator_guess __cdecl FindMailHeaderById_guess(CollectionIterator_guess first_guess,
                                                    CollectionIterator_guess last_guess, int value_guess)
{
    while (!first_guess.Equals_guess(last_guess)) {
        if (first_guess.Deref_guess()->unknown_000_guess == value_guess) {
            break;
        }
        ++first_guess.index_004_guess;
    }
    return first_guess;
}

// Standard library: scalar deleting destructor of a locale facet (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004258A7
Message_guess* Message_guess::Delete_guess(unsigned char flags_guess)
{
    this->~Message_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Empty destructor.
// FUNCTION: TITANIUM 0x004258C3
Message_guess::~Message_guess()
{
}

// codecvt::do_in for the no-conversion facet: hands the input back unchanged and returns 3 (noconv).
// FUNCTION: TITANIUM 0x00425919
unsigned int __stdcall do_in_guess(unsigned int unused1_guess,
                                          unsigned int value1_guess,
                                          unsigned int unused3_guess,
                                          unsigned int* output1_guess,
                                          unsigned int value2_guess,
                                          unsigned int unused6_guess,
                                          unsigned int* output2_guess)
{
    *output1_guess = value1_guess;
    *output2_guess = value2_guess;
    return 3;
}

// codecvt::do_length: min(last - first, limit).
// FUNCTION: TITANIUM 0x00425939
unsigned int __stdcall do_length_guess(unsigned int unused1_guess,
                                          unsigned int first_guess,
                                          unsigned int last_guess,
                                          unsigned int limit_guess)
{
    unsigned int difference_guess = last_guess - first_guess;
    if (limit_guess < difference_guess) {
        difference_guess = limit_guess;
    }
    return difference_guess;
}

struct StringRep_guess {
    unsigned char padding_guess[4];  // 0x0
    union {
        char buffer_guess[16];       // 0x4, small-string buffer
        char* pointer_guess;         // 0x4, heap buffer
    };
    unsigned int length_guess;       // 0x14
    unsigned int capacity_guess;     // 0x18
};

struct StringRef_guess {
    StringRep_guess* rep_guess;      // 0x0
    StringRef_guess(const std::string& text_guess)
        : rep_guess((StringRep_guess*)&text_guess) {}
    bool Equals_guess(const StringRep_guess* other_guess) const;
};

// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* first_guess, const char* second_guess);

// Case-insensitive compare (0x574950) of the two strings' text, small-buffer aware (capacity < 16 means
// inline).
// FUNCTION: TITANIUM 0x0042599F
bool StringRef_guess::Equals_guess(const StringRep_guess* other_guess) const
{
    const char* first_guess = rep_guess->capacity_guess >= 0x10
        ? rep_guess->pointer_guess : rep_guess->buffer_guess;
    const char* second_guess = other_guess->capacity_guess >= 0x10
        ? other_guess->pointer_guess : other_guess->buffer_guess;
    return FUN_00574950_guess(second_guess, first_guess) == 0;
}

// The mail header with id `value` in the header collection (+0x24, searched by 0x004257CA), or null.
// FUNCTION: TITANIUM 0x004259D2
// @early-stop: budget, diff ndiff=11
CollectionEntry_guess* CollectionRoot_guess::Find_guess(int value_guess)
{
    CollectionState_guess* state_guess_ptr = &state_guess;
    CollectionIterator_guess found_guess;
    found_guess = FindMailHeaderById_guess(state_guess_ptr->Begin_guess(),
                                     state_guess_ptr->End_guess(), value_guess);
    if (!found_guess.Equals_guess(state_guess_ptr->End_guess())) {
        return found_guess.Deref_guess();
    }
    return 0;
}

// Standard library: std::find of a string in a list of strings.
// FUNCTION: TITANIUM 0x00425D79
void __cdecl FindStringInList_guess(ListNode_guess** result_guess, ListNode_guess* first_guess,
                                ListNode_guess* last_guess, StringRef_guess target_guess)
{
    for (; first_guess != last_guess; first_guess = first_guess->next_guess) {
        if (target_guess.Equals_guess((StringRep_guess*)first_guess->value_guess)) {
            break;
        }
    }
    *result_guess = first_guess;
}

struct Holder_guess;

struct Index_guess {
    unsigned char storage_guess[4];
    // EXTERNAL: TITANIUM 0x00425F18 Index_guess::Find_guess
    int* Find_guess(Holder_guess*& owner_guess, const int& key_guess);
};

struct Holder_guess {
    unsigned char padding_guess[0x38];
    Index_guess index_guess;   // 0x38
    int value_guess;           // 0x3C
    int Check_guess(int key_guess);
};

struct DeletePrefix_guess {
    unsigned char padding_guess[0x4c];
};

struct DeleteBase_guess;
struct DeleteObject_guess;

struct DeleteBase_guess {
    DeleteObject_guess* Delete_guess(unsigned char flags_guess);
};

struct DeleteObject_guess : DeletePrefix_guess, DeleteBase_guess {
    // EXTERNAL: TITANIUM 0x00425EBE DeleteObject_guess::~DeleteObject_guess
    ~DeleteObject_guess();
};

// Scalar deleting destructor: destroys the object and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00425F52
// @early-stop: budget, structural ndiff=6
DeleteObject_guess* DeleteBase_guess::Delete_guess(unsigned char flags_guess)
{
    DeleteObject_guess& object_ref_guess = static_cast<DeleteObject_guess&>(*this);
    DeleteObject_guess* object_guess = &object_ref_guess;
    object_guess->~DeleteObject_guess();
    if ((flags_guess & 1) != 0) {
        ::operator delete(object_guess);
    }
    return object_guess;
}

struct OwnerPrefix_guess {
    int value_guess;
};

struct OwnerPart_guess {
    void* Delete_guess(unsigned char flags_guess);
};

struct PartOwner_guess : OwnerPrefix_guess, OwnerPart_guess {
    // EXTERNAL: TITANIUM 0x0042547C PartOwner_guess::Release_guess
    void Release_guess();
};

// Standard library: scalar deleting destructor of a stream entered through its ios_base part
// (0x0042547C; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x0042545D
// @early-stop: budget, structural ndiff=6
void* OwnerPart_guess::Delete_guess(unsigned char flags_guess)
{
    PartOwner_guess& owner_ref_guess = static_cast<PartOwner_guess&>(*this);
    owner_ref_guess.Release_guess();
    if ((flags_guess & 1) != 0) {
        free(&owner_ref_guess);
    }
    return &owner_ref_guess;
}

struct StringTreeNode_guess {
    unsigned char padding_guess[0x10];
    BasicStringCopy_guess text_guess;  // 0x10
};

struct LookupMap_guess {
    unsigned char padding_guess[0x44];
    Index_guess index_guess;           // 0x44
    TreeNode_guess* head_guess;        // 0x48
    BasicStringCopy_guess Extract_guess(int key_guess, BasicStringCopy_guess search_guess,
                                        BasicStringCopy_guess fallback_guess);
};

// basic_string construction from the char range [first, last): reserves the length, then appends one char
// at a time; on an exception the storage is freed and the exception passed on.
// FUNCTION: TITANIUM 0x00426A3C
void BasicStringCopy_guess::Construct_guess(const char* first_guess, const char* last_guess, RandomTag_guess tag_guess)
{
    reserve_guess(last_guess - first_guess);
    try {
        for (; first_guess != last_guess; ++first_guess) {
            append_guess(1, *first_guess);
        }
    } catch (...) {
        ((StringStorage_guess*)this)->Tidy_guess(true, 0);
        throw;
    }
}

// Map lookup: the address of the value stored under `key` (node +0x10), or 0 when absent; the mail
// window uses it.
// FUNCTION: TITANIUM 0x00426A9F
int Holder_guess::Check_guess(int key_guess)
{
    Holder_guess* owner_guess;
    int* found_guess = index_guess.Find_guess(owner_guess, key_guess);
    if (*found_guess == value_guess) {
        return 0;
    }
    return *found_guess + 0x10;
}

// EXTERNAL: TITANIUM 0x004260BD FUN_004260bd_guess
void __fastcall FUN_004260bd_guess(int self_guess);

// Standard library: deque destructor (pops every element, frees each block and the block map).
// FUNCTION: TITANIUM 0x00426DBE
void __fastcall DestroyEntryArray_guess(int self_guess)
{
    return FUN_004260bd_guess(self_guess);
}

// EXTERNAL: TITANIUM 0x00426998 use_facet_guess
void* __cdecl use_facet_guess(void* locale_guess);

struct LocaleDispatch_guess {
    // EXTERNAL: TITANIUM 0x00425C83 LocaleDispatch_guess::Apply_guess
    void Apply_guess(void* facet_guess);
    void Bind_guess(void* locale_guess);
};

// Standard library: looks the locale's facet up (use_facet) and binds it (0x00425C83).
// FUNCTION: TITANIUM 0x00426F48
void LocaleDispatch_guess::Bind_guess(void* locale_guess)
{
    void* facet_guess = use_facet_guess(locale_guess);
    Apply_guess(facet_guess);
}

// Standard library: map value pair constructor (unsigned key, string).
// FUNCTION: TITANIUM 0x004273A7
StringRecord_guess::StringRecord_guess(const unsigned int& first_guess, const BasicStringCopy_guess& text_guess)
    : first_guess(first_guess), text_guess(text_guess)
{
}

// Standard library: copy constructor of a map value pair (unsigned key, string).
// FUNCTION: TITANIUM 0x004273C4
StringRecord_guess::StringRecord_guess(const StringRecord_guess& source_guess)
    : first_guess(source_guess.first_guess), text_guess(source_guess.text_guess)
{
}

// Standard library: string constructor from the char range [first, last).
// FUNCTION: TITANIUM 0x004273FC
BasicStringCopy_guess::BasicStringCopy_guess(const char* first_guess, const char* last_guess)
{
    capacity_guess = 0xf;
    Eos_guess(0);
    Construct_guess(first_guess, last_guess, IterCat_guess(first_guess));
}

// Standard library: scalar deleting destructor of an exception (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x00427427
ExceptionDerived_guess* ExceptionDerived_guess::Delete_guess(unsigned char flags_guess)
{
    this->ExceptionDerived_guess::~ExceptionDerived_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Standard library: exception destructor: sets its vtable and runs 0x00403026 (frees the message,
// destroys the base).
// FUNCTION: TITANIUM 0x00427443
ExceptionDerived_guess::~ExceptionDerived_guess()
{
}

// Standard library: exception constructor from a message.
// FUNCTION: TITANIUM 0x00428350
ExceptionDerived_guess::ExceptionDerived_guess(const char* message_guess)
    : ExceptionBase_guess(message_guess)
{
}

struct CtorPart_guess {
    unsigned char storage_guess[0xc];  // 0x0
    // EXTERNAL: TITANIUM 0x00403115 CtorPart_guess::CtorPart_guess
    CtorPart_guess();
    // EXTERNAL: TITANIUM 0x00402A80 CtorPart_guess::~CtorPart_guess
    ~CtorPart_guess();
};

struct CtorText_guess {
    unsigned char storage_guess[0x1c];  // 0x0
    // EXTERNAL: TITANIUM 0x00402E5E CtorText_guess::CtorText_guess
    CtorText_guess();
    // EXTERNAL: TITANIUM 0x0040B488 CtorText_guess::~CtorText_guess
    ~CtorText_guess();
};

struct CtorOwner_guess {
    CtorPart_guess first_guess;   // 0x0
    CtorText_guess text_guess;    // 0xc
    CtorPart_guess second_guess;  // 0x28
    unsigned char flag_guess;     // 0x34
    CtorOwner_guess();
};

struct DualStringCtor_guess {
    int firstValue_guess;                     // 0x0
    int secondValue_guess;                    // 0x4
    int thirdValue_guess;                     // 0x8
    BasicStringCopy_guess firstText_guess;    // 0xc
    BasicStringCopy_guess secondText_guess;   // 0x28
    DualStringCtor_guess(const int first_guess, const int second_guess, const int third_guess,
                         BasicStringCopy_guess firstText_guess,
                         BasicStringCopy_guess secondText_guess);
};

// Mail header constructor: id (+0), the value tracked as the largest seen (+4) and status (+8), then the
// sender and subject strings, all copied from the arguments. The mail loaders build one per header.
// FUNCTION: TITANIUM 0x00427467
DualStringCtor_guess::DualStringCtor_guess(const int first_guess, const int second_guess,
                                           const int third_guess,
                                           BasicStringCopy_guess firstText_guess,
                                           BasicStringCopy_guess secondText_guess)
    : firstValue_guess(first_guess),
      secondValue_guess(second_guess),
      thirdValue_guess(third_guess),
      firstText_guess(firstText_guess),
      secondText_guess(secondText_guess)
{
}

// Default constructor: empty strings and middle part, flag set to 1.
// FUNCTION: TITANIUM 0x004274D5
CtorOwner_guess::CtorOwner_guess()
    : first_guess(), text_guess(), second_guess(), flag_guess(1)
{
}

struct AddressEntry_guess {
    char text_guess[0x1c];  // 0x0
};

struct MailAddressEntry_guess {
    std::string text_guess; // 0x0
};

struct MailAddressRecord_guess {
    std::string name_guess;                         // 0x0
    std::vector<MailAddressEntry_guess> addresses_guess; // 0x1C
    std::string note_guess;                         // 0x2C
    unsigned char flags_guess;                      // 0x48
    std::map<std::string, int> Diff_guess(const MailAddressRecord_guess& other_guess) const;
    int Compare_guess(const MailAddressRecord_guess& other_guess) const;
};

struct AddressRecord_guess {
    char name_guess[0x1c];            // 0x0
    unsigned int id_guess;            // 0x1c
    AddressEntry_guess* first_guess;  // 0x20
    AddressEntry_guess* last_guess;   // 0x24
    unsigned int capacity_guess;      // 0x28
    char note_guess[0x1c];            // 0x2c
    unsigned char flags_guess;        // 0x48
};

// EXTERNAL: TITANIUM 0x0042650A FUN_0042650a_guess
void* __cdecl FUN_0042650a_guess(void* stream_guess, const char* text_guess);

// EXTERNAL: TITANIUM 0x00426786 FUN_00426786_guess
void* __cdecl FUN_00426786_guess(void* stream_guess, const char* text_guess);

// EXTERNAL: TITANIUM 0x0042744E FUN_0042744e_guess
void* __cdecl FUN_0042744e_guess(void* stream_guess);

#define g_addressFormat_guess EQ_ARRAY(char, 0x0063FE10)

// Writes one address book entry: "Name: ", the addresses, "Flags: " (PRIVATE...) and "Note: ".
// FUNCTION: TITANIUM 0x00427516
void* __cdecl WriteAddressRecord_guess(void* stream_guess, AddressRecord_guess* record_guess)
{
    FUN_0042744e_guess(FUN_00426786_guess(
        FUN_0042650a_guess(stream_guess, "Name: "), record_guess->name_guess));
    FUN_0042650a_guess(stream_guess, "Addresses:");
    for (AddressEntry_guess* entry_guess = record_guess->first_guess;
         entry_guess != record_guess->last_guess; ++entry_guess) {
        FUN_00426786_guess(FUN_0042650a_guess(stream_guess, g_addressFormat_guess),
                           entry_guess->text_guess);
    }
    FUN_0042744e_guess(stream_guess);
    FUN_0042650a_guess(stream_guess, "Flags: ");
    if (record_guess->flags_guess == 0) {
        FUN_0042650a_guess(stream_guess, "PRIVATE");
    }
    FUN_0042744e_guess(stream_guess);
    FUN_0042744e_guess(FUN_0042744e_guess(FUN_00426786_guess(
        FUN_0042650a_guess(stream_guess, "Note: "), record_guess->note_guess)));
    return stream_guess;
}

// Frees the string member.
// FUNCTION: TITANIUM 0x00425ABC
void StringOwner_guess::Release_guess()
{
    this->value_guess.Tidy_guess(true, 0);
}

// Frees the string member at +0x10.
// FUNCTION: TITANIUM 0x00425DC8
void StringOwnerAt10_guess::Release_guess()
{
    this->value_guess.Tidy_guess(true, 0);
}

// Frees both string members, second first.
// FUNCTION: TITANIUM 0x00425EA1
void DualStringOwner_guess::Release_guess()
{
    this->second_guess.Tidy_guess(true, 0);
    this->first_guess.Tidy_guess(true, 0);
}

struct KeyedSlot_guess {
    unsigned char padding_guess[0x1c];
    int key_guess;                    // 0x1C
    unsigned char padding1_guess[0x34];
    int value54_guess;                // 0x54
    unsigned int count58_guess;       // 0x58
    // EXTERNAL: TITANIUM 0x00402D37 KeyedSlot_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    void Update_guess(int key_guess, int value_guess, unsigned int count_guess);
};

// For our key only: a nonzero count stores value and count, a zero count sends event 0 to the listeners.
// FUNCTION: TITANIUM 0x00425ED1
void KeyedSlot_guess::Update_guess(int key, int value, unsigned int count)
{
    if (key == key_guess) {
        if (count > 0) {
            value54_guess = value;
            count58_guess = count;
        } else {
            int* owned_guess = new int(0);
            Attach_guess(owned_guess);
            delete owned_guess;
        }
    }
}

// map::find: the lower bound of `key` (0x004256F0), or the head (end) when that node's key differs. The
// node is stored through `owner`, whose address is returned.
// FUNCTION: TITANIUM 0x00425F18
int* Index_guess::Find_guess(Holder_guess*& owner_guess, const int& key_guess)
{
    Tree_guess* tree_guess = (Tree_guess*)this;
    const unsigned int* keyPtr_guess = (const unsigned int*)&key_guess;
    TreeNode_guess* node_guess = tree_guess->Lbound_guess(*keyPtr_guess);
    TreeNode_guess* head_guess;
    TreeNode_guess** chosen_guess;
    if (node_guess == tree_guess->head_guess || *keyPtr_guess < node_guess->key_guess) {
        head_guess = tree_guess->head_guess;
        chosen_guess = &head_guess;
    } else {
        chosen_guess = &node_guess;
    }
    *(TreeNode_guess**)&owner_guess = *chosen_guess;
    return (int*)&owner_guess;
}

// Standard library: std::getline into a string, up to a newline.
// FUNCTION: TITANIUM 0x004283CE
int __cdecl GetLine_guess(Stream_guess* first_guess, Stream_guess* second_guess)
{
    return FUN_00403448_guess(first_guess, second_guess, first_guess->Widen_guess(10));
}

// Standard library: operator+ for two strings.
// FUNCTION: TITANIUM 0x004283F1
BasicStringCopy_guess __cdecl ConcatStrings_guess(const BasicStringCopy_guess& first_guess,
                                                  const BasicStringCopy_guess& second_guess)
{
    return *BasicStringCopy_guess(first_guess).AppendString_guess(second_guess, 0, 0xffffffff);
}

// Standard library: string::rfind of `count` chars at or before `position`; npos when absent.
// FUNCTION: TITANIUM 0x0042552C
// @early-stop: budget, structural ndiff=62
unsigned int PathString_guess::Rfind_guess(const char* text_guess, unsigned int position_guess,
                                           unsigned int count_guess) const
{
    if (count_guess > length_guess) {
        return 0xffffffff;
    }
    unsigned int last_guess = length_guess - count_guess;
    if (position_guess > last_guess) {
        position_guess = last_guess;
    }
    const char* source_guess = capacity_guess >= 0x10 ? *(const char**)buffer_guess : buffer_guess;
    do {
        if (memcmp(source_guess + position_guess, text_guess, count_guess) == 0) {
            return position_guess;
        }
    } while (position_guess-- != 0);
    return 0xffffffff;
}

// Standard library: string::substr of up to `count` chars from `position`.
// FUNCTION: TITANIUM 0x00427645
// @early-stop: budget, structural ndiff=59
PathString_guess PathString_guess::Substr_guess(unsigned int position_guess,
                                                 unsigned int count_guess) const
{
    PathString_guess result_guess;
    const char* source_guess = capacity_guess >= 0x10 ? *(const char**)buffer_guess : buffer_guess;
    unsigned int copied_guess = length_guess - position_guess;
    if (count_guess < copied_guess) {
        copied_guess = count_guess;
    }
    result_guess.prefix_guess = 0;
    result_guess.length_guess = copied_guess;
    result_guess.capacity_guess = copied_guess >= 0x10 ? copied_guess : 0xf;
    if (copied_guess >= 0x10) {
        *(char**)result_guess.buffer_guess = (char*)malloc(copied_guess + 1);
        memcpy(*(char**)result_guess.buffer_guess, source_guess + position_guess, copied_guess);
        (*(char**)result_guess.buffer_guess)[copied_guess] = 0;
    } else {
        memcpy(result_guess.buffer_guess, source_guess + position_guess, copied_guess);
        result_guess.buffer_guess[copied_guess] = 0;
    }
    return result_guess;
}

// Mail header assignment: message id, the +4 value and the status (+8), then sender and subject.
// FUNCTION: TITANIUM 0x00428780
DualStringRecord_guess* DualStringRecord_guess::CopyFrom_guess(const DualStringRecord_guess& source_guess)
{
    firstValue_guess = source_guess.firstValue_guess;
    secondValue_guess = source_guess.secondValue_guess;
    thirdValue_guess = source_guess.thirdValue_guess;
    firstText_guess.Assign_guess(source_guess.firstText_guess, 0, 0xffffffff);
    secondText_guess.Assign_guess(source_guess.secondText_guess, 0, 0xffffffff);
    return this;
}

// Checks a file name's extension against the extension policy (BeingIgnored_guess); no extension fails.
// FUNCTION: TITANIUM 0x004287BF
bool ExtensionCheck_guess::Check_guess(const char* path_guess)
{
    PathString_guess pathText_guess(path_guess);
    char dot_guess = '.';
    unsigned int dotPosition_guess = pathText_guess.Rfind_guess(&dot_guess, 0xffffffff, 1);
    if (dotPosition_guess == 0xffffffff) {
        return false;
    }
    PathString_guess extension_guess = pathText_guess.Substr_guess(dotPosition_guess + 1, 0xffffffff);
    ExtensionPolicy_guess* policy_guess = g_extensionPolicy_guess;
    if (policy_guess != 0) {
        if (policy_guess->Check_guess(extension_guess.CStr_guess()) != 0) {
            return true;
        }
    }
    return false;
}

#define g_lookupOpen_guess EQ_ARRAY(char, 0x00641588)
#define g_lookupClose_guess EQ_ARRAY(char, 0x00641584)

// Finds `search` wrapped in the two markers (0x00641588 before, 0x00641584 after) in key's text and returns
// what follows it up to the next opening marker; `fallback` when the key, the tag or the end is missing.
// FUNCTION: TITANIUM 0x0042886C
BasicStringCopy_guess LookupMap_guess::Extract_guess(int key_guess,
                                                      BasicStringCopy_guess search_guess,
                                                      BasicStringCopy_guess fallback_guess)
{
    Holder_guess* owner_guess;
    int* link_guess = index_guess.Find_guess(owner_guess, key_guess);
    TreeNode_guess* node_guess = (TreeNode_guess*)*link_guess;
    if (node_guess == head_guess) {
        return fallback_guess;
    }
    BasicStringCopy_guess value_guess(((StringTreeNode_guess*)node_guess)->text_guess);
    search_guess.Insert_guess(0, g_lookupOpen_guess);
    search_guess.Append_guess(g_lookupClose_guess);
    int start_guess = value_guess.FindString_guess(search_guess, 0);
    if (start_guess == -1) {
        return fallback_guess;
    }
    start_guess += search_guess.Length_guess();
    int end_guess = value_guess.FindText_guess(g_lookupOpen_guess, start_guess);
    if (end_guess == -1) {
        return fallback_guess;
    }
    return value_guess.Substr_guess(start_guess, end_guess - start_guess);
}

// Selects mailbox `index_guess` ("[selectmailbox n"); without a chat-service connection shows string 4529
// "Please wait until we reconnect you with the Universal Chat service...".
// FUNCTION: TITANIUM 0x00428962
void Collection_guess::SelectMailbox_guess(unsigned int index_guess)
{
    if (selected_guess != index_guess) {
        if (g_mailHost_guess->sender_guess != 0) {
            if (index_guess < mailboxes_guess.size()) {
                std::ostringstream stream_guess;
                stream_guess << '[' << "selectmailbox " << index_guess;
                g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());
            }
        } else {
            pEverQuest->dsp_chat(pStringTable->getString(0x11b1, 0), 0xd, 1);
        }
    }
}

// Selects the mailbox whose index is at +0x20 (0x00428962 sends "[selectmailbox n" when it changed);
// the mail window calls it.
// FUNCTION: TITANIUM 0x00428A65
void Collection_guess::Commit_guess()
{
    SelectMailbox_guess(value20_guess);
}

struct OutputStream_guess {
    unsigned char storage_guess[0x74];
    // EXTERNAL: TITANIUM 0x00427663 OutputStream_guess::OutputStream_guess
    OutputStream_guess(int mode_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00425A76 OutputStream_guess::~OutputStream_guess
    ~OutputStream_guess();
    // EXTERNAL: TITANIUM 0x004276D4 OutputStream_guess::Str_guess
    BasicStringCopy_guess Str_guess();
};

// EXTERNAL: TITANIUM 0x004263D1 FUN_004263d1_guess
void* __cdecl FUN_004263d1_guess(OutputStream_guess* stream_guess, int ch_guess,
                                 const char* text_guess, int key_guess);

struct BodySink_guess {
    // EXTERNAL: TITANIUM 0x00426C2D BodySink_guess::Commit_guess
    void Commit_guess();
};

struct BodyRecord_guess {
    int kind_guess;
    CollectionEntry_guess* entry_guess;
    int state_guess;
    BodyRecord_guess(CollectionEntry_guess* entry_value_guess, int state_value_guess)
    {
        state_guess = state_value_guess;
        kind_guess = 1;
        entry_guess = entry_value_guess;
    }
};

struct BodyRequestOwner_guess {
    unsigned char padding_guess[0x24];
    CollectionState_guess state_guess;  // 0x24
    Index_guess index_guess;            // 0x38
    int head_guess;                     // 0x3C
    // EXTERNAL: TITANIUM 0x00402D37 BodyRequestOwner_guess::Attach_guess
    void Attach_guess(BodyRecord_guess* entry_guess);
    void RequestBody_guess(int key_guess);
};

// Shows a message body from the cache or requests it ("[getbody id"); string 4529 when not connected.
// FUNCTION: TITANIUM 0x00428A6E
// @early-stop: budget, structural ndiff=49
void BodyRequestOwner_guess::RequestBody_guess(int key_guess)
{
    CollectionIterator_guess found_guess = FindMailHeaderById_guess(
        state_guess.Begin_guess(), state_guess.End_guess(), key_guess);
    if (!found_guess.Equals_guess(state_guess.End_guess())) {
        CollectionEntry_guess* entry_guess = found_guess.Deref_guess();
        std::string text_guess;
        Holder_guess* owner_guess;
        int state_guess = 2;
        if (*index_guess.Find_guess(owner_guess, key_guess) == head_guess) {
            state_guess = 0;
            if (g_mailHost_guess->sender_guess != 0) {
                state_guess = 1;
                std::ostringstream stream_guess;
                stream_guess << '[' << "getbody " << (unsigned int)key_guess;
                g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x11b1, 0), 0xd, 1);
            }
        }
        BodyRecord_guess* record_guess = new BodyRecord_guess(entry_guess, state_guess);
        Attach_guess(record_guess);
        delete record_guess;
    }
}

// Sends one status command (chosen by `status_guess`) for the listed message ids; string 4529 when not
// connected.
// FUNCTION: TITANIUM 0x00428C37
// @early-stop: budget, structural ndiff=35
void MailStatusTable_guess::SetStatuses_guess(const unsigned int* ids_guess, int count_guess,
                                             int status_guess)
{
    if (g_mailHost_guess->sender_guess == 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x11b1, 0), 0xd, 1);
        return;
    }

    std::ostringstream stream_guess;
    stream_guess << '[' << EQ_ARRAY(char, 0x006415CC);
    switch (status_guess) {
    case 0:
        stream_guess << EQ_ARRAY(char, 0x006415A8);
        break;
    case 1:
        stream_guess << EQ_ARRAY(char, 0x006415AC);
        break;
    case 2:
        stream_guess << EQ_ARRAY(char, 0x006415B4);
        break;
    case 3:
        stream_guess << EQ_ARRAY(char, 0x006415BC);
        break;
    case 4:
        stream_guess << EQ_ARRAY(char, 0x006415C4);
        break;
    }
    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        stream_guess << g_addressFormat_guess << ids_guess[index_guess];
    }
    g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());

    for (int index_guess = 0; index_guess < count_guess; ++index_guess) {
        CollectionIterator_guess found_guess = FindMailHeaderById_guess(
            state_guess.Begin_guess(), state_guess.End_guess(), ids_guess[index_guess]);
        if (!found_guess.Equals_guess(state_guess.End_guess())) {
            if (status_guess == 4) {
                state_guess.Erase_guess(found_guess);
            } else {
                found_guess.Deref_guess()->status_guess = status_guess;
            }
        }
    }

    pending_guess = 0;
    for (CollectionIterator_guess current_guess = state_guess.Begin_guess();
         current_guess.Less_guess(state_guess.End_guess()); ++current_guess.index_004_guess) {
        if (current_guess.Deref_guess()->status_guess == 0
            || current_guess.Deref_guess()->status_guess == 1) {
            pending_guess = 1;
            break;
        }
    }

    int* owned_guess = new int(0);
    Attach_guess(owned_guess);
    free(owned_guess);
}

// Reports the listed messages: sender, subject, date and body of each, cut to 0x2004 bytes and sent as
// OP_Report.
// FUNCTION: TITANIUM 0x00428E9A
// @early-stop: budget, structural ndiff=117
void MailStatusTable_guess::ReportMessages_guess(int count_guess, const unsigned int* ids_guess)
{
    std::ostringstream stream_guess;
    CollectionState_guess* state_guess_ptr = &state_guess;
    int index_guess = 0;
    while (index_guess < count_guess) {
        CollectionIterator_guess first_guess(state_guess_ptr, state_guess.first_guess);
        CollectionIterator_guess last_guess(state_guess_ptr,
                                             state_guess.first_guess + state_guess.count_guess);
        CollectionIterator_guess found_guess =
            FindMailHeaderById_guess(first_guess, last_guess, ids_guess[index_guess]);
        if (found_guess.Equals_guess(last_guess)) {
            return;
        }

        CollectionEntry_guess* entry_guess = found_guess.Deref_guess();
        if (index_guess == 0) {
            MessageInfoOffset_guess* infoOffset_guess =
                (MessageInfoOffset_guess*)g_messageInfoRoot_guess->messageInfo_guess;
            unsigned int infoAddress_guess = (unsigned int)g_messageInfoRoot_guess
                + infoOffset_guess->vbaseOffset_0004_guess + 0x44;
            const char* infoText_guess = (const char*)infoAddress_guess;
            stream_guess << entry_guess->sender_guess << EQ_ARRAY(char, 0x00641624)
                         << infoText_guess << EQ_ARRAY(char, 0x00641624);
        }

        stream_guess << EQ_ARRAY(char, 0x0064161C) << ids_guess[index_guess]
                     << EQ_ARRAY(char, 0x00641588);
        stream_guess << EQ_ARRAY(char, 0x00641614) << entry_guess->sender_guess
                     << EQ_ARRAY(char, 0x00641588);
        stream_guess << EQ_ARRAY(char, 0x00641608) << entry_guess->subject_guess
                     << EQ_ARRAY(char, 0x00641588);

        time_t date_guess = entry_guess->value004_guess;
        stream_guess << EQ_ARRAY(char, 0x006415F8) << ctime(&date_guess)
                     << EQ_ARRAY(char, 0x00641600);

        int messageText_guess = ((Holder_guess*)this)->Check_guess(ids_guess[index_guess]);
        if (messageText_guess == 0) {
            stream_guess << EQ_ARRAY(char, 0x006415E0);
        } else {
            const std::string* text_guess = (const std::string*)messageText_guess;
            stream_guess << *text_guess;
        }
        stream_guess << EQ_ARRAY(char, 0x00641588);
        ++index_guess;
    }

    std::string text_guess = stream_guess.str().substr(0, 0x2004);
    EQSendMessage(EQ_ARRAY(unsigned char, 0x00905CA0), OP_Report,
                       text_guess.c_str(), text_guess.length(), 1);
}

struct StringTreeNodeFull_guess {
    StringTreeNodeFull_guess* left_guess;    // 0x0
    StringTreeNodeFull_guess* parent_guess;  // 0x4
    StringTreeNodeFull_guess* right_guess;   // 0x8
    StringRecord_guess value_guess;          // 0xC
    char color_guess;                        // 0x2C
    char isNil_guess;                        // 0x2D
    StringTreeNodeFull_guess(StringTreeNodeFull_guess* left_guess, StringTreeNodeFull_guess* parent_guess,
                             StringTreeNodeFull_guess* right_guess, const StringRecord_guess& value_guess,
                             char color_guess);
};

struct StringTree_guess {
    StringTreeNodeFull_guess* BuyNode_guess(StringTreeNodeFull_guess* left_guess,
                                            StringTreeNodeFull_guess* parent_guess,
                                            StringTreeNodeFull_guess* right_guess,
                                            const StringRecord_guess& value_guess, char color_guess);
};

// Standard library: map node constructor (links, value, color; not the nil node).
// FUNCTION: TITANIUM 0x00428368
StringTreeNodeFull_guess::StringTreeNodeFull_guess(StringTreeNodeFull_guess* left_guess,
                                                   StringTreeNodeFull_guess* parent_guess,
                                                   StringTreeNodeFull_guess* right_guess,
                                                   const StringRecord_guess& value_guess, char color_guess)
    : left_guess(left_guess), parent_guess(parent_guess), right_guess(right_guess),
      value_guess(value_guess), color_guess(color_guess), isNil_guess(0)
{
}

// Allocates a 0x30-byte tree node and constructs it from its links, colour and string record value; the
// memory is freed again if the constructor throws.
// FUNCTION: TITANIUM 0x0042A01E
StringTreeNodeFull_guess* StringTree_guess::BuyNode_guess(StringTreeNodeFull_guess* left_guess,
                                                          StringTreeNodeFull_guess* parent_guess,
                                                          StringTreeNodeFull_guess* right_guess,
                                                          const StringRecord_guess& value_guess,
                                                          char color_guess)
{
    StringTreeNodeFull_guess* node_guess = (StringTreeNodeFull_guess*)::operator new(0x30);
    try {
        new (node_guess) StringTreeNodeFull_guess(left_guess, parent_guess, right_guess, value_guess,
                                                  color_guess);
    } catch (...) {
        ::operator delete(node_guess);
        throw;
    }
    return node_guess;
}

// Standard library: operator+ for a string and a C string.
// FUNCTION: TITANIUM 0x0042A3BE
BasicStringCopy_guess __cdecl ConcatStringChars_guess(const BasicStringCopy_guess& source_guess,
                                                  const char* text_guess)
{
    return BasicStringCopy_guess(source_guess).Append_guess(text_guess);
}

struct Entry_guess {
    unsigned char storage_guess[0x1c];
};

struct EntryRange_guess {
    unsigned char padding_guess[0x20];
    Entry_guess* begin_guess;  // 0x20
    Entry_guess* end_guess;    // 0x24
    void ForEach_guess();
};

// Qualifies a chat channel name: names with too few periods get the "SOE.EQ.<server>." prefix (server name at
// 0x95D3D4).
// FUNCTION: TITANIUM 0x0042A439
// @early-stop: budget, structural ndiff=45
void __cdecl QualifyChannelName_guess(void* entry_guess)
{
    BasicStringCopy_guess* text_guess = (BasicStringCopy_guess*)entry_guess;
    BasicStringCopy_guess soe_guess(EQ_ARRAY(char, 0x0064167C));
    BasicStringCopy_guess soeeq_guess("SOE.EQ.");
    BasicStringCopy_guess prefix_guess = ConcatStringChars_guess(
        ConcatStringChars_guess(soeeq_guess, EQ_ARRAY(char, 0x0095D3D4)),
        EQ_ARRAY(char, 0x0063FDE0));

    const char period_guess = '.';
    char* first_guess = text_guess->Begin_guess();
    int periods_guess = CountChar_guess(first_guess, text_guess->End_guess(),
                                            &period_guess);
    if (periods_guess == 0) {
        text_guess->Assign_guess(ConcatStrings_guess(prefix_guess, *text_guess), 0,
                                 0xffffffff);
    } else if (periods_guess == 1) {
        text_guess->Assign_guess(ConcatStrings_guess(soeeq_guess, *text_guess), 0,
                                 0xffffffff);
    } else if (periods_guess == 2) {
        text_guess->Assign_guess(ConcatStrings_guess(soe_guess, *text_guess), 0,
                                 0xffffffff);
    }

    const char space_guess = ' ';
    const char underscore_guess = '_';
    ReplaceChar_guess(text_guess->Begin_guess(), text_guess->End_guess(), &space_guess,
                       &underscore_guess);
}

// Qualifies every channel name in the parsed range (0x0042A439).
// FUNCTION: TITANIUM 0x0042A5C2
void EntryRange_guess::ForEach_guess()
{
    Entry_guess* entry_guess = begin_guess;
    while (entry_guess != end_guess) {
        Entry_guess* current_guess = entry_guess;
        ++entry_guess;
        QualifyChannelName_guess(current_guess);
    }
}

struct MailCommands_guess {
    void SetForwarding_guess(bool enabled_guess);
    std::string Quote_guess(const std::string& text_guess);
};

struct MailboxText_guess {
    unsigned char padding_guess[0x2c];
    std::string text_guess;
    void Normalize_guess();
};

// "[setmailforwarding 0|1"; silently dropped when not connected.
// FUNCTION: TITANIUM 0x0042846B
void MailCommands_guess::SetForwarding_guess(bool enabled_guess)
{
    if (g_mailHost_guess->sender_guess != 0) {
        std::ostringstream stream_guess;
        stream_guess << '[' << "setmailforwarding " << (enabled_guess ? 1 : 0);
        g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());
    }
}

// Trims trailing spaces and newlines from the text and collapses runs of blank lines.
// FUNCTION: TITANIUM 0x004285E1
void MailboxText_guess::Normalize_guess()
{
    std::ostringstream stream_guess;
    bool previousNewline_guess = false;
    std::string::iterator first_guess = text_guess.begin();
    std::string::iterator last_guess = text_guess.end();
    while (first_guess < last_guess) {
        --last_guess;
        if (*last_guess == ' ' || *last_guess == '\n') {
            continue;
        }
        ++last_guess;
        break;
    }
    for (; first_guess != last_guess; ++first_guess) {
        if (*first_guess != '\n') {
            previousNewline_guess = false;
        } else {
            if (previousNewline_guess) {
                stream_guess << ' ';
            }
            previousNewline_guess = true;
        }
        stream_guess << *first_guess;
    }
    text_guess = stream_guess.str();
}

// Wraps `text_guess` in quotes when it contains a space.
// FUNCTION: TITANIUM 0x004286D4
std::string MailCommands_guess::Quote_guess(const std::string& text_guess)
{
    if (text_guess.find(' ') != std::string::npos) {
        std::ostringstream stream_guess;
        stream_guess << '"' << text_guess << '"';
        return stream_guess.str();
    }
    return text_guess;
}

struct MailtoLookup_guess {
    unsigned char padding_guess[0x2c];
    ListNode_guess* head_guess;                      // 0x2C, list of record pointers
    MailAddressRecord_guess* Find_guess(const std::string& address_guess);
};

// Address book entry for `address_guess`, trimmed of surrounding spaces; 0 when unknown.
// FUNCTION: TITANIUM 0x00428534
// @early-stop: budget, structural ndiff=9
MailAddressRecord_guess* MailtoLookup_guess::Find_guess(const std::string& address_guess)
{
    char space_guess[4];
    space_guess[0] = ' ';
    unsigned int first_guess = address_guess.find_first_of(space_guess, 0, 1);
    space_guess[0] = ' ';
    unsigned int last_guess = address_guess.find_last_of(space_guess, 0xffffffff, 1);
    unsigned int count_guess = last_guess == 0xffffffff
        ? 0xffffffff : last_guess - first_guess + 1;
    std::string key_guess = address_guess.substr(first_guess, count_guess);
    ListNode_guess* foundNode_guess;
    FindStringInList_guess(&foundNode_guess, head_guess->next_guess, head_guess,
                       StringRef_guess(key_guess));
    if (foundNode_guess == head_guess) {
        return 0;
    }
    return (MailAddressRecord_guess*)foundNode_guess->value_guess;
}

struct MailtoLink_guess {
    unsigned char padding_guess[0x60];
    MailtoLookup_guess lookup_guess;                 // 0x60
    std::string Quote_guess(const std::string& address_guess);
    std::string Format_guess(const std::string& link_guess);
    void Send_guess(const std::string& address_guess, const std::string& subject_guess,
                    const std::string& message_guess, int flags_guess);
};

// Expands a comma-separated recipient list: address book names become their addresses, each quoted.
// FUNCTION: TITANIUM 0x0042A5DF
// @early-stop: budget, structural ndiff=117
std::string MailtoLink_guess::Quote_guess(const std::string& address_guess)
{
    std::ostringstream stream_guess;
    bool hasOutput_guess = false;
    const char* first_guess = address_guess.c_str();
    const char* last_guess = first_guess + address_guess.size();
    while (first_guess < last_guess) {
        char comma_guess = ',';
        char* commaPosition_guess = FindChar_guess((char*)first_guess, (char*)last_guess,
                                                        &comma_guess);
        while (first_guess < commaPosition_guess && *first_guess == ' ') {
            ++first_guess;
        }
        bool negative_guess = false;
        if (*first_guess == '-') {
            negative_guess = true;
            ++first_guess;
        }
        std::string::const_iterator tokenFirstIt_guess(first_guess);
        std::string::const_iterator tokenLastIt_guess(commaPosition_guess);
        std::string token_guess(tokenFirstIt_guess, tokenLastIt_guess);
        const char lessThan_guess = '<';
        if (token_guess.find(&lessThan_guess, 0, 1) == std::string::npos) {
            MailAddressRecord_guess* record_guess = lookup_guess.Find_guess(token_guess);
            if (record_guess == 0 || record_guess->addresses_guess.size() == 0) {
                QualifyChannelName_guess(&token_guess);
            } else {
                std::ostringstream expanded_guess;
                if (record_guess->flags_guess != 0) {
                    expanded_guess << record_guess->name_guess << EQ_ARRAY(char, 0x00641688);
                }
                bool firstAddress_guess = true;
                for (std::vector<MailAddressEntry_guess>::iterator addressIt_guess =
                         record_guess->addresses_guess.begin();
                     addressIt_guess != record_guess->addresses_guess.end(); ++addressIt_guess) {
                    if (!firstAddress_guess) {
                        expanded_guess << (record_guess->flags_guess != 0
                            ? g_addressFormat_guess : EQ_ARRAY(char, 0x0063FDE4));
                    }
                    if (record_guess->flags_guess == 0 && negative_guess) {
                        expanded_guess << '-';
                    }
                    expanded_guess << addressIt_guess->text_guess;
                    firstAddress_guess = false;
                }
                if (record_guess->flags_guess != 0) {
                    expanded_guess << EQ_ARRAY(char, 0x00641684);
                }
                token_guess = expanded_guess.str();
            }
        }
        if (negative_guess) {
            token_guess.insert(token_guess.begin(), '-');
        }
        if (hasOutput_guess) {
            token_guess.insert(token_guess.begin(), ' ');
        }
        if (stream_guess.str().find(token_guess, 0) == std::string::npos) {
            if (hasOutput_guess) {
                stream_guess << EQ_ARRAY(char, 0x0063F9EC);
            }
            stream_guess << token_guess;
            hasOutput_guess = true;
        }
        first_guess = commaPosition_guess + 1;
    }
    return stream_guess.str();
}

// Rewrites a "[mailto <address> ..." link with the expanded, quoted recipients; other links pass through.
// FUNCTION: TITANIUM 0x0042A8C8
std::string MailtoLink_guess::Format_guess(const std::string& link_guess)
{
    if (link_guess.substr(1, 6).compare("mailto") != 0) {
        return link_guess;
    }
    const char* first_guess;
    const char* last_guess;
    if (!GetNextToken_guess(link_guess.c_str() + 7, &first_guess, &last_guess)) {
        return link_guess;
    }
    std::string address_guess = Quote_guess(std::string(first_guess, last_guess));
    std::ostringstream stream_guess;
    stream_guess << "[mailto \"";
    stream_guess << address_guess;
    stream_guess << "\" ";
    stream_guess << last_guess + 1;
    return stream_guess.str();
}

// Sends a mail command with the expanded recipients, the quoted subject and the body.
// FUNCTION: TITANIUM 0x0042B166
void MailtoLink_guess::Send_guess(const std::string& address_guess,
                                  const std::string& subject_guess,
                                  const std::string& message_guess, int flags_guess)
{
    std::string quotedAddress_guess = Quote_guess(address_guess);
    if (g_mailHost_guess->sender_guess != 0) {
        std::ostringstream stream_guess;
        stream_guess << '[' << EQ_ARRAY(char, 0x006417E0);
        stream_guess << EQ_ARRAY(char, 0x006417DC) << quotedAddress_guess
                     << EQ_ARRAY(char, 0x0064168C);
        stream_guess << ((MailCommands_guess*)this)->Quote_guess(subject_guess)
                     << g_addressFormat_guess;
        stream_guess << message_guess;
        g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());
    }
}

// Allocates a tree node and constructs it from its links, unsigned int key and colour; the memory is freed
// again if the constructor throws.
// FUNCTION: TITANIUM 0x0042A353
TreeNode_guess* Tree_guess::BuyNode_guess(TreeNode_guess* head_guess, TreeNode_guess* parent_guess,
                                          TreeNode_guess* head2_guess, const unsigned int& key_guess,
                                          unsigned char color_guess)
{
    TreeNode_guess* node_guess = (TreeNode_guess*)operator new(sizeof(TreeNode_guess));
    try {
        new (node_guess) TreeNode_guess(head_guess, parent_guess, head2_guess, key_guess, color_guess);
    } catch (...) {
        operator delete(node_guess);
        throw;
    }
    return node_guess;
}

// Standard library: map/set subtree copy (_Copy); on an exception the copied part is erased.
// FUNCTION: TITANIUM 0x0042AD6F
TreeNode_guess* Tree_guess::Copy_guess(TreeNode_guess* source_guess, TreeNode_guess* parent_guess)
{
    TreeNode_guess* result_guess = head_guess;
    if (source_guess->isNil_guess == 0) {
        TreeNode_guess* node_guess = BuyNode_guess(head_guess, parent_guess, head_guess,
                                                   source_guess->key_guess, source_guess->color_guess);
        if (result_guess->isNil_guess != 0) {
            result_guess = node_guess;
        }
        try {
            node_guess->left_guess = Copy_guess(source_guess->left_guess, node_guess);
            node_guess->right_guess = Copy_guess(source_guess->right_guess, node_guess);
        } catch (...) {
            EraseSubtree_guess(result_guess);
            throw;
        }
    }
    return result_guess;
}

struct EntryArray_guess {
    unsigned char padding_guess[0xc];  // 0x0
    int begin_00c;                     // 0xC
    int count_010;                     // 0x10
    // EXTERNAL: TITANIUM 0x004260BD EntryArray_guess::Destroy_guess
    void Destroy_guess();
};

struct EntryIter_guess {
    EntryArray_guess* array_guess;     // 0x0
    int index_guess;                   // 0x4
    EntryIter_guess(EntryArray_guess* array_in, int index_in)
        : array_guess(array_in), index_guess(index_in) {}
    // EXTERNAL: TITANIUM 0x00425170 EntryIter_guess::Deref_guess
    DualStringOwner_guess*& Deref_guess() const;
    // EXTERNAL: TITANIUM 0x00425196 EntryIter_guess::NotEqual_guess
    bool NotEqual_guess(const EntryIter_guess& other_guess) const;
};

struct EntryHolder_guess {
    unsigned char padding_guess[0xc];
    // EXTERNAL: TITANIUM 0x0042AABD EntryHolder_guess::Clear_guess
    void Clear_guess();
};

struct EntryOwner_guess {
    unsigned char padding_guess[0x24];  // 0x0
    EntryArray_guess array_024;          // 0x24
    EntryHolder_guess holder_038;       // 0x38
    EntryHolder_guess holder_044;       // 0x44
    unsigned char flag_050;             // 0x50
    int value_054;                      // 0x54
    int value_058;                      // 0x58
    int value_05c;                      // 0x5c
    void Reset_guess();
};

// Clears the mail state: the counters at +0x50..+0x5C, every header entry (freed), the header deque
// at +0x24 (0x004260BD) and the two maps at +0x38 and +0x44.
// FUNCTION: TITANIUM 0x0042AF8E
// @early-stop: budget, structural ndiff=38
void EntryOwner_guess::Reset_guess()
{
    value_054 = 0;
    value_058 = 0;
    value_05c = 0;
    flag_050 = 0;
    EntryArray_guess* array_guess = &array_024;
    EntryIter_guess it_guess(array_guess, array_guess->begin_00c);
    EntryIter_guess end_guess(array_guess, array_guess->begin_00c + array_guess->count_010);
    while (it_guess.NotEqual_guess(end_guess)) {
        DualStringOwner_guess* entry_guess = it_guess.Deref_guess();
        if (entry_guess != 0) {
            entry_guess->Release_guess();
            delete entry_guess;
        }
        ++it_guess.index_guess;
        end_guess.index_guess = array_guess->begin_00c + array_guess->count_010;
    }
    array_024.Destroy_guess();
    holder_038.Clear_guess();
    holder_044.Clear_guess();
}

struct Slot_guess {
    unsigned char padding_guess[0x1c];
    int field_guess;                  // 0x1C
    // EXTERNAL: TITANIUM 0x00402D37 Slot_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    // EXTERNAL: TITANIUM 0x0042B34A Slot_guess::Reset_guess
    void Reset_guess();
    void Set_guess(int input_guess);
};

// Stores the value at +0x1C, tells the listeners (0x00402D37) with event 2, then asks the mail server for
// the message headers again (0x0042B34A sends "[getheaders", or prints eqstr 0x11B1 when not connected).
// FUNCTION: TITANIUM 0x0042B428
void Slot_guess::Set_guess(int input_guess)
{
    field_guess = input_guess;
    int* owned_guess = new int(2);
    Attach_guess(owned_guess);
    delete owned_guess;
    Reset_guess();
}

// Standard library: stream destructor: the stream part at +0x64 (0x0042AB50), then its ios_base
// (0x00401C6C).
// FUNCTION: TITANIUM 0x0042B029
// @early-stop: budget, structural ndiff=6
DeleteObject64_guess::~DeleteObject64_guess()
{
}

// Standard library: scalar deleting destructor of a stream entered through a secondary base (flag 1
// frees the memory).
// FUNCTION: TITANIUM 0x0042B7DF
DeleteObject64_guess* DeleteSecondary64_guess::Delete_guess(unsigned char flags_guess)
{
    DeleteObject64_guess* object_guess = reinterpret_cast<DeleteObject64_guess*>(this - 0x19);
    object_guess->DeleteObject64_guess::~DeleteObject64_guess();
    if ((flags_guess & 1) != 0) {
        ::operator delete(object_guess);
    }
    return object_guess;
}

// Standard library: copies a tree into an empty one (the tree copy constructor 0x0042C0C6): the
// nodes, the size, and resets the leftmost and rightmost links.
// FUNCTION: TITANIUM 0x0042B829
void Tree_guess::Assign_guess(const Tree_guess& source_guess)
{
    TreeNode_guess* head = head_guess;
    head->parent_guess = Copy_guess(source_guess.head_guess->parent_guess, head);
    size_guess = source_guess.size_guess;
    if (head_guess->parent_guess->isNil_guess == 0) {
        TreeNode_guess* node_guess = head_guess->parent_guess;
        while (node_guess->left_guess->isNil_guess == 0) {
            node_guess = node_guess->left_guess;
        }
        head_guess->left_guess = node_guess;
        node_guess = head_guess->parent_guess;
        while (node_guess->right_guess->isNil_guess == 0) {
            node_guess = node_guess->right_guess;
        }
        head_guess->right_guess = node_guess;
    } else {
        head_guess->left_guess = head_guess;
        head_guess->right_guess = head_guess;
    }
}

struct Builder_guess {
    // EXTERNAL: TITANIUM 0x0044A537 Builder_guess::WavePlay_guess
    void WavePlay_guess(int value_guess, void* params_guess);
};

#define g_queueBuilder_guess EQ_GLOBAL(Builder_guess*, 0x00851390)

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess,
                              const char* p0_guess, const char* p1_guess,
                              const char* p2_guess, const char* p3_guess,
                              const char* p4_guess, const char* p5_guess,
                              const char* p6_guess, const char* p7_guess,
                              const char* p8_guess);

// EXTERNAL: TITANIUM 0x004657FB FilterBadWords_guess
void __cdecl FilterBadWords_guess(const char* source_guess, const char* destination_guess);

struct Loader_guess : ExtensionCheck_guess {
    unsigned char padding0_guess[0x1c];
    int key1c_guess;                    // 0x1C
    unsigned char padding1_guess[4];    // 0x20
    CollectionState_guess state24_guess; // 0x24
    unsigned char padding1b_guess[0x18]; // 0x38
    unsigned char flag50_guess;         // 0x50
    unsigned char padding2_guess[0x3];
    int slot54_guess;                   // 0x54
    int slot58_guess;                   // 0x58
    unsigned int max5c_guess;           // 0x5C
    unsigned char padding3_guess[0x38];
    int value98_guess;                  // 0x98
    unsigned char flag9c_guess;         // 0x9C
    unsigned char flag9d_guess;         // 0x9D
    // EXTERNAL: TITANIUM 0x00402D37 Loader_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    void Store_guess(DualStringCtor_guess* item_guess);
    void NotifyNewMail_guess(int key_guess, int first_guess, unsigned int count_guess, int mode_guess,
                    const char* path_guess, const char* name_guess);
    void AddHeader_guess(int key_guess, int slot_guess, int index_guess, int first_guess,
                        unsigned int count_guess, int mode_guess, const char* path_guess,
                        const char* name_guess);
};

// Adds `item` keyed by its first value, or copies it over the entry with that key and frees it.
// FUNCTION: TITANIUM 0x0042B2C8
// @early-stop: budget, structural ndiff=13
void Loader_guess::Store_guess(DualStringCtor_guess* item_guess)
{
    DualStringCtor_guess* memory_guess = item_guess;
    int key_guess = memory_guess->firstValue_guess;
    CollectionState_guess* state_guess = &state24_guess;
    CollectionIterator_guess found_guess;
    found_guess = FindMailHeaderById_guess(
        CollectionIterator_guess(state_guess, state_guess->first_guess),
        CollectionIterator_guess(state_guess, state_guess->first_guess + state_guess->count_guess),
        key_guess);
    if (found_guess.Equals_guess(CollectionIterator_guess(state_guess, state_guess->first_guess + state_guess->count_guess))) {
        state_guess->Insert_guess(item_guess);
    } else {
        ((DualStringRecord_guess*)found_guess.Deref_guess())->CopyFrom_guess(*(DualStringRecord_guess*)memory_guess);
        ((DualStringOwner_guess*)memory_guess)->Release_guess();
        free(memory_guess);
    }
}

// New header for the current mailbox (`key_guess` matches): filters bad words in the subject and stores it
// unless the sender is ignored; tracks the highest message id.
// FUNCTION: TITANIUM 0x0042B466
void Loader_guess::AddHeader_guess(int key_guess, int slot_guess, int index_guess, int first_guess,
                                  unsigned int count_guess, int mode_guess, const char* path_guess,
                                  const char* name_guess)
{
    if (key_guess == key1c_guess) {
        if (!Check_guess(path_guess)) {
            FilterBadWords_guess(name_guess, name_guess);
            Store_guess(new DualStringCtor_guess(first_guess, count_guess, mode_guess, path_guess, name_guess));
            if (mode_guess == 0 || mode_guess == 1) {
                flag50_guess = 1;
            }
            if (max5c_guess < count_guess) {
                max5c_guess = count_guess;
            }
        }
        if (slot54_guess == slot_guess && slot58_guess == index_guess + 1) {
            int* owned_guess = new int();
            Attach_guess(owned_guess);
            delete owned_guess;
        }
    }
}

// New-mail notice: another mailbox shows string 4533 "You received a new message in your primary mailbox.";
// the current one shows 4547 "New mail from %1: "%2"." and plays the you've-got-mail sound.
// FUNCTION: TITANIUM 0x0042B557
void Loader_guess::NotifyNewMail_guess(int key_guess, int first_guess, unsigned int count_guess, int mode_guess,
                              const char* path_guess, const char* name_guess)
{
    if (key_guess != key1c_guess) {
        if (flag9c_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x11b5, 0), 0xf, 1);
        }
    } else {
        if (flag9c_guess != 0) {
            char text_guess[512];
            FormatText_guess(text_guess, 0x11c3, path_guess, name_guess, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(text_guess, 0xa, 1);
        }
        if (flag9d_guess != 0 && value98_guess != -1) {
            g_queueBuilder_guess->WavePlay_guess(value98_guess, 0);
        }
        if (!Check_guess(path_guess)) {
            FilterBadWords_guess(name_guess, name_guess);
            Store_guess(new DualStringCtor_guess(first_guess, count_guess, mode_guess, path_guess, name_guess));
            if (mode_guess == 0 || mode_guess == 1) {
                flag50_guess = 1;
            }
            if (max5c_guess < count_guess) {
                max5c_guess = count_guess;
            }
        }
        int* owned_guess = new int();
        Attach_guess(owned_guess);
        delete owned_guess;
    }
}

// Standard library: set<unsigned>::insert; returns the position and whether a node was added.
// FUNCTION: TITANIUM 0x0042B887
TreeInsertResult_guess Tree_guess::Insert_guess(const unsigned int& key_guess)
{
    TreeNode_guess* tryNode_guess = head_guess->parent_guess;
    TreeNode_guess* where_guess = head_guess;
    bool addLeft_guess = true;
    while (tryNode_guess->isNil_guess == 0) {
        where_guess = tryNode_guess;
        addLeft_guess = key_guess < tryNode_guess->key_guess;
        tryNode_guess = addLeft_guess ? tryNode_guess->left_guess : tryNode_guess->right_guess;
    }
    TreeIter_guess position_guess(where_guess);
    if (addLeft_guess) {
        if (position_guess.node_guess == head_guess->left_guess) {
            position_guess = InsertNode_guess(position_guess, true, where_guess, key_guess);
            return TreeInsertResult_guess(position_guess, true);
        }
        --position_guess;
    }
    if (position_guess.node_guess->key_guess < key_guess) {
        position_guess = InsertNode_guess(position_guess, addLeft_guess, where_guess, key_guess);
        return TreeInsertResult_guess(position_guess, true);
    }
    return TreeInsertResult_guess(position_guess, false);
}

// Address book entry constructor: name, address list (+0x1C) and notes (+0x2C) copied from the arguments,
// the flag at +0x48 set and +0x49 (entries the save skips) cleared. Every address is then qualified into a
// full mail address (0x0042A5C2) and the notes are normalized (0x004285E1).
// FUNCTION: TITANIUM 0x0042BA5E
PurgeObject_guess::PurgeObject_guess(std::string firstArg_guess,
                                    std::vector<std::string> middleArg_guess,
                                    std::string secondArg_guess, bool flagArg_guess)
    : first_guess(firstArg_guess), middle_guess(middleArg_guess), second_guess(secondArg_guess)
{
    flag_guess = flagArg_guess;
    flag2_guess = 0;
    ((EntryRange_guess*)this)->ForEach_guess();
    Refresh_guess();
}

// Address book entry copy constructor: copies the name, address list, notes and both flags, then qualifies
// the addresses (0x0042A5C2) and normalizes the notes (0x004285E1) again.
// FUNCTION: TITANIUM 0x0042BAEC
PurgeObject_guess::PurgeObject_guess(const PurgeObject_guess& source_guess)
{
    first_guess.assign(source_guess.first_guess, 0, std::string::npos);
    middle_guess = source_guess.middle_guess;
    second_guess.assign(source_guess.second_guess, 0, std::string::npos);
    flag_guess = source_guess.flag_guess;
    flag2_guess = source_guess.flag2_guess;
    ((EntryRange_guess*)this)->ForEach_guess();
    Refresh_guess();
}

// Assignment: both strings, the middle part and the flag at +0x48.
// FUNCTION: TITANIUM 0x0042BB77
PurgeObject_guess* PurgeObject_guess::CopyFrom_guess(const PurgeObject_guess& source_guess)
{
    first_guess.assign(source_guess.first_guess, 0, std::string::npos);
    middle_guess = source_guess.middle_guess;
    second_guess.assign(source_guess.second_guess, 0, std::string::npos);
    flag_guess = source_guess.flag_guess;
    return this;
}

// Hinted insert (_Tree::insert(where, value)): inserts next to the hint when the key falls just before or
// just after it, else does a plain insert.
// FUNCTION: TITANIUM 0x0042BBB2
// @early-stop: budget, structural ndiff=132
TreeIter_guess Tree_guess::InsertAt_guess(TreeNode_guess* hint_guess,
                                          const StringRecord_guess& value_guess)
{
    TreeIter_guess result_guess;
    if (size_guess == 0) {
        InsertNode_guess(result_guess, true, head_guess, value_guess.first_guess);
        return result_guess;
    }

    if (hint_guess == head_guess->left_guess) {
        if (value_guess.first_guess < hint_guess->key_guess) {
            InsertNode_guess(result_guess, true, hint_guess, value_guess.first_guess);
            return result_guess;
        }
        result_guess = Insert_guess(value_guess.first_guess).first_guess;
        return result_guess;
    }

    if (hint_guess == head_guess) {
        TreeNode_guess* rightmost_guess = head_guess->right_guess;
        if (rightmost_guess->key_guess < value_guess.first_guess) {
            InsertNode_guess(result_guess, false, rightmost_guess, value_guess.first_guess);
            return result_guess;
        }
        result_guess = Insert_guess(value_guess.first_guess).first_guess;
        return result_guess;
    }

    if (value_guess.first_guess < hint_guess->key_guess) {
        TreeIter_guess previous_guess(hint_guess);
        --previous_guess;
        if (previous_guess.node_guess->key_guess < value_guess.first_guess) {
            if (previous_guess.node_guess->right_guess->isNil_guess != 0) {
                InsertNode_guess(result_guess, false, previous_guess.node_guess,
                                 value_guess.first_guess);
            } else {
                InsertNode_guess(result_guess, true, hint_guess, value_guess.first_guess);
            }
            return result_guess;
        }
        result_guess = Insert_guess(value_guess.first_guess).first_guess;
        return result_guess;
    }

    if (hint_guess->key_guess < value_guess.first_guess) {
        TreeIter_guess next_guess(hint_guess);
        ++next_guess;
        if (next_guess.node_guess == head_guess ||
            value_guess.first_guess < next_guess.node_guess->key_guess) {
            if (hint_guess->right_guess->isNil_guess != 0) {
                InsertNode_guess(result_guess, false, hint_guess, value_guess.first_guess);
            } else {
                InsertNode_guess(result_guess, true, next_guess.node_guess,
                                 value_guess.first_guess);
            }
            return result_guess;
        }
        result_guess = Insert_guess(value_guess.first_guess).first_guess;
        return result_guess;
    }

    result_guess = Insert_guess(value_guess.first_guess).first_guess;
    return result_guess;
}

// EXTERNAL: TITANIUM 0x0042B7FE FUN_0042b7fe_guess
void __fastcall FUN_0042b7fe_guess(int self_guess);

// Standard library: list destructor (erases every node and frees the head, 0x0042B7FE).
// FUNCTION: TITANIUM 0x0042BDE9
void __fastcall FUN_0042bde9_guess(int self_guess)
{
    return FUN_0042b7fe_guess(self_guess);
}

// EXTERNAL: TITANIUM 0x0042BDBE FUN_0042bdbe_guess
void __fastcall FUN_0042bdbe_guess(int self_guess);

typedef CompoundValue_guess State_guess;

struct SortedNode_guess {
    SortedNode_guess* next_guess;      // 0x0
    SortedNode_guess* prev_guess;      // 0x4
    CompoundValue_guess* value_guess;  // 0x8
};

struct SortedList_guess {
    void* firstIter_guess;            // 0x0
    SortedNode_guess* head_guess;     // 0x4
    unsigned int size_guess;          // 0x8
    // EXTERNAL: TITANIUM 0x0042926B SortedList_guess::Insert_guess
    void Insert_guess(SortedNode_guess* where_guess, CompoundValue_guess* const& value_guess);
};

struct Activator_guess {
    unsigned char padding_guess[0x28];
    SortedList_guess values_guess;    // 0x28
    // EXTERNAL: TITANIUM 0x0042B03C Activator_guess::Update_guess
    void Update_guess();
    // EXTERNAL: TITANIUM 0x00402D37 Activator_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    void Activate_guess(State_guess* state_guess);
    void Enable_guess(State_guess* state_guess);
};

// Adds `state` to the name-sorted list or updates the entry with the same name (0x00574950 compare); an
// entry with the +0x49 flag is only overwritten by one that has it too. Then refreshes and sends event 4
// to the listeners (0x00402D37).
// FUNCTION: TITANIUM 0x0042BE14
// @early-stop: budget, diff ndiff=80
void Activator_guess::Activate_guess(State_guess* state_guess)
{
    SortedNode_guess* node_guess = values_guess.head_guess->next_guess;
    for (; node_guess != values_guess.head_guess; node_guess = node_guess->next_guess) {
        CompoundValue_guess* current_guess = node_guess->value_guess;
        int compare_guess = FUN_00574950_guess(current_guess->first_guess.c_str(),
                                                state_guess->first_guess.c_str());
        if (compare_guess == 0) {
            if (current_guess->flag2_guess == 0 || state_guess->flag2_guess != 0) {
                current_guess->CopyFrom_guess(*state_guess);
            }
            break;
        }
        if (compare_guess > 0) {
            values_guess.Insert_guess(node_guess, new CompoundValue_guess(*state_guess));
            break;
        }
    }
    if (node_guess == values_guess.head_guess) {
        state_guess = new CompoundValue_guess(*state_guess);
        values_guess.Insert_guess(values_guess.head_guess, state_guess);
    }
    Update_guess();
    int* owned_guess = new int(4);
    Attach_guess(owned_guess);
    delete owned_guess;
}

// Sets the entry's +0x49 flag, then adds it to the name-sorted list or updates the same name
// (0x0042BE14); the guild and friends lists add through it.
// FUNCTION: TITANIUM 0x0042BF38
void Activator_guess::Enable_guess(State_guess* state_guess)
{
    state_guess->enabled_guess = 1;
    Activate_guess(state_guess);
}

// Map lookup by id that inserts on a miss: returns the text slot for the id, adding an empty string first
// when the id is absent. 0x0042CA9A fills its two text maps through it.
// FUNCTION: TITANIUM 0x0042BFC6
int* Tree_guess::Subscript_guess(const unsigned int& key_guess)
{
    TreeNode_guess* node_guess = Lbound_guess(key_guess);
    if (node_guess == head_guess || key_guess < node_guess->key_guess) {
        node_guess = InsertAt_guess(node_guess, StringRecord_guess(key_guess, BasicStringCopy_guess())).node_guess;
    }
    return &node_guess->value_guess;
}

// Copy constructor of the id -> text map: builds the empty head, then copies the source; if a copy throws,
// the nodes made so far are freed and the exception is rethrown.
// FUNCTION: TITANIUM 0x0042C0C6
Tree_guess::Tree_guess(const Tree_guess& source_guess)
{
    Init_guess();
    try {
        Assign_guess(source_guess);
    } catch (...) {
        EraseSubtree_guess(head_guess->parent_guess);
        throw;
    }
}

struct ParsedString_guess {
    unsigned int prefix_guess;
    char buffer_guess[16];
    unsigned int length_guess;
    unsigned int capacity_guess;
    // EXTERNAL: TITANIUM 0x00402E5E ??0ParsedString_guess@@QAE@XZ
    ParsedString_guess();
    // EXTERNAL: TITANIUM 0x00425491 ParsedString_guess::Find_guess
    int Find_guess(const char* text_guess, unsigned int position_guess,
                   unsigned int count_guess) const;
    // EXTERNAL: TITANIUM 0x004255B3 ParsedString_guess::FindFirstOf_guess
    unsigned int FindFirstOf_guess(const char* text_guess, unsigned int position_guess,
                                   unsigned int count_guess) const;
    // EXTERNAL: TITANIUM 0x0042561D ParsedString_guess::FindLastOf_guess
    unsigned int FindLastOf_guess(const char* text_guess, unsigned int position_guess,
                                  unsigned int count_guess) const;
    // EXTERNAL: TITANIUM 0x00427645 ParsedString_guess::Substr_guess
    ParsedString_guess Substr_guess(unsigned int position_guess, unsigned int count_guess) const;
    // EXTERNAL: TITANIUM 0x00403174 ParsedString_guess::Assign_guess
    ParsedString_guess* Assign_guess(const ParsedString_guess& source_guess,
                                     unsigned int position_guess, unsigned int count_guess);
    const std::string& StdString_guess() const {
        return *(const std::string*)this;
    }
    ~ParsedString_guess() {
        ((StringStorage_guess*)this)->Tidy_guess(true, 0);
    }
};

// basic_ios<char> part of the input stream (virtual base at +0x50)
// EXTERNAL: TITANIUM 0x0063F558 ??_7StreamIos_guess@@6B@
struct StreamIos_guess : std::ios_base {
    virtual ~StreamIos_guess() {}
    operator void*() const {
        return fail() ? 0 : (void*)this;
    }
};

// istringstream
struct ParsedInputStream_guess : virtual StreamIos_guess {
    unsigned char storage_guess[0x4c];
    // EXTERNAL: TITANIUM 0x00403317 ParsedInputStream_guess::ParsedInputStream_guess
    ParsedInputStream_guess(const std::string& text_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x0040271A ParsedInputStream_guess::~ParsedInputStream_guess
    ~ParsedInputStream_guess();
};

// operator>>(istream&, string&)
// EXTERNAL: TITANIUM 0x00426654 ReadWord_guess
ParsedInputStream_guess& __cdecl ReadWord_guess(ParsedInputStream_guess& stream_guess,
                                                std::string& text_guess);

struct ParsedText_guess {
    ParsedString_guess name_guess;            // 0x0
    std::vector<std::string> entries_guess;   // 0x1C
    ParsedString_guess value_guess;           // 0x2C
    bool valid_guess;                         // 0x48
    bool state_guess;                         // 0x49
    ParsedText_guess(const ParsedString_guess& text_guess);
};

struct ParseError_guess {
};

// Parses "<name> address": throws a parse error when the angle brackets are missing.
// FUNCTION: TITANIUM 0x0042C74B
// @early-stop: budget, structural ndiff=50
ParsedText_guess::ParsedText_guess(const ParsedString_guess& text_guess)
{
    int one_guess = 0;
    ++one_guess;
    char delimiter_guess = '<';
    unsigned int first_guess = text_guess.Find_guess(&delimiter_guess, 0, one_guess);
    if (first_guess == std::string::npos) {
        throw ParseError_guess();
    }
    delimiter_guess = '>';
    unsigned int last_guess = text_guess.Find_guess(&delimiter_guess, 0, one_guess);
    if (last_guess == std::string::npos) {
        throw ParseError_guess();
    }
    delimiter_guess = ' ';
    if (text_guess.FindFirstOf_guess(&delimiter_guess, last_guess + 1, one_guess)
        != std::string::npos) {
        throw ParseError_guess();
    }
    ParsedString_guess prefix_guess = text_guess.Substr_guess(0, first_guess);
    delimiter_guess = ' ';
    unsigned int firstSpace_guess = prefix_guess.FindFirstOf_guess(&delimiter_guess, 0, one_guess);
    if (firstSpace_guess == std::string::npos) {
        throw ParseError_guess();
    }
    delimiter_guess = ' ';
    unsigned int lastSpace_guess =
        prefix_guess.FindLastOf_guess(&delimiter_guess, std::string::npos, one_guess);
    name_guess.Assign_guess(prefix_guess.Substr_guess(
        firstSpace_guess, lastSpace_guess - firstSpace_guess + 1), 0, std::string::npos);
    ParsedInputStream_guess stream_guess(
        text_guess.Substr_guess(first_guess + 1, last_guess - first_guess - 1).StdString_guess(),
        std::ios_base::in);
    std::string entry_guess;
    while (ReadWord_guess(stream_guess, entry_guess)) {
        entries_guess.push_back(entry_guess);
    }
    if (entries_guess.size() == 0) {
        throw ParseError_guess();
    }
    ((EntryRange_guess*)this)->ForEach_guess();
    valid_guess = true;
    state_guess = false;
}

// Standard library: list destructor (erases every node and frees the head, 0x0042BDBE).
// FUNCTION: TITANIUM 0x0042C96D
void __fastcall FUN_0042c96d_guess(int self_guess)
{
    return FUN_0042bdbe_guess(self_guess);
}

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* message_guess, ...);

struct PathVector_guess {
    unsigned int prefix_guess;        // 0x0
    PathString_guess* first_guess;    // 0x4
    PathString_guess* last_guess;     // 0x8
    unsigned int end_guess;           // 0xC
    // EXTERNAL: TITANIUM 0x0040B540 PathVector_guess::Tidy_guess
    void Tidy_guess();
    // EXTERNAL: TITANIUM 0x0040AB88 PathVector_guess::Size_guess
    int Size_guess();
    // EXTERNAL: TITANIUM 0x0040B88B PathVector_guess::PushBack_guess
    void PushBack_guess(const PathString_guess& text_guess);
};

struct MailboxList_guess {
    unsigned char padding_guess[0xc];
    PathVector_guess mailboxes_guess;  // 0xC
    int value1c_guess;                 // 0x1C
    int value20_guess;                 // 0x20
    // EXTERNAL: TITANIUM 0x00402D37 MailboxList_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    void SetMailboxes_guess(int count_guess, int value_guess, const char* text_guess);
};

// Splits the comma-separated mailbox list; logs an unexpected-count line when the count
// differs.
// FUNCTION: TITANIUM 0x0042C972
void MailboxList_guess::SetMailboxes_guess(int count_guess, int value_guess, const char* text_guess)
{
    PathString_guess text_guess_local(text_guess);
    mailboxes_guess.Tidy_guess();
    unsigned int position_guess = 0;
    if (count_guess > 0) {
        int remaining_guess = count_guess;
        do {
            char separator_guess = ',';
            int found_guess = text_guess_local.Find_guess(&separator_guess, position_guess, 1);
            if (found_guess != -1) {
                mailboxes_guess.PushBack_guess(
                    text_guess_local.Substr_guess(position_guess, found_guess - position_guess));
                position_guess = found_guess + 1;
            } else {
                mailboxes_guess.PushBack_guess(text_guess_local.Substr_guess(position_guess, 0xffffffff));
            }
        } while (--remaining_guess != 0);
    }
    if (mailboxes_guess.Size_guess() != count_guess) {
        Log_guess("Mail: unexpected number of mailboxes.");
    }
    value1c_guess = value_guess;
    value20_guess = value_guess;
    int* owned_guess = new int(3);
    Attach_guess(owned_guess);
    free(owned_guess);
}


// EXTERNAL: TITANIUM 0x006104F0 _stat
extern "C" int __cdecl _stat(const char* path_guess, void* buffer_guess);

struct NameText_guess {
    unsigned int prefix_guess;       // 0x0
    char buffer_guess[16];           // 0x4
    unsigned int length_guess;       // 0x14
    unsigned int capacity_guess;     // 0x18
    const char* CStr_guess() const {
        return capacity_guess >= 0x10 ? *(const char**)buffer_guess : buffer_guess;
    }
    // EXTERNAL: TITANIUM 0x0040338B NameText_guess::Assign_guess
    void Assign_guess(const char* text_guess);
};

struct FileLoader_guess {
    unsigned char padding_guess[0xc];
    NameText_guess path_guess;             // 0xC
    // EXTERNAL: TITANIUM 0x00402D37 FileLoader_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    // EXTERNAL: TITANIUM 0x0042C213 FileLoader_guess::Probe_guess
    char Probe_guess();
    // EXTERNAL: TITANIUM 0x0042B03C FileLoader_guess::Fallback_guess
    bool Fallback_guess();
    bool Load_guess(const char* text_guess);
};

struct StringVector_guess {
    unsigned int prefix_guess;            // 0x0
    BasicStringCopy_guess* first_guess;   // 0x4
    BasicStringCopy_guess* last_guess;    // 0x8
    // EXTERNAL: TITANIUM 0x0040AB88 StringVector_guess::Size_guess
    int Size_guess();
};

struct StringList_guess {
    unsigned char padding_guess[0xc];
    StringVector_guess items_guess;       // 0xC
    BasicStringCopy_guess At_guess(unsigned int index_guess);
};

#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

// Copy of the string at the given index in the vector at +0x0C, or an empty string when out of range.
// FUNCTION: TITANIUM 0x004275C7
BasicStringCopy_guess StringList_guess::At_guess(unsigned int index_guess)
{
    if (index_guess < items_guess.Size_guess()) {
        return items_guess.first_guess[index_guess];
    }
    return BasicStringCopy_guess(g_emptyText_guess);
}

// Loads the address book file `text_guess`; a missing file falls back to an empty book.
// FUNCTION: TITANIUM 0x0042CB80
bool FileLoader_guess::Load_guess(const char* text_guess)
{
    path_guess.Assign_guess(text_guess);
    int stat_guess[9];
    if (_stat(text_guess, stat_guess) != 0) {
        return Fallback_guess();
    }
    if (Probe_guess() != 0) {
        int* owned_guess = new int(4);
        Attach_guess(owned_guess);
        free(owned_guess);
        return true;
    }
    return false;
}

// Address multiset difference: +1 for each of ours, -1 for each of `other_guess`'s.
// FUNCTION: TITANIUM 0x0042CBEA
// @early-stop: budget, diff ndiff=4
std::map<std::string, int> MailAddressRecord_guess::Diff_guess(
    const MailAddressRecord_guess& other_guess) const
{
    std::map<std::string, int> counts_guess;
    std::vector<MailAddressEntry_guess>::const_iterator it_guess;
    for (it_guess = addresses_guess.begin(); it_guess != addresses_guess.end(); ++it_guess) {
        ++counts_guess[it_guess->text_guess];
    }
    for (it_guess = other_guess.addresses_guess.begin();
         it_guess != other_guess.addresses_guess.end(); ++it_guess) {
        --counts_guess[it_guess->text_guess];
    }
    return counts_guess;
}

// Change flags against `other_guess`: bit 0 the name differs, bit 1 the addresses differ; further bits for
// the other fields.
// FUNCTION: TITANIUM 0x0042CC75
int MailAddressRecord_guess::Compare_guess(const MailAddressRecord_guess& other_guess) const
{
    int flags_guess = 0;
    if (name_guess.compare(other_guess.name_guess) != 0) {
        flags_guess = 1;
    }
    std::map<std::string, int> diff_guess = Diff_guess(other_guess);
    for (std::map<std::string, int>::const_iterator it_guess = diff_guess.begin();
         it_guess != diff_guess.end(); ++it_guess) {
        if (it_guess->second != 0) {
            flags_guess |= 2;
            break;
        }
    }
    if (note_guess.compare(other_guess.note_guess) != 0) {
        flags_guess |= 4;
    }
    return flags_guess;
}

struct PurgeOwner_guess {
    std::list<int> first_guess;                  // 0x00
    std::string text_guess;                      // 0x0C
    std::list<PurgeObject_guess*> list_guess;    // 0x28
    void Purge_guess(bool all_guess);
    bool SaveAddressBook_guess();
    ~PurgeOwner_guess();
};

// Deletes the listed objects whose +0x49 flag is clear, or every object when `all_guess` is set.
// FUNCTION: TITANIUM 0x0042BA0C
void PurgeOwner_guess::Purge_guess(bool all_guess)
{
    std::list<PurgeObject_guess*>::iterator it_guess = list_guess.begin();
    while (it_guess != list_guess.end()) {
        if ((*it_guess)->flag49_guess == 0 || all_guess) {
            delete *it_guess;
            it_guess = list_guess.erase(it_guess);
        } else {
            ++it_guess;
        }
    }
}

// Destructor: deletes every entry, flagged or not (Purge with all set).
// FUNCTION: TITANIUM 0x0042BDEE
PurgeOwner_guess::~PurgeOwner_guess()
{
    Purge_guess(true);
}

#define g_addressBookHeader_guess EQ_GLOBAL(std::string, 0x0079DBF8)

// EXTERNAL: TITANIUM 0x0042AAE3 ??0?$basic_ifstream@DU?$char_traits@D@std@@@std@@QAE@XZ
// EXTERNAL: TITANIUM 0x004276EE ?open@?$basic_ifstream@DU?$char_traits@D@std@@@std@@QAEXPBDHH@Z
// EXTERNAL: TITANIUM 0x0042AB50 ??1?$basic_ifstream@DU?$char_traits@D@std@@@std@@UAE@XZ

// Loads the mail address book file: the header line (0x79DBF8), then '#' comment lines, then records of
// "Name: ", "Addresses: " (words), an optional "Flags: " line (PRIVATE clears the public flag) and "Note: "
// plus continuation lines up to an empty line. Each record is handed to Activate_guess. The address book
// object is viewed here as FileLoader_guess, PurgeOwner_guess and Activator_guess.
// FUNCTION: TITANIUM 0x0042C213
char FileLoader_guess::Probe_guess()
{
    if (path_guess.length_guess == 0) {
        return 0;
    }

    std::ifstream input_guess;
    input_guess.open(path_guess.CStr_guess());
    if (input_guess.fail()) {
        return 0;
    }

    ((PurgeOwner_guess*)this)->Purge_guess(false);

    std::string line_guess;
    GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);
    if (line_guess.compare(g_addressBookHeader_guess) != 0) {
        return 0;
    }

    while (!input_guess.eof()) {
        GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);
        if (line_guess.size() != 0 && line_guess.at(0) != '#') {
            break;
        }
    }

    do {
        std::string name_guess;
        std::vector<std::string> addresses_guess;
        bool public_guess = true;
        std::string note_guess;
        if (line_guess.substr(0, 6).compare("Name: ") != 0) {
            return 0;
        }
        name_guess.assign(line_guess.substr(6));
        GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);

        std::istringstream stream_guess(line_guess);
        std::string word_guess;
        stream_guess >> word_guess;
        if (word_guess.compare("Addresses:") != 0) {
            return 0;
        }
        while (stream_guess >> word_guess) {
            addresses_guess.push_back(word_guess);
        }

        GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);
        if (line_guess.substr(0, 7).compare("Flags: ") == 0) {
            public_guess = line_guess.find("PRIVATE") == std::string::npos;
            GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);
        }
        if (line_guess.substr(0, 6).compare("Note: ") != 0) {
            return 0;
        }
        note_guess.append(line_guess.substr(6));
        while (*(std::istream*)GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess)
               && line_guess.size() != 0) {
            note_guess.append(1, '\n');
            note_guess.append(line_guess);
        }

        CompoundValue_guess entry_guess(name_guess, addresses_guess, note_guess, public_guess);
        ((Activator_guess*)this)->Activate_guess(&entry_guess);
        GetLine_guess((Stream_guess*)&input_guess, (Stream_guess*)&line_guess);
    } while (!input_guess.eof());

    return 1;
}

// EXTERNAL: TITANIUM 0x00429177 ??0?$basic_ofstream@DU?$char_traits@D@std@@@std@@QAE@XZ
// EXTERNAL: TITANIUM 0x00427AB4 ?open@?$basic_ofstream@DU?$char_traits@D@std@@@std@@QAEXPBDHH@Z
// EXTERNAL: TITANIUM 0x00429229 ?close@?$basic_ofstream@DU?$char_traits@D@std@@@std@@QAEXXZ
// EXTERNAL: TITANIUM 0x004291E3 ??1?$basic_ofstream@DU?$char_traits@D@std@@@std@@UAE@XZ
// EXTERNAL: TITANIUM 0x0042744E ?endl@std@@YAAAV?$basic_ostream@DU?$char_traits@D@std@@@1@AAV21@@Z

// Writes the address book with its warning header (edit through the game; empty lines separate entries);
// false without a file name.
// FUNCTION: TITANIUM 0x0042B03C
// @early-stop: budget, diff ndiff=23
bool PurgeOwner_guess::SaveAddressBook_guess()
{
    bool saved_guess = false;
    if (text_guess.size() == 0) {
        return false;
    }
    std::ofstream file_guess;
    file_guess.open(text_guess.c_str());
    if (!file_guess.fail()) {
        file_guess << g_addressBookHeader_guess << std::endl;
        file_guess << "# WARNING: To avoid errors, you should modify your address book using the game interface." << std::endl;
        file_guess << "# For those of you who like to live dangerously, just be aware that empty lines separate address book entries." << std::endl;
        file_guess << "# The game normalizes notes by inserting a space in empty lines." << std::endl;
        for (std::list<PurgeObject_guess*>::iterator it_guess = list_guess.begin();
             it_guess != list_guess.end(); ++it_guess) {
            if ((*it_guess)->flag49_guess == 0) {
                WriteAddressRecord_guess(&file_guess, (AddressRecord_guess*)*it_guess);
            }
        }
        file_guess.close();
        saved_guess = true;
    }
    return saved_guess;
}

struct Element_guess {
    // EXTERNAL: TITANIUM 0x0040B867 Element_guess::~Element_guess
    ~Element_guess();
};

struct ListBase_guess {
    unsigned int prefix_guess;     // 0x0
    ListNode_guess* head_guess;    // 0x4
    ListIter_guess Begin_guess() {
        return ListIter_guess(head_guess->next_guess);
    }
    ListIter_guess End_guess() {
        return ListIter_guess(head_guess);
    }
    // EXTERNAL: TITANIUM 0x005184E7 ListBase_guess::Erase_guess
    ListIter_guess Erase_guess(ListIter_guess where_guess);
};

struct ListLoader_guess {
    unsigned char padding_guess[0x28];
    ListBase_guess list_guess;     // 0x28
    // EXTERNAL: TITANIUM 0x00402D37 ListLoader_guess::Attach_guess
    void Attach_guess(int* owned_guess);
    // EXTERNAL: TITANIUM 0x0042B03C ListLoader_guess::Fallback_guess
    bool Fallback_guess();
    void Remove_guess(int value_guess);
};

// Removes the address book entry `value` (compared as a pointer): deletes it, erases it from the list
// (+0x28), saves the address book file (0x0042B03C) and passes event 4 to the listeners (0x00402D37).
// Nothing happens when it is not in the list.
// FUNCTION: TITANIUM 0x0042BF49
void ListLoader_guess::Remove_guess(int value_guess)
{
    ListIter_guess it_guess = FindListValue_guess(list_guess.Begin_guess(), list_guess.End_guess(), value_guess);
    if (it_guess.node_guess != list_guess.head_guess) {
        delete (Element_guess*)it_guess.node_guess->value_guess;
        list_guess.Erase_guess(it_guess);
        Fallback_guess();
        int* owned_guess = new int(4);
        Attach_guess(owned_guess);
        delete owned_guess;
    }
}

struct ChatState_guess {
    std::list<int> first_guess;                // 0x00
    std::vector<std::string> paths_guess;      // 0x0C
    int value1c_guess;                         // 0x1C
    int value20_guess;                         // 0x20
    std::deque<int> pending_guess;             // 0x24
    std::map<int, int> firstMap_guess;         // 0x38
    std::map<int, int> secondMap_guess;        // 0x44
    unsigned char padding50_guess[0x10];       // 0x50
    PurgeOwner_guess owner_guess;              // 0x60
    // EXTERNAL: TITANIUM 0x0042AF8E ChatState_guess::Clear_guess
    void Clear_guess();
    void RequestHeaders_guess();
    ~ChatState_guess();
};

// Mail state destructor: clears it (0x0042AF8E).
// FUNCTION: TITANIUM 0x0042C1B2
ChatState_guess::~ChatState_guess()
{
    Clear_guess();
}

// Clears the headers and requests them again ("[getheaders"); string 4529 when not connected.
// FUNCTION: TITANIUM 0x0042B34A
void ChatState_guess::RequestHeaders_guess()
{
    Clear_guess();
    if (g_mailHost_guess->sender_guess != 0) {
        std::ostringstream stream_guess;
        stream_guess << '[' << "getheaders";
        g_mailHost_guess->sender_guess->Send_guess(stream_guess.str().c_str());
    } else {
        pEverQuest->dsp_chat(pStringTable->getString(0x11b1, 0), 0xd, 1);
    }
}

// EXTERNAL: TITANIUM 0x0044C325 GetDynamicAssetId_guess
int __stdcall GetDynamicAssetId_guess(const char* text_guess);

struct MailStringLookup_guess {
    // EXTERNAL: TITANIUM 0x0044C325 MailStringLookup_guess::Get_guess
    int Get_guess(const char* text_guess);
};

#define g_youveGotMail_guess EQ_GLOBAL(MailStringLookup_guess*, 0x00851390)
#define g_mailString_guess EQ_ARRAY(char, 0x006417F4)

struct SoundList_guess {
    unsigned int words_guess[3];
    // EXTERNAL: TITANIUM 0x0042610D ??0SoundList_guess@@QAE@XZ
    SoundList_guess();
    ~SoundList_guess();
};

struct ManagedObject_guess {
    CtorPart_guess first_guess;          // 0x0
    std::vector<std::string> paths_guess; // 0xc
    int field1c_guess;                   // 0x1c
    int field20_guess;                   // 0x20
    std::deque<int> pending_guess;       // 0x24
    SoundList_guess list38_guess;        // 0x38
    SoundList_guess list44_guess;        // 0x44
    unsigned char pad50_guess[0x10];     // 0x50
    CtorOwner_guess owner60_guess;       // 0x60
    int field98_guess;                   // 0x98
    unsigned char byte9c_guess;          // 0x9c
    unsigned char byte9d_guess;          // 0x9d
    ManagedObject_guess();
    // EXTERNAL: TITANIUM 0x0042AF8E ManagedObject_guess::FUN_0042af8e_guess
    void FUN_0042af8e_guess();
};

// Mail state: looks up the you've-got-mail sound id when the asset table exists.
// FUNCTION: TITANIUM 0x0042C115
ManagedObject_guess::ManagedObject_guess()
{
    FUN_0042af8e_guess();
    field1c_guess = 0;
    field20_guess = 0;
    byte9c_guess = 0;
    byte9d_guess = 1;
    MailStringLookup_guess* mailLookup_guess = g_youveGotMail_guess;
    if (mailLookup_guess != 0) {
        field98_guess = mailLookup_guess->Get_guess(g_mailString_guess);
    }
}

struct SpanRange_guess {
    unsigned char storage_guess[0xc];  // 0x0
    int begin_guess;                   // 0xc
    int length_guess;                  // 0x10
};

struct SpanPair_guess {
    void* first_guess;
    unsigned int second_guess;
    SpanPair_guess() {}
    SpanPair_guess(void* first_value_guess, unsigned int second_value_guess)
        : first_guess(first_value_guess), second_guess(second_value_guess) {}
    // EXTERNAL: TITANIUM 0x00491002 SpanPair_guess::Equals_guess
    bool Equals_guess(const SpanPair_guess& other_guess) const;
    // EXTERNAL: TITANIUM 0x00425170 SpanPair_guess::Deref_guess
    unsigned int* Deref_guess() const;
};

// EXTERNAL: TITANIUM 0x004257CA FindRange_guess
SpanPair_guess __cdecl FindRange_guess(const void* source_guess, int begin_guess,
                                       const void* source2_guess, int end_guess, unsigned int key_guess);

// EXTERNAL: TITANIUM 0x004657FB CopyTextPair_guess
void __cdecl CopyTextPair_guess(const char* source_guess, const char* destination_guess);

struct RangeTriple_guess {
    int tag_guess;                     // 0x0
    unsigned int value_guess;          // 0x4
    int flag_guess;                    // 0x8
    RangeTriple_guess(int tag_value_guess, unsigned int value_value_guess, int flag_value_guess)
        : tag_guess(tag_value_guess), value_guess(value_value_guess), flag_guess(flag_value_guess) {}
};

struct StdStringRef_guess {
    // EXTERNAL: TITANIUM 0x0040338B StdStringRef_guess::Assign_guess
    StdStringRef_guess& Assign_guess(const char* text_guess);
};

struct RangeRecord_guess {
    unsigned char padding0_guess[0x1c];  // 0x0
    int kind_guess;                      // 0x1c
    unsigned char padding1_guess[4];     // 0x20
    SpanRange_guess span_guess;          // 0x24
    Tree_guess first_tree_guess;         // 0x38
    Tree_guess second_tree_guess;        // 0x44
    // EXTERNAL: TITANIUM 0x00402D37 RangeRecord_guess::Flush_guess
    void Flush_guess(RangeTriple_guess* entry_guess);
    void Fn_guess(int kind_arg_guess, unsigned int key_guess, const char* first_text_guess,
                  const char* second_text_guess);
};

// A fetched mail body: when `kind` matches and `key` is a pending header id, stores the body text(s)
// under that id and tells the listeners (0x00402D37); the mail callback calls it.
// FUNCTION: TITANIUM 0x0042CA9A
// @early-stop: budget, diff ndiff=13
void RangeRecord_guess::Fn_guess(int kind_arg_guess, unsigned int key_guess, const char* first_text_guess,
                                 const char* second_text_guess)
{
    if (kind_arg_guess == kind_guess) {
        SpanRange_guess* span_ptr_guess = &span_guess;
        SpanPair_guess found_guess;
        found_guess = FindRange_guess(span_ptr_guess, span_ptr_guess->begin_guess, span_ptr_guess,
                                      span_ptr_guess->begin_guess + span_ptr_guess->length_guess, key_guess);
        if (!found_guess.Equals_guess(SpanPair_guess(span_ptr_guess,
                                                     span_ptr_guess->begin_guess + span_ptr_guess->length_guess))) {
            unsigned int value_guess = *found_guess.Deref_guess();
            CopyTextPair_guess(first_text_guess, first_text_guess);
            StdStringRef_guess* first_slot_guess = (StdStringRef_guess*)first_tree_guess.Subscript_guess(key_guess);
            first_slot_guess->Assign_guess(first_text_guess);
            if (second_text_guess != 0 && *second_text_guess != 0) {
                StdStringRef_guess* second_slot_guess = (StdStringRef_guess*)second_tree_guess.Subscript_guess(key_guess);
                second_slot_guess->Assign_guess(second_text_guess);
            }
            RangeTriple_guess* entry_guess = new RangeTriple_guess(1, value_guess, 2);
            Flush_guess(entry_guess);
            free(entry_guess);
        }
    }
}

// Standard library: scalar deleting destructor of a stream entered at its ios_base (+0x60; flag 1 frees
// the memory).
// FUNCTION: TITANIUM 0x0042AB96
// @early-stop: budget, diff ndiff=1
AdjustedObject_guess* AdjustedObject_guess::Delete_guess(unsigned char flags_guess)
{
    AdjustedObject_guess* object_guess = this - 0x60;
    object_guess->Destroy_guess();
    if ((flags_guess & 1) != 0) {
        ::operator delete(object_guess);
    }
    return object_guess;
}

// Standard library: destroys the stream's ios_base part (0x00401C6C).
// FUNCTION: TITANIUM 0x0042A426
// @early-stop: budget, structural ndiff=6
void AdjustedObject_guess::Destroy_guess()
{
    DestroyPart_guess();
}

struct CandidateActionTarget_guess;
struct CandidateAction_guess;

struct Candidate_guess {
    unsigned char kind_guess;             // 0x0
    unsigned char padding_guess[0x21];    // 0x1
    unsigned char enabled_guess;           // 0x22
    unsigned char padding1_guess[0x185];   // 0x23
    CandidateAction_guess* action_guess;   // 0x1a8
    unsigned char padding2_guess[0x98];    // 0x1ac
    unsigned char state_guess;             // 0x244
    // EXTERNAL: TITANIUM 0x004903F1 Candidate_guess::Check_guess
    bool Check_guess();
};

struct CandidateAction_guess {
    CandidateActionTarget_guess* target_guess;
};

struct CandidateActionTarget_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual bool Check_guess();
};

struct CandidateSource_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual Candidate_guess* Get_guess();
};

struct CandidateOwner_guess {
    unsigned char padding_guess[0x5c];
    CandidateSource_guess* source_guess;  // 0x5c
    int HasAction_guess();
    int HasCandidate_guess();
    int SetCandidate_guess(int unused_guess);
};

// True unless the selected object is a kind-3 one that is not ready (state < 1).
// FUNCTION: TITANIUM 0x0042CD0B
int CandidateOwner_guess::HasAction_guess()
{
    Candidate_guess* candidate_guess = source_guess->Get_guess();
    if ((unsigned int)candidate_guess > 0x10) {
        switch (candidate_guess->kind_guess) {
        case 3:
            if (candidate_guess->state_guess >= 1 ||
                candidate_guess->action_guess->target_guess->Check_guess()) {
                return 0;
            }
            return 1;
        case 5:
            return 1;
        }
    }
    return 1;
}

// True when the selected object is a kind-5 one that passes its check (0x004903F1).
// FUNCTION: TITANIUM 0x0042CD4A
int CandidateOwner_guess::HasCandidate_guess()
{
    Candidate_guess* candidate_guess = source_guess->Get_guess();
    if ((unsigned int)candidate_guess > 0x10 && candidate_guess->kind_guess == 5) {
        if (candidate_guess->Check_guess()) {
            return true;
        }
    }
    return false;
}

struct CandidateSlot_guess {
    unsigned char padding_guess[0xf94];
    Candidate_guess* candidate_guess;  // 0xf94
};

struct CandidateManager_guess {
    unsigned char padding_guess[0x1a8];
    CandidateSlot_guess* slot_guess;  // 0x1a8
    // EXTERNAL: TITANIUM 0x0047F7DC CandidateManager_guess::Refresh_guess
    void Refresh_guess();
};

#define g_candidateManager_guess EQ_GLOBAL(CandidateManager_guess*, 0x00905CF8)

// Selects a kind-5 object that passes its check and refreshes the manager (TouchingSwitch_guess).
// FUNCTION: TITANIUM 0x0042CD6E
int CandidateOwner_guess::SetCandidate_guess(int unused_guess)
{
    Candidate_guess* candidate_guess = source_guess->Get_guess();
    if ((unsigned int)candidate_guess > 0x10 && candidate_guess->kind_guess == 5) {
        if (candidate_guess->Check_guess()) {
            g_candidateManager_guess->slot_guess->candidate_guess = candidate_guess;
            g_candidateManager_guess->Refresh_guess();
        }
    }
    return 1;
}

struct StrMapNode_guess {
    StrMapNode_guess* left_guess;    // 0x0
    StrMapNode_guess* parent_guess;  // 0x4
    StrMapNode_guess* right_guess;   // 0x8
    unsigned int key_guess;          // 0xC
    StringStorage_guess value_guess;  // 0x10
    unsigned char padding_guess[0x1b];
    unsigned char color_guess;       // 0x2C
    unsigned char isNil_guess;       // 0x2D
};

struct StrMapIter_guess {
    StrMapNode_guess* node_guess;    // 0x0
    StrMapIter_guess(const StrMapIter_guess& source_guess) : node_guess(source_guess.node_guess) {}
    // EXTERNAL: TITANIUM 0x0042533A ??EStrMapIter_guess@@QAEAAU0@XZ
    StrMapIter_guess& operator++();
};

struct StrMap_guess {
    unsigned char padding_guess[4];
    StrMapNode_guess* head_guess;    // 0x4
    unsigned int size_guess;         // 0x8
    // EXTERNAL: TITANIUM 0x00425275 StrMap_guess::Lrotate_guess
    void Lrotate_guess(StrMapNode_guess* node_guess);
    // EXTERNAL: TITANIUM 0x004252B7 StrMap_guess::Rrotate_guess
    void Rrotate_guess(StrMapNode_guess* node_guess);
    StrMapIter_guess Erase_guess(StrMapIter_guess where_guess);
    static StrMapNode_guess* Min_guess(StrMapNode_guess* node_guess) {
        while (node_guess->left_guess->isNil_guess == 0) {
            node_guess = node_guess->left_guess;
        }
        return node_guess;
    }
    static StrMapNode_guess* Max_guess(StrMapNode_guess* node_guess) {
        while (node_guess->right_guess->isNil_guess == 0) {
            node_guess = node_guess->right_guess;
        }
        return node_guess;
    }
};

// map<..., string>::erase(iterator) as in the Dinkumware _Tree: unlinks the node, rebalances (color 1 is
// black), destroys the string and frees the node; returns the next iterator. Throws on the end node.
// FUNCTION: TITANIUM 0x004280BF
// @early-stop: inline, structural ndiff=103
StrMapIter_guess StrMap_guess::Erase_guess(StrMapIter_guess where_guess)
{
    if (where_guess.node_guess->isNil_guess != 0) {
        throw ExceptionDerived_guess(BasicStringCopy_guess("invalid map/set<T> iterator"));
    }
    StrMapNode_guess* fixParent_guess;
    StrMapNode_guess* fix_guess;
    StrMapNode_guess* erased_guess = where_guess.node_guess;
    ++where_guess;

    StrMapNode_guess* node_guess = erased_guess;
    if (node_guess->left_guess->isNil_guess != 0) {
        fix_guess = node_guess->right_guess;
    } else if (node_guess->right_guess->isNil_guess != 0) {
        fix_guess = node_guess->left_guess;
    } else {
        node_guess = where_guess.node_guess;
        fix_guess = node_guess->right_guess;
    }

    if (node_guess == erased_guess) {
        fixParent_guess = erased_guess->parent_guess;
        if (fix_guess->isNil_guess == 0) {
            fix_guess->parent_guess = fixParent_guess;
        }
        if (head_guess->parent_guess == erased_guess) {
            head_guess->parent_guess = fix_guess;
        } else if (fixParent_guess->left_guess == erased_guess) {
            fixParent_guess->left_guess = fix_guess;
        } else {
            fixParent_guess->right_guess = fix_guess;
        }
        if (head_guess->left_guess == erased_guess) {
            head_guess->left_guess = fix_guess->isNil_guess != 0 ? fixParent_guess : Min_guess(fix_guess);
        }
        if (head_guess->right_guess == erased_guess) {
            head_guess->right_guess = fix_guess->isNil_guess != 0 ? fixParent_guess : Max_guess(fix_guess);
        }
    } else {
        erased_guess->left_guess->parent_guess = node_guess;
        node_guess->left_guess = erased_guess->left_guess;
        if (node_guess == erased_guess->right_guess) {
            fixParent_guess = node_guess;
        } else {
            fixParent_guess = node_guess->parent_guess;
            if (fix_guess->isNil_guess == 0) {
                fix_guess->parent_guess = fixParent_guess;
            }
            fixParent_guess->left_guess = fix_guess;
            node_guess->right_guess = erased_guess->right_guess;
            erased_guess->right_guess->parent_guess = node_guess;
        }
        if (head_guess->parent_guess == erased_guess) {
            head_guess->parent_guess = node_guess;
        } else if (erased_guess->parent_guess->left_guess == erased_guess) {
            erased_guess->parent_guess->left_guess = node_guess;
        } else {
            erased_guess->parent_guess->right_guess = node_guess;
        }
        node_guess->parent_guess = erased_guess->parent_guess;
        std::swap(node_guess->color_guess, erased_guess->color_guess);
    }

    if (erased_guess->color_guess == 1) {
        for (; fix_guess != head_guess->parent_guess && fix_guess->color_guess == 1;
             fix_guess = fixParent_guess, fixParent_guess = fix_guess->parent_guess) {
            if (fix_guess == fixParent_guess->left_guess) {
                node_guess = fixParent_guess->right_guess;
                if (node_guess->color_guess == 0) {
                    node_guess->color_guess = 1;
                    fixParent_guess->color_guess = 0;
                    Lrotate_guess(fixParent_guess);
                    node_guess = fixParent_guess->right_guess;
                }
                if (node_guess->isNil_guess != 0) {
                    fix_guess = fixParent_guess;
                } else if (node_guess->left_guess->color_guess == 1 &&
                           node_guess->right_guess->color_guess == 1) {
                    node_guess->color_guess = 0;
                    fix_guess = fixParent_guess;
                } else {
                    if (node_guess->right_guess->color_guess == 1) {
                        node_guess->left_guess->color_guess = 1;
                        node_guess->color_guess = 0;
                        Rrotate_guess(node_guess);
                        node_guess = fixParent_guess->right_guess;
                    }
                    node_guess->color_guess = fixParent_guess->color_guess;
                    fixParent_guess->color_guess = 1;
                    node_guess->right_guess->color_guess = 1;
                    Lrotate_guess(fixParent_guess);
                    break;
                }
            } else {
                node_guess = fixParent_guess->left_guess;
                if (node_guess->color_guess == 0) {
                    node_guess->color_guess = 1;
                    fixParent_guess->color_guess = 0;
                    Rrotate_guess(fixParent_guess);
                    node_guess = fixParent_guess->left_guess;
                }
                if (node_guess->isNil_guess != 0) {
                    fix_guess = fixParent_guess;
                } else if (node_guess->right_guess->color_guess == 1 &&
                           node_guess->left_guess->color_guess == 1) {
                    node_guess->color_guess = 0;
                    fix_guess = fixParent_guess;
                } else {
                    if (node_guess->left_guess->color_guess == 1) {
                        node_guess->right_guess->color_guess = 1;
                        node_guess->color_guess = 0;
                        Lrotate_guess(node_guess);
                        node_guess = fixParent_guess->left_guess;
                    }
                    node_guess->color_guess = fixParent_guess->color_guess;
                    fixParent_guess->color_guess = 1;
                    node_guess->left_guess->color_guess = 1;
                    Rrotate_guess(fixParent_guess);
                    break;
                }
            }
        }
        fix_guess->color_guess = 1;
    }

    erased_guess->value_guess.Tidy_guess(true, 0);
    free(erased_guess);
    if (0 < size_guess) {
        --size_guess;
    }
    return where_guess;
}
