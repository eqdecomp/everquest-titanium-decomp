// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 63: a hint from compare/tumap.py.
// Client options and per-character settings files. Global options live in eqclient.ini [Options]/[Defaults]
// (defaults.ini supplies the fallback for each read); per-character data (hotbuttons, socials, loadouts,
// abilities) goes to the character ini. The Save* functions write only when 0x923798 is set or the game state
// allows it (0x923788 set, 0x923D7A and 0x923D7B clear), and most write only entries marked changed.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include <windows.h>

struct NumberText_guess {
    void WriteCharIniInt_guess(int value, int first, int second);
    void FormatIfOne(char value, int first, int second);
    void WriteCharIniString_guess(int first, int second, int third);
};

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);
// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();
// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(int first, int second, char* text, int value);
// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(int first, int second, char* source,
    char* destination, int size, const char* path);
// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

struct IniConfig_guess {
    void SaveCamera_guess();
    void WriteInt_guess(int value, int first, int second);
    void WriteIntIfOne_guess(char value, int first, int second);
    void WriteFloat_guess(float value, int first, int second);
    void WriteClientIniString_guess(int first, int second, int third);
    int ReadClientIniInt_guess(int first, int second, int third);
    float ReadFloat_guess(int first, int second, float defaultValue);
    char* ReadDefaults_guess(int first, int second, char* third, char* fourth,
        int fifth);
    char* ReadDefaults_guess(int first, int second, char* third, char* fourth,
        int fifth, char sixth);
    int UpdateDefaults_guess(int first, int second, int third, char fourth);
    char ReadFlag_guess(int first, int second, unsigned char third, char fourth);
    char ReadFlag_guess(int first, int second, unsigned char third);
    void WriteChannels_guess(int channel);
    void LoadChannels_guess();
    void loadOptions_guess();
    void saveOptions_guess();
};

struct ChannelTable_guess {
    // EXTERNAL: TITANIUM 0x0060CB00 ChannelTable_guess::GetName_guess
    char* GetName_guess(int index);
    // EXTERNAL: TITANIUM 0x0060CA70 ChannelTable_guess::GetValue_guess
    int GetValue_guess(int index);
    // EXTERNAL: TITANIUM 0x0060CB20 ChannelTable_guess::GetDefault_guess
    int GetDefault_guess(int index);
    // EXTERNAL: TITANIUM 0x0060CAC0 ChannelTable_guess::SetValue_guess
    void SetValue_guess(int index, int value);
};

#define g_channelTable_guess EQ_GLOBAL(ChannelTable_guess, 0x009248E0)

struct EffectData_guess {
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int value5;
    char flag;
};

struct EffectObject_guess {
    virtual char Slot00_guess();
    virtual char Slot01_guess();
    virtual char Slot02_guess();
    virtual char Slot03_guess();
    virtual char Slot04_guess();
    virtual char Slot05_guess();
    virtual char Slot06_guess();
    virtual char Slot07_guess();
    virtual char Slot08_guess();
    virtual char Slot09_guess();
    virtual char Slot10_guess();
    virtual char GetFlag_guess();
    char pad_04[0x24];
    int value0;
    int value1;
    int value2;
    int value3;
    int value4;
    int pad_3c;
    int value5;
    void CopyFrom(EffectData_guess* data);
    void CopyTo(EffectData_guess* data);
};

struct Camera_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual float GetDirHeading_guess();
    virtual void Slot10_guess();
    virtual char GetChange_guess();
    int pad_04[9];
    float heading_guess;   // 0x28
    int pad_2c;
    float pitch_guess;     // 0x30
    float distance_guess;  // 0x34
    int pad_38;
    int pad_3c;
    float zoom_guess;      // 0x40
};

#define g_camera1_guess EQ_GLOBAL(Camera_guess*, 0x00925508)
#define g_camera2_guess EQ_GLOBAL(Camera_guess*, 0x0092550c)

#define g_camera1Change_guess EQ_GLOBAL(unsigned char, 0x00924A90)
#define g_camera1Distance_guess EQ_GLOBAL(float, 0x00924A78)
#define g_camera1DirHeading_guess EQ_GLOBAL(float, 0x00924A7C)
#define g_camera1Height_guess EQ_GLOBAL(float, 0x00924A80)
#define g_camera1Heading_guess EQ_GLOBAL(float, 0x00924A84)
#define g_camera1Pitch_guess EQ_GLOBAL(float, 0x00924A88)
#define g_camera1Zoom_guess EQ_GLOBAL(float, 0x00924A8C)

#define g_camera2Change_guess EQ_GLOBAL(unsigned char, 0x00924AAC)
#define g_camera2Distance_guess EQ_GLOBAL(float, 0x00924A94)
#define g_camera2DirHeading_guess EQ_GLOBAL(float, 0x00924A98)
#define g_camera2Height_guess EQ_GLOBAL(float, 0x00924A9C)
#define g_camera2Heading_guess EQ_GLOBAL(float, 0x00924AA0)
#define g_camera2Pitch_guess EQ_GLOBAL(float, 0x00924AA4)
#define g_camera2Zoom_guess EQ_GLOBAL(float, 0x00924AA8)

// Language ids 1-3 and 6 (probably the double-byte languages): social names may then be 15 bytes, not 8.
// FUNCTION: TITANIUM 0x004AE49C
char __cdecl IsDoubleByteLanguage_guess(int value) {
    if (value > 0 && (value <= 3 || value == 6)) {
        return 1;
    }
    return 0;
}

// Camera settings from the ini block into a camera; the field order differs between the two.
// FUNCTION: TITANIUM 0x004AE4B4
void EffectObject_guess::CopyFrom(EffectData_guess* data) {
    value3 = data->value0;
    value4 = data->value1;
    value0 = data->value3;
    value2 = data->value4;
    value1 = data->value2;
    value5 = data->value5;
}

// Copies a camera's live values into its saved block (camera 1 at 0x00924A78, camera 2 at 0x00924A94):
// distance (+0x34), direction heading (+0x38), height (+0x2C), heading (+0x28), pitch (+0x30), zoom
// (+0x40) and the slot 11 flag. 0x004AE4B4 is the reverse.
// FUNCTION: TITANIUM 0x004AE4DE
void EffectObject_guess::CopyTo(EffectData_guess* data) {
    data->flag = GetFlag_guess();
    data->value0 = value3;
    data->value1 = value4;
    data->value3 = value0;
    data->value4 = value2;
    data->value2 = value1;
    data->value5 = value5;
}

// Writes `value` as a decimal integer to eqclient.ini, section `first`, key `second`.
// FUNCTION: TITANIUM 0x004AE514
void IniConfig_guess::WriteInt_guess(int value, int first, int second) {
    char buffer[512];
    _sprintf_guess(buffer, "%d", value);
    FUN_0060beb0_guess(first, second, buffer, (int)".\\eqclient.ini");
}

// Writes a flag to eqclient.ini as 1 when `value` is exactly 1, else 0.
// FUNCTION: TITANIUM 0x004AE5AF
void IniConfig_guess::WriteIntIfOne_guess(char value, int first, int second) {
    if (value == 1) {
        WriteInt_guess(1, first, second);
    } else {
        WriteInt_guess(0, first, second);
    }
}

// Writes `value` as a float ("%f") to eqclient.ini, section `first`, key `second`.
// FUNCTION: TITANIUM 0x004AE55F
void IniConfig_guess::WriteFloat_guess(float value, int first, int second) {
    char buffer[512];
    _sprintf_guess(buffer, "%f", value);
    FUN_0060beb0_guess(first, second, buffer, (int)".\\eqclient.ini");
}

// Writes a string value to eqclient.ini.
// FUNCTION: TITANIUM 0x004AE5CD
void IniConfig_guess::WriteClientIniString_guess(int first, int second, int third) {
    FUN_0060beb0_guess(second, third, (char*)first, (int)".\\eqclient.ini");
}

// String setting: eqclient.ini, falling back to defaults.ini.
// FUNCTION: TITANIUM 0x004AE5E9
char* IniConfig_guess::ReadDefaults_guess(int first, int second, char* third,
    char* fourth, int fifth) {
    char buffer[8192];
    FUN_0060be50_guess(first, second, third, buffer, 0x2000,
        ".\\defaults.ini");
    FUN_0060be50_guess(first, second, buffer, fourth, fifth,
        ".\\eqclient.ini");
    return fourth;
}

// EXTERNAL: TITANIUM 0x0060BE20 FUN_0060be20_guess
int __cdecl FUN_0060be20_guess(int first, int second, int third, const char* path);

// Integer setting: eqclient.ini, falling back to defaults.ini.
// FUNCTION: TITANIUM 0x004AE64C
int IniConfig_guess::ReadClientIniInt_guess(int first, int second, int third) {
    int value = FUN_0060be20_guess(first, second, third, ".\\defaults.ini");
    return FUN_0060be20_guess(first, second, value, ".\\eqclient.ini");
}

// EXTERNAL: TITANIUM 0x00610837 _sscanf_guess
int __cdecl _sscanf_guess(const char* source, const char* format, ...);

// Float option: `defaultValue` is the fallback for .\defaults.ini, whose value is in turn the fallback for
// .\eqclient.ini (both read through 0x0060BE50, which takes GetPrivateProfileString's arguments).
// FUNCTION: TITANIUM 0x004AE67A
float IniConfig_guess::ReadFloat_guess(int first, int second, float defaultValue) {
    char text[512];
    char defaults[512];
    char client[512];
    float value = defaultValue;
    _sprintf_guess(text, "%f", value);
    FUN_0060be50_guess(first, second, text, defaults, 0x1ff,
        ".\\defaults.ini");
    FUN_0060be50_guess(first, second, defaults, client, 0x1ff,
        ".\\eqclient.ini");
    _sscanf_guess(client, "%f", &value);
    return value;
}

// Flag setting: false when the value starts with 'F', 'f' or '0'.
// FUNCTION: TITANIUM 0x004AE721
char IniConfig_guess::ReadFlag_guess(int first, int second, unsigned char third) {
    char value[512];
    char text[32];
    _sprintf_guess(text, "%d", third);
    FUN_0060be50_guess(first, second, text, value, 0x1ff, ".\\defaults.ini");
    FUN_0060e450_guess(text, value);
    FUN_0060be50_guess(first, second, text, value, 0x1ff, ".\\eqclient.ini");
    if (value[0] == 'F' || value[0] == 'f' || value[0] == '0') {
        return 0;
    }
    return 1;
}

// Deletes a key from eqclient.ini (null value).
// FUNCTION: TITANIUM 0x004AE7C4
void __stdcall DeleteClientIniKey_guess(int first, int second) {
    FUN_0060beb0_guess(first, second, 0, (int)".\\eqclient.ini");
}

// Writes an integer to the character ini.
// FUNCTION: TITANIUM 0x004AE7DE
void NumberText_guess::WriteCharIniInt_guess(int value, int first, int second) {
    char buffer[512];
    _sprintf_guess(buffer, "%d", value);
    int result = NewUIINI();
    FUN_0060beb0_guess(first, second, buffer, result);
}

// Writes a flag to the character ini (0x004AE7DE) as 1 when `value` is exactly 1, else 0.
// FUNCTION: TITANIUM 0x004AE82A
void NumberText_guess::FormatIfOne(char value, int first, int second) {
    if (value == 1) {
        WriteCharIniInt_guess(1, first, second);
    } else {
        WriteCharIniInt_guess(0, first, second);
    }
}

// Writes a string to the character ini.
// FUNCTION: TITANIUM 0x004AE848
void NumberText_guess::WriteCharIniString_guess(int first, int second, int third) {
    int value = NewUIINI();
    FUN_0060beb0_guess(second, third, (char*)first, value);
}

// String setting from defaults.ini, overridden by the character ini when `sixth` is set.
// FUNCTION: TITANIUM 0x004AE865
char* IniConfig_guess::ReadDefaults_guess(int first, int second, char* third,
    char* fourth, int fifth, char sixth) {
    char buffer[8192];
    FUN_0060be50_guess(first, second, third, fourth, fifth, ".\\defaults.ini");
    if (sixth != 0) {
        FUN_0060e450_guess(buffer, fourth);
        int path = NewUIINI();
        FUN_0060be50_guess(first, second, buffer, fourth, fifth,
            (const char*)path);
    }
    return fourth;
}

// Integer setting from defaults.ini, overridden by the character ini when `fourth` is set.
// FUNCTION: TITANIUM 0x004AE8D9
int IniConfig_guess::UpdateDefaults_guess(int first, int second, int third,
    char fourth) {
    int value = FUN_0060be20_guess(first, second, third, ".\\defaults.ini");
    if (fourth != 0) {
        int path = NewUIINI();
        value = FUN_0060be20_guess(first, second, value, (const char*)path);
    }
    return value;
}

// Flag setting from defaults.ini, overridden by the character ini when `fourth` is set.
// FUNCTION: TITANIUM 0x004AE919
char IniConfig_guess::ReadFlag_guess(int first, int second, unsigned char third,
    char fourth) {
    char value[512];
    char text[32];
    _sprintf_guess(text, "%d", third);
    FUN_0060be50_guess(first, second, text, value, 0x1ff, ".\\defaults.ini");
    if (fourth != 0) {
        FUN_0060e450_guess(text, value);
        int path = NewUIINI();
        FUN_0060be50_guess(first, second, text, value, 0x1ff,
            (const char*)path);
    }
    if (value[0] == 'F' || value[0] == 'f' || value[0] == '0') {
        return 0;
    }
    return 1;
}

// Copies both cameras into their globals and writes Camera1-*/Camera2-* to [Options].
// FUNCTION: TITANIUM 0x004AE9C6
void IniConfig_guess::SaveCamera_guess() {
    char section[128];
    FUN_0060e450_guess(section, "Options");
    g_camera1Change_guess = g_camera1_guess->GetChange_guess();
    g_camera1Distance_guess = g_camera1_guess->distance_guess;
    g_camera1DirHeading_guess = g_camera1_guess->GetDirHeading_guess();
    g_camera1Heading_guess = g_camera1_guess->heading_guess;
    g_camera1Pitch_guess = g_camera1_guess->pitch_guess;
    g_camera1Zoom_guess = g_camera1_guess->zoom_guess;
    g_camera2Change_guess = g_camera2_guess->GetChange_guess();
    g_camera2Distance_guess = g_camera2_guess->distance_guess;
    g_camera2DirHeading_guess = g_camera2_guess->GetDirHeading_guess();
    g_camera2Heading_guess = g_camera2_guess->heading_guess;
    g_camera2Pitch_guess = g_camera2_guess->pitch_guess;
    g_camera2Zoom_guess = g_camera2_guess->zoom_guess;
    WriteFloat_guess(g_camera1Distance_guess, (int)section, (int)"Camera1-Distance");
    WriteFloat_guess(g_camera1DirHeading_guess, (int)section, (int)"Camera1-DirHeading");
    WriteFloat_guess(g_camera1Heading_guess, (int)section, (int)"Camera1-Heading");
    WriteFloat_guess(g_camera1Pitch_guess, (int)section, (int)"Camera1-Pitch");
    WriteFloat_guess(g_camera1Height_guess, (int)section, (int)"Camera1-Height");
    WriteFloat_guess(g_camera1Zoom_guess, (int)section, (int)"Camera1-Zoom");
    WriteInt_guess(g_camera1Change_guess, (int)section, (int)"Camera1-Change");
    WriteFloat_guess(g_camera2Distance_guess, (int)section, (int)"Camera2-Distance");
    WriteFloat_guess(g_camera2DirHeading_guess, (int)section, (int)"Camera2-DirHeading");
    WriteFloat_guess(g_camera2Heading_guess, (int)section, (int)"Camera2-Heading");
    WriteFloat_guess(g_camera2Pitch_guess, (int)section, (int)"Camera2-Pitch");
    WriteFloat_guess(g_camera2Height_guess, (int)section, (int)"Camera2-Height");
    WriteFloat_guess(g_camera2Zoom_guess, (int)section, (int)"Camera2-Zoom");
    WriteInt_guess(g_camera2Change_guess, (int)section, (int)"Camera2-Change");
}

// EXTERNAL: TITANIUM 0x0060BF60 FUN_0060bf60_guess
void __cdecl FUN_0060bf60_guess(const char* section, const char* key, const char* value);

// Writes one chat channel colour setting (0-27), or all 28 for -1.
// FUNCTION: TITANIUM 0x004AEC1A
void IniConfig_guess::WriteChannels_guess(int channel) {
    char section[128];
    FUN_0060e450_guess(section, "Options");
    int first = 0;
    int last = 0x1b;
    if (channel != -1 && channel >= 0 && channel < 0x1c) {
        last = channel;
        first = channel;
    }
    for (int i = first; i <= last; ++i) {
        WriteInt_guess(g_channelTable_guess.GetValue_guess(i), (int)section,
            (int)g_channelTable_guess.GetName_guess(i));
    }
}

// Loads the 28 named values of the option table 0x009248E0 (chat filters; 7-9 filter spell text) from
// [Options]: the defaults.ini value, overridden by eqclient.ini (0x004AE64C). 0x004AEC1A writes them back.
// FUNCTION: TITANIUM 0x004AECA2
void IniConfig_guess::LoadChannels_guess() {
    char section[128];
    FUN_0060e450_guess(section, "Options");
    for (int i = 0; i < 0x1c; ++i) {
        g_channelTable_guess.SetValue_guess(i,
            ReadClientIniInt_guess((int)section, (int)g_channelTable_guess.GetName_guess(i),
                g_channelTable_guess.GetDefault_guess(i)));
    }
}

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(CXStr* destination, const char* format, ...);
// EXTERNAL: TITANIUM 0x0060E460 FUN_0060e460_guess
void __cdecl FUN_0060e460_guess(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x0060E887 _fopen_guess
void* __cdecl _fopen_guess(const char* filename, const char* mode);
// EXTERNAL: TITANIUM 0x0061030F _fseek_guess
int __cdecl _fseek_guess(void* file, long offset, int origin);
// EXTERNAL: TITANIUM 0x006101BA _fwrite_guess
unsigned int __cdecl _fwrite_guess(const void* buffer, unsigned int size,
    unsigned int count, void* file);
// EXTERNAL: TITANIUM 0x0060E790 _fclose_guess
int __cdecl _fclose_guess(void* file);

// Writes every option (privacy, mouse, sound, particles, the 20 ignore and 20 friend names...), then dumps
// the 0xB80-byte option block to eqOptions1.opt with two fields (0x924970,
// 0x9249B0) set to -42. The client never reads the file back (LoadOptions reads eqclient.ini).
// FUNCTION: TITANIUM 0x004AED0E
// @early-stop: budget, diff ndiff=6
void IniConfig_guess::saveOptions_guess() {
    char section[100];
    char filename[128];
    char friendName[128];
    char ignoreName[128];

    // Saved only with 0x923788 set and the flags 0x923D7B and 0x923D7A clear.
    if (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
        EQ_GLOBAL(int, 0x00923788) != 0 &&
        EQ_GLOBAL(char, 0x00923D7A) == 0) {
        FUN_0060e450_guess(section, "Options");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924954), (int)section,
            (int)"Anonymous");
        WriteInt_guess(EQ_GLOBAL(int, 0x0092495C), (int)section,
            (int)"Trade");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924960), (int)section,
            (int)"GuildInvites");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924964), (int)section,
            (int)EQ_ARRAY(char, 0x0064AC48));
        WriteInt_guess(EQ_GLOBAL(int, 0x00924968), (int)section,
            (int)"ParticleDensity");
        WriteInt_guess(EQ_GLOBAL(int, 0x0092496C), (int)section,
            (int)EQ_ARRAY(char, 0x0064AC34));
        WriteInt_guess(EQ_GLOBAL(int, 0x00924974), (int)section,
            (int)"SameResolution");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924978), (int)section,
            (int)"PCNames");
        WriteInt_guess(EQ_GLOBAL(int, 0x0092497C), (int)section,
            (int)"NPCNames");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924988), (int)section,
            (int)"Realism");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924990), (int)section,
            (int)"MouseSensitivity");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924994), (int)section,
            (int)"InverseMouse");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924998), (int)section,
            (int)"LookSpring");
        WriteInt_guess(EQ_GLOBAL(int, 0x0092499C), (int)section,
            (int)"MouseActive");
        WriteInt_guess(EQ_GLOBAL(int, 0x009249A0), (int)section,
            (int)"Destroy");
        WriteInt_guess(EQ_GLOBAL(int, 0x009249AC), (int)section,
            (int)"ClipPlane");
        WriteInt_guess(EQ_GLOBAL(int, 0x009254B0), (int)section,
            (int)"AANoConfirm");
        WriteInt_guess(EQ_GLOBAL(int, 0x009254B4), (int)section,
            (int)"pointMerchantNoConfirm");
        WriteInt_guess(EQ_GLOBAL(int, 0x009254BC), (int)section,
            (int)"MouseWheelZoom");
        WriteIntIfOne_guess(EQ_GLOBAL(unsigned char, 0x00923878), (int)section,
            (int)"MouseRightHanded");
        WriteInt_guess(EQ_GLOBAL(int, 0x009254CC), (int)section,
            (int)"LoadScreenMode");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924980), (int)"Defaults",
            (int)"Music");
        WriteFloat_guess(EQ_GLOBAL(float, 0x00924950), (int)"Defaults",
            (int)"Gamma");
        WriteInt_guess(EQ_GLOBAL(int, 0x00924984), (int)"Defaults",
            (int)"SoundVolume");
        WriteChannels_guess(-1);

        int index;
        int entry;
        index = 0;
        entry = (int)EQ_ARRAY(char, 0x00924AB0);
        do {
            // Ignore00-19 and Friend00-19: the 64-byte names at 0x924AB0 and 0x924FB0 inside the option
            // block.
            _sprintf_guess(ignoreName, "Ignore%02d", index);
            FUN_0060beb0_guess((int)section, (int)ignoreName, (char*)entry,
                (int)".\\eqclient.ini");
            entry += 64;
            ++index;
        } while (entry < (int)EQ_ARRAY(char, 0x00924FB0));
        index = 0;
        entry = (int)EQ_ARRAY(char, 0x00924FB0);
        do {
            _sprintf_guess(friendName, "Friend%02d", index);
            FUN_0060beb0_guess((int)section, (int)friendName, (char*)entry,
                (int)".\\eqclient.ini");
            entry += 64;
            ++index;
        } while (entry < (int)EQ_ARRAY(char, 0x009254B0));
        WriteInt_guess(1, (int)section, (int)"IgnoreFile1");

        CXStr value;
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985810));
        // Particle settings for spells, the environment and actors, written as text floats.
        FUN_0060beb0_guess((int)"Defaults", (int)"SpellParticleDensity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985814));
        FUN_0060beb0_guess((int)"Defaults", (int)"SpellParticleOpacity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985818));
        FUN_0060beb0_guess((int)"Defaults", (int)"SpellParticleNearClipPlane",
            (char*)value, (int)".\\eqclient.ini");
        WriteInt_guess(EQ_GLOBAL(int, 0x0098581C), (int)"Defaults",
            (int)"SpellParticleCastFilter");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985820));
        FUN_0060beb0_guess((int)"Defaults", (int)"EnvironmentParticleDensity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985824));
        FUN_0060beb0_guess((int)"Defaults", (int)"EnvironmentParticleOpacity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985828));
        FUN_0060beb0_guess((int)"Defaults",
            (int)"EnvironmentParticleNearClipPlane", (char*)value,
            (int)".\\eqclient.ini");
        WriteInt_guess(EQ_GLOBAL(int, 0x0098582C), (int)"Defaults",
            (int)"EnvironmentParticleCastFilter");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985830));
        FUN_0060beb0_guess((int)"Defaults", (int)"ActorParticleDensity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985834));
        FUN_0060beb0_guess((int)"Defaults", (int)"ActorParticleOpacity",
            (char*)value, (int)".\\eqclient.ini");
        FUN_005738b0_guess(&value, "%f", EQ_GLOBAL(float, 0x00985838));
        FUN_0060beb0_guess((int)"Defaults", (int)"ActorParticleNearClipPlane",
            (char*)value, (int)".\\eqclient.ini");
        WriteInt_guess(EQ_GLOBAL(int, 0x0098583C), (int)"Defaults",
            (int)"ActorParticleCastFilter");

        FUN_0060e450_guess(filename, "eqOptions1");
        FUN_0060e460_guess(filename, ".opt");
        void* file = _fopen_guess(filename, "wb");
        if (file != 0) {
            SaveCamera_guess();
            EQ_GLOBAL(int, 0x009249B0) = -42;
            EQ_GLOBAL(int, 0x00924970) = -42;
            _fseek_guess(file, 0, 0);
            _fwrite_guess(EQ_ARRAY(char, 0x00924950), 0xB80, 1, file);
            _fclose_guess(file);
        }
    }
}

// EXTERNAL: TITANIUM 0x00612662 FUN_00612662_guess
int __cdecl FUN_00612662_guess(const char* path);

struct SoundManager_guess {
    // EXTERNAL: TITANIUM 0x0044B050 SoundManager_guess::SetEnvSounds_guess
    void SetEnvSounds_guess(bool off);
    // EXTERNAL: TITANIUM 0x0044A776 SoundManager_guess::SetMusicVolume_guess
    void SetMusicVolume_guess(float volume);
    // EXTERNAL: TITANIUM 0x0044A753 SoundManager_guess::SetWaveVolume_guess
    void SetWaveVolume_guess(float volume);
    // EXTERNAL: TITANIUM 0x0044A71F SoundManager_guess::SetRealism_guess
    void SetRealism_guess(float volume);
    // EXTERNAL: TITANIUM 0x0044A742 SoundManager_guess::SetMixAhead_guess
    void SetMixAhead_guess(int value);
};

struct ParticleManager_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess();
    virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot20_guess();
    virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess();
    virtual void Slot27_guess(); virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void SetEnvironmentDensity_guess(float value);  // 0x94
    virtual void SetEnvironmentOpacity_guess(float value);  // 0x98
    virtual void SetActorDensity_guess(float value);        // 0x9c
    virtual void SetActorOpacity_guess(float value);        // 0xa0
};

struct Display_guess {
    // EXTERNAL: TITANIUM 0x004372E6 Display_guess::DefaultCameras_guess
    void DefaultCameras_guess();
    // EXTERNAL: TITANIUM 0x004389FB Display_guess::SetPCloudDensity_guess
    void SetPCloudDensity_guess(int value);
    // EXTERNAL: TITANIUM 0x00439A93 Display_guess::SetPCNameSpriteState_guess
    void SetPCNameSpriteState_guess(int show);
    // EXTERNAL: TITANIUM 0x00439AC7 Display_guess::SetNPCNameSpriteState_guess
    void SetNPCNameSpriteState_guess(int show);
};

struct Setting_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess();
    virtual void Slot03_guess(); virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess();
    virtual void Slot15_guess(); virtual void Slot16_guess();
    virtual void SetInt_guess(int value);  // 0x44
};

struct SettingsManager_guess {
    // EXTERNAL: TITANIUM 0x00577110 SettingsManager_guess::Find_guess
    Setting_guess* Find_guess(const char* name);
};

// EXTERNAL: TITANIUM 0x004C398E GetSettingsManager_guess
SettingsManager_guess* __cdecl GetSettingsManager_guess();
// EXTERNAL: TITANIUM 0x0046C7A7 setLOD_guess
void __cdecl setLOD_guess(int value);

typedef char Name64_guess[64];

#define g_soundManager_guess EQ_GLOBAL(SoundManager_guess*, 0x00851390)
#define g_particleManager_guess EQ_GLOBAL(ParticleManager_guess*, 0x0099E36C)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)
#define g_defaultsConfig_guess EQ_GLOBAL(IniConfig_guess*, 0x00988DF0)
#define g_camera1Object_guess EQ_GLOBAL(EffectObject_guess*, 0x00925508)
#define g_camera2Object_guess EQ_GLOBAL(EffectObject_guess*, 0x0092550C)
#define g_camera1Data_guess EQ_GLOBAL(EffectData_guess, 0x00924A78)
#define g_camera2Data_guess EQ_GLOBAL(EffectData_guess, 0x00924A94)
#define g_ignoreList_guess EQ_ARRAY(Name64_guess, 0x00924AB0)
#define g_friendList_guess EQ_ARRAY(Name64_guess, 0x00924FB0)

#define CLAMP_guess(v, lo, hi) \
    if (!((lo) > (v)) && (hi) < (v)) (v) = (hi); \
    else if ((lo) > (v)) (v) = (lo)

// Reads every option and applies it, clamping out-of-range values: particle densities and opacities 0-1,
// clip planes 1-8, gamma 0-20, mouse sensitivity 1-8. Deletes the old eqOptions.opt. A camera zoom outside
// 0-500 resets both cameras. Sky cubemap size is clamped to 5-9 (ini value + 5).
// FUNCTION: TITANIUM 0x004AF32C
// @early-stop: budget, structural ndiff=66
void IniConfig_guess::loadOptions_guess() {
    char optFile[128];
    char key[128];
    char text[64];
    char section[128];
    float value;
    // [Defaults] first: gamma, volumes, mipmapping, environment sounds and the spell, environment and actor
    // particle settings, each clamped to its range.
    FUN_0060e450_guess(optFile, "eqOptions.opt");
    FUN_00612662_guess(optFile);
    EQ_GLOBAL(float, 0x00924950) = ReadFloat_guess((int)"Defaults", (int)"Gamma", 11.0f);
    EQ_GLOBAL(int, 0x00924984) = ReadClientIniInt_guess((int)"Defaults", (int)"SoundVolume", 10);
    EQ_GLOBAL(int, 0x00924980) = ReadClientIniInt_guess((int)"Defaults", (int)"Music", 10);
    EQ_GLOBAL(int, 0x009249A4) = (unsigned char)ReadFlag_guess((int)"Defaults", (int)"MipMapping", 1);
    EQ_GLOBAL(char, 0x009254EC) = ReadFlag_guess((int)"Defaults", (int)"EnvSounds", 1);
    g_soundManager_guess->SetEnvSounds_guess(EQ_GLOBAL(char, 0x009254EC) == 0);

    value = ReadFloat_guess((int)"Defaults", (int)"SpellParticleDensity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985810) = value;
    value = ReadFloat_guess((int)"Defaults", (int)"SpellParticleOpacity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985814) = value;
    value = ReadFloat_guess((int)"Defaults", (int)"SpellParticleNearClipPlane", 2.0f);
    CLAMP_guess(value, 1.0f, 8.0f);
    EQ_GLOBAL(float, 0x00985818) = value;
    EQ_GLOBAL(int, 0x0098581C) = ReadClientIniInt_guess((int)"Defaults", (int)"SpellParticleCastFilter", 0x18);

    value = ReadFloat_guess((int)"Defaults", (int)"EnvironmentParticleDensity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985820) = value;
    g_particleManager_guess->SetEnvironmentDensity_guess(value);
    value = ReadFloat_guess((int)"Defaults", (int)"EnvironmentParticleOpacity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985824) = value;
    g_particleManager_guess->SetEnvironmentOpacity_guess(value);
    value = ReadFloat_guess((int)"Defaults", (int)"EnvironmentParticleNearClipPlane", 2.0f);
    CLAMP_guess(value, 1.0f, 8.0f);
    EQ_GLOBAL(float, 0x00985828) = value;
    EQ_GLOBAL(int, 0x0098582C) = ReadClientIniInt_guess((int)"Defaults", (int)"EnvironmentParticleCastFilter", 0x18);

    value = ReadFloat_guess((int)"Defaults", (int)"ActorParticleDensity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985830) = value;
    g_particleManager_guess->SetActorDensity_guess(value);
    value = ReadFloat_guess((int)"Defaults", (int)"ActorParticleOpacity", 1.0f);
    CLAMP_guess(value, 0.0f, 1.0f);
    EQ_GLOBAL(float, 0x00985834) = value;
    g_particleManager_guess->SetActorOpacity_guess(value);
    value = ReadFloat_guess((int)"Defaults", (int)"ActorParticleNearClipPlane", 2.0f);
    CLAMP_guess(value, 1.0f, 8.0f);
    EQ_GLOBAL(float, 0x00985838) = value;
    EQ_GLOBAL(int, 0x0098583C) = ReadClientIniInt_guess((int)"Defaults", (int)"ActorParticleCastFilter", 0x18);

    g_display_guess->DefaultCameras_guess();
    // [Options]: IgnoreFile1 is read and then written back as 1, then the two camera setups.
    FUN_0060e450_guess(section, "Options");
    ReadClientIniInt_guess((int)"Options", (int)"IgnoreFile1", 0);
    WriteInt_guess(1, (int)"Options", (int)"IgnoreFile1");

    g_camera1Heading_guess = ReadFloat_guess((int)section, (int)"Camera1-Heading", value);
    g_camera1DirHeading_guess = ReadFloat_guess((int)section, (int)"Camera1-DirHeading", value);
    g_camera1Pitch_guess = ReadFloat_guess((int)section, (int)"Camera1-Pitch", value);
    g_camera1Zoom_guess = ReadFloat_guess((int)section, (int)"Camera1-Zoom", value);
    g_camera1Distance_guess = ReadFloat_guess((int)section, (int)"Camera1-Distance", value);
    g_camera1Height_guess = ReadFloat_guess((int)section, (int)"Camera1-Height", value);
    g_camera1Change_guess = ReadClientIniInt_guess((int)section, (int)"Camera1-Change", 0);
    // As in the binary (stores at 0x004AF833-0x004AF893), the Camera2 keys load into the Camera1 globals
    // (0x00924A78-0x00924A8C) and overwrite them, while the save code (above) writes the Camera2 globals
    // (0x00924AA0..).
    g_camera1Heading_guess = ReadFloat_guess((int)section, (int)"Camera2-Heading", value);
    g_camera1DirHeading_guess = ReadFloat_guess((int)section, (int)"Camera2-DirHeading", value);
    g_camera1Pitch_guess = ReadFloat_guess((int)section, (int)"Camera2-Pitch", value);
    g_camera1Zoom_guess = ReadFloat_guess((int)section, (int)"Camera2-Zoom", value);
    g_camera1Distance_guess = ReadFloat_guess((int)section, (int)"Camera2-Distance", value);
    g_camera1Height_guess = ReadFloat_guess((int)section, (int)"Camera2-Height", value);
    g_camera1Change_guess = ReadClientIniInt_guess((int)section, (int)"Camera2-Change", 0);

    // Social and interface switches: anonymous, trade filter (2), guild invites, names, mouse, clip plane...
    EQ_GLOBAL(int, 0x00924954) = ReadClientIniInt_guess((int)section, (int)"Anonymous", 0);
    EQ_GLOBAL(int, 0x0092495C) = ReadClientIniInt_guess((int)section, (int)"Trade", 2);
    EQ_GLOBAL(int, 0x00924960) = ReadClientIniInt_guess((int)section, (int)"GuildInvites", 1);
    EQ_GLOBAL(int, 0x00924964) = ReadClientIniInt_guess((int)section, (int)EQ_ARRAY(char, 0x0064AC48), 1);
    EQ_GLOBAL(int, 0x00924968) = ReadClientIniInt_guess((int)section, (int)"ParticleDensity", 3);
    EQ_GLOBAL(int, 0x0092496C) = ReadClientIniInt_guess((int)section, (int)EQ_ARRAY(char, 0x0064AC34), 1);
    EQ_GLOBAL(int, 0x00924974) = ReadClientIniInt_guess((int)section, (int)"SameResolution", 1);
    EQ_GLOBAL(int, 0x00924978) = ReadClientIniInt_guess((int)section, (int)"PCNames", 1);
    EQ_GLOBAL(int, 0x0092497C) = ReadClientIniInt_guess((int)section, (int)"NPCNames", 1);
    EQ_GLOBAL(int, 0x00924988) = ReadClientIniInt_guess((int)section, (int)"Realism", 1);
    EQ_GLOBAL(int, 0x00924990) = ReadClientIniInt_guess((int)section, (int)"MouseSensitivity", 4);
    EQ_GLOBAL(int, 0x00924994) = ReadClientIniInt_guess((int)section, (int)"InverseMouse", 0);
    EQ_GLOBAL(int, 0x00924998) = ReadClientIniInt_guess((int)section, (int)"LookSpring", 0);
    EQ_GLOBAL(int, 0x0092499C) = ReadClientIniInt_guess((int)section, (int)"MouseActive", 1);
    EQ_GLOBAL(int, 0x009249A0) = ReadClientIniInt_guess((int)section, (int)"Destroy", 0);
    EQ_GLOBAL(int, 0x009249AC) = ReadClientIniInt_guess((int)section, (int)"ClipPlane", 0xf);
    EQ_GLOBAL(int, 0x009254B0) = ReadClientIniInt_guess((int)section, (int)"AANoConfirm", 0);
    EQ_GLOBAL(int, 0x009254B4) = ReadClientIniInt_guess((int)section, (int)"pointMerchantNoConfirm", 0);
    EQ_GLOBAL(int, 0x009254BC) = ReadClientIniInt_guess((int)section, (int)"MouseWheelZoom", 1);
    EQ_GLOBAL(char, 0x00923878) = ReadFlag_guess((int)section, (int)"MouseRightHanded", 1);
    EQ_GLOBAL(int, 0x009254C0) = (unsigned char)ReadFlag_guess((int)section, (int)"Show3dTargetIndicator", 1);
    EQ_GLOBAL(char, 0x009254EF) = g_defaultsConfig_guess->ReadFlag_guess((int)"Defaults", (int)"LeftClickTargetHelp", 1);
    EQ_GLOBAL(char, 0x009254F6) = g_defaultsConfig_guess->ReadFlag_guess((int)"Defaults", (int)"AllowAutoDuck", 1);
    EQ_GLOBAL(char, 0x009254F7) = g_defaultsConfig_guess->ReadFlag_guess((int)"Defaults", (int)"AllowAutoStand", 1);
    EQ_GLOBAL(char, 0x009254F8) = g_defaultsConfig_guess->ReadFlag_guess((int)"Defaults", (int)"AutojoinHelp", 1);
    EQ_GLOBAL(int, 0x009254C4) = ReadClientIniInt_guess((int)section, (int)"MaxFPS", 100);
    EQ_GLOBAL(int, 0x009254C8) = ReadClientIniInt_guess((int)section, (int)"LODBias", 10);
    int mode = ReadClientIniInt_guess((int)section, (int)"LoadScreenMode", 1);
    if (mode < 0) {
        mode = 0;
    }
    EQ_GLOBAL(int, 0x009254CC) = mode;
    if (mode > 0) {
        EQ_GLOBAL(int, 0x009254CC) = 1;
    }
    LoadChannels_guess();

    // The ignore and friend lists from eqclient.ini: Ignore00-Ignore19 and Friend00-Friend19, 63 characters
    // each.
    for (int i = 0; i < 20; ++i) {
        _sprintf_guess(key, "Ignore%02d", i);
        FUN_0060be50_guess((int)section, (int)key, "", text, 0x3f, ".\\eqclient.ini");
        text[0x3f] = 0;
        FUN_0060e450_guess(g_ignoreList_guess[i], text);
        _sprintf_guess(key, "Friend%02d", i);
        FUN_0060be50_guess((int)section, (int)key, "", text, 0x3f, ".\\eqclient.ini");
        text[0x3f] = 0;
        FUN_0060e450_guess(g_friendList_guess[i], text);
    }

    // Apply: volumes and realism are 0-20 steps turned into fractions; the rest is clamped and handed to the
    // display and sound objects.
    g_soundManager_guess->SetMusicVolume_guess(
        (float)(EQ_GLOBAL(int, 0x00924980) * 100 / 20) * 0.01f);
    g_soundManager_guess->SetWaveVolume_guess(
        (float)(EQ_GLOBAL(int, 0x00924984) * 100 / 20) * 0.01f);
    g_soundManager_guess->SetRealism_guess(
        (float)(EQ_GLOBAL(int, 0x00924988) * 100 / 20) * 0.01f);
    g_soundManager_guess->SetMixAhead_guess(EQ_GLOBAL(int, 0x009248DC));

    CLAMP_guess(EQ_GLOBAL(float, 0x00924950), 0.0f, 20.0f);
    CLAMP_guess(EQ_GLOBAL(int, 0x00924964), 0, 2);
    CLAMP_guess(EQ_GLOBAL(int, 0x00924968), 0, 3);
    CLAMP_guess(EQ_GLOBAL(int, 0x00924990), 1, 8);
    EQ_GLOBAL(char, 0x00923840) = (char)EQ_GLOBAL(int, 0x00924994);
    EQ_GLOBAL(char, 0x009237B8) = (char)EQ_GLOBAL(int, 0x0092499C);
    EQ_GLOBAL(int, 0x009237DC) = EQ_GLOBAL(int, 0x00924990);
    setLOD_guess(EQ_GLOBAL(int, 0x0092496C));
    g_display_guess->SetPCloudDensity_guess(EQ_GLOBAL(int, 0x00924968));
    if (EQ_GLOBAL(int, 0x00924978) == 0) {
        g_display_guess->SetPCNameSpriteState_guess(0);
    }
    if (EQ_GLOBAL(int, 0x0092497C) == 0) {
        g_display_guess->SetNPCNameSpriteState_guess(0);
    }

    if (g_camera1Zoom_guess <= 0.0f || g_camera1Zoom_guess >= 500.0f ||
        g_camera2Zoom_guess <= 0.0f || g_camera2Zoom_guess >= 500.0f) {
        g_display_guess->DefaultCameras_guess();
        g_camera1Object_guess->CopyTo(&g_camera1Data_guess);
        g_camera2Object_guess->CopyTo(&g_camera2Data_guess);
        SaveCamera_guess();
    } else {
        g_camera1Object_guess->CopyFrom(&g_camera1Data_guess);
        g_camera2Object_guess->CopyFrom(&g_camera2Data_guess);
    }

    EQ_GLOBAL(float, 0x009254D0) = ReadFloat_guess((int)section, (int)"FogScale", 1.0f);
    EQ_GLOBAL(int, 0x009254D4) = ReadClientIniInt_guess((int)section, (int)"VoiceRecognition", 0);
    EQ_GLOBAL(int, 0x009254D8) = ReadClientIniInt_guess((int)section, (int)"VRDelay", 0);
    EQ_GLOBAL(int, 0x009254DC) = ReadClientIniInt_guess((int)section, (int)"NoSafeDrop", 0);
    EQ_GLOBAL(int, 0x009254E0) = ReadClientIniInt_guess((int)section, (int)"LootNoDrop", 0);
    EQ_GLOBAL(int, 0x009254E4) = ReadClientIniInt_guess((int)section, (int)"ReverseSound", 0);
    if (EQ_GLOBAL(float, 0x009254D0) == 0.0f) {
        EQ_GLOBAL(int, 0x009249AC) = 5;
        EQ_GLOBAL(float, 0x009254D0) = 1.0f;
    }
    SettingsManager_guess* settings = GetSettingsManager_guess();
    settings->Find_guess("Graphics.Scene.SkyCubeUpdateInterval")->SetInt_guess(
        g_defaultsConfig_guess->ReadClientIniInt_guess((int)"Defaults", (int)"SkyUpdateInterval", 0));
    Setting_guess* setting = settings->Find_guess("Graphics.Scene.SkyCubeMapSizeNext");
    unsigned int size = g_defaultsConfig_guess->ReadClientIniInt_guess((int)"Defaults", (int)"SkyCubemapSize", 0) + 5;
    if (size > 8) {
        size = 9;
    }
    if (size < 6) {
        size = 5;
    }
    setting->SetInt_guess(size);
}

struct HBSet_guess {
    char name[0x19];
    char inuse;
    char active;
    int fileNum;
};

#define g_hbSets_guess EQ_ARRAY(HBSet_guess, 0x00984A84)

// HBLoadouts: HBSet<n>.inuse, .name and .fileNum for each changed hotbar loadout. It walks 100 entries
// while Load_guess reads only 10, so it runs past the 10 sets into whatever follows.
// FUNCTION: TITANIUM 0x004B010A
void SaveHotbuttonLoadouts_guess() {
    char value[256];
    char name[128];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        int index = 1;
        int remaining = 100;
        HBSet_guess* set = g_hbSets_guess;
        do {
            if (set->active == 1) {
                _sprintf_guess(name, "HBSet%d.inuse", index);
                _sprintf_guess(value, "%d", set->inuse != 0);
                FUN_0060bf60_guess("HBLoadouts", name, value);
                if (set->inuse != 0) {
                    _sprintf_guess(name, "HBSet%d.name", index);
                    FUN_0060bf60_guess("HBLoadouts", name, set->name);
                    _sprintf_guess(name, "HBSet%d.fileNum", index);
                    _sprintf_guess(value, "%d", set->fileNum);
                    FUN_0060bf60_guess("HBLoadouts", name, value);
                }
            }
            ++index;
            ++set;
            --remaining;
        } while (remaining != 0);
    }
}

struct SocialButtonState_guess {
    char active;
};

struct SocialPageFlags_guess {
    SocialButtonState_guess buttons[12];
};

// Socials: Page<p>Button<b>Name, Color and Line1-5 for each changed button (10 pages of 12); an empty social
// deletes its keys.
// FUNCTION: TITANIUM 0x004B03B1
// @early-stop: budget, structural ndiff=38
void SaveSocials_guess() {
    char colorText[256];
    char key[128];
    char buttonName[64];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        for (int page = 0; page < 10; ++page) {
            SocialButtonState_guess* active = EQ_ARRAY(SocialPageFlags_guess,
                0x0095D45C)[page].buttons;
            int button = 1;
            char* social = EQ_ARRAY(char, 0x0095D4D4) + page * 0x3ccc;
            int remaining = 12;
            do {
                if (active->active == 1) {
                    if (*social != 0) {
                        _sprintf_guess(buttonName, "Page%dButton%d", page + 1,
                            button);
                        _sprintf_guess(key, "%sName", buttonName);
                        FUN_0060bf60_guess("Socials", key, social);
                        _sprintf_guess(key, "%sColor", buttonName);
                        _sprintf_guess(colorText, "%d", (int)social[0x510]);
                        FUN_0060bf60_guess("Socials", key, colorText);
                        char* lineText = social + 0x10;
                        int line = 0;
                        do {
                            ++line;
                            _sprintf_guess(key, "%sLine%d", buttonName, line);
                            char* value = lineText;
                            if (*lineText == 0) {
                                value = 0;
                            }
                            FUN_0060bf60_guess("Socials", key, value);
                            lineText += 0x100;
                        } while (line < 5);
                    } else {
                        _sprintf_guess(buttonName, "Page%dButton%d", page + 1,
                            button);
                        _sprintf_guess(key, "%sName", buttonName);
                        FUN_0060bf60_guess("Socials", key, 0);
                        _sprintf_guess(key, "%sColor", buttonName);
                        FUN_0060bf60_guess("Socials", key, 0);
                        int line = 0;
                        do {
                            ++line;
                            _sprintf_guess(key, "%sLine%d", buttonName, line);
                            FUN_0060bf60_guess("Socials", key, 0);
                        } while (line < 5);
                    }
                    active->active = 0;
                }
                social += 0x511;
                ++button;
                ++active;
                --remaining;
            } while (remaining != 0);
        }
    }
}

// Abilities: Ability1-6.
// FUNCTION: TITANIUM 0x004B05D6
void SaveAbilities_guess() {
    char value[256];
    char name[128];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        for (int i = 0; i < 6; ++i) {
            _sprintf_guess(name, "Ability%d", i + 1);
            _sprintf_guess(value, "%d", EQ_ARRAY(int, 0x0095D424)[i]);
            FUN_0060bf60_guess("Abilities", name, value);
        }
    }
}

// CombatSkills: CombatSkill1-4.
// FUNCTION: TITANIUM 0x004B0668
void SaveCombatSkills_guess() {
    char value[256];
    char name[128];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        for (int i = 0; i < 4; ++i) {
            _sprintf_guess(name, "CombatSkill%d", i + 1);
            _sprintf_guess(value, "%d", EQ_ARRAY(int, 0x0095D414)[i]);
            FUN_0060bf60_guess("CombatSkills", name, value);
        }
    }
}

// CombatAbilities: CombatAbility1-8.
// FUNCTION: TITANIUM 0x004B06FA
void SaveCombatAbilities_guess() {
    char value[256];
    char name[128];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        for (int i = 0; i < 8; ++i) {
            _sprintf_guess(name, "CombatAbility%d", i + 1);
            _sprintf_guess(value, "%d", EQ_ARRAY(int, 0x0095D43C)[i]);
            FUN_0060bf60_guess("CombatAbilities", name, value);
        }
    }
}

// EXTERNAL: TITANIUM 0x0055955C GetCustomIniFilename_guess
int __cdecl GetCustomIniFilename_guess();

// The inspect text ([InspectText] Text); empty deletes the key.
// FUNCTION: TITANIUM 0x004B078C
void saveCustom_guess() {
    int zero = 0;
    if (EQ_GLOBAL(char, 0x00923798) != zero ||
        (EQ_GLOBAL(char, 0x00923D7B) == zero &&
         EQ_GLOBAL(int, 0x00923788) != zero &&
         EQ_GLOBAL(char, 0x00923D7A) == zero)) {
        GetCustomIniFilename_guess();
        if (EQ_GLOBAL(char, 0x00985708) != zero) {
            FUN_0060bf60_guess(EQ_ARRAY(char, 0x0064AEB4),
                EQ_ARRAY(char, 0x0064AEC0), EQ_ARRAY(char, 0x00985708));
        } else {
            FUN_0060bf60_guess(EQ_ARRAY(char, 0x0064AEB4),
                EQ_ARRAY(char, 0x0064AEC0), (char*)zero);
        }
    }
}

struct SpellLoadout_guess {
    int slots[9];
    char name[25];
    unsigned char inuse;
    unsigned char active;
    char pad;
};

#define g_spellLoadouts_guess EQ_ARRAY(SpellLoadout_guess, 0x00984804)

// EXTERNAL: TITANIUM 0x0060C030 FUN_0060c030_guess
int __cdecl FUN_0060c030_guess(const char* section, const char* key, int fallback);
// EXTERNAL: TITANIUM 0x0060BFA0 FUN_0060bfa0_guess
void __cdecl FUN_0060bfa0_guess(const char* section, const char* key,
    const char* fallback, char* buffer, int size);
// EXTERNAL: TITANIUM 0x00576FA0 FUN_00576fa0_guess
void __cdecl FUN_00576fa0_guess(char* destination, const char* source, int size);
// EXTERNAL: TITANIUM 0x00576FD0 FUN_00576fd0_guess
void __cdecl FUN_00576fd0_guess(char* destination, const char* source, int size);
// EXTERNAL: TITANIUM 0x006220E9 __itoa_guess
char* __cdecl __itoa_guess(int value, char* destination, int radix);
// EXTERNAL: TITANIUM 0x0060E3A3 atol_guess
long __cdecl atol_guess(const char* text);
// EXTERNAL: TITANIUM 0x0060D970 strlen_guess
unsigned int __cdecl strlen_guess(const char* text);

struct HotButton_guess {
    char type;
    int value;
};

#define g_hotButtons_guess EQ_ARRAY(HotButton_guess, 0x00983B7C)
#define g_hotButtonsEnd_guess EQ_ARRAY(HotButton_guess, 0x009847FC)

struct Social_guess {
    char name[16];
    char lines[5][256];
    char color;
};

#define g_socials_guess EQ_ARRAY(Social_guess, 0x0095D4D4)

struct LoadoutConfig_guess {
    void Load_guess(int unused_guess);
};

// SpellLoadouts: SpellLoadout<n>.inuse, .name and .slot1-9 for each changed loadout (1-10).
// FUNCTION: TITANIUM 0x004AFFC3
void SaveSpellLoadouts_guess() {
    char value[256];
    char name[128];
    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        int index = 1;
        int remaining = 10;
        SpellLoadout_guess* loadout = g_spellLoadouts_guess;
        do {
            if (loadout->active == 1) {
                _sprintf_guess(name, "SpellLoadout%d.inuse", index);
                _sprintf_guess(value, "%d", loadout->inuse);
                FUN_0060bf60_guess("SpellLoadouts", name, value);
                if (loadout->inuse != 0) {
                    _sprintf_guess(name, "SpellLoadout%d.name", index);
                    FUN_0060bf60_guess("SpellLoadouts", name, loadout->name);
                    int slot = 0;
                    int* slotValues = loadout->slots;
                    for (; slot < 9; ++slot) {
                        _sprintf_guess(name, EQ_ARRAY(char, 0x0064AD84), index,
                            slot + 1);
                        _sprintf_guess(value, "%d", *slotValues);
                        FUN_0060bf60_guess("SpellLoadouts", name, value);
                        ++slotValues;
                    }
                }
            }
            ++index;
            ++loadout;
            --remaining;
        } while (remaining != 0);
    }
}

struct IniSave_guess {
    // EXTERNAL: TITANIUM 0x004AFFC3 IniSave_guess::SaveSpellLoadouts_guess
    void SaveSpellLoadouts_guess();
    // EXTERNAL: TITANIUM 0x004B010A IniSave_guess::SaveHotbuttonLoadouts_guess
    void SaveHotbuttonLoadouts_guess();
    void SaveHotButtons_guess();
    // EXTERNAL: TITANIUM 0x004B03B1 IniSave_guess::SaveSocials_guess
    void SaveSocials_guess();
    // EXTERNAL: TITANIUM 0x004B05D6 IniSave_guess::SaveAbilities_guess
    void SaveAbilities_guess();
    // EXTERNAL: TITANIUM 0x004B0668 IniSave_guess::SaveCombatSkills_guess
    void SaveCombatSkills_guess();
    // EXTERNAL: TITANIUM 0x004B06FA IniSave_guess::SaveCombatAbilities_guess
    void SaveCombatAbilities_guess();
    // EXTERNAL: TITANIUM 0x004B078C IniSave_guess::saveCustom_guess
    void saveCustom_guess();
    void SaveAll_guess();
    // EXTERNAL: TITANIUM 0x00494E0F IniSave_guess::initCustom_guess
    void initCustom_guess();
    // EXTERNAL: TITANIUM 0x00496E20 IniSave_guess::SetDefaultClassHotButtons_guess
    void SetDefaultClassHotButtons_guess();
    // EXTERNAL: TITANIUM 0x004B0812 IniSave_guess::FUN_004b0812_guess
    void FUN_004b0812_guess(int path);
    void Init_guess();
};

#define g_hotButtonFlags_guess EQ_ARRAY(char, 0x009839E5)

// HotButtons, HotButtons2..4: Page<p>Button<b> = a type letter ('A' + type) and a value, for each changed
// button of the four hotbars (10 pages of 10).
// FUNCTION: TITANIUM 0x004B023B
// @early-stop: budget, structural ndiff=14
void IniSave_guess::SaveHotButtons_guess() {
    char section[256];
    char value[256];
    char key[128];

    if (EQ_GLOBAL(char, 0x00923798) != 0 ||
        (EQ_GLOBAL(char, 0x00923D7B) == 0 &&
         EQ_GLOBAL(int, 0x00923788) != 0 &&
         EQ_GLOBAL(char, 0x00923D7A) == 0)) {
        int page = 0;
        int pageOffset = 0;
        do {
            FUN_00576fa0_guess(section, "HotButtons", 0x100);
            int rowInPage = 0;
            if (pageOffset > 0) {
                FUN_00576fd0_guess(section,
                    __itoa_guess(page + 1, EQ_ARRAY(char, 0x0099DB00), 10),
                    0x100);
            }
            do {
                int row = pageOffset + rowInPage;
                int button = 0;
                HotButton_guess* buttonData = g_hotButtons_guess + row * 10;
                do {
                    if (g_hotButtonFlags_guess[row * 10 + button] == 1) {
                        _sprintf_guess(key, "Page%dButton%d", rowInPage + 1,
                            button + 1);
                        if ((unsigned char)buttonData->type > 0) {
                            _sprintf_guess(value, "%c%d",
                                (unsigned char)buttonData->type + 0x41,
                                buttonData->value);
                            FUN_0060bf60_guess(section, key, value);
                        } else {
                            FUN_0060bf60_guess(section, key, 0);
                        }
                        g_hotButtonFlags_guess[row * 10 + button] = 0;
                    }
                    ++button;
                    ++buttonData;
                } while (button < 10);
                ++rowInPage;
            } while (rowInPage < 10);
            pageOffset += 10;
            ++page;
        } while (pageOffset < 0x28);
    }
}

// Writes the character's ini sections in order: SpellLoadouts, HBLoadouts, the changed HotButtons pages
// (0x004B023B), Socials, Abilities, CombatSkills, CombatAbilities, then the custom UI entry
// (0x004B078C).
// FUNCTION: TITANIUM 0x004B07D8
void IniSave_guess::SaveAll_guess() {
    SaveSpellLoadouts_guess();
    SaveHotbuttonLoadouts_guess();
    SaveHotButtons_guess();
    SaveSocials_guess();
    SaveAbilities_guess();
    SaveCombatSkills_guess();
    SaveCombatAbilities_guess();
    saveCustom_guess();
}

// Reads everything the Save* functions write. Missing keys read as "*NULL*" and keep the current value;
// hotbutton and loadout names cut at 24 characters ("Unnamed" by default).
// FUNCTION: TITANIUM 0x004B0812
// @early-stop: budget, structural ndiff=200
void LoadoutConfig_guess::Load_guess(int unused_guess) {
    char name[128];
    char text[256];
    char page[64];
    char hotbar[256];
    int index;
    int remaining;
    int row;
    int next;
    index = 1;
    remaining = 10;
    SpellLoadout_guess* loadout = g_spellLoadouts_guess;
    do {
        loadout->active = 0;
        _sprintf_guess(name, "SpellLoadout%d.inuse", index);
        loadout->inuse = FUN_0060c030_guess("SpellLoadouts", name, 0) != 0;
        if (loadout->inuse) {
            _sprintf_guess(name, "SpellLoadout%d.name", index);
            FUN_0060bfa0_guess("SpellLoadouts", name, "Unnamed", text, 0x18);
            text[0x18] = 0;
            FUN_0060e450_guess(loadout->name, text);
            loadout->inuse = 1;
            row = 0;
            int* slotValue = loadout->slots;
            do {
                ++row;
                _sprintf_guess(name, "SpellLoadout%d.slot%d", index, row);
                *slotValue = FUN_0060c030_guess("SpellLoadouts", name, -1);
                ++slotValue;
            } while (row < 9);
        }
        ++index;
        ++loadout;
        --remaining;
    } while (remaining != 0);

    index = 1;
    remaining = 10;
    HBSet_guess* set = g_hbSets_guess;
    do {
        set->active = 0;
        _sprintf_guess(name, "HBSet%d.inuse", index);
        set->inuse = FUN_0060c030_guess("HBLoadouts", name, 0) != 0;
        if (set->inuse) {
            _sprintf_guess(name, "HBSet%d.name", index);
            FUN_0060bfa0_guess("HBLoadouts", name, "Unnamed", text, 0x18);
            text[0x18] = 0;
            FUN_0060e450_guess(set->name, text);
            _sprintf_guess(name, "HBSet%d.fileNum", index);
            set->fileNum = FUN_0060c030_guess("HBLoadouts", name, 0);
        }
        ++index;
        ++set;
        --remaining;
    } while (remaining != 0);

    row = 0;
    HotButton_guess* hot = g_hotButtons_guess;
    do {
        FUN_00576fa0_guess(hotbar, "HotButtons", 0x100);
        if (hot > g_hotButtons_guess) {
            char* number = __itoa_guess(row + 1, EQ_ARRAY(char, 0x0099DB00), 10);
            FUN_00576fd0_guess(hotbar, number, 0x100);
        }
        remaining = 0;
        do {
            index = 0;
            ++remaining;
            do {
                hot->value = 0;
                ++index;
                hot->type = 0;
                _sprintf_guess(page, "Page%dButton%d", remaining, index);
                FUN_0060bfa0_guess(hotbar, page, "*NULL*", text, 0x100);
                if (text[0] != '*') {
                    hot->type = text[0] - 0x41;
                    if (hot->type != 0) {
                        hot->value = atol_guess(text + 1);
                    }
                }
                ++hot;
            } while (index < 10);
        } while (remaining < 10);
        ++row;
    } while (hot < g_hotButtonsEnd_guess);

    row = 0;
    index = 0;
    do {
        remaining = 0;
        ++index;
        do {
            next = remaining + 1;
            _sprintf_guess(page, "Page%dButton%d", index, next);
            _sprintf_guess(name, "%sName", page);
            FUN_0060bfa0_guess("Socials", name, "*NULL*", text, 0x100);
            if (text[0] != '*') {
                next = 8;
                if (EQ_GLOBAL(int, 0x00923D74) != 0) {
                    if (IsDoubleByteLanguage_guess(EQ_GLOBAL(int, 0x00923D74))) {
                        next = 15;
                    }
                }
                if (strlen_guess(text) > (unsigned int)next) {
                    text[next] = 0;
                }
                Social_guess* social = &g_socials_guess[remaining + row];
                FUN_0060e450_guess(social->name, text);
                _sprintf_guess(name, "%sColor", page);
                FUN_0060bfa0_guess("Socials", name, "*NULL*", text, 0x100);
                if (text[0] != '*') {
                    social->color = (char)atol_guess(text);
                }
                char* lineDst = social->lines[0];
                next = 0;
                do {
                    ++next;
                    _sprintf_guess(name, "%sLine%d", page, next);
                    FUN_0060bfa0_guess("Socials", name, "*NULL*", text, 0x100);
                    if (text[0] != '*') {
                        FUN_0060e450_guess(lineDst, text);
                    }
                    lineDst += 0x100;
                } while (next < 5);
            }
            ++remaining;
        } while (remaining < 12);
        row += 12;
    } while (row < 0x78);

    for (int i = 0; i < 6; ++i) {
        _sprintf_guess(name, "Ability%d", i + 1);
        FUN_0060bfa0_guess("Abilities", name, "*NULL*", text, 0x100);
        if (text[0] != '*') {
            EQ_ARRAY(int, 0x0095D424)[i] = atol_guess(text);
        }
    }
    for (int i = 0; i < 4; ++i) {
        _sprintf_guess(name, "CombatSkill%d", i + 1);
        FUN_0060bfa0_guess("CombatSkills", name, "*NULL*", text, 0x100);
        if (text[0] != '*') {
            EQ_ARRAY(int, 0x0095D414)[i] = atol_guess(text);
        }
    }
    for (int i = 0; i < 8; ++i) {
        _sprintf_guess(name, "CombatAbility%d", i + 1);
        FUN_0060bfa0_guess("CombatAbilities", name, "*NULL*", text, 0x100);
        if (text[0] != '*') {
            EQ_ARRAY(int, 0x0095D43C)[i] = atol_guess(text);
        }
    }
    FUN_0060bfa0_guess("InspectText", "Text", "*NULL*", text, 0x100);
    if (text[0] != '*' && text[4] != '*') {
        FUN_0060e450_guess(EQ_ARRAY(char, 0x00985708), text);
    }
}

struct CharBase_guess {
    // EXTERNAL: TITANIUM 0x0040E73F CharBase_guess::FUN_0040e73f_guess
    int FUN_0040e73f_guess(int index);
};

struct CharHead_guess {
    int pad_00;
    int pad_04;
};

struct CharVbptr_guess : CharHead_guess, virtual CharBase_guess {
};

struct CharSub_guess {
    // EXTERNAL: TITANIUM 0x0041B0DE CharSub_guess::HasSkill_guess
    int HasSkill_guess(int mode);
};

struct PcChar_guess : CharVbptr_guess {
    char pad_0C[0xC280 - 0x0C];
    CharSub_guess sub_c280;
};

// EXTERNAL: TITANIUM 0x00576670 FUN_00576670_guess
char __cdecl FUN_00576670_guess(int path);

#include "titanium/layouts/core.h"
#include "titanium/wnd/CActionsWnd.h"

struct PathInputRoot_guess {
    char bytes_guess[8];
    VBTable* input_guess;
};

struct ClientState_guess {
    char pad_00000[0x39ab8];
    char flag_39ab8_guess;
    char flag_39ab9_guess;
    char path_39aba_guess[0x200];
    char path_39cba_guess[0x200];
    char path_39eba_guess[0x200];
    char path_3a0ba_guess[0x200];

    // EXTERNAL: TITANIUM 0x00493A10 ClientState_guess::CreateUserDirectories_guess
    void CreateUserDirectories_guess();
    // EXTERNAL: TITANIUM 0x00493B8F ClientState_guess::GetServerShortName_guess
    void GetServerShortName_guess(char* output);
    // EXTERNAL: TITANIUM 0x00493ADA ClientState_guess::Read_guess
    void Read_guess(char* output);
    void CreateIniFilenames_guess();
};

// EXTERNAL: TITANIUM 0x0040552D GetLanguageCodePage_guess
int __cdecl GetLanguageCodePage_guess(int value);
// EXTERNAL: TITANIUM 0x005749F0 FUN_005749f0_guess
void __cdecl FUN_005749f0_guess(int mode, const char* input, char* output, int size);
// EXTERNAL: TITANIUM 0x00577000 FUN_00577000_guess
void __cdecl FUN_00577000_guess(char* destination, int size, const char* format, ...);
// EXTERNAL: TITANIUM 0x00576ED0 FUN_00576ed0_guess
void __cdecl FUN_00576ed0_guess(const char* value);

// Builds the character's file names: UI_<name>_<server>.ini, <name>_<server>.ini,
// userdata\Abilities_<name>_<server>.ini and Logs\eqlog_<name>_<server>.txt. A missing per-server file is
// copied from the old per-name one, which is then deleted.
// FUNCTION: TITANIUM 0x004B0DB5
// @early-stop: unknown, normalised ndiff=0
void ClientState_guess::CreateIniFilenames_guess() {
    char userName[512];
    char uiPath[512];
    char sharedPath[512];
    char worldName[512];
    CreateUserDirectories_guess();
    char* dest = path_39aba_guess;
    *dest = 0;
    PathInputRoot_guess* root = EQ_GLOBAL(PathInputRoot_guess*, 0x00905D00);
    if (root != 0) {
        FUN_005749f0_guess(GetLanguageCodePage_guess(EQ_GLOBAL(int, 0x00923D74)),
            root->bytes_guess + root->input_guess->vbase_offset + 0x44, userName, 0x100);
        _sprintf_guess(dest, ".\\UI_%s_", userName);
        _sprintf_guess(uiPath, ".\\UI_%s_", userName);
        char* dest2 = path_39cba_guess;
        _sprintf_guess(dest2, ".\\%s_", userName);
        FUN_00577000_guess(path_39eba_guess, 0x200, ".\\%s\\Abilities_%s_",
            "userdata", userName);
        _sprintf_guess(sharedPath, ".\\%s_", userName);
        FUN_00576ed0_guess("Logs");
        _sprintf_guess(path_3a0ba_guess, ".\\Logs\\eqlog_%s_", userName);
        GetServerShortName_guess(userName);
        Read_guess(worldName);
        strcat(uiPath, worldName);
        strcat(uiPath, ".ini");
        strcat(dest, userName);
        strcat(dest, ".ini");
        strcat(sharedPath, worldName);
        strcat(sharedPath, ".ini");
        strcat(dest2, userName);
        strcat(dest2, ".ini");
        FUN_00576fd0_guess(path_39eba_guess, userName, 0x200);
        FUN_00576fd0_guess(path_39eba_guess, ".ini", 0x200);
        strcat(path_3a0ba_guess, userName);
        strcat(path_3a0ba_guess, ".txt");
        flag_39ab8_guess = 1;
        flag_39ab9_guess = 1;
        char exists = FUN_00576670_guess((int)dest);
        if (exists == 0 && (exists = FUN_00576670_guess((int)uiPath)) != 0 &&
            CopyFileA(uiPath, dest, 1) != 0) {
            FUN_00612662_guess(uiPath);
        }
        exists = FUN_00576670_guess((int)dest2);
        if (exists == 0 && (exists = FUN_00576670_guess((int)sharedPath)) != 0 &&
            CopyFileA(sharedPath, dest2, 1) != 0) {
            FUN_00612662_guess(sharedPath);
        }
    }
}

// Loads the character ini (or defaults when it is missing), drops abilities the character can't use, and
// turns old-style hotbuttons (types 2 and 3: an index into the ability lists) into type 9 (the ability id
// itself). Only the first 100 buttons, hotbar 1, are converted.
// FUNCTION: TITANIUM 0x004B102D
// @early-stop: budget, structural ndiff=99
void IniSave_guess::Init_guess() {
    int path = GetCustomIniFilename_guess();
    initCustom_guess();
    if (FUN_00576670_guess(path) == 0) {
        SetDefaultClassHotButtons_guess();
    } else {
        FUN_004b0812_guess(path);
    }
    for (int* slot = EQ_ARRAY(int, 0x0095D424); slot < EQ_ARRAY(int, 0x0095D43C); ++slot) {
        if (*slot > -1) {
            if (*slot < 100) {
                if (EQ_GLOBAL(PcChar_guess*, 0x00905D00)->sub_c280.HasSkill_guess((unsigned char)*slot) == 0) {
                    *slot = -1;
                }
            } else {
                if (EQ_GLOBAL(PcChar_guess*, 0x00905D00)->FUN_0040e73f_guess(*slot - 100) != 0) {
                    *slot = -1;
                }
                int value = *slot - 100;
                if (value != 5 && value != 7 && value != 0xb && (value < 0xe || value > 0xf)) {
                    *slot = -1;
                }
            }
        }
    }
    for (int* slot = EQ_ARRAY(int, 0x0095D414); slot < EQ_ARRAY(int, 0x0095D424); ++slot) {
        if (*slot > -1) {
            if (*slot < 100) {
                if (EQ_GLOBAL(PcChar_guess*, 0x00905D00)->sub_c280.HasSkill_guess((unsigned char)*slot) == 0) {
                    *slot = -1;
                }
            } else {
                if (EQ_GLOBAL(PcChar_guess*, 0x00905D00)->FUN_0040e73f_guess(*slot - 100) != 0) {
                    *slot = -1;
                }
                int value = *slot - 100;
                if (value != 5 && value != 7 && value != 0xb && (value < 0xe || value > 0xf)) {
                    *slot = -1;
                }
            }
        }
    }
    for (int group = 0; group < 100; group += 10) {
        for (int i = 0; i < 10; ++i) {
            HotButton_guess* slot = &g_hotButtons_guess[group + i];
            if (slot->type == 2) {
                if (EQ_ARRAY(int, 0x0095D414)[slot->value] == -1) {
                    slot->type = 0;
                    slot->value = 0;
                } else {
                    slot->type = 9;
                    slot->value = EQ_ARRAY(int, 0x0095D414)[slot->value];
                }
                EQ_ARRAY(char, 0x009839E5)[group + i] = 1;
            }
            if (slot->type == 3) {
                if (EQ_ARRAY(int, 0x0095D424)[slot->value] == -1) {
                    slot->type = 0;
                    slot->value = 0;
                } else {
                    slot->type = 9;
                    slot->value = EQ_ARRAY(int, 0x0095D424)[slot->value];
                }
                EQ_ARRAY(char, 0x009839E5)[group + i] = 1;
            }
        }
    }
    SaveAbilities_guess();
    SaveCombatSkills_guess();
    SaveHotButtons_guess();
    pinstCActionsWnd_guess->UpdateButtonLabels_guess();
}

