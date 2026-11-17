// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 199: a hint from compare/tumap.py.
// CPotionBeltWnd ("PotionBeltWnd"): four potion-belt slots, each an A_DragItem button with a count label,
// over the profile's belt entries (item id, icon, name: EQEmu PotionBeltItem_Struct). The usable slot count
// comes from GetPotionBeltSize_guess (2 plus a profile value, at most 4). Sends OP_PotionBelt.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/opcodes.h"

struct SlotObject_guess {
	virtual void Release_guess(int flags);
	int padding_guess[29]; // 0x004-0x077
	CXStr text_78_guess;
	int padding_7c_guess;
	unsigned int color_80_guess;
	int padding_84_guess[58]; // 0x084-0x16b
	int field_16c_guess;

	// EXTERNAL: TITANIUM 0x005B1AB0 SlotObject_guess::SetValue_guess
	void SetValue_guess(int value_guess);
	void SetText_guess(const CXStr& text_guess) { text_78_guess = text_guess; }
};

struct Label_guess {
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess();
	virtual void Slot05_guess();
	virtual void Slot06_guess();
	virtual void Slot07_guess();
	virtual void Slot08_guess();
	virtual void Slot09_guess();
	virtual void Slot10_guess();
	virtual void Slot11_guess();
	virtual void Slot12_guess();
	virtual void Slot13_guess();
	virtual void Slot14_guess();
	virtual void Slot15_guess();
	virtual void Slot16_guess();
	virtual void Slot17_guess();
	virtual void Slot18_guess();
	virtual void Slot19_guess();
	virtual void Slot20_guess();
	virtual void Slot21_guess();
	virtual void Slot22_guess();
	virtual void Slot23_guess();
	virtual void Slot24_guess();
	virtual void Slot25_guess();
	virtual void Slot26_guess();
	virtual void Slot27_guess();
	virtual void Slot28_guess();
	virtual void Slot29_guess();
	virtual void Slot30_guess();
	virtual void Slot31_guess();
	virtual void Slot32_guess();
	virtual void Slot33_guess();
	virtual void Slot34_guess();
	virtual void Slot35_guess();
	virtual void Slot36_guess();
	virtual void Slot37_guess();
	virtual void Slot38_guess();
	virtual void Slot39_guess();
	virtual void Slot40_guess();
	virtual void Slot41_guess();
	virtual void Slot42_guess();
	virtual void Slot43_guess();
	virtual void Slot44_guess();
	virtual void Slot45_guess();
	virtual void Slot46_guess();
	virtual void Slot47_guess();
	virtual void Slot48_guess();
	virtual void Slot49_guess();
	virtual void Slot50_guess();
	virtual void Slot51_guess();
	virtual void Slot52_guess();
	virtual void Slot53_guess();
	virtual void Slot54_guess();
	virtual void Slot55_guess();
	virtual void Slot56_guess();
	virtual void Slot57_guess();
	virtual void Slot58_guess();
	virtual void Slot59_guess();
	virtual void Slot60_guess();
	virtual void Slot61_guess();
	virtual void Slot62_guess();
	virtual void SetWindowText_guess(const CXStr& text_guess);
};

struct Parent_guess {
	// EXTERNAL: TITANIUM 0x005A3850 ??0Parent_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
	Parent_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int iniVersion_guess,
		char* blockName_guess);
	// EXTERNAL: TITANIUM 0x005A3100 ??1Parent_guess@@UAE@XZ
	virtual ~Parent_guess();
};

// CTextureAnimation, 0x4C bytes.
struct Anim_guess {
	char padding_guess[0x4c];
	// EXTERNAL: TITANIUM 0x005B1D90 ??0Anim_guess@@QAE@XZ
	Anim_guess();
	// EXTERNAL: TITANIUM 0x004DBB3B ??4Anim_guess@@QAEAAU0@ABU0@@Z
	Anim_guess& operator=(const Anim_guess& other_guess);
	// EXTERNAL: TITANIUM 0x005B1AB0 Anim_guess::SetValue_guess
	void SetValue_guess(int value_guess);
};

struct Button_guess {
	char padding_000_guess[0x60];
	bool flag_60_guess;
	char padding_061_guess[3];
	unsigned int style_64_guess;
	char padding_068_guess[0x104];
	Anim_guess* anim_16c_guess;
	void SetAnimation_guess(Anim_guess* anim_guess) { anim_16c_guess = anim_guess; }
};

struct SidlPiece_guess {
	char padding_guess[0x60];
	unsigned int style_60_guess;
};

struct SidlManager_guess {
	// EXTERNAL: TITANIUM 0x005B44A0 SidlManager_guess::FindAnimation_guess
	Anim_guess* FindAnimation_guess(const CXStr& name_guess);
};

#define g_sidlManager_guess EQ_GLOBAL(SidlManager_guess*, 0x0099D3F4)

struct CPotionBeltWnd_guess : Parent_guess {
	char padding_004_guess[0x14];
	bool flag_18_guess;
	char padding_019_guess[0x43];
	bool show_5c_guess;
	char padding_05d_guess[7];
	unsigned int style_64_guess;
	char padding_068_guess[0xbc];
	SidlPiece_guess* sidlPiece_124_guess;
	char padding_128_guess[0x30];
	int field_158_guess;
	int padding_15c_guess;
	union {
		SlotObject_guess* slots_160_guess[8];
		struct {
			Anim_guess* anims_160_guess[4];
			Button_guess* buttons_170_guess[4];
		};
	};
	Label_guess* labels_180_guess[4];
	CPotionBeltWnd_guess(CXWnd* parent_guess);
	virtual ~CPotionBeltWnd_guess();
	CPotionBeltWnd_guess* DeletingDestructor_guess(unsigned char flags_guess);
	void Refresh_guess();
	bool AboutToShow_guess();
	int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
	bool IsVisible_guess() const { return show_5c_guess; }
};

// EXTERNAL: TITANIUM 0x0065ACD0 ??_7CPotionBeltWnd_guess@@6B@
// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);

// anims_160 and buttons_170 share storage with slots_160 (union): for each button that exists, clears its
// animation pointer (+0x16C) and deletes the animation copy the constructor made.
// FUNCTION: TITANIUM 0x005484DA
CPotionBeltWnd_guess::~CPotionBeltWnd_guess() {
	if (sidlPiece_124_guess != 0) {
		SlotObject_guess** entry = slots_160_guess;
		int remaining = 4;
		do {
			if (entry[4] != 0) {
				entry[4]->field_16c_guess = 0;
				if (*entry != 0) {
					(*entry)->Release_guess(1);
				}
			}
			++entry;
			--remaining;
		} while (remaining != 0);
	}
}

// Scalar deleting destructor of the potion belt window (vtable 0x65ACD0 slot 1): runs the destructor
// (0x005484DA) and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00548548
CPotionBeltWnd_guess* CPotionBeltWnd_guess::DeletingDestructor_guess(unsigned char flags_guess) {
	CPotionBeltWnd_guess* object_guess = this;
	this->CPotionBeltWnd_guess::~CPotionBeltWnd_guess();
	if ((flags_guess & 1) != 0) {
		free(object_guess);
	}
	return object_guess;
}

struct Item_guess {
	// EXTERNAL: TITANIUM 0x005ECC90 Item_guess::GetCount_guess
	int GetCount_guess();
	char padding_00_guess[0x58];
	int multiplier_58_guess;
};

struct Inventory_guess;

struct TableEntry_guess {
	char head_00_guess[0x10];
	int quantity_10_guess;
	char padding_14_guess[0x10];

	// EXTERNAL: TITANIUM 0x004B76A6 TableEntry_guess::GetInventorySlot_guess
	Item_guess** GetInventorySlot_guess(Inventory_guess* inventory_guess);
};

struct Table_guess {
	int count_00_guess;
	int size_04_guess;
	int mask_08_guess;
	int shift_0c_guess;
	TableEntry_guess** blocks_10_guess;
	int blockCount_14_guess;
	int field_18_guess;

	// EXTERNAL: TITANIUM 0x0047C3AF Table_guess::Init_guess
	void Init_guess(int capacity_guess);
	Table_guess(int capacity_guess) { Init_guess(capacity_guess); }
	// EXTERNAL: TITANIUM 0x004B73EE ??1Table_guess@@QAE@XZ
	~Table_guess();
	TableEntry_guess* At_guess(int index_guess) {
		return &blocks_10_guess[index_guess >> shift_0c_guess][index_guess & mask_08_guess];
	}
};

struct Slot_guess {
	int id_00_guess;
	int value_04_guess;
	char name_08_guess[1];
};

struct Inventory_guess {
	char padding_guess[8];
};

struct CharData_guess {
	char padding_0000_guess[0xc280];
	Inventory_guess inventory_c280_guess;

	// EXTERNAL: TITANIUM 0x004BAF4D CharData_guess::GetPotionBeltSize_guess
	int GetPotionBeltSize_guess();
	// EXTERNAL: TITANIUM 0x005F0CD0 CharData_guess::GetSlot_guess
	Slot_guess* GetSlot_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x004BECC9 CharData_guess::AddPotionBeltItem_guess
	void AddPotionBeltItem_guess(int index_guess, int id_guess);
	// EXTERNAL: TITANIUM 0x004BEDCA CharData_guess::UsePotionBeltItem_guess
	void UsePotionBeltItem_guess(int index_guess);
};

#define g_charData_guess EQ_GLOBAL(CharData_guess*, 0x00905D00)

// EXTERNAL: TITANIUM 0x004B85AE FindItemsById_guess
char __cdecl FindItemsById_guess(CharData_guess* charData_guess, int id_guess, int maxCount_guess, int flags_guess,
	Table_guess* table_guess, int zero_guess);

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(CXStr* out_guess, const char* format_guess, ...);

// Redraws the four slots. Past the belt size: no icon, grey (0xFF404040) and no label. Empty: white.
// Else the icon (belt icon - 500, the item-icon cell) and the item name, then the total count of that
// item id in the inventory: green with the count when found, red with "0" when not.
// A stackable item counts its stack size times the entry's quantity.
// FUNCTION: TITANIUM 0x00548564
void CPotionBeltWnd_guess::Refresh_guess() {
	for (int i = 0; i < 4; ++i) {
		if (i >= g_charData_guess->GetPotionBeltSize_guess()) {
			if (slots_160_guess[i] != 0) {
				slots_160_guess[i]->SetValue_guess(-1);
			}
			if (slots_160_guess[i + 4] != 0) {
				{
					CXStr text(EQ_ARRAY(char, 0x0063F53F));
					slots_160_guess[i + 4]->SetText_guess(text);
				}
				slots_160_guess[i + 4]->color_80_guess = 0xff404040;
			}
			if (labels_180_guess[i] != 0) {
				labels_180_guess[i]->SetWindowText_guess(EQ_ARRAY(char, 0x0063F53F));
			}
		} else if (g_charData_guess->GetSlot_guess(i)->id_00_guess == 0) {
			if (slots_160_guess[i] != 0) {
				slots_160_guess[i]->SetValue_guess(-1);
			}
			if (slots_160_guess[i + 4] != 0) {
				{
					CXStr text(EQ_ARRAY(char, 0x0063F53F));
					slots_160_guess[i + 4]->SetText_guess(text);
				}
				slots_160_guess[i + 4]->color_80_guess = 0xffffffff;
			}
			if (labels_180_guess[i] != 0) {
				labels_180_guess[i]->SetWindowText_guess(EQ_ARRAY(char, 0x0063F53F));
			}
		} else {
			if (slots_160_guess[i] != 0) {
				slots_160_guess[i]->SetValue_guess(g_charData_guess->GetSlot_guess(i)->value_04_guess - 500);
			}
			Table_guess table(0x20);
			FindItemsById_guess(g_charData_guess, g_charData_guess->GetSlot_guess(i)->id_00_guess, 999999, 0x100, &table, 0);
			if (table.count_00_guess > 0) {
				int total = 0;
				for (int index = 0; index < table.count_00_guess; ++index) {
					Item_guess* item = *table.At_guess(index)->GetInventorySlot_guess(
						g_charData_guess ? &g_charData_guess->inventory_c280_guess : 0);
					if (item->GetCount_guess() > 0) {
						int stackSize = item->multiplier_58_guess;
						total += stackSize * table.At_guess(index)->quantity_10_guess;
					} else {
						total += table.At_guess(index)->quantity_10_guess;
					}
				}
				CXStr text;
				FormatString_guess(&text, EQ_ARRAY(char, 0x0063F53C), total);
				if (slots_160_guess[i + 4] != 0) {
					{
						CXStr name(g_charData_guess->GetSlot_guess(i)->name_08_guess);
						slots_160_guess[i + 4]->SetText_guess(name);
					}
					slots_160_guess[i + 4]->color_80_guess = 0xff00ff00;
				}
				if (labels_180_guess[i] != 0) {
					labels_180_guess[i]->SetWindowText_guess(text);
				}
			} else {
				if (slots_160_guess[i + 4] != 0) {
					{
						CXStr name(g_charData_guess->GetSlot_guess(i)->name_08_guess);
						slots_160_guess[i + 4]->SetText_guess(name);
					}
					slots_160_guess[i + 4]->color_80_guess = 0xffff0000;
				}
				if (labels_180_guess[i] != 0) {
					labels_180_guess[i]->SetWindowText_guess(EQ_ARRAY(char, 0x006410A8));
				}
			}
		}
	}
}

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
extern "C" int __cdecl sprintf(char* buffer_guess, const char* format_guess, ...);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z

// Each button gets its own copy of the A_DragItem animation, cell -1 (blank) until Refresh_guess sets it.
// Without A_DragItem the slots stay null and the window is never filled.
// FUNCTION: TITANIUM 0x00548B9D
CPotionBeltWnd_guess::CPotionBeltWnd_guess(CXWnd* parent_guess)
	: Parent_guess(parent_guess, "PotionBeltWnd", 0xfffffdff, 1, 0) {
	style_64_guess |= 0x10000;
	field_158_guess = 0x42;
	for (int i = 0; i < 4; ++i) {
		buttons_170_guess[i] = 0;
		labels_180_guess[i] = 0;
		anims_160_guess[i] = 0;
	}
	if (sidlPiece_124_guess != 0) {
		style_64_guess |= sidlPiece_124_guess->style_60_guess | 0x800;
		flag_18_guess = false;
		reinterpret_cast<CSidlScreenWnd*>(this)->CreateChildrenFromSidl();
		Anim_guess* drag_guess = g_sidlManager_guess->FindAnimation_guess("A_DragItem");
		if (drag_guess != 0) {
			for (int i = 0; i < 4; ++i) {
				char name_guess[128];
				sprintf(name_guess, "PotionSlot%d", i);
				buttons_170_guess[i] = (Button_guess*)reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name_guess);
				sprintf(name_guess, "PotionSlotLabel%d", i);
				labels_180_guess[i] = (Label_guess*)reinterpret_cast<CSidlScreenWnd*>(this)->GetChildItem(name_guess);
				anims_160_guess[i] = new Anim_guess;
				if (buttons_170_guess[i] != 0) {
					*anims_160_guess[i] = *drag_guess;
					anims_160_guess[i]->SetValue_guess(-1);
					buttons_170_guess[i]->SetAnimation_guess(anims_160_guess[i]);
					buttons_170_guess[i]->flag_60_guess = false;
					buttons_170_guess[i]->style_64_guess |= 0x800;
				// The animation allocated above is not freed when the button is missing: original leak.
				} else {
					anims_160_guess[i] = 0;
				}
				if (labels_180_guess[i] != 0) {
					labels_180_guess[i]->SetWindowText_guess(EQ_ARRAY(char, 0x0063F53F));
				}
			}
			Refresh_guess();
		}
	}
}

struct SpellRef_guess {
	// EXTERNAL: TITANIUM 0x005E0F30 SpellRef_guess::GetItemId_guess
	int GetItemId_guess();
};

struct CharInfoState_guess {
	char pad_guess[0x78];
	SpellRef_guess* ref_guess;

	SpellRef_guess* GetRef_guess() { return ref_guess; }
};

struct CharInfoOuter_guess {
	char pad_guess[0x10];
	CharInfoState_guess sub_guess;
};

// pCharData's class: vfptr and int at +0, vbptr at +8, the profile in the virtual base.
struct CharDataPrefix_guess {
	virtual void slot00_guess() = 0;
	int field04_guess;
};

struct CharDataVirtual_guess {
	void* vftable_guess;
	EQ_CharacterProfile_guess profile_guess;

	CharInfoOuter_guess* Lookup_guess() {
		return reinterpret_cast<CharInfoOuter_guess*>(profile_guess.GetCharInfo2());
	}
};

struct CharDataRoot_guess : CharDataPrefix_guess, virtual CharDataVirtual_guess {
};

#define g_charRoot_guess EQ_GLOBAL(CharDataRoot_guess*, 0x00905D00)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManager*, 0x0099D3EC)
#define g_object_905CE4_guess EQ_GLOBAL(void*, 0x00905CE4)

// EXTERNAL: TITANIUM 0x00475CE4 do_autoinventory_guess
void __cdecl do_autoinventory_guess(void* object_guess, int value_guess);

// EXTERNAL: TITANIUM 0x0046BC70 SetSocial_guess
int __cdecl SetSocial_guess(const char* left_guess, const char* right_guess, int mode_guess, int limit_guess);

struct SlotMessage_guess {
	int type_guess;
	int index_guess;
	int flags_guess;
};

// Refreshes the slots; false while the SIDL screen is not loaded.
// FUNCTION: TITANIUM 0x00548918
bool CPotionBeltWnd_guess::AboutToShow_guess() {
	if (sidlPiece_124_guess == 0) {
		return false;
	}
	Refresh_guess();
	return true;
}

// Slot notifications (sender = a slot's button):
// 1 (click, no keyboard flags 0xC): with an item on the cursor, AddPotionBeltItem_guess stores it in
//   the slot and do_autoinventory_guess puts it back in the inventory;
// 3: UsePotionBeltItem_guess;
// 0x17 (drag): hot button "PB n" running "/potionbelt Activate n" (string ids 9355, 9310), then
//   13282 (created) or 13283 (failed) in chat;
// 0x18: OP_PotionBelt (12 bytes), action 3 for the slot, flag 2 when keyboard flag 1 is down.
// SetSocial_guess (0x46BC70) creates the hot button: it fills the first free or same-named of the
// 120 hot buttons (10 pages of 12) and returns its index, -1 when all are used.
// FUNCTION: TITANIUM 0x0054892C
int CPotionBeltWnd_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess) {
	if (IsVisible_guess()) {
		if (message_guess == 1) {
			if ((pinstCXWndManager_guess->GetKeyboardFlags() & 0xc) == 0) {
				for (int i = 0; i < 4; ++i) {
					if (sender_guess == (CXWnd*)slots_160_guess[i + 4]) {
						if (g_charRoot_guess->Lookup_guess()->sub_guess.GetRef_guess() != 0) {
							g_charData_guess->AddPotionBeltItem_guess(i,
								g_charRoot_guess->Lookup_guess()->sub_guess.GetRef_guess()->GetItemId_guess());
							do_autoinventory_guess(g_object_905CE4_guess, 0);
							Refresh_guess();
						}
						break;
					}
				}
			}
		} else if (message_guess == 3) {
			for (int i = 0; i < 4; ++i) {
				if (sender_guess == (CXWnd*)slots_160_guess[i + 4]) {
					g_charData_guess->UsePotionBeltItem_guess(i);
					break;
				}
			}
		} else if (message_guess == 0x17) {
			for (int i = 0; i < 4; ++i) {
				if (sender_guess == (CXWnd*)slots_160_guess[i + 4]) {
					CXStr shortName;
					CXStr fullName;
					FormatString_guess(&fullName, EQ_ARRAY(char, 0x006410DC), pStringTable->getString(0x248b, 0),
						pStringTable->getString(0x245e, 0), i + 1);
					FormatString_guess(&shortName, EQ_ARRAY(char, 0x0065ADF0), i + 1);
					int result = SetSocial_guess(shortName, fullName, 0, -1);
					if (result >= 0) {
						pEverQuest->dsp_chat(pStringTable->getString(0x33e2, 0));
					} else {
						pEverQuest->dsp_chat(pStringTable->getString(0x33e3, 0));
					}
				}
			}
		} else if (message_guess == 0x18) {
			for (int i = 0; i < 4; ++i) {
				if (sender_guess == (CXWnd*)slots_160_guess[i + 4]) {
					SlotMessage_guess message;
					message.flags_guess = 0;
					if (pinstCXWndManager_guess->GetKeyboardFlags() & 1) {
						message.flags_guess |= 2;
					}
					message.type_guess = 3;
					message.index_guess = i;
					EQSendMessage(EQ_ARRAY(int, 0x00905CA0), OP_PotionBelt, &message, 0xc, 1);
					break;
				}
			}
		}
	}
	return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(sender_guess, message_guess, data_guess);
}
