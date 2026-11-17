"""Whole-export compare summaries, without requiring a PE or compiler."""
import json
import sys
from pathlib import Path

TOOLS = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(TOOLS / "unicorn"))
sys.path.insert(0, str(TOOLS / "compare"))

import compare  # noqa: E402
import coff  # noqa: E402


def test_baseline_report_counts_functions_and_bytes_by_span():
    functions = [
        {"address": "00401000", "name": "same", "size": 10},
        {"address": "00401010", "name": "normalised", "size": 20},
        {"address": "00401020", "name": "diff", "size": 30},
        {"address": "00401030", "name": "structural", "size": 40},
        {"address": "00401040", "name": "error", "size": 50},
        {"address": "00402000", "name": "unattempted", "size": 60},
    ]
    spans = [
        {"name": "game", "start": "0x00401000", "end": "0x00402000"},
        {"name": "suite", "start": "0x00402000", "end": None},
    ]
    results = [
        compare.Result(0x00401000, "same", "game.cpp", "identical", bytes_identical=True),
        compare.Result(0x00401010, "normalised", "game.cpp", "identical_normalised", bytes_identical=False),
        compare.Result(0x00401020, "diff", "game.cpp", "differs", structural=False),
        compare.Result(0x00401030, "structural", "game.cpp", "differs", structural=True),
        compare.Result(0x00401040, "error", "game.cpp", "error"),
    ]

    report = compare.baseline_report(functions, spans, results, "titanium")
    game = report["spans"][0]
    suite = report["spans"][1]
    assert game["total"] == {"count": 5, "bytes": 150}
    assert game["attempted"] == {"count": 5, "bytes": 150}
    assert [game[k]["count"] for k in ("identical", "normalised", "diff", "structural", "error")] == [1] * 5
    assert suite["total"] == {"count": 1, "bytes": 60} and suite["attempted"]["count"] == 0
    assert report["overall"]["total"] == {"count": 6, "bytes": 210}
    assert report["functions"][-1]["status"] == "unattempted"
    assert "baseline titanium" in compare.baseline_text(report)


def test_baseline_rejects_overlapping_spans_and_unmapped_functions():
    spans = [{"name": "a", "start": "0x1000", "end": "0x2000"},
             {"name": "b", "start": "0x1800", "end": None}]
    try:
        compare.baseline_report([], spans, [], "titanium")
    except ValueError as exc:
        assert "overlaps" in str(exc)
    else:
        raise AssertionError("overlapping spans accepted")
    try:
        compare.baseline_report([{"address": "0x3000", "size": 4}],
                                [{"name": "a", "start": "0x1000", "end": "0x2000"}], [], "titanium")
    except ValueError as exc:
        assert "outside the span table" in str(exc)
    else:
        raise AssertionError("unmapped function accepted")


def test_load_defaults_reads_rewrite_data_aliases(tmp_path):
    path = tmp_path / "crt_defaults.json"
    path.write_text(json.dumps({"rewrite_aliases": {"helper": "0x401000"},
                                "rewrite_data_aliases": {"cookie": "0x402000"}, "link": []}))
    aliases, link = compare.load_defaults(path, tmp_path)
    assert aliases == {"helper": 0x401000}
    assert aliases.data_symbols == {"cookie": 0x402000}
    assert link == []


def test_match_symbols_include_titanium_function_and_data_tokens(tmp_path):
    repo = tmp_path / "eq-titanium"
    source = repo / "src" / "Game" / "match.cpp"
    source.parent.mkdir(parents=True)
    source.write_text("void f() { EQ_CDECL(void, 0x00401000, ())(); "
                      "(void)EQ_GLOBAL(int, 0x00402000); }\n")
    functions, data, problems = compare.match_symbols(repo)
    assert functions == {"0x00401000"}
    assert data == {"0x00402000"}
    assert problems == []
    assert coff.eqd_va("_eqd_fn_0x00401000") == ("fn", 0x00401000)
    assert coff.eqd_va("_eqd_va_0x00402000") == ("va", 0x00402000)


def test_eq_method_template_symbol_maps_to_its_client_va():
    symbol = "?m@?$eqd_tc1@$0EABAFA@HPAUTarget@@H@@QAEHH@Z"
    assert coff.eqd_va(symbol) == ("fn", 0x00401050)
