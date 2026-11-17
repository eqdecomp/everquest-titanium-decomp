// QUIRK: vc71q-inline-small-static
// KEYWORDS: inline, static helper, /O1
// At default /O1 this small static helper is inlined. Adding /Ob1 leaves its call in place.
// VARIANTS: DEFAULT OB1
// FLAGS@OB1: /Ob1
// EXPECT@DEFAULT: InlineProbe has lea eax, \[eax \+ eax \+ 2\]
// EXPECT@DEFAULT: InlineProbe lacks call _SmallHelper
// EXPECT@OB1: InlineProbe has call \?SmallHelper
// EXPECT: InlineProbe differs DEFAULT OB1
static int SmallHelper(int value) { return value + 1; }
extern "C" int __cdecl InlineProbe(int value) { return SmallHelper(value) * 2; }
