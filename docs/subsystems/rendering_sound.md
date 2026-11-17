# Rendering glue and sound

[Subsystems](README.md) | [Overview](../ARCHITECTURE.md) section 15 | [Long page](../rendering.md)

`eqgame.exe` does not render the world itself: it loads the graphics DLL and calls virtual methods on the interfaces
that DLL returns. The game side is the per-frame world function in CDisplay, which also drives physics,
missiles, the character tick, the sky and the light. Sound is a separate manager over Miles.

## Files and classes

| File | Classes / objects | Role |
|---|---|---|
| `tu_097_Win.cpp` | `WinMain_guess` | loads the graphics DLL |
| `tu_029_Display.cpp` | `CDisplay_guess` | `Render_World_guess`, `RealRender_World_guess`, `SetAmbientLight_guess` |
| `tu_000_FadeList.cpp` | fade list | actor fades updated each frame |
| `tu_037_EQ_SoundManager.cpp` | `EqSoundManager_guess` | game sounds, soundassets.txt |
| `tu_087_SoundManager.cpp` | `SoundManager_guess`, `SoundAsset_guess` | Miles wrappers: drivers, 3D provider, playback |

## Key functions

| VA | Name | What it does |
|---|---|---|
| 0x004CFD32 | `WinMain_guess` | loads the graphics DLL: the one named by `[Defaults] GraphicsDLL9` in eqclient.ini, else EQGraphicsDX9.DLL, through 0x00609680; a named DLL that fails is retried with the default, and if that fails too the client shows an error box and exits |
| 0x00445A6C | `CDisplay_guess::Render_World_guess` | calls `RealRender_World_guess` |
| 0x00445243 | `CDisplay_guess::RealRender_World_guess` | one world frame (below) |
| 0x00441295 | `CDisplay_guess::SetAmbientLight_guess(rate)` | light by zone type when there is no sky |
| 0x0044CA8F | `EqSoundManager_guess(disable, highRate, speakerType)` | unless disabled: loads soundassets.txt, opens a device at 44100 or 22050 Hz, creates listener, mixer and bank |
| 0x004C6B3A | `SoundManager_guess::SoundDevice_guess` | Miles start-up: XMIDI and digital drivers, then looks for Miles' fast 2D positional 3D provider |
| 0x004C5B16 | `SoundAsset_guess::SoundAsset_Play_guess` | plays one sample |

## One frame: `RealRender_World_guess` (0x00445243)

```
fades, mobile sound emitters, indoor sound state, listener at our spawn, ProcessSound
frame time -> CDisplay +0x148; particles and world time follow it
spawn at actor +0x158: process_physics 0x004BFE0F + MovePlayer_guess, also while paused
controlled spawn and (if different) our own spawn: the same, not while paused
every 250 ms: camera clip, distance capped at 600
world->ForEachPlayer(ProcessPlayerPhysics_guess 0x00436039); again for visible spawns within 250 units
missile list: MotionObject_guess::CreateActorWhenReady_guess 0x00476B12 / TrackTarget_guess 0x004766AA, removal when done
character tick: DoPassageOfTime_guess on the character (not while paused)
target name tint (old and new target)
zone type (0x00923B88) 1, 2 or 5 (outdoor): ProcessSky_guess; otherwise SetAmbientLight_guess
cursor net status, effects and resources at our position, our model update, sky object
renderer: BeginFrame, optional extra pass, pending video mode change, pending screenshot, EndFrame
```

## Key globals

| Address | What |
|---|---|
| 0x0099E38C | game-side graphics object |
| 0x0099E348 - 0x0099E374 | interface pointers into the graphics DLL |
| 0x00923B88 | zone type (outdoor 1, 2, 5); the code names it `g_gameState_445243_guess` |
| 0x00851390 | sound manager |

## Known client bugs

- [B36](../KNOWN_CLIENT_BUGS.md#sound-and-music-tu_037_eq_soundmanager-tu_087_soundmanager-tu_178_largedialogwnd): `SoundAsset_Play_guess` 0x004C5B16 reads
  a null parameter block. [B37](../KNOWN_CLIENT_BUGS.md#not-bugs) is not a bug: the 3D pool call `AddInstances_guess`
  0x004C6203 returns when there is no provider.
- [B38, B86](../KNOWN_CLIENT_BUGS.md#options-ini-and-local-files): MP3 playlist and mp3index.txt loads.
- [B81](../KNOWN_CLIENT_BUGS.md#sound-and-music-tu_037_eq_soundmanager-tu_087_soundmanager-tu_178_largedialogwnd): MP3 window volume label.
- [B41](../KNOWN_CLIENT_BUGS.md#other-confirmed-behaviour): camera distance cap without a lower bound
  (0x00570FCA `UpdateChase_guess`).
