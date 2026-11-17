/* include/titanium/layouts/sidl_base.h: CSidlScreenWndBase, the polymorphic base that TU window classes derive
 * from when they define their own ctor/dtor (core_decls' CSidlScreenWnd stays a non-virtual view).
 * Synthetic 0x15C code-generation view of CSidlScreenWnd (fields at MQ2 offsets). Its lone virtual dtor is a
 * compiler placeholder, not the real slot layout: slot 0 reads byte +0x118 (0x004079D1), slot 1 is the deleting
 * dtor (0x005A3340). Do not use it for virtual dispatch or delete through the base.
 * TUs whose local base declares more slots keep their own class.
 * The _guess fields are the ones the user TUs read or write (offsets from their own code). */
#ifndef TITANIUM_LAYOUTS_SIDL_BASE_H
#define TITANIUM_LAYOUTS_SIDL_BASE_H

#include "titanium/layouts/ui.h"

struct CXWnd;
struct CXStr;

struct CSidlScreenWndBase {
    // EXTERNAL: TITANIUM 0x005A3100 ??1CSidlScreenWndBase@@UAE@XZ
    virtual ~CSidlScreenWndBase();
    /*0x004*/ char pad_004[0x13];
    /*0x017*/ unsigned char field_017_guess;       /* CContainerWnd ctor */
    /*0x018*/ unsigned char field_018_guess;       /* several window ctors set it */
    /*0x019*/ char pad_019[0x43];
    /*0x05C*/ unsigned char Show;                  /* CXWnd::Show */
    /*0x05D*/ char pad_05D[0x7];
    /*0x064*/ unsigned int WindowStyle;            /* CXWnd::WindowStyle */
    /*0x068*/ char pad_068[0x14];
    /*0x07C*/ int field_07C_guess;
    /*0x080*/ char pad_080[0xC];
    /*0x08C*/ unsigned char field_08C_guess;
    /*0x08D*/ char pad_08D[0x97];
    /*0x124*/ CScreenPieceTemplate* SidlPiece;     /* window ctors OR its style into WindowStyle */
    /*0x128*/ char pad_128[0x30];
    /*0x158*/ int field_158_guess;

    // EXTERNAL: TITANIUM 0x005A3850 ??0CSidlScreenWndBase@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    CSidlScreenWndBase(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3900 ??0CSidlScreenWndBase@@QAE@PAUCXWnd@@ABUCXStr@@@Z
    CSidlScreenWndBase(CXWnd* parent, const CXStr& screen);
    // EXTERNAL: TITANIUM 0x0059DB90 ?FUN_0059db90_guess@CSidlScreenWndBase@@QAEXH@Z
    void FUN_0059db90_guess(int value);          /* a CXWnd method; ctors pass 20, 100, 199, 200 or 300 */
};

#endif
