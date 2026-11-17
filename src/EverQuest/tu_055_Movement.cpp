// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 55: a hint from compare/tumap.py.
// EQPlayer movement: MovePlayer, floor and ceiling probes, falling and under-world recovery, region (water,
// lava, PvP arena) changes, warps (OP_ClientUpdate) and the teleport-text parser. State_*,
// Player_48BA76_guess and Actor_489BF5_guess are views of EQPlayer; pActorInfo_01a8_guess is pActorInfo.
// Stand states are chars: 'n' sitting, 'o' crouching, 'f' feigned, 'i' looting, 'x' dead.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct Data_4898_guess {
    unsigned int actorInstance_0000_guess;
    unsigned char unknown_004[0x44];
    float floorHeight_0048_guess;
    float value_04c_guess;
    unsigned char unknown_050[0x1c];
    unsigned int value_06c_guess;
    unsigned char unknown_070[0x3d];
    unsigned char value_0ad_guess;
    unsigned char unknown_0ae[0x12];
    float value_0c0_guess;
    unsigned char unknown_0c4[0x94];
    int value_158_guess;
    int mount_015c_guess;
    int rider_0160_guess;
    unsigned char unknown_164[0x4c];
    float value_1b0_guess;
    unsigned char unknown_1b4[0xde0];
    int value_f94_guess;
};

struct Trig_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float angle_guess);
    virtual float Cos_guess(float angle_guess);
};

#define g_trig_guess EQ_GLOBAL(Trig_guess*, 0x0099E374)

struct Vector_48A324_guess;

struct Display_48A026_guess {
    unsigned char unknown_000[0x05];
    char value_005_guess;
    unsigned char unknown_006[0x0f];
    char message_015_guess;
    unsigned char unknown_016[0x106];
    Vector_48A324_guess* probe_11c_guess;
    unsigned char unknown_120[0x28];
    unsigned int time_148_guess;

    // EXTERNAL: TITANIUM 0x0043A371 Display_48A026_guess::UpdateActor_guess
    void UpdateActor_guess(void* data_guess, int* values_guess);
    // EXTERNAL: TITANIUM 0x0043D9C5 Display_48A026_guess::UpdatePosition_guess
    void UpdatePosition_guess(void* data_guess, Vector_48A324_guess* position_guess);
    // EXTERNAL: TITANIUM 0x004365DB Display_48A026_guess::FixHeading_guess
    float FixHeading_guess(float value_guess);

    // EXTERNAL: TITANIUM 0x0043745D Display_48A026_guess::GetValue2cf8_guess
    int GetValue2cf8_guess();
    // EXTERNAL: TITANIUM 0x0043A292 Display_48A026_guess::GetEnvironment_guess
    bool GetEnvironment_guess(float x_guess, float y_guess, float z_guess, int* flag_guess);
    // EXTERNAL: TITANIUM 0x00439F26 Display_48A026_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x_guess, float y_guess, float z_guess);
    // EXTERNAL: TITANIUM 0x0043A0A0 Display_48A026_guess::GetCeilingHeight_guess
    float GetCeilingHeight_guess(float x_guess, float y_guess, float z_guess, float height_guess);
    // EXTERNAL: TITANIUM 0x0043A15C Display_48A026_guess::s3dCollideSphereWithWorld_guess
    char s3dCollideSphereWithWorld_guess(float start_x_guess, float start_y_guess, float start_z_guess,
        float end_x_guess, float end_y_guess, float end_z_guess, float* x_guess, float* y_guess,
        float* z_guess, int mode_guess);
    // EXTERNAL: TITANIUM 0x00439DB8 Display_48A026_guess::UpdateGrassDisplacement_guess
    void UpdateGrassDisplacement_guess();
    // EXTERNAL: TITANIUM 0x0043D7C5 Display_48A026_guess::ResetLocalPlayer_guess
    void ResetLocalPlayer_guess();
};

#define g_display_48A026_guess EQ_GLOBAL(Display_48A026_guess*, 0x00905D24)

struct Vector_48A324_guess {
    float x_guess;
    float y_guess;
    float z_guess;

    void Abs_guess();
    char IsLess_guess(Vector_48A324_guess* other_guess);
    char IsGreater_guess(Vector_48A324_guess* other_guess);
    // EXTERNAL: TITANIUM 0x00477C8F Vector_48A324_guess::operator*
    Vector_48A324_guess operator*(float scale_guess) const;
    // EXTERNAL: TITANIUM 0x00435B36 Vector_48A324_guess::Length_guess
    float Length_guess();
};

struct Point_48A945_guess {
    float first_guess;
    float second_guess;
};

struct PositionRequest_48A945_guess {
    Point_48A945_guess point_guess;
    float zero_guess;
    Vector_48A324_guess position_guess;
};

struct PositionInterface_48A945_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0c_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1c_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2c_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3c_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual int ReadPosition_guess(Vector_48A324_guess* position_guess) = 0;
    virtual void WritePosition_guess(Point_48A945_guess* point_guess) = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5c_guess() = 0;
    virtual float GetValue_guess() = 0;
};

struct Triple_48A00B_guess {
    float value_000_guess;
    unsigned int value_004_guess;
    unsigned int value_008_guess;

    Triple_48A00B_guess* Copy_guess(Triple_48A00B_guess* destination_guess, Triple_48A00B_guess* source_guess);
};

struct State_48995D_guess {
    unsigned char unknown_000[0x30];
    Vector_48A324_guess position_0030_guess;
    float velocityY_003c_guess;
    float velocityX_0040_guess;
    float velocityZ_0044_guess;
    unsigned char unknown_048[0x04];
    float heading_004c_guess;
    float value_050_guess;
    unsigned char unknown_054[0x08];
    float value_05c_guess;
    int value_060_guess;
    int value_064_guess;
    unsigned char unknown_068[0x48];
    Vector_48A324_guess savedPosition_00b0_guess;
    unsigned char unknown_0bc[0xec];
    Data_4898_guess* pActorInfo_01a8_guess;
    unsigned char unknown_1ac[0x0a];
    char value_1b6_guess;
    unsigned char unknown_1b7[0x4d];
    int zoneId_0204_guess;
    unsigned char unknown_208[0x24];
    float stepHeight_022c_guess;
    unsigned char unknown_230[0x04];
    float eyeHeight_0234_guess;
    float heightOffset_0238_guess;
    unsigned char unknown_23c[0x08];
    unsigned char type_0244_guess;
    unsigned char unknown_245[0x0c];
    unsigned char standState_0251_guess;
    unsigned char unknown_252[0x06];
    unsigned int spawnId_0258_guess;
    unsigned char unknown_25c[0x04];
    int race_0260_guess;
    unsigned char unknown_264[0x0c];
    int bodyType_0270_guess;
    unsigned char unknown_274[0x71];
    unsigned char value_2e5_guess;
    unsigned char unknown_2e6[2];
    unsigned int value_2e8_guess;
    float floorCacheX_02ec_guess;
    float floorCacheY_02f0_guess;
    float floorCacheZ_02f4_guess;
    float floorCacheHeight_02f8_guess;
    unsigned char unknown_2fc[0x0c];
    float value_308_guess;

    unsigned int Get_1a8_guess();
    char Check_4898_guess();
    float Calculate_489906_guess();
    // EXTERNAL: TITANIUM 0x0047BFD0 State_48995D_guess::IsHorseRace_guess
    char IsHorseRace_guess();
    float Calculate_4899D3_guess();
    float Calculate_489A32_guess();
    void Clear_guess();
    bool Check_guess();
    float Get_234_guess();
    char IsSet_2e5_guess();
    char Check_48A2F4_guess();
    void Copy_48A324_guess(Vector_48A324_guess* destination_guess);
    float Speed_guess() { return heightOffset_0238_guess; }
    void Push_489C83_guess(float scale_guess);
    int IsLedgeAhead_guess();
    float GetFloorHeightAt_guess(float x_guess, float y_guess, float z_guess, char flag_guess);
    float GetFloorHeightHere_guess(float lift_guess);
    void Update_48A6F2_guess();
    void Update_48A793_guess(bool move_guess);
    void Update_48A7F9_guess();
    char Update_48A945_guess();
    void UpdateIgnoring_48BB7B_guess(int unused_guess);
    // EXTERNAL: TITANIUM 0x00483556 State_48995D_guess::ChangePosition_guess
    void ChangePosition_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x00479EE8 State_48995D_guess::PlaySound_guess
    void PlaySound_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0047CA9D State_48995D_guess::IHaveFallen_guess
    void IHaveFallen_guess(float value_guess);
    // EXTERNAL: TITANIUM 0x00478474 State_48995D_guess::WarpToPosition_guess
    void WarpToPosition_guess(Vector_48A324_guess* position_guess, float value_guess);
    void CheckForUnderFloor_guess();
    char Forward_489FDA_guess(int a_guess, int b_guess, int c_guess, int d_guess, int e_guess, int f_guess, int g_guess, int h_guess);
};

struct TeleportLogger_489CC2_guess {
    int handle_000_guess;

    // EXTERNAL: TITANIUM 0x004482FB TeleportLogger_489CC2_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00572E00 TeleportLogger_489CC2_guess::Show_guess
    void Show_guess(const char* message_guess);
    // EXTERNAL: TITANIUM 0x00571D00 TeleportLogger_489CC2_guess::FreeRep
    void FreeRep(int handle_guess);
    // EXTERNAL: TITANIUM 0x00572300 TeleportLogger_489CC2_guess::GetValue_guess
    void* GetValue_guess();

    ~TeleportLogger_489CC2_guess()
    {
        if (handle_000_guess != 0)
            FreeRep(handle_000_guess);
    }
};

struct StackSlot3_48B42B_guess {
    unsigned char unknown_000_guess[3];
    unsigned char value_003_guess;
};

struct Window_48B42B_guess {
    // EXTERNAL: TITANIUM 0x0040E934 Window_48B42B_guess::FindBuffWithEffect_guess
    void* FindBuffWithEffect_guess(unsigned int id_guess, void* argument_guess);
    // EXTERNAL: TITANIUM 0x00411F2F Window_48B42B_guess::RemovePCAffect_guess
    void RemovePCAffect_guess(void* message_guess);
};

struct Manager_48B42B_guess {
    unsigned char unknown_000_guess[0xc280];
    Window_48B42B_guess window_c280_guess;
};

#define g_manager_48B42B_guess EQ_GLOBAL(Manager_48B42B_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x005738B0 FUN_005738b0_guess
void __cdecl FUN_005738b0_guess(TeleportLogger_489CC2_guess* logger_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x004913AE GetTPCoordsFromIndex_guess
int __cdecl GetTPCoordsFromIndex_guess(int index_guess, float* x_guess, float* y_guess, float* z_guess, float* heading_guess, int* zone_guess);

struct TeleportEntry_489CC2_guess {
    unsigned char unknown_000_guess[0x46];
    unsigned char value_046_guess;
};

#define g_cameras_guess EQ_ARRAY(TeleportEntry_489CC2_guess*, 0x009254FC)

// Parses a teleport text: either an index into the teleporter table (0x9254FC) or "zone x y z heading",
// logging a new- or old-teleport line. Outputs the zone, the coordinates and whether it stays in the
// current zone.
// FUNCTION: TITANIUM 0x00489CC2
// @early-stop: budget, structural ndiff=166
char __cdecl DoTeleport_guess(int text_value_guess, int selector_guess, int coordinates_value_guess, int zone_value_guess, int logger_value_guess, int unused_flag_value_guess, int same_zone_value_guess, int previous_zone_value_guess, void* player_position_value_guess, int current_zone_guess)
{
    char* text_guess = (char*)text_value_guess;
    float* coordinates_guess = (float*)coordinates_value_guess;
    int* zone_guess = (int*)zone_value_guess;
    TeleportLogger_489CC2_guess* logger_guess = (TeleportLogger_489CC2_guess*)logger_value_guess;
    unsigned char* unused_flag_guess = (unsigned char*)unused_flag_value_guess;
    unsigned char* same_zone_guess = (unsigned char*)same_zone_value_guess;
    int* previous_zone_guess = (int*)previous_zone_value_guess;
    float* player_position_guess = (float*)player_position_value_guess;
    int length_guess = (int)strlen(text_guess);
    logger_guess->Refresh_guess();
    *zone_guess = 0;
    coordinates_guess[0] = 0.0f;
    coordinates_guess[1] = 0.0f;
    char result_text_guess[264];
    result_text_guess[0] = '\0';
    char zone_text_guess[6];
    char index_text_guess[7];
    coordinates_guess[2] = 0.0f;
    coordinates_guess[3] = 0.0f;
    *same_zone_guess = 0;

    int parsed_zone_guess = 0;
    *unused_flag_guess = 0;
    if (selector_guess < 0) {
        if (length_guess > 9) {
            zone_text_guess[0] = text_guess[5];
            zone_text_guess[1] = text_guess[6];
            zone_text_guess[2] = text_guess[7];
            zone_text_guess[3] = text_guess[8];
            zone_text_guess[4] = text_guess[9];
            zone_text_guess[5] = '\0';
            parsed_zone_guess = (int)atol(zone_text_guess);
            if (length_guess > 15) {
                char x_text_guess[7];
                x_text_guess[0] = text_guess[10];
                x_text_guess[1] = text_guess[11];
                x_text_guess[2] = text_guess[12];
                x_text_guess[3] = text_guess[13];
                x_text_guess[4] = text_guess[14];
                x_text_guess[5] = text_guess[15];
                x_text_guess[6] = '\0';
                coordinates_guess[0] = (float)atof(x_text_guess);
                if (length_guess > 21) {
                    char y_text_guess[7];
                    y_text_guess[0] = text_guess[16];
                    y_text_guess[1] = text_guess[17];
                    y_text_guess[2] = text_guess[18];
                    y_text_guess[3] = text_guess[19];
                    y_text_guess[4] = text_guess[20];
                    y_text_guess[5] = text_guess[21];
                    y_text_guess[6] = '\0';
                    coordinates_guess[1] = (float)atof(y_text_guess);
                    if (length_guess > 27) {
                        char z_text_guess[7];
                        z_text_guess[0] = text_guess[22];
                        z_text_guess[1] = text_guess[23];
                        z_text_guess[2] = text_guess[24];
                        z_text_guess[3] = text_guess[25];
                        z_text_guess[4] = text_guess[26];
                        z_text_guess[5] = text_guess[27];
                        z_text_guess[6] = '\0';
                        coordinates_guess[2] = (float)atof(z_text_guess);
                        if (length_guess > 30) {
                            char heading_text_guess[4];
                            heading_text_guess[0] = text_guess[28];
                            heading_text_guess[1] = text_guess[29];
                            heading_text_guess[2] = text_guess[30];
                            heading_text_guess[3] = '\0';
                            coordinates_guess[3] = (float)atof(heading_text_guess);
                        }
                    }
                }
            }
        }
    } else {
        coordinates_guess[0] = (float)selector_guess;
        parsed_zone_guess = 0xff;
        strcpy(index_text_guess, "index");
    }

    if (parsed_zone_guess == 0xff) {
        int index_guess = (int)coordinates_guess[0];
        FUN_005738b0_guess(logger_guess, "new teleport (index #%d, %s): ", index_guess, index_text_guess);
        int result_guess = GetTPCoordsFromIndex_guess((int)coordinates_guess[0], coordinates_guess, coordinates_guess + 1, coordinates_guess + 2, coordinates_guess + 3, &parsed_zone_guess);
        if (result_guess == -1) {
            logger_guess->Show_guess("Index does not exist in teleporter table.");
            return 0;
        }
    } else {
        FUN_005738b0_guess(logger_guess, "old teleport: zone#%d, %s", parsed_zone_guess, zone_text_guess);
        *zone_guess = parsed_zone_guess;
    }

    sprintf(result_text_guess, "Teleport found! Zone nbr = %ld XYZ = %1.1f, %1.1f, %1.1f HD = %1.0f", parsed_zone_guess,
        (double)coordinates_guess[0], (double)coordinates_guess[1], (double)coordinates_guess[2], (double)coordinates_guess[3]);
    g_cameras_guess[EQ_GLOBAL(int, 0x00850CCC)]->value_046_guess = 1;
    logger_guess->Show_guess(result_text_guess);
    *same_zone_guess = *zone_guess == current_zone_guess;
    *previous_zone_guess = *zone_guess;
    *zone_guess = parsed_zone_guess;
    if (current_zone_guess == 0x22) {
        if (parsed_zone_guess != 0xa)
            return 1;
        float value_guess = player_position_guess[1] - 1044.0f;
        player_position_guess[1] = value_guess;
        coordinates_guess[1] = value_guess;
    } else {
        if (current_zone_guess != 10) {
            if (current_zone_guess == 3) {
                if (parsed_zone_guess != 4)
                    return 1;
                float value_guess = player_position_guess[2] + 2.0f;
                player_position_guess[2] = value_guess;
                coordinates_guess[2] = value_guess;
                return 1;
            }
            if (current_zone_guess != 2 || parsed_zone_guess != 4)
                return 1;
            coordinates_guess[0] += 10.0f;
            return 1;
        }
        if (parsed_zone_guess != 0x22)
            return 1;
        float value_guess = player_position_guess[1] + 1044.0f;
        player_position_guess[1] = value_guess;
        coordinates_guess[1] = value_guess;
    }
    return 1;
}

// DoTeleport_guess with this spawn's position (+0x30) and current zone (+0x204).
// FUNCTION: TITANIUM 0x00489FDA
char State_48995D_guess::Forward_489FDA_guess(int a_guess, int b_guess, int c_guess, int d_guess, int e_guess, int f_guess, int g_guess, int h_guess)
{
    return DoTeleport_guess(a_guess, b_guess, c_guess, d_guess, e_guess, f_guess, g_guess, h_guess, &position_0030_guess, zoneId_0204_guess);
}

struct Property_489BF5_guess {
    unsigned char unknown_000[0x44];
    float value_044_guess;
};

struct Data_489BF5_guess {
    unsigned char unknown_000[0x48];
    float floorHeight_0048_guess;
    unsigned char unknown_04c[0x78];
    float value_0c4_guess;
    unsigned char unknown_0c8[0x64];
    Property_489BF5_guess* property_12c_guess;
    unsigned char unknown_130[0x2c];
    int state_15c_guess;

    // EXTERNAL: TITANIUM 0x0048F019 Data_489BF5_guess::CheckMode_guess
    char CheckMode_guess();
};

struct Actor_489BF5_guess {
    unsigned char unknown_000[0x38];
    float value_038_guess;
    unsigned char unknown_03c[0x08];
    float value_044_guess;
    unsigned char unknown_048[0x160];
    Data_489BF5_guess* pActorInfo_01a8_guess;
    unsigned char unknown_1ac[0x88];
    float eyeHeight_0234_guess;
    float heightOffset_0238_guess;
    unsigned char unknown_23c[0x24];
    int kind_260_guess;

    float Calculate_489BF5_guess();
    char Advance_489C51_guess();
};

struct StatusInterface_48996B_guess {
    virtual void Slot_00_guess() = 0;
    virtual void Slot_04_guess() = 0;
    virtual void Slot_08_guess() = 0;
    virtual void Slot_0c_guess() = 0;
    virtual void Slot_10_guess() = 0;
    virtual void Slot_14_guess() = 0;
    virtual void Slot_18_guess() = 0;
    virtual void Slot_1c_guess() = 0;
    virtual void Slot_20_guess() = 0;
    virtual char Check_guess() = 0;
};

struct ValueInterface_48996B_guess {
    virtual void Slot_00_guess() = 0;
    virtual void Slot_04_guess() = 0;
    virtual void Slot_08_guess() = 0;
    virtual void Slot_0c_guess() = 0;
    virtual void Slot_10_guess() = 0;
    virtual void Slot_14_guess() = 0;
    virtual void Slot_18_guess() = 0;
    virtual void Slot_1c_guess() = 0;
    virtual void Slot_20_guess() = 0;
    virtual void Slot_24_guess() = 0;
    virtual void Slot_28_guess() = 0;
    virtual void Slot_2c_guess() = 0;
    virtual void Slot_30_guess() = 0;
    virtual void Slot_34_guess() = 0;
    virtual void Slot_38_guess() = 0;
    virtual void Slot_3c_guess() = 0;
    virtual void Slot_40_guess() = 0;
    virtual void Slot_44_guess() = 0;
    virtual void Slot_48_guess() = 0;
    virtual void Slot_4c_guess() = 0;
    virtual void Slot_50_guess() = 0;
    virtual void Slot_54_guess() = 0;
    virtual void Slot_58_guess() = 0;
    virtual void Slot_5c_guess() = 0;
    virtual float GetValue_guess() = 0;
};

struct ValueInterface_489A32_guess {
    virtual void Slot_00_guess() = 0;
    virtual void Slot_04_guess() = 0;
    virtual void Slot_08_guess() = 0;
    virtual void Slot_0c_guess() = 0;
    virtual void Slot_10_guess() = 0;
    virtual void Slot_14_guess() = 0;
    virtual void Slot_18_guess() = 0;
    virtual void Slot_1c_guess() = 0;
    virtual void Slot_20_guess() = 0;
    virtual void Slot_24_guess() = 0;
    virtual float GetValue_guess() = 0;
};

struct Data_48996B_guess {
    ValueInterface_48996B_guess* valueInterface_000_guess;
};

struct State_48996B_guess {
    unsigned char unknown_000_guess[0x4c];
    float heading_004c_guess;
    unsigned char unknown_050_guess[0x158];
    Data_48996B_guess* pActorInfo_01a8_guess;
    unsigned char unknown_1ac_guess[0x0a];
    char value_1b6_guess;
    unsigned char unknown_1b7_guess[0x51];
    StatusInterface_48996B_guess* status_208_guess;
    unsigned char unknown_20c_guess[0x80];
    int levitate_028c_guess;

    char Check_48996B_guess();
};

struct World_48A026_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual bool IsLoaded_guess(Vector_48A324_guess* position_guess);
    virtual void GetBounds_guess(Vector_48A324_guess* low_guess, Vector_48A324_guess* high_guess);
};

#define g_world_48A026_guess EQ_GLOBAL(World_48A026_guess*, 0x0099E368)

struct CheckInterface_48A7F9_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0c_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual void Slot1c_guess();
    virtual void Slot20_guess();
    virtual void Slot24_guess();
    virtual void Slot28_guess();
    virtual void Slot2c_guess();
    virtual void Slot30_guess();
    virtual void Slot34_guess();
    virtual void Slot38_guess();
    virtual void Slot3c_guess();
    virtual void Slot40_guess();
    virtual void Slot44_guess();
    virtual void Slot48_guess();
    virtual char Check_guess();
};

#define g_check_interface_48A7F9_guess EQ_GLOBAL(CheckInterface_48A7F9_guess*, 0x0099E370)

// EXTERNAL: TITANIUM 0x0060DA00 _memcpy
extern "C" void* __cdecl _memcpy(void* destination_guess, const void* source_guess, unsigned int size_guess);


struct CopyTriples_48A919_guess {
    unsigned int value_000_guess;
    unsigned int value_004_guess;
    unsigned int value_008_guess;
    unsigned int value_00c_guess;
    unsigned int value_010_guess;
    unsigned int value_014_guess;

    void Copy_guess(unsigned int* first_guess, unsigned int* second_guess);
};

struct Values_48A8D4_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int third_guess;
};

struct Processor_48A8D4_guess {
    // EXTERNAL: TITANIUM 0x004B5FD9 Processor_48A8D4_guess::Process_guess
    void Process_guess();
};

struct Data_48A8D4_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int third_guess;
};

struct State_48A8D4_guess {
    unsigned char unknown_000_guess[0xe8];
    Data_48A8D4_guess data_e8_guess;
    unsigned char unknown_f4_guess[0x10];
    float value_104_guess;

    // EXTERNAL: TITANIUM 0x004B6088 State_48A8D4_guess::Build_guess
    Processor_48A8D4_guess* Build_guess(Data_48A8D4_guess* values_guess, float* scalar_guess);
    void Update_guess();
};

struct StateVtable_48BB3B_guess {
    unsigned int vtable_000_guess;
};

struct State_48C_guess {
    State_48C_guess* GetState_guess();
    void Update_guess();
    void UpdateWithArgs_guess(int first_guess, int second_guess);
    void UpdateIfCurrent_guess();
    void UpdateIfCurrentWithArgs_guess(int first_guess, int second_guess);
    void UpdateIfCurrentWithPosition_guess(char lift_guess);
    // EXTERNAL: TITANIUM 0x004B6E39 State_48C_guess::IsBlocked_guess
    char IsBlocked_guess();
    // EXTERNAL: TITANIUM 0x004B6E42 State_48C_guess::GetTime_guess
    unsigned int GetTime_guess();
    // EXTERNAL: TITANIUM 0x004B6F1F State_48C_guess::BuildMessage_guess
    int BuildMessage_guess(void* buffer, int value);
    void SendMovementHistory_guess(int value);
};

struct Data_48BF_guess {
    unsigned char unknown_000[0xf94];
    int flag_f94_guess;
};

struct State_48BF_guess {
    unsigned char unknown_000[0x1a8];
    Data_48BF_guess* data_1a8_guess;
    void UpdateIfActive_guess();
};

struct Interface_48BF35_guess {
    virtual void Slot_00_guess() = 0;
    virtual void Slot_04_guess() = 0;
    virtual void Slot_08_guess(int first_guess, int second_guess, int third_guess, float value_guess, int last_guess) = 0;
    virtual void Slot_0c_guess(char value_guess) = 0;
    virtual void Slot_10_guess() = 0;
    virtual void Slot_14_guess() = 0;
    virtual void Slot_18_guess() = 0;
    virtual void Slot_1c_guess() = 0;
    virtual void Slot_20_guess(int first_guess, int second_guess, int third_guess, float value_guess) = 0;
};

struct Global_48BF35_guess {
    unsigned char unknown_000[0x148];
    unsigned int value_148_guess;
};

struct Data_48BF35_guess {
    unsigned char unknown_000[0x68];
    unsigned int value_068_guess;
    unsigned char unknown_06c[0xee0];
    unsigned int value_f4c_guess;
};

struct State_48BF35_guess {
    unsigned char unknown_000[0x50];
    float value_050_guess;
    unsigned char unknown_054[0x154];
    Data_48BF35_guess* pActorInfo_01a8_guess;
    unsigned char unknown_1ac[0x98];
    unsigned char type_0244_guess;
    unsigned char unknown_245[0x0c];
    unsigned char standState_0251_guess;

    // EXTERNAL: TITANIUM 0x0047C08E State_48BF35_guess::GetObject_guess
    Interface_48BF35_guess* GetObject_guess();
    void UpdateIfReady_guess();
};

// EXTERNAL: TITANIUM 0x004B718D State_48C_guess::GetState_guess
// EXTERNAL: TITANIUM 0x004B6EF8 State_48C_guess::Update_guess
// EXTERNAL: TITANIUM 0x004B70DB State_48C_guess::UpdateWithArgs_guess
// EXTERNAL: TITANIUM 0x0047F7DC TouchingSwitch_guess
void __fastcall TouchingSwitch_guess(void* param_1);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

// Makes each component of the vector non-negative.
// FUNCTION: TITANIUM 0x00489841
void Vector_48A324_guess::Abs_guess()
{
    x_guess = (float)fabs(x_guess);
    y_guess = (float)fabs(y_guess);
    z_guess = (float)fabs(z_guess);
}

// True when every component is below `other`'s.
// FUNCTION: TITANIUM 0x00489872
char Vector_48A324_guess::IsLess_guess(Vector_48A324_guess* other_guess)
{
    if (x_guess < other_guess->x_guess && y_guess < other_guess->y_guess && z_guess < other_guess->z_guess)
        return 1;
    return 0;
}

// True when every component is above `other`'s.
// FUNCTION: TITANIUM 0x004898A4
char Vector_48A324_guess::IsGreater_guess(Vector_48A324_guess* other_guess)
{
    if (x_guess > other_guess->x_guess && y_guess > other_guess->y_guess && z_guess > other_guess->z_guess)
        return 1;
    return 0;
}

// The actor info's first dword (+0); the display reads it for spawns.
// FUNCTION: TITANIUM 0x004898D6
unsigned int State_48995D_guess::Get_1a8_guess()
{
    return pActorInfo_01a8_guess->actorInstance_0000_guess;
}

// True when the actor isn't in a special mode (+0x15C), the spawn isn't on a mount/boat (+0x1B6) and its body
// type is below 65 (drawn).
// FUNCTION: TITANIUM 0x004898DF
char State_48995D_guess::Check_4898_guess()
{
    if (pActorInfo_01a8_guess->mount_015c_guess == 0 && value_1b6_guess == 0 && bodyType_0270_guess < 0x41)
        return 1;
    return 0;
}

// Half the model height, scaled: NPCs (type 1) by 0.35 (0.9 more for race 31, doubled in a special state),
// others by 0.95. Probably the collision radius.
// FUNCTION: TITANIUM 0x00489906
// @early-stop: budget, diff ndiff=1
float State_48995D_guess::Calculate_489906_guess()
{
    float result_guess = heightOffset_0238_guess * 0.5f;
    if (type_0244_guess == 1) {
        result_guess *= 0.35f;
        if (race_0260_guess == 0x1f)
            result_guess *= 0.9f;
        if (IsHorseRace_guess() != 0)
            return result_guess + result_guess;
    } else {
        result_guess *= 0.95f;
    }
    return result_guess;
}

// Resets the blocked-move counter (+0x2E8; see 0x0048995D).
// FUNCTION: TITANIUM 0x00489955
void State_48995D_guess::Clear_guess()
{
    value_2e8_guess = 0;
}

// True after more than two blocked moves in a row (+0x2E8, cleared by Clear_guess).
// FUNCTION: TITANIUM 0x0048995D
bool State_48995D_guess::Check_guess()
{
    return 2 < value_2e8_guess;
}

// True when the spawn should not fall: a status says so, the controlled player levitates (2), the global
// no-fall flag 0x9237B9 is set, or (+0x1B6) its ride's heading differs (probably mid-turn).
// FUNCTION: TITANIUM 0x0048996B
char State_48996B_guess::Check_48996B_guess()
{
    if (status_208_guess->Check_guess() != 0)
        return 1;
    if (this == EQ_GLOBAL(State_48996B_guess*, 0x00905CF8) && levitate_028c_guess == 2)
        return 1;
    if (EQ_GLOBAL(unsigned char, 0x009237B9) != 0)
        return 1;
    if (value_1b6_guess != 0) {
        ValueInterface_48996B_guess* interface_guess = pActorInfo_01a8_guess->valueInterface_000_guess;
        float value_guess = heading_004c_guess;
        if (interface_guess->GetValue_guess() != value_guess)
            return 1;
    }
    return 0;
}

// The spawn's float at +0x234 (5.5 from the constructor); the display reads it.
// FUNCTION: TITANIUM 0x004899CC
float State_48995D_guess::Get_234_guess()
{
    return eyeHeight_0234_guess;
}

// Head height: the height when crouching ('o'), 3x on some mounts, a fixed override (+0x22C) when set, else
// 2x the height.
// FUNCTION: TITANIUM 0x004899D3
float State_48995D_guess::Calculate_4899D3_guess()
{
    if (standState_0251_guess == 'o')
        return heightOffset_0238_guess;
    if (IsHorseRace_guess() != 0 && pActorInfo_01a8_guess->rider_0160_guess != 0)
        return heightOffset_0238_guess * 3.0f;
    if (stepHeight_022c_guess > 0.0f)
        return stepHeight_022c_guess;
    return heightOffset_0238_guess + heightOffset_0238_guess;
}

// Extra floor offset: half the height for Barbarians, Trolls and Ogres (races 2, 9, 10), 3/4 of a negative
// height, else 0; none while crouching, dead, mounted or in deep water (+0xAD >= 5).
// FUNCTION: TITANIUM 0x00489A32
float State_48995D_guess::Calculate_489A32_guess()
{
    float result_guess = 0.0f;
    if (standState_0251_guess != 'o' && standState_0251_guess != 'x' &&
        pActorInfo_01a8_guess->value_0ad_guess < 5 && value_1b6_guess == 0) {
        if (race_0260_guess == 2 || (race_0260_guess > 8 && race_0260_guess <= 10)) {
            result_guess = heightOffset_0238_guess * 0.5f;
        } else if (heightOffset_0238_guess < 0.0f) {
            result_guess = heightOffset_0238_guess * 0.75f;
        } else {
            result_guess = 0.0f;
        }
        if (result_guess < EQ_GLOBAL(float, 0x006484AC))
            result_guess = EQ_GLOBAL(float, 0x006484AC);
    }
    if (pActorInfo_01a8_guess->actorInstance_0000_guess != 0 && result_guess > 0.0f && value_1b6_guess == 0) {
        float value_guess = ((struct ValueInterface_489A32_guess*)pActorInfo_01a8_guess->actorInstance_0000_guess)->GetValue_guess();
        if (result_guess < value_guess)
            result_guess = value_guess;
    }
    return result_guess;
}

// Height of the spawn: the model's size times its scale for model-based actors, else +0x234 - +0x238;
// when something is chained at ActorInfo +0x15C a Froglok (race 330) adds the constant at 0x0063F4D0,
// other races the one at 0x006410BC.
// FUNCTION: TITANIUM 0x00489BF5
// @early-stop: budget, structural ndiff=16
float Actor_489BF5_guess::Calculate_489BF5_guess()
{
    float result;
    if (pActorInfo_01a8_guess->CheckMode_guess()) {
        result = pActorInfo_01a8_guess->property_12c_guess->value_044_guess *
            pActorInfo_01a8_guess->value_0c4_guess;
    } else {
        result = eyeHeight_0234_guess - heightOffset_0238_guess;
        if (pActorInfo_01a8_guess->state_15c_guess != 0) {
            if (kind_260_guess == 0x14a) {
                result = result + EQ_GLOBAL(float, 0x0063F4D0);
            } else {
                result = result + EQ_GLOBAL(float, 0x006410BC);
            }
        }
    }
    return result;
}

// Snaps the spawn onto the floor (and stops its fall) once it has sunk below floor + offset; true when it
// did.
// FUNCTION: TITANIUM 0x00489C51
char Actor_489BF5_guess::Advance_489C51_guess()
{
    float result_guess = ((State_48995D_guess*)this)->Calculate_489A32_guess();
    float difference_guess = value_038_guess - result_guess;
    if (difference_guess < pActorInfo_01a8_guess->floorHeight_0048_guess) {
        value_038_guess = result_guess + pActorInfo_01a8_guess->floorHeight_0048_guess;
        value_044_guess = 0.0f;
        return 1;
    }
    return 0;
}

// Pushes the spawn `scale_guess` units along its heading.
// FUNCTION: TITANIUM 0x00489C83
void State_48995D_guess::Push_489C83_guess(float scale_guess)
{
    velocityY_003c_guess += g_trig_guess->Cos_guess(heading_004c_guess) * scale_guess;
    velocityX_0040_guess += g_trig_guess->Sin_guess(heading_004c_guess) * scale_guess;
}

// Copies three dwords (a position) from `source` to `destination` and returns it.
// FUNCTION: TITANIUM 0x0048A00B
Triple_48A00B_guess* Triple_48A00B_guess::Copy_guess(Triple_48A00B_guess* destination_guess, Triple_48A00B_guess* source_guess)
{
    destination_guess->value_000_guess = source_guess->value_000_guess;
    destination_guess->value_004_guess = source_guess->value_004_guess;
    destination_guess->value_008_guess = source_guess->value_008_guess;
    return destination_guess;
}

// True when there is no floor one step ahead along the heading (a ledge).
// FUNCTION: TITANIUM 0x0048A026
// @early-stop: budget, diff ndiff=11
int State_48995D_guess::IsLedgeAhead_guess()
{
    char hit_guess = 0;
    float dx_guess = Speed_guess() * g_trig_guess->Cos_guess(heading_004c_guess);
    float dy_guess = Speed_guess() * g_trig_guess->Sin_guess(heading_004c_guess);
    g_display_48A026_guess->probe_11c_guess->x_guess = position_0030_guess.x_guess + dx_guess;
    g_display_48A026_guess->probe_11c_guess->y_guess = position_0030_guess.y_guess + dy_guess;
    g_display_48A026_guess->probe_11c_guess->z_guess = position_0030_guess.z_guess - 1.0f;
    if (g_world_48A026_guess->IsLoaded_guess(g_display_48A026_guess->probe_11c_guess)) {
        Vector_48A324_guess* probe_guess = g_display_48A026_guess->probe_11c_guess;
        hit_guess = g_display_48A026_guess->GetEnvironment_guess(probe_guess->x_guess, probe_guess->y_guess, probe_guess->z_guess, 0);
    }
    return hit_guess == 0;
}

// EXTERNAL: TITANIUM 0x0042D05F CanCollideWith_guess
void __cdecl CanCollideWith_guess();

// EXTERNAL: TITANIUM 0x0042CE5D Callback_42CE5D_guess
void __cdecl Callback_42CE5D_guess();

struct Tracer_48A0FC_guess {
    virtual void Slot_00_guess() = 0;
    virtual void Slot_04_guess() = 0;
    virtual void Slot_08_guess() = 0;
    virtual void Slot_0c_guess() = 0;
    virtual void Slot_10_guess() = 0;
    virtual void Slot_14_guess() = 0;
    virtual void Slot_18_guess() = 0;
    virtual void Slot_1c_guess() = 0;
    virtual void Slot_20_guess() = 0;
    virtual int Trace_24_guess(Vector_48A324_guess* start_guess, Vector_48A324_guess* end_guess, float step_guess,
        void (*first_callback_guess)(), void (*second_callback_guess)(), State_48995D_guess* owner_guess,
        Vector_48A324_guess* hit_guess, Vector_48A324_guess* normal_guess, float* z_guess,
        unsigned int data_value_guess, int one_guess) = 0;
    virtual void Slot_28_guess() = 0;
    virtual void Slot_2c_guess() = 0;
    virtual void Slot_30_guess() = 0;
    virtual void Slot_34_guess() = 0;
    virtual void Slot_38_guess() = 0;
    virtual void Slot_3c_guess() = 0;
    virtual void Slot_40_guess() = 0;
    virtual void Slot_44_guess() = 0;
    virtual void Slot_48_guess() = 0;
    virtual void Slot_4c_guess() = 0;
    virtual char GetMode_50_guess() = 0;
    virtual void Slot_54_guess() = 0;
    virtual void SetMode_58_guess(char mode_guess) = 0;
};

#define g_tracer_48A0FC_guess EQ_GLOBAL(Tracer_48A0FC_guess*, 0x0099E370)

// Floor height under (x, y, z), cached for repeat calls at the same spot; -1e27 when there is none.
// FUNCTION: TITANIUM 0x0048A0FC
// @early-stop: budget, structural ndiff=32
float State_48995D_guess::GetFloorHeightAt_guess(float x_guess, float y_guess, float z_guess, char flag_guess)
{
    float step_guess = 0.0f;
    if (pActorInfo_01a8_guess == 0)
        return -1e27f;
    if (g_display_48A026_guess->GetValue2cf8_guess() != 0) {
        step_guess = heightOffset_0238_guess * 0.1f;
        if (step_guess == 0.0f)
            step_guess = 0.1f;
        if (floorCacheX_02ec_guess != x_guess || y_guess != floorCacheY_02f0_guess || z_guess + 0.001f < floorCacheZ_02f4_guess
            || (this == EQ_GLOBAL(State_48995D_guess*, 0x00905CF8) && z_guess > value_308_guess - (step_guess + step_guess))
            || pActorInfo_01a8_guess->value_158_guess != 0) {
            value_2e8_guess = 0;
            floorCacheY_02f0_guess = y_guess;
            floorCacheX_02ec_guess = x_guess;
            floorCacheZ_02f4_guess = z_guess;
        }
        if (value_2e8_guess > 2)
            return floorCacheHeight_02f8_guess;
        Vector_48A324_guess start_guess;
        start_guess.y_guess = y_guess;
        start_guess.z_guess = z_guess;
        start_guess.x_guess = x_guess;
        unsigned int data_value_guess = 0;
        if (!g_world_48A026_guess->IsLoaded_guess(&start_guess)) {
            step_guess = -1e27f;
        } else {
            Vector_48A324_guess end_guess;
            Vector_48A324_guess hit_guess;
            Vector_48A324_guess normal_guess;
            end_guess.x_guess = x_guess;
            end_guess.y_guess = y_guess;
            end_guess.z_guess = -32767.0f;
            if (flag_guess != 0) {
                pActorInfo_01a8_guess->value_f94_guess = 0;
                if (pActorInfo_01a8_guess != 0)
                    data_value_guess = pActorInfo_01a8_guess->actorInstance_0000_guess;
            }
            pActorInfo_01a8_guess->value_158_guess = 0;
            flag_guess = g_tracer_48A0FC_guess->GetMode_50_guess();
            g_tracer_48A0FC_guess->SetMode_58_guess(1);
            int missed_guess = g_tracer_48A0FC_guess->Trace_24_guess(&start_guess, &end_guess, step_guess,
                CanCollideWith_guess, Callback_42CE5D_guess, this, &hit_guess, &normal_guess, &z_guess,
                data_value_guess, 1);
            g_tracer_48A0FC_guess->SetMode_58_guess(flag_guess);
            if (missed_guess == 0)
                step_guess = hit_guess.z_guess - step_guess + 0.001f;
            else
                step_guess = -1e27f;
        }
    }
    if (step_guess < EQ_GLOBAL(float, 0x00923BDC))
        step_guess = -1e27f;
    floorCacheHeight_02f8_guess = step_guess;
    return step_guess;
}

// True when the feet are within 0.5 of the floor (on the ground).
// FUNCTION: TITANIUM 0x0048A2F4
char State_48995D_guess::Check_48A2F4_guess()
{
    float value_guess = position_0030_guess.z_guess - heightOffset_0238_guess + velocityZ_0044_guess;
    float threshold_guess = pActorInfo_01a8_guess->floorHeight_0048_guess + 0.5f;
    if (value_guess > threshold_guess + 0.001f)
        return 0;
    return 1;
}

// Copies the spawn's position (+0x30) into `destination`.
// FUNCTION: TITANIUM 0x0048A324
void State_48995D_guess::Copy_48A324_guess(Vector_48A324_guess* destination_guess)
{
    Vector_48A324_guess values_guess;
    values_guess.x_guess = position_0030_guess.x_guess;
    values_guess.y_guess = position_0030_guess.y_guess;
    values_guess.z_guess = position_0030_guess.z_guess;
    destination_guess->x_guess = values_guess.x_guess;
    destination_guess->y_guess = values_guess.y_guess;
    destination_guess->z_guess = values_guess.z_guess;
}

// Stores two 3-dword vectors: `first` at +0 and `second` at +0xC.
// FUNCTION: TITANIUM 0x0048A919
void CopyTriples_48A919_guess::Copy_guess(unsigned int* first_guess, unsigned int* second_guess)
{
    value_000_guess = first_guess[0];
    value_004_guess = first_guess[1];
    value_008_guess = first_guess[2];
    value_00c_guess = second_guess[0];
    value_010_guess = second_guess[1];
    value_014_guess = second_guess[2];
}

// Pushes the spawn's position (+0x30) and heading to its actor model while the world is up (CDisplay
// +0x2CF8); returns 0 when the model refuses the position. Pending movement (+0x60/+0x64) first lifts z
// above the floor offset (0x00489C51); the spawn chained at ActorInfo +0x15C is moved to the same spot. A
// race-49 spawn plays animation 0x13 when its heading changed.
// FUNCTION: TITANIUM 0x0048A945
// @early-stop: budget, structural ndiff=30
char State_48995D_guess::Update_48A945_guess()
{
    char result_guess = 1;
    float current_guess;
    PositionRequest_48A945_guess request_guess;

    if (pActorInfo_01a8_guess == 0)
        return 0;
    if (pActorInfo_01a8_guess->actorInstance_0000_guess == 0) {
        g_display_48A026_guess->GetValue2cf8_guess();
        return 0;
    }
    if (g_display_48A026_guess->GetValue2cf8_guess() != 0) {
        if (race_0260_guess == 0x31) {
            current_guess = heading_004c_guess;
            PositionInterface_48A945_guess* interface_guess =
                (PositionInterface_48A945_guess*)pActorInfo_01a8_guess->actorInstance_0000_guess;
            if (current_guess != interface_guess->GetValue_guess()) {
                Interface_48BF35_guess* object_guess =
                    ((State_48BF35_guess*)this)->GetObject_guess();
                object_guess->Slot_08_guess(0x13, 1, 0, 1.5f, 0);
            }
        }
        int flags_guess = value_060_guess;
        flags_guess |= value_064_guess;
        if (flags_guess != 0)
            ((Actor_489BF5_guess*)this)->Advance_489C51_guess();

        request_guess.position_guess.x_guess = position_0030_guess.x_guess;
        request_guess.zero_guess = 0.0f;
        request_guess.position_guess.y_guess = position_0030_guess.y_guess;
        request_guess.position_guess.z_guess = position_0030_guess.z_guess;
        request_guess.point_guess.first_guess = heading_004c_guess;
        request_guess.point_guess.second_guess = value_050_guess;

        if (((PositionInterface_48A945_guess*)pActorInfo_01a8_guess->actorInstance_0000_guess)->
            ReadPosition_guess(&request_guess.position_guess) != 0) {
            result_guess = 0;
        } else {
            State_48995D_guess* other_guess =
                (State_48995D_guess*)pActorInfo_01a8_guess->mount_015c_guess;
            if (other_guess != 0 && other_guess->pActorInfo_01a8_guess != 0 &&
                other_guess->pActorInfo_01a8_guess->actorInstance_0000_guess != 0) {
                other_guess->position_0030_guess.x_guess = position_0030_guess.x_guess;
                other_guess->position_0030_guess.y_guess = position_0030_guess.y_guess;
                other_guess->position_0030_guess.z_guess = position_0030_guess.z_guess;
                other_guess->heading_004c_guess = heading_004c_guess;
                other_guess->pActorInfo_01a8_guess->floorHeight_0048_guess = pActorInfo_01a8_guess->floorHeight_0048_guess;
                PositionInterface_48A945_guess* other_interface_guess =
                    (PositionInterface_48A945_guess*)other_guess->pActorInfo_01a8_guess->actorInstance_0000_guess;
                other_interface_guess->ReadPosition_guess(&request_guess.position_guess);
                other_interface_guess->WritePosition_guess(&request_guess.point_guess);
                other_guess->Update_48A7F9_guess();
            }
        }
        ((PositionInterface_48A945_guess*)pActorInfo_01a8_guess->actorInstance_0000_guess)->
            WritePosition_guess(&request_guess.point_guess);
    }
    Update_48A7F9_guess();
    return result_guess;
}

// True once a move was refused and the spawn put back (+0x2E5).
// FUNCTION: TITANIUM 0x0048A344
char State_48995D_guess::IsSet_2e5_guess()
{
    return value_2e5_guess != 0;
}

struct Origin_48A34F_guess {
    virtual void Slot00_guess();
    unsigned char unknown_004_guess[0x6c];

    // EXTERNAL: TITANIUM 0x0046D713 Origin_48A34F_guess::Origin_48A34F_guess
    Origin_48A34F_guess(int* current_guess, int* previous_guess);
};

// EXTERNAL: TITANIUM 0x0064856C ??_7Motion_48A34F_guess@@6B@
struct Motion_48A34F_guess : Origin_48A34F_guess {
    virtual void Slot01_guess();
    float radius_070_guess;
    int current_074_guess;
    int current_078_guess;
    int current_07c_guess;
    float radiusSquared_080_guess;
    float inverseRadius_084_guess;

    Motion_48A34F_guess(int* current_guess, float radius_guess, int* previous_guess);
};

// Constructor: the base (0x0046D713) takes the current and previous positions; this keeps the radius, a
// copy of the current position, and the radius squared and inverted for the later tests.
// FUNCTION: TITANIUM 0x0048A34F
// @early-stop: budget, diff ndiff=7
Motion_48A34F_guess::Motion_48A34F_guess(int* current_guess, float radius_guess, int* previous_guess)
    : Origin_48A34F_guess(current_guess, previous_guess)
{
    radius_070_guess = radius_guess;
    current_074_guess = current_guess[0];
    current_078_guess = current_guess[1];
    current_07c_guess = current_guess[2];
    radiusSquared_080_guess = radius_guess * radius_guess;
    inverseRadius_084_guess = 1.0f / radius_guess;
}

struct Base_48A34F_guess {
    virtual void Slot00_guess();
    int unknown_004[0x1b];
    int value_070_guess;
    float value_074_guess;
    int value_078_guess;

    // EXTERNAL: TITANIUM 0x0048A34F Base_48A34F_guess::Base_48A34F_guess
    Base_48A34F_guess(int a_guess, float f_guess, int b_guess);
    ~Base_48A34F_guess() {}
};

// EXTERNAL: TITANIUM 0x0064858C ??_7Mover_48A39C_guess@@6B@
struct Mover_48A39C_guess : Base_48A34F_guess {
    int unknown_07c[3];
    ValueInterface_489A32_guess* value_088_guess;

    Mover_48A39C_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess);
    Mover_48A39C_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess, float f_guess);
};

// Collision sphere for a move (0x0048A34F) with the radius from `value`'s GetValue; keeps `value` at
// +0x88.
// FUNCTION: TITANIUM 0x0048A39C
Mover_48A39C_guess::Mover_48A39C_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess)
    : Base_48A34F_guess(a_guess, value_guess->GetValue_guess(), b_guess)
{
    value_088_guess = value_guess;
}

// Collision sphere for a move (0x0048A34F) with radius `f`; keeps `value` at +0x88.
// FUNCTION: TITANIUM 0x0048A3D1
Mover_48A39C_guess::Mover_48A39C_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess, float f_guess)
    : Base_48A34F_guess(a_guess, f_guess, b_guess)
{
    value_088_guess = value_guess;
}

// EXTERNAL: TITANIUM 0x006485AC ??_7Derived_48A3FF_guess@@6B@
struct Derived_48A3FF_guess : Mover_48A39C_guess {
    Derived_48A3FF_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess);
    Derived_48A3FF_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess, float f_guess);
    virtual void Slot00_guess();
};

// Derived collision sphere: the 0x0048A39C form (radius from `value`).
// FUNCTION: TITANIUM 0x0048A3FF
Derived_48A3FF_guess::Derived_48A3FF_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess)
    : Mover_48A39C_guess(value_guess, a_guess, b_guess)
{
}

// Derived collision sphere: the 0x0048A3D1 form (explicit radius `f`).
// FUNCTION: TITANIUM 0x0048A41F
Derived_48A3FF_guess::Derived_48A3FF_guess(ValueInterface_489A32_guess* value_guess, int a_guess, int b_guess, float f_guess)
    : Mover_48A39C_guess(value_guess, a_guess, b_guess, f_guess)
{
}

// Floor height under the spawn: casts down from its position (+0x30) raised by `lift` (0x0048A0FC);
// -1e27 when no floor is found.
// FUNCTION: TITANIUM 0x0048A6BF
float State_48995D_guess::GetFloorHeightHere_guess(float lift_guess)
{
    float z_guess = position_0030_guess.z_guess;
    unsigned int x_bits_guess = *(unsigned int*)&position_0030_guess.x_guess;
    float y_guess = position_0030_guess.y_guess;
    return GetFloorHeightAt_guess(*(float*)&x_bits_guess, y_guess, z_guess + lift_guess, 1);
}

// Re-reads the floor height under the spawn into the actor (+0x48), falling back to a probe without lift.
// FUNCTION: TITANIUM 0x0048A6F2
void State_48995D_guess::Update_48A6F2_guess()
{
    if (g_display_48A026_guess->GetValue2cf8_guess() != 0 && pActorInfo_01a8_guess != 0 && pActorInfo_01a8_guess->actorInstance_0000_guess != 0) {
        float result_guess = GetFloorHeightHere_guess(0.0f);
        if (result_guess != -1e27f) {
            pActorInfo_01a8_guess->floorHeight_0048_guess = result_guess;
        } else {
            unsigned int x_bits_guess = *(unsigned int*)&position_0030_guess.x_guess;
            float z_guess = position_0030_guess.z_guess;
            float y_guess = position_0030_guess.y_guess;
            result_guess = GetFloorHeightAt_guess(*(float*)&x_bits_guess, y_guess, z_guess, 1);
            if (result_guess != -1e27f) {
                pActorInfo_01a8_guess->floorHeight_0048_guess = result_guess;
            } else {
                pActorInfo_01a8_guess->floorHeight_0048_guess = -1e27f;
            }
        }
    }
}

// Every 1.5 s, when moving toward a ledge, drops and nudges the spawn half a unit forward (probably to
// unstick it from edges).
// FUNCTION: TITANIUM 0x0048A793
// @early-stop: budget, diff ndiff=7
void State_48995D_guess::Update_48A793_guess(bool move_guess)
{
    if (pActorInfo_01a8_guess != 0 && g_display_48A026_guess->time_148_guess > pActorInfo_01a8_guess->value_06c_guess) {
        pActorInfo_01a8_guess->value_06c_guess = g_display_48A026_guess->time_148_guess + 0x5dc;
        Data_4898_guess* data_guess = pActorInfo_01a8_guess;
        if (move_guess && IsLedgeAhead_guess()) {
            velocityZ_0044_guess += data_guess->value_0c0_guess * 3.0f;
            Push_489C83_guess(0.5f);
        }
    }
}

// Outside the zone's bounds by more than 2000 units: moves the spawn back to safety and sends a position
// update.
// FUNCTION: TITANIUM 0x0048A7F9
// @early-stop: budget, structural ndiff=26
void State_48995D_guess::Update_48A7F9_guess()
{
    Vector_48A324_guess upper_guess;
    Vector_48A324_guess lower_guess;
    if (g_check_interface_48A7F9_guess->Check_guess() != 0) {
        g_world_48A026_guess->GetBounds_guess(&lower_guess, &upper_guess);
        Vector_48A324_guess* position_guess = &position_0030_guess;
        lower_guess.x_guess -= 2000.0f;
        lower_guess.y_guess -= 2000.0f;
        lower_guess.z_guess -= 2000.0f;
        upper_guess.x_guess += 2000.0f;
        upper_guess.y_guess += 2000.0f;
        upper_guess.z_guess += 2000.0f;
        if (position_guess->IsLess_guess(&upper_guess) == 0 ||
            position_guess->IsGreater_guess(&lower_guess) == 0) {
            velocityY_003c_guess = 0.0f;
            velocityX_0040_guess = 0.0f;
            velocityZ_0044_guess = 0.0f;
            position_0030_guess = savedPosition_00b0_guess;
            return;
        }
    }
    _memcpy(&savedPosition_00b0_guess, &position_0030_guess, 0x38);
    ((State_48C_guess*)this)->UpdateIfCurrentWithPosition_guess(0);
    ((State_48C_guess*)this)->SendMovementHistory_guess(0);
}

// Copies the oldest recorded position from the position history (0x004B5FD9) to +0xE8 (x, y, z) and its
// float to +0x104.
// FUNCTION: TITANIUM 0x0048A8D4
void State_48A8D4_guess::Update_guess()
{
    Data_48A8D4_guess values_guess;
    float scalar_guess = 0.0f;
    Build_guess(&values_guess, &scalar_guess)->Process_guess();
    Data_48A8D4_guess* destination_guess = &data_e8_guess;
    destination_guess->first_guess = values_guess.first_guess;
    destination_guess->second_guess = values_guess.second_guess;
    destination_guess->third_guess = values_guess.third_guess;
    value_104_guess = scalar_guess;
}

// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* message_guess, ...);

// EXTERNAL: TITANIUM 0x00469DD7 NoOp_guess
void __cdecl NoOp_guess(void);

struct Actor_489B0A_guess {
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
    virtual float Update_028_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void SetPosition_048_guess(Vector_48A324_guess* position_guess);
    virtual void SetHeading_04c_guess(float* values_guess);
    virtual void Slot14_guess();
    virtual Vector_48A324_guess* GetCurrentPosition_054_guess();
    virtual void GetPosition_058_guess(Vector_48A324_guess* position_guess);
    virtual void GetHeading_05c_guess(float* values_guess);
    virtual float GetValue_060_guess();
    virtual float GetValue_064_guess();
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess();
    virtual void Slot1f_guess();
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
    virtual void Slot2a_guess();
    virtual void Slot2b_guess();
    virtual void Slot2c_guess();
    virtual void Slot2d_guess();
    virtual void Slot2e_guess();
    virtual void Slot2f_guess();
    virtual void GetValues_0c0_guess(int id_guess, int* values_guess, int flag_guess);
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
    virtual void Slot38_guess();
    virtual void Slot39_guess();
    virtual void Slot3a_guess();
    virtual void Slot3b_guess();
    virtual void Slot3c_guess();
    virtual void Slot3d_guess();
    virtual void Slot3e_guess();
    virtual void Slot3f_guess();
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
    virtual void Slot4a_guess();
    virtual void Slot4b_guess();
    virtual void Slot4c_guess();
    virtual void Slot4d_guess();
    virtual void Slot4e_guess();
    virtual void Slot4f_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual char HasValues_154_guess(int id_guess);
};

struct Player_48BA76_guess;

struct Data_489B0A_guess {
    Actor_489B0A_guess* actorInstance_0000_guess;
    void* light_0004_guess;
    unsigned char unknown_008[0x98];
    unsigned int value_0a0_guess;
    unsigned int value_0a4_guess;
    unsigned int regionFlags_00a8_guess;
    unsigned char unknown_0ac[0x01];
    unsigned char value_0ad_guess;
    unsigned char unknown_0ae[0x02];
    unsigned char value_0b0_guess;
    unsigned char unknown_0b1[0x03];
    unsigned int value_0b4_guess;
    unsigned int value_0b8_guess;
    unsigned char unknown_0bc[0x74];
    unsigned int value_130_guess;
    unsigned char unknown_134[0x1c];
    unsigned char value_150_guess;
    unsigned char unknown_151[0x0b];
    Player_48BA76_guess* mount_015c_guess;
    Player_48BA76_guess* rider_0160_guess;
    unsigned char unknown_164[0x4c];
    float ceilingHeight_01b0_guess;

    // EXTERNAL: TITANIUM 0x0048F019 Data_489B0A_guess::CheckMode_48F019_guess
    char CheckMode_48F019_guess();
};

struct Collider_48ACEF_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual char Test_00c_guess(Derived_48A3FF_guess* mover_guess);
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual int Sweep_020_guess(Actor_489B0A_guess* actor_guess, Vector_48A324_guess* start_guess,
        Vector_48A324_guess* end_guess, void* filter_guess, void* test_guess, Player_48BA76_guess* owner_guess,
        Vector_48A324_guess* result_guess, Vector_48A324_guess* normal_guess, float* fraction_guess, int flags_guess);
    virtual void Slot09_guess();
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual char IsActive_04c_guess();
};

#define g_collider_48ACEF_guess EQ_GLOBAL(Collider_48ACEF_guess*, 0x0099E370)

// EXTERNAL: TITANIUM 0x0042CFD5 SweepFilterLinked_guess
int __cdecl SweepFilterLinked_guess(int a_guess, void* b_guess);
// EXTERNAL: TITANIUM 0x0042CF6E SweepFilter_guess
int __cdecl SweepFilter_guess(int a_guess, void* b_guess);
// EXTERNAL: TITANIUM 0x0042CDB1 RecordCollisionHit_guess
int __cdecl RecordCollisionHit_guess(int a_guess, void* b_guess);

// 0x0048A919 as Pick's own unit saw it: declared, not defined
struct Segment_48ACEF_guess {
    Vector_48A324_guess start_guess;
    Vector_48A324_guess delta_guess;

    // EXTERNAL: TITANIUM 0x0048A919 Segment_48ACEF_guess::Set_guess
    void Set_guess(Vector_48A324_guess* start_guess, Vector_48A324_guess* delta_guess);
};

struct Sweep_48ACEF_guess {
    Segment_48ACEF_guess segment_guess;
    float radius_guess;
};

struct Buffer_48AAA6_guess;

struct Player_48BA76_guess {
    unsigned char unknown_000[0x30];
    Vector_48A324_guess position_030_guess;
    Vector_48A324_guess velocity_03c_guess;
    float speedRun_0048_guess;
    float heading_004c_guess;
    unsigned char unknown_050[0x08];
    float value_058_guess;
    unsigned char unknown_05c[0x54];
    Vector_48A324_guess saved_0b0_guess;
    unsigned char unknown_0bc[0x64];
    char name_120_guess[0x28];
    unsigned char unknown_148[0x60];
    Data_489B0A_guess* pActorInfo_01a8_guess;
    unsigned char unknown_1ac[0x06];
    unsigned char linkdead_01b2_guess;
    unsigned char unknown_1b3[0x03];
    char value_1b6_guess;
    unsigned char unknown_1b7[0x4d];
    void* state_204_guess;
    unsigned char unknown_208[0x24];
    float stepHeight_022c_guess;
    unsigned char unknown_230_guess[0x04];
    float eyeHeight_0234_guess;
    float heightOffset_0238_guess;
    unsigned char unknown_23c[0x08];
    unsigned char type_0244_guess;
    unsigned char unknown_245[0x09];
    unsigned char sex_24e_guess;
    unsigned char unknown_24f[0x02];
    unsigned char standState_0251_guess;
    unsigned char unknown_252[0x06];
    unsigned short spawnId_0258_guess;
    unsigned char unknown_25a[0x06];
    int race_260_guess;
    unsigned char unknown_264[0x80];
    unsigned char value_2e4_guess;
    unsigned char value_2e5_guess;
    unsigned char unknown_2e6[2];
    unsigned int value_2e8_guess;

    // EXTERNAL: TITANIUM 0x0048C5F1 Player_48BA76_guess::Check_48C5F1_guess
    char Check_48C5F1_guess();
    void Update_48BE7E_guess();
    char Pick_48ACEF_guess(Vector_48A324_guess* position_guess);
    // EXTERNAL: TITANIUM 0x0048BB7B Player_48BA76_guess::UpdateFloor_48BB7B_guess
    void UpdateFloor_48BB7B_guess(int unused_guess);
    // EXTERNAL: TITANIUM 0x0048BB42 Player_48BA76_guess::IsLocalPlayer_guess
    bool IsLocalPlayer_guess();
    // EXTERNAL: TITANIUM 0x0048BB4E Player_48BA76_guess::IsControlledPlayer_guess
    bool IsControlledPlayer_guess();
    // EXTERNAL: TITANIUM 0x0048BB6F Player_48BA76_guess::AddSharedOwnerValues_guess
    void AddSharedOwnerValues_guess();
    // EXTERNAL: TITANIUM 0x0048C63F Player_48BA76_guess::Settle_48C63F_guess
    void Settle_48C63F_guess();
    void Follow_48A447_guess(Vector_48A324_guess* position_guess, Vector_48A324_guess* result_guess);
    char Check_48BB83_guess(Vector_48A324_guess* position_guess, bool direct_guess);
    // EXTERNAL: TITANIUM 0x00489955 Player_48BA76_guess::Clear_489955_guess
    void Clear_489955_guess();
    // EXTERNAL: TITANIUM 0x0048995D Player_48BA76_guess::Check_48995D_guess
    char Check_48995D_guess();
    // EXTERNAL: TITANIUM 0x0048A7F9 Player_48BA76_guess::Finish_48A7F9_guess
    void Finish_48A7F9_guess();
    // EXTERNAL: TITANIUM 0x0049183F Player_48BA76_guess::EmptyCallback2_guess
    void EmptyCallback2_guess(Vector_48A324_guess* from_guess, Vector_48A324_guess* to_guess);
    void Apply_48BFA2_guess(char flag_guess);
    // EXTERNAL: TITANIUM 0x004898D6 Player_48BA76_guess::GetActor_4898D6_guess
    Actor_489B0A_guess* GetActor_4898D6_guess();
    // EXTERNAL: TITANIUM 0x0047C08E Player_48BA76_guess::GetAnimation_guess
    Interface_48BF35_guess* GetAnimation_guess();
    char UpdateRegion_guess(Vector_48A324_guess* position_guess);
    char Handle_48B42B_guess(const char* message_guess, int value_guess, void** state_guess);
    char WarpPlayer_guess(unsigned int state_guess, float x_guess, float y_guess,
        float z_guess, float heading_guess, void* value_guess, int zero_guess);
    // EXTERNAL: TITANIUM 0x0047CB5F Player_48BA76_guess::feetEnvironmentChange_guess
    void feetEnvironmentChange_guess(unsigned int flags_guess);
    // EXTERNAL: TITANIUM 0x0047CAE6 Player_48BA76_guess::SetRegionType_guess
    void SetRegionType_guess(unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x00483439 Player_48BA76_guess::headEnvironmentChange_guess
    void headEnvironmentChange_guess(unsigned int value_guess);
    void Fix_489B0A_guess();
    int MovePlayer();
    unsigned char unknown_2ec_guess[0x0c];
    float value_2f8_guess;
    float value_2fc_guess;
    float value_300_guess;
    float value_304_guess;
    float value_308_guess;
};

// EXTERNAL: TITANIUM 0x004BF9B2 TransformPassengersToBoatSpace_guess
void __cdecl TransformPassengersToBoatSpace_guess(void* state_guess);

// EXTERNAL: TITANIUM 0x004BFC71 TransformPassengersToWorldSpace_guess
void __cdecl TransformPassengersToWorldSpace_guess(void* state_guess);

// A spot 6 units ahead of `position_guess` on the floor, used when it is free of world collision.
// FUNCTION: TITANIUM 0x0048A447
// @early-stop: budget, structural ndiff=75
void Player_48BA76_guess::Follow_48A447_guess(Vector_48A324_guess* position_guess,
    Vector_48A324_guess* result_guess)
{
    Actor_489B0A_guess* actor_guess = pActorInfo_01a8_guess->actorInstance_0000_guess;
    Vector_48A324_guess* current_guess = actor_guess->GetCurrentPosition_054_guess();
    float z_guess = position_guess->z_guess;
    float x_guess = g_trig_guess->Cos_guess(heading_004c_guess) * 6.0f + position_guess->x_guess;
    float y_guess = g_trig_guess->Sin_guess(heading_004c_guess) * 6.0f + position_guess->y_guess;
    float floor_guess = ((State_48995D_guess*)this)->GetFloorHeightAt_guess(
        x_guess, y_guess, z_guess + 1.0f, 1);
    if (floor_guess == EQ_GLOBAL(float, 0x00640EA0))
        floor_guess = z_guess;

    if (!g_display_48A026_guess->s3dCollideSphereWithWorld_guess(current_guess->x_guess,
            current_guess->y_guess, current_guess->z_guess, x_guess, y_guess, z_guess,
            &position_guess->x_guess, &position_guess->y_guess, &position_guess->z_guess, 2)) {
        char clear_guess = (char)!g_display_48A026_guess->GetEnvironment_guess(
            x_guess, y_guess, floor_guess + 0.01f, (int*)0);
        if (clear_guess == 0) {
            x_guess = g_trig_guess->Cos_guess(heading_004c_guess) * -18.0f + position_guess->x_guess;
            y_guess = g_trig_guess->Sin_guess(heading_004c_guess) * -18.0f + position_guess->y_guess;
            floor_guess = ((State_48995D_guess*)this)->GetFloorHeightAt_guess(
                x_guess, y_guess, z_guess + 1.0f, 1);
            if (floor_guess == EQ_GLOBAL(float, 0x00640EA0))
                floor_guess = z_guess;
            if (!g_display_48A026_guess->s3dCollideSphereWithWorld_guess(current_guess->x_guess,
                    current_guess->y_guess, current_guess->z_guess, x_guess, y_guess, z_guess,
                    &position_guess->x_guess, &position_guess->y_guess, &position_guess->z_guess, 2)) {
                char reverse_clear_guess = (char)!g_display_48A026_guess->GetEnvironment_guess(
                    x_guess, y_guess, floor_guess + 0.01f, (int*)0);
                if (reverse_clear_guess == 0)
                    return;
            }
        }
    }

    TransformPassengersToBoatSpace_guess(this);
    position_030_guess.x_guess = current_guess->x_guess;
    position_030_guess.y_guess = current_guess->y_guess;
    position_030_guess.z_guess = current_guess->z_guess;
    heading_004c_guess = actor_guess->GetValue_060_guess();
    result_guess->x_guess = current_guess->x_guess;
    result_guess->y_guess = current_guess->y_guess;
    result_guess->z_guess = current_guess->z_guess;
    speedRun_0048_guess = 0.0f;
    velocity_03c_guess.x_guess = 0.0f;
    velocity_03c_guess.y_guess = 0.0f;
    velocity_03c_guess.z_guess = 0.0f;
    TransformPassengersToWorldSpace_guess(this);
}

struct Buffer_48AAA6_guess {
    unsigned char unknown_000_guess[0x18];
    unsigned short value_018_guess;

    // EXTERNAL: TITANIUM 0x004B70DB Buffer_48AAA6_guess::Commit_48AAA6_guess
    void Commit_48AAA6_guess(Vector_48A324_guess* position_guess, int count_guess);
};

struct Data_48AAA6_guess {
    unsigned char unknown_000_guess[0x48];
    float floor_048_guess;
    unsigned char unknown_04c_guess[0x104];
    unsigned char value_150_guess;
    unsigned char unknown_151_guess[0x07];
    unsigned int value_158_guess;
    unsigned char unknown_15c_guess[0xe38];
    unsigned int value_f94_guess;
};

struct Scene_48AAA6_guess {
    unsigned char unknown_000_guess[0xb54];
    int value_b54_guess;

    // EXTERNAL: TITANIUM 0x004AB056 Scene_48AAA6_guess::MoveToZone_guess
    void MoveToZone_guess(unsigned int target_guess, void* value_guess, int zero_guess,
        int send_guess, float x_guess, float y_guess, float z_guess, unsigned int heading_guess);
};

struct Map_48AAA6_guess {
    // EXTERNAL: TITANIUM 0x004C1409 Map_48AAA6_guess::ResendFindRequest_guess
    void ResendFindRequest_guess();
};

struct Message_48AAA6_guess {
    unsigned short spawnId_0000_guess;
    unsigned short value_002_guess;
    int data_004_guess[10];
};

struct Position_48AAA6_guess {
    float saved_z_guess;
    Vector_48A324_guess coordinates_guess;
};

// EXTERNAL: TITANIUM 0x00465244 pack_physics_guess
void __cdecl pack_physics_guess(Vector_48A324_guess* position_guess,
    void* buffer_guess, Player_48BA76_guess* player_guess);

// EXTERNAL: TITANIUM 0x004B718D ?FUN_004b718d_48AAA6_guess@@YAPAUBuffer_48AAA6_guess@@XZ
Buffer_48AAA6_guess* __cdecl FUN_004b718d_48AAA6_guess();
// EXTERNAL: TITANIUM 0x004B718D ?FUN_004b718d_48AAA6_guess@@YAPAUBuffer_48AAA6_guess@@PAUVector_48A324_guess@@H@Z
Buffer_48AAA6_guess* __cdecl FUN_004b718d_48AAA6_guess(Vector_48A324_guess* position_guess, int count_guess);

void __fastcall UpdateSharedValuesIfLocal_guess(unsigned int param_1);

// Warps the player: within the zone, clamps the values, moves the spawn and sends OP_ClientUpdate (0x24
// bytes); to another zone, MoveToZone_guess. Refused while feigned or linkdead.
// FUNCTION: TITANIUM 0x0048AAA6
// @early-stop: budget, structural ndiff=92
char Player_48BA76_guess::WarpPlayer_guess(unsigned int state_guess, float x_guess, float y_guess,
    float z_guess, float heading_guess, void* value_guess, int zero_guess)
{
    if (standState_0251_guess == 'f' || linkdead_01b2_guess != 0)
        return 0;

    Message_48AAA6_guess message_guess;
    Position_48AAA6_guess position_guess;
    message_guess.spawnId_0000_guess = EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)->spawnId_0258_guess;
    pack_physics_guess(&EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)->position_030_guess,
        message_guess.data_004_guess, EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4));
    ((State_48C_guess*)this)->UpdateIfCurrentWithPosition_guess(0);
    Buffer_48AAA6_guess* buffer_guess = FUN_004b718d_48AAA6_guess();
    message_guess.value_002_guess = buffer_guess->value_018_guess;
    FUN_004b718d_48AAA6_guess(&EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)->position_030_guess, 2)
        ->Commit_48AAA6_guess(&EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)->position_030_guess, 2);
    ((State_48C_guess*)this)->SendMovementHistory_guess(0);
    if (zero_guess == 0)
        EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_ClientUpdate, &message_guess, 0x24, 1);

    ((State_48A8D4_guess*)this)->Update_guess();
    if (x_guess < EQ_GLOBAL(float, 0x006485D4))
        position_030_guess.x_guess = x_guess;
    if (y_guess < EQ_GLOBAL(float, 0x006485D4))
        position_030_guess.y_guess = y_guess;
    if (z_guess < EQ_GLOBAL(float, 0x006485D4))
        position_030_guess.z_guess = z_guess;
    if (heading_guess < EQ_GLOBAL(float, 0x006485D0))
        heading_004c_guess = heading_guess;

    if (EQ_GLOBAL(Scene_48AAA6_guess*, 0x00988DF0)->value_b54_guess == 1 ||
        state_guess == (unsigned int)state_204_guess) {
        position_guess.saved_z_guess = position_030_guess.z_guess;
        position_030_guess.z_guess = position_guess.saved_z_guess;
        position_guess.coordinates_guess.x_guess = x_guess;
        position_guess.coordinates_guess.y_guess = y_guess;
        position_guess.coordinates_guess.z_guess = z_guess;
        FUN_004b718d_48AAA6_guess(&position_guess.coordinates_guess, 3)
            ->Commit_48AAA6_guess(&position_guess.coordinates_guess, 3);
        float floor_guess = ((State_48995D_guess*)this)->GetFloorHeightAt_guess(
            position_030_guess.x_guess, position_030_guess.y_guess,
            position_030_guess.z_guess + EQ_GLOBAL(float, 0x0063F4D0), 1);
        if (floor_guess != EQ_GLOBAL(float, 0x00640EA0))
            ((Data_48AAA6_guess*)pActorInfo_01a8_guess)->floor_048_guess = floor_guess;
        ((State_48995D_guess*)this)->Update_48A945_guess();
        Data_48AAA6_guess* data_guess = (Data_48AAA6_guess*)pActorInfo_01a8_guess;
        data_guess->value_150_guess = 0;
        data_guess->value_158_guess = 0;
        data_guess->value_f94_guess = 0;
        EQ_GLOBAL(Map_48AAA6_guess*, 0x00985C88)->ResendFindRequest_guess();
        UpdateSharedValuesIfLocal_guess((unsigned int)EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4));
    } else {
        if (race_260_guess == 8 || (race_260_guess > 10 && race_260_guess < 13))
            position_030_guess.z_guess += EQ_GLOBAL(float, 0x0063F4D0);
        Player_48BA76_guess* player_guess = EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4);
        unsigned int heading_value_guess = (unsigned int)heading_004c_guess;
        EQ_GLOBAL(Scene_48AAA6_guess*, 0x00988DF0)->MoveToZone_guess(state_guess, value_guess, 0,
            zero_guess, player_guess->position_030_guess.x_guess, player_guess->position_030_guess.y_guess,
            player_guess->position_030_guess.z_guess, heading_value_guess);
        UpdateSharedValuesIfLocal_guess((unsigned int)this);
    }
    return 1;
}

struct MovementInterface_48B52C_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual unsigned int GetFlags_guess(Vector_48A324_guess* position_guess);
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual char CheckPosition_guess(Vector_48A324_guess* position_guess);
};

#define g_movement_interface_48B52C_guess EQ_GLOBAL(MovementInterface_48B52C_guess*, 0x0099E368)

// Updates the region type under the spawn (water, lava...) and fires the feet/head environment changes.
// FUNCTION: TITANIUM 0x00489B0A
void Player_48BA76_guess::Fix_489B0A_guess()
{
    Vector_48A324_guess position_guess;
    position_guess.x_guess = position_030_guess.x_guess;
    position_guess.y_guess = position_030_guess.y_guess;
    position_guess.z_guess = position_030_guess.z_guess;
    if (g_world_48A026_guess->IsLoaded_guess(&position_guess)) {
        Actor_489B0A_guess* actor_guess = pActorInfo_01a8_guess->actorInstance_0000_guess;
        if (actor_guess != 0)
            actor_guess->Update_028_guess();
        unsigned int value_guess = (unsigned char)g_display_48A026_guess->GetEnvironment_guess(
            position_guess.x_guess, position_guess.y_guess, position_guess.z_guess, 0);
        if (value_guess != pActorInfo_01a8_guess->value_0a4_guess) {
            pActorInfo_01a8_guess->value_0a4_guess = value_guess;
            SetRegionType_guess(value_guess);
        }
    }
    position_guess.z_guess += eyeHeight_0234_guess - heightOffset_0238_guess;
    if (g_world_48A026_guess->IsLoaded_guess(&position_guess)) {
        unsigned int value_guess = (unsigned char)g_display_48A026_guess->GetEnvironment_guess(
            position_guess.x_guess, position_guess.y_guess, position_guess.z_guess, 0);
        if (value_guess != pActorInfo_01a8_guess->value_0a0_guess) {
            pActorInfo_01a8_guess->value_0a0_guess = value_guess;
            headEnvironmentChange_guess(value_guess);
        }
    }
}

struct Source_48BE7E_guess {
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
    virtual void Slot0a_guess();
    virtual void Slot0b_guess();
    virtual void Slot0c_guess();
    virtual void Slot0d_guess();
    virtual void Slot0e_guess();
    virtual void Slot0f_guess();
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
    virtual void Slot1a_guess();
    virtual void Slot1b_guess();
    virtual void Slot1c_guess();
    virtual void Slot1d_guess();
    virtual void Slot1e_guess();
    virtual void Slot1f_guess();
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
    virtual void Slot2a_guess();
    virtual void Slot2b_guess();
    virtual void Slot2c_guess();
    virtual void GetPosition_guess(Vector_48A324_guess* position_guess);
};

// State mode 1 (0x00924824), our own player only: once the engine position (0x0099E364) has moved more
// than 2 units in x or y since the last time (0x0078D85C/0x0078D858), re-sends the negated engine vector
// (0x00439DB8) and stores the new spot.
// FUNCTION: TITANIUM 0x0048BE7E
void Player_48BA76_guess::Update_48BE7E_guess()
{
    if (EQ_GLOBAL(int, 0x00924824) == 1 && this == EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)) {
        Vector_48A324_guess position_guess;
        EQ_GLOBAL(Source_48BE7E_guess*, 0x0099E364)->GetPosition_guess(&position_guess);
        if (fabs(position_guess.x_guess - EQ_GLOBAL(float, 0x0078D85C)) > 2.0f ||
            fabs(position_guess.y_guess - EQ_GLOBAL(float, 0x0078D858)) > 2.0f) {
            g_display_48A026_guess->UpdateGrassDisplacement_guess();
            EQ_GLOBAL(float, 0x0078D85C) = position_guess.x_guess;
            EQ_GLOBAL(float, 0x0078D858) = position_guess.y_guess;
        }
    }
}

// Per-frame movement for one spawn; logs a null actor with its race and sex.
// FUNCTION: TITANIUM 0x0048BA76
int Player_48BA76_guess::MovePlayer()
{
    g_display_48A026_guess->time_148_guess = FUN_0046d655_guess();
    if (this == 0) {
        FUN_00574110_guess("** this is NULL (in MovePlayer)!!!!\n");
    } else {
        if (!Check_48C5F1_guess()) {
            Update_48BE7E_guess();
            ((State_48BF_guess*)this)->UpdateIfActive_guess();
            ((State_48BF35_guess*)this)->UpdateIfReady_guess();
            if (pActorInfo_01a8_guess->actorInstance_0000_guess == 0) {
                FUN_00574110_guess("EQPlayer::MovePlayer() - Null actor pointer!\n%s:race = %d sex = %d",
                    name_120_guess, race_260_guess, sex_24e_guess);
            } else {
                Vector_48A324_guess position_guess;
                ((State_48995D_guess*)this)->Copy_48A324_guess(&position_guess);
                NoOp_guess();
                char flag_guess = Pick_48ACEF_guess(&position_guess);
                Apply_48BFA2_guess(flag_guess);
                if (!UpdateRegion_guess(&position_guess))
                    Fix_489B0A_guess();
            }
        }
    }
    return 1;
}

// Collision step for a move to `position_guess`, within the zone bounds plus 2000; counts blocked moves
// (+0x2E8).
// FUNCTION: TITANIUM 0x0048ACEF
// @early-stop: budget, structural ndiff=483
char Player_48BA76_guess::Pick_48ACEF_guess(Vector_48A324_guess* position_guess)
{
    Actor_489B0A_guess* actor_guess = pActorInfo_01a8_guess->actorInstance_0000_guess;
    Vector_48A324_guess current_guess;
    actor_guess->GetPosition_058_guess(&current_guess);
    value_2e8_guess++;
    if (g_collider_48ACEF_guess->IsActive_04c_guess()) {
        Vector_48A324_guess low_guess;
        Vector_48A324_guess high_guess;
        g_world_48A026_guess->GetBounds_guess(&low_guess, &high_guess);
        // A target more than 2000 units outside the zone's box is refused: motion stops and the last good
        // position (+0xB0) comes back.
        float margin_guess = 2000.0f;
        low_guess.x_guess -= margin_guess;
        low_guess.y_guess -= margin_guess;
        low_guess.z_guess -= margin_guess;
        high_guess.x_guess += margin_guess;
        high_guess.y_guess += margin_guess;
        high_guess.z_guess += margin_guess;
        if (!position_guess->IsLess_guess(&high_guess) || !position_guess->IsGreater_guess(&low_guess)) {
            velocity_03c_guess.x_guess = 0.0f;
            velocity_03c_guess.y_guess = 0.0f;
            velocity_03c_guess.z_guess = 0.0f;
            position_030_guess = saved_0b0_guess;
            return 0;
        }
    }
    char can_move_guess = ((State_48995D_guess*)this)->Check_4898_guess();
    Vector_48A324_guess previous_guess = position_030_guess;
    // The sweep runs at the model's centre: both ends are lifted by the height offset and lowered again at
    // the end.
    float height_guess = ((State_48995D_guess*)this)->Calculate_489A32_guess();
    current_guess.z_guess += height_guess;
    position_guess->z_guess += height_guess;
    position_030_guess = *position_guess;
    Vector_48A324_guess start_guess = current_guess;
    float dz_guess = position_guess->z_guess - current_guess.z_guess;
    Vector_48A324_guess result_guess = *position_guess;
    float dy_guess = position_guess->y_guess - current_guess.y_guess;
    Vector_48A324_guess delta_guess;
    delta_guess.x_guess = position_guess->x_guess - current_guess.x_guess;
    delta_guess.y_guess = dy_guess;
    delta_guess.z_guess = dz_guess;
    float radius_guess = actor_guess->Update_028_guess();
    Sweep_48ACEF_guess sweep_guess;
    sweep_guess.segment_guess.Set_guess(&current_guess, &delta_guess);
    sweep_guess.radius_guess = radius_guess;
    float move_x_guess = delta_guess.x_guess;
    float move_y_guess = dy_guess;
    float move_z_guess = dz_guess;
    char stuck_guess = 0;
    char busy_guess = ((State_48996B_guess*)this)->Check_48996B_guess();
    // A move under 0.01 on every axis after the first two calls is no move. Out of water (+0xAD < 5) the
    // spawn is marked idle (+0x130 = now, also on the spawn at +0x160) and, unless busy and with +0x48 at
    // zero, counts as stuck; in water only the idle time is stamped.
    if (busy_guess || value_2e8_guess <= 2 || fabs(delta_guess.x_guess) >= 0.01f ||
        fabs(dy_guess) >= 0.01f || fabs(dz_guess) >= 0.01f) {
        pActorInfo_01a8_guess->value_150_guess = 0;
    } else {
        *position_guess = current_guess;
        move_z_guess = 0.0f;
        move_y_guess = 0.0f;
        move_x_guess = 0.0f;
        if (pActorInfo_01a8_guess->value_0ad_guess >= 5 && pActorInfo_01a8_guess->value_130_guess == 0)
            pActorInfo_01a8_guess->value_130_guess = g_display_48A026_guess->time_148_guess;
    }
    if (value_2e8_guess > 2 && move_x_guess < 0.01f && move_x_guess > -0.01f &&
        move_y_guess < 0.01f && move_y_guess > -0.01f &&
        move_z_guess < 0.01f && move_z_guess > -0.01f &&
        pActorInfo_01a8_guess->value_0ad_guess < 5) {
        if (pActorInfo_01a8_guess->value_130_guess == 0) {
            pActorInfo_01a8_guess->value_130_guess = g_display_48A026_guess->time_148_guess;
            Player_48BA76_guess* linked_guess = pActorInfo_01a8_guess->rider_0160_guess;
            if (linked_guess != 0)
                linked_guess->pActorInfo_01a8_guess->value_130_guess = g_display_48A026_guess->time_148_guess;
        }
        if (!busy_guess && speedRun_0048_guess == 0.0f) {
            stuck_guess = 1;
            can_move_guess = 0;
        }
    }
    void* filter_guess = (void*)SweepFilterLinked_guess;
    if (pActorInfo_01a8_guess->rider_0160_guess == 0)
        filter_guess = (void*)SweepFilter_guess;
    value_2e5_guess = 0;
    char hit_guess = 0;
    Vector_48A324_guess normal_guess;
    float fraction_guess;
    // Swept-sphere collision against the world (radius from the actor). On a hit (fraction > 0) a second
    // sweep runs from the start to the hit point pushed out along the normal by the fraction; a spawn that
    // may not move only settles, or follows its ride (+0x1B6).
    if (can_move_guess) {
        g_collider_48ACEF_guess->Sweep_020_guess(actor_guess, &start_guess, position_guess, filter_guess,
            (void*)RecordCollisionHit_guess, this, &result_guess, &normal_guess, &fraction_guess, 0);
        if (fraction_guess > 0.0f) {
            Vector_48A324_guess restart_guess = start_guess;
            hit_guess = 1;
            delta_guess = normal_guess * fraction_guess;
            delta_guess.x_guess = result_guess.x_guess + delta_guess.x_guess;
            delta_guess.y_guess = result_guess.y_guess + delta_guess.y_guess;
            delta_guess.z_guess = result_guess.z_guess + delta_guess.z_guess;
            g_collider_48ACEF_guess->Sweep_020_guess(actor_guess, &restart_guess, &delta_guess, filter_guess,
                (void*)RecordCollisionHit_guess, this, &result_guess, &normal_guess, &fraction_guess, 0);
        }
    } else {
        Settle_48C63F_guess();
        if (value_1b6_guess)
            Follow_48A447_guess(position_guess, &result_guess);
    }
    position_030_guess = result_guess;
    // The controlled spawn may not leave loaded world or end in a bad spot (Check_48BB83_guess): it is put
    // back (+0x2E5 = refused).
    if (can_move_guess && IsControlledPlayer_guess() && !value_1b6_guess && !stuck_guess &&
        !value_2e5_guess &&
        (!g_world_48A026_guess->IsLoaded_guess(&position_030_guess) ||
         !Check_48BB83_guess(&position_030_guess, hit_guess == 0))) {
        value_2e5_guess = 1;
        position_030_guess = previous_guess;
        stuck_guess = 1;
    }
    Vector_48A324_guess moved_guess;
    moved_guess.z_guess = position_030_guess.z_guess - start_guess.z_guess;
    moved_guess.y_guess = position_030_guess.y_guess - start_guess.y_guess;
    moved_guess.x_guess = position_030_guess.x_guess - start_guess.x_guess;
    moved_guess.Abs_guess();
    char still_guess;
    // Whether the sweep moved at all; with no vertical progress the downward speed is held to -1.
    if (moved_guess.z_guess <= 0.001f &&
        moved_guess.z_guess * moved_guess.z_guess + moved_guess.y_guess * moved_guess.y_guess +
        moved_guess.x_guess * moved_guess.x_guess < 1.0000001e-6f)
        still_guess = 1;
    else
        still_guess = 0;
    if (!value_2e5_guess) {
        if (value_1b6_guess) {
            stuck_guess = value_2e4_guess;
        } else if (still_guess && value_2e8_guess > 2) {
            stuck_guess = 1;
        } else {
            value_2e4_guess = 0;
            if (moved_guess.z_guess < 0.001f && velocity_03c_guess.z_guess < -1.0f)
                velocity_03c_guess.z_guess = -1.0f;
            hit_guess = still_guess;
            if (!still_guess || value_2e8_guess <= 2) {
                UpdateFloor_48BB7B_guess(0);
                hit_guess = 0;
                if (((Actor_489BF5_guess*)this)->Advance_489C51_guess() && IsControlledPlayer_guess()) {
                    // Two extra probes for the controlled spawn: the floor drop under the new spot and the
                    // 0.1-radius path from the start; either one hitting refuses the move.
                    Derived_48A3FF_guess drop_guess((ValueInterface_489A32_guess*)actor_guess,
                        (int)&position_030_guess, (int)&position_030_guess);
                    if (g_collider_48ACEF_guess->Test_00c_guess(&drop_guess)) {
                        value_2e5_guess = 1;
                        can_move_guess = 0;
                    }
                }
            }
            if (hit_guess)
                stuck_guess = 1;
            if (IsControlledPlayer_guess() && can_move_guess && !value_1b6_guess) {
                Derived_48A3FF_guess step_guess((ValueInterface_489A32_guess*)actor_guess,
                    (int)&start_guess, (int)&position_030_guess, 0.1f);
                if (g_collider_48ACEF_guess->Test_00c_guess(&step_guess))
                    value_2e5_guess = 1;
            }
        }
    }
    // Commit: the actor gets the new position (back at foot height) and the player's move is reported;
    // otherwise vertical motion stops and the last good position is restored.
    if (!value_2e5_guess && !stuck_guess) {
        current_guess.x_guess = position_030_guess.x_guess;
        current_guess.y_guess = position_030_guess.y_guess;
        current_guess.z_guess = position_030_guess.z_guess - height_guess;
        actor_guess->SetPosition_048_guess(&current_guess);
        position_030_guess.z_guess -= height_guess;
        if (IsLocalPlayer_guess())
            AddSharedOwnerValues_guess();
    } else {
        velocity_03c_guess.z_guess = 0.0f;
        position_030_guess = saved_0b0_guess;
    }
    Finish_48A7F9_guess();
    EmptyCallback2_guess(&start_guess, &current_guess);
    return !(velocity_03c_guess.Length_guess() > 0.0f);
}

// Restores the base vtable (0x00645E5C).
// FUNCTION: TITANIUM 0x0048BB3B
void __fastcall FUN_0048bb3b_guess(StateVtable_48BB3B_guess* param_1)
{
    param_1->vtable_000_guess = (unsigned int)&EQ_GLOBAL(unsigned int, 0x00645E5C);
}

// True when `param_1` is the local player (0x00905CE4).
// FUNCTION: TITANIUM 0x0048BB42
bool __fastcall IsLocalPlayer_guess(unsigned int param_1)
{
    return param_1 == EQ_GLOBAL(unsigned int, 0x00905CE4);
}

// Teleport text for the local player (DoTeleport_guess, then a warp); for a controlled spawn of race 108
// shows message 0x43 instead.
// FUNCTION: TITANIUM 0x0048B42B
// @early-stop: budget, structural ndiff=21
char Player_48BA76_guess::Handle_48B42B_guess(const char* message_guess, int value_guess, void** state_guess)
{
    if (this != EQ_GLOBAL(Player_48BA76_guess*, 0x00905CE4)) {
        if (IsControlledPlayer_guess() != 0 && race_260_guess == 0x6c) {
            void* message_value_guess = g_manager_48B42B_guess->window_c280_guess.FindBuffWithEffect_guess(
                0x43, &state_guess);
            g_manager_48B42B_guess->window_c280_guess.RemovePCAffect_guess(message_value_guess);
        }
        return 0;
    }

    TeleportLogger_489CC2_guess logger_guess;
    float values_guess[4];
    logger_guess.handle_000_guess = 0;
    if (((State_48995D_guess*)this)->Forward_489FDA_guess((int)message_guess, value_guess,
            (int)values_guess, (int)state_guess, (int)&logger_guess,
            (int)&((StackSlot3_48B42B_guess*)&value_guess)->value_003_guess,
            (int)&((StackSlot3_48B42B_guess*)&state_guess)->value_003_guess,
            (int)&message_guess) != 0) {
        if (WarpPlayer_guess((unsigned int)*state_guess, values_guess[0], values_guess[1],
                values_guess[2], values_guess[3], logger_guess.GetValue_guess(), 0) != 0)
            return 1;
    }
    return 0;
}

// Region flags at head height: on a change, updates swimming and lava drag (0x3F7D70A4 = 0.99, 0x3CA3D70A =
// 0.02) and, in zone 126, shows 12009 "You have entered an Arena (PvP) area.".
// FUNCTION: TITANIUM 0x0048B52C
// @early-stop: budget, structural ndiff=60
char Player_48BA76_guess::UpdateRegion_guess(Vector_48A324_guess* position_guess)
{
    Vector_48A324_guess adjusted_guess = *position_guess;
    float speed_guess = heightOffset_0238_guess;
    adjusted_guess.z_guess += 0.25f -
        (((State_48995D_guess*)this)->Calculate_4899D3_guess() - speed_guess);

    if (g_movement_interface_48B52C_guess->CheckPosition_guess(&adjusted_guess) == 0)
        return 0;

    unsigned int flags_guess = g_movement_interface_48B52C_guess->GetFlags_guess(&adjusted_guess);
    if (flags_guess == pActorInfo_01a8_guess->regionFlags_00a8_guess)
        return 0;

    pActorInfo_01a8_guess->regionFlags_00a8_guess = flags_guess;
    if ((flags_guess & 0x10000000) == 0 || type_0244_guess == 1) {
        pActorInfo_01a8_guess->value_0b4_guess = EQ_GLOBAL(unsigned int, 0x009237C0);
        pActorInfo_01a8_guess->value_0b8_guess = EQ_GLOBAL(unsigned int, 0x009237C4);
    } else {
        pActorInfo_01a8_guess->value_0b4_guess = 0x3f7d70a4;
        pActorInfo_01a8_guess->value_0b8_guess = 0x3ca3d70a;
    }

    if ((int)flags_guess < 0) {
        void* result_state_guess = state_204_guess;
        ((State_48C_guess*)this)->UpdateIfCurrentWithArgs_guess((int)&adjusted_guess, 4);
        if (Handle_48B42B_guess(&g_display_48A026_guess->message_015_guess, -1,
                &result_state_guess) != 0)
            return 1;
        if (result_state_guess == state_204_guess)
            ((State_48C_guess*)this)->UpdateIfCurrentWithArgs_guess((int)&adjusted_guess, 5);
    }

    pActorInfo_01a8_guess->value_0b0_guess = (unsigned char)((flags_guess >> 30) & 1);
    if (EQ_GLOBAL(unsigned int, 0x00924470) == 0x7e)
        pActorInfo_01a8_guess->value_0b0_guess = 0;
    if (pActorInfo_01a8_guess->value_0b0_guess != 0 && IsLocalPlayer_guess() != 0) {
        pEverQuest->dsp_chat(pStringTable->getString(0x2ee9, 0));
    }
    feetEnvironmentChange_guess(flags_guess);
    return 0;
}

struct ZoneInfo_48B6C5_guess {
    // EXTERNAL: TITANIUM 0x005FA1C0 ZoneInfo_48B6C5_guess::GetZoneName_guess
    void GetZoneName_guess(int zone_guess, char* output_guess, int flag_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, unsigned int size_guess,
    const char* format_guess, ...);

struct MoveMessage_48B6C5_guess {
    unsigned int id_guess;
    Vector_48A324_guess position_guess;
};

struct PositionQueue_48B6C5_guess {
    // EXTERNAL: TITANIUM 0x004B70DB PositionQueue_48B6C5_guess::Push_guess
    void Push_guess(Vector_48A324_guess* position_guess, int flags_guess);
};

// EXTERNAL: TITANIUM 0x004B718D GetPositionQueue_48B6C5_guess
PositionQueue_48B6C5_guess* __cdecl GetPositionQueue_48B6C5_guess();

// Below the floor: lands the spawn, with fall sound 114 and fall damage (IHaveFallen_guess) for a fall faster
// than 2.5. Far below the world sends OP_UnderWorld and logs string 1279 "Player is beneath the world..."
// before moving to the safe point.
// FUNCTION: TITANIUM 0x0048B6C5
// @early-stop: budget, structural ndiff=31
void State_48995D_guess::CheckForUnderFloor_guess()
{
    MoveMessage_48B6C5_guess message_guess;
    float floor_guess = pActorInfo_01a8_guess->floorHeight_0048_guess;
    float height_guess = heightOffset_0238_guess;
    if (position_0030_guess.z_guess - height_guess < floor_guess) {
        if (pActorInfo_01a8_guess->value_0ad_guess == 0 && race_0260_guess != 0x7f &&
            velocityZ_0044_guess + velocityZ_0044_guess <= -2.5f)
            PlaySound_guess(0x72);
        if (velocityZ_0044_guess <= -2.5f) {
            float amount_guess = (float)fabs(velocityZ_0044_guess - -2.5f);
            if (type_0244_guess == 0) {
                IHaveFallen_guess(amount_guess);
            } else if (pActorInfo_01a8_guess != 0 && pActorInfo_01a8_guess->rider_0160_guess != 0) {
                ((State_48995D_guess*)pActorInfo_01a8_guess->rider_0160_guess)->IHaveFallen_guess(amount_guess);
            }
        }
        velocityZ_0044_guess = 0.0f;
        position_0030_guess.z_guess = height_guess + floor_guess;
        pActorInfo_01a8_guess->value_04c_guess = -1.0e27f;
    } else if (position_0030_guess.z_guess - height_guess > floor_guess && velocityZ_0044_guess < 0.0f &&
        pActorInfo_01a8_guess->value_04c_guess == -1.0e27f) {
        pActorInfo_01a8_guess->value_04c_guess = position_0030_guess.z_guess;
    }

    height_guess = position_0030_guess.z_guess - height_guess;
    if (height_guess < EQ_GLOBAL(float, 0x00923BDC)) {
        char self_guess = (char)((Player_48BA76_guess*)this)->IsLocalPlayer_guess();
        unsigned int local_player_guess = EQ_GLOBAL(unsigned int, 0x00905CE4);
        if (self_guess == 0 && pActorInfo_01a8_guess->rider_0160_guess != (int)local_player_guess) {
            if (type_0244_guess != 0 && EQ_GLOBAL(unsigned char, 0x00923B88) != 0) {
                float ground_guess = g_display_48A026_guess->GetFloorHeight_guess(
                    position_0030_guess.x_guess, position_0030_guess.y_guess, 32000.0f);
                if (ground_guess == -1.0e27f)
                    return;
                if (ground_guess < EQ_GLOBAL(float, 0x00923BD8) - 10.0f) {
                    message_guess.position_guess.x_guess = position_0030_guess.x_guess;
                    message_guess.position_guess.y_guess = position_0030_guess.y_guess;
                    message_guess.position_guess.z_guess = ground_guess;
                    WarpToPosition_guess(&message_guess.position_guess, heading_004c_guess);
                } else {
                    ground_guess = g_display_48A026_guess->GetFloorHeight_guess(
                        position_0030_guess.x_guess, position_0030_guess.y_guess, ground_guess);
                    if (ground_guess == -1.0e27f)
                        return;
                    if (ground_guess >= EQ_GLOBAL(float, 0x00923BD8) - 10.0f)
                        return;
                    message_guess.position_guess.x_guess = position_0030_guess.x_guess;
                    message_guess.position_guess.y_guess = position_0030_guess.y_guess;
                    message_guess.position_guess.z_guess = ground_guess;
                    WarpToPosition_guess(&message_guess.position_guess, heading_004c_guess);
                }
            }
            return;
        }
        if (EQ_GLOBAL(unsigned int, 0x00924470) != 0x47 ||
            ((Player_48BA76_guess*)local_player_guess)->Handle_48B42B_guess(
                EQ_ARRAY(char, 0x0063FE10), 0xb, (void**)&floor_guess) == 0) {
            message_guess.id_guess = spawnId_0258_guess;
            Vector_48A324_guess* position_guess = &position_0030_guess;
            message_guess.position_guess.x_guess = position_guess->x_guess;
            message_guess.position_guess.y_guess = position_guess->y_guess;
            message_guess.position_guess.z_guess = position_guess->z_guess;
            EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), OP_UnderWorld,
                &message_guess, 0x10, 1);
            const char* format_guess = "%.3f";
            sprintf(EQ_ARRAY(char, 0x0099DB00), format_guess, message_guess.position_guess.x_guess);
            sprintf(EQ_ARRAY(char, 0x0099DAE0), format_guess, message_guess.position_guess.y_guess);
            sprintf(EQ_ARRAY(char, 0x0099DF60), format_guess, message_guess.position_guess.z_guess);
            char zone_name_guess[0x50];
            EQ_GLOBAL(ZoneInfo_48B6C5_guess*, 0x00905CC0)->GetZoneName_guess(
                zoneId_0204_guess, zone_name_guess, 1);
            char message_text_guess[0x200];
            FUN_0046da4a_guess(message_text_guess, 0x4ff, zone_name_guess,
                EQ_ARRAY(char, 0x0099DB00), EQ_ARRAY(char, 0x0099DAE0),
                EQ_ARRAY(char, 0x0099DF60), 0, 0, 0, 0, 0);
            pEverQuest->dsp_chat(message_text_guess);
            FUN_00574110_guess(message_text_guess);
            FUN_00574110_guess(EQ_ARRAY(char, 0x00641588));
            FUN_00574110_guess("hp = %f,%f, nfh = %f, soh = %f, cp = %x\n",
                heading_004c_guess, value_05c_guess, height_guess, heightOffset_0238_guess, this);
            GetPositionQueue_48B6C5_guess()->Push_guess(&position_0030_guess, 8);
            g_display_48A026_guess->ResetLocalPlayer_guess();
            FUN_00574110_guess("finished MoveLocalPlayerToSafeCoords.\n");
        }
    }
}

// True when `param_1` is the controlled spawn (0x00905CF8).
// FUNCTION: TITANIUM 0x0048BB4E
bool __fastcall IsControlledPlayer_guess(unsigned int param_1)
{
    return param_1 == EQ_GLOBAL(unsigned int, 0x00905CF8);
}

// EXTERNAL: TITANIUM 0x004B6088 FUN_004b6088_guess
void* __cdecl FUN_004b6088_guess();

// EXTERNAL: TITANIUM 0x004B60C2 FUN_004b60c2_guess
void __fastcall FUN_004b60c2_guess(void* param_1);

// EXTERNAL: TITANIUM 0x004B60F2 FUN_004b60f2_guess
void __fastcall FUN_004b60f2_guess(void* param_1);

// For the local player only: resets the position history to where the player stands (0x004B60C2).
// FUNCTION: TITANIUM 0x0048BB5A
void __fastcall UpdateSharedValuesIfLocal_guess(unsigned int param_1)
{
    if (param_1 == EQ_GLOBAL(unsigned int, 0x00905CE4))
        FUN_004b60c2_guess(FUN_004b6088_guess());
}

// Records the player's position in the position history when moved (0x004B60F2).
// FUNCTION: TITANIUM 0x0048BB6F
void __cdecl AddSharedOwnerValues_guess()
{
    FUN_004b60f2_guess(FUN_004b6088_guess());
}

// Floor refresh with an ignored argument (a callback signature).
// FUNCTION: TITANIUM 0x0048BB7B
void State_48995D_guess::UpdateIgnoring_48BB7B_guess(int unused_guess)
{
    Update_48A6F2_guess();
}

struct Runtime_48BB83_guess {
    virtual void Slot_00_guess();
    virtual void Slot_04_guess();
    virtual void Slot_08_guess();
    virtual void Slot_0c_guess();
    virtual void Slot_10_guess();
    virtual void Slot_14_guess();
    virtual void Slot_18_guess();
    virtual void Slot_1c_guess();
    virtual void Slot_20_guess();
    virtual void Slot_24_guess();
    virtual void Slot_28_guess();
    virtual void Slot_2c_guess();
    virtual void Slot_30_guess();
    virtual void Slot_34_guess();
    virtual void Slot_38_guess();
    virtual void Slot_3c_guess();
    virtual void Slot_40_guess();
    virtual void Slot_44_guess();
    virtual void Slot_48_guess();
    virtual char IsReady_guess();
};

struct HeightGetter_48BB83_guess {
    virtual void Slot_00_guess();
    virtual void Slot_04_guess();
    virtual void Slot_08_guess();
    virtual void Slot_0c_guess();
    virtual void Slot_10_guess();
    virtual void Slot_14_guess();
    virtual void Slot_18_guess();
    virtual void Slot_1c_guess();
    virtual void Slot_20_guess();
    virtual void Slot_24_guess();
    virtual float GetHeight_guess();
};

// For the controlled player: checks the target spot has a floor (zones 71, 75 and 150 are exempt) and sets
// the no-fall grace flag 0x9237B9 with its timeout.
// FUNCTION: TITANIUM 0x0048BB83
// @early-stop: budget, structural ndiff=143
char Player_48BA76_guess::Check_48BB83_guess(Vector_48A324_guess* position_guess, bool)
{
    if (this != EQ_GLOBAL(Player_48BA76_guess*, 0x00905CF8) ||
        EQ_GLOBAL(Runtime_48BB83_guess*, 0x0099E370)->IsReady_guess() == 0)
        return 1;

    float height_guess = 1.0f;
    if (pActorInfo_01a8_guess->actorInstance_0000_guess != 0)
        height_guess = ((HeightGetter_48BB83_guess*)pActorInfo_01a8_guess->actorInstance_0000_guess)->GetHeight_guess();

    float saved_speed_guess = value_2f8_guess;
    float floor_guess = ((State_48995D_guess*)this)->GetFloorHeightAt_guess(
        position_guess->x_guess, position_guess->y_guess, position_guess->z_guess, 0);
    if (floor_guess != EQ_GLOBAL(float, 0x00640EA0) ||
        EQ_GLOBAL(int, 0x00924470) == 0x47 || EQ_GLOBAL(int, 0x00924470) == 0x4b ||
        EQ_GLOBAL(int, 0x00924470) == 0x96) {
        if (position_guess->x_guess != value_2fc_guess ||
            position_guess->y_guess != value_300_guess ||
            position_guess->z_guess + 0.001f < value_304_guess ||
            position_guess->z_guess + 0.001f > value_308_guess - height_guess ||
            0.01f < fabs((double)(saved_speed_guess - floor_guess))) {
            Clear_489955_guess();
            value_2fc_guess = position_guess->x_guess;
            value_300_guess = position_guess->y_guess;
            value_304_guess = position_guess->z_guess;
        }

        float destination_guess;
        if (Check_48995D_guess()) {
            destination_guess = value_308_guess;
        } else {
            destination_guess = g_display_48A026_guess->GetCeilingHeight_guess(
                position_guess->x_guess, position_guess->y_guess, position_guess->z_guess, height_guess);
        }

        if (destination_guess != EQ_GLOBAL(float, 0x00640EA0)) {
            float projected_guess = ((State_48995D_guess*)this)->Calculate_4899D3_guess() +
                heightOffset_0238_guess + floor_guess;
            float step_guess;
            if (standState_0251_guess == 'o') {
                step_guess = heightOffset_0238_guess + 1.0f;
            } else if (((State_48995D_guess*)this)->IsHorseRace_guess() != 0 &&
                       pActorInfo_01a8_guess->rider_0160_guess != 0) {
                step_guess = heightOffset_0238_guess * 3.0f;
            } else if (stepHeight_022c_guess <= 0.0f) {
                step_guess = heightOffset_0238_guess + heightOffset_0238_guess;
            } else {
                step_guess = stepHeight_022c_guess;
            }

            if (step_guess + floor_guess + 0.5f < destination_guess ||
                destination_guess <= floor_guess) {
                if (EQ_GLOBAL(unsigned char, 0x009237B9) != 0 &&
                    EQ_GLOBAL(unsigned int, 0x009237BC) < g_display_48A026_guess->time_148_guess &&
                    projected_guess + height_guess < destination_guess) {
                    EQ_GLOBAL(unsigned char, 0x009237B9) = 0;
                    EQ_GLOBAL(unsigned int, 0x009237BC) = 0;
                    ((State_48995D_guess*)this)->ChangePosition_guess(100);
                }
                if (step_guess <= destination_guess - floor_guess) {
                    pActorInfo_01a8_guess->ceilingHeight_01b0_guess = destination_guess;
                    value_308_guess = destination_guess;
                    return 1;
                }
            } else {
                if (standState_0251_guess != 'd')
                    return 0;
                if (EQ_GLOBAL(unsigned char, 0x009254F6) == 0)
                    return 0;
                EQ_GLOBAL(unsigned char, 0x009237B9) = 1;
                EQ_GLOBAL(unsigned int, 0x009237BC) =
                    g_display_48A026_guess->time_148_guess + 2000;
            }
        } else {
            value_2f8_guess = saved_speed_guess;
            Clear_489955_guess();
            return 1;
        }
    }

    value_2f8_guess = saved_speed_guess;
    Clear_489955_guess();
    return 0;
}

// When the actor's +0xF94 flag is set: the local player runs the switch check (0x0047F7DC); any other
// spawn just clears the flag.
// FUNCTION: TITANIUM 0x0048BF14
void State_48BF_guess::UpdateIfActive_guess()
{
    if (data_1a8_guess->flag_f94_guess != 0) {
        if (this == EQ_GLOBAL(State_48BF_guess*, 0x00905CE4)) {
            TouchingSwitch_guess(this);
            return;
        }
        data_1a8_guess->flag_f94_guess = 0;
    }
}

// A corpse (type > 1) gets stand state 'x' (dead) and its death animation once.
// FUNCTION: TITANIUM 0x0048BF35
void State_48BF35_guess::UpdateIfReady_guess()
{
    if (type_0244_guess > 1 && pActorInfo_01a8_guess->value_068_guess == 0) {
        standState_0251_guess = 0x78;
        value_050_guess = 0.0f;
        pActorInfo_01a8_guess->value_068_guess = EQ_GLOBAL(Global_48BF35_guess*, 0x00905D24)->value_148_guess;
        unsigned int saved_guess = pActorInfo_01a8_guess->value_f4c_guess;
        pActorInfo_01a8_guess->value_f4c_guess = 0;
        GetObject_guess()->Slot_20_guess(0x10, 1, 1, 0.0f);
        pActorInfo_01a8_guess->value_f4c_guess = saved_guess;
    }
}

// Moves the actor model to the spawn's position (or its bone 0x22 position) and applies the heading.
// FUNCTION: TITANIUM 0x0048BFA2
void Player_48BA76_guess::Apply_48BFA2_guess(char flag_guess)
{
    Actor_489B0A_guess* actor_guess = GetActor_4898D6_guess();
    if (pActorInfo_01a8_guess->light_0004_guess != 0) {
        if (pActorInfo_01a8_guess->CheckMode_48F019_guess() != 0 && pActorInfo_01a8_guess->actorInstance_0000_guess != 0 &&
            pActorInfo_01a8_guess->actorInstance_0000_guess->HasValues_154_guess(0x22) != 0) {
            int values_guess[3];
            pActorInfo_01a8_guess->actorInstance_0000_guess->GetValues_0c0_guess(0x22, values_guess, 1);
            g_display_48A026_guess->UpdateActor_guess(pActorInfo_01a8_guess->light_0004_guess, values_guess);
        } else {
            g_display_48A026_guess->UpdatePosition_guess(pActorInfo_01a8_guess->light_0004_guess, &position_030_guess);
        }
    }

    float heading_guess[3];
    actor_guess->GetHeading_05c_guess(heading_guess);
    if (race_260_guess == 0x6c) {
        heading_guess[0] = g_display_48A026_guess->FixHeading_guess(heading_guess[0] + 8.0f);
    } else {
        heading_guess[0] = heading_004c_guess;
        if (pActorInfo_01a8_guess->mount_015c_guess != 0 &&
            pActorInfo_01a8_guess->mount_015c_guess->pActorInfo_01a8_guess->actorInstance_0000_guess != 0) {
            heading_guess[1] = pActorInfo_01a8_guess->mount_015c_guess->pActorInfo_01a8_guess->actorInstance_0000_guess->GetValue_064_guess();
        }
    }
    actor_guess->SetHeading_04c_guess(heading_guess);

    if (g_display_48A026_guess->value_005_guess == 1 && type_0244_guess <= 1) {
        char changed_guess = value_058_guess != 0.0f || heading_guess[0] != heading_004c_guess;
        GetAnimation_guess()->Slot_0c_guess(changed_guess);
        if (pActorInfo_01a8_guess != 0 && pActorInfo_01a8_guess->rider_0160_guess != 0)
            pActorInfo_01a8_guess->rider_0160_guess->GetAnimation_guess()->Slot_0c_guess(0);
    }
}

// For the local player only: returns every pending position-history entry to the free list
// (0x004B6EF8).
// FUNCTION: TITANIUM 0x0048C11B
void State_48C_guess::UpdateIfCurrent_guess()
{
    if (this == EQ_GLOBAL(State_48C_guess*, 0x00905CE4))
        GetState_guess()->Update_guess();
}

// For the local player only: records a position-history spot (0x004B70DB) with `first` (position) and
// `second` (type).
// FUNCTION: TITANIUM 0x0048C130
void State_48C_guess::UpdateIfCurrentWithArgs_guess(int first_guess, int second_guess)
{
    if (this == EQ_GLOBAL(State_48C_guess*, 0x00905CE4))
        GetState_guess()->UpdateWithArgs_guess(first_guess, second_guess);
}

// For the local player only: records the current position in the position history, as type 3 when
// `lift` is set, else as type 1 with the floor offset (0x00489A32) added to z.
// FUNCTION: TITANIUM 0x0048C14F
void State_48C_guess::UpdateIfCurrentWithPosition_guess(char lift_guess)
{
    if (this == EQ_GLOBAL(State_48C_guess*, 0x00905CE4)) {
        GetState_guess();
        State_48995D_guess* state_guess = (State_48995D_guess*)this;
        Vector_48A324_guess position_guess;
        position_guess.x_guess = state_guess->position_0030_guess.x_guess;
        position_guess.y_guess = state_guess->position_0030_guess.y_guess;
        position_guess.z_guess = state_guess->position_0030_guess.z_guess;
        int mode_guess;
        if (lift_guess != 0) {
            mode_guess = 3;
        } else {
            position_guess.z_guess += state_guess->Calculate_489A32_guess();
            mode_guess = 1;
        }
        UpdateIfCurrentWithArgs_guess((int)&position_guess, mode_guess);
    }
}

// For the local player: sends message 0x6A1B (no EQEmu Titanium name, probably a movement history) at most
// once a second unless `value` forces it.
// FUNCTION: TITANIUM 0x0048C1A3
// @early-stop: budget, diff ndiff=10
void State_48C_guess::SendMovementHistory_guess(int value)
{
    unsigned int start;
    int buffer[42500];
    if (this == EQ_GLOBAL(State_48C_guess*, 0x00905CE4)) {
        State_48C_guess* state = GetState_guess();
        if (!state->IsBlocked_guess()) {
            start = state->GetTime_guess();
            if (FUN_0046d655_guess() - start >= 1000 || (char)value != 0) {
                int length = state->BuildMessage_guess(buffer, value);
                if (length != 0)
                    EQSendMessage(&EQ_GLOBAL(unsigned char, 0x00905CA0), 0x6a1b, buffer, length, 1);
            }
        }
    }
}

