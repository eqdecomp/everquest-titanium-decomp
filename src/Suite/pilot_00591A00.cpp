// CFLAGS: /O2 /GX /Gy /MT /GR-
struct SuiteState {
    int a0, a4, a8, ac;
    int m10, m14;
    int a18;
    unsigned char bytes[3];
    int a20, a24, a28;
    SuiteState();
};
// FUNCTION: TITANIUM 0x00591A00
SuiteState::SuiteState() {
    a0 = 0;
    a4 = 0;
    a8 = 0;
    ac = 0;
    a18 = 0;
    a20 = 0;
    a24 = 0;
    a28 = 0;
    m10 = -1;
    m14 = -1;
    bytes[0] = 0;
    bytes[1] = 0;
    bytes[2] = 0;
}
