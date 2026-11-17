// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 218: a hint from compare/tumap.py.
// CSystemInfoDialogBox (screen "SystemInfoDialogBox", vtable 0x65D3C8): a Yes/No box with a text pane; only
// the constructor lives here. CSidlScreenWndView_guess is its CSidlScreenWnd base (ctor 0x5A3900, MQ2); stateWnd_guess
// (+0x124) is the SidlPiece.
#include "titanium/eqaddr.h"

#include "titanium/core_decls.h"
struct CSidlScreenWndView_guess {
	virtual void Slot00_guess();
	char unknown_004_guess[0x5c];
	unsigned int field_060_guess;
	unsigned int flags_guess;
	char unknown_068_guess[0x49];
	unsigned char fades_00b1_guess;
	char unknown_0b2_guess[0x72];
	CSidlScreenWndView_guess* sidlPiece_0124_guess;
	char unknown_128_guess[0x34];
	// EXTERNAL: TITANIUM 0x005A3900 CSidlScreenWndView_guess::CSidlScreenWndView_guess
	CSidlScreenWndView_guess(CSidlScreenWndView_guess* parent, const CXStr& name);
	// EXTERNAL: TITANIUM 0x005A3100 CSidlScreenWndView_guess::~CSidlScreenWndView_guess
	virtual ~CSidlScreenWndView_guess();
	// EXTERNAL: TITANIUM 0x005A25B0 CSidlScreenWndView_guess::CreateChildrenFromSidl
	void CreateChildrenFromSidl();
	// EXTERNAL: TITANIUM 0x005A1E10 CSidlScreenWndView_guess::GetChildItem
	struct CXWnd* GetChildItem(const CXStr& name);
};

struct CSystemInfoDialogBox_guess : CSidlScreenWndView_guess {
	virtual void Slot00_guess();
	CXWnd* yesButton_guess;
	CXWnd* noButton_guess;
	CXWnd* textOutput_guess;
	CSystemInfoDialogBox_guess(CSidlScreenWndView_guess* parent);
	// EXTERNAL: TITANIUM 0x0059DB90 CSystemInfoDialogBox_guess::Delay_guess
	void Delay_guess(int milliseconds);
	// EXTERNAL: TITANIUM 0x0065D3C8 ??_7CSystemInfoDialogBox_guess@@6B@
};


// CSystemInfoDialogBox::CSystemInfoDialogBox: finds Yes_Button, No_Button and TextOutput and fills the
// text with string 0xD0C. TextOutput (+0x164) is not zeroed first, unlike the two buttons.
// FUNCTION: TITANIUM 0x0055B4D1
CSystemInfoDialogBox_guess::CSystemInfoDialogBox_guess(CSidlScreenWndView_guess* parent)
	: CSidlScreenWndView_guess(parent, "SystemInfoDialogBox")
{
	yesButton_guess = 0;
	noButton_guess = 0;
	if (sidlPiece_0124_guess != 0) {
		flags_guess |= sidlPiece_0124_guess->field_060_guess;
		CreateChildrenFromSidl();
		fades_00b1_guess = 0;
		yesButton_guess = GetChildItem("Yes_Button");
		noButton_guess = GetChildItem("No_Button");
		textOutput_guess = GetChildItem("TextOutput");
		if (textOutput_guess != 0) {
			textOutput_guess->SetWindowTextA(pStringTable->getString(0x0d0c, 0));
		}
		// 0x59DB90 with 200 is probably the Z layer (Mac SetZLayer, low), not a delay.
		Delay_guess(200);
	}
}

