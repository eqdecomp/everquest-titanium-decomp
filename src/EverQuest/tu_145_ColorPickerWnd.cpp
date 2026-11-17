// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 145: a hint from compare/tumap.py.
// CColorPickerWnd (screen "ColorPickerWnd", vtable 0x652CF8): 15 preset colour buttons, a preview
// (button 16), and red/green/blue sliders each paired with a 3-digit edit box. CColorPickerWndView_guess is the window and
// ColorPickerBase_guess its CSidlScreenWnd base; CSliderWnd_guess is CSliderWnd, CEditWnd_guess the edit boxes.
#include "titanium/eqaddr.h"
#include "titanium/types.h"

struct CButtonWndView_guess
{
	char pad_000_guess[0x7c];
	unsigned int field_07c_guess;
	char pad_080_guess[0x13c - 0x80];
	unsigned int color_013c_guess;
};

struct SidlPiece_guess
{
	char pad_000_guess[0x60];
	unsigned int flags_060_guess;
};

struct CSliderWnd_guess;
struct CEditWnd_guess;
struct CColorPickerWndView_guess;

struct ColorPickerBase_guess
{
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess();
	virtual void Slot05_guess();
	virtual void Slot06_guess();
	virtual void Slot07_guess();
	virtual void Slot08_guess();
	virtual void Slot09_guess();
	virtual void Slot0A_guess();
	virtual void Slot0B_guess();
	virtual void Slot0C_guess();
	virtual void Slot0D_guess();
	virtual void Slot0E_guess();
	virtual void Slot0F_guess();
	virtual void Slot10_guess();
	virtual void Slot11_guess();
	virtual void Slot12_guess();
	virtual void Slot13_guess();
	virtual void Slot14_guess();
	virtual void Slot15_guess();
	virtual void Slot16_guess();
	virtual void Slot17_guess();
	virtual void Slot18_guess();
	virtual void Slot19_guess();
	virtual void Slot1A_guess();
	virtual void Slot1B_guess();
	virtual void Slot1C_guess();
	virtual void Slot1D_guess();
	virtual void Slot1E_guess();
	virtual void Slot1F_guess();
	virtual void Slot20_guess();
	virtual void Slot21_guess();
	virtual void Slot22_guess();
	// EXTERNAL: TITANIUM 0x005A3100 ??1ColorPickerBase_guess@@UAE@XZ
	virtual ~ColorPickerBase_guess();
	// EXTERNAL: TITANIUM 0x005A3850 ColorPickerBase_guess::ColorPickerBase_guess
	ColorPickerBase_guess(CXWnd* parent_guess, const CXStr& screen_guess, int flags_guess, int iniVersion_guess, char* blockName_guess);
	// EXTERNAL: TITANIUM 0x005A25B0 ColorPickerBase_guess::CreateChildrenFromSidl
	void CreateChildrenFromSidl();
	// EXTERNAL: TITANIUM 0x005A1E10 ColorPickerBase_guess::GetChildItem
	CXWnd* GetChildItem(const CXStr& name_guess);
	// EXTERNAL: TITANIUM 0x0059DB90 ColorPickerBase_guess::Finish_guess
	void Finish_guess(int value_guess);
	char pad_004_guess[0x64 - 0x04];
	unsigned int windowStyle_064_guess;
	char pad_068_guess[0x124 - 0x068];
	SidlPiece_guess* sidlPiece_124_guess;
	char pad_128_guess[0x15c - 0x128];
};

// EXTERNAL: TITANIUM 0x00652CF8 ??_7CColorPickerWndView_guess@@6B@
struct CColorPickerWndView_guess : ColorPickerBase_guess
{
	char pad_15c_guess[4];
	int limit_160_guess;
	CEditWnd_guess* requester_0164_guess;
	CButtonWndView_guess* colorButtons_0168_guess[16];
	int red_01a8_guess;
	CSliderWnd_guess* redSlider_1ac_guess;
	CEditWnd_guess* redEdit_1b0_guess;
	int green_01b4_guess;
	CSliderWnd_guess* greenSlider_1b8_guess;
	CEditWnd_guess* greenEdit_1bc_guess;
	int blue_01c0_guess;
	CSliderWnd_guess* blueSlider_1c4_guess;
	CEditWnd_guess* blueEdit_1c8_guess;
	void* window_1cc_guess;

	void SetPresetColor_guess(int index_guess, unsigned int value_guess);
	bool clear_guess();
	void pack_fields_guess();
	void UpdateSlidersFromEdits_guess();
	CColorPickerWndView_guess(CXWnd* parent_guess);
	void set_value_guess(unsigned int value_guess);
	void foo_guess(CSliderWnd_guess* inner_guess, CEditWnd_guess* ctl_guess, int* out_guess);
	void bar_guess(CSliderWnd_guess* inner_guess, CEditWnd_guess* ctl_guess, int* out_guess);
	int WndNotification(void* sender_guess, unsigned int message_guess, void* data_guess);
};

struct CXStr;

struct CSliderWnd_guess
{
	// EXTERNAL: TITANIUM 0x005BCB90 CSliderWnd_guess::GetValue_guess
	int GetValue_guess();
	// EXTERNAL: TITANIUM 0x005BCD10 CSliderWnd_guess::Process_guess
	void Process_guess(long value_guess);
	// EXTERNAL: TITANIUM 0x005BD180 CSliderWnd_guess::SetValue_guess
	void SetValue_guess(int value_guess);
};

struct CXStr;

struct CEditWnd_guess
{
	virtual void Slot00_guess();
	virtual void Slot01_guess();
	virtual void Slot02_guess();
	virtual void Slot03_guess();
	virtual void Slot04_guess();
	virtual void Slot05_guess();
	virtual void Slot06_guess();
	virtual void Slot07_guess();
	virtual void Slot08_guess();
	virtual void Slot09_guess();
	virtual void Slot0A_guess();
	virtual void Slot0B_guess();
	virtual void Slot0C_guess();
	virtual void Slot0D_guess();
	virtual void Slot0E_guess();
	virtual void Slot0F_guess();
	virtual void Slot10_guess();
	virtual void Slot11_guess();
	virtual void Slot12_guess();
	virtual void Slot13_guess();
	virtual void Slot14_guess();
	virtual void Slot15_guess();
	virtual void Slot16_guess();
	virtual void Slot17_guess();
	virtual void Slot18_guess();
	virtual void Slot19_guess();
	virtual void Slot1A_guess();
	virtual void Slot1B_guess();
	virtual void Slot1C_guess();
	virtual void Slot1D_guess();
	virtual void Slot1E_guess();
	virtual void Slot1F_guess();
	virtual void Slot20_guess(CColorPickerWndView_guess* owner_guess, int code_guess, unsigned int value_guess);
	virtual void Slot21_guess();
	virtual void Slot22_guess();
	virtual void Slot23_guess();
	virtual void Slot24_guess();
	virtual void Slot25_guess();
	virtual void Slot26_guess();
	virtual void Slot27_guess();
	virtual void Slot28_guess();
	virtual void Slot29_guess();
	virtual void Slot2A_guess();
	virtual void Slot2B_guess();
	virtual void Slot2C_guess();
	virtual void Slot2D_guess();
	virtual void Slot2E_guess();
	virtual void Slot2F_guess();
	virtual void Slot30_guess();
	virtual void Slot31_guess();
	virtual void Slot32_guess();
	virtual void Slot33_guess();
	virtual void Slot34_guess();
	virtual void Slot35_guess();
	virtual void Slot36_guess();
	virtual void Slot37_guess();
	virtual void Slot38_guess();
	virtual void Slot39_guess();
	virtual void Slot3A_guess();
	virtual void Slot3B_guess();
	virtual void Slot3C_guess();
	virtual void Slot3D_guess();
	virtual void Slot3E_guess();
	virtual void Slot3F_guess(CXStr* text_guess);
	virtual void Slot40_guess();
	virtual void Slot41_guess();
	virtual void Slot42_guess();
	virtual void Slot43_guess();
	virtual void Slot44_guess();
	virtual void Slot45_guess();
	virtual void Slot46_guess();
	virtual void Slot47_guess();
	virtual void Slot48_guess();
	virtual void Slot49_guess();
	virtual void Slot4A_guess();
	virtual void Slot4B_guess();
	virtual CXStr Slot4C_guess();
	// EXTERNAL: TITANIUM 0x004D7EBC CEditWnd_guess::SetMaxChars_guess
	void SetMaxChars_guess(int max_guess);
	char pad_004_guess[0x230 - 0x04];
	int field_230_guess;
};

// EXTERNAL: TITANIUM 0x0059DD30 CheckReady_guess
bool __cdecl CheckReady_guess();

// EXTERNAL: TITANIUM 0x0060D5EB _sprintf
int __cdecl _sprintf(char* destination_guess, const char* format_guess, ...);

// CColorPickerWnd constructor: binds the colour buttons (CPW_TC0-15) and the slider/edit pairs.
// FUNCTION: TITANIUM 0x004F83AC
// @early-stop: budget, structural ndiff=36
CColorPickerWndView_guess::CColorPickerWndView_guess(CXWnd* parent_guess)
	: ColorPickerBase_guess(parent_guess, "ColorPickerWnd", 0xfffffeff, 1, 0)
{
	if (sidlPiece_124_guess != 0)
	{
		windowStyle_064_guess |= sidlPiece_124_guess->flags_060_guess | 0x800;
		requester_0164_guess = 0;
		red_01a8_guess = 0;
		green_01b4_guess = 0;
		blue_01c0_guess = 0;
		// Highest channel value an edit box accepts.
		limit_160_guess = 0xff;
		CreateChildrenFromSidl();
		for (int i_guess = 0; i_guess < 16; i_guess++)
		{
			char buffer_guess[64];
			_sprintf(buffer_guess, "CPW_TC%dButton", i_guess);
			CXStr name_guess(buffer_guess);
			colorButtons_0168_guess[i_guess] = (CButtonWndView_guess*)GetChildItem(name_guess);
			// Each button keeps its SIDL colour (+0x7C) as its preset (+0x13C).
			colorButtons_0168_guess[i_guess]->color_013c_guess = colorButtons_0168_guess[i_guess]->field_07c_guess;
		}
		redSlider_1ac_guess = (CSliderWnd_guess*)GetChildItem(CXStr("CPW_RedSlider"));
		redEdit_1b0_guess = (CEditWnd_guess*)GetChildItem(CXStr("CPW_RedSliderInput"));
		greenSlider_1b8_guess = (CSliderWnd_guess*)GetChildItem(CXStr("CPW_GreenSlider"));
		greenEdit_1bc_guess = (CEditWnd_guess*)GetChildItem(CXStr("CPW_GreenSliderInput"));
		blueSlider_1c4_guess = (CSliderWnd_guess*)GetChildItem(CXStr("CPW_BlueSlider"));
		blueEdit_1c8_guess = (CEditWnd_guess*)GetChildItem(CXStr("CPW_BlueSliderInput"));
		// 0x5BD180 with 256, probably the slider range.
		redSlider_1ac_guess->SetValue_guess(0x100);
		greenSlider_1b8_guess->SetValue_guess(0x100);
		blueSlider_1c4_guess->SetValue_guess(0x100);
		window_1cc_guess = GetChildItem(CXStr("CPW_Accept_Button"));
		if (redEdit_1b0_guess != 0)
		{
			redEdit_1b0_guess->field_230_guess = 3;
			redEdit_1b0_guess->SetMaxChars_guess(3);
		}
		if (greenEdit_1bc_guess != 0)
		{
			greenEdit_1bc_guess->field_230_guess = 3;
			greenEdit_1bc_guess->SetMaxChars_guess(3);
		}
		if (blueEdit_1c8_guess != 0)
		{
			blueEdit_1c8_guess->field_230_guess = 3;
			blueEdit_1c8_guess->SetMaxChars_guess(3);
		}
		// 0x59DB90 (Mac map, low: CXWnd::SetZLayer) with 199.
		Finish_guess(199);
	}
}

// EXTERNAL: TITANIUM 0x0060E3A3 atol
long __cdecl atol(const char* value);

// EXTERNAL: TITANIUM 0x005738B0 Format_guess
void __cdecl Format_guess(CXStr* out_guess, const char* format_guess, ...);

// Sets preset colour `index_guess` (0-15).
// FUNCTION: TITANIUM 0x004F8080
void CColorPickerWndView_guess::SetPresetColor_guess(int index_guess, unsigned int value_guess)
{
	if (index_guess >= 0 && index_guess < 16)
		colorButtons_0168_guess[index_guess]->color_013c_guess = value_guess;
}

// CColorPickerWnd::Deactivate (vtable slot 50): forgets the window that asked for a colour.
// FUNCTION: TITANIUM 0x004F80A1
bool CColorPickerWndView_guess::clear_guess()
{
	if (requester_0164_guess != 0)
		requester_0164_guess = 0;
	return true;
}

// Shows the chosen colour on the preview button (16th), alpha forced to 0xFF.
// FUNCTION: TITANIUM 0x004F80B2
void CColorPickerWndView_guess::pack_fields_guess()
{
	colorButtons_0168_guess[15]->color_013c_guess =
		(((red_01a8_guess | 0xffffff00) << 8) |
		 (green_01b4_guess & 0xff)) << 8 |
		(blue_01c0_guess & 0xff);
}

// Moves all three sliders to the edit-box values; a value above the limit (+0x160, 255) is capped and
// written back to its box.
// FUNCTION: TITANIUM 0x004F80EC
void CColorPickerWndView_guess::UpdateSlidersFromEdits_guess()
{
	CXStr text_guess;
	text_guess = redEdit_1b0_guess->Slot4C_guess();
	long value_guess = atol((char*)text_guess);
	if (value_guess > limit_160_guess)
	{
		value_guess = limit_160_guess;
		Format_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C), value_guess);
		redEdit_1b0_guess->Slot3F_guess(&text_guess);
	}
	redSlider_1ac_guess->Process_guess(value_guess);
	text_guess = greenEdit_1bc_guess->Slot4C_guess();
	value_guess = atol((char*)text_guess);
	if (value_guess > limit_160_guess)
	{
		value_guess = limit_160_guess;
		Format_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C), value_guess);
		greenEdit_1bc_guess->Slot3F_guess(&text_guess);
	}
	greenSlider_1b8_guess->Process_guess(value_guess);
	text_guess = blueEdit_1c8_guess->Slot4C_guess();
	value_guess = atol((char*)text_guess);
	if (value_guess > limit_160_guess)
	{
		value_guess = limit_160_guess;
		Format_guess(&text_guess, EQ_ARRAY(char, 0x0063F53C), value_guess);
		blueEdit_1c8_guess->Slot3F_guess(&text_guess);
	}
	blueSlider_1c4_guess->Process_guess(value_guess);
}

// Slider moved: its value goes to the channel field and the paired edit box.
// FUNCTION: TITANIUM 0x004F82A8
void CColorPickerWndView_guess::foo_guess(CSliderWnd_guess* inner_guess, CEditWnd_guess* ctl_guess, int* out_guess)
{
	int value_guess = inner_guess->GetValue_guess();
	*out_guess = value_guess;
	char buffer_guess[32];
	_sprintf(buffer_guess, EQ_ARRAY(char, 0x0063F53C), value_guess);
	CXStr text_guess(buffer_guess);
	ctl_guess->Slot3F_guess(&text_guess);
}

// Edit box changed: its number goes to the channel field and the paired slider, unclamped.
// FUNCTION: TITANIUM 0x004F8326
void CColorPickerWndView_guess::bar_guess(CSliderWnd_guess* inner_guess, CEditWnd_guess* ctl_guess, int* out_guess)
{
	CXStr text_guess;
	text_guess = ctl_guess->Slot4C_guess();
	long value_guess = atol((char*)text_guess);
	*out_guess = value_guess;
	inner_guess->Process_guess(value_guess);
}

// CColorPickerWnd::SetCurrentColor: splits an RGB colour into the three channels and updates sliders,
// edit boxes and preview.
// FUNCTION: TITANIUM 0x004F86D9
void CColorPickerWndView_guess::set_value_guess(unsigned int value_guess)
{
	unsigned int packed_guess = value_guess | 0xff000000;
	red_01a8_guess = (packed_guess & 0xff0000) >> 16;
	green_01b4_guess = (packed_guess & 0xff00) >> 8;
	blue_01c0_guess = packed_guess & 0xff;
	unsigned int hi_guess = red_01a8_guess;
	redSlider_1ac_guess->Process_guess(hi_guess);
	greenSlider_1b8_guess->Process_guess(green_01b4_guess);
	blueSlider_1c4_guess->Process_guess(blue_01c0_guess);
	foo_guess(redSlider_1ac_guess, redEdit_1b0_guess, &red_01a8_guess);
	foo_guess(greenSlider_1b8_guess, greenEdit_1bc_guess, &green_01b4_guess);
	foo_guess(blueSlider_1c4_guess, blueEdit_1c8_guess, &blue_01c0_guess);
	pack_fields_guess();
}

// CColorPickerWnd::WndNotification. Message 10 closes; 0xE (slider or edit change) and 6 (edit
// commit) resync a channel; a click on Accept sends the colour to the requester, on a preset picks it.
// FUNCTION: TITANIUM 0x004F8783
int CColorPickerWndView_guess::WndNotification(void* sender_guess, unsigned int message_guess, void* data_guess)
{
	if (!CheckReady_guess())
		return 0;
	if (message_guess == 10)
		Slot22_guess();
	else
	{
		if (message_guess == 0xe)
		{
			if (sender_guess == redSlider_1ac_guess)
				foo_guess(redSlider_1ac_guess, redEdit_1b0_guess, &red_01a8_guess);
			else if (sender_guess == greenSlider_1b8_guess)
				foo_guess(greenSlider_1b8_guess, greenEdit_1bc_guess, &green_01b4_guess);
			else if (sender_guess == blueSlider_1c4_guess)
				foo_guess(blueSlider_1c4_guess, blueEdit_1c8_guess, &blue_01c0_guess);
			else if (sender_guess == redEdit_1b0_guess || sender_guess == greenEdit_1bc_guess || sender_guess == blueEdit_1c8_guess)
				UpdateSlidersFromEdits_guess();
			pack_fields_guess();
			return 0;
		}
		if (message_guess == 6)
		{
			if (sender_guess == redEdit_1b0_guess)
				bar_guess(redSlider_1ac_guess, redEdit_1b0_guess, &red_01a8_guess);
			else if (sender_guess == greenEdit_1bc_guess)
				bar_guess(greenSlider_1b8_guess, greenEdit_1bc_guess, &green_01b4_guess);
			else if (sender_guess == blueEdit_1c8_guess)
				bar_guess(blueSlider_1c4_guess, blueEdit_1c8_guess, &blue_01c0_guess);
			pack_fields_guess();
			return 0;
		}
		if (message_guess == 1)
		{
			if (sender_guess == window_1cc_guess)
			{
				bar_guess(redSlider_1ac_guess, redEdit_1b0_guess, &red_01a8_guess);
				bar_guess(greenSlider_1b8_guess, greenEdit_1bc_guess, &green_01b4_guess);
				bar_guess(blueSlider_1c4_guess, blueEdit_1c8_guess, &blue_01c0_guess);
				pack_fields_guess();
				if (requester_0164_guess == 0)
					return 0;
				int packed_guess = ((red_01a8_guess | 0xffffff00) << 8 | (green_01b4_guess & 0xff)) << 8 | (blue_01c0_guess & 0xff);
				// Hands 0xFFRRGGBB to the requesting window's WndNotification as message 0x20, then closes.
				requester_0164_guess->Slot20_guess(this, 0x20, packed_guess);
				Slot22_guess();
				return 0;
			}
			// Only the 15 presets: button 16 is the preview.
			for (int i = 0; i < 15; ++i)
			{
				if (sender_guess == colorButtons_0168_guess[i])
				{
					set_value_guess(colorButtons_0168_guess[i]->color_013c_guess);
					return 0;
				}
			}
		}
	}
	return ((CSidlScreenWnd*)this)->WndNotification((CXWnd*)sender_guess, message_guess, data_guess);
}
