// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 231: a hint from compare/tumap.py.
// The tradeskill window (TradeskillWnd, CTradeskillWnd_guess; CTradeskillWndView_guess is the same object):
// recipe search by name and trivial range, up to 100 results sorted by name or trivial, 500 favourites kept
// in the UI ini, the 10 required-item icons, and auto-combine. The container being used is +0x184's owner
// (`pendingCallback_guess`); its type byte picks the tradeskill.
#include "titanium/types.h"
#include "titanium/eqaddr.h"
#include "titanium/opcodes.h"
#include <new>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SortRecord_guess {
    char gap_0000[4];
    int key;
    char gap_0008[0xC];
    char name[1];
};

typedef void (__cdecl *ElementDestructor_guess)(void*);

// EXTERNAL: TITANIUM 0x004482FB ElementDestructorFunction_guess
void __cdecl ElementDestructorFunction_guess(void* element);

// EXTERNAL: TITANIUM 0x0060D6E5 VectorDestructorIterator_guess
void __stdcall VectorDestructorIterator_guess(void* elements, unsigned int elementSize,
                                               int count, ElementDestructor_guess destructor);

struct CXStr;

struct Interface_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot0A_guess() = 0;
    virtual void Slot0B_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot0D_guess() = 0;
    virtual void Slot0E_guess() = 0;
    virtual void Slot0F_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot1A_guess() = 0;
    virtual void Slot1B_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot1D_guess() = 0;
    virtual void Slot1E_guess() = 0;
    virtual void Slot1F_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot2A_guess() = 0;
    virtual void Slot2B_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot2D_guess() = 0;
    virtual void Slot2E_guess() = 0;
    virtual void Slot2F_guess() = 0;
    virtual void Slot30_guess(int flag, int value) = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot3A_guess() = 0;
    virtual void Slot3B_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot3D_guess() = 0;
    virtual void Slot3E_guess() = 0;
    virtual void Slot3F_guess(CXStr* text) = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot4A_guess() = 0;
    virtual void Slot4B_guess() = 0;
    virtual void Slot4C_guess() = 0;

    // EXTERNAL: TITANIUM 0x00597BE0 Interface_guess::GetCurSel
    int GetCurSel();
    // EXTERNAL: TITANIUM 0x00597ED0 Interface_guess::GetItemData
    int GetItemData(int index);
    // EXTERNAL: TITANIUM 0x0059B3E0 Interface_guess::SetValue_guess
    void SetValue_guess(int index, int flag, int value);

    char gap_004[0x118];
    int count_11C;
};

struct TextWidget_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot0A_guess() = 0;
    virtual void Slot0B_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot0D_guess() = 0;
    virtual void Slot0E_guess() = 0;
    virtual void Slot0F_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot1A_guess() = 0;
    virtual void Slot1B_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot1D_guess() = 0;
    virtual void Slot1E_guess() = 0;
    virtual void Slot1F_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot2A_guess() = 0;
    virtual void Slot2B_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot2D_guess() = 0;
    virtual void Slot2E_guess() = 0;
    virtual void Slot2F_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot3A_guess() = 0;
    virtual void Slot3B_guess() = 0;
    virtual void Slot3C_guess() = 0;
    virtual void Slot3D_guess() = 0;
    virtual void Slot3E_guess() = 0;
    virtual void Slot3F_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot4A_guess() = 0;
    virtual void Slot4B_guess() = 0;
    virtual CXStr GetText_guess() = 0;
};

struct RecipeQueryPacket_guess {
    int field_0000_guess;             // 0x00
    int field_0004_guess;             // 0x04
    int field_0008_guess;             // 0x08
    int field_000C_guess;             // 0x0C
    char text_0010_guess[64];         // 0x10
};

struct ChildEntry_guess {
    char gap_0000[4];
    int value_4;
};

struct HashEntry_guess {
    void* value_guess; // 0x00
};

struct Element_guess;

struct Lookup_guess {
    char data_guess[0x10];
    // EXTERNAL: TITANIUM 0x0042F092 Lookup_guess::Lookup_guess
    Lookup_guess(int buckets_guess);
    // EXTERNAL: TITANIUM 0x00447C66 Lookup_guess::Insert_guess
    void Insert_guess(Element_guess** out, unsigned int key);
    // EXTERNAL: TITANIUM 0x004FF9C9 Lookup_guess::Find_guess
    int* Find_guess(unsigned int key);
    // EXTERNAL: TITANIUM 0x004466FA Lookup_guess::First_guess
    HashEntry_guess* First_guess();
    // EXTERNAL: TITANIUM 0x0042EC1A Lookup_guess::Next_guess
    HashEntry_guess* Next_guess(HashEntry_guess* entry_guess);
    // EXTERNAL: TITANIUM 0x004C9745 Lookup_guess::~Lookup_guess
    ~Lookup_guess();
};

struct Recipe_guess {
    char gap_0000[0x12C];
    int widthCount;

    // EXTERNAL: TITANIUM 0x00598170 Recipe_guess::GetWidth_guess
    int GetWidth_guess(int index);
    // EXTERNAL: TITANIUM 0x005981F0 Recipe_guess::SetWidth_guess
    void SetWidth_guess(int index, int width);
};

struct RecipeTable_guess {
    char gap_0000[0x3C];
    // EXTERNAL: TITANIUM 0x00572300 RecipeTable_guess::GetValue_guess
    int GetValue_guess(const char* key);
    // EXTERNAL: TITANIUM 0x00572300 RecipeTable_guess::GetText_guess
    const char* GetText_guess();
};

struct CallbackService_guess {
    char gap_0000_guess[0x6C];
    int target_6C_guess;

    // EXTERNAL: TITANIUM 0x004FAA17 CallbackService_guess::CloseContainer_guess
    void CloseContainer_guess(void* callback, int flag);
    // EXTERNAL: TITANIUM 0x004FA7A4 CallbackService_guess::Cancel_guess
    void Cancel_guess(void* callback, int id);
};

struct Client_guess {
    // EXTERNAL: TITANIUM 0x005ECCF0 Client_guess::GetByte_guess
    int GetByte_guess();
    // EXTERNAL: TITANIUM 0x005E0F30 Client_guess::GetItemId_guess
    int GetItemId_guess();
    // EXTERNAL: TITANIUM 0x005E0F60 Client_guess::Value_guess
    int Value_guess();
    // EXTERNAL: TITANIUM 0x005E0EC0 Client_guess::Name_guess
    const char* Name_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Client_guess::Flag_guess
    int Flag_guess(int index);
    // EXTERNAL: TITANIUM 0x005ECCC0 Client_guess::GetItemClass_guess
    int GetItemClass_guess();
    // EXTERNAL: TITANIUM 0x005ECC30 Client_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x005EC630 Client_guess::GetChild_guess
    Client_guess* GetChild_guess(int index);
    // EXTERNAL: TITANIUM 0x005EC760 Client_guess::IsStackable_guess
    char IsStackable_guess();
    char gap_0000_guess[0x48];
    int field_48_guess; // 0x48
};

struct SlotSource_guess {
    char gap_0000[0x58];
    int ids_guess[10]; // 0x58
};

struct FavoriteList_guess {
    int recipes[500];
};

struct FavoriteRecord_guess {
    int id_guess;            // 0x00
    char gap_0004[0x10];
    char text_guess[1];      // 0x14
};

struct Widget_guess {
    char gap_0000[0x5D];
    char active; // 0x5D
};

struct LookupHolder_guess {
    int unused_guess;
    int offset_guess; // 0x04
};

struct LookupSub_guess {
    // EXTERNAL: TITANIUM 0x0041ACE9 LookupSub_guess::Get_guess
    int Get_guess(int index);
};

struct LookupRoot_guess {
    char gap_0000[8];
    LookupHolder_guess* holder_guess; // 0x08
    char gap_000C[0xC280 - 0x0C];
    LookupSub_guess sub_c280_guess;   // 0xC280

    // EXTERNAL: TITANIUM 0x004BB89C LookupRoot_guess::FindIndex_guess
    int FindIndex_guess(int value);
};

struct LookupPrefix_guess {
    char padding_0000_guess[0x10];
};

struct LookupFlags_guess {
    char padding_0000_guess[0x78];
    int flag_guess; // 0x78
};

struct LookupRecord_guess {
    LookupPrefix_guess prefix_guess; // 0x0
    LookupFlags_guess flags_guess;   // 0x10
    char gap_008C_guess[0x1198 - 0x8C];
    int race_1198_guess;              // 0x1198
    char class_119c_guess;             // 0x119C
};

struct LookupService_guess {
    int unused_guess;

    // EXTERNAL: TITANIUM 0x005EC220 LookupService_guess::GetCharInfo2
    LookupRecord_guess* GetCharInfo2();
};

struct LookupStatus_guess {
    int unused_guess;
    LookupService_guess service_guess; // 0x04

    // EXTERNAL: TITANIUM 0x0040CC50 LookupStatus_guess::Get_guess
    int Get_guess(int index);
    LookupRecord_guess* FindRecord_guess() { return service_guess.GetCharInfo2(); }
};

struct FavoritePacket_guess {
    int field_0000;
    int field_0004;
    FavoriteList_guess favorites;
};

struct RecipeSelectPacket_guess {
    int id_guess;             // 0x00
    int flags_guess;          // 0x04
    char gap_0008_guess[0x40]; // 0x08
};

struct Pending_guess;
struct Slot_guess;

typedef void (__cdecl *ElementConstructor_guess)(void*);

// EXTERNAL: TITANIUM 0x0053ACD9 LAB_0053acd9_guess
void __cdecl LAB_0053acd9_guess(void* element);

// EXTERNAL: TITANIUM 0x0060E2B9 VectorConstructorIterator_guess
void __stdcall VectorConstructorIterator_guess(void* elements, unsigned int elementSize,
                                                int count, ElementConstructor_guess constructor,
                                                ElementDestructor_guess destructor);

#pragma pack(push, 1)
struct StatusBlock_guess {
    union {
        char flags_guess[10];
        struct {
            unsigned int first_guess;
            unsigned int second_guess;
            unsigned short last_guess;
        } reset_guess;
    };
};
#pragma pack(pop)

struct StatusEntry_guess {
    char gap_0000[0x80];
    int value_80_guess;
};

struct Element_guess {
    int field00_guess;          // 0x00
    int field04_guess;          // 0x04
    int field08_guess;          // 0x08
    int field0C_guess;          // 0x0C
    int field10_guess;          // 0x10
    char text_guess[64];        // 0x14
    char flag_guess;            // 0x54
    char gap_0055_guess[0xA8 - 0x55];
    unsigned int elements[10];  // 0xA8
    Element_guess();
};

struct CTradeskillWndView_guess {
    char gap_0000[0x5C];
    char flag_5C_guess;
    char gap_005D_guess[0xA8 - 0x5D];
    unsigned int elements[10];
    char gap_00D0[0x50];
    RecipeTable_guess table;
    union {
        Interface_guess* child;
        Recipe_guess* recipe;
    };
    TextWidget_guess* widget_160_guess; // 0x160
    TextWidget_guess* widget_164_guess; // 0x164
    TextWidget_guess* widget_168_guess; // 0x168
    Widget_guess* widget_16C_guess; // 0x16C
    Widget_guess* widget_170_guess; // 0x170
    Widget_guess* widget_174_guess; // 0x174
    Widget_guess* widget_178_guess; // 0x178
    Widget_guess* widget_17C_guess; // 0x17C
    CButtonWnd* notifier_180_guess; // 0x180
    Slot_guess* slot_184_guess; // 0x184
    Interface_guess* iface_188_guess; // 0x188
    Interface_guess* child_18C_guess; // 0x18C
    int slots_190_guess[10]; // 0x190
    Widget_guess* widget_1B8_guess; // 0x1B8
    Widget_guess* widget_1BC_guess; // 0x1BC
    Widget_guess* widget_1C0_guess; // 0x1C0
    Lookup_guess* lookup;
    unsigned int values[100];
    unsigned int state;
    unsigned int value_35C_guess;
    char flag_360_guess; // 0x360
    char gap_0361_guess[3];
    Client_guess* pendingCallback_guess;
    int value_368_guess; // 0x368
    Pending_guess* pending_36C_guess; // 0x36C
    int value_370_guess;
    int value_374_guess;
    char flag_378_guess;
    char gap_0379_guess[3];
    int timer_37C_guess;
    int timer_380_guess; // 0x380
    int timer_384_guess;
    FavoriteList_guess favorites_388;
    char favoritesLoaded_B58_guess;
    StatusBlock_guess status_B59_guess; // 0xB59

    int GetValue_guess();
    void UpdateChildValues_guess();
    int FindValue_guess(unsigned int key);
    void Handle_OP_RecipeReply_guess(Element_guess* record);
    void DestroyElements_guess();
    void Reset_guess();
    void LoadRecipeWidths_guess();
    void SaveRecipeWidths_guess();
    void RequestRecipes_guess();
    char DispatchCallback_guess();
    void LoadFavorites_guess();
    void SaveFavorites_guess();
    void SendFavorites_guess();
    void Begin_guess(Client_guess* client, int value);
    void UpdateButtons_guess();
    void AddFavorite_guess();
    void RemoveFavorite_guess();
    void ApplyPacket_guess(const char* packet);

    void Refresh_guess();
    void Sort_guess();
    void SetCurrent_guess(int key, int value);
    void MarkHeldIngredients_guess(char* flags_guess, SlotSource_guess* source_guess,
                    Client_guess* client_guess, int depth_guess);
    void Rebuild_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 CTradeskillWndView_guess::OnProcessFrame
    void OnProcessFrame();
    void Poll_guess();
    // EXTERNAL: TITANIUM 0x005680CC CTradeskillWndView_guess::SendAutoCombine_guess
    void SendAutoCombine_guess();
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                              unsigned int data_guess);
};

struct Control_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot0A_guess() = 0;
    virtual void Slot0B_guess() = 0;
    virtual void Slot0C_guess() = 0;
    virtual void Slot0D_guess() = 0;
    virtual void Slot0E_guess() = 0;
    virtual void Slot0F_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot1A_guess() = 0;
    virtual void Slot1B_guess() = 0;
    virtual void Slot1C_guess() = 0;
    virtual void Slot1D_guess() = 0;
    virtual void Slot1E_guess() = 0;
    virtual void Slot1F_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot2A_guess() = 0;
    virtual void Slot2B_guess() = 0;
    virtual void Slot2C_guess() = 0;
    virtual void Slot2D_guess() = 0;
    virtual void Slot2E_guess() = 0;
    virtual void Slot2F_guess() = 0;
    virtual void Slot30_guess(bool flag) = 0;
};

struct Text_guess {
    char* buffer_guess; // 0x00

    Text_guess() { buffer_guess = 0; }
    ~Text_guess() {
        if (buffer_guess != 0) {
            FreeRep(buffer_guess);
        }
    }

    // EXTERNAL: TITANIUM 0x00572E00 Text_guess::Append_guess
    void Append_guess(const char* text);
    // EXTERNAL: TITANIUM 0x00572300 Text_guess::Convert_guess
    int Convert_guess(int value);
    // EXTERNAL: TITANIUM 0x00571D00 Text_guess::FreeRep
    void FreeRep(char* buffer);
};

struct Defaults_guess {
    // EXTERNAL: TITANIUM 0x004AE848 Defaults_guess::WriteCharIniString_guess
    void WriteCharIniString_guess(int value);
    // EXTERNAL: TITANIUM 0x004AE8D9 Defaults_guess::GetValue_guess
    int GetValue_guess(int value, int width, int mode);
    // EXTERNAL: TITANIUM 0x004AE7DE Defaults_guess::SetValue_guess
    void SetValue_guess(int width, int fallback);
    // EXTERNAL: TITANIUM 0x004AE865 Defaults_guess::ReadDefaults_guess
    char* ReadDefaults_guess(const char* section, const char* key,
                             char* fallback, char* output, int size, char flag);
    // EXTERNAL: TITANIUM 0x004982C6 Defaults_guess::dsp_chat
    void dsp_chat(const char* text, int line, bool flag);
    // EXTERNAL: TITANIUM 0x004AE82A Defaults_guess::SetFlag_guess
    void SetFlag_guess(char value, const char* section, const char* key);
};

#define g_defaults_guess EQ_GLOBAL(Defaults_guess*, 0x00988DF0)
#define pinstCContainerMgr_guess EQ_GLOBAL(CallbackService_guess*, 0x00850CBC)
#define g_connection_guess EQ_ARRAY(char, 0x00905CA0)
#define g_lookupRoot_guess EQ_GLOBAL(LookupRoot_guess*, 0x00905D00)
#define g_recipeCount_guess EQ_GLOBAL(int, 0x009248D0)
#define g_flag_9254F5_guess EQ_GLOBAL(char, 0x009254F5)

struct Gate_guess {
    char gap_0000_guess[0x11];
    char flag_11_guess;
};

#define g_gate_guess EQ_GLOBAL(Gate_guess*, 0x00905D24)
#define g_object_905CE4_guess EQ_GLOBAL(void*, 0x00905CE4)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// EXTERNAL: TITANIUM 0x0060E450 strcpy
extern "C" char* __cdecl strcpy(char* destination_guess, const char* source_guess);

// EXTERNAL: TITANIUM 0x0060E3A3 atoi
extern "C" int __cdecl atoi(const char* text_guess);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source);

// EXTERNAL: TITANIUM 0x004B2056 ParseLong_guess
int __cdecl ParseLong_guess(const char* input, int* output, int option);

// EXTERNAL: TITANIUM 0x00475CE4 do_autoinventory_guess
void __cdecl do_autoinventory_guess(void* object_guess, int value_guess);

// EXTERNAL: TITANIUM 0x0046D655 GetTime_guess
int __cdecl GetTime_guess();

// EXTERNAL: TITANIUM 0x006220E9 _itoa
char* __cdecl _itoa(int value, char* buffer, int radix);

// EXTERNAL: TITANIUM 0x0046DA4A FUN_0046da4a_guess
void __cdecl FUN_0046da4a_guess(char* output_guess, unsigned int id_guess,
    const char* text_guess, int zero1_guess, int zero2_guess, int zero3_guess,
    int zero4_guess, int zero5_guess, int zero6_guess, int zero7_guess,
    int zero8_guess);

// EXTERNAL: TITANIUM 0x00433D68 ReadBigEndianUInt32_guess
int __cdecl ReadBigEndianUInt32_guess(const char* packet);

// Destructor of a cached recipe record: destroys its 10 component name strings (+0xA8; vector
// destructor iterator with 0x004482FB). The tradeskill window destructor runs it on each cached recipe.
// FUNCTION: TITANIUM 0x0056733F
void CTradeskillWndView_guess::DestroyElements_guess() {
    VectorDestructorIterator_guess(elements, 4, 10, ElementDestructorFunction_guess);
}

// Clears the result list and the 100 result slots.
// FUNCTION: TITANIUM 0x00567355
void CTradeskillWndView_guess::Reset_guess() {
    if (child != 0) {
        child->Slot4C_guess();
    }
    state = 0;
    unsigned int* current = values;
    for (int count = 100; count != 0; --count) {
        *current++ = 0;
    }
}

// Sends OP_RecipesSearch (container type and id, trivial range 0-500 by default, search text) and blocks
// another search for 5 s.
// FUNCTION: TITANIUM 0x00567382
void CTradeskillWndView_guess::RequestRecipes_guess() {
    Reset_guess();
    RecipeQueryPacket_guess packet;
    packet.field_0000_guess = pendingCallback_guess->GetByte_guess();
    packet.field_0004_guess = pendingCallback_guess->GetItemId_guess();
    packet.text_0010_guess[0] = 0;
    if (widget_168_guess != 0) {
        strcpy(packet.text_0010_guess, widget_168_guess->GetText_guess());
    }
    packet.field_0008_guess = 0;
    packet.field_000C_guess = 500;
    if (widget_160_guess != 0) {
        packet.field_0008_guess = atoi(widget_160_guess->GetText_guess());
    }
    if (widget_164_guess != 0) {
        packet.field_000C_guess = atoi(widget_164_guess->GetText_guess());
    }
    EQSendMessage(g_connection_guess, OP_RecipesSearch, &packet, sizeof(packet), 1);
    pEverQuest->dsp_chat("Requesting matching recipes...", 0x10E, 1);
    timer_37C_guess = GetTime_guess() + 5000;
}

// Column widths from RecipeList.col<n>.wid in the UI ini.
// FUNCTION: TITANIUM 0x005674E6
// @early-stop: budget, diff ndiff=22
void CTradeskillWndView_guess::LoadRecipeWidths_guess() {
    int widths[10];
    char key[256];
    int column = 0;
    if (recipe != 0) {
        int index = 0;
        while (index < (recipe->widthCount < 1 ? 1 : recipe->widthCount)) {
            widths[index] = recipe->GetWidth_guess(index);
            ++index;
        }
        while (column < (recipe->widthCount < 1 ? 1 : recipe->widthCount)) {
            sprintf(key, "RecipeList.col%d.wid", column);
            int value = g_defaults_guess->GetValue_guess(
                table.GetValue_guess(key), widths[column], 1);
            widths[column] = value;
            recipe->SetWidth_guess(column, value);
            ++column;
        }
    }
}

// StoreIniInfo side for the recipe list: saves each column width as RecipeList.colN.wid.
// FUNCTION: TITANIUM 0x005675AE
void CTradeskillWndView_guess::SaveRecipeWidths_guess() {
    char key[256];
    int column = 0;
    if (recipe != 0) {
        while (column < (recipe->widthCount < 1 ? 1 : recipe->widthCount)) {
            sprintf(key, "RecipeList.col%d.wid", column);
            g_defaults_guess->SetValue_guess(recipe->GetWidth_guess(column),
                                             table.GetValue_guess(key));
            ++column;
        }
    }
}

// Container types that hold tradeskill recipes (forges, ovens, kilns, tomes...).
// FUNCTION: TITANIUM 0x00567634
char __stdcall IsTradeskillContainerType_guess(int value_guess) {
    char result_guess = 0;
    switch (value_guess) {
    case 0x09: case 0x0A: case 0x0B: case 0x0C:
    case 0x0E: case 0x0F: case 0x10: case 0x11: case 0x12: case 0x13:
    case 0x14: case 0x15: case 0x16:
    case 0x18: case 0x19: case 0x1A: case 0x1B:
    case 0x1F: case 0x20: case 0x21: case 0x22: case 0x23: case 0x24:
    case 0x26: case 0x27: case 0x28: case 0x29: case 0x2A: case 0x2B:
    case 0x2C: case 0x2D: case 0x2E: case 0x2F: case 0x30: case 0x31:
    case 0x32: case 0x34: case 0x36:
        result_guess = 1;
        break;
    }
    return result_guess;
}

// Returns the item data of the selected row of the list at +0x15C, or 0 with no selection (0x00597BE0,
// 0x00597ED0). One body shared by the tradeskill window (the selected recipe id) and the find window
// (the selected spawn, 0x00502F3E).
// FUNCTION: TITANIUM 0x0056768B
int CTradeskillWndView_guess::GetValue_guess() {
    int result = 0;
    if (child != 0) {
        int index = child->GetCurSel();
        if (index != -1) {
            result = child->GetItemData(index);
        }
    }
    return result;
}

// Constructor of a cached recipe record: builds its 10 component name strings (+0xA8; vector
// constructor iterator with 0x0053ACD9). Used when a recipe from the reply is cached (0x00567B79).
// FUNCTION: TITANIUM 0x005676B4
Element_guess::Element_guess() {
    VectorConstructorIterator_guess(elements, 4, 10, LAB_0053acd9_guess,
                                    ElementDestructorFunction_guess);
}

// Writes the favourites as a comma list under "Favorites".
// FUNCTION: TITANIUM 0x005676D5
void CTradeskillWndView_guess::SaveFavorites_guess() {
    Text_guess text;
    int* item = favorites_388.recipes;
    for (int count = 500; count != 0; --count) {
        if (*item != 0) {
            text.Append_guess(_itoa(*item, EQ_ARRAY(char, 0x0099DB00), 10));
            text.Append_guess(",");
        }
        ++item;
    }
    int favorites = table.GetValue_guess("Favorites");
    g_defaults_guess->WriteCharIniString_guess(text.Convert_guess(favorites));
}

// qsort comparator for the recipe results: by name (strcmp). The sort (0x005677EC) uses it for column
// 0.
// FUNCTION: TITANIUM 0x00567773
int __cdecl CompareRecipeName_guess(SortRecord_guess** first_guess,
                               SortRecord_guess** second_guess) {
    SortRecord_guess* first_record_guess = *first_guess;
    return strcmp(first_record_guess->name, (*second_guess)->name);
}

// By trivial, then by name; the reverse-order comparers sit at 0x56778F and 0x5677DA.
// FUNCTION: TITANIUM 0x005677A1
int __cdecl CompareRecipeTrivialThenName_guess(SortRecord_guess** first_guess, SortRecord_guess** second_guess) {
    int difference_guess = (*first_guess)->key - (*second_guess)->key;
    if (difference_guess > 0) {
        return 1;
    }
    int result_guess = (difference_guess >= 0) - 1;
    if (result_guess == 0) {
        result_guess = strcmp((*first_guess)->name, (*second_guess)->name);
    }
    return result_guess;
}

typedef int (__cdecl *SortCompare_guess)(const void*, const void*);

// EXTERNAL: TITANIUM 0x0056778F FUN_0056778f_guess
int __cdecl FUN_0056778f_guess(SortRecord_guess** first_guess, SortRecord_guess** second_guess);
// EXTERNAL: TITANIUM 0x005677DA FUN_005677da_guess
int __cdecl FUN_005677da_guess(SortRecord_guess** first_guess, SortRecord_guess** second_guess);

// Sort column +0x35C (0 name, 1 trivial), ascending while +0x360 is set.
// FUNCTION: TITANIUM 0x005677EC
void CTradeskillWndView_guess::Sort_guess() {
    SortCompare_guess compare = 0;
    switch (value_35C_guess) {
    case 0:
        compare = (SortCompare_guess)CompareRecipeName_guess;
        if (flag_360_guess == 0) {
            compare = (SortCompare_guess)FUN_0056778f_guess;
        }
        break;
    case 1:
        if (flag_360_guess != 0) {
            compare = (SortCompare_guess)CompareRecipeTrivialThenName_guess;
        } else {
            compare = (SortCompare_guess)FUN_005677da_guess;
        }
        break;
    }
    if ((int)state > 0 && compare != 0) {
        qsort(values, state, 4, compare);
    }
}

// EXTERNAL: TITANIUM 0x005ECCF0 ReadClientByte_guess
int __stdcall ReadClientByte_guess(int client);

// Skill label: "<skill name> (<value>)" for the container's tradeskill, or "CANNOT USE" (string 3104).
// FUNCTION: TITANIUM 0x00567846
// @early-stop: budget, diff ndiff=3
void CTradeskillWndView_guess::Refresh_guess() {
    char text[256];
    int client;
    if (child_18C_guess != 0 && (client = (int)pendingCallback_guess) != 0) {
        int slot = ReadClientByte_guess(client);
        value_370_guess = g_lookupRoot_guess->FindIndex_guess(slot);
        if (value_370_guess != 0xff) {
            value_374_guess = g_lookupRoot_guess->sub_c280_guess.Get_guess(value_370_guess);
            sprintf(text, "%s (%d)",
                    pStringTable->getString(*EQ_ARRAY(unsigned long*, 0x00851200)[value_370_guess], 0),
                    value_374_guess);
        } else {
            sprintf(text, pStringTable->getString(0xc20, 0));
        }
        CXStr label(text);
        child_18C_guess->Slot3F_guess(&label);
    }
}

// Trivial colour: the gap between the recipe's trivial and your skill picks one of five colours from the
// table at 0x65EFB4 (thresholds at 0x65EFC8); red when past all five.
// FUNCTION: TITANIUM 0x00567965
int __cdecl GetTrivialColor_guess(int first, int second) {
    int difference = second - first;
    for (int index = 0; index < 5; ++index) {
        if (difference <= EQ_ARRAY(int, 0x0065EFC8)[index]) {
            return EQ_ARRAY(int, 0x0065EFB4)[index];
        }
    }
    return (int)0xFFFF0000;
}

// Closing: releases the container and saves the column widths.
// FUNCTION: TITANIUM 0x0056798C
char CTradeskillWndView_guess::DispatchCallback_guess() {
    void* callback = pendingCallback_guess;
    if (callback != 0) {
        pendingCallback_guess = 0;
        pinstCContainerMgr_guess->CloseContainer_guess(callback, 1);
    }
    SaveRecipeWidths_guess();
    return 1;
}

// Fills the list from the sorted results (name, trivial, trivial colour), keeping the selection.
// FUNCTION: TITANIUM 0x005679B7
void CTradeskillWndView_guess::Rebuild_guess() {
    if (child != 0) {
        int selected = GetValue_guess();
        child->Slot4C_guess();
        int found = -1;
        Sort_guess();
        int index;
        int i = 0;
        if ((int)state > 0) {
            unsigned int* slot = values;
            do {
                int value = GetTrivialColor_guess(value_374_guess, ((SortRecord_guess*)*slot)->key);
                {
                    CXStr text(((SortRecord_guess*)*slot)->name);
                    index = ((CListWnd*)child)->AddString(text, 0xffffffff, *slot, 0);
                }
                {
                    CXStr keyText(_itoa(((SortRecord_guess*)*slot)->key, EQ_ARRAY(char, 0x0099DB00), 10));
                    ((CListWnd*)child)->SetItemText(index, 1, keyText);
                }
                child->SetValue_guess(index, 1, value);
                if (*slot == (unsigned int)selected) {
                    found = index;
                }
                ++i;
                ++slot;
            } while (i < (int)state);
        }
        ((CListWnd*)child)->SetCurSel(found);
    }
    flag_378_guess = 0;
}

// Recolours column 1 of every row by the gap between the row's value (+4) and the skill value at +0x374
// (0x00567965: five bands from 0x65EFC8, red beyond).
// FUNCTION: TITANIUM 0x00567B04
void CTradeskillWndView_guess::UpdateChildValues_guess() {
    if (child != 0) {
        for (int index = 0; index < child->count_11C; ++index) {
            ChildEntry_guess* entry = (ChildEntry_guess*)child->GetItemData(index);
            if (entry != 0) {
                int value = GetTrivialColor_guess(value_374_guess, entry->value_4);
                child->SetValue_guess(index, 1, value);
            }
        }
    }
}

// Tradeskill window: the cached recipe record for id `key` from the hash at +0x1C4 (0x004FF9C9), or 0.
// Used when caching a recipe and when a details reply arrives.
// FUNCTION: TITANIUM 0x00567B57
int CTradeskillWndView_guess::FindValue_guess(unsigned int key) {
    int result = 0;
    if (lookup != 0) {
        int* value = lookup->Find_guess(key);
        if (value != 0) {
            result = *value;
        }
    }
    return result;
}

// Caches one recipe from the reply by id and adds it to the results when it matches the open container
// (at most 100).
// FUNCTION: TITANIUM 0x00567B79
// @early-stop: budget, structural ndiff=42
void CTradeskillWndView_guess::Handle_OP_RecipeReply_guess(Element_guess* record) {
    Element_guess* source = record;
    bool created = false;
    Element_guess* entry = (Element_guess*)FindValue_guess(source->field0C_guess);
    record = entry;
    if (entry == 0) {
        created = true;
        record = new Element_guess();
        entry = record;
        entry->flag_guess = 0;
    }
    CopyText_guess(entry->text_guess, source->text_guess);
    entry->field00_guess = source->field0C_guess;
    entry->field0C_guess = source->field04_guess;
    entry->field08_guess = source->field00_guess;
    entry->field04_guess = source->field10_guess;
    entry->field10_guess = source->field08_guess;
    if (created) {
        lookup->Insert_guess(&record, source->field0C_guess);
    }
    if (pendingCallback_guess != 0) {
        if (source->field00_guess == pendingCallback_guess->GetByte_guess()) {
            if (source->field04_guess == pendingCallback_guess->GetItemId_guess()) {
                if ((int)state < 100) {
                    values[state] = (unsigned int)entry;
                    ++state;
                    flag_378_guess = 1;
                }
            }
        }
    }
}

// Adds the selected recipe to the first free favourite slot: "Recipe %1 has been added to your favorites."
// (3458).
// FUNCTION: TITANIUM 0x00567C66
void CTradeskillWndView_guess::AddFavorite_guess() {
    char message[1024];
    FavoriteRecord_guess* record = (FavoriteRecord_guess*)GetValue_guess();
    if (record != 0) {
        for (int index = 0; index < 500; ++index) {
            if (favorites_388.recipes[index] == 0) {
                favorites_388.recipes[index] = record->id_guess;
                SaveFavorites_guess();
                FUN_0046da4a_guess(message, 0xd82, record->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                g_defaults_guess->dsp_chat(message, 0xf, 1);
                return;
            }
        }
    }
}

// "Recipe %1 removed from favorites." (3459), once per slot that held it.
// FUNCTION: TITANIUM 0x00567CF6
void CTradeskillWndView_guess::RemoveFavorite_guess() {
    char message[1024];
    FavoriteRecord_guess* record = (FavoriteRecord_guess*)GetValue_guess();
    if (record != 0) {
        int* item = favorites_388.recipes;
        for (int count = 500; count != 0; --count) {
            if (*item == record->id_guess) {
                *item = 0;
                SaveFavorites_guess();
                FUN_0046da4a_guess(message, 0xd83, record->text_guess, 0, 0, 0, 0, 0, 0, 0, 0);
                g_defaults_guess->dsp_chat(message, 0xf, 1);
            }
            ++item;
        }
    }
}

// Parses the "Favorites" comma list; "*" (missing) clears them. A '0' entry is not skipped over, so every
// slot after it also reads 0.
// FUNCTION: TITANIUM 0x00567D8F
void CTradeskillWndView_guess::LoadFavorites_guess() {
    char text[4096];
    char fallback[256];
    CopyText_guess(fallback, EQ_ARRAY(char, 0x006591B8));
    g_defaults_guess->ReadDefaults_guess(table.GetText_guess(), "Favorites",
        fallback, text, 0xfff, 1);
    if (text[0] == '*') {
        memset(favorites_388.recipes, 0, sizeof(favorites_388.recipes));
    } else {
        const char* p = text;
        for (int i = 0; i < 500; ++i) {
            if (*p != '0') {
                p += ParseLong_guess(p, &favorites_388.recipes[i], 0x2c);
            } else {
                favorites_388.recipes[i] = 0;
            }
        }
    }
}

// Skill value changed: recolour and relabel when it is this window's skill.
// FUNCTION: TITANIUM 0x00567E44
void CTradeskillWndView_guess::SetCurrent_guess(int key, int value) {
    if (key == value_370_guess) {
        value_374_guess = value;
        UpdateChildValues_guess();
        Refresh_guess();
    }
}

// Marks which required items the container holds (walking into bags), then refreshes.
// FUNCTION: TITANIUM 0x00567E6D
void CTradeskillWndView_guess::MarkHeldIngredients_guess(char* flags_guess, SlotSource_guess* source_guess,
                             Client_guess* client_guess, int depth_guess) {
    if (client_guess->GetItemClass_guess() == 1) {
        for (int index = 0; index < client_guess->Count_guess(); ++index) {
            Client_guess* child_guess = client_guess->GetChild_guess(index);
            if (child_guess != 0) {
                MarkHeldIngredients_guess(flags_guess, source_guess, child_guess,
                           index + 0x1f + depth_guess * 10);
            }
        }
    } else {
        depth_guess = 0;
        int* id_guess = source_guess->ids_guess;
        for (int index = 0; index < 10; ++index, ++id_guess) {
            if (flags_guess[index] == 0 && *id_guess == client_guess->GetItemId_guess()) {
                ++depth_guess;
                flags_guess[index] = 1;
                if (!client_guess->IsStackable_guess() || client_guess->field_48_guess <= depth_guess) {
                    break;
                }
            }
        }
        UpdateChildValues_guess();
        Refresh_guess();
    }
}

// Sends OP_RecipesFavorite with the container and the 500 favourite ids, loading them first if needed.
// FUNCTION: TITANIUM 0x00567F28
void CTradeskillWndView_guess::SendFavorites_guess() {
    if (favoritesLoaded_B58_guess == 0) {
        LoadFavorites_guess();
        favoritesLoaded_B58_guess = 1;
    }
    Reset_guess();
    FavoritePacket_guess packet;
    memset(&packet, 0, sizeof(packet));
    packet.field_0000 = pendingCallback_guess->GetByte_guess();
    packet.field_0004 = pendingCallback_guess->GetItemId_guess();
    packet.favorites = favorites_388;
    EQSendMessage(g_connection_guess, OP_RecipesFavorite, &packet, sizeof(packet), 1);
    g_defaults_guess->dsp_chat("Requesting favorite recipes...", 0x10e, 1);
    timer_37C_guess = GetTime_guess() + 5000;
}

// The lookup status is root + 8 + the holder's offset; the record is its service's Find().
#define CurrentStatus_guess() ((LookupStatus_guess*)((int)g_lookupRoot_guess + 8 + g_lookupRoot_guess->holder_guess->offset_guess))
#define CurrentRecord_guess() (CurrentStatus_guess()->FindRecord_guess())

// Combine: class tomes (types 24-27) and racial forges (types 31-45) refuse the wrong class or race
// (strings 12010-12023); a full cursor refuses too (12024). Then sends OP_RecipeAutoCombine (container type
// and id, slot, recipe id) and locks the button for 2.1 s.
// FUNCTION: TITANIUM 0x005680CC
// @early-stop: budget, structural ndiff=24
void CTradeskillWndView_guess::SendAutoCombine_guess() {
    if (g_lookupRoot_guess != 0 && pendingCallback_guess != 0) {
        if (pendingCallback_guess->GetByte_guess() == 0x18) {
            if (CurrentRecord_guess()->class_119c_guess != 0x0c) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x19) {
            if (CurrentRecord_guess()->class_119c_guess != 0x0d) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x1a) {
            if (CurrentRecord_guess()->class_119c_guess != 0x0b) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x1b) {
            if (CurrentRecord_guess()->class_119c_guess != 0x0e) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2eea, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x1f && CurrentRecord_guess()->race_1198_guess != 5) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2eeb, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x20 && CurrentRecord_guess()->race_1198_guess != 6) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2eec, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x21 && CurrentRecord_guess()->race_1198_guess != 10) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2eed, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x22 && CurrentRecord_guess()->race_1198_guess != 8) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2eee, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x23 && CurrentRecord_guess()->race_1198_guess != 12) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2eef, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x24 && CurrentRecord_guess()->race_1198_guess != 2) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef0, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x26 && CurrentRecord_guess()->race_1198_guess != 0x80) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef1, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x27) {
            if (CurrentRecord_guess()->race_1198_guess != 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2ef2, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x28) {
            if (CurrentRecord_guess()->race_1198_guess != 1) {
                pEverQuest->dsp_chat(pStringTable->getString(0x2ef2, 0), 0xf, 1);
                return;
            }
        }
        if (pendingCallback_guess->GetByte_guess() == 0x2d && CurrentRecord_guess()->race_1198_guess != 0x80) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef3, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x2a && CurrentRecord_guess()->race_1198_guess != 3) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef4, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x29 && CurrentRecord_guess()->race_1198_guess != 11) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef5, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x2b && CurrentRecord_guess()->race_1198_guess != 4) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef6, 0), 0xf, 1);
            return;
        }
        if (pendingCallback_guess->GetByte_guess() == 0x2c && CurrentRecord_guess()->race_1198_guess != 4) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef7, 0), 0xf, 1);
            return;
        }
        if (CurrentRecord_guess()->flags_guess.flag_guess != 0 || g_gate_guess->flag_11_guess != 0) {
            pEverQuest->dsp_chat(pStringTable->getString(0x2ef8, 0), 0xf, 1);
            return;
        }
        int id = 0;
        if (pinstCContainerMgr_guess->target_6C_guess != 0 &&
            pinstCContainerMgr_guess->target_6C_guess == (int)pendingCallback_guess) {
            id = 1000;
        } else {
            for (int i = 0; i < 0x1f; ++i) {
                if (CurrentStatus_guess()->Get_guess(i) == (int)pendingCallback_guess) {
                    id = i;
                }
            }
            if (id == 0) {
                return;
            }
        }
        FavoriteRecord_guess* record = (FavoriteRecord_guess*)GetValue_guess();
        if (record == 0) {
            return;
        }
        g_recipeCount_guess++;
        int packet[5];
        packet[0] = pendingCallback_guess->GetByte_guess();
        packet[1] = pendingCallback_guess->GetItemId_guess();
        packet[2] = id;
        packet[3] = record->id_guess;
        EQSendMessage(g_connection_guess, OP_RecipeAutoCombine, packet, sizeof(packet), 1);
        timer_380_guess = GetTime_guess() + 0x834;
    }
}

// Every 250 ms: Search after its 5 s lock, Combine when nothing is pending, Add/Remove favourite by whether
// the
// recipe is already one, and the Ctrl-bypass box from the option.
// FUNCTION: TITANIUM 0x00568645
void CTradeskillWndView_guess::UpdateButtons_guess() {
    int now = GetTime_guess();
    char canSend = now > timer_37C_guess;

    char enabled;
    if (child != 0 && now > timer_380_guess && GetValue_guess() != 0) {
        LookupRoot_guess* root = g_lookupRoot_guess;
        LookupStatus_guess* status = reinterpret_cast<LookupStatus_guess*>(
            reinterpret_cast<char*>(root) + 8 + root->holder_guess->offset_guess);
        LookupRecord_guess* record = status->service_guess.GetCharInfo2();
        LookupFlags_guess* flags = &record->flags_guess;
        if (flags->flag_guess == 0 && g_recipeCount_guess <= 0) {
            enabled = 1;
        } else {
            enabled = 0;
        }
    } else {
        enabled = 0;
    }

    if (widget_16C_guess != 0) {
        widget_16C_guess->active = canSend;
    }
    if (widget_1B8_guess != 0) {
        widget_1B8_guess->active = enabled;
    }

    char hasRoom = 0;
    char isFavorite = 0;
    if (child != 0) {
        int index = child->GetCurSel();
        if (index != -1) {
            char empty = 0;
            char found = 0;
            int* value = (int*)child->GetItemData(index);
            for (int i = 0; i < 500; ++i) {
                if (favorites_388.recipes[i] == 0) {
                    empty = 1;
                } else if (favorites_388.recipes[i] == *value) {
                    found = 1;
                }
            }
            if (empty && !found) {
                hasRoom = 1;
            } else {
                hasRoom = 0;
            }
            isFavorite = found;
        }
    }

    if (widget_170_guess != 0) {
        widget_170_guess->active = hasRoom;
    }
    if (widget_174_guess != 0) {
        widget_174_guess->active = isFavorite;
    }
    if (notifier_180_guess != 0) {
        notifier_180_guess->SetCheck(g_flag_9254F5_guess == 0);
    }
}

struct BackRefWidget_guess {
    char gap_0000[0x16C];
    void* back_guess; // 0x16C
};

struct WidgetSet_guess {
    BackRefWidget_guess* first_guess; // 0x00
    CXWnd* containerName_guess;       // 0x04
    CXWnd* skillLabel_guess;          // 0x08
    BackRefWidget_guess* items_guess[10]; // 0x0C

    ~WidgetSet_guess() {}
};

struct BucketHolder_guess {
    Lookup_guess* bucket_guess; // 0x00

    ~BucketHolder_guess() {}
};

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// CTextureAnimation (0x4C bytes).
struct Animation_guess {
    char data_guess[0x4C];
    // EXTERNAL: TITANIUM 0x005B1D90 ??0Animation_guess@@QAE@XZ
    Animation_guess();
    // EXTERNAL: TITANIUM 0x004DBB3B ??4Animation_guess@@QAEAAU0@ABU0@@Z
    Animation_guess& operator=(const Animation_guess& other);
    // EXTERNAL: TITANIUM 0x005B1AB0 Animation_guess::SetCurCell_guess
    void SetCurCell_guess(int cell);
};

struct SidlManager_guess {
    // EXTERNAL: TITANIUM 0x005B44A0 SidlManager_guess::FindAnimation_guess
    Animation_guess* FindAnimation_guess(const CXStr& name);
};

#define g_sidlManager_guess EQ_GLOBAL(SidlManager_guess*, 0x0099D3F4)

struct RecipeListWnd_guess : CListWnd {
    char pad_140_guess[0x1C];
    unsigned char field_15C_guess;   // 0x15C
    char pad_15D_guess[0xF];
    unsigned long field_16C_guess;   // 0x16C
};

struct EditWnd_guess : CXWnd {
    char pad_11C_guess[0x230 - 0x11C];
    int field_230_guess;             // 0x230
    // EXTERNAL: TITANIUM 0x004D7EBC EditWnd_guess::SetMaxChars_guess
    void SetMaxChars_guess(int count);
};

// EXTERNAL: TITANIUM 0x0065F040 ??_7CTradeskillWnd_guess@@6B@
struct CTradeskillWnd_guess : CSidlScreenWndBase {
    RecipeListWnd_guess* recipeList_15C;
    EditWnd_guess* minTrivial_160;
    EditWnd_guess* maxTrivial_164;
    EditWnd_guess* searchText_168;
    CXWnd* searchButton_16C;
    CXWnd* addFavorite_170;
    CXWnd* removeFavorite_174;
    CXWnd* showFavorites_178;
    CXWnd* autoInv_17C;
    CXWnd* useCtrl_180;
    WidgetSet_guess widgets_184;    // 0x184..0x1B7
    CXWnd* combine_1B8;
    CXWnd* experiment_1BC;
    CXWnd* close_1C0;
    BucketHolder_guess lookup_1C4;  // 0x1C4
    unsigned int values_1C8[100];
    unsigned int state_358;
    unsigned int value_35C;
    char flag_360;
    char gap_361[3];
    int value_364;
    int value_368;
    int value_36C;
    int value_370;
    int value_374;
    char flag_378;
    char gap_379[3];
    int timer_37C;
    int timer_380;
    int timer_384;
    int favorites_388[500];
    char favoritesLoaded_B58;
    char required_B59[10];
    CTradeskillWnd_guess(CXWnd* parent);
    virtual ~CTradeskillWnd_guess();
    void* ScalarDelete_guess(unsigned char flags);
};

// Tradeskill window destructor: destroys and deletes every element stored in the hash table at +0x1C4,
// then the table, and clears the back pointer of the ten controls in +0x184 and of its extra one.
// FUNCTION: TITANIUM 0x0056881F
CTradeskillWnd_guess::~CTradeskillWnd_guess() {
    HashEntry_guess* entry_guess = lookup_1C4.bucket_guess->First_guess();
    while (entry_guess != 0) {
        CTradeskillWndView_guess* element_guess = (CTradeskillWndView_guess*)entry_guess->value_guess;
        entry_guess = lookup_1C4.bucket_guess->Next_guess(entry_guess);
        if (element_guess != 0) {
            element_guess->DestroyElements_guess();
            delete element_guess;
        }
    }
    if (lookup_1C4.bucket_guess != 0) {
        delete lookup_1C4.bucket_guess;
    }
    for (int index = 0; index < 10; ++index) {
        if (widgets_184.items_guess[index] != 0) {
            widgets_184.items_guess[index]->back_guess = 0;
        }
    }
    if (widgets_184.first_guess != 0) {
        widgets_184.first_guess->back_guess = 0;
    }
}

// Rebuilds the list when new results came in while the window is open.
// FUNCTION: TITANIUM 0x00568A4E
void CTradeskillWndView_guess::Poll_guess() {
    if (flag_5C_guess != 0 && flag_378_guess != 0) {
        Rebuild_guess();
    }
    if (GetTime_guess() - timer_384_guess > 250) {
        UpdateButtons_guess();
    }
    OnProcessFrame();
}

struct Pending_guess {
    int head_guess;            // 0x00
    char gap_0004[0x50];
    char flag_guess;           // 0x54
    char gap_0055[3];
    int keys_guess[10];        // 0x58
    int offsets_guess[10];     // 0x80
    unsigned int elements[10]; // 0xA8
};

struct Holder_guess {
    // EXTERNAL: TITANIUM 0x00571F70 Holder_guess::Release_guess
    void Release_guess(unsigned int* item);
};

struct Timer_guess {
    // EXTERNAL: TITANIUM 0x005B1AB0 Timer_guess::Set_guess
    void Set_guess(int value);
};

struct Slot_guess {
    char gap_0000[0x78];
    Holder_guess holder_78;  // 0x78
    char gap_0079[0xF3];
    Timer_guess* timer_16C;  // 0x16C
};

// Opens the window for `client`: names the container, shows as many required icons as it has slots, and asks
// for the favourites.
// FUNCTION: TITANIUM 0x00567FE5
void CTradeskillWndView_guess::Begin_guess(Client_guess* client, int value) {
    value_368_guess = value;
    pendingCallback_guess = client;
    if (slot_184_guess != 0) {
        Timer_guess* timer = slot_184_guess->timer_16C;
        timer->Set_guess(client->Value_guess() - 500);
    }
    if (iface_188_guess != 0) {
        CXStr temp(client->Name_guess());
        iface_188_guess->Slot3F_guess(&temp);
    }
    Refresh_guess();
    for (int i = 0; i < 10; ++i) {
        if (slots_190_guess[i] != 0) {
            ((Control_guess*)slots_190_guess[i])->Slot30_guess(
                i >= 10 - client->Flag_guess(1));
        }
    }
    SendFavorites_guess();
}

struct Group_guess {
    char gap_0000[0x160];
    Interface_guess* child_160_guess; // 0x160
    Interface_guess* child_164_guess; // 0x164
    Interface_guess* child_168_guess; // 0x168
    char gap_016C[0x190 - 0x16C];
    Slot_guess* slots_190[10]; // 0x190
    char gap_01B8[0x1B4];
    Pending_guess* pending_36C; // 0x36C

    void Flush_guess();
    void Refresh_guess(Pending_guess* pending);
    void Dispatch_guess(Pending_guess* pending);
    void ClearSlots_guess();
};

// Resets the search fields (0, 500, empty), the results and every required icon.
// FUNCTION: TITANIUM 0x005688D2
void Group_guess::ClearSlots_guess() {
    if (child_160_guess != 0) {
        CXStr text(_itoa(0, EQ_ARRAY(char, 0x0099DB00), 10));
        child_160_guess->Slot3F_guess(&text);
    }
    if (child_164_guess != 0) {
        CXStr text(_itoa(500, EQ_ARRAY(char, 0x0099DB00), 10));
        child_164_guess->Slot3F_guess(&text);
    }
    const char* empty = EQ_ARRAY(char, 0x0063F53F);
    if (child_168_guess != 0) {
        CXStr text(empty);
        child_168_guess->Slot3F_guess(&text);
    }
    ((CTradeskillWndView_guess*)this)->Reset_guess();
    pending_36C = 0;
    Slot_guess** slot = slots_190;
    for (int count = 10; count != 0; --count) {
        if (*slot != 0) {
            Timer_guess* timer = (*slot)->timer_16C;
            timer->Set_guess(-1);
            CXStr text(empty);
            Slot_guess* currentSlot = *slot;
            currentSlot->holder_78.Release_guess((unsigned int*)&text);
        }
        ++slot;
    }
    Flush_guess();
}

// Required icons: green when the container holds that item, red when not, none when unused.
// FUNCTION: TITANIUM 0x0056875D
// @early-stop: budget, structural ndiff=39
void Group_guess::Flush_guess() {
    CTradeskillWndView_guess* owner = (CTradeskillWndView_guess*)this;
    owner->status_B59_guess.reset_guess.first_guess = 0;
    owner->status_B59_guess.reset_guess.second_guess = 0;
    owner->status_B59_guess.reset_guess.last_guess = 0;
    int index;
    int lookup = owner->GetValue_guess();
    if (lookup != 0) {
        index = 0x16;
        do {
            if (CurrentStatus_guess()->Get_guess(index) != 0) {
                owner->MarkHeldIngredients_guess(owner->status_B59_guess.flags_guess,
                                  (SlotSource_guess*)lookup,
                                  (Client_guess*)CurrentStatus_guess()->Get_guess(index),
                                  index);
            }
            ++index;
        } while (index <= 0x1D);
    }
    int i = 0;
    int* slot = owner->slots_190_guess;
    int* key = ((SlotSource_guess*)lookup)->ids_guess;
    do {
        if (*slot != 0) {
            int value = -1;
            if (lookup != 0 && *key != -1) {
                value = (-(unsigned int)(owner->status_B59_guess.flags_guess[i] != 0) & 0xff01ff00) - 0x10000;
            }
            ((StatusEntry_guess*)*slot)->value_80_guess = value;
        }
        ++i;
        ++key;
        ++slot;
    } while (i < 10);
    owner->Refresh_guess();
}

// Shows a recipe's required items once its details have arrived.
// FUNCTION: TITANIUM 0x00568A86
void Group_guess::Refresh_guess(Pending_guess* pending) {
    if (pending == pending_36C) {
        for (int i = 0; i < 10; ++i) {
            slots_190[i]->timer_16C->Set_guess(pending->offsets_guess[i] - 500);
            slots_190[i]->holder_78.Release_guess(&pending->elements[i]);
        }
        Flush_guess();
    }
}

// Scalar deleting destructor of the tradeskill window (vtable 0x65F040 slot 1): destroys it and frees
// it when flag 1 is set.
// FUNCTION: TITANIUM 0x00568AE6
void* CTradeskillWnd_guess::ScalarDelete_guess(unsigned char flags) {
    this->CTradeskillWnd_guess::~CTradeskillWnd_guess();
    if ((flags & 1) != 0) {
        ::operator delete(this);
    }
    return this;
}

// Uses cached details, or asks with OP_RecipeDetails (recipe id).
// FUNCTION: TITANIUM 0x00568B02
void Group_guess::Dispatch_guess(Pending_guess* pending) {
    if (pending->flag_guess != 0) {
        Refresh_guess(pending);
    } else {
        int head_guess = pending->head_guess;
        EQSendMessage(g_connection_guess, OP_RecipeDetails, &head_guess, 4, 1);
    }
}

// Reads a details reply: for each of the 10 slots an item id (-1 = unused), its icon and name.
// FUNCTION: TITANIUM 0x00568B39
void CTradeskillWndView_guess::ApplyPacket_guess(const char* packet) {
    int id = ReadBigEndianUInt32_guess(packet);
    packet += 4;
    Pending_guess* pending = (Pending_guess*)FindValue_guess(id);
    if (pending != 0) {
        if (pending->flag_guess == 0) {
            for (int count = 0; count < 10; ++count) {
                int key = ReadBigEndianUInt32_guess(packet);
                packet += 4;
                pending->keys_guess[count] = key;
                if (key != -1) {
                    pending->offsets_guess[count] = ReadBigEndianUInt32_guess(packet);
                    packet += 4;
                    *(CXStr*)&pending->elements[count] = packet;
                    packet = packet + strlen(packet) + 1;
                } else {
                    pending->offsets_guess[count] = 499;
                    *(CXStr*)&pending->elements[count] = EQ_ARRAY(char, 0x0063F53F);
                }
            }
            pending->flag_guess = 1;
        }
        if (pending->flag_guess == 0) {
            return;
        }
        ((Group_guess*)this)->Refresh_guess(pending);
    }
}

// Style 0x10000; trivial boxes take 3 digits, the search box 21 characters; each required icon gets a copy
// of the A_DragItem animation.
// FUNCTION: TITANIUM 0x00568BDB
CTradeskillWnd_guess::CTradeskillWnd_guess(CXWnd* parent)
    : CSidlScreenWndBase(parent, "TradeskillWnd", -1, 1, 0) {
    recipeList_15C = 0;
    minTrivial_160 = 0;
    maxTrivial_164 = 0;
    searchText_168 = 0;
    searchButton_16C = 0;
    addFavorite_170 = 0;
    removeFavorite_174 = 0;
    showFavorites_178 = 0;
    widgets_184.first_guess = 0;
    widgets_184.containerName_guess = 0;
    widgets_184.skillLabel_guess = 0;
    close_1C0 = 0;
    autoInv_17C = 0;
    useCtrl_180 = 0;
    favoritesLoaded_B58 = 0;
    BackRefWidget_guess** icon = widgets_184.items_guess;
    for (int count = 10; count != 0; --count) {
        *icon++ = 0;
    }
    combine_1B8 = 0;
    experiment_1BC = 0;
    lookup_1C4.bucket_guess = new Lookup_guess(0x80);
    state_358 = 0;
    value_35C = 0;
    flag_360 = 1;
    flag_378 = 0;
    value_364 = 0;
    unsigned int* value = values_1C8;
    for (int count = 100; count != 0; --count) {
        *value++ = 0;
    }
    value_370 = 0xff;
    value_374 = 0xff;
    timer_384 = 0;
    timer_380 = 0;
    timer_37C = 0;
    // Room for 500 favourite recipe ids (cleared here, filled from the server).
    int* favorite = favorites_388;
    for (int count = 500; count != 0; --count) {
        *favorite++ = 0;
    }
    if (SidlPiece != 0) {
        WindowStyle |= 0x10000;
        field_158_guess = 0x2c;
        CSidlScreenWnd* sidl = (CSidlScreenWnd*)this;
        sidl->CreateChildrenFromSidl();
        recipeList_15C = (RecipeListWnd_guess*)sidl->GetChildItem("RecipeList");
        minTrivial_160 = (EditWnd_guess*)sidl->GetChildItem("MinTrivialEdit");
        maxTrivial_164 = (EditWnd_guess*)sidl->GetChildItem("MaxTrivialEdit");
        searchText_168 = (EditWnd_guess*)sidl->GetChildItem("SearchTextEdit");
        searchButton_16C = sidl->GetChildItem("SearchButton");
        addFavorite_170 = sidl->GetChildItem("AddFavoriteButton");
        removeFavorite_174 = sidl->GetChildItem("RemoveFavoriteButton");
        showFavorites_178 = sidl->GetChildItem("ShowFavoritesButton");
        close_1C0 = sidl->GetChildItem("CloseButton");
        widgets_184.first_guess = (BackRefWidget_guess*)sidl->GetChildItem("ContainerIcon");
        widgets_184.containerName_guess = sidl->GetChildItem("ContainerName");
        widgets_184.skillLabel_guess = sidl->GetChildItem("SkillLabel");
        autoInv_17C = sidl->GetChildItem("AutoInvButton");
        useCtrl_180 = sidl->GetChildItem("UseCtrlCheckbox");
        Animation_guess* drag = g_sidlManager_guess->FindAnimation_guess("A_DragItem");
        for (int i = 0; i < 10; ++i) {
            char name[256];
            // Ten required-component icons, each drawing with its own copy of A_DragItem.
            sprintf(name, "RequiredIcon%d", i);
            widgets_184.items_guess[i] = (BackRefWidget_guess*)sidl->GetChildItem(name);
            Animation_guess* anim = new Animation_guess;
            if (anim != 0) {
                *anim = *drag;
                anim->SetCurCell_guess(-1);
            }
            widgets_184.items_guess[i]->back_guess = anim;
            required_B59[i] = 0;
        }
        combine_1B8 = sidl->GetChildItem("CombineButton");
        experiment_1BC = sidl->GetChildItem("ExperimentButton");
        // Recipe list: the name column left-justified, the trivial column right; Combine waits for a pick.
        if (recipeList_15C != 0) {
            recipeList_15C->SetColors(0xffffffff, 0xff008080, 0xff808080);
            recipeList_15C->SetColumnJustification(0, 0);
            recipeList_15C->SetColumnJustification(1, 1);
            recipeList_15C->field_16C_guess = 0xff8aa3ff;
            recipeList_15C->field_15C_guess = 1;
        }
        if (combine_1B8 != 0) {
            combine_1B8->Enabled = 0;
        }
        if (minTrivial_160 != 0) {
            minTrivial_160->field_230_guess = 3;
            minTrivial_160->SetMaxChars_guess(3);
        }
        if (maxTrivial_164 != 0) {
            maxTrivial_164->field_230_guess = 3;
            maxTrivial_164->SetMaxChars_guess(3);
        }
        if (searchText_168 != 0) {
            searchText_168->field_230_guess = 0;
            searchText_168->SetMaxChars_guess(0x15);
        }
        if (widgets_184.first_guess != 0) {
            Animation_guess* anim = new Animation_guess;
            if (anim != 0) {
                *anim = *drag;
                anim->SetCurCell_guess(-1);
            }
            widgets_184.first_guess->back_guess = anim;
        }
        ((CTradeskillWndView_guess*)this)->LoadRecipeWidths_guess();
        flag_378 = 1;
    }
}

// Experiment cancels and closes, Close only closes, Auto-Inv drops the cursor item into the inventory.
// Enter in the search box searches; a column click (0xF) sorts, the same column again reverses. A double
// click (3) sends message 0x2387 (recipe id; flag 2 with Shift), not in EQEmu's Titanium list.
// FUNCTION: TITANIUM 0x00569324
int CTradeskillWndView_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess,
                                       unsigned int data_guess) {
    if (message_guess == 1) {
        if (sender_guess == (CXWnd*)widget_1BC_guess) {
            pinstCContainerMgr_guess->Cancel_guess(pendingCallback_guess, value_368_guess);
            pendingCallback_guess = 0;
            ((Interface_guess*)this)->Slot30_guess(0, 1);
            return 0;
        }
        if (sender_guess == (CXWnd*)widget_1C0_guess) {
            ((Interface_guess*)this)->Slot30_guess(0, 1);
            return 0;
        }
        if (sender_guess == (CXWnd*)widget_17C_guess) {
            do_autoinventory_guess(g_object_905CE4_guess, 0);
        } else if (sender_guess == (CXWnd*)widget_16C_guess) {
            RequestRecipes_guess();
            return 0;
        } else if (sender_guess == (CXWnd*)child) {
            int index = child->GetCurSel();
            int value = child->GetItemData(index);
            pending_36C_guess = (Pending_guess*)value;
            ((Group_guess*)this)->Dispatch_guess((Pending_guess*)value);
            return 0;
        } else if (sender_guess == (CXWnd*)widget_1B8_guess) {
            SendAutoCombine_guess();
            return 0;
        } else if (sender_guess == (CXWnd*)widget_178_guess) {
            SendFavorites_guess();
            return 0;
        } else if (sender_guess == (CXWnd*)widget_170_guess) {
            AddFavorite_guess();
            return 0;
        } else if (sender_guess == (CXWnd*)widget_174_guess) {
            RemoveFavorite_guess();
            return 0;
        } else if (sender_guess == (CXWnd*)notifier_180_guess) {
            g_flag_9254F5_guess = g_flag_9254F5_guess == 0;
            g_defaults_guess->SetFlag_guess(g_flag_9254F5_guess, "TradeskillWnd", "CtrlBypass");
            return 0;
        }
    } else if (message_guess == 6) {
        if (sender_guess == (CXWnd*)widget_168_guess) {
            if (widget_16C_guess != 0 && widget_16C_guess->active != 0) {
                RequestRecipes_guess();
            }
            return 0;
        }
    } else if (message_guess == 0xf) {
        if (sender_guess == (CXWnd*)child) {
            unsigned int value = value_35C_guess;
            switch (data_guess) {
            case 0:
                value = 0;
                break;
            case 1:
                value = 1;
                break;
            }
            if (value == value_35C_guess) {
                flag_360_guess = flag_360_guess == 0;
            }
            value_35C_guess = value;
            Rebuild_guess();
        }
    } else if (message_guess == 3) {
        if (sender_guess == (CXWnd*)child) {
            int index = child->GetCurSel();
            if (index != -1) {
                int* item_guess = (int*)child->GetItemData(index);
                RecipeSelectPacket_guess packet;
                memset(&packet, 0, sizeof(packet));
                packet.id_guess = *item_guess;
                if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0) {
                    packet.flags_guess |= 2;
                }
                EQSendMessage(g_connection_guess, 0x2387, &packet, sizeof(packet), 1);
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(sender_guess, message_guess,
                                                    (void*)data_guess);
}
