// CFLAGS: /O2 /GX /Gy /MT /GR-
struct SuiteChild {
    bool IsActive();
};
struct SuiteOwner {
    char beforeChild[0x28];
    SuiteChild* child;
    char beforeFlag[0x30];
    unsigned char enabled;
    bool IsActive();
};
// FUNCTION: TITANIUM 0x0059FEC0
bool SuiteOwner::IsActive() {
    if (enabled == 0) {
        return false;
    }
    SuiteChild* current = child;
    if (current != 0) {
        return current->IsActive();
    }
    return true;
}
