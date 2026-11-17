/* Layouts of eqgame.exe (Titanium) classes: sizes pinned by the binary, checked at compile time.
 *
 * Sizes come from `push size; call operator new` before each constructor. Fields are named only where
 * MQ2Emu's Titanium EQData.h / EQUIStructs.h agree with offsets the queue's functions use; everything
 * else is padding (`pad_<offset>`). Field types are MQ2's
 * (BYTE = unsigned char, DWORD = unsigned int, FLOAT = float): if movsx/movzx or fld/mov in the original
 * disagrees, the field is wrong for that use; say so in your note rather than casting around it.
 *
 * Like core_decls.h, these are non-polymorphic layout views (the vtable pointer is padding or a field at
 * +0). The window classes only pin each class's size on top of CSidlScreenWnd (0x15C): use them for
 * sizeof/new and as the base of a local class that adds the members you need; they are not the real
 * ctor's class. Two names with one size are both listed; that can mean one first-pass ctor name is off.
 *
 * Including this file includes core_decls.h (and eqaddr.h).
 */
#ifndef TITANIUM_TYPES_H
#define TITANIUM_TYPES_H

#include "titanium/core_decls.h"

/* Compile-time size check (VC7.1 has no static_assert): a negative array size fails the build. */
#define TITANIUM_SIZE_CAT(a, b) a##b
#define TITANIUM_SIZE(type, size) \
    typedef char TITANIUM_SIZE_CAT(titanium_size_check_, type)[(sizeof(type) == (size)) ? 1 : -1]

/* ---- EQPlayer (MQ2 SPAWNINFO), 0x348 -----------------------------------------------------------------
 * new 0x348 at 0x004554E5, 0x00455710, 0x00457F32, 0x004AA92B, then ctor 0x004850A0 (matched, tu_053;
 * dtor 0x004849B2 matched too). There is NO vtable: the ctor stores the byte 3 at +0. Members with
 * constructors (proven by the ctor): four 0x38-byte motion blocks at +0x30/+0x68/+0xB0/+0xE8 (inline ctor
 * -> Reset 0x004519AC) and an ArrayClass2-style table at +0x328 (ctor 0x0047C3AF(0x20), cleanup 0x004B73EE,
 * the only member destroyed by the dtor). This view keeps them as plain fields (MQ2 names for the first
 * motion block). Type notes from the ctor: +0x50..+0x5C and +0x22C are stored with fldz/fstp (float; MQ2
 * says DWORD for +0x54/+0x58/+0x22C); Race is compared with jge (signed; MQ2 DWORD); Levitate is written as
 * a dword (MQ2 BYTE); +0x204 is copied as one dword from the character (MQ2 WORD Zone + WORD Instance). */
struct EQPlayer {
    /*0x000*/ unsigned char field_000;    /* = 3 in the ctor (MQ2 Unknown0x0) */
    /*0x001*/ unsigned char pad_001[0x23];/* MQ2 Lastname[0x27] would overlap the float at +0x24 */
    /*0x024*/ float field_024;            /* 1.0f */
    /*0x028*/ float field_028;            /* 1.0f */
    /*0x02C*/ float field_02C;            /* 1.0f */
    /*0x030*/ float Y;                    /* motion block 1 (+0x30, 0x38 bytes): Y, X, Z (inline Set) */
    /*0x034*/ float X;
    /*0x038*/ float Z;                    /* 9.0f for a new spawn */
    /*0x03C*/ float SpeedY;               /* SpeedY, SpeedX, SpeedZ (second inline Set) */
    /*0x040*/ float SpeedX;
    /*0x044*/ float SpeedZ;
    /*0x048*/ float SpeedRun;
    /*0x04C*/ float Heading;
    /*0x050*/ float field_50;
    /*0x054*/ float field_54;
    /*0x058*/ float field_58;
    /*0x05C*/ float CameraAngle;          /* MQ2 CameraAngle; set from the float at 0x00923D20 */
    /*0x060*/ unsigned int pad_060[(0x068 - 0x060) / 4];
    /*0x068*/ unsigned int motion_068[0x38 / 4];  /* motion block 2 */
    /*0x0A0*/ unsigned int pad_0A0[(0x0B0 - 0x0A0) / 4];
    /*0x0B0*/ float Y2;                   /* motion block 3 (MQ2 Y2 .. Heading2) */
    /*0x0B4*/ float X2;
    /*0x0B8*/ float Z2;
    /*0x0BC*/ float SpeedY2;
    /*0x0C0*/ float SpeedX2;
    /*0x0C4*/ float SpeedZ2;
    /*0x0C8*/ float SpeedRun2;
    /*0x0CC*/ float Heading2;
    /*0x0D0*/ unsigned int pad_0D0[(0x0E8 - 0x0D0) / 4];
    /*0x0E8*/ unsigned int motion_0E8[0x38 / 4];  /* motion block 4 */
    /*0x120*/ char Name[0x40];            /* SetName 0x0047C3EF; compared with the character name */
    /*0x160*/ char DisplayedName[0x40];
    /*0x1A0*/ float boundingRadius_01a0_guess;
    /*0x1A4*/ unsigned int field_1A4;
    /*0x1A8*/ void* pActorInfo;           /* hottest field (389 uses); new 0x10C0, ctor 0x0048F023 */
    /*0x1AC*/ unsigned int field_1AC;
    /*0x1B0*/ unsigned char CanFindLocation;
    /*0x1B1*/ unsigned char Sneak;
    /*0x1B2*/ unsigned char Linkdead;
    /*0x1B3*/ unsigned char field_1B3;
    /*0x1B4*/ unsigned char LFG;
    /*0x1B5*/ unsigned char field_1B5;
    /*0x1B6*/ unsigned char IsABoat;
    /*0x1B7*/ unsigned char field_1B7;
    /*0x1B8*/ unsigned int pad_1B8[(0x204 - 0x1B8) / 4];
    /*0x204*/ unsigned short Zone;
    /*0x206*/ unsigned short Instance;
    /*0x208*/ void* field_208;            /* polymorphic; `delete` (virtual dtor) in the EQPlayer dtor */
    /*0x20C*/ unsigned int pad_20C[(0x214 - 0x20C) / 4];
    /*0x214*/ EQPlayer* pNext;
    /*0x218*/ void* pCharInfo;            /* the EQ_PC's +0xC280 base when this is the player */
    /*0x21C*/ unsigned int field_21C;
    /*0x220*/ EQPlayer* pPrev;            /* list head 0x00905CC4 */
    /*0x224*/ unsigned int pad_224;
    /*0x228*/ float field_228;            /* 3.0f */
    /*0x22C*/ float stepHeight_022c_guess;
    /*0x230*/ float RunSpeed;             /* 0.7f (1.4f for race 0xD8) */
    /*0x234*/ float eyeHeight_0234_guess;  /* 5.5f */
    /*0x238*/ float heightOffset_0238_guess;
    /*0x23C*/ float AvatarHeight;         /* -1.0f */
    /*0x240*/ float WalkSpeed;
    /*0x244*/ unsigned char Type;
    /*0x245*/ unsigned char HairColor;    /* +0x245..+0x24A = 0xFF in the ctor */
    /*0x246*/ unsigned char BeardColor;
    /*0x247*/ unsigned char eyeColor1_0247_guess;
    /*0x248*/ unsigned char Eyes;
    /*0x249*/ unsigned char Eyes2;
    /*0x24A*/ unsigned char BeardType;
    /*0x24B*/ unsigned char Holding;
    /*0x24C*/ unsigned char Level;
    /*0x24D*/ unsigned char FaceHair;
    /*0x24E*/ unsigned char Gender;
    /*0x24F*/ unsigned char PvPFlag;
    /*0x250*/ unsigned char HideMode;
    /*0x251*/ unsigned char StandState;   /* 100 */
    /*0x252*/ unsigned char Class;
    /*0x253*/ unsigned char Light;
    /*0x254*/ unsigned char InNonPCRaceIllusion;  /* 0xFF */
    /*0x255*/ unsigned char helm_0255_guess;    /* 0xFF */
    /*0x256*/ unsigned char GM;
    /*0x257*/ unsigned char field_257;
    /*0x258*/ unsigned int SpawnID;       /* unsigned: dtor tests 0 < id < 3000 with jbe/jae */
    /*0x25C*/ unsigned int MasterID;
    /*0x260*/ int Race;
    /*0x264*/ unsigned int Anon;
    /*0x268*/ unsigned int field_268;
    /*0x26C*/ unsigned int AFK;
    /*0x270*/ unsigned int BodyType;      /* 1 */
    /*0x274*/ int HPCurrent;              /* 50 */
    /*0x278*/ unsigned int pad_278[(0x280 - 0x278) / 4];
    /*0x280*/ unsigned int Deity;
    /*0x284*/ unsigned int HPMax;         /* 50 */
    /*0x288*/ unsigned int GuildID;       /* -1 */
    /*0x28C*/ int Levitate;
    /*0x290*/ unsigned int pad_290[(0x328 - 0x290) / 4];
    /*0x328*/ unsigned int table_328[0x1C / 4];   /* ArrayClass2: count, alloc, mask, shift, blocks, ?, flag */
    /*0x344*/ int tableCursor_344;
};

/* ---- EQ_PC, 0xC4D0 (new at 0x004AA92B, 0x004ACF33 x3, 0x004EF965; ctor 0x004BF2A7 matched, tu_080) -------
 * The object behind pCharData (0x00905D00). Its ctor takes only the hidden most-derived flag (ret 4, not
 * MQ2's EQ_PC*). EQ_PC has one base (ctor 0x004BE859) whose two bases sit at +0 (vbptr at +8, vbtable
 * {-8, 0xC37C}) and +0xC280 (MQ2 pCharData1 / EQ_Character1; vbptr at +0xC284, vbtable {-4, 0x100}); both
 * share one virtual base at +0xC384 (ctor 0x005FB0D0), with a vtordisp at +0xC380. The GetCharInfo2 list
 * (0x005EC220) is at +4 of that virtual base. Code reaching it from an EQ_PC pointer goes through the vbptr
 * (`mov ecx,[eax+8]; mov ecx,[ecx+4]; lea ecx,[ecx+eax+0xC]`), so the 1,311 `lea ecx,[eax+4]` sites that
 * core_decls.h's EQ_Character view of pCharData is based on deserve a second look. Non-polymorphic view:
 * the vtable/vbtable pointers are plain fields. */
struct EQ_CharacterBase_guess {           /* the virtual base, 0x14C */
    /*0x000*/ void* vftable;              /* 0x0064BA30 in an EQ_PC; slot 1 is the deleting dtor */
    /*0x004*/ void* list;                 /* GetCharInfo2: nodes {key, value, ?, next@0xC} */
    /*0x008*/ int key;
    /*0x00C*/ unsigned int pad_00C[(0x02C - 0x00C) / 4];
    /*0x02C*/ float Y;                    /* 0.0f, 0.0f, 9.0f (inline Set) */
    /*0x030*/ float X;
    /*0x034*/ float Z;
    /*0x038*/ float Heading;
    /*0x03C*/ char Name[0x40];            /* compared with EQPlayer::Name in the EQPlayer ctor */
    /*0x07C*/ char text_07C[0x20];        /* fixed text, set with 0x00454EA9("") */
    /*0x09C*/ unsigned int pad_09C[(0x0FC - 0x09C) / 4];
    /*0x0FC*/ unsigned char field_0FC;
    /*0x0FD*/ unsigned char pad_0FD[3];
    /*0x100*/ unsigned int ZoneInstance;  /* copied to EQPlayer +0x204 */
    /*0x104*/ unsigned char field_104;    /* 100 */
    /*0x105*/ unsigned char pad_105[0x14C - 0x105];
};

struct EQ_PC {
    /*0x0000*/ void* vftable;             /* 0x0064BA90 */
    /*0x0004*/ unsigned int field_0004;
    /*0x0008*/ int* vbtable;              /* 0x0064BAA8 */
    /*0x000C*/ unsigned int pad_000C[(0x0D30 - 0x000C) / 4];
    /*0x0D30*/ unsigned int field_0D30[2];/* cleared by 0x004BC5D2 */
    /*0x0D38*/ unsigned int pad_0D38[(0x0E18 - 0x0D38) / 4];
    /*0x0E18*/ int field_0E18;            /* = 0x00576E80() */
    /*0x0E1C*/ unsigned int pad_0E1C[(0xC280 - 0x0E1C) / 4];
    /*0xC280*/ void* vftable_C280;        /* 0x0064BA78; second base (MQ2 pCharData1) */
    /*0xC284*/ int* vbtable_C284;         /* 0x0064BAA0 */
    /*0xC288*/ EQPlayer* pSpawn;          /* the EQPlayer ctor stores itself here */
    /*0xC28C*/ unsigned char field_C28C;  /* 1 */
    /*0xC28D*/ unsigned char pad_C28D[3];
    /*0xC290*/ unsigned int field_C290[13];   /* 0 */
    /*0xC2C4*/ unsigned int pad_C2C4;
    /*0xC2C8*/ unsigned int field_C2C8;   /* 0 */
    /*0xC2CC*/ unsigned int pad_C2CC[(0xC348 - 0xC2CC) / 4];
    /*0xC348*/ unsigned char field_C348;
    /*0xC349*/ unsigned char pad_C349[3];
    /*0xC34C*/ unsigned int pad_C34C[(0xC378 - 0xC34C) / 4];
    /*0xC378*/ int field_C378;            /* 1 */
    /*0xC37C*/ unsigned int pad_C37C;
    /*0xC380*/ int vtordisp_C380;
    /*0xC384*/ EQ_CharacterBase_guess Character;   /* the virtual base */
};

/* ---- EqSoundManager, 0xBAFC (ctor 0x0044CA8F matched, tu_037: EqSoundManager(bool, bool, SpeakerType)) ---- */
struct EqSoundManager {
    /*0x0000*/ void* pBank;               /* new 0x4020, ctor 0x004C5E4D(device, listener) */
    /*0x0004*/ void* pDevice;             /* new 0x4AC, ctor 0x004C6B3A(0x10, 6, 1, 22050/44100, 0x10, 1, speaker) */
    /*0x0008*/ void* pMixer;              /* new 0x14, ctor 0x004C603C(device) */
    /*0x000C*/ void* pListener;           /* new 0x10, ctor 0x004C60FD */
    /*0x0010*/ unsigned int pad_0010[(0x0024 - 0x0010) / 4];
    /*0x0024*/ unsigned int field_0024;
    /*0x0028*/ unsigned int field_0028;
    /*0x002C*/ unsigned char Disabled;    /* first ctor argument */
    /*0x002D*/ unsigned char pad_002D[3];
    /*0x0030*/ int field_0030;            /* 16 */
    /*0x0034*/ void* Callbacks[1000];
    /*0x0FD4*/ int CallbackCount;
    /*0x0FD8*/ void* FilterA;
    /*0x0FDC*/ void* FilterB;
    /*0x0FE0*/ int field_0FE0;            /* 2 */
    /*0x0FE4*/ int field_0FE4;            /* 12 */
    /*0x0FE8*/ int field_0FE8;            /* 19 */
    /*0x0FEC*/ float field_0FEC;          /* 1.0f */
    /*0x0FF0*/ float field_0FF0;          /* 1.0f */
    /*0x0FF4*/ unsigned char field_0FF4[3];
    /*0x0FF7*/ unsigned char pad_0FF7;
    /*0x0FF8*/ int field_0FF8;
    /*0x0FFC*/ int Mode;
    /*0x1000*/ unsigned char field_1000;
    /*0x1001*/ unsigned char pad_1001[3];
    /*0x1004*/ unsigned int Entries[5000 * 2];    /* 8-byte entries, memset 0x9C40 */
    /*0xAC44*/ unsigned char field_AC44[0x80];
    /*0xACC4*/ void* pArchives;           /* new 1, ctor 0x00577750; snd1..17.pfs loaded via 0x00579970 */
    /*0xACC8*/ unsigned int pad_ACC8[(0xBADC - 0xACC8) / 4];
    /*0xBADC*/ unsigned int table_BADC[4];    /* member, ctor 0x00435652(0x100) */
    /*0xBAEC*/ unsigned int list_BAEC[3];     /* member, ctor 0x0042610D */
    /*0xBAF8*/ int field_BAF8;            /* 4999 */
};

/* ---- windows: size on top of CSidlScreenWnd 0x15C (ctor after `push size; call operator new`) -------- */
struct CCastingWnd : CSidlScreenWnd {  /* = base size */
};
struct CBreathWnd : CSidlScreenWnd {  /* same size as CPlayerNotesWnd */
    /*0x15C*/ unsigned int pad_15C[(0x160 - 0x15C) / 4];
};
struct CPlayerNotesWnd : CSidlScreenWnd {  /* same size as CBreathWnd */
    /*0x15C*/ unsigned int pad_15C[(0x160 - 0x15C) / 4];
};
struct CExploreModeWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x164 - 0x15C) / 4];
};
struct CSkillsSelectWnd : CSidlScreenWnd {  /* same size as CFeedbackWnd */
    /*0x15C*/ unsigned int pad_15C[(0x16C - 0x15C) / 4];
};
struct CFeedbackWnd : CSidlScreenWnd {  /* same size as CSkillsSelectWnd */
    /*0x15C*/ unsigned int pad_15C[(0x16C - 0x15C) / 4];
};
struct CAlarmWnd : CSidlScreenWnd {  /* same size as CLoadskinWnd, CTargetWnd, CVideoModesWnd */
    /*0x15C*/ unsigned int pad_15C[(0x170 - 0x15C) / 4];
};
struct CLoadskinWnd : CSidlScreenWnd {  /* same size as CAlarmWnd, CTargetWnd, CVideoModesWnd */
    /*0x15C*/ unsigned int pad_15C[(0x170 - 0x15C) / 4];
};
struct CTargetWnd : CSidlScreenWnd {  /* same size as CAlarmWnd, CLoadskinWnd, CVideoModesWnd */
    /*0x15C*/ unsigned int pad_15C[(0x170 - 0x15C) / 4];
};
struct CVideoModesWnd : CSidlScreenWnd {  /* same size as CAlarmWnd, CLoadskinWnd, CTargetWnd */
    /*0x15C*/ unsigned int pad_15C[(0x170 - 0x15C) / 4];
};
struct CSkillsWnd : CSidlScreenWnd {  /* same size as CQuantityWnd */
    /*0x15C*/ unsigned int pad_15C[(0x174 - 0x15C) / 4];
};
struct CQuantityWnd : CSidlScreenWnd {  /* same size as CSkillsWnd */
    /*0x15C*/ unsigned int pad_15C[(0x174 - 0x15C) / 4];
};
struct CTextEntryWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x17C - 0x15C) / 4];
};
struct CPlayerWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x180 - 0x15C) / 4];
};
struct CCursorAttachment : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x184 - 0x15C) / 4];
};
struct CItemDisplayWnd : CSidlScreenWnd {  /* same size as CConfirmationDialog */
    /*0x15C*/ unsigned int pad_15C[(0x188 - 0x15C) / 4];
};
struct CConfirmationDialog : CSidlScreenWnd {  /* same size as CItemDisplayWnd; ctor 0x00547C3D matched */
    /*0x15C*/ CXWnd* TextOutput;
    /*0x160*/ CXWnd* YesButton;
    /*0x164*/ CXWnd* NoButton;
    /*0x168*/ CXWnd* Button_168;
    /*0x16C*/ CXWnd* OKButton;
    /*0x170*/ CXStr Text;
    /*0x174*/ int field_174;
    /*0x178*/ void* pAction;              /* its slot 0 is called with (value, kind, flags) */
    /*0x17C*/ int ActionValue;
    /*0x180*/ int Timeout;                /* -1: none */
    /*0x184*/ unsigned int Flags;
};
struct CRaidOptionsWnd : CSidlScreenWnd {  /* same size as CGiveWnd */
    /*0x15C*/ unsigned int pad_15C[(0x18C - 0x15C) / 4];
};
struct CGiveWnd : CSidlScreenWnd {  /* same size as CRaidOptionsWnd */
    /*0x15C*/ unsigned int pad_15C[(0x18C - 0x15C) / 4];
};
struct CBugReportWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1A8 - 0x15C) / 4];
};
struct CContainerWnd : CSidlScreenWnd {  /* new 0x1B4 at 0x004FA346; ctor 0x004FC9A4 matched ("ContainerWindow").
        Same size as CCastSpellWnd below: one of the two first-pass ctor names may be off. */
    /*0x15C*/ int field_15C;
    /*0x160*/ CXWnd* Slots[10];           /* ContainerSlot1..10 */
    /*0x188*/ CXWnd* CombineButton;
    /*0x18C*/ CXWnd* DoneButton;
    /*0x190*/ CXWnd* Icon;                /* its +0x16C gets DragAnim */
    /*0x194*/ CXWnd* InsertButton;
    /*0x198*/ CXWnd* RemoveButton;
    /*0x19C*/ CXWnd* DeleteButton;
    /*0x1A0*/ void* DragAnim;             /* copy of A_DragItem */
    /*0x1A4*/ CXWnd* Label;
    /*0x1A8*/ CListWnd* AugmentList;
    /*0x1AC*/ CXWnd* AugmentInfoLabel;
    /*0x1B0*/ unsigned char field_1B0;
    /*0x1B1*/ unsigned char field_1B1;    /* 1 */
    /*0x1B2*/ unsigned char pad_1B2[2];
};
struct CCastSpellWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1B4 - 0x15C) / 4];
};
struct CCompassWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1C0 - 0x15C) / 4];
};
struct CInspectWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1C4 - 0x15C) / 4];
};
struct CColorPickerWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1D0 - 0x15C) / 4];
};
struct CSocialEditWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1D8 - 0x15C) / 4];
};
struct CCharacterSelect : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x1FC - 0x15C) / 4];
};
struct CSelectorWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x220 - 0x15C) / 4];
};
struct CTradeWnd : CSidlScreenWnd {  /* ctor 0x0056982F matched */
    /*0x15C*/ unsigned int pad_15C[2];
    /*0x164*/ CXWnd* HisMoney[4];
    /*0x174*/ CXWnd* MyMoney[4];
    /*0x184*/ CXWnd* TradeButton;
    /*0x188*/ CXWnd* CancelButton;
    /*0x18C*/ CXWnd* HisName;
    /*0x190*/ CXWnd* MyName;
    /*0x194*/ CXWnd* TradeSlots[16];
    /*0x1D4*/ unsigned int pad_1D4[(0x234 - 0x1D4) / 4];
    /*0x234*/ unsigned char pad_234[2];
    /*0x236*/ unsigned char field_236;
    /*0x237*/ unsigned char pad_237;
};
struct CInventoryWnd : CSidlScreenWnd {  /* same size as CChatWindow; ctor 0x00516E9A matched */
    /* Real class: CSidlScreenWnd, the notifier interface (vtable 0x0063FD9C) at +0x15C and a one-slot
     * interface (vtable 0x006563B8) at +0x160; here those vtable pointers are plain fields. */
    /*0x15C*/ void* vftable_15C;
    /*0x160*/ void* vftable_160;
    /*0x164*/ unsigned int pad_164[2];
    /*0x16C*/ CXWnd* Money[4];
    /*0x17C*/ CXWnd* InvSlots[30];
    /*0x1F4*/ CXWnd* NextLevelLabel;
    /*0x1F8*/ CXWnd* ExpGauge;
    /*0x1FC*/ CXWnd* AltAdvLabel;
    /*0x200*/ CXWnd* AltAdvGauge;
    /*0x204*/ CXWnd* DestroyButton;
    /*0x208*/ CXWnd* SkillsButton;
    /*0x20C*/ CXWnd* AltAdvButton;
    /*0x210*/ CXWnd* DoneButton;
    /*0x214*/ CXWnd* FacePickButton;
    /*0x218*/ CXWnd* TintingButton;
    /*0x21C*/ CXWnd* GoodPoints;
    /*0x220*/ CXWnd* EvilPoints;
    /*0x224*/ CXWnd* ReclaimButton;
    /*0x228*/ CXWnd* ClassAnim;           /* its +0x64 gets a new CTextureAnimation */
    /*0x22C*/ CXWnd* CharacterView;
    /*0x230*/ int field_230;              /* CDisplay (0x00905D24) +0x148 */
    /*0x234*/ int field_234;
    /*0x238*/ CListWnd* ItemList;         /* EI_ItemList */
    /*0x23C*/ CXWnd* ToggleButton;
    /*0x240*/ CXWnd* AllOnButton;
    /*0x244*/ CXWnd* AllOffButton;
    /*0x248*/ CListWnd* ProgressionList;
    /*0x24C*/ CXWnd* ProgressionInfo;
    /*0x250*/ CXWnd* InvPage;
    /*0x254*/ CXWnd* EIPage;
    /*0x258*/ CXWnd* AltCharProgPage;
    /*0x25C*/ CXWnd* Subwindows;
    /*0x260*/ int field_260;
    /*0x264*/ unsigned int pad_264;
};
struct CChatWindow : CSidlScreenWnd {  /* same size as CInventoryWnd */
    /*0x15C*/ unsigned int pad_15C[(0x268 - 0x15C) / 4];
};
struct CMapViewWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x274 - 0x15C) / 4];
};
struct CRaidWnd : CSidlScreenWnd {  /* ctor 0x0054EFB5 matched */
    /*0x15C*/ CListWnd* PlayerList;
    /*0x160*/ CXWnd* PlayerListLabel;
    /*0x164*/ CListWnd* NotInGroupPlayerList;
    /*0x168*/ CXWnd* NotInGroupPlayerListLabel;
    /*0x16C*/ CXWnd* PlayerCountLabel;
    /*0x170*/ CXWnd* LevelAverageLabel;
    /*0x174*/ CXWnd* InviteButton;
    /*0x178*/ CXWnd* DisbandButton;
    /*0x17C*/ CXWnd* AcceptButton;
    /*0x180*/ CXWnd* DeclineButton;
    /*0x184*/ CXWnd* MakeLeaderButton;
    /*0x188*/ CXWnd* OptionsButton;
    /*0x18C*/ CXWnd* AddLooterButton;
    /*0x190*/ CXWnd* RemoveLooterButton;
    /*0x194*/ CXWnd* DumpButton;
    /*0x198*/ CXWnd* MainAssistButton;
    /*0x19C*/ CXWnd* MarkNPCButton;
    /*0x1A0*/ CXWnd* pad_1A0;
    /*0x1A4*/ CXWnd* FindPCButton;
    /*0x1A8*/ CXWnd* LockButton;
    /*0x1AC*/ CXWnd* UnlockButton;
    /*0x1B0*/ CXWnd* RemoveLeaderButton;
    /*0x1B4*/ CXWnd* NoGroupButton;
    /*0x1B8*/ CXWnd* GroupButtons[12];    /* RAID_Group1Button .. RAID_Group12Button */
    /*0x1E8*/ CListWnd* NoteList;
    /*0x1EC*/ CXWnd* NoteEdit;            /* SetMaxChars 0x004D7EBC(0x3F) */
    /*0x1F0*/ CXWnd* NoteUpdateButton;
    /*0x1F4*/ CXWnd* MOTDViewer;
    /*0x1F8*/ CXWnd* MOTDInput;           /* SetMaxChars(0x3FF) */
    /*0x1FC*/ CXWnd* UpdateMOTDButton;
    /*0x200*/ unsigned int pad_200[(0x240 - 0x200) / 4];
    /*0x240*/ int field_240;
    /*0x244*/ unsigned int pad_244[(0x28C - 0x244) / 4];
    /*0x28C*/ unsigned char field_28C;
    /*0x28D*/ unsigned char pad_28D[3];
};
struct CSpellBookWnd : CSidlScreenWnd {  /* ctor 0x00558521 matched */
    /*0x15C*/ void* vftable_15C;          /* second base: the notifier interface (vtable 0x0063FD9C) */
    /*0x160*/ int field_160;
    /*0x164*/ unsigned int pad_164;
    /*0x168*/ int field_168;              /* -1 */
    /*0x16C*/ unsigned int pad_16C[2];
    /*0x174*/ int field_174;              /* -1 */
    /*0x178*/ unsigned int pad_178[3];
    /*0x184*/ int field_184;              /* -1 */
    /*0x188*/ int field_188;
    /*0x18C*/ unsigned char field_18C;
    /*0x18D*/ unsigned char pad_18D[3];
    /*0x190*/ unsigned int pad_190[(0x1BC - 0x190) / 4];
    /*0x1BC*/ int field_1BC;
    /*0x1C0*/ int field_1C0;              /* -1 */
    /*0x1C4*/ int field_1C4;              /* -1 */
    /*0x1C8*/ void* SpellIcons[16];       /* new CTextureAnimation copied from A_SpellIcons */
    /*0x208*/ void* SlotAnim;             /* A_SpellBookSlot */
    /*0x20C*/ CXWnd* SpellButtons[16];    /* SBW_Spell0..15 (their +0x16C gets SpellIcons[i]) */
    /*0x24C*/ CXWnd* PageDownButton;
    /*0x250*/ CXWnd* PageUpButton;
    /*0x254*/ CXWnd* MemPage0Button;
    /*0x258*/ CXWnd* MemPage1Button;
    /*0x25C*/ CXWnd* DoneButton;
    /*0x260*/ CXWnd* LeftPageNum;
    /*0x264*/ CXWnd* RightPageNum;
    /*0x268*/ CXWnd* SpellNames[16];      /* SBW_SpellName0..15 */
};
struct CMerchantWnd : CSidlScreenWnd {  /* ctor 0x00536D26 matched */
    /*0x15C*/ unsigned int pad_15C[2];
    /*0x164*/ void* Items[80];
    /*0x2A4*/ unsigned int pad_2A4[2];
    /*0x2AC*/ int field_2AC;
    /*0x2B0*/ unsigned char field_2B0;
    /*0x2B1*/ unsigned char pad_2B1[3];
    /*0x2B4*/ CXWnd* MerchantName;
    /*0x2B8*/ CXWnd* SelectedItemLabel;
    /*0x2BC*/ CXWnd* SelectedPriceLabel;
    /*0x2C0*/ CXWnd* SelectedItem;
    /*0x2C4*/ CXWnd* BuyButton;
    /*0x2C8*/ CXWnd* SellButton;
    /*0x2CC*/ CListWnd* ItemList;
    /*0x2D0*/ CXWnd* DoneButton;
};
struct CLootWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x2F0 - 0x15C) / 4];
};
struct CPetInfoWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x380 - 0x15C) / 4];
};
struct CNoteWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x56C - 0x15C) / 4];
};
struct CBazaarWnd : CSidlScreenWnd {  /* ctor 0x004E66C2 matched */
    /*0x15C*/ unsigned int pad_15C[(0x170 - 0x15C) / 4];
    /*0x170*/ CXWnd* StartButton;
    /*0x174*/ CXWnd* EndButton;
    /*0x178*/ CXWnd* ClearButton;
    /*0x17C*/ CXWnd* SetPriceButton;
    /*0x180*/ CXWnd* ListButton;
    /*0x184*/ CXWnd* pad_184;
    /*0x188*/ CXWnd* AddButton;
    /*0x18C*/ CXWnd* RemoveButton;
    /*0x190*/ CXWnd* Money[4];
    /*0x1A0*/ CXWnd* BazaarText;
    /*0x1A4*/ CXWnd* Slots[80];           /* BZR_BazaarSlot0..79 */
    /*0x2E4*/ unsigned int pad_2E4[(0x5F4 - 0x2E4) / 4];
    /*0x5F4*/ unsigned char field_5F4;
    /*0x5F5*/ unsigned char pad_5F5[3];
};
struct CBookWnd : CSidlScreenWnd {  /* same size as CFriendsWnd */
    /*0x15C*/ unsigned int pad_15C[(0x718 - 0x15C) / 4];
};
struct CFriendsWnd : CSidlScreenWnd {  /* same size as CBookWnd */
    /*0x15C*/ unsigned int pad_15C[(0x718 - 0x15C) / 4];
};
struct CTrainWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x7D4 - 0x15C) / 4];
};
struct COptionsWnd : CSidlScreenWnd {  /* same size as CBuffWindow */
    /*0x15C*/ unsigned int pad_15C[(0xAE8 - 0x15C) / 4];
};
struct CBuffWindow : CSidlScreenWnd {  /* same size as COptionsWnd */
    /*0x15C*/ unsigned int pad_15C[(0xAE8 - 0x15C) / 4];
};
struct CPetitionQWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0xB90 - 0x15C) / 4];
};
struct CGemsGameWnd : CSidlScreenWnd {  /* ctor 0x00506AE5 matched */
    /*0x15C*/ unsigned int pad_15C[(0xD88 - 0x15C) / 4];
    /*0xD88*/ unsigned int Color_D88;     /* 0xFF5242DE */
    /*0xD8C*/ unsigned int RowColors[10]; /* 0xFFDE2121 */
    /*0xDB4*/ int field_DB4;              /* 0xFF */
    /*0xDB8*/ int RowValues[10];          /* 234 - 21 * row */
    /*0xDE0*/ int GemValue_DE0;           /* from GGW_SpellGem +0x180 */
    /*0xDE4*/ int GemValue_DE4;           /* +0x184 */
    /*0xDE8*/ int GemWidth;               /* Location.right - left */
    /*0xDEC*/ int GemHeight;              /* Location.bottom - top */
    /*0xDF0*/ void* GemsAnim;             /* copy of A_SpellGems */
    /*0xDF4*/ int GemValue_DF4;           /* +0x19C */
    /*0xDF8*/ int GemValue_DF8;           /* +0x1A4 */
    /*0xDFC*/ CXWnd* StartButton;
    /*0xE00*/ CXWnd* DoneButton;
    /*0xE04*/ CXWnd* HighScores;          /* parent set to GameView */
    /*0xE08*/ CXWnd* ScoreHeader;
    /*0xE0C*/ CXWnd* WaveHeader;
    /*0xE10*/ CXWnd* HighNames[10];
    /*0xE38*/ CXWnd* HighScoreValues[10];
    /*0xE60*/ CXWnd* HighWaves[10];
    /*0xE88*/ CXWnd* GameOver;
    /*0xE8C*/ CXWnd* Instructions[3];
    /*0xE98*/ CXWnd* LargeWave;
    /*0xE9C*/ CXWnd* LargeWaveNbr;
    /*0xEA0*/ CXWnd* Paused;
    /*0xEA4*/ CXWnd* Wave;
    /*0xEA8*/ CXWnd* WaveNbr;
    /*0xEAC*/ CXWnd* Score;
    /*0xEB0*/ CXWnd* ScoreNbr;
    /*0xEB4*/ CXWnd* Next;
    /*0xEB8*/ CXWnd* Special;
    /*0xEBC*/ CXWnd* GameView;
};
struct CAAWnd : CSidlScreenWnd {  /* same size as CGroupWnd */
    /*0x15C*/ unsigned int pad_15C[(0x1384 - 0x15C) / 4];
};
struct CGroupWnd : CSidlScreenWnd {  /* same size as CAAWnd */
    /*0x15C*/ unsigned int pad_15C[(0x1384 - 0x15C) / 4];
};
struct CSoulmarkWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x18F4 - 0x15C) / 4];
};
struct CBazaarSearchWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x3D58 - 0x15C) / 4];
};
struct CTrackingWnd : CSidlScreenWnd {
    /*0x15C*/ unsigned int pad_15C[(0x401C - 0x15C) / 4];
};

/* ---- size checks ----------------------------------------------------------------------------------- */
TITANIUM_SIZE(CStrRep, 0x18);
TITANIUM_SIZE(CXStr, 0x4);
TITANIUM_SIZE(CXRect, 0x10);
TITANIUM_SIZE(CEverQuest, 0x3A1C8);
TITANIUM_SIZE(EQ_Character, 0xC);
TITANIUM_SIZE(EQ_PC, 0xC4D0);
TITANIUM_SIZE(EQ_CharacterBase_guess, 0x14C);
TITANIUM_SIZE(EqSoundManager, 0xBAFC);
TITANIUM_SIZE(EQPlayer, 0x348);
TITANIUM_SIZE(CXWnd, 0x11C);
TITANIUM_SIZE(CListWnd, 0x140);
TITANIUM_SIZE(CButtonWnd, 0x12C);
TITANIUM_SIZE(CSidlScreenWnd, 0x15C);
TITANIUM_SIZE(CCastingWnd, 0x15C);
TITANIUM_SIZE(CBreathWnd, 0x160);
TITANIUM_SIZE(CPlayerNotesWnd, 0x160);
TITANIUM_SIZE(CExploreModeWnd, 0x164);
TITANIUM_SIZE(CSkillsSelectWnd, 0x16C);
TITANIUM_SIZE(CFeedbackWnd, 0x16C);
TITANIUM_SIZE(CAlarmWnd, 0x170);
TITANIUM_SIZE(CLoadskinWnd, 0x170);
TITANIUM_SIZE(CTargetWnd, 0x170);
TITANIUM_SIZE(CVideoModesWnd, 0x170);
TITANIUM_SIZE(CSkillsWnd, 0x174);
TITANIUM_SIZE(CQuantityWnd, 0x174);
TITANIUM_SIZE(CTextEntryWnd, 0x17C);
TITANIUM_SIZE(CPlayerWnd, 0x180);
TITANIUM_SIZE(CCursorAttachment, 0x184);
TITANIUM_SIZE(CItemDisplayWnd, 0x188);
TITANIUM_SIZE(CConfirmationDialog, 0x188);
TITANIUM_SIZE(CRaidOptionsWnd, 0x18C);
TITANIUM_SIZE(CGiveWnd, 0x18C);
TITANIUM_SIZE(CBugReportWnd, 0x1A8);
TITANIUM_SIZE(CCastSpellWnd, 0x1B4);
TITANIUM_SIZE(CContainerWnd, 0x1B4);
TITANIUM_SIZE(CCompassWnd, 0x1C0);
TITANIUM_SIZE(CInspectWnd, 0x1C4);
TITANIUM_SIZE(CColorPickerWnd, 0x1D0);
TITANIUM_SIZE(CSocialEditWnd, 0x1D8);
TITANIUM_SIZE(CCharacterSelect, 0x1FC);
TITANIUM_SIZE(CSelectorWnd, 0x220);
TITANIUM_SIZE(CTradeWnd, 0x238);
TITANIUM_SIZE(CInventoryWnd, 0x268);
TITANIUM_SIZE(CChatWindow, 0x268);
TITANIUM_SIZE(CMapViewWnd, 0x274);
TITANIUM_SIZE(CRaidWnd, 0x290);
TITANIUM_SIZE(CSpellBookWnd, 0x2A8);
TITANIUM_SIZE(CMerchantWnd, 0x2D4);
TITANIUM_SIZE(CLootWnd, 0x2F0);
TITANIUM_SIZE(CPetInfoWnd, 0x380);
TITANIUM_SIZE(CNoteWnd, 0x56C);
TITANIUM_SIZE(CBazaarWnd, 0x5F8);
TITANIUM_SIZE(CBookWnd, 0x718);
TITANIUM_SIZE(CFriendsWnd, 0x718);
TITANIUM_SIZE(CTrainWnd, 0x7D4);
TITANIUM_SIZE(COptionsWnd, 0xAE8);
TITANIUM_SIZE(CBuffWindow, 0xAE8);
TITANIUM_SIZE(CPetitionQWnd, 0xB90);
TITANIUM_SIZE(CGemsGameWnd, 0xEC0);
TITANIUM_SIZE(CAAWnd, 0x1384);
TITANIUM_SIZE(CGroupWnd, 0x1384);
TITANIUM_SIZE(CSoulmarkWnd, 0x18F4);
TITANIUM_SIZE(CBazaarSearchWnd, 0x3D58);
TITANIUM_SIZE(CTrackingWnd, 0x401C);

#endif /* TITANIUM_TYPES_H */
