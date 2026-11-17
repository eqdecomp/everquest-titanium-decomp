// QUIRK: vc71q-ebp-frame-refs
// KEYWORDS: EBP frame, no locals, parameter references, /O1 size, cached local
// VARIANTS: REPEATED CACHED
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@REPEATED: Sel has push ebp
// EXPECT@REPEATED: Sel has mov eax, dword ptr \[ebp \+ 8\]
// EXPECT@CACHED: Sel lacks push ebp
// EXPECT@CACHED: Sel has dword ptr \[esp \+ 4\]
// EXPECT: Sel differs REPEATED CACHED
int __stdcall Sel(int kind, char a, char b) {
#if defined(CACHED)
    int i = kind - 1;
    if (!a) {
        if (!b) return i == 0 ? 0x2163 : 0x215e;
        return i == 0 ? 0x2161 : 0x215c;
    }
    return i == 0 ? 0x2162 : 0x215d;
#else
    if (!a) {
        if (!b) return kind == 1 ? 0x2163 : 0x215e;
        return kind == 1 ? 0x2161 : 0x215c;
    }
    return kind == 1 ? 0x2162 : 0x215d;
#endif
}
