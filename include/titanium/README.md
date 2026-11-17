# include/titanium: shared headers for the Titanium byte-match

| header | what | include when |
|---|---|---|
| `eqaddr.h` | `EQ_GLOBAL` / `EQ_ARRAY` / `EQ_METHOD` address macros | always (already in every TU) |
| `crt.h` | the VC7.1 CRT headers plus `// EXTERNAL:` markers at the CRT's real VAs | the function calls the C runtime, `new` or `delete` |
| `core_decls.h` | one declaration for each of the ~45 most-called client functions (CXStr, StringTable::getString, CEverQuest::dsp_chat, GetCharInfo2, CXWnd / CListWnd / CSidlScreenWnd / CButtonWnd / CStmlWnd / CXWndManager methods, the 0x00548460 Activate, EQSendMessage) and the globals pEverQuest, pStringTable, pCharData | the function calls one of them |
| `types.h` | sizes checked at compile time (EQPlayer 0x348, EQ_PC 0xC4D0, CEverQuest 0x3A1C8, CSidlScreenWnd 0x15C, CXStr 4, 50 windows) and MQ2 fields that agree with observed offsets; includes `core_decls.h` | the function reads EQPlayer fields or needs a window's size |

Use them in new or edited code; landed `tu_*.cpp` files keep their local declarations until someone edits them.

Rules:
- If a callee's VA is in `core_decls.h`, use that declaration (and its class) instead of writing a local `_guess` one.
  Do not redeclare a header class or function in the TU.
- CRT VAs: use the CRT name (`strcpy`, `atoi`, `delete p`, `new T[n]`) from `crt.h`; never take a CRT name from
  the name list. 0x0060D0D5 is `operator delete` (write `delete p`), 0x0060E07D is `free`, 0x0060E3A3 is `atoi`, not atol.
  A TU that already declares a CRT function itself (`void __cdecl free(void*)` at 0x0060D0D5 and the like) keeps
  that and does not include `crt.h`.
- `__EH_prolog`, `__security_check_cookie`, `__ftol2` and the eh vector iterators are compiler-generated: never
  declare or call them.
- Header classes are layout views without virtual functions (vtable pointer = field/padding at +0). A qualified
  call such as `CSidlScreenWnd::WndNotification(...)` through them is right; a TU that defines a window's ctor,
  dtor or virtual overrides still needs its own class with the virtual slots.
- `~CXStr` is inline (see the comment in `core_decls.h`); the compare needs the alias
  `"??1CXStr@@QAE@XZ": "0x004482FB"` in `tests/unicorn/crt_defaults.json` for the places VC calls it out of line.
  CXStr temporaries come in two shapes; read the original: `push eax` right after the CXStr ctor call
  (EAX = the new string) is the explicit `CXStr(text)` (`list->AddString(CXStr(text), -1, 0, 0)`, 0x0054E242);
  `lea eax,[ebp-N]; push eax` after it is the implicit conversion (`GetChildItem("Yes_Button")`, every
  window ctor's base call and child lookups: 0x00547C3D, 0x0054EFB5, 0x00558521, ...).
- Window ctors (CSidlScreenWnd derivatives) need a local polymorphic base with the real ctor
  (0x005A3900 `(CXWnd*, const CXStr&)` or 0x005A3850 `(CXWnd*, const CXStr&, int, int, char*)`) and dtor
  (0x005A3100) markers and the window's vtable marker; call the header's methods through
  `((CSidlScreenWnd*)this)->GetChildItem(...)`. The proven member layouts are in `types.h`.
- Field types are MQ2's. If the original's movsx/movzx or fld/mov disagrees with a header field, note it; do not cast
  around it.

Checked (scratch copies, compare --match, 2026-11-03): with these headers under `include/` the whole repo compares
exactly as before (2,716 functions, statuses and ndiff unchanged). Rewritten to use them, all identical:
tu_002 (0x00401B42 nested `dsp_chat(getString(..), 0xf, 1)`, 0x00401B65/0x00401BEF/0x00401C53 EQSendMessage,
Activate, 0x00401710 CXStr base+member dtor), tu_013 (19 GetCharInfo2 calls through the EQ_Character base at +4),
tu_046 with `crt.h` (0x004667DC strcpy/memset/getString/dsp_chat/EQSendMessage), tu_205 (0x0054E242 AddString +
SetItemData with a CXStr temporary), tu_234 (0x0056C185/0x0056C1DB GetCurSel/GetItemData/SetSTMLText).
