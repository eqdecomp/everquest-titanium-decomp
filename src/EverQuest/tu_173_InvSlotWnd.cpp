// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 173: a hint from compare/tumap.py.
// InvSlotWnd: the window for one inventory slot (the original's C:\EQ\EverQuest\InvSlotWnd.cpp, named in
// Draw's error strings). Draws background, icon, stack count and recast shade, and forwards mouse presses and
// releases to the slot object (+0x140) and the parent. +0x120 is the inventory slot id (-1 = no slot object),
// +0x12C the icon (0 = empty), +0x130 the stack count, +0x14C set while a button pressed here is down.
#include "titanium/types.h"

struct Event_guess;
struct Holder_guess;

struct ChildWnd_guess {
    char pad_000[0x10];
    Holder_guess* field_10_guess;
    // EXTERNAL: TITANIUM 0x00518E58 ChildWnd_guess::IsAvailable_guess
    char IsAvailable_guess();
    // EXTERNAL: TITANIUM 0x00519061 ChildWnd_guess::ProcessEvent_guess
    void ProcessEvent_guess(Event_guess* event);
    // EXTERNAL: TITANIUM 0x00491839 ChildWnd_guess::EmptyCallback1_guess
    void EmptyCallback1_guess(Event_guess* event);
    // EXTERNAL: TITANIUM 0x0051A3A0 ChildWnd_guess::ResetSlot_guess
    void ResetSlot_guess(Event_guess* event);
    // EXTERNAL: TITANIUM 0x0051917A ChildWnd_guess::Process_guess
    void Process_guess(Event_guess* event);
    // EXTERNAL: TITANIUM 0x005191E1 ChildWnd_guess::PickUpQuantity_guess
    void PickUpQuantity_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005190D3 ChildWnd_guess::Reset_guess
    void Reset_guess(Event_guess* event);
    // EXTERNAL: TITANIUM 0x00519356 ChildWnd_guess::HandleLButtonUp_guess
    void HandleLButtonUp_guess(Event_guess* event, unsigned char flag);
    // EXTERNAL: TITANIUM 0x0051A5A5 ChildWnd_guess::SetValue_guess
    void SetValue_guess(int value);
};

struct Event_guess {
    char pad_000[0x8];
    int type_guess;
    char pad_00c[0xe0];
    int value_guess;
};

struct InvSlotWnd_guess;

struct Receiver_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
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
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess();
    virtual void Slot1f_guess();
    virtual int Notify_guess(InvSlotWnd_guess* wnd, int code, int value);
};

struct LocalThing_guess {
    int words_guess[4];
    // EXTERNAL: TITANIUM 0x004EA5BF LocalThing_guess::IsReady_guess
    char IsReady_guess(Event_guess* event);
};

struct Counter_guess {
    char pad_000[0x48];
    int field_48_guess;
    char pad_04c[0x20];
    int field_6c_guess;
    // EXTERNAL: TITANIUM 0x00435AA7 Counter_guess::Attach_guess
    void Attach_guess(InvSlotWnd_guess* wnd);
};

// EXTERNAL: TITANIUM 0x0099D334 g_counterRoot_guess
#define g_counterRoot_guess EQ_GLOBAL(Counter_guess**, 0x0099D334)

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x005B47A0 Manager_guess::GetValue_guess
    int GetValue_guess(int value);
};

struct InvSlotRect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    InvSlotRect_guess(int left, int top, int right, int bottom)
        : left_guess(left), top_guess(top), right_guess(right), bottom_guess(bottom) {}
    InvSlotRect_guess(const InvSlotRect_guess& other)
        : left_guess(other.left_guess), top_guess(other.top_guess),
          right_guess(other.right_guess), bottom_guess(other.bottom_guess) {}
    ~InvSlotRect_guess() {}
};

struct InvSlotWndBase_guess {
    // EXTERNAL: TITANIUM 0x005A1290 InvSlotWndBase_guess::InvSlotWndBase_guess
    InvSlotWndBase_guess(int first_guess, int second_guess,
        InvSlotRect_guess rect_guess);
    // EXTERNAL: TITANIUM 0x005A0940 ??1InvSlotWndBase_guess@@UAE@XZ
    virtual ~InvSlotWndBase_guess();
};

struct HandleManager_guess {
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
    virtual int Slot13_guess();
    virtual void Slot14_guess(int handle_guess);
};

#define g_handleManager_guess EQ_GLOBAL(HandleManager_guess*, 0x0099E360)

// EXTERNAL: TITANIUM 0x004C43F2 GetLanguage_guess
int __cdecl GetLanguage_guess();
// EXTERNAL: TITANIUM 0x004AE49C IsDoubleByteLanguage_guess
char __cdecl IsDoubleByteLanguage_guess(int value_guess);
// EXTERNAL: TITANIUM 0x00559535 CreateInvSlot_guess
int __cdecl CreateInvSlot_guess(int argument_guess);

struct InvSlotWnd_guess : InvSlotWndBase_guess {
    char pad_004[0x24];
    Receiver_guess* notifyReceiver_0028_guess;
    char pad_02c[0x31];
    unsigned char field_5d_guess;
    char pad_05e[4];
    unsigned char field_62_guess;
    char pad_063[0xb9];
    int iconAnim_011c_guess;
    int slotId_0120_guess;
    int offsetX_0124_guess;
    int offsetY_0128_guess;
    int itemIconAnim_012c_guess;
    int quantity_0130_guess;
    unsigned char field_134_guess;
    char pad_135[7];
    unsigned char field_13c_guess;
    char pad_13d[3];
    ChildWnd_guess* invSlot_0140_guess;
    int surface_0144_guess;
    int field_148_guess;
    int field_14c_guess;
    int field_150_guess;
    unsigned int color_0154_guess;
    int field_158_guess;

    InvSlotWnd_guess(int first_guess, int second_guess,
        InvSlotRect_guess rect_guess, int third_guess,
        int fourth_guess, int fifth_guess, int sixth_guess);
    virtual ~InvSlotWnd_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
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
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess();
    virtual void Slot1f_guess();
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
    virtual void Slot2a_guess();
    virtual void Slot2b_guess();
    virtual void Slot2c_guess();
    virtual void Slot2d_guess();
    virtual void Slot2e_guess();
    virtual void Slot2f_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual CXRect Slot39_guess();
    int Draw_guess();
    void* Delete_guess(unsigned char flags_guess);

    // EXTERNAL: TITANIUM 0x0059D960 InvSlotWnd_guess::GetScreenRect
    void GetScreenRect(LocalThing_guess* value);

    // EXTERNAL: TITANIUM 0x005A0F90 InvSlotWnd_guess::Apply_guess
    int Apply_guess(int value);
    // EXTERNAL: TITANIUM 0x005A0780 InvSlotWnd_guess::Prepare_guess
    void Prepare_guess(Event_guess* event);

    void SetChild_guess(ChildWnd_guess* child);
    int Query_guess(int value);
    int Callback31_guess(int unused_guess, int code_guess, int* value_guess);
    void Handle_guess(Event_guess* event);
    int Callback16_guess(Event_guess* event, unsigned int code);
    int Callback4_guess(Event_guess* event, unsigned int code);
    int Callback17_guess(Event_guess* event, unsigned int code);
    int Callback19_guess(Event_guess* event, unsigned int code);
    int Callback5_guess(Event_guess* event, unsigned int code);
    int Callback3_guess(Event_guess* event, unsigned int code);
    int Callback1_guess(Event_guess* event, unsigned int code);
    int Callback2_guess(Event_guess* event, unsigned int code);
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x0099D3F4)

// EXTERNAL: TITANIUM 0x006567A0 ??_7InvSlotWnd_guess@@6B@

// third..sixth: background texture, slot id, icon x and y offset. A slot id of -1 gets no slot object.
// FUNCTION: TITANIUM 0x0051B649
InvSlotWnd_guess::InvSlotWnd_guess(int first_guess, int second_guess,
    InvSlotRect_guess rect_guess, int third_guess, int fourth_guess,
    int fifth_guess, int sixth_guess)
    : InvSlotWndBase_guess(first_guess, second_guess, rect_guess) {
    field_150_guess = -1;
    iconAnim_011c_guess = third_guess;
    slotId_0120_guess = fourth_guess;
    offsetX_0124_guess = fifth_guess;
    offsetY_0128_guess = sixth_guess;
    itemIconAnim_012c_guess = 0;
    quantity_0130_guess = 0;
    field_134_guess = 0;
    field_14c_guess = 0;
    field_13c_guess = 0;
    color_0154_guess = 0xffc0c0c0;
    int flag_guess = 1;
    if (IsDoubleByteLanguage_guess(GetLanguage_guess()) != 0) {
        flag_guess = 0;
    }
    surface_0144_guess = g_handleManager_guess->Slot13_guess();
    field_148_guess = flag_guess;
    if (slotId_0120_guess == -1) {
        invSlot_0140_guess = 0;
    } else {
        invSlot_0140_guess = (ChildWnd_guess*)CreateInvSlot_guess((int)this);
    }
    field_158_guess = 0;
}

// Frees the count text object made in the constructor.
// FUNCTION: TITANIUM 0x0051B74A
InvSlotWnd_guess::~InvSlotWnd_guess() {
    g_handleManager_guess->Slot14_guess(surface_0144_guess);
    if (field_13c_guess == 0 && invSlot_0140_guess != 0) {
        invSlot_0140_guess->SetValue_guess(0);
    }
}

// Binds the slot window to inventory slot object `child` (+0x140). The hot button bar refresh
// (0x0051482B) binds its buttons' slot windows this way.
// FUNCTION: TITANIUM 0x0051B7A8
void InvSlotWnd_guess::SetChild_guess(ChildWnd_guess* child) {
    invSlot_0140_guess = child;
}

// Slot window, vtable 0x6567A0 slot 9: passes `value` on to the CXWnd handler (0x005A0F90) only when
// the bound slot object (+0x140) has its +0x14 flag set (0x00518E58); otherwise returns 0.
// FUNCTION: TITANIUM 0x0051B7B5
int InvSlotWnd_guess::Query_guess(int value) {
    if (invSlot_0140_guess != 0 && invSlot_0140_guess->IsAvailable_guess()) {
        return Apply_guess(value);
    }
    return 0;
}

// Only code 0x1F is handled: it passes *value_guess on to the slot object.
// FUNCTION: TITANIUM 0x0051B7DE
int InvSlotWnd_guess::Callback31_guess(int unused_guess, int code_guess,
    int* value_guess) {
    if (code_guess == 0x1f && invSlot_0140_guess != 0) {
        invSlot_0140_guess->PickUpQuantity_guess(*value_guess);
    }
    return 0;
}

// Event type 0x1A reloads the background texture from the event's value.
// FUNCTION: TITANIUM 0x0051B7FF
void InvSlotWnd_guess::Handle_guess(Event_guess* event) {
    Prepare_guess(event);
    if (event->type_guess == 0x1a) {
        iconAnim_011c_guess = g_manager_guess->GetValue_guess(event->value_guess);
    }
}

// The eight mouse handlers below share one shape. A press (Callback4, Callback5) sets +0x14C and takes a
// capture count on *g_counterRoot_guess; a release (Callback16, 19, 3, 2) forwards the event, clears +0x14C
// and drops the count (+0x48 is cleared at 0); a held call (Callback17, 1) only forwards. Each tells the
// parent
// through Notify_guess with its own code. The empty then-branch on the count test is deliberate (match
// shape):
// don't fold it into `<= 0` without re-running compare.
// Release; parent code 1.
// FUNCTION: TITANIUM 0x0051B82F
int InvSlotWnd_guess::Callback16_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0) {
                invSlot_0140_guess->HandleLButtonUp_guess(event, field_13c_guess);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 1, 0);
            }
        }
        Counter_guess* counter = *g_counterRoot_guess;
        --counter->field_6c_guess;
        if (counter->field_6c_guess > 0) {
        } else {
            counter->field_48_guess = 0;
        }
        field_14c_guess = 0;
    }
    return 0;
}

// Press; parent code 4. Returns -1 only when code has bit 0x10 and the parent vetoes (Notify < 0).
// FUNCTION: TITANIUM 0x0051B8B9
int InvSlotWnd_guess::Callback4_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        return 0;
    }
    int result_guess = -1;
    LocalThing_guess local;
    GetScreenRect(&local);
    field_14c_guess = 1;
    (*g_counterRoot_guess)->Attach_guess(this);
    if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
        if (invSlot_0140_guess != 0) {
            invSlot_0140_guess->EmptyCallback1_guess(event);
        }
        if (notifyReceiver_0028_guess == 0 || (code & 0x10) == 0 || notifyReceiver_0028_guess->Notify_guess(this, 4, 0) >= 0) {
            result_guess = 0;
        }
    } else {
        result_guess = 0;
    }
    return result_guess;
}

// While held; parent code 0x17.
// FUNCTION: TITANIUM 0x0051B94D
int InvSlotWnd_guess::Callback17_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0 && field_13c_guess == 0) {
                invSlot_0140_guess->ProcessEvent_guess(event);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 0x17, 0);
            }
        }
    }
    return 0;
}

// Release; parent code 0x19.
// FUNCTION: TITANIUM 0x0051B9BE
int InvSlotWnd_guess::Callback19_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0 && field_13c_guess == 0) {
                invSlot_0140_guess->EmptyCallback1_guess(event);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 0x19, 0);
            }
        }
        Counter_guess* counter = *g_counterRoot_guess;
        --counter->field_6c_guess;
        if (counter->field_6c_guess > 0) {
        } else {
            counter->field_48_guess = 0;
        }
        field_14c_guess = 0;
    }
    return 0;
}

// Press; parent code 5. Same veto rule as Callback4_guess.
// FUNCTION: TITANIUM 0x0051BA47
int InvSlotWnd_guess::Callback5_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        return 0;
    }
    int result_guess = -1;
    LocalThing_guess local;
    GetScreenRect(&local);
    field_14c_guess = 1;
    (*g_counterRoot_guess)->Attach_guess(this);
    if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
        if (invSlot_0140_guess != 0) {
            invSlot_0140_guess->EmptyCallback1_guess(event);
        }
        if (notifyReceiver_0028_guess == 0 || (code & 0x10) == 0 || notifyReceiver_0028_guess->Notify_guess(this, 5, 0) >= 0) {
            result_guess = 0;
            }
    } else {
        result_guess = 0;
    }
    return result_guess;
}

// Release; parent code 3.
// FUNCTION: TITANIUM 0x0051BADB
int InvSlotWnd_guess::Callback3_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0) {
                invSlot_0140_guess->ResetSlot_guess(event);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 3, 0);
            }
        }
        Counter_guess* counter = *g_counterRoot_guess;
        --counter->field_6c_guess;
        if (counter->field_6c_guess > 0) {
        } else {
            counter->field_48_guess = 0;
        }
        field_14c_guess = 0;
    }
    return 0;
}

// While held; parent code 0x18.
// FUNCTION: TITANIUM 0x0051BB5C
int InvSlotWnd_guess::Callback1_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0) {
                invSlot_0140_guess->Process_guess(event);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 0x18, 0);
            }
        }
    }
    return 0;
}

// Release; parent code 0x1A.
// FUNCTION: TITANIUM 0x0051BBC4
int InvSlotWnd_guess::Callback2_guess(Event_guess* event, unsigned int code) {
    if (field_14c_guess == 1) {
        LocalThing_guess local;
        GetScreenRect(&local);
        if (local.IsReady_guess(event) != 0 && (code & 0xffff0000) != 0x10000) {
            if (invSlot_0140_guess != 0) {
                invSlot_0140_guess->Reset_guess(event);
            }
            if (notifyReceiver_0028_guess != 0) {
                notifyReceiver_0028_guess->Notify_guess(this, 0x1a, 0);
            }
        }
        Counter_guess* counter = *g_counterRoot_guess;
        --counter->field_6c_guess;
        if (counter->field_6c_guess > 0) {
        } else {
            counter->field_48_guess = 0;
        }
        field_14c_guess = 0;
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Scalar deleting destructor of a slot window (vtable 0x6567A0 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x0051BC45
void* InvSlotWnd_guess::Delete_guess(unsigned char flags_guess) {
    this->InvSlotWnd_guess::~InvSlotWnd_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x005C0C30 DebugSpew_guess
void __cdecl DebugSpew_guess(const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x005A3A00 MeasureText_guess
int __stdcall MeasureText_guess(CXStr* text_guess);
// EXTERNAL: TITANIUM 0x005591D0 GetBankWndFlag04_guess
unsigned char __cdecl GetBankWndFlag04_guess();
// EXTERNAL: TITANIUM 0x00576E80 GetTime_guess
unsigned int __cdecl GetTime_guess();
// EXTERNAL: TITANIUM 0x0059D2E0 DrawRect_guess
void __cdecl DrawRect_guess(CXRect* rect_guess, unsigned int color_guess, CXRect* clip_guess);
// EXTERNAL: TITANIUM 0x005A00E0 DrawFallback_guess
void __cdecl DrawFallback_guess(CXRect* first_guess, unsigned int color_guess, CXRect* second_guess);

struct Item_guess {
    // EXTERNAL: TITANIUM 0x005ECCC0 Item_guess::GetItemClass_guess
    char GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Item_guess::Check_guess
    int Check_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E05B0 Item_guess::GetRecastTime_guess
    unsigned int GetRecastTime_guess();
};

struct Holder_guess {
    Item_guess* item_guess;
};

struct CharDataCost_guess {
    // EXTERNAL: TITANIUM 0x004BAC48 CharDataCost_guess::GetItemTimerValue
    unsigned int GetItemTimerValue(Item_guess* item_guess);
};

struct TextureAnim_guess {
    char pad_000[0x24];
    int x_guess;
    int y_guess;
    // EXTERNAL: TITANIUM 0x005B1910 TextureAnim_guess::Draw_guess
    int Draw_guess(CXRect* output_guess, CXRect* texture_guess,
        unsigned int color_guess, unsigned int alpha_guess);
};

struct Surface_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(CXStr* text_guess);
    virtual void Slot02_guess();
    virtual void Slot03_guess(int handle_guess, CXRect* a_guess, CXRect* b_guess,
        int c_guess, int d_guess, int e_guess);
};

struct Painter_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
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
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess(Surface_guess* surface_guess);
};

struct Table_guess {
    // EXTERNAL: TITANIUM 0x004EB924 Table_guess::Get_guess
    int* Get_guess(int index_guess);
};

struct Owner_guess {
    char pad_000[0xf4];
    Table_guess table_guess;
};

#define pinstCXWndManager_guess EQ_GLOBAL(Owner_guess*, 0x0099D3EC)
#define g_painter_guess EQ_GLOBAL(Painter_guess*, 0x0099E364)

// Draws the slot in layers: background, icon, stack count, highlight, recast shade. Returns 0, or -1 when a
// texture fails to draw (after logging the original's file and line).
// Slot ids 2000-2499 are bank and bank-bag slots in the Titanium slot numbering. The icon box is offset into
// the slot and clipped to the icon's own size.
// Recast shade: GetItemTimerValue is the time the item can be used again and GetSize_guess its recast time;
// the grey shade covers the share of the recast still to wait, from the bottom of the icon up.
// FUNCTION: TITANIUM 0x0051BC61
// @early-stop: budget, structural ndiff=220
int InvSlotWnd_guess::Draw_guess() {
    if (invSlot_0140_guess == 0 || !invSlot_0140_guess->IsAvailable_guess()) {
        return 0;
    }

    int result_guess = -1;
    CXRect rect30_guess = Slot39_guess();
    CXRect rect50_guess = ((CXWnd*)this)->GetClientClipRect();
    if (slotId_0120_guess >= 0x7d0 && slotId_0120_guess < 0x9c4) {
        field_5d_guess = GetBankWndFlag04_guess();
    }

    if (iconAnim_011c_guess != 0) {
        int draw_result_guess;
        if (field_62_guess != 0) {
            draw_result_guess = ((TextureAnim_guess*)iconAnim_011c_guess)->Draw_guess(
                &rect30_guess, &rect50_guess, field_150_guess, 0xff000000);
        } else {
            draw_result_guess = ((TextureAnim_guess*)iconAnim_011c_guess)->Draw_guess(
                &rect30_guess, &rect50_guess, color_0154_guess, 0xff000000);
        }
        if (draw_result_guess < 0) {
            DebugSpew_guess("%s at: %s, %d\n", "", "C:\\EQ\\EverQuest\\InvSlotWnd.cpp", 0x91);
            return result_guess;
        }
    }

    TextureAnim_guess* anchor_guess = (TextureAnim_guess*)itemIconAnim_012c_guess;
    if (anchor_guess == 0) {
        return 0;
    }

    CXRect box20_guess = {rect30_guess.left + offsetX_0124_guess,
        rect30_guess.top + offsetY_0128_guess, rect30_guess.right, rect30_guess.bottom};
    int max_right_guess = anchor_guess->x_guess + box20_guess.left;
    int max_bottom_guess = anchor_guess->y_guess + box20_guess.top;
    if (box20_guess.bottom >= max_bottom_guess) {
        box20_guess.bottom = max_bottom_guess;
    }
    if (box20_guess.right >= max_right_guess) {
        box20_guess.right = max_right_guess;
    }
    if (anchor_guess->Draw_guess(&box20_guess, &rect50_guess, 0xffffffff, 0xff000000) < 0) {
        DebugSpew_guess("%s at: %s, %d\n", "", "C:\\EQ\\EverQuest\\InvSlotWnd.cpp", 0xa2);
        return result_guess;
    }

    if (quantity_0130_guess > 0) {
        CXStr text_guess;
        // Stack count: right-aligned in a dark 10-pixel-high box in the icon's bottom-right corner,
        // at least 10
        // pixels wide (no width at all when the font table entry is 0).
        FormatString_guess(&text_guess, "%d", quantity_0130_guess);
        int width_guess = 0;
        int* count_guess = pinstCXWndManager_guess->table_guess.Get_guess(field_148_guess);
        if (*count_guess != 0) {
            width_guess = MeasureText_guess(&text_guess);
            if (width_guess < 10) {
                width_guess = 10;
            }
        }
        CXRect box60_guess = {box20_guess.right - 1 - width_guess,
            box20_guess.bottom - 11, box20_guess.right - 1, box20_guess.bottom - 1};
        DrawRect_guess(&box60_guess, 0xff404040, &rect50_guess);
        Surface_guess* surface_guess = (Surface_guess*)surface_0144_guess;
        surface_guess->Slot01_guess(&text_guess);
        surface_guess->Slot03_guess(field_148_guess, &box60_guess, &rect50_guess, -1, 0, 0);
        g_painter_guess->Slot1e_guess(surface_guess);
    }

    if (field_134_guess != 0) {
        DrawFallback_guess(&rect30_guess, 0xffffff00, &rect50_guess);
    }

    if (invSlot_0140_guess != 0) {
        Item_guess* item_guess = 0;
        if (invSlot_0140_guess->field_10_guess != 0) {
            item_guess = invSlot_0140_guess->field_10_guess->item_guess;
        }
        if (item_guess != 0 && !item_guess->GetItemClass_guess()
                && item_guess->Check_guess(0) != 0 && item_guess->GetRecastTime_guess() > 0) {
            unsigned int cost_guess = ((CharDataCost_guess*)pCharData)->GetItemTimerValue(item_guess);
            unsigned int now_guess = GetTime_guess();
            if (now_guess < cost_guess) {
                CXRect box40_guess = box20_guess;
                unsigned int size_guess = item_guess->GetRecastTime_guess();
                if (size_guess > cost_guess - now_guess) {
                    box40_guess.top += (box40_guess.bottom - box40_guess.top)
                        * (int)(size_guess - (cost_guess - now_guess)) / size_guess;
                }
                DrawRect_guess(&box40_guess, 0x40c0c0c0, &rect50_guess);
            }
        }
    }
    return 0;
}

