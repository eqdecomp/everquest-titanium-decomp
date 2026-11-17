/* CContainerMgr: object, constructor 0x004FA372 (tu_148_ContainerMgr). Shared by the TUs that reach it through its global;
 * the defining TU keeps its own class. */
#ifndef TITANIUM_WND_CCONTAINERMGR_H
#define TITANIUM_WND_CCONTAINERMGR_H

#include "titanium/eqaddr.h"

struct CContainerMgr_guess {
    /*0x000*/ virtual void Slot00_guess(int value);
    /*0x004*/ unsigned char pad_004[0x06C - 0x004];
    /*0x06C*/ void* attached_06C_guess;    /* pointer stored by 0x004FAC8D */

    // EXTERNAL: TITANIUM 0x004FA39A CContainerMgr_guess::Get_guess
    int Get_guess(unsigned char key_guess);
    // EXTERNAL: TITANIUM 0x004FA6B6 CContainerMgr_guess::SetValue_guess
    void SetValue_guess(void* value_guess, int index_guess);
    // EXTERNAL: TITANIUM 0x004FA6E6 CContainerMgr_guess::GetValue_guess
    int GetValue_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x004FA714 CContainerMgr_guess::Reselect_guess
    void Reselect_guess();
    // EXTERNAL: TITANIUM 0x004FA77F CContainerMgr_guess::Update_guess
    void Update_guess(int value_guess);
    // EXTERNAL: TITANIUM 0x004FA7A4 CContainerMgr_guess::Select_guess
    void Select_guess(void* first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x004FA7CD CContainerMgr_guess::Bind_guess
    void Bind_guess(void* element, int index, bool flags);
    // EXTERNAL: TITANIUM 0x004FA948 CContainerMgr_guess::CloseEQContainer_guess
    void CloseEQContainer_guess(void* spell_guess);
    // EXTERNAL: TITANIUM 0x004FAA17 CContainerMgr_guess::CloseContainer_guess
    void CloseContainer_guess(void* id_guess, unsigned char flag_guess);
    // EXTERNAL: TITANIUM 0x004FAABA CContainerMgr_guess::Flush_guess
    unsigned char Flush_guess();
    // EXTERNAL: TITANIUM 0x004FAB7E CContainerMgr_guess::Process_guess
    void Process_guess();
    // EXTERNAL: TITANIUM 0x004FAC58 CContainerMgr_guess::Attach_guess
    void Attach_guess(void* object_guess, int value_guess);
};
#define pinstCContainerMgr_guess EQ_GLOBAL(CContainerMgr_guess*, 0x00850CBC)

#endif
