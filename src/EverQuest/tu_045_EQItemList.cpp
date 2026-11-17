// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 45: a hint from compare/tumap.py.
// EQItemList: the doubly linked list of items lying on the ground (head 0x905CC8). EQItemList_guess is
// EQItemList (MQ2 names the ctor and dtor); value0C_guess is the drop id and value14_guess the item's actor.
#include "titanium/eqaddr.h"

struct EQItemList_guess {
    EQItemList_guess* prev_guess;
    EQItemList_guess* next_guess;
    int unknown08_guess;
    int dropId_000c_guess;
    int unknown10_guess;
    int actor_0014_guess;
    int unknown18_guess;
    float unknown1C_guess;
    float unknown20_guess;
    float value24_guess;
    float value28_guess;
    char actorDefName_002c_guess[0x20];
    int unknown4C_guess;
    int unknown50_guess;
    int unknown54_guess;
    int unknown58_guess;

    EQItemList_guess* Init_guess();
    EQItemList_guess* FindByDropId_guess(int value);
    EQItemList_guess* FindByActor_guess(int value);
    void Remove_guess();
};

struct CDisplayView_guess {
    // EXTERNAL: TITANIUM 0x00439A46 CDisplayView_guess::Release_guess
    void Release_guess(int value);
};

#define g_listHead_guess EQ_GLOBAL(EQItemList_guess*, 0x00905CC8)
#define g_manager_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EQItemList::EQItemList: pushes the item at the head of the ground list and sets the defaults.
// FUNCTION: TITANIUM 0x0046469F
EQItemList_guess* EQItemList_guess::Init_guess() {
    if (g_listHead_guess == 0) {
        g_listHead_guess = this;
        next_guess = 0;
        prev_guess = 0;
    } else {
        g_listHead_guess->prev_guess = this;
        next_guess = g_listHead_guess;
        prev_guess = 0;
        g_listHead_guess = this;
    }
    value28_guess = 0.0f;
    unknown20_guess = 0.0f;
    value24_guess = 20.0f;
    unknown1C_guess = 0.0f;
    // Placeholder model until the real one is known (the older client's constructor does the same).
    strcpy(actorDefName_002c_guess, "SWORD_ACTORDEF");
    unknown4C_guess = -1;
    unknown54_guess = -1;
    dropId_000c_guess = 0;
    unknown18_guess = 0;
    unknown58_guess = 0;
    actor_0014_guess = 0;
    unknown50_guess = 10;
    // 0x924470 is probably the current zone id (other TUs call it that).
    unknown10_guess = EQ_GLOBAL(int, 0x00924470);
    return this;
}

// EQItemList::~EQItemList: unlinks the item and deletes its actor (CDisplay::DeleteActor).
// FUNCTION: TITANIUM 0x0046471B
void EQItemList_guess::Remove_guess() {
    EQItemList_guess* next = next_guess;
    EQItemList_guess* prev = prev_guess;
    do {
        if (prev != 0) {
            if (next != 0) {
                prev_guess->next_guess = next_guess;
                next_guess->prev_guess = prev_guess;
                break;
            }
        } else if (next != 0) {
            next_guess->prev_guess = 0;
            g_listHead_guess = next_guess;
            break;
        }
        if (prev_guess != 0) {
            // Last item: only the back link is cut. Head with no successor: the list empties.
            prev_guess->next_guess = 0;
        } else {
            next_guess = 0;
            prev_guess = 0;
            g_listHead_guess = 0;
        }
    } while (0);
    if (actor_0014_guess != 0) {
        g_manager_guess->Release_guess(actor_0014_guess);
    }
}

// The ground item with drop id `value`, or 0.
// FUNCTION: TITANIUM 0x00464770
EQItemList_guess* EQItemList_guess::FindByDropId_guess(int dropId) {
    EQItemList_guess* node = g_listHead_guess;
    while (node != 0 && node->dropId_000c_guess != dropId) {
        node = node->next_guess;
    }
    return node;
}

// The ground item whose actor is `value`, or 0.
// FUNCTION: TITANIUM 0x0046478A
EQItemList_guess* EQItemList_guess::FindByActor_guess(int value) {
    EQItemList_guess* node = g_listHead_guess;
    while (node != 0 && node->actor_0014_guess != value) {
        node = node->next_guess;
    }
    return node;
}
