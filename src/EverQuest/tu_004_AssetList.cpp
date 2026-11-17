// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 4: a hint from compare/tumap.py.
// The zone asset list "<zone>_assets.txt" (read by tu_029): one entry per word, "CHR,<name>,<file>" for
// a character model, anything else an object file. AssetList_guess is that list; AssetObjectEntry_guess and AssetCharacterEntry_guess
// the entry kinds (vtables 0x63F9D4, 0x63F9F0), Callback_guess and Entry_guess their views.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <stdio.h>
#include <string.h>

struct Target_guess {
    // EXTERNAL: TITANIUM 0x004482FB Target_guess::Run_guess
    void Run_guess();
};

struct Wrapper_guess {
    void FreeFileName_guess();
};

struct WrapperCall_guess {
    // EXTERNAL: TITANIUM 0x004051C5 WrapperCall_guess::FreeFileName_guess
    void FreeFileName_guess();
};

struct CallbackPrefix_guess {
    int unknown_00_guess[3];
};

struct CallbackSource_guess {
    // EXTERNAL: TITANIUM 0x00572300 CallbackSource_guess::Make_guess
    void* Make_guess(int first_guess, int zero_guess, int second_guess);
};

struct CallbackSink_guess {
    virtual void Send_guess(void* value_guess);
};

struct Callback_guess : CallbackPrefix_guess, CallbackSource_guess {
    void Load_guess(int first_guess, int second_guess);
};

#define g_callbackSink_guess EQ_GLOBAL(CallbackSink_guess*, 0x0099E360)

struct Node_guess {
    int unknown_00_guess;
    Node_guess* next_guess;
    Node_guess* prev_guess;
};

// EXTERNAL: TITANIUM 0x0060E590 FindSubstring_guess
char* __cdecl FindSubstring_guess(const char* text_guess, const char* search_guess);
// EXTERNAL: TITANIUM 0x0060E620 CopyLimited_guess
char* __cdecl CopyLimited_guess(char* destination_guess, const char* source_guess, unsigned int count_guess);

struct AssetList_guess {
    int count_guess;
    Node_guess* first_guess;
    Node_guess* last_guess;
    AssetList_guess* Load_guess(const char* path_guess);
    void Append_guess(Node_guess* node);
    void Clear_guess();
};

// The two counts at +4 and +8, zeroed before the file name text (+0xC) is constructed.
struct AssetCharacterBase_guess {
    int first_guess;
    int second_guess;
    AssetCharacterBase_guess() : first_guess(0), second_guess(0) {}
};

// The file name text is the CXStr base at +0xC.
// EXTERNAL: TITANIUM 0x0063F9F0 ??_7AssetCharacterEntry_guess@@6B@
struct AssetCharacterEntry_guess : AssetCharacterBase_guess, CXStr {
    virtual void RefreshCounts_guess();
    char name_guess[0x28];
    AssetCharacterEntry_guess(const char* line_guess);
};

// EXTERNAL: TITANIUM 0x0063F9D4 ??_7AssetObjectEntry_guess@@6B@
struct AssetObjectEntry_guess {
    virtual void RefreshCounts_guess();
    int first_guess;
    int second_guess;
    CXStr text_guess;
    AssetObjectEntry_guess(const char* text_guess);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* block);

// Frees an entry's file name (CXStr at +0xC); called before each entry is freed.
// FUNCTION: TITANIUM 0x004051C5
void Wrapper_guess::FreeFileName_guess() {
    reinterpret_cast<Target_guess*>(reinterpret_cast<char*>(this) + 0xC)->Run_guess();
}

// Object entry, vtable slot 0: hands its file name to the resource manager (0x99E360, slot 0).
// FUNCTION: TITANIUM 0x0040519E
void Callback_guess::Load_guess(int first_guess, int second_guess) {
    g_callbackSink_guess->Send_guess(
        Make_guess(first_guess, 0, second_guess));
}

struct Loader_guess {
    virtual int Open_guess(char* path_guess, int a_guess, int b_guess, int c_guess);
};

struct Display_guess {
    // EXTERNAL: TITANIUM 0x0043C187 Display_guess::LoadWorldFile_guess
    void LoadWorldFile_guess(char* a_guess, char* b_guess, int c_guess, int d_guess, int e_guess, int f_guess);
    // EXTERNAL: TITANIUM 0x004387B8 Display_guess::Method2_guess
    void Method2_guess(char* a_guess, char* b_guess, char* c_guess);
};

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format_guess, ...);

#define g_loader_guess EQ_GLOBAL(Loader_guess*, 0x0099E360)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

struct Entry_guess {
    int unknown_00_guess[3];
    CXStr text_guess;
    char name_guess[64];
    void Load_guess(int a_guess, int b_guess);
};

// Character entry, vtable slot 0: a file named after the model loads as "<file>.EQG" through the resource
// manager, falling back to CDisplay 0x43C187; otherwise CDisplay 0x4387B8 loads model `name` from the file.
// FUNCTION: TITANIUM 0x004051CD
void Entry_guess::Load_guess(int a_guess, int b_guess) {
    char path_guess[512];
    char* str_guess = name_guess;
    size_t max_guess = strlen(str_guess);
    if (strncmp(text_guess, str_guess, max_guess) == 0) {
        strcpy(path_guess, text_guess);
        strcat(path_guess, EQ_ARRAY(char, 0x0063F9E4));
        if (g_loader_guess->Open_guess(path_guess, 0, 0, 0) == 0) {
            // Logs the loaded path when the open returns 0.
            Log_guess(EQ_ARRAY(char, 0x0063F9D8), path_guess);
        } else {
            char copy_guess[256];
            strcpy(copy_guess, text_guess);
            g_display_guess->LoadWorldFile_guess(copy_guess, copy_guess, 0, 0, 0, 0);
        }
    } else {
        char copy_guess[256];
        strcpy(copy_guess, text_guess);
        g_display_guess->Method2_guess(copy_guess, copy_guess, name_guess);
    }
}

// Object-file entry of the zone asset list: no links yet, the file name copied from `input`.
// FUNCTION: TITANIUM 0x0040515E
AssetObjectEntry_guess::AssetObjectEntry_guess(const char* input_guess)
    : first_guess(0), second_guess(0), text_guess() {
    text_guess = input_guess;
}

// Reads the list file word by word (fscanf %s) until end of file.
// FUNCTION: TITANIUM 0x00405359
AssetList_guess* AssetList_guess::Load_guess(const char* path_guess) {
    count_guess = 0;
    first_guess = 0;
    last_guess = 0;
    FILE* file_guess = fopen(path_guess, "rt");
    if (file_guess != 0) {
        char line_guess[1024];
        // _IOEOF in the CRT FILE flags.
        while ((file_guess->_flag & 0x10) == 0) {
            fscanf(file_guess, "%s", line_guess);
            if (line_guess[0] != 0) {
                Node_guess* node_guess;
                if (strncmp(line_guess, "CHR,", 4) == 0) {
                    node_guess = reinterpret_cast<Node_guess*>(new AssetCharacterEntry_guess(line_guess));
                } else {
                    node_guess = reinterpret_cast<Node_guess*>(new AssetObjectEntry_guess(line_guess));
                }
                Append_guess(node_guess);
                line_guess[0] = 0;
            }
        }
        fclose(file_guess);
    }
    return this;
}

// Appends `node` at the tail of the asset list and counts it.
// FUNCTION: TITANIUM 0x004052C5
void AssetList_guess::Append_guess(Node_guess* node) {
    if (first_guess == 0) {
        first_guess = node;
    } else {
        last_guess->next_guess = node;
        node->prev_guess = last_guess;
    }
    ++count_guess;
    last_guess = node;
}

// "CHR,<name>,<file>": name (at most 40 chars) up to the comma, the rest the file; without a second comma
// the file is the whole tail after "CHR,".
// FUNCTION: TITANIUM 0x004052E8
AssetCharacterEntry_guess::AssetCharacterEntry_guess(const char* line_guess) {
    CopyLimited_guess(name_guess, line_guess + 5, 0x28);
    // ","
    char* separator_guess = FindSubstring_guess(name_guess, EQ_ARRAY(char, 0x0063F9EC));
    const char* text_value_guess = line_guess + 5;
    if (separator_guess != 0) {
        text_value_guess = separator_guess + 1;
        *separator_guess = 0;
    }
    CXStr::operator=(text_value_guess);
}

// Frees every entry. The count (+0) is left as it was.
// FUNCTION: TITANIUM 0x00405463
void AssetList_guess::Clear_guess() {
    Node_guess* node = first_guess;
    while (node != 0) {
        Node_guess* next = node->next_guess;
        reinterpret_cast<WrapperCall_guess*>(node)->FreeFileName_guess();
        free(node);
        node = next;
    }
    first_guess = 0;
    last_guess = 0;
}

