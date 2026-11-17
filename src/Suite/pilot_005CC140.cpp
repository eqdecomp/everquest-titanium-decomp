// CFLAGS: /O2 /GX /Gy /MT /GR-
struct SuiteSubobject {
    SuiteSubobject();
    ~SuiteSubobject();
};
struct SuiteWidget {
    virtual void VTableAnchor() {}
    char gap[0xe8];
    SuiteSubobject child;
    void Initialize();
    SuiteWidget();
};
// FUNCTION: TITANIUM 0x005CC140
SuiteWidget::SuiteWidget() : child() {
    Initialize();
}
