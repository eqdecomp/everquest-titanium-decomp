// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 49: a hint from compare/tumap.py.
// CDisplay::MoveMissile (Mac map, unique debug string): one step of a spell or arrow missile. EQMissile_guess is
// the missile, CDisplayView_guess CDisplay, SpellManagerView_guess the spell manager (0x985CC8) and
// EQ_Spell_guess EQ_Spell; CastRay is CastRay (MQ2 eqgame.h).
#include "titanium/eqaddr.h"
#include "titanium/types.h"

#include <stdio.h>

struct Vec3_49_guess {
    float x_guess;
    float y_guess;
    float z_guess;
    Vec3_49_guess() {}
    Vec3_49_guess(float x, float y, float z) : x_guess(x), y_guess(y), z_guess(z) {}
    Vec3_49_guess(const Vec3_49_guess &o) : x_guess(o.x_guess), y_guess(o.y_guess), z_guess(o.z_guess) {}
    Vec3_49_guess Scale_guess(float s) const;
    // EXTERNAL: TITANIUM 0x00477BBA Vec3_49_guess::IsZero_guess
    bool IsZero_guess();
};

// The vector scaled by `s`.
// FUNCTION: TITANIUM 0x00477C8F
Vec3_49_guess Vec3_49_guess::Scale_guess(float s) const
{
    Vec3_49_guess t(*this);
    t.x_guess *= s;
    t.y_guess *= s;
    t.z_guess *= s;
    return t;
}

struct MoveActor_guess {
    virtual void v00_guess();
    virtual void v04_guess();
    virtual void v08_guess();
    virtual void v0c_guess();
    virtual void v10_guess();
    virtual void v14_guess();
    virtual void v18_guess();
    virtual void v1c_guess();
    virtual void v20_guess();
    virtual void v24_guess();
    virtual void v28_guess();
    virtual void v2c_guess();
    virtual void v30_guess();
    virtual void v34_guess();
    virtual void v38_guess();
    virtual void v3c_guess();
    virtual void v40_guess();
    virtual void v44_guess();
    virtual void SetPosition_guess(Vec3_49_guess *pos);    // 0x48
    virtual void SetRotation_guess(Vec3_49_guess *rot);    // 0x4c
    virtual void v50_guess();
    virtual void v54_guess();
    virtual void GetPosition_guess(Vec3_49_guess *pos);    // 0x58
    virtual void GetRotation_guess(float *rot);            // 0x5c
};

struct MoveInfo_guess {
    MoveActor_guess *actor_guess;        // 0x00
    int link_guess;                      // 0x04
    char unknown_08_guess[0x40];
    float floorHeight_guess;             // 0x48
    char unknown_4c_guess[0x14];
    unsigned int alertTime_guess;        // 0x60
    char unknown_64_guess[4];
    unsigned int expireTime_guess;       // 0x68
    char unknown_6c_guess[0x41];
    unsigned char stillCount_guess;      // 0xAD
    char unknown_ae_guess[0x82];
    unsigned int stillTime_guess;        // 0x130
    char unknown_134_guess[0xED0];
    char alerted_guess;                  // 0x1004
    char stuck_guess;                    // 0x1005
};

struct Motion_guess {
    Vec3_49_guess pos_guess;             // 0x00
    Vec3_49_guess vel_guess;             // 0x0C
    char unknown_18_guess[4];
    float heading_guess;                 // 0x1C
    float pitch_guess;                   // 0x20
    char unknown_24_guess[8];
    float viewPitch_guess;               // 0x2C
    char unknown_30_guess[8];
};

struct EQMissile_guess {
    char unknown_00_guess[0x10];
    Motion_guess motion_guess;           // 0x10
    MoveInfo_guess *info_guess;          // 0x48
    void *casterId_004c_guess;                // 0x4C
    char unknown_50_guess[0x0C];
    void *spellId_005c_guess;                  // 0x5C
    char unknown_60_guess[3];
    char type_guess;                     // 0x63

    // EXTERNAL: TITANIUM 0x00469DD7 EQMissile_guess::Touch_guess
    void Touch_guess();
    // EXTERNAL: TITANIUM 0x0047789D EQMissile_guess::MissileTeardown_guess
    void MissileTeardown_guess();
    // EXTERNAL: TITANIUM 0x0047658A EQMissile_guess::ReportSentinel_guess
    void ReportSentinel_guess(int recordId_guess, int unused_guess);
};

struct EQ_Spell_guess {
    char unknown_00_guess[8];
    float range_guess;                   // 0x08
    char unknown_0c_guess[0x19C];
    char flag_guess;                     // 0x1A8
    // EXTERNAL: TITANIUM 0x0044E77B EQ_Spell_guess::FindAffectSlot_guess
    char FindAffectSlot_guess(int category_guess);
};

struct SpellManagerView_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 SpellManagerView_guess::Find_guess
    EQ_Spell_guess *Find_guess(void *window_guess);
};

struct MoveCollider_guess {
    virtual void v00_guess();
    virtual void v04_guess();
    virtual void v08_guess();
    virtual void v0c_guess();
    virtual void v10_guess();
    virtual void v14_guess();
    virtual void v18_guess();
    virtual void v1c_guess();
    virtual int Sweep_guess(MoveActor_guess *actor, Vec3_49_guess *from, Vec3_49_guess *to,
        void *filter_guess, void *accept_guess, EQMissile_guess *mover, Vec3_49_guess *result,
        Vec3_49_guess *normal, float *dist, int flags_guess);   // 0x20
};

struct MoveWorld_guess {
    virtual void v00_guess();
    virtual void v04_guess();
    virtual void v08_guess();
    virtual void v0c_guess();
    virtual void v10_guess();
    virtual void v14_guess();
    virtual void v18_guess();
    virtual void v1c_guess();
    virtual void v20_guess();
    virtual void v24_guess();
    virtual void v28_guess();
    virtual void v2c_guess();
    virtual bool IsValid_guess(Vec3_49_guess *pos);          // 0x30
};

struct CDisplayView_guess {
    char unknown_00_guess[0x148];
    unsigned int time_guess;             // 0x148

    int MoveMissile_guess(EQMissile_guess *mover);
    // EXTERNAL: TITANIUM 0x00439F26 CDisplayView_guess::GetFloorHeight_guess
    float GetFloorHeight_guess(float x, float y, float z);
    // EXTERNAL: TITANIUM 0x00439C41 CDisplayView_guess::TrueDistance_guess
    float TrueDistance_guess(float x1, float y1, float z1, float x2, float y2, float z2, float scale_guess);
    // EXTERNAL: TITANIUM 0x0043D9C5 CDisplayView_guess::Attach_guess
    void Attach_guess(int link_guess, Motion_guess *motion);
};

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();
// EXTERNAL: TITANIUM 0x0044D0D0 IsWindowAvailable_guess
char __cdecl IsWindowAvailable_guess(void *window_guess);
// EXTERNAL: TITANIUM 0x00401B28 FindPlayer_guess
EQPlayer *__cdecl FindPlayer_guess(void *key_guess);
// EXTERNAL: TITANIUM 0x00476167 CastRay
int __cdecl CastRay(EQPlayer *player_guess, float y_guess, float x_guess, float z_guess);
// EXTERNAL: TITANIUM 0x0042CF6E SweepFilter_guess
int __cdecl SweepFilter_guess(int a_guess, void *b_guess);
// EXTERNAL: TITANIUM 0x00477BF8 CheckMissileHit_guess
int __cdecl CheckMissileHit_guess(int candidate_guess, EQMissile_guess *owner_guess);

#define g_moveDebug_guess EQ_GLOBAL(int, 0x00850980)
#define g_controlled_guess EQ_GLOBAL(EQMissile_guess *, 0x00905CFC)
#define g_spawnList_guess EQ_GLOBAL(EQPlayer *, 0x00905CC4)
#define g_localPlayer_guess EQ_GLOBAL(EQPlayer *, 0x00905CE4)
#define g_display_guess EQ_GLOBAL(CDisplayView_guess *, 0x00905D24)
#define g_validation_guess EQ_GLOBAL(SpellManagerView_guess *, 0x00985CC8)
#define g_collider_guess EQ_GLOBAL(MoveCollider_guess *, 0x0099E370)
#define g_world_guess EQ_GLOBAL(MoveWorld_guess *, 0x0099E368)
#define g_safeX_guess EQ_GLOBAL(float, 0x00923BCC)
#define g_safeY_guess EQ_GLOBAL(float, 0x00923BD0)
#define g_safeZ_guess EQ_GLOBAL(float, 0x00923BD4)

// Mac: CDisplay::MoveMissile. A flying missile sweeps from the actor's position to its wanted one and stops
// or slides on what it hits; a resting type-9 missile is a stationary spell that watches for players. Frees
// the missile and returns 0 when it expires, hits or its spell is gone; else moves the actor and returns 1.
// FUNCTION: TITANIUM 0x00477CC9
// @early-stop: tiebreak, structural ndiff=424
int CDisplayView_guess::MoveMissile_guess(EQMissile_guess *mover)
{
    char text[256];
    bool moved = true;
    time_guess = FUN_0046d655_guess();
    if (mover == 0) {
        return 1;
    }
    MoveInfo_guess *info = mover->info_guess;
    MoveActor_guess *actor = info->actor_guess;
    Motion_guess *motion = &mover->motion_guess;
    mover->Touch_guess();
    if (actor == 0) {
        return 1;
    }
    Vec3_49_guess actorPos;
    actor->GetPosition_guess(&actorPos);
    float rot[3];
    actor->GetRotation_guess(rot);
    Vec3_49_guess start = actorPos;
    Vec3_49_guess wanted = motion->pos_guess;
    Vec3_49_guess result = wanted;
    if (motion->vel_guess.x_guess >= 0.001f || motion->vel_guess.x_guess <= -0.001f ||
        motion->vel_guess.y_guess >= 0.001f || motion->vel_guess.y_guess <= -0.001f ||
        motion->vel_guess.z_guess >= 0.001f || motion->vel_guess.z_guess <= -0.001f) {
        float floor = GetFloorHeight_guess(actorPos.x_guess, actorPos.y_guess, actorPos.z_guess + 1.0f);
        // -1e27: no floor under the actor.
        if (floor != -1e27f) {
            info->floorHeight_guess = floor;
        }
    }
    if (g_moveDebug_guess != 0 && g_controlled_guess != 0 && g_controlled_guess == mover) {
        // Debug line for the controlled missile (0x850980 set); built, never shown. Kept.
        sprintf(text, "XYZ=%1.3f, %1.3f, %1.3f H=%3.1f VP=%3.1f FH=%1.3f VXYZ=%1.4f, %1.4f, %1.4f LVZ=0.0",
            actorPos.x_guess, actorPos.y_guess, actorPos.z_guess, rot[0], motion->viewPitch_guess,
            info->floorHeight_guess, motion->vel_guess.x_guess, motion->vel_guess.y_guess,
            motion->vel_guess.z_guess);
    }
    float dx = wanted.x_guess - actorPos.x_guess;
    float dy = wanted.y_guess - actorPos.y_guess;
    float dz = wanted.z_guess - actorPos.z_guess;
    if (dx < 0.001f && dx > -0.001f && dy < 0.001f && dy > -0.001f && dz < 0.001f && dz > -0.001f) {
        moved = false;
        if (info->stillCount_guess > 4 && info->stillTime_guess == 0) {
            info->stillTime_guess = time_guess;
        }
    }
    if (motion->vel_guess.x_guess >= 0.001f || motion->vel_guess.x_guess <= -0.001f ||
        motion->vel_guess.y_guess >= 0.001f || motion->vel_guess.y_guess <= -0.001f ||
        motion->vel_guess.z_guess >= 0.001f || motion->vel_guess.z_guess <= -0.001f) {
        if (time_guess > mover->info_guess->expireTime_guess) {
            mover->MissileTeardown_guess();
            operator delete(mover);
            return 0;
        }
        int hit;
        Vec3_49_guess normal;
        float dist;
        if (moved) {
            hit = g_collider_guess->Sweep_guess(actor, &start, &wanted, (void *)SweepFilter_guess,
                (void *)CheckMissileHit_guess, mover, &result, &normal, &dist, 0);
            if (mover->type_guess != 9) {
                Vec3_49_guess delta(result.x_guess - wanted.x_guess, result.y_guess - wanted.y_guess,
                    result.z_guess - wanted.z_guess);
                if (delta.IsZero_guess()) {
                    mover->MissileTeardown_guess();
                    operator delete(mover);
                    return 0;
                }
            }
        } else {
            if (mover->type_guess != 9) {
                mover->MissileTeardown_guess();
                operator delete(mover);
                return 0;
            }
            hit = 0;
            dist = 0.0f;
        }
        if (hit == 0) {
            // Missiles flagged +0x1005 stop where the sweep ended instead of sliding along the surface.
            if (mover->info_guess->stuck_guess == 1) {
                motion->pos_guess = result;
                mover->MissileTeardown_guess();
                operator delete(mover);
                return 0;
            }
            if (dist > 0.0f) {
                Vec3_49_guess offset = normal.Scale_guess(dist);
                Vec3_49_guess target(start.x_guess + offset.x_guess, start.y_guess + offset.y_guess,
                    start.z_guess + offset.z_guess);
                hit = g_collider_guess->Sweep_guess(actor, &start, &target, (void *)SweepFilter_guess,
                    (void *)CheckMissileHit_guess, mover, &result, &normal, &dist, 0);
            }
        }
        if (hit != 0) {
            motion->pos_guess = actorPos;
        } else {
            motion->pos_guess = result;
        }
    } else {
        if (mover->type_guess == 9) {
            if (!IsWindowAvailable_guess(mover->spellId_005c_guess)) {
                mover->MissileTeardown_guess();
                operator delete(mover);
                return 0;
            }
            EQ_Spell_guess *query = g_validation_guess->Find_guess(mover->spellId_005c_guess);
            if (query == 0) {
                mover->MissileTeardown_guess();
                operator delete(mover);
                return 0;
            }
            // Spell effect 76 (0x4C), probably Sentinel: every 2 s, report moving players within
            // 2.5x range and in sight.
            if (query->FindAffectSlot_guess(0x4C)) {
                mover->info_guess->alerted_guess = 1;
                EQPlayer *player = g_spawnList_guess;
                if (time_guess > mover->info_guess->alertTime_guess) {
                    mover->info_guess->alertTime_guess = time_guess + 2000;
                    for (; player != 0; player = player->pNext) {
                        // Only players that are moving.
                        if (player->SpeedRun != 0.0f) {
                            float d = g_display_guess->TrueDistance_guess(motion->pos_guess.x_guess,
                                motion->pos_guess.y_guess, motion->pos_guess.z_guess, player->Y,
                                player->X, player->Z, 1.0f);
                            if (d <= query->range_guess * 2.5f &&
                                CastRay(player, motion->pos_guess.x_guess,
                                    motion->pos_guess.y_guess, motion->pos_guess.z_guess) != 0) {
                                mover->ReportSentinel_guess(*(int *)player->pActorInfo, 1);
                            }
                        }
                    }
                }
            } else {
                EQPlayer *owner = FindPlayer_guess(mover->casterId_004c_guess);
                EQPlayer *local = g_localPlayer_guess;
                float d = g_display_guess->TrueDistance_guess(motion->pos_guess.x_guess,
                    motion->pos_guess.y_guess, motion->pos_guess.z_guess, local->Y, local->X,
                    local->Z, 1.0f);
                if (d <= query->range_guess && owner != 0 &&
                    (CastRay(owner, g_localPlayer_guess->Y, g_localPlayer_guess->X,
                         g_localPlayer_guess->Z) != 0 ||
                     // Other stationary spells: report the local player every 3 s when within range and in
                     // the caster's sight (or spell +0x1A8 set and an NPC caster, Type 1).
                     (query->flag_guess != 0 && owner->Type == 1))) {
                    if (time_guess > mover->info_guess->alertTime_guess) {
                        mover->info_guess->alertTime_guess = time_guess + 3000;
                        mover->ReportSentinel_guess(*(int *)g_localPlayer_guess->pActorInfo, 1);
                    }
                }
            }
        }
        if (time_guess > mover->info_guess->expireTime_guess) {
            mover->MissileTeardown_guess();
            operator delete(mover);
            return 0;
        }
    }
    result = motion->pos_guess;
    if (!g_world_guess->IsValid_guess(&result)) {
        motion->vel_guess.x_guess = 0.0f;
        motion->vel_guess.y_guess = 0.0f;
        motion->vel_guess.z_guess = 0.0f;
        if (!g_world_guess->IsValid_guess(&actorPos)) {
            // Both positions outside the world: fall back to the zone's safe point (0x923BCC).
            motion->pos_guess.x_guess = g_safeX_guess;
            motion->pos_guess.y_guess = g_safeY_guess;
            motion->pos_guess.z_guess = g_safeZ_guess;
        } else {
            motion->pos_guess = actorPos;
        }
    }
    if (mover->info_guess->link_guess != 0) {
        Attach_guess(mover->info_guess->link_guess, motion);
    }
    Vec3_49_guess newPos(motion->pos_guess.x_guess, motion->pos_guess.y_guess, motion->pos_guess.z_guess);
    Vec3_49_guess newRot(motion->heading_guess, motion->pitch_guess, 0.0f);
    float fall = actorPos.z_guess - newPos.z_guess;
    // No height change this step: falling speed is capped at -1.
    if (fall < 0.001f && fall > -0.001f && motion->vel_guess.z_guess < -1.0f) {
        motion->vel_guess.z_guess = -1.0f;
    }
    actor->SetPosition_guess(&newPos);
    actor->SetRotation_guess(&newRot);
    return 1;
}
