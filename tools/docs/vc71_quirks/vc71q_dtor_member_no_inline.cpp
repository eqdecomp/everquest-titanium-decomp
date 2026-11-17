// QUIRK: vc71q-dtor-member-no-inline
// KEYWORDS: scalar deleting destructor, ??_G, inline, member destructor, base destructor
// VARIANTS: PLAIN MEMBER
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@PLAIN: T::Del lacks call \?\?1T
// EXPECT@PLAIN: T::~T has mov dword ptr \[ecx\], \?\?_7T
// EXPECT@MEMBER: T::Del has call \?\?1T
// EXPECT@MEMBER: T::~T has mov dword ptr \[ecx\], \?\?_7T
// EXPECT: T::Del differs PLAIN MEMBER
// EXPECT: T::~T same PLAIN MEMBER
extern "C" void __cdecl free(void*);
struct M { ~M() {} };
struct T {
#if defined(MEMBER)
    M m;
#endif
    virtual ~T();
    T* Del(unsigned char f);
};
T* T::Del(unsigned char f) { this->T::~T(); if (f & 1) free(this); return this; }
T::~T() {}
