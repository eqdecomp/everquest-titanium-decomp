// QUIRK: vc71q-gs-trigger
// KEYWORDS: /GS, security cookie, char array, stack
// Under /GS, an address-taken char array or a struct containing one gets a cookie check; an int array does not.
// CFLAGS: /GS
// EXPECT: ProbeCharArray has mov eax, dword ptr \[___security_cookie\]
// EXPECT: ProbeCharArray has call @__security_check_cookie@4
// EXPECT: ProbeIntArray lacks ___security_cookie|__security_check_cookie
// EXPECT: ProbeStructArray has call @__security_check_cookie@4
struct Holder { char bytes[16]; };
extern "C" void __cdecl Consume(void* p);
extern "C" void __cdecl ProbeCharArray() { char data[16]; Consume(data); }
extern "C" void __cdecl ProbeIntArray() { int data[16]; Consume(data); }
extern "C" void __cdecl ProbeStructArray() { Holder data; Consume(&data); }
