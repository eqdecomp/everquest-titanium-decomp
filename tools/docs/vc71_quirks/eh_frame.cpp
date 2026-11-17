// QUIRK: vc71q-eh-frame
// KEYWORDS: EH, exception frame, destructor, __EH_prolog, state
// With /GX, a destructible local alive across a call uses an EH handler symbol and __EH_prolog, then updates its state.
// VARIANTS: GX EHSC
// FLAGS@EHSC: /EHsc
// EXPECT: WithDtor has ^mov eax, __ehhandler\$.*\ncall __EH_prolog
// EXPECT: WithDtor has and dword ptr \[ebp - 4\], 0
// EXPECT: WithDtor has or dword ptr \[ebp - 4\], 0xffffffff
// EXPECT: WithDtor same GX EHSC
struct D { ~D(); };
extern int C();
int WithDtor() { D d; return C(); }
