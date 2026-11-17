// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 104: a hint from compare/tumap.py.
// The /alarm window (AlarmWnd): hours and minutes edit boxes, OK/Cancel and "never show again", saved as
// ShowAlarmWindow in eqclient.ini [Defaults]. The alarm itself is the 0x99140C/0x991410 pair: tu_105's
// frame handler (0x004D82FF) shows the announcement when it falls due, and /played (tu_046 0x0046F9CB)
// prints the time left.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"

#define g_alarmSet_guess EQ_GLOBAL(unsigned char, 0x0099140C)
#define g_showAlarmWindow_guess EQ_GLOBAL(unsigned char, 0x0099140D)
#define g_alarmTime_guess EQ_GLOBAL(int, 0x00991410)
#define g_alarmHours_guess EQ_GLOBAL(int, 0x00991414)
#define g_alarmMinutes_guess EQ_GLOBAL(int, 0x00991418)

// EXTERNAL: TITANIUM 0x0060BEB0 WriteIniString_guess
void __cdecl WriteIniString_guess(const char* section_guess, const char* key_guess,
                                  const char* value_guess, const char* path_guess);

// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section_guess, const char* key_guess,
    const char* defaultValue_guess, char* output_guess, int outputSize_guess,
    const char* filename_guess);

struct CXStrRep_guess {
    int refCount_guess; // 0x0
    int alloc_guess;    // 0x4
    int length_guess;   // 0x8
};

struct CXStr_guess {
    CXStrRep_guess* rep_guess; // 0x0
    int GetLength_guess() const {
        return rep_guess ? rep_guess->length_guess : 0;
    }
};

struct CEditBaseWnd_guess {
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
    virtual void SetWindowText_guess(const CXStr_guess& text_guess); // 0xFC
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
    virtual CXStr GetWindowText_guess(); // 0x130
    char padding_0004_guess[0x124];
    int maxChars_guess;        // 0x128
    char padding_012c_guess[4];
    CXStr_guess text_guess;    // 0x130
    char padding_0134_guess[0x230 - 0x134];
    int field_0230_guess;      // 0x230
    void SetMaxChars_guess(int maxChars);
};

// Re-sets the text when it is already longer than the new limit, so the box trims it; 0 or less means no
// limit.
// FUNCTION: TITANIUM 0x004D7EBC
void CEditBaseWnd_guess::SetMaxChars_guess(int maxChars) {
    maxChars_guess = maxChars;
    if (maxChars > 0 && text_guess.GetLength_guess() > maxChars) {
        SetWindowText_guess(text_guess);
    }
}

struct SidlPiece_guess {
    char pad_0000_guess[0x60];
    unsigned int flags_0060_guess; // 0x60
};

// Local polymorphic base for the CSidlScreenWnd ctor (0x005A3900), 0x15C bytes.
struct AlarmWindowBase_guess {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x005A3100 ??1AlarmWindowBase_guess@@UAE@XZ
    virtual ~AlarmWindowBase_guess();
    // EXTERNAL: TITANIUM 0x005A3900 AlarmWindowBase_guess::AlarmWindowBase_guess
    AlarmWindowBase_guess(CXWnd* parent, const CXStr& screen);
    char pad_0004_guess[0x10];
    unsigned char field_0014_guess;
    char pad_0015_guess[0x64 - 0x15];
    unsigned int windowStyle_0064_guess; // 0x64
    char pad_0068_guess[0x124 - 0x68];
    SidlPiece_guess* sidlPiece_0124_guess; // 0x124
    char pad_0128_guess[0x15c - 0x128];
};

// EXTERNAL: TITANIUM 0x0064EBE8 ??_7CAlarmWnd_guess@@6B@
struct CAlarmWnd_guess : AlarmWindowBase_guess {
    virtual void Slot00_guess();
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
    virtual int WndNotification_guess(CXWnd* sender, unsigned int message, void* data); // 0x20
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
    virtual void Show_guess(int show_guess, int activate_guess); // 0xC0
    void SaveShowAlarm_guess();
    CAlarmWnd_guess(CXWnd* parent);
    CXWnd* okButton_015c_guess;
    CXWnd* cancelButton_0160_guess;
    CXWnd* neverShowAgainCheckbox_0164_guess;
    CEditBaseWnd_guess* hoursEditbox_0168_guess;
    CEditBaseWnd_guess* minutesEditbox_016c_guess;
};

// Both edit boxes get style value 3 at +0x230 and a two-digit limit.
// The minutes branch limits the hours box again, so the minutes box keeps no limit: an original slip, kept
// for
// the match.
// FUNCTION: TITANIUM 0x004D7EEF
CAlarmWnd_guess::CAlarmWnd_guess(CXWnd* parent)
    : AlarmWindowBase_guess(parent, "AlarmWnd") {
    field_0014_guess = 0xff;
    okButton_015c_guess = 0;
    cancelButton_0160_guess = 0;
    neverShowAgainCheckbox_0164_guess = 0;
    hoursEditbox_0168_guess = 0;
    minutesEditbox_016c_guess = 0;
    if (sidlPiece_0124_guess != 0) {
        windowStyle_0064_guess |= sidlPiece_0124_guess->flags_0060_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        okButton_015c_guess = ((CSidlScreenWnd*)this)->GetChildItem("ALRW_OkButton");
        cancelButton_0160_guess = ((CSidlScreenWnd*)this)->GetChildItem("ALRW_CancelButton");
        neverShowAgainCheckbox_0164_guess =
            ((CSidlScreenWnd*)this)->GetChildItem("ALRW_NeverShowAgainCheckbox");
        hoursEditbox_0168_guess =
            (CEditBaseWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ALRW_HoursEditbox");
        if (hoursEditbox_0168_guess != 0) {
            hoursEditbox_0168_guess->field_0230_guess = 3;
            hoursEditbox_0168_guess->SetMaxChars_guess(2);
        }
        minutesEditbox_016c_guess =
            (CEditBaseWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("ALRW_MinutesEditbox");
        if (minutesEditbox_016c_guess != 0) {
            minutesEditbox_016c_guess->field_0230_guess = 3;
            hoursEditbox_0168_guess->SetMaxChars_guess(2);
        }
    }
}

// True only on the first call that finds ShowAlarmWindow set ('t', 'T' or '1'; default "true"), so the window
// opens at most once per session. Reads only 32 bytes into the 256-byte buffer.
// FUNCTION: TITANIUM 0x004D80DA
unsigned char ConsumeShowAlarmWindowSetting_guess() {
    char showAlarmWindow_guess[256];
    unsigned char result_guess = 0;
    if (g_showAlarmWindow_guess == 0) {
        FUN_0060be50_guess("Defaults", "ShowAlarmWindow", "true",
            showAlarmWindow_guess, 0x20, ".\\eqclient.ini");
        if (showAlarmWindow_guess[0] == 't' || showAlarmWindow_guess[0] == 'T' ||
            showAlarmWindow_guess[0] == '1') {
            result_guess = 1;
            g_showAlarmWindow_guess = 1;
        }
    }
    return result_guess;
}

struct AlarmConfig_guess {
    char pad_0000_guess[0x128];
    unsigned char showAlarmWindow_guess; // 0x128
};

// Writes ShowAlarmWindow: "false" when "never show again" is checked (+0x128), and also when the window has
// no
// checkbox at all.
// FUNCTION: TITANIUM 0x004D8150
// @early-stop: unknown, structural ndiff=6
void CAlarmWnd_guess::SaveShowAlarm_guess() {
    const char* value_guess;
    if (neverShowAgainCheckbox_0164_guess == 0) {
        value_guess = "false";
    } else if (((AlarmConfig_guess*)neverShowAgainCheckbox_0164_guess)->showAlarmWindow_guess == 0) {
        value_guess = "true";
    } else {
        value_guess = "false";
    }
    WriteIniString_guess("Defaults", "ShowAlarmWindow", value_guess, ".\\eqclient.ini");
}

// OK (message 1 = left click) arms the alarm: negative fields count as 0, minutes of 60 or more carry into
// hours, and the alarm time is now + the total in seconds. Both buttons save the checkbox and hide the
// window.
// FUNCTION: TITANIUM 0x004D8188
int CAlarmWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        if (sender == okButton_015c_guess) {
            int hours = 0;
            int minutes = 0;
            if (hoursEditbox_0168_guess != 0) {
                sscanf(hoursEditbox_0168_guess->GetWindowText_guess(), "%d", &hours);
                if (hours < 0) {
                    hours = 0;
                }
            }
            if (minutesEditbox_016c_guess != 0) {
                sscanf(minutesEditbox_016c_guess->GetWindowText_guess(), "%d", &minutes);
                if (minutes < 0) {
                    minutes = 0;
                }
                if (minutes >= 60) {
                    unsigned int q = (unsigned int)minutes / 60;
                    hours += q;
                    minutes += q * -60;
                }
            }
            g_alarmHours_guess = hours;
            g_alarmMinutes_guess = minutes;
            g_alarmTime_guess = (hours * 60 + minutes) * 60 + time(0);
            g_alarmSet_guess = 1;
            SaveShowAlarm_guess();
            Show_guess(0, 1);
        } else if (sender == cancelButton_0160_guess) {
            SaveShowAlarm_guess();
            Show_guess(0, 1);
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}
