// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 238: a hint from compare/tumap.py.
// The CVideoModesWnd destructors (CVideoModesWndView_guess; its confirmation-dialog listener at +0x15C, vtable 0x63FD9C as
// in tu_236), then the camera shake started by OP_CameraEffect (tu_042). CameraShake_guess, GlobalRecord_guess
// and Jitter_guess are all views of the one shake object at 0x99CA00.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"

struct Primary_guess {
    char pad[0x15c];
    // EXTERNAL: TITANIUM 0x005A3100 ??1Primary_guess@@QAE@XZ
    ~Primary_guess();
};

struct ConfirmationListenerView_guess {
    virtual void Slot00_guess();
    virtual ~ConfirmationListenerView_guess() {
        Initialize_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 ConfirmationListenerView_guess::Initialize_guess
    void Initialize_guess(int value);
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7ConfirmationListenerView_guess@@6B@

struct CVideoModesWndView_guess : Primary_guess {
    char storage[4];
    ~CVideoModesWndView_guess();
    void* Delete_guess(unsigned char flags);
};

struct CameraShake_guess {
    unsigned value;
    unsigned tick;
    float time;
    void StartShake_guess(float time, unsigned value);
};

// EXTERNAL: TITANIUM 0x0046D655 GetTick_guess
int __cdecl GetTick_guess();

struct GlobalRecord_guess {
    unsigned first;
    unsigned second;
    float third;
    char pad[0xc];
};

#define g_globalRecord_guess EQ_GLOBAL(GlobalRecord_guess*, 0x0099CA00)

// EXTERNAL: TITANIUM 0x0060D071 Allocate_guess
void* __cdecl Allocate_guess(unsigned size);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Scalar deleting destructor of CVideoModesWnd.
// FUNCTION: TITANIUM 0x0056FBF6
void* CVideoModesWndView_guess::Delete_guess(unsigned char flags) {
    this->CVideoModesWndView_guess::~CVideoModesWndView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// CVideoModesWnd::~CVideoModesWnd: the listener base calls 0x5482A0 with -1, probably dropping its
// pending confirmations, before CSidlScreenWnd's destructor.
// FUNCTION: TITANIUM 0x0056FC12
CVideoModesWndView_guess::~CVideoModesWndView_guess() {
    ConfirmationListenerView_guess* p = this ? reinterpret_cast<ConfirmationListenerView_guess*>(storage) : 0;
    p->ConfirmationListenerView_guess::~ConfirmationListenerView_guess();
}

// Starts a shake (OP_CameraEffect: intensity `time`, duration `value` ms): a stronger or equal shake takes
// over the range and, if longer, the duration, restarting the clock.
// FUNCTION: TITANIUM 0x0056FC58
void CameraShake_guess::StartShake_guess(float time, unsigned value) {
    if (time >= this->time) {
        if (value > this->value) {
            this->value = value;
            this->tick = GetTick_guess();
        }
        this->time = time;
    }
}

// The shake object, created on first use (0x18 bytes); OP_CameraEffect and the camera update go through it.
// FUNCTION: TITANIUM 0x0056FC86
GlobalRecord_guess* GetCameraShake_guess() {
    GlobalRecord_guess* p = g_globalRecord_guess;
    if (p == 0) {
        p = (GlobalRecord_guess*)Allocate_guess(0x18);
        if (p != 0) {
            p->first = 0;
            p->second = 0;
            p->third = 0.0f;
        } else {
            p = 0;
        }
        g_globalRecord_guess = p;
    }
    return p;
}

struct Jitter_guess {
    unsigned left;    // +0x00
    unsigned tick;    // +0x04
    float range;      // +0x08
    float pos[3];     // +0x0C
    float* ApplyShake_guess(float* offset);
};

// Per frame, while time is left: returns `offset` (the camera position) moved by a random step of up to
// half the range on each axis, and counts the time down; at zero the shake ends.
// FUNCTION: TITANIUM 0x0056FCB1
// @early-stop: unknown, structural ndiff=25
float* Jitter_guess::ApplyShake_guess(float* offset) {
    if (left == 0) {
        return offset;
    }
    unsigned now = (unsigned)GetTick_guess();
    if (tick == 0) {
        tick = now;
    }
    // 3.0518e-5 is 1/32767: rand() scaled to 0..1, centred on 0.
    float x = ((float)rand() * 3.051851e-05f - 0.5f) * range;
    float y = ((float)rand() * 3.051851e-05f - 0.5f) * range;
    float z = ((float)rand() * 3.051851e-05f - 0.5f) * range;
    pos[0] = x + offset[0];
    pos[1] = y + offset[1];
    float zOffset = z + offset[2];
    pos[2] = zOffset;
    unsigned elapsed = now - tick;
    if (left < elapsed) {
        left = 0;
        range = 0.0f;
    } else {
        left -= elapsed;
    }
    tick = now;
    return pos;
}

