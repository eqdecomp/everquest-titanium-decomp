# Chat and commands

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 13 | [Long page](../ui.md)

Two input paths: key-map commands (keys, hot buttons, some UI buttons) go to `ExecuteCmd`; typed lines go
from a chat window to `InterpretCmd`, which runs a slash command from the command table or sends the text
to the window's current channel. Output reaches the chat windows through the chat manager.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_044_ExecuteCmd.cpp` | `ExecuteCmd` | the key-command switch |
| `tu_062_EverQuest.cpp` | `GlobalState_guess` (CEverQuest): `InterpretCmd`, `send_social_guess`, `do_*` senders | typed lines, socials |
| `tu_046_EQMisc.cpp` | slash command handlers | the bodies behind the command table |
| `tu_143_ChatManager.cpp` | `Selector_guess` (the chat manager) | chat windows, channel maps, context menus |
| `tu_144_ChatWindow.cpp` | `CChatWindowView_guess` | one chat window: input line, history, output |
| `tu_051_bad_word_class.cpp` | `ContainsProfanity_guess`, `GarbleText_guess` | profanity filter, language garbling |
| `tu_023_SystemCommands.cpp` | `DisplayTextLines_guess` | splits text into chat lines (`pEverQuest` 0x00498436) |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x004619CD | `ExecuteCmd(command, keyDown, data)` | ignores disabled commands; marks the call not allowed in command mode (0x0095A174), when the character state (+0xFC) is above 2 or our stand state is 102 (no control); the offline flags 0x00923798 / 0x00923884 allow it again; then one `case` per command id |
| 0x00498B78 | `GlobalState_guess::InterpretCmd(target, text)` | `;` lines go to the chat server, `[` lines to the mail channel; otherwise the first word is matched (by prefix) against the command table, first on the alias then on the name; restricted entries need the player flag +0x256; a matched command is refused at 0 HP or while a character state byte is 3 or 4 unless the entry allows it (string 0x21A); an unknown `/word` prints string 0x305C; plain text goes to the current channel |
| 0x0049E0C1 | `GlobalState_guess::send_social_guess` | an emote: target, pronouns, OP_Emote (0x547A) and OP_Animation (0x2ACF) |
| 0x004F70EF | `CChatWindowView_guess::WndNotification_guess` | on Enter (message 6): history, channel prefix for tell / chat / mail channels, then `InterpretCmd` with our spawn |
| 0x004F6A90 | `CChatWindowView_guess::AddOutputText_guess(text, color)` | colours the line by the chat colour index and appends it to the output view |
| 0x004F26E2 | `Selector_guess::AddChat_guess(name)` | opens a tell window (name capitalised; at most 0x20 windows) |
| 0x004F3120 | `Selector_guess::InitContextMenu` | the shared chat-window menus (channels, filters, display styles, languages) |
| 0x004788E1 | `ContainsProfanity_guess(word, len)` | tests one word against the 0x20-byte bad-word records |

Channels used by `InterpretCmd` for plain text (global 0x009237EC): 0 guild, 2 group, 4 auction, 5 OOC,
7 tell (to the name at 0x009237F4), 0xF raid, 0x13 chat-server channel, 0x14 mail channel, anything else
say (0x00476411 `SayToTarget_guess`).

## Data flow

```
key / hot button  -> key map -> ExecuteCmd 0x004619CD -> case per command id
                                   movement and camera keys only set 0x00925520[id]
chat input Enter  -> CChatWindowView_guess::WndNotification_guess 0x004F70EF
                  -> InterpretCmd 0x00498B78 -> command table 0x0078A0C8 (count at 0x006450B8) -> handler
                                             -> or do_guildsay / do_gsay / do_ooc / do_tell / say ...
server text       -> dispatcher -> dsp_chat -> chat manager -> AddOutputText_guess 0x004F6A90
```

## Key globals

| Address | What |
|---|---|
| 0x0078A0C8 / 0x006450B8 | slash command table / its count |
| 0x00789908 | key command names |
| 0x00925520 | held state per key command |
| 0x0095A174 | command mode: only the commands listed in string 0x3771 run |
| 0x009237EC / 0x009237F4 | current channel / tell or channel name |

## Known client bugs

- [B46, B47, B48](../KNOWN_CLIENT_BUGS.md#commands-and-input-tu_044_executecmd): `ExecuteCmd` 0x004619CD cycle-reply
  format, paste falling into the PvP statistics-window toggle, signed-char paste filter.
- [B06](../KNOWN_CLIENT_BUGS.md#character-rules-and-combat-tu_013_eq_character): the social macro `/pause` match in Tick
  (0x00422198).
- [B09, B34](../KNOWN_CLIENT_BUGS.md#text-and-chat-tu_023_systemcommands-tu_051_bad_word_class): the chat-text line splitter (0x0042DE64) and
  `GarbleText_guess` (0x00478F73).
- Not bugs: [B35, B40](../KNOWN_CLIENT_BUGS.md#not-bugs) (profanity test, garble compare); [B18](../KNOWN_CLIENT_BUGS.md#not-bugs) (chat-channel parse).
