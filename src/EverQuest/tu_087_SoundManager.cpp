// CFLAGS: /O1 /GS /GX /Gy /MT /GR-
// Estimated object 87: a hint from compare/tumap.py.
// Sound on Miles (mss32; the g_AIL_* globals are its import slots): the sound manager, assets
// (.wav/.mp3/.xmi), 2D/3D/XMIDI instances, emitters, zone music and the MP3 player; and the slide show.
// Most classes are per-function views: QueueState_/SoundData_/Manager_guess are one sound asset (renames say
// SoundAsset_Play), MusicManager_guess the music manager, PointerArray_/FileScanner_guess the MP3 player.
#include "titanium/eqaddr.h"
#include <winsock2.h>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "titanium/crt.h"
#include "titanium/wnd/CVideoModesWnd.h"

#define g_value_guess EQ_GLOBAL(int, 0x00923D74)

typedef void* (__stdcall *GetForegroundWindowFn_guess)();
typedef int (__stdcall *DeviceStateFn_guess)(void* self_guess, int size_guess,
    char* data_guess);

struct InputVtable_guess {
    char padding00_guess[0x24];
    DeviceStateFn_guess getState_guess; // 0x24
};

struct InputDevice_guess {
    InputVtable_guess* vtable_guess; // 0x0
};

#define g_getForegroundWindow_guess EQ_GLOBAL(GetForegroundWindowFn_guess, 0x0063F244)
#define g_foregroundWindow_guess EQ_GLOBAL(void*, 0x00923770)
#define g_inputDevice_guess EQ_GLOBAL(InputDevice_guess*, 0x00988C80)

struct RangeCallback_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess(int value_guess); // 0x10
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess();
    virtual void Slot08_guess(); // 0x20
};

struct RangeObject_guess {
    char padding00_guess[0x14];
    unsigned int start_guess; // 0x14
    int length_guess; // 0x18
    char padding1C_guess[0x28 - 0x1C];
    int active_guess; // 0x28
    RangeCallback_guess* callback_guess; // 0x2C
    char entered_guess; // 0x30

    char Process_guess(unsigned int value_guess);
};

struct SoundInstance_guess {
    void* table_guess; // 0x0
    int state_guess; // 0x4
    int argument_guess; // 0x8
    int valueC_guess; // 0xC
    int value10_guess; // 0x10
    int value14_guess; // 0x14

    SoundInstance_guess(int argument);
};

struct SampleObject_guess;

struct WaveInstance3D_guess : SoundInstance_guess {
    int handle_guess; // 0x18
    float targetVolume_guess; // 0x1C
    float currentVolume_guess; // 0x20
    float startVolume_guess; // 0x24
    int startTick_guess; // 0x28
    int duration_guess; // 0x2C

    WaveInstance3D_guess(SampleObject_guess* source_guess);
    char Update_guess();
    char Update3D_guess();
    void SetVolume_guess(float volume_guess, int newDuration_guess);
    void SetPosition_guess(float x_guess, float y_guess, float z_guess);
};

#define g_table_guess EQ_GLOBAL(void*, 0x0064C0D0)

struct Node_guess {
    virtual void Slot00_guess(int value_guess);
    virtual void Detach_guess(int value_guess);
    virtual void SetIndex_guess(int index_guess);
    virtual char Check_guess();
    virtual void Slot10_guess(int value_guess);
    virtual void Slot14_guess(float value_guess, int value2_guess);
    virtual int GetKind_guess();

    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10
    Node_guess* next_guess; // 0x14

    void SetValue_guess(int value_guess);

    void Finish_guess();
};

struct ValueSetter_guess {
    char padding_guess[4];
    char value04_guess; // 0x4

    // EXTERNAL: TITANIUM 0x00609D70 ValueSetter_guess::Check_guess
    char Check_guess();
    void SetValue_guess(char value_guess);
};

struct CallbackInterface_guess {
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
    virtual void Slot25_guess(int value_guess);
    virtual void Slot26_guess();
    virtual void Slot27_guess(float value_guess); // 0x6C
    virtual void Slot28_guess();
    virtual void Slot29_guess();
    virtual void Slot30_guess(int value_guess);
    virtual void Slot31_guess();
    virtual void Slot32_guess();
    virtual void Slot33_guess();
    virtual void Slot34_guess();
    virtual void Slot35_guess();
    virtual void Slot36_guess();
    virtual void Slot37_guess();
};

#define g_callbackInterface_guess EQ_GLOBAL(CallbackInterface_guess*, 0x0099E364)

#define g_screenMode_guess EQ_GLOBAL(int, 0x00923780)
#define g_screenWidth_guess EQ_GLOBAL(int, 0x0092379C)
#define g_screenHeight_guess EQ_GLOBAL(int, 0x009237A0)

union ColorValue_guess {
    unsigned int value_guess;
    unsigned char bytes_guess[4];
};

struct SurfaceObject_guess {
    virtual void Slot00_guess(int handle_guess);
    virtual void Slot01_guess();
    virtual void Slot02_guess(int mode_guess, int left_guess, int top_guess,
        int width_guess, int* rect_guess, unsigned int color_guess,
        int first_guess, int second_guess);
};

struct FadeSprite_guess {
    char padding00_guess[0x14];
    unsigned int start_guess; // 0x14
    int length_guess; // 0x18
    unsigned int fadeIn_guess; // 0x1C
    unsigned int fadeOut_guess; // 0x20
    int handle_guess; // 0x24
    int x_guess; // 0x28
    int y_guess; // 0x2C
    ColorValue_guess color_guess; // 0x30
    SurfaceObject_guess* shadow_guess; // 0x34
    SurfaceObject_guess* image_guess; // 0x38

    char Process_guess(unsigned int value_guess);
};

struct CallbackListNode_guess {
    virtual void Slot00_guess() = 0;
    virtual char Process_guess(int value_guess) = 0;

    int value04_guess; // 0x4
    CallbackListNode_guess* next_guess; // 0x8
    int value0C_guess; // 0xC
    int kind_guess; // 0x10
};

struct CallbackListState_guess {
    unsigned int boundary_guess; // 0x0
    CallbackListNode_guess* first_guess; // 0x4
    int value08_guess; // 0x8
    char active_guess; // 0xC

    char Update_guess();
};

struct UpdateManager_guess {
    // EXTERNAL: TITANIUM 0x0044A63A UpdateManager_guess::Update_guess
    void Update_guess();
    char padding00_guess[4];
    void* service_guess; // 0x4
};

#define g_updateManager_guess EQ_GLOBAL(UpdateManager_guess*, 0x00851390)

#define g_nodeVtable_guess EQ_GLOBAL(void*, 0x0064C0CC)

typedef void (__stdcall *AILSampleRelease_guess)(int handle_guess);
#define g_AIL_release_sample_guess EQ_GLOBAL(AILSampleRelease_guess, 0x0063F408)
#define g_sampleVtable_guess EQ_GLOBAL(void*, 0x0064C0F4)
typedef void (__stdcall *AILSampleFunction_guess)(int handle_guess);
#define g_AIL_end_sample_guess EQ_GLOBAL(AILSampleFunction_guess, 0x0063F3F8)
#define g_AIL_init_sample_guess EQ_GLOBAL(AILSampleFunction_guess, 0x0063F3FC)
typedef int (__stdcall *AILSampleStatus_guess)(int handle_guess);
#define g_AIL_sample_status_guess EQ_GLOBAL(AILSampleStatus_guess, 0x0063F400)
typedef int (__stdcall *AILAllocate3DSampleHandle_guess)(int handle_guess);
#define g_AIL_allocate_3D_sample_handle_guess EQ_GLOBAL(AILAllocate3DSampleHandle_guess, 0x0063F3F4)
typedef void (__stdcall *AILSetSampleVolumeLevels_guess)(int handle_guess,
    float left_guess, float right_guess);
#define g_AIL_set_sample_volume_levels_guess EQ_GLOBAL(AILSetSampleVolumeLevels_guess, 0x0063F404)
typedef void (__stdcall *AIL3DSampleRelease_guess)(int handle_guess);
#define g_AIL_release_3D_sample_guess EQ_GLOBAL(AIL3DSampleRelease_guess, 0x0063F3F0)
#define g_3dSampleVtable_guess EQ_GLOBAL(void*, 0x0064C118)

typedef void (__stdcall *AIL3DSampleEnd_guess)(int handle_guess);
#define g_AIL_end_3D_sample_guess EQ_GLOBAL(AIL3DSampleEnd_guess, 0x0063F3E8)
typedef int (__stdcall *AIL3DSampleStatus_guess)(int handle_guess);
#define g_AIL_3D_sample_status_guess EQ_GLOBAL(AIL3DSampleStatus_guess, 0x0063F3EC)
typedef void (__stdcall *AIL3DSampleVolume_guess)(int handle_guess, float volume_guess);
#define g_AIL_set_3D_sample_volume_guess EQ_GLOBAL(AIL3DSampleVolume_guess, 0x0063F3E4)
typedef void (__stdcall *SleepFunction_guess)(unsigned long milliseconds_guess);
#define g_sleep_guess EQ_GLOBAL(SleepFunction_guess, 0x0063F120)
typedef int (__stdcall *AILSetNamedSampleFile_guess)(int handle_guess,
    const char* name_guess, void* data_guess, int size_guess, int flags_guess);
#define g_AIL_set_named_sample_file_guess EQ_GLOBAL(AILSetNamedSampleFile_guess, 0x0063F37C)
typedef void (__stdcall *AILSetSampleLoopCount_guess)(int handle_guess,
    int count_guess);
#define g_AIL_set_sample_loop_count_guess EQ_GLOBAL(AILSetSampleLoopCount_guess, 0x0063F380)
typedef void (__stdcall *AILStartSample_guess)(int handle_guess);
#define g_AIL_start_sample_guess EQ_GLOBAL(AILStartSample_guess, 0x0063F384)

struct SampleObject_guess {
    void* table_guess; // 0x0
    char padding_guess[0x14];
    int handle_guess; // 0x18

    void Release_guess();
    void Release3D_guess();
    void StopAndWait_guess();
    void StopAndWait3D_guess();
    void* Delete_guess(unsigned char flags_guess);
    void* Delete3D_guess(unsigned char flags_guess);
};

struct SoundFile_guess {
    char padding00_guess[0x208];
    void* data_guess; // 0x208
    int size_guess; // 0x20C
    int format_guess; // 0x210
};

struct Params_guess;
struct SoundManager_guess;

struct SamplePlayParams_guess {
    float volume_guess; // 0x0
    int value04_guess; // 0x4
    int loopCount_guess; // 0x8
};

struct SamplePlayer_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess(float volume_guess, int value_guess); // 0x14

    char padding04_guess[0x0C - 0x04];
    SoundFile_guess* file_guess; // 0xC
    char padding10_guess[0x18 - 0x10];
    int handle_guess; // 0x18

    void Play_guess(SamplePlayParams_guess* params_guess);
    void Play3D_guess(Params_guess* params_guess);
};

struct VtableObject_guess {
    void* vtable_guess; // 0x0

    void SetVtable_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct AudioValueNotifier_guess {
    virtual void Slot00_guess();
    virtual void Slot04_guess();
    virtual void Slot08_guess();
    virtual void Slot0C_guess();
    virtual void Slot10_guess();
    virtual void Slot14_guess();
    virtual void Slot18_guess();
    virtual void Slot1C_guess();
    virtual void Notify_guess(); // vtable +0x20

    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC

    void SetAsset_guess(int value_guess);
};

struct VtableResetExternal_guess {
    // EXTERNAL: TITANIUM 0x004C52CE VtableResetExternal_guess::Reset_guess
    void Reset_guess();
};

typedef void (__stdcall *AILSequenceFunction_guess)(int handle_guess);
#define g_AIL_end_sequence_guess EQ_GLOBAL(AILSequenceFunction_guess, 0x0063F3C4)
#define g_AIL_release_sequence_guess EQ_GLOBAL(AILSequenceFunction_guess, 0x0063F3C8)
typedef int (__stdcall *AILSequenceStatus_guess)(int handle_guess);
#define g_AIL_sequence_status_guess EQ_GLOBAL(AILSequenceStatus_guess, 0x0063F3BC)
typedef int (__stdcall *AILSequenceVolume_guess)(int handle_guess);
#define g_AIL_sequence_volume_guess EQ_GLOBAL(AILSequenceVolume_guess, 0x0063F3C0)
#define g_sequenceZero_guess EQ_GLOBAL(double, 0x00640FC0)
typedef void (__stdcall *AILSetSequenceVolume_guess)(int handle_guess,
    int volume_guess, int mode_guess);
#define g_AIL_set_sequence_volume_guess EQ_GLOBAL(AILSetSequenceVolume_guess, 0x0063F3B8)
#define g_sequenceVolumeScale_guess EQ_GLOBAL(float, 0x0064C0C8)
#define g_sequenceVtable_guess EQ_GLOBAL(void*, 0x0064C13C)
typedef int (__stdcall *AILAllocateSequenceHandle_guess)(int driver_guess);
#define g_AIL_allocate_sequence_handle_guess EQ_GLOBAL(AILAllocateSequenceHandle_guess, 0x0063F3A8)
typedef int (__stdcall *AILInitSequence_guess)(int handle_guess, void* data_guess,
    int index_guess);
#define g_AIL_init_sequence_guess EQ_GLOBAL(AILInitSequence_guess, 0x0063F3AC)
typedef void (__stdcall *AILSetSequenceLoopCount_guess)(int handle_guess, int count_guess);
#define g_AIL_set_sequence_loop_count_guess EQ_GLOBAL(AILSetSequenceLoopCount_guess, 0x0063F3B0)
#define g_AIL_start_sequence_guess EQ_GLOBAL(AILSequenceFunction_guess, 0x0063F3B4)

struct SequencePlayParams_guess;

struct SequenceOwner_guess {
    char padding00_guess[0x10];
    int driver_guess; // 0x10
};

struct MusicInstance_guess : SoundInstance_guess {
    int handle_guess; // 0x18
    float volume_guess; // 0x1C

    MusicInstance_guess(int argument_guess);
    void Play_guess(SequencePlayParams_guess* params_guess);
    void Destroy_guess();
    void Stop_guess();
    char IsPlaying_guess();
    void SetVolume_guess(float volume_guess, int mode_guess);
    void* Delete_guess(unsigned char flags_guess);
};

struct CleanupContext_guess {
    char padding_guess[0x30];
    Node_guess* firstHeads_guess[12]; // 0x30
    Node_guess* secondHeads_guess[12]; // 0x60
    Node_guess* pending_guess; // 0x90

    void ReturnInstance_guess(Node_guess* node_guess);
};

// EXTERNAL: TITANIUM 0x0064C0CC ??_7ManagerBase_guess@@6B@
struct ManagerBase_guess {
    virtual ~ManagerBase_guess() { }
    void* Delete_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x0064C160 ??_7Manager_guess@@6B@
struct Manager_guess : ManagerBase_guess {
    char padding_guess[0x204];
    SoundFile_guess* value208_guess; // 0x208
    char padding20C_guess[0x214 - 0x20C];
    CleanupContext_guess* context_guess; // 0x214
    Node_guess* first_guess; // 0x218
    Manager_guess* next_guess; // 0x21C

    virtual ~Manager_guess();
    void Update_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct ManagerList_guess {
    char padding_guess[0x9C];
    Manager_guess* first_guess; // 0x9C

    void Update_guess();
    void UpdateThunk_guess();
};

struct SoundAsset_guess {
    char padding_guess[0x210];
    int value210_guess; // 0x210
    SoundManager_guess* value214_guess; // 0x214
    Node_guess* first_guess; // 0x218

    int GetType_guess();
    void Clear_guess();
    bool IsPlaying_guess();
    void SetVolume_guess(float value_guess, int value2_guess);
    void SoundAsset_Stop_guess();
    Node_guess* SoundAsset_Play_guess(Params_guess* params_guess);
};

struct ScaledQueue_guess {
    float scale_guess; // 0x0
    char padding04_guess[0x14 - 0x4];
    SoundAsset_guess* queue_guess; // 0x14

    void Dispatch_guess(float value_guess);
};

struct DispatchSelector_guess {
    char padding00_guess[0x14];
    SoundAsset_guess* queue_guess; // 0x14
    char padding18_guess[0x28 - 0x18];
    int value28_guess; // 0x28
    int value2C_guess; // 0x2C

    void FadeOut_guess(char selectSecond_guess);
};

struct ScaledQueueValue_guess {
    char padding00_guess[4];
    ScaledQueue_guess* queue_guess; // 0x4
    float value08_guess; // 0x8

    void SetMusicTrackVolume_guess(float value_guess);
};

struct ManagerQueue_guess : SoundAsset_guess {
    ManagerQueue_guess* next_guess; // 0x21C
};

struct OffsetObject_guess {
    char padding_guess[8];
    char value08_guess; // 0x8

    char* GetValue_guess();
};

struct ByteObject_guess {
    char padding_guess[0x174];
    char value174_guess; // 0x174

    void SetEnabled_guess(char value_guess);
};

struct SmallObject_guess {
    char value00_guess; // 0x0
    char value01_guess; // 0x1
    char padding02_guess[2];
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10
    char value14_guess; // 0x14
    char padding15_guess[3];
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C

    SmallObject_guess(int first_guess, int second_guess);
    int IsShuffle_guess();
};

struct FourValue_guess {
    int value00_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC

    void GetListenerLocation_guess(int* first_guess, int* second_guess,
        int* third_guess, int* fourth_guess);
};

struct PositionHolder_guess {
    FourValue_guess* values_guess; // 0x0
    char padding04_guess[8];
    float value0C_guess; // 0xC
    float value10_guess; // 0x10
};

struct IndexedObject_guess {
    char padding_guess[4];
    int value04_guess; // 0x4
    char padding08_guess[0x1C - 0x8];
    int count_guess; // 0x1C
    int* values_guess[1]; // 0x20

    int GetAt_guess(int index_guess);
    int GetCount_guess();
    int GetValue_guess();
};

struct FloatSource_guess {
    char padding_guess[0xA4];
    float valueA4_guess; // 0xA4
};

struct FloatGetter_guess {
    char padding_guess[0xC];
    FloatSource_guess* source_guess; // 0xC

    float GetVolume_guess();
};

struct Transform2D_guess {
    int value00_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    float value0C_guess; // 0xC
    float value10_guess; // 0x10

    Transform2D_guess(int id_guess);
};

// EXTERNAL: TITANIUM 0x004C5E77 CompareTrackName_guess
int __cdecl CompareTrackName_guess(const void* left_guess, const void* right_guess);
// EXTERNAL: TITANIUM 0x004C5E8A CompareTrackPath_guess
int __cdecl CompareTrackPath_guess(const void* left_guess, const void* right_guess);

struct PlaylistTrack_guess {
    const char* name_guess; // 0x0
    const char* path_guess; // 0x4
    int duration_guess; // 0x8
};

struct Playlist_guess {
    char padding_guess[0x18];
    int sortMode_guess; // 0x18
    int count_guess; // 0x1C
    PlaylistTrack_guess* tracks_guess[1]; // 0x20

    void Write_guess(char* outputPath_guess);
};

struct Mp3Track_guess {
    char* title_guess; // 0x0
    char* path_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10

    Mp3Track_guess(const char* path_guess,
        const char* title_guess, int value08_guess, int value10_guess);
};

struct QueueEntry_guess {
    void* table_guess; // 0x0
    int count_guess; // 0x4
    char padding_guess[0x17C - 0x8];
    QueueEntry_guess* previous_guess; // 0x17C
};

struct LinkOwner_guess;

struct LinkPart_guess {
    LinkOwner_guess* next_guess; // 0x0
    LinkOwner_guess* previous_guess; // 0x4

    void Attach_guess(LinkOwner_guess* item_guess);
};

struct LinkPrefix_guess {
    int value00_guess; // 0x0
};

struct LinkOwner_guess : LinkPrefix_guess, LinkPart_guess {
    void* owner_guess; // 0xC
};

struct LinkList_guess {
    LinkOwner_guess* first_guess; // 0x0
    LinkOwner_guess* last_guess; // 0x4

    void Insert_guess(LinkOwner_guess* item_guess);
};

struct EntryList_guess {
    char padding_guess[4];
    QueueEntry_guess* first_guess; // 0x4
    int count_guess; // 0x8

    void Clear_guess();
    void Insert_guess(QueueEntry_guess* entry_guess);
    void Remove_guess(QueueEntry_guess* entry_guess);
};

#define g_callbackVtable_guess EQ_GLOBAL(void*, 0x0064C004)

struct CallbackMarker_guess {
    ~CallbackMarker_guess() {}
};

struct SlideShowEvent_guess {
    void* vtable_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10
    int value14_guess; // 0x14
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C
    int value20_guess; // 0x20
    CallbackMarker_guess marker_guess;

    SlideShowEvent_guess(int first_guess, int second_guess, int third_guess,
        int fourth_guess, int fifth_guess);
    ~SlideShowEvent_guess();
    void* Delete_guess(unsigned char flags_guess);
};

typedef void (__stdcall *AILSetPreference_guess)(int preference_guess, int value_guess);
typedef void (__stdcall *AILServe_guess)();
typedef void (__stdcall *AILSet3DRoomType_guess)(int handle_guess, int roomType_guess);

#define g_AILSetPreference_guess EQ_GLOBAL(AILSetPreference_guess, 0x0063F354)
#define g_AILServe_guess EQ_GLOBAL(AILServe_guess, 0x0063F350)
#define g_AILSet3DRoomType_guess EQ_GLOBAL(AILSet3DRoomType_guess, 0x0063F42C)

struct AudioPreference_guess {
    void SetValue_guess(int value_guess);
};

struct RoomAudio_guess {
    char padding_guess[0x18];
    int handle_guess; // 0x18
    char padding1c_guess[0x94 - 0x1C];
    int roomType_guess; // 0x94

    int GetRoomType_guess();
    void SetListenerEnvironment_guess(int roomType_guess);
};

typedef void (__stdcall *AILStreamMSPosition_guess)(int stream_guess,
    int* position_guess, int* length_guess);
typedef void (__stdcall *AILSetStreamMSPosition_guess)(int stream_guess,
    int position_guess);
typedef int (__stdcall *AILStreamStatus_guess)(int stream_guess);
typedef void (__stdcall *AILSetStreamVolumeLevels_guess)(int stream_guess,
    float left_guess, float right_guess);

#define g_AILStreamMSPosition_guess EQ_GLOBAL(AILStreamMSPosition_guess, 0x0063F414)
#define g_AILSetStreamMSPosition_guess EQ_GLOBAL(AILSetStreamMSPosition_guess, 0x0063F418)
#define g_AILStreamStatus_guess EQ_GLOBAL(AILStreamStatus_guess, 0x0063F410)
#define g_AIL_set_stream_volume_levels_guess EQ_GLOBAL(AILSetStreamVolumeLevels_guess, 0x0063F41C)

struct AudioStream_guess {
    char padding_guess[0xA4];
    float volume_guess; // 0xA4
    int stream_guess; // 0xA8

    void SetVolume_guess(float level_guess);
    void SetPosition_guess(int position_guess);
    int GetStreamPosition_guess();
    int GetStreamLength_guess();
    int GetStatus_guess();
    void Pause_guess();
};

struct AudioStreamHolder_guess {
    char padding_guess[0xC];
    AudioStream_guess* stream_guess; // 0xC

    int GetStatus_guess();
    int GetTrackLength_guess();
    int GetTrackPosition_guess();
    void SetPosition_guess(int position_guess);
    void SetVolume_guess(float level_guess);
    void Pause_guess();
};

typedef void (__stdcall *AILPauseStream_guess)(int stream_guess, int pause_guess);
#define g_AILPauseStream_guess EQ_GLOBAL(AILPauseStream_guess, 0x0063F388)

struct ReferenceCounted_guess {
    int value00_guess; // 0x0
    int count_guess; // 0x4
};

struct MusicTrack_guess {
    int value00_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10
    ReferenceCounted_guess* value14_guess; // 0x14
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C
    char value20_guess; // 0x20
    char padding21_guess[3];
    int value24_guess; // 0x24
    int value28_guess; // 0x28
    int value2C_guess; // 0x2C
    int value30_guess; // 0x30

    MusicTrack_guess(int value10_guess,
        ReferenceCounted_guess* reference_guess, int value18_guess,
        float value00_guess, int unused_guess, int value1C_guess,
        int value24_guess, int value28_guess, int value2C_guess,
        int value0C_guess);
};

struct NodeHandle_guess {
    char padding_guess[4];
    char flag4_guess; // 0x4
    char padding5_guess[0x10 - 5];
    int value10_guess; // 0x10
    Node_guess* node_guess; // 0x14
    char padding18_guess[0x1C - 0x18];
    int order1C_guess; // 0x1C
    char flag20_guess; // 0x20
    char padding21_guess[0x30 - 0x21];
    NodeHandle_guess* next_guess; // 0x30

    void Release_guess();
};

struct MusicManager_guess {
    NodeHandle_guess* first_guess; // 0x0
    NodeHandle_guess* last_guess; // 0x4
    float value8_guess; // 0x8
    char flagC_guess; // 0xC

    void Enable_guess(int value_guess);
    void Clear_guess();
    void UpdateMusic_guess();
    void Disable_guess(int value_guess);
    void Remove_guess(int value_guess);
    void RemoveAsset_guess(Node_guess* target_guess);
    void Add_guess(int value_guess, ReferenceCounted_guess* reference_guess,
        int value18_guess, float value00_guess, int unused_guess,
        int value1C_guess, int value24_guess, int value28_guess,
        int value2C_guess, int value0C_guess);
};

struct PointerPair_guess {
    void* first_guess; // 0x0
    void* second_guess; // 0x4
    int duration_guess; // 0x8

    void Free_guess();
};

struct QueueLinkItem_guess {
    char padding_guess[0x21c];
    QueueLinkItem_guess* next_guess; // 0x21C
};

struct QueueHead_guess {
    char padding_guess[0x9c];
    QueueLinkItem_guess* first_guess; // 0x9C
    int count_guess; // 0xA0

    void Insert_guess(QueueLinkItem_guess* item_guess);
    void Remove_guess(QueueLinkItem_guess* item_guess);
};

struct NameEntry_guess {
    int value00_guess; // 0x0
    int count_guess; // 0x4
    char name_guess[0x214]; // 0x8
    NameEntry_guess* next_guess; // 0x21C
};

struct NameList_guess {
    char padding_guess[0x9c];
    NameEntry_guess* first_guess; // 0x9C

    NameEntry_guess* Find_guess(char* name_guess);
};

typedef void (__stdcall *AILCloseStream_guess)(int stream_guess);
#define g_AILCloseStream_guess EQ_GLOBAL(AILCloseStream_guess, 0x0063F420)

typedef unsigned long (__stdcall *GetTickCountFunction_guess)();
#define g_getTickCount_guess EQ_GLOBAL(GetTickCountFunction_guess, 0x0063F180)

struct TimerState_guess {
    char padding_guess[0x40];
    int minimum_guess; // 0x40
    int maximum_guess; // 0x44
    char padding48_guess[0x158 - 0x48];
    int tick_guess; // 0x158
    int next_guess; // 0x15C

    void ScheduleNextPlay_guess();
};

struct AudioStreamObject_guess {
    char padding_guess[0xa8];
    int stream_guess; // 0xA8

    void Close_guess();
};

struct AudioState_guess {
    int value00_guess; // 0x0
    int value04_guess; // 0x4
    float value08_guess; // 0x8
    char value0C_guess; // 0xC

    AudioState_guess* Initialize_guess();
};

typedef void (__stdcall *AILStartup_guess)();
typedef int (__stdcall *AILOpenXMIDIDriver_guess)(int flags_guess);
typedef int (__stdcall *AILOpenDigitalDriver_guess)(int rate_guess,
    int bits_guess, int channels_guess, int flags_guess);
typedef int (__stdcall *AILEnumerate3DProviders_guess)(int* index_guess,
    int* provider_guess, char** name_guess);
typedef void (__stdcall *AILOpen3DProvider_guess)(int provider_guess);
typedef int (__stdcall *AILOpen3DListener_guess)(int provider_guess);
typedef void (__stdcall *AILSet3DSpeakerType_guess)(int provider_guess,
    int speaker_guess);

#define g_AIL_startup_guess EQ_GLOBAL(AILStartup_guess, 0x0063F360)
#define g_AIL_open_XMIDI_driver_guess EQ_GLOBAL(AILOpenXMIDIDriver_guess, 0x0063F364)
#define g_AIL_open_digital_driver_guess EQ_GLOBAL(AILOpenDigitalDriver_guess, 0x0063F368)
#define g_AIL_enumerate_3D_providers_guess EQ_GLOBAL(AILEnumerate3DProviders_guess, 0x0063F36C)
#define g_AIL_open_3D_provider_guess EQ_GLOBAL(AILOpen3DProvider_guess, 0x0063F370)
#define g_AIL_open_3D_listener_guess EQ_GLOBAL(AILOpen3DListener_guess, 0x0063F374)
#define g_AIL_set_3D_speaker_type_guess EQ_GLOBAL(AILSet3DSpeakerType_guess, 0x0063F378)

struct SoundManager_guess {
    float value00_guess; // 0x0
    float value04_guess; // 0x4
    float value08_guess; // 0x8
    float value0C_guess; // 0xC
    int xmidiDriver_guess; // 0x10
    int digitalDriver_guess; // 0x14
    int provider_guess; // 0x18
    int listener_guess; // 0x1C
    int value20_guess; // 0x20
    int value24_guess; // 0x24
    int value28_guess; // 0x28
    int value2C_guess; // 0x2C
    int value30_guess[6]; // 0x30
    int value48_guess[6]; // 0x48
    int value60_guess[6]; // 0x60
    int value78_guess[6]; // 0x78
    MusicInstance_guess* sequence_guess; // 0x90
    int value94_guess; // 0x94
    int speakerType_guess; // 0x98
    int value9C_guess; // 0x9C
    int valueA0_guess; // 0xA0
    float valueA4_guess; // 0xA4
    int valueA8_guess; // 0xA8
    char valueAC_guess; // 0xAC

    void AddInstances_guess(int type_guess, int index_guess,
        int count_guess);
    Node_guess* TakeFreeInstance_guess(int type_guess, int index_guess);
    SoundManager_guess* SoundDevice_guess(int spatialCount_guess,
        int digitalCount_guess, const char* xmidiConfig_guess,
        int rate_guess, int bits_guess, char positional_guess,
        int speakerType_guess);
};

typedef void (__stdcall *AILDLSUnload_guess)(int file_guess, int bank_guess);
typedef void (__stdcall *AILDLSClose_guess)(int file_guess, int value_guess);
typedef void (__stdcall *AILCloseXMIDI_guess)(int driver_guess);
typedef void (__stdcall *AILClose3D_guess)(int handle_guess);
typedef void (__stdcall *AILShutdown_guess)();

#define g_AIL_DLS_unload_guess EQ_GLOBAL(AILDLSUnload_guess, 0x0063F38C)
#define g_AIL_DLS_close_guess EQ_GLOBAL(AILDLSClose_guess, 0x0063F390)
#define g_AIL_close_XMIDI_guess EQ_GLOBAL(AILCloseXMIDI_guess, 0x0063F394)
#define g_AIL_close_listener_guess EQ_GLOBAL(AILClose3D_guess, 0x0063F398)
#define g_AIL_close_provider_guess EQ_GLOBAL(AILClose3D_guess, 0x0063F39C)
#define g_AIL_close_digital_guess EQ_GLOBAL(AILClose3D_guess, 0x0063F3A0)
#define g_AIL_shutdown_guess EQ_GLOBAL(AILShutdown_guess, 0x0063F3A4)

struct AudioShutdown_guess {
    char padding00_guess[0x10];
    int xmidiDriver_guess; // 0x10
    int digitalDriver_guess; // 0x14
    int provider_guess; // 0x18
    int listener_guess; // 0x1C
    int dlsFile_guess; // 0x20
    int dlsBank_guess; // 0x24
    void* allocation_guess; // 0x28
    char padding2C_guess[4];
    Node_guess* lists_guess[18]; // 0x30, with unused slots at 0x48..0x5C
    char padding78_guess[0x90 - 0x78];
    Node_guess* pending_guess; // 0x90
    char padding94_guess[8];
    ManagerQueue_guess* queues_guess; // 0x9C

    void Shutdown_guess();
};

// EXTERNAL: TITANIUM 0x0060D0D5 free
void __cdecl free(void* memory_guess);

extern "C" unsigned int __cdecl strlen(const char* string_guess);

extern "C" int __cdecl rand(void);

// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
void* __cdecl operator new(unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
void* __cdecl operator new[](unsigned int size_guess);

// EXTERNAL: TITANIUM 0x0060E450 CopyText_guess
void __cdecl CopyText_guess(char* destination_guess, const char* source_guess);
// EXTERNAL: TITANIUM 0x00621E9C __stricmp
int __cdecl __stricmp(const char* first_guess, const char* second_guess);

// EXTERNAL: TITANIUM 0x0046D655 FUN_0046d655
unsigned int __cdecl FUN_0046d655();

struct FileMarker_guess {
    int value_guess; // 0x0
    ~FileMarker_guess() { value_guess = 0; }
};

struct FilePrefix_guess {
    int value00_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8

    FilePrefix_guess()
    {
        value04_guess = 0;
        value00_guess = 0;
        value08_guess = 0;
    }
};

struct FileLoader_guess : FilePrefix_guess {
    char value0C_guess; // 0xC
    FileMarker_guess marker_guess; // 0x10

    // EXTERNAL: TITANIUM 0x004C4228 FileLoader_guess::Load_guess
    void Load_guess(char* name_guess);

    FileLoader_guess(char* name_guess);
};

// File reader: +0xC set, then `name` loaded (0x004C4228) when given; the driver check reads
// RecommendedDrivers.txt with it.
// FUNCTION: TITANIUM 0x004C42BB
FileLoader_guess::FileLoader_guess(char* name_guess)
    : value0C_guess(1)
{
    if (name_guess != 0) {
        Load_guess(name_guess);
    }
}

// Stores the flag (+4), then calls virtual slot 25 of the display (0x0099E364) with 1 when the flag is
// set and 0x00609D70 agrees, else with 0.
// FUNCTION: TITANIUM 0x004C42FB
void ValueSetter_guess::SetValue_guess(char value_guess)
{
    value04_guess = value_guess;
    if ((Check_guess() != 0) && (value_guess != 0)) {
        g_callbackInterface_guess->Slot25_guess(1);
    } else {
        g_callbackInterface_guess->Slot25_guess(0);
    }
}

struct FrameState_guess {
    char padding00_guess[0xEC];
    int width_guess;  // 0xEC
    int height_guess; // 0xF0
};

struct FrameDisplay_guess {
    // EXTERNAL: TITANIUM 0x00437BCD FrameDisplay_guess::Refresh_guess
    void Refresh_guess();
    // EXTERNAL: TITANIUM 0x00439212 FrameDisplay_guess::ApplyVideoMode_guess
    void ApplyVideoMode_guess();
    // EXTERNAL: TITANIUM 0x0043BA81 FrameDisplay_guess::ActivateMainUI_guess
    void ActivateMainUI_guess(bool changed_guess);
};

#define g_frameDisplay_guess EQ_GLOBAL(FrameDisplay_guess*, 0x00905D24)
#define pinstCXWndManager_guess EQ_GLOBAL(FrameState_guess*, 0x0099D3EC)

#define g_frameWidth_guess EQ_GLOBAL(int, 0x0092379C)
#define g_frameHeight_guess EQ_GLOBAL(int, 0x009237A0)

// EXTERNAL: TITANIUM 0x0046C627 LoadViewportRect_guess
void __cdecl LoadViewportRect_guess();

struct FrameOwner_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual float Slot02_guess(); // 0x8
    virtual void Slot03_guess();
    virtual void Slot04_guess();

    // EXTERNAL: TITANIUM 0x00609E20 FrameOwner_guess::Finish_guess
    void Finish_guess();

    void Update_guess(int width_guess, int height_guess);
};

// Applies the render size `width_guess` x `height_guess`; the display is refreshed only when it changed.
// FUNCTION: TITANIUM 0x004C4325
void FrameOwner_guess::Update_guess(int width_guess, int height_guess)
{
    bool changed_guess = false;
    if (g_frameWidth_guess != width_guess || g_frameHeight_guess != height_guess) {
        g_frameDisplay_guess->Refresh_guess();
        g_frameWidth_guess = width_guess;
        g_frameHeight_guess = height_guess;
        pinstCXWndManager_guess->width_guess = width_guess;
        pinstCXWndManager_guess->height_guess = height_guess;
        changed_guess = true;
    }
    LoadViewportRect_guess();
    if (pinstCVideoModesWnd_guess != 0) {
        pinstCVideoModesWnd_guess->OnModeChanged_guess();
    }
    g_frameDisplay_guess->ApplyVideoMode_guess();
    float aspect_guess = Slot02_guess();
    g_callbackInterface_guess->Slot27_guess(aspect_guess * 0.1f + 0.5f);
    g_frameDisplay_guess->ActivateMainUI_guess(changed_guess);
    Finish_guess();
}

// Returns the global at 0x00923D74.
// FUNCTION: TITANIUM 0x004C43F2
int __cdecl GetLanguage_guess()
{
    return g_value_guess;
}

// Reads the DirectInput keyboard (0x988C80); scan code 1 is DIK_ESCAPE. Only while EQ has the focus.
// FUNCTION: TITANIUM 0x004C43FE
char __cdecl IsEscapeKeyDown_guess()
{
    char state_guess[256];
    void* foreground_guess = g_getForegroundWindow_guess();
    if (foreground_guess != 0 && foreground_guess == g_foregroundWindow_guess) {
        InputDevice_guess* device_guess = g_inputDevice_guess;
        if (device_guess->vtable_guess->getState_guess(device_guess, 0x100,
                state_guess) == 0
            && (state_guess[1] & 0x80) != 0) {
            return 1;
        }
    }
    return 0;
}

// One slide-show frame (a view of SlideShow_guess: +0 start time, +4 events, +0xC playing). Runs the image
// (kind 0), text (2), then audio (1) events at the time since the start, presents when an image or text drew
// and stops playing when no event did. Escape stops the sounds and ends the show.
// FUNCTION: TITANIUM 0x004C4AF0
char CallbackListState_guess::Update_guess()
{
    int delta_guess;
    if (FUN_0046d655() < boundary_guess) {
        delta_guess = FUN_0046d655() - boundary_guess - 1;
    } else {
        delta_guess = FUN_0046d655() - boundary_guess;
    }

    char result_guess = 0;
    char handled_guess = 0;
    CallbackListNode_guess* node_guess = first_guess;
    while (node_guess != 0) {
        if (node_guess->kind_guess == 0
            && node_guess->Process_guess(delta_guess) != 0) {
            result_guess = 1;
            handled_guess = 1;
        }
        node_guess = node_guess->next_guess;
    }
    node_guess = first_guess;
    while (node_guess != 0) {
        if (node_guess->kind_guess == 2
            && node_guess->Process_guess(delta_guess) != 0) {
            result_guess = 1;
            handled_guess = 1;
        }
        node_guess = node_guess->next_guess;
    }
    node_guess = first_guess;
    while (node_guess != 0) {
        if (node_guess->kind_guess == 1
            && node_guess->Process_guess(delta_guess) != 0) {
            result_guess = 1;
        }
        node_guess = node_guess->next_guess;
    }

    if (result_guess != 0) {
        if (handled_guess != 0) {
            g_callbackInterface_guess->Slot37_guess();
        }
    } else {
        active_guess = 0;
    }
    g_updateManager_guess->Update_guess();

    if (IsEscapeKeyDown_guess() != 0) {
        result_guess = 0;
        active_guess = 0;
        node_guess = first_guess;
        while (node_guess != 0) {
            if (node_guess->kind_guess == 1) {
                node_guess->Process_guess(-1);
            }
            node_guess = node_guess->next_guess;
        }
        g_callbackInterface_guess->Slot35_guess();
        g_callbackInterface_guess->Slot37_guess();
        g_callbackInterface_guess->Slot35_guess();
    }
    return result_guess;
}

// Slide-show audio event at time `value_guess`: inside its window it starts the sound once (+0x30 is never
// reset, so it does not replay); outside it stops the sound, every frame.
// FUNCTION: TITANIUM 0x004C4455
char RangeObject_guess::Process_guess(unsigned int value_guess)
{
    if (active_guess != 0 && callback_guess != 0) {
        if (value_guess >= start_guess
            && value_guess <= start_guess + length_guess) {
            if (entered_guess == 0) {
                callback_guess->Slot04_guess(0);
                entered_guess = 1;
            }
            return 1;
        }
        callback_guess->Slot08_guess();
    }
    return 0;
}

// Slide-show text event: the text at (x, y) over a black shadow one pixel down-right, alpha fading in over
// +0x1C ms and out over +0x20 ms. Positions are for 1024x768, centred when 0x923780 (width) is above 1024.
// FUNCTION: TITANIUM 0x004C449A
// @early-stop: tiebreak, structural ndiff=19
char FadeSprite_guess::Process_guess(unsigned int value_guess)
{
    if (value_guess < start_guess || value_guess > start_guess + length_guess
        || shadow_guess == 0) {
        return 0;
    }
    unsigned int offset_guess = value_guess - start_guess;
    ColorValue_guess* colour_guess = (ColorValue_guess*)&value_guess;
    value_guess = color_guess.value_guess;
    if (offset_guess < fadeIn_guess) {
        colour_guess->bytes_guess[3] = (unsigned char)((float)color_guess.bytes_guess[3]
            / (float)fadeIn_guess * (float)offset_guess);
    } else if (offset_guess > length_guess - fadeOut_guess) {
        colour_guess->bytes_guess[3] = color_guess.bytes_guess[3]
            - (unsigned char)((float)(fadeOut_guess - length_guess + offset_guess)
                * ((float)color_guess.bytes_guess[3] / (float)fadeOut_guess));
    }
    int left_guess = x_guess;
    int top_guess = y_guess;
    if (g_screenMode_guess > 0x400) {
        left_guess += (g_screenWidth_guess - 0x400) / 2;
        top_guess += (g_screenHeight_guess - 0x300) / 2;
    }
    int rect_guess[4];
    rect_guess[3] = 0x400;
    rect_guess[0] = left_guess;
    rect_guess[1] = top_guess;
    rect_guess[2] = 0x300;
    shadow_guess->Slot00_guess(handle_guess);
    int width_guess = 0x400 - left_guess;
    shadow_guess->Slot02_guess(6, left_guess + 1, top_guess + 1, width_guess,
        rect_guess, value_guess & 0xff000000, 1, 0);
    image_guess->Slot00_guess(handle_guess);
    image_guess->Slot02_guess(6, left_guess, top_guess, width_guess,
        rect_guess, value_guess, 1, 0);
    g_callbackInterface_guess->Slot30_guess((int)shadow_guess);
    g_callbackInterface_guess->Slot30_guess((int)image_guess);
    return 1;
}

// Links this event in after `item_guess`.
// FUNCTION: TITANIUM 0x004C462B
void LinkPart_guess::Attach_guess(LinkOwner_guess* item_guess)
{
    next_guess = item_guess;
    if (item_guess != 0) {
        previous_guess = item_guess->previous_guess;
        LinkOwner_guess* owner_guess = static_cast<LinkOwner_guess*>(this);
        item_guess->previous_guess = owner_guess;
        if (previous_guess != 0) {
            previous_guess->next_guess = owner_guess;
        }
    }
}

// Slide-show event base: kind (0 image, 1 audio, 2 text) at +0x10, then start, length, fade-in and fade-out
// in ms (+0x14 to +0x20).
// FUNCTION: TITANIUM 0x004C464E
SlideShowEvent_guess::SlideShowEvent_guess(int first_guess, int second_guess,
    int third_guess, int fourth_guess, int fifth_guess)
{
    value04_guess = 0;
    value08_guess = 0;
    value0C_guess = 0;
    value10_guess = first_guess;
    value14_guess = second_guess;
    value18_guess = third_guess;
    value1C_guess = fourth_guess;
    vtable_guess = &g_callbackVtable_guess;
    value20_guess = fifth_guess;
}

// Slide-show event base destructor: restores the base vtable (0x0064C004).
// FUNCTION: TITANIUM 0x004C4686
SlideShowEvent_guess::~SlideShowEvent_guess()
{
    vtable_guess = &g_callbackVtable_guess;
}

// Scalar deleting destructor of a slide-show event (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C468D
void* SlideShowEvent_guess::Delete_guess(unsigned char flags_guess)
{
    this->~SlideShowEvent_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// EXTERNAL: TITANIUM 0x0064C004 ??_7CallbackChildBase_guess@@6B@
struct CallbackChildBase_guess {
    virtual ~CallbackChildBase_guess() { }
    // EXTERNAL: TITANIUM 0x004C464E CallbackChildBase_guess::CallbackChildBase_guess
    CallbackChildBase_guess(int first_guess, int second_guess, int third_guess,
        int fourth_guess, int fifth_guess);
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    int value10_guess; // 0x10
    int value14_guess; // 0x14
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C
    int value20_guess; // 0x20
};

// EXTERNAL: TITANIUM 0x0064C04C ??_7SlideShowEventImage_guess@@6B@
struct SlideShowEventImage_guess : CallbackChildBase_guess {
    char* buffer_guess; // 0x24
    int handle_guess; // 0x28

    SlideShowEventImage_guess(const char* name_guess, int first_guess,
        int second_guess, int third_guess, int fourth_guess);
    virtual ~SlideShowEventImage_guess();
    void* Delete_guess(unsigned char flags_guess);
};

// EXTERNAL: TITANIUM 0x0064C060 ??_7SlideShowEventAudio_guess@@6B@
struct SlideShowEventAudio_guess : CallbackChildBase_guess {
    void* allocation_guess; // 0x24
    Node_guess* firstNode_guess; // 0x28
    Node_guess* secondNode_guess; // 0x2C
    unsigned char flag_guess; // 0x30

    SlideShowEventAudio_guess(const char* name_guess, int first_guess, int second_guess,
        int third_guess, int fourth_guess);

    virtual ~SlideShowEventAudio_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct Size_guess {
    int width_guess;
    int height_guess;
};

// EXTERNAL: TITANIUM 0x0064C074 ??_7SlideShowEventText_guess@@6B@
struct SlideShowEventText_guess : CallbackChildBase_guess {
    char* buffer_guess; // 0x24
    int width_guess; // 0x28
    int height_guess; // 0x2C
    unsigned int color_guess; // 0x30
    int firstHandle_guess; // 0x34
    int secondHandle_guess; // 0x38

    SlideShowEventText_guess(const char* name_guess, Size_guess size_guess,
        unsigned int color_guess, int duration_guess, int start_guess,
        int end_guess, int value_guess);

    virtual ~SlideShowEventText_guess();
    void* Delete_guess(unsigned char flags_guess);
};

struct SlideShowMode_guess {
    int value00_guess;
    int audioEnabled_guess; // 0x4
};

#define g_slideShowMode_guess EQ_GLOBAL(SlideShowMode_guess*, 0x00851390)

struct TextFileReader_guess {
    void* stream_guess; // 0x0
    char buffer_guess[0x10000]; // 0x4
    char* cursor_guess; // 0x10004
    int value10008_guess; // 0x10008

    // EXTERNAL: TITANIUM 0x00576BD0 TextFileReader_guess::TextFileReader_guess
    TextFileReader_guess(char* name_guess, int kind_guess);
    // EXTERNAL: TITANIUM 0x00576D10 TextFileReader_guess::IsOpen_guess
    char IsOpen_guess();
    // EXTERNAL: TITANIUM 0x00576C60 TextFileReader_guess::GetCount_guess
    int GetCount_guess();
    // EXTERNAL: TITANIUM 0x00576F80 TextFileReader_guess::ReadInteger_guess
    int ReadInteger_guess();
    // EXTERNAL: TITANIUM 0x00576F50 TextFileReader_guess::ReadString_guess
    void ReadString_guess(char* buffer_guess, int size_guess);
    // EXTERNAL: TITANIUM 0x00576C50 TextFileReader_guess::Close_guess
    void Close_guess();
};

// EXTERNAL: TITANIUM 0x0060E590 FindToken_guess
int __cdecl FindToken_guess(const char* input_guess, const char* token_guess);

struct SlideShow_guess {
    int current_guess; // 0x0
    LinkList_guess items_guess; // 0x4
    char flag_guess; // 0xC

    SlideShow_guess(char* name_guess);
};

struct RenderResources_guess {
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
    virtual int Slot13_guess();
    virtual void Slot14_guess(int value_guess); // 0x38
    virtual void Slot15_guess();
    virtual void Slot16_guess();
    virtual int Slot17_guess(char* first_guess, char* second_guess,
        int third_guess, int fourth_guess); // 0x44
    virtual void Slot18_guess();
    virtual void Slot19_guess();
    virtual void Slot20_guess();
    virtual void Slot21_guess();
    virtual void Slot22_guess(int value_guess); // 0x58
};

#define g_renderResources_guess EQ_GLOBAL(RenderResources_guess*, 0x0099E360)

// EXTERNAL: TITANIUM 0x0060D682 FreeBuffer_guess
void __cdecl FreeBuffer_guess(void* memory_guess);

// EXTERNAL: TITANIUM 0x00574110 LogFailure_guess
void __cdecl LogFailure_guess(const char* message_guess, char* name_guess);

// Slide-show image event (its log text says CSlidShowEventImage): loads the image through the graphics DLL
// interface at 0x99E360. Not audio code, despite this file's name.
// FUNCTION: TITANIUM 0x004C46A9
SlideShowEventImage_guess::SlideShowEventImage_guess(const char* name_guess, int first_guess,
    int second_guess, int third_guess, int fourth_guess)
    : CallbackChildBase_guess(0, first_guess, second_guess, third_guess,
        fourth_guess)
{
    unsigned int length_guess = strlen(name_guess);
    buffer_guess = new char[length_guess + 1];
    CopyText_guess(buffer_guess, name_guess);
    handle_guess = g_renderResources_guess->Slot17_guess(buffer_guess,
        buffer_guess, 0, 1);
    if (handle_guess == 0) {
        LogFailure_guess("Failed to load image %s in CSlidShowEventImage().",
            buffer_guess);
    }
}

// Slide-show image destructor: releases the texture (0x0099E360, virtual slot 22) and frees the image
// buffer.
// FUNCTION: TITANIUM 0x004C4730
SlideShowEventImage_guess::~SlideShowEventImage_guess()
{
    g_renderResources_guess->Slot22_guess(handle_guess);
    FreeBuffer_guess(buffer_guess);
}

struct Color_guess {
    unsigned char blue_guess;  // 0x0
    unsigned char green_guess; // 0x1
    unsigned char red_guess;   // 0x2
    unsigned char alpha_guess; // 0x3
};

struct FadeRange_guess {
    char padding00_guess[0x14];
    unsigned int start_guess;   // 0x14
    int length_guess;           // 0x18
    unsigned int fadeIn_guess;  // 0x1C
    unsigned int fadeOut_guess; // 0x20
    char padding24_guess[0x28 - 0x24];
    int handle_guess;           // 0x28

    char Process_guess(unsigned int value_guess);
};

struct RenderDevice_guess {
    virtual void Slot00_guess(); virtual void Slot01_guess();
    virtual void Slot02_guess(); virtual void Slot03_guess();
    virtual void Slot04_guess(); virtual void Slot05_guess();
    virtual void Slot06_guess(); virtual void Slot07_guess();
    virtual void Slot08_guess(); virtual void Slot09_guess();
    virtual void Slot10_guess(); virtual void Slot11_guess();
    virtual void Slot12_guess(); virtual void Slot13_guess();
    virtual void Slot14_guess(); virtual char Slot15_guess();
    virtual void Slot16_guess(); virtual void Slot17_guess();
    virtual void Slot18_guess(); virtual void Slot19_guess();
    virtual void Slot20_guess(); virtual void Slot21_guess();
    virtual void Slot22_guess(); virtual void Slot23_guess();
    virtual void Slot24_guess(); virtual void Slot25_guess();
    virtual void Slot26_guess(); virtual void Slot27_guess();
    virtual void Slot28_guess(); virtual void Slot29_guess();
    virtual void Slot30_guess(); virtual void Slot31_guess();
    virtual void Slot32_guess(float* corners_guess, float* uv_guess,
        unsigned int color_guess, int handle_guess);
    virtual void Slot33_guess(); virtual void Slot34_guess();
    virtual void Slot35_guess();
};

#define g_renderDevice_guess EQ_GLOBAL(RenderDevice_guess*, 0x0099E364)
#define g_quadWidth_guess EQ_GLOBAL(int, 0x0092379C)
#define g_quadHeight_guess EQ_GLOBAL(int, 0x009237A0)
#define g_fadeScale_guess EQ_GLOBAL(float, 0x00642B28)
#define g_fadeTexCoord_guess EQ_GLOBAL(float, 0x00641F98)

// Image event: a full-screen quad, white with alpha fading in and out (0-255). When the renderer asks
// (slot 15) v stops at 0.75, probably a 1024x768 picture in a 1024x1024 texture.
// FUNCTION: TITANIUM 0x004C4775
char FadeRange_guess::Process_guess(unsigned int value_guess)
{
    // Inside the range, with a texture: draw a fading quad.
    if (value_guess >= start_guess
        && value_guess <= start_guess + length_guess
        && handle_guess != 0) {
        unsigned int rel_guess = value_guess - start_guess;
        Color_guess* color_guess = (Color_guess*)&value_guess;
        color_guess->red_guess = 0xff;
        color_guess->green_guess = 0xff;
        color_guess->blue_guess = 0xff;
        color_guess->alpha_guess = 0xff;
        if (rel_guess < fadeIn_guess) {
            color_guess->alpha_guess = (char)((float)rel_guess
                * (g_fadeScale_guess / (float)fadeIn_guess));
        } else if (rel_guess > (unsigned int)(length_guess - fadeOut_guess)) {
            unsigned int tail_guess = fadeOut_guess - length_guess + rel_guess;
            char fade_guess = (char)((float)tail_guess
                * (g_fadeScale_guess / (float)fadeOut_guess));
            color_guess->alpha_guess = (char)(-1 - fade_guess);
        }

        RenderDevice_guess* device_guess = g_renderDevice_guess;
        float corners_guess[4][3];
        corners_guess[0][0] = 0;
        corners_guess[0][1] = 0;
        corners_guess[0][2] = 0;
        corners_guess[1][1] = 0;
        corners_guess[1][2] = 0;
        float width_guess = (float)g_quadWidth_guess;
        corners_guess[1][0] = width_guess;
        corners_guess[2][0] = width_guess;
        corners_guess[2][2] = 0;
        float height_guess = (float)g_quadHeight_guess;
        corners_guess[2][1] = height_guess;
        corners_guess[3][1] = height_guess;
        corners_guess[3][2] = 0;
        corners_guess[3][0] = width_guess - (float)g_quadWidth_guess;

        char flag_guess = device_guess->Slot15_guess();
        float uv_guess[4][2];
        uv_guess[0][0] = 0;
        uv_guess[0][1] = 0;
        uv_guess[1][0] = 1;
        uv_guess[1][1] = 0;
        uv_guess[2][0] = 1;
        if (flag_guess != 0) {
            uv_guess[2][1] = g_fadeTexCoord_guess;
            uv_guess[3][0] = 0;
            uv_guess[3][1] = g_fadeTexCoord_guess;
        } else {
            uv_guess[2][1] = 1;
            uv_guess[3][0] = 0;
            uv_guess[3][1] = 1;
        }

        int count_guess = 2;
        // The quad is drawn twice per frame; that is the original.
        do {
            g_renderDevice_guess->Slot35_guess();
            g_renderDevice_guess->Slot32_guess(&corners_guess[0][0],
                &uv_guess[0][0], value_guess, handle_guess);
        } while (--count_guess != 0);
        return 1;
    }
    return 0;
}

// Audio event dtor: releases the instance (+0x2C) and the asset (+0x28).
// FUNCTION: TITANIUM 0x004C49CB
SlideShowEventAudio_guess::~SlideShowEventAudio_guess()
{
    secondNode_guess->Finish_guess();
    firstNode_guess->Finish_guess();
    FreeBuffer_guess(allocation_guess);
}

// Slide-show text event: the text, position (+0x28, +0x2C), colour, and two text objects from the graphics
// DLL, the shadow and the text.
// FUNCTION: TITANIUM 0x004C4A12
// @early-stop: budget, diff ndiff=5
SlideShowEventText_guess::SlideShowEventText_guess(const char* name_guess,
    Size_guess position_guess, unsigned int color_guess, int duration_guess,
    int start_guess, int end_guess, int value_guess)
    : CallbackChildBase_guess(2, duration_guess, start_guess, end_guess,
        value_guess)
{
    width_guess = position_guess.width_guess;
    height_guess = position_guess.height_guess;
    this->color_guess = color_guess;
    size_t length_guess = strlen(name_guess);
    buffer_guess = new char[length_guess + 1];
    CopyText_guess(buffer_guess, name_guess);
    firstHandle_guess = g_renderResources_guess->Slot13_guess();
    secondHandle_guess = g_renderResources_guess->Slot13_guess();
}

// Slide-show "text" event (type 2): gives back its two handles (+0x34, +0x38, taken from slot 13 of
// 0x0099E360 in 0x004C4A12) and frees the text (+0x24).
// FUNCTION: TITANIUM 0x004C4A9D
SlideShowEventText_guess::~SlideShowEventText_guess()
{
    g_renderResources_guess->Slot14_guess(firstHandle_guess);
    g_renderResources_guess->Slot14_guess(secondHandle_guess);
    FreeBuffer_guess(buffer_guess);
}

// Appends `item` at the tail of the linked list and records the list as its owner.
// FUNCTION: TITANIUM 0x004C4C08
void LinkList_guess::Insert_guess(LinkOwner_guess* item_guess)
{
    if (last_guess != 0) {
        item_guess->Attach_guess(last_guess);
    } else {
        first_guess = item_guess;
    }
    last_guess = item_guess;
    item_guess->owner_guess = this;
}

// Scalar deleting destructor of a slide-show image event (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C4C2F
void* SlideShowEventImage_guess::Delete_guess(unsigned char flags_guess)
{
    this->SlideShowEventImage_guess::~SlideShowEventImage_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Scalar deleting destructor of a slide-show audio event (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C4C4B
void* SlideShowEventAudio_guess::Delete_guess(unsigned char flags_guess)
{
    this->SlideShowEventAudio_guess::~SlideShowEventAudio_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Scalar deleting destructor of a slide-show text event (flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C4C67
void* SlideShowEventText_guess::Delete_guess(unsigned char flags_guess)
{
    this->SlideShowEventText_guess::~SlideShowEventText_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Loads a slide-show script, one event per line, fields split by '^' (0x5E): start (s); image, audio or
// text; the file, or for text the string, x, y and r, g, b; then length, fade-in and fade-out (s).
// Seconds become ms. Audio lines are skipped without a sound manager (0x851390 +4). The locals are
// mislabelled: `duration_guess` is the start, `text_guess` the file and `image_guess` the text.
// FUNCTION: TITANIUM 0x004C4C83
// @early-stop: budget, structural ndiff=141
SlideShow_guess::SlideShow_guess(char* name_guess)
    : current_guess(-1), items_guess(), flag_guess(0)
{
    int zero_guess = 0;
    char line_guess[0x20];
    char text_guess[0x100];
    char image_guess[0x100];
    TextFileReader_guess* file_guess =
        new TextFileReader_guess(name_guess, 0x5e);

    if (file_guess->IsOpen_guess() == zero_guess) {
        LogFailure_guess("CSlideShow() Bad filename: %s", name_guess);
    } else {
        for (;;) {
            int count_guess = file_guess->GetCount_guess();
            if (count_guess <= zero_guess) {
                if (count_guess == -1) {
                    break;
                }
                continue;
            }

            int duration_guess = file_guess->ReadInteger_guess() * 1000;
            file_guess->ReadString_guess(line_guess, 0x20);
            int type_guess = 0x7fffffff;
            if (FindToken_guess(line_guess, "image") != 0) {
                type_guess = 0;
            } else if (FindToken_guess(line_guess, "audio") != 0) {
                type_guess = 1;
            } else if (FindToken_guess(line_guess, "text") != 0) {
                type_guess = 2;
            }

            text_guess[0] = 0;
            image_guess[0] = 0;
            Size_guess size_guess;
            size_guess.width_guess = zero_guess;
            size_guess.height_guess = zero_guess;
            Color_guess color_guess = { 0, 0, 0, 0xff };
            if (type_guess >= zero_guess) {
                if (type_guess <= 1) {
                    file_guess->ReadString_guess(text_guess, 0x100);
                } else if (type_guess == 2) {
                    file_guess->ReadString_guess(image_guess, 0x100);
                    size_guess.width_guess = file_guess->ReadInteger_guess();
                    size_guess.height_guess = file_guess->ReadInteger_guess();
                    color_guess.red_guess = (unsigned char)
                        file_guess->ReadInteger_guess();
                    color_guess.green_guess = (unsigned char)
                        file_guess->ReadInteger_guess();
                    color_guess.blue_guess = (unsigned char)
                        file_guess->ReadInteger_guess();
                }
            }

            int start_guess = file_guess->ReadInteger_guess() * 1000;
            int end_guess = file_guess->ReadInteger_guess() * 1000;
            int value_guess = file_guess->ReadInteger_guess() * 1000;
            LinkOwner_guess* item_guess = 0;
            if (type_guess == zero_guess) {
                item_guess = (LinkOwner_guess*)new SlideShowEventImage_guess(
                    text_guess, duration_guess, start_guess, end_guess,
                    value_guess);
            } else if (type_guess == 1) {
                if (g_slideShowMode_guess->audioEnabled_guess == zero_guess) {
                    continue;
                }
                item_guess = (LinkOwner_guess*)new SlideShowEventAudio_guess(
                    text_guess, duration_guess, start_guess, end_guess,
                    value_guess);
            } else if (type_guess == 2) {
                item_guess = (LinkOwner_guess*)new SlideShowEventText_guess(
                    image_guess, size_guess, *(unsigned int*)&color_guess,
                    duration_guess, start_guess, end_guess, value_guess);
            } else {
                continue;
            }
            items_guess.Insert_guess(item_guess);
        }
    }

    if (file_guess != 0) {
        file_guess->Close_guess();
        delete file_guess;
    }
}

// 10^(level/2000): hundredths of a decibel (the DirectSound scale) to linear gain; -10000 and below is
// silence, anything above 0 is 1.
// FUNCTION: TITANIUM 0x004C4FA1
float __cdecl LevelToGain_guess(int level_guess)
{
    if (level_guess < -10000) {
        return 0.0f;
    }
    if (level_guess > 0) {
        return 1.0f;
    }
    return (float)pow(10.0, (double)level_guess * 0.0005);
}

// Copy of `source` in a new buffer (operator new, strlen + 1 bytes).
// FUNCTION: TITANIUM 0x004C4FE3
void* __cdecl DuplicateString_guess(const char* source_guess)
{
    unsigned int length_guess = strlen(source_guess);
    char* result_guess = (char*)operator new(length_guess + 1);
    CopyText_guess(result_guess, source_guess);
    return result_guess;
}

// Miles preference 42 (AIL_set_preference), clamped to 4-96, then AIL_serve.
// FUNCTION: TITANIUM 0x004C5007
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))
void AudioPreference_guess::SetValue_guess(int value_guess)
{
    value_guess = min(0x60, max(4, value_guess));
    g_AILSetPreference_guess(0x2a, value_guess);
    g_AILServe_guess();
}
#undef min
#undef max

// Copies the listener position (+0, +4, +8) and +0xC to whichever outputs are non-null. The values are
// floats passed through int pointers; callers ask for x, y and z only.
// FUNCTION: TITANIUM 0x004C50EF
void FourValue_guess::GetListenerLocation_guess(int* first_guess, int* second_guess,
    int* third_guess, int* fourth_guess)
{
    if (first_guess != 0) {
        *first_guess = value00_guess;
    }
    if (second_guess != 0) {
        *second_guess = value04_guess;
    }
    if (third_guess != 0) {
        *third_guess = value08_guess;
    }
    if (fourth_guess != 0) {
        *fourth_guess = value0C_guess;
    }
}

// The room's environment preset (+0x94); the sound manager reads it.
// FUNCTION: TITANIUM 0x004C5033
int RoomAudio_guess::GetRoomType_guess()
{
    return roomType_guess;
}

// Miles 3D room type (the EAX environment) on the 3D provider (+0x18); remembered at +0x94.
// FUNCTION: TITANIUM 0x004C503A
void RoomAudio_guess::SetListenerEnvironment_guess(int roomType_guess)
{
    if (roomType_guess == this->roomType_guess) {
        return;
    }
    this->roomType_guess = roomType_guess;
    if (handle_guess != 0) {
        g_AILSet3DRoomType_guess(handle_guess, roomType_guess);
    }
}

typedef void (__stdcall *AIL3DPosition_guess)(int handle_guess, float x_guess,
    float y_guess, float z_guess);
typedef void (__stdcall *AIL3DOrientation_guess)(int handle_guess, float x_guess,
    float y_guess, float z_guess, float xUp_guess, float yUp_guess, float zUp_guess);
#define g_AIL_set_3D_position_guess EQ_GLOBAL(AIL3DPosition_guess, 0x0063F424)
#define g_AIL_set_3D_orientation_guess EQ_GLOBAL(AIL3DOrientation_guess, 0x0063F428)

// EXTERNAL: TITANIUM 0x0060F6D4 Angle1_guess
float __cdecl Angle1_guess(double angle_guess);
// EXTERNAL: TITANIUM 0x0060F784 Angle2_guess
float __cdecl Angle2_guess(double angle_guess);

struct Source3D_guess {
    float value00_guess; // 0x0
    float value04_guess; // 0x4
    float value08_guess; // 0x8
    float value0C_guess; // 0xC
    char padding10_guess[0x1C - 0x10];
    int handle_guess; // 0x1C

    void SetListenerLocation_guess(float x_guess, float y_guess, float z_guess, float angle_guess);
};

// Moves the 3D listener: position, and orientation facing `angle_guess` with up = -Z. The setter of
// GetListenerLocation_guess; Source3D_guess here is the listener, not a source.
// FUNCTION: TITANIUM 0x004C505C
void Source3D_guess::SetListenerLocation_guess(float x_guess, float y_guess, float z_guess,
    float angle_guess)
{
    value00_guess = x_guess;
    value04_guess = y_guess;
    value08_guess = z_guess;
    value0C_guess = angle_guess;
    if (handle_guess != 0) {
        g_AIL_set_3D_position_guess(handle_guess, x_guess, y_guess, z_guess);
        z_guess = Angle1_guess(angle_guess);
        g_AIL_set_3D_orientation_guess(handle_guess, z_guess, Angle2_guess(angle_guess),
            0.0f, 0.0f, 0.0f, -1.0f);
    }
}

// Adds an asset to the sound manager's list (+0x9C, count +0xA0).
// FUNCTION: TITANIUM 0x004C516E
void QueueHead_guess::Insert_guess(QueueLinkItem_guess* item_guess)
{
    item_guess->next_guess = first_guess;
    ++count_guess;
    first_guess = item_guess;
}

// Unlinks `item` from the singly linked queue (first at +0), clearing its next link and lowering the
// count. An item not in the queue is ignored.
// FUNCTION: TITANIUM 0x004C518D
void QueueHead_guess::Remove_guess(QueueLinkItem_guess* item_guess)
{
    QueueLinkItem_guess** link_guess = &first_guess;
    QueueLinkItem_guess* node_guess = *link_guess;
    while (node_guess != 0) {
        QueueLinkItem_guess* next_guess = node_guess->next_guess;
        if (node_guess == item_guess) {
            node_guess->next_guess = 0;
            *link_guess = next_guess;
            --count_guess;
            return;
        }
        link_guess = &node_guess->next_guess;
        node_guess = next_guess;
    }
}

// Closes the manager's MP3 stream (+0xA8).
// FUNCTION: TITANIUM 0x004C51C7
void AudioStreamObject_guess::Close_guess()
{
    if (stream_guess != 0) {
        g_AILCloseStream_guess(stream_guess);
        stream_guess = 0;
    }
}

// Sets the MP3 stream's volume (both channels) and remembers it.
// FUNCTION: TITANIUM 0x004C51E0
void AudioStream_guess::SetVolume_guess(float level_guess)
{
    volume_guess = level_guess;
    if (stream_guess != 0) {
        g_AIL_set_stream_volume_levels_guess(stream_guess, level_guess,
            level_guess);
    }
}

// Moves the MP3 stream to `position` ms.
// FUNCTION: TITANIUM 0x004C520F
void AudioStream_guess::SetPosition_guess(int position_guess)
{
    if (stream_guess != 0) {
        g_AILSetStreamMSPosition_guess(stream_guess, position_guess);
    }
}

// AIL_stream_ms_position fills (total, current): this returns the play position in ms (the typedef's
// parameter names are swapped).
// FUNCTION: TITANIUM 0x004C5227
int AudioStream_guess::GetStreamPosition_guess()
{
    int position_guess;
    int length_guess;
    if (stream_guess != 0) {
        g_AILStreamMSPosition_guess(stream_guess, &position_guess, &length_guess);
        return length_guess;
    }
    return 0;
}

// The track length in ms, not the position; see GetLength_guess.
// FUNCTION: TITANIUM 0x004C524E
int AudioStream_guess::GetStreamLength_guess()
{
    int position_guess;
    int length_guess;
    if (stream_guess != 0) {
        g_AILStreamMSPosition_guess(stream_guess, &position_guess, &length_guess);
        return position_guess;
    }
    return 0;
}

// Stream state: 0 done (SMP_DONE 2) or unknown, 1 playing (SMP_PLAYING 4), 2 paused (SMP_STOPPED 8).
// FUNCTION: TITANIUM 0x004C5275
int AudioStream_guess::GetStatus_guess()
{
    if (stream_guess != 0) {
        switch (g_AILStreamStatus_guess(stream_guess)) {
        case 2:
            return 0;
        case 4:
            return 1;
        case 8:
            return 2;
        default:
            break;
        }
    }
    return 0;
}

// Drops a reference (+4); the last one deletes the object (vtable slot 0, flag 1).
// FUNCTION: TITANIUM 0x004C529E
void Node_guess::Finish_guess()
{
    --value04_guess;
    if (value04_guess == 0) {
        Slot00_guess(1);
    }
}

// Sound instance base: one reference, owner sound manager +8, asset +0xC, pool index +0x10, next +0x14.
// FUNCTION: TITANIUM 0x004C52AA
SoundInstance_guess::SoundInstance_guess(int argument)
{
    SoundInstance_guess* self_guess = this;
    self_guess->argument_guess = argument;
    self_guess->state_guess = 1;
    self_guess->table_guess = &g_table_guess;
    self_guess->valueC_guess = 0;
    self_guess->value10_guess = 0;
    self_guess->value14_guess = 0;
}

// Sound object base destructor body: back to the base vtable 0x64C0CC.
// FUNCTION: TITANIUM 0x004C52CE
void VtableObject_guess::SetVtable_guess()
{
    vtable_guess = &g_nodeVtable_guess;
}

// Points the instance at another asset (+0xC), stopping it first (vtable +0x20, probably Stop).
// FUNCTION: TITANIUM 0x004C52DF
void AudioValueNotifier_guess::SetAsset_guess(int value_guess)
{
    if (value0C_guess != value_guess) {
        Notify_guess();
        value0C_guess = value_guess;
    }
}

struct SourceObject_guess {
    char padding00_guess[0x14];
    int handle14_guess; // 0x14
};

struct WaveInstance2D_guess : SoundInstance_guess {
    int handle_guess; // 0x18
    float targetVolume_guess; // 0x1C
    float currentVolume_guess; // 0x20
    float startVolume_guess; // 0x24
    int startTick_guess; // 0x28
    int duration_guess; // 0x2C

    WaveInstance2D_guess(int argument_guess);
    void SetVolume_guess(float volume_guess, int newDuration_guess);
};

typedef int (__stdcall *AILAllocateSampleHandle_guess)(int handle_guess);
#define g_AIL_allocate_sample_handle_guess EQ_GLOBAL(AILAllocateSampleHandle_guess, 0x0063F40C)

// 2D wave instance: a sample handle from the owner's digital driver (+0x14), silent, no fade.
// FUNCTION: TITANIUM 0x004C52F9
WaveInstance2D_guess::WaveInstance2D_guess(int argument_guess)
    : SoundInstance_guess(argument_guess)
{
    value14_guess = 0;
    handle_guess = 0;
    table_guess = &g_sampleVtable_guess;
    SourceObject_guess* source_guess = (SourceObject_guess*)this->argument_guess;
    if (source_guess->handle14_guess != 0) {
        handle_guess = g_AIL_allocate_sample_handle_guess(source_guess->handle14_guess);
    }
    currentVolume_guess = 0.0f;
    targetVolume_guess = 0.0f;
    startVolume_guess = 0.0f;
    startTick_guess = (int)GetTickCount();
    duration_guess = 0;
}

// Starts a fade from the current volume to `volume_guess` over `newDuration_guess` ms (0 or less: at once);
// the per-frame step (0x4C541B) moves it. A zero duration always applies, even to the same volume.
// FUNCTION: TITANIUM 0x004C5368
void WaveInstance2D_guess::SetVolume_guess(float volume_guess, int newDuration_guess)
{
    if ((newDuration_guess == 0 || volume_guess != targetVolume_guess) && handle_guess != 0) {
        targetVolume_guess = volume_guess;
        startVolume_guess = currentVolume_guess;
        startTick_guess = (int)GetTickCount();
        duration_guess = newDuration_guess;
        if (newDuration_guess <= 0) {
            currentVolume_guess = targetVolume_guess;
        }
        g_AIL_set_sample_volume_levels_guess(handle_guess, currentVolume_guess,
            currentVolume_guess);
    }
}

// Blocking stop: ends and re-inits the 2D sample, then waits up to 3 s (0xBB8 ms, 1 ms sleeps)
// for SMP_DONE (2).
// FUNCTION: TITANIUM 0x004C53CA
void SampleObject_guess::StopAndWait_guess()
{
    if (handle_guess == 0) {
        return;
    }
    g_AIL_end_sample_guess(handle_guess);
    g_AIL_init_sample_guess(handle_guess);
    GetTickCountFunction_guess tick_guess = g_getTickCount_guess;
    unsigned long start_guess = tick_guess();
    AILSampleStatus_guess status_guess = g_AIL_sample_status_guess;
    while (status_guess(handle_guess) != 2) {
        if (tick_guess() - start_guess > 0xBB8) {
            break;
        }
        g_sleep_guess(1);
    }
}

// Per-frame step of a 2D wave (misplaced on WaveInstance3D_guess: it uses the 2D sample calls). While
// playing (SMP_PLAYING 4) moves the volume linearly to the target and stops the sample once it rests at 0.
// False when not playing, so the asset drops the instance.
// FUNCTION: TITANIUM 0x004C541B
char WaveInstance3D_guess::Update_guess()
{
    if (handle_guess != 0 && g_AIL_sample_status_guess(handle_guess) == 4) {
        if (targetVolume_guess != currentVolume_guess) {
            int tick_guess = (int)GetTickCount();
            int duration_guess = this->duration_guess;
            int startTick_guess = this->startTick_guess;
            if (tick_guess >= startTick_guess + duration_guess) {
                currentVolume_guess = targetVolume_guess;
            }
            else {
                int elapsed_guess = tick_guess - startTick_guess;
                float elapsedVolume_guess = (float)elapsed_guess;
                currentVolume_guess = elapsedVolume_guess *
                    (targetVolume_guess - startVolume_guess) / duration_guess +
                    startVolume_guess;
            }
            g_AIL_set_sample_volume_levels_guess(handle_guess,
                currentVolume_guess, currentVolume_guess);
        }
        else if (currentVolume_guess == 0.0f) {
            g_AIL_end_sample_guess(handle_guess);
            g_AIL_init_sample_guess(handle_guess);
        }
        return 1;
    }
    return 0;
}

// 3D wave instance: a 3D sample handle from the owner's 3D provider (+0x18), silent.
// FUNCTION: TITANIUM 0x004C54CA
WaveInstance3D_guess::WaveInstance3D_guess(SampleObject_guess* source_guess)
    : SoundInstance_guess((int)source_guess)
{
    value14_guess = 0;
    handle_guess = 0;
    table_guess = &g_3dSampleVtable_guess;
    source_guess = (SampleObject_guess*)this->argument_guess;
    if (source_guess->handle_guess != 0) {
        handle_guess = g_AIL_allocate_3D_sample_handle_guess(
            source_guess->handle_guess);
    }
    currentVolume_guess = 0.0f;
    targetVolume_guess = 0.0f;
    startVolume_guess = 0.0f;
    startTick_guess = (int)GetTickCount();
    duration_guess = 0;
}

// 2D wave dtor body: releases the sample handle.
// FUNCTION: TITANIUM 0x004C5349
void SampleObject_guess::Release_guess()
{
    int handle_guess = this->handle_guess;
    table_guess = &g_sampleVtable_guess;
    if (handle_guess != 0) {
        g_AIL_release_sample_guess(handle_guess);
    }
    table_guess = &g_nodeVtable_guess;
}

// 3D twin of StopAndWait_guess, a blocking stop; no re-init.
// FUNCTION: TITANIUM 0x004C5539
void SampleObject_guess::StopAndWait3D_guess()
{
    if (handle_guess == 0) {
        return;
    }
    g_AIL_end_3D_sample_guess(handle_guess);
    GetTickCountFunction_guess tick_guess = g_getTickCount_guess;
    unsigned long start_guess = tick_guess();
    AIL3DSampleStatus_guess status_guess = g_AIL_3D_sample_status_guess;
    while (status_guess(handle_guess) != 2) {
        if (tick_guess() - start_guess > 0xBB8) {
            break;
        }
        g_sleep_guess(1);
    }
}

// 3D wave dtor body: releases the 3D sample handle.
// FUNCTION: TITANIUM 0x004C551A
void SampleObject_guess::Release3D_guess()
{
    int handle_guess = this->handle_guess;
    table_guess = &g_3dSampleVtable_guess;
    if (handle_guess != 0) {
        g_AIL_release_3D_sample_guess(handle_guess);
    }
    table_guess = &g_nodeVtable_guess;
}

// Per-frame step of a 3D wave; the 3D twin of 0x4C541B.
// FUNCTION: TITANIUM 0x004C5581
char WaveInstance3D_guess::Update3D_guess()
{
    if (handle_guess != 0 && g_AIL_3D_sample_status_guess(handle_guess) == 4) {
        if (targetVolume_guess != currentVolume_guess) {
            int tick_guess = (int)GetTickCount();
            int duration_guess = this->duration_guess;
            int startTick_guess = this->startTick_guess;
            if (tick_guess >= startTick_guess + duration_guess) {
                currentVolume_guess = targetVolume_guess;
            }
            else {
                int elapsed_guess = tick_guess - startTick_guess;
                float elapsedVolume_guess = (float)elapsed_guess;
                currentVolume_guess = elapsedVolume_guess *
                    (targetVolume_guess - startVolume_guess) / duration_guess +
                    startVolume_guess;
            }
            g_AIL_set_3D_sample_volume_guess(handle_guess, currentVolume_guess);
        }
        else if (currentVolume_guess == 0.0f) {
            g_AIL_end_3D_sample_guess(handle_guess);
        }
        return 1;
    }
    return 0;
}

// 3D twin of the 2D fade setter 0x4C5368.
// FUNCTION: TITANIUM 0x004C561B
void WaveInstance3D_guess::SetVolume_guess(float volume_guess, int newDuration_guess)
{
    if ((newDuration_guess == 0 || volume_guess != targetVolume_guess) && handle_guess != 0) {
        targetVolume_guess = volume_guess;
        startVolume_guess = currentVolume_guess;
        startTick_guess = (int)GetTickCount();
        duration_guess = newDuration_guess;
        if (newDuration_guess <= 0) {
            currentVolume_guess = targetVolume_guess;
        }
        g_AIL_set_3D_sample_volume_guess(handle_guess, currentVolume_guess);
    }
}

typedef int (__stdcall *AIL3DSampleFile_guess)(int handle_guess, void* data_guess);
#define g_AIL_set_3D_sample_file_guess EQ_GLOBAL(AIL3DSampleFile_guess, 0x0063F3CC)
typedef void (__stdcall *AIL3DSampleDistances_guess)(int handle_guess, float max_guess,
    float min_guess);
#define g_AIL_set_3D_sample_distances_guess EQ_GLOBAL(AIL3DSampleDistances_guess, 0x0063F3D0)
typedef void (__stdcall *AIL3DSampleLoopCount_guess)(int handle_guess, int count_guess);
#define g_AIL_set_3D_sample_loop_count_guess EQ_GLOBAL(AIL3DSampleLoopCount_guess, 0x0063F3D4)
typedef void (__stdcall *AIL3DSampleEffects_guess)(int handle_guess, float level_guess);
#define g_AIL_set_3D_sample_effects_level_guess EQ_GLOBAL(AIL3DSampleEffects_guess, 0x0063F3D8)
typedef void (__stdcall *AIL3DVelocity_guess)(int handle_guess, float x_guess,
    float y_guess, float z_guess);
#define g_AIL_set_3D_velocity_vector_guess EQ_GLOBAL(AIL3DVelocity_guess, 0x0063F3DC)
typedef void (__stdcall *AIL3DSampleStart_guess)(int handle_guess);
#define g_AIL_start_3D_sample_guess EQ_GLOBAL(AIL3DSampleStart_guess, 0x0063F3E0)

struct Params_guess {
    float value00_guess; // 0x0
    int value04_guess; // 0x4
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    float value10_guess; // 0x10
    float value14_guess; // 0x14
    float value18_guess; // 0x18
    float value1C_guess; // 0x1C
    float value20_guess; // 0x20
    float value24_guess; // 0x24
    int value28_guess; // 0x28

    Params_guess();
};

struct ChannelParams_guess : Params_guess {
    float randomDistance_guess; // 0x2C

    ChannelParams_guess() : Params_guess() { }
};

// Plays the asset as a 3D sample: distances (Miles takes max, then min), loop count, effects level, position,
// zero velocity; it starts silent and fades to the asked volume (vtable +0x14).
// FUNCTION: TITANIUM 0x004C5675
void SamplePlayer_guess::Play3D_guess(Params_guess* params_guess)
{
    if (handle_guess != 0 && file_guess != 0) {
        if (g_AIL_set_3D_sample_file_guess(handle_guess, file_guess->data_guess) != 0) {
            if (params_guess != 0) {
                g_AIL_set_3D_sample_distances_guess(handle_guess, params_guess->value20_guess,
                    params_guess->value1C_guess);
                g_AIL_set_3D_sample_loop_count_guess(handle_guess, params_guess->value08_guess);
                g_AIL_set_3D_sample_effects_level_guess(handle_guess, params_guess->value24_guess);
                g_AIL_set_3D_position_guess(handle_guess, params_guess->value10_guess,
                    params_guess->value14_guess, params_guess->value18_guess);
                g_AIL_set_3D_velocity_vector_guess(handle_guess, 0.0f, 0.0f, 0.0f);
                g_AIL_set_3D_sample_volume_guess(handle_guess, 0.0f);
                Slot05_guess(params_guess->value00_guess, params_guess->value04_guess);
            }
            g_AIL_start_3D_sample_guess(handle_guess);
        }
    }
}

// Moves the 3D sample to (x, y, z), when it has a handle.
// FUNCTION: TITANIUM 0x004C574E
void WaveInstance3D_guess::SetPosition_guess(float x_guess, float y_guess, float z_guess)
{
    if (handle_guess != 0) {
        g_AIL_set_3D_position_guess(handle_guess, x_guess, y_guess, z_guess);
    }
}

// XMIDI music instance; the sequence handle is allocated on first play.
// FUNCTION: TITANIUM 0x004C5779
MusicInstance_guess::MusicInstance_guess(int argument_guess)
    : SoundInstance_guess(argument_guess)
{
    value14_guess = 0;
    handle_guess = 0;
    table_guess = &g_sequenceVtable_guess;
}

// Music instance dtor body: ends and releases the sequence.
// FUNCTION: TITANIUM 0x004C5797
void MusicInstance_guess::Destroy_guess()
{
    int handle_guess = this->handle_guess;
    table_guess = &g_sequenceVtable_guess;
    if (handle_guess != 0) {
        g_AIL_end_sequence_guess(handle_guess);
        g_AIL_release_sequence_guess(this->handle_guess);
    }
    table_guess = &g_nodeVtable_guess;
}

// Ends and releases the sequence; Play_guess allocates a new one.
// FUNCTION: TITANIUM 0x004C57BF
void MusicInstance_guess::Stop_guess()
{
    if (handle_guess != 0) {
        g_AIL_end_sequence_guess(handle_guess);
        g_AIL_release_sequence_guess(handle_guess);
        handle_guess = 0;
    }
}

// True while the sequence plays and the asked volume or Miles' own is above 0; otherwise it ends the
// sequence, so a finished fade-out stops it.
// FUNCTION: TITANIUM 0x004C57DF
char MusicInstance_guess::IsPlaying_guess()
{
    if (handle_guess != 0) {
        int status_guess = g_AIL_sequence_status_guess(handle_guess);
        if (status_guess == 4) {
            if (volume_guess > g_sequenceZero_guess) {
                return 1;
            }
            if (g_AIL_sequence_volume_guess(handle_guess) > 0) {
                return 1;
            }
        }
        g_AIL_end_sequence_guess(handle_guess);
    }
    return 0;
}

// Volume 0-1 as MIDI volume 0-127, fading over `mode_guess` ms; a repeat of the current volume with a fade
// is ignored, as is any call without a handle or asset. An immediate 0 ends the sequence.
// FUNCTION: TITANIUM 0x004C5823
void MusicInstance_guess::SetVolume_guess(float volume_guess, int mode_guess)
{
    if (mode_guess != 0 && volume_guess == this->volume_guess) {
        return;
    }
    int handle_guess = this->handle_guess;
    if (handle_guess == 0 || valueC_guess == 0) {
        return;
    }
    this->volume_guess = volume_guess;
    g_AIL_set_sequence_volume_guess(handle_guess,
        (int)(volume_guess * 127.0f), mode_guess);
    if (volume_guess == 0.0 && mode_guess == 0) {
        g_AIL_end_sequence_guess(this->handle_guess);
    }
}

struct SequencePlayParams_guess {
    float volume_guess; // 0x0
    int fadeMs_guess; // 0x4
    int loopCount_guess; // 0x8
    int index_guess; // 0xC
};

// Plays sequence `index_guess` of the XMI asset from volume 0, fading to volume x 127 over the asked ms.
// Without params: full volume, loop count 0 (endless). A failed init releases the handle.
// FUNCTION: TITANIUM 0x004C5892
// @early-stop: budget, diff ndiff=4
void MusicInstance_guess::Play_guess(SequencePlayParams_guess* params_guess)
{
    if (handle_guess == 0 &&
        ((SequenceOwner_guess*)argument_guess)->driver_guess != 0) {
        handle_guess = g_AIL_allocate_sequence_handle_guess(
            ((SequenceOwner_guess*)argument_guess)->driver_guess);
    }
    if (handle_guess == 0) {
        return;
    }
    SoundFile_guess* file_guess = (SoundFile_guess*)valueC_guess;
    if (file_guess == 0) {
        return;
    }
    int started_guess;
    if (params_guess != 0) {
        volume_guess = params_guess->volume_guess;
        started_guess = g_AIL_init_sequence_guess(handle_guess, file_guess->data_guess,
            params_guess->index_guess);
        if (started_guess) {
            g_AIL_set_sequence_loop_count_guess(handle_guess, params_guess->loopCount_guess);
            AILSetSequenceVolume_guess setVolume_guess = g_AIL_set_sequence_volume_guess;
            setVolume_guess(handle_guess, 0, 0);
            setVolume_guess(handle_guess,
                (int)(g_sequenceVolumeScale_guess * params_guess->volume_guess),
                params_guess->fadeMs_guess);
        }
    } else {
        volume_guess = 1.0f;
        started_guess = g_AIL_init_sequence_guess(handle_guess, file_guess->data_guess, 0);
        if (started_guess) {
            g_AIL_set_sequence_loop_count_guess(handle_guess, 0);
            g_AIL_set_sequence_volume_guess(handle_guess, 0x7f, 0);
        }
    }
    if (started_guess == 0) {
        g_AIL_release_sequence_guess(handle_guess);
        handle_guess = 0;
    }
    if (handle_guess != 0) {
        g_AIL_start_sequence_guess(handle_guess);
    }
}

// EXTERNAL: TITANIUM 0x00611D9D _filelength
long __cdecl _filelength(int handle_guess);

struct SoundBase_guess {
    int value_guess; // 0x0 (sub-object at 0x4)

    SoundBase_guess() : value_guess(1) {}
    ~SoundBase_guess();
};

// EXTERNAL: TITANIUM 0x0064C160 ??_7SoundData_guess@@6B@
struct SoundData_guess : SoundBase_guess {
    virtual void Slot00_guess();
    char name_guess[0x200]; // 0x8
    void* data_guess; // 0x208
    unsigned size_guess; // 0x20C
    int format_guess; // 0x210
    void* queue_guess; // 0x214
    int value218_guess; // 0x218
    int value21C_guess; // 0x21C

    SoundData_guess(void* head_guess, const char* path_guess,
        const void* memory_guess, unsigned size_param_guess);
};

// Sound asset: type from the extension (.wav 1, .mp3 2, .xmi 3, else 0), data copied from memory or read
// whole from the file; then it joins the manager's list. Same class as Manager_guess (vtable 0x64C160).
// FUNCTION: TITANIUM 0x004C596F
SoundData_guess::SoundData_guess(void* head_guess, const char* path_guess,
    const void* memory_guess, unsigned size_param_guess)
    : SoundBase_guess()
{
    queue_guess = head_guess;
    data_guess = 0;
    size_guess = 0;
    format_guess = 0;
    strcpy(name_guess, path_guess);
    value218_guess = 0;
    head_guess = strrchr(name_guess, '.');
    if (head_guess != 0) {
        if (_stricmp((char*)head_guess, ".xmi") == 0) {
            format_guess = 3;
        } else if (_stricmp((char*)head_guess, ".wav") == 0) {
            format_guess = 1;
        } else if (_stricmp((char*)head_guess, ".mp3") == 0) {
            format_guess = 2;
        }
    }
    if (memory_guess != 0) {
        size_guess = size_param_guess;
        data_guess = operator new(size_guess);
        memcpy(data_guess, memory_guess, size_guess);
    } else {
        FILE* file_guess = fopen(name_guess, "rb");
        if (file_guess != 0) {
            size_guess = _filelength(file_guess->_file);
            data_guess = operator new(size_guess);
            fread(data_guess, 1, size_guess, file_guess);
            fclose(file_guess);
        }
    }
    reinterpret_cast<QueueHead_guess*>(queue_guess)->Insert_guess(
        reinterpret_cast<QueueLinkItem_guess*>(this));
}

// Slide-show audio event: an asset for the file and a 2D wave instance on it, from the sound manager at
// 0x851390 +4.
// FUNCTION: TITANIUM 0x004C48FE
// @early-stop: budget, structural ndiff=6
SlideShowEventAudio_guess::SlideShowEventAudio_guess(const char* name_guess,
    int first_guess, int second_guess, int third_guess, int fourth_guess)
    : CallbackChildBase_guess(1, first_guess, second_guess, third_guess,
        fourth_guess)
{
    flag_guess = 0;
    unsigned int length_guess = strlen(name_guess);
    allocation_guess = new char[length_guess + 1];
    CopyText_guess((char*)allocation_guess, name_guess);
    firstNode_guess = (Node_guess*)new SoundData_guess(
        g_updateManager_guess->service_guess, (const char*)allocation_guess, 0, 0);
    secondNode_guess = (Node_guess*)new WaveInstance2D_guess(
        (int)g_updateManager_guess->service_guess);
    secondNode_guess->Detach_guess((int)firstNode_guess);
}

// Takes a free instance: type 0 from 2D pool `index_guess` (+0x60), 1 from 3D pool (+0x30), 2 the one
// music instance (+0x90). 0 when that pool is empty.
// FUNCTION: TITANIUM 0x004C5125
// @early-stop: budget, diff ndiff=25
Node_guess* SoundManager_guess::TakeFreeInstance_guess(int type_guess,
    int index_guess)
{
    int* slot_guess;
    switch (type_guess) {
    case 0:
        slot_guess = &value60_guess[index_guess];
        break;
    case 1:
        slot_guess = &value30_guess[index_guess];
        break;
    case 2: {
        Node_guess* taken_guess = (Node_guess*)sequence_guess;
        if (taken_guess == 0) {
            return 0;
        }
        sequence_guess = 0;
        return taken_guess;
    }
    default:
        return 0;
    }
    Node_guess* node_guess = (Node_guess*)*slot_guess;
    if (node_guess == 0) {
        return 0;
    }
    *slot_guess = (int)node_guess->next_guess;
    node_guess->next_guess = 0;
    return node_guess;
}

// The asset type: 1 wav, 2 mp3, 3 xmi.
// FUNCTION: TITANIUM 0x004C5ABE
int SoundAsset_guess::GetType_guess()
{
    return value210_guess;
}

// Clears the manager pointer of every instance and of the asset; the manager's shutdown calls it.
// FUNCTION: TITANIUM 0x004C5AC5
void SoundAsset_guess::Clear_guess()
{
    Node_guess* node_guess = first_guess;
    while (node_guess != 0) {
        node_guess->value08_guess = 0;
        node_guess = node_guess->next_guess;
    }
    value214_guess = 0;
}

// True while the asset has a live instance.
// FUNCTION: TITANIUM 0x004C5ADF
bool SoundAsset_guess::IsPlaying_guess()
{
    return first_guess != 0;
}

// Sets the volume of every instance (vtable +0x14: volume, fade ms).
// FUNCTION: TITANIUM 0x004C5AEB
void SoundAsset_guess::SetVolume_guess(float value_guess, int value2_guess)
{
    Node_guess* node_guess = first_guess;
    while (node_guess != 0) {
        node_guess->Slot14_guess(value_guess, value2_guess);
        node_guess = node_guess->next_guess;
    }
}

// The sound asset's name (+8).
// FUNCTION: TITANIUM 0x004C5B12
char* OffsetObject_guess::GetValue_guess()
{
    return &value08_guess;
}

// Plays the asset with `params_guess` (layout at Params_guess's ctor). A wav with distances plays in 3D and
// not at all when the listener is beyond the max distance; other wavs and mp3s play in 2D, xmi as music.
// Takes a free instance from pool +0x28, links and starts it; 0 when none or the volume is 0 or less.
// FUNCTION: TITANIUM 0x004C5B16
// @early-stop: budget, structural ndiff=70
Node_guess* SoundAsset_guess::SoundAsset_Play_guess(Params_guess* params_guess)
{
    int zero_guess = 0;
    if (value214_guess == (SoundManager_guess*)zero_guess) {
        return 0;
    }
    Params_guess* source_guess = params_guess;
    if (source_guess != (Params_guess*)zero_guess &&
        source_guess->value00_guess <= 0.0) {
        return 0;
    }

    int type_guess;
    if (value210_guess == 1) {
        if (source_guess != (Params_guess*)zero_guess &&
            (source_guess->value1C_guess != 0.0f ||
             source_guess->value20_guess != 0.0f)) {
            float localY_guess;
            float localZ_guess;
            ((FourValue_guess*)value214_guess)->GetListenerLocation_guess(
                (int*)&params_guess, (int*)&localY_guess,
                (int*)&localZ_guess, (int*)zero_guess);
            float deltaX_guess = *(float*)&params_guess -
                source_guess->value10_guess;
            float deltaY_guess = localY_guess - source_guess->value14_guess;
            float deltaZ_guess = localZ_guess - source_guess->value18_guess;
            if (source_guess->value20_guess * source_guess->value20_guess <=
                deltaX_guess * deltaX_guess + deltaY_guess * deltaY_guess +
                deltaZ_guess * deltaZ_guess) {
                return 0;
            }
            type_guess = 1;
        } else {
            type_guess = 0;
        }
    } else if (value210_guess == 2) {
        type_guess = 0;
    } else if (value210_guess == 3) {
        type_guess = 2;
    } else {
        return 0;
    }

    Node_guess* node_guess = value214_guess->TakeFreeInstance_guess(
        type_guess, source_guess->value28_guess);
    if (node_guess == 0) {
        return 0;
    }
    node_guess->next_guess = first_guess;
    first_guess = node_guess;
    node_guess->Detach_guess((int)this);
    node_guess->Slot10_guess((int)source_guess);
    return node_guess;
}

// Volume 0 at once on every instance; the next update drops them.
// FUNCTION: TITANIUM 0x004C5C2B
void SoundAsset_guess::SoundAsset_Stop_guess()
{
    SetVolume_guess(0.0f, 0);
}

// Play parameters: +0 volume (1), +4 fade ms, +8 loop count (1; 0 loops forever), +0xC XMI sequence,
// +0x10 position, +0x1C min and +0x20 max distance, +0x24 effects level (1), +0x28 pool index.
// FUNCTION: TITANIUM 0x004C5C39
Params_guess::Params_guess()
{
    value00_guess = 1.0f;
    value04_guess = 0;
    value10_guess = 0.0f;
    value08_guess = 1;
    value0C_guess = 0;
    value28_guess = 0;
    value14_guess = 0.0f;
    value18_guess = 0.0f;
    value1C_guess = 0.0f;
    value20_guess = 0.0f;
    value24_guess = 1.0f;
}

struct ResetState_guess {
    char padding00_guess[0x8];
    float value08_guess; // 0x8
    float value0C_guess; // 0xC
    float value10_guess; // 0x10
    float value14_guess; // 0x14
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C
    int value20_guess; // 0x20
    float value24_guess; // 0x24
    float value28_guess; // 0x28
    float value2C_guess; // 0x2C
    float value30_guess; // 0x30
    float value34_guess; // 0x34
    float value38_guess; // 0x38
    float value3C_guess; // 0x3C
    int value40_guess; // 0x40
    int value44_guess; // 0x44
    int value48_guess[4]; // 0x48
    char value58_guess; // 0x58
    char padding59_guess[0x158 - 0x59];
    int value158_guess; // 0x158
    int value15C_guess; // 0x15C
    int value160_guess; // 0x160
    int value164_guess; // 0x164
    char padding168_guess[0x16C - 0x168];
    int value16C_guess; // 0x16C
    int value170_guess; // 0x170
    char value174_guess; // 0x174
    char padding175_guess[0x178 - 0x175];
    int value178_guess; // 0x178
    int value17C_guess; // 0x17C

    void Reset_guess();
};

// Emitter defaults: volume scales 1, repeat delay 1000-1000 ms, loop count 1, enabled.
// FUNCTION: TITANIUM 0x004C5C70
void ResetState_guess::Reset_guess()
{
    memset(value48_guess, 0, 0x10);
    value08_guess = 1.0f;
    value0C_guess = 1.0f;
    value170_guess = 0;
    value158_guess = 0;
    value15C_guess = 0;
    value10_guess = 0.0f;
    value160_guess = 0;
    value164_guess = 0;
    value58_guess = 0;
    value14_guess = 0.0f;
    value17C_guess = 0;
    value16C_guess = 0;
    value178_guess = 0;
    value24_guess = 0.0f;
    value18_guess = 0;
    value1C_guess = 0;
    value20_guess = 1;
    value28_guess = 0.0f;
    value40_guess = 1000;
    value44_guess = 1000;
    value174_guess = 1;
    value2C_guess = 0.0f;
    value30_guess = 0.0f;
    value34_guess = 0.0f;
    value3C_guess = 0.0f;
    value38_guess = 0.0f;
}

struct SoundEmitter_guess {
    char padding00_guess[0x8];
    float scale_guess; // 0x8
    float multiplier_guess; // 0xC
    char padding10_guess[0x18 - 0x10];
    int value18_guess; // 0x18
    int value1C_guess; // 0x1C
    int value20_guess; // 0x20
    float value24_guess; // 0x24
    float value28_guess; // 0x28
    float value2C_guess; // 0x2C
    float value30_guess; // 0x30
    float value34_guess; // 0x34
    float value38_guess; // 0x38
    float value3C_guess; // 0x3C
    int value40_guess; // 0x40
    int value44_guess; // 0x44
    char padding48_guess[0x158 - 0x48];
    int tick_guess; // 0x158
    int delay_guess; // 0x15C
    Node_guess* value160_guess; // 0x160
    Node_guess* node_guess; // 0x164
    PositionHolder_guess* position_guess; // 0x168
    MusicManager_guess* handles_guess; // 0x16C
    int handleId_guess; // 0x170
    char active_guess; // 0x174
    char padding175_guess[3];
    int value178_guess; // 0x178
    SoundEmitter_guess* next_guess; // 0x17C

    void SetVolume_guess(float value_guess);
    void Stop_guess();
    void SetAsset_guess(Node_guess* node_guess);
    void Process_guess();
};

struct EmitterManager_guess {
    char padding00_guess[4];
    SoundEmitter_guess* first_guess; // 0x4
    char padding08_guess[0x10 - 0x8];
    float value10_guess; // 0x10

    void SetVolume_guess(float value_guess);
    void ProcessAll_guess();
};

// Emitter volume: the master `value_guess` times the emitter's scale (+8), on its playing instance.
// FUNCTION: TITANIUM 0x004C5D11
void SoundEmitter_guess::SetVolume_guess(float value_guess)
{
    if (node_guess != 0) {
        node_guess->Slot14_guess(value_guess * scale_guess, 0);
    }
}

// Fades the emitter's instance out over +0x1C ms and lets it go.
// FUNCTION: TITANIUM 0x004C5D35
void SoundEmitter_guess::Stop_guess()
{
    if (node_guess != 0) {
        node_guess->Slot14_guess(0.0f, value1C_guess);
        node_guess->Finish_guess();
        node_guess = 0;
    }
}

// Restarts the emitter's repeat timer: next play after min (+0x40) + rand() % (max - min) ms (+0x44).
// FUNCTION: TITANIUM 0x004C5D64
void TimerState_guess::ScheduleNextPlay_guess()
{
    tick_guess = g_getTickCount_guess();
    next_guess = minimum_guess;
    if (maximum_guess > minimum_guess) {
        next_guess += rand() % (maximum_guess - minimum_guess);
    }
}

struct PositionListener_guess {
    virtual void Slot00_guess();
    virtual void Slot01_guess();
    virtual void Slot02_guess();
    virtual void Slot03_guess();
    virtual void Slot04_guess();
    virtual void Slot05_guess();
    virtual void Slot06_guess();
    virtual void Slot07_guess(float x_guess, float y_guess, float z_guess); // 0x1C
};

struct PositionSource_guess {
    char padding00_guess[0x24];
    float value24_guess; // 0x24
    float value28_guess; // 0x28
    float value2C_guess; // 0x2C
    char padding30_guess[0x164 - 0x30];
    PositionListener_guess* listener_guess; // 0x164

    void SetPosition_guess(float x_guess, float y_guess, float z_guess);
};

// Moves the emitter (+0x24) and its playing instance (vtable +0x1C).
// FUNCTION: TITANIUM 0x004C5D97
void PositionSource_guess::SetPosition_guess(float x_guess, float y_guess, float z_guess)
{
    if (value24_guess != x_guess || value28_guess != y_guess || value2C_guess != z_guess) {
        value24_guess = x_guess;
        value28_guess = y_guess;
        value2C_guess = z_guess;
        if (listener_guess != 0) {
            listener_guess->Slot07_guess(x_guess, y_guess, z_guess);
        }
    }
}

// Gives the emitter another asset (+0x160, referenced), stopping the old sound.
// FUNCTION: TITANIUM 0x004C5E03
void SoundEmitter_guess::SetAsset_guess(Node_guess* node_guess)
{
    if (value160_guess != node_guess) {
        Stop_guess();
        if (value160_guess != 0) {
            value160_guess->Finish_guess();
            value160_guess = 0;
        }
        value160_guess = node_guess;
        if (node_guess != 0) {
            ++node_guess->value04_guess;
        }
    }
}

// Emitter enable flag (+0x174).
// FUNCTION: TITANIUM 0x004C5E40
void ByteObject_guess::SetEnabled_guess(char value_guess)
{
    value174_guess = value_guess;
}

// Sound bank constructor: device `first` (+0xC) and listener `second` (+0x10), enabled (+1), the rest
// zeroed.
// FUNCTION: TITANIUM 0x004C5E4D
SmallObject_guess::SmallObject_guess(int first_guess, int second_guess)
{
    SmallObject_guess* self_guess = this;
    self_guess->value04_guess = 0;
    self_guess->value10_guess = second_guess;
    self_guess->value0C_guess = first_guess;
    self_guess->value1C_guess = 0;
    self_guess->value00_guess = 0;
    self_guess->value01_guess = 1;
    self_guess->value08_guess = 0;
    self_guess->value14_guess = 0;
    self_guess->value18_guess = 0;
}

// The dword at +0x18; the music player window reads it.
// FUNCTION: TITANIUM 0x004C5E9D
int SmallObject_guess::IsShuffle_guess()
{
    return value18_guess;
}

// Status of the MP3 player's stream; the music player window polls it.
// FUNCTION: TITANIUM 0x004C5EA1
int AudioStreamHolder_guess::GetStatus_guess()
{
    return stream_guess->GetStatus_guess();
}

// MP3 player: the track length.
// FUNCTION: TITANIUM 0x004C5EA9
int AudioStreamHolder_guess::GetTrackLength_guess()
{
    return stream_guess->GetStreamLength_guess();
}

// MP3 player: the play position in ms.
// FUNCTION: TITANIUM 0x004C5EB1
int AudioStreamHolder_guess::GetTrackPosition_guess()
{
    return stream_guess->GetStreamPosition_guess();
}

// Moves the MP3 player's stream to `position` ms.
// FUNCTION: TITANIUM 0x004C5EB9
void AudioStreamHolder_guess::SetPosition_guess(int position_guess)
{
    stream_guess->SetPosition_guess(position_guess);
}

// MP3 player: the title of track `index_guess` (the record's first field), 0 out of range.
// FUNCTION: TITANIUM 0x004C5EC1
int IndexedObject_guess::GetAt_guess(int index_guess)
{
    if (index_guess < 0 || index_guess >= count_guess) {
        return 0;
    }
    return *values_guess[index_guess];
}

// Number of tracks in the MP3 player's list (+0x1C).
// FUNCTION: TITANIUM 0x004C5EDB
int IndexedObject_guess::GetCount_guess()
{
    return count_guess;
}

// MP3 player: the current track index.
// FUNCTION: TITANIUM 0x004C5EDF
int IndexedObject_guess::GetValue_guess()
{
    return value04_guess;
}

// Sets the MP3 player's stream volume.
// FUNCTION: TITANIUM 0x004C5EE3
void AudioStreamHolder_guess::SetVolume_guess(float level_guess)
{
    stream_guess->SetVolume_guess(level_guess);
}

// MP3 player volume (the manager's stream volume, +0xA4).
// FUNCTION: TITANIUM 0x004C5EF6
float FloatGetter_guess::GetVolume_guess()
{
    return source_guess->valueA4_guess;
}

// Saves the MP3 list as an M3U file. In sort mode 1 the file is written in title order and the list is
// then re-sorted with CompareTrackPath_guess.
// FUNCTION: TITANIUM 0x004C5F00
void Playlist_guess::Write_guess(char* outputPath_guess)
{
    if (count_guess > 0) {
        int index_guess = 0;
        if (sortMode_guess == 1) {
            qsort(tracks_guess, count_guess, 4, CompareTrackName_guess);
        }
        outputPath_guess = (char*)fopen(outputPath_guess, "wt");
        if (outputPath_guess != 0) {
            fprintf((FILE*)outputPath_guess, "#EXTM3U\n");
            if (count_guess > 0) {
                PlaylistTrack_guess** track_guess = tracks_guess;
                do {
                    fprintf((FILE*)outputPath_guess, "#EXTINF:%d,%s\n",
                        (*track_guess)->duration_guess, (*track_guess)->name_guess);
                    fprintf((FILE*)outputPath_guess, "%s\n", (*track_guess)->path_guess);
                    ++index_guess;
                    ++track_guess;
                } while (index_guess < count_guess);
            }
            fclose((FILE*)outputPath_guess);
        }
        if (sortMode_guess == 1) {
            qsort(tracks_guess, count_guess, 4, CompareTrackPath_guess);
        }
    }
}

// MP3 player track: path, title (the file name without folder and extension when none is given), length
// in s, id (+0x10).
// FUNCTION: TITANIUM 0x004C5FB8
Mp3Track_guess::Mp3Track_guess(
    const char* path_guess, const char* title_guess, int value08_guess,
    int value10_guess)
{
    char* copiedPath_guess = (char*)DuplicateString_guess(path_guess);
    path_guess = copiedPath_guess;
    this->path_guess = copiedPath_guess;
    if (title_guess == 0 || title_guess[0] == 0) {
        char* base_guess = strrchr(path_guess, '\\');
        if (base_guess != 0) {
            ++base_guess;
        } else {
            base_guess = this->path_guess;
        }
        char* copiedTitle_guess = (char*)DuplicateString_guess(base_guess);
        this->title_guess = copiedTitle_guess;
        char* extension_guess = strrchr(copiedTitle_guess, '.');
        if (extension_guess != 0) {
            *extension_guess = 0;
        }
    } else {
        this->title_guess = (char*)DuplicateString_guess(title_guess);
    }
    value0C_guess = 0;
    this->value08_guess = value08_guess;
    this->value10_guess = value10_guess;
}

// Frees both buffers, second first.
// FUNCTION: TITANIUM 0x004C6026
void PointerPair_guess::Free_guess()
{
    free(second_guess);
    free(first_guess);
}

// Sound mixer constructor: device `id`, +4/+8 zeroed, both volumes (+0xC, +0x10) 1.0.
// FUNCTION: TITANIUM 0x004C603C
Transform2D_guess::Transform2D_guess(int id_guess)
{
    value0C_guess = 1.0f;
    value08_guess = 0;
    value04_guess = 0;
    value10_guess = 1.0f;
    value00_guess = id_guess;
}

// Releases every emitter of the emitter manager (list +4, linked through +0x17C).
// FUNCTION: TITANIUM 0x004C6059
void EntryList_guess::Clear_guess()
{
    while (first_guess != 0) {
        QueueEntry_guess* next_guess = first_guess->previous_guess;
        reinterpret_cast<Node_guess*>(first_guess)->Finish_guess();
        first_guess = next_guess;
    }
}

// Adds an emitter, with a reference, to the emitter manager.
// FUNCTION: TITANIUM 0x004C6079
void EntryList_guess::Insert_guess(QueueEntry_guess* entry_guess)
{
    entry_guess->previous_guess = first_guess;
    first_guess = entry_guess;
    ++entry_guess->count_guess;
    ++count_guess;
}

// Unlinks and releases one emitter.
// FUNCTION: TITANIUM 0x004C6092
void EntryList_guess::Remove_guess(QueueEntry_guess* entry_guess)
{
    QueueEntry_guess** link_guess = &first_guess;
    QueueEntry_guess* current_guess = *link_guess;
    while (current_guess != 0) {
        if (current_guess == entry_guess) {
            *link_guess = current_guess->previous_guess;
            current_guess->previous_guess = 0;
            reinterpret_cast<Node_guess*>(current_guess)->Finish_guess();
            --count_guess;
            return;
        }
        link_guess = &current_guess->previous_guess;
        current_guess = *link_guess;
    }
}

// Sets the asset (+0xC) without the stop of AudioValueNotifier_guess::SetAsset_guess.
// FUNCTION: TITANIUM 0x004C60C9
void Node_guess::SetValue_guess(int value_guess)
{
    value0C_guess = value_guess;
}

// Emitter manager volume (+0x10), passed to every emitter.
// FUNCTION: TITANIUM 0x004C60D3
void EmitterManager_guess::SetVolume_guess(float value_guess)
{
    value10_guess = value_guess;
    for (SoundEmitter_guess* channel_guess = first_guess; channel_guess != 0;
         channel_guess = channel_guess->next_guess) {
        channel_guess->SetVolume_guess(value_guess);
    }
}

// Sound listener constructor: +0 and +4 zeroed, +8 = 1.0, +0xC = 1.
// FUNCTION: TITANIUM 0x004C60FD
AudioState_guess* AudioState_guess::Initialize_guess()
{
    value00_guess = 0;
    value04_guess = 0;
    value08_guess = 1.0f;
    value0C_guess = 1;
    return this;
}

// Sound manager teardown (tu_037 calls it as the dtor): closes the MP3 stream, frees the six 2D and six 3D
// free pools and the music instance, unloads the DLS bank, closes XMIDI, detaches the assets, closes the
// listener, provider and digital driver, then AIL_shutdown.
// FUNCTION: TITANIUM 0x004C6110
void AudioShutdown_guess::Shutdown_guess()
{
    int remaining_guess;
    reinterpret_cast<AudioStreamObject_guess*>(this)->Close_guess();

    Node_guess** secondHeads_guess = &lists_guess[12];
    remaining_guess = 6;
    do {
        Node_guess** firstHead_guess = secondHeads_guess - 12;
        while (*firstHead_guess != 0) {
            Node_guess* current_guess = *firstHead_guess;
            Node_guess* next_guess = current_guess->next_guess;
            current_guess->Finish_guess();
            *firstHead_guess = next_guess;
        }
        while (*secondHeads_guess != 0) {
            Node_guess* current_guess = *secondHeads_guess;
            Node_guess* next_guess = current_guess->next_guess;
            current_guess->Finish_guess();
            *secondHeads_guess = next_guess;
        }
        ++secondHeads_guess;
        --remaining_guess;
    } while (remaining_guess != 0);

    if (pending_guess != 0) {
        pending_guess->Finish_guess();
        pending_guess = 0;
    }

    if (xmidiDriver_guess != 0) {
        if (dlsBank_guess != 0) {
            g_AIL_DLS_unload_guess(dlsFile_guess, dlsBank_guess);
        }
        if (dlsFile_guess != 0) {
            g_AIL_DLS_close_guess(dlsFile_guess, 0);
        }
        free(allocation_guess);
        g_AIL_close_XMIDI_guess(xmidiDriver_guess);
        xmidiDriver_guess = 0;
    }

    ManagerQueue_guess* queue_guess = queues_guess;
    while (queue_guess != 0) {
        ManagerQueue_guess* nextQueue_guess = queue_guess->next_guess;
        queue_guess->Clear_guess();
        queue_guess = nextQueue_guess;
    }

    if (listener_guess != 0) {
        g_AIL_close_listener_guess(listener_guess);
        listener_guess = 0;
    }
    if (provider_guess != 0) {
        g_AIL_close_provider_guess(provider_guess);
        provider_guess = 0;
    }
    if (digitalDriver_guess != 0) {
        g_AIL_close_digital_guess(digitalDriver_guess);
        digitalDriver_guess = 0;
    }
    return g_AIL_shutdown_guess();
}

// Returns an instance, with a reference, to its free pool: 2D to +0x60, 3D to +0x30, music to +0x90.
// FUNCTION: TITANIUM 0x004C62D8
void CleanupContext_guess::ReturnInstance_guess(Node_guess* node_guess)
{
    ++node_guess->value04_guess;
    int kind_guess = node_guess->GetKind_guess();
    Node_guess** head_guess;

    switch (kind_guess) {
    case 0:
        head_guess = &secondHeads_guess[node_guess->value10_guess];
        break;
    case 1:
        head_guess = &firstHeads_guess[node_guess->value10_guess];
        break;
    case 2:
        node_guess->next_guess = 0;
        pending_guess = node_guess;
        return;
    default:
        return;
    }

    node_guess->next_guess = *head_guess;
    *head_guess = node_guess;
}

// Loaded asset by file name, case-insensitive, with a reference added; 0 when not loaded.
// FUNCTION: TITANIUM 0x004C631D
NameEntry_guess* NameList_guess::Find_guess(char* name_guess)
{
    NameEntry_guess* entry_guess = first_guess;
    while (entry_guess != 0) {
        if (__stricmp(entry_guess->name_guess, name_guess) == 0) {
            ++entry_guess->count_guess;
            return entry_guess;
        }
        entry_guess = entry_guess->next_guess;
    }
    return 0;
}

// Toggles pause on the manager's stream: playing pauses, paused resumes.
// FUNCTION: TITANIUM 0x004C6350
void AudioStream_guess::Pause_guess()
{
    int status_guess = GetStatus_guess();
    if (--status_guess != 0) {
        if (--status_guess != 0) {
            return;
        }
        g_AILPauseStream_guess(stream_guess, 0);
    } else {
        g_AILPauseStream_guess(stream_guess, 1);
    }
}

// Zone music track: id +0x10, asset +0x14 (referenced), XMI sequence +0x18, priority +0x1C, volume +0,
// fade-in +0x24, fade-outs +0x28 (replaced) and +0x2C (nothing follows), pool +0xC; loops forever.
// FUNCTION: TITANIUM 0x004C6372
MusicTrack_guess::MusicTrack_guess(int value10_guess,
    ReferenceCounted_guess* reference_guess, int value18_guess,
    float value00_guess, int unused_guess, int value1C_guess,
    int value24_guess, int value28_guess, int value2C_guess,
    int value0C_guess)
{
    this->value0C_guess = value0C_guess;
    this->value10_guess = value10_guess;
    this->value14_guess = reference_guess;
    this->value08_guess = 0;
    ++reference_guess->count_guess;
    this->value18_guess = value18_guess;
    this->value1C_guess = value1C_guess;
    this->value24_guess = value24_guess;
    this->value28_guess = value28_guess;
    this->value2C_guess = value2C_guess;
    this->value20_guess = 0;
    this->value00_guess = reinterpret_cast<int&>(value00_guess);
    this->value30_guess = 0;
}

// Track releases its asset.
// FUNCTION: TITANIUM 0x004C63BE
void NodeHandle_guess::Release_guess()
{
    node_guess->Finish_guess();
    node_guess = 0;
}

// Track volume: the music volume times the track's own (+0).
// FUNCTION: TITANIUM 0x004C63CF
void ScaledQueue_guess::Dispatch_guess(float value_guess)
{
    queue_guess->SetVolume_guess(value_guess * scale_guess, 0);
}

struct ParamSource_guess {
    char padding00_guess[8];
    int value08_guess; // 0x8
    int value0C_guess; // 0xC
    char padding10_guess[4];
    SoundAsset_guess* queue_guess; // 0x14
    int value18_guess; // 0x18
    char padding1C_guess[8];
    int value24_guess; // 0x24

    void Play_guess(float value_guess);
};

// Plays the track unless its asset already has an instance: endless, with its sequence, pool and fade-in.
// FUNCTION: TITANIUM 0x004C63E6
void ParamSource_guess::Play_guess(float value_guess)
{
    if (queue_guess->first_guess == 0) {
        Params_guess params_guess;
        params_guess.value28_guess = value0C_guess;
        params_guess.value04_guess = value24_guess;
        params_guess.value08_guess = value08_guess;
        params_guess.value0C_guess = value18_guess;
        params_guess.value00_guess = value_guess;
        queue_guess->SoundAsset_Play_guess(&params_guess);
    }
}

// Fades the track out: over +0x2C ms when `selectSecond_guess` (nothing replaces it), else over +0x28.
// FUNCTION: TITANIUM 0x004C6431
void DispatchSelector_guess::FadeOut_guess(char selectSecond_guess)
{
    if (selectSecond_guess != 0) {
        queue_guess->SetVolume_guess(0.0f, value2C_guess);
    } else {
        queue_guess->SetVolume_guess(0.0f, value28_guess);
    }
}

// Scalar deleting destructor of the sound object base (operator delete with flag 1).
// FUNCTION: TITANIUM 0x004C6451
void* ManagerBase_guess::Delete_guess(unsigned char flags_guess)
{
    this->ManagerBase_guess::~ManagerBase_guess();
    if ((flags_guess & 1) != 0) {
        operator delete(this);
    }
    return this;
}

// Scalar deleting destructor: restores the sound object base vtable (0x004C52CE); flag 1 frees the
// memory.
// FUNCTION: TITANIUM 0x004C646E
void* VtableObject_guess::Delete_guess(unsigned char flags_guess)
{
    ((VtableResetExternal_guess*)this)->Reset_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Scalar deleting destructor of a 2D wave instance (0x004C5349 releases the sample handle).
// FUNCTION: TITANIUM 0x004C648A
void* SampleObject_guess::Delete_guess(unsigned char flags_guess)
{
    Release_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Plays the asset as a 2D sample. Miles learns the format from a dummy name, ".mp3" for type 2 and ".wav"
// for anything else; volume and fade go through vtable +0x14 before the loop count.
// FUNCTION: TITANIUM 0x004C64A6
void SamplePlayer_guess::Play_guess(SamplePlayParams_guess* params_guess)
{
    if (handle_guess != 0 && file_guess != 0) {
        g_AIL_init_sample_guess(handle_guess);
        int result_guess;
        if (file_guess->format_guess == 2) {
            result_guess = g_AIL_set_named_sample_file_guess(handle_guess,
                ".mp3", file_guess->data_guess, file_guess->size_guess, 0);
        } else {
            result_guess = g_AIL_set_named_sample_file_guess(handle_guess,
                ".wav", file_guess->data_guess, file_guess->size_guess, 0);
        }
        if (result_guess != 0) {
            if (params_guess != 0) {
                Slot05_guess(params_guess->volume_guess,
                    params_guess->value04_guess);
                g_AIL_set_sample_loop_count_guess(handle_guess,
                    params_guess->loopCount_guess);
            }
            g_AIL_start_sample_guess(handle_guess);
        }
    }
}

// Scalar deleting destructor of a 3D wave instance (0x004C551A releases the 3D sample handle).
// FUNCTION: TITANIUM 0x004C6523
void* SampleObject_guess::Delete3D_guess(unsigned char flags_guess)
{
    Release3D_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Scalar deleting destructor of a music instance (0x004C5797 ends and releases the sequence).
// FUNCTION: TITANIUM 0x004C653F
void* MusicInstance_guess::Delete_guess(unsigned char flags_guess)
{
    Destroy_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Sound asset dtor: leaves the manager's list, silences every instance and returns it to its pool, frees
// the data. Same class as SoundData_guess.
// FUNCTION: TITANIUM 0x004C655B
Manager_guess::~Manager_guess()
{
    if (context_guess != 0) {
        reinterpret_cast<QueueHead_guess*>(context_guess)->Remove_guess(
            reinterpret_cast<QueueLinkItem_guess*>(this));
    }
    Node_guess* node_guess = first_guess;
    while (node_guess != 0) {
        Node_guess* next_guess = node_guess->next_guess;
        node_guess->Slot14_guess(0.0f, 0);
        node_guess->Detach_guess(0);
        node_guess->next_guess = 0;
        if (context_guess != 0) {
            context_guess->ReturnInstance_guess(node_guess);
        }
        node_guess->Finish_guess();
        node_guess = next_guess;
    }
    first_guess = 0;
    delete value208_guess;
}

// Returns the instances that stopped playing (vtable Check_guess false) to the manager's pools.
// FUNCTION: TITANIUM 0x004C65F6
void Manager_guess::Update_guess()
{
    Node_guess** link_guess = &first_guess;
    Node_guess* node_guess = *link_guess;
    while (node_guess != 0) {
        Node_guess* next_guess = node_guess->next_guess;
        if (node_guess->Check_guess() == 0) {
            node_guess->next_guess = 0;
            node_guess->Detach_guess(0);
            if (context_guess != 0) {
                context_guess->ReturnInstance_guess(node_guess);
            }
            node_guess->Finish_guess();
            *link_guess = next_guess;
        } else {
            link_guess = &node_guess->next_guess;
        }
        node_guess = next_guess;
    }
}

struct RefHolder_guess {
    char padding00_guess[4];
    int refs_guess; // 0x4
};

// EXTERNAL: TITANIUM 0x0064C0CC ??_7ResetBase_guess@@6B@
struct ResetBase_guess {
    virtual void Slot00_guess();
    int value04_guess; // 0x4

    ResetBase_guess() { value04_guess = 1; }
    virtual ~ResetBase_guess() { }
};

// EXTERNAL: TITANIUM 0x0064C180 ??_7ResetObject_guess@@6B@
struct ResetObject_guess : ResetBase_guess {
    virtual void Slot00_guess();
    char padding08_guess[0x160 - 0x8];
    RefHolder_guess* value160_guess; // 0x160
    int value164_guess; // 0x164
    int value168_guess; // 0x168
    MusicManager_guess* value16C_guess; // 0x16C
    int value170_guess; // 0x170
    char padding174_guess[0x178 - 0x174];
    int value178_guess; // 0x178

    ResetObject_guess(int first_guess, RefHolder_guess* second_guess, int third_guess);
    ResetObject_guess(int first_guess, MusicManager_guess* second_guess, int third_guess);
    virtual ~ResetObject_guess();
    void* Delete_guess(unsigned char flags_guess);
};

// Emitter of sound asset `second_guess` (referenced), pool `third_guess`; `first_guess` (+0x168) gives
// the listener and the master volumes.
// FUNCTION: TITANIUM 0x004C6658
ResetObject_guess::ResetObject_guess(int first_guess, RefHolder_guess* second_guess, int third_guess)
{
    ((ResetState_guess*)this)->Reset_guess();
    value178_guess = third_guess;
    value168_guess = first_guess;
    value160_guess = second_guess;
    if (second_guess != 0) {
        second_guess->refs_guess++;
    }
}

// Emitter that switches zone music track `third_guess` of music manager `second_guess` instead of playing
// an asset.
// FUNCTION: TITANIUM 0x004C6698
ResetObject_guess::ResetObject_guess(int first_guess, MusicManager_guess* second_guess, int third_guess)
{
    ((ResetState_guess*)this)->Reset_guess();
    value16C_guess = second_guess;
    value168_guess = first_guess;
    value170_guess = third_guess;
}

// MP3 player pause toggle.
// FUNCTION: TITANIUM 0x004C66D1
void AudioStreamHolder_guess::Pause_guess()
{
    stream_guess->Pause_guess();
}

// Removes every track that plays asset `target_guess`, releasing it. Not a full clear (that is Clear_guess).
// FUNCTION: TITANIUM 0x004C69EA
void MusicManager_guess::RemoveAsset_guess(Node_guess* target_guess)
{
    NodeHandle_guess** link_guess = &first_guess;
    NodeHandle_guess* current_guess = *link_guess;
    while (current_guess != 0) {
        NodeHandle_guess* next_guess = current_guess->next_guess;
        if (current_guess->node_guess == target_guess) {
            *link_guess = next_guess;
            current_guess->Release_guess();
            free(current_guess);
            if (last_guess == current_guess) {
                last_guess = 0;
            }
        } else {
            link_guess = &current_guess->next_guess;
        }
        current_guess = next_guess;
    }
}

// Music volume (+8), applied to the current track (+4).
// FUNCTION: TITANIUM 0x004C6A37
void ScaledQueueValue_guess::SetMusicTrackVolume_guess(float value_guess)
{
    value08_guess = value_guess;
    if (queue_guess != 0) {
        queue_guess->Dispatch_guess(value_guess);
    }
}

// Removes track `value_guess` (first match), releasing its asset; a current track goes without a fade.
// FUNCTION: TITANIUM 0x004C6A55
void MusicManager_guess::Remove_guess(int value_guess)
{
    NodeHandle_guess** link_guess = &first_guess;
    NodeHandle_guess* node_guess = *link_guess;
    while (node_guess != 0) {
        NodeHandle_guess* next_guess = node_guess->next_guess;
        if (node_guess->value10_guess == value_guess) {
            *link_guess = next_guess;
            node_guess->Release_guess();
            free(node_guess);
            if (last_guess == node_guess) {
                last_guess = 0;
            }
            return;
        }
        link_guess = &node_guess->next_guess;
        node_guess = next_guess;
    }
}

// Makes the wanted track with the lowest priority value (+0x1C) current, fading out the one it replaces.
// While music is allowed (+0xC; the MP3 player clears it) the current track plays at the music volume (+8);
// while it is not, the current track fades out.
// FUNCTION: TITANIUM 0x004C6956
void MusicManager_guess::UpdateMusic_guess()
{
    NodeHandle_guess* best_guess = last_guess;
    if (best_guess != 0 && best_guess->flag20_guess == 0) {
        best_guess = 0;
    }
    for (NodeHandle_guess* node_guess = first_guess; node_guess != 0;
         node_guess = node_guess->next_guess) {
        if (node_guess->flag20_guess != 0 &&
            (best_guess == 0 || node_guess->order1C_guess < best_guess->order1C_guess)) {
            best_guess = node_guess;
        }
    }
    if (best_guess != last_guess) {
        if (last_guess != 0) {
            reinterpret_cast<DispatchSelector_guess*>(last_guess)->FadeOut_guess(best_guess == 0);
        }
        last_guess = best_guess;
    }
    NodeHandle_guess* current_guess = last_guess;
    if (current_guess != 0) {
        if (flagC_guess != 0) {
            if (current_guess->flag4_guess != 0) {
                if (value8_guess > 0.0) {
                    reinterpret_cast<ParamSource_guess*>(current_guess)->Play_guess(value8_guess);
                }
            } else {
                current_guess->flag20_guess = 0;
            }
        } else {
            DispatchSelector_guess* selector_guess =
                reinterpret_cast<DispatchSelector_guess*>(current_guess);
            selector_guess->queue_guess->SetVolume_guess(0.0f, selector_guess->value28_guess);
        }
    }
}

// Marks track `value_guess` wanted, then re-picks.
// FUNCTION: TITANIUM 0x004C6AF2
void MusicManager_guess::Enable_guess(int value_guess)
{
    for (NodeHandle_guess* node_guess = first_guess; node_guess != 0;
         node_guess = node_guess->next_guess) {
        if (node_guess->value10_guess == value_guess) {
            node_guess->flag4_guess = 1;
            node_guess->flag20_guess = 1;
            UpdateMusic_guess();
            return;
        }
    }
}

// Unmarks track `value_guess`, then re-picks.
// FUNCTION: TITANIUM 0x004C6B18
void MusicManager_guess::Disable_guess(int value_guess)
{
    for (NodeHandle_guess* node_guess = first_guess; node_guess != 0;
         node_guess = node_guess->next_guess) {
        if (node_guess->value10_guess == value_guess) {
            node_guess->flag20_guess = 0;
            break;
        }
    }
    UpdateMusic_guess();
}

// EXTERNAL: TITANIUM 0x0057F680 AudioStartup_guess
void __cdecl AudioStartup_guess();

// Fills a free pool: type 0 2D waves, 1 3D waves; tu_037 calls it five times after making the manager.
// FUNCTION: TITANIUM 0x004C6203
// @early-stop: budget, structural ndiff=28 (EH frame for the new-expressions; identical when the
// ctors' Miles calls are dllimport declarations, which compare --match cannot key)
// Adds count_guess to the instance total of slot index_guess, then allocates that many
// instances (the new total, not count_guess) onto the slot's free list; only when the
// device for the type is open (0: digital driver, 1: 3D provider).
void SoundManager_guess::AddInstances_guess(int type_guess, int index_guess,
    int count_guess)
{
    switch (type_guess) {
    case 0:
        if (digitalDriver_guess != 0) {
            int* total_guess = &value78_guess[index_guess];
            *total_guess += count_guess;
            for (int i_guess = 0; i_guess < *total_guess; i_guess++) {
                Node_guess* node_guess =
                    (Node_guess*)new WaveInstance2D_guess((int)this);
                node_guess->SetIndex_guess(index_guess);
                node_guess->next_guess = (Node_guess*)value60_guess[index_guess];
                value60_guess[index_guess] = (int)node_guess;
            }
        }
        break;
    case 1:
        if (provider_guess != 0) {
            int* total_guess = &value48_guess[index_guess];
            *total_guess += count_guess;
            for (int i_guess = 0; i_guess < *total_guess; i_guess++) {
                Node_guess* node_guess = (Node_guess*)new WaveInstance3D_guess(
                    (SampleObject_guess*)this);
                node_guess->SetIndex_guess(index_guess);
                node_guess->next_guess = (Node_guess*)value30_guess[index_guess];
                value30_guess[index_guess] = (int)node_guess;
            }
        }
        break;
    }
}

// Sound manager ctor (tu_037: 16, 6, 1, 22050 or 44100 Hz, 16 bits, 1, speaker type). AIL startup; the
// XMIDI driver and music instance when `xmidiConfig_guess` (really a flag) is set; a digital driver, two
// channels when `positional_guess`; and only Miles' fast 2D positional 3D provider.
// FUNCTION: TITANIUM 0x004C6B3A
// @early-stop: budget, structural ndiff=29
SoundManager_guess* SoundManager_guess::SoundDevice_guess(int spatialCount_guess,
    int digitalCount_guess, const char* xmidiConfig_guess, int rate_guess,
    int bits_guess, char positional_guess, int speakerType_guess)
{
    AudioStartup_guess();
    g_AIL_startup_guess();
    this->speakerType_guess = speakerType_guess;
    valueA8_guess = 0;
    valueAC_guess = 0;
    xmidiDriver_guess = 0;
    digitalDriver_guess = 0;
    value94_guess = 0;
    provider_guess = 0;
    listener_guess = 0;
    memset(value78_guess, 0, 0x18);
    memset(value48_guess, 0, 0x18);
    memset(value60_guess, 0, 0x18);
    memset(value30_guess, 0, 0x18);
    value00_guess = 0.0f;
    value04_guess = 0.0f;
    valueA0_guess = 0;
    value24_guess = 0;
    value20_guess = 0;
    value08_guess = 0.0f;
    value28_guess = 0;
    value2C_guess = 0;
    value9C_guess = 0;
    value0C_guess = 0.0f;
    sequence_guess = 0;
    valueA4_guess = 1.0f;

    if ((char)xmidiConfig_guess != 0) {
        xmidiDriver_guess = g_AIL_open_XMIDI_driver_guess(0);
        if (xmidiDriver_guess != 0) {
            sequence_guess = new MusicInstance_guess((int)this);
        }
    }

    if (digitalCount_guess > 0) {
        digitalDriver_guess = g_AIL_open_digital_driver_guess(rate_guess,
            bits_guess, (positional_guess != 0) + 1, 0);
        if (digitalDriver_guess != 0) {
            AddInstances_guess(0, 0, digitalCount_guess);
        }
    }

    if (digitalDriver_guess != 0 && spatialCount_guess > 0) {
        int providerIndex_guess = 0;
        int providerValue_guess = 0;
        char* providerName_guess = 0;
        while (g_AIL_enumerate_3D_providers_guess(&providerIndex_guess,
            &providerValue_guess, &providerName_guess) != 0) {
            if (__stricmp(providerName_guess,
                "Miles Fast 2D Positional Audio") == 0) {
                provider_guess = providerValue_guess;
                g_AIL_open_3D_provider_guess(providerValue_guess);
                listener_guess = g_AIL_open_3D_listener_guess(provider_guess);
                g_AIL_set_3D_speaker_type_guess(provider_guess,
                    this->speakerType_guess);
                break;
            }
        }
        AddInstances_guess(1, 0, spatialCount_guess);
    }
    return this;
}

// Adds zone music track `value_guess`, replacing one with the same id; nothing when `reference_guess`
// (the asset) is 0.
// FUNCTION: TITANIUM 0x004C6A99
void MusicManager_guess::Add_guess(int value_guess,
    ReferenceCounted_guess* reference_guess, int value18_guess,
    float value00_guess, int unused_guess, int value1C_guess,
    int value24_guess, int value28_guess, int value2C_guess,
    int value0C_guess)
{
    Remove_guess(value_guess);
    if (reference_guess != 0) {
        NodeHandle_guess* node_guess = reinterpret_cast<NodeHandle_guess*>(
            new MusicTrack_guess(value_guess, reference_guess,
                value18_guess, value00_guess, unused_guess, value1C_guess,
                value24_guess, value28_guess, value2C_guess, value0C_guess));
        node_guess->next_guess = first_guess;
        first_guess = node_guess;
    }
}

// Per frame: every asset drops its finished instances.
// FUNCTION: TITANIUM 0x004C6CC1
void ManagerList_guess::Update_guess()
{
    Manager_guess* manager_guess = first_guess;
    while (manager_guess != 0) {
        manager_guess->Update_guess();
        manager_guess = manager_guess->next_guess;
    }
}

typedef int (__stdcall *AILOpenStream_guess)(int driver_guess, const char* name_guess,
    int flags_guess);
#define g_AIL_open_stream_guess EQ_GLOBAL(AILOpenStream_guess, 0x0063F358)
typedef void (__stdcall *AILStartStream_guess)(int stream_guess);
#define g_AIL_start_stream_guess EQ_GLOBAL(AILStartStream_guess, 0x0063F35C)

struct NamedAudioStream_guess {
    char padding00_guess[0x14];
    int driver_guess; // 0x14
    char padding18_guess[0xA4 - 0x18];
    float volume_guess; // 0xA4
    int stream_guess; // 0xA8
    char name_guess[0x100]; // 0xAC, size guessed

    void Open_guess(const char* path_guess);
};

// MP3 player: plays `path_guess` on the manager's stream. The same file while paused resumes instead; any
// other stream is closed first.
// FUNCTION: TITANIUM 0x004C6CDD
void NamedAudioStream_guess::Open_guess(const char* path_guess)
{
    if (stream_guess != 0) {
        if (__stricmp(path_guess, name_guess) == 0
            && ((AudioStream_guess*)this)->GetStatus_guess() == 2) {
            ((AudioStream_guess*)this)->Pause_guess();
            return;
        }
        ((AudioStreamObject_guess*)this)->Close_guess();
    }
    CopyText_guess(name_guess, path_guess);
    stream_guess = g_AIL_open_stream_guess(driver_guess, name_guess, 0);
    if (stream_guess != 0) {
        g_AIL_set_stream_volume_levels_guess(stream_guess, volume_guess,
            volume_guess);
        g_AIL_start_stream_guess(stream_guess);
    }
}

// Scalar deleting destructor of a sound asset (0x004C655B; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C6D6F
void* Manager_guess::Delete_guess(unsigned char flags_guess)
{
    this->Manager_guess::~Manager_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Per-frame update of every emitter.
// FUNCTION: TITANIUM 0x004C72A8
void EmitterManager_guess::ProcessAll_guess()
{
    for (SoundEmitter_guess* channel_guess = first_guess; channel_guess != 0;
         channel_guess = channel_guess->next_guess) {
        channel_guess->Process_guess();
    }
}

// Frees every track but leaves the list heads as they were: probably the music manager's dtor body.
// FUNCTION: TITANIUM 0x004C72C1
void MusicManager_guess::Clear_guess()
{
    NodeHandle_guess* node_guess = first_guess;
    while (node_guess != 0) {
        NodeHandle_guess* next_guess = node_guess->next_guess;
        node_guess->Release_guess();
        free(node_guess);
        node_guess = next_guess;
    }
}

// Emitter dtor: hands back its music track, if any, and its asset.
// FUNCTION: TITANIUM 0x004C6D8B
ResetObject_guess::~ResetObject_guess()
{
    if (value170_guess > 0) {
        value16C_guess->Disable_guess(value170_guess);
        value16C_guess->Remove_guess(value170_guess);
    }
    ((SoundEmitter_guess*)this)->SetAsset_guess(0);
}

// EXTERNAL: TITANIUM 0x0060F784 Cos_guess
double __cdecl Cos_guess(double angle_guess);
// EXTERNAL: TITANIUM 0x0060F6D4 Sin_guess
double __cdecl Sin_guess(double angle_guess);

// Per-frame emitter update. In range: the listener nearer than the max distance (+0x34) or the radius
// (+0x3C, 1e7 when unset), whichever is smaller. A music emitter (+0x170) only wants or unwants its track.
// A sound emitter plays once in range and its repeat delay has passed, at its spot or, with a scatter
// (+0x38), at a random angle and distance around the listener. With no repeat delay or loop count 0 it loops
// forever and is faded out on leaving range; otherwise each play is fired and forgotten.
// FUNCTION: TITANIUM 0x004C6DE9
// @early-stop: budget, diff ndiff=26
void SoundEmitter_guess::Process_guess()
{
    char shouldProcess_guess = 0;
    if (tick_guess == 0) {
        ((TimerState_guess*)this)->ScheduleNextPlay_guess();
    }

    float x_guess = 0.0f;
    float y_guess = 0.0f;
    float z_guess = 0.0f;
    float angle_guess;
    int randomValue_guess;
    if (active_guess != 0) {
        position_guess->values_guess->GetListenerLocation_guess((int*)&x_guess,
            (int*)&y_guess, (int*)&z_guess, 0);
        float dx_guess = x_guess - value24_guess;
        float dy_guess = y_guess - value28_guess;
        float dz_guess = z_guess - value2C_guess;
        float range_guess;
        if (value3C_guess <= 0.0f) {
            range_guess = 10000000.0f;
        } else {
            range_guess = value3C_guess;
        }
        if (value34_guess != 0.0f && value34_guess < range_guess) {
            range_guess = value34_guess;
        }
        if (dx_guess * dx_guess + dy_guess * dy_guess + dz_guess * dz_guess
            < range_guess * range_guess) {
            int elapsed_guess = GetTickCount() - tick_guess;
            if (delay_guess == 0 || elapsed_guess > delay_guess || handleId_guess != 0) {
                shouldProcess_guess = 1;
            }
        }
    }

    if (handleId_guess != 0) {
        if (shouldProcess_guess != 0) {
            handles_guess->Enable_guess(handleId_guess);
        } else {
            handles_guess->Disable_guess(handleId_guess);
        }
    } else if (value160_guess != 0) {
        if (shouldProcess_guess != 0) {
            ((TimerState_guess*)this)->ScheduleNextPlay_guess();
            if (node_guess == 0) {
                ChannelParams_guess params_guess;
                int value04_guess = value18_guess;
                params_guess.value28_guess = value178_guess;
                params_guess.value1C_guess = value30_guess;
                params_guess.value20_guess = value34_guess;
                params_guess.value00_guess = position_guess->value10_guess * scale_guess;
                params_guess.value04_guess = value04_guess;
                params_guess.value08_guess = value20_guess;
                params_guess.value24_guess = position_guess->value0C_guess * multiplier_guess;

                if (value38_guess > 0.0f) {
                    randomValue_guess = rand() % 0x168;
                    angle_guess = (float)randomValue_guess * 0.017453292519943295;
                    randomValue_guess = rand() % 0x2710;
                    params_guess.randomDistance_guess = (float)randomValue_guess
                        * value38_guess * 0.0001f;
                    params_guess.value10_guess = (float)(
                        Cos_guess(angle_guess) * params_guess.randomDistance_guess + x_guess);
                    params_guess.value14_guess = (float)(
                        Sin_guess(angle_guess) * params_guess.randomDistance_guess + y_guess);
                    params_guess.value18_guess = z_guess;
                } else {
                    params_guess.value10_guess = value24_guess;
                    params_guess.value14_guess = value28_guess;
                    params_guess.value18_guess = value2C_guess;
                }

                if ((value40_guess == 0 && value44_guess == 0)
                    || value20_guess == 0) {
                    params_guess.value08_guess = 0;
                    Node_guess* newNode_guess =
                        ((SoundAsset_guess*)value160_guess)->SoundAsset_Play_guess(&params_guess);
                    node_guess = newNode_guess;
                    if (newNode_guess != 0) {
                        ++newNode_guess->value04_guess;
                    }
                } else {
                    ((SoundAsset_guess*)value160_guess)->SoundAsset_Play_guess(&params_guess);
                }
            }
        } else {
            Stop_guess();
        }
    }
}

// Scalar deleting destructor of a sound emitter (0x004C6D8B; flag 1 frees the memory).
// FUNCTION: TITANIUM 0x004C72E8
void* ResetObject_guess::Delete_guess(unsigned char flags_guess)
{
    this->ResetObject_guess::~ResetObject_guess();
    if ((flags_guess & 1) != 0) {
        free(this);
    }
    return this;
}

// Per-frame asset update: every asset drops its finished instances (0x004C6CC1).
// FUNCTION: TITANIUM 0x004C72E3
void ManagerList_guess::UpdateThunk_guess()
{
    Update_guess();
}

struct StreamOwner_guess {
    char padding_guess[0xc];
    AudioStreamObject_guess* stream_guess; // 0xC
    MusicManager_guess* list_guess; // 0x10
    char flag_guess; // 0x14

    void Stop_guess();
};

// MP3 player stop: lets zone music back in (+0xC = 1), closes the stream, clears playing (+0x14).
// FUNCTION: TITANIUM 0x004C703E
void StreamOwner_guess::Stop_guess()
{
    MusicManager_guess* list = list_guess;
    if (list != 0) {
        list->flagC_guess = 1;
        list->UpdateMusic_guess();
    }
    stream_guess->Close_guess();
    flag_guess = 0;
}


struct Mp3Player_guess {
    char padding00_guess[4];
    int value04_guess; // 0x4
    char padding08_guess[0x1C - 0x8];
    int count_guess; // 0x1C
    PointerPair_guess* items_guess[1]; // 0x20

    void ClearPlaylist_guess();
    void Remove_guess(int index_guess);
    void PlayIndex_guess(int index_guess);
    void Play_guess();
};

// MP3 player play: unless already playing, silences zone music and plays the current track (+4); an
// unknown length is filled in, in whole seconds, from GetPosition_guess (the length, see the swap note).
// FUNCTION: TITANIUM 0x004C705F
void Mp3Player_guess::Play_guess()
{
    StreamOwner_guess* owner_guess = (StreamOwner_guess*)this;
    if (owner_guess->flag_guess != 0
        && ((AudioStream_guess*)owner_guess->stream_guess)->GetStatus_guess() == 1) {
        return;
    }
    MusicManager_guess* list = owner_guess->list_guess;
    if (list != 0) {
        list->flagC_guess = 0;
        list->UpdateMusic_guess();
    }
    if (value04_guess < count_guess) {
        PointerPair_guess* item_guess = items_guess[value04_guess];
        ((NamedAudioStream_guess*)owner_guess->stream_guess)->Open_guess(
            (const char*)item_guess->second_guess);
        if (items_guess[value04_guess]->duration_guess == 0) {
            int position_guess = ((AudioStream_guess*)owner_guess->stream_guess)->GetStreamLength_guess();
            items_guess[value04_guess]->duration_guess = (position_guess + 999) / 1000;
        }
        owner_guess->flag_guess = 1;
    }
}

// MP3 player: stops and frees every track.
// FUNCTION: TITANIUM 0x004C70FD
void Mp3Player_guess::ClearPlaylist_guess()
{
    ((StreamOwner_guess*)this)->Stop_guess();
    for (int i = 0; i < count_guess; i++) {
        PointerPair_guess* item = items_guess[i];
        if (item != 0) {
            item->Free_guess();
            delete item;
        }
    }
    count_guess = 0;
    value04_guess = 0;
}

// Removes track `index_guess`. Removing the playing one stops playback; the current index stays on the same
// track, clamped to the list.
// FUNCTION: TITANIUM 0x004C713C
void Mp3Player_guess::Remove_guess(int index_guess)
{
    if (index_guess >= 0 && index_guess < count_guess) {
        if (index_guess == value04_guess) {
            ((StreamOwner_guess*)this)->Stop_guess();
        } else if (index_guess < value04_guess) {
            value04_guess--;
        }
        PointerPair_guess** slot_guess = &items_guess[index_guess];
        PointerPair_guess* item_guess = *slot_guess;
        if (item_guess != 0) {
            item_guess->Free_guess();
            delete item_guess;
        }
        count_guess--;
        memmove(slot_guess, &items_guess[index_guess + 1],
            (count_guess - index_guess) * 4);
        if (value04_guess >= count_guess) {
            value04_guess = count_guess - 1;
        }
        if (value04_guess < 0) {
            value04_guess = 0;
        }
    }
}

// Stops, selects track `index_guess` (clamped) and plays it.
// FUNCTION: TITANIUM 0x004C70CE
void Mp3Player_guess::PlayIndex_guess(int index_guess)
{
    ((StreamOwner_guess*)this)->Stop_guess();
    value04_guess = index_guess;
    if (index_guess >= count_guess) {
        value04_guess = count_guess - 1;
    }
    if (value04_guess < 0) {
        value04_guess = 0;
    }
    Play_guess();
}

// EXTERNAL: TITANIUM 0x00624405 _access
extern "C" int __cdecl _access(const char* path_guess, int mode_guess);

struct FileScanner_guess {
    char padding00_guess[0x8];
    int nextId_guess; // 0x8
    char padding0C_guess[0x1C - 0xC];
    int count_guess; // 0x1C
    Mp3Track_guess* records_guess[1]; // 0x20

    int Process_guess(const char* path_guess, const char* title_guess, int duration_guess);
    int AddFile_guess(const char* pattern_guess);
};

// Adds a file to the MP3 list: .mp3/.wav directly (title and length from the caller); .m3u by reading each
// #EXTINF title and length and adding its entries (relative to the list's folder, recursively). Returns
// the count added; nothing checks the list's capacity.
// FUNCTION: TITANIUM 0x004C66D9
int FileScanner_guess::Process_guess(const char* path_guess, const char* title_guess, int duration_guess)
{
    char* ext_guess = strrchr(path_guess, '.');
    if (ext_guess == 0) {
        return 0;
    }
    if (_access(path_guess, 0) == -1) {
        return 0;
    }
    int added_guess = 0;
    if (__stricmp(ext_guess, ".mp3") == 0 || __stricmp(ext_guess, ".wav") == 0) {
        records_guess[count_guess] = new Mp3Track_guess(path_guess, title_guess, duration_guess, nextId_guess);
        count_guess++;
        nextId_guess++;
        added_guess = 1;
    } else if (__stricmp(ext_guess, ".m3u") == 0) {
        char full_guess[512];
        char dir_guess[512];
        char name_guess[512];
        char line_guess[1024];
        strcpy(dir_guess, path_guess);
        char* sep_guess = strrchr(dir_guess, '\\');
        if (sep_guess != 0) {
            sep_guess[1] = 0;
        } else {
            dir_guess[0] = 0;
        }
        FILE* file_guess = fopen(path_guess, "rt");
        if (file_guess != 0) {
            int length_guess = 0;
            name_guess[0] = 0;
            while (!(file_guess->_flag & _IOEOF)) {
                line_guess[0] = 0;
                fgets(line_guess, 1024, file_guess);
                char* end_guess = line_guess + strlen(line_guess);
                while (end_guess > line_guess && *end_guess < ' ') {
                    *end_guess-- = 0;
                }
                if (line_guess[0] == '#') {
                    if (_strnicmp(line_guess, "#EXTINF:", 8) == 0) {
                        length_guess = atoi(line_guess + 8);
                        char* comma_guess = strchr(line_guess, ',');
                        if (comma_guess != 0) {
                            strcpy(name_guess, comma_guess + 1);
                        } else {
                            name_guess[0] = 0;
                        }
                    }
                } else if (strlen(line_guess) > 3) {
                    if (line_guess[0] == '\\' || strchr(line_guess, ':') != 0) {
                        strcpy(full_guess, line_guess);
                    } else {
                        sprintf(full_guess, "%s%s", dir_guess, line_guess);
                    }
                    added_guess += Process_guess(full_guess, name_guess, length_guess);
                    length_guess = 0;
                    name_guess[0] = 0;
                }
            }
            fclose(file_guess);
        }
    }
    return added_guess;
}

// Adds every file matching the wildcard `pattern_guess`, by full path; returns the count added.
// FUNCTION: TITANIUM 0x004C71B6
int FileScanner_guess::AddFile_guess(const char* pattern_guess)
{
    char* file_part_guess;
    char full_guess[512];
    char combined_guess[512];
    char dir_guess[512];
    WIN32_FIND_DATAA find_guess;
    HANDLE handle_guess;
    int total_guess;

    strcpy(dir_guess, pattern_guess);
    char* sep_guess = strrchr(dir_guess, '\\');
    if (sep_guess == 0) {
        sep_guess = strrchr(dir_guess, ':');
    }
    if (sep_guess == 0) {
        dir_guess[0] = 0;
    } else {
        sep_guess[1] = 0;
    }
    handle_guess = FindFirstFileA(pattern_guess, &find_guess);
    total_guess = 0;
    if (handle_guess != INVALID_HANDLE_VALUE) {
        do {
            sprintf(combined_guess, "%s%s", dir_guess, find_guess.cFileName);
            GetFullPathNameA(combined_guess, 512, full_guess, &file_part_guess);
            total_guess += Process_guess(full_guess, 0, 0);
        } while (FindNextFileA(handle_guess, &find_guess) != 0);
    }
    return total_guess;
}
