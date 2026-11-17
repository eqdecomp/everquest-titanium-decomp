// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 234: a hint from compare/tumap.py.
// Two windows. The GM trainer window (CTrainWndView_guess and its views): skills (ids 0-99) and languages
// (100-131) the trainer offers, sorted by name or value, trained with OP_GMTrainSkill and closed with
// OP_GMEndTraining. Then the tribute benefit window, CTributeBenefitWnd ("TributeBenefitWnd"): personal and
// guild benefit lists, OP_TributeToggle and OP_GuildTributeToggleReq.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CTributeMasterWnd.h"

struct DestructorBarrier_guess {
    ~DestructorBarrier_guess() {}
};

// EXTERNAL: TITANIUM 0x0065F470 ??_7Object_guess@@6B@
struct Object_guess {
    virtual void OnShow_guess();
    virtual ~Object_guess();
    // EXTERNAL: TITANIUM 0x005A3100 Object_guess::Cleanup_guess
    void Cleanup_guess();
    // EXTERNAL: TITANIUM 0x005A1880 Object_guess::OnShow
    void OnShow();
    Object_guess* Delete_guess(unsigned char flags);
    char pad_4[0x58];
    char flag_5c_guess;
    DestructorBarrier_guess destructorBarrier_guess;
};


struct TargetState_guess {
    char pad_0[0x5d];
    char enabled_005d_guess;
};

// EXTERNAL: TITANIUM 0x0065F5B0 ??_7CTributeBenefitWndView_guess@@6B@
struct CTributeBenefitWndView_guess {
    char pad_4[0x168];
    void* allocations_guess[5];
    char pad_180[0x09];
    char flag_189_guess;
    char pad_18a[0x0a];
    TargetState_guess* state_guess;
    char pad_198[0x25];
    char flag_1bd_guess;

    virtual ~CTributeBenefitWndView_guess();
    void* Delete_guess(unsigned char flags);
    void SetFirst_guess();
    void SetSecond_guess();
    void UpdateValue_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct LookupResult_guess {
    char pad_0[0x264];
    char value_guess;
};

struct LookupGlobal_guess {
    char pad_0[0x120];
    char input_guess[0x168];
    int state_guess;
};

struct LookupManager_guess {
    // EXTERNAL: TITANIUM 0x0040AA28 LookupManager_guess::Find_guess
    LookupResult_guess* Find_guess(char* input);
    // EXTERNAL: TITANIUM 0x0040AB34 LookupManager_guess::SendPacket_guess
    void SendPacket_guess(const char* text_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x0040B27A LookupManager_guess::Count_guess
    int Count_guess();
};

#define g_lookupGlobal_guess EQ_GLOBAL(LookupGlobal_guess*, 0x00905CE4)
#define g_lookupManager_guess EQ_GLOBAL(LookupManager_guess, 0x00905D38)

struct IndexedValue_guess {
    int value_guess;
    char pad_4[5];
    char flag_9_guess;
    // EXTERNAL: TITANIUM 0x0044A335 IndexedValue_guess::Has_guess
    bool Has_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x0044A2E4 IndexedValue_guess::GetFirst_guess
    int GetFirst_guess(int index);
};

struct ChatSink_guess {
    // EXTERNAL: TITANIUM 0x004FD36C ChatSink_guess::Test_guess
    bool Test_guess(int channel);
    // EXTERNAL: TITANIUM 0x004FD91E ChatSink_guess::Send_guess
    void Send_guess(int zero, int channel, int id, int value, int extra);
};

#define pinstCCursorAttachment_guess EQ_GLOBAL(ChatSink_guess*, 0x00850C24)

struct IndexedDispatch_guess {
    // EXTERNAL: TITANIUM 0x00492595 IndexedDispatch_guess::Dispatch_guess
    int Dispatch_guess(int value);
    // EXTERNAL: TITANIUM 0x00492595 IndexedDispatch_guess::Name_guess
    char* Name_guess(int value);
    // EXTERNAL: TITANIUM 0x00492EC2 IndexedDispatch_guess::GetDisplay_guess
    char* GetDisplay_guess(int* text_guess);
    // EXTERNAL: TITANIUM 0x00492EC2 IndexedDispatch_guess::CleanText_guess
    char* CleanText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x004982C6 IndexedDispatch_guess::dsp_chat
    void dsp_chat(const char* text_guess, int event_guess, bool flag_guess);
    // EXTERNAL: TITANIUM 0x00491845 IndexedDispatch_guess::CloseTrainWindow_guess
    void CloseTrainWindow_guess();
};

#define g_indexedValues_guess EQ_ARRAY(IndexedValue_guess*, 0x00851200)
#define g_indexedDispatch_guess EQ_GLOBAL(IndexedDispatch_guess*, 0x00988DF0)

struct WorldEntry_guess;

struct UpdateClock_guess {
    char pad_0[0x148];
    unsigned int tick_guess;
    // EXTERNAL: TITANIUM 0x00439D16 UpdateClock_guess::PlayerDistance_guess
    float PlayerDistance_guess(WorldEntry_guess* first_guess,
        WorldEntry_guess* second_guess, float scale_guess);
};

struct DisplayOwner_guess {
    char pad_0[0x120];
    int text_guess;
};

struct CallbackVtable_guess {
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
};

#define g_displayOwner_guess EQ_GLOBAL(DisplayOwner_guess*, 0x00905D1C)

// EXTERNAL: TITANIUM 0x0046DA4A FormatDisplay_guess
void __cdecl FormatDisplay_guess(char* output_guess, int format_guess,
    char* first_guess, char* second_guess, int zero1_guess, int zero2_guess,
    int zero3_guess, int zero4_guess, int zero5_guess, int zero6_guess,
    int zero7_guess);

struct UpdateOwner_guess {
    char pad_0[0x15c];
    unsigned int updateTick_guess;
    void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 UpdateOwner_guess::Ready_guess
    bool Ready_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 UpdateOwner_guess::OnProcessFrame
    void OnProcessFrame();
};

#define g_updateClock_guess EQ_GLOBAL(UpdateClock_guess*, 0x00905D24)

struct LookupTableBranch_guess {
    char pad_0[4];
    int offset_guess;
};

struct LookupTableMethod_guess {
    // EXTERNAL: TITANIUM 0x0040E722 LookupTableMethod_guess::Get_guess
    unsigned int Get_guess(int index);
};

struct LookupTableRoot_guess {
    char pad_0[8];
    union {
        LookupTableBranch_guess* branch_guess;
        LookupTableMethod_guess method_guess[1];
        unsigned char bytes_guess[1];
    } data_guess;
};

#define g_lookupTableRoot_guess EQ_GLOBAL(LookupTableRoot_guess*, 0x00905D00)

struct CharacterLanguageInfo_guess {
    char pad_0000[0x119c];
    unsigned char language_guess;
    char pad_119d[7];
    int maximum_guess;
};

struct CharacterLanguageCalculator_guess {
    // EXTERNAL: TITANIUM 0x004BDAD1 CharacterLanguageCalculator_guess::CostToTrain_guess
    int CostToTrain_guess(bool above_guess, float scale_guess, int value_guess);
};

#define g_languageCount_guess EQ_GLOBAL(int, 0x00796220)
#define g_languageLimits_guess EQ_ARRAY(int, 0x007961C8)
#define g_languageStrings_guess EQ_ARRAY(int, 0x007961F4)
#define g_emptyString_guess EQ_ARRAY(const char, 0x006410A8)
#define g_digitString_guess EQ_ARRAY(const char, 0x0064DA6C)
#define g_separator_guess EQ_ARRAY(const char, 0x0063F53C)
#define g_columnSeparator_guess EQ_ARRAY(const char, 0x0063F53F)
#define g_removeNumberBuffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x0046DA4A FormatDisplay_guess
void __cdecl FormatDisplay_guess(char* output_guess, int format_guess,
    char* first_guess, char* second_guess, int zero1_guess, int zero2_guess,
    int zero3_guess, int zero4_guess, int zero5_guess, int zero6_guess,
    int zero7_guess);

extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x005738B0 FormatNumber_guess
void __cdecl FormatNumber_guess(CXStr* output_guess, const char* format_guess, ...);

extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);
extern "C" int __cdecl strcmp(const char* left, const char* right);
// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* dst, const char* src);
// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* dst, int value, unsigned int size);

struct ManagerEntry_guess {
    int id_guess;
    int value_guess;
    int pad_8_guess;
};

struct SortEntry_guess {
    char name_guess[0x40];
    int key40_guess;
    int key44_guess;
    int key48_guess;
    int key4c_guess;
    int key50_guess;
};

struct CTrainWndView_guess {
    char pad_0[0x15c];
    int field_15c_guess;
    char pad_160[4];
    CXWnd* state_164_guess;
    CXWnd* field_168_guess;
    char pad_16c[0x0c];
    CXWnd* text_178_guess;
    CXWnd* text_17c_guess;
    CXWnd* text_180_guess;
    CXWnd* text_184_guess;
    CXWnd* text_188_guess;
    CListWnd* list_guess;
    ManagerEntry_guess entries_guess[1];
    char pad_19c[0x624];
    int count_guess;
    union {
        int field_7c4_guess;
        float scale_7c4_guess;
    };
    int nameSortOrder_07c8_guess;
    int valueSortOrder_07cc_guess;
    char flag_7d0_guess;
    // EXTERNAL: TITANIUM 0x0056A9D3 CTrainWndView_guess::Lookup_guess
    int Lookup_guess(int id);
    void Swap_guess(int first, int second);
    void SortNames_guess(int direction);
    void SortValues_guess(int direction);
    // EXTERNAL: TITANIUM 0x0056AE31 CTrainWndView_guess::GetSkillOrLanguageValue_guess
    int GetSkillOrLanguageValue_guess(int id);
    // EXTERNAL: TITANIUM 0x0056B391 CTrainWndView_guess::AddRow_guess
    void AddRow_guess(int id);
    void Flush_guess();
    void UpdateAll_guess(char flag);
    void SetGMData_guess(int* ids, unsigned char* flags, int value);
    bool Init_guess();
    bool AboutToHide_guess();
    // EXTERNAL: TITANIUM 0x0059DD30 CTrainWndView_guess::Ready_guess
    bool Ready_guess();
    // EXTERNAL: TITANIUM 0x0056AF2C CTrainWndView_guess::FillRow_guess
    void FillRow_guess(int index);
    void Post_guess(int id, int flag);
    void Train_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
        void* data_guess);
};

struct NotifyTarget_guess {
    // EXTERNAL: TITANIUM 0x0044A617 NotifyTarget_guess::Notify_guess
    void Notify_guess(int value, char flag);
};

struct WorldEntry_guess {
    char pad_0[0x120];
    char text_120_guess[0x138];
    int id_guess;
};

struct Connection_guess;

#define g_notifyTarget_guess EQ_GLOBAL(NotifyTarget_guess*, 0x00851390)
#define g_activeWorldEntry_guess EQ_GLOBAL(WorldEntry_guess*, 0x00905D1C)
#define g_currentWorldEntry_guess EQ_GLOBAL(WorldEntry_guess*, 0x00905CE4)
#define g_worldConnection_guess EQ_GLOBAL(Connection_guess*, 0x00905CA0)
#define g_worldCounter_guess EQ_GLOBAL(int, 0x009248D4)
#define g_pendingWorldEntry_guess EQ_GLOBAL(WorldEntry_guess*, 0x00905D04)

// Every 500 ms closes the trainer window (CloseTrainWindow_guess) once the player is more than 20 units from
// the trainer.
// FUNCTION: TITANIUM 0x0056A968
void UpdateOwner_guess::OnProcessFrame_guess() {
    if (Ready_guess()) {
        unsigned int* updateTick = &updateTick_guess;
        unsigned int tick = g_updateClock_guess->tick_guess;
        if (tick >= *updateTick) {
            *updateTick = tick + 500;
            if (g_activeWorldEntry_guess != 0 &&
                g_updateClock_guess->PlayerDistance_guess(g_activeWorldEntry_guess,
                    g_currentWorldEntry_guess, 1.0f) > 20.0f) {
                g_indexedDispatch_guess->CloseTrainWindow_guess();
            }
        }
    }
    OnProcessFrame();
}

// Destructor of the GM trainer window (vtable 0x65F470, ctor 0x0056A4FF): restores its vtable and runs
// the CSidlScreenWnd destructor (0x005A3100); nothing of its own to free.
// FUNCTION: TITANIUM 0x0056A8BA
Object_guess::~Object_guess() {
    Cleanup_guess();
}

// On close: turns off music selection 7 and, with a trainer, sends OP_GMEndTraining (trainer spawn id, player
// spawn id) and forgets it.
// FUNCTION: TITANIUM 0x0056A8C5
bool CTrainWndView_guess::AboutToHide_guess() {
    count_guess = 0;
    g_notifyTarget_guess->Notify_guess(7, 0);
    if (g_activeWorldEntry_guess != 0) {
        g_notifyTarget_guess->Notify_guess(7, 0);
        int values[2];
        values[0] = g_activeWorldEntry_guess->id_guess;
        values[1] = g_currentWorldEntry_guess->id_guess;
        EQSendMessage(&g_worldConnection_guess, OP_GMEndTraining, values, 8, 1);
        g_worldCounter_guess = 0;
        g_activeWorldEntry_guess = 0;
        g_pendingWorldEntry_guess = 0;
    }
    return true;
}

// The train window's OnShow (vtable slot 35 of TrainWnd, ctor 0x0056A4FF): when shown (+0x5C), context tip
// 0x13 in the tip window (0x9928E0); then the base OnShow.
// FUNCTION: TITANIUM 0x0056A944
void Object_guess::OnShow_guess() {
    if (flag_5c_guess != 0) {
        CTipWnd_guess* manager = pinstCTipWndCONTEXT_guess;
        if (manager != 0) {
            manager->selectTip_guess(0x13, 0);
        }
    }
    OnShow();
}

// Name of skill `index` (0-99) or language index - 100 (GetLangDesc_guess).
// FUNCTION: TITANIUM 0x0056A9D3
int __stdcall GetSkillOrLanguageName_guess(int index) {
    if (index < 100) {
        return (int)pStringTable->getString(g_indexedValues_guess[index]->value_guess, 0);
    }
    return g_indexedDispatch_guess->Dispatch_guess(index - 100);
}

// Trainer window: swaps entries `first` and `second` (12 bytes each) of the offer list. Both selection
// sorts (by name, 0x0056AA54; by value, 0x0056AE70) use it.
// FUNCTION: TITANIUM 0x0056AA06
void CTrainWndView_guess::Swap_guess(int first, int second) {
    ManagerEntry_guess temp;
    memcpy(&temp, &entries_guess[first], 12);
    memcpy(&entries_guess[first], &entries_guess[second], 12);
    memcpy(&entries_guess[second], &temp, 12);
}

// Selection sort by name; `direction` is the strcmp result that wins (1 or -1).
// FUNCTION: TITANIUM 0x0056AA54
void CTrainWndView_guess::SortNames_guess(int direction) {
    for (int i = 0; i < count_guess; ++i) {
        char* best = (char*)Lookup_guess(entries_guess[i].id_guess);
        int bestIndex = i;
        for (int j = i + 1; j < count_guess; ++j) {
            if (strcmp((char*)Lookup_guess(entries_guess[j].id_guess), best) == direction) {
                best = (char*)Lookup_guess(entries_guess[j].id_guess);
                bestIndex = j;
            }
        }
        if (i != bestIndex) {
            Swap_guess(i, bestIndex);
        }
    }
}

// Fills row `index_guess`: name, the player's current value with its rank text, and the price (or "LEVEL:
// %1", string 2161, when the class can't train it yet).
// FUNCTION: TITANIUM 0x0056AF2C
// @early-stop: budget, structural ndiff=188
void CTrainWndView_guess::FillRow_guess(int index_guess) {
    CXStr text_guess;
    char format_guess[0x400];
    if (list_guess == 0) {
        return;
    }

    int id_guess;
    int level_guess;
    id_guess = entries_guess[index_guess].id_guess;
    text_guess = (const char*)GetSkillOrLanguageName_guess(id_guess);
    level_guess = GetSkillOrLanguageValue_guess(id_guess);
    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
        list_guess)(index_guess, 0, text_guess);

    int languageIndex_guess = 0;
    int languageCount_guess = g_languageCount_guess;
    for (int i_guess = 0; i_guess < languageCount_guess; ++i_guess) {
        if (level_guess <= g_languageLimits_guess[i_guess]) {
            languageIndex_guess = i_guess;
            if (i_guess == 9 && id_guess > 99 && level_guess == 100) {
                languageIndex_guess = 10;
            }
            break;
        }
    }

    if (level_guess == 0 && id_guess < 100) {
        unsigned char language_guess =
            ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess;
        if (g_indexedValues_guess[id_guess]->Has_guess(language_guess)) {
            unsigned char selectedLanguage_guess =
                ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess;
            int maximum_guess =
                ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->maximum_guess;
            if (g_indexedValues_guess[id_guess]->GetFirst_guess(selectedLanguage_guess) >
                maximum_guess) {
                int currentLanguage_guess =
                    ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess;
                FormatDisplay_guess(format_guess, 0x871,
                    _itoa(g_indexedValues_guess[id_guess]->GetFirst_guess(
                        currentLanguage_guess), g_removeNumberBuffer_guess, 10),
                    0, 0, 0, 0, 0, 0, 0, 0);
                FormatNumber_guess(&text_guess, format_guess);
            }
            else if (g_indexedValues_guess[id_guess]->Has_guess(
                ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess)) {
                text_guess = pStringTable->getString(
                    g_languageStrings_guess[languageIndex_guess], 0);
            }
            else {
                FormatDisplay_guess(format_guess, 0x871,
                    (char*)g_emptyString_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                FormatNumber_guess(&text_guess, format_guess);
            }
        }
        else if (g_indexedValues_guess[id_guess]->Has_guess(
            ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess)) {
            text_guess = pStringTable->getString(
                g_languageStrings_guess[languageIndex_guess], 0);
        }
        else {
            FormatDisplay_guess(format_guess, 0x871,
                (char*)g_emptyString_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            FormatNumber_guess(&text_guess, format_guess);
        }
    }
    else if (id_guess < 100 &&
        !g_indexedValues_guess[id_guess]->Has_guess(
            ((CharacterLanguageInfo_guess*)pCharData->GetCharInfo2())->language_guess)) {
        FormatDisplay_guess(format_guess, 0x871,
            (char*)g_emptyString_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        FormatNumber_guess(&text_guess, format_guess);
    }
    else {
        text_guess = pStringTable->getString(
            g_languageStrings_guess[languageIndex_guess], 0);
    }

    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
        list_guess)(index_guess, 1, text_guess);
    if (text_guess.Ptr != 0) {
        text_guess.FreeRep(text_guess.Ptr);
    }
    text_guess.Ptr = 0;
    if (level_guess >= 0) {
        FormatNumber_guess(&text_guess, g_separator_guess, level_guess);
    }
    EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
        list_guess)(index_guess, 2, text_guess);

    for (int column_guess = 3; column_guess < 7; ++column_guess) {
        CXStr columnText_guess(g_columnSeparator_guess);
        EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
            list_guess)(index_guess, column_guess, columnText_guess);
    }

    int value_guess = id_guess;
    if (id_guess > 99) {
        value_guess = id_guess - 100;
    }
    int result_guess = ((CharacterLanguageCalculator_guess*)pCharData)->CostToTrain_guess(
        id_guess > 99, scale_7c4_guess, value_guess);
    entries_guess[index_guess].pad_8_guess = result_guess;
    if (result_guess < 1) {
        for (int column_guess = 3; column_guess < 7; ++column_guess) {
            CXStr columnText_guess(g_digitString_guess);
            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
                list_guess)(index_guess, column_guess, columnText_guess);
        }
    }
    else {
        int column_guess = 6;
        int quotient_guess;
        do {
            quotient_guess = result_guess / 10;
            FormatNumber_guess(&text_guess, g_separator_guess, result_guess % 10);
            EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
                list_guess)(index_guess, column_guess, text_guess);
            result_guess = quotient_guess;
            if (result_guess == 0) {
                break;
            }
            --column_guess;
        } while (column_guess >= 4);
        FormatNumber_guess(&text_guess, g_separator_guess, result_guess);
        EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
            list_guess)(index_guess, 3, text_guess);
    }
}

// Scalar deleting destructor of the GM trainer window (vtable 0x65F470 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x0056AB06
Object_guess* Object_guess::Delete_guess(unsigned char flags) {
    this->Object_guess::~Object_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

// Character record fields read by Flush.
struct CHARINFO2 {
    char pad_0[0x119c];
    unsigned char class_119c_guess;
    char pad_119d[7];
    int level_11a4_guess;
    char pad_11a8[0x2c];
    int platinum_11d4_guess;
    int gold_11d8_guess;
    int silver_11dc_guess;
    int copper_11e0_guess;
    char pad_11e4[0x14];
    int practicePoints_11f8_guess;
};

struct CharacterPrefix_guess {
    int pad_0_guess;
    int pad_4_guess;
};

struct CharacterBase_guess : EQ_Character {
    unsigned char values_c_guess[0x20];
    // EXTERNAL: TITANIUM 0x004BC59B CharacterBase_guess::AddSkillValue_guess
    void AddSkillValue_guess(int id, int count);
    CHARINFO2* Info_guess() {
        return GetCharInfo2();
    }
};

struct CharacterInner_guess {
    // EXTERNAL: TITANIUM 0x0041B0DE CharacterInner_guess::HasSkill_guess
    int HasSkill_guess(int index);
};

struct CharacterObject_guess {
    // EXTERNAL: TITANIUM 0x004BEF02 CharacterObject_guess::BitchCanTrain_guess
    int BitchCanTrain_guess(int value, int flag, int index);
    // EXTERNAL: TITANIUM 0x004BDAD1 CharacterObject_guess::CostToTrain_guess
    int CostToTrain_guess(int flag, float scale, int index);
    // EXTERNAL: TITANIUM 0x004BC0D3 CharacterObject_guess::SpendMoney_guess
    int SpendMoney_guess(int value);
    char pad_0[0xc280];
    CharacterInner_guess inner_c280_guess;
};

#define g_characterObject_guess EQ_GLOBAL(CharacterObject_guess*, 0x00905D00)

struct CharacterView_guess : CharacterPrefix_guess, virtual CharacterBase_guess {
    char pad_0c_guess[0xe10 - 0x0c];
    unsigned char field_e10_guess;
    // EXTERNAL: TITANIUM 0x004BBEDA CharacterView_guess::Test_guess
    int Test_guess(int index);
};

#define g_characterView_guess EQ_GLOBAL(CharacterView_guess*, 0x00905D00)

struct TextControlVtable_guess {
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
    virtual void SetWindowTextA_guess(const CXStr& text_guess);
};

// EXTERNAL: TITANIUM 0x005738B0 FormatNumber_guess
void __cdecl FormatNumber_guess(CXStr* output_guess, const char* format_guess,
    ...);

// Shows the player's training points (+0x11F8) and the money columns, and enables Train only when the
// selected row can be trained.
// FUNCTION: TITANIUM 0x0056AB22
// @early-stop: budget, diff ndiff=21
void CTrainWndView_guess::Flush_guess() {
    CXStr text;
    if (g_characterView_guess != 0) {
        if (text_178_guess != 0) {
            FormatNumber_guess(&text, EQ_ARRAY(const char, 0x0063F53C),
                g_characterView_guess->Info_guess()->practicePoints_11f8_guess);
            ((TextControlVtable_guess*)text_178_guess)->SetWindowTextA_guess(text);
        }
        if (state_164_guess != 0) {
            state_164_guess->Enabled = 0;
        }
        if (list_guess != 0) {
            int index = list_guess->GetCurSel();
            if (index != -1 &&
                g_characterView_guess->Info_guess()->practicePoints_11f8_guess > 0) {
                int field_11d4 = g_characterView_guess->Info_guess()->platinum_11d4_guess;
                int field_11d8 = g_characterView_guess->Info_guess()->gold_11d8_guess;
                int field_11dc = g_characterView_guess->Info_guess()->silver_11dc_guess;
                int total = g_characterView_guess->Info_guess()->copper_11e0_guess +
                    10 * (field_11dc +
                    10 * (field_11d8 + 10 * field_11d4));
                if (total >= entries_guess[index].pad_8_guess) {
                    int required = 1;
                    if (entries_guess[index].id_guess < 100) {
                        required = g_indexedValues_guess[entries_guess[index].id_guess]
                            ->GetFirst_guess(g_characterView_guess->Info_guess()->class_119c_guess);
                    }
                    if (required <= g_characterView_guess->Info_guess()->level_11a4_guess &&
                        state_164_guess != 0) {
                        state_164_guess->Enabled = 1;
                    }
                }
            }
        }
        if (text_188_guess != 0) {
            FormatNumber_guess(&text, EQ_ARRAY(const char, 0x0063F53C),
                g_characterView_guess->Info_guess()->copper_11e0_guess);
            ((TextControlVtable_guess*)text_188_guess)->SetWindowTextA_guess(text);
        }
        if (text_184_guess != 0) {
            FormatNumber_guess(&text, EQ_ARRAY(const char, 0x0063F53C),
                g_characterView_guess->Info_guess()->silver_11dc_guess);
            ((TextControlVtable_guess*)text_184_guess)->SetWindowTextA_guess(text);
        }
        if (text_180_guess != 0) {
            FormatNumber_guess(&text, EQ_ARRAY(const char, 0x0063F53C),
                g_characterView_guess->Info_guess()->gold_11d8_guess);
            ((TextControlVtable_guess*)text_180_guess)->SetWindowTextA_guess(text);
        }
        if (text_17c_guess != 0) {
            FormatNumber_guess(&text, EQ_ARRAY(const char, 0x0063F53C),
                g_characterView_guess->Info_guess()->platinum_11d4_guess);
            ((TextControlVtable_guess*)text_17c_guess)->SetWindowTextA_guess(text);
        }
    }
}

// Player's value for skill `index` or language index - 100 (one of 32 language bytes).
// FUNCTION: TITANIUM 0x0056AE31
unsigned int __stdcall GetSkillOrLanguageValue_guess(int index) {
    if (index < 100) {
        return g_lookupTableRoot_guess->data_guess.method_guess[
            g_lookupTableRoot_guess->data_guess.branch_guess->offset_guess].Get_guess(index);
    }
    unsigned int offset = index - 100;
    LookupTableRoot_guess* root = g_lookupTableRoot_guess;
    LookupTableBranch_guess* branch = root->data_guess.branch_guess;
    unsigned char* value = &root->data_guess.bytes_guess[branch->offset_guess + 0x0c];
    if (offset >= 32) {
        // Language index past 31: int 3, as in the original.
        __debugbreak();
    }
    return value[offset];
}

// Selection sort by the player's value, ascending or descending by `direction`.
// FUNCTION: TITANIUM 0x0056AE70
void CTrainWndView_guess::SortValues_guess(int direction) {
    for (int i = 0; i < count_guess; ++i) {
        int best = GetSkillOrLanguageValue_guess(entries_guess[i].id_guess);
        int bestIndex = i;
        for (int j = i + 1; j < count_guess; ++j) {
            if ((GetSkillOrLanguageValue_guess(entries_guess[j].id_guess) - best > 0) == (direction > 0)) {
                best = GetSkillOrLanguageValue_guess(entries_guess[j].id_guess);
                bestIndex = j;
            }
        }
        if (i != bestIndex) {
            Swap_guess(i, bestIndex);
        }
    }
}

// Trainer window: adds a list row named for skill or language `id` and fills its columns (0x0056AF2C).
// The full refill (0x0056B814) adds each offer this way.
// FUNCTION: TITANIUM 0x0056B391
// @early-stop: tiebreak, diff ndiff=8
void CTrainWndView_guess::AddRow_guess(int id_guess) {
    CXStr text_guess;
    if (list_guess != 0) {
        text_guess = (char*)GetSkillOrLanguageName_guess(id_guess);
        FillRow_guess(list_guess->AddString(text_guess, -1, 0, 0));
    }
}

// Refreshes the row for `id`; for a usable skill (flag `flag` 0) also tells the hotkey sink (type 0xB) so
// skill buttons update.
// FUNCTION: TITANIUM 0x0056B400
void CTrainWndView_guess::Post_guess(int id, int flag) {
    if (Ready_guess()) {
        for (int i = 0; i < count_guess; ++i) {
            if (entries_guess[i].id_guess == id) {
                FillRow_guess(i);
                break;
            }
        }
        if (flag == 0 && id < 100 && g_indexedValues_guess[id]->flag_9_guess != 0 &&
            pinstCCursorAttachment_guess->Test_guess(0xb)) {
            pinstCCursorAttachment_guess->Send_guess(0, 0xb, id,
                (int)pStringTable->getString(g_indexedValues_guess[id]->value_guess, 0), -1);
        }
    }
}

// Train button: checks the trainer may teach it (BitchCanTrain_guess) and the price (12065 when short), sends
// OP_GMTrainSkill (12 bytes), and pays locally; prints 12066 "You have learned the basics of %2." or 12067
// for a language's fluency.
// FUNCTION: TITANIUM 0x0056B48E
// @early-stop: budget, structural ndiff=72
void CTrainWndView_guess::Train_guess() {
    int check = 0;
    int flag;
    int value;
    char message[1024];
    if (list_guess != 0 && g_activeWorldEntry_guess != 0) {
        int index = list_guess->GetCurSel();
        if (index != -1) {
            int id = entries_guess[index].id_guess;
            if (id > 99) {
                if (g_characterObject_guess->BitchCanTrain_guess(
                        entries_guess[index].value_guess, 1, id - 100) == 0) {
                    return;
                }
                value = id - 100;
                flag = 1;
            } else {
                if (g_characterObject_guess->BitchCanTrain_guess(
                        entries_guess[index].value_guess, 0, id) == 0) {
                    return;
                }
                value = id;
                flag = 0;
                check = (g_characterObject_guess->inner_c280_guess.HasSkill_guess(id) == 0);
            }
            int price = g_characterObject_guess->CostToTrain_guess(
                flag, scale_7c4_guess, value);
            int platinum = g_characterView_guess->Info_guess()->platinum_11d4_guess;
            int gold = g_characterView_guess->Info_guess()->gold_11d8_guess;
            int silver = g_characterView_guess->Info_guess()->silver_11dc_guess;
            int copper = g_characterView_guess->Info_guess()->copper_11e0_guess;
            int money = ((platinum * 10 + gold) * 10 + silver) * 10 + copper;
            if (price > money) {
                FormatDisplay_guess(message, 0x2f21,
                    g_indexedDispatch_guess->CleanText_guess(
                        g_activeWorldEntry_guess->text_120_guess), 0,
                    0, 0, 0, 0, 0, 0, 0);
                pEverQuest->dsp_chat(message, 0x111, 1);
            } else {
                if (price != 0) {
                    g_characterObject_guess->SpendMoney_guess(price);
                }
                int data[3];
                data[0] = g_activeWorldEntry_guess->id_guess;
                data[1] = flag;
                data[2] = value;
                EQSendMessage(&g_worldConnection_guess, OP_GMTrainSkill, data, 0xc, 1);
                if (check != 0) {
                    g_characterView_guess->Info_guess()->practicePoints_11f8_guess--;
                    FormatDisplay_guess(message, 0x2f22,
                        g_indexedDispatch_guess->CleanText_guess(
                            g_activeWorldEntry_guess->text_120_guess),
                        pStringTable->getString(
                            g_indexedValues_guess[value]->value_guess, 0),
                        0, 0, 0, 0, 0, 0, 0);
                    pEverQuest->dsp_chat(message, 0x111, 1);
                } else {
                    if (id > 99) {
                        unsigned int offset = id - 100;
                        if (offset >= 0x20) {
                            __debugbreak();
                        }
                        if (g_characterView_guess->values_c_guess[offset] == 0) {
                            FormatDisplay_guess(message, 0x2f22,
                                g_indexedDispatch_guess->CleanText_guess(
                                    g_activeWorldEntry_guess->text_120_guess),
                                g_indexedDispatch_guess->Name_guess(offset),
                                0, 0, 0, 0, 0, 0, 0);
                        } else {
                            FormatDisplay_guess(message, 0x2f23,
                                g_indexedDispatch_guess->CleanText_guess(
                                    g_activeWorldEntry_guess->text_120_guess),
                                g_indexedDispatch_guess->Name_guess(offset),
                                0, 0, 0, 0, 0, 0, 0);
                        }
                        pEverQuest->dsp_chat(message, 0x111, 1);
                        g_characterView_guess->Info_guess()->practicePoints_11f8_guess--;
                    } else {
                        g_characterView_guess->Info_guess()->practicePoints_11f8_guess--;
                        g_characterView_guess->AddSkillValue_guess(id, 1);
                    }
                }
                FillRow_guess(index);
            }
        }
    }
}

// Done closes; Train trains; a list click shows 12056 "Interested in training in %2 ?" (12055 for a language)
// from the trainer; column headers re-sort.
// FUNCTION: TITANIUM 0x0056B9B5
// @early-stop: budget, structural ndiff=83
int CTrainWndView_guess::WndNotification_guess(CXWnd* sender_guess,
    unsigned int message_guess, void* data_guess) {
    char text_guess[1024];
    if (message_guess == 1) {
        if (sender_guess == field_168_guess) {
            ((CallbackVtable_guess*)this)->Slot34_guess();
            return 1;
        }
        if (sender_guess == state_164_guess) {
            Train_guess();
            Flush_guess();
            return 1;
        }
        if (sender_guess == (CXWnd*)list_guess) {
            int index_guess = ((CListWnd*)list_guess)->GetCurSel();
            if (index_guess != -1 && g_displayOwner_guess != 0) {
                int value_guess = entries_guess[index_guess].id_guess;
                char* first_guess;
                char* second_guess;
                int format_guess;
                if (value_guess < 100) {
                    first_guess = pStringTable->getString(
                        g_indexedValues_guess[value_guess]->value_guess, 0);
                    second_guess = g_indexedDispatch_guess->GetDisplay_guess(
                        &g_displayOwner_guess->text_guess);
                    format_guess = 0x2f18;
                } else {
                    first_guess = (char*)g_indexedDispatch_guess->Dispatch_guess(
                        value_guess - 100);
                    second_guess = g_indexedDispatch_guess->GetDisplay_guess(
                        &g_displayOwner_guess->text_guess);
                    format_guess = 0x2f17;
                }
                FormatDisplay_guess(text_guess, format_guess, second_guess,
                    first_guess, 0, 0, 0, 0, 0, 0, 0);
                g_indexedDispatch_guess->dsp_chat(text_guess, 0xf, 1);
            }
            Flush_guess();
            return 1;
        }
    }
    if (message_guess == 0xf) {
        if (data_guess == 0) {
            nameSortOrder_07c8_guess = -nameSortOrder_07c8_guess;
            flag_7d0_guess = 1;
            UpdateAll_guess(1);
        } else if ((int)data_guess == 1 || (int)data_guess == 2) {
            valueSortOrder_07cc_guess = -valueSortOrder_07cc_guess;
            flag_7d0_guess = 0;
            UpdateAll_guess(1);
        }
    }
    return ((CSidlScreenWnd*)this)->CSidlScreenWnd::WndNotification(
        sender_guess, message_guess, data_guess);
}

// Polymorphic view of a CListWnd: the slots up to the one Reset calls (vtable +0x130).
struct ListSlots_guess {
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
    virtual void Slot63_guess();
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
    virtual void Slot76_guess();
};

// Re-sorts (by name or value, whichever was last used) when `flag` is set, then refills every row.
// FUNCTION: TITANIUM 0x0056B814
void CTrainWndView_guess::UpdateAll_guess(char flag) {
    list_guess->SetCurSel(-1);
    if (flag != 0) {
        if (flag_7d0_guess != 0) {
            SortNames_guess(nameSortOrder_07c8_guess);
        } else {
            SortValues_guess(valueSortOrder_07cc_guess);
        }
    }
    if (list_guess != 0) {
        ((ListSlots_guess*)list_guess)->Slot76_guess();
        for (int i = 0; i < count_guess; ++i) {
            AddRow_guess(entries_guess[i].id_guess);
        }
    }
    Flush_guess();
}

// Trainer offer: skills the trainer lists (`ids`, > 0) that the player's class can learn, minus SkillDefense,
// SkillOffense and SkillBerserking, then the languages in `flags` the player can learn.
// FUNCTION: TITANIUM 0x0056B897
void CTrainWndView_guess::SetGMData_guess(int* ids, unsigned char* flags, int value) {
    field_7c4_guess = value;
    count_guess = 0;
    for (int i = 0; i < 100; ++i) {
        if (i != 0x48 && ids[i] > 0) {
            if (g_indexedValues_guess[i]->GetFirst_guess(
                    g_characterView_guess->Info_guess()->class_119c_guess) > 0 &&
                i != 0x21 && i != 0xf) {
                entries_guess[count_guess].id_guess = i;
                entries_guess[count_guess].value_guess = ids[i];
                ++count_guess;
            }
        }
    }
    for (int i = 0; i < 0x20; ++i) {
        if (g_characterView_guess->Test_guess(i) != 0 && flags[i] > 0) {
            entries_guess[count_guess].id_guess = i + 100;
            entries_guess[count_guess].value_guess = 100;
            ++count_guess;
        }
    }
    UpdateAll_guess(0);
}

// On open: music selection 7 (training), then fills the window.
// FUNCTION: TITANIUM 0x0056B98F
bool CTrainWndView_guess::Init_guess() {
    field_15c_guess = 0;
    g_notifyTarget_guess->Notify_guess(7, 1);
    UpdateAll_guess(0);
    return true;
}

// Tribute benefit window: marks the personal benefit list for a refresh (+0x189). The tribute code sets
// it when lists are requested, when a tribute's tier changes and on the tribute master messages.
// FUNCTION: TITANIUM 0x0056BB49
void CTributeBenefitWndView_guess::SetFirst_guess() {
    flag_189_guess = 1;
}

// Tribute benefit window: marks the guild benefit list for a refresh (+0x1BD). Set by the guild tribute
// messages and the guild tribute master's upgrade and downgrade buttons.
// FUNCTION: TITANIUM 0x0056BB51
void CTributeBenefitWndView_guess::SetSecond_guess() {
    flag_1bd_guess = 1;
}

// Copies the guild tribute on/off state of the player's guild into the status object.
// FUNCTION: TITANIUM 0x0056BB59
void CTributeBenefitWndView_guess::UpdateValue_guess() {
    char value = 0;
    LookupGlobal_guess* data = g_lookupGlobal_guess;
    if (data->state_guess != -1) {
        LookupResult_guess* result = g_lookupManager_guess.Find_guess(data->input_guess);
        if (result != 0) {
            value = result->value_guess;
        }
    }
    if (state_guess != 0) {
        state_guess->enabled_005d_guess = value;
    }
}

// Destructor of the tribute benefit window (vtable 0x65F5B0): frees its five buffers (+0x16C..+0x17C),
// then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0056BB1D
CTributeBenefitWndView_guess::~CTributeBenefitWndView_guess() {
    int count = 5;
    void** allocation = allocations_guess;
    do {
        free(*allocation);
        ++allocation;
        --count;
    } while (count != 0);
    ((Object_guess*)this)->Cleanup_guess();
}

// Scalar deleting destructor of the tribute benefit window (vtable 0x65F5B0 slot 1): destroys it and
// frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x0056C715
void* CTributeBenefitWndView_guess::Delete_guess(unsigned char flags) {
    this->CTributeBenefitWndView_guess::~CTributeBenefitWndView_guess();
    if ((flags & 1) != 0) {
        free(this);
    }
    return this;
}

int __cdecl CompareTributeName_guess(const char** a, const char** b);

// Benefit sort: by tier (+0x40), then name.
// FUNCTION: TITANIUM 0x0056BF76
int __cdecl CompareTributeTierThenName_guess(SortEntry_guess** a, SortEntry_guess** b) {
    int left = (*a)->key40_guess;
    int right = (*b)->key40_guess;
    if (left == right) {
        return CompareTributeName_guess((const char**)a, (const char**)b);
    }
    int difference = left - right;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Benefit sort: by cost (+0x44), then name.
// FUNCTION: TITANIUM 0x0056BFC1
int __cdecl CompareTributeCostThenName_guess(SortEntry_guess** a, SortEntry_guess** b) {
    int left = (*a)->key44_guess;
    int right = (*b)->key44_guess;
    if (left == right) {
        return CompareTributeName_guess((const char**)a, (const char**)b);
    }
    int difference = left - right;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// Benefit sort: by the +0x48 value, then name.
// FUNCTION: TITANIUM 0x0056C00C
int __cdecl FUN_0056c00c_guess(SortEntry_guess** a, SortEntry_guess** b) {
    int left = (*a)->key48_guess;
    int right = (*b)->key48_guess;
    if (left == right) {
        return CompareTributeName_guess((const char**)a, (const char**)b);
    }
    int difference = left - right;
    if (difference > 0) {
        return 1;
    }
    return (difference >= 0) - 1;
}

// qsort comparator by name: strcmp of the strings the two entries point to. The benefit, guild tribute
// master and tribute master list sorts use it, alone or as the tie-break.
// FUNCTION: TITANIUM 0x0056BF4F
int __cdecl CompareTributeName_guess(const char** a, const char** b) {
    const char* left = *a;
    return strcmp(left, *b);
}

struct LayoutLookup_guess {
    char pad_000[4];
    unsigned int sidlPiece_124_guess;
    char pad_128[0x30];
    int field_158_guess;
    // EXTERNAL: TITANIUM 0x00572300 LayoutLookup_guess::Lookup_guess
    void* Lookup_guess(const char* name);
};

struct BenefitStr_guess;

struct BenefitListVtable_guess {
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
    virtual void Slot63_guess();
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
};

struct BenefitList_guess : BenefitListVtable_guess {
    virtual void Slot76_guess();
    char pad_004[0x158];
    unsigned char flag_15c_guess;
    char pad_15d[0x0f];
    unsigned int color_16c_guess;
    // EXTERNAL: TITANIUM 0x00597BE0 BenefitList_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 BenefitList_guess::GetItemData
    int GetItemData(int index);
    // EXTERNAL: TITANIUM 0x00597C60 BenefitList_guess::SetColors
    void SetColors(int first_guess, unsigned int second_guess, unsigned int third_guess);
    // EXTERNAL: TITANIUM 0x005982E0 BenefitList_guess::SetColumnJustification
    void SetColumnJustification(int column_guess, int justification_guess);
    // EXTERNAL: TITANIUM 0x0059B9D0 BenefitList_guess::AddString
    int AddString(const BenefitStr_guess& text_guess, int color_guess,
        int id_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x0059B360 BenefitList_guess::SetItemText
    void SetItemText(int id_guess, int column_guess, BenefitStr_guess* text_guess);
    // EXTERNAL: TITANIUM 0x0059B3E0 BenefitList_guess::SetColor_guess
    void SetColor_guess(int id_guess, int column_guess, int color_guess);
    // EXTERNAL: TITANIUM 0x00597C20 BenefitList_guess::SetCurSel
    void SetCurSel(int row_guess);
};

struct BenefitWindow_guess {
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
    virtual void Slot63_guess();
    virtual void Slot64_guess();
    virtual void Slot65_guess();
    virtual void Slot66_guess();
    virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual void Slot69_guess();
    virtual void Slot70_guess();
    virtual void Slot71_guess();
    virtual void Slot72_guess();
    virtual void Slot73_guess(void* value);
    virtual void Slot74_guess(void* value);
};

struct BenefitStr_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0BenefitStr_guess@@QAE@PBD@Z
    BenefitStr_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571FC0 ??4BenefitStr_guess@@QAEAAU0@PBD@Z
    BenefitStr_guess& operator=(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 BenefitStr_guess::FreeRep
    void FreeRep(int value);
    ~BenefitStr_guess() {
        if (value_guess != 0) {
            FreeRep(value_guess);
        }
    }
};

struct TextTarget_guess {
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
    virtual void Slot63_guess(BenefitStr_guess* text_guess);
    char pad_004[0x59];
    unsigned char flag_5d_guess;
};

struct BenefitStr_guess;

struct BenefitName_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x00571E00 ??0BenefitName_guess@@QAE@PBD@Z
    BenefitName_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00571D00 BenefitName_guess::FreeRep
    void FreeRep(int value);
    ~BenefitName_guess() {
        if (value_guess != 0) {
            FreeRep(value_guess);
        }
        value_guess = 0;
    }
};

struct BenefitBase_guess {
    virtual void Anchor_guess() = 0;
    char pad_004[0x62];
    unsigned char flags_066_guess;
    char pad_067[0xb9];
    // EXTERNAL: TITANIUM 0x005A3850 BenefitBase_guess::BenefitBase_guess
    BenefitBase_guess(void* parent, const BenefitName_guess& name, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A25B0 BenefitBase_guess::CreateChildrenFromSidl
    void CreateChildrenFromSidl();
    // EXTERNAL: TITANIUM 0x005A1E10 BenefitBase_guess::GetChildItem
    void* GetChildItem(const CXStr& name);
    // EXTERNAL: TITANIUM 0x005A3100 BenefitBase_guess::~BenefitBase_guess
    virtual ~BenefitBase_guess();
};

struct BenefitGuildRow_guess {
    char text_guess[0x40];
    int value_040_guess;
    int value_044_guess;
    char pad_048[4];
    int id_04c_guess;
};

// EXTERNAL: TITANIUM 0x0065F5B0 ??_7CTributeBenefitWnd_guess@@6B@
struct CTributeBenefitWnd_guess : BenefitBase_guess {
    LayoutLookup_guess layout_120_guess;
    CStmlWnd* activeSink_15c_guess;
    BenefitList_guess* activeList_160_guess;
    TextTarget_guess* downgrade_164_guess;
    BenefitWindow_guess* window_168_guess;
    SortEntry_guess* allocations_16c_guess[5];
    int activeCount_0180_guess;
    int mode_184_guess;
    char flag_188_guess;
    char flag_189_guess;
    char pad_18a[2];
    CStmlWnd* guildSink_18c_guess;
    BenefitList_guess* guildList_190_guess;
    TextTarget_guess* optOut_194_guess;
    void* activate_198_guess;
    void* guildLayout_19c_guess;
    TextTarget_guess* target_1a0_guess;
    void* guildPage_1a4_guess;
    void* subwindows_1a8_guess;
    union {
        char pad_1ac[8];
        BenefitGuildRow_guess* rows_1ac_guess[2];
    };
    int entryCount_01b4_guess;
    int field_1b8_guess;
    char flag_1bc_guess;
    char flag_1bd_guess;
    char pad_1be[2];
    int lastUpdateTime_01c0_guess;

    CTributeBenefitWnd_guess(void* parent);

    void NotifyText_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
        void* data_guess);
    // EXTERNAL: TITANIUM 0x005A1FE0 CTributeBenefitWnd_guess::StoreIniListWnd_guess
    void StoreIniListWnd_guess(BenefitList_guess* list, const char* name);
    // EXTERNAL: TITANIUM 0x005A1EF0 CTributeBenefitWnd_guess::LoadIniListWnd
    void LoadIniListWnd(BenefitList_guess* list, const char* name);

    void StoreIniInfo_guess();
    void LoadIniInfo_guess();
    void SortData_guess(void* data, int count);
    void SelectActive_guess(int id, const char* name);
    void SelectGuild_guess(int id, const char* name);
    void RebuildEntries_guess();
    void RefreshFromCandidates_guess();
    void UpdateActive_guess();
    char CheckReady_guess();
    void OnProcessFrame_guess();
    void UpdateDowngrade_guess();
    // EXTERNAL: TITANIUM 0x0056BD46 CTributeBenefitWnd_guess::UpdateGuild_guess
    void UpdateGuild_guess();
};

typedef int (__cdecl* SortCompare_guess)(const char** first, const char** second);

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// EXTERNAL: TITANIUM 0x0056BF64 FUN_0056bf64_guess
int __cdecl FUN_0056bf64_guess(const char** first, const char** second);
// EXTERNAL: TITANIUM 0x0056BFAF FUN_0056bfaf_guess
int __cdecl FUN_0056bfaf_guess(const char** first, const char** second);
// EXTERNAL: TITANIUM 0x0056BFFA FUN_0056bffa_guess
int __cdecl FUN_0056bffa_guess(const char** first, const char** second);

// EXTERNAL: TITANIUM 0x0060EE40 _qsort
void __cdecl _qsort(void* base, unsigned int count, unsigned int size,
    SortCompare_guess compare);

// Guild status label: string 12946 "off" or 12947 "on" for the player's guild.
// FUNCTION: TITANIUM 0x0056BB97
void CTributeBenefitWnd_guess::NotifyText_guess() {
    BenefitStr_guess text(pStringTable->getString(0x3292, 0));
    int mode = 0x3292;
    int state = g_lookupGlobal_guess->state_guess;
    if (state != -1) {
        LookupResult_guess* result = g_lookupManager_guess.Find_guess(g_lookupGlobal_guess->input_guess);
        if (result != 0) {
            mode += result->value_guess != 0;
        }
        text = pStringTable->getString(mode, 0);
    }
    if (target_1a0_guess != 0) {
        target_1a0_guess->Slot63_guess(&text);
    }
}

struct DowngradeEligibility_guess {
    // EXTERNAL: TITANIUM 0x00434495 DowngradeEligibility_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x00435150 DowngradeEligibility_guess::GetUpkeep_guess
    int GetUpkeep_guess();
};

struct DowngradeThreshold_guess {
    char pad_000[0xe80];
    __int64 threshold_guess;
};

#define g_downgradeEligibility_guess EQ_GLOBAL(DowngradeEligibility_guess, 0x00850350)
#define g_downgradeThreshold_guess EQ_GLOBAL(DowngradeThreshold_guess*, 0x00905D00)
#define g_statusSelector_guess EQ_GLOBAL(unsigned char, 0x00850375)

// Downgrade button text (Activate 6006 / Deactivate 6007, by state) and whether it is enabled.
// FUNCTION: TITANIUM 0x0056BC4D
// @early-stop: budget, diff ndiff=5
void CTributeBenefitWnd_guess::UpdateDowngrade_guess() {
    if (downgrade_164_guess != 0) {
        {
            BenefitName_guess text(pStringTable->getString(
                (g_statusSelector_guess != 0) + 0x1776, 0));
            downgrade_164_guess->Slot63_guess((BenefitStr_guess*)&text);
        }

        char enabled;
        if (g_downgradeEligibility_guess.Check_guess()) {
            int state = g_downgradeEligibility_guess.GetUpkeep_guess();
            if (state > 0) {
                enabled = 1;
            } else {
                enabled = 0;
            }
        } else {
            enabled = 0;
        }

        __int64 threshold = g_downgradeThreshold_guess->threshold_guess;
        int value = g_downgradeEligibility_guess.GetUpkeep_guess();
        char active = enabled & (value < threshold);
        CTributeMasterWnd_guess* statusOwner = pinstCTributeMasterWnd_guess;
        if (statusOwner != 0) {
            active &= !statusOwner->IsVisible_guess();
        }
        downgrade_164_guess->flag_5d_guess = active;
    }
}

// Refills the guild benefit list (grey 0xFFC0C0C0 while guild tribute is off), keeping the selection.
// FUNCTION: TITANIUM 0x0056BD46
// @early-stop: budget, structural ndiff=29
void CTributeBenefitWnd_guess::UpdateGuild_guess() {
    if (guildList_190_guess == 0) {
        return;
    }

    int selectedIndex = guildList_190_guess->GetCurSel();
    int selectedValue = -1;
    if (selectedIndex != -1) {
        selectedValue = guildList_190_guess->GetItemData(selectedIndex);
    }
    guildList_190_guess->Slot76_guess();

    int selectedRow = -1;
    for (int index = 0; index < entryCount_01b4_guess; ++index) {
        int color = 0xffc0c0c0;
        if (g_lookupGlobal_guess->state_guess != -1) {
            LookupResult_guess* result = g_lookupManager_guess.Find_guess(
                g_lookupGlobal_guess->input_guess);
            if (result != 0 && result->value_guess != 0) {
                color = -1;
            }
        }

        int rowId = guildList_190_guess->AddString(
            BenefitStr_guess(rows_1ac_guess[index]->text_guess), color,
            rows_1ac_guess[index]->id_04c_guess, 0);
        {
            BenefitStr_guess text(_itoa(rows_1ac_guess[index]->value_040_guess + 1,
                EQ_ARRAY(char, 0x0099DB00), 10));
            guildList_190_guess->SetItemText(rowId, 1, &text);
        }
        guildList_190_guess->SetColor_guess(rowId, 1, color);
        {
            BenefitStr_guess text(_itoa(rows_1ac_guess[index]->value_044_guess,
                EQ_ARRAY(char, 0x0099DB00), 10));
            guildList_190_guess->SetItemText(rowId, 2, &text);
        }
        guildList_190_guess->SetColor_guess(rowId, 2, color);

        if (rows_1ac_guess[index]->id_04c_guess == selectedValue) {
            selectedRow = rowId;
        }
    }
    if (selectedRow == -1) {
        guildSink_18c_guess->SetSTMLText(
            (const char*)EQ_ARRAY(char, 0x0063F53F), 1, 0);
    }
    guildList_190_guess->SetCurSel(selectedRow);
}

// Picks the sort callback for the current column (`mode_184_guess`) and direction.
// FUNCTION: TITANIUM 0x0056C057
void CTributeBenefitWnd_guess::SortData_guess(void* data, int count) {
    SortCompare_guess compare = 0;
    switch (mode_184_guess) {
    case 2:
        if (flag_188_guess != 0) {
            compare = (SortCompare_guess)CompareTributeCostThenName_guess;
        } else {
            compare = (SortCompare_guess)FUN_0056bffa_guess;
        }
        break;
    case 1:
        if (flag_188_guess != 0) {
            compare = (SortCompare_guess)CompareTributeTierThenName_guess;
        } else {
            compare = (SortCompare_guess)FUN_0056bfaf_guess;
        }
        break;
    case 0:
        compare = (SortCompare_guess)CompareTributeName_guess;
        if (flag_188_guess == 0) {
            compare = (SortCompare_guess)FUN_0056bf64_guess;
        }
        break;
    }
    if (count > 0 && compare != 0) {
        _qsort(data, count, 4, compare);
    }
}

// LoadIniInfo side: restores both benefit lists (0x005A1EF0, LoadIniListWnd) and the Layout setting.
// FUNCTION: TITANIUM 0x0056C0CB
void CTributeBenefitWnd_guess::LoadIniInfo_guess() {
    if (activeList_160_guess != 0) {
        LoadIniListWnd(activeList_160_guess, "ActiveBenefitList");
    }
    if (guildList_190_guess != 0) {
        LoadIniListWnd(guildList_190_guess, "GuildBenefitList");
    }
    if (window_168_guess != 0) {
        window_168_guess->Slot73_guess(layout_120_guess.Lookup_guess("Layout"));
    }
}

// StoreIniInfo side of 0x0056C0CB: saves both benefit lists through the list INI store (0x005A1FE0) and
// the Layout setting.
// FUNCTION: TITANIUM 0x0056C128
void CTributeBenefitWnd_guess::StoreIniInfo_guess() {
    if (activeList_160_guess != 0) {
        StoreIniListWnd_guess(activeList_160_guess, "ActiveBenefitList");
    }
    if (guildList_190_guess != 0) {
        StoreIniListWnd_guess(guildList_190_guess, "GuildBenefitList");
    }
    if (window_168_guess != 0) {
        window_168_guess->Slot74_guess(layout_120_guess.Lookup_guess("Layout"));
    }
}

// Shows `name` in the description box when benefit `id` is still the selected one.
// FUNCTION: TITANIUM 0x0056C185
void CTributeBenefitWnd_guess::SelectActive_guess(int id, const char* name) {
    if (activeList_160_guess != 0) {
        int index = activeList_160_guess->GetCurSel();
        if (index != -1) {
            if (activeList_160_guess->GetItemData(index) == id &&
                activeSink_15c_guess != 0) {
                activeSink_15c_guess->SetSTMLText(name, 1, 0);
            }
        }
    }
}

// When the selected guild benefit row has value `id`, shows `name` in the guild description.
// FUNCTION: TITANIUM 0x0056C1DB
void CTributeBenefitWnd_guess::SelectGuild_guess(int id, const char* name) {
    if (guildList_190_guess != 0) {
        int index = guildList_190_guess->GetCurSel();
        if (index != -1) {
            if (guildList_190_guess->GetItemData(index) == id &&
                guildSink_18c_guess != 0) {
                guildSink_18c_guess->SetSTMLText(name, 1, 0);
            }
        }
    }
}

// Tribute benefit window constructor: builds the children, sets up the personal (ActiveBenefitList) and
// guild (GuildBenefitList) lists, labels the downgrade button with string 0x1776 and disables it and Opt
// Out (+0x5D, Enabled), then restores both lists and the layout from the INI (0x0056C0CB).
// FUNCTION: TITANIUM 0x0056C231
CTributeBenefitWnd_guess::CTributeBenefitWnd_guess(void* parent)
    : BenefitBase_guess(parent, "TributeBenefitWnd", 0xfffffdff, 1, 0) {
    activeSink_15c_guess = 0;
    activeList_160_guess = 0;
    downgrade_164_guess = 0;
    window_168_guess = 0;
    mode_184_guess = 0;
    flag_188_guess = 1;
    activeCount_0180_guess = 0;
    flag_189_guess = 0;
    guildSink_18c_guess = 0;
    guildList_190_guess = 0;
    optOut_194_guess = 0;
    activate_198_guess = 0;
    guildLayout_19c_guess = 0;
    target_1a0_guess = 0;
    field_1b8_guess = 0;
    flag_1bc_guess = 1;
    entryCount_01b4_guess = 0;
    flag_1bd_guess = 0;
    memset(allocations_16c_guess, 0, 0x14);
    memset(pad_1ac, 0, 8);
    if (layout_120_guess.sidlPiece_124_guess != 0) {
        flags_066_guess |= 1;
        layout_120_guess.field_158_guess = 0x2a;
        CreateChildrenFromSidl();
        activeSink_15c_guess = (CStmlWnd*)GetChildItem("Description");
        activeList_160_guess = (BenefitList_guess*)GetChildItem("ActiveBenefitList");
        downgrade_164_guess = (TextTarget_guess*)GetChildItem("DowngradeButton");
        window_168_guess = (BenefitWindow_guess*)GetChildItem("Layout");
        if (activeList_160_guess != 0) {
            activeList_160_guess->SetColors(-1, 0xffffff00, 0xff808080);
            activeList_160_guess->SetColumnJustification(0, 0);
            activeList_160_guess->SetColumnJustification(1, 1);
            activeList_160_guess->SetColumnJustification(2, 1);
            activeList_160_guess->color_16c_guess = 0xff8aa3ff;
            activeList_160_guess->flag_15c_guess = 1;
        }
        if (downgrade_164_guess != 0) {
            {
                BenefitStr_guess text(pStringTable->getString(0x1776, 0));
                downgrade_164_guess->Slot63_guess(&text);
            }
            downgrade_164_guess->flag_5d_guess = 0;
        }
        guildSink_18c_guess = (CStmlWnd*)GetChildItem("GuildDescription");
        guildList_190_guess = (BenefitList_guess*)GetChildItem("GuildBenefitList");
        optOut_194_guess = (TextTarget_guess*)GetChildItem("OptOutButton");
        activate_198_guess = GetChildItem("ActivateButton");
        guildLayout_19c_guess = GetChildItem("GuildLayout");
        target_1a0_guess = (TextTarget_guess*)GetChildItem("GuildStatusLabel");
        guildPage_1a4_guess = GetChildItem("GuildPage");
        subwindows_1a8_guess = GetChildItem("Subwindows");
        if (guildList_190_guess != 0) {
            guildList_190_guess->SetColors(-1, 0xffffff00, 0xff808080);
            guildList_190_guess->SetColumnJustification(0, 0);
            guildList_190_guess->SetColumnJustification(1, 1);
            guildList_190_guess->SetColumnJustification(2, 1);
            guildList_190_guess->color_16c_guess = 0xff8aa3ff;
            guildList_190_guess->flag_15c_guess = 1;
        }
        if (optOut_194_guess != 0) {
            optOut_194_guess->flag_5d_guess = 0;
        }
        lastUpdateTime_01c0_guess = 0;
        LoadIniInfo_guess();
        flag_189_guess = 1;
        flag_1bd_guess = 1;
    }
}

struct RecordPair_guess {
    int key_guess;
    int index_guess;
};

#define g_records_guess EQ_ARRAY(RecordPair_guess, 0x0091D6D8)

struct NameSource_guess {
    // EXTERNAL: TITANIUM 0x00572300 NameSource_guess::Get_guess
    char* Get_guess();
};

struct NameEntry_guess {
    char pad_0[4];
    NameSource_guess source_4_guess;
    char pad_5[0x33];
    int values_38_guess[10];
};

struct NameTable_guess {
    // EXTERNAL: TITANIUM 0x00434B0A NameTable_guess::Find_guess
    NameEntry_guess* Find_guess(int key);
    // EXTERNAL: TITANIUM 0x00434AE0 NameTable_guess::FindValue_guess
    NameEntry_guess* FindValue_guess(int key);
    // EXTERNAL: TITANIUM 0x00434495 NameTable_guess::IsTributeAvailable_guess
    char IsTributeAvailable_guess();
    // EXTERNAL: TITANIUM 0x004346D5 NameTable_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x00434B8A NameTable_guess::RequestTributeDescription_guess
    void RequestTributeDescription_guess(int message_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x00434C06 NameTable_guess::RequestGuildTributeDescription_guess
    void RequestGuildTributeDescription_guess(int message_guess, int index_guess);
};

#define g_nameTable_guess EQ_GLOBAL(NameTable_guess, 0x00850350)

// Rebuilds the guild benefit entries from the two (id, tier) pairs at 0x91D6D8.
// FUNCTION: TITANIUM 0x0056C739
void CTributeBenefitWnd_guess::RebuildEntries_guess() {
    entryCount_01b4_guess = 0;
    int* pair = EQ_ARRAY(int, 0x0091D6DC);
    do {
        int key = pair[-1];
        int index = *pair;
        NameEntry_guess* entry = g_nameTable_guess.Find_guess(key);
        if (entry != 0) {
            if (((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess] == 0) {
                ((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess] = new SortEntry_guess();
            }
            strcpy(((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess]->name_guess, entry->source_4_guess.Get_guess());
            ((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess]->key44_guess = entry->values_38_guess[index];
            ((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess]->key40_guess = index;
            ((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess]->key4c_guess = key;
            entryCount_01b4_guess++;
        } else {
            free(((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess]);
            ((SortEntry_guess**)pad_1ac)[entryCount_01b4_guess] = 0;
        }
        pair += 2;
    } while ((int)pair < (int)EQ_ARRAY(int, 0x0091D6EC));
    SortData_guess(pad_1ac, entryCount_01b4_guess);
    UpdateGuild_guess();
    NotifyText_guess();
    ((CTributeBenefitWndView_guess*)this)->UpdateValue_guess();
    flag_1bd_guess = 0;
}

#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

// Refills the personal benefit list from the five active benefits, keeping the selection.
// FUNCTION: TITANIUM 0x0056C86E
void CTributeBenefitWnd_guess::UpdateActive_guess() {
    if (activeList_160_guess == 0) {
        return;
    }
    int current = ((CListWnd*)activeList_160_guess)->GetCurSel();
    int selected = -1;
    if (current != -1) {
        selected = ((CListWnd*)activeList_160_guess)->GetItemData(current);
    }
    ((ListSlots_guess*)activeList_160_guess)->Slot76_guess();
    int activeIndex = -1;
    int i = 0;
    if (activeCount_0180_guess > 0) {
        do {
            int row;
            {
                CXStr name(allocations_16c_guess[i]->name_guess);
                row = ((CListWnd*)activeList_160_guess)->AddString(name, -1,
                    allocations_16c_guess[i]->key4c_guess, 0);
            }
            {
                CXStr text(_itoa(allocations_16c_guess[i]->key40_guess + 1,
                    g_itoaBuffer_guess, 10));
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
                    activeList_160_guess)(row, 1, text);
            }
            {
                CXStr text(_itoa(allocations_16c_guess[i]->key44_guess,
                    g_itoaBuffer_guess, 10));
                EQ_METHOD(3, void, 0x0059B360, (CListWnd, int, int, const CXStr&),
                    activeList_160_guess)(row, 2, text);
            }
            if (allocations_16c_guess[i]->key4c_guess == selected) {
                activeIndex = row;
            }
            ++i;
        } while (i < activeCount_0180_guess);
    }
    if (activeIndex == -1) {
        ((CStmlWnd*)activeSink_15c_guess)->SetSTMLText(
            EQ_ARRAY(char, 0x0063F53F), 1, 0);
    }
    ((CListWnd*)activeList_160_guess)->SetCurSel(activeIndex);
    UpdateDowngrade_guess();
}

#define g_downgradeState_guess EQ_GLOBAL(unsigned char, 0x00850375)
#define g_benefitEnabled_guess EQ_GLOBAL(unsigned char, 0x0091D6ED)

// List clicks request the benefit's description; Downgrade/Activate sends OP_TributeToggle; the guild buttons
// send OP_GuildTributeToggleReq (12 bytes).
// FUNCTION: TITANIUM 0x0056CA21
int CTributeBenefitWnd_guess::WndNotification_guess(CXWnd* sender_guess,
    unsigned int message_guess, void* data_guess) {
    if (message_guess == 1) {
        if (sender_guess == (CXWnd*)activeList_160_guess) {
            int value = activeList_160_guess->GetItemData(
                activeList_160_guess->GetCurSel());
            if (activeSink_15c_guess != 0) {
                g_nameTable_guess.RequestTributeDescription_guess(0, value);
            }
            return 0;
        } else if (sender_guess == (CXWnd*)guildList_190_guess) {
            int value = guildList_190_guess->GetItemData(
                guildList_190_guess->GetCurSel());
            if (guildSink_18c_guess != 0) {
                g_nameTable_guess.RequestGuildTributeDescription_guess(2, value);
            }
            return 0;
        } else if (sender_guess == (CXWnd*)downgrade_164_guess) {
            int downgrade = (g_downgradeState_guess == 0);
            EQSendMessage(&g_worldConnection_guess, OP_TributeToggle, &downgrade, 4, 1);
            return 0;
        } else if (sender_guess == (CXWnd*)activate_198_guess) {
            int values[3];
            values[0] = (g_benefitEnabled_guess == 0);
            EQSendMessage(&g_worldConnection_guess, OP_GuildTributeToggleReq, values, 0xc, 1);
            return 0;
        } else if (sender_guess == (CXWnd*)optOut_194_guess) {
            g_lookupManager_guess.SendPacket_guess(g_lookupGlobal_guess->input_guess, 0);
            return 0;
        }
    } else if (message_guess == 0xf) {
        if (sender_guess == (CXWnd*)activeList_160_guess ||
            sender_guess == (CXWnd*)guildList_190_guess) {
            int value = mode_184_guess;
            switch ((int)data_guess) {
            case 0:
                value = 0;
                break;
            case 1:
                value = 1;
                break;
            case 2:
                value = 2;
                break;
            }
            if (sender_guess == (CXWnd*)activeList_160_guess) {
                if (value == mode_184_guess) {
                    flag_188_guess = !flag_188_guess;
                }
                mode_184_guess = value;
                SortData_guess(allocations_16c_guess, activeCount_0180_guess);
                UpdateActive_guess();
            } else if (sender_guess == (CXWnd*)guildList_190_guess) {
                if (value == field_1b8_guess) {
                    flag_1bc_guess = !flag_1bc_guess;
                }
                field_1b8_guess = value;
                SortData_guess(pad_1ac, entryCount_01b4_guess);
                UpdateGuild_guess();
            }
        }
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(sender_guess,
        message_guess, data_guess);
}

struct CandidateSlot_guess {
    int id_guess;
    int index_guess;
};

struct Candidate_guess {
    // EXTERNAL: TITANIUM 0x005F0D80 Candidate_guess::GetSlot_guess
    CandidateSlot_guess* GetSlot_guess(int index_guess);
};

#define g_candidate_guess EQ_GLOBAL(Candidate_guess*, 0x00905D00)

// Reads the player's five active tribute benefits (id, tier) into sortable entries.
// FUNCTION: TITANIUM 0x0056CBF4
void CTributeBenefitWnd_guess::RefreshFromCandidates_guess() {
    activeCount_0180_guess = 0;
    for (int i = 0; i < 5; ++i) {
        int id = g_candidate_guess->GetSlot_guess(i)->id_guess;
        int index = g_candidate_guess->GetSlot_guess(i)->index_guess;
        NameEntry_guess* entry = g_nameTable_guess.FindValue_guess(id);
        if (entry != 0) {
            if (allocations_16c_guess[activeCount_0180_guess] == 0) {
                allocations_16c_guess[activeCount_0180_guess] = new SortEntry_guess;
            }
            strcpy(allocations_16c_guess[activeCount_0180_guess]->name_guess,
                entry->source_4_guess.Get_guess());
            allocations_16c_guess[activeCount_0180_guess]->key44_guess =
                entry->values_38_guess[index];
            allocations_16c_guess[activeCount_0180_guess]->key40_guess = index;
            allocations_16c_guess[activeCount_0180_guess]->key4c_guess = id;
            activeCount_0180_guess++;
        } else {
            free(allocations_16c_guess[activeCount_0180_guess]);
            allocations_16c_guess[activeCount_0180_guess] = 0;
        }
    }
    SortData_guess(allocations_16c_guess, activeCount_0180_guess);
    UpdateActive_guess();
    flag_189_guess = 0;
}

// Tribute benefit window AboutToShow (vtable 0x65F5B0 slot 49): vetoes the show unless tribute is
// available (0x00434495); when allowed and the personal list is marked (+0x189), reloads the five
// active benefits (0x0056CBF4).
// FUNCTION: TITANIUM 0x0056CD0F
char CTributeBenefitWnd_guess::CheckReady_guess() {
    char result = g_nameTable_guess.IsTributeAvailable_guess();
    if (result != 0 && flag_189_guess != 0) {
        RefreshFromCandidates_guess();
    }
    return result;
}

// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
unsigned int __cdecl FUN_00576e80_guess();

#define g_benefitLimit_guess EQ_GLOBAL(int, 0x0091D6D4)

// While shown: applies pending rebuilds and, on a timer, refreshes the buttons (Activate/Deactivate,
// 6006/6007) and lists.
// FUNCTION: TITANIUM 0x0056CD38
// @early-stop: budget, structural ndiff=25
void CTributeBenefitWnd_guess::OnProcessFrame_guess() {
    unsigned int now;
    int previous;
    if (((CXWnd*)this)->Show != 0) {
        if (flag_189_guess != 0) {
            RefreshFromCandidates_guess();
        }
        if (flag_1bd_guess != 0) {
            RebuildEntries_guess();
        }
        now = FUN_00576e80_guess();
        if (now > (unsigned int)lastUpdateTime_01c0_guess) {
            UpdateDowngrade_guess();
            if (activate_198_guess != 0) {
                {
                    CXStr text(pStringTable->getString(
                        0x1776 + (g_benefitEnabled_guess != 0), 0));
                    ((TextTarget_guess*)activate_198_guess)->Slot63_guess(
                        (BenefitStr_guess*)&text);
                }
                char enabled = g_nameTable_guess.Check_guess() != 0 &&
                    g_lookupGlobal_guess->state_guess != -1 &&
                    g_characterView_guess->field_e10_guess >= 1;
                if (g_benefitEnabled_guess == 0) {
                    if (enabled && g_lookupManager_guess.Count_guess() > 0) {
                        previous = g_benefitLimit_guess;
                        if (g_lookupManager_guess.Count_guess() < previous) {
                            enabled = 1;
                        } else {
                            enabled = 0;
                        }
                    } else {
                        enabled = 0;
                    }
                }
                ((TextTarget_guess*)activate_198_guess)->flag_5d_guess = enabled;
            }
            lastUpdateTime_01c0_guess = now;
        }
    }
    ((CXWnd*)this)->OnProcessFrame();
}

