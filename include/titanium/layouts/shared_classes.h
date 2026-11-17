/* include/titanium/layouts/shared_classes.h: classes that several TUs declared on their own, merged into one
 * layout (data members plus method declarations; no bodies, no special members, no virtuals).
 * The TUs that define a method keep its `// FUNCTION:` definition; the markers here name the same VAs. */
#ifndef TITANIUM_LAYOUTS_SHARED_CLASSES_H
#define TITANIUM_LAYOUTS_SHARED_CLASSES_H

/* Partial CDisplay view (pinstCDisplay 0x00905D24) under its legacy name; not a separate clock object.
 * +0x148 holds timing state (tu_062 timers). Extent incomplete. */
struct ClockData_guess {
    /*0x0000*/ unsigned char pad_0000[0x8];
    /*0x0008*/ int yon_0008_guess;  // raw bits of the float yon distance (0x0043C80E fld), not an integer
    /*0x000C*/ unsigned char pad_000C[0x4];
    /*0x0010*/ unsigned char field10_guess;
    /*0x0011*/ unsigned char field11_guess;
    /*0x0012*/ unsigned char field12_guess;
    /*0x0013*/ unsigned char pad_0013[0x148 - 0x13];
    /*0x0148*/ unsigned int current_guess;
    /*0x014C*/ unsigned char pad_014C[0x28E8 - 0x14C];
    /*0x28E8*/ float fieldOfView_28e8_guess;

    // EXTERNAL: TITANIUM 0x0043C78F ClockData_guess::ChangeVideoMode_guess
    void ChangeVideoMode_guess();
    // EXTERNAL: TITANIUM 0x00440F42 ClockData_guess::SetYon_guess
    void SetYon_guess(int value);  // takes the float's bits, not an integer distance
    // EXTERNAL: TITANIUM 0x00440F51 ClockData_guess::SetViewAngle
    void SetViewAngle(int value);
    // EXTERNAL: TITANIUM 0x004396DF ClockData_guess::PickActorAt_guess
    // Legacy integer result contains the picked actor address (or zero); outputs are raw buffers.
    int PickActorAt_guess(int first_guess, int second_guess, bool select_guess,
        int* firstOutput_guess, int* secondOutput_guess);
    // EXTERNAL: TITANIUM 0x0043D7C5 ClockData_guess::MoveLocalPlayerToSafeCoords_guess
    void MoveLocalPlayerToSafeCoords_guess();
    // EXTERNAL: TITANIUM 0x0043745D ClockData_guess::GetValue2cf8_guess
    int GetValue2cf8_guess();
};

/* a [low, high] range with the squares and the span cached */
struct FloatRange_guess {
    float low_guess;
    float high_guess;
    float low_square_guess;
    float high_square_guess;
    float span_guess;

    // EXTERNAL: TITANIUM 0x004C0AF7 FloatRange_guess::Set_guess
    void Set_guess(float first_guess, float second_guess);
    // EXTERNAL: TITANIUM 0x004C0B38 FloatRange_guess::Fraction_guess
    float Fraction_guess(float value_guess);
};

/* two int tables, the second one right after the first's 0x42C bytes */
struct PointerTable_guess {
    int first_guess[0x42C / 4];
    int second_guess[1];

    // EXTERNAL: TITANIUM 0x004B244F PointerTable_guess::First_guess
    int* First_guess(int index);
    // EXTERNAL: TITANIUM 0x004B2459 PointerTable_guess::Second_guess
    int* Second_guess(int index);
};

/* Partial CXWndManager view (0x0099D3EC; core_decls.h CXWndManager), not a render surface.
 * Width/height at +0xEC/+0xF0. Merge into CXWndManager in a gated follow-up. */
struct RenderTarget_guess {
    /*0x00*/ char pad_000[0xEC];
    /*0xEC*/ int width_guess;
    /*0xF0*/ int height_guess;

    // EXTERNAL: TITANIUM 0x005B0B80 RenderTarget_guess::FUN_005b0b80_guess
    int FUN_005b0b80_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B0050 RenderTarget_guess::FUN_005b0050_guess
    void FUN_005b0050_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B0230 RenderTarget_guess::FUN_005b0230_guess
    int FUN_005b0230_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B1480 RenderTarget_guess::FUN_005b1480_guess
    int FUN_005b1480_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B03E0 RenderTarget_guess::FUN_005b03e0_guess
    int FUN_005b03e0_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B0140 RenderTarget_guess::FUN_005b0140_guess
    void FUN_005b0140_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B0530 RenderTarget_guess::FUN_005b0530_guess
    int FUN_005b0530_guess(int* position_guess);
    // EXTERNAL: TITANIUM 0x005B1580 RenderTarget_guess::FUN_005b1580_guess
    void FUN_005b1580_guess(int* position_guess);
};

#endif
