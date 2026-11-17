// CFLAGS: /O2 /GX /Gy /MT /GR-
struct SuiteEntry {
    char reserved[8];
    int value;
};
// FUNCTION: TITANIUM 0x005DACE0
extern "C" int __cdecl EntryValue(SuiteEntry** entry) {
    SuiteEntry* value = *entry;
    int result = 0;
    if (value != 0) {
        result = value->value + 2;
    } else {
        result = 2;
    }
    return result;
}
