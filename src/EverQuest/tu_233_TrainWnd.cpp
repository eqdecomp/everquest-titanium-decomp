// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 233: a hint from compare/tumap.py.
// CTrainWnd (screen "TrainWindow", vtable 0x65F470), the guild-master skill trainer: only its constructor
// lives here. CTrainWndView_guess is CTrainWnd (Mac map, high).
#include "titanium/types.h"
#include "titanium/crt.h"

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct SkillListFields_guess {
    char pad_000[0x159];
    unsigned char field_159_guess;          // 0x159
    char pad_15a[6];
    int field_160_guess;                    // 0x160
    char pad_164[8];
    int field_16c_guess;                    // 0x16c
};

// EXTERNAL: TITANIUM 0x0065F470 ??_7CTrainWndView_guess@@6B@
struct CTrainWndView_guess : CSidlScreenWndBase {
    char pad_15c[0x8];
    CXWnd* trainButton_164;                 // 0x164 TrainButton
    CXWnd* doneButton_168;                  // 0x168 DoneButton
    CXWnd* expLabel_16c;                    // 0x16c ExpLabel
    CXWnd* moneyLabel_170;                  // 0x170 MoneyLabel
    CXWnd* practiceLabel_174;               // 0x174 PracticeLabel
    CXWnd* practiceCount_178;               // 0x178 PracticeCount
    CXWnd* coinCount_17c[4];                // 0x17c CoinCount0..3
    CListWnd* skillList_18c;                // 0x18c SkillList
    char pad_190[0x630];
    int field_7c0_guess;                    // 0x7c0
    char pad_7c4[4];
    int field_7c8_guess;                    // 0x7c8
    int field_7cc_guess;                    // 0x7cc
    unsigned char field_7d0_guess;          // 0x7d0
    CTrainWndView_guess(CXWnd* parent);
};

// CTrainWnd constructor: Train starts disabled until a skill is picked; the skill list gets a left-aligned
// name column and six right-aligned number columns.
// FUNCTION: TITANIUM 0x0056A4FF
CTrainWndView_guess::CTrainWndView_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "TrainWindow") {
    field_7cc_guess = -1;
    trainButton_164 = 0;
    doneButton_168 = 0;
    skillList_18c = 0;
    coinCount_17c[0] = 0;
    coinCount_17c[1] = 0;
    coinCount_17c[2] = 0;
    coinCount_17c[3] = 0;
    expLabel_16c = 0;
    practiceLabel_174 = 0;
    practiceCount_178 = 0;
    moneyLabel_170 = 0;
    field_7c0_guess = 0;
    field_7c8_guess = 1;
    field_7d0_guess = 1;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x10800;
        // 19; CPvPStatsWnd sets 50 here too, probably the window's help-tip id.
        field_158_guess = 0x13;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        trainButton_164 = ((CSidlScreenWnd*)this)->GetChildItem("TrainButton");
        if (trainButton_164 != 0) {
            trainButton_164->Enabled = 0;
        }
        doneButton_168 = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
        skillList_18c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("SkillList");
        if (skillList_18c != 0) {
            skillList_18c->SetColors(-1, 0xffffff00, 0xff808080);
            skillList_18c->SetColumnJustification(0, 0);
            skillList_18c->SetColumnJustification(1, 1);
            skillList_18c->SetColumnJustification(2, 1);
            skillList_18c->SetColumnJustification(3, 1);
            skillList_18c->SetColumnJustification(4, 1);
            skillList_18c->SetColumnJustification(5, 1);
            skillList_18c->SetColumnJustification(6, 1);
            SkillListFields_guess* list = (SkillListFields_guess*)skillList_18c;
            list->field_159_guess = 1;
            // Same list colours as CPvPStatsWnd (+0x16C 0xFF8AA3FF); +0x160 24, probably the row height.
            list->field_160_guess = 0x18;
            ((SkillListFields_guess*)skillList_18c)->field_16c_guess = 0xff8aa3ff;
        }
        char name[0x100];
        for (int i = 0; i < 4; ++i) {
            sprintf(name, "CoinCount%d", i);
            coinCount_17c[i] = ((CSidlScreenWnd*)this)->GetChildItem(name);
        }
        expLabel_16c = ((CSidlScreenWnd*)this)->GetChildItem("ExpLabel");
        practiceLabel_174 = ((CSidlScreenWnd*)this)->GetChildItem("PracticeLabel");
        practiceCount_178 = ((CSidlScreenWnd*)this)->GetChildItem("PracticeCount");
        moneyLabel_170 = ((CSidlScreenWnd*)this)->GetChildItem("MoneyLabel");
        // 0x59DB90 (Mac map, low: CXWnd::SetZLayer) with 20; CColorPickerWnd passes 199.
        FUN_0059db90_guess(0x14);
    }
}
