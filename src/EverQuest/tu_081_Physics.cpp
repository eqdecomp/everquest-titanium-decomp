// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 81: a hint from compare/tumap.py.
// Movement physics: process_physics advances one player, ground object or missile by the time since its
// last step, plus the two helpers that carry boat passengers along. Headings run 0-512 per turn, pitch
// -128..128. Time is in 50 ms units (ms * 0.02), at most 3 per step.
#include "titanium/eqaddr.h"
#include "titanium/crt.h"
#include "titanium/types.h"

struct Loc_004BFAE8_guess {
    float f00_guess;
    float f04_guess;
    float f08_guess;
    float f0c_guess;
    unsigned int u10_guess;
    float f14_guess;
    float f18_guess;
    unsigned int u1c_guess;
};

struct Actor_004BFE0F_guess {
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
    virtual float GetPitch_guess();     // 0x64
};

struct Actor_004BFC71_guess {
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
    virtual void SetPosition_guess(float* position);  // 0x48
    virtual void SetHeading_guess(float* heading);    // 0x4c
};

struct ActorInfo_004BF9B2_guess {
    Actor_004BFE0F_guess* pActor;       // 0x000
    unsigned char pad_004[0x48 - 0x4];
    float FloorZ_guess;                 // 0x048
    unsigned char pad_04c[0x50 - 0x4c];
    unsigned int LastTime_guess;        // 0x050
    unsigned char pad_054[0x84 - 0x54];
    int BobPhase_guess;                 // 0x084
    int SwayPhase_guess;                // 0x088
    int BobStep_guess;                  // 0x08c
    int SwayStep_guess;                 // 0x090
    float SwayAmp_guess;                // 0x094
    float BobAmp_guess;                 // 0x098
    unsigned char f9c_guess;            // 0x09c
    unsigned char pad_09d[0xad - 0x9d];
    unsigned char WaterType_guess;      // 0x0ad
    unsigned char pad_0ae[0xb4 - 0xae];
    float DampXY_guess;                 // 0x0b4
    float AccScale_guess;               // 0x0b8
    unsigned char pad_0bc[0x134 - 0xbc];
    int f134_guess;                     // 0x134
    unsigned char pad_138[0x150 - 0x138];
    unsigned char f150_guess;           // 0x150
    unsigned char pad_151[0x158 - 0x151];
    void* pOwner;                       // 0x158
    EQPlayer* pMount_guess;             // 0x15c
    int f160_guess;                     // 0x160
    unsigned char pad_164[0xecc - 0x164];
    unsigned int ecc_guess;             // 0xecc
    int ed0_guess;                      // 0xed0
    int ed4_guess;                      // 0xed4
};

struct Motion_004BFE0F_guess {
    float Y;                            // 0x00
    float X;                            // 0x04
    float Z;                            // 0x08
    float SpeedY;                       // 0x0c
    float SpeedX;                       // 0x10
    float SpeedZ;                       // 0x14
    float SpeedRun;                     // 0x18
    float Heading;                      // 0x1c
    float Pitch_guess;                  // 0x20
    float PitchSpeed_guess;             // 0x24
    float HeadingSpeed_guess;           // 0x28
    float f2c_guess;                    // 0x2c
    float f30_guess;                    // 0x30
    float f34_guess;                    // 0x34
};

struct Obj2_004BFE0F_guess {
    unsigned char pad_000[0x10];
    Motion_004BFE0F_guess motion;       // 0x10
    ActorInfo_004BF9B2_guess* pActorInfo;   // 0x48
    unsigned char pad_04c[0x62 - 0x4c];
    unsigned char f62_guess;            // 0x62
};

struct Obj3_004BFE0F_guess {
    Motion_004BFE0F_guess motion;       // 0x00
    unsigned char pad_038[0x7c - 0x38];
    unsigned int LastTime_guess;        // 0x7c
    unsigned char pad_080[0x88 - 0x80];
    int f88_guess;                      // 0x88
};

struct PlayerObj_004BFE0F_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual bool Slot09_guess();        // 0x24
};

struct Player_004BFE0F_guess : EQPlayer {
    // EXTERNAL: TITANIUM 0x0047BFD0 Player_004BFE0F_guess::IsHorseRace_guess
    bool IsHorseRace_guess();
    // EXTERNAL: TITANIUM 0x0047C08E Player_004BFE0F_guess::GetAnimation_guess
    PlayerObj_004BFE0F_guess* GetAnimation_guess();
    // EXTERNAL: TITANIUM 0x0047C2CD Player_004BFE0F_guess::GetWalkSpeed_guess
    float GetWalkSpeed_guess();
    // EXTERNAL: TITANIUM 0x0048A2F4 Player_004BFE0F_guess::FUN_0048a2f4_guess
    bool FUN_0048a2f4_guess();
    // EXTERNAL: TITANIUM 0x0048A344 Player_004BFE0F_guess::FUN_0048a344_guess
    bool FUN_0048a344_guess();
    // EXTERNAL: TITANIUM 0x0048B6C5 Player_004BFE0F_guess::CheckForUnderFloor_guess
    void CheckForUnderFloor_guess();
    // EXTERNAL: TITANIUM 0x0048BB4E Player_004BFE0F_guess::IsControlledPlayer_guess
    bool IsControlledPlayer_guess();
};

struct Display_004BFE0F_guess {
    unsigned char pad_000[0x148];
    unsigned int frameTime_f148_guess;            // 0x148
    // EXTERNAL: TITANIUM 0x0043D64B Display_004BFE0F_guess::FUN_0043d64b_guess
    float FUN_0043d64b_guess(float y, float x, float z);
    // EXTERNAL: TITANIUM 0x004365DB Display_004BFE0F_guess::FixHeading_guess
    float FixHeading_guess(float heading);
};

struct Obj985CC8_004BFE0F_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 Obj985CC8_004BFE0F_guess::GetSpell_guess
    int GetSpell_guess(int id);
};

struct Obj99E370_004BFE0F_guess {
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
    virtual bool Slot19_guess();        // 0x4c
};

// EXTERNAL: TITANIUM 0x0046D655 GetTime_guess
unsigned int __cdecl GetTime_guess();
// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
bool __cdecl IsValidSpellIndex_guess(int id);
// EXTERNAL: TITANIUM 0x0049B260 DoSpellEffect_guess
void __cdecl DoSpellEffect_guess(int a, int b, EQPlayer* c, EQPlayer* d, int e, int f, int g);

#define g_controlled_004BFE0F_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)
#define g_localPlayer_004BFE0F_guess EQ_GLOBAL(EQPlayer*, 0x00905CF8)
#define g_display_004BFE0F_guess EQ_GLOBAL(Display_004BFE0F_guess*, 0x00905D24)
#define g_985cc8_004BFE0F_guess EQ_GLOBAL(Obj985CC8_004BFE0F_guess*, 0x00985CC8)
#define g_99e370_004BFE0F_guess EQ_GLOBAL(Obj99E370_004BFE0F_guess*, 0x0099E370)
#define g_dt_004BFE0F_guess EQ_GLOBAL(float, 0x00924858)
#define g_autorun_004BFE0F_guess EQ_GLOBAL(unsigned char, 0x00923843)
#define g_9237b4_004BFE0F_guess EQ_GLOBAL(unsigned char, 0x009237B4)
#define g_923798_004BFE0F_guess EQ_GLOBAL(unsigned char, 0x00923798)
#define g_923d90_004BFE0F_guess EQ_GLOBAL(float, 0x00923D90)
#define g_gravity_004BFE0F_guess EQ_GLOBAL(float, 0x00923B84)
#define g_zone_004BFE0F_guess EQ_GLOBAL(int, 0x00924470)

struct EQPlayer_004BF9B2_guess {
    unsigned char pad_000[0x30];
    float Y;                            // 0x30
    float X;                            // 0x34
    float Z;                            // 0x38
    float SpeedY;                       // 0x3c
    float SpeedX;                       // 0x40
    float SpeedZ;                       // 0x44
    float SpeedRun;                     // 0x48
    float Heading;                      // 0x4c
    float field_50;                     // 0x50
    unsigned char pad_054[0x1a8 - 0x54];
    ActorInfo_004BF9B2_guess* pActorInfo;   // 0x1a8
    unsigned char pad_1ac[0x1b6 - 0x1ac];
    unsigned char IsABoat;              // 0x1b6
    unsigned char pad_1b7[0x214 - 0x1b7];
    EQPlayer_004BF9B2_guess* pNext;     // 0x214
};

struct Trig_004BF9B2_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Sin_guess(float a);
    virtual float Cos_guess(float a);
    virtual float Sqrt_guess(float a);
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Rotate_guess(float y, float x, float z, float* matrix);
};

#define g_trig_004BF9B2_guess EQ_GLOBAL(Trig_004BF9B2_guess*, 0x0099E374)
#define g_playerList_004BF9B2_guess EQ_GLOBAL(EQPlayer_004BF9B2_guess*, 0x00905CC4)
#define g_playerList_004BFC71_guess EQ_GLOBAL(EQPlayer*, 0x00905CC4)

// Before a boat moves: puts every spawn riding it (actor info owner == boat) into the boat's frame,
// position and velocity rotated by the boat's heading and pitch.
// FUNCTION: TITANIUM 0x004BF9B2
void __cdecl TransformPassengersToBoatSpace_guess(EQPlayer_004BF9B2_guess* pBoat)
{
    if (pBoat == 0 || pBoat->IsABoat == 0)
        return;

    float matrix[9];
    g_trig_004BF9B2_guess->Rotate_guess(pBoat->Heading, pBoat->field_50, 0.0f, matrix);

    for (EQPlayer_004BF9B2_guess* p = g_playerList_004BF9B2_guess; p != 0; p = p->pNext) {
        if (p->pActorInfo->pOwner == pBoat && p != pBoat) {
            float dy = p->Y - pBoat->Y;
            float dx = p->X - pBoat->X;
            float dz = p->Z - pBoat->Z;
            p->Y = matrix[0] * dy + matrix[1] * dx + matrix[2] * dz;
            p->X = matrix[3] * dy + matrix[4] * dx + matrix[5] * dz;
            p->Z = matrix[6] * dy + matrix[7] * dx + matrix[8] * dz;
            p->Heading -= pBoat->Heading;
            p->field_50 -= pBoat->field_50;
            dy = p->SpeedY;
            dx = p->SpeedX;
            dz = p->SpeedZ;
            p->SpeedY = matrix[0] * dy + matrix[1] * dx + matrix[2] * dz;
            p->SpeedX = matrix[3] * dy + matrix[4] * dx + matrix[5] * dz;
            p->SpeedZ = matrix[6] * dy + matrix[7] * dx + matrix[8] * dz;
        }
    }
}

// True when two position updates match: the packed heading and animation bits are equal, every float is
// within
// 0.001, and the three velocity deltas are near zero (under 0.01), so the spawn is standing still.
// FUNCTION: TITANIUM 0x004BFAE8
bool __cdecl IsPositionUpdateUnchanged_guess(Loc_004BFAE8_guess* a, Loc_004BFAE8_guess* b)
{
    if (((a->u1c_guess ^ b->u1c_guess) & 0xfff) != 0)
        return false;
    unsigned int au10 = a->u10_guess;
    unsigned int bu10 = b->u10_guess;
    if (((au10 ^ bu10) & 0xffc00) != 0)
        return false;
    if ((((unsigned short)au10 ^ (unsigned short)bu10) & 0x3ff) != 0)
        return false;
    if (fabs(a->f00_guess - b->f00_guess) > 0.001f)
        return false;
    if (fabs(a->f14_guess - b->f14_guess) > 0.001f)
        return false;
    if (fabs(a->f18_guess - b->f18_guess) > 0.001f)
        return false;
    if (fabs(a->f0c_guess - b->f0c_guess) > 0.001f)
        return false;
    if (fabs(a->f08_guess - b->f08_guess) > 0.001f)
        return false;
    if (fabs(a->f04_guess - b->f04_guess) > 0.001f)
        return false;
    if (fabs(a->f0c_guess) > 0.01f)
        return false;
    if (fabs(a->f08_guess) > 0.01f)
        return false;
    if (fabs(a->f04_guess) > 0.01f)
        return false;
    return true;
}

// After a boat moves: puts its riders back in world space (the transposed rotation, plus the boat's position)
// and pushes the new position and heading to their actors. The inverse of
// TransformPassengersToBoatSpace_guess.
// FUNCTION: TITANIUM 0x004BFC71
// @early-stop: unknown, diff ndiff=15
void __cdecl TransformPassengersToWorldSpace_guess(EQPlayer* pBoat)
{
    if (pBoat == 0 || pBoat->IsABoat == 0)
        return;

    float matrix[9];
    g_trig_004BF9B2_guess->Rotate_guess(pBoat->Heading, pBoat->field_50, 0.0f, matrix);

    for (EQPlayer* p = g_playerList_004BFC71_guess; p != 0; p = p->pNext) {
        if (((ActorInfo_004BF9B2_guess*)p->pActorInfo)->pOwner == pBoat && p != pBoat) {
            float x = (matrix[7] * p->Z + matrix[4] * p->X) + matrix[1] * p->Y;
            float z = (matrix[8] * p->Z + matrix[5] * p->X) + matrix[2] * p->Y;
            float y = (matrix[6] * p->Z + matrix[3] * p->X) + matrix[0] * p->Y;
            p->Y = y + pBoat->Y;
            p->X = x + pBoat->X;
            p->Z = z + pBoat->Z;

            p->Heading += pBoat->Heading;
            p->Heading = g_display_004BFE0F_guess->FixHeading_guess(p->Heading);
            p->field_50 += pBoat->field_50;
            p->field_50 = g_display_004BFE0F_guess->FixHeading_guess(p->field_50);

            float sx = (matrix[1] * p->SpeedY + matrix[4] * p->SpeedX) + matrix[7] * p->SpeedZ;
            float sz = (matrix[2] * p->SpeedY + matrix[5] * p->SpeedX) + matrix[8] * p->SpeedZ;
            float sy = (matrix[0] * p->SpeedY + matrix[3] * p->SpeedX) + matrix[6] * p->SpeedZ;
            p->SpeedY = sy;
            p->SpeedX = sx;
            p->SpeedZ = sz;

            float heading[3];
            float position[3];
            position[0] = p->Y;
            position[1] = p->X;
            position[2] = p->Z;
            heading[0] = p->Heading;
            heading[1] = p->field_50;
            heading[2] = 0.0f;
            ((Actor_004BFC71_guess*)((ActorInfo_004BF9B2_guess*)p->pActorInfo)->pActor)->SetPosition_guess(position);
            ((Actor_004BFC71_guess*)((ActorInfo_004BF9B2_guess*)p->pActorInfo)->pActor)->SetHeading_guess(heading);
        }
    }
}

// Three callers share it: a player (EQPlayer), a ground object (pObj2) or a free object such as a missile
// (pObj3);
// exactly one is non-null. A rider copies its mount and stops. Water type, levitation and race pick the
// acceleration scale and per-tick drag; then speeds decay, the step is applied, and bob/sway effects are
// added.
// Time: milliseconds become 50 ms units (x 0.02), at most 3 per step; the controlled player's step is also
// kept in a global (capped at 12).
// Sideways input (heading +-128, a quarter turn: strafing) moves at half run speed.
// Drag: free fall in air gets no steering and almost no drag; water type 5 in zone 222 has its own heavier
// vertical drag (222 is poearthb in the client's zone table).
// A levitating controlled player or boat sinks back toward 15 units above the floor, faster the
// higher it is; race 141 (model tag BOAT) settles to 0.4.
// Races 72 and 404 (SHIP, SHP) never move vertically.
// Spawn types 2 and 3 (corpses) never slide; FLT_EPSILON snaps tiny velocities to 0.
// FUNCTION: TITANIUM 0x004BFE0F
// @early-stop: budget, structural ndiff=314
void __cdecl process_physics(Player_004BFE0F_guess* pPlayer, Obj2_004BFE0F_guess* pObj2, Obj3_004BFE0F_guess* pObj3)
{
    float dampXY = 0.0f;
    float accScale = 0.0f;
    float dampZ = 0.0f;
    float accZScale = 0.0f;
    float dt;
    ActorInfo_004BF9B2_guess* ai;
    Motion_004BFE0F_guess* m;

    if (pPlayer) {
        ai = (ActorInfo_004BF9B2_guess*)pPlayer->pActorInfo;
        if (ai == 0)
            return;
        if (ai->LastTime_guess < 1) {
            ai->LastTime_guess = GetTime_guess();
            return;
        }
        if (pPlayer->Race >= 0x8cd)
            return;
        // Time step in 50 ms units, at most 3 per call (the controlled spawn's step is also kept, capped at
        // 12). A rider just copies its mount's position and heading.
        dt = (float)(GetTime_guess() - ai->LastTime_guess) * 0.02f;
        EQPlayer* pCtl = g_controlled_004BFE0F_guess;
        EQPlayer* pMount = ((ActorInfo_004BF9B2_guess*)pCtl->pActorInfo)->pMount_guess;
        if (pPlayer == (pMount ? pMount : pCtl))
            g_dt_004BFE0F_guess = dt;
        if (g_dt_004BFE0F_guess > 12.0f)
            g_dt_004BFE0F_guess = 12.0f;
        if (dt > 3.0f)
            dt = 3.0f;
        EQPlayer* pRide = ai->pMount_guess;
        if (pRide) {
            pPlayer->Y = pRide->Y;
            pPlayer->X = pRide->X;
            pPlayer->Z = pRide->Z;
            pPlayer->SpeedRun = 0.0f;
            pPlayer->Heading = pRide->Heading;
            pPlayer->SpeedY = 0.0f;
            pPlayer->SpeedX = 0.0f;
            pPlayer->SpeedZ = 0.0f;
            if (pPlayer == g_controlled_004BFE0F_guess && ai->pActor) {
                ActorInfo_004BF9B2_guess* rideAi = (ActorInfo_004BF9B2_guess*)pRide->pActorInfo;
                if (rideAi->pActor)
                    pPlayer->field_50 = rideAi->pActor->GetPitch_guess();
            }
            return;
        }
        if (ai->ecc_guess > 0 && ai->ecc_guess < g_display_004BFE0F_guess->frameTime_f148_guess) {
            if (IsValidSpellIndex_guess(ai->ed4_guess))
                DoSpellEffect_guess(0, g_985cc8_004BFE0F_guess->GetSpell_guess(ai->ed4_guess),
                                   pPlayer, pPlayer, 0, 0, ai->ed0_guess);
            ai->ed4_guess = -1;
            ai->ecc_guess = 0;
            ai->ed0_guess = 0;
        }
        ai->LastTime_guess = GetTime_guess();
        m = (Motion_004BFE0F_guess*)&pPlayer->Y;
        if (pPlayer->StandState == 0x78 || ai->f134_guess == 0x10) {
            m->SpeedRun = 0.0f;
            m->HeadingSpeed_guess = 0.0f;
        }
        if (pPlayer->Type != 0 && pPlayer->Race != 0x6c)
            m->f2c_guess = 0.0f;
        TransformPassengersToBoatSpace_guess((EQPlayer_004BF9B2_guess*)pPlayer);
    } else if (pObj2) {
        if (pObj2->pActorInfo->LastTime_guess < 1) {
            pObj2->pActorInfo->LastTime_guess = GetTime_guess();
            return;
        }
        dt = (float)(GetTime_guess() - pObj2->pActorInfo->LastTime_guess) * 0.02f;
        if (dt > 3.0f)
            dt = 3.0f;
        pObj2->pActorInfo->LastTime_guess = GetTime_guess();
        ai = pObj2->pActorInfo;
        m = &pObj2->motion;
    } else {
        if (pObj3 == 0)
            return;
        if (pObj3->LastTime_guess < 1) {
            pObj3->LastTime_guess = GetTime_guess();
            return;
        }
        dt = (float)(GetTime_guess() - pObj3->LastTime_guess) * 0.02f;
        if (dt < 0.001f)
            dt = 0.0f;
        if (dt > 3.0f)
            dt = 3.0f;
        pObj3->LastTime_guess = GetTime_guess();
        ai = 0;
        m = &pObj3->motion;
    }

    float accY = 0.0f;
    float accX = 0.0f;
    float accZ = 0.0f;
    // Strafing for the local player at half run speed: g_autorun_004BFE0F_guess is really the strafe side (1
    // turns the heading +128, a quarter circle, else -128).
    if (g_autorun_004BFE0F_guess && pPlayer == g_localPlayer_004BFE0F_guess
        && (m->HeadingSpeed_guess == 0.0f || m->SpeedRun == 0.0f)) {
        accX = (g_9237b4_004BFE0F_guess ? pPlayer->RunSpeed : pPlayer->GetWalkSpeed_guess()) * 0.5f;
        if (m->SpeedRun == 0.0f)
            accX = g_923d90_004BFE0F_guess * accX;
        float heading = g_display_004BFE0F_guess->FixHeading_guess(
            g_autorun_004BFE0F_guess == 1 ? m->Heading + 128.0f : m->Heading - 128.0f);
        accY = g_trig_004BF9B2_guess->Cos_guess(heading) * accX;
        accX = g_trig_004BF9B2_guess->Sin_guess(heading) * accX;
    }

    m->Heading += dt * m->HeadingSpeed_guess;
    int i = 0;
    while (m->Heading >= 512.0f) {
        m->Heading -= 512.0f;
        if (i > 5) {
            m->Heading = 0.0f;
            break;
        }
        i++;
    }
    i = 0;
    while (m->Heading < 0.0) {
        m->Heading += 512.0f;
        if (i > 5) {
            m->Heading = 0.0f;
            break;
        }
        i++;
    }

    m->Pitch_guess += dt * m->PitchSpeed_guess;
    if (m->Pitch_guess < -128.0f)
        m->Pitch_guess = -128.0f;
    if (m->Pitch_guess > 128.0f)
        m->Pitch_guess = 128.0f;
    if (pObj3 && pObj3->f88_guess == 2)
        m->f2c_guess = m->Pitch_guess;

    if (m->SpeedRun != 0.0f) {
        accY += m->SpeedRun * g_trig_004BF9B2_guess->Cos_guess(m->Heading);
        accX += m->SpeedRun * g_trig_004BF9B2_guess->Sin_guess(m->Heading);
        if (m->f2c_guess != 0.0f) {
            float z = m->SpeedRun * g_trig_004BF9B2_guess->Sin_guess(m->f2c_guess);
            if (pPlayer && pPlayer->Levitate == 2 && ai->WaterType_guess == 0 && z > 0.0f)
                z = 0.0f;
            accZ = z;
        }
    }

    // Acceleration and damping by medium. Falling spawns get gravity; on land, over half a unit above the
    // floor (0x0048A2F4) with +0x2E5 clear, there is no control;
    // water types 5-10 are slow and heavily damped (zone 222's type 5 even
    // more); levitating spawns use the flying values, or the water ones over water.
    if (ai && ai->f150_guess == 6) {
        accScale = 0.8f;
        accZScale = 0.8f;
        dampXY = 0.625f;
        dampZ = 0.625f;
    } else if (pObj3 == 0 && ai->f9c_guess == 1 && !pPlayer->FUN_0048a344_guess()
               && g_99e370_004BFE0F_guess->Slot19_guess()) {
        m->SpeedZ += -(g_gravity_004BFE0F_guess * dt);
        bool b = false;
        if (pPlayer->Type == 1) {
            b = true;
            if (pPlayer->Race == 0x6c && pPlayer == g_localPlayer_004BFE0F_guess)
                b = false;
        }
        unsigned char water = ai->WaterType_guess;
        if (water == 0 || b) {
            if (!pPlayer->FUN_0048a2f4_guess() && !pPlayer->FUN_0048a344_guess() && ai->f150_guess <= 2) {
                accScale = 0.0f;
                accZScale = 0.0f;
                dampXY = 0.99f;
                dampZ = 0.99f;
            } else {
                accScale = ai->AccScale_guess;
                accZScale = 0.0f;
                dampXY = ai->DampXY_guess;
                dampZ = 0.99f;
            }
        } else if (water == 5 && g_zone_004BFE0F_guess == 0xde) {
            accScale = 0.02f;
            accZScale = 0.1f;
            dampXY = 0.85f;
            dampZ = 0.1f;
        } else if (water == 5) {
            accScale = 0.025f;
            accZScale = 0.8f;
            dampXY = 0.95f;
            dampZ = 0.2f;
        } else if (water == 6 || water == 7 || water == 8) {
            accScale = 0.02f;
            accZScale = 0.8f;
            dampXY = 0.94f;
            dampZ = 0.15f;
        } else if (water == 9 || water == 10) {
            accScale = 0.025f;
            accZScale = 0.8f;
            dampXY = 0.95f;
            dampZ = 0.2f;
        }
    } else {
        accScale = 0.8f;
        accZScale = 0.8f;
        dampXY = 0.625f;
        dampZ = 0.625f;
        if (pPlayer && (pPlayer->Type != 1 || pPlayer->IsHorseRace_guess()) && pPlayer->Levitate == 2) {
            if (pPlayer->Race != 0x8d && ai->WaterType_guess != 0) {
                unsigned char water = ai->WaterType_guess;
                if (water == 5) {
                    accScale = 0.025f;
                    accZScale = 0.8f;
                    dampXY = 0.95f;
                    dampZ = 0.2f;
                } else if (water == 6 || water == 7 || water == 8) {
                    accScale = 0.02f;
                    accZScale = 0.8f;
                    dampXY = 0.94f;
                    dampZ = 0.15f;
                } else if (water == 9 || water == 10) {
                    accScale = 0.025f;
                    accZScale = 0.8f;
                    dampXY = 0.95f;
                    dampZ = 0.2f;
                }
            }
            if (g_99e370_004BFE0F_guess->Slot19_guess()
                && (pPlayer->IsControlledPlayer_guess() || pPlayer->IsABoat)) {
                float floorZ = m->Z - 70.0f;
                if (floorZ < ai->FloorZ_guess)
                    floorZ = ai->FloorZ_guess;
                float groundZ = g_display_004BFE0F_guess->FUN_0043d64b_guess(m->Y, m->X, floorZ);
                if (groundZ == -1e27f)
                    groundZ = ai->FloorZ_guess;
                float height = m->Z - groundZ;
                if (height > 15.0f) {
                    float sink = 0.0f;
                    if (m->SpeedRun != 0.0f)
                        sink = 0.05f;
                    if (height > 60.0f)
                        m->SpeedZ -= (sink + 0.3f) * dt;
                    else if (height > 30.0f)
                        m->SpeedZ -= (sink + 0.2f) * dt;
                    else
                        m->SpeedZ -= dt * 0.1f;
                } else if (pPlayer->Race == 0x8d && height > 0.4f) {
                    m->SpeedZ -= dt * 0.1f;
                }
            }
        }
    }

    if (accY != 0.0f)
        accY *= accScale;
    if (accX != 0.0f)
        accX *= accScale;
    if (accZ != 0.0f)
        accZ *= accZScale;

    if (pPlayer) {
        // Ships (races 72 and 404) never move vertically; moving NPCs damp twice as hard.
        if (pPlayer->Race == 0x48 || pPlayer->Race == 0x194) {
            accZ = 0.0f;
            m->SpeedZ = 0.0f;
        }
        if ((ai == 0 || ai->f160_guess == 0) && pPlayer->Type == 1
            && (m->SpeedY != 0.0f || m->SpeedX != 0.0f)) {
            if (!g_923798_004BFE0F_guess || !pPlayer->GetAnimation_guess()->Slot09_guess())
                dampXY *= 0.5f;
        }
    } else if (pObj2 && pObj2->f62_guess == 0) {
        dampXY = 0.85f;
        dampZ = 0.85f;
    }

    if (m->SpeedY != 0.0f)
        m->SpeedY = dampXY * m->SpeedY;
    if (m->SpeedX != 0.0f)
        m->SpeedX = dampXY * m->SpeedX;
    if (m->SpeedZ != 0.0f)
        m->SpeedZ = dampZ * m->SpeedZ;
    if (fabs(m->SpeedY) < 1.1920929e-07f)
        m->SpeedY = 0.0f;
    if (fabs(m->SpeedX) < 1.1920929e-07f)
        m->SpeedX = 0.0f;
    if (fabs(m->SpeedZ) < 1.1920929e-07f)
        m->SpeedZ = 0.0f;
    m->SpeedY = accY + m->SpeedY;
    accX += m->SpeedX;
    m->SpeedX = accX;
    m->SpeedZ = accZ + m->SpeedZ;

    if (pObj2) {
        // the original squares the stored X and multiplies the unrounded Y sum by the stored Y
        Motion_004BFE0F_guess* mv = pPlayer ? (Motion_004BFE0F_guess*)&pPlayer->Y : &pObj2->motion;
        float speed = g_trig_004BF9B2_guess->Sqrt_guess(mv->SpeedX * mv->SpeedX + m->SpeedY * mv->SpeedY);
        if (pObj2->f62_guess == 0 && speed < 0.05f) {
            m->SpeedY = 0.0f;
            m->SpeedX = 0.0f;
            m->SpeedZ = 0.0f;
        }
    } else if (pPlayer) {
        if (pPlayer->Type == 0
            && ((ActorInfo_004BF9B2_guess*)pPlayer->pActorInfo)->WaterType_guess == 0
            && (((ActorInfo_004BF9B2_guess*)pPlayer->pActorInfo)->f134_guess == 0x19
                || ((ActorInfo_004BF9B2_guess*)pPlayer->pActorInfo)->f134_guess == 0x25)
            && m->SpeedZ > 0.0f && m->SpeedZ < 1.0f)
            m->SpeedZ = 0.0f;
        if (pPlayer == g_localPlayer_004BFE0F_guess && m->SpeedRun == 0.0f
            && ((ActorInfo_004BF9B2_guess*)pPlayer->pActorInfo)->WaterType_guess == 0) {
            if (m->SpeedY < 0.01f && m->SpeedY > -0.01f)
                m->SpeedY = 0.0f;
            if (m->SpeedX < 0.01f && m->SpeedX > -0.01f)
                m->SpeedX = 0.0f;
        }
        if (pPlayer->Type == 2 || pPlayer->Type == 3) {
            m->SpeedY = 0.0f;
            m->SpeedX = 0.0f;
        }
    }

    m->Y += dt * m->SpeedY;
    m->X += dt * m->SpeedX;
    m->Z += dt * m->SpeedZ;

    if (ai) {
        if (ai->BobPhase_guess > -1) {
            if (ai->BobPhase_guess > 0x200)
                ai->BobPhase_guess = 0;
            m->Z += g_trig_004BF9B2_guess->Sin_guess((float)ai->BobPhase_guess) * ai->BobAmp_guess * dt;
            ai->BobPhase_guess += ai->BobStep_guess;
        }
        if (ai->SwayPhase_guess > -1 && (m->SpeedY != 0.0f || m->SpeedX != 0.0f)) {
            if (ai->SwayPhase_guess > 0x200)
                ai->SwayPhase_guess = 0;
            float sway = g_trig_004BF9B2_guess->Sin_guess((float)ai->SwayPhase_guess) * ai->SwayAmp_guess;
            float dir = g_display_004BFE0F_guess->FixHeading_guess(m->Heading + 128.0f);
            m->Y += g_trig_004BF9B2_guess->Cos_guess(dir) * sway;
            m->X += g_trig_004BF9B2_guess->Sin_guess(dir) * sway;
            ai->SwayPhase_guess += ai->SwayStep_guess;
        }
    }

    if (pPlayer) {
        pPlayer->CheckForUnderFloor_guess();
        TransformPassengersToWorldSpace_guess(pPlayer);
    }
}
