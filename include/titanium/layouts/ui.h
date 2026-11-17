/* include/titanium/layouts/ui.h: UI data layouts that several TUs share (no methods, no VA tokens). */
#ifndef TITANIUM_LAYOUTS_UI_H
#define TITANIUM_LAYOUTS_UI_H

/* what CSidlScreenWnd::SidlPiece (+0x124) points to; window ctors OR its style into CXWnd::WindowStyle */
struct CScreenPieceTemplate {
    /*0x00*/ char pad_000[0x60];
    /*0x60*/ unsigned int style_guess;
};

/* two fields of a 0x170 list window that some window ctors set after creating it */
struct ListFields_guess {
    /*0x000*/ char pad_000[0x15C];
    /*0x15C*/ unsigned char flag_guess;
    /*0x15D*/ char pad_15D[0xF];
    /*0x16C*/ unsigned int textColor_guess;
};

/* one 0x40-byte name of the target-name table at 0x0090424D */
struct MenuEntry_guess {
    char text_guess[0x40];
};

#endif
