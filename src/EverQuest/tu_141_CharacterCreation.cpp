// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 141: a hint from compare/tumap.py.
// The character creation window, CCharacterCreation_guess (SIDL screen "CharacterCreation"; tu_029 calls
// the constructor 0x4EF965 as CharacterCreation_guess). CCharacterCreationView_guess, Updated_guess,
// EntryLists_guess, LanguageOwner_guess, CreationScreen_guess and Owner_004ee978_guess are views of that
// one object. +0x160 is the new character's data; g_systemSource_guess (0x905CE4) is pLocalPlayer, the model.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* destination, const char* format, ...);

struct EntryLists_guess {
    char pad_0000[0x1ac];
    int first_01ac[15];
    int second_01e8[16];

    int FindRaceButton_guess(int value);
    int FindClassButton_guess(int value);
};

struct Stamped_guess {
    char pad_0000[0x5d];
    unsigned char flag_005d;
};

struct Updated_guess {
    char pad_0000[0x244];
    int when_0244;
    int pair_0248[2];              // 0x248
    int field_0250;                // 0x250
    int field_0254;                // 0x254
    int field_0258;                // 0x258
    int field_025c;                // 0x25c
    int field_0260;                // 0x260
    int field_0264;                // 0x264
    int field_0268;                // 0x268
    int field_026c;                // 0x26c
    int field_0270;                // 0x270
    int field_0274;                // 0x274
    int field_0278;                // 0x278
    int field_027c;                // 0x27c
    int field_0280;                // 0x280
    Stamped_guess* stamped_0284;   // 0x284
    int field_0288;                // 0x288
    int field_028c;                // 0x28c
    int field_0290;                // 0x290
    int array_0294[15];            // 0x294
    int array_02d0[16];            // 0x2d0
    int array_0310[7];             // 0x310
    int array_032c[7];             // 0x32c
    int array_0348[7];             // 0x348
    int array_0364[7];             // 0x364
    int field_0380;                // 0x380
    int field_0384;                // 0x384
    int field_0388;                // 0x388
    int field_038c;                // 0x38c
    int field_0390;                // 0x390
    int array_0394[17];            // 0x394
    int array_03d8[15];            // 0x3d8
    int field_0414;                // 0x414

    // EXTERNAL: TITANIUM 0x005A0E50 Updated_guess::OnProcessFrame
    void OnProcessFrame();
    void Update_guess();
    void Clear_guess();
};

struct NameInput_guess {
    char pad_0000[0x128];
    int field_0128;
    int field_012c;
    char pad_0130[0x100];
    int field_0230;
};

struct CreationScreen_guess : CSidlScreenWnd {
    char pad_015c[0xec];
    CXWnd* screens_0248[2];
    CXWnd* title_0250;
    CXWnd* screen0a_0254;
    CXWnd* screen0b_0258;
    CXWnd* screen0c_025c;
    CXWnd* screen1_0260[4];
    CXWnd* creationHelp_0270;
    CXWnd* helpButton_0274;
    CXWnd* backButton_0278;
    CXWnd* nextButton_027c;
    CButtonWnd* tutorialButton_0280;
    CXWnd* getNameButton_0284;
    CXWnd* faceButton_0288;
    CXWnd* maleButton_028c;
    CXWnd* femaleButton_0290;
    CXWnd* raceButtons_0294[15];
    CXWnd* classButtons_02d0[16];
    CXWnd* statUpButtons_0310[7];
    CXWnd* statDownButtons_032c[7];
    CXWnd* statDisplayButtons_0348[7];
    CXWnd* statButtons_0364[7];
    CXWnd* pointsButton_0380;
    CXWnd* pointsDisplayButton_0384;
    NameInput_guess* nameInput_0388;
    CXWnd* stageHelp_038c;
    CXWnd* stageTitle_0390;
    CXWnd* deityButtons_0394[17];
    CXWnd* cityButtons_03d8[15];
    CXWnd* stageHelp_0414;
    char pad_0418[8];
    unsigned char tutorialFlag_0420;

    void Initialize_guess();
};

struct Source_guess {
    // EXTERNAL: TITANIUM 0x005ED6D0 Source_guess::GetFirst_guess
    unsigned char GetFirst_guess();
    // EXTERNAL: TITANIUM 0x005ED5D0 Source_guess::GetSecond_guess
    unsigned char GetSecond_guess();
    // EXTERNAL: TITANIUM 0x005ED690 Source_guess::GetThird_guess
    unsigned char GetThird_guess();
    // EXTERNAL: TITANIUM 0x005ED590 Source_guess::GetFourth_guess
    unsigned char GetFourth_guess();
    // EXTERNAL: TITANIUM 0x005ED610 Source_guess::GetFifth_guess
    unsigned char GetFifth_guess();
    // EXTERNAL: TITANIUM 0x005ED650 Source_guess::GetSixth_guess
    unsigned char GetSixth_guess();

    char pad_0000[8];
    struct VBTable* nested_0008;
};

struct SkillOwner_guess {
    // EXTERNAL: TITANIUM 0x00419E83 SkillOwner_guess::CanWorship_guess
    char CanWorship_guess(int skill, int column, int row);
    // EXTERNAL: TITANIUM 0x00419DFD SkillOwner_guess::ClassMin_guess
    unsigned char ClassMin_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x00417355 SkillOwner_guess::FUN_00417355_guess
    unsigned char FUN_00417355_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x00416E9C SkillOwner_guess::CheckClass_guess
    bool CheckClass_guess(int first, int second);
};

struct Destination_guess {
    // EXTERNAL: TITANIUM 0x005ED6D0 Destination_guess::GetFirst_guess
    unsigned char GetFirst_guess();
    // EXTERNAL: TITANIUM 0x005ED5D0 Destination_guess::GetSecond_guess
    unsigned char GetSecond_guess();
    // EXTERNAL: TITANIUM 0x005ED690 Destination_guess::GetThird_guess
    unsigned char GetThird_guess();
    // EXTERNAL: TITANIUM 0x005ED590 Destination_guess::GetFourth_guess
    unsigned char GetFourth_guess();
    // EXTERNAL: TITANIUM 0x005ED610 Destination_guess::GetFifth_guess
    unsigned char GetFifth_guess();
    // EXTERNAL: TITANIUM 0x005ED650 Destination_guess::GetSixth_guess
    unsigned char GetSixth_guess();
    // EXTERNAL: TITANIUM 0x005F05E0 Destination_guess::GetSlot_guess
    int GetSlot_guess(int index);
    // EXTERNAL: TITANIUM 0x005ED6F0 Destination_guess::SetFirst_guess
    void SetFirst_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5F0 Destination_guess::SetSecond_guess
    void SetSecond_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED6B0 Destination_guess::SetThird_guess
    void SetThird_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5B0 Destination_guess::SetFourth_guess
    void SetFourth_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED630 Destination_guess::SetFifth_guess
    void SetFifth_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED670 Destination_guess::SetSixth_guess
    void SetSixth_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED4B0 Destination_guess::GetDeity_guess
    int GetDeity_guess();
    // EXTERNAL: TITANIUM 0x005ED4D0 Destination_guess::SetDeity_guess
    void SetDeity_guess(int value);

    char pad_0000[8];
    struct VBTable* nested_0008;
    char pad_000c[0xc274];
    SkillOwner_guess skill_c280;
};

#include "titanium/layouts/core.h"

struct Cell_guess {
    // EXTERNAL: TITANIUM 0x005EC220 Cell_guess::GetCharInfo2
    struct CellData_guess* GetCharInfo2();
    // EXTERNAL: TITANIUM 0x004B919F Cell_guess::SetFace_guess
    void SetFace_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x004B9160 Cell_guess::Set1198_guess
    void Set1198_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004B914B Cell_guess::SetGender_guess
    void SetGender_guess(int value);
    // EXTERNAL: TITANIUM 0x004B9175 Cell_guess::SetClass_guess
    void SetClass_guess(unsigned char value);
};

struct CellHolder_guess {
    char pad_0000[4];
    Cell_guess data_0004;
};

struct CellData_guess {
    char pad_0000[0x1194];
    unsigned char gender_1194_guess;      // 0x1194
    int race_1198_guess;                // 0x1198
    unsigned char class_119c_guess;      // 0x119c
    char pad_119d[7];
    unsigned char level_11a4_guess;      // 0x11a4
    char pad_11a5[0xf];
    int baseStr_11b4_guess;                 // 0x11b4
    int baseSta_11b8_guess;                 // 0x11b8
    int baseCha_11bc_guess;                 // 0x11bc
    int baseDex_11c0_guess;                 // 0x11c0
    int baseInt_11c4_guess;                 // 0x11c4
    int baseAgi_11c8_guess;                 // 0x11c8
    int baseWis_11cc_guess;                 // 0x11cc
    unsigned char face_11d0_guess;      // 0x11d0
};

struct SystemSource_guess;

struct LanguageSlot_guess;

struct ResetBlock_guess {
    int field_0000;
    // EXTERNAL: TITANIUM 0x005482A0 ResetBlock_guess::Reset_guess
    void Reset_guess(int value);
};

// Character data: the virtual base of the profile; GetCharInfo2's list at +4.
struct CharacterProfileData_guess : EQ_CharacterProfile_guess {
    virtual void Slot00_guess();
    char pad_000c[0x30];
    char name_003c[0x40];                  // 0x3c
    CellData_guess* GetProfile_guess() { return (CellData_guess*)GetCharInfo2(); }
    char* GetName_guess() { return name_003c; }
};

// vbptr at +8 after an 8-byte base.
struct ProfilePrefix_guess {
    int field_0000;
    int field_0004;
};

struct CharacterProfile_guess : ProfilePrefix_guess, virtual CharacterProfileData_guess {
};

// Edit window; slot 76 (+0x130) returns its text.
struct NameEdit_guess {
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
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess(); virtual void Slot44_guess();
    virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess();
    virtual void Slot51_guess(); virtual void Slot52_guess(); virtual void Slot53_guess();
    virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void Slot63_guess(); virtual void Slot64_guess(); virtual void Slot65_guess();
    virtual void Slot66_guess(); virtual void Slot67_guess(); virtual void Slot68_guess();
    virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
    virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess();
    virtual void Slot75_guess();
    virtual CXStr GetText_guess() const;
    // EXTERNAL: TITANIUM 0x0059EDF0 NameEdit_guess::SetFocus
    void SetFocus();
};

// Text window; slot 63 (+0xFC) sets its text.
struct TextWnd_guess {
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
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess(); virtual void Slot44_guess();
    virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Show_guess(int show, int bringToTop); virtual void Slot49_guess(); virtual void Slot50_guess();
    virtual void Slot51_guess(); virtual void Slot52_guess(); virtual void Slot53_guess();
    virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void SetWindowText_guess(const CXStr& text);
    // EXTERNAL: TITANIUM 0x005A8B00 TextWnd_guess::SetSTMLText
    void SetSTMLText(CXStr text, bool first, SLinkInfo* second);
    char pad_0004[0x78];
    int field_007c;                        // 0x7c
};

#define g_creationMode_guess EQ_GLOBAL(int, 0x00923D58)
#define g_screenWidth_guess EQ_GLOBAL(int, 0x00923780)
#define g_screenHeight_guess EQ_GLOBAL(int, 0x00923784)

struct SlotElement_004ee7ea_guess;

struct CCharacterCreationView_guess {
    char pad_0000[0x15c];
    ResetBlock_guess reset_015c;           // 0x15c
    union {
        Destination_guess* destination_0160;   // 0x160
        CharacterProfile_guess* profile_0160;
    };
    int field_0164;                        // 0x164
    int field_0168;                        // 0x168
    int field_016c;                        // 0x16c
    int points_0170;                       // 0x170
    int base_0174[7];                      // 0x174
    int max_0190[7];                       // 0x190
    int entries_01ac[15];                  // 0x1ac
    int entries_01e8[16];                  // 0x1e8
    int* array_0228[7];                    // 0x228
    int when_0244;                         // 0x244
    SlotElement_004ee7ea_guess* screens_0248[2]; // 0x248
    void* field_0250;
    void* field_0254;
    void* field_0258;
    void* field_025c;
    void* field_0260;
    void* field_0264;
    void* field_0268;
    void* field_026c;
    struct HelpWnd_guess* help_0270;       // 0x270
    CXWnd* helpButton_0274;                // 0x274
    CXWnd* back_0278;                      // 0x278
    CXWnd* next_027c;                      // 0x27c
    CButtonWnd* tutorial_0280;             // 0x280
    CXWnd* getName_0284;                   // 0x284
    CXWnd* face_0288;                      // 0x288
    CButtonWnd* male_028c;                 // 0x28c
    CButtonWnd* female_0290;               // 0x290
    CButtonWnd* race_0294[15];             // 0x294
    CButtonWnd* class_02d0[16];            // 0x2d0
    CButtonWnd* up_0310[7];                // 0x310
    CButtonWnd* down_032c[7];              // 0x32c
    TextWnd_guess* display_0348[7];        // 0x348
    CXWnd* stat_0364[7];                   // 0x364
    CXWnd* pointsButton_0380;              // 0x380
    TextWnd_guess* points_0384;            // 0x384
    NameEdit_guess* nameInput_0388;        // 0x388
    CStmlWnd* stml_038c;                   // 0x38c
    TextWnd_guess* stage_0390;             // 0x390
    LanguageSlot_guess* slot_0394[17];     // 0x394
    LanguageSlot_guess* city_03d8[15];     // 0x3d8
    CXWnd* window_0414;                    // 0x414
    int field_0418;                        // 0x418
    int field_041c;                        // 0x41c
    bool field_0420;                       // 0x420
    unsigned char field_0421;              // 0x421
    void OnNextButton_guess();
    bool Deactivate_guess();
    void HandleApproveName_guess(int mode);
    void SetScreen_guess(int value);
    void Transfer_guess(Source_guess* source);
    void RandomizeFace_guess();
    void SendCharacterCreate_guess();
    bool CheckExpansionLocked_guess(unsigned char first, unsigned char second);
    void ResetCreationState_guess();
    void ResetStatsAndDeity_guess();
    void InitializeCharacterStats_guess(bool value);
    void SetNewPCDeityFromBtnIndex_guess(int index);
    void UpdateCitySelectionButtons_guess();
    void RandomizeCharacter_guess(bool first, bool second);
    void UpdatePreviewModel_guess();
    void CopyAppearanceToPlayer_guess(SystemSource_guess* system, Destination_guess* destination, int flag);
    void UpdateScreenZeroButtons_guess(int value);
    void SelectClass_guess(int index);
    void SelectRace_guess(int index);
    void Reset_guess();
    void SubmitNameToWorld_guess();
    void ApplyName_guess(const char* name);
    void AddRemainingPointsToStat_guess(int index);
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
};

struct NamePacket_guess {
    char name_000[0x40];
    int field_040;                 // 0x40
    int field_044;                 // 0x44
    int field_048;                 // 0x48
};

struct NameChecker_guess {
    // EXTERNAL: TITANIUM 0x004933FE NameChecker_guess::IsValidName_guess
    int IsValidName_guess(char* text);
};

struct Display_guess {
    char pad_0000[0x148];
    int field_0148;
};

#define g_nameChecker_guess EQ_GLOBAL(NameChecker_guess*, 0x00988DF0)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination, const char* source, int length);

struct ErrorQueue_guess {
    // EXTERNAL: TITANIUM 0x00548460 ErrorQueue_guess::Activate
    void Activate(int owner, int category, char* text, int enabled,
                     int duration, int first, int second);
    // EXTERNAL: TITANIUM 0x00548256 ErrorQueue_guess::Refresh_guess
    void Refresh_guess();
};

struct Pending_guess {
    // EXTERNAL: TITANIUM 0x00469DD7 Pending_guess::Flush_guess
    void Flush_guess();
    // EXTERNAL: TITANIUM 0x004F0D08 Pending_guess::SetBuffer_guess
    void SetBuffer_guess(const char* value);
};

#define g_pending_guess EQ_GLOBAL(Pending_guess*, 0x00850B9C)

struct Activation_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Activate_guess(int value);
};

struct ActivationHolder_guess {
    int field_0000;
    Activation_guess* activation_0004;
};

struct SystemSource_guess {
    char pad_0000[0x1a8];
    ActivationHolder_guess* activation_01a8;
    char pad_01ac[0x99];
    unsigned char hairColor_0245_guess;      // 0x245
    unsigned char beardColor_0246_guess;      // 0x246
    unsigned char eyeColor1_0247_guess;      // 0x247
    unsigned char field_0248;      // 0x248
    unsigned char field_0249;      // 0x249
    unsigned char field_024a;      // 0x24a
    char pad_024b;
    unsigned char level_024c_guess;      // 0x24c
    unsigned char faceHair_024d_guess;      // 0x24d
    unsigned char gender_024e_guess;      // 0x24e
    char pad_024f[3];
    unsigned char playerClass_0252_guess;      // 0x252
    char pad_0253[0x2d];
    int deity_0280_guess;                // 0x280

    // EXTERNAL: TITANIUM 0x0047A3EB SystemSource_guess::SetArmorType_guess
    void SetArmorType_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x0047A406 SystemSource_guess::SetArmorTint_guess
    void SetArmorTint_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x0047A3D0 SystemSource_guess::GetSlot_guess
    int GetSlot_guess(int index, int first, int second);
    // EXTERNAL: TITANIUM 0x0047E619 SystemSource_guess::CreateUserLight_guess
    Activation_guess* CreateUserLight_guess(int value, int kind);
    // EXTERNAL: TITANIUM 0x004845D8 SystemSource_guess::HandleMaterialEx_guess
    void HandleMaterialEx_guess(int index, int first, int second);
    // EXTERNAL: TITANIUM 0x0048083A SystemSource_guess::AddMessage_guess
    void AddMessage_guess(int index, const char* text, int flag);

    // EXTERNAL: TITANIUM 0x0047C3EF SystemSource_guess::FUN_0047c3ef_guess
    void FUN_0047c3ef_guess(char* target);
    // EXTERNAL: TITANIUM 0x0047A741 SystemSource_guess::SetRace_guess
    void SetRace_guess(int value);
    // EXTERNAL: TITANIUM 0x0047DEC4 SystemSource_guess::SetLanguage_guess
    void SetLanguage_guess(unsigned char value, int flag);
    // EXTERNAL: TITANIUM 0x00480130 SystemSource_guess::Reset_guess
    void Reset_guess(int first, int second, int third);
    // EXTERNAL: TITANIUM 0x00483B9B SystemSource_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x0047A62D SystemSource_guess::CanHaveNoHair_guess
    int CanHaveNoHair_guess();
};

struct ControlPanel_guess {
    // EXTERNAL: TITANIUM 0x004F1733 ControlPanel_guess::RebuildPlayerActor_guess
    void RebuildPlayerActor_guess(SystemSource_guess* system, unsigned char first, int count,
                     int second, unsigned char last);
};

struct ClientSettings_guess {
    char pad_0000[0x2878];
    int value_2878;
};

#define g_controlPanel_guess EQ_GLOBAL(ControlPanel_guess*, 0x00850B9C)
#define g_cellDestination_guess EQ_GLOBAL(Destination_guess*, 0x00905D00)
#define g_clientSettings_guess EQ_GLOBAL(ClientSettings_guess*, 0x00905D24)
#define g_messageText_guess EQ_ARRAY(char, 0x006410A8)

struct ClientInfoPacket_guess {
    int field_000;                 // 0x00
    int field_004;                 // 0x04
    int field_008;                 // 0x08
    int field_00c;                 // 0x0c
    int field_010;                 // 0x10
    int field_014;                 // 0x14
    int field_018;                 // 0x18
    int field_01c;                 // 0x1c
    int field_020;                 // 0x20
    int array_024[7];              // 0x24
    int field_040;                 // 0x40
    int field_044;                 // 0x44
    int field_048;                 // 0x48
    int field_04c;                 // 0x4c
};

struct NameBlock_guess {
    char pad_0000[0x3c];
    char first_003c;               // 0x3c
};

struct EffectSystem_004ee978_guess {
    // EXTERNAL: TITANIUM 0x0044B741 EffectSystem_004ee978_guess::PlayMp3_guess
    void PlayMp3_guess(const char* text, float amount);
    // EXTERNAL: TITANIUM 0x0044A617 EffectSystem_004ee978_guess::SetMusicSelection_guess
    void SetMusicSelection_guess(int first, int second);
};

// Polymorphic entries; slot 48 (+0xC0) is Stop_guess.
struct SlotElement_004ee7ea_guess {
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
    virtual void Stop_guess(int first, int second);
};

struct Owner_004ee978_guess {
    char pad_0000[0x16c];
    int field_016c;
    char pad_0170[0xd8];
    SlotElement_004ee7ea_guess* pair_0248[2];   // 0x248
    char pad_0250[0x1c8];
    int field_0418;
    int field_041c;

    // EXTERNAL: TITANIUM 0x004ED32E Owner_004ee978_guess::SetScreen_guess
    void SetScreen_guess(int value);
    bool ShowCurrentScreen_guess();
    void OnBackButton_guess();
};

#define g_effectSystem_004ee978_guess EQ_GLOBAL(EffectSystem_004ee978_guess*, 0x00851390)

#define g_systemSource_guess EQ_GLOBAL(SystemSource_guess*, 0x00905CE4)
#define g_messageTarget_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_defaultsEnabled_guess EQ_GLOBAL(int, 0x00923D5C)
#define g_errorQueue_guess EQ_GLOBAL(ErrorQueue_guess*, 0x00991E44)
#define g_condition80_guess EQ_GLOBAL(int, 0x00924790)
#define g_condition82_guess EQ_GLOBAL(int, 0x00924798)
#define g_condition14a_guess EQ_GLOBAL(int, 0x009247A0)
#define g_condition10_guess EQ_GLOBAL(int, 0x009247A8)
#define g_condition14_guess EQ_GLOBAL(int, 0x00924798)
#define pinstCCharacterCreation_guess EQ_GLOBAL(int, 0x00850C20)

struct RectangleTarget_guess {
    // EXTERNAL: TITANIUM 0x0059FB00 RectangleTarget_guess::GetRectangle_guess
    void GetRectangle_guess(int* rectangle);
};

struct LayoutTarget_guess {
    // EXTERNAL: TITANIUM 0x005A0540 LayoutTarget_guess::FUN_005a0540_guess
    void FUN_005a0540_guess();
    // EXTERNAL: TITANIUM 0x005A0650 LayoutTarget_guess::FUN_005a0650_guess
    void FUN_005a0650_guess();
    // EXTERNAL: TITANIUM 0x005A05F0 LayoutTarget_guess::FUN_005a05f0_guess
    void FUN_005a05f0_guess();
    // EXTERNAL: TITANIUM 0x005A06A0 LayoutTarget_guess::FUN_005a06a0_guess
    void FUN_005a06a0_guess();
    // EXTERNAL: TITANIUM 0x005A0850 LayoutTarget_guess::FUN_005a0850_guess
    void FUN_005a0850_guess(int x, int y);
    // EXTERNAL: TITANIUM 0x005A0590 LayoutTarget_guess::FUN_005a0590_guess
    void FUN_005a0590_guess();
};

struct TransferOwnerFlags_guess {
    char pad_0000[0x65];
    unsigned char flags_0065;
};

// EXTERNAL: TITANIUM 0x00464BB0 GetDefaultLanguageForRace_guess
char* __cdecl GetDefaultLanguageForRace_guess(int value);
// EXTERNAL: TITANIUM 0x0060BEB0 FUN_0060beb0_guess
void __cdecl FUN_0060beb0_guess(const char* section, const char* key, const char* value, const char* filename);

// EXTERNAL: TITANIUM 0x0060BE50 FUN_0060be50_guess
void __cdecl FUN_0060be50_guess(const char* section, const char* key, const char* defaultValue,
                                char* value, int size, const char* filename);

// EXTERNAL: TITANIUM 0x0060E450 FUN_0060e450_guess
void __cdecl FUN_0060e450_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int minimum, int maximum);

// EXTERNAL: TITANIUM 0x0059DD30 CheckReady_guess
bool __cdecl CheckReady_guess();
// EXTERNAL: TITANIUM 0x00576E80 Now_guess
int __cdecl Now_guess();

struct DestinationPrefix_004ed258_guess {
    int field_0000;
    int field_0004;
};

struct DestinationBase_004ed258_guess {
    virtual void Slot00_guess();
    virtual ~DestinationBase_004ed258_guess();
};

struct Destination_004ed258_guess : DestinationPrefix_004ed258_guess,
                                     virtual DestinationBase_004ed258_guess {
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"
#include "titanium/wnd/CFacePick.h"

// EXTERNAL: TITANIUM 0x0063FD9C ??_7Secondary_004ed258_guess@@6B@
struct Secondary_004ed258_guess {
    // EXTERNAL: TITANIUM 0x005482A0 Secondary_004ed258_guess::Reset_guess
    void Reset_guess(int value);
    virtual ~Secondary_004ed258_guess() {
        Reset_guess(-1);
    }
};

// EXTERNAL: TITANIUM 0x006522E0 ??_7CCharacterCreation_guess@@6BCSidlScreenWndBase@@@
// EXTERNAL: TITANIUM 0x006522DC ??_7CCharacterCreation_guess@@6BSecondary_004ed258_guess@@@
struct CCharacterCreation_guess : CSidlScreenWndBase, Secondary_004ed258_guess {
    Destination_004ed258_guess* destination_0160;
    char pad_0164[0x1ac - 0x164];
    int table_01ac[31];
    char pad_0228[0x244 - 0x228];
    int when_0244;
    char pad_0248[0x280 - 0x248];
    CButtonWnd* tutorialButton_0280;
    ~CCharacterCreation_guess();
    void* Delete_guess(unsigned char flags);
    // EXTERNAL: TITANIUM 0x004EE5EC CCharacterCreation_guess::ResetCreationState_guess
    void ResetCreationState_guess();
    CCharacterCreation_guess(CXWnd* parent);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory);

// Deletes the new character's data (+0x160).
// FUNCTION: TITANIUM 0x004ED258
CCharacterCreation_guess::~CCharacterCreation_guess()
{
    if (destination_0160 != 0) {
        delete destination_0160;
        destination_0160 = 0;
    }
}

// Calls the message-box base's (+0x15C) Reset_guess with 100, the type of the name boxes (probably closes
// them); always true.
// FUNCTION: TITANIUM 0x004ED2CF
bool CCharacterCreationView_guess::Deactivate_guess()
{
    reset_015c.Reset_guess(100);
    return true;
}

// Per-frame update: keeps Get Name (+0x284) disabled until the wait that a random-name request set
// (+0x244, 3 units of 0x576E80's clock) is over, then enables it once.
// FUNCTION: TITANIUM 0x004ED2DF
void Updated_guess::Update_guess()
{
    if (CheckReady_guess() && stamped_0284 != 0) {
        int when = when_0244;
        if (when > Now_guess()) {
            stamped_0284->flag_005d = 0;
        } else if (when >= 0) {
            stamped_0284->flag_005d = 1;
            when_0244 = -1;
        }
    }
    OnProcessFrame();
}

// Shows creation screen `value`: 0 = race, class and stats; 1 = deity, city and name; others become 0.
// ShowCreationHelp missing from eqclient.ini is only set to TRUE (no help that time); T, t or 1 opens the
// help with CharCreateHelp1/2.wav. The last panel (Screen0c/1d) goes to (width/2 - 30, height/3), at least
// (280, 180).
// FUNCTION: TITANIUM 0x004ED32E
// @early-stop: budget, structural ndiff=332
void CCharacterCreationView_guess::SetScreen_guess(int value)
{
    char text[0x100];

    if (value < 0 || value >= 2)
        value = 0;

    if (value != field_041c) {
        if (screens_0248[field_041c] != 0)
            screens_0248[field_041c]->Stop_guess(0, 1);
        field_041c = value;
    }

    if (field_041c == 0) {
        for (int i = 0; i < 7; ++i) {
            if (display_0348[i] != 0) {
                sprintf(text, "%d", *array_0228[i]);
                display_0348[i]->SetWindowText_guess(text);
            }
        }

        if (stage_0390 != 0 && help_0270 != 0) {
            stage_0390->SetSTMLText(
                CXStr(pStringTable->getString(0x16f2, 0)), 1, 0);
            ((TextWnd_guess*)help_0270)->SetWindowText_guess(
                pStringTable->getString(0x16f4, 0));

            FUN_0060be50_guess("Defaults", "ShowCreationHelp", "*NULL*", text, 0x20,
                               ".\\eqclient.ini");
            if (text[0] == '*') {
                FUN_0060beb0_guess("Defaults", "ShowCreationHelp", "TRUE", ".\\eqclient.ini");
            } else {
                g_effectSystem_004ee978_guess->PlayMp3_guess(
                    EQ_ARRAY(char, 0x0063F53F), 1.0f);
                if (text[0] == 'T' || text[0] == 't' || text[0] == '1') {
                    ((TextWnd_guess*)help_0270)->Show_guess(1, 1);
                    g_effectSystem_004ee978_guess->SetMusicSelection_guess(4, 0);
                    g_effectSystem_004ee978_guess->PlayMp3_guess("CharCreateHelp1.wav", 1.0f);
                } else {
                    ((TextWnd_guess*)help_0270)->Show_guess(0, 1);
                }
            }
        }
    } else if (field_041c == 1) {
        if (nameInput_0388 != 0)
            nameInput_0388->SetFocus();

        if (stage_0390 != 0 && help_0270 != 0) {
            stage_0390->SetSTMLText(
                CXStr(pStringTable->getString(0x16f3, 0)), 1, 0);
            ((TextWnd_guess*)help_0270)->SetWindowText_guess(
                pStringTable->getString(0x16f4, 0));

            FUN_0060be50_guess("Defaults", "ShowCreationHelp", "*NULL*", text, 0x20,
                               ".\\eqclient.ini");
            if (text[0] == '*') {
                FUN_0060beb0_guess("Defaults", "ShowCreationHelp", "TRUE", ".\\eqclient.ini");
            } else {
                g_effectSystem_004ee978_guess->PlayMp3_guess(
                    EQ_ARRAY(char, 0x0063F53F), 1.0f);
                if (text[0] == 'T' || text[0] == 't' || text[0] == '1') {
                    ((TextWnd_guess*)help_0270)->Show_guess(1, 1);
                    g_effectSystem_004ee978_guess->SetMusicSelection_guess(4, 0);
                    g_effectSystem_004ee978_guess->PlayMp3_guess("CharCreateHelp2.wav", 1.0f);
                } else {
                    ((TextWnd_guess*)help_0270)->Show_guess(0, 1);
                }
            }
        }
    }

    if (screens_0248[field_041c] != 0) {
        int width = g_screenWidth_guess;
        int height = g_screenHeight_guess;
        int rectangle[2] = { 0, 0 };

        ((RectangleTarget_guess*)this)->GetRectangle_guess(rectangle);

        int x = width / 2 - 0x1e;
        int y = height / 3;
        if (x < 0x118)
            x = 0x118;
        if (y < 0xb4)
            y = 0xb4;

        ((RectangleTarget_guess*)screens_0248[field_041c])->GetRectangle_guess(rectangle);

        if (field_041c == 0) {
            if (field_0250 != 0)
                ((LayoutTarget_guess*)field_0250)->FUN_005a0540_guess();
            if (field_0254 != 0)
                ((LayoutTarget_guess*)field_0254)->FUN_005a0650_guess();
            if (field_0258 != 0)
                ((LayoutTarget_guess*)field_0258)->FUN_005a05f0_guess();
            if (field_025c != 0) {
                ((LayoutTarget_guess*)field_025c)->FUN_005a0850_guess(x, y);
                ((LayoutTarget_guess*)field_025c)->FUN_005a0590_guess();
            }
        } else if (field_041c == 1) {
            if (field_0260 != 0)
                ((LayoutTarget_guess*)field_0260)->FUN_005a06a0_guess();
            if (field_0264 != 0)
                ((LayoutTarget_guess*)field_0264)->FUN_005a0650_guess();
            if (field_0268 != 0)
                ((LayoutTarget_guess*)field_0268)->FUN_005a05f0_guess();
            if (field_026c != 0) {
                ((LayoutTarget_guess*)field_026c)->FUN_005a0850_guess(x, y);
                ((LayoutTarget_guess*)field_026c)->FUN_005a0590_guess();
            }
        }

        screens_0248[field_041c]->Stop_guess(1, 1);
        ((TransferOwnerFlags_guess*)this)->flags_0065 |= 4;
    }
}

// Race button index for race id `value` (table +0x1AC); 0 when absent.
// FUNCTION: TITANIUM 0x004ED820
int EntryLists_guess::FindRaceButton_guess(int value)
{
    int i = 0;
    int* current = first_01ac;
    do {
        if (*current == value)
            return i;
        ++i;
        ++current;
    } while (i < 15);
    return 0;
}

// Class button index for class id `value` (table +0x1E8); 0 when absent.
// FUNCTION: TITANIUM 0x004ED83E
int EntryLists_guess::FindClassButton_guess(int value)
{
    int i = 0;
    int* current = second_01e8;
    do {
        if (*current == value)
            return i;
        ++i;
        ++current;
    } while (i < 16);
    return 0;
}

struct LanguageSlot_guess {
    char pad_0000[0x5d];
    unsigned char flag_005d;
    // EXTERNAL: TITANIUM 0x005BB140 LanguageSlot_guess::SetCheck
    void SetCheck(bool flag);
};

struct LanguageOwner_guess {
    char pad_0000[0x164];
    int current_0164;                      // 0x164
    char pad_0168[0x270];
    LanguageSlot_guess* slot_03d8[15];     // 0x3d8

    void SetStartCity_guess(int value);
};

// Selects start city `value` (0 Erudin ... 13 Shar Vahl, -1 none; sent as start_zone in
// OP_CharacterCreate) and unchecks the old city button.
// The city's description (string ids 0x751-0x75E) is copied into a local that is never used; original code.
// FUNCTION: TITANIUM 0x004ED85C
void LanguageOwner_guess::SetStartCity_guess(int value)
{
    char text[512];
    int previous = current_0164;
    if (previous >= 0 && previous < 15 && value != previous && slot_03d8[previous] != 0)
        slot_03d8[previous]->SetCheck(0);

    current_0164 = value;
    switch (value) {
    case 0:
        FUN_0060e450_guess(text, pStringTable->getString(0x751, 0));
        break;
    case 1:
        FUN_0060e450_guess(text, pStringTable->getString(0x752, 0));
        break;
    case 2:
        FUN_0060e450_guess(text, pStringTable->getString(0x753, 0));
        break;
    case 3:
        FUN_0060e450_guess(text, pStringTable->getString(0x754, 0));
        break;
    case 4:
        FUN_0060e450_guess(text, pStringTable->getString(0x755, 0));
        break;
    case 5:
        FUN_0060e450_guess(text, pStringTable->getString(0x756, 0));
        break;
    case 6:
        FUN_0060e450_guess(text, pStringTable->getString(0x757, 0));
        break;
    case 7:
        FUN_0060e450_guess(text, pStringTable->getString(0x758, 0));
        break;
    case 8:
        FUN_0060e450_guess(text, pStringTable->getString(0x759, 0));
        break;
    case 9:
        FUN_0060e450_guess(text, pStringTable->getString(0x75a, 0));
        break;
    case 10:
        FUN_0060e450_guess(text, pStringTable->getString(0x75b, 0));
        break;
    case 11:
        FUN_0060e450_guess(text, pStringTable->getString(0x75c, 0));
        break;
    case 12:
        FUN_0060e450_guess(text, pStringTable->getString(0x75d, 0));
        break;
    case 13:
        FUN_0060e450_guess(text, pStringTable->getString(0x75e, 0));
        break;
    default:
        break;
    }
}

// Constructor helper: nulls the child-window pointers before the SIDL children are bound.
// FUNCTION: TITANIUM 0x004ED993
void Updated_guess::Clear_guess()
{
    for (int i = 0; i < 2; ++i)
        pair_0248[i] = 0;

    field_0250 = 0;
    field_0254 = 0;
    field_0258 = 0;
    field_0260 = 0;
    field_0264 = 0;
    field_0268 = 0;
    field_026c = 0;
    field_0278 = 0;
    field_027c = 0;
    field_0274 = 0;
    stamped_0284 = 0;
    field_0288 = 0;
    field_028c = 0;
    field_0290 = 0;

    for (int i = 0; i < 15; ++i)
        array_0294[i] = 0;
    for (int i = 0; i < 16; ++i)
        array_02d0[i] = 0;
    for (int i = 0; i < 7; ++i)
        array_0310[i] = 0;
    for (int i = 0; i < 7; ++i)
        array_032c[i] = 0;
    for (int i = 0; i < 7; ++i)
        array_0348[i] = 0;
    for (int i = 0; i < 7; ++i)
        array_0364[i] = 0;

    field_0380 = 0;
    field_0384 = 0;
    field_0388 = 0;
    field_038c = 0;
    field_0390 = 0;
    field_025c = 0;

    for (int i = 0; i < 17; ++i)
        array_0394[i] = 0;
    for (int i = 0; i < 15; ++i)
        array_03d8[i] = 0;

    field_0414 = 0;
}

// Binds the child windows by their SIDL names. The tutorial box starts checked and is disabled when
// 0x923D66 is set (a byte of the world's login data, tu_042); the name field gets a 15-character limit.
// FUNCTION: TITANIUM 0x004EDA7E
void CreationScreen_guess::Initialize_guess()
{
    char name[256];
    int index = 0;
    do {
        sprintf(name, "CharacterCreationScreen%d", index);
        screens_0248[index] = GetChildItem(name);
        ++index;
    } while (index < 2);

    backButton_0278 = GetChildItem("CC_Back_Button");
    nextButton_027c = GetChildItem("CC_Next_Button");
    helpButton_0274 = GetChildItem("CC_Help_Button");
    creationHelp_0270 = GetChildItem("CharacterCreationHelp");
    stageTitle_0390 = GetChildItem("CC_Creation_Help");
    title_0250 = GetChildItem("CC_CharacterCreationTitle");
    screen0a_0254 = GetChildItem("CharacterCreationScreen0a");
    screen0b_0258 = GetChildItem("CharacterCreationScreen0b");
    screen0c_025c = GetChildItem("CharacterCreationScreen0c");
    faceButton_0288 = GetChildItem("CC0_Face_Button");
    maleButton_028c = GetChildItem("CC0_Male_Button");
    femaleButton_0290 = GetChildItem("CC0_Female_Button");
    stageHelp_038c = GetChildItem("CC0_Help");

    index = 0;
    do {
        sprintf(name, "CC0_Stat%d_Up_Button", index);
        statUpButtons_0310[index] = GetChildItem(name);
        sprintf(name, "CC0_Stat%d_Down_Button", index);
        statDownButtons_032c[index] = GetChildItem(name);
        sprintf(name, "CC0_Stat%d_Button", index);
        statButtons_0364[index] = GetChildItem(name);
        sprintf(name, "CC0_Stat%d_Display_Button", index);
        statDisplayButtons_0348[index] = GetChildItem(name);
        ++index;
    } while (index < 7);

    index = 0;
    do {
        sprintf(name, "CC0_Race%d_Button", index);
        raceButtons_0294[index] = GetChildItem(name);
        ++index;
    } while (index < 15);

    index = 0;
    do {
        sprintf(name, "CC0_Class%d_Button", index);
        classButtons_02d0[index] = GetChildItem(name);
        ++index;
    } while (index < 16);

    pointsButton_0380 = GetChildItem("CC0_Points_Left_Button");
    pointsDisplayButton_0384 = GetChildItem("CC0_Points_Left_Display_Button");
    nameInput_0388 = (NameInput_guess*)GetChildItem("CC1_NameInput");
    getNameButton_0284 = GetChildItem("CC1_Get_Name_Button");
    tutorialButton_0280 = 0;
    tutorialButton_0280 = (CButtonWnd*)GetChildItem("CC1_StartTutorial_Button");
    if (tutorialButton_0280 != 0) {
        tutorialButton_0280->SetCheck(true);
        tutorialFlag_0420 = 1;
        if (EQ_GLOBAL(unsigned char, 0x00923D66) != 0)
            tutorialButton_0280->Enabled = 0;
    }

    NameInput_guess* nameInput = nameInput_0388;
    if (nameInput != 0) {
        nameInput->field_0230 = 1;
        nameInput = nameInput_0388;
        nameInput->field_012c = 15;
        nameInput->field_0128 = 15;
    }

    screen1_0260[0] = GetChildItem("CharacterCreationScreen1a");
    screen1_0260[1] = GetChildItem("CharacterCreationScreen1b");
    screen1_0260[2] = GetChildItem("CharacterCreationScreen1c");
    screen1_0260[3] = GetChildItem("CharacterCreationScreen1d");

    index = 0;
    do {
        sprintf(name, "CC1_Deity%d_Button", index);
        deityButtons_0394[index] = GetChildItem(name);
        ++index;
    } while (index < 17);

    index = 0;
    do {
        sprintf(name, "CC1_City%d_Button", index);
        cityButtons_03d8[index] = GetChildItem(name);
        ++index;
    } while (index < 15);

    stageHelp_0414 = GetChildItem("CC1_Help");
}

struct NameBuffer_guess {
    char bytes_guess[64];
    // EXTERNAL: TITANIUM 0x0040E25C NameBuffer_guess::Copy_guess
    char Copy_guess(const char* input);
};

struct NameSlot_guess {
    char pad_0000[0x3c];
    NameBuffer_guess buffer_003c;      // 0x3c
};

// Clears the name, points and help text (string 0xCA6, the right-click hint), and points the seven stat
// rows at the profile's STR, STA, AGI, DEX, WIS, INT, CHA (+0x11B4.. in that display order).
// The constructor reaches it as ResetCreationState_guess.
// FUNCTION: TITANIUM 0x004EE5EC
void CCharacterCreationView_guess::ResetCreationState_guess()
{
    field_0418 = 0;
    field_041c = 0;
    points_0170 = 0;
    field_016c = 0;
    {
        NameSlot_guess* slot = (NameSlot_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        slot->buffer_003c.Copy_guess(EQ_ARRAY(char, 0x0063F53F));
    }

    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[0] = &cell->data_0004.GetCharInfo2()->baseStr_11b4_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[1] = &cell->data_0004.GetCharInfo2()->baseSta_11b8_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[2] = &cell->data_0004.GetCharInfo2()->baseAgi_11c8_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[3] = &cell->data_0004.GetCharInfo2()->baseDex_11c0_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[4] = &cell->data_0004.GetCharInfo2()->baseWis_11cc_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[5] = &cell->data_0004.GetCharInfo2()->baseInt_11c4_guess;
    }
    {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
        array_0228[6] = &cell->data_0004.GetCharInfo2()->baseCha_11bc_guess;
    }

    if (stml_038c != 0)
        stml_038c->SetSTMLText(pStringTable->getString(0xca6, 0), true, 0);
    if (nameInput_0388 != 0) {
        CXStr text(EQ_ARRAY(char, 0x0063F53F));
        ((TextWnd_guess*)nameInput_0388)->SetWindowText_guess(text);
    }
    if (stage_0390 != 0) {
        CXStr text(EQ_ARRAY(char, 0x0063F53F));
        stage_0390->SetWindowText_guess(text);
    }
    field_0421 = 0;
}

// Scalar deleting destructor.
// FUNCTION: TITANIUM 0x004EE5D0
void* CCharacterCreation_guess::Delete_guess(unsigned char flags)
{
    this->CCharacterCreation_guess::~CCharacterCreation_guess();
    if ((flags & 1) != 0)
        free(this);
    return this;
}

// Hides both creation screens, then shows the current one again (SetScreen_guess).
// FUNCTION: TITANIUM 0x004EE7EA
bool Owner_004ee978_guess::ShowCurrentScreen_guess()
{
    int index = 0;
    do {
        if (pair_0248[index] != 0)
            pair_0248[index]->Stop_guess(0, 1);
        ++index;
    } while (index < 2);
    SetScreen_guess(field_041c);
    return true;
}

struct LocalPlayer_guess {
    // EXTERNAL: TITANIUM 0x0047C3EF LocalPlayer_guess::SetName_guess
    void SetName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x0047D776 LocalPlayer_guess::RefreshNameSprite_guess
    void RefreshNameSprite_guess();
};

#define pLocalPlayer_guess EQ_GLOBAL(LocalPlayer_guess*, 0x00905CE4)

// Puts `name` in the profile, the name field and the model's name tag (tu_042 calls it, probably for the
// OP_RandomNameGenerator answer).
// FUNCTION: TITANIUM 0x004EE824
void CCharacterCreationView_guess::ApplyName_guess(const char* name)
{
    NameSlot_guess* slot = (NameSlot_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset);
    slot->buffer_003c.Copy_guess(name);
    {
        CXStr text(((NameSlot_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset))
            ->buffer_003c.bytes_guess);
        ((TextWnd_guess*)nameInput_0388)->SetWindowText_guess(text);
    }
    pLocalPlayer_guess->SetName_guess(
        ((NameSlot_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset))
            ->buffer_003c.bytes_guess);
    pLocalPlayer_guess->RefreshNameSprite_guess();
}

// Copies beard colour, beard, face, hair style, hair colour and both eye colours from another character's
// data (tu_155 calls it).
// FUNCTION: TITANIUM 0x004EE8CA
void CCharacterCreationView_guess::Transfer_guess(Source_guess* source)
{
    destination_0160->SetFirst_guess(source->GetFirst_guess());
    destination_0160->SetSecond_guess(source->GetSecond_guess());

    CellHolder_guess* sourceCell = (CellHolder_guess*)((char*)&source->nested_0008 + source->nested_0008->vbase_offset);
    CellData_guess* sourceData = sourceCell->data_0004.GetCharInfo2();
    ((Cell_guess*)((char*)&destination_0160->nested_0008 + destination_0160->nested_0008->vbase_offset))
        ->SetFace_guess(sourceData->face_11d0_guess);

    destination_0160->SetThird_guess(source->GetThird_guess());
    destination_0160->SetFourth_guess(source->GetFourth_guess());
    destination_0160->SetFifth_guess(source->GetFifth_guess());
    destination_0160->SetSixth_guess(source->GetSixth_guess());
}

// Back button (tu_044 calls it too): one screen back; on screen 0 it leaves creation (+0x418) and stops the
// help sound. Ignored while a name is with the server (+0x16C).
// FUNCTION: TITANIUM 0x004EE978
void Owner_004ee978_guess::OnBackButton_guess()
{
    if (field_016c == 0) {
        int count = field_041c;
        if (count <= 0) {
            field_0418 = 1;
            g_effectSystem_004ee978_guess->PlayMp3_guess(
                EQ_ARRAY(char, 0x0063F53F), 1.0f);
            g_effectSystem_004ee978_guess->SetMusicSelection_guess(4, 1);
            return;
        }
        SetScreen_guess(count - 1);
    }
}

// Rolls a random face (0-7; 0-9 for race 330, Froglok), lets the model take that face's default hair,
// beard and eyes (hair style 0xFF becomes 1), and copies them back into the profile.
// FUNCTION: TITANIUM 0x004EE9C3
void CCharacterCreationView_guess::RandomizeFace_guess()
{
    int offset = destination_0160->nested_0008->vbase_offset;
    int value = 7;
    CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 + offset);
    if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x14a)
        value = 9;

    ((Cell_guess*)((char*)&destination_0160->nested_0008 +
     destination_0160->nested_0008->vbase_offset))
        ->SetFace_guess(RandomRange_guess(0, value));

    unsigned char flag = g_systemSource_guess->faceHair_024d_guess;
    cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                               destination_0160->nested_0008->vbase_offset);
    CellData_guess* data = cell->data_0004.GetCharInfo2();
    g_systemSource_guess->SetLanguage_guess(data->face_11d0_guess, flag);

    g_systemSource_guess->Reset_guess(-1, 1, 1);
    g_systemSource_guess->Refresh_guess();
    if (g_systemSource_guess->CanHaveNoHair_guess() == 0 && g_systemSource_guess->field_0249 == 0xff)
        g_systemSource_guess->field_0249 = 1;

    destination_0160->SetThird_guess(g_systemSource_guess->field_0249);
    destination_0160->SetFourth_guess(g_systemSource_guess->hairColor_0245_guess);
    destination_0160->SetFirst_guess(g_systemSource_guess->field_024a);
    destination_0160->SetSecond_guess(g_systemSource_guess->beardColor_0246_guess);
    destination_0160->SetFifth_guess(g_systemSource_guess->eyeColor1_0247_guess);
    destination_0160->SetSixth_guess(g_systemSource_guess->field_0248);
}

struct LanguageTable_guess {
    // EXTERNAL: TITANIUM 0x004171A1 LanguageTable_guess::CityCanStart_guess
    bool CityCanStart_guess(int index, int limit, int value, int flag);
};

struct CellByte_guess {
    unsigned char value_0000;
};

struct DestinationCellBytes_guess {
    char pad_0000[8];
    CellByte_guess bytes_0008[1];
};

// Enables the start cities the race, deity and class allow (0x4171A1) and selects the first. Humans that
// may start in Qeynos and Freeport get one of them at random; Half Elves with Qeynos, Freeport, Kelethin
// and Felwithe get one of the four, 25% each.
// FUNCTION: TITANIUM 0x004EEB1D
// @early-stop: budget, structural ndiff=136
void CCharacterCreationView_guess::UpdateCitySelectionButtons_guess()
{
    LanguageOwner_guess* languageOwner = (LanguageOwner_guess*)this;
    languageOwner->SetStartCity_guess(-1);
    LanguageSlot_guess** slot = languageOwner->slot_03d8;
    int i = 0;
    do {
        unsigned char code = ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
            destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess;
        int limit = ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
            destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess;
        bool fits = ((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
            i, limit - 1, field_0168, code - 1);
        LanguageSlot_guess* current = *slot;
        if (!fits) {
            if (current != 0)
                current->flag_005d = 0;
        } else {
            if (current != 0)
                current->flag_005d = 1;
            if (field_0164 == -1)
                languageOwner->SetStartCity_guess(i);
        }
        ++slot;
        ++i;
    } while (i < 15);

    int language = -1;
    if (((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
        destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess == 1) {
        if (((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                1,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)
            && ((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                4,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)) {
            int roll = RandomRange_guess(1, 100);
            language = roll < 0x33 ? 1 : 4;
        }
    } else if (((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
        destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess == 7) {
        if (((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                1,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)
            && ((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                4,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)
            && ((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                9,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)
            && ((LanguageTable_guess*)&destination_0160->skill_c280)->CityCanStart_guess(
                10,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->race_1198_guess - 1,
                field_0168,
                ((CellHolder_guess*)(((DestinationCellBytes_guess*)destination_0160)->bytes_0008 +
                    destination_0160->nested_0008->vbase_offset))->data_0004.GetCharInfo2()->class_119c_guess - 1)) {
            int roll = RandomRange_guess(1, 100);
            if (roll < 0x1a)
                language = 1;
            else if (roll < 0x33)
                language = 4;
            else if (roll < 0x4c)
                language = 9;
            else
                language = 10;
        }
    }
    if (language != -1)
        languageOwner->SetStartCity_guess(language);

    LanguageSlot_guess* current = languageOwner->slot_03d8[field_0164];
    if (current != 0)
        current->SetCheck(1);
}

// Deity button `index`: sets the deity id (201-216, 396 Agnostic) and shows its description (string ids
// 0xFA2-0xFB2); then redoes the cities, which depend on the deity.
// FUNCTION: TITANIUM 0x004EEEAC
void CCharacterCreationView_guess::SetNewPCDeityFromBtnIndex_guess(int index)
{
    CXStr text;
    field_0168 = index;
    switch (index) {
    case 0:
        destination_0160->SetDeity_guess(0x18c);
        text += pStringTable->getString(0xfa2, 0);
        break;
    default:
        destination_0160->SetDeity_guess(0x18c);
        text += pStringTable->getString(0xfa2, 0);
        break;
    case 1:
        destination_0160->SetDeity_guess(0xc9);
        text += pStringTable->getString(0xfa3, 0);
        break;
    case 2:
        destination_0160->SetDeity_guess(0xcd);
        text += pStringTable->getString(0xfa4, 0);
        break;
    case 3:
        destination_0160->SetDeity_guess(0xcb);
        text += pStringTable->getString(0xfa5, 0);
        break;
    case 4:
        destination_0160->SetDeity_guess(0xce);
        text += pStringTable->getString(0xfa6, 0);
        break;
    case 5:
        destination_0160->SetDeity_guess(0xcf);
        text += pStringTable->getString(0xfa7, 0);
        break;
    case 6:
        destination_0160->SetDeity_guess(0xcc);
        text += pStringTable->getString(0xfa8, 0);
        break;
    case 7:
        destination_0160->SetDeity_guess(0xd0);
        text += pStringTable->getString(0xfa9, 0);
        break;
    case 8:
        destination_0160->SetDeity_guess(0xd4);
        text += pStringTable->getString(0xfaa, 0);
        break;
    case 9:
        destination_0160->SetDeity_guess(0xd1);
        text += pStringTable->getString(0xfab, 0);
        break;
    case 10:
        destination_0160->SetDeity_guess(0xd2);
        text += pStringTable->getString(0xfac, 0);
        break;
    case 11:
        destination_0160->SetDeity_guess(0xd5);
        text += pStringTable->getString(0xfad, 0);
        break;
    case 12:
        destination_0160->SetDeity_guess(0xca);
        text += pStringTable->getString(0xfae, 0);
        break;
    case 13:
        destination_0160->SetDeity_guess(0xd6);
        text += pStringTable->getString(0xfaf, 0);
        break;
    case 14:
        destination_0160->SetDeity_guess(0xd7);
        text += pStringTable->getString(0xfb0, 0);
        break;
    case 15:
        destination_0160->SetDeity_guess(0xd8);
        text += pStringTable->getString(0xfb1, 0);
        break;
    case 16:
        destination_0160->SetDeity_guess(0xd3);
        text += pStringTable->getString(0xfb2, 0);
        break;
    }
    if (window_0414 != 0)
        window_0414->SetWindowTextA(text);
    UpdateCitySelectionButtons_guess();
}

// Redraws screen 0: race and class (only classes the race allows are enabled), gender, points left and the
// stats; + needs points left (+0x170 nonzero), - a value above the rolled base. `value` is unused.
// In creation mode 6 (0x923D58) Iksar and Vah Shir (buttons 9, 12) are disabled, without a null test.
// FUNCTION: TITANIUM 0x004EF129
void CCharacterCreationView_guess::UpdateScreenZeroButtons_guess(int value)
{
    char text[256];
    int race = ((EntryLists_guess*)this)->FindRaceButton_guess(profile_0160->GetProfile_guess()->race_1198_guess);
    int cls = ((EntryLists_guess*)this)->FindClassButton_guess(profile_0160->GetProfile_guess()->class_119c_guess);

    for (int i = 0; i < 15; ++i) {
        if (race_0294[i] != 0)
            race_0294[i]->SetCheck(i == race);
        if (g_creationMode_guess == 6 && (i == 12 || i == 9))
            race_0294[i]->Enabled = 0;
    }

    for (int i = 0; i < 16; ++i) {
        if (class_02d0[i] != 0) {
            if (destination_0160->skill_c280.CheckClass_guess(
                    profile_0160->GetProfile_guess()->race_1198_guess - 1, entries_01e8[i] - 1)) {
                class_02d0[i]->SetCheck(i == cls);
                class_02d0[i]->Enabled = 1;
            } else {
                class_02d0[i]->Enabled = 0;
            }
        }
    }

    if (male_028c != 0)
        male_028c->SetCheck(profile_0160->GetProfile_guess()->gender_1194_guess == 0);
    if (female_0290 != 0)
        female_0290->SetCheck(profile_0160->GetProfile_guess()->gender_1194_guess == 1);

    if (points_0384 != 0) {
        sprintf(text, "%d", points_0170);
        points_0384->SetWindowText_guess(text);
    }

    for (int i = 0; i < 7; ++i) {
        if (display_0348[i] != 0) {
            sprintf(text, "%d", *array_0228[i]);
            display_0348[i]->SetWindowText_guess(text);
        }
        if (up_0310[i] != 0)
            up_0310[i]->Enabled = points_0170 != 0;
        if (down_032c[i] != 0)
            down_032c[i]->Enabled = *array_0228[i] - 1 >= base_0174[i];
    }
}

// True, after a 5-second warning, when the race (`first`) or class (`second`) needs an expansion the
// account lacks: Iksar - Kunark (0x924790); Vah Shir and Beastlord - Luclin (0x924798, two macros);
// Froglok - Legacy of Ykesha (0x9247A0); Berserker - Gates of Discord (0x9247A8).
// FUNCTION: TITANIUM 0x004EF3FD
bool CCharacterCreationView_guess::CheckExpansionLocked_guess(unsigned char first, unsigned char second)
{
    char text[512];
    text[0] = 0;

    if (first != 0) {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x80 &&
            g_condition80_guess == 0) {
            FUN_0060e450_guess(text, pStringTable->getString(0x62e, 0));
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                0xb, text, 1, 5000, 0, 0);
            return true;
        }

        cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x82 &&
            g_condition82_guess == 0) {
            FUN_0060e450_guess(text, pStringTable->getString(0x631, 0));
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                0xb, text, 1, 5000, 0, 0);
            return true;
        }
    }

    if (second != 0) {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        if (cell->data_0004.GetCharInfo2()->class_119c_guess == 0xf &&
            g_condition14_guess == 0) {
            FUN_0060e450_guess(text, pStringTable->getString(0x634, 0));
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                0xb, text, 1, 5000, 0, 0);
            return true;
        }
    }

    if (first != 0) {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x14a &&
            g_condition14a_guess == 0) {
            FUN_0060e450_guess(text, pStringTable->getString(0x1691, 0));
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                0xb, text, 1, 5000, 0, 0);
            return true;
        }
    }

    if (second != 0) {
        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        if (cell->data_0004.GetCharInfo2()->class_119c_guess == 0x10 &&
            g_condition10_guess == 0) {
            FUN_0060e450_guess(text, pStringTable->getString(0x16d3, 0));
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                0xb, text, 1, 5000, 0, 0);
            return true;
        }
    }

    return false;
}

// Copies the new character's look to the model `system` and to 0x905D00: face, hair, beard and eyes; then
// RebuildPlayerActor_guess with gender, race and class, a light, the nine armour slots, and empty weapon
// slots 7 and 8. `flag` is unused.
// FUNCTION: TITANIUM 0x004EF58E
// @early-stop: budget, structural ndiff=10
void CCharacterCreationView_guess::CopyAppearanceToPlayer_guess(SystemSource_guess* system,
                                             Destination_guess* destination,
                                             int flag)
{
    if (system != 0) {
        CellHolder_guess* sourceCell = (CellHolder_guess*)((char*)&destination->nested_0008 +
            destination->nested_0008->vbase_offset);
        ((Cell_guess*)((char*)&g_cellDestination_guess->nested_0008 +
            g_cellDestination_guess->nested_0008->vbase_offset))->SetFace_guess(
                sourceCell->data_0004.GetCharInfo2()->face_11d0_guess);

        g_cellDestination_guess->SetFirst_guess(destination->GetFirst_guess());
        g_cellDestination_guess->SetSecond_guess(destination->GetSecond_guess());
        g_cellDestination_guess->SetThird_guess(system->field_0249);
        g_cellDestination_guess->SetFourth_guess(destination->GetFourth_guess());
        g_cellDestination_guess->SetFifth_guess(destination->GetFifth_guess());
        g_cellDestination_guess->SetSixth_guess(system->field_0248);

        {
            CellHolder_guess* sourceCell = (CellHolder_guess*)((char*)&destination->nested_0008 +
                destination->nested_0008->vbase_offset);
            system->faceHair_024d_guess = sourceCell->data_0004.GetCharInfo2()->face_11d0_guess;
        }
        system->field_024a = destination->GetFirst_guess();
        system->beardColor_0246_guess = destination->GetSecond_guess();
        system->field_0249 = destination->GetThird_guess();
        system->hairColor_0245_guess = destination->GetFourth_guess();
        system->eyeColor1_0247_guess = destination->GetFifth_guess();
        system->field_0248 = destination->GetSixth_guess();

        CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination->nested_0008 +
            destination->nested_0008->vbase_offset);
        char savedValue = (char)cell->data_0004.GetCharInfo2()->class_119c_guess;
        cell = (CellHolder_guess*)((char*)&destination->nested_0008 +
            destination->nested_0008->vbase_offset);
        int count = cell->data_0004.GetCharInfo2()->race_1198_guess;
        cell = (CellHolder_guess*)((char*)&destination->nested_0008 +
            destination->nested_0008->vbase_offset);
        int firstValue = cell->data_0004.GetCharInfo2()->gender_1194_guess;
        g_controlPanel_guess->RebuildPlayerActor_guess(system,
            firstValue, count - 1, 0, savedValue);

        int slot = 0;
        if (g_systemSource_guess->activation_01a8->activation_0004 == 0) {
            g_systemSource_guess->activation_01a8->activation_0004 =
                g_systemSource_guess->CreateUserLight_guess(
                    g_clientSettings_guess->value_2878, 0x4b);
            g_systemSource_guess->activation_01a8->activation_0004->Activate_guess(1);
        }

        int index = 0;
        do {
            system->SetArmorType_guess(index, 0);
            system->SetArmorTint_guess(index, 0);
            ++index;
        } while (index < 9);

        do {
            system->HandleMaterialEx_guess(slot, destination->GetSlot_guess(slot),
                                  system->GetSlot_guess(slot, 0, 1));
            ++slot;
        } while (slot < 9);

        CellHolder_guess* languageCell = (CellHolder_guess*)((char*)&destination->nested_0008 +
            destination->nested_0008->vbase_offset);
        system->SetLanguage_guess(languageCell->data_0004.GetCharInfo2()->face_11d0_guess,
                                  system->faceHair_024d_guess);
        system->AddMessage_guess(7, g_messageText_guess, 1);
        system->AddMessage_guess(8, g_messageText_guess, 1);
    }
}

// Sends OP_CharacterCreate (CharCreate_Struct, 0x50 bytes): class, hair, beard, gender, race, start city,
// deity, the seven stats, face, eyes and the tutorial box. Then clears the name and, when 0x923D5C is set,
// saves the race's language as Defaults/DefaultLanguage in eqclient.ini.
// FUNCTION: TITANIUM 0x004EF7EE
void CCharacterCreationView_guess::SendCharacterCreate_guess()
{
    ClientInfoPacket_guess packet;
    memset(&packet, 0, sizeof(packet));

    packet.field_01c = g_systemSource_guess->field_0249;
    packet.field_004 = g_systemSource_guess->hairColor_0245_guess;
    packet.field_008 = g_systemSource_guess->field_024a;
    packet.field_00c = g_systemSource_guess->beardColor_0246_guess;
    packet.field_044 = g_systemSource_guess->eyeColor1_0247_guess;
    packet.field_048 = g_systemSource_guess->field_0248;
    packet.field_040 = g_systemSource_guess->faceHair_024d_guess;

    CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                                                 destination_0160->nested_0008->vbase_offset);
    packet.field_014 = cell->data_0004.GetCharInfo2()->race_1198_guess;
    cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                               destination_0160->nested_0008->vbase_offset);
    packet.field_000 = cell->data_0004.GetCharInfo2()->class_119c_guess;
    packet.field_020 = destination_0160->GetDeity_guess();
    packet.field_018 = field_0164;
    cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                               destination_0160->nested_0008->vbase_offset);
    packet.field_010 = cell->data_0004.GetCharInfo2()->gender_1194_guess;
    packet.field_04c = field_0420;

    for (int i = 0; i < 7; ++i)
        packet.array_024[i] = *array_0228[i];

    EQSendMessage(&g_messageTarget_guess, OP_CharacterCreate, &packet, 0x50, 1);

    ((NameBlock_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset))->first_003c = 0;

    if (g_defaultsEnabled_guess != 0) {
        cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                                   destination_0160->nested_0008->vbase_offset);
        int value = cell->data_0004.GetCharInfo2()->race_1198_guess;
        FUN_0060beb0_guess("Defaults", "DefaultLanguage",
            GetDefaultLanguageForRace_guess(value),
            ".\\eqclient.ini");
    }
}

// Right-clicking a stat name lands here; the stat's maximum caps it and the rest stays in the pool.
// FUNCTION: TITANIUM 0x004EFB80
void CCharacterCreationView_guess::AddRemainingPointsToStat_guess(int index)
{
    *array_0228[index] += points_0170;
    points_0170 = 0;
    if (*array_0228[index] > max_0190[index]) {
        points_0170 = *array_0228[index] - max_0190[index];
        *array_0228[index] = max_0190[index];
    }
    UpdateScreenZeroButtons_guess(0);
}

// Rolls the starting stats: race base (0x417355) plus class part (0x419DFD) for each stat. The pool is 50
// less the class parts; the maximum is the start plus 25, capped at 150; stats with a class part show green.
// The switch maps display order (STR STA AGI DEX WIS INT CHA) onto the tables' (STR DEX AGI STA INT WIS CHA).
// FUNCTION: TITANIUM 0x004EFBCB
// @early-stop: budget, diff ndiff=17
void CCharacterCreationView_guess::InitializeCharacterStats_guess(bool value)
{
    int cost;
    int slot;
    points_0170 = 50;
    for (int i = 0; i < 7; ++i) {
        switch (i) {
        case 1: slot = 3; break;
        case 2: slot = 2; break;
        case 3: slot = 1; break;
        case 4: slot = 5; break;
        case 5: slot = 4; break;
        default: slot = i; break;
        }
        int level = profile_0160->GetProfile_guess()->race_1198_guess;
        unsigned char second = profile_0160->GetProfile_guess()->class_119c_guess;
        cost = (unsigned char)destination_0160->skill_c280.ClassMin_guess(
            second - 1, level - 1, slot);
        int** slotRef = &array_0228[i];
        *(*slotRef) = (unsigned char)destination_0160->skill_c280.FUN_00417355_guess(
            profile_0160->GetProfile_guess()->race_1198_guess - 1, slot) + cost;
        int* slotVal = *slotRef;
        base_0174[i] = *slotVal;
        int max = *slotVal + 0x19;
        int* maxRef = max_0190 + i;
        *maxRef = max;
        if (max > 0x96)
            *maxRef = 0x96;
        if (cost > 0) {
            points_0170 -= cost;
            if (display_0348[i] != 0)
                display_0348[i]->field_007c = (int)0xff00ff00;
        } else {
            if (display_0348[i] != 0)
                display_0348[i]->field_007c = -1;
        }
    }
    if (value)
        UpdateScreenZeroButtons_guess(0);
}

// Rerolls the stats and resets the deity: enables the deities the race and class allow (0x419E83) and
// picks the first; then the cities and screen 0.
// FUNCTION: TITANIUM 0x004EFD37
void CCharacterCreationView_guess::ResetStatsAndDeity_guess()
{
    InitializeCharacterStats_guess(0);
    destination_0160->SetDeity_guess(0);
    for (int i = 0; i < 17; ++i) {
        if (slot_0394[i] != 0) {
            slot_0394[i]->SetCheck(0);
            if (destination_0160->skill_c280.CanWorship_guess(-1, -1, i) != 0) {
                if (destination_0160->GetDeity_guess() == 0) {
                    SetNewPCDeityFromBtnIndex_guess(i);
                    slot_0394[i]->SetCheck(1);
                }
                slot_0394[i]->flag_005d = 1;
            } else {
                slot_0394[i]->flag_005d = 0;
            }
        }
    }
    UpdateCitySelectionButtons_guess();
    UpdateScreenZeroButtons_guess(0);
}

// Mirrors the new character onto the model (pLocalPlayer): name, level, deity, class, race and look
// (CopyAppearanceToPlayer_guess), then redraws screen 0.
// FUNCTION: TITANIUM 0x004EFDC9
void CCharacterCreationView_guess::UpdatePreviewModel_guess()
{
    if (g_systemSource_guess != 0) {
        g_systemSource_guess->FUN_0047c3ef_guess(
            &((NameBlock_guess*)((char*)&destination_0160->nested_0008 +
                                 destination_0160->nested_0008->vbase_offset))->first_003c);
        {
            CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                                                         destination_0160->nested_0008->vbase_offset);
            g_systemSource_guess->level_024c_guess = cell->data_0004.GetCharInfo2()->level_11a4_guess;
        }
        g_systemSource_guess->deity_0280_guess = destination_0160->GetDeity_guess();
        {
            CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                                                         destination_0160->nested_0008->vbase_offset);
            g_systemSource_guess->playerClass_0252_guess = cell->data_0004.GetCharInfo2()->class_119c_guess;
        }
        {
            CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                                                         destination_0160->nested_0008->vbase_offset);
            g_systemSource_guess->SetRace_guess(cell->data_0004.GetCharInfo2()->race_1198_guess);
        }
        CopyAppearanceToPlayer_guess(g_systemSource_guess, destination_0160, 1);
        g_pending_guess->Flush_guess();
        UpdateScreenZeroButtons_guess(0);
    }
}

// Class button `index`: sets the class, rerolls stats, deity and city, updates the model, and warns when the
// class needs an expansion.
// FUNCTION: TITANIUM 0x004EFEAF
void CCharacterCreationView_guess::SelectClass_guess(int index)
{
    unsigned char value = (unsigned char)entries_01e8[index];
    Cell_guess* cell = (Cell_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset);
    cell->SetClass_guess(value);
    ResetStatsAndDeity_guess();
    UpdatePreviewModel_guess();
    CheckExpansionLocked_guess(0, 1);
}

// Handles the OP_ApproveName answer (tu_042 passes its first byte; -1 is the local 'Name is not valid').
// 1 creates the character (OP_CharacterCreate) and turns the first-time help off; 2 and 3 are server limits
// (one character per server; three on one deity team). Those close the window (+0x418); anything else
// reports the name rejected and goes back to screen 1.
// FUNCTION: TITANIUM 0x004EFEF1
void CCharacterCreationView_guess::HandleApproveName_guess(int mode)
{
    switch (mode) {
    case 1:
        if (g_pending_guess != 0) {
            g_pending_guess->SetBuffer_guess(
                &((NameBlock_guess*)((char*)&destination_0160->nested_0008 +
                                     destination_0160->nested_0008->vbase_offset))->first_003c);
        }
        SendCharacterCreate_guess();
        reset_015c.Reset_guess(-1);
        FUN_0060beb0_guess("Defaults", "ShowCreationHelp", "FALSE", ".\\eqclient.ini");
        break;
    case 2:
        g_errorQueue_guess->Refresh_guess();
        pConfirmationDialogPool_guess->Activate(
            (void*)(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0), 0xb,
            pStringTable->getString(0x637, 0), 1, 45000, 0, 0);
        break;
    case 3:
        g_errorQueue_guess->Refresh_guess();
        pConfirmationDialogPool_guess->Activate(
            (void*)(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0), 0xb,
            pStringTable->getString(0x157e, 0), 1, 45000, 0, 0);
        break;
    default:
        g_errorQueue_guess->Refresh_guess();
        if (mode == -1) {
            pConfirmationDialogPool_guess->Activate(
                (void*)(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0), 100,
                pStringTable->getString(0x628, 0), 1, 45000, 0, 0);
        } else {
            pConfirmationDialogPool_guess->Activate(
                (void*)(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0), 100,
                pStringTable->getString(0x62d, 0), 1, 45000, 0, 0);
        }
        SetScreen_guess(1);
        field_016c = 0;
        return;
    }
    field_0418 = 1;
}

// Checks the name locally (IsValidName_guess), then sends OP_ApproveName (name, race, class, deity; 0x4C
// bytes). steve_strncpy_guess keeps 15 characters. Input waits (+0x16C) for the answer (Notify_guess).
// FUNCTION: TITANIUM 0x004F002F
void CCharacterCreationView_guess::SubmitNameToWorld_guess()
{
    NamePacket_guess packet;
    memset(&packet, 0, sizeof(packet));
    if (nameInput_0388 == 0) {
        HandleApproveName_guess(-1);
        return;
    }
    steve_strncpy_guess(profile_0160->GetName_guess(), nameInput_0388->GetText_guess(), 16);
    if (g_nameChecker_guess->IsValidName_guess(profile_0160->name_003c) == 0) {
        HandleApproveName_guess(-1);
        return;
    }
    field_016c = g_display_guess->field_0148;
    g_errorQueue_guess->Refresh_guess();
    pConfirmationDialogPool_guess->Activate(
        (void*)(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0), 100,
        pStringTable->getString(0x62c, 0), 1, 45000, 0, 0);
    FUN_0060e450_guess(packet.name_000, profile_0160->name_003c);
    packet.field_040 = profile_0160->GetProfile_guess()->race_1198_guess;
    packet.field_044 = profile_0160->GetProfile_guess()->class_119c_guess;
    packet.field_048 = destination_0160->GetDeity_guess();
    EQSendMessage(&g_messageTarget_guess, OP_ApproveName, &packet, 0x4c, 1);
}

// `first`: a random race, rerolled until the account owns its expansion; `second`: a random gender.
// Then a random face, a random class the race allows, and the stat, deity, city and model updates.
// The race buttons call it with neither, for the random class only.
// FUNCTION: TITANIUM 0x004F02BE
void CCharacterCreationView_guess::RandomizeCharacter_guess(bool first, bool second)
{
    int allowed[16];
    int count = 0;

    if (first) {
        bool ok;
        do {
            ((Cell_guess*)((char*)&destination_0160->nested_0008 +
                destination_0160->nested_0008->vbase_offset))
                ->Set1198_guess(entries_01ac[RandomRange_guess(0, 14)]);
            ok = true;
            CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                destination_0160->nested_0008->vbase_offset);
            if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x80 && g_condition80_guess == 0)
                ok = false;
            cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                destination_0160->nested_0008->vbase_offset);
            if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x82 && g_condition82_guess == 0)
                ok = false;
            cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
                destination_0160->nested_0008->vbase_offset);
            if (cell->data_0004.GetCharInfo2()->race_1198_guess == 0x14a && g_condition14a_guess == 0)
                ok = false;
        } while (!ok);
    }

    if (second) {
        ((Cell_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset))
            ->SetGender_guess(RandomRange_guess(0, 1));
    }

    CellHolder_guess* cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset);
    g_systemSource_guess->SetRace_guess(cell->data_0004.GetCharInfo2()->race_1198_guess);
    cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset);
    g_systemSource_guess->gender_024e_guess = cell->data_0004.GetCharInfo2()->gender_1194_guess;

    RandomizeFace_guess();

    for (int i = 0; i < 16; ++i) {
        cell = (CellHolder_guess*)((char*)&destination_0160->nested_0008 +
            destination_0160->nested_0008->vbase_offset);
        int language = cell->data_0004.GetCharInfo2()->race_1198_guess;
        if (destination_0160->skill_c280.CheckClass_guess(language - 1, entries_01e8[i] - 1))
            allowed[count++] = entries_01e8[i];
    }
    if (count > 0)
        --count;

    ((Cell_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset))
        ->SetClass_guess((unsigned char)allowed[RandomRange_guess(0, count)]);
    ResetStatsAndDeity_guess();
    UpdatePreviewModel_guess();
}

// Race button `index`: sets the race, rolls a random legal class, and warns when the race needs an
// expansion.
// FUNCTION: TITANIUM 0x004F04AF
void CCharacterCreationView_guess::SelectRace_guess(int index)
{
    Cell_guess* cell = (Cell_guess*)((char*)&destination_0160->nested_0008 +
        destination_0160->nested_0008->vbase_offset);
    cell->Set1198_guess(entries_01ac[index]);
    RandomizeCharacter_guess(0, 0);
    CheckExpansionLocked_guess(1, 0);
}

// New character: clears everything, then a random race, gender and class.
// FUNCTION: TITANIUM 0x004F04EC
void CCharacterCreationView_guess::Reset_guess()
{
    ResetCreationState_guess();
    ResetStatsAndDeity_guess();
    RandomizeCharacter_guess(1, 1);
}

// Next button (tu_044 calls it too): screen 0 needs every point spent (strings 0x629, 0x62A) and the
// expansions; screen 1 submits the name.
// FUNCTION: TITANIUM 0x004F01D0
void CCharacterCreationView_guess::OnNextButton_guess()
{
    char text[512];
    if (field_041c == 0) {
        if (points_0170 > 0) {
            sprintf(text, "%s %s", pStringTable->getString(0x629, 0),
                pStringTable->getString(0x62a, 0));
            g_errorQueue_guess->Refresh_guess();
            g_errorQueue_guess->Activate(pinstCCharacterCreation_guess != 0 ? pinstCCharacterCreation_guess + 0x15c : 0,
                100, text, 1, 5000, 0, 0);
            return;
        }
        if (CheckExpansionLocked_guess(1, 1))
            return;
    }
    int next = field_041c + 1;
    if (next >= 2) {
        g_effectSystem_004ee978_guess->PlayMp3_guess(EQ_ARRAY(char, 0x0063F53F), 1.0f);
        SubmitNameToWorld_guess();
    } else {
        SetScreen_guess(next);
    }
}

struct SidlPiece_guess {
    char pad_0000[0x60];
    unsigned int style_0060;
};

struct CharacterData_guess : DestinationPrefix_004ed258_guess,
                             virtual DestinationBase_004ed258_guess {
    // EXTERNAL: TITANIUM 0x004BF2A7 CharacterData_guess::CharacterData_guess
    CharacterData_guess();
    char pad_000c[0xC4D0 - 16];
};

struct CreationChildWnd_guess {
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
    virtual void Slot48_guess(int value, int flag);
};

// Builds the window and the new character's data (0xC4D0 bytes). The 31 ints at +0x1AC are the button ids,
// both alphabetical: 15 races (2 6 8 3 12 7 11 5 1 128 10 9 130 4 330: Barbarian ... Froglok), then 16
// classes (8 15 16 2 6 14 13 7 11 3 4 9 5 10 1 12: Bard ... Wizard). 0x923D66 hides the tutorial box.
// FUNCTION: TITANIUM 0x004EF965
CCharacterCreation_guess::CCharacterCreation_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "CharacterCreation", 0, 1, 0), when_0244(-1)
{
    destination_0160 = 0;
    ((Updated_guess*)this)->Clear_guess();
    SidlPiece_guess* piece = (SidlPiece_guess*)((CSidlScreenWnd*)this)->SidlPiece;
    if (piece != 0) {
        ((CSidlScreenWnd*)this)->WindowStyle |= piece->style_0060;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        ((CreationScreen_guess*)this)->Initialize_guess();
        int* table = table_01ac;
        table[0] = 2;
        table[1] = 6;
        table[2] = 8;
        table[3] = 3;
        table[4] = 0xc;
        table[5] = 7;
        table[6] = 0xb;
        table[7] = 5;
        table[8] = 1;
        table[9] = 0x80;
        table[10] = 10;
        table[11] = 9;
        table[12] = 0x82;
        table[13] = 4;
        table[14] = 0x14a;
        table[15] = 8;
        table[16] = 0xf;
        table[17] = 0x10;
        table[18] = 2;
        table[19] = 6;
        table[20] = 0xe;
        table[21] = 0xd;
        table[22] = 7;
        table[23] = 0xb;
        table[24] = 3;
        table[25] = 4;
        table[26] = 9;
        table[27] = 5;
        table[28] = 10;
        table[29] = 1;
        table[30] = 0xc;
        destination_0160 = (Destination_004ed258_guess*)new CharacterData_guess;
        if (EQ_GLOBAL(unsigned char, 0x00923D66) != 0 && tutorialButton_0280 != 0)
            ((CreationChildWnd_guess*)tutorialButton_0280)->Slot48_guess(0, 1);
        ResetCreationState_guess();
    }
}

// Help window: slot 48 (+0xC0) shows it, slot 63 (+0xFC) sets its text.
struct HelpWnd_guess {
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
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess();
    virtual void Slot42_guess(); virtual void Slot43_guess(); virtual void Slot44_guess();
    virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Show_guess(int show, int bringToTop);
    virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess();
    virtual void Slot55_guess(); virtual void Slot56_guess(); virtual void Slot57_guess();
    virtual void Slot58_guess(); virtual void Slot59_guess(); virtual void Slot60_guess();
    virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void SetWindowText_guess(const CXStr& text);
};

#define g_raceHelp_guess EQ_ARRAY(int, 0x007919D8)
#define g_classHelp_guess EQ_ARRAY(int, 0x00791A18)
#define g_statHelp_guess EQ_ARRAY(int, 0x00791A58)

// Ignored while a name is with the server. Right click (3) shows a race, class or stat help text (id
// tables 0x7919D8, 0x791A18, 0x791A58); on a stat it also adds the points left. Click (1) handles the
// buttons; Get Name sends OP_RandomNameGenerator (race, gender, "Bob") and locks itself for 3 clock units.
// Message 14 from the name field copies the text to the profile and model; 10 from the help stops its sound.
// FUNCTION: TITANIUM 0x004F0508
// @early-stop: budget, structural ndiff=140
int CCharacterCreationView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data)
{
    if (field_016c == 0) {
        if (message == 3) {
            if (stml_038c != 0) {
                int text = -1;
                int i;
                for (i = 0; i < 15; ++i) {
                    if (sender == race_0294[i])
                        text = g_raceHelp_guess[i];
                }
                for (i = 0; i < 16; ++i) {
                    if (sender == class_02d0[i])
                        text = g_classHelp_guess[i];
                }
                for (i = 0; i < 7; ++i) {
                    if (sender == stat_0364[i]) {
                        stml_038c->SetSTMLText(pStringTable->getString(g_statHelp_guess[i], 0), true, 0);
                        AddRemainingPointsToStat_guess(i);
                        return 0;
                    }
                }
                if (text != -1)
                    stml_038c->SetSTMLText(pStringTable->getString(text, 0), true, 0);
            }
        } else if (message == 1) {
            if (sender == back_0278) {
                ((Owner_004ee978_guess*)this)->OnBackButton_guess();
            } else if (sender == next_027c) {
                OnNextButton_guess();
            // Page 1 (+0x41C is 0: race, class, gender and stats) and page 2 handle their own buttons; Help
            // on each shows its help text (strings 5874, 5875) with a voice-over (CharCreateHelp1.wav,
            // CharCreateHelp2.wav).
            } else if (field_041c == 0) {
                if (sender == helpButton_0274) {
                    if (stage_0390 != 0 && help_0270 != 0) {
                        ((CStmlWnd*)stage_0390)->SetSTMLText(pStringTable->getString(0x16f2, 0), true, 0);
                        {
                            CXStr text(pStringTable->getString(0x16f4, 0));
                            help_0270->SetWindowText_guess(text);
                        }
                        help_0270->Show_guess(1, 1);
                        g_effectSystem_004ee978_guess->SetMusicSelection_guess(4, 0);
                        g_effectSystem_004ee978_guess->PlayMp3_guess(EQ_ARRAY(char, 0x0063F53F), 1.0f);
                        g_effectSystem_004ee978_guess->PlayMp3_guess("CharCreateHelp1.wav", 1.0f);
                    }
                } else if (sender == face_0288) {
                    pinstCFacePick_guess->Activate();
                    ((HelpWnd_guess*)this)->Show_guess(0, 1);
                } else if (sender == male_028c) {
                    profile_0160->GetProfile_guess()->gender_1194_guess = 0;
                    g_systemSource_guess->gender_024e_guess = 0;
                    RandomizeFace_guess();
                    UpdatePreviewModel_guess();
                } else if (sender == female_0290) {
                    profile_0160->GetProfile_guess()->gender_1194_guess = 1;
                    g_systemSource_guess->gender_024e_guess = 1;
                    RandomizeFace_guess();
                    UpdatePreviewModel_guess();
                } else if (sender == pointsButton_0380) {
                    InitializeCharacterStats_guess(1);
                } else {
                    int i;
                    for (i = 0; i < 7; ++i) {
                        // Stat up/down buttons spend and refund the free points.
                        if (sender == up_0310[i]) {
                            if (points_0170 > 0 && *array_0228[i] + 1 <= max_0190[i]) {
                                ++*array_0228[i];
                                --points_0170;
                                UpdateScreenZeroButtons_guess(0);
                            }
                            return 0;
                        }
                        if (sender == down_032c[i]) {
                            if (*array_0228[i] - 1 >= base_0174[i]) {
                                --*array_0228[i];
                                ++points_0170;
                                UpdateScreenZeroButtons_guess(0);
                            }
                            return 0;
                        }
                        if (sender == stat_0364[i] && stml_038c != 0)
                            stml_038c->SetSTMLText(pStringTable->getString(g_statHelp_guess[i], 0), true, 0);
                    }
                    for (i = 0; i < 15; ++i) {
                        if (sender == race_0294[i]) {
                            SelectRace_guess(i);
                            if (stml_038c != 0)
                                stml_038c->SetSTMLText(pStringTable->getString(g_raceHelp_guess[i], 0), true, 0);
                            return 0;
                        }
                    }
                    for (i = 0; i < 16; ++i) {
                        if (sender == class_02d0[i]) {
                            SelectClass_guess(i);
                            if (stml_038c != 0)
                                stml_038c->SetSTMLText(pStringTable->getString(g_classHelp_guess[i], 0), true, 0);
                            return 0;
                        }
                    }
                }
            } else if (field_041c == 1) {
                if (sender == helpButton_0274) {
                    if (stage_0390 != 0 && help_0270 != 0) {
                        ((CStmlWnd*)stage_0390)->SetSTMLText(pStringTable->getString(0x16f3, 0), true, 0);
                        {
                            CXStr text(pStringTable->getString(0x16f4, 0));
                            help_0270->SetWindowText_guess(text);
                        }
                        help_0270->Show_guess(1, 1);
                        g_effectSystem_004ee978_guess->SetMusicSelection_guess(4, 0);
                        g_effectSystem_004ee978_guess->PlayMp3_guess(EQ_ARRAY(char, 0x0063F53F), 1.0f);
                        g_effectSystem_004ee978_guess->PlayMp3_guess("CharCreateHelp2.wav", 1.0f);
                    }
                // Get Name: OP_RandomNameGenerator (0x23D4).
                } else if (sender == getName_0284) {
                    struct {
                        int race;
                        int gender;
                        char text[0x40];
                    } request;
                    request.race = profile_0160->GetProfile_guess()->race_1198_guess;
                    request.gender = profile_0160->GetProfile_guess()->gender_1194_guess;
                    FUN_0060e450_guess(request.text, EQ_ARRAY(char, 0x0065271C));
                    EQSendMessage(&g_messageTarget_guess, OP_RandomNameGenerator, &request, 0x48, 1);
                    when_0244 = Now_guess() + 3;
                } else if (sender == tutorial_0280) {
                    if (tutorial_0280 != 0) {
                        field_0420 = !field_0420;
                        tutorial_0280->SetCheck(field_0420);
                    }
                } else {
                    int i;
                    for (i = 0; i < 17; ++i) {
                        if (sender == (CXWnd*)slot_0394[i]) {
                            SetNewPCDeityFromBtnIndex_guess(i);
                            return 0;
                        }
                    }
                    for (i = 0; i < 15; ++i) {
                        if (sender == (CXWnd*)city_03d8[i]) {
                            ((LanguageOwner_guess*)this)->SetStartCity_guess(i);
                            return 0;
                        }
                    }
                }
            }
        } else if (message == 14) {
            if (field_041c == 1 && sender == (CXWnd*)nameInput_0388) {
                ((NameBuffer_guess*)profile_0160->name_003c)->Copy_guess(nameInput_0388->GetText_guess());
                pLocalPlayer_guess->SetName_guess(profile_0160->name_003c);
                pLocalPlayer_guess->RefreshNameSprite_guess();
            }
        } else if (message == 10) {
            if (sender == (CXWnd*)help_0270)
                g_effectSystem_004ee978_guess->PlayMp3_guess(EQ_ARRAY(char, 0x0063F53F), 1.0f);
        }
    }
    return ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(sender, message, data);
}
