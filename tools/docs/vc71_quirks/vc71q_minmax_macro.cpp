// QUIRK: vc71q-minmax-macro
// KEYWORDS: min, max, macro, clamp, repeated compare, redundant bound check
// VARIANTS: MACRO PLAIN
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@MACRO: Clamp count cmp eax, 4 == 2
// EXPECT@MACRO: Clamp has cmp eax, 0x60
// EXPECT@PLAIN: Clamp count cmp eax, 4 == 1
// EXPECT: Clamp differs MACRO PLAIN
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
void __stdcall Sink(int a, int b);
void __stdcall Clamp(int v) {
#if defined(MACRO)
    Sink(0x2a, min(0x60, max(4, v)));
#else
    if (v < 4) v = 4; else if (v > 0x60) v = 0x60;
    Sink(0x2a, v);
#endif
}
