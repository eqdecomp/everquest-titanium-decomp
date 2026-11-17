// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 131: a hint from compare/tumap.py.
// CBazaarSearchWnd ("BazaarSearchWnd"), all through OP_BazaarSearch (0x1EE9): action 7 search, 9 welcome,
// 18 inspect, and the replies (7 results, 12 probably "done"). StateOwner_guess, RecordOwner_guess and
// MoneyText_guess are views of this window. Results live in 100 records of 0x98 bytes at +0x180: trader name,
// item name +0x40, price +0x80, sort rank +0x84, item id +0x88, stat value +0x8C, serial +0x90, +0x94.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include <stdio.h>
#include "titanium/crt.h"
#include "titanium/opcodes.h"

struct FlagData_guess
{
	unsigned char padding_0000_guess[0x128];
	char enabled_0128_guess;
};

struct Record_guess
{
	union
	{
		char name_0000_guess[0x40];
		char flag_0000_guess;
	};
	char flag_0040_guess;
	unsigned char padding_0041_guess[0x3f];
	int value_0080_guess;
	int marker_0084_guess;
	int value_0088_guess;
	int value_008c_guess;
	int value_0090_guess;
	int value_0094_guess;
};

struct RecordOwner_guess
{
	unsigned char padding_0000_guess[0x180];
	Record_guess records_0180_guess[100];
	CListWnd* list_3ce0_guess;

	void AddSearchResult_guess(char* label_guess, unsigned int value_guess, char* detail_guess, int value_88_guess,
		int format_arg_guess, int value_90_guess, int value_94_guess);
	void ClearBazaarSearchItems_guess();
};

struct StateValue_guess
{
	unsigned char padding_0000_guess[0x5d];
	unsigned char value_005d_guess;
};

// 8-byte value passed by value to 0x004E36B3.
struct PacketPair_guess
{
	int low_guess;
	int high_guess;
};

#define CONFIG_SLOT(n) virtual void slot_##n##_guess() = 0
struct ConfigVTablePrefix_guess
{
	CONFIG_SLOT(0); CONFIG_SLOT(1); CONFIG_SLOT(2); CONFIG_SLOT(3); CONFIG_SLOT(4); CONFIG_SLOT(5); CONFIG_SLOT(6); CONFIG_SLOT(7);
	CONFIG_SLOT(8); CONFIG_SLOT(9); CONFIG_SLOT(10); CONFIG_SLOT(11); CONFIG_SLOT(12); CONFIG_SLOT(13); CONFIG_SLOT(14); CONFIG_SLOT(15);
	CONFIG_SLOT(16); CONFIG_SLOT(17); CONFIG_SLOT(18); CONFIG_SLOT(19); CONFIG_SLOT(20); CONFIG_SLOT(21); CONFIG_SLOT(22); CONFIG_SLOT(23);
	CONFIG_SLOT(24); CONFIG_SLOT(25); CONFIG_SLOT(26); CONFIG_SLOT(27); CONFIG_SLOT(28); CONFIG_SLOT(29); CONFIG_SLOT(30); CONFIG_SLOT(31);
	CONFIG_SLOT(32); CONFIG_SLOT(33); CONFIG_SLOT(34); CONFIG_SLOT(35); CONFIG_SLOT(36); CONFIG_SLOT(37); CONFIG_SLOT(38); CONFIG_SLOT(39);
	CONFIG_SLOT(40); CONFIG_SLOT(41); CONFIG_SLOT(42); CONFIG_SLOT(43); CONFIG_SLOT(44); CONFIG_SLOT(45); CONFIG_SLOT(46); CONFIG_SLOT(47);
	CONFIG_SLOT(48); CONFIG_SLOT(49); CONFIG_SLOT(50); CONFIG_SLOT(51); CONFIG_SLOT(52); CONFIG_SLOT(53); CONFIG_SLOT(54); CONFIG_SLOT(55);
	CONFIG_SLOT(56); CONFIG_SLOT(57); CONFIG_SLOT(58); CONFIG_SLOT(59); CONFIG_SLOT(60); CONFIG_SLOT(61); CONFIG_SLOT(62); CONFIG_SLOT(63);
	CONFIG_SLOT(64); CONFIG_SLOT(65); CONFIG_SLOT(66); CONFIG_SLOT(67); CONFIG_SLOT(68); CONFIG_SLOT(69); CONFIG_SLOT(70); CONFIG_SLOT(71);
	CONFIG_SLOT(72); CONFIG_SLOT(73); CONFIG_SLOT(74); CONFIG_SLOT(75);
};
#undef CONFIG_SLOT

struct ConfigRoot_guess : ConfigVTablePrefix_guess
{
	virtual void Activate_guess() = 0;
	// EXTERNAL: TITANIUM 0x005986F0 ConfigRoot_guess::SetOption_guess
	void SetOption_guess(int option, const CXStr& value);
};

struct ConfigItem_guess : ConfigVTablePrefix_guess
{
	virtual CXStr GetText_guess() = 0;
};

struct ConfigMap_guess
{
	// EXTERNAL: TITANIUM 0x0059C3A0 ConfigMap_guess::GetCurChoice_guess
	int GetCurChoice_guess();
	// EXTERNAL: TITANIUM 0x0059C3B0 ConfigMap_guess::GetText_guess
	CXStr GetText_guess();
};

// Packet sent by SubmitQuery: 0x6C bytes, type at 0, text at 0x1C.
struct SettingsPacket_guess
{
	int type_0000_guess;
	int setting1_0004_guess;
	int setting2_0008_guess;
	int setting3_000c_guess;
	int setting4_0010_guess;
	int setting5_0014_guess;
	int setting6_0018_guess;
	char text_001c_guess[0x40];
	int setting23_005c_guess;
	int setting24_0060_guess;
	int setting25_0064_guess;
	int setting26_0068_guess;
};

struct LookupSettingResult_guess
{
	unsigned char padding_0000_guess[0x258];
	int value_0258_guess;
};

// EXTERNAL: TITANIUM 0x0047C88E LookupSetting_guess
LookupSettingResult_guess* __cdecl LookupSetting_guess(char* value);

#define g_setting_table_6507d4_guess EQ_ARRAY(int, 0x006507D4)
#define g_setting_table_65088c_guess EQ_ARRAY(int, 0x0065088C)
#define g_setting_table_65094c_guess EQ_ARRAY(int, 0x0065094C)
#define g_setting_table_6506ec_guess EQ_ARRAY(int, 0x006506EC)
#define g_setting_table_65056c_guess EQ_ARRAY(int, 0x0065056C)

struct StateOwner_guess
{
	unsigned char padding_0000_guess[0x5c];
	unsigned char enabled_005c_guess;
	unsigned char padding_005d_guess[0xff];
	int flag_015c_guess;
	int flag_0160_guess;
	int flag_0164_guess;
	int flag_0168_guess;
	int ptr_016c_guess;
	unsigned int time_0170_guess;
	unsigned int time_0174_guess;
	unsigned char flag_0178_guess;
	unsigned char padding_0179_guess[3];
	int value_017c_guess;
	Record_guess records_0180_guess[100];
	union
	{
		CListWnd* list_3ce0_guess;
		ConfigRoot_guess* root_3ce0_guess;
	};
	StateValue_guess* state_3ce4_guess;
	unsigned char padding_3ce8_guess[4];
	StateValue_guess* state_3cec_guess;
	unsigned char padding_3cf0_guess[4];
	StateValue_guess* state_3cf4_guess;
	FlagData_guess* state_3cf8_guess;
	unsigned char padding_3cfc_guess[0x2c];
	ConfigMap_guess* map_3d28_guess;
	ConfigMap_guess* map_3d2c_guess;
	ConfigMap_guess* map_3d30_guess;
	ConfigMap_guess* map_3d34_guess;
	ConfigMap_guess* map_3d38_guess;
	ConfigMap_guess* map_3d3c_guess;
	ConfigItem_guess* item_3d40_guess;
	ConfigItem_guess* item_3d44_guess;
	ConfigItem_guess* item_3d48_guess;
	ConfigItem_guess* item_3d4c_guess;
	ConfigItem_guess* item_3d50_guess;

	// EXTERNAL: TITANIUM 0x005A0E50 StateOwner_guess::OnProcessFrame
	void OnProcessFrame();

	bool IsHideTraders_guess();
	int GetValue_guess();
	void EnableUpdatePlayerButton_guess(unsigned char value);
	void OnProcessFrame_guess();

	// EXTERNAL: TITANIUM 0x004E36B3 StateOwner_guess::AddSearchResult_guess
	void AddSearchResult_guess(int* a, int b, char* c, int d, int e, PacketPair_guess pair);
	void HandleBazaarMsg(int* data, unsigned int size);
	void SortResults_guess(int mode);
	char AboutToHide_guess();
	void SendSearch_guess();
};

struct Named_guess
{
	unsigned char padding_0000_guess[0x120];
	char name_0120_guess[256];
};
// EXTERNAL: TITANIUM 0x00401B28 FindNamed_guess
Named_guess* __cdecl FindNamed_guess(int id);

// EXTERNAL: TITANIUM 0x0046D655 Time_guess
unsigned int __cdecl Time_guess();

#define g_flag_guess EQ_GLOBAL(char*, 0x00985C88)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

struct InitialState_guess
{
	// EXTERNAL: TITANIUM 0x00408F28 InitialState_guess::IsTestServer_guess
	char IsTestServer_guess();
};

struct ValidationState_guess
{
	// EXTERNAL: TITANIUM 0x005F6CC0 ValidationState_guess::Validate_guess
	char Validate_guess(unsigned int value);
    // EXTERNAL: TITANIUM 0x005F6D00 ValidationState_guess::Check_guess
    char Check_guess(unsigned int value);
};

struct CallbackOwner_guess
{
	// EXTERNAL: TITANIUM 0x004E2159 CallbackOwner_guess::Activate_guess
	void Activate_guess();

	char CheckState_guess();
};

struct MoneyText_guess
{
	char* FormatMoney_guess(unsigned int value);
};

// EXTERNAL: TITANIUM 0x0060E450 CopyString_guess
char* __cdecl CopyString_guess(char* destination, const char* source);
// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* text, const char* format, ...);
// EXTERNAL: TITANIUM 0x005A1FE0 InitializeItemList_guess
void __stdcall InitializeItemList_guess(void* list, const char* name);
// EXTERNAL: TITANIUM 0x00464954 SortNames_guess
int __cdecl SortNames_guess(const void* a, const void* b);
// EXTERNAL: TITANIUM 0x00464959 CompareTextB_guess
int __cdecl CompareTextB_guess(const void* a, const void* b);
// EXTERNAL: TITANIUM 0x00464969 CompareIntA_guess
int __cdecl CompareIntA_guess(const void* a, const void* b);
// EXTERNAL: TITANIUM 0x00464976 CompareIntB_guess
int __cdecl CompareIntB_guess(const void* a, const void* b);
// EXTERNAL: TITANIUM 0x00574720 CopyText_guess
void __cdecl CopyText_guess(char* destination, const char* source, int count);
// EXTERNAL: TITANIUM 0x00574950 CompareText_guess
int __cdecl CompareText_guess(const char* first, const char* second);
// EXTERNAL: TITANIUM 0x004649D5 text_to_client_guess
void __cdecl text_to_client_guess(unsigned int color, const char* text, int channel);
#define g_chatColorBase_guess EQ_GLOBAL(unsigned int, 0x00905D00)

// Belongs to tu_130's window (probably CBarterWnd): starts it (0x4E2159) when the list at 0x79C198 is
// ready and the 0x905CC0 check passes; returns whether it did.
// FUNCTION: TITANIUM 0x004E26F6
char CallbackOwner_guess::CheckState_guess()
{
	char result = reinterpret_cast<InitialState_guess*>(EQ_ARRAY(char, 0x0079C198))->IsTestServer_guess() != 0 &&
		EQ_GLOBAL(ValidationState_guess*, 0x00905CC0)->Validate_guess(EQ_GLOBAL(unsigned int, 0x00924470)) != 0;
	if (result != 0)
		Activate_guess();
	return result;
}

/* ---- CBazaarSearchWnd::CBazaarSearchWnd(CXWnd*) (0x004E272F) ----------------------------------------
 * Layout: include/titanium/types.h CBazaarSearchWnd. */

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

struct SearchEntry_guess {
    unsigned int id_guess;                  // 0x00 (12-byte rows)
    unsigned int pad_004_guess[2];
};

struct CDBStr_guess {
    // EXTERNAL: TITANIUM 0x004355F7 CDBStr_guess::GetString_guess
    char* GetString_guess(unsigned int id, int kind, int flag);
};
#define g_stringDb_guess EQ_GLOBAL(CDBStr_guess*, 0x00850398)

struct CEverQuestView_guess {
    // EXTERNAL: TITANIUM 0x004AE919 CEverQuestView_guess::Find_guess
    bool Find_guess(const char* screen, const char* name, int a, int b);
};

struct ComboWnd_guess : CXWnd {
    // EXTERNAL: TITANIUM 0x0059C330 ComboWnd_guess::SetColors_guess
    void SetColors_guess(int a, unsigned int b, unsigned int c);
    // EXTERNAL: TITANIUM 0x0059C8D0 ComboWnd_guess::AddString_guess
    void AddString_guess(const CXStr& text);
    // EXTERNAL: TITANIUM 0x0059C360 ComboWnd_guess::Select_guess
    void Select_guess(int index);
    // EXTERNAL: TITANIUM 0x0059C3E0 ComboWnd_guess::Clear_guess
    void Clear_guess();
    // EXTERNAL: TITANIUM 0x0059C3A0 ComboWnd_guess::GetCurChoice_guess
    int GetCurChoice_guess();
    // EXTERNAL: TITANIUM 0x0059C390 ComboWnd_guess::Count_guess
    int Count_guess();
};

struct ListWnd_guess : CXWnd {
    char pad_11c[0x40];
    unsigned char flag_15c_guess;           // 0x15C
    char pad_15d[0xf];
    unsigned int color_16c_guess;           // 0x16C
    // EXTERNAL: TITANIUM 0x00597C60 ListWnd_guess::SetColors
    void SetColors(int a, unsigned int b, unsigned int c);
    // EXTERNAL: TITANIUM 0x005982E0 ListWnd_guess::SetColumnJustification
    void SetColumnJustification(int column, int value);
};

struct EditWnd_guess : CXWnd {
    char pad_11c[0x114];
    int field_230_guess;                    // 0x230
    // EXTERNAL: TITANIUM 0x004D7EBC EditWnd_guess::SetMaxChars_guess
    void SetMaxChars_guess(int max);
};

struct TextWnd_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
	virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
	virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
	virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
	virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
	virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
	virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
	virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess(); virtual void Slot63_guess();
	virtual void Slot64_guess(); virtual void Slot65_guess(); virtual void Slot66_guess(); virtual void Slot67_guess();
	virtual void Slot68_guess(); virtual void Slot69_guess(); virtual void Slot70_guess(); virtual void Slot71_guess();
	virtual void Slot72_guess(); virtual void Slot73_guess(); virtual void Slot74_guess(); virtual void Slot75_guess();
	virtual CXStr GetText_guess();
};

// Virtual view of a window: SetWindowText is slot 0x3F (0xFC); slot 0x4C (0x130) is the list's clear.
struct WindowVt_guess {
	virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
	virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
	virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
	virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
	virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
	virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
	virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
	virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
	virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
	virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
	virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
	virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
	virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
	virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
	virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess();
	virtual void SetWindowText_guess(const CXStr& text);   // 0x3F (0xFC)
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
	virtual void Slot4C_guess();   // 0x4C (0x130)
};

// EXTERNAL: TITANIUM 0x00650CB8 ??_7BazaarSearchWnd_guess@@6B@
struct BazaarSearchWnd_guess : CSidlScreenWndBase {
    unsigned int flags_15c_guess[4];
    int value_16c_guess;
    unsigned int time_0170_guess;
    int value_174_guess;                    // 0x174
    unsigned char flag_178_guess;
    unsigned char pad_179[3];
    int value_17c_guess;                    // 0x17C
    Record_guess records_0180_guess[100];
    CXWnd* itemList_3ce0;                   // BZR_ItemList
    CButtonWnd* queryButton_3ce4;           // BZR_QueryButton
    CButtonWnd* welcomeButton_3ce8;         // BZR_WelcomeButton
    CButtonWnd* updatePlayerButton_3cec;    // BZR_UpdatePlayerButton
    CButtonWnd* requestItemButton_3cf0;     // BZR_RequestItemButton
    CButtonWnd* findTraderButton_3cf4;      // BZR_FindTraderButton
    CButtonWnd* hideTradersButton_3cf8;     // BZR_HideTradersButton
    CButtonWnd* defaultButton_3cfc;         // BZR_Default
    CXWnd* itemNameLabel_3d00;
    CXWnd* playersLabel_3d04;
    CXWnd* itemSlotLabel_3d08;
    CXWnd* statSlotLabel_3d0c;
    CXWnd* raceSlotLabel_3d10;
    CXWnd* classSlotLabel_3d14;
    CXWnd* itemTypeLabel_3d18;
    CXWnd* searchResultLabel_3d1c;
    CXWnd* maxPriceLabel_3d20;
    CXWnd* minPriceLabel_3d24;
    ComboWnd_guess* itemSlotCombo_3d28;
    ComboWnd_guess* statSlotCombo_3d2c;
    ComboWnd_guess* raceSlotCombo_3d30;
    ComboWnd_guess* classSlotCombo_3d34;
    ComboWnd_guess* itemTypeCombo_3d38;
    ComboWnd_guess* playersCombo_3d3c;
    EditWnd_guess* itemNameInput_3d40;
    EditWnd_guess* maxPriceInput_3d44;
    EditWnd_guess* minPriceInput_3d48;
    EditWnd_guess* maxLevelInput_3d4c;
    EditWnd_guess* minLevelInput_3d50;
    void UpdatePlayerList_guess();
    void ResetInputs_guess();
    int WndNotification_guess(CXWnd* sender, unsigned int message, void* data);
    void UpdateButtons_guess();
    // EXTERNAL: TITANIUM 0x005A1EF0 BazaarSearchWnd_guess::LoadIniListWnd
    void LoadIniListWnd(CXWnd* list, const char* name);
    char Activate_guess();
    BazaarSearchWnd_guess(CXWnd* parent);
};

struct SearchPacket_guess
{
	int type_0000_guess;
	char name_0004_guess[0x40];
	int value_0044_guess;
	int value_0048_guess;
	int value_004c_guess;
	int value_0050_guess;
	int flags_0054_guess;
};

// EXTERNAL: TITANIUM 0x0047C88E FindBazaarItem_guess
void* __cdecl FindBazaarItem_guess(const char* name);
// EXTERNAL: TITANIUM 0x00576FA0 CopyBounded_guess
void __cdecl CopyBounded_guess(char* destination, const char* source, unsigned int size);

struct ListWndExtra_guess : CListWnd
{
	// EXTERNAL: TITANIUM 0x00597C00 ListWndExtra_guess::GetSelectionMode_guess
	int GetSelectionMode_guess() const;
};

struct PlayerPathView_guess
{
	// EXTERNAL: TITANIUM 0x004C13D7 PlayerPathView_guess::Cancel_guess
	void Cancel_guess();
	// EXTERNAL: TITANIUM 0x004C251B PlayerPathView_guess::SelectItem_guess
	void SelectItem_guess(void* item);
};

struct BazaarItemOwner_guess
{
	// EXTERNAL: TITANIUM 0x004797D5 BazaarItemOwner_guess::FacePlayer_guess
	void FacePlayer_guess(void* item);
};

struct FoundBazaarItem_guess
{
	unsigned char padding_0000_guess[0x258];
	int value_0258_guess;
};

struct BazaarSettings_guess
{
	// EXTERNAL: TITANIUM 0x004AE82A BazaarSettings_guess::SetWindowSetting_guess
	void SetWindowSetting_guess(unsigned char enabled, const char* window, const char* setting);
};

#define g_bazaarRuntime_guess EQ_GLOBAL(PlayerPathView_guess*, 0x00985C88)
#define g_bazaarItemOwner_guess EQ_GLOBAL(BazaarItemOwner_guess*, 0x00905CE4)
#define g_bazaarSettings_guess ((BazaarSettings_guess*)pEverQuest)
#define g_bazaarConnection_guess EQ_ARRAY(char, 0x00905CA0)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)

// Bazaar search window constructor: finds the BZR_ controls, limits the text inputs, fills the item type,
// class, race, stat and slot combos from their tables, restores Hide Traders from the UI INI (0x004AE919)
// and sets up the result list.
// FUNCTION: TITANIUM 0x004E272F
BazaarSearchWnd_guess::BazaarSearchWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "BazaarSearchWnd") {
    value_17c_guess = -1;
    hideTradersButton_3cf8 = 0;
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        itemList_3ce0 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemList");
        queryButton_3ce4 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_QueryButton");
        welcomeButton_3ce8 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_WelcomeButton");
        updatePlayerButton_3cec = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_UpdatePlayerButton");
        requestItemButton_3cf0 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_RequestItemButton");
        findTraderButton_3cf4 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_FindTraderButton");
        hideTradersButton_3cf8 = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_HideTradersButton");
        defaultButton_3cfc = (CButtonWnd*)((CSidlScreenWnd*)this)->GetChildItem("BZR_Default");
        itemNameLabel_3d00 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemNameLabel");
        playersLabel_3d04 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_PlayersLabel");
        itemSlotLabel_3d08 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemSlotLabel");
        statSlotLabel_3d0c = ((CSidlScreenWnd*)this)->GetChildItem("BZR_StatSlotLabel");
        raceSlotLabel_3d10 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_RaceSlotLabel");
        classSlotLabel_3d14 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_ClassSlotLabel");
        itemTypeLabel_3d18 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemTypeLabel");
        searchResultLabel_3d1c = ((CSidlScreenWnd*)this)->GetChildItem("BZR_SearchResultLabel");
        maxPriceLabel_3d20 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_MaxPriceLabel");
        minPriceLabel_3d24 = ((CSidlScreenWnd*)this)->GetChildItem("BZR_MinPriceLabel");
        itemSlotCombo_3d28 = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemSlotCombobox");
        statSlotCombo_3d2c = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_StatSlotCombobox");
        raceSlotCombo_3d30 = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_RaceSlotCombobox");
        classSlotCombo_3d34 = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_ClassSlotCombobox");
        itemTypeCombo_3d38 = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemTypeCombobox");
        playersCombo_3d3c = (ComboWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_PlayersCombobox");
        itemNameInput_3d40 = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_ItemNameInput");
        maxPriceInput_3d44 = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_MaxPriceInput");
        minPriceInput_3d48 = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_MinPriceInput");
        maxLevelInput_3d4c = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_MaxLevelInput");
        minLevelInput_3d50 = (EditWnd_guess*)((CSidlScreenWnd*)this)->GetChildItem("BZR_MinLevelInput");
        if (itemNameInput_3d40 != 0) {
            // Item name 30 characters, prices 7 digits, levels 2; field +0x230 = 3 probably makes them
            // numeric.
            itemNameInput_3d40->SetMaxChars_guess(0x1e);
        }
        if (maxPriceInput_3d44 != 0) {
            maxPriceInput_3d44->field_230_guess = 3;
            maxPriceInput_3d44->SetMaxChars_guess(7);
        }
        if (minPriceInput_3d48 != 0) {
            minPriceInput_3d48->field_230_guess = 3;
            minPriceInput_3d48->SetMaxChars_guess(7);
        }
        if (maxLevelInput_3d4c != 0) {
            maxLevelInput_3d4c->field_230_guess = 3;
            maxLevelInput_3d4c->SetMaxChars_guess(2);
        }
        if (minLevelInput_3d50 != 0) {
            minLevelInput_3d50->field_230_guess = 3;
            minLevelInput_3d50->SetMaxChars_guess(2);
        }
        if (playersCombo_3d3c != 0) {
            playersCombo_3d3c->SetColors_guess(-1, 0xffffff00, 0xff808080);
            playersCombo_3d3c->AddString_guess(pStringTable->getString(0x1a63, 0));
            playersCombo_3d3c->Select_guess(0);
        }
        if (hideTradersButton_3cf8 != 0) {
            hideTradersButton_3cf8->SetCheck(((CEverQuestView_guess*)pEverQuest)->Find_guess("BazaarSearchWnd", "HideTraders", 0, 1));
        }
        if (itemTypeCombo_3d38 != 0) {
            itemTypeCombo_3d38->SetColors_guess(-1, 0xffffff00, 0xff808080);
            itemTypeCombo_3d38->AddString_guess(pStringTable->getString(0x1a64, 0));
            // Each combo: a string-table "any" entry, then the 12-byte rows of its table (first int =
            // string id); race names come from CDBStr kind 11.
            int entry = (int)EQ_ARRAY(SearchEntry_guess, 0x00650570);
            do {
                itemTypeCombo_3d38->AddString_guess(pStringTable->getString(((SearchEntry_guess*)entry)->id_guess, 0));
                entry += sizeof(SearchEntry_guess);
            } while (entry < (int)EQ_ARRAY(SearchEntry_guess, 0x006506F0));
            itemTypeCombo_3d38->Select_guess(0);
        }
        if (classSlotCombo_3d34 != 0) {
            classSlotCombo_3d34->SetColors_guess(-1, 0xffffff00, 0xff808080);
            classSlotCombo_3d34->AddString_guess(pStringTable->getString(0x1a65, 0));
            int entry = (int)EQ_ARRAY(SearchEntry_guess, 0x00650890);
            do {
                classSlotCombo_3d34->AddString_guess(pStringTable->getString(((SearchEntry_guess*)entry)->id_guess, 0));
                entry += sizeof(SearchEntry_guess);
            } while (entry < (int)EQ_ARRAY(SearchEntry_guess, 0x00650950));
            classSlotCombo_3d34->Select_guess(0);
        }
        if (raceSlotCombo_3d30 != 0) {
            raceSlotCombo_3d30->SetColors_guess(-1, 0xffffff00, 0xff808080);
            raceSlotCombo_3d30->AddString_guess(pStringTable->getString(0x1a66, 0));
            int entry = (int)EQ_ARRAY(SearchEntry_guess, 0x006507D8);
            do {
                raceSlotCombo_3d30->AddString_guess(g_stringDb_guess->GetString_guess(((SearchEntry_guess*)entry)->id_guess, 0xb, 0));
                entry += sizeof(SearchEntry_guess);
            } while (entry < (int)EQ_ARRAY(SearchEntry_guess, 0x0065088C));
            raceSlotCombo_3d30->Select_guess(0);
        }
        if (statSlotCombo_3d2c != 0) {
            statSlotCombo_3d2c->SetColors_guess(-1, 0xffffff00, 0xff808080);
            statSlotCombo_3d2c->AddString_guess(pStringTable->getString(0x1a67, 0));
            int entry = (int)EQ_ARRAY(SearchEntry_guess, 0x00650950);
            do {
                statSlotCombo_3d2c->AddString_guess(pStringTable->getString(((SearchEntry_guess*)entry)->id_guess, 0));
                entry += sizeof(SearchEntry_guess);
            } while (entry < (int)EQ_ARRAY(SearchEntry_guess, 0x00650A4C));
            statSlotCombo_3d2c->Select_guess(0);
        }
        if (itemSlotCombo_3d28 != 0) {
            itemSlotCombo_3d28->SetColors_guess(-1, 0xffffff00, 0xff808080);
            itemSlotCombo_3d28->AddString_guess(pStringTable->getString(0x1a68, 0));
            int entry = (int)EQ_ARRAY(SearchEntry_guess, 0x006506F0);
            do {
                itemSlotCombo_3d28->AddString_guess(pStringTable->getString(((SearchEntry_guess*)entry)->id_guess, 0));
                entry += sizeof(SearchEntry_guess);
            } while (entry < (int)EQ_ARRAY(SearchEntry_guess, 0x006507D4));
            itemSlotCombo_3d28->Select_guess(0);
        }
        ((ListWnd_guess*)itemList_3ce0)->SetColors(-1, 0xffffff00, 0xff808080);
        ((ListWnd_guess*)itemList_3ce0)->SetColumnJustification(0, 0);
        ((ListWnd_guess*)itemList_3ce0)->SetColumnJustification(1, 1);
        ((ListWnd_guess*)itemList_3ce0)->SetColumnJustification(2, 0);
        ((ListWnd_guess*)itemList_3ce0)->SetColumnJustification(3, 0);
        ((ListWnd_guess*)itemList_3ce0)->color_16c_guess = 0xff8aa3ff;
        ((ListWnd_guess*)itemList_3ce0)->flag_15c_guess = 1;
    }
}

// Empties the 100 result records (rank -1).
// FUNCTION: TITANIUM 0x004E332E
void RecordOwner_guess::ClearBazaarSearchItems_guess()
{
	int* values = &records_0180_guess[0].value_0080_guess;
	int count = 100;
	do
	{
		values[1] |= -1;
		values[0] = 0;
		((Record_guess*)((char*)values - 0x80))->flag_0040_guess = 0;
		((Record_guess*)((char*)values - 0x80))->flag_0000_guess = 0;
		values[2] = 0;
		values[3] = 0;
		values[4] = 0;
		values[5] = 0;
		values += 0x26;
		--count;
	} while (count != 0);
}

// Sets UpdatePlayerButton's enabled byte.
// FUNCTION: TITANIUM 0x004E335A
void StateOwner_guess::EnableUpdatePlayerButton_guess(unsigned char value)
{
	state_3cec_guess->value_005d_guess = value;
}

// Field 0x106C of the EQPlayer's actor info (0x1A8); read only here.
struct ActorInfo_guess
{
	unsigned char padding_0000_guess[0x106c];
	int flag_106c_guess;
};

// Fills the Players combo with the traders in the zone (spawns whose actor info +0x106C is set), sorted,
// after an all-traders entry; then disables UpdatePlayerButton.
// FUNCTION: TITANIUM 0x004E336A
void BazaarSearchWnd_guess::UpdatePlayerList_guess()
{
	int count;
	char* dst;
	char names[600][64];
	for (int i = 0; i < 600; i++)
		names[i][0] = 0;
	{
		EQPlayer* obj = EQ_GLOBAL(EQPlayer*, 0x00905CC4);
		count = 0;
		if (obj != 0)
		{
			dst = names[0];
			EQPlayer* next;
			do
			{
				next = obj->pNext;
				ActorInfo_guess* info = (ActorInfo_guess*)obj->pActorInfo;
				if (info != 0 && info->flag_106c_guess != 0)
				{
					strcpy(dst, obj->Name);
					count++;
					dst += 64;
				}
				obj = next;
			} while (next != 0);
		}
		qsort(names, count, 64, SortNames_guess);
	}
	if (playersCombo_3d3c != 0)
	{
		playersCombo_3d3c->Clear_guess();
		{
			CXStr all("All Traders");
			playersCombo_3d3c->AddString_guess(all);
		}
		playersCombo_3d3c->Select_guess(0);
		count = 0;
		if (strlen(names[0]) > 0)
		{
			char* p = names[0];
			do
			{
				if (count >= 600)
					break;
				{
					CXStr entry(p);
					playersCombo_3d3c->AddString_guess(entry);
				}
				count++;
				p += 64;
			} while (strlen(p) > 0);
		}
	}
	updatePlayerButton_3cec->Enabled = 0;
}

// CBazaarSearchWnd::Deactivate (vtable slot 50): stores the result list's INI layout (0x5A1FE0).
// FUNCTION: TITANIUM 0x004E351B
char StateOwner_guess::AboutToHide_guess()
{
	::InitializeItemList_guess(list_3ce0_guess, "ItemList");
	return 1;
}

// OnProcessFrame: re-enables Query 3 s after the last search ended, and FindTrader 15 s after its last use
// while no find-path trail runs (0x985C88).
// FUNCTION: TITANIUM 0x004E352E
void StateOwner_guess::OnProcessFrame_guess()
{
	if (enabled_005c_guess != 0)
	{
		if (state_3ce4_guess != 0 && flag_0178_guess != 0)
		{
			unsigned int now = Time_guess();
			if (now - time_0170_guess >= 3000)
				state_3ce4_guess->value_005d_guess = 1;
		}
		if (state_3cf4_guess != 0 && g_flag_guess != 0 && *g_flag_guess == 0)
		{
			unsigned int now = Time_guess();
			if ((now - time_0174_guess) / 1000 > 15)
				state_3cf4_guess->value_005d_guess = 1;
		}
	}
	OnProcessFrame();
}

// Copper amount as " 1p 2g 3s 4c", zero units left out, in the static buffer 0x991628.
// FUNCTION: TITANIUM 0x004E35A6
char* MoneyText_guess::FormatMoney_guess(unsigned int value)
{
	int platinum = value / 1000;
	int gold = value % 1000 / 100;
	int silver = value % 100 / 10;
	int copper = value % 10;
	char platinumText[16];
	char copperText[16];
	char goldText[16];
	char silverText[16];
	if (platinum > 0)
		sprintf(platinumText, " %dp", platinum);
	else
		CopyString_guess(platinumText, g_emptyString_guess);
	if (gold > 0)
		sprintf(goldText, " %dg", gold);
	else
		CopyString_guess(goldText, g_emptyString_guess);
	if (silver > 0)
		sprintf(silverText, " %ds", silver);
	else
		CopyString_guess(silverText, g_emptyString_guess);
	if (copper > 0)
		sprintf(copperText, " %dc", copper);
	else
		CopyString_guess(copperText, g_emptyString_guess);
	char* result = EQ_ARRAY(char, 0x00991628);
	sprintf(result, "%s%s%s%s", platinumText, goldText, silverText, copperText);
	return result;
}

// Button states: Query needs any filter or a name over one character, and at least one trader in the
// Players combo; RequestItem needs a selected row; FindTrader stays off (OnProcessFrame turns it back on).
// FUNCTION: TITANIUM 0x004E3809
// @early-stop: budget, structural ndiff=49
void BazaarSearchWnd_guess::UpdateButtons_guess()
{
	int changed = 0;
	if (requestItemButton_3cf0 != 0)
		((StateValue_guess*)requestItemButton_3cf0)->value_005d_guess = 0;
	if (queryButton_3ce4 != 0)
		((StateValue_guess*)queryButton_3ce4)->value_005d_guess = 0;
	if (findTraderButton_3cf4 != 0)
		((StateValue_guess*)findTraderButton_3cf4)->value_005d_guess = 0;
	if (itemSlotCombo_3d28 != 0)
		((StateValue_guess*)itemSlotCombo_3d28)->value_005d_guess = 1;
	if (statSlotCombo_3d2c != 0)
		((StateValue_guess*)statSlotCombo_3d2c)->value_005d_guess = 1;
	if (raceSlotCombo_3d30 != 0)
		((StateValue_guess*)raceSlotCombo_3d30)->value_005d_guess = 1;
	if (playersCombo_3d3c != 0)
		((StateValue_guess*)playersCombo_3d3c)->value_005d_guess = 1;
	if (classSlotCombo_3d34 != 0)
		((StateValue_guess*)classSlotCombo_3d34)->value_005d_guess = 1;
	if (itemNameInput_3d40 != 0)
		((StateValue_guess*)itemNameInput_3d40)->value_005d_guess = 1;
	if (itemTypeCombo_3d38 != 0)
		((StateValue_guess*)itemTypeCombo_3d38)->value_005d_guess = 1;

	int textLength = 0;
	{
		CXStr value = ((TextWnd_guess*)itemNameInput_3d40)->GetText_guess();
		textLength = value.Ptr != 0 ? value.Ptr->length : 0;
	}
	if (itemSlotCombo_3d28->GetCurChoice_guess() > 0 || statSlotCombo_3d2c->GetCurChoice_guess() > 0 ||
		raceSlotCombo_3d30->GetCurChoice_guess() > 0 || classSlotCombo_3d34->GetCurChoice_guess() > 0 ||
		playersCombo_3d3c->GetCurChoice_guess() > 0 || itemTypeCombo_3d38->GetCurChoice_guess() > 0 || textLength > 1)
	{
		changed = 1;
		if (maxPriceInput_3d44 != 0 && minPriceInput_3d48 != 0)
		{
			int valueA = 0;
			int valueB = 0;
			{
				CXStr value = ((TextWnd_guess*)minPriceInput_3d48)->GetText_guess();
				valueA = value.Ptr != 0 ? value.Ptr->length : 0;
			}
			{
				CXStr value = ((TextWnd_guess*)maxPriceInput_3d44)->GetText_guess();
				valueB = value.Ptr != 0 ? value.Ptr->length : 0;
			}
			int low = 0;
			int high = 0;
			{
				low = atoi(((TextWnd_guess*)minPriceInput_3d48)->GetText_guess());
			}
			{
				high = atoi(((TextWnd_guess*)maxPriceInput_3d44)->GetText_guess());
			}
			if ((valueA != 0 || valueB != 0) && (low != 0 || high != 0) && low <= high)
				changed = 1;
		}
	}
	if (((CListWnd*)itemList_3ce0)->GetCurSel() >= 0 && requestItemButton_3cf0 != 0)
		((StateValue_guess*)requestItemButton_3cf0)->value_005d_guess = 1;
	if (changed && playersCombo_3d3c->Count_guess() > 1)
		((StateValue_guess*)queryButton_3ce4)->value_005d_guess = 1;
}

// Adds one result row (up to 100): item name, price, trader and the stat value when nonzero, keeping the
// rest in the record for inspect and sorting.
// FUNCTION: TITANIUM 0x004E36B3
// @early-stop: budget, diff ndiff=11
void RecordOwner_guess::AddSearchResult_guess(char* label_guess, unsigned int value_guess, char* detail_guess,
	int value_88_guess, int format_arg_guess, int value_90_guess, int value_94_guess)
{
	CXStr text;
	int index = list_3ce0_guess->ItemsCount;
	if (index < 100)
	{
		records_0180_guess[index].value_0088_guess = value_88_guess;
		records_0180_guess[index].value_008c_guess = format_arg_guess;
		records_0180_guess[index].value_0090_guess = value_90_guess;
		records_0180_guess[index].value_0094_guess = value_94_guess;
		records_0180_guess[index].marker_0084_guess = 0;
		records_0180_guess[index].value_0080_guess = value_guess;
		CopyString_guess(&records_0180_guess[index].flag_0040_guess, label_guess);
		CopyString_guess(&records_0180_guess[index].flag_0000_guess, detail_guess);
		text = label_guess;
		int row = list_3ce0_guess->AddString(text, 0xffffffff, index, 0);
		text = ((MoneyText_guess*)this)->FormatMoney_guess(value_guess);
		list_3ce0_guess->SetItemText(row, 1, text);
		text = detail_guess;
		list_3ce0_guess->SetItemText(row, 2, text);
		text.~CXStr();
		if (format_arg_guess != 0)
			FormatString_guess(&text, EQ_ARRAY(char, 0x0063F53C), format_arg_guess);
		list_3ce0_guess->SetItemText(row, 3, text);
	}
}

// Sends the search (BazaarSearch_Struct, action 7): trader spawn id (0 = all), class, race, stat, slot and
// type from the combo tables (-1 = any), name, price range and level range (defaults 1-70).
// FUNCTION: TITANIUM 0x004E3AA7
void StateOwner_guess::SendSearch_guess()
{
	SettingsPacket_guess packet;
	char initialText[32];
	int setting6;
	int setting25;
	int setting4;
	int setting26;
	int setting23;
	int setting24;
	int setting2;
	int setting5;
	int setting3;
	int setting1;
	memset(&packet, 0, sizeof(packet));
	setting6 = -1;
	setting4 = -1;
	setting5 = -1;
	setting2 = -1;
	setting3 = -1;
	setting23 = 0;
	setting24 = 0;
	setting25 = 1;
	// Default max level 70.
	setting26 = 0x46;
	setting1 = 0;
	root_3ce0_guess->Activate_guess();
	{
		strcpy(initialText, item_3d40_guess->GetText_guess());
	}

	if (map_3d30_guess->GetCurChoice_guess() != 0)
		setting3 = g_setting_table_6507d4_guess[map_3d30_guess->GetCurChoice_guess() * 3];
	if (map_3d34_guess->GetCurChoice_guess() != 0)
		setting2 = g_setting_table_65088c_guess[map_3d34_guess->GetCurChoice_guess() * 3];
	if (map_3d2c_guess->GetCurChoice_guess() != 0)
	{
		setting4 = g_setting_table_65094c_guess[map_3d2c_guess->GetCurChoice_guess() * 3];
		root_3ce0_guess->SetOption_guess(3, map_3d2c_guess->GetText_guess());
	}
	if (map_3d28_guess->GetCurChoice_guess() != 0)
		setting5 = g_setting_table_6506ec_guess[map_3d28_guess->GetCurChoice_guess() * 3];
	if (map_3d38_guess->GetCurChoice_guess() != 0)
		setting6 = g_setting_table_65056c_guess[map_3d38_guess->GetCurChoice_guess() * 3];

	if (item_3d44_guess != 0)
	{
		setting24 = atoi(item_3d44_guess->GetText_guess());
	}
	if (item_3d48_guess != 0)
	{
		setting23 = atoi(item_3d48_guess->GetText_guess());
	}
	if (item_3d4c_guess != 0)
	{
		setting26 = atoi(item_3d4c_guess->GetText_guess());
	}
	if (item_3d50_guess != 0)
	{
		setting25 = atoi(item_3d50_guess->GetText_guess());
	}

	LookupSettingResult_guess* found;
	{
		found = LookupSetting_guess(map_3d3c_guess->GetText_guess());
	}
	if (found != 0)
		setting1 = found->value_0258_guess;

	packet.setting2_0008_guess = setting2;
	packet.setting3_000c_guess = setting3;
	packet.setting5_0014_guess = setting5;
	packet.setting4_0010_guess = setting4;
	packet.setting6_0018_guess = setting6;
	packet.setting23_005c_guess = setting23;
	packet.setting24_0060_guess = setting24;
	packet.setting25_0064_guess = setting25;
	packet.setting26_0068_guess = setting26;
	packet.setting1_0004_guess = setting1;
	strcpy(packet.text_001c_guess, initialText);
	packet.type_0000_guess = 7;
	// 0x6C bytes; replies arrive in HandleBazaarMsg.
	EQSendMessage(EQ_ARRAY(void, 0x00905CA0), OP_BazaarSearch, &packet, 0x6c, 1);
}

// Whether HideTradersButton is checked.
// FUNCTION: TITANIUM 0x004E3ECA
bool StateOwner_guess::IsHideTraders_guess()
{
	return state_3cf8_guess != 0 && state_3cf8_guess->enabled_0128_guess != 0;
}

// Bazaar search window: returns the spawn id of the trader picked with Find Trader (+0x17C; 0 after
// HideTraders is toggled). With HideTraders checked, spawn visibility (0x0047E7EE) hides every trader
// except this one.
// FUNCTION: TITANIUM 0x004E3EE4
int StateOwner_guess::GetValue_guess()
{
	return value_017c_guess;
}

// Clears the results and rebuilds the trader list, resets prices and levels, and prints string 0x1A69.
// FUNCTION: TITANIUM 0x004E3EEB
void BazaarSearchWnd_guess::ResetInputs_guess()
{
	((RecordOwner_guess*)this)->ClearBazaarSearchItems_guess();
	UpdatePlayerList_guess();
	((WindowVt_guess*)itemList_3ce0)->Slot4C_guess();
	if (maxPriceInput_3d44 != 0)
		// The largest 7-digit price.
		((WindowVt_guess*)maxPriceInput_3d44)->SetWindowText_guess("9999999");
	if (minPriceInput_3d48 != 0)
		((WindowVt_guess*)minPriceInput_3d48)->SetWindowText_guess(EQ_ARRAY(char, 0x006410A8));
	if (maxLevelInput_3d4c != 0)
		((WindowVt_guess*)maxLevelInput_3d4c)->SetWindowText_guess(EQ_ARRAY(char, 0x00650DF4));
	if (minLevelInput_3d50 != 0)
		((WindowVt_guess*)minLevelInput_3d50)->SetWindowText_guess(EQ_ARRAY(char, 0x00645EB4));
	text_to_client_guess(g_chatColorBase_guess != 0 ? g_chatColorBase_guess + 0xc280 : 0, pStringTable->getString(0x1a69, 0), 0xf);
	value_174_guess = 0;
}

// CBazaarSearchWnd::Activate (vtable slot 49): unless the 0x905CC0 check fails, resets the window, the
// sort flags and the Query timer, and loads the result list's INI layout.
// FUNCTION: TITANIUM 0x004E405B
char BazaarSearchWnd_guess::Activate_guess()
{
	char result = 0;
	if (EQ_GLOBAL(ValidationState_guess*, 0x00905CC0)->Check_guess(EQ_GLOBAL(unsigned int, 0x00924470)) != 0)
	{
		ResetInputs_guess();
		flags_15c_guess[2] = 0;
		flags_15c_guess[0] = 0;
		flags_15c_guess[1] = 0;
		flags_15c_guess[3] = 0;
		value_16c_guess = 0;
		time_0170_guess = Time_guess() - 3000;
		flag_178_guess = 1;
		LoadIniListWnd(itemList_3ce0, "ItemList");
		result = 1;
	}
	UpdateButtons_guess();
	return result;
}

// Re-sorts the results by column `mode` (0 item, 1 price, 2 trader, 3 stat), each column with its own
// reverse flag (+0x15C-0x168), and refills the list. Ties are ranked in record order.
// FUNCTION: TITANIUM 0x004E40D2
// @early-stop: budget, structural ndiff=64
void StateOwner_guess::SortResults_guess(int mode)
{
	Record_guess rows[100];
	char key[0x40] = {0};
	char keys[100][0x40];
	int i;
	int k;
	int count;

	memcpy(rows, records_0180_guess, sizeof(rows));
	((RecordOwner_guess*)this)->ClearBazaarSearchItems_guess();
	count = list_3ce0_guess->ItemsCount;
	((WindowVt_guess*)list_3ce0_guess)->Slot4C_guess();
	if (mode == 2)
	{
		memset(keys, 0, sizeof(keys));
		int* marker = &rows[0].marker_0084_guess;
		int n = 100;
		do
		{
			*marker = -1;
			marker += 0x26;
			--n;
		} while (n != 0);
		for (i = 0; i < count; ++i)
			CopyString_guess(keys[i], rows[i].name_0000_guess);
		if (flag_0164_guess == 0)
			qsort(keys, count, 0x40, SortNames_guess);
		else
			qsort(keys, count, 0x40, CompareTextB_guess);
		for (k = 0; k < count; ++k)
		{
			for (i = 0; i < count; ++i)
			{
				if (CompareText_guess(keys[k], rows[i].name_0000_guess) == 0 && rows[i].marker_0084_guess == -1)
				{
					rows[i].marker_0084_guess = k;
					break;
				}
			}
		}
	}
	else if (mode == 0)
	{
		memset(keys, 0, sizeof(keys));
		int* marker = &rows[0].marker_0084_guess;
		int n = 100;
		do
		{
			*marker = -1;
			marker += 0x26;
			--n;
		} while (n != 0);
		for (i = 0; i < count; ++i)
		{
			CopyText_guess(&rows[i].flag_0040_guess, key, 0x40);
			CopyString_guess(keys[i], key);
		}
		if (flag_015c_guess == 0)
			qsort(keys, count, 0x40, SortNames_guess);
		else
			qsort(keys, count, 0x40, CompareTextB_guess);
		for (k = 0; k < count; ++k)
		{
			for (i = 0; i < count; ++i)
			{
				if (CompareText_guess(keys[k], &rows[i].flag_0040_guess) == 0 && rows[i].marker_0084_guess == -1)
				{
					rows[i].marker_0084_guess = k;
					break;
				}
			}
		}
	}
	else if (mode == 1)
	{
		int sorted[100] = {0};
		int* marker = &rows[0].marker_0084_guess;
		int n = 100;
		do
		{
			*marker = -1;
			marker += 0x26;
			--n;
		} while (n != 0);
		for (i = 0; i < count; ++i)
			sorted[i] = rows[i].value_0080_guess;
		if (flag_0160_guess == 0)
			qsort(sorted, count, 4, CompareIntA_guess);
		else
			qsort(sorted, count, 4, CompareIntB_guess);
		for (k = 0; k < count; ++k)
		{
			for (i = 0; i < count; ++i)
			{
				if (sorted[k] == rows[i].value_0080_guess && rows[i].marker_0084_guess == -1)
				{
					rows[i].marker_0084_guess = k;
					break;
				}
			}
		}
	}
	else if (mode == 3)
	{
		int sorted[100] = {0};
		int* marker = &rows[0].marker_0084_guess;
		int n = 100;
		do
		{
			*marker = -1;
			marker += 0x26;
			--n;
		} while (n != 0);
		for (i = 0; i < count; ++i)
			sorted[i] = rows[i].value_008c_guess;
		if (flag_0168_guess == 0)
			qsort(sorted, count, 4, CompareIntA_guess);
		else
			qsort(sorted, count, 4, CompareIntB_guess);
		for (k = 0; k < count; ++k)
		{
			for (i = 0; i < count; ++i)
			{
				if (sorted[k] == rows[i].value_008c_guess && rows[i].marker_0084_guess == -1)
				{
					rows[i].marker_0084_guess = k;
					break;
				}
			}
		}
	}
	for (k = 0; k < count; ++k)
	{
		for (i = 0; i < count; ++i)
		{
			if (rows[i].marker_0084_guess == k)
			{
				PacketPair_guess pair = {rows[i].value_0090_guess, rows[i].value_0094_guess};
				AddSearchResult_guess((int*)&rows[i].flag_0040_guess, rows[i].value_0080_guess, (char*)&rows[i],
					rows[i].value_0088_guess, rows[i].value_008c_guess, pair);
				break;
			}
		}
	}
}

// 0x60-byte record as copied from the packet.
struct PacketEntry_guess
{
	int type_0000_guess;
	int id_0004_guess;
	int value_0008_guess;
	int value_000c_guess;
	PacketPair_guess pair_0010_guess;
	int data_0018_guess[16];
	int value_0058_guess;
	int value_005c_guess;
};

// CBazaarSearchWnd::HandleBazaarMsg (MQ2 name): action 7 is a batch of 0x60-byte results, 12 ends the
// search (re-sort by the last column, Query may come back).
// FUNCTION: TITANIUM 0x004E455A
void StateOwner_guess::HandleBazaarMsg(int* data, unsigned int size)
{
	if (*data != 7)
	{
		if (*data == 0xc)
		{
			SortResults_guess(ptr_016c_guess);
			flag_0178_guess = 1;
		}
	}
	else
	{
		// Not cleared per entry: an unknown trader id shows the previous row's trader.
		char name[64] = {0};
		PacketEntry_guess entries[200];
		// Up to 200 results fit; a longer packet overruns `entries` (no size check).
		int count = size / 0x60;
		memset(entries, 0, sizeof(entries));
		memcpy(entries, data, count * 0x60);
		for (int i = 0; i < count; i++)
		{
			Named_guess* named = FindNamed_guess(entries[i].id_0004_guess);
			if (named != 0)
				CopyString_guess(name, named->name_0120_guess);
			AddSearchResult_guess(entries[i].data_0018_guess, entries[i].value_0058_guess, name, entries[i].value_000c_guess,
				entries[i].value_005c_guess, entries[i].pair_0010_guess);
		}
	}
}

// WndNotification. Clicks: Default resets the filters, Welcome asks for the bazaar summary (action 9),
// UpdatePlayer rebuilds the trader list, Query searches, FindTrader starts a find-path to the row's trader,
// HideTraders saves its INI flag, RequestItem inspects the row (action 18; shift sets flag 2). 0xF sorts by
// the clicked column; Enter in the name box searches; type 3 on a row inspects it, or with the list in
// mode 2 probably targets the trader (find-path at most every 15 s).
// FUNCTION: TITANIUM 0x004E463F
// @early-stop: budget, structural ndiff=182
int BazaarSearchWnd_guess::WndNotification_guess(CXWnd* sender, unsigned int message, void* data)
{
	int one = 0;
	++one;
	if (message == (unsigned int)one)
	{
		if (sender == defaultButton_3cfc)
		{
			if (itemNameInput_3d40 != 0)
				((WindowVt_guess*)itemNameInput_3d40)->SetWindowText_guess(EQ_ARRAY(char, 0x0063F53F));
			if (playersCombo_3d3c != 0)
				playersCombo_3d3c->Select_guess(0);
			if (itemTypeCombo_3d38 != 0)
				itemTypeCombo_3d38->Select_guess(0);
			if (classSlotCombo_3d34 != 0)
				classSlotCombo_3d34->Select_guess(0);
			if (raceSlotCombo_3d30 != 0)
				raceSlotCombo_3d30->Select_guess(0);
			if (statSlotCombo_3d2c != 0)
				statSlotCombo_3d2c->Select_guess(0);
			if (itemSlotCombo_3d28 != 0)
				itemSlotCombo_3d28->Select_guess(0);
			if (maxPriceInput_3d44 != 0)
				((WindowVt_guess*)maxPriceInput_3d44)->SetWindowText_guess("9999999");
			if (minPriceInput_3d48 != 0)
				((WindowVt_guess*)minPriceInput_3d48)->SetWindowText_guess(EQ_ARRAY(char, 0x006410A8));
			if (maxLevelInput_3d4c != 0)
				((WindowVt_guess*)maxLevelInput_3d4c)->SetWindowText_guess(EQ_ARRAY(char, 0x00650DF4));
			if (minLevelInput_3d50 != 0)
				((WindowVt_guess*)minLevelInput_3d50)->SetWindowText_guess(EQ_ARRAY(char, 0x00645EB4));
			UpdateButtons_guess();
		}
		else if (sender == welcomeButton_3ce8)
		{
			int packet[5];
			memset(packet, 0, sizeof(packet));
			// WelcomeMessage: the server answers with trader and item counts.
			packet[0] = 9;
			EQSendMessage(g_bazaarConnection_guess, OP_BazaarSearch, packet, sizeof(packet), 1);
			return 0;
		}
		else if (sender == updatePlayerButton_3cec)
		{
			UpdatePlayerList_guess();
			UpdateButtons_guess();
			return 0;
		}
		else if (sender == queryButton_3ce4)
		{
			queryButton_3ce4->Enabled = 0;
			flag_178_guess = 0;
			time_0170_guess = Time_guess();
			((StateOwner_guess*)this)->SendSearch_guess();
			return 0;
		}
		else if (sender == findTraderButton_3cf4)
		{
			findTraderButton_3cf4->Enabled = 0;
			CListWnd* list = (CListWnd*)itemList_3ce0;
			char itemName[0x50];
			CopyString_guess(itemName, (char*)list->GetItemText(list->GetCurSel(), 2));
			void* item = FindBazaarItem_guess(itemName);
			if (item != 0)
			{
				g_bazaarRuntime_guess->Cancel_guess();
				g_bazaarRuntime_guess->SelectItem_guess(item);
				value_174_guess = Time_guess();
				value_17c_guess = ((FoundBazaarItem_guess*)item)->value_0258_guess;
			}
			return 0;
		}
		else if (sender == hideTradersButton_3cf8)
		{
			g_bazaarSettings_guess->SetWindowSetting_guess(((FlagData_guess*)hideTradersButton_3cf8)->enabled_0128_guess,
				"BazaarSearchWnd", "HideTraders");
			value_17c_guess = 0;
			return 0;
		}
		else if (sender == requestItemButton_3cf0)
		{
			SearchPacket_guess packet;
			memset(&packet, 0, sizeof(packet));
			int selected = ((CListWnd*)itemList_3ce0)->GetCurSel();
			if (selected != -1)
			{
				((CListWnd*)itemList_3ce0)->GetItemData(selected);
				Record_guess* record = &records_0180_guess[selected];
				packet.value_0050_guess = record->value_0088_guess;
				packet.value_0048_guess = record->value_0090_guess;
				packet.value_004c_guess = record->value_0094_guess;
				CopyBounded_guess(packet.name_0004_guess, record->name_0000_guess, 0x40);
				if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0)
					packet.flags_0054_guess |= 2;
				packet.type_0000_guess = 0x12;
				EQSendMessage(g_bazaarConnection_guess, OP_BazaarSearch, &packet, sizeof(packet), 1);
			}
			return 0;
		}
		else if (sender == itemSlotCombo_3d28 || sender == statSlotCombo_3d2c ||
			sender == raceSlotCombo_3d30 || sender == classSlotCombo_3d34 ||
			sender == itemTypeCombo_3d38 || sender == playersCombo_3d3c)
		{
			UpdateButtons_guess();
			return 0;
		}
		else if (sender == itemList_3ce0)
		{
			UpdateButtons_guess();
			return 0;
		}
	}
	else if (message == 0xe)
	{
		UpdateButtons_guess();
		return 0;
	}
	else if (message == 0xf)
	{
		value_16c_guess = (int)data;
		if (data == 0)
			flags_15c_guess[0] ^= one;
		else if ((int)data == 1)
			flags_15c_guess[1] ^= one;
		else if ((int)data == 2)
			flags_15c_guess[2] ^= one;
		else if ((int)data == 3)
			flags_15c_guess[3] ^= one;
		((StateOwner_guess*)this)->SortResults_guess((int)data);
		return 0;
	}
	else if (message == 6)
	{
		if (sender == itemNameInput_3d40)
		{
			if (queryButton_3ce4->Enabled != 0)
			{
				queryButton_3ce4->Enabled = 0;
				flag_178_guess = 0;
				time_0170_guess = Time_guess();
				((StateOwner_guess*)this)->SendSearch_guess();
			}
			return 0;
		}
	}
	else if (message == 3 && sender == itemList_3ce0)
	{
		int mode = ((ListWndExtra_guess*)itemList_3ce0)->GetSelectionMode_guess();
		if (mode == 0)
		{
			SearchPacket_guess packet;
			memset(&packet, 0, sizeof(packet));
			int selected = ((CListWnd*)itemList_3ce0)->GetCurSel();
			if (selected != -1)
			{
				((CListWnd*)itemList_3ce0)->GetItemData(selected);
				Record_guess* record = &records_0180_guess[selected];
				packet.value_0050_guess = record->value_0088_guess;
				packet.value_0048_guess = record->value_0090_guess;
				packet.value_004c_guess = record->value_0094_guess;
				CopyBounded_guess(packet.name_0004_guess, record->name_0000_guess, 0x40);
				if ((pinstCXWndManager_guess->GetKeyboardFlags() & 1) != 0)
					packet.flags_0054_guess |= 2;
				packet.type_0000_guess = 0x12;
				EQSendMessage(g_bazaarConnection_guess, OP_BazaarSearch, &packet, sizeof(packet), 1);
			}
		}
		else if (mode == 2)
		{
			CListWnd* list = (CListWnd*)itemList_3ce0;
			char itemName[0x40];
			CopyString_guess(itemName, (char*)list->GetItemText(list->GetCurSel(), 2));
			void* item = FindBazaarItem_guess(itemName);
			if (item != 0)
			{
				g_bazaarItemOwner_guess->FacePlayer_guess(item);
				value_17c_guess = ((FoundBazaarItem_guess*)item)->value_0258_guess;
				g_bazaarRuntime_guess->Cancel_guess();
				unsigned int now = Time_guess();
				if ((now - value_174_guess) / 1000 > 15)
				{
					g_bazaarRuntime_guess->SelectItem_guess(item);
					value_174_guess = Time_guess();
				}
			}
		}
		return 0;
	}
	return ((CSidlScreenWnd*)this)->WndNotification(sender, message, data);
}

