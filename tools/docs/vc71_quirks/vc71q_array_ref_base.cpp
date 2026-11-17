// QUIRK: vc71q-array-ref-base
// KEYWORDS: base index, addressing mode, [ecx+eax+N], member array, reference, bounds check, __debugbreak
// VARIANTS: DIRECT DECAY GETTER REF
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@DIRECT: S::f has \[eax \+ ecx \+ 0x1164\]
// EXPECT@DECAY: S::f has \[eax \+ ecx \+ 0x1164\]
// EXPECT@GETTER: S::f has \[eax \+ ecx \+ 0x1164\]
// EXPECT@REF: S::f has \[ecx \+ eax \+ 0x1164\]
// EXPECT: S::f differs DIRECT REF
struct S {
    char pad[0x1164];
    unsigned char a[9];
    unsigned char (&Bytes())[9] { return a; }
    void f(unsigned int i, unsigned char v);
};
void S::f(unsigned int i, unsigned char v) {
#if defined(DIRECT)
    if (i >= 9) __debugbreak();
    a[i] = v;
#elif defined(DECAY)
    if (i >= 9) __debugbreak();
    unsigned char* p = a;
    p[i] = v;
#elif defined(GETTER)
    if (i >= 9) __debugbreak();
    Bytes()[i] = v;
#else
    unsigned char (&r)[9] = a;
    if (i >= 9) __debugbreak();
    r[i] = v;
#endif
}
