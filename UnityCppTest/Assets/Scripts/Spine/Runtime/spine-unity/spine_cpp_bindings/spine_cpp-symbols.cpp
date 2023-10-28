#include <spine/spine.h>
#include <spine/dll.h>
#include <new>

bool operator==(const class spine::String&, const class spine::String&);
bool (*_0)(const class spine::String&, const class spine::String&) = &spine::operator==;
bool operator!=(const class spine::String&, const class spine::String&);
bool (*_1)(const class spine::String&, const class spine::String&) = &spine::operator!=;
extern "C" __declspec(dllexport) void c__N_spine_S_Polygon_Polygon(void* __instance) { ::new (__instance) spine::Polygon(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Polygon_Polygon___1__N_spine_S_Polygon(void* __instance, const spine::Polygon& _0) { ::new (__instance) spine::Polygon(_0); }
class spine::Polygon& (spine::Polygon::*_2)(class spine::Polygon&&) = &spine::Polygon::operator=;
