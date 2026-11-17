// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 35: a hint from compare/tumap.py.
// The zoning load screen: picks a background JPEG, draws it with a progress bar and a status line or loading
// tip, all laid out for 640x480 and centred on bigger screens. LoadScreenView_guess is the load-screen object;
// LoadScreen_guess is another view of it, with the status text at +0x14.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct PointerHolder_guess {
    int value; // 0x0
    void Cleanup_guess();
    // EXTERNAL: TITANIUM 0x004482FB ??1PointerHolder_guess@@QAE@XZ
    ~PointerHolder_guess();
};

union Color_guess {
    unsigned int argb_0000_guess;  // 0x0
    unsigned char bytes_guess[4];
};

struct Manager_guess {
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
    virtual void Slot14_guess(int value);
    virtual char Slot15_guess();
    virtual void Slot16_guess();
    virtual int Slot17_guess(const char* name_guess, const char* name2_guess,
                             int zero_guess, int one_guess);
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess(int value);
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess(float* first_guess, float* second_guess,
                              unsigned int color_guess);
    virtual void Slot29_guess();
    virtual void Slot30_guess(int value);
    virtual void Slot31_guess();
    virtual void Slot32_guess(float* vertices_guess, float* texcoords_guess,
                              unsigned int color_guess, int texture_guess);
    virtual void Slot33_guess(float* vertices_guess, unsigned int color_guess);
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x0099E360)
#define g_releaseManager_guess EQ_GLOBAL(Manager_guess*, 0x0099E364)

struct Surface_guess {
    virtual void Slot00_guess(int context_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess(int operation_guess, int x_guess, int y_guess,
                              int width_guess, CXRect* rect_guess, int color_guess,
                              int mode_guess, int flags_guess);
};

#include "titanium/layouts/shared_classes.h"

// EXTERNAL: TITANIUM 0x00643F6C ??_7LoadScreenView_guess@@6B@
struct LoadScreenView_guess {
    int handle1; // 0x4
    int handle2; // 0x8
    int handle3; // 0xC
    CXStr holder; // 0x10
    union {
        int context_guess; // 0x14
        bool flag_guess;
    };
    unsigned char pad_guess[0x214 - 0x18]; // 0x18
    int count_guess; // 0x214

    LoadScreenView_guess();
    virtual ~LoadScreenView_guess();
    void WriteTextHD(int context_guess, int x_guess, int y_guess, int color_guess);
    void DrawBackground_guess(float* point_guess);
    void DrawLoadScreen_guess();
};

#define pinstCXWndManager_guess EQ_GLOBAL(RenderTarget_guess*, 0x0099D3EC)
#define g_screenWidth_guess EQ_GLOBAL(int, 0x00923780)
#define g_screenX_guess EQ_GLOBAL(int, 0x0092379C)
#define g_screenY_guess EQ_GLOBAL(int, 0x009237A0)

struct RedrawMode_guess {
    int unused_guess[3];
    char active_guess;
};

#define g_redrawMode_guess EQ_GLOBAL(RedrawMode_guess*, 0x0085098C)
#define g_redrawPending_guess EQ_GLOBAL(char, 0x00698B28)
#define g_drawProgressText_guess EQ_GLOBAL(int, 0x00923D74)
#define g_drawCursor_guess EQ_GLOBAL(int, 0x00905D24)

// EXTERNAL: TITANIUM 0x00571D00 FUN_00571d00_guess
void __stdcall FUN_00571d00_guess(int value);

struct Bar_guess {
    int values_guess[4];
    // EXTERNAL: TITANIUM 0x0042F092 Bar_guess::Bar_guess
    Bar_guess(int value_guess);
};

struct Holder_guess {
    Bar_guess* bar_guess; // 0x0
    Holder_guess* Init_guess(int first_guess, int second_guess);
};

// Allocates the 500-entry Bar_guess the holder owns; `first_guess`/`second_guess` are unused.
// FUNCTION: TITANIUM 0x004482A9
Holder_guess* Holder_guess::Init_guess(int first_guess, int second_guess) {
    char probe_guess[8];
    bar_guess = new Bar_guess(500);
    return this;
}

// Releases the held CXStr buffer (0x00571D00), if any, and clears the pointer.
// FUNCTION: TITANIUM 0x004482FB
void PointerHolder_guess::Cleanup_guess() {
    if (value != 0) {
        FUN_00571d00_guess(value);
    }
    value = 0;
}

// Releases the held CXStr buffer (0x004482FB).
// FUNCTION: TITANIUM 0x0044830F
void __fastcall FUN_0044830f_guess(PointerHolder_guess* self) {
    self->Cleanup_guess();
}

// Releases the background texture (handle1) and the two text fonts (handle2 shadow, handle3 text).
// FUNCTION: TITANIUM 0x00448314
LoadScreenView_guess::~LoadScreenView_guess() {
    g_manager_guess->Slot22_guess(handle1);
    g_manager_guess->Slot14_guess(handle2);
    g_manager_guess->Slot14_guess(handle3);
    handle1 = 0;
}

// Draws `context_guess` text at (x, y) with a black shadow 1 pixel down-right. `color_guess` is an EQ colour
// index (12 grey, 13 red, 14 green, 15 yellow, 16 blue, 18 cyan...), turned into ARGB here. Coordinates are
// for 640x480 and shift to the centre of a larger screen.
// FUNCTION: TITANIUM 0x00448376
void LoadScreenView_guess::WriteTextHD(int context_guess, int x_guess, int y_guess, int color_guess) {
    if (pinstCXWndManager_guess == 0) {
        return;
    }

    switch (color_guess) {
    case 12: color_guess = 0xffa0a0a0; break;
    case 2: color_guess = 0xff008000; break;
    case 4: color_guess = 0xff000080; break;
    case 5: color_guess = 0xfff000f0; break;
    case 6: color_guess = 0xff808080; break;
    case 7: color_guess = 0xffe0e0e0; break;
    case 10: color_guess = 0xfff0f0f0; break;
    case 13: color_guess = 0xfff00000; break;
    case 14: color_guess = 0xff00f000; break;
    case 15: color_guess = 0xfff0f000; break;
    case 16: color_guess = 0xff0000f0; break;
    case 18: color_guess = 0xff00f0f0; break;
    case 20: color_guess = 0xff000000; break;
    default: color_guess = 0xff606060; break;
    }

    if (g_screenWidth_guess > 0x280) {
        x_guess += (g_screenX_guess - 0x280) / 2;
        y_guess += (g_screenY_guess - 0x1e0) / 2;
    }

    CXRect rect_guess;
    rect_guess.bottom = 0;
    rect_guess.right = 0;
    rect_guess.top = y_guess;
    rect_guess.left = x_guess;
    rect_guess.bottom = pinstCXWndManager_guess->height_guess;
    rect_guess.right = pinstCXWndManager_guess->width_guess;

    ((Surface_guess*)handle2)->Slot00_guess(context_guess);
    ((Surface_guess*)handle2)->Slot02_guess(2, x_guess + 1, y_guess + 1,
        pinstCXWndManager_guess->width_guess - x_guess, &rect_guess,
        0xff000000, 1, 0);
    ((Surface_guess*)handle3)->Slot00_guess(context_guess);
    ((Surface_guess*)handle3)->Slot02_guess(2, x_guess, y_guess,
        pinstCXWndManager_guess->width_guess - x_guess, &rect_guess,
        color_guess, 1, 0);
    g_releaseManager_guess->Slot30_guess(handle2);
    g_releaseManager_guess->Slot30_guess(handle3);
}

// Draws the background as one 640x480 quad at `point_guess`. When the device reports power-of-two textures
// (Slot15_guess), only the top-left 640x480 of the 1024x512 texture is used (0.625, 0.9375).
// FUNCTION: TITANIUM 0x00448526
void LoadScreenView_guess::DrawBackground_guess(float* point_guess) {
    if (handle1 == 0) {
        return;
    }

    float vertices_guess[4][3];
    float texcoords_guess[4][2];
    Color_guess color_guess;

    color_guess.bytes_guess[3] = 0xff;
    color_guess.bytes_guess[2] = 0xff;
    color_guess.bytes_guess[1] = 0xff;
    color_guess.bytes_guess[0] = 0xff;

    vertices_guess[0][0] = point_guess[0];
    vertices_guess[0][1] = point_guess[1];
    vertices_guess[0][2] = point_guess[2];
    vertices_guess[1][2] = vertices_guess[0][2];
    vertices_guess[1][1] = vertices_guess[0][1];
    vertices_guess[1][0] = vertices_guess[0][0] + 640.0f;
    vertices_guess[2][0] = vertices_guess[0][0] + 640.0f;
    vertices_guess[2][2] = vertices_guess[0][2];
    vertices_guess[2][1] = vertices_guess[0][1] + 480.0f;
    vertices_guess[3][1] = vertices_guess[0][1] + 480.0f;
    vertices_guess[3][2] = vertices_guess[0][2];
    // + 640 - 640 is the original arithmetic (match shape); keep it.
    vertices_guess[3][0] = vertices_guess[0][0] + 640.0f - 640.0f;

    char lit_guess = g_releaseManager_guess->Slot15_guess();
    texcoords_guess[0][0] = 0.0f;
    texcoords_guess[0][1] = 0.0f;
    if (lit_guess) {
        texcoords_guess[1][0] = 0.625f;
        texcoords_guess[1][1] = 0.0f;
        texcoords_guess[2][0] = 0.625f;
        texcoords_guess[2][1] = 0.9375f;
        texcoords_guess[3][0] = 0.0f;
        texcoords_guess[3][1] = 0.9375f;
    } else {
        texcoords_guess[1][0] = 1.0f;
        texcoords_guess[1][1] = 0.0f;
        texcoords_guess[2][0] = 1.0f;
        texcoords_guess[2][1] = 1.0f;
        texcoords_guess[3][0] = 0.0f;
        texcoords_guess[3][1] = 1.0f;
    }

    g_releaseManager_guess->Slot35_guess();
    g_releaseManager_guess->Slot32_guess(&vertices_guess[0][0],
        &texcoords_guess[0][0], color_guess.argb_0000_guess, handle1);
}

// Redraws the load screen twice, probably once per buffer of the flip chain: black fill when a redraw is
// pending, the background, a 290-pixel progress bar (180-470, 466-478) filled to count_guess percent when
// 1-100, then the status line in yellow (colour 15) at (210, 465) unless text is turned off.
// FUNCTION: TITANIUM 0x0044861F
// @early-stop: unknown, structural ndiff=220
void LoadScreenView_guess::DrawLoadScreen_guess() {
    if (g_redrawMode_guess == 0 || g_redrawMode_guess->active_guess == 0) {
        float origin_guess[3];
        int iterations_guess = 2;
        origin_guess[2] = 0.0f;

        do {
            float points_guess[4][3];
            Color_guess fillColor_guess;
            Color_guess outlineColor_guess;
            Color_guess bottomColor_guess;
            Color_guess topColor_guess;
            float screenWidth_guess = 0.0f;
            float screenHeight_guess = 0.0f;

            origin_guess[0] = 0.0f;
            origin_guess[1] = 0.0f;
            if (g_screenWidth_guess > 0x280) {
                origin_guess[0] = (float)((g_screenX_guess - 0x280) / 2);
                origin_guess[1] = (float)((g_screenY_guess - 0x1e0) / 2);
                screenWidth_guess = (float)g_screenX_guess;
                screenHeight_guess = (float)g_screenY_guess;
            }

            if (g_redrawPending_guess != 0) {
                srand((unsigned int)time(0));
                points_guess[0][0] = 0.0f;
                points_guess[0][1] = 0.0f;
                points_guess[0][2] = 1.0f;
                points_guess[1][0] = screenWidth_guess;
                points_guess[1][1] = 0.0f;
                points_guess[1][2] = 1.0f;
                points_guess[2][0] = screenWidth_guess;
                points_guess[2][1] = screenHeight_guess;
                points_guess[2][2] = 1.0f;
                points_guess[3][0] = 0.0f;
                points_guess[3][1] = screenHeight_guess;
                points_guess[3][2] = 1.0f;
                fillColor_guess.argb_0000_guess = 0xff000000;
                g_releaseManager_guess->Slot33_guess(&points_guess[0][0],
                    fillColor_guess.argb_0000_guess);
            }

                DrawBackground_guess(&origin_guess[0]);

            if (count_guess > 0 && count_guess < 0x65) {
                float left_guess = origin_guess[0] + 179.0f;
                float top_guess = origin_guess[1] + 465.0f;
                float right_guess = origin_guess[0] + 471.0f;
                float bottom_guess = origin_guess[1] + 479.0f;

                topColor_guess.bytes_guess[2] = 0xc8;
                topColor_guess.bytes_guess[1] = 0xc8;
                topColor_guess.bytes_guess[0] = 0;
                topColor_guess.bytes_guess[3] = 0xff;
                bottomColor_guess.bytes_guess[2] = 0x64;
                bottomColor_guess.bytes_guess[1] = 0x64;
                bottomColor_guess.bytes_guess[0] = 0;
                bottomColor_guess.bytes_guess[3] = 0xff;
                outlineColor_guess.bytes_guess[0] = 0;
                outlineColor_guess.bytes_guess[1] = 0;
                outlineColor_guess.bytes_guess[2] = 0;
                outlineColor_guess.bytes_guess[3] = 0xff;
                fillColor_guess.bytes_guess[2] = 0x32;
                fillColor_guess.bytes_guess[1] = 0x32;
                fillColor_guess.bytes_guess[0] = 0xc8;
                fillColor_guess.bytes_guess[3] = 0xff;

                points_guess[0][0] = left_guess;
                points_guess[0][1] = top_guess;
                points_guess[0][2] = 0.0f;
                points_guess[1][0] = right_guess;
                points_guess[1][1] = top_guess;
                points_guess[1][2] = 0.0f;
                g_releaseManager_guess->Slot28_guess(&points_guess[0][0],
                    &points_guess[1][0], topColor_guess.argb_0000_guess);

                points_guess[1][0] = left_guess;
                points_guess[1][1] = bottom_guess;
                g_releaseManager_guess->Slot28_guess(&points_guess[0][0],
                    &points_guess[1][0], topColor_guess.argb_0000_guess);

                points_guess[2][0] = right_guess;
                points_guess[2][1] = bottom_guess;
                points_guess[3][0] = left_guess;
                points_guess[3][1] = bottom_guess;
                g_releaseManager_guess->Slot28_guess(&points_guess[2][0],
                    &points_guess[3][0], bottomColor_guess.argb_0000_guess);

                points_guess[3][0] = points_guess[2][0];
                points_guess[3][1] = top_guess;
                g_releaseManager_guess->Slot28_guess(&points_guess[2][0],
                    &points_guess[3][0], bottomColor_guess.argb_0000_guess);

                points_guess[0][0] = origin_guess[0] + 180.0f;
                points_guess[0][1] = origin_guess[1] + 466.0f;
                points_guess[0][2] = 0.0f;
                int width_guess = count_guess * 0x122;
                points_guess[1][0] = (float)width_guess * 0.01f +
                    origin_guess[0] + 180.0f;
                points_guess[1][1] = points_guess[0][1];
                points_guess[1][2] = 0.0f;
                points_guess[2][0] = points_guess[1][0];
                points_guess[2][1] = origin_guess[1] + 478.0f;
                points_guess[2][2] = 0.0f;
                points_guess[3][0] = points_guess[0][0];
                points_guess[3][1] = points_guess[2][1];
                points_guess[3][2] = 0.0f;

                g_releaseManager_guess->Slot33_guess(&points_guess[0][0],
                    fillColor_guess.argb_0000_guess);

                fillColor_guess.bytes_guess[0] = 100;
                g_releaseManager_guess->Slot28_guess(&points_guess[1][0],
                    &points_guess[2][0], fillColor_guess.argb_0000_guess);

                points_guess[0][0] = points_guess[1][0];
                points_guess[3][0] = points_guess[1][0];
                points_guess[1][0] = origin_guess[0] + 470.0f;
                points_guess[2][0] = points_guess[1][0];
                g_releaseManager_guess->Slot33_guess(&points_guess[0][0],
                    outlineColor_guess.argb_0000_guess);
            }

            if (g_drawProgressText_guess == 0) {
                WriteTextHD((int)&context_guess, 0xd2, 0x1d1, 0xf);
            }
            if (g_drawCursor_guess != 0) {
                g_releaseManager_guess->Slot37_guess();
            }
            --iterations_guess;
        } while (iterations_guess != 0);

        g_redrawPending_guess = 0;
    }
}

#define g_tips_guess EQ_ARRAY(char*, 0x00698A18)
#define g_tipActive_guess EQ_GLOBAL(char, 0x008511E0)
#define g_tipTime_guess EQ_GLOBAL(unsigned int, 0x008511DC)

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess(void);

struct LoadScreen_guess {
    char head_guess[0x14];
    char text_guess[0x200]; // 0x14
    int progress_guess;     // 0x214

    // EXTERNAL: TITANIUM 0x0044861F LoadScreen_guess::DrawLoadScreen_guess
    void DrawLoadScreen_guess();
    void SetProgressBar_guess(int value_guess, const char* source_guess);
};

// Sets the progress (capped at 100) and the status line "<text>...". One call in 20 shows a random loading
// tip from the 68-entry table at 0x698A18 instead, which then stays at least 3 seconds. A null `source_guess`
// clears the line. Redraws at once.
// FUNCTION: TITANIUM 0x0044894C
void LoadScreen_guess::SetProgressBar_guess(int value_guess, const char* source_guess) {
    progress_guess = value_guess;
    int roll_guess = rand();
    bool pick_guess = roll_guess % 20 == 0;
    unsigned int now_guess = FUN_0046d655_guess();
    if (progress_guess > 100) {
        progress_guess = 100;
    }

    if (source_guess == 0) {
        text_guess[0] = 0;
    } else if (g_tipActive_guess == 0 || g_tipTime_guess + 3000 <= now_guess) {
        if (pick_guess) {
            char* tip_guess;
            do {
                roll_guess = rand();
                tip_guess = g_tips_guess[roll_guess % 0x44];
            // Empty table slots are skipped by rolling again.
            } while (tip_guess == 0);
            sprintf(text_guess, "%s...", tip_guess);
            g_tipTime_guess = now_guess;
            g_tipActive_guess = 1;
        } else {
            sprintf(text_guess, "%s...", source_guess);
            g_tipActive_guess = 0;
        }
    }

    DrawLoadScreen_guess();
}

// Globals and callees of the loader ctor; names not in the shared headers yet.
struct Loader_guess {
    char pad_guess[0x252];
    unsigned char class_guess; // 0x252
};

struct Everything_guess {
    // EXTERNAL: TITANIUM 0x004922D5 Everything_guess::GetClassThreeLetterCode
    int GetClassThreeLetterCode(unsigned char race_guess);
};

struct Lookup_guess {
    // EXTERNAL: TITANIUM 0x0043A6BF Lookup_guess::Find_guess
    int Find_guess(int id_guess);
};

struct PathTable_guess {
    // EXTERNAL: TITANIUM 0x0060C0D0 PathTable_guess::Get_guess
    CXStr* Get_guess(int index_guess);
};

struct FindFiles_guess {
    void* handle_guess; // 0x0
    char find_data_guess[0x140]; // 0x4, WIN32_FIND_DATAA
    int unk_guess; // 0x144

    // EXTERNAL: TITANIUM 0x00576690 FindFiles_guess::FindFiles_guess
    FindFiles_guess(const char* path_guess, const char* pattern_guess);
    // EXTERNAL: TITANIUM 0x00576760 FindFiles_guess::Next_guess
    bool Next_guess(CXStr* out_guess);
    // EXTERNAL: TITANIUM 0x00576740 FindFiles_guess::~FindFiles_guess
    ~FindFiles_guess();
};

// ArrayClass2 (types.h 0x328): count, alloc, mask, shift, blocks.
struct NameList_guess {
    int count_guess; // 0x0
    int alloc_guess; // 0x4
    int mask_guess; // 0x8
    int shift_guess; // 0xC
    CXStr** blocks_guess; // 0x10
    int unk_guess; // 0x14
    int flag_guess; // 0x18

    // EXTERNAL: TITANIUM 0x0047C3AF NameList_guess::NameList_guess
    NameList_guess(int size_guess);
    // EXTERNAL: TITANIUM 0x00405BFF NameList_guess::~NameList_guess
    ~NameList_guess();
    // EXTERNAL: TITANIUM 0x00405F79 NameList_guess::SetElementIdxStr_guess
    void SetElementIdxStr_guess(int index_guess, const CXStr& item_guess);
    void Add_guess(const CXStr& item_guess) { SetElementIdxStr_guess(count_guess, item_guess); }
    CXStr* At_guess(int index_guess) { return &blocks_guess[index_guess >> shift_guess][index_guess & mask_guess]; }
};

// EXTERNAL: TITANIUM 0x005738B0 Format_guess
void __cdecl Format_guess(CXStr* out_guess, const char* fmt_guess, ...);
// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* fmt_guess, ...);

#define g_loader_guess EQ_GLOBAL(Loader_guess*, 0x00905CE4)
#define g_lookup_guess EQ_GLOBAL(Lookup_guess*, 0x00905CC0)
#define g_resource_guess EQ_GLOBAL(int, 0x00924470)
#define g_mode_guess EQ_GLOBAL(int, 0x009254CC)
#define g_pathTable_guess EQ_GLOBAL(PathTable_guess, 0x0099E414)

// Picks the background by the load-screen option: 0 none, 1 any loadscreen*.jpg in
// uifiles/default/loadscreens, 2 the zone's <shortname>*.jpg (probably), 3 the local player's class code
// (WAR*.jpg, GetClassThreeLetterCode), 4 any *.jpg; 5-8 repeat 1-4 in the user's own folder. One match is
// picked at random; with none it falls back to Resources/loadscreen.jpg. Mode 1 is forced while there is no
// local player.
// FUNCTION: TITANIUM 0x00448A0B
// @early-stop: budget, structural ndiff=115
LoadScreenView_guess::LoadScreenView_guess() : holder(), flag_guess(false), count_guess(0) {
    const char* path_guess;
    CXStr pattern_guess("loadscreen*.jpg");
    CXStr* dir_guess;
    int mode_guess;
    path_guess = ".\\uifiles\\default\\loadscreens";
    dir_guess = g_pathTable_guess.Get_guess(0);
    mode_guess = g_mode_guess;
    if (g_loader_guess == 0) {
        mode_guess = 1;
    }

    switch (mode_guess) {
    case 0:
        path_guess = 0;
        pattern_guess = "";
        break;
    case 2: {
        int id_guess = g_lookup_guess->Find_guess(g_resource_guess);
        if (id_guess != 0) {
            Format_guess(&pattern_guess, "%s*.jpg", id_guess + 0x10);
        }
        break;
    }
    case 3:
        if (g_loader_guess != 0) {
            int model_guess = ((Everything_guess*)pEverQuest)->GetClassThreeLetterCode(g_loader_guess->class_guess);
            if (model_guess != 0) {
                Format_guess(&pattern_guess, "%s*.jpg", model_guess);
            }
        }
        break;
    case 4:
        pattern_guess = "*.jpg";
        break;
    case 5:
        path_guess = *dir_guess;
        break;
    case 6: {
        path_guess = *dir_guess;
        int id_guess = g_lookup_guess->Find_guess(g_resource_guess);
        if (id_guess != 0) {
            Format_guess(&pattern_guess, "%s*.jpg", id_guess + 0x10);
        }
        break;
    }
    case 7:
        path_guess = *dir_guess;
        if (g_loader_guess != 0) {
            int model_guess = ((Everything_guess*)pEverQuest)->GetClassThreeLetterCode(g_loader_guess->class_guess);
            if (model_guess != 0) {
                Format_guess(&pattern_guess, "%s*.jpg", model_guess);
            }
        }
        break;
    case 8:
        path_guess = *dir_guess;
        pattern_guess = "*.jpg";
        break;
    }

    if (path_guess == 0) {
        holder.~CXStr();
        handle1 = 0;
    } else {
        NameList_guess names_guess(0x20);
        FindFiles_guess search_guess(path_guess, pattern_guess);
        CXStr entry_guess;
        int n_guess = 0;
        if (search_guess.Next_guess(&entry_guess)) {
            do {
                names_guess.Add_guess(entry_guess);
                ++n_guess;
            } while (search_guess.Next_guess(&entry_guess));
        }
        if (n_guess == 0) {
            holder = ".\\Resources\\loadscreen.jpg";
        } else {
            int pick_guess = rand() % n_guess;
            CXStr* item_guess = names_guess.At_guess(pick_guess);
            Format_guess(&holder, "%s\\%s", path_guess, (char*)*item_guess);
        }
        handle1 = g_manager_guess->Slot17_guess(holder, holder, 0, 1);
        if (handle1 == 0) {
            // A failed load only logs; the screen then draws without a background.
            Log_guess("ERROR: Failed to load %s.\n", (char*)holder);
        }
    }
    handle2 = g_manager_guess->Slot13_guess();
    handle3 = g_manager_guess->Slot13_guess();
}

