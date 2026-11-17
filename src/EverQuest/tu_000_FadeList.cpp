// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 0: a hint from compare/tumap.py.
// Two compiler-style helpers, then a fade-out list for actors. FadeNode_guess, Owner_guess and State_guess
// are one 0x14-byte node (links, actor +8, start time +0xC, last update +0x10); FadeList_guess and List_guess
// are one list object seen at +0 (fading nodes) and +8 (free nodes). Times come from EqGetTime (0x46D655).
#include "titanium/eqaddr.h"

struct Link_guess {
	Link_guess* next;
	Link_guess* previous;
};

struct Attachable_guess {
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess(int value);
	virtual void Slot04_guess(int value);
	virtual void Slot05_guess();
	virtual void Slot06_guess();
	virtual void Slot07_guess();
	virtual void Slot08_guess();
	virtual void Slot09_guess();
	virtual void Slot10_guess();
	virtual void Slot11_guess();
	virtual void Slot12_guess(unsigned flags);
	virtual unsigned Slot13_guess();
};

struct List_guess {
	int unknown00;
	int unknown04;
	Link_guess* head;
	Link_guess* tail;
	void Append_guess(Link_guess* node);
	void Remove_guess(Link_guess* node);
	void StartFade_guess(Attachable_guess* owner);
};

struct FadeList_guess {
	Link_guess* head;
	Link_guess* tail;
	void Append_guess(Link_guess* node);
	void Remove_guess(Link_guess* node);
	void ClearFades_guess();
	void UpdateFades_guess();
};

struct IteratorItem_guess {
	void* Construct_guess();
};

struct AllocationRecord_guess {
	int value00;
	int value04;
	int value08;
	int value0c;
};

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size);

#define g_allocationRecord_guess EQ_GLOBAL(AllocationRecord_guess*, 0x0079C100)

// The compiler's `vector constructor iterator`.
// FUNCTION: TITANIUM 0x00401000
void __stdcall vector_constructor_iterator_guess(void* first, unsigned int stride, int count, void* (IteratorItem_guess::*constructor)()) {
	if (--count < 0) {
		return;
	}
	int remaining = count + 1;
	char* current = (char*)first;
	do {
		(((IteratorItem_guess*)current)->*constructor)();
		current += stride;
		--remaining;
	} while (remaining != 0);
}

// The fade list singleton (0x0079C100): created empty (16 bytes, all zero) on first use, then returned.
// RealRender_World updates the fades through it every frame.
// FUNCTION: TITANIUM 0x00401022
AllocationRecord_guess* GetFadeList_guess() {
	if (g_allocationRecord_guess) {
		return g_allocationRecord_guess;
	}
	AllocationRecord_guess* record = (AllocationRecord_guess*)operator new(16);
	if (record) {
		record->value00 = 0;
		record->value04 = 0;
		record->value08 = 0;
		record->value0c = 0;
	} else {
		record = 0;
	}
	g_allocationRecord_guess = record;
	return record;
}

// Appends `node` to the fading list (+0).
// FUNCTION: TITANIUM 0x00401050
void FadeList_guess::Append_guess(Link_guess* node) {
	if (head == 0) {
		head = node;
	} else {
		tail->next = node;
		node->previous = tail;
	}
	tail = node;
}

// Unlinks `node` from the fading list.
// FUNCTION: TITANIUM 0x0040106E
void FadeList_guess::Remove_guess(Link_guess* node) {
	if (head == node) {
		head = node->next;
	}
	if (tail == node) {
		tail = node->previous;
	}
	if (node->previous != 0) {
		node->previous->next = node->next;
	}
	if (node->next != 0) {
		node->next->previous = node->previous;
	}
	node->next = 0;
	node->previous = 0;
}

// Appends `node` to the free list (+8).
// FUNCTION: TITANIUM 0x004010A6
void List_guess::Append_guess(Link_guess* node) {
	if (head == 0) {
		head = node;
	} else {
		tail->next = node;
		node->previous = tail;
	}
	tail = node;
}

// Unlinks `node` from the free list.
// FUNCTION: TITANIUM 0x004010C6
void List_guess::Remove_guess(Link_guess* node) {
	if (head == node) {
		head = node->next;
	}
	if (tail == node) {
		tail = node->previous;
	}
	if (node->previous != 0) {
		node->previous->next = node->next;
	}
	if (node->next != 0) {
		node->next->previous = node->previous;
	}
	node->next = 0;
	node->previous = 0;
}

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655_guess
int __cdecl FUN_0046d655_guess();

struct State_guess {
	int unknown00;
	int unknown04;
	int unknown08;
	int value0c;
	int value10;
	void Initialize_guess();
	State_guess(int value);
};

// Stamps the node's start time (+0xC) and last update (+0x10) with the current time (EqGetTime).
// FUNCTION: TITANIUM 0x00401100
void State_guess::Initialize_guess() {
	int value = FUN_0046d655_guess();
	value0c = value;
	value10 = value;
}

struct CDisplayView_guess {
	// EXTERNAL: TITANIUM 0x00439A46 CDisplayView_guess::Release_guess
	void Release_guess(void* value);
};

#define g_manager_guess EQ_GLOBAL(CDisplayView_guess*, 0x00905D24)

struct Owner_guess {
	int unknown00;
	int unknown04;
	void* resource;
	void DeleteActor_guess();
};

// Deletes the node's actor (CDisplay::DeleteActor) and forgets it.
// FUNCTION: TITANIUM 0x00401110
void Owner_guess::DeleteActor_guess() {
	g_manager_guess->Release_guess(resource);
	resource = 0;
}

struct Effects_guess {
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
	virtual void Slot63_guess();
	virtual void Slot64_guess();
	virtual void Slot65_guess();
	virtual void Slot66_guess();
	virtual void Slot67_guess();
	virtual void Slot68_guess();
	virtual void Slot69_guess();
	virtual void Slot70_guess();
	virtual void Slot71_guess();
	virtual void Slot72_guess();
	virtual void Slot73_guess();
	virtual void Slot74_guess();
	virtual void Slot75_guess();
	virtual void Slot76_guess();
	virtual int Slot77_guess(const char* name);
	virtual void Slot78_guess();
	virtual void Slot79_guess();
	virtual void Slot80_guess();
	virtual void Slot81_guess();
	virtual void Slot82_guess();
	virtual void Slot83_guess();
	virtual void Slot84_guess();
	virtual void Slot85_guess();
	virtual void Slot86_guess();
	virtual void Slot87_guess();
	virtual void Slot88_guess();
	virtual void Slot89_guess();
	virtual void Slot90_guess();
	virtual void Slot91_guess();
	virtual void Slot92_guess();
	virtual void Slot93_guess();
	virtual void Slot94_guess();
	virtual void Slot95_guess();
	virtual void Slot96_guess();
	virtual void Slot97_guess();
	virtual void Slot98_guess();
	virtual void Slot99_guess();
	virtual void Slot100_guess();
	virtual void Slot101_guess();
	virtual void Slot102_guess();
	virtual void Slot103_guess();
	virtual void Slot104_guess();
	virtual void Slot105_guess(int kind, int handle, int flag);
	virtual void Slot106_guess();
	virtual void Slot107_guess();
	virtual void Slot108_guess(float value);
};

struct FadeNode_guess {
	int unknown00;
	int unknown04;
	Effects_guess* target;
	int startValue;
	int lastValue;
	void UpdateFade_guess(int value);
};

// One actor's fade by ms since the start: at 1000 particle effect 0x5E on both hands, at 1150 on the chest
// (else SPELLPOINT_DEFAULT), at 1300 on both feet; from 1300 it fades to nothing over 2000 ms. A node with no
// actor jumps to 7000 so it expires. Probably the despawn shimmer.
// FUNCTION: TITANIUM 0x00401127
void FadeNode_guess::UpdateFade_guess(int value) {
	if (target == 0) {
		value = startValue + 7000;
	} else {
		unsigned elapsed = value - startValue;
		unsigned sinceLast = lastValue - startValue;
		if (elapsed > 1000) {
			if (elapsed > 0x514) {
				float scale = 1.0f - (float)(elapsed - 0x514) * 0.0005f;
				if (scale < 0.0f) {
					scale = 0.0f;
				} else if (scale > 1.0f) {
					scale = 1.0f;
				}
				target->Slot108_guess(scale);
			}
			if (sinceLast < 1000) {
				int rhand = target->Slot77_guess("SPELLPOINT_RHAND");
				int lhand = target->Slot77_guess("SPELLPOINT_LHAND");
				if (rhand != 0) {
					target->Slot105_guess(0x5e, rhand, 1);
				}
				if (lhand != 0) {
					target->Slot105_guess(0x5e, lhand, 1);
				}
			}
			if (sinceLast < 0x47e && elapsed >= 0x47e) {
				int chest = target->Slot77_guess("SPELLPOINT_CHEST");
				Effects_guess* owner = target;
				if (chest == 0) {
					chest = owner->Slot77_guess("SPELLPOINT_DEFAULT");
					if (chest != 0) {
						owner = target;
					}
				}
				if (chest != 0) {
					owner->Slot105_guess(0x5e, chest, 1);
				}
			}
			if (sinceLast < 0x514 && elapsed >= 0x514) {
				int rfoot = target->Slot77_guess("SPELLPOINT_RFOOT");
				int lfoot = target->Slot77_guess("SPELLPOINT_LFOOT");
				if (rfoot != 0) {
					target->Slot105_guess(0x5e, rfoot, 1);
				}
				if (lfoot != 0) {
					target->Slot105_guess(0x5e, lfoot, 1);
				}
			}
		}
	}
	lastValue = value;
}

// Per frame: advances every fading actor; after 3500 ms deletes it and moves its node to the free list.
// FUNCTION: TITANIUM 0x004012BB
void FadeList_guess::UpdateFades_guess() {
	Link_guess* node = head;
	int value = FUN_0046d655_guess();
	while (node != 0) {
		Link_guess* next = node->next;
		FadeNode_guess* tracker = (FadeNode_guess*)node;
		tracker->UpdateFade_guess(value);
		if ((unsigned)(tracker->lastValue - tracker->startValue) >= 0xdac) {
			((Owner_guess*)node)->DeleteActor_guess();
			Remove_guess(node);
			((List_guess*)this)->Append_guess(node);
		}
		node = next;
	}
}

// Deletes every fading actor at once and frees all nodes.
// FUNCTION: TITANIUM 0x00401307
void FadeList_guess::ClearFades_guess() {
	Link_guess* node = head;
	while (node != 0) {
		Link_guess* next = node->next;
		((Owner_guess*)node)->DeleteActor_guess();
		Remove_guess(node);
		((List_guess*)this)->Append_guess(node);
		node = next;
	}
}

// Node constructor: no links, actor `value` at +8, start and update times set to now (0x00401100).
// FUNCTION: TITANIUM 0x00401335
State_guess::State_guess(int value) {
	unknown00 = 0;
	unknown04 = 0;
	unknown08 = value;
	Initialize_guess();
}

// Starts fading `owner`, an actor: reuses a free node or allocates one, zeroes two actor settings (virtual
// slots 3 and 4) and sets actor flag 4, clearing flag 2.
// FUNCTION: TITANIUM 0x00401351
void List_guess::StartFade_guess(Attachable_guess* owner) {
	State_guess* node = (State_guess*)head;
	owner->Slot03_guess(0);
	owner->Slot04_guess(0);
	if (node == 0) {
		node = new State_guess((int)owner);
	} else {
		Remove_guess((Link_guess*)node);
		node->unknown08 = (int)owner;
	}
	node->Initialize_guess();
	((FadeList_guess*)this)->Append_guess((Link_guess*)node);
	unsigned flags = owner->Slot13_guess();
	owner->Slot12_guess((flags & 0xfffffffd) | 4);
}


