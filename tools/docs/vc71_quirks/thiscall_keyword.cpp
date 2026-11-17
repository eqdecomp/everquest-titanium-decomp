// QUIRK: vc71q-thiscall-keyword
// KEYWORDS: thiscall, compiler diagnostic, calling convention
// The explicit __thiscall keyword is rejected by the RTM compiler with C4234; class members still use thiscall implicitly.
// EXPECT: compile fails C4234
struct ThiscallProbe { int value; int __thiscall Add(int amount); };
int __thiscall ThiscallProbe::Add(int amount) { return value + amount; }
