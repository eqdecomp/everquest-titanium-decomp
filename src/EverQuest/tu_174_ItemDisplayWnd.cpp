// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 174: a hint from compare/tumap.py.
// The item display window (ItemDisplayWindow, CItemDisplayWnd_guess): the STML description of an item (stats,
// race/class lists, effects, augments, evolving info, flags like MAGIC ITEM and NO RENT), plus the pool of up
// to MaxItemDisplays such windows (PickManager_guess, keyed "ItemDisplay%d"). The Create*String helpers each
// add one section and count its lines in `count_guess`.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include "titanium/wnd/CTipWnd.h"

struct Ref_guess {
    int handle_guess;
    // EXTERNAL: TITANIUM 0x00407D68 Ref_guess::Ref_guess
    Ref_guess(const Ref_guess& other_guess);
    ~Ref_guess();
    // EXTERNAL: TITANIUM 0x004482FB Ref_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00572E00 Ref_guess::Append_guess
    void Append_guess(const char* value_guess);
};

struct CStmlWndView_guess {
    // EXTERNAL: TITANIUM 0x005A8B00 CStmlWndView_guess::SetSTMLText
    void SetSTMLText(Ref_guess value_guess, int first_guess, int second_guess);
};

struct UpdateVTable_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int flags_guess);
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
    virtual void Slot63_guess(void* value_guess);
};

struct ValueSlot_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 ValueSlot_guess::Set_guess
    void Set_guess(int value_guess);
};

struct SetChild_guess {
    char pad0_guess[0x158];
    ValueSlot_guess* field158_guess;
    char pad15c_guess[0x10];
    void* field16c_guess;
};

struct ReleaseTarget_guess;

struct UpdateObject_guess : UpdateVTable_guess {
    char pad4_guess[0x158];
    CStmlWndView_guess* state_guess;
    char pad160_guess[4];
    SetChild_guess* field164_guess;
    Ref_guess ref_guess;
    Ref_guess value_guess;
    ReleaseTarget_guess* field170_guess; // 0x170

    void Update_guess();
    char AboutToHide_guess();
    // EXTERNAL: TITANIUM 0x0059D080 UpdateObject_guess::Enable_guess
    void Enable_guess(int value_guess);
    char AboutToShow_guess();
    void ShowItemInfo_guess(const char* text_guess);
};

struct ItemState_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual char Slot04_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005ECC00 ItemState_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E0D70 ItemState_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005E0770 ItemState_guess::CheckA_guess
    char CheckA_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005EC790 ItemState_guess::CheckB_guess
    char CheckB_guess();
    // EXTERNAL: TITANIUM 0x005E09D0 ItemState_guess::CheckC_guess
    char CheckC_guess();
    // EXTERNAL: TITANIUM 0x005EC7C0 ItemState_guess::CheckD_guess
    char CheckD_guess();
    // EXTERNAL: TITANIUM 0x005E0A00 ItemState_guess::CheckE_guess
    char CheckE_guess();
    // EXTERNAL: TITANIUM 0x005E0A30 ItemState_guess::CheckF_guess
    char CheckF_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005EC820 ItemState_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x005E0620 ItemState_guess::GetLimit_guess
    int GetLimit_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E1020 ItemState_guess::CheckG_guess
    char CheckG_guess();
};

struct EventObject_guess {
    char pad0_guess[0x5c];
    char active_guess;
    char pad1_guess[0x113];
    ItemState_guess* state_guess;

    void OnShow_guess();
    // EXTERNAL: TITANIUM 0x005A1880 EventObject_guess::OnShow
    void OnShow();
};


struct ShiftValue_guess {
    int pad_guess[3]; // 0x0-0xB
    int shift_guess; // 0xC
    int Calculate_guess(int value_guess);
};

struct MessageSender_guess {
    void RequestEvolvingFinalResult_guess(const char* text_guess);
};

struct MapValue_guess {
    int values_guess[4];
};

// EXTERNAL: TITANIUM 0x004B2056 ParseToken_guess
int __cdecl ParseToken_guess(const char* text_guess, char* output_guess, int delimiter_guess);

#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_packetConnection_guess EQ_GLOBAL(int, 0x00905CA0)

struct ResizeMap_guess : ShiftValue_guess {
    void** buckets_guess; // 0x10
    int count_guess; // 0x14
    char active_guess; // 0x18

    // EXTERNAL: TITANIUM 0x0047C3AF ResizeMap_guess::ResizeMap_guess
    ResizeMap_guess(int capacity_guess);
    // EXTERNAL: TITANIUM 0x004B73EE ResizeMap_guess::~ResizeMap_guess
    ~ResizeMap_guess();
    // EXTERNAL: TITANIUM 0x004B73EE ResizeMap_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x00405492 ResizeMap_guess::Fail_guess
    void Fail_guess();
    void Resize_guess(int requested_guess);
    void Set_guess(int index_guess, const MapValue_guess* value_guess);
};

struct DisplayMap_guess : ResizeMap_guess {
    DisplayMap_guess() : ResizeMap_guess(0x20) {}
};

struct ItemDisplayConfig_guess {
    DisplayMap_guess first_guess;
    DisplayMap_guess second_guess;
    int maxDisplays_guess; // 0x38

    ItemDisplayConfig_guess();
};

// EXTERNAL: TITANIUM 0x005595B5 LoadIntFromUIIniFile_guess
int __cdecl LoadIntFromUIIniFile_guess(const char* section_guess, const char* key_guess,
                                 int type_guess, int default_guess);

// EXTERNAL: TITANIUM 0x0060E985 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060D682 _free
extern "C" void __cdecl _free(void* value_guess);

// EXTERNAL: TITANIUM 0x0060E450 CopyString_guess
void __cdecl CopyString_guess(char* output_guess, const char* value_guess);

#define g_stringIds_guess EQ_ARRAY(int, 0x00792ED8)
#define g_defaultStringId_guess EQ_GLOBAL(int, 0x00792EE8)
struct ReleaseTarget_guess {
    virtual void Release_guess(int value_guess);
};

struct DestructorMember_guess {
    int value_guess;
    // EXTERNAL: TITANIUM 0x004482FB DestructorMember_guess::~DestructorMember_guess
    ~DestructorMember_guess();
};

struct DestructorBase_guess {
    // EXTERNAL: TITANIUM 0x005A3100 DestructorBase_guess::~DestructorBase_guess
    virtual ~DestructorBase_guess();
    char pad4_guess[0x164];
};

// EXTERNAL: TITANIUM 0x00656948 ??_7DestructorTarget_guess@@6B@
struct DestructorTarget_guess : DestructorBase_guess {
    DestructorMember_guess member168_guess;
    DestructorMember_guess member16c_guess;
    char pad170_guess[8];
    ReleaseTarget_guess* release178_guess;
    ReleaseTarget_guess* release17c_guess;

    virtual ~DestructorTarget_guess();
    DestructorTarget_guess* Delete_guess(unsigned char flags_guess);
};

// Item display window destructor: releases the A_SpellIcons and A_DragItem animations its constructor made
// (+0x178, +0x17C).
// FUNCTION: TITANIUM 0x0051BFC1
DestructorTarget_guess::~DestructorTarget_guess() {
    if (release178_guess != 0) {
        release178_guess->Release_guess(1);
    }
    if (release17c_guess != 0) {
        release17c_guess->Release_guess(1);
    }
}

// EXTERNAL: TITANIUM 0x0060D0D5 FreeObject_guess
extern "C" void __cdecl FreeObject_guess(void* value_guess);

// Shows the built item text: the body (+0x168) goes into the display box at +0x158 (0x005A8B00) and
// +0x16C becomes the window title (slot 63, SetWindowText).
// FUNCTION: TITANIUM 0x0051C035
void UpdateObject_guess::Update_guess() {
    if (state_guess != 0) {
        state_guess->SetSTMLText(ref_guess, 0, 0);
    }
    Slot63_guess(&value_guess);
}

// Item display window AboutToShow (vtable 0x656948 slot 49): puts the built text and title in place
// (0x0051C035) and calls 0x0059D080 with 1 (a window-manager call); never vetoes.
// FUNCTION: TITANIUM 0x0051C077
char UpdateObject_guess::AboutToShow_guess() {
    Update_guess();
    Enable_guess(1);
    return 1;
}

// Item display window AboutToHide (vtable 0x656948 slot 50): releases the object at +0x170 (virtual
// slot 0 with 1) and clears it; never vetoes.
// FUNCTION: TITANIUM 0x0051C08C
char UpdateObject_guess::AboutToHide_guess() {
    if (field170_guess != 0) {
        field170_guess->Release_guess(1);
        field170_guess = 0;
    }
    return 1;
}

// OnShow (vtable slot 35): when shown and the item's state is 0x36, shows context tip 0x21 in the tip window
// (0x9928E0); then the base CSidlScreenWnd::OnShow.
// FUNCTION: TITANIUM 0x0051C0A6
void EventObject_guess::OnShow_guess() {
    if (active_guess != 0 && state_guess != 0) {
        if (state_guess->GetItemType_guess() == 0x36) {
            pinstCTipWndCONTEXT_guess->selectTip_guess(0x21, 0);
        }
    }
    OnShow();
}

struct ItemQuery_guess {
    // EXTERNAL: TITANIUM 0x005E0B60 ItemQuery_guess::FUN_005e0b60_guess
    int FUN_005e0b60_guess();
    // EXTERNAL: TITANIUM 0x005E3160 ItemQuery_guess::GetRank_guess
    int GetRank_guess(int value_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0D00 ItemQuery_guess::HasFirst_guess
    char HasFirst_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0CC0 ItemQuery_guess::HasSecond_guess
    char HasSecond_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 ItemQuery_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E2F90 ItemQuery_guess::GetRankFor_guess
    int GetRankFor_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005EC630 ItemQuery_guess::GetChild_guess
    ItemQuery_guess* GetChild_guess(int index_guess);
};

#define g_itemInfoTitle_guess EQ_ARRAY(char, 0x00656A68)
#define g_brTag_guess EQ_ARRAY(char, 0x0064DD5C)

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
extern "C" int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

// Whether any of the item's augment slots is filled.
// FUNCTION: TITANIUM 0x0051C0DA
char __cdecl HasAnyAugment_guess(ItemQuery_guess* query_guess) {
    char result_guess = 0;
    for (int i_guess = 0; i_guess < 5; i_guess++) {
        if (query_guess->HasFirst_guess(i_guess) && query_guess->HasSecond_guess(i_guess) &&
            query_guess->GetValue_guess(i_guess)) {
            result_guess = 1;
            break;
        }
    }
    return result_guess;
}

// Appends a titled extra block to the description and redraws it.
// FUNCTION: TITANIUM 0x0051C119
void UpdateObject_guess::ShowItemInfo_guess(const char* text_guess) {
    char buffer_guess[256];
    if (field170_guess != 0) {
        sprintf(buffer_guess, g_itemInfoTitle_guess);
        ref_guess.Append_guess(g_brTag_guess);
        ref_guess.Append_guess(buffer_guess);
        ref_guess.Append_guess(g_brTag_guess);
        ref_guess.Append_guess(text_guess);
        Update_guess();
    }
}

struct ItemOwner_guess {
    // EXTERNAL: TITANIUM 0x005ECBA0 ItemOwner_guess::GetMask_guess
    unsigned int GetMask_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC920 ItemOwner_guess::GetBits_guess
    unsigned int GetBits_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005EC8B0 ItemOwner_guess::GetBitsAlt_guess
    unsigned int GetBitsAlt_guess(int first_guess, int second_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* destination, unsigned int token_guess, const char* p0_guess,
                          const char* p1_guess, const char* p2_guess, const char* p3_guess,
                          const char* p4_guess, const char* p5_guess, const char* p6_guess,
                          const char* p7_guess, const char* p8_guess);

// EXTERNAL: TITANIUM 0x00574720 CopyText_00574720_guess
void __cdecl CopyText_00574720_guess(const char* source, char* destination, int count);

#define g_bitTable_guess EQ_ARRAY(int, 0x006568F0)
#define g_stringIdTable_guess EQ_ARRAY(int, 0x006674C8)
#define g_separator_guess EQ_ARRAY(char, 0x0063FE10)
#define g_emptyText_guess EQ_ARRAY(char, 0x0063F53F)
#define g_brText_guess EQ_ARRAY(char, 0x00656A94)
#define g_numberFormat_guess EQ_ARRAY(char, 0x00656248)
#define g_itemIds_guess EQ_ARRAY(int, 0x00792E98)
#define g_itemIdsEnd_guess EQ_ARRAY(int, 0x00792ED4)

// Worn slots (string 3000 with the slot names); slots 4, 10 and 16 are skipped, the second ear, wrist and
// ring, which share a name with the first.
// FUNCTION: TITANIUM 0x0051C194
CXStr CreateSlotString_guess(ItemOwner_guess* owner_guess, int* count_guess) {
    CXStr result_guess;
    char line_guess[100];
    char text_guess[1024];
    for (int i_guess = 0; i_guess < 22; i_guess++) {
        if (i_guess != 4 && i_guess != 10 && i_guess != 16) {
            int bit_guess = 1 << g_bitTable_guess[i_guess];
            if ((bit_guess & owner_guess->GetMask_guess(1)) != 0) {
                char* name_guess = pStringTable->getString(g_stringIdTable_guess[i_guess], 0);
                CopyText_00574720_guess(name_guess, line_guess, 100);
                result_guess += g_separator_guess;
                result_guess += line_guess;
            }
        }
    }
    int length_guess = result_guess.Ptr != 0 ? result_guess.Ptr->length : 0;
    if (length_guess != 0) {
        Format_guess(text_guess, 3000, result_guess, 0, 0, 0, 0, 0, 0, 0, 0);
        result_guess = text_guess;
        result_guess += "<BR>";
        (*count_guess)++;
    }
    return result_guess;
}

struct ItemFlags_guess {
    // EXTERNAL: TITANIUM 0x005E0AD0 ItemFlags_guess::GetFlags_guess
    unsigned int GetFlags_guess();
};

// "This Augmentation fits in slot types: %1" (3357), or "Fits in all slot types." (3369).
// FUNCTION: TITANIUM 0x0051CCFB
CXStr CreateAugmentSlotTypeString_guess(ItemFlags_guess* owner_guess) {
    CXStr result_guess = g_emptyText_guess;
    int count_guess = 0;
    char line_guess[128] = "";
    char text_guess[256];
    for (int i_guess = 1; i_guess < 32; i_guess++) {
        int bit_guess = 1 << (i_guess - 1);
        if ((bit_guess & owner_guess->GetFlags_guess()) != 0) {
            if (count_guess == 0) {
                sprintf(line_guess, g_numberFormat_guess, i_guess);
            } else {
                sprintf(line_guess, "%s, %d", line_guess, i_guess);
            }
            count_guess++;
        }
    }
    if (count_guess >= 31) {
        Format_guess(text_guess, 0xd1d, pStringTable->getString(0xd29, 0), 0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        Format_guess(text_guess, 0xd1d, line_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    result_guess += text_guess;
    return result_guess;
}

// "Race: " (3049) with the three-letter race codes (HUM...VAH, FRG; "Shroud" 3608), or "ALL" (13205).
// FUNCTION: TITANIUM 0x0051CE67
CXStr CreateRaceString_guess(ItemOwner_guess* owner_guess) {
    CXStr result_guess = g_emptyText_guess;
    result_guess += pStringTable->getString(0xbe9, 0);
    int remaining_guess;
    int count_guess = 0;
    int i_guess = 0;
    remaining_guess = 16;
    do {
        int bit_guess = 1 << i_guess;
        if ((bit_guess & owner_guess->GetBits_guess(1, 0)) != 0) {
            switch (i_guess) {
            case 0:
                result_guess += pStringTable->getString(0xbea, 0);
                break;
            case 1:
                result_guess += pStringTable->getString(0xbeb, 0);
                break;
            case 2:
                result_guess += pStringTable->getString(0xbec, 0);
                break;
            case 3:
                result_guess += pStringTable->getString(0xbed, 0);
                break;
            case 4:
                result_guess += pStringTable->getString(0xbee, 0);
                break;
            case 5:
                result_guess += pStringTable->getString(0xbef, 0);
                break;
            case 6:
                result_guess += pStringTable->getString(0xbf0, 0);
                break;
            case 7:
                result_guess += pStringTable->getString(0xbf1, 0);
                break;
            case 8:
                result_guess += pStringTable->getString(0xbf2, 0);
                break;
            case 9:
                result_guess += pStringTable->getString(0xbf3, 0);
                break;
            case 10:
                result_guess += pStringTable->getString(0xbf4, 0);
                break;
            case 11:
                result_guess += pStringTable->getString(0xbf5, 0);
                break;
            case 12:
                result_guess += pStringTable->getString(0xbf6, 0);
                break;
            case 13:
                result_guess += pStringTable->getString(0xbf7, 0);
                break;
            case 14:
                result_guess += pStringTable->getString(0xfcc, 0);
                break;
            case 15:
                result_guess += pStringTable->getString(0xe18, 0);
                break;
            }
            result_guess += g_separator_guess;
            count_guess++;
        }
        i_guess++;
    } while (--remaining_guess != 0);
    if (count_guess == 0) {
        result_guess += pStringTable->getString(0x4c0, 0);
    } else if (count_guess >= 0xf) {
        result_guess = pStringTable->getString(0xbe9, 0);
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0x3395, 0);
    }
    return result_guess;
}

// "Class: " (3064) with the class codes, or "ALL".
// FUNCTION: TITANIUM 0x0051D058
CXStr CreateClassString_guess(ItemOwner_guess* owner_guess) {
    CXStr result_guess = g_emptyText_guess;
    result_guess += pStringTable->getString(0xbf8, 0);
    int count_guess = 0;
    unsigned short i_guess = 1;
    int* id_guess = g_itemIds_guess;
    do {
        int bit_guess = 1 << (i_guess - 1);
        if ((bit_guess & owner_guess->GetBitsAlt_guess(1, 0)) != 0) {
            result_guess += pStringTable->getString(*id_guess, 0);
            result_guess += g_separator_guess;
            count_guess++;
        }
        id_guess++;
        i_guess++;
    } while ((int)id_guess <= (int)g_itemIdsEnd_guess);
    if (count_guess == 0) {
        result_guess += pStringTable->getString(0x4c0, 0);
    } else if (count_guess >= 0x10) {
        result_guess = pStringTable->getString(0xbf8, 0);
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0x3395, 0);
    }
    return result_guess;
}

// Food and drink size, "This is a snack." (3080) up to "This is a miraculous drink!" (3093), by the
// item's size thresholds 0x15, 0x1F, 0x29, 0x33, 0x3D.
// FUNCTION: TITANIUM 0x0051D17F
CXStr CreateMealSizeString_guess(ItemState_guess* state_guess) {
    CXStr result_guess = g_emptyText_guess;
    char buffer_guess[256];
    if (state_guess->GetItemType_guess() == 0xe || state_guess->GetItemType_guess() == 0xf) {
        int value_guess = state_guess->GetValue_guess();
        if (state_guess->GetItemType_guess() == 0xe) {
            if (value_guess < 6) {
                sprintf(buffer_guess, pStringTable->getString(0xc08, 0));
            } else if (value_guess < 0x15) {
                sprintf(buffer_guess, pStringTable->getString(0xc09, 0));
            } else if (value_guess < 0x1f) {
                sprintf(buffer_guess, pStringTable->getString(0xc0a, 0));
            } else if (value_guess < 0x29) {
                sprintf(buffer_guess, pStringTable->getString(0xc0b, 0));
            } else if (value_guess < 0x33) {
                sprintf(buffer_guess, pStringTable->getString(0xc0c, 0));
            } else if (value_guess < 0x3d) {
                sprintf(buffer_guess, pStringTable->getString(0xc0d, 0));
            } else {
                sprintf(buffer_guess, pStringTable->getString(0xc0e, 0));
            }
        } else if (state_guess->GetItemType_guess() == 0xf) {
            if (value_guess < 6) {
                sprintf(buffer_guess, pStringTable->getString(0xc0f, 0));
            } else if (value_guess < 0x15) {
                sprintf(buffer_guess, pStringTable->getString(0xc10, 0));
            } else if (value_guess < 0x1f) {
                sprintf(buffer_guess, pStringTable->getString(0xc11, 0));
            } else if (value_guess < 0x29) {
                sprintf(buffer_guess, pStringTable->getString(0xc12, 0));
            } else if (value_guess < 0x33) {
                sprintf(buffer_guess, pStringTable->getString(0xc13, 0));
            } else if (value_guess < 0x3d) {
                sprintf(buffer_guess, pStringTable->getString(0xc14, 0));
            } else {
                sprintf(buffer_guess, pStringTable->getString(0xc15, 0));
            }
        }
        result_guess += buffer_guess;
        result_guess += "<BR>";
    }
    return result_guess;
}

struct Entry_guess {
    virtual void Slot00_guess(int flags_guess);
};

struct UpdateQuery_guess {
    virtual void Slot00_guess(int flags_guess);
    // EXTERNAL: TITANIUM 0x005EC630 UpdateQuery_guess::GetEntry_guess
    Entry_guess* GetEntry_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC640 UpdateQuery_guess::SetEntry_guess
    void SetEntry_guess(int index_guess, int value_guess);
    // EXTERNAL: TITANIUM 0x005E33F0 UpdateQuery_guess::GetCount_guess
    int GetCount_guess();
};

struct Owner_guess {
    virtual void Slot00_guess();
    virtual UpdateQuery_guess* Slot01_guess();
    char pad4_guess[0x5C];
    int field64_guess; // 0x64
    int field68_guess; // 0x68
    char pad6c_guess[4];
    double field70_guess; // 0x70
    char pad78_guess[0x24];
    int field9c_guess; // 0x9C
    // EXTERNAL: TITANIUM 0x005E0F30 Owner_guess::GetItemId_guess
    int GetItemId_guess();
};

// EXTERNAL: TITANIUM 0x00577000 FormatShort_guess
int __cdecl FormatShort_guess(char* buffer_guess, int size_guess, const char* format_guess, ...);

// EXTERNAL: TITANIUM 0x005A4190 Build_guess
CXStr __cdecl Build_guess(int id_guess, const CXStr& first_guess, const CXStr& second_guess);

char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

#define g_numBuf0_guess EQ_ARRAY(char, 0x0099DF60)
#define g_numBuf1_guess EQ_ARRAY(char, 0x0099DAE0)
#define g_numBuf2_guess EQ_ARRAY(char, 0x0099DB00)

struct RankEntry_guess {
    // EXTERNAL: TITANIUM 0x005E0BF0 RankEntry_guess::HasValue240_guess
    int HasValue240_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 RankEntry_guess::GetItemType_guess
    int GetItemType_guess();
};

struct StatSource_guess {
    // EXTERNAL: TITANIUM 0x00479D99 StatSource_guess::Adjust_guess
    unsigned char Adjust_guess(int value_guess);
};

struct RankApplier_guess {
    // EXTERNAL: TITANIUM 0x0041C7C1 RankApplier_guess::ApplyRank_guess
    int ApplyRank_guess(RankEntry_guess* entry_guess, int rank_guess, int adjusted_guess);
};

struct RankOwner_guess {
    char pad_0000_guess[0xC280];
    RankApplier_guess applier_guess;
};

#define g_statSource_guess EQ_GLOBAL(StatSource_guess*, 0x00905CE4)
#define g_rankOwner_guess EQ_GLOBAL(RankOwner_guess*, 0x00905D00)

// A stat with its bonus: "%+d", or red (#FF4040) with the base in brackets when the bonus lowers it.
// FUNCTION: TITANIUM 0x0051D331
// @early-stop: budget, diff ndiff=4
CXStr __cdecl CreateModString_guess(RankEntry_guess* entry_guess, int value_guess,
                                 unsigned int token_guess, int* count_guess) {
    CXStr result_guess = g_emptyText_guess;
    char text_guess[128];
    char buffer_guess[64];
    if (value_guess == 0) {
        return result_guess;
    }
    if (entry_guess->HasValue240_guess() == 0) {
        int adjusted_guess = g_statSource_guess->Adjust_guess(entry_guess->GetItemType_guess());
        int applied_guess =
            g_rankOwner_guess->applier_guess.ApplyRank_guess(entry_guess, value_guess, adjusted_guess);
        if (applied_guess == value_guess) {
            sprintf(buffer_guess, "%+d", applied_guess);
        } else {
            sprintf(buffer_guess, "<c \"#FF4040\"> %+d </C> (%+d)", applied_guess, value_guess);
        }
        Format_guess(text_guess, token_guess, buffer_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    } else {
        sprintf(buffer_guess, "%+d", value_guess);
        Format_guess(text_guess, token_guess, buffer_guess, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    result_guess += text_guess;
    result_guess += g_brText_guess;
    (*count_guess)++;
    return result_guess;
}

// "Evolving: Level %1/%2 %3%% %4" (6146) with a "Final Result" (6194) link carrying the item's ids.
// FUNCTION: TITANIUM 0x0051D4A8
// @early-stop: budget, structural ndiff=33
CXStr CreateEvolvingString_guess(Owner_guess* owner_guess) {
    CXStr result_guess;
    CXStr temp_guess;
    char text_guess[1024];
    char buffer_guess[256];
    if (owner_guess->field68_guess < owner_guess->field9c_guess) {
        int i_guess;
        UpdateQuery_guess* query_guess = owner_guess->Slot01_guess();
        for (i_guess = 0; i_guess < 5; i_guess++) {
            Entry_guess* entry_guess = query_guess->GetEntry_guess(i_guess);
            if (entry_guess != 0) {
                entry_guess->Slot00_guess(1);
            }
            query_guess->SetEntry_guess(i_guess, 0);
        }
        FormatShort_guess(buffer_guess, 0x100, "%d^%d^%d^%d^%d", 1, owner_guess->GetItemId_guess(),
                          owner_guess->field64_guess, owner_guess->field68_guess,
                          query_guess->GetCount_guess());
        {
            CXStr buffer_str_guess(buffer_guess);
            CXStr id_str_guess(pStringTable->getString(0x1832, 0));
            temp_guess = Build_guess(0x1b, id_str_guess, buffer_str_guess);
        }
        if (query_guess != 0) {
            query_guess->Slot00_guess(1);
        }
    }
    double d_guess = owner_guess->field70_guess;
    int e_guess = owner_guess->field9c_guess;
    int f_guess = owner_guess->field68_guess;
    Format_guess(text_guess, 0x1802, __itoa(f_guess, g_numBuf2_guess, 10),
                 __itoa(e_guess, g_numBuf1_guess, 10), __itoa((int)d_guess, g_numBuf0_guess, 10),
                 temp_guess, 0, 0, 0, 0, 0);
    result_guess = text_guess;
    return result_guess;
}

// The flag line: MAGIC ITEM, LORE, NO DROP, NO RENT, AUGMENTATION, NO TRANSFER, ATTUNEABLE, NO PET...
// (strings 3094-3100, 3356, 6155, 5911, 8876).
// FUNCTION: TITANIUM 0x0051D72A
CXStr CreateEquipmentStatusString_guess(ItemState_guess* state_guess) {
    CXStr result_guess = g_emptyText_guess;
    if (state_guess->CheckA_guess(1)) {
        result_guess += pStringTable->getString(0xc16, 0);
    }
    if (state_guess->CheckB_guess()) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc17, 0);
    }
    if (state_guess->CheckC_guess()) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc18, 0);
    }
    if (state_guess->CheckD_guess()) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc19, 0);
    }
    if (state_guess->CheckE_guess()) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc1a, 0);
    }
    if (!state_guess->Slot04_guess(0x29a)) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc1b, 0);
    }
    if (state_guess->CheckF_guess(0)) {
        result_guess += g_separator_guess;
        result_guess += pStringTable->getString(0x180b, 0);
    }
    if (state_guess->GetCount_guess() != 0) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0x1717, 0);
    }
    if (state_guess->GetLimit_guess(0) == 0) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xc1c, 0);
    }
    if (state_guess->CheckG_guess()) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0x22ac, 0);
    }
    if (state_guess->GetItemType_guess() == 0x36) {
        result_guess += g_brText_guess;
        result_guess += pStringTable->getString(0xd1c, 0);
    }
    return result_guess;
}

struct TargetChild_guess {
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
    virtual void Adjust_guess(int value_guess);
    char pad4_guess[0x108];
    int value_guess;
};

struct TargetOwner_guess {
    char pad0_guess[0x15c];
    TargetChild_guess* child_guess;
    int HandleKeyboardMsg_guess(int action_guess, unsigned int flags_guess, char enabled_guess);
};

// Page Down / Page Up (DirectInput 0xD1/0xC9) scroll the description by 40 pixels, without Shift or Ctrl.
// FUNCTION: TITANIUM 0x0051D98F
int TargetOwner_guess::HandleKeyboardMsg_guess(int action_guess, unsigned int flags_guess, char enabled_guess) {
    char result_guess = 0;
    if ((flags_guess & 1) != 0 && enabled_guess != 0) {
        unsigned char inverse2_guess = (unsigned char)~(flags_guess >> 2);
        unsigned char inverse1_guess = (unsigned char)~(flags_guess >> 1);
        if ((inverse2_guess & inverse1_guess & 1) != 0) {
            switch (action_guess) {
            case 0xd1:
                if (child_guess != 0) {
                    child_guess->Adjust_guess(child_guess->value_guess + 0x28);
                }
                result_guess = 1;
                break;
            case 0xc9:
                if (child_guess != 0) {
                    child_guess->Adjust_guess(child_guess->value_guess - 0x28);
                }
                result_guess = 1;
                break;
            }
        }
    }
    return (result_guess != 0) - 1;
}

// ceil(value / 2^shift); 0 for 0 or less.
// FUNCTION: TITANIUM 0x0051DA09
int ShiftValue_guess::Calculate_guess(int value_guess) {
    if (value_guess <= 0) {
        return 0;
    }
    return ((value_guess - 1) >> shift_guess) + 1;
}

// Scalar deleting destructor of the item display window (vtable 0x656948 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x0051DA1F
DestructorTarget_guess* DestructorTarget_guess::Delete_guess(unsigned char flags_guess) {
    this->DestructorTarget_guess::~DestructorTarget_guess();
    if ((flags_guess & 1) != 0) {
        FreeObject_guess(this);
    }
    return this;
}

// "Final Result" link clicked: sends message 0x7E61 (24 bytes: code 4, four ids from the link, Ctrl flag);
// not in EQEmu's Titanium list.
// FUNCTION: TITANIUM 0x0051DE5D
void MessageSender_guess::RequestEvolvingFinalResult_guess(const char* text_guess) {
    int data_guess[6];
    data_guess[0] = 4;
    text_guess += ParseToken_guess(text_guess, reinterpret_cast<char*>(&data_guess[1]), 0x5e);
    text_guess += ParseToken_guess(text_guess, reinterpret_cast<char*>(&data_guess[2]), 0x5e);
    text_guess += ParseToken_guess(text_guess, reinterpret_cast<char*>(&data_guess[3]), 0x5e);
    ParseToken_guess(text_guess, reinterpret_cast<char*>(&data_guess[4]), 0x5e);
    data_guess[5] = (~pinstCXWndManager_guess->GetKeyboardFlags()) & 1;
    EQSendMessage(&g_packetConnection_guess, 0x7e61, data_guess, 0x18, 1);
}

// Grows the window pool to `requested_guess` entries.
// FUNCTION: TITANIUM 0x0051DED9
void ResizeMap_guess::Resize_guess(int requested_guess) {
    if (active_guess != 0 && requested_guess > 0) {
        int newCount_guess = Calculate_guess(requested_guess);
        if (newCount_guess > count_guess) {
            void** newBuckets_guess = (void**)operator new(newCount_guess << 2);
            if (newBuckets_guess == 0) {
                active_guess = 0;
            } else {
                for (int i_guess = 0; i_guess < count_guess; i_guess++) {
                    newBuckets_guess[i_guess] = buckets_guess[i_guess];
                }
                for (int i_guess = count_guess; i_guess < newCount_guess; i_guess++) {
                    void* block_guess = operator new(pad_guess[1] << 4);
                    newBuckets_guess[i_guess] = block_guess;
                    if (block_guess == 0) {
                        active_guess = 0;
                        break;
                    }
                }
                if (active_guess != 0) {
                    _free(buckets_guess);
                    buckets_guess = newBuckets_guess;
                    count_guess = newCount_guess;
                }
            }
        }
        if (active_guess == 0) {
            Clear_guess();
            Fail_guess();
        }
    }
}

// Pool size from [Main] MaxItemDisplays.
// FUNCTION: TITANIUM 0x0051DF88
ItemDisplayConfig_guess::ItemDisplayConfig_guess() {
    maxDisplays_guess = LoadIntFromUIIniFile_guess("Main", "MaxItemDisplays", 4, 1);
}

// Stores `value_guess` at `index_guess` in the chunked array, growing it (0x0051DED9) and its count when
// the index is past the end; nothing happens if the growth failed.
// FUNCTION: TITANIUM 0x0051DFDA
void ResizeMap_guess::Set_guess(int index_guess, const MapValue_guess* value_guess) {
    if (index_guess >= 0) {
        if (index_guess >= pad_guess[0]) {
            Resize_guess(index_guess + 1);
            if (active_guess == 0) {
                return;
            }
            pad_guess[0] = index_guess + 1;
        }
        if (active_guess != 0) {
            ((MapValue_guess*)buckets_guess[index_guess >> shift_guess])
                [index_guess & pad_guess[2]] = *value_guess;
        }
    }
}

struct TextAppend_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00572C10 TextAppend_guess::Append_guess
    void Append_guess(const CXStr& other_guess);
};

struct ItemDef_guess {
    char pad0_guess[0x208];
    char* name_guess; // 0x208
};

struct ItemDb_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 ItemDb_guess::Get_guess
    ItemDef_guess* Get_guess(int id_guess);
};

#define g_itemDb_guess EQ_GLOBAL(ItemDb_guess*, 0x00985CC8)
#define g_valueSeparator_guess EQ_ARRAY(char, 0x0063FDE4)

struct EQ_ItemView_guess {
    // EXTERNAL: TITANIUM 0x005E0BF0 EQ_ItemView_guess::HasCharges_guess
    int HasCharges_guess();
    // EXTERNAL: TITANIUM 0x005E0BC0 EQ_ItemView_guess::GetCharges_guess
    int GetCharges_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 EQ_ItemView_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 EQ_ItemView_guess::GetEffectId_guess
    int GetEffectId_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005E1140 EQ_ItemView_guess::GetEffectLevel_guess
    int GetEffectLevel_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005E11A0 EQ_ItemView_guess::GetEffectType_guess
    int GetEffectType_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005E11D0 EQ_ItemView_guess::GetEffectExtra_guess
    int GetEffectExtra_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005E0D70 EQ_ItemView_guess::GetCastTime_guess
    int GetCastTime_guess();
    // EXTERNAL: TITANIUM 0x005E05B0 EQ_ItemView_guess::GetRecastTime_guess
    unsigned int GetRecastTime_guess();
    // EXTERNAL: TITANIUM 0x005E05F0 EQ_ItemView_guess::GetRecastType_guess
    int GetRecastType_guess();
    // EXTERNAL: TITANIUM 0x005EC630 EQ_ItemView_guess::GetChild_guess
    EQ_ItemView_guess* GetChild_guess(int index_guess);
};

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidEffect_guess
char __cdecl IsValidEffect_guess(int id_guess);

// EXTERNAL: TITANIUM 0x0046F97F GetTimeStringFromSeconds_guess
void __cdecl GetTimeStringFromSeconds_guess(char* buffer_guess, unsigned int value_guess);

// Spell effects: Combat/Worn/Casting-time click effects (3029-3032), focus (5530), recast delay and type
// (9234/9239).
// FUNCTION: TITANIUM 0x0051E1CD
// @early-stop: budget, diff ndiff=15
CXStr __cdecl CreateEffectString_guess(EQ_ItemView_guess* item_guess, int* count_guess, ResizeMap_guess* mapA_guess,
                                 ResizeMap_guess* mapB_guess, char flag_guess) {
    TextAppend_guess result_guess;
    MapValue_guess entry_guess;
    int id_guess;
    ItemDef_guess* def_guess;
    char ok_guess = 1;
    char text_guess[1024];
    char line_guess[512];
    text_guess[0] = 0;
    // An item out of charges lists no effects; neither does item state 0x14.
    if (item_guess->HasCharges_guess() != 0 && item_guess->GetCharges_guess() <= 0) {
        ok_guess = 0;
    }
    if (item_guess->GetItemType_guess() != 0x14 && ok_guess != 0) {
        id_guess = item_guess->GetEffectId_guess(0);
        if (IsValidEffect_guess(id_guess)) {
            def_guess = g_itemDb_guess->Get_guess(id_guess);
            entry_guess.values_guess[0] = id_guess;
            entry_guess.values_guess[1] = item_guess->GetEffectLevel_guess(0);
            entry_guess.values_guess[3] = item_guess->GetEffectType_guess(0);
            mapA_guess->Set_guess(mapA_guess->pad_guess[0], &entry_guess);
            // Effect 0 is the click effect: its line depends on the click type (1, 3, 5 and 4 with or
            // without a casting time), then the recast delay and type.
            switch (item_guess->GetEffectType_guess(0)) {
            case 1:
            case 3:
            case 5:
                if (item_guess->GetCastTime_guess() > 0) {
                    sprintf(text_guess, pStringTable->getString(0xbd6, 0), item_guess->GetCastTime_guess() * 0.001);
                } else {
                    CopyString_guess(text_guess, pStringTable->getString(0xbd7, 0));
                }
                break;
            case 4:
                if (item_guess->GetCastTime_guess() > 0) {
                    sprintf(text_guess, pStringTable->getString(0xbd9, 0), item_guess->GetCastTime_guess() * 0.001);
                } else {
                    CopyString_guess(text_guess, pStringTable->getString(0xbda, 0));
                }
                break;
            default:
                CopyString_guess(text_guess, pStringTable->getString(0xbdb, 0));
                break;
            }
            Format_guess(line_guess, 0xbdc, def_guess->name_guess, text_guess, 0, 0, 0, 0, 0, 0, 0);
            result_guess += line_guess;
            result_guess += "<BR>";
            (*count_guess)++;
            if (item_guess->GetRecastTime_guess() > 0) {
                GetTimeStringFromSeconds_guess(line_guess, item_guess->GetRecastTime_guess());
                Format_guess(text_guess, 0x2412, line_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                result_guess += text_guess;
                if (item_guess->GetRecastType_guess() != -1) {
                    result_guess += g_valueSeparator_guess;
                    sprintf(line_guess, "%d", item_guess->GetRecastType_guess());
                    Format_guess(text_guess, 0x2417, line_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    result_guess += text_guess;
                }
                result_guess += "<BR>";
                (*count_guess)++;
            }
        }
        // Effects 1-3: the combat proc, the worn effect and the focus effect, one line each.
        if (item_guess->GetEffectId_guess(1) > 0) {
            def_guess = g_itemDb_guess->Get_guess(item_guess->GetEffectId_guess(1));
            entry_guess.values_guess[0] = item_guess->GetEffectId_guess(1);
            entry_guess.values_guess[1] = item_guess->GetEffectLevel_guess(1);
            entry_guess.values_guess[3] = item_guess->GetEffectType_guess(1);
            entry_guess.values_guess[2] = item_guess->GetEffectExtra_guess(1);
            mapB_guess->Set_guess(mapB_guess->pad_guess[0], &entry_guess);
            CopyString_guess(text_guess, pStringTable->getString(0xbd5, 0));
            Format_guess(line_guess, 0xbdc, def_guess->name_guess, text_guess, 0, 0, 0, 0, 0, 0, 0);
            result_guess += line_guess;
            result_guess += "<BR>";
            (*count_guess)++;
        }
        if (item_guess->GetEffectId_guess(2) > 0) {
            def_guess = g_itemDb_guess->Get_guess(item_guess->GetEffectId_guess(2));
            entry_guess.values_guess[0] = item_guess->GetEffectId_guess(2);
            entry_guess.values_guess[1] = item_guess->GetEffectLevel_guess(2);
            entry_guess.values_guess[3] = item_guess->GetEffectType_guess(2);
            mapB_guess->Set_guess(mapB_guess->pad_guess[0], &entry_guess);
            CopyString_guess(text_guess, pStringTable->getString(0xbd8, 0));
            Format_guess(line_guess, 0xbdc, def_guess->name_guess, text_guess, 0, 0, 0, 0, 0, 0, 0);
            result_guess += line_guess;
            result_guess += "<BR>";
            (*count_guess)++;
        }
        if (item_guess->GetEffectId_guess(3) > 0) {
            def_guess = g_itemDb_guess->Get_guess(item_guess->GetEffectId_guess(3));
            entry_guess.values_guess[0] = item_guess->GetEffectId_guess(3);
            entry_guess.values_guess[1] = item_guess->GetEffectLevel_guess(3);
            entry_guess.values_guess[3] = item_guess->GetEffectType_guess(3);
            mapB_guess->Set_guess(mapB_guess->pad_guess[0], &entry_guess);
            Format_guess(line_guess, 0x159a, def_guess->name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            result_guess += line_guess;
            result_guess += "<BR>";
            (*count_guess)++;
        }
    }
    // With `flag_guess` the five augments add their own effect lines.
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            if (item_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateEffectString_guess(item_guess->GetChild_guess(i_guess), count_guess,
                                                             mapA_guess, mapB_guess, 0));
            }
        }
    }
    return result_guess;
}

// Item size name for sizes 0-3 (table 0x792ED8), else the default string.
// FUNCTION: TITANIUM 0x0051C2E9
void __cdecl GetItemSizeDescription_guess(int index_guess, char* output_guess) {
    const char* value_guess;
    if (index_guess > 3 || index_guess < 0) {
        value_guess = pStringTable->getString(g_defaultStringId_guess, 0);
    } else {
        value_guess = pStringTable->getString(g_stringIds_guess[index_guess], 0);
    }
    CopyString_guess(output_guess, value_guess);
}

struct QueryNode_guess {
    // EXTERNAL: TITANIUM 0x005E0C20 QueryNode_guess::HasFirst_guess
    int HasFirst_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0C50 QueryNode_guess::GetSecond_guess
    int GetSecond_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 QueryNode_guess::GetChild_guess
    QueryNode_guess* GetChild_guess(int index_guess);
};

// "This item has a faction modifier." (3026) and the factions.
// FUNCTION: TITANIUM 0x0051C321
CXStr CreateFactionModString_guess(QueryNode_guess* query_guess, int* count_guess, char flag_guess) {
    char buffer_guess[256];
    CXStr result_guess;
    int matches_guess = 0;
    for (int i_guess = 0; i_guess < 4; i_guess++) {
        if (query_guess->HasFirst_guess(i_guess) && query_guess->GetSecond_guess(i_guess) > 0) {
            matches_guess++;
        }
    }
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            QueryNode_guess* node_guess = query_guess->GetChild_guess(i_guess);
            if (node_guess != 0) {
                for (i_guess = 0; i_guess < 4; i_guess++) {
                    if (node_guess->HasFirst_guess(i_guess) && node_guess->GetSecond_guess(i_guess) > 0) {
                        matches_guess++;
                    }
                }
            }
        }
    }
    if (matches_guess != 0) {
        sprintf(buffer_guess, pStringTable->getString(0xbd2, 0));
        result_guess += buffer_guess;
        result_guess += "<BR>";
        (*count_guess)++;
    }
    return result_guess;
}

// EXTERNAL: TITANIUM 0x006220E9 __itoa
char* __cdecl __itoa(int value_guess, char* buffer_guess, int radix_guess);

#define g_numberBuffer_guess EQ_ARRAY(char, 0x0099DB00)

struct GlobalState_guess {
    // EXTERNAL: TITANIUM 0x004923D5 GlobalState_guess::GetItemClassDesc_guess
    char* GetItemClassDesc_guess(int value_guess);
};

#define g_globalState_guess EQ_GLOBAL(GlobalState_guess*, 0x00988DF0)

struct SkillQuery_guess {
    // EXTERNAL: TITANIUM 0x005E0940 SkillQuery_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005E0B30 SkillQuery_guess::GetSkill_guess
    int GetSkill_guess();
    // EXTERNAL: TITANIUM 0x005E0970 SkillQuery_guess::GetBonus_guess
    int GetBonus_guess();
    // EXTERNAL: TITANIUM 0x005EC630 SkillQuery_guess::GetChild_guess
    SkillQuery_guess* GetChild_guess(int index_guess);
};

#define g_skillNames_guess EQ_ARRAY(int*, 0x00851200)
#define g_bonusBuffer_guess EQ_ARRAY(char, 0x0099DAE0)

// "Skill Mod: %1  +%2 %%" (3025); "INVALID SKILL" for a bad id.
// FUNCTION: TITANIUM 0x0051C45F
CXStr __cdecl CreateSkillModString_guess(SkillQuery_guess* query_guess, int* count_guess, char flag_guess) {
    char buffer_guess[256];
    TextAppend_guess result_guess;
    int value_guess = query_guess->GetValue_guess();
    if (query_guess->GetSkill_guess() != 0 && value_guess != 0) {
        if (query_guess->GetSkill_guess() > 0 && query_guess->GetSkill_guess() < 100) {
            if (query_guess->GetBonus_guess() > 0) {
                Format_guess(buffer_guess, 0xbd1,
                             pStringTable->getString(*g_skillNames_guess[query_guess->GetSkill_guess()], 0),
                             __itoa(value_guess, g_numberBuffer_guess, 10),
                             __itoa(query_guess->GetBonus_guess(), g_bonusBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0);
            } else {
                Format_guess(buffer_guess, 0xbd1,
                             pStringTable->getString(*g_skillNames_guess[query_guess->GetSkill_guess()], 0),
                             __itoa(value_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0);
            }
        } else {
            Format_guess(buffer_guess, 0xbd1, "INVALID SKILL", __itoa(value_guess, g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0);
        }
        result_guess += buffer_guess;
        result_guess += g_brTag_guess;
        (*count_guess)++;
    }
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            if (query_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateSkillModString_guess(query_guess->GetChild_guess(i_guess), count_guess, 0));
            }
        }
    }
    return result_guess;
}

struct SlotQuery_guess {
    // EXTERNAL: TITANIUM 0x005E0190 SlotQuery_guess::GetType_guess
    int GetType_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0230 SlotQuery_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 SlotQuery_guess::GetChild_guess
    SlotQuery_guess* GetChild_guess(int index_guess);
};

// Elemental damage lines, "Magic DMG: %1" .. "Disease DMG: %1" (3017-3021).
// FUNCTION: TITANIUM 0x0051C625
CXStr CreateElementalDamageString_guess(SlotQuery_guess* query_guess, int* count_guess, char flag_guess) {
    char buffer_guess[256];
    TextAppend_guess result_guess;
    if (query_guess->GetType_guess(0) != 0 && query_guess->GetValue_guess(0) != 0) {
        switch (query_guess->GetType_guess(1)) {
        case 1:
            Format_guess(buffer_guess, 0xbc9, __itoa(query_guess->GetValue_guess(1), g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            break;
        case 2:
            Format_guess(buffer_guess, 0xbca, __itoa(query_guess->GetValue_guess(1), g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            break;
        case 3:
            Format_guess(buffer_guess, 0xbcb, __itoa(query_guess->GetValue_guess(1), g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            break;
        case 4:
            Format_guess(buffer_guess, 0xbcc, __itoa(query_guess->GetValue_guess(1), g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            break;
        case 5:
            Format_guess(buffer_guess, 0xbcd, __itoa(query_guess->GetValue_guess(1), g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            break;
        }
        result_guess += buffer_guess;
        result_guess += g_brTag_guess;
        (*count_guess)++;
    }
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            if (query_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateElementalDamageString_guess(query_guess->GetChild_guess(i_guess), count_guess, 0));
            }
        }
    }
    return result_guess;
}

// Instrument modifier, "%1: %2" (5855).
// FUNCTION: TITANIUM 0x0051C854
CXStr __cdecl CreateInstrumentModString_guess(ItemQuery_guess* query_guess, int* count_guess, char flag_guess) {
    int i_guess;
    char buffer_guess[512];
    TextAppend_guess result_guess;
    if (query_guess->FUN_005e0b60_guess() != 0) {
        Format_guess(buffer_guess, 0x16df,
                     g_globalState_guess->GetItemClassDesc_guess(query_guess->FUN_005e0b60_guess()),
                     __itoa(query_guess->GetRank_guess(query_guess->FUN_005e0b60_guess(), 1),
                            g_numberBuffer_guess, 10),
                     0, 0, 0, 0, 0, 0, 0);
        result_guess += buffer_guess;
        result_guess += g_brTag_guess;
        (*count_guess)++;
    }
    if (flag_guess != 0) {
        for (i_guess = 0; i_guess < 5; i_guess++) {
            if (query_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateInstrumentModString_guess(query_guess->GetChild_guess(i_guess),
                                                             count_guess, 0));
            }
        }
    }
    return result_guess;
}

// "Effect: Haste" (5848) with the percent.
// FUNCTION: TITANIUM 0x0051C9C7
CXStr CreateHasteString_guess(ItemQuery_guess* query_guess, int* count_guess, char flag_guess) {
    char buffer_guess[512];
    TextAppend_guess result_guess;
    if (query_guess->GetRankFor_guess(0, 0) != 0) {
        Format_guess(buffer_guess, 0x16d8, __itoa(query_guess->GetRankFor_guess(0, 0), g_numberBuffer_guess, 10),
                     0, 0, 0, 0, 0, 0, 0, 0);
        result_guess += buffer_guess;
        result_guess += g_brTag_guess;
        (*count_guess)++;
    }
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            if (query_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateHasteString_guess(query_guess->GetChild_guess(i_guess), count_guess, 0));
            }
        }
    }
    return result_guess;
}

struct AugQuery_guess {
    // EXTERNAL: TITANIUM 0x005E02D0 AugQuery_guess::GetFirst_guess
    int GetFirst_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0350 AugQuery_guess::GetSecond_guess
    int GetSecond_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0860 AugQuery_guess::GetAmount_guess
    int GetAmount_guess(int second_guess, int first_guess, int flag_guess);
    // EXTERNAL: TITANIUM 0x005EC630 AugQuery_guess::GetChild_guess
    AugQuery_guess* GetChild_guess(int index_guess);
};

struct NameLookup_guess {
    // EXTERNAL: TITANIUM 0x0049273D NameLookup_guess::GetRaceDesc
    char* GetRaceDesc(int value_guess);
    // EXTERNAL: TITANIUM 0x00492438 NameLookup_guess::GetBodyTypeDesc
    char* GetBodyTypeDesc(int value_guess);
};

#define g_nameLookup_guess EQ_GLOBAL(NameLookup_guess*, 0x00988DF0)

// Bane damage by body type or race (3022-3024), then the augments, each "(Augmented)" with its own link.
// FUNCTION: TITANIUM 0x0051CB0B
CXStr CreateBaneDamageString_guess(AugQuery_guess* query_guess, int* count_guess, char flag_guess) {
    char buffer_guess[256];
    TextAppend_guess result_guess;
    int first_guess = query_guess->GetFirst_guess(0);
    int second_guess = query_guess->GetSecond_guess(0);
    int amount_guess = query_guess->GetAmount_guess(second_guess, first_guess, 0);
    if ((first_guess != 0 || second_guess != 0) && amount_guess > 0) {
        buffer_guess[0] = 0;
        if (second_guess != 0 && first_guess == 0) {
            Format_guess(buffer_guess, 0xbce, g_nameLookup_guess->GetRaceDesc(second_guess),
                         __itoa(amount_guess, g_numberBuffer_guess, 10), 0, 0, 0, 0, 0, 0, 0);
        } else if (first_guess != 0 && second_guess == 0) {
            Format_guess(buffer_guess, 0xbcf, g_nameLookup_guess->GetBodyTypeDesc(first_guess),
                         __itoa(amount_guess, g_numberBuffer_guess, 10), 0, 0, 0, 0, 0, 0, 0);
        } else if (first_guess != 0 && second_guess != 0) {
            Format_guess(buffer_guess, 0xbd0, g_nameLookup_guess->GetBodyTypeDesc(first_guess),
                         g_nameLookup_guess->GetRaceDesc(second_guess),
                         __itoa(amount_guess, g_numberBuffer_guess, 10), 0, 0, 0, 0, 0, 0);
        }
        result_guess += buffer_guess;
        result_guess += g_brTag_guess;
        (*count_guess)++;
    }
    if (flag_guess != 0) {
        for (int i_guess = 0; i_guess < 5; i_guess++) {
            if (query_guess->GetChild_guess(i_guess) != 0) {
                result_guess.Append_guess(CreateBaneDamageString_guess(query_guess->GetChild_guess(i_guess), count_guess, 0));
            }
        }
    }
    return result_guess;
}

struct PickEntry_guess : UpdateObject_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess(int flags_guess);
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
    char flag174_guess;
    char pad175_guess[3];
    void* target178_guess;
    ValueSlot_guess* field17c_guess;
    char pad180_guess[4];
    int field184_guess;
    // EXTERNAL: TITANIUM 0x0059DD30 PickEntry_guess::IsActive_guess
    char IsActive_guess();
    // EXTERNAL: TITANIUM 0x0051C119 PickEntry_guess::ShowItemInfo_guess
    void ShowItemInfo_guess(const char* text_guess);
    void Set_guess(int first_guess, char second_guess, int third_guess);
    // EXTERNAL: TITANIUM 0x00521827 PickEntry_guess::SetItem
    void SetItem(int first_guess, unsigned int second_guess);
};

struct PickData_guess {
    char pad0_guess[0x14];
    unsigned int value14_guess;
    char pad18_guess[0x14];
    int value2c_guess;
    char pad30_guess[0x14d];
    unsigned char state17d_guess;
    char pad17e_guess[4];
    unsigned char type182_guess;
    char pad183_guess[9];
    int value18c_guess;
    char pad190_guess[0x78];
    const char* value208_guess;
    char pad20c_guess[0x3c];
    int value248_guess;

    // EXTERNAL: TITANIUM 0x0044E755 PickData_guess::Check_guess
    unsigned char Check_guess(unsigned char value_guess);
};

struct PickDataAccessor_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 PickDataAccessor_guess::GetSpell_guess
    PickData_guess* GetSpell_guess(int value_guess);
};

#define g_pickDataAccessor_guess EQ_GLOBAL(PickDataAccessor_guess*, 0x00985CC8)

struct CharacterMethods_guess {
    // EXTERNAL: TITANIUM 0x0040E2D2 CharacterMethods_guess::GetFirst_guess
    int GetFirst_guess(EQPlayer* player_guess);
    // EXTERNAL: TITANIUM 0x0040D663 CharacterMethods_guess::GetSecond_guess
    int GetSecond_guess(EQPlayer* player_guess, int flag_guess);
};

struct CharacterSystem_guess {
    char pad0_guess[0xc280];
    CharacterMethods_guess methods_guess;
};

#define g_characterSystem_guess EQ_GLOBAL(CharacterSystem_guess*, 0x00905D00)
#define g_skillIds_guess EQ_ARRAY(int*, 0x00851200)
#define g_itemInfoFlag_guess EQ_GLOBAL(int, 0x00923D18)

struct SetTarget_guess {
    // EXTERNAL: TITANIUM 0x004E8BA8 SetTarget_guess::Update_guess
    void Update_guess(SetChild_guess* target_guess, int value_guess, unsigned char type_guess);
};

#define pinstCBuffWindowNORMAL_guess EQ_GLOBAL(SetTarget_guess*, 0x00850C18)

struct PickCharInfo_guess {
    char pad0_guess[0x119c];
    unsigned char field119c_guess;
};

// EXTERNAL: TITANIUM 0x00475855 FormatSpellDescription_guess
void __cdecl FormatSpellDescription_guess(char* destination_guess, PickData_guess* data_guess);

#define g_brText_guess EQ_ARRAY(char, 0x00656A94)

// Shows `first_guess` in this display: title, icon, description and, for scrolls, "Spell:" with skill, mana
// and cast time ("Normal Cast Time: %1    Your Cast Time: %2", 3106) or "CANNOT USE" (3104).
// FUNCTION: TITANIUM 0x0051DA3B
// @early-stop: budget, structural ndiff=86
void PickEntry_guess::Set_guess(int first_guess, char second_guess, int third_guess) {
    char text_guess[512];
    char name_guess[512];
    PickData_guess* data_guess;
    EQ_Character* character_guess;
    CHARINFO2* charInfo_guess;
    unsigned char flag_guess;
    int firstValue_guess;
    int secondValue_guess;
    int adjustedValue_guess;
    double total_guess;

    flag174_guess = 0;
    data_guess = g_pickDataAccessor_guess->GetSpell_guess(first_guess);
    value_guess.Clear_guess();
    value_guess.Append_guess(pStringTable->getString(0xc1d, 0));
    value_guess.Append_guess(g_brText_guess);
    value_guess.Append_guess(data_guess->value208_guess);
    ref_guess.Clear_guess();

    if (second_guess != 0) {
        character_guess = pCharData;
        charInfo_guess = character_guess->GetCharInfo2();
        flag_guess = data_guess->Check_guess(((PickCharInfo_guess*)charInfo_guess)->field119c_guess);
        if (flag_guess == 0xff && third_guess == -1) {
            ref_guess.Append_guess(pStringTable->getString(0xc20, 0));
            ref_guess.Append_guess(g_brTag_guess);
        } else {
            Format_guess(text_guess, 0x1fa, __itoa(flag_guess, g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            ref_guess.Append_guess(text_guess);
            ref_guess.Append_guess(g_brTag_guess);
            Format_guess(text_guess, 0xc21,
                         pStringTable->getString(*g_skillIds_guess[data_guess->type182_guess], 0),
                         0, 0, 0, 0, 0, 0, 0, 0);
            ref_guess.Append_guess(text_guess);
            ref_guess.Append_guess(g_brTag_guess);
            if (data_guess->value2c_guess > 0) {
                Format_guess(text_guess, 0xbbe,
                             __itoa(data_guess->value2c_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
                ref_guess.Append_guess(text_guess);
            }
            ref_guess.Append_guess(g_brTag_guess);

            charInfo_guess = pCharData->GetCharInfo2();
            if (((PickCharInfo_guess*)charInfo_guess)->field119c_guess != 8) {
                firstValue_guess = g_characterSystem_guess->methods_guess.GetFirst_guess((EQPlayer*)data_guess);
                secondValue_guess = g_characterSystem_guess->methods_guess.GetSecond_guess((EQPlayer*)data_guess, 0);
                total_guess = (double)data_guess->value14_guess;
                total_guess += (double)secondValue_guess + (double)firstValue_guess;
                adjustedValue_guess = (int)total_guess;
                if (adjustedValue_guess < (int)data_guess->value14_guess / 2) {
                    adjustedValue_guess = (int)(data_guess->value14_guess >> 1);
                }
                sprintf(g_numberBuffer_guess, "%4.1f", (double)data_guess->value14_guess * 0.001f);
                if (secondValue_guess == 0 && firstValue_guess == 0) {
                    Format_guess(text_guess, 0xc23, g_numberBuffer_guess,
                                 0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    sprintf(g_bonusBuffer_guess, "%4.1f", (double)((float)adjustedValue_guess * 0.001f));
                    Format_guess(text_guess, 0xc22, g_numberBuffer_guess, g_bonusBuffer_guess,
                                 0, 0, 0, 0, 0, 0, 0);
                }
                ref_guess.Append_guess(text_guess);
            }
            ref_guess.Append_guess(g_brTag_guess);
            if (g_itemInfoFlag_guess != 0 && data_guess->value18c_guess != 0) {
                FormatSpellDescription_guess(name_guess, data_guess);
                Format_guess(text_guess, 0x213b, name_guess,
                             0, 0, 0, 0, 0, 0, 0, 0);
                ref_guess.Append_guess(g_brTag_guess);
                ref_guess.Append_guess(text_guess);
                ref_guess.Append_guess(g_brTag_guess);
            }
        }
    }

    field164_guess->field16c_guess = target178_guess;
    if (data_guess->value248_guess >= 0) {
        pinstCBuffWindowNORMAL_guess->Update_guess(field164_guess, data_guess->value248_guess, data_guess->state17d_guess);
    } else {
        pinstCBuffWindowNORMAL_guess->Update_guess(field164_guess, 0, data_guess->state17d_guess);
    }
    Update_guess();
}

struct PickActiveMap_guess {
    int count_guess;                     // 0x0
    int pad4_guess;                      // 0x4
    int mask_guess;                      // 0x8
    int shift_guess;                     // 0xC
    PickEntry_guess*** buckets_guess;    // 0x10
    int pad14_guess[2];                  // 0x14

    // EXTERNAL: TITANIUM 0x0040600C PickActiveMap_guess::Set_guess
    void Set_guess(int index_guess, PickEntry_guess* const& value_guess);
    // EXTERNAL: TITANIUM 0x004B73EE PickActiveMap_guess::~PickActiveMap_guess
    ~PickActiveMap_guess();
    // EXTERNAL: TITANIUM 0x004B73EE PickActiveMap_guess::Clear_guess
    void Clear_guess();
};

// The int table; its cleanup is out of line at 0x004B73EE (landed in tu_077_ItemMoveQueue.cpp). The body stays
// visible here so the owner's dtor sees it is nothrow; crt_defaults.json maps the symbol to 0x004B73EE.
struct DialogTable_guess {
    int count_guess;                 // 0x0
    int pad4_guess;                  // 0x4
    int mask_guess;                  // 0x8
    int shift_guess;                 // 0xC
    int** buckets_guess;             // 0x10
    int chunkCount_guess;            // 0x14
    int pad18_guess;                 // 0x18

    int At_guess(int index_guess) {
        return buckets_guess[index_guess >> shift_guess][index_guess & mask_guess];
    }

    // EXTERNAL: TITANIUM 0x0040600C DialogTable_guess::Set_guess
    void Set_guess(int index_guess, const int& value_guess);
    ~DialogTable_guess();
};

typedef DialogTable_guess PickValueMap_guess;

DialogTable_guess::~DialogTable_guess() {
    for (int i_guess = 0; i_guess < chunkCount_guess; i_guess++) {
        _free(buckets_guess[i_guess]);
    }
    _free(buckets_guess);
    buckets_guess = 0;
    chunkCount_guess = 0;
    count_guess = 0;
}

struct PickManager_guess {
    PickActiveMap_guess active_guess;    // 0x0
    PickValueMap_guess values_guess;     // 0x1C
    int limit_guess;                     // 0x38

    ~PickManager_guess();
    char CloseNewestItemDisplay_guess();
    void CloseAllItemDisplays_guess();
    void ShowEntryInfo_guess(const char* text_guess, int index_guess);
    void Set_guess(int first_guess, bool key_guess, int second_guess, int third_guess);
    void SetRaw_guess(int first_guess, unsigned int key_guess);
    int Key_guess(bool value_guess);
};

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
unsigned int __cdecl FUN_0046d655_guess();


// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct CXStrCapacity_guess : CXStr {
    // EXTERNAL: TITANIUM 0x00572040 CXStrCapacity_guess::SetCapacity_guess
    void SetCapacity_guess(int capacity_guess);
};

struct ButtonInfo_guess {
    char data_guess[0x4c];
    // EXTERNAL: TITANIUM 0x0060D071 ??2ButtonInfo_guess@@SAPAXI@Z
    static void* __cdecl operator new(unsigned int size_guess);
    // EXTERNAL: TITANIUM 0x005B1D90 ButtonInfo_guess::ButtonInfo_guess
    ButtonInfo_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ButtonInfo_guess::Bind_guess
    void Bind_guess(CXWnd* child_guess);
};

struct ButtonInfoManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 ButtonInfoManager_guess::Get_guess
    CXWnd* Get_guess(const CXStr& name_guess);
};

struct ItemDescriptionControl_guess : CXWnd {
    char pad11c_guess[0x58];
    int field174_guess;
};

// EXTERNAL: TITANIUM 0x00656948 ??_7CItemDisplayWnd_guess@@6B@
struct CItemDisplayWnd_guess : CSidlScreenWndBase {
    ItemDescriptionControl_guess* itemDescription_guess; // 0x15c
    char pad160_guess[4];                                // 0x160
    CXWnd* iconButton_guess;                             // 0x164
    CXStrCapacity_guess errorText_guess;                 // 0x168
    CXStrCapacity_guess titleText_guess;                 // 0x16c
    int field170_guess;                                  // 0x170
    unsigned char field174_guess;                        // 0x174
    char pad175_guess[3];
    ButtonInfo_guess* spellIcons_guess;                  // 0x178
    ButtonInfo_guess* dragItem_guess;                    // 0x17c
    char pad180_guess[4];
    int index184_guess;                  // 0x184

    // EXTERNAL: TITANIUM 0x0060D071 ??2CItemDisplayWnd_guess@@SAPAXI@Z
    static void* __cdecl operator new(unsigned int size_guess);
    CItemDisplayWnd_guess(CXWnd* parent_guess);
    // EXTERNAL: TITANIUM 0x0059DB90 CItemDisplayWnd_guess::Enable_guess
    void Enable_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0059FA70 CItemDisplayWnd_guess::Move_guess
    void Move_guess(const int* point_guess);
};

// Destructor: each active entry runs virtual slot 34 and is deleted (virtual slot 1 with flag 1), then
// the chunked array is freed.
// FUNCTION: TITANIUM 0x0051E027
// @early-stop: budget, structural ndiff=1
PickManager_guess::~PickManager_guess() {
    for (int i_guess = 0; i_guess < active_guess.count_guess; i_guess++) {
        PickEntry_guess* entry_guess =
            active_guess.buckets_guess[i_guess >> active_guess.shift_guess][i_guess & active_guess.mask_guess];
        entry_guess->Slot34_guess();
        entry_guess->Slot01_guess(1);
    }
    active_guess.Clear_guess();
}

// Shows a text in pool window `index_guess`.
// FUNCTION: TITANIUM 0x0051E099
void PickManager_guess::ShowEntryInfo_guess(const char* text_guess, int index_guess) {
    if (index_guess >= 0 && index_guess < active_guess.count_guess) {
        if (active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]->IsActive_guess()) {
            active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]->ShowItemInfo_guess(text_guess);
        }
    }
}

// Closes the newest open item display window: of the pooled windows that are visible (0x0059DD30), the one
// with the latest time stamp in the parallel array gets Deactivate (vtable +0x88). Returns 1 when one was
// closed.
// FUNCTION: TITANIUM 0x0051E0EA
char PickManager_guess::CloseNewestItemDisplay_guess() {
    char result_guess = 0;
    int bestIndex_guess = -1;
    int bestValue_guess = 0;
    for (int i_guess = 0; i_guess < active_guess.count_guess; i_guess++) {
        if (active_guess.buckets_guess[i_guess >> active_guess.shift_guess][i_guess & active_guess.mask_guess]->IsActive_guess()) {
            if (values_guess.At_guess(i_guess) > bestValue_guess) {
                bestIndex_guess = i_guess;
                bestValue_guess = values_guess.At_guess(i_guess);
            }
        }
    }
    if (bestIndex_guess >= 0) {
        active_guess.buckets_guess[bestIndex_guess >> active_guess.shift_guess][bestIndex_guess & active_guess.mask_guess]->Slot34_guess();
        result_guess = 1;
    }
    return result_guess;
}

// Closes every visible item display window (Deactivate, vtable +0x88).
// FUNCTION: TITANIUM 0x0051E180
void PickManager_guess::CloseAllItemDisplays_guess() {
    for (int i_guess = 0; i_guess < active_guess.count_guess; i_guess++) {
        if (active_guess.buckets_guess[i_guess >> active_guess.shift_guess][i_guess & active_guess.mask_guess]->IsActive_guess()) {
            active_guess.buckets_guess[i_guess >> active_guess.shift_guess][i_guess & active_guess.mask_guess]->Slot34_guess();
        }
    }
}

struct DisplayItemBase_guess {
    // EXTERNAL: TITANIUM 0x004B1C4D DisplayItemBase_guess::GetContainerRestrictionId_guess
    int GetContainerRestrictionId_guess();
};

struct DisplayChild_guess {
    // EXTERNAL: TITANIUM 0x005E0EC0 DisplayChild_guess::GetName_guess
    char* GetName_guess();
};

struct DisplayItem_guess {
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
    virtual DisplayItemBase_guess* Slot10_guess();
    char pad4_guess[0x54];
    int charges_guess; // 0x58
    char pad5c_guess[4];
    char flag60_guess; // 0x60

    // EXTERNAL: TITANIUM 0x005ECCC0 DisplayItem_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005E0EE0 DisplayItem_guess::GetIdText_guess
    char* GetIdText_guess();
    // EXTERNAL: TITANIUM 0x005EC790 DisplayItem_guess::HasLore_guess
    char HasLore_guess();
    // EXTERNAL: TITANIUM 0x005EC7F0 DisplayItem_guess::GetLoreId_guess
    int GetLoreId_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 DisplayItem_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E11A0 DisplayItem_guess::GetEffectType_guess
    int GetEffectType_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005ECD20 DisplayItem_guess::GetEffectId_guess
    int GetEffectId_guess(int slot_guess);
    // EXTERNAL: TITANIUM 0x005ECC90 DisplayItem_guess::GetMaxCharges_guess
    int GetMaxCharges_guess();
    // EXTERNAL: TITANIUM 0x005E00A0 DisplayItem_guess::Check00a0_guess
    char Check00a0_guess();
    // EXTERNAL: TITANIUM 0x005EC8B0 DisplayItem_guess::GetBitsAlt_guess
    unsigned int GetBitsAlt_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005E1640 DisplayItem_guess::Check1640_guess
    char Check1640_guess();
    // EXTERNAL: TITANIUM 0x005E0E90 DisplayItem_guess::Get0e90_guess
    int Get0e90_guess();
    // EXTERNAL: TITANIUM 0x005E2350 DisplayItem_guess::GetDamage_guess
    int GetDamage_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0BF0 DisplayItem_guess::Get0bf0_guess
    int Get0bf0_guess();
    // EXTERNAL: TITANIUM 0x005E0540 DisplayItem_guess::GetArmor_guess
    int GetArmor_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E09A0 DisplayItem_guess::Check09a0_guess
    char Check09a0_guess();
    // EXTERNAL: TITANIUM 0x005E1710 DisplayItem_guess::Stat1710_guess
    int Stat1710_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E18D0 DisplayItem_guess::Stat18d0_guess
    int Stat18d0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E17F0 DisplayItem_guess::Stat17f0_guess
    int Stat17f0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1B70 DisplayItem_guess::Stat1b70_guess
    int Stat1b70_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1A90 DisplayItem_guess::Stat1a90_guess
    int Stat1a90_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1C50 DisplayItem_guess::Stat1c50_guess
    int Stat1c50_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E19B0 DisplayItem_guess::Stat19b0_guess
    int Stat19b0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2190 DisplayItem_guess::Stat2190_guess
    int Stat2190_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2270 DisplayItem_guess::Stat2270_guess
    int Stat2270_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1200 DisplayItem_guess::Stat1200_guess
    int Stat1200_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1E10 DisplayItem_guess::Stat1e10_guess
    int Stat1e10_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1FD0 DisplayItem_guess::Stat1fd0_guess
    int Stat1fd0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E20B0 DisplayItem_guess::Stat20b0_guess
    int Stat20b0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1D30 DisplayItem_guess::Stat1d30_guess
    int Stat1d30_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E1EF0 DisplayItem_guess::Stat1ef0_guess
    int Stat1ef0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2C10 DisplayItem_guess::Stat2c10_guess
    int Stat2c10_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2CF0 DisplayItem_guess::Stat2cf0_guess
    int Stat2cf0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2DD0 DisplayItem_guess::Stat2dd0_guess
    int Stat2dd0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2EB0 DisplayItem_guess::Stat2eb0_guess
    int Stat2eb0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E3080 DisplayItem_guess::Stat3080_guess
    int Stat3080_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2B30 DisplayItem_guess::Stat2b30_guess
    int Stat2b30_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2430 DisplayItem_guess::Stat2430_guess
    int Stat2430_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2510 DisplayItem_guess::Stat2510_guess
    int Stat2510_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E25F0 DisplayItem_guess::Stat25f0_guess
    int Stat25f0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E26D0 DisplayItem_guess::Stat26d0_guess
    int Stat26d0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2880 DisplayItem_guess::Stat2880_guess
    int Stat2880_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E2960 DisplayItem_guess::Stat2960_guess
    int Stat2960_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E27A0 DisplayItem_guess::Stat27a0_guess
    int Stat27a0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0DD0 DisplayItem_guess::Stat0dd0_guess
    int Stat0dd0_guess();
    // EXTERNAL: TITANIUM 0x005E0B00 DisplayItem_guess::GetSkillMod_guess
    int GetSkillMod_guess();
    // EXTERNAL: TITANIUM 0x005E0AA0 DisplayItem_guess::Get0aa0_guess
    int Get0aa0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E04C0 DisplayItem_guess::GetRecommendedLevel_guess
    int GetRecommendedLevel_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005ECAA0 DisplayItem_guess::Getcaa0_guess
    int Getcaa0_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005ECA30 DisplayItem_guess::GetSize_guess
    int GetSize_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005E0130 DisplayItem_guess::GetWeight_guess
    int GetWeight_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005EC850 DisplayItem_guess::Getc850_guess
    int Getc850_guess(int flag_guess);
    // EXTERNAL: TITANIUM 0x005EC990 DisplayItem_guess::GetRaces_guess
    unsigned int GetRaces_guess(int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005E0D00 DisplayItem_guess::HasFirst_guess
    char HasFirst_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0CC0 DisplayItem_guess::HasSecond_guess
    char HasSecond_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0C80 DisplayItem_guess::GetSlotType_guess
    int GetSlotType_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005EC630 DisplayItem_guess::GetChild_guess
    DisplayChild_guess* GetChild_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005DFCC0 DisplayItem_guess::Checkdfcc0_guess
    char Checkdfcc0_guess();
    // EXTERNAL: TITANIUM 0x005ECC60 DisplayItem_guess::Getcc60_guess
    int Getcc60_guess();
    // EXTERNAL: TITANIUM 0x005E0E00 DisplayItem_guess::Get0e00_guess
    int Get0e00_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 DisplayItem_guess::Getcc30_guess
    int Getcc30_guess();
    // EXTERNAL: TITANIUM 0x005E0E30 DisplayItem_guess::Check0e30_guess
    char Check0e30_guess();
    // EXTERNAL: TITANIUM 0x005DFCD0 DisplayItem_guess::Getdfcd0_guess
    int Getdfcd0_guess();
};

struct DisplaySpell_guess {
    char pad0_guess[0x2c];
    int value2c_guess; // 0x2C
    char pad30_guess[0x152];
    unsigned char type182_guess; // 0x182
    char pad183_guess[9];
    int value18c_guess; // 0x18C
    char pad190_guess[0x34];
    char flag1c4_guess; // 0x1C4
    char pad1c5_guess[0x43];
    char* name208_guess; // 0x208

    // EXTERNAL: TITANIUM 0x0044E755 DisplaySpell_guess::Check_guess
    unsigned char Check_guess(unsigned char value_guess);
};

struct DisplaySpellDb_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 DisplaySpellDb_guess::Get_guess
    DisplaySpell_guess* Get_guess(int id_guess);
};

struct DisplayDbStr_guess {
    // EXTERNAL: TITANIUM 0x004355F7 DisplayDbStr_guess::Get_guess
    char* Get_guess(int id_guess, int type_guess, bool* found_guess);
};

struct DisplayPlayer_guess {
    char pad0_guess[0x4c];
    float value4c_guess; // 0x4C
    // EXTERNAL: TITANIUM 0x00479D99 DisplayPlayer_guess::Adjust_guess
    unsigned char Adjust_guess(int value_guess);
};

struct DisplayCharPad_guess {
    char pad0_guess[0xc280];
};

struct DisplayCharBase_guess {
    int first_guess;
    // EXTERNAL: TITANIUM 0x0041C7C1 DisplayCharBase_guess::ApplyRank_guess
    int ApplyRank_guess(DisplayItem_guess* item_guess, int rank_guess, int adjusted_guess);
    // EXTERNAL: TITANIUM 0x00417C33 DisplayCharBase_guess::FindSkill_guess
    int FindSkill_guess(int value_guess);
};

struct DisplayChar_guess : DisplayCharPad_guess, DisplayCharBase_guess {};

struct DisplayNames_guess {
    // EXTERNAL: TITANIUM 0x0049275D DisplayNames_guess::GetDeityDesc
    char* GetDeityDesc(int value_guess);
};

// EXTERNAL: TITANIUM 0x0046E0A5 GetWeaponDamageBonus_guess
int __cdecl GetWeaponDamageBonus_guess(DisplayCharBase_guess* base_guess, DisplayItem_guess* item_guess);

// EXTERNAL: TITANIUM 0x005A40F0 ColorTag_guess
CXStr __cdecl ColorTag_guess(unsigned int color_guess);

// EXTERNAL: TITANIUM 0x0060E460 _strcat
extern "C" char* __cdecl strcat(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x0060D970 _strlen
extern "C" unsigned int __cdecl strlen(const char* text_guess);

#define g_displaySpellDb_guess EQ_GLOBAL(DisplaySpellDb_guess*, 0x00985CC8)
#define g_displayDbStr_guess EQ_GLOBAL(DisplayDbStr_guess*, 0x00850398)
#define g_displayPlayer_guess EQ_GLOBAL(DisplayPlayer_guess*, 0x00905CE4)
#define g_displayChar_guess EQ_GLOBAL(DisplayChar_guess*, 0x00905D00)
#define g_displayNames_guess EQ_GLOBAL(DisplayNames_guess*, 0x00988DF0)
#define g_showItemId_guess EQ_GLOBAL(int, 0x00923D68)
#define g_flag9247b0_guess EQ_GLOBAL(int, 0x009247B0)
#define g_colorOpen_guess EQ_ARRAY(char, 0x00656738)
#define g_colorClose_guess EQ_ARRAY(char, 0x00641684)

// Style 0x800/0x400/0x100 on the description; icons from A_SpellIcons and A_DragItem; the window title.
// FUNCTION: TITANIUM 0x0051E7DC
CItemDisplayWnd_guess::CItemDisplayWnd_guess(CXWnd* parent_guess)
    : CSidlScreenWndBase(parent_guess, "ItemDisplayWindow") {
    field170_guess = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();

        itemDescription_guess = (ItemDescriptionControl_guess*)((CSidlScreenWnd*)this)->GetChildItem("ItemDescription");
        if (itemDescription_guess != 0) {
            itemDescription_guess->Unknown0x060 = 0;
            if (EQ_GLOBAL(int, 0x00923D74) == 0) {
                itemDescription_guess->field174_guess = -2;
            }
        }

        iconButton_guess = ((CSidlScreenWnd*)this)->GetChildItem("IconButton");

        spellIcons_guess = new ButtonInfo_guess;
        CXWnd* spellChild_guess = EQ_GLOBAL(ButtonInfoManager_guess*, 0x0099D3F4)->Get_guess("A_SpellIcons");
        spellIcons_guess->Bind_guess(spellChild_guess);

        dragItem_guess = new ButtonInfo_guess;
        CXWnd* dragChild_guess = EQ_GLOBAL(ButtonInfoManager_guess*, 0x0099D3F4)->Get_guess("A_DragItem");
        dragItem_guess->Bind_guess(dragChild_guess);

        errorText_guess.SetCapacity_guess(0x400);
        titleText_guess.SetCapacity_guess(0x100);
        errorText_guess += "Error: Item description not set";
        titleText_guess += "Item Display";
        Enable_guess(100);
        field174_guess = 0;
    }
}

// The full item description (STML): name, stats with their bonuses, resists, weight and size, then each of
// the Create*String sections above.
// FUNCTION: TITANIUM 0x0051EA25
// @early-stop: budget, structural ndiff=361
CXStr __cdecl BuildItemDescription_guess(DisplayItem_guess* item_guess, int flags_guess) {
    CXStr unused_guess;
    TextAppend_guess result_guess;
    int count_guess = 0;
    char text_guess[1024];
    // The Item Display text, built as HTML with <BR> line breaks. Item class 0 is a common item, 1 a
    // container, 2 a book; with the show-item-id option the id comes first (0xBE8). Item types are EQEmu's
    // ItemType numbers (20 scroll, 27 arrow, 54 augment...).
    if (item_guess->GetItemClass_guess() == 0) {
        ResizeMap_guess mapA_guess(0x20);
        ResizeMap_guess mapB_guess(0x20);
        char dmgText_guess[256];
        char name_guess[1024];
        if (g_showItemId_guess != 0) {
            result_guess += pStringTable->getString(0xbe8, 0);
            result_guess += item_guess->GetIdText_guess();
            result_guess += g_brTag_guess;
            count_guess++;
        }
        CXStr temp_guess;
        temp_guess = CreateEquipmentStatusString_guess((ItemState_guess*)item_guess);
        result_guess.Append_guess(temp_guess);
        result_guess += g_brTag_guess;
        count_guess++;
        // The flag words under the name (lore is 0x1806).
        if (item_guess->HasLore_guess()) {
            if (item_guess->GetLoreId_guess() != -1) {
                bool found_guess = false;
                char* lore_guess = g_displayDbStr_guess->Get_guess(item_guess->GetLoreId_guess(), 7, &found_guess);
                if (found_guess) {
                    temp_guess = pStringTable->getString(0x1806, 0);
                    temp_guess += lore_guess;
                    result_guess.Append_guess(temp_guess);
                    result_guess += g_brTag_guess;
                    count_guess++;
                }
            }
        }
        if (item_guess->flag60_guess != 0) {
            temp_guess = CreateEvolvingString_guess((Owner_guess*)item_guess);
            result_guess.Append_guess(temp_guess);
            result_guess += g_brTag_guess;
            count_guess++;
        }
        if (item_guess->GetItemType_guess() == 0x36) {
            result_guess.Append_guess(CreateAugmentSlotTypeString_guess((ItemFlags_guess*)item_guess));
            result_guess += g_brTag_guess;
            count_guess++;
        } else {
            result_guess.Append_guess(CreateSlotString_guess((ItemOwner_guess*)item_guess, &count_guess));
            if (item_guess->GetEffectType_guess(0) != 3 && item_guess->GetItemType_guess() != 0x15) {
                if (IsValidEffect_guess(item_guess->GetEffectId_guess(0)) && item_guess->GetMaxCharges_guess() > 0) {
                    if (item_guess->charges_guess > 0) {
                        Format_guess(text_guess, 0xbbb, __itoa(item_guess->charges_guess, g_numberBuffer_guess, 10),
                                     0, 0, 0, 0, 0, 0, 0, 0);
                    } else {
                        CopyString_guess(text_guess, pStringTable->getString(0xbba, 0));
                    }
                    result_guess += text_guess;
                    result_guess += g_brTag_guess;
                    count_guess++;
                }
            } else {
                int charges_guess = item_guess->charges_guess;
                Format_guess(text_guess, 0xbb9, __itoa(charges_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
                result_guess += text_guess;
                result_guess += g_brTag_guess;
                count_guess++;
            }
            if (g_flag9247b0_guess != 0 && item_guess->Check00a0_guess()) {
                result_guess += pStringTable->getString(0x248a, 0);
                result_guess += g_brTag_guess;
                count_guess++;
            }
        }
        // Scrolls list the classes (and levels) that can scribe the spell, and its skill.
        if (item_guess->GetItemType_guess() == 0x14) {
            DisplaySpell_guess* spell_guess = g_displaySpellDb_guess->Get_guess(item_guess->GetEffectId_guess(4));
            int value18c_guess = spell_guess->value18c_guess;
            char classText_guess[256];
            char small_guess[20];
            classText_guess[0] = 0;
            int i_guess = 1;
            int* id_guess = g_itemIds_guess;
            do {
                int bit_guess = 1 << (i_guess - 1);
                if ((bit_guess & item_guess->GetBitsAlt_guess(1, 0)) != 0) {
                    sprintf(small_guess, "%s(%d) ", pStringTable->getString(*id_guess, 0),
                            spell_guess->Check_guess(i_guess));
                    strcat(classText_guess, small_guess);
                }
                i_guess++;
                id_guess++;
            } while ((int)id_guess <= (int)g_itemIdsEnd_guess);
            if (strlen(classText_guess) > 0) {
                Format_guess(text_guess, 0xbbc, classText_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                result_guess += text_guess;
                result_guess += g_brTag_guess;
                count_guess++;
            }
            Format_guess(text_guess, 0x30a5,
                         pStringTable->getString(*g_skillNames_guess[spell_guess->type182_guess], 0),
                         0, 0, 0, 0, 0, 0, 0, 0);
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
            Format_guess(text_guess, 0xbbe, __itoa(spell_guess->value2c_guess, g_numberBuffer_guess, 10),
                         0, 0, 0, 0, 0, 0, 0, 0);
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
            if (g_itemInfoFlag_guess != 0 && value18c_guess != 0) {
                FormatSpellDescription_guess(name_guess, (PickData_guess*)spell_guess);
                Format_guess(text_guess, spell_guess->flag1c4_guess == 0 ? 0x213b : 0x16b4, name_guess,
                             0, 0, 0, 0, 0, 0, 0, 0);
                result_guess += text_guess;
                result_guess += g_brTag_guess;
                count_guess++;
            }
        }
        // Weapons and ammunition name their skill (arrows: archery, 7).
        if (item_guess->Check1640_guess() || item_guess->GetItemType_guess() == 0x1b ||
            item_guess->GetItemType_guess() == 0x1c) {
            int skill_guess = g_displayPlayer_guess->Adjust_guess(item_guess->GetItemType_guess());
            if (item_guess->GetItemType_guess() == 0x1b) {
                skill_guess = 7;
            }
            if (item_guess->GetItemType_guess() == 0x1c) {
                skill_guess = 7;
            }
            if (item_guess->GetItemType_guess() == 0x13) {
                skill_guess = 0x33;
            }
            if (skill_guess != 0x1c || item_guess->GetItemType_guess() == 0x2d) {
                if (item_guess->GetItemType_guess() == 0x23) {
                    Format_guess(text_guess, 0xbbf, __itoa(item_guess->Get0e90_guess(), g_numberBuffer_guess, 10),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                } else {
                    Format_guess(text_guess, 0xbc0, pStringTable->getString(*g_skillNames_guess[skill_guess], 0),
                                 __itoa(item_guess->Get0e90_guess(), g_numberBuffer_guess, 10),
                                 0, 0, 0, 0, 0, 0, 0);
                }
                result_guess += text_guess;
                result_guess += g_brTag_guess;
                count_guess++;
            }
        }
        if (item_guess->GetItemType_guess() == 0x28 && (flags_guess & 4) == 0) {
            int light_guess = (int)g_displayPlayer_guess->value4c_guess;
            char lightText_guess[100];
            CopyString_guess(lightText_guess, g_emptyText_guess);
            if ((short)light_guess >= 0x1e0) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308b, 0));
            } else if ((short)light_guess > 0x1a0) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308c, 0));
            } else if ((short)light_guess > 0x160) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308d, 0));
            } else if ((short)light_guess > 0x120) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308e, 0));
            } else if ((short)light_guess > 0xe0) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308f, 0));
            } else if ((short)light_guess > 0xa0) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x3090, 0));
            } else if ((short)light_guess > 0x60) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x3091, 0));
            } else if ((short)light_guess > 0x20) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x3092, 0));
            } else if ((short)light_guess >= 0) {
                CopyString_guess(lightText_guess, pStringTable->getString(0x308b, 0));
            }
            Format_guess(text_guess, 0xbc1, lightText_guess, 0, 0, 0, 0, 0, 0, 0, 0);
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        int applied_guess = 0;
        dmgText_guess[0] = 0;
        int damage_guess = item_guess->GetDamage_guess(1);
        if (damage_guess != 0) {
            if (item_guess->Get0bf0_guess() == 0) {
                applied_guess = g_displayChar_guess->ApplyRank_guess(
                    item_guess, item_guess->GetDamage_guess(1),
                    g_displayPlayer_guess->Adjust_guess(item_guess->GetItemType_guess()));
            }
            if (applied_guess < damage_guess && item_guess->Get0bf0_guess() == 0) {
                Format_guess(dmgText_guess, 0xbc7, __itoa(applied_guess, g_numberBuffer_guess, 10),
                             __itoa(item_guess->GetDamage_guess(1), g_bonusBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0);
            } else {
                Format_guess(dmgText_guess, 0xbc8, __itoa(damage_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
            }
        }
        // AC, shown as current/maximum when both apply, else the damage/delay text.
        if (item_guess->GetArmor_guess(1) > 0) {
            char acText_guess[128];
            int base_guess = GetWeaponDamageBonus_guess(g_displayChar_guess, item_guess);
            acText_guess[0] = 0;
            if (base_guess > 0 && item_guess->GetItemType_guess() != 0x36) {
                Format_guess(acText_guess, 0xbc2, __itoa(base_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
            }
            int armor_guess = g_displayChar_guess->ApplyRank_guess(
                item_guess, item_guess->GetArmor_guess(1),
                g_displayPlayer_guess->Adjust_guess(item_guess->GetItemType_guess()));
            if (damage_guess != 0) {
                if (armor_guess < item_guess->GetArmor_guess(1)) {
                    Format_guess(text_guess, 0xbc3, __itoa(armor_guess, g_numberBuffer_guess, 10),
                                 __itoa(item_guess->GetArmor_guess(1), g_bonusBuffer_guess, 10), acText_guess,
                                 dmgText_guess, 0, 0, 0, 0, 0);
                } else {
                    Format_guess(text_guess, 0xbc4, __itoa(armor_guess, g_numberBuffer_guess, 10), acText_guess,
                                 dmgText_guess, 0, 0, 0, 0, 0, 0);
                }
            } else {
                if (armor_guess < item_guess->GetArmor_guess(1)) {
                    Format_guess(text_guess, 0xbc5, __itoa(armor_guess, g_numberBuffer_guess, 10),
                                 __itoa(item_guess->GetArmor_guess(1), g_bonusBuffer_guess, 10), acText_guess,
                                 0, 0, 0, 0, 0, 0);
                } else {
                    Format_guess(text_guess, 0xbc6, __itoa(armor_guess, g_numberBuffer_guess, 10), acText_guess,
                                 0, 0, 0, 0, 0, 0, 0);
                }
            }
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
            sprintf(name_guess, "%d/%d", item_guess->GetArmor_guess(1), item_guess->Get0e90_guess());
            Format_guess(text_guess, 0xbc6, name_guess, g_emptyText_guess, 0, 0, 0, 0, 0, 0, 0);
        } else if (dmgText_guess[0] != 0) {
            result_guess += dmgText_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        CXStr slots_guess = CreateElementalDamageString_guess((SlotQuery_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(slots_guess);
        CXStr augs_guess = CreateBaneDamageString_guess((AugQuery_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(augs_guess);
        CXStr skills_guess = CreateSkillModString_guess((SkillQuery_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(skills_guess);
        CXStr nodes_guess = CreateFactionModString_guess((QueryNode_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(nodes_guess);
        CXStr effects_guess =
            CreateEffectString_guess((EQ_ItemView_guess*)item_guess, &count_guess, &mapA_guess, &mapB_guess, 1);
        result_guess.Append_guess(effects_guess);
        if (item_guess->Check09a0_guess()) {
            sprintf(text_guess, pStringTable->getString(0x236b, 0));
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        int stats_guess = 0;
        CopyString_guess(text_guess, g_emptyText_guess);
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1710_guess(1),
                                                     0x30a9, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat18d0_guess(1),
                                                     0x30aa, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat17f0_guess(1),
                                                     0x30ab, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1b70_guess(1),
                                                     0x30ac, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1a90_guess(1),
                                                     0x30ad, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1c50_guess(1),
                                                     0x30ae, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat19b0_guess(1),
                                                     0x30af, &stats_guess));
        // Stat, HP/mana/endurance and resist bonuses (strings 0x30AB on); a <BR> after every few keeps lines
        // short.
        if (stats_guess > 5) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2190_guess(1),
                                                     0x30b0, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2270_guess(1),
                                                     0x30b1, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1200_guess(1),
                                                     0x16b1, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1e10_guess(1),
                                                     0x30b2, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1fd0_guess(1),
                                                     0x30b3, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat20b0_guess(1),
                                                     0x30b4, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1d30_guess(1),
                                                     0x30b5, &stats_guess));
        if (count_guess < 4 && stats_guess > 3) {
            result_guess += g_brTag_guess;
            count_guess++;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat1ef0_guess(1),
                                                     0x30b6, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2c10_guess(1),
                                                     0x16d4, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2cf0_guess(1),
                                                     0x16d5, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2dd0_guess(1),
                                                     0x16d6, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2eb0_guess(1),
                                                     0x1828, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat3080_guess(1),
                                                     0x16d7, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2b30_guess(1),
                                                     0x234f, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2430_guess(1),
                                                     0x2350, &stats_guess));
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2510_guess(1),
                                                     0x2351, &stats_guess));
        if (stats_guess >= 3) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat25f0_guess(1),
                                                     0x2352, &stats_guess));
        if (stats_guess >= 3) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat26d0_guess(1),
                                                     0x2353, &stats_guess));
        if (stats_guess >= 3) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2880_guess(1),
                                                     0x2354, &stats_guess));
        if (stats_guess >= 3) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat2960_guess(1),
                                                     0x2355, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        result_guess.Append_guess(CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat27a0_guess(1),
                                                     0x16cc, &stats_guess));
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
            stats_guess = 0;
        }
        CXStr ranks_guess = CreateHasteString_guess((ItemQuery_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(ranks_guess);
        CXStr rankNames_guess = CreateInstrumentModString_guess((ItemQuery_guess*)item_guess, &count_guess, 1);
        result_guess.Append_guess(rankNames_guess);
        CXStr skillMod_guess;
        skillMod_guess =
            CreateModString_guess((RankEntry_guess*)item_guess, item_guess->Stat0dd0_guess(), 0x30a7, &stats_guess);
        int length_guess = skillMod_guess.Ptr != 0 ? skillMod_guess.Ptr->length : 0;
        if (length_guess > 2 && g_displayChar_guess->FindSkill_guess(item_guess->GetSkillMod_guess()) != -1) {
            result_guess += pStringTable->getString(*g_skillNames_guess[item_guess->GetSkillMod_guess()], 0);
            result_guess.Append_guess(g_separator_guess);
            result_guess.Append_guess(skillMod_guess);
        }
        if (stats_guess > 0) {
            result_guess += g_brTag_guess;
            count_guess++;
        }
        if (item_guess->GetItemType_guess() == 0x36) {
            result_guess += g_brTag_guess;
            count_guess++;
            result_guess += pStringTable->getString(0xd1e, 0);
            result_guess += " -<BR>";
            count_guess++;
            int stringId_guess = item_guess->Slot10_guess()->GetContainerRestrictionId_guess();
            if (stringId_guess != 0) {
                result_guess += pStringTable->getString(stringId_guess, 0);
                result_guess += g_brTag_guess;
                count_guess++;
            }
            int value_guess = item_guess->Get0e90_guess();
            if (value_guess > 0) {
                sprintf(name_guess, "%d", value_guess);
                Format_guess(text_guess, 0x23bb, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                result_guess += text_guess;
                result_guess += g_brTag_guess;
                count_guess++;
            }
            result_guess.Append_guess(CreateSlotString_guess((ItemOwner_guess*)item_guess, &count_guess));
        }
        if ((item_guess->Get0aa0_guess(1) != 0 || item_guess->GetRecommendedLevel_guess(1) != 0 ||
             item_guess->Getcaa0_guess(1) != 0) &&
            item_guess->GetItemType_guess() != 0x21) {
            int skill_guess = g_displayPlayer_guess->Adjust_guess(item_guess->GetItemType_guess());
            int first_guess = item_guess->GetRecommendedLevel_guess(1);
            int second_guess = item_guess->Getcaa0_guess(1);
            if (second_guess > first_guess) {
                first_guess = 0;
            }
            if (item_guess->Get0aa0_guess(1) != 0) {
                if (item_guess->Getcaa0_guess(1) != 0) {
                    Format_guess(text_guess, 0x22c, __itoa(item_guess->Get0aa0_guess(1), g_numberBuffer_guess, 10),
                                 pStringTable->getString(*g_skillNames_guess[skill_guess], 0),
                                 __itoa(second_guess, g_bonusBuffer_guess, 10), 0, 0, 0, 0, 0, 0);
                } else {
                    Format_guess(text_guess, 0xbd3, __itoa(item_guess->Get0aa0_guess(1), g_numberBuffer_guess, 10),
                                 pStringTable->getString(*g_skillNames_guess[skill_guess], 0),
                                 0, 0, 0, 0, 0, 0, 0);
                }
            } else if (second_guess != 0) {
                if (first_guess != 0) {
                    Format_guess(text_guess, 0x22d, __itoa(first_guess, g_numberBuffer_guess, 10),
                                 __itoa(second_guess, g_bonusBuffer_guess, 10), 0, 0, 0, 0, 0, 0, 0);
                } else {
                    Format_guess(text_guess, 0x168f, __itoa(second_guess, g_numberBuffer_guess, 10),
                                 0, 0, 0, 0, 0, 0, 0, 0);
                }
            } else if (first_guess != 0) {
                Format_guess(text_guess, 0xbd4, __itoa(first_guess, g_numberBuffer_guess, 10),
                             0, 0, 0, 0, 0, 0, 0, 0);
            }
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        result_guess.Append_guess(CreateMealSizeString_guess((ItemState_guess*)item_guess));
        // Weight in tenths (not for augments), size, then class and race lists.
        if (item_guess->GetItemType_guess() != 0x36) {
            char sizeText_guess[128];
            GetItemSizeDescription_guess(item_guess->GetSize_guess(1), sizeText_guess);
            sprintf(g_numberBuffer_guess, "%4.1f", item_guess->GetWeight_guess(1) * 0.1f);
            if (item_guess->Getc850_guess(1) > 0) {
                Format_guess(text_guess, 0xbdd, g_numberBuffer_guess,
                             __itoa(item_guess->Getc850_guess(1), g_bonusBuffer_guess, 10), sizeText_guess,
                             0, 0, 0, 0, 0, 0);
            } else {
                Format_guess(text_guess, 0xbde, g_numberBuffer_guess, sizeText_guess, 0, 0, 0, 0, 0, 0, 0);
            }
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        if (item_guess->GetItemType_guess() != 0x14) {
            temp_guess = CreateClassString_guess((ItemOwner_guess*)item_guess);
            result_guess.Append_guess(temp_guess);
            result_guess += g_brTag_guess;
            count_guess++;
        }
        temp_guess = CreateRaceString_guess((ItemOwner_guess*)item_guess);
        result_guess.Append_guess(temp_guess);
        result_guess += g_brTag_guess;
        count_guess++;
        if (item_guess->GetRaces_guess(1, 0) != 0) {
            int shown_guess = 0;
            result_guess += pStringTable->getString(0xbdf, 0);
            int race_guess = 200;
            int remaining_guess = 0x11;
            do {
                int bit_guess = 1 << (race_guess - 200);
                if ((bit_guess & item_guess->GetRaces_guess(1, 0)) != 0) {
                    result_guess += g_brText_guess;
                    result_guess += g_displayNames_guess->GetDeityDesc(race_guess);
                    shown_guess++;
                }
                if (shown_guess == 5) {
                    result_guess += g_brTag_guess;
                    count_guess++;
                    shown_guess = 0;
                }
                race_guess++;
            } while (--remaining_guess != 0);
            if (shown_guess != 0) {
                result_guess += g_brTag_guess;
                count_guess++;
            }
        }
        int i_guess;
        // The five augment slots, each as a link ("0^n").
        for (i_guess = 0; i_guess < 5; i_guess++) {
            if (item_guess->HasFirst_guess(i_guess) && item_guess->HasSecond_guess(i_guess)) {
                int slotType_guess = item_guess->GetSlotType_guess(i_guess);
                DisplayChild_guess* child_guess = item_guess->GetChild_guess(i_guess);
                if (child_guess != 0) {
                    char link_guess[256];
                    FormatShort_guess(link_guess, 0x100, "%d^%d", 0, i_guess);
                    CXStr linkText_guess = Build_guess(0x1b, child_guess->GetName_guess(), link_guess);
                    Format_guess(text_guess, 0xd1b, __itoa(i_guess + 1, g_bonusBuffer_guess, 10),
                                 __itoa(slotType_guess, g_numberBuffer_guess, 10), linkText_guess,
                                 0, 0, 0, 0, 0, 0);
                    result_guess += text_guess;
                    result_guess += g_brTag_guess;
                    count_guess++;
                } else {
                    Format_guess(text_guess, 0xd1b, __itoa(i_guess + 1, g_bonusBuffer_guess, 10),
                                 __itoa(slotType_guess, g_numberBuffer_guess, 10),
                                 pStringTable->getString(0x1a2b, 0), 0, 0, 0, 0, 0, 0);
                    result_guess += text_guess;
                    result_guess += g_brTag_guess;
                    count_guess++;
                }
            }
        }
        // With item info on: every effect spell by name in a colour tag, with its details.
        if (g_itemInfoFlag_guess != 0) {
            for (i_guess = 0; i_guess < mapA_guess.pad_guess[0]; i_guess++) {
                DisplaySpell_guess* spell_guess = g_displaySpellDb_guess->Get_guess(
                    ((MapValue_guess*)mapA_guess.buckets_guess[i_guess >> mapA_guess.shift_guess])
                        [mapA_guess.pad_guess[2] & i_guess].values_guess[0]);
                if (spell_guess != 0 && spell_guess->value18c_guess != 0) {
                    result_guess += g_brTag_guess;
                    count_guess++;
                    result_guess += g_colorOpen_guess;
                    result_guess.Append_guess(ColorTag_guess(0xff8aa3ff));
                    result_guess += g_colorClose_guess;
                    result_guess += spell_guess->name208_guess;
                    result_guess += "</C>";
                    result_guess += g_brTag_guess;
                    count_guess++;
                    MapValue_guess* entry_guess =
                        &((MapValue_guess*)mapA_guess.buckets_guess[i_guess >> mapA_guess.shift_guess])
                            [mapA_guess.pad_guess[2] & i_guess];
                    if (entry_guess->values_guess[3] == 1 || entry_guess->values_guess[3] == 3 ||
                        entry_guess->values_guess[3] == 4 || entry_guess->values_guess[3] == 5) {
                        if (entry_guess->values_guess[1] != 0) {
                            Format_guess(text_guess, 0x1aa4,
                                         __itoa(entry_guess->values_guess[1], g_numberBuffer_guess, 10),
                                         0, 0, 0, 0, 0, 0, 0, 0);
                            result_guess += text_guess;
                        }
                        result_guess += g_brTag_guess;
                        count_guess++;
                    }
                    FormatSpellDescription_guess(name_guess, (PickData_guess*)spell_guess);
                    Format_guess(text_guess, 0x213b, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    result_guess += text_guess;
                    result_guess += g_brTag_guess;
                    count_guess++;
                }
            }
            for (i_guess = 0; i_guess < mapB_guess.pad_guess[0]; i_guess++) {
                DisplaySpell_guess* spell_guess = g_displaySpellDb_guess->Get_guess(
                    ((MapValue_guess*)mapB_guess.buckets_guess[i_guess >> mapB_guess.shift_guess])
                        [i_guess & mapB_guess.pad_guess[2]].values_guess[0]);
                if (spell_guess != 0 && spell_guess->value18c_guess != 0) {
                    result_guess += g_brTag_guess;
                    count_guess++;
                    result_guess += g_colorOpen_guess;
                    result_guess.Append_guess(ColorTag_guess(0xff8aa3ff));
                    result_guess += g_colorClose_guess;
                    result_guess += spell_guess->name208_guess;
                    result_guess += "</C>";
                    result_guess += g_brTag_guess;
                    count_guess++;
                    MapValue_guess* entry_guess =
                        &((MapValue_guess*)mapB_guess.buckets_guess[i_guess >> mapB_guess.shift_guess])
                            [i_guess & mapB_guess.pad_guess[2]];
                    if (entry_guess->values_guess[3] == 0) {
                        Format_guess(text_guess, 0x1aa4,
                                     __itoa(entry_guess->values_guess[1], g_numberBuffer_guess, 10),
                                     0, 0, 0, 0, 0, 0, 0, 0);
                        result_guess += text_guess;
                        result_guess += g_brTag_guess;
                        count_guess++;
                    }
                    FormatSpellDescription_guess(name_guess, (PickData_guess*)spell_guess);
                    Format_guess(text_guess, 0x213b, name_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                    result_guess += text_guess;
                    result_guess += g_brTag_guess;
                    count_guess++;
                }
            }
        }
    // Containers: one of two words (0xBE0/0xBE1), weight and the weight reduction percent.
    } else if (item_guess->GetItemClass_guess() == 1) {
        char sizeText_guess[128];
        result_guess += g_separator_guess;
        if (g_showItemId_guess != 0) {
            result_guess += pStringTable->getString(0xbe8, 0);
            result_guess += item_guess->GetIdText_guess();
            result_guess += g_brTag_guess;
            count_guess++;
        }
        result_guess += pStringTable->getString(item_guess->Checkdfcc0_guess() ? 0xbe0 : 0xbe1, 0);
        result_guess += g_brTag_guess;
        result_guess.Append_guess(CreateEquipmentStatusString_guess((ItemState_guess*)item_guess));
        result_guess += g_brTag_guess;
        GetItemSizeDescription_guess(item_guess->Getcc60_guess(), sizeText_guess);
        sprintf(g_numberBuffer_guess, "%4.1f", item_guess->GetWeight_guess(1) * 0.1f);
        sprintf(g_bonusBuffer_guess, "%d%%", item_guess->Get0e00_guess());
        Format_guess(text_guess, 0xbe2, g_numberBuffer_guess, g_bonusBuffer_guess, 0, 0, 0, 0, 0, 0, 0);
        result_guess += text_guess;
        result_guess += g_brTag_guess;
        Format_guess(text_guess, 0xbe3, __itoa(item_guess->Getcc30_guess(), g_numberBuffer_guess, 10),
                     sizeText_guess, 0, 0, 0, 0, 0, 0, 0);
        result_guess += text_guess;
        result_guess += g_brTag_guess;
    // Books: readable or not (0xBE4-0xBE7), weight.
    } else if (item_guess->GetItemClass_guess() == 2) {
        char sizeText_guess[128];
        result_guess += g_separator_guess;
        if (g_showItemId_guess != 0) {
            result_guess += pStringTable->getString(0xbe8, 0);
            result_guess += item_guess->GetIdText_guess();
            result_guess += g_brTag_guess;
            count_guess++;
        }
        if (item_guess->Check0e30_guess()) {
            CopyString_guess(text_guess, pStringTable->getString(item_guess->Getdfcd0_guess() ? 0xbe4 : 0xbe5, 0));
        } else {
            CopyString_guess(text_guess, pStringTable->getString(item_guess->Getdfcd0_guess() ? 0xbe6 : 0xbe7, 0));
        }
        result_guess += text_guess;
        result_guess += g_brTag_guess;
        result_guess.Append_guess(CreateEquipmentStatusString_guess((ItemState_guess*)item_guess));
        result_guess += g_brTag_guess;
        if (item_guess->Check09a0_guess()) {
            sprintf(text_guess, pStringTable->getString(0x236b, 0));
            result_guess += text_guess;
            result_guess += g_brTag_guess;
            count_guess++;
        }
        GetItemSizeDescription_guess(item_guess->GetSize_guess(1), sizeText_guess);
        sprintf(g_numberBuffer_guess, "%4.1f", item_guess->GetWeight_guess(1) * 0.1f);
        Format_guess(text_guess, 0xbde, g_numberBuffer_guess, sizeText_guess, 0, 0, 0, 0, 0, 0, 0);
        result_guess += text_guess;
        result_guess += g_brTag_guess;
    }
    return result_guess;
}

// Which pool window to use: the most recently opened one, unless `create_guess`; then a closed one, the most
// recent when the pool is full, or a new window placed 20 pixels further down and right.
// FUNCTION: TITANIUM 0x005215E7
// @early-stop: budget, diff ndiff=1
int PickManager_guess::Key_guess(bool create_guess) {
    int bestIndex_guess = -1;
    int freeIndex_guess = -1;
    int bestValue_guess = 0;
    for (int i_guess = 0; i_guess < active_guess.count_guess; i_guess++) {
        if (active_guess.buckets_guess[i_guess >> active_guess.shift_guess][i_guess & active_guess.mask_guess]->IsActive_guess()) {
            if (values_guess.At_guess(i_guess) > bestValue_guess) {
                bestValue_guess = values_guess.At_guess(i_guess);
                bestIndex_guess = i_guess;
            }
        } else {
            freeIndex_guess = i_guess;
        }
    }
    int index_guess = -1;
    if ((char)create_guess == 0) {
        index_guess = bestIndex_guess;
    }
    if (index_guess == -1) {
        index_guess = freeIndex_guess;
        if (index_guess == -1 && active_guess.count_guess >= limit_guess) {
            index_guess = bestIndex_guess;
        }
    }
    if (index_guess == -1) {
        CItemDisplayWnd_guess* item_guess = new CItemDisplayWnd_guess(0);
        PickEntry_guess* entry_guess = (PickEntry_guess*)item_guess;
        int count_guess = active_guess.count_guess;
        char buf_guess[256];
        sprintf(buf_guess, "ItemDisplay%d", count_guess);
        int offset_guess = count_guess * 20;
        int point_guess[2];
        int top_guess = ((CXWnd*)item_guess)->GetScreenRect().top + offset_guess;
        point_guess[0] = ((CXWnd*)item_guess)->GetScreenRect().left + offset_guess;
        point_guess[1] = top_guess;
        item_guess->Move_guess(point_guess);
        ((CSidlScreenWnd*)item_guess)->EnableIniStorage(-257, buf_guess);
        active_guess.Set_guess(active_guess.count_guess, entry_guess);
        item_guess->index184_guess = count_guess;
        offset_guess = FUN_0046d655_guess();
        values_guess.Set_guess(values_guess.count_guess, offset_guess);
        index_guess = count_guess;
    }
    return index_guess;
}

// EXTERNAL: TITANIUM 0x0060D750 memset
extern "C" void* __cdecl memset(void* destination_guess, int value_guess, unsigned int size_guess);

#define g_pctsFormat_guess EQ_ARRAY(char, 0x00649904)

struct SetPairPacket_guess {
    int first_guess;     // 0x0
    int second_guess;    // 0x4
    char pad8_guess[0x40];
};

struct ItemSink_guess {
    // EXTERNAL: TITANIUM 0x004B1DB0 ItemSink_guess::SendReadBook_guess
    void SendReadBook_guess();
};

struct ItemSource_guess {
    virtual void Slot00_guess();
    virtual ReleaseTarget_guess* Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess();
    virtual void Slot09_guess();
    virtual ItemSink_guess* Slot10_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 ItemSource_guess::GetText_guess
    const char* GetText_guess();
    // EXTERNAL: TITANIUM 0x005E0F60 ItemSource_guess::GetValue_guess
    int GetValue_guess();
    // EXTERNAL: TITANIUM 0x005ECC00 ItemSource_guess::GetItemType_guess
    int GetItemType_guess();
    // EXTERNAL: TITANIUM 0x005E10B0 ItemSource_guess::GetFlag_guess
    int GetFlag_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 ItemSource_guess::GetItemClass_guess
    int GetItemClass_guess();
};

// Fills a display from an item, marking augmented items "(Augmented)" (3368).
// FUNCTION: TITANIUM 0x00521827
// @early-stop: unknown, structural ndiff=30
void PickEntry_guess::SetItem(int first_guess, unsigned int second_guess) {
    CXStr temp_guess;
    char buffer_guess[0x400];
    SetPairPacket_guess packet_guess;
    ItemSource_guess* source_guess = (ItemSource_guess*)first_guess;
    value_guess.Clear_guess();
    ref_guess.Clear_guess();
    value_guess.Append_guess(source_guess->GetText_guess());
    if (HasAnyAugment_guess((ItemQuery_guess*)source_guess) != 0) {
        sprintf(buffer_guess, g_pctsFormat_guess, pStringTable->getString(0xd28, 0));
        value_guess.Append_guess(buffer_guess);
    }
    if (field170_guess != 0) {
        field170_guess->Release_guess(1);
    }
    field170_guess = source_guess->Slot01_guess();
    flag174_guess = 1;
    *(CXStr*)&ref_guess = BuildItemDescription_guess((DisplayItem_guess*)source_guess, second_guess);
    if (source_guess->GetItemClass_guess() != 2) {
        ItemSink_guess* sink_guess = source_guess->Slot10_guess(field184_guess);
        sink_guess->SendReadBook_guess();
    }
    if (source_guess->GetItemType_guess() == 0x36) {
        if (source_guess->GetFlag_guess() != 0) {
            memset(&packet_guess, 0, 0x48);
            packet_guess.first_guess = source_guess->GetFlag_guess();
            packet_guess.second_guess = field184_guess;
            EQSendMessage(&g_packetConnection_guess, OP_AugmentInfo, &packet_guess, 0x48, 1);
        }
    }
    field164_guess->field16c_guess = 0;
    field164_guess->field158_guess = field17c_guess;
    field17c_guess->Set_guess(source_guess->GetValue_guess() - 500);
    Update_guess();
}

// Opens spell info in a window from the display pool (0x991B88): picks a window (0x005215E7; `key` asks
// for a fresh one), fills it from `first`, `second` and `third`, activates it (slot 33) and stamps its
// open time (0x0046D655), which the close-newest helper (0x0051E0EA) uses. Called from buff, pet buff,
// spell gem, hot button and spell book clicks.
// FUNCTION: TITANIUM 0x005217B6
void PickManager_guess::Set_guess(int first_guess, bool key_guess, int second_guess, int third_guess) {
    int index_guess = Key_guess(key_guess);
    active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]
        ->Set_guess(first_guess, second_guess, third_guess);
    active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]
        ->Slot33_guess();
    int* slot_guess =
        &values_guess.buckets_guess[index_guess >> values_guess.shift_guess][index_guess & values_guess.mask_guess];
    *slot_guess = FUN_0046d655_guess();
}

// Opens a display for an item; `key_guess` 1 (Ctrl not held) reuses the latest window, else a new one.
// FUNCTION: TITANIUM 0x005219F6
void PickManager_guess::SetRaw_guess(int first_guess, unsigned int key_guess) {
    int index_guess = Key_guess((key_guess & 2) == 0);
    active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]
        ->SetItem(first_guess, key_guess);
    active_guess.buckets_guess[index_guess >> active_guess.shift_guess][index_guess & active_guess.mask_guess]
        ->Slot33_guess();
    int* slot_guess =
        &values_guess.buckets_guess[index_guess >> values_guess.shift_guess][index_guess & values_guess.mask_guess];
    *slot_guess = FUN_0046d655_guess();
}

struct Slot_guess {
    virtual void Release_guess(int value_guess);
    virtual Slot_guess* Get_guess();
};

struct Query_guess {
    // EXTERNAL: TITANIUM 0x005ECB20 Query_guess::Check_guess
    int Check_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x005E3850 Query_guess::Fill_guess
    void Fill_guess(char* buffer_guess, int size_guess);
    // EXTERNAL: TITANIUM 0x005E0EC0 Query_guess::Read_guess
    int Read_guess(char* buffer_guess);
    // EXTERNAL: TITANIUM 0x005EC630 Query_guess::GetChild_guess
    Slot_guess* GetChild_guess(int index_guess);
};

struct Target_guess {
    // EXTERNAL: TITANIUM 0x005B9670 Target_guess::Store_guess
    void Store_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x0059EDF0 Target_guess::SetFocus
    void SetFocus();
};

struct Container_guess {
    char pad0_guess[0x160];
    Target_guess* target160_guess; // 0x160
};

struct Locator_guess {
    // EXTERNAL: TITANIUM 0x004F288C Locator_guess::GetActiveChatWindow_guess
    Container_guess* GetActiveChatWindow_guess();
};

#define pinstCChatManager_guess EQ_GLOBAL(Locator_guess*, 0x009917E4)
#define g_pickMgr_guess EQ_GLOBAL(PickManager_guess*, 0x00991B88)
#define g_msgSender_guess EQ_GLOBAL(MessageSender_guess*, 0x00991B88)

struct Handler_guess {
    char pad0_guess[0x164];
    int field164_guess;             // 0x164
    char pad168_guess[8];
    Query_guess* query170_guess;    // 0x170
    char flag174_guess;             // 0x174

    void Handle_guess(int first_guess, int second_guess, const char* third_guess);
    // EXTERNAL: TITANIUM 0x005A2230 Handler_guess::WndNotification
    void WndNotification(int first_guess, int second_guess, const char* third_guess);
};

// STML link clicks (message 0x1B): "0^<n>" opens augment `n`, "1^..." asks for the evolving final result.
// FUNCTION: TITANIUM 0x00521A6D
void Handler_guess::Handle_guess(int first_guess, int second_guess, const char* third_guess) {
    int index_guess;
    char buffer_guess[1024];
    if (second_guess == 1) {
        if (first_guess == field164_guess && flag174_guess != 0 && query170_guess != 0) {
            if (query170_guess->Check_guess(1) == 0) {
                Target_guess* target_guess = pinstCChatManager_guess->GetActiveChatWindow_guess()->target160_guess;
                if (target_guess != 0) {
                    query170_guess->Fill_guess(buffer_guess, 0x400);
                    int value_guess = query170_guess->Read_guess(buffer_guess);
                    target_guess->Store_guess(value_guess);
                    target_guess->SetFocus();
                }
            }
        }
    } else if (second_guess == 0x1b) {
        const char* rest_guess =
            third_guess + ParseToken_guess(third_guess, reinterpret_cast<char*>(&index_guess), 0x5e);
        if (index_guess == 0) {
            index_guess = -1;
            ParseToken_guess(rest_guess, reinterpret_cast<char*>(&index_guess), 0x5e);
            if (query170_guess != 0 && index_guess >= 0 && index_guess < 5) {
                Slot_guess* slot_guess = query170_guess->GetChild_guess(index_guess)->Get_guess();
                unsigned int flags_guess = pinstCXWndManager_guess->GetKeyboardFlags();
                g_pickMgr_guess->SetRaw_guess((int)slot_guess, ~flags_guess & 1);
                if (slot_guess != 0) {
                    slot_guess->Release_guess(1);
                }
            }
        } else if (index_guess == 1) {
            g_msgSender_guess->RequestEvolvingFinalResult_guess(rest_guess);
        }
    }
    WndNotification(first_guess, second_guess, third_guess);
}

struct LayoutLookup_guess {
    int field0_guess;
    // EXTERNAL: TITANIUM 0x00572300 LayoutLookup_guess::Find_guess
    void* Find_guess(const char* name_guess);
};

struct LayoutEntryVTable_guess {
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
};

struct LayoutEntry_guess : LayoutEntryVTable_guess {
    virtual void Apply_guess(void* value_guess);
};

struct MainLayoutObject_guess {
    char pad0_guess[0x140];
    LayoutLookup_guess lookup_guess;
    char pad144_guess[0x6c];
    LayoutEntry_guess* entry1b0_guess;

    char AboutToHide_guess();
};

// AboutToHide of the item experience transfer window (vtable slot 50 of 0x656C20, ctor 0x0052201C
// "ItemExpTransferWnd"): stores the "MainLayout" setting of the layout child (+0x1B0, its vtable slot 74);
// always true. Its AboutToShow (0x0052271B) loads it through slot 73.
// FUNCTION: TITANIUM 0x00521BEC
char MainLayoutObject_guess::AboutToHide_guess() {
    if (entry1b0_guess != 0) {
        entry1b0_guess->Apply_guess(lookup_guess.Find_guess("MainLayout"));
    }
    return 1;
}

