/* The shared base of the window singletons' classes (titanium/wnd/<Class>.h): the CSidlScreenWnd virtual
 * slots, so that a TU can call a window's slot through its pinst* global without a per-TU view or a cast.
 *
 * Unlike core_decls.h's CSidlScreenWnd, this class is polymorphic, so a slot call stays an indirect call. The slot
 * order is the CXWnd vtable 0x006644F0 / CSidlScreenWnd vtable 0x006646F8 (both checked against the binary).
 * A slot whose signature is not established keeps the placeholder form `void SlotNN_guess()`: it only holds the
 * slot's position and must not be called (its comment gives the stack bytes the base implementation pops).
 * A user TU never constructs a window except through its out-of-line constructor, and nothing here has a
 * body, so no vtable is emitted from these declarations.
 * Data: 0x15C bytes as in core_decls.h's CSidlScreenWnd; only the members a user TU reads are named.
 */
#ifndef TITANIUM_WND_VIEWS_H
#define TITANIUM_WND_VIEWS_H

#include "titanium/eqaddr.h"

struct CXWnd;

struct CSidlScreenWndVirtuals_guess {
    /*0x000*/ virtual unsigned char Slot00_guess();    /* returns byte +0x118 (0x004079D1) */
    /*0x004*/ virtual void* Release_guess(unsigned int flags);    /* scalar deleting destructor */
    /*0x008*/ virtual void Slot02_guess();
    /*0x00C*/ virtual void Slot03_guess();
    /*0x010*/ virtual void Slot04_guess();
    /*0x014*/ virtual void Slot05_guess();    /* placeholder, not callable: the base pops 12 bytes */
    /*0x018*/ virtual void Slot06_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x01C*/ virtual void Slot07_guess();
    /*0x020*/ virtual void Slot08_guess();
    /*0x024*/ virtual void Slot09_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x028*/ virtual void Slot10_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x02C*/ virtual void Slot11_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x030*/ virtual void Slot12_guess();
    /*0x034*/ virtual void Slot13_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x038*/ virtual void Slot14_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x03C*/ virtual void Slot15_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x040*/ virtual void Slot16_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x044*/ virtual void Slot17_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x048*/ virtual void Slot18_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x04C*/ virtual void Slot19_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x050*/ virtual void Slot20_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x054*/ virtual void Slot21_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x058*/ virtual void Slot22_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x05C*/ virtual void Slot23_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x060*/ virtual void Slot24_guess();    /* placeholder, not callable: the base pops 12 bytes */
    /*0x064*/ virtual void Slot25_guess();    /* placeholder, not callable: the base pops 12 bytes */
    /*0x068*/ virtual void Slot26_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x06C*/ virtual void Slot27_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x070*/ virtual void Slot28_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x074*/ virtual void Slot29_guess();    /* placeholder, not callable: the base pops 12 bytes */
    /*0x078*/ virtual void Slot30_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x07C*/ virtual void Slot31_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x080*/ virtual int WndNotification(CXWnd* sender, unsigned int message, void* data);
    /*0x084*/ virtual void Activate();    /* Show(1, 1) */
    /*0x088*/ virtual void Deactivate();    /* Show(0, 1) */
    /*0x08C*/ virtual int OnShow();
    /*0x090*/ virtual void Slot36_guess();    /* placeholder, not callable: the base pops 4 bytes; MQ2 order: OnMove */
    /*0x094*/ virtual void Slot37_guess();    /* placeholder, not callable: really OnResize(int width, int height) (0x005A1700 reads both, ret 8) */
    /*0x098*/ virtual void OnMinimizeBox_guess();
    /*0x09C*/ virtual void OnMaximizeBox_guess();
    /*0x0A0*/ virtual void Slot40_guess();
    /*0x0A4*/ virtual void Slot41_guess();    /* placeholder, not callable: the base pops 4 bytes; MQ2 order: OnSetFocus */
    /*0x0A8*/ virtual void Slot42_guess();    /* placeholder, not callable: the base pops 4 bytes; MQ2 order: OnKillFocus */
    /*0x0AC*/ virtual int OnProcessFrame();
    /*0x0B0*/ virtual void Slot44_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x0B4*/ virtual void Slot45_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x0B8*/ virtual void Slot46_guess();
    /*0x0BC*/ virtual void Slot47_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0C0*/ virtual int Show(bool show, bool bringToTop);    /* 0 on a visibility transition; -1 on no-op or veto */
    /*0x0C4*/ virtual bool AboutToShow();    /* false vetoes the show */
    /*0x0C8*/ virtual bool AboutToHide();    /* false vetoes the hide */
    /*0x0CC*/ virtual void Slot51_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0D0*/ virtual void Slot52_guess();    /* placeholder, not callable: the base pops 12 bytes */
    /*0x0D4*/ virtual void Slot53_guess();    /* placeholder, not callable: really `CXStr GetTooltip()` (0x004079DD copies the CXStr at +0x78 to the hidden return, ret 4) */
    /*0x0D8*/ virtual void Slot54_guess();    /* placeholder, not callable: the base pops 8 bytes */
    /*0x0DC*/ virtual void Slot55_guess();
    /*0x0E0*/ virtual void Slot56_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0E4*/ virtual void Slot57_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0E8*/ virtual void Slot58_guess();    /* placeholder, not callable: the base pops 4 bytes; MQ2 order: GetMinSize (two ints through a result pointer) */
    /*0x0EC*/ virtual void Slot59_guess();    /* placeholder, not callable: the base pops 4 bytes; MQ2 order: GetUntileSize (two ints through a result pointer) */
    /*0x0F0*/ virtual void Slot60_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0F4*/ virtual void Slot61_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x0F8*/ virtual void Slot62_guess();    /* placeholder, not callable: really SetDrawTemplate(one pointer, stored at +0x68; 0x00407A38, ret 4) */
    /*0x0FC*/ virtual void Slot63_guess();    /* placeholder, not callable: really `SetWindowText(const CXStr&)` (0x00407A5F: CXStr::operator= on +0x74) */
    /*0x100*/ virtual void Slot64_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x104*/ virtual void Slot65_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x108*/ virtual void Slot66_guess();    /* placeholder, not callable: the base pops 4 bytes */
    /*0x10C*/ virtual void Slot67_guess();
    /*0x110*/ virtual void Slot68_guess();
    /*0x114*/ virtual void Slot69_guess();
    /*0x118*/ virtual void LoadIniInfo();
    /*0x11C*/ virtual void StoreIniInfo();

    /*0x004*/ unsigned char pad_004[0x05C - 0x004];
    /*0x05C*/ unsigned char dShow;    /* MQ2 dShow (core_decls.h CXWnd::Show) */
    /*0x05D*/ unsigned char pad_05D[0x138 - 0x05D];
    /*0x138*/ unsigned char state_0138_guess;
    /*0x139*/ unsigned char pad_139[0x15C - 0x139];

    // EXTERNAL: TITANIUM 0x0059D080 CSidlScreenWndVirtuals_guess::BringToTop
    void BringToTop(int flag);    /* CXWndManager::BringWndToTop(this, flag) */
    // EXTERNAL: TITANIUM 0x0059DD30 CSidlScreenWndVirtuals_guess::IsVisible_guess
    bool IsVisible_guess();    /* returns byte +4; callers toggle Activate/Deactivate on it */
    // EXTERNAL: TITANIUM 0x005A1CD0 CSidlScreenWndVirtuals_guess::StoreIniVis
    void StoreIniVis();    /* writes the Show state to the ini and keeps it at +0x138 */
};

#endif
