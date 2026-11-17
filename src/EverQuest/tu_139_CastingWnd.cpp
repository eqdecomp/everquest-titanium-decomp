// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 139: a hint from compare/tumap.py.
// CCastingWnd (screen "CastingWindow", vtable 0x652018), the spell-casting bar: only its constructor
// lives here. CCastingWndView_guess is CCastingWnd (Mac map, high).
#include "titanium/eqaddr.h"
#include "titanium/types.h"

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

// EXTERNAL: TITANIUM 0x00652018 ??_7CCastingWndView_guess@@6B@
struct CCastingWndView_guess : CSidlScreenWndBase
{
	CCastingWndView_guess(CXWnd* parent_guess);
};

// CCastingWnd constructor; like CEQMainWnd (tu_152) it clears CXWnd byte +0x18 after building the children.
// FUNCTION: TITANIUM 0x004EB411
CCastingWndView_guess::CCastingWndView_guess(CXWnd* parent_guess)
	: CSidlScreenWndBase(parent_guess, "CastingWindow")
{
	if (SidlPiece != 0)
	{
		WindowStyle |= SidlPiece->style_guess;
		((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
		field_018_guess = 0;
	}
}
