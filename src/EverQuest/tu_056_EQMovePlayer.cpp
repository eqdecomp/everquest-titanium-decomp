// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 56: a hint from compare/tumap.py.
// Player movement helpers next to EQPlayer: getting onto a ladder (CDisplay::GetOnActor in the Mac map) and
// two small EQPlayer methods. CDisplayView_guess is CDisplay (0x439C41 TrueDistance, 0x436628
// HeadingDiff), CEverQuestView_guess CEverQuest; One_guess/Two_guess are an effect pushed to 0x99E370.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct Position_guess {
    int x_guess;
    int y_guess;
    int z_guess;
};

struct Dispatch_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess(Position_guess* position_guess);
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual float Slot10_guess();
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
    virtual int* Slot21_guess();
};

// EXTERNAL: TITANIUM 0x0064858C ??_7One_guess@@6B@
struct One_guess {
    virtual void Slot00_guess();
    int padding_04_guess[0x17];
    short padding_60_guess;
    unsigned char state_62_guess;
    char padding_63_guess;
    int padding_64_guess[3];
    float value_70_guess;
    int value_74_guess;
    int value_78_guess;
    int padding_7c_guess[3];
    Dispatch_guess* source_guess;

    // EXTERNAL: TITANIUM 0x0048A34F One_guess::Initialize_guess
    void Initialize_guess(int* current_guess, float value_guess, int* previous_guess);

    One_guess(Dispatch_guess* source_guess, float amount_guess);
};

// EXTERNAL: TITANIUM 0x006486C0 ??_7Two_guess@@6B@
struct Two_guess : One_guess {
    Two_guess(Dispatch_guess* source_guess, float amount_guess);
    ~Two_guess() {}
};

struct SourceValue_guess {
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
    virtual float Value_guess();
};

struct Manager_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Add_guess(Two_guess* effect_guess);
};

struct EffectOwner_guess {
    void Apply_guess();
};

// EXTERNAL: TITANIUM 0x004898D6 GetSource_guess
Dispatch_guess* __cdecl GetSource_guess();

struct Handle_guess {
    char padding_00_guess[4];
    Dispatch_guess* dispatch_guess;
};

struct Actor_guess {
    char padding_00_guess[0x30];
    Position_guess position_guess;
    char padding_3c_guess[0x16c];
    Handle_guess* handle_guess;
    char padding_1ac_guess[0xb4];
    int state_guess;

    char Check_guess();
};

// Collision sphere for `source` (0x0048A34F): its position (virtual slot 21) as both the current and
// the previous one, radius = its virtual slot 10 value plus `amount`; the source is kept.
// FUNCTION: TITANIUM 0x0048C220
// @early-stop: budget, diff ndiff=20
One_guess::One_guess(Dispatch_guess* source_guess, float amount_guess)
{
    int* previous_guess = source_guess->Slot21_guess();
    Initialize_guess(source_guess->Slot21_guess(),
                     source_guess->Slot10_guess() + amount_guess,
                     previous_guess);
    this->source_guess = source_guess;
}

// The same collision sphere (0x0048C220), with the byte at +0x62 cleared.
// FUNCTION: TITANIUM 0x0048C261
Two_guess::Two_guess(Dispatch_guess* source_guess, float amount_guess)
    : One_guess(source_guess, amount_guess) {
    state_62_guess = 0;
}

struct LadderObjectView_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual unsigned int Type_guess();
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
    virtual float Range_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void ReadPosition_guess(float* position_guess);
    virtual void ReadTarget_guess(float* target_guess);
};

struct ActorServices_guess {
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
    virtual float Height_guess();
};

struct ActorInfo_guess {
    ActorServices_guess* service_guess;
    char pad_004_guess[0x44];
    float field_048_guess;
    char pad_04c_guess[0x104];
    unsigned char state_150_guess;
    char pad_151_guess[7];
    int field_158_guess;
    char pad_15c_guess[0xe38];
    int field_f94_guess;
};

struct Trig_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float angle_guess);
    virtual float Cos_guess(float angle_guess);
};

struct TargetPoint_guess {
    float x_guess;
    float y_guess;
    float z_guess;
};

struct PlayerFloat_guess {
    char pad_000_guess[0x238];
    float heightOffset_0238_guess;
};

struct EQPlayerOps_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x0048BB83 EQPlayerOps_guess::CanMove_guess
    char CanMove_guess(TargetPoint_guess* point_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x0048A945 EQPlayerOps_guess::UpdatePosition_guess
    void UpdatePosition_guess();
    // EXTERNAL: TITANIUM 0x0048A0FC EQPlayerOps_guess::GetFloorHeightAt_guess
    float GetFloorHeightAt_guess(float y_guess, float x_guess, float z_guess, int flags_guess);
};

struct CDisplayView_guess {
    // EXTERNAL: TITANIUM 0x00439C41 CDisplayView_guess::TrueDistance_guess
    float TrueDistance_guess(float x_guess, float y_guess, float z_guess,
                         float target_x_guess, float target_y_guess,
                         float target_z_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x00436628 CDisplayView_guess::HeadingDiff_guess
    float HeadingDiff_guess(float heading_guess, float current_guess, int flags_guess);
    // EXTERNAL: TITANIUM 0x004365DB CDisplayView_guess::FixHeading_guess
    float FixHeading_guess(float heading_guess);

    void GetOnActor_guess(LadderObjectView_guess* input_guess, EQPlayer* player_guess);
};

// Mac: CDisplay::GetOnActor (low). Puts the player on ladder object `input_guess` (type 6) from the top:
// already climbing (actor state 6) it only turns to face the ladder or away from it; otherwise, within 25
// units and above 70% of the ladder's height, places the player just behind it facing down (camera -75),
// moving toward it, and sets climb state 6. Headings run 0-512, so +256 turns around.
// FUNCTION: TITANIUM 0x0048C285
// @early-stop: unknown, structural ndiff=172
void CDisplayView_guess::GetOnActor_guess(LadderObjectView_guess* input_guess, EQPlayer* player_guess) {
    if (input_guess == 0 || player_guess == 0) {
        return;
    }
    unsigned int type_guess = input_guess->Type_guess();
    // The >= 0x11 test is redundant with != 6 (kept as compiled).
    if (type_guess >= 0x11 || type_guess != 6) {
        return;
    }

    float position_guess[3];
    float target_guess[3];
    input_guess->ReadPosition_guess(position_guess);
    input_guess->ReadTarget_guess(target_guess);

    if (((ActorInfo_guess*)player_guess->pActorInfo)->state_150_guess == 6) {
        if (HeadingDiff_guess(target_guess[0], player_guess->Heading, 0) < 256.0f) {
            player_guess->Heading = target_guess[0];
        } else {
            player_guess->Heading = FixHeading_guess(target_guess[0] + 256.0f);
        }
        return;
    }

    float radius_guess = ((ActorInfo_guess*)player_guess->pActorInfo)->service_guess->Height_guess();
    if (radius_guess < 2.0f) {
        radius_guess = 2.0f;
    }
    float distance_guess = radius_guess + 0.5f;
    float input_radius_guess = input_guess->Range_guess();
    float top_guess = position_guess[2] + input_radius_guess;
    if (TrueDistance_guess(player_guess->Y, player_guess->X, player_guess->Z,
                       position_guess[0], position_guess[1], top_guess, 0) > 25.0f) {
        // String 12008: "You are too far away from the ladder, get closer."
        pEverQuest->dsp_chat(pStringTable->getString(0x2ee8, 0));
        return;
    }
    // Below 70% of the ladder's height: nothing to climb down from.
    if (input_radius_guess * 0.7f + position_guess[2] >= player_guess->Z) {
        return;
    }

    float destination_z_guess = 1.5f;
    if (1.5f < ((PlayerFloat_guess*)player_guess)->heightOffset_0238_guess) {
        destination_z_guess = top_guess - ((PlayerFloat_guess*)player_guess)->heightOffset_0238_guess;
    }
    float normalized_guess = FixHeading_guess(target_guess[0] + 256.0f);
    TargetPoint_guess candidate_guess;
    candidate_guess.x_guess = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Cos_guess(normalized_guess) * distance_guess + position_guess[0];
    candidate_guess.y_guess = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Sin_guess(normalized_guess) * distance_guess + position_guess[1];
    candidate_guess.z_guess = destination_z_guess;

    EQPlayerOps_guess* player_ops_guess = (EQPlayerOps_guess*)player_guess;
    if (player_ops_guess->CanMove_guess(&candidate_guess, 0)) {
        player_guess->Y = candidate_guess.x_guess;
        player_guess->X = candidate_guess.y_guess;
        player_guess->Z = destination_z_guess;
        player_guess->Heading = target_guess[0];
    } else {
        normalized_guess = target_guess[0];
        candidate_guess.x_guess = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Cos_guess(normalized_guess) * distance_guess + position_guess[0];
        candidate_guess.y_guess = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Sin_guess(normalized_guess) * distance_guess + position_guess[1];
        candidate_guess.z_guess = destination_z_guess;
        if (!player_ops_guess->CanMove_guess(&candidate_guess, 0)) {
            return;
        }
        player_guess->Y = candidate_guess.x_guess;
        player_guess->X = candidate_guess.y_guess;
        player_guess->Z = destination_z_guess;
        player_guess->Heading = FixHeading_guess(target_guess[0] + 256.0f);
    }

    player_ops_guess->UpdatePosition_guess();
    distance_guess += 2.0f;
    player_guess->SpeedY = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Cos_guess(player_guess->Heading) * distance_guess;
    float sin_guess = EQ_GLOBAL(Trig_guess*, 0x0099E374)->Sin_guess(player_guess->Heading) * distance_guess;
    player_guess->CameraAngle = -75.0f;
    player_guess->SpeedX = sin_guess;
    player_guess->SpeedZ = 0.0f;
    player_guess->SpeedRun = 0.0f;
    ((ActorInfo_guess*)player_guess->pActorInfo)->state_150_guess = 6;
    ((ActorInfo_guess*)player_guess->pActorInfo)->field_158_guess = 0;
    ((ActorInfo_guess*)player_guess->pActorInfo)->field_f94_guess = 0;
    float floor_guess = player_ops_guess->GetFloorHeightAt_guess(player_guess->Y, player_guess->X, player_guess->Z + 1.0f, 1);
    if (floor_guess != -1.0e27f) {
        ((ActorInfo_guess*)player_guess->pActorInfo)->field_048_guess = floor_guess;
    }
}

// With +0x260 at least 0x8CD, pushes the player's position to its model (+0x1A8 handle, slot 6); 0 below.
// FUNCTION: TITANIUM 0x0048C5F1
char Actor_guess::Check_guess() {
    if (state_guess < 0x8cd) {
        return 0;
    }
    if (handle_guess != 0 && handle_guess->dispatch_guess != 0) {
        Position_guess copy_guess;
        copy_guess.x_guess = position_guess.x_guess;
        copy_guess.y_guess = position_guess.y_guess;
        copy_guess.z_guess = position_guess.z_guess;
        handle_guess->dispatch_guess->Slot06_guess(&copy_guess);
    }
    return 1;
}

// For the controlled player (0x905CF8) only: hands 0x99E370 an effect of minus half the value of
// source 0x4898D6.
// FUNCTION: TITANIUM 0x0048C63F
void EffectOwner_guess::Apply_guess() {
    if (this == EQ_GLOBAL(void*, 0x00905CF8)) {
        Dispatch_guess* source_guess = GetSource_guess();
        Two_guess effect_guess(source_guess,
                               reinterpret_cast<SourceValue_guess*>(source_guess)->Value_guess() * -0.5f);
        EQ_GLOBAL(Manager_guess*, 0x0099E370)->Add_guess(&effect_guess);
    }
}

