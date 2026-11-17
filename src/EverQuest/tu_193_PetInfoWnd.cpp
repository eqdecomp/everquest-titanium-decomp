// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 193: a hint from compare/tumap.py.
// CPetInfoWnd ("PetInfoWindow", CPetInfoWndView_guess): the pet command buttons and the pet's 30 buff icons. Buff i
// has its button at entries_guess[30+i] and its CTextureAnimation at entries_guess[i], spell id +0x288 and
// time left in ms +0x308. CCursorAttachmentView_guess (0x850C24) is CCursorAttachment; 0x985CC8 looks up spells by id
// (name +0x208, icon +0x248, beneficial +0x17D), probably the spell manager.
#include "titanium/types.h"
#include "titanium/crt.h"

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

struct Spell_guess {
    char pad000_guess[0x17d];
    unsigned char flag17d_guess; // 0x17D
    char pad17e_guess[0x208 - 0x17e];
    char* name_guess; // 0x208
    char pad20c_guess[0x248 - 0x20c];
    int icon_0248_guess; // 0x248
};

struct Lookup_guess {
    // EXTERNAL: TITANIUM 0x0040CBD6 Lookup_guess::Find_guess
    Spell_guess* Find_guess(int id);
};

struct CXWndManagerView_guess {
    // EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::GetKeyboardFlags
    unsigned char GetKeyboardFlags(int first, int second);
};

struct Effect_guess {
    // EXTERNAL: TITANIUM 0x005217B6 Effect_guess::Apply_guess
    void Apply_guess(int value, unsigned char flags);
    // EXTERNAL: TITANIUM 0x0051E0EA Effect_guess::Clear_guess
    void Clear_guess();
};

#define g_wndmgr_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_help_guess EQ_GLOBAL(void*, 0x00905CE4)

struct Labelled_guess {
    // EXTERNAL: TITANIUM 0x004D22D7 Labelled_guess::GetText_guess
    CXStr GetText_guess();
};

// EXTERNAL: TITANIUM 0x00467D40 do_pet_guess
void __cdecl do_pet_guess(void* target, char* text);

// EXTERNAL: TITANIUM 0x005738B0 FormatStr_guess
void __cdecl FormatStr_guess(CXStr* out, const char* format, ...);

// EXTERNAL: TITANIUM 0x0044D0D0 Predicate_guess
char __cdecl Predicate_guess(int value);

#define g_mode_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)
#define pinstCItemDisplayManager_guess EQ_GLOBAL(Effect_guess*, 0x00991B88)

struct Text_guess {
    // EXTERNAL: TITANIUM 0x00572300 Text_guess::Get_guess
    char* Get_guess(const char* name);
    int rep_guess;
};

struct Popup_guess {
    // EXTERNAL: TITANIUM 0x004AE82A Popup_guess::Show_guess
    void Show_guess(char shown, char* text);
    // EXTERNAL: TITANIUM 0x004AE919 Popup_guess::ReadFlag_guess
    char ReadFlag_guess(char* value, const char* name, int first, int second);
};

#define g_popup_guess EQ_GLOBAL(Popup_guess*, 0x00988DF0)

struct State_guess {
    char pad0000_guess[0x16c];
    int value16c_guess;
};

struct Entry_guess {
    virtual void Close_guess(int flags);
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
    virtual void Slot48_guess(int first, int second);
    char pad004_guess[0x74];
    CXStr label_guess; // 0x78
};

struct PetControl_guess : CXWnd {
    char pad11c_guess[0x50];
    void* attached_guess; // 0x16C
};

struct WindowStyleFlags_guess {
    unsigned char low_guess;
    unsigned char flags_guess;
};

struct CTextureAnimationView_guess {
    // EXTERNAL: TITANIUM 0x005B1D90 CTextureAnimationView_guess::CTextureAnimationView_guess
    CTextureAnimationView_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B CTextureAnimationView_guess::Initialize_guess
    void Initialize_guess(CXWnd* icons);
    char pad000_guess[0x4C];
};

struct SidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 SidlManager_guess::Find_guess
    CXWnd* Find_guess(const CXStr& name);
};

struct ClientData_guess {
    char pad000_guess[0x148];
    int value148_guess;
};

#define g_sidlManager_guess EQ_GLOBAL(SidlManager_guess*, 0x0099D3F4)
#define g_clientData_guess EQ_GLOBAL(ClientData_guess*, 0x00905D24)

struct Gauge_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Gauge_guess::Set_guess
    void Set_guess(int value);
};

struct Slot_guess {
    char pad000_guess[0x158];
    int value158_guess; // 0x158
    char pad15c_guess[0x10];
    Gauge_guess* gauge_guess; // 0x16C
};

#include "titanium/layouts/geometry.h"
#include "titanium/wnd/CCursorAttachment.h"

struct Cell_guess {
    char pad000_guess[0x3C];
    int left_guess; // 0x3C
    int top_guess; // 0x40
    int right_guess; // 0x44
    int bottom_guess; // 0x48
    // EXTERNAL: TITANIUM 0x0059FA70 Cell_guess::Place_guess
    void Place_guess(CXPoint* point);
};


struct Container_guess {
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
    virtual CXRect* GetRect_guess(CXPoint* scratch); // 0xE0
};

struct Base_guess {
    // EXTERNAL: TITANIUM 0x005A3850 Base_guess::Base_guess
    Base_guess(CXWnd* parent, CXStr* screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 ??1Base_guess@@UAE@XZ
    virtual ~Base_guess();
};

// EXTERNAL: TITANIUM 0x0065A0A8 ??_7CPetInfoWndView_guess@@6B@
struct CPetInfoWndView_guess : Base_guess {
    char pad0004_guess[0x14];
    char value18_guess; // 0x18
    char pad0019_guess[0x73];
    char value8c_guess; // 0x8C
    char pad008d_guess[0x97];
    int active_guess; // 0x124
    char pad0128_guess[0x18];
    Text_guess text140_guess; // 0x140
    char pad0144_guess[0x18];
    int value15c_guess; // 0x15C
    int petId_0160_guess; // 0x160
    char flag164_guess; // 0x164
    char pad165_guess[3];
    int attackButton_0168_guess; // 0x168
    int backButton_016c_guess; // 0x16C
    int sitButton_0170_guess; // 0x170
    int standButton_0174_guess; // 0x174
    int lostButton_0178_guess; // 0x178
    int guardButton_017c_guess; // 0x17C
    int followButton_0180_guess; // 0x180
    int tauntButton_0184_guess; // 0x184
    char pad0188_guess[4];
    Container_guess* container_guess; // 0x18C
    int blueIconBackground_0190_guess; // 0x190
    int redIconBackground_0194_guess; // 0x194
    void* entries_guess[60]; // 0x198, 0x210
    int values288_guess[0x1E]; // 0x288
    int lastTick300_guess; // 0x300
    char state304_guess; // 0x304
    char shown305_guess; // 0x305
    char pad306_guess[2];
    int durations308_guess[30]; // 0x308

    virtual ~CPetInfoWndView_guess();
    CPetInfoWndView_guess(CXWnd* parent_guess);
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
    virtual int WndNotification_guess(CXWnd* sender, unsigned int message, void* data); // 0x80
    virtual void Slot33_guess(); // 0x84
    virtual void Slot34_guess(); // 0x88
    int GetButton_guess(int index);
    void ShowBuffSpell_guess(int index);
    void UpdateBuffTooltips_guess();
    CPetInfoWndView_guess* Delete_guess(unsigned char flags);
    void SetBuffIcon_guess(Slot_guess* slot, int value, int mode);
    void LayoutBuffIcons_guess();
    // EXTERNAL: TITANIUM 0x005A1700 CPetInfoWndView_guess::Start_guess
    void Start_guess(int first, int second);
    void OnResize_guess(int first, int second);
    // EXTERNAL: TITANIUM 0x005A1CD0 CPetInfoWndView_guess::Redraw_guess
    void Redraw_guess();
    // EXTERNAL: TITANIUM 0x0054210E CPetInfoWndView_guess::SetPetBuffs_guess
    void SetPetBuffs_guess(int* ids, int* durations, int count);
    void Refresh_guess();
    void SetShownPopup_guess(char shown);
};

// Non-virtual view of a CXWnd for its vtable slot 0xC0 (index 48).
struct Window_guess {
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
    virtual void SetState_guess(char on, int flag); // 0xC0
};

// EXTERNAL: TITANIUM 0x00401B28 FindSpawn_guess
EQPlayer* __cdecl FindSpawn_guess(int id);

// EXTERNAL: TITANIUM 0x0046D655 GetTick_guess
int __cdecl GetTick_guess();

struct Gate_guess {
    // EXTERNAL: TITANIUM 0x005F6D40 Gate_guess::Check_guess
    char Check_guess(int value);
};

struct CharacterStats_guess {
    // EXTERNAL: TITANIUM 0x004106A3 CharacterStats_guess::TotalSpellAffects_guess
    int TotalSpellAffects_guess(int affect, bool includeAlt, int subindex, bool includeItems);
};

#define g_pc_guess EQ_GLOBAL(EQ_PC*, 0x00905D00)
#define g_gate_guess EQ_GLOBAL(Gate_guess*, 0x00905CC0)
#define g_flag_guess EQ_GLOBAL(int, 0x00924470)

// Sets buff button `slot` to icon cell `value` (-1 empties it) on PetBlueIconBackground for a beneficial
// spell, PetRedIconBackground otherwise; `mode` -1 gives no background.
// FUNCTION: TITANIUM 0x00541A3B
void CPetInfoWndView_guess::SetBuffIcon_guess(Slot_guess* slot, int value, int mode) {
    if (slot != 0) {
        if (value > -1) {
            if (mode == -1) {
                slot->value158_guess = 0;
            } else {
                slot->value158_guess = mode ? blueIconBackground_0190_guess : redIconBackground_0194_guess;
            }
            slot->gauge_guess->Set_guess(value);
        } else {
            slot->value158_guess = 0;
            slot->gauge_guess->Set_guess(-1);
        }
    }
}

// Lays the buff icons out top to bottom in columns that fit the BuffWindow child, one pixel apart.
// FUNCTION: TITANIUM 0x00541A90
// @early-stop: tiebreak, structural ndiff=9
void CPetInfoWndView_guess::LayoutBuffIcons_guess() {
    CXPoint scratch;
    CXPoint pos;
    int column;
    int y;
    int i;
    void** entry;
    void** slots = &entries_guess[30];
    if (container_guess != 0 && (entry = slots, *entry != 0)) {
        Cell_guess* first = static_cast<Cell_guess*>(entries_guess[30]);
        int height = first->bottom_guess - first->top_guess;
        int width = first->right_guess - first->left_guess;
        CXRect* rect = container_guess->GetRect_guess(&scratch);
        int maxX = rect->right - rect->left;
        rect = container_guess->GetRect_guess(&scratch);
        int maxY = rect->bottom - rect->top;
        column = 0;
        y = 0;
        i = 0;
        do {
            Cell_guess* cell = static_cast<Cell_guess*>(*entry);
            if (cell != 0) {
                if (y + height > maxY) {
                    y = 0;
                    column = column + width + 1;
                }
                if (column > maxX) return;
                if (y > maxY) return;
                pos.x = column;
                pos.y = y;
                cell->Place_guess(&pos);
                y = y + height + 1;
            }
            ++i;
            ++entry;
        } while (i < 30);
    }
}

// OnResize: re-lays the icons, then the base resize.
// FUNCTION: TITANIUM 0x00541B62
void CPetInfoWndView_guess::OnResize_guess(int first, int second) {
    LayoutBuffIcons_guess();
    Start_guess(first, second);
}

// Pet window destructor: for each of the 30 buff buttons, detaches its animation (+0x16C) and deletes
// that copy (virtual slot 0 with flag 1).
// FUNCTION: TITANIUM 0x00541B7D
CPetInfoWndView_guess::~CPetInfoWndView_guess() {
    if (active_guess != 0) {
        void** entry_guess = entries_guess;
        int count_guess = 30;
        do {
            if (entry_guess[30] != 0) {
                static_cast<State_guess*>(entry_guess[30])->value16c_guess = 0;
                if (entry_guess[0] != 0) {
                    static_cast<Entry_guess*>(entry_guess[0])->Close_guess(1);
                }
            }
            ++entry_guess;
            --count_guess;
        } while (count_guess != 0);
    }
}

// Buff tooltips: "<spell> (mm:ss)", empty for a free slot.
// FUNCTION: TITANIUM 0x00541BEB
void CPetInfoWndView_guess::UpdateBuffTooltips_guess() {
    int minutes;
    for (int i = 0; i < 30; ++i) {
        if (entries_guess[30 + i] != 0) {
            Spell_guess* spell = EQ_GLOBAL(Lookup_guess*, 0x00985CC8)->Find_guess(values288_guess[i]);
            if (spell != 0) {
                int seconds = durations308_guess[i] / 1000;
                if (seconds < 0) {
                    seconds = 0;
                }
                minutes = seconds / 60;
                char text[0x200];
                // Seconds are rounded down to a whole 6-second tick.
                sprintf(text, "%s (%02d:%02d)", spell->name_guess, minutes,
                    seconds % 60 - seconds % 6);
                CXStr label(text);
                Entry_guess* entry_guess = static_cast<Entry_guess*>(entries_guess[30 + i]);
                entry_guess->label_guess = label;
            } else {
                CXStr label(EQ_ARRAY(char, 0x0063F53F));
                Entry_guess* entry_guess = static_cast<Entry_guess*>(entries_guess[30 + i]);
                entry_guess->label_guess = label;
            }
        }
    }
}

// Opens the spell display (0x991B88) for buff `index`; the flag is "Shift not held".
// FUNCTION: TITANIUM 0x00541D4A
void CPetInfoWndView_guess::ShowBuffSpell_guess(int index) {
    if (Predicate_guess(values288_guess[index])) {
        pinstCItemDisplayManager_guess->Apply_guess(values288_guess[index],
            !(g_mode_guess->GetKeyboardFlags(0, -1) & 1));
    }
}

// A click on a command button issues /pet (do_pet) with attack 0x3324, guard here 0x1D52, get lost 0x1D50,
// sit or stand (by the pet's stand state 'n'), back off 0x1D4C, follow me 0x1D54 or taunt 0x1D4E. A buff
// clicked with keyboard flags 0xC, or notification 0x18, opens its spell display; 0x1A closes it.
// FUNCTION: TITANIUM 0x00541D8A
int CPetInfoWndView_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data) {
    if (message == 1) {
        char text[256];
        text[0] = 0;
        bool found = true;
        if ((int)sender == attackButton_0168_guess) {
            strcpy(text, pStringTable->getString(0x3324, 0));
        } else if ((int)sender == guardButton_017c_guess) {
            strcpy(text, pStringTable->getString(0x1d52, 0));
        } else if ((int)sender == lostButton_0178_guess) {
            strcpy(text, pStringTable->getString(0x1d50, 0));
        } else if ((int)sender == sitButton_0170_guess || (int)sender == standButton_0174_guess) {
            EQPlayer* spawn_guess = FindSpawn_guess(
                reinterpret_cast<State_guess*>(g_pc_guess->pSpawn->pActorInfo)->value16c_guess);
            if (spawn_guess != 0) {
                if (spawn_guess->StandState == 'n') {
                    strcpy(text, pStringTable->getString(0x1d5f, 0));
                } else {
                    strcpy(text, pStringTable->getString(0x1d5e, 0));
                }
            }
        } else if ((int)sender == backButton_016c_guess) {
            strcpy(text, pStringTable->getString(0x1d4c, 0));
        } else if ((int)sender == followButton_0180_guess) {
            strcpy(text, pStringTable->getString(0x1d54, 0));
        } else if ((int)sender == tauntButton_0184_guess) {
            strcpy(text, pStringTable->getString(0x1d4e, 0));
        } else {
            found = false;
        }
        if (found) {
            do_pet_guess(g_help_guess, text);
            return 0;
        }
        if (g_wndmgr_guess->GetKeyboardFlags() & 0xc) {
            for (int i = 0; i < 30; ++i) {
                if (sender == entries_guess[30 + i]) {
                    ShowBuffSpell_guess(i);
                    return 0;
                }
            }
        }
    } else if (message == 0x17) {
        if (!pinstCCursorAttachment_guess->IsVisible_guess() ||
            (pinstCCursorAttachment_guess->IsVisible_guess() && pinstCCursorAttachment_guess->mode_15c_guess >= 4)) {
            int index = 0;
            if ((int)sender == attackButton_0168_guess) {
                index = 1;
            } else if ((int)sender == guardButton_017c_guess) {
                index = 2;
            } else if ((int)sender == lostButton_0178_guess) {
                index = 3;
            } else if ((int)sender == sitButton_0170_guess || (int)sender == standButton_0174_guess) {
                index = 4;
            } else if ((int)sender == backButton_016c_guess) {
                index = 5;
            } else if ((int)sender == followButton_0180_guess) {
                index = 6;
            } else if ((int)sender == tauntButton_0184_guess) {
                index = 7;
            }
            CXStr line;
            // 0x17 puts the button on the cursor as a "Pet <text>" hot button (kind 10,
            // index 1-7), unless the cursor holds an item or coins (kinds below 4).
            FormatStr_guess(&line, "%s %s", pStringTable->getString(0x1a2c, 0),
                (char*)reinterpret_cast<Labelled_guess*>(sender)->GetText_guess());
            pinstCCursorAttachment_guess->Post_guess(0, 10, index, line, -1);
        }
    } else if (message == 0x18) {
        for (int i = 0; i < 30; ++i) {
            if (sender == entries_guess[30 + i]) {
                ShowBuffSpell_guess(i);
                return 0;
            }
        }
    } else if (message == 0x1a) {
        pinstCItemDisplayManager_guess->Clear_guess();
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->CSidlScreenWnd::WndNotification(sender, message, data);
}

// Command button by index: 1 attack, 2 guard, 3 get lost, 4 sit, 5 back off, 6 follow, 7 taunt (hot
// button type 8 uses it).
// FUNCTION: TITANIUM 0x0054209C
int CPetInfoWndView_guess::GetButton_guess(int index) {
    switch (index) {
    default: return 0;
    case 7: return tauntButton_0184_guess;
    case 6: return followButton_0180_guess;
    case 5: return backButton_016c_guess;
    case 4: return sitButton_0170_guess;
    case 3: return lostButton_0178_guess;
    case 2: return guardButton_017c_guess;
    case 1: return attackButton_0168_guess;
    }
}

// Scalar deleting destructor of the pet info window (vtable 0x65A0A8 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x005420F2
CPetInfoWndView_guess* CPetInfoWndView_guess::Delete_guess(unsigned char flags) {
    this->CPetInfoWndView_guess::~CPetInfoWndView_guess();
    if (flags & 1) {
        free(this);
    }
    return this;
}

// Loads the pet buff list: spell ids and durations in 6-second ticks (kept in ms); unknown or invalid
// spells empty their slot. Probably called for OP_PetBuffWindow (names.tsv, low).
// FUNCTION: TITANIUM 0x0054210E
// @early-stop: budget, structural ndiff=101
void CPetInfoWndView_guess::SetPetBuffs_guess(int* ids, int* durations, int count) {
    lastTick300_guess = GetTick_guess();
    void** entry = &entries_guess[30];
    int* id = ids;
    for (int i = 0; i < 30; ++i, ++entry, ++id) {
        if (container_guess != 0 && *entry != 0) {
            if (ids == 0 || i >= count || !Predicate_guess(*id)) {
                SetBuffIcon_guess(static_cast<Slot_guess*>(*entry), -1, 0);
                CXStr label(EQ_ARRAY(char, 0x0063F53F));
                static_cast<Entry_guess*>(*entry)->label_guess = label;
            } else {
                Spell_guess* spell = EQ_GLOBAL(Lookup_guess*, 0x00985CC8)->Find_guess(*id);
                if (spell != 0) {
                    int duration = spell->icon_0248_guess;
                    if (duration < 0) {
                        duration = 0;
                    }
                    SetBuffIcon_guess(static_cast<Slot_guess*>(*entry), duration, spell->flag17d_guess);
                    durations308_guess[i] = durations[i] * 6000;
                    static_cast<Entry_guess*>(*entry)->Slot48_guess(1, 1);
                    values288_guess[i] = *id;
                    continue;
                }
                SetBuffIcon_guess(static_cast<Slot_guess*>(*entry), -1, 0);
                CXStr label(EQ_ARRAY(char, 0x0063F53F));
                static_cast<Entry_guess*>(*entry)->label_guess = label;
            }
            static_cast<Entry_guess*>(*entry)->Slot48_guess(0, 1);
            values288_guess[i] = -1;
            durations308_guess[i] = 0;
        }
    }
    UpdateBuffTooltips_guess();
    LayoutBuffIcons_guess();
}

// Per update: finds the pet (actor +0x16C), shows or hides the window as it appears or goes (PopupOnPet),
// enables the command buttons and counts the buff timers down (not while 0x5F6D40 holds on 0x924470).
// FUNCTION: TITANIUM 0x005422B5
void CPetInfoWndView_guess::Refresh_guess() {
    EQPlayer* spawn_guess = 0;
    char state_guess = 0;
    bool plain_guess = false;
    bool flagged_guess = false;
    bool b7_guess = false;
    bool b5_guess = false;
    bool b8_guess = false;
    bool b1_guess = false;
    char sit_guess = 0;
    int id_guess = 0;

    if (g_pc_guess->pSpawn != 0 && g_pc_guess->pSpawn->pActorInfo != 0) {
        id_guess = reinterpret_cast<State_guess*>(g_pc_guess->pSpawn->pActorInfo)->value16c_guess;
        if (id_guess != -1) {
            spawn_guess = FindSpawn_guess(id_guess);
        }
    }
    if (spawn_guess != 0) {
        state_guess = 1;
        plain_guess = true;
        // Body type 31: only Get Lost is enabled.
        if (spawn_guess->BodyType == 0x1f) {
            flagged_guess = true;
            plain_guess = false;
        }
        if (petId_0160_guess != id_guess) {
            petId_0160_guess = id_guess;
            flag164_guess = 0;
            // Race 127 with +0x1B5 set: each button needs spell effect 267 (0x10B) with its own sub-index.
            if (spawn_guess->Race == 0x7f && spawn_guess->field_1B5 != 0) {
                flag164_guess = 1;
            }
        }
        if (flag164_guess != 0) {
            plain_guess = reinterpret_cast<CharacterStats_guess*>(&g_pc_guess->vftable_C280)->TotalSpellAffects_guess(0x10b, 1, 9, 1) != 0;
            flagged_guess = true;
            b7_guess = reinterpret_cast<CharacterStats_guess*>(&g_pc_guess->vftable_C280)->TotalSpellAffects_guess(0x10b, 1, 7, 1) != 0;
            b5_guess = reinterpret_cast<CharacterStats_guess*>(&g_pc_guess->vftable_C280)->TotalSpellAffects_guess(0x10b, 1, 5, 1) != 0;
            b8_guess = reinterpret_cast<CharacterStats_guess*>(&g_pc_guess->vftable_C280)->TotalSpellAffects_guess(0x10b, 1, 8, 1) != 0;
            b1_guess = reinterpret_cast<CharacterStats_guess*>(&g_pc_guess->vftable_C280)->TotalSpellAffects_guess(0x10b, 1, 1, 1) != 0;
        }
        if (spawn_guess->StandState == 'n') {
            sit_guess = 1;
        }
    }

    if (state_guess != state304_guess) {
        state304_guess = state_guess;
        if (shown305_guess != 0) {
            if (state_guess != 0) {
                Slot33_guess();
            } else {
                Slot34_guess();
            }
            Redraw_guess();
        }
        if (state_guess == 0) {
            SetPetBuffs_guess(0, 0, 0);
        }
    }
    if (guardButton_017c_guess != 0) {
        reinterpret_cast<CXWnd*>(guardButton_017c_guess)->Enabled = plain_guess || b5_guess;
    }
    if (attackButton_0168_guess != 0) {
        reinterpret_cast<CXWnd*>(attackButton_0168_guess)->Enabled = plain_guess || b7_guess;
    }
    if (backButton_016c_guess != 0) {
        reinterpret_cast<CXWnd*>(backButton_016c_guess)->Enabled = plain_guess || b1_guess;
    }
    if (sitButton_0170_guess != 0) {
        reinterpret_cast<CXWnd*>(sitButton_0170_guess)->Enabled = plain_guess;
    }
    if (standButton_0174_guess != 0) {
        reinterpret_cast<CXWnd*>(standButton_0174_guess)->Enabled = plain_guess;
    }
    if (lostButton_0178_guess != 0) {
        reinterpret_cast<CXWnd*>(lostButton_0178_guess)->Enabled = plain_guess || flagged_guess;
    }
    if (followButton_0180_guess != 0) {
        reinterpret_cast<CXWnd*>(followButton_0180_guess)->Enabled = plain_guess || b8_guess;
    }
    if (tauntButton_0184_guess != 0) {
        reinterpret_cast<CXWnd*>(tauntButton_0184_guess)->Enabled = plain_guess;
    }

    if (state_guess != 0) {
        if (sitButton_0170_guess != 0 && standButton_0174_guess != 0) {
            reinterpret_cast<Window_guess*>(sitButton_0170_guess)->SetState_guess(sit_guess == 0, 1);
            reinterpret_cast<Window_guess*>(standButton_0174_guess)->SetState_guess(sit_guess, 1);
        }
        if (lastTick300_guess != 0) {
            int now_guess = GetTick_guess();
            int elapsed_guess = now_guess - lastTick300_guess;
            if (g_gate_guess->Check_guess(g_flag_guess) == 0) {
                int* slot_guess = durations308_guess;
                int count_guess = 30;
                do {
                    if (*slot_guess > elapsed_guess) {
                        *slot_guess -= elapsed_guess;
                    } else {
                        *slot_guess = 0;
                    }
                    ++slot_guess;
                    --count_guess;
                } while (count_guess != 0);
            }
            lastTick300_guess = now_guess;
        }
        UpdateBuffTooltips_guess();
    }
}

// Stores the PopupOnPet option (show the window when a pet appears) and reapplies it.
// FUNCTION: TITANIUM 0x005425E9
void CPetInfoWndView_guess::SetShownPopup_guess(char shown) {
    shown305_guess = shown;
    char* text_guess = text140_guess.Get_guess("PopupOnPet");
    g_popup_guess->Show_guess(shown, text_guess);
    Refresh_guess();
}

// Pet window constructor: finds the command buttons and the buff area, gives each PetBuff0-29 button its own
// copy of the A_PetSpellIcons animation with no spell (-1), and reads PopupOnPet from the UI INI
// (0x004AE919, default on).
// FUNCTION: TITANIUM 0x00542620
// @early-stop: budget, structural ndiff=57
CPetInfoWndView_guess::CPetInfoWndView_guess(CXWnd* parent_guess)
    : Base_guess(parent_guess, &CXStr("PetInfoWindow"), -513, 1, 0) {
    state304_guess = 0;
    guardButton_017c_guess = 0;
    attackButton_0168_guess = 0;
    backButton_016c_guess = 0;
    sitButton_0170_guess = 0;
    standButton_0174_guess = 0;
    lostButton_0178_guess = 0;
    followButton_0180_guess = 0;
    tauntButton_0184_guess = 0;
    shown305_guess = 1;
    container_guess = 0;
    value15c_guess = g_clientData_guess->value148_guess;
    petId_0160_guess = 0;
    flag164_guess = 0;
    lastTick300_guess = 0;
    memset(durations308_guess, 0, 0x78);

    if (active_guess != 0) {
        value18_guess = 0;
        value8c_guess = 0x44;
        reinterpret_cast<CSidlScreenWnd*>(this)->CreateChildrenFromSidl();

        guardButton_017c_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("GuardButton"));
        attackButton_0168_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("AttackButton"));
        backButton_016c_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("BackButton"));
        sitButton_0170_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("SitButton"));
        standButton_0174_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("StandButton"));
        lostButton_0178_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("LostButton"));
        followButton_0180_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("FollowButton"));
        tauntButton_0184_guess = reinterpret_cast<int>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("TauntButton"));
        container_guess = reinterpret_cast<Container_guess*>(
            reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem("BuffWindow"));

        if (container_guess != 0) {
            reinterpret_cast<WindowStyleFlags_guess*>(
                &reinterpret_cast<CXWnd*>(container_guess)->WindowStyle)->flags_guess &= 0xF7;
        }
        blueIconBackground_0190_guess = reinterpret_cast<int>(g_sidlManager_guess->Find_guess("PetBlueIconBackground"));
        redIconBackground_0194_guess = reinterpret_cast<int>(g_sidlManager_guess->Find_guess("PetRedIconBackground"));
        CXWnd* spell_icons_guess = g_sidlManager_guess->Find_guess("A_PetSpellIcons");

        char name_guess[32];
        for (int i_guess = 0; i_guess < 30; ++i_guess) {
            // Buttons PetBuff0-29 each get their own copy of A_PetSpellIcons.
            sprintf(name_guess, "PetBuff%d", i_guess);
            entries_guess[30 + i_guess] =
                reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name_guess);
            if (entries_guess[30 + i_guess] != 0) {
                CTextureAnimationView_guess* buff_guess = new CTextureAnimationView_guess;
                entries_guess[i_guess] = buff_guess;
                buff_guess->Initialize_guess(spell_icons_guess);

                PetControl_guess* control_guess = reinterpret_cast<PetControl_guess*>(
                    entries_guess[30 + i_guess]);
                control_guess->attached_guess = buff_guess;
                control_guess->Unknown0x060 = 0;
                reinterpret_cast<WindowStyleFlags_guess*>(&control_guess->WindowStyle)->flags_guess |= 8;
                SetBuffIcon_guess(reinterpret_cast<Slot_guess*>(entries_guess[30 + i_guess]), -1, 0);

                {
                    CXStr empty_guess(EQ_ARRAY(char, 0x0063F53F));
                    static_cast<Entry_guess*>(entries_guess[30 + i_guess])->label_guess = empty_guess;
                }
                values288_guess[i_guess] = -1;
            } else {
                entries_guess[i_guess] = 0;
            }
        }

        shown305_guess = g_popup_guess->ReadFlag_guess(
            static_cast<char*>(reinterpret_cast<CXStr&>(text140_guess)), "PopupOnPet", 1, 1);
    }
}

