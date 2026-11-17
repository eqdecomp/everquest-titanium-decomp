# Items and inventory

[Overview](ARCHITECTURE.md) section 10 | [Source guide](README.md)

An item reaches the client as a text record inside a message, becomes an item object, and is stored in a
slot of the character (`pCharData`, 0x00905D00). Windows show the slots; moving an item changes the slots
locally and tells the server.

```
OP_ItemPacket (0x3397)    dispatcher case
   |  CreateItemList_guess 0x004B232E (tu_069_KeypressHandler)       build one EQ_Item from the record
   v
PlaceReceivedItem_guess 0x0045A817 (tu_042_EQHandleMsg)         switch on the packet's mode
   |- inventory / bags / bank / shared bank         -> pCharData slot arrays
   |- merchant (0x64), trade (0x65), loot (0x66)    -> the window's own list
   `- refresh: CDisplay equipment, container windows
                                     ^
player drags an item                 |
ActionQueue_guess::HandleLButtonUp_guess 0x00519356 (tu_172_InvSlotMgr; MQ2 CInvSlot::HandleLButtonUp)
   `- CInvSlotMgr::MoveItem 0x0051A9A8: swap the two slots, send OP_MoveItem (0x420F)
```

## Receiving items
| case | handler | what |
|---|---|---|
| OP_ItemPacket (0x3397) | `CreateItemList_guess` 0x004B232E, then `PlaceReceivedItem_guess` 0x0045A817 | one item; the first dword of the payload is the mode, the item record follows at +4 |
| OP_CharInventory (0x5394) | 0x0045AF4E (`ReceiveSerializedItems_guess`) | the whole inventory at zone-in |
| OP_MoveItem (0x420F) | `Handle_OP_MoveItem_guess` 0x004591FD (from, to, count) | a server-side move; on failure prints string 0x56D (1389) |
| OP_DeleteItem (0x4D81) | `Handle_OP_DeleteItem_guess` 0x00458DC2 | on failure prints string 0x56E (1390) |
| OP_DeleteCharge (0x1C4A) | `Handle_OP_DeleteCharge_guess` 0x00458CD1 | uses up a charge |

After a move or delete the dispatcher refreshes two windows if they are open (the objects at 0x00992940 and
0x00850C58).

`CreateItemList_guess` (0x004B232E) allocates one item instance (`EQ_Item`, 0xA8 bytes, vtable 0x00644780),
loads it from the text record and returns it only if it parsed (`Ready_guess`); a valid item with a count of
0 or less gets count 1. "ItemList" is a misnomer: the class it builds is `EQ_Item_guess` in tu_069_KeypressHandler
(whose two old views of the vtable 0x00644780 family were merged into it) and in tu_042_EQHandleMsg. Despite the reference
label `Handle_OP_ItemPacket` it is a parser; the dispatcher does the rest.

### PlaceReceivedItem_guess: modes and slot ranges
The item is rejected with a chat message if its type is 0xD or its count is below 1 (string 0x556 = 1366), or if it
is stackable and its field +0x48 is 0 or less (string 0x558 = 1368, with the count). Otherwise the mode decides.

Sources: "code" is the switch in `PlaceReceivedItem_guess` (0x0045A817, tu_042_EQHandleMsg); a window is identified by
the constructor `InitGameUI_guess` (0x0043EFDD) stores in its global (tu_029_Display). "EQEmu" is `ItemPacketType` in
EQEmu's `titanium_limits.h` (used as a reference, not shipped). The source names the globals backwards (`g_trade45A817_guess` is
0x00850C4C, the merchant window; `g_merchant45A817_guess` is 0x00850C50, the trade window), as its own comment says.

| mode | EQEmu name | destination (from the code) | source |
|---|---|---|---|
| 0x64 (100) | Merchant | merchant window 0x00850C4C (ctor 0x00536D26, tu_188_MerchantWnd `CMerchantWnd_guess`): adds the item to its list | code; EQEmu agrees |
| 0x65 | TradeView | trade window 0x00850C50 (ctor 0x0056982F, tu_232_TradeWnd `CTradeWnd_guess`); if it accepts the item, prints string 0x2344 (9028) with the name of the spawn at 0x00905CE0 and the item's name (the source comment gives the text as "%1 has offered you a %2") | code; EQEmu agrees. Unverified: the string text and which spawn 0x00905CE0 holds |
| 0x66 | Loot | loot window 0x00850C40 (ctor 0x0052B4C9, tu_182_LootWnd, `CLootWnd` by the file name) | code; EQEmu agrees |
| 0x67 | Trade | the character's slots, by slot number (below), and shows notice 0x92 | code; EQEmu agrees (EQEmu uses it to put items into the inventory) |
| 0x69 | CharInventory | the character's slots, by slot number; refused while a save or weather update is pending; logs each item as a starting item | code; EQEmu agrees |
| 0x6A | Limbo (`titanium_structs.h`: SummonItem) | `AddItemToCursorQueue_guess`: the cursor queue; the item is freed if that fails | code; EQEmu agrees |
| 0x6B | WorldContainer | slots 0-9 of the object at 0x00850CBC (ctor 0x004FA372, tu_148_ContainerMgr, `CContainerMgr_guess` in the class map); the source calls this global `g_tribute45A817_guess` | code; EQEmu agrees |
| 0x6C | TributeItem | slots 400-404: a five-entry array in the character, the old item is freed | code; EQEmu agrees. The slot range is from the code; the reader in the source's view is still called `GetBankItem_guess` (0x0040CC6B); the writer is `SetTributeItem_guess` (0x00434792) |
| 0x6D | GuildTribute | slots 450-451: a two-entry array in the character, the old item is freed | code; EQEmu agrees. The slot range is from the code; only the accessor name `SetSharedItem_guess` is doubtful |
| 0x6E | CharmUpdate (not in `titanium_structs.h`) | replaces the item in place: slots 0-30 (worn, general, cursor) or a bag slot 31-341 | code; EQEmu agrees |

After the switch, modes 0x65, 0x67, 0x69, 0x6C, 0x6D and 0x6E mark the character's data dirty (0x69 also refreshes
it). No case handles 0x68.

Slot numbers used by modes 0x67/0x69 (0x6E uses the first two ranges), from the range checks:

| slots | meaning |
|---|---|
| 0-30 | worn slots, the general inventory and the cursor; for slots 1-20 (outside mode 0x69) `pEverQuest` also gets an update call (0x00988DF0) |
| 31-341 | bag contents: `(slot - 31) / 10` is the slot holding the bag, `(slot - 31) % 10` the position in it. EQEmu's general bags are 251-340, i.e. bags in slots 22-30 |
| 2000-2015 | bank |
| 2031-2190 | contents of bank bags: `(slot - 2031) / 10` is the bank slot (0-15), `% 10` the position |
| 2500-2501 | shared bank |
| 2531-2550 | contents of shared bank bags |

These match the Titanium slot numbering EQEmu uses. Bank bag contents use slots 2031-2190.

## Moving items (tu_171_InvSlot, tu_172_InvSlotMgr, tu_173_InvSlotWnd)
- `CInvSlot`* (tu_171_InvSlot, tu_172_InvSlotMgr): one per visible slot; `ActionQueue_guess::HandleLButtonUp_guess` (0x00519356, `HandleLButtonUp`*) starts a pick-up or a drop.
- `CInvSlotMgr`* (tu_172_InvSlotMgr; ctor 0x0051A8E2, global 0x00850CB8): finds slots (`FindInvSlot`* 0x0051A84D, `LookupTable_guess::FindInvSlot` in the source) and
  moves items (`MoveItem` 0x0051A9A8, on the view `ItemMover_guess`). `MoveItem` swaps the two slot pointers, then sends OP_MoveItem with
  `{from, to, 0}` (12 bytes) and, if the trade window is involved, tells it (`CTradeWnd::TradeItemChanged`*).
  It is also called by the bank window code (tu_127_BankWnd) and the action queue (0x005191E1 `ActionQueue_guess::PickUpQuantity_guess`, the quantity-prompt answer).
- `InvSlotWnd` (tu_173_InvSlotWnd): the window of one slot. Draws the background, the icon, the stack count
  and the recast shade, and forwards mouse presses to its `CInvSlot` (field +0x140) and to its parent.
- `CCursorAttachment`* (tu_150_CursorAttachment; ctor 0x004FD3CE): the item or money on the cursor; `CCursorAttachmentView_guess::Draw` 0x004FD8A9.

## Windows that show items
| file | window | constructor | screen name |
|---|---|---|---|
| tu_170_InventoryWnd | `CInventoryWnd` (class `CInventoryWndView_guess`) | 0x00516E9A | "InventoryWindow" |
| tu_148_ContainerMgr | `CContainerMgr`* (class `CContainerMgr_guess`; `GetFreeContainerWnd_guess` 0x004FA2D4) | 0x004FA372 | |
| tu_149_ContainerWnd | `CContainerWnd`* (`SetContainer_guess` 0x004FB700, `HandleCombine` 0x004FC106) | 0x004FC9A4 | "ContainerWindow" |
| tu_174_ItemDisplayWnd | `CItemDisplayWnd_guess` (item inspect) | | |
| tu_182_LootWnd | `CLootWnd` | | |
| tu_188_MerchantWnd | `CMerchantWnd_guess` | 0x00536D26 | |
| tu_232_TradeWnd | `CTradeWnd_guess` | 0x0056982F | |
| tu_127_BankWnd | `CBigBankWnd` / bank helpers (`GetNumBankSlots`* 0x004DC831, `ClientObject_guess::GetNumBankSlots` in the source) | | |
| tu_161_GiveWnd | `CGiveWnd` (give to an NPC) | | |

## The item object
Item methods live in the 0x005E0000 band (0x005E0D70-0x005ECCC0) and are not rewritten. Reference names:
`EQ_Item::IsStackable` (0x005EC760), `EQ_Item::GetItemLinkHash` (0x005E3850). Pinned down in review:
0x005EC8B0 returns the classes mask (definition +0x114) and 0x005EC920 the races mask (+0x118) (the source's
`GetRaces_guess`/`GetClasses_guess` in tu_080_EQ_PC are swapped); 0x005ECCC0 returns the item class byte (+0xD5:
0 item, 1 container, 2 book; it was `IsBlocked_guess`); 0x005E10B0 returns the augment's distiller item id
(+0x2A0), sent in OP_AugmentInfo (0x45FF) by 0x00521827. Each TU declares the
ones it calls under its own local name (`Element_guess::IsValid_guess` = 0x005EC760 in tu_172_InvSlotMgr), so grep by VA.
The item classes local to tu_042_EQHandleMsg are `EQ_Item_guess`, `ItemInfo_guess` and
`EQ_ItemBase_guess`; there `ItemInfo_guess` is the item definition. tu_174_ItemDisplayWnd's view of the item instance
(`EQ_Item` methods at 0x005E0xxx/0x005ECxxx) is `EQ_ItemView_guess`; tu_080_EQ_PC has its own `EQ_ItemView_guess`.
0x00401B65 (tu_002_ProgressionData, `GetProgressionRecord_guess`)
looks a progression record up by key; on a miss with its flag set it requests the key with opcode 0x3A14.

Coins are separate from items: `Handle_OP_MoneyUpdate_guess` (0x0045686E), `AddCoinsByType_guess`
(0x00457A91) and three deduct helpers, one per dispatcher case (all three values have no EQEmu name): `DeductCarriedCoins_guess`
0x00456A1E (case 0x3E52, the carried coins at character +0x11D4), 0x00456CA5 `FUN_00456ca5_guess` (case 0x4642,
the coin set at +0x144..+0x150) and 0x00456E3B `FUN_00456e3b_guess` (case 0x7DF1, the set at +0x134..+0x140).
Which coin set (bank, cursor, ...) the last two are is unproven, so they keep their placeholder names;
`DeductCarriedCoins_guess` is low confidence too. The cursor coins
are at +0x11E4..+0x11F0 of the profile block (0x004BE5FE sends them as OP_MoveCoin (0x7657)).
