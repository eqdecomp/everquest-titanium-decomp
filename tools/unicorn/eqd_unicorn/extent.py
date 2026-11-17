"""Which instructions belong to the function under test.

The harness treats any basic block that starts outside this set as a call (or tail jump) to another function
and intercepts it. The set comes from a recursive descent with capstone:
  - conditional and direct jumps are followed, calls are not (execution continues after them);
  - `ret`, `int3`, `hlt`, indirect `jmp reg` and `jmp [mem]` (an import thunk / tail call) end a path;
  - a direct jump to, or fall-through onto, a known function start (`stops`) is a tail call, not a branch;
  - an explicit `size` limits the function to [entry, entry + size) instead;
  - VC6 switch tables `jmp [reg*4 + table]` are followed. How many entries the table has:
      1. the immediate of the last `cmp` that is *immediately followed by an unsigned upper-bound jump*
         (ja/jbe/jae/jb): N+1 entries. Any other `cmp` (also `cmp reg,reg`) and any `call` forgets the
         bound, so a stale one from an earlier switch or loop is never used (`cmp eax,-1; je` is no bound);
      2. a byte index table (`mov/movzx r8,[reg+tbl]`, VC6's form for sparse switches), only if it is loaded
         after that bound, its destination is the jump's index register and `tbl` lies inside the image
         (`in_image`): max byte + 1 entries. A struct byte `[esi+0x8FBAC]` has a small disp but is no table;
      3. no bound at all (VC6 omits the range check after `default: __assume(0)`): read entries while they
         point into [entry, table) (with `size`: [entry, entry + size)) and are not other functions' starts
         (at most 1024);
      4. none of these: ExtentError, give `size` (with `size` such a table just yields no cases).
    (CRT memcpy's two tables are the known exception: bounded only by an `and` on another path, they need
    `size`.)
    Pass a list as `switches` to get one `(jmp_va, table, count, how)` per decoded switch jump
    (`how` is "cmp", "bytetable" or "scan").
"""
from __future__ import annotations

import capstone
from capstone import x86_const as X

_MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_MD.detail = True
_UPPER = {"ja", "jbe", "jae", "jb"}
_REG32 = {"al": "eax", "ah": "eax", "ax": "eax", "bl": "ebx", "bh": "ebx", "bx": "ebx", "cl": "ecx",
          "ch": "ecx", "cx": "ecx", "dl": "edx", "dh": "edx", "dx": "edx", "si": "esi", "di": "edi",
          "bp": "ebp", "sp": "esp"}
_NONE = (None, None, None)        # (pending cmp imm, bound, byte table (reg32, va))


class ExtentError(RuntimeError):
    pass


def _reg32(r):
    n = _MD.reg_name(r)
    return _REG32.get(n, n)


def function_extent(read, entry: int, stops=frozenset(), size: int | None = None,
                    max_insns: int = 200000, in_image=None, switches=None) -> set:
    """Return the set of instruction addresses of the function at `entry`.

    `read(va, n) -> bytes` reads the image. `stops` = known function starts other than `entry`.
    `in_image(va) -> bool` says whether an address is inside the image (default: >= 0x10000); pass the PE's
    `contains`. `switches`, if a list, receives `(jmp_va, table, count, how)` for every switch jump.
    """
    lo, hi = (entry, entry + size) if size else (None, None)
    in_image = in_image or (lambda a: a >= 0x10000)
    seen: set = set()
    work = [(entry, _NONE)]
    while work:
        va, (pend, bound, btab) = work.pop()
        while True:
            if va in seen or (va != entry and va in stops):
                break
            if lo is not None and not (lo <= va < hi):
                break
            insn = next(_MD.disasm(read(va, 16), va, 1), None)
            if insn is None:
                break
            seen.add(va)
            if len(seen) > max_insns:
                raise ExtentError(f"function at {entry:#x} exceeds {max_insns} instructions")
            m, ops = insn.mnemonic, insn.operands
            if m == "cmp":                      # any compare starts a new bound (cmp reg,reg -> none)
                imm = len(ops) == 2 and ops[1].type == X.X86_OP_IMM
                pend, bound, btab = (ops[1].imm & 0xFFFFFFFF) if imm else None, None, None
            elif m in ("mov", "movzx") and len(ops) == 2 and ops[0].type == X.X86_OP_REG \
                    and ops[1].type == X.X86_OP_MEM and ops[1].size == 1 and ops[1].mem.scale == 1 \
                    and in_image(ops[1].mem.disp & 0xFFFFFFFF) and bound is not None:
                btab = (_reg32(ops[0].reg), ops[1].mem.disp & 0xFFFFFFFF)
            elif m == "call":
                pend = bound = btab = None
            if m in ("ret", "retf", "int3", "hlt", "ud2", "iretd"):
                break
            if m == "jmp":
                op = ops[0]
                if op.type == X.X86_OP_IMM:
                    va = op.imm & 0xFFFFFFFF
                    continue
                if op.type == X.X86_OP_MEM and op.mem.index != 0 and op.mem.scale == 4 and op.mem.base == 0:
                    table = op.mem.disp & 0xFFFFFFFF
                    idx = _reg32(op.mem.index)
                    if btab is not None and btab[0] == idx and bound is not None and bound < 0x1000:
                        count, how = max(read(btab[1], bound + 1)) + 1, "bytetable"
                    elif bound is not None and bound < 0x1000:
                        count, how = bound + 1, "cmp"
                    else:
                        count = 0
                        while count < 1024:
                            t = int.from_bytes(read(table + 4 * count, 4), "little")
                            if not (entry <= t < (hi if hi is not None else table)) or t in stops:
                                break
                            count += 1
                        how = "scan"
                        if not count and size is None:
                            raise ExtentError(f"switch table at {table:#x} ({va:#x}) has no bound; give `size`")
                    if switches is not None:
                        switches.append((va, table, count, how))
                    for i in range(count):
                        work.append((int.from_bytes(read(table + 4 * i, 4), "little"), _NONE))
                break
                # jmp reg / jmp [mem]: tail call or thunk, ends the path
            if insn.group(capstone.CS_GRP_JUMP):          # jcc, loop, jecxz
                if pend is not None and m in _UPPER:
                    bound = pend
                pend = None
                if ops[0].type == X.X86_OP_IMM:
                    work.append((ops[0].imm & 0xFFFFFFFF, (pend, bound, btab)))
            va += insn.size
    if not seen:
        raise ExtentError(f"nothing decodes at {entry:#x}")
    return seen


FRAGMENTS_JSON = ("tests", "unicorn", "fragments.json")


def load_fragments(repo) -> dict:
    """{fragment VA: head VA} from the repo's tests/unicorn/fragments.json; {} when the repo has none.

    A fragment is an export function start that is really the tail of the function before it (Ghidra split
    it): the head jumps or falls into it and nothing else reaches it. Consumers drop the fragment from the
    function starts, so the head's extent runs on into it and the fragment is no `F:` key. check_fragments
    proves each row against the binary; this loader only checks the file's shape."""
    import json
    from pathlib import Path
    path = Path(repo).joinpath(*FRAGMENTS_JSON)
    if not path.is_file():
        return {}
    data = json.loads(path.read_text(encoding="utf-8"))
    out = {}
    for row in data.get("fragments", []):
        frag, head = int(row["fragment"], 16), int(row["head"], 16)
        if frag <= head:
            raise ExtentError(f"{path}: fragment {frag:#x} is not after its head {head:#x}")
        if frag in out:
            raise ExtentError(f"{path}: fragment {frag:#x} listed twice")
        out[frag] = head
    if set(out) & set(out.values()):
        raise ExtentError(f"{path}: a fragment is also listed as a head")
    return out


def check_fragments(read, starts, frags: dict, in_image=None, annotated=(), others=None) -> list:
    """Problems with the fragment rows `frags` ({fragment: head}); [] when every row holds. A row holds when
    (a) both addresses are known function starts, (b) the head's extent, with the fragment no longer a stop,
    takes in the fragment, (c) no other function's extent reaches the fragment with that stop removed, and
    (d) no `// FUNCTION:` annotation (`annotated`, a set of VAs) names the fragment. `others` = the starts to
    check for (c) (default: all `starts`; a narrower set saves time at the cost of the guarantee)."""
    problems = []
    starts = frozenset(starts)
    merged = starts - set(frags)
    for frag, head in sorted(frags.items()):
        if frag not in starts or head not in starts:
            problems.append(f"{frag:#x}: fragment or head {head:#x} is not a function start")
            continue
        if frag in annotated:
            problems.append(f"{frag:#x}: a // FUNCTION: annotation names it")
        try:
            ext = function_extent(read, head, merged - {head}, in_image=in_image)
        except ExtentError as e:
            problems.append(f"{frag:#x}: head {head:#x} extent fails: {e}")
            continue
        if frag not in ext:
            problems.append(f"{frag:#x}: not reached from its head {head:#x}")
    for va in sorted(others if others is not None else starts):
        if va in frags:
            continue
        try:
            ext = function_extent(read, va, merged - {va}, in_image=in_image)
        except Exception:       # noqa: BLE001 (ExtentError, undecodable code: that function can't reach one)
            continue
        for frag in set(frags) & ext:
            if frags[frag] != va:
                problems.append(f"{frag:#x}: also reached from {va:#x}, not only from its head {frags[frag]:#x}")
    return problems


def seh_seeds(read, entry: int, is_handler3, is_code, max_entries: int = 64) -> list:
    """The `__except` filters and handlers of a function with an `_except_handler3` frame, which nothing but its
    scope table reaches: [] for any other function. The frame is `push -1; push <table>; push <handler3>` within
    the first 6 instructions (`is_handler3(va)`: the pushed address is `_except_handler3`). The table holds
    12-byte entries {enclosing, filter, handler}; it is read while the enclosing index is -1 or an earlier entry
    and both pointers are code (`is_code(va)`; filter 0 = a `__finally`). Seeds = filters and handlers, in
    table order."""
    imms = []
    for insn in _MD.disasm(read(entry, 32), entry, 6):
        imm = insn.mnemonic == "push" and insn.operands[0].type == X.X86_OP_IMM
        imms.append(insn.operands[0].imm & 0xFFFFFFFF if imm else None)
    table = None
    for k in range(len(imms) - 2):
        if imms[k] == 0xFFFFFFFF and imms[k + 1] is not None and imms[k + 2] is not None \
                and is_handler3(imms[k + 2]):
            table = imms[k + 1]
            break
    if table is None:
        return []
    seeds = []
    for i in range(max_entries):
        enc, flt, hnd = (int.from_bytes(read(table + 12 * i + k, 4), "little") for k in (0, 4, 8))
        if not (enc == 0xFFFFFFFF or enc < i) or not is_code(hnd) or (flt and not is_code(flt)):
            break
        seeds += [a for a in (flt, hnd) if a and a not in seeds]
    return seeds


def stack_purge(read, entry: int, stops=frozenset(), in_image=None) -> int | None:
    """Bytes a function pops on return (its `ret N`), from its code: the one N every `ret` in its extent
    agrees on. None when that can't be known: no `ret` reached (a thunk `jmp [IAT]`, a function that never
    returns), `ret`s that disagree, or code that doesn't decode. A lone `jmp` (an ILT-style thunk) is followed
    once. Used to check a fixture's callee stubs (difftest `_check_purges`): a stub that pops a different
    number of bytes than the real callee unbalances the caller's stack."""
    try:
        insn = next(_MD.disasm(read(entry, 16), entry, 1), None)
        if insn is not None and insn.mnemonic == "jmp" and insn.operands[0].type == X.X86_OP_IMM:
            entry = insn.operands[0].imm & 0xFFFFFFFF
        ext = function_extent(read, entry, frozenset(stops) - {entry}, in_image=in_image, max_insns=20000)
    except Exception:           # noqa: BLE001 (ExtentError, unreadable or undecodable code: unknown)
        return None
    pops = set()
    for va in ext:
        i = next(_MD.disasm(read(va, 16), va, 1), None)
        if i is not None and i.mnemonic == "ret":
            pops.add(i.operands[0].imm & 0xFFFF if i.operands else 0)
    return pops.pop() if len(pops) == 1 else None
