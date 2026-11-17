# Rendering: the boundary to the graphics DLL

[Overview](ARCHITECTURE.md) section 15 | [Source guide](README.md)

`eqgame.exe` does not render the world itself; the UI library's drawing code is in the executable, but the world goes through the DLL. All 3D work (zones, actors, particles, sky, collision, the frame
itself) is done by EQGraphicsDX9.dll, which the game loads at start-up and reaches only through a few
exported functions and a set of interface objects. Game code that "renders" is bookkeeping around calls into
those interfaces. The DLL is not part of this repo.

```
WinMain_guess (tu_097_Win)
  `- graphics DLL loader 0x00609680 (not rewritten)
       LoadLibraryA(<[Defaults] GraphicsDLL9 or "EQGraphicsDX9.DLL">)       -> module 0x0099E350
       GetProcAddress "GetGraphicsEngineInfo"  -> 0x0099E378;  call it    -> info block 0x0099E354
       GetProcAddress "CreateGraphicsEngine"   -> 0x0099E37C
       GetProcAddress "ReleaseGraphicsEngine"  -> 0x0099E380
       GetProcAddress "EQG_GetCpuSpeed2" / "EQG_GetCpuSpeed3" -> 0x0099E384 / 0x0099E388
       CreateGraphicsEngine(&table 0x0099E358) and copy the table's pointers:

          table[0] -> 0x0099E35C   table[1] -> 0x0099E360   table[2] -> 0x0099E368
          table[3] -> 0x0099E364   table[4] -> 0x0099E36C   table[5] -> 0x0099E370
          table[6] -> 0x0099E374   table[7] -> 0x0099E348   table[8] -> 0x0099E34C

game code ---> EQ_GLOBAL(<local view>*, 0x0099E36x)->VirtualMethod(...) ---> EQGraphicsDX9.dll
```

The loader's behaviour above is read from the disassembly; it returns 0 on success and -1 to -7 when
the DLL does not load, an export is missing, or the engine-info call fails (-3). `WinMain_guess` exits with -0x2A when the configured DLL and the
default both fail. It logs the DLL version from the first three words of the info block.

## The interfaces
Each global holds a pointer to an object with a vtable inside the DLL. Game code calls only virtual methods
on them. Because no shared header declares them yet, every TU declares a small local struct with the slots it
uses (`virtual float Sin_guess(float)` in slot 2 of `Trig_guess`, tu_055_Movement). The names those views were given
agree well enough to tell the roles apart:

| global | from table | local view names in the source (examples) | role (inferred) |
|---|---|---|---|
| 0x0099E35C | [0] | `WorldFileSystem_guess` | zone file access |
| 0x0099E360 | [1] | `FontService_guess`, `ZoneLoader_guess`, `NpcFileSystem_guess` | resources: files, fonts, sprites |
| 0x0099E364 | [3] | `Render_445243_guess`, `Renderer_guess`, `ScreenshotOutput_guess`, `DisplayInterface_guess` | the renderer: `BeginFrame_guess` / `EndFrame_guess`, screenshots, video mode |
| 0x0099E368 | [2] | `World_445243_guess`, `ZoneRender_guess`, `SpawnFactory_guess`, `SkyOwner_guess` | the world: actors, sky, time of day, clip planes |
| 0x0099E36C | [4] | `Particle_445243_guess`, `ParticleSystem_guess`, `EmitterFactory_guess` | particles and effects |
| 0x0099E370 | [5] | `CollisionQuery_guess`, `Collider_48ACEF_guess`, `TraceService_guess` | collision and line traces |
| 0x0099E374 | [6] | `Trig_guess`, `AngleFunctions_guess`, `CalcMath_guess` | math: `Sin_guess`, `Cos_guess`, `Sqrt_guess` |
| 0x0099E348 | [7] | `ResourceFactory_guess`, `PathFactory_guess` | |
| 0x0099E354 | info block | `EngineInfo_guess`, `SysInfo_guess` | version and system information |

Separate from the table: `0x0099E38C` holds a game-side graphics object that `WinMain_guess` creates before
loading the DLL (constructor 0x00609940, vtable 0x0064CA88). tu_029_Display reads it as the video settings
(`SetDisplayOptions_guess` 0x00437A1B and `StoreDisplayOptions_guess` 0x00437A61: `Initialize_guess`, a
fullscreen flag at +4, width and height); other TUs call it the cursor, command or options state. It is one
object with many local names. The byte at +4 is the fullscreen flag: when it is 0, 0x004CD510
(`GetMouseClientPos_guess`) converts the cursor through ScreenToClient (the windowed path), and 0x0053CA42 (`ActionOwner_guess::UpdateAction_guess`) in
tu_192_OptionsWnd shows the Set Windowed button when it is set. tu_192_OptionsWnd's `IsWindowed_guess` reads the same byte and is
misnamed.

There is no shared declaration per interface; grep for the global's address to find every use:
`grep -rn "0x0099E368" src/`.

## One frame (tu_029_Display)
`CDisplay::Render_World_guess` (0x00445A6C) is a one-line wrapper; the work is in
`RealRender_World_guess` (0x00445243). In order, from the code:
1. toggles a frame flag; enables or disables particles (0x0099E36C) by the particle option;
2. gives the sound manager (0x00851390, MQ2 `pinstEQSoundManager`; methods in tu_037_EQ_SoundManager) the local player's
   position (0x00905CE4) and the camera; passes the listener position to the particle interface and the client millisecond
   clock (`EqGetTime`) to the world (`SetTime_guess` on 0x0099E368);
3. moves the boat (actor +0x158), then, unless paused, the controlled spawn (0x00905CF8) and the local player
   if different (`MovePlayer_guess`);
4. sets the clip distance from the camera (`SetClip_guess`), runs a per-player callback over the world
   (`ForEachPlayer_guess` with `ProcessPlayerPhysics_guess` 0x00436039, which calls `process_physics` and
   `MovePlayer_guess` for each spawn except the local/controlled one and the one at actor +0x158; after 12 s without an update, a Type >= 1 spawn
   whose SpeedRun and SpeedZ are both 0 (one with only SpeedZ set still moves) and, while 0x00923884 is 0, any
   other spawn are skipped), and walks the
   spawn list (0x00905CC4) checking the visible spawns within 250 units (distance squared below 62,500) of the
   controlled spawn;
5. updates the sky (object 0x008503A8) and hands it to the world (`SetSky_guess`);
6. `BeginFrame_guess` on the renderer (0x0099E364), an extra draw when the local player's actor asks for one,
   a pending video-mode change (`SetRenderWindow_guess` 0x00436267), a pending screenshot
   (`CaptureScreenshot_guess` 0x00438ED8), then `EndFrame_guess`.

`DoMainLoop` (0x004ABA14) calls `Render_World_guess` once per frame after the window manager has drawn the UI (see
[startup.md](startup.md)), and skips it for the first 30 frames. The function 0x004A9CA7 (`ProcessGameEventsAndRender_guess`, tu_062_EverQuest) draws one frame
outside the loop: it sets the flag 0x00905CA4, runs `ProcessGameEvents`, calls `Render_World_guess` and clears
the flag.

## Actors
Every spawn has a graphics-side actor. `CDisplay::CreateActor_guess` (0x0043972A) and `DeleteActor_guess`
(0x00439A46) create and destroy them; `CreatePlayerActor` (0x0043C84B) builds one for an `EQPlayer`;
`EQPlayer::pActorInfo` (+0x1A8) holds the game-side state for it. Appearance changes go through helpers in
tu_053_EQPlayer that the Mac client has on `CDisplay`; in Titanium they are `EQPlayer` methods (`this` is the spawn),
and they are named that way: `SwapHead_guess` (0x0048236E), `SwapMaterial_guess` (0x00483C3C), `UpdateItemSlot_guess`
(0x0048083A), `SwapFace_guess` (0x0047DEC4), `UpdateDAGPointers_guess` (0x0047D7A4).

## Floor and collision
`CDisplay::GetFloorHeight_guess` (0x00439F26) and the movement code in tu_055_Movement/tu_056_EQMovePlayer ask the collision
interface (0x0099E370) for the floor under a point. `DoMainLoop` treats a result of -1e27 as
"no floor" when placing the player on a boat (inferred from that test).

## What is not here
- The UI library draws windows and text with its own code (`CTextureFont`, `CXWndManager::DrawWindows`*), in
  the 0x0057.... - 0x0060.... range, not rewritten.
- Sound is not graphics: `EqSoundManager` (tu_037_EQ_SoundManager, ctor 0x0044CA8F, `pinstEQSoundManager` 0x00851390) has
  its own device objects. Its methods are named, and so are the tu_037_EQ_SoundManager views (`EqSoundManagerView_guess`,
  `EqMobileEmitterView_guess`).
- EQGraphicsDX9.dll itself is not part of this tree.
