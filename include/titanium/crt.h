/* C runtime of eqgame.exe (Titanium, statically linked VC7.1 /MT CRT) at its real addresses.
 *
 * The declarations are the toolchain's own CRT headers (included below), so names, linkage (extern "C",
 * nothrow under /GX) and types are exactly what the game's source saw. This file only adds the
 * `// EXTERNAL:` markers that tie each symbol to its VA in this binary. Names come from the Ghidra export
 * (FID) and from the code shape; the first-pass name list is wrong for CRT addresses: never
 * use it here (0x0060E450 is strcpy, not LoadSplashScreen; 0x0060D0D5 is operator delete, not EqGetTime).
 *
 * Use: call the CRT by its normal name (`strcpy(d, s)`, `delete p`, `new T[n]`) after
 * `#include "titanium/crt.h"`. Do not redeclare these functions in a TU that includes this file.
 */
#ifndef TITANIUM_CRT_H
#define TITANIUM_CRT_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#ifdef __cplusplus
#include <new>
#endif

/* ---- heap: operator new/delete and malloc/free ------------------------------------------------------
 * 0x0060D0D5 is `operator delete` (jmp free), 0x0060D682 `operator delete[]` (jmp operator delete),
 * 0x0060D071 `operator new`, 0x0060E985 `operator new[]` (jmp operator new). The game calls these through
 * `delete p` / scalar-deleting destructors (1,431 calls to 0x0060D0D5) and `new`; plain `free` is
 * 0x0060E07D (164 calls). <new> declares the array forms, so `new T[n]` / `delete[] p` give
 * ??_U / ??_V as in the original. All four are nothrow for /GX except operator new (bad_alloc). */
// EXTERNAL: TITANIUM 0x0060D071 ??2@YAPAXI@Z
// EXTERNAL: TITANIUM 0x0060E985 ??_U@YAPAXI@Z
// EXTERNAL: TITANIUM 0x0060D0D5 ??3@YAXPAX@Z
// EXTERNAL: TITANIUM 0x0060D682 ??_V@YAXPAX@Z
// EXTERNAL: TITANIUM 0x0060E07D free
// EXTERNAL: TITANIUM 0x0060F317 malloc
// EXTERNAL: TITANIUM 0x0060F0C3 realloc
// EXTERNAL: TITANIUM 0x00614837 calloc

/* ---- string.h ---------------------------------------------------------------------------------------- */
// EXTERNAL: TITANIUM 0x0060E450 strcpy
// EXTERNAL: TITANIUM 0x0060E460 strcat
// EXTERNAL: TITANIUM 0x0060E620 strncpy
// EXTERNAL: TITANIUM 0x006123B0 strncat
// EXTERNAL: TITANIUM 0x0060D970 strlen
// EXTERNAL: TITANIUM 0x0060ED40 strcmp
// EXTERNAL: TITANIUM 0x0060E550 strncmp
// EXTERNAL: TITANIUM 0x00621E9C _stricmp
// EXTERNAL: TITANIUM 0x0062202C _strnicmp
// EXTERNAL: TITANIUM 0x0060E590 strstr
// EXTERNAL: TITANIUM 0x0060F520 strchr
// EXTERNAL: TITANIUM 0x00612070 strrchr
// EXTERNAL: TITANIUM 0x00610380 strcspn
// EXTERNAL: TITANIUM 0x0061C080 strpbrk
// EXTERNAL: TITANIUM 0x00611F5B _strlwr
// EXTERNAL: TITANIUM 0x006243D0 _strrev
// EXTERNAL: TITANIUM 0x00623589 _strdup
// EXTERNAL: TITANIUM 0x00613345 strcoll
// EXTERNAL: TITANIUM 0x0060D750 memset
// EXTERNAL: TITANIUM 0x0060DA00 memcpy
// EXTERNAL: TITANIUM 0x0060DD40 memmove
// EXTERNAL: TITANIUM 0x0060D8B0 memcmp
// EXTERNAL: TITANIUM 0x0060FC70 memchr
// EXTERNAL: TITANIUM 0x00613208 wcscmp

/* ---- stdlib.h / ctype.h ------------------------------------------------------------------------------
 * 0x0060E3A3 is atoi (`jmp atol`, 237 calls); atol proper is 0x0060E31B (12 calls). */
// EXTERNAL: TITANIUM 0x0060E3A3 atoi
// EXTERNAL: TITANIUM 0x0060E31B atol
// EXTERNAL: TITANIUM 0x00611C30 atof
// EXTERNAL: TITANIUM 0x0060EC17 strtol
// EXTERNAL: TITANIUM 0x0060EC2E strtoul
// EXTERNAL: TITANIUM 0x006220E9 _itoa
// EXTERNAL: TITANIUM 0x00622113 _ltoa
// EXTERNAL: TITANIUM 0x0060EE40 qsort
// EXTERNAL: TITANIUM 0x0060F5EB rand
// EXTERNAL: TITANIUM 0x0060D890 atexit
// EXTERNAL: TITANIUM 0x00611848 exit
// EXTERNAL: TITANIUM 0x006216C4 abort
// EXTERNAL: TITANIUM 0x0060F3DC isdigit
// EXTERNAL: TITANIUM 0x0060F329 isalpha
// EXTERNAL: TITANIUM 0x0060F455 isspace
// EXTERNAL: TITANIUM 0x0060F416 isxdigit
// EXTERNAL: TITANIUM 0x0060F368 isupper
// EXTERNAL: TITANIUM 0x0060F3A2 islower
// EXTERNAL: TITANIUM 0x0060F48F isalnum
// EXTERNAL: TITANIUM 0x0060E963 toupper
// EXTERNAL: TITANIUM 0x00611F39 tolower

/* ---- stdio.h ----------------------------------------------------------------------------------------- */
// EXTERNAL: TITANIUM 0x0060D5EB sprintf
// EXTERNAL: TITANIUM 0x0060EA01 _snprintf
// EXTERNAL: TITANIUM 0x006125E1 vsprintf
// EXTERNAL: TITANIUM 0x0061323A _vsnprintf
// EXTERNAL: TITANIUM 0x00610837 sscanf
// EXTERNAL: TITANIUM 0x0060EC45 fprintf
// EXTERNAL: TITANIUM 0x0060E7E1 fscanf
// EXTERNAL: TITANIUM 0x0060E887 fopen
// EXTERNAL: TITANIUM 0x0060E790 fclose
// EXTERNAL: TITANIUM 0x00611D51 fread
// EXTERNAL: TITANIUM 0x006101BA fwrite
// EXTERNAL: TITANIUM 0x0060FBE1 fgets
// EXTERNAL: TITANIUM 0x00610063 fgetc
// EXTERNAL: TITANIUM 0x00610206 fputc
// EXTERNAL: TITANIUM 0x0061030F fseek
// EXTERNAL: TITANIUM 0x00612D7F ftell
// EXTERNAL: TITANIUM 0x0060FF59 fflush

/* ---- math.h / time.h --------------------------------------------------------------------------------- */
// EXTERNAL: TITANIUM 0x0060F60D fabs
// EXTERNAL: TITANIUM 0x006126B0 pow
// EXTERNAL: TITANIUM 0x0060ECBC time
// EXTERNAL: TITANIUM 0x0060ECA3 ctime
// EXTERNAL: TITANIUM 0x00612227 localtime
// EXTERNAL: TITANIUM 0x0061D79D gmtime
// EXTERNAL: TITANIUM 0x00612DC0 asctime
// EXTERNAL: TITANIUM 0x00613FB7 strftime

/* ---- compiler-generated references (never call or declare these yourself) ----------------------------
 * __EH_prolog 0x0060D5A8, __security_check_cookie 0x0060D674, __ftol2 0x0060E98C and __CxxFrameHandler
 * 0x0060D163 are mapped by tests/unicorn/crt_defaults.json: a destructible local across a call, a char
 * buffer (/GS), a float->int cast and an EH frame produce them. The markers below cover the other
 * helpers the compiler emits: `delete[]` / `new[]` of class arrays (eh vector iterators), `throw`,
 * frames over 4 KB (_chkstk) and 64-bit arithmetic. */
// EXTERNAL: TITANIUM 0x0060D6E5 ??_M@YGXPAXIHP6EX0@Z@Z
// EXTERNAL: TITANIUM 0x0060E2B9 ??_L@YGXPAXIHP6EX0@Z1@Z
// EXTERNAL: TITANIUM 0x0060E27F _CxxThrowException
// EXTERNAL: TITANIUM 0x0060ED00 _chkstk
// EXTERNAL: TITANIUM 0x0060F830 _allmul
// EXTERNAL: TITANIUM 0x0060F930 _alldiv
// EXTERNAL: TITANIUM 0x0060F870 _allrem
// EXTERNAL: TITANIUM 0x00618C40 _aulldiv
// EXTERNAL: TITANIUM 0x00614BC0 _allshr

#endif /* TITANIUM_CRT_H */
