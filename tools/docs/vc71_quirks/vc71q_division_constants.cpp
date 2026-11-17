// QUIRK: vc71q-division-constants
// KEYWORDS: arithmetic, signed division, unsigned division, reciprocal multiply, /O1, /O2
// VARIANTS: O1 O2
// FLAGS@O1: /O1
// FLAGS@O2: /O2
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@O1: DivS5 has idiv ecx
// EXPECT@O2: DivS5 lacks idiv ecx
// EXPECT@O2: DivS5 has imul ecx
// EXPECT@O1: DivU5 has div ecx
// EXPECT@O2: DivU5 lacks div ecx
// EXPECT@O2: DivU5 has mul dword ptr
int DivS5(int x) { return x/5; }
unsigned DivU5(unsigned x) { return x/5; }
