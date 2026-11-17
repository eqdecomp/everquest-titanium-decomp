// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 79: a hint from compare/tumap.py.
// OP_PlayerProfile: checking the zone-in profile and copying it into the character (Pc_guess, Owner_guess is
// its virtual base), plus the group-list rebuild it triggers. PlayerProfile_guess is EQEmu's Titanium
// PlayerProfile_Struct without the leading checksum: Src offset = EQEmu offset - 4 (names3288 = name,
// names33dc = groupMembers, name355c = groupLeader).
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"
#include "titanium/bounded_array.h"

struct PilotFloatThing_guess {
    char pad_0000_guess[0x40];
    float value_guess;
};

struct PilotManager_guess {
    char pad_0000_guess[0x11];
    unsigned char state_11_guess;
    char pad_0012_guess[0x148 - 0x12];
    int field_148_guess;
    // EXTERNAL: TITANIUM 0x00440F51 PilotManager_guess::SetValue_guess
    void SetValue_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00438FDF PilotManager_guess::Update_guess
    void Update_guess();
};

struct PilotPart_guess {
    // EXTERNAL: TITANIUM 0x0041B46C PilotPart_guess::ProcessDrunkenness_guess
    void ProcessDrunkenness_guess();
};

struct PilotOwner_guess {
    char pad_0000_guess[0xc280];
    void UpdateZoneEnvironment_guess();
};

#define gPilotThingIndex_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_cameras_guess EQ_ARRAY(PilotFloatThing_guess*, 0x009254FC)
#define gPilotManager_guess EQ_GLOBAL(PilotManager_guess*, 0x00905D24)

typedef char SlotName_guess[0x40];

#include "titanium/layouts/core.h"
#include "titanium/wnd/CCombatAbilityWnd.h"
#include "titanium/wnd/CGroupSearchWnd.h"

struct PcView_guess {
    char reserved0_guess[8];
    VBTable* ref8_guess;
    char reserved10_guess[0x38];
    char name44_guess[1];
    char reserved45_guess[0x15b0 - 0x45];
    char names_15b0_guess[6][0x40];
    void UpdateGroupFromProfile_guess();
};

#define gGateFlag_guess EQ_GLOBAL(char, 0x00923798)
#define gGateCount_guess EQ_GLOBAL(int, 0x00923884)
#define gSlotNames_guess EQ_ARRAY(SlotName_guess, 0x0090424D)
#define gSlotFlags_guess EQ_ARRAY(unsigned char, 0x00904248)
#define gSlotValues_guess EQ_ARRAY(unsigned int, 0x00904390)
#define gPending_guess EQ_ARRAY(char, 0x009043A4)
#define gChatHook_guess EQ_GLOBAL(void*, 0x00905CE4)
#define gDisconnectState_guess EQ_GLOBAL(unsigned int, 0x00923794)

struct GameState_guess {
    char pad_0000_guess[0xB50];
    unsigned int field_b50_guess;
    char pad_b54_guess[0x39400 - 0xB54];
    unsigned int field_39400_guess;
    // EXTERNAL: TITANIUM 0x00494B3D GameState_guess::SetGameState
    void SetGameState(unsigned int mode_guess);
};
#define gGameState_guess EQ_GLOBAL(GameState_guess*, 0x00988DF0)

struct Connection_guess {
    // EXTERNAL: TITANIUM 0x0040BE64 Connection_guess::Stop_guess
    void Stop_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0040BEAE Connection_guess::Wait_guess
    void Wait_guess(int value_guess);
    virtual void Slot00_guess();
    virtual void Slot01_guess();
};
#define gConnection_guess EQ_GLOBAL(Connection_guess*, 0x00905CA0)

struct Candidate_guess {
    // EXTERNAL: TITANIUM 0x00518E4E Candidate_guess::Apply_guess
    void Apply_guess(int value_guess);
};

struct CandidateTable_guess {
    // EXTERNAL: TITANIUM 0x0051A84D CandidateTable_guess::FindInvSlot
    Candidate_guess* FindInvSlot(int index_guess);
};
#define pinstCInvSlotMgr_guess EQ_GLOBAL(CandidateTable_guess*, 0x00850CB8)

// EXTERNAL: TITANIUM 0x004B6C04 MemChecker0
int __cdecl MemChecker0(const unsigned int* data_guess, int size_guess);
// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* text_guess);


// EXTERNAL: TITANIUM 0x00574950 FUN_00574950_guess
int __cdecl FUN_00574950_guess(const char* first, const char* second);
// EXTERNAL: TITANIUM 0x0047C88E GetSpawnByName_guess
unsigned int __cdecl GetSpawnByName_guess(const char* name);
// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output, unsigned int id, const char* text, int zero1, int zero2,
    int zero3, int zero4, int zero5, int zero6, int zero7, int zero8);
// EXTERNAL: TITANIUM 0x00467441 FUN_00467441_guess
void __cdecl FUN_00467441_guess(char* output, const char* text, char** args, int count, int flags);
// EXTERNAL: TITANIUM 0x00468694 do_lfg_guess
void __cdecl do_lfg_guess(void* target, const char* text);

struct Target_guess {
    unsigned int field_00_guess;
    unsigned int field_04_guess;
    unsigned int field_08_guess;
    unsigned char field_0c_guess;
    char pad_0d_guess[3];
    // EXTERNAL: TITANIUM 0x0050F3F6 Target_guess::Run_guess
    void Run_guess();
    Target_guess() {
        field_04_guess = 0;
        field_00_guess = 0;
        field_08_guess = 0;
        field_0c_guess = 1;
    }
};

struct Thunk_guess {
    char pad_guess[0x74];
    Target_guess target_guess;
    void FUN_004ba0f3();
};

struct Thunk38_guess {
    char pad_guess[0x38c4];
    Target_guess target_guess;
    void FUN_004ba88e();
};

struct Result_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    char pad_0000_guess[0x1160];
    unsigned char value_1164_guess[9];
    char pad_116d_guess[3];
    unsigned int value_1170_guess[9];
    unsigned char gender_1194_guess;
    unsigned int race_1198_guess;
    unsigned char class_119c_guess;
    char pad_119d_guess[3];
    unsigned int value_11a0_guess;
    char pad_11a4_guess[0x2c];
    unsigned char face_11d0_guess;
    char pad_11d1_guess[0x13];
    unsigned int value_11e4_guess[4];
    unsigned char value_11f4_guess;
    char pad_11f5_guess[7];
    unsigned int value_11fc_guess;
    unsigned int value_1200_guess;
    unsigned int value_1204_guess;
    unsigned int value_1208_guess;
    char pad_120c_guess[4];
    unsigned int value_1210_guess;
    unsigned int value_1214_guess;
    char pad_1218_guess[8];
    unsigned int value_1220_guess;
    char pad_1224_guess[4];
    unsigned int value_1228_guess;
    char pad_122c_guess[0x10];
    unsigned int value_123c_guess;
    unsigned int value_1240_guess;
    unsigned int value_1244_guess;
    unsigned int value_1248_guess;
    unsigned int value_124c_guess;
    unsigned int value_1250_guess;
    unsigned int value_1254_guess;
    unsigned int value_1258_guess;
    unsigned int value_125c_guess;
    unsigned int value_1260_guess;
    unsigned int value_1264_guess;
    unsigned int value_1268_guess;
    unsigned int value_126c_guess;
    unsigned int value_1270_guess;
    unsigned int value_1274_guess;
    unsigned int value_1278_guess;
    unsigned int value_127c_guess;
    unsigned int value_1280_guess;
    unsigned int value_1284_guess;
    char pad_1288_guess[4];
    struct Block_guess {
        unsigned int value_guess[5];
    } block_128c_guess[5];
    unsigned int value_12f0_guess[22];
    struct Pair_guess {
        unsigned int first_guess;
        unsigned int second_guess;
    } pair_1348_guess[240];
    void Set_indexed_byte_guess(unsigned int index, unsigned char value);
    void Set_indexed_dword_guess(unsigned int index, unsigned int value);
    void SetBindPoint_guess(unsigned int index, const Block_guess* value);
    void Set_indexed_value_guess(unsigned int index, unsigned int value);
    void SetAAEntry_guess(unsigned int index, const Pair_guess* value);
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    Result_guess* GetCharInfo2();
};

struct Entry_guess;

struct Name40_guess {
    char text_guess[0x40];
    // EXTERNAL: TITANIUM 0x0040E25C Name40_guess::Set_guess
    void Set_guess(const char* text);
};

struct Text20_guess {
    char text_guess[0x20];
    // EXTERNAL: TITANIUM 0x00454EA9 Text20_guess::Set_guess
    void Set_guess(const char* text);
};

struct Name32_guess {
    char data_guess[32];
    void Set_guess(int index, char value) {
        if ((unsigned int)index >= 32) {
            __debugbreak();
        }
        data_guess[index] = value;
    }
};

struct Owner_guess {
    virtual void VbSlot00_guess();
    virtual void VbSlot01_guess();
    virtual void VbSlot02_guess();
    virtual void VbSlot03_guess();
    EQ_CharacterProfileView_guess accessor_guess;
    char pad_005_guess[7];
    Name32_guess languages_000c_guess;
    float vb_y_02c_guess;
    float vb_x_030_guess;
    float vb_z_034_guess;
    float vb_heading_038_guess;
    Name40_guess vb_name_03c_guess;
    Text20_guess vb_text_07c_guess;
    char pad_09c_guess[0x20];
    Name40_guess vb_name_0bc_guess;
    unsigned char vb_0fc_guess;
    char pad_0fd_guess[3];
    unsigned int vb_100_guess;
    unsigned char vb_104_guess;
    char pad_105_guess[3];
    unsigned int vb_108_guess;
    unsigned char vb_10c_guess;
    unsigned char vb_10d_guess;
    unsigned char vb_10e_guess;
    char pad_10f_guess;
    unsigned int vb_110_guess;
    unsigned int vb_114_guess;
    unsigned char vb_118_guess;
    unsigned char vb_119_guess;
    unsigned char vb_11a_guess;
    char pad_11b_guess;
    unsigned int vb_11c_guess;
    unsigned char vb_120_guess;
    unsigned char vb_121_guess;
    unsigned char vb_122_guess;
    char pad_123_guess;
    unsigned int vb_124_guess;
    unsigned char vb_128_guess;
    char pad_129_guess[3];
    unsigned int vb_12c_guess;
    unsigned int vb_130_guess;
    unsigned int vb_134_guess;
    unsigned int vb_138_guess;
    unsigned int vb_13c_guess;
    unsigned int vb_140_guess;
    unsigned int vb_144_guess;
    unsigned int vb_148_guess;
    // EXTERNAL: TITANIUM 0x00434792 Owner_guess::SetTributeItem_guess
    void SetTributeItem_guess(int index, int value);
    // NOTES "unfolded virtual-base access": the vbase pointer is materialised, then the accessor is at +4.
    Result_guess* AccessorResult_guess() { return accessor_guess.GetCharInfo2(); }
    void Set_indexed_byte_guess(unsigned int index, unsigned char value);
    void Set_indexed_dword_guess(unsigned int index, unsigned int value);
    void SetGender_guess(unsigned char value);
    void SetRace_guess(unsigned int value);
    void SetClass_guess(unsigned char value);
    void Set_11a0_guess(unsigned int value);
    void SetFace_guess(unsigned char value);
    void Set_11f4_guess(unsigned char value);
    void Set_11fc_guess(unsigned int value);
    void Set_1200_guess(unsigned int value);
    void Set_1204_guess(unsigned int value);
    void Set_1208_guess(unsigned int value);
    void Set_1210_guess(unsigned int value);
    void Set_1214_guess(unsigned int value);
    void SetToxicity_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004B91C9 Owner_guess::Set_11fc_guess
    void Set_11fc_guess(float value);
    // EXTERNAL: TITANIUM 0x004B91DE Owner_guess::Set_1200_guess
    void Set_1200_guess(float value);
    // EXTERNAL: TITANIUM 0x004B91F3 Owner_guess::Set_1204_guess
    void Set_1204_guess(float value);
    // EXTERNAL: TITANIUM 0x004B9208 Owner_guess::Set_1208_guess
    void Set_1208_guess(float value);
    // EXTERNAL: TITANIUM 0x00455023 Owner_guess::FUN_00455023_guess
    void FUN_00455023_guess(int value);
    // EXTERNAL: TITANIUM 0x00455038 Owner_guess::FUN_00455038_guess
    void FUN_00455038_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x0045504D Owner_guess::FUN_0045504d_guess
    void FUN_0045504d_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004550A1 Owner_guess::FUN_004550a1_guess
    void FUN_004550a1_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00455077 Owner_guess::FUN_00455077_guess
    void FUN_00455077_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x0045508C Owner_guess::FUN_0045508c_guess
    void FUN_0045508c_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004550B6 Owner_guess::FUN_004550b6_guess
    void FUN_004550b6_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00455062 Owner_guess::FUN_00455062_guess
    void FUN_00455062_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x0043A718 Owner_guess::FUN_0043a718_guess
    void FUN_0043a718_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x0045510A Owner_guess::SetCopperCursor_guess
    void SetCopperCursor_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004550E0 Owner_guess::SetGoldCursor_guess
    void SetGoldCursor_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004550CB Owner_guess::FUN_004550cb_guess
    void FUN_004550cb_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004550F5 Owner_guess::SetSilverCursor_guess
    void SetSilverCursor_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417D5B Owner_guess::FUN_00417d5b_guess
    void FUN_00417d5b_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417D07 Owner_guess::FUN_00417d07_guess
    void FUN_00417d07_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417CDD Owner_guess::FUN_00417cdd_guess
    void FUN_00417cdd_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417D31 Owner_guess::FUN_00417d31_guess
    void FUN_00417d31_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x004586A5 Owner_guess::FUN_004586a5_guess
    void FUN_004586a5_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x0045868B Owner_guess::FUN_0045868b_guess
    void FUN_0045868b_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x0041AA6A Owner_guess::FUN_0041aa6a_guess
    void FUN_0041aa6a_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x0040E75C Owner_guess::FUN_0040e75c_guess
    void FUN_0040e75c_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x0041AA84 Owner_guess::FUN_0041aa84_guess
    void FUN_0041aa84_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x0040CC50 Owner_guess::GetInventorySlot_guess
    Entry_guess* GetInventorySlot_guess(int index);
    // EXTERNAL: TITANIUM 0x0045511F Owner_guess::FUN_0045511f_guess
    void FUN_0045511f_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417CC8 Owner_guess::FUN_00417cc8_guess
    void FUN_00417cc8_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x0040E293 Owner_guess::FUN_0040e293_guess
    void FUN_0040e293_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417D85 Owner_guess::FUN_00417d85_guess
    void FUN_00417d85_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417D9A Owner_guess::FUN_00417d9a_guess
    void FUN_00417d9a_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x00417CB3 Owner_guess::FUN_00417cb3_guess
    void FUN_00417cb3_guess(unsigned int value);
};

// Frees the array member at +0x74 (0x50F3F6).
// FUNCTION: TITANIUM 0x004BA0F3
void Thunk_guess::FUN_004ba0f3() {
    return target_guess.Run_guess();
}

// Frees the array inside the profile buffer's +0x3850 block (the same one ~PlayerProfile_guess frees).
// FUNCTION: TITANIUM 0x004BA88E
void Thunk38_guess::FUN_004ba88e() {
    return target_guess.Run_guess();
}

// After zoning, probably: CDisplay's view angle from the current camera's field of view (+0x40 of entry
// 0x850CCC in 0x9254FC), then UpdateSoundEnvironment_guess and the +0xC280 part's ProcessDrunkenness_guess.
// FUNCTION: TITANIUM 0x004B9111
void PilotOwner_guess::UpdateZoneEnvironment_guess() {
    int amount_guess = (int)g_cameras_guess[gPilotThingIndex_guess]->value_guess;
    gPilotManager_guess->SetValue_guess(amount_guess);
    gPilotManager_guess->Update_guess();
    reinterpret_cast<PilotPart_guess*>(reinterpret_cast<char*>(this) + 0xc280)->ProcessDrunkenness_guess();
}

// Setters on the base profile (Owner_guess accessor). Load_guess feeds them these profile fields:
// Gender.
// FUNCTION: TITANIUM 0x004B914B
void Owner_guess::SetGender_guess(unsigned char value) {
    accessor_guess.GetCharInfo2()->gender_1194_guess = value;
}

// Race.
// FUNCTION: TITANIUM 0x004B9160
void Owner_guess::SetRace_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->race_1198_guess = value;
}

// Class.
// FUNCTION: TITANIUM 0x004B9175
void Owner_guess::SetClass_guess(unsigned char value) {
    accessor_guess.GetCharInfo2()->class_119c_guess = value;
}

// Profile offset 16 (EQEmu unknown00016).
// FUNCTION: TITANIUM 0x004B918A
void Owner_guess::Set_11a0_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_11a0_guess = value;
}

// Face.
// FUNCTION: TITANIUM 0x004B919F
void Owner_guess::SetFace_guess(unsigned char value) {
    accessor_guess.GetCharInfo2()->face_11d0_guess = value;
}

// The byte at profile offset 4424 (unnamed in EQEmu).
// FUNCTION: TITANIUM 0x004B91B4
void Owner_guess::Set_11f4_guess(unsigned char value) {
    accessor_guess.GetCharInfo2()->value_11f4_guess = value;
}

// First of four floats at profile offset 4964 (EQEmu unknown04760). Callers use a float overload at
// this address; the int body stores the bits unchanged.
// FUNCTION: TITANIUM 0x004B91C9
void Owner_guess::Set_11fc_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_11fc_guess = value;
}

// Second float of that block.
// FUNCTION: TITANIUM 0x004B91DE
void Owner_guess::Set_1200_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1200_guess = value;
}

// Third float of that block.
// FUNCTION: TITANIUM 0x004B91F3
void Owner_guess::Set_1204_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1204_guess = value;
}

// Fourth float of that block.
// FUNCTION: TITANIUM 0x004B9208
void Owner_guess::Set_1208_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1208_guess = value;
}

// Profile offset 4988 (unnamed in EQEmu).
// FUNCTION: TITANIUM 0x004B921D
void Owner_guess::Set_1210_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1210_guess = value;
}

// Profile offset 4992 plus the current time (EqGetTime), so probably a timer.
// FUNCTION: TITANIUM 0x004B9232
void Owner_guess::Set_1214_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1214_guess = value;
}

// Toxicity (profile offset 4996).
// FUNCTION: TITANIUM 0x004B9247
void Owner_guess::SetToxicity_guess(unsigned int value) {
    accessor_guess.GetCharInfo2()->value_1220_guess = value;
}

// Rebuilds the client's group from the profile's groupMembers (+0x15B0, six names, you among them):
// member names 0x90424D, flags 0x904248, spawns 0x904390, leader 0x9043A4. Leaving: "Your group has
// been disbanded" (0x2EE2) when you led, else "You have been removed from the group" (0x2EE1).
// Joining: the leader becomes "PENDING" until known, "You have formed/joined the group" (0x2EE3/4),
// and LFG goes off (do_lfg_guess "off", 0x3292) or the group search window drops you. Staying: "%1 has
// joined the group" (0x577) and "%1 has left the group" (0x2EE5) for the differences. Skipped while
// 0x923798 or 0x923884 is set. `missing_guess` is true when the name was found (inverted name).
// FUNCTION: TITANIUM 0x004B925C
// @early-stop: budget, structural ndiff=190
void PcView_guess::UpdateGroupFromProfile_guess() {
    char copies_guess[5][0x40];
    char message_guess[512];
    int hit_guess = 0;
    int slot_guess = 0;
    int member_guess = 0;

    if (gGateFlag_guess == 0 && gGateCount_guess == 0) {
        for (int i = 0; i < 6; ++i) {
            if (names_15b0_guess[i][0] != 0 &&
                FUN_00574950_guess(names_15b0_guess[i], name44_guess + ref8_guess->vbase_offset)) {
                member_guess = 1;
            }
        }
        for (int i = 0; i < 5; ++i) {
            strcpy(copies_guess[i], gSlotNames_guess[i]);
            if (copies_guess[i][0] != 0 &&
                FUN_00574950_guess(name44_guess + ref8_guess->vbase_offset, copies_guess[i])) {
                slot_guess = 1;
            }
            gSlotFlags_guess[i] = 0;
            gSlotValues_guess[i] = 0;
            gSlotNames_guess[i][0] = 0;
        }
        if (slot_guess) {
            if (gPending_guess[0] != 0) {
                for (int i = 0; i < 6; ++i) {
                    if (_stricmp(gPending_guess, names_15b0_guess[i]) == 0) {
                        hit_guess = 1;
                    }
                }
                if (_stricmp(gPending_guess, name44_guess + ref8_guess->vbase_offset) == 0) {
                    hit_guess = 2;
                }
            }
            if (!member_guess) {
                pEverQuest->dsp_chat(pStringTable->getString(hit_guess == 2 ? 0x2ee2 : 0x2ee1, 0), 0x111, 1);
                gPending_guess[0] = 0;
            } else {
                int n = 0;
                for (int i = 0; i < 6; ++i) {
                    if (names_15b0_guess[i][0] != 0 &&
                        FUN_00574950_guess(names_15b0_guess[i], name44_guess + ref8_guess->vbase_offset)) {
                        strcpy(gSlotNames_guess[n], names_15b0_guess[i]);
                        gSlotFlags_guess[n] = 1;
                        gSlotValues_guess[n] = GetSpawnByName_guess(gSlotNames_guess[n]);
                        ++n;
                        if (n >= 5) {
                            break;
                        }
                    }
                }
                for (int k = 0; k < 5; ++k) {
                    bool missing_guess = false;
                    if (gSlotNames_guess[k][0] != 0) {
                        for (int j = 0; j < 5; ++j) {
                            if (FUN_00574950_guess(gSlotNames_guess[k], copies_guess[j]) == 0) {
                                missing_guess = true;
                            }
                        }
                        if (!missing_guess) {
                            FUN_0046da4a_guess(message_guess, 0x577, gSlotNames_guess[k], 0, 0, 0, 0, 0, 0, 0, 0);
                            pEverQuest->dsp_chat(message_guess, 0x111, 1);
                        }
                    }
                }
                for (int j = 0; j < 5; ++j) {
                    bool missing_guess = false;
                    if (copies_guess[j][0] != 0) {
                        for (int k = 0; k < 5; ++k) {
                            if (FUN_00574950_guess(copies_guess[j], gSlotNames_guess[k]) == 0) {
                                missing_guess = true;
                            }
                        }
                        if (!missing_guess) {
                            char* arg_guess = copies_guess[j];
                            FUN_00467441_guess(message_guess, pStringTable->getString(0x2ee5, 0), &arg_guess, -1, 0);
                            pEverQuest->dsp_chat(message_guess, 0x111, 1);
                        }
                    }
                }
            }
        } else if (member_guess) {
            if (gPending_guess[0] == 0) {
                strcpy(gPending_guess, "PENDING");
            }
            pEverQuest->dsp_chat(
                pStringTable->getString(0x2ee3 + (strcmp(gPending_guess, name44_guess + ref8_guess->vbase_offset) != 0), 0),
                0x111, 1);
            if (pinstCGroupSearchWnd_guess == 0) {
                do_lfg_guess(gChatHook_guess, pStringTable->getString(0x3292, 0));
            } else {
                pinstCGroupSearchWnd_guess->RemoveInfoOnGroupChange_guess();
            }
            int n = 0;
            for (int i = 0; i < 6; ++i) {
                if (names_15b0_guess[i][0] != 0 &&
                    FUN_00574950_guess(names_15b0_guess[i], name44_guess + ref8_guess->vbase_offset)) {
                    strcpy(gSlotNames_guess[n], names_15b0_guess[i]);
                    gSlotFlags_guess[n] = 1;
                    gSlotValues_guess[n] = GetSpawnByName_guess(gSlotNames_guess[n]);
                    ++n;
                    if (n >= 5) {
                        break;
                    }
                }
            }
        }
    }
}

// Nine bytes after the face (profile offset 2265, EQEmu unknown02264).
// FUNCTION: TITANIUM 0x004B9679
void Result_guess::Set_indexed_byte_guess(unsigned int index, unsigned char value) {
    /* fake match: the array reference puts `this` in the base register ([ecx+eax+N]); indexing the member
       directly gives [eax+ecx+N] (probe: plain, decayed, pointer and getter forms all swap) */
    unsigned char (&bytes_guess)[9] = value_1164_guess;
    if (index >= 9) {
        __debugbreak();
    }
    bytes_guess[index] = value;
}

// Nine dwords at profile offset 2276 (EQEmu unknown02264).
// FUNCTION: TITANIUM 0x004B9691
void Result_guess::Set_indexed_dword_guess(unsigned int index, unsigned int value) {
    if (index >= 9) {
        __debugbreak();
    }
    value_1170_guess[index] = value;
}

// Forwards to the base profile's byte array (0x4B9679).
// FUNCTION: TITANIUM 0x004B96A9
void Owner_guess::Set_indexed_byte_guess(unsigned int index, unsigned char value) {
    accessor_guess.GetCharInfo2()->Set_indexed_byte_guess(index, value);
}

// Forwards to the base profile's dword array (0x4B9691).
// FUNCTION: TITANIUM 0x004B96C3
void Owner_guess::Set_indexed_dword_guess(unsigned int index, unsigned int value) {
    accessor_guess.GetCharInfo2()->Set_indexed_dword_guess(index, value);
}

// Bind point `index` (0-4, 20 bytes each; 0 is the primary bind).
// FUNCTION: TITANIUM 0x004B96DD
void Result_guess::SetBindPoint_guess(unsigned int index, const Block_guess* value) {
    if (index >= 5) {
        __debugbreak();
    }
    block_128c_guess[index] = *value;
}

// One of 22 dwords at profile offset 180 (the worn item materials among them).
// FUNCTION: TITANIUM 0x004B9701
void Result_guess::Set_indexed_value_guess(unsigned int index, unsigned int value) {
    if (index >= 22) {
        __debugbreak();
    }
    value_12f0_guess[index] = value;
}

// AA slot `index` (0-239): ability id and rank.
// FUNCTION: TITANIUM 0x004B9719
void Result_guess::SetAAEntry_guess(unsigned int index, const Pair_guess* value) {
    Pair_guess* entries = pair_1348_guess;
    if (index >= 240) {
        __debugbreak();
    }
    entries[index] = *value;
}

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int FUN_0046d655_guess();
// EXTERNAL: TITANIUM 0x00576E80 FUN_00576e80_guess
void FUN_00576e80_guess();

struct Entry_guess {
    virtual void Slot00_guess(int flag);
};

struct Core_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int value);
    virtual void Slot02_guess(int value);
    virtual void Slot03_guess(int value);
    unsigned int field_4_guess;
};

struct Deletable_guess {
    virtual ~Deletable_guess();
};

struct Blob4f_guess {
    unsigned int values_guess[0x4f];
};

struct Blob55_guess {
    unsigned int values_guess[0x55];
};

struct Blob58_guess {
    unsigned int values_guess[0x16];
};

struct Pair8_guess {
    unsigned int first_guess;
    unsigned int second_guess;
};

struct Block14_guess {
    unsigned int pad_guess[4];
    unsigned int value_10_guess;
};

struct Blob84_guess {
    char pad_0000_guess[0x74];
    Target_guess target_guess;
};

struct Copyable_guess {
    // EXTERNAL: TITANIUM 0x0045AEFB Copyable_guess::Copy_guess
    void Copy_guess(const Blob84_guess* value);
};

struct ListEntry_guess {
    char name_guess[0x58];
};

struct NameList_guess {
    unsigned int values_guess[4];
    // EXTERNAL: TITANIUM 0x00454F3F NameList_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00454EE0 NameList_guess::Add_guess
    void Add_guess(const char* name, int hash);
};

// EXTERNAL: TITANIUM 0x00574890 FUN_00574890_guess
int __cdecl FUN_00574890_guess(const char* name);

struct Effects_guess {
    // EXTERNAL: TITANIUM 0x0040E7AC Effects_guess::GetBuff_guess
    void* GetBuff_guess(int index);
};

struct PlayerProfile_guess {
    unsigned char b00_guess;
    char pad_01_guess[3];
    unsigned int d04_guess;
    unsigned char b08_guess;
    char pad_09_guess[3];
    unsigned int d0c_guess;
    unsigned char b10_guess;
    unsigned char b11_guess;
    char pad_12_guess[2];
    Result_guess::Block_guess blk14_guess[5];
    unsigned int d78_guess;
    unsigned int d7c_guess;
    unsigned int d80_guess[10];
    unsigned char ba8_guess;
    unsigned char ba9_guess;
    unsigned char baa_guess;
    unsigned char bab_guess;
    unsigned char bac_guess;
    unsigned char bad_guess;
    unsigned char bae_guess;
    char pad_af_guess[1];
    unsigned int db0_guess[22];
    unsigned int d108_guess[9];
    Result_guess::Pair_guess pair12c_guess[240];
    unsigned int d8ac_guess;
    unsigned int d8b0_guess;
    unsigned int d8b4_guess;
    unsigned int d8b8_guess;
    unsigned int d8bc_guess;
    unsigned int d8c0_guess;
    unsigned int d8c4_guess;
    unsigned int d8c8_guess;
    unsigned int d8cc_guess;
    unsigned int d8d0_guess;
    unsigned char b8d4_guess;
    unsigned char b8d5_guess[9];
    char pad_8de_guess[2];
    unsigned int d8e0_guess[9];
    unsigned int d904_guess[512];
    unsigned int d1104_guess[16];
    unsigned char b1144_guess;
    char pad_1145_guess[3];
    unsigned int d1148_guess;
    unsigned int d114c_guess;
    unsigned int d1150_guess;
    unsigned int d1154_guess;
    unsigned int d1158_guess;
    unsigned int d115c_guess;
    unsigned int d1160_guess;
    unsigned int d1164_guess;
    unsigned int d1168_guess[100];
    unsigned int d12f8_guess[25];
    unsigned char b135c_guess;
    char pad_135d_guess[3];
    float f1360_guess;
    float f1364_guess;
    float f1368_guess;
    float f136c_guess;
    unsigned int d1370_guess;
    unsigned int d1374_guess;
    unsigned int d1378_guess;
    unsigned int d137c_guess;
    unsigned int d1380_guess;
    unsigned int d1384_guess;
    unsigned int d1388_guess;
    unsigned char blk138c_guess[25][0x14];
    unsigned char d1580_guess[0x190];
    unsigned int d1710_guess[20];
    unsigned int d1760_guess[20];
    unsigned int d17b0_guess[20];
    unsigned int d1800_guess;
    unsigned int d1804_guess;
    unsigned int d1808_guess;
    unsigned char b180c_guess;
    unsigned char b180d_guess;
    char pad_180e_guess[2];
    unsigned char blk1810_guess[20][0x140];
    unsigned char blk3110_guess[4][0x48];
    unsigned int d3230_guess;
    unsigned int d3234_guess;
    unsigned int d3238_guess;
    unsigned int d323c_guess;
    unsigned int d3240_guess;
    unsigned int d3244_guess;
    unsigned int d3248_guess;
    unsigned int d324c_guess;
    unsigned int d3250_guess;
    unsigned int d3254_guess;
    unsigned int d3258_guess;
    unsigned int d325c_guess;
    unsigned int d3260_guess;
    unsigned int d3264_guess;
    unsigned int d3268_guess;
    unsigned int d326c_guess;
    unsigned int d3270_guess;
    unsigned int d3274_guess;
    unsigned int d3278_guess;
    unsigned int d327c_guess;
    unsigned int d3280_guess;
    unsigned int d3284_guess;
    char name3288_guess[0x40];
    char text32c8_guess[0x20];
    unsigned int d32e8_guess;
    unsigned int d32ec_guess;
    unsigned int d32f0_guess;
    unsigned int d32f4_guess;
    unsigned char b32f8_guess;
    unsigned char b32f9_guess;
    unsigned char b32fa_guess;
    unsigned char b32fb_guess;
    unsigned int d32fc_guess;
    unsigned int d3300_guess;
    unsigned int pad_3304_guess;
    unsigned int d3308_guess;
    unsigned int d330c_guess;
    unsigned char b3310_guess;
    char pad_3311_guess[3];
    unsigned int d3314_guess;
    char name3318_guess[0x20];
    float f3338_guess;
    float f333c_guess;
    float f3340_guess;
    float f3344_guess;
    unsigned char b3348_guess;
    char pad_3349_guess[3];
    unsigned int d334c_guess;
    unsigned int d3350_guess;
    unsigned int d3354_guess;
    unsigned int d3358_guess;
    unsigned int d335c_guess;
    unsigned int d3360_guess;
    unsigned int d3364_guess;
    unsigned int d3368_guess;
    unsigned int d336c_guess;
    unsigned int d3370_guess;
    char name3374_guess[0x40];
    unsigned int d33b4_guess;
    unsigned char b33b8_guess;
    unsigned char b33b9_guess;
    unsigned char b33ba_guess;
    char pad_33bb_guess;
    unsigned int d33bc_guess;
    unsigned int d33c0_guess;
    unsigned char b33c4_guess;
    unsigned char b33c5_guess;
    unsigned char b33c6_guess;
    char pad_33c7_guess;
    unsigned int d33c8_guess;
    unsigned char b33cc_guess;
    unsigned char b33cd_guess;
    unsigned char b33ce_guess;
    char pad_33cf_guess;
    unsigned int d33d0_guess;
    unsigned char b33d4_guess;
    char pad_33d5_guess[3];
    unsigned int d33d8_guess;
    char names33dc_guess[6][0x40];
    char name355c_guess[0x40];
    Blob4f_guess blob359c_guess;
    Blob55_guess blob36d8_guess;
    unsigned int d382c_guess;
    unsigned char b3830_guess;
    char pad_3831_guess[3];
    unsigned int d3834_guess[6];
    unsigned int d384c_guess;
    Blob84_guess blob3850_guess;
    unsigned int d38d4_guess;
    unsigned int d38d8_guess;
    unsigned int d38dc_guess;
    unsigned int d38e0_guess;
    unsigned int d38e4_guess;
    unsigned char b38e8_guess;
    char pad_38e9_guess[3];
    Pair8_guess pairs38ec_guess[5];
    unsigned int pad_3914_guess;
    double g3918_guess;
    double g3920_guess;
    unsigned int d3928_guess;
    unsigned int d392c_guess;
    unsigned int d3930_guess[0x40];
    unsigned int d3a30_guess;
    unsigned int d3a34_guess;
    unsigned int d3a38_guess;
    unsigned int d3a3c_guess;
    unsigned int d3a40_guess;
    unsigned int d3a44_guess;
    unsigned int d3a48_guess;
    unsigned int d3a4c_guess;
    Blob58_guess blob3a50_guess;
    Blob58_guess blob3aa8_guess;
    int count3b00_guess;
    ListEntry_guess entries3b04_guess[50];
    unsigned int d4c34_guess;
    unsigned int d4c38_guess;
    unsigned int d4c3c_guess;
    unsigned int d4c40_guess;
    unsigned int d4c44_guess;
    unsigned int d4c48_guess;
    unsigned int d4c4c_guess;
    unsigned int d4c50_guess;
    int d4c54_guess;
    unsigned int d4c58_guess;
    unsigned int d4c5c_guess;
    unsigned int d4c60_guess;
    unsigned int d4c64_guess;
    unsigned int d4c68_guess;
    unsigned int d4c6c_guess;
    unsigned char b4c70_guess;
    unsigned char b4c71_guess;
    unsigned char b4c72_guess;
    char pad_4c73_guess;
    unsigned int d4c74_guess;
    unsigned char b4c78_guess;
    ~PlayerProfile_guess() { blob3850_guess.target_guess.Run_guess(); }
};

struct PacketBuffer_guess {
    PlayerProfile_guess src_guess;
};

#pragma pack(push, 4)
struct Pc_guess : Core_guess, virtual Owner_guess {
    char pad_000c_guess[0x104 - 0xC];
    unsigned char field_104_guess;
    char pad_105_guess[0xCF0 - 0x105];
    BoundedArray_guess<Deletable_guess*, 16> owned_cf0_guess;
    BoundedArray_guess<Deletable_guess*, 2> owned_d30_guess;
    char pad_d38_guess[0xE0C - 0xD38];
    unsigned int field_e0c_guess;
    unsigned char field_e10_guess;
    char pad_e11_guess[3];
    unsigned int field_e14_guess;
    unsigned int field_e18_guess;
    unsigned int field_e1c_guess;
    unsigned int field_e20_guess;
    unsigned char field_e24_guess;
    bool field_e25_guess;
    char pad_e26_guess[2];
    unsigned int field_e28_guess;
    unsigned int pad_e2c_guess;
    unsigned int field_e30_guess;
    unsigned int pad_e34_guess[2];
    unsigned int field_e3c_guess;
    unsigned int field_e40_guess;
    unsigned int field_e44_guess;
    unsigned int field_e48_guess;
    unsigned int field_e4c_guess;
    int field_e50_guess;
    unsigned int field_e54_guess;
    unsigned int pad_e58_guess[6];
    unsigned int field_e70_guess;
    unsigned int pad_e74_guess;
    unsigned int field_e78_guess;
    unsigned int field_e7c_guess;
    unsigned int field_e80_guess;
    unsigned int field_e84_guess;
    unsigned char field_e88_guess;
    char pad_e89_guess[7];
    double field_e90_guess;
    double field_e98_guess;
    unsigned int field_ea0_guess;
    unsigned int field_ea4_guess;
    bool field_ea8_guess;
    char pad_ea9_guess[3];
    unsigned int field_eac_guess;
    unsigned int field_eb0_guess;
    unsigned int field_eb4_guess;
    unsigned int field_eb8_guess;
    unsigned int field_ebc_guess;
    unsigned int field_ec0_guess;
    unsigned int field_ec4_guess;
    Blob58_guess blob_ec8_guess;
    Blob58_guess blob_f20_guess;
    NameList_guess list_f78_guess;
    unsigned int field_f88_guess;
    unsigned int field_f8c_guess;
    unsigned int pad_f90_guess[5];
    unsigned int field_fa4_guess;
    unsigned int field_fa8_guess;
    unsigned int field_fac_guess;
    unsigned int field_fb0_guess;
    unsigned int field_fb4_guess;
    unsigned int field_fb8_guess;
    char pad_fbc_guess[0x103C - 0xFBC];
    unsigned int field_103c_guess;
    unsigned int pad_1040_guess[2];
    Block14_guess blocks_1048_guess[6];
    Copyable_guess copy_10c0_guess;
    char pad_10c1_guess[0x1770 - 0x10C1];
    Blob4f_guess blob_1770_guess;
    Blob55_guess blob_18ac_guess;
    unsigned int field_1a00_guess;
    unsigned int field_1a04_guess;
    unsigned int field_1a08_guess;
    unsigned int pad_1a0c_guess;
    unsigned int field_1a10_guess;
    unsigned int field_1a14_guess;
    unsigned int field_1a18_guess;
    char pad_1a1c_guess[0x1A58 - 0x1A1C];
    unsigned int field_1a58_guess;
    unsigned char field_1a5c_guess;
    char pad_1a5d_guess[0xC280 - 0x1A5D];
    Effects_guess effects_c280_guess;
    char pad_c281_guess[0xC348 - 0xC281];
    unsigned char field_c348_guess;
    char pad_c349_guess[0xC350 - 0xC349];
    unsigned char field_c350_guess;
    // EXTERNAL: TITANIUM 0x005ED490 Pc_guess::GetResult_guess
    Result_guess* GetResult_guess();
    // EXTERNAL: TITANIUM 0x005F09D0 Pc_guess::FUN_005f09d0_guess
    void FUN_005f09d0_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x005F0A80 Pc_guess::FUN_005f0a80_guess
    void FUN_005f0a80_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x005F0AE0 Pc_guess::FUN_005f0ae0_guess
    void FUN_005f0ae0_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x005F0B40 Pc_guess::FUN_005f0b40_guess
    void FUN_005f0b40_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x005F0BA0 Pc_guess::FUN_005f0ba0_guess
    void FUN_005f0ba0_guess(int index, unsigned int value);
    // EXTERNAL: TITANIUM 0x005F0D00 Pc_guess::FUN_005f0d00_guess
    void FUN_005f0d00_guess(int index, const void* value);
    // EXTERNAL: TITANIUM 0x005F0C60 Pc_guess::FUN_005f0c60_guess
    void FUN_005f0c60_guess(int index, const void* value);
    // EXTERNAL: TITANIUM 0x005ED6F0 Pc_guess::FUN_005ed6f0_guess
    void FUN_005ed6f0_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5F0 Pc_guess::FUN_005ed5f0_guess
    void FUN_005ed5f0_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED6B0 Pc_guess::FUN_005ed6b0_guess
    void FUN_005ed6b0_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED5B0 Pc_guess::FUN_005ed5b0_guess
    void FUN_005ed5b0_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED630 Pc_guess::FUN_005ed630_guess
    void FUN_005ed630_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED670 Pc_guess::FUN_005ed670_guess
    void FUN_005ed670_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED710 Pc_guess::FUN_005ed710_guess
    void FUN_005ed710_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED530 Pc_guess::FUN_005ed530_guess
    void FUN_005ed530_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED860 Pc_guess::FUN_005ed860_guess
    void FUN_005ed860_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED820 Pc_guess::FUN_005ed820_guess
    void FUN_005ed820_guess(unsigned char value);
    // EXTERNAL: TITANIUM 0x005ED4D0 Pc_guess::SetDeity_guess
    void SetDeity_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED570 Pc_guess::FUN_005ed570_guess
    void FUN_005ed570_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED8A0 Pc_guess::FUN_005ed8a0_guess
    void FUN_005ed8a0_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED8E0 Pc_guess::FUN_005ed8e0_guess
    void FUN_005ed8e0_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED7B0 Pc_guess::FUN_005ed7b0_guess
    void FUN_005ed7b0_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED750 Pc_guess::FUN_005ed750_guess
    void FUN_005ed750_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED920 Pc_guess::FUN_005ed920_guess
    void FUN_005ed920_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005ED900 Pc_guess::FUN_005ed900_guess
    void FUN_005ed900_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005EE550 Pc_guess::FUN_005ee550_guess
    size_t FUN_005ee550_guess();
    // EXTERNAL: TITANIUM 0x005F0A30 Pc_guess::FUN_005f0a30_guess
    void* FUN_005f0a30_guess();

    // EXTERNAL: TITANIUM 0x005ED4F0 Pc_guess::FUN_005ed4f0_guess
    void FUN_005ed4f0_guess(bool value);
    // EXTERNAL: TITANIUM 0x005F0E20 Pc_guess::FUN_005f0e20_guess
    void FUN_005f0e20_guess(int index, int value);
    // EXTERNAL: TITANIUM 0x00451A65 Pc_guess::ClearGroupMemberNames_guess
    void ClearGroupMemberNames_guess();
    // EXTERNAL: TITANIUM 0x0045871F Pc_guess::FUN_0045871f_guess
    void FUN_0045871f_guess();
    // EXTERNAL: TITANIUM 0x0046484B Pc_guess::SetGroupMemberName_guess
    void SetGroupMemberName_guess(int index, const char* name);
    // EXTERNAL: TITANIUM 0x00464889 Pc_guess::SetGroupLeaderName_guess
    void SetGroupLeaderName_guess(const char* name);
    // EXTERNAL: TITANIUM 0x005F0DB0 Pc_guess::FUN_005f0db0_guess
    void FUN_005f0db0_guess(int index, const Pair8_guess* value);
    // EXTERNAL: TITANIUM 0x004586BF Pc_guess::FUN_004586bf_guess
    void FUN_004586bf_guess(int index, unsigned int value);

    void LoadBaseProfile_guess(PlayerProfile_guess* src);
    void LoadProfile_guess(PlayerProfile_guess* src);
    // EXTERNAL: TITANIUM 0x005EE500 Pc_guess::HasFlag_guess
    int HasFlag_guess(int index_guess);
    void Handle_OP_PlayerProfile_guess(const unsigned int* packet_guess, int size_guess);
};
#pragma pack(pop)

// Copies the base-profile part: identity, stats, money, skills, spell book and gems, buffs, binds, AAs,
// disciplines, recast timers, bandoliers and potion belt. `base_guess` (EqGetTime) turns the spell-gem and
// ability refresh times (profile 132-171) and one timer into absolute times.
// FUNCTION: TITANIUM 0x004B9741
void Pc_guess::LoadBaseProfile_guess(PlayerProfile_guess* src) {
    int base_guess = FUN_0046d655_guess();
    AccessorResult_guess()->Slot01_guess();
    FUN_00455023_guess(src->b10_guess);
    SetClass_guess(src->b08_guess);
    FUN_00455038_guess(src->d8b8_guess);
    FUN_0045504d_guess(src->d8bc_guess);
    FUN_004550a1_guess(src->d8cc_guess);
    FUN_00455077_guess(src->d8c4_guess);
    FUN_0045508c_guess(src->d8c8_guess);
    FUN_004550b6_guess(src->d8d0_guess);
    FUN_00455062_guess(src->d8c0_guess);
    SetRace_guess(src->d04_guess);
    SetGender_guess(src->b00_guess);
    Set_11a0_guess(src->d0c_guess);
    SetFace_guess(src->b8d4_guess);
    FUN_005ed6f0_guess(src->bad_guess);
    FUN_005ed5f0_guess(src->ba9_guess);
    Set_11fc_guess(src->f1360_guess);
    FUN_005ed6b0_guess(src->bac_guess);
    FUN_005ed5b0_guess(src->ba8_guess);
    FUN_005ed630_guess(src->baa_guess);
    FUN_005ed670_guess(src->bab_guess);
    FUN_005ed710_guess(src->bae_guess);
    FUN_0043a718_guess(src->b135c_guess);
    for (int i = 0; i < 9; i++) {
        Set_indexed_byte_guess(i, src->b8d5_guess[i]);
    }
    for (int j = 0; j < 22; j++) {
        GetResult_guess()->Set_indexed_value_guess(j, src->db0_guess[j]);
    }
    for (int k = 0; k < 9; k++) {
        FUN_005f09d0_guess(k, src->d108_guess[k]);
    }
    for (int m = 0; m < 9; m++) {
        Set_indexed_dword_guess(m, src->d8e0_guess[m]);
    }
    SetCopperCursor_guess(src->d1164_guess);
    SetGoldCursor_guess(src->d115c_guess);
    FUN_004550cb_guess(src->d1158_guess);
    SetSilverCursor_guess(src->d1160_guess);
    FUN_00417d5b_guess(src->d1154_guess);
    FUN_00417d07_guess(src->d114c_guess);
    FUN_00417cdd_guess(src->d1148_guess);
    FUN_00417d31_guess(src->d1150_guess);
    Set_11f4_guess(src->b1144_guess);
    for (int n = 0; n < 16; n++) {
        FUN_004586a5_guess(n, src->d1104_guess[n]);
    }
    for (int p = 0; p < 512; p++) {
        FUN_0045868b_guess(p, src->d904_guess[p]);
    }
    for (int q = 0; q < 240; q++) {
        GetResult_guess()->SetAAEntry_guess(q, &src->pair12c_guess[q]);
    }
    field_c350_guess = 0;
    for (int r = 0; r < 100; r++) {
        FUN_0041aa6a_guess(r, src->d1168_guess[r]);
    }
    for (int s = 0; s < 10; s++) {
        FUN_005f0a80_guess(s, src->d80_guess[s] + base_guess);
    }
    for (int t = 0; t < 25; t++) {
        memcpy(effects_c280_guess.GetBuff_guess(t), src->blk138c_guess[t], 0x14);
    }
    field_c348_guess = 0;
    FUN_0045511f_guess(src->d8ac_guess);
    for (int u = 0; u < 5; u++) {
        GetResult_guess()->SetBindPoint_guess(u, &src->blk14_guess[u]);
    }
    FUN_00417cc8_guess(src->d8b4_guess);
    FUN_0040e293_guess(src->d8b0_guess);
    SetDeity_guess(src->d78_guess);
    Set_1210_guess(src->d1378_guess);
    FUN_00417d85_guess(src->d1384_guess);
    FUN_00417d9a_guess(src->d1388_guess);
    Set_1214_guess(src->d137c_guess + base_guess);
    SetToxicity_guess(src->d1380_guess);
    FUN_005ed530_guess(src->b11_guess);
    for (int v = 0; v < 25; v++) {
        FUN_0040e75c_guess(v, src->d12f8_guess[v]);
    }
    Set_1204_guess(src->f1368_guess);
    FUN_005ed8a0_guess(src->d1370_guess);
    FUN_005ed8e0_guess(src->d1374_guess);
    FUN_005ed570_guess(src->d7c_guess);
    Set_1208_guess(src->f136c_guess);
    Set_1200_guess(src->f1364_guess);
    for (int w = 0; w < 31; w++) {
        if (GetInventorySlot_guess(w) != 0) {
            Entry_guess* e = GetInventorySlot_guess(w);
            if (e != 0) {
                e->Slot00_guess(1);
            }
        }
        FUN_0041aa84_guess(w, 0);
    }
    memcpy(FUN_005f0a30_guess(), src->d1580_guess, FUN_005ee550_guess());
    for (int x = 0; x < 20; x++) {
        FUN_005f0ae0_guess(x, src->d1710_guess[x]);
    }
    for (int y = 0; y < 20; y++) {
        FUN_005f0b40_guess(y, src->d1760_guess[y]);
    }
    FUN_00576e80_guess();
    for (int z = 0; z < 20; z++) {
        FUN_005f0ba0_guess(z, src->d17b0_guess[z]);
    }
    if (pinstCCombatAbilityWnd_guess != 0) {
        pinstCCombatAbilityWnd_guess->Run_guess();
    }
    FUN_00417cb3_guess(src->d1800_guess);
    FUN_005ed7b0_guess(src->d1804_guess);
    FUN_005ed750_guess(src->d1808_guess);
    FUN_005ed860_guess(src->b180d_guess);
    FUN_005ed820_guess(src->b180c_guess);
    for (int a = 0; a < 4; a++) {
        FUN_005f0d00_guess(a, src->blk3110_guess[a]);
    }
    for (int b = 0; b < 20; b++) {
        FUN_005f0c60_guess(b, src->blk1810_guess[b]);
    }
    FUN_005ed920_guess(src->d3230_guess);
    AccessorResult_guess()->value_1228_guess = src->d3234_guess;
    FUN_005ed900_guess(src->d3238_guess);
    AccessorResult_guess()->value_123c_guess = src->d323c_guess;
    AccessorResult_guess()->value_1244_guess = src->d3244_guess;
    AccessorResult_guess()->value_1240_guess = src->d3240_guess;
    AccessorResult_guess()->value_1250_guess = src->d3248_guess;
    AccessorResult_guess()->value_124c_guess = src->d324c_guess;
    AccessorResult_guess()->value_1248_guess = src->d3250_guess;
    AccessorResult_guess()->value_1254_guess = src->d3254_guess;
    AccessorResult_guess()->value_1258_guess = src->d3258_guess;
    AccessorResult_guess()->value_125c_guess = src->d325c_guess;
    AccessorResult_guess()->value_1260_guess = src->d3260_guess;
    AccessorResult_guess()->value_1264_guess = src->d3264_guess;
    AccessorResult_guess()->value_1268_guess = src->d3268_guess;
    AccessorResult_guess()->value_126c_guess = src->d326c_guess;
    AccessorResult_guess()->value_1270_guess = src->d3270_guess;
    AccessorResult_guess()->value_1274_guess = src->d3274_guess;
    AccessorResult_guess()->value_1278_guess = src->d3278_guess;
    AccessorResult_guess()->value_127c_guess = src->d327c_guess;
    AccessorResult_guess()->value_1284_guess = src->d3284_guess;
    AccessorResult_guess()->value_1280_guess = src->d3280_guess;
}

// Copies the rest: name, last name, languages (into the 32-char +0x0C field), position, guild and bank,
// group names and leader, LDoN points, tribute, leadership, air, PVP stats, AA exp, crystals and
// autoconsent (virtual slots 1-3).
// Position: +0x2C gets the profile's x and is then overwritten with z; y goes to +0x30 and +0x34 is never
// written. A decomp error or an original bug (early stop, ndiff 8); check the asm.
// FUNCTION: TITANIUM 0x004BA0FB
// @early-stop: budget, structural ndiff=8
void Pc_guess::LoadProfile_guess(PlayerProfile_guess* src) {
    Blob58_guess temp_guess;
    int i;

    VbSlot03_guess();
    LoadBaseProfile_guess(src);
    vb_name_03c_guess.Set_guess(src->name3288_guess);
    vb_text_07c_guess.Set_guess(src->text32c8_guess);
    field_1a00_guess = src->d336c_guess;
    field_1a04_guess = src->d3370_guess;
    field_1a18_guess = src->d3314_guess;
    vb_148_guess = src->d3358_guess;
    vb_140_guess = src->d3350_guess;
    vb_13c_guess = src->d334c_guess;
    vb_144_guess = src->d3354_guess;
    vb_138_guess = src->d3368_guess;
    vb_130_guess = src->d3360_guess;
    vb_12c_guess = src->d335c_guess;
    vb_134_guess = src->d3364_guess;
    vb_100_guess = src->d33d8_guess;
    // The position quirk the function comment describes: +0x2C is written twice and +0x34 never.
    vb_y_02c_guess = src->f3338_guess;
    vb_x_030_guess = src->f333c_guess;
    vb_y_02c_guess = src->f3340_guess;
    vb_heading_038_guess = src->f3344_guess;
    field_e30_guess = src->d3a30_guess;
    field_e24_guess = src->b32f9_guess;
    field_e18_guess = src->d32ec_guess;
    field_1a10_guess = src->d3308_guess;
    field_1a14_guess = src->d330c_guess;
    vb_108_guess = src->d33b4_guess;
    vb_10c_guess = src->b33b8_guess;
    vb_10d_guess = src->b33b9_guess;
    vb_10e_guess = src->b33ba_guess;
    vb_110_guess = src->d33bc_guess;
    vb_114_guess = src->d33c0_guess;
    vb_118_guess = src->b33c4_guess;
    vb_119_guess = src->b33c5_guess;
    vb_11a_guess = src->b33c6_guess;
    vb_11c_guess = src->d33c8_guess;
    vb_120_guess = src->b33cc_guess;
    vb_121_guess = src->b33cd_guess;
    vb_122_guess = src->b33ce_guess;
    vb_124_guess = src->d33d0_guess;
    vb_128_guess = src->b33d4_guess;
    field_e25_guess = src->b32fa_guess != 0;
    field_e0c_guess = src->d32e8_guess;
    field_e10_guess = src->b32fb_guess;
    field_e14_guess = src->d32fc_guess;
    for (i = 0; i < 32; i++) {
        languages_000c_guess.Set_guess(i, src->name3318_guess[i]);
    }
    field_e1c_guess = src->d32f0_guess;
    field_e20_guess = src->d32f4_guess;
    FUN_005ed4f0_guess(src->b32f8_guess != 0);
    vb_104_guess = src->b3348_guess;
    vb_0fc_guess = src->b3310_guess;
    field_1a08_guess = src->d3300_guess;
    vb_name_0bc_guess.Set_guess(src->name3374_guess);
    for (i = 0; i < 6; i++) {
        blocks_1048_guess[i].value_10_guess = src->d3834_guess[i];
    }
    field_103c_guess = src->d384c_guess;
    copy_10c0_guess.Copy_guess(&src->blob3850_guess);
    for (i = 0; i < 5; i++) {
        SetTributeItem_guess(i, 0);
    }
    for (i = 0; i < 2; i++) {
        FUN_005f0e20_guess(i, 0);
    }
    // The 16 bank and 2 shared-bank items held are freed; the item packets fill them again.
    for (i = 0; i < 16; i++) {
        if (owned_cf0_guess[i]) {
            delete owned_cf0_guess[i];
        }
        owned_cf0_guess[i] = 0;
    }
    for (i = 0; i < 2; i++) {
        if (owned_d30_guess[i]) {
            delete owned_d30_guess[i];
        }
        owned_d30_guess[i] = 0;
    }
    ClearGroupMemberNames_guess();
    FUN_0045871f_guess();
    for (i = 0; i < 6; i++) {
        // Group member names, six slots, empty names skipped.
        if (src->names33dc_guess[i][0]) {
            SetGroupMemberName_guess(i, src->names33dc_guess[i]);
        }
    }
    SetGroupLeaderName_guess(src->name355c_guess);
    blob_1770_guess = src->blob359c_guess;
    blob_18ac_guess = src->blob36d8_guess;
    field_e54_guess = src->d382c_guess;
    field_ea8_guess = src->b3830_guess != 0;
    field_e70_guess = src->d38d4_guess;
    field_e78_guess = src->d38d8_guess;
    field_e7c_guess = src->d38dc_guess;
    field_e80_guess = src->d38e0_guess;
    field_e84_guess = src->d38e4_guess;
    field_e88_guess = src->b38e8_guess;
    for (i = 0; i < 5; i++) {
        FUN_005f0db0_guess(i, &src->pairs38ec_guess[i]);
    }
    FUN_00576e80_guess();
    field_e90_guess = src->g3918_guess;
    field_e98_guess = src->g3920_guess;
    field_ea0_guess = src->d3928_guess;
    field_ea4_guess = src->d392c_guess;
    for (i = 0; i < 0x40; i++) {
        FUN_004586bf_guess(i, src->d3930_guess[i]);
    }
    field_eb4_guess = src->d3a3c_guess;
    field_eb0_guess = src->d3a38_guess;
    field_eac_guess = src->d3a34_guess;
    field_eb8_guess = src->d3a40_guess;
    field_ebc_guess = src->d3a44_guess;
    field_ec0_guess = src->d3a48_guess;
    field_ec4_guess = src->d3a4c_guess;
    temp_guess = src->blob3a50_guess;
    blob_ec8_guess = temp_guess;
    temp_guess = src->blob3aa8_guess;
    blob_f20_guess = temp_guess;
    list_f78_guess.Clear_guess();
    for (i = 0; i < src->count3b00_guess; i++) {
        list_f78_guess.Add_guess(src->entries3b04_guess[i].name_guess,
            FUN_00574890_guess(src->entries3b04_guess[i].name_guess));
    }
    field_e28_guess = src->d4c34_guess;
    field_e3c_guess = src->d4c40_guess;
    field_e40_guess = src->d4c44_guess;
    field_e44_guess = src->d4c48_guess;
    field_e48_guess = src->d4c4c_guess;
    field_e4c_guess = src->d4c50_guess;
    field_e50_guess = src->d4c54_guess + gPilotManager_guess->field_148_guess;
    field_f88_guess = src->d4c38_guess;
    field_f8c_guess = src->d4c3c_guess;
    field_fa4_guess = src->d4c58_guess;
    field_fa8_guess = src->d4c5c_guess;
    field_fac_guess = src->d4c60_guess;
    field_fb4_guess = src->d4c68_guess;
    field_fb0_guess = src->d4c64_guess;
    field_fb8_guess = src->d4c6c_guess;
    Slot01_guess(src->b4c70_guess);
    Slot02_guess(src->b4c71_guess);
    Slot03_guess(src->b4c72_guess);
    field_1a58_guess = src->d4c74_guess;
    field_1a5c_guess = src->b4c78_guess;
}

// OP_PlayerProfile handler: the packet must be 0x4C88 bytes (EQEmu sizeof(PlayerProfile_Struct)) and
// MemChecker0 over its 0x4C80 data bytes must equal the leading checksum, else corrupt-PC error [2] (size)
// or "[3]" (checksum) and a disconnect (game state 0xFF, 0x923794 = 0xFD). On success it loads the
// profile, sets CDisplay +0x11 to 1-4 for the first of four profile flags (base +0x11E4) that is set,
// rebuilds the group and gives 30 entries of 0x850CB8 their profile flag (HasFlag_guess).
// FUNCTION: TITANIUM 0x004BA899
// @early-stop: unknown, structural ndiff=158
void Pc_guess::Handle_OP_PlayerProfile_guess(const unsigned int* packet_guess, int size_guess) {
    PacketBuffer_guess buffer_guess;

    memset(&buffer_guess, 0, 0x4c80);
    if (size_guess == 0x4c88 &&
        MemChecker0(packet_guess + 1, 0x4c80) == (int)packet_guess[0]) {
        memcpy(&buffer_guess, packet_guess + 1, 0x4c80);
        LoadProfile_guess(&buffer_guess.src_guess);
        field_c348_guess = 0;
        if (gPilotManager_guess != 0) {
            if (AccessorResult_guess()->value_11e4_guess[0] != 0) {
                gPilotManager_guess->state_11_guess = 1;
            } else if (AccessorResult_guess()->value_11e4_guess[1] != 0) {
                gPilotManager_guess->state_11_guess = 2;
            } else if (AccessorResult_guess()->value_11e4_guess[2] != 0) {
                gPilotManager_guess->state_11_guess = 3;
            } else if (AccessorResult_guess()->value_11e4_guess[3] != 0) {
                gPilotManager_guess->state_11_guess = 4;
            }
        }
        reinterpret_cast<PcView_guess*>(this)->UpdateGroupFromProfile_guess();
        field_104_guess = 0;
        if (pinstCInvSlotMgr_guess != 0) {
            for (int i_guess = 0; i_guess < 0x1e; ++i_guess) {
                Candidate_guess* candidate_guess = pinstCInvSlotMgr_guess->FindInvSlot(i_guess);
                if (candidate_guess != 0) {
                    candidate_guess->Apply_guess(HasFlag_guess(i_guess));
                }
            }
        }
    } else {
        if (size_guess == 0x4c88) {
            FUN_00574110_guess("ERROR: Corrupt PC [3], disconnecting.\n");
        } else {
            FUN_00574110_guess("ERROR: Corrupt PC [2], disconnecting.\n");
        }
        gGameState_guess->field_39400_guess = 1;
        gGameState_guess->SetGameState(0xff);
        gDisconnectState_guess = 0xfd;
        gGameState_guess->field_b50_guess = 1;
        if (gConnection_guess != 0) {
            gConnection_guess->Stop_guess(0);
            gConnection_guess->Wait_guess(10000);
            gConnection_guess->Slot01_guess();
            gConnection_guess = 0;
        }
    }
}

