// QUIRK: vc71q-index-loop-reduction
// KEYWORDS: index loop, strength reduction, byte offset, global table, dec counter, pointer walk
// VARIANTS: GLOBAL COUNT
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@GLOBAL: F has add esi, 4
// EXPECT@GLOBAL: F has cmp esi, 0xfa0
// EXPECT@COUNT: S::F has dec e
extern int tab[1000];
#if defined(GLOBAL)
char F(int v) {
    for (unsigned i = 0; i < 1000; ++i) { if (tab[i] * tab[i] >= v) break; if (v % tab[i] == 0) return 0; }
    return 1;
}
#else
struct R { int v; };
struct S { int n; R** r; int m; void F(); };
void S::F() {
    int k = 0;
    for (int i = 0; i < n; ++i) { int v = r[i]->v; if (v > k) k = v; }
    m = k;
}

#endif
