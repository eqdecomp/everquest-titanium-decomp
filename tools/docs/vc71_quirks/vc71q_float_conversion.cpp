// QUIRK: vc71q-float-conversion
// KEYWORDS: float, literal, compare, unordered, int conversion, /O1
// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// EXPECT: FloatZero lacks fldz
// EXPECT: FloatZero has __real@
// EXPECT: FloatOne lacks fld1
// EXPECT: FloatOne has __real@
// EXPECT: FloatLess has fnstsw
// EXPECT: FloatLess has test ah, 5
// EXPECT: FloatToInt has jmp __ftol2
float FloatZero() { return 0.0f; }
float FloatOne() { return 1.0f; }
extern float Bound;
int FloatLess(float x) { return x < Bound; }
int FloatToInt(float x) { return (int)x; }


