# Items and inventory

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 10 | [Long page](../items_inventory.md)

Items arrive from the server as text records, are built into `EQ_Item` objects, and are placed by a mode
number into the character, a bag, the bank, a window or the cursor queue. Moves start in the inventory
slot windows and are sent to the server as OP_MoveItem.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_069_KeypressHandler.cpp` | `CreateItemList_guess`, `EQ_Item_guess` | builds an item from a packet |
| `tu_042_EQHandleMsg.cpp` | `PlaceReceivedItem_guess` | puts a received item where its mode says |
| `tu_171_InvSlot.cpp`, `tu_172_InvSlotMgr.cpp`, `tu_173_InvSlotWnd.cpp` | `CInvSlot`, `ItemMover_guess` (the slot manager), `CInvSlotWnd` | slot windows and moves |
| `tu_077_ItemMoveQueue.cpp` | `SwapMovedItem_guess`; also the position history (`PositionHistory_guess`) | item swaps, movement history |
| `tu_148_ContainerMgr.cpp`, `tu_149_ContainerWnd.cpp` | `CContainerMgr`, `CContainerWnd` | bags, combines, augments |
| `tu_170_InventoryWnd.cpp`, `tu_174_ItemDisplayWnd.cpp`, `tu_127_BankWnd.cpp`, `tu_182_LootWnd.cpp`, `tu_188_MerchantWnd.cpp`, `tu_232_TradeWnd.cpp` | item windows | |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x004B232E | `CreateItemList_guess(text)` | `new` item, loads the record, deletes it unless it parses; a valid item with count 0 or less gets count 1 |
| 0x0045A817 | `PlaceReceivedItem_guess(mode, item)` | refuses type 0xD or count < 1 (string 0x556) and stackables with no count (0x558); then by mode (below) |
| 0x0051A9A8 | `ItemMover_guess::MoveItem(from, to, arg, tryMerge)` | refuses targets 5000-5030 and 8000-8030; resolves both slots (worn and general, bag contents, bank within the bank size); swaps them and sends OP_MoveItem (0x420F) with {from, to, 0} (12 bytes) |
| 0x004B78F2 | `SwapMovedItem_guess` | finds an earlier queued record for the same item to swap with |
| 0x004B6F1F | `PositionHistory_guess::BuildMessage_guess` | builds the movement-history records sent as 0x6A1B, at most 10000; holds records younger than 2 s (`GetTickCount` against `EqGetTime` stamps, B42) |

Modes in `PlaceReceivedItem_guess` (EQEmu's ItemPacketType numbers): 0x64 merchant list, 0x65 trade
offer ("%1 has offered you a %2", string 0x2344), 0x66 loot, 0x67 trade and 0x69 character inventory (into
its slot; 0x69 is refused while weather or a save is pending), 0x6A summoned item to the cursor queue,
0x6B world container, 0x6C tribute, 0x6D guild tribute, 0x6E replace in place.

## Data flow

```
OP_ItemPacket (0x3397) {mode, text} -> CreateItemList_guess 0x004B232E -> PlaceReceivedItem_guess 0x0045A817
OP_CharInventory (0x5394)           -> 0x0045AF4E `ReceiveSerializedItems_guess` (the zone-in batch)
click on an InvSlotWnd -> CInvSlot -> ItemMover_guess::MoveItem 0x0051A9A8 -> OP_MoveItem (0x420F)
```

## Slot numbers (as range-checked in 0x0045A817 and 0x0051A9A8)

| Range | What |
|---|---|
| 0-30 | worn 0-21 (21 ammo), general 22-29, cursor 30; held directly in the item array |
| 31-341 | bag contents: `(slot - 31) / 10` is the holding slot, `% 10` the position (general bags 251-330, the bag on the cursor 331-340) |
| 2000-2015 | bank; 2031-2190 bank bag contents |
| 2500-2501 | shared bank; 2531-2550 its bag contents |

## Key globals and structs

| Address / offset | What |
|---|---|
| 0x00850CB8 | inventory slot manager (created by `CDisplay_guess::InitGameUI_guess`) |
| 0x00850C4C / 0x00850C50 | merchant window / trade window, as used by 0x0045A817 (the code's names for these two globals are swapped) |
| EQ_Item +0x48 | stack count |

## Known client bugs

- [B42](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd): the position history's
  2 s hold (0x004B6F1F `BuildMessage_guess`) compares `GetTickCount` with `EqGetTime` stamps, two clocks with different origins.
- [B43](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd):
  `SwapMovedItem_guess` 0x004B78F2 dereferences the slot lookup result without a null test.
- [B50](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd) tribute item
  reply, [B61](../KNOWN_CLIENT_BUGS.md#character-profile-items-and-coins-tu_079_playerprofile-tu_077_itemmovequeue-tu_027_tribute-tu_165_guildbankwnd) guild bank
  split.
- [B19](../KNOWN_CLIENT_BUGS.md#unresolved) (unresolved): `~CContainerWnd` and the A_DragItem copy.
