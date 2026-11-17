// QUIRK: vc71q-thiscall-member
// KEYWORDS: thiscall, ECX, member function
// A C++ member function uses ECX for this and returns with callee cleanup, without an explicit calling-convention keyword.
// EXPECT: ThiscallProbe::Add has ^mov eax, dword ptr \[ecx\]
// EXPECT: ThiscallProbe::Add has ret 4
struct ThiscallProbe { int value; int Add(int amount); };
int ThiscallProbe::Add(int amount) { return value + amount; }
