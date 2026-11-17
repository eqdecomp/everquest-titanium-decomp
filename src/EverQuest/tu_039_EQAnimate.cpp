// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 39: a hint from compare/tumap.py.
// The old-model player animation driver, OldPlayerAnimation_guess (vtable 0x6446B0, base
// PlayerAnimationBase_guess at 0x6444F0), and the tables for its 79 animation rows ("InitAnimationTracks()"
// in the log text). The OldPlayerAnimation*View_guess classes are views of that one object: +4 is the
// EQPlayer, +0xC/+0x10 the two animation channels. Three EQ_Spell helpers (EQ_SpellView_guess) come first.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/classes.h"
#include "titanium/races.h"
#include <string.h>
#include <new>

template <class T, unsigned int N>
struct BoundedArray_guess {
    T data[N];
    T& operator[](int index) {
        if ((unsigned int)index >= N) {
            __debugbreak();
        }
        return data[index];
    }
};

struct EQ_SpellView_guess {
    int id;
    unsigned char pad04[0x11c];
    BoundedArray_guess<int, 12> values;            // 0x120
    BoundedArray_guess<unsigned char, 0x24> bytes; // 0x150

    unsigned char GetSpellLevelNeeded_guess(int index);
    char FindAffectSlot_guess(int target);
    int IsIllusion_guess();
};

// Level the spell needs for class `index` (bytes at +0x150, classes 1-35); others read class 1's entry.
// FUNCTION: TITANIUM 0x0044E755
unsigned char EQ_SpellView_guess::GetSpellLevelNeeded_guess(int index) {
    /* fake match: the array reference puts `this` in the base register ([ecx+eax+N]); `bytes[index]` gives
       [eax+ecx+N] (probe) */
    BoundedArray_guess<unsigned char, 0x24>& table_guess = bytes;
    if (index >= 1 && index <= 0x23) {
        return table_guess[index];
    }
    return table_guess[1];
}

// 1-based slot of effect `target` among the spell's 12 effect ids (+0x120); 0 when absent or `this` is null.
// FUNCTION: TITANIUM 0x0044E77B
char EQ_SpellView_guess::FindAffectSlot_guess(int target) {
    if (this != 0) {
        BoundedArray_guess<int, 12>& table_guess = values;
        int i = 0;
        do {
            if (table_guess[i++] == target) {
                return (char)i;
            }
        } while (i < 12);
    }
    return 0;
}

// Has an Illusion effect (SPA 58), except spells 287 and 601.
// FUNCTION: TITANIUM 0x0044E79F
int EQ_SpellView_guess::IsIllusion_guess() {
    if (id == 0x11f || id == 0x259) {
        return false;
    }
    return FindAffectSlot_guess(0x3a) != 0;
}

// EXTERNAL: TITANIUM 0x006444F0 ??_7PlayerAnimationBase_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
struct PlayerAnimationBase_guess {
    virtual ~PlayerAnimationBase_guess();
    PlayerAnimationBase_guess* Release_guess(unsigned char flags);
};

PlayerAnimationBase_guess::~PlayerAnimationBase_guess()
{
}

// Scalar deleting destructor of PlayerAnimationBase_guess.
// FUNCTION: TITANIUM 0x0044E7C7
PlayerAnimationBase_guess* PlayerAnimationBase_guess::Release_guess(unsigned char flags)
{
    this->PlayerAnimationBase_guess::~PlayerAnimationBase_guess();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination, const char* source);

// Fills the animation-row tables. 0x8FFBC8 (20-byte rows) gets the 3-character track tag: rows 1-11
// C01-C11 (attacks), 12-16 D01-D05 (damage, death), 17-25 and 75-78 L (moving), 26/72/73 O (idles),
// 32-38/71/74 P (poses), 39-47 T (instruments, casts, monk), 27-31/48-70/77 S (social). 0x9001F8 (5-byte
// rows) gets the 4-letter name (KICK, WALK, STND...). Three 80-byte flag tables follow from 0x900388:
// animations a new request may interrupt (0x00450A17 refuses while the flag is 0);
// upper-body actions (2-9, 39-44) that play over moving legs; the leg rows they play over.
// FUNCTION: TITANIUM 0x0044E7E4
void InitAnimationTags_guess()
{
    // Fills the animation tables for ids 1-0x4E: first the 3-character track tags (C01, L02, S..., 0x14-byte
    // rows from 0x008FFBC8, the code's g_animTrackTags_guess; the stores are in the original's order, not by
    // id).
    strcpy(EQ_ARRAY(char, 0x008ffbdc), EQ_ARRAY(char, 0x00644664));
    strcpy(EQ_ARRAY(char, 0x008ffbf0), EQ_ARRAY(char, 0x00644660));
    strcpy(EQ_ARRAY(char, 0x008ffc04), EQ_ARRAY(char, 0x0064465c));
    strcpy(EQ_ARRAY(char, 0x008ffc18), EQ_ARRAY(char, 0x00644658));
    strcpy(EQ_ARRAY(char, 0x008ffc2c), EQ_ARRAY(char, 0x00644654));
    strcpy(EQ_ARRAY(char, 0x008ffc40), EQ_ARRAY(char, 0x00644650));
    strcpy(EQ_ARRAY(char, 0x008ffc54), EQ_ARRAY(char, 0x0064464c));
    strcpy(EQ_ARRAY(char, 0x008ffc68), EQ_ARRAY(char, 0x00644648));
    strcpy(EQ_ARRAY(char, 0x008ffc7c), EQ_ARRAY(char, 0x00644644));
    strcpy(EQ_ARRAY(char, 0x008ffc90), EQ_ARRAY(char, 0x00644640));
    strcpy(EQ_ARRAY(char, 0x008ffca4), EQ_ARRAY(char, 0x0064463c));
    strcpy(EQ_ARRAY(char, 0x008ffcb8), EQ_ARRAY(char, 0x00644638));
    strcpy(EQ_ARRAY(char, 0x008ffccc), EQ_ARRAY(char, 0x00644634));
    strcpy(EQ_ARRAY(char, 0x008ffce0), EQ_ARRAY(char, 0x00644630));
    strcpy(EQ_ARRAY(char, 0x008ffcf4), EQ_ARRAY(char, 0x0064462c));
    strcpy(EQ_ARRAY(char, 0x008ffd08), EQ_ARRAY(char, 0x00644628));
    strcpy(EQ_ARRAY(char, 0x008ffd1c), EQ_ARRAY(char, 0x00644624));
    strcpy(EQ_ARRAY(char, 0x008ffd30), EQ_ARRAY(char, 0x00644620));
    strcpy(EQ_ARRAY(char, 0x008ffd44), EQ_ARRAY(char, 0x0064461c));
    strcpy(EQ_ARRAY(char, 0x008ffd58), EQ_ARRAY(char, 0x00644618));
    strcpy(EQ_ARRAY(char, 0x008ffd6c), EQ_ARRAY(char, 0x00644614));
    strcpy(EQ_ARRAY(char, 0x008ffd80), EQ_ARRAY(char, 0x00644610));
    strcpy(EQ_ARRAY(char, 0x008ffd94), EQ_ARRAY(char, 0x0064460c));
    strcpy(EQ_ARRAY(char, 0x008ffda8), EQ_ARRAY(char, 0x00644608));
    strcpy(EQ_ARRAY(char, 0x008ffdbc), EQ_ARRAY(char, 0x00644604));
    strcpy(EQ_ARRAY(char, 0x009001e0), EQ_ARRAY(char, 0x00644600));
    strcpy(EQ_ARRAY(char, 0x009001a4), EQ_ARRAY(char, 0x006445fc));
    strcpy(EQ_ARRAY(char, 0x009001b8), EQ_ARRAY(char, 0x006445f8));
    strcpy(EQ_ARRAY(char, 0x008ffdd0), EQ_ARRAY(char, 0x006445f4));
    strcpy(EQ_ARRAY(char, 0x00900168), EQ_ARRAY(char, 0x006445f0));
    strcpy(EQ_ARRAY(char, 0x0090017c), EQ_ARRAY(char, 0x006445ec));
    strcpy(EQ_ARRAY(char, 0x008ffe48), EQ_ARRAY(char, 0x006445e8));
    strcpy(EQ_ARRAY(char, 0x008ffe5c), EQ_ARRAY(char, 0x006445e4));
    strcpy(EQ_ARRAY(char, 0x008ffe70), EQ_ARRAY(char, 0x006445e0));
    strcpy(EQ_ARRAY(char, 0x008ffe84), EQ_ARRAY(char, 0x006445dc));
    strcpy(EQ_ARRAY(char, 0x008ffe98), EQ_ARRAY(char, 0x006445d8));
    strcpy(EQ_ARRAY(char, 0x008ffeac), EQ_ARRAY(char, 0x006445d4));
    strcpy(EQ_ARRAY(char, 0x008ffec0), EQ_ARRAY(char, 0x006445d0));
    strcpy(EQ_ARRAY(char, 0x00900154), EQ_ARRAY(char, 0x006445cc));
    strcpy(EQ_ARRAY(char, 0x00900190), EQ_ARRAY(char, 0x006445c8));
    strcpy(EQ_ARRAY(char, 0x008ffde4), EQ_ARRAY(char, 0x006445c4));
    strcpy(EQ_ARRAY(char, 0x008ffdf8), EQ_ARRAY(char, 0x006445c0));
    strcpy(EQ_ARRAY(char, 0x008ffe0c), EQ_ARRAY(char, 0x006445bc));
    strcpy(EQ_ARRAY(char, 0x008ffe20), EQ_ARRAY(char, 0x006445b8));
    strcpy(EQ_ARRAY(char, 0x008ffe34), EQ_ARRAY(char, 0x006445b4));
    strcpy(EQ_ARRAY(char, 0x008fff88), EQ_ARRAY(char, 0x006445b0));
    strcpy(EQ_ARRAY(char, 0x008fff9c), EQ_ARRAY(char, 0x006445ac));
    strcpy(EQ_ARRAY(char, 0x008fffb0), EQ_ARRAY(char, 0x006445a8));
    strcpy(EQ_ARRAY(char, 0x008fffc4), EQ_ARRAY(char, 0x006445a4));
    strcpy(EQ_ARRAY(char, 0x008fffd8), EQ_ARRAY(char, 0x006445a0));
    strcpy(EQ_ARRAY(char, 0x008fffec), EQ_ARRAY(char, 0x0064459c));
    strcpy(EQ_ARRAY(char, 0x00900000), EQ_ARRAY(char, 0x00644598));
    strcpy(EQ_ARRAY(char, 0x00900014), EQ_ARRAY(char, 0x00644594));
    strcpy(EQ_ARRAY(char, 0x00900028), EQ_ARRAY(char, 0x00644590));
    strcpy(EQ_ARRAY(char, 0x0090003c), EQ_ARRAY(char, 0x0064458c));
    strcpy(EQ_ARRAY(char, 0x00900050), EQ_ARRAY(char, 0x00644588));
    strcpy(EQ_ARRAY(char, 0x00900064), EQ_ARRAY(char, 0x00644584));
    strcpy(EQ_ARRAY(char, 0x00900078), EQ_ARRAY(char, 0x00644580));
    strcpy(EQ_ARRAY(char, 0x0090008c), EQ_ARRAY(char, 0x0064457c));
    strcpy(EQ_ARRAY(char, 0x009000a0), EQ_ARRAY(char, 0x00644578));
    strcpy(EQ_ARRAY(char, 0x009000b4), EQ_ARRAY(char, 0x00644574));
    strcpy(EQ_ARRAY(char, 0x009000c8), EQ_ARRAY(char, 0x00644570));
    strcpy(EQ_ARRAY(char, 0x009000dc), EQ_ARRAY(char, 0x0064456c));
    strcpy(EQ_ARRAY(char, 0x009000f0), EQ_ARRAY(char, 0x00644568));
    strcpy(EQ_ARRAY(char, 0x00900104), EQ_ARRAY(char, 0x00644564));
    strcpy(EQ_ARRAY(char, 0x00900118), EQ_ARRAY(char, 0x00644560));
    strcpy(EQ_ARRAY(char, 0x0090012c), EQ_ARRAY(char, 0x0064455c));
    strcpy(EQ_ARRAY(char, 0x00900140), EQ_ARRAY(char, 0x00644558));
    strcpy(EQ_ARRAY(char, 0x009001cc), EQ_ARRAY(char, 0x00644554));
    strcpy(EQ_ARRAY(char, 0x008ffed4), EQ_ARRAY(char, 0x00644550));
    strcpy(EQ_ARRAY(char, 0x008ffee8), EQ_ARRAY(char, 0x0064454c));
    strcpy(EQ_ARRAY(char, 0x008ffefc), EQ_ARRAY(char, 0x00644548));
    strcpy(EQ_ARRAY(char, 0x008fff10), EQ_ARRAY(char, 0x00644544));
    strcpy(EQ_ARRAY(char, 0x008fff24), EQ_ARRAY(char, 0x00644540));
    strcpy(EQ_ARRAY(char, 0x008fff38), EQ_ARRAY(char, 0x0064453c));
    strcpy(EQ_ARRAY(char, 0x008fff4c), EQ_ARRAY(char, 0x00644538));
    strcpy(EQ_ARRAY(char, 0x008fff60), EQ_ARRAY(char, 0x00644534));
    strcpy(EQ_ARRAY(char, 0x008fff74), EQ_ARRAY(char, 0x00644530));
    // Then the 4-letter animation names (KICK, WALK, STND..., 5-byte rows from 0x009001F8, the code's
    // g_animNames_guess); several ids share a name.
    strcpy(EQ_ARRAY(char, 0x009001fd), EQ_ARRAY(char, 0x0063f924));
    strcpy(EQ_ARRAY(char, 0x00900202), EQ_ARRAY(char, 0x0063f98c));
    strcpy(EQ_ARRAY(char, 0x00900207), EQ_ARRAY(char, 0x0063f96c));
    strcpy(EQ_ARRAY(char, 0x0090020c), EQ_ARRAY(char, 0x0063f95c));
    strcpy(EQ_ARRAY(char, 0x00900211), EQ_ARRAY(char, 0x0063f99c));
    strcpy(EQ_ARRAY(char, 0x00900216), EQ_ARRAY(char, 0x0063f984));
    strcpy(EQ_ARRAY(char, 0x0090021b), EQ_ARRAY(char, 0x0063f944));
    strcpy(EQ_ARRAY(char, 0x00900220), EQ_ARRAY(char, 0x0063f93c));
    strcpy(EQ_ARRAY(char, 0x00900225), EQ_ARRAY(char, 0x0063f934));
    strcpy(EQ_ARRAY(char, 0x0090022a), EQ_ARRAY(char, 0x0063f92c));
    strcpy(EQ_ARRAY(char, 0x0090022f), EQ_ARRAY(char, 0x0063f91c));
    strcpy(EQ_ARRAY(char, 0x00900234), EQ_ARRAY(char, 0x0063f7a4));
    strcpy(EQ_ARRAY(char, 0x00900239), EQ_ARRAY(char, 0x0063f79c));
    strcpy(EQ_ARRAY(char, 0x0090023e), EQ_ARRAY(char, 0x0063f76c));
    strcpy(EQ_ARRAY(char, 0x00900243), EQ_ARRAY(char, 0x0063f794));
    strcpy(EQ_ARRAY(char, 0x00900248), EQ_ARRAY(char, 0x0063f78c));
    strcpy(EQ_ARRAY(char, 0x0090024d), EQ_ARRAY(char, 0x0063f8dc));
    strcpy(EQ_ARRAY(char, 0x00900252), EQ_ARRAY(char, 0x0063f8cc));
    strcpy(EQ_ARRAY(char, 0x00900257), EQ_ARRAY(char, 0x0063f844));
    strcpy(EQ_ARRAY(char, 0x0090025c), EQ_ARRAY(char, 0x0063f83c));
    strcpy(EQ_ARRAY(char, 0x00900261), EQ_ARRAY(char, 0x0063f764));
    strcpy(EQ_ARRAY(char, 0x00900266), EQ_ARRAY(char, 0x0063f834));
    strcpy(EQ_ARRAY(char, 0x0090026b), EQ_ARRAY(char, 0x0063f82c));
    strcpy(EQ_ARRAY(char, 0x00900270), EQ_ARRAY(char, 0x0063f84c));
    strcpy(EQ_ARRAY(char, 0x00900275), EQ_ARRAY(char, 0x0063f824));
    strcpy(EQ_ARRAY(char, 0x0090037e), EQ_ARRAY(char, 0x0063f8cc));
    strcpy(EQ_ARRAY(char, 0x0090036f), EQ_ARRAY(char, 0x0063f8dc));
    strcpy(EQ_ARRAY(char, 0x00900374), EQ_ARRAY(char, 0x0063f8cc));
    strcpy(EQ_ARRAY(char, 0x0090027a), EQ_ARRAY(char, 0x0063f8a4));
    strcpy(EQ_ARRAY(char, 0x00900360), EQ_ARRAY(char, 0x0063f8a4));
    strcpy(EQ_ARRAY(char, 0x00900365), EQ_ARRAY(char, 0x0063f864));
    strcpy(EQ_ARRAY(char, 0x00900298), EQ_ARRAY(char, 0x0063f8ac));
    strcpy(EQ_ARRAY(char, 0x0090029d), EQ_ARRAY(char, 0x0063f854));
    strcpy(EQ_ARRAY(char, 0x009002a2), EQ_ARRAY(char, 0x0063f8c4));
    strcpy(EQ_ARRAY(char, 0x009002a7), EQ_ARRAY(char, 0x0063f8bc));
    strcpy(EQ_ARRAY(char, 0x009002ac), EQ_ARRAY(char, 0x0063f8b4));
    strcpy(EQ_ARRAY(char, 0x009002b1), EQ_ARRAY(char, 0x0063f81c));
    strcpy(EQ_ARRAY(char, 0x009002b6), EQ_ARRAY(char, 0x0063f86c));
    strcpy(EQ_ARRAY(char, 0x0090035b), EQ_ARRAY(char, 0x0063f8ac));
    strcpy(EQ_ARRAY(char, 0x0090036a), EQ_ARRAY(char, 0x0063f8ac));
    strcpy(EQ_ARRAY(char, 0x0090027f), EQ_ARRAY(char, 0x0063f714));
    strcpy(EQ_ARRAY(char, 0x00900284), EQ_ARRAY(char, 0x0063f70c));
    strcpy(EQ_ARRAY(char, 0x00900289), EQ_ARRAY(char, 0x0063f74c));
    strcpy(EQ_ARRAY(char, 0x0090028e), EQ_ARRAY(char, 0x0063f704));
    strcpy(EQ_ARRAY(char, 0x00900293), EQ_ARRAY(char, 0x0063f6fc));
    strcpy(EQ_ARRAY(char, 0x009002e8), EQ_ARRAY(char, 0x0063f744));
    strcpy(EQ_ARRAY(char, 0x009002ed), EQ_ARRAY(char, 0x0063f6c4));
    strcpy(EQ_ARRAY(char, 0x009002f2), EQ_ARRAY(char, 0x0063f6f4));
    strcpy(EQ_ARRAY(char, 0x009002f7), EQ_ARRAY(char, 0x0063f73c));
    strcpy(EQ_ARRAY(char, 0x009002fc), EQ_ARRAY(char, 0x0063f734));
    strcpy(EQ_ARRAY(char, 0x00900301), EQ_ARRAY(char, 0x0063f6ec));
    strcpy(EQ_ARRAY(char, 0x00900306), EQ_ARRAY(char, 0x0063f724));
    strcpy(EQ_ARRAY(char, 0x0090030b), EQ_ARRAY(char, 0x0063f6e4));
    strcpy(EQ_ARRAY(char, 0x00900310), EQ_ARRAY(char, 0x0063f6dc));
    strcpy(EQ_ARRAY(char, 0x00900315), EQ_ARRAY(char, 0x0063f6cc));
    strcpy(EQ_ARRAY(char, 0x0090031a), EQ_ARRAY(char, 0x0063f6d4));
    strcpy(EQ_ARRAY(char, 0x0090031f), EQ_ARRAY(char, 0x0063f6cc));
    strcpy(EQ_ARRAY(char, 0x00900324), EQ_ARRAY(char, 0x0063f71c));
    strcpy(EQ_ARRAY(char, 0x00900329), EQ_ARRAY(char, 0x0063f6c4));
    strcpy(EQ_ARRAY(char, 0x0090032e), EQ_ARRAY(char, 0x0063f6a4));
    strcpy(EQ_ARRAY(char, 0x00900333), EQ_ARRAY(char, 0x0063f6b4));
    strcpy(EQ_ARRAY(char, 0x00900338), EQ_ARRAY(char, 0x0063f72c));
    strcpy(EQ_ARRAY(char, 0x0090033d), EQ_ARRAY(char, 0x0063f71c));
    strcpy(EQ_ARRAY(char, 0x00900342), EQ_ARRAY(char, 0x0063f754));
    strcpy(EQ_ARRAY(char, 0x00900347), EQ_ARRAY(char, 0x0063f754));
    strcpy(EQ_ARRAY(char, 0x0090034c), EQ_ARRAY(char, 0x0063f6bc));
    strcpy(EQ_ARRAY(char, 0x00900351), EQ_ARRAY(char, 0x0063f6ac));
    strcpy(EQ_ARRAY(char, 0x00900356), EQ_ARRAY(char, 0x0063f75c));
    strcpy(EQ_ARRAY(char, 0x00900379), EQ_ARRAY(char, 0x0063f74c));
    strcpy(EQ_ARRAY(char, 0x009002bb), EQ_ARRAY(char, 0x0063f80c));
    strcpy(EQ_ARRAY(char, 0x009002c0), EQ_ARRAY(char, 0x0063f804));
    strcpy(EQ_ARRAY(char, 0x009002c5), EQ_ARRAY(char, 0x0063f7fc));
    strcpy(EQ_ARRAY(char, 0x009002ca), EQ_ARRAY(char, 0x0063f7ec));
    strcpy(EQ_ARRAY(char, 0x009002cf), EQ_ARRAY(char, 0x0063f7f4));
    strcpy(EQ_ARRAY(char, 0x009002d4), EQ_ARRAY(char, 0x0063f7e4));
    strcpy(EQ_ARRAY(char, 0x009002d9), EQ_ARRAY(char, 0x0063f8f4));
    strcpy(EQ_ARRAY(char, 0x009002de), EQ_ARRAY(char, 0x0063f8ec));
    strcpy(EQ_ARRAY(char, 0x009002e3), EQ_ARRAY(char, 0x0063f8e4));
    // Then three 0x50-byte yes/no tables indexed by animation id: 0x00900388 (the playing animation may be
    // interrupted; 0x00450A17 refuses while it is 0), then 0x009003D8 and 0x00900428, which SetAnim_guess
    // (0x00450C2F) reads when a moving humanoid layers a new animation over the playing one.
    EQ_GLOBAL(char, 0x00900388) = 1;
    EQ_GLOBAL(char, 0x00900399) = 1;
    EQ_GLOBAL(char, 0x0090039a) = 1;
    EQ_GLOBAL(char, 0x0090039d) = 1;
    EQ_GLOBAL(char, 0x0090039e) = 1;
    EQ_GLOBAL(char, 0x0090039f) = 1;
    EQ_GLOBAL(char, 0x009003a0) = 1;
    EQ_GLOBAL(char, 0x009003a1) = 1;
    EQ_GLOBAL(char, 0x009003d6) = 1;
    EQ_GLOBAL(char, 0x009003d3) = 1;
    EQ_GLOBAL(char, 0x009003d4) = 1;
    EQ_GLOBAL(char, 0x009003a8) = 1;
    EQ_GLOBAL(char, 0x009003aa) = 1;
    EQ_GLOBAL(char, 0x009003ab) = 1;
    EQ_GLOBAL(char, 0x009003ad) = 1;
    EQ_GLOBAL(char, 0x009003ae) = 1;
    EQ_GLOBAL(char, 0x009003cf) = 1;
    EQ_GLOBAL(char, 0x009003d2) = 1;
    EQ_GLOBAL(char, 0x009003a2) = 1;
    EQ_GLOBAL(char, 0x009003d0) = 1;
    EQ_GLOBAL(char, 0x009003d1) = 1;
    EQ_GLOBAL(char, 0x009003a3) = 1;
    EQ_GLOBAL(char, 0x009003a4) = 1;
    EQ_GLOBAL(char, 0x009003a5) = 1;
    EQ_GLOBAL(char, 0x009003a6) = 1;
    EQ_GLOBAL(char, 0x009003a7) = 1;
    EQ_GLOBAL(char, 0x009003b8) = 1;
    EQ_GLOBAL(char, 0x009003b9) = 1;
    EQ_GLOBAL(char, 0x009003ba) = 1;
    EQ_GLOBAL(char, 0x009003bb) = 1;
    EQ_GLOBAL(char, 0x009003bc) = 1;
    EQ_GLOBAL(char, 0x009003bd) = 1;
    EQ_GLOBAL(char, 0x009003be) = 1;
    EQ_GLOBAL(char, 0x009003bf) = 1;
    EQ_GLOBAL(char, 0x009003c0) = 1;
    EQ_GLOBAL(char, 0x009003c1) = 1;
    EQ_GLOBAL(char, 0x009003c2) = 1;
    EQ_GLOBAL(char, 0x009003c3) = 1;
    EQ_GLOBAL(char, 0x009003c4) = 1;
    EQ_GLOBAL(char, 0x009003c5) = 1;
    EQ_GLOBAL(char, 0x009003c6) = 1;
    EQ_GLOBAL(char, 0x009003c7) = 1;
    EQ_GLOBAL(char, 0x009003c8) = 1;
    EQ_GLOBAL(char, 0x009003c9) = 1;
    EQ_GLOBAL(char, 0x009003ca) = 1;
    EQ_GLOBAL(char, 0x009003cb) = 1;
    EQ_GLOBAL(char, 0x009003cc) = 1;
    EQ_GLOBAL(char, 0x009003cd) = 1;
    EQ_GLOBAL(char, 0x009003ce) = 1;
    EQ_GLOBAL(char, 0x009003d5) = 1;
    EQ_GLOBAL(char, 0x009003ff) = 1;
    EQ_GLOBAL(char, 0x00900400) = 1;
    EQ_GLOBAL(char, 0x00900401) = 1;
    EQ_GLOBAL(char, 0x00900402) = 1;
    EQ_GLOBAL(char, 0x00900403) = 1;
    EQ_GLOBAL(char, 0x00900404) = 1;
    EQ_GLOBAL(char, 0x009003da) = 1;
    EQ_GLOBAL(char, 0x009003db) = 1;
    EQ_GLOBAL(char, 0x009003dc) = 1;
    EQ_GLOBAL(char, 0x009003dd) = 1;
    EQ_GLOBAL(char, 0x009003de) = 1;
    EQ_GLOBAL(char, 0x009003df) = 1;
    EQ_GLOBAL(char, 0x009003e0) = 1;
    EQ_GLOBAL(char, 0x009003e1) = 1;
    EQ_GLOBAL(char, 0x00900439) = 1;
    EQ_GLOBAL(char, 0x0090043a) = 1;
    EQ_GLOBAL(char, 0x00900448) = 1;
    EQ_GLOBAL(char, 0x00900472) = 1;
    EQ_GLOBAL(char, 0x00900476) = 1;
    EQ_GLOBAL(char, 0x00900473) = 1;
    EQ_GLOBAL(char, 0x00900474) = 1;
}

// EXTERNAL: TITANIUM 0x00574110 LogError_guess
void __cdecl LogError_guess(const char* text);

// EXTERNAL: TITANIUM 0x00464A28 steve_strncpy_guess
void __cdecl steve_strncpy_guess(char* dest, const char* src, int count);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060E460 strcat
extern "C" char* __cdecl strcat(char* destination, const char* source);

struct TrackSetEntry_guess {
    unsigned int first;
    unsigned int second;
    unsigned int third;
    unsigned int fourth;
};

struct TrackSet_guess {
    TrackSetEntry_guess variantTracks[8];
    unsigned int variantCounts[8];
    unsigned char bytes[0x80];
    unsigned char flag;

    // EXTERNAL: TITANIUM 0x00451965 TrackSet_guess::TrackSet_guess
    TrackSet_guess();
    TrackSet_guess* Construct_guess();
};

struct FUN_0044f319_obj_guess {
    virtual unsigned int Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual unsigned int Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual FUN_0044f319_obj_guess* Slot3C_guess(const char* name) = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual void Slot88_guess() = 0;
    virtual void Slot8C_guess() = 0;
    virtual void Slot90_guess() = 0;
    virtual void Slot94_guess() = 0;
    virtual void Slot98_guess() = 0;
    virtual void Slot9C_guess() = 0;
    virtual void SlotA0_guess() = 0;
    virtual void SlotA4_guess() = 0;
    virtual void SlotA8_guess() = 0;
    virtual void SlotAC_guess() = 0;
    virtual void SlotB0_guess() = 0;
    virtual void SlotB4_guess() = 0;
    virtual void SlotB8_guess() = 0;
    virtual void SlotBC_guess() = 0;
    virtual void SlotC0_guess() = 0;
    virtual void SlotC4_guess() = 0;
    virtual void SlotC8_guess() = 0;
    virtual void SlotCC_guess() = 0;
    virtual void SlotD0_guess() = 0;
    virtual void SlotD4_guess() = 0;
    virtual void SlotD8_guess() = 0;
    virtual void SlotDC_guess() = 0;
    virtual void SlotE0_guess() = 0;
    virtual void SlotE4_guess() = 0;
    virtual void SlotE8_guess() = 0;
    virtual void SlotEC_guess() = 0;
    virtual void SlotF0_guess() = 0;
    virtual void SlotF4_guess() = 0;
    virtual void SlotF8_guess() = 0;
    virtual void SlotFC_guess() = 0;
    virtual void Slot100_guess() = 0;
    virtual void Slot104_guess() = 0;
    virtual void Slot108_guess() = 0;
    virtual void Slot10C_guess() = 0;
    virtual void Slot110_guess() = 0;
    virtual void Slot114_guess() = 0;
    virtual int Slot118_guess() = 0;
    virtual void Slot11C_guess() = 0;
    virtual void Slot120_guess() = 0;
    virtual void Slot124_guess() = 0;
    virtual void Slot128_guess() = 0;
    virtual void Slot12C_guess() = 0;
    virtual void Slot130_guess() = 0;
    virtual void Slot134_guess() = 0;
    virtual void Slot138_guess() = 0;
    virtual void Slot13C_guess() = 0;
    virtual void Slot140_guess() = 0;
    virtual void Slot144_guess() = 0;
    virtual void Slot148_guess() = 0;
    virtual void Slot14C_guess(int id, char* text) = 0;
    virtual char Slot150_guess() = 0;
    virtual char Slot154_guess(int id) = 0;
    virtual void Slot158_guess() = 0;
    virtual void Slot15C_guess() = 0;
    virtual void Slot160_guess() = 0;
    virtual void Slot164_guess() = 0;
    virtual FUN_0044f319_obj_guess* Slot168_guess(int id) = 0;
};

struct FUN_0044f319_ref_guess {
    FUN_0044f319_obj_guess* obj;        // 0x0
    char pad4[4];
    char text8[4];                      // 0x8
};

struct FUN_0044f319_outer_guess {
    char pad0[0x1a8];
    FUN_0044f319_ref_guess* ref;        // 0x1a8
};

struct FUN_0044f319_out_guess {
    char pad0[0x2c];
    TrackSet_guess** tracks;        // 0x2c
    int field30;                        // 0x30
    unsigned char flag34;               // 0x34
    char pad35[0x50 - 0x35];
    int field50;                        // 0x50
};

struct OldPlayerAnimationTracksView_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess(char* name, char* name2, unsigned char flag) = 0;
    FUN_0044f319_outer_guess* outer;    // 0x4

    void InitAnimationTracks_guess(FUN_0044f319_out_guess* out, FUN_0044f319_obj_guess* actor);
};

// Finds each row's track on the actor's model: data name = row tag + model tag (3 letters; SHI* models take
// sub-object 1's), else the second name Slot34_guess gives. A model with attach point 7 (TUNIC_POINT_DAG,
// added when missing) has variants: tracks A-H are tried first, and a plain track then counts only from 50
// (probably frames) up, or for KES and GP* models.
// FUNCTION: TITANIUM 0x0044F319
// @early-stop: budget, diff ndiff=7
void OldPlayerAnimationTracksView_guess::InitAnimationTracks_guess(FUN_0044f319_out_guess* out, FUN_0044f319_obj_guess* actor)
{
    char tag[0x80];
    char name110[0x80];
    char name190[0x80];
    char name210[0x80];
    if (actor == 0) {
        LogError_guess("actor is NULL in InitAnimationTracks()!\n");
        return;
    }
    if (outer->ref != 0 && actor->Slot118_guess() >= 1) {
        out->field30 = actor->Slot118_guess();
        steve_strncpy_guess(tag, outer->ref->text8, 4);
        if (tag[0] == 'S' && tag[1] == 'H' && tag[2] == 'I') {
            FUN_0044f319_obj_guess* sub = actor->Slot168_guess(1);
            if (sub != 0) {
                char* text = (char*)sub->Slot00_guess();
                steve_strncpy_guess(tag, text, 4);
            }
        }
        if (outer->ref->obj->Slot154_guess(7) == 0) {
            char name290[0x80];
            strcpy(name290, tag);
            strcat(name290, "TUNIC_POINT_DAG");
            outer->ref->obj->Slot14C_guess(7, name290);
        }
        if (outer->ref->obj->Slot154_guess(7) != 0) {
            out->flag34 = 1;
        }
        Slot34_guess(tag, name210, out->flag34);

        char letter[2] = "A";
        int n = 0;
        const char* prefix = EQ_ARRAY(char, 0x008ffbc8);
        do {
            if (out->tracks[n] == 0) {
                out->tracks[n] = new TrackSet_guess;
            }
            bool found = false;
            if (out->flag34 != 0) {
                for (unsigned char k = 0; k < 8; ++k) {
                    letter[0] = (char)('A' + k);
                    sprintf(name110, "%s%s%s", prefix, letter, tag);
                    sprintf(name190, "%s%s%s", prefix, letter, name210);
                    FUN_0044f319_obj_guess* obj = EQ_GLOBAL(FUN_0044f319_obj_guess*, 0x0099E360)->Slot3C_guess(name110);
                    if (obj == 0) {
                        obj = EQ_GLOBAL(FUN_0044f319_obj_guess*, 0x0099E360)->Slot3C_guess(name190);
                    }
                    if (obj != 0) {
                        out->tracks[n]->flag = 1;
                        out->tracks[n]->variantTracks[k].first = (unsigned int)obj;
                        out->tracks[n]->variantCounts[k] += 1;
                        out->field50 += 1;
                        found = true;
                    }
                }
            }
            if (!found) {
                sprintf(name110, "%s%s", prefix, tag);
                sprintf(name190, "%s%s", prefix, name210);
                FUN_0044f319_obj_guess* obj = EQ_GLOBAL(FUN_0044f319_obj_guess*, 0x0099E360)->Slot3C_guess(name110);
                if (obj == 0) {
                    obj = EQ_GLOBAL(FUN_0044f319_obj_guess*, 0x0099E360)->Slot3C_guess(name190);
                }
                if (obj != 0) {
                    bool keyB = outer->ref->text8[0] == 'K' && outer->ref->text8[1] == 'E' && outer->ref->text8[2] == 'S';
                    bool keyF = outer->ref->text8[0] == 'G' && outer->ref->text8[1] == 'P';
                    if (out->flag34 == 0 || obj->Slot08_guess() >= 0x32 || keyF || keyB) {
                        out->tracks[n]->flag = 0;
                        out->tracks[n]->variantTracks[0].first = (unsigned int)obj;
                        out->tracks[n]->variantCounts[0] += 1;
                        out->field50 += 1;
                    }
                }
            }
            n += 1;
            prefix += 0x14;
        } while ((int)prefix < (int)EQ_ARRAY(char, 0x009001f4));
    }
}

// EXTERNAL: TITANIUM 0x006446B0 ??_7OldPlayerAnimation_guess@@6B@
struct OldPlayerAnimationData_guess {
    unsigned int unused;
    unsigned char flag;

    OldPlayerAnimationData_guess()
        : flag(0)
    {
    }
};

struct OldPlayerAnimation_guess : OldPlayerAnimationData_guess {
    unsigned int fieldC;
    unsigned int field10;

    OldPlayerAnimation_guess(unsigned int value);
    virtual void Slot00_guess();
};

// Binds the driver to its EQPlayer (+4); no channels yet.
// FUNCTION: TITANIUM 0x0044F6D9
OldPlayerAnimation_guess::OldPlayerAnimation_guess(unsigned int value)
    : OldPlayerAnimationData_guess()
{
    unused = value;
    field10 = 0;
    fieldC = 0;
}

// Bone-name filter for splitting the skeleton (after the 3-letter model tag): 0 for upper-body bones FA,
// HE, FI, FO, BI, NE, HI, CH; 1 for the rest, CHCHEST_ included.
// FUNCTION: TITANIUM 0x0044F6FA
int __cdecl IsLowerBodyPart_guess(int param_1)
{
    const char* text = (const char*)param_1 + 3;
    if (strncmp(text, "CHCHEST_", 8) == 0) {
        return 1;
    }
    if (strncmp(text, "FA", 2) == 0 ||
        strncmp(text, "HE", 2) == 0 ||
        strncmp(text, "FI", 2) == 0 ||
        strncmp(text, "FO", 2) == 0 ||
        strncmp(text, "BI", 2) == 0 ||
        strncmp(text, "NE", 2) == 0 ||
        strncmp(text, "HI", 2) == 0 ||
        strncmp(text, "CH", 2) == 0) {
        return 0;
    }
    return 1;
}

struct FUN_0044f7c3_sink_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Notify_guess(int id, float value, int extra, int mode) = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess(int value) = 0;
};

struct FUN_0044f7c3_source_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot4C_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot5C_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot6C_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot78_guess() = 0;
    virtual void Slot7C_guess() = 0;
    virtual void Slot80_guess() = 0;
    virtual void Slot84_guess() = 0;
    virtual void Slot88_guess() = 0;
    virtual void Slot8C_guess() = 0;
    virtual void Slot90_guess() = 0;
    virtual void Slot94_guess() = 0;
    virtual void Slot98_guess() = 0;
    virtual void Slot9C_guess() = 0;
    virtual void SlotA0_guess() = 0;
    virtual void SlotA4_guess() = 0;
    virtual void SlotA8_guess() = 0;
    virtual void SlotAC_guess() = 0;
    virtual void SlotB0_guess() = 0;
    virtual void SlotB4_guess() = 0;
    virtual void SlotB8_guess() = 0;
    virtual void SlotBC_guess() = 0;
    virtual void SlotC0_guess() = 0;
    virtual void SlotC4_guess() = 0;
    virtual void SlotC8_guess() = 0;
    virtual void SlotCC_guess() = 0;
    virtual void SlotD0_guess() = 0;
    virtual void SlotD4_guess() = 0;
    virtual void SlotD8_guess() = 0;
    virtual void SlotDC_guess() = 0;
    virtual void SlotE0_guess() = 0;
    virtual void SlotE4_guess() = 0;
    virtual void SlotE8_guess() = 0;
    virtual void SlotEC_guess() = 0;
    virtual void SlotF0_guess() = 0;
    virtual void SlotF4_guess() = 0;
    virtual void SlotF8_guess() = 0;
    virtual void SlotFC_guess() = 0;
    virtual void Slot100_guess() = 0;
    virtual void Slot104_guess() = 0;
    virtual void Slot108_guess() = 0;
    virtual void Slot10C_guess() = 0;
    virtual void Slot110_guess() = 0;
    virtual void Slot114_guess() = 0;
    virtual void Slot118_guess() = 0;
    virtual void Slot11C_guess() = 0;
    virtual void Slot120_guess() = 0;
    virtual void Slot124_guess() = 0;
    virtual void Slot128_guess() = 0;
    virtual void Slot12C_guess() = 0;
    virtual void Slot130_guess() = 0;
    virtual void Slot134_guess() = 0;
    virtual void Slot138_guess() = 0;
    virtual void Slot13C_guess() = 0;
    virtual void Slot140_guess() = 0;
    virtual void Slot144_guess() = 0;
    virtual void Slot148_guess(int (__cdecl* callback)(int), int value, int flag) = 0;
    virtual void Slot14C_guess() = 0;
    virtual void Slot150_guess() = 0;
    virtual void Slot154_guess() = 0;
    virtual void Slot158_guess() = 0;
    virtual void Slot15C_guess() = 0;
    virtual void Slot160_guess() = 0;
    virtual void Slot164_guess() = 0;
    virtual void Slot168_guess() = 0;
    virtual void Slot16C_guess() = 0;
    virtual void Slot170_guess() = 0;
    virtual FUN_0044f7c3_sink_guess* Slot174_guess(int index) = 0;
};

struct FUN_0044f7c3_table_guess {
    char pad0[0x2c];
    int** rows;                         // 0x2c
    char pad30[0x20];
    int field50;                        // 0x50
};

struct FUN_0044f7c3_mid_guess {
    FUN_0044f7c3_source_guess* source;  // 0x0
    char pad4[0x128];
    FUN_0044f7c3_table_guess* table;    // 0x12c
};

struct FUN_0044f7c3_outer_guess {
    char pad0[0x1a8];
    FUN_0044f7c3_mid_guess* mid;        // 0x1a8
};

struct OldPlayerAnimationLayersView_guess {
    char pad0[4];
    FUN_0044f7c3_outer_guess* outer;    // 0x4
    char pad8[4];
    FUN_0044f7c3_sink_guess* sinkB;     // 0xc
    FUN_0044f7c3_sink_guess* sinkA;     // 0x10

    void Refresh_guess();
};

// Splits the skeleton at IsLowerBodyPart_guess into two channels (+0x10 upper, +0xC lower), preloads every
// track of the 79 rows into both, then starts row 32 (P01, stand).
// FUNCTION: TITANIUM 0x0044F7C3
void OldPlayerAnimationLayersView_guess::Refresh_guess()
{
    FUN_0044f7c3_table_guess* table = outer->mid->table;
    if (table != 0) {
        outer->mid->source->Slot148_guess(IsLowerBodyPart_guess, table->field50, 0);
        sinkA = outer->mid->source->Slot174_guess(0);
        sinkB = outer->mid->source->Slot174_guess(1);
        for (int i = 0; i < 79; ++i) {
            if (table->rows[i] != 0) {
                for (int j = 0; j < 32; j += 4) {
                    for (int k = 0; k < 4; ++k) {
                        int id = table->rows[i][j + k];
                        if (id != 0) {
                            if (sinkA != 0) {
                                sinkA->Slot14_guess(id);
                            }
                            if (sinkB != 0) {
                                sinkB->Slot14_guess(table->rows[i][j + k]);
                            }
                        }
                    }
                }
            }
        }
        int* last = table->rows[32];
        if (last != 0 && last[0] != 0) {
            int id = last[0];
            if (sinkA != 0) {
                sinkA->Notify_guess(id, 1.0f, 0, 1);
            }
            if (sinkB != 0) {
                sinkB->Notify_guess(id, 1.0f, 0, 1);
            }
            outer->mid->source->Slot44_guess();
        }
    }
}

struct FUN_0044f8eb_state_guess {
    char pad0[0x129];
    char flag129;                       // 0x129
};

// Doubles the speed of row `kind` for: 20 (L04 jump); 19 (L03) except race 8 male; 16 (D05) on variant
// models (`flag`); race 216; races 209-212 when 0x905D24+0x129 is set; and on female variant models
// (`b` = gender 1) rows 2 and 4, and 5 for race 2.
// FUNCTION: TITANIUM 0x0044F8EB
// @early-stop: budget, structural ndiff=26
float __stdcall AdjustAnimationSpeed_guess(int kind, float value, int a, int b, char flag)
{
    float result = value;
    if (kind == 0x14 || (kind == 0x13 && (a != 8 || b != 0)) || (kind == 0x10 && flag != 0) ||
        a == 0xd8 ||
        (EQ_GLOBAL(FUN_0044f8eb_state_guess*, 0x00905D24)->flag129 != 0 &&
         (a == 0xd2 || a == 0xd1 || a == 0xd3 || a == 0xd4)) ||
        (flag != 0 && b == 1 && (kind == 2 || kind == 4 || (a == 2 && kind == 5)))) {
        result = value + value;
    }
    return result;
}

struct FUN_0044f974_sink_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Notify_guess(int id, float value, int extra, int mode);
};

struct FUN_0044f974_entry_guess {
    int id;
};

struct FUN_0044f974_table_guess {
    char pad0[0x2c];
    FUN_0044f974_entry_guess** entries; // 0x2c
};

struct FUN_0044f974_mid_guess {
    char pad0[0x12c];
    FUN_0044f974_table_guess* table;    // 0x12c
    char pad130[4];
    unsigned int current;               // 0x134
};

struct FUN_0044f974_outer_guess {
    char pad0[0x1a8];
    FUN_0044f974_mid_guess* mid;        // 0x1a8
};

struct OldPlayerAnimationDirectView_guess {
    char pad0[4];
    FUN_0044f974_outer_guess* outer;    // 0x4
    char pad8[4];
    FUN_0044f974_sink_guess* sinkB;     // 0xc
    FUN_0044f974_sink_guess* sinkA;     // 0x10

    void PlayAnimationDirect_guess(unsigned short index, char flag, int extra, float value);
};

// Plays row `index` (< 79), variant 0, on both channels; `flag` restarts it (mode 1), else mode 3. Records
// it as the current row (+0x134).
// FUNCTION: TITANIUM 0x0044F974
void OldPlayerAnimationDirectView_guess::PlayAnimationDirect_guess(unsigned short index, char flag, int extra, float value)
{
    FUN_0044f974_mid_guess* mid = outer->mid;
    if (mid != 0 && mid->table != 0 && index < 0x4f) {
        FUN_0044f974_entry_guess* entry = mid->table->entries[index];
        if (entry != 0 && entry->id != 0) {
            int id = entry->id;
            if (sinkA != 0) {
                sinkA->Notify_guess(id, value, extra, (flag == 0) ? 3 : 1);
            }
            if (sinkB != 0) {
                sinkB->Notify_guess(id, value, extra, (flag == 0) ? 3 : 1);
            }
            outer->mid->current = index;
        }
    }
}

struct FUN_0044fa14_state_guess {
    char pad0[0x134];
    int field134;                       // 0x134
};

struct FUN_0044fa14_mid_guess {
    char pad0[0x1a8];
    FUN_0044fa14_state_guess* state;    // 0x1a8
};

struct OldPlayerAnimationJumpView_guess {
    char pad0[4];
    FUN_0044fa14_mid_guess* mid;        // 0x4

    char IsJumping_guess();
};

// True while row 19 or 20 (L03, L04: the jumps) plays.
// FUNCTION: TITANIUM 0x0044FA14
// @early-stop: budget, diff ndiff=5
char OldPlayerAnimationJumpView_guess::IsJumping_guess()
{
    FUN_0044fa14_state_guess* state = mid->state;
    if (state == 0) {
        return 0;
    }
    int value = state->field134;
    return value == 0x13 || value == 0x14;
}

struct FUN_0044fa37_state_guess {
    char pad0[0x34];
    unsigned char enabled;              // 0x34
};

struct FUN_0044fa37_actor_guess {
    char pad0[0x12c];
    FUN_0044fa37_state_guess* state;    // 0x12c
};

struct OldPlayerAnimationPlayView_guess {
    virtual char Slot00_guess();
    virtual char Dispatch_guess(int a, int b, int c, float f, int e, char extra);
    EQPlayer* player;                   // 0x4

    char SetAnimHeld_guess(int a, int b, int c, float f, int e);
};

// SetAnim_guess without a slot: variant models use the player's Holding value as the variant, others 0.
// FUNCTION: TITANIUM 0x0044FA37
char OldPlayerAnimationPlayView_guess::SetAnimHeld_guess(int a, int b, int c, float f, int e)
{
    EQPlayer* player = this->player;
    FUN_0044fa37_actor_guess* actor = (FUN_0044fa37_actor_guess*)player->pActorInfo;
    if (actor == 0 || actor->state == 0) {
        return 0;
    }
    if (actor->state->enabled != 0) {
        char extra = (char)player->Holding;
        return Dispatch_guess(a, b, c, f, e, extra);
    } else {
        return Dispatch_guess(a, b, c, f, e, 0);
    }
}

// Inlined base destructor: points the vtable back at PlayerAnimationBase_guess's (0x6444F0).
// FUNCTION: TITANIUM 0x0044FA88
void __fastcall DestroyAnimationBase_guess(unsigned int* param_1)
{
    *param_1 = (unsigned int)&EQ_GLOBAL(unsigned int, 0x006444F0);
}

struct FUN_0044fa8f_vec_guess {
    float y, x, z;
    // EXTERNAL: TITANIUM 0x00435B36 FUN_0044fa8f_vec_guess::LengthSquared_guess
    float LengthSquared_guess();
};

struct FUN_0044fa8f_actor_guess {
    char pad0[0xad];
    unsigned char fad;                  // 0xad
    unsigned char fae;                  // 0xae
    char padaf[0xbc - 0xaf];
    float fbc;                          // 0xbc
    char padc0[0x130 - 0xc0];
    unsigned int lastTime;              // 0x130
    int anim;                           // 0x134
    char pad138[0x150 - 0x138];
    char f150;                          // 0x150
    char pad151[0x15c - 0x151];
    int mount_f15c_guess;                           // 0x15c
    char pad160[0xf88 - 0x160];
    int ff88;                           // 0xf88
};

struct FUN_0044fa8f_player_guess {
    char pad0[0x30];
    float Y;                            // 0x30
    float X;                            // 0x34
    float Z;                            // 0x38
    float SpeedY;                       // 0x3c
    float SpeedX;                       // 0x40
    float SpeedZ;                       // 0x44
    float SpeedRun;                     // 0x48
    char pad4c[0x58 - 0x4c];
    float f58;                          // 0x58
    char pad5c[0x1a8 - 0x5c];
    FUN_0044fa8f_actor_guess* actor;    // 0x1a8
    char pad1ac[0x230 - 0x1ac];
    float RunSpeed;                     // 0x230
    char pad234[0x244 - 0x234];
    unsigned char Type;                 // 0x244
    char pad245[0x251 - 0x245];
    unsigned char StandState;           // 0x251
    char pad252[0x25c - 0x252];
    unsigned int MasterID;              // 0x25c
    int Race;                           // 0x260

    // EXTERNAL: TITANIUM 0x0047BFD0 FUN_0044fa8f_player_guess::IsRunning_guess
    bool IsRunning_guess();
    // EXTERNAL: TITANIUM 0x0047C2CD FUN_0044fa8f_player_guess::GetWalkSpeed_guess
    float GetWalkSpeed_guess();
};

struct FUN_0044fa8f_clock_guess {
    char pad0[0x148];
    unsigned int now;                   // 0x148
};

struct FUN_0044fa8f_math_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual float Sqrt_guess(float value);
};

// EXTERNAL: TITANIUM 0x004657EC number_percent_guess
int __cdecl number_percent_guess();

struct OldPlayerAnimationUpdateView_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void SetAnim_guess(unsigned short anim, bool a, bool b, float speed, bool c);
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
    virtual char CanPlay_guess(int anim);
    FUN_0044fa8f_player_guess* player;  // 0x4

    // EXTERNAL: TITANIUM 0x00486F60 OldPlayerAnimationUpdateView_guess::Finish_guess
    void Finish_guess();
    void UpdateMovementAnimation_guess(bool flag);
};

// Per-frame movement animation. Still: stand (32), duck (24), tread water (25) in water (+0xAD,
// the water type tu_081 reads, is 5 or more),
// or after 5 s an idle (26): roll above 75, or 99 for pets (MasterID). Moving: climb (23,
// reversed going down), jump (19/20) or fall (21), swim (37), else walk (17) / run (18) by speed against
// the walk-run midpoint, duck-walk (22); reversed when moving backwards.
// FUNCTION: TITANIUM 0x0044FA8F
// @early-stop: budget, structural ndiff=176
void OldPlayerAnimationUpdateView_guess::UpdateMovementAnimation_guess(bool flag)
{
    FUN_0044fa8f_actor_guess* actor = player->actor;
    // Standing still (speed under 0.1): stand, duck or tread water, then an idle after 5 s.
    if (((FUN_0044fa8f_vec_guess*)&player->SpeedY)->LengthSquared_guess() < 0.01f
        && player->actor->mount_f15c_guess == 0) {
        if (actor->ff88 == 1) {
            SetAnim_guess(0x20, 0, 0, 1.0f, 0);
            return;
        }
        if (EQ_GLOBAL(FUN_0044fa8f_clock_guess*, 0x00905D24)->now == actor->lastTime) {
            if (player->StandState == 'o') {
                SetAnim_guess(0x18, 1, 0, 10000.0f, 1);
            } else if (actor->fad < 5 && actor->anim != 0x25 && actor->anim != 0x19) {
                SetAnim_guess(0x20, 0, 0, 1.0f, 1);
            } else {
                SetAnim_guess(0x19, 0, 0, 1.0f, 0);
            }
        } else if (actor->fad >= 5 && player->Race != 0x18 && player->Race != 0x3d
                   && player->Race != 0x4a) {
            SetAnim_guess(0x19, 0, 0, 1.0f, 0);
        } else if (flag) {
            if (player->Race == 0x31) {
                SetAnim_guess(0x13, 1, 0, 1.5f, 1);
            } else if (player->f58 > 0.0f) {
                SetAnim_guess(player->StandState == 'o' ? 0x16 : 0x22, 1, 1, 1.0f, 1);
            } else if (player->f58 < 0.0f) {
                SetAnim_guess(player->StandState == 'o' ? 0x16 : 0x22, 1, 0, 1.0f, 1);
            }
        } else if (EQ_GLOBAL(FUN_0044fa8f_clock_guess*, 0x00905D24)->now - actor->lastTime <= 5000) {
            if (player->StandState != 'o') {
                int anim = actor->anim;
                if (anim != 0x25 && anim != 0x19) {
                    if (anim == 0x11 || anim == 0x12) {
                        SetAnim_guess(0x20, 0, 0, 1.0f, 1);
                    } else {
                        SetAnim_guess(0x20, 0, 0, 1.0f, 0);
                    }
                }
            }
        } else if (player->StandState != 'o') {
            int roll = number_percent_guess();
            actor->lastTime = EQ_GLOBAL(FUN_0044fa8f_clock_guess*, 0x00905D24)->now;
            if (CanPlay_guess(actor->anim) && EQ_GLOBAL(char, 0x009858C7) == 0) {
            FUN_0044fa8f_player_guess* p = player;
            int limit = p->MasterID != 0 ? 0x63 : 0x4b;
            if (p->Type == 1) {
                if (roll > limit) {
                    int race = p->Race;
                    SetAnim_guess(0x1a, 1, 0,
                                  (race == 0x31 || race == 0x9e || race == 0xc4) ? 1.5f : 1.0f, 0);
                } else {
                    SetAnim_guess(0x20, 0, 0, 1.0f, 0);
                }
            } else if (roll > limit) {
                SetAnim_guess(0x1a, 1, 0, 1.0f, 0);
            } else {
                SetAnim_guess(0x20, 0, 0, 1.0f, 0);
            }
            }
        }
    } else {
        actor->lastTime = 0;
        float speed = 1.0f;
        FUN_0044fa8f_player_guess* p = player;
        bool a = 1;
        bool b = 0;
        bool c = 0;
        if (actor->ff88 == 1) {
            unsigned char anim;
            // Zone 84 (firiona in the client's zone table) north of Y -4800 keeps the stand row here.
            if (EQ_GLOBAL(int, 0x00924470) == 0x54 && p->Y > -4800.0f) {
                anim = 0x20;
            } else {
                int cur = actor->anim;
                anim = 0x12;
                a = 0;
                if (cur != 0x11) {
                    if (cur != 0x12 || p->SpeedRun <= 0.0f) {
                        if (cur == 0x12) {
                            b = 1;
                            speed = 0.5f;
                        }
                        anim = 0x11;
                        a = 1;
                    }
                }
            }
            SetAnim_guess(anim, a, b, speed, 0);
            return;
        }
        // Climbing (actor +0x150 is 6, as in tu_081), reversed going down; then swim, jump or fall.
        if (actor->f150 == 6) {
            if (p->SpeedZ > 0.0f) {
                SetAnim_guess(0x17, 1, 0, 1.0f, 1);
            } else if (p->SpeedZ < 0.0f) {
                SetAnim_guess(0x17, 1, 1, 1.0f, 1);
            }
        } else if (p->SpeedY < 0.001f && p->SpeedY > -0.001f
                   && p->SpeedX < 0.001f && p->SpeedX > -0.001f) {
            unsigned char anim;
            if (actor->fad >= 5) {
                anim = 0x19;
                if (p->Race == 0x31 && flag) {
                    anim = 0x13;
                }
                SetAnim_guess(anim, 1, 0, 1.0f, 0);
            } else if (actor->fae < 5) {
                if (actor->fbc * 0.5f <= p->SpeedZ) {
                    anim = 0x14;
                    c = 1;
                    SetAnim_guess(anim, a, 0, 1.0f, c);
                } else if (p->SpeedZ < -2.25f) {
                    anim = 0x15;
                    a = 0;
                    c = 1;
                    SetAnim_guess(anim, a, 0, 1.0f, c);
                } else if (p->Race == 0x31 && flag) {
                    anim = 0x13;
                    SetAnim_guess(anim, a, 0, 1.0f, c);
                } else {
                    SetAnim_guess(0x20, 0, 0, 1.0f, 1);
                }
            }
        } else {
            speed = EQ_GLOBAL(FUN_0044fa8f_math_guess*, 0x0099E374)->Sqrt_guess(
                        p->SpeedX * p->SpeedX + p->SpeedY * p->SpeedY) * 0.5f + 1.0f;
            a = 0;
            c = 1;
            b = 0;
            unsigned char anim;
            if (actor->fad >= 5) {
                anim = 0x25;
                if (player->Race == 0x31 && flag) {
                    anim = 0x13;
                }
                SetAnim_guess(anim, 0, 0, speed, 1);
            } else {
            anim = 0xff;
            if (actor->fae < 5) {
                float walk;
                if (player->IsRunning_guess()) {
                    float run = player->RunSpeed;
                    walk = player->GetWalkSpeed_guess() + (run - player->GetWalkSpeed_guess()) * 0.5f;
                } else {
                    walk = player->GetWalkSpeed_guess();
                }
                unsigned char stand = player->StandState;
                anim = stand == 'o' ? 0x16 : 0x11;
                if (p->SpeedZ >= actor->fbc) {
                    anim = 0x13;
                    a = 1;
                    speed = 1.0f;
                } else if (p->SpeedZ < -3.2f) {
                    anim = 0x15;
                    c = 1;
                } else if (walk < p->SpeedRun) {
                    if (stand != 'o') {
                        anim = 0x12;
                    }
                } else if (p->SpeedZ != 0.0f) {
                    c = 0;
                }
            } else if (actor->anim != 0x19 && actor->anim != 0x25) {
                float walk;
                if (player->IsRunning_guess()) {
                    float run = player->RunSpeed;
                    walk = player->GetWalkSpeed_guess() + (run - player->GetWalkSpeed_guess()) * 0.5f;
                } else {
                    walk = player->GetWalkSpeed_guess();
                }
                anim = 0x11;
                if (walk < p->SpeedRun) {
                    anim = 0x12;
                }
            }
            if (p->SpeedRun < 0.0f && actor->anim != 0x25 && actor->anim != 0x19) {
                b = 1;
            }
            if (anim != 0xff) {
                SetAnim_guess(anim, a, b, speed, c);
            }
            }
        }
    }
    Finish_guess();
}

// EXTERNAL: TITANIUM 0x0040CBB2 RandomRange_guess
int __cdecl RandomRange_guess(int minimum_guess, int maximum_guess);

struct FUN_00450248_outer_guess;

struct FUN_00450248_clock_guess {
    char pad0[0x148];
    unsigned int now;                   // 0x148
};
#define g_display_clock_guess EQ_GLOBAL(FUN_00450248_clock_guess*, 0x00905D24)

struct FUN_00450248_mid_guess {
    char pad0[0x134];
    int current;                        // 0x134
    char pad138[0x15c - 0x138];
    FUN_00450248_outer_guess* other;    // 0x15c
    char pad160[0xf20 - 0x160];
    int f20;                            // 0xf20
    int f24;                            // 0xf24
    int f28;                            // 0xf28
    int f2c;                            // 0xf2c
    char pad30[0xf48 - 0xf30];
    int f48;                            // 0xf48
    int f4c;                            // 0xf4c
    int f50;                            // 0xf50
    char pad54[0xf58 - 0xf54];
    int f58;                            // 0xf58
    int f5c;                            // 0xf5c
    int f60;                            // 0xf60
    int f64;                            // 0xf64
    int f68;                            // 0xf68
    char pad6c[0xf70 - 0xf6c];
    int f70;                            // 0xf70
    unsigned int f74;                   // 0xf74
    int primaryItemType_0f78_guess;                            // 0xf78
    int secondaryItemType_0f7c_guess;                            // 0xf7c
};

struct FUN_00450248_outer_guess {
    char pad0[0x1a8];
    FUN_00450248_mid_guess* mid;        // 0x1a8
    char pad1ac[0x1b1 - 0x1ac];
    char flag1b1;                       // 0x1b1
    char pad1b2[0x244 - 0x1b2];
    char type_0244_guess;                       // 0x244
    char pad245[0x251 - 0x245];
    char tag251;                        // 0x251
    char pad252[0x260 - 0x252];
    int race_0260_guess;                       // 0x260
    char pad264[0x270 - 0x264];
    int bodyType_0270_guess;                           // 0x270
    int hpCurrent_0274_guess;                           // 0x274

    // EXTERNAL: TITANIUM 0x00479F75 FUN_00450248_outer_guess::Play_guess
    void Play_guess(int value);
    // EXTERNAL: TITANIUM 0x00479E02 FUN_00450248_outer_guess::Check_guess
    int Check_guess(int value);
    // EXTERNAL: TITANIUM 0x00479EE8 FUN_00450248_outer_guess::Notify_guess
    void Notify_guess(int value);
};

struct FUN_00450248_owner_guess {
    // EXTERNAL: TITANIUM 0x0044A516 FUN_00450248_owner_guess::Status_guess
    char Status_guess(int value);
};
#define g_statusOwner_guess EQ_GLOBAL(FUN_00450248_owner_guess*, 0x00851390)
#define g_player_guess EQ_GLOBAL(FUN_00450248_outer_guess*, 0x00905CE4)

struct OldPlayerAnimationSoundView_guess {
    char pad0[4];
    FUN_00450248_outer_guess* outer;    // 0x4

    void PlayAnimationSound_guess(int id, int arg2_guess, int arg3_guess);
};

// Plays the sound for row `id` as it starts. Footsteps (random of four for the local player), duck-walk and
// climb sounds come at most every 500 ms (swim 550, tread 600); for other spawns footsteps are not gated
// and swim/tread are gated only under Check_guess(-1). The race's slots at +0xF20.. give idle, jump, damage
// and attack shouts (1 in 3 for others). Sounds below 32 are dropped; for the local player and the player
// at its actor +0x15C, 0x44A516 may veto them. Race 127 is silent.
// FUNCTION: TITANIUM 0x00450248
// @early-stop: budget, structural ndiff=236
void OldPlayerAnimationSoundView_guess::PlayAnimationSound_guess(int id, int arg2_guess, int arg3_guess)
{
    int sound = 0;
    if (id != outer->mid->current) {
        outer->mid->f70 = 0;
        outer->Play_guess(outer->mid->f20);
    }
    if (id == 0x20 || id == 0x47) {
        return;
    }
    if (outer->race_0260_guess == 0x7f) {
        return;
    }

    // Rate limits, local player only: each kind of step sound waits its interval since the last one
    // (+0xF74).
    bool ok = true;
    if (outer == g_player_guess) {
        if (id == 0x11 || id == 0x12 || id == 0x16 || id == 0x17) {
            if (g_display_clock_guess->now - outer->mid->f74 > 500 && outer->flag1b1 == 0) {
                outer->mid->f74 = g_display_clock_guess->now;
            } else {
                ok = false;
            }
        } else if (id == 0x25) {
            if (g_display_clock_guess->now - outer->mid->f74 > 0x226) {
                outer->mid->f74 = g_display_clock_guess->now;
            } else {
                ok = false;
            }
        } else if (id == 0x19) {
            if (g_display_clock_guess->now - outer->mid->f74 > 0x258) {
                outer->mid->f74 = g_display_clock_guess->now;
            } else {
                ok = false;
            }
        }
    } else {
        if (id == 0x16 || id == 0x17) {
            if (g_display_clock_guess->now - outer->mid->f74 > 500 && outer->flag1b1 == 0) {
                outer->mid->f74 = g_display_clock_guess->now;
            } else {
                ok = false;
            }
        } else if (id == 0x25) {
            if (outer->Check_guess(-1)) {
                if (g_display_clock_guess->now - outer->mid->f74 > 0x226) {
                    outer->mid->f74 = g_display_clock_guess->now;
                } else {
                    ok = false;
                }
            } else if (outer->mid->f5c == 0) {
                ok = false;
            }
        } else if (id == 0x19) {
            if (outer->Check_guess(-1)) {
                if (g_display_clock_guess->now - outer->mid->f74 > 0x258) {
                    outer->mid->f74 = g_display_clock_guess->now;
                } else {
                    ok = false;
                }
            } else if (outer->mid->f5c == 0) {
                ok = false;
            }
        }
    }

    if (ok) {
        // Footsteps: the local player gets one of four at random, other spawns their race's own step sound
        // (+0xF60, +0xF5C).
        if (id == 0x12) {
            if (outer->flag1b1 == 0) {
                if (outer == g_player_guess) {
                    sound = 0x5f;
                } else {
                    sound = outer->mid->f60;
                }
                if (sound == 0x5f) {
                    switch (RandomRange_guess(0, 3)) {
                    case 0: sound = 0x5f; break;
                    case 1: sound = 0x5e; break;
                    case 2: sound = 0x99; break;
                    case 3: sound = 0x9a; break;
                    }
                } else if (sound != 0) {
                    outer->Play_guess(sound);
                    sound = 0;
                }
            }
        } else if (id == 0x11) {
            if (outer->flag1b1 == 0) {
                if (outer == g_player_guess) {
                    sound = 0x5d;
                } else {
                    sound = outer->mid->f5c;
                }
                if (sound == 0x5d) {
                    switch (RandomRange_guess(0, 3)) {
                    case 0: sound = 0x5d; break;
                    case 1: sound = 0x5c; break;
                    case 2: sound = 0x97; break;
                    case 3: sound = 0x98; break;
                    }
                } else if (sound != 0) {
                    outer->Play_guess(sound);
                    sound = 0;
                }
            }
        } else if (id == 0x19) {
            if (outer->Check_guess(-1)) {
                sound = 0x65;
            }
        } else if (id == 0x25) {
            if (outer->Check_guess(-1)) {
                sound = 0x66;
            }
        } else if (id == 0x1a) {
            if (RandomRange_guess(1, 100) < 0x32) {
                outer->Play_guess(outer->mid->f24);
            } else {
                outer->Play_guess(outer->mid->f28);
            }
        } else if (id == 0x13 || id == 0x14) {
            sound = outer->mid->f2c;
        } else if (id == 0x16) {
            if (outer->flag1b1 == 0) {
                sound = outer->mid->f64;
            }
        } else if (id == 0x17) {
            if (outer->flag1b1 == 0) {
                if (outer->mid->f68 == 0) {
                    sound = 0x60;
                    outer->mid->f68 = 1;
                } else {
                    outer->mid->f68 = 0;
                    sound = 0x61;
                }
            }
        } else if (id == 0x21) {
            if (outer->flag1b1 == 0) {
                sound = 0x62;
                if (outer->race_0260_guess == 0x3c) {
                    sound = 0x1d0;
                }
            }
        } else if (id == 0x24) {
            if (outer->flag1b1 == 0) {
                sound = 0x62;
            }
        } else if (id == 0xf) {
            sound = outer->mid->f48;
        } else if (id == 0x10) {
            if (outer->type_0244_guess == 0) {
                if (outer->tag251 == 'x' || outer->hpCurrent_0274_guess > 0) {
                    sound = outer->mid->f4c;
                }
            } else if (outer->bodyType_0270_guess < 0x41) {
                sound = outer->mid->f4c;
            }
        } else if (id == 1) {
            sound = 0x7e;
        } else if (id == 2) {
            sound = 0x7a;
            if (outer->mid->primaryItemType_0f78_guess == 5) {
                sound = 0x96;
            }
        } else if (id == 3) {
            sound = 0x77;
            if (outer->mid->primaryItemType_0f78_guess == 5) {
                sound = 0x96;
            }
        } else if (id == 4) {
            sound = 0x79;
        } else if (id == 5) {
            if (RandomRange_guess(1, 3) == 1 || outer == g_player_guess) {
                sound = outer->mid->f50;
            }
            int state = outer->mid->primaryItemType_0f78_guess;
            if (state == 5) {
                sound = 0x96;
            } else if (state != 0) {
                outer->Notify_guess(0x76);
                if (sound == 0x82) {
                    sound = 0;
                }
            } else if (sound == 0) {
                switch (RandomRange_guess(1, 5)) {
                case 1: sound = 0x7e; break;
                case 2: sound = 0x7a; break;
                case 3: sound = 0x82; break;
                case 4: sound = 0x81; break;
                case 5: sound = 0x76; break;
                }
            }
            if (outer->race_0260_guess == 0x31 || outer->race_0260_guess == 0x7a) {
                sound = outer->mid->f50;
            }
        } else if (id == 6) {
            int state = outer->mid->secondaryItemType_0f7c_guess;
            if (state == 5) {
                sound = 0x96;
            } else if (state == 3) {
                sound = 0x7c;
            } else {
                sound = state != 0 ? 0x76 : 0x81;
            }
        } else if (id == 7) {
            sound = outer->mid->secondaryItemType_0f7c_guess == 3 ? 0x7c : 0x77;
        } else if (id == 8) {
            if (RandomRange_guess(1, 3) == 1 || outer == g_player_guess) {
                sound = outer->mid->f50;
            }
            int state = outer->mid->primaryItemType_0f78_guess;
            if (state == 5) {
                sound = 0x96;
            } else if (state != 0) {
                outer->Notify_guess(0x76);
                if (sound == 0x82) {
                    sound = 0;
                }
            } else if (sound == 0) {
                switch (RandomRange_guess(1, 5)) {
                case 1: sound = 0x7e; break;
                case 2: sound = 0x7a; break;
                case 3: sound = 0x82; break;
                case 4: sound = 0x81; break;
                case 5: sound = 0x76; break;
                }
            }
        } else if (id == 9) {
            sound = 0x74;
        } else if (id == 10) {
            if (RandomRange_guess(1, 3) == 1 || outer == g_player_guess) {
                sound = outer->mid->f50;
            }
            if (outer->mid->primaryItemType_0f78_guess != 0) {
                outer->Notify_guess(0x76);
                if (sound == 0x82) {
                    sound = 0;
                }
            } else {
                switch (RandomRange_guess(1, 5)) {
                case 1: sound = 0x7e; break;
                case 2: sound = 0x7a; break;
                case 3: sound = 0x82; break;
                case 4: sound = 0x81; break;
                case 5: sound = 0x76; break;
                }
            }
        } else if (id == 0xb) {
            sound = 0x80;
        } else if (id == 0x2a || id == 0x2b || id == 0x2c) {
            sound = outer->mid->f58;
        } else if (id == 0x2d) {
            sound = 0x80;
        } else if (id == 0x2e) {
            sound = 0x82;
        } else if (id == 0x2f) {
            sound = 0x82;
        }
    }

    // Ids below 32 are no sound; the local player's (and the +0x15C spawn's) go through 0x0044A516 first.
    if (sound < 0x20) {
        sound = 0;
    }
    if (outer == g_player_guess || outer == g_player_guess->mid->other) {
        if (sound == 0) {
            return;
        }
        if (g_statusOwner_guess->Status_guess(sound)) {
            sound = 0;
        }
    }
    if (sound != 0) {
        outer->Notify_guess(sound);
    }
}

struct FUN_00450148_obj_guess {
    char pad0[0x252];
    unsigned char tag252;               // 0x252
    char pad253[0x260 - 0x253];
    int tag260;                         // 0x260
};

struct OldPlayerAnimationAttackView_guess {
    char pad0[4];
    FUN_00450148_obj_guess* obj;        // 0x4

    char GetAttackAnimation_guess(int a, int b, int c, float* out, char flag);
};

// Attack row for attack skill `a`: 1H blunt/slash and Frenzy 5, 2H blunt 4, 2H slash 3, Bash 7, Hand to
// Hand 8, Kick/Intimidation 1, Round Kick 11, Flying Kick 45, Eagle Strike 47, Dragon Punch/Tiger Claw
// 46; else piercing 2 (4 for `b` 35, probably the 2H piercing item type). Iksar (race 128) Bash uses 6.
// FUNCTION: TITANIUM 0x00450148
char OldPlayerAnimationAttackView_guess::GetAttackAnimation_guess(int a, int b, int c, float* out, char flag)
{
    int r;
    *out = 1.0f;
    if (b == 9) {
        r = 0x2c;
    } else if (c == 0) {
        switch (a) {
        case 0:
        case 1:
        case 0x4a:
            r = 5;
            break;
        case 2:
            r = 4;
            break;
        case 3:
            r = 3;
            break;
        case 10:
            r = 7;
            break;
        case 0x15:
        case 0x34:
            r = 0x2e;
            break;
        case 0x17:
            r = 0x2f;
            break;
        case 0x1a:
            r = 0x2d;
            break;
        case 0x1c:
            r = 8;
            break;
        case 0x1e:
        case 0x47:
            r = 1;
            break;
        case 0x26:
            r = 0xb;
            break;
        default:
            r = (b == 0x23) * 2 + 2;
        }
    } else {
        switch (b) {
        case 0x1b:
            r = 9;
            break;
        case 0x1c:
            r = 10;
            break;
        default:
            r = 5;
        }
    }
    if (a == 0x47 && obj->tag252 == 7) {
        r = 0xb;
    } else if (flag == 0xe) {
        r = 6;
    }
    if (obj->tag260 == 0x80) {
        if (r == 7) {
            r = 6;
        } else if (r == 0x2e && a == 0x15) {
            r = 7;
        }
    }
    return (char)r;
}

// True for the stand poses 32 (P01), 38 (P07, sitting), 71 (P08) and 74 (P09).
// FUNCTION: TITANIUM 0x004500D0
char __stdcall IsStandAnimation_guess(int value)
{
    if (value == 0x20 || value == 0x26 || value == 0x47 || value == 0x4a) {
        return 1;
    }
    return 0;
}

// True for the idles 26 (O01), 72 (O02) and 73 (O03).
// FUNCTION: TITANIUM 0x004500F1
char __stdcall IsIdleAnimation_guess(int param_1)
{
    if (param_1 == 0x1a || (param_1 > 0x47 && param_1 <= 0x49)) {
        return 1;
    }
    return 0;
}

struct OldPlayerAnimationFilterView_guess {
    char IsAllowed_guess(int value);
};

// Rows after which a stand or idle uses the normal rows 32/26, not 71/72: stand, 1-16, 42-47, walk (17),
// turn (34), 75 and 254.
// FUNCTION: TITANIUM 0x0045010D
char OldPlayerAnimationFilterView_guess::IsAllowed_guess(int value)
{
    if (value == 0x20) {
        return 1;
    } else if (value >= 1 && value <= 0x10) {
        return 1;
    } else if (value >= 0x2a && value <= 0x2f) {
        return 1;
    } else if (value == 0xfe) {
        return 1;
    } else if (value == 0x11) {
        return 1;
    } else if (value == 0x4b) {
        return 1;
    } else {
        return (char)(value == 0x22);
    }
}

struct FUN_00450c2f_model_guess {
    virtual void S00() = 0; virtual void S04() = 0; virtual void S08() = 0; virtual void S0C() = 0;
    virtual void S10() = 0; virtual void S14() = 0; virtual void S18() = 0; virtual void S1C() = 0;
    virtual void S20() = 0; virtual void S24() = 0; virtual void S28() = 0; virtual void S2C() = 0;
    virtual void S30() = 0; virtual void S34() = 0; virtual void S38() = 0; virtual void S3C() = 0;
    virtual void S40() = 0; virtual void S44() = 0; virtual void S48() = 0; virtual void S4C() = 0;
    virtual void S50() = 0; virtual void S54() = 0; virtual void S58() = 0; virtual void S5C() = 0;
    virtual void S60() = 0;
    virtual float GetHeight_guess() = 0;                                   // 0x64
    virtual void S68() = 0; virtual void S6C() = 0;
    virtual void SetOffset_guess(float value) = 0;                          // 0x70
    virtual void S74() = 0; virtual void S78() = 0; virtual void S7C() = 0;
    virtual void S80() = 0; virtual void S84() = 0; virtual void S88() = 0; virtual void S8C() = 0;
    virtual void S90() = 0; virtual void S94() = 0; virtual void S98() = 0; virtual void S9C() = 0;
    virtual void SA0() = 0; virtual void SA4() = 0; virtual void SA8() = 0; virtual void SAC() = 0;
    virtual void SB0() = 0; virtual void SB4() = 0; virtual void SB8() = 0; virtual void SBC() = 0;
    virtual void SC0() = 0; virtual void SC4() = 0; virtual void SC8() = 0; virtual void SCC() = 0;
    virtual void SD0() = 0; virtual void SD4() = 0; virtual void SD8() = 0; virtual void SDC() = 0;
    virtual void SE0() = 0; virtual void SE4() = 0; virtual void SE8() = 0; virtual void SEC() = 0;
    virtual void SF0() = 0; virtual void SF4() = 0; virtual void SF8() = 0; virtual void SFC() = 0;
    virtual void S100() = 0; virtual void S104() = 0; virtual void S108() = 0; virtual void S10C() = 0;
    virtual void S110() = 0; virtual void S114() = 0; virtual void S118() = 0; virtual void S11C() = 0;
    virtual void S120() = 0; virtual void S124() = 0; virtual void S128() = 0; virtual void S12C() = 0;
    virtual void S130() = 0; virtual void S134() = 0; virtual void S138() = 0; virtual void S13C() = 0;
    virtual void S140() = 0; virtual void S144() = 0; virtual void S148() = 0; virtual void S14C() = 0;
    virtual void S150() = 0; virtual void S154() = 0; virtual void S158() = 0; virtual void S15C() = 0;
    virtual void S160() = 0; virtual void S164() = 0; virtual void S168() = 0; virtual void S16C() = 0;
    virtual void S170() = 0; virtual void S174() = 0;
    virtual void PlaySound_guess(int channel, const char* name, const char* code, float speed, char loop,
                                 char mode, float blend) = 0;               // 0x178
    virtual void S17C() = 0;
    virtual void S180() = 0; virtual void S184() = 0; virtual void S188() = 0; virtual void S18C() = 0;
    virtual void S190() = 0; virtual void S194() = 0; virtual void S198() = 0; virtual void S19C() = 0;
    virtual void SetChannel_guess(int channel, int value) = 0;              // 0x1a0
};

struct FUN_00450c2f_entry_guess {
    int id;
    int pad4[3];
};

struct FUN_00450c2f_table_guess {
    char pad0[0x2c];
    FUN_00450c2f_entry_guess** rows;    // 0x2c, one per animation
    char pad30[4];
    unsigned char multi;                // 0x34
};

struct FUN_00450c2f_player_guess;

struct FUN_00450c2f_actor_guess {
    FUN_00450c2f_model_guess* model;    // 0x0
    char pad4[0xad - 4];
    unsigned char fad;                  // 0xad
    char padae[0x12c - 0xae];
    FUN_00450c2f_table_guess* table;    // 0x12c
    char pad130[4];
    int anim;                           // 0x134
    int next;                           // 0x138
    char pad13c[0x148 - 0x13c];
    int slot;                           // 0x148
    char pad14c[0x158 - 0x14c];
    int f158;                           // 0x158
    FUN_00450c2f_player_guess* rider;   // 0x15c
    FUN_00450c2f_player_guess* mount;   // 0x160
};

struct FUN_00450c2f_player_guess {
    char pad0[0x48];
    float SpeedRun;                     // 0x48
    char pad4c[0x5c - 0x4c];
    float CameraAngle;                  // 0x5c
    char pad60[0x1a8 - 0x60];
    FUN_00450c2f_actor_guess* actor;    // 0x1a8
    char pad1ac[0x230 - 0x1ac];
    float RunSpeed;                     // 0x230
    char pad234[0x24e - 0x234];
    unsigned char Gender;               // 0x24e
    char pad24f[0x251 - 0x24f];
    unsigned char StandState;           // 0x251
    unsigned char Class;                // 0x252
    char pad253[0x260 - 0x253];
    int Race;                           // 0x260
    char pad264[0x270 - 0x264];
    int BodyType;                       // 0x270
    int HPCurrent;                      // 0x274

    // EXTERNAL: TITANIUM 0x0047BFD0 FUN_00450c2f_player_guess::IsRunning_guess
    bool IsRunning_guess();
    // EXTERNAL: TITANIUM 0x0047C007 FUN_00450c2f_player_guess::HasPlayerState_guess
    bool HasPlayerState_guess(int skill);
};

struct FUN_00450c2f_sink_guess {
    virtual void SetSpeed_guess(float speed, char loop) = 0;               // 0x0
    virtual void S04() = 0;
    virtual void PlayBlend_guess(int id, float speed, char loop, char mode, float blend) = 0;  // 0x8
    virtual void Play_guess(int id, float speed, char loop, char mode) = 0;  // 0xc
    virtual void S10() = 0; virtual void S14() = 0; virtual void S18() = 0;
    virtual char IsPlaying_guess() = 0;                                     // 0x1c
    virtual int Current_guess() = 0;                                        // 0x20
    virtual int Position_guess() = 0;                                       // 0x24
    virtual void UpdateMovementAnimation_guess() = 0;                                        // 0x28
    virtual void Link_guess(FUN_00450c2f_sink_guess* other) = 0;            // 0x2c
};

struct FUN_00450c2f_world_guess {
    virtual void S00() = 0; virtual void S04() = 0; virtual void S08() = 0; virtual void S0C() = 0;
    virtual void S10() = 0; virtual void S14() = 0; virtual void S18() = 0; virtual void S1C() = 0;
    virtual void S20() = 0; virtual void S24() = 0; virtual void S28() = 0; virtual void S2C() = 0;
    virtual void S30() = 0; virtual void S34() = 0;
    virtual void Touch_guess() = 0;                                         // 0x38
};

struct FUN_00450c2f_name_guess {
    char text[0x14];
};

struct FUN_00450c2f_code_guess {
    char text[5];
};

struct OldPlayerAnimationSetView_guess {
    virtual void S00() = 0; virtual void S04() = 0; virtual void S08() = 0; virtual void S0C() = 0;
    virtual void S10() = 0; virtual void S14() = 0; virtual void S18() = 0; virtual void S1C() = 0;
    virtual void S20() = 0; virtual void S24() = 0;
    virtual unsigned short Fallback_guess(int anim, unsigned char* slot) = 0;  // 0x28
    virtual void S2C() = 0; virtual void S30() = 0; virtual void S34() = 0;
    virtual char IsSpecial_guess(int anim) = 0;                             // 0x38
    virtual char HasSound_guess() = 0;                                      // 0x3c

    FUN_00450c2f_player_guess* player;  // 0x4
    char pad8[4];
    FUN_00450c2f_sink_guess* sinkB;     // 0xc
    FUN_00450c2f_sink_guess* sinkA;     // 0x10

    char CanInterrupt_guess(int requested, int anim, unsigned char extra);
    char SetAnim_guess(unsigned short anim, char restart, char loop, float speed, int extra,
                       unsigned char slot);
};

#define g_world_guess EQ_GLOBAL(FUN_00450c2f_world_guess*, 0x0099E368)
#define g_animTrackTags_guess EQ_ARRAY(FUN_00450c2f_name_guess, 0x008FFBC8)
#define g_animNames_guess EQ_ARRAY(FUN_00450c2f_code_guess, 0x009001F8)
#define g_animTimes_guess EQ_ARRAY(int, 0x00693498)
#define g_timeBase_guess EQ_GLOBAL(int, 0x0066D248)

// True when `requested` may cut into the playing row. `extra` 2+ forces it, and 1 does for idles and
// the mounted 74/78. Otherwise rows 16, 33, 44 (and 15 for class 62, LDoN treasure) always may, 74/78
// never, and the rest only with `extra` 1, over a different row that may be cut off (0x900388).
// FUNCTION: TITANIUM 0x00450A17
// @early-stop: budget, structural ndiff=32
char OldPlayerAnimationSetView_guess::CanInterrupt_guess(int requested, int anim, unsigned char extra)
{
    char result;
    if (extra == 0 || (extra < 2 && requested != 0x4a && requested != 0x4e && IsIdleAnimation_guess(requested) == 0)) {
        bool allowed = IsSpecial_guess(requested) && IsIdleAnimation_guess(player->actor->anim);
        int cur = player->actor->anim;
        if (requested == 0xf && player->Class == '>') {
            result = 1;
        } else if (requested == 0x4a || requested == 0x4e) {
            result = 0;
        } else if (requested == 0x10 || requested == 0x21 || requested == 0x2c) {
            result = 1;
        } else if (allowed) {
            result = 0;
        } else if (extra == 0 && cur < 0x4f) {
            result = 0;
        } else if (cur == anim) {
            result = 0;
        } else if (cur < 0x4f && EQ_ARRAY(unsigned char, 0x00900388)[cur] == 0) {
            result = 0;
        } else {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}

struct FUN_0045099f_entry_guess {
    int field0;
    int field4;
    int field8;
    int fieldC;
};

struct FUN_0045099f_table_guess {
    char pad0[0x2c];
    FUN_0045099f_entry_guess** entries; // 0x2c
    char pad30[4];
    unsigned char enabled;              // 0x34
};

struct FUN_0045099f_mid_guess {
    char pad0[0x12c];
    FUN_0045099f_table_guess* table;    // 0x12c
};

struct FUN_0045099f_outer_guess {
    char pad0[0x1a8];
    FUN_0045099f_mid_guess* mid;        // 0x1a8
};

struct OldPlayerAnimationCheckView_guess {
    char pad0[4];
    FUN_0045099f_outer_guess* outer;    // 0x4

    char FindVariantSlot_guess(int index, char mode);
};

struct FUN_00450aed_state_guess {
    char pad0[0x252];
    char field252_guess;            // 0x252
    char pad253[0x260 - 0x253];
    int field260_guess;             // 0x260
};

struct OldPlayerAnimationMapView_guess {
    char pad0[4];
    FUN_00450aed_state_guess* state_guess; // 0x4

    int GetFallbackAnimation_guess(int code_guess, char* text_guess);
};

// Substitute when the model has no track for row `code`: another variant slot first, else a stand-in
// (attacks 5, kicks 1, walk and run swapped, tread to swim, swim to walk or run, idles to stand). Last
// resort stand (32), or 43 when 0x92446C is 1. SetAnim_guess reaches it through the Fallback_guess vtable
// slot (+0x28).
// FUNCTION: TITANIUM 0x00450AED
// @early-stop: budget, structural ndiff=119
int OldPlayerAnimationMapView_guess::GetFallbackAnimation_guess(int input_code_guess, char* input_text_guess)
{
    char* text_guess = input_text_guess;
    int code_guess = input_code_guess;
    char first_guess = *text_guess;
    char checked_guess = ((OldPlayerAnimationCheckView_guess*)this)->FindVariantSlot_guess(code_guess, first_guess);
    if (checked_guess != first_guess) {
        *text_guess = checked_guess;
        return code_guess;
    }
    if (code_guess > 0x15) {
        if (code_guess < 0x2d) {
            if (code_guess == 0x2c) {
                return 0x2b;
            }
            if (code_guess == 0x19) {
                return 0x25;
            }
            if (code_guess == 0x1a) {
                return 0x20;
            }
            if (code_guess == 0x25) {
                int value_guess = state_guess->field260_guess;
                if (value_guess == 0x48 || value_guess == 0x194 || value_guess == 0x2a) {
                    return 0x12;
                }
                return 0x11;
            }
            if (code_guess == 0x27) {
                return 0x28;
            }
            if (code_guess == 0x2a) {
                return 0x2b;
            }
        } else {
            if (code_guess == 0x48) {
                return 0x1a;
            }
            if (code_guess == 0x4b) {
                return 0x11;
            }
            if (code_guess == 0x4c) {
                return 0x12;
            }
            if (code_guess == 0x4e) {
                return 0x4a;
            }
        }
    } else {
        if (code_guess == 0x15) {
            return 0x25;
        }
        switch (code_guess) {
        case 1: case 2: case 3: case 4: case 6: case 7: case 8: case 9:
            return 5;
        case 0xa:
            return 0x25;
        case 0xb:
            return 1;
        case 0xc: case 0xe:
            return 0xd;
        case 0xd:
            return 0xc;
        case 0xf:
            return ((state_guess->field252_guess != '>') - 1 & 3) + 0xd;
        case 0x11:
            return 0x12;
        case 0x12:
            return 0x11;
        }
    }
    if (EQ_GLOBAL(int, 0x0092446C) == 1 && code_guess != 0x2b) {
        return 0x2b;
    }
    return 0x20;
}

// Starts row `anim`, variant `slot` (0-7 on variant models). Substitutes sit poses, mounted rows 74/78
// and missing tracks; races 475+ have none, and the dead or feigning only fall. Then the cut-in test
// (Check_guess), speed rules, both channels (or the upper one alone while legs move) and the row's
// sound (OldPlayerAnimationSoundView_guess). 1 when it played.
// FUNCTION: TITANIUM 0x00450C2F
// @early-stop: budget, structural ndiff=502
char OldPlayerAnimationSetView_guess::SetAnim_guess(unsigned short anim, char restart, char loop, float speed, int extra,
                                       unsigned char slot)
{
    bool reuse = false;
    unsigned short requested = anim;
    // Animation ids run 0-0x4E (names at g_animTrackTags_guess). LDoN chests use 0xF for 0x10 when they have
    // the skill at 0x00647CA8; a bard without the skill at 0x00647CB8 gets only the sound of 0x27-0x29.
    if (anim >= 0x4f) {
        return 0;
    }
    if (player->Class == Class_LDoNTreasure && anim == 0x10 && player->HasPlayerState_guess(EQ_GLOBAL(int, 0x00647CA8))) {
        anim = 0xf;
    }
    if (player->Class == Class_Bard && (anim == 0x27 || anim == 0x28 || anim == 0x29)
        && !player->HasPlayerState_guess(EQ_GLOBAL(int, 0x00647CB8))) {
        ((OldPlayerAnimationSoundView_guess*)this)->PlayAnimationSound_guess(anim, 0, 0);
        return 0;
    }
    if (player->Race >= 0x1db) {
        return 0;
    }
    FUN_00450c2f_actor_guess* actor = player->actor;
    if (actor == 0) {
        return 0;
    }
    int hp = player->HPCurrent;
    // Below 1 HP or in stand states 's' / 'x' (0x73 dead, 0x78) only 0x10 plays (0xF for chests).
    if ((hp < 1 || player->StandState == 's' || player->StandState == 'x') && anim != 0x10
        && (anim != 0xf || player->Class != Class_LDoNTreasure) && hp < 10) {
        return 0;
    }
    FUN_00450c2f_table_guess* table = actor->table;
    if (table == 0 || actor->model == 0) {
        return 0;
    }
    int slots;
    // Models with variant tables (`multi`) have 8 slots per animation and swap 0x32 with 0x3E; others have
    // one.
    if (table->multi != 0) {
        slots = 8;
        if (anim == 0x32) {
            anim = 0x3e;
        } else if (anim == 0x3e) {
            anim = 0x32;
        }
    } else {
        slots = 1;
    }
    if (player->IsRunning_guess()) {
        player->CameraAngle = 64.0f;
        if (player->actor->model != 0 && player->actor->model->GetHeight_guess() > 256.0f
            && 512.0f - player->actor->model->GetHeight_guess() > 25.0f) {
            player->actor->model->SetOffset_guess(-25.0f);
            if (player->actor->mount != 0) {
                player->actor->mount->actor->model->SetOffset_guess(-25.0f);
            }
        }
        player->StandState = 100;
    }
    int previous;
    // A mount moves with its rider: 0x4E at full run speed, 0x4A below, replacing the rider-driven idle and
    // movement ids.
    if (player->actor->rider == 0) {
        previous = anim;
    } else {
        FUN_00450c2f_player_guess* rider = player->actor->rider;
        if (rider->SpeedRun >= rider->RunSpeed) {
            if (IsSpecial_guess(anim) || IsIdleAnimation_guess(anim)) {
                anim = 0x4e;
                restart = 0;
            }
            previous = 0x4e;
        } else {
            if (IsSpecial_guess(anim)
                || (IsIdleAnimation_guess(anim) && player->actor->rider->SpeedRun != 0.0f)) {
                anim = 0x4a;
                restart = 0;
            }
            previous = 0x4a;
        }
    }
    int current = anim;
    if (slot >= slots) {
        slot = 0;
    }
    if (player->actor->slot >= slots) {
        player->actor->slot = 0;
    }
    unsigned char prevSlot = slot;
    unsigned char curSlot = slot;
    FUN_00450c2f_player_guess* self = player;
    // Sitting ('n'): 0x20/0x47 become 0x26 and 0x1A/0x48 become 0x49 (our own player only with 0x00850CCC
    // set); race 60 and 0x27-0x29 play nothing.
    if (self->StandState == 'n') {
        switch (current) {
        case 0x20:
        case 0x47:
            if (self->Race == 0x3c) {
                return 0;
            }
            anim = 0x26;
            if (self == EQ_GLOBAL(FUN_00450c2f_player_guess*, 0x00905CE4) && EQ_GLOBAL(int, 0x00850CCC) == 0) {
                return 0;
            }
            break;
        case 0x1a:
        case 0x48:
            if (self->Race == 0x3c) {
                return 0;
            }
            anim = 0x49;
            if (self == EQ_GLOBAL(FUN_00450c2f_player_guess*, 0x00905CE4) && EQ_GLOBAL(int, 0x00850CCC) == 0) {
                return 0;
            }
            break;
        case 0x27:
        case 0x28:
        case 0x29:
            return 0;
        }
    }
    if (self->SpeedRun != 0.0f && self->BodyType == 1 && EQ_ARRAY(unsigned char, 0x009003D8)[anim] != 0) {
        previous = 0;
    }
    FUN_00450c2f_entry_guess* entries = table->rows[anim];
    if (entries == 0 || entries[slot].id == 0) {
        if (anim == 0x26 || anim == 0x49) {
            return 0;
        }
        anim = Fallback_guess(anim, &slot);
        prevSlot = slot;
        curSlot = slot;
    }
    entries = table->rows[anim];
    if (entries == 0 || entries[slot].id == 0) {
        anim = 0x20;
    }
    if (anim == 0x20) {
        FUN_00450c2f_actor_guess* act = player->actor;
        if (act->next == 0x20) {
            speed = 1.0f;
            restart = 0;
            if (!((OldPlayerAnimationFilterView_guess*)this)->IsAllowed_guess(act->anim)) {
                anim = 0x47;
            }
        } else {
            anim = (unsigned short)act->next;
            char allowed = ((OldPlayerAnimationFilterView_guess*)this)->IsAllowed_guess(act->anim);
            speed = 1.0f;
            restart = 1;
            act->next = allowed ? 0x20 : 0x47;
        }
    } else if (anim == 0x1a && !((OldPlayerAnimationFilterView_guess*)this)->IsAllowed_guess(player->actor->anim)) {
        anim = 0x48;
        entries = table->rows[0x48];
        if (entries == 0 || entries[slot].id == 0) {
            anim = Fallback_guess(0x48, &slot);
        }
    }
    entries = table->rows[anim];
    if (entries == 0 || entries[slot].id == 0) {
        entries = table->rows[0x20];
        anim = 0x20;
        if (entries == 0 || entries[slot].id == 0) {
            slot = 0;
            prevSlot = 0;
            curSlot = 0;
            if (table->rows[0x20] == 0) {
                return 0;
            }
        }
    }
    self = player;
    // Idle and movement animations (0x20, 0x22, 0x47, 0x1A, 0x48, 0xC-0xF) need a standing spawn ('d').
    if (self->StandState != 'd'
        && (requested == 0x20 || requested == 0x22 || requested == 0x47 || requested == 0x1a
            || requested == 0x48 || (requested >= 0xc && requested <= 0xf))
        && anim != 0x49 && anim != 0x26) {
        return 0;
    }
    if (self != EQ_GLOBAL(FUN_00450c2f_player_guess*, 0x00905CE4) && self->actor->f158 != 0
        && (anim == 0x15 || anim == 0x19 || anim == 0x25)) {
        return 0;
    }
    if (self->actor->fad >= 5 && anim == 0x24) {
        return 0;
    }
    int chosen = anim;
    if (chosen != current && current == previous) {
        previous = chosen;
        current = chosen;
    }
    if (table->multi == 0 && anim == 0x21 && self->Race == 0x3c) {
        loop = loop == 0;
    }
    int asked = requested;
    // When Check_guess says the new animation may not cut in, it is queued as `next` (one-shots 1-11,
    // 0x2D-0x2F) or the idle 0x20 follows; it only interrupts when both tables at 0x009003D8 / 0x00900428
    // allow it.
    if (!CanInterrupt_guess(asked, chosen, extra)) {
        FUN_00450c2f_sink_guess* sink = sinkA != 0 ? sinkA : sinkB;
        if (sink == 0 || !sink->IsPlaying_guess() || sink->Position_guess() != 0) {
            switch (chosen) {
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
            case 0x2d: case 0x2e: case 0x2f:
                player->actor->next = chosen;
                break;
            case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18:
            case 0x19: case 0x21: case 0x24: case 0x4b: case 0x4c:
                player->actor->next = 0x20;
                break;
            }
            if (player->BodyType != 1 || EQ_ARRAY(unsigned char, 0x00900428)[chosen] == 0) {
                return 0;
            }
            int playing = player->actor->anim;
            if (EQ_ARRAY(unsigned char, 0x009003D8)[playing] == 0) {
                return 0;
            }
            if (anim == 0x20 || anim == 0x4a || anim == 0x4e) {
                if (EQ_ARRAY(unsigned char, 0x00900428)[playing] == 0 || !sinkA->IsPlaying_guess()
                    || sinkA->Position_guess() != 0) {
                    return 0;
                }
            }
            current = 0;
        }
    }
    // Playback speed: running halves it (0x12 at 0.4), some races slow down (42 and 120 neuter, 330), and on
    // variant models special or 'S' animations play at 0.5 / 0.75.
    if (table->multi == 0 || player->Race == Race_Froglok || anim == 0x11 || anim == 0x12) {
        if (player->IsRunning_guess()) {
            if (anim == 0x12) {
                speed = speed * 0.4f;
            } else {
                speed = 0.5f;
            }
        } else {
            int race = player->Race;
            if ((race == 0x2a || race == 0x78) && player->Gender == 2) {
                if (anim != 0x11) {
                    speed = 0.5f;
                }
            } else if (race == Race_Froglok) {
                speed = speed * 0.65f;
            }
        }
    } else if (speed == 1.0f) {
        if (IsSpecial_guess(current) || IsIdleAnimation_guess(current)) {
            speed = 0.5f;
        } else if (g_animTrackTags_guess[current].text[0] == 'S') {
            speed = 0.75f;
        }
    }
    int id = 0;
    entries = table->rows[chosen];
    if (entries != 0) {
        id = entries[slot].id;
    }
    // The same animation already playing in the same slot only changes speed; otherwise both track sinks
    // start the new one, blended when they can be.
    if (player->actor->anim == chosen && restart == 0 && !IsSpecial_guess(asked) && anim != 0x16
        && anim != 0x19) {
        FUN_00450c2f_actor_guess* act = player->actor;
        if (act->slot == slot) {
            reuse = true;
            if (player->BodyType == 1) {
                if (table->rows[act->anim] == 0 || sinkA == 0 || sinkA->Current_guess() != id) {
                    reuse = false;
                }
            }
        }
    }
    speed = AdjustAnimationSpeed_guess(chosen, speed, player->Race, player->Gender, table->multi);
    if (reuse) {
        if (sinkA != 0) {
            sinkA->SetSpeed_guess(speed, loop);
        }
        if (sinkB != 0) {
            sinkB->SetSpeed_guess(speed, loop);
        }
    } else {
        bool blend = true;
        if (sinkA != 0 && sinkA->Current_guess() == 0) {
            blend = false;
        }
        g_world_guess->Touch_guess();
        if (previous == current) {
            if (id != 0) {
            float weight = 0.0f;
            if (blend) {
                if (sinkA != 0) {
                    sinkA->PlayBlend_guess(id, speed, loop, restart ? 1 : 3, 100.0f);
                    sinkA->Link_guess(sinkB);
                }
                if (sinkB != 0) {
                    sinkB->PlayBlend_guess(id, speed, loop, restart ? 1 : 3, 100.0f);
                }
                weight = 100.0f;
            } else {
                if (sinkA != 0) {
                    sinkA->Play_guess(id, speed, loop, restart ? 1 : 3);
                    sinkA->Link_guess(sinkB);
                }
                if (sinkB != 0) {
                    sinkB->Play_guess(id, speed, loop, restart ? 1 : 3);
                }
            }
            if (sinkA != 0) {
                sinkA->UpdateMovementAnimation_guess();
            }
            if (table->multi != 0 && (IsSpecial_guess(current) || IsIdleAnimation_guess(current))) {
                speed = 1.0f;
            }
            char mode = restart ? 1 : 3;
            player->actor->model->PlaySound_guess(3, g_animTrackTags_guess[chosen].text, g_animNames_guess[chosen].text,
                                                 speed, loop, mode, weight);
            char sound = HasSound_guess();
            if (anim == 6) {
                player->actor->model->PlaySound_guess(4, g_animTrackTags_guess[5].text, g_animNames_guess[5].text,
                                                     speed, loop, mode, weight);
                if (sound) {
                    player->actor->model->SetChannel_guess(4, g_animTimes_guess[5] - g_timeBase_guess);
                    player->actor->model->SetChannel_guess(5, g_animTimes_guess[chosen] - g_timeBase_guess);
                }
            } else if (anim != 5) {
                player->actor->model->PlaySound_guess(4, g_animTrackTags_guess[chosen].text,
                                                     g_animNames_guess[chosen].text, speed, loop, mode, weight);
                if (sound) {
                    player->actor->model->SetChannel_guess(3, g_animTimes_guess[chosen] - g_timeBase_guess);
                    player->actor->model->SetChannel_guess(4, g_animTimes_guess[chosen] - g_timeBase_guess);
                    player->actor->model->SetChannel_guess(5, g_animTimes_guess[chosen] - g_timeBase_guess);
                }
            } else if (sound) {
                player->actor->model->SetChannel_guess(3, g_animTimes_guess[5] - g_timeBase_guess);
                player->actor->model->SetChannel_guess(5, g_animTimes_guess[chosen] - g_timeBase_guess);
            }
            }
        } else {
            if (previous != 0) {
                entries = table->rows[previous];
                if (entries != 0) {
                    id = entries[prevSlot].id;
                }
                if (sinkB != 0) {
                    if (blend) {
                        sinkB->PlayBlend_guess(id, speed, loop, restart ? 1 : 3, 100.0f);
                    } else {
                        sinkB->Play_guess(id, speed, loop, restart ? 1 : 3);
                    }
                }
            }
            if (current != 0) {
                entries = table->rows[current];
                if (entries != 0) {
                    id = entries[curSlot].id;
                }
                float weight = 0.0f;
                if (sinkA != 0) {
                    if (blend) {
                        sinkA->PlayBlend_guess(id, speed, loop, restart ? 1 : 3, 100.0f);
                        weight = 100.0f;
                    } else {
                        sinkA->Play_guess(id, speed, loop, restart ? 1 : 3);
                    }
                }
                char mode = restart ? 1 : 3;
                player->actor->model->PlaySound_guess(3, g_animTrackTags_guess[chosen].text,
                                                     g_animNames_guess[chosen].text, speed, loop, mode, weight);
                if (anim == 6) {
                    player->actor->model->PlaySound_guess(4, g_animTrackTags_guess[5].text, g_animNames_guess[5].text,
                                                         speed, loop, mode, weight);
                } else if (anim != 5) {
                    player->actor->model->PlaySound_guess(4, g_animTrackTags_guess[chosen].text,
                                                         g_animNames_guess[chosen].text, speed, loop, mode, weight);
                }
            }
        }
    }
    ((OldPlayerAnimationSoundView_guess*)this)->PlayAnimationSound_guess(chosen, 0, 0);
    player->actor->anim = chosen;
    player->actor->slot = slot;
    return 1;
}

// Variant slot with a track for row `index`, given wanted slot `mode`: 0 tries 1 and 1 tries 0 (others
// try 1, then 0). Returns `mode` when none fits, 0 on models without variants.
// FUNCTION: TITANIUM 0x0045099F
char OldPlayerAnimationCheckView_guess::FindVariantSlot_guess(int index, char mode)
{
    FUN_0045099f_table_guess* table = outer->mid->table;
    FUN_0045099f_entry_guess* entry;
    if (table->enabled != 0 && (entry = table->entries[index]) != 0) {
        unsigned char slot = (mode == 0) ? 1 : (mode != 1);
        if (entry[slot].field0 != 0) {
            return slot;
        }
        if (mode != 0 && slot != 0 && entry[0].field0 != 0) {
            return 0;
        }
    } else {
        mode = 0;
    }
    return mode;
}

struct PlayerAnimationBaseView_guess {
    void* Release_guess(unsigned char param_1);
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// Scalar deleting destructor of PlayerAnimationBase_guess.
// FUNCTION: TITANIUM 0x004509FB
void* PlayerAnimationBaseView_guess::Release_guess(unsigned char param_1)
{
    void (__fastcall *helper)(unsigned int*) = DestroyAnimationBase_guess;
    helper((unsigned int*)this);
    if ((param_1 & 1) != 0) {
        free(this);
    }
    return this;
}

// TrackSet_guess's constructor (tu_054 declares it so): clears the 8 variant tracks, their counts, the
// 128-byte block and the flag.
// FUNCTION: TITANIUM 0x00451965
TrackSet_guess* TrackSet_guess::Construct_guess()
{
    int remainingTracks = 8;
    TrackSetEntry_guess* track = variantTracks;
    unsigned int* trackCount = variantCounts;
    do {
        int remainingWords = 4;
        unsigned int* word = (unsigned int*)track;
        do {
            *word = 0;
            word = word + 1;
            remainingWords = remainingWords - 1;
        } while (remainingWords != 0);
        *trackCount = 0;
        trackCount = trackCount + 1;
        track = track + 1;
        remainingTracks = remainingTracks - 1;
    } while (remainingTracks != 0);
    memset(bytes, 0, 0x80);
    flag = 0;
    return this;
}

