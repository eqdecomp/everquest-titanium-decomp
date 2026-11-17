// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 30: a hint from compare/tumap.py.
// The startup video-driver check: VideoDriverCheck_guess is the installed card (vendor and device ids, name, driver
// version a.b.c.d), compared with RecommendedDrivers.txt; dialog 0x6E offers the download. Object_guess is
// the same object (+0x18 the installed build, +0x1C the recommended build, +0x20 the download URL).
// Parts_guess and PartsOwner_guess hold the parsed RecommendedDrivers.txt records (0x18 bytes each).
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/crt.h"

struct Node_guess
{
    // EXTERNAL: TITANIUM 0x00572300 Node_guess::Get_guess
    void* Get_guess();
};

// EXTERNAL: TITANIUM 0x0040822D Process_guess
void __cdecl Process_guess(void* value_guess);

struct Object_guess
{
    char pad_00[0x18];
    unsigned int installedBuild_0018_guess; // 0x18
    unsigned int recommendedBuild_001c_guess; // 0x1c
    Node_guess downloadUrl_0020_guess; // 0x20

    void OpenDownloadPage_guess();

    unsigned char IsDriverCurrent_guess();
};

struct CXStrView_guess
{
    void* data_guess;

    CXStrView_guess() : data_guess(0) {}

    // EXTERNAL: TITANIUM 0x00572300 CXStrView_guess::Get_guess
    void* Get_guess();

    // EXTERNAL: TITANIUM 0x00571FC0 CXStrView_guess::Set_guess
    void Set_guess(void* value_guess);

    // EXTERNAL: TITANIUM 0x00407D68 ??0CXStrView_guess@@QAE@ABU0@@Z
    CXStrView_guess(const CXStrView_guess& source_guess);

    // EXTERNAL: TITANIUM 0x00571D00 CXStrView_guess::FreeRep
    void FreeRep(void* data_guess);

    ~CXStrView_guess()
    {
        if (data_guess != 0)
            FreeRep(data_guess);
        data_guess = 0;
    }
};

struct VideoDriverCheck_guess
{
    int field0_guess; // 0x00
    CXStrView_guess name_guess; // 0x04
    int field8_guess; // 0x08
    int part0_guess; // 0x0c
    int part1_guess; // 0x10
    int part2_guess; // 0x14
    int part3_guess; // 0x18
    unsigned int count_guess; // 0x1c
    CXStrView_guess url_guess; // 0x20

    VideoDriverCheck_guess(HINSTANCE instance_guess, HWND parent_guess, int field0_arg_guess, CXStrView_guess name_arg_guess,
        int field8_arg_guess, int part0_arg_guess, int part1_arg_guess, int part2_arg_guess, int part3_arg_guess);

    CXStrView_guess ToString_guess();
    CXStrView_guess Message_guess();
    void SaveShowForCard_guess(bool value_guess);

    // EXTERNAL: TITANIUM 0x00445B00 ?GetWindowsVersion_guess@VideoDriverCheck_guess@@QAEHPAHPAPAX@Z
    int GetWindowsVersion_guess(int* count_guess, void** url_guess);
    int GetWindowsVersion_guess();

    unsigned char IsWarningDisabled_guess();

    void LoadRecommended_guess();
};

#define g_versionDialog_guess EQ_GLOBAL(VideoDriverCheck_guess*, 0x00850DAC)

// EXTERNAL: TITANIUM 0x00611848 _exit_guess
void __stdcall _exit_guess(int status_guess);

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStrView_guess* output_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x0042E3D9 LookupSetting_guess
CXStrView_guess __cdecl LookupSetting_guess(const char* key_guess, const CXStrView_guess& value_guess);

struct CEverQuestView_guess
{
    // EXTERNAL: TITANIUM 0x004AE5AF CEverQuestView_guess::Set_guess
    void Set_guess(bool value_guess, const char* key_guess, void* text_guess);

    // EXTERNAL: TITANIUM 0x004AE721 CEverQuestView_guess::Get_guess
    unsigned char Get_guess(const char* key_guess, void* text_guess, int default_guess);
};

#define g_settings_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)

struct PartAt4_guess
{
    // EXTERNAL: TITANIUM 0x004482FB PartAt4_guess::Finish_guess
    void Finish_guess();
};

struct PartAt8_guess
{
    // EXTERNAL: TITANIUM 0x0050F3F6 PartAt8_guess::Initialize_guess
    void Initialize_guess();
};

struct Parts_guess
{
    char pad_00[4];
    PartAt4_guess partAt4_guess;
    char pad_05[3];
    PartAt8_guess partAt8_guess;
    char pad_09[0x0f];

    void Release_guess();
    void* VectorDelete_guess(unsigned char flags_guess);
};

struct PartsArray_guess
{
    int count_guess; // 0x00
    Parts_guess elements_guess[1]; // 0x04
};

struct PartsOwner_guess
{
    unsigned int field0_guess; // 0x00
    Parts_guess* parts_guess; // 0x04
    unsigned int field8_guess; // 0x08

    void Clear_guess();
};

struct RecommendedFile_guess : PartsOwner_guess
{
    int field0c_guess; // 0x0c

    // EXTERNAL: TITANIUM 0x004C42BB RecommendedFile_guess::RecommendedFile_guess
    RecommendedFile_guess(const char* name_guess);

    // EXTERNAL: TITANIUM 0x004C3EF3 RecommendedFile_guess::Read_guess
    unsigned char Read_guess(int field0_guess, int field8_guess, int found_guess);

    ~RecommendedFile_guess()
    {
        Clear_guess();
    }
};

// EXTERNAL: TITANIUM 0x0060D6E5 EHVectorDestructorIterator_guess
void __stdcall EHVectorDestructorIterator_guess(Parts_guess* elements_guess, unsigned int size_guess,
    int count_guess, void (Parts_guess::*destructor_guess)());

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
void __cdecl FreeArray_guess(void* memory_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 FreeSingle_guess
void __cdecl FreeSingle_guess(void* memory_guess);

// Opens the driver download URL in the browser (0x40822D, LaunchBrowser_guess in tu_007).
// FUNCTION: TITANIUM 0x00445A71
void Object_guess::OpenDownloadPage_guess()
{
    Process_guess(downloadUrl_0020_guess.Get_guess());
}

// Whether the installed build is at least the recommended one, or none is listed.
// FUNCTION: TITANIUM 0x00445A81
unsigned char Object_guess::IsDriverCurrent_guess()
{
    unsigned char result_guess = 1;
    if ((recommendedBuild_001c_guess != 0) && (recommendedBuild_001c_guess > installedBuild_0018_guess))
        result_guess = 0;
    return result_guess;
}

// The installed driver version as "a.b.c.d" (+0xC..+0x18): shown in the warning text and used as the
// per-version "ShowForCard" key in the Defaults section.
// FUNCTION: TITANIUM 0x00445A92
CXStrView_guess VideoDriverCheck_guess::ToString_guess()
{
    CXStrView_guess text_guess;
    FormatString_guess(&text_guess, "%d.%d.%d.%d", part0_guess, part1_guess, part2_guess, part3_guess);
    return text_guess;
}

// Windows family: 1 Windows Me (4.90), 2 Windows 2000, 3 XP or Server 2003, else 0; probably the OS
// column of RecommendedDrivers.txt.
// FUNCTION: TITANIUM 0x00445B00
// @early-stop: unknown, diff ndiff=10
int VideoDriverCheck_guess::GetWindowsVersion_guess()
{
    int result_guess = 0;
    OSVERSIONINFOEXA info_guess;
    memset(&info_guess, 0, sizeof(info_guess));
    info_guess.dwOSVersionInfoSize = sizeof(info_guess);
    if (!GetVersionExA((LPOSVERSIONINFOA)&info_guess))
    {
        info_guess.dwOSVersionInfoSize = sizeof(OSVERSIONINFOA);
        if (!GetVersionExA((LPOSVERSIONINFOA)&info_guess))
            return 0;
    }
    switch (info_guess.dwPlatformId)
    {
    case 0:
        result_guess = 0;
        break;
    case 1:
        if (info_guess.dwMajorVersion == 4 && info_guess.dwMinorVersion != 0 &&
            // Only 4.90 counts; the 4.0 and 4.10 tests add nothing.
            info_guess.dwMinorVersion != 10 && info_guess.dwMinorVersion == 90)
            result_guess = 1;
        break;
    case 2:
        if (info_guess.dwMajorVersion == 5)
        {
            if (info_guess.dwMinorVersion == 2 || info_guess.dwMinorVersion == 1)
                result_guess = 3;
            else if (info_guess.dwMinorVersion == 0)
                result_guess = 2;
        }
        break;
    }
    return result_guess;
}

// Whether the player turned the warning off for this driver version (Defaults, "ShowForCard" key built
// with the version by 0x42E3D9, stored 0).
// FUNCTION: TITANIUM 0x00445BA6
// @early-stop: budget, structural ndiff=33
unsigned char VideoDriverCheck_guess::IsWarningDisabled_guess()
{
    CXStrView_guess version_guess = ToString_guess();
    unsigned char result_guess;
    {
        CXStrView_guess shown_guess = LookupSetting_guess("ShowForCard", version_guess);
        result_guess = g_settings_guess->Get_guess("Defaults", shown_guess.Get_guess(), 1) == 0;
    }
    return result_guess;
}

// Text of the outdated video driver dialog (0x00445D71 puts it in control 0x3EE): card name, installed
// driver version (0x00445A92), recommended driver version (+0x1C) and the download URL (+0x20).
// FUNCTION: TITANIUM 0x00445C36
CXStrView_guess VideoDriverCheck_guess::Message_guess()
{
    void* name_text_guess = name_guess.Get_guess();
    CXStrView_guess version_guess = ToString_guess();
    unsigned int count = count_guess;
    void* url_text_guess = url_guess.Get_guess();
    CXStrView_guess text_guess;
    FormatString_guess(&text_guess, "You currently have a %s (%s) video card installed. We recommend that you download version %d drivers before playing EverQuest. You can pick up these drivers at %s.", name_text_guess, version_guess.Get_guess(), count, url_text_guess);
    return text_guess;
}

// Saves the "don't show again" choice for this driver version.
// FUNCTION: TITANIUM 0x00445CE8
void VideoDriverCheck_guess::SaveShowForCard_guess(bool value_guess)
{
    CXStrView_guess version_guess = ToString_guess();
    {
        CXStrView_guess shown_guess = LookupSetting_guess("ShowForCard", version_guess);
        g_settings_guess->Set_guess(value_guess, "Defaults", shown_guess.Get_guess());
    }
}

// Destructor of one RecommendedDrivers.txt record (0x18 bytes): releases its members at +8 and +4.
// FUNCTION: TITANIUM 0x00445E51
void Parts_guess::Release_guess()
{
    partAt8_guess.Initialize_guess();
    partAt4_guess.Finish_guess();
}

// Compiler vector deleting destructor for 0x18-byte elements: with flag 2 it destroys the whole array
// (count in the dword before it), else one element; flag 1 also frees the memory.
// FUNCTION: TITANIUM 0x00445E65
void* Parts_guess::VectorDelete_guess(unsigned char flags_guess)
{
    if ((flags_guess & 2) != 0)
    {
        PartsArray_guess* array_guess = reinterpret_cast<PartsArray_guess*>(reinterpret_cast<char*>(this) - 4);
        EHVectorDestructorIterator_guess(this, 0x18, array_guess->count_guess, &Parts_guess::Release_guess);
        if ((flags_guess & 1) != 0)
            FreeArray_guess(&array_guess->count_guess);
        return &array_guess->count_guess;
    }

    Release_guess();
    if ((flags_guess & 1) != 0)
        FreeSingle_guess(this);
    return this;
}

// Frees the parsed RecommendedDrivers.txt records.
// FUNCTION: TITANIUM 0x00445EB0
void PartsOwner_guess::Clear_guess()
{
    if (parts_guess != 0)
        parts_guess->VectorDelete_guess(3);
    parts_guess = 0;
    field8_guess = 0;
    field0_guess = 0;
}

// Frees the parsed RecommendedDrivers.txt records (0x00445EB0).
// FUNCTION: TITANIUM 0x00445ECE
void __fastcall ClearThunk_guess(PartsOwner_guess* owner_guess)
{
    owner_guess->Clear_guess();
}

// Dialog 0x6E: control 0x3EE shows the message, 0x3ED is "don't show again", 0x3EF opens the download
// page and ends with 0 (the caller then exits the game), 1000 continues.
// FUNCTION: TITANIUM 0x00445D71
INT_PTR CALLBACK VersionDialogProc_guess(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    INT_PTR result_guess = 1;
    switch (msg)
    {
    case WM_CLOSE:
        EndDialog(hwnd, 1);
        break;
    case WM_INITDIALOG:
    {
        VideoDriverCheck_guess* version_guess = reinterpret_cast<VideoDriverCheck_guess*>(lParam);
        g_versionDialog_guess = version_guess;
        SetWindowTextA(GetDlgItem(hwnd, 0x3ee), static_cast<LPCSTR>(version_guess->Message_guess().Get_guess()));
        break;
    }
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1000:
            EndDialog(hwnd, 1);
            break;
        case 0x3ed:
        {
            bool checked_guess = IsDlgButtonChecked(hwnd, 0x3ed) & 1;
            g_versionDialog_guess->SaveShowForCard_guess(!checked_guess);
            break;
        }
        case 0x3ef:
            reinterpret_cast<Object_guess*>(g_versionDialog_guess)->OpenDownloadPage_guess();
            EndDialog(hwnd, 0);
            break;
        }
        break;
    default:
        result_guess = 0;
        break;
    }
    return result_guess;
}

// Looks up the recommended build and URL for this card and OS in RecommendedDrivers.txt. The two pointers
// given to GetWindowsVersion_guess are really Read_guess's last two arguments (tu_085's FindValue_guess takes them); the
// overload keeps their push order for the match.
// FUNCTION: TITANIUM 0x00445ED3
void VideoDriverCheck_guess::LoadRecommended_guess()
{
    RecommendedFile_guess file_guess("RecommendedDrivers.txt");
    void* loaded_url_guess;
    int loaded_count_guess;
    if (file_guess.Read_guess(field0_guess, field8_guess, GetWindowsVersion_guess(&loaded_count_guess, &loaded_url_guess)))
    {
        count_guess = loaded_count_guess;
        url_guess.Set_guess(loaded_url_guess);
    }
}

// Unless turned off, shows dialog 0x6E when the card's build is below the recommended one; Download
// (result 0) exits the game.
// FUNCTION: TITANIUM 0x00445F3F
VideoDriverCheck_guess::VideoDriverCheck_guess(HINSTANCE instance_guess, HWND parent_guess, int field0_arg_guess, CXStrView_guess name_arg_guess,
    int field8_arg_guess, int part0_arg_guess, int part1_arg_guess, int part2_arg_guess, int part3_arg_guess)
    : field0_guess(field0_arg_guess), name_guess(name_arg_guess), field8_guess(field8_arg_guess),
      part0_guess(part0_arg_guess), part1_guess(part1_arg_guess), part2_guess(part2_arg_guess),
      part3_guess(part3_arg_guess), count_guess(0)
{
    if (!IsWarningDisabled_guess())
    {
        LoadRecommended_guess();
        if (!reinterpret_cast<Object_guess*>(this)->IsDriverCurrent_guess())
        {
            int result = DialogBoxParamA(instance_guess, (LPCSTR)0x6e, parent_guess, (DLGPROC)VersionDialogProc_guess, (LPARAM)this);
            if (!result)
                _exit_guess(0);
        }
    }
}

