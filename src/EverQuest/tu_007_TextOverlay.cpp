// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 7: a hint from compare/tumap.py.
// CTextOverlay, the fading text shown in the middle of the screen (MQ2: CTextOverlay::DisplayText at
// 0x40812F; instance 0x79C164), then the help-browser launcher. CTextOverlay_guess is CTextOverlay and
// CXStrView_guess is CXStr.
#include "titanium/eqaddr.h"
#include <windows.h>

struct CXStrRep_guess {
    long refCount;      // +0x00
};

// Atomic increment of a refcount; the result (counter reached zero) is computed but unused by callers.
// as original: `xor ebx,ebx; lock inc [eax]; setz bl; mov [local],ebx` with EBX saved around it is an inline
// asm block; VC7.1 has no intrinsic that emits `lock inc` (_InterlockedIncrement is `lock xadd`).
inline int AtomicIncrement_guess(long* counter) {
    int zero;
    __asm {
        xor ebx, ebx
        mov eax, counter
        lock inc dword ptr [eax]
        setz bl
        mov zero, ebx
    }
    return zero;
}

struct CXStrView_guess {
    CXStrRep_guess* rep;    // +0x00
    // EXTERNAL: TITANIUM 0x00571E00 ??0CXStrView_guess@@QAE@PBD@Z
    CXStrView_guess(const char* text);
    CXStrView_guess(const CXStrView_guess& other);
    // EXTERNAL: TITANIUM 0x00571D00 CXStrView_guess::FreeRep
    void FreeRep(CXStrRep_guess* text);
    ~CXStrView_guess() {
        if (rep != 0) {
            FreeRep(rep);
        }
        rep = 0;
    }
};

// CXStr copy constructor: shares the other string's buffer, raising its reference count.
// FUNCTION: TITANIUM 0x00407D68
CXStrView_guess::CXStrView_guess(const CXStrView_guess& other) {
    if (other.rep != 0) {
        AtomicIncrement_guess(&other.rep->refCount);
    }
    rep = other.rep;
}

struct Service_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(CXStrView_guess* name);
    virtual void Slot02_guess();
    virtual void Slot03_guess(int surface, int* rectA, int* rectB, unsigned int color, int flags, int extra);
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual int Slot13_guess();
};

struct CTextOverlay_guess {
    int value;
    char field04;
    char field05;
    char field06;
    char pad07;
    int field08;
    int fadeInMs_000c_guess;
    int field10;
    int fadeOutMs_0014_guess;
    int holdMs_0018_guess;
    union {
        int color_001c_guess;
        struct {
            char field1C_low[3];
            signed char field1F;
        };
    };
    int priority_0020_guess;
    int maxAlpha_0024_guess;
    CTextOverlay_guess();
    void DisplayText_guess(CXStrView_guess name, int kind, int limit, int v14, int v18, int v1C, int v20);
    void DisplayText(const char* name, int kind, int limit, int v14, int v18, int v1C, int v20);
    void StartFadeOut_guess(int value);
    void Draw_guess();
};

struct GameState_guess {
    char pad000[0x148];
    int field148;
};

// EXTERNAL: TITANIUM 0x0046D655 GetTick_guess
int __cdecl GetTick_guess();
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

#define g_currentObject_guess EQ_GLOBAL(CTextOverlay_guess*, 0x0079C164)
#define g_service_guess EQ_GLOBAL(Service_guess*, 0x0099E360)
#define g_stateSource_guess EQ_GLOBAL(GameState_guess*, 0x00905D24)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x0099E364)
#define g_surface_guess EQ_GLOBAL(int, 0x006945A0)
#define g_viewLeft_guess EQ_GLOBAL(int, 0x00923778)
#define g_viewTop_guess EQ_GLOBAL(int, 0x0092377C)
#define g_viewRight_guess EQ_GLOBAL(int, 0x00923780)
#define g_viewBottom_guess EQ_GLOBAL(int, 0x00923784)
#define g_scaleTop_guess EQ_GLOBAL(float, 0x0063FD2C)
#define g_scaleLeft_guess EQ_GLOBAL(float, 0x0063FD28)
#define g_scaleRight_guess EQ_GLOBAL(float, 0x0063FD24)

// EXTERNAL: TITANIUM 0x0060E590 FindSubstring_guess
char* __cdecl FindSubstring_guess(const char* text, const char* search);
// EXTERNAL: TITANIUM 0x0060E620 CopyLimited_guess
char* __cdecl CopyLimited_guess(char* destination, const char* source, unsigned int count);
// EXTERNAL: TITANIUM 0x0060EA01 Snprintf_guess
int __cdecl Snprintf_guess(char* destination, unsigned int count, const char* format, ...);

struct ProcessFrame_guess {
    STARTUPINFOA startupInfo;
    PROCESS_INFORMATION processInfo;
    char commandLine[512];
    char browserCommand[256];
};

struct Display_guess {
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
    virtual void Slot30_guess(int object);
};

// CTextOverlay::CTextOverlay: becomes the instance and gets its text object from 0x99E360 (slot 13).
// FUNCTION: TITANIUM 0x00407D92
CTextOverlay_guess::CTextOverlay_guess() {
    g_currentObject_guess = this;
    field04 = 0;
    field05 = 0;
    field06 = 0;
    field08 = 0;
    holdMs_0018_guess = 0;
    fadeInMs_000c_guess = 0;
    field10 = 0;
    fadeOutMs_0014_guess = 0;
    priority_0020_guess = 0;
    value = g_service_guess->Slot13_guess();
}

// The overlay instance, created on first use.
// FUNCTION: TITANIUM 0x00407DC9
CTextOverlay_guess* __cdecl GetOrCreateInitObject_guess() {
    CTextOverlay_guess* object = g_currentObject_guess;
    if (object == 0) {
        object = new CTextOverlay_guess;
        g_currentObject_guess = object;
    }
    return object;
}

// Shows `name` in colour `kind` unless a message of higher priority (`limit`, +0x20) is still up. v14 is
// the peak alpha, v18 the fade-in ms, v1C the fade-out ms, v20 the hold ms (0 = until replaced).
// FUNCTION: TITANIUM 0x00407E0C
void CTextOverlay_guess::DisplayText_guess(CXStrView_guess name, int kind, int limit, int v14, int v18, int v1C, int v20) {
    if (field04 != 0 && limit < priority_0020_guess) {
        return;
    }
    ((Service_guess*)value)->Slot01_guess(&name);
    field04 = 1;
    field06 = 1;
    field08 = g_stateSource_guess->field148;
    holdMs_0018_guess = v20;
    fadeInMs_000c_guess = v18;
    fadeOutMs_0014_guess = v1C;
    maxAlpha_0024_guess = v14;
    priority_0020_guess = limit;
    field05 = 0;
    // Chat colour ids to RGB, alpha 0 until drawn: 2 dark green, 4 dark blue, 5 purple, 6 grey,
    // 7 light grey, 0xA white, 0xD red, 0xE green, 0xF yellow, 0x10 blue, 0x12 light blue, 0x14 black.
    switch (kind) {
    case 0xc:
        color_001c_guess = 0xa0a0a0;
        break;
    case 2:
        color_001c_guess = 0x8000;
        break;
    case 4:
        color_001c_guess = 0x80;
        break;
    case 5:
        color_001c_guess = 0xf000f0;
        break;
    case 6:
        color_001c_guess = 0x808080;
        break;
    case 7:
        color_001c_guess = 0xe0e0e0;
        break;
    case 0xa:
        color_001c_guess = 0xf0f0f0;
        break;
    case 0xd:
        color_001c_guess = 0xf00000;
        break;
    case 0xe:
        color_001c_guess = 0xf000;
        break;
    case 0xf:
        color_001c_guess = 0xf0f000;
        break;
    case 0x10:
        color_001c_guess = 0xf0;
        break;
    case 0x12:
        color_001c_guess = 0xf0f0;
        break;
    case 0x14:
        color_001c_guess = 0;
        break;
    default:
        color_001c_guess = 0x606060;
        break;
    }
}

// Starts the fade-out now, lasting `value` ms.
// FUNCTION: TITANIUM 0x00407F46
void CTextOverlay_guess::StartFadeOut_guess(int value) {
    if (field04 != 0) {
        field10 = GetTick_guess();
        holdMs_0018_guess = 0;
        fadeOutMs_0014_guess = value;
        field05 = 1;
    }
}

// Per frame: fades in (CDisplay clock), holds, then fades out (EqGetTime) and hides; draws the text in a
// box half the view wide, from a third of the way down, with font 6.
// FUNCTION: TITANIUM 0x00407F6A
// @early-stop: unknown, diff ndiff=12
void CTextOverlay_guess::Draw_guess() {
    if (field04 == 0) {
        return;
    }
    if ((unsigned int)holdMs_0018_guess > 0 && (unsigned int)(g_stateSource_guess->field148 - field08) > (unsigned int)holdMs_0018_guess) {
        StartFadeOut_guess(fadeOutMs_0014_guess);
    }
    int fade = field1F;
    int limit = maxAlpha_0024_guess;
    unsigned int alpha = (unsigned int)fade;
    if ((color_001c_guess & 0xff000000) == 0xff000000 || (unsigned int)fade > (unsigned int)limit) {
        alpha = (unsigned int)limit;
    }
    if (field05 != 0) {
        unsigned int elapsed = GetTick_guess() - field10;
        if ((unsigned int)fadeOutMs_0014_guess <= elapsed) {
            field05 = 0;
            field04 = 0;
            field06 = 0;
            return;
        }
        alpha = maxAlpha_0024_guess - (int)((float)elapsed / (float)(unsigned int)fadeOutMs_0014_guess * (float)maxAlpha_0024_guess);
    } else if (field06 != 0) {
        unsigned int remaining = (unsigned int)(g_stateSource_guess->field148 - field08);
        if ((unsigned int)fadeInMs_000c_guess <= remaining) {
            alpha = (unsigned int)limit;
            field06 = 0;
        } else {
            alpha = (unsigned int)((float)remaining / (float)(unsigned int)fadeInMs_000c_guess * (float)limit);
        }
    }
    unsigned int color = ((unsigned int)color_001c_guess & 0x00ffffff) | (alpha << 24);
    color_001c_guess = (int)color;
    int width = g_viewRight_guess - g_viewLeft_guess;
    int height = g_viewBottom_guess - g_viewTop_guess;
    // Constants -0.33, -0.25 and -0.5 (0x63FD2C, 0x63FD28, 0x63FD24): top a third down, left a
    // quarter in, width one half.
    int top = g_viewTop_guess - (int)((float)height * g_scaleTop_guess);
    int left = g_viewLeft_guess - (int)((float)width * g_scaleLeft_guess);
    int right = left - (int)((float)width * g_scaleRight_guess);
    int rect1[4] = { left, top, right, g_viewBottom_guess };
    int rect2[4] = { left, top, g_viewRight_guess, g_viewBottom_guess };
    ((Service_guess*)value)->Slot03_guess(g_surface_guess, rect1, rect2, color, 0x10, 0);
    g_display_guess->Slot30_guess(value);
}

// CTextOverlay::DisplayText (MQ2): the char* form of 0x407E0C.
// FUNCTION: TITANIUM 0x0040812F
void CTextOverlay_guess::DisplayText(const char* textMessage, int kind, int limit, int v14, int v18, int v1C, int v20) {
    CXStrView_guess text(textMessage);
    DisplayText_guess(text, kind, limit, v14, v18, v1C, v20);
}

// The default browser's command from HKEY_CLASSES_ROOT\HTTP\shell\open\command, cut after ".exe" (and its
// closing quote); Internet Explorer's path when the key is missing. Always returns true.
// FUNCTION: TITANIUM 0x00408197
bool __cdecl GetBrowserPath_guess(char* command, unsigned long size) {
    HKEY key;
    if (RegOpenKeyExA((HKEY)0x80000000, "HTTP\\shell\\open\\command", 0, 0xF003F, &key) == 0) {
        RegQueryValueExA(key, EQ_ARRAY(char, 0x0063F53F), 0, 0, (LPBYTE)command, &size);
        _strlwr(command);
        char* executable = FindSubstring_guess(command, EQ_ARRAY(char, 0x0063FD60));
        if (executable != 0) {
            executable += 4;
            if (*executable == '"') {
                ++executable;
            }
            *executable = 0;
        }
    } else {
        CopyLimited_guess(command, "c:\\program files\\internet explorer\\iexplore.exe", size);
        command[size - 1] = 0;
    }
    // `key` is never set when RegOpenKeyExA fails, so this tests stack garbage (original bug).
    if (key != 0) {
        RegCloseKey(key);
    }
    return true;
}

// Starts the browser with `arguments` ("%s %s"); true when the process started. The process and thread
// handles are never closed.
// FUNCTION: TITANIUM 0x0040822D
char __cdecl LaunchBrowser_guess(const char* arguments) {
    ProcessFrame_guess frame;
    GetBrowserPath_guess(frame.browserCommand, 0x100);
    GetStartupInfoA(&frame.startupInfo);
    Snprintf_guess(frame.commandLine, 0x200, EQ_ARRAY(char, 0x0063FD80), frame.browserCommand, arguments);
    frame.commandLine[0x1FF] = 0;
    return CreateProcessA(0, frame.commandLine, 0, 0, 0, 0, 0, 0, &frame.startupInfo, &frame.processInfo) != 0;
}

