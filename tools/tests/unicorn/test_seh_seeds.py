r"""extent.seh_seeds: an `_except_handler3` frame's filters and handlers, found through its scope table (no game
files needed).

Run: .venv\Scripts\python.exe -m pytest eq-titanium\tools\tests\unicorn\test_seh_seeds.py
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "unicorn"))

from eqd_unicorn.extent import function_extent, seh_seeds  # noqa: E402
from eqd_unicorn.pe import Image  # noqa: E402

B = 0x00500000
H3 = 0x00612944                         # the client's _except_handler3 (not in this image)
FILTER, HANDLER, TABLE, PLAIN = B + 0x20, B + 0x24, B + 0x100, B + 0x30


def image(second_entry=b""):
    code = bytearray(0x200)
    body = b"\x55\x8B\xEC\x6A\xFF" + b"\x68" + struct.pack("<I", TABLE) + b"\x68" + struct.pack("<I", H3) + b"\xC9\xC3"
    code[0:len(body)] = body                                    # push ebp; mov ebp,esp; push -1; push T; push H3
    code[FILTER - B:FILTER - B + 4] = b"\x33\xC0\x40\xC3"        # filter: xor eax,eax; inc eax; ret
    code[HANDLER - B:HANDLER - B + 1] = b"\xC3"                  # handler: ret
    code[PLAIN - B:PLAIN - B + 4] = b"\x55\x8B\xEC\xC3"          # no frame
    table = struct.pack("<iII", -1, FILTER, HANDLER) + second_entry + b"EverQuest!!!"
    code[TABLE - B:TABLE - B + len(table)] = table
    img = Image.from_bytes("t", B, bytes(code))
    img.code_ranges = [(B, 0x100)]                              # the table is data
    return img


def is_code(img):
    return lambda a: any(lo <= a < lo + n for lo, n in img.code_ranges)


def test_seeds_are_filter_and_handler_and_stop_at_data():
    img = image()
    seeds = seh_seeds(img.read, B, lambda a: a == H3, is_code(img))
    assert seeds == [FILTER, HANDLER]
    assert FILTER + 3 in function_extent(img.read, FILTER, frozenset(), in_image=img.contains)


def test_nested_entry_and_finally():
    img = image(struct.pack("<iII", 0, 0, PLAIN))              # entry 1: inside entry 0, __finally (no filter)
    assert seh_seeds(img.read, B, lambda a: a == H3, is_code(img)) == [FILTER, HANDLER, PLAIN]


def test_no_frame_or_other_handler_gives_nothing():
    img = image()
    assert seh_seeds(img.read, PLAIN, lambda a: a == H3, is_code(img)) == []
    assert seh_seeds(img.read, B, lambda a: False, is_code(img)) == []
