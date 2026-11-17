// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 187: a hint from compare/tumap.py.
// CMapViewWnd (screen "MapViewWnd"), the in-game map: per zone a base map and three user layers
// (maps\<zone>.txt, <zone>_1.txt to _3.txt), drawing by walking, labels, a height filter and the Atlas tab.
// Nearly every _guess class here is a view of the window or of its map object at +0x1EC (MapViewMap,
// MapLayer, Viewport, Event, Scale, OffsetOwner, AtlasControlOwner...). 0x905CE4 is the player's spawn; map
// coordinates are its negated +0x34/+0x30.
#include <winsock2.h>
#include <windows.h>
#include "titanium/eqaddr.h"
#include "titanium/types.h"
#include "titanium/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node_guess {
    Node_guess* next_guess;
    Node_guess* prev_guess;
};

struct ForwardTarget_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual int Forward_guess(int first_guess, int second_guess) = 0;
};

struct ForwardOwner_guess {
    char pad_00_guess[0x28];
    ForwardTarget_guess* target_28_guess;
    int Dispatch_guess(int first_guess, int second_guess);
};

struct List_guess {
    char pad_guess[0x40];
    Node_guess* first_guess;
    void Remove_guess(Node_guess* node_guess);
};

struct RecyclableNode_guess {
    RecyclableNode_guess* next_guess;
    RecyclableNode_guess* prev_guess;
    char pad_08_guess[0x14];
    void* allocation_guess;
};

struct RecyclableList_guess {
    char pad_00_guess[0x44];
    RecyclableNode_guess* first_guess;
    void RemoveAndFree_guess(RecyclableNode_guess* node_guess);
};

struct MatchNode24_guess {
    MatchNode24_guess* next_guess;
    char pad_04_guess[0x20];
    unsigned int key_guess;
};

struct MatchNode20_guess {
    MatchNode20_guess* next_guess;
    char pad_04_guess[0x1c];
    unsigned int key_guess;
};

struct MatchOwner_guess {
    char pad_00_guess[0x40];
    MatchNode24_guess* first_guess;
    MatchNode20_guess* second_guess;
    char pad_4c_guess[0x20];
    unsigned int key_guess;
    void ClearActiveLayer_guess();
};

struct Color_guess {
    char pad_guess[0x58];
    unsigned char first_guess;
    unsigned char second_guess;
    unsigned char third_guess;
    unsigned char marker_guess;
    unsigned int GetCurrentColor_guess();
    void SetCurrentColor_guess(unsigned int value_guess);
};

struct PackedColor_guess {
    char pad_00_guess[0x20];
    unsigned char first_guess;
    unsigned char second_guess;
    unsigned char third_guess;
    unsigned char marker_guess;
};

struct ColorNode_guess {
    ColorNode_guess* next_guess;
    PackedColor_guess* color_guess;
};

struct ColorOwner_guess {
    char pad_00_guess[0x5c];
    ColorNode_guess* node_guess;
    void AddLineToSelection_guess(PackedColor_guess* color_guess);
    void SetSelectedLinesColor_guess(unsigned int value_guess);
    unsigned int GetSelectedLineColor_guess();
};

struct ElementList_guess;

struct Event_guess {
    char pad_00_guess[8];
    float offset_x_guess;
    float offset_y_guess;
    char pad_10_guess[0x10];
    int field_20_guess;
    int field_24_guess;
    char pad_28_guess[0x18];
    ElementList_guess* list_guess;
    char pad_44_guess[4];
    unsigned char ready_guess;
    char pad_49_guess[3];
    float first_guess;
    float second_guess;
    float third_guess;
    unsigned int field_58_guess;
    char pad_5c_guess[0x0c];
    unsigned int field_68_guess;
    char pad_6c_guess[0x16];
    unsigned char enabled_guess;
    void Submit_guess(float first_value_guess, float second_value_guess, float third_value_guess);
    void AddPoint_guess(float first_value_guess, float second_value_guess, float third_value_guess);
    void Place_guess(float first_value_guess, float second_value_guess, float third_value_guess);
};

struct AtlasLoader_guess;
struct ResourceText_guess;

struct OffsetOwner_guess {
    char pad_00_guess[0x5c];
    unsigned char enabled_5c_guess;
    char pad_5d_guess[0x15c - 0x5d];
    unsigned char flag_15c_guess;
    char pad_15d_guess[0x1e8 - 0x15d];
    AtlasLoader_guess* atlas_guess;
    Event_guess event_guess;
    void StartAutoMap_guess();
    void StopAutoMap_guess();
    void ScanAtlas_guess();
    char AboutToShow_guess();
    char AboutToHide_guess();
    void OnProcessFrame_guess();
    // EXTERNAL: TITANIUM 0x005A0E50 OffsetOwner_guess::OnProcessFrame
    void OnProcessFrame();
};

struct ScanController_guess {
    // EXTERNAL: TITANIUM 0x005F6BC0 ScanController_guess::Check_guess
    char Check_guess(unsigned int request_guess);
};

struct AtlasControlEvent_guess {
    float scale_first_guess;
    char pad_04_guess[4];
    float scale_third_guess;
    char pad_0c_guess[0x14];
    int offset_x_guess;
    int offset_y_guess;
    char pad_28_guess[0x18];
    void* first_node_guess;
    void* second_node_guess;
    unsigned char ready_guess;
    char pad_49_guess[3];
    float first_guess;
    float second_guess;
    float third_guess;
    char pad_58_guess[4];
    ColorNode_guess* color_node_guess;
    unsigned int color_value_guess;
    unsigned int flags_guess;
    unsigned int selection_guess;
    int first_state_guess;
    int second_state_guess;
    unsigned char toggle_guess;
    char pad_75_guess[3];
    float ratio_guess;
    int count_guess;
    unsigned char first_flag_guess;
    unsigned char changed_guess;
    unsigned char enabled_guess;
};

struct AtlasControlOwner_guess {
    char pad_00_guess[0x15c];
    unsigned char flag_15c_guess;
    char pad_15d_guess[3];
    CXWnd* control_160_guess;
    CXWnd* control_164_guess;
    CXWnd* control_168_guess;
    CXWnd* control_16c_guess;
    CXWnd* control_170_guess;
    CXWnd* control_174_guess;
    CXWnd* control_178_guess;
    CXWnd* control_17c_guess;
    char pad_180_guess[0x20];
    CXWnd* control_1a0_guess;
    CXWnd* control_1a4_guess;
    CXWnd* control_1a8_guess;
    CXWnd* control_1ac_guess;
    CXWnd* control_1b0_guess;
    CXWnd* control_1b4_guess;
    CXWnd* control_1b8_guess;
    CXWnd* control_1bc_guess;
    CXWnd* control_1c0_guess;
    CXWnd* control_1c4_guess;
    CXWnd* control_1c8_guess;
    CXWnd* control_1cc_guess;
    char pad_1d0_guess[4];
    void* manager_1d4_guess;
    void* manager_1d8_guess;
    CXWnd* control_1dc_guess;
    char pad_1e0_guess[4];
    CXWnd* control_1e4_guess;
    AtlasLoader_guess* atlas_guess;
    AtlasControlEvent_guess event_guess;
    void SelectMap_guess();
    // EXTERNAL: TITANIUM 0x00535AA0 AtlasControlOwner_guess::SetMap_guess
    void SetMap_guess(int count_guess, float* first_guess, float* second_guess);
    int HandleControl_guess(CXWnd* control_guess, unsigned int message_guess, void* data_guess);
};

struct ElementList_guess {
    union {
        char pad_00_guess[8];
        struct {
            ElementList_guess* next_guess;
            ElementList_guess* previous_guess;
        } links_guess;
    };
    union {
        char pad_08_guess[0x18];
        struct {
            float old_x_guess;
            float old_y_guess;
            float old_z_guess;
            float new_x_guess;
            float new_y_guess;
            float new_z_guess;
        } position_guess;
    };
    unsigned int field_20_guess;
    unsigned int field_24_guess;
    ElementList_guess() { Initialize_guess(); }
    ElementList_guess* Initialize_guess();
};

struct FlagSet_guess {
    char pad_00_guess[0x64];
    unsigned int flags_guess;
    char Test_guess(int index_guess);
};

struct PermissionTarget_guess {
    char pad_00_guess[0x1d8];
    int enabled_guess;
    CXWnd* gate_guess;
    char Permit_guess();
};

struct MessageManager_guess {
    // EXTERNAL: TITANIUM 0x0059DD30 MessageManager_guess::Check_guess
    char Check_guess();
    // EXTERNAL: TITANIUM 0x00531779 MessageManager_guess::SetAutoMapCheck_guess
    void SetAutoMapCheck_guess(unsigned char argument_guess);
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
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess();
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Dispatch_guess();
};

struct RefreshTarget_guess {
    char pad_00_guess[0x5c];
    unsigned char refreshed_guess;
    // EXTERNAL: TITANIUM 0x005A1880 RefreshTarget_guess::OnShow
    void OnShow();
    void Refresh_guess();
};

struct Rect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    Rect_guess() {}
    Rect_guess(const Rect_guess& other_guess) {
        left_guess = other_guess.left_guess;
        top_guess = other_guess.top_guess;
        right_guess = other_guess.right_guess;
        bottom_guess = other_guess.bottom_guess;
    }
    char Equal_guess(Rect_guess* other_guess);
    void NormalizeRect_guess();
    // EXTERNAL: TITANIUM 0x004D9160 Rect_guess::Copy_guess
    void Copy_guess(void* output_guess, Rect_guess* source_guess);
};

struct DrawPoint_guess {
    int x_guess;
    int y_guess;
    DrawPoint_guess() {}
    DrawPoint_guess(int x, int y) { x_guess = x; y_guess = y; }
};

struct DrawRect_guess : Rect_guess {
    DrawRect_guess() {}
    DrawRect_guess(int l, int t, int r, int b) {
        left_guess = l;
        top_guess = t;
        right_guess = r;
        bottom_guess = b;
    }
    DrawRect_guess(const DrawRect_guess& other_guess) {
        left_guess = other_guess.left_guess;
        top_guess = other_guess.top_guess;
        right_guess = other_guess.right_guess;
        bottom_guess = other_guess.bottom_guess;
    }
    // EXTERNAL: TITANIUM 0x004EA5BF DrawRect_guess::Contains_guess
    char Contains_guess(const DrawPoint_guess& point_guess) const;
    // EXTERNAL: TITANIUM 0x0050445A DrawRect_guess::Intersect_guess
    DrawRect_guess Intersect_guess(const DrawRect_guess& other_guess) const;
    // EXTERNAL: TITANIUM 0x004D9160 ??4DrawRect_guess@@QAE?AU0@ABU0@@Z
    DrawRect_guess operator=(const DrawRect_guess& other_guess);
};

struct Rect6_guess {
    float left_guess;
    float top_guess;
    float unused_guess;
    float right_guess;
    float bottom_guess;
    float unused2_guess;
};

struct ClipScratch_guess {
    float endpoints_guess[6];
    float delta_x_guess;
    float delta_y_guess;
    float max_x_guess;
    float min_x_guess;
};

struct DrawTarget_guess {
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
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void DrawSegment_guess(float* first_guess, float* second_guess, unsigned int value_guess);
};

struct SegmentOwner_guess {
    char Clip_guess(Rect6_guess* rect_guess, unsigned int value_guess, DrawRect_guess clip_guess);
};

#include "titanium/layouts/geometry.h"

struct Bounds_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    // EXTERNAL: TITANIUM 0x004EA5BF Bounds_guess::Contains_guess
    char Contains_guess(CXPoint* point_guess);
};

struct DisplayOffset_guess {
    char pad_00_guess[0x30];
    float field_30_guess;
    float field_34_guess;
    float field_38_guess;
    char pad_3c_guess[0x10];
    float heading_4c_guess;
    char pad_50_guess[0x23c - 0x50];
    float field_23c_guess;
};

struct PositionSource_guess {
    char pad_00_guess[0x74];
    int field_74_guess;
    int field_78_guess;
};

struct Viewport_guess {
    float left_0000_guess;   // 0x00
    float top_0004_guess;   // 0x04
    float right_0008_guess;   // 0x08
    float bottom_000c_guess;   // 0x0c
    float viewWidth_0010_guess;   // 0x10
    float viewHeight_0014_guess;   // 0x14
    float field_18_guess;   // 0x18
    float field_1c_guess;   // 0x1c
    int field_20_guess;     // 0x20
    int field_24_guess;     // 0x24
    float field_28_guess;   // 0x28
    float field_2c_guess;   // 0x2c
    float offsetX_0030_guess;   // 0x30
    float offsetY_0034_guess;   // 0x34
    float scaleX_0038_guess;   // 0x38
    float scaleY_003c_guess;   // 0x3c
    char pad_40_guess[0x38];
    float zoom_0078_guess;   // 0x78
    char pad_7c_guess[8];
    unsigned int field_84_guess; // 0x84
    char ContainsPoint_guess(int arg0_guess, int arg1_guess, int arg2_guess,
        int arg3_guess, int arg4_guess);
    // EXTERNAL: TITANIUM 0x005329DF Viewport_guess::ContainsRect_guess
    char ContainsRect_guess(int point_guess, Rect_guess rect_guess);
    void UpdateLayout_guess();
    void TransformPoint_guess(float* point_guess);
};

struct ValueBounds_guess {
    char pad_00_guess[0x10];
    float first_guess;
    float second_guess;
    float third_guess;
    float fourth_guess;
    char pad_20_guess[0x60];
    unsigned char pad_80_guess;
    unsigned char enabled_guess;
    void Set_guess(int first_value_guess, int second_value_guess, int third_value_guess, int fourth_value_guess);
};

struct Scale_guess {
    float first_guess;                  // 0x00
    float second_guess;                 // 0x04
    float third_guess;                  // 0x08
    float fourth_guess;                 // 0x0c
    char pad_10_guess[0x68];
    float ratio_guess;                  // 0x78
    int count_guess;                    // 0x7c
    char pad_80_guess;
    unsigned char ready_guess;          // 0x81
    void Update_guess(float value_guess);
};

struct Triple_guess {
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int third_guess;
};

struct TargetData_guess {
    char pad_00_guess[8];
    float value_08_guess;
    int value_0c_guess;
    int value_10_guess;
};

struct SaveLine_guess {
    SaveLine_guess* next_guess;
    SaveLine_guess* prev_guess;
    float first_guess;
    float second_guess;
    float third_guess;
    float fourth_guess;
    float fifth_guess;
    float sixth_guess;
    unsigned char first_color_guess;
    unsigned char second_color_guess;
    unsigned char third_color_guess;
    char pad_23_guess;
    int map_index_guess;
    SaveLine_guess() { ((ElementList_guess*)this)->Initialize_guess(); }
};

struct SavePoint_guess {
    SavePoint_guess* next_guess;
    SavePoint_guess* prev_guess;
    float x_guess;
    float y_guess;
    float z_guess;
    unsigned char first_color_guess;
    unsigned char second_color_guess;
    unsigned char third_color_guess;
    char pad_17_guess;
    int value_18_guess;
    char* text_guess;
    int map_index_guess;
    char pad_24_guess[0x10];
};

struct MapViewMap_guess {
    char pad_00_guess[0x20];
    unsigned int field_20_guess;
    unsigned int field_24_guess;
    char pad_28_guess[0x18];
    SaveLine_guess* lines_guess;
    SavePoint_guess* points_guess;
    char pad_48_guess[0x1c];
    unsigned int flags_guess;
    unsigned int field_68_guess;
    char pad_6c_guess[0x0c];
    float field_78_guess;
    int field_7c_guess;
    char pad_80_guess;
    unsigned char saved_81_guess;
    char pad_82_guess[2];
    void SaveEx(const char* map_name_guess, int map_index_guess);
    // EXTERNAL: TITANIUM 0x00533E29 MapViewMap_guess::LoadMapLayer_guess
    bool LoadMapLayer_guess(const char* map_name_guess, int map_index_guess);
    void LoadAllLayers_guess(const char* map_name_guess);
    void SaveAllEx_guess(const char* map_name_guess);
};

struct IntersectionSegment_guess {
    char pad_00_guess[8];
    float first_x_guess;
    float first_y_guess;
    char pad_10_guess[4];
    float second_x_guess;
    float second_y_guess;
};

struct IntersectionRef_guess {
    int state_guess;
    IntersectionSegment_guess* segment_guess;
};

struct IntersectionPair_guess {
    IntersectionRef_guess* first_guess;
    IntersectionSegment_guess* second_guess;
};

struct IntersectionOwner_guess {
    char pad_00_guess[0x5c];
    IntersectionPair_guess* pair_guess;
    void JoinAtIntersect_guess(unsigned char both_guess);
};

#define g_intersectionLimit_guess EQ_GLOBAL(float, 0x006588F0)
#define g_intersectionMax_guess EQ_GLOBAL(float, 0x0064BADC)

struct Block16_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    // EXTERNAL: TITANIUM 0x004D9160 Block16_guess::CopyTo_guess
    void CopyTo_guess(Block16_guess* destination_guess, Block16_guess* source_guess);
};

struct Block16Entry_guess {
    int first_guess;
    int second_guess;
    int third_guess;
    int fourth_guess;
    Block16Entry_guess() {}
    Block16Entry_guess(const Block16Entry_guess& source_guess) {
        first_guess = source_guess.first_guess;
        second_guess = source_guess.second_guess;
        third_guess = source_guess.third_guess;
        fourth_guess = source_guess.fourth_guess;
    }
    // EXTERNAL: TITANIUM 0x004D911A ??0Block16Entry_guess@@QAE@ABUBlock16_guess@@@Z
    Block16Entry_guess(const Block16_guess& source_guess);
    // EXTERNAL: TITANIUM 0x004D9160 Block16Entry_guess::CopyTo_guess
    void CopyTo_guess(Block16_guess* destination_guess, Block16_guess* source_guess);
};

struct QueueOwner_guess {
    char pad_00_guess[0x24];
    int field_24_guess;
    int field_28_guess;
    int field_2c_guess;
    int field_30_guess;
};

struct QueueEntry_guess {
    QueueEntry_guess* next_guess;
    union {
        Block16_guess block_guess;
        struct {
            int x_0004_guess;
            int y_0008_guess;
            int value_0c_guess;
            int value_10_guess;
        };
    };
    QueueOwner_guess* owner_guess;
    unsigned char enabled_guess;
};

struct ArgumentContext_guess {
    // EXTERNAL: TITANIUM 0x0050445A ArgumentContext_guess::Convert_guess
    void Convert_guess(Rect_guess* output_guess, int* values_guess);
};

struct InitObject_guess {
    char pad_00_guess[0x40];
    unsigned int field_40_guess;
    unsigned int field_44_guess;
    unsigned char field_48_guess;
    char pad_49_guess[0x0f];
    unsigned char field_58_guess;
    unsigned char field_59_guess;
    unsigned char field_5a_guess;
    unsigned char field_5b_guess;
    unsigned int field_5c_guess;
    char pad_60_guess[4];
    unsigned int field_64_guess;
    unsigned int field_68_guess;
    unsigned int field_6c_guess;
    unsigned int field_70_guess;
    unsigned char field_74_guess;
    char pad_75_guess[3];
    float field_78_guess;
    char pad_7c_guess[4];
    unsigned char field_80_guess;
    InitObject_guess();
};

struct SimpleNode_guess {
    SimpleNode_guess* next_guess;
    SimpleNode_guess* prev_guess;
};

struct AllocatedNode_guess {
    AllocatedNode_guess* next_guess;
    AllocatedNode_guess* prev_guess;
    char pad_08_guess[0x14];
    void* allocation_guess;
};

struct PendingEntry_guess {
    PendingEntry_guess* next_guess;
    SimpleNode_guess* node_guess;
};

struct DestroyObject_guess {
    char pad_00_guess[0x40];
    SimpleNode_guess* first_guess;
    AllocatedNode_guess* second_guess;
    unsigned char field_48_guess;
    char pad_49_guess[0x13];
    unsigned int field_5c_guess;
    char pad_60_guess[4];
    unsigned int field_64_guess;
    unsigned int field_68_guess;
    unsigned int field_6c_guess;
    unsigned int field_70_guess;
    unsigned char field_74_guess;
    char pad_75_guess[3];
    float field_78_guess;
    char pad_7c_guess[4];
    unsigned char field_80_guess;
    ~DestroyObject_guess();
    void Apply_guess(int first_value_guess, int second_value_guess, int third_value_guess, int fourth_value_guess);
    void ComputeBounds_guess();
};

struct ClearObject_guess {
    char pad_00_guess[0x40];
    SimpleNode_guess* first_guess;
    AllocatedNode_guess* second_guess;
    unsigned char field_48_guess;
    char pad_49_guess[0x13];
    PendingEntry_guess* field_5c_guess;
    AllocatedNode_guess* field_60_guess;
    ~ClearObject_guess();
    void RemoveSelectedLines_guess();
    void RemoveSelectedLabel_guess();
};

struct OuterBase_guess {
    char pad_00_guess[0x1ec];
    // EXTERNAL: TITANIUM 0x005A3100 OuterBase_guess::~OuterBase_guess
    ~OuterBase_guess() ;
};

struct Outer_guess : OuterBase_guess {
    DestroyObject_guess member_guess; // 0x1ec
    ~Outer_guess() ;
    void* Delete_guess(unsigned char flags_guess);
};

struct Primary31c04_guess {
    char pad_00_guess[0x15c];
    // EXTERNAL: TITANIUM 0x005A3100 Primary31c04_guess::~Primary31c04_guess
    ~Primary31c04_guess();
};

struct Secondary31c04_guess {
    // EXTERNAL: TITANIUM 0x0063FD9C ??_7Secondary31c04_guess@@6B@
    // EXTERNAL: TITANIUM 0x005482A0 Secondary31c04_guess::Reset_guess
    void Reset_guess(int value_guess);
    virtual ~Secondary31c04_guess() {
        Reset_guess(-1);
    }
};

struct SecondaryStorage31c04_guess {
    char bytes_guess[4];
};

struct Target31c04_guess : Primary31c04_guess {
    SecondaryStorage31c04_guess member_guess;
    ~Target31c04_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct ResourceItem_guess {
    // EXTERNAL: TITANIUM 0x005A3A00 ResourceItem_guess::Read_guess
    unsigned int Read_guess(void* value_guess);
    // EXTERNAL: TITANIUM 0x005A3A20 ResourceItem_guess::Finish_guess
    unsigned int Finish_guess();
};

struct ResourceSection_guess {
    // EXTERNAL: TITANIUM 0x004EB924 ResourceSection_guess::Get_guess
    ResourceItem_guess** Get_guess(int index_guess);
};

struct ResourceCatalog_guess {
    char pad_00_guess[0xf4];
    ResourceSection_guess section_guess;
};

struct ActiveSlot_guess {
    char pad_00_guess[0x48];
    OffsetOwner_guess* owner_48_guess;
    char pad_4c_guess[0x20];
    int count_6c_guess;
};

struct ResourceText_guess {
    ResourceText_guess() {}
    // EXTERNAL: TITANIUM 0x00571E00 ResourceText_guess::ResourceText_guess
    ResourceText_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00407D68 ??0ResourceText_guess@@QAE@ABU0@@Z
    ResourceText_guess(const ResourceText_guess& source_guess);
    // EXTERNAL: TITANIUM 0x00571D00 ResourceText_guess::FreeRep
    void FreeRep(unsigned int value_guess);
    // EXTERNAL: TITANIUM 0x00573610 ResourceText_guess::Unshare_guess
    void Unshare_guess();
    // EXTERNAL: TITANIUM 0x00572E00 ResourceText_guess::Append_guess
    void Append_guess(const char* text_guess);
    // EXTERNAL: TITANIUM 0x00572650 ResourceText_guess::Find_guess
    int Find_guess(const ResourceText_guess& other_guess);
    ~ResourceText_guess() {
        if (value_guess != 0) {
            FreeRep(value_guess);
        }
        value_guess = 0;
    }
    unsigned int value_guess;
};

struct TextSink_guess {
    // EXTERNAL: TITANIUM 0x005C0CC0 TextSink_guess::Add_guess
    void Add_guess(ResourceText_guess* text_guess);
};

struct ResourceTable_guess {
    // EXTERNAL: TITANIUM 0x0043A6BF ResourceTable_guess::Get_guess
    int Get_guess(unsigned int id_guess);
    // EXTERNAL: TITANIUM 0x005F6ED0 ResourceTable_guess::Update_guess
    void Update_guess(unsigned int id_guess, const char* map_name_guess);
};

struct MainOwner_guess {
    char pad_00_guess[0x180];
    char map_name_guess[0x30];
    CButtonWnd* field_1b0_guess;
    CButtonWnd* field_1b4_guess;
    CButtonWnd* field_1b8_guess;
    CButtonWnd* field_1bc_guess;
    CButtonWnd* field_1c0_guess;
    CButtonWnd* field_1c4_guess;
    CButtonWnd* field_1c8_guess;
    char pad_1cc_guess[8];
    TextSink_guess* field_1d4_guess;
    char pad_1d8_guess[0x14];
    MapViewMap_guess map_guess;
    unsigned int resource_id_guess;
    void Initialize_guess(unsigned int resource_id_guess,
        const float* first_point_guess, const float* second_point_guess);
};

#define g_resourceTable_guess EQ_GLOBAL(ResourceTable_guess*, 0x00905CC0)

// EXTERNAL: TITANIUM 0x0046DA4A FormatResourceText_guess
void __cdecl FormatResourceText_guess(char* text_guess, int string_id_guess,
    int resource_id_guess, int arg3_guess, int arg4_guess, int arg5_guess,
    int arg6_guess, int arg7_guess, int arg8_guess, int arg9_guess, int arg10_guess);

// EXTERNAL: TITANIUM 0x0060F81E GetMapTick_guess
int __cdecl GetMapTick_guess();

struct ResourceTextAppender_guess {
    // EXTERNAL: TITANIUM 0x00572C10 ResourceTextAppender_guess::Append_guess
    void Append_guess(const CXStr& text_guess);
};

struct StringIndex_guess {
    // EXTERNAL: TITANIUM 0x00571630 StringIndex_guess::Get_guess
    int Get_guess();
};

struct ResourceEntry_guess {
    char pad_00_guess[0x18];
    int index_guess;
    const char* text_guess;
    char pad_20_guess[4];
    unsigned int first_guess;
    unsigned int second_guess;
};

struct ResourceLoader_guess {
    void Load_guess(ResourceEntry_guess* entry_guess);
};

struct AddedEntry_guess {
    AddedEntry_guess* next_guess;
    AddedEntry_guess* previous_guess;
    unsigned int first_guess;
    unsigned int second_guess;
    unsigned int third_guess;
    unsigned char color_14_guess;
    unsigned char color_15_guess;
    unsigned char color_16_guess;
    unsigned char color_17_guess;
    unsigned int value_18_guess;
    char* text_guess;
    unsigned int value_20_guess;
    char pad_24_guess[8];
    unsigned int value_2c_guess;
    unsigned int value_30_guess;
};

struct EntryOwner_guess {
    char pad_00_guess[0x44];
    AddedEntry_guess* first_guess;
    char pad_48_guess[0x20];
    unsigned int value_68_guess;
    char pad_6c_guess[0x16];
    unsigned char enabled_guess;
    void AddLabel_guess(unsigned int first_value_guess, unsigned int second_value_guess,
        unsigned int third_value_guess, unsigned int color_guess,
        unsigned int value_guess, const char* text_guess);
};

struct AtlasLoader_guess {
    // EXTERNAL: TITANIUM 0x0059C3E0 AtlasLoader_guess::Begin_guess
    void Begin_guess();
    // EXTERNAL: TITANIUM 0x0059C8D0 AtlasLoader_guess::AddFolder_guess
    void AddFolder_guess(ResourceText_guess* folder_guess);
    // EXTERNAL: TITANIUM 0x0059C390 AtlasLoader_guess::Count_guess
    int Count_guess();
    // EXTERNAL: TITANIUM 0x0059C360 AtlasLoader_guess::RemoveAt_guess
    void RemoveAt_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0059C3B0 AtlasLoader_guess::GetText_guess
    CXStr GetText_guess();
};

struct AtlasRoot_guess {
    // EXTERNAL: TITANIUM 0x0060C0C0 AtlasRoot_guess::Get_guess
    ResourceText_guess& Get_guess(int index_guess);
    // EXTERNAL: TITANIUM 0x0060C590 AtlasRoot_guess::Set_guess
    void Set_guess(int index_guess, CXStr* text_guess);
};

struct TextControl_guess {
    // EXTERNAL: TITANIUM 0x004D987A TextControl_guess::GetText_guess
    CXStr GetText_guess();
    // EXTERNAL: TITANIUM 0x004DA486 TextControl_guess::SetText_guess
    void SetText_guess(CXStr* text_guess);
};

struct SkinManager_guess {
    // EXTERNAL: TITANIUM 0x005F6F20 SkinManager_guess::FindSkin_guess
    int FindSkin_guess(char* text_guess);
};

// EXTERNAL: TITANIUM 0x0060BF20 SetAtlasSetting_guess
void __cdecl SetAtlasSetting_guess(const char* section_guess, const char* key_guess, char* value_guess);

#define g_skinManager_guess EQ_GLOBAL(SkinManager_guess*, 0x00905CC0)
#define g_skinError_guess EQ_GLOBAL(int, 0x00924470)
#define g_mapScaleLarge_guess EQ_GLOBAL(float, 0x00658CD0)
#define g_mapScaleSmall_guess EQ_GLOBAL(float, 0x00658CCC)
#define g_mapBounds_guess EQ_GLOBAL(float, 0x006431A0)
#define g_mapBoundsSmall_guess EQ_GLOBAL(float, 0x00642F60)
#define g_mapBoundsTop_guess EQ_GLOBAL(float, 0x0063F4D0)
#define g_mapError_guess EQ_GLOBAL(MapBoundsSource_guess*, 0x0099E368)

struct ControlWindow_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Action_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void Slot63_guess() = 0;
    virtual void Slot64_guess() = 0;
    virtual void Slot65_guess() = 0;
    virtual void Slot66_guess() = 0;
    virtual void Slot67_guess() = 0;
    virtual void Slot68_guess() = 0;
    virtual void Slot69_guess() = 0;
    virtual void Slot70_guess() = 0;
    virtual void Slot71_guess() = 0;
    virtual void Slot72_guess() = 0;
    virtual void Slot73_guess() = 0;
    virtual void Slot74_guess() = 0;
    virtual void Slot75_guess() = 0;
    virtual CXStr GetText_guess() = 0;
};

struct MapBoundsSource_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual int GetBounds_guess(float* first_guess, float* second_guess) = 0;
};

struct RefreshManager_guess {
    // EXTERNAL: TITANIUM 0x005BC460 RefreshManager_guess::Refresh_guess
    void Refresh_guess(void* manager_guess, int value_guess);
};

#define g_atlasRoot_guess EQ_GLOBAL(AtlasRoot_guess, 0x0099E414)
#define g_atlasScanFirst_guess EQ_GLOBAL(unsigned int, 0x00991CF8)
#define g_atlasScanSecond_guess EQ_GLOBAL(unsigned int, 0x00991CFC)

// EXTERNAL: TITANIUM 0x0060E450 CopyEntryText_guess
void __cdecl CopyEntryText_guess(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x0060E985 operator_new_text_guess
void* __cdecl operator_new_text_guess(unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060F60D _fabs
extern "C" double __cdecl _fabs(double value_guess);
// EXTERNAL: TITANIUM 0x00574110 FUN_00574110_guess
void __cdecl FUN_00574110_guess(const char* format_guess, ...);

#define g_resourceCatalog_guess EQ_GLOBAL(ResourceCatalog_guess*, 0x0099D3EC)
#define g_activeSlot_guess EQ_GLOBAL(ActiveSlot_guess*, 0x0099D3EC)
#define g_flag_991d02_guess EQ_GLOBAL(unsigned char, 0x00991D02)
#define g_flag_991d00_guess EQ_GLOBAL(unsigned char, 0x00991D00)

#define g_queueHead_guess EQ_GLOBAL(QueueEntry_guess*, 0x00991D10)

#define pinstCMapToolbarWnd_guess EQ_GLOBAL(MessageManager_guess*, 0x00850C00)
#define g_firstTripleFirst_guess EQ_GLOBAL(unsigned int, 0x00991D2C)
#define g_firstTripleSecond_guess EQ_GLOBAL(unsigned int, 0x00991D30)
#define g_firstTripleThird_guess EQ_GLOBAL(unsigned int, 0x00991D34)
#define g_secondTripleFirst_guess EQ_GLOBAL(unsigned int, 0x00991D40)
#define g_secondTripleSecond_guess EQ_GLOBAL(unsigned int, 0x00991D44)
#define g_secondTripleThird_guess EQ_GLOBAL(unsigned int, 0x00991D48)
#define g_selectedValue_guess EQ_GLOBAL(unsigned int, 0x00991CF4)
#define g_selectionReady_guess EQ_GLOBAL(unsigned char, 0x00991D0C)
#define g_viewportMode_guess EQ_GLOBAL(unsigned int, 0x00924470)
#define g_displayOffset_guess EQ_GLOBAL(DisplayOffset_guess*, 0x00905CE4)
#define g_offsetClamp_guess EQ_GLOBAL(double, 0x00793758)
#define g_positionSource_guess EQ_GLOBAL(PositionSource_guess*, 0x0099D3EC)
#define g_savedOffsetZ_guess EQ_GLOBAL(float, 0x0079376C)
#define g_savedOffsetX_guess EQ_GLOBAL(float, 0x00793764)
#define g_savedOffsetY_guess EQ_GLOBAL(float, 0x00793768)
#define g_offsetSentinel_guess EQ_GLOBAL(float, 0x00658990)
#define g_distanceFour_guess EQ_GLOBAL(double, 0x00640FB8)
#define g_distanceHundred_guess EQ_GLOBAL(double, 0x00640FC8)
#define g_distanceFourHundred_guess EQ_GLOBAL(double, 0x00658980)
#define g_distanceNineHundred_guess EQ_GLOBAL(double, 0x00658970)
#define g_changeFivePercent_guess EQ_GLOBAL(double, 0x00658988)
#define g_changeOnePercent_guess EQ_GLOBAL(double, 0x00658978)
#define g_changeHalfPercent_guess EQ_GLOBAL(double, 0x00658968)
#define g_changeTenthPercent_guess EQ_GLOBAL(double, 0x00658960)
#define g_initialRatio_guess EQ_GLOBAL(double, 0x00658958)
#define g_halfDistance_guess EQ_GLOBAL(double, 0x006410A0)
#define g_clampSentinel_guess EQ_GLOBAL(double, 0x006588F8)
#define g_drawTarget_guess EQ_GLOBAL(DrawTarget_guess*, 0x0099E364)

typedef void* (__cdecl *ElementConstructorFunction_guess)(void*);
#define g_elementConstructorAddress_guess EQ_ARRAY(char, 0x00451A9B)

// EXTERNAL: TITANIUM 0x00401000 VectorConstructorIterator_guess
void __stdcall VectorConstructorIterator_guess(void* first_guess, unsigned int size_guess, int count_guess, ElementConstructorFunction_guess constructor_guess);

// EXTERNAL: TITANIUM 0x0060D0D5 free
extern "C" void __cdecl free(void* memory_guess);
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);
// EXTERNAL: TITANIUM 0x0060E985 AllocateText_guess
void* __cdecl AllocateText_guess(unsigned int size_guess);

// Scalar deleting destructor of the map toolbar window (vtable 0x6586A8 slot 1, ctor 0x005317CC):
// destroys it and frees it when flag 1 is set.
// FUNCTION: TITANIUM 0x00531BE8
void* Target31c04_guess::Delete_guess(unsigned char flags_guess) {
    this->Target31c04_guess::~Target31c04_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the map toolbar window: expires every confirmation dialog its dialog-owner part
// (+0x15C) opened (0x005482A0, all messages), then runs the CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x00531C04
Target31c04_guess::~Target31c04_guess() {
    Secondary31c04_guess* value_guess = this != 0 ? (Secondary31c04_guess*)&member_guess : 0;
    value_guess->Secondary31c04_guess::~Secondary31c04_guess();
}

// Whether two rects are equal (left, top, right, bottom). The label placement routines compare
// candidate boxes with it.
// FUNCTION: TITANIUM 0x00531C4A
char Rect_guess::Equal_guess(Rect_guess* other_guess) {
    if (left_guess == other_guess->left_guess &&
        top_guess == other_guess->top_guess &&
        right_guess == other_guess->right_guess &&
        bottom_guess == other_guess->bottom_guess) {
        return 1;
    }
    return 0;
}

// Swaps the edges so that left <= right and top <= bottom. The map's drag selection runs from the press
// point to the cursor, so either corner can come first.
// FUNCTION: TITANIUM 0x00531C75
void Rect_guess::NormalizeRect_guess() {
    if (left_guess > right_guess) {
        int temp_guess = left_guess;
        left_guess = right_guess;
        right_guess = temp_guess;
    }
    if (top_guess > bottom_guess) {
        int temp_guess = top_guess;
        top_guess = bottom_guess;
        bottom_guess = temp_guess;
    }
}

// EXTERNAL: TITANIUM 0x0060F81E Span_guess
int __cdecl Span_guess(int value_guess);

// Sets the map extents (x min/max, y min/max) and works out the zoom steps for them.
// FUNCTION: TITANIUM 0x00531C94
// @early-stop: budget, structural ndiff=13
void DestroyObject_guess::Apply_guess(int first_value_guess, int second_value_guess,
    int third_value_guess, int fourth_value_guess) {
    Scale_guess* scale_guess = (Scale_guess*)this;
    if (scale_guess->ratio_guess == 0.0f) {
        scale_guess->ratio_guess = (float)Span_guess(second_value_guess - first_value_guess) * 0.005f;
        scale_guess->count_guess = 200;
    } else {
        int count_value_guess;
        if (scale_guess->ratio_guess != 1.0f) {
            float quotient_guess = (float)(_fabs((double)(scale_guess->third_guess - scale_guess->first_guess)) / scale_guess->ratio_guess);
            int span_value_guess = second_value_guess - first_value_guess;
            if (quotient_guess < (float)Span_guess(span_value_guess)) {
                scale_guess->ratio_guess = (float)Span_guess(span_value_guess) / quotient_guess;
                count_value_guess = (int)quotient_guess;
            } else {
                scale_guess->ratio_guess = 1.0f;
                count_value_guess = Span_guess(span_value_guess);
            }
        } else {
            count_value_guess = (int)_fabs((double)(second_value_guess - first_value_guess));
        }
        scale_guess->count_guess = count_value_guess;
    }
    scale_guess->ready_guess = 1;
    scale_guess->first_guess = (float)first_value_guess;
    scale_guess->third_guess = (float)second_value_guess;
    scale_guess->second_guess = (float)third_value_guess;
    scale_guess->fourth_guess = (float)fourth_value_guess;
}

// Stores four integer bounds as floats (+0x10..+0x1C) and marks them set (+0x81). The map window
// constructor (0x00535CAA) sets the map object's initial bounds with it.
// FUNCTION: TITANIUM 0x00531D83
void ValueBounds_guess::Set_guess(int first_value_guess, int second_value_guess, int third_value_guess, int fourth_value_guess) {
    first_guess = (float)first_value_guess;
    enabled_guess = 1;
    second_guess = (float)second_value_guess;
    third_guess = (float)third_value_guess;
    fourth_guess = (float)fourth_value_guess;
}

// Sets the zoom; when that leaves fewer than 5 steps across the map, the step is a fifth of the width.
// FUNCTION: TITANIUM 0x00531DA9
void Scale_guess::Update_guess(float value_guess) {
    ratio_guess = value_guess;
    if (value_guess == 1.0f || value_guess == 0.0f) {
        count_guess = (int)_fabs((double)(third_guess - first_guess));
    } else {
        count_guess = (int)(_fabs((double)(third_guess - first_guess)) / ratio_guess);
        if (count_guess < 5) {
            ratio_guess = (float)_fabs((double)(third_guess - first_guess)) * 0.2f;
            count_guess = 5;
        }
    }
    ready_guess = 1;
}

// Map input gate: false when the control at +0x1DC is in use (+0x1D8 set) but not really visible
// (0x0059FEC0); else true. The left-button, mouse-wheel and pan/zoom handlers stop on false.
// FUNCTION: TITANIUM 0x00531E41
char PermissionTarget_guess::Permit_guess() {
    if (enabled_guess != 0 && !gate_guess->IsReallyVisible()) {
        return 0;
    }
    return 1;
}

// Map window OnShow (vtable 0x658BA0 slot 35): on hide, also closes the map toolbar (0x850C00) when it
// is open; then the CSidlScreenWnd OnShow (0x005A1880).
// FUNCTION: TITANIUM 0x00531E5D
void RefreshTarget_guess::Refresh_guess() {
    if (refreshed_guess == 0 && pinstCMapToolbarWnd_guess != 0 &&
        pinstCMapToolbarWnd_guess->Check_guess()) {
        pinstCMapToolbarWnd_guess->Dispatch_guess();
    }
    OnShow();
}

// Map window, vtable 0x658BA0 slot 15: passes (`first`, `second`) on to the parent window's slot 15
// (+0x28); 0 without a parent.
// FUNCTION: TITANIUM 0x00531EE0
int ForwardOwner_guess::Dispatch_guess(int first_guess, int second_guess) {
    if (target_28_guess != 0) {
        return target_28_guess->Forward_guess(first_guess, second_guess);
    }
    return 0;
}

// EXTERNAL: TITANIUM 0x00559545 NewUIINI
int __cdecl NewUIINI();

// Edit box child: SetWindowText is the virtual at slot 63 (0xFC).
struct IniEdit_guess {
    virtual void Slot00_guess() = 0;
    virtual void Slot01_guess() = 0;
    virtual void Slot02_guess() = 0;
    virtual void Slot03_guess() = 0;
    virtual void Slot04_guess() = 0;
    virtual void Slot05_guess() = 0;
    virtual void Slot06_guess() = 0;
    virtual void Slot07_guess() = 0;
    virtual void Slot08_guess() = 0;
    virtual void Slot09_guess() = 0;
    virtual void Slot10_guess() = 0;
    virtual void Slot11_guess() = 0;
    virtual void Slot12_guess() = 0;
    virtual void Slot13_guess() = 0;
    virtual void Slot14_guess() = 0;
    virtual void Slot15_guess() = 0;
    virtual void Slot16_guess() = 0;
    virtual void Slot17_guess() = 0;
    virtual void Slot18_guess() = 0;
    virtual void Slot19_guess() = 0;
    virtual void Slot20_guess() = 0;
    virtual void Slot21_guess() = 0;
    virtual void Slot22_guess() = 0;
    virtual void Slot23_guess() = 0;
    virtual void Slot24_guess() = 0;
    virtual void Slot25_guess() = 0;
    virtual void Slot26_guess() = 0;
    virtual void Slot27_guess() = 0;
    virtual void Slot28_guess() = 0;
    virtual void Slot29_guess() = 0;
    virtual void Slot30_guess() = 0;
    virtual void Slot31_guess() = 0;
    virtual void Slot32_guess() = 0;
    virtual void Slot33_guess() = 0;
    virtual void Slot34_guess() = 0;
    virtual void Slot35_guess() = 0;
    virtual void Slot36_guess() = 0;
    virtual void Slot37_guess() = 0;
    virtual void Slot38_guess() = 0;
    virtual void Slot39_guess() = 0;
    virtual void Slot40_guess() = 0;
    virtual void Slot41_guess() = 0;
    virtual void Slot42_guess() = 0;
    virtual void Slot43_guess() = 0;
    virtual void Slot44_guess() = 0;
    virtual void Slot45_guess() = 0;
    virtual void Slot46_guess() = 0;
    virtual void Slot47_guess() = 0;
    virtual void Slot48_guess() = 0;
    virtual void Slot49_guess() = 0;
    virtual void Slot50_guess() = 0;
    virtual void Slot51_guess() = 0;
    virtual void Slot52_guess() = 0;
    virtual void Slot53_guess() = 0;
    virtual void Slot54_guess() = 0;
    virtual void Slot55_guess() = 0;
    virtual void Slot56_guess() = 0;
    virtual void Slot57_guess() = 0;
    virtual void Slot58_guess() = 0;
    virtual void Slot59_guess() = 0;
    virtual void Slot60_guess() = 0;
    virtual void Slot61_guess() = 0;
    virtual void Slot62_guess() = 0;
    virtual void SetWindowText_guess(const CXStr& text_guess) = 0;
};

// Map window fields read by the ini save and load (offsets from MapViewWnd_guess).
struct MapViewIniFields_guess {
    char pad_000_guess[0x140];
    CXStr section_140_guess;       // 0x140, CXStr passed as char*
    char pad_144_guess[0x1a0 - 0x144];
    CButtonWnd* button_1a0_guess;  // 0x1a0, SetCheck
    IniEdit_guess* edit_1a4_guess; // 0x1a4, height low text
    IniEdit_guess* edit_1a8_guess; // 0x1a8, height high text
    CButtonWnd* button_1ac_guess;  // 0x1ac, SetCheck
    char pad_1b0_guess[0x258 - 0x1b0];
    int height_low_258_guess;      // 0x258
    int height_high_25c_guess;     // 0x25c
    bool filter_260_guess;         // 0x260
    char pad_261_guess[0x26c - 0x261];
    bool labels_26c_guess;         // 0x26c
    bool changed_26d_guess;        // 0x26d
    void StoreIniInfo_guess();
    void LoadIniInfo_guess();
};

// EXTERNAL: TITANIUM 0x0055958A LoadStringFromUIIniFile_guess
void __cdecl LoadStringFromUIIniFile_guess(char* section_guess, const char* key_guess, char* default_guess, char* value_guess, int size_guess, int flag_guess);

// Restores LabelsActive, HeightFilter, HeightLow and HeightHigh from the window's INI section and sets the
// controls to match.
// FUNCTION: TITANIUM 0x00531F44
// @early-stop: budget, structural ndiff=53
void MapViewIniFields_guess::LoadIniInfo_guess() {
    char text_guess[256];
    char value_guess[256];
    char low_guess[64];
    char high_guess[64];
    if (NewUIINI() != 0) {
        sprintf(text_guess, "%s", labels_26c_guess ? "true" : "false");
        LoadStringFromUIIniFile_guess(section_140_guess, "LabelsActive", text_guess, value_guess, 0x100, 1);
        labels_26c_guess = value_guess[0] == 't' || value_guess[0] == 'T' || value_guess[0] == '1';
        changed_26d_guess = true;

        sprintf(text_guess, "%s", filter_260_guess ? "true" : "false");
        LoadStringFromUIIniFile_guess(section_140_guess, "HeightFilter", text_guess, value_guess, 0x100, 1);
        filter_260_guess = value_guess[0] == 't' || value_guess[0] == 'T' || value_guess[0] == '1';
        changed_26d_guess = true;

        sprintf(text_guess, "%d", height_low_258_guess);
        LoadStringFromUIIniFile_guess(section_140_guess, "HeightLow", text_guess, value_guess, 0x100, 1);
        height_low_258_guess = atoi(value_guess);
        changed_26d_guess = true;

        sprintf(text_guess, "%d", height_high_25c_guess);
        LoadStringFromUIIniFile_guess(section_140_guess, "HeightHigh", text_guess, value_guess, 0x100, 1);
        height_high_25c_guess = atoi(value_guess);
        changed_26d_guess = true;

        if (button_1a0_guess != 0) {
            bool labels_checked_guess = labels_26c_guess;
            button_1a0_guess->SetCheck(labels_checked_guess);
        }
        if (button_1ac_guess != 0) {
            bool filter_checked_guess = filter_260_guess;
            button_1ac_guess->SetCheck(filter_checked_guess);
        }
        if (edit_1a4_guess != 0) {
            edit_1a4_guess->SetWindowText_guess(CXStr(_itoa(height_low_258_guess, low_guess, 10)));
        }
        if (edit_1a8_guess != 0) {
            edit_1a8_guess->SetWindowText_guess(CXStr(_itoa(height_high_25c_guess, high_guess, 10)));
        }
        ((CSidlScreenWnd*)this)->LoadIniInfo();
    }
}

// Saves LabelsActive, HeightFilter, HeightLow and HeightHigh.
// FUNCTION: TITANIUM 0x00532250
void MapViewIniFields_guess::StoreIniInfo_guess() {
    char buf_guess[256];
    if (NewUIINI() != 0) {
        sprintf(buf_guess, "%s", labels_26c_guess ? "true" : "false");
        SetAtlasSetting_guess(section_140_guess, "LabelsActive", buf_guess);

        sprintf(buf_guess, "%s", filter_260_guess ? "true" : "false");
        SetAtlasSetting_guess(section_140_guess, "HeightFilter", buf_guess);

        sprintf(buf_guess, "%d", height_low_258_guess);
        SetAtlasSetting_guess(section_140_guess, "HeightLow", buf_guess);

        sprintf(buf_guess, "%d", height_high_25c_guess);
        SetAtlasSetting_guess(section_140_guess, "HeightHigh", buf_guess);

        ((CSidlScreenWnd*)this)->StoreIniInfo();
    }
}

// Map defaults: layers 0-3 shown (flags 0xF), new lines go to layer 1, height filter 10 below and above.
// FUNCTION: TITANIUM 0x0053236E
InitObject_guess::InitObject_guess() {
    field_78_guess = 0.0f;
    field_40_guess = 0;
    field_44_guess = 0;
    field_48_guess = 0;
    field_5c_guess = 0;
    field_5b_guess = 0xff;
    field_5a_guess = 0;
    field_59_guess = 0;
    field_58_guess = 0;
    field_64_guess = 0xf;
    field_68_guess = 1;
    field_6c_guess = 10;
    field_70_guess = 10;
    field_74_guess = 0;
    field_80_guess = 1;
}

// Frees both node chains (the second one's nodes own an allocation each) and resets the counters and
// extents; +0x80 = 1.
// FUNCTION: TITANIUM 0x005323B2
DestroyObject_guess::~DestroyObject_guess() {
    while (first_guess != 0) {
        SimpleNode_guess* next_guess = first_guess->next_guess;
        free(first_guess);
        first_guess = next_guess;
    }
    while (second_guess != 0) {
        AllocatedNode_guess* next_guess = second_guess->next_guess;
        free(second_guess->allocation_guess);
        free(second_guess);
        second_guess = next_guess;
    }
    field_48_guess = 0;
    field_5c_guess = 0;
    field_64_guess = 0;
    field_68_guess = 0;
    field_6c_guess = 0;
    field_70_guess = 0;
    field_74_guess = 0;
    field_80_guess = 1;
}

// Frees both node chains (the second one's nodes own an allocation each) and zeroes +0x48, +0x5C, +0x60.
// FUNCTION: TITANIUM 0x00532410
ClearObject_guess::~ClearObject_guess() {
    while (first_guess != 0) {
        SimpleNode_guess* next_guess = first_guess->next_guess;
        free(first_guess);
        first_guess = next_guess;
    }
    while (second_guess != 0) {
        AllocatedNode_guess* next_guess = second_guess->next_guess;
        free(second_guess->allocation_guess);
        free(second_guess);
        second_guess = next_guess;
    }
    field_48_guess = 0;
    field_5c_guess = 0;
    field_60_guess = 0;
}

// Sets the start point of a recorded line.
// FUNCTION: TITANIUM 0x0053245B
void Event_guess::Submit_guess(float first_value_guess, float second_value_guess, float third_value_guess) {
    if (enabled_guess != 0) {
        first_guess = first_value_guess;
        second_guess = second_value_guess;
        third_guess = third_value_guess;
        ready_guess = 1;
    }
}

// Constructs the two 0xC-byte points at +8 of a new map line record (0x00451A9B on each). Line
// recording and layer loading build their records with it.
// FUNCTION: TITANIUM 0x00532480
ElementList_guess* ElementList_guess::Initialize_guess() {
    VectorConstructorIterator_guess(&pad_00_guess[8], 0xc, 2,
        (ElementConstructorFunction_guess)g_elementConstructorAddress_guess);
    return this;
}

// Deletes the selected lines.
// FUNCTION: TITANIUM 0x00532499
void ClearObject_guess::RemoveSelectedLines_guess() {
    PendingEntry_guess* entry_guess = field_5c_guess;
    while (entry_guess != 0) {
        PendingEntry_guess* next_entry_guess = entry_guess->next_guess;
        SimpleNode_guess* prev_guess = entry_guess->node_guess->prev_guess;
        if (prev_guess != 0) {
            SimpleNode_guess* next_node_guess = entry_guess->node_guess->next_guess;
            prev_guess->next_guess = next_node_guess;
            if (next_node_guess != 0) {
                next_node_guess->prev_guess = prev_guess;
            }
        } else if (entry_guess->node_guess->next_guess != 0) {
            entry_guess->node_guess->next_guess->prev_guess = 0;
            first_guess = entry_guess->node_guess->next_guess;
        } else {
            first_guess = 0;
        }
        free(entry_guess);
        entry_guess = next_entry_guess;
    }
    field_5c_guess = 0;
}

// Deletes the selected point.
// FUNCTION: TITANIUM 0x005324ED
void ClearObject_guess::RemoveSelectedLabel_guess() {
    if (field_60_guess != 0) {
        AllocatedNode_guess* previous_guess = field_60_guess->prev_guess;
        AllocatedNode_guess* next_guess = field_60_guess->next_guess;
        if (previous_guess != 0) {
            previous_guess->next_guess = next_guess;
            if (next_guess != 0) {
                next_guess->prev_guess = previous_guess;
            }
        } else if (next_guess != 0) {
            next_guess->prev_guess = 0;
            second_guess = field_60_guess->next_guess;
        } else {
            second_guess = 0;
        }
        free(field_60_guess->allocation_guess);
        field_60_guess->allocation_guess = 0;
        free(field_60_guess);
        field_60_guess = 0;
    }
}

// Sets a map label target's height and position (+0x08 float, +0x0C, +0x10). The map toolbar uses it
// when placing a label at the player's position.
// FUNCTION: TITANIUM 0x00532543
void __stdcall SetLabelPosition_guess(TargetData_guess* target_guess, float value_guess, int first_guess, int second_guess) {
    target_guess->value_08_guess = value_guess;
    target_guess->value_0c_guess = first_guess;
    target_guess->value_10_guess = second_guess;
}

// Label placement: counts the placed boxes that overlap the candidate box.
// FUNCTION: TITANIUM 0x0053255F
int __cdecl CountMatchingEntries_guess(int first_guess, int second_guess, int third_guess, int fourth_guess) {
    int count_guess = 0;
    QueueEntry_guess* entry_guess = g_queueHead_guess;
    if (entry_guess != 0) {
        Rect_guess converted_guess;
        Rect_guess invalid_guess;
        invalid_guess.left_guess = -1;
        invalid_guess.top_guess = -1;
        invalid_guess.right_guess = -1;
        invalid_guess.bottom_guess = -1;
        do {
            ((ArgumentContext_guess*)&first_guess)->Convert_guess(&converted_guess, &entry_guess->x_0004_guess);
            if (!converted_guess.Equal_guess(&invalid_guess) &&
                second_guess != entry_guess->value_10_guess &&
                fourth_guess != entry_guess->y_0008_guess &&
                first_guess != entry_guess->value_0c_guess &&
                third_guess != entry_guess->x_0004_guess) {
                ++count_guess;
            }
            entry_guess = entry_guess->next_guess;
        } while (entry_guess != 0);
    }
    return count_guess;
}

// As CountMatchingEntries_guess, but skipping the label being placed.
// FUNCTION: TITANIUM 0x005325D0
int __cdecl CountMatchingEntriesExcept_guess(int first_guess, int second_guess, int third_guess, int fourth_guess, QueueEntry_guess* except_guess) {
    int count_guess = 0;
    for (QueueEntry_guess* entry_guess = g_queueHead_guess; entry_guess != 0; entry_guess = entry_guess->next_guess) {
        if (entry_guess != except_guess) {
            Rect_guess converted_guess;
            Rect_guess invalid_guess;
            ((ArgumentContext_guess*)&first_guess)->Convert_guess(&converted_guess, &entry_guess->x_0004_guess);
            invalid_guess.left_guess = -1;
            invalid_guess.top_guess = -1;
            invalid_guess.right_guess = -1;
            invalid_guess.bottom_guess = -1;
            if (!converted_guess.Equal_guess(&invalid_guess) &&
                second_guess != entry_guess->value_10_guess &&
                fourth_guess != entry_guess->y_0008_guess &&
                first_guess != entry_guess->value_0c_guess &&
                third_guess != entry_guess->x_0004_guess) {
                ++count_guess;
            }
        }
    }
    return count_guess;
}

// Candidate box `index_guess` (0-23) for a label of the given size at a point: above, below, right or left of
// it, at several heights.
// FUNCTION: TITANIUM 0x0053264A
// @early-stop: budget, structural ndiff=165
Block16_guess* __cdecl BuildBlock_guess(Block16_guess* out_guess, int index_guess, int first_guess, int second_guess, int third_guess, int fourth_guess) {
    Rect_guess rect_guess;
    int right_guess = first_guess + third_guess;
    int bottom_guess = second_guess + fourth_guess;
    rect_guess.right_guess = right_guess;
    rect_guess.left_guess = first_guess;
    rect_guess.top_guess = second_guess;
    rect_guess.bottom_guess = bottom_guess;
    rect_guess.NormalizeRect_guess();
    switch (index_guess) {
    case 0:
        rect_guess.left_guess += third_guess / -2;
        rect_guess.right_guess += third_guess / -2;
        rect_guess.top_guess += -2 - fourth_guess;
        rect_guess.bottom_guess += -2 - fourth_guess;
        break;
    case 1:
        rect_guess.top_guess += 2;
        rect_guess.bottom_guess += 2;
        rect_guess.left_guess += third_guess / -2;
        rect_guess.right_guess += third_guess / -2;
        break;
    case 2:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += fourth_guess / -2;
        rect_guess.bottom_guess += fourth_guess / -2;
        break;
    case 3:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += -fourth_guess;
        rect_guess.bottom_guess += -fourth_guess;
        break;
    case 4:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        break;
    case 5:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += fourth_guess / -2;
        rect_guess.bottom_guess += fourth_guess / -2;
        break;
    case 6:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += -fourth_guess;
        rect_guess.bottom_guess += -fourth_guess;
        break;
    case 7:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        break;
    case 8:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += -fourth_guess - fourth_guess / 2;
        rect_guess.bottom_guess += -fourth_guess - fourth_guess / 2;
        break;
    case 9:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += fourth_guess / 2;
        rect_guess.bottom_guess += fourth_guess / 2;
        break;
    case 10:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += -fourth_guess - fourth_guess / 2;
        rect_guess.bottom_guess += -fourth_guess - fourth_guess / 2;
        break;
    case 11:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += fourth_guess / 2;
        rect_guess.bottom_guess += fourth_guess / 2;
        break;
    case 12:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += -2 * fourth_guess;
        rect_guess.bottom_guess += -2 * fourth_guess;
        break;
    case 13:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += fourth_guess;
        rect_guess.bottom_guess += fourth_guess;
        break;
    case 14:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += -2 * fourth_guess;
        rect_guess.bottom_guess += -2 * fourth_guess;
        break;
    case 15:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += fourth_guess;
        rect_guess.bottom_guess += fourth_guess;
        break;
    case 16:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += -2 * fourth_guess - fourth_guess / 2;
        rect_guess.bottom_guess += -2 * fourth_guess - fourth_guess / 2;
        break;
    case 17:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += fourth_guess + fourth_guess / 2;
        rect_guess.bottom_guess += fourth_guess + fourth_guess / 2;
        break;
    case 18:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += -2 * fourth_guess - fourth_guess / 2;
        rect_guess.bottom_guess += -2 * fourth_guess - fourth_guess / 2;
        break;
    case 19:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += fourth_guess + fourth_guess / 2;
        rect_guess.bottom_guess += fourth_guess + fourth_guess / 2;
        break;
    case 20:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += -3 * fourth_guess;
        rect_guess.bottom_guess += -3 * fourth_guess;
        break;
    case 21:
        rect_guess.left_guess += 4;
        rect_guess.right_guess += 4;
        rect_guess.top_guess += 2 * fourth_guess;
        rect_guess.bottom_guess += 2 * fourth_guess;
        break;
    case 22:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += -3 * fourth_guess;
        rect_guess.bottom_guess += -3 * fourth_guess;
        break;
    case 23:
        rect_guess.left_guess += -4 - third_guess;
        rect_guess.right_guess += -4 - third_guess;
        rect_guess.top_guess += 2 * fourth_guess;
        rect_guess.bottom_guess += 2 * fourth_guess;
        break;
    }
    out_guess->first_guess = rect_guess.left_guess;
    out_guess->second_guess = rect_guess.top_guess;
    out_guess->third_guess = rect_guess.right_guess;
    out_guess->fourth_guess = rect_guess.bottom_guess;
    return out_guess;
}
// EXTERNAL: TITANIUM 0x005325D0 CountMatchingEntry_guess
int __cdecl CountMatchingEntry_guess(Block16Entry_guess box_guess, QueueEntry_guess* except_guess);

// The candidate box with the fewest overlaps (under 50); stops at the first with none.
// FUNCTION: TITANIUM 0x00532899
int __cdecl FindBestIndex_guess(int first_guess, int second_guess, int third_guess, int fourth_guess,
    QueueEntry_guess* except_guess, int unused_guess) {
    Block16Entry_guess box_guess;
    box_guess.fourth_guess = 0;
    box_guess.third_guess = 0;
    box_guess.second_guess = 0;
    box_guess.first_guess = 0;
    int best_index_guess = -1;
    int best_count_guess = 0x32;
    for (int i_guess = 0; i_guess < 0x18; ++i_guess) {
        Block16_guess built_guess;
        Block16_guess saved_guess;
        box_guess.CopyTo_guess(&saved_guess, BuildBlock_guess(&built_guess, i_guess, first_guess, second_guess, third_guess, fourth_guess));
        int count_guess = CountMatchingEntry_guess(box_guess, except_guess);
        if (count_guess < best_count_guess) {
            best_count_guess = count_guess;
            best_index_guess = i_guess;
            if (count_guess == 0) {
                break;
            }
        }
    }
    return best_index_guess;
}

// One improvement pass: moves every label to its least-overlapping candidate box.
// FUNCTION: TITANIUM 0x00532921
void __cdecl ProcessQueue_guess() {
    for (QueueEntry_guess* entry_guess = g_queueHead_guess; entry_guess != 0; entry_guess = entry_guess->next_guess) {
        if (entry_guess->enabled_guess != 0) {
            int count_guess = CountMatchingEntry_guess(entry_guess->block_guess, entry_guess);
            int x_guess = entry_guess->x_0004_guess - entry_guess->owner_guess->field_2c_guess;
            int y_guess = entry_guess->y_0008_guess - entry_guess->owner_guess->field_30_guess;
            int field_24_guess = entry_guess->owner_guess->field_24_guess;
            int field_28_guess = entry_guess->owner_guess->field_28_guess;
            int best_guess = FindBestIndex_guess(x_guess, y_guess, field_24_guess, field_28_guess, entry_guess, count_guess);
            if (best_guess >= 0) {
                Block16_guess built_guess;
                Block16_guess saved_guess;
                entry_guess->block_guess.CopyTo_guess(&saved_guess, BuildBlock_guess(&built_guess, best_guess, x_guess, y_guess, field_24_guess, field_28_guess));
                entry_guess->owner_guess->field_2c_guess = entry_guess->x_0004_guess - x_guess;
                entry_guess->owner_guess->field_30_guess = entry_guess->y_0008_guess - y_guess;
            }
        }
    }
}

// Whether layer `index_guess` (0-3) is shown.
// FUNCTION: TITANIUM 0x005329C2
char FlagSet_guess::Test_guess(int index_guess) {
    if (index_guess > 3) {
        return false;
    }
    return (flags_guess & (1 << index_guess)) != 0;
}

// Whether the point at `arg0_guess` lies in the rectangle at (arg1 + +0x1C, arg2 + +0x18) of width +0x10
// and height +0x14.
// FUNCTION: TITANIUM 0x005329DF
char Viewport_guess::ContainsPoint_guess(int arg0_guess, int arg1_guess, int arg2_guess,
    int arg3_guess, int arg4_guess) {
    Bounds_guess bounds_guess;
    bounds_guess.top_guess = (int)((float)arg2_guess + field_18_guess);
    bounds_guess.left_guess = (int)((float)arg1_guess + field_1c_guess);
    bounds_guess.bottom_guess = (int)((float)bounds_guess.top_guess + viewHeight_0014_guess);
    bounds_guess.right_guess = (int)((float)bounds_guess.left_guess + viewWidth_0010_guess);
    return bounds_guess.Contains_guess((CXPoint*)arg0_guess);
}

// Fits the map extents into the render area with one scale for both axes, centred. Zoomed in on the current
// zone's map (+0x84 equals the zone id at 0x924470), it centres on the player.
// FUNCTION: TITANIUM 0x00532A30
// @early-stop: budget, structural ndiff=37
void Viewport_guess::UpdateLayout_guess() {
    float width_guess = right_0008_guess - left_0000_guess;
    scaleX_0038_guess = viewWidth_0010_guess / width_guess;
    float height_guess = bottom_000c_guess - top_0004_guess;
    scaleY_003c_guess = viewHeight_0014_guess / height_guess;
    offsetX_0030_guess = 0.0f;
    offsetY_0034_guess = 0.0f;
    if (scaleX_0038_guess < scaleY_003c_guess) {
        float height_abs_guess = (float)_fabs((double)height_guess);
        offsetY_0034_guess = ((float)_fabs((double)height_guess) * scaleX_0038_guess -
            height_abs_guess * scaleY_003c_guess) * -0.5f;
        scaleY_003c_guess = scaleX_0038_guess;
    } else {
        float width_abs_guess = (float)_fabs((double)width_guess);
        offsetX_0030_guess = ((float)_fabs((double)width_guess) * scaleY_003c_guess -
            width_abs_guess * scaleX_0038_guess) * -0.5f;
        scaleX_0038_guess = scaleY_003c_guess;
    }
    field_28_guess = right_0008_guess;
    field_2c_guess = bottom_000c_guess;
    if (field_84_guess == g_viewportMode_guess) {
        field_28_guess = right_0008_guess - g_displayOffset_guess->field_34_guess;
        field_2c_guess = bottom_000c_guess - g_displayOffset_guess->field_30_guess;
    }
    field_28_guess *= zoom_0078_guess;
    field_2c_guess *= zoom_0078_guess;
}

// Map coordinates to render-area pixels.
// FUNCTION: TITANIUM 0x00532B2F
// Point in, transformed point out (x at [0], y at [1]).
void Viewport_guess::TransformPoint_guess(float* point_guess) {
    point_guess[0] = right_0008_guess + point_guess[0];
    point_guess[1] = bottom_000c_guess + point_guess[1];
    if (zoom_0078_guess != 1.0f) {
        float scaled_guess = zoom_0078_guess * point_guess[0];
        point_guess[0] = scaled_guess;
        point_guess[0] = scaled_guess - field_28_guess;
        scaled_guess = point_guess[1] * zoom_0078_guess;
        point_guess[1] = scaled_guess;
        point_guess[1] = scaled_guess - field_2c_guess;
    }
    point_guess[0] = scaleX_0038_guess * point_guess[0];
    point_guess[1] = scaleY_003c_guess * point_guess[1];
    if (zoom_0078_guess != 1.0f) {
        point_guess[0] = viewWidth_0010_guess * 0.5f + point_guess[0];
        point_guess[1] = viewHeight_0014_guess * 0.5f + point_guess[1];
    } else {
        point_guess[0] = offsetX_0030_guess + point_guess[0];
        point_guess[1] = offsetY_0034_guess + point_guess[1];
    }
    point_guess[0] = (float)field_20_guess + point_guess[0];
    point_guess[1] = (float)field_24_guess + point_guess[1];
}

// Writes one layer to maps\<zone>.txt (layer 0) or maps\<zone>_<n>.txt. Lines are "L x1, y1, z1, x2, y2, z2,
// r, g, b", points "P x, y, z, r, g, b, size, label" with spaces in the label written as '_'.
// FUNCTION: TITANIUM 0x00532BCD
void MapViewMap_guess::SaveEx(const char* map_name_guess, int map_index_guess) {
    char file_name_guess[256];
    char point_name_guess[256];
    FILE* file_guess;
    if (map_index_guess != 0) {
        sprintf(file_name_guess, "maps\\%s_%d.txt", map_name_guess, map_index_guess);
    } else {
        sprintf(file_name_guess, "maps\\%s.txt", map_name_guess);
    }
    file_guess = fopen(file_name_guess, "wt");
    if (file_guess != 0) {
        for (SaveLine_guess* line_guess = lines_guess; line_guess != 0; line_guess = line_guess->next_guess) {
            if (line_guess->map_index_guess == map_index_guess) {
                fprintf(file_guess, "L %0.4f, %0.4f, %0.4f,  %0.4f, %0.4f, %0.4f,  %d, %d, %d\n",
                    line_guess->first_guess, line_guess->second_guess, line_guess->third_guess,
                    line_guess->fourth_guess, line_guess->fifth_guess, line_guess->sixth_guess,
                    line_guess->third_color_guess, line_guess->second_color_guess, line_guess->first_color_guess);
            }
        }
        for (SavePoint_guess* point_guess = points_guess; point_guess != 0; point_guess = point_guess->next_guess) {
            if (point_guess->map_index_guess == map_index_guess) {
                strncpy(point_name_guess, point_guess->text_guess, 0xff);
                unsigned int index_guess = 0;
                if (strlen(point_name_guess) > 0) {
                    do {
                        if (point_name_guess[index_guess] == ' ') {
                            point_name_guess[index_guess] = '_';
                        }
                        ++index_guess;
                    } while (index_guess < strlen(point_name_guess));
                }
                fprintf(file_guess, "P %0.4f, %0.4f, %0.4f,  %d, %d, %d,  %d,  %s\n",
                    point_guess->x_guess, point_guess->y_guess, point_guess->z_guess,
                    point_guess->third_color_guess, point_guess->second_color_guess,
                    point_guess->first_color_guess, point_guess->value_18_guess, point_name_guess);
            }
        }
        fclose(file_guess);
    } else {
        FUN_00574110_guess("Failed to open %s for writing in MapViewMap::SaveEx()\n", file_name_guess);
    }
}

// Packs the colour as 0x00RRGGBB.
// FUNCTION: TITANIUM 0x00532D71
unsigned int Color_guess::GetCurrentColor_guess() {
    return ((third_guess << 8) | second_guess) << 8 | first_guess;
}

// Unpacks 0x00RRGGBB and makes it opaque.
// FUNCTION: TITANIUM 0x00532D83
void Color_guess::SetCurrentColor_guess(unsigned int value_guess) {
    third_guess = (unsigned char)(value_guess >> 16);
    marker_guess = 0xff;
    second_guess = (unsigned char)(value_guess >> 8);
    first_guess = (unsigned char)value_guess;
}

// Adds a line to the selection once; a null line clears the selection.
// FUNCTION: TITANIUM 0x00532DA1
void ColorOwner_guess::AddLineToSelection_guess(PackedColor_guess* color_guess) {
    if (color_guess == 0) {
        ColorNode_guess* current_guess = this->node_guess;
        while (current_guess != 0) {
            ColorNode_guess* next_guess = current_guess->next_guess;
            free(current_guess);
            current_guess = next_guess;
        }
        this->node_guess = 0;
    } else {
        for (ColorNode_guess* node_guess = this->node_guess; node_guess != 0; node_guess = node_guess->next_guess) {
            if (color_guess == node_guess->color_guess) {
                return;
            }
        }
        ColorNode_guess* node_guess = (ColorNode_guess*)operator new(8);
        node_guess->color_guess = color_guess;
        node_guess->next_guess = this->node_guess;
        this->node_guess = node_guess;
    }
}

// Recolours every selected line.
// FUNCTION: TITANIUM 0x00532DEC
void ColorOwner_guess::SetSelectedLinesColor_guess(unsigned int value_guess) {
    for (ColorNode_guess* current_guess = this->node_guess; current_guess != 0; current_guess = current_guess->next_guess) {
        current_guess->color_guess->marker_guess = 0xff;
        current_guess->color_guess->third_guess = (unsigned char)(value_guess >> 16);
        current_guess->color_guess->second_guess = (unsigned char)(value_guess >> 8);
        current_guess->color_guess->first_guess = (unsigned char)value_guess;
    }
}

// Colour of the first selected line, 0 when none.
// FUNCTION: TITANIUM 0x00532E34
unsigned int ColorOwner_guess::GetSelectedLineColor_guess() {
    unsigned int result_guess = 0;
    if (node_guess != 0) {
        result_guess = ((node_guess->color_guess->third_guess << 8) | node_guess->color_guess->second_guess) << 8 | node_guess->color_guess->first_guess;
    }
    return result_guess;
}

// Unlinks `node_guess` from the doubly linked list (moving the head when it was first) and frees it.
// FUNCTION: TITANIUM 0x00532E53
void List_guess::Remove_guess(Node_guess* node_guess) {
    if (node_guess->prev_guess != 0) {
        Node_guess* prev_guess = node_guess->prev_guess;
        Node_guess* next_guess = node_guess->next_guess;
        prev_guess->next_guess = next_guess;
        if (next_guess != 0) {
            next_guess->prev_guess = prev_guess;
        }
    } else if (node_guess->next_guess != 0) {
        node_guess->next_guess->prev_guess = 0;
        first_guess = node_guess->next_guess;
    } else {
        first_guess = 0;
    }
    free(node_guess);
}

// Unlinks `node_guess` from the doubly linked list (moving the head when it was first) and frees it and
// its allocation.
// FUNCTION: TITANIUM 0x00532E8A
void RecyclableList_guess::RemoveAndFree_guess(RecyclableNode_guess* node_guess) {
    RecyclableNode_guess* previous_guess = node_guess->prev_guess;
    RecyclableNode_guess* next_guess = node_guess->next_guess;
    if (previous_guess != 0) {
        previous_guess->next_guess = next_guess;
        if (next_guess != 0) {
            next_guess->prev_guess = previous_guess;
        }
    } else if (next_guess != 0) {
        next_guess->prev_guess = 0;
        first_guess = node_guess->next_guess;
    } else {
        first_guess = 0;
    }
    free(node_guess->allocation_guess);
    node_guess->allocation_guess = 0;
    free(node_guess);
}

// Where the lines through two segments cross; false when they are (nearly) parallel.
// FUNCTION: TITANIUM 0x00532ECE
// @early-stop: budget, structural ndiff=9
char __cdecl IntersectSegments_guess(double x1_guess, double y1_guess, double x2_guess, double y2_guess,
                                     double x3_guess, double y3_guess, double x4_guess, double y4_guess,
                                     float* x_out_guess, float* y_out_guess) {
    double dx1_guess = x2_guess - x1_guess;
    y4_guess -= y3_guess;
    y2_guess -= y1_guess;
    x2_guess = x4_guess - x3_guess;
    x4_guess = y4_guess * dx1_guess - x2_guess * y2_guess;
    if (_fabs(x4_guess) < 0.0001) {
        return 0;
    }
    double t_guess = ((y1_guess - y3_guess) * x2_guess - (x1_guess - x3_guess) * y4_guess) / x4_guess;
    *x_out_guess = (float)(dx1_guess * t_guess + x1_guess);
    *y_out_guess = (float)(y2_guess * t_guess + y1_guess);
    return 1;
}

// Snaps the two selected lines to their crossing point: the nearer end of each moves there if some end is
// within 500 units (250000, squared). With `both_guess` only the first line moves. String 0x3AD0: not two
// lines; 0x3ACE: too far; 0x3ACF: parallel.
// FUNCTION: TITANIUM 0x00532F60
// @early-stop: budget, structural ndiff=99
void IntersectionOwner_guess::JoinAtIntersect_guess(unsigned char both_guess) {
    if (pair_guess == 0) {
        return;
    }
    if (pair_guess->first_guess == 0 || pair_guess->first_guess->state_guess != 0) {
        pEverQuest->dsp_chat(
            pStringTable->getString(0x3ad0, 0));
        return;
    }

    IntersectionSegment_guess* second_segment_guess = pair_guess->second_guess;
    IntersectionSegment_guess* first_segment_guess = pair_guess->first_guess->segment_guess;
    float intersection_x_guess = g_intersectionMax_guess;
    float intersection_y_guess = g_intersectionMax_guess;
    if (IntersectSegments_guess(
        (double)first_segment_guess->first_x_guess,
        (double)first_segment_guess->first_y_guess,
        (double)first_segment_guess->second_x_guess,
        (double)first_segment_guess->second_y_guess,
        (double)second_segment_guess->first_x_guess,
        (double)second_segment_guess->first_y_guess,
        (double)second_segment_guess->second_x_guess,
        (double)second_segment_guess->second_y_guess,
        &intersection_x_guess, &intersection_y_guess)) {

        const float first_distance_guess =
            (first_segment_guess->first_y_guess - intersection_y_guess) *
                (first_segment_guess->first_y_guess - intersection_y_guess) +
            (first_segment_guess->first_x_guess - intersection_x_guess) *
                (first_segment_guess->first_x_guess - intersection_x_guess);
        float second_distance_guess =
            (first_segment_guess->second_y_guess - intersection_y_guess) *
                (first_segment_guess->second_y_guess - intersection_y_guess) +
            (first_segment_guess->second_x_guess - intersection_x_guess) *
                (first_segment_guess->second_x_guess - intersection_x_guess);

        if (both_guess == 0) {
            float third_distance_guess =
                (second_segment_guess->first_y_guess - intersection_y_guess) *
                    (second_segment_guess->first_y_guess - intersection_y_guess) +
                (second_segment_guess->first_x_guess - intersection_x_guess) *
                    (second_segment_guess->first_x_guess - intersection_x_guess);
            float fourth_distance_guess =
                (second_segment_guess->second_y_guess - intersection_y_guess) *
                    (second_segment_guess->second_y_guess - intersection_y_guess) +
                (second_segment_guess->second_x_guess - intersection_x_guess) *
                    (second_segment_guess->second_x_guess - intersection_x_guess);
            if (first_distance_guess <= g_intersectionLimit_guess ||
                second_distance_guess <= g_intersectionLimit_guess ||
                third_distance_guess <= g_intersectionLimit_guess ||
                fourth_distance_guess <= g_intersectionLimit_guess) {
                if (second_distance_guess <= first_distance_guess) {
                    first_segment_guess->second_x_guess = intersection_x_guess;
                    first_segment_guess->second_y_guess = intersection_y_guess;
                } else {
                    first_segment_guess->first_x_guess = intersection_x_guess;
                    first_segment_guess->first_y_guess = intersection_y_guess;
                }
                if (third_distance_guess < fourth_distance_guess) {
                    second_segment_guess->first_x_guess = intersection_x_guess;
                    second_segment_guess->first_y_guess = intersection_y_guess;
                } else {
                    second_segment_guess->second_x_guess = intersection_x_guess;
                    second_segment_guess->second_y_guess = intersection_y_guess;
                }
                return;
            }
        } else if (first_distance_guess <= g_intersectionLimit_guess ||
            second_distance_guess <= g_intersectionLimit_guess) {
            if (first_distance_guess < second_distance_guess) {
                first_segment_guess->first_x_guess = intersection_x_guess;
                first_segment_guess->first_y_guess = intersection_y_guess;
            } else {
                first_segment_guess->second_x_guess = intersection_x_guess;
                first_segment_guess->second_y_guess = intersection_y_guess;
            }
            return;
        }

        pEverQuest->dsp_chat(
            pStringTable->getString(0x3ace, 0));
    } else {
        pEverQuest->dsp_chat(
            pStringTable->getString(0x3acf, 0));
    }
}

struct VirtualHost5332_guess {
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
    virtual void Slot10_guess();
    virtual void Slot11_guess();
    virtual void Slot12_guess();
    virtual int Slot13_guess(CXPoint* point_guess, int second_guess);
    virtual void Slot14_guess();
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual void Slot17_guess();
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
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
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual Rect_guess Slot57_guess();
};

struct Frame5332_guess {
    char pad_00_guess[0x20];
    int first_guess;                    // 0x20 (0x20c)
    int second_guess;                   // 0x24 (0x210)
    char pad_28_guess[0x38];
    int value_60_guess;                 // 0x60 (0x24c)
    char pad_64_guess[0x78 - 0x64];
    float ratio_78_guess;               // 0x78 (0x264)
};

struct Target5332_guess;

struct State5332_guess {
    char pad_00_guess[0x48];
    Target5332_guess* target_guess;     // 0x48
    char pad_4c_guess[0x74 - 0x4c];
    int x_guess;                        // 0x74
    int y_guess;                        // 0x78
    // EXTERNAL: TITANIUM 0x00435AA7 State5332_guess::Update_guess
    void Update_guess(Target5332_guess* target_guess);
};

struct Target5332_guess {
    char pad_00_guess[0x28];
    VirtualHost5332_guess* host_guess;      // 0x28
    char pad_2c_guess[0x1dc - 0x2c];
    VirtualHost5332_guess* gate_host_guess; // 0x1dc
    char pad_1e0_guess[0x1ec - 0x1e0];
    Frame5332_guess frame_guess;            // 0x1ec
    int Handle_guess(CXPoint* point_guess, int second_guess);
    int HandleWheel_guess(CXPoint* point_guess, int second_guess, int third_guess);
};

#define g_hostState_guess EQ_GLOBAL(State5332_guess*, 0x0099D3EC)
#define g_valueA_guess EQ_GLOBAL(int, 0x00991CFC)
#define g_valueB_guess EQ_GLOBAL(unsigned int, 0x00991CF8)
#define g_stateReady_guess EQ_GLOBAL(unsigned char, 0x00991D00)
#define g_resultReady_guess EQ_GLOBAL(unsigned char, 0x00991D02)
#define g_deltaX_guess EQ_GLOBAL(int, 0x00991D04)
#define g_deltaY_guess EQ_GLOBAL(int, 0x00991D08)
#define g_anchorX_guess EQ_GLOBAL(int, 0x00991D38)
#define g_anchorY_guess EQ_GLOBAL(int, 0x00991D3C)

// Left button in the map. With the map toolbar shown (0x850C00, probably) and no ctrl (flag 2), it picks the
// point or line under the cursor; otherwise it starts a pan by dragging. With ctrl it starts a box selection.
// FUNCTION: TITANIUM 0x005332A4
// @early-stop: budget, structural ndiff=48
int Target5332_guess::Handle_guess(CXPoint* point_guess, int second_guess) {
    if (((PermissionTarget_guess*)this)->Permit_guess()) {
        Rect_guess rect_guess = gate_host_guess->Slot57_guess();
        if (((Viewport_guess*)&frame_guess)->ContainsPoint_guess((int)point_guess,
                rect_guess.left_guess, rect_guess.top_guess, rect_guess.right_guess, rect_guess.bottom_guess)) {
            if ((EQ_GLOBAL(CXWndManager*, 0x0099D3EC)->GetKeyboardFlags() & 2) == 0) {
                if (pinstCMapToolbarWnd_guess->Check_guess()) {
                    if (g_valueA_guess != 0) {
                        frame_guess.value_60_guess = g_valueA_guess;
                        return 0;
                    }
                    frame_guess.value_60_guess = 0;
                    if (g_valueB_guess != 0) {
                        ((ColorOwner_guess*)&frame_guess)->AddLineToSelection_guess((PackedColor_guess*)g_valueB_guess);
                        return 0;
                    }
                    ((ColorOwner_guess*)&frame_guess)->AddLineToSelection_guess(0);
                }
                g_deltaX_guess = frame_guess.first_guess - g_hostState_guess->x_guess;
                g_deltaY_guess = frame_guess.second_guess - g_hostState_guess->y_guess;
                g_resultReady_guess = 1;
            } else if (g_stateReady_guess == 0) {
                if (pinstCMapToolbarWnd_guess->Check_guess()) {
                    g_anchorX_guess = g_hostState_guess->x_guess;
                    g_anchorY_guess = g_hostState_guess->y_guess;
                    g_stateReady_guess = 1;
                }
            }
            if (g_hostState_guess->target_guess != this) {
                g_hostState_guess->Update_guess(this);
            }
            return 0;
        }
    }
    if (host_guess == 0) {
        return 0;
    }
    return host_guess->Slot13_guess(point_guess, second_guess);
}

// Map extents from the lines' x and y. The x maximum is passed again as the y maximum (the y maximum is
// computed and dropped). The function has no @early-stop, so this is probably the original's bug: keep it.
// FUNCTION: TITANIUM 0x00533151
void DestroyObject_guess::ComputeBounds_guess() {
    float max3_guess = 0.0f;
    float min2_guess = 0.0f;
    float max2_guess = 0.0f;
    float min3_guess = 0.0f;
    float* node_guess = (float*)first_guess;
    for (; node_guess != 0; node_guess = *(float**)node_guess) {
        int count_guess = 2;
        float* next_guess = node_guess + 3;
        do {
            if (next_guess[-1] > max2_guess) {
                max2_guess = next_guess[-1];
            }
            if (*next_guess > max3_guess) {
                max3_guess = *next_guess;
            }
            if (next_guess[-1] < min2_guess) {
                min2_guess = next_guess[-1];
            }
            if (*next_guess < min3_guess) {
                min3_guess = *next_guess;
            }
            next_guess += 3;
        } while (--count_guess != 0);
    }
    Apply_guess((int)min2_guess, (int)max2_guess, (int)min3_guess, (int)max2_guess);
}

// Remembers a map change (zone and extents) for when the window exists; the constructor applies it.
// FUNCTION: TITANIUM 0x005331ED
void __cdecl SetSelection_guess(unsigned int selected_guess, Triple_guess* first_guess, Triple_guess* second_guess) {
    g_firstTripleFirst_guess = first_guess->first_guess;
    g_firstTripleSecond_guess = first_guess->second_guess;
    g_firstTripleThird_guess = first_guess->third_guess;
    g_secondTripleFirst_guess = second_guess->first_guess;
    g_secondTripleSecond_guess = second_guess->second_guess;
    g_secondTripleThird_guess = second_guess->third_guess;
    g_selectedValue_guess = selected_guess;
    g_selectionReady_guess = 1;
}

// Starts recording a walked line at the player's position (z minus 0.625 times +0x23C, probably the feet).
// FUNCTION: TITANIUM 0x00533238
void OffsetOwner_guess::StartAutoMap_guess() {
    if (flag_15c_guess == 0 && g_displayOffset_guess != 0 && event_guess.enabled_guess != 0) {
        if (event_guess.ready_guess != 1) {
            event_guess.Submit_guess(-g_displayOffset_guess->field_34_guess, -g_displayOffset_guess->field_30_guess,
                g_displayOffset_guess->field_38_guess - g_displayOffset_guess->field_23c_guess * 0.625f);
        }
        flag_15c_guess = 1;
        g_offsetClamp_guess = -5000.0;
    }
}

// Mouse wheel over the map: zoom in x1.5 or out x2/3, never below 1.
// FUNCTION: TITANIUM 0x005333C9
// @early-stop: budget, structural ndiff=17
int Target5332_guess::HandleWheel_guess(CXPoint* point_guess, int second_guess, int third_guess) {
    if (!((PermissionTarget_guess*)this)->Permit_guess()) {
        return 1;
    }
    Scale_guess* scale_guess = (Scale_guess*)&frame_guess;
    if (!((Viewport_guess*)&frame_guess)->ContainsRect_guess((int)point_guess, gate_host_guess->Slot57_guess())) {
        return 1;
    }
    if (second_guess > 0) {
        scale_guess->Update_guess(frame_guess.ratio_78_guess * 1.5f);
    } else if (second_guess < 0) {
        scale_guess->Update_guess(frame_guess.ratio_78_guess * 0.6666667f);
        if (!(frame_guess.ratio_78_guess < 1.0f)) {
            return 0;
        }
        scale_guess->Update_guess(1.0f);
    }
    return 0;
}

// Ends the recorded line at the given point if it moved more than 0.9 units, on the active layer and in the
// drawing colour, and makes that the next start.
// FUNCTION: TITANIUM 0x00533455
// @early-stop: budget, structural ndiff=28
void Event_guess::Place_guess(float x_guess, float y_guess, float z_guess) {
    if (ready_guess != 0 && enabled_guess != 0) {
        if (_fabs((double)(first_guess - (x_guess + offset_x_guess))) <= 0.9f &&
            _fabs((double)(second_guess - (y_guess + offset_y_guess))) <= 0.9f) {
        } else {
            ElementList_guess* node_guess = new ElementList_guess;
            node_guess->links_guess.previous_guess = 0;
            node_guess->links_guess.next_guess = list_guess;
            if (list_guess != 0) {
                list_guess->links_guess.previous_guess = node_guess;
            }
            list_guess = node_guess;
            node_guess->position_guess.old_x_guess = first_guess;
            node_guess->position_guess.old_y_guess = second_guess;
            node_guess->position_guess.old_z_guess = third_guess;
            node_guess->position_guess.new_x_guess = x_guess;
            node_guess->position_guess.new_y_guess = y_guess;
            node_guess->position_guess.new_z_guess = z_guess;
            node_guess->field_20_guess = field_58_guess;
            node_guess->field_24_guess = field_68_guess;
            first_guess = node_guess->position_guess.new_x_guess;
            second_guess = node_guess->position_guess.new_y_guess;
            third_guess = node_guess->position_guess.new_z_guess;
        }
    }
    ready_guess = 0;
}

// Same as Place_guess but keeps recording on.
// FUNCTION: TITANIUM 0x0053354E
// @early-stop: budget, structural ndiff=28
void Event_guess::AddPoint_guess(float x_guess, float y_guess, float z_guess) {
    if (ready_guess != 0 && enabled_guess != 0) {
        float dx_guess = (float)_fabs((double)(first_guess - (x_guess + offset_x_guess)));
        if (dx_guess <= 0.9f) {
            float dy_guess = (float)_fabs((double)(second_guess - (y_guess + offset_y_guess)));
            if (dy_guess <= 0.9f) {
                return;
            }
        }
        ElementList_guess* node_guess = new ElementList_guess;
        node_guess->links_guess.previous_guess = 0;
        node_guess->links_guess.next_guess = list_guess;
        if (list_guess != 0) {
            list_guess->links_guess.previous_guess = node_guess;
        }
        list_guess = node_guess;
        node_guess->position_guess.old_x_guess = first_guess;
        node_guess->position_guess.old_y_guess = second_guess;
        node_guess->position_guess.old_z_guess = third_guess;
        node_guess->position_guess.new_x_guess = x_guess;
        node_guess->position_guess.new_y_guess = y_guess;
        node_guess->position_guess.new_z_guess = z_guess;
        node_guess->field_20_guess = field_58_guess;
        node_guess->field_24_guess = field_68_guess;
        first_guess = node_guess->position_guess.new_x_guess;
        second_guess = node_guess->position_guess.new_y_guess;
        third_guess = node_guess->position_guess.new_z_guess;
    }
}

// Measures a label with font size 1-3: width and height.
// FUNCTION: TITANIUM 0x00533644
void ResourceLoader_guess::Load_guess(ResourceEntry_guess* entry_guess) {
    ResourceItem_guess* item_guess = *g_resourceCatalog_guess->section_guess.Get_guess(entry_guess->index_guess - 1);
    {
        ResourceText_guess text_guess(entry_guess->text_guess);
        entry_guess->first_guess = item_guess->Read_guess(&text_guess);
    }
    entry_guess->second_guess = item_guess->Finish_guess();
}

// Clips a segment to the render area and draws it; false when nothing is left.
// FUNCTION: TITANIUM 0x00533B57
// @early-stop: budget, structural ndiff=55
char SegmentOwner_guess::Clip_guess(Rect6_guess* rect_guess, unsigned int value_guess, DrawRect_guess clip_guess) {
    ClipScratch_guess scratch_guess;
    double ratio_guess;
    float max_y_guess;
    float min_y_guess;

    scratch_guess.min_x_guess = (float)clip_guess.left_guess;
    if (rect_guess->left_guess < scratch_guess.min_x_guess &&
        rect_guess->right_guess < scratch_guess.min_x_guess) {
        return 0;
    }
    scratch_guess.max_x_guess = (float)clip_guess.right_guess;
    if (rect_guess->left_guess > scratch_guess.max_x_guess &&
        rect_guess->right_guess > scratch_guess.max_x_guess) {
        return 0;
    }
    min_y_guess = (float)clip_guess.top_guess;
    if (rect_guess->top_guess < min_y_guess && rect_guess->bottom_guess < min_y_guess) {
        return 0;
    }
    max_y_guess = (float)clip_guess.bottom_guess;
    if (rect_guess->top_guess > max_y_guess && rect_guess->bottom_guess > max_y_guess) {
        return 0;
    }
    scratch_guess.endpoints_guess[0] = rect_guess->left_guess;
    scratch_guess.endpoints_guess[1] = rect_guess->top_guess;
    scratch_guess.endpoints_guess[2] = rect_guess->unused_guess;
    scratch_guess.endpoints_guess[3] = rect_guess->right_guess;
    scratch_guess.endpoints_guess[4] = rect_guess->bottom_guess;
    scratch_guess.endpoints_guess[5] = rect_guess->unused2_guess;
    scratch_guess.delta_x_guess = scratch_guess.endpoints_guess[0] - scratch_guess.endpoints_guess[3];
    scratch_guess.delta_y_guess = scratch_guess.endpoints_guess[1] - scratch_guess.endpoints_guess[4];

    do {
        if (scratch_guess.endpoints_guess[0] < scratch_guess.min_x_guess) {
            ratio_guess = _fabs((double)((scratch_guess.min_x_guess - scratch_guess.endpoints_guess[0]) /
                scratch_guess.delta_x_guess));
            scratch_guess.endpoints_guess[0] = scratch_guess.min_x_guess;
        } else if (!(scratch_guess.endpoints_guess[0] > scratch_guess.max_x_guess)) {
            break;
        } else {
            ratio_guess = _fabs((double)((scratch_guess.endpoints_guess[0] - scratch_guess.max_x_guess) /
                scratch_guess.delta_x_guess));
            scratch_guess.endpoints_guess[0] = scratch_guess.max_x_guess;
        }
        scratch_guess.endpoints_guess[1] = scratch_guess.endpoints_guess[1] -
            ratio_guess * scratch_guess.delta_y_guess;
    } while (0);

    do {
        if (scratch_guess.endpoints_guess[3] < scratch_guess.min_x_guess) {
            ratio_guess = _fabs((double)((scratch_guess.min_x_guess - scratch_guess.endpoints_guess[3]) /
                scratch_guess.delta_x_guess));
            scratch_guess.endpoints_guess[3] = scratch_guess.min_x_guess;
        } else if (!(scratch_guess.endpoints_guess[3] > scratch_guess.max_x_guess)) {
            break;
        } else {
            ratio_guess = _fabs((double)((scratch_guess.endpoints_guess[3] - scratch_guess.max_x_guess) /
                scratch_guess.delta_x_guess));
            scratch_guess.endpoints_guess[3] = scratch_guess.max_x_guess;
        }
        scratch_guess.endpoints_guess[4] = ratio_guess * scratch_guess.delta_y_guess +
            scratch_guess.endpoints_guess[4];
    } while (0);

    if (scratch_guess.endpoints_guess[1] < min_y_guess &&
        scratch_guess.endpoints_guess[4] < min_y_guess) {
        return 0;
    }
    if (max_y_guess < scratch_guess.endpoints_guess[1] &&
        max_y_guess < scratch_guess.endpoints_guess[4]) {
        return 0;
    }

    do {
        if (scratch_guess.endpoints_guess[1] < min_y_guess) {
            ratio_guess = _fabs((double)((min_y_guess - scratch_guess.endpoints_guess[1]) /
                scratch_guess.delta_y_guess));
            scratch_guess.endpoints_guess[1] = min_y_guess;
        } else if (!(scratch_guess.endpoints_guess[1] > max_y_guess)) {
            break;
        } else {
            ratio_guess = _fabs((double)((scratch_guess.endpoints_guess[1] - max_y_guess) /
                scratch_guess.delta_y_guess));
            scratch_guess.endpoints_guess[1] = max_y_guess;
        }
        scratch_guess.endpoints_guess[0] = scratch_guess.endpoints_guess[0] -
            ratio_guess * scratch_guess.delta_x_guess;
    } while (0);

    do {
        if (scratch_guess.endpoints_guess[4] < min_y_guess) {
            ratio_guess = _fabs((double)((min_y_guess - scratch_guess.endpoints_guess[4]) /
                scratch_guess.delta_y_guess));
            scratch_guess.endpoints_guess[3] = ratio_guess * scratch_guess.delta_x_guess +
                scratch_guess.endpoints_guess[3];
            scratch_guess.endpoints_guess[4] = min_y_guess;
        } else if (!(scratch_guess.endpoints_guess[4] > max_y_guess)) {
            break;
        } else {
            ratio_guess = _fabs((double)((scratch_guess.endpoints_guess[4] - max_y_guess) /
                scratch_guess.delta_y_guess));
            scratch_guess.endpoints_guess[3] = ratio_guess * scratch_guess.delta_x_guess +
                scratch_guess.endpoints_guess[3];
            scratch_guess.endpoints_guess[4] = max_y_guess;
        }
    } while (0);

    if (scratch_guess.min_x_guess > scratch_guess.endpoints_guess[0] &&
        scratch_guess.min_x_guess > scratch_guess.endpoints_guess[3]) {
        return 0;
    }
    if (scratch_guess.endpoints_guess[0] > scratch_guess.max_x_guess &&
        scratch_guess.endpoints_guess[3] > scratch_guess.max_x_guess) {
        return 0;
    }
    g_drawTarget_guess->DrawSegment_guess(scratch_guess.endpoints_guess,
        &scratch_guess.endpoints_guess[3], value_guess);
    return 1;
}

// Saves the user layers 1-3; the base map (layer 0) is never written.
// FUNCTION: TITANIUM 0x00533E0B
void MapViewMap_guess::SaveAllEx_guess(const char* map_name_guess) {
    for (int map_index_guess = 1; map_index_guess <= 3; ++map_index_guess) {
        SaveEx(map_name_guess, map_index_guess);
    }
}

// Labels get '_' back to spaces and sizes
// clamped to 1-3; loading layer 0 also sets the map extents.
// FUNCTION: TITANIUM 0x00533E29
// @early-stop: budget, structural ndiff=86
bool MapViewMap_guess::LoadMapLayer_guess(const char* map_name_guess, int map_index_guess) {
    char file_name_guess[256];
    char point_name_guess[256];
    char line_buffer_guess[1024];
    FILE* file_guess;
    int first_color_guess;
    int second_color_guess;
    int third_color_guess;
    int min_first_guess;
    int max_first_guess;
    int min_second_guess;
    int max_second_guess;

    max_second_guess = 0;
    max_first_guess = 0;
    min_second_guess = 0;
    min_first_guess = 0;

    if (map_index_guess != 0) {
        sprintf(file_name_guess, "maps\\%s_%d.txt", map_name_guess, map_index_guess);
    } else {
        sprintf(file_name_guess, "maps\\%s.txt", map_name_guess);
    }
    file_guess = fopen(file_name_guess, "rt");
    if (file_guess == 0) {
        return false;
    }

    while ((file_guess->_flag & 0x10) == 0) {
        map_name_guess = 0;
        first_color_guess = 0;
        second_color_guess = 0;
        third_color_guess = 0;
        line_buffer_guess[1023] = 0;
        line_buffer_guess[0] = 0;
        fgets(line_buffer_guess, 0x3fe, file_guess);
        if (toupper(line_buffer_guess[0]) == 'L') {
            SaveLine_guess* line_guess = new SaveLine_guess;
            line_guess->prev_guess = 0;
            line_guess->next_guess = lines_guess;
            if (lines_guess != 0) {
                lines_guess->prev_guess = line_guess;
            }
            lines_guess = line_guess;
            sscanf(line_buffer_guess + 2, "%f, %f, %f,  %f, %f, %f,  %d, %d, %d",
                &line_guess->first_guess, &line_guess->second_guess, &line_guess->third_guess,
                &line_guess->fourth_guess, &line_guess->fifth_guess, &line_guess->sixth_guess,
                &first_color_guess, &second_color_guess, &third_color_guess);
            line_guess->third_color_guess = (unsigned char)first_color_guess;
            line_guess->second_color_guess = (unsigned char)second_color_guess;
            line_guess->first_color_guess = (unsigned char)third_color_guess;
            line_guess->map_index_guess = map_index_guess;
            line_guess->pad_23_guess = (char)0xff;

            if (line_guess->first_guess < min_first_guess) {
                min_first_guess = (int)line_guess->first_guess;
            }
            if (line_guess->second_guess < min_second_guess) {
                min_second_guess = (int)line_guess->second_guess;
            }
            if (max_first_guess < line_guess->first_guess) {
                max_first_guess = (int)line_guess->first_guess;
            }
            if (max_second_guess < line_guess->second_guess) {
                max_second_guess = (int)line_guess->second_guess;
            }
            if (line_guess->fourth_guess < min_first_guess) {
                min_first_guess = (int)line_guess->fourth_guess;
            }
            if (line_guess->fifth_guess < min_second_guess) {
                min_second_guess = (int)line_guess->fifth_guess;
            }
            if (max_first_guess < line_guess->fourth_guess) {
                max_first_guess = (int)line_guess->fourth_guess;
            }
            if (max_second_guess < line_guess->fifth_guess) {
                max_second_guess = (int)line_guess->fifth_guess;
            }
        } else if (toupper(line_buffer_guess[0]) == 'P') {
            SavePoint_guess* point_guess = new SavePoint_guess;
            point_guess->prev_guess = 0;
            point_guess->next_guess = points_guess;
            if (points_guess != 0) {
                points_guess->prev_guess = point_guess;
            }
            points_guess = point_guess;
            sscanf(line_buffer_guess + 2, "%f, %f, %f,  %d, %d, %d,  %d,  %256s",
                &point_guess->x_guess, &point_guess->y_guess, &point_guess->z_guess,
                &first_color_guess, &second_color_guess, &third_color_guess,
                &point_guess->value_18_guess, point_name_guess);
            point_guess->third_color_guess = (unsigned char)first_color_guess;
            point_guess->second_color_guess = (unsigned char)second_color_guess;
            point_guess->first_color_guess = (unsigned char)third_color_guess;
            point_guess->pad_17_guess = (char)0xff;
            unsigned int index_guess = 0;
            if (strlen(point_name_guess) > 0) {
                do {
                    if (point_name_guess[index_guess] == '_') {
                        point_name_guess[index_guess] = ' ';
                    }
                    ++index_guess;
                } while (index_guess < strlen(point_name_guess));
            }
            point_guess->text_guess = (char*)operator_new_text_guess(strlen(point_name_guess) + 1);
            CopyEntryText_guess(point_guess->text_guess, point_name_guess);
            point_guess->map_index_guess = map_index_guess;
            if (point_guess->value_18_guess < 1) {
                point_guess->value_18_guess = 1;
            } else if (point_guess->value_18_guess > 3) {
                point_guess->value_18_guess = 3;
            }
            ((ResourceLoader_guess*)this)->Load_guess((ResourceEntry_guess*)point_guess);
        }
    }

    fclose(file_guess);
    if (map_index_guess == 0) {
        ((DestroyObject_guess*)this)->Apply_guess(min_first_guess, max_first_guess,
            min_second_guess, max_second_guess);
    }
    return true;
}

// FUNCTION: TITANIUM 0x0053572D
void MapViewMap_guess::LoadAllLayers_guess(const char* map_name_guess) {
    for (int map_index_guess = 0; map_index_guess <= 3; ++map_index_guess) {
        LoadMapLayer_guess(map_name_guess, map_index_guess);
    }
    saved_81_guess = 1;
}

// Stops recording and adds the last segment up to the player.
// FUNCTION: TITANIUM 0x00534497
void OffsetOwner_guess::StopAutoMap_guess() {
    if (flag_15c_guess == 1) {
        flag_15c_guess = 0;
        event_guess.Place_guess(-g_displayOffset_guess->field_34_guess, -g_displayOffset_guess->field_30_guess,
            g_displayOffset_guess->field_38_guess - g_displayOffset_guess->field_23c_guess * 0.625f);
    }
    if (pinstCMapToolbarWnd_guess != 0) {
        pinstCMapToolbarWnd_guess->SetAutoMapCheck_guess(flag_15c_guess);
    }
}

// Deletes every line and point of one layer (+key).
// FUNCTION: TITANIUM 0x00534224
void MatchOwner_guess::ClearActiveLayer_guess() {
    MatchNode24_guess* node_guess = first_guess;
    while (node_guess != 0) {
        MatchNode24_guess* next_guess = node_guess->next_guess;
        if (node_guess->key_guess == key_guess) {
            ((List_guess*)this)->Remove_guess((Node_guess*)node_guess);
        }
        node_guess = next_guess;
    }
    MatchNode20_guess* node2_guess = second_guess;
    while (node2_guess != 0) {
        MatchNode20_guess* next2_guess = node2_guess->next_guess;
        if (node2_guess->key_guess == key_guess) {
            ((RecyclableList_guess*)this)->RemoveAndFree_guess((RecyclableNode_guess*)node2_guess);
        }
        node2_guess = next2_guess;
    }
}

// Auto-mapping while recording: a new segment starts when the direction of travel (dy/dx) drifts more than a
// tolerance, 5% for short segments down to 0.1% for long ones. Also applies a drag pan.
// FUNCTION: TITANIUM 0x00534269
// @early-stop: budget, diff ndiff=128
void OffsetOwner_guess::OnProcessFrame_guess() {
    if (enabled_5c_guess != 0) {
        if (flag_15c_guess == 1 && g_displayOffset_guess != 0) {
            float offset_values_guess[3];
            offset_values_guess[0] = -g_displayOffset_guess->field_34_guess;
            offset_values_guess[1] = -g_displayOffset_guess->field_30_guess;
            offset_values_guess[2] = g_displayOffset_guess->field_38_guess -
                g_displayOffset_guess->field_23c_guess * 0.625f;
            if (g_savedOffsetZ_guess == g_offsetSentinel_guess) {
                g_savedOffsetZ_guess = offset_values_guess[0];
                g_savedOffsetY_guess = offset_values_guess[2];
                g_savedOffsetX_guess = offset_values_guess[1];
            }
            double delta_x_guess = _fabs((double)(event_guess.first_guess - offset_values_guess[0]));
            double delta_y_guess = _fabs((double)(event_guess.second_guess - offset_values_guess[1]));
            double distance_guess = delta_x_guess * delta_x_guess + delta_y_guess * delta_y_guess;
            if (distance_guess > g_distanceFour_guess) {
                double change_guess;
                if (distance_guess >= g_distanceHundred_guess) {
                    if (distance_guess >= g_distanceFourHundred_guess) {
                        if (distance_guess >= g_distanceNineHundred_guess) {
                            change_guess = g_changeTenthPercent_guess;
                        } else {
                            change_guess = g_changeHalfPercent_guess;
                        }
                    } else {
                        change_guess = g_changeOnePercent_guess;
                    }
                } else {
                    change_guess = g_changeFivePercent_guess;
                }
                double ratio_guess = g_initialRatio_guess;
                if (delta_x_guess > g_halfDistance_guess) {
                    ratio_guess = delta_y_guess / delta_x_guess;
                }
                if (g_offsetClamp_guess == g_clampSentinel_guess) {
                    g_offsetClamp_guess = ratio_guess;
                } else {
                    double difference_guess = _fabs(g_offsetClamp_guess - ratio_guess);
                    if (difference_guess <= change_guess) {
                        if (g_offsetClamp_guess == g_clampSentinel_guess) {
                            g_offsetClamp_guess = ratio_guess;
                        }
                    } else {
                        g_offsetClamp_guess = ratio_guess;
                        event_guess.AddPoint_guess(g_savedOffsetZ_guess,
                            g_savedOffsetX_guess, g_savedOffsetY_guess);
                    }
                }
            }
            g_savedOffsetZ_guess = offset_values_guess[0];
            g_savedOffsetX_guess = offset_values_guess[1];
            g_savedOffsetY_guess = offset_values_guess[2];
        } else {
            g_savedOffsetZ_guess = g_offsetSentinel_guess;
            g_savedOffsetX_guess = g_offsetSentinel_guess;
            g_savedOffsetY_guess = g_offsetSentinel_guess;
            float value_x_guess = g_savedOffsetX_guess;
            float value_y_guess = g_savedOffsetY_guess;
            float value_z_guess = g_savedOffsetZ_guess;
            g_savedOffsetZ_guess = value_z_guess;
            g_savedOffsetY_guess = value_y_guess;
            g_savedOffsetX_guess = value_x_guess;
        }
        if (g_flag_991d02_guess == 1) {
            event_guess.field_20_guess = g_deltaX_guess + g_positionSource_guess->field_74_guess;
            event_guess.field_24_guess = g_deltaY_guess + g_positionSource_guess->field_78_guess;
        }
    }
    OnProcessFrame();
}

// Adds a label point on the active layer: position, colour, size and text.
// FUNCTION: TITANIUM 0x005344FB
void EntryOwner_guess::AddLabel_guess(unsigned int first_value_guess, unsigned int second_value_guess,
    unsigned int third_value_guess, unsigned int color_guess,
    unsigned int value_guess, const char* text_guess) {
    if (enabled_guess != 0) {
        AddedEntry_guess* entry_guess = (AddedEntry_guess*)operator new(0x34);
        entry_guess->previous_guess = 0;
        entry_guess->next_guess = first_guess;
        if (first_guess != 0) {
            first_guess->previous_guess = entry_guess;
        }
        first_guess = entry_guess;
        entry_guess->first_guess = first_value_guess;
        entry_guess->second_guess = second_value_guess;
        entry_guess->third_guess = third_value_guess;
        entry_guess->color_17_guess = (unsigned char)(color_guess >> 24);
        entry_guess->color_16_guess = (unsigned char)(color_guess >> 16);
        entry_guess->color_15_guess = (unsigned char)(color_guess >> 8);
        entry_guess->color_14_guess = (unsigned char)color_guess;
        char* copy_guess = (char*)AllocateText_guess((unsigned int)strlen(text_guess) + 1);
        entry_guess->text_guess = copy_guess;
        entry_guess->value_18_guess = value_guess;
        entry_guess->value_20_guess = value_68_guess;
        CopyEntryText_guess(copy_guess, text_guess);
        ((ResourceLoader_guess*)this)->Load_guess((ResourceEntry_guess*)entry_guess);
        entry_guess->value_2c_guess = 0;
        entry_guess->value_30_guess = 0;
    }
}

union MapColor_guess {
    struct {
        unsigned char blue_guess;
        unsigned char green_guess;
        unsigned char red_guess;
        unsigned char alpha_guess;
    };
    unsigned long argb_guess;
};

struct MapFont_guess {
    // EXTERNAL: TITANIUM 0x005A3C80 MapFont_guess::DrawText_guess
    void DrawText_guess(const CXStr& text_guess, int x_guess, int y_guess, int width_guess,
        const DrawRect_guess& clip_guess, unsigned long color_guess, int first_guess, int second_guess);
    // EXTERNAL: TITANIUM 0x005A3A00 MapFont_guess::GetTextWidth_guess
    int GetTextWidth_guess(const CXStr& text_guess);
    // EXTERNAL: TITANIUM 0x005A3A20 MapFont_guess::GetHeight_guess
    int GetHeight_guess();
};

struct MapFontArray_guess {
    int count_guess;
    MapFont_guess** data_guess;
    // EXTERNAL: TITANIUM 0x00405492 MapFontArray_guess::Fail_guess
    __declspec(noreturn) void Fail_guess();
    MapFont_guess* Get_guess(int index_guess) {
        if (index_guess < count_guess && index_guess >= 0 && data_guess != 0)
            return data_guess[index_guess];
        Fail_guess();
    }
};

struct MapGlobals_guess {
    char pad_00_guess[0x74];
    DrawPoint_guess cursor_guess;       // 0x74
    char pad_7c_guess[0xf4 - 0x7c];
    MapFontArray_guess fonts_guess;     // 0xf4
};

struct MapDrawLine_guess {
    MapDrawLine_guess* next_guess;
    char pad_04_guess[4];
    float x1_guess;                     // 0x08
    float y1_guess;
    float z1_guess;
    float x2_guess;
    float y2_guess;
    float z2_guess;
    unsigned long color_guess;          // 0x20
    int layer_guess;                    // 0x24
};

struct MapDrawPoint_guess {
    MapDrawPoint_guess* next_guess;
    char pad_04_guess[4];
    float x_guess;                      // 0x08
    float y_guess;                      // 0x0c
    float z_guess;                      // 0x10
    unsigned long color_guess;          // 0x14
    int size_guess;                     // 0x18
    const char* text_guess;             // 0x1c
    int layer_guess;                    // 0x20
    int width_guess;                    // 0x24
    int height_guess;                   // 0x28
    int offset_x_guess;                 // 0x2c
    int offset_y_guess;                 // 0x30
};

struct MapMarked_guess {
    MapMarked_guess* next_guess;
    MapDrawLine_guess* line_guess;
};

struct MapMath_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Cos_guess(float angle_guess);
    virtual float Sin_guess(float angle_guess);
};

struct CharInfoView_guess {
    char pad_00_guess[0x1010];
    int field_1010_guess;
};

struct PcHead_guess {
    virtual void Slot00_guess();
    int field_04_guess;
};

// vbptr at +8, EQ_Character is the virtual base.
struct PcCharacter_guess : PcHead_guess, virtual EQ_Character {
};

struct MapLayer_guess {
    char pad_00_guess[0x10];
    float width_guess;                  // 0x10
    float height_guess;                 // 0x14
    float top_guess;                    // 0x18
    float left_guess;                   // 0x1c
    char pad_20_guess[0x20];
    MapDrawLine_guess* lines_guess;     // 0x40
    MapDrawPoint_guess* points_guess;   // 0x44
    unsigned char has_player_guess;     // 0x48
    char pad_49_guess[3];
    float player_x_guess;               // 0x4c
    float player_y_guess;               // 0x50
    char pad_54_guess[4];
    unsigned long player_color_guess;   // 0x58
    MapMarked_guess* marked_guess;      // 0x5c
    MapDrawPoint_guess* selected_guess; // 0x60
    char pad_64_guess[8];
    int min_z_guess;                    // 0x6c
    int max_z_guess;                    // 0x70
    unsigned char z_filter_guess;       // 0x74
    char pad_75_guess[7];
    int label_value_guess;              // 0x7c
    unsigned char labels_guess;         // 0x80
    unsigned char labels_dirty_guess;   // 0x81
    unsigned char show_arrow_guess;     // 0x82
    void Draw_guess(DrawRect_guess clip_guess);
    void LayoutLabels_guess(DrawRect_guess rect_guess);
};

#define g_mapGlobals_guess EQ_GLOBAL(MapGlobals_guess*, 0x0099D3EC)
#define g_selectStartX_guess EQ_GLOBAL(int, 0x00991D38)
#define g_selectStartY_guess EQ_GLOBAL(int, 0x00991D3C)
#define g_selectAdd_guess EQ_GLOBAL(unsigned char, 0x00991D01)
#define g_hoverLine_guess EQ_GLOBAL(MapDrawLine_guess*, 0x00991CF8)
#define g_hoverPoint_guess EQ_GLOBAL(MapDrawPoint_guess*, 0x00991CFC)
#define g_mapMath_guess EQ_GLOBAL(MapMath_guess*, 0x0099E374)
#define g_pcCharacter_guess EQ_GLOBAL(PcCharacter_guess*, 0x00905D00)
#define g_itoaBuffer_guess EQ_ARRAY(char, 0x0099DB00)

// EXTERNAL: TITANIUM 0x00610884 sqrt
extern "C" double __cdecl sqrt(double value_guess);
// EXTERNAL: TITANIUM 0x0060F81E abs
extern "C" int __cdecl abs(int value_guess);
// EXTERNAL: TITANIUM 0x0046DA4A FormatString_guess
char* __cdecl FormatString_guess(char* out_guess, int id_guess, const char* a1_guess, const char* a2_guess,
    const char* a3_guess, const char* a4_guess, const char* a5_guess, const char* a6_guess,
    const char* a7_guess, const char* a8_guess, const char* a9_guess);
// EXTERNAL: TITANIUM 0x005A00E0 DrawFrame_guess
void __cdecl DrawFrame_guess(const DrawRect_guess& rect_guess, unsigned long color_guess, const DrawRect_guess& clip_guess);

#define g_overlayInflation_guess EQ_GLOBAL(float, 0x0063F4D0)
struct OverlayNode_guess {
    OverlayNode_guess* next_guess;
    Rect_guess rect_guess;
    MapDrawPoint_guess* entry_guess;
    bool placed_guess;
    OverlayNode_guess() {
        rect_guess.left_guess = rect_guess.top_guess = rect_guess.right_guess = rect_guess.bottom_guess = 0;
    }
};

#define g_overlayHead_guess EQ_GLOBAL(OverlayNode_guess*, 0x00991D10)

// Marks a box as taken by a label. placed_guess is stored without being set (as decompiled).
// FUNCTION: TITANIUM 0x005336BB
// @early-stop: tiebreak, diff ndiff=44
void __cdecl AddOverlay_guess(Rect_guess bounds_guess, MapDrawPoint_guess* entry_guess) {
    OverlayNode_guess* node_guess;
    bool placed_guess;
    Rect_guess result_guess;
    if (g_overlayHead_guess != 0) {
        node_guess = new OverlayNode_guess;
        node_guess->next_guess = g_overlayHead_guess;
        node_guess->rect_guess.Copy_guess(&result_guess, &bounds_guess);
        g_overlayHead_guess = node_guess;
    } else {
        node_guess = new OverlayNode_guess;
        g_overlayHead_guess = node_guess;
        node_guess->next_guess = 0;
        node_guess->rect_guess.Copy_guess(&result_guess, &bounds_guess);
    }
    node_guess->entry_guess = entry_guess;
    node_guess->placed_guess = placed_guess;
}
// Tries candidate boxes from `mode_guess` on; returns 0 once one fits with no overlap, else -(best + 1).
// FUNCTION: TITANIUM 0x0053374B
// @early-stop: budget, structural ndiff=67
int __cdecl TestOverlay_guess(int mode_guess, int first_guess, int second_guess,
    int width_guess, int height_guess, Rect_guess bounds_guess,
    MapDrawPoint_guess* entry_guess, int flag_guess) {
    Block16_guess built_guess;
    Rect_guess converted_guess;
    Rect_guess invalid_guess;
    BuildBlock_guess(&built_guess, mode_guess, first_guess, second_guess, width_guess, height_guess);
    ((ArgumentContext_guess*)&built_guess)->Convert_guess(&converted_guess, (int*)&bounds_guess);
    int top_guess = built_guess.second_guess;
    int left_guess = built_guess.first_guess;
    if ((char)flag_guess != 0 ||
        ((invalid_guess.left_guess = -1, invalid_guess.top_guess = -1,
          invalid_guess.right_guess = -1, invalid_guess.bottom_guess = -1,
          !converted_guess.Equal_guess(&invalid_guess)) &&
         converted_guess.right_guess - converted_guess.left_guess == built_guess.third_guess - left_guess &&
         converted_guess.bottom_guess - converted_guess.top_guess == built_guess.fourth_guess - top_guess)) {
        if (CountMatchingEntries_guess(built_guess.first_guess, built_guess.second_guess,
                built_guess.third_guess, built_guess.fourth_guess) == 0) {
            AddOverlay_guess(*(Rect_guess*)&built_guess, entry_guess);
            entry_guess->offset_x_guess = left_guess - first_guess;
            entry_guess->offset_y_guess = top_guess - second_guess;
            return 0;
        }
    }
    if (mode_guess < 0x17) {
        return TestOverlay_guess(mode_guess + 1, first_guess, second_guess, width_guess, height_guess,
            bounds_guess, entry_guess, flag_guess);
    }
    int best_index_guess = -1;
    int best_count_guess = 0x32;
    for (int i_guess = 0; i_guess < 0x18; ++i_guess) {
        built_guess.CopyTo_guess((Block16_guess*)&converted_guess,
            BuildBlock_guess((Block16_guess*)&invalid_guess, i_guess, first_guess, second_guess,
                width_guess, height_guess));
        int count_guess = CountMatchingEntries_guess(built_guess.first_guess, built_guess.second_guess,
            built_guess.third_guess, built_guess.fourth_guess);
        if (count_guess < best_count_guess) {
            best_count_guess = count_guess;
            best_index_guess = i_guess + 1;
            if (count_guess == 0) {
                break;
            }
        }
    }
    return -best_index_guess;
}

// Lays out the labels: reserves every shown point, places each label in a free candidate box, then makes
// three improvement passes.
// FUNCTION: TITANIUM 0x005338D1
// @early-stop: budget, structural ndiff=129
void MapLayer_guess::LayoutLabels_guess(DrawRect_guess rect_guess) {
    MapDrawPoint_guess* current_guess;
    if (points_guess != 0) {
        while (g_queueHead_guess != 0) {
            QueueEntry_guess* next_guess = g_queueHead_guess->next_guess;
            free(g_queueHead_guess);
            g_queueHead_guess = next_guess;
        }
        current_guess = points_guess;
        g_queueHead_guess = 0;
        while (current_guess != 0) {
            MapDrawPoint_guess* entry_guess = current_guess;
            if (((FlagSet_guess*)this)->Test_guess(entry_guess->layer_guess)) {
                float point_guess[3];
                point_guess[0] = entry_guess->x_guess;
                point_guess[1] = entry_guess->y_guess;
                point_guess[2] = entry_guess->z_guess;
                ((Viewport_guess*)this)->TransformPoint_guess(point_guess);
                point_guess[0] = (float)rect_guess.left_guess + point_guess[0];
                point_guess[1] = (float)rect_guess.top_guess + point_guess[1];
                Rect_guess bounds_guess;
                bounds_guess.left_guess = (int)(point_guess[0] - g_overlayInflation_guess);
                bounds_guess.top_guess = (int)(point_guess[1] - g_overlayInflation_guess);
                bounds_guess.right_guess = (int)(point_guess[0] + g_overlayInflation_guess);
                bounds_guess.bottom_guess = (int)(point_guess[1] + g_overlayInflation_guess);
                bounds_guess.NormalizeRect_guess();
                AddOverlay_guess(bounds_guess, entry_guess);
            }
            current_guess = current_guess->next_guess;
        }
        current_guess = points_guess;
        while (current_guess != 0) {
            MapDrawPoint_guess* entry_guess = current_guess;
            entry_guess->offset_x_guess = 0;
            entry_guess->offset_y_guess = 0;
            if (((FlagSet_guess*)this)->Test_guess(entry_guess->layer_guess) && labels_guess != 0) {
                float point_guess[3];
                point_guess[0] = entry_guess->x_guess;
                point_guess[1] = entry_guess->y_guess;
                point_guess[2] = entry_guess->z_guess;
                ((Viewport_guess*)this)->TransformPoint_guess(point_guess);
                point_guess[0] = (float)rect_guess.left_guess + point_guess[0];
                point_guess[1] = (float)rect_guess.top_guess + point_guess[1];
                int pixel_y_guess = (int)point_guess[1];
                int pixel_x_guess = (int)point_guess[0];
                Rect_guess bounds_guess;
                int hit_guess = TestOverlay_guess(0, pixel_x_guess, pixel_y_guess,
                    entry_guess->width_guess, entry_guess->height_guess,
                    rect_guess, entry_guess, 1);
                if (hit_guess < 0) {
                    hit_guess = TestOverlay_guess(0, pixel_x_guess, pixel_y_guess,
                        entry_guess->width_guess, entry_guess->height_guess,
                        rect_guess, entry_guess, 1);
                    if (hit_guess < 0) {
                        Block16_guess result_guess;
                        CXPoint copy_guess;
                        BuildBlock_guess(&result_guess, -1 - hit_guess, pixel_x_guess,
                            pixel_y_guess, entry_guess->width_guess, entry_guess->height_guess);
                        bounds_guess.Copy_guess(&copy_guess, (Rect_guess*)&result_guess);
                        AddOverlay_guess(bounds_guess, entry_guess);
                        entry_guess->offset_x_guess =
                            (int)((float)bounds_guess.left_guess - point_guess[0]);
                        entry_guess->offset_y_guess =
                            (int)((float)bounds_guess.top_guess - point_guess[1]);
                    }
                }
            }
            current_guess = current_guess->next_guess;
        }
        ProcessQueue_guess();
        ProcessQueue_guess();
        ProcessQueue_guess();
    }
}

// Draws the map: lines and points of the shown layers (inside the height filter when it is on), the recorded
// segment, labels with leader lines, the player and the box selection. Lines and points within 3 pixels of
// the cursor, selected or in the box are drawn yellow.
// FUNCTION: TITANIUM 0x0053459F
// @early-stop: budget, structural ndiff=740
void MapLayer_guess::Draw_guess(DrawRect_guess clip_guess) {
    MapColor_guess highlight_guess;
    highlight_guess.blue_guess = 0;
    highlight_guess.green_guess = 0xff;
    highlight_guess.red_guess = 0xff;
    highlight_guess.alpha_guess = 0xff;
    MapGlobals_guess* globals_guess = g_mapGlobals_guess;
    MapFont_guess* fonts_guess[3];
    fonts_guess[0] = globals_guess->fonts_guess.Get_guess(0);
    fonts_guess[1] = globals_guess->fonts_guess.Get_guess(1);
    fonts_guess[2] = globals_guess->fonts_guess.Get_guess(2);
    bool highlighted_guess;
    char buffer_guess[512];

    DrawRect_guess rect_guess;
    rect_guess.top_guess = (int)((float)clip_guess.top_guess + top_guess);
    rect_guess.left_guess = (int)((float)clip_guess.left_guess + left_guess);
    rect_guess.bottom_guess = (int)((float)rect_guess.top_guess + height_guess);
    rect_guess.right_guess = (int)((float)rect_guess.left_guess + width_guess);
    rect_guess = clip_guess.Intersect_guess(rect_guess);

    DrawPoint_guess cursor_guess = globals_guess->cursor_guess;
    DrawRect_guess selection_guess;
    selection_guess.left_guess = 0;
    selection_guess.top_guess = 0;
    selection_guess.right_guess = 0;
    selection_guess.bottom_guess = 0;
    if (g_flag_991d00_guess) {
        // While box-selecting (map editing, 0x00991D00) the rectangle runs from the drag start to the cursor.
        selection_guess.left_guess = g_selectStartX_guess;
        selection_guess.top_guess = g_selectStartY_guess;
        selection_guess.right_guess = cursor_guess.x_guess;
        selection_guess.bottom_guess = cursor_guess.y_guess;
        selection_guess.NormalizeRect_guess();
    }

    ((Viewport_guess*)this)->UpdateLayout_guess();
    g_hoverLine_guess = 0;
    g_hoverPoint_guess = 0;

    Rect6_guess line_guess;
    // Map lines on visible layers. The height filter drops lines wholly outside the band around the player's
    // eye level. A line within 3 pixels of the cursor, a marked line or one inside the selection box is drawn
    // in the highlight colour (selected lines are added to the selection).
    for (MapDrawLine_guess* node_guess = lines_guess; node_guess != 0; node_guess = node_guess->next_guess) {
        if (!((FlagSet_guess*)this)->Test_guess(node_guess->layer_guess)) {
            continue;
        }
        highlighted_guess = false;
        if (z_filter_guess == 1) {
            float z_guess = g_displayOffset_guess->field_38_guess - g_displayOffset_guess->field_23c_guess * 0.625f;
            float low_guess = z_guess - (float)min_z_guess;
            if (low_guess > node_guess->z1_guess && low_guess > node_guess->z2_guess) {
                continue;
            }
            float high_guess = z_guess + max_z_guess;
            if (high_guess < node_guess->z1_guess && high_guess < node_guess->z2_guess) {
                continue;
            }
        }
        line_guess.left_guess = node_guess->x1_guess;
        line_guess.top_guess = node_guess->y1_guess;
        line_guess.unused_guess = node_guess->z1_guess;
        line_guess.right_guess = node_guess->x2_guess;
        line_guess.bottom_guess = node_guess->y2_guess;
        line_guess.unused2_guess = node_guess->z2_guess;
        ((Viewport_guess*)this)->TransformPoint_guess(&line_guess.left_guess);
        ((Viewport_guess*)this)->TransformPoint_guess(&line_guess.right_guess);
        line_guess.left_guess += rect_guess.left_guess;
        line_guess.top_guess += rect_guess.top_guess;
        line_guess.right_guess += rect_guess.left_guess;
        line_guess.bottom_guess += rect_guess.top_guess;
        line_guess.unused_guess = 1.0f;
        line_guess.unused2_guess = 1.0f;
        if (rect_guess.Contains_guess(cursor_guess) && pinstCMapToolbarWnd_guess->Check_guess()) {
            float dx_guess = line_guess.right_guess - line_guess.left_guess;
            float dy_guess = line_guess.bottom_guess - line_guess.top_guess;
            float cursor_x_guess = (float)cursor_guess.x_guess;
            float px_guess = cursor_x_guess - line_guess.left_guess;
            float cursor_y_guess = (float)cursor_guess.y_guess;
            float py_guess = cursor_y_guess - line_guess.top_guess;
            float t_guess = px_guess * dx_guess + py_guess * dy_guess;
            if (t_guess > 0.0f) {
                float length_guess = dy_guess * dy_guess + dx_guess * dx_guess;
                if (length_guess <= t_guess) {
                    px_guess = cursor_x_guess - line_guess.right_guess;
                    py_guess = cursor_y_guess - line_guess.bottom_guess;
                } else {
                    t_guess = t_guess / length_guess;
                    px_guess = cursor_x_guess - (t_guess * dx_guess + line_guess.left_guess);
                    py_guess = cursor_y_guess - (t_guess * dy_guess + line_guess.top_guess);
                }
            }
            if (sqrt(px_guess * px_guess + py_guess * py_guess) < 3.0f) {
                highlighted_guess = true;
                g_hoverLine_guess = node_guess;
            }
        }
        if (marked_guess != 0 && pinstCMapToolbarWnd_guess->Check_guess()) {
            for (MapMarked_guess* marked_node_guess = marked_guess; marked_node_guess != 0;
                 marked_node_guess = marked_node_guess->next_guess) {
                if (marked_node_guess->line_guess == node_guess) {
                    highlighted_guess = true;
                    break;
                }
            }
        }
        if (g_flag_991d00_guess && pinstCMapToolbarWnd_guess->Check_guess()) {
            DrawPoint_guess start_guess((int)line_guess.left_guess, (int)line_guess.top_guess);
            DrawPoint_guess end_guess((int)line_guess.right_guess, (int)line_guess.bottom_guess);
            if (selection_guess.Contains_guess(start_guess) && selection_guess.Contains_guess(end_guess)) {
                highlighted_guess = true;
                if (g_selectAdd_guess) {
                    ((ColorOwner_guess*)this)->AddLineToSelection_guess((PackedColor_guess*)node_guess);
                }
            }
        }
        if (highlighted_guess) {
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, highlight_guess.argb_guess, rect_guess);
        } else {
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, node_guess->color_guess, rect_guess);
        }
    }

    if (has_player_guess) {
        line_guess.left_guess = player_x_guess;
        line_guess.top_guess = player_y_guess;
        line_guess.right_guess = -g_displayOffset_guess->field_34_guess;
        line_guess.bottom_guess = -g_displayOffset_guess->field_30_guess;
        ((Viewport_guess*)this)->TransformPoint_guess(&line_guess.left_guess);
        ((Viewport_guess*)this)->TransformPoint_guess(&line_guess.right_guess);
        line_guess.left_guess += rect_guess.left_guess;
        line_guess.top_guess += rect_guess.top_guess;
        line_guess.right_guess += rect_guess.left_guess;
        line_guess.bottom_guess += rect_guess.top_guess;
        line_guess.unused_guess = 1.0f;
        line_guess.unused2_guess = 1.0f;
        ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, player_color_guess, rect_guess);
    }

    if (points_guess != 0) {
        if (labels_dirty_guess == 1) {
            LayoutLabels_guess(rect_guess);
            labels_dirty_guess = 0;
        }
        // Labels (map points) on visible layers, with the same height filter, hover and selection rules.
        for (MapDrawPoint_guess* point_guess = points_guess; point_guess != 0; point_guess = point_guess->next_guess) {
            if (!((FlagSet_guess*)this)->Test_guess(point_guess->layer_guess)) {
                continue;
            }
            highlighted_guess = false;
            if (z_filter_guess == 1) {
                float z_guess = g_displayOffset_guess->field_38_guess - g_displayOffset_guess->field_23c_guess * 0.625f;
                if (z_guess - (float)min_z_guess > point_guess->z_guess) {
                    continue;
                }
                if (point_guess->z_guess > (float)max_z_guess + z_guess) {
                    continue;
                }
            }
            float spot_guess[3];
            spot_guess[0] = point_guess->x_guess;
            spot_guess[1] = point_guess->y_guess;
            spot_guess[2] = point_guess->z_guess;
            ((Viewport_guess*)this)->TransformPoint_guess(spot_guess);
            spot_guess[0] += rect_guess.left_guess;
            spot_guess[1] += rect_guess.top_guess;
            spot_guess[2] = 1.0f;
            if (rect_guess.Contains_guess(cursor_guess)) {
                float px_guess = (float)cursor_guess.x_guess - spot_guess[0];
                float py_guess = (float)cursor_guess.y_guess - spot_guess[1];
                if (sqrt(px_guess * px_guess + py_guess * py_guess) < 3.0f) {
                    highlighted_guess = true;
                    g_hoverPoint_guess = point_guess;
                }
            }
            if (selected_guess == point_guess) {
                highlighted_guess = true;
            }
            line_guess.left_guess = spot_guess[0] - 1.0f;
            line_guess.top_guess = spot_guess[1];
            line_guess.unused_guess = 1.0f;
            line_guess.right_guess = spot_guess[0] + 2.0f;
            line_guess.bottom_guess = spot_guess[1];
            line_guess.unused2_guess = 1.0f;
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess,
                highlighted_guess ? highlight_guess.argb_guess : point_guess->color_guess, rect_guess);
            line_guess.left_guess = spot_guess[0];
            line_guess.top_guess = spot_guess[1] - 1.0f;
            line_guess.unused_guess = 1.0f;
            line_guess.right_guess = spot_guess[0];
            line_guess.bottom_guess = spot_guess[1] + 2.0f;
            line_guess.unused2_guess = 1.0f;
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess,
                highlighted_guess ? highlight_guess.argb_guess : point_guess->color_guess, rect_guess);
            if (labels_guess) {
                line_guess.unused_guess = 1.0f;
                line_guess.left_guess = spot_guess[0];
                line_guess.top_guess = spot_guess[1];
                if (abs(point_guess->offset_x_guess) > 4) {
                    if (abs(point_guess->offset_x_guess) > point_guess->width_guess) {
                        line_guess.right_guess = spot_guess[0] - 4.0f;
                        line_guess.bottom_guess = (float)(point_guess->height_guess / 2) + point_guess->offset_y_guess + spot_guess[1];
                    } else {
                        line_guess.right_guess = spot_guess[0];
                        if (point_guess->offset_y_guess > 0) {
                            line_guess.bottom_guess = spot_guess[1] + 5.0f;
                        } else {
                            line_guess.bottom_guess = spot_guess[1] - 5.0f;
                        }
                    }
                } else {
                    line_guess.right_guess = spot_guess[0] + 4.0f;
                    line_guess.bottom_guess = (float)(point_guess->height_guess / 2) + point_guess->offset_y_guess + spot_guess[1];
                }
                line_guess.unused2_guess = 1.0f;
                ((SegmentOwner_guess*)this)->Clip_guess(&line_guess,
                    highlighted_guess ? highlight_guess.argb_guess : point_guess->color_guess, rect_guess);
            }
            if (highlighted_guess) {
                if ((point_guess->offset_x_guess == 0 && point_guess->offset_y_guess == 0) || !labels_guess) {
                    CXStr text_guess(point_guess->text_guess);
                    fonts_guess[point_guess->size_guess - 1]->DrawText_guess(text_guess,
                        (int)(spot_guess[0] - (float)(point_guess->width_guess / 2)),
                        (int)(spot_guess[1] - (float)point_guess->height_guess - 2.0f),
                        300, rect_guess, highlight_guess.argb_guess, 0, 0);
                } else {
                    CXStr text_guess(point_guess->text_guess);
                    fonts_guess[point_guess->size_guess - 1]->DrawText_guess(text_guess,
                        (int)((float)point_guess->offset_x_guess + spot_guess[0]),
                        (int)((float)point_guess->offset_y_guess + spot_guess[1]),
                        300, rect_guess, highlight_guess.argb_guess, 0, 0);
                }
            } else if (labels_guess) {
                CXStr text_guess(point_guess->text_guess);
                fonts_guess[point_guess->size_guess - 1]->DrawText_guess(text_guess,
                    (int)((float)point_guess->offset_x_guess + spot_guess[0]),
                    (int)((float)point_guess->offset_y_guess + spot_guess[1]),
                    300, rect_guess, point_guess->color_guess, 0, 0);
            }
        }
    }

    PcCharacter_guess* pc_guess;
    if (show_arrow_guess && g_displayOffset_guess != 0 && (pc_guess = g_pcCharacter_guess) != 0) {
        MapColor_guess arrow_guess;
        arrow_guess.alpha_guess = 0xff;
        arrow_guess.red_guess = 0;
        arrow_guess.green_guess = 0;
        arrow_guess.blue_guess = 0;
        float pos_guess[3];
        pos_guess[0] = -g_displayOffset_guess->field_34_guess;
        pos_guess[1] = -g_displayOffset_guess->field_30_guess;
        pos_guess[2] = 1.0f;
        ((Viewport_guess*)this)->TransformPoint_guess(pos_guess);
        pos_guess[0] += rect_guess.left_guess;
        pos_guess[1] += rect_guess.top_guess;
        line_guess.unused_guess = pos_guess[2];
        line_guess.unused2_guess = pos_guess[2];
        // Above 190 at CHARINFO2 +0x1010 (unknown, maybe a skill) the player is an arrow showing the heading;
        // headings run 0-511, so +48 and +464 are the arrow's wings. Otherwise a small cross.
        if (((CharInfoView_guess*)pc_guess->GetCharInfo2())->field_1010_guess > 190) {
            float dir_y_guess = g_mapMath_guess->Sin_guess(g_displayOffset_guess->heading_4c_guess) * 4.0f;
            float dir_x_guess = g_mapMath_guess->Cos_guess(g_displayOffset_guess->heading_4c_guess) * 4.0f;
            float wing1_y_guess = g_mapMath_guess->Sin_guess(g_displayOffset_guess->heading_4c_guess + 48.0f) * 6.0f;
            float wing1_x_guess = g_mapMath_guess->Cos_guess(g_displayOffset_guess->heading_4c_guess + 48.0f) * 6.0f;
            float wing2_y_guess = g_mapMath_guess->Sin_guess(g_displayOffset_guess->heading_4c_guess + 464.0f) * 6.0f;
            float wing2_x_guess = g_mapMath_guess->Cos_guess(g_displayOffset_guess->heading_4c_guess + 464.0f) * 6.0f;
            float x_guess = (float)(int)pos_guess[0];
            line_guess.left_guess = wing1_x_guess + x_guess;
            float y_guess = (float)(int)pos_guess[1];
            line_guess.top_guess = y_guess + wing1_y_guess;
            float tip_x_guess = x_guess - dir_x_guess;
            line_guess.right_guess = tip_x_guess;
            float tip_y_guess = y_guess - dir_y_guess;
            line_guess.bottom_guess = tip_y_guess;
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, arrow_guess.argb_guess, rect_guess);
            line_guess.left_guess = x_guess + wing2_x_guess;
            line_guess.top_guess = y_guess + wing2_y_guess;
            line_guess.right_guess = tip_x_guess;
            line_guess.bottom_guess = tip_y_guess;
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, arrow_guess.argb_guess, rect_guess);
            line_guess.left_guess = dir_x_guess * 2.0f + x_guess;
            line_guess.top_guess = dir_y_guess * 2.0f + y_guess;
            line_guess.right_guess = tip_x_guess;
            line_guess.bottom_guess = tip_y_guess;
        } else {
            line_guess.left_guess = (float)(int)(pos_guess[0] - 2.0f);
            line_guess.top_guess = (float)(int)pos_guess[1];
            line_guess.right_guess = (float)(int)(pos_guess[0] + 3.0f);
            line_guess.bottom_guess = line_guess.top_guess;
            ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, arrow_guess.argb_guess, rect_guess);
            line_guess.left_guess = (float)(int)pos_guess[0];
            line_guess.top_guess = (float)(int)(pos_guess[1] - 2.0f);
            line_guess.right_guess = line_guess.left_guess;
            line_guess.bottom_guess = (float)(int)(pos_guess[1] + 3.0f);
        }
        ((SegmentOwner_guess*)this)->Clip_guess(&line_guess, arrow_guess.argb_guess, rect_guess);
    }

    if (g_flag_991d00_guess && pinstCMapToolbarWnd_guess->Check_guess()) {
        DrawRect_guess frame_guess(0, 0, 9999, 9999);
        DrawFrame_guess(selection_guess, 0xffffffff, frame_guess);
        if (g_selectAdd_guess) {
            g_flag_991d00_guess = 0;
            g_selectAdd_guess = 0;
        }
    }

    FormatString_guess(buffer_guess, 0x1a4a, _itoa(label_value_guess, g_itoaBuffer_guess, 10),
        0, 0, 0, 0, 0, 0, 0, 0);
    int text_width_guess = fonts_guess[1]->GetTextWidth_guess(buffer_guess);
    CXStr label_guess(buffer_guess);
    fonts_guess[1]->DrawText_guess(label_guess, rect_guess.right_guess - text_width_guess,
        rect_guess.bottom_guess - fonts_guess[1]->GetHeight_guess(), 300, rect_guess, 0xff000000, 0, 0);
}

// Stops recording and refills the Atlas folder list from the subfolders of .\Atlas.
// FUNCTION: TITANIUM 0x00535751
void OffsetOwner_guess::ScanAtlas_guess() {
    g_offsetClamp_guess = -5000.0;
    g_atlasScanFirst_guess = 0;
    g_atlasScanSecond_guess = 0;
    StopAutoMap_guess();
    if (atlas_guess != 0) {
        ResourceText_guess root_guess(g_atlasRoot_guess.Get_guess(1));
        root_guess.Unshare_guess();
        atlas_guess->Begin_guess();
        WIN32_FIND_DATAA find_guess;
        HANDLE find_handle_guess = FindFirstFileA(".\\Atlas\\*.*", &find_guess);
        if (find_handle_guess != INVALID_HANDLE_VALUE) {
            do {
                if ((find_guess.dwFileAttributes & 0x10) != 0 && find_guess.cFileName[0] != '.') {
                    {
                        ResourceText_guess folder_guess(find_guess.cFileName);
                        atlas_guess->AddFolder_guess(&folder_guess);
                    }
                    {
                        ResourceText_guess path_guess("Atlas\\");
                        path_guess.Append_guess(find_guess.cFileName);
                        path_guess.Append_guess("\\");
                        path_guess.Unshare_guess();
                        if (path_guess.Find_guess(root_guess) != 0) {
                            atlas_guess->RemoveAt_guess(atlas_guess->Count_guess() - 1);
                        }
                    }
                }
            } while (FindNextFileA(find_handle_guess, &find_guess) != 0);
        }
        FindClose(find_handle_guess);
    }
}

// Map window AboutToShow (vtable 0x658BA0 slot 49): vetoes the show unless 0x9247A0 is set or the
// 0x905CC0 check (0x005F6BC0) on 0x924470 passes; otherwise refills the Atlas folder list (0x00535751).
// FUNCTION: TITANIUM 0x0053592D
char OffsetOwner_guess::AboutToShow_guess() {
    if (EQ_GLOBAL(int, 0x009247A0) == 0) {
        if (EQ_GLOBAL(ScanController_guess*, 0x00905CC0)->Check_guess(
                EQ_GLOBAL(unsigned int, 0x00924470)) == 0) {
            return 0;
        }
    }
    ScanAtlas_guess();
    return 1;
}

// Window closing: releases the mouse capture and ends any drag or box selection.
// FUNCTION: TITANIUM 0x0053595B
char OffsetOwner_guess::AboutToHide_guess() {
    ScanAtlas_guess();
    while (g_activeSlot_guess->owner_48_guess == this) {
        ActiveSlot_guess* slot_guess = g_activeSlot_guess;
        int* count_guess = &g_activeSlot_guess->count_6c_guess;
        *count_guess = *count_guess - 1;
        if (*count_guess <= 0) {
            slot_guess->owner_48_guess = 0;
        }
    }
    g_flag_991d02_guess = 0;
    g_flag_991d00_guess = 0;
    return 1;
}

struct MapPoint_guess {
    int x_guess;
    int y_guess;
    MapPoint_guess(int x, int y) { x_guess = x; y_guess = y; }
};

struct MapSize_guess {
    int cx_guess;
    int cy_guess;
    MapSize_guess(const CXRect& rect) {
        cy_guess = rect.bottom - rect.top;
        cx_guess = rect.right - rect.left;
    }
};

struct MapRect_guess {
    int left_guess;
    int top_guess;
    int right_guess;
    int bottom_guess;
    MapRect_guess(int l, int t, int r, int b) { left_guess = l; top_guess = t; right_guess = r; bottom_guess = b; }
    // EXTERNAL: TITANIUM 0x004D90F1 ??0MapRect_guess@@QAE@ABUMapPoint_guess@@ABUMapSize_guess@@@Z
    MapRect_guess(const MapPoint_guess& point_guess, const MapSize_guess& size_guess);
    // EXTERNAL: TITANIUM 0x004D9160 ??4MapRect_guess@@QAE?AU0@ABU0@@Z
    MapRect_guess operator=(const MapRect_guess& other_guess);
};

struct MapRenderArea_guess {
    // EXTERNAL: TITANIUM 0x0059D860 MapRenderArea_guess::GetClientRect_guess
    MapRect_guess GetClientRect_guess() const;
};

struct MapRenderAreaVCall_guess {
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
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
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
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual MapRect_guess GetClientRect_guess() const;
};

struct AtlasRender_guess {
    // EXTERNAL: TITANIUM 0x004DA867 ??0AtlasRender_guess@@QAE@PAUCXWnd@@HUMapRect_guess@@@Z
    AtlasRender_guess(CXWnd* parent_guess, int id_guess, MapRect_guess rect_guess);
    // EXTERNAL: TITANIUM 0x004DA486 AtlasRender_guess::SetFile_guess
    void SetFile_guess(const CXStr& file_guess);
    char data_guess[0x16c];
};

struct AtlasCombo_guess {
    // EXTERNAL: TITANIUM 0x0059C330 AtlasCombo_guess::SetColors_guess
    void SetColors_guess(unsigned long first_guess, unsigned long second_guess, unsigned long third_guess);
    // EXTERNAL: TITANIUM 0x0059D080 AtlasCombo_guess::Choose_guess
    void Choose_guess(int index_guess);
};

struct MapTabWnd_guess {
    // EXTERNAL: TITANIUM 0x005BC4B0 MapTabWnd_guess::SetPage_guess
    void SetPage_guess(CXWnd* page_guess);
};

struct MapChildWnd_guess {
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
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess();
    virtual void Slot23_guess();
    virtual void Slot24_guess();
    virtual void Slot25_guess();
    virtual void Slot26_guess();
    virtual void Slot27_guess();
    virtual void Slot28_guess();
    virtual void Slot29_guess();
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
    virtual void Slot40_guess();
    virtual void Slot41_guess();
    virtual void Slot42_guess();
    virtual void Slot43_guess();
    virtual void Slot44_guess();
    virtual void Slot45_guess();
    virtual void Slot46_guess();
    virtual void Slot47_guess();
    virtual void Show_guess(int show_guess, int all_guess);           // 0xc0
    virtual void Slot49_guess();
    virtual void Slot50_guess();
    virtual void Slot51_guess();
    virtual void Slot52_guess();
    virtual void Slot53_guess();
    virtual void Slot54_guess();
    virtual void Slot55_guess();
    virtual void Slot56_guess();
    virtual void Slot57_guess();
    virtual void Slot58_guess();
    virtual void Slot59_guess();
    virtual void Slot60_guess();
    virtual void Slot61_guess();
    virtual void Slot62_guess();
    virtual void SetWindowText_guess(const CXStr& text_guess);        // 0xfc
};

struct AtlasPathTable_guess {
    // EXTERNAL: TITANIUM 0x0060C0C0 AtlasPathTable_guess::Get_guess
    CXStr& Get_guess(int index_guess);
};
#define g_atlasPaths_guess EQ_GLOBAL(AtlasPathTable_guess, 0x0099E414)
#define g_toolbarAllowed_guess EQ_GLOBAL(int, 0x009247A0)
#define g_atlasAllowed_guess EQ_GLOBAL(int, 0x009247B0)

// EXTERNAL: TITANIUM 0x004B1357 ??H@YA?AUCXStr@@ABU0@PBD@Z
CXStr __cdecl operator+(const CXStr& left_guess, const char* right_guess);
// EXTERNAL: TITANIUM 0x00576670 FileExists_guess
bool __cdecl FileExists_guess(const char* path_guess);
// EXTERNAL: TITANIUM 0x006220E9 _itoa
extern "C" char* __cdecl _itoa(int value_guess, char* buffer_guess, int radix_guess);

struct SidlPieceView_guess {
    char pad_00_guess[0x60];
    unsigned int style_60_guess;
};

struct MapViewWndBase_guess {
    // EXTERNAL: TITANIUM 0x005A3850 ??0MapViewWndBase_guess@@QAE@PAUCXWnd@@ABUCXStr@@HHPAD@Z
    MapViewWndBase_guess(CXWnd* parent, const CXStr& screen, int flags, int iniVersion, char* blockName);
    // EXTERNAL: TITANIUM 0x005A3100 MapViewWndBase_guess::~MapViewWndBase_guess
    virtual ~MapViewWndBase_guess();
};

// Layer flags of the map object, read as bool.
struct MapViewFlags_guess {
    char pad_00_guess[0x6c];
    int min_z_guess;          // 0x6c
    int max_z_guess;          // 0x70
    bool z_filter_guess;      // 0x74
    char pad_75_guess[0x0b];
    bool labels_guess;        // 0x80
};

// Map object at 0x1ec: ctor 0x0053236E, dtor 0x005323B2.
struct MapViewMember_guess : InitObject_guess {
    ~MapViewMember_guess() { ((DestroyObject_guess*)this)->~DestroyObject_guess(); }
};

// EXTERNAL: TITANIUM 0x00658BA0 ??_7MapViewWnd_guess@@6B@
struct MapViewWnd_guess : MapViewWndBase_guess {
    char pad_004_guess[0x20 - 0x04];
    int width_020_guess;
    int height_024_guess;
    char pad_028_guess[0x5c - 0x28];
    unsigned char show_05c_guess;
    char pad_05d_guess[3];
    char pad_060_guess[4];
    unsigned int style_064_guess;
    char pad_068_guess[0x124 - 0x68];
    SidlPieceView_guess* piece_124_guess;
    char pad_128_guess[0x15c - 0x128];
    unsigned char flag_15c_guess;
    char pad_15d_guess[3];
    CXWnd* panLeft_160_guess;
    CXWnd* panRight_164_guess;
    CXWnd* panUp_168_guess;
    CXWnd* panDown_16c_guess;
    CXWnd* panReset_170_guess;
    CXWnd* zoomIn_174_guess;
    CXWnd* zoomOut_178_guess;
    CXWnd* toolbar_17c_guess;
    unsigned char flag_180_guess;
    char pad_181_guess[0x1a0 - 0x181];
    CButtonWnd* labels_1a0_guess;
    MapChildWnd_guess* minZ_1a4_guess;
    MapChildWnd_guess* maxZ_1a8_guess;
    CButtonWnd* zFilter_1ac_guess;
    CButtonWnd* layer0_1b0_guess;
    CButtonWnd* layer1_1b4_guess;
    CButtonWnd* layer2_1b8_guess;
    CButtonWnd* layer3_1bc_guess;
    CButtonWnd* layer1Active_1c0_guess;
    CButtonWnd* layer2Active_1c4_guess;
    CButtonWnd* layer3Active_1c8_guess;
    CXWnd* loadCurrent_1cc_guess;
    CXWnd* atlasPage_1d0_guess;
    MapChildWnd_guess* mapPage_1d4_guess;
    MapTabWnd_guess* subwindows_1d8_guess;
    MapRenderArea_guess* mapArea_1dc_guess;
    CXWnd* atlasArea_1e0_guess;
    AtlasRender_guess* atlasRender_1e4_guess;
    AtlasCombo_guess* atlasCombo_1e8_guess;
    MapViewMember_guess map_1ec_guess;
    char pad_270_guess[4];

    MapViewWnd_guess(CXWnd* parent_guess);
    virtual ~MapViewWnd_guess();
    CSidlScreenWnd* Sidl_guess() { return (CSidlScreenWnd*)this; }
    int PostDraw_guess();
};

// Draws the map into MVW_MapRenderArea, or string 0x1A48 when no map is loaded (0x793760).
// FUNCTION: TITANIUM 0x0053598F
// @early-stop: budget, structural ndiff=13
int MapViewWnd_guess::PostDraw_guess() {
    if (show_05c_guess != 0) {
        if (((CXWnd*)mapArea_1dc_guess)->IsReallyVisible()) {
            MapRect_guess rect_guess = ((MapRenderAreaVCall_guess*)mapArea_1dc_guess)->GetClientRect_guess();
            if (rect_guess.right_guess - rect_guess.left_guess > 0 &&
                rect_guess.bottom_guess - rect_guess.top_guess > 0) {
                if (EQ_GLOBAL(unsigned char, 0x00793760) != 0) {
                    ((MapLayer_guess*)&map_1ec_guess)->Draw_guess(*(DrawRect_guess*)&rect_guess);
                } else {
                    MapFont_guess* font_guess = g_mapGlobals_guess->fonts_guess.Get_guess(3);
                    CXStr text_guess(pStringTable->getString(0x1a48, 0));
                    font_guess->DrawText_guess(text_guess, rect_guess.left_guess + 0x1e,
                        rect_guess.top_guess + 0x1e, 0x320, *(DrawRect_guess*)&rect_guess,
                        0xff000000, 0, 0);
                }
            }
        }
    }
    return 0;
}

// Map window constructor: finds the MVW_ controls, checks all four layer buttons with layer 1 active, and
// sets up the Atlas tab only when Default.xml exists in UI path 1 and 0x9247B0 is set (else the Map page is
// shown). Then default extents, the Atlas folder list (0x00535751) and a zone change saved before the
// window existed (0x005331ED).
// FUNCTION: TITANIUM 0x00535CAA
// @early-stop: budget, structural ndiff=267
MapViewWnd_guess::MapViewWnd_guess(CXWnd* parent_guess)
    : MapViewWndBase_guess(parent_guess, "MapViewWnd", -0x201, 1, 0) {
    flag_180_guess = 0;
    panLeft_160_guess = 0;
    panRight_164_guess = 0;
    panUp_168_guess = 0;
    panDown_16c_guess = 0;
    panReset_170_guess = 0;
    zoomIn_174_guess = 0;
    zoomOut_178_guess = 0;
    layer0_1b0_guess = 0;
    layer1_1b4_guess = 0;
    layer2_1b8_guess = 0;
    layer3_1bc_guess = 0;
    layer1Active_1c0_guess = 0;
    layer2Active_1c4_guess = 0;
    layer3Active_1c8_guess = 0;
    labels_1a0_guess = 0;
    minZ_1a4_guess = 0;
    maxZ_1a8_guess = 0;
    zFilter_1ac_guess = 0;
    toolbar_17c_guess = 0;
    subwindows_1d8_guess = 0;
    mapArea_1dc_guess = 0;
    atlasArea_1e0_guess = 0;
    atlasCombo_1e8_guess = 0;
    mapPage_1d4_guess = 0;
    atlasPage_1d0_guess = 0;
    loadCurrent_1cc_guess = 0;
    if (piece_124_guess != 0) {
        style_064_guess |= piece_124_guess->style_60_guess;
        Sidl_guess()->CreateChildrenFromSidl();
        panLeft_160_guess = Sidl_guess()->GetChildItem("MVW_PanLeftButton");
        panRight_164_guess = Sidl_guess()->GetChildItem("MVW_PanRightButton");
        panUp_168_guess = Sidl_guess()->GetChildItem("MVW_PanUpButton");
        panDown_16c_guess = Sidl_guess()->GetChildItem("MVW_PanDownButton");
        panReset_170_guess = Sidl_guess()->GetChildItem("MVW_PanResetButton");
        zoomIn_174_guess = Sidl_guess()->GetChildItem("MVW_ZoomInButton");
        zoomOut_178_guess = Sidl_guess()->GetChildItem("MVW_ZoomOutButton");
        layer0_1b0_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer0Button");
        layer1_1b4_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer1Button");
        layer2_1b8_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer2Button");
        layer3_1bc_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer3Button");
        if (layer0_1b0_guess != 0) {
            layer0_1b0_guess->SetCheck(true);
        }
        if (layer1_1b4_guess != 0) {
            layer1_1b4_guess->SetCheck(true);
        }
        if (layer2_1b8_guess != 0) {
            layer2_1b8_guess->SetCheck(true);
        }
        if (layer3_1bc_guess != 0) {
            layer3_1bc_guess->SetCheck(true);
        }
        // Layer n Active: the layer new lines and labels go to; layer 1 at start.
        layer1Active_1c0_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer1ActiveButton");
        layer2Active_1c4_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer2ActiveButton");
        layer3Active_1c8_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_Layer3ActiveButton");
        if (layer1Active_1c0_guess != 0) {
            layer1Active_1c0_guess->SetCheck(true);
        }
        if (layer2Active_1c4_guess != 0) {
            layer2Active_1c4_guess->SetCheck(false);
        }
        if (layer3Active_1c8_guess != 0) {
            layer3Active_1c8_guess->SetCheck(false);
        }
        labels_1a0_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_LabelsToggleButton");
        minZ_1a4_guess = (MapChildWnd_guess*)Sidl_guess()->GetChildItem("MVW_MinZEditBox");
        maxZ_1a8_guess = (MapChildWnd_guess*)Sidl_guess()->GetChildItem("MVW_MaxZEditBox");
        zFilter_1ac_guess = (CButtonWnd*)Sidl_guess()->GetChildItem("MVW_ZFilterButton");
        // Opens the map toolbar; disabled unless 0x9247A0 is set.
        toolbar_17c_guess = Sidl_guess()->GetChildItem("MVW_ToolbarButton");
        if (toolbar_17c_guess != 0 && g_toolbarAllowed_guess == 0) {
            toolbar_17c_guess->Enabled = 0;
        }
        loadCurrent_1cc_guess = Sidl_guess()->GetChildItem("MVW_LoadCurrent");
        subwindows_1d8_guess = (MapTabWnd_guess*)Sidl_guess()->GetChildItem("MVW_Subwindows");
        mapPage_1d4_guess = (MapChildWnd_guess*)Sidl_guess()->GetChildItem("MapPage");
        atlasPage_1d0_guess = Sidl_guess()->GetChildItem("AtlasPage");

        CXStr path_guess = g_atlasPaths_guess.Get_guess(1) + "Default.xml";
        bool atlas_guess;
        if (FileExists_guess(path_guess) && g_atlasAllowed_guess != 0) {
            atlas_guess = true;
            atlasArea_1e0_guess = Sidl_guess()->GetChildItem("MVW_AtlasRenderArea");
            atlasCombo_1e8_guess = (AtlasCombo_guess*)Sidl_guess()->GetChildItem("MVW_AtlasDirCombobox");
            if (atlasCombo_1e8_guess != 0) {
                atlasCombo_1e8_guess->SetColors_guess(0xffffffff, 0xffffff00, 0xff808080);
            }
            if (atlasArea_1e0_guess != 0) {
                atlasRender_1e4_guess = new AtlasRender_guess(atlasArea_1e0_guess, 0,
                    MapRect_guess(MapPoint_guess(0, 0), MapSize_guess(atlasArea_1e0_guess->GetClientClipRect())));
                atlasRender_1e4_guess->SetFile_guess("Default.xml");
                if (atlasCombo_1e8_guess != 0) {
                    atlasCombo_1e8_guess->Choose_guess(1);
                }
            }
        } else {
            atlas_guess = false;
        }
        if (subwindows_1d8_guess != 0 && atlasPage_1d0_guess != 0 && !atlas_guess) {
            subwindows_1d8_guess->SetPage_guess(atlasPage_1d0_guess);
            if (mapPage_1d4_guess != 0) {
                mapPage_1d4_guess->Show_guess(1, 1);
            }
        }
        mapArea_1dc_guess = (MapRenderArea_guess*)Sidl_guess()->GetChildItem("MVW_MapRenderArea");
        MapRect_guess rect_guess(10, 10, 100, 100);
        if (mapArea_1dc_guess != 0) {
            rect_guess = mapArea_1dc_guess->GetClientRect_guess();
        }
        // Extents until a map loads.
        ((DestroyObject_guess*)&map_1ec_guess)->Apply_guess(-1000, 1000, -1000, 1000);
        ((Scale_guess*)&map_1ec_guess)->Update_guess(2.0f);
        ((ValueBounds_guess*)&map_1ec_guess)->Set_guess(rect_guess.right_guess - rect_guess.left_guess,
            rect_guess.bottom_guess - rect_guess.top_guess, rect_guess.left_guess, rect_guess.top_guess);
        height_024_guess = 0x1d6;
        ((Viewport_guess*)&map_1ec_guess)->field_20_guess = 0;
        ((Viewport_guess*)&map_1ec_guess)->field_24_guess = 0;
        width_020_guess = 0x24e;
        flag_15c_guess = 0;
        ((OffsetOwner_guess*)this)->ScanAtlas_guess();
        if (labels_1a0_guess != 0) {
            labels_1a0_guess->SetCheck(((MapViewFlags_guess*)&map_1ec_guess)->labels_guess);
        }
        if (zFilter_1ac_guess != 0) {
            zFilter_1ac_guess->SetCheck(((MapViewFlags_guess*)&map_1ec_guess)->z_filter_guess);
        }
        char buffer_guess[64];
        if (minZ_1a4_guess != 0) {
            minZ_1a4_guess->SetWindowText_guess(CXStr(_itoa(map_1ec_guess.field_6c_guess, buffer_guess, 10)));
        }
        if (maxZ_1a8_guess != 0) {
            // Radix 30 where 10 is meant, as decompiled; check the binary before changing it
            // (this function is not matched yet).
            maxZ_1a8_guess->SetWindowText_guess(CXStr(_itoa(map_1ec_guess.field_70_guess, buffer_guess, 30)));
        }
        if (g_selectionReady_guess != 0) {
            ((AtlasControlOwner_guess*)this)->SetMap_guess(g_selectedValue_guess,
                EQ_ARRAY(float, 0x00991D2C), EQ_ARRAY(float, 0x00991D40));
            g_selectionReady_guess = 0;
        }
    }
}

// Scalar deleting destructor of the map window (vtable 0x658BA0 slot 1): destroys it and frees it when
// flag 1 is set.
// FUNCTION: TITANIUM 0x0053670F
void* Outer_guess::Delete_guess(unsigned char flags_guess) {
    this->Outer_guess::~Outer_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Destructor of the map window: frees the map object's node chains (+0x1EC, 0x005323B2), then runs the
// CSidlScreenWnd destructor (0x005A3100).
// FUNCTION: TITANIUM 0x0053672B
Outer_guess::~Outer_guess()  {
}

// MVW_LoadCurrent: shows the current zone's map, with the world extents or +-2000 when they are unknown.
// FUNCTION: TITANIUM 0x00536741
void AtlasControlOwner_guess::SelectMap_guess() {
    float first_guess[3];
    float second_guess[3];
    event_guess.enabled_guess = 1;
    if (g_mapError_guess->GetBounds_guess(first_guess, second_guess) == -1) {
        first_guess[0] = g_mapBounds_guess;
        first_guess[1] = g_mapBounds_guess;
        first_guess[2] = g_mapBounds_guess;
        second_guess[0] = g_mapBoundsSmall_guess;
        second_guess[1] = g_mapBoundsSmall_guess;
        second_guess[2] = g_mapBoundsSmall_guess;
        FUN_00574110_guess("Failed to Get World Extents, using default values.\n");
    }
    SetMap_guess(g_skinError_guess, first_guess, second_guess);
}

// Switches to zone `resource_id_guess`: saves the old user layers, shows all four layers with layer 1 active,
// and loads the new map. The current zone takes the extents passed in.
// FUNCTION: TITANIUM 0x00535AA0
// @early-stop: budget, structural ndiff=50
void MainOwner_guess::Initialize_guess(unsigned int resource_id_guess,
    const float* first_point_guess, const float* second_point_guess) {
    unsigned int saved_resource_id_guess = resource_id_guess;
    const char* map_name_guess = this->map_name_guess;
    char text_guess[256];
    if (map_name_guess[0] != 0) {
        map_guess.SaveAllEx_guess(map_name_guess);
    }
    this->resource_id_guess = saved_resource_id_guess;
    int resource_index_guess = g_resourceTable_guess->Get_guess(saved_resource_id_guess);
    if (resource_index_guess != 0 && field_1d4_guess != 0) {
        FormatResourceText_guess(text_guess, 0x1a49, resource_index_guess + 0x91,
            0, 0, 0, 0, 0, 0, 0, 0);
        ResourceText_guess resource_text_guess(text_guess);
        field_1d4_guess->Add_guess(&resource_text_guess);
    }
    g_resourceTable_guess->Update_guess(saved_resource_id_guess, map_name_guess);
    MapViewMap_guess* map_pointer_guess = &map_guess;
    ((ClearObject_guess*)map_pointer_guess)->~ClearObject_guess();
    ((OffsetOwner_guess*)this)->StopAutoMap_guess();
    map_pointer_guess->flags_guess |= 1;
    map_pointer_guess->saved_81_guess = 1;
    map_pointer_guess->flags_guess |= 2;
    map_pointer_guess->saved_81_guess = 1;
    map_pointer_guess->flags_guess |= 4;
    map_pointer_guess->saved_81_guess = 1;
    map_pointer_guess->flags_guess |= 8;
    map_pointer_guess->saved_81_guess = 1;
    if (field_1b0_guess != 0) {
        field_1b0_guess->SetCheck(1);
    }
    if (field_1b4_guess != 0) {
        field_1b4_guess->SetCheck(1);
    }
    if (field_1b8_guess != 0) {
        field_1b8_guess->SetCheck(1);
    }
    if (field_1bc_guess != 0) {
        field_1bc_guess->SetCheck(1);
    }
    map_pointer_guess->field_68_guess = 1;
    if (field_1c0_guess != 0) {
        field_1c0_guess->SetCheck(1);
    }
    if (field_1c4_guess != 0) {
        field_1c4_guess->SetCheck(0);
    }
    if (field_1c8_guess != 0) {
        field_1c8_guess->SetCheck(0);
    }
    ((OffsetOwner_guess*)this)->ScanAtlas_guess();
    map_pointer_guess->field_20_guess = 0;
    map_pointer_guess->field_24_guess = 0;
    map_pointer_guess->LoadAllLayers_guess(map_name_guess);
    if (saved_resource_id_guess == g_skinError_guess) {
        ((DestroyObject_guess*)map_pointer_guess)->Apply_guess(
            (int)first_point_guess[1], (int)second_point_guess[1],
            (int)*first_point_guess, (int)*second_point_guess);
    }
}

// Pan buttons move 5 units, PanReset centres, Zoom In/Out x1.1 and /1.1 (never below 1). Layer0-3 show or
// hide a layer (bits 1, 2, 4, 8); Layer1-3Active pick the drawing layer. Labels and ZFilter toggle; a click
// in the render area selects what is under the cursor. On the Atlas tab a folder choice is saved as [Main]
// AtlasSkin.
// FUNCTION: TITANIUM 0x005367AA
// @early-stop: budget, structural ndiff=65
int AtlasControlOwner_guess::HandleControl_guess(CXWnd* control_guess, unsigned int message_guess, void* data_guess) {
    if (((MessageManager_guess*)this)->Check_guess() != 0 && message_guess == 1) {
        if (control_guess == control_1cc_guess) {
            SelectMap_guess();
        } else if (control_guess == control_1e4_guess) {
            int skin_index_guess;
            {
                CXStr skin_guess = ((TextControl_guess*)control_1e4_guess)->GetText_guess();
                skin_index_guess = g_skinManager_guess->FindSkin_guess((char*)skin_guess);
            }
            if (skin_index_guess != 0) {
                if (skin_index_guess == g_skinError_guess) {
                    SelectMap_guess();
                } else {
                    float first_guess[3] = {
                        g_mapBounds_guess, g_mapBounds_guess, g_mapBounds_guess
                    };
                    float second_guess[3] = {
                        g_mapBoundsSmall_guess, g_mapBoundsSmall_guess, g_mapBoundsSmall_guess
                    };
                    SetMap_guess(skin_index_guess, first_guess, second_guess);
                    event_guess.enabled_guess = 0;
                    ((DestroyObject_guess*)&event_guess)->ComputeBounds_guess();
                    if (manager_1d8_guess != 0) {
                        ((RefreshManager_guess*)manager_1d8_guess)->Refresh_guess(manager_1d4_guess, 1);
                    }
                }
            }
        } else if (control_guess == (CXWnd*)atlas_guess && control_1e4_guess != 0) {
            CXStr path_guess("Atlas\\");
            {
                CXStr folder_guess = atlas_guess->GetText_guess();
                ((ResourceTextAppender_guess*)&path_guess)->Append_guess(folder_guess);
            }
            path_guess += EQ_ARRAY(char, 0x0064217C);
            g_atlasRoot_guess.Set_guess(1, &path_guess);
            {
                CXStr default_guess("Default.xml");
                ((TextControl_guess*)control_1e4_guess)->SetText_guess(&default_guess);
            }
            {
                CXStr skin_name_guess = atlas_guess->GetText_guess();
                SetAtlasSetting_guess(EQ_ARRAY(char, 0x00642F10), "AtlasSkin",
                    (char*)skin_name_guess);
            }
        }
    }

    if (((MessageManager_guess*)this)->Check_guess() != 0 &&
        ((PermissionTarget_guess*)this)->Permit_guess() != 0) {
        if (message_guess == 6) {
            return 0;
        }
        // 0xE: an edit box changed; MVW_MinZEditBox and MVW_MaxZEditBox set the height filter.
        if (message_guess == 0xe) {
            if (control_guess == control_1a4_guess) {
                CXStr text_guess = ((ControlWindow_guess*)control_1a4_guess)->GetText_guess();
                event_guess.first_state_guess = ((StringIndex_guess*)&text_guess)->Get_guess();
                event_guess.changed_guess = 1;
            } else if (control_guess == control_1a8_guess) {
                CXStr text_guess = ((ControlWindow_guess*)control_1a8_guess)->GetText_guess();
                event_guess.second_state_guess = ((StringIndex_guess*)&text_guess)->Get_guess();
                event_guess.changed_guess = 1;
            }
        } else if (message_guess == 1) {
            if (control_guess == control_17c_guess) {
                pinstCMapToolbarWnd_guess->Slot33_guess();
            } else if (control_guess == control_174_guess) {
                ((Scale_guess*)&event_guess)->Update_guess(event_guess.ratio_guess * g_mapScaleLarge_guess);
            } else if (control_guess == control_178_guess) {
                ((Scale_guess*)&event_guess)->Update_guess(event_guess.ratio_guess * g_mapScaleSmall_guess);
                if (event_guess.ratio_guess < 1.0f) {
                    ((Scale_guess*)&event_guess)->Update_guess(g_mapBoundsTop_guess);
                }
            } else if (control_guess == control_168_guess) {
                event_guess.offset_y_guess += 5;
            } else if (control_guess == control_16c_guess) {
                event_guess.offset_y_guess -= 5;
            } else if (control_guess == control_160_guess) {
                event_guess.offset_x_guess += 5;
            } else if (control_guess == control_164_guess) {
                event_guess.offset_x_guess -= 5;
            } else if (control_guess == control_170_guess) {
                event_guess.offset_x_guess = 0;
                event_guess.offset_y_guess = 0;
            } else if (control_guess == control_1c0_guess) {
                event_guess.selection_guess = 1;
            } else if (control_guess == control_1c4_guess) {
                event_guess.selection_guess = 2;
            } else if (control_guess == control_1c8_guess) {
                event_guess.selection_guess = 3;
            } else if (control_guess == control_1b0_guess) {
                event_guess.changed_guess = 1;
                if (((CButtonWnd*)control_1b0_guess)->Checked == 0) {
                    event_guess.flags_guess &= 0xfffffffe;
                } else {
                    event_guess.flags_guess |= (unsigned int)message_guess;
                }
            } else if (control_guess == control_1b4_guess) {
                event_guess.changed_guess = 1;
                if (((CButtonWnd*)control_1b4_guess)->Checked == 0) {
                    event_guess.flags_guess &= 0xfffffffd;
                } else {
                    event_guess.flags_guess |= 2;
                }
            } else if (control_guess == control_1b8_guess) {
                event_guess.changed_guess = 1;
                if (((CButtonWnd*)control_1b8_guess)->Checked == 0) {
                    event_guess.flags_guess &= 0xfffffffb;
                } else {
                    event_guess.flags_guess |= 4;
                }
            } else if (control_guess == control_1bc_guess) {
                event_guess.changed_guess = 1;
                if (((CButtonWnd*)control_1bc_guess)->Checked == 0) {
                    event_guess.flags_guess &= 0xfffffff7;
                } else {
                    event_guess.flags_guess |= 8;
                }
            } else if (control_guess == control_1ac_guess) {
                event_guess.changed_guess = 1;
                event_guess.toggle_guess = ((CButtonWnd*)control_1ac_guess)->Checked != 0;
            } else if (control_guess == control_1a0_guess) {
                event_guess.changed_guess = 1;
                event_guess.first_flag_guess = ((CButtonWnd*)control_1a0_guess)->Checked != 0;
            } else if (control_guess == control_1dc_guess) {
                event_guess.color_value_guess = g_atlasScanSecond_guess;
                ((ColorOwner_guess*)&event_guess)->AddLineToSelection_guess((PackedColor_guess*)g_atlasScanFirst_guess);
            }
        }
    }
    return ((CSidlScreenWnd*)this)->WndNotification(control_guess, message_guess, data_guess);
}

