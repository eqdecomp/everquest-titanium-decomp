// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 125: a hint from compare/tumap.py.
// CAvaZoneWnd (screen "AvaZoneWnd", vtable 0x64F960, pointer 0x850CB4): a GM-only list of every known zone
// that zones you to the pick (tu_029 creates it only for GMs). ZoneSelect_guess is the same window;
// pZoneMgr_guess (0x905CC0) is the world data (0x5FA1C0 EQWorldData::GetFullZoneName, Mac).
#include "titanium/types.h"
#include "titanium/crt.h"

struct ZoneInfo_guess {
    unsigned char pad_0000_guess[0x10];
    char shortName_0010_guess[0x40];
};

struct EQWorldData_guess {
    // EXTERNAL: TITANIUM 0x0043A6BF EQWorldData_guess::Find_guess
    ZoneInfo_guess* Find_guess(int zoneId_guess);
    // EXTERNAL: TITANIUM 0x005FA1C0 EQWorldData_guess::GetZoneName_guess
    void GetZoneName_guess(int zoneId_guess, char* out_guess, int flag_guess);
};
#define pZoneMgr_guess EQ_GLOBAL(EQWorldData_guess*, 0x00905CC0)

// CSidlScreenWndBase: the polymorphic CSidlScreenWnd base (ctor 0x005A3850/0x005A3900, dtor 0x005A3100).
#include "titanium/layouts/sidl_base.h"

/* The zone list: a CListWnd whose colour field is at 0x16C. */
struct AvaZoneList_guess : CListWnd {
    unsigned int pad_140[(0x16C - 0x140) / 4];
    unsigned int color_16C;
};

/* The zone name label: vtable slot 0xFC is SetWindowText; Enabled at 0x5D. */
struct ZoneLabel_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess(); virtual void Slot14_guess(); virtual void Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess(); virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(); virtual void Slot33_guess(); virtual void Slot34_guess(); virtual void Slot35_guess();
    virtual void Slot36_guess(); virtual void Slot37_guess(); virtual void Slot38_guess(); virtual void Slot39_guess();
    virtual void Slot40_guess(); virtual void Slot41_guess(); virtual void Slot42_guess(); virtual void Slot43_guess();
    virtual void Slot44_guess(); virtual void Slot45_guess(); virtual void Slot46_guess(); virtual void Slot47_guess();
    virtual void Slot48_guess(); virtual void Slot49_guess(); virtual void Slot50_guess(); virtual void Slot51_guess();
    virtual void Slot52_guess(); virtual void Slot53_guess(); virtual void Slot54_guess(); virtual void Slot55_guess();
    virtual void Slot56_guess(); virtual void Slot57_guess(); virtual void Slot58_guess(); virtual void Slot59_guess();
    virtual void Slot60_guess(); virtual void Slot61_guess(); virtual void Slot62_guess();
    virtual void SetWindowText_guess(const CXStr& text);    // 0xFC
    char pad_004[0x59];                     // 0x004
    unsigned char enabled_05D;              // 0x05D
};

// EXTERNAL: TITANIUM 0x0064F960 ??_7CAvaZoneWnd_guess@@6B@
struct CAvaZoneWnd_guess : CSidlScreenWndBase {
    CXWnd* zoneButton_15C;                  // 0x15C Zone_ZoneButton
    AvaZoneList_guess* zoneList_160;        // 0x160 Zone_ZoneList
    ZoneLabel_guess* zoneName_164;          // 0x164 Zone_ZoneName
    int zoneIndex_168[1000];                // 0x168 zone ids, filled by the scan
    char zoneName_1108[1000][0x100];        // 0x1108 zone names, 256 bytes each
    unsigned char zoneBusy_3F908;           // 0x3F908
    CAvaZoneWnd_guess(CXWnd* parent);
};

// Lists zone ids 0-999 that exist by full name, a leading "The " dropped, sorted by name (insertion sort),
// and shows the first zone's short name (zone record +0x10) in the read-only label.
// FUNCTION: TITANIUM 0x004DAA44
CAvaZoneWnd_guess::CAvaZoneWnd_guess(CXWnd* parent) : CSidlScreenWndBase(parent, "AvaZoneWnd") {
    if (SidlPiece != 0) {
        WindowStyle |= SidlPiece->style_guess | 0x800;
        ((CSidlScreenWnd*)this)->CreateChildrenFromSidl();
        zoneButton_15C = ((CSidlScreenWnd*)this)->GetChildItem("Zone_ZoneButton");
        zoneList_160 = (AvaZoneList_guess*)((CSidlScreenWnd*)this)->GetChildItem("Zone_ZoneList");
        zoneName_164 = (ZoneLabel_guess*)((CSidlScreenWnd*)this)->GetChildItem("Zone_ZoneName");
        if (zoneButton_15C != 0 && zoneList_160 != 0 && zoneName_164 != 0) {
            zoneList_160->SetColors(-1, 0xffffff00, 0xff808080);
            // Light blue (ARGB) at list +0x16C, as in CMIZoneSelectWnd; probably the selection highlight.
            zoneList_160->color_16C = 0xff8aa3ff;
            int count = 0;
            for (int i = 0; i < 1000; ++i) {
                if (pZoneMgr_guess->Find_guess(i) != 0) {
                    pZoneMgr_guess->GetZoneName_guess(i, zoneName_1108[count], 1);
                    if (strncmp(zoneName_1108[count], "The ", 4) == 0) {
                        strcpy(zoneName_1108[count], zoneName_1108[count] + 4);
                    }
                    zoneIndex_168[count] = i;
                    ++count;
                }
            }
            for (int i = 1; i < count; ++i) {
                for (int k = i; k > 0; --k) {
                    if (strcmp(zoneName_1108[k], zoneName_1108[k - 1]) >= 0) {
                        break;
                    }
                    char tmp[256];
                    strcpy(tmp, zoneName_1108[k]);
                    strcpy(zoneName_1108[k], zoneName_1108[k - 1]);
                    strcpy(zoneName_1108[k - 1], tmp);
                    int idx = zoneIndex_168[k];
                    zoneIndex_168[k] = zoneIndex_168[k - 1];
                    zoneIndex_168[k - 1] = idx;
                }
            }
            for (int j = 0; j < count; ++j) {
                zoneList_160->AddString(zoneName_1108[j], 0xffffffff, 0, 0);
            }
            zoneList_160->SetCurSel(0);
            zoneName_164->enabled_05D = 0;
            zoneName_164->SetWindowText_guess(EQ_ARRAY(char, 0x0063F53F));
            if (count > 0) {
                ZoneInfo_guess* zone = pZoneMgr_guess->Find_guess(zoneIndex_168[0]);
                if (zone != 0) {
                    // The busy flag is set and cleared around the label update (match shape).
                    zoneBusy_3F908 = 1;
                    zoneName_164->SetWindowText_guess(zone->shortName_0010_guess);
                }
            }
            zoneBusy_3F908 = 0;
        }
    }
}

// EXTERNAL: TITANIUM 0x0046F157 do_switchzone_guess
void __cdecl do_switchzone_guess(int flag_guess, char* name_guess);

struct EditWnd_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess(); virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess(); virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess(); virtual void Slot0A_guess(); virtual void Slot0B_guess();
    virtual void Slot0C_guess(); virtual void Slot0D_guess(); virtual void Slot0E_guess(); virtual void Slot0F_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess(); virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual void Slot15_guess(); virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess(); virtual void Slot1A_guess(); virtual void Slot1B_guess();
    virtual void Slot1C_guess(); virtual void Slot1D_guess(); virtual void Slot1E_guess(); virtual void Slot1F_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess(); virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess(); virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess(); virtual void Slot2A_guess(); virtual void Slot2B_guess();
    virtual void Slot2C_guess(); virtual void Slot2D_guess(); virtual void Slot2E_guess(); virtual void Slot2F_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess(); virtual void Slot32_guess(); virtual void Slot33_guess();
    virtual void Slot34_guess(); virtual void Slot35_guess(); virtual void Slot36_guess(); virtual void Slot37_guess();
    virtual void Slot38_guess(); virtual void Slot39_guess(); virtual void Slot3A_guess(); virtual void Slot3B_guess();
    virtual void Slot3C_guess(); virtual void Slot3D_guess(); virtual void Slot3E_guess();
    virtual void SetWindowText_guess(const CXStr& text_guess); // 0xFC
};

struct ZoneSelect_guess {
    unsigned char pad_0000_guess[0x15c];
    CXWnd* field_15c_guess;
    CListWnd* field_160_guess;
    EditWnd_guess* zoneName_0164_guess;
    int zoneIds_guess[(0x3F908 - 0x168) / 4];
    char busy_guess;                       // 0x3F908
    int WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess);
};

// Zone_ZoneButton zones to the selected zone by short name through do_switchzone (0x46F157, Mac), guarded
// by the busy flag; picking a list row shows that row's short name.
// FUNCTION: TITANIUM 0x004DAE47
int ZoneSelect_guess::WndNotification_guess(CXWnd* sender_guess, unsigned int message_guess, void* data_guess)
{
    if (message_guess == 1) {
        if (sender_guess == field_15c_guess) {
            ZoneInfo_guess* zone_guess = pZoneMgr_guess->Find_guess(zoneIds_guess[field_160_guess->GetCurSel()]);
            if (zone_guess != 0) {
                if (busy_guess == 0) {
                    busy_guess = 1;
                    char name_guess[256];
                    strcpy(name_guess, zone_guess->shortName_0010_guess);
                    do_switchzone_guess(0, name_guess);
                    busy_guess = 0;
                }
            } else {
                // The selected id no longer resolves to a zone record.
                pEverQuest->dsp_chat("Unable to find that zone's real name.\n");
            }
            return 0;
        }
        if (sender_guess == field_160_guess) {
            ZoneInfo_guess* zone_guess = pZoneMgr_guess->Find_guess(zoneIds_guess[field_160_guess->GetCurSel()]);
            if (zone_guess != 0) {
                CXStr text_guess(zone_guess->shortName_0010_guess);
                zoneName_0164_guess->SetWindowText_guess(text_guess);
            }
            return 0;
        }
    }
    return reinterpret_cast<CSidlScreenWnd*>(this)->WndNotification(sender_guess, message_guess, data_guess);
}
