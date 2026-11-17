/* CContextMenuManager: object, constructor 0x004FD26A (tu_149_ContainerWnd). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. It is CXWnd-derived (ctor chain 0x004FD26A -> 0x005ADD50 -> CXWnd 0x005A1290); this partial view lists only the slots its users call. */
#ifndef TITANIUM_WND_CCONTEXTMENUMANAGER_H
#define TITANIUM_WND_CCONTEXTMENUMANAGER_H

#include "titanium/eqaddr.h"

struct CContextMenuManager_guess {
    /*0x000*/ virtual void Slot00_guess();
    /*0x004*/ virtual void Slot01_guess();
    /*0x008*/ virtual void Slot02_guess();
    /*0x00C*/ virtual void Slot03_guess();
    /*0x010*/ virtual void Slot04_guess();
    /*0x014*/ virtual void Slot05_guess();
    /*0x018*/ virtual void Slot06_guess();
    /*0x01C*/ virtual void Slot07_guess();
    /*0x020*/ virtual void Slot08_guess();
    /*0x024*/ virtual void Slot09_guess();
    /*0x028*/ virtual void Slot10_guess();
    /*0x02C*/ virtual void Slot11_guess();
    /*0x030*/ virtual void Slot12_guess();
    /*0x034*/ virtual void Slot13_guess();
    /*0x038*/ virtual void Slot14_guess();
    /*0x03C*/ virtual void Slot15_guess();
    /*0x040*/ virtual void Slot16_guess();
    /*0x044*/ virtual void Slot17_guess();
    /*0x048*/ virtual void Slot18_guess();
    /*0x04C*/ virtual void Slot19_guess();
    /*0x050*/ virtual void Slot20_guess();
    /*0x054*/ virtual void Slot21_guess();
    /*0x058*/ virtual void Slot22_guess();
    /*0x05C*/ virtual void Slot23_guess();
    /*0x060*/ virtual void Slot24_guess();
    /*0x064*/ virtual void Slot25_guess();
    /*0x068*/ virtual void Slot26_guess();
    /*0x06C*/ virtual void Slot27_guess();
    /*0x070*/ virtual void Slot28_guess();
    /*0x074*/ virtual void Slot29_guess();
    /*0x078*/ virtual void Slot30_guess();
    /*0x07C*/ virtual void Slot31_guess();
    /*0x080*/ virtual void Slot32_guess();
    /*0x084*/ virtual void Slot33_guess();
    /*0x088*/ virtual void Deactivate_guess();
    /*0x004*/ unsigned char pad_004[0x1154 - 0x004];
    /*0x1154*/ int field_1154_guess;
    /*0x1158*/ unsigned char pad_1158[0x1168 - 0x1158];

    // EXTERNAL: TITANIUM 0x004DAFEA CContextMenuManager_guess::GetMenu_guess
    int GetMenu_guess(int index);
    // EXTERNAL: TITANIUM 0x005AD5A0 CContextMenuManager_guess::AddMenu_guess
    int AddMenu_guess(void* object);
    // EXTERNAL: TITANIUM 0x005AD7F0 CContextMenuManager_guess::ReleaseIndex_guess
    void ReleaseIndex_guess(int index, int flag);
};
#define pinstCContextMenuManager_guess EQ_GLOBAL(CContextMenuManager_guess*, 0x0099D414)

#endif
