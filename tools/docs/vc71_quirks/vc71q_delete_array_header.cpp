// QUIRK: vc71q-delete-array-header
// KEYWORDS: delete array, vector deleting destructor, <new>, operator delete[]
// VARIANTS: NO_NEW WITH_NEW
// FLAGS@NO_NEW: /O1
// FLAGS@WITH_NEW: /O1
// CFLAGS: /GS /GX /Gy /MT /GR-
// EXPECT@NO_NEW: ??_EItem@@QAEPAXI@Z has call \?\?3@YAXPAX@Z
// EXPECT@NO_NEW: ??_EItem@@QAEPAXI@Z lacks call \?\?_V@YAXPAX@Z
// EXPECT@WITH_NEW: ??_EItem@@QAEPAXI@Z has call \?\?_V@YAXPAX@Z
#if defined(WITH_NEW)
#include <new>
#endif
struct Item { ~Item(); int value; };
Item::~Item() { value=0; }
void DeleteItems(Item* p) { delete [] p; }
