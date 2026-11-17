// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 127: a hint from compare/tumap.py.
// CBankWnd, built as "BankWnd" (8 slots) or "BigBankWnd" (16, plus AutoButton) by the same ctor.
// CBankWnd_guess, Window_guess, State_guess and Owner_guess are all CBankWnd views (+0x168 coin labels,
// +0x17C BankerName, +0x180 bank slots, +0x1C0 shared slots, +0x1D8 slot count). 0x905D14 is the banker
// being talked to. Inventory slot ids: 2000-2015 bank, 2031 + 10*slot + n inside bank bags.
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/crt.h"

struct FormatManager_guess {
	// EXTERNAL: TITANIUM 0x00492EC2 FormatManager_guess::Lookup_guess
	char* Lookup_guess(const char* text_guess);
	// EXTERNAL: TITANIUM 0x004982C6 FormatManager_guess::Display_guess
	void Display_guess(const char* text_guess);
	// EXTERNAL: TITANIUM 0x00495F81 FormatManager_guess::MoveMoney_guess
	void MoveMoney_guess(int a_guess, int b_guess, int c_guess, int d_guess, int e_guess, int f_guess);
	// EXTERNAL: TITANIUM 0x004A1350 FormatManager_guess::SavePC_guess
	void SavePC_guess(int first_guess, int second_guess, int third_guess);
};

// EXTERNAL: TITANIUM 0x0046DA4A Format_guess
void __cdecl Format_guess(char* output_guess, int format_guess, ...);

struct Owner_guess {
	// EXTERNAL: TITANIUM 0x005A0A80 Owner_guess::Update_guess
	void Update_guess(int first_guess, int second_guess);
	void CloseBank_guess(char enabled_guess);
	void Show_guess(char enabled_guess, int value_guess);
	void OpenBank_guess(char* message_guess);
};

struct ModalManager_guess {
	// EXTERNAL: TITANIUM 0x004A2F7A ModalManager_guess::SetAutoAttack_guess
	void SetAutoAttack_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x0049994C ModalManager_guess::SetAutoFire_guess
	void SetAutoFire_guess(int value_guess);
};

struct StringTableView_guess {
	// EXTERNAL: TITANIUM 0x005DFA00 StringTableView_guess::GetString_guess
	char* GetString_guess(int id_guess, int zero_guess, int kind_guess, int enabled_guess);
};

struct EventRouter_guess {
	// EXTERNAL: TITANIUM 0x0044A617 EventRouter_guess::CCursorAttachmentView_guess
	void CCursorAttachmentView_guess(int event_guess, int value_guess);
};

struct QueueRoot_guess {
	char padding_0000_guess[0xc280];
	struct RequestLootSlot_guess {
	// EXTERNAL: TITANIUM 0x00417A1D QueueRoot_guess::RequestLootSlot_guess::Process_guess
	void Process_guess(int value_guess);
	} queue_0000_guess;
};

#define g_modal_guess EQ_GLOBAL(ModalManager_guess, 0x00923770)
#define g_resourceManager_guess EQ_GLOBAL(StringTableView_guess*, 0x00905CB0)
#define g_eventRouter_guess EQ_GLOBAL(EventRouter_guess*, 0x00851390)
#define g_queueRoot_guess EQ_GLOBAL(QueueRoot_guess*, 0x00905D00)

struct Window_guess;

struct State_guess {
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
	virtual void Notify_guess(int first_guess, int second_guess);
	char padding_0000_guess[0x58];
	char flag_005c_guess;
	char padding_005d_guess[0xff];
	int value_015c_guess;
	unsigned int timer_0160_guess;
	char flag_0164_guess;
	// EXTERNAL: TITANIUM 0x005A1880 State_guess::Tail_guess
	void Tail_guess();
	// EXTERNAL: TITANIUM 0x005A0E50 State_guess::UpdateBase_guess
	void UpdateBase_guess();
	void OnProcessFrame_guess();
	void OnShow_guess();
};

struct TickSource_guess {
	char padding_0000_guess[0x148];
	unsigned int tick_0148_guess;
	// EXTERNAL: TITANIUM 0x00439D16 TickSource_guess::PlayerDistance_guess
	float PlayerDistance_guess(const void* first_guess, const void* second_guess,
		float scale_guess);
};

#define g_tickSource_guess EQ_GLOBAL(TickSource_guess*, 0x00905D24)

struct CXWndManagerView_guess {
	// EXTERNAL: TITANIUM 0x005B0940 CXWndManagerView_guess::BringWndToTop
	void BringWndToTop(State_guess* state_guess, int enabled_guess);
	// EXTERNAL: TITANIUM 0x005ADF60 CXWndManagerView_guess::GetKeyboardFlags
	unsigned char GetKeyboardFlags();
};

#define g_message_guess EQ_GLOBAL(char*, 0x00905D14)
#define g_formatManager_guess EQ_GLOBAL(FormatManager_guess*, 0x00988DF0)
#define pinstCXWndManager_guess EQ_GLOBAL(CXWndManagerView_guess*, 0x0099D3EC)

#include "titanium/layouts/geometry.h"
#include "titanium/wnd/CInvSlotMgr.h"
#include "titanium/wnd/CTipWnd.h"
#include "titanium/wnd/CContainerMgr.h"
#include "titanium/wnd/CCursorAttachment.h"
#include "titanium/wnd/CInventoryWnd.h"
#include "titanium/wnd/CQuantityWnd.h"

struct Rect_guess {
	int left_guess;
	int top_guess;
	int right_guess;
	int bottom_guess;

	void CenterPoint(CXPoint* point);
};

// Writes the rect's centre point ((left + right) / 2, (top + bottom) / 2, rounded toward left/top)
// to `point`. The bank, barter, bazaar, guild bank, inventory, slot and combat ability windows use
// it to place a popup, such as the quantity window, over the clicked control.
// FUNCTION: TITANIUM 0x004DC02D
void Rect_guess::CenterPoint(CXPoint* point)
{
	int centerX = (right_guess - left_guess) / 2 + left_guess;
	int centerY = (bottom_guess - top_guess) / 2 + top_guess;
	point->x = centerX;
	point->y = centerY;
}

// Closes the bank: with `enabled_guess` prints string 0x2F6F naming the banker, forgets the banker,
// hides.
// FUNCTION: TITANIUM 0x004DC160
void Owner_guess::CloseBank_guess(char enabled_guess)
{
	char output_guess[256];
	if (g_message_guess != 0) {
		if (enabled_guess != 0) {
			Format_guess(output_guess, 0x2f6f,
				g_formatManager_guess->Lookup_guess(g_message_guess + 0x120),
				0, 0, 0, 0, 0, 0, 0, 0);
			pEverQuest->dsp_chat(output_guess);
		}
		g_message_guess = 0;
	}
	Update_guess(0, 1);
}

// Show(show, bring to top) override: showing passes through; hiding goes through the close at 0x4DC160.
// FUNCTION: TITANIUM 0x004DC1E3
void Owner_guess::Show_guess(char enabled_guess, int value_guess)
{
	if (enabled_guess == 1)
		Update_guess(1, value_guess);
	else
		CloseBank_guess(1);
}

// Probably the tail of leaving the bank: 0x44A617(3, 0) (names.tsv: SetMusicSelection, low), flag
// 0x923D94 = 1, then 0x4A1350 (names.tsv: CEverQuest::SavePC, low).
// FUNCTION: TITANIUM 0x004DC201
unsigned char __cdecl Initialize_guess()
{
	g_eventRouter_guess->CCursorAttachmentView_guess(3, 0);
	EQ_GLOBAL(int, 0x00923D94) = 1;
	g_formatManager_guess->SavePC_guess(0, 1, 0x19);
	EQ_GLOBAL(int, 0x009248D4) = 0;
	return 1;
}

// Opens the bank for banker `message_guess`: greeting string 0x5B9 with the banker's name; stops the two
// modes flagged at 0x9858C7/0x9858C8 (probably auto attack and auto fire) with their strings; shows.
// FUNCTION: TITANIUM 0x004DC05E
void Owner_guess::OpenBank_guess(char* message_guess)
{
	char output_guess[512];
	g_message_guess = message_guess;
	Format_guess(output_guess, 0x5b9,
		g_formatManager_guess->Lookup_guess(message_guess + 0x120),
		0, 0, 0, 0, 0, 0, 0, 0);
	pEverQuest->dsp_chat(output_guess);
	if (EQ_GLOBAL(char, 0x009858C7) != 0) {
		g_modal_guess.SetAutoAttack_guess(0);
		g_formatManager_guess->Display_guess(
			g_resourceManager_guess->GetString_guess(0x5ba, 0, 0xd, 1));
	}
	if (EQ_GLOBAL(char, 0x009858C8) != 0) {
		g_modal_guess.SetAutoFire_guess(0);
		g_formatManager_guess->Display_guess(
			g_resourceManager_guess->GetString_guess(0x117, 0, 0xd, 1));
	}
	g_eventRouter_guess->CCursorAttachmentView_guess(3, 1);
	g_queueRoot_guess->queue_0000_guess.Process_guess(0);
	Update_guess(1, 1);
}

// Show hook. Shown: opens the inventory window (0x850C34), remembering whether it was already open,
// brings itself to the top and pops context tip 18. Hidden: closes the quantity window (0x850C3C) if a
// coin pick is pending (+0x15C), closes the inventory unless it was open before, and calls 0x4FAABA on
// 0x850CBC.
// FUNCTION: TITANIUM 0x004DC235
void State_guess::OnShow_guess()
{
	if (flag_005c_guess != 0) {
		flag_0164_guess = pinstCInventoryWnd_guess->IsVisible_guess();
		if (flag_0164_guess == 0)
			pinstCInventoryWnd_guess->Activate();
		pinstCXWndManager_guess->BringWndToTop(this, 1);
		if (pinstCTipWndCONTEXT_guess != 0)
			pinstCTipWndCONTEXT_guess->selectTip_guess(0x12, 0);
	} else {
		if (value_015c_guess != -1 && pinstCQuantityWnd_guess->IsVisible_guess() != 0)
			pinstCQuantityWnd_guess->Deactivate();
		if (flag_0164_guess == 0)
			pinstCInventoryWnd_guess->Deactivate();
		pinstCContainerMgr_guess->Flush_guess();
	}
	Tail_guess();
}

// OnProcessFrame: every 500 ms, closes the bank (vtable slot 0 with 0, 1, probably) once the banker is
// more than 20 units away (CDisplay::PlayerDistance).
// FUNCTION: TITANIUM 0x004DC46C
void State_guess::OnProcessFrame_guess()
{
	if (flag_005c_guess != 0) {
		unsigned int* timer_guess = &timer_0160_guess;
		unsigned int tick_guess = g_tickSource_guess->tick_0148_guess;
		if (tick_guess >= *timer_guess) {
			*timer_guess = tick_guess + 500;
			if (g_message_guess != 0 &&
				g_tickSource_guess->PlayerDistance_guess(g_message_guess,
					EQ_GLOBAL(void*, 0x00905CE4), 1.0f) > 20.0f) {
				Notify_guess(0, 1);
			}
		}
	}
	UpdateBase_guess();
}

struct TextValue_guess {
	int field_0000_guess;
	int field_0004_guess;
	int field_0008_guess;
	int field_000c_guess;

	// EXTERNAL: TITANIUM 0x004D9160 ??4TextValue_guess@@QAE?AU0@ABU0@@Z
	TextValue_guess operator=(const TextValue_guess& value_guess);
};

#include "titanium/layouts/core.h"

struct Entry_guess {
	char padding_0000_guess[0x62];
	unsigned char enabled_0062_guess;
	char padding_0063_guess[0xdd];
	RecordLink_guess* link_0140_guess;

	// EXTERNAL: TITANIUM 0x0059D960 Entry_guess::GetText_guess
	TextValue_guess GetText_guess();
	// EXTERNAL: TITANIUM 0x0059FEC0 Entry_guess::IsReady_guess
	unsigned char IsReady_guess();
	// EXTERNAL: TITANIUM 0x005A02F0 Entry_guess::ApplyPoint_guess
	void ApplyPoint_guess(CXPoint* point_guess);
};

struct TextSink_guess {
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
	virtual TextValue_guess* Slot57_guess(CXPoint* out_guess);
	virtual void Slot58_guess();
	virtual void Slot59_guess();
	virtual void Slot60_guess();
	virtual void Slot61_guess();
	virtual void Slot62_guess();
	virtual void Slot63_guess(const CXStr& text_guess);
};

struct Window_guess {
	char padding_0000_guess[0x62];
	unsigned char enabled_0062_guess;
	char padding_0063_guess[0xf9];
	int selectedMoneyButton_015c_guess;
	unsigned int timer_0160_guess;
	char padding_0164_guess[4];
	TextSink_guess* text_0168_guess;
	TextSink_guess* text_016c_guess;
	TextSink_guess* text_0170_guess;
	TextSink_guess* text_0174_guess;
	TextSink_guess* text_0178_guess;
	TextSink_guess* text_017c_guess;
	Entry_guess* entries_0180_guess[0x10];
	Entry_guess* entries_01c0_guess[0x6];
	int count_01d8_guess;

	int DrawSlotTooltips_guess();
	void UpdateMoneyLabels_guess();
	bool HandleMessage_guess();
	void Process_guess(char flag_guess);
	void OnMoneyClick_guess(int index_guess, int value_guess);
};

// While the keyboard flags have bit 0x4 or 0x8 set, draws every occupied bank slot's tooltip beside it
// (CXWnd::DrawTooltipAtPoint): the eight-slot page that holds the first visible slot, then the two shared
// slots.
// FUNCTION: TITANIUM 0x004DC2D4
int Window_guess::DrawSlotTooltips_guess()
{
	if ((pinstCXWndManager_guess->GetKeyboardFlags() & 0x0c) != 0 &&
		enabled_0062_guess != 0) {
		Entry_guess** cursor_guess;
		int index_guess = 0;
		int start_guess = 0;
		int end_guess = count_01d8_guess;
		TextValue_guess value_guess;
		CXPoint point_guess;

		point_guess.x = 0;
		point_guess.y = 0;
		value_guess.field_000c_guess = 0;
		value_guess.field_0008_guess = 0;
		value_guess.field_0004_guess = 0;
		value_guess.field_0000_guess = 0;

		if (end_guess > 0) {
			cursor_guess = entries_0180_guess;
			do {
				if (*cursor_guess != 0 && (*cursor_guess)->enabled_0062_guess != 0) {
					start_guess = index_guess / 8 * 8;
					end_guess = start_guess / 8 * 8 + 8;
					break;
				}
				++index_guess;
				++cursor_guess;
			} while (index_guess < end_guess);
		}

		index_guess = start_guess;
		if (index_guess < end_guess) {
			cursor_guess = entries_0180_guess + index_guess;
			do {
				if (*cursor_guess != 0 && (*cursor_guess)->IsReady_guess() != 0) {
					int* records_guess = (*cursor_guess)->link_0140_guess->records_guess;
					int record_guess = records_guess != 0 ? *records_guess : 0;
					if (record_guess != 0) {
						value_guess = (*cursor_guess)->GetText_guess();
						int row_guess = index_guess / 4;
						int offset_guess;
						if (row_guess < 2)
							offset_guess = row_guess * 0x14;
						else
							offset_guess = row_guess * 0x14 - 0x1e;
						point_guess.x = value_guess.field_0008_guess - 5;
						point_guess.y = value_guess.field_0004_guess + 2 + offset_guess;
						(*cursor_guess)->ApplyPoint_guess(&point_guess);
					}
				}
				++index_guess;
				++cursor_guess;
			} while (index_guess < end_guess);
		}

		Entry_guess** other_guess;
		for (index_guess = 0, other_guess = entries_01c0_guess;
			index_guess < 0x28;
			index_guess += 0x14, ++other_guess) {
			if (*other_guess != 0 && (*other_guess)->IsReady_guess() != 0) {
				int* records_guess = (*other_guess)->link_0140_guess->records_guess;
				int record_guess = records_guess != 0 ? *records_guess : 0;
				if (record_guess != 0) {
					value_guess = (*other_guess)->GetText_guess();
					int offset_guess = index_guess;
					if (index_guess >= 0x28)
						offset_guess = index_guess - 0x1e;
					point_guess.x = value_guess.field_0008_guess - 5;
					point_guess.y = value_guess.field_0004_guess + 2 + offset_guess;
					(*other_guess)->ApplyPoint_guess(&point_guess);
				}
			}
		}
	}
	return 0;
}


struct ValueRoot_guess {
	char padding_0000_guess[8];
	VBTable* offset_holder_guess;
};

struct ValueBlock_guess {
	char padding_0000_guess[0x134];
	int value_134_guess;
	int value_138_guess;
	int value_13C_guess;
	int value_140_guess;
	int value_144_guess;
	int value_148_guess;
	int value_14C_guess;
	int value_150_guess;
};

struct Settings_guess {
	char padding_0000_guess[0x11];
	unsigned char mode_0011_guess;
};

#define g_settings_guess EQ_GLOBAL(Settings_guess*, 0x00905D24)

struct ValueSlots_guess {
	char padding_0000_guess[0x11e4];
	int cursorPlatinum_11e4_guess;
	int cursorGold_11e8_guess;
	int cursorSilver_11ec_guess;
	int cursorCopper_11f0_guess;
};

struct EQ_CharacterProfileView_guess {
	// EXTERNAL: TITANIUM 0x005EC220 EQ_CharacterProfileView_guess::GetCharInfo2
	ValueSlots_guess* GetCharInfo2();
};

struct ValueSpan_guess {
	char padding_0000_guess[0xc];
	EQ_CharacterProfileView_guess list_000c_guess;
};

#define g_valueRoot_guess EQ_GLOBAL(ValueRoot_guess*, 0x00905D00)

// Coins by slot: 0-3 bank platinum, gold, silver, copper (pCharData view +0x144-0x150); 4-7 the block at
// +0x134-0x140, whose +0x134 is the shared bank's platinum.
// FUNCTION: TITANIUM 0x004DC4D7
int __stdcall GetBankCoins_guess(int index_guess)
{
	if (index_guess < 4) {
		switch (index_guess) {
		case 0: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_144_guess;
		}
		case 1: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_148_guess;
		}
		case 2: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_14C_guess;
		}
		case 3: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_150_guess;
		}
		}
	} else {
		switch (index_guess - 4) {
		case 0: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_134_guess;
		}
		case 1: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_138_guess;
		}
		case 2: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_13C_guess;
		}
		case 3: {
			ValueBlock_guess* block_guess = reinterpret_cast<ValueBlock_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			return block_guess->value_140_guess;
		}
		}
	}
	return 0;
}

// Writes the four bank coin counts and the shared platinum into the BW_Money/SharedMoney labels.
// FUNCTION: TITANIUM 0x004DC5AA
void Window_guess::UpdateMoneyLabels_guess()
{
	char buffer_guess[256];
	if (text_0168_guess != 0) {
		sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C),
			*reinterpret_cast<int*>(reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset + 0x144));
		CXStr text_guess(buffer_guess);
		text_0168_guess->Slot63_guess(text_guess);
	}
	if (text_016c_guess != 0) {
		sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C),
			*reinterpret_cast<int*>(reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset + 0x148));
		CXStr text_guess(buffer_guess);
		text_016c_guess->Slot63_guess(text_guess);
	}
	if (text_0170_guess != 0) {
		sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C),
			*reinterpret_cast<int*>(reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset + 0x14C));
		CXStr text_guess(buffer_guess);
		text_0170_guess->Slot63_guess(text_guess);
	}
	if (text_0174_guess != 0) {
		sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C),
			*reinterpret_cast<int*>(reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset + 0x150));
		CXStr text_guess(buffer_guess);
		text_0174_guess->Slot63_guess(text_guess);
	}
	if (text_0178_guess != 0) {
		sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C),
			*reinterpret_cast<int*>(reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset + 0x134));
		CXStr text_guess(buffer_guess);
		text_0178_guess->Slot63_guess(text_guess);
	}
}

// Click on coin slot `index_guess`. With coins on the cursor (0x905D24 +0x11 = coin type) drops them
// there (0x495F81: from 0 = cursor to 2 = bank, 4 = shared bank). Otherwise `value_guess` < 0 opens the
// quantity window at the label's centre, and a known amount is picked up onto the cursor.
// FUNCTION: TITANIUM 0x004DCD85
// @early-stop: budget, structural ndiff=207
void Window_guess::OnMoneyClick_guess(int index_guess, int value_guess)
{
	int first_guess;
	int second_guess;
	if (g_settings_guess->mode_0011_guess != 0) {
		first_guess = 0;
		second_guess = 2;
		if (index_guess > 3)
			second_guess = 4;
		int mode_guess = g_settings_guess->mode_0011_guess;
		value_guess = 0;
		switch (mode_guess) {
		case 1: {
			ValueSpan_guess* span_guess = reinterpret_cast<ValueSpan_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			value_guess = span_guess->list_000c_guess.GetCharInfo2()->cursorPlatinum_11e4_guess;
			break;
		}
		case 2: {
			ValueSpan_guess* span_guess = reinterpret_cast<ValueSpan_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			value_guess = span_guess->list_000c_guess.GetCharInfo2()->cursorGold_11e8_guess;
			break;
		}
		case 3: {
			ValueSpan_guess* span_guess = reinterpret_cast<ValueSpan_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			value_guess = span_guess->list_000c_guess.GetCharInfo2()->cursorSilver_11ec_guess;
			break;
		}
		case 4: {
			ValueSpan_guess* span_guess = reinterpret_cast<ValueSpan_guess*>(
				reinterpret_cast<char*>(g_valueRoot_guess) +
				g_valueRoot_guess->offset_holder_guess->vbase_offset);
			value_guess = span_guess->list_000c_guess.GetCharInfo2()->cursorCopper_11f0_guess;
			break;
		}
		}
		g_formatManager_guess->MoveMoney_guess(first_guess, second_guess, mode_guess - 1,
			index_guess % 4, value_guess, 0);
	} else {
		first_guess = 2;
		if (index_guess > 3)
			first_guess = 4;
		int slot_guess = index_guess % 4;
		second_guess = 0;
		if (value_guess < 0) {
			TextValue_guess rect_guess;
			rect_guess.field_000c_guess = 0;
			rect_guess.field_0008_guess = 0;
			rect_guess.field_0004_guess = 0;
			rect_guess.field_0000_guess = 0;
			selectedMoneyButton_015c_guess = index_guess;
			int current_guess = GetBankCoins_guess(index_guess);
			CXPoint point_guess;
			int x_guess = 0;
			int y_guess = 0;
			TextSink_guess* sink_guess = (&text_0168_guess)[index_guess];
			if (sink_guess != 0) {
				CXPoint out_guess;
				TextValue_guess* source_guess = sink_guess->Slot57_guess(&out_guess);
				rect_guess = *source_guess;
				reinterpret_cast<Rect_guess*>(&rect_guess)->CenterPoint(&point_guess);
				x_guess = point_guess.x;
				y_guess = point_guess.y;
			}
			pinstCQuantityWnd_guess->Function_0054d976_guess(this, current_guess, current_guess, x_guess, y_guess, 1);
			return;
		}
		g_formatManager_guess->MoveMoney_guess(first_guess, second_guess, slot_guess, slot_guess,
			value_guess, 0);
	}
	UpdateMoneyLabels_guess();
}

struct ClientObject_guess {
	char unknown_0000_guess[0x1D8];
	unsigned int value_01D8_guess;

	unsigned int GetNumBankSlots();
};

// Bank window: returns the number of bank slots the account has (+0x1D8). The slot manager uses it to
// lock bank slots past that count (0x005190E7) and to refuse moves into them.
// FUNCTION: TITANIUM 0x004DC831
unsigned int ClientObject_guess::GetNumBankSlots()
{
	return value_01D8_guess;
}

// With a banker set: clears the pending coin pick, shows the banker's name and updates the coin labels;
// returns whether there was a banker.
// FUNCTION: TITANIUM 0x004DCCF3
bool Window_guess::HandleMessage_guess()
{
	bool result_guess = false;
	if (g_message_guess != 0) {
		selectedMoneyButton_015c_guess |= -1;
		timer_0160_guess = 0;
		if (text_017c_guess != 0) {
			CXStr text_guess(g_formatManager_guess->Lookup_guess(g_message_guess + 0x120));
			text_017c_guess->Slot63_guess(text_guess);
		}
		UpdateMoneyLabels_guess();
		result_guess = true;
	}
	return result_guess;
}

// One object type for the slot entries, the owner at [info+0x88] and the list items: same member calls.
struct Node_guess {
	char padding_0000_guess[0x48];
	int value_0048_guess;

	// EXTERNAL: TITANIUM 0x005E0A30 Node_guess::Ready_guess
	char Ready_guess(int value_guess);
	// EXTERNAL: TITANIUM 0x005EC760 Node_guess::IsStackable_guess
	char IsStackable_guess();
	// EXTERNAL: TITANIUM 0x005ECCC0 Node_guess::GetItemClass_guess
	int GetItemClass_guess();
	// EXTERNAL: TITANIUM 0x005E0F30 Node_guess::GetItemId_guess
	int GetItemId_guess();
	// EXTERNAL: TITANIUM 0x005ECC30 Node_guess::Count_guess
	int Count_guess();
	// EXTERNAL: TITANIUM 0x005EC630 Node_guess::GetChild_guess
	Node_guess* GetChild_guess(int index_guess);
	// EXTERNAL: TITANIUM 0x005ECD50 Node_guess::GetLimit_guess
	int GetLimit_guess();
};

struct CharInfo_guess {
	char padding_0000_guess[0x88];
	Node_guess* node_0088_guess;
	char padding_008c_guess[0x11e4 - 0x8c];
	int cursorPlatinum_11e4_guess;
	int cursorGold_11e8_guess;
	int cursorSilver_11ec_guess;
	int cursorCopper_11f0_guess;
};

struct CharProfile_guess {
	void* list_guess;
	int key_guess;

	// EXTERNAL: TITANIUM 0x005EC220 CharProfile_guess::GetCharInfo2
	CharInfo_guess* GetCharInfo2();
};

struct PcCharacter_guess {
	void* vftable_guess;
	CharProfile_guess profile_guess;
};

struct PcPrefix_guess {
	virtual void slot00_guess() = 0;
	int field04_guess;
};

// pCharData (0x00905D00): the profile sits in the virtual base, reached through the vbptr at +8.
struct PcView_guess : PcPrefix_guess, virtual PcCharacter_guess {
	char padding_000c_guess[0xcf0 - 0x0c];
	Node_guess* slots_0cf0_guess[0x10];
};

#define g_pcView_guess EQ_GLOBAL(PcView_guess*, 0x00905D00)

struct StateFlags_guess {
	char padding_0000_guess[0x10];
	unsigned char flag_0010_guess;
	unsigned char flag_0011_guess;
};

#define g_stateFlags_guess EQ_GLOBAL(StateFlags_guess*, 0x00905D24)


struct CCursorAttachmentView_guess {
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
	virtual void Slot48_guess(int first_guess, int second_guess);
};


struct EverQuest_guess {
	// EXTERNAL: TITANIUM 0x00495F81 EverQuest_guess::Notify_guess
	void Notify_guess(int a_guess, int b_guess, int c_guess, int d_guess, int e_guess, int f_guess);
};

#define g_everQuest_guess EQ_GLOBAL(EverQuest_guess*, 0x00988DF0)

// AutoButton: banks what is on the cursor. Coins go to the bank, highest denomination present first. An item
// 0x5E0A30(1) rejects (probably one that may not be banked) gets string 0x182F. A stackable item first tops
// up matching stacks in the bank and its bags, then the loop runs again unstacked: first empty bank slot,
// else the first empty bag slot (a bag is not put into a bag); with no room the cursor attachment is hidden
// and string 0xD9D printed.
// FUNCTION: TITANIUM 0x004DCF17
// @early-stop: budget, structural ndiff=333
void Window_guess::Process_guess(char flag_guess)
{
	Node_guess* node_guess;
	int index_guess;
	unsigned int slot_index_guess;
	int message_guess;
	while (true) {
		node_guess = g_pcView_guess->profile_guess.GetCharInfo2()->node_0088_guess;
		if (node_guess == 0) {
			if (g_stateFlags_guess->flag_0011_guess == 0)
				return;
			int level_guess;
			int amount_guess;
			if (g_pcView_guess->profile_guess.GetCharInfo2()->cursorCopper_11f0_guess > 0) {
				level_guess = 3;
				amount_guess = g_pcView_guess->profile_guess.GetCharInfo2()->cursorCopper_11f0_guess;
			} else if (g_pcView_guess->profile_guess.GetCharInfo2()->cursorSilver_11ec_guess > 0) {
				level_guess = 2;
				amount_guess = g_pcView_guess->profile_guess.GetCharInfo2()->cursorSilver_11ec_guess;
			} else if (g_pcView_guess->profile_guess.GetCharInfo2()->cursorGold_11e8_guess > 0) {
				level_guess = 1;
				amount_guess = g_pcView_guess->profile_guess.GetCharInfo2()->cursorGold_11e8_guess;
			} else {
				if (g_pcView_guess->profile_guess.GetCharInfo2()->cursorPlatinum_11e4_guess <= 0)
					return;
				level_guess = 0;
				amount_guess = g_pcView_guess->profile_guess.GetCharInfo2()->cursorPlatinum_11e4_guess;
			}
			if (amount_guess < 1)
				return;
			g_everQuest_guess->Notify_guess(0, 2, level_guess, level_guess, amount_guess, 0);
			UpdateMoneyLabels_guess();
			return;
		}
		if (node_guess->Ready_guess(1) != 0) {
			message_guess = 0x182f;
			break;
		}
		if (node_guess->IsStackable_guess() == 0 || flag_guess == 0) {
			slot_index_guess = 0;
			if (0 < count_01d8_guess) {
				do {
					Node_guess** slots_guess = g_pcView_guess->slots_0cf0_guess;
					if (slot_index_guess >= 0x10)
						__debugbreak();
					if (slots_guess[slot_index_guess] == 0 &&
						pinstCInvSlotMgr_guess->MoveItem(0x1e, slot_index_guess + 2000, 0, 0) != 0) {
						g_stateFlags_guess->flag_0010_guess = 0;
						return;
					}
					++slot_index_guess;
				} while (static_cast<int>(slot_index_guess) < count_01d8_guess);
			}
			index_guess = 0;
			if (0 < count_01d8_guess) {
				int base_guess = 0x7ef;
				do {
					Node_guess** slots_guess = g_pcView_guess->slots_0cf0_guess;
					if (base_guess >= 0x88f)
						__debugbreak();
					Node_guess* slot_guess = slots_guess[index_guess];
					if (slot_guess != 0 && slot_guess->GetItemClass_guess() == 1 && node_guess->GetItemClass_guess() != 1) {
						int child_guess = 0;
						if (slot_guess->Count_guess() > 0) {
							do {
								if (slot_guess->GetChild_guess(child_guess) == 0 &&
									pinstCInvSlotMgr_guess->MoveItem(0x1e, base_guess + child_guess, 0, 0) != 0) {
									g_stateFlags_guess->flag_0010_guess = 0;
									return;
								}
								++child_guess;
							} while (child_guess < slot_guess->Count_guess());
						}
					}
					++index_guess;
					base_guess += 10;
				} while (index_guess < count_01d8_guess);
			}
			pinstCCursorAttachment_guess->Show(0, 1);
			message_guess = 0xd9d;
			break;
		}
		index_guess = 0;
		if (0 < count_01d8_guess) {
			do {
				Node_guess** slots_guess = g_pcView_guess->slots_0cf0_guess;
				if (static_cast<unsigned int>(index_guess) >= 0x10)
					__debugbreak();
				Node_guess* slot_guess = slots_guess[index_guess];
				if (slot_guess != 0 && slot_guess->GetItemId_guess() == node_guess->GetItemId_guess()) {
					pinstCInvSlotMgr_guess->MoveItem(0x1e, index_guess + 2000, 0, 1);
					node_guess = g_pcView_guess->profile_guess.GetCharInfo2()->node_0088_guess;
					if (node_guess == 0) {
						g_stateFlags_guess->flag_0010_guess = 0;
						break;
					}
				}
				++index_guess;
			} while (index_guess < count_01d8_guess);
		}
		if (node_guess == 0)
			return;
		index_guess = 0;
		if (0 < count_01d8_guess) {
			int base_guess = 0x7ef;
			do {
				Node_guess** slots_guess = g_pcView_guess->slots_0cf0_guess;
				if (base_guess >= 0x88f)
					__debugbreak();
				Node_guess* slot_guess = slots_guess[index_guess];
				if (slot_guess != 0 && slot_guess->GetItemClass_guess() == 1) {
					int child_guess = 0;
					if (slot_guess->Count_guess() > 0) {
						do {
							Node_guess* child_ptr_guess = slot_guess->GetChild_guess(child_guess);
							if (child_ptr_guess != 0) {
								if (slot_guess->GetChild_guess(child_guess)->GetItemId_guess() == node_guess->GetItemId_guess()) {
									int child_value_guess = slot_guess->GetChild_guess(child_guess)->value_0048_guess;
									int child_limit_guess = slot_guess->GetChild_guess(child_guess)->GetLimit_guess();
									if (child_value_guess < child_limit_guess) {
										pinstCInvSlotMgr_guess->MoveItem(0x1e, base_guess + child_guess, 0, 1);
										node_guess = g_pcView_guess->profile_guess.GetCharInfo2()->node_0088_guess;
									}
								}
								if (node_guess == 0) {
									g_stateFlags_guess->flag_0010_guess = 0;
									break;
								}
							}
							++child_guess;
						} while (child_guess < slot_guess->Count_guess());
					}
					if (node_guess == 0) {
						g_stateFlags_guess->flag_0010_guess = 0;
						break;
					}
				}
				++index_guess;
				base_guess += 10;
			} while (index_guess < count_01d8_guess);
		}
		if (node_guess == 0)
			return;
		flag_guess = 0;
	}
	g_formatManager_guess->Display_guess(
		g_resourceManager_guess->GetString_guess(message_guess, 0, 0xf, 1));
}

struct SidlPiece_guess {
	char pad_0000_guess[0x60];
	unsigned int style_0060_guess;
};

struct BankSidlBase_guess {
	// EXTERNAL: TITANIUM 0x005A3100 ??1BankSidlBase_guess@@UAE@XZ
	virtual ~BankSidlBase_guess();
	char pad_0004_guess[0x60];
	unsigned int windowStyle_0064_guess;    // 0x064 (CXWnd::WindowStyle)
	char pad_0068_guess[0xbc];
	SidlPiece_guess* sidlPiece_0124_guess;  // 0x124 (CSidlScreenWnd::SidlPiece)
	char pad_0128_guess[0x30];
	// EXTERNAL: TITANIUM 0x005A3900 ??0BankSidlBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@@Z
	BankSidlBase_guess(CXWnd* parent, const CXStr& screen);
	// EXTERNAL: TITANIUM 0x0059DB90 BankSidlBase_guess::FUN_0059db90_guess
	void FUN_0059db90_guess(int value);
};

// EXTERNAL: TITANIUM 0x0064FD68 ??_7CBankWnd_guess@@6B@
struct CBankWnd_guess : BankSidlBase_guess {
	unsigned int field_0158_guess;          // 0x158 (set before CreateChildrenFromSidl)
	int field_015c_guess;                   // 0x15C
	int field_0160_guess;                   // 0x160
	char pad_0164_guess[4];
	CXWnd* money_0168_guess[5];             // 0x168 BW_Money%d, then shared money
	CXWnd* banker_017c_guess;               // 0x17C BW_BankerName
	CXWnd* bankSlot_0180_guess[16];         // 0x180 BW_BankSlot%d
	CXWnd* sharedBankSlot_01c0_guess[2];    // 0x1C0 BW_SharedBankSlot%d
	CXWnd* done_01c8_guess;                 // 0x1C8 DoneButton
	CXWnd* change_01cc_guess;               // 0x1CC ChangeButton
	CXWnd* auto_01d0_guess;                 // 0x1D0 AutoButton (big bank only)
	CXWnd* altStorage_01d4_guess;           // 0x1D4 AltStorageButton
	int count_01d8_guess;                   // 0x1D8 16 for big bank, 8 otherwise

	CBankWnd_guess(CXWnd* parent, CXStr screen);
};

// Bank window constructor (BankWnd or BigBankWnd): finds Done, Change, AltStorage (and Auto on the big
// bank), the four coin labels and the shared coin label, the banker name, the 8 or 16 bank slots and the
// two shared bank slots.
// FUNCTION: TITANIUM 0x004DC838
// @early-stop: budget, structural ndiff=68
CBankWnd_guess::CBankWnd_guess(CXWnd* parent, CXStr screen)
	: BankSidlBase_guess(parent, screen) {
	// The screen name picks the layout: BIGB_ children and 16 slots, else BW_ and 8.
	bool big_guess = EQ_METHOD(1, int, 0x00572860, (CXStr, const char*), &screen)("BigBankWnd") != 0;
	char buffer_guess[256];
	int i_guess;
	CXWnd** slot_guess;   // walks money_0168 (EDI in the original)
	count_01d8_guess = big_guess ? 16 : 8;
	for (i_guess = 0; i_guess < count_01d8_guess; ++i_guess) {
		bankSlot_0180_guess[i_guess] = 0;
	}
	slot_guess = money_0168_guess;
	*slot_guess++ = 0;
	*slot_guess++ = 0;
	*slot_guess++ = 0;
	*slot_guess++ = 0;
	*slot_guess++ = 0;
	banker_017c_guess = 0;
	done_01c8_guess = 0;
	change_01cc_guess = 0;
	auto_01d0_guess = 0;
	altStorage_01d4_guess = 0;
	if (sidlPiece_0124_guess != 0) {
		windowStyle_0064_guess |= sidlPiece_0124_guess->style_0060_guess | 0x10000;
		field_0158_guess = 0x12;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		done_01c8_guess = ((CSidlScreenWnd*)this)->GetChildItem("DoneButton");
		change_01cc_guess = ((CSidlScreenWnd*)this)->GetChildItem("ChangeButton");
		altStorage_01d4_guess = ((CSidlScreenWnd*)this)->GetChildItem("AltStorageButton");
		if (big_guess) {
			auto_01d0_guess = ((CSidlScreenWnd*)this)->GetChildItem("AutoButton");
		}
		for (i_guess = 0, slot_guess = money_0168_guess; i_guess < 4; ++i_guess, ++slot_guess) {
			sprintf(buffer_guess, big_guess ? "BIGB_Money%d" : "BW_Money%d", i_guess);
			*slot_guess = ((CSidlScreenWnd*)this)->GetChildItem(buffer_guess);
		}
		sprintf(buffer_guess, big_guess ? "BIGB_SharedMoney%d" : "BW_SharedMoney%d", 0);
		money_0168_guess[4] = ((CSidlScreenWnd*)this)->GetChildItem(buffer_guess);
		if (big_guess) {
			banker_017c_guess = ((CSidlScreenWnd*)this)->GetChildItem(CXStr("BIGB_BankerName"));
		} else {
			banker_017c_guess = ((CSidlScreenWnd*)this)->GetChildItem(CXStr("BW_BankerName"));
		}
		for (i_guess = 0; i_guess < count_01d8_guess; ++i_guess) {
			sprintf(buffer_guess, big_guess ? "BIGB_BankSlot%d" : "BW_BankSlot%d", i_guess);
			bankSlot_0180_guess[i_guess] = ((CSidlScreenWnd*)this)->GetChildItem(buffer_guess);
		}
		for (i_guess = 0, slot_guess = sharedBankSlot_01c0_guess; i_guess < 2; ++i_guess, ++slot_guess) {
			sprintf(buffer_guess, big_guess ? "BIGB_SharedBankSlot%d" : "BW_SharedBankSlot%d", i_guess);
			*slot_guess = ((CSidlScreenWnd*)this)->GetChildItem(buffer_guess);
		}
		FUN_0059db90_guess(0x14);
		field_015c_guess = -1;
		field_0160_guess = 0;
	}
}

