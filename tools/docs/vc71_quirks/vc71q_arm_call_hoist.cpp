// QUIRK: vc71q-arm-call-hoist
// KEYWORDS: if else, argument push, hoist, tail merge, ternary, shared call
// VARIANTS: ARMS TERNARY
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@ARMS: F has (?s)push 1.*jle
// EXPECT@ARMS: F lacks setle
// EXPECT@TERNARY: F has setle
// EXPECT: F differs ARMS TERNARY
const char* Get(int id);
void Show(const char* t, int color, int flag);
void F(int v) {
#if defined(ARMS)
    if (v > 0) Show(Get(0xd17), 0xd, 1); else Show(Get(0xd1a), 0xf, 1);
#else
    Show(Get(v > 0 ? 0xd17 : 0xd1a), v > 0 ? 0xd : 0xf, 1);
#endif
}
