// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 186: a hint from compare/tumap.py.
// CMapToolbarWnd ("MapToolbarWnd", MTW_* buttons; pinst 0x850C00, built in tu_029). CMapToolbarWnd_guess is it,
// CMapToolbarWndDialogListenerView_guess its confirmation-dialog listener base (+0x15C); CMapViewWndView_guess is CMapViewWnd (0x850BFC),
// MapViewMap_guess its MapViewMap (+0x1EC), CEditLabelWnd_guess CEditLabelWnd (0x850C04).
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/wnd/CColorPickerWnd.h"

struct Target_guess {
    virtual void slot_00_guess();
    virtual void slot_01_guess();
    virtual void slot_02_guess();
    virtual void slot_03_guess();
    virtual void slot_04_guess();
    virtual void slot_05_guess();
    virtual void slot_06_guess();
    virtual void slot_07_guess();
    virtual void slot_08_guess();
    virtual void slot_09_guess();
    virtual void slot_0a_guess();
    virtual void slot_0b_guess();
    virtual void slot_0c_guess();
    virtual void slot_0d_guess();
    virtual void slot_0e_guess();
    virtual void slot_0f_guess();
    virtual void slot_10_guess();
    virtual void slot_11_guess();
    virtual void slot_12_guess();
    virtual void slot_13_guess();
    virtual void slot_14_guess();
    virtual void slot_15_guess();
    virtual void slot_16_guess();
    virtual void slot_17_guess();
    virtual void slot_18_guess();
    virtual void slot_19_guess();
    virtual void slot_1a_guess();
    virtual void slot_1b_guess();
    virtual void slot_1c_guess();
    virtual void slot_1d_guess();
    virtual void slot_1e_guess();
    virtual void slot_1f_guess();
    virtual void slot_20_guess();
    virtual void slot_21_guess();
    virtual void slot_22_guess();
    virtual void slot_23_guess();
    virtual void slot_24_guess();
    virtual void slot_25_guess();
    virtual void slot_26_guess();
    virtual void slot_27_guess();
    virtual void slot_28_guess();
    virtual void slot_29_guess();
    virtual void slot_2a_guess();
    virtual void slot_2b_guess();
    virtual void slot_2c_guess();
    virtual void slot_2d_guess();
    virtual void slot_2e_guess();
    virtual void slot_2f_guess();
    virtual void slot_30_guess();
    virtual void slot_31_guess();
    virtual void slot_32_guess();
    virtual void slot_33_guess();
    virtual void slot_34_guess();
    virtual void slot_35_guess();
    virtual void slot_36_guess();
    virtual void slot_37_guess();
    virtual void slot_38_guess();
    virtual void slot_39_guess();
    virtual void slot_3a_guess();
    virtual void slot_3b_guess();
    virtual void slot_3c_guess();
    virtual void slot_3d_guess();
    virtual void slot_3e_guess();
    virtual void slot_3f_guess();
    virtual void slot_40_guess();
    virtual void slot_41_guess();
    virtual void slot_42_guess();
    virtual void slot_43_guess();
    virtual void slot_44_guess();
    virtual void slot_45_guess();
    virtual void slot_46_guess();
    virtual void slot_47_guess();
    virtual void slot_48_guess();
    virtual void slot_49_guess();
    virtual void slot_4a_guess();
    virtual void slot_4b_guess();
    virtual CXStr slot_4c_guess();
    // EXTERNAL: TITANIUM 0x005BB140 Target_guess::SetCheck
    void SetCheck(int argument);
};

struct CEditLabelWnd_guess {
    char unknown_000[0x160];
    void* value_160;
    void* value_164;
    Target_guess* value_168;
    char unknown_16c[0x0c];
    Target_guess* autoMapButton_178_guess;
    char unknown_17c[0xd0];
    void* value_24c;
    CXStr GetLabelText_guess();
    void SetAutoMapCheck_guess(int argument);
    // EXTERNAL: TITANIUM 0x004FF7D2 CEditLabelWnd_guess::Activate_guess
    void Activate_guess(void* endpoint, void* text, unsigned int id, unsigned int color);
};

struct RefreshInput_guess {
    char unknown_000[0x204];
    int value_204;
};

struct RefreshService_guess {
    // EXTERNAL: TITANIUM 0x005F6BC0 RefreshService_guess::check_guess
    char check_guess(int argument);
};

struct Callback_guess {
    virtual void slot_00_guess();
    virtual void slot_01_guess();
    virtual void slot_02_guess();
    virtual void slot_03_guess();
    virtual void slot_04_guess();
    virtual void slot_05_guess();
    virtual void slot_06_guess();
    virtual void slot_07_guess();
    virtual void slot_08_guess();
    virtual void slot_09_guess();
    virtual void slot_0a_guess();
    virtual void slot_0b_guess();
    virtual void slot_0c_guess();
    virtual void slot_0d_guess();
    virtual void slot_0e_guess();
    virtual void slot_0f_guess();
    virtual void slot_10_guess();
    virtual void slot_11_guess();
    virtual void slot_12_guess();
    virtual void slot_13_guess();
    virtual void slot_14_guess();
    virtual void slot_15_guess();
    virtual void slot_16_guess();
    virtual void slot_17_guess();
    virtual void slot_18_guess();
    virtual void slot_19_guess();
    virtual void slot_1a_guess();
    virtual void slot_1b_guess();
    virtual void slot_1c_guess();
    virtual void slot_1d_guess();
    virtual void slot_1e_guess();
    virtual void slot_1f_guess();
    virtual void slot_20_guess();
    virtual void slot_21_guess();
    virtual void slot_22_guess();
    char unknown_004[0x58];
    char enabled_05c;
    void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 Callback_guess::OnProcessFrame
    void OnProcessFrame();
};

struct MapViewMap_guess {
    // EXTERNAL: TITANIUM 0x00532DEC MapViewMap_guess::SetSelectedLinesColor_guess
    void SetSelectedLinesColor_guess(void* value);
    // EXTERNAL: TITANIUM 0x00532DA1 MapViewMap_guess::AddLineToSelection_guess
    void AddLineToSelection_guess(int zero);
    // EXTERNAL: TITANIUM 0x00532D83 MapViewMap_guess::SetCurrentColor_guess
    void SetCurrentColor_guess(void* value);
    // EXTERNAL: TITANIUM 0x00533644 MapViewMap_guess::set_record_guess
    void set_record_guess(void* value);
    // EXTERNAL: TITANIUM 0x0053245B MapViewMap_guess::start_line_guess
    void start_line_guess(float y, float x, float z);
    // EXTERNAL: TITANIUM 0x00533455 MapViewMap_guess::end_line_guess
    void end_line_guess(float y, float x, float z);
    // EXTERNAL: TITANIUM 0x00532499 MapViewMap_guess::RemoveSelectedLines_guess
    void RemoveSelectedLines_guess();
    // EXTERNAL: TITANIUM 0x0053354E MapViewMap_guess::AddPoint_guess
    void AddPoint_guess(float y, float x, float z);
    // EXTERNAL: TITANIUM 0x00532543 MapViewMap_guess::SetLabelPosition_guess
    void SetLabelPosition_guess(void* record, float y, float x, float z);
    // EXTERNAL: TITANIUM 0x005324ED MapViewMap_guess::RemoveSelectedLabel_guess
    void RemoveSelectedLabel_guess();
    // EXTERNAL: TITANIUM 0x00533E0B MapViewMap_guess::normalize_guess
    void normalize_guess(char* value);
    // EXTERNAL: TITANIUM 0x00532F60 MapViewMap_guess::JoinAtIntersect_guess
    void JoinAtIntersect_guess(int value);
    // EXTERNAL: TITANIUM 0x00532D71 MapViewMap_guess::GetCurrentColor_guess
    unsigned int GetCurrentColor_guess();
    // EXTERNAL: TITANIUM 0x00532E34 MapViewMap_guess::GetSelectedLineColor_guess
    unsigned int GetSelectedLineColor_guess();
    // EXTERNAL: TITANIUM 0x005344FB MapViewMap_guess::AddLabel_guess
    void AddLabel_guess(float y, float x, float z, void* start, void* end, const char* text);
};

struct CMapViewWndView_guess {
    char unknown_000[0x180];
    char value_180[0x68];
    char unknown_1e8[4];
    MapViewMap_guess actions_1ec;
    char unknown_1ed[0x5b];
    void* value_248;
    void* value_24c;
    // EXTERNAL: TITANIUM 0x00533238 CMapViewWndView_guess::StartAutoMap_guess
    void StartAutoMap_guess();
    // EXTERNAL: TITANIUM 0x00534497 CMapViewWndView_guess::StopAutoMap_guess
    void StopAutoMap_guess();
    // EXTERNAL: TITANIUM 0x00495A87 CMapViewWndView_guess::check_guess
    char check_guess();
};

struct Camera_guess {
    char unknown_000[0x30];
    float x_030;
    float y_034;
    float z_038;
    char unknown_03c[0x200];
    float height_23c;
};

struct Record_guess {
    char unknown_000[0x14];
    unsigned char red_014;
    unsigned char green_015;
    unsigned char blue_016;
    char unknown_017;
    unsigned int value_018;
    char* text_01c;
};

struct Input_guess {
    char unknown_000[8];
    unsigned int length_008;
};

struct ControlNode_guess {
    void* vtable;
    void* value_004;
};

struct CConfirmationDialogPoolView_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPoolView_guess::Activate
    void Activate(void* owner, int timeout, const char* text, int twelve, int minus_one, int zero, int one);
};

struct Owner_guess {
    char unknown_000[0x15c];
    void* value_15c;
};

struct Button_guess {
    char unknown_000[0x128];
    char state_128;
};

struct String_guess {
    void* value;
    // EXTERNAL: TITANIUM 0x00571E00 String_guess::initialize_guess
    void initialize_guess(const char* value);
    String_guess(const char* value)
    {
        initialize_guess(value);
    }
    // EXTERNAL: TITANIUM 0x00571D00 String_guess::release_guess
    void release_guess(void* value);
    ~String_guess()
    {
        if (value != 0) {
            release_guess(value);
        }
    }
};

// EXTERNAL: TITANIUM 0x0046DA4A format_text_guess
void format_text_guess(void* result, unsigned int id, char* text,
                       int zero_1, int zero_2, int zero_3, int zero_4,
                       int zero_5, int zero_6, int zero_7, int zero_8);

struct Data_guess {
    char unknown_000[0x60];
    unsigned int value_060;
};

struct MainBase_guess {
    virtual void slot_00_guess() {}
    char unknown_004[0x60];
    unsigned int flags_064;
    char unknown_068[0xbc];
    Data_guess* data_124;
    char unknown_128[0x34];
    // EXTERNAL: TITANIUM 0x005A3850 MainBase_guess::MainBase_guess
    MainBase_guess(int argument, String_guess& name, int flags, int one, int zero);
    // EXTERNAL: TITANIUM 0x005A25B0 MainBase_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A1E10 MainBase_guess::GetChildItem
    void* GetChildItem(String_guess& name);
    ~MainBase_guess() {}
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7CMapToolbarWndDialogListenerView_guess@@6B@
struct CMapToolbarWndDialogListenerView_guess {
    virtual void slot_00_guess() {}
    ~CMapToolbarWndDialogListenerView_guess() {}
    void OnConfirmationAnswer_guess(int message, unsigned char flags, int ignored);
};

struct CallbackSubobject_guess {
    // EXTERNAL: TITANIUM 0x00534224 CallbackSubobject_guess::ClearActiveLayer_guess
    void ClearActiveLayer_guess();
    // EXTERNAL: TITANIUM 0x00532410 CallbackSubobject_guess::on_hundred_one_guess
    void on_hundred_one_guess();
};

struct CallbackOwner_guess {
    char unknown_000[0x1ec];
    CallbackSubobject_guess callback_1ec;
};

// EXTERNAL: TITANIUM 0x006586A8 ??_7CMapToolbarWnd_guess@@6BMainBase_guess@@@
// EXTERNAL: TITANIUM 0x006587C8 ??_7CMapToolbarWnd_guess@@6BCMapToolbarWndDialogListenerView_guess@@@
struct CMapToolbarWnd_guess : MainBase_guess, CMapToolbarWndDialogListenerView_guess {
    void* startLine_160;
    void* endLine_164;
    void* addPoint_168;
    void* removeLine_16c;
    void* changeLineColor_170;
    void* joinAtIntersect_174;
    Button_guess* autoMap_178;
    void* addLabel_17c;
    void* editLabel_180;
    void* moveLabelToMe_184;
    void* removeLabel_188;
    void* setCurrentColor_18c;
    void* clearMap_190;
    void* clearLayer_194;
    void* saveMap_198;
    // EXTERNAL: TITANIUM 0x0059DD30 CMapToolbarWnd_guess::ready_guess
    char ready_guess();
    // EXTERNAL: TITANIUM 0x005A2230 CMapToolbarWnd_guess::WndNotification
    int WndNotification(unsigned int sender, unsigned int code, unsigned int data);
    int WndNotification_guess(unsigned int sender, unsigned int code, unsigned int data);
    CMapToolbarWnd_guess(int argument);
    virtual ~CMapToolbarWnd_guess() {}
};

#define g_state_guess EQ_GLOBAL(CMapViewWndView_guess*, 0x00850BFC)
#define pinstCEditLabelWnd_guess EQ_GLOBAL(CEditLabelWnd_guess*, 0x00850C04)
#define g_camera_guess EQ_GLOBAL(Camera_guess*, 0x00905CE4)
#define g_record_guess EQ_GLOBAL(Record_guess*, 0x00991CD4)
#define g_record_mode_guess EQ_GLOBAL(unsigned char, 0x00991CD8)
#define g_label_mode_guess EQ_GLOBAL(unsigned char, 0x00991CD9)
#define g_dialog_guess EQ_GLOBAL(CConfirmationDialogPoolView_guess*, 0x00991E44)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define pinstCMapToolbarWnd_guess EQ_GLOBAL(Owner_guess*, 0x00850C00)

// CEditLabelWnd: the label text from its edit box (+0x168).
// FUNCTION: TITANIUM 0x005311CF
CXStr CEditLabelWnd_guess::GetLabelText_guess()
{
    return value_168->slot_4c_guess();
}

// True when flag 0x9247A0 is set or the world-data test 0x5F6BC0 passes for the player's zone (+0x204);
// probably whether the map may be used here.
// FUNCTION: TITANIUM 0x005311EF
char refresh_guess()
{
    if (EQ_GLOBAL(int, 0x009247A0) == 0 &&
        EQ_GLOBAL(RefreshService_guess*, 0x00905CC0)->check_guess(
            EQ_GLOBAL(RefreshInput_guess*, 0x00905CE4)->value_204) == 0) {
        return 0;
    }
    return 1;
}

// CMapToolbarWnd::OnProcessFrame: hides the toolbar (vtable slot 0x22) once the map view says no, then
// CXWnd::OnProcessFrame. 0x495A87 always returns 1, so the hide branch never runs.
// FUNCTION: TITANIUM 0x00531216
void Callback_guess::OnProcessFrame_guess()
{
    Callback_guess* self = this;
    if (g_state_guess != 0) {
        if (g_state_guess->check_guess() != 1 && self->enabled_05c != 0) {
            self->slot_22_guess();
        }
    }
    return self->OnProcessFrame();
}

// CMapToolbarWnd::WndNotification. Positions are the player's (-y, -x, feet height = z - 0.625 * height).
// FUNCTION: TITANIUM 0x00531244
// @early-stop: unknown, structural ndiff=237
int CMapToolbarWnd_guess::WndNotification_guess(unsigned int sender, unsigned int code, unsigned int data)
{
    if (ready_guess() == 0 || g_state_guess == 0) {
        return 0;
    }

    // Colour chosen in CColorPickerWnd: recolours the selected lines (Change Line Color) or sets the
    // drawing colour.
    if (code == 0x20) {
        if (g_label_mode_guess == 1) {
            g_state_guess->actions_1ec.SetSelectedLinesColor_guess((void*)data);
            g_label_mode_guess = 0;
            g_state_guess->actions_1ec.AddLineToSelection_guess(0);
        } else {
            g_state_guess->actions_1ec.SetCurrentColor_guess((void*)data);
        }
        return 0;
    }

    // CEditLabelWnd closed with OK: colour (+0x160) and size (+0x164). Mode 0 adds a label where the
    // player stands; mode 1 rewrites the label being edited.
    if (code == 6) {
        if (pinstCEditLabelWnd_guess != 0 && sender == (unsigned int)pinstCEditLabelWnd_guess) {
            CXStr result = pinstCEditLabelWnd_guess->GetLabelText_guess();
            unsigned int start = (unsigned int)pinstCEditLabelWnd_guess->value_160;
            unsigned int end = (unsigned int)pinstCEditLabelWnd_guess->value_164;

            if (g_record_mode_guess == 0) {
                Camera_guess* camera = g_camera_guess;
                float z = camera->z_038 - camera->height_23c * 0.625f;
                g_state_guess->actions_1ec.AddLabel_guess(
                    -camera->y_034, -camera->x_030, z, (void*)start, (void*)end, result);
            } else {
                Record_guess* record = g_record_guess;
                char* old_text = record->text_01c;
                record->blue_016 = (unsigned char)(start >> 16);
                record->value_018 = end;
                record->green_015 = (unsigned char)(start >> 8);
                record->red_014 = (unsigned char)start;
                delete old_text;
                unsigned int length = (unsigned int)result.Ptr->length;
                record->text_01c = new char[length + 1];
                strcpy(record->text_01c, result);
                g_state_guess->actions_1ec.set_record_guess(record);
            }
        }
        return 0;
    }

    if (code == 1) {
        if (sender == (unsigned int)startLine_160) {
            Camera_guess* camera = g_camera_guess;
            float z = camera->z_038 - camera->height_23c * 0.625f;
            g_state_guess->actions_1ec.start_line_guess(-camera->y_034, -camera->x_030, z);
        } else if (sender == (unsigned int)endLine_164) {
            Camera_guess* camera = g_camera_guess;
            float z = camera->z_038 - camera->height_23c * 0.625f;
            g_state_guess->actions_1ec.end_line_guess(-camera->y_034, -camera->x_030, z);
        // Remove Line: 0x532499 removes the selected lines.
        // Add Point: 0x53354E adds a point at the camera.
        } else if (sender == (unsigned int)removeLine_16c) {
            g_state_guess->actions_1ec.RemoveSelectedLines_guess();
        } else if (sender == (unsigned int)addPoint_168) {
            Camera_guess* camera = g_camera_guess;
            float z = camera->z_038 - camera->height_23c * 0.625f;
            g_state_guess->actions_1ec.AddPoint_guess(-camera->y_034, -camera->x_030, z);
        } else if (sender == (unsigned int)addLabel_17c) {
            g_record_mode_guess = 0;
            g_record_guess = 0;
            // New label: empty text, size 1, opaque black.
            pinstCEditLabelWnd_guess->Activate_guess(this, 0, 1, 0xff000000);
        } else if (sender == (unsigned int)editLabel_180) {
            Record_guess* record = (Record_guess*)g_state_guess->value_24c;
            if (record != 0) {
                unsigned int color = ((unsigned int)record->blue_016 << 16) |
                                     ((unsigned int)record->green_015 << 8) |
                                     (unsigned int)record->red_014;
                color |= 0xff000000;
                g_record_mode_guess = 1;
                g_record_guess = record;
                pinstCEditLabelWnd_guess->Activate_guess(this, record->text_01c,
                                                       record->value_018, color);
            }
        } else if (sender == (unsigned int)moveLabelToMe_184) {
            Record_guess* record = (Record_guess*)g_state_guess->value_24c;
            if (record != 0) {
                Camera_guess* camera = g_camera_guess;
                float z = camera->z_038 - camera->height_23c * 0.625f;
                g_state_guess->actions_1ec.SetLabelPosition_guess(
                    record, -camera->y_034, -camera->x_030, z);
            }
        } else if (sender == (unsigned int)removeLabel_188) {
            g_state_guess->actions_1ec.RemoveSelectedLabel_guess();
        } else if (sender == (unsigned int)saveMap_198) {
            char text[0x40];
            strcpy(text, g_state_guess->value_180);
            // 0x533E0B saves all three layers (SaveAllEx in tu_187); the name is then capitalised for message
            // 0x3022 (map saved).
            g_state_guess->actions_1ec.normalize_guess(text);
            text[0] = (char)toupper(text[0]);
            char formatted[0x80];
            format_text_guess(formatted, 0x3022, text,
                              0, 0, 0, 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(formatted);
        } else if (sender == (unsigned int)joinAtIntersect_174) {
            unsigned int flags = pinstCXWndManager_guess->GetKeyboardFlags();
            // Keyboard flag 2, probably Ctrl, joins both lines at the intersection.
            g_state_guess->actions_1ec.JoinAtIntersect_guess((flags & 2) != 0);
        } else if (sender == (unsigned int)clearLayer_194 || sender == (unsigned int)clearMap_190) {
            // Clear Layer (string 0x3AD5, dialog id 100) or Clear Map (0x3AD4, id 101) asks first; the answer
            // comes back to OnConfirmationAnswer_guess.
            unsigned int id = sender == (unsigned int)clearLayer_194 ? 0x3ad5 : 0x3ad4;
            const char* text = pStringTable->getString(id, 0);
            void* owner = pinstCMapToolbarWnd_guess == 0 ? 0 : &pinstCMapToolbarWnd_guess->value_15c;
            g_dialog_guess->Activate(owner, sender == (unsigned int)clearLayer_194 ? 100 : 101,
                                       text, 0xc, -1, 0, 1);
        } else if (sender == (unsigned int)setCurrentColor_18c) {
            g_label_mode_guess = 0;
            unsigned int value = g_state_guess->actions_1ec.GetCurrentColor_guess();
            pinstCColorPickerWnd_guess->Activate_guess(this, value);
        } else if (sender == (unsigned int)changeLineColor_170) {
            ControlNode_guess* node = (ControlNode_guess*)g_state_guess->value_248;
            if (node != 0 && node->value_004 != 0) {
                // Opens the colour picker on the selected line's colour; the reply (code 0x20) recolours it.
                g_label_mode_guess = 1;
                unsigned int value = g_state_guess->actions_1ec.GetSelectedLineColor_guess();
                pinstCColorPickerWnd_guess->Activate_guess(this, value);
            }
        } else if (sender == (unsigned int)autoMap_178) {
            // Auto Map checked starts recording the player's trail, unchecked ends it.
            if (autoMap_178->state_128 != 0) {
                g_state_guess->StartAutoMap_guess();
            } else {
                g_state_guess->StopAutoMap_guess();
            }
        }
    }

    return WndNotification(sender, code, data);
}

// Sets the Auto Map button's check (CButtonWnd::SetCheck); called with this = CMapToolbarWnd when
// the map view stops auto-mapping (tu_187).
// FUNCTION: TITANIUM 0x00531779
void CEditLabelWnd_guess::SetAutoMapCheck_guess(int checked_guess)
{
    if (autoMapButton_178_guess != 0) {
        autoMapButton_178_guess->SetCheck(checked_guess);
    }
}

// Confirmation-dialog answer: on flags 1 or 4 (probably yes) dialog 100 clears the active layer,
// 101 the whole map (MapViewMap::Clear).
// FUNCTION: TITANIUM 0x0053178B
void CMapToolbarWndDialogListenerView_guess::OnConfirmationAnswer_guess(int message, unsigned char flags, int ignored)
{
    switch (message) {
    case 101:
        if ((flags & 5) != 0) {
            EQ_GLOBAL(CallbackOwner_guess*, 0x00850BFC)->callback_1ec.on_hundred_one_guess();
        }
        break;
    case 100:
        if ((flags & 5) != 0) {
            EQ_GLOBAL(CallbackOwner_guess*, 0x00850BFC)->callback_1ec.ClearActiveLayer_guess();
        }
        break;
    }
}

// CMapToolbarWnd::CMapToolbarWnd: loads "MapToolbarWnd" and finds its fifteen buttons.
// FUNCTION: TITANIUM 0x005317CC
CMapToolbarWnd_guess::CMapToolbarWnd_guess(int argument)
    : MainBase_guess(argument, String_guess("MapToolbarWnd"), -513, 1, 0)
{
    startLine_160 = 0;
    endLine_164 = 0;
    addPoint_168 = 0;
    changeLineColor_170 = 0;
    removeLine_16c = 0;
    joinAtIntersect_174 = 0;
    setCurrentColor_18c = 0;
    addLabel_17c = 0;
    editLabel_180 = 0;
    moveLabelToMe_184 = 0;
    removeLabel_188 = 0;
    autoMap_178 = 0;
    clearMap_190 = 0;
    clearLayer_194 = 0;
    saveMap_198 = 0;

    if (data_124 != 0) {
        flags_064 |= data_124->value_060;
        CreateChildrenFromSidl();

        startLine_160 = GetChildItem(String_guess("MTW_StartLineButton"));
        endLine_164 = GetChildItem(String_guess("MTW_EndLineButton"));
        addPoint_168 = GetChildItem(String_guess("MTW_AddPointButton"));
        changeLineColor_170 = GetChildItem(String_guess("MTW_ChangeLineColorButton"));
        removeLine_16c = GetChildItem(String_guess("MTW_RemoveLineButton"));
        joinAtIntersect_174 = GetChildItem(String_guess("MTW_JoinAtIntersectButton"));
        setCurrentColor_18c = GetChildItem(String_guess("MTW_SetCurrentColorButton"));
        addLabel_17c = GetChildItem(String_guess("MTW_AddLabelButton"));
        editLabel_180 = GetChildItem(String_guess("MTW_EditLabelButton"));
        moveLabelToMe_184 = GetChildItem(String_guess("MTW_MoveLabelToMeButton"));
        removeLabel_188 = GetChildItem(String_guess("MTW_RemoveLabelButton"));
        autoMap_178 = (Button_guess*)GetChildItem(String_guess("MTW_AutoMapButton"));
        clearMap_190 = GetChildItem(String_guess("MTW_ClearMapButton"));
        clearLayer_194 = GetChildItem(String_guess("MTW_ClearLayerButton"));
        saveMap_198 = GetChildItem(String_guess("MTW_SaveMapButton"));
    }
}

