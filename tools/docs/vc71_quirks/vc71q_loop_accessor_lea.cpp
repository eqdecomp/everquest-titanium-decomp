// QUIRK: vc71q-loop-accessor-lea
// KEYWORDS: member object, inline accessor, loop condition, lea, hoist
// VARIANTS: LOOP IF
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@LOOP: L::F has lea esi, \[ecx \+ 4\]
// EXPECT@IF: L::F has mov esi, ecx
// EXPECT: L::F differs LOOP IF
struct N { N* prev; void Done(); };
struct Q { N* head; N* Head() { return head; } void Set(N* e) { head = e; } };
struct L { int a; Q q; void F(); };
void L::F() {
#if defined(LOOP)
    while (q.Head()) { N* e = q.Head(); N* n = e->prev; e->Done(); q.Set(n); }
#else
    if (q.Head()) { N* n; do { N* e = q.Head(); n = e->prev; e->Done(); q.Set(n); } while (n); }
#endif
}
