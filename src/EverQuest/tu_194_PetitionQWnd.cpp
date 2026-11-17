// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 194: a hint from compare/tumap.py.
// CPetitionQWnd constructor (screen "PetitionQWindow", vtable 0x65A468, pointer 0x850C98): the GM petition
// queue; tu_029 creates it only for GMs. CPetitionQWndView_guess is CPetitionQWnd.
#include "titanium/types.h"

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x0065A468 ??_7CPetitionQWndView_guess@@6B@
struct CPetitionQWndView_guess : CSidlScreenWndBase {
    CListWnd* petitionList_15c;                 // 0x15c PetitionList
    CXWnd* petitionTotal_160;                   // 0x160 PetitionTotal
    CXWnd* checkOutButton_164;                  // 0x164 CheckOutButton
    CXWnd* userText_168;                        // 0x168 UserText
    CXWnd* gmText_16c;                          // 0x16c GMText
    CXWnd* gmInput_170;                         // 0x170 GMInput
    CXWnd* addGmTextButton_174;                 // 0x174 AddGMTextButton
    CXWnd* inquireButton_178;                   // 0x178 InquireButton
    CXWnd* logBugButton_17c;                    // 0x17c LogBugButton
    CXWnd* logFeedbackButton_180;               // 0x180 LogFeedbackButton
    CXWnd* logGuideButton_184;                  // 0x184 LogGuideButton
    CXWnd* decreasePriorityButton_188;          // 0x188 DecreasePriorityButton
    CXWnd* priority_18c;                        // 0x18c Priority
    CXWnd* increasePriorityButton_190;          // 0x190 IncreasePriorityButton
    CXWnd* userHandle_194;                      // 0x194 UserHandle
    CXWnd* lastGuide_198;                       // 0x198 LastGuide
    CXWnd* checkOuts_19c;                       // 0x19c CheckOuts
    CXWnd* zone_1a0;                            // 0x1a0 Zone
    CXWnd* character_1a4;                       // 0x1a4 Character
    CXWnd* level_1a8;                           // 0x1a8 Level
    CXWnd* class_1ac;                           // 0x1ac Class
    CXWnd* race_1b0;                            // 0x1b0 Race
    CXWnd* checkInButton_1b4;                   // 0x1b4 CheckInButton
    CXWnd* undoCheckButton_1b8;                 // 0x1b8 UndoCheckButton
    CXWnd* resolveButton_1bc;                   // 0x1bc ResolveButton
    CXWnd* deleteButton_1c0;                    // 0x1c0 DeleteButton
    CXWnd* unavailableButton_1c4;               // 0x1c4 UnavailableButton
    CXWnd* availableButton_1c8;                 // 0x1c8 AvailableButton
    CXWnd* time_1cc;                            // 0x1cc Time
    CXWnd* unavailableCount_1d0;                // 0x1d0 UnavailableCount
    CXWnd* filterGreenButton_1d4;               // 0x1d4 FilterGreenButton
    CXWnd* filterYellowButton_1d8;              // 0x1d8 FilterYellowButton
    CXWnd* filterRedButton_1dc;                 // 0x1dc FilterRedButton
    int field_1e0;                              // 0x1e0
    char pad_1e4[0xa8c - 0x1e4];
    unsigned char field_a8c;                    // 0xa8c
    unsigned char field_a8d;                    // 0xa8d
    unsigned char field_a8e;                    // 0xa8e
    CPetitionQWndView_guess(CXWnd* parent);
};

#define pLocalPlayer_guess EQ_GLOBAL(EQPlayer*, 0x00905CE4)

// Mac: CPetitionQWnd::CPetitionQWnd. Binds the 33 children (INI version 1); "Zone", "Character", "Race"
// and "Time" are pooled string literals.
// FUNCTION: TITANIUM 0x00542B35
CPetitionQWndView_guess::CPetitionQWndView_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "PetitionQWindow", -1, 1, 0) {
    petitionTotal_160 = 0;
    checkOutButton_164 = 0;
    userText_168 = 0;
    gmText_16c = 0;
    gmInput_170 = 0;
    addGmTextButton_174 = 0;
    inquireButton_178 = 0;
    logBugButton_17c = 0;
    logFeedbackButton_180 = 0;
    logGuideButton_184 = 0;
    decreasePriorityButton_188 = 0;
    increasePriorityButton_190 = 0;
    priority_18c = 0;
    userHandle_194 = 0;
    lastGuide_198 = 0;
    checkOuts_19c = 0;
    zone_1a0 = 0;
    character_1a4 = 0;
    level_1a8 = 0;
    class_1ac = 0;
    race_1b0 = 0;
    checkInButton_1b4 = 0;
    undoCheckButton_1b8 = 0;
    resolveButton_1bc = 0;
    deleteButton_1c0 = 0;
    unavailableButton_1c4 = 0;
    availableButton_1c8 = 0;
    time_1cc = 0;
    unavailableCount_1d0 = 0;
    petitionList_15c = 0;
    filterGreenButton_1d4 = 0;
    filterYellowButton_1d8 = 0;
    filterRedButton_1dc = 0;
    if (SidlPiece != 0) {
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        petitionTotal_160 = ((CSidlScreenWnd*)this)->GetChildItem("PetitionTotal");
        checkOutButton_164 = ((CSidlScreenWnd*)this)->GetChildItem("CheckOutButton");
        userText_168 = ((CSidlScreenWnd*)this)->GetChildItem("UserText");
        gmText_16c = ((CSidlScreenWnd*)this)->GetChildItem("GMText");
        gmInput_170 = ((CSidlScreenWnd*)this)->GetChildItem("GMInput");
        addGmTextButton_174 = ((CSidlScreenWnd*)this)->GetChildItem("AddGMTextButton");
        inquireButton_178 = ((CSidlScreenWnd*)this)->GetChildItem("InquireButton");
        logBugButton_17c = ((CSidlScreenWnd*)this)->GetChildItem("LogBugButton");
        logFeedbackButton_180 = ((CSidlScreenWnd*)this)->GetChildItem("LogFeedbackButton");
        logGuideButton_184 = ((CSidlScreenWnd*)this)->GetChildItem("LogGuideButton");
        decreasePriorityButton_188 = ((CSidlScreenWnd*)this)->GetChildItem("DecreasePriorityButton");
        increasePriorityButton_190 = ((CSidlScreenWnd*)this)->GetChildItem("IncreasePriorityButton");
        priority_18c = ((CSidlScreenWnd*)this)->GetChildItem("Priority");
        userHandle_194 = ((CSidlScreenWnd*)this)->GetChildItem("UserHandle");
        lastGuide_198 = ((CSidlScreenWnd*)this)->GetChildItem("LastGuide");
        checkOuts_19c = ((CSidlScreenWnd*)this)->GetChildItem("CheckOuts");
        zone_1a0 = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065A370));
        character_1a4 = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x00642B7C));
        level_1a8 = ((CSidlScreenWnd*)this)->GetChildItem("Level");
        class_1ac = ((CSidlScreenWnd*)this)->GetChildItem("Class");
        race_1b0 = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065A358));
        checkInButton_1b4 = ((CSidlScreenWnd*)this)->GetChildItem("CheckInButton");
        undoCheckButton_1b8 = ((CSidlScreenWnd*)this)->GetChildItem("UndoCheckButton");
        resolveButton_1bc = ((CSidlScreenWnd*)this)->GetChildItem("ResolveButton");
        deleteButton_1c0 = ((CSidlScreenWnd*)this)->GetChildItem("DeleteButton");
        unavailableButton_1c4 = ((CSidlScreenWnd*)this)->GetChildItem("UnavailableButton");
        availableButton_1c8 = ((CSidlScreenWnd*)this)->GetChildItem("AvailableButton");
        time_1cc = ((CSidlScreenWnd*)this)->GetChildItem(EQ_ARRAY(char, 0x0065A2FC));
        unavailableCount_1d0 = ((CSidlScreenWnd*)this)->GetChildItem("UnavailableCount");
        filterGreenButton_1d4 = ((CSidlScreenWnd*)this)->GetChildItem("FilterGreenButton");
        filterYellowButton_1d8 = ((CSidlScreenWnd*)this)->GetChildItem("FilterYellowButton");
        filterRedButton_1dc = ((CSidlScreenWnd*)this)->GetChildItem("FilterRedButton");
        petitionList_15c = (CListWnd*)((CSidlScreenWnd*)this)->GetChildItem("PetitionList");
        if (petitionList_15c != 0) {
            petitionList_15c->SetColors(-1, 0xffffff00, 0xff808080);
            petitionList_15c->SetColumnJustification(0, 0);
            petitionList_15c->WindowStyle &= ~0x200000;
        }
        // No petition selected, probably. The three bytes at +0xA8C match the three filter buttons
        // (green, yellow, red); a GM starts with the last two on.
        field_1e0 = -1;
        field_a8c = 0;
        field_a8d = 0;
        field_a8e = 0;
        if (pLocalPlayer_guess->GM != 0) {
            field_a8d = 1;
            field_a8e = 1;
        }
    }
}
