// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Split from the head of tumap object 73: the leadership ability definition (one of LeadershipManager_guess's 31
// elements, tu_073). The original builds an EH frame around `new MenuSelection_guess(i)` in 0x4B3F48, so it could
// not see this constructor (seen, it is nothrow and the frame goes).
#include "titanium/types.h"

struct MenuSelection_guess {
	int first_guess;
	int second_guess;
	int third_guess;
	int fourth_guess;
	int fifth_guess;
	int sixth_guess;
	int seventh_guess;
	int eighth_guess;
	int pad20_guess;
	int type_guess;
	int state_guess;
	int flag0_guess;
	int flag1_guess;
	int category_guess;
	unsigned char enabled_guess;
	MenuSelection_guess(unsigned int index);
};

// Definition of leadership ability `index`: name and description string ids (+0, +4), +8 (1 or 3), three rank
// texts (+0xC to +0x14), cost text (+0x18), extra text (+0x1C), cost base +0x24 and step +0x28, kind +0x2C
// (1 group, 2 raid), +0x30, rank cap +0x34, purchasable +0x38. Unknown ids get 0x4C0.
// FUNCTION: TITANIUM 0x004B3898
MenuSelection_guess::MenuSelection_guess(unsigned int index)
{
	first_guess = -1;
	second_guess = -1;
	seventh_guess = -1;
	eighth_guess = -1;
	fourth_guess = -1;
	fifth_guess = -1;
	sixth_guess = -1;
	third_guess = 1;
	type_guess = 1;
	state_guess = 0;
	category_guess = 1;
	flag0_guess = 0;
	flag1_guess = 0;

	// One case per ability id 0-30; the string ids point into the leadership block of eqstr (8558 up).
	switch (index) {
	case 0:
		first_guess = 0x216e; second_guess = 0x216f; third_guess = 3;
		fourth_guess = 0x2190; fifth_guess = 0x2191; sixth_guess = 0x2192;
		seventh_guess = 0x2229; category_guess = 3; type_guess = 3;
		state_guess = 1; flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 1:
		first_guess = 0x2170; second_guess = 0x2171; seventh_guess = 0x21d2;
		type_guess = 2; flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 2:
		first_guess = 0x2172; second_guess = 0x2173; third_guess = 3;
		fourth_guess = 0x2198; fifth_guess = 0x2199; sixth_guess = 0x219a;
		seventh_guess = 0x2229; category_guess = 3; type_guess = 3;
		state_guess = 1; flag0_guess = 1; flag1_guess = 1; enabled_guess = 0;
		break;
	case 3:
		first_guess = 0x2174; second_guess = 0x2175;
		fourth_guess = 0x219b; fifth_guess = 0x219c; sixth_guess = 0x219d;
		seventh_guess = 0x21d0; category_guess = 1; type_guess = 4;
		state_guess = 0; flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 4:
		first_guess = 0x21fd; second_guess = 0x21fe;
		fourth_guess = 0x21ff; fifth_guess = 0x2200; sixth_guess = 0x2201;
		eighth_guess = 0x2259; seventh_guess = 0x21d0; category_guess = 1;
		type_guess = 4; state_guess = 0; flag0_guess = 1; flag1_guess = 1;
		enabled_guess = 1;
		break;
	case 5:
		first_guess = 0x2207; second_guess = 0x2208;
		fourth_guess = 0x2209; fifth_guess = 0x220a; sixth_guess = 0x220b;
		eighth_guess = 0x225b; category_guess = 1; type_guess = 4;
		state_guess = 0; seventh_guess = 0x21d0;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 0;
		break;
	case 6:
		first_guess = 0x217a; second_guess = 0x217b;
		fourth_guess = 0x219e; fifth_guess = 0x219f; sixth_guess = 0x21a0;
		seventh_guess = 0x21d2; category_guess = 2; type_guess = 4;
		state_guess = 2; flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 7:
		first_guess = 0x2211; second_guess = 0x2212; seventh_guess = 0x21d2;
		category_guess = 5; type_guess = 4; state_guess = 1;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 0;
		break;
	case 8:
		first_guess = 0x2213; second_guess = 0x2214; seventh_guess = 0x21d2;
		type_guess = 6; flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 9:
		first_guess = 0x2215; second_guess = 0x2216; seventh_guess = 0x21d2;
		category_guess = 5; type_guess = 4; state_guess = 1;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 10:
		first_guess = 0x2217; second_guess = 0x2218; seventh_guess = 0x21d2;
		category_guess = 3; type_guess = 4; state_guess = 2;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 11:
		first_guess = 0x2219; second_guess = 0x221a; seventh_guess = 0x21d2;
		category_guess = 3; type_guess = 4; state_guess = 2;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 12:
		first_guess = 0x221b; second_guess = 0x221c; seventh_guess = 0x21d2;
		category_guess = 3; type_guess = 4; state_guess = 2;
		flag0_guess = 1; flag1_guess = 1; enabled_guess = 1;
		break;
	case 13:
		first_guess = 0x217e; second_guess = 0x217f;
		fourth_guess = 0x21a1; fifth_guess = 0x21a2; sixth_guess = 0x21a3;
		seventh_guess = 0x21d2; type_guess = 4; flag0_guess = 1;
		flag1_guess = 1; enabled_guess = 1;
		break;
	case 14:
		first_guess = 0x2193; second_guess = 0x2194;
		fourth_guess = 0x2195; fifth_guess = 0x2196; sixth_guess = 0x2197;
		seventh_guess = 0x21d2; type_guess = 7; flag0_guess = 1;
		flag1_guess = 1; enabled_guess = 1;
		break;
	case 15:
		first_guess = 0x2180; second_guess = 0x2181;
		fourth_guess = 0x21a4; fifth_guess = 0x21a5; sixth_guess = 0x21a6;
		type_guess = 8; seventh_guess = 0x21d0; flag0_guess = 1;
		flag1_guess = 1; enabled_guess = 0;
		break;
	case 16:
		first_guess = 0x21d8; second_guess = 0x21d9; third_guess = 3;
		fourth_guess = 0x21da; fifth_guess = 0x21db; sixth_guess = 0x21dc;
		seventh_guess = 0x222a; category_guess = 3; type_guess = 5;
		state_guess = 1; flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 17:
		first_guess = 0x21a7; second_guess = 0x21a8; type_guess = 4;
		seventh_guess = 0x21d3; flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 18:
		first_guess = 0x21ac; second_guess = 0x21ad; third_guess = 3;
		fourth_guess = 0x21ae; fifth_guess = 0x21af; sixth_guess = 0x21b0;
		seventh_guess = 0x222a; type_guess = 5; category_guess = 3;
		state_guess = 1; flag0_guess = 2; flag1_guess = 2; enabled_guess = 0;
		break;
	case 19:
		first_guess = 0x21dd; second_guess = 0x21de;
		fourth_guess = 0x21df; fifth_guess = 0x21e0; sixth_guess = 0x21e1;
		seventh_guess = 0x21d1; category_guess = 3; type_guess = 6;
		state_guess = 1; flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 20:
		first_guess = 0x2202; second_guess = 0x2203;
		fourth_guess = 0x2204; fifth_guess = 0x2205; sixth_guess = 0x2206;
		seventh_guess = 0x21d1; eighth_guess = 0x225a; category_guess = 3;
		type_guess = 6; state_guess = 0; flag0_guess = 2; flag1_guess = 2;
		enabled_guess = 1;
		break;
	case 21:
		first_guess = 0x220c; second_guess = 0x220d;
		fourth_guess = 0x220e; fifth_guess = 0x220f; sixth_guess = 0x2210;
		eighth_guess = 0x225c; category_guess = 3; type_guess = 6;
		state_guess = 0; seventh_guess = 0x21d1;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 0;
		break;
	case 22:
		first_guess = 0x221d; second_guess = 0x221e; seventh_guess = 0x21d3;
		type_guess = 5; category_guess = 5; state_guess = 1;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 0;
		break;
	case 23:
		first_guess = 0x221f; second_guess = 0x2220; type_guess = 8;
		seventh_guess = 0x21d3; flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 24:
		first_guess = 0x2221; second_guess = 0x2222; category_guess = 5;
		type_guess = 6; state_guess = 1; seventh_guess = 0x21d3;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 25:
		first_guess = 0x2223; second_guess = 0x2224; seventh_guess = 0x21d3;
		category_guess = 3; type_guess = 6; state_guess = 2;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 26:
		first_guess = 0x2225; second_guess = 0x2226; seventh_guess = 0x21d3;
		category_guess = 3; type_guess = 6; state_guess = 2;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 27:
		first_guess = 0x2227; second_guess = 0x2228; seventh_guess = 0x21d3;
		category_guess = 3; type_guess = 6; state_guess = 2;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 28:
		first_guess = 0x21f8; second_guess = 0x21f9;
		fourth_guess = 0x21fa; fifth_guess = 0x21fb; sixth_guess = 0x21fc;
		type_guess = 5; seventh_guess = 0x21d3;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 29:
		first_guess = 0x21b1; second_guess = 0x21b2;
		fourth_guess = 0x21b3; fifth_guess = 0x21b4; sixth_guess = 0x21b5;
		type_guess = 9; seventh_guess = 0x21d3;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 1;
		break;
	case 30:
		first_guess = 0x21b8; second_guess = 0x21b9;
		fourth_guess = 0x21ba; fifth_guess = 0x21bb; sixth_guess = 0x21bc;
		type_guess = 10; seventh_guess = 0x21d1;
		flag0_guess = 2; flag1_guess = 2; enabled_guess = 0;
		break;
	default:
		first_guess = 0x4c0; second_guess = 0x4c0;
		fourth_guess = 0x4c0; fifth_guess = 0x4c0; sixth_guess = 0x4c0;
		type_guess = 0; flag0_guess = 0; flag1_guess = 0; enabled_guess = 0;
		break;
	}
}

