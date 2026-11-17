/* The most-called client functions of eqgame.exe (Titanium), one declaration each, at their real VAs.
 *
 * Arity and convention come from the function's own `ret N` (export stack_purge) and its call sites,
 * names from MQ2Emu's Titanium eqgame.h / EQClasses.h where they agree with this binary. Classes here are
 * call targets with their known layout (fields only where MQ2 and observed offsets agree, padding
 * elsewhere; sizes are checked in titanium/types.h). They are NOT polymorphic: a vtable pointer is a plain
 * field. Calling a method that is virtual in the real class (marked `virtual slot`) through these
 * declarations gives a direct call, which is what a qualified call `Base::F()` compiles to. A TU that
 * defines a class's ctor/dtor or virtual methods still needs its own class with the virtual slots.
 *
 * If a callee's VA is listed here, use this declaration instead of writing a local `_guess` one.
 * Overloaded names carry the decorated symbol in their marker (externs.py needs it to pick the overload).
 */
#ifndef TITANIUM_CORE_DECLS_H
#define TITANIUM_CORE_DECLS_H

#include "titanium/eqaddr.h"

struct CXWnd;
struct CListWnd;
struct CTextureAnimation;
struct SLinkInfo;
struct CHARINFO2;

/* ---- CXStr: 4-byte handle to a refcounted CStrRep (MQ2 _CXSTR) ------------------------------------- */
struct CStrRep {
    /*0x00*/ int refCount;          /* lock inc / lock dec in copy ctor / FreeRep */
    /*0x04*/ int alloc;
    /*0x08*/ int length;
    /*0x0C*/ int encoding;          /* 0 = ASCII, 1 = Unicode (operator char* converts) */
    /*0x10*/ CStrRep* next;         /* free list / lock in MQ2 */
    /*0x14*/ char text[4];          /* variable length */
};

/* ~CXStr is inline, as the game's header had it: VC inlines it in most places (FreeRep 0x00571D00 is
 * called directly 2,916 times) and calls its out-of-line COMDAT copy, 0x004482FB, in EH-state contexts
 * (member/base dtors, unwinding). That COMDAT is defined in your object, so a marker cannot map it: the
 * compare needs the alias "??1CXStr@@QAE@XZ": "0x004482FB" in tests/unicorn/crt_defaults.json (like the
 * existing ??1Item@@QAE@XZ). Without it the out-of-line case shows `call ?` where the original has
 * F:4482fb. Temporaries: `CXStr(text)` reuses the ctor's EAX (`push eax` right after the ctor; 0x0054E242);
 * the implicit char* conversion reloads the address (`lea eax,[ebp-N]; push eax`; the window ctors'
 * GetChildItem("...") calls). Pick the form the original shows. */
struct CXStr {
    /*0x00*/ CStrRep* Ptr;

    CXStr() : Ptr(0) {}                 /* inline: a member CXStr is `mov [this+N], 0` (CConfirmationDialog +0x170) */
    // EXTERNAL: TITANIUM 0x00571E00 ??0CXStr@@QAE@PBD@Z
    CXStr(const char* text);
    // EXTERNAL: TITANIUM 0x00407D68 ??0CXStr@@QAE@ABU0@@Z
    CXStr(const CXStr& other);
    ~CXStr() {
        if (Ptr != 0) {
            FreeRep(Ptr);
        }
        Ptr = 0;
    }
    // EXTERNAL: TITANIUM 0x00571F70 ??4CXStr@@QAEAAU0@ABU0@@Z
    CXStr& operator=(const CXStr& other);
    // EXTERNAL: TITANIUM 0x00571FC0 ??4CXStr@@QAEAAU0@PBD@Z
    CXStr& operator=(const char* text);
    // EXTERNAL: TITANIUM 0x00572E00 ??YCXStr@@QAEXPBD@Z
    void operator+=(const char* text);
    // EXTERNAL: TITANIUM 0x00572300 ??BCXStr@@QBEPADXZ
    operator char*() const;
    // EXTERNAL: TITANIUM 0x00571D00 CXStr::FreeRep
    void FreeRep(CStrRep* rep);
};

/* 16-byte rectangle; returned by value through a hidden pointer (GetScreenRect: ret 4). */
struct CXRect {
    int left, top, right, bottom;
};

/* ---- StringTable (pinstStringTable 0x00905CB0) -------------------------------------------------------- */
struct StringTable {
    // EXTERNAL: TITANIUM 0x005DFA00 StringTable::getString
    char* getString(unsigned long id, bool* found);     /* ret 8; callers pass found = 0 */
};
#define pStringTable EQ_GLOBAL(StringTable*, 0x00905CB0)

/* ---- CEverQuest (pinstCEverQuest 0x00988DF0; size 0x3A1C8, types.h) ----------------------------------- */
struct CEverQuest {
    /* dtor 0x00497395 (matched, tu_062): three polymorphic bases, vtables 0x006498D4 (+0), 0x00649890 (+4) and
     * 0x0064988C (+8); the +8 base is the notifier interface (own vtable 0x0063FD9C) whose inline dtor
     * purges it from the 0x00991E44 table. Plain fields in this view. */
    /*0x00000*/ void* vftable;
    /*0x00004*/ void* vftable_04;
    /*0x00008*/ void* vftable_08;
    /*0x0000C*/ unsigned int pad_0000C[(0x3A1C4 - 0x0000C) / 4];
    /*0x3A1C4*/ void* field_3A1C4;        /* owned object deleted first by the dtor (0x00497123) */

    // EXTERNAL: TITANIUM 0x004982C6 ?dsp_chat@CEverQuest@@QAEXPBDH_N@Z
    void dsp_chat(const char* text, int color, bool allowLog);  /* ret 0xC */
    // EXTERNAL: TITANIUM 0x00498436 ?dsp_chat@CEverQuest@@QAEXPBD@Z
    void dsp_chat(const char* text);                            /* = dsp_chat(text, 0x111, 1) */
};
#define pEverQuest EQ_GLOBAL(CEverQuest*, 0x00988DF0)

/* ---- EQ_Character (pinstCharData 0x00905D00) ----------------------------------------------------------
 * GetCharInfo2 0x005EC220 reads [this] and [this+4]; its callers pass pCharData+4 (`lea ecx,[eax+4]`,
 * 1,311 sites). So it is a method of a non-virtual base at +4. The base name is not known (MQ2 calls the
 * function EQ_Character::GetCharInfo2): `pCharData->GetCharInfo2()` gives the `lea ecx,[eax+4]`. */
struct EQ_CharacterHead_guess {
    /*0x00*/ void* vftable;
};
struct EQ_CharacterProfile_guess {
    /*0x04*/ void* list;            /* nodes {key, value, ?, next@0xC}; GetCharInfo2 returns the value */
    /*0x08*/ int key;                 /* of the node to find */
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfile_guess::GetCharInfo2
    CHARINFO2* GetCharInfo2();
};
struct EQ_Character : EQ_CharacterHead_guess, EQ_CharacterProfile_guess {
};
#define pCharData EQ_GLOBAL(EQ_Character*, 0x00905D00)

/* ---- Player and display globals (names from eqclientmod-titanium's eq_titanium.h, Unlicense) ----------- */
struct EQPlayer;
struct CDisplay;
/* MQ2's pinst* names: plain pTarget/pDisplay would be macros over SDK parameter names (RPCNDR.H NDRcopy). */
#define pinstLocalPlayer EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define pinstTarget EQ_GLOBAL(EQPlayer*, 0x00905D04)
#define pinstCDisplay EQ_GLOBAL(CDisplay*, 0x00905D24)

/* ---- CXWnd (base window; layout per MQ2 _CSIDLWND up to 0x11C) ----------------------------------------- */
struct CXWnd {
    /*0x000*/ void** vftable;
    /*0x004*/ unsigned int pad_004[(0x028 - 0x004) / 4];
    /*0x028*/ CXWnd* pParentWindow;
    /*0x02C*/ CXWnd* pChildren;
    /*0x030*/ CXWnd* pSiblings;
    /*0x034*/ unsigned int pad_034[(0x03C - 0x034) / 4];
    /*0x03C*/ CXRect Location;            /* MQ2 Location; CGemsGameWnd ctor takes a gem's width/height from it */
    /*0x04C*/ CXRect OldLocation;         /* MQ2 OldLocation */
    /*0x05C*/ unsigned char Show;         /* MQ2 Show; read by 13 queue functions */
    /*0x05D*/ unsigned char Enabled;      /* MQ2 Enabled; CRaidWnd ctor clears it on its Lock/Group buttons */
    /*0x05E*/ unsigned char pad_05E[2];
    /*0x060*/ unsigned char Unknown0x060;
    /*0x061*/ unsigned char Unknown0x061; /* CGemsGameWnd ctor sets it to 1 on GGW_HighScores */
    /*0x062*/ unsigned char MouseOver;    /* MQ2 MouseOver */
    /*0x063*/ unsigned char pad_063;
    /*0x064*/ unsigned int WindowStyle;   /* MQ2 WindowStyle; GetScreenRect reads its low byte signed */
    /*0x068*/ unsigned int pad_068[(0x0B0 - 0x068) / 4];
    /*0x0B0*/ unsigned char Alpha;        /* MQ2 Alpha */
    /*0x0B1*/ unsigned char Fades;        /* MQ2 Fades; CBazaarWnd ctor clears it on BZW_BazaarSlotsWnd */
    /*0x0B2*/ unsigned char pad_0B2[2];
    /*0x0B4*/ unsigned int pad_0B4[(0x11C - 0x0B4) / 4];

    // EXTERNAL: TITANIUM 0x0059D960 CXWnd::GetScreenRect
    CXRect GetScreenRect() const;                 /* ret 4: hidden return pointer */
    // EXTERNAL: TITANIUM 0x0059D6C0 CXWnd::GetClientClipRect
    CXRect GetClientClipRect() const;
    // EXTERNAL: TITANIUM 0x0059EDF0 CXWnd::SetFocus
    CXWnd* SetFocus();
    // EXTERNAL: TITANIUM 0x0059FEC0 CXWnd::IsReallyVisible
    bool IsReallyVisible() const;
    // EXTERNAL: TITANIUM 0x005A0E50 CXWnd::OnProcessFrame
    int OnProcessFrame();                         /* virtual slot */
    // EXTERNAL: TITANIUM 0x005A8BF0 CXWnd::SetWindowTextA
    void SetWindowTextA(const CXStr& text);       /* ret 4; callers pass the address of a CXStr they destroy */
};

/* ---- CListWnd : CXWnd ---------------------------------------------------------------------------------- */
struct CListWnd : CXWnd {
    /*0x11C*/ int ItemsCount;         /* line array: count at +0x11C, data at +0x120 */
    /*0x120*/ void* Items;
    /*0x124*/ unsigned int pad_124[(0x13C - 0x124) / 4];
    /*0x13C*/ int CurSel;             /* GetCurSel: CurSel < ItemsCount ? CurSel : -1 */

    // EXTERNAL: TITANIUM 0x00597BE0 CListWnd::GetCurSel
    int GetCurSel() const;
    // EXTERNAL: TITANIUM 0x00597C20 CListWnd::SetCurSel
    void SetCurSel(int index);
    // EXTERNAL: TITANIUM 0x00597C60 CListWnd::SetColors
    void SetColors(unsigned long a, unsigned long b, unsigned long c);
    // EXTERNAL: TITANIUM 0x00597ED0 CListWnd::GetItemData
    unsigned int GetItemData(int index) const;
    // EXTERNAL: TITANIUM 0x00597F10 CListWnd::GetItemText
    CXStr GetItemText(int index, int column) const;   /* ret 0xC: hidden return + 2 */
    // EXTERNAL: TITANIUM 0x00598580 CListWnd::ClearAllSel
    void ClearAllSel();
    // EXTERNAL: TITANIUM 0x005982E0 CListWnd::SetColumnJustification
    void SetColumnJustification(int column, int justification);
    // EXTERNAL: TITANIUM 0x00598620 CListWnd::SetItemData
    void SetItemData(int index, unsigned int data);
    // EXTERNAL: TITANIUM 0x0059B360 CListWnd::SetItemText
    void SetItemText(int index, int column, const CXStr& text);   /* the caller owns and frees the CXStr (0x004D5D1D) */
    // EXTERNAL: TITANIUM 0x0059B9D0 CListWnd::AddString
    int AddString(const CXStr& text, unsigned long color, unsigned int data, const CTextureAnimation* icon);
                                                      /* ret 0x10; MQ2 spells the first argument CXStr* */
    // EXTERNAL: TITANIUM 0x0059BB00 CListWnd::RemoveLine
    void RemoveLine(int index);
};

/* ---- CButtonWnd : CXWnd -------------------------------------------------------------------------------- */
struct CButtonWnd : CXWnd {
    /*0x11C*/ unsigned int pad_11C[(0x128 - 0x11C) / 4];
    /*0x128*/ bool Checked;

    // EXTERNAL: TITANIUM 0x005BB140 CButtonWnd::SetCheck
    void SetCheck(bool checked);
};

/* ---- CStmlWnd : CXWnd ---------------------------------------------------------------------------------- */
struct CStmlWnd : CXWnd {
    // EXTERNAL: TITANIUM 0x005A8B00 CStmlWnd::SetSTMLText
    void SetSTMLText(CXStr text, bool flag, SLinkInfo* link);   /* ret 0xC */
};

/* ---- CSidlScreenWnd : CXWnd (size 0x15C; layout per MQ2 _CSIDLWND) ------------------------------------- */
struct CSidlScreenWnd : CXWnd {
    /*0x11C*/ CXStr* SidlText;
    /*0x120*/ CXStr* SidlScreen;
    /*0x124*/ void* SidlPiece;
    /*0x128*/ unsigned int pad_128[(0x13C - 0x128) / 4];
    /*0x13C*/ int EnableINIStorage;
    /*0x140*/ CXStr* INIStorageName;
    /*0x144*/ unsigned int pad_144[(0x15C - 0x144) / 4];

    // EXTERNAL: TITANIUM 0x005A3850 ??0CSidlScreenWnd@@QAE@PAUCXWnd@@PAUCXStr@@HHPAD@Z
    CSidlScreenWnd(CXWnd* parent, CXStr* screen, int flags, int iniVersion, char* blockName);  /* ret 0x14 */
    // EXTERNAL: TITANIUM 0x005A3900 ??0CSidlScreenWnd@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    CSidlScreenWnd(CXWnd* parent, const CXStr& screen);   /* ret 8; MQ2 says CXStr by value, but every derived
        ctor (0x00547C3D, 0x0054EFB5, ...) builds the CXStr in its own frame, passes its address and frees it */
    // EXTERNAL: TITANIUM 0x005A3100 ??1CSidlScreenWnd@@QAE@XZ
    ~CSidlScreenWnd();                                                          /* virtual slot */
    // EXTERNAL: TITANIUM 0x005A1880 CSidlScreenWnd::OnShow
    int OnShow();                                                               /* virtual slot */
    // EXTERNAL: TITANIUM 0x005A2230 CSidlScreenWnd::WndNotification
    int WndNotification(CXWnd* sender, unsigned int message, void* data);       /* virtual slot */
    // EXTERNAL: TITANIUM 0x005A25B0 CSidlScreenWnd::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A1E10 CSidlScreenWnd::GetChildItem
    CXWnd* GetChildItem(const CXStr& name);       /* ret 4 (MQ2: GetChildItem(CXStr&) const) */
    // EXTERNAL: TITANIUM 0x005A1EF0 CSidlScreenWnd::LoadIniListWnd
    void LoadIniListWnd(CListWnd* list, char* prefix);
    // EXTERNAL: TITANIUM 0x005A1D40 CSidlScreenWnd::EnableIniStorage
    void EnableIniStorage(int enable, char* name);
    // EXTERNAL: TITANIUM 0x005A1890 CSidlScreenWnd::StoreIniInfo
    void StoreIniInfo();                                                        /* virtual slot */
    // EXTERNAL: TITANIUM 0x005A2660 CSidlScreenWnd::LoadIniInfo
    void LoadIniInfo();                                                         /* virtual slot */
};

/* ---- CXWndManager (pinstCXWndManager) ------------------------------------------------------------------ */
struct CXWndManager {
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManager::GetKeyboardFlags
    unsigned int GetKeyboardFlags() const;
    // EXTERNAL: TITANIUM 0x005B0940 CXWndManager::BringWndToTop
    void BringWndToTop(CXWnd* wnd, bool flag);                                  /* ret 8 */
};

/* ---- 0x00548460 "CConfirmationDialog::Activate" (first-pass name list, mac_chain medium) -------------------
 * ret 0x1C = 7 arguments. Its `this` is *pinstCConfirmationDialog (0x00991E44), but it is not the
 * 0x188-byte CConfirmationDialog window (ctor 0x00547C3D): it holds two ArrayClass2-style tables
 * (+0x08 mask, +0x0C shift, +0x10 blocks; +0x28/+0x2C/+0x30 a second one), forwards arguments 1..6 to
 * vtable slot 0x120 of the dialog it picks (arguments 1 and 7 pick it, via 0x005482D4) and returns that
 * dialog. Real class name unknown, hence _guess. Known call (0x00401BEF):
 * Activate(pEverQuest ? (char*)pEverQuest + 8 : 0, 0x82, pStringTable->getString(0x1447, 0), 0, 45000, 0, 0). */
struct CConfirmationDialogPool_guess {
    // EXTERNAL: TITANIUM 0x00548460 CConfirmationDialogPool_guess::Activate
    void* Activate(void* parent, int type, char* text, int a4, int timeoutMs, int a6, int a7);
};
#define pConfirmationDialogPool_guess EQ_GLOBAL(CConfirmationDialogPool_guess*, 0x00991E44)

/* ---- free functions ------------------------------------------------------------------------------------
 * SendMessage 0x004912B1 (MQ2 __SendMessage, fEQSendMessage(PVOID,DWORD,PVOID,DWORD,BOOL)): __cdecl,
 * 5 arguments, C++ linkage (game code may throw). Named EQSendMessage because <windows.h> defines
 * SendMessage as a macro. The definition (tu_062) reads `wait` as a byte (`mov al,[ebp+18h]`; nonzero = send
 * flag 4) and returns 1 when sent, 0 otherwise (`mov al,1` / `xor al,al`). */
// EXTERNAL: TITANIUM 0x004912B1 EQSendMessage
char __cdecl EQSendMessage(void* connection, unsigned long opcode, const void* data, unsigned long size, char wait);

#endif /* TITANIUM_CORE_DECLS_H */
