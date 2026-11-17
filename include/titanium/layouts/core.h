/* include/titanium/layouts/core.h: plain data layouts that several TUs share (no methods, no VA tokens).
 * Included where a TU had its own copy, at that copy's line. */
#ifndef TITANIUM_LAYOUTS_CORE_H
#define TITANIUM_LAYOUTS_CORE_H

/* MSVC virtual-base table. A class with a virtual base keeps a pointer to this table (the vbptr, at +8 in
 * EQ_Character and the classes below it); the virtual base starts at (address of the vbptr) + vbase_offset,
 * e.g. pCharData + 8 + vbptr->vbase_offset + 0x3C (= pCharData + vbase_offset + 0x44, 0x00405911) = the name. */
struct VBTable {
    /*0x0*/ int self_offset;            /* the vbptr's offset back to the start of its subobject (unused here) */
    /*0x4*/ int vbase_offset;           /* first virtual base, relative to the vbptr */
};

/* a vbptr seen as a member (the slot at +8 that holds &VBTable) */
struct VBPtr {
    /*0x0*/ VBTable* table;
};

/* a float read back as its bit pattern */
union FloatBits {
    float value;
    int bits;
};

/* the first 0x7C bytes of EQ_CharacterBase_guess (types.h, the 0x14C virtual base): its Name */
struct FeedbackCharBase_guess {
    /*0x00*/ char pad_000[0x3C];
    /*0x3C*/ char Name[0x40];
};

struct RecordLink_guess {
    /*0x00*/ char pad_000[0x10];
    /*0x10*/ int* records_guess;
};

struct ModeContext_guess {
    /*0x0000*/ char pad_0000[0x119C];
    /*0x119C*/ unsigned char class_119c_guess;  /* character class */
};

#endif
