// QUIRK: vc71q-eh-state
// KEYWORDS: EH, state store, __EH_prolog, destructor
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: EhWithCxxCall has __EH_prolog
// EXPECT: EhWithCxxCall has CxxMayThrow
// EXPECT: EhWithCxxCall has and dword ptr
// EXPECT: EhWithCxxCall has or dword ptr
struct Guarded { Guarded(); ~Guarded(); int value; };
int CxxMayThrow();
int EhWithCxxCall() { Guarded g; return CxxMayThrow()+g.value; }


