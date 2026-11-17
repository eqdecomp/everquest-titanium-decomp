// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 52: a hint from compare/tumap.py.
// EQObject (Mac map: ctor 0x4790D0, dtor 0x479305): a placed ground object such as a dropped item, ladder or
// grass, kept on a list whose head is 0x905CD8. EQObject_guess is EQObject; g_manager_guess is CDisplay
// (CreateActor 0x43972A, DeleteActor 0x439A46).
#include "titanium/eqaddr.h"
#include "titanium/crt.h"

struct Actor_guess {
    virtual void Slot0_guess();
    virtual void Slot1_guess();
    virtual void Slot2_guess();
    virtual void Slot3_guess(int state);
    virtual void Slot4_guess(int value);
    virtual void Slot5_guess();
    virtual void Slot6_guess();
    virtual void Slot7_guess();
    virtual void Slot8_guess();
    virtual void Slot9_guess();
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
    virtual void Slot20_guess(float scale, int flag);
};

struct ActorInfo_guess {
    char pad00[0x48];
    float f48_guess;
};

struct Spawn_guess {
    char pad00[0x30];
    float f30_guess;
    float f34_guess;
    char pad38[0x14];
    float f4c_guess;
    float f50_guess;
    char pad54[0x1a8 - 0x54];
    ActorInfo_guess* info1a8_guess;
};

struct EQObject_guess {
    unsigned char kind_0000_guess;
    char pad01[3];
    EQObject_guess* previous;
    EQObject_guess* next;
    char name0c_guess[0x14];
    char name20_guess[0x1c];
    float scale_003c_guess;
    float f40_guess;
    float f44_guess;
    float f48_guess;
    float f4c_guess;
    float f50_guess;
    void* actor_0054_guess;

    void Unlink();
    EQObject_guess* Init_guess(EQObject_guess* src, Spawn_guess* spawn, char* defName, char* name);
};

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x00439A46 Manager_guess::DeleteActor_guess
    void DeleteActor_guess(void* data);
    // EXTERNAL: TITANIUM 0x0043972A Manager_guess::CreateActor_guess
    Actor_guess* CreateActor_guess(char* name, float a, float b, float c, float d, float e, float f, int g, int h);
};

#define g_eqObjectListHead_guess EQ_GLOBAL(EQObject_guess*, 0x00905CD8)
#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x00905D24)

// Mac: EQObject::EQObject. Pushes the object at the list head, then builds it from `src` (a copy) or from
// `spawn` (dropped where the spawn stands: its x/y, floor + 0.25, heading +0x4C, +0x50; scale 1), and creates
// the actor "<name>_ACTORDEF". A failed copy empties `defName` for the caller; a failed drop keeps state 0.
// FUNCTION: TITANIUM 0x004790D0
EQObject_guess* EQObject_guess::Init_guess(EQObject_guess* src, Spawn_guess* spawn, char* defName, char* name)
{
    char buf_guess[40];
    Actor_guess* actor_guess;

    kind_0000_guess = 0;
    if (g_eqObjectListHead_guess == 0) {
        g_eqObjectListHead_guess = this;
        next = 0;
        previous = 0;
    } else {
        g_eqObjectListHead_guess->previous = this;
        next = g_eqObjectListHead_guess;
        previous = 0;
        g_eqObjectListHead_guess = this;
    }

    if (src == 0) {
        strcpy(name0c_guess, defName);
        strcpy(name20_guess, name);
        f40_guess = spawn->f30_guess;
        f44_guess = spawn->f34_guess;
        f48_guess = spawn->info1a8_guess->f48_guess + 0.25f;
        f4c_guess = spawn->f4c_guess;
        unsigned int bits50_guess = *(unsigned int*)&spawn->f50_guess;
        scale_003c_guess = 1.0f;
        *(unsigned int*)&f50_guess = bits50_guess;
        sprintf(buf_guess, "%s_ACTORDEF", name20_guess);
        actor_guess = g_manager_guess->CreateActor_guess(buf_guess, f40_guess, f44_guess, f48_guess, f4c_guess, f50_guess, 0.0f, 0, 0);
        actor_0054_guess = actor_guess;
        if (actor_guess == 0) {
            return this;
        }
        actor_guess->Slot4_guess(4);
    } else {
        strcpy(name0c_guess, src->name0c_guess);
        strcpy(name20_guess, src->name20_guess);
        f40_guess = src->f40_guess;
        f44_guess = src->f44_guess;
        f48_guess = src->f48_guess;
        f4c_guess = src->f4c_guess;
        f50_guess = src->f50_guess;
        scale_003c_guess = src->scale_003c_guess;
        if (scale_003c_guess <= 0.0f) {
            scale_003c_guess = 1.0f;
        }
        sprintf(buf_guess, "%s_ACTORDEF", name20_guess);
        actor_guess = g_manager_guess->CreateActor_guess(buf_guess, f40_guess, f44_guess, f48_guess, f4c_guess, f50_guess, 0.0f, 1, 0);
        actor_0054_guess = actor_guess;
        if (actor_guess != 0) {
            actor_guess->Slot4_guess(4);
        }
    }
    kind_0000_guess = 7;
    if (actor_0054_guess == 0) {
        strcpy(defName, EQ_ARRAY(char, 0x0063F53F));
    } else {
        // Object kinds (slot 3): 7 plain, 6 ladder (any case), 8 grass; slot 4 gets 4, 5 or 6 to match.
        if (_strnicmp(name20_guess, "LADDER", 6) == 0) {
            kind_0000_guess = 6;
            ((Actor_guess*)actor_0054_guess)->Slot4_guess(5);
        }
        if (strncmp(name0c_guess, "GRASS_", 6) == 0) {
            kind_0000_guess = 8;
            ((Actor_guess*)actor_0054_guess)->Slot4_guess(6);
        }
        ((Actor_guess*)actor_0054_guess)->Slot3_guess(kind_0000_guess);
        // Scale (+0x3C).
        ((Actor_guess*)actor_0054_guess)->Slot20_guess(scale_003c_guess, 1);
    }
    return this;
}

// Mac: EQObject::~EQObject. Unlinks the object (state 0xFF: never linked) and deletes its actor. The list
// head is the newest object; `next` runs toward older ones.
// FUNCTION: TITANIUM 0x00479305
void EQObject_guess::Unlink()
{
    if (kind_0000_guess != 0xff) {
        do {
            if (previous != 0) {
                if (next != 0) {
                    previous->next = next;
                    next->previous = previous;
                    break;
                }
            }
            if (previous == 0) {
                if (next != 0) {
                    next->previous = 0;
                    g_eqObjectListHead_guess = next;
                    break;
                }
            }
            if (next == 0 && previous != 0) {
                previous->next = 0;
            } else {
                next = 0;
                previous = 0;
                g_eqObjectListHead_guess = 0;
            }
        } while (0);
    }

    if (actor_0054_guess != 0) {
        g_manager_guess->DeleteActor_guess(actor_0054_guess);
    }
}
