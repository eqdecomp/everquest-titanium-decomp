// CFLAGS: /O2 /GX /Gy /MT /GR-
struct SuiteFlags {
    int value;
    unsigned char enabled;
    void Reset();
};
// FUNCTION: TITANIUM 0x005D9920
void SuiteFlags::Reset() {
    try {
        value = 0;
        enabled = 0;
    } catch (...) {
    }
}
