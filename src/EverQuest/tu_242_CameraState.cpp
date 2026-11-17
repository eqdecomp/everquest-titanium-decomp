// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 242: a hint from compare/tumap.py.
// Camera placement: the per-mode camera objects (0x9254FC, current mode 0x850CCC) and the eye position
// used when following a player. g_resolver_guess and g_display_guess are CDisplay, g_settings_guess
// CEverQuest, g_actorA_guess pinstLocalPlayer, Input_guess an EQPlayer view; Owner/Result: one camera?
#include "titanium/eqaddr.h"

struct EQPlayerView_guess;
struct State_guess;
struct Container_guess;
struct Settings_guess;
struct Vector3_guess {
    float x;
    float y;
    float z;
};

// Slots 0..28; the call in the target uses vtable offset 0x70 (slot 28).
struct EQPlayerView_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual char Slot06_guess(int value);
    virtual char Slot07_guess();
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
    virtual void Slot18_guess(Vector3_guess* value);
    virtual void Slot19_guess(Vector3_guess* value);
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess(float value);
    char pad15c[0x158];         // 0x4..0x15b
    State_guess* field15c;      // 0x15c
    char pad1a8[0x48];          // 0x160..0x1a7
    EQPlayerView_guess** field1a8;     // 0x1a8
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
    virtual void Slot52_guess(int value);
};

struct EffectHost_guess {
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
    virtual void Slot77_guess();
    virtual void Slot78_guess();
    virtual void Slot79_guess();
    virtual void Slot80_guess();
    virtual void Slot81_guess();
    virtual void Slot82_guess();
    virtual void Slot83_guess();
    virtual void Slot84_guess();
    virtual char Slot85_guess(int value);
};

struct State_guess {
    char pad0[0x30];
    float x30;
    float y34;
    float z38;
    char pad3c[0x16c];
    EffectHost_guess** host1a8;
    // EXTERNAL: TITANIUM 0x0047BF6C State_guess::GetEffect_guess
    char GetEffect_guess(int effectId_guess, int* effectInfo_guess);
};

struct Container_guess {
    EQPlayerView_guess* actor0;
    char pad4[0x158];
    State_guess* field15c;
};

struct Input_guess {
    char pad0[0x30];
    float x30;
    float y34;
    float z38;
    char pad3c[0x10];
    float heading_004c_guess;
    char pad50[0xc];
    float cameraAngle_005c_guess;
    char pad60[0x148];
    Container_guess* container1a8;
    char pad1ac[0xa5];
    char mode251;
    // EXTERNAL: TITANIUM 0x00489BF5 Input_guess::GetHeight_guess
    float GetHeight_guess();
};

struct Transform_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Slot02_guess(float value_guess);
    virtual float Slot03_guess(float value_guess);
};

struct Resolver_guess {
    // EXTERNAL: TITANIUM 0x0043A15C Resolver_guess::s3dCollideSphereWithWorld_guess
    void s3dCollideSphereWithWorld_guess(float x0_guess, float y0_guess, float z0_guess,
                       float x_guess, float y_guess, float z_guess,
                       float* outX_guess, float* outY_guess, float* outZ_guess,
                       int mode_guess);
};

struct Result_guess {
    char pad0[4];
    float x;
    float y;
    float z;
    float value10;
    float value14;
    float value18;
    char pad1c[0x2c];
    Input_guess* source48;
    Settings_guess* SetFrom_guess(Input_guess* source_guess);
};

struct Settings_guess {
    char pad0[0xb54];
    int fieldb54;
};

#define g_transform_guess EQ_GLOBAL(Transform_guess*, 0x0099E374)
#define g_resolver_guess EQ_GLOBAL(Resolver_guess*, 0x00905D24)
#define g_settings_guess EQ_GLOBAL(Settings_guess*, 0x00988DF0)

struct Owner_guess {
    char pad0[0x48];
    EQPlayerView_guess* field48;       // 0x48
    void Clear_guess(int arg_guess);
    void Update_guess();
};

struct Condition_guess {
    void* field0;
    // EXTERNAL: TITANIUM 0x0048F019 Condition_guess::CheckCondition_guess
    char CheckCondition_guess();
};

struct DispatchSource_guess {
    char pad0[0x1a8];
    Condition_guess* field1a8;
};

struct Dispatcher_guess {
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
    virtual void Slot16_guess(DispatchSource_guess* source_guess);
    virtual void Slot17_guess(DispatchSource_guess* source_guess);
    void Dispatch_guess(DispatchSource_guess* source_guess);
};

struct Node_guess {         // array at 0x009254FC, indexed by g_index
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess(Owner_guess* who);
    Vector3_guess a4;           // 0x04
    Vector3_guess b10;          // 0x10
};

struct Sink_guess {         // object at 0x0099E370
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
    virtual void Slot10_guess(int a, char b);
    virtual char Slot11_guess(int a);
};

struct Mesh_guess {         // object at 0x0099E368
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
    virtual char Slot12_guess(Vector3_guess* v);
};

struct Cam2_guess {         // object at Display+0x118
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
    virtual int Slot13_guess(Vector3_guess* v, int b);
    virtual void Slot14_guess(Vector3_guess* v);
};

struct Display_guess {      // object at 0x00905D24
    char pad0[0x118];
    Cam2_guess* field118;       // 0x118
    Vector3_guess* field11c;    // 0x11C
    Vector3_guess* field120;    // 0x120
};

struct Ray_guess {
    // EXTERNAL: TITANIUM 0x0056FCB1 Ray_guess::ApplyShake_guess
    Vector3_guess* ApplyShake_guess();
};

// EXTERNAL: TITANIUM 0x0056FC86 GetCameraShake_guess
Ray_guess* __stdcall GetCameraShake_guess(Vector3_guess* v);
// EXTERNAL: TITANIUM 0x0043A292 GetEnvironment_guess
char __stdcall GetEnvironment_guess(float x, float y, float z, int mode);

#define g_sinkA_guess EQ_GLOBAL(Sink_guess*, 0x0099E370)
#define g_mesh_guess EQ_GLOBAL(Mesh_guess*, 0x0099E368)
#define g_display_guess EQ_GLOBAL(Display_guess*, 0x00905D24)
#define g_cameras_guess EQ_ARRAY(Node_guess*, 0x009254FC)
#define g_index_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_pickFlag_guess EQ_GLOBAL(char, 0x0085097C)
#define g_pickFlagOld_guess EQ_GLOBAL(char, 0x00796230)
#define g_lastIndex_guess EQ_GLOBAL(char, 0x0099CA04)

// Runs the current camera mode's object, then pushes its position and orientation into the CDisplay
// camera (+0x118); if the filtered position is refused, retries with the raw one. Then records the region
// type at the camera (0x85097C, probably water or similar) and the mode just used (0x99CA04).
// FUNCTION: TITANIUM 0x0056FFA8
// @early-stop: unknown, diff ndiff=2
void Owner_guess::Update_guess() {
    char prev = g_sinkA_guess->Slot11_guess(3);
    // Render state 3 is switched off while the camera object runs, then restored.
    g_sinkA_guess->Slot10_guess(3, 0);
    g_cameras_guess[g_index_guess]->Slot02_guess(this);
    g_sinkA_guess->Slot10_guess(3, prev);
    Vector3_guess tmp;
    {
        Vector3_guess* s = &g_cameras_guess[g_index_guess]->a4;
        tmp.x = s->x;
        tmp.y = s->y;
        tmp.z = s->z;
    }
    Vector3_guess* p = GetCameraShake_guess(&tmp)->ApplyShake_guess();
    Vector3_guess* d = g_display_guess->field11c;
    d->x = p->x;
    d->y = p->y;
    d->z = p->z;
    {
        Vector3_guess* e = &g_cameras_guess[g_index_guess]->b10;
        Vector3_guess* f = g_display_guess->field120;
        f->x = e->x;
        f->y = e->y;
        f->z = e->z;
    }
    g_display_guess->field118->Slot14_guess(g_display_guess->field120);
    if (g_display_guess->field118->Slot13_guess(g_display_guess->field11c, 0)) {
        Vector3_guess* s = &g_cameras_guess[g_index_guess]->a4;
        Vector3_guess* g = g_display_guess->field11c;
        g->x = s->x;
        g->y = s->y;
        g->z = s->z;
        g_display_guess->field118->Slot13_guess(g_display_guess->field11c, 0);
    }
    if (g_mesh_guess->Slot12_guess(g_display_guess->field11c)) {
        g_pickFlag_guess = 0;
        Vector3_guess* q = g_display_guess->field11c;
        g_pickFlag_guess = GetEnvironment_guess(q->x, q->y, q->z, 0);
        if (g_pickFlagOld_guess != g_pickFlag_guess)
            g_pickFlagOld_guess = g_pickFlag_guess;
    }
    g_lastIndex_guess = (char)g_index_guess;
}

// Calls vtable slot 17 for a source whose +0x1A8 condition holds (0x48F019), else slot 16.
// FUNCTION: TITANIUM 0x00570147
void Dispatcher_guess::Dispatch_guess(DispatchSource_guess* source_guess) {
    if (source_guess->field1a8->field0 != 0 &&
        source_guess->field1a8->CheckCondition_guess() != 0)
        Slot17_guess(source_guess);
    else
        Slot16_guess(source_guess);
}

#define g_actorA_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CE4)
#define g_actorB_guess EQ_GLOBAL(EQPlayerView_guess*, 0x00905CF8)

// Forgets the followed actor (+0x48). For the local or controlled player (0x905CE4, 0x905CF8) it first
// sets a float on its model (slot 28) to 0, probably the first-person fade; other actors are just dropped.
// FUNCTION: TITANIUM 0x0057017A
void Owner_guess::Clear_guess(int arg_guess) {
    if (field48 != g_actorA_guess && field48 != g_actorB_guess)
        field48 = 0;
    EQPlayerView_guess* p = field48;
    if (p != 0) {
        EQPlayerView_guess** pp = p->field1a8;
        if (pp != 0) {
            EQPlayerView_guess* q = *pp;
            if (q != 0)
                q->Slot28_guess(0.0f);
        }
    }
    field48 = 0;
}

// Eye position for following player `source_guess`: its position at head height, or, when it rides
// something (+0x1A8 +0x15C), the mount's position raised by attachment point 0x12's height (else head + 3.5)
// and pushed along the heading. The result is collided with the world from the player (mode 3); heading
// +0x4C, pitch +0x5C (8.5 lower unless CEverQuest +0xB54 is 1), roll 0.
// FUNCTION: TITANIUM 0x005701C0
// @early-stop: budget, structural ndiff=53
Settings_guess* Result_guess::SetFrom_guess(Input_guess* source_guess) {
    Container_guess* container_guess = source_guess->container1a8;
    EQPlayerView_guess* actor_guess = container_guess->actor0;
    State_guess* state_guess;
    int effectInfo_guess[3];
    Vector3_guess offset_guess;
    Vector3_guess sourcePosition_guess;

    source48 = source_guess;
    if (container_guess->field15c == 0) {
        x = source_guess->x30;
        y = source_guess->y34;
        z = source_guess->z38;
        // +0x251 'o': the eye stays at the feet, no head height added.
        if (source_guess->mode251 == 'o')
            z = source_guess->z38;
        else
            z = source_guess->GetHeight_guess() + source_guess->z38;
    } else {
        // Below pitch -16 the player's model gets its position and the pitch + 16 (slots 18, 19).
        if (source_guess->cameraAngle_005c_guess < -16.0f) {
            sourcePosition_guess.x = source_guess->x30;
            sourcePosition_guess.y = source_guess->y34;
            sourcePosition_guess.z = source_guess->z38;
            offset_guess.x = source_guess->heading_004c_guess;
            offset_guess.y = source_guess->cameraAngle_005c_guess + 16.0f;
            offset_guess.z = 0.0f;
            actor_guess->Slot18_guess(&sourcePosition_guess);
            actor_guess->Slot19_guess(&offset_guess);
        }

        state_guess = container_guess->field15c;
        x = state_guess->x30;
        y = state_guess->y34;
        z = state_guess->z38;
        if ((*state_guess->host1a8)->Slot85_guess(0x12) == 0 ||
            state_guess->GetEffect_guess(0x12, effectInfo_guess) == 0) {
            z = source_guess->GetHeight_guess() + source_guess->z38 + 3.5f;
        } else {
            z = source_guess->GetHeight_guess() + ((float*)effectInfo_guess)[2];
        }
        x += g_transform_guess->Slot03_guess(source_guess->heading_004c_guess);
        y += g_transform_guess->Slot02_guess(source_guess->heading_004c_guess);
        actor_guess->Slot52_guess(1);
    }

    if (actor_guess->Slot07_guess() == 0)
        actor_guess->Slot06_guess(1);
    g_resolver_guess->s3dCollideSphereWithWorld_guess(source_guess->x30, source_guess->y34, source_guess->z38,
                                    x, y, z, &x, &y, &z, 3);
    value10 = source_guess->heading_004c_guess;
    value14 = source_guess->cameraAngle_005c_guess;
    value18 = 0.0f;
    if (g_settings_guess->fieldb54 != 1)
        value14 -= 8.5f;
    return g_settings_guess;
}
