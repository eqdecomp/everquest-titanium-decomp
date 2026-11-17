// QUIRK: vc71q-byvalue-arg-temp
// KEYWORDS: by-value argument, temporary, mov ecx esp, destructor, copy constructor
// VARIANTS: DTOR PLAIN
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@DTOR: Owner::Fwd has mov ecx, esp
// EXPECT@DTOR: Owner::Fwd has mov dword ptr \[esp \+ 0x10\], esp
// EXPECT@PLAIN: Owner::Fwd lacks mov dword ptr \[esp
// EXPECT: Owner::Fwd differs DTOR PLAIN
struct Str {
    int p;
    Str(const char* s);
#if defined(DTOR)
    ~Str();
#endif
};
struct Sink { void Set(Str s, int a, int b); };
struct Owner { char pad[0x5c8]; Sink* s; void Fwd(); };
void Owner::Fwd() { if (s) s->Set("x", 1, 0); }
