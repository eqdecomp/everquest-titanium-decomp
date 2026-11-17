// QUIRK: vc71q-single-use-sinks
// KEYWORDS: div, modulo, forward substitution, single use, null test, sink
// VARIANTS: ONE TWO
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@TWO: T::Next lacks (?s)test eax, eax.*div
// EXPECT@ONE: T::Next has (?s)test eax, eax.*div
// EXPECT: T::Next differs ONE TWO
struct E { unsigned hash; E* next; };
struct T { E** b; int count; E* Next(E* e); };
E* T::Next(E* e) {
    int i = e->hash % count;
    E* n = e->next;
    if (n) return n;
#if defined(TWO)
    int j = i + 1;
    if (i + 1 < count) { for (; j < count; ++j) { n = b[j]; if (n) return n; } }
#else
    for (int j = i + 1; j < count; ++j) { n = b[j]; if (n) return n; }
#endif
    return 0;
}
