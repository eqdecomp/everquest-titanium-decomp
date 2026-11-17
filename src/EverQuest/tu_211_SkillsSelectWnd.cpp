// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 211: a hint from compare/tumap.py.
// The end of the game's SIDL control factory (tu_210: one game control type per template class id), then the
// CSkillsSelectWnd constructor (screen "SkillsSelectWindow", vtable 0x65C958). SidlControlFactory_guess is that factory,
// RequestLootSlot_guess a view of the template's class-id list, InvSlotWnd_guess the InvSlotWnd of tu_173.
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x00553959 Noop_guess
void __cdecl Noop_guess();
// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

struct Releasable_guess {
    void* Release_guess(unsigned char flags_guess);
};

struct RequestLootSlot_guess {
    char pad00_guess[4];
    int count_guess;
    char pad08_guess[4];
    unsigned int mask_guess;
    int shift_guess;
    int** chunks_guess;
    int Read_guess();
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

struct Pair16_guess {
    int a_guess;
    int b_guess;
    int c_guess;
    int d_guess;
};

struct Copy16_guess {
    int a_guess;
    int b_guess;
    int c_guess;
    int d_guess;
    // EXTERNAL: TITANIUM 0x004D911A ??0Copy16_guess@@QAE@ABU0@@Z
    Copy16_guess(const Copy16_guess& source_guess);
};

struct Src_guess {
    char pad00_guess[0x24];
    int x24_guess;
    char pad28_guess[0x48 - 0x28];
    Copy16_guess x48_guess;
    char pad58_guess[0x6c - 0x58];
    Pair16_guess x6c_guess;
};

struct InvSlotWnd_guess {
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
    virtual void Slot48_guess(int a_guess, int b_guess);
    char pad04_guess[0x65 - 4];
    unsigned char flags65_guess;
    char pad66_guess[0x15c - 0x66];
    // EXTERNAL: TITANIUM 0x0051B649 InvSlotWnd_guess::InvSlotWnd_guess
    InvSlotWnd_guess(int a_guess, int b_guess, Copy16_guess c_guess, int d0_guess, int d1_guess, int d2_guess, int d3_guess);
};

struct SidlControlFactory_guess {
    InvSlotWnd_guess* CreateInvSlotWnd_guess(int a_guess, Src_guess* s_guess);
    void Dispatch_guess(int a_guess, Src_guess* s_guess);
    // EXTERNAL: TITANIUM 0x00553A19 SidlControlFactory_guess::Case18_guess
    int Case18_guess(int a_guess, Src_guess* s_guess);
    // EXTERNAL: TITANIUM 0x00553AF4 SidlControlFactory_guess::Case19_guess
    int Case19_guess(int a_guess, Src_guess* s_guess);
    // EXTERNAL: TITANIUM 0x00553964 SidlControlFactory_guess::Case1d_guess
    int Case1d_guess(int a_guess, Src_guess* s_guess);
    // EXTERNAL: TITANIUM 0x005B5DC0 SidlControlFactory_guess::Fallback_guess
    void Fallback_guess(int a_guess, Src_guess* s_guess);
};

// Class id 0x1A: a new InvSlotWnd from the template (rect +0x48; background, slot id and icon offsets
// +0x6C-0x78), then vtable slot 48 with (1, 1) as in the other cases, probably Show.
// FUNCTION: TITANIUM 0x00553B98
InvSlotWnd_guess* SidlControlFactory_guess::CreateInvSlotWnd_guess(int a_guess, Src_guess* s_guess) {
    InvSlotWnd_guess* obj_guess = new InvSlotWnd_guess(a_guess, s_guess->x24_guess, s_guess->x48_guess, s_guess->x6c_guess.a_guess, s_guess->x6c_guess.b_guess, s_guess->x6c_guess.c_guess, s_guess->x6c_guess.d_guess);
    if (obj_guess != 0) {
        obj_guess->flags65_guess |= 4;
        obj_guess->Slot48_guess(1, 1);
    }
    return obj_guess;
}

// Scalar deleting destructor of the factory (its destructor 0x553959 is empty).
// FUNCTION: TITANIUM 0x00553C19
void* Releasable_guess::Release_guess(unsigned char flags_guess) {
    Noop_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// The last class id in the template's list (the most derived type), or 0 when empty.
// FUNCTION: TITANIUM 0x00553C35
int RequestLootSlot_guess::Read_guess() {
    if (count_guess > 0) {
        int index_guess = count_guess - 1;
        return chunks_guess[index_guess >> shift_guess][mask_guess & index_guess];
    }
    return 0;
}

// Builds the control for a template: ids 0x18, 0x19 (probably the gauge, ctor 0x5590FD), 0x1A (inventory
// slot) and 0x1D are game types; anything else goes to the base factory 0x5B5DC0.
// FUNCTION: TITANIUM 0x00553C5C
void SidlControlFactory_guess::Dispatch_guess(int a_guess, Src_guess* s_guess) {
    int kind_guess = ((RequestLootSlot_guess*)s_guess)->Read_guess();
    int done_guess = 0;
    switch (kind_guess) {
    case 0x1d:
        done_guess = Case1d_guess(a_guess, s_guess);
        break;
    case 0x1a:
        done_guess = (int)CreateInvSlotWnd_guess(a_guess, s_guess);
        break;
    case 0x19:
        done_guess = Case19_guess(a_guess, s_guess);
        break;
    case 0x18:
        done_guess = Case18_guess(a_guess, s_guess);
        break;
    }
    if (done_guess == 0) {
        Fallback_guess(a_guess, s_guess);
    }
}

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct SkillSelectorList_guess : CListWnd {
    char pad_140_guess[0x159 - 0x140];
    unsigned char field_159_guess;          // 0x159
    char pad_15a_guess[0x160 - 0x15a];
    int field_160_guess;                    // 0x160

    void Setup_guess() {
        field_159_guess = 1;
        field_160_guess = 0x10;
    }
};

// EXTERNAL: TITANIUM 0x0065C958 ??_7CSkillsSelectWndView_guess@@6B@
struct CSkillsSelectWndView_guess : CSidlScreenWndBase {
    int field_15c_guess;                    // 0x15C
    int field_160_guess;                    // 0x160
    SkillSelectorList_guess* list_164_guess; // 0x164
    int field_168_guess;                    // 0x168

    CSkillsSelectWndView_guess(CXWnd* parent);
};

// CSkillsSelectWnd::CSkillsSelectWnd: sets up SKSW_SkillSelectorList, which is used without a null test.
// FUNCTION: TITANIUM 0x00553CBD
CSkillsSelectWndView_guess::CSkillsSelectWndView_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "SkillsSelectWindow") {
    field_15c_guess = 0;
    field_160_guess = 0;
    field_168_guess = 0;
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        list_164_guess = (SkillSelectorList_guess*)((CSidlScreenWnd*)this)->GetChildItem("SKSW_SkillSelectorList");
        list_164_guess->SetColors(0xffffffff, 0xffffff00, 0xff808080);
        list_164_guess->Setup_guess();
        list_164_guess->WindowStyle &= ~0x200000;
    }
}

