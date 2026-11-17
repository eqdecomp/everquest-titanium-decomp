// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 11: a hint from compare/tumap.py.
// Spell focus effects: picks the best item, buff and AA focus of one SPA for a spell and applies the
// focus limit effects (SPA 134-144, 311 LimitCombatSkills, 348 LimitManaMin). tu_012's spell code calls
// the totals. Scaler_guess/Searcher_guess are views of the casting character; g_lookup_guess (0x985CC8)
// is the spell table and Lookup_guess::GetSpell_guess its get-spell-by-id.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

// EXTERNAL: TITANIUM 0x004657A6 RandNbr_guess
int __cdecl RandNbr_guess();

// EXTERNAL: TITANIUM 0x0044D011 IsFocusEffect_guess
char __cdecl IsFocusEffect_guess(int value);

struct Lookup_guess {
    int unknown_00_guess[9];
    int values_guess[20000];
    int fallback_guess;
    int GetSpell_guess(int index);
};

struct Node_guess {
    int value;
    Node_guess* previous;
    Node_guess* next;
};

struct Iterator_guess {
    int active;
    int unknown_04_guess[2];
    Node_guess* current;
    void Advance();
    int Take();
    int TakeR_guess();
    void Retreat();
    // EXTERNAL: TITANIUM 0x0040CC3D Iterator_guess::RetreatExternal_guess
    void RetreatExternal_guess();
};

struct TakeIterator_guess {
    int active;
    Node_guess* first_guess;
    int unknown_08_guess;
    Node_guess* current;
    // EXTERNAL: TITANIUM 0x0040CC0C TakeIterator_guess::Advance_guess
    void Advance_guess();
    int Take_guess();
};

struct LookupTable_guess {
    int unknown_00_guess[4];
    int values_10_guess[31];
    int values_8c_guess[5];
    unsigned char unknown_a0_guess[0x119c - 0xa0];
    unsigned char class_119c_guess;
    unsigned char unknown_119d_guess[7];
    int level_11a4_guess;
};

struct EQ_CharacterProfileView_guess {
    // EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
    LookupTable_guess* GetCharInfo2();
};

struct IndexedAccess_guess {
    int unknown_00_guess;
    EQ_CharacterProfileView_guess context;
    int GetInventorySlot_guess(unsigned int index);
    int GetSecond(unsigned int index);
};

struct Record_guess {
    int first_guess;
    int second_guess;
    int third_guess;
};

struct Holder_guess {
    int unknown_00_guess[6];
    int level_18_guess;
    int unknown_1c_guess[16];
    TakeIterator_guess iterator_5c_guess;
    // EXTERNAL: TITANIUM 0x0044791F Holder_guess::CanClassUse_guess
    char CanClassUse_guess(int bit);
};

struct Rows_guess {
    int unknown_00_guess[12];
    int base_0030_guess[12];
    int b_60_guess[12];
    int unknown_90_guess[36];
    int effectIds_0120_guess[12];
};

struct CharInfo_guess {
    unsigned char pad_000_guess[0x119c];
    unsigned char field119C_guess;
    unsigned char pad119D_guess[7];
    int field11A4_guess;
};

struct CheckEntry_guess {
    int first_guess;
    unsigned char pad004_guess[0x10];
    unsigned int field14_guess;
    unsigned char pad018_guess[8];
    unsigned int field20_guess;
    unsigned char pad024_guess[8];
    int field2C_guess;
    unsigned char pad030_guess[0xf0];
    unsigned int values120_guess[12];
    unsigned char pad150_guess[0x2d];
    unsigned char field17D_guess;
    unsigned char pad17E_guess;
    unsigned char field17F_guess;
    unsigned char field180_guess;
    unsigned char pad181_guess[0x43];
    unsigned char field1C4_guess;
    // EXTERNAL: TITANIUM 0x0044E755 CheckEntry_guess::Check_guess
    unsigned char Check_guess(int value);
};

struct Searcher_guess : virtual EQ_Character {
    virtual void Slot00_guess();
    // EXTERNAL: TITANIUM 0x0040EBC3 Searcher_guess::SpellDuration_guess
    int SpellDuration_guess(CheckEntry_guess* entry, int a, int b);
    int CheckFocusLimit_guess(int entry, int code, int value, int scale, int other);
    int CheckSpellFocusLimits_guess(int obj, Rows_guess* rows, int flag);
    int CheckAAFocusLimits_guess(int obj, Holder_guess* holder);
};

// Inclusive range; `first` when the range is empty or reversed.
// FUNCTION: TITANIUM 0x0040CBB2
int __cdecl RandomRange_guess(int first, int last) {
    if (first >= last) {
        return first;
    }
    return RandNbr_guess() % (last - first + 1) + first;
}

// Spell record by id; ids outside 0-9999 get fallback_guess.
// FUNCTION: TITANIUM 0x0040CBD6
int Lookup_guess::GetSpell_guess(int index) {
    if (index < 0 || index >= 10000) {
        return fallback_guess;
    }
    return values_guess[index];
}

// Steps the list iterator to the next node, when it is active and not at the end.
// FUNCTION: TITANIUM 0x0040CC0C
void Iterator_guess::Advance() {
    if (active != 0 && current != 0) {
        current = current->next;
    }
}

// Returns the current node's value and steps forward; 0 at the end.
// FUNCTION: TITANIUM 0x0040CC1F
int TakeIterator_guess::Take_guess() {
    if (active != 0 && current != 0) {
        Node_guess* node = current;
        Advance_guess();
        if (node) return node->value;
    }
    return 0;
}

// Steps the list iterator to the previous node, when it is active and has a current node.
// FUNCTION: TITANIUM 0x0040CC3D
void Iterator_guess::Retreat() {
    if (active != 0 && current != 0) {
        current = current->previous;
    }
}

// Item in inventory slot `index` (0-30: worn 0-21, general 22-29, cursor 30).
// FUNCTION: TITANIUM 0x0040CC50
int IndexedAccess_guess::GetInventorySlot_guess(unsigned int index) {
    LookupTable_guess* table = context.GetCharInfo2();
    int* values = table->values_10_guess;
    if (index >= 31) {
        __debugbreak();
    }
    return values[index];
}

// Item in one of a second set of 5 slots (table +0x8C), probably the tribute slots.
// FUNCTION: TITANIUM 0x0040CC6B
int IndexedAccess_guess::GetSecond(unsigned int index) {
    LookupTable_guess* table = context.GetCharInfo2();
    int* values = table->values_8c_guess;
    if (index >= 5) {
        __debugbreak();
    }
    return values[index];
}

// Returns the current node's value and steps back; 0 at the start.
// FUNCTION: TITANIUM 0x0040CEA6
int Iterator_guess::TakeR_guess() {
    if (active != 0 && current != 0) {
        Node_guess* node = current;
        RetreatExternal_guess();
        if (node != 0) {
            return node->value;
        }
    }
    return 0;
}

// One focus limit: 100 = passes, 0 = blocked, in between = partly applies. `code` is the limit SPA, `value`
// its base and `scale` its base2; the class and level come from `other` when given, else this. 134
// LimitMaxLevel: each level over the cap loses `scale` percent. 135 LimitResist (+0x17F) must equal
// `value`. 136 LimitTarget (+0x180) and 139 LimitSpell (id) exclude instead when `value` is negative. 137
// LimitEffect searches the 12 effect ids (+0x120); the pet summons 33, 71 and 106 count as one. 138
// LimitSpellType (+0x17D); 140 LimitMinDur (duration at the caster's level); 141 LimitInstant fails any
// spell with a duration formula (+0x20), whatever `value` is; 142 LimitMinLevel (the spell's level for the
// caster's class); 143/144 LimitCastTimeMin/Max (+0x14, ms); 311 LimitCombatSkills (+0x1C4); 348
// LimitManaMin (+0x2C). Other codes pass.
// FUNCTION: TITANIUM 0x0040CC88
// @early-stop: budget, structural ndiff=233
int Searcher_guess::CheckFocusLimit_guess(int entryValue, int code, int value, int scale, int otherValue) {
    CheckEntry_guess* entry = (CheckEntry_guess*)entryValue;
    if (entry == 0) {
        return 0;
    }
    Searcher_guess* target = otherValue ? (Searcher_guess*)otherValue : this;
    int result = 100;
    if (code > 0x137) {
        if (code != 0x15c) {
            return 100;
        }
        if (entry->field2C_guess < value) {
            result = 0;
        }
        return result;
    }
    if (code == 0x137) {
        if (entry->field1C4_guess != (value != 0)) {
            result = 0;
        }
        return result;
    }
    switch (code) {
    case 0x86: {
        CharInfo_guess* info = (CharInfo_guess*)target->GetCharInfo2();
        int level = entry->Check_guess(info->field119C_guess);
        if (level <= value) {
            return 100;
        }
        if (scale == 0) {
            return 0;
        }
        info = (CharInfo_guess*)target->GetCharInfo2();
        level = entry->Check_guess(info->field119C_guess);
        return 100 - (level - value) * scale;
    }
    case 0x87:
        if (entry->field17F_guess != value) {
            result = 0;
        }
        break;
    case 0x88:
        if (value > 0) {
            if (entry->field180_guess != value) {
                result = 0;
            }
        } else if (entry->field180_guess == -value) {
            result = 0;
        }
        break;
    case 0x89: {
        bool positive = value >= 0;
        if (!positive) {
            value = -value;
        }
        bool found = false;
        unsigned int slot = 0;
        do {
            if (slot >= 0x30) {
                __debugbreak();
            }
            unsigned int id = entry->values120_guess[slot / 4];
            if (id == 0xfe) {
                break;
            }
            if (value == (int)id ||
                ((id == 0x21 || id == 0x6a || id == 0x47) && (value == 0x21 || value == 0x6a || value == 0x47))) {
                found = true;
                break;
            }
            slot += 4;
        } while (slot < 0x30);
        if (found != positive) {
            result = 0;
        }
        break;
    }
    case 0x8a:
        if (entry->field17D_guess != value) {
            result = 0;
        }
        break;
    case 0x8b:
        if (value > 0) {
            if (entry->first_guess != value) {
                result = 0;
            }
        } else if (-entry->first_guess == value) {
            result = 0;
        }
        break;
    case 0x8c: {
        CharInfo_guess* info = (CharInfo_guess*)target->GetCharInfo2();
        int r = SpellDuration_guess(entry, info->field11A4_guess, 0);
        if (r < value) {
            result = 0;
        }
        break;
    }
    case 0x8d:
        if (entry->field20_guess != 0) {
            result = 0;
        }
        break;
    case 0x8e: {
        CharInfo_guess* info = (CharInfo_guess*)target->GetCharInfo2();
        int r = entry->Check_guess(info->field119C_guess);
        if (r < value) {
            result = 0;
        }
        break;
    }
    case 0x8f:
        if (entry->field14_guess < (unsigned int)value) {
            result = 0;
        }
        break;
    case 0x90:
        if (entry->field14_guess > (unsigned int)value) {
            result = 0;
        }
        break;
    default:
        break;
    }
    return result;
}

// Lowest limit result over effect slots 1-11 of a focus spell (slot 0 is the focus itself), stopping at
// the first 254 (SPA Blank) or once a limit blocks. The repeated bounds checks are match shape.
// FUNCTION: TITANIUM 0x0040CEC4
// @early-stop: budget, structural ndiff=29
int Searcher_guess::CheckSpellFocusLimits_guess(int obj, Rows_guess* rows, int flag) {
    int best = 100;
    int i = 1;
    do {
        if (i >= 12) {
            break;
        }
        if (i >= 12) {
            __debugbreak();
        }
        if (rows->effectIds_0120_guess[i] == 0xfe) {
            return best;
        }
        if (i >= 12) {
            __debugbreak();
        }
        int v = CheckFocusLimit_guess(obj, rows->effectIds_0120_guess[i], rows->base_0030_guess[i], rows->b_60_guess[i], flag);
        if (v < best) {
            best = v;
        }
        ++i;
    } while (best > 0);
    return best;
}

// AA version of Searcher_guess::CheckSpellFocusLimits_guess: the limit records that follow the current focus
// record in the AA's effect list, up to the next focus effect (IsFocusEffect_guess).
// FUNCTION: TITANIUM 0x0040CF30
int Searcher_guess::CheckAAFocusLimits_guess(int obj, Holder_guess* holder) {
    if (obj == 0 || holder == 0) {
        return 0;
    }
    int best = 100;
    Record_guess* rec = (Record_guess*)holder->iterator_5c_guess.Take_guess();
    do {
        if (rec == 0) {
            break;
        }
        if (IsFocusEffect_guess(rec->first_guess) != 0) {
            return best;
        }
        int v = CheckFocusLimit_guess(obj, rec->first_guess, rec->second_guess, rec->third_guess, 0);
        if (v < best) {
            best = v;
        }
        rec = (Record_guess*)holder->iterator_5c_guess.Take_guess();
    } while (best > 0);
    return best;
}

// EXTERNAL: TITANIUM 0x0044D0D0 IsValidSpellIndex_guess
char __cdecl IsValidSpellIndex_guess(int value);

struct Source_guess {
    // EXTERNAL: TITANIUM 0x005ECD20 Source_guess::Pick_guess
    int Pick_guess(int index);
};

struct Entry_guess {
    int unknown_00_guess;
    int value_04_guess;
    int unknown_08_guess[10];
    int value_30_guess;
};

struct SearchEntry_guess {
    unsigned char active_guess;
    unsigned char pad_001_guess[3];
    int id_guess;
};

struct Scaler_guess : Searcher_guess, virtual IndexedAccess_guess {
    // Slots 01 through 05 follow the inherited slot 00.
    virtual int Slot01_guess();
    virtual int Slot02_guess();
    virtual int Slot03_guess();
    virtual int Slot04_guess();
    virtual int Slot05_guess(int index);
    // EXTERNAL: TITANIUM 0x0040D933 Scaler_guess::GetMaxBuffs_guess
    unsigned char GetMaxBuffs_guess();
    // EXTERNAL: TITANIUM 0x0040E7AC Scaler_guess::GetBuff_guess
    SearchEntry_guess* GetBuff_guess(int index);
    int GetItemFocus_guess(int id, int type, int* scale);
    int GetBuffFocus_guess(int id, int type, int* scale, int a, int b);
    // EXTERNAL: TITANIUM 0x0040D3B1 Scaler_guess::GetAAFocus_guess
    int GetAAFocus_guess(int id, int type, int* scale);
    int GetFocusReagentSaveChance_guess(int id, int* out);
    int GetFocusCastingTimeModifier(int id, int* out);
    int GetFocusRangeModifier_guess(int id, int* out);
};

struct Registry_guess {
    // EXTERNAL: TITANIUM 0x005F0910 Registry_guess::Get_guess
    int Get_guess(int index);
};

struct Manager_guess {
    // EXTERNAL: TITANIUM 0x00447D07 Manager_guess::GetAltAbility
    Holder_guess* GetAltAbility(int id);
};

#define g_manager_guess EQ_GLOBAL(Manager_guess*, 0x008511D8)

struct SearchBase_guess {
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
    virtual Registry_guess* Slot16_guess();
    EQ_CharacterProfileView_guess context;
    LookupTable_guess* Lookup_guess() { return context.GetCharInfo2(); }
};

struct PickerOwner_guess {
    unsigned char unknown_00_guess[0x244];
    unsigned char flag_244_guess;
};

struct PickerUnit_guess {
    unsigned char unknown_00_guess[0x1c4];
    unsigned char flag_1c4_guess;
    unsigned char unknown_1c5_guess[0x269 - 0x1c5];
    unsigned char flag_269_guess;
};

struct Picker_guess : virtual SearchBase_guess {
    virtual void Dispatch_guess();
    PickerOwner_guess* owner_8_guess;
    Record_guess* GetAAFocus_guess(PickerUnit_guess* unit, int wanted, int* score);
};

struct Owner_guess {
    int unknown_00_guess[5];
    int rate_14_guess;
};

struct Entity_guess {
    unsigned char pad_000_guess[0x1c4];
    unsigned char field_1c4_guess;
    unsigned char pad_1c5_guess[0x269 - 0x1c5];
    unsigned char field_269_guess;
};

struct Cand_guess {
    // EXTERNAL: TITANIUM 0x005E0BF0 Cand_guess::GetA_guess
    int GetA_guess();
    // EXTERNAL: TITANIUM 0x005E0BC0 Cand_guess::GetB_guess
    int GetB_guess();
    // EXTERNAL: TITANIUM 0x005ECCC0 Cand_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECD20 Cand_guess::GetD_guess
    int GetD_guess(int kind);
    // EXTERNAL: TITANIUM 0x005EC630 Cand_guess::GetE_guess
    int GetE_guess(int index);
};

#define g_lookup_guess EQ_GLOBAL(Lookup_guess*, 0x00985CC8)

// Best focus of SPA `wanted` among the caster's buffs, its limit result in `*outIndex`. `index` nonzero
// skips the class test; `flag` is the target passed to the limit checks. A negative focus (a penalty)
// wins over every positive one. Warriors, Monks, Bards and Rogues get foci only on spells with +0x1C4
// set (the LimitCombatSkills flag); spells with +0x269 set get none.
// FUNCTION: TITANIUM 0x0040D1E5
// @early-stop: budget, structural ndiff=134
int Scaler_guess::GetBuffFocus_guess(int object, int wanted, int* outIndex, int index, int flag) {
    if (object == 0 || ((Entity_guess*)object)->field_269_guess != 0 ||
        (index == 0 &&
         (((CharInfo_guess*)GetCharInfo2())->field119C_guess == 8 ||
          ((CharInfo_guess*)GetCharInfo2())->field119C_guess == 1 ||
          ((CharInfo_guess*)GetCharInfo2())->field119C_guess == 9 ||
          ((CharInfo_guess*)GetCharInfo2())->field119C_guess == 7) &&
         ((Entity_guess*)object)->field_1c4_guess == 0)) {
        return 0;
    }

    int best = 0;
    int worst = 0;
    int bestScaled = 0;
    int worstScaled = 0;
    int bestIndex = 100;
    int worstIndex = 100;
    index = 0;
    if (GetMaxBuffs_guess() != 0) {
        do {
            SearchEntry_guess* entry = GetBuff_guess(index);
            if (entry->active_guess != 0) {
                int id = entry->id_guess;
                if (IsValidSpellIndex_guess(id) != 0) {
                    Rows_guess* row = (Rows_guess*)g_lookup_guess->GetSpell_guess(id);
                    if (row != 0 && row->effectIds_0120_guess[0] == wanted) {
                        int score = Searcher_guess::CheckSpellFocusLimits_guess(object, row, flag);
                        if (score > 0) {
                            int scaled = (row->base_0030_guess[0] * score) / 100;
                            if (scaled < worstScaled) {
                                worstIndex = score;
                                worstScaled = scaled;
                                worst = g_lookup_guess->GetSpell_guess(id);
                            } else {
                                if (scaled <= bestScaled && best != 0 && worst != 0) {
                                    ++index;
                                    continue;
                                }
                                if (worst == 0) {
                                    worstIndex = score;
                                    worstScaled = scaled;
                                    worst = g_lookup_guess->GetSpell_guess(id);
                                }
                            }
                            if (scaled > bestScaled || best == 0) {
                                bestIndex = score;
                                bestScaled = scaled;
                                best = g_lookup_guess->GetSpell_guess(id);
                            }
                        }
                    }
                }
            }
            ++index;
        } while (index < (int)GetMaxBuffs_guess());
        if (worstScaled < 0) {
            *outIndex = worstIndex;
            return worst;
        }
    }
    *outIndex = bestIndex;
    return best;
}

// Best AA focus record (effect, base, base2) of SPA `wanted`: walks the 240 AA slots, keeping AAs for
// the caster's class and level whose list starts with a focus effect. Unlike the item and buff search
// there is no negative case, and ties go to the later AA. Declared as Scaler_guess::GetAAFocus_guess above.
// FUNCTION: TITANIUM 0x0040D3B1
// @early-stop: unknown, diff ndiff=10
Record_guess* Picker_guess::GetAAFocus_guess(PickerUnit_guess* unit, int wanted, int* score) {
    if (owner_8_guess == 0 || owner_8_guess->flag_244_guess != 0 || unit == 0 || unit->flag_269_guess != 0) {
        return 0;
    }
    Registry_guess* registry = Slot16_guess();
    if (Lookup_guess()->class_119c_guess == 8 || Lookup_guess()->class_119c_guess == 1 ||
        Lookup_guess()->class_119c_guess == 9 || Lookup_guess()->class_119c_guess == 7) {
        if (unit->flag_1c4_guess == 0) {
            return 0;
        }
    }
    Record_guess* best = 0;
    int best_score = 100;
    int best_weight = 0;
    int index = 0;
    do {
        Holder_guess* holder = g_manager_guess->GetAltAbility(registry->Get_guess(index));
        if (holder != 0 && holder->CanClassUse_guess(Lookup_guess()->class_119c_guess)) {
            int level = holder->level_18_guess;
            if (level <= Lookup_guess()->level_11a4_guess) {
                TakeIterator_guess* iterator = &holder->iterator_5c_guess;
                iterator->current = iterator->first_guess;
                Record_guess* record = (Record_guess*)iterator->Take_guess();
                if (record != 0 && IsFocusEffect_guess(record->first_guess) != 0) {
                    do {
                        if (record->first_guess == wanted) {
                            int value = ((Searcher_guess*)this)->CheckAAFocusLimits_guess((int)unit, holder);
                            if (value > 0) {
                                int weight = record->second_guess * value / 100;
                                if (best == 0 || best_weight <= weight) {
                                    best_score = value;
                                    best_weight = weight;
                                    best = record;
                                }
                            }
                        }
                        ((Iterator_guess*)iterator)->TakeR_guess();
                        Record_guess* next = (Record_guess*)iterator->Take_guess();
                        if (next == record) {
                            next = (Record_guess*)iterator->Take_guess();
                        }
                        record = next;
                    } while (record != 0);
                }
            }
        }
        ++index;
    } while (index < 0xf0);
    *score = best_score;
    return best;
}

// SPA 131 ReduceReagentCost: percent chance to keep one reagent, summed over the best item, buff and AA
// focus. tu_012's cast code rolls 1-100 against it.
// FUNCTION: TITANIUM 0x0040D59B
int Scaler_guess::GetFocusReagentSaveChance_guess(int id, int* out) {
    int total = 0;
    int scale = 100;
    int src = GetItemFocus_guess(id, 0x83, &scale);
    if (src != 0) {
        if (out != 0) {
            *out = src;
        }
        int slot = ((Source_guess*)src)->Pick_guess(3);
        if (IsValidSpellIndex_guess(slot) != 0) {
            int entry = g_lookup_guess->GetSpell_guess(slot);
            if (entry != 0) {
                int share = (((Entry_guess*)entry)->value_30_guess * scale) / 100;
                if (share > 0) {
                    total = share;
                }
            }
        }
    }
    int extra = GetBuffFocus_guess(id, 0x83, &scale, 0, 0);
    if (extra != 0) {
        int share = (((Entry_guess*)extra)->value_30_guess * scale) / 100;
        if (share > 0) {
            total = total + share;
        }
    }
    int other = GetAAFocus_guess(id, 0x83, &scale);
    if (other != 0) {
        int share = (((Entry_guess*)other)->value_04_guess * scale) / 100;
        if (share > 0) {
            total = total + share;
        }
    }
    return total;
}

// SPA 127 IncreaseSpellHaste: cast-time change in ms (negative = faster), each source's percent of the
// spell's cast time (+0x14); best item, buff and AA focus added.
// FUNCTION: TITANIUM 0x0040D663
int Scaler_guess::GetFocusCastingTimeModifier(int id, int* out) {
    int total = 0;
    int scale = 100;
    int src = GetItemFocus_guess(id, 0x7f, &scale);
    if (src != 0) {
        if (out != 0) {
            *out = src;
        }
        int slot = ((Source_guess*)src)->Pick_guess(3);
        if (IsValidSpellIndex_guess(slot) != 0) {
            int entry = g_lookup_guess->GetSpell_guess(slot);
            if (entry != 0) {
                total = (((Entry_guess*)entry)->value_30_guess * scale) / -100 * ((Owner_guess*)id)->rate_14_guess / 100;
            }
        }
    }
    int extra = GetBuffFocus_guess(id, 0x7f, &scale, 0, 0);
    if (extra != 0) {
        total = total + (((Entry_guess*)extra)->value_30_guess * scale) / -100 * ((Owner_guess*)id)->rate_14_guess / 100;
    }
    int other = GetAAFocus_guess(id, 0x7f, &scale);
    if (other != 0) {
        total = total + (((Entry_guess*)other)->value_04_guess * scale) / -100 * ((Owner_guess*)id)->rate_14_guess / 100;
    }
    return total;
}

struct Factor_guess {
    int unknown_00_guess;
    float rate_04_guess;
};

#define g_magicRate_guess EQ_GLOBAL(float, 0x00640038)

// Best focus of SPA `kind_guess` among the caster's items: worn slots 0-20 (not ammo), the 5 slots of
// GetSecond, two more from Slot05_guess, and up to 10 items inside each. GetD_guess(3) is
// probably the item's focus spell. Limit result in `*out_guess`; a negative focus wins as in
// GetBuffFocus_guess.
// FUNCTION: TITANIUM 0x0040CF9B
// @early-stop: budget, structural ndiff=99
int Scaler_guess::GetItemFocus_guess(int id, int kind_guess, int* out_guess) {
    int object_guess = id;
    Searcher_guess* self_guess = this;
    if (object_guess == 0 || ((Entity_guess*)object_guess)->field_269_guess != 0 ||
        (((CharInfo_guess*)self_guess->GetCharInfo2())->field119C_guess == 8 ||
         ((CharInfo_guess*)self_guess->GetCharInfo2())->field119C_guess == 1 ||
         ((CharInfo_guess*)self_guess->GetCharInfo2())->field119C_guess == 9 ||
         ((CharInfo_guess*)self_guess->GetCharInfo2())->field119C_guess == 7) &&
            ((Entity_guess*)object_guess)->field_1c4_guess == 0) {
        return 0;
    }

    int candidates[28];
    int count = 0;
    int hi_pick = 0;
    int lo_pick = 0;
    int hi_score = 0;
    int hi_check = 100;
    int lo_score = 0;
    int lo_check = 100;
    for (int i = 0; i < 0x15; ++i) {
        candidates[count++] = GetInventorySlot_guess(i);
    }
    for (int i = 0; i < 5; ++i) {
        candidates[count++] = GetSecond(i);
    }
    for (int i = 0; i < 2; ++i) {
        candidates[count++] = Slot05_guess(i);
    }

    for (int idx = 0; idx < count; ++idx) {
        int candidate = candidates[idx];
        if (candidate != 0 && ((Cand_guess*)candidate)->GetItemClass_guess() == 0) {
            int c = 0;
            do {
                bool ok = true;
                if (candidate != 0) {
                    if (((Cand_guess*)candidate)->GetA_guess() != 0 &&
                        ((Cand_guess*)candidate)->GetB_guess() <= 0) {
                        ok = false;
                    }
                    if (((Cand_guess*)candidate)->GetItemClass_guess() == 0 && ok) {
                        int value = ((Cand_guess*)candidate)->GetD_guess(3);
                        if (IsValidSpellIndex_guess(value) != 0) {
                            Rows_guess* row = (Rows_guess*)g_lookup_guess->GetSpell_guess(value);
                            if (row != 0 && row->effectIds_0120_guess[0] == kind_guess) {
                                int score = self_guess->Searcher_guess::CheckSpellFocusLimits_guess(object_guess, row, 0);
                                if (score > 0) {
                                    int weight = (row->base_0030_guess[0] * score) / 100;
                                    if (weight > hi_score || hi_pick == 0) {
                                        hi_score = weight;
                                        hi_check = score;
                                        hi_pick = candidate;
                                    }
                                    if (weight < lo_score || lo_pick == 0) {
                                        lo_score = weight;
                                        lo_check = score;
                                        lo_pick = candidate;
                                    }
                                }
                            }
                        }
                    }
                }
                if (c < 10) {
                    candidate = ((Cand_guess*)candidates[idx])->GetE_guess(c);
                }
                ++c;
            } while (c < 11);
        }
    }

    if (lo_score < 0) {
        *out_guess = lo_check;
        return lo_pick;
    }
    *out_guess = hi_check;
    return hi_pick;
}

// SPA 129 IncreaseRange: extra range, each source's percent of the spell's range (+0x04; the 0.01 is the
// float at 0x640038); best item, buff and AA focus added.
// FUNCTION: TITANIUM 0x0040D738
int Scaler_guess::GetFocusRangeModifier_guess(int id, int* out) {
    int total = 0;
    int scale = 100;
    int src = GetItemFocus_guess(id, 0x81, &scale);
    if (src != 0) {
        if (out != 0) {
            *out = src;
        }
        int slot = ((Source_guess*)src)->Pick_guess(3);
        if (IsValidSpellIndex_guess(slot) != 0) {
            int entry = g_lookup_guess->GetSpell_guess(slot);
            if (entry != 0) {
                int share = (((Entry_guess*)entry)->value_30_guess * scale) / 100;
                total = (int)((float)share * ((Factor_guess*)id)->rate_04_guess * g_magicRate_guess);
            }
        }
    }
    int extra = GetBuffFocus_guess(id, 0x81, &scale, 0, 0);
    if (extra != 0) {
        int share = (((Entry_guess*)extra)->value_30_guess * scale) / 100;
        total = total + (int)((float)share * ((Factor_guess*)id)->rate_04_guess * g_magicRate_guess);
    }
    int other = GetAAFocus_guess(id, 0x81, &scale);
    if (other != 0) {
        int share = (((Entry_guess*)other)->value_04_guess * scale) / 100;
        total = total + (int)((float)share * ((Factor_guess*)id)->rate_04_guess * g_magicRate_guess);
    }
    return total;
}
