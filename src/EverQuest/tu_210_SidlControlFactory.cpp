// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 210: a hint from compare/tumap.py.
// Server popup windows and three SIDL window builders. Allocated_guess::Init_guess fills a popup from a
// record
// laid out like EQEmu's OnLevelMessage_Struct (title 128 bytes, text 4096); SendPopupResponse_guess answers
// it with OP_PopupResponse. The Build_guess functions create a window from its SIDL template and open it.
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"

#include "titanium/core_decls.h"
#define g_voidConnection_guess EQ_GLOBAL(int, 0x00905CA0)

// EXTERNAL: TITANIUM 0x00526574 FUN_00526574_guess
int __stdcall FUN_00526574_guess(int param_1, int param_2, int param_3);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

struct Handler_guess {
    // EXTERNAL: TITANIUM 0x004C26F4 Handler_guess::Process_guess
    void Process_guess(int value);
};

#define g_handler_guess EQ_GLOBAL(Handler_guess*, 0x00985C88)

#define g_vtable_guess EQ_GLOBAL(char, 0x0065C7E0)

struct VtableOwner_guess {
    void* vtable; // 0x0
    // EXTERNAL: TITANIUM 0x00525F6F VtableOwner_guess::Continue_guess
    void Continue_guess();
    void SetVtable_guess();
    // EXTERNAL: TITANIUM 0x00553773 VtableOwner_guess::Destroy_guess
    void Destroy_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct AtomicMember_guess {
    char storage[0x20];
    // EXTERNAL: TITANIUM 0x00571F70 AtomicMember_guess::Update_guess
    void Update_guess(void* value);
};

struct Container_guess {
    char prefix[0x78];
    AtomicMember_guess first;
    AtomicMember_guess second;
    void Refresh_guess(void* value);
};

struct Temp_guess {
    int values[4];
    // EXTERNAL: TITANIUM 0x004D911A Temp_guess::Temp_guess
    Temp_guess(const Temp_guess& value_guess);
};

struct Temp_argument_guess {
    int values[4];
    // EXTERNAL: TITANIUM 0x004D911A Temp_argument_guess::Temp_argument_guess
    Temp_argument_guess(const Temp_argument_guess& value_guess);
    ~Temp_argument_guess() {
    }
};

struct Input_guess {
    char prefix24[0x24];
    int value24;
    char prefix48[0x20];
    Temp_guess value48;
    char field58;
    char prefix59[7];
    unsigned int value60;
    char field64;
    char prefix65[7];
    unsigned char field6c;
    unsigned char field6d;
    unsigned char field6e;
    char field6f;
    int value70;
    int value74;
    int value78;
    int value7c;
    int value80;
};

struct FactoryInput_guess {
    char prefix24[0x24];
    int value24;
    char prefix48[0x20];
    Temp_argument_guess value48;
    char field58;
    char prefix59[7];
    unsigned int value60;
    char field64;
    char prefix65[7];
    unsigned char field6c;
    unsigned char field6d;
    unsigned char field6e;
    char field6f;
    int value70;
    int value74;
    int value78;
    int value7c;
    int value80;
};

struct LargeInput_guess {
    char prefix24[0x24];
    int value24;
    char prefix48[0x20];
    Temp_argument_guess value48;
    char field58;
    char prefix59[7];
    unsigned int value60;
    char field64;
    char prefix65[0xb];
    int value70;
    int value74;
    int value78;
    int value7c;
    int value80;
    int value84;
    int value88;
    int value8c;
    int value90;
    unsigned char field94;
    char prefix95[3];
    int value98;
    int value9c;
    int valuea0;
    int valuea4;
};

struct Str_guess {
    char* data_guess; // 0x0
    // EXTERNAL: TITANIUM 0x00571E00 ??0Str_guess@@QAE@PBD@Z
    Str_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 Str_guess::Str_guess
    Str_guess(const Str_guess& other_guess);
    // EXTERNAL: TITANIUM 0x00571D00 Str_guess::FreeRep
    void FreeRep(char* value_guess);
    ~Str_guess() {
        if (data_guess != 0) {
            FreeRep(data_guess);
        }
        data_guess = 0;
    }
};

struct StrArg_guess {
    char* data_guess; // 0x0
    // EXTERNAL: TITANIUM 0x00407D68 ??0StrArg_guess@@QAE@ABUStr_guess@@@Z
    StrArg_guess(const Str_guess& other_guess);
};

struct Flag_guess {
    unsigned char value_guess;
};

struct Info_guess {
    char name_guess[0x80];
    char text_guess[0x1000];
    unsigned char flag1080_guess;
    unsigned char flag1081_guess;
    int count_guess;
    int value1088_guess;
    int value108c_guess;
    int value1090_guess;
};

struct Allocated_guess {
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
    virtual void Open_guess(int first_guess, int second_guess);
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
    virtual void Set_guess(void* value_guess);
    char prefix65[0x61];
    unsigned char flags;
    char tail[0x11e];
    int value184_guess;
    int value188_guess;
    int value18c_guess;
    char tail2[0x18];
    // EXTERNAL: TITANIUM 0x005590FD Allocated_guess::Allocated_guess
    Allocated_guess(int first_guess, int second_guess, Temp_guess value_guess,
        int value70_guess, int value74_guess, int value78_guess,
        int value7c_guess, int value80_guess, int last_guess);
    // EXTERNAL: TITANIUM 0x00553925 Allocated_guess::Refresh_guess
    void Refresh_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x00525FBC Allocated_guess::Apply_guess
    void Apply_guess(Flag_guess first_guess, StrArg_guess text_guess, int count_guess,
        StrArg_guess name_guess, Flag_guess second_guess);
    void Init_guess(Info_guess* info_guess);
};

struct LargeAllocatedBase_guess {
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
};

struct CGaugeWnd_guess : LargeAllocatedBase_guess {
    virtual void Open_guess(int first_guess, int second_guess);
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
    virtual void Set_guess(void* value_guess);
    char prefix65[0x61];
    unsigned char flags;
    char tail[0x10e];
    // EXTERNAL: TITANIUM 0x005044F2 CGaugeWnd_guess::CGaugeWnd_guess
    CGaugeWnd_guess(int first_guess, int second_guess, Temp_argument_guess value_guess,
        int value70_guess, int value74_guess, int value78_guess, int value7c_guess,
        int value80_guess, int value84_guess, int value88_guess, int value8c_guess,
        int value90_guess, unsigned char value94_guess, int value98_guess, int value9c_guess,
        int valuea0_guess, int valuea4_guess);
};

struct Owner_guess {
    Allocated_guess* Build_guess(int first_guess, Input_guess* input_guess);
    CGaugeWnd_guess* Build_guess(int first_guess, LargeInput_guess* input_guess);
};

struct FactoryResult_guess {
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
    virtual void Open_guess(int first_guess, int second_guess);
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
    virtual void Set_guess(void* value_guess);
    char prefix64[0x60];
    unsigned int flags64_guess;
    char tail[0xc0];
    // EXTERNAL: TITANIUM 0x00525E53 FactoryResult_guess::FactoryResult_guess
    FactoryResult_guess(int first_guess, int second_guess,
        Temp_argument_guess value_guess, int value70_guess);
    // EXTERNAL: TITANIUM 0x005BD650 FactoryResult_guess::Set6c_guess
    void Set6c_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x005BD660 FactoryResult_guess::Set6d_guess
    void Set6d_guess(unsigned char value_guess);
    // EXTERNAL: TITANIUM 0x005BD670 FactoryResult_guess::Set6e_guess
    void Set6e_guess(unsigned char value_guess);
};

struct Factory_guess {
    FactoryResult_guess* Build_guess(int first_guess, FactoryInput_guess* input_guess);
};

struct Base_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005B7060 Base_guess::Base_guess
    Base_guess();
    // EXTERNAL: TITANIUM 0x005B71C0 Base_guess::~Base_guess
    ~Base_guess() ;
};

// EXTERNAL: TITANIUM 0x0065C924 ??_7Derived_guess@@6B@
struct Derived_guess : Base_guess {
    Derived_guess();
    ~Derived_guess() ;
};

// Destructor of the server popup window (vtable 0x65C7E0, ctor 0x00553747): restores its vtable and
// continues into the large dialog window's destructor (0x00525F6F).
// FUNCTION: TITANIUM 0x00553773
void VtableOwner_guess::SetVtable_guess() {
    vtable = &g_vtable_guess;
    Continue_guess();
}

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z
void __cdecl operator delete[](void* memory_guess);

// EXTERNAL: TITANIUM 0x00467441 ReplaceTokens_guess
void __cdecl ReplaceTokens_guess(char* dest_guess, const char* text_guess,
    const char** params_guess, int length_guess, int flags_guess);

// Expands the text's tokens into a 4 KB buffer, then shows title and text with the record's two flag bytes,
// its count (negative counts as 0; probably the duration) and the three dwords at +0x1088..+0x1090
// (kept at +0x184..+0x18C).
// FUNCTION: TITANIUM 0x0055377E
void Allocated_guess::Init_guess(Info_guess* info_guess) {
    char* buffer_guess = new char[0x1000];
    ReplaceTokens_guess(buffer_guess, info_guess->text_guess, 0, -1, 0);
    Str_guess name_guess(info_guess->name_guess);
    Str_guess text_guess(buffer_guess);
    delete[] buffer_guess;
    int count_guess = info_guess->count_guess < 0 ? 0 : info_guess->count_guess;
    Flag_guess first_guess;
    first_guess.value_guess = info_guess->flag1080_guess;
    Flag_guess second_guess;
    second_guess.value_guess = info_guess->flag1081_guess;
    value184_guess = info_guess->value1088_guess;
    value188_guess = info_guess->value108c_guess;
    value18c_guess = info_guess->value1090_guess;
    Apply_guess(first_guess, text_guess, count_guess, name_guess, second_guess);
}

// Sends OP_PopupResponse (8 bytes: popup id, button) to the world connection; a zero button sends nothing.
// FUNCTION: TITANIUM 0x00553886
void __stdcall SendPopupResponse_guess(int first_guess, int second_guess) {
    int payload[2];
    payload[0] = first_guess;
    payload[1] = second_guess;
    if (second_guess != 0) {
        EQSendMessage(&g_voidConnection_guess, OP_PopupResponse, payload, 8, 1);
    }
}

// Notification 1000 goes to the popup handler object; any other to the default handler.
// FUNCTION: TITANIUM 0x005538B9
int __stdcall HandleWndNotification_guess(int param_1, int param_2, int param_3) {
    if (param_2 == 1000) {
        g_handler_guess->Process_guess(param_3);
        return 0;
    }
    return FUN_00526574_guess(param_1, param_2, param_3);
}

// Scalar deleting destructor of the server popup window (vtable 0x65C7E0 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x005538DF
void* VtableOwner_guess::Delete_guess(unsigned char flags_guess) {
    Destroy_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// SIDL builders: assigns string `value` (the template's piece at +0x64) to both strings of the new
// window, +0x98 and +0x78 (0x00571F70). The generic, gauge and small-window builders call it.
// FUNCTION: TITANIUM 0x00553925
void Container_guess::Refresh_guess(void* value) {
    second.Update_guess(value);
    first.Update_guess(value);
}

// Constructor of the SIDL control factory (vtable 0x65C924) on its base (0x005B7060). Made once by the
// UI setup (0x0043AD1F).
// FUNCTION: TITANIUM 0x00553947
Derived_guess::Derived_guess() {
}

// Destructor of the SIDL control factory (vtable 0x65C924): runs the base destructor (0x005B71C0).
// FUNCTION: TITANIUM 0x00553959
Derived_guess::~Derived_guess()  {
}

// Generic SIDL builder: creates the window, copies the template's text and tooltip pieces (+0x58, +0x64),
// three flag bytes, opens it and adds the template style.
// FUNCTION: TITANIUM 0x00553964
FactoryResult_guess* Factory_guess::Build_guess(int first_guess, FactoryInput_guess* input_guess) {
    FactoryResult_guess* result_guess = new FactoryResult_guess(first_guess, input_guess->value24,
        input_guess->value48, input_guess->value70);
    result_guess->Set_guess(&input_guess->field58);
    ((Container_guess*)result_guess)->Refresh_guess(&input_guess->field64);
    result_guess->Set6c_guess(input_guess->field6c);
    result_guess->Set6d_guess(input_guess->field6d);
    result_guess->Set6e_guess(input_guess->field6e);
    result_guess->Open_guess(1, 1);
    result_guess->flags64_guess |= input_guess->value60;
    return result_guess;
}

// Gauge builder (CGaugeWnd_guess family): `first_guess` and 16 template fields to the ctor; style bit 4 is
// set before opening.
// FUNCTION: TITANIUM 0x00553A19
CGaugeWnd_guess* Owner_guess::Build_guess(int first_guess, LargeInput_guess* input_guess) {
    CGaugeWnd_guess* result_guess = new CGaugeWnd_guess(first_guess, input_guess->value24,
        input_guess->value48, input_guess->value70, input_guess->value74,
        input_guess->value78, input_guess->value7c, input_guess->value80,
        input_guess->value84, input_guess->value88, input_guess->value8c,
        input_guess->value90, input_guess->field94, input_guess->value98,
        input_guess->value9c, input_guess->valuea0, input_guess->valuea4);
    if (result_guess != 0) {
        result_guess->flags |= 4;
        result_guess->Open_guess(1, 1);
        result_guess->Set_guess(&input_guess->field58);
        ((Container_guess*)result_guess)->Refresh_guess(&input_guess->field64);
    }
    return result_guess;
}

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// The same for the smaller window class: `first_guess`, seven template fields and a zero, style bit 4, then
// open.
// FUNCTION: TITANIUM 0x00553AF4
Allocated_guess* Owner_guess::Build_guess(int first_guess, Input_guess* input_guess) {
    Allocated_guess* result_guess = new Allocated_guess(first_guess, input_guess->value24,
        input_guess->value48, input_guess->value70, input_guess->value74,
        input_guess->value78, input_guess->value7c, input_guess->value80, 0);
    if (result_guess != 0) {
        result_guess->flags |= 4;
        result_guess->Open_guess(1, 1);
        result_guess->Set_guess(&input_guess->field58);
        result_guess->Refresh_guess(&input_guess->field64);
    }
    return result_guess;
}
