#include <string.h>
// QUIRK: vc71q-intrinsic-oi
// KEYWORDS: /Oi, memset, strcpy, strlen, intrinsic
// VARIANTS: BASE OI
// FLAGS@BASE: /O1
// FLAGS@OI: /O1 /Oi
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@BASE: Set16 has call _memset
// EXPECT@OI: Set16 lacks call _memset
// EXPECT@OI: Set16 count stosd == 4
// EXPECT@BASE: CopyLiteral has call _strcpy
// EXPECT@OI: CopyLiteral lacks call _strcpy
// EXPECT@OI: CopyLiteral has mov dword ptr
// EXPECT@BASE: LiteralLength has call _strlen
// EXPECT@OI: LiteralLength lacks call _strlen
// EXPECT@OI: LiteralLength has (push 3|mov eax, 3)
int Set16(char* p) { memset(p,0,16); return p[0]; }
char* CopyLiteral(char* p) { return strcpy(p,"abc"); }
int LiteralLength() { return (int)strlen("abc"); }





