// QUIRK: vc71q-inline-o1
// KEYWORDS: inline, static helper, loop, in-class definition, /O1
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: SmallCaller lacks call
// EXPECT: LoopCaller lacks call
// EXPECT: InClassCaller lacks call
static int SmallHelper(int x) { return x+5; }
int SmallCaller(int x) { return SmallHelper(x)*2; }
static int LoopHelper(int x) { while(x>3) x-=3; return x; }
int LoopCaller(int x) { return LoopHelper(x); }
struct InlineClass { int Add(int x) { return x+9; } };
int InClassCaller(InlineClass* p,int x) { return p->Add(x); }
