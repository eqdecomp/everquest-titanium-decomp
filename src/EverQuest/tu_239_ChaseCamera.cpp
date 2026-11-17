// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 239: a hint from compare/tumap.py.
// One camera function: the chase (third-person) camera behind the player, kept out of walls by
// s3dCollideSphereWithWorld (Mac map, 0x43A15C). ChaseCameraView_guess is that camera's state; CEverQuestView_guess is
// CEverQuest (0x988DF0) with the game state at +0xB54.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct ActorSlot_guess {
    unsigned char pad_000[0x15c];
    void* actor_guess;
};

struct ActorRoot_guess {
    unsigned char pad_000[0x1a8];
    void* actor_state_guess;
};

struct ActorState_guess {
    void* actor_query_guess;
};

struct AngleFunctions_guess {
    virtual void slot_000_guess();
    virtual void slot_004_guess();
    virtual float slot_008_guess(float angle_guess);
    virtual float slot_00c_guess(float angle_guess);
};

struct ActorQuery_guess {
    virtual void slot_000_guess();
    virtual void slot_004_guess();
    virtual void slot_008_guess();
    virtual void slot_00c_guess();
    virtual void slot_010_guess();
    virtual void slot_014_guess();
    virtual void slot_018_guess();
    virtual void slot_01c_guess();
    virtual void slot_020_guess();
    virtual void slot_024_guess();
    virtual void slot_028_guess();
    virtual void slot_02c_guess();
    virtual void slot_030_guess();
    virtual void slot_034_guess();
    virtual void slot_038_guess();
    virtual void slot_03c_guess();
    virtual void slot_040_guess();
    virtual void slot_044_guess();
    virtual void slot_048_guess();
    virtual void slot_04c_guess();
    virtual void slot_050_guess();
    virtual void slot_054_guess();
    virtual void slot_058_guess();
    virtual void slot_05c_guess();
    virtual void slot_060_guess();
    virtual void slot_064_guess();
    virtual void slot_068_guess();
    virtual void slot_06c_guess();
    virtual void slot_070_guess();
    virtual void slot_074_guess();
    virtual void slot_078_guess();
    virtual void slot_07c_guess();
    virtual void slot_080_guess();
    virtual void slot_084_guess();
    virtual void slot_088_guess();
    virtual void slot_08c_guess();
    virtual void slot_090_guess();
    virtual void slot_094_guess();
    virtual void slot_098_guess();
    virtual void slot_09c_guess();
    virtual void slot_0a0_guess();
    virtual void slot_0a4_guess();
    virtual void slot_0a8_guess();
    virtual void slot_0ac_guess();
    virtual void slot_0b0_guess();
    virtual void slot_0b4_guess();
    virtual void slot_0b8_guess();
    virtual void slot_0bc_guess();
    virtual void slot_0c0_guess();
    virtual void slot_0c4_guess();
    virtual void slot_0c8_guess();
    virtual void slot_0cc_guess();
    virtual void slot_0d0_guess();
    virtual void slot_0d4_guess();
    virtual void slot_0d8_guess();
    virtual void slot_0dc_guess();
    virtual void slot_0e0_guess();
    virtual void slot_0e4_guess();
    virtual void slot_0e8_guess();
    virtual void slot_0ec_guess();
    virtual void slot_0f0_guess();
    virtual void slot_0f4_guess();
    virtual void slot_0f8_guess();
    virtual void slot_0fc_guess();
    virtual void slot_100_guess();
    virtual void slot_104_guess();
    virtual void slot_108_guess();
    virtual void slot_10c_guess();
    virtual void slot_110_guess();
    virtual void slot_114_guess();
    virtual void slot_118_guess();
    virtual void slot_11c_guess();
    virtual void slot_120_guess();
    virtual void slot_124_guess();
    virtual void slot_128_guess();
    virtual void slot_12c_guess();
    virtual void slot_130_guess();
    virtual void slot_134_guess();
    virtual void slot_138_guess();
    virtual void slot_13c_guess();
    virtual void slot_140_guess();
    virtual void slot_144_guess();
    virtual void slot_148_guess();
    virtual void slot_14c_guess();
    virtual void slot_150_guess();
    virtual char HasFlag_guess(int flag_guess);
};

struct CEverQuestView_guess {
    unsigned char pad_000[0xb54];
    int gameState_0b54_guess;
};

struct ChaseCameraView_guess {
    unsigned char pad_000[4];
    float x_guess;
    float y_guess;
    float z_guess;
    float bearing_0010_guess;
    float final_height_guess;
    float zero_guess;
    float previous_x_guess;
    float previous_y_guess;
    float previous_z_guess;
    unsigned char pad_028[4];
    float height_002c_guess;
    float field_030_guess;
    float distance_0034_guess;
    float transformed_value_guess;
    unsigned char pad_03c[9];
    unsigned char flag_guess;

    CEverQuestView_guess* UpdateChaseCamera_guess(EQPlayer* player_guess);
};

// EXTERNAL: TITANIUM 0x00489BF5 FUN_00489bf5_guess
// EXTERNAL: TITANIUM 0x0047BF6C FUN_0047bf6c_guess
// EXTERNAL: TITANIUM 0x004365DB FixHeading_guess
// EXTERNAL: TITANIUM 0x0043A15C s3dCollideSphereWithWorld_guess
// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess

// Places the chase camera: aims from the player's head, backs off `limit` (+0x34) along the heading,
// raises it by +0x2C, then lets the collision move it (out +0x04-0x0C, old position +0x1C-0x24). +0x10 gets
// the bearing to the player (the heading when +0x45 is set); +0x14 copies +0x30, 8.5 lower outside character
// select, probably the pitch.
// FUNCTION: TITANIUM 0x0056FD78
// @early-stop: unknown, structural ndiff=81
CEverQuestView_guess* ChaseCameraView_guess::UpdateChaseCamera_guess(EQPlayer* player_guess)
{
    float next_height_guess;
    float parameter_height_guess;
    float vertical_guess;
    float horizontal_guess;
    float angle_guess;
    float actor_height_guess[3];

    // In game (state 5, as MQ2's GAMESTATE_INGAME) the distance is capped at 200 and the height at 0-30.
    if (EQ_GLOBAL(CEverQuestView_guess*, 0x00988df0)->gameState_0b54_guess == 5) {
        if (200.0f < distance_0034_guess) {
            distance_0034_guess = 200.0f;
        }
        if (0.0f > height_002c_guess) {
            height_002c_guess = 0.0f;
        } else if (30.0f < height_002c_guess) {
            height_002c_guess = 30.0f;
        }
    }

    parameter_height_guess = EQ_METHOD(0, float, 0x00489bf5, (EQPlayer*), player_guess)() + player_guess->Z;
    next_height_guess = parameter_height_guess;
    // 'o' (111) is ducking: aim 1.5 above the feet.
    if (player_guess->StandState == 'o') {
        next_height_guess = player_guess->Z + 1.5f;
    }
    if (height_002c_guess < 0.0f) {
        height_002c_guess = 0.0f;
    }

    if (player_guess->pActorInfo != 0) {
        void* actor_guess = ((ActorSlot_guess*)player_guess->pActorInfo)->actor_guess;
        if (actor_guess != 0) {
            ActorRoot_guess* root_guess = (ActorRoot_guess*)actor_guess;
            ActorState_guess* actor_state_guess = (ActorState_guess*)root_guess->actor_state_guess;
            ActorQuery_guess* query_guess = (ActorQuery_guess*)actor_state_guess->actor_query_guess;
            // Point 0x12 of the model, probably the head; without it the aim is 3.5 above the
            // player's height (0x489BF5).
            if (!query_guess->HasFlag_guess(0x12) ||
                !EQ_METHOD(2, char, 0x0047bf6c, (void*, int, float*), actor_guess)(0x12, actor_height_guess)) {
                parameter_height_guess = player_guess->Z +
                    EQ_METHOD(0, float, 0x00489bf5, (EQPlayer*), player_guess)() + 3.5f;
                next_height_guess = parameter_height_guess;
            } else {
                parameter_height_guess = EQ_METHOD(0, float, 0x00489bf5, (EQPlayer*), player_guess)() + actor_height_guess[2];
                next_height_guess = parameter_height_guess;
            }
        }
    }

    transformed_value_guess = EQ_METHOD(1, float, 0x004365db, (void*, float), EQ_GLOBAL(void*, 0x00905d24))(transformed_value_guess);
    previous_x_guess = x_guess;
    previous_y_guess = y_guess;
    previous_z_guess = z_guess;

    vertical_guess = player_guess->Y;
    horizontal_guess = player_guess->X;
    {
        angle_guess = EQ_GLOBAL(AngleFunctions_guess*, 0x0099e374)->slot_00c_guess(player_guess->Heading);
        vertical_guess = -(EQ_METHOD(0, float, 0x00489bf5, (EQPlayer*), player_guess)() + distance_0034_guess) *
            angle_guess + vertical_guess;
        angle_guess = EQ_GLOBAL(AngleFunctions_guess*, 0x0099e374)->slot_008_guess(player_guess->Heading);
        horizontal_guess = -(EQ_METHOD(0, float, 0x00489bf5, (EQPlayer*), player_guess)() + distance_0034_guess) *
            angle_guess + horizontal_guess;
    }

    EQ_METHOD(10, void, 0x0043a15c,
        (void*, float, float, float, float, float, float, float*, float*, float*, int),
        EQ_GLOBAL(void*, 0x00905d24))(player_guess->Y, player_guess->X, next_height_guess, vertical_guess,
        // Sphere sweep from the aim point to the wanted spot, radius 3 (probably); the result
        // is the camera position.
        horizontal_guess, parameter_height_guess + height_002c_guess, &x_guess, &y_guess, &z_guess, 3);

    if (flag_guess == 0) {
        // Bearing from the camera to the player (Mac: get_bearing).
        bearing_0010_guess = EQ_CDECL(float, 0x0046e42f, (float, float, float, float))(
            x_guess, y_guess, player_guess->Y, player_guess->X);
    } else {
        bearing_0010_guess = player_guess->Heading;
    }
    final_height_guess = field_030_guess;
    zero_guess = 0.0f;
    if (EQ_GLOBAL(CEverQuestView_guess*, 0x00988df0)->gameState_0b54_guess != 1) {
        final_height_guess = field_030_guess - 8.5f;
    }
    return EQ_GLOBAL(CEverQuestView_guess*, 0x00988df0);
}

