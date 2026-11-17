// QUIRK: vc71q-class-layout-option
// KEYWORDS: layout, compiler diagnostic, internal option
// The undocumented class-layout report option is not recognized by this RTM compiler.
// FLAGS: /d1reportSingleClassLayout
// EXPECT: compile fails C1007
struct LayoutProbe { int member; };
int ReadMember(LayoutProbe* value) { return value->member; }
