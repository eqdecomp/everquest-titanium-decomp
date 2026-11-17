// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 84: a hint from compare/tumap.py.
// Zone weather: rain and snow fading in and out over 256 steps while the fog closes in, lightning with
// thunder, and the weather sound emitter. Weather_guess is the weather singleton at 0x985C8C (type
// 0 rain, 1 snow, 0xFF none). The list and "Globals" helpers at the end are unrelated.
#include "titanium/eqaddr.h"
#include "titanium/core_decls.h"
#include <new>

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_arg_guess
int __stdcall FUN_0046d655_arg_guess(int arg_guess);

struct Base_guess {
    unsigned int field04_guess;
    unsigned int field08_guess;
    unsigned int field0c_guess;
    Base_guess()
        : field04_guess(0), field08_guess(0), field0c_guess(0) {
    }
};

struct Callback_guess {
    virtual void RefreshCounts_guess();
    virtual void Slot01_guess(int value_guess);
    virtual void Slot02_guess();
    virtual void Slot03_guess(float scale_guess, int value_guess);
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(float* position_guess);
    virtual void Slot07_guess(int value_guess);
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess(int value_guess);
    virtual void Slot11_guess(int a_guess, int b_guess);
    virtual void Slot12_guess();
};

// Object at display+0x118: vtable slots 23 and 24 return ints.
struct Clock_guess {
    virtual void RefreshCounts_guess();
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
    virtual int Slot23_guess();
    virtual int Slot24_guess();
};

struct PointPair_guess {
    float first_guess;
    float second_guess;
    PointPair_guess& operator=(const PointPair_guess& value_guess) {
        first_guess = value_guess.first_guess;
        second_guess = value_guess.second_guess;
        return *this;
    }
};

struct Weather_guess {
    unsigned int field00_guess;
    unsigned char pad04_guess;
    unsigned char field05_guess;
    unsigned char field06_guess;
    unsigned char field07_guess;
    unsigned char field08_guess;
    unsigned char field09_guess;
    unsigned char pad0a_guess[2];
    unsigned int field0c_guess;
    int field10_guess;
    int field14_guess;
    int field18_guess;
    int field1c_guess;
    unsigned char field20_guess;
    unsigned char pad21_guess[3];
    PointPair_guess field24_pair_guess;
    Callback_guess* field2c_guess;
    Weather_guess();
    void Init_guess(int value_guess, char flag_guess);
    void UpdateWeather_guess();
    void LightningStrike_guess();
    void FadeStep_guess();
    void StopWeather_guess(int value_guess, char flag_guess);
    void Clear_guess(int value_guess);
    void SetWeather_guess(int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x004C3325 Weather_guess::UpdateSoundEmitter_guess
    void UpdateSoundEmitter_guess(const char* name_guess);
};

struct Mgr_guess {
    // EXTERNAL: TITANIUM 0x0044A537 Mgr_guess::WavePlay_guess
    void WavePlay_guess(int mode_guess, int argument_guess);
    // EXTERNAL: TITANIUM 0x0044AFFC Mgr_guess::EmitterSetWind_guess
    void EmitterSetWind_guess(int arg_guess);
    // EXTERNAL: TITANIUM 0x0044B014 Mgr_guess::Callee_44b014_guess
    void Callee_44b014_guess(int arg_guess);
};

#define g_mgr_guess EQ_GLOBAL(Mgr_guess*, 0x00851390)

struct Factory_guess {
    virtual void RefreshCounts_guess();
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
    virtual Callback_guess* Slot33_guess(int argument_guess);
};

#define g_factory_guess EQ_GLOBAL(Factory_guess*, 0x0099E360)

// EXTERNAL: TITANIUM 0x0064BF08 ??_7Object_guess@@6B@
struct Object_guess : Base_guess {
    virtual void RefreshCounts_guess();
    unsigned int field10_guess;
    unsigned int field14_guess;
    unsigned int field18_guess;
    unsigned char field1c_guess;
    unsigned int field20_guess;
    unsigned int field24_guess;
    unsigned int field28_guess;
    Callback_guess* field2c_guess;
    Object_guess(int argument_guess);
    void UpdateSoundEmitter_guess();
};

struct ObjectTail_guess {
    unsigned int field00_guess;
    unsigned int field04_guess;
    // EXTERNAL: TITANIUM 0x004C4C08 ObjectTail_guess::Set_guess
    void Set_guess(int value_guess);
};

struct Shared_guess {
    unsigned char padding00_guess[0x24];
    int field24_guess;
};

struct GlobalSpace_guess {
    Object_guess* globals_guess;
    unsigned char padding04_guess[0x186c4];
    Shared_guess* shared_guess;
};

#define g_global_space_guess EQ_GLOBAL(GlobalSpace_guess, 0x00985C90)

#define g_singleton_guess EQ_GLOBAL(Weather_guess*, 0x00985C8C)

struct State_guess {
    int field00_guess;
    unsigned char field04_guess;
    unsigned char padding05_guess[3];
    int field08_guess;
    int field0c_guess;
    int field10_guess;
    void Set_guess(int* values_guess);
};

struct List_guess;
struct ListNode_guess;

struct ListNodeLinks_guess {
    ListNode_guess* previous_guess;
    ListNode_guess* next_guess;
    List_guess* owner_guess;
    // EXTERNAL: TITANIUM 0x004952B6 ListNodeLinks_guess::Clear_guess
    void Clear_guess();
    void RemoveSelf_guess();
};

// EXTERNAL: TITANIUM 0x0064BE90 ??_7ListNode_guess@@6B@
struct ListNode_guess {
    virtual void RefreshCounts_guess();
    ListNodeLinks_guess links_guess;
    ListNode_guess* Delete_guess(unsigned char free_flag_guess);
    ~ListNode_guess() ;
};

struct List_guess {
    ListNode_guess* first_guess;
    ListNode_guess* last_guess;
    void Remove_guess(ListNode_guess* node_guess);
};

// Weather constructor: no weather (type 0xFF, +0xC 0xFF), every fade and timer value zeroed.
// FUNCTION: TITANIUM 0x004C32C2
// @early-stop: budget, diff ndiff=2
Weather_guess::Weather_guess() {
    field24_pair_guess.second_guess = 0.0f;
    field24_pair_guess.first_guess = 0.0f;
    field2c_guess = 0;
    pad04_guess = 0;
    field05_guess = 0;
    field06_guess = 0;
    field0c_guess = 0xff;
    field10_guess = 0;
    field00_guess = 0xff;
    field14_guess = 0;
    field18_guess = 0;
    field20_guess = 0;
    field1c_guess = 0;
    field07_guess = 0;
    field08_guess = 0;
    field09_guess = 0;
}

// The weather object at 0x985C8C, created on first use.
// FUNCTION: TITANIUM 0x004C32FF
Weather_guess* GetSingleton_guess() {
    if (g_singleton_guess == 0) {
        g_singleton_guess = new Weather_guess();
    }
    return g_singleton_guess;
}

// Creates the sound emitter on first use (factory slot 33, id 0x1D4C) and updates it.
// FUNCTION: TITANIUM 0x004C3325
void Object_guess::UpdateSoundEmitter_guess() {
    if (field2c_guess == 0) {
        field2c_guess = g_factory_guess->Slot33_guess(0x1d4c);
    }
    field2c_guess->Slot12_guess();
}

// Stores a pending (type, intensity) request; type 0xFF means keep the current type at intensity 0.
// FUNCTION: TITANIUM 0x004C334D
void State_guess::Set_guess(int* values_guess) {
    field0c_guess = *values_guess;
    field10_guess = values_guess[1];
    if (field0c_guess == 0xff) {
        field10_guess = 0;
        field0c_guess = field00_guess;
    }
    field04_guess = 1;
}

struct Display_guess {
    unsigned char pad000_guess[0x118];
    Clock_guess* field118_guess;
    unsigned char pad11c_guess[0x10];
    float field12c_guess;
    float field130_guess;
    unsigned char field134_guess;
    unsigned char field135_guess;
    unsigned char field136_guess;
    unsigned char pad137_guess[0x0e];
    unsigned char field145_guess;
    unsigned char pad146_guess[0x2];
    unsigned int field148_guess;
    unsigned char field14c_guess;
    unsigned char field14d_guess;
    // EXTERNAL: TITANIUM 0x0044104C Display_guess::SetFogState_guess
    void SetFogState_guess(int enabled_guess, float x_guess, float y_guess,
                             int red_guess, int green_guess, int blue_guess);
    // EXTERNAL: TITANIUM 0x00441295 Display_guess::SetAmbientLight_guess
    void SetAmbientLight_guess(float value_guess);
};

#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

struct OffsetSource_guess {
    unsigned int pad00_guess;
    int field04_guess;
};

struct StateSource_guess {
    unsigned int pad00_guess[2];
    OffsetSource_guess* field08_guess;
    unsigned char pad00c_guess[0xfc];
    unsigned char field108_guess[1];
};

#define g_state_source_guess EQ_GLOBAL(StateSource_guess*, 0x00905D00)



#define g_mode_guess EQ_GLOBAL(int, 0x0078F614)

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int minimum_guess, int maximum_guess);

// EXTERNAL: TITANIUM 0x0060F5EB rand
extern "C" int __cdecl rand(void);

// Rain only: when the next-strike time passes, plays thunder sound 143 or 144 (alternating, or a coin flip
// for the first). 30% of strikes queue a quick second one within 1 s; otherwise the next comes in 10-20 s.
// Snow just keeps its sound running.
// FUNCTION: TITANIUM 0x004C3374
// @early-stop: budget, structural ndiff=15
void Weather_guess::LightningStrike_guess() {
    if (g_display_guess->field148_guess < (unsigned int)field18_guess) {
        return;
    }
    if (field00_guess == 0) {
        int mode_guess;
        unsigned char current_guess = field20_guess;
        if (current_guess != 0) {
            mode_guess = (current_guess == 0x8f) + 0x8f;
        } else {
            mode_guess = (RandomRange_guess(1, 100) >= 50) + 0x8f;
        }
        g_mgr_guess->WavePlay_guess(g_mode_guess = mode_guess, 0);
        field09_guess = 1;
    } else if (field00_guess == 1) {
        g_mgr_guess->Callee_44b014_guess(1);
    }
    if (field20_guess == 0) {
        field20_guess = ((rand() % 100 >= 30) - 1U) & (unsigned int)g_mode_guess;
    } else {
        field20_guess = 0;
    }
    int delay_guess;
    if (field20_guess == 0) {
        // Always true below, so the gap is 10-20 seconds.
        delay_guess = rand() % 10000;
        if (delay_guess < 10000) {
            delay_guess += 10000;
        }
    } else {
        delay_guess = rand() % 1000;
    }
    field18_guess = g_display_guess->field148_guess + delay_guess;
}

// One fade step (at most one per display tick): 4/256 per step while starting, 6/256 while stopping. Starting
// announces string 541 "It begins to rain." (540 "...rain blood." when a character value at +0x108 reads 72),
// or 542 for snow, and turns the sound on. The fog start and end are pulled toward 100 and 1000 over 64 steps
// and given back as it stops.
// FUNCTION: TITANIUM 0x004C344B
// @early-stop: budget, structural ndiff=93
void Weather_guess::FadeStep_guess() {
    if (field14_guess >= 0x100) {
        if (field06_guess == 0) {
            g_display_guess->field14d_guess = 0;
            g_display_guess->field14c_guess = 0;
            if (field00_guess == 0) {
                field07_guess = 0;
                g_mgr_guess->EmitterSetWind_guess(0);
                field00_guess = 0xff;
            } else if (field00_guess == 1) {
                field08_guess = 0;
                g_mgr_guess->Callee_44b014_guess(0);
                field00_guess = 0xff;
            }
        } else {
            g_display_guess->field14d_guess = 1;
            if (field00_guess == 0) {
            if (g_state_source_guess == 0 ||
                *reinterpret_cast<int*>(
                    &g_state_source_guess->field108_guess[
                        g_state_source_guess->field08_guess->field04_guess]) != 0x48) {
                pEverQuest->dsp_chat(
                    pStringTable->getString(0x21d, 0));
            } else {
                pEverQuest->dsp_chat(
                    pStringTable->getString(0x21c, 0));
                }
                field07_guess = 1;
                g_mgr_guess->EmitterSetWind_guess(1);
            } else if (field00_guess == 1) {
                pEverQuest->dsp_chat(
                    pStringTable->getString(0x21e, 0));
                field08_guess = 1;
                g_mgr_guess->Callee_44b014_guess(1);
            }
        }
        field05_guess = 0;
        return;
    }

    if (g_display_guess->field148_guess < (unsigned int)field1c_guess) {
        return;
    }
    field1c_guess = g_display_guess->field148_guess - 1;
    if (field06_guess == 0) {
        field14_guess += 6;
    } else {
        field14_guess += 4;
    }
    if (field06_guess == 0) {
        if (field14_guess == 6) {
                field24_pair_guess = field24_pair_guess;
        }
        g_display_guess->SetFogState_guess(
            1, g_display_guess->field12c_guess + field24_pair_guess.first_guess,
            g_display_guess->field130_guess + field24_pair_guess.second_guess,
            g_display_guess->field134_guess, g_display_guess->field135_guess,
            g_display_guess->field136_guess);
        return;
    }
    if (field14_guess == 4) {
        if (g_display_guess->field12c_guess > 100.0f) {
            field24_pair_guess.first_guess =
                (g_display_guess->field12c_guess - 100.0f) * 0.015625f;
        } else {
            field24_pair_guess.first_guess = 0.0f;
        }
        if (g_display_guess->field130_guess >= 1000.0f) {
            field24_pair_guess.second_guess =
                (g_display_guess->field130_guess - 1000.0f) * 0.015625f;
        } else {
            field24_pair_guess.second_guess = 0.0f;
        }
    }
    float x_guess = g_display_guess->field12c_guess;
    float y_guess = g_display_guess->field130_guess;
    if (g_display_guess->field12c_guess > 100.0f) {
        x_guess = g_display_guess->field12c_guess - field24_pair_guess.first_guess;
        if (x_guess < 100.0f) {
            x_guess = 100.0f;
        }
    }
    if (g_display_guess->field130_guess > 1000.0f) {
        y_guess = g_display_guess->field130_guess - field24_pair_guess.second_guess;
        if (y_guess < 1000.0f) {
            y_guess = 1000.0f;
        }
    }
    g_display_guess->SetFogState_guess(
        1, x_guess, y_guess, g_display_guess->field134_guess,
        g_display_guess->field135_guess, g_display_guess->field136_guess);
}

// Weather from the server: type `value_guess`, intensity `flag_guess` (0-100; 0 stops it). A new type stops
// the old one first. The sound emitter gets intensity / 100 (probably its volume).
// FUNCTION: TITANIUM 0x004C37BE
// @early-stop: budget, diff ndiff=2
void Weather_guess::SetWeather_guess(int value_guess, int flag_guess) {
    float position_guess[3] = {0.0f, 0.0f, -1.0f};
    if (field2c_guess == 0) {
        UpdateSoundEmitter_guess("default");
    }
    field2c_guess->Slot01_guess(value_guess);
    field2c_guess->Slot06_guess(position_guess);
    field2c_guess->Slot07_guess(g_display_guess->field118_guess->Slot23_guess());
    field2c_guess->Slot10_guess(g_display_guess->field118_guess->Slot24_guess());
    if (flag_guess == 0) {
        if (field00_guess != 0xff) {
            StopWeather_guess(value_guess, 1);
        }
    } else if (flag_guess > 0) {
        if (field00_guess != 0xff) {
            if (field00_guess != (unsigned int)value_guess) {
                StopWeather_guess((int)field00_guess, 0);
                field2c_guess->Slot11_guess(1, 1);
                Init_guess(value_guess, 1);
            }
        } else {
            Init_guess(value_guess, 1);
        }
    }
    field2c_guess->Slot03_guess((float)flag_guess * 0.01f, FUN_0046d655_arg_guess(0));
}

// Per-frame update: ambient light from the table at 0x78F618 by the display's light level, then the fade step
// while fading, else lightning.
// FUNCTION: TITANIUM 0x004C36CD
void Weather_guess::UpdateWeather_guess() {
    g_display_guess->SetAmbientLight_guess(EQ_ARRAY(float, 0x0078F618)[g_display_guess->field145_guess]);
    if (field05_guess != 0) {
        FadeStep_guess();
        return;
    }
    LightningStrike_guess();
}

#define field24_guess field24_pair_guess.first_guess
#define field28_guess field24_pair_guess.second_guess

// Starts type `value_guess` fading in; with `flag_guess` 0 it appears at full strength at once.
// FUNCTION: TITANIUM 0x004C375F
void Weather_guess::Init_guess(int value_guess, char flag_guess) {
    field00_guess = value_guess;
    g_display_guess->field14c_guess = 1;
    field24_guess = 0.0f;
    field28_guess = 0.0f;
    field05_guess = 1;
    field06_guess = 1;
    field14_guess = 0;
    field1c_guess = g_display_guess->field148_guess;
    field18_guess = g_display_guess->field148_guess;
    field20_guess = 0;
    if (flag_guess == 0) {
        field14_guess = 0x100;
        UpdateWeather_guess();
    }
}

#undef field24_guess
#undef field28_guess

// Starts fading out, from the current strength when it was mid-fade; with `flag_guess` 0 it stops at once and
// silences both sounds.
// FUNCTION: TITANIUM 0x004C3700
void Weather_guess::StopWeather_guess(int value_guess, char flag_guess) {
    field00_guess = value_guess;
    field05_guess = 1;
    field06_guess = 0;
    if (field14_guess <= -1 || field14_guess == 0x100) {
        field14_guess = 0;
    } else {
        field14_guess = 0x100 - field14_guess;
    }
    if (flag_guess == 0) {
        g_mgr_guess->EmitterSetWind_guess(0);
        g_mgr_guess->Callee_44b014_guess(0);
        field14_guess = 0x100;
        UpdateWeather_guess();
    }
}

// Stops the weather at once and clears the rain and snow sound flags.
// FUNCTION: TITANIUM 0x004C38A9
void Weather_guess::Clear_guess(int value_guess) {
    if (field2c_guess != 0) {
        field2c_guess->Slot11_guess(1, 1);
    }
    StopWeather_guess(value_guess, 0);
    field07_guess = 0;
    field08_guess = 0;
}

// Unlinks `node` from the list, moving the head or tail past it when needed, and clears its links.
// FUNCTION: TITANIUM 0x004C390B
void List_guess::Remove_guess(ListNode_guess* node_guess) {
    if (node_guess == first_guess) {
        first_guess = node_guess->links_guess.next_guess;
    }
    if (node_guess == last_guess) {
        last_guess = node_guess->links_guess.previous_guess;
    }
    node_guess->links_guess.Clear_guess();
}

// Unlinks the node (these links sit at +4 in it) from its owning list.
// FUNCTION: TITANIUM 0x004C392E
void ListNodeLinks_guess::RemoveSelf_guess() {
    if (owner_guess != 0) {
        ListNode_guess* node_guess = reinterpret_cast<ListNode_guess*>(reinterpret_cast<char*>(this) - 4);
        owner_guess->Remove_guess(node_guess);
    }
}

// Scalar deleting destructor of a list node (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C3941
ListNode_guess* ListNode_guess::Delete_guess(unsigned char free_flag_guess) {
    this->~ListNode_guess();
    if ((free_flag_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// The shared "Globals" object's constructor (made by 0x004C398E): an empty base, `argument` (the name)
// at +0x18, the rest zeroed.
// FUNCTION: TITANIUM 0x004C395D
Object_guess::Object_guess(int argument_guess)
    : Base_guess(), field10_guess(0), field14_guess(0),
      field18_guess(argument_guess),
      field1c_guess(0) {
}

// The shared "Globals" object, created on first use.
// FUNCTION: TITANIUM 0x004C398E
// @early-stop: unknown, diff ndiff=3
Object_guess* __cdecl GetGlobals_guess() {
    Object_guess* object_guess = g_global_space_guess.globals_guess;
    if (object_guess != 0) {
        return object_guess;
    }
    void* memory_guess = ::operator new(0x20);
    if (memory_guess != 0) {
        object_guess = new (memory_guess) Object_guess((int)"Globals");
    } else {
        object_guess = 0;
    }
    g_global_space_guess.globals_guess = object_guess;
    reinterpret_cast<ObjectTail_guess*>(&object_guess->field10_guess)->Set_guess(
        g_global_space_guess.shared_guess->field24_guess);
    return object_guess;
}

// List node destructor: unlinks the node from its list (0x004C392E).
// FUNCTION: TITANIUM 0x004C39D0
ListNode_guess::~ListNode_guess()  {
    links_guess.RemoveSelf_guess();
}

// EXTERNAL: TITANIUM 0x004C37BE SetWeather_guess
void __stdcall SetWeather_guess(int a_guess, int b_guess);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

struct Slot_guess {
    virtual void RefreshCounts_guess(int value_guess);
};

struct Pending_guess {
    unsigned int field00_guess;
    unsigned char field04_guess;
    unsigned char pad05_guess[3];
    unsigned int field08_guess;
    unsigned int field0c_guess;
    unsigned int field10_guess;
    unsigned int pad14_guess[6];
    Slot_guess* field2c_guess;
    void Flush_guess();
};

// Applies a pending weather request (Weather_guess::SetWeather_guess), then updates the sound emitter with
// the current time.
// FUNCTION: TITANIUM 0x004C38D5
void Pending_guess::Flush_guess() {
    if (field04_guess != 0) {
        SetWeather_guess(field0c_guess, field10_guess);
        field04_guess = 0;
    }
    if (field2c_guess != 0) {
        field2c_guess->RefreshCounts_guess(FUN_0046d655_guess());
    }
}

