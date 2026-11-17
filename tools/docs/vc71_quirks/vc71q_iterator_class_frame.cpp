// QUIRK: vc71q-iterator-class-frame
// KEYWORDS: std::find, _Ptrit, iterator class, by-value iterator, EBP frame, copy constructor
// VARIANTS: COPYCTOR PLAIN
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@COPYCTOR: Find has push ebp
// EXPECT@COPYCTOR: Find has mov ecx, dword ptr \[ebp \+ 0xc\]
// EXPECT@PLAIN: Find lacks push ebp
// EXPECT: Find differs COPYCTOR PLAIN
struct It {
    char* cur;
#if defined(COPYCTOR)
    It() {}
    It(const It& o) : cur(o.base()) {}
#endif
    char* base() const { return cur; }
    char& operator*() const { return *cur; }
    It& operator++() { ++cur; return *this; }
    bool operator==(const It& r) const { return cur == r.cur; }
    bool operator!=(const It& r) const { return !(*this == r); }
};
It __cdecl Find(It first, It last, const char& value) {
    for (; first != last; ++first)
        if (*first == value) break;
    return first;
}
