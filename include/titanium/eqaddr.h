/* Fixed-address declarations for the Titanium client and COFF match builds. */
#ifndef TITANIUM_EQADDR_H
#define TITANIUM_EQADDR_H

#ifdef EQD_MATCH
#define EQD_FUNCTION(va) eqd_fn_##va
#define EQD_DATA(va) (&eqd_va_##va)
#else
#define EQD_FUNCTION(va) (va)
#define EQD_DATA(va) (va)
#endif

#define EQ_GLOBAL(type, va) (*(type *)EQD_DATA(va))
#define EQ_ARRAY(type, va) ((type *)EQD_DATA(va))
#define EQ_CALL(ret, conv, va, params) ((ret (conv *) params)EQD_FUNCTION(va))
#define EQ_CDECL(ret, va, params) EQ_CALL(ret, __cdecl, va, params)
#define EQ_STDCALL(ret, va, params) EQ_CALL(ret, __stdcall, va, params)
#define EQ_FASTCALL(ret, va, params) EQ_CALL(ret, __fastcall, va, params)
/* C-compatible thiscall: params begins with (this_type, int), and callers pass (this, 0, ...). */
#define EQ_THISCALL(ret, va, params) EQ_CALL(ret, __fastcall, va, params)

#ifdef __cplusplus
template<class R> struct eqd_ret { typedef R type; };
template<> struct eqd_ret<void> { typedef int type; };

/* Declared-only member functions let EQ_METHOD emit thiscall without a reserved keyword. */
template<unsigned VA, class R, class T> struct eqd_tc0 { typename eqd_ret<R>::type m(); };
#define EQD_P0(t) t
template<unsigned VA, class R, class T, class A1> struct eqd_tc1 { typename eqd_ret<R>::type m(A1); };
#define EQD_P1(t, a1) t, a1
template<unsigned VA, class R, class T, class A1, class A2> struct eqd_tc2 { typename eqd_ret<R>::type m(A1, A2); };
#define EQD_P2(t, a1, a2) t, a1, a2
template<unsigned VA, class R, class T, class A1, class A2, class A3> struct eqd_tc3 { typename eqd_ret<R>::type m(A1, A2, A3); };
#define EQD_P3(t, a1, a2, a3) t, a1, a2, a3
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4> struct eqd_tc4 { typename eqd_ret<R>::type m(A1, A2, A3, A4); };
#define EQD_P4(t, a1, a2, a3, a4) t, a1, a2, a3, a4
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5> struct eqd_tc5 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5); };
#define EQD_P5(t, a1, a2, a3, a4, a5) t, a1, a2, a3, a4, a5
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6> struct eqd_tc6 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6); };
#define EQD_P6(t, a1, a2, a3, a4, a5, a6) t, a1, a2, a3, a4, a5, a6
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7> struct eqd_tc7 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7); };
#define EQD_P7(t, a1, a2, a3, a4, a5, a6, a7) t, a1, a2, a3, a4, a5, a6, a7
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8> struct eqd_tc8 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8); };
#define EQD_P8(t, a1, a2, a3, a4, a5, a6, a7, a8) t, a1, a2, a3, a4, a5, a6, a7, a8
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9> struct eqd_tc9 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9); };
#define EQD_P9(t, a1, a2, a3, a4, a5, a6, a7, a8, a9) t, a1, a2, a3, a4, a5, a6, a7, a8, a9
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10> struct eqd_tc10 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10); };
#define EQD_P10(t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10) t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11> struct eqd_tc11 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11); };
#define EQD_P11(t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11) t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12> struct eqd_tc12 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12); };
#define EQD_P12(t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12) t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13> struct eqd_tc13 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13); };
#define EQD_P13(t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13) t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13
template<unsigned VA, class R, class T, class A1, class A2, class A3, class A4, class A5, class A6, class A7, class A8, class A9, class A10, class A11, class A12, class A13, class A14> struct eqd_tc14 { typename eqd_ret<R>::type m(A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14); };
#define EQD_P14(t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14) t, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14
#define EQ_METHOD(n, ret, va, params, object) ((eqd_tc##n<va, ret, EQD_P##n params> *)(object))->m
#endif

#endif /* TITANIUM_EQADDR_H */

