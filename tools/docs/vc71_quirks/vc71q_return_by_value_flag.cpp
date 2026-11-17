// QUIRK: vc71q-return-flag
// KEYWORDS: return by value, hidden return pointer, EBP frame, zeroed local, destructor
// VARIANTS: DTOR PLAIN
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@DTOR: Owner::Get has push ebp
// EXPECT@DTOR: Owner::Get has and dword ptr \[ebp - 4\], 0
// EXPECT@DTOR: Owner::Get has mov eax, dword ptr \[ebp \+ 8\]
// EXPECT@PLAIN: Owner::Get lacks push ebp
// EXPECT@PLAIN: Owner::Get lacks and dword ptr
// EXPECT: Owner::Get differs DTOR PLAIN
struct Str {
    int p;
    Str(const Str& o);
#if defined(DTOR)
    ~Str();
#endif
};
struct Owner { char pad[0x184]; Str name; Str Get(); };
Str Owner::Get() { return name; }
