// QUIRK: vc71q-packing
// KEYWORDS: layout, packing, /Zp1, byte array
// /Zp1 removes default padding after a three-byte field and moves following int fields by one byte.
// VARIANTS: DEFAULT PACK1
// FLAGS@PACK1: /Zp1
// EXPECT@DEFAULT: ReadA20 has dword ptr \[eax \+ 0x20\]
// EXPECT@PACK1: ReadA20 has dword ptr \[eax \+ 0x1f\]
// EXPECT: ReadA20 differs DEFAULT PACK1
struct SuiteState {
    int a0, a4, a8, ac;
    int m10, m14;
    int a18;
    unsigned char bytes[3];
    int a20, a24, a28;
};
int ReadA20(SuiteState* state) { return state->a20; }
