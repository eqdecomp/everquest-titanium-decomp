// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 90: a hint from compare/tumap.py.
// The target indicator: a ring under the target coloured by con level, and markers on the assist target
// and marked NPCs, set up from TargetIndicator.ini (UI dir, else UIFiles\Default). TargetIndicator_guess
// (0x985CE4) holds 6 con effects and 4 marker effects of 0xAC bytes (Elem_guess = TargetIndicatorEffect_guess =
// ResourceHolder_guess) and 5 drawn rings (Resource_guess: +0x2C target, +0x30 assist, +0x34.. marks).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <winsock2.h>
#include <windows.h>
#include <new>

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory);

struct Resource_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess(void* from, float a, float b, unsigned char* color, float c, int d) = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess(Resource_guess* value) = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess(char value) = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Release_guess() = 0;
};

struct Owner_guess {
    char pad00[0x30];
    Resource_guess* field30_guess; // 0x30
    Resource_guess* fields34_guess[3]; // 0x34, 0x38, 0x3c

    void ReleaseSlot_guess(Resource_guess* value);
    void ReleaseAll_guess();
};

struct Dispatch_guess {
    virtual int Slot00_guess() = 0;
    virtual int Slot01_guess() = 0;
    virtual int Slot02_guess() = 0;
    virtual int Slot03_guess() = 0;
    virtual int Slot04_guess() = 0;
    virtual int Slot05_guess() = 0;
    virtual int Slot06_guess() = 0;
    virtual int Slot07_guess() = 0;
    virtual int Slot08_guess() = 0;
    virtual int Slot09_guess() = 0;
    virtual int Slot10_guess() = 0;
    virtual int Slot11_guess() = 0;
    virtual int Slot12_guess() = 0;
    virtual int Slot13_guess() = 0;
    virtual int Slot14_guess() = 0;
    virtual int Slot15_guess() = 0;
    virtual int Slot16_guess() = 0;
    virtual int Slot17_guess(void* first, void* second, int third, int fourth) = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess(Resource_guess* value) = 0;
};

struct ResourceList_guess {
    int count_guess;
    Resource_guess** data_004_guess;
    int unknown_008_guess;
    char pad_00c_guess[0x9c];
    // EXTERNAL: TITANIUM 0x004EB924 ResourceList_guess::At_guess
    Resource_guess** At_guess(int index);
    void Clear_guess();
    ~ResourceList_guess() { Clear_guess(); }
};

struct ResourceHolder_guess {
    char pad00[4];
    ResourceList_guess list04_guess; // 0x04

    ResourceHolder_guess() {}
    void ReleaseAll_guess();
    void* Delete_guess(unsigned char flags);
    ~ResourceHolder_guess();
};

struct ResourceArrayPrefix_guess {
    int count_guess;
};

struct DtorCallback_guess {
    // EXTERNAL: TITANIUM 0x004C871C DtorCallback_guess::Invoke_guess
    void Invoke_guess();
};

// EXTERNAL: TITANIUM 0x0060D6E5 VectorDtorIterator_guess
void __stdcall VectorDtorIterator_guess(void* array, unsigned int size, int count,
    void (DtorCallback_guess::*callback)());

struct CallbackOwner_guess {
    int Invoke_guess(void* value);
};

#define g_dispatch_guess EQ_GLOBAL(Dispatch_guess*, 0x0099E360)

typedef unsigned long (__stdcall *GetTickCountFunction_guess)();
#define g_getTickCount_guess EQ_GLOBAL(GetTickCountFunction_guess, 0x0063F180)

struct TickSource_guess {
    char pad00_guess[0x64]; // 0x00
    float base64_guess; // 0x64
    char pad68_guess[0x28]; // 0x68
    float value90_guess; // 0x90
    float value94_guess; // 0x94
    float value98_guess; // 0x98
    char pad9c_guess[8]; // 0x9c
    unsigned long ticka4_guess; // 0xa4

    void RestartGrow_guess();
};

// Restarts an effect's grow animation: length = InitialLength - fade span (+0x94 - +0x64), clock now.
// FUNCTION: TITANIUM 0x004C7F78
void TickSource_guess::RestartGrow_guess() {
    value98_guess = value94_guess - base64_guess;
    value90_guess = 0.0f;
    ticka4_guess = g_getTickCount_guess();
}

// Loads a texture file through the render device (0x99E360, slot 17); returns its handle.
// FUNCTION: TITANIUM 0x004C805F
int CallbackOwner_guess::Invoke_guess(void* value) {
    return g_dispatch_guess->Slot17_guess(value, value, 0, 1);
}

struct ResourceFactory_guess {
    virtual Resource_guess* Create_guess();
};

#define g_resourceFactory_guess EQ_GLOBAL(ResourceFactory_guess*, 0x0099E348)

// Readies a ring for a new spawn: creates it (factory 0x99E348) or clears it, and restarts `timer`.
// FUNCTION: TITANIUM 0x004C8113
void __stdcall ResetRing_guess(Resource_guess** resource, TickSource_guess* timer) {
    if (g_resourceFactory_guess != 0) {
        if (*resource != 0) {
            (*resource)->Release_guess();
        } else {
            *resource = g_resourceFactory_guess->Create_guess();
        }
        timer->RestartGrow_guess();
    }
}

struct ResourceOwner_guess {
    char field00_guess; // 0x00
    char pad01_guess[0x2b]; // 0x01
    Resource_guess* resource2c_guess; // 0x2c
    Resource_guess* resources30_guess[4]; // 0x30

    void SetEnabled_guess(char value);
};

// Turns the indicator on or off; off hides and clears all five rings.
// FUNCTION: TITANIUM 0x004C8143
void ResourceOwner_guess::SetEnabled_guess(char value) {
    field00_guess = value;
    if (resource2c_guess != 0) {
        resource2c_guess->Slot10_guess(value);
        if (value == 0) {
            resource2c_guess->Release_guess();
        }
        Resource_guess** current = &resources30_guess[4];
        int count = 4;
        do {
            --current;
            (*current)->Slot10_guess(value);
            if (value == 0) {
                (*current)->Release_guess();
            }
            --count;
        } while (count != 0);
    }
}

// Releases a drawn ring, when there is one.
// FUNCTION: TITANIUM 0x004C818C
void Owner_guess::ReleaseSlot_guess(Resource_guess* value) {
    if (value != 0) {
        value->Release_guess();
    }
}

// Clears the three mark rings, then the assist ring.
// FUNCTION: TITANIUM 0x004C819C
void Owner_guess::ReleaseAll_guess() {
    Resource_guess** current = &fields34_guess[0];
    int count = 3;
    do {
        ReleaseSlot_guess(*current);
        ++current;
        --count;
    } while (count != 0);
    ReleaseSlot_guess(field30_guess);
}

// Releases the effect's frame textures (0x99E360, slot 22).
// FUNCTION: TITANIUM 0x004C830A
void ResourceHolder_guess::ReleaseAll_guess() {
    int index = list04_guess.count_guess;
    while (index != 0) {
        --index;
        Resource_guess* value = *list04_guess.At_guess(index);
        g_dispatch_guess->Slot22_guess(value);
        *list04_guess.At_guess(index) = 0;
    }
    list04_guess.Clear_guess();
}

struct HolderPair_guess {
    char pad00[0x18];
    ResourceHolder_guess* field18_guess; // 0x18
    ResourceHolder_guess* field1c_guess; // 0x1c

    void ReleaseEffectTextures_guess();
};

// Releases con effect 0 six times and marker effect 0 four times, never the others; the vector deletes in
// Cleanup_guess free those. Matches the binary as written: don't index it.
// FUNCTION: TITANIUM 0x004C8448
void HolderPair_guess::ReleaseEffectTextures_guess() {
    int count = 6;
    do {
        field18_guess->ReleaseAll_guess();
        --count;
    } while (count != 0);
    count = 4;
    do {
        field1c_guess->ReleaseAll_guess();
        --count;
    } while (count != 0);
}

// Effect holder destructor: releases everything it holds.
// FUNCTION: TITANIUM 0x004C871C
ResourceHolder_guess::~ResourceHolder_guess() {
    ReleaseAll_guess();
}

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* value);

// EXTERNAL: TITANIUM 0x0060D0D5 FreeObject_guess
extern "C" void __cdecl FreeObject_guess(void* value);

// Compiler vector deleting destructor for 0xAC-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x004C8812
void* ResourceHolder_guess::Delete_guess(unsigned char flags) {
    if ((flags & 2) != 0) {
        ResourceArrayPrefix_guess* array = (ResourceArrayPrefix_guess*)this - 1;
        VectorDtorIterator_guess(this, 0xac, array->count_guess,
            &DtorCallback_guess::Invoke_guess);
        if ((flags & 1) != 0) {
            FreeArray_guess(array);
        }
        return array;
    }
    this->~ResourceHolder_guess();
    if ((flags & 1) != 0) {
        FreeObject_guess(this);
    }
    return this;
}

struct CallbackSlot_guess {
    virtual void Invoke_guess() = 0;
};

struct TargetIndicator_guess {
    char flag00_guess; // 0x00
    char flag01_guess; // 0x01
    char pad02_guess[6];
    void* stored08_guess[4]; // 0x08
    ResourceHolder_guess* field18_guess; // 0x18
    ResourceHolder_guess* field1c_guess; // 0x1c
    int field20_guess; // 0x20
    char pad24_guess[8];
    CallbackSlot_guess* field2c_guess; // 0x2c
    Resource_guess* resources30_guess[4]; // 0x30

    TargetIndicator_guess();
    void Cleanup_guess();
};

// 6 con effects (Trivial to Deadly) and 4 marker effects (AssistMarker, Marker0-2).
// FUNCTION: TITANIUM 0x004C874B
TargetIndicator_guess::TargetIndicator_guess() {
    flag00_guess = 1;
    flag01_guess = 0;
    field20_guess = 0;
    field2c_guess = 0;
    field18_guess = new ResourceHolder_guess[6];
    field1c_guess = new ResourceHolder_guess[4];
    int count = 4;
    do {
        --count;
        resources30_guess[count] = 0;
        stored08_guess[count] = 0;
    } while (count != 0);
}

// Teardown: the +0x2C callback, rings cleared, effects freed. Not CBankWnd::Activate (Mac match).
// FUNCTION: TITANIUM 0x004C8860
void TargetIndicator_guess::Cleanup_guess() {
    if (field2c_guess != 0) {
        field2c_guess->Invoke_guess();
    }
    ((Owner_guess*)this)->ReleaseAll_guess();
    ((HolderPair_guess*)this)->ReleaseEffectTextures_guess();
    if (field18_guess != 0) {
        field18_guess->Delete_guess(3);
    }
    if (field1c_guess != 0) {
        field1c_guess->Delete_guess(3);
    }
}

struct ActorInfo_guess {
    char pad000_guess[0x180];
    void* slot180_guess[7]; // 0x180..0x198
};

struct LocalPlayer_guess {
    char pad000_guess[0x1a8];
    ActorInfo_guess* pActorInfo_guess; // 0x1a8
};

#define pLocalPlayer_guess EQ_GLOBAL(LocalPlayer_guess*, 0x00905CE4)
#define g_flag9859ec_guess EQ_GLOBAL(int, 0x009859EC)

// EXTERNAL: TITANIUM 0x004B424F GetMode_guess
extern "C" void* __stdcall GetMode_guess(int which);

union FloatBits_guess {
    int i;
    float f;
};

struct Value_guess {
    char pad00_guess[0x30];
    FloatBits_guess x30_guess; // 0x30
    FloatBits_guess y34_guess; // 0x34
    FloatBits_guess z38_guess; // 0x38
};

struct Pos_guess {
    int x;
    int y;
    float z;

    // EXTERNAL: TITANIUM 0x00435B55 Pos_guess::Length_guess
    float Length_guess(Pos_guess* other);
};

// EXTERNAL: TITANIUM 0x00610884 Sqrt_guess
double __cdecl Sqrt_guess(double value);

struct Range_guess {
    float low_guess;
    float high_guess;
    float low_square_guess;
    float high_square_guess;
    float span_guess;

    // EXTERNAL: TITANIUM 0x004C0B38 Range_guess::Fraction_guess
    float Fraction_guess(float value);
};

struct FloatRangeRef_guess {
    // EXTERNAL: TITANIUM 0x004C0AF7 FloatRangeRef_guess::Set_guess
    void Set_guess(float low, float high);
};

struct Clock_guess {
    // EXTERNAL: TITANIUM 0x00439F26 Clock_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x, float y, float z);
};

struct Classifier_guess;

struct RefreshGlobals_guess {
    Classifier_guess* classifier00_guess; // 0x00
    Value_guess* value04_guess; // 0x04
    char pad08_guess[0x1c];
    Clock_guess* clock24_guess; // 0x24
};

#define g_refreshGlobals_guess EQ_GLOBAL(RefreshGlobals_guess, 0x00905D00)
#define g_clock_guess (g_refreshGlobals_guess.clock24_guess)
#define g_half_guess EQ_GLOBAL(float, 0x006410BC)

struct TargetIni_guess {
    int pad00_guess[4]; // 0x00, 16 bytes; not a char array, so /GS does not move it next to the cookie

    // EXTERNAL: TITANIUM 0x005764E0 ??0TargetIni_guess@@QAE@PBD0@Z
    TargetIni_guess(const char* path, const char* section);
    // EXTERNAL: TITANIUM 0x005761D0 TargetIni_guess::~TargetIni_guess
    ~TargetIni_guess();
    // EXTERNAL: TITANIUM 0x005750A0 TargetIni_guess::GetBool_guess
    char GetBool_guess(const char* key, int defaultValue, int flags);
    // EXTERNAL: TITANIUM 0x00575070 TargetIni_guess::GetInt_guess
    int GetInt_guess(const char* key, int defaultValue, int flags);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatPath_guess
extern "C" void __cdecl FormatPath_guess(CXStr* output, const char* format, ...);

// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
extern "C" char __cdecl FileExists_guess(char* path);

struct Elem_guess {
    unsigned char b0_guess; // 0x00
    unsigned char b1_guess; // 0x01
    unsigned char b2_guess; // 0x02
    unsigned char b3_guess; // 0x03
    unsigned int count04_guess; // 0x04
    char pad08_guess[0x0c];
    unsigned int interval14_guess; // 0x14
    unsigned int index18_guess; // 0x18
    DWORD lastTick1c_guess; // 0x1c
    float f20_guess; // 0x20
    float rate24_guess; // 0x24
    float f28_guess; // 0x28
    char pad2c_guess[4];
    float rate30_guess; // 0x30
    float f34_guess; // 0x34
    char pad38_guess[0x14];
    float rate4c_guess; // 0x4c
    float accum50_guess; // 0x50
    Range_guess range54_guess; // 0x54
    Range_guess range68_guess; // 0x68
    FloatRangeRef_guess range7c_guess; // 0x7c
    char pad7d_guess[0x1b];
    float value98_guess; // 0x98
    float rate9c_guess; // 0x9c
    char pada0_guess[4];
    DWORD tickA4_guess; // 0xa4
    DWORD deltaA8_guess; // 0xa8

    void Load_guess(TargetIni_guess* ini, const char* section);
    void Animate_guess(Resource_guess* resource, char flag);
    bool DrawLayer_guess(Resource_guess* resource, Pos_guess* from, void* to, float a, float b, int c, float d);
};

struct IndicatorResource_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual int* GetData_guess() = 0;
    virtual void UpdateTargetRing_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void SetAdditive_guess(char value) = 0;
};

struct PointSettings_guess {
    int pointCount_guess;
    float position_guess[2];
};

struct ResourceTimer_guess {
    char pad00_guess[4]; // 0x00
    int count04_guess; // 0x04
    char pad08_guess[0x0c]; // 0x08
    unsigned int interval14_guess; // 0x14
    unsigned int index18_guess; // 0x18
    DWORD lastTick1c_guess; // 0x1c
    char pad20_guess[4]; // 0x20
    float rate24_guess; // 0x24
    float accum28_guess; // 0x28
    char pad2c_guess[4]; // 0x2c
    float rate30_guess; // 0x30
    float accum34_guess; // 0x34
    char pad38_guess[0x14]; // 0x38
    float rate4c_guess; // 0x4c
    float accum50_guess; // 0x50
    float min54_guess; // 0x54
    float max58_guess; // 0x58
    char pad5c_guess[8]; // 0x5c
    float offset64_guess; // 0x64
    char pad68_guess[0x14]; // 0x68
    FloatRangeRef_guess range7c_guess; // 0x7c
    char pad7d_guess[0x1b]; // 0x7d
    float value98_guess; // 0x98
    float rate9c_guess; // 0x9c
    char pada0_guess[4]; // 0xa0
    DWORD tickA4_guess; // 0xa4
    DWORD deltaA8_guess; // 0xa8
};

// Per-frame animation: next texture frame every +0x14 ms (or on `flag` when 0), texture scroll, twist and
// scale advance by their speeds, and the length grows by GrowSpeed until it reaches FadeStart.
// FUNCTION: TITANIUM 0x004C8340
// @early-stop: budget, diff ndiff=2
void Elem_guess::Animate_guess(Resource_guess* resource, char flag) {
    deltaA8_guess = GetTickCount() - tickA4_guess;
    DWORD now = GetTickCount();
    tickA4_guess = now;
    unsigned int elapsed = now - lastTick1c_guess;
    if (count04_guess != 0) {
        char bump;
        if (interval14_guess == 0) {
            bump = flag;
            lastTick1c_guess = now;
        } else {
            bump = elapsed > interval14_guess;
            if (bump) {
                lastTick1c_guess = now;
            }
        }
        if (bump) {
            ++index18_guess;
            if (index18_guess >= count04_guess) {
                index18_guess = 0;
            }
        }
        if (count04_guess <= index18_guess) {
        } else {
            Resource_guess** slot = ((ResourceList_guess*)&count04_guess)->At_guess(index18_guess);
            resource->Slot06_guess(*slot);
        }
    } else {
        resource->Slot06_guess(0);
    }
    float dt = (float)elapsed;
    f28_guess = dt * rate24_guess + f28_guess;
    f34_guess = dt * rate30_guess + f34_guess;
    accum50_guess = dt * rate4c_guess + accum50_guess;
    float v = (float)deltaA8_guess;
    v = v * rate9c_guess + value98_guess;
    value98_guess = v;
    if (v > range54_guess.low_guess) {
        range7c_guess.Set_guess(range54_guess.low_guess, range54_guess.high_guess);
    } else {
        range7c_guess.Set_guess(v, v + range54_guess.span_guess);
    }
}

// Draws one ring layer at `from`; alpha falls off with distance through the fade and opaque ranges.
// False when fully transparent.
// FUNCTION: TITANIUM 0x004C7FA0
// @early-stop: budget, structural ndiff=18
bool Elem_guess::DrawLayer_guess(Resource_guess* resource, Pos_guess* from, void* to, float a, float b, int c, float d) {
    (float&)to = from->Length_guess((Pos_guess*)to);
    float span = range68_guess.Fraction_guess((float)(Sqrt_guess((float&)to) + b));
    float fade = EQ_GLOBAL(float, 0x0063F4D0) - range54_guess.Fraction_guess((float)Sqrt_guess((float&)to));
    (int&)to = b0_guess;
    unsigned char alpha = (unsigned char)(int)(fade * span * (int&)to * d);
    unsigned char* color = (unsigned char*)&to;
    color[0] = b3_guess;
    color[1] = b2_guess;
    color[2] = b1_guess;
    color[3] = alpha;
    resource->Slot02_guess(from, b, f34_guess, color, (a + f28_guess) * f20_guess, c);
    return alpha != 0;
}

struct Reader_guess {
    // EXTERNAL: TITANIUM 0x00574E70 Reader_guess::Init_guess
    void Init_guess(CXStr& name);
    // EXTERNAL: TITANIUM 0x00575140 Reader_guess::GetFloat_guess
    float GetFloat_guess(const char* key, float def, int flags);
    // EXTERNAL: TITANIUM 0x00575070 Reader_guess::GetInt_guess
    int GetInt_guess(const char* key, int def, int flags);
    // EXTERNAL: TITANIUM 0x005751E0 Reader_guess::GetString_guess
    void GetString_guess(const char* key, CXStr* out, int flags);
};

#include "titanium/layouts/shared_classes.h"

struct ScaleSource238_guess {
    char pad00_guess[0x238];
    float heightOffset_0238_guess;
};

#define g_scaleSource238_guess EQ_GLOBAL(ScaleSource238_guess*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x005738B0 Format_guess
extern "C" void __cdecl Format_guess(CXStr* out, const char* fmt, ...);

struct ResourceCount_guess {
    int count_guess;

    // EXTERNAL: TITANIUM 0x0050319B ResourceCount_guess::Attach_guess
    void Attach_guess(int count, int* handle);
};

struct TargetIndicatorEffect_guess {
    char color_guess[4];
    ResourceCount_guess field04_guess;
    char pad08_guess[0x0c];
    int duration_guess;
    int field18_guess;
    DWORD tick_guess;
    float textureScale_guess;
    float textureSpeed_guess;
    float field28_guess;
    float twistFactor_guess;
    float twistSpeed_guess;
    float field34_guess;
    FloatRange_guess scaleRange_guess;
    float scaleSpeed_guess;
    float field50_guess;
    FloatRange_guess fadeRange_guess;
    FloatRange_guess opaqueRange_guess;
    char pad7c_guess[0x18];
    float initialLength_guess;
    float field98_guess;
    float growSpeed_guess;
    float floorOffset_guess;

    void Load_guess(Reader_guess* reader, CXStr& name);
};
// Reads one effect section: texture (default TargetIndicator; FrameCount numbered .tga frames, UI dir
// then UIFiles\Default), speeds, scale/fade/opaque ranges, ARGB, FloorOffset (x player +0x238).
// FUNCTION: TITANIUM 0x004C889C
// @early-stop: budget, structural ndiff=164
void TargetIndicatorEffect_guess::Load_guess(Reader_guess* reader, CXStr& name) {
    reader->Init_guess(name);
    CXStr texture("TargetIndicator");
    reader->GetString_guess("Texture", &texture, 0);
    field34_guess = 0.0f;
    twistFactor_guess = reader->GetFloat_guess("TwistFactor", 1.0f, 0);
    twistSpeed_guess = reader->GetFloat_guess("TwistSpeed", 1.0f, 0);
    int frames = reader->GetInt_guess("FrameCount", 0, 0);
    field18_guess = 0;
    duration_guess = reader->GetInt_guess("Duration", 0, 0);
    textureScale_guess = reader->GetFloat_guess("TextureScale", 1.0f, 0);
    textureSpeed_guess = reader->GetFloat_guess("TextureSpeed", 0.0f, 0);
    field28_guess = 0.0f;
    field50_guess = 0.0f;
    float scaleMax = reader->GetFloat_guess("ScaleMax", EQ_GLOBAL(float, 0x006410D0), 0);
    float scaleMin = reader->GetFloat_guess("ScaleMin", EQ_GLOBAL(float, 0x006410BC), 0);
    scaleRange_guess.Set_guess(scaleMin, scaleMax);
    scaleSpeed_guess = reader->GetFloat_guess("ScaleSpeed", 1.0f, 0);
    color_guess[0] = (char)reader->GetInt_guess("Alpha", 0xc0, 0);
    color_guess[1] = (char)reader->GetInt_guess("Red", 0xff, 0);
    color_guess[2] = (char)reader->GetInt_guess("Green", 0xff, 0);
    color_guess[3] = (char)reader->GetInt_guess("Blue", 0xff, 0);
    if (color_guess[0] == -1) {
        color_guess[0] = -1;
    }
    if (color_guess[1] == -1) {
        color_guess[1] = -1;
    }
    if (color_guess[2] == -1) {
        color_guess[2] = -1;
    }
    if (color_guess[3] == -1) {
        color_guess[3] = -1;
    }
    initialLength_guess = reader->GetFloat_guess("InitialLength", 1.0f, 0);
    field98_guess = initialLength_guess - fadeRange_guess.span_guess;
    growSpeed_guess = reader->GetFloat_guess("GrowSpeed", 1.0f, 0);
    float fadeEnd = reader->GetFloat_guess("FadeEnd", EQ_GLOBAL(float, 0x00644368), 0);
    float fadeStart = reader->GetFloat_guess("FadeStart", EQ_GLOBAL(float, 0x006410C8), 0);
    fadeRange_guess.Set_guess(fadeStart, fadeEnd);
    float opaqueEnd = reader->GetFloat_guess("OpaqueEnd", EQ_GLOBAL(float, 0x006410D0), 0);
    float opaqueStart = reader->GetFloat_guess("OpaqueStart", 1.0f, 0);
    opaqueRange_guess.Set_guess(opaqueStart, opaqueEnd);
    floorOffset_guess = reader->GetFloat_guess("FloorOffset", 1.0f, 0);
    floorOffset_guess = floorOffset_guess * g_scaleSource238_guess->heightOffset_0238_guess;
    ((ResourceHolder_guess*)this)->ReleaseAll_guess();
    CXStr file;
    if (frames < 1) {
        Format_guess(&file, "%s%s.tga", EQ_ARRAY(char, 0x00850990), (char*)texture);
        if (FileExists_guess((char*)file) == 0) {
            Format_guess(&file, "%s%s.tga", "UIFiles\\Default\\", (char*)texture);
        }
        int handle = ((CallbackOwner_guess*)this)->Invoke_guess((char*)file);
        if (handle != 0) {
            field04_guess.Attach_guess(field04_guess.count_guess, &handle);
        }
    } else {
        for (int i = 0; i < frames; ++i) {
            Format_guess(&file, "%s%s%d.tga", EQ_ARRAY(char, 0x00850990), (char*)texture, i);
            if (FileExists_guess((char*)file) == 0) {
                Format_guess(&file, "%s%s%d.tga", "UIFiles\\Default\\", (char*)texture, i);
            }
            int handle = ((CallbackOwner_guess*)this)->Invoke_guess((char*)file);
            if (handle != 0) {
                field04_guess.Attach_guess(field04_guess.count_guess, &handle);
            }
        }
    }
    field18_guess = 0;
    tick_guess = GetTickCount();
}

void Elem_guess::Load_guess(TargetIni_guess* ini, const char* section) {
    int alpha = ini->GetInt_guess("Alpha", 255, 0);
    int red = ini->GetInt_guess("Red", 255, 0);
    int green = ini->GetInt_guess("Green", 255, 0);
    int blue = ini->GetInt_guess("Blue", 255, 0);
    b0_guess = (unsigned char)alpha;
    b1_guess = (unsigned char)blue;
    b2_guess = (unsigned char)green;
    b3_guess = (unsigned char)red;
    f20_guess = (float)ini->GetInt_guess("Scale", 1, 0);
    f28_guess = (float)ini->GetInt_guess("Offset", 0, 0);
    f34_guess = (float)ini->GetInt_guess("Size", 1, 0);
    range54_guess.low_guess = (float)ini->GetInt_guess("FadeMin", 0, 0);
    range54_guess.high_guess = (float)ini->GetInt_guess("FadeMax", 100, 0);
    range68_guess.low_guess = (float)ini->GetInt_guess("RangeMin", 0, 0);
    range68_guess.high_guess = (float)ini->GetInt_guess("RangeMax", 100, 0);
    range54_guess.low_square_guess = range54_guess.low_guess * range54_guess.low_guess;
    range54_guess.high_square_guess = range54_guess.high_guess * range54_guess.high_guess;
    range54_guess.span_guess = range54_guess.high_guess - range54_guess.low_guess;
    range68_guess.low_square_guess = range68_guess.low_guess * range68_guess.low_guess;
    range68_guess.high_square_guess = range68_guess.high_guess * range68_guess.high_guess;
    range68_guess.span_guess = range68_guess.high_guess - range68_guess.low_guess;
    ini->GetBool_guess(section, 1, 0);
}

struct PointSink_guess;

struct SlotOwner_guess {
    char flag00_guess; // 0x00
    char flag01_guess; // 0x01
    char pad02_guess[6];
    void* stored08_guess[4]; // 0x08
    Elem_guess* elems18_guess; // 0x18
    Elem_guess* elems1c_guess; // 0x1c
    char pad20_guess[0x0c];
    Resource_guess* resource2c_guess; // 0x2c
    Resource_guess* resources30_guess[4]; // 0x30

    // EXTERNAL: TITANIUM 0x004C8537 SlotOwner_guess::UpdateTargetRing_guess
    void UpdateTargetRing_guess(unsigned int arg);
    void Place_guess(Resource_guess* resource, Elem_guess* elem, void* pos, void* value);
    void UpdateMarker_guess(unsigned int arg, int index, void* value);
    void Init_guess();
    PointSink_guess* BuildCircle_guess(Resource_guess* resource, float* position, float scale,
        unsigned int pointCount);
    void Process_guess(unsigned int arg);
};

struct PointSink_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Add_guess(float* point) = 0;
};

struct PointSource_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual PointSink_guess* Sink_guess() = 0;
};

// EXTERNAL: TITANIUM 0x0060F784 Cos_guess
extern "C" float __cdecl Cos_guess(double angle);

// EXTERNAL: TITANIUM 0x0060F6D4 Sin_guess
extern "C" float __cdecl Sin_guess(double angle);

#define g_twoPi_guess EQ_GLOBAL(double, 0x0064BAF8)
#define g_pi_guess EQ_GLOBAL(double, 0x0064BAF0)

// Ring geometry: `count` + 1 points on a circle of `radius`, starting at angle pi.
// FUNCTION: TITANIUM 0x004C8079
// @early-stop: budget, diff ndiff=2
PointSink_guess* SlotOwner_guess::BuildCircle_guess(Resource_guess* resource, float* center,
    float radius, unsigned int count) {
    PointSink_guess* sink = ((PointSource_guess*)resource)->Sink_guess();
    double step = g_twoPi_guess / (double)count;
    for (unsigned int i = 0; i <= count; ++i) {
        float angle = (double)i * step + g_pi_guess;
        float c = Cos_guess(angle);
        float y = Sin_guess(angle) * radius + center[1];
        float point[3];
        point[0] = c * radius + center[0];
        point[1] = y;
        point[2] = 0.0f;
        sink->Add_guess(point);
    }
    return sink;
}

// Loads TargetIndicator.ini: the target ring (Additive, PointCount default 16), con sections, then four
// marker rings. Each marker pass sets Additive on the target ring again, not on the new marker ring.
// FUNCTION: TITANIUM 0x004C8C95
// @early-stop: unknown, structural ndiff=88
void SlotOwner_guess::Init_guess() {
    flag01_guess = 1;
    CXStr section("TargetIndicator");
    CXStr path;
    FormatPath_guess(&path, "%s\\TargetIndicator.ini", EQ_ARRAY(char, 0x00850990));
    if (!FileExists_guess((char*)path)) {
        FormatPath_guess(&path, "%s\\TargetIndicator.ini", "UIFiles\\Default\\");
    }
    TargetIni_guess ini((char*)path, (char*)section);
    if (g_resourceFactory_guess == 0) {
        return;
    }

    if (resource2c_guess == 0) {
        resource2c_guess = g_resourceFactory_guess->Create_guess();
    } else {
        ((IndicatorResource_guess*)resource2c_guess)->UpdateTargetRing_guess();
    }
    {
        char additive = (char)(1 - (ini.GetBool_guess("Additive", 1, 0) != 0));
        ((IndicatorResource_guess*)resource2c_guess)->SetAdditive_guess(additive);
    }

    int pointCount = ini.GetInt_guess("PointCount", 0x10, 0);
    {
        float position[2] = { 0.0f, 0.0f };
        BuildCircle_guess(resource2c_guess, position, 1.0f, (unsigned int)pointCount);
    }

    // The binary's section loader is 0x4C889C (Texture, TwistFactor...); Elem_guess::Load_guess, with
    // other keys and no FUNCTION line, is probably a decomp stand-in.
    elems18_guess[0].Load_guess(&ini, "Trivial");
    elems18_guess[1].Load_guess(&ini, "VeryEasy");
    elems18_guess[2].Load_guess(&ini, "Easy");
    elems18_guess[3].Load_guess(&ini, "FairMatch");
    elems18_guess[4].Load_guess(&ini, "Difficult");
    elems18_guess[5].Load_guess(&ini, "Deadly");

    float markerPosition[2] = { 0.0f, 0.0f };
    {
        int elementCount = 4;
        Resource_guess** current = &resources30_guess[4];
        do {
            --current;
            if (*current == 0) {
                *current = g_resourceFactory_guess->Create_guess();
            } else {
                ((IndicatorResource_guess*)*current)->UpdateTargetRing_guess();
            }
            ((IndicatorResource_guess*)resource2c_guess)->SetAdditive_guess(
                (char)(1 - (ini.GetBool_guess("Additive", 1, 0) != 0)));
            BuildCircle_guess(*current, markerPosition, 1.0f, (unsigned int)pointCount);
            --elementCount;
        } while (elementCount != 0);
    }

    elems1c_guess[0].Load_guess(&ini, "AssistMarker");
    char markerName[256];
    {
        int markerIndex = 1;
        int markerOffset = 0xac;
        do {
            sprintf(markerName, "Marker%d", markerIndex - 1);
            Elem_guess* marker = elems1c_guess + markerOffset / sizeof(Elem_guess);
            marker->Load_guess(&ini, markerName);
            markerOffset += 0xac;
            ++markerIndex;
        } while (markerOffset <= 0x204);
    }
}

// Slash-command handler: string 0x3292 (probably "off") disables the indicator, 0x3293 ("on") enables
// it and reloads the ini.
// FUNCTION: TITANIUM 0x004C9051
void __cdecl do_indicator_guess(unsigned int unused, char* command) {
    if (EQ_GLOBAL(SlotOwner_guess*, 0x00985CE4) == 0 ||
        strcmp(command, EQ_ARRAY(char, 0x0063F53F)) == 0) {
        return;
    }

    if (_stricmp(command, pStringTable->getString(0x3292, 0)) == 0) {
        ((ResourceOwner_guess*)EQ_GLOBAL(SlotOwner_guess*, 0x00985CE4))->SetEnabled_guess(0);
    } else if (_stricmp(command, pStringTable->getString(0x3293, 0)) == 0) {
        ((ResourceOwner_guess*)EQ_GLOBAL(SlotOwner_guess*, 0x00985CE4))->SetEnabled_guess(1);
        ((SlotOwner_guess*)EQ_GLOBAL(SlotOwner_guess*, 0x00985CE4))->Init_guess();
    }
}

struct ScaleSource_guess {
    char pad00_guess[0x3c];
    float scale3c_guess; // 0x3c
};

struct PlaceSpec_guess {
    char pad00_guess[0x12c];
    ScaleSource_guess* scale12c_guess; // 0x12c
};

struct PlaceValue_guess {
    char pad00_guess[0x1a8];
    PlaceSpec_guess* spec1a8_guess; // 0x1a8
    char pad1ac_guess[0x238 - 0x1ac];
    float heightOffset_0238_guess; // 0x238
};

// Draws the ring as four layers, each 0.01 lower, at 0.5, 1, 1.5 and 1.8 x the spawn's size (+0x238
// times its model scale, at least 2).
// FUNCTION: TITANIUM 0x004C81C4
void SlotOwner_guess::Place_guess(Resource_guess* resource, Elem_guess* elem, void* pos, void* value) {
    resource->Release_guess();
    PlaceValue_guess* v = (PlaceValue_guess*)value;
    float scale = v->heightOffset_0238_guess;
    ScaleSource_guess* s = v->spec1a8_guess->scale12c_guess;
    if (s != 0) {
        scale *= s->scale3c_guess;
    }
    if (scale < 2.0f) {
        scale = 2.0f;
    }
    Pos_guess* p = (Pos_guess*)pos;
    Pos_guess local;
    elem->DrawLayer_guess(resource, p, p, 0.0f, scale * 0.5f, 0, 0.0f);
    local.x = p->x;
    local.y = p->y;
    local.z = p->z - 0.01f;
    elem->DrawLayer_guess(resource, &local, p, 0.25f, scale, 0, 1.0f);
    local.x = p->x;
    local.y = p->y;
    local.z = p->z - 0.02f;
    elem->DrawLayer_guess(resource, &local, p, 0.75f, scale * 1.5f, 0, 1.0f);
    local.x = p->x;
    local.y = p->y;
    local.z = p->z - 0.03f;
    elem->DrawLayer_guess(resource, &local, p, 1.0f, scale * 1.8f, 1, 0.0f);
}

// Marker `index` (0 assist, 1-3 marks) follows spawn `value`; a new spawn restarts the effect.
// FUNCTION: TITANIUM 0x004C846B
void SlotOwner_guess::UpdateMarker_guess(unsigned int arg, int index, void* value) {
    if (value == 0 || flag00_guess == 0) {
        ((Owner_guess*)this)->ReleaseSlot_guess(resources30_guess[index]);
        return;
    }
    Elem_guess* elem = elems1c_guess + index;
    bool changed = value != stored08_guess[index];
    if (changed) {
        ResetRing_guess(&resources30_guess[index], (TickSource_guess*)elem);
        stored08_guess[index] = value;
    }
    Resource_guess* resource = resources30_guess[index];
    if (resource != 0) {
        resource->Slot10_guess(1);
        Value_guess* v = (Value_guess*)value;
        float zf = g_clock_guess->GetFloorHeight_guess(v->x30_guess.f, v->y34_guess.f, v->z38_guess.f) + 0.5f;
        Pos_guess pos;
        pos.x = v->x30_guess.i;
        pos.y = v->y34_guess.i;
        pos.z = zf;
        Place_guess(resource, elem, &pos, value);
        elem->Animate_guess(resource, changed);
    }
}

#define g_value_guess (g_refreshGlobals_guess.value04_guess)

struct Classifier_guess {
    // EXTERNAL: TITANIUM 0x004BC20B Classifier_guess::Classify_guess
    int Classify_guess(Value_guess* value);
};

#define g_classifier_guess (g_refreshGlobals_guess.classifier00_guess)

struct PosF_guess {
    int x;
    float y;
    float z;
};

struct RefreshOwner_guess {
    char flag00_guess; // 0x00
    char pad01_guess[3];
    Value_guess* value04_guess; // 0x04
    char pad08_guess[0x10];
    Elem_guess* elems18_guess; // 0x18
    char pad1c_guess[4];
    int state20_guess; // 0x20
    char pad24_guess[8];
    Resource_guess* resource2c_guess; // 0x2c

    // EXTERNAL: TITANIUM 0x004C8113 RefreshOwner_guess::Init_guess
    void Init_guess(Resource_guess** resource, TickSource_guess* timer);
    void UpdateTargetRing_guess(unsigned int arg);
};

// Target ring: effect by con colour (0x4BC20B: 0-5 Trivial to Deadly), drawn just above the floor
// under the target (g_value_guess, 0x905D04).
// FUNCTION: TITANIUM 0x004C8537
// @early-stop: budget, diff ndiff=7
void RefreshOwner_guess::UpdateTargetRing_guess(unsigned int arg) {
    GetTickCount();
    if (g_value_guess == 0 || flag00_guess == 0) {
        ((Owner_guess*)this)->ReleaseSlot_guess(resource2c_guess);
        return;
    }
    bool changed = g_value_guess != value04_guess;
    if (changed) {
        value04_guess = g_value_guess;
    }
    switch (g_classifier_guess->Classify_guess(g_value_guess)) {
    case 0:
        state20_guess = 0;
        break;
    case 1:
        state20_guess = 1;
        break;
    case 2:
        state20_guess = 2;
        break;
    case 3:
        state20_guess = 3;
        break;
    case 4:
        state20_guess = 4;
        break;
    case 5:
        state20_guess = 5;
        break;
    // 6: no ring; hidden once when the target changes.
    case 6:
        if (!changed) {
            return;
        }
        resource2c_guess->Slot10_guess(0);
        ((Owner_guess*)this)->ReleaseSlot_guess(resource2c_guess);
        return;
    }
    Value_guess* v = g_value_guess;
    Elem_guess* elem = elems18_guess + state20_guess;
    FloatBits_guess* p = &v->x30_guess;
    if (changed) {
        Init_guess(&resource2c_guess, (TickSource_guess*)elem);
    }
    if (resource2c_guess != 0) {
        resource2c_guess->Slot10_guess(1);
        float zf = g_clock_guess->GetFloorHeight_guess(p[0].f, p[1].f, p[2].f) + g_half_guess;
        PosF_guess pos = { p[0].i, p[1].f, zf };
        ((SlotOwner_guess*)this)->Place_guess(resource2c_guess, elem, &pos, g_value_guess);
        elem->Animate_guess(resource2c_guess, changed);
    }
}

// Per frame: loads the ini once, draws the target ring, the assist marker (tu_073's assist target, mode
// 2, while 0x9859EC is set) and marks 1-3: the raid mark if set, else the group mark (actor info +0x18C,
// +0x180; tu_073 slots 7-9 and 4-6).
// FUNCTION: TITANIUM 0x004C8FDB
// @early-stop: budget, structural ndiff=26
void SlotOwner_guess::Process_guess(unsigned int arg) {
    if (flag01_guess == 0) {
        Init_guess();
    }
    UpdateTargetRing_guess(arg);
    ActorInfo_guess* info = pLocalPlayer_guess->pActorInfo_guess;
    if (info != 0) {
        int index = 1;
        if (g_flag9859ec_guess != 0) {
            void* mode = GetMode_guess(2);
            UpdateMarker_guess(arg, 0, mode);
        }
        void** current = &info->slot180_guess[3];
        do {
            void* value = *current;
            if (value == 0) {
                value = current[-3];
            }
            UpdateMarker_guess(arg, index, value);
            ++index;
            ++current;
        } while (index <= 3);
    }
}

// Destructor of the client's growable array: frees the element buffer (+4) and zeroes it, the
// capacity (+8) and the count (+0).
// FUNCTION: TITANIUM 0x0050F3F6
void ResourceList_guess::Clear_guess() {
    if (data_004_guess != 0) {
        FreeArray_guess(data_004_guess);
    }
    data_004_guess = 0;
    unknown_008_guess = 0;
    count_guess = 0;
}

