// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 44: a hint from compare/tumap.py.
// Key commands: ExecuteCmd and the enable table of the 267 command ids (0x9004A0); ids 0-0xF6 index the
// mappable command names at 0x789908 (AUTORUN, JUMP, FORWARD...). Before it, the per-model camera settings
// list (head 0x905CD4): Node_guess is one model's record, keyed by actor tag, that actor info +0x12C points
// to; NodeView_guess and Lookup_guess are views of it and of the list.
#include <winsock2.h>
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct ModelCameraRecord_guess;

struct Source_guess {
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
    virtual int GetValue_guess();
};

struct Attachment_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Attach_guess(ModelCameraRecord_guess* node_guess, Source_guess* source_guess);
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual int GetCount_guess();
};

struct Player_guess {
    // EXTERNAL: TITANIUM 0x0047C017 Player_guess::SetValue_guess
    void SetValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047C08E Player_guess::GetAnimation_guess
    Attachment_guess* GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x004798D7 Player_guess::GetActorTag_guess
    void GetActorTag_guess(char* output_guess);
};

struct Settings_guess {
    // EXTERNAL: TITANIUM 0x004B6CF7 Settings_guess::GetPESFactor_guess
    float GetPESFactor_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004B6D10 Settings_guess::GetTIFactor_guess
    float GetTIFactor_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004B6D29 Settings_guess::GetFPCOffset_guess
    float GetFPCOffset_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004B6D5F Settings_guess::GetCOFactor_guess
    float GetCOFactor_guess(const char* name_guess);
    // EXTERNAL: TITANIUM 0x004B6D78 Settings_guess::GetZCMinDis_guess
    float GetZCMinDis_guess(const char* name_guess);
};

// EXTERNAL: TITANIUM 0x004B6CB4 GetSettings_guess
Settings_guess* __cdecl GetSettings_guess();
// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* destination_guess, const char* source_guess, int length_guess);

struct ModelCameraRecord_guess {
    ModelCameraRecord_guess* previous_guess;
    ModelCameraRecord_guess* next_guess;
    char name_guess[0x24];
    void** entries_guess;
    int field30_guess;
    char flag_guess;
    float pesFactor_guess;
    float tiFactor_guess;
    float fpcOffset_guess;
    float rOffset_0044_guess;
    float coFactor_guess;
    float zcMinDis_guess;
    int field50_guess;
    int entryCount_guess;
    ModelCameraRecord_guess(const char* name_guess, Source_guess* source_guess, Player_guess* player_guess);
    void Release_guess();
};

struct ModelCameraList_guess {
    ModelCameraRecord_guess* Find_guess(const char* name_guess);
};

struct Interface_guess {
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
    virtual char Slot40_guess();
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();
    virtual void Slot79_guess();
    virtual void Slot80_guess();
    virtual void Slot81_guess();
    virtual void Slot82_guess();
    virtual void Slot83_guess();
    virtual void Slot84_guess();
    virtual void Slot85_guess();
    virtual void Slot86_guess();
    virtual void Slot87_guess();
    virtual void Slot88_guess();
    virtual void Slot89_guess();
    virtual void Slot90_guess();
    virtual void Slot91_guess();
    virtual void Slot92_guess();
    virtual void Slot93_guess();
    virtual void Slot94_guess();
    virtual void Slot95_guess();
    virtual void Slot96_guess();
    virtual void Slot97_guess();
    virtual void Slot98_guess();
    virtual void Slot99_guess();
    virtual void Slot100_guess();
    virtual void Slot101_guess();
    virtual void Slot102_guess();
    virtual void Slot103_guess();
    virtual void Slot104_guess();
    virtual void Slot105_guess();
    virtual void Slot106_guess();
    virtual void Slot107_guess();
    virtual void Slot108_guess();
    virtual void Slot109_guess();
    virtual void Slot110_guess();
    virtual void Slot111_guess();
    virtual void Slot112_guess();
    virtual void Slot113_guess();
    virtual void Slot114_guess();
    virtual float Slot115_guess();
};

struct NodeView_guess {
    char padding_guess[0x44];
    float value_guess;
    void SetROffsetFromActor_guess(Interface_guess* source_guess, int unused_guess);
};

#define g_nodeHead_guess EQ_GLOBAL(ModelCameraRecord_guess*, 0x00905CD4)

// EXTERNAL: TITANIUM 0x0060D0D5 FreeEntry_guess
void __cdecl FreeEntry_guess(void* memory_guess);
// EXTERNAL: TITANIUM 0x0060E07D FreeArray_guess
void __cdecl FreeArray_guess(void* memory_guess);

// Record for actor tag `name` (30 characters kept), pushed onto the list head. Camera factors come from the
// model settings by tag: PESFactor, TIFactor, FPCOffset, COFactor and ZCMinDis (default 3); +0x44 is
// ROffset, which Update_guess takes from the actor instead. +0x34 is set while attaching, probably for the
// newer skeletons (tu_155 and tu_053 test it).
// FUNCTION: TITANIUM 0x00461772
ModelCameraRecord_guess::ModelCameraRecord_guess(const char* name_guess, Source_guess* source_guess, Player_guess* player_guess) {
    rOffset_0044_guess = 0.0f;
    zcMinDis_guess = 3.0f;
    if (g_nodeHead_guess == 0) {
        g_nodeHead_guess = this;
        next_guess = 0;
        previous_guess = 0;
    } else {
        g_nodeHead_guess->previous_guess = this;
        next_guess = g_nodeHead_guess;
        previous_guess = 0;
        g_nodeHead_guess = this;
    }
    steve_strncpy_guess(this->name_guess, name_guess, 0x1e);
    field50_guess = 0;
    player_guess->SetValue_guess(source_guess->GetValue_guess());
    entryCount_guess = player_guess->GetAnimation_guess()->GetCount_guess();
    entries_guess = (void**)malloc(entryCount_guess * 4);
    for (int i_guess = 0; i_guess < entryCount_guess; i_guess++) {
        entries_guess[i_guess] = 0;
    }
    flag_guess = 0;
    player_guess->GetAnimation_guess()->Attach_guess(this, source_guess);
    if (player_guess != 0) {
        char buffer_guess[32];
        player_guess->GetActorTag_guess(buffer_guess);
        pesFactor_guess = GetSettings_guess()->GetPESFactor_guess(buffer_guess);
        tiFactor_guess = GetSettings_guess()->GetTIFactor_guess(buffer_guess);
        fpcOffset_guess = GetSettings_guess()->GetFPCOffset_guess(buffer_guess);
        coFactor_guess = GetSettings_guess()->GetCOFactor_guess(buffer_guess);
        zcMinDis_guess = GetSettings_guess()->GetZCMinDis_guess(buffer_guess);
    }
}

// Unlinks the record from the list and frees its per-entry blocks and their array.
// FUNCTION: TITANIUM 0x004618AB
void ModelCameraRecord_guess::Release_guess() {
    ModelCameraRecord_guess* previous_guess = this->previous_guess;
    ModelCameraRecord_guess* next_guess = this->next_guess;
    if (previous_guess != 0 && next_guess != 0) {
            previous_guess->next_guess = next_guess;
            this->next_guess->previous_guess = this->previous_guess;
    } else if (previous_guess == 0 && next_guess != 0) {
        this->next_guess->previous_guess = 0;
        g_nodeHead_guess = this->next_guess;
    } else if (this->previous_guess != 0) {
        this->previous_guess->next_guess = 0;
    } else {
        this->next_guess = 0;
        this->previous_guess = 0;
        g_nodeHead_guess = 0;
    }

    int index_guess = 0;
    if (this->entryCount_guess > 0) {
        do {
            void* memory_guess = this->entries_guess[index_guess];
            if (memory_guess != 0) {
                FreeEntry_guess(memory_guess);
            }
            this->entries_guess[index_guess] = 0;
            ++index_guess;
        } while (index_guess < this->entryCount_guess);
    }
    FreeArray_guess(this->entries_guess);
}

// Takes ROffset (+0x44) from the actor instance (vslot 115) when vslot 40 says it has one.
// FUNCTION: TITANIUM 0x00461920
void NodeView_guess::SetROffsetFromActor_guess(Interface_guess* source_guess, int unused_guess) {
    if (source_guess != 0) {
        if (source_guess->Slot40_guess()) {
            this->value_guess = source_guess->Slot115_guess();
        }
    }
}

// The camera settings record for actor tag `name` from the per-model list, or 0.
// FUNCTION: TITANIUM 0x0046194C
ModelCameraRecord_guess* ModelCameraList_guess::Find_guess(const char* name_guess) {
    ModelCameraRecord_guess* node_guess = g_nodeHead_guess;
    while (node_guess != 0) {
        if (strcmp(node_guess->name_guess, name_guess) == 0) {
            return node_guess;
        }
        node_guess = node_guess->next_guess;
    }
    return 0;
}

// Languages 2, 3 and 6 (0x923D74 holds the current one).
// FUNCTION: TITANIUM 0x00461979
char __cdecl IsChineseOrJapaneseLanguage_guess(int value_guess) {
    if (value_guess >= 2 && (value_guess <= 3 || value_guess == 6)) {
        return 1;
    }
    return 0;
}

// Window with the virtual slots the command handler uses.
struct Wnd_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void AboutToShow_guess();      // 0x84
    virtual void Deactivate_guess();    // 0x88
    virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess();
    virtual void Slot39_guess(); virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess();
    virtual void Slot43_guess(); virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void SetVisible_guess(bool show_guess, bool flag_guess);    // 0xC0
    virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess(); virtual void Slot52_guess();
    virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess(); virtual void Slot56_guess();
    virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess(); virtual void Slot60_guess();
    virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void SetText_guess(const CXStr& text_guess);                // 0xFC
    virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
    virtual void Slot68_guess();
    virtual struct EditWnd_guess* GetEdit_guess();                      // 0x114
    /*0x04*/ char pad_004_guess[0x58];
    /*0x5C*/ unsigned char show_guess;
    /*0x5D*/ char pad_05D_guess[3];
    // EXTERNAL: TITANIUM 0x0059DD30 Wnd_guess::IsVisible_guess
    bool IsVisible_guess();
    // EXTERNAL: TITANIUM 0x005A1CD0 Wnd_guess::Store_guess
    void Store_guess();
};

struct EditWnd_guess {
    // EXTERNAL: TITANIUM 0x005B90E0 EditWnd_guess::Replace_guess
    void Replace_guess(CXStr text_guess, int flag_guess);
};

// Extra CXStr members, reached through a cast.
struct XStrFns_guess {
    // EXTERNAL: TITANIUM 0x00573250 XStrFns_guess::Mid_guess
    CXStr Mid_guess(int start_guess, int count_guess);
    // EXTERNAL: TITANIUM 0x005722D0 XStrFns_guess::FUN_005722d0_guess
    void FUN_005722d0_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00573F00 XStrFns_guess::Compare_guess
    int Compare_guess(const CXStr& other_guess, int length_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00572060 XStrFns_guess::Append_guess
    void Append_guess(char character_guess);
};

struct ChatWnd_guess : Wnd_guess {
    /*0x060*/ char pad_060_guess[0x100];
    /*0x160*/ Wnd_guess* input_guess;
    // EXTERNAL: TITANIUM 0x004F6F9E ChatWnd_guess::GetWindowTextA_guess
    CXStr GetWindowTextA_guess();
    // EXTERNAL: TITANIUM 0x004F6D57 ChatWnd_guess::HistoryUp_guess
    void HistoryUp_guess();
    // EXTERNAL: TITANIUM 0x004F6DA3 ChatWnd_guess::HistoryDown_guess
    void HistoryDown_guess();
    // EXTERNAL: TITANIUM 0x004F6FCE ChatWnd_guess::ScrollChatWindowUp_guess
    void ScrollChatWindowUp_guess();
    // EXTERNAL: TITANIUM 0x004F7008 ChatWnd_guess::ScrollChatWindowDown_guess
    void ScrollChatWindowDown_guess();
};

struct ChatManager_guess {
    // EXTERNAL: TITANIUM 0x004F288C ChatManager_guess::GetActiveChatWindow_guess
    ChatWnd_guess* GetActiveChatWindow_guess();
};

struct FocusManager_guess {
    // EXTERNAL: TITANIUM 0x005AE150 FocusManager_guess::GetFocus_guess
    Wnd_guess* GetFocus_guess();
};

// The object behind 0x00905D00, with its real virtual base.
struct PcVBase_guess {
    virtual void VBaseSlot0_guess();
    /*0x004*/ char pad_004_guess[0xF8];
    /*0x0FC*/ signed char field_FC_guess;
    /*0x0FD*/ char pad_0FD_guess[0xB];
    /*0x108*/ unsigned char flags_108_guess;
    /*0x109*/ char pad_109_guess[0x43];
    signed char GetFC_guess() { return field_FC_guess; }
    // EXTERNAL: TITANIUM 0x004167E2 PcVBase_guess::GetStatus_guess
    int GetStatus_guess();
};
struct PcHead_guess {
    virtual void HeadSlot0_guess();
    /*0x004*/ int field_4_guess;
};
struct PcMain_guess : PcHead_guess, virtual PcVBase_guess {
    /*0x000C*/ char pad_00C_guess[0xE25 - 0xC];
    /*0x0E25*/ unsigned char field_E25_guess;
    /*0x0E26*/ char pad_E26_guess[0xC280 - 0xE26];
    // EXTERNAL: TITANIUM 0x004BEDCA PcMain_guess::UsePotionBeltItem_guess
    void UsePotionBeltItem_guess(int value_guess);
};
struct PcSecond_guess : virtual PcVBase_guess {
    virtual void SecondSlot0_guess();
    /*0x008*/ char pad_008_guess[0xFC];
    bool Flag4_guess() { return (flags_108_guess & 4) != 0; }
    bool Flag8_guess() { return (flags_108_guess & 8) != 0; }
    bool Flag20_guess() { return (flags_108_guess & 0x20) != 0; }
};
struct Pc_guess : PcMain_guess, PcSecond_guess {
};

struct Camera_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void SetValue_guess(float value_guess);     // 0x14
    virtual void Slot06_guess(); virtual void Slot07_guess(); virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Deactivate_guess(int flag_guess);           // 0x30
};

struct Thing12C_guess {
    /*0x00*/ char pad_00_guess[0x34];
    /*0x34*/ unsigned char field_34_guess;
};
struct ActorInfo_guess {
    /*0x000*/ char pad_000_guess[0x12C];
    /*0x12C*/ Thing12C_guess* field_12C_guess;
    /*0x130*/ char pad_130_guess[0x30];
    /*0x160*/ EQPlayer* field_160_guess;
    /*0x164*/ char pad_164_guess[8];
    /*0x16C*/ int field_16C_guess;
    /*0x170*/ char pad_170_guess[0xE20];
    /*0xF90*/ int field_F90_guess;
};
struct PlayerFns_guess {
    // EXTERNAL: TITANIUM 0x0047BFD0 PlayerFns_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x0047E8E0 PlayerFns_guess::FUN_0047e8e0_guess
    void FUN_0047e8e0_guess();
    // EXTERNAL: TITANIUM 0x00479EA3 PlayerFns_guess::IsGroupInvitePending_guess
    char IsGroupInvitePending_guess();
    // EXTERNAL: TITANIUM 0x00483556 PlayerFns_guess::ChangePosition_guess
    void ChangePosition_guess(int state_guess);
};
struct TargetHistory_guess {
    /*0x00*/ char pad_00_guess[0xF0];
    /*0xF0*/ unsigned int field_F0_guess;
    /*0xF4*/ unsigned int field_F4_guess;
    /*0xF8*/ unsigned int field_F8_guess;
    void SetF0_guess(unsigned int id_guess) { field_F0_guess = id_guess; }
    void SetF4_guess(unsigned int id_guess) { field_F4_guess = id_guess; }
    void SetF8_guess(unsigned int id_guess) { field_F8_guess = id_guess; }
    // EXTERNAL: TITANIUM 0x004C9585 TargetHistory_guess::FindNextTarget_guess
    EQPlayer* FindNextTarget_guess(float range_guess, int a_guess, int b_guess);
};
struct DisplayFns_guess {
    // EXTERNAL: TITANIUM 0x004392DE DisplayFns_guess::SetCameraMode_guess
    void SetCameraMode_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x00440F63 DisplayFns_guess::CycleCamera_guess
    void CycleCamera_guess();
    // EXTERNAL: TITANIUM 0x0043C78F DisplayFns_guess::ChangeVideoMode_guess
    void ChangeVideoMode_guess();
    // EXTERNAL: TITANIUM 0x004382E5 DisplayFns_guess::FUN_004382e5_guess
    void FUN_004382e5_guess();
};
struct EverQuestFns_guess {
    /*0x00000*/ char pad_00000_guess[0x17BB4];
    /*0x17BB4*/ unsigned char field_17BB4_guess;
    // EXTERNAL: TITANIUM 0x00496AEF EverQuestFns_guess::IsChatInputFocused_guess
    char IsChatInputFocused_guess();
    // EXTERNAL: TITANIUM 0x00496AFB EverQuestFns_guess::IsGameInputFocused_guess
    char IsGameInputFocused_guess();
    // EXTERNAL: TITANIUM 0x004AE82A EverQuestFns_guess::FUN_004ae82a_guess
    void FUN_004ae82a_guess(bool value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x00494051 EverQuestFns_guess::SetChatInputFocus_guess
    void SetChatInputFocus_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00494AC5 EverQuestFns_guess::ClickedPlayer
    EQPlayer* ClickedPlayer(int x_guess, int y_guess);
    // EXTERNAL: TITANIUM 0x004A6F0E EverQuestFns_guess::LeftClickedOnPlayer
    void LeftClickedOnPlayer(EQPlayer* player_guess);
    // EXTERNAL: TITANIUM 0x004A7356 EverQuestFns_guess::RightClickedOnPlayer
    void RightClickedOnPlayer(EQPlayer* player_guess);
    // EXTERNAL: TITANIUM 0x0049812E EverQuestFns_guess::ClickSwitchAtScreenPos_guess
    void ClickSwitchAtScreenPos_guess(int x_guess, int y_guess);
    // EXTERNAL: TITANIUM 0x0049C800 EverQuestFns_guess::Who_guess
    void Who_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x0049D3CC EverQuestFns_guess::Invite_guess
    void Invite_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0049D7B6 EverQuestFns_guess::AcceptGroupInvite_guess
    void AcceptGroupInvite_guess();
    // EXTERNAL: TITANIUM 0x0049D8BD EverQuestFns_guess::Disband_guess
    void Disband_guess();
    // EXTERNAL: TITANIUM 0x0049DDA6 EverQuestFns_guess::PrepareToCamp_guess
    void PrepareToCamp_guess();
    // EXTERNAL: TITANIUM 0x0049DCFA EverQuestFns_guess::ToggleSit_guess
    void ToggleSit_guess();
    // EXTERNAL: TITANIUM 0x004AE514 EverQuestFns_guess::FUN_004ae514_guess
    void FUN_004ae514_guess(int value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004AE55F EverQuestFns_guess::FUN_004ae55f_guess
    void FUN_004ae55f_guess(float value_guess, const char* section_guess, const char* key_guess);
    // EXTERNAL: TITANIUM 0x004980D2 EverQuestFns_guess::ToggleChatInputFocus_guess
    void ToggleChatInputFocus_guess();
};
struct Wnd850B9C_guess {
    /*0x000*/ char pad_000_guess[0x1E2];
    /*0x1E2*/ unsigned char field_1E2_guess;
    // EXTERNAL: TITANIUM 0x004F1A03 Wnd850B9C_guess::SelectCharacter_guess
    void SelectCharacter_guess(int a_guess, int b_guess);
    // EXTERNAL: TITANIUM 0x004F18FF Wnd850B9C_guess::LeaveExplorationMode_guess
    void LeaveExplorationMode_guess();
    // EXTERNAL: TITANIUM 0x004F0E21 Wnd850B9C_guess::Quit_guess
    void Quit_guess();
    // EXTERNAL: TITANIUM 0x004F14F0 Wnd850B9C_guess::FUN_004f14f0_guess
    void FUN_004f14f0_guess();
};
struct Wnd850C20_guess {
    // EXTERNAL: TITANIUM 0x004F01D0 Wnd850C20_guess::OnNextButton_guess
    void OnNextButton_guess();
    // EXTERNAL: TITANIUM 0x004EE978 Wnd850C20_guess::OnBackButton_guess
    void OnBackButton_guess();
};
struct Wnd850C98_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x00543ED1 Wnd850C98_guess::GetPetitionerName_guess
    char* GetPetitionerName_guess();
    // EXTERNAL: TITANIUM 0x005440BD Wnd850C98_guess::UndoCheckout_guess
    void UndoCheckout_guess();
};
struct HotWnd_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x0051415B HotWnd_guess::DoHotButton
    void DoHotButton(int slot_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x00513B6B HotWnd_guess::UpdatePageLabel_guess
    void UpdatePageLabel_guess();
};
struct Wnd850C2C_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x004ECB56 Wnd850C2C_guess::FUN_004ecb56_guess
    void FUN_004ecb56_guess(int index_guess);
};
struct Wnd850C48_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x004F8AAB Wnd850C48_guess::UseAbilitySlot_guess
    void UseAbilitySlot_guess(int index_guess);
};
struct Wnd850C44_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x004D22F2 Wnd850C44_guess::ShowPage_guess
    void ShowPage_guess(int page_guess);
    // EXTERNAL: TITANIUM 0x004D25E1 Wnd850C44_guess::GetCurrentPage_guess
    int GetCurrentPage_guess();
};
struct Wnd850C90_guess : Wnd_guess {
    /*0x060*/ char pad_060_guess[0xFC];
    /*0x15C*/ unsigned char field_15C_guess;
    // EXTERNAL: TITANIUM 0x00505205 Wnd850C90_guess::SetInputCommand_guess
    void SetInputCommand_guess(int value_guess);
};
struct Wnd9919C4_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x00502F3E Wnd9919C4_guess::StartFind_guess
    void StartFind_guess();
    // EXTERNAL: TITANIUM 0x00502F2F Wnd9919C4_guess::FUN_00502f2f_guess
    char FUN_00502f2f_guess();
    // EXTERNAL: TITANIUM 0x0050300F Wnd9919C4_guess::FUN_0050300f_guess
    void FUN_0050300f_guess();
    // EXTERNAL: TITANIUM 0x00502F37 Wnd9919C4_guess::FUN_00502f37_guess
    int FUN_00502f37_guess();
};
struct Wnd9918C0_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x004FE347 Wnd9918C0_guess::FUN_004fe347_guess
    void FUN_004fe347_guess();
};
struct Wnd9928A8_guess : Wnd_guess {
    // EXTERNAL: TITANIUM 0x00561310 Wnd9928A8_guess::ShowHelpPage_guess
    void ShowHelpPage_guess(const char* page_guess);
    // EXTERNAL: TITANIUM 0x005612E7 Wnd9928A8_guess::ShowPage_guess
    void ShowPage_guess(int value_guess);
};
struct Obj9928E0_guess {
    // EXTERNAL: TITANIUM 0x00564E7E Obj9928E0_guess::FUN_00564e7e_guess
    char FUN_00564e7e_guess(int value_guess, int flag_guess);
};
struct Obj923770_guess {
    /*0x00*/ HWND window_guess;
    /*0x04*/ int field_04_guess;
    /*0x08*/ int left_guess;
    /*0x0C*/ int top_guess;
    /*0x10*/ int right_guess;
    /*0x14*/ int bottom_guess;
    // EXTERNAL: TITANIUM 0x004A2F7A Obj923770_guess::SetAutoAttack_guess
    void SetAutoAttack_guess(bool value_guess);
};
struct Obj99E38C_guess {
    /*0x00*/ char pad_00_guess[4];
    /*0x04*/ unsigned char field_4_guess;
};
struct Obj850CB8_guess {
    // EXTERNAL: TITANIUM 0x0051A69B Obj850CB8_guess::OpenAllBags_guess
    void OpenAllBags_guess();
    // EXTERNAL: TITANIUM 0x0051A6E6 Obj850CB8_guess::CloseAllBags_guess
    void CloseAllBags_guess();
};
struct Obj9232F0_guess {
    // EXTERNAL: TITANIUM 0x00408583 Obj9232F0_guess::FUN_00408583_guess
    void FUN_00408583_guess();
};
struct Obj850350_guess {
    // EXTERNAL: TITANIUM 0x00434495 Obj850350_guess::IsTributeAvailable_guess
    char IsTributeAvailable_guess();
};

// EXTERNAL: TITANIUM 0x004C94AE GetTargetState_guess
TargetHistory_guess* __cdecl GetTargetState_guess();
// EXTERNAL: TITANIUM 0x00401B28 FindSpawn_guess
EQPlayer* __cdecl FindSpawn_guess(unsigned int id_guess);
// EXTERNAL: TITANIUM 0x00466A73 do_consider_guess
void __cdecl do_consider_guess(int value_guess, const char* text_guess);
// EXTERNAL: TITANIUM 0x00476336 do_hail_guess
void __cdecl do_hail_guess(EQPlayer* player_guess, int value_guess);
// EXTERNAL: TITANIUM 0x0046A75A do_stopcast_guess
void __cdecl do_stopcast_guess(EQPlayer* player_guess, int value_guess);
// EXTERNAL: TITANIUM 0x00467B95 CycleNamesInTellList_guess
void __cdecl CycleNamesInTellList_guess(int GetLabelText_guess);
// EXTERNAL: TITANIUM 0x00466244 allowslashcommand_guess
int __cdecl allowslashcommand_guess();
// EXTERNAL: TITANIUM 0x004CE72D ReinitMouse_guess
void __cdecl ReinitMouse_guess();
// EXTERNAL: TITANIUM 0x0060BEB0 WriteIniString_guess
void __cdecl WriteIniString_guess(const char* section_guess, const char* key_guess, const char* value_guess, const char* file_guess);
// EXTERNAL: TITANIUM 0x00574110 Log_guess
void __cdecl Log_guess(const char* format_guess, ...);

typedef char NameSlot_guess[0x40];

#define g_commandEnabled_guess EQ_ARRAY(unsigned char, 0x009004A0)
#define g_commandKeyDown_guess EQ_ARRAY(int, 0x00925520)
#define g_pc_guess EQ_GLOBAL(Pc_guess*, 0x00905D00)
#define g_everQuest_guess EQ_GLOBAL(EverQuestFns_guess*, 0x00988DF0)
#define g_display_guess EQ_GLOBAL(DisplayFns_guess*, 0x00905D24)
#define g_controlled_guess EQ_GLOBAL(EQPlayer*, 0x00905CF8)
#define g_spawnList_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)
#define pinstCChatManager_guess EQ_GLOBAL(ChatManager_guess*, 0x009917E4)
#define pinstCXWndManager_guess EQ_GLOBAL(FocusManager_guess*, 0x0099D3EC)
#define g_tellNames_guess EQ_ARRAY(NameSlot_guess, 0x00925920)
#define g_tellIndex_guess EQ_GLOBAL(int, 0x009265A0)
#define g_groupNames_guess EQ_ARRAY(NameSlot_guess, 0x0090424D)
#define g_groupPlayers_guess EQ_ARRAY(EQPlayer*, 0x00904390)
#define g_hotWnds_guess EQ_ARRAY(HotWnd_guess*, 0x00991AE4)
#define g_hotPages_guess EQ_ARRAY(unsigned char, 0x00983B75)
#define g_cameras_guess EQ_ARRAY(Camera_guess*, 0x009254FC)
#define g_cameraMode_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_mainWindow_guess EQ_GLOBAL(Obj923770_guess, 0x00923770)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)

// Name of command `index` (0-0xF6 only; the table has no names for the internal ids above).
// FUNCTION: TITANIUM 0x00461992
char* __cdecl GetMappableCommandName_guess(int index_guess) {
    return EQ_ARRAY(char*, 0x00789908)[index_guess];
}

// The enable table (0x9004A0, 0x10B entries) that ExecuteCmd checks first.
// FUNCTION: TITANIUM 0x0046199E
void __cdecl SetCommandEnabled_guess(int index_guess, unsigned char value_guess) {
    EQ_ARRAY(unsigned char, 0x009004A0)[index_guess] = value_guess;
}

// Sets the enable flag of all 267 key commands (0x009004A0) to `value`.
// FUNCTION: TITANIUM 0x004619AD
void __cdecl SetAllCommandsEnabled_guess(unsigned char value_guess) {
    unsigned char* p_guess = EQ_ARRAY(unsigned char, 0x009004A0);
    int count_guess = 0x10B;
    while (count_guess != 0) {
        *p_guess++ = value_guess;
        --count_guess;
    }
}

#define pinstCFacePick_guess EQ_GLOBAL(Wnd_guess*, 0x00850BA0)
#define pinstCPetInfoWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BAC)
#define pinstCSkillsWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BB4)
#define pinstCFriendsWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BC0)
#define pinstCBandolierWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BC8)
#define pinstCPotionBeltWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BCC)
#define pinstCAAWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BD0)
#define pinstCMailWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BE4)
#define pinstCMailCompositionWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BE8)
#define pinstCRaidWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BF0)
#define pinstCMapViewWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850BFC)
#define pinstCTargetWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C08)
#define pinstCPlayerWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C10)
#define pinstCOptionsWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C14)
#define pinstCBuffWindowNORMAL_guess EQ_GLOBAL(Wnd_guess*, 0x00850C18)
#define pinstCBuffWindowSHORT_guess EQ_GLOBAL(Wnd_guess*, 0x00850C1C)
#define pinstCCharacterCreation_guess EQ_GLOBAL(Wnd850C20_guess*, 0x00850C20)
#define pinstCCastSpellWnd_guess EQ_GLOBAL(Wnd850C2C_guess*, 0x00850C2C)
#define pinstCSpellBookWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C30)
#define pinstCInventoryWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C34)
#define pinstCActionsWnd_guess EQ_GLOBAL(Wnd850C44_guess*, 0x00850C44)
#define pinstCCombatAbilityWnd_guess EQ_GLOBAL(Wnd850C48_guess*, 0x00850C48)
#define pinstCSelectorWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C54)
#define pinstCBazaarWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C58)
#define pinstCBazaarSearchWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C5C)
#define pinstCVideoModesWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C78)
#define pinstCCompassWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850C88)
#define pinstCGemsGameWnd_guess EQ_GLOBAL(Wnd850C90_guess*, 0x00850C90)
#define pinstCPetitionQWnd_guess EQ_GLOBAL(Wnd850C98_guess*, 0x00850C98)
#define pinstCJournalNPCWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00850CA4)
#define pinstCInvSlotMgr_guess EQ_GLOBAL(Obj850CB8_guess*, 0x00850CB8)
#define pinstCVoiceMacroWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00985D94)
#define pinstCAdventureRequestWnd_guess EQ_GLOBAL(int, 0x009913D4)
#define pinstCDynamicZoneWnd_guess EQ_GLOBAL(Wnd9918C0_guess*, 0x009918C0)
#define pinstCFindLocationWnd_guess EQ_GLOBAL(Wnd9919C4_guess*, 0x009919C4)
#define pinstCGroupSearchWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00991A58)
#define pinstCGroupWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00991A74)
#define pinstCGuildManagementWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00991AAC)
#define pinstCLeadershipWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00991C24)
#define pinstCPvPStatsWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00991EB0)
#define pinstCTaskWnd_guess EQ_GLOBAL(Wnd_guess*, 0x00992858)
#define pinstCTicketWnd_guess EQ_GLOBAL(Wnd9928A8_guess*, 0x009928A8)
#define pinstCTipWndCONTEXT_guess EQ_GLOBAL(Obj9928E0_guess*, 0x009928E0)
#define pinstCTitleWnd_guess EQ_GLOBAL(Wnd_guess*, 0x009928FC)
#define pinstCTributeBenefitWnd_guess EQ_GLOBAL(Wnd_guess*, 0x0099298C)

// Runs command `command_guess` for a key press (`keyDown_guess`) or release; false for a disabled or unknown
// id. `allowed_guess` is off while 0x95A174 is set, PC state +0xFC is above 2 or the player has no control of
// itself (StandState 0x66), and forced on by 0x923798 or 0x923884 (running without a server). Held keys
// (movement, pitch, camera moves)
// are states in 0x925520, indexed by id.
// Ids: 0x19-0x1D PARTY1-5 (again: that member's target), 0x23-0x4A HOT1_1..HOT4_10, 0x4B-0x72
// HOTPAGE1_1..4_10, 0x73-0x7B CAST1-9, 0xC0-0xC5 the six cameras, 0xCC-0xD3 CMD_OPENING_ATTACK1-8,
// 0xDC-0xDF POTION_SLOT_1-4. Ids from 0xF7 have no name: 0xFD logs CMD_EXITGAME, 0x109/0x10A drive the
// creation window 0x850C20. Target memory (0x4C94AE object): +0xF0 previous target (TOGGLETWOTARGETS),
// +0xF4 the target before TOGGLETARGET picked self, +0xF8 the last NPC warned about.
// AUTOPRIM: refused with the spellbook open (0x850C30), while not standing or on self; does nothing
// while we deal with a merchant (0x905D10, also tu_027's tribute master), banker (0x905D14) or trainer
// (0x905D1C).
// Up to level 10, a target 3+ levels higher gets hint 0x20 once, and no attack if it shows.
// TARGETNPC skips body types 11, 60, 65 and 67 and picks a horse's rider.
// CLIP_IN/OUT step ClipPlane 0-20 and scale FogScale with it.
// CYCLEREPLY/_BACK rewrite a typed tell or reply with the next name in the tell list (0x925920). For a
// plain name after the reply word the original passes the reply word as the format string, so the line
// becomes just that word ("argument order as in the original"). Kept.
// FUNCTION: TITANIUM 0x004619CD
// @early-stop: tiebreak, structural ndiff=799
bool __cdecl ExecuteCmd(unsigned int command_guess, bool keyDown_guess, int data_guess) {
    char buffer_guess[256];
    int allowed_guess = 1;

    // Key-map commands (0x10B ids; their names are the table at 0x00789908). Disabled commands do nothing.
    // Game actions also need `allowed_guess`: off while 0x0095A174 is set, in character state above 2 (+0xFC)
    // or without control (StandState 0x66); always on when 0x00923798 or 0x00923884 is set (no server).
    if (!g_commandEnabled_guess[command_guess]) {
        return false;
    }
    if (EQ_GLOBAL(char, 0x0095A174)) {
        allowed_guess = 0;
    }
    // StandState 0x66 is "You do not have control of yourself right now." (string 12368), not feign death.
    if (g_pc_guess->GetFC_guess() > 2 || (pinstLocalPlayer != 0 && pinstLocalPlayer->StandState == 'f')) {
        allowed_guess = 0;
    }
    if (EQ_GLOBAL(char, 0x00923798) || EQ_GLOBAL(int, 0x00923884) != 0) {
        allowed_guess = 1;
    }

    switch (command_guess) {
    // 0x105-0x10A are past the 0xF7 names of the command table (0x00789908): four actions on window
    // 0x00850B9C, then two on the character-creation window (0x00850C20).
    case 0x106:
        if (keyDown_guess && EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C) != 0 &&
            !EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->field_1E2_guess) {
            EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->SelectCharacter_guess(0x3e9, 1);
        }
        break;
    case 0x105:
        if (keyDown_guess && EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C) != 0 &&
            !EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->field_1E2_guess) {
            EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->SelectCharacter_guess(0x3e8, 1);
        }
        break;
    case 0x107:
        if (keyDown_guess && EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C) != 0) {
            if (EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->field_1E2_guess) {
                EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->LeaveExplorationMode_guess();
            } else {
                EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->Quit_guess();
            }
        }
        break;
    case 0x108:
        if (keyDown_guess && EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C) != 0) {
            EQ_GLOBAL(Wnd850B9C_guess*, 0x00850B9C)->FUN_004f14f0_guess();
        }
        break;
    case 0x109:
        if (keyDown_guess && pinstCCharacterCreation_guess != 0) {
            pinstCCharacterCreation_guess->OnNextButton_guess();
        }
        break;
    case 0x10a:
        if (keyDown_guess && pinstCCharacterCreation_guess != 0) {
            pinstCCharacterCreation_guess->OnBackButton_guess();
        }
        break;
    // TOGGLETARGET: from self back to the target remembered at +0xF4, else remember the target and take self.
    // +0xF0 always keeps the previous target for TOGGLETWOTARGETS (0xBE), which swaps with it.
    case 0x80:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            if (pinstTarget == pinstLocalPlayer) {
                EQPlayer* spawn_guess = FindSpawn_guess(GetTargetState_guess()->field_F4_guess);
                if (spawn_guess != 0) {
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                    pinstTarget = spawn_guess;
                }
            } else {
                if (pinstTarget != 0) {
                    GetTargetState_guess()->SetF4_guess(pinstTarget->SpawnID);
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                }
                pinstTarget = pinstLocalPlayer;
            }
        }
        break;
    case 0xbe:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            unsigned int id_guess = GetTargetState_guess()->field_F0_guess;
            if (pinstTarget != 0) {
                GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
            }
            if (id_guess != 0) {
                EQPlayer* spawn_guess = FindSpawn_guess(id_guess);
                if (spawn_guess != 0) {
                    pinstTarget = spawn_guess;
                }
            }
        }
        break;
    // TOGGLE_CONTEXTMENUS, saved as [Main] ContextMenus. Then the camera keys 0xC0-0xC5: first person,
    // overhead, chase, user 1, user 2, tether.
    case 0xbf:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            EQ_GLOBAL(bool, 0x009254ED) = !EQ_GLOBAL(bool, 0x009254ED);
            g_everQuest_guess->FUN_004ae82a_guess(EQ_GLOBAL(bool, 0x009254ED), "Main", "ContextMenus");
        }
        break;
    case 0xc0:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(0);
        }
        break;
    case 0xc1:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(1);
        }
        break;
    case 0xc2:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(2);
        }
        break;
    case 0xc3:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(3);
        }
        break;
    case 0xc4:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(4);
        }
        break;
    case 0xc5:
        if (allowed_guess && keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            g_display_guess->SetCameraMode_guess(5);
        }
        break;
    // Chat shortcuts fill the active chat line: TELL (0xF) "/tell " plus the name selected in window
    // 0x00850C98 if any, REPLY (0x7C), CYCLEREPLY / CYCLEREPLY_BACK (0x7D/0x7E) walk the tell list (12365
    // when it is empty), RTARGET (0xA6); CMDMODE_SAY (0x94) types "'", CMDMODE_EMOTE (0x95) ":", 0xF9 ";" and
    // 0xFA "/".
    case 0xf:
        if (!g_everQuest_guess->IsChatInputFocused_guess() && keyDown_guess && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                char* name_guess;
                if (pinstCPetitionQWnd_guess != 0 &&
                    (name_guess = pinstCPetitionQWnd_guess->GetPetitionerName_guess()) != 0) {
                    sprintf(buffer_guess, "%s %s ", pStringTable->getString(0x3696, 0), name_guess);
                } else {
                    sprintf(buffer_guess, "%s ", pStringTable->getString(0x3696, 0));
                }
                chat_guess->input_guess->SetText_guess(buffer_guess);
                ((CXWnd*)chat_guess->input_guess)->SetFocus();
                g_everQuest_guess->SetChatInputFocus_guess(0);
            }
        }
        break;
    // REPLY: "/tell <last teller> ", or string 12364 when nobody has sent a tell. A stored name starting with
    // ';' or '[' keeps that character in front of the command word instead of the slash.
    case 0x7c:
        if (!g_everQuest_guess->IsChatInputFocused_guess() && keyDown_guess && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                char* name_guess = g_tellNames_guess[g_tellIndex_guess];
                if (name_guess[0] == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x304c, 0));
                } else {
                    if (name_guess[0] == ';' || name_guess[0] == '[') {
                        sprintf(buffer_guess, "%c%s %s ", name_guess[0], pStringTable->getString(0x3696, 0) + 1,
                                name_guess + 1);
                    } else {
                        sprintf(buffer_guess, "%s %s ", pStringTable->getString(0x3696, 0), name_guess);
                    }
                    chat_guess->input_guess->SetText_guess(buffer_guess);
                    ((CXWnd*)chat_guess->input_guess)->SetFocus();
                    g_everQuest_guess->SetChatInputFocus_guess(0);
                }
            }
        }
        break;
    case 0x7d:
    case 0x7e:
        if (allowed_guess && keyDown_guess && g_everQuest_guess->IsChatInputFocused_guess() && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                buffer_guess[0] = 0;
                CXStr text_guess = ((XStrFns_guess*)&chat_guess->GetWindowTextA_guess())->Mid_guess(1, 0xffff);
                ((XStrFns_guess*)&text_guess)->FUN_005722d0_guess(0);
                char* tell_guess = pStringTable->getString(0x3696, 0) + 1;
                int tellLength_guess = strlen(tell_guess);
                char* reply_guess = pStringTable->getString(0x377a, 0) + 1;
                int replyLength_guess = strlen(reply_guess);
                if (((XStrFns_guess*)&text_guess)->Compare_guess(reply_guess, replyLength_guess, 0) == 0) {
                    CycleNamesInTellList_guess(command_guess != 0x7d);
                    char* name_guess = g_tellNames_guess[g_tellIndex_guess];
                    if (name_guess[0] == 0) {
                        pEverQuest->dsp_chat(pStringTable->getString(0x304d, 0));
                        break;
                    }
                    if (name_guess[0] == ';' || name_guess[0] == '[') {
                        sprintf(buffer_guess, "/%s %s", reply_guess, name_guess + 1);
                    } else {
                        // argument order as in the original
                        // Original bug: the reply word is passed as the format, so the line becomes just that
                        // word. The ';' / '[' branch above has the arguments in the right order.
                        sprintf(buffer_guess, reply_guess, "/%s %s", name_guess);
                    }
                } else if (((XStrFns_guess*)&text_guess)->Compare_guess(tell_guess, tellLength_guess, 0) == 0) {
                    CycleNamesInTellList_guess(command_guess != 0x7d);
                    char* name_guess = g_tellNames_guess[g_tellIndex_guess];
                    if (name_guess[0] == 0) {
                        pEverQuest->dsp_chat(pStringTable->getString(0x304d, 0));
                        break;
                    }
                    if (name_guess[0] == ';' || name_guess[0] == '[') {
                        sprintf(buffer_guess, "%c%s %s ", name_guess[0], tell_guess, name_guess + 1);
                    } else {
                        sprintf(buffer_guess, "/%s %s ", tell_guess, name_guess);
                    }
                }
                if (buffer_guess[0] != 0) {
                    chat_guess->input_guess->SetText_guess(buffer_guess);
                    ((CXWnd*)chat_guess->input_guess)->SetFocus();
                    g_everQuest_guess->SetChatInputFocus_guess(0);
                }
            }
        }
        break;
    // RTARGET: "/rtarget <name>" from the same tell list.
    case 0xa6:
        if (!g_everQuest_guess->IsChatInputFocused_guess() && keyDown_guess && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                char* name_guess = g_tellNames_guess[g_tellIndex_guess];
                if (name_guess[0] == 0) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x304d, 0));
                } else {
                    if (name_guess[0] == ';' || name_guess[0] == '[') {
                        name_guess++;
                    }
                    sprintf(buffer_guess, "%s %s", pStringTable->getString(0x377a, 0), name_guess);
                    chat_guess->input_guess->SetText_guess(buffer_guess);
                    ((CXWnd*)chat_guess->input_guess)->SetFocus();
                    g_everQuest_guess->SetChatInputFocus_guess(0);
                }
            }
        }
        break;
    // CONSIDER the current target.
    case 0xb:
        if (allowed_guess && keyDown_guess) {
            do_consider_guess(0, g_emptyText_guess);
        }
        break;
    // DUCK: toggles standing ('d' = 100) and ducking ('o' = 111); not for races 142 and 143, while 0x0047BFD0
    // is true or 0x00923854 is set. SIT_STAND is command 0x8A.
    case 0xc:
        if (allowed_guess && keyDown_guess) {
            if (g_controlled_guess->Race != 0x8f && g_controlled_guess->Race != 0x8e &&
                !((PlayerFns_guess*)g_controlled_guess)->IsHorseRace_guess() && EQ_GLOBAL(int, 0x00923854) == 0) {
                if (g_controlled_guess->StandState == 'd') {
                    ((PlayerFns_guess*)g_controlled_guess)->ChangePosition_guess('o');
                } else if (g_controlled_guess->StandState == 'o') {
                    ((PlayerFns_guess*)g_controlled_guess)->ChangePosition_guess('d');
                }
            }
        }
        break;
    // INVENTORY window toggle; not in view mode 3 (see FULLSCREEN, 0x17) or while 0x009248D0 counts a pending
    // request.
    case 0xe:
        if (allowed_guess && EQ_GLOBAL(int, 0x00850508) != 3 && keyDown_guess && !EQ_GLOBAL(char, 0x00923876) &&
            !EQ_GLOBAL(char, 0x00923877) && EQ_GLOBAL(int, 0x009248D0) == 0 &&
            pinstCInventoryWnd_guess != 0) {
            if (!pinstCInventoryWnd_guess->IsVisible_guess()) {
                pinstCInventoryWnd_guess->AboutToShow_guess();
            } else {
                pinstCInventoryWnd_guess->Deactivate_guess();
            }
        }
        break;
    // Targets the spawn under the screen centre (then RightClickedOnPlayer when it is an NPC or there was no
    // target), else clicks the world there.
    case 0x10:
        if (allowed_guess && !g_everQuest_guess->IsChatInputFocused_guess() && keyDown_guess &&
            g_everQuest_guess->IsGameInputFocused_guess()) {
            int x_guess = (g_mainWindow_guess.left_guess + g_mainWindow_guess.right_guess) >> 1;
            int y_guess = (g_mainWindow_guess.top_guess + g_mainWindow_guess.bottom_guess) >> 1;
            EQPlayer* spawn_guess = g_everQuest_guess->ClickedPlayer(x_guess, y_guess);
            if (spawn_guess != 0) {
                g_everQuest_guess->LeftClickedOnPlayer(spawn_guess);
                if (pinstTarget == 0 || pinstTarget->Type == 1) {
                    g_everQuest_guess->RightClickedOnPlayer(spawn_guess);
                }
            } else {
                g_everQuest_guess->ClickSwitchAtScreenPos_guess(x_guess, y_guess);
            }
        }
        break;
    case 0x94:
    case 0x95:
    case 0xf9:
    case 0xfa:
        if (!g_everQuest_guess->IsChatInputFocused_guess() && keyDown_guess && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                char prefix_guess[4];
                switch (command_guess) {
                case 0x94:
                    strcpy(prefix_guess, EQ_ARRAY(char, 0x0064504C));
                    break;
                case 0x95:
                    strcpy(prefix_guess, EQ_ARRAY(char, 0x00641584));
                    break;
                case 0xf9:
                    strcpy(prefix_guess, EQ_ARRAY(char, 0x00645050));
                    break;
                case 0xfa:
                    strcpy(prefix_guess, EQ_ARRAY(char, 0x00645054));
                    break;
                }
                chat_guess->input_guess->SetText_guess(prefix_guess);
                ((CXWnd*)chat_guess->input_guess)->SetFocus();
                g_everQuest_guess->SetChatInputFocus_guess(0);
            }
        }
        break;
    // HAIL.
    case 0xd:
        if (keyDown_guess) {
            do_hail_guess(pinstLocalPlayer, 0);
        }
        break;
    // TARGETME: self, or our pet when already on ourselves; PARTY1-5 (0x19-0x1D) target a group member, and a
    // second press the spawn whose id is at the member's actor +0x16C. None while a request is pending.
    case 0x18:
        if (allowed_guess && keyDown_guess && EQ_GLOBAL(int, 0x009248D4) == 0 && EQ_GLOBAL(int, 0x009248D0) == 0) {
            if (pinstTarget == pinstLocalPlayer) {
                EQPlayer* spawn_guess = g_spawnList_guess;
                while (spawn_guess != 0) {
                    if (spawn_guess->field_1B3 == 0 && spawn_guess->MasterID == pinstLocalPlayer->SpawnID) {
                        break;
                    }
                    spawn_guess = spawn_guess->pNext;
                }
                if (spawn_guess != 0) {
                    if (pinstTarget != 0) {
                        GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                    }
                    pinstTarget = spawn_guess;
                }
            } else {
                if (pinstTarget != 0) {
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                }
                pinstTarget = pinstLocalPlayer;
                ((ActorInfo_guess*)pinstLocalPlayer->pActorInfo)->field_F90_guess = -1;
            }
        }
        break;
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
        if (allowed_guess && keyDown_guess && EQ_GLOBAL(int, 0x009248D4) == 0 && EQ_GLOBAL(int, 0x009248D0) == 0) {
            int index_guess = command_guess - 0x19;
            if (g_groupNames_guess[index_guess][0] != 0) {
                ((ActorInfo_guess*)pinstLocalPlayer->pActorInfo)->field_F90_guess = index_guess;
                EQPlayer* member_guess = g_groupPlayers_guess[index_guess];
                EQPlayer* old_guess = pinstTarget;
                if (member_guess != 0) {
                    if (old_guess != 0) {
                        GetTargetState_guess()->SetF0_guess(old_guess->SpawnID);
                    }
                    pinstTarget = member_guess;
                    if (old_guess == member_guess) {
                        ActorInfo_guess* info_guess = (ActorInfo_guess*)member_guess->pActorInfo;
                        if (info_guess != 0) {
                            int id_guess = info_guess->field_16C_guess;
                            if (id_guess != -1) {
                                EQPlayer* spawn_guess = FindSpawn_guess(id_guess);
                                if (spawn_guess != 0) {
                                    pinstTarget = spawn_guess;
                                }
                            }
                        }
                    }
                } else {
                    pinstTarget = 0;
                }
            }
        }
        break;
    // Hot buttons: 0x23-0x4A press button n % 10 on hotbar n / 10 (n = command - 0x23), 0x4B-0x72 switch a
    // bar's page, 0x73-0x7B the nine spell gems (window 0x00850C2C); 0xCC-0xD3 use ability slot n of the
    // window at 0x00850C48 and 0xDC-0xDF use potion-belt slot n on the character.
    case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c:
    case 0x2d: case 0x2e: case 0x2f: case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36:
    case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: case 0x40:
    case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4a:
        if (allowed_guess && keyDown_guess) {
            if (g_hotWnds_guess[(command_guess - 0x23) / 10] != 0) {
                g_hotWnds_guess[(command_guess - 0x23) / 10]->DoHotButton((command_guess - 0x23) % 10, 0);
            }
        }
        break;
    case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f: case 0x50: case 0x51: case 0x52: case 0x53: case 0x54:
    case 0x55: case 0x56: case 0x57: case 0x58: case 0x59: case 0x5a: case 0x5b: case 0x5c: case 0x5d: case 0x5e:
    case 0x5f: case 0x60: case 0x61: case 0x62: case 0x63: case 0x64: case 0x65: case 0x66: case 0x67: case 0x68:
    case 0x69: case 0x6a: case 0x6b: case 0x6c: case 0x6d: case 0x6e: case 0x6f: case 0x70: case 0x71: case 0x72:
        if (allowed_guess && keyDown_guess) {
            g_hotPages_guess[(command_guess - 0x4b) / 10] = (command_guess - 0x4b) % 10;
            HotWnd_guess* hot_guess = g_hotWnds_guess[(command_guess - 0x4b) / 10];
            if (hot_guess != 0) {
                hot_guess->UpdatePageLabel_guess();
            }
        }
        break;
    case 0x73: case 0x74: case 0x75: case 0x76: case 0x77: case 0x78: case 0x79: case 0x7a: case 0x7b:
        if (allowed_guess && keyDown_guess && pinstCCastSpellWnd_guess != 0) {
            ((PlayerFns_guess*)pinstLocalPlayer)->FUN_0047e8e0_guess();
            pinstCCastSpellWnd_guess->FUN_004ecb56_guess(command_guess - 0x73);
        }
        break;
    // CMD_STOP_CAST. Then CMD_OPENING_ATTACK1-8 (0xCC-0xD3, combat ability window 0x00850C48) and
    // POTION_SLOT_1-4.
    case 0xd9:
        do_stopcast_guess(pinstLocalPlayer, 0);
        break;
    case 0xcc: case 0xcd: case 0xce: case 0xcf: case 0xd0: case 0xd1: case 0xd2: case 0xd3:
        if (allowed_guess && keyDown_guess && pinstCCombatAbilityWnd_guess != 0) {
            pinstCCombatAbilityWnd_guess->UseAbilitySlot_guess(command_guess - 0xcc);
        }
        break;
    case 0xdc: case 0xdd: case 0xde: case 0xdf:
        if (allowed_guess && keyDown_guess) {
            g_pc_guess->UsePotionBeltItem_guess(command_guess - 0xdc);
        }
        break;
    case 0xe0:
        if (allowed_guess && keyDown_guess && pinstCPotionBeltWnd_guess != 0) {
            if (!pinstCPotionBeltWnd_guess->IsVisible_guess()) {
                pinstCPotionBeltWnd_guess->AboutToShow_guess();
            } else {
                pinstCPotionBeltWnd_guess->Deactivate_guess();
            }
            pinstCPotionBeltWnd_guess->Store_guess();
        }
        break;
    case 0xe1:
        if (allowed_guess && keyDown_guess && pinstCBandolierWnd_guess != 0) {
            if (!pinstCBandolierWnd_guess->IsVisible_guess()) {
                pinstCBandolierWnd_guess->AboutToShow_guess();
            } else {
                pinstCBandolierWnd_guess->Deactivate_guess();
            }
        }
        break;
    case 0xe4:
        if (allowed_guess && keyDown_guess && pinstCSkillsWnd_guess != 0) {
            if (!pinstCSkillsWnd_guess->IsVisible_guess()) {
                pinstCSkillsWnd_guess->AboutToShow_guess();
            } else {
                pinstCSkillsWnd_guess->Deactivate_guess();
            }
        }
        break;
    case 0xd4:
        if (allowed_guess && keyDown_guess && pinstCCombatAbilityWnd_guess != 0) {
            if (pinstCCombatAbilityWnd_guess->show_guess == 0) {
                pinstCCombatAbilityWnd_guess->SetVisible_guess(true, true);
            } else {
                pinstCCombatAbilityWnd_guess->SetVisible_guess(false, true);
            }
            pinstCCombatAbilityWnd_guess->Store_guess();
        }
        break;
    case 0x81:
        if (allowed_guess && keyDown_guess && allowslashcommand_guess() != 0) {
            if (g_pc_guess->GetStatus_guess() == 0 && pinstCSpellBookWnd_guess != 0) {
                if (!pinstCSpellBookWnd_guess->IsVisible_guess()) {
                    pinstCSpellBookWnd_guess->AboutToShow_guess();
                } else {
                    pinstCSpellBookWnd_guess->Deactivate_guess();
                }
            }
        }
        break;
    case 0x82:
        if (allowed_guess && keyDown_guess && pinstCActionsWnd_guess != 0) {
            pinstCActionsWnd_guess->ShowPage_guess(1);
            pinstCActionsWnd_guess->Store_guess();
        }
        break;
    case 0x83:
        if (allowed_guess && keyDown_guess && pinstCActionsWnd_guess != 0) {
            pinstCActionsWnd_guess->ShowPage_guess(2);
            pinstCActionsWnd_guess->Store_guess();
        }
        break;
    case 0x84:
        if (allowed_guess && keyDown_guess && pinstCActionsWnd_guess != 0) {
            pinstCActionsWnd_guess->ShowPage_guess(3);
            pinstCActionsWnd_guess->Store_guess();
        }
        break;
    case 0x85:
        if (allowed_guess && keyDown_guess && pinstCActionsWnd_guess != 0) {
            pinstCActionsWnd_guess->ShowPage_guess(0);
            pinstCActionsWnd_guess->Store_guess();
        }
        break;
    // RUN_WALK flips 0x009237B4. Then WHO, INVITE_FOLLOW, DISBAND, CAMP and SIT_STAND each call their
    // CEverQuest handler.
    case 0x8b:
        if (allowed_guess && keyDown_guess) {
            EQ_GLOBAL(unsigned char, 0x009237B4) ^= 1;
        }
        break;
    case 0x86:
        if (allowed_guess && keyDown_guess) {
            g_everQuest_guess->Who_guess(g_emptyText_guess);
        }
        break;
    case 0x87:
        if (allowed_guess && keyDown_guess) {
            if (!EQ_GLOBAL(char, 0x00985808) && !((PlayerFns_guess*)pinstLocalPlayer)->IsGroupInvitePending_guess()) {
                g_everQuest_guess->Invite_guess(0);
            } else {
                g_everQuest_guess->AcceptGroupInvite_guess();
            }
        }
        break;
    case 0x88:
        if (allowed_guess && keyDown_guess) {
            g_everQuest_guess->Disband_guess();
        }
        break;
    case 0x89:
        if (allowed_guess && keyDown_guess) {
            g_everQuest_guess->PrepareToCamp_guess();
        }
        break;
    case 0x8a:
        if (allowed_guess && keyDown_guess && allowslashcommand_guess() != 0) {
            g_everQuest_guess->ToggleSit_guess();
        }
        break;
    // Clip plane down/up (0x8C/0x8D), saved as [Options] ClipPlane and FogScale.
    case 0x8c:
        if (keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            if (EQ_GLOBAL(int, 0x009249AC) > 0) {
                EQ_GLOBAL(int, 0x009249AC)--;
            }
            EQ_GLOBAL(float, 0x009254D0) = (float)EQ_GLOBAL(int, 0x009249AC) * EQ_GLOBAL(float, 0x00640FEC);
            if (EQ_GLOBAL(float, 0x009254D0) < EQ_GLOBAL(float, 0x00640E38)) {
                EQ_GLOBAL(float, 0x009254D0) = EQ_GLOBAL(float, 0x00640E38);
            }
            g_everQuest_guess->FUN_004ae514_guess(EQ_GLOBAL(int, 0x009249AC), "Options", "ClipPlane");
            g_everQuest_guess->FUN_004ae55f_guess(EQ_GLOBAL(float, 0x009254D0), "Options", "FogScale");
        }
        break;
    case 0x8d:
        if (keyDown_guess && !g_everQuest_guess->IsChatInputFocused_guess()) {
            if (EQ_GLOBAL(int, 0x009249AC) < 20) {
                EQ_GLOBAL(int, 0x009249AC)++;
            }
            EQ_GLOBAL(float, 0x009254D0) = (float)EQ_GLOBAL(int, 0x009249AC) * EQ_GLOBAL(float, 0x00640FEC);
            if (EQ_GLOBAL(float, 0x009254D0) > EQ_GLOBAL(float, 0x00642650)) {
                EQ_GLOBAL(float, 0x009254D0) = EQ_GLOBAL(float, 0x00642650);
            }
            g_everQuest_guess->FUN_004ae514_guess(EQ_GLOBAL(int, 0x009249AC), "Options", "ClipPlane");
            g_everQuest_guess->FUN_004ae55f_guess(EQ_GLOBAL(float, 0x009254D0), "Options", "FogScale");
        }
        break;
    // 0xF7/0xF8 (no names): clear CEverQuest +0x17BB4 while text entry is active.
    case 0xf7:
    case 0xf8:
        if (keyDown_guess && g_everQuest_guess->IsChatInputFocused_guess()) {
            g_everQuest_guess->field_17BB4_guess = 0;
        }
        break;
    // HISTORY_UP / HISTORY_DOWN and PAGEUP / PAGEDOWN go to the active chat window.
    case 0x90:
        if (keyDown_guess && g_everQuest_guess->IsGameInputFocused_guess() && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                chat_guess->HistoryUp_guess();
                ((CXWnd*)chat_guess->input_guess)->SetFocus();
                g_everQuest_guess->SetChatInputFocus_guess(0);
            }
        }
        break;
    case 0x91:
        if (keyDown_guess && g_everQuest_guess->IsGameInputFocused_guess() && pinstCChatManager_guess != 0) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                chat_guess->HistoryDown_guess();
                ((CXWnd*)chat_guess->input_guess)->SetFocus();
                g_everQuest_guess->SetChatInputFocus_guess(0);
            }
        }
        break;
    case 0x92:
        if (keyDown_guess) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                chat_guess->ScrollChatWindowUp_guess();
            }
        }
        break;
    case 0x93:
        if (keyDown_guess) {
            ChatWnd_guess* chat_guess = pinstCChatManager_guess->GetActiveChatWindow_guess();
            if (chat_guess != 0) {
                chat_guess->ScrollChatWindowDown_guess();
            }
        }
        break;
    // TARGETPC, CYCLEPCTARGETS, TARGETNPC and CYCLENPCTARGETS share one search, 0x004C9585(range, npc,
    // nearest). TARGETNPC also refuses body types 11, 60, 65 and 67 (races below 2253) and, for a mounted
    // spawn, takes the spawn linked at actor +0x160.
    case 0x1e:
        if (allowed_guess && keyDown_guess) {
            EQPlayer* spawn_guess = GetTargetState_guess()->FindNextTarget_guess(EQ_GLOBAL(float, 0x00640E50), 0, 1);
            if (spawn_guess != 0) {
                if (pinstTarget != 0) {
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                }
                pinstTarget = spawn_guess;
            }
        }
        break;
    case 0x1f:
        if (allowed_guess && keyDown_guess) {
            EQPlayer* spawn_guess = GetTargetState_guess()->FindNextTarget_guess(EQ_GLOBAL(float, 0x00640E50), 0, 0);
            if (spawn_guess != 0) {
                if (pinstTarget != 0) {
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                }
                pinstTarget = spawn_guess;
            }
        }
        break;
    case 0x20:
        if (allowed_guess && keyDown_guess) {
            EQPlayer* spawn_guess = GetTargetState_guess()->FindNextTarget_guess(EQ_GLOBAL(float, 0x00640E50), 1, 1);
            if (spawn_guess != 0) {
                EQPlayer* old_guess = pinstTarget;
                if (old_guess != 0) {
                    GetTargetState_guess()->SetF0_guess(old_guess->SpawnID);
                }
                pinstTarget = spawn_guess;
                if (spawn_guess->Race < 0x8cd) {
                    if (spawn_guess->BodyType == 0xb || spawn_guess->BodyType == 0x41 ||
                        spawn_guess->BodyType == 0x43 || spawn_guess->BodyType == 0x3c) {
                        pinstTarget = old_guess;
                    }
                }
                if (((PlayerFns_guess*)spawn_guess)->IsHorseRace_guess()) {
                    ActorInfo_guess* info_guess = (ActorInfo_guess*)spawn_guess->pActorInfo;
                    if (info_guess != 0) {
                        EQPlayer* mount_guess = info_guess->field_160_guess;
                        if (mount_guess != 0) {
                            pinstTarget = mount_guess;
                        }
                    }
                }
            }
        }
        break;
    case 0x21:
        if (allowed_guess && keyDown_guess) {
            EQPlayer* spawn_guess = GetTargetState_guess()->FindNextTarget_guess(EQ_GLOBAL(float, 0x00640E50), 1, 0);
            if (spawn_guess != 0) {
                if (pinstTarget != 0) {
                    GetTargetState_guess()->SetF0_guess(pinstTarget->SpawnID);
                }
                pinstTarget = spawn_guess;
            }
        }
        break;
    // NETSTAT display, saved as [Defaults] NetStat.
    case 0x22:
        if (allowed_guess && keyDown_guess) {
            EQ_GLOBAL(unsigned char, 0x00923844) ^= 1;
            WriteIniString_guess("Defaults", "NetStat", EQ_GLOBAL(unsigned char, 0x00923844) ? "TRUE" : "FALSE",
                                 ".\\eqclient.ini");
        }
        break;
    // AUTOPRIM, the attack key; ignored while a merchant, banker or trainer (0x905D10/14/1C) is open.
    // Refusals: spell book open (9027), no control (12368), not standing (12369), target is yourself
    // (12696); at level 10 or lower a first attack on a target more than 2 levels up stops when context tip
    // 32 is shown. 0x009858C7 is the auto-attack flag; the result line is 12370 / 12371.
    case 0xa:
        if (allowed_guess && keyDown_guess && !EQ_GLOBAL(char, 0x0092384C)) {
            if (pinstCSpellBookWnd_guess != 0 && pinstCSpellBookWnd_guess->IsVisible_guess() &&
                !EQ_GLOBAL(char, 0x009858C7)) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2343, 0), 0xd, 1);
                break;
            }
            if (EQ_GLOBAL(int, 0x00905D10) == 0 && EQ_GLOBAL(int, 0x00905D1C) == 0 &&
                EQ_GLOBAL(int, 0x00905D14) == 0) {
                if (pinstLocalPlayer->StandState != 'd') {
                    if (!EQ_GLOBAL(char, 0x009858C7)) {
                        if (pinstLocalPlayer->StandState == 'f') {
                            pEverQuest->dsp_chat(pStringTable->getString(0x3050, 0), 0xd, 1);
                        } else {
                            pEverQuest->dsp_chat(pStringTable->getString(0x3051, 0), 0xd, 1);
                        }
                        break;
                    }
                } else if (!EQ_GLOBAL(char, 0x009858C7) && pinstTarget == pinstLocalPlayer) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3198, 0), 0xd, 1);
                    break;
                }
                if (pinstTarget != 0 && !EQ_GLOBAL(char, 0x009858C7) && pinstLocalPlayer->Level <= 10 &&
                    pinstTarget->Level - pinstLocalPlayer->Level > 2 &&
                    pinstTarget->SpawnID != GetTargetState_guess()->field_F8_guess) {
                    GetTargetState_guess()->SetF8_guess(pinstTarget->SpawnID);
                    if (pinstCTipWndCONTEXT_guess != 0 &&
                        pinstCTipWndCONTEXT_guess->FUN_00564e7e_guess(0x20, 0)) {
                        break;
                    }
                }
                g_mainWindow_guess.SetAutoAttack_guess(EQ_GLOBAL(char, 0x009858C7) == 0);
                if (EQ_GLOBAL(char, 0x009858C7)) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3052, 0), 0xd, 1);
                } else {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3053, 0), 0xd, 1);
                }
            }
        }
        break;
    case 0x1:
        if (allowed_guess && keyDown_guess) {
            g_commandKeyDown_guess[1] = keyDown_guess;
        }
        break;
    // Movement keys keep their up/down state in g_commandKeyDown_guess: AUTORUN (0) toggles 0x00923860 or
    // sets it from the argument, FORWARD and BACK (2, 3) cancel each other and stop autorun, RIGHT and LEFT
    // (4, 5) likewise. While window 0x00850C90 is up and unlocked, FORWARD/BACK drive it instead.
    case 0x0:
        if (allowed_guess && keyDown_guess) {
            if (data_guess == 0) {
                if (EQ_GLOBAL(int, 0x00923860) == 0) {
                    EQ_GLOBAL(int, 0x00923860) = 1;
                    g_commandKeyDown_guess[3] = 0;
                    EQ_GLOBAL(int, 0x00923D4C) = 0;
                } else {
                    EQ_GLOBAL(int, 0x00923860) = 0;
                }
            } else {
                EQ_GLOBAL(int, 0x00923860) = data_guess;
                EQ_GLOBAL(int, 0x00923D4C) = 0;
            }
        }
        break;
    case 0x2:
        if (pinstCGemsGameWnd_guess != 0 && pinstCGemsGameWnd_guess->IsVisible_guess() &&
            !pinstCGemsGameWnd_guess->field_15C_guess) {
            pinstCGemsGameWnd_guess->SetInputCommand_guess(0);
        } else if (allowed_guess) {
            g_commandKeyDown_guess[2] = keyDown_guess;
            if (g_commandKeyDown_guess[2] != 0) {
                if (EQ_GLOBAL(int, 0x00923860) & 3) {
                    EQ_GLOBAL(int, 0x00923860) = 0;
                }
                g_commandKeyDown_guess[3] = 0;
                EQ_GLOBAL(int, 0x00923D4C) = 0;
            } else {
                EQ_GLOBAL(int, 0x00923D48) = 0;
            }
        }
        break;
    case 0x3:
        if (pinstCGemsGameWnd_guess != 0 && pinstCGemsGameWnd_guess->IsVisible_guess() &&
            !pinstCGemsGameWnd_guess->field_15C_guess) {
            if (keyDown_guess) {
                pinstCGemsGameWnd_guess->SetInputCommand_guess(1000);
            } else {
                pinstCGemsGameWnd_guess->SetInputCommand_guess(0);
            }
        } else if (allowed_guess) {
            g_commandKeyDown_guess[3] = keyDown_guess;
            if (g_commandKeyDown_guess[3] != 0) {
                if (EQ_GLOBAL(int, 0x00923860) & 3) {
                    EQ_GLOBAL(int, 0x00923860) = 0;
                }
                g_commandKeyDown_guess[2] = 0;
                EQ_GLOBAL(int, 0x00923D48) = 0;
            } else {
                EQ_GLOBAL(int, 0x00923D4C) = 0;
            }
        }
        break;
    case 0x4:
        if (pinstCGemsGameWnd_guess != 0 && pinstCGemsGameWnd_guess->IsVisible_guess() &&
            !pinstCGemsGameWnd_guess->field_15C_guess) {
            if (keyDown_guess) {
                pinstCGemsGameWnd_guess->SetInputCommand_guess(1);
            }
        } else if (allowed_guess) {
            g_commandKeyDown_guess[4] = keyDown_guess;
            g_commandKeyDown_guess[6] = 0;
            g_commandKeyDown_guess[7] = 0;
            if (g_commandKeyDown_guess[4] != 0) {
                if (EQ_GLOBAL(int, 0x00923860) & 0xc) {
                    EQ_GLOBAL(int, 0x00923860) = 0;
                }
                g_commandKeyDown_guess[5] = 0;
                EQ_GLOBAL(int, 0x00923D50) = 0;
            } else {
                EQ_GLOBAL(int, 0x00923D54) = 0;
            }
        }
        break;
    case 0x5:
        if (pinstCGemsGameWnd_guess != 0 && pinstCGemsGameWnd_guess->IsVisible_guess() &&
            !pinstCGemsGameWnd_guess->field_15C_guess) {
            if (keyDown_guess) {
                pinstCGemsGameWnd_guess->SetInputCommand_guess(-1);
            }
        } else if (allowed_guess) {
            g_commandKeyDown_guess[5] = keyDown_guess;
            g_commandKeyDown_guess[6] = 0;
            g_commandKeyDown_guess[7] = 0;
            if (g_commandKeyDown_guess[5] != 0) {
                if (EQ_GLOBAL(int, 0x00923860) & 0xc) {
                    EQ_GLOBAL(int, 0x00923860) = 0;
                }
                g_commandKeyDown_guess[4] = 0;
                EQ_GLOBAL(int, 0x00923D54) = 0;
            } else {
                EQ_GLOBAL(int, 0x00923D50) = 0;
            }
        }
        break;
    // STRAFE_LEFT / STRAFE_RIGHT, ZOOMIN / ZOOMOUT and the six camera-move keys (0xB1-0xB6) are plain key
    // states. PITCHUP (0x11) and PITCHDOWN (0x12) cancel each other.
    case 0x6:
        if (allowed_guess) {
            g_commandKeyDown_guess[6] = keyDown_guess;
        }
        break;
    case 0x7:
        if (allowed_guess) {
            g_commandKeyDown_guess[7] = keyDown_guess;
        }
        break;
    case 0x14:
    case 0x15:
    case 0xb1:
    case 0xb2:
    case 0xb3:
    case 0xb4:
    case 0xb5:
    case 0xb6:
        g_commandKeyDown_guess[command_guess] = keyDown_guess;
        break;
    case 0x11:
        g_commandKeyDown_guess[0x11] = keyDown_guess;
        if (g_commandKeyDown_guess[0x11] != 0) {
            g_commandKeyDown_guess[0x12] = 0;
            EQ_GLOBAL(int, 0x00923D44) = 0;
        } else {
            EQ_GLOBAL(int, 0x00923D40) = 0;
        }
        break;
    case 0x12:
        g_commandKeyDown_guess[0x12] = keyDown_guess;
        if (g_commandKeyDown_guess[0x12] != 0) {
            g_commandKeyDown_guess[0x11] = 0;
            EQ_GLOBAL(int, 0x00923D40) = 0;
        } else {
            EQ_GLOBAL(int, 0x00923D44) = 0;
        }
        break;
    case 0x100:
        if (keyDown_guess) {
            g_everQuest_guess->ToggleChatInputFocus_guess();
        }
        break;
    // TOGGLECAM: next camera. CENTERVIEW (0x13) levels the view: a camera reset, or CameraAngle 0 in first
    // person.
    case 0x16:
        if (allowed_guess && keyDown_guess) {
            g_commandKeyDown_guess[0x16] = keyDown_guess;
            g_display_guess->CycleCamera_guess();
        }
        break;
    case 0x13:
        if (allowed_guess && keyDown_guess) {
            g_commandKeyDown_guess[0x13] = keyDown_guess;
            if (g_cameraMode_guess != 0) {
                if (g_cameraMode_guess == 1) {
                    g_cameras_guess[1]->SetValue_guess(EQ_GLOBAL(float, 0x00640D70));
                } else if (g_cameraMode_guess != 6) {
                    g_cameras_guess[g_cameraMode_guess]->Deactivate_guess(1);
                }
            } else {
                if (((PlayerFns_guess*)g_controlled_guess)->IsHorseRace_guess() || g_controlled_guess->Race == 0x8d) {
                    pinstLocalPlayer->CameraAngle = 0.0f;
                } else {
                    g_controlled_guess->CameraAngle = 0.0f;
                }
            }
            g_commandKeyDown_guess[0x11] = 0;
            EQ_GLOBAL(int, 0x009257F4) = 0;
            EQ_GLOBAL(int, 0x00923D40) = 0;
            EQ_GLOBAL(int, 0x009257F8) = 0;
            g_commandKeyDown_guess[0x12] = 0;
            EQ_GLOBAL(int, 0x00923D44) = 0;
        }
        break;
    // MOUSELOOK toggle (12372 / 12373). MOUSELOOK_ENGAGE (9) flips 0x00923842.
    case 0x8:
        if (allowed_guess && keyDown_guess) {
            g_commandKeyDown_guess[8] = keyDown_guess;
            EQ_GLOBAL(unsigned char, 0x009237B8) ^= 1;
            EQ_GLOBAL(int, 0x0092499C) = EQ_GLOBAL(unsigned char, 0x009237B8);
            if (EQ_GLOBAL(unsigned char, 0x009237B8) == 0) {
                pEverQuest->dsp_chat(pStringTable->getString(0x3054, 0));
            } else {
                pEverQuest->dsp_chat(pStringTable->getString(0x3055, 0));
            }
        }
        break;
    case 0x9:
        if (allowed_guess && keyDown_guess) {
            EQ_GLOBAL(unsigned char, 0x00923842) ^= 1;
        }
        break;
    // FULLSCREEN is the full-screen view (UI hidden), not the display mode: view mode 0x00850508 flips 2 <->
    // 3.
    case 0x17:
        if (keyDown_guess) {
            g_commandKeyDown_guess[0x17] = keyDown_guess;
            EQ_GLOBAL(int, 0x00850508) = EQ_GLOBAL(int, 0x00850508) == 3 ? 2 : 3;
            g_display_guess->ChangeVideoMode_guess();
        }
        break;
    // SCREENCAP: sets the capture flag, "Taking a screenshot...".
    case 0x8f:
        if (allowed_guess && keyDown_guess) {
            EQ_GLOBAL(unsigned char, 0x00923D1C) = 1;
            pEverQuest->dsp_chat(pStringTable->getString(0x3056, 0), 0xf, 1);
        }
        break;
    case 0xb9:
        if (keyDown_guess) {
            if (!EQ_GLOBAL(Obj99E38C_guess*, 0x0099E38C)->field_4_guess ||
                IsChineseOrJapaneseLanguage_guess(EQ_GLOBAL(int, 0x00923D74))) {
                // RELEASE_MOUSE_CURSOR: a fake WM_ACTIVATE(0) frees the mouse; skipped in fullscreen
                // (0x99E38C +4), unless 0x00923D74 is 2, 3 or 6 (0x00461979).
                PostMessageA(g_mainWindow_guess.window_guess, WM_ACTIVATE, 0, 0);
            }
        }
        break;
    case 0x101:
        if (keyDown_guess) {
            ReinitMouse_guess();
        }
        break;
    // Id 0xFD (past the name table): logs the CMD_EXITGAME and sets the exit flag
    // 0x00923D7B.
    case 0xfd:
        Log_guess("ExecuteCmd has received a CMD_EXITGAME.\n");
        EQ_GLOBAL(unsigned char, 0x00923D7B) = 1;
        break;
    // CLOSE_TOP_WINDOW, then CLEAR_TARGET (also drops 0x00905D0C) and OPEN_INV_BAGS / CLOSE_INV_BAGS.
    case 0xc7:
        if (keyDown_guess) {
            g_display_guess->FUN_004382e5_guess();
        }
        break;
    case 0xc8:
        if (keyDown_guess && allowed_guess) {
            if (pinstTarget != 0 || EQ_GLOBAL(int, 0x00905D0C) != 0) {
                pinstTarget = 0;
                EQ_GLOBAL(int, 0x00905D0C) = 0;
                pEverQuest->dsp_chat(pStringTable->getString(0x3057, 0));
            }
        }
        break;
    case 0xe2:
        if (allowed_guess) {
            pinstCInvSlotMgr_guess->OpenAllBags_guess();
        }
        break;
    case 0xe3:
        if (allowed_guess) {
            pinstCInvSlotMgr_guess->CloseAllBags_guess();
        }
        break;
    case 0xc9:
        if (keyDown_guess && allowed_guess && pinstCFindLocationWnd_guess != 0) {
            if (pinstCFindLocationWnd_guess->show_guess) {
                pinstCFindLocationWnd_guess->StartFind_guess();
                pinstCFindLocationWnd_guess->Deactivate_guess();
            } else if (pinstCFindLocationWnd_guess->FUN_00502f2f_guess()) {
                pinstCFindLocationWnd_guess->FUN_0050300f_guess();
                if (pinstCDynamicZoneWnd_guess != 0) {
                    pinstCDynamicZoneWnd_guess->FUN_004fe347_guess();
                }
            } else if (pinstCFindLocationWnd_guess->FUN_00502f37_guess() > 0) {
                pinstCFindLocationWnd_guess->AboutToShow_guess();
            } else {
                pConfirmationDialogPool_guess->Activate(0, 0xb, pStringTable->getString(0x1a8c, 0), 1, 6000, 0, 0);
            }
            pinstCFindLocationWnd_guess->Store_guess();
        }
        break;
    // TOGGLE_PETITION: only a GM can open window 0x00850C98; anyone can close it.
    case 0xea:
        if (pinstCPetitionQWnd_guess != 0 && keyDown_guess) {
            if (!pinstCPetitionQWnd_guess->IsVisible_guess()) {
                if (pinstLocalPlayer == 0 || !pinstLocalPlayer->GM) {
                    break;
                }
                pinstCPetitionQWnd_guess->AboutToShow_guess();
            } else {
                pinstCPetitionQWnd_guess->UndoCheckout_guess();
                pinstCPetitionQWnd_guess->Deactivate_guess();
            }
            pinstCPetitionQWnd_guess->Store_guess();
        }
        break;
    // Window toggles from here on save their state to eqclient.ini (HidePlayerWin, HideTargetWin,
    // HideSpellsWin, HideBuffWin, HideAltAdvWin...); 0xAA and 0xE5 open help pages.
    case 0x97:
        if (keyDown_guess) {
            if (EQ_GLOBAL(int, 0x009247EC) != 0) {
                EQ_GLOBAL(int, 0x009247EC) = 0;
                WriteIniString_guess("Defaults", "HidePlayerWin", "FALSE", ".\\eqclient.ini");
                if (pinstCPlayerWnd_guess != 0) {
                    pinstCPlayerWnd_guess->AboutToShow_guess();
                    pinstCPlayerWnd_guess->Store_guess();
                }
            } else {
                EQ_GLOBAL(int, 0x009247EC) = 1;
                WriteIniString_guess("Defaults", "HidePlayerWin", "TRUE", ".\\eqclient.ini");
                if (pinstCPlayerWnd_guess != 0) {
                    pinstCPlayerWnd_guess->Deactivate_guess();
                    pinstCPlayerWnd_guess->Store_guess();
                }
            }
        }
        break;
    case 0xae:
        if (keyDown_guess && pinstCCompassWnd_guess != 0) {
            if (!pinstCCompassWnd_guess->IsVisible_guess()) {
                pinstCCompassWnd_guess->AboutToShow_guess();
            } else {
                pinstCCompassWnd_guess->Deactivate_guess();
            }
            pinstCCompassWnd_guess->Store_guess();
        }
        break;
    case 0x98:
        if (keyDown_guess && pinstCGroupWnd_guess != 0) {
            if (pinstCGroupWnd_guess->IsVisible_guess()) {
                pinstCGroupWnd_guess->Deactivate_guess();
            } else {
                pinstCGroupWnd_guess->AboutToShow_guess();
            }
            pinstCGroupWnd_guess->Store_guess();
        }
        break;
    case 0x99:
        if (keyDown_guess) {
            if (EQ_GLOBAL(int, 0x009247F4) != 0) {
                EQ_GLOBAL(int, 0x009247F4) = 0;
                WriteIniString_guess("Defaults", "HideTargetWin", "FALSE", ".\\eqclient.ini");
                if (pinstCTargetWnd_guess != 0) {
                    pinstCTargetWnd_guess->AboutToShow_guess();
                    pinstCTargetWnd_guess->Store_guess();
                }
            } else {
                EQ_GLOBAL(int, 0x009247F4) = 1;
                WriteIniString_guess("Defaults", "HideTargetWin", "TRUE", ".\\eqclient.ini");
                if (pinstCTargetWnd_guess != 0) {
                    pinstCTargetWnd_guess->Deactivate_guess();
                    pinstCTargetWnd_guess->Store_guess();
                }
            }
        }
        break;
    case 0x9a:
        if (keyDown_guess) {
            if (EQ_GLOBAL(int, 0x009247F8) != 0) {
                EQ_GLOBAL(int, 0x009247F8) = 0;
                WriteIniString_guess("Defaults", "HideSpellsWin", "FALSE", ".\\eqclient.ini");
                if (pinstCCastSpellWnd_guess != 0) {
                    pinstCCastSpellWnd_guess->AboutToShow_guess();
                    pinstCCastSpellWnd_guess->Store_guess();
                }
            } else {
                EQ_GLOBAL(int, 0x009247F8) = 1;
                WriteIniString_guess("Defaults", "HideSpellsWin", "TRUE", ".\\eqclient.ini");
                if (pinstCCastSpellWnd_guess != 0) {
                    pinstCCastSpellWnd_guess->Deactivate_guess();
                    pinstCCastSpellWnd_guess->Store_guess();
                }
            }
        }
        break;
    case 0x9b:
        if (keyDown_guess) {
            if (EQ_GLOBAL(int, 0x009247FC) != 0) {
                EQ_GLOBAL(int, 0x009247FC) = 0;
                WriteIniString_guess("Defaults", "HideBuffWin", "FALSE", ".\\eqclient.ini");
                if (pinstCBuffWindowNORMAL_guess != 0) {
                    pinstCBuffWindowNORMAL_guess->AboutToShow_guess();
                    pinstCBuffWindowNORMAL_guess->Store_guess();
                }
            } else {
                EQ_GLOBAL(int, 0x009247FC) = 1;
                WriteIniString_guess("Defaults", "HideBuffWin", "TRUE", ".\\eqclient.ini");
                if (pinstCBuffWindowNORMAL_guess != 0) {
                    pinstCBuffWindowNORMAL_guess->Deactivate_guess();
                    pinstCBuffWindowNORMAL_guess->Store_guess();
                }
            }
        }
        break;
    case 0x9c:
    case 0x9d:
    case 0x9e:
    case 0x9f:
        if (keyDown_guess && g_hotWnds_guess[command_guess - 0x9c] != 0) {
            if (g_hotWnds_guess[command_guess - 0x9c]->IsVisible_guess()) {
                g_hotWnds_guess[command_guess - 0x9c]->Deactivate_guess();
            } else {
                g_hotWnds_guess[command_guess - 0x9c]->AboutToShow_guess();
            }
            g_hotWnds_guess[command_guess - 0x9c]->Store_guess();
        }
        break;
    case 0xa3:
        if (keyDown_guess && pinstCActionsWnd_guess != 0) {
            if (pinstCActionsWnd_guess->IsVisible_guess()) {
                pinstCActionsWnd_guess->Deactivate_guess();
            } else {
                pinstCActionsWnd_guess->ShowPage_guess(
                    pinstCActionsWnd_guess->GetCurrentPage_guess());
            }
            pinstCActionsWnd_guess->Store_guess();
        }
        break;
    case 0xa4:
        if (keyDown_guess) {
            if (g_pc_guess->Flag4_guess() || g_pc_guess->field_E25_guess) {
                if (pinstCAAWnd_guess != 0) {
                    if (!pinstCAAWnd_guess->IsVisible_guess()) {
                        pinstCAAWnd_guess->AboutToShow_guess();
                        EQ_GLOBAL(int, 0x0092480C) = 0;
                    } else {
                        pinstCAAWnd_guess->Deactivate_guess();
                        EQ_GLOBAL(int, 0x0092480C) = 1;
                    }
                    pinstCAAWnd_guess->Store_guess();
                }
                WriteIniString_guess("Defaults", "HideAltAdvWin", EQ_GLOBAL(int, 0x0092480C) == 1 ? "TRUE" : "FALSE",
                                     ".\\eqclient.ini");
            }
        }
        break;
    case 0x104:
        if (keyDown_guess && pinstLocalPlayer != 0 && pinstLocalPlayer->pActorInfo != 0 &&
            ((ActorInfo_guess*)pinstLocalPlayer->pActorInfo)->field_12C_guess != 0) {
            Thing12C_guess* thing_guess = ((ActorInfo_guess*)pinstLocalPlayer->pActorInfo)->field_12C_guess;
            if (g_pc_guess->Flag4_guess() || g_pc_guess->Flag8_guess() || g_pc_guess->field_E25_guess ||
                EQ_GLOBAL(int, 0x00923D74) != 0) {
                if (!thing_guess->field_34_guess) {
                    pEverQuest->dsp_chat(pStringTable->getString(0x3059, 0), 0xd, 1);
                } else if (EQ_GLOBAL(int, 0x00924814) != 0) {
                    if (pinstCFacePick_guess != 0) {
                        pinstCFacePick_guess->AboutToShow_guess();
                    }
                } else {
                    if (pinstCFacePick_guess != 0) {
                        pinstCFacePick_guess->Deactivate_guess();
                    }
                }
            }
        }
        break;
    case 0xa7:
        if (keyDown_guess && pinstCFriendsWnd_guess != 0) {
            if (pinstCFriendsWnd_guess->IsVisible_guess()) {
                pinstCFriendsWnd_guess->Deactivate_guess();
            } else {
                pinstCFriendsWnd_guess->AboutToShow_guess();
            }
            pinstCFriendsWnd_guess->Store_guess();
        }
        break;
    case 0xa8:
        if (keyDown_guess && pinstCPetInfoWnd_guess != 0) {
            if (pinstCPetInfoWnd_guess->IsVisible_guess()) {
                pinstCPetInfoWnd_guess->Deactivate_guess();
            } else {
                pinstCPetInfoWnd_guess->AboutToShow_guess();
            }
            pinstCPetInfoWnd_guess->Store_guess();
        }
        break;
    case 0xa9:
        if (keyDown_guess && pinstCOptionsWnd_guess != 0) {
            if (pinstCOptionsWnd_guess->IsVisible_guess()) {
                pinstCOptionsWnd_guess->Deactivate_guess();
            } else {
                pinstCOptionsWnd_guess->AboutToShow_guess();
            }
            pinstCOptionsWnd_guess->Store_guess();
        }
        break;
    case 0xaa:
        if (keyDown_guess && pinstCTicketWnd_guess != 0) {
            if (!pinstCTicketWnd_guess->IsVisible_guess()) {
                pinstCTicketWnd_guess->ShowHelpPage_guess("help\\help.html");
                pinstCTicketWnd_guess->ShowPage_guess(0);
                pinstCTicketWnd_guess->AboutToShow_guess();
            } else {
                pinstCTicketWnd_guess->Deactivate_guess();
            }
            pinstCTicketWnd_guess->Store_guess();
        }
        break;
    case 0xe5:
        if (keyDown_guess && pinstCTicketWnd_guess != 0) {
            pinstCTicketWnd_guess->ShowHelpPage_guess("help\\subscribeEQ.html");
            pinstCTicketWnd_guess->ShowPage_guess(0);
            pinstCTicketWnd_guess->AboutToShow_guess();
            pinstCTicketWnd_guess->Store_guess();
        }
        break;
    case 0xab:
        if (keyDown_guess && pinstCSelectorWnd_guess != 0) {
            if (pinstCSelectorWnd_guess->IsVisible_guess()) {
                pinstCSelectorWnd_guess->Deactivate_guess();
            } else {
                pinstCSelectorWnd_guess->AboutToShow_guess();
            }
            pinstCSelectorWnd_guess->Store_guess();
        }
        break;
    case 0xac:
        if (keyDown_guess && pinstCVideoModesWnd_guess != 0) {
            if (pinstCVideoModesWnd_guess->IsVisible_guess()) {
                pinstCVideoModesWnd_guess->Deactivate_guess();
            } else {
                pinstCVideoModesWnd_guess->AboutToShow_guess();
            }
            pinstCVideoModesWnd_guess->Store_guess();
        }
        break;
    case 0xa5:
        if (keyDown_guess && pinstCBazaarWnd_guess != 0) {
            if (pinstCBazaarWnd_guess->IsVisible_guess()) {
                pinstCBazaarWnd_guess->Deactivate_guess();
            } else {
                pinstCBazaarWnd_guess->AboutToShow_guess();
            }
            pinstCBazaarWnd_guess->Store_guess();
        }
        break;
    case 0xad:
        if (keyDown_guess && pinstCBazaarSearchWnd_guess != 0) {
            if (pinstCBazaarSearchWnd_guess->IsVisible_guess()) {
                pinstCBazaarSearchWnd_guess->Deactivate_guess();
            } else {
                pinstCBazaarSearchWnd_guess->AboutToShow_guess();
            }
            pinstCBazaarSearchWnd_guess->Store_guess();
        }
        break;
    case 0xb0:
        if (keyDown_guess && EQ_GLOBAL(Wnd_guess*, 0x00850BE0) != 0) {
            if (EQ_GLOBAL(Wnd_guess*, 0x00850BE0)->IsVisible_guess()) {
                EQ_GLOBAL(Wnd_guess*, 0x00850BE0)->Deactivate_guess();
            } else {
                EQ_GLOBAL(Wnd_guess*, 0x00850BE0)->AboutToShow_guess();
            }
            EQ_GLOBAL(Wnd_guess*, 0x00850BE0)->Store_guess();
        }
        break;
    case 0xaf:
        if (keyDown_guess && pinstCRaidWnd_guess != 0) {
            if (pinstCRaidWnd_guess->IsVisible_guess()) {
                pinstCRaidWnd_guess->Deactivate_guess();
            } else {
                pinstCRaidWnd_guess->AboutToShow_guess();
            }
            pinstCRaidWnd_guess->Store_guess();
        }
        break;
    case 0xba:
        if (keyDown_guess && EQ_GLOBAL(Wnd_guess*, 0x00850CA0) != 0) {
            if (EQ_GLOBAL(Wnd_guess*, 0x00850CA0)->IsVisible_guess()) {
                EQ_GLOBAL(Wnd_guess*, 0x00850CA0)->Deactivate_guess();
            } else {
                EQ_GLOBAL(Wnd_guess*, 0x00850CA0)->AboutToShow_guess();
            }
            EQ_GLOBAL(Wnd_guess*, 0x00850CA0)->Store_guess();
        }
        break;
    case 0xbb:
        if (keyDown_guess && pinstCMapViewWnd_guess != 0) {
            if (pinstCMapViewWnd_guess->IsVisible_guess()) {
                pinstCMapViewWnd_guess->Deactivate_guess();
            } else {
                pinstCMapViewWnd_guess->AboutToShow_guess();
            }
            pinstCMapViewWnd_guess->Store_guess();
        }
        break;
    case 0xa1:
        if (keyDown_guess && EQ_GLOBAL(char, 0x00923D65) && pinstCMailWnd_guess != 0) {
            if (pinstCMailWnd_guess->IsVisible_guess()) {
                pinstCMailWnd_guess->Deactivate_guess();
            } else {
                pinstCMailWnd_guess->AboutToShow_guess();
            }
            pinstCMailWnd_guess->Store_guess();
        }
        break;
    case 0xa2:
        if (keyDown_guess && EQ_GLOBAL(char, 0x00923D65) && pinstCMailCompositionWnd_guess != 0) {
            if (pinstCMailCompositionWnd_guess->IsVisible_guess()) {
                pinstCMailCompositionWnd_guess->Deactivate_guess();
            } else {
                pinstCMailCompositionWnd_guess->AboutToShow_guess();
            }
            pinstCMailCompositionWnd_guess->Store_guess();
        }
        break;
    case 0xb7:
        if (keyDown_guess && (EQ_GLOBAL(int, 0x009247A0) != 0 || EQ_GLOBAL(int, 0x009247A4) != 0) &&
            pinstCJournalNPCWnd_guess != 0) {
            if (pinstCJournalNPCWnd_guess->IsVisible_guess()) {
                pinstCJournalNPCWnd_guess->Deactivate_guess();
            } else {
                pinstCJournalNPCWnd_guess->AboutToShow_guess();
            }
            pinstCJournalNPCWnd_guess->Store_guess();
        }
        break;
    case 0xbc:
        if (keyDown_guess && EQ_GLOBAL(int, 0x009247A0) != 0 && pinstCGuildManagementWnd_guess != 0) {
            if (pinstCGuildManagementWnd_guess->IsVisible_guess()) {
                pinstCGuildManagementWnd_guess->Deactivate_guess();
            } else {
                pinstCGuildManagementWnd_guess->AboutToShow_guess();
            }
            pinstCGuildManagementWnd_guess->Store_guess();
        }
        break;
    case 0xbd:
        if (keyDown_guess && pinstCGroupSearchWnd_guess != 0) {
            if (pinstCGroupSearchWnd_guess->IsVisible_guess()) {
                pinstCGroupSearchWnd_guess->Deactivate_guess();
            } else {
                pinstCGroupSearchWnd_guess->AboutToShow_guess();
            }
            pinstCGroupSearchWnd_guess->Store_guess();
        }
        break;
    case 0xb8:
        if (keyDown_guess && pinstCBuffWindowSHORT_guess != 0) {
            if (pinstCBuffWindowSHORT_guess->IsVisible_guess()) {
                pinstCBuffWindowSHORT_guess->Deactivate_guess();
            } else {
                pinstCBuffWindowSHORT_guess->AboutToShow_guess();
            }
            pinstCBuffWindowSHORT_guess->Store_guess();
        }
        break;
    case 0xc6:
        if (keyDown_guess && g_pc_guess->Flag20_guess() && pinstCAdventureRequestWnd_guess != 0) {
            EQ_GLOBAL(Obj9232F0_guess, 0x009232F0).FUN_00408583_guess();
        }
        break;
    case 0xca:
        if (keyDown_guess && EQ_GLOBAL(int, 0x009247A8) != 0 && pinstCLeadershipWnd_guess != 0) {
            if (pinstCLeadershipWnd_guess->IsVisible_guess()) {
                pinstCLeadershipWnd_guess->Deactivate_guess();
            } else {
                pinstCLeadershipWnd_guess->AboutToShow_guess();
            }
            pinstCLeadershipWnd_guess->Store_guess();
        }
        break;
    case 0xd8:
        if (keyDown_guess && pinstCTicketWnd_guess != 0) {
            if (pinstCTicketWnd_guess->IsVisible_guess()) {
                pinstCTicketWnd_guess->Deactivate_guess();
            } else if (EQ_GLOBAL(char, 0x00923D64)) {
                pinstCTicketWnd_guess->AboutToShow_guess();
                pinstCTicketWnd_guess->ShowPage_guess(1);
            }
            pinstCTicketWnd_guess->Store_guess();
        }
        break;
    case 0xcb:
        if (keyDown_guess && EQ_GLOBAL(Obj850350_guess, 0x00850350).IsTributeAvailable_guess() &&
            pinstCTributeBenefitWnd_guess != 0) {
            if (pinstCTributeBenefitWnd_guess->IsVisible_guess()) {
                pinstCTributeBenefitWnd_guess->Deactivate_guess();
            } else {
                pinstCTributeBenefitWnd_guess->AboutToShow_guess();
            }
            pinstCTributeBenefitWnd_guess->Store_guess();
        }
        break;
    case 0xd5:
        if (keyDown_guess && pinstCDynamicZoneWnd_guess != 0) {
            pinstCDynamicZoneWnd_guess->SetVisible_guess(
                pinstCDynamicZoneWnd_guess->show_guess == 0, true);
            pinstCDynamicZoneWnd_guess->Store_guess();
        }
        break;
    case 0xdb:
        if (keyDown_guess && pinstCTitleWnd_guess != 0) {
            pinstCTitleWnd_guess->SetVisible_guess(pinstCTitleWnd_guess->show_guess == 0, true);
            pinstCTitleWnd_guess->Store_guess();
        }
        break;
    case 0xe6:
        if (keyDown_guess && EQ_GLOBAL(Wnd_guess*, 0x0079C148) != 0) {
            EQ_GLOBAL(Wnd_guess*, 0x0079C148)->SetVisible_guess(EQ_GLOBAL(Wnd_guess*, 0x0079C148)->show_guess == 0, true);
            EQ_GLOBAL(Wnd_guess*, 0x0079C148)->Store_guess();
        }
        break;
    case 0xe7: {
        if (!keyDown_guess) {
            break;
        }
        Wnd_guess* focus_guess = pinstCXWndManager_guess->GetFocus_guess();
        if (focus_guess == 0) {
            break;
        }
        EditWnd_guess* edit_guess = focus_guess->GetEdit_guess();
        if (edit_guess == 0) {
            break;
        }
        if (!OpenClipboard(0)) {
            break;
        }
        HANDLE handle_guess = GetClipboardData(CF_TEXT);
        if (handle_guess != 0) {
            char* source_guess = (char*)GlobalLock(handle_guess);
            if (source_guess != 0) {
                CXStr text_guess;
                while (*source_guess != 0) {
                    char character_guess = *source_guess;
                    // Original bug: the byte is a signed char in the binary (cmp al,0x20; jl ... movsx), so
                    // 0x80-0xFF also turn into spaces and the 0xFF test can never hit.
                    if (character_guess < 0x20 || character_guess == 0x7f || character_guess == 0xff) {
                        character_guess = ' ';
                    }
                    ((XStrFns_guess*)&text_guess)->Append_guess(character_guess);
                    source_guess++;
                }
                GlobalUnlock(handle_guess);
                char* pasted_guess = text_guess;
                edit_guess->Replace_guess(pasted_guess, 0);
            }
        }
        // No break follows: a paste also toggles the PvP stats window (0x991EB0). Original; kept.
        CloseClipboard();
    }
    // falls through, as in the original
    case 0xd6:
        if (keyDown_guess && pinstCPvPStatsWnd_guess != 0) {
            pinstCPvPStatsWnd_guess->SetVisible_guess(pinstCPvPStatsWnd_guess->show_guess == 0, true);
            pinstCPvPStatsWnd_guess->Store_guess();
        }
        break;
    case 0xd7:
        if (keyDown_guess && pinstCTaskWnd_guess != 0) {
            pinstCTaskWnd_guess->SetVisible_guess(pinstCTaskWnd_guess->show_guess == 0, true);
            pinstCTaskWnd_guess->Store_guess();
        }
        break;
    case 0xda:
        if (keyDown_guess && EQ_GLOBAL(int, 0x009247AC) != 0 && pinstCVoiceMacroWnd_guess != 0) {
            pinstCVoiceMacroWnd_guess->SetVisible_guess(pinstCVoiceMacroWnd_guess->show_guess == 0, true);
        }
        break;
    case 0x7f:
    case 0x96:
    case 0xf2:
    case 0xf3:
        break;
    default:
        return false;
    }
    return true;
}

// Enables key command `index`.
// FUNCTION: TITANIUM 0x00464675
void __cdecl EnableCommand_guess(int index_guess) {
    EQ_ARRAY(unsigned char, 0x009004A0)[index_guess] = 1;
}

// Enables every key command.
// FUNCTION: TITANIUM 0x00464681
void __cdecl EnableAllCommands_guess() {
    SetAllCommandsEnabled_guess(1);
}

// Disables key command `index`.
// FUNCTION: TITANIUM 0x0046468A
void __cdecl DisableCommand_guess(int index_guess) {
    EQ_ARRAY(unsigned char, 0x009004A0)[index_guess] = 0;
}

// Disables every key command; the client then re-enables the few allowed in its current state.
// FUNCTION: TITANIUM 0x00464696
void __cdecl DisableAllCommands_guess() {
    SetAllCommandsEnabled_guess(0);
}

