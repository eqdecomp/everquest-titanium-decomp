// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 23: a hint from compare/tumap.py.
// Slash-command helpers and handlers: GrabFirstWord_guess (quoted-argument tokenizer), DisplayTextLines_guess
// (chat printer that honours "\n" escapes), /fullscreen, /corpse, /corpsedrag, /corpsedrop, /resetaas,
// /system, /url and /www. g_log_guess (0x00988DF0) is pEverQuest.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <winsock2.h>
#include <windows.h>

struct CommandState_guess {
    char pad_0[4];
    char enabled;

    // EXTERNAL: TITANIUM 0x0060A310 CommandState_guess::Apply_guess
    void Apply_guess();
};

#define g_displayMode_guess EQ_GLOBAL(CommandState_guess*, 0x0099E38C)

// EXTERNAL: TITANIUM 0x00621E9C _stricmp_guess
extern "C" int __cdecl _stricmp_guess(const char* string1, const char* string2);

struct Logger_guess {
    // EXTERNAL: TITANIUM 0x00498436 Logger_guess::dsp_chat
    void dsp_chat(const char* text);

    // EXTERNAL: TITANIUM 0x004AE721 Logger_guess::GetBool_guess
    char GetBool_guess(const char* section, const char* key, int defaultValue);
};

#define g_log_guess EQ_GLOBAL(Logger_guess*, 0x00988DF0)
#define g_message_guess EQ_GLOBAL(int, 0x00905CA0)

extern "C" char* __cdecl strncpy(char* destination, const char* source, unsigned int count);
extern "C" void* __cdecl memset(void* destination, int value, unsigned int count);
extern "C" unsigned int __cdecl strlen(const char* text);

#define g_shellWindow_guess EQ_GLOBAL(void*, 0x00923770)

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* destination, unsigned int capacity, const char* text,
                          int arg4_guess, int arg5_guess, int arg6_guess, int arg7_guess,
                          int arg8_guess, int arg9_guess, int arg10_guess, int arg11_guess);

typedef void* (__stdcall *ShellExecuteA_guess)(void*, const char*, const char*, const char*, const char*, int);
#define g_shellExecuteA_guess EQ_GLOBAL(ShellExecuteA_guess, 0x0063F230)

// EXTERNAL: TITANIUM 0x00574860 SkipWhitespace_guess
int __cdecl SkipWhitespace_guess(const char* text, int* length);

// EXTERNAL: TITANIUM 0x005741C0 CharacterWidth_guess
int __cdecl CharacterWidth_guess(const char* text);

// EXTERNAL: TITANIUM 0x0042DF83 FUN_0042df83_guess
void __cdecl FUN_0042df83_guess(int arg1_guess, int arg2_guess, int arg3_guess);

// Copies the next argument of `input` to `output` and returns the rest, both with leading blanks skipped.
// An argument is a word or a '...' / "..." quoted run. Copying stops at 0x12 (the start of an item
// link) and before maxLength - 1 bytes (-1: no limit). CharacterWidth_guess steps whole DBCS characters.
// `input` doubles as the int out-parameter for SkipWhitespace_guess's length.
// FUNCTION: TITANIUM 0x0042DD82
char* __cdecl GrabFirstWord_guess(char* input, char* output, int maxLength) {
    int quote = 0;
    int outputLength = 0;
    char* source = input;

    while (SkipWhitespace_guess(source, (int*)&input) != 0) {
        source += (int)input;
    }

    if (*source == '\'') {
        quote = 1;
        ++source;
    } else if (*source == '"') {
        quote = 2;
        ++source;
    }

    if (*source != 0) {
        for (;;) {
            if ((quote == 1 && *source == '\'') || (quote == 2 && *source == '"')) {
                source += CharacterWidth_guess(source);
                break;
            }
            if (quote == 0 && SkipWhitespace_guess(source, (int*)&input) != 0) {
                source += (int)input;
                break;
            }
            if (*source == 0x12) {
                break;
            }

            int width = CharacterWidth_guess(source);
            if (maxLength != -1 && outputLength + width >= maxLength - 1) {
                break;
            }

            strncpy(output, source, width);
            output += width;
            outputLength += width;
            source += width;
            if (*source == 0) {
                break;
            }
        }
    }

    *output = 0;
    while (SkipWhitespace_guess(source, (int*)&input) != 0) {
        source += (int)input;
    }
    return source;
}

// Prints text to the chat window line by line. A line ends at a real newline, at the two-character
// escape \n, or after 256 characters; a doubled backslash prints one. The character that hits the
// 256 limit is dropped, not carried to the next line.
// FUNCTION: TITANIUM 0x0042DE64
void __cdecl DisplayTextLines_guess(char* input) {
    char buffer[260];
    if (input != 0) {
        char current = *input;
        int length = 0;
        while (current != 0) {
            if (length < 256 && current != '\n') {
                if (current == '\\') {
                    char* next = input + 1;
                    char nextCharacter = *next;
                    if (nextCharacter == 'n') {
                        buffer[length] = 0;
                        g_log_guess->dsp_chat(buffer);
                        input = next;
                        length = 0;
                    } else if (nextCharacter == '\\') {
                        buffer[length] = *next;
                        ++length;
                        input = next;
                    } else {
                        buffer[length] = *input;
                        ++length;
                    }
                } else {
                    buffer[length] = current;
                    ++length;
                }
            } else {
                buffer[length] = 0;
                g_log_guess->dsp_chat(buffer);
                length = 0;
            }
            ++input;
            current = *input;
        }
        buffer[length] = 0;
        if (length > 0) {
            g_log_guess->dsp_chat(buffer);
        }
    }
}

// /fullscreen on|off|toggle: Apply_guess toggles the display mode, so on/off call it only when the
// flag at 0x0099E38C +4 differs (tu_192 reads that byte as IsWindowed_guess; this use says fullscreen).
// FUNCTION: TITANIUM 0x0042E08D
void __cdecl do_fullscreen_guess(void* unused_guess, const char* command) {
    if (command != 0) {
        if (_stricmp_guess(command, "on") == 0) {
            if (g_displayMode_guess->enabled == 0) {
                g_displayMode_guess->Apply_guess();
            }
        } else if (_stricmp_guess(command, "off") == 0) {
            if (g_displayMode_guess->enabled != 0) {
                g_displayMode_guess->Apply_guess();
            }
        } else if (_stricmp_guess(command, "toggle") == 0) {
            g_displayMode_guess->Apply_guess();
        }
    }
}

// /corpse: request 0x1EDC (OP_GMSummon in EQEmu's table) through FUN_0042df83_guess, with string ids
// 0x32F7/0x32F8 for its error messages, probably.
// FUNCTION: TITANIUM 0x0042E0EF
void __cdecl do_corpse_guess() {
    FUN_0042df83_guess(0x1edc, 0x32f7, 0x32f8);
}

// /corpsedrag: the same helper with request 0x50C0 (not in opcodes.h).
// FUNCTION: TITANIUM 0x0042E107
void __cdecl do_corpsedrag_guess() {
    FUN_0042df83_guess(0x50c0, 0x32f7, 0x32f8);
}

// /corpsedrop: OP_CorpseDrop with the target's 64-character name (+0x120), NUL included; an empty
// string when nothing is targeted.
// FUNCTION: TITANIUM 0x0042E11F
void __cdecl do_corpsedrop_guess() {
    char buffer[65];
    if (pinstTarget != 0) {
        strncpy(buffer, pinstTarget->Name, 64);
        buffer[64] = 0;
    } else {
        memset(buffer, 0, 65);
    }
    unsigned int length = strlen(buffer);
    EQSendMessage(&g_message_guess, OP_CorpseDrop, buffer, length + 1, 1);
}

// /resetaas: message 0x460 with no payload (not in opcodes.h).
// FUNCTION: TITANIUM 0x0042E18A
void __cdecl do_resetaas_guess() {
    EQSendMessage(&g_message_guess, 0x460, 0, 0, 1);
}

// /system: runs a program, first argument the file, the rest its parameters. Only with [Defaults]
// EnableSystemCommand=1 in the INI; otherwise, or with no text, prints string 0xFFC.
// FUNCTION: TITANIUM 0x0042E1A3
void __cdecl do_system_guess(void* unused_guess, const char* text) {
    char command[256];
    char buffer[1024];
    // 0xFFD below is the string-table id of the echo line, not a capacity (this file prints 0xFFC-0x1000).
    // 0x0063F53F is ""; 5 is SW_SHOW.
    char enabled = g_log_guess->GetBool_guess("Defaults", "EnableSystemCommand", 0);

    if (*text == 0 || enabled == 0) {
        DisplayTextLines_guess((char*)pStringTable->getString(0xffc, 0));
    } else {
        char* parameters = GrabFirstWord_guess((char*)text, command, 0x100);
        Format_guess(buffer, 0xffd, command, (int)parameters, 0, 0, 0, 0, 0, 0, 0);
        DisplayTextLines_guess(buffer);
        g_shellExecuteA_guess(g_shellWindow_guess, 0, command, parameters, EQ_ARRAY(char, 0x0063F53F), 5);
    }
}

// /url: opens `text` with the shell's "open" verb; with no text, prints string 0x1000.
// FUNCTION: TITANIUM 0x0042E25E
void __cdecl do_url_guess(void* unused_guess, const char* text) {
    char buffer[1024];
    if (*text == 0) {
        DisplayTextLines_guess((char*)pStringTable->getString(0x1000, 0));
    } else {
        Format_guess(buffer, 0xfff, text, 0, 0, 0, 0, 0, 0, 0, 0);
        DisplayTextLines_guess(buffer);
        g_shellExecuteA_guess(g_shellWindow_guess, "open", text, 0, EQ_ARRAY(char, 0x0063F53F), 5);
    }
}

// EXTERNAL: TITANIUM 0x00573AB0 FormatString_00573ab0_guess
CXStr __cdecl FormatString_00573ab0_guess(const char* format, ...);

// /www: opens http://<text> in the default browser; with no text, prints string 0xFFE.
// FUNCTION: TITANIUM 0x0042E2E7
void __cdecl do_www_guess(void* unused_guess, const char* text) {
    char buffer[1024];
    if (*text == 0) {
        DisplayTextLines_guess(pStringTable->getString(0xffe, 0));
    } else {
        CXStr link = FormatString_00573ab0_guess("http://%s", text);
        Format_guess(buffer, 0xfff, link, 0, 0, 0, 0, 0, 0, 0, 0);
        DisplayTextLines_guess(buffer);
        ShellExecuteA((HWND)g_shellWindow_guess, "open", link, 0,
                      EQ_ARRAY(char, 0x0063F53F), 5);
    }
}

// Second entry point to GrabFirstWord_guess.
// FUNCTION: TITANIUM 0x0042E2E2
char* __cdecl GrabFirstWord2_guess(char* input, char* output, int maxLength) {
    return GrabFirstWord_guess(input, output, maxLength);
}

