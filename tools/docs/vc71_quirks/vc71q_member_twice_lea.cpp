// QUIRK: vc71q-member-spelled-twice-lea
// KEYWORDS: null test, member spelled twice, lea, large displacement, cmp memory
// VARIANTS: TWICE LOCAL
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@TWICE: E::F has lea eax, \[esi \+ 0x104\]
// EXPECT@TWICE: E::F has cmp dword ptr \[eax\], 0
// EXPECT@LOCAL: E::F has test ecx, ecx
// EXPECT: E::F differs TWICE LOCAL
struct V { virtual void S0(); virtual void S1(); };
struct H { void Adv(); };
struct E { char a[0x100]; H h; char b[3]; V* x; void F(); };
void E::F() {
    h.Adv();
#if defined(TWICE)
    if (x != 0) x->S1();
#else
    V* p = x; if (p) p->S1();
#endif
}
