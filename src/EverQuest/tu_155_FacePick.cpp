// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 155: a hint from compare/tumap.py.
// The face picker ("FacePickWindow", CFacePick_guess): Down/Up steppers for face, hair, hair colour,
// eyes, beard, beard colour and woad, plus Random, Accept and Cancel. EQPlayerView_guess is a view of
// EQPlayer
// (gSetting_guess is pinstLocalPlayer, 0x905CE4); changes show on the model at once and Accept sends them
// as OP_FaceChange.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CBodyTintWnd.h"
#include "titanium/wnd/CCharacterCreation.h"

struct Name_guess;

struct VisualTarget_guess {
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
    virtual void Apply_guess(int value, int enabled);
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
    virtual void SetText_guess(const Name_guess& text);

    // EXTERNAL: TITANIUM 0x005A06C0 VisualTarget_guess::Refresh_guess
    void Refresh_guess();
};

struct ByteTarget_guess {
    char pad_000_guess[0x60];
    unsigned char value_060_guess;
};

struct WindowHeader_guess {
    char pad_000_guess[0x60];
    unsigned int value_060_guess;
};

struct Name_guess {
    char* value_guess;

    // EXTERNAL: TITANIUM 0x00571E00 Name_guess::Set_guess
    void Set_guess(const char* value);
    // EXTERNAL: TITANIUM 0x00571D00 Name_guess::Release_guess
    void Release_guess(char* value);

    Name_guess(const char* value) {
        Set_guess(value);
    }

    ~Name_guess() {
        if (value_guess != 0) {
            Release_guess(value_guess);
        }
        value_guess = 0;
    }
};

struct BaseWindow_guess {
    virtual void Init_guess() = 0;
    virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess(); virtual void Slot04_guess();
    virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess();
    virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess();
    virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess();
    virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot20_guess();
    virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess(); virtual void Slot24_guess();
    virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess(); virtual void Slot28_guess();
    virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess();
    virtual void Slot33_guess(); virtual void Slot34_guess();
    char pad_000_guess[0x5c];
    unsigned int state_060_guess;
    unsigned int flags_064_guess;
    char pad_068_guess[0xbc];
    WindowHeader_guess* current_124_guess;
    char pad_128_guess[0x30];
    int state_158_guess;
    VisualTarget_guess* state_15c_guess;
    VisualTarget_guess* state_160_guess;
    VisualTarget_guess* state_164_guess;

    // EXTERNAL: TITANIUM 0x005A3850 BaseWindow_guess::BaseWindow_guess
    BaseWindow_guess(void* parent, const Name_guess& name, int first, int second, int third);
    ~BaseWindow_guess() {}
    // EXTERNAL: TITANIUM 0x005A25B0 BaseWindow_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A0650 BaseWindow_guess::Finish_guess
    void Finish_guess();
    // EXTERNAL: TITANIUM 0x005A1E10 BaseWindow_guess::GetChildItem
    VisualTarget_guess* GetChildItem(const Name_guess& name);
    // EXTERNAL: TITANIUM 0x005A2490 BaseWindow_guess::FindText_guess
    ByteTarget_guess* FindText_guess(const Name_guess& name);
};

struct SettingDetails_guess {
    char pad_000_guess[0x34];
    char active_034_guess;
};

struct SettingBranch_guess {
    char pad_000_guess[0x12c];
    SettingDetails_guess* details_12c_guess;
};

struct EQPlayerView_guess {
    char pad_000_guess[0x4c];
    float float_04c_guess;
    char pad_050_guess[0x120 - 0x50];
    char text_120_guess[0x88];
    SettingBranch_guess* branch_1a8_guess;
    char pad_1ac_guess[0x58];
    int zone_204_guess;
    char pad_208_guess[0x3d];
    unsigned char hairColor_0245_guess;
    unsigned char beardColor_0246_guess;
    unsigned char eyeColor1_0247_guess;
    unsigned char value_248_guess;
    unsigned char value_249_guess;
    unsigned char value_24a_guess;
    char pad_24b_guess[1];
    unsigned char level_024c_guess;
    unsigned char faceHair_024d_guess;
    unsigned char gender_024e_guess;
    char pad_24f_guess[3];
    unsigned char playerClass_0252_guess;
    char pad_253_guess[0xd];
    int race_0260_guess;

    // EXTERNAL: TITANIUM 0x0047A491 EQPlayerView_guess::GetBaseFaceNbr_guess
    unsigned char GetBaseFaceNbr_guess(int value, char* output);
    // EXTERNAL: TITANIUM 0x0047A523 EQPlayerView_guess::GetHairKind_guess
    unsigned char GetHairKind_guess();
    // EXTERNAL: TITANIUM 0x0047A4E1 EQPlayerView_guess::GetBeardKind_guess
    unsigned char GetBeardKind_guess();
    // EXTERNAL: TITANIUM 0x00480130 EQPlayerView_guess::SetDefaultFacialFeaturesByFace_guess
    void SetDefaultFacialFeaturesByFace_guess(int value, int a, int b);
    // EXTERNAL: TITANIUM 0x00483B9B EQPlayerView_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00480614 EQPlayerView_guess::Mark_guess
    void Mark_guess(unsigned char value, int flag);
    // EXTERNAL: TITANIUM 0x0047A62D EQPlayerView_guess::CanHaveNoHair_guess
    int CanHaveNoHair_guess();
    // EXTERNAL: TITANIUM 0x00480614 EQPlayerView_guess::Select_guess
    int Select_guess(char digit, char kind);
    // EXTERNAL: TITANIUM 0x00480767 EQPlayerView_guess::SetFeatureColor_guess
    int SetFeatureColor_guess(int value, int kind);
};

#define gSetting_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)

struct ZoneInfo_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneInfo_guess::GetZoneName_guess
    void GetZoneName_guess(int zone, char* output, int flag);
};

#define gZoneInfo_guess EQ_GLOBAL(ZoneInfo_guess*, 0x00905CC0)

struct EverQuest_guess {
    char pad_000_guess[0xb54];
    int state_b54_guess;

    // EXTERNAL: TITANIUM 0x00491E5B EverQuest_guess::GetClassDesc
    const char* GetClassDesc(int value);
};

#define gEverQuest_guess EQ_GLOBAL(EverQuest_guess*, 0x00988DF0)
#define gNumberText_guess EQ_ARRAY(char, 0x0099DB00)
#define gSendFlag_guess EQ_GLOBAL(unsigned char, 0x00923798)

struct CharInfoBytes_guess {
    char pad_000_guess[0x11d0];
    unsigned char value_11d0_guess;
};

struct SettingBytes_guess {
    unsigned char value_245_guess;
    unsigned char value_246_guess;
    unsigned char value_247_guess;
    unsigned char value_248_guess;
    unsigned char value_249_guess;
    unsigned char value_24a_guess;
    unsigned char value_24d_guess;
};

struct CharSetters_guess {
    // EXTERNAL: TITANIUM 0x005ED6F0 CharSetters_guess::Set24a_guess
    void Set24a_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5F0 CharSetters_guess::Set246_guess
    void Set246_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED6B0 CharSetters_guess::Set249_guess
    void Set249_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5B0 CharSetters_guess::Set245_guess
    void Set245_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED630 CharSetters_guess::Set247_guess
    void Set247_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED670 CharSetters_guess::Set248_guess
    void Set248_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED690 CharSetters_guess::Get249_guess
    unsigned char Get249_guess();
    // EXTERNAL: TITANIUM 0x005ED590 CharSetters_guess::Get245_guess
    unsigned char Get245_guess();
    // EXTERNAL: TITANIUM 0x005ED6D0 CharSetters_guess::Get24a_guess
    unsigned char Get24a_guess();
    // EXTERNAL: TITANIUM 0x005ED5D0 CharSetters_guess::Get246_guess
    unsigned char Get246_guess();
    // EXTERNAL: TITANIUM 0x005ED610 CharSetters_guess::Get247_guess
    unsigned char Get247_guess();
    // EXTERNAL: TITANIUM 0x005ED650 CharSetters_guess::Get248_guess
    unsigned char Get248_guess();
};

#define gCharSetters_guess EQ_GLOBAL(CharSetters_guess*, 0x00905D00)

struct CharDataSet24d_guess {
    // EXTERNAL: TITANIUM 0x004B919F CharDataSet24d_guess::SetFace_guess
    void SetFace_guess(unsigned char value);
};

union CharDataProfile_guess {
    CharDataSet24d_guess setters_guess;
    EQ_Character character_guess;
};

struct CharDataLookup_guess {
    char pad_000_guess[8];
    CharDataProfile_guess profile_008_guess;
};

#define gCharDataLookup_guess EQ_GLOBAL(CharDataLookup_guess*, 0x00905D00)


// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int low, int high);

// EXTERNAL: TITANIUM 0x0046DA4A FormatMsg_guess
void __cdecl FormatMsg_guess(char* output, int id, ...);

struct CFacePick_guess : BaseWindow_guess {
    VisualTarget_guess* primary_guess[7];
    VisualTarget_guess* secondary_guess[7];
    ByteTarget_guess* values_guess[7];
    unsigned short value_1bc_guess;
    char pad_1be_guess[2];
    int state_1c0_guess;
    unsigned char state_1c4_guess;
    unsigned char state_1c5_guess;
    unsigned char state_1c6_guess;
    unsigned char state_1c7_guess;
    unsigned char state_1c8_guess;
    unsigned char state_1c9_guess;
    unsigned char state_1ca_guess;
    char settingText_guess[16];

    bool ExploreModeAboutToShow_guess();
    bool AboutToHide_guess();
    bool Enter_guess();
    void SetValue_guess(int index, int value);
    void SetFaceSelectionsFromPlayer_guess();
    void StepSetting_guess(int value, int apply);
    virtual void Init_guess();
    int WndNotification_guess(int sender, int message, void* data);

    CFacePick_guess(void* parent);
};

// EXTERNAL: TITANIUM 0x006540E0 ??_7CFacePick_guess@@6B@

// Binds the controls by their XML names: row i of primary_guess/secondary_guess/values_guess is the Down
// button, Up button and label of one feature (0 face, 1 hair, 2 hair colour, 3 eyes, 4 beard,
// 5 beard colour, 6 woad); +0x15C/+0x160/+0x164 are Random, Accept and Cancel.
// FUNCTION: TITANIUM 0x00500DF3
CFacePick_guess::CFacePick_guess(void* parent_guess)
    : BaseWindow_guess(parent_guess, Name_guess("FacePickWindow"), 0, 1, 0) {
    for (int index_guess = 0; index_guess < 7; ++index_guess) {
        primary_guess[index_guess] = 0;
        secondary_guess[index_guess] = 0;
        values_guess[index_guess] = 0;
    }

    state_15c_guess = 0;
    state_160_guess = 0;
    state_164_guess = 0;
    if (current_124_guess != 0) {
        flags_064_guess |= current_124_guess->value_060_guess | 0x10000;
        state_158_guess = 10;
        CreateChildrenFromSidl();

        primary_guess[0] = GetChildItem(Name_guess("Face_Down_Button"));
        secondary_guess[0] = GetChildItem(Name_guess("Face_Up_Button"));
        primary_guess[1] = GetChildItem(Name_guess("Hair_Down_Button"));
        secondary_guess[1] = GetChildItem(Name_guess("Hair_Up_Button"));
        primary_guess[2] = GetChildItem(Name_guess("Hair_Color_Down_Button"));
        secondary_guess[2] = GetChildItem(Name_guess("Hair_Color_Up_Button"));
        primary_guess[3] = GetChildItem(Name_guess("Eyes_Down_Button"));
        secondary_guess[3] = GetChildItem(Name_guess("Eyes_Up_Button"));
        primary_guess[4] = GetChildItem(Name_guess("Beard_Down_Button"));
        secondary_guess[4] = GetChildItem(Name_guess("Beard_Up_Button"));
        primary_guess[5] = GetChildItem(Name_guess("Beard_Color_Down_Button"));
        secondary_guess[5] = GetChildItem(Name_guess("Beard_Color_Up_Button"));
        primary_guess[6] = GetChildItem(Name_guess("Wode_Down_Button"));
        secondary_guess[6] = GetChildItem(Name_guess("Wode_Up_Button"));
        state_15c_guess = GetChildItem(Name_guess("Random_Button"));
        state_160_guess = GetChildItem(Name_guess("Accept_Button"));
        state_164_guess = GetChildItem(Name_guess("Cancel_Button"));
        values_guess[0] = FindText_guess(Name_guess("Face_Text"));
        values_guess[1] = FindText_guess(Name_guess("Hair_Text"));
        values_guess[2] = FindText_guess(Name_guess("Hair_Color_Text"));
        values_guess[3] = FindText_guess(Name_guess("Eyes_Text"));
        values_guess[4] = FindText_guess(Name_guess("Beard_Text"));
        values_guess[5] = FindText_guess(Name_guess("Beard_Color_Text"));
        values_guess[6] = FindText_guess(Name_guess("Wode_Text"));
        state_1c0_guess = 0;
        Init_guess();
    }
}

// AboutToShow of the explore-mode window (slot 49 of vtable 0x653DF0, ctor 0x004FFFD0 "ExploreModeWindow",
// tu_154; not CFacePick): puts string 0x1A19 (name, level, class name, zone) on the char-info label
// (+0x15C, EXW_CharInfoLabel) and refreshes +0x160; always true.
// FUNCTION: TITANIUM 0x005000BA
bool CFacePick_guess::ExploreModeAboutToShow_guess() {
    if (state_15c_guess != 0 && gSetting_guess != 0) {
        char zone_guess[512];
        char text_guess[1024];
        int zone_guess_id = gSetting_guess->zone_204_guess;
        gZoneInfo_guess->GetZoneName_guess(zone_guess_id, zone_guess, 1);
        unsigned char race_guess = gSetting_guess->playerClass_0252_guess;
        unsigned char count_guess = gSetting_guess->level_024c_guess;
        char* name_guess = gSetting_guess->text_120_guess;
        FormatMsg_guess(text_guess, 0x1a19, name_guess, _itoa(count_guess, gNumberText_guess, 10),
                        gEverQuest_guess->GetClassDesc(race_guess), zone_guess, 0, 0, 0, 0, 0);
        state_15c_guess->SetText_guess(Name_guess(text_guess));
    }
    if (state_160_guess != 0) {
        state_160_guess->Refresh_guess();
    }
    return true;
}

// Enables or disables row `index` (both buttons and the label) for `value`.
// FUNCTION: TITANIUM 0x005001E8
void CFacePick_guess::SetValue_guess(int index, int value) {
    if (index >= 0 && index < 7) {
        if (primary_guess[index] != 0) {
            primary_guess[index]->Apply_guess(value, 1);
        }
        if (secondary_guess[index] != 0) {
            secondary_guess[index]->Apply_guess(value, 1);
        }
        if (values_guess[index] != 0) {
            values_guess[index]->value_060_guess = (unsigned char)value;
        }
    }
}

// Copies the player's features into the edit bytes +0x1C4..+0x1CA (face, eye colours, hair style, beard,
// hair and beard colour) and the face code's tens digit (the woad variant, via GetBaseFaceNbr_guess) into
// settingText_guess[0].
// FUNCTION: TITANIUM 0x00500295
void CFacePick_guess::SetFaceSelectionsFromPlayer_guess() {
    if (gSetting_guess != 0) {
        state_1c8_guess = gSetting_guess->value_24a_guess;
        state_1ca_guess = gSetting_guess->beardColor_0246_guess;
        state_1c7_guess = gSetting_guess->value_249_guess;
        state_1c9_guess = gSetting_guess->hairColor_0245_guess;
        state_1c5_guess = gSetting_guess->eyeColor1_0247_guess;
        state_1c6_guess = gSetting_guess->value_248_guess;
        state_1c4_guess = gSetting_guess->faceHair_024d_guess;
        char* output_guess = settingText_guess;
        gSetting_guess->GetBaseFaceNbr_guess(gSetting_guess->faceHair_024d_guess, output_guess);
    }
}

// Steps one feature up (`value_guess` 1) or down, wrapping between its limits and skipping values the model
// refuses. Mode (+0x1C0): 1 face (`apply` 1: woad, Barbarians only), 2 hair (`apply` 1: colour), 3 eyes,
// 4 beard (`apply` 1: colour). Erudite hair and some beards (kind 2) are head models, so they step the face
// code's tens digit instead. Limits: face 0-7 (0-9 Froglok, race 330), colours 0-23, eyes 1-20 (Froglok
// from 0); the eyes step eye colour 2 and copy it to eye colour 1.
// FUNCTION: TITANIUM 0x0050032F
// @early-stop: budget, structural ndiff=213
void CFacePick_guess::StepSetting_guess(int value_guess, int apply_guess) {
    unsigned char state_guess = (unsigned char)state_1c0_guess;
    unsigned char count_guess;
    bool failed_guess = false;
    unsigned char limit_guess = 0x1d;
    unsigned char low_guess = 0;
    unsigned char* slot_guess = 0;

    switch (state_guess) {
    case 1:
        if (apply_guess == 0) {
            slot_guess = &state_1c4_guess;
            *slot_guess = (unsigned char)gSetting_guess->GetBaseFaceNbr_guess(*slot_guess, 0);
            limit_guess = 7;
            if (gSetting_guess->race_0260_guess == 0x14a) {
                limit_guess = 9;
            }
        } else {
            if (gSetting_guess->race_0260_guess != 2) {
                return;
            }
            limit_guess = 8;
            slot_guess = (unsigned char*)settingText_guess;
        }
        break;
    case 2:
        if (gSetting_guess->GetHairKind_guess() == 0) {
            return;
        }
        if (gSetting_guess->race_0260_guess == 3) {
            if (apply_guess != 0) {
                return;
            }
            limit_guess = gSetting_guess->gender_024e_guess != 0 ? 8 : 5;
            state_guess = 1;
            apply_guess = 1;
            slot_guess = (unsigned char*)settingText_guess;
        } else if (apply_guess == 0) {
            limit_guess = (unsigned char)(gSetting_guess->CanHaveNoHair_guess() + 2);
            slot_guess = &state_1c7_guess;
        } else {
            limit_guess = 0x17;
            slot_guess = &state_1c9_guess;
        }
        break;
    case 3:
        if (apply_guess != 0) {
            return;
        }
        slot_guess = &state_1c6_guess;
        low_guess = 1;
        limit_guess = 0x14;
        if (gSetting_guess->race_0260_guess == 0x14a) {
            low_guess = 0;
        }
        break;
    case 4: {
        unsigned char query_guess = gSetting_guess->GetBeardKind_guess();
        if (query_guess == 2) {
            if (apply_guess == 0) {
                limit_guess = gSetting_guess->race_0260_guess != 8 ? 3 : 1;
                state_guess = 1;
                apply_guess = 1;
                slot_guess = (unsigned char*)settingText_guess;
            } else {
                limit_guess = 0x17;
                slot_guess = &state_1ca_guess;
            }
        } else {
            if (query_guess == 0) {
                return;
            }
            if (apply_guess == 0) {
                slot_guess = &state_1c8_guess;
            } else {
                limit_guess = 0x17;
                slot_guess = &state_1ca_guess;
            }
        }
        break;
    }
    default:
        return;
    }

    count_guess = 0;
    if (value_guess == 0) {
        if (*slot_guess > limit_guess) {
            *slot_guess = limit_guess;
        }
        if (*slot_guess == low_guess) {
            *slot_guess = limit_guess;
        } else {
            *slot_guess = (unsigned char)(*slot_guess - 1);
        }
        value_guess = *slot_guess;
        if (value_guess >= low_guess) {
            do {
                int result_guess;
                if (apply_guess == 0) {
                    char digit_guess = (char)value_guess;
                    if (state_guess == 1 && settingText_guess[0] != 0) {
                        digit_guess = (char)(settingText_guess[0] * 10 + value_guess);
                    }
                    result_guess = gSetting_guess->Select_guess(digit_guess, state_guess);
                } else {
                    result_guess = gSetting_guess->SetFeatureColor_guess(value_guess, state_guess);
                }
                if (result_guess != 0) {
                    failed_guess = true;
                    break;
                }
                if (value_guess == limit_guess && gSetting_guess->CanHaveNoHair_guess() != 0) {
                    failed_guess = true;
                    break;
                }
                value_guess--;
            } while (value_guess >= low_guess);
        }
    } else {
        *slot_guess = (unsigned char)(*slot_guess + 1);
        if (*slot_guess > limit_guess) {
            *slot_guess = low_guess;
        }
        value_guess = *slot_guess;
        if (value_guess <= limit_guess) {
            do {
                int result_guess;
                if (apply_guess == 0) {
                    char digit_guess = (char)value_guess;
                    if (state_guess == 1 && settingText_guess[0] != 0) {
                        digit_guess = (char)(settingText_guess[0] * 10 + value_guess);
                    }
                    result_guess = gSetting_guess->Select_guess(digit_guess, state_guess);
                    if (result_guess != 0) {
                        failed_guess = true;
                        break;
                    }
                    if (value_guess == limit_guess) {
                        if (state_guess == 3 ||
                            (state_guess == 2 && gSetting_guess->CanHaveNoHair_guess() == 0) ||
                            (state_guess == 4 && gSetting_guess->race_0260_guess == 8 &&
                             gSetting_guess->gender_024e_guess == 0)) {
                            value_guess = low_guess - 1;
                            count_guess++;
                        }
                    }
                } else {
                    result_guess = gSetting_guess->SetFeatureColor_guess(value_guess, state_guess);
                    if (result_guess != 0) {
                        failed_guess = true;
                        break;
                    }
                }
                if (count_guess > 1) {
                    break;
                }
                value_guess++;
            } while (value_guess <= limit_guess);
        }
    }

    *slot_guess = (unsigned char)value_guess;
    if (state_guess == 3) {
        state_1c5_guess = state_1c6_guess;
    } else if (state_guess == 1 && apply_guess != 0) {
        if (!failed_guess) {
            *slot_guess = 0;
        }
    } else if (failed_guess) {
        if (state_guess == 2) {
            gSetting_guess->SetFeatureColor_guess(state_1c9_guess, 2);
        } else if (state_guess == 4) {
            gSetting_guess->SetFeatureColor_guess(state_1ca_guess, 4);
        }
    } else if (state_guess == 2) {
        if (gSetting_guess->CanHaveNoHair_guess() == 1) {
            *slot_guess = 0xff;
        }
    } else if (state_guess == 4) {
        if (gSetting_guess->race_0260_guess != 8) {
            *slot_guess = 0xff;
        }
    }
}

struct CharInfoMode_guess {
    char pad_000_guess[0x1198];
    int mode_1198_guess;
};

struct Stage_guess {
    // EXTERNAL: TITANIUM 0x004392DE Stage_guess::Enter_guess
    void Enter_guess(int value);
    // EXTERNAL: TITANIUM 0x004426FB Stage_guess::SetupCharacterViewCamera_guess
    void SetupCharacterViewCamera_guess(int value);
    // EXTERNAL: TITANIUM 0x0043C783 Stage_guess::RestoreCameraMode_guess
    void RestoreCameraMode_guess();
};
#define gStage_guess EQ_GLOBAL(Stage_guess*, 0x00905D24)

// Closing: in character creation (game state 2) puts the creation camera back and re-enables the creation
// window (0x850C20); otherwise restores the camera mode unless 0x923D7A is set.
// FUNCTION: TITANIUM 0x00500248
bool CFacePick_guess::AboutToHide_guess() {
    state_1c0_guess = 0;
    if (gEverQuest_guess->state_b54_guess == 2) {
        gStage_guess->SetupCharacterViewCamera_guess(0);
        pinstCCharacterCreation_guess->Show(1, 1);
    } else if (EQ_GLOBAL(unsigned char, 0x00923D7A) == 0) {
        gStage_guess->RestoreCameraMode_guess();
    }
    return true;
}

struct Viewer_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess(float value);
    virtual void Slot05_guess(float value);
    virtual void Slot06_guess(float value);
    virtual void Slot07_guess();
    virtual void Slot08_guess(float value);
    char pad_004_guess[0x28];
    float field_02c_guess;
    char pad_030_guess[4];
    float field_034_guess;
};
#define gViewer_guess EQ_GLOBAL(Viewer_guess*, 0x00925518)

// AboutToShow: refused with string 0xFC3 while the player's race differs from the character's (+0x1198 of
// CharInfo2, so under an illusion) outside character creation, or while the body tint window (0x850CAC) is
// open. Then switches to camera mode 7, frames the head (1.5 higher for Froglok) and shows context tip 10
// in the tip window (0x9928E0).
// FUNCTION: TITANIUM 0x005007D4
// @early-stop: budget, structural ndiff=27
bool CFacePick_guess::Enter_guess() {
    if (pCharData != 0) {
        int mode_guess = gSetting_guess->race_0260_guess;
        if (mode_guess != ((CharInfoMode_guess*)pCharData->GetCharInfo2())->mode_1198_guess &&
            (pinstCCharacterCreation_guess == 0 || pinstCCharacterCreation_guess->dShow == 0)) {
            pEverQuest->dsp_chat(pStringTable->getString(0xfc3, 0));
            return false;
        }
    }
    if (pinstCBodyTintWnd_guess != 0 && pinstCBodyTintWnd_guess->IsVisible_guess()) {
        return false;
    }
    CFacePick_guess::Init_guess();
    state_1c0_guess = 1;
    gStage_guess->Enter_guess(7);
    gViewer_guess->Slot01_guess();
    gStage_guess->SetupCharacterViewCamera_guess(100);
    gViewer_guess->Slot08_guess(gSetting_guess->float_04c_guess);
    gViewer_guess->Slot06_guess(gViewer_guess->field_034_guess + 1.5f);
    gViewer_guess->Slot05_guess(0.0f);
    if (gSetting_guess->race_0260_guess == 0x14a) {
        gViewer_guess->Slot04_guess(gViewer_guess->field_02c_guess + 1.5f);
    }
    if (pinstCTipWndCONTEXT_guess != 0) {
        pinstCTipWndCONTEXT_guess->selectTip_guess(10, 0);
    }
    BaseWindow_guess::Finish_guess();
    return true;
}

// Enables the rows the model supports. Old models (actor model +0x34 clear) keep only the face row; hair
// needs a hair kind (GetHairKind_guess), hair colour a kind other than 2 (Erudite), beard rows a
// beard kind (GetBeardKind_guess); woad is for Barbarians (race 2, race_0260_guess is Race) only.
// FUNCTION: TITANIUM 0x005006D3
void CFacePick_guess::Init_guess() {
    if (gSetting_guess == 0 ||
        gSetting_guess->branch_1a8_guess == 0 ||
        gSetting_guess->branch_1a8_guess->details_12c_guess == 0) {
        value_1bc_guess = 0;
        return;
    }

    unsigned char active_guess = gSetting_guess->branch_1a8_guess->details_12c_guess->active_034_guess;
    value_1bc_guess = (unsigned short)gSetting_guess->race_0260_guess;
    SetFaceSelectionsFromPlayer_guess();
    if (active_guess != 0) {
        SetValue_guess(3, 1);
    } else {
        SetValue_guess(3, 0);
    }

    if (active_guess == 0 || gSetting_guess->GetHairKind_guess() == 0) {
        SetValue_guess(1, 0);
        SetValue_guess(2, 0);
    } else {
        SetValue_guess(1, 1);
        if (gSetting_guess->GetHairKind_guess() != 2) {
            SetValue_guess(2, 1);
        } else {
            SetValue_guess(2, 0);
        }
    }

    if (active_guess == 0 || gSetting_guess->GetBeardKind_guess() == 0) {
        SetValue_guess(4, 0);
        SetValue_guess(5, 0);
    } else {
        SetValue_guess(4, 1);
        SetValue_guess(5, 1);
    }

    if (active_guess != 0 && gSetting_guess->race_0260_guess == 2) {
        SetValue_guess(6, 1);
    } else {
        SetValue_guess(6, 0);
    }
}

// Random: an old model rolls face 0-7; a newer one rolls a face with random features. Accept: commits the
// edit bytes; in character creation they go to pCharData, otherwise out as OP_FaceChange (7 bytes: hair
// colour, beard colour, eye colours 1 and 2, hair style, beard, face), or only to pCharData when 0x923798
// is set; then string 0x2EFC and close. Cancel: restores the character's stored features. The face itself
// was already applied while stepping, so Accept doesn't copy it back.
// FUNCTION: TITANIUM 0x00500936
// @early-stop: budget, structural ndiff=169
int CFacePick_guess::WndNotification_guess(int sender, int message, void* data) {
    if (message == 1) {
        if ((VisualTarget_guess*)sender == state_15c_guess) {
            if (gSetting_guess->branch_1a8_guess->details_12c_guess->active_034_guess == 0) {
                state_1c4_guess = (unsigned char)RandomRange_guess(0, 7);
                state_1c0_guess = 1;
                StepSetting_guess(1, 0);
                return 0;
            }
            int roll_guess = RandomRange_guess(0, 7);
            gSetting_guess->SetDefaultFacialFeaturesByFace_guess(roll_guess, 1, 1);
            gSetting_guess->Refresh_guess();
            return 0;
        }
        if ((VisualTarget_guess*)sender == state_160_guess) {
            gSetting_guess->value_24a_guess = state_1c8_guess;
            gSetting_guess->beardColor_0246_guess = state_1ca_guess;
            gSetting_guess->value_249_guess = state_1c7_guess;
            gSetting_guess->hairColor_0245_guess = state_1c9_guess;
            gSetting_guess->eyeColor1_0247_guess = state_1c5_guess;
            gSetting_guess->value_248_guess = state_1c6_guess;
            if (gSendFlag_guess == 0) {
                if (gEverQuest_guess->state_b54_guess == 2) {
                    gCharSetters_guess->Set24a_guess(gSetting_guess->value_24a_guess);
                    gCharSetters_guess->Set246_guess(gSetting_guess->beardColor_0246_guess);
                    gCharDataLookup_guess->profile_008_guess.setters_guess.SetFace_guess(gSetting_guess->faceHair_024d_guess);
                    gCharSetters_guess->Set249_guess(gSetting_guess->value_249_guess);
                    gCharSetters_guess->Set245_guess(gSetting_guess->hairColor_0245_guess);
                    gCharSetters_guess->Set247_guess(gSetting_guess->eyeColor1_0247_guess);
                    gCharSetters_guess->Set248_guess(gSetting_guess->value_248_guess);
                    if (pinstCCharacterCreation_guess != 0) {
                        pinstCCharacterCreation_guess->Transfer_guess(gCharSetters_guess);
                    }
                } else {
                    SettingBytes_guess packet_guess;
                    packet_guess.value_24a_guess = gSetting_guess->value_24a_guess;
                    packet_guess.value_246_guess = gSetting_guess->beardColor_0246_guess;
                    packet_guess.value_24d_guess = gSetting_guess->faceHair_024d_guess;
                    packet_guess.value_249_guess = gSetting_guess->value_249_guess;
                    packet_guess.value_245_guess = gSetting_guess->hairColor_0245_guess;
                    packet_guess.value_247_guess = gSetting_guess->eyeColor1_0247_guess;
                    packet_guess.value_248_guess = gSetting_guess->value_248_guess;
                    EQSendMessage(EQ_ARRAY(char, 0x00905CA0), OP_FaceChange, &packet_guess, 7, 1);
                }
            } else {
                gCharSetters_guess->Set24a_guess(gSetting_guess->value_24a_guess);
                gCharSetters_guess->Set246_guess(gSetting_guess->beardColor_0246_guess);
                gCharDataLookup_guess->profile_008_guess.setters_guess.SetFace_guess(gSetting_guess->faceHair_024d_guess);
                gCharSetters_guess->Set249_guess(gSetting_guess->value_249_guess);
                gCharSetters_guess->Set245_guess(gSetting_guess->hairColor_0245_guess);
                gCharSetters_guess->Set247_guess(gSetting_guess->eyeColor1_0247_guess);
                gCharSetters_guess->Set248_guess(gSetting_guess->value_248_guess);
            }
            pEverQuest->dsp_chat(pStringTable->getString(0x2efc, 0));
            Slot34_guess();
            return 0;
        }
        if ((VisualTarget_guess*)sender == state_164_guess) {
            if (pCharData != 0) {
                gSetting_guess->Mark_guess(((CharInfoBytes_guess*)gCharDataLookup_guess->profile_008_guess.character_guess.GetCharInfo2())->value_11d0_guess, 1);
                gSetting_guess->faceHair_024d_guess = ((CharInfoBytes_guess*)gCharDataLookup_guess->profile_008_guess.character_guess.GetCharInfo2())->value_11d0_guess;
                gSetting_guess->value_249_guess = gCharSetters_guess->Get249_guess();
                gSetting_guess->hairColor_0245_guess = gCharSetters_guess->Get245_guess();
                gSetting_guess->value_24a_guess = gCharSetters_guess->Get24a_guess();
                gSetting_guess->beardColor_0246_guess = gCharSetters_guess->Get246_guess();
                gSetting_guess->eyeColor1_0247_guess = gCharSetters_guess->Get247_guess();
                gSetting_guess->value_248_guess = gCharSetters_guess->Get248_guess();
                gSetting_guess->Refresh_guess();
                SetFaceSelectionsFromPlayer_guess();
            }
            Slot34_guess();
            return 0;
        }
        for (int index_guess = 0; index_guess < 7; ++index_guess) {
            int flag_guess;
            if (sender == (int)secondary_guess[index_guess]) {
                flag_guess = 1;
            } else if (sender == (int)primary_guess[index_guess]) {
                flag_guess = 0;
            } else {
                continue;
            }
            switch (index_guess) {
            case 0:
                state_1c0_guess = 1;
                StepSetting_guess(flag_guess, 0);
                break;
            case 1:
                state_1c0_guess = 2;
                StepSetting_guess(flag_guess, 0);
                break;
            case 2:
                state_1c0_guess = 2;
                StepSetting_guess(flag_guess, 1);
                break;
            case 3:
                state_1c0_guess = 3;
                StepSetting_guess(flag_guess, 0);
                break;
            case 4:
                state_1c0_guess = 4;
                StepSetting_guess(flag_guess, 0);
                break;
            case 5:
                state_1c0_guess = 4;
                StepSetting_guess(flag_guess, 1);
                break;
            case 6:
                state_1c0_guess = 1;
                StepSetting_guess(flag_guess, 1);
                break;
            }
            return 0;
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification((CXWnd*)sender, message, data);
}

