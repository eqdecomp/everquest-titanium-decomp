// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 154: a hint from compare/tumap.py.
// CExploreModeWnd (screen "ExploreModeWindow", vtable 0x653DF0) plus input filters that, while the player is
// dead, let only the respawn window (0x850BC4, CRespawnWnd) and chat windows (CChatManager 0x9917E4) react.
// Thing_guess is probably a window-manager subclass (vtable 0x653DA0; base dtor 0x5B0A00, CXWndManager).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/wnd/CChatManager.h"

struct DtorGuard_guess {
    ~DtorGuard_guess() {}
};

struct Thing_guess {
    void* vtable;
    char pad04[0x24];
    Thing_guess* related;
    DtorGuard_guess dtorGuard;
    ~Thing_guess();
    Thing_guess* Delete_guess(unsigned char flags);
    void Finish_guess();
};

struct RelevanceState_guess {
    char pad_000[0x244];
    unsigned char mode_244;
};

struct ManagerCommands_guess {
    int Cur_HP(int argument);
};

struct RuntimeModeBytes_guess {
    char pad_000[0x104];
    char modes[1];
};

struct RuntimeModeNode_guess {
    char pad_000[4];
    RuntimeModeBytes_guess* bytes_004;
};

struct EQ_CharacterView_guess {
    char pad_000[8];
    RuntimeModeNode_guess* modeNode_008;
    char pad_00c[0xC280 - 0x0c];
    ManagerCommands_guess commands_C280;
};

struct EventCallback_guess {
    void OnFirst_guess(int argument);
    char OnSecond_guess(int argument);
    char IsRespawnOrChatWindow_guess(int argument);
    char Fallback_guess(int argument);
};

// EXTERNAL: TITANIUM 0x00417E07 ManagerCommands_guess::Cur_HP
// EXTERNAL: TITANIUM 0x004FFEC9 EventCallback_guess::IsRespawnOrChatWindow_guess
// EXTERNAL: TITANIUM 0x005ADFB0 EventCallback_guess::Fallback_guess

// EXTERNAL: TITANIUM 0x005B0A00 Thing_guess::Finish_guess
// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Destructor: restores vtable 0x653DA0 and runs the base destructor 0x5B0A00 (names.tsv
// CXWndManager::~CXWndManager, medium).
// FUNCTION: TITANIUM 0x004FFEBE
Thing_guess::~Thing_guess() {
    vtable = &EQ_GLOBAL(int, 0x00653DA0);
    Finish_guess();
}

#define pinstCRespawnWnd_guess EQ_GLOBAL(Thing_guess*, 0x00850BC4)

// Whether window `thing` (or its +0x28 owner, probably the top-level parent) is the respawn window or
// one of the chat manager's windows.
// FUNCTION: TITANIUM 0x004FFEC9
char __stdcall IsRespawnOrChatWindow_guess(Thing_guess* thing) {
    char result = 0;
    Thing_guess* related = thing->related;
    if (related == 0) {
        related = thing;
    }
    if (related == pinstCRespawnWnd_guess ||
        pinstCChatManager_guess->Contains_guess(related)) {
        result = 1;
    }
    return result;
}

// Scalar deleting destructor of the window-manager subclass (vtable 0x653DA0 slot 0): runs its
// destructor (0x004FFEBE) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x004FFEF9
Thing_guess* Thing_guess::Delete_guess(unsigned char flags) {
    this->~Thing_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Input filter: dead (EQ_Character1::Cur_HP 0x417E07 below 1) or state 3/4 restricts to the respawn and
// chat windows; otherwise the default handler 0x5ADFB0.
// FUNCTION: TITANIUM 0x004FFF15
void EventCallback_guess::OnFirst_guess(int argument) {
    if (EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00) != 0 &&
        // The state byte below is indexed by the pCharData pointer value itself; that matches the binary, but
        // the real expression is not understood yet.
        (EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->commands_C280.Cur_HP(0) < 1 ||
         EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->modeNode_008->bytes_004->modes[
             (unsigned int)EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)] == 3 ||
         EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->modeNode_008->bytes_004->modes[
             (unsigned int)EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)] == 4)) {
        IsRespawnOrChatWindow_guess(argument);
    } else {
        Fallback_guess(argument);
    }
}

// Same test returning a verdict: true unless dead (or state 3/4) and the window is neither respawn nor chat.
// FUNCTION: TITANIUM 0x004FFF69
char EventCallback_guess::OnSecond_guess(int argument) {
    if (EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00) != 0 &&
        (EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->commands_C280.Cur_HP(0) < 1 ||
         EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->modeNode_008->bytes_004->modes[
             (unsigned int)EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)] == 3 ||
         EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)->modeNode_008->bytes_004->modes[
             (unsigned int)EQ_GLOBAL(EQ_CharacterView_guess*, 0x00905D00)] == 4)) {
        return IsRespawnOrChatWindow_guess(argument);
    }
    return 1;
}

// True unless the local player's +0x244 is above 1; then the respawn/chat test decides.
// FUNCTION: TITANIUM 0x004FFFB4
char __stdcall IsRelevantMode_guess(Thing_guess* thing) {
    RelevanceState_guess* state = EQ_GLOBAL(RelevanceState_guess*, 0x00905CE4);
    if (state != 0 && state->mode_244 > 1) {
        return IsRespawnOrChatWindow_guess(thing);
    }
    return 1;
}

/* ---- CExploreModeWnd::CExploreModeWnd(CXWnd*) (0x004FFFD0) ------------------------------------------
 * Layout: include/titanium/types.h CExploreModeWnd (0x164). The ctor needs a polymorphic base with the
 * real CSidlScreenWnd base ctor and dtor: CSidlScreenWndBase. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x00653DF0 ??_7CExploreModeWndView_guess@@6B@
struct CExploreModeWndView_guess : CSidlScreenWndBase {
    CXWnd* charInfoLabel_15c;               // 0x15c EXW_CharInfoLabel
    CXWnd* exploreLabel_160;                // 0x160 EXW_ExploreModeWindow3
    CExploreModeWndView_guess(CXWnd* parent);
};

// Explore mode window constructor: finds EXW_CharInfoLabel and EXW_ExploreModeWindow3.
// FUNCTION: TITANIUM 0x004FFFD0
CExploreModeWndView_guess::CExploreModeWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "ExploreModeWindow") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        charInfoLabel_15c = ((CSidlScreenWnd*)this)->GetChildItem("EXW_CharInfoLabel");
        exploreLabel_160 = ((CSidlScreenWnd*)this)->GetChildItem("EXW_ExploreModeWindow3");
    }
}

