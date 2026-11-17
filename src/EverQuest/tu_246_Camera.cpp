// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 246: a hint from compare/tumap.py.
// Game cameras. ProjectileCamera_guess (misnamed) is the projectile camera, slot 8 of the camera array 0x9254FC
// (tu_047). Camera_guess holds the player cameras: position +0x04, heading/pitch/roll +0x10..+0x18,
// height +0x2C, pitch +0x30, distance +0x34, orbit angle +0x38; headings run 0-512. CEverQuestView_guess is
// pEverQuest, +0xB54 its GameState (MQ2: 1 character select, 5 in game).
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"

struct Vector_guess {
    int x_guess;
    int y_guess;
    int z_guess;
};

struct Source_guess {
    char pad_00[0x10];
    Vector_guess position_guess; // 0x10
    char pad_1c[0x10];
    int value_2c_guess; // 0x2c
};

struct CallbackManager_guess {
    // EXTERNAL: TITANIUM 0x004392DE CallbackManager_guess::SetCameraMode_guess
    void SetCameraMode_guess(int value);
};

#define g_callbackTarget_guess EQ_GLOBAL(int, 0x00905D24)

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();

struct ProjectileCamera_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess(int value);

    Vector_guess position_guess; // 0x04
    int value_10_guess;          // 0x10
    float value_14_guess;        // 0x14
    float value_18_guess;        // 0x18
    char pad_1c[0x2c];
    int value_48_guess;             // 0x48
    int followTarget_004c_guess;             // 0x4c
    unsigned int lastTime_50_guess; // 0x50

    void Follow_guess(int value);
    void Activate_guess(int unused_guess);
    void Update_guess(int unused_guess);
};

// EXTERNAL: TITANIUM 0x006120A0 FUN_006120a0_guess
void __cdecl FUN_006120a0_guess(double first, double second);

// EXTERNAL: TITANIUM 0x0060F6D4 FUN_0060f6d4_guess
double __cdecl FUN_0060f6d4_guess(double angle);

// EXTERNAL: TITANIUM 0x0060F784 FUN_0060f784_guess
double __cdecl FUN_0060f784_guess(double angle);

// EXTERNAL: TITANIUM 0x00612EE4 FUN_00612ee4_guess
double __cdecl FUN_00612ee4_guess(double angle);

struct MotionVector_guess {
    float x_guess;
    float y_guess;
    float z_guess;

    // EXTERNAL: TITANIUM 0x0046D66E MotionVector_guess::Length_guess
    float Length_guess();

    // EXTERNAL: TITANIUM 0x004C1414 MotionVector_guess::Normalize_guess
    void Normalize_guess();
};

struct DirectionStep_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    float scale_guess;
};

// Starts following projectile `value` (tu_047 passes the missile just fired), then calls vtable slot 2.
// FUNCTION: TITANIUM 0x005707B8
void ProjectileCamera_guess::Follow_guess(int value)
{
    followTarget_004c_guess = value;
    Slot02_guess(0);
}

// Enter hook, probably slot 14 of the camera switch 0x4392DE: saves the camera being left (0x850CCC)
// and the start time.
// FUNCTION: TITANIUM 0x005707A1
void ProjectileCamera_guess::Activate_guess(int unused_guess)
{
    value_48_guess = EQ_GLOBAL(int, 0x00850CCC);
    lastTime_50_guess = FUN_0046d655_guess();
}

// Copies the projectile's position and heading (+0x10, +0x2C) for up to 6 s, then switches back to the
// saved camera. FUN_0046d655_guess is the millisecond clock (tu_046 EqGetTime).
// FUNCTION: TITANIUM 0x005707C9
// @early-stop: budget, structural ndiff=32
void ProjectileCamera_guess::Update_guess(int unused_guess)
{
    if (followTarget_004c_guess != 0 && FUN_0046d655_guess() - lastTime_50_guess < 6000) {
        position_guess.x_guess = reinterpret_cast<Source_guess*>(followTarget_004c_guess)->position_guess.x_guess;
        position_guess.y_guess = reinterpret_cast<Source_guess*>(followTarget_004c_guess)->position_guess.y_guess;
        position_guess.z_guess = reinterpret_cast<Source_guess*>(followTarget_004c_guess)->position_guess.z_guess;
        value_14_guess = 0.0f;
        value_10_guess = reinterpret_cast<Source_guess*>(followTarget_004c_guess)->value_2c_guess;
        value_18_guess = 0.0f;
        return;
    }
    reinterpret_cast<CallbackManager_guess*>(g_callbackTarget_guess)->SetCameraMode_guess(value_48_guess);
}

// FUNCTION: TITANIUM 0x005709A7
void __cdecl Atan2f_guess(float first, float second)
{
    FUN_006120a0_guess((double)first, (double)second);
}

// Second float atan2 thunk; UpdateTrailing_guess calls it through a float-returning cast.
// FUNCTION: TITANIUM 0x005709C2
void __cdecl FUN_005709c2_guess(float first, float second)
{
    Atan2f_guess(first, second);
}
struct Feature_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess(int value) = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess(float* values) = 0;
    virtual void Slot19_guess(float* values) = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual float Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess(int value) = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot75_guess() = 0;
    virtual void Slot76_guess() = 0;
    virtual void Slot77_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot79_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot81_guess() = 0;
    virtual void Slot82_guess() = 0;
    virtual void Slot83_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual char IsAvailable_guess(int feature) = 0;
    virtual void Slot86_guess() = 0;
    virtual void Slot87_guess() = 0;
    virtual void Slot88_guess() = 0;
    virtual void Slot89_guess() = 0;
    virtual void Slot90_guess() = 0;
    virtual void Slot91_guess() = 0;
    virtual void Slot92_guess() = 0;
    virtual void Slot93_guess() = 0;
    virtual void Slot94_guess() = 0;
    virtual void Slot95_guess() = 0;
    virtual void Slot96_guess() = 0;
    virtual void Slot97_guess() = 0;
    virtual void Slot98_guess() = 0;
    virtual void Slot99_guess() = 0;
    virtual void Slot100_guess() = 0;
    virtual void Slot101_guess() = 0;
    virtual void Slot102_guess() = 0;
    virtual void Slot103_guess() = 0;
    virtual void Slot104_guess() = 0;
    virtual void Slot105_guess() = 0;
    virtual void Slot106_guess() = 0;
    virtual void Slot107_guess() = 0;
    virtual void Slot108_guess() = 0;
    virtual void Slot109_guess() = 0;
    virtual void Slot110_guess() = 0;
    virtual void Slot111_guess() = 0;
    virtual void Slot112_guess() = 0;
    virtual void Slot113_guess() = 0;
    virtual void Slot114_guess() = 0;
    virtual void Slot115_guess() = 0;
    virtual float Slot116_guess() = 0;
};

typedef Feature_guess ActorObject_guess;

struct FeatureHolder_guess {
    Feature_guess* feature_guess;
};

struct ActorState_guess {
    char pad_00_guess[0x30];
    float x_30_guess;
    float y_34_guess;
    float z_38_guess;
    char pad_3c_guess[0x10];
    float angle_4c_guess;
    char pad_50_guess[0x158];
    FeatureHolder_guess* feature_holder_1a8_guess;

    // EXTERNAL: TITANIUM 0x0047BF6C ActorState_guess::ReadFeature_guess
    char ReadFeature_guess(int feature, float* values);
};

struct ActorAngle_guess {
    char pad_00_guess[0x40];
    float scale_40_guess;
};

struct ActorOwner_guess {
    ActorObject_guess* object_00_guess;
    char pad_04_guess[0x128];
    ActorAngle_guess* angle_12c_guess;
    char pad_130_guess[4];
    int class_id_134_guess;
    char pad_138_guess[0x24];
    ActorState_guess* state_15c_guess;
};

struct Actor_guess {
    char pad_00_guess[0x30];
    float x_30_guess;
    float y_34_guess;
    float z_0038_guess;
    char pad_3c_guess[0x10];
    float heading_004c_guess;
    char pad_50_guess[0x0c];
    float pitch_005c_guess;
    char pad_60_guess[0x148];
    ActorOwner_guess* owner_1a8_guess;
    char pad_1ac_guess[0xa5];
    char type_251_guess;
    char pad_252_guess[0x0e];
    int mode_260_guess;

    // EXTERNAL: TITANIUM 0x00489BF5 Actor_guess::GetBase_guess
    float GetBase_guess();

    // EXTERNAL: TITANIUM 0x0047BF6C Actor_guess::ReadFeature_guess
    char ReadFeature_guess(int feature, float* values);
};

struct CalcMath_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual float Sin_guess(float angle) = 0;
    virtual float Cos_guess(float angle) = 0;
    virtual float Sqrt_guess(float value) = 0;
    virtual void Slot05_guess() = 0;
    virtual float GetAngle_guess(float difference, float distance, float* value) = 0;
};

struct TargetMath_guess {
    virtual float Sin_guess(float angle);
    virtual float Cos_guess(float angle);
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Sqrt_guess(float value);
};

struct ShapeManager_guess {
    // EXTERNAL: TITANIUM 0x004365DB ShapeManager_guess::FixHeading_guess
    float FixHeading_guess(float angle);

    // EXTERNAL: TITANIUM 0x0043A15C ShapeManager_guess::s3dCollideSphereWithWorld_guess
    void s3dCollideSphereWithWorld_guess(float x, float y, float height, float base, float result_x,
                     float result_y, float* out_x, float* out_y, float* out_z,
                     int count);
};

struct CEverQuestView_guess {
    char pad_00_guess[0xb54];
    int mode_b54_guess;
};

#define g_calcMath_guess EQ_GLOBAL(CalcMath_guess*, 0x0099E374)
#define g_targetMath_guess EQ_GLOBAL(TargetMath_guess*, 0x0099E374)
#define g_shapeManager_guess EQ_GLOBAL(ShapeManager_guess*, 0x00905D24)
#define g_modeState_guess EQ_GLOBAL(CEverQuestView_guess*, 0x00988DF0)

// EXTERNAL: TITANIUM 0x0046E42F get_bearing_guess
float __cdecl get_bearing_guess(float x1, float y1, float x2, float y2);

struct Camera_guess {
    char pad_00_guess[4];
    float x_04_guess;
    float y_08_guess;
    float z_0c_guess;
    float angle_10_guess;
    float angle_14_guess;
    float value_18_guess;
    float x_1c_guess;
    float y_20_guess;
    float z_24_guess;
    char pad_28_guess[4];
    float height_002c_guess;
    float pitch_0030_guess;
    float distance_0034_guess;
    float angle_38_guess;
    char pad_3c_guess[8];
    char flag_44_guess;
    char flag_45_guess;
    char pad_46_guess[2];
    Actor_guess* actor_48_guess;

    CEverQuestView_guess* UpdateFirstPerson_guess(Actor_guess* actor);
    void UpdateOrbit_guess(Actor_guess* actor);
    CEverQuestView_guess* UpdateChase_guess(Actor_guess* actor);
    void UpdateTrailing_guess(Actor_guess* actor);
    void ComputeCameraPosition_guess(Actor_guess* actor);
};

// First-person view: the eye at the head point (attachment 0) or at Z plus the model height (GetBase_guess).
// Actor-info kinds 1-11 (+0x134) and riders also move forward by the model's +0x40 scale along the heading;
// riders start at the mount's rider point (0x12), or 3.5 above. Race 49 and riders call actor vtable slot 6
// with 1. Outside character select the pitch drops 8.5.
// FUNCTION: TITANIUM 0x005703A0
// @early-stop: budget, structural ndiff=322
CEverQuestView_guess* Camera_guess::UpdateFirstPerson_guess(Actor_guess* actor)
{
    ActorOwner_guess* owner = actor->owner_1a8_guess;
    ActorObject_guess* object = owner->object_00_guess;
    int class_id = owner->class_id_134_guess;

    actor_48_guess = actor;
    if ((class_id < 1 || class_id > 11) && owner->state_15c_guess == 0) {
        if (class_id == 0x24 || class_id == 0x21) {
            float values[3];
            if (actor->ReadFeature_guess(0, values) == 0) {
                x_04_guess = actor->x_30_guess;
                y_08_guess = actor->y_34_guess;
                z_0c_guess = actor->z_0038_guess;
                z_0c_guess = actor->GetBase_guess() + z_0c_guess;
            } else {
                x_04_guess = values[0];
                y_08_guess = values[1];
                z_0c_guess = values[2];
            }
        } else {
            x_04_guess = actor->x_30_guess;
            y_08_guess = actor->y_34_guess;
            z_0c_guess = actor->z_0038_guess;
            if (actor->type_251_guess == 'o')
                z_0c_guess = actor->z_0038_guess;
            else
                z_0c_guess = actor->GetBase_guess() + actor->z_0038_guess;
        }
        object->Slot06_guess(1);
    } else {
        if (actor->pitch_005c_guess < -16.0f) {
            float position[3];
            float angle[3];
            position[0] = actor->x_30_guess;
            position[1] = actor->y_34_guess;
            position[2] = actor->z_0038_guess;
            angle[0] = actor->heading_004c_guess;
            angle[1] = actor->pitch_005c_guess + 16.0f;
            angle[2] = 0.0f;
            object->Slot18_guess(position);
            object->Slot19_guess(angle);
        }

        if (owner->state_15c_guess == 0) {
            float values[3];
            if (actor->ReadFeature_guess(0, values) != 0) {
                x_04_guess = values[0];
                y_08_guess = values[1];
                z_0c_guess = values[2];
            } else {
                x_04_guess = actor->x_30_guess;
                y_08_guess = actor->y_34_guess;
                z_0c_guess = actor->z_0038_guess;
                z_0c_guess = actor->GetBase_guess() + z_0c_guess;
            }
        } else {
            ActorState_guess* state = owner->state_15c_guess;
            x_04_guess = state->x_30_guess;
            y_08_guess = state->y_34_guess;
            z_0c_guess = state->z_38_guess;
            float values[3];
            Feature_guess* feature = state->feature_holder_1a8_guess->feature_guess;
            if (feature->IsAvailable_guess(0x12) != 0 &&
                state->ReadFeature_guess(0x12, values) != 0) {
                z_0c_guess = actor->GetBase_guess() + values[2];
            } else {
                z_0c_guess = actor->GetBase_guess() + actor->z_0038_guess + 3.5f;
            }
        }

        float scale = owner->angle_12c_guess->scale_40_guess;
        float angle = actor->heading_004c_guess;
        x_04_guess += g_calcMath_guess->Cos_guess(angle) * scale;
        y_08_guess += g_calcMath_guess->Sin_guess(angle) * scale;
        if (owner->state_15c_guess != 0) {
            x_04_guess += g_calcMath_guess->Cos_guess(angle);
            y_08_guess += g_calcMath_guess->Sin_guess(angle);
            object->Slot06_guess(1);
            object->Slot52_guess(1);

            ActorState_guess* state = owner->state_15c_guess;
            float extra = 0.0f;
            FeatureHolder_guess* holder = state->feature_holder_1a8_guess;
            if (holder != 0 && holder->feature_guess != 0) {
                Feature_guess* feature = holder->feature_guess;
                float local_angle = feature->Slot25_guess();
                extra = local_angle + feature->Slot116_guess();
            }
            float cos_angle = g_calcMath_guess->Cos_guess(state->angle_4c_guess);
            float sin_angle = g_calcMath_guess->Sin_guess(state->angle_4c_guess);
            extra += 128.0f;
            float forward = g_calcMath_guess->Cos_guess(extra);
            float base = actor->GetBase_guess();
            float forward_height = base * forward;
            float side = g_calcMath_guess->Sin_guess(extra);
            float side_height = actor->GetBase_guess() * side;
            x_04_guess += forward_height * cos_angle;
            y_08_guess += forward_height * sin_angle;
            z_0c_guess += side_height - actor->GetBase_guess();
        } else {
            object->Slot06_guess(0);
        }
    }

    if (actor->mode_260_guess == 0x31)
        object->Slot06_guess(1);

    g_shapeManager_guess->s3dCollideSphereWithWorld_guess(actor->x_30_guess, actor->y_34_guess,
                                      actor->z_0038_guess, x_04_guess, y_08_guess,
                                      z_0c_guess, &x_04_guess, &y_08_guess, &z_0c_guess, 3);
    angle_10_guess = actor->heading_004c_guess;
    angle_14_guess = actor->pitch_005c_guess;
    value_18_guess = 0.0f;
    CEverQuestView_guess* result = g_modeState_guess;
    if (result->mode_b54_guess != 1)
        angle_14_guess -= 8.5f;
    return result;
}

// These four place the camera with Place_guess, a trace from the player's eye (riders: the mount's rider
// point 0x12 or 3.5 above; crouching 'o': 1.5 above Z) to the wanted spot, so walls stop it. In game
// (GameState 5) distance is held to 2-200 and height to 0-30.
// Trailing camera: keeps the direction from the player to the old camera spot, turned by the orbit angle
// (then cleared) and pitched by +0x30, and puts the camera 4-20 units out along it. With the old spot on
// the player it drops in behind the heading.
// FUNCTION: TITANIUM 0x005709DB
// @early-stop: budget, structural ndiff=160
void Camera_guess::UpdateTrailing_guess(Actor_guess* actor)
{
    float values[3];
    ActorOwner_guess* owner = actor->owner_1a8_guess;
    float base_height = actor->GetBase_guess() + actor->z_0038_guess;
    float place_height = base_height;
    float target_height = base_height;
    if (actor->type_251_guess == 'o')
        place_height = actor->z_0038_guess + 1.5f;

    if (actor->owner_1a8_guess != 0 && actor->owner_1a8_guess->state_15c_guess != 0) {
        ActorState_guess* state = actor->owner_1a8_guess->state_15c_guess;
        Feature_guess* feature = state->feature_holder_1a8_guess->feature_guess;
        if (feature->IsAvailable_guess(0x12) != 0 &&
            state->ReadFeature_guess(0x12, values) != 0) {
            place_height = target_height = actor->GetBase_guess() + values[2];
        } else {
            place_height = target_height =
                actor->GetBase_guess() + actor->z_0038_guess + 3.5f;
        }
    }

    x_1c_guess = x_04_guess;
    y_20_guess = y_08_guess;
    z_24_guess = z_0c_guess;
    if (g_modeState_guess->mode_b54_guess == 5) {
        if (distance_0034_guess < 2.0f || distance_0034_guess > 200.0f) {
            if (distance_0034_guess < 2.0f)
                distance_0034_guess = 2.0f;
            else
                distance_0034_guess = 200.0f;
        }
        if (height_002c_guess < 0.0f || height_002c_guess > 30.0f) {
            if (height_002c_guess < 0.0f)
                height_002c_guess = 0.0f;
            else
                height_002c_guess = 30.0f;
        }
    }

    if (owner->class_id_134_guess == 0x24 || owner->class_id_134_guess == 0x21 ||
        actor->type_251_guess == 'n') {
        if (actor->ReadFeature_guess(0, values) != 0)
            target_height = actor->GetBase_guess() * 0.1f + values[2];
    }

    values[0] = actor->x_30_guess;
    values[1] = actor->y_34_guess;
    MotionVector_guess difference;
    difference.x_guess = x_1c_guess - values[0];
    difference.y_guess = y_20_guess - values[1];
    difference.z_guess = z_24_guess - target_height;
    if (fabs((double)difference.x_guess) < 0.01 &&
        fabs((double)difference.y_guess) < 0.01) {
        difference.x_guess = -g_targetMath_guess->Cos_guess(actor->heading_004c_guess);
        difference.y_guess = -g_targetMath_guess->Sin_guess(actor->heading_004c_guess);
        difference.z_guess = 0.0f;
    }

    float distance = difference.Length_guess();
    typedef float (__cdecl *DirectionAngle_guess)(float, float);
    DirectionAngle_guess direction_angle =
        (DirectionAngle_guess)FUN_005709c2_guess;
    float angle = direction_angle(difference.y_guess, difference.x_guess);
    float horizontal_distance = g_targetMath_guess->Sqrt_guess(
        difference.x_guess * difference.x_guess +
        difference.y_guess * difference.y_guess);
    angle = angle + angle_38_guess * 0.00390625f * 3.1415927;
    difference.x_guess = (float)FUN_0060f6d4_guess((double)angle) * horizontal_distance;
    difference.y_guess = (float)FUN_0060f784_guess((double)angle) * horizontal_distance;
    direction_angle(difference.z_guess, horizontal_distance);
    difference.z_guess = (float)FUN_00612ee4_guess(
        (double)(-(pitch_0030_guess * 0.00390625f) * 3.1415927)) * horizontal_distance;
    difference.Normalize_guess();
    angle_38_guess = 0.0f;

    DirectionStep_guess step;
    step.scale_guess = 4.0f;
    if (distance < 4.0f || (step.scale_guess = 20.0f, 20.0f < distance)) {
        step.x_guess = difference.x_guess * step.scale_guess;
    } else {
        step.x_guess = distance * difference.x_guess;
        step.scale_guess = distance;
    }
    step.z_guess = difference.z_guess * step.scale_guess;
    step.y_guess = difference.y_guess * step.scale_guess;
    g_shapeManager_guess->s3dCollideSphereWithWorld_guess(
        actor->x_30_guess, actor->y_34_guess, place_height,
        values[0] + step.x_guess, values[1] + step.y_guess,
        step.z_guess + target_height, &x_04_guess, &y_08_guess, &z_0c_guess, 3);
    angle_10_guess = get_bearing_guess(x_04_guess, y_08_guess,
                                        actor->x_30_guess, actor->y_34_guess);
    angle_14_guess = pitch_0030_guess;
}

// Orbit camera: +0x34 out at orbit angle +0x38 (normalized to 0-512), +0x2C above the eye. Faces the player
// (flag +0x45: takes the player's heading); flag +0x44 aims the pitch at the player, else uses +0x30.
// FUNCTION: TITANIUM 0x00570D81
// @early-stop: budget, structural ndiff=75
void Camera_guess::UpdateOrbit_guess(Actor_guess* actor)
{
    float height = actor->z_0038_guess;
    float base_height = actor->GetBase_guess() + height;
    float place_height = base_height;
    if (actor->type_251_guess == 'o')
        place_height = actor->z_0038_guess + 1.5f;

    if (actor->owner_1a8_guess != 0) {
        ActorState_guess* state = actor->owner_1a8_guess->state_15c_guess;
        if (state != 0) {
            float values[3];
            Feature_guess* feature = state->feature_holder_1a8_guess->feature_guess;
            if (feature->IsAvailable_guess(0x12) == 0 ||
                state->ReadFeature_guess(0x12, values) == 0) {
                float fallback_height = actor->z_0038_guess;
                place_height = base_height =
                    actor->GetBase_guess() + fallback_height + 3.5f;
            } else {
                place_height = base_height = actor->GetBase_guess() + values[2];
            }
        }
    }

    x_1c_guess = x_04_guess;
    y_20_guess = y_08_guess;
    z_24_guess = z_0c_guess;
    if (g_modeState_guess->mode_b54_guess == 5) {
        if (distance_0034_guess < 2.0f)
            distance_0034_guess = 2.0f;
        else if (distance_0034_guess > 200.0f)
            distance_0034_guess = 200.0f;
        if (height_002c_guess < 0.0f)
            height_002c_guess = 0.0f;
        else if (height_002c_guess > 30.0f)
            height_002c_guess = 30.0f;
    }

    angle_38_guess = g_shapeManager_guess->FixHeading_guess(angle_38_guess);
    float y_origin = actor->y_34_guess;
    float x = actor->x_30_guess +
              g_calcMath_guess->Cos_guess(angle_38_guess) * distance_0034_guess;
    float y = actor->y_34_guess +
              g_calcMath_guess->Sin_guess(angle_38_guess) * distance_0034_guess;
    g_shapeManager_guess->s3dCollideSphereWithWorld_guess(actor->x_30_guess, actor->y_34_guess, place_height,
                                      x, y, base_height + height_002c_guess,
                                      &x_04_guess, &y_08_guess, &z_0c_guess, 3);

    if (flag_45_guess == 0)
        angle_10_guess = get_bearing_guess(x_04_guess, y_08_guess,
                                             actor->x_30_guess, actor->y_34_guess);
    else
        angle_10_guess = actor->heading_004c_guess;

    if (flag_44_guess == 0) {
        angle_14_guess = pitch_0030_guess;
    } else {
        float dx = actor->x_30_guess - x_04_guess;
        float dy = actor->y_34_guess - y_08_guess;
        float distance = g_calcMath_guess->Sqrt_guess(dx * dx + dy * dy);
        angle_14_guess = g_calcMath_guess->GetAngle_guess(base_height - z_0c_guess,
                                                           distance, &y_origin);
    }
    value_18_guess = 0.0f;
}

// Chase camera: +0x34 behind the player's heading at pitch +0x30 (distance x cos across, base height -
// distance x sin), collided with the world. In mode 5 the distance is capped at 200 (no 2.0 floor) and
// height +0x2C clamped to 0..30. Faces the player unless flag +0x45 is set (then the player's heading).
// Pitch drops 8.5 outside character select.
// FUNCTION: TITANIUM 0x00570FCA
// @early-stop: budget, structural ndiff=179
CEverQuestView_guess* Camera_guess::UpdateChase_guess(Actor_guess* actor)
{
    float base_height = actor->GetBase_guess() + actor->z_0038_guess;
    float place_height = base_height;
    if (actor->type_251_guess == 'o')
        place_height = actor->z_0038_guess + 1.5f;

    if (actor->owner_1a8_guess != 0) {
        ActorState_guess* state = actor->owner_1a8_guess->state_15c_guess;
        if (state != 0) {
            Feature_guess* feature = state->feature_holder_1a8_guess->feature_guess;
            float values[3];
            if (feature->IsAvailable_guess(0x12) == 0 ||
                state->ReadFeature_guess(0x12, values) == 0) {
                base_height = place_height = actor->GetBase_guess() +
                    actor->z_0038_guess + 3.5f;
            } else {
                base_height = place_height = actor->GetBase_guess() + values[2];
            }
        }
    }

    x_1c_guess = x_04_guess;
    y_20_guess = y_08_guess;
    z_24_guess = z_0c_guess;
    if (g_modeState_guess->mode_b54_guess == 5) {
        if (distance_0034_guess > 200.0f)
            distance_0034_guess = 200.0f;
        if (height_002c_guess < 0.0f || height_002c_guess > 30.0f)
            height_002c_guess = height_002c_guess < 0.0f ? 0.0f : 30.0f;
    }

    angle_38_guess = g_shapeManager_guess->FixHeading_guess(angle_38_guess);
    float distance = g_targetMath_guess->Cos_guess(pitch_0030_guess) * distance_0034_guess;
    float x = actor->x_30_guess - g_targetMath_guess->Cos_guess(actor->heading_004c_guess) * distance;
    float y = actor->y_34_guess - g_targetMath_guess->Sin_guess(actor->heading_004c_guess) * distance;

    int class_id = actor->owner_1a8_guess->class_id_134_guess;
    if (class_id == 0x24 || class_id == 0x21 || actor->type_251_guess == 'n') {
        float values[3];
        if (actor->ReadFeature_guess(0, values) != 0)
            base_height = actor->GetBase_guess() * 0.1f + values[2];
    }

    float z_offset = g_targetMath_guess->Sin_guess(pitch_0030_guess) * distance_0034_guess;
    g_shapeManager_guess->s3dCollideSphereWithWorld_guess(actor->x_30_guess, actor->y_34_guess, place_height,
                                      x, y, base_height - z_offset,
                                      &x_04_guess, &y_08_guess, &z_0c_guess, 3);

    if (flag_45_guess == 0) {
        angle_10_guess = get_bearing_guess(x_04_guess, y_08_guess,
                                             actor->x_30_guess, actor->y_34_guess);
        if (fabs((double)(x_04_guess - actor->x_30_guess)) < 0.01 &&
            fabs((double)(y_08_guess - actor->y_34_guess)) < 0.01)
            angle_10_guess = actor->heading_004c_guess;
    } else {
        angle_10_guess = actor->heading_004c_guess;
    }
    angle_14_guess = pitch_0030_guess;
    value_18_guess = 0.0f;
    if (g_modeState_guess->mode_b54_guess != 1)
        angle_14_guess -= 8.5f;
    return g_modeState_guess;
}

// Orbit camera locked to the player's heading: the Update_guess spot (angle +0x38, distance +0x34, height
// +0x2C) without facing back; pitch is +0x30. Like the chase camera it caps only at 200.
// FUNCTION: TITANIUM 0x0057081F
// @early-stop: unknown, structural ndiff=45
void Camera_guess::ComputeCameraPosition_guess(Actor_guess* actor)
{
    Actor_guess* actor_at_entry = actor;
    if (g_modeState_guess->mode_b54_guess == 5) {
        if (distance_0034_guess > 200.0f)
            distance_0034_guess = 200.0f;
        float limit = 0.0f;
        if (limit > height_002c_guess ||
            (limit = 30.0f, limit < height_002c_guess))
            height_002c_guess = limit;
    }

    float height = actor_at_entry->z_0038_guess;
    float base_height = actor_at_entry->GetBase_guess() + height;
    float place_height = base_height;
    if (actor_at_entry->type_251_guess == 'o')
        place_height = actor_at_entry->z_0038_guess + 1.5f;

    if (actor_at_entry->owner_1a8_guess != 0) {
        ActorState_guess* state = actor_at_entry->owner_1a8_guess->state_15c_guess;
        if (state != 0) {
            float values[3];
            Feature_guess* feature = state->feature_holder_1a8_guess->feature_guess;
            if (feature->IsAvailable_guess(0x12) == 0 ||
                state->ReadFeature_guess(0x12, values) == 0) {
                float fallback_height = actor_at_entry->z_0038_guess;
                base_height = actor_at_entry->GetBase_guess() + fallback_height + 3.5f;
            } else {
                base_height = actor_at_entry->GetBase_guess() + values[2];
            }
            place_height = base_height;
        }
    }

    float x = actor_at_entry->x_30_guess +
              g_calcMath_guess->Cos_guess(angle_38_guess) * distance_0034_guess;
    float y = actor_at_entry->y_34_guess +
              g_calcMath_guess->Sin_guess(angle_38_guess) * distance_0034_guess;
    g_shapeManager_guess->s3dCollideSphereWithWorld_guess(actor_at_entry->x_30_guess, actor_at_entry->y_34_guess,
                                      place_height, x, y,
                                      base_height + height_002c_guess,
                                      &x_04_guess, &y_08_guess, &z_0c_guess, 3);
    angle_10_guess = actor_at_entry->heading_004c_guess;
    angle_14_guess = pitch_0030_guess;
    value_18_guess = 0.0f;
}

