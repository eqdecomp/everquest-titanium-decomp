// QUIRK: vc71q-aggregate-copy
// KEYWORDS: struct copy, rep movsd, zero loop, /O1
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: Copy12 has movsd
// EXPECT: Copy32 has rep movsd
// EXPECT: Zero16 has rep stosd
struct S12 { int a,b,c; };
struct S32 { int a[8]; };
void Copy12(S12* d,const S12* s) { *d=*s; }
void Copy32(S32* d,const S32* s) { *d=*s; }
void Zero16(int* p) { for(int i=0;i<16;++i) p[i]=0; }
