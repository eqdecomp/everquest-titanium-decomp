/* include/titanium/layouts/geometry.h: the UI's 8-byte point (no methods, no VA tokens).
 * CXRect stays in core_decls.h: editing that header raised tu_044 ExecuteCmd (0x004619CD) structural ndiff 799 -> 800. */
#ifndef TITANIUM_LAYOUTS_GEOMETRY_H
#define TITANIUM_LAYOUTS_GEOMETRY_H

/* 8-byte point (MQ2 CXPoint), screen coordinates */
struct CXPoint {
    int x, y;
};

#endif
