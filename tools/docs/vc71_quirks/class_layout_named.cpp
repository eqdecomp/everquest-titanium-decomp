// QUIRK: vc71q-class-layout-option
// KEYWORDS: layout, compiler diagnostic, internal option
// Naming a class on the undocumented class-layout report option also fails in this RTM compiler.
// FLAGS: /d1reportSingleClassLayout:LayoutProbe
// EXPECT: compile fails C1007
struct LayoutProbe { int member; };
int ReadMember(LayoutProbe* value) { return value->member; }
