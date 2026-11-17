r"""fragments.json: a split-off tail joins its head's extent, and a row that the binary does not prove is refused
(no game files needed).

Run: .venv\Scripts\python.exe -m pytest eq-titanium\tools\tests\unicorn\test_fragments.py
"""
import json
import struct
import sys
from pathlib import Path
from types import SimpleNamespace

import pytest

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "unicorn"))
sys.path.insert(0, str(ROOT / "compare"))
sys.path.insert(0, str(ROOT / "queue"))

from eqd_unicorn.extent import ExtentError, check_fragments, function_extent, load_fragments  # noqa: E402
from eqd_unicorn.pe import Image  # noqa: E402

import compare as C  # noqa: E402
import queuelib as q  # noqa: E402

B = 0x00500000
HEAD, FUNCLET, FRAG, OTHER, LONE = B, B + 4, B + 6, B + 8, B + 14


def image(other_jumps_in: bool):
    code = bytearray()
    code += b"\x31\xC0"                         # HEAD: xor eax,eax
    code += b"\xEB\x02"                         #       jmp FRAG (over the funclet)
    code += b"\xC3\x90"                         # FUNCLET: ret; nop (a Catch@ block returns its continuation)
    code += b"\x40\xC3"                         # FRAG: inc eax; ret
    if other_jumps_in:                          # OTHER: jmp FRAG (a shared tail: no fragment)
        code += b"\xE9" + struct.pack("<i", FRAG - (OTHER + 5))
    else:                                       # OTHER: mov eax,1
        code += b"\xB8\x01\x00\x00\x00"
    code += b"\xC3"                             # ret
    code += b"\xC3"                             # LONE: ret (nothing reaches it)
    return Image.from_bytes("t", B, bytes(code))


STARTS = frozenset({HEAD, FUNCLET, FRAG, OTHER, LONE})


def write(tmp_path, rows):
    d = tmp_path / "tests" / "unicorn"
    d.mkdir(parents=True, exist_ok=True)
    (d / "fragments.json").write_text(json.dumps({"schema_version": 1, "fragments": [
        {"fragment": f"0x{f:08X}", "head": f"0x{h:08X}"} for f, h in rows]}), encoding="utf-8")
    return tmp_path


def test_head_extent_takes_the_fragment_once_it_is_no_stop():
    img = image(False)
    assert FRAG not in function_extent(img.read, HEAD, STARTS - {HEAD}, in_image=img.contains)
    ext = function_extent(img.read, HEAD, STARTS - {HEAD, FRAG}, in_image=img.contains)
    assert {FRAG, FRAG + 1} <= ext and FUNCLET not in ext


def test_loader(tmp_path):
    assert load_fragments(tmp_path) == {}
    assert load_fragments(write(tmp_path, [(FRAG, HEAD)])) == {FRAG: HEAD}
    with pytest.raises(ExtentError):
        load_fragments(write(tmp_path, [(HEAD, FRAG)]))           # fragment before its head
    with pytest.raises(ExtentError):
        load_fragments(write(tmp_path, [(FRAG, HEAD), (FRAG, HEAD)]))


def test_check_accepts_a_proven_row():
    img = image(False)
    assert check_fragments(img.read, STARTS, {FRAG: HEAD}, img.contains) == []


def test_check_refuses_a_shared_tail():
    img = image(True)
    probs = check_fragments(img.read, STARTS, {FRAG: HEAD}, img.contains)
    assert any("also reached from" in p for p in probs)


def test_check_refuses_an_unreached_and_an_annotated_fragment():
    img = image(False)
    assert any("not reached" in p for p in check_fragments(img.read, STARTS, {LONE: HEAD}, img.contains))
    assert any("annotation" in p for p in check_fragments(img.read, STARTS, {FRAG: HEAD}, img.contains,
                                                           annotated={FRAG}))
    assert any("not a function start" in p for p in check_fragments(img.read, STARTS - {FRAG}, {FRAG: HEAD},
                                                                     img.contains))


def _ws(tmp_path):
    exp = tmp_path / "build" / "export" / "titanium"
    exp.mkdir(parents=True)
    fns = [{"address": f"{va:08X}", "size": n, "instructions": i, "class": c} for va, n, i, c in
           ((HEAD, 4, 2, "unnamed"), (FUNCLET, 2, 1, "eh_funclet"), (FRAG, 2, 2, "unnamed"),
            (OTHER, 6, 2, "unnamed"), (LONE, 1, 1, "unnamed"))]
    (exp / "functions.json").write_text(json.dumps({"functions": fns}), encoding="utf-8")
    return SimpleNamespace(build=tmp_path / "build"), fns


def test_function_starts_drop_fragments_only_when_listed(tmp_path):
    ws, _ = _ws(tmp_path)
    repo = tmp_path / "repo"
    repo.mkdir()
    assert C.function_starts(ws, "titanium", repo) == set(STARTS)         # no fragments.json: unchanged
    write(repo, [(FRAG, HEAD)])
    assert C.function_starts(ws, "titanium", repo) == set(STARTS) - {FRAG}


def test_merged_spans_cover_funclets_and_fragments(tmp_path):
    _, fns = _ws(tmp_path)
    assert q.merged_spans(fns, {FRAG: HEAD}) == {f"{HEAD:08X}": (8, 5)}
    assert q.merged_spans(fns, {}) == {}
