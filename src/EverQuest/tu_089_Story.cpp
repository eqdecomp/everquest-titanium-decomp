// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 89: a hint from compare/tumap.py.
// Three pieces: the MP3 player's playlist (MusicPlayer_guess and Forwarder_guess; tu_087 has the rest), the
// spell table (SpellManager_guess is SpellManager: a '^'-separated file, 10000 slots) and the Storyline window
// (Story_guess, CStoryWnd_guess and Object_guess are all CStoryWnd: screen "StoryWnd", vtable 0x64C220).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <new>
#include "titanium/wnd/CTipWnd.h"

struct Source_guess {
    char pad0000_guess[0x128];
    char flag_guess; // 0x128
};

struct Item_guess {
    char pad0000_guess[0x800];
    int rank_guess; // 0x800
    char pad0804_guess[0x1004 - 0x804];
    int extra_guess; // 0x1004
};

struct Rows_guess {
    int count_guess; // 0x0

    // EXTERNAL: TITANIUM 0x004EB924 Rows_guess::At_guess
    Item_guess** At_guess(int index);
};

struct Stml_guess : CStmlWnd {
    // EXTERNAL: TITANIUM 0x005A9060 Stml_guess::Append_guess
    void Append_guess(const CXStr& text, int flag, int link);
};

struct CStoryWnd_guess {
    char pad005c_guess[0x5c];
    char enabled_guess; // 0x5c
    char pad005d_guess[0x15c - 0x5d];
    Source_guess* source_guess; // 0x15c
    Stml_guess* stml_guess; // 0x160
    CListWnd* feed_guess; // 0x164
    Rows_guess rows_guess; // 0x168
    char pad016c_guess[0x17c - 0x16c];
    int current_guess; // 0x17c
    int limit_guess; // 0x180
    char active_guess; // 0x184

    bool HasUnreadStory_guess();
    void Callback_guess();
    void WndNotification_guess(void* target, int kind, int extra);
    int ShouldAutoOpen_guess();
    void Save_guess();
    void LoadIniInfo_guess();
    void SelectNewestUnread_guess();

    void ShowStory_guess(int value);
    // EXTERNAL: TITANIUM 0x005A2230 CStoryWnd_guess::WndNotification
    void WndNotification(void* target, int kind, int extra);
    // EXTERNAL: TITANIUM 0x005A1880 CStoryWnd_guess::OnShow
    void OnShow();
};

struct PoolItem_guess {
    // EXTERNAL: TITANIUM 0x0044DBF0 PoolItem_guess::PoolItem_guess
    PoolItem_guess(const char* line);
    // EXTERNAL: TITANIUM 0x0044CEF0 PoolItem_guess::FreeStrings_guess
    void FreeStrings_guess();
    char pad0000_guess[0x270];
};

struct Stat_guess {
    char pad0000_guess[0x1c];
    time_t mtime_guess; // 0x1c
    char pad0020_guess[4];
};

struct TextFileReader_guess {
    // EXTERNAL: TITANIUM 0x00576BD0 TextFileReader_guess::TextFileReader_guess
    TextFileReader_guess(const char* path, char delimiter);
    // EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::IsOpen_guess
    bool IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::Next_guess
    int Next_guess();
    // EXTERNAL: TITANIUM 0x00576CF0 TextFileReader_guess::Line_guess
    void Line_guess(char* buffer, int size);
    // EXTERNAL: TITANIUM 0x00576C50 TextFileReader_guess::Close_guess
    void Close_guess();
    char pad0000_guess[0x1000c];
};

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x006104F0 _stat_guess
extern "C" int __cdecl _stat_guess(const char* path, struct _stat* info);
// EXTERNAL: TITANIUM 0x004B6C04 MemChecker0
unsigned int __cdecl MemChecker0(const void* data, int size);
// EXTERNAL: TITANIUM 0x00574830 IsEntry_guess
int __cdecl IsEntry_guess(const char* line, int flags);
// EXTERNAL: TITANIUM 0x00576D80 ParseInt_guess
long __cdecl ParseInt_guess(char** cursor, char delimiter);

struct SpellManager_guess {
    Stat_guess stat_guess; // 0x0
    PoolItem_guess* items_guess[10000]; // 0x24
    unsigned int sums_guess[10000]; // 0x9c64
    PoolItem_guess* tail_guess; // 0x138a4
    unsigned int tailSum_guess; // 0x138a8
    char path_guess[0x104]; // 0x138ac

    SpellManager_guess(const char* path);
    void Clear_guess();
};

#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

struct BasePart_guess {
    // EXTERNAL: TITANIUM 0x005A3100 BasePart_guess::~BasePart_guess
    virtual ~BasePart_guess() ;
};

struct MemberPart_guess {
    int value0_guess;
    int value1_guess;
    int value2_guess;
    unsigned char flag_guess; // 0xc
    MemberPart_guess() {
        value1_guess = 0;
        value0_guess = 0;
        value2_guess = 0;
        flag_guess = 1;
    }
    // EXTERNAL: TITANIUM 0x004EB924 MemberPart_guess::Get_guess
    struct StoryEntry_guess** Get_guess(int index);
    // EXTERNAL: TITANIUM 0x0050319B MemberPart_guess::Insert_guess
    void Insert_guess(int index, struct StoryEntry_guess** item);
    ~MemberPart_guess() ;
};

// EXTERNAL: TITANIUM 0x0064C220 ??_7Object_guess@@6B@
struct Object_guess : BasePart_guess {
    char pad0168_guess[0x164];
    MemberPart_guess member_guess; // 0x168

    ~Object_guess() ;
    Object_guess* Delete_guess(unsigned char flags);
};

struct Forwarder_guess {
    // EXTERNAL: TITANIUM 0x004C703E Forwarder_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x004C70FD Forwarder_guess::ClearPlaylist_guess
    void ClearPlaylist_guess();
    void StopAndClearPlaylist_guess();
};

struct Stream_guess {
    // EXTERNAL: TITANIUM 0x004C5227 Stream_guess::GetStreamPosition_guess
    int GetStreamPosition_guess();
    // EXTERNAL: TITANIUM 0x004C5275 Stream_guess::Status_guess
    int Status_guess();
};

struct Entry_guess {
    char pad0000_guess[0xc];
    int random_guess; // 0xc
};

struct MusicPlayer_guess {
    char enabled_guess; // 0x0
    char repeat_guess; // 0x1
    char pad0002_guess[2];
    int index_guess; // 0x4
    char pad0008_guess[4];
    Stream_guess* stream_guess; // 0xc
    char pad0010_guess[4];
    char active_guess; // 0x14
    char pad0015_guess[3];
    int mode_guess; // 0x18
    int limit_guess; // 0x1c
    Entry_guess* entries_guess[1]; // 0x20

    // EXTERNAL: TITANIUM 0x004C70CE MusicPlayer_guess::PlayIndex_guess
    void PlayIndex_guess(int value);
    // EXTERNAL: TITANIUM 0x004C703E MusicPlayer_guess::Prepare_guess
    void Prepare_guess();
    // EXTERNAL: TITANIUM 0x004C705F MusicPlayer_guess::Play_guess
    void Play_guess();
    void NextTrack_guess();
    void PreviousTrack_guess();
    void Sort_guess(int mode);
    void Process_guess();
};

// EXTERNAL: TITANIUM 0x004C5E77 CompareOrder_guess
int __cdecl CompareOrder_guess(const void* left, const void* right);
// EXTERNAL: TITANIUM 0x004C5E8A CompareRandom_guess
int __cdecl CompareRandom_guess(const void* left, const void* right);

typedef int (__cdecl *HasUnreadStory_guess)(const void*, const void*);
extern "C" int __cdecl rand(void);
extern "C" void __cdecl qsort(void* base, unsigned int count, unsigned int size, HasUnreadStory_guess compare);

// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory);

// Storyline window destructor: frees the array at +0x168 (0x0050F3F6), then the CSidlScreenWnd
// destructor (0x005A3100).
// FUNCTION: TITANIUM 0x004C7A11
Object_guess::~Object_guess() 
{
}

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf_guess
int __cdecl _sprintf_guess(char* destination, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060BEE0 FUN_0060bee0_guess
void __cdecl FUN_0060bee0_guess(const char* section, const char* key,
    char* value, const char* path);
// EXTERNAL: TITANIUM 0x0060BF10 thunk_FUN_0060be50_guess
void __cdecl thunk_FUN_0060be50_guess(const char* section, const char* key,
    const char* defaultValue, char* value, int size, const char* path);

// Scalar deleting destructor of the Storyline window (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C7A35
Object_guess* Object_guess::Delete_guess(unsigned char flags)
{
    this->Object_guess::~Object_guess();
    if (flags & 1)
        free(this);
    return this;
}

// Stops playback and empties the playlist (0x4C70FD).
// FUNCTION: TITANIUM 0x004C7304
void Forwarder_guess::StopAndClearPlaylist_guess()
{
    Prepare_guess();
    ClearPlaylist_guess();
}

// Play order: mode 0 list order, 1 shuffled (fresh rand() keys). Keeps the playing track selected; if
// nothing is playing, selects track 0.
// FUNCTION: TITANIUM 0x004C7314
// @early-stop: budget, diff ndiff=17
void MusicPlayer_guess::Sort_guess(int mode)
{
    int selector = mode;
    mode_guess = selector;
    int count = limit_guess;
    int i = 0;
    if (count <= i)
        return;

    Entry_guess* selected = entries_guess[index_guess];
    HasUnreadStory_guess compare;
    int doSort = 1;
    switch (selector) {
    case 0:
        compare = CompareOrder_guess;
        break;
    case 1:
        if (limit_guess > i) {
            do {
                entries_guess[i]->random_guess = rand();
                ++i;
            } while (i < limit_guess);
    }
        compare = CompareRandom_guess;
        count = limit_guess;
        break;
    default:
        doSort = 0;
        break;
    }
    if (doSort)
        qsort(entries_guess, count, 4, compare);

    if (stream_guess->Status_guess() == 1) {
        for (int i = 0; i < limit_guess; ++i) {
            if (entries_guess[i] == selected) {
                index_guess = i;
                return;
            }
        }
    }
    else {
        PlayIndex_guess(0);
    }
}

// Per frame, once the track has ended (status 0): with byte 0 set, single-track mode (replay if repeat,
// else stop); otherwise the next track, and past the end back to 0, playing only if repeat (byte 1).
// FUNCTION: TITANIUM 0x004C73B8
void MusicPlayer_guess::Process_guess()
{
    if (active_guess && stream_guess->Status_guess() == 0) {
        if (enabled_guess) {
            if (repeat_guess) {
                Play_guess();
                return;
            }
            return;
        }

        ++index_guess;
        if (index_guess < limit_guess) {
            Play_guess();
            return;
        }
        if (repeat_guess)
            PlayIndex_guess(0);
        else
            index_guess = 0;
    }
}

// Next track, wrapping.
// FUNCTION: TITANIUM 0x004C7403
void MusicPlayer_guess::NextTrack_guess()
{
    if (limit_guess > 0)
        PlayIndex_guess((index_guess + 1) % limit_guess);
}

// Previous-track button. Not CTextureFont::DrawWrappedText (Mac match).
// FUNCTION: TITANIUM 0x004C741A
void MusicPlayer_guess::PreviousTrack_guess()
{
    if (limit_guess > 0) {
        int position = stream_guess->GetStreamPosition_guess();
        // Within the first 3 s: the previous track; later: restart this one.
        if (position < 3000) {
            PlayIndex_guess((index_guess + limit_guess - 1) % limit_guess);
            return;
        }
        Prepare_guess();
        Play_guess();
        return;
    }
}


// Whether a story newer than the last one read exists (LastRead +0x17C, newest file time +0x180).
// FUNCTION: TITANIUM 0x004C776D
bool CStoryWnd_guess::HasUnreadStory_guess()
{
    return current_guess < limit_guess;
}

// Close hook: if shown (+0x5C), reports window id 0x10 (+0x158) to the 0x9928E0 object, then the base
// call; tu_146's 0x4F8A17 is the same with id 0x2E.
// FUNCTION: TITANIUM 0x004C7781
void CStoryWnd_guess::Callback_guess()
{
    if (enabled_guess && pinstCTipWndCONTEXT_guess)
        pinstCTipWndCONTEXT_guess->selectTip_guess(0x10, 0);
    OnShow();
}

// Shows story row `value`: marks it read (LastRead = its file time, saved) and hands its path (+0) to the
// Display box, probably to load the file; -1 clears the box.
// FUNCTION: TITANIUM 0x004C77A5
void CStoryWnd_guess::ShowStory_guess(int value)
{
    if (value >= 0) {
        Item_guess* item = (Item_guess*)((CListWnd*)feed_guess)->GetItemData(value);
        if (current_guess <= item->rank_guess) {
            current_guess = item->rank_guess;
            Save_guess();
        }
        if (stml_guess != 0) {
            CXStr text((const char*)item);
            stml_guess->Append_guess(text, 0, 0);
        }
    }
    else {
        if (stml_guess != 0)
            stml_guess->SetSTMLText(CXStr(g_emptyString_guess), true, 0);
    }
}

// WndNotification: a click on AutomaticButton toggles auto-open (saved); on StoryList shows that story.
// Not CSpellBookWnd::DeleteSpellFromBook (Mac match).
// FUNCTION: TITANIUM 0x004C7857
void CStoryWnd_guess::WndNotification_guess(void* target, int kind, int extra)
{
    if (kind == 1) {
        if (target == source_guess) {
            active_guess = source_guess->flag_guess;
            Save_guess();
        }
        else if (target == feed_guess) {
            ShowStory_guess(feed_guess->GetCurSel());
        }
    }
    WndNotification(target, kind, extra);
}

// 1 when a story is unread and auto-open is on: the window should pop up.
// FUNCTION: TITANIUM 0x004C799A
int CStoryWnd_guess::ShouldAutoOpen_guess()
{
    int result = 0;
    if (current_guess < limit_guess && active_guess)
        result++;
    return result;
}

// Selects and shows the last row newer than LastRead, or clears the selection.
// FUNCTION: TITANIUM 0x004C79B4
void CStoryWnd_guess::SelectNewestUnread_guess()
{
    int index = rows_guess.count_guess;
    int value = -1;
    while (--index >= 0) {
        if (rows_guess.At_guess(index)[0]->rank_guess > current_guess) {
            value = rows_guess.At_guess(index)[0]->extra_guess;
            break;
        }
    }
    if (feed_guess != 0) {
        feed_guess->SetCurSel(value);
        ShowStory_guess(value);
    }
}

union Dword_guess {
    unsigned int value_guess;
    unsigned char bytes_guess[4];
};

// Reorders the 4 checksum bytes to b1 b3 b0 b2, the stored form of the spell checksums.
// FUNCTION: TITANIUM 0x004C7458
// @early-stop: budget, structural ndiff=9
int ReorderChecksum_guess(Dword_guess* p)
{
    Dword_guess v = *p;
    p->bytes_guess[0] = v.bytes_guess[1];
    p->bytes_guess[1] = v.bytes_guess[3];
    p->bytes_guess[2] = v.bytes_guess[0];
    p->bytes_guess[3] = v.bytes_guess[2];
    return 1;
}

// SpellManager::SpellManager (the Mac-matched dtor is 0x4C7666): all 10000 slots start at one blank
// spell, then each '^' line fills its id; every spell gets a reordered MemChecker0 CRC.
// FUNCTION: TITANIUM 0x004C7481
// @early-stop: budget, diff ndiff=2
SpellManager_guess::SpellManager_guess(const char* path)
{
    char line[0x1000];
    memset(items_guess, 0, sizeof(items_guess));
    memset(sums_guess, 0, sizeof(sums_guess));
    _stat(path, (struct _stat*)&stat_guess);
    strcpy(path_guess, path);
    tail_guess = new PoolItem_guess(0);
    // The blank spell is summed over 0x22C bytes, loaded ones over 0x204.
    tailSum_guess = MemChecker0(tail_guess, 0x22c);
    ReorderChecksum_guess((Dword_guess*)&tailSum_guess);
    for (int i = 0; i < 10000; ++i) {
        items_guess[i] = tail_guess;
        sums_guess[i] = tailSum_guess;
    }

    TextFileReader_guess* reader = new TextFileReader_guess(path, '^');
    if (reader->IsOpen_guess()) {
        while (reader->Next_guess() > 0) {
            reader->Line_guess(line, sizeof(line));
            if (IsEntry_guess(line, 0)) {
                char* cursor = line;
                long id = ParseInt_guess(&cursor, '^');
                // An id over 9999 ends the whole load, not just that line.
                if (id > 9999)
                    break;
                items_guess[id] = new PoolItem_guess(line);
                sums_guess[id] = MemChecker0(items_guess[id], 0x204);
                ReorderChecksum_guess((Dword_guess*)&sums_guess[id]);
            }
        }
    }
    if (reader != 0) {
        reader->Close_guess();
        free(reader);
    }
}

// SpellManager::~SpellManager (Mac match, high): frees the loaded spells, then the shared blank one.
// FUNCTION: TITANIUM 0x004C7666
void SpellManager_guess::Clear_guess()
{
    for (int index = 0; index < 10000; ++index) {
        PoolItem_guess* item = items_guess[index];
        if (item != tail_guess && item != 0) {
            item->FreeStrings_guess();
            free(item);
        }
    }
    PoolItem_guess* last = tail_guess;
    if (last != 0) {
        last->FreeStrings_guess();
        free(last);
    }
}

// Writes [News] LastRead (hex file time) and Automatic to eqclient.ini.
// FUNCTION: TITANIUM 0x004C76DE
void CStoryWnd_guess::Save_guess()
{
    char buffer[256];
    _sprintf_guess(buffer, "%08X", current_guess);
    FUN_0060bee0_guess("News", "LastRead", buffer, ".\\eqclient.ini");
    _sprintf_guess(buffer, "%d", active_guess != 0);
    FUN_0060bee0_guess("News", "Automatic", buffer, ".\\eqclient.ini");
}

// LoadIniInfo override: reads [News] LastRead and Automatic ('1', 't' or 'T' is on), then rewrites them.
// FUNCTION: TITANIUM 0x004C78AE
void CStoryWnd_guess::LoadIniInfo_guess()
{
    char defaultValue[256];
    char value[256];
    int automatic;

    ((CSidlScreenWnd*)this)->CSidlScreenWnd::LoadIniInfo();
    _sprintf_guess(defaultValue, "%08X", 0);
    thunk_FUN_0060be50_guess("News", "LastRead", defaultValue, value, 0xff, ".\\eqclient.ini");
    sscanf(value, "%08X", &current_guess);
    active_guess = 0;
    _sprintf_guess(defaultValue, "%d", 0);
    thunk_FUN_0060be50_guess("News", "Automatic", defaultValue, value, 0xff, ".\\eqclient.ini");
    if (value[0] == '1' || value[0] == 't' || value[0] == 'T')
        automatic = 1;
    else
        automatic = 0;
    active_guess = automatic;
    Save_guess();
}

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct StoryList_guess : CListWnd {
    char pad0140_guess[0x15c - 0x140];
    unsigned char flag15c_guess; // 0x15c
    char pad0160_guess[0x16c - 0x160];
    unsigned int color16c_guess; // 0x16c
};

// EXTERNAL: TITANIUM 0x0064C220 ??_7Story_guess@@6B@
struct Story_guess : CSidlScreenWndBase {
    CXWnd* automatic_guess;      // 0x15c
    CXWnd* display_guess;        // 0x160
    StoryList_guess* list_guess; // 0x164
    MemberPart_guess member_guess; // 0x168
    char pad0178_guess[8];
    int newest_guess; // 0x180
    bool active_guess; // 0x184

    virtual void Slot04_guess(); virtual void Slot08_guess(); virtual void Slot0C_guess(); virtual void Slot10_guess();
    virtual void Slot14_guess(); virtual void Slot18_guess(); virtual void Slot1C_guess(); virtual void Slot20_guess();
    virtual void Slot24_guess(); virtual void Slot28_guess(); virtual void Slot2C_guess(); virtual void Slot30_guess();
    virtual void Slot34_guess(); virtual void Slot38_guess(); virtual void Slot3C_guess(); virtual void Slot40_guess();
    virtual void Slot44_guess(); virtual void Slot48_guess(); virtual void Slot4C_guess(); virtual void Slot50_guess();
    virtual void Slot54_guess(); virtual void Slot58_guess(); virtual void Slot5C_guess(); virtual void Slot60_guess();
    virtual void Slot64_guess(); virtual void Slot68_guess(); virtual void Slot6C_guess(); virtual void Slot70_guess();
    virtual void Slot74_guess(); virtual void Slot78_guess(); virtual void Slot7C_guess(); virtual void Slot80_guess();
    virtual void Slot84_guess(); virtual void Slot88_guess(); virtual void Slot8C_guess(); virtual void Slot90_guess();
    virtual void Slot94_guess(); virtual void Slot98_guess(); virtual void Slot9C_guess(); virtual void SlotA0_guess();
    virtual void SlotA4_guess(); virtual void SlotA8_guess(); virtual void SlotAC_guess(); virtual void SlotB0_guess();
    virtual void SlotB4_guess(); virtual void SlotB8_guess(); virtual void SlotBC_guess(); virtual void SlotC0_guess();
    virtual void SlotC4_guess(); virtual void SlotC8_guess(); virtual void SlotCC_guess(); virtual void SlotD0_guess();
    virtual void SlotD4_guess(); virtual void SlotD8_guess(); virtual void SlotDC_guess(); virtual void SlotE0_guess();
    virtual void SlotE4_guess(); virtual void SlotE8_guess(); virtual void SlotEC_guess(); virtual void SlotF0_guess();
    virtual void SlotF4_guess(); virtual void SlotF8_guess(); virtual void SlotFC_guess(); virtual void Slot100_guess();
    virtual void Slot104_guess(); virtual void Slot108_guess(); virtual void Slot10C_guess(); virtual void Slot110_guess();
    virtual void Slot114_guess(); virtual void Slot118_guess();

    // EXTERNAL: TITANIUM 0x004C7A51 Story_guess::Refresh_guess
    void Refresh_guess();

    Story_guess(CXWnd* parent);
};

struct StoryEntry_guess {
    char path_guess[0x800]; // 0x000
    time_t mtime_guess; // 0x800
    char name_guess[0x800]; // 0x804
    unsigned int row_guess; // 0x1004
};

struct ListSlots_guess {
    virtual void RefreshCounts_guess(); virtual void Slot04_guess(); virtual void Slot08_guess(); virtual void Slot0C_guess();
    virtual void Slot10_guess(); virtual void Slot14_guess(); virtual void Slot18_guess(); virtual void Slot1C_guess();
    virtual void Slot20_guess(); virtual void Slot24_guess(); virtual void Slot28_guess(); virtual void Slot2C_guess();
    virtual void Slot30_guess(); virtual void Slot34_guess(); virtual void Slot38_guess(); virtual void Slot3C_guess();
    virtual void Slot40_guess(); virtual void Slot44_guess(); virtual void Slot48_guess(); virtual void Slot4C_guess();
    virtual void Slot50_guess(); virtual void Slot54_guess(); virtual void Slot58_guess(); virtual void Slot5C_guess();
    virtual void Slot60_guess(); virtual void Slot64_guess(); virtual void Slot68_guess(); virtual void Slot6C_guess();
    virtual void Slot70_guess(); virtual void Slot74_guess(); virtual void Slot78_guess(); virtual void Slot7C_guess();
    virtual void Slot80_guess(); virtual void Slot84_guess(); virtual void Slot88_guess(); virtual void Slot8C_guess();
    virtual void Slot90_guess(); virtual void Slot94_guess(); virtual void Slot98_guess(); virtual void Slot9C_guess();
    virtual void SlotA0_guess(); virtual void SlotA4_guess(); virtual void SlotA8_guess(); virtual void SlotAC_guess();
    virtual void SlotB0_guess(); virtual void SlotB4_guess(); virtual void SlotB8_guess(); virtual void SlotBC_guess();
    virtual void SlotC0_guess(); virtual void SlotC4_guess(); virtual void SlotC8_guess(); virtual void SlotCC_guess();
    virtual void SlotD0_guess(); virtual void SlotD4_guess(); virtual void SlotD8_guess(); virtual void SlotDC_guess();
    virtual void SlotE0_guess(); virtual void SlotE4_guess(); virtual void SlotE8_guess(); virtual void SlotEC_guess();
    virtual void SlotF0_guess(); virtual void SlotF4_guess(); virtual void SlotF8_guess(); virtual void SlotFC_guess();
    virtual void Slot100_guess(); virtual void Slot104_guess(); virtual void Slot108_guess(); virtual void Slot10C_guess();
    virtual void Slot110_guess(); virtual void Slot114_guess(); virtual void Slot118_guess(); virtual void Slot11C_guess();
    virtual void Slot120_guess(); virtual void Slot124_guess(); virtual void Slot128_guess(); virtual void Slot12C_guess();
    virtual void Slot130_guess();
};

// EXTERNAL: TITANIUM 0x00574A30 Trim_guess
void __cdecl Trim_guess(char* text, int size);
// EXTERNAL: TITANIUM 0x004C76B3 CompareStory_guess
int __cdecl CompareStory_guess(const void* left, const void* right);
// EXTERNAL: TITANIUM 0x0060D682 FreeArray_guess
extern "C" void __cdecl FreeArray_guess(void* memory);
// EXTERNAL: TITANIUM 0x006104F0 _stat
// Rebuilds the story list from storyline\story*.txt: first line = title, file time = date, sorted by
// CompareStory_guess; the newest time goes to +0x180. The explicit ~MemberPart_guess calls just empty
// the array (match shape).
// FUNCTION: TITANIUM 0x004C7A51
// @early-stop: unknown, structural ndiff=135
void Story_guess::Refresh_guess()
{
    char pattern[512];
    WIN32_FIND_DATAA find;
    char path[2048];
    char name[2048];
    char text[2052];
    struct _stat info;
    FILE* file;
    HANDLE handle;
    StoryEntry_guess* entry;
    StoryEntry_guess** sorted;
    int count;
    int i;

    Slot118_guess();
    if (automatic_guess != 0)
        ((CButtonWnd*)automatic_guess)->SetCheck(active_guess);
    member_guess.~MemberPart_guess();
    newest_guess = 0;
    _sprintf_guess(pattern, "%s\\story*.txt", "storyline");
    handle = FindFirstFileA(pattern, &find);
    if (handle != INVALID_HANDLE_VALUE) {
        do {
            _sprintf_guess(path, "%s\\%s", "storyline", find.cFileName);
            file = fopen(path, "rt");
            if (file != 0) {
                entry = new StoryEntry_guess();
                fgets(text, 0x804, file);
                sscanf(text, "%[^\n", name);
                Trim_guess(name, 0x7ff);
                strcpy(entry->name_guess, name);
                strcpy(entry->path_guess, path);
                info.st_mtime = 0;
                if (_stat_guess(path, &info) == 0)
                    entry->mtime_guess = info.st_mtime;
                if (newest_guess < entry->mtime_guess)
                    newest_guess = entry->mtime_guess;
                member_guess.Insert_guess(member_guess.value0_guess, &entry);
            }
        } while (FindNextFileA(handle, &find) != 0);
        FindClose(handle);
    }
    count = member_guess.value0_guess;
    sorted = new StoryEntry_guess*[count];
    for (i = 0; i < count; ++i)
        sorted[i] = *member_guess.Get_guess(i);
    qsort(sorted, count, 4, CompareStory_guess);
    member_guess.~MemberPart_guess();
    if (0 < count) {
        StoryEntry_guess** item = sorted;
        int left = count;
        do {
            member_guess.Insert_guess(member_guess.value0_guess, item);
            ++item;
        } while (--left != 0);
    }
    FreeArray_guess(sorted);
    if (list_guess != 0) {
        ((ListSlots_guess*)list_guess)->Slot130_guess();
        for (i = 0; i < count; ++i) {
            entry = *member_guess.Get_guess(i);
            entry->row_guess = list_guess->AddString(CXStr(ctime(&entry->mtime_guess)), -1, (unsigned int)entry, 0);
            list_guess->SetItemText(entry->row_guess, 1, CXStr(entry->name_guess));
        }
    }
}

// StoryWnd: binds AutomaticButton, Display and StoryList, sets the list colors, then fills the list from
// the storyline folder's story*.txt files (0x004C7A51: one row per file, sorted, shown by file date).
// FUNCTION: TITANIUM 0x004C7DE4
Story_guess::Story_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "StoryWnd", 0xfffffdff, 1, 0)
{
    automatic_guess = 0;
    list_guess = 0;
    display_guess = 0;
    if (SidlPiece != 0) {
        WindowStyle |= 0x10800;
        field_158_guess = 0x10;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        automatic_guess = ((CSidlScreenWnd*)this)->GetChildItem("AutomaticButton");
        display_guess = ((CSidlScreenWnd*)this)->GetChildItem("Display");
        list_guess = (StoryList_guess*)((CSidlScreenWnd*)this)->GetChildItem("StoryList");
        if (list_guess != 0) {
            list_guess->SetColors(-1, 0xffffff00, 0xff808080);
            list_guess->color16c_guess = 0xff8aa3ff;
            list_guess->flag15c_guess = 1;
        }
        Refresh_guess();
    }
}

// Destructor of the client's growable array: frees the element buffer (+4) and zeroes it, the
// capacity (+8) and the count (+0).
// FUNCTION: TITANIUM 0x0050F3F6
MemberPart_guess::~MemberPart_guess() {
    if (value1_guess != 0) {
        FreeArray_guess((void*)value1_guess);
    }
    value1_guess = 0;
    value2_guess = 0;
    value0_guess = 0;
}
