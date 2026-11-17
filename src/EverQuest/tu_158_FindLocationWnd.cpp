// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 158: a hint from compare/tumap.py.
// The Find window, CFindLocationWnd ("FindLocationWnd"): a list of findable spawns (FLW_FindLocationList), an
// optional filter that hides other classes' trainers, and the 15-second limit between find paths.
// EQPlayerView_guess is a spawn (class at +0x252, id at +0x258); g_selected_guess is pinstLocalPlayer.
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory);

#define g_bytePointer_guess EQ_GLOBAL(char*, 0x00985C88)

struct ItemAt8c_guess;
struct TableAt180_guess;

struct StateAt15C_guess {
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
    virtual void Slot48_guess();
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
    virtual void Slot63_guess();
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess();
    virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual void Slot76_guess();
    virtual void Slot77_guess();
    virtual void Dispatch_guess();

    char pad_004[0x62];
    unsigned char flags_66;
    char pad_067[0xb5];
    int count_11c;
    char pad_120[0x34];
    int id_154;
    char toggle_158;
    char pad_159[3];
    char enabled_15c;
    char pad_15d[0xf];
    int color_16c;

    // EXTERNAL: TITANIUM 0x0059BB00 StateAt15C_guess::RemoveLine
    void RemoveLine(int value);
    // EXTERNAL: TITANIUM 0x00597ED0 StateAt15C_guess::GetItemData
    struct EQPlayerView_guess* GetItemData(int index);
    // EXTERNAL: TITANIUM 0x00597C60 StateAt15C_guess::SetColors
    void SetColors(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x0059B800 StateAt15C_guess::Add_guess
    void Add_guess(ItemAt8c_guess* item);
};

struct EQPlayerView_guess {
    char pad_000;
    char name_001[0x11f];           // 0x001
    char text_120[0x40];            // 0x120
    char name_160[0xf2];            // 0x160
    unsigned char flag_252;         // 0x252
    char pad_253[5];
    int spawnId_258_guess;                  // 0x258
    char pad_25c[4];
    int field_260;                  // 0x260
};

struct TimerAt160_guess {
    char pad_000[0x128];
    char enabled_128;               // 0x128
    // EXTERNAL: TITANIUM 0x005BB140 TimerAt160_guess::SetCheck
    void SetCheck(bool value);
};

struct CXStrMatch_guess {
    // EXTERNAL: TITANIUM 0x00574030 CXStrMatch_guess::Match_guess
    char Match_guess(const CXStr& text, int pos);
};

#define g_selected_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"


// EXTERNAL: TITANIUM 0x00654598 ??_7CFindLocationWnd_guess@@6B@
struct CFindLocationWnd_guess : CSidlScreenWndBase {
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
    StateAt15C_guess* state_15c;
    void InitializeChildren_guess();
    CFindLocationWnd_guess(CXWnd* parent);
    void Update_guess(int value);
    char StartFind_guess();
    // EXTERNAL: TITANIUM 0x0056768B CFindLocationWnd_guess::Pick_guess
    int Pick_guess();
    int Route_guess(CXWnd* sender, unsigned int message, int data);
    void Reset_guess(int value);
    void Loop_guess();
    char AddListRow_guess(int value);
    char IsClassTrainer_guess(EQPlayerView_guess* other);
    char IsFilteredOut_guess(EQPlayerView_guess* other);
    void AddSpawn_guess(int value);
    void RebuildList_guess();
    void LoopAndClear_guess();
    void Init_guess();
    char BuildLocationListCallback_guess();
    char ResetLocationListCallback_guess();
    // EXTERNAL: TITANIUM 0x005A1EF0 CFindLocationWnd_guess::LoadIniListWnd
    void LoadIniListWnd(StateAt15C_guess* state, const char* name);
    // EXTERNAL: TITANIUM 0x005A1FE0 CFindLocationWnd_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(StateAt15C_guess* state, const char* name);
    char RemoveSpawnRow_guess(EQPlayerView_guess* other);
    char FindIndex_guess(EQPlayerView_guess* other, unsigned int* index);
    char Remove_guess(EQPlayerView_guess* other);
    char RemoveByValue_guess(int value);
    char Append_guess(int value);
    virtual ~CFindLocationWnd_guess();
    CFindLocationWnd_guess* Delete_guess(unsigned char flags);
    TimerAt160_guess* timer_160;
    unsigned int clock_164;
    unsigned int lastCheck_168;
    struct EmbeddedAt16C_guess {
        unsigned int count_000;
        EQPlayerView_guess** data_004;
        int unknown_008;
        unsigned char flag_00c;
        EmbeddedAt16C_guess() {
            data_004 = 0;
            count_000 = 0;
            unknown_008 = 0;
            flag_00c = 1;
        }
        ~EmbeddedAt16C_guess() { Clear_guess(); }
        // EXTERNAL: TITANIUM 0x004EB924 CFindLocationWnd_guess::EmbeddedAt16C_guess::Slot_guess
        EQPlayerView_guess** Slot_guess(int index);
        void Clear_guess();
        // EXTERNAL: TITANIUM 0x00564298 CFindLocationWnd_guess::EmbeddedAt16C_guess::DeleteElement_guess
        void DeleteElement_guess(int index);
    } cachedSpawns_16c_guess;
    char pad_17c[4];
    TableAt180_guess* table_180;
    char pad_184[0x7f8 - 0x184];
    unsigned int field_7f8;             /* CXStr handle, passed by address */
    CXStr GetLabel_guess(int index);
};

struct ObjectAt16C_guess {
    char pad_000[0x16c];
    int value_16c;
    int GetValue_guess();
};

struct ByteGate_guess {
    char enabled_00;
    // EXTERNAL: TITANIUM 0x004C13D7 ByteGate_guess::Cancel_guess
    void Cancel_guess();
};

struct ClockManager_guess {
    char pad_000[0x148];
    unsigned int clock_148;
};

#define g_clockManager_guess EQ_GLOBAL(ClockManager_guess*, 0x00905D24)

struct ObjectAt164_guess {
    char pad_000[0x164];
    unsigned int lastUpdate_164;
    void OnTimer_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 ObjectAt164_guess::OnProcessFrame
    void OnProcessFrame();
};

struct IndexBuffer_guess {
    int count_000;
    int* data_004;
    // EXTERNAL: TITANIUM 0x004EB943 IndexBuffer_guess::Reserve_guess
    void Reserve_guess(int count);
    void SetAt_guess(int index, int* value);
};

// EXTERNAL: TITANIUM 0x0059DD30 TimerCheck_guess
char __cdecl TimerCheck_guess();

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* out, int id, const char* arg, ...);
// EXTERNAL: TITANIUM 0x00416C2C ClassName_guess
char* __cdecl ClassName_guess(int id_guess);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value, char* buffer, int radix);
#define g_numberBuf_guess EQ_ARRAY(char, 0x0099DB00)

struct HookSink_guess {
    // EXTERNAL: TITANIUM 0x004C251B HookSink_guess::Fire_guess
    void Fire_guess(int value);
};
#define g_hookSink_guess EQ_GLOBAL(HookSink_guess*, 0x00985C88)

struct TableAt180_guess {
    char pad_000[8];
    int count_008;
};

struct ArrayClass_guess {
    int count_000;
    int alloc_004;
    int mask_008;
    int shift_00c;
    int** blocks_010;
    int blockCount_014;
    unsigned int flag_018;
    int cursor_01c;
    // EXTERNAL: TITANIUM 0x0047C3AF ArrayClass_guess::Initialize_guess
    void Initialize_guess(int size);
    ArrayClass_guess(int size) { Initialize_guess(size); }
    // EXTERNAL: TITANIUM 0x00406E7E ArrayClass_guess::~ArrayClass_guess
    ~ArrayClass_guess();
};

struct ListFill_guess {
    // EXTERNAL: TITANIUM 0x0059BB50 ListFill_guess::Fill_guess
    void Fill_guess(ArrayClass_guess* out);
};

// EXTERNAL: TITANIUM 0x004D9090 Join_guess
CXStr __cdecl Join_guess(const CXStr& left, const CXStr& right);

// Row `index`'s text with the prefix at +0x7F8 in front; empty when out of range.
// FUNCTION: TITANIUM 0x00502AA1
// @early-stop: budget, structural ndiff=13
CXStr CFindLocationWnd_guess::GetLabel_guess(int index) {
    CXStr result;
    int count = reinterpret_cast<CXStr*>(&table_180)->Ptr != 0 ? reinterpret_cast<CXStr*>(&table_180)->Ptr->length : 0;
    if (count > 0) {
        result = Join_guess(*reinterpret_cast<CXStr*>(&field_7f8), *reinterpret_cast<CXStr*>(&table_180));
    }
    CListWnd* list = reinterpret_cast<CListWnd*>(clock_164);
    if (list != 0) {
        ArrayClass_guess items(0x20);
        reinterpret_cast<ListFill_guess*>(list)->Fill_guess(&items);
        if (index < items.count_000) {
            result = Join_guess(*reinterpret_cast<CXStr*>(&field_7f8), list->GetItemText(items.blocks_010[index >> items.shift_00c][index & items.mask_008], 0));
        }
    }
    return result;
}

// Find window OnProcessFrame (vtable 0x654598 slot 43): while 0x0059DD30 holds, moves the time stamp at
// +0x164 up to the game clock (0x905D24 +0x148) once it is more than a second behind; then the CXWnd
// OnProcessFrame (0x005A0E50).
// FUNCTION: TITANIUM 0x00502BF4
void ObjectAt164_guess::OnTimer_guess() {
    if (TimerCheck_guess()) {
        if (g_clockManager_guess->clock_148 > lastUpdate_164 + 1000) {
            lastUpdate_164 = g_clockManager_guess->clock_148;
        }
    }
    OnProcessFrame();
}

// Find window AboutToShow (vtable 0x654598 slot 49): loads the FLW_FindLocationList (+0x15C) INI
// settings under "LocationList" (0x005A1EF0); never vetoes.
// FUNCTION: TITANIUM 0x00502C28
char CFindLocationWnd_guess::BuildLocationListCallback_guess() {
    LoadIniListWnd(state_15c, "LocationList");
    return 1;
}

// Find window AboutToHide (vtable 0x654598 slot 50): stores the FLW_FindLocationList (+0x15C) INI
// settings under "LocationList" (0x005A1FE0); never vetoes.
// FUNCTION: TITANIUM 0x00502C3B
char CFindLocationWnd_guess::ResetLocationListCallback_guess() {
    StoreIniListWnd_guess(state_15c, "LocationList");
    return 1;
}

// Sort request from the list (message 0xF, probably a column click): the same column flips the direction, a
// new one sorts ascending.
// FUNCTION: TITANIUM 0x00502C4E
void CFindLocationWnd_guess::Update_guess(int value) {
    if (state_15c != 0) {
        int* id = &state_15c->id_154;
        if (*id == value) {
            state_15c->toggle_158 = !state_15c->toggle_158;
        } else {
            *id = value;
            state_15c->toggle_158 = 1;
        }
        state_15c->Dispatch_guess();
    }
}

// Find window: deletes row `value` of the location list (+0x15C). Used to empty the list and to drop
// the row of a spawn that is no longer tracked.
// FUNCTION: TITANIUM 0x00502C97
void CFindLocationWnd_guess::Reset_guess(int value) {
    if (state_15c != 0) {
        return state_15c->RemoveLine(value);
    }
}

// Removes rows until the list is empty.
// FUNCTION: TITANIUM 0x00502CA9
void CFindLocationWnd_guess::Loop_guess() {
    StateAt15C_guess* state = state_15c;
    if (state != 0) {
        while (state->count_11c > 0) {
            Reset_guess(0);
            state = state_15c;
        }
    }
}

// Finds FLW_FindLocationList (+0x15C) and FLW_FilterLocationsCheckbox (+0x160).
// FUNCTION: TITANIUM 0x00502CD2
void CFindLocationWnd_guess::InitializeChildren_guess() {
    state_15c = (StateAt15C_guess*)((CSidlScreenWnd*)this)->GetChildItem("FLW_FindLocationList");
    timer_160 = (TimerAt160_guess*)((CSidlScreenWnd*)this)->GetChildItem("FLW_FilterLocationsCheckbox");
}

// List colours (yellow 0xFFFFFF00 text, grey 0xFF808080, highlight 0xFF8AA3FF), sort by column 0, filter box
// checked.
// FUNCTION: TITANIUM 0x00502D5F
void CFindLocationWnd_guess::Init_guess() {
    if (state_15c != 0) {
        state_15c->SetColors(-1, 0xffffff00, 0xff808080);
        state_15c->color_16c = 0xff8aa3ff;
        state_15c->enabled_15c = 1;
        state_15c->flags_66 |= 4;
        state_15c->id_154 = 0;
    }
    if (timer_160 != 0) {
        timer_160->SetCheck(1);
    }
}

// Removes the list row for spawn `other` (matched by spawn id); true if one was found.
// FUNCTION: TITANIUM 0x00502DC4
char CFindLocationWnd_guess::RemoveSpawnRow_guess(EQPlayerView_guess* other) {
    char found = 0;
    int value = other->spawnId_258_guess;
    int count = state_15c->count_11c;
    for (int i = 0; i < count; i++) {
        EQPlayerView_guess* element = state_15c->GetItemData(i);
        if (value == element->spawnId_258_guess) {
            Reset_guess(i);
            found = 1;
            break;
        }
    }
    return found;
}

// True when the spawn's name is a class name (strings 1502-1558 and 5791, "Warrior" ... "Berserker"), i.e. a
// class trainer.
// FUNCTION: TITANIUM 0x00502E1F
char CFindLocationWnd_guess::IsClassTrainer_guess(EQPlayerView_guess* other) {
    int ids[16] = { 0x5fa, 0x616, 0x169f, 0x5e2, 0x5f2, 0x612, 0x60e, 0x5f6,
                    0x606, 0x5e6, 0x5ee, 0x5fe, 0x5ea, 0x602, 0x5de, 0x60a };
    char found = 0;
    CXStr text;
    CXStr name(other->name_001);
    for (unsigned int i = 0; i < 16; i++) {
        text = pStringTable->getString(ids[i], 0);
        if (((CXStrMatch_guess*)&name)->Match_guess(text, 0)) {
            found = 1;
            break;
        }
    }
    return found;
}

// Find button: within 15 s of the last find shows string 6196 "You may not initiate a Find path for %1
// seconds." (chat colour 15); otherwise starts a path to the selected spawn (Pick_guess) and restarts the
// timer.
// FUNCTION: TITANIUM 0x00502F3E
char CFindLocationWnd_guess::StartFind_guess() {
    char result = 0;
    char buf[1024];
    unsigned int elapsed = (g_clockManager_guess->clock_148 - lastCheck_168) / 1000;
    if (elapsed < 0xf && lastCheck_168 != 0) {
        FUN_0046da4a_guess(buf, 0x1834, _itoa(0xf - elapsed, g_numberBuf_guess, 10), 0, 0, 0, 0, 0, 0, 0, 0);
        pEverQuest->dsp_chat(buf, 0xf, 1);
    } else {
        int picked = Pick_guess();
        if (picked != 0) {
            g_hookSink_guess->Fire_guess(picked);
            result = 1;
            lastCheck_168 = g_clockManager_guess->clock_148;
        }
    }
    return result;
}

// Whether a find path is running (first byte of the path follower at 0x985C88). The Find command uses
// it to cancel a running path instead of opening the window; the actions window checks it for its Find
// button.
// FUNCTION: TITANIUM 0x00502F2F
char __cdecl GetByte_guess() {
    return *g_bytePointer_guess;
}

// Find window: number of tracked spawns (+0x16C). The Find command shows the window when there is at
// least one, else prints string 0x1A8C.
// FUNCTION: TITANIUM 0x00502F37
int ObjectAt16C_guess::GetValue_guess() {
    return value_16c;
}

// Cancels a running find path (0x004C13D7) when the path follower (0x985C88) is active. Used by the
// Find command.
// FUNCTION: TITANIUM 0x0050300F
void __cdecl CheckByteGate_guess() {
    ByteGate_guess* gate = (ByteGate_guess*)g_bytePointer_guess;
    if (gate->enabled_00 != 0) {
        gate->Cancel_guess();
    }
}

// Find window: empties the location list (0x00502CA9) and frees the tracked spawn array (+0x16C). The
// UI rebuild (0x00437BCD) and the destructor call it.
// FUNCTION: TITANIUM 0x00503020
void CFindLocationWnd_guess::LoopAndClear_guess() {
    Loop_guess();
    cachedSpawns_16c_guess.Clear_guess();
}

// Index of spawn `other` (by id) in the tracked-spawn array, into `index` when given.
// FUNCTION: TITANIUM 0x00503034
char CFindLocationWnd_guess::FindIndex_guess(EQPlayerView_guess* other, unsigned int* index) {
    char found = 0;
    unsigned int count = cachedSpawns_16c_guess.count_000;
    for (unsigned int i = 0; i < count; i++) {
        if (other->spawnId_258_guess == (*cachedSpawns_16c_guess.Slot_guess(i))->spawnId_258_guess) {
            if (index != 0) {
                *index = i;
            }
            found = 1;
            break;
        }
    }
    return found;
}

// Find window: drops spawn `other` from the tracked spawn array; true when it was there. Used when a
// spawn stops being findable (0x005032E3).
// FUNCTION: TITANIUM 0x00503086
char CFindLocationWnd_guess::Remove_guess(EQPlayerView_guess* other) {
    unsigned int index;
    if (FindIndex_guess(other, &index)) {
        cachedSpawns_16c_guess.DeleteElement_guess(index);
        return 1;
    }
    return 0;
}

// Filter test, only while the filter box is checked: true (hide) for a trainer of another class than the
// local player, and for a class-63 spawn ('?', tribute master) whose +0x260 value differs from the player's
// (probably the guild).
// FUNCTION: TITANIUM 0x005030B5
char CFindLocationWnd_guess::IsFilteredOut_guess(EQPlayerView_guess* other) {
    char changed = 0;
    if (timer_160 != 0 && timer_160->enabled_128 != 0 && g_selected_guess != 0) {
        if (IsClassTrainer_guess(other)) {
            CXStr current(ClassName_guess(g_selected_guess->flag_252));
            CXStr name(other->name_001);
            if (!((CXStrMatch_guess*)&name)->Match_guess(current, 0)) {
                changed = 1;
            }
        } else if (other->flag_252 == '?') {
            changed = other->field_260 != g_selected_guess->field_260;
        }
    }
    return changed;
}

// Stores `*value` at `index`, growing the array to index + 1 when needed.
// FUNCTION: TITANIUM 0x0050319B
void IndexBuffer_guess::SetAt_guess(int index, int* value) {
    if (index >= 0) {
        if (index >= count_000) {
            int newCount = index + 1;
            Reserve_guess(newCount);
            if (data_004 != 0) {
                count_000 = newCount;
            }
        }
        if (data_004 != 0) {
            data_004[index] = *value;
        }
    }
}

// Find location window constructor: finds FLW_FindLocationList and the filter check box (0x00502CD2),
// sets them up (0x00502D5F) and keeps the creation time (+0x164).
// FUNCTION: TITANIUM 0x005031D3
CFindLocationWnd_guess::CFindLocationWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "FindLocationWnd", 0xfffffeff, 1, 0) {
    state_15c = 0;
    timer_160 = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        InitializeChildren_guess();
        Init_guess();
        clock_164 = g_clockManager_guess->clock_148;
        lastCheck_168 = 0;
    }
}

// Destructor of the find window (vtable 0x654598): empties the list and the tracked spawns
// (0x00503020), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0050329D
CFindLocationWnd_guess::~CFindLocationWnd_guess() {
    LoopAndClear_guess();
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Stops tracking the spawn with id `value` and drops its list row.
// FUNCTION: TITANIUM 0x005032E3
char CFindLocationWnd_guess::RemoveByValue_guess(int spawnId) {
    char removed = 0;
    if (state_15c != 0) {
        int count = cachedSpawns_16c_guess.count_000;
        for (int i = 0; i < count; i++) {
            EQPlayerView_guess* element = *cachedSpawns_16c_guess.Slot_guess(i);
            if (spawnId == element->spawnId_258_guess) {
                removed = Remove_guess(element);
                RemoveSpawnRow_guess(element);
                break;
            }
        }
    }
    return removed;
}

// Scalar deleting destructor of the find window (vtable 0x654598 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x0050334F
CFindLocationWnd_guess* CFindLocationWnd_guess::Delete_guess(unsigned char flags) {
    this->CFindLocationWnd_guess::~CFindLocationWnd_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Tracks spawn `value` (a spawn pointer passed as int).
// FUNCTION: TITANIUM 0x0050336B
char CFindLocationWnd_guess::Append_guess(int value) {
    IndexBuffer_guess* buffer = (IndexBuffer_guess*)&cachedSpawns_16c_guess;
    buffer->SetAt_guess(buffer->count_000, &value);
    return 1;
}

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* dest, const char* source, int count);

struct EverQuestText_guess {
    // EXTERNAL: TITANIUM 0x00492EC2 EverQuestText_guess::Store_guess
    char* Store_guess(char* text);
};
#define g_everQuest_guess EQ_GLOBAL(EverQuestText_guess*, 0x00988DF0)

struct StateEntry_guess {
    int value_guess;
    CXStr text_guess;
    int style_guess;
    StateEntry_guess() : style_guess(-1) {
        value_guess = 0;
    }
};

struct ItemAt8c_guess {
    int index_guess;
    int field_004_guess;
    int field_008_guess;
    unsigned char flag_00c_guess;
    void* rec_guess;
    int field_014_guess;
    unsigned char flag_018_guess;
    unsigned char flag_019_guess;
    ItemAt8c_guess() {
        field_014_guess = -1;
        field_004_guess = 0;
        index_guess = 0;
        field_008_guess = 0;
        flag_00c_guess = 1;
        rec_guess = 0;
        flag_018_guess = 0;
        flag_019_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x0042D7A7 ItemAt8c_guess::Set_guess
    void Set_guess(int index, StateEntry_guess* value);
    // EXTERNAL: TITANIUM 0x0042D7E5 ??1ItemAt8c_guess@@QAE@XZ
    ~ItemAt8c_guess();
};

// Adds a list row for spawn `value` (name, and the +0x120 text trimmed) unless the filter hides it.
// FUNCTION: TITANIUM 0x00503382
char CFindLocationWnd_guess::AddListRow_guess(int value) {
    EQPlayerView_guess* other = (EQPlayerView_guess*)value;
    if (IsFilteredOut_guess(other) == 0) {
        char name30[0x20];
        char text70[0x40];
        steve_strncpy_guess(text70, other->text_120, 0x40);
        steve_strncpy_guess(name30, other->name_001, 0x20);
        steve_strncpy_guess(text70, g_everQuest_guess->Store_guess(text70), 0x40);
        ItemAt8c_guess item;
        StateEntry_guess s1;
        StateEntry_guess s2;
        s1.text_guess = name30;
        s2.text_guess = text70;
        item.Set_guess(item.index_guess, &s1);
        item.Set_guess(item.index_guess, &s2);
        item.rec_guess = other;
        state_15c->Add_guess(&item);
        return 1;
    }
    return 0;
}

// New findable spawn: tracked and listed once.
// FUNCTION: TITANIUM 0x0050353E
void CFindLocationWnd_guess::AddSpawn_guess(int value) {
    if (state_15c != 0) {
        if (!FindIndex_guess((EQPlayerView_guess*)value, 0)) {
            Append_guess(value);
            AddListRow_guess(value);
        }
    }
}

// Filter box clicked: clears the list and re-adds every tracked spawn under the new filter.
// FUNCTION: TITANIUM 0x005034FB
void CFindLocationWnd_guess::RebuildList_guess() {
    if (state_15c != 0) {
        state_15c->Slot76_guess();
        unsigned int count = cachedSpawns_16c_guess.count_000;
        for (unsigned int i = 0; i < count; i++) {
            AddListRow_guess(reinterpret_cast<int>(*cachedSpawns_16c_guess.Slot_guess(i)));
        }
    }
}

// Destructor of the client's growable array: frees the element buffer and zeroes the pointer, capacity
// and count. Shared by many owners (window lists, compass markers, menu nodes, rule sets).
// FUNCTION: TITANIUM 0x0050F3F6
void CFindLocationWnd_guess::EmbeddedAt16C_guess::Clear_guess() {
    if (data_004 != 0) {
        FreeArray_guess(data_004);
    }
    data_004 = 0;
    unknown_008 = 0;
    count_000 = 0;
}

// List click: find (and close on success); list header: sort; filter box: rebuild.
// FUNCTION: TITANIUM 0x00503570
int CFindLocationWnd_guess::Route_guess(CXWnd* sender, unsigned int message, int data) {
    int result = 0;
    if (sender != 0) {
        StateAt15C_guess* state = state_15c;
        if (sender == reinterpret_cast<CXWnd*>(state) && message == 1) {
            if (StartFind_guess()) {
                Slot34_guess();
            }
        } else if (sender == reinterpret_cast<CXWnd*>(state_15c) && message == 0xf) {
            Update_guess(data);
        } else if (sender == reinterpret_cast<CXWnd*>(timer_160) && message == 1) {
            RebuildList_guess();
        } else {
            result = ((CSidlScreenWnd*)this)->WndNotification(sender, message, (void*)data);
        }
    }
    return result;
}
