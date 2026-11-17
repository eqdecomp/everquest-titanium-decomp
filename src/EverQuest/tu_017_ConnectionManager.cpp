// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 17: a hint from compare/tumap.py.
// The client's network connection manager: one UDP manager (+0x4C) created on first use from eqclient.ini
// [Networking] PortBase/PortRange, connections opened per zone and closed with a pending-byte drain, and a
// closure count that tears the manager down when the last connection closes. Logs use "Networking:".
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include <windows.h>

typedef void (__stdcall *DeleteCriticalSection_guess)(void*);
#define gDeleteCriticalSection_guess EQ_GLOBAL(DeleteCriticalSection_guess, 0x0063F11C)
#define gCriticalSectionCount_guess EQ_GLOBAL(long, 0x0099CA3C)
#define gConnectionTerminatedFormat_guess EQ_ARRAY(char, 0x00641320)

// Atomic increment/decrement of a counter; the result (counter reached zero) is computed but unused.
// as original: `xor ebx,ebx; lock inc|dec [eax]; setz bl; mov [local],ebx` with EBX saved around it is an
// inline asm block (the tu_007 AtomicIncrement_guess block of 0x00407D68); VC7.1 has no intrinsic that emits
// `lock inc` (_InterlockedIncrement is `lock xadd`, InterlockedIncrement an import call).
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

inline int AtomicDecrement_guess(long* counter) {
    int zero;
    __asm {
        xor ebx, ebx
        mov eax, counter
        lock dec dword ptr [eax]
        setz bl
        mov zero, ebx
    }
    return zero;
}

struct CriticalSectionLock_guess {
    CRITICAL_SECTION section_guess; // 0x00
    long field18_guess; // 0x18
    CriticalSectionLock_guess();
    // EXTERNAL: TITANIUM 0x005E49A0 CriticalSectionLock_guess::Enter_guess
    void Enter_guess();
    // EXTERNAL: TITANIUM 0x005E49B0 CriticalSectionLock_guess::Leave_guess
    void Leave_guess();
    ~CriticalSectionLock_guess();
};

struct CriticalSectionOwner_guess {
    char pad00[0x28];
    CriticalSectionLock_guess lock_guess; // 0x28
    void Destroy_guess();
};

struct NetConfig_guess {
    // EXTERNAL: TITANIUM 0x0040BD15 NetConfig_guess::NetConfig_guess
    NetConfig_guess();
    int pad00_guess[2];
    int portBase_guess; // 0x08
    int portRange_guess; // 0x0c
    int field10_guess; // 0x10
    int field14_guess; // 0x14
    int pad18_guess;
    int field1c_guess; // 0x1c
    int field20_guess; // 0x20
    int pad24_guess;
    int field28_guess; // 0x28
    int field2c_guess; // 0x2c
    int field30_guess; // 0x30
    int field34_guess; // 0x34
    int field38_guess; // 0x38
    int pad3c_guess;
    int field40_guess; // 0x40
    int field44_guess; // 0x44
    char field48_guess; // 0x48
    char pad49_guess[3];
    int field4c_guess; // 0x4c
    int pad50_guess[0x10];
    int field90_guess; // 0x90
    int field94_guess; // 0x94
    int field98_guess; // 0x98
    int pad9c_guess[0x2d];
    int field150_guess; // 0x150
    int pad154_guess[2];
    char field15c_guess; // 0x15c
    char pad15d_guess[3];
    int pad160_guess;
    int field164_guess; // 0x164
    int field168_guess; // 0x168
    int pad16c_guess;
};

struct Connection_guess;

struct ValueOwner_guess {
    char pad00[0x10];
    int value_guess; // 0x10
    char pad14[0x248];
    CriticalSectionLock_guess lock_guess; // 0x25c
    char pad278[0x138];
    // EXTERNAL: TITANIUM 0x005E9D70 ValueOwner_guess::ValueOwner_guess
    ValueOwner_guess(const NetConfig_guess& config_guess);
    // EXTERNAL: TITANIUM 0x005E9A00 ValueOwner_guess::Open_guess
    void Open_guess();
    // EXTERNAL: TITANIUM 0x005E8810 ValueOwner_guess::GetPort_guess
    int GetPort_guess();
    // EXTERNAL: TITANIUM 0x005EA440 ValueOwner_guess::Connect_guess
    Connection_guess* Connect_guess(const char* zone_guess, int port_guess, int flags_guess);
    void SetValue_guess(int value_guess);
};

// EXTERNAL: TITANIUM 0x0060BE50 IniRead_guess
void __cdecl IniRead_guess(const char* section_guess, const char* key_guess, const char* default_guess,
    char* buffer_guess, int size_guess, const char* file_guess);

struct ValueOwner2_guess {
    char pad00[0x158];
    int value_guess; // 0x158
    char pad15c[0xc8];
    CriticalSectionLock_guess lock_guess; // 0x224
    int GetValue_guess();
};

// Counts the live critical sections in gCriticalSectionCount_guess.
// FUNCTION: TITANIUM 0x00424B38
CriticalSectionLock_guess::CriticalSectionLock_guess() {
    InitializeCriticalSection(&section_guess);
    AtomicIncrement_guess(&gCriticalSectionCount_guess);
    field18_guess = 0;
}

// Also lowers the global count of live critical sections (0x99CA3C).
// FUNCTION: TITANIUM 0x00424B5F
CriticalSectionLock_guess::~CriticalSectionLock_guess() {
    DeleteCriticalSection(&section_guess);
    AtomicDecrement_guess(&gCriticalSectionCount_guess);
}

// Destroys the critical section at +0x28.
// FUNCTION: TITANIUM 0x00424C0D
void CriticalSectionOwner_guess::Destroy_guess() {
    lock_guess.~CriticalSectionLock_guess();
}

// Sets the value under the lock.
// FUNCTION: TITANIUM 0x00424B7C
void ValueOwner_guess::SetValue_guess(int value_guess) {
    lock_guess.Enter_guess();
    this->value_guess = value_guess;
    lock_guess.Leave_guess();
}

// Reads the value under the lock.
// FUNCTION: TITANIUM 0x00424BA0
int ValueOwner2_guess::GetValue_guess() {
    lock_guess.Enter_guess();
    int value_guess = this->value_guess;
    lock_guess.Leave_guess();
    return value_guess;
}

struct LockedValueOwner_guess {
    char pad00[0x88];
    int value88_guess; // 0x88
    char pad8c[0xd0];
    int value15c_guess; // 0x15c
    char pad160[0xc4];
    CriticalSectionLock_guess lock_guess; // 0x224
    int GetValue_guess();
    void SetValue_guess(int value_guess);
};

// Reads +0x15C under the lock: the server-side end of the connection, logged as "server:%s".
// FUNCTION: TITANIUM 0x00424BC3
int LockedValueOwner_guess::GetValue_guess() {
    lock_guess.Enter_guess();
    int value_guess = this->value15c_guess;
    lock_guess.Leave_guess();
    return value_guess;
}

// Sets +0x88 under the lock (1 marks the connection terminated).
// FUNCTION: TITANIUM 0x00424BE6
void LockedValueOwner_guess::SetValue_guess(int value_guess) {
    lock_guess.Enter_guess();
    this->value88_guess = value_guess;
    lock_guess.Leave_guess();
}

struct CallbackTarget_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    // EXTERNAL: TITANIUM 0x0040BEAE CallbackTarget_guess::Reset_guess
    void Reset_guess(int value_guess);
};

struct ClosureResource_guess {
    // EXTERNAL: TITANIUM 0x005E94B0 ClosureResource_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x005E9AA0 ClosureResource_guess::Finish_guess
    void Finish_guess();
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};

struct ClosureOwner_guess {
    char pad00[0x4c];
    ClosureResource_guess* resource_guess; // 0x4c
    char pad50[4];
    int closureCount_guess; // 0x54
    void Close_guess();
    void AdjustClosureCount_guess();
    char WaitForDisconnect_guess(Connection_guess* connection_guess, int limit_guess);
    void CloseConnection_guess(Connection_guess** connection_guess);
};

// First base at offset 0. Its own vtable is stored by its constructor.
// EXTERNAL: TITANIUM 0x00641358 ??_7ConnectionBase_guess@@6B@
struct ConnectionBase_guess {
    virtual void Slot00_guess();
    char pad04_guess[4];
    struct Counters_guess {
        int v_guess[8];
        Counters_guess() {
            v_guess[0] = 0; v_guess[1] = 0; v_guess[2] = 0; v_guess[3] = 0;
            v_guess[4] = 0; v_guess[5] = 0; v_guess[6] = 0; v_guess[7] = 0;
        }
    } counters08_guess; // 0x08
    CriticalSectionLock_guess lock28_guess; // 0x28
    char pad44_guess[4]; // 0x44..0x47
    ConnectionBase_guess();
};

// Empty constructor.
// FUNCTION: TITANIUM 0x00424EC3
ConnectionBase_guess::ConnectionBase_guess() {}

// Second base at offset 0x48: empty, only its vtable.
// EXTERNAL: TITANIUM 0x0063FFE4 ??_7ClosureBase_guess@@6B@
struct ClosureBase_guess {
    virtual void Slot00_guess();
};

// EXTERNAL: TITANIUM 0x00641380 ??_7ConnectionManager_guess@@6BConnectionBase_guess@@@
// EXTERNAL: TITANIUM 0x0064136C ??_7ConnectionManager_guess@@6BClosureBase_guess@@@
// EXTERNAL: TITANIUM 0x005E5AF0 ValueToString_guess
const char* __cdecl ValueToString_guess(int value_guess);

// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format_guess, ...);

struct ConnectionManager_guess : ConnectionBase_guess, ClosureBase_guess {
    ValueOwner_guess* field4c_guess; // 0x4c
    int timeout_guess; // 0x50
    int field54_guess; // 0x54
    ConnectionManager_guess();
    ~ConnectionManager_guess();
    void Start_guess();
    Connection_guess* Connect_guess(const char* zone_guess, int port_guess, int flags_guess);
};

// Creates the UDP manager once: 128 KB buffers, the connection timeout (+0x50, 3 minutes), 15 s and 60 s
// timers and other fixed tuning. PortBase 0 lets the system pick the port; otherwise it is picked at random
// in PortBase..PortBase+PortRange-1.
// FUNCTION: TITANIUM 0x00424C15
void ConnectionManager_guess::Start_guess() {
    if (field4c_guess == 0) {
        NetConfig_guess config_guess;
        char buffer_guess[10];
        config_guess.field15c_guess = 1;
        IniRead_guess("Networking", "PortBase", EQ_ARRAY(char, 0x006410A8), buffer_guess, 10, ".\\eqclient.ini");
        config_guess.portBase_guess = atoi(buffer_guess);
        IniRead_guess("Networking", "PortRange", EQ_ARRAY(char, 0x006410A8), buffer_guess, 10, ".\\eqclient.ini");
        config_guess.portRange_guess = atoi(buffer_guess);
        config_guess.field20_guess = 0;
        config_guess.field14_guess = 0x20000;
        config_guess.field10_guess = 0x20000;
        config_guess.field2c_guess = timeout_guess;
        config_guess.field30_guess = timeout_guess;
        config_guess.field94_guess = 400;
        config_guess.field98_guess = 400;
        config_guess.field38_guess = 0x96;
        config_guess.field1c_guess = 15000;
        config_guess.field28_guess = 60000;
        config_guess.field34_guess = 0x10000000;
        config_guess.field40_guess = 0x200;
        config_guess.field44_guess = 10;
        config_guess.field48_guess = 1;
        config_guess.field4c_guess = 30000;
        config_guess.field90_guess = 100000;
        config_guess.field164_guess = 2;
        config_guess.field150_guess = 1;
        config_guess.field168_guess = 1;
        field4c_guess = new ValueOwner_guess(config_guess);
        field4c_guess->SetValue_guess((int)this);
        field4c_guess->Open_guess();
        if (config_guess.portBase_guess == 0) {
            Log_guess("Networking: using port [%d].", field4c_guess->GetPort_guess());
        } else {
            Log_guess("Networking: port [%d] was randomly selected in range [%d..%d].",
                field4c_guess->GetPort_guess(), config_guess.portBase_guess,
                config_guess.portRange_guess + config_guess.portBase_guess - 1);
        }
    }
}

// Shuts the UDP manager down (three of its virtual calls), forgets it and zeroes the closure count.
// FUNCTION: TITANIUM 0x00424DE3
void ClosureOwner_guess::Close_guess() {
    if (this->resource_guess != 0) {
        this->resource_guess->Prepare_guess();
        this->resource_guess->Finish_guess();
        this->resource_guess->Slot01_guess();
        this->resource_guess = 0;
    }
    this->closureCount_guess = 0;
}

// One connection fewer; at zero (or an already broken count, which is logged) the manager is closed.
// FUNCTION: TITANIUM 0x00424E0C
void ClosureOwner_guess::AdjustClosureCount_guess() {
    int count_guess = this->closureCount_guess;
    if (count_guess <= 0) {
        Log_guess("Networking: Adjusted closure count [%d].", count_guess);
        this->Close_guess();
        this->closureCount_guess = 0;
    } else {
        --count_guess;
        this->closureCount_guess = count_guess;
        if (count_guess == 0) {
            this->Close_guess();
            return;
        }
    }
}

// Callback: resets the target, then releases it (vtable slot 1).
// FUNCTION: TITANIUM 0x00424E3E
void __stdcall FUN_00424e3e_guess(CallbackTarget_guess* target_guess) {
    target_guess->Reset_guess(0);
    target_guess->Slot01_guess();
}

#define gDispatchId_guess EQ_GLOBAL(int, 0x00905CA0)
#define gDispatcher_guess EQ_GLOBAL(DispatchObject_guess*, 0x00988DF0)

struct DispatchObject_guess {
    // EXTERNAL: TITANIUM 0x0045B8F0 DispatchObject_guess::HandleWorldMessage_guess
    void HandleWorldMessage_guess(int identifier_guess, unsigned short value_guess,
        unsigned short* next_guess, int length_guess);
};

// Received data for the current connection (id 0x905CA0) goes to the world message handler: first word is
// the opcode, the rest the payload.
// FUNCTION: TITANIUM 0x00424E57
void __stdcall DispatchReceivedMessage_guess(int identifier_guess, unsigned short* data_guess, int length_guess) {
    if (identifier_guess == gDispatchId_guess) {
        gDispatcher_guess->HandleWorldMessage_guess(identifier_guess, *data_guess, data_guess + 1, length_guess - 2);
    }
}

// Marks the connection terminated and logs both ends.
// FUNCTION: TITANIUM 0x00424E86
void __stdcall OnConnectionTerminated_guess(LockedValueOwner_guess* owner_guess) {
    owner_guess->SetValue_guess(1);
    Log_guess(gConnectionTerminatedFormat_guess,
        ValueToString_guess(((ValueOwner2_guess*)owner_guess)->GetValue_guess()),
        ValueToString_guess(owner_guess->GetValue_guess()));
}

struct Connection_guess {
    // EXTERNAL: TITANIUM 0x0040BE8B Connection_guess::GetState_guess
    int GetState_guess();
    // EXTERNAL: TITANIUM 0x0040BE64 Connection_guess::SetState_guess
    void SetState_guess(int state_guess);
    // EXTERNAL: TITANIUM 0x0040BEAE Connection_guess::Flush_guess
    void Flush_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E53D0 Connection_guess::GetPending_guess
    int GetPending_guess();
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};

// EXTERNAL: TITANIUM 0x0040C194 GetClockStamp_guess
__int64 __cdecl GetClockStamp_guess();
// EXTERNAL: TITANIUM 0x0040C1E2 ClockElapsed_guess
int __cdecl ClockElapsed_guess(__int64 value_guess);
// EXTERNAL: TITANIUM 0x00600E40 FUN_00600e40_guess
void __cdecl FUN_00600e40_guess(int milliseconds_guess);

// Connection manager destructor: shuts the UDP manager down (0x00424DE3).
// FUNCTION: TITANIUM 0x00424EF2
ConnectionManager_guess::~ConnectionManager_guess() {
    ((ClosureOwner_guess*)this)->Close_guess();
}

// Opens a connection to a zone host and port, starting the manager if needed. A connection that is already
// disconnected (state 2) is logged and dropped; each success raises the connection count (+0x54).
// FUNCTION: TITANIUM 0x00424F2E
Connection_guess* ConnectionManager_guess::Connect_guess(const char* zone_guess, int port_guess, int flags_guess) {
    Start_guess();
    Connection_guess* connection_guess = field4c_guess->Connect_guess(zone_guess, port_guess, flags_guess);
    if (connection_guess != 0) {
        if (connection_guess->GetState_guess() == 2) {
            Log_guess("Disconnected while opening connection to zone %s:%d [client:%s,server:%s]\n",
                zone_guess, port_guess,
                ValueToString_guess(((ValueOwner2_guess*)connection_guess)->GetValue_guess()),
                ValueToString_guess(((LockedValueOwner_guess*)connection_guess)->GetValue_guess()));
            connection_guess->Slot01_guess();
            connection_guess = 0;
        }
        if (connection_guess != 0) {
            ++field54_guess;
            Log_guess("Networking: Connection Established [%d]", field54_guess);
        }
    }
    return connection_guess;
}

// Polls every 50 ms for up to `limit_guess` ms; true as soon as the connection is gone or disconnected
// (state 2), false on timeout or with no manager. It waits for the end of a connection, not its start.
// FUNCTION: TITANIUM 0x00424FB5
char ClosureOwner_guess::WaitForDisconnect_guess(Connection_guess* connection_guess, int limit_guess) {
    if (this->resource_guess == 0) {
        return 0;
    }
    __int64 start_guess = GetClockStamp_guess();
    int elapsed_guess = ClockElapsed_guess(start_guess);
    while (elapsed_guess < limit_guess) {
        if (connection_guess == 0) {
            return 1;
        }
        if (connection_guess->GetState_guess() == 2) {
            return 1;
        }
        FUN_00600e40_guess(0x32);
        elapsed_guess = ClockElapsed_guess(start_guess);
    }
    return 0;
}

// Stops the connection, waits up to 10 s (100 x 100 ms) for unsent data to drain, then flushes, releases
// it, clears the caller's pointer and drops the closure count.
// FUNCTION: TITANIUM 0x0042500C
void ClosureOwner_guess::CloseConnection_guess(Connection_guess** connection_guess) {
    if (connection_guess != 0 && *connection_guess != 0) {
        (*connection_guess)->SetState_guess(0);
        int i_guess = 100;
        do {
            --i_guess;
            if ((*connection_guess)->GetPending_guess() == 0) {
                break;
            }
            FUN_00600e40_guess(100);
        } while (i_guess > 0);
        int pending_guess = (*connection_guess)->GetPending_guess();
        (*connection_guess)->Flush_guess(0);
        (*connection_guess)->Slot01_guess();
        *connection_guess = 0;
        this->AdjustClosureCount_guess();
        Log_guess("Networking: Connection Closed [%d] with %d pending bytes.",
            this->closureCount_guess, pending_guess);
    }
}

// Connection timeout 180000 ms (3 minutes).
// FUNCTION: TITANIUM 0x0042507B
ConnectionManager_guess::ConnectionManager_guess()
    : field4c_guess(0), field54_guess(0) {
    timeout_guess = 180000;
}
