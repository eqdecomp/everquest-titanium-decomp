// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 236: a hint from compare/tumap.py.
// CVideoModesWnd (screen "VideoModesWindow", vtable 0x65F990, instance 0x850C78): the resolution list and the
// refresh-rate and bit-depth combos. DisplayModes_guess and MessageOwner_guess are views of it; the "message"
// records at 0x9929C8 are the video-mode table, gWindowProvider_guess (0x99E364) the graphics driver.
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct Handler_guess {
    // EXTERNAL: TITANIUM 0x00437BCD Handler_guess::Refresh_guess
    void Refresh_guess();
};

struct MessageData_guess;

struct GraphicsDriverView_guess {
    virtual unsigned int Slot00_guess();
    virtual unsigned int Slot01_guess();
    virtual unsigned int Slot02_guess();
    virtual int Slot03_guess();
    virtual int Slot04_guess();
    virtual int Slot05_guess();
    virtual unsigned int Slot06_guess();
    virtual int Slot07_guess();
    virtual char Slot08_guess();
    virtual unsigned int Slot09_guess();
    virtual void* GetWindow_guess();
    virtual void Slot11_guess(unsigned int index_guess, MessageData_guess* out_guess);
};

struct MessageData_guess {
    unsigned int width_guess;
    unsigned int height_guess;
    unsigned int refreshRate_guess;
    unsigned int format_guess;
};

struct VideoMode_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int refreshRates_guess[32];
    unsigned int refreshRateCount_guess;
    unsigned int formats_guess[4];
    unsigned int formatCount_guess;
};

struct Combo_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 Combo_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x0059C360 Combo_guess::SetCurSel_guess
    void SetCurSel_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0059C3A0 Combo_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 Combo_guess::Fill_guess
    void Fill_guess(CXStr& text_guess);
};

struct ListSlots_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot0A_guess(); virtual void Slot0B_guess();
    virtual void Slot0C_guess(); virtual void Slot0D_guess();
    virtual void Slot0E_guess(); virtual void Slot0F_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot1A_guess(); virtual void Slot1B_guess();
    virtual void Slot1C_guess(); virtual void Slot1D_guess();
    virtual void Slot1E_guess(); virtual void Slot1F_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot2A_guess(); virtual void Slot2B_guess();
    virtual void Slot2C_guess(); virtual void Slot2D_guess();
    virtual void Slot2E_guess(); virtual void Slot2F_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess();
    virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess();
    virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot3A_guess(); virtual void Slot3B_guess();
    virtual void Slot3C_guess(); virtual void Slot3D_guess();
    virtual void Slot3E_guess(); virtual void Slot3F_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess();
    virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess();
    virtual void Slot4A_guess(); virtual void Slot4B_guess();
    virtual void Slot4C_guess();
};

struct DisplayModes_guess {
    unsigned int pad_000[0x160 / 4];
    CListWnd* list160_guess;
    Combo_guess* combo164_guess;
    Combo_guess* combo168_guess;
    void Init_guess();
};

struct FlagHolder_guess {
    unsigned int pad_000_guess;
    char flag_004_guess;
};

// EXTERNAL: TITANIUM 0x0046DA4A FormatText_guess
void __cdecl FormatText_guess(char* output_guess, unsigned int id_guess,
    const char* text_guess, int zero1_guess, int zero2_guess, int zero3_guess,
    int zero4_guess, int zero5_guess, int zero6_guess, int zero7_guess, int zero8_guess);

typedef long (__stdcall *SendMessageA_guess)(void*, unsigned int, unsigned int, long);

#define gHandler_guess EQ_GLOBAL(Handler_guess*, 0x00905D24)
#define gWindowProvider_guess EQ_GLOBAL(GraphicsDriverView_guess*, 0x0099E364)
#define gSendMessageA_guess EQ_GLOBAL(SendMessageA_guess, 0x0063F2D0)
#define gMessageCount_guess EQ_GLOBAL(unsigned int, 0x0099C9C8)
#define gMessageRecords_guess EQ_ARRAY(VideoMode_guess, 0x009929C8)
#define gDigits_guess EQ_ARRAY(char, 0x0099DB00)
#define gFormatBuffer_guess EQ_ARRAY(char, 0x0099DB00)
#define gFlagHolder_guess EQ_GLOBAL(FlagHolder_guess*, 0x0099E38C)

struct Filter_guess {
    unsigned char pad_0000_guess[0x5d];
    bool flag_005d_guess;
    // EXTERNAL: TITANIUM 0x0059C3A0 Filter_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C3E0 Filter_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 Filter_guess::Add_guess
    void Add_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x0059C360 Filter_guess::Finish_guess
    void Finish_guess(int value_guess);
};

struct ChoiceState_guess {
    unsigned char pad_0000_guess[4];
    unsigned char flag_0004_guess;
    // EXTERNAL: TITANIUM 0x00609D50 ChoiceState_guess::GetFirst_guess
    int GetFirst_guess();
    // EXTERNAL: TITANIUM 0x00609D60 ChoiceState_guess::GetSecond_guess
    int GetSecond_guess();
    // EXTERNAL: TITANIUM 0x00609BB0 ChoiceState_guess::Flush_guess
    void Flush_guess();
};

#define g_state_guess EQ_GLOBAL(ChoiceState_guess*, 0x0099E38C)

struct MessageOwner_guess {
    char pad_0000_guess[0x164];
    Filter_guess* firstFilter_guess;    // 0x164
    Filter_guess* secondFilter_guess;   // 0x168
    // EXTERNAL: TITANIUM 0x0056EE2B MessageOwner_guess::Init_guess
    void Init_guess();
    void OnModeChanged_guess();
    void SelectResolution_guess(unsigned int index_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A build_token_string_guess
char* __cdecl build_token_string_guess(char* buffer_guess, int token_guess,
                                       const char* p0_guess, const char* p1_guess,
                                       const char* p2_guess, const char* p3_guess,
                                       const char* p4_guess, const char* p5_guess,
                                       const char* p6_guess, const char* p7_guess,
                                       const char* p8_guess);

// Adds driver mode `data` (width, height, refresh, format) to the table: a known size gains the refresh rate
// (32 max) and format (4 max); a new size gets a row, up to 256 (TAKP: AddVideoModeTo...).
// FUNCTION: TITANIUM 0x0056ED0B
void __cdecl AddVideoMode_guess(const MessageData_guess* data) {
    unsigned int i;
    i = 0;
    if (gMessageCount_guess > 0) {
        unsigned int width = data->width_guess;
        unsigned int* key = &gMessageRecords_guess[0].second_guess;
        do {
            if (width == key[-1] && data->height_guess == *key) {
                unsigned int j;
                for (j = 0; j < gMessageRecords_guess[i].refreshRateCount_guess; ++j) {
                    if (gMessageRecords_guess[i].refreshRates_guess[j] == data->refreshRate_guess) {
                        break;
                    }
                }
                if (j == gMessageRecords_guess[i].refreshRateCount_guess &&
                    gMessageRecords_guess[i].refreshRateCount_guess < 0x20) {
                    gMessageRecords_guess[i].refreshRates_guess[j] = data->refreshRate_guess;
                    ++gMessageRecords_guess[i].refreshRateCount_guess;
                }

                for (j = 0; j < gMessageRecords_guess[i].formatCount_guess; ++j) {
                    if (gMessageRecords_guess[i].formats_guess[j] == data->format_guess) {
                        break;
                    }
                }
                if (j == gMessageRecords_guess[i].formatCount_guess &&
                    gMessageRecords_guess[i].formatCount_guess < 4) {
                    gMessageRecords_guess[i].formats_guess[j] = data->format_guess;
                    ++gMessageRecords_guess[i].formatCount_guess;
                }
                return;
            }
            ++i;
            key += 40;
        } while (i < gMessageCount_guess);
    }

    if (gMessageCount_guess < 0x100) {
        gMessageRecords_guess[gMessageCount_guess].first_guess = data->width_guess;
        gMessageRecords_guess[gMessageCount_guess].second_guess = data->height_guess;
        gMessageRecords_guess[gMessageCount_guess].refreshRateCount_guess = 1;
        gMessageRecords_guess[gMessageCount_guess].refreshRates_guess[0] = data->refreshRate_guess;
        gMessageRecords_guess[gMessageCount_guess].formatCount_guess = 1;
        gMessageRecords_guess[gMessageCount_guess].formats_guess[0] = data->format_guess;
        ++gMessageCount_guess;
    }
}

// CVideoModesWnd::Init: collects the driver's modes and lists every size; the current size's row also fills
// the refresh and depth combos and selects the current values.
// FUNCTION: TITANIUM 0x0056EE2B
// @early-stop: budget, diff ndiff=147
void DisplayModes_guess::Init_guess() {
    char buf[0x80];
    unsigned int count = gWindowProvider_guess->Slot09_guess();
    if (count > 0 && list160_guess != 0) {
        unsigned int h;
        unsigned int w;
        h = gWindowProvider_guess->Slot00_guess();
        w = gWindowProvider_guess->Slot01_guess();
        for (unsigned int k = 0; k < count; ++k) {
            MessageData_guess mode;
            gWindowProvider_guess->Slot11_guess(k, &mode);
            // At least 640x480, in D3D formats 21-24 (A8R8G8B8, X8R8G8B8, R5G6B5, X1R5G5B5).
            if (mode.width_guess >= 0x280 && mode.height_guess >= 0x1e0 &&
                (mode.format_guess == 0x15 || mode.format_guess == 0x16 ||
                 mode.format_guess == 0x18 || mode.format_guess == 0x17)) {
                // Without the 0x99E38C flag (probably full screen) only modes within slots 0/1 (likely the
                // desktop size).
                char flag = gFlagHolder_guess->flag_004_guess;
                if (flag != 0 || (mode.width_guess <= h && mode.height_guess <= w)) {
                    AddVideoMode_guess(&mode);
                }
            }
        }
        ((ListSlots_guess*)list160_guess)->Slot4C_guess();
        if (combo164_guess != 0) {
            combo164_guess->Refresh_guess();
        }
        if (combo168_guess != 0) {
            combo168_guess->Refresh_guess();
        }

        int row = 0;
        for (unsigned int i = 0; i < gMessageCount_guess; ++i) {
            sprintf(buf, "%dx%d", gMessageRecords_guess[i].first_guess,
                    gMessageRecords_guess[i].second_guess);
            if (gWindowProvider_guess->Slot04_guess() == (int)gMessageRecords_guess[i].first_guess &&
                gWindowProvider_guess->Slot05_guess() == (int)gMessageRecords_guess[i].second_guess) {
                {
                    CXStr text(buf);
                    row = list160_guess->AddString(text, -1, 0, 0);
                }
                list160_guess->SetItemData(row, i);

                int sel = 0;
                unsigned int j = 0;
                for (j = 0; j < gMessageRecords_guess[i].refreshRateCount_guess; ++j) {
                    unsigned int value = gMessageRecords_guess[i].refreshRates_guess[j];
                    if (value == 0) {
                        // Refresh 0 is the default rate (0x19E5); others print as 0x19E4 with the number.
                        strcpy(buf, pStringTable->getString(0x19e5, 0));
                    } else {
                        FormatText_guess(buf, 0x19e4, _itoa(value, gDigits_guess, 10),
                                         0, 0, 0, 0, 0, 0, 0, 0);
                    }
                    if (gWindowProvider_guess->Slot07_guess() == (int)value) {
                        sel = j;
                    }
                    if (combo164_guess != 0) {
                        CXStr text(buf);
                        combo164_guess->Fill_guess(text);
                    }
                }
                if (combo164_guess != 0) {
                    combo164_guess->SetCurSel_guess(sel);
                }

                sel = 0;
                for (j = 0; j < gMessageRecords_guess[i].formatCount_guess; ++j) {
                    unsigned int value = gMessageRecords_guess[i].formats_guess[j];
                    if (value == 0x16 || value == 0x15) {
                        // Depth names: 0x19E3 32-bit (current depth 32), 0x19E1 X1R5G5B5, 0x19E2 R5G6B5
                        // (16-bit; slot 8 tells which).
                        strcpy(buf, pStringTable->getString(0x19e3, 0));
                        if (gWindowProvider_guess->Slot06_guess() == 0x20) {
                            sel = j;
                        }
                    } else if (value == 0x18) {
                        strcpy(buf, pStringTable->getString(0x19e1, 0));
                        if (gWindowProvider_guess->Slot06_guess() == 0x10 &&
                            gWindowProvider_guess->Slot08_guess() == 0) {
                            sel = j;
                        }
                    } else if (value == 0x17) {
                        strcpy(buf, pStringTable->getString(0x19e2, 0));
                        if (gWindowProvider_guess->Slot06_guess() == 0x10 &&
                            gWindowProvider_guess->Slot08_guess() != 0) {
                            sel = j;
                        }
                    }
                    if (combo168_guess != 0) {
                        CXStr text(buf);
                        combo168_guess->Fill_guess(text);
                    }
                }
                if (combo168_guess != 0) {
                    combo168_guess->SetCurSel_guess(sel);
                }
            } else {
                int missRow;
                {
                    CXStr text(buf);
                    missRow = list160_guess->AddString(text, -1, 0, 0);
                }
                list160_guess->SetItemData(missRow, i);
            }
        }
        list160_guess->SetCurSel(row);
    }
}

// After a mode change (tu_087 calls it with the new frame size): picks the combo entries for the active
// refresh and depth (the saved ones when the 0x99E38C flag is clear), then empties and rebuilds the table.
// FUNCTION: TITANIUM 0x0056F37D
// @early-stop: budget, structural ndiff=26
void MessageOwner_guess::OnModeChanged_guess() {
    bool active_guess;
    int value_guess;
    unsigned int group_guess;
    if (g_state_guess->flag_0004_guess == 0) {
        value_guess = gWindowProvider_guess->Slot03_guess();
        group_guess = gWindowProvider_guess->Slot02_guess();
        active_guess = false;
    } else {
        value_guess = gWindowProvider_guess->Slot07_guess();
        group_guess = gWindowProvider_guess->Slot06_guess();
        active_guess = true;
    }
    int choice1_guess = -1;
    int choice2_guess = -1;
    int key_guess = g_state_guess->GetFirst_guess();
    g_state_guess->GetSecond_guess();
    unsigned int count = gMessageCount_guess;
    unsigned int i;
    if (count > 0) {
        i = 0;
        unsigned int* key = &gMessageRecords_guess[0].second_guess;
        do {
            if (key[-1] == key_guess && *key != 0) {
                if (i != -1) {
                    for (unsigned int j = 0; j < gMessageRecords_guess[i].refreshRateCount_guess; ++j) {
                        if (value_guess == gMessageRecords_guess[i].refreshRates_guess[j]) {
                            choice1_guess = j;
                            break;
                        }
                    }
                    // Depth 16 -> entry 0, 32 -> entry 1; assumes the combo holds one entry per depth.
                    choice2_guess = (group_guess >> 4) - 1;
                }
                break;
            }
            ++i;
            key += 40;
        } while (i < count);
    }
    Filter_guess* first_guess = firstFilter_guess;
    if (first_guess != 0) {
        bool flag_guess;
        if (active_guess || choice1_guess == -1) {
            flag_guess = true;
        } else {
            flag_guess = false;
        }
        first_guess->flag_005d_guess = flag_guess;
        firstFilter_guess->Finish_guess(choice1_guess);
    }
    if (secondFilter_guess != 0) {
        secondFilter_guess->Finish_guess(choice2_guess);
        bool flag_guess;
        if (active_guess || choice2_guess == -1) {
            flag_guess = true;
        } else {
            flag_guess = false;
        }
        secondFilter_guess->flag_005d_guess = flag_guess;
    }
    gMessageCount_guess = 0;
    Init_guess();
    g_state_guess->Flush_guess();
}

// Resolution row `index_guess` picked: refills both combos with that size's rates and depths, keeping the
// previous choices.
// FUNCTION: TITANIUM 0x0056F4C1
void MessageOwner_guess::SelectResolution_guess(unsigned int index_guess) {
    unsigned int i;
    char buffer_guess[0x80];
    if (index_guess < gMessageCount_guess) {
        int firstChoice_guess = 0;
        int secondChoice_guess = 0;
        if (firstFilter_guess != 0) {
            firstChoice_guess = firstFilter_guess->GetCurChoice_guess();
            firstFilter_guess->Reset_guess();
        }
        if (secondFilter_guess != 0) {
            secondChoice_guess = secondFilter_guess->GetCurChoice_guess();
            secondFilter_guess->Reset_guess();
        }
        for (i = 0; i < gMessageRecords_guess[index_guess].refreshRateCount_guess; ++i) {
            unsigned int value_guess = gMessageRecords_guess[index_guess].refreshRates_guess[i];
            if (value_guess > 0) {
                build_token_string_guess(buffer_guess, 0x19e4,
                                         _itoa(value_guess, gDigits_guess, 10),
                                         0, 0, 0, 0, 0, 0, 0, 0);
            } else {
                strcpy(buffer_guess, pStringTable->getString(0x19e5, 0));
            }
            if (firstFilter_guess != 0) {
                CXStr text_guess(buffer_guess);
                firstFilter_guess->Add_guess(text_guess);
            }
        }
        for (i = 0; i < gMessageRecords_guess[index_guess].formatCount_guess; ++i) {
            unsigned int value_guess = gMessageRecords_guess[index_guess].formats_guess[i];
            if (value_guess == 0x16 || value_guess == 0x15) {
                strcpy(buffer_guess, pStringTable->getString(0x19e3, 0));
            } else if (value_guess == 0x18) {
                strcpy(buffer_guess, pStringTable->getString(0x19e1, 0));
            } else if (value_guess == 0x17) {
                strcpy(buffer_guess, pStringTable->getString(0x19e2, 0));
            }
            if (secondFilter_guess != 0) {
                CXStr text_guess(buffer_guess);
                secondFilter_guess->Add_guess(text_guess);
            }
        }
        // No null check here, unlike every other use of the refresh combo.
        firstFilter_guess->Finish_guess(firstChoice_guess);
        if (secondFilter_guess != 0) {
            secondFilter_guess->Finish_guess(secondChoice_guess);
        }
    }
}

// Returns 0. A shared stub that fills many vtable slots (the CXWnd slot 40 default among them) and is
// the default trace callback in 0x0043A15C.
// FUNCTION: TITANIUM 0x0056F736
int __cdecl ReturnZero_guess() {
    return 0;
}

struct ParentBase_guess {
    unsigned char pad_0000_guess[0x15c];
    unsigned char tail_015c_guess[4];
};

#define pVideoModesWnd_guess EQ_GLOBAL(ParentBase_guess*, 0x00850C78)


// EXTERNAL: TITANIUM 0x0063FD9C ??_7Notifier_guess@@6B@
struct Notifier_guess {
    virtual void Slot00_guess();
    virtual ~Notifier_guess() {
        Reset_guess(-1);
    }
    // EXTERNAL: TITANIUM 0x005482A0 Notifier_guess::Reset_guess
    void Reset_guess(int value);
};

// EXTERNAL: TITANIUM 0x0065F990 ??_7VideoModesWindow_guess@@6BVideoModesBase_guess@@@
// EXTERNAL: TITANIUM 0x0065FAB0 ??_7VideoModesWindow_guess@@6BNotifier_guess@@@

#include "titanium/layouts/ui.h"
#include "titanium/wnd/CGiveWnd.h"
#include "titanium/wnd/CTradeWnd.h"

struct VideoModesBase_guess {
    char pad_004[0x60];                     // 0x004..0x063
    unsigned int windowStyle_064;           // 0x064
    char pad_068[0xbc];                     // 0x068..0x123
    CScreenPieceTemplate* sidlPiece_124;      // 0x124
    char pad_128[0x34];                     // 0x128..0x15b
    virtual void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A3900 VideoModesBase_guess::VideoModesBase_guess
    VideoModesBase_guess(CXWnd* parent, const CXStr& screen);
    // EXTERNAL: TITANIUM 0x005A3100 ??1VideoModesBase_guess@@UAE@XZ
    virtual ~VideoModesBase_guess();
};

struct WindowFlags_guess {
    char pad_000[0x66];
    unsigned char flags_066;                // 0x066
};

struct ComboWnd_guess {
    // EXTERNAL: TITANIUM 0x0059C330 ComboWnd_guess::SetColors_guess
    void SetColors_guess(unsigned long a, unsigned long b, unsigned long c);
};

struct ListColumn_guess {
    // EXTERNAL: TITANIUM 0x0059C140 ListColumn_guess::AddColumn_guess
    void AddColumn_guess(const CXStr& text, int width, int a, int b);
};

struct VideoModesWindow_guess : VideoModesBase_guess, Notifier_guess {
    CXWnd* resolutionList_160;              // 0x160
    CXWnd* refreshCombo_164;                // 0x164
    CXWnd* depthCombo_168;                  // 0x168
    CXWnd* acceptButton_16c;                // 0x16c
    // EXTERNAL: TITANIUM 0x0056EE2B VideoModesWindow_guess::Init_guess
    void Init_guess();
    int WndNotification(CXWnd* sender, unsigned int message, void* data);
    VideoModesWindow_guess(CXWnd* parent);
};

// Accept: refuses while the trade (0x850C50) or give (0x850C60) window is up, string 0xC78; otherwise saves
// the current mode, asks the main window to switch, and starts a 30 s keep-or-revert confirmation.
// FUNCTION: TITANIUM 0x0056F739
int VideoModesWindow_guess::WndNotification(CXWnd* sender, unsigned int message, void* data) {
    char buf[0x100];
    if (message == 1) {
        if (sender == resolutionList_160) {
            unsigned int index = ((CListWnd*)resolutionList_160)->GetItemData(
                ((CListWnd*)resolutionList_160)->GetCurSel());
            ((MessageOwner_guess*)this)->SelectResolution_guess(index);
        } else if (sender == acceptButton_16c && resolutionList_160 != 0) {
            if ((pinstCGiveWnd_guess != 0 && pinstCGiveWnd_guess->IsVisible_guess()) ||
                (pinstCTradeWnd_guess != 0 && pinstCTradeWnd_guess->IsVisible_guess())) {
                pEverQuest->dsp_chat(pStringTable->getString(0xc78, 0), 0xf, 1);
            } else {
                int index = ((CListWnd*)resolutionList_160)->GetItemData(
                    ((CListWnd*)resolutionList_160)->GetCurSel());
                int choice1 = 0;
                int choice2 = 0;
                // The request carries a bit depth (16 or 32), not the D3D format.
                unsigned int fourth = 0x10;
                if (refreshCombo_164 != 0) {
                    choice1 = ((Combo_guess*)refreshCombo_164)->GetCurChoice_guess();
                }
                if (depthCombo_168 != 0) {
                    choice2 = ((Combo_guess*)depthCombo_168)->GetCurChoice_guess();
                }
                if (gMessageRecords_guess[index].formats_guess[choice2] == 0x16 ||
                    gMessageRecords_guess[index].formats_guess[choice2] == 0x15) {
                    fourth = 0x20;
                }
                EQ_GLOBAL(unsigned int, 0x00796224) = gWindowProvider_guess->Slot04_guess();
                EQ_GLOBAL(unsigned int, 0x00796228) = gWindowProvider_guess->Slot05_guess();
                EQ_GLOBAL(unsigned int, 0x0079622C) = gWindowProvider_guess->Slot06_guess();
                EQ_GLOBAL(unsigned int, 0x0099C9CC) = gWindowProvider_guess->Slot07_guess();
                MessageData_guess msg;
                msg.width_guess = gMessageRecords_guess[index].first_guess;
                msg.height_guess = gMessageRecords_guess[index].second_guess;
                msg.refreshRate_guess = gMessageRecords_guess[index].refreshRates_guess[choice1];
                msg.format_guess = fourth;
                gHandler_guess->Refresh_guess();
                // Private message 0x4644 (wParam 0x4244, lParam the mode): the graphics side switches.
                SendMessageA((HWND)gWindowProvider_guess->GetWindow_guess(), 0x4644, 0x4244, (LPARAM)&msg);
                // String 0x1A1A with the 30 s count; dialog kind 0xC (likely yes/no), 30000 ms timeout.
                FormatText_guess(buf, 0x1a1a, _itoa(30, gDigits_guess, 10),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                pConfirmationDialogPool_guess->Activate(
                    pVideoModesWnd_guess != 0 ? &pVideoModesWnd_guess->tail_015c_guess : 0,
                    100, buf, 0xc, 30000, 0, 0);
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

// CVideoModesWnd::RestoreOldMode (Mac map): switches back to the mode the accept saved (0x796224 width,
// 0x796228 height, 0x79622C depth, 0x99C9CC refresh).
// FUNCTION: TITANIUM 0x0056F988
void __cdecl RestoreOldMode_guess() {
    MessageData_guess data;
    data.width_guess = EQ_GLOBAL(unsigned int, 0x00796224);
    data.height_guess = EQ_GLOBAL(unsigned int, 0x00796228);
    data.refreshRate_guess = EQ_GLOBAL(unsigned int, 0x0099C9CC);
    data.format_guess = EQ_GLOBAL(unsigned int, 0x0079622C);
    gHandler_guess->Refresh_guess();
    gSendMessageA_guess(gWindowProvider_guess->GetWindow_guess(), 0x4644, 0x4244, (long)&data);
}

// Builds the window from SIDL, adds the 200-pixel Resolution column and fills the lists.
// FUNCTION: TITANIUM 0x0056F9FA
VideoModesWindow_guess::VideoModesWindow_guess(CXWnd* parent)
    : VideoModesBase_guess(parent, "VideoModesWindow") {
    if (sidlPiece_124 != 0) {
        windowStyle_064 |= sidlPiece_124->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        resolutionList_160 = ((CSidlScreenWnd*)this)->GetChildItem("VIDW_VideoResolutionsList");
        if (resolutionList_160 != 0) {
            ((WindowFlags_guess*)resolutionList_160)->flags_066 &= 0xdf;
            ((CListWnd*)resolutionList_160)->SetColors(0xffffffff, 0xffffff00, 0xff808080);
            ((ListColumn_guess*)resolutionList_160)->AddColumn_guess(CXStr("Resolution"), 200, 0, 3);
        }
        refreshCombo_164 = ((CSidlScreenWnd*)this)->GetChildItem("VIDW_RefreshRateCombobox");
        depthCombo_168 = ((CSidlScreenWnd*)this)->GetChildItem("VIDW_BitDepthCombobox");
        if (refreshCombo_164 != 0) {
            ((ComboWnd_guess*)refreshCombo_164)->SetColors_guess(0xffffffff, 0xffffff00, 0xff808080);
        }
        if (depthCombo_168 != 0) {
            ((ComboWnd_guess*)depthCombo_168)->SetColors_guess(0xffffffff, 0xffffff00, 0xff808080);
        }
        acceptButton_16c = ((CSidlScreenWnd*)this)->GetChildItem("VIDW_AcceptButton");
        Init_guess();
    }
}

