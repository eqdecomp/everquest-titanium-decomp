// QUIRK: vc71q-gs-buffer-threshold
// KEYWORDS: /GS, char buffer, cookie, struct, alloca
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: Buffer4 lacks security_cookie
// EXPECT: Buffer8 has security_cookie
// EXPECT: StructBuffer has security_cookie
// EXPECT: AllocaBuffer lacks security_cookie
#include <malloc.h>
extern "C" void UseChar(char*);
int Buffer4() { char b[4]; b[0]=1; UseChar(b); return b[0]; }
int Buffer8() { char b[8]; b[0]=1; UseChar(b); return b[0]; }
struct Record { char bytes[16]; int tag; };
int StructBuffer() { Record r; r.bytes[0]=1; r.tag=2; UseChar(r.bytes); return r.bytes[0]+r.tag; }
int AllocaBuffer(unsigned n) { char* p=(char*)_alloca(n); p[0]=1; UseChar(p); return p[0]; }
