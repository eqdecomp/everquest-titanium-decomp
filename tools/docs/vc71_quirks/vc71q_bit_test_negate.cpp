// QUIRK: vc71q-bit-test-negate
// KEYWORDS: xor al 0xff, not, bit test, negate, unsigned char, bool argument
// VARIANTS: BYTE CHAR
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@BYTE: F has xor al, 0xff
// EXPECT@BYTE: F has and eax, 0xffffff01
// EXPECT@CHAR: F has not al
// EXPECT: F differs BYTE CHAR
#if defined(BYTE)
typedef unsigned char B;
#else
typedef char B;
#endif
B Get();
void Set(B v);
void F() { Set(!(Get() & 1)); }
