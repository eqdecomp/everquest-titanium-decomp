// QUIRK: vc71q-same-tu-effect
// KEYWORDS: same translation unit, ECX, known callee effects, caller/callee
// VARIANTS: SAME EXTERNAL
// FLAGS@SAME: /O1
// FLAGS@EXTERNAL: /O1
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@SAME: Caller has mov edx, ecx
// EXPECT@EXTERNAL: Caller has mov esi, ecx
// EXPECT: Caller differs SAME EXTERNAL
struct Block { int before[24]; int tail[4]; };
#if defined(EXTERNAL)
extern "C" __declspec(noinline) void __fastcall Init(Block* p);
#else
extern "C" __declspec(noinline) void __fastcall Init(Block* p) {
    for (int i=0; i<24; ++i) p->before[i]=0;
}
#endif
extern "C" Block* __fastcall Caller(Block* p) {
    p->tail[0]=0; p->tail[1]=0; p->tail[2]=0; p->tail[3]=0;
    Init(p);
    return p;
}

