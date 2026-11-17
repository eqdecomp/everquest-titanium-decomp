// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 160: a hint from compare/tumap.py.
// Gems, the falling-block minigame window (SIDL "GemsGameWnd", GGW_* children): spell-gem icons from
// A_SpellGems drop into a 10x12 grid; three or more of a kind in a line score and set off that kind's
// effect (most kinds need four).
// CGemsGameWndView_guess is the same object as CGemsGameWnd_guess (one vtable, 0x6549E8); slot cells are
// 16 bytes (kind or -1, fall offset, falling flag). High scores live in chs.dat.
#include "titanium/types.h"
#include <stdio.h>

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

struct Slot_guess {
    int state_guess;
    int pad_4_guess;
    union {
        int active_guess;
        struct ReleaseObject_guess* object_guess;
    };
    int pad_c_guess;
};

struct ReleaseObject_guess {
    virtual void Release_guess(int flags);
};

// EXTERNAL: TITANIUM 0x005A3100 ??1Base_guess@@UAE@XZ
struct Base_guess {
    virtual ~Base_guess();
};

struct Entry_guess {
    int first_guess;
    int second_guess;
    char flag_guess;
    char pad_9_guess[0x3f];
};

struct Record_guess {
    int* target_guess;
    int first_guess;
    int second_guess;
};

struct DrawBuffer_guess {
    int values_guess[4];
};

struct DrawRect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
};

struct DrawPoint_guess {
    int x_guess;
    int y_guess;
};

struct Quad_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9139 Quad_guess::Add_guess
    void Add_guess(const DrawPoint_guess* point, const Quad_guess* size);
    // EXTERNAL: TITANIUM 0x004D9160 Quad_guess::Copy_guess
    void Copy_guess(Quad_guess* destination, const Quad_guess* source);
};

struct VirtualWndSlots_guess {
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
};

struct VirtualWnd_guess : VirtualWndSlots_guess {
    virtual Quad_guess* Slot57_guess(Quad_guess* screen);
};

struct GemsBoard_guess {
    char pad_000_de8_guess[0xde8];
    Quad_guess gemSize_de8_guess;
    char pad_df8_eb4_guess[0xeb4 - 0xdf8];
    CXWnd* next_eb4_guess;
    CXWnd* special_eb8_guess;
    CXWnd* gameView_ebc_guess;
};

struct Renderer_guess {
    char pad_0_30_guess[0x30];
    int width_guess;
    int height_guess;
    // EXTERNAL: TITANIUM 0x005B1AB0 Renderer_guess::SetSource_guess
    void SetSource_guess(int source);
    // EXTERNAL: TITANIUM 0x005B1910 Renderer_guess::Draw_guess
    void Draw_guess(int* rect, DrawBuffer_guess* buffer, unsigned int color, unsigned int alpha);
};

// EXTERNAL: TITANIUM 0x006549E8 ??_7CGemsGameWndView_guess@@6B@
struct CGemsGameWndView_guess : Base_guess {
    char pad_4_5c_guess[0x58];
    char flag_5c_guess;
    char pad_5d_15c_guess[0xff];
    char enabled_15c_guess;
    int gameState_0160_guess;
    int value_164_guess;
    Entry_guess entries_guess[10];
    int score_0438_guess;
    int wave_043c_guess;
    char pad_440_480_guess[0x40];
    int value_480_guess;
    int value_484_guess;
    unsigned int value_488_guess;
    unsigned int value_48c_guess;
    Record_guess records_490_guess[22];
    int choices_598_guess[12];
    int value_5c8_guess;
    int activeEffect_05cc_guess;
    int value_5d0_guess;
    int flag_5d4_guess;
    int count_5d8_guess;
    int value_5dc_guess;
    int value_5e0_guess;
    float value_5e4_guess;
    int value_5e8_guess;
    int value_5ec_guess;
    int value_5f0_guess;
    int value_5f4_guess;
    int value_5f8_guess;
    int value_5fc_guess;
    int value_600_guess;
    int value_604_guess;
    union {
        Slot_guess slots_guess[1000];
        struct {
            char pad_608_d88_guess[0x780];
            int colors_d88_guess[11];
            int colors_db4_guess[11];
            int origin_x_de0_guess;
            int origin_y_de4_guess;
            char pad_de8_df0_guess[8];
            Renderer_guess* renderer_df0_guess;
            Renderer_guess* renderer_df4_guess;
            Renderer_guess* renderer_df8_guess;
        };
    };

    // EXTERNAL: TITANIUM 0x0059D6C0 CGemsGameWndView_guess::GetClientClipRect
    void GetClientClipRect(DrawBuffer_guess* buffer);
    void Draw_guess(int source, int x, int y, int unused_14, int unused_18, int index, char highlighted);
    void UpdateScore_guess(int amount);
    void UpdateTimer_guess();
    int GetRndBlockImage_guess();
    void SetInputCommand_guess(int value);
    char IsThreeMatchKind_guess(unsigned int value);
    void MarkColumnFalling_guess(int start, int count);
    void StartEffect_guess(int state);
    void ClearHighScores_guess();
    void LoadHighScoresFromFile_guess();
    void SaveHighScoresToFile_guess();
    void ProcessGemMatch_guess(int count);
    void StartNextWave_guess();
    int PostDraw_guess();
    void SetGamePauseState_guess(char enabled);
    void TogglePause_guess();
    void GetNextBlock_guess();
    void MoveColumnBlockHorizontally_guess(int amount);
    void UpdateGameState_guess();
    void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CGemsGameWndView_guess::OnProcessFrame
    void OnProcessFrame();
    void StepFallingGem_guess(int x, int y, int flag);
    void Restart_guess();
    void CheckAndProcessMatchingCells_guess(int x, int y);
    char TryMoveColumnCell_guess(int sourceX, int sourceY, int destX, int destY, char move);
    void CheckForNewHighScore_guess();
    // EXTERNAL: TITANIUM 0x005057D3 CGemsGameWndView_guess::FUN_005057d3_guess
    void FUN_005057d3_guess();
    virtual ~CGemsGameWndView_guess();
    CGemsGameWndView_guess* Delete_guess(int flags);
};

struct EQPlayerView_guess {
    // EXTERNAL: TITANIUM 0x00479EE8 EQPlayerView_guess::PlaySound_guess
    void PlaySound_guess(int amount);
};

struct Clock_guess {
    char pad_0_148_guess[0x148];
    int value_148_guess;
};

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess();
// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int low, int high);

#define g_allocator_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)
#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)
#define g_scale_guess EQ_GLOBAL(float, 0x006410D0)

// Deletes the copied A_SpellGems animation (+0xDF0, which slots_guess[126] overlaps).
// FUNCTION: TITANIUM 0x00504F33
CGemsGameWndView_guess::~CGemsGameWndView_guess() {
    if (slots_guess[126].object_guess != 0) {
        slots_guess[126].object_guess->Release_guess(1);
        slots_guess[126].object_guess = 0;
    }
}

// Score for the `amount`-th gem of a line: 225 * (amount^2 + 1). Effect 0x99 makes it a loss, 0x96
// doubles it.
// FUNCTION: TITANIUM 0x00504F7D
void CGemsGameWndView_guess::UpdateScore_guess(int amount) {
    int delta = amount * amount * 0xe1 + 0xe1;
    if (activeEffect_05cc_guess == 0x99) {
        delta = -delta;
    } else if (activeEffect_05cc_guess == 0x96) {
        delta += delta;
    }
    score_0438_guess += delta;
}

// Draws one gem: the tile tinted by `index` (0 blue 0xFF5242DE, 1 red 0xFFDE2121; brighter when
// `highlighted`), the icon `source` offset by +0xDE0/+0xDE4, then the overlay animation (+0xDF8).
// FUNCTION: TITANIUM 0x00504FB4
// @early-stop: budget, diff ndiff=8
void CGemsGameWndView_guess::Draw_guess(int source, int x, int y, int unused_14, int unused_18, int index, char highlighted) {
    DrawBuffer_guess buffer;
    GetClientClipRect(&buffer);
    renderer_df0_guess->SetSource_guess(source);
    unsigned int alpha = 0xff000000;
    if (renderer_df4_guess != 0) {
        if (highlighted != 0) {
            renderer_df4_guess->Draw_guess(&x, &buffer, colors_d88_guess[index] + 0x202020, alpha);
        } else {
            renderer_df4_guess->Draw_guess(&x, &buffer, colors_d88_guess[index], alpha);
        }
    }
    if (renderer_df0_guess != 0) {
        DrawRect_guess rect;
        int left = origin_x_de0_guess + x;
        int top = origin_y_de4_guess + y;
        int bottom = renderer_df0_guess->height_guess + top;
        int right = renderer_df0_guess->width_guess + left;
        rect.left_guess = left;
        rect.top_guess = top;
        rect.right_guess = right;
        rect.bottom_guess = bottom;
        if (index == 0) {
            renderer_df0_guess->Draw_guess(&rect.left_guess, &buffer, 0xffffffff, alpha);
        } else {
            renderer_df0_guess->Draw_guess(&rect.left_guess, &buffer, (colors_db4_guess[index] << 0x18) | 0xffffff, alpha);
        }
    }
    if (renderer_df8_guess != 0) {
        renderer_df8_guess->Draw_guess(&x, &buffer, 0xffffffff, alpha);
    }
}

// Next step time (+0x480): now + 40 ms minus wave * the factor at 0x6410D0, at least 2 ms.
// FUNCTION: TITANIUM 0x0050509B
void CGemsGameWndView_guess::UpdateTimer_guess() {
    int remaining = 0x28 - (int)(wave_043c_guess * g_scale_guess);
    int current = g_clock_guess->value_148_guess;
    if (remaining < 2) {
        ++current;
        ++current;
    } else {
        current += remaining;
    }
    value_480_guess = current;
}

// Kind of the next gem. While state 0x26 or 0x33 runs (+0x5CC, also copied to +0x5F8) every gem is
// that kind. Otherwise a percent roll under 36 picks one of the kinds in +0x598 entries 0-5, else one
// of entries 6-11; a 0x33 is re-rolled once on a second roll of 40 or less.
// FUNCTION: TITANIUM 0x005050D2
int CGemsGameWndView_guess::GetRndBlockImage_guess() {
    int state = activeEffect_05cc_guess;
    if (state == 0x26 || state == 0x33) {
        value_5f8_guess = state;
        return state;
    }
    int choice;
    if (number_percent_guess() < 0x24) {
        choice = choices_598_guess[RandomRange_guess(0, 5)];
    } else {
        choice = choices_598_guess[RandomRange_guess(6, 0x0b)];
        if (choice == 0x33) {
            if (number_percent_guess() <= 0x28) {
                choice = choices_598_guess[RandomRange_guess(6, 0x0b)];
            }
        }
    }
    return choice;
}

// True for the six kinds in choice-table entries 0-5 (+0x598: 4, 0x1C, 0x28, 0x2A, 0x55, 0x99): they trigger their
// effect with a line of 3 and draw on the red tile.
// FUNCTION: TITANIUM 0x00505136
char CGemsGameWndView_guess::IsThreeMatchKind_guess(unsigned int value) {
    switch (value) {
    case 4:
    case 0x1c:
    case 0x28:
    case 0x2a:
    case 0x55:
    case 0x99:
        return 1;
    default:
        return 0;
    }
}

// Starts effect `state` with sound 0x70 (0x479EE8 is the spawn PlaySound). Durations: kind 4 6 s,
// 0x15 6 s (clears the bottom row from 2 s on), 0x96 and 0x99 24 s, 0x67 none (it skips waves), others
// 12 s. A running 0x26 is not restarted.
// FUNCTION: TITANIUM 0x00505160
void CGemsGameWndView_guess::StartEffect_guess(int state) {
    if (state == 0x26 && activeEffect_05cc_guess == 0x26) {
        return;
    }
    g_allocator_guess->PlaySound_guess(0x70);
    activeEffect_05cc_guess = state;
    switch (state) {
    case 4:
        break;
    case 0x15:
        value_484_guess = g_clock_guess->value_148_guess + 2000;
        break;
    case 0x67:
        value_488_guess = 0;
        return;
    case 0x96:
    case 0x99:
        value_488_guess = g_clock_guess->value_148_guess + 24000;
        return;
    default:
        value_488_guess = g_clock_guess->value_148_guess + 12000;
        return;
    }
    value_488_guess = g_clock_guess->value_148_guess + 6000;
}

// Player input: 1000 drops the gem fast, anything else is a sideways step for the next tick.
// FUNCTION: TITANIUM 0x00505205
void CGemsGameWndView_guess::SetInputCommand_guess(int value) {
    if (value == 1000) {
        flag_5d4_guess = 1;
    } else {
        flag_5d4_guess = 0;
        value_5d0_guess = value;
    }
}

// Marks the occupied cells of column `start` above row `count` as falling, after a match below them.
// FUNCTION: TITANIUM 0x0050522C
void CGemsGameWndView_guess::MarkColumnFalling_guess(int start, int count) {
    int index = count;
    --index;
    if (index >= 0) {
        int* active = &slots_guess[start + index * 10].active_guess;
        ++index;
        do {
            if (active[-2] != -1) {
                *active = 1;
                ++count_5d8_guess;
            }
            active -= 40;
            --index;
        } while (index != 0);
    }
}

// Empties the ten high-score rows (score, wave, name).
// FUNCTION: TITANIUM 0x00505263
void CGemsGameWndView_guess::ClearHighScores_guess() {
    int i = 10;
    int* second = &entries_guess[0].second_guess;
    do {
        second[-1] = 0;
        second[0] = 0;
        ((Entry_guess*)(second - 1))->flag_guess = 0;
        second += 18;
        --i;
    } while (i != 0);
}

// Reads the ten 0x48-byte high-score rows from chs.dat; missing or negative-wave rows are cleared.
// FUNCTION: TITANIUM 0x0050527D
void CGemsGameWndView_guess::LoadHighScoresFromFile_guess() {
    FILE* file = fopen("chs.dat", "rb");
    if (file == 0) {
        return ClearHighScores_guess();
    }
    Entry_guess* entry = entries_guess;
    int count = 10;
    do {
        if (fread(entry, 0x48, 1, file) < 1 || entry->second_guess < 0) {
            entry->first_guess = 0;
            entry->second_guess = 0;
            entry->flag_guess = 0;
        }
        ++entry;
        --count;
    } while (count != 0);
    fclose(file);
}

// Writes the ten 0x48-byte high score entries to chs.dat (binary).
// FUNCTION: TITANIUM 0x005052E0
void CGemsGameWndView_guess::SaveHighScoresToFile_guess() {
    FILE* file = fopen("chs.dat", "wb");
    if (file != 0) {
        Entry_guess* entry = entries_guess;
        int count = 10;
        do {
            fwrite(entry, 0x48, 1, file);
            ++entry;
            --count;
        } while (count != 0);
        fclose(file);
    }
}

// Scores a line of `count` cells (from 3): sound 0x89, the line's kind starts its effect (the six
// kinds of 0x00505136 always, the others with 4 or more), the cells above fall, and all but the first
// cell are cleared.
// FUNCTION: TITANIUM 0x00505324
void CGemsGameWndView_guess::ProcessGemMatch_guess(int count) {
    if (count > 2) {
        int value = *records_490_guess[0].target_guess;
        g_allocator_guess->PlaySound_guess(0x89);
        char allowed = IsThreeMatchKind_guess(value);
        int remaining = allowed ? count - 2 : count - 3;
        if (remaining > 0) {
            StartEffect_guess(value);
        }
        for (int i = 0; i < count; ++i) {
            MarkColumnFalling_guess(records_490_guess[i].first_guess, records_490_guess[i].second_guess);
            UpdateScore_guess(i);
            if (i > 0) {
                int* target = records_490_guess[i].target_guess;
                target[0] = -1;
                target[2] = 0;
                target[3] = 0;
                target[1] = 0;
            }
        }
    }
}

// After a gem lands at (`x`, `y`): collects same-kind runs through it vertically, horizontally and on
// both diagonals and scores each; the gem itself is cleared if any run counted.
// FUNCTION: TITANIUM 0x005053AB
// @early-stop: budget, structural ndiff=229
void CGemsGameWndView_guess::CheckAndProcessMatchingCells_guess(int x, int y) {
    int count;
    int any = 0;
    int row = y * 10;
    Slot_guess* start = &slots_guess[row + x];
    if (start->state_guess < 1) {
        return;
    }
    int value = start->state_guess;
    int left = x - 1;
    int up = y - 1;
    int right = x + 1;
    int down = y + 1;
    {
        int* zero = &records_490_guess[0].first_guess;
        count = 22;
        do {
            zero[-1] = 0;
            zero[0] = 0;
            zero[1] = 0;
            zero += 3;
            --count;
        } while (count != 0);
    }
    records_490_guess[0].target_guess = &start->state_guess;
    records_490_guess[0].first_guess = x;
    records_490_guess[0].second_guess = y;
    count = 1;
    for (int yy = down; yy < 12; ++yy) {
        int* cell = &slots_guess[x + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = x;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    for (int yy = up; yy >= 0; --yy) {
        int* cell = &slots_guess[x + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = x;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    ProcessGemMatch_guess(count);
    if (count > 2) any = 1;

    {
        int* zero = &records_490_guess[0].first_guess;
        count = 22;
        do {
            zero[-1] = 0;
            zero[0] = 0;
            zero[1] = 0;
            zero += 3;
            --count;
        } while (count != 0);
    }
    records_490_guess[0].target_guess = &start->state_guess;
    records_490_guess[0].first_guess = x;
    records_490_guess[0].second_guess = y;
    count = 1;
    for (int xx = right; xx < 10; ++xx) {
        int* cell = &slots_guess[xx + y * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = y;
        ++count;
    }
    for (int xx = left; xx >= 0; --xx) {
        int* cell = &slots_guess[xx + y * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = y;
        ++count;
    }
    ProcessGemMatch_guess(count);
    if (count > 2) any = 1;

    {
        int* zero = &records_490_guess[0].first_guess;
        count = 22;
        do {
            zero[-1] = 0;
            zero[0] = 0;
            zero[1] = 0;
            zero += 3;
            --count;
        } while (count != 0);
    }
    records_490_guess[0].target_guess = &start->state_guess;
    records_490_guess[0].first_guess = x;
    records_490_guess[0].second_guess = y;
    count = 1;
    for (int xx = right, yy = up; yy >= 0; --yy, ++xx) {
        if (xx > 9) break;
        int* cell = &slots_guess[xx + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    for (int xx = left, yy = down; yy < 12; ++yy, --xx) {
        if (xx < 0) break;
        int* cell = &slots_guess[xx + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    ProcessGemMatch_guess(count);
    if (count > 2) any = 1;

    {
        int* zero = &records_490_guess[0].first_guess;
        count = 22;
        do {
            zero[-1] = 0;
            zero[0] = 0;
            zero[1] = 0;
            zero += 3;
            --count;
        } while (count != 0);
    }
    records_490_guess[0].target_guess = &start->state_guess;
    records_490_guess[0].first_guess = x;
    records_490_guess[0].second_guess = y;
    count = 1;
    for (int xx = left, yy = up; yy >= 0; --yy, --xx) {
        if (xx < 0) break;
        int* cell = &slots_guess[xx + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    for (int xx = right, yy = down; yy < 12; ++yy, ++xx) {
        if (xx > 9) break;
        int* cell = &slots_guess[xx + yy * 10].state_guess;
        if (*cell != value) break;
        records_490_guess[count].target_guess = cell;
        records_490_guess[count].first_guess = xx;
        records_490_guess[count].second_guess = yy;
        ++count;
    }
    ProcessGemMatch_guess(count);
    if (count > 2) any = 1;

    if (any) {
        start->state_guess = -1;
        start->pad_4_guess = 0;
        start->active_guess = 0;
        start->pad_c_guess = 0;
    }
}

// Scalar deleting destructor of the gems game window (vtable 0x6549E8 slot 1): runs the destructor
// (0x00504F33) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00505DE2
CGemsGameWndView_guess* CGemsGameWndView_guess::Delete_guess(int flags) {
    this->CGemsGameWndView_guess::~CGemsGameWndView_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Next wave: a wave bonus (Adjust_guess(2)) after the first, 2 * wave + 50 gems (at most 400), and the
// wave banner (state 2 then 3). Effect 0x67 instead skips ahead up to four waves, 250 ms apart.
// FUNCTION: TITANIUM 0x00505E06
void CGemsGameWndView_guess::StartNextWave_guess() {
    if (wave_043c_guess > 0) {
        UpdateScore_guess(2);
    }
    ++wave_043c_guess;
    value_5d0_guess = 0;
    value_600_guess = 0;
    value_604_guess = wave_043c_guess * 2 + 0x32;
    if (value_604_guess > 400) {
        value_604_guess = 400;
    }
    gameState_0160_guess = 2;
    value_5c8_guess = 3;
    UpdateTimer_guess();
    value_484_guess = g_clock_guess->value_148_guess + 2000;
    if (activeEffect_05cc_guess == 0x67 && value_488_guess < 4) {
        ++value_488_guess;
        value_484_guess = g_clock_guess->value_148_guess + 0xfa;
        return;
    }
    activeEffect_05cc_guess = -1;
}

// While playing (state 1): every gem in the grid, the Next preview (hidden by effect 0x1C) and the
// icon of the running effect in GGW_Special.
// FUNCTION: TITANIUM 0x00505EB1
// @early-stop: budget, structural ndiff=86
int CGemsGameWndView_guess::PostDraw_guess() {
    Quad_guess screen_b;
    Quad_guess screen_a;
    Quad_guess board;
    Quad_guess rect;
    DrawPoint_guess point;
    int state;
    int* column;
    int x;
    int y;
    int* cell;
    if (gameState_0160_guess != 1) {
        return 0;
    }
    board.bottom_guess = 0;
    board.right_guess = 0;
    board.top_guess = 0;
    board.left_guess = 0;
    rect.bottom_guess = 0;
    rect.right_guess = 0;
    rect.top_guess = 0;
    rect.left_guess = 0;
    point.x_guess = 0;
    point.y_guess = 0;
    GemsBoard_guess* window = (GemsBoard_guess*)this;
    board.Copy_guess(&screen_b, ((VirtualWnd_guess*)window->gameView_ebc_guess)->Slot57_guess(&screen_a));
    column = &slots_guess[0].pad_4_guess;
    for (x = 0; x < 10; ++x) {
        cell = column;
        for (y = 0; y < 12; ++y) {
            state = cell[-1];
            if (state >= 0) {
                point.x_guess = value_5e8_guess * x + 6 + board.left_guess;
                point.y_guess = value_5ec_guess * y + cell[0] + 0x15 + board.top_guess;
                rect.Add_guess(&point, &window->gemSize_de8_guess);
                Draw_guess(state, rect.left_guess, rect.top_guess, rect.right_guess,
                    rect.bottom_guess, IsThreeMatchKind_guess(state), 0);
            }
            cell += 40;
        }
        column += 4;
    }
    if (activeEffect_05cc_guess != 0x1c) {
        rect.Copy_guess(&screen_a, ((VirtualWnd_guess*)window->next_eb4_guess)->Slot57_guess(&screen_b));
        point.x_guess = rect.left_guess - 3;
        point.y_guess = rect.top_guess + 0x14;
        rect.Add_guess(&point, &window->gemSize_de8_guess);
        Draw_guess(value_5fc_guess, rect.left_guess, rect.top_guess, rect.right_guess,
            rect.bottom_guess, IsThreeMatchKind_guess(value_5fc_guess), 0);
    }
    if (activeEffect_05cc_guess != -1) {
        rect.Copy_guess(&screen_a, ((VirtualWnd_guess*)window->special_eb8_guess)->Slot57_guess(&screen_b));
        point.x_guess = rect.left_guess + 7;
        point.y_guess = rect.top_guess + 0x14;
        rect.Add_guess(&point, &window->gemSize_de8_guess);
        Draw_guess(activeEffect_05cc_guess, rect.left_guess, rect.top_guess, rect.right_guess,
            rect.bottom_guess, IsThreeMatchKind_guess(activeEffect_05cc_guess), 0);
    }
    return 0;
}

// Pausing freezes the effect timer (+0x48C keeps the time left, capped back to 12 s if over 24 s);
// resuming restarts the step timer and the effect clock from it.
// FUNCTION: TITANIUM 0x005060D1
void CGemsGameWndView_guess::SetGamePauseState_guess(char enabled) {
    enabled_15c_guess = enabled;
    if (enabled == 0) {
        UpdateTimer_guess();
        value_484_guess = g_clock_guess->value_148_guess + 2000;
        if (activeEffect_05cc_guess != -1 && activeEffect_05cc_guess != 0x67) {
            value_488_guess = value_48c_guess + g_clock_guess->value_148_guess;
        }
    } else {
        if (activeEffect_05cc_guess != -1 && activeEffect_05cc_guess != 0x67) {
            value_48c_guess = value_488_guess - g_clock_guess->value_148_guess;
            if (value_48c_guess > 24000) {
                value_48c_guess = 12000;
            }
        }
    }
    value_5d0_guess = 0;
    flag_5d4_guess = 0;
    FUN_005057d3_guess();
}

// Gems game: toggles pause (0x005060D1 with the opposite of +0x15C) and updates the labels for the new
// state (0x005057D3). A click in the game view calls it (0x0050658A).
// FUNCTION: TITANIUM 0x00506177
void CGemsGameWndView_guess::TogglePause_guess() {
    SetGamePauseState_guess(enabled_15c_guess == 0);
    FUN_005057d3_guess();
}

// Whether cell (`destX`, `destY`) is inside the grid and free; with `move` the source cell moves there.
// FUNCTION: TITANIUM 0x00506192
// @early-stop: budget, structural ndiff=29
char CGemsGameWndView_guess::TryMoveColumnCell_guess(int sourceX, int sourceY, int destX, int destY, char move) {
    if (destX < 0 || destY < 0 || destX >= 10 || destY >= 12) {
        return 0;
    }
    if (slots_guess[destX + destY * 10].state_guess > -1 &&
        slots_guess[destX + destY * 10].pad_c_guess == 0) {
        return 0;
    }
    if (move) {
        slots_guess[destX + destY * 10].state_guess = slots_guess[sourceX + sourceY * 10].state_guess;
        slots_guess[destX + destY * 10].active_guess = slots_guess[sourceX + sourceY * 10].active_guess;
        slots_guess[destX + destY * 10].pad_c_guess = slots_guess[sourceX + sourceY * 10].pad_c_guess;
        slots_guess[destX + destY * 10].pad_4_guess = slots_guess[sourceX + sourceY * 10].pad_4_guess;
        slots_guess[sourceX + sourceY * 10].state_guess = -1;
        slots_guess[sourceX + sourceY * 10].active_guess = 0;
        slots_guess[sourceX + sourceY * 10].pad_c_guess = 0;
        slots_guess[sourceX + sourceY * 10].pad_4_guess = 0;
    }
    return 1;
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination, const char* source);

#include "titanium/layouts/core.h"

struct LookupRoot_guess {
    char pad_0_8_guess[8];
    VBTable* branch_guess;
    char pad_c_44_guess[0x38];
    char text_44_guess[1];
};

#define g_lookupRoot_guess EQ_GLOBAL(LookupRoot_guess*, 0x00905D00)

// Inserts the score (+0x438), wave and character name as a high-score row and saves chs.dat; the row
// index goes to +0x5DC for the highlight. Scores compare unsigned, so a negative score (effects 0x99,
// 0x2A) beats every row.
// FUNCTION: TITANIUM 0x00506257
// @early-stop: budget, structural ndiff=70
void CGemsGameWndView_guess::CheckForNewHighScore_guess() {
    int i;
    int j;
    Entry_guess* entry = entries_guess;
    for (i = 0; i < 10; ++i, ++entry) {
        if ((unsigned int)score_0438_guess > (unsigned int)entry->first_guess) {
            j = 9;
            if (i < 9) {
                do {
                    --j;
                    if (j >= 0) {
                        entries_guess[j + 1].first_guess = entries_guess[j].first_guess;
                        entries_guess[j + 1].second_guess = entries_guess[j].second_guess;
                        strcpy(&entries_guess[j + 1].flag_guess, &entries_guess[j].flag_guess);
                    }
                } while (j > i);
            }
            if (g_lookupRoot_guess != 0) {
                strcpy(pad_440_480_guess,
                    g_lookupRoot_guess->text_44_guess + g_lookupRoot_guess->branch_guess->vbase_offset);
            }
            entries_guess[i] = *(Entry_guess*)&score_0438_guess;
            value_5dc_guess = i;
            SaveHighScoresToFile_guess();
            return;
        }
    }
}

// Moves the gem at (`x`, `y`) down by its speed: 2 per tick (1 under effect 5), 18 for falling
// rubble, a fast drop or effect 0x33, 14 for the player's gem under effect 4. A landed gem is checked
// for lines; under effect 0x33 a landing bomb destroys the gem below it (sound 0x6E).
// FUNCTION: TITANIUM 0x00506304
void CGemsGameWndView_guess::StepFallingGem_guess(int x, int y, int flag) {
    int index;
    if (activeEffect_05cc_guess == 5) {
        index = x + y * 10;
        slots_guess[index].pad_4_guess += 1;
    } else {
        index = x + y * 10;
        slots_guess[index].pad_4_guess += 2;
    }
    if (flag_5d4_guess == 0 && flag != 0 && activeEffect_05cc_guess != 0x33) {
        if (activeEffect_05cc_guess == 4) {
            slots_guess[index].pad_4_guess += 0xc;
        }
    } else {
        slots_guess[index].pad_4_guess += 0x12;
    }
    if (slots_guess[index].pad_4_guess > 0) {
        int next = y + 1;
        if (TryMoveColumnCell_guess(x, y, x, next, 1) != 0) {
            slots_guess[x + next * 10].pad_4_guess = 1 - value_5ec_guess;
            if (flag != 0) {
                value_5f4_guess = next;
            }
        } else {
            if (activeEffect_05cc_guess == 0x33 && flag != 0 && value_5f8_guess == 0x33) {
                if (y < 11) {
                    Slot_guess* below = &slots_guess[index + 10];
                    below->state_guess = -1;
                    below->active_guess = 0;
                    below->pad_c_guess = 0;
                    below->pad_4_guess = 0;
                    g_allocator_guess->PlaySound_guess(0x6e);
                    return;
                }
                Slot_guess* cell = &slots_guess[index];
                cell->state_guess = -1;
                cell->active_guess = 0;
                cell->pad_c_guess = 0;
                cell->pad_4_guess = 0;
                g_allocator_guess->PlaySound_guess(0x6e);
            }
            slots_guess[index].pad_4_guess = 0;
            slots_guess[index].active_guess = 0;
            if (flag != 0) {
                value_5f8_guess = -1;
                value_5f0_guess = 0;
                value_5f4_guess = 0;
            } else {
                count_5d8_guess--;
                if (count_5d8_guess < 0) {
                    count_5d8_guess = 0;
                }
            }
            CheckAndProcessMatchingCells_guess(x, y);
        }
    }
}

// New game: score, wave and effects reset, grid emptied, first wave queued. Pressed during a game, at
// game over or on the high scores (states 1, 4, 5) it returns to the title (state 0) instead.
// FUNCTION: TITANIUM 0x00506486
void CGemsGameWndView_guess::Restart_guess() {
    value_5e4_guess = 0.0f;
    value_164_guess = gameState_0160_guess;
    value_5dc_guess = -1;
    activeEffect_05cc_guess = -1;
    value_5f8_guess = -1;
    value_5e0_guess = -120;
    value_488_guess = 0;
    score_0438_guess = 0;
    wave_043c_guess = 0;
    count_5d8_guess = 0;
    value_5f0_guess = 0;
    value_5f4_guess = 0;
    value_5fc_guess = GetRndBlockImage_guess();
    int col = 10;
    Slot_guess* cell = slots_guess;
    do {
        int row = 12;
        Slot_guess* slot = cell;
        do {
            slot->state_guess = -1;
            slot->active_guess = 0;
            slot->pad_c_guess = 0;
            slot->pad_4_guess = 0;
            slot += 10;
            --row;
        } while (row != 0);
        ++cell;
        --col;
    } while (col != 0);
    StartNextWave_guess();
    SetGamePauseState_guess(0);
    int state = value_164_guess;
    if (state == 1 || state == 4 || state == 5) {
        gameState_0160_guess = 0;
    }
}

// Game step, skipped while paused: runs the effects (0x67 waves, 0x15 clears the bottom row with sound
// 0x63, expiry), then on each step time spawns, moves and drops gems. Effect 0x2A costs 1 point per
// step. A step time over 320 ms away (after a pause) is reset.
// FUNCTION: TITANIUM 0x00506774
void CGemsGameWndView_guess::UpdateGameState_guess() {
    if (enabled_15c_guess != 0) {
        return;
    }
    if (activeEffect_05cc_guess != -1) {
        if (activeEffect_05cc_guess == 0x67) {
            if ((unsigned int)g_clock_guess->value_148_guess > (unsigned int)value_484_guess) {
                StartNextWave_guess();
            }
        } else {
            if (activeEffect_05cc_guess == 0x15 && (unsigned int)g_clock_guess->value_148_guess > (unsigned int)value_484_guess) {
                int any = 0;
                int* cell = &slots_guess[110].pad_c_guess;
                int i = 0;
                do {
                    if (cell[-3] != -1) {
                        any = 1;
                    }
                    MarkColumnFalling_guess(i, 11);
                    cell[-3] = -1;
                    cell[-1] = 0;
                    cell[0] = 0;
                    cell[-2] = 0;
                    ++i;
                    cell += 4;
                } while (i < 10);
                if (any) {
                    g_allocator_guess->PlaySound_guess(0x63);
                }
            }
            if ((unsigned int)g_clock_guess->value_148_guess > (unsigned int)value_488_guess) {
                if (value_5fc_guess == activeEffect_05cc_guess) {
                    activeEffect_05cc_guess = -1;
                    value_5fc_guess = GetRndBlockImage_guess();
                } else {
                    activeEffect_05cc_guess = -1;
                }
            }
        }
    }
    if ((unsigned int)g_clock_guess->value_148_guess < (unsigned int)value_480_guess) {
        if ((unsigned int)value_480_guess - (unsigned int)g_clock_guess->value_148_guess <= 0x140) {
            return;
        }
    } else {
        if (activeEffect_05cc_guess == 0x2a) {
            --score_0438_guess;
        }
        if (gameState_0160_guess == 3) {
            if ((unsigned int)g_clock_guess->value_148_guess > (unsigned int)value_484_guess ||
                (unsigned int)value_484_guess - (unsigned int)g_clock_guess->value_148_guess > 8000) {
                value_484_guess = g_clock_guess->value_148_guess + 2000;
                gameState_0160_guess = 2;
                value_5c8_guess = 1;
            }
        } else if (value_5f8_guess == -1) {
            GetNextBlock_guess();
        } else if (value_600_guess >= value_604_guess) {
            StartNextWave_guess();
        } else {
            MoveColumnBlockHorizontally_guess(value_5d0_guess);
            StepFallingGem_guess(value_5f0_guess, value_5f4_guess, 1);
            if (count_5d8_guess > 0) {
                for (int x = 0; x < 10; ++x) {
                    for (int y = 11; y >= 0; --y) {
                        if (slots_guess[x + y * 10].active_guess != 0 && (y != value_5f4_guess || x != value_5f0_guess)) {
                            StepFallingGem_guess(x, y, 0);
                        }
                    }
                }
            }
        }
    }
    UpdateTimer_guess();
}

// Per-frame. Game states (+0x160): 0 title, 1 playing, 2 switch to +0x5C8, 3 wave banner (2 s),
// 4 game over (to the high scores after 2 s when the score placed), 5 high scores.
// FUNCTION: TITANIUM 0x00506A3F
void CGemsGameWndView_guess::OnProcessFrame_guess() {
    if (flag_5c_guess != 0) {
        FUN_005057d3_guess();
        if (gameState_0160_guess == 1) {
            UpdateGameState_guess();
        } else if (gameState_0160_guess == 3) {
            UpdateGameState_guess();
        } else if (gameState_0160_guess == 2) {
            gameState_0160_guess = value_5c8_guess;
            if (gameState_0160_guess == -1) {
                gameState_0160_guess = 1;
            } else if (gameState_0160_guess == 3) {
                value_480_guess = g_clock_guess->value_148_guess + 2000;
            }
        } else if (gameState_0160_guess == 4 && value_5dc_guess != -1) {
            gameState_0160_guess = 2;
            value_5c8_guess = 5;
            value_484_guess = g_clock_guess->value_148_guess + 2000;
        }
    }
    OnProcessFrame();
}

/* ---- CGemsGameWnd::CGemsGameWnd(CXWnd*) (0x00506AE5) ------------------------------------------------
 * Layout: include/titanium/types.h CGemsGameWnd (0xEC0). */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// CTextureAnimation (0x4C bytes).
struct GemsAnimation_guess {
    char data[0x4c];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0GemsAnimation_guess@@QAE@XZ
    GemsAnimation_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ??4GemsAnimation_guess@@QAEAAU0@ABU0@@Z
    GemsAnimation_guess& operator=(const GemsAnimation_guess& other);
};

struct GemsSidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 GemsSidlManager_guess::FindAnimation_guess
    GemsAnimation_guess* FindAnimation_guess(const CXStr& name);
};

struct GemsPoint_guess {
    int x_guess;
    int y_guess;
};

struct GemsRow_guess {
    int value_0_guess;
    int value_4_guess;
    char text_8_guess[0x40];
};

struct GemsRect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004D9160 GemsRect_guess::Copy_guess
    void Copy_guess(CXRect* src, int value);
    // EXTERNAL: TITANIUM 0x004EA5BF GemsRect_guess::Contains_guess
    char Contains_guess(const GemsPoint_guess* point_guess);
};

struct GemsChildWnd_guess {
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
    virtual void Slot0A_guess();
    virtual void Slot0B_guess();
    virtual void Slot0C_guess();
    virtual void Slot0D_guess();
    virtual void Slot0E_guess();
    virtual void Slot0F_guess();
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
    virtual void Slot1A_guess();
    virtual void Slot1B_guess();
    virtual void Slot1C_guess();
    virtual void Slot1D_guess();
    virtual void Slot1E_guess();
    virtual void Slot1F_guess();
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
    virtual void Slot2A_guess();
    virtual void Slot2B_guess();
    virtual void Slot2C_guess();
    virtual void Slot2D_guess();
    virtual void Slot2E_guess();
    virtual void Slot2F_guess();
    virtual void SetShow_guess(int value, int flag);
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot3A_guess();
    virtual void Slot3B_guess();
    virtual void Slot3C_guess();
    virtual void Slot3D_guess();
    virtual void Slot3E_guess();
    virtual void SetText_guess(const CXStr& text);
    char pad_004_guess[0x78];
    unsigned int textColor_07c_guess;
    // EXTERNAL: TITANIUM 0x0059FA70 GemsChildWnd_guess::SetPos_guess
    void SetPos_guess(GemsPoint_guess* pos);
    // EXTERNAL: TITANIUM 0x0059D860 GemsChildWnd_guess::GetRect_guess
    int GetRect_guess(CXRect* out);
};

#define g_gemsSidlManager_guess EQ_GLOBAL(GemsSidlManager_guess*, 0x0099D3F4)

// The GGW_SpellGem template window: the game copies its size and four values from it.
struct GemsSpellGemWnd_guess : CXWnd {
    char pad_11c[0x64];
    int field_180;                          // 0x180
    int field_184;                          // 0x184
    char pad_188[0x14];
    int field_19c;                          // 0x19c
    char pad_1a0[4];
    int field_1a4;                          // 0x1a4
};

// EXTERNAL: TITANIUM 0x006549E8 ??_7CGemsGameWnd_guess@@6B@
struct CGemsGameWnd_guess : CSidlScreenWndBase {
    unsigned char flag_15c_guess;
    char pad_15d_guess[0x3];
    int state_160_guess;
    int value_164_guess;
    GemsRow_guess rows_168_guess[10];
    int value_438_guess;
    int value_43c_guess;
    char pad_440_guess[0x158];
    int choices_598_guess[12];              // 0x598
    char pad_5c8_guess[4];
    int state_5cc_guess;
    char pad_5d0_guess[0xc];
    int count_5dc_guess;
    int slide_5e0_guess;
    float timer_5e4_guess;
    int value_5e8_guess;                    // 0x5e8
    int value_5ec_guess;                    // 0x5ec
    char pad_5f0_guess[0x798];
    unsigned int color_d88;                 // 0xd88
    unsigned int rowColors_d8c[10];         // 0xd8c
    int field_db4;                          // 0xdb4
    int rowValues_db8[10];                  // 0xdb8
    int gemValue_de0;                       // 0xde0 (GGW_SpellGem +0x180)
    int gemValue_de4;                       // 0xde4 (+0x184)
    int gemWidth_de8;                       // 0xde8
    int gemHeight_dec;                      // 0xdec
    GemsAnimation_guess* gemsAnim_df0;      // 0xdf0 copy of A_SpellGems
    int gemValue_df4;                       // 0xdf4 (+0x19c)
    int gemValue_df8;                       // 0xdf8 (+0x1a4)
    CXWnd* startButton_dfc;                 // 0xdfc GGW_StartButton
    CXWnd* doneButton_e00;                  // 0xe00 GGW_DoneButton
    CXWnd* highScores_e04;                  // 0xe04 GGW_HighScores
    CXWnd* scoreHeader_e08;                 // 0xe08 GGW_ScoreHeader
    CXWnd* waveHeader_e0c;                  // 0xe0c GGW_WaveHeader
    CXWnd* highNames_e10[10];               // 0xe10 GGW_HighName0..9
    CXWnd* highScoreValues_e38[10];         // 0xe38 GGW_HighScore0..9
    CXWnd* highWaves_e60[10];               // 0xe60 GGW_HighWave0..9
    CXWnd* gameOver_e88;                    // 0xe88 GGW_GameOver
    CXWnd* instructions_e8c;                // 0xe8c GGW_Instructions
    CXWnd* instructions2_e90;               // 0xe90 GGW_Instructions2
    CXWnd* instructions3_e94;               // 0xe94 GGW_Instructions3
    CXWnd* largeWave_e98;                   // 0xe98 GGW_LargeWave
    CXWnd* largeWaveNbr_e9c;                // 0xe9c GGW_LargeWaveNbr
    CXWnd* paused_ea0;                      // 0xea0 GGW_Paused
    CXWnd* wave_ea4;                        // 0xea4 GGW_Wave
    CXWnd* waveNbr_ea8;                     // 0xea8 GGW_WaveNbr
    CXWnd* score_eac;                       // 0xeac GGW_Score
    CXWnd* scoreNbr_eb0;                    // 0xeb0 GGW_ScoreNbr
    CXWnd* next_eb4;                        // 0xeb4 GGW_Next
    CXWnd* special_eb8;                     // 0xeb8 GGW_Special
    CXWnd* gameView_ebc;                    // 0xebc GGW_GameView
    CGemsGameWnd_guess(CXWnd* parent);
    void Refresh_guess();
    int CheckPoint_guess(const GemsPoint_guess* point_guess, unsigned int flags);
    int WndNotification_guess(CXWnd* sender, int message, void* data);
    void InitializeGame_guess();
};

// Updates the labels for the game state. The high-score panel scrolls across the game view (3 px a
// frame, wrapping at -120) and the new row pulses through the alpha table +0xDB4.
// FUNCTION: TITANIUM 0x005057D3
// @early-stop: budget, structural ndiff=281
void CGemsGameWnd_guess::Refresh_guess() {
    int showFlag;
    char buf1[256];
    char buf2[32];
    sprintf(buf1, "%d", value_438_guess);
    if (scoreNbr_eb0 != 0) {
        {
            CXStr text(buf1);
            ((GemsChildWnd_guess*)scoreNbr_eb0)->SetText_guess(text);
        }
        showFlag = 0;
        ++showFlag;
        ((GemsChildWnd_guess*)scoreNbr_eb0)->SetShow_guess(state_160_guess != 0, showFlag);
    } else {
        showFlag = 0;
        ++showFlag;
    }
    sprintf(buf2, "%d", value_43c_guess);
    if (waveNbr_ea8 != 0) {
        {
            CXStr text(buf2);
            ((GemsChildWnd_guess*)waveNbr_ea8)->SetText_guess(text);
        }
        ((GemsChildWnd_guess*)waveNbr_ea8)->SetShow_guess(state_160_guess != 0, showFlag);
    }
    // Game states (+0x160): 0 instructions, 1 playing (Paused, Next and Special shown), 3 the big wave
    // banner, 4 game over, 5 the high-score panel.
    if (state_160_guess == 1) {
        if (paused_ea0 != 0) {
            ((GemsChildWnd_guess*)paused_ea0)->SetShow_guess(flag_15c_guess, showFlag);
        }
        if (next_eb4 != 0) {
            bool show = false;
            if (state_5cc_guess != 0x1c) {
                show = state_160_guess == 1;
            }
            ((GemsChildWnd_guess*)next_eb4)->SetShow_guess(show, showFlag);
        }
        if (special_eb8 != 0) {
            bool show = false;
            if (state_5cc_guess != -1) {
                show = state_160_guess == 1;
            }
            ((GemsChildWnd_guess*)special_eb8)->SetShow_guess(show, showFlag);
        }
    } else {
        if (paused_ea0 != 0) {
            ((GemsChildWnd_guess*)paused_ea0)->SetShow_guess(state_160_guess == 0 ? 0 : flag_15c_guess, showFlag);
        }
        if (next_eb4 != 0) {
            ((GemsChildWnd_guess*)next_eb4)->SetShow_guess(0, showFlag);
        }
        if (special_eb8 != 0) {
            ((GemsChildWnd_guess*)special_eb8)->SetShow_guess(0, showFlag);
        }
    }
    if (largeWave_e98 != 0) {
        ((GemsChildWnd_guess*)largeWave_e98)->SetShow_guess(state_160_guess == 3, showFlag);
    }
    if (largeWaveNbr_e9c != 0) {
        {
            CXStr text(buf2);
            ((GemsChildWnd_guess*)largeWaveNbr_e9c)->SetText_guess(text);
        }
        ((GemsChildWnd_guess*)largeWaveNbr_e9c)->SetShow_guess(state_160_guess == 3, showFlag);
    }
    if (gameOver_e88 != 0) {
        ((GemsChildWnd_guess*)gameOver_e88)->SetShow_guess(state_160_guess == 4, showFlag);
    }
    if (instructions_e8c != 0) {
        ((GemsChildWnd_guess*)instructions_e8c)->SetShow_guess(state_160_guess == 0, showFlag);
    }
    if (instructions2_e90 != 0) {
        ((GemsChildWnd_guess*)instructions2_e90)->SetShow_guess(state_160_guess == 0, showFlag);
    }
    if (instructions3_e94 != 0) {
        ((GemsChildWnd_guess*)instructions3_e94)->SetShow_guess(state_160_guess == 0, showFlag);
    }
    // In state 5 the high-score panel slides across the game view.
    bool isFive = state_160_guess == 5;
    if (highScores_e04 != 0) {
        if (isFive) {
            CXRect bounds;
            CXRect src;
            GemsRect_guess rect = {0, 0, 0, 0};
            GemsPoint_guess pos = {0, 0};
            int ret = ((GemsChildWnd_guess*)gameView_ebc)->GetRect_guess(&bounds);
            rect.Copy_guess(&src, ret);
            int x = rect.left_guess + slide_5e0_guess;
            if (x < rect.right_guess) {
                slide_5e0_guess += 3;
            } else {
                slide_5e0_guess = -0x78;
            }
            pos.y_guess = rect.top_guess + 5;
            pos.x_guess = x;
            ((GemsChildWnd_guess*)highScores_e04)->SetPos_guess(&pos);
        }
        ((GemsChildWnd_guess*)highScores_e04)->SetShow_guess(isFive, showFlag);
    }
    if (scoreHeader_e08 != 0) {
        ((GemsChildWnd_guess*)scoreHeader_e08)->SetShow_guess(isFive, showFlag);
    }
    if (waveHeader_e0c != 0) {
        ((GemsChildWnd_guess*)waveHeader_e0c)->SetShow_guess(isFive, showFlag);
    }
    for (int row = 0; row < 10; ++row) {
        GemsRow_guess* data = &rows_168_guess[row];
        int color = -1;
        if (row == count_5dc_guess) {
            int index = (int)timer_5e4_guess;
            int value = (&field_db4)[index];
            timer_5e4_guess = timer_5e4_guess + 0.2f;
            color = value << 0x18 | 0xffffff;
            if (timer_5e4_guess >= 11.0f) {
                timer_5e4_guess = 0.0f;
            }
        }
        if (highNames_e10[row] != 0) {
            {
                CXStr text(data->text_8_guess);
                ((GemsChildWnd_guess*)highNames_e10[row])->SetText_guess(text);
            }
            ((GemsChildWnd_guess*)highNames_e10[row])->textColor_07c_guess = color;
            ((GemsChildWnd_guess*)highNames_e10[row])->SetShow_guess(isFive, showFlag);
        }
        if (highScoreValues_e38[row] != 0) {
            sprintf(buf1, "%d", data->value_0_guess);
            {
                CXStr text(buf1);
                ((GemsChildWnd_guess*)highScoreValues_e38[row])->SetText_guess(text);
            }
            ((GemsChildWnd_guess*)highScoreValues_e38[row])->textColor_07c_guess = color;
            ((GemsChildWnd_guess*)highScoreValues_e38[row])->SetShow_guess(isFive, showFlag);
        }
        if (highWaves_e60[row] != 0) {
            sprintf(buf1, "%d", data->value_4_guess);
            {
                CXStr text(buf1);
                ((GemsChildWnd_guess*)highWaves_e60[row])->SetText_guess(text);
            }
            ((GemsChildWnd_guess*)highWaves_e60[row])->textColor_07c_guess = color;
            ((GemsChildWnd_guess*)highWaves_e60[row])->SetShow_guess(isFive, showFlag);
        }
    }
}

// Done closes the window; Start starts a game (or returns to the title, see Restart_guess).
// FUNCTION: TITANIUM 0x0050654E
int CGemsGameWnd_guess::WndNotification_guess(CXWnd* sender, int message, void* data) {
    if (message == 1) {
        if (sender == doneButton_e00) {
            ((VirtualWnd_guess*)this)->Slot34_guess();
        } else if (sender == startButton_dfc) {
            ((CGemsGameWndView_guess*)this)->Restart_guess();
            Refresh_guess();
        }
    }
    return 0;
}

// A click in the game view pauses or resumes, unless the high word of `flags` is 1.
// FUNCTION: TITANIUM 0x0050658A
int CGemsGameWnd_guess::CheckPoint_guess(const GemsPoint_guess* point_guess, unsigned int flags) {
    if (gameView_ebc != 0) {
        CXRect rect = gameView_ebc->GetScreenRect();
        if (((GemsRect_guess&)rect).Contains_guess(point_guess) && (flags & 0xffff0000) != 0x10000) {
            ((CGemsGameWndView_guess*)this)->TogglePause_guess();
        }
    }
    return 0;
}

// Drops the next gem in a random column; if that column and one more random pick are full the game
// is over (state 2 then 4) and the score is checked. Sound 0x6B when a bomb drops under effect 0x33.
// FUNCTION: TITANIUM 0x005065D2
void CGemsGameWndView_guess::GetNextBlock_guess() {
    ++value_600_guess;
    value_5f0_guess = RandomRange_guess(0, 9);
    value_5f4_guess = 0;
    if (slots_guess[value_5f0_guess].state_guess != -1) {
        value_5f0_guess = RandomRange_guess(0, 9);
        if (slots_guess[value_5f0_guess + value_5f4_guess * 10].state_guess != -1) {
            gameState_0160_guess = 2;
            value_5c8_guess = 4;
            CheckForNewHighScore_guess();
            return;
        }
    }
    value_5f8_guess = value_5fc_guess;
    value_5fc_guess = GetRndBlockImage_guess();
    slots_guess[value_5f0_guess + value_5f4_guess * 10].state_guess = value_5f8_guess;
    slots_guess[value_5f0_guess + value_5f4_guess * 10].active_guess = 1;
    slots_guess[value_5f0_guess + value_5f4_guess * 10].pad_c_guess = 0;
    slots_guess[value_5f0_guess + value_5f4_guess * 10].pad_4_guess = -10;
    if (activeEffect_05cc_guess == 0x33 && value_5f8_guess == 0x33) {
        g_allocator_guess->PlaySound_guess(0x6b);
    }
}

// Applies the sideways input: none under effect 0x33, reversed under 0x28, and under 0x55 a random
// drift each step (2 in 5 left).
// FUNCTION: TITANIUM 0x005066FC
void CGemsGameWndView_guess::MoveColumnBlockHorizontally_guess(int amount) {
    int state = activeEffect_05cc_guess;
    if (state == 0x33) {
        return;
    }
    if (amount == 0 && state != 0x55) {
        return;
    }
    if (state == 0x28) {
        amount = -amount;
    } else if (state == 0x55) {
        int roll = RandomRange_guess(0, 4);
        if (roll >= 0 && roll <= 1) {
            amount = -1;
        } else {
            amount = 1;
        }
    }
    int newValue = value_5f0_guess + amount;
    if (TryMoveColumnCell_guess(value_5f0_guess, value_5f4_guess, newValue, value_5f4_guess, 1)) {
        value_5f0_guess = newValue;
    }
    value_5d0_guess = 0;
}

// Loads the high scores, takes the cell size from GGW_SpellGem and fills the kind table: entries 0-5
// (0x2A, 4, 0x55, 0x99, 0x28, 0x1C) and 6-11 (0x96, 0x26, 0x15, 0x33, 5, 0x67) are A_SpellGems icons.
// FUNCTION: TITANIUM 0x00506990
// @early-stop: unknown, structural ndiff=5
void CGemsGameWnd_guess::InitializeGame_guess() {
    ((CGemsGameWndView_guess*)this)->LoadHighScoresFromFile_guess();
    value_5e8_guess = gemWidth_de8;
    int height = gemHeight_dec;
    int* flag = &state_160_guess;
    *flag = 0;
    choices_598_guess[0] = 0x2a;
    choices_598_guess[1] = 4;
    choices_598_guess[2] = 0x55;
    choices_598_guess[3] = 0x99;
    choices_598_guess[4] = 0x28;
    choices_598_guess[5] = 0x1c;
    choices_598_guess[6] = 0x96;
    choices_598_guess[7] = 0x26;
    choices_598_guess[8] = 0x15;
    choices_598_guess[9] = 0x33;
    choices_598_guess[10] = 5;
    choices_598_guess[11] = 0x67;
    value_5ec_guess = height;
    ((CGemsGameWndView_guess*)this)->Restart_guess();
    *flag = 0;
}

// Binds the GGW_* children and copies A_SpellGems; GGW_SpellGem is only a template for the cell size
// and draw offsets. Tile colours and the 11-step highlight alpha table (255, 234 ... 45) are set here.
// FUNCTION: TITANIUM 0x00506AE5
CGemsGameWnd_guess::CGemsGameWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "GemsGameWnd") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        startButton_dfc = ((CSidlScreenWnd*)this)->GetChildItem("GGW_StartButton");
        doneButton_e00 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_DoneButton");
        instructions_e8c = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Instructions");
        instructions2_e90 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Instructions2");
        instructions3_e94 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Instructions3");
        paused_ea0 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Paused");
        largeWave_e98 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_LargeWave");
        largeWaveNbr_e9c = ((CSidlScreenWnd*)this)->GetChildItem("GGW_LargeWaveNbr");
        score_eac = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Score");
        scoreNbr_eb0 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_ScoreNbr");
        wave_ea4 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Wave");
        waveNbr_ea8 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_WaveNbr");
        gameOver_e88 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_GameOver");
        highScores_e04 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_HighScores");
        scoreHeader_e08 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_ScoreHeader");
        waveHeader_e0c = ((CSidlScreenWnd*)this)->GetChildItem("GGW_WaveHeader");
        next_eb4 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Next");
        special_eb8 = ((CSidlScreenWnd*)this)->GetChildItem("GGW_Special");
        char name[0x200];
        // Ten high-score rows: name, score and wave.
        for (int i = 0; i < 10; ++i) {
            sprintf(name, "GGW_HighName%d", i);
            highNames_e10[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            sprintf(name, "GGW_HighScore%d", i);
            highScoreValues_e38[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
            sprintf(name, "GGW_HighWave%d", i);
            highWaves_e60[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        gameView_ebc = ((CSidlScreenWnd*)this)->GetChildItem("GGW_GameView");
        if (gameView_ebc != 0) {
            gameView_ebc->WindowStyle &= ~0x800;
            gameView_ebc->Fades = 0;
            if (highScores_e04 != 0) {
                highScores_e04->pParentWindow = gameView_ebc;
                highScores_e04->Unknown0x061 = 1;
            }
        }
        GemsAnimation_guess* gems = g_gemsSidlManager_guess->FindAnimation_guess("A_SpellGems");
        gemsAnim_df0 = new GemsAnimation_guess;
        *gemsAnim_df0 = *gems;
        GemsSpellGemWnd_guess* gem = (GemsSpellGemWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("GGW_SpellGem");
        gemValue_df4 = gem->field_19c;
        gemValue_df8 = gem->field_1a4;
        gemValue_de0 = gem->field_180;
        gemValue_de4 = gem->field_184;
        gemWidth_de8 = gem->Location.right - gem->Location.left;
        gemHeight_dec = gem->Location.bottom - gem->Location.top;
        field_db4 = 0xff;
        color_d88 = 0xff5242de;
        // Row alphas 234 down to 45 in steps of 21: the table the new high-score row pulses through.
        for (int row = 0; row < 10; ++row) {
            rowColors_d8c[row] = 0xffde2121;
            rowValues_db8[row] = 234 - row * 21;
        }
        InitializeGame_guess();
    }
}
