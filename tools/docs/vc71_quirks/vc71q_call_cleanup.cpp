// QUIRK: vc71q-call-cleanup
// KEYWORDS: call cleanup, add esp, pop ecx, /O1, same translation unit
// VARIANTS: SAME EXTERNAL
// FLAGS@SAME: /O1
// FLAGS@EXTERNAL: /O1
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@SAME: CleanupLiteral has add esp, 4
// EXPECT@EXTERNAL: CleanupLiteral has pop ecx
// EXPECT: CleanupLiteral differs SAME EXTERNAL
#if defined(EXTERNAL)
extern "C" __declspec(noinline) int One(int);
#else
extern "C" __declspec(noinline) int One(int x) { return x*9+1; }
#endif
extern "C" int CleanupLiteral() { return One(7); }
