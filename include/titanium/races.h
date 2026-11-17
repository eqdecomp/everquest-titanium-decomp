// Race ids (the spawn / profile race field, not the 1-16 playable index): the Titanium playable races.
// Names and values from EQEmu's common/races.h (namespace Race; Race_ prefix ours). 1-12, 128 and 130 also match
// the client's own race-name function (0x00437915), which also prints "Froglok" for 330.
#ifndef TITANIUM_RACES_H
#define TITANIUM_RACES_H

enum TitaniumRace {
    Race_Human     = 1,
    Race_Barbarian = 2,
    Race_Erudite   = 3,
    Race_WoodElf   = 4,
    Race_HighElf   = 5,
    Race_DarkElf   = 6,
    Race_HalfElf   = 7,
    Race_Dwarf     = 8,
    Race_Troll     = 9,
    Race_Ogre      = 10,
    Race_Halfling  = 11,
    Race_Gnome     = 12,
    Race_Iksar     = 128,
    Race_VahShir   = 130,
    Race_Froglok   = 330,  // EQEmu Froglok2; the playable Froglok (EQEmu's Froglok = 26 is the older, non-playable one)
};

#endif
