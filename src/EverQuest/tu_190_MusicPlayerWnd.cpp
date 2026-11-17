// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 190: a hint from compare/tumap.py.
// CMusicPlayerWnd ("MusicPlayerWnd"; Handler_guess is the same window) over the MP3 player that
// EqSoundManager (0x851390) holds at +0: +0x188 SongSelector combo, +0x18C Volume slider, +0x19C the
// remembered playlist ("***" = none). The first function is CMIZoneSelectWnd's (tu_189); the last belongs
// to a neighbouring STML window, probably CNoteWnd.
#include "titanium/types.h"
#include "titanium/crt.h"

struct CComboWnd_guess;
struct CSliderWnd_guess;

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(void* value, const char* category, char* input, char* output,
                                int size, int mode);

struct Settings_guess {
    // EXTERNAL: TITANIUM 0x00572300 Settings_guess::Get_guess
    void* Get_guess();
};

struct Handler_guess {
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
    virtual void Dispatch_guess(int zero, int one);
    virtual void Slot49_guess();
    virtual bool Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual CXRect GetScreenRect_guess() const;
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

    char pad_004_guess[0x58];
    unsigned char flag_05c_guess; // 0x5c
    char pad_05d_guess[0x140 - 0x5d];
    Settings_guess settings_140_guess; // 0x140
    char pad_141_guess[0x15c - 0x141];
    CXWnd* playButton_15c_guess;
    CXWnd* pauseButton_160_guess;
    CXWnd* stopButton_164_guess;
    CXWnd* backButton_168_guess;
    CXWnd* nextButton_16c_guess;
    CButtonWnd* randomButton_170_guess;
    CXWnd* deleteButton_174_guess;
    CXWnd* addButton_178_guess;
    CXWnd* clearButton_17c_guess;
    CXWnd* saveButton_180_guess;
    CXWnd* songTimer_184_guess;
    CComboWnd_guess* state_188_guess;
    CXWnd* volume_18c_guess;
    int mode_190_guess;
    const char* currentSong_0194_guess;
    int value_198_guess;
    char text_19c_guess[0x98];
    int value_234_guess;
    int value_238_guess;
    char pad_23c_guess[0x160];
    char flag_39c_guess;
    char flag_039d_guess;
    char flag_39e_guess;

    // EXTERNAL: TITANIUM 0x0053964C Handler_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x005A2230 Handler_guess::WndNotification
    void WndNotification(int value, int mode, int extra);
    void MIZoneSelectWndNotification_guess(int value, int mode, int extra);
    void RestorePlaylist_guess();
    void UpdateSongList_guess();
    void UpdateButtons_guess();
    int OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A2660 Handler_guess::LoadIniInfo
    void LoadIniInfo();
    void MusicPlayerLoadIniInfo_guess();
    // EXTERNAL: TITANIUM 0x005A1CD0 Handler_guess::SaveIni_guess
    void SaveIni_guess();
    // EXTERNAL: TITANIUM 0x005A1890 Handler_guess::StoreIniInfo
    void StoreIniInfo();
    int WndNotification_guess(CXWnd* sender, int message, void* data);
    void StoreIniInfo_guess();
    bool UpdateVolume_guess();
};

#define g_pickerHandler_guess EQ_GLOBAL(Handler_guess*, 0x00850C84)

// On close, also closes the file picker (0x850C84, probably CFileSelectionWnd) if this window opened it.
// FUNCTION: TITANIUM 0x00539BC6
bool Handler_guess::Slot50_guess() {
    if (flag_039d_guess != 0) {
        if (g_pickerHandler_guess != 0) {
            g_pickerHandler_guess->Slot34_guess();
        }
        flag_039d_guess = 0;
    }
    return true;
}

struct Clock_guess {
    char pad_000_guess[0x148];
    int tick_148_guess; // 0x148
};

#define g_clock_guess EQ_GLOBAL(Clock_guess*, 0x00905D24)

struct Processor_guess {
    // EXTERNAL: TITANIUM 0x004C5EDB Processor_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x004C5EA1 Processor_guess::GetState_guess
    int GetState_guess();
    // EXTERNAL: TITANIUM 0x004C5EF6 Processor_guess::GetVolume_guess
    double GetVolume_guess();
    // EXTERNAL: TITANIUM 0x004C5E9D Processor_guess::IsShuffle_guess
    int IsShuffle_guess();
    // EXTERNAL: TITANIUM 0x004C5EC1 Processor_guess::GetItem_guess
    const char* GetItem_guess(int index);
    // EXTERNAL: TITANIUM 0x004C5EDF Processor_guess::GetCurrent_guess
    const char* GetCurrent_guess();
    // EXTERNAL: TITANIUM 0x004C70FD Processor_guess::ClearPlaylist_guess
    void ClearPlaylist_guess();
    // EXTERNAL: TITANIUM 0x004C71B6 Processor_guess::SetText_guess
    int SetText_guess(char* text);
    // EXTERNAL: TITANIUM 0x004C70CE Processor_guess::PlayIndex_guess
    void PlayIndex_guess(int index);
    // EXTERNAL: TITANIUM 0x004C703E Processor_guess::Stop_guess
    void Stop_guess();
    // EXTERNAL: TITANIUM 0x004C66D1 Processor_guess::Pause_guess
    void Pause_guess();
    // EXTERNAL: TITANIUM 0x004C741A Processor_guess::PreviousTrack_guess
    void PreviousTrack_guess();
    // EXTERNAL: TITANIUM 0x004C7403 Processor_guess::NextTrack_guess
    void NextTrack_guess();
    // EXTERNAL: TITANIUM 0x004C713C Processor_guess::Remove_guess
    void Remove_guess(const char* name);
    // EXTERNAL: TITANIUM 0x004C5EA9 Processor_guess::GetTrackLength_guess
    int GetTrackLength_guess();
    // EXTERNAL: TITANIUM 0x004C5EB9 Processor_guess::SetPosition_guess
    void SetPosition_guess(int position);
    // EXTERNAL: TITANIUM 0x004C5EE3 Processor_guess::SetVolume_guess
    void SetVolume_guess(float volume);
    // EXTERNAL: TITANIUM 0x004C5F00 Processor_guess::Save_guess
    void Save_guess(char* path);
    // EXTERNAL: TITANIUM 0x004C7314 Processor_guess::SetMode_guess
    void SetMode_guess(int mode);
    // EXTERNAL: TITANIUM 0x004C705F Processor_guess::Play_guess
    void Play_guess();
};

struct CComboWnd_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 CComboWnd_guess::Reset_guess
    void Reset_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 CComboWnd_guess::SetText_guess
    void SetText_guess(CXStr& text);
    // EXTERNAL: TITANIUM 0x0059C360 CComboWnd_guess::SetCurrent_guess
    void SetCurrent_guess(const char* text);
    // EXTERNAL: TITANIUM 0x0059C3B0 CComboWnd_guess::GetValue_guess
    CXStr GetValue_guess();
    // EXTERNAL: TITANIUM 0x0059C3A0 CComboWnd_guess::GetCurChoice_guess
    int GetCurChoice_guess();

    char pad_000_guess[0x78];
    CXStr text_078_guess;
};

struct Manager_guess {
    Processor_guess* processor_guess;
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00851390)

// CMIZoneSelectWnd notifications: SelectButton (+0x234) or notification 4 sends the chosen zone
// (0x53964C, opcode 0xDFE) and closes; CancelButton (+0x238) just closes.
// FUNCTION: TITANIUM 0x00539738
void Handler_guess::MIZoneSelectWndNotification_guess(int value, int mode, int extra) {
    if (mode == 1) {
        if (value == value_234_guess) {
            Prepare_guess();
            Dispatch_guess(0, 1);
        } else if (value == value_238_guess) {
            Dispatch_guess(0, 1);
        }
    } else if (mode == 4) {
        Prepare_guess();
        Dispatch_guess(0, 1);
    }
    WndNotification(value, mode, extra);
}

struct SidlPiece_guess {
    char pad_0000_guess[0x60];
    unsigned int flags_0060_guess; // 0x60
};

// Local polymorphic base for the CSidlScreenWnd ctor (0x005A3850), 0x15C bytes.
struct SidlScreenBase_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005A3100 ??1SidlScreenBase_guess@@UAE@XZ
    virtual ~SidlScreenBase_guess();
    // EXTERNAL: TITANIUM 0x005A3850 SidlScreenBase_guess::SidlScreenBase_guess
    SidlScreenBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    char pad_0004_guess[0x18 - 0x04];
    unsigned char field_0018_guess; // 0x18
    char pad_0019_guess[0x64 - 0x19];
    unsigned int windowStyle_0064_guess; // 0x64
    char pad_0068_guess[0x124 - 0x68];
    SidlPiece_guess* sidlPiece_0124_guess; // 0x124
    char pad_0128_guess[0x15c - 0x128];
};

struct CSliderWnd_guess {
    // EXTERNAL: TITANIUM 0x005BD180 CSliderWnd_guess::SetValue_guess
    void SetValue_guess(int value);
    // EXTERNAL: TITANIUM 0x005BCD10 CSliderWnd_guess::SetValueFromAudio_guess
    void SetValueFromAudio_guess(int value);
    // EXTERNAL: TITANIUM 0x005BCB90 CSliderWnd_guess::GetValue_guess
    int GetValue_guess();
};

// EXTERNAL: TITANIUM 0x00659088 ??_7CMusicPlayerWnd_guess@@6B@
struct CMusicPlayerWnd_guess : SidlScreenBase_guess {
    virtual void Slot00_guess();
    CMusicPlayerWnd_guess(CXWnd* parent);
    CXWnd* playButton_015c_guess;
    CXWnd* pauseButton_0160_guess;
    CXWnd* stopButton_0164_guess;
    CXWnd* backButton_0168_guess;
    CXWnd* nextButton_016c_guess;
    CXWnd* randomButton_0170_guess;
    CXWnd* deleteButton_0174_guess;
    CXWnd* addButton_0178_guess;
    CXWnd* clearButton_017c_guess;
    CXWnd* saveButton_0180_guess;
    CXWnd* songTimer_0184_guess;
    CXWnd* songSelector_0188_guess;
    CXWnd* volume_018c_guess;
    char pad_0190_guess[0x198 - 0x190];
    int field_0198_guess;
    char pad_019c_guess[0x39d - 0x19c];
    unsigned char flag_039d_guess;
};

// Music player window constructor: finds the play, pause, stop, back, next, random, playlist edit and
// save buttons, the song timer, SongSelector and the Volume slider, which starts at 21 (0x005BD180).
// FUNCTION: TITANIUM 0x00539810
CMusicPlayerWnd_guess::CMusicPlayerWnd_guess(CXWnd* parent)
    : SidlScreenBase_guess(parent, "MusicPlayerWnd", 0xfffffdff, 1, 0) {
    playButton_015c_guess = 0;
    stopButton_0164_guess = 0;
    backButton_0168_guess = 0;
    nextButton_016c_guess = 0;
    pauseButton_0160_guess = 0;
    randomButton_0170_guess = 0;
    deleteButton_0174_guess = 0;
    addButton_0178_guess = 0;
    clearButton_017c_guess = 0;
    saveButton_0180_guess = 0;
    songTimer_0184_guess = 0;
    songSelector_0188_guess = 0;
    volume_018c_guess = 0;
    if (sidlPiece_0124_guess != 0) {
        windowStyle_0064_guess |= sidlPiece_0124_guess->flags_0060_guess | 0x800;
        field_0018_guess = 0;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        playButton_015c_guess = ((CSidlScreenWnd*)this)->GetChildItem("PlayButton");
        stopButton_0164_guess = ((CSidlScreenWnd*)this)->GetChildItem("StopButton");
        backButton_0168_guess = ((CSidlScreenWnd*)this)->GetChildItem("BackButton");
        nextButton_016c_guess = ((CSidlScreenWnd*)this)->GetChildItem("NextButton");
        pauseButton_0160_guess = ((CSidlScreenWnd*)this)->GetChildItem("PauseButton");
        randomButton_0170_guess = ((CSidlScreenWnd*)this)->GetChildItem("RandomButton");
        deleteButton_0174_guess = ((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        addButton_0178_guess = ((CSidlScreenWnd*)this)->GetChildItem("AddButton");
        clearButton_017c_guess = ((CSidlScreenWnd*)this)->GetChildItem("ClearButton");
        saveButton_0180_guess = ((CSidlScreenWnd*)this)->GetChildItem("SaveButton");
        songTimer_0184_guess = ((CSidlScreenWnd*)this)->GetChildItem("SongTimer");
        songSelector_0188_guess = ((CSidlScreenWnd*)this)->GetChildItem("SongSelector");
        volume_018c_guess = ((CSidlScreenWnd*)this)->GetChildItem("Volume");
        if (volume_018c_guess != 0) {
            ((CSliderWnd_guess*)volume_018c_guess)->SetValue_guess(0x15);
        }
        field_0198_guess = 0;
        flag_039d_guess = 0;
    }
}

// Reloads the remembered playlist into the player, then restores shuffle (Random) and playing (Playing).
// FUNCTION: TITANIUM 0x00539BEB
void Handler_guess::RestorePlaylist_guess() {
    Slot70_guess();
    if (strcmp(text_19c_guess, "***") != 0 && g_manager_guess != 0 &&
        g_manager_guess->processor_guess != 0) {
        g_manager_guess->processor_guess->ClearPlaylist_guess();
        g_manager_guess->processor_guess->SetText_guess(text_19c_guess);
        if (flag_39e_guess != 0) {
            g_manager_guess->processor_guess->SetMode_guess(1);
        }
        if (flag_39c_guess != 0) {
            g_manager_guess->processor_guess->Play_guess();
        }
    }
}

// Refills the song combo from the playlist and selects the current song.
// FUNCTION: TITANIUM 0x00539C60
void Handler_guess::UpdateSongList_guess() {
    Processor_guess* processor = g_manager_guess->processor_guess;
    if (processor != 0) {
        int count = processor->GetCount_guess();
        if (state_188_guess != 0) {
            state_188_guess->Reset_guess();
            for (int index = 0; index < count; ++index) {
                CXStr text(processor->GetItem_guess(index));
                state_188_guess->SetText_guess(text);
            }
            const char* value = processor->GetCurrent_guess();
            state_188_guess->SetCurrent_guess(value);
            state_188_guess->text_078_guess = state_188_guess->GetValue_guess();
            currentSong_0194_guess = value;
        }
    }
}

// Enables the buttons by play state (GetState_guess: 0 stopped, 1 playing, 2 paused) and playlist size;
// editing waits while the file picker is open (+0x39D). Random shows GetPlaying_guess, really the shuffle
// flag.
// FUNCTION: TITANIUM 0x00539D4B
void Handler_guess::UpdateButtons_guess() {
    if (g_manager_guess->processor_guess != 0) {
        int count;
        bool selected;
        bool mode;
        bool stopped;
        count = g_manager_guess->processor_guess->GetCount_guess();
        selected = g_manager_guess->processor_guess->GetState_guess() == 1;
        mode = g_manager_guess->processor_guess->GetState_guess() == 2;
        stopped = g_manager_guess->processor_guess->GetState_guess() == 0;
        CXWnd* playButton = playButton_15c_guess;
        if (playButton != 0) {
            playButton->Enabled = count > 0 && !selected;
        }
        if (pauseButton_160_guess != 0) {
            pauseButton_160_guess->Enabled = selected || mode;
        }
        if (stopButton_164_guess != 0) {
            stopButton_164_guess->Enabled = !stopped;
        }
        if (backButton_168_guess != 0) {
            backButton_168_guess->Enabled = count > 0;
        }
        if (nextButton_16c_guess != 0) {
            nextButton_16c_guess->Enabled = count > 0;
        }
        if (deleteButton_174_guess != 0) {
            deleteButton_174_guess->Enabled = count > 0 && flag_039d_guess == 0;
        }
        if (clearButton_17c_guess != 0) {
            clearButton_17c_guess->Enabled = count > 0 && flag_039d_guess == 0;
        }
        if (randomButton_170_guess != 0) {
            randomButton_170_guess->Enabled = count > 0 && flag_039d_guess == 0;
        }
        if (saveButton_180_guess != 0) {
            saveButton_180_guess->Enabled = count > 0 && flag_039d_guess == 0;
        }
        if (state_188_guess != 0) {
            ((CXWnd*)state_188_guess)->Enabled = count > 0 && flag_039d_guess == 0;
        }
        if (addButton_178_guess != 0) {
            addButton_178_guess->Enabled = flag_039d_guess == 0;
        }
        if (count == 0) {
            if (randomButton_170_guess == 0) {
                return;
            }
            randomButton_170_guess->SetCheck(false);
        } else {
            if (randomButton_170_guess == 0) {
                return;
            }
            randomButton_170_guess->SetCheck(
                g_manager_guess->processor_guess->IsShuffle_guess() == 1);
        }
    }
}

// Reads LastM3U, Playing and Random from the UI ini, then the base LoadIniInfo.
// FUNCTION: TITANIUM 0x00539F0D
void Handler_guess::MusicPlayerLoadIniInfo_guess() {
    char output_guess[512];
    char input_guess[512];
    if (NewUIINI() != 0) {
        sprintf(input_guess, "%s", EQ_ARRAY(char, 0x006591B8));
        LoadStringFromUIIniFile_guess(settings_140_guess.Get_guess(), "LastM3U", input_guess, output_guess, 0x1ff, 1);
        strcpy(text_19c_guess, output_guess);
        sprintf(input_guess, "%s", EQ_ARRAY(char, 0x006410A8));
        LoadStringFromUIIniFile_guess(settings_140_guess.Get_guess(), "Playing", input_guess, output_guess, 0x1ff, 1);
        flag_39c_guess = (output_guess[0] == '1' || output_guess[0] == 't' || output_guess[0] == 'T') ? 1 : 0;
        sprintf(input_guess, "%s", EQ_ARRAY(char, 0x006410A8));
        LoadStringFromUIIniFile_guess(settings_140_guess.Get_guess(), "Random", input_guess, output_guess, 0x1ff, 1);
        flag_39e_guess = (output_guess[0] == '1' || output_guess[0] == 't' || output_guess[0] == 'T') ? 1 : 0;
        LoadIniInfo();
    }
}

// EXTERNAL: TITANIUM 0x0060BF20 SaveSetting_guess
void __cdecl SaveSetting_guess(void* setting, const char* name, char* value);

// Writes LastM3U, Playing and Random to the UI ini, then the base StoreIniInfo.
// FUNCTION: TITANIUM 0x0053A06B
// @early-stop: unknown, structural ndiff=22
void Handler_guess::StoreIniInfo_guess() {
    int playing;
    int status = 1;
    if (g_manager_guess->processor_guess != 0) {
        int state = g_manager_guess->processor_guess->GetState_guess();
        status = 1 - (state != 0);
        g_manager_guess->processor_guess->IsShuffle_guess();
    }
    if (NewUIINI() != 0) {
        char buffer[256];
        sprintf(buffer, "%s", text_19c_guess);
        SaveSetting_guess(settings_140_guess.Get_guess(), "LastM3U", buffer);
        playing = status == 0;
        sprintf(buffer, "%d", playing);
        SaveSetting_guess(settings_140_guess.Get_guess(), "Playing", buffer);
        sprintf(buffer, "%d", playing);
        // Writes the Playing value again; the shuffle flag read above is dropped.
        SaveSetting_guess(settings_140_guess.Get_guess(), "Random", buffer);
        StoreIniInfo();
    }
}

// Sets the slider from the player volume (0-1 to 0-20, rounded) and refreshes the song list.
// FUNCTION: TITANIUM 0x0053A16D
bool Handler_guess::UpdateVolume_guess() {
    Processor_guess* processor = g_manager_guess->processor_guess;
    if (processor != 0) {
        if (volume_18c_guess != 0) {
            int value = (int)(processor->GetVolume_guess() * *EQ_ARRAY(double, 0x00641080) +
                              *EQ_ARRAY(double, 0x006410A0));
            ((CSliderWnd_guess*)volume_18c_guess)->SetValueFromAudio_guess(value);
        }
        UpdateSongList_guess();
        return true;
    }
    return false;
}

// Every 250 ms while shown: refreshes the song list when the song changed, then the buttons.
// FUNCTION: TITANIUM 0x0053A1B5
int Handler_guess::OnProcessFrame_guess() {
    if (flag_05c_guess != 0) {
        int now = g_clock_guess->tick_148_guess;
        if (now - value_198_guess > 0xfa) {
            value_198_guess = now;
            if (g_manager_guess->processor_guess != 0) {
                if (g_manager_guess->processor_guess->GetCurrent_guess() != currentSong_0194_guess) {
                    UpdateSongList_guess();
                }
            }
            UpdateButtons_guess();
        }
    }
    return ((CXWnd*)this)->OnProcessFrame();
}

struct PathStr_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00572380 PathStr_guess::Find_guess
    bool Find_guess(char c, int* pos);
    // EXTERNAL: TITANIUM 0x00571760 PathStr_guess::FindLast_guess
    bool FindLast_guess(char c, int* pos);
    // EXTERNAL: TITANIUM 0x005715D0 PathStr_guess::GetChar_guess
    short GetChar_guess(int index);
    // EXTERNAL: TITANIUM 0x00572130 PathStr_guess::Delete_guess
    void Delete_guess(int pos, int count);
    // EXTERNAL: TITANIUM 0x0050178B PathStr_guess::Right_guess
    PathStr_guess Right_guess(int count);
};

struct CFileSelectionWnd_guess : Handler_guess {
    virtual void Open_guess(Handler_guess* owner, int flags);
    // EXTERNAL: TITANIUM 0x005024B7 CFileSelectionWnd_guess::HasSelection_guess
    int HasSelection_guess();
    // EXTERNAL: TITANIUM 0x00502AA1 CFileSelectionWnd_guess::GetName_guess
    PathStr_guess GetName_guess(int index);
};

#define g_filePicker_guess EQ_GLOBAL(CFileSelectionWnd_guess*, 0x00850C84)

// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
void __cdecl FormatString_guess(char* output, int id, const char* a1, const char* a2,
                                const char* a3, const char* a4, const char* a5, const char* a6,
                                const char* a7, const char* a8, const char* a9);
// EXTERNAL: TITANIUM 0x00574950 CompareNoCase_guess
int __cdecl CompareNoCase_guess(const char* first, const char* second);
// EXTERNAL: TITANIUM 0x004B1357 Join_guess
CXStr __cdecl Join_guess(const CXStr& left, const char* right);

// Add and Save open the file picker (+0x190: 0 add, 1 save); notification 0x22 is its answer. Adding
// reports per file (0x1D75 not found, 0xC76 how many) and the total (0xC77); Save writes <name>.m3u. A
// click on SongTimer seeks to that fraction of the song; 0xE from Volume sets it (slider * 0.05).
// FUNCTION: TITANIUM 0x0053A20B
// @early-stop: budget, structural ndiff=40
int Handler_guess::WndNotification_guess(CXWnd* sender, int message, void* data) {
    if (message == 1) {
        if (sender == addButton_178_guess) {
            if (g_filePicker_guess != 0) {
                mode_190_guess = 0;
                flag_039d_guess = 1;
                g_filePicker_guess->Open_guess(this, 0x100);
                UpdateButtons_guess();
            }
            return 0;
        }

        if (sender == saveButton_180_guess) {
            if (g_filePicker_guess != 0) {
                mode_190_guess = 1;
                flag_039d_guess = 1;
                g_filePicker_guess->Open_guess(this, 0);
                UpdateButtons_guess();
            }
            return 0;
        }
        if (sender == (CXWnd*)state_188_guess) {
            g_manager_guess->processor_guess->PlayIndex_guess(state_188_guess->GetCurChoice_guess());
            UpdateSongList_guess();
            return 0;
        }
        if (sender == randomButton_170_guess) {
            if (randomButton_170_guess->Checked) {
                g_manager_guess->processor_guess->SetMode_guess(1);
            } else {
                g_manager_guess->processor_guess->SetMode_guess(0);
            }
            g_manager_guess->processor_guess->Play_guess();
            Slot71_guess();
            UpdateSongList_guess();
            return 0;
        }
        if (sender == playButton_15c_guess) {
            g_manager_guess->processor_guess->Play_guess();
            Slot71_guess();
            return 0;
        }
        if (sender == stopButton_164_guess) {
            g_manager_guess->processor_guess->Stop_guess();
            Slot71_guess();
            return 0;
        }
        if (sender == pauseButton_160_guess) {
            g_manager_guess->processor_guess->Pause_guess();
            return 0;
        }
        if (sender == backButton_168_guess) {
            g_manager_guess->processor_guess->PreviousTrack_guess();
            return 0;
        }
        if (sender == nextButton_16c_guess) {
            g_manager_guess->processor_guess->NextTrack_guess();
            return 0;
        }
        if (sender == deleteButton_174_guess) {
            g_manager_guess->processor_guess->Remove_guess(currentSong_0194_guess);
            UpdateSongList_guess();
            return 0;
        }
        if (sender == clearButton_17c_guess) {
            g_manager_guess->processor_guess->Stop_guess();
            g_manager_guess->processor_guess->ClearPlaylist_guess();
            strcpy(text_19c_guess, EQ_ARRAY(char, 0x006591B8));
            Slot71_guess();
            UpdateSongList_guess();
            return 0;
        }
        if (sender == songTimer_184_guess) {
            CXRect rect = ((Handler_guess*)songTimer_184_guess)->GetScreenRect_guess();
            int width = rect.right - rect.left;
            if (width != 0) {
                float fraction = (float)(*(int*)data - rect.left) / (float)width;
                if (g_manager_guess->processor_guess->GetState_guess() == 0) {
                    g_manager_guess->processor_guess->SetPosition_guess(
                        (int)(g_manager_guess->processor_guess->GetTrackLength_guess() * fraction));
                    g_manager_guess->processor_guess->Play_guess();
                    g_manager_guess->processor_guess->Pause_guess();
                } else {
                    g_manager_guess->processor_guess->SetPosition_guess(
                        (int)(g_manager_guess->processor_guess->GetTrackLength_guess() * fraction));
                }
            }
        }
    } else if (message == 0xe) {
        if (sender == volume_18c_guess) {
            g_manager_guess->processor_guess->SetVolume_guess(((CSliderWnd_guess*)volume_18c_guess)->GetValue_guess() * 0.05);
        }
    } else if (message == 0x22) {
        flag_039d_guess = 0;
        UpdateButtons_guess();
        if (*(char*)data == 1) {
            if (mode_190_guess == 0) {
                char buffer[256];
                char number[16];
                int count = g_filePicker_guess->HasSelection_guess();
                int total = 0;
                for (int index = 0; index < count; ++index) {
                    PathStr_guess name = g_filePicker_guess->GetName_guess(index);
                    int pos;
                    if (!name.Find_guess('.', &pos)) {
                        // No extension: ".*" is appended.
                        name += EQ_ARRAY(char, 0x006591D8);
                    }
                    int added = g_manager_guess->processor_guess->SetText_guess(name);
                    if (added == 0) {
                        FormatString_guess(buffer, 0x1d75, name, 0, 0, 0, 0, 0, 0, 0, 0);
                        pEverQuest->dsp_chat(buffer);
                    } else {
                        if (added > 1) {
                            sprintf(number, "%d", added);
                            FormatString_guess(buffer, 0xc76, name, number, 0, 0, 0, 0, 0, 0, 0);
                            pEverQuest->dsp_chat(buffer);
                        }
                        if (added > 0) {
                            PathStr_guess extension = name.Right_guess(4);
                            if (extension.GetChar_guess(0) == '.') {
                                extension.Delete_guess(0, 1);
                                // An .m3u becomes the remembered playlist.
                                if (CompareNoCase_guess(extension, EQ_ARRAY(char, 0x006591D4)) == 0) {
                                    strcpy(text_19c_guess, name);
                                    Slot71_guess();
                                }
                            }
                        }
                    }
                    total += added;
                }
                sprintf(number, "%d", total);
                FormatString_guess(buffer, 0xc77, number, 0, 0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(buffer);
                UpdateSongList_guess();
            } else if (mode_190_guess == 1) {
                CXStr result;
                PathStr_guess name = g_filePicker_guess->GetName_guess(0);
                int pos;
                if (name.FindLast_guess('.', &pos)) {
                    name.Delete_guess(pos, 0xffff);
                }
                result = Join_guess(name, ".m3u");
                g_manager_guess->processor_guess->Save_guess(result);
                strcpy(text_19c_guess, result);
                Slot71_guess();
                UpdateSongList_guess();
            }
        }
        return 0;
    } else if (message == 10) {
        SaveIni_guess();
        return 0;
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

struct StmlHolder_guess {
    char pad_000_guess[0x15c];
    CStmlWnd* stmlWnd_15c_guess;
    CXStr text_160_guess;

    bool AboutToShow_guess();
};

// Shows the stored STML text (+0x160).
// FUNCTION: TITANIUM 0x0053A84A
bool StmlHolder_guess::AboutToShow_guess() {
    if (stmlWnd_15c_guess != 0) {
        stmlWnd_15c_guess->SetSTMLText(text_160_guess, true, 0);
    }
    return true;
}

