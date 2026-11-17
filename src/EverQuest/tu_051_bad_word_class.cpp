// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 51: a hint from compare/tumap.py.
// Chat text filters: the profanity word lists and their check, and the two language garblers that
// chat display runs (tu_042): SpeakBabel_guess (broken grammar, profanity scramble) then GarbleText_guess.
// g_profanityFilter_guess/g_recordCount_guess are the words and count of the one ProfanityFilter_guess at
// 0x900830; g_displayState_guess is pinstLocalPlayer and g_characterData_guess is pCharData.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <ctype.h>

#define g_recordCount_guess EQ_GLOBAL(int, 0x00900BB4)
#define g_profanityFilter_guess EQ_ARRAY(char, 0x00900830)
#define g_logServerGibberish_guess EQ_GLOBAL(int, 0x00923D70)

// EXTERNAL: TITANIUM 0x005768A0 Compare_guess
int __cdecl Compare_guess(const char* value, const char* record);

struct DisplayObject_guess {
    unsigned int pad_000[0x158 / 4];
    unsigned int field_158;
};

struct DisplayState_guess {
    unsigned int pad_000[0x1a8 / 4];
    DisplayObject_guess* object_1a8;
};

#define g_displayState_guess EQ_GLOBAL(DisplayState_guess*, 0x00905CE4)
#define g_characterData_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)
#define g_actorHeightSentinel_guess EQ_GLOBAL(float, 0x00640EA0)
#define g_flag_923798_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_flag_923884_guess EQ_GLOBAL(unsigned int, 0x00923884)
#define g_state_923D94_guess EQ_GLOBAL(unsigned int, 0x00923D94)

struct EQ_CharacterSettings_guess {
    // EXTERNAL: TITANIUM 0x0040E25C EQ_CharacterSettings_guess::SetLanguage_guess
    void SetLanguage_guess(const char* text_guess);
};

struct EQ_PCCharacterData_guess {
    unsigned int pad_000[0xBC / 4];
    EQ_CharacterSettings_guess settings_guess;
};

struct EQ_PCHead_guess {
    unsigned int field_000;
    unsigned int field_004;
};

struct EQ_PCCharacterView_guess : EQ_PCHead_guess, virtual EQ_PCCharacterData_guess {
};

struct EQPlayer_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x0048A00B EQPlayer_guess::CopyPosition_guess
    float* CopyPosition_guess(float* destination_guess, const float* source_guess);
    // EXTERNAL: TITANIUM 0x0048C14F EQPlayer_guess::UpdatePosition_guess
    void UpdatePosition_guess(int update_guess);
    // EXTERNAL: TITANIUM 0x0048A0FC EQPlayer_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float y_guess, float x_guess, float z_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x0048A945 EQPlayer_guess::RefreshHeight_guess
    void RefreshHeight_guess();
    char WarpToPosition_guess(const float* position_guess, float heading_guess);
};

struct DataManager_guess {
    // EXTERNAL: TITANIUM 0x004B60C2 DataManager_guess::Refresh_guess
    void Refresh_guess();
};

// EXTERNAL: TITANIUM 0x004B6088 GetDataManager_guess
DataManager_guess* __cdecl GetDataManager_guess();

struct ActorInfo_guess {
    unsigned int pad_000[0x48 / 4];
    float height_048;
};

struct EverQuestEvents_guess : CEverQuest {
    // EXTERNAL: TITANIUM 0x004A1350 EverQuestEvents_guess::SavePC_guess
    void SavePC_guess(int first_guess, int second_guess, int third_guess);
};

#include "titanium/crt.h"

// Puts this player at `position_guess` facing `heading_guess` with all motion zeroed, refreshes the floor
// height under it and, unless 0x923798 or 0x923884 is set, raises game event (0, 1, 7) in state 4.
// FUNCTION: TITANIUM 0x00478474
// @early-stop: unknown, structural ndiff=18
char EQPlayer_guess::WarpToPosition_guess(const float* position_guess, float heading_guess) {
    float copiedPosition_guess[3];
    g_displayState_guess->object_1a8->field_158 = 0;
    ((EQ_PCCharacterView_guess*)g_characterData_guess)->settings_guess.SetLanguage_guess(g_emptyString_guess);
    float* positionCopy_guess = CopyPosition_guess(copiedPosition_guess, position_guess);
    Y = positionCopy_guess[0];
    X = positionCopy_guess[1];
    Z = positionCopy_guess[2];
    field_50 = 0.0f;
    Heading = heading_guess;
    SpeedY = 0.0f;
    SpeedX = 0.0f;
    SpeedZ = 0.0f;
    field_58 = 0.0f;
    field_54 = 0.0f;
    SpeedRun = 0.0f;
    DataManager_guess* dataManager_guess = GetDataManager_guess();
    dataManager_guess->Refresh_guess();
    UpdatePosition_guess(1);
    if (pActorInfo != 0) {
        float height_guess = GetFloorHeightAt_guess(Y, X, Z, 1);
        if (height_guess != g_actorHeightSentinel_guess) {
            ((ActorInfo_guess*)pActorInfo)->height_048 = height_guess;
        }
        RefreshHeight_guess();
        if (g_flag_923798_guess == 0 && g_flag_923884_guess == 0) {
            g_state_923D94_guess = 4;
            ((EverQuestEvents_guess*)pEverQuest)->SavePC_guess(0, 1, 7);
        }
    }
    return 1;
}

struct ProfanityFilter_guess {
    char words_guess[25][0x20];  // 0x000
    char text_guess[100];        // 0x320
    int count_guess;             // 0x384
    int state_guess;             // 0x388
    ProfanityFilter_guess* LoadWordList_guess(const char* language_guess);
};

// Loads the word list (misnamed: the argument picks a list, not a language). 'n' gets 25 fragments
// ("ussy", "enis"...) that match inside longer words, probably for names; 'w' gets 20 whole chat words;
// anything else empties the list.
// FUNCTION: TITANIUM 0x00478593
ProfanityFilter_guess* ProfanityFilter_guess::LoadWordList_guess(const char* listKind_guess) {
    state_guess = 0;
    memset(text_guess, 0, 100);
    if (*listKind_guess == 'n') {
        strcpy(words_guess[0], EQ_ARRAY(char, 0x00647BB8));
        strcpy(words_guess[1], "shit");
        strcpy(words_guess[2], "ussy");
        strcpy(words_guess[3], EQ_ARRAY(char, 0x00647BA4));
        strcpy(words_guess[4], "phuk");
        strcpy(words_guess[5], EQ_ARRAY(char, 0x00647B98));
        strcpy(words_guess[6], EQ_ARRAY(char, 0x00647B94));
        strcpy(words_guess[7], "nigger");
        strcpy(words_guess[8], "niger");
        strcpy(words_guess[9], EQ_ARRAY(char, 0x00647B80));
        strcpy(words_guess[10], "hole");
        strcpy(words_guess[11], "tits");
        strcpy(words_guess[12], "piss");
        strcpy(words_guess[13], EQ_ARRAY(char, 0x00647B64));
        strcpy(words_guess[14], EQ_ARRAY(char, 0x00647B60));
        strcpy(words_guess[15], "enis");
        strcpy(words_guess[16], "phag");
        strcpy(words_guess[17], EQ_ARRAY(char, 0x00647B4C));
        strcpy(words_guess[18], "phuc");
        strcpy(words_guess[19], EQ_ARRAY(char, 0x00647B40));
        strcpy(words_guess[20], "nigga");
        strcpy(words_guess[21], "damien");
        strcpy(words_guess[22], EQ_ARRAY(char, 0x00647B2C));
        strcpy(words_guess[23], "labia");
        strcpy(words_guess[24], "satan");
        count_guess = 0x19;
    } else if (*listKind_guess == 'w') {
        strcpy(words_guess[0], "fuck");
        strcpy(words_guess[1], "shit");
        strcpy(words_guess[2], "piss");
        strcpy(words_guess[3], "cock");
        strcpy(words_guess[4], "penis");
        strcpy(words_guess[5], "pussy");
        strcpy(words_guess[6], EQ_ARRAY(char, 0x00647BA4));
        strcpy(words_guess[7], "cunt");
        strcpy(words_guess[8], "kunt");
        strcpy(words_guess[9], "nigger");
        strcpy(words_guess[10], "niger");
        strcpy(words_guess[11], "asshole");
        strcpy(words_guess[12], "tits");
        strcpy(words_guess[13], "nigga");
        strcpy(words_guess[14], "jesus!");
        strcpy(words_guess[15], "christ!");
        strcpy(words_guess[16], "damn");
        strcpy(words_guess[17], "dong");
        strcpy(words_guess[18], "bitch");
        strcpy(words_guess[19], "dickhead");
        count_guess = 0x14;
    } else {
        count_guess = 0;
    }
    return this;
}

// True when `value` matches an entry of the loaded word list (Compare_guess per 32-byte entry); the
// chat filter (tu_046) stars out the word. `length_guess` is ignored, so the match sees the rest of the line.
// FUNCTION: TITANIUM 0x004788E1
char __cdecl ContainsProfanity_guess(const char* value, int length_guess) {
    int count = g_recordCount_guess;
    int index = 0;
    char* record;
    if (count > 0) {
        record = g_profanityFilter_guess;
        do {
            if (Compare_guess(value, record) != 0) {
                return 1;
            }
            ++index;
            record += 0x20;
        } while (index < count);
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
char __cdecl RandomRange_guess(int minimum, int maximum);

// One of "aeiouy" at random.
// FUNCTION: TITANIUM 0x00478917
char __cdecl RandomVowel_guess() {
    char index = RandomRange_guess(0, 5);
    char vowels[7] = "aeiouy";
    return vowels[index];
}

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* output_guess, const char* input_guess);

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess();

// EXTERNAL: TITANIUM 0x00576E40 IsVowel_guess
char __cdecl IsVowel_guess(unsigned char letter_guess);

// Listener side of a foreign language: copies `input_guess` with letters scrambled by how far rolls beat
// `threshold_guess` (the reader's skill in that language); 1 when anything changed. Skill 100+ or the
// OP_LogServer flag at 0x923D70 off (EQEmu calls it Gibberish, probably) copies the text unchanged.
// Text between 0x12 bytes (item links) is never touched. Random consonants are a-y and random letters
// '`'-'y' (0x60 + 0..25): 'z' never comes out and '`' can; the off-by-one is the original's.
// FUNCTION: TITANIUM 0x00478F73
// @early-stop: budget, structural ndiff=77
char __cdecl GarbleText_guess(const char* input_guess, char* output_guess, unsigned char threshold_guess) {
    int outputIndex_guess = 0;
    if (output_guess == 0 || input_guess == 0) {
        return 0;
    }

    int length_guess = (int)strlen(input_guess);
    char changed_guess = 0;
    if (threshold_guess > 99 || g_logServerGibberish_guess == 0) {
        CopyText_guess(output_guess, input_guess);
        return 0;
    }

    char inMarker_guess = 0;
    for (int inputIndex_guess = 0; inputIndex_guess < length_guess; inputIndex_guess++) {
        const char* current_guess = input_guess + inputIndex_guess;
        if (*current_guess == 0x12) {
            inMarker_guess = !inMarker_guess;
        }

        if (isalpha((unsigned char)*current_guess) == 0 || inMarker_guess != 0 ||
            number_percent_guess() <= 50) {
            output_guess[outputIndex_guess] = *current_guess;
        } else {
            unsigned char chance_guess = (unsigned char)number_percent_guess();
            if (chance_guess <= 5 || chance_guess <= threshold_guess + 10) {
                output_guess[outputIndex_guess] = *current_guess;
            } else {
                changed_guess = 1;
                // A roll above 98 turns the letter into a space (0x00479025 tests the roll).
                if (chance_guess > 98 && outputIndex_guess > 0 &&
                    output_guess[outputIndex_guess - 1] != ' ' &&
                    input_guess[inputIndex_guess + 1] != ' ' &&
                    inputIndex_guess != length_guess - 1) {
                    output_guess[outputIndex_guess] = ' ';
                } else if (chance_guess - threshold_guess > 30) {
                    output_guess[outputIndex_guess] = (char)(RandomRange_guess(0, 25) + 0x60);
                } else if (IsVowel_guess((unsigned char)*current_guess) != 0) {
                    output_guess[outputIndex_guess] = RandomVowel_guess();
                } else {
                    do {
                        output_guess[outputIndex_guess] = (char)(RandomRange_guess(0, 24) + 'a');
                    } while (IsVowel_guess((unsigned char)output_guess[outputIndex_guess]) != 0);
                }
            }
        }
        outputIndex_guess++;
    }
    output_guess[outputIndex_guess] = 0;
    return changed_guess;
}

// EXTERNAL: TITANIUM 0x0042E2E2 GrabFirstWord2_guess
char* __cdecl GrabFirstWord2_guess(char* source_guess, char* token_guess, int size_guess);

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination_guess, const char* source_guess, int max_guess);

// Speaker side of a foreign language: below `skill_guess` short words turn into pidgin (I/my become "me",
// let's/we'll "we", went "did go", best a double comparative), small words like "the" and "and" are dropped,
// and letters are scrambled as in GarbleText_guess ('`'-'y' too). Mode 1 also scrambles words on the
// profanity list; skill 100+ with mode 0 copies the text. Item links (0x12 ... 0x12) pass whole; an
// unclosed 0x12 becomes 'Q'. At the end the text's closing punctuation replaces the last letter of the
// last word, the trailing space goes and the first letter is capitalized.
// FUNCTION: TITANIUM 0x00478951
// @early-stop: budget, structural ndiff=162
void __cdecl SpeakBabel_guess(const char* text_guess, char* out_guess, int unused_guess,
                          unsigned char skill_guess, int mode_guess) {
    char buf_guess[4096];
    char tok_guess[4096];
    char word_guess[16];
    char* cur_guess;
    int len_guess = strlen(text_guess);
    int i = 0;
    if (out_guess == 0 || text_guess == 0) {
        return;
    }
    if (skill_guess > 99 && mode_guess == 0) {
        strcpy(out_guess, text_guess);
        return;
    }
    *out_guess = 0;
    if (len_guess > 0xfff) {
        len_guess = 0xfff;
    }
    for (; i < len_guess; i++) {
        buf_guess[i] = text_guess[i];
    }
    buf_guess[i] = 0;
    cur_guess = buf_guess;
    while (strlen(cur_guess) > 0) {
        // Item link: copied whole up to its closing 0x12; an unclosed one turns the 0x12 into 'Q' and is
        // read again as text.
        if (*cur_guess == 0x12) {
            int end_guess = 1;
            char c_guess = cur_guess[1];
            while (c_guess != 0 && c_guess != 0x12) {
                end_guess++;
                c_guess = cur_guess[end_guess];
            }
            if (cur_guess[end_guess] != 0x12) {
                *cur_guess = 'Q';
            } else {
                strncat(out_guess, cur_guess, end_guess + 1);
                strcat(out_guess, EQ_ARRAY(char, 0x0063FE10));
                cur_guess += end_guess + 1;
            }
            continue;
        }
        cur_guess = GrabFirstWord2_guess(cur_guess, tok_guess, 0x1000);
        if (strlen(tok_guess) == 0) {
            steve_strncpy_guess(word_guess, cur_guess, 0x10);
            cur_guess += strlen(word_guess);
        } else {
            steve_strncpy_guess(word_guess, tok_guess, 0x10);
        }
        // Mode 1: a word on the profanity list (0x004788E1) becomes random characters '`'-'y'.
        if (mode_guess == 1) {
            int wlen_guess = strlen(word_guess);
            if (wlen_guess > 0 && ContainsProfanity_guess(word_guess, wlen_guess)) {
                for (int k = 0; k < wlen_guess; k++) {
                    word_guess[k] = RandomRange_guess(0, 0x19) + 0x60;
                }
                if (strlen(out_guess) > 0) {
                    strcat(out_guess, word_guess);
                } else {
                    strcpy(out_guess, word_guess);
                }
                if (out_guess[strlen(out_guess) - 1] != ' ') {
                    strcat(out_guess, EQ_ARRAY(char, 0x0063FE10));
                }
                continue;
            }
        }
        // Words are cut to 15 characters. A word under 8 whose percent roll beats the skill becomes pidgin
        // or is dropped; then each letter may be scrambled, more often the lower the skill.
        unsigned char roll_guess = number_percent_guess();
        if (roll_guess > skill_guess && (int)strlen(word_guess) < 8) {
            if (_stricmp(word_guess, EQ_ARRAY(char, 0x0064796C)) == 0 ||
                _stricmp(word_guess, EQ_ARRAY(char, 0x00647C54)) == 0 ||
                _stricmp(word_guess, EQ_ARRAY(char, 0x00647C50)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x00647C4C));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647C44)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647C3C)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x00647928));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647C34)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x00647C2C));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647C24)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647C20)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x00647C1C));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647C14)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x00647C0C));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x0063FE30)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x006479BC)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647A84)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647C08)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x006479B0)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647C04)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647C00)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647BFC)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647BF8)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647BF4)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647BF0)) == 0 ||
                       _stricmp(word_guess, EQ_ARRAY(char, 0x00647BE8)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x0063F53F));
            } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647BE0)) == 0) {
                strcpy(word_guess, EQ_ARRAY(char, 0x0063F53F));
            } else if ((int)roll_guess - (int)skill_guess > 0x14) {
                if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647990)) == 0 ||
                    _stricmp(word_guess, EQ_ARRAY(char, 0x00647814)) == 0) {
                    strcpy(word_guess, EQ_ARRAY(char, 0x0063F53F));
                } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647BDC)) == 0) {
                    strcpy(word_guess, EQ_ARRAY(char, 0x00647BD8));
                } else if (_stricmp(word_guess, EQ_ARRAY(char, 0x00647BD0)) == 0) {
                    strcpy(word_guess, EQ_ARRAY(char, 0x00647BC4));
                }
            }
        }
        int n_guess = strlen(word_guess);
        if (n_guess > 0) {
            for (int j = 0; j < n_guess; j++) {
                unsigned char* p_guess = (unsigned char*)&word_guess[j];
                if (isalpha(*p_guess) && number_percent_guess() > 0x28) {
                    unsigned char r_guess = number_percent_guess();
                    if (r_guess > 5 && r_guess > skill_guess + 10) {
                        if (r_guess > 0x62 && j > 0 && word_guess[j - 1] != ' ' &&
                            word_guess[j + 1] != ' ') {
                            *p_guess = ' ';
                        } else if (r_guess - skill_guess > 0x1e) {
                            *p_guess = RandomRange_guess(0, 0x19) + 0x60;
                        } else if (IsVowel_guess(*p_guess)) {
                            *p_guess = RandomVowel_guess();
                        } else {
                            do {
                                *p_guess = RandomRange_guess(0, 0x18) + 0x61;
                            } while (IsVowel_guess(*p_guess));
                        }
                    }
                }
            }
            if (strlen(word_guess) > 0) {
                if (strlen(out_guess) > 0) {
                    strcat(out_guess, word_guess);
                } else {
                    strcpy(out_guess, word_guess);
                }
                if (out_guess[strlen(out_guess) - 1] != ' ') {
                    strcat(out_guess, EQ_ARRAY(char, 0x0063FE10));
                }
            }
        }
    }
    int last_guess = strlen(text_guess) - 1;
    if (last_guess > 0 && strlen(out_guess) > 0) {
        const char* p_last = text_guess + last_guess;
        if (!isalpha((unsigned char)*p_last) && !isdigit((unsigned char)*p_last)) {
            out_guess[strlen(out_guess) - 2] = *p_last;
        }
        out_guess[strlen(out_guess) - 1] = 0;
        char first_guess = *out_guess;
        *out_guess = (first_guess >= 'a' && first_guess <= 'z') ? first_guess - 0x20 : first_guess;
    }
}

