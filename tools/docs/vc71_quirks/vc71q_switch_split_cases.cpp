// QUIRK: vc71q-switch-split-cases
// KEYWORDS: switch, dec chain, sub reg, split case bodies, merged labels
// VARIANTS: SPLIT MERGED
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@SPLIT: F has sub ecx, eax
// EXPECT@SPLIT: F count dec ecx == 2
// EXPECT@MERGED: F lacks sub ecx, eax
// EXPECT: F differs SPLIT MERGED
int __stdcall F(int code) {
    int r = 0;
    switch (code) {
#if defined(SPLIT)
    case 0: r = 1; break;
    case 1: r = 1; break;
#else
    case 0:
    case 1: r = 1; break;
#endif
    case 2: r = 0x13; break;
    }
    return r;
}
