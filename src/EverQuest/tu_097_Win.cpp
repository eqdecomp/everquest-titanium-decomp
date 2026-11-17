// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 97: a hint from compare/tumap.py.
// Startup and input: WinMain_guess (0x4CFD32) and ExecuteEverQuest_guess (0x4CF93C); eqmain.dll loading,
// DirectInput keyboard and mouse, eqWndProc, the crash report and the code checksums.
// g_keyboardDevice_00988c80_guess / g_mouseDevice_00988c84_guess are the DirectInput keyboard and mouse;
// DirectInputDevice_guess is an IDirectInputDevice8 view (vtable slots by index).
#include <winsock2.h>
#include <windows.h>
#include <objbase.h>
#include "titanium/eqaddr.h"
#include <winsock2.h>
#include <windows.h>
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(int, int, int, const char*);

struct Checker_guess {
    int Check_guess(int value);
    // EXTERNAL: TITANIUM 0x00572A10 Checker_guess::FUN_00572a10_guess
    int FUN_00572a10_guess(int value);
    // EXTERNAL: TITANIUM 0x00572650 Checker_guess::FUN_00572650_guess
    int FUN_00572650_guess(int value);
};

struct CheckerList_guess {
    int count_guess; // +0x00
    int unknown04_guess; // +0x04
    int mask_guess; // +0x08
    int shift_guess; // +0x0c
    int** blocks_guess; // +0x10
    char Check_guess(Checker_guess* checker);
};

struct Data_guess {
    int unknown00_guess; // +0x00
    int unknown04_guess; // +0x04
    int length_guess; // +0x08
    int mode_guess; // +0x0c
    char unknown10_guess[4]; // +0x10
    char bytes_guess[1]; // +0x14
};

struct Reader_guess {
    Data_guess* data_guess; // +0x00
    char Read_guess(int index);
    // EXTERNAL: TITANIUM 0x00571590 Reader_guess::FUN_00571590_guess
    char FUN_00571590_guess(int index);
};

struct DirectInputDevice_guess;
typedef void (__stdcall *DeviceSlotFunction_guess)(DirectInputDevice_guess* self);
typedef int (__stdcall *GetDeviceStateFunction_guess)(DirectInputDevice_guess* self, int size, int* state);
typedef int (__stdcall *GetDeviceDataFunction_guess)(DirectInputDevice_guess* self, int objectSize, void* buffer, int* count, int flags);
typedef int (__stdcall *SetKeyboardDataFormatFunction_guess)(DirectInputDevice_guess*, const void*);
typedef int (__stdcall *SetKeyboardCooperativeLevelFunction_guess)(DirectInputDevice_guess*, void*, unsigned int);
typedef int (__stdcall *SetKeyboardPropertyFunction_guess)(DirectInputDevice_guess*, unsigned int, void*);
typedef int (__stdcall *AcquireKeyboardFunction_guess)(DirectInputDevice_guess*);
typedef int (__stdcall *GetMouseCapabilitiesFunction_guess)(DirectInputDevice_guess*, void*);

// IDirectInputDevice8 vtable, by slot index.
struct DirectInputDeviceVTable_guess {
    void* slots00_guess[2];                                           // QueryInterface, AddRef
    DeviceSlotFunction_guess Release_guess;                           // 2
    GetMouseCapabilitiesFunction_guess GetCapabilities_guess;         // 3
    void* slots10_guess[2];                                           // EnumObjects, GetProperty
    SetKeyboardPropertyFunction_guess SetProperty_guess;              // 6
    AcquireKeyboardFunction_guess Acquire_guess;                      // 7
    DeviceSlotFunction_guess Unacquire_guess;                         // 8
    GetDeviceStateFunction_guess GetDeviceState_guess;                // 9
    GetDeviceDataFunction_guess GetDeviceData_guess;                  // 10
    SetKeyboardDataFormatFunction_guess SetDataFormat_guess;          // 11
    void* slot30_guess;                                               // 12 SetEventNotification
    SetKeyboardCooperativeLevelFunction_guess SetCooperativeLevel_guess; // 13
};

struct DirectInputDevice_guess {
    DirectInputDeviceVTable_guess* vtable_guess;
};

#define g_byte_0098799d_guess EQ_GLOBAL(unsigned char, 0x0098799D)
#define g_byte_00988c1d_guess EQ_GLOBAL(unsigned char, 0x00988C1D)
#define g_byte_00985db8_guess EQ_GLOBAL(unsigned char, 0x00985DB8)
#define g_byte_00985db9_guess EQ_GLOBAL(unsigned char, 0x00985DB9)
#define g_byte_00985dba_guess EQ_GLOBAL(unsigned char, 0x00985DBA)
#define g_byte_00985dbb_guess EQ_GLOBAL(unsigned char, 0x00985DBB)
#define g_byte_00985dbc_guess EQ_GLOBAL(unsigned char, 0x00985DBC)
#define g_byte_00985dbd_guess EQ_GLOBAL(unsigned char, 0x00985DBD)
#define g_byte_00985dbe_guess EQ_GLOBAL(unsigned char, 0x00985DBE)
#define g_byte_00985dbf_guess EQ_GLOBAL(unsigned char, 0x00985DBF)
#define g_byte_00985dc0_guess EQ_GLOBAL(unsigned char, 0x00985DC0)
#define g_byte_00985dc1_guess EQ_GLOBAL(unsigned char, 0x00985DC1)

typedef int (__stdcall *FreeLibraryFunction_guess)(void*);
#define g_module_00988df4_guess EQ_GLOBAL(void*, 0x00988DF4)
#define g_dll_main_009889fc_guess EQ_GLOBAL(int, 0x009889FC)
#define g_new_dll_main_009889a4_guess EQ_GLOBAL(int, 0x009889A4)
#define g_FreeLibrary_0063f190_guess EQ_GLOBAL(FreeLibraryFunction_guess, 0x0063F190)

typedef int (__stdcall *SendMessageAFunction_guess)(void*, unsigned int, unsigned int, int);
#define g_SendMessageA_0063f2d0_guess EQ_GLOBAL(SendMessageAFunction_guess, 0x0063F2D0)
#define g_foregroundWindow_009889bc_guess EQ_GLOBAL(void*, 0x009889BC)
#define pinstCXWndManager_guess EQ_GLOBAL(struct StateManager_guess*, 0x0099D3EC)
#define g_lastState_00988c98_guess EQ_GLOBAL(void*, 0x00988C98)
typedef void* (__stdcall *GetForegroundWindowFunction_guess)();
#define g_GetForegroundWindow_0063f244_guess EQ_GLOBAL(GetForegroundWindowFunction_guess, 0x0063F244)

struct StateManager_guess {
    int unknown00_guess; // +0x00
    unsigned char flag04_guess; // +0x04
    char unknown05_guess[0x12f];
    HCURSOR cursor0134_guess; // +0x134
    char unknown138_guess[0x6fc];
    float scaleX_0834_guess; // +0x834
    float scaleY_0838_guess; // +0x838
    // EXTERNAL: TITANIUM 0x0060A310 StateManager_guess::FUN_0060a310_guess
    void FUN_0060a310_guess();
    // EXTERNAL: TITANIUM 0x005ADF90 StateManager_guess::FUN_005adf90_guess
    void FUN_005adf90_guess();
    // EXTERNAL: TITANIUM 0x005AEF50 StateManager_guess::FUN_005aef50_guess
    unsigned char FUN_005aef50_guess();
    // EXTERNAL: TITANIUM 0x005AFE60 StateManager_guess::FUN_005afe60_guess
    int FUN_005afe60_guess(void* value);
    // EXTERNAL: TITANIUM 0x005B0230 StateManager_guess::FUN_005b0230_guess
    void FUN_005b0230_guess(int* point_guess);
};

struct KeyCombo_guess;

struct Keyboard_guess {
    // EXTERNAL: TITANIUM 0x004B263B Keyboard_guess::HandleKeyUp
    char HandleKeyUp(KeyCombo_guess* key_guess);
};

#define g_state_0099e38c_guess EQ_GLOBAL(StateManager_guess*, 0x0099E38C)
#define g_keyboard_0098599c_guess EQ_GLOBAL(Keyboard_guess*, 0x0098599C)

struct InputState_guess {
    // EXTERNAL: TITANIUM 0x0053CA42 InputState_guess::FUN_0053ca42_guess
    void FUN_0053ca42_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0053F1F4 InputState_guess::FUN_0053f1f4_guess
    void FUN_0053f1f4_guess();
};

#define pinstCOptionsWnd_guess EQ_GLOBAL(InputState_guess*, 0x00850C14)

typedef int (__stdcall *SetCursorPosFunction_guess)(int, int);
typedef void* (__stdcall *SetCursorFunction_guess)(void*);
typedef int (__stdcall *ShowCursorFunction_guess)(int);
#define g_SetCursorPos_0063f240_guess EQ_GLOBAL(SetCursorPosFunction_guess, 0x0063F240)
#define g_SetCursor_0063f258_guess EQ_GLOBAL(SetCursorFunction_guess, 0x0063F258)
#define g_ShowCursor_0063f23c_guess EQ_GLOBAL(ShowCursorFunction_guess, 0x0063F23C)

#define g_keyFlag_00923d2c_guess EQ_GLOBAL(unsigned char, 0x00923D2C)
#define g_keyFlag_00923d2d_guess EQ_GLOBAL(unsigned char, 0x00923D2D)
#define g_keyFlag_00923d2e_guess EQ_GLOBAL(unsigned char, 0x00923D2E)
#define g_keyFlag_00923d2f_guess EQ_GLOBAL(unsigned char, 0x00923D2F)
#define g_keyFlag_00923d30_guess EQ_GLOBAL(unsigned char, 0x00923D30)
#define g_keyFlag_00923d31_guess EQ_GLOBAL(unsigned char, 0x00923D31)
#define g_keyFlag_00923d32_guess EQ_GLOBAL(unsigned char, 0x00923D32)
#define g_keyFlag_00923d33_guess EQ_GLOBAL(unsigned char, 0x00923D33)
#define g_keyFlag_00923d34_guess EQ_GLOBAL(unsigned char, 0x00923D34)
#define g_keyLast_00923d38_guess EQ_GLOBAL(unsigned int, 0x00923D38)

struct KeyCombo_guess {
    int code_guess; // +0x00
    KeyCombo_guess() {}
    KeyCombo_guess(unsigned int code_value_guess) : code_guess((int)code_value_guess) {}
    // EXTERNAL: TITANIUM 0x005BA230 KeyCombo_guess::Set_guess
    void Set_guess(unsigned int key, unsigned char control, unsigned char shift, unsigned char alt);
    // EXTERNAL: TITANIUM 0x005BA300 KeyCombo_guess::Value_guess
    int Value_guess();
    // EXTERNAL: TITANIUM 0x005BA290 KeyCombo_guess::Matches_guess
    int Matches_guess(int record);
};

// EXTERNAL: TITANIUM 0x004917D5 NoteUserActivity_guess
void __cdecl NoteUserActivity_guess();

// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char*, const char*, const char*, char*, int, const char*);

extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

struct NameList_guess {
    int count_guess; // +0x00
    char names_guess[1][0x40]; // +0x04
};

struct NameTable_guess {
    char records_guess[64][0x40];
};

#define g_textTable_009879a0_guess EQ_GLOBAL(NameTable_guess, 0x009879A0)

#define g_mouseDevice_00988c84_guess EQ_GLOBAL(DirectInputDevice_guess*, 0x00988C84)
#define g_keyboardDevice_00988c80_guess EQ_GLOBAL(DirectInputDevice_guess*, 0x00988C80)
#define g_configValue_00988c90_guess EQ_GLOBAL(int, 0x00988C90)
#define g_configValue_00988c94_guess EQ_GLOBAL(int, 0x00988C94)

#define g_configFlag_00850508_guess EQ_GLOBAL(int, 0x00850508)
#define g_configWidthA_00923778_guess EQ_GLOBAL(int, 0x00923778)
#define g_configWidthB_00923780_guess EQ_GLOBAL(int, 0x00923780)
#define g_configHeightA_0092377c_guess EQ_GLOBAL(int, 0x0092377C)
#define g_configHeightB_00923784_guess EQ_GLOBAL(int, 0x00923784)
#define g_configWidth_0092379c_guess EQ_GLOBAL(int, 0x0092379C)
#define g_configHeight_009237a0_guess EQ_GLOBAL(int, 0x009237A0)
#define g_configOutA_009889a8_guess EQ_GLOBAL(int, 0x009889A8)
#define g_configOutB_009889ac_guess EQ_GLOBAL(int, 0x009889AC)
#define g_configOutC_00988c88_guess EQ_GLOBAL(int, 0x00988C88)
#define g_configOutD_00988c8c_guess EQ_GLOBAL(int, 0x00988C8C)
#define g_configOutE_009237c8_guess EQ_GLOBAL(int, 0x009237C8)
#define g_configOutF_009237cc_guess EQ_GLOBAL(int, 0x009237CC)

struct Message_guess {
    void* window_guess;
    unsigned int message_guess;
    unsigned int wParam_guess;
    int lParam_guess;
    unsigned int time_guess;
    int point_guess[2];
};

typedef unsigned int (__stdcall *GetTickCountFunction_guess)();
typedef int (__stdcall *PeekMessageAFunction_guess)(Message_guess*, void*, unsigned int, unsigned int, unsigned int);
typedef int (__stdcall *TranslateMessageFunction_guess)(const Message_guess*);
typedef int (__stdcall *DispatchMessageAFunction_guess)(const Message_guess*);
#define g_GetTickCount_0063f180_guess EQ_GLOBAL(GetTickCountFunction_guess, 0x0063F180)
#define g_PeekMessageA_0063f250_guess EQ_GLOBAL(PeekMessageAFunction_guess, 0x0063F250)
#define g_TranslateMessage_0063f24c_guess EQ_GLOBAL(TranslateMessageFunction_guess, 0x0063F24C)
#define g_DispatchMessageA_0063f248_guess EQ_GLOBAL(DispatchMessageAFunction_guess, 0x0063F248)
#define g_messageState_0099d3f8_guess EQ_GLOBAL(MessageState_guess*, 0x0099D3F8)

struct MessageState_guess {
    // EXTERNAL: TITANIUM 0x005ACFB0 MessageState_guess::FUN_005acfb0_guess
    char FUN_005acfb0_guess();
    // EXTERNAL: TITANIUM 0x005AD310 MessageState_guess::FUN_005ad310_guess
    int FUN_005ad310_guess(unsigned int message_guess, unsigned int wParam_guess, int* lParam_guess);
};

typedef unsigned int (__stdcall *GetLastErrorFunction_guess)();
typedef int (__stdcall *MessageBoxAFunction_guess)(void*, const char*, const char*, unsigned int);
typedef void* (__stdcall *LoadLibraryAFunction_guess)(const char*);
typedef void* (__stdcall *GetProcAddressFunction_guess)(void*, const char*);
#define g_GetLastError_0063f144_guess EQ_GLOBAL(GetLastErrorFunction_guess, 0x0063F144)
#define g_MessageBoxA_0063f2f0_guess EQ_GLOBAL(MessageBoxAFunction_guess, 0x0063F2F0)
#define g_LoadLibraryA_0063f18c_guess EQ_GLOBAL(LoadLibraryAFunction_guess, 0x0063F18C)
#define g_GetProcAddress_0063f188_guess EQ_GLOBAL(GetProcAddressFunction_guess, 0x0063F188)
#define g_errorText_0064c9f4_guess EQ_ARRAY(char, 0x0064C9F4)
#define g_fatalText_0064c9c8_guess EQ_ARRAY(char, 0x0064C9C8)
#define g_fatalCaption_0064c9e8_guess EQ_ARRAY(char, 0x0064C9E8)
#define g_newDllMainText_0064c9b8_guess EQ_ARRAY(char, 0x0064C9B8)
#define g_dllMainText_0064c9ac_guess EQ_ARRAY(char, 0x0064C9AC)
#define g_dllMainErrorText_0064c980_guess EQ_ARRAY(char, 0x0064C980)

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message_guess, ...);

struct KeyboardFile_guess {
    char unknown00_guess[0x0C];
    unsigned char flags_guess; // +0x0C
};

struct KeyboardPart_guess {
    char unknown00_guess[0x1C];
    // EXTERNAL: TITANIUM 0x004482FB KeyboardPart_guess::~KeyboardPart_guess
    ~KeyboardPart_guess();
};

struct KeyboardOwner_guess {
    int unknown00_guess;
    KeyboardPart_guess first_guess;
    KeyboardPart_guess second_guess;
    // EXTERNAL: TITANIUM 0x00445F3F KeyboardOwner_guess::KeyboardOwner_guess
    KeyboardOwner_guess(HINSTANCE instance_guess, HWND window_guess, int value48_guess, CXStr name_guess,
        int value4c_guess, int value38_guess, int value3c_guess, int value40_guess, int value44_guess);
    ~KeyboardOwner_guess();
};

// EXTERNAL: TITANIUM 0x0060E887 fopen
extern "C" KeyboardFile_guess* __cdecl fopen(const char* filename_guess, const char* mode_guess);
// EXTERNAL: TITANIUM 0x006101BA fwrite
extern "C" unsigned int __cdecl fwrite(const void* data_guess, unsigned int size_guess,
    unsigned int count_guess, KeyboardFile_guess* file_guess);
// EXTERNAL: TITANIUM 0x0060E790 fclose
extern "C" int __cdecl fclose(KeyboardFile_guess* file_guess);
// EXTERNAL: TITANIUM 0x00611D51 fread
extern "C" unsigned int __cdecl fread(void* data_guess, unsigned int size_guess,
    unsigned int count_guess, KeyboardFile_guess* file_guess);

// 1 when both checks on `value` (0x00572A10, 0x00572650) return 0, else 0.
// FUNCTION: TITANIUM 0x004CC5FE
int Checker_guess::Check_guess(int value) {
    if (FUN_00572a10_guess(value) == 0 && FUN_00572650_guess(value) == 0) {
        return 1;
    }
    return 0;
}

// CXStr character `index`; 0 past the end or for an empty string (wide strings through 0x00571590).
// FUNCTION: TITANIUM 0x004CC626
// @early-stop: budget, structural ndiff=13
char Reader_guess::Read_guess(int index) {
    char result;
    if (data_guess == 0) {
        result = 0;
    } else {
        if (index >= data_guess->length_guess) {
            result = 0;
        } else {
            if (data_guess->mode_guess == 0) {
                result = data_guess->bytes_guess[index];
            } else {
                result = FUN_00571590_guess(index);
            }
        }
    }
    return result;
}

// Stores the client file name, obfuscated, at 0x985DB8; CheckCriticalFiles_guess decodes it ('P' becomes '.',
// every other byte +0x11) to EQGAME.EXE.
// FUNCTION: TITANIUM 0x004CC662
void __cdecl initializeClientValidationString_guess() {
    g_byte_0098799d_guess = 0x50;
    g_byte_00988c1d_guess = 0x2e;
    g_byte_00985db8_guess = 0x34;
    g_byte_00985db9_guess = 0x40;
    g_byte_00985dba_guess = 0x36;
    g_byte_00985dbb_guess = 0x30;
    g_byte_00985dbc_guess = 0x3c;
    g_byte_00985dbd_guess = 0x34;
    g_byte_00985dbe_guess = 0x50;
    g_byte_00985dbf_guess = 0x34;
    g_byte_00985dc0_guess = 0x47;
    g_byte_00985dc1_guess = 0x34;
}

// Clears the 64-name table at 0x009879A0 (64 bytes per name) and copies the list's names into it.
// FUNCTION: TITANIUM 0x004CC6B7
void __cdecl fillEvilProcessNames_guess(NameList_guess* list_guess) {
    char (*records_guess)[0x40] = g_textTable_009879a0_guess.records_guess;
    int index_guess = 0;
    memset(records_guess, 0, 0x1000);
    if (list_guess != 0 && list_guess->count_guess > 0) {
        do {
            strcpy(records_guess[index_guess], list_guess->names_guess[index_guess]);
            ++index_guess;
        } while (index_guess < list_guess->count_guess);
    }
}

// Asks before sending crash data (6 = Yes) unless the world server name starts with "eqworld-0" (only 9
// of the 10 characters are compared), then sends it.
// FUNCTION: TITANIUM 0x004CC700
void __cdecl CrashDetected(void* connection_guess, unsigned long opcode_guess, void* data_guess,
    unsigned long size_guess, int flag_guess) {
    if (_strnicmp(EQ_ARRAY(char, 0x0098754C), "eqworld-01", 9) != 0) {
        int result_guess = MessageBoxA(0,
                "EverQuest has detected that your client may have crashed.\n\nIt is often possible to determine where and why the crash occurred.\nClick Yes to send this data back to the developers in an effort to help the stability of the game.\n\nThe only personal information that will be sent with the data is the character logged in, the server they were on and the zone they were in at the time.",
                "EverQuest", 0x40004);
        if (result_guess != 6) {
            return;
        }
    }
    EQSendMessage(connection_guess, opcode_guess, data_guess, size_guess, flag_guess);
}

// Dispatches pending window messages for up to `duration_guess` ms. Key messages are translated only while
// the UI takes text (0x5ACFB0), and never for VK_NUMPAD0-9 (0x60-0x69).
// FUNCTION: TITANIUM 0x004CC73F
void __cdecl PumpMessages_guess(unsigned int duration_guess) {
    unsigned int start_guess = GetTickCount();
    MSG message;
    while (PeekMessageA(&message, 0, 0, 0, 1)) {
        if (g_messageState_0099d3f8_guess != 0 && g_messageState_0099d3f8_guess->FUN_005acfb0_guess() != 0 &&
            (message.message == 0x100 || message.message == 0x101 ||
                message.message == 0x104 || message.message == 0x105) &&
            message.wParam != 0x60 && message.wParam != 0x61 &&
            message.wParam != 0x62 && message.wParam != 0x63 &&
            message.wParam != 0x64 && message.wParam != 0x65 &&
            message.wParam != 0x66 && message.wParam != 0x67 &&
            message.wParam != 0x68 && message.wParam != 0x69) {
            TranslateMessage(&message);
        }
        DispatchMessageA(&message);
        if (GetTickCount() - start_guess > duration_guess) {
            break;
        }
    }
}

// Loads eqmain.dll (login and server select) and its entry, new_dll_main, else the older dll_main.
// LoadEQMainDLL in the earlier sibling decomp.
// FUNCTION: TITANIUM 0x004CC7FD
int __cdecl LoadEQMainDLL_guess() {
    g_module_00988df4_guess = g_LoadLibraryA_0063f18c_guess(EQ_ARRAY(char, 0x0064CA20));
    if (g_module_00988df4_guess == 0) {
        unsigned int error_guess = g_GetLastError_0063f144_guess();
        FUN_00574110_guess(g_errorText_0064c9f4_guess, error_guess);
        g_MessageBoxA_0063f2f0_guess((void*)EQ_GLOBAL(void*, 0x00988C24),
            g_fatalText_0064c9c8_guess, g_fatalCaption_0064c9e8_guess, 0);
        return 0;
    }
    GetProcAddressFunction_guess getProcAddress_guess = g_GetProcAddress_0063f188_guess;
    g_new_dll_main_009889a4_guess = (int)getProcAddress_guess(
        g_module_00988df4_guess, g_newDllMainText_0064c9b8_guess);
    if (g_new_dll_main_009889a4_guess == 0) {
        g_dll_main_009889fc_guess = (int)getProcAddress_guess(
            g_module_00988df4_guess, g_dllMainText_0064c9ac_guess);
        if (g_dll_main_009889fc_guess == 0) {
            unsigned int error_guess = g_GetLastError_0063f144_guess();
            FUN_00574110_guess(g_dllMainErrorText_0064c980_guess, error_guess);
            return 0;
        }
    }
    return 1;
}

// Unloads eqmain.dll (FreeLibrary) and forgets its entry points.
// FUNCTION: TITANIUM 0x004CC889
void __cdecl UnloadFrontendDll_guess() {
    if (g_module_00988df4_guess != 0) {
        g_FreeLibrary_0063f190_guess(g_module_00988df4_guess);
        g_module_00988df4_guess = 0;
        g_dll_main_009889fc_guess = 0;
        g_new_dll_main_009889a4_guess = 0;
    }
}

// Reads two 256-byte key tables (0x790128, 0x790228) and, before end of file, a third (0x988CC0); a
// missing file is created from the built-in tables.
// FUNCTION: TITANIUM 0x004CC8AF
void __cdecl LoadKeyboardTables_guess() {
    FUN_00574110_guess("Loading keyboard tables.");
    const char* filename_guess = EQ_ARRAY(char, 0x0064CA2C);
    KeyboardFile_guess* file_guess = fopen(filename_guess, EQ_ARRAY(char, 0x0063FA00));
    if (file_guess == 0) {
        file_guess = fopen(filename_guess, EQ_ARRAY(char, 0x00641B08));
        if (file_guess != 0) {
            fwrite(EQ_ARRAY(char, 0x00790128), 0x100, 1, file_guess);
            fwrite(EQ_ARRAY(char, 0x00790228), 0x100, 1, file_guess);
            fclose(file_guess);
        }
        return;
    }
    fread(EQ_ARRAY(char, 0x00790128), 0x100, 1, file_guess);
    fread(EQ_ARRAY(char, 0x00790228), 0x100, 1, file_guess);
    if ((file_guess->flags_guess & 0x10) == 0) {
        fread(EQ_ARRAY(char, 0x00988CC0), 0x100, 1, file_guess);
    }
    fclose(file_guess);
}

// Destructor: releases the two CXStr members, +0x20 then +4 (0x004482FB).
// FUNCTION: TITANIUM 0x004CC959
KeyboardOwner_guess::~KeyboardOwner_guess() {
}

#define g_timerStart_00988c60_guess EQ_GLOBAL(unsigned __int64, 0x00988C60)

// CPU time-stamp counter minus the count taken at startup (WinMain stores the first reading).
// as original: `rdtsc` into two zeroed EBP-frame locals is an inline asm block; VC7.1 has no __rdtsc intrinsic.
// FUNCTION: TITANIUM 0x004CC98F
unsigned __int64 __cdecl CyclesSinceStart_guess() {
    unsigned long lowPart = 0;
    unsigned long highPart = 0;
    __asm {
        rdtsc
        mov lowPart, eax
        mov highPart, edx
    }
    return (((unsigned __int64)highPart << 32) | lowPart) - g_timerStart_00988c60_guess;
}

typedef void* (__stdcall *GetCurrentProcessFunction_guess)();
typedef int (__stdcall *InitializeAclFunction_guess)(void*, unsigned long, unsigned long);
typedef int (__stdcall *SetSecurityInfoFunction_guess)(void*, unsigned long, unsigned long, void*, void*, void*, void*);

#define g_GetCurrentProcess_0063f194_guess EQ_GLOBAL(GetCurrentProcessFunction_guess, 0x0063F194)
#define g_advapi32_0064ca78_guess EQ_ARRAY(char, 0x0064CA78)
#define g_InitializeAcl_0064ca68_guess EQ_ARRAY(char, 0x0064CA68)
#define g_SetSecurityInfo_0064ca58_guess EQ_ARRAY(char, 0x0064CA58)

// Gives the process an empty DACL (SetSecurityInfo on SE_KERNEL_OBJECT, DACL only), so other processes
// cannot open it; probably an anti-cheat measure.
// FUNCTION: TITANIUM 0x004CC9C2
void __cdecl RestrictProcessAccess_guess() {
    void* module_guess = g_LoadLibraryA_0063f18c_guess(g_advapi32_0064ca78_guess);
    if (module_guess != 0) {
        GetProcAddressFunction_guess getProcAddress_guess = g_GetProcAddress_0063f188_guess;
        InitializeAclFunction_guess initializeAcl_guess = (InitializeAclFunction_guess)
            getProcAddress_guess(module_guess, g_InitializeAcl_0064ca68_guess);
        SetSecurityInfoFunction_guess setSecurityInfo_guess = (SetSecurityInfoFunction_guess)
            getProcAddress_guess(module_guess, g_SetSecurityInfo_0064ca58_guess);
        if (initializeAcl_guess != 0 && setSecurityInfo_guess != 0) {
            int acl_guess[2];
            initializeAcl_guess(acl_guess, 8, 2);
            setSecurityInfo_guess(g_GetCurrentProcess_0063f194_guess(), 6, 4, 0, 0, acl_guess, 0);
        }
    }
}

struct ClearState_guess {
    int mode_guess;                                // 0x009237DC
    char pad_004_guess[0x00923840 - 0x009237DC - 4];
    unsigned char flag_guess;                      // 0x00923840
    char pad_065_guess[0x00925520 - 0x00923840 - 1];
    unsigned int table_guess[0x100];               // 0x00925520
};

#define g_clearState_guess EQ_GLOBAL(ClearState_guess, 0x009237DC)

// Startup reset: 0x009237DC = 4, the flag at 0x00923840 cleared and the 256 dwords at 0x00925520
// zeroed.
// FUNCTION: TITANIUM 0x004CCA22
void __cdecl FUN_004cca22_guess() {
    g_clearState_guess.mode_guess = 4;
    g_clearState_guess.flag_guess = 0;
    for (int i_guess = 0; i_guess < 0x100; ++i_guess) {
        g_clearState_guess.table_guess[i_guess] = 0;
    }
}

#define g_table_00790540_guess EQ_ARRAY(unsigned int, 0x00790540)
#define g_table_00790940_guess EQ_ARRAY(unsigned int, 0x00790940)

// CRC-32 that feeds the four seed bytes first; Crc32WithTableB_guess differs only in its table (0x790940).
// FUNCTION: TITANIUM 0x004CCA44
unsigned int __cdecl MemChecker2(const unsigned char* data_guess, int length_guess, unsigned int seed_guess) {
    const unsigned char* seedBytes_guess = (const unsigned char*)&seed_guess;
    int hash_guess = (int)(g_table_00790540_guess[(~seedBytes_guess[0]) & 0xff] ^ 0xffffff);
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790540_guess[(seedBytes_guess[1] ^ hash_guess) & 0xff];
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790540_guess[(seedBytes_guess[2] ^ hash_guess) & 0xff];
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790540_guess[(seedBytes_guess[3] ^ hash_guess) & 0xff];
    const unsigned char* end_guess = data_guess + length_guess;
    for (; data_guess < end_guess; ++data_guess) {
        hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790540_guess[(*data_guess ^ hash_guess) & 0xff];
    }
    return ~hash_guess;
}

// CRC-32 (table at 0x00790940) over the four bytes of `seed_guess` and then `data_guess`; the checker's
// hash of a memory range.
// FUNCTION: TITANIUM 0x004CCAD1
unsigned int __cdecl MemChecker3(const unsigned char* data_guess, int length_guess, unsigned int seed_guess) {
    const unsigned char* seedBytes_guess = (const unsigned char*)&seed_guess;
    int hash_guess = (int)(g_table_00790940_guess[(~seedBytes_guess[0]) & 0xff] ^ 0xffffff);
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790940_guess[(seedBytes_guess[1] ^ hash_guess) & 0xff];
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790940_guess[(seedBytes_guess[2] ^ hash_guess) & 0xff];
    hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790940_guess[(seedBytes_guess[3] ^ hash_guess) & 0xff];
    const unsigned char* end_guess = data_guess + length_guess;
    for (; data_guess < end_guess; ++data_guess) {
        hash_guess = ((hash_guess >> 8) & 0xffffff) ^ g_table_00790940_guess[(*data_guess ^ hash_guess) & 0xff];
    }
    return ~hash_guess;
}

// WM_SYSCOMMAND SC_MAXIMIZE (0xF030) or SC_RESTORE (0xF120) to the main window.
// FUNCTION: TITANIUM 0x004CCB5E
void __cdecl MaximizeOrRestoreWindow_guess(char param_1) {
    if (param_1 != 0) {
        g_SendMessageA_0063f2d0_guess((void*)EQ_GLOBAL(void*, 0x00988C24), 0x112, 0xF030, 0);
    } else {
        g_SendMessageA_0063f2d0_guess((void*)EQ_GLOBAL(void*, 0x00988C24), 0x112, 0xF120, 0);
    }
}

// Drains up to 32 buffered keyboard events (GetDeviceData) and clears every modifier flag.
// FUNCTION: TITANIUM 0x004CCB85
int __cdecl FlushKeyboard_guess() {
    int buffer_guess[160];
    int size_guess = 0x20;
    g_keyboardDevice_00988c80_guess->vtable_guess->GetDeviceData_guess(
        g_keyboardDevice_00988c80_guess, 0x14, buffer_guess, &size_guess, 0);
    StateManager_guess* state_guess = pinstCXWndManager_guess;
    EQ_GLOBAL(unsigned char, 0x00923D2C) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2D) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2E) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D2F) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D30) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D31) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D32) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D33) = 0;
    EQ_GLOBAL(unsigned char, 0x00923D34) = 0;
    if (state_guess != 0) {
        state_guess->FUN_005adf90_guess();
    }
    return size_guess;
}

// Key release (DirectInput scan code): updates the left/right Shift, Ctrl and Alt flags and passes the
// combo to the key manager (0x98599C). A Right Shift release is ignored while VK_RSHIFT still reads down.
// The combo's modifiers go in the order Shift, Ctrl, Alt (scan codes 0x2A/0x36, 0x1D/0x9D, 0x38/0xB8),
// not the control, shift, alt of KeyCombo_guess::Set_guess's parameter names.
// FUNCTION: TITANIUM 0x004CCBFC
// @early-stop: budget, structural ndiff=28
char __cdecl HandleKeyUp_guess(KeyCombo_guess key_guess) {
    unsigned int keyValue_guess = (unsigned int)key_guess.code_guess;
    if ((unsigned char)keyValue_guess == 0x36 &&
        GetAsyncKeyState(0xA1) < 0) {
        return 0;
    }
    switch ((unsigned char)keyValue_guess) {
    case 0xB8:
        g_keyFlag_00923d34_guess = 0;
        break;
    case 0x9D:
        g_keyFlag_00923d33_guess = 0;
        break;
    case 0x38:
        g_keyFlag_00923d31_guess = 0;
        break;
    case 0x36:
        g_keyFlag_00923d32_guess = 0;
        break;
    case 0x2A:
        g_keyFlag_00923d2f_guess = 0;
        break;
    case 0x1D:
        g_keyFlag_00923d30_guess = 0;
        break;
    }
    if (g_keyFlag_00923d2f_guess != 0 ||
        (g_keyFlag_00923d2c_guess = 0, g_keyFlag_00923d32_guess != 0)) {
        g_keyFlag_00923d2c_guess = 1;
    }
    if (g_keyFlag_00923d30_guess != 0 ||
        (g_keyFlag_00923d2d_guess = 0, g_keyFlag_00923d33_guess != 0)) {
        g_keyFlag_00923d2d_guess = 1;
    }
    if (g_keyFlag_00923d31_guess != 0 ||
        (g_keyFlag_00923d2e_guess = 0, g_keyFlag_00923d34_guess != 0)) {
        g_keyFlag_00923d2e_guess = 1;
    }
    key_guess.Set_guess(keyValue_guess, g_keyFlag_00923d2c_guess,
        g_keyFlag_00923d2d_guess, g_keyFlag_00923d2e_guess);
    char result_guess = g_keyboard_0098599c_guess->HandleKeyUp(&key_guess);
    NoteUserActivity_guess();
    return result_guess;
}

// Passes the mouse wheel delta to the UI while EQ is the foreground window.
// FUNCTION: TITANIUM 0x004CCD03
void __cdecl HandleMouseWheel_guess(void* param_1) {
    if (g_GetForegroundWindow_0063f244_guess() == g_foregroundWindow_009889bc_guess &&
        pinstCXWndManager_guess != 0 &&
        pinstCXWndManager_guess->FUN_005afe60_guess(param_1) != 0) {
        g_lastState_00988c98_guess = param_1;
    }
}

struct KeyManager_guess {
    // EXTERNAL: TITANIUM 0x004B244F KeyManager_guess::First_guess
    int First_guess(int code);
    // EXTERNAL: TITANIUM 0x004B2459 KeyManager_guess::Second_guess
    int Second_guess(int code);
    // EXTERNAL: TITANIUM 0x004B23C4 KeyManager_guess::HandleKeyDown
    char HandleKeyDown(KeyCombo_guess* combo);
};

// 8-byte records at 0x00790D40: code dword at +0, control/shift/alt bytes at +4/+5/+6
#define g_keyTable_guess EQ_ARRAY(unsigned char, 0x00790D40)
#define g_keyManager_guess EQ_GLOBAL(KeyManager_guess*, 0x0098599C)

// Six commands (8-byte records at 0x790D40) also fire with extra modifiers held: each record says which
// of Shift, Ctrl and Alt to ignore. True when one fired.
// FUNCTION: TITANIUM 0x004CCD32
char __cdecl FireModifierTolerantCommands_guess(unsigned int key_guess) {
    char result_guess = 0;
    KeyCombo_guess base_guess;
    base_guess.Set_guess(key_guess, g_keyFlag_00923d2c_guess, g_keyFlag_00923d2d_guess,
        g_keyFlag_00923d2e_guess);
    for (unsigned int offset_guess = 0; offset_guess < 0x30; offset_guess += 8) {
        unsigned char control_guess;
        if (g_keyFlag_00923d2c_guess == 0 || (control_guess = 1, g_keyTable_guess[offset_guess + 4] != 0)) {
            control_guess = 0;
        }
        unsigned char shift_guess;
        if (g_keyFlag_00923d2d_guess == 0 || (shift_guess = 1, g_keyTable_guess[offset_guess + 5] != 0)) {
            shift_guess = 0;
        }
        unsigned char alt_guess;
        if (g_keyFlag_00923d2e_guess == 0 || (alt_guess = 1, g_keyTable_guess[offset_guess + 6] != 0)) {
            alt_guess = 0;
        }
        KeyCombo_guess combo_guess;
        combo_guess.Set_guess(key_guess, control_guess, shift_guess, alt_guess);
        int* code_guess = (int*)&g_keyTable_guess[offset_guess];
        int first_guess = g_keyManager_guess->First_guess(*code_guess);
        int second_guess = g_keyManager_guess->Second_guess(*code_guess);
        if (combo_guess.Value_guess() != base_guess.Value_guess()) {
            if (combo_guess.Matches_guess(first_guess) || combo_guess.Matches_guess(second_guess)) {
                g_keyManager_guess->HandleKeyDown(&combo_guess);
                result_guess = 1;
            }
        }
    }
    return result_guess;
}

struct CleanupModeObject_guess {
    char unknown0000_guess[0xB54];
    int mode_guess; // +0xB54
};

#define g_cleanupModeObject_00988df0_guess EQ_GLOBAL(CleanupModeObject_guess*, 0x00988DF0)
#define g_configFlags_009889b4_guess EQ_GLOBAL(unsigned int, 0x009889B4)
#define g_configFlagA_00923876_guess EQ_GLOBAL(unsigned char, 0x00923876)
#define g_configFlagB_00923877_guess EQ_GLOBAL(unsigned char, 0x00923877)
#define g_configFlagC_00923878_guess EQ_GLOBAL(unsigned char, 0x00923878)
#define g_configActive_00988c28_guess EQ_GLOBAL(int, 0x00988C28)
#define g_mouseWheelDelta_guess EQ_GLOBAL(void*, 0x009889B0)
#define g_configScale_009237e0_guess EQ_GLOBAL(int, 0x009237E0)

// Reads the mouse; 7 when GetDeviceData fails. lX/lY (0x9889A8/AC, times the speed 0x9237E0 above 1) move
// the cursor (0x988C88/8C) within the screen; lZ (0x9889B0) is the wheel, in game states 1, 2 and 5.
// 0x923876/0x923877 get the left and right buttons, swapped when 0x923878 is set.
// FUNCTION: TITANIUM 0x004CCE44
// @early-stop: budget, diff ndiff=10
int __cdecl ProcessMouseEvents_guess() {
    int buffer_guess[640];
    int size_guess = 0x80;
    g_configValue_00988c90_guess = 0;
    g_configValue_00988c94_guess = 0;
    g_lastState_00988c98_guess = 0;
    if (g_mouseDevice_00988c84_guess->vtable_guess->GetDeviceData_guess(
            g_mouseDevice_00988c84_guess, 0x14, buffer_guess, &size_guess, 0) < 0) {
        return 7;
    }
    if (g_mouseDevice_00988c84_guess->vtable_guess->GetDeviceState_guess(
            g_mouseDevice_00988c84_guess, 0x10, &g_configOutA_009889a8_guess) == 0) {
        unsigned int flags_guess = g_configFlags_009889b4_guess;
        unsigned char lowFlags_guess = (unsigned char)flags_guess;
        unsigned char highFlags_guess = (unsigned char)(flags_guess >> 8);
        g_configFlagA_00923876_guess = highFlags_guess & 0x80;
        g_configValue_00988c90_guess += g_configOutA_009889a8_guess;
        g_configValue_00988c94_guess += g_configOutB_009889ac_guess;
        g_configFlagB_00923877_guess = lowFlags_guess & 0x80;
        if (g_configActive_00988c28_guess != 0 &&
            (g_cleanupModeObject_00988df0_guess->mode_guess == 5 ||
             g_cleanupModeObject_00988df0_guess->mode_guess == 2 ||
             g_cleanupModeObject_00988df0_guess->mode_guess == 1) &&
            g_mouseWheelDelta_guess != 0) {
            HandleMouseWheel_guess(g_mouseWheelDelta_guess);
            NoteUserActivity_guess();
        }
    }
    if (g_configValue_00988c90_guess != 0 || g_configValue_00988c94_guess != 0) {
        if (g_configScale_009237e0_guess > 1) {
            g_configOutC_00988c88_guess += g_configValue_00988c90_guess * g_configScale_009237e0_guess;
            g_configOutD_00988c8c_guess += g_configValue_00988c94_guess * g_configScale_009237e0_guess;
        } else {
            g_configOutC_00988c88_guess += g_configValue_00988c90_guess;
            g_configOutD_00988c8c_guess += g_configValue_00988c94_guess;
        }
        if (g_configOutC_00988c88_guess < 0) {
            g_configOutC_00988c88_guess = 0;
        }
        if (g_configOutD_00988c8c_guess < 0) {
            g_configOutD_00988c8c_guess = 0;
        }
        if (g_configOutC_00988c88_guess > g_configWidth_0092379c_guess - 1) {
            g_configOutC_00988c88_guess = g_configWidth_0092379c_guess - 1;
        }
        if (g_configOutD_00988c8c_guess > g_configHeight_009237a0_guess - 1) {
            g_configOutD_00988c8c_guess = g_configHeight_009237a0_guess - 1;
        }
        NoteUserActivity_guess();
    }
    if (g_configFlagC_00923878_guess == 0) {
        unsigned char oldFlag_guess = g_configFlagA_00923876_guess;
        g_configFlagA_00923876_guess = g_configFlagB_00923877_guess;
        g_configFlagB_00923877_guess = oldFlag_guess;
    }
    return size_guess;
}

// Drains buffered mouse events; 1 on success, 7 on failure.
// FUNCTION: TITANIUM 0x004CCFB7
int __cdecl FlushMouse_guess() {
    int buffer[640];
    int size = 0x80;
    g_configValue_00988c90_guess = 0;
    g_configValue_00988c94_guess = 0;
    int result = g_mouseDevice_00988c84_guess->vtable_guess->GetDeviceData_guess(g_mouseDevice_00988c84_guess, 0x14, buffer, &size, 0);
    return ((result >= 0) - 1U & 6U) + 1U;
}

// Cursor to the screen centre, or to the window's centre when 0x850508 is 1 (windowed, probably).
// FUNCTION: TITANIUM 0x004CCFFE
void __cdecl CenterMouse_guess() {
    int first;
    int second;
    if (g_configFlag_00850508_guess == 1) {
        first = (g_configWidthA_00923778_guess + g_configWidthB_00923780_guess) / 2;
        second = (g_configHeightA_0092377c_guess + g_configHeightB_00923784_guess) / 2;
    } else {
        first = g_configWidth_0092379c_guess / 2;
        second = g_configHeight_009237a0_guess / 2;
    }
    g_configOutA_009889a8_guess = first;
    g_configOutC_00988c88_guess = first;
    g_configOutB_009889ac_guess = second;
    g_configOutD_00988c8c_guess = second;
    g_configOutE_009237c8_guess = first;
    g_configOutF_009237cc_guess = second;
}

// Releases the DirectInput mouse device (unacquire, then release) and clears its pointer.
// FUNCTION: TITANIUM 0x004CD060
void __cdecl ReleaseMouse_guess() {
    if (g_mouseDevice_00988c84_guess != 0) {
        g_mouseDevice_00988c84_guess->vtable_guess->Unacquire_guess(g_mouseDevice_00988c84_guess);
        g_mouseDevice_00988c84_guess->vtable_guess->Release_guess(g_mouseDevice_00988c84_guess);
        g_mouseDevice_00988c84_guess = 0;
    }
}

struct DirectInput_guess;
typedef int (__stdcall *CreateKeyboardDeviceFunction_guess)(DirectInput_guess*, const void*, DirectInputDevice_guess**, void*);

struct DirectInputVTable_guess {
    void* slots00_guess[3];
    CreateKeyboardDeviceFunction_guess CreateDevice_guess;
};

struct DirectInput_guess {
    DirectInputVTable_guess* vtable_guess;
};

struct KeyboardProperty_guess {
    unsigned int size_guess;
    unsigned int header_guess;
    unsigned int object_guess;
    unsigned int how_guess;
    unsigned int value_guess;
};

#define g_directInput_00988c7c_guess EQ_GLOBAL(DirectInput_guess*, 0x00988C7C)
#define g_keyboardProperty_00988c34_guess EQ_GLOBAL(KeyboardProperty_guess, 0x00988C34)

// Creates the DirectInput keyboard: non-exclusive foreground (6), a 32-event buffer. Returns 0 or the
// step that failed (1-5). A failed Acquire is retried once; that double call is the original.
// FUNCTION: TITANIUM 0x004CD082
int __cdecl InitKeyboard_guess(void* window_guess) {
    FUN_00574110_guess("Initializing Keyboard.");
    if (g_directInput_00988c7c_guess == 0) {
        FUN_00574110_guess("DirectInputCreate has not been created!\n");
        return 1;
    }
    g_keyFlag_00923d2c_guess = 0;
    g_keyFlag_00923d2d_guess = 0;
    g_keyFlag_00923d2e_guess = 0;
    g_keyFlag_00923d2f_guess = 0;
    g_keyFlag_00923d30_guess = 0;
    g_keyFlag_00923d31_guess = 0;
    g_keyFlag_00923d32_guess = 0;
    g_keyFlag_00923d33_guess = 0;
    g_keyFlag_00923d34_guess = 0;
    if (g_directInput_00988c7c_guess->vtable_guess->CreateDevice_guess(
        g_directInput_00988c7c_guess, EQ_ARRAY(char, 0x006638B0),
        &g_keyboardDevice_00988c80_guess, 0) < 0) {
        FUN_00574110_guess("Failed to CreateDevice for keyboard!\n");
        return 2;
    }
    if (g_keyboardDevice_00988c80_guess->vtable_guess->SetDataFormat_guess(
        g_keyboardDevice_00988c80_guess, EQ_ARRAY(char, 0x006611DC)) < 0) {
        FUN_00574110_guess("Failed to SetDataFormat for keyboard!\n");
        return 3;
    }
    int cooperativeResult_guess = g_keyboardDevice_00988c80_guess->vtable_guess->SetCooperativeLevel_guess(
        g_keyboardDevice_00988c80_guess, window_guess, 6);
    DWORD lastError_guess = GetLastError();
    if (cooperativeResult_guess < 0) {
        FUN_00574110_guess("Failed to SetCooperativeLevel for keyboard! (%d, %d)\n",
            cooperativeResult_guess, lastError_guess);
        return 4;
    }
    KeyboardProperty_guess* property_guess = &g_keyboardProperty_00988c34_guess;
    memset(property_guess, 0, 0x14);
    property_guess->size_guess = 0x14;
    property_guess->header_guess = 0x10;
    property_guess->object_guess = 0;
    property_guess->how_guess = 0;
    property_guess->value_guess = 0x20;
    if (g_keyboardDevice_00988c80_guess->vtable_guess->SetProperty_guess(
        g_keyboardDevice_00988c80_guess, 1, property_guess) < 0) {
        FUN_00574110_guess("Failed to SetProperty for keyboard!\n");
        return 5;
    }
    if (g_keyboardDevice_00988c80_guess == 0 ||
        g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess) == 0 ||
        g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess) >= 0) {
        return 0;
    }
    FUN_00574110_guess("Failed to Acquire keyboard!\n");
    return 1;
}

// Releases the DirectInput keyboard device (unacquire, then release) and clears its pointer.
// FUNCTION: TITANIUM 0x004CD1EF
void __cdecl ReleaseKeyboard_guess() {
    if (g_keyboardDevice_00988c80_guess != 0) {
        g_keyboardDevice_00988c80_guess->vtable_guess->Unacquire_guess(g_keyboardDevice_00988c80_guess);
        g_keyboardDevice_00988c80_guess->vtable_guess->Release_guess(g_keyboardDevice_00988c80_guess);
        g_keyboardDevice_00988c80_guess = 0;
    }
}

// Table-B twin of ChecksumCodeRangesA_guess; tu_042 calls it.
// FUNCTION: TITANIUM 0x004CD211
unsigned int __cdecl ChecksumCodeRangesB_guess(unsigned int seed_guess) {
    return MemChecker3(EQ_ARRAY(unsigned char, 0x0048F7A8),
        EQ_ARRAY(unsigned char, 0x004905E7) - EQ_ARRAY(unsigned char, 0x0048F7A8), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x00464948),
        EQ_ARRAY(unsigned char, 0x0046D5FB) - EQ_ARRAY(unsigned char, 0x00464948), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x00479370),
        EQ_ARRAY(unsigned char, 0x0047C2EF) - EQ_ARRAY(unsigned char, 0x00479370), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x004BAADF),
        EQ_ARRAY(unsigned char, 0x004BB051) - EQ_ARRAY(unsigned char, 0x004BAADF), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x0040D8D4),
        EQ_ARRAY(unsigned char, 0x0040E250) - EQ_ARRAY(unsigned char, 0x0040D8D4), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x0040CBF4),
        EQ_ARRAY(unsigned char, 0x0040CC00) - EQ_ARRAY(unsigned char, 0x0040CBF4), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x00416823),
        EQ_ARRAY(unsigned char, 0x00417C90) - EQ_ARRAY(unsigned char, 0x00416823), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x00491119),
        EQ_ARRAY(unsigned char, 0x004952AA) - EQ_ARRAY(unsigned char, 0x00491119), seed_guess) ^
        MemChecker3(EQ_ARRAY(unsigned char, 0x004CC656),
        EQ_ARRAY(unsigned char, 0x004CD46D) - EQ_ARRAY(unsigned char, 0x004CC656), seed_guess) ^ ~seed_guess;
}

// XOR of seeded CRCs over nine code ranges (among them this file's 0x4CC656-0x4CD46D and tu_053's
// 0x479370-0x47C2EF), probably so the server can spot patched code (WriteChecksumFile_guess).
// FUNCTION: TITANIUM 0x004CD2EC
unsigned int __cdecl ChecksumCodeRangesA_guess(unsigned int seed_guess) {
    return MemChecker2(EQ_ARRAY(unsigned char, 0x0048F7A8),
        EQ_ARRAY(unsigned char, 0x004905E7) - EQ_ARRAY(unsigned char, 0x0048F7A8), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x00464948),
        EQ_ARRAY(unsigned char, 0x0046D5FB) - EQ_ARRAY(unsigned char, 0x00464948), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x00479370),
        EQ_ARRAY(unsigned char, 0x0047C2EF) - EQ_ARRAY(unsigned char, 0x00479370), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x004BAADF),
        EQ_ARRAY(unsigned char, 0x004BB051) - EQ_ARRAY(unsigned char, 0x004BAADF), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x0040D8D4),
        EQ_ARRAY(unsigned char, 0x0040E250) - EQ_ARRAY(unsigned char, 0x0040D8D4), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x0040CBF4),
        EQ_ARRAY(unsigned char, 0x0040CC00) - EQ_ARRAY(unsigned char, 0x0040CBF4), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x00416823),
        EQ_ARRAY(unsigned char, 0x00417C90) - EQ_ARRAY(unsigned char, 0x00416823), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x00491119),
        EQ_ARRAY(unsigned char, 0x004952AA) - EQ_ARRAY(unsigned char, 0x00491119), seed_guess) ^
        MemChecker2(EQ_ARRAY(unsigned char, 0x004CC656),
        EQ_ARRAY(unsigned char, 0x004CD46D) - EQ_ARRAY(unsigned char, 0x004CC656), seed_guess) ^ ~seed_guess;
}

// Boolean from eqclient.ini: T, t or 1 is true; a missing key gets `param_3` written as its default.
// FUNCTION: TITANIUM 0x004CD3C7
int __cdecl ReadIniBool_guess(const char* param_1, const char* param_2, const char* param_3) {
    char value_guess[256];
    int result_guess = 0;
    FUN_0060be50_guess(param_1, param_2, "*NULL*", value_guess, 0x20, ".\\eqclient.ini");
    if (value_guess[0] == '*') {
        if (param_3 != 0) {
            if (*param_3 == 'T' || *param_3 == 't' || *param_3 == '1') {
                result_guess = 1;
            }
            FUN_0060beb0_guess((int)param_1, (int)param_2, (int)param_3, ".\\eqclient.ini");
        }
    } else if (value_guess[0] == 'T' || value_guess[0] == 't' || value_guess[0] == '1') {
        result_guess = 1;
    } else {
        result_guess = 0;
    }
    return result_guess;
}

// Writes string `third` to eqclient.ini, section `first`, key `second`.
// FUNCTION: TITANIUM 0x004CD453
void __cdecl WriteIniString_guess(int first, int second, int third) {
    FUN_0060beb0_guess(first, second, third, ".\\eqclient.ini");
}

// Re-acquires the mouse, parks the cursor at (10, 10) in full screen when `param_1`, and shows it.
// FUNCTION: TITANIUM 0x004CD479
void __cdecl AcquireMouse_guess(char param_1) {
    g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(g_mouseDevice_00988c84_guess);
    if (g_state_0099e38c_guess->flag04_guess != 0 && param_1 != 0) {
        g_SetCursorPos_0063f240_guess(10, 10);
    }
    g_SetCursor_0063f258_guess(pinstCXWndManager_guess->cursor0134_guess);
    int showCursor_guess;
    do {
        showCursor_guess = g_ShowCursor_0063f23c_guess(1);
    } while (showCursor_guess < 0);
}

// 1 (full screen) only when [Defaults] WindowedMode in eqclient.ini starts with F, f or 0; a missing key
// or any other value means windowed.
// FUNCTION: TITANIUM 0x004CD4BE
char __cdecl IsFullScreen_guess() {
    char windowedMode_guess[8];
    FUN_0060be50_guess("Defaults", "WindowedMode", "*NULL*", windowedMode_guess, 6, ".\\eqclient.ini");
    if (windowedMode_guess[0] == 'F' || windowedMode_guess[0] == 'f' || windowedMode_guess[0] == '0') {
        return 1;
    }
    return 0;
}

struct OsVersionInfoExA_guess {
    unsigned int size_guess; // +0x00
    unsigned int major_guess; // +0x04
    unsigned int minor_guess; // +0x08
    unsigned int build_guess; // +0x0c
    unsigned int platform_guess; // +0x10
    char servicePack_guess[128]; // +0x14
    unsigned short servicePackMajor_guess; // +0x94
    unsigned short servicePackMinor_guess; // +0x96
    unsigned short suiteMask_guess; // +0x98
    unsigned char productType_guess; // +0x9a
    unsigned char reserved_guess; // +0x9b
};

typedef int (__stdcall *GetVersionExAFunction_guess)(OsVersionInfoExA_guess*);

// Cursor position; in windowed mode in client coordinates, scaled to the render size (+0x834, +0x838).
// FUNCTION: TITANIUM 0x004CD510
unsigned __int64 __cdecl GetMouseClientPos_guess() {
    POINT point_guess;
    GetCursorPos(&point_guess);
    if (g_state_0099e38c_guess->flag04_guess == 0) {
        ScreenToClient(GetForegroundWindow(), &point_guess);
        point_guess.x = (LONG)(point_guess.x * g_state_0099e38c_guess->scaleX_0834_guess);
        point_guess.y = (LONG)(point_guess.y * g_state_0099e38c_guess->scaleY_0838_guess);
    }
    return *(unsigned __int64*)&point_guess;
}

// 0 for Windows XP (NT 5.1); 1 for Win32s, 95/98/ME, NT 4 and older, 2000 and 2003; 2 for anything newer
// or when GetVersionExA fails. InitMouse_guess takes the mouse exclusively only on XP.
// FUNCTION: TITANIUM 0x004CD56D
int __cdecl CheckOSVersion_guess() {
    OsVersionInfoExA_guess version_guess;
    unsigned int versionSize_guess = 0x9c;
    memset(&version_guess, 0, versionSize_guess);
    version_guess.size_guess = versionSize_guess;
    unsigned int getVersionExAAddress_guess = EQ_GLOBAL(unsigned int, 0x0063F130);
    GetVersionExAFunction_guess getVersionExA_guess = (GetVersionExAFunction_guess)getVersionExAAddress_guess;
    if (getVersionExA_guess(&version_guess) == 0) {
        version_guess.size_guess = 0x94;
        if (getVersionExA_guess(&version_guess) == 0) {
            return 2;
        }
    }
    switch (version_guess.platform_guess) {
    case 0:
        return 1;
    case 1:
        if (version_guess.major_guess == 4) {
            if (version_guess.minor_guess == 0) return 1;
            if (version_guess.minor_guess == 10) return 1;
            if (version_guess.minor_guess == 0x5a) return 1;
        }
        break;
    case 2:
        if (version_guess.major_guess == 5) {
            if (version_guess.minor_guess == 2) return 1;
            if (version_guess.minor_guess == 1) {
                return 0;
            }
            if (version_guess.minor_guess == 0) return 1;
        } else if (version_guess.major_guess <= 4) {
            return 1;
        }
        break;
    }
    return 2;
}

struct CrashOffsetSource_guess {
    int unknown00_guess;
    int dataOffset_guess; // +0x04
};

struct CrashContextSource_guess {
    int unknown00_guess[2];
    CrashOffsetSource_guess* offsetSource_guess; // +0x08
};

struct CrashReportData_guess {
    char unknown00_guess[0x44];
    char playerName_guess[0x40]; // +0x44
    char unknown84_guess[0x84];
    int zoneId_guess; // +0x108
};

struct WorldData_guess {
    // EXTERNAL: TITANIUM 0x005F6ED0 WorldData_guess::FUN_005f6ed0_guess
    void FUN_005f6ed0_guess(int zoneId_guess, char* zoneName_guess);
};

struct RawStackScratch_guess {
    int lineCount_guess;
    unsigned char* byteAddress_guess;
};

#define g_savedContext_00989258_guess EQ_GLOBAL(CONTEXT, 0x00989258)

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060D970 strlen
extern "C" unsigned int __cdecl strlen(const char* text_guess);
// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* destination_guess, const char* source_guess);

// Crash text for an exception, into `report_guess` and the log: registers, a hex dump of 4 KB of stack
// (32 lines kept), 8 EBP frames, stack words that look like code addresses (0x400000-0x1000000 or
// 0x10000000-0x10200000; 300 scanned, 20 kept), the access type and address, and the player and zone.
// The scans stop at 0x988C70, the stack top GuardedShutdown_guess records.
// FUNCTION: TITANIUM 0x004CD620
// @early-stop: budget, structural ndiff=81
int __cdecl BuildCrashReport_guess(EXCEPTION_POINTERS* exceptionPointers_guess,
    char* report_guess, char* faultAddress_guess) {
    RawStackScratch_guess rawStackScratch_guess;
    char zoneName_guess[32];
    FUN_00574110_guess((g_savedContext_00989258_guess =
        *exceptionPointers_guess->ContextRecord, EQ_ARRAY(char, 0x0064CF68)),
        EQ_GLOBAL(const char*, 0x00790D70),
        exceptionPointers_guess->ExceptionRecord->ExceptionCode,
        exceptionPointers_guess->ExceptionRecord->ExceptionAddress);
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CF40), g_savedContext_00989258_guess.Eax,
        g_savedContext_00989258_guess.Ebx, g_savedContext_00989258_guess.Ecx,
        g_savedContext_00989258_guess.Edx);
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CF18), g_savedContext_00989258_guess.Esi,
        g_savedContext_00989258_guess.Edi, g_savedContext_00989258_guess.Ebp,
        g_savedContext_00989258_guess.Esp);
    sprintf(faultAddress_guess, EQ_ARRAY(char, 0x0064CF10),
        exceptionPointers_guess->ExceptionRecord->ExceptionAddress);
    sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CEF0),
        EQ_GLOBAL(const char*, 0x00790D70),
        exceptionPointers_guess->ExceptionRecord->ExceptionCode,
        exceptionPointers_guess->ExceptionRecord->ExceptionAddress);
    strcpy(report_guess, EQ_ARRAY(char, 0x00989058));
    sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CEC4),
        g_savedContext_00989258_guess.Eax, g_savedContext_00989258_guess.Ebx,
        g_savedContext_00989258_guess.Ecx, g_savedContext_00989258_guess.Edx);
    strcat(report_guess, EQ_ARRAY(char, 0x00989058));
    sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CE98),
        g_savedContext_00989258_guess.Esi, g_savedContext_00989258_guess.Edi,
        g_savedContext_00989258_guess.Ebp, g_savedContext_00989258_guess.Esp);
    strcat(report_guess, EQ_ARRAY(char, 0x00989058));

    try {
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CE8C));
    strcat(report_guess, EQ_ARRAY(char, 0x0064CE8C));
    // Stack dump: 4 KB from ESP, 16 bytes a line as hex and then as text ('.' for bytes it won't print);
    // every line is logged, the first 32 also go into the report.
    rawStackScratch_guess.lineCount_guess = 0;
    EQ_GLOBAL(unsigned char*, 0x00989054) =
        (unsigned char*)g_savedContext_00989258_guess.Esp;
    EQ_GLOBAL(unsigned char*, 0x00989050) =
        EQ_GLOBAL(unsigned char*, 0x00989054) + 0x1000;
    char* line_guess = EQ_ARRAY(char, 0x00988E50);
    while (EQ_GLOBAL(unsigned char*, 0x00989054) <
        EQ_GLOBAL(unsigned char*, 0x00989050)) {
        sprintf(line_guess, EQ_ARRAY(char, 0x0064CE84),
            EQ_GLOBAL(unsigned char*, 0x00989054));
        EQ_GLOBAL(int, 0x00988E48) = 0;
        rawStackScratch_guess.byteAddress_guess =
            EQ_GLOBAL(unsigned char*, 0x00989054);
        while (EQ_GLOBAL(int, 0x00988E48) < 2) {
            EQ_GLOBAL(int, 0x00988E44) = 0;
            while (EQ_GLOBAL(int, 0x00988E44) < 8) {
                unsigned int byteValue_guess = *rawStackScratch_guess.byteAddress_guess;
                sprintf(line_guess + strlen(line_guess), EQ_ARRAY(char, 0x0064CE7C),
                    byteValue_guess);
                ++rawStackScratch_guess.byteAddress_guess;
                ++EQ_GLOBAL(int, 0x00988E44);
            }
            sprintf(line_guess + strlen(line_guess), EQ_ARRAY(char, 0x0063FE10));
            ++EQ_GLOBAL(int, 0x00988E48);
        }
        sprintf(line_guess + strlen(line_guess), EQ_ARRAY(char, 0x0063FE10));
        EQ_GLOBAL(int, 0x00988E48) = 0;
        rawStackScratch_guess.byteAddress_guess =
            EQ_GLOBAL(unsigned char*, 0x00989054);
        while (EQ_GLOBAL(int, 0x00988E48) < 2) {
            EQ_GLOBAL(int, 0x00988E44) = 0;
            while (EQ_GLOBAL(int, 0x00988E44) < 8) {
                unsigned char byteValue_guess = *rawStackScratch_guess.byteAddress_guess;
                EQ_GLOBAL(char, 0x00988E40) = '.';
                if (byteValue_guess >= 0x20 && byteValue_guess <= 0x7D) {
                    EQ_GLOBAL(char, 0x00988E40) = (char)byteValue_guess;
                }
                sprintf(line_guess + strlen(line_guess), EQ_ARRAY(char, 0x0064CE78),
                    EQ_GLOBAL(char, 0x00988E40));
                ++rawStackScratch_guess.byteAddress_guess;
                ++EQ_GLOBAL(int, 0x00988E44);
            }
            sprintf(line_guess + strlen(line_guess), EQ_ARRAY(char, 0x0063FE10));
            ++EQ_GLOBAL(int, 0x00988E48);
        }
        EQ_GLOBAL(unsigned char*, 0x00989054) += 0x10;
        FUN_00574110_guess(EQ_ARRAY(char, 0x0063FE24), line_guess);
        if (rawStackScratch_guess.lineCount_guess < 0x20) {
            sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0063FE24), line_guess);
            strcat(report_guess, EQ_ARRAY(char, 0x00989058));
        }
        ++rawStackScratch_guess.lineCount_guess;
    }
    } catch (...) {
    }

    try {
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CE4C));
    strcat(report_guess, EQ_ARRAY(char, 0x0064CE4C));
    EQ_GLOBAL(int, 0x00988E44) = 0;
    EQ_GLOBAL(unsigned int*, 0x00988E3C) =
        (unsigned int*)g_savedContext_00989258_guess.Ebp;
    while (EQ_GLOBAL(int, 0x00988E44) < 8) {
        unsigned int* nextFrame_guess =
            (unsigned int*)*EQ_GLOBAL(unsigned int*, 0x00988E3C);
        ++EQ_GLOBAL(unsigned int*, 0x00988E3C);
        EQ_GLOBAL(unsigned int, 0x00988E38) = *EQ_GLOBAL(unsigned int*, 0x00988E3C);
        if (!((EQ_GLOBAL(unsigned int, 0x00988E38) > 0x400000 &&
               EQ_GLOBAL(unsigned int, 0x00988E38) < 0x1000000) ||
              (EQ_GLOBAL(unsigned int, 0x00988E38) > 0x10000000 &&
               EQ_GLOBAL(unsigned int, 0x00988E38) < 0x10200000))) {
            break;
        }
        FUN_00574110_guess(EQ_ARRAY(char, 0x0064CE24), EQ_GLOBAL(unsigned int, 0x00988E38),
            (int)nextFrame_guess - (int)EQ_GLOBAL(unsigned int*, 0x00988E3C));
        sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CE14),
            EQ_GLOBAL(unsigned int, 0x00988E38));
        strcat(report_guess, EQ_ARRAY(char, 0x00989058));
        ++EQ_GLOBAL(int, 0x00988E44);
        EQ_GLOBAL(unsigned int*, 0x00988E3C) = nextFrame_guess;
    }
    } catch (...) {
    }

    try {
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CDEC));
    strcat(report_guess, EQ_ARRAY(char, 0x0064CDEC));
    if ((EQ_GLOBAL(unsigned int, 0x00988E34) & 1) == 0) {
        EQ_GLOBAL(unsigned int, 0x00988E34) |= 1;
        EQ_GLOBAL(unsigned int*, 0x00988E30) =
            (unsigned int*)((g_savedContext_00989258_guess.Esp >> 2) << 2);
    }
    int stackScanCount_guess = 0;
    // Return-address scan from ESP up to the stack limit at 0x00988C70: words inside the exe
    // (0x400000-0x1000000) or 0x10000000-0x10200000 are logged, at most 300 of them, and the first 20 also go
    // into the report.
    while (EQ_GLOBAL(unsigned int*, 0x00988E30) <
        EQ_GLOBAL(unsigned int*, 0x00988C70) && stackScanCount_guess < 300) {
        EQ_GLOBAL(unsigned int, 0x00988E38) =
            *EQ_GLOBAL(unsigned int*, 0x00988E30);
        unsigned int address_guess = EQ_GLOBAL(unsigned int, 0x00988E38);
        if ((address_guess > 0x400000 && address_guess < 0x1000000) ||
            (address_guess > 0x10000000 && address_guess < 0x10200000)) {
            sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CDD4),
                EQ_GLOBAL(unsigned int*, 0x00988E30), address_guess);
            FUN_00574110_guess(EQ_ARRAY(char, 0x0063F9FC),
                EQ_ARRAY(char, 0x00989058));
            if (stackScanCount_guess < 0x14) {
                strcat(report_guess, EQ_ARRAY(char, 0x00989058));
            }
            ++stackScanCount_guess;
        }
        ++EQ_GLOBAL(unsigned int*, 0x00988E30);
    }
    } catch (...) {
    }

    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CF68),
        EQ_GLOBAL(const char*, 0x00790D70),
        exceptionPointers_guess->ExceptionRecord->ExceptionCode,
        exceptionPointers_guess->ExceptionRecord->ExceptionAddress);
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CF40), g_savedContext_00989258_guess.Eax,
        g_savedContext_00989258_guess.Ebx, g_savedContext_00989258_guess.Ecx,
        g_savedContext_00989258_guess.Edx);
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064CF18), g_savedContext_00989258_guess.Esi,
        g_savedContext_00989258_guess.Edi, g_savedContext_00989258_guess.Ebp,
        g_savedContext_00989258_guess.Esp);
    const char* faultType_guess = EQ_ARRAY(char, 0x0064CDA0);
    if (exceptionPointers_guess->ExceptionRecord->ExceptionCode == 0xC0000005) {
        if (exceptionPointers_guess->ExceptionRecord->NumberParameters <= 1) {
            FUN_00574110_guess(EQ_ARRAY(char, 0x0064CCB0));
            strcat(report_guess, EQ_ARRAY(char, 0x0064CCB0));
            faultType_guess = EQ_ARRAY(char, 0x0064CC98);
        } else {
            // Access violations name the access (information word 0: 0 read, else write) and the address.
            if (exceptionPointers_guess->ExceptionRecord->ExceptionInformation[0] == 0) {
                FUN_00574110_guess(EQ_ARRAY(char, 0x0064CD74));
                strcat(report_guess, EQ_ARRAY(char, 0x0064CD74));
                faultType_guess = EQ_ARRAY(char, 0x0064CD64);
            } else {
                FUN_00574110_guess(EQ_ARRAY(char, 0x0064CD38));
                strcat(report_guess, EQ_ARRAY(char, 0x0064CD38));
                faultType_guess = EQ_ARRAY(char, 0x0064CD28);
            }
            FUN_00574110_guess(EQ_ARRAY(char, 0x0064CCF4),
                exceptionPointers_guess->ExceptionRecord->ExceptionInformation[1]);
            sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CCF4),
                exceptionPointers_guess->ExceptionRecord->ExceptionInformation[1]);
            strcat(report_guess, EQ_ARRAY(char, 0x00989058));
        }
    }

    try {
    // Player name and zone ("NULL" / "UNKNOWN" until found), the report header, the registers and the stack
    // scan, all in one try in case the game state is broken.
    strcpy(zoneName_guess, EQ_ARRAY(char, 0x0064CC90));
    const char* playerName_guess = EQ_ARRAY(char, 0x0064CC88);
    CrashContextSource_guess* crashContext_guess =
        EQ_GLOBAL(CrashContextSource_guess*, 0x00905D00);
    if (crashContext_guess != 0) {
        int reportDataAddress_guess = (int)crashContext_guess +
            crashContext_guess->offsetSource_guess->dataOffset_guess;
        CrashReportData_guess* reportData_guess =
            (CrashReportData_guess*)reportDataAddress_guess;
        playerName_guess = reportData_guess->playerName_guess;
        if (EQ_GLOBAL(WorldData_guess*, 0x00905CC0) != 0) {
            EQ_GLOBAL(WorldData_guess*, 0x00905CC0)->FUN_005f6ed0_guess(
                reportData_guess->zoneId_guess, zoneName_guess);
        }
    }
    sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CC4C),
        playerName_guess, zoneName_guess,
        exceptionPointers_guess->ExceptionRecord->ExceptionCode, faultType_guess,
        exceptionPointers_guess->ExceptionRecord->ExceptionAddress);
    strcat(report_guess, EQ_ARRAY(char, 0x00989058));
    sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CBF8),
        g_savedContext_00989258_guess.Eax, g_savedContext_00989258_guess.Ebx,
        g_savedContext_00989258_guess.Ecx, g_savedContext_00989258_guess.Edx,
        g_savedContext_00989258_guess.Esi, g_savedContext_00989258_guess.Edi,
        g_savedContext_00989258_guess.Ebp, g_savedContext_00989258_guess.Esp);
    strcat(report_guess, EQ_ARRAY(char, 0x00989058));
    if ((EQ_GLOBAL(unsigned int, 0x00988E34) & 2) == 0) {
        EQ_GLOBAL(unsigned int, 0x00988E34) |= 2;
        EQ_GLOBAL(unsigned int*, 0x00988E2C) =
            (unsigned int*)((g_savedContext_00989258_guess.Esp >> 2) << 2);
    }
    int addressCount_guess = 0;
    while (EQ_GLOBAL(unsigned int*, 0x00988E2C) <
        EQ_GLOBAL(unsigned int*, 0x00988C70) && addressCount_guess < 300) {
        EQ_GLOBAL(unsigned int, 0x00988E38) =
            *EQ_GLOBAL(unsigned int*, 0x00988E2C);
        unsigned int address_guess = EQ_GLOBAL(unsigned int, 0x00988E38);
        if ((address_guess > 0x400000 && address_guess < 0x1000000) ||
            (address_guess > 0x10000000 && address_guess < 0x10200000)) {
            sprintf(EQ_ARRAY(char, 0x00989058), EQ_ARRAY(char, 0x0064CBEC),
                address_guess);
            strcat(report_guess, EQ_ARRAY(char, 0x00989058));
            ++addressCount_guess;
        }
        ++EQ_GLOBAL(unsigned int*, 0x00988E2C);
    }
    strcat(report_guess, EQ_ARRAY(char, 0x0064CBE8));
    } catch (...) {
    }
    return 1;
}

struct CleanupObject_guess {
    char unknown0000_guess[0xB50];
    int state_guess; // +0xB50
    // EXTERNAL: TITANIUM 0x004ACF33 CleanupObject_guess::ProcessGame_guess
    void ProcessGame_guess(int argumentA_guess, int argumentB_guess);
    // EXTERNAL: TITANIUM 0x00497395 CleanupObject_guess::Release_guess
    void Release_guess();
};

#define g_cleanupObject_00988df0_guess EQ_GLOBAL(CleanupObject_guess*, 0x00988DF0)
#define g_cleanupArgumentA_009889bc_guess EQ_GLOBAL(int, 0x009889BC)
#define g_cleanupArgumentB_00985db0_guess EQ_GLOBAL(int, 0x00985DB0)
#define g_cleanupMessage_0064cf88_guess EQ_ARRAY(char, 0x0064CF88)

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

typedef void (__stdcall *DeleteCriticalSectionFunction_guess)(void*);
#define g_DeleteCriticalSection_0063f11c_guess EQ_GLOBAL(DeleteCriticalSectionFunction_guess, 0x0063F11C)

// Runs pEverQuest's session loop (0x4ACF33, ProcessGame_guess) unless it is quitting (+0xB50), then
// deletes it and the three critical sections.
// FUNCTION: TITANIUM 0x004CDD09
void __cdecl RunGameAndShutdown_guess() {
    if (g_cleanupObject_00988df0_guess != 0 && g_cleanupObject_00988df0_guess->state_guess == 0) {
        g_cleanupObject_00988df0_guess->ProcessGame_guess(
            g_cleanupArgumentA_009889bc_guess, g_cleanupArgumentB_00985db0_guess);
    }
    FUN_00574110_guess(g_cleanupMessage_0064cf88_guess);
    if (g_cleanupObject_00988df0_guess != 0) {
        void* cleanupMemory_guess = g_cleanupObject_00988df0_guess;
        g_cleanupObject_00988df0_guess->Release_guess();
        free(cleanupMemory_guess);
        g_cleanupObject_00988df0_guess = 0;
    }
    DeleteCriticalSectionFunction_guess deleteCriticalSection_guess = g_DeleteCriticalSection_0063f11c_guess;
    deleteCriticalSection_guess(&EQ_GLOBAL(char, 0x00903FC0));
    deleteCriticalSection_guess(&EQ_GLOBAL(char, 0x00900800));
    deleteCriticalSection_guess(&EQ_GLOBAL(char, 0x0090422C));
}

// EXTERNAL: TITANIUM 0x00624477 FUN_00624477_guess
int __cdecl FUN_00624477_guess(KeyboardFile_guess* file_guess);
// EXTERNAL: TITANIUM 0x00611D9D FUN_00611d9d_guess
long __cdecl FUN_00611d9d_guess(int handle_guess);
// EXTERNAL: TITANIUM 0x0060E985 FUN_0060e985_guess
void* __cdecl FUN_0060e985_guess(unsigned int size_guess);
// EXTERNAL: TITANIUM 0x004B6C04 MemChecker0
int __cdecl MemChecker0(void* data_guess, unsigned int length_guess);
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();
// EXTERNAL: TITANIUM 0x0060F5DE srand
extern "C" void __cdecl srand(unsigned int seed_guess);
// EXTERNAL: TITANIUM 0x0060F5EB rand
extern "C" int __cdecl rand(void);

typedef int (__cdecl *FrontendMainFunction_guess)(void*, void*, int);
typedef int (__cdecl *LegacyFrontendMainFunction_guess)(void*, void*);
#define g_newFrontendMain_009889a4_guess EQ_GLOBAL(FrontendMainFunction_guess, 0x009889A4)
#define g_frontendMain_009889fc_guess EQ_GLOBAL(LegacyFrontendMainFunction_guess, 0x009889FC)

struct FrontendService_guess {
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
    virtual void NotifyError_guess();
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
    virtual void Shutdown_guess();
};

#define g_errorServiceA_0099e364_guess EQ_GLOBAL(FrontendService_guess*, 0x0099E364)
#define g_errorServiceB_0099e368_guess EQ_GLOBAL(FrontendService_guess*, 0x0099E368)

// EXTERNAL: TITANIUM 0x00611848 exit
extern "C" void __cdecl exit(int code_guess);

// Runs eqmain.dll's front end on the device list 0x986FC0 (0x9C0 bytes): -1 means quit, -2 shows an
// error box. Without either entry point it reports and exits with -45.
// FUNCTION: TITANIUM 0x004CE2D6
// @early-stop: budget, structural ndiff=15
int __cdecl RunFrontend_guess() {
    int result_guess = 1;
    LoadEQMainDLL_guess();
    int zero_guess = 0;
    int initResult_guess;
    if (g_newFrontendMain_009889a4_guess != (FrontendMainFunction_guess)zero_guess) {
        initResult_guess = g_newFrontendMain_009889a4_guess(
            g_module_00988df4_guess, EQ_ARRAY(char, 0x00986FC0), 0x9c0);
    } else if (g_frontendMain_009889fc_guess != (LegacyFrontendMainFunction_guess)zero_guess) {
        initResult_guess = g_frontendMain_009889fc_guess(
            g_module_00988df4_guess, EQ_ARRAY(char, 0x00986FC0));
    } else {
        FUN_00574110_guess(EQ_ARRAY(char, 0x0064D380));
        g_errorServiceA_0099e364_guess->NotifyError_guess();
        g_errorServiceB_0099e368_guess->Shutdown_guess();
        MessageBoxA((HWND)zero_guess, EQ_ARRAY(char, 0x0064D270), EQ_ARRAY(char, 0x0064D4D8), zero_guess);
        exit(-0x2d);
    }
    if (initResult_guess == -1) {
        result_guess = -1;
    } else if (initResult_guess == -2) {
        MessageBoxA((HWND)zero_guess, EQ_ARRAY(char, 0x0064D3C0), EQ_ARRAY(char, 0x0064D4D8), zero_guess);
    }
    UnloadFrontendDll_guess();
    return result_guess;
}

// Writes the exe's checksum, then 1024 (seed, ChecksumCodeRangesA_guess(seed)) pairs, seed 0 first, to
// `path_guess`. WinMain runs it for a command-line switch (0x64DA6C) and quits.
// FUNCTION: TITANIUM 0x004CE382
void __cdecl WriteChecksumFile_guess(char* path_guess) {
    int checksum_guess = -1;
    char modulePath_guess[512];
    GetModuleFileNameA(0, modulePath_guess, 0x200);
    KeyboardFile_guess* file_guess = fopen(modulePath_guess, "rb");
    if (file_guess != 0) {
        unsigned int count_guess = FUN_00611d9d_guess(FUN_00624477_guess(file_guess));
        void* buffer_guess = FUN_0060e985_guess(count_guess);
        fread(buffer_guess, 1, count_guess, file_guess);
        checksum_guess = MemChecker0(buffer_guess, count_guess);
        free(buffer_guess);
        fclose(file_guess);
    }
    srand(FUN_00576e80_guess());
    KeyboardFile_guess* out_guess = fopen(path_guess, "wb");
    if (out_guess != 0) {
        fwrite(&checksum_guess, 1, 4, out_guess);
        int index_guess = 0;
        do {
            unsigned int seed_guess = ((unsigned int)rand() << 16) | (unsigned int)rand();
            if (index_guess == 0) {
                seed_guess = 0;
            } else if (seed_guess == 0) {
                seed_guess = 1;
            }
            unsigned int hashed_guess = ChecksumCodeRangesA_guess(seed_guess);
            fwrite(&seed_guess, 1, 4, out_guess);
            fwrite(&hashed_guess, 1, 4, out_guess);
            ++index_guess;
        } while (index_guess < 0x400);
        fclose(out_guess);
    }
}

union MouseCapabilityFlags_guess {
    unsigned int flagsWord_guess;
    unsigned char flagsByte_guess;
};

struct MouseCapabilities_guess {
    unsigned int size_guess; // +0x00
    MouseCapabilityFlags_guess flags_guess; // +0x04
    unsigned int deviceType_guess; // +0x08
    unsigned int axes_guess; // +0x0c
    unsigned int unknown10_guess[7];
};

#define g_mouseProperty_00988c48_guess EQ_GLOBAL(KeyboardProperty_guess, 0x00988C48)

// Key press: modifier flags as in HandleKeyUp_guess, then the key manager and the extra bindings
// (FireModifierTolerantCommands_guess); 1 when either took it.
// FUNCTION: TITANIUM 0x004CE4AC
int __cdecl HandleKeyDown_guess(unsigned int key_guess) {
    unsigned int key = (unsigned char)key_guess;
    g_keyLast_00923d38_guess = key;
    switch (key) {
    case 0x1d:
        g_keyFlag_00923d30_guess = 1;
        break;
    case 0x2a:
        g_keyFlag_00923d2f_guess = 1;
        break;
    case 0x36:
        g_keyFlag_00923d32_guess = 1;
        break;
    case 0x38:
        g_keyFlag_00923d31_guess = 1;
        break;
    case 0x9d:
        g_keyFlag_00923d33_guess = 1;
        break;
    case 0xb8:
        g_keyFlag_00923d34_guess = 1;
        break;
    }
    if (g_keyFlag_00923d2f_guess != 0 || g_keyFlag_00923d32_guess != 0) {
        g_keyFlag_00923d2c_guess = 1;
    } else {
        g_keyFlag_00923d2c_guess = 0;
    }
    if (g_keyFlag_00923d30_guess != 0 || g_keyFlag_00923d33_guess != 0) {
        g_keyFlag_00923d2d_guess = 1;
    } else {
        g_keyFlag_00923d2d_guess = 0;
    }
    if (g_keyFlag_00923d31_guess != 0 || g_keyFlag_00923d34_guess != 0) {
        g_keyFlag_00923d2e_guess = 1;
    } else {
        g_keyFlag_00923d2e_guess = 0;
    }
    KeyCombo_guess combo_guess;
    combo_guess.Set_guess(key_guess, g_keyFlag_00923d2c_guess, g_keyFlag_00923d2d_guess,
        g_keyFlag_00923d2e_guess);
    char actioned_guess = g_keyManager_guess->HandleKeyDown(&combo_guess);
    char matched_guess = FireModifierTolerantCommands_guess(key_guess);
    NoteUserActivity_guess();
    if (actioned_guess == 0 && matched_guess == 0) {
        return 0;
    }
    return 1;
}

// Creates the DirectInput mouse; a wheel counts when it is attached with 3+ axes (0x988C28). Exclusive (5)
// only in full screen on XP, else non-exclusive (6); a 128-event buffer. Returns 0 or the failed step.
// FUNCTION: TITANIUM 0x004CE5C4
int __cdecl InitMouse_guess(void* window_guess, char mode_guess) {
    FUN_00574110_guess("Initializing Mouse.");
    if (g_directInput_00988c7c_guess == 0) {
        FUN_00574110_guess("DirectInputCreate has not been created!\n");
        return 1;
    }
    if (g_directInput_00988c7c_guess->vtable_guess->CreateDevice_guess(
        g_directInput_00988c7c_guess, EQ_ARRAY(char, 0x006638C0),
        &g_mouseDevice_00988c84_guess, 0) < 0) {
        return 2;
    }
    MouseCapabilities_guess capabilities_guess;
    capabilities_guess.size_guess = 0x2c;
    g_mouseDevice_00988c84_guess->vtable_guess->GetCapabilities_guess(
        g_mouseDevice_00988c84_guess, &capabilities_guess);
    if ((capabilities_guess.flags_guess.flagsByte_guess & 1) != 0 && capabilities_guess.axes_guess > 2) {
        EQ_GLOBAL(int, 0x00988C28) = 1;
    } else {
        EQ_GLOBAL(int, 0x00988C28) = 0;
    }
    if (g_mouseDevice_00988c84_guess->vtable_guess->SetDataFormat_guess(
        g_mouseDevice_00988c84_guess, EQ_ARRAY(char, 0x00660FD4)) < 0) {
        return 4;
    }
    char exclusive_guess;
    if (mode_guess != 0) {
        exclusive_guess = g_state_0099e38c_guess->flag04_guess;
    } else {
        exclusive_guess = IsFullScreen_guess();
    }
    int cooperativeResult_guess;
    if (exclusive_guess == 0) {
        cooperativeResult_guess = g_mouseDevice_00988c84_guess->vtable_guess->SetCooperativeLevel_guess(
            g_mouseDevice_00988c84_guess, window_guess, 6);
        OutputDebugStringA("nonexclusive mode\n");
    } else {
        if (CheckOSVersion_guess() == 0) {
            cooperativeResult_guess = g_mouseDevice_00988c84_guess->vtable_guess->SetCooperativeLevel_guess(
                g_mouseDevice_00988c84_guess, window_guess, 5);
        } else {
            cooperativeResult_guess = g_mouseDevice_00988c84_guess->vtable_guess->SetCooperativeLevel_guess(
                g_mouseDevice_00988c84_guess, window_guess, 6);
        }
    }
    if (cooperativeResult_guess < 0) {
        return 5;
    }
    KeyboardProperty_guess* property_guess = &g_mouseProperty_00988c48_guess;
    memset(property_guess, 0, 0x14);
    g_mouseProperty_00988c48_guess.size_guess = 0x14;
    g_mouseProperty_00988c48_guess.header_guess = 0x10;
    g_mouseProperty_00988c48_guess.object_guess = 0;
    g_mouseProperty_00988c48_guess.how_guess = 0;
    g_mouseProperty_00988c48_guess.value_guess = 0x80;
    if (g_mouseDevice_00988c84_guess->vtable_guess->SetProperty_guess(
        g_mouseDevice_00988c84_guess, 1, property_guess) < 0) {
        return 6;
    }
    if (g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(
        g_mouseDevice_00988c84_guess) < 0) {
        return 7;
    }
    EQ_GLOBAL(int, 0x00790118) = 1;
    return 0;
}

// Restores the mouse when the window is activated again: resets the device state (0x0060A310), releases
// and re-creates the mouse for the foreground window, tells the input state whether the client is full
// screen (+4), and in full screen sets the cursor, parks it at (10, 10) and shows it.
// FUNCTION: TITANIUM 0x004CE72D
void __cdecl ReinitMouse_guess() {
    g_state_0099e38c_guess->FUN_0060a310_guess();
    ReleaseMouse_guess();
    InitMouse_guess(g_foregroundWindow_009889bc_guess, 1);
    if (pinstCOptionsWnd_guess != 0) {
        pinstCOptionsWnd_guess->FUN_0053ca42_guess(g_state_0099e38c_guess->flag04_guess);
    }
    if (g_state_0099e38c_guess->flag04_guess != 0) {
        SetCursor(pinstCXWndManager_guess->cursor0134_guess);
        SetCursorPos(10, 10);
        while (ShowCursor(1) < 0) {
        }
    }
}

// EXTERNAL: TITANIUM 0x00461979 IsChineseOrJapaneseLanguage_guess
char __cdecl IsChineseOrJapaneseLanguage_guess(int value_guess);
// EXTERNAL: TITANIUM 0x00469215 do_quit_guess
void __cdecl do_quit_guess(int unused_guess, char* command_guess);

struct ParamBlock_guess {
    int field00_guess; // +0x00
    int field04_guess; // +0x04
    int field08_guess; // +0x08
    int field0c_guess; // +0x0c
    unsigned char flag10_guess; // +0x10
};

// EXTERNAL: TITANIUM 0x00609F80 FUN_00609f80_guess
void __stdcall FUN_00609f80_guess(ParamBlock_guess* block_guess);
// EXTERNAL: TITANIUM 0x00609DC0 FUN_00609dc0_guess
void __stdcall FUN_00609dc0_guess(int first_guess, int second_guess);

struct StateDispatch_guess {
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
    virtual void Slot24_guess(int* value_guess);
};

struct Client_guess {
    // EXTERNAL: TITANIUM 0x0043745D Client_guess::GetValue2cf8_guess
    int GetValue2cf8_guess();
    // EXTERNAL: TITANIUM 0x00445243 Client_guess::RealRender_World_guess
    void RealRender_World_guess();
};

struct KeyEvent_guess {
    // EXTERNAL: TITANIUM 0x005BA4D0 KeyEvent_guess::FUN_005ba4d0_guess
    void FUN_005ba4d0_guess(unsigned int wParam_guess, int* lParam_guess, unsigned char flag_guess,
        unsigned char flag2_guess, unsigned char flag3_guess);
    // EXTERNAL: TITANIUM 0x005BA250 KeyEvent_guess::FUN_005ba250_guess
    unsigned int FUN_005ba250_guess();
};

#define g_client_00905d24_guess EQ_GLOBAL(Client_guess*, 0x00905D24)
#define g_stateDispatch_0099e364_guess EQ_GLOBAL(StateDispatch_guess*, 0x0099E364)

// Window messages while CDisplay is up (0x905D24): (de)activation unacquires or re-acquires DirectInput,
// key messages go to HandleKeyDown_guess/HandleKeyUp_guess, IME and input-language messages flush the
// keyboard. 0x4642-0x4644 (wParam 0x4242-0x4244) are private, probably from the graphics or front-end DLL.
// FUNCTION: TITANIUM 0x004CE798
// @early-stop: budget, structural ndiff=153
LRESULT CALLBACK eqWndProc(HWND window_guess, UINT message_guess, WPARAM wParam_guess, LPARAM lParam_guess) {
    if (g_messageState_0099d3f8_guess != 0 && g_messageState_0099d3f8_guess->FUN_005acfb0_guess() != 0 &&
        g_messageState_0099d3f8_guess->FUN_005ad310_guess(message_guess, wParam_guess, (int*)lParam_guess) == 0) {
        return 0;
    }
    if (g_cleanupObject_00988df0_guess == 0) {
        return DefWindowProcA(window_guess, message_guess, wParam_guess, lParam_guess);
    }
    if (g_client_00905d24_guess->GetValue2cf8_guess() != 0) {
        switch (message_guess) {
        case 0x2:
            return 0;
        case 0x5:
            return 0;
        case 0x6:
            if (wParam_guess == 0) {
                if (g_mouseDevice_00988c84_guess != 0) {
                    g_mouseDevice_00988c84_guess->vtable_guess->Unacquire_guess(g_mouseDevice_00988c84_guess);
                }
                if (g_keyboardDevice_00988c80_guess != 0) {
                    g_keyboardDevice_00988c80_guess->vtable_guess->Unacquire_guess(g_keyboardDevice_00988c80_guess);
                }
                FlushKeyboard_guess();
                EQ_GLOBAL(int, 0x00790118) = 0;
                return 0;
            }
            if (g_mouseDevice_00988c84_guess != 0) {
                g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(g_mouseDevice_00988c84_guess);
            }
            if (g_keyboardDevice_00988c80_guess != 0) {
                g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
            }
            FlushKeyboard_guess();
            EQ_GLOBAL(int, 0x00790118) = 1;
            if (EQ_GLOBAL(unsigned char, 0x00988C74) != 1) {
                EQ_GLOBAL(int, 0x00790118) = 1;
                return 0;
            }
            ReinitMouse_guess();
            EQ_GLOBAL(unsigned char, 0x00988C74) = 0;
            return 0;
        case 0xf:
            ValidateRect(window_guess, 0);
            return 0;
        case 0x10:
            do_quit_guess(EQ_GLOBAL(int, 0x00905CE4), EQ_ARRAY(char, 0x0063FE10));
            return 0;
        case 0x1c:
            if (wParam_guess == 0) {
                if (g_state_0099e38c_guess->flag04_guess != 0) {
                    EQ_GLOBAL(unsigned char, 0x00988C74) = 1;
                }
                {
                    int point_guess[2];
                    point_guess[0] = g_configOutC_00988c88_guess;
                    point_guess[1] = g_configOutD_00988c8c_guess;
                    EQ_GLOBAL(unsigned char, 0x00988C76) = 1;
                    pinstCXWndManager_guess->FUN_005b0230_guess(point_guess);
                }
                if (g_mouseDevice_00988c84_guess != 0) {
                    g_mouseDevice_00988c84_guess->vtable_guess->Unacquire_guess(g_mouseDevice_00988c84_guess);
                }
                if (g_keyboardDevice_00988c80_guess != 0) {
                    g_keyboardDevice_00988c80_guess->vtable_guess->Unacquire_guess(g_keyboardDevice_00988c80_guess);
                }
                FlushKeyboard_guess();
                EQ_GLOBAL(int, 0x00790118) = 0;
                return 0;
            }
            EQ_GLOBAL(unsigned char, 0x00988C76) = 0;
            SetForegroundWindow((HWND)g_foregroundWindow_009889bc_guess);
            SetFocus((HWND)g_foregroundWindow_009889bc_guess);
            g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(g_mouseDevice_00988c84_guess);
            g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
            FlushKeyboard_guess();
            EQ_GLOBAL(int, 0x00790118) = 1;
            if (EQ_GLOBAL(unsigned char, 0x00988C74) != 1) {
                EQ_GLOBAL(int, 0x00790118) = 1;
                return 0;
            }
            ReinitMouse_guess();
            EQ_GLOBAL(unsigned char, 0x00988C74) = 0;
            return 0;
        case 0x50:
            break;
        case 0x51:
            if (pinstCOptionsWnd_guess == 0) {
                return 0;
            }
            pinstCOptionsWnd_guess->FUN_0053f1f4_guess();
            return 0;
        case 0x100:
        case 0x104:
            if (g_messageState_0099d3f8_guess == 0) {
                return 0;
            }
            // Auto-repeat (lParam bit 30) is ignored.
            if ((((unsigned int)lParam_guess) >> 30 & 1) != 0) {
                return 0;
            }
            {
                KeyEvent_guess* key_guess = (KeyEvent_guess*)&wParam_guess;
                key_guess->FUN_005ba4d0_guess(wParam_guess, (int*)lParam_guess, g_keyFlag_00923d2c_guess,
                    g_keyFlag_00923d2d_guess, g_keyFlag_00923d2e_guess);
                HandleKeyDown_guess(key_guess->FUN_005ba250_guess());
            }
            return 0;
        case 0x101:
        case 0x105:
            if (g_messageState_0099d3f8_guess == 0) {
                return 0;
            }
            {
                KeyEvent_guess* key_guess = (KeyEvent_guess*)&wParam_guess;
                key_guess->FUN_005ba4d0_guess(wParam_guess, (int*)lParam_guess, g_keyFlag_00923d2c_guess,
                    g_keyFlag_00923d2d_guess, g_keyFlag_00923d2e_guess);
                HandleKeyUp_guess(key_guess->FUN_005ba250_guess());
            }
            return 0;
        case 0x112:
            if (g_state_0099e38c_guess->flag04_guess != 0 && IsChineseOrJapaneseLanguage_guess(EQ_GLOBAL(int, 0x00923D74)) == 0) {
                return 0;
            }
            if (EQ_GLOBAL(int, 0x00790118) == 1) {
                unsigned int command_guess = wParam_guess & 0xfff0;
                // While input is acquired, SC_MOUSEMENU, SC_KEYMENU (Alt) and SC_HOTKEY are eaten.
                if (command_guess == 0xf090 || command_guess == 0xf100 || command_guess == 0xf150) {
                    return 0;
                }
            }
            return DefWindowProcA(window_guess, message_guess, wParam_guess, lParam_guess);
        case 0x201:
            if (EQ_GLOBAL(int, 0x00790118) != 0) {
                return 0;
            }
            EQ_GLOBAL(unsigned char, 0x00988C75) = 1;
            SetForegroundWindow((HWND)g_foregroundWindow_009889bc_guess);
            SetFocus((HWND)g_foregroundWindow_009889bc_guess);
            g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(g_mouseDevice_00988c84_guess);
            g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
            FlushKeyboard_guess();
            EQ_GLOBAL(int, 0x00790118) = 1;
            return 0;
        case 0x216:
            if (g_state_0099e38c_guess->flag04_guess != 0) {
                return 0;
            }
            FUN_00609dc0_guess(((int*)lParam_guess)[0], ((int*)lParam_guess)[1]);
            return 0;
        case 0x218:
            if (wParam_guess != 0) {
                return 0;
            }
            // WM_POWERBROADCAST query: BROADCAST_QUERY_DENY, so the PC may not suspend.
            return 0x424d5144;
        case 0x231:
            if (g_state_0099e38c_guess->flag04_guess != 0) {
                return 0;
            }
            g_mouseDevice_00988c84_guess->vtable_guess->Unacquire_guess(g_mouseDevice_00988c84_guess);
            g_keyboardDevice_00988c80_guess->vtable_guess->Unacquire_guess(g_keyboardDevice_00988c80_guess);
            FlushKeyboard_guess();
            EQ_GLOBAL(int, 0x00790118) = 0;
            return 0;
        case 0x4642:
            if (wParam_guess != 0x4242) {
                return 0;
            }
            g_stateDispatch_0099e364_guess->Slot24_guess((int*)lParam_guess);
            return 0;
        case 0x4643:
            if (wParam_guess != 0x4243) {
                return 0;
            }
            g_client_00905d24_guess->RealRender_World_guess();
            return 0;
        case 0x4644:
            {
                if (wParam_guess != 0x4244) {
                    return 0;
                }
                ParamBlock_guess block_guess;
                block_guess.flag10_guess = g_state_0099e38c_guess->flag04_guess;
                block_guess.field00_guess = ((int*)lParam_guess)[0];
                block_guess.field04_guess = ((int*)lParam_guess)[1];
                block_guess.field08_guess = ((int*)lParam_guess)[3];
                block_guess.field0c_guess = ((int*)lParam_guess)[2];
                FUN_00609f80_guess(&block_guess);
                return 0;
            }
        case 0x4645:
            return 0;
        case 0xf000:
            return 0;
        case 0x20:
            return 0;
        case 0x111:
            return 0;
        case 0xf010:
            return 0;
        case 0x10d:
        case 0x10e:
        case 0x10f:
        case 0x281:
        case 0x282:
        case 0x283:
        case 0x284:
        case 0x285:
        case 0x286:
        case 0x290:
        case 0x291:
            break;
        default:
            return DefWindowProcA(window_guess, message_guess, wParam_guess, lParam_guess);
        }
        if (g_messageState_0099d3f8_guess == 0) {
            return 0;
        }
        FlushKeyboard_guess();
    } else {
        if (message_guess == 0x4642) {
            if (wParam_guess == 0x4242) {
                g_stateDispatch_0099e364_guess->Slot24_guess((int*)lParam_guess);
            }
        } else if (message_guess == 0x4643 && wParam_guess == 0x4243) {
            g_client_00905d24_guess->RealRender_World_guess();
        }
    }
    return DefWindowProcA(window_guess, message_guess, wParam_guess, lParam_guess);
}

#define g_mainWindow_00923770_guess EQ_GLOBAL(void*, 0x00923770)

struct KeyRecord_guess {
    unsigned char key_guess; // +0x00
    char unknown01_guess[3];
    unsigned char flags04_guess; // +0x04
    char unknown05_guess[15];
};

// Reads up to 32 buffered key events while EQ is the foreground window; data bit 0x80 means pressed.
// Returns the event count, or 1.
// FUNCTION: TITANIUM 0x004CECC7
// @early-stop: budget, structural ndiff=18
unsigned int __cdecl ProcessKeyboardEvents_guess() {
    int buffer_guess[160];
    unsigned int size_guess = 0x20;
    void* window_guess = GetForegroundWindow();
    unsigned int count_guess = 0;
    if (window_guess != 0 && window_guess == g_mainWindow_00923770_guess) {
        g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
        if (g_keyboardDevice_00988c80_guess->vtable_guess->GetDeviceData_guess(
                g_keyboardDevice_00988c80_guess, 0x14, buffer_guess, (int*)&size_guess, 0) != 0) {
            FlushKeyboard_guess();
        } else {
            if (size_guess > 0) {
                KeyRecord_guess* event_guess = (KeyRecord_guess*)buffer_guess;
                do {
                    unsigned char key_guess = event_guess->key_guess;
                    if ((event_guess->flags04_guess & 0x80) != 0) {
                        HandleKeyDown_guess(key_guess);
                    } else {
                        HandleKeyUp_guess(key_guess);
                    }
                    ++count_guess;
                    ++event_guess;
                } while (count_guess < size_guess);
            }
            return size_guess;
        }
    }
    return 1;
}

// True when the block-stored string table already holds a string equal to `checker` (0x00572650). The font
// list uses it to add each font family once.
// FUNCTION: TITANIUM 0x004CED52
char CheckerList_guess::Check_guess(Checker_guess* checker) {
    int index_guess = 0;
    if (count_guess > 0) {
        do {
            if (checker->FUN_00572650_guess((int)&blocks_guess[index_guess >> shift_guess][index_guess & mask_guess])) {
                return 1;
            }
            ++index_guess;
        } while (index_guess < count_guess);
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x00612662 FUN_00612662_guess
int __cdecl FUN_00612662_guess(const char* path_guess);
// EXTERNAL: TITANIUM 0x0046556B copyFileWithRetry_guess
int __cdecl copyFileWithRetry_guess(const char* dataFile_guess, const char* exeFile_guess, char* message_guess);
// EXTERNAL: TITANIUM 0x004656C2 calculateFileCRC32_guess
int __cdecl calculateFileCRC32_guess(const char* file_guess, int* value_guess);
// EXTERNAL: TITANIUM 0x004250F0 ReturnOne_guess
int __cdecl ReturnOne_guess();
// EXTERNAL: TITANIUM 0x0046E370 init_mm_guess
void __cdecl init_mm_guess();
// EXTERNAL: TITANIUM 0x004B385E FUN_004b385e_guess
void __cdecl FUN_004b385e_guess();
// EXTERNAL: TITANIUM 0x0057F6A6 FUN_0057f6a6_guess
int __stdcall FUN_0057f6a6_guess(unsigned short version_guess, WSADATA* data_guess);

// EXTERNAL: TITANIUM 0x00610837 sscanf
extern "C" int __cdecl sscanf(const char* text_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x00611F5B _strlwr
extern "C" char* __cdecl _strlwr(char* text_guess);
// EXTERNAL: TITANIUM 0x0060E590 strstr
extern "C" char* __cdecl strstr(const char* text_guess, const char* pattern_guess);
// EXTERNAL: TITANIUM 0x0062202C _strnicmp
extern "C" int __cdecl _strnicmp(const char* first_guess, const char* second_guess, unsigned int count_guess);
// EXTERNAL: TITANIUM 0x00621E9C _stricmp
extern "C" int __cdecl _stricmp(const char* first_guess, const char* second_guess);
// EXTERNAL: TITANIUM 0x0060E620 strncpy
extern "C" char* __cdecl strncpy(char* destination_guess, const char* source_guess, unsigned int count_guess);
// EXTERNAL: TITANIUM 0x0060EC45 fprintf
extern "C" int __cdecl fprintf(KeyboardFile_guess* file_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x00611848 exit
extern "C" void __cdecl exit(int code_guess);

// struct _stat (VC7.1 sys/stat.h layout)
struct StatBuffer_guess {
    unsigned int st_dev; // +0x00
    unsigned short st_ino; // +0x04
    unsigned short st_mode; // +0x06
    short st_nlink; // +0x08
    short st_uid; // +0x0a
    short st_gid; // +0x0c
    unsigned int st_rdev; // +0x10
    long st_size; // +0x14
    long st_atime; // +0x18
    long st_mtime; // +0x1c
    long st_ctime; // +0x20
};
// EXTERNAL: TITANIUM 0x006104F0 _stat
extern "C" int __cdecl _stat(const char* path_guess, StatBuffer_guess* buffer_guess);

struct DeviceRecord_guess {
    char name_guess[0x80];
};

struct GraphicsState_guess {
    char unknown00_guess[0x28];
    DeviceRecord_guess devices_guess[16]; // +0x28
    int deviceCount_guess; // +0x828
    // EXTERNAL: TITANIUM 0x00609D90 GraphicsState_guess::FUN_00609d90_guess
    int FUN_00609d90_guess(HINSTANCE instance_guess);
};

struct EngineInfo_guess {
    char unknown00_guess[0x0C];
    const char* buildDate_guess; // +0x0c
    const char* buildTime_guess; // +0x10
    char unknown14_guess[0x10];
    int cpuSpeed_guess; // +0x24
    char unknown28_guess[0x08];
    const char* cpuName_guess; // +0x30
    const char* name_guess; // +0x34 video card
    int value38_guess; // +0x38
    int value3c_guess; // +0x3c
    int value40_guess; // +0x40
    int value44_guess; // +0x44
    int value48_guess; // +0x48
    int value4c_guess; // +0x4c
};

struct DeviceList_guess {
    char names_guess[16][0x40];
    int deviceCount_guess; // 0x009873C0
    HWND window_guess; // 0x009873C4
    int ready_guess; // 0x009873C8
};

typedef void (__cdecl *GetEngineInfoFunction_guess)(EngineInfo_guess** info_guess);

#define g_graphics_0099e38c_guess EQ_GLOBAL(GraphicsState_guess*, 0x0099E38C)
#define g_engineInfo_0099e354_guess EQ_GLOBAL(EngineInfo_guess*, 0x0099E354)
#define g_GetEngineInfo_0099e378_guess EQ_GLOBAL(GetEngineInfoFunction_guess, 0x0099E378)
#define g_deviceList_00986fc0_guess EQ_GLOBAL(DeviceList_guess, 0x00986FC0)
typedef char Argument_guess[0x100];
#define g_args_00985fc0_guess EQ_ARRAY(Argument_guess, 0x00985FC0)
#define g_argCount_00988ddc_guess EQ_GLOBAL(int, 0x00988DDC)
#define g_exePath_00988a00_guess EQ_ARRAY(char, 0x00988A00)
#define g_exeName_00987690_guess EQ_ARRAY(char, 0x00987690)
#define g_clientName_00985db8_guess EQ_ARRAY(char, 0x00985DB8)
#define g_commandLine_009876b0_guess EQ_ARRAY(char, 0x009876B0)
#define g_ticket_009878f0_guess EQ_ARRAY(char, 0x009878F0)
#define g_server_0098754c_guess EQ_ARRAY(char, 0x0098754C)
#define g_name_00987930_guess EQ_ARRAY(char, 0x00987930)
#define g_localeCount_00799810_guess EQ_GLOBAL(int, 0x00799810)
#define g_localeNames_00799830_guess EQ_ARRAY(const char*, 0x00799830)
#define g_locale_00923d74_guess EQ_GLOBAL(int, 0x00923D74)
#define g_noSound_00988de0_guess EQ_GLOBAL(int, 0x00988DE0)
#define g_noReverb_00988de4_guess EQ_GLOBAL(int, 0x00988DE4)
#define g_solo_00988dd4_guess EQ_GLOBAL(int, 0x00988DD4)
#define g_tutorial_00988dd8_guess EQ_GLOBAL(int, 0x00988DD8)
#define g_letters_00988c00_guess EQ_ARRAY(char, 0x00988C00)
#define g_digits_00987980_guess EQ_ARRAY(char, 0x00987980)
#define g_mainWindow_00988c24_guess EQ_GLOBAL(HWND, 0x00988C24)
#define g_window_009889bc_guess EQ_GLOBAL(HWND, 0x009889BC)
#define g_instance_00985db0_guess EQ_GLOBAL(HINSTANCE, 0x00985DB0)
#define g_driverInfo_00904000_guess EQ_ARRAY(char, 0x00904000)
#define g_driverValue_00904204_guess EQ_GLOBAL(int, 0x00904204)
#define g_driverValue_00904208_guess EQ_GLOBAL(int, 0x00904208)
#define g_savedEngine_00987970_guess EQ_GLOBAL(int, 0x00987970)
#define g_savedEngine_00987974_guess EQ_GLOBAL(EngineInfo_guess*, 0x00987974)
#define g_savedGraphics_00987978_guess EQ_GLOBAL(GraphicsState_guess*, 0x00987978)
#define g_engineValue_0099e358_guess EQ_GLOBAL(int, 0x0099E358)

// Startup checks and setup, beyond what the name says: patcher hand-off (p.dat, optp.dat, kp.dat), the
// client file name (EQGAME.EXE, else ILLEGAL.TXT and exit), command-line switches (patchme required,
// /ticket:, /server:, /name:, /locale:, nosound, solo, tutorial), WinSock 1.1, 3D devices, the window.
// FUNCTION: TITANIUM 0x004CED8F
// @early-stop: budget, structural ndiff=165
int __cdecl CheckCriticalFiles_guess(const char* commandLine_guess, HINSTANCE instance_guess) {
    char patchMe_guess = 0;
    char message_guess[256];
    char patchMessage_guess[256];
    char dataFile_guess[32];
    char exeFile_guess[32];
    int dataValue_guess;
    int exeValue_guess;
    int i;

    FUN_00574110_guess("Checking critical files.");
    FUN_00612662_guess("memory.txt");
    message_guess[0] = 0;
    copyFileWithRetry_guess("mssb16.tsk", "eq.tmp", message_guess);
    memset(&g_deviceList_00986fc0_guess, 0, 0x9c0);
    char* line_guess = GetCommandLineA();
    for (i = 0; i < 30; i++) {
        g_letters_00988c00_guess[i] = (char)i + 'A';
        g_digits_00987980_guess[i] = (char)i + '0';
    }
    g_argCount_00988ddc_guess = sscanf(line_guess, "%s ", g_exePath_00988a00_guess);
    if (GetModuleFileNameA(0, g_exePath_00988a00_guess, 0x200) == 0) {
        FUN_00574110_guess("ERROR: Unable to get filename.\n");
    }
    int start_guess = 0;
    int length_guess = strlen(g_exePath_00988a00_guess);
    while (--length_guess > 0) {
        char c = g_exePath_00988a00_guess[length_guess];
        if (c == '_' || c == '\\') {
            start_guess = length_guess + 1;
            break;
        }
    }
    strcpy(g_exeName_00987690_guess, &g_exePath_00988a00_guess[start_guess]);
    _strlwr(g_exeName_00987690_guess);
    if (strstr(g_exeName_00987690_guess, "test") != 0) {
        strcpy(g_exeName_00987690_guess, "test");
        strcpy(dataFile_guess, "testp.dat");
        strcpy(exeFile_guess, "testEverquest.exe");
        sprintf(patchMessage_guess, "Patch program updated, please restart %s.", exeFile_guess);
    } else {
        strcpy(dataFile_guess, "p.dat");
        strcpy(exeFile_guess, "Everquest.exe");
        sprintf(patchMessage_guess, "Patch program updated, please restart %s.", exeFile_guess);
    }
    if (calculateFileCRC32_guess(dataFile_guess, &dataValue_guess) != -1 &&
        (calculateFileCRC32_guess(exeFile_guess, &exeValue_guess) == -1 || dataValue_guess != exeValue_guess)) {
        message_guess[0] = 0;
        if (copyFileWithRetry_guess(dataFile_guess, exeFile_guess, message_guess) == -1) {
            MessageBoxA(0, message_guess, "EverQuest", 0x40000);
        } else {
            MessageBoxA(0, patchMessage_guess, "EverQuest", 0x40000);
        }
        exit(0);
    }
    sprintf(patchMessage_guess, "Optional Patch program updated, please restart %s.", exeFile_guess);
    if (calculateFileCRC32_guess("optp.dat", &dataValue_guess) != -1 &&
        (calculateFileCRC32_guess("OptPatch.exe", &exeValue_guess) == -1 || dataValue_guess != exeValue_guess)) {
        message_guess[0] = 0;
        if (copyFileWithRetry_guess("optp.dat", "OptPatch.exe", message_guess) == -1) {
            MessageBoxA(0, message_guess, "EverQuest", 0x40000);
        } else {
            MessageBoxA(0, patchMessage_guess, "EverQuest", 0x40000);
        }
        exit(0);
    }
    sprintf(patchMessage_guess, "Kunark Patch program updated, please restart %s.", exeFile_guess);
    if (calculateFileCRC32_guess("kp.dat", &dataValue_guess) != -1 &&
        (calculateFileCRC32_guess("kpatch.exe", &exeValue_guess) == -1 || dataValue_guess != exeValue_guess)) {
        message_guess[0] = 0;
        if (copyFileWithRetry_guess("kp.dat", "kpatch.exe", message_guess) == -1) {
            MessageBoxA(0, message_guess, "EverQuest", 0x40000);
        } else {
            MessageBoxA(0, patchMessage_guess, "EverQuest", 0x40000);
        }
        exit(0);
    }
    message_guess[0] = 0;
    copyFileWithRetry_guess("defaults.dat", "defaults.eal", message_guess);

    int nameStart_guess = 0;
    length_guess = strlen(g_exePath_00988a00_guess);
    if (g_exePath_00988a00_guess[0] == '"') {
        for (i = 0; i < length_guess; i++) {
            g_exePath_00988a00_guess[i] = g_exePath_00988a00_guess[i + 1];
        }
        length_guess--;
    }
    if (length_guess > 0) {
        if (g_exePath_00988a00_guess[length_guess - 1] == '\\') {
            g_exePath_00988a00_guess[length_guess - 1] = 0;
            length_guess--;
        }
        if (length_guess > 0) {
            if (g_exePath_00988a00_guess[length_guess - 1] == '"') {
                g_exePath_00988a00_guess[length_guess - 1] = 0;
                length_guess--;
            }
            if (length_guess > 0) {
                while (--length_guess > 0) {
                    if (g_exePath_00988a00_guess[length_guess] == '\\') {
                        nameStart_guess = length_guess + 1;
                        break;
                    }
                }
            }
        }
    }
    initializeClientValidationString_guess();
    if (_strnicmp(g_exeName_00987690_guess, "test", 4) == 0) {
        nameStart_guess += 4;
    }
    for (i = 0; i < (int)strlen(g_clientName_00985db8_guess); i++) {
        if (g_clientName_00985db8_guess[i] == 'P') {
            g_clientName_00985db8_guess[i] = '.';
        } else {
            g_clientName_00985db8_guess[i] += 0x11;
        }
    }
    if (g_argCount_00988ddc_guess != 1 ||
        _stricmp(g_clientName_00985db8_guess, &g_exePath_00988a00_guess[nameStart_guess]) != 0) {
        KeyboardFile_guess* file_guess = fopen("ILLEGAL.TXT", "wt");
        if (file_guess != 0) {
            fprintf(file_guess, "You have an illegal client filename %s (fndi = %d, n = %d, %s)\n",
                &g_exePath_00988a00_guess[nameStart_guess], nameStart_guess, g_argCount_00988ddc_guess, g_clientName_00985db8_guess);
            fclose(file_guess);
        }
        exit(0);
    }
    if (ReturnOne_guess() == 0) {
        FUN_00574110_guess("You are using an incorrect version of winsock.\n");
        exit(0);
    }
    g_noSound_00988de0_guess = !ReadIniBool_guess("Defaults", "Sound", "TRUE");
    g_argCount_00988ddc_guess = sscanf(commandLine_guess, "%s %s %s %s %s %s %s %s",
        g_args_00985fc0_guess[0], g_args_00985fc0_guess[1], g_args_00985fc0_guess[2], g_args_00985fc0_guess[3],
        g_args_00985fc0_guess[4], g_args_00985fc0_guess[5], g_args_00985fc0_guess[6], g_args_00985fc0_guess[7]);
    if (g_argCount_00988ddc_guess > 0) {
        memset(g_commandLine_009876b0_guess, 0, 0x1c0);
        for (i = 0; i < g_argCount_00988ddc_guess; i++) {
            char* arg_guess = g_args_00985fc0_guess[i];
            if (strlen(arg_guess) + strlen(g_commandLine_009876b0_guess) + 2 < 0x1c0) {
                strcat(g_commandLine_009876b0_guess, arg_guess);
                strcat(g_commandLine_009876b0_guess, EQ_ARRAY(char, 0x0063FE10));
            }
            // nosound ends the loop: switches after it, patchme included, are never read.
            if (_strnicmp(arg_guess, "nosou", 5) == 0) {
                g_noSound_00988de0_guess = 1;
                if (i >= 0) {
                    for (; i < g_argCount_00988ddc_guess; i++) {
                        strcpy(g_args_00985fc0_guess[i], g_args_00985fc0_guess[i + 1]);
                    }
                    g_argCount_00988ddc_guess--;
                }
                break;
            }
            if (_strnicmp(arg_guess, "patchme", 7) == 0) {
                patchMe_guess = 1;
            } else if (_strnicmp(arg_guess, "/ticket:", 8) == 0) {
                strncpy(g_ticket_009878f0_guess, arg_guess + 8, 0x3f);
                if (g_ticket_009878f0_guess[strlen(g_ticket_009878f0_guess) - 1] == '"') {
                    g_ticket_009878f0_guess[strlen(g_ticket_009878f0_guess) - 1] = 0;
                }
            } else if (_strnicmp(arg_guess, "/server:", 8) == 0) {
                strncpy(g_server_0098754c_guess, arg_guess + 8, 0x7f);
            } else if (_strnicmp(arg_guess, "/name:", 6) == 0) {
                strncpy(g_name_00987930_guess, arg_guess + 6, 0x3f);
            } else if (_strnicmp(arg_guess, "/locale:", 8) == 0) {
                char locale_guess[4];
                strncpy(locale_guess, arg_guess + 8, 3);
                int found_guess = 0;
                for (int j = 0; j < g_localeCount_00799810_guess; j++) {
                    if (_strnicmp(locale_guess, g_localeNames_00799830_guess[j], 2) == 0) {
                        found_guess = j;
                        break;
                    }
                }
                g_locale_00923d74_guess = found_guess;
            }
        }
    }
    if (patchMe_guess == 0) {
        MessageBoxA(0, "Please run EverQuest.exe", "EverQuest", 0x40000);
        exit(0);
    }
    StatBuffer_guess stat_guess;
    if (_stat("nosound.txt", &stat_guess) == 0) {
        FUN_00574110_guess("Found nosound.txt, disabling sound.");
        g_noSound_00988de0_guess = 1;
    }
    if (_stat("noreverb.txt", &stat_guess) == 0) {
        FUN_00574110_guess("Found noreverb.txt, disabling reverb.");
        g_noReverb_00988de4_guess = 1;
    }
    if (g_argCount_00988ddc_guess > 0) {
        for (i = 0; i < g_argCount_00988ddc_guess; i++) {
            if (_strnicmp(g_args_00985fc0_guess[i], "solo", 4) == 0) {
                g_solo_00988dd4_guess = 1;
            } else if (_stricmp(g_args_00985fc0_guess[i], "tutorial") == 0) {
                g_tutorial_00988dd8_guess = 1;
            } else {
                continue;
            }
            if (i >= 0) {
                for (; i < g_argCount_00988ddc_guess; i++) {
                    strcpy(g_args_00985fc0_guess[i], g_args_00985fc0_guess[i + 1]);
                }
                g_argCount_00988ddc_guess--;
            }
            break;
        }
    }
    FUN_00574110_guess("Initializing WinSock.");
    WSADATA wsaData_guess;
    if (FUN_0057f6a6_guess(0x101, &wsaData_guess) != 0) {
        MessageBoxA(0, "Unable to initialize WinSock", "EverQuest", 0x40000);
        exit(0);
    }
    FUN_00574110_guess("Enumerating 3D devices.");
    g_graphics_0099e38c_guess->FUN_00609d90_guess(instance_guess);
    if (g_graphics_0099e38c_guess->deviceCount_guess == 0) {
        MessageBoxA(0, "No 3D devices found", "EverQuest", 0x40000);
        exit(0);
    }
    init_mm_guess();
    FUN_004b385e_guess();
    LoadKeyboardTables_guess();
    WNDCLASSA windowClass_guess;
    windowClass_guess.style = 3;
    windowClass_guess.lpfnWndProc = eqWndProc;
    windowClass_guess.cbClsExtra = 0;
    windowClass_guess.cbWndExtra = 0;
    windowClass_guess.hInstance = instance_guess;
    windowClass_guess.hIcon = 0;
    windowClass_guess.hCursor = LoadCursorA(0, IDC_ARROW);
    windowClass_guess.hbrBackground = (HBRUSH)GetStockObject(4);
    windowClass_guess.lpszMenuName = 0;
    windowClass_guess.lpszClassName = "_EverQuestwndclass";
    if (RegisterClassA(&windowClass_guess) == 0) {
        exit(0);
    }
    FUN_00574110_guess("Creating window.");
    g_mainWindow_00988c24_guess = CreateWindowExA(0x40000, "_EverQuestwndclass", "EverQuest", 0x90000000,
        0, 0, 100, 0x28, 0, 0, instance_guess, 0);
    if (g_mainWindow_00988c24_guess == 0) {
        exit(0);
    }
    g_window_009889bc_guess = g_mainWindow_00988c24_guess;
    g_instance_00985db0_guess = instance_guess;
    FUN_00574110_guess("Checking display driver version.");
    memset(g_driverInfo_00904000_guess, 0, 0x20c);
    g_driverValue_00904204_guess = 9000;
    g_driverValue_00904208_guess = 0;
    g_deviceList_00986fc0_guess.deviceCount_guess = g_graphics_0099e38c_guess->deviceCount_guess;
    g_deviceList_00986fc0_guess.window_guess = g_window_009889bc_guess;
    g_deviceList_00986fc0_guess.ready_guess = 1;
    for (i = 0; i < 16; i++) {
        strcpy(g_deviceList_00986fc0_guess.names_guess[i], g_graphics_0099e38c_guess->devices_guess[i].name_guess);
    }
    if (g_locale_00923d74_guess == 0) {
        g_GetEngineInfo_0099e378_guess(&g_engineInfo_0099e354_guess);
        KeyboardOwner_guess owner_guess(instance_guess, g_mainWindow_00988c24_guess,
            g_engineInfo_0099e354_guess->value48_guess, g_engineInfo_0099e354_guess->name_guess,
            g_engineInfo_0099e354_guess->value4c_guess, g_engineInfo_0099e354_guess->value38_guess,
            g_engineInfo_0099e354_guess->value3c_guess, g_engineInfo_0099e354_guess->value40_guess,
            g_engineInfo_0099e354_guess->value44_guess);
    }
    g_savedEngine_00987970_guess = g_engineValue_0099e358_guess;
    g_savedEngine_00987974_guess = g_engineInfo_0099e354_guess;
    g_savedGraphics_00987978_guess = g_graphics_0099e38c_guess;
    FUN_00574110_guess("Activating window.");
    ShowWindow(g_mainWindow_00988c24_guess, 5);
    UpdateWindow(g_mainWindow_00988c24_guess);
    return 1;
}

struct LogFontA_guess {
    int height_guess; // +0x00
    int width_guess; // +0x04
    int escapement_guess; // +0x08
    int orientation_guess; // +0x0c
    int weight_guess; // +0x10
    unsigned char italic_guess; // +0x14
    unsigned char underline_guess; // +0x15
    unsigned char strikeOut_guess; // +0x16
    unsigned char charSet_guess; // +0x17
    unsigned char outPrecision_guess; // +0x18
    unsigned char clipPrecision_guess; // +0x19
    unsigned char quality_guess; // +0x1a
    unsigned char pitchAndFamily_guess; // +0x1b
    char faceName_guess[32]; // +0x1c
};

typedef int (__stdcall *EnumFontProc_guess)(const LogFontA_guess*, const void*, unsigned long, long);
typedef void* (__stdcall *GetDCFunction_guess)(void*);
typedef int (__stdcall *EnumFontFamiliesExAFunction_guess)(void*, const LogFontA_guess*, EnumFontProc_guess, unsigned long, unsigned long);
typedef int (__stdcall *ReleaseDCFunction_guess)(void*, void*);

#define g_GetDC_0063f27c_guess EQ_GLOBAL(GetDCFunction_guess, 0x0063F27C)
#define g_EnumFontFamiliesExA_0063f024_guess EQ_GLOBAL(EnumFontFamiliesExAFunction_guess, 0x0063F024)
#define g_ReleaseDC_0063f278_guess EQ_GLOBAL(ReleaseDCFunction_guess, 0x0063F278)

int __stdcall AddFontFamilyCallback_guess(const LogFontA_guess* logFont, const void* metrics, unsigned long type, long param);

struct ChunkSlot_guess {
    int field00_guess; // +0x00
    // EXTERNAL: TITANIUM 0x00571F70 ChunkSlot_guess::FUN_00571f70_guess
    void FUN_00571f70_guess(void* value_guess);
};

struct ChunkedTable_guess {
    int count_guess; // +0x00
    int unknown04_guess; // +0x04
    int mask_guess; // +0x08
    int shift_guess; // +0x0c
    ChunkSlot_guess** chunks_guess; // +0x10
    int unknown14_guess; // +0x14
    unsigned char enabled_guess; // +0x18
    ChunkSlot_guess& At_guess(int index_guess) {
        return chunks_guess[index_guess >> shift_guess][index_guess & mask_guess];
    }
    // EXTERNAL: TITANIUM 0x00405C81 ChunkedTable_guess::AssureStr_guess
    void AssureStr_guess(int count_guess);
    // EXTERNAL: TITANIUM 0x00405F79 ChunkedTable_guess::SetElementIdxStr_guess
    void SetElementIdxStr_guess(int index_guess, void* value_guess);
    void Insert_guess(int index_guess, void* value_guess);
};

// Inserts a copy of the string at `index`: at or past the end it is a plain set (0x00405F79), otherwise
// the table grows by one (0x00405C81) and the later strings move up a slot. Negative indexes and a failed
// allocation are ignored. The font list keeps its names sorted with it.
// FUNCTION: TITANIUM 0x004CF77A
void ChunkedTable_guess::Insert_guess(int index_guess, void* value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= count_guess) {
            SetElementIdxStr_guess(index_guess, value_guess);
        } else {
            AssureStr_guess(count_guess + 1);
            if (enabled_guess != 0) {
                for (int i_guess = count_guess; i_guess > index_guess; --i_guess) {
                    At_guess(i_guess).FUN_00571f70_guess(&At_guess(i_guess - 1));
                }
                At_guess(index_guess).FUN_00571f70_guess(value_guess);
                ++count_guess;
            }
        }
    }
}

struct StringEdit97_guess {
    // EXTERNAL: TITANIUM 0x00572130 StringEdit97_guess::FUN_00572130_guess
    void FUN_00572130_guess(int first_guess, int second_guess);
};

#define g_fontTable_00988e10_guess EQ_GLOBAL(ChunkedTable_guess, 0x00988E10)

// Adds each font family once, in order, to the table 0x988E10; vertical fonts lose their leading '@'.
// FUNCTION: TITANIUM 0x004CF817
int __stdcall AddFontFamilyCallback_guess(const LogFontA_guess* logFont, const void* metrics, unsigned long type, long param) {
    CXStr name_guess;
    name_guess = logFont->faceName_guess;
    if (((Reader_guess*)&name_guess)->Read_guess(0) == '@') {
        ((StringEdit97_guess*)&name_guess)->FUN_00572130_guess(0, 1);
    }
    ChunkedTable_guess& table_guess = g_fontTable_00988e10_guess;
    if (!((CheckerList_guess*)&table_guess)->Check_guess((Checker_guess*)&name_guess)) {
        for (int i_guess = 0;; ++i_guess) {
            if (i_guess < table_guess.count_guess) {
                if (((Checker_guess*)&name_guess)->Check_guess((int)&table_guess.At_guess(i_guess))) {
                    table_guess.Insert_guess(i_guess, &name_guess);
                    break;
                }
            } else {
                table_guess.SetElementIdxStr_guess(table_guess.count_guess, &name_guess);
                break;
            }
        }
    }
    return 1;
}

// Fills the font family table 0x00988E10 (through 0x004CF817) with every family the window's device
// context offers, in any character set (DEFAULT_CHARSET).
// FUNCTION: TITANIUM 0x004CF8ED
void __cdecl EnumerateFonts_guess(void* window_guess) {
    LogFontA_guess logFont_guess;
    logFont_guess.charSet_guess = 1;
    logFont_guess.faceName_guess[0] = '\0';
    logFont_guess.pitchAndFamily_guess = 0;
    void* dc_guess = g_GetDC_0063f27c_guess(window_guess);
    g_EnumFontFamiliesExA_0063f024_guess(dc_guess, &logFont_guess, AddFontFamilyCallback_guess, 0, 0);
    g_ReleaseDC_0063f278_guess(window_guess, dc_guess);
}

struct GraphicsObject_guess {
    void* vtable_guess; // +0x00
    char unknown04_guess[0x828]; // +0x04
    int unknown82c_guess; // +0x82c
    char unknown830_guess[0x0c]; // +0x830
    // EXTERNAL: TITANIUM 0x00609940 GraphicsObject_guess::FUN_00609940_guess
    void FUN_00609940_guess();
};

#define g_tickBase_00988c20_guess EQ_GLOBAL(unsigned int, 0x00988C20)
#define g_timezone_0079af50_guess EQ_GLOBAL(int, 0x0079AF50)
#define g_timerScale_00988c68_guess EQ_GLOBAL(unsigned __int64, 0x00988C68)
#define g_timerScaleHigh_00988c6c_guess EQ_GLOBAL(int, 0x00988C6C)
#define g_oleFailed_00988c79_guess EQ_GLOBAL(unsigned char, 0x00988C79)
#define g_quitMessage_00905d28_guess EQ_GLOBAL(int, 0x00905D28)
#define g_loopMessage_00988c2c_guess EQ_GLOBAL(unsigned char, 0x00988C2C)
#define g_lastResult_009873c8_guess EQ_GLOBAL(int, 0x009873C8)
#define g_login_00904004_guess EQ_ARRAY(char, 0x00904004)
#define g_password_00904084_guess EQ_ARRAY(char, 0x00904084)
#define g_serverHost_00904104_guess EQ_ARRAY(char, 0x00904104)
#define g_serverPort_00904184_guess EQ_ARRAY(char, 0x00904184)
#define g_serverName_0098754c_guess EQ_ARRAY(char, 0x0098754C)
#define g_accountName_guess EQ_ARRAY(char, 0x009873CC)
#define g_iniServerValue_0098764c_guess EQ_GLOBAL(int, 0x0098764C)
#define g_loginReady_00904208_guess EQ_GLOBAL(int, 0x00904208)
#define g_loginDelay_0098797c_guess EQ_GLOBAL(int, 0x0098797C)
#define g_pendingTime_00985840_guess EQ_GLOBAL(int, 0x00985840)
#define g_allocatedData_00851398_guess EQ_GLOBAL(void*, 0x00851398)
#define g_mainWindow_00988c24_guess EQ_GLOBAL(HWND, 0x00988C24)
typedef int (__cdecl *CpuSpeedFunction_guess)();
#define g_tickSlot1_0099e388_guess EQ_GLOBAL(CpuSpeedFunction_guess, 0x0099E388)
#define g_tickSlot2_0099e384_guess EQ_GLOBAL(CpuSpeedFunction_guess, 0x0099E384)

// EXTERNAL: TITANIUM 0x00576ED0 FUN_00576ed0_guess
void __cdecl FUN_00576ed0_guess(const char* path_guess);
// EXTERNAL: TITANIUM 0x00609680 FUN_00609680_guess
int __cdecl FUN_00609680_guess(const char* path_guess);
// EXTERNAL: TITANIUM 0x0060F81E FUN_0060f81e_guess
int __cdecl FUN_0060f81e_guess(int value_guess);
// EXTERNAL: TITANIUM 0x0060F3DC _isdigit
extern "C" int __cdecl _isdigit(int value_guess);
// EXTERNAL: TITANIUM 0x0060ECBC _time32_guess
extern "C" long __cdecl _time32_guess(long* value_guess);
struct InputRecord97_guess {
    int value_guess;
    int unknown04_guess[5];
};

// EXTERNAL: TITANIUM 0x00580720 DirectInput8Create
HRESULT WINAPI DirectInput8Create(HINSTANCE instance_guess, DWORD version_guess,
    REFIID interfaceId_guess, LPVOID* output_guess, LPUNKNOWN outer_guess);

struct EverQuestStartupState97_guess {
    char unknown00_guess[0xb50];
    int state_guess;
};

struct CharacterStartupFlags97_guess {
    char unknown00_guess[0x2d2c];
    unsigned char flag_guess;
};

struct CEverQuestStartupCalls97_guess : CEverQuest {
    // EXTERNAL: TITANIUM 0x004A3341 ??0CEverQuestStartupCalls97_guess@@QAE@PAUHWND__@@@Z
    CEverQuestStartupCalls97_guess(HWND window_guess);
    // EXTERNAL: TITANIUM 0x0049377D CEverQuestStartupCalls97_guess::Initialize_guess
    int Initialize_guess(void* config_guess, int startupArgument_guess);
    // EXTERNAL: TITANIUM 0x00497395 CEverQuestStartupCalls97_guess::~CEverQuestStartupCalls97_guess
    ~CEverQuestStartupCalls97_guess();
};

struct StartupWaitObject97_guess {
    virtual void Slot00_guess() = 0;
    virtual void Release_guess() = 0;
    // EXTERNAL: TITANIUM 0x0040BE64 StartupWaitObject97_guess::Stop_guess
    void Stop_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040BEAE StartupWaitObject97_guess::Wait_guess
    void Wait_guess(int milliseconds_guess);
};

struct StartupGlobal97_guess {
    // EXTERNAL: TITANIUM 0x00408D13 StartupGlobal97_guess::Initialize_guess
    void Initialize_guess();
};

// The crash packet CrashDetected sends (0x7E48 bytes, opcode 0x7825); BuildCrashReport_guess fills
// faultAddress_guess and report_guess.
struct CrashPacket_guess {
    int mode_guess; // +0x00
    unsigned char ready_guess; // +0x04
    unsigned char initialized_guess; // +0x05
    char unknown06_guess[0x40]; // +0x06
    char playerName_guess[0x40]; // +0x46
    char zoneName_guess[0x40]; // +0x86
    char faultAddress_guess[0x40]; // +0xc6
    char graphicsDll_guess[0x40]; // +0x106
    char report_guess[0x7D02]; // +0x146
};

#define g_crashPacket_00989528_guess EQ_GLOBAL(CrashPacket_guess, 0x00989528)
#define g_stackTop_00988c70_guess EQ_GLOBAL(char*, 0x00988C70)
#define g_skinPath_00850990_guess EQ_ARRAY(char, 0x00850990)
#define g_graphicsDllName_0099e148_guess EQ_ARRAY(char, 0x0099E148)
#define g_sendSystemInfo_009254ee_guess EQ_GLOBAL(char, 0x009254EE)
#define g_crashContext_00905d00_guess EQ_GLOBAL(CrashContextSource_guess*, 0x00905D00)
#define g_worldData_00905cc0_guess EQ_GLOBAL(WorldData_guess*, 0x00905CC0)
#define g_connection_00905ca0_guess EQ_GLOBAL(void*, 0x00905CA0)

// EXTERNAL: TITANIUM 0x0060ED40 strcmp
extern "C" int __cdecl strcmp(const char* first_guess, const char* second_guess);

// Runs RunGameAndShutdown_guess, and so the game, under __try. A 4 KB 0xCE-filled local marks the stack
// top for BuildCrashReport_guess (0x988C70); the crash packet is reset with mode 7. On an exception the
// filter writes the crash report into the packet; the handler adds the version, skin, graphics DLL,
// player, location, game state and system lines, offers to send the packet, shows memory.txt and exits.
// FUNCTION: TITANIUM 0x004CDD75
int __cdecl GuardedShutdown_guess() {
    char zoneName_guess[32];
    char line_guess[0x200];
    char processorText_guess[0x80];
    char cpuText_guess[0x80];
    char memoryText_guess[0x80];
    char stackMarker_guess[0x1000];
    MEMORYSTATUS memoryStatus_guess;
    SYSTEM_INFO systemInfo_guess;
    StatBuffer_guess stat_guess;
    memset(stackMarker_guess, 0xCE, 0x1000);
    memset(&g_crashPacket_00989528_guess, 0, 0x7E48);
    g_crashPacket_00989528_guess.ready_guess = 1;
    g_crashPacket_00989528_guess.initialized_guess = pinstCXWndManager_guess->FUN_005aef50_guess();
    g_crashPacket_00989528_guess.mode_guess = 7;
    g_stackTop_00988c70_guess = stackMarker_guess;
    __try {
        RunGameAndShutdown_guess();
    } __except (BuildCrashReport_guess(GetExceptionInformation(), g_crashPacket_00989528_guess.report_guess,
                    g_crashPacket_00989528_guess.faultAddress_guess),
        EXCEPTION_EXECUTE_HANDLER) {
        char* report_guess = g_crashPacket_00989528_guess.report_guess;
        FUN_00574110_guess("Fatal error occurred in mainthread! (Release Client #630)\n");
        strcat(report_guess, "Fatal error in mainthread! (Release Client #630)\n");
        FUN_00574110_guess("Client Version: %s %s", "Oct 31 2005", "10:33:37");
        sprintf(line_guess, "Client Version: %s %s\n", "Oct 31 2005", "10:33:37");
        strcat(report_guess, line_guess);
        FUN_00574110_guess("Skin Directory: %s\n", g_skinPath_00850990_guess);
        sprintf(line_guess, "Skin Directory: %s\n", g_skinPath_00850990_guess);
        strcat(report_guess, line_guess);
        if (strcmp(g_graphicsDllName_0099e148_guess, "~*RPE") != 0) {
            FUN_00574110_guess("Graphics DLL Loaded: %s", g_graphicsDllName_0099e148_guess);
            sprintf(line_guess, "Graphics DLL Loaded: %s\n", g_graphicsDllName_0099e148_guess);
            strcat(report_guess, line_guess);
            strcpy(g_crashPacket_00989528_guess.graphicsDll_guess, g_graphicsDllName_0099e148_guess);
            FUN_00574110_guess("Graphics Build Date: %s %s", g_engineInfo_0099e354_guess->buildDate_guess,
                g_engineInfo_0099e354_guess->buildTime_guess);
            sprintf(line_guess, "Graphics Build Date: %s %s\n", g_engineInfo_0099e354_guess->buildDate_guess,
                g_engineInfo_0099e354_guess->buildTime_guess);
            strcat(report_guess, line_guess);
        } else {
            FUN_00574110_guess("Graphics DLL NOT Loaded.\n");
        }
        sprintf(line_guess, "Video Card: %s, %d.%d.%d.%04d\n", g_engineInfo_0099e354_guess->name_guess,
            g_engineInfo_0099e354_guess->value38_guess, g_engineInfo_0099e354_guess->value3c_guess,
            g_engineInfo_0099e354_guess->value40_guess, g_engineInfo_0099e354_guess->value44_guess);
        if (g_sendSystemInfo_009254ee_guess != 0) {
            strcat(report_guess, line_guess);
        }
        FUN_00574110_guess(line_guess);
        if (g_crashContext_00905d00_guess != 0) {
            g_worldData_00905cc0_guess->FUN_005f6ed0_guess(
                ((CrashReportData_guess*)((int)g_crashContext_00905d00_guess +
                    g_crashContext_00905d00_guess->offsetSource_guess->dataOffset_guess))->zoneId_guess,
                zoneName_guess);
            FUN_00574110_guess("Crash (char = %s, zone = %s)\n",
                ((CrashReportData_guess*)((int)g_crashContext_00905d00_guess +
                    g_crashContext_00905d00_guess->offsetSource_guess->dataOffset_guess))->playerName_guess,
                zoneName_guess);
            strcpy(g_crashPacket_00989528_guess.playerName_guess,
                ((CrashReportData_guess*)((int)g_crashContext_00905d00_guess +
                    g_crashContext_00905d00_guess->offsetSource_guess->dataOffset_guess))->playerName_guess);
            strcpy(g_crashPacket_00989528_guess.zoneName_guess, zoneName_guess);
        }
        if (pinstLocalPlayer != 0) {
            FUN_00574110_guess("Local Player's World location at time of crash: %f, %f, %f.\n",
                (double)pinstLocalPlayer->Y, (double)pinstLocalPlayer->X, (double)pinstLocalPlayer->Z);
        }
        if (g_cleanupModeObject_00988df0_guess != 0) {
            FUN_00574110_guess("Gamestate at crash = %d\n", g_cleanupModeObject_00988df0_guess->mode_guess);
        }
        GetSystemInfo(&systemInfo_guess);
        memoryStatus_guess.dwLength = sizeof(MEMORYSTATUS);
        GlobalMemoryStatus(&memoryStatus_guess);
        sprintf(processorText_guess, "Processor: %d of type %d", systemInfo_guess.dwNumberOfProcessors,
            systemInfo_guess.dwProcessorType);
        sprintf(memoryText_guess, "Physical memory: %d Megs", (memoryStatus_guess.dwTotalPhys + 0xFFFFF) >> 20);
        sprintf(cpuText_guess, "CPU: %s %d", g_engineInfo_0099e354_guess->cpuName_guess,
            g_engineInfo_0099e354_guess->cpuSpeed_guess);
        g_errorServiceA_0099e364_guess->NotifyError_guess();
        g_errorServiceB_0099e368_guess->Shutdown_guess();
        sprintf(line_guess, "%s", processorText_guess);
        FUN_00574110_guess(line_guess);
        sprintf(line_guess, "%s", memoryText_guess);
        FUN_00574110_guess(line_guess);
        sprintf(line_guess, "%s\n", cpuText_guess);
        FUN_00574110_guess(line_guess);
        if (g_sendSystemInfo_009254ee_guess != 0) {
            sprintf(line_guess, "%s\n", processorText_guess);
            strcat(report_guess, line_guess);
            sprintf(line_guess, "%s\n", memoryText_guess);
            strcat(report_guess, line_guess);
            sprintf(line_guess, "%s\n", cpuText_guess);
            strcat(report_guess, line_guess);
        }
        CrashDetected(&g_connection_00905ca0_guess, 0x7825, &g_crashPacket_00989528_guess, 0x7E48, 1);
        Sleep(3000);
        ReleaseMouse_guess();
        DestroyWindow(g_mainWindow_00988c24_guess);
        if (_stat("memory.txt", &stat_guess) == 0) {
            HGLOBAL text_guess = GlobalAlloc(GPTR, stat_guess.st_size);
            if (text_guess == 0) {
                MessageBoxA(0, "You are out of memory.  Free up a few hundred more megs of space on your "
                    "hard drive and then try running EverQuest again.", "EverQuest", MB_TOPMOST);
            } else {
                KeyboardFile_guess* file_guess = fopen("memory.txt", "r");
                if (file_guess != 0) {
                    fread(text_guess, stat_guess.st_size, 1, file_guess);
                    MessageBoxA(0, (const char*)text_guess, "EverQuest", MB_TOPMOST);
                    fclose(file_guess);
                } else {
                    MessageBoxA(0, "You are out of memory.  Free up a few hundred more megs of space on "
                        "your hard drive and then try running EverQuest again.", "EverQuest", MB_TOPMOST);
                }
                GlobalFree(text_guess);
            }
        }
        if (g_graphics_0099e38c_guess != 0) {
            delete g_graphics_0099e38c_guess;
            g_graphics_0099e38c_guess = 0;
        }
        exit(0);
    }
    return 0;
}

typedef unsigned long (__stdcall *DirectInputRelease97_guess)(void* object_guess);

// ExecuteEverQuest (the Mac name, as in the earlier sibling decomp): DirectInput 8, keyboard and
// mouse, login, password and host from the first command-line words, 640x480, fonts, then a new
// CEverQuest and its main loop (GuardedShutdown_guess); input is torn down afterwards.
// FUNCTION: TITANIUM 0x004CF93C
// @early-stop: budget, structural ndiff=58
int __cdecl ExecuteEverQuest_guess(HINSTANCE instance_guess, HINSTANCE previousInstance_guess,
    const char* commandLine_guess, int showCommand_guess) {
    int result_guess;
    int mode_guess;
    unsigned char* entry_guess;
    int index_guess;
    size_t length_guess;
    HFILE file_guess;
    STARTUPINFOA startupInfo_guess;
    OFSTRUCT fileInfo_guess;
    StartupWaitObject97_guess* waitObject_guess;

    FUN_00574110_guess(EQ_ARRAY(char, 0x0064D950));
    if (DirectInput8Create((HINSTANCE)EQ_GLOBAL(void*, 0x00985DB0), 0x800,
        *EQ_ARRAY(GUID, 0x00663910), (LPVOID*)&g_directInput_00988c7c_guess, 0) < 0) {
        FUN_00574110_guess(EQ_ARRAY(char, 0x0064D934));
        return -1;
    }

    InitKeyboard_guess((void*)EQ_GLOBAL(void*, 0x009889BC));
    InitMouse_guess((void*)EQ_GLOBAL(void*, 0x009889BC), 0);
    SetForegroundWindow((HWND)EQ_GLOBAL(void*, 0x009889BC));
    SetFocus((HWND)EQ_GLOBAL(void*, 0x009889BC));
    g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
    FlushKeyboard_guess();
    g_mouseDevice_00988c84_guess->vtable_guess->Acquire_guess(g_mouseDevice_00988c84_guess);
    EQ_GLOBAL(int, 0x00905D28) = 0;
    InputRecord97_guess* record_guess = EQ_ARRAY(InputRecord97_guess, 0x009043E8);
    do {
        record_guess->value_guess = -1;
        ++record_guess;
    } while ((int)record_guess < (int)EQ_ARRAY(InputRecord97_guess, 0x00905BE8));

    if (EQ_GLOBAL(int, 0x00904208) == 0 && EQ_GLOBAL(int, 0x00988DDC) >= 3) {
        strcpy(EQ_ARRAY(char, 0x00904004), EQ_ARRAY(char, 0x00985FC0));
        strcpy(EQ_ARRAY(char, 0x00904084), EQ_ARRAY(char, 0x009860C0));
        strcpy(EQ_ARRAY(char, 0x00904104), EQ_ARRAY(char, 0x009861C0));
        strcpy(EQ_ARRAY(char, 0x00904184), EQ_ARRAY(char, 0x009863C0));
        length_guess = strlen(EQ_ARRAY(char, 0x00904184));
        if (length_guess < 0x19) {
            EQ_ARRAY(char, 0x00904184)[0] = 0;
        }
        if (EQ_GLOBAL(int, 0x00988DDC) >= 6) {
            EQ_GLOBAL(int, 0x00904208) = atoi(EQ_ARRAY(char, 0x009864C0));
        }
    }

    if (_stricmp(EQ_ARRAY(char, 0x00904004), EQ_ARRAY(char, 0x0064D92C)) == 0) {
        EQ_ARRAY(char, 0x00904004)[0] = 0;
    }
    if (_stricmp(EQ_ARRAY(char, 0x00904084), EQ_ARRAY(char, 0x0064D920)) == 0) {
        EQ_ARRAY(char, 0x00904084)[0] = 0;
    }
    EQ_GLOBAL(int, 0x0092379C) = 0x280;
    EQ_GLOBAL(int, 0x009237A0) = 0x1e0;
    FUN_004cca22_guess();
    InitializeCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x00903FC0));
    InitializeCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x00900800));
    InitializeCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x0090422C));
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064D90C));
    EnumerateFonts_guess((void*)EQ_GLOBAL(void*, 0x00988C24));
    FUN_00574110_guess(EQ_ARRAY(char, 0x0064D8F4));

    pEverQuest = new CEverQuestStartupCalls97_guess((HWND)EQ_GLOBAL(void*, 0x009889BC));
    result_guess = -1;
    if (((EverQuestStartupState97_guess*)pEverQuest)->state_guess == 1) {
        FUN_00574110_guess(EQ_ARRAY(char, 0x0064D8CC));
    }

    mode_guess = EQ_GLOBAL(int, 0x00924964);
    switch (mode_guess) {
    case 0:
        ((CharacterStartupFlags97_guess*)EQ_GLOBAL(void*, 0x00905D24))->flag_guess = 0;
        break;
    case 1:
    case 2:
        ((CharacterStartupFlags97_guess*)EQ_GLOBAL(void*, 0x00905D24))->flag_guess =
            EQ_GLOBAL(unsigned char, 0x00923C3C) != 0;
        break;
    }

    entry_guess = EQ_ARRAY(unsigned char, 0x0090424D);
    index_guess = 0;
    do {
        (&EQ_GLOBAL(unsigned char, 0x00904248))[index_guess] = 0;
        *entry_guess = 0;
        (&EQ_GLOBAL(int, 0x00904390))[index_guess] = 0;
        entry_guess += 0x40;
        ++index_guess;
    } while (entry_guess < EQ_ARRAY(unsigned char, 0x0090438D));
    EQ_GLOBAL(unsigned char, 0x009043A4) = 0;
    ((StartupGlobal97_guess*)EQ_ARRAY(char, 0x009232F0))->Initialize_guess();
    GetStartupInfoA(&startupInfo_guess);
    file_guess = OpenFile(EQ_ARRAY(char, 0x00988A00), &fileInfo_guess, 2);
    if (file_guess != HFILE_ERROR) {
        FUN_00574110_guess(EQ_ARRAY(char, 0x0064D8AC));
        CloseHandle((HANDLE)file_guess);
        ((EverQuestStartupState97_guess*)pEverQuest)->state_guess = 1;
    }

    if (pEverQuest != 0) {
        if (((EverQuestStartupState97_guess*)pEverQuest)->state_guess == 0) {
            result_guess = ((CEverQuestStartupCalls97_guess*)pEverQuest)->Initialize_guess(
                (void*)EQ_GLOBAL(void*, 0x00988C24), (int)instance_guess);
        }
        if (((EverQuestStartupState97_guess*)pEverQuest)->state_guess == 1) {
            delete (CEverQuestStartupCalls97_guess*)pEverQuest;
            pEverQuest = 0;
            waitObject_guess = (StartupWaitObject97_guess*)EQ_GLOBAL(void*, 0x00905CA0);
            if (waitObject_guess != 0) {
                waitObject_guess->Stop_guess(0);
                waitObject_guess->Wait_guess(10000);
                waitObject_guess->Release_guess();
                EQ_GLOBAL(void*, 0x00905CA0) = 0;
            }
            DeleteCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x00903FC0));
            DeleteCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x00900800));
            DeleteCriticalSection(&EQ_GLOBAL(CRITICAL_SECTION, 0x0090422C));
            return result_guess;
        }
        SetForegroundWindow((HWND)EQ_GLOBAL(void*, 0x009889BC));
        SetFocus((HWND)EQ_GLOBAL(void*, 0x009889BC));
        g_keyboardDevice_00988c80_guess->vtable_guess->Acquire_guess(g_keyboardDevice_00988c80_guess);
        FlushKeyboard_guess();
        GuardedShutdown_guess();
    }

    waitObject_guess = (StartupWaitObject97_guess*)EQ_GLOBAL(void*, 0x00905CA0);
    if (waitObject_guess != 0) {
        waitObject_guess->Stop_guess(0);
        waitObject_guess->Wait_guess(10000);
        waitObject_guess->Release_guess();
        EQ_GLOBAL(void*, 0x00905CA0) = 0;
    }
    ReleaseMouse_guess();
    ReleaseKeyboard_guess();
    if (g_directInput_00988c7c_guess != 0) {
        ((DirectInputRelease97_guess)g_directInput_00988c7c_guess->vtable_guess->slots00_guess[2])(
            g_directInput_00988c7c_guess);
        g_directInput_00988c7c_guess = 0;
    }
    return 1;
}
// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();
// EXTERNAL: TITANIUM 0x004B3709 FUN_004b3709_guess
void __cdecl FUN_004b3709_guess();
// EXTERNAL: TITANIUM 0x006098C0 FUN_006098c0_guess
void __cdecl FUN_006098c0_guess();
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();

// WinMain (g1's WinMain_guess is not applied): log, process ACL, graphics DLL (GraphicsDLL9, default
// EQGraphicsDX9.DLL; exit -42), CPU timer, CheckCriticalFiles_guess, then front end (RunFrontend_guess)
// and game (ExecuteEverQuest_guess) in turn until the front end quits.
// FUNCTION: TITANIUM 0x004CFD32
// @early-stop: budget, diff ndiff=347
int __stdcall WinMain_guess(HINSTANCE instance_guess, HINSTANCE previousInstance_guess,
    const char* commandLine_guess, int showCommand_guess) {
    int pollCount_guess = 0;
    char graphicsDll_guess[0x80];
    char serverCheck_guess[0x20];
    int cpuStart_guess;
    int cpuEnd_guess;
    int message_guess;
    int index_guess;
    long time_guess;
    int carry_guess;
    int useDefault_guess;
    char* digit_guess;
    char* login_guess;
    char* password_guess;
    int result_guess;

    FUN_00612662_guess("dbg.txt");
    FUN_00576ed0_guess(EQ_ARRAY(char, 0x0063FE5C));
    FUN_00612662_guess("Logs\\dbg.txt");
    FUN_00574110_guess("Starting EverQuest (Build %s %s)", "Oct 31 2005", "10:33:37");
    int timezone_guess = g_timezone_0079af50_guess;
    int absoluteTimezone_guess = timezone_guess;
    if (absoluteTimezone_guess < 0) {
        absoluteTimezone_guess = -absoluteTimezone_guess;
    }
    FUN_00574110_guess("Timezone: UTC%+dh%02dm", timezone_guess / -0xE10,
        (absoluteTimezone_guess % 0xE10) / 0x3C);
    RestrictProcessAccess_guess();
    char* errorText_guess = strstr(commandLine_guess, EQ_ARRAY(char, 0x0064DA6C));
    if (errorText_guess != 0) {
        WriteChecksumFile_guess(errorText_guess + 2);
        return 0;
    }

    g_tickBase_00988c20_guess = FUN_00576e80_guess();
    EQ_GLOBAL(unsigned char, 0x0099140D) = 0;
    EQ_GLOBAL(unsigned char, 0x0099140C) = 0;
    GraphicsObject_guess* graphicsObject_guess = new GraphicsObject_guess;
    if (graphicsObject_guess != 0) {
        graphicsObject_guess->FUN_00609940_guess();
        graphicsObject_guess->vtable_guess = EQ_ARRAY(void, 0x0064CA88);
    }
    g_graphics_0099e38c_guess = (GraphicsState_guess*)graphicsObject_guess;
    FUN_00574110_guess("Loading graphics DLL.");
    useDefault_guess = 1;
    FUN_0060be50_guess("Defaults", "GraphicsDLL9", "*NULL*", graphicsDll_guess, 0x80,
        ".\\eqclient.ini");
    if (graphicsDll_guess[0] == '*' && graphicsDll_guess[5] == '*') {
        strcpy(graphicsDll_guess, "EQGraphicsDX9.DLL");
        useDefault_guess = 0;
    }
    result_guess = FUN_00609680_guess(graphicsDll_guess);
    if (result_guess != 0 && useDefault_guess != 0) {
        strcpy(graphicsDll_guess, "EQGraphicsDX9.DLL");
        result_guess = FUN_00609680_guess(graphicsDll_guess);
        if (result_guess != 0) {
            FUN_00574110_guess("Failed to load graphics DLL in WinMain(), exiting!\n");
            MessageBoxA(0, "Failed to load the graphics DLL!", "Error", 0);
            delete (char*)g_graphics_0099e38c_guess;
            exit(-0x2A);
        }
    }

    FUN_00574110_guess("Initializing timers.");
    g_timerStart_00988c60_guess = 0;
    g_timerStart_00988c60_guess = CyclesSinceStart_guess();
    cpuStart_guess = g_tickSlot1_0099e388_guess();
    cpuEnd_guess = g_tickSlot2_0099e384_guess();
    result_guess = FUN_0060f81e_guess(cpuEnd_guess - cpuStart_guess);
    if (result_guess < cpuStart_guess / 0x32) {
        g_timerScale_00988c68_guess = cpuEnd_guess;
    } else {
        g_timerScale_00988c68_guess = cpuStart_guess;
        FUN_00574110_guess("Psh (%d).\n", FUN_0060f81e_guess(cpuEnd_guess - cpuStart_guess));
    }
    memset(EQ_ARRAY(char, 0x00923770), 0, 0x6215C);
    CheckCriticalFiles_guess(commandLine_guess, instance_guess);
    if (CoInitialize(0) < 0) {
        FUN_00574110_guess("OLE initialization failed.\n");
        g_oleFailed_00988c79_guess = 1;
    }

    while (1) {
        message_guess = RunFrontend_guess();
        g_pendingTime_00985840_guess = 0;
        if (message_guess == -1 || (pollCount_guess > 0 && message_guess == 0)) {
            break;
        }
        g_loopMessage_00988c2c_guess = (unsigned char)message_guess;
        if (message_guess != 0) {
            result_guess = _isdigit((int)g_accountName_guess[0]);
            if (result_guess != 0) {
                unsigned int serverLength_guess = strlen(g_accountName_guess);
                if (serverLength_guess < 0x1E) {
                    time_guess = _time32_guess(0);
                    carry_guess = time_guess % 10;
                    digit_guess = serverCheck_guess + 1;
                    serverCheck_guess[0] = (char)carry_guess + '0';
                    if (_isdigit((int)g_accountName_guess[0]) != 0) {
                        index_guess = (int)g_accountName_guess - (int)digit_guess;
                        do {
                            carry_guess = (digit_guess[index_guess] - '0' + carry_guess) % 10;
                            *digit_guess = (char)carry_guess + '0';
                            ++digit_guess;
                        } while (_isdigit((int)digit_guess[index_guess]) != 0);
                    }
                    *digit_guess = '\0';
                    // Logs the account digits summed with the time's last digit, mod 10 each: a scrambled id.
                    FUN_00574110_guess("Server selected %s (%s).", g_serverName_0098754c_guess,
                        serverCheck_guess);
                }
            }
            strcpy(g_login_00904004_guess, g_accountName_guess);
            strcpy(g_password_00904084_guess, EQ_ARRAY(char, 0x0098744C));
            strcpy(g_serverHost_00904104_guess, g_serverName_0098754c_guess);
            strcpy(g_serverPort_00904184_guess, EQ_ARRAY(char, 0x009875CC));
            if (strlen(g_serverPort_00904184_guess) < 0x19) {
                g_serverPort_00904184_guess[0] = '\0';
            }
            ((GraphicsObject_guess*)g_graphics_0099e38c_guess)->unknown82c_guess =
                g_iniServerValue_0098764c_guess;
            if (_stricmp(g_login_00904004_guess, "login") == 0) {
                g_login_00904004_guess[0] = '\0';
            }
            if (_stricmp(g_password_00904084_guess, "password") == 0) {
                g_password_00904084_guess[0] = '\0';
            }
            login_guess = g_login_00904004_guess;
            password_guess = g_password_00904084_guess;
            if (strlen(login_guess) != 0 && strlen(password_guess) != 0) {
                g_loginReady_00904208_guess = 1;
            }
            if (g_loginDelay_0098797c_guess > 0) {
                result_guess = FUN_0046d655_guess();
                g_pendingTime_00985840_guess = result_guess + g_loginDelay_0098797c_guess * 1000;
            }
        }
        g_lastResult_009873c8_guess = ExecuteEverQuest_guess(instance_guess, previousInstance_guess,
            commandLine_guess, showCommand_guess);
        MaximizeOrRestoreWindow_guess(1);
        if (g_quitMessage_00905d28_guess == 1) {
            FUN_00574110_guess(EQ_ARRAY(char, 0x0064D96C));
            break;
        }
        ++pollCount_guess;
        if (message_guess == 0) {
            break;
        }
    }

    if (g_allocatedData_00851398_guess != 0) {
        free(g_allocatedData_00851398_guess);
        g_allocatedData_00851398_guess = 0;
    }
    FUN_004b3709_guess();
    CoUninitialize();
    DestroyWindow(g_mainWindow_00988c24_guess);
    FUN_006098c0_guess();
    if (g_graphics_0099e38c_guess != 0) {
        delete (char*)g_graphics_0099e38c_guess;
        g_graphics_0099e38c_guess = 0;
    }
    ExitProcess(0);
}

