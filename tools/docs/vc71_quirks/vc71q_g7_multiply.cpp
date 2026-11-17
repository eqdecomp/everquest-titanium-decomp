// QUIRK: vc71q-g7-multiply
// KEYWORDS: /G7, IMUL, LEA, optimization level
// VARIANTS: O1 O1G7 O2 O2G7
// FLAGS@O1: /O1
// FLAGS@O1G7: /O1 /G7
// FLAGS@O2: /O2
// FLAGS@O2G7: /O2 /G7
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@O1: Mul3 has lea
// EXPECT@O1G7: Mul3 has imul
// EXPECT@O2: Mul7 has imul
// EXPECT@O2G7: Mul7 has lea
// EXPECT@O2G7: Mul7 has sub
int Mul3(int x) { return x*3; }
int Mul7(int x) { return x*7; }
int Mul15(int x) { return x*15; }
