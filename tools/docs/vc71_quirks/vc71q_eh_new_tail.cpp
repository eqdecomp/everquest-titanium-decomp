// QUIRK: vc71q-eh-new-tail
// KEYWORDS: EH, new, static guard, tail call, bit test, value initialization, NRVO
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: EhCLinkageCall lacks __EH_prolog
// EXPECT: NewGuarded has __EH_prolog
// EXPECT: TailWrap has jmp _Tail
// EXPECT: BitShift has sar eax, 5
// EXPECT: BitMask has shr eax, 5
// EXPECT: NewValue has stosd
// EXPECT: NewPlain lacks stosd
// EXPECT: StaticGuard has test byte ptr
// EXPECT: StaticGuard has or dword ptr
extern "C" int __cdecl Tail(int);
extern "C" int CxxMayThrow();
extern "C" int InitValue();
int TailWrap(int x) { return Tail(x); }
int BitShift(int x) { return (x>>5)&1; }
int BitMask(int x) { return (x&0x20)!=0; }
int StaticGuard() { static int value=InitValue(); return value; }
struct Plain { int x; };
void NewPlain(Plain** p) { *p=new Plain; }
void NewValue(Plain** p) { *p=new Plain(); }
struct Guarded { Guarded(); ~Guarded(); int value; };
int EhCLinkageCall() { Guarded g; return CxxMayThrow()+g.value; }
void NewGuarded(Guarded** p) { *p=new Guarded; }
struct Returnable { Returnable(); Returnable(const Returnable&); ~Returnable(); int x; };
Returnable ReturnByValue() { Returnable r; r.x=1; return r; }



