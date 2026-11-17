// Titanium inventory slot numbers: indexes into the character's 31-entry item array (worn slots, the eight
// general slots, then the cursor), and the first slot of the bank, shared bank, trade and world inventories.
// Names and values from EQEmu's titanium_limits.h (namespace invslot); the InvSlot_ prefix and CamelCase are ours.
#ifndef TITANIUM_SLOTS_H
#define TITANIUM_SLOTS_H

enum TitaniumInvSlot {
    InvSlot_Charm      = 0,
    InvSlot_Ear1       = 1,
    InvSlot_Head       = 2,
    InvSlot_Face       = 3,
    InvSlot_Ear2       = 4,
    InvSlot_Neck       = 5,
    InvSlot_Shoulders  = 6,
    InvSlot_Arms       = 7,
    InvSlot_Back       = 8,
    InvSlot_Wrist1     = 9,
    InvSlot_Wrist2     = 10,
    InvSlot_Range      = 11,
    InvSlot_Hands      = 12,
    InvSlot_Primary    = 13,
    InvSlot_Secondary  = 14,
    InvSlot_Finger1    = 15,
    InvSlot_Finger2    = 16,
    InvSlot_Chest      = 17,
    InvSlot_Legs       = 18,
    InvSlot_Feet       = 19,
    InvSlot_Waist      = 20,
    InvSlot_Ammo       = 21,
    InvSlot_General1   = 22,
    InvSlot_General2   = 23,
    InvSlot_General3   = 24,
    InvSlot_General4   = 25,
    InvSlot_General5   = 26,
    InvSlot_General6   = 27,
    InvSlot_General7   = 28,
    InvSlot_General8   = 29,
    InvSlot_Cursor     = 30,

    InvSlot_EquipmentCount   = 22,  // worn slots are 0 .. InvSlot_Ammo
    InvSlot_PossessionsCount = 31,  // size of the item array; bag slot numbers start here

    // first slot number of the other inventories (EQEmu BANK_BEGIN, SHARED_BANK_BEGIN, TRADE_BEGIN, WORLD_BEGIN)
    InvSlot_BankBegin        = 2000,
    InvSlot_SharedBankBegin  = 2500,
    InvSlot_TradeBegin       = 3000,
    InvSlot_WorldBegin       = 4000,
};

#endif
