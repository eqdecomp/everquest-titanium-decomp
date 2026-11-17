// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 229: a hint from compare/tumap.py.
// The title window, CTitleWnd ("TitleWnd"): lists the prefixes and suffixes the server offers
// (OP_RequestTitles), previews the name with them, and sets or clears them with OP_SetTitle. Titles live in
// a hash (TitleTable_guess, built with 200, so 211 buckets; 0x44-byte TitleEntry_guess: id, prefix,
// suffix). The player's prefix is at spawn +0x2A4, the suffix at +0x2C4.
#include "titanium/types.h"
#include "titanium/opcodes.h"
#include <string.h>
#include "titanium/wnd/CTipWnd.h"

#define g_connection_guess EQ_GLOBAL(int, 0x00905CA0)
#define g_nameTable_guess EQ_GLOBAL(HashTable_guess, 0x00992918)
#define g_controlState_guess EQ_GLOBAL(char*, 0x00905CE4)
#define g_emptyString_guess EQ_ARRAY(char, 0x0063F53F)

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory);

// EXTERNAL: TITANIUM 0x0060D682 _free
void __cdecl _free(void* memory);

// EXTERNAL: TITANIUM 0x0042429E NextPrimeCandidate_guess
int __cdecl NextPrimeCandidate_guess(int hint);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size);

// EXTERNAL: TITANIUM 0x005738B0 FormatString_guess
void __cdecl FormatString_guess(void* out, const char* format, ...);

// EXTERNAL: TITANIUM 0x0060D5EB sprintf
int __cdecl sprintf(char* destination_guess, const char* format_guess, ...);

struct TextPair_guess
{
	int value;
	char first[32];
	char second[32];
	TextPair_guess* Copy(TextPair_guess* source);
};

struct TitleEntry_guess
{
	int titleId_0000_guess;
	char first[32];
	char second[32];
	TitleEntry_guess* ResetEntry_guess();
};

struct MessageSender_guess
{
	void SendSetTitle_guess(int* value, int messageValue);
};

struct HashNode_guess
{
	unsigned int key_0000_guess;
	char name_guess[32]; // 0x04
	char title_guess[32]; // 0x24
	unsigned int key;
	HashNode_guess* next;
};

struct HashTable_guess
{
	HashNode_guess** buckets;
	int bucketCount;
	int nodeCount;
	int used;
	HashTable_guess(int hint);
	// EXTERNAL: TITANIUM 0x004466FA HashTable_guess::First_guess
	HashNode_guess* First_guess();
	HashNode_guess* Find_guess(unsigned int key);
	HashNode_guess* FindNext_guess(HashNode_guess* node);
	HashNode_guess* Next_guess(HashNode_guess* node);
	void Rehash_guess(int hint);
	HashNode_guess* FindKey_guess(unsigned int key);
	// EXTERNAL: TITANIUM 0x00564F92 HashTable_guess::RequestTitles_guess
	void RequestTitles_guess();
};

struct DerivedTable_guess : HashTable_guess
{
	DerivedTable_guess();
};

struct CleanupNode_guess : TitleEntry_guess
{
	unsigned int key; // 0x44
	CleanupNode_guess* next; // 0x48
	CleanupNode_guess() { ResetEntry_guess(); }
};

struct TitleTable_guess
{
	CleanupNode_guess** buckets;
	int bucketCount;
	int nodeCount;
	int chainCount;
	void Clear_guess();
	void ClearTitles_guess();
	void Free_guess();
	void Handle_OP_SendTitleList_guess(char* data_guess);
	void AddTitle_guess(TitleEntry_guess* entry_guess, int value_guess);
};

struct CTitleWndShowView_guess
{
	char reserved[0x5c];
	char active;
	void OnShow_guess();
	// EXTERNAL: TITANIUM 0x005A1880 CTitleWndShowView_guess::OnShow
	void OnShow();
};

struct ControlFlag_guess : CXWnd
{
	unsigned char reserved[0x154 - 0x11c];
	int value154_guess; // 0x154
	unsigned char reserved158_guess[0x14];
	int value16c_guess; // 0x16c
	// EXTERNAL: TITANIUM 0x00597BE0 ControlFlag_guess::GetCurSel
	int GetCurSel();
};

struct ControlWidget_guess
{
	char reserved[0x5d];
	char active;
};

struct TextTarget_guess
{
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
	virtual void SetWindowText_guess(const CXStr& text_guess); // 0xFC
};

struct ControlSource_guess
{
	char reserved[0x128];
	unsigned char state_guess;
};

struct ListSlots_guess
{
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
	virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess(); virtual void Slot3F_guess();
	virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
	virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
	virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot4A_guess(); virtual void Slot4B_guess();
	virtual void Slot4C_guess(); // 0x130
};

struct CTitleWndView_guess
{
	char reserved[0x5c];
	char active_guess; // 0x5c
	char reserved_b[0x160 - 0x5d];
	int field160_guess; // 0x160
	int field164_guess; // 0x164
	TextTarget_guess* textTarget_guess; // 0x168
	TextTarget_guess* target_guess; // 0x16c
	ControlFlag_guess* firstControl; // 0x170
	ControlFlag_guess* secondControl; // 0x174
	ControlWidget_guess* firstWidget; // 0x178
	ControlWidget_guess* secondWidget; // 0x17c
	ControlWidget_guess* thirdWidget; // 0x180
	ControlWidget_guess* fourthWidget; // 0x184
	ControlSource_guess* source_guess; // 0x188
	char reserved2[0x198 - 0x18c];
	char nameBuf_guess[32]; // 0x198
	char titleBuf_guess[32]; // 0x1b8
	char flag_guess; // 0x1d8
	void Sync_guess();
	void SetSelectedTitle_guess(TextPair_guess* pair_guess, bool useFirst_guess);
	void Populate_guess();
	void OnMessage_guess(void* sender_guess, unsigned int message_guess, void* data_guess);
	// EXTERNAL: TITANIUM 0x005659C1 CTitleWndView_guess::UpdateNamePreview_guess
	void UpdateNamePreview_guess(bool mode_guess);
	char AboutToShow_guess();
};

// EXTERNAL: TITANIUM 0x0063FD9C ??_7CallbackBase_guess@@6B@
struct CallbackBase_guess
{
	// EXTERNAL: TITANIUM 0x005482A0 CallbackBase_guess::Set_guess
	void Set_guess(int value);
	virtual void Slot_guess();
	virtual ~CallbackBase_guess() { Set_guess(-1); }
};

struct CallbackMainBase_guess
{
	virtual void Slot_guess();
	char reserved04_guess[0x154];
	int value158_guess; // 0x158
	// EXTERNAL: TITANIUM 0x005A3900 CallbackMainBase_guess::CallbackMainBase_guess
	CallbackMainBase_guess(CXWnd* parent, const CXStr& screen);
	// EXTERNAL: TITANIUM 0x005A3100 ??1CallbackMainBase_guess@@UAE@XZ
	virtual ~CallbackMainBase_guess();
};

// EXTERNAL: TITANIUM 0x0065EB08 ??_7CTitleWnd_guess@@6BCallbackMainBase_guess@@@
// EXTERNAL: TITANIUM 0x0065EB04 ??_7CTitleWnd_guess@@6BCallbackBase_guess@@@
struct CTitleWnd_guess : CallbackMainBase_guess, CallbackBase_guess
{
	int index;
	float value;
	void* setting_guess[12]; // 0x168
	char nameBuf_guess[32]; // 0x198
	char titleBuf_guess[32]; // 0x1b8
	unsigned char notifyNewTitles_guess; // 0x1d8
	CTitleWnd_guess(CXWnd* parent);
	virtual char AboutToHide_guess();
	~CTitleWnd_guess();
	CTitleWnd_guess* Destroy_guess(unsigned char flags);
};

struct Settings_guess
{
	// EXTERNAL: TITANIUM 0x004AE919 Settings_guess::GetBool_guess
	char GetBool_guess(const char* section, const char* key, int defaultValue, int value);
};

struct CallbackManager_guess
{
	// EXTERNAL: TITANIUM 0x004392DE CallbackManager_guess::SetCameraMode_guess
	void SetCameraMode_guess(int index);
	// EXTERNAL: TITANIUM 0x004426FB CallbackManager_guess::SetupCharacterViewCamera_guess
	void SetupCharacterViewCamera_guess(int value_guess);
};

struct CallbackGlobal_guess
{
	char reserved[0xb5c];
	float value;
	// EXTERNAL: TITANIUM 0x004AE82A CallbackGlobal_guess::Notify_guess
	void Notify_guess(int state_guess, const char* first_guess, const char* second_guess);
};

struct CallbackGlobalBits_guess
{
	char reserved[0xb5c];
	int bits_guess;
};

struct RenderOwner_guess
{
	virtual void Slot00_guess(); virtual void Slot04_guess(); virtual void Slot08_guess(); virtual void Slot0C_guess();
	virtual void Slot10_guess(); virtual void Slot14_guess(float value_guess); virtual void Slot18_guess(float value_guess);
	virtual void Slot1C_guess(); virtual void Slot20_guess(float value_guess);
	char reserved_guess[0x30];
	float value34_guess; // 0x34
};

#define g_slotIndex_guess EQ_GLOBAL(int, 0x00850CCC)
#define g_renderOwner_guess EQ_GLOBAL(RenderOwner_guess*, 0x00925518)
#define g_callbackGlobalBits_guess EQ_GLOBAL(CallbackGlobalBits_guess*, 0x00988DF0)

#define g_callbackTarget_guess EQ_GLOBAL(int, 0x00905D24)
#define g_callbackGlobal_guess EQ_GLOBAL(CallbackGlobal_guess*, 0x00988DF0)
#define g_settings_guess EQ_GLOBAL(Settings_guess*, 0x00988DF0)
#define pinstCTitleWnd_guess EQ_GLOBAL(CTitleWndView_guess*, 0x009928FC)
#define g_activeTarget_guess EQ_GLOBAL(TargetText_guess*, 0x00905CE4)

// Clears a title entry: id 0 and both 32-byte strings (prefix and suffix) zeroed. Used before an entry
// is filled from the title list payload or copied into the table.
// FUNCTION: TITANIUM 0x00564F37
TitleEntry_guess* TitleEntry_guess::ResetEntry_guess()
{
	titleId_0000_guess = 0;
	memset(first, 0, sizeof(first));
	memset(second, 0, sizeof(second));
	return this;
}

// Copies a title entry from `source`: the id, then prefix and suffix (at most 31 characters each).
// Adding a title to the table (0x00565C5D) copies the entry this way.
// FUNCTION: TITANIUM 0x00564F5E
TextPair_guess* TextPair_guess::Copy(TextPair_guess* source)
{
	value = source->value;
	strncpy(first, source->first, 31);
	strncpy(second, source->second, 31);
	return this;
}

// OP_RequestTitles, no payload; the answer arrives in TitleTable_guess::Handle_OP_SendTitleList_guess.
// FUNCTION: TITANIUM 0x00564F92
void __cdecl RequestTitles_guess()
{
	EQSendMessage(&g_connection_guess, OP_RequestTitles, 0, 0, 1);
}

// OP_SetTitle (8 bytes): 0 prefix or 1 suffix, then the title id (0 clears it).
// FUNCTION: TITANIUM 0x00564FAB
void MessageSender_guess::SendSetTitle_guess(int* value, int messageValue)
{
	int payload[2];
	if (value != 0)
		payload[1] = *value;
	else
		payload[1] = 0;
	payload[0] = messageValue;
	EQSendMessage(&g_connection_guess, OP_SetTitle, payload, 8, 1);
}

// Destructor of the title window (vtable 0x65EB08): expires every confirmation dialog its dialog-owner
// part (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd destructor
// (0x005A3100).
// FUNCTION: TITANIUM 0x00564FE6
CTitleWnd_guess::~CTitleWnd_guess()
{
}

// On close: puts the camera back to the mode and zoom saved when the window opened.
// FUNCTION: TITANIUM 0x00565032
char CTitleWnd_guess::AboutToHide_guess()
{
	reinterpret_cast<CallbackManager_guess*>(g_callbackTarget_guess)->SetCameraMode_guess(index);
	g_callbackGlobal_guess->value = value;
	return 1;
}

// Title window: the prefix being previewed (+0x198). While the window is open, the player's name
// sprite (0x0047CF7C) shows it in place of the current title, and the name colour (0x0047AA0B)
// changes when a preview differs from the current title or suffix.
// FUNCTION: TITANIUM 0x0056513B
char* __fastcall GetTitlePrefix_guess(char* self)
{
	return self + 0x198;
}

// Title window: the suffix being previewed (+0x1B8). While the window is open, the player's name
// sprite (0x0047CF7C) shows it in place of the current suffix, and the name colour (0x0047AA0B)
// changes when a preview differs from the current title or suffix.
// FUNCTION: TITANIUM 0x00565142
char* __fastcall GetTitleSuffix_guess(char* self)
{
	return self + 0x1b8;
}

// Frees every node of every bucket and empties the buckets, keeping the node and used-bucket counts
// in step.
// FUNCTION: TITANIUM 0x00565149
void TitleTable_guess::Clear_guess()
{
	int i = 0;
	if (0 < bucketCount)
	{
		do
		{
			CleanupNode_guess* node = buckets[i];
			if (node != 0)
			{
				--chainCount;
				do
				{
					CleanupNode_guess* next = node->next;
					free(node);
					--nodeCount;
					node = next;
				} while (node != 0);
				buckets[i] = node;
			}
			++i;
		} while (i < bucketCount);
	}
}

// Title table: the hash node for title id `key` (bucket key % bucket count, then the chain), or 0. The
// by-id lookup (0x0056529C) uses it.
// FUNCTION: TITANIUM 0x00565183
HashNode_guess* HashTable_guess::Find_guess(unsigned int key)
{
	HashNode_guess* node = buckets[key % bucketCount];
	while (node != 0 && node->key != key)
		node = node->next;
	return node;
}

// Next node after `node` in its chain with the same key, or null.
// FUNCTION: TITANIUM 0x005651A6
HashNode_guess* HashTable_guess::FindNext_guess(HashNode_guess* node)
{
	unsigned int key = node->key;
	for (;;)
	{
		node = node->next;
		if (node == 0)
			break;
		if (node->key == key)
			break;
	}
	return node;
}

// Iteration: the next node in this chain, else the first node of a later bucket, else 0.
// FUNCTION: TITANIUM 0x005651BE
HashNode_guess* HashTable_guess::Next_guess(HashNode_guess* node)
{
	int i = node->key % bucketCount;
	HashNode_guess* next = node->next;
	if (next)
		return next;
	int j = i + 1;
	if (i + 1 < bucketCount)
	{
		for (; j < bucketCount; ++j)
		{
			next = buckets[j];
			if (next)
				return next;
		}
	}
	return 0;
}

// Rehashes the table into a new bucket array of 0x0042429E(`hint`) buckets (odd; prime squares can pass):
// every node is relinked at the head of bucket key % count, `used` recounts the non-empty buckets, and the
// old array is freed.
// FUNCTION: TITANIUM 0x005651F4
void HashTable_guess::Rehash_guess(int hint)
{
	HashNode_guess** old = buckets;
	int oldCount = bucketCount;
	bucketCount = NextPrimeCandidate_guess(hint);
	buckets = new HashNode_guess*[bucketCount];
	memset(buckets, 0, bucketCount << 2);
	used = 0;
	if (nodeCount > 0)
	{
		for (int i = 0; i < oldCount; ++i)
		{
			HashNode_guess* p = old[i];
			while (p)
			{
				HashNode_guess* c = p;
				unsigned int h = c->key;
				HashNode_guess** l = &p->next;
				p = *l;
				h %= bucketCount;
				HashNode_guess* f = buckets[h];
				if (!f)
				{
					*l = 0;
					buckets[h] = c;
					++used;
				}
				else
				{
					*l = f;
					buckets[h] = c;
				}
			}
		}
	}
	_free(old);
}

// Title with id `key`: walks the chain for an exact id match.
// FUNCTION: TITANIUM 0x0056529C
HashNode_guess* HashTable_guess::FindKey_guess(unsigned int key)
{
	HashNode_guess* node = Find_guess(key);
	while (node != 0 && node->key_0000_guess != key)
		node = FindNext_guess(node);
	return node;
}

// Empties the title table (0x00565149). Done on the way from login to character select (0x004AA92B), so
// the next character's titles start fresh.
// FUNCTION: TITANIUM 0x005652C1
void TitleTable_guess::ClearTitles_guess()
{
	Clear_guess();
}

// Binds the Title_* controls and reads the Titles/NotifyNewTitles setting (default on).
// FUNCTION: TITANIUM 0x005652C6
// @early-stop: budget, structural ndiff=71
CTitleWnd_guess::CTitleWnd_guess(CXWnd* parent)
	: CallbackMainBase_guess(parent, CXStr("TitleWnd"))
{
	memset(nameBuf_guess, 0, sizeof(nameBuf_guess));
	memset(titleBuf_guess, 0, sizeof(titleBuf_guess));
	value = 0.0f;
	index = g_slotIndex_guess;
	notifyNewTitles_guess = g_settings_guess->GetBool_guess("Titles", "NotifyNewTitles", 1, 1);
	setting_guess[0] = 0;
	setting_guess[1] = 0;
	setting_guess[2] = 0;
	setting_guess[3] = 0;
	setting_guess[4] = 0;
	setting_guess[5] = 0;
	setting_guess[6] = 0;
	setting_guess[7] = 0;
	setting_guess[8] = 0;
	setting_guess[9] = 0;
	setting_guess[10] = 0;
	setting_guess[11] = 0;
	if (((CSidlScreenWnd*)this)->SidlPiece != 0)
	{
		((CXWnd*)this)->WindowStyle |= 0x10000;
		value158_guess = 0x39;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		{
			CXStr name_guess("Title_CurrentName");
			setting_guess[0] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_ProposedName");
			setting_guess[1] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_AvailableTitles");
			setting_guess[2] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_AvailableSuffixes");
			setting_guess[3] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_ChangeTitlePrefix");
			setting_guess[4] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_ClearTitlePrefix");
			setting_guess[5] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_ChangeTitleSuffix");
			setting_guess[6] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_ClearTitleSuffix");
			setting_guess[7] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_NotifyNewTitles");
			setting_guess[8] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_TitleSheet");
			setting_guess[9] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_PrefixPage");
			setting_guess[10] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		{
			CXStr name_guess("Title_SuffixPage");
			setting_guess[11] = ((CSidlScreenWnd*)this)->GetChildItem(name_guess);
		}
		if (setting_guess[2] != 0)
		{
			ControlFlag_guess* control_guess = (ControlFlag_guess*)setting_guess[2];
			control_guess->value16c_guess = 0xffffff00;
			control_guess->value154_guess = 0;
			control_guess->WindowStyle |= 0x40000;
		}
		if (setting_guess[3] != 0)
		{
			ControlFlag_guess* control_guess = (ControlFlag_guess*)setting_guess[3];
			control_guess->value16c_guess = 0xffffff00;
			control_guess->value154_guess = 0;
			control_guess->WindowStyle |= 0x40000;
		}
		if (setting_guess[8] != 0)
			reinterpret_cast<CButtonWnd*>(setting_guess[8])->SetCheck(notifyNewTitles_guess);
	}
}

// OnShow (vtable slot 35): when shown (+0x5C), context tip 0x39 in the tip window (0x9928E0); then the base
// OnShow (0x5A1880).
// FUNCTION: TITANIUM 0x0056505B
void CTitleWndShowView_guess::OnShow_guess()
{
	if (active != 0 && pinstCTipWndCONTEXT_guess != 0)
		pinstCTipWndCONTEXT_guess->selectTip_guess(0x39, 0);
	return OnShow();
}

// Enables Change only with a list selection, and Clear only when the player has that prefix or suffix.
// FUNCTION: TITANIUM 0x00565084
void CTitleWndView_guess::Sync_guess()
{
	if (firstControl != 0 && firstWidget != 0)
		firstWidget->active = firstControl->GetCurSel() > -1;
	if (secondControl != 0 && thirdWidget != 0)
		thirdWidget->active = secondControl->GetCurSel() > -1;
	if (secondWidget != 0 && g_controlState_guess != 0)
	{
		char* text = g_controlState_guess + 0x2a4;
		char enabled;
		if (text == 0 || strlen(text) <= 0)
			enabled = 0;
		else
			enabled = 1;
		secondWidget->active = enabled;
	}
	if (fourthWidget != 0 && g_controlState_guess != 0)
	{
		char* text = g_controlState_guess + 0x2c4;
		char enabled;
		if (text == 0 || strlen(text) <= 0)
			enabled = 0;
		else
			enabled = 1;
		fourthWidget->active = enabled;
	}
}

// Scalar deleting destructor of the title window (vtable 0x65EB08 slot 1): destroys it and frees it
// when flag 1 is set.
// FUNCTION: TITANIUM 0x005656EB
CTitleWnd_guess* CTitleWnd_guess::Destroy_guess(unsigned char flags)
{
	this->CTitleWnd_guess::~CTitleWnd_guess();
	if ((flags & 1) != 0)
		free(this);
	return this;
}

// Refills both lists from the title table and selects the player's current prefix and suffix.
// FUNCTION: TITANIUM 0x00565707
void CTitleWndView_guess::Populate_guess()
{
	if (firstControl != 0)
		reinterpret_cast<ListSlots_guess*>(firstControl)->Slot4C_guess();
	if (secondControl != 0)
		reinterpret_cast<ListSlots_guess*>(secondControl)->Slot4C_guess();
	int found1 = -1;
	int found2 = -1;
	char* name1 = g_emptyString_guess;
	char* name2 = g_emptyString_guess;
	if (g_controlState_guess != 0)
	{
		name1 = g_controlState_guess + 0x2a4;
		name2 = g_controlState_guess + 0x2c4;
	}
	for (HashNode_guess* node = g_nameTable_guess.First_guess(); node != 0; node = g_nameTable_guess.Next_guess(node))
	{
		if (firstControl != 0 && strlen(node->name_guess) > 0)
		{
			int index = reinterpret_cast<CListWnd*>(firstControl)->AddString(node->name_guess, 0xffffffff, node->key_0000_guess, 0);
			if (found1 == -1 && _stricmp(node->name_guess, name1) == 0)
			{
				found1 = index;
				strncpy(nameBuf_guess, node->name_guess, 31);
			}
		}
		if (secondControl != 0 && strlen(node->title_guess) > 0)
		{
			int index = reinterpret_cast<CListWnd*>(secondControl)->AddString(node->title_guess, 0xffffffff, node->key_0000_guess, 0);
			if (found2 == -1 && _stricmp(node->title_guess, name2) == 0)
			{
				found2 = index;
				strncpy(titleBuf_guess, node->title_guess, 31);
			}
		}
	}
	if (firstControl != 0)
	{
		int count = reinterpret_cast<CListWnd*>(firstControl)->ItemsCount;
		for (int i = 0; i < count; ++i)
		{
			CXStr text = reinterpret_cast<CListWnd*>(firstControl)->GetItemText(i, 0);
			if (_stricmp(text, name1) == 0)
			{
				reinterpret_cast<CListWnd*>(firstControl)->SetCurSel(i);
				break;
			}
		}
	}
	if (secondControl != 0)
	{
		int count = reinterpret_cast<CListWnd*>(secondControl)->ItemsCount;
		for (int i = 0; i < count; ++i)
		{
			CXStr text = reinterpret_cast<CListWnd*>(secondControl)->GetItemText(i, 0);
			if (_stricmp(text, name2) == 0)
			{
				reinterpret_cast<CListWnd*>(secondControl)->SetCurSel(i);
				break;
			}
		}
	}
}

// Shows the player's current full name with prefix and suffix in Title_CurrentName (always when `mode_guess`,
// else only while the window is open).
// FUNCTION: TITANIUM 0x005659C1
// @early-stop: unknown, diff ndiff=12
void CTitleWndView_guess::UpdateNamePreview_guess(bool mode_guess)
{
	if (mode_guess || active_guess)
	{
		CXStr first_guess(g_controlState_guess + 0x2a4);
		CXStr second_guess(g_controlState_guess + 0x2c4);
		if (textTarget_guess != 0)
		{
			CXStr output_guess;
			int firstLength_guess;
			if (first_guess.Ptr != 0)
				firstLength_guess = first_guess.Ptr->length;
			else
				firstLength_guess = 0;
			if (firstLength_guess > 0)
				FormatString_guess(&output_guess, "%s %s %s", (char*)first_guess, g_controlState_guess + 0x120, g_controlState_guess + 1);
			else
				FormatString_guess(&output_guess, "%s %s", g_controlState_guess + 0x120, g_controlState_guess + 1);
			int secondLength_guess;
			if (second_guess.Ptr != 0)
				secondLength_guess = second_guess.Ptr->length;
			else
				secondLength_guess = 0;
			if (secondLength_guess > 0)
			{
				CXStr copy_guess(output_guess);
				FormatString_guess(&output_guess, "%s %s", (char*)copy_guess, (char*)second_guess);
			}
			textTarget_guess->SetWindowText_guess(*reinterpret_cast<CXStr*>(&output_guess));
		}
		Sync_guess();
	}
}

// Picks a prefix (`useFirst_guess`) or suffix from `pair_guess` for the proposed-name preview.
// FUNCTION: TITANIUM 0x00565B3B
void CTitleWndView_guess::SetSelectedTitle_guess(TextPair_guess* pair_guess, bool useFirst_guess)
{
	char* first_guess = nameBuf_guess;
	char* second_guess = titleBuf_guess;
	if (useFirst_guess)
	{
		first_guess = g_emptyString_guess;
		if (pair_guess != 0 && strlen(pair_guess->first) > 0)
			first_guess = pair_guess->first;
		strncpy(nameBuf_guess, first_guess, 31);
	}
	else
	{
		second_guess = g_emptyString_guess;
		if (pair_guess != 0 && strlen(pair_guess->second) > 0)
			second_guess = pair_guess->second;
		strncpy(titleBuf_guess, second_guess, 31);
	}
	if (target_guess != 0)
	{
		CXStr text_guess;
		FormatString_guess(&text_guess, "%s %s %s %s", first_guess, g_controlState_guess + 0x120, g_controlState_guess + 1, second_guess);
		target_guess->SetWindowText_guess(text_guess);
	}
	Sync_guess();
}

// Hash table constructor: no buckets or nodes yet, then sized for `hint` entries (rehash). The title
// table constructor (0x00565CC1) passes 200.
// FUNCTION: TITANIUM 0x00565C2C
HashTable_guess::HashTable_guess(int hint)
{
	buckets = 0;
	bucketCount = 0;
	nodeCount = 0;
	used = 0;
	Rehash_guess(hint);
}

// Destructor of the title table: frees every node (0x00565149) and the bucket array. Reached through
// the exit-time thunk 0x00565CBC.
// FUNCTION: TITANIUM 0x00565C4B
void TitleTable_guess::Free_guess()
{
	Clear_guess();
	_free(buckets);
}

// Adds a copy of `entry_guess` under id `value_guess`.
// FUNCTION: TITANIUM 0x00565C5D
void TitleTable_guess::AddTitle_guess(TitleEntry_guess* entry_guess, int value_guess)
{
	CleanupNode_guess* node = new CleanupNode_guess;
	reinterpret_cast<TextPair_guess*>(node)->Copy(reinterpret_cast<TextPair_guess*>(entry_guess));
	node->key = value_guess;
	unsigned int slot = (unsigned int)value_guess % (unsigned int)bucketCount;
	CleanupNode_guess* head = buckets[slot];
	if (head == 0)
	{
		node->next = 0;
		buckets[slot] = node;
		++chainCount;
	}
	else
	{
		node->next = head;
		buckets[slot] = node;
	}
	++nodeCount;
}

// Constructor of the title table: a hash with 200 buckets requested (0x00565C2C, rounded up to 211).
// Run by a static initializer (0x0063C05D) at startup.
// FUNCTION: TITANIUM 0x00565CC1
DerivedTable_guess::DerivedTable_guess() : HashTable_guess(200)
{
}

// Title list payload: count, then per title an int id, the prefix and the suffix as NUL-terminated strings.
// Refills the open window.
// FUNCTION: TITANIUM 0x00565CD2
void TitleTable_guess::Handle_OP_SendTitleList_guess(char* data_guess)
{
	Clear_guess();
	if (data_guess != 0)
	{
		int count = 0;
		memcpy(&count, data_guess, 4);
		int offset = 4;
		for (int i = 0; i < count; ++i)
		{
			TitleEntry_guess entry;
			entry.ResetEntry_guess();
			memcpy(&entry.titleId_0000_guess, data_guess + offset, 4);
			offset += 4;
			// Copied into 32-byte fields with no length limit (sprintf %s).
			offset += sprintf(entry.first, "%s", data_guess + offset) + 1;
			offset += sprintf(entry.second, "%s", data_guess + offset) + 1;
			AddTitle_guess(&entry, entry.titleId_0000_guess);
		}
	}
	if (pinstCTitleWnd_guess != 0 && pinstCTitleWnd_guess->active_guess != 0)
		pinstCTitleWnd_guess->Populate_guess();
}

struct TargetText_guess
{
	// EXTERNAL: TITANIUM 0x0047A77B TargetText_guess::SetName_guess
	void SetName_guess(const char* text_guess);
	// EXTERNAL: TITANIUM 0x0047A7B7 TargetText_guess::SetTitle_guess
	void SetTitle_guess(const char* text_guess);
	char reserved_guess[0x4c];
	float value4c_guess; // 0x4c
};

// EXTERNAL: TITANIUM 0x00401B28 FUN_00401b28_guess
TargetText_guess* __cdecl FUN_00401b28_guess(int id_guess);

struct NameSetter_guess
{
	void SetName_guess(int id_guess, const char* text_guess);
	void SetTitle_guess(int id_guess, const char* text_guess);
};

// Sets spawn `id_guess`'s name text and, for the local player, refreshes the preview.
// FUNCTION: TITANIUM 0x00565D94
void NameSetter_guess::SetName_guess(int id_guess, const char* text_guess)
{
	TargetText_guess* target = FUN_00401b28_guess(id_guess);
	if (target != 0 && text_guess != 0)
	{
		target->SetName_guess(text_guess);
		if (target == g_activeTarget_guess)
			pinstCTitleWnd_guess->UpdateNamePreview_guess(0);
	}
}

// Sets spawn `id_guess`'s suffix (SetSuffix_guess) and, for the local player, refreshes the preview.
// FUNCTION: TITANIUM 0x00565DD0
void NameSetter_guess::SetTitle_guess(int id_guess, const char* text_guess)
{
	TargetText_guess* target = FUN_00401b28_guess(id_guess);
	if (target != 0 && text_guess != 0)
	{
		target->SetTitle_guess(text_guess);
		if (target == g_activeTarget_guess)
			pinstCTitleWnd_guess->UpdateNamePreview_guess(0);
	}
}

// On open: requests the titles, fills the lists and preview, saves the camera, then switches to camera mode 7
// aimed at the player (SetupCharacterViewCamera_guess(100), height + 4.5).
// FUNCTION: TITANIUM 0x00565E0C
char CTitleWndView_guess::AboutToShow_guess()
{
	memset(nameBuf_guess, 0, 0x1f);
	memset(titleBuf_guess, 0, 0x1f);
	if (g_controlState_guess != 0)
		UpdateNamePreview_guess(1);
	g_nameTable_guess.RequestTitles_guess();
	Populate_guess();
	if (target_guess != 0)
	{
		CXStr text_guess;
		FormatString_guess(&text_guess, "%s %s %s %s", nameBuf_guess, g_controlState_guess + 0x120, g_controlState_guess + 1, titleBuf_guess);
		target_guess->SetWindowText_guess(text_guess);
	}
	field160_guess = g_slotIndex_guess;
	field164_guess = g_callbackGlobalBits_guess->bits_guess;
	reinterpret_cast<CallbackManager_guess*>(g_callbackTarget_guess)->SetCameraMode_guess(7);
	g_renderOwner_guess->Slot04_guess();
	reinterpret_cast<CallbackManager_guess*>(g_callbackTarget_guess)->SetupCharacterViewCamera_guess(100);
	g_renderOwner_guess->Slot20_guess(g_activeTarget_guess->value4c_guess);
	g_renderOwner_guess->Slot18_guess(g_renderOwner_guess->value34_guess + 4.5f);
	g_renderOwner_guess->Slot14_guess(0.0f);
	return 1;
}

// List clicks update the preview; Change sends the selected title (OP_SetTitle 0 prefix, 1 suffix), Clear
// sends id 0; the notify box saves Titles/NotifyNewTitles.
// FUNCTION: TITANIUM 0x00565F53
// @early-stop: budget, diff ndiff=72
void CTitleWndView_guess::OnMessage_guess(void* sender_guess, unsigned int message_guess, void* data_guess)
{
	if (message_guess == 1)
	{
		if (sender_guess == firstControl)
		{
			unsigned int key_guess = reinterpret_cast<CListWnd*>(firstControl)->GetItemData(reinterpret_cast<CListWnd*>(firstControl)->GetCurSel());
			HashNode_guess* node_guess = g_nameTable_guess.FindKey_guess(key_guess);
			if (node_guess != 0)
				SetSelectedTitle_guess(reinterpret_cast<TextPair_guess*>(node_guess), true);
			Sync_guess();
		}
		else if (sender_guess == secondControl)
		{
			unsigned int key_guess = reinterpret_cast<CListWnd*>(secondControl)->GetItemData(reinterpret_cast<CListWnd*>(secondControl)->GetCurSel());
			HashNode_guess* node_guess = g_nameTable_guess.FindKey_guess(key_guess);
			if (node_guess != 0)
				SetSelectedTitle_guess(reinterpret_cast<TextPair_guess*>(node_guess), false);
			Sync_guess();
		}
		else if (sender_guess == firstWidget)
		{
			unsigned int key_guess = reinterpret_cast<CListWnd*>(firstControl)->GetItemData(reinterpret_cast<CListWnd*>(firstControl)->GetCurSel());
			HashNode_guess* node_guess = g_nameTable_guess.FindKey_guess(key_guess);
			if (node_guess != 0)
				reinterpret_cast<MessageSender_guess*>(&g_nameTable_guess)->SendSetTitle_guess(reinterpret_cast<int*>(node_guess), 0);
		}
		else if (sender_guess == thirdWidget)
		{
			unsigned int key_guess = reinterpret_cast<CListWnd*>(secondControl)->GetItemData(reinterpret_cast<CListWnd*>(secondControl)->GetCurSel());
			HashNode_guess* node_guess = g_nameTable_guess.FindKey_guess(key_guess);
			if (node_guess != 0)
				reinterpret_cast<MessageSender_guess*>(&g_nameTable_guess)->SendSetTitle_guess(reinterpret_cast<int*>(node_guess), 1);
		}
		else if (sender_guess == secondWidget)
		{
			if (firstControl != 0)
				reinterpret_cast<CListWnd*>(firstControl)->ClearAllSel();
			SetSelectedTitle_guess(0, true);
			reinterpret_cast<MessageSender_guess*>(&g_nameTable_guess)->SendSetTitle_guess(0, 0);
		}
		else if (sender_guess == fourthWidget)
		{
			if (secondControl != 0)
				reinterpret_cast<CListWnd*>(secondControl)->ClearAllSel();
			SetSelectedTitle_guess(0, false);
			reinterpret_cast<MessageSender_guess*>(&g_nameTable_guess)->SendSetTitle_guess(0, 1);
		}
		else if (sender_guess == source_guess)
		{
			unsigned char state_guess = source_guess->state_guess;
			flag_guess = state_guess;
			g_callbackGlobal_guess->Notify_guess(state_guess, "Titles", "NotifyNewTitles");
		}
	}
	reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(reinterpret_cast<CXWnd*>(sender_guess), message_guess, data_guess);
}

