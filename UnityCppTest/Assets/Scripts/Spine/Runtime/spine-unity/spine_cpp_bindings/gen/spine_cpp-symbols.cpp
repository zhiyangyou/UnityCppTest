#include <spine/spine.h>
#include <spine/dll.h>
#include <SpineMesh.h>
#include <SpineCppAdapterCore.h>
#include <SkeletonRendererInstruction.h>
#include <MeshRendererBuffers.h>
#include <MeshGenerator.h>
#include <new>

extern "C" __declspec(dllexport) void c__N_spine_S_DefaultSpineExtension_DefaultSpineExtension___1__N_spine_S_DefaultSpineExtension(void* __instance, const spine::DefaultSpineExtension& _0) { ::new (__instance) spine::DefaultSpineExtension(_0); }
class spine::DefaultSpineExtension& (spine::DefaultSpineExtension::*_0)(const class spine::DefaultSpineExtension&) = &spine::DefaultSpineExtension::operator=;
char* (*_1)(const class spine::String&, int*) = &spine::SpineExtension::readFile;
class spine::SpineExtension& (spine::SpineExtension::*_2)(const class spine::SpineExtension&) = &spine::SpineExtension::operator=;
class c__N_spine_S_SpineExtension_SpineExtension___1__N_spine_S_SpineExtensionSpineExtension : public spine::SpineExtension { public: c__N_spine_S_SpineExtension_SpineExtension___1__N_spine_S_SpineExtensionSpineExtension(const spine::SpineExtension& _0): spine::SpineExtension(_0) {}; void* _alloc(unsigned long long, const char*, int) { return {}; } void* _calloc(unsigned long long, const char*, int) { return {}; } void* _realloc(void*, unsigned long long, const char*, int) { return {}; } void _free(void*, const char*, int) {} char* _readFile(const spine::String&, int*) { return {}; }  };
extern "C" __declspec(dllexport) void c__N_spine_S_SpineExtension_SpineExtension___1__N_spine_S_SpineExtension(void* __instance, const spine::SpineExtension& _0) { ::new (__instance) c__N_spine_S_SpineExtension_SpineExtension___1__N_spine_S_SpineExtensionSpineExtension(_0); }
class spine::SpineObject& (spine::SpineObject::*_3)(const class spine::SpineObject&) = &spine::SpineObject::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_SpineObject_SpineObject(void* __instance) { ::new (__instance) spine::SpineObject(); }
extern "C" __declspec(dllexport) void c__N_spine_S_SpineObject_SpineObject___1__N_spine_S_SpineObject(void* __instance, const spine::SpineObject& _0) { ::new (__instance) spine::SpineObject(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_String_String(void* __instance) { ::new (__instance) spine::String(); }
extern "C" __declspec(dllexport) void c__N_spine_S_String_String__1C_b_b(void* __instance, const char* chars, bool own, bool tofree) { ::new (__instance) spine::String(chars, own, tofree); }
extern "C" __declspec(dllexport) void c__N_spine_S_String_String___1__N_spine_S_String(void* __instance, const spine::String& other) { ::new (__instance) spine::String(other); }
extern "C" __declspec(dllexport) void c__N_spine_S_String_String__v(void* __instance, void* pOther) { ::new (__instance) spine::String(pOther); }
unsigned long long (spine::String::*_4)() const = &spine::String::length;
bool (spine::String::*_5)() const = &spine::String::isEmpty;
const char* (spine::String::*_6)() const = &spine::String::buffer;
void (spine::String::*_7)(const class spine::String&) = &spine::String::own;
void (spine::String::*_8)(const char*) = &spine::String::own;
void (spine::String::*_9)() = &spine::String::unown;
class spine::String& (spine::String::*_10)(const class spine::String&) = &spine::String::operator=;
class spine::String& (spine::String::*_11)(const char*) = &spine::String::operator=;
class spine::String& (spine::String::*_12)(const char*) = &spine::String::append;
class spine::String& (spine::String::*_13)(const class spine::String&) = &spine::String::append;
class spine::String& (spine::String::*_14)(int) = &spine::String::append;
class spine::String& (spine::String::*_15)(float) = &spine::String::append;
bool (spine::String::*_16)(const class spine::String&) = &spine::String::startsWith;
bool operator==(const class spine::String&, const class spine::String&);
bool (*_17)(const class spine::String&, const class spine::String&) = &spine::operator==;
bool operator!=(const class spine::String&, const class spine::String&);
bool (*_18)(const class spine::String&, const class spine::String&) = &spine::operator!=;
template __declspec(dllexport) spine::Vector<long long>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__K_F_Vector___1__N_spine_S_Vector__K(void* __instance, const spine::Vector<long long>& inVector) { ::new (__instance) spine::Vector<long long>(inVector); }
void (spine::Vector<long long>::*_19)() = &spine::Vector<long long>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<long long>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<long long>::size() const;
template __declspec(dllexport) void spine::Vector<long long>::setSize(unsigned long long, const long long&);
template __declspec(dllexport) void spine::Vector<long long>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<long long>::add(const long long&);
template __declspec(dllexport) void spine::Vector<long long>::addAll(spine::Vector<long long>&);
template __declspec(dllexport) void spine::Vector<long long>::clearAndAddAll(spine::Vector<long long>&);
template __declspec(dllexport) void spine::Vector<long long>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<long long>::contains(const long long&);
template __declspec(dllexport) int spine::Vector<long long>::indexOf(const long long&);
long long& (spine::Vector<long long>::*_20)(unsigned long long) = &spine::Vector<long long>::operator[];
template __declspec(dllexport) long long* spine::Vector<long long>::buffer();
template __declspec(dllexport) void* spine::Vector<long long>::voidPBuffer();
spine::Vector<long long>& (spine::Vector<long long>::*_21)(const spine::Vector<long long>&) = &spine::Vector<long long>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__f_F_Vector(void* __instance) { ::new (__instance) spine::Vector<float>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__f_F_Vector___1__N_spine_S_Vector__f(void* __instance, const spine::Vector<float>& inVector) { ::new (__instance) spine::Vector<float>(inVector); }
void (spine::Vector<float>::*_22)() = &spine::Vector<float>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<float>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<float>::size() const;
template __declspec(dllexport) void spine::Vector<float>::setSize(unsigned long long, const float&);
void (spine::Vector<float>::*_23)(unsigned long long) = &spine::Vector<float>::ensureCapacity;
template __declspec(dllexport) void spine::Vector<float>::add(const float&);
template __declspec(dllexport) void spine::Vector<float>::addAll(spine::Vector<float>&);
template __declspec(dllexport) void spine::Vector<float>::clearAndAddAll(spine::Vector<float>&);
template __declspec(dllexport) void spine::Vector<float>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<float>::contains(const float&);
template __declspec(dllexport) int spine::Vector<float>::indexOf(const float&);
float& (spine::Vector<float>::*_24)(unsigned long long) = &spine::Vector<float>::operator[];
template __declspec(dllexport) float* spine::Vector<float>::buffer();
template __declspec(dllexport) void* spine::Vector<float>::voidPBuffer();
spine::Vector<float>& (spine::Vector<float>::*_25)(const spine::Vector<float>&) = &spine::Vector<float>::operator=;
template __declspec(dllexport) spine::Vector<spine::BoneData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_BoneData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::BoneData*>& inVector) { ::new (__instance) spine::Vector<spine::BoneData*>(inVector); }
void (spine::Vector<spine::BoneData*>::*_26)() = &spine::Vector<spine::BoneData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::BoneData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::BoneData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::setSize(unsigned long long, spine::BoneData* const&);
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::add(spine::BoneData* const&);
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::addAll(spine::Vector<spine::BoneData*>&);
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::clearAndAddAll(spine::Vector<spine::BoneData*>&);
template __declspec(dllexport) void spine::Vector<spine::BoneData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::BoneData*>::contains(spine::BoneData* const&);
template __declspec(dllexport) int spine::Vector<spine::BoneData*>::indexOf(spine::BoneData* const&);
class spine::BoneData*& (spine::Vector<spine::BoneData*>::*_27)(unsigned long long) = &spine::Vector<spine::BoneData*>::operator[];
template __declspec(dllexport) spine::BoneData** spine::Vector<spine::BoneData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::BoneData*>::voidPBuffer();
spine::Vector<class spine::BoneData*>& (spine::Vector<spine::BoneData*>::*_28)(const spine::Vector<class spine::BoneData*>&) = &spine::Vector<spine::BoneData*>::operator=;
template __declspec(dllexport) spine::Vector<spine::SlotData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_SlotData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::SlotData*>& inVector) { ::new (__instance) spine::Vector<spine::SlotData*>(inVector); }
void (spine::Vector<spine::SlotData*>::*_29)() = &spine::Vector<spine::SlotData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::SlotData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::SlotData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::setSize(unsigned long long, spine::SlotData* const&);
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::add(spine::SlotData* const&);
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::addAll(spine::Vector<spine::SlotData*>&);
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::clearAndAddAll(spine::Vector<spine::SlotData*>&);
template __declspec(dllexport) void spine::Vector<spine::SlotData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::SlotData*>::contains(spine::SlotData* const&);
template __declspec(dllexport) int spine::Vector<spine::SlotData*>::indexOf(spine::SlotData* const&);
class spine::SlotData*& (spine::Vector<spine::SlotData*>::*_30)(unsigned long long) = &spine::Vector<spine::SlotData*>::operator[];
template __declspec(dllexport) spine::SlotData** spine::Vector<spine::SlotData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::SlotData*>::voidPBuffer();
spine::Vector<class spine::SlotData*>& (spine::Vector<spine::SlotData*>::*_31)(const spine::Vector<class spine::SlotData*>&) = &spine::Vector<spine::SlotData*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Skin*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Skin_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Skin*>& inVector) { ::new (__instance) spine::Vector<spine::Skin*>(inVector); }
void (spine::Vector<spine::Skin*>::*_32)() = &spine::Vector<spine::Skin*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Skin*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Skin*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Skin*>::setSize(unsigned long long, spine::Skin* const&);
template __declspec(dllexport) void spine::Vector<spine::Skin*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Skin*>::add(spine::Skin* const&);
template __declspec(dllexport) void spine::Vector<spine::Skin*>::addAll(spine::Vector<spine::Skin*>&);
template __declspec(dllexport) void spine::Vector<spine::Skin*>::clearAndAddAll(spine::Vector<spine::Skin*>&);
template __declspec(dllexport) void spine::Vector<spine::Skin*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Skin*>::contains(spine::Skin* const&);
template __declspec(dllexport) int spine::Vector<spine::Skin*>::indexOf(spine::Skin* const&);
class spine::Skin*& (spine::Vector<spine::Skin*>::*_33)(unsigned long long) = &spine::Vector<spine::Skin*>::operator[];
template __declspec(dllexport) spine::Skin** spine::Vector<spine::Skin*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Skin*>::voidPBuffer();
spine::Vector<class spine::Skin*>& (spine::Vector<spine::Skin*>::*_34)(const spine::Vector<class spine::Skin*>&) = &spine::Vector<spine::Skin*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Vector<spine::SkinEntry>>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_Vector____N_spine_S_SkinEntry_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Vector<spine::SkinEntry>>& inVector) { ::new (__instance) spine::Vector<spine::Vector<spine::SkinEntry>>(inVector); }
void (spine::Vector<spine::Vector<spine::SkinEntry>>::*_35)() = &spine::Vector<spine::Vector<spine::SkinEntry>>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<spine::SkinEntry>>::getCapacity() const;
unsigned long long (spine::Vector<spine::Vector<spine::SkinEntry>>::*_36)() const = &spine::Vector<spine::Vector<spine::SkinEntry>>::size;
template __declspec(dllexport) spine::Vector<spine::SkinEntry>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_SkinEntry_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::SkinEntry>& inVector) { ::new (__instance) spine::Vector<spine::SkinEntry>(inVector); }
void (spine::Vector<spine::SkinEntry>::*_37)() = &spine::Vector<spine::SkinEntry>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::SkinEntry>::getCapacity() const;
unsigned long long (spine::Vector<spine::SkinEntry>::*_38)() const = &spine::Vector<spine::SkinEntry>::size;
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::setSize(unsigned long long, const spine::SkinEntry&);
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::add(const spine::SkinEntry&);
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::addAll(spine::Vector<spine::SkinEntry>&);
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::clearAndAddAll(spine::Vector<spine::SkinEntry>&);
template __declspec(dllexport) void spine::Vector<spine::SkinEntry>::removeAt(unsigned long long);
struct spine::SkinEntry& (spine::Vector<spine::SkinEntry>::*_39)(unsigned long long) = &spine::Vector<spine::SkinEntry>::operator[];
template __declspec(dllexport) spine::SkinEntry* spine::Vector<spine::SkinEntry>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::SkinEntry>::voidPBuffer();
spine::Vector<struct spine::SkinEntry>& (spine::Vector<spine::SkinEntry>::*_40)(const spine::Vector<struct spine::SkinEntry>&) = &spine::Vector<spine::SkinEntry>::operator=;
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::setSize(unsigned long long, const spine::Vector<spine::SkinEntry>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::add(const spine::Vector<spine::SkinEntry>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::addAll(spine::Vector<spine::Vector<spine::SkinEntry>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::clearAndAddAll(spine::Vector<spine::Vector<spine::SkinEntry>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<spine::SkinEntry>>::removeAt(unsigned long long);
spine::Vector<struct spine::SkinEntry>& (spine::Vector<spine::Vector<spine::SkinEntry>>::*_41)(unsigned long long) = &spine::Vector<spine::Vector<spine::SkinEntry>>::operator[];
template __declspec(dllexport) spine::Vector<spine::SkinEntry>* spine::Vector<spine::Vector<spine::SkinEntry>>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Vector<spine::SkinEntry>>::voidPBuffer();
spine::Vector<spine::Vector<struct spine::SkinEntry>>& (spine::Vector<spine::Vector<spine::SkinEntry>>::*_42)(const spine::Vector<spine::Vector<struct spine::SkinEntry>>&) = &spine::Vector<spine::Vector<spine::SkinEntry>>::operator=;
template __declspec(dllexport) spine::Vector<spine::ConstraintData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_ConstraintData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::ConstraintData*>& inVector) { ::new (__instance) spine::Vector<spine::ConstraintData*>(inVector); }
void (spine::Vector<spine::ConstraintData*>::*_43)() = &spine::Vector<spine::ConstraintData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::ConstraintData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::ConstraintData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::setSize(unsigned long long, spine::ConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::add(spine::ConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::addAll(spine::Vector<spine::ConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::clearAndAddAll(spine::Vector<spine::ConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::ConstraintData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::ConstraintData*>::contains(spine::ConstraintData* const&);
template __declspec(dllexport) int spine::Vector<spine::ConstraintData*>::indexOf(spine::ConstraintData* const&);
class spine::ConstraintData*& (spine::Vector<spine::ConstraintData*>::*_44)(unsigned long long) = &spine::Vector<spine::ConstraintData*>::operator[];
template __declspec(dllexport) spine::ConstraintData** spine::Vector<spine::ConstraintData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::ConstraintData*>::voidPBuffer();
spine::Vector<class spine::ConstraintData*>& (spine::Vector<spine::ConstraintData*>::*_45)(const spine::Vector<class spine::ConstraintData*>&) = &spine::Vector<spine::ConstraintData*>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_String_F_Vector(void* __instance) { ::new (__instance) spine::Vector<spine::String>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_String_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::String>& inVector) { ::new (__instance) spine::Vector<spine::String>(inVector); }
void (spine::Vector<spine::String>::*_46)() = &spine::Vector<spine::String>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::String>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::String>::size() const;
template __declspec(dllexport) void spine::Vector<spine::String>::setSize(unsigned long long, const spine::String&);
template __declspec(dllexport) void spine::Vector<spine::String>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::String>::add(const spine::String&);
template __declspec(dllexport) void spine::Vector<spine::String>::addAll(spine::Vector<spine::String>&);
template __declspec(dllexport) void spine::Vector<spine::String>::clearAndAddAll(spine::Vector<spine::String>&);
template __declspec(dllexport) void spine::Vector<spine::String>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::String>::contains(const spine::String&);
template __declspec(dllexport) int spine::Vector<spine::String>::indexOf(const spine::String&);
class spine::String& (spine::Vector<spine::String>::*_47)(unsigned long long) = &spine::Vector<spine::String>::operator[];
template __declspec(dllexport) spine::String* spine::Vector<spine::String>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::String>::voidPBuffer();
spine::Vector<class spine::String>& (spine::Vector<spine::String>::*_48)(const spine::Vector<class spine::String>&) = &spine::Vector<spine::String>::operator=;
template __declspec(dllexport) spine::Vector<spine::Attachment*>::Vector();
template __declspec(dllexport) spine::Vector<spine::Attachment*>::Vector(const spine::Vector<spine::Attachment*>&);
void (spine::Vector<spine::Attachment*>::*_49)() = &spine::Vector<spine::Attachment*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Attachment*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Attachment*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::setSize(unsigned long long, spine::Attachment* const&);
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::add(spine::Attachment* const&);
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::addAll(spine::Vector<spine::Attachment*>&);
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::clearAndAddAll(spine::Vector<spine::Attachment*>&);
template __declspec(dllexport) void spine::Vector<spine::Attachment*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Attachment*>::contains(spine::Attachment* const&);
template __declspec(dllexport) int spine::Vector<spine::Attachment*>::indexOf(spine::Attachment* const&);
class spine::Attachment*& (spine::Vector<spine::Attachment*>::*_50)(unsigned long long) = &spine::Vector<spine::Attachment*>::operator[];
template __declspec(dllexport) spine::Attachment** spine::Vector<spine::Attachment*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Attachment*>::voidPBuffer();
spine::Vector<class spine::Attachment*>& (spine::Vector<spine::Attachment*>::*_51)(const spine::Vector<class spine::Attachment*>&) = &spine::Vector<spine::Attachment*>::operator=;
template __declspec(dllexport) spine::Vector<spine::EventData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_EventData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::EventData*>& inVector) { ::new (__instance) spine::Vector<spine::EventData*>(inVector); }
void (spine::Vector<spine::EventData*>::*_52)() = &spine::Vector<spine::EventData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::EventData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::EventData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::EventData*>::setSize(unsigned long long, spine::EventData* const&);
template __declspec(dllexport) void spine::Vector<spine::EventData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::EventData*>::add(spine::EventData* const&);
template __declspec(dllexport) void spine::Vector<spine::EventData*>::addAll(spine::Vector<spine::EventData*>&);
template __declspec(dllexport) void spine::Vector<spine::EventData*>::clearAndAddAll(spine::Vector<spine::EventData*>&);
template __declspec(dllexport) void spine::Vector<spine::EventData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::EventData*>::contains(spine::EventData* const&);
template __declspec(dllexport) int spine::Vector<spine::EventData*>::indexOf(spine::EventData* const&);
class spine::EventData*& (spine::Vector<spine::EventData*>::*_53)(unsigned long long) = &spine::Vector<spine::EventData*>::operator[];
template __declspec(dllexport) spine::EventData** spine::Vector<spine::EventData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::EventData*>::voidPBuffer();
spine::Vector<class spine::EventData*>& (spine::Vector<spine::EventData*>::*_54)(const spine::Vector<class spine::EventData*>&) = &spine::Vector<spine::EventData*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Animation*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Animation_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Animation*>& inVector) { ::new (__instance) spine::Vector<spine::Animation*>(inVector); }
void (spine::Vector<spine::Animation*>::*_55)() = &spine::Vector<spine::Animation*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Animation*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Animation*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Animation*>::setSize(unsigned long long, spine::Animation* const&);
template __declspec(dllexport) void spine::Vector<spine::Animation*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Animation*>::add(spine::Animation* const&);
template __declspec(dllexport) void spine::Vector<spine::Animation*>::addAll(spine::Vector<spine::Animation*>&);
template __declspec(dllexport) void spine::Vector<spine::Animation*>::clearAndAddAll(spine::Vector<spine::Animation*>&);
template __declspec(dllexport) void spine::Vector<spine::Animation*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Animation*>::contains(spine::Animation* const&);
template __declspec(dllexport) int spine::Vector<spine::Animation*>::indexOf(spine::Animation* const&);
class spine::Animation*& (spine::Vector<spine::Animation*>::*_56)(unsigned long long) = &spine::Vector<spine::Animation*>::operator[];
template __declspec(dllexport) spine::Animation** spine::Vector<spine::Animation*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Animation*>::voidPBuffer();
spine::Vector<class spine::Animation*>& (spine::Vector<spine::Animation*>::*_57)(const spine::Vector<class spine::Animation*>&) = &spine::Vector<spine::Animation*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Timeline*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Timeline_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Timeline*>& inVector) { ::new (__instance) spine::Vector<spine::Timeline*>(inVector); }
void (spine::Vector<spine::Timeline*>::*_58)() = &spine::Vector<spine::Timeline*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Timeline*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Timeline*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::setSize(unsigned long long, spine::Timeline* const&);
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::add(spine::Timeline* const&);
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::addAll(spine::Vector<spine::Timeline*>&);
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::clearAndAddAll(spine::Vector<spine::Timeline*>&);
template __declspec(dllexport) void spine::Vector<spine::Timeline*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Timeline*>::contains(spine::Timeline* const&);
template __declspec(dllexport) int spine::Vector<spine::Timeline*>::indexOf(spine::Timeline* const&);
class spine::Timeline*& (spine::Vector<spine::Timeline*>::*_59)(unsigned long long) = &spine::Vector<spine::Timeline*>::operator[];
template __declspec(dllexport) spine::Timeline** spine::Vector<spine::Timeline*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Timeline*>::voidPBuffer();
spine::Vector<class spine::Timeline*>& (spine::Vector<spine::Timeline*>::*_60)(const spine::Vector<class spine::Timeline*>&) = &spine::Vector<spine::Timeline*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Event*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Event_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Event*>& inVector) { ::new (__instance) spine::Vector<spine::Event*>(inVector); }
void (spine::Vector<spine::Event*>::*_61)() = &spine::Vector<spine::Event*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Event*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Event*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Event*>::setSize(unsigned long long, spine::Event* const&);
template __declspec(dllexport) void spine::Vector<spine::Event*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Event*>::add(spine::Event* const&);
template __declspec(dllexport) void spine::Vector<spine::Event*>::addAll(spine::Vector<spine::Event*>&);
template __declspec(dllexport) void spine::Vector<spine::Event*>::clearAndAddAll(spine::Vector<spine::Event*>&);
template __declspec(dllexport) void spine::Vector<spine::Event*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Event*>::contains(spine::Event* const&);
template __declspec(dllexport) int spine::Vector<spine::Event*>::indexOf(spine::Event* const&);
class spine::Event*& (spine::Vector<spine::Event*>::*_62)(unsigned long long) = &spine::Vector<spine::Event*>::operator[];
template __declspec(dllexport) spine::Event** spine::Vector<spine::Event*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Event*>::voidPBuffer();
spine::Vector<class spine::Event*>& (spine::Vector<spine::Event*>::*_63)(const spine::Vector<class spine::Event*>&) = &spine::Vector<spine::Event*>::operator=;
template __declspec(dllexport) spine::Vector<spine::IkConstraintData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_IkConstraintData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::IkConstraintData*>& inVector) { ::new (__instance) spine::Vector<spine::IkConstraintData*>(inVector); }
void (spine::Vector<spine::IkConstraintData*>::*_64)() = &spine::Vector<spine::IkConstraintData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::IkConstraintData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::IkConstraintData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::setSize(unsigned long long, spine::IkConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::add(spine::IkConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::addAll(spine::Vector<spine::IkConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::clearAndAddAll(spine::Vector<spine::IkConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraintData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::IkConstraintData*>::contains(spine::IkConstraintData* const&);
template __declspec(dllexport) int spine::Vector<spine::IkConstraintData*>::indexOf(spine::IkConstraintData* const&);
class spine::IkConstraintData*& (spine::Vector<spine::IkConstraintData*>::*_65)(unsigned long long) = &spine::Vector<spine::IkConstraintData*>::operator[];
template __declspec(dllexport) spine::IkConstraintData** spine::Vector<spine::IkConstraintData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::IkConstraintData*>::voidPBuffer();
spine::Vector<class spine::IkConstraintData*>& (spine::Vector<spine::IkConstraintData*>::*_66)(const spine::Vector<class spine::IkConstraintData*>&) = &spine::Vector<spine::IkConstraintData*>::operator=;
template __declspec(dllexport) spine::Vector<spine::TransformConstraintData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_TransformConstraintData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::TransformConstraintData*>& inVector) { ::new (__instance) spine::Vector<spine::TransformConstraintData*>(inVector); }
void (spine::Vector<spine::TransformConstraintData*>::*_67)() = &spine::Vector<spine::TransformConstraintData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TransformConstraintData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TransformConstraintData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::setSize(unsigned long long, spine::TransformConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::add(spine::TransformConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::addAll(spine::Vector<spine::TransformConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::clearAndAddAll(spine::Vector<spine::TransformConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraintData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::TransformConstraintData*>::contains(spine::TransformConstraintData* const&);
template __declspec(dllexport) int spine::Vector<spine::TransformConstraintData*>::indexOf(spine::TransformConstraintData* const&);
class spine::TransformConstraintData*& (spine::Vector<spine::TransformConstraintData*>::*_68)(unsigned long long) = &spine::Vector<spine::TransformConstraintData*>::operator[];
template __declspec(dllexport) spine::TransformConstraintData** spine::Vector<spine::TransformConstraintData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::TransformConstraintData*>::voidPBuffer();
spine::Vector<class spine::TransformConstraintData*>& (spine::Vector<spine::TransformConstraintData*>::*_69)(const spine::Vector<class spine::TransformConstraintData*>&) = &spine::Vector<spine::TransformConstraintData*>::operator=;
template __declspec(dllexport) spine::Vector<spine::PathConstraintData*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_PathConstraintData_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::PathConstraintData*>& inVector) { ::new (__instance) spine::Vector<spine::PathConstraintData*>(inVector); }
void (spine::Vector<spine::PathConstraintData*>::*_70)() = &spine::Vector<spine::PathConstraintData*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::PathConstraintData*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::PathConstraintData*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::setSize(unsigned long long, spine::PathConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::add(spine::PathConstraintData* const&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::addAll(spine::Vector<spine::PathConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::clearAndAddAll(spine::Vector<spine::PathConstraintData*>&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraintData*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::PathConstraintData*>::contains(spine::PathConstraintData* const&);
template __declspec(dllexport) int spine::Vector<spine::PathConstraintData*>::indexOf(spine::PathConstraintData* const&);
class spine::PathConstraintData*& (spine::Vector<spine::PathConstraintData*>::*_71)(unsigned long long) = &spine::Vector<spine::PathConstraintData*>::operator[];
template __declspec(dllexport) spine::PathConstraintData** spine::Vector<spine::PathConstraintData*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::PathConstraintData*>::voidPBuffer();
spine::Vector<class spine::PathConstraintData*>& (spine::Vector<spine::PathConstraintData*>::*_72)(const spine::Vector<class spine::PathConstraintData*>&) = &spine::Vector<spine::PathConstraintData*>::operator=;
template __declspec(dllexport) spine::Vector<char*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector___C_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<char*>& inVector) { ::new (__instance) spine::Vector<char*>(inVector); }
void (spine::Vector<char*>::*_73)() = &spine::Vector<char*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<char*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<char*>::size() const;
template __declspec(dllexport) void spine::Vector<char*>::setSize(unsigned long long, char* const&);
template __declspec(dllexport) void spine::Vector<char*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<char*>::add(char* const&);
template __declspec(dllexport) void spine::Vector<char*>::addAll(spine::Vector<char*>&);
template __declspec(dllexport) void spine::Vector<char*>::clearAndAddAll(spine::Vector<char*>&);
template __declspec(dllexport) void spine::Vector<char*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<char*>::contains(char* const&);
template __declspec(dllexport) int spine::Vector<char*>::indexOf(char* const&);
char*& (spine::Vector<char*>::*_74)(unsigned long long) = &spine::Vector<char*>::operator[];
template __declspec(dllexport) char** spine::Vector<char*>::buffer();
template __declspec(dllexport) void* spine::Vector<char*>::voidPBuffer();
spine::Vector<char*>& (spine::Vector<char*>::*_75)(const spine::Vector<char*>&) = &spine::Vector<char*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Bone*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Bone_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Bone*>& inVector) { ::new (__instance) spine::Vector<spine::Bone*>(inVector); }
void (spine::Vector<spine::Bone*>::*_76)() = &spine::Vector<spine::Bone*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Bone*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Bone*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Bone*>::setSize(unsigned long long, spine::Bone* const&);
template __declspec(dllexport) void spine::Vector<spine::Bone*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Bone*>::add(spine::Bone* const&);
template __declspec(dllexport) void spine::Vector<spine::Bone*>::addAll(spine::Vector<spine::Bone*>&);
template __declspec(dllexport) void spine::Vector<spine::Bone*>::clearAndAddAll(spine::Vector<spine::Bone*>&);
template __declspec(dllexport) void spine::Vector<spine::Bone*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Bone*>::contains(spine::Bone* const&);
template __declspec(dllexport) int spine::Vector<spine::Bone*>::indexOf(spine::Bone* const&);
class spine::Bone*& (spine::Vector<spine::Bone*>::*_77)(unsigned long long) = &spine::Vector<spine::Bone*>::operator[];
template __declspec(dllexport) spine::Bone** spine::Vector<spine::Bone*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Bone*>::voidPBuffer();
spine::Vector<class spine::Bone*>& (spine::Vector<spine::Bone*>::*_78)(const spine::Vector<class spine::Bone*>&) = &spine::Vector<spine::Bone*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Slot*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Slot_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Slot*>& inVector) { ::new (__instance) spine::Vector<spine::Slot*>(inVector); }
void (spine::Vector<spine::Slot*>::*_79)() = &spine::Vector<spine::Slot*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Slot*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Slot*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Slot*>::setSize(unsigned long long, spine::Slot* const&);
template __declspec(dllexport) void spine::Vector<spine::Slot*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Slot*>::add(spine::Slot* const&);
template __declspec(dllexport) void spine::Vector<spine::Slot*>::addAll(spine::Vector<spine::Slot*>&);
template __declspec(dllexport) void spine::Vector<spine::Slot*>::clearAndAddAll(spine::Vector<spine::Slot*>&);
template __declspec(dllexport) void spine::Vector<spine::Slot*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Slot*>::contains(spine::Slot* const&);
template __declspec(dllexport) int spine::Vector<spine::Slot*>::indexOf(spine::Slot* const&);
class spine::Slot*& (spine::Vector<spine::Slot*>::*_80)(unsigned long long) = &spine::Vector<spine::Slot*>::operator[];
template __declspec(dllexport) spine::Slot** spine::Vector<spine::Slot*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Slot*>::voidPBuffer();
spine::Vector<class spine::Slot*>& (spine::Vector<spine::Slot*>::*_81)(const spine::Vector<class spine::Slot*>&) = &spine::Vector<spine::Slot*>::operator=;
template __declspec(dllexport) spine::Vector<spine::IkConstraint*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_IkConstraint_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::IkConstraint*>& inVector) { ::new (__instance) spine::Vector<spine::IkConstraint*>(inVector); }
void (spine::Vector<spine::IkConstraint*>::*_82)() = &spine::Vector<spine::IkConstraint*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::IkConstraint*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::IkConstraint*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::setSize(unsigned long long, spine::IkConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::add(spine::IkConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::addAll(spine::Vector<spine::IkConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::clearAndAddAll(spine::Vector<spine::IkConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::IkConstraint*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::IkConstraint*>::contains(spine::IkConstraint* const&);
template __declspec(dllexport) int spine::Vector<spine::IkConstraint*>::indexOf(spine::IkConstraint* const&);
class spine::IkConstraint*& (spine::Vector<spine::IkConstraint*>::*_83)(unsigned long long) = &spine::Vector<spine::IkConstraint*>::operator[];
template __declspec(dllexport) spine::IkConstraint** spine::Vector<spine::IkConstraint*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::IkConstraint*>::voidPBuffer();
spine::Vector<class spine::IkConstraint*>& (spine::Vector<spine::IkConstraint*>::*_84)(const spine::Vector<class spine::IkConstraint*>&) = &spine::Vector<spine::IkConstraint*>::operator=;
template __declspec(dllexport) spine::Vector<spine::TransformConstraint*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_TransformConstraint_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::TransformConstraint*>& inVector) { ::new (__instance) spine::Vector<spine::TransformConstraint*>(inVector); }
void (spine::Vector<spine::TransformConstraint*>::*_85)() = &spine::Vector<spine::TransformConstraint*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TransformConstraint*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TransformConstraint*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::setSize(unsigned long long, spine::TransformConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::add(spine::TransformConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::addAll(spine::Vector<spine::TransformConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::clearAndAddAll(spine::Vector<spine::TransformConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::TransformConstraint*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::TransformConstraint*>::contains(spine::TransformConstraint* const&);
template __declspec(dllexport) int spine::Vector<spine::TransformConstraint*>::indexOf(spine::TransformConstraint* const&);
class spine::TransformConstraint*& (spine::Vector<spine::TransformConstraint*>::*_86)(unsigned long long) = &spine::Vector<spine::TransformConstraint*>::operator[];
template __declspec(dllexport) spine::TransformConstraint** spine::Vector<spine::TransformConstraint*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::TransformConstraint*>::voidPBuffer();
spine::Vector<class spine::TransformConstraint*>& (spine::Vector<spine::TransformConstraint*>::*_87)(const spine::Vector<class spine::TransformConstraint*>&) = &spine::Vector<spine::TransformConstraint*>::operator=;
template __declspec(dllexport) spine::Vector<spine::PathConstraint*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_PathConstraint_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::PathConstraint*>& inVector) { ::new (__instance) spine::Vector<spine::PathConstraint*>(inVector); }
void (spine::Vector<spine::PathConstraint*>::*_88)() = &spine::Vector<spine::PathConstraint*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::PathConstraint*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::PathConstraint*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::setSize(unsigned long long, spine::PathConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::add(spine::PathConstraint* const&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::addAll(spine::Vector<spine::PathConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::clearAndAddAll(spine::Vector<spine::PathConstraint*>&);
template __declspec(dllexport) void spine::Vector<spine::PathConstraint*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::PathConstraint*>::contains(spine::PathConstraint* const&);
template __declspec(dllexport) int spine::Vector<spine::PathConstraint*>::indexOf(spine::PathConstraint* const&);
class spine::PathConstraint*& (spine::Vector<spine::PathConstraint*>::*_89)(unsigned long long) = &spine::Vector<spine::PathConstraint*>::operator[];
template __declspec(dllexport) spine::PathConstraint** spine::Vector<spine::PathConstraint*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::PathConstraint*>::voidPBuffer();
spine::Vector<class spine::PathConstraint*>& (spine::Vector<spine::PathConstraint*>::*_90)(const spine::Vector<class spine::PathConstraint*>&) = &spine::Vector<spine::PathConstraint*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Updatable*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Updatable_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Updatable*>& inVector) { ::new (__instance) spine::Vector<spine::Updatable*>(inVector); }
void (spine::Vector<spine::Updatable*>::*_91)() = &spine::Vector<spine::Updatable*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Updatable*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Updatable*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::setSize(unsigned long long, spine::Updatable* const&);
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::add(spine::Updatable* const&);
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::addAll(spine::Vector<spine::Updatable*>&);
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::clearAndAddAll(spine::Vector<spine::Updatable*>&);
template __declspec(dllexport) void spine::Vector<spine::Updatable*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::Updatable*>::contains(spine::Updatable* const&);
template __declspec(dllexport) int spine::Vector<spine::Updatable*>::indexOf(spine::Updatable* const&);
class spine::Updatable*& (spine::Vector<spine::Updatable*>::*_92)(unsigned long long) = &spine::Vector<spine::Updatable*>::operator[];
template __declspec(dllexport) spine::Updatable** spine::Vector<spine::Updatable*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Updatable*>::voidPBuffer();
spine::Vector<class spine::Updatable*>& (spine::Vector<spine::Updatable*>::*_93)(const spine::Vector<class spine::Updatable*>&) = &spine::Vector<spine::Updatable*>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__I_F_Vector(void* __instance) { ::new (__instance) spine::Vector<int>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__I_F_Vector___1__N_spine_S_Vector__I(void* __instance, const spine::Vector<int>& inVector) { ::new (__instance) spine::Vector<int>(inVector); }
void (spine::Vector<int>::*_94)() = &spine::Vector<int>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<int>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<int>::size() const;
template __declspec(dllexport) void spine::Vector<int>::setSize(unsigned long long, const int&);
template __declspec(dllexport) void spine::Vector<int>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<int>::add(const int&);
template __declspec(dllexport) void spine::Vector<int>::addAll(spine::Vector<int>&);
template __declspec(dllexport) void spine::Vector<int>::clearAndAddAll(spine::Vector<int>&);
template __declspec(dllexport) void spine::Vector<int>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<int>::contains(const int&);
template __declspec(dllexport) int spine::Vector<int>::indexOf(const int&);
int& (spine::Vector<int>::*_95)(unsigned long long) = &spine::Vector<int>::operator[];
template __declspec(dllexport) int* spine::Vector<int>::buffer();
template __declspec(dllexport) void* spine::Vector<int>::voidPBuffer();
spine::Vector<int>& (spine::Vector<int>::*_96)(const spine::Vector<int>&) = &spine::Vector<int>::operator=;
template __declspec(dllexport) spine::Vector<spine::TrackEntry*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_TrackEntry_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::TrackEntry*>& inVector) { ::new (__instance) spine::Vector<spine::TrackEntry*>(inVector); }
void (spine::Vector<spine::TrackEntry*>::*_97)() = &spine::Vector<spine::TrackEntry*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TrackEntry*>::getCapacity() const;
unsigned long long (spine::Vector<spine::TrackEntry*>::*_98)() const = &spine::Vector<spine::TrackEntry*>::size;
template __declspec(dllexport) void spine::Vector<spine::TrackEntry*>::setSize(unsigned long long, spine::TrackEntry* const&);
template __declspec(dllexport) void spine::Vector<spine::TrackEntry*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::TrackEntry*>::add(spine::TrackEntry* const&);
template __declspec(dllexport) void spine::Vector<spine::TrackEntry*>::addAll(spine::Vector<spine::TrackEntry*>&);
template __declspec(dllexport) void spine::Vector<spine::TrackEntry*>::clearAndAddAll(spine::Vector<spine::TrackEntry*>&);
void (spine::Vector<spine::TrackEntry*>::*_99)(unsigned long long) = &spine::Vector<spine::TrackEntry*>::removeAt;
template __declspec(dllexport) bool spine::Vector<spine::TrackEntry*>::contains(spine::TrackEntry* const&);
template __declspec(dllexport) int spine::Vector<spine::TrackEntry*>::indexOf(spine::TrackEntry* const&);
class spine::TrackEntry*& (spine::Vector<spine::TrackEntry*>::*_100)(unsigned long long) = &spine::Vector<spine::TrackEntry*>::operator[];
template __declspec(dllexport) spine::TrackEntry** spine::Vector<spine::TrackEntry*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::TrackEntry*>::voidPBuffer();
spine::Vector<class spine::TrackEntry*>& (spine::Vector<spine::TrackEntry*>::*_101)(const spine::Vector<class spine::TrackEntry*>&) = &spine::Vector<spine::TrackEntry*>::operator=;
template __declspec(dllexport) spine::Vector<spine::AtlasPage*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_AtlasPage_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::AtlasPage*>& inVector) { ::new (__instance) spine::Vector<spine::AtlasPage*>(inVector); }
void (spine::Vector<spine::AtlasPage*>::*_102)() = &spine::Vector<spine::AtlasPage*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::AtlasPage*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::AtlasPage*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::setSize(unsigned long long, spine::AtlasPage* const&);
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::add(spine::AtlasPage* const&);
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::addAll(spine::Vector<spine::AtlasPage*>&);
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::clearAndAddAll(spine::Vector<spine::AtlasPage*>&);
template __declspec(dllexport) void spine::Vector<spine::AtlasPage*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::AtlasPage*>::contains(spine::AtlasPage* const&);
template __declspec(dllexport) int spine::Vector<spine::AtlasPage*>::indexOf(spine::AtlasPage* const&);
class spine::AtlasPage*& (spine::Vector<spine::AtlasPage*>::*_103)(unsigned long long) = &spine::Vector<spine::AtlasPage*>::operator[];
template __declspec(dllexport) spine::AtlasPage** spine::Vector<spine::AtlasPage*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::AtlasPage*>::voidPBuffer();
spine::Vector<class spine::AtlasPage*>& (spine::Vector<spine::AtlasPage*>::*_104)(const spine::Vector<class spine::AtlasPage*>&) = &spine::Vector<spine::AtlasPage*>::operator=;
template __declspec(dllexport) spine::Vector<spine::AtlasRegion*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_AtlasRegion_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::AtlasRegion*>& inVector) { ::new (__instance) spine::Vector<spine::AtlasRegion*>(inVector); }
void (spine::Vector<spine::AtlasRegion*>::*_105)() = &spine::Vector<spine::AtlasRegion*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::AtlasRegion*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::AtlasRegion*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::setSize(unsigned long long, spine::AtlasRegion* const&);
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::add(spine::AtlasRegion* const&);
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::addAll(spine::Vector<spine::AtlasRegion*>&);
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::clearAndAddAll(spine::Vector<spine::AtlasRegion*>&);
template __declspec(dllexport) void spine::Vector<spine::AtlasRegion*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::AtlasRegion*>::contains(spine::AtlasRegion* const&);
template __declspec(dllexport) int spine::Vector<spine::AtlasRegion*>::indexOf(spine::AtlasRegion* const&);
class spine::AtlasRegion*& (spine::Vector<spine::AtlasRegion*>::*_106)(unsigned long long) = &spine::Vector<spine::AtlasRegion*>::operator[];
template __declspec(dllexport) spine::AtlasRegion** spine::Vector<spine::AtlasRegion*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::AtlasRegion*>::voidPBuffer();
spine::Vector<class spine::AtlasRegion*>& (spine::Vector<spine::AtlasRegion*>::*_107)(const spine::Vector<class spine::AtlasRegion*>&) = &spine::Vector<spine::AtlasRegion*>::operator=;
template __declspec(dllexport) spine::Vector<spine::TextureRegion*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_TextureRegion_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::TextureRegion*>& inVector) { ::new (__instance) spine::Vector<spine::TextureRegion*>(inVector); }
void (spine::Vector<spine::TextureRegion*>::*_108)() = &spine::Vector<spine::TextureRegion*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TextureRegion*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::TextureRegion*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::setSize(unsigned long long, spine::TextureRegion* const&);
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::add(spine::TextureRegion* const&);
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::addAll(spine::Vector<spine::TextureRegion*>&);
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::clearAndAddAll(spine::Vector<spine::TextureRegion*>&);
template __declspec(dllexport) void spine::Vector<spine::TextureRegion*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::TextureRegion*>::contains(spine::TextureRegion* const&);
template __declspec(dllexport) int spine::Vector<spine::TextureRegion*>::indexOf(spine::TextureRegion* const&);
class spine::TextureRegion*& (spine::Vector<spine::TextureRegion*>::*_109)(unsigned long long) = &spine::Vector<spine::TextureRegion*>::operator[];
template __declspec(dllexport) spine::TextureRegion** spine::Vector<spine::TextureRegion*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::TextureRegion*>::voidPBuffer();
spine::Vector<class spine::TextureRegion*>& (spine::Vector<spine::TextureRegion*>::*_110)(const spine::Vector<class spine::TextureRegion*>&) = &spine::Vector<spine::TextureRegion*>::operator=;
template __declspec(dllexport) spine::Vector<unsigned short>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__s_F_Vector___1__N_spine_S_Vector__s(void* __instance, const spine::Vector<unsigned short>& inVector) { ::new (__instance) spine::Vector<unsigned short>(inVector); }
void (spine::Vector<unsigned short>::*_111)() = &spine::Vector<unsigned short>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<unsigned short>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<unsigned short>::size() const;
template __declspec(dllexport) void spine::Vector<unsigned short>::setSize(unsigned long long, const unsigned short&);
template __declspec(dllexport) void spine::Vector<unsigned short>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<unsigned short>::add(const unsigned short&);
template __declspec(dllexport) void spine::Vector<unsigned short>::addAll(spine::Vector<unsigned short>&);
template __declspec(dllexport) void spine::Vector<unsigned short>::clearAndAddAll(spine::Vector<unsigned short>&);
template __declspec(dllexport) void spine::Vector<unsigned short>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<unsigned short>::contains(const unsigned short&);
template __declspec(dllexport) int spine::Vector<unsigned short>::indexOf(const unsigned short&);
unsigned short& (spine::Vector<unsigned short>::*_112)(unsigned long long) = &spine::Vector<unsigned short>::operator[];
template __declspec(dllexport) unsigned short* spine::Vector<unsigned short>::buffer();
template __declspec(dllexport) void* spine::Vector<unsigned short>::voidPBuffer();
spine::Vector<unsigned short>& (spine::Vector<unsigned short>::*_113)(const spine::Vector<unsigned short>&) = &spine::Vector<unsigned short>::operator=;
template __declspec(dllexport) spine::Vector<spine::Vector<float>>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_Vector__f_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Vector<float>>& inVector) { ::new (__instance) spine::Vector<spine::Vector<float>>(inVector); }
void (spine::Vector<spine::Vector<float>>::*_114)() = &spine::Vector<spine::Vector<float>>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<float>>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<float>>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::setSize(unsigned long long, const spine::Vector<float>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::add(const spine::Vector<float>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::addAll(spine::Vector<spine::Vector<float>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::clearAndAddAll(spine::Vector<spine::Vector<float>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>>::removeAt(unsigned long long);
spine::Vector<float>& (spine::Vector<spine::Vector<float>>::*_115)(unsigned long long) = &spine::Vector<spine::Vector<float>>::operator[];
template __declspec(dllexport) spine::Vector<float>* spine::Vector<spine::Vector<float>>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Vector<float>>::voidPBuffer();
spine::Vector<spine::Vector<float>>& (spine::Vector<spine::Vector<float>>::*_116)(const spine::Vector<spine::Vector<float>>&) = &spine::Vector<spine::Vector<float>>::operator=;
template __declspec(dllexport) spine::Vector<spine::Vector<int>>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_spine_S_Vector__I_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Vector<int>>& inVector) { ::new (__instance) spine::Vector<spine::Vector<int>>(inVector); }
void (spine::Vector<spine::Vector<int>>::*_117)() = &spine::Vector<spine::Vector<int>>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<int>>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<int>>::size() const;
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::setSize(unsigned long long, const spine::Vector<int>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::add(const spine::Vector<int>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::addAll(spine::Vector<spine::Vector<int>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::clearAndAddAll(spine::Vector<spine::Vector<int>>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>>::removeAt(unsigned long long);
spine::Vector<int>& (spine::Vector<spine::Vector<int>>::*_118)(unsigned long long) = &spine::Vector<spine::Vector<int>>::operator[];
template __declspec(dllexport) spine::Vector<int>* spine::Vector<spine::Vector<int>>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Vector<int>>::voidPBuffer();
spine::Vector<spine::Vector<int>>& (spine::Vector<spine::Vector<int>>::*_119)(const spine::Vector<spine::Vector<int>>&) = &spine::Vector<spine::Vector<int>>::operator=;
template __declspec(dllexport) spine::Vector<spine::LinkedMesh*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_LinkedMesh_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::LinkedMesh*>& inVector) { ::new (__instance) spine::Vector<spine::LinkedMesh*>(inVector); }
void (spine::Vector<spine::LinkedMesh*>::*_120)() = &spine::Vector<spine::LinkedMesh*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::LinkedMesh*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::LinkedMesh*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::setSize(unsigned long long, spine::LinkedMesh* const&);
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::add(spine::LinkedMesh* const&);
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::addAll(spine::Vector<spine::LinkedMesh*>&);
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::clearAndAddAll(spine::Vector<spine::LinkedMesh*>&);
template __declspec(dllexport) void spine::Vector<spine::LinkedMesh*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::LinkedMesh*>::contains(spine::LinkedMesh* const&);
template __declspec(dllexport) int spine::Vector<spine::LinkedMesh*>::indexOf(spine::LinkedMesh* const&);
class spine::LinkedMesh*& (spine::Vector<spine::LinkedMesh*>::*_121)(unsigned long long) = &spine::Vector<spine::LinkedMesh*>::operator[];
template __declspec(dllexport) spine::LinkedMesh** spine::Vector<spine::LinkedMesh*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::LinkedMesh*>::voidPBuffer();
spine::Vector<class spine::LinkedMesh*>& (spine::Vector<spine::LinkedMesh*>::*_122)(const spine::Vector<class spine::LinkedMesh*>&) = &spine::Vector<spine::LinkedMesh*>::operator=;
template __declspec(dllexport) spine::Vector<spine::Polygon*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Polygon_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Polygon*>& inVector) { ::new (__instance) spine::Vector<spine::Polygon*>(inVector); }
void (spine::Vector<spine::Polygon*>::*_123)() = &spine::Vector<spine::Polygon*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Polygon*>::getCapacity() const;
unsigned long long (spine::Vector<spine::Polygon*>::*_124)() const = &spine::Vector<spine::Polygon*>::size;
template __declspec(dllexport) void spine::Vector<spine::Polygon*>::setSize(unsigned long long, spine::Polygon* const&);
template __declspec(dllexport) void spine::Vector<spine::Polygon*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Polygon*>::add(spine::Polygon* const&);
template __declspec(dllexport) void spine::Vector<spine::Polygon*>::addAll(spine::Vector<spine::Polygon*>&);
template __declspec(dllexport) void spine::Vector<spine::Polygon*>::clearAndAddAll(spine::Vector<spine::Polygon*>&);
void (spine::Vector<spine::Polygon*>::*_125)(unsigned long long) = &spine::Vector<spine::Polygon*>::removeAt;
template __declspec(dllexport) bool spine::Vector<spine::Polygon*>::contains(spine::Polygon* const&);
template __declspec(dllexport) int spine::Vector<spine::Polygon*>::indexOf(spine::Polygon* const&);
class spine::Polygon*& (spine::Vector<spine::Polygon*>::*_126)(unsigned long long) = &spine::Vector<spine::Polygon*>::operator[];
template __declspec(dllexport) spine::Polygon** spine::Vector<spine::Polygon*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Polygon*>::voidPBuffer();
spine::Vector<class spine::Polygon*>& (spine::Vector<spine::Polygon*>::*_127)(const spine::Vector<class spine::Polygon*>&) = &spine::Vector<spine::Polygon*>::operator=;
template __declspec(dllexport) spine::Vector<spine::BoundingBoxAttachment*>::Vector();
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_BoundingBoxAttachment_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::BoundingBoxAttachment*>& inVector) { ::new (__instance) spine::Vector<spine::BoundingBoxAttachment*>(inVector); }
void (spine::Vector<spine::BoundingBoxAttachment*>::*_128)() = &spine::Vector<spine::BoundingBoxAttachment*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::BoundingBoxAttachment*>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<spine::BoundingBoxAttachment*>::size() const;
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::setSize(unsigned long long, spine::BoundingBoxAttachment* const&);
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::add(spine::BoundingBoxAttachment* const&);
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::addAll(spine::Vector<spine::BoundingBoxAttachment*>&);
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::clearAndAddAll(spine::Vector<spine::BoundingBoxAttachment*>&);
template __declspec(dllexport) void spine::Vector<spine::BoundingBoxAttachment*>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<spine::BoundingBoxAttachment*>::contains(spine::BoundingBoxAttachment* const&);
template __declspec(dllexport) int spine::Vector<spine::BoundingBoxAttachment*>::indexOf(spine::BoundingBoxAttachment* const&);
class spine::BoundingBoxAttachment*& (spine::Vector<spine::BoundingBoxAttachment*>::*_129)(unsigned long long) = &spine::Vector<spine::BoundingBoxAttachment*>::operator[];
template __declspec(dllexport) spine::BoundingBoxAttachment** spine::Vector<spine::BoundingBoxAttachment*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::BoundingBoxAttachment*>::voidPBuffer();
spine::Vector<class spine::BoundingBoxAttachment*>& (spine::Vector<spine::BoundingBoxAttachment*>::*_130)(const spine::Vector<class spine::BoundingBoxAttachment*>&) = &spine::Vector<spine::BoundingBoxAttachment*>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Vector__f_F_Vector(void* __instance) { ::new (__instance) spine::Vector<spine::Vector<float>*>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Vector__f_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Vector<float>*>& inVector) { ::new (__instance) spine::Vector<spine::Vector<float>*>(inVector); }
void (spine::Vector<spine::Vector<float>*>::*_131)() = &spine::Vector<spine::Vector<float>*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<float>*>::getCapacity() const;
unsigned long long (spine::Vector<spine::Vector<float>*>::*_132)() const = &spine::Vector<spine::Vector<float>*>::size;
template __declspec(dllexport) void spine::Vector<spine::Vector<float>*>::setSize(unsigned long long, spine::Vector<float>* const&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>*>::add(spine::Vector<float>* const&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>*>::addAll(spine::Vector<spine::Vector<float>*>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<float>*>::clearAndAddAll(spine::Vector<spine::Vector<float>*>&);
void (spine::Vector<spine::Vector<float>*>::*_133)(unsigned long long) = &spine::Vector<spine::Vector<float>*>::removeAt;
template __declspec(dllexport) bool spine::Vector<spine::Vector<float>*>::contains(spine::Vector<float>* const&);
template __declspec(dllexport) int spine::Vector<spine::Vector<float>*>::indexOf(spine::Vector<float>* const&);
spine::Vector<float>*& (spine::Vector<spine::Vector<float>*>::*_134)(unsigned long long) = &spine::Vector<spine::Vector<float>*>::operator[];
template __declspec(dllexport) spine::Vector<float>** spine::Vector<spine::Vector<float>*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Vector<float>*>::voidPBuffer();
spine::Vector<spine::Vector<float>*>& (spine::Vector<spine::Vector<float>*>::*_135)(const spine::Vector<spine::Vector<float>*>&) = &spine::Vector<spine::Vector<float>*>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Vector__I_F_Vector(void* __instance) { ::new (__instance) spine::Vector<spine::Vector<int>*>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector_____N_spine_S_Vector__I_F_Vector___1__N_spine_S_Vector__S0(void* __instance, const spine::Vector<spine::Vector<int>*>& inVector) { ::new (__instance) spine::Vector<spine::Vector<int>*>(inVector); }
void (spine::Vector<spine::Vector<int>*>::*_136)() = &spine::Vector<spine::Vector<int>*>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<spine::Vector<int>*>::getCapacity() const;
unsigned long long (spine::Vector<spine::Vector<int>*>::*_137)() const = &spine::Vector<spine::Vector<int>*>::size;
template __declspec(dllexport) void spine::Vector<spine::Vector<int>*>::setSize(unsigned long long, spine::Vector<int>* const&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>*>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>*>::add(spine::Vector<int>* const&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>*>::addAll(spine::Vector<spine::Vector<int>*>&);
template __declspec(dllexport) void spine::Vector<spine::Vector<int>*>::clearAndAddAll(spine::Vector<spine::Vector<int>*>&);
void (spine::Vector<spine::Vector<int>*>::*_138)(unsigned long long) = &spine::Vector<spine::Vector<int>*>::removeAt;
template __declspec(dllexport) bool spine::Vector<spine::Vector<int>*>::contains(spine::Vector<int>* const&);
template __declspec(dllexport) int spine::Vector<spine::Vector<int>*>::indexOf(spine::Vector<int>* const&);
spine::Vector<int>*& (spine::Vector<spine::Vector<int>*>::*_139)(unsigned long long) = &spine::Vector<spine::Vector<int>*>::operator[];
template __declspec(dllexport) spine::Vector<int>** spine::Vector<spine::Vector<int>*>::buffer();
template __declspec(dllexport) void* spine::Vector<spine::Vector<int>*>::voidPBuffer();
spine::Vector<spine::Vector<int>*>& (spine::Vector<spine::Vector<int>*>::*_140)(const spine::Vector<spine::Vector<int>*>&) = &spine::Vector<spine::Vector<int>*>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__b_F_Vector(void* __instance) { ::new (__instance) spine::Vector<bool>(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Vector__b_F_Vector___1__N_spine_S_Vector__b(void* __instance, const spine::Vector<bool>& inVector) { ::new (__instance) spine::Vector<bool>(inVector); }
void (spine::Vector<bool>::*_141)() = &spine::Vector<bool>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<bool>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<bool>::size() const;
template __declspec(dllexport) void spine::Vector<bool>::setSize(unsigned long long, const bool&);
template __declspec(dllexport) void spine::Vector<bool>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<bool>::add(const bool&);
template __declspec(dllexport) void spine::Vector<bool>::addAll(spine::Vector<bool>&);
template __declspec(dllexport) void spine::Vector<bool>::clearAndAddAll(spine::Vector<bool>&);
template __declspec(dllexport) void spine::Vector<bool>::removeAt(unsigned long long);
template __declspec(dllexport) bool spine::Vector<bool>::contains(const bool&);
template __declspec(dllexport) int spine::Vector<bool>::indexOf(const bool&);
bool& (spine::Vector<bool>::*_142)(unsigned long long) = &spine::Vector<bool>::operator[];
template __declspec(dllexport) bool* spine::Vector<bool>::buffer();
template __declspec(dllexport) void* spine::Vector<bool>::voidPBuffer();
spine::Vector<bool>& (spine::Vector<bool>::*_143)(const spine::Vector<bool>&) = &spine::Vector<bool>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vector____N_SpineUnity_S_SubmeshInstruction_F_Vector(void* __instance) { ::new (__instance) spine::Vector<SpineUnity::SubmeshInstruction>(); }
template __declspec(dllexport) spine::Vector<SpineUnity::SubmeshInstruction>::Vector(const spine::Vector<SpineUnity::SubmeshInstruction>&);
void (spine::Vector<SpineUnity::SubmeshInstruction>::*_144)() = &spine::Vector<SpineUnity::SubmeshInstruction>::clear;
template __declspec(dllexport) unsigned long long spine::Vector<SpineUnity::SubmeshInstruction>::getCapacity() const;
template __declspec(dllexport) unsigned long long spine::Vector<SpineUnity::SubmeshInstruction>::size() const;
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::setSize(unsigned long long, const SpineUnity::SubmeshInstruction&);
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::ensureCapacity(unsigned long long);
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::add(const SpineUnity::SubmeshInstruction&);
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::addAll(spine::Vector<SpineUnity::SubmeshInstruction>&);
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::clearAndAddAll(spine::Vector<SpineUnity::SubmeshInstruction>&);
template __declspec(dllexport) void spine::Vector<SpineUnity::SubmeshInstruction>::removeAt(unsigned long long);
struct SpineUnity::SubmeshInstruction& (spine::Vector<SpineUnity::SubmeshInstruction>::*_145)(unsigned long long) = &spine::Vector<SpineUnity::SubmeshInstruction>::operator[];
template __declspec(dllexport) SpineUnity::SubmeshInstruction* spine::Vector<SpineUnity::SubmeshInstruction>::buffer();
template __declspec(dllexport) void* spine::Vector<SpineUnity::SubmeshInstruction>::voidPBuffer();
spine::Vector<struct SpineUnity::SubmeshInstruction>& (spine::Vector<SpineUnity::SubmeshInstruction>::*_146)(const spine::Vector<struct SpineUnity::SubmeshInstruction>&) = &spine::Vector<SpineUnity::SubmeshInstruction>::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Animation_Animation___1__N_spine_S_Animation(void* __instance, const spine::Animation& _0) { ::new (__instance) spine::Animation(_0); }
class spine::Animation& (spine::Animation::*_147)(const class spine::Animation&) = &spine::Animation::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_HasRendererObject_HasRendererObject(void* __instance) { ::new (__instance) spine::HasRendererObject(); }
void* (spine::HasRendererObject::*_148)() = &spine::HasRendererObject::getRendererObject;
void (spine::HasRendererObject::*_149)(void*, void (*)(void*)) = &spine::HasRendererObject::setRendererObject;
class spine::HasRendererObject& (spine::HasRendererObject::*_150)(const class spine::HasRendererObject&) = &spine::HasRendererObject::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_HasRendererObject_HasRendererObject___1__N_spine_S_HasRendererObject(void* __instance, const spine::HasRendererObject& _0) { ::new (__instance) spine::HasRendererObject(_0); }
union spine::Color32& (spine::Color32::*_151)(union spine::Color32&&) = &spine::Color32::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Color_Color(void* __instance) { ::new (__instance) spine::Color(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Color_Color_f_f_f_f(void* __instance, float r, float g, float b, float a) { ::new (__instance) spine::Color(r, g, b, a); }
class spine::Color& (spine::Color::*_152)(float, float, float, float) = &spine::Color::set;
class spine::Color& (spine::Color::*_153)(float, float, float) = &spine::Color::set;
class spine::Color& (spine::Color::*_154)(const class spine::Color&) = &spine::Color::set;
class spine::Color& (spine::Color::*_155)(float, float, float, float) = &spine::Color::add;
class spine::Color& (spine::Color::*_156)(float, float, float) = &spine::Color::add;
class spine::Color& (spine::Color::*_157)(const class spine::Color&) = &spine::Color::add;
class spine::Color& (spine::Color::*_158)() = &spine::Color::clamp;
extern "C" __declspec(dllexport) void c__N_spine_S_Color_Color___1__N_spine_S_Color(void* __instance, const spine::Color& _0) { ::new (__instance) spine::Color(_0); }
class spine::Color& (spine::Color::*_159)(class spine::Color&&) = &spine::Color::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Slot_Slot___1__N_spine_S_Slot(void* __instance, const spine::Slot& _0) { ::new (__instance) spine::Slot(_0); }
class c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObjectAnimationStateListenerObject : public spine::AnimationStateListenerObject { public: c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObjectAnimationStateListenerObject(): spine::AnimationStateListenerObject() {}; void callback(spine::AnimationState*, spine::EventType, spine::TrackEntry*, spine::Event*) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObject(void* __instance) { ::new (__instance) c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObjectAnimationStateListenerObject(); }
class spine::AnimationStateListenerObject& (spine::AnimationStateListenerObject::*_160)(const class spine::AnimationStateListenerObject&) = &spine::AnimationStateListenerObject::operator=;
class c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObject___1__N_spine_S_AnimationStateListenerObjectAnimationStateListenerObject : public spine::AnimationStateListenerObject { public: c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObject___1__N_spine_S_AnimationStateListenerObjectAnimationStateListenerObject(const spine::AnimationStateListenerObject& _0): spine::AnimationStateListenerObject(_0) {}; void callback(spine::AnimationState*, spine::EventType, spine::TrackEntry*, spine::Event*) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObject___1__N_spine_S_AnimationStateListenerObject(void* __instance, const spine::AnimationStateListenerObject& _0) { ::new (__instance) c__N_spine_S_AnimationStateListenerObject_AnimationStateListenerObject___1__N_spine_S_AnimationStateListenerObjectAnimationStateListenerObject(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_TrackEntry_TrackEntry___1__N_spine_S_TrackEntry(void* __instance, const spine::TrackEntry& _0) { ::new (__instance) spine::TrackEntry(_0); }
class spine::TrackEntry& (spine::TrackEntry::*_161)(const class spine::TrackEntry&) = &spine::TrackEntry::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_EventQueueEntry_EventQueueEntry___1__N_spine_S_EventQueueEntry(void* __instance, const spine::EventQueueEntry& _0) { ::new (__instance) spine::EventQueueEntry(_0); }
class spine::EventQueueEntry& (spine::EventQueueEntry::*_162)(class spine::EventQueueEntry&&) = &spine::EventQueueEntry::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_EventQueue_EventQueue___1__N_spine_S_EventQueue(void* __instance, const spine::EventQueue& _0) { ::new (__instance) spine::EventQueue(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_AnimationState_AnimationState___1__N_spine_S_AnimationState(void* __instance, const spine::AnimationState& _0) { ::new (__instance) spine::AnimationState(_0); }
class spine::AnimationState& (spine::AnimationState::*_163)(const class spine::AnimationState&) = &spine::AnimationState::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_AnimationStateData_AnimationStateData___1__N_spine_S_AnimationStateData(void* __instance, const spine::AnimationStateData& _0) { ::new (__instance) spine::AnimationStateData(_0); }
class spine::AnimationStateData& (spine::AnimationStateData::*_164)(class spine::AnimationStateData&&) = &spine::AnimationStateData::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_TextureRegion_TextureRegion(void* __instance) { ::new (__instance) spine::TextureRegion(); }
extern "C" __declspec(dllexport) void c__N_spine_S_TextureRegion_TextureRegion___1__N_spine_S_TextureRegion(void* __instance, const spine::TextureRegion& _0) { ::new (__instance) spine::TextureRegion(_0); }
class spine::TextureRegion& (spine::TextureRegion::*_165)(const class spine::TextureRegion&) = &spine::TextureRegion::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_AtlasPage_AtlasPage___1__N_spine_S_String(void* __instance, const spine::String& inName) { ::new (__instance) spine::AtlasPage(inName); }
extern "C" __declspec(dllexport) void c__N_spine_S_AtlasPage_AtlasPage___1__N_spine_S_AtlasPage(void* __instance, const spine::AtlasPage& _0) { ::new (__instance) spine::AtlasPage(_0); }
class spine::AtlasPage& (spine::AtlasPage::*_166)(class spine::AtlasPage&&) = &spine::AtlasPage::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_AtlasRegion_AtlasRegion___1__N_spine_S_AtlasRegion(void* __instance, const spine::AtlasRegion& _0) { ::new (__instance) spine::AtlasRegion(_0); }
class spine::AtlasRegion& (spine::AtlasRegion::*_167)(class spine::AtlasRegion&&) = &spine::AtlasRegion::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_AtlasRegion_AtlasRegion(void* __instance) { ::new (__instance) spine::AtlasRegion(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Atlas_Atlas___1__N_spine_S_Atlas(void* __instance, const spine::Atlas& _0) { ::new (__instance) spine::Atlas(_0); }
class spine::Atlas& (spine::Atlas::*_168)(const class spine::Atlas&) = &spine::Atlas::operator=;
class c__N_spine_S_AttachmentLoader_AttachmentLoader___1__N_spine_S_AttachmentLoaderAttachmentLoader : public spine::AttachmentLoader { public: c__N_spine_S_AttachmentLoader_AttachmentLoader___1__N_spine_S_AttachmentLoaderAttachmentLoader(const spine::AttachmentLoader& _0): spine::AttachmentLoader(_0) {}; spine::RegionAttachment* newRegionAttachment(spine::Skin&, const spine::String&, const spine::String&, spine::Sequence*) { return {}; } spine::MeshAttachment* newMeshAttachment(spine::Skin&, const spine::String&, const spine::String&, spine::Sequence*) { return {}; } spine::BoundingBoxAttachment* newBoundingBoxAttachment(spine::Skin&, const spine::String&) { return {}; } spine::PathAttachment* newPathAttachment(spine::Skin&, const spine::String&) { return {}; } spine::PointAttachment* newPointAttachment(spine::Skin&, const spine::String&) { return {}; } spine::ClippingAttachment* newClippingAttachment(spine::Skin&, const spine::String&) { return {}; } void configureAttachment(spine::Attachment*) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_AttachmentLoader_AttachmentLoader___1__N_spine_S_AttachmentLoader(void* __instance, const spine::AttachmentLoader& _0) { ::new (__instance) c__N_spine_S_AttachmentLoader_AttachmentLoader___1__N_spine_S_AttachmentLoaderAttachmentLoader(_0); }
class spine::AttachmentLoader& (spine::AttachmentLoader::*_169)(const class spine::AttachmentLoader&) = &spine::AttachmentLoader::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_AtlasAttachmentLoader_AtlasAttachmentLoader___1__N_spine_S_AtlasAttachmentLoader(void* __instance, const spine::AtlasAttachmentLoader& _0) { ::new (__instance) spine::AtlasAttachmentLoader(_0); }
class spine::AtlasAttachmentLoader& (spine::AtlasAttachmentLoader::*_170)(class spine::AtlasAttachmentLoader&&) = &spine::AtlasAttachmentLoader::operator=;
class c__N_spine_S_Attachment_Attachment___1__N_spine_S_AttachmentAttachment : public spine::Attachment { public: c__N_spine_S_Attachment_Attachment___1__N_spine_S_AttachmentAttachment(const spine::Attachment& _0): spine::Attachment(_0) {}; spine::Attachment* copy() { return {}; }  };
extern "C" __declspec(dllexport) void c__N_spine_S_Attachment_Attachment___1__N_spine_S_Attachment(void* __instance, const spine::Attachment& _0) { ::new (__instance) c__N_spine_S_Attachment_Attachment___1__N_spine_S_AttachmentAttachment(_0); }
class c__N_spine_S_Timeline_Timeline___1__N_spine_S_TimelineTimeline : public spine::Timeline { public: c__N_spine_S_Timeline_Timeline___1__N_spine_S_TimelineTimeline(const spine::Timeline& _0): spine::Timeline(_0) {}; void apply(spine::Skeleton&, float, float, spine::Vector<spine::Event*>*, float, spine::MixBlend, spine::MixDirection) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_Timeline_Timeline___1__N_spine_S_Timeline(void* __instance, const spine::Timeline& _0) { ::new (__instance) c__N_spine_S_Timeline_Timeline___1__N_spine_S_TimelineTimeline(_0); }
class spine::Timeline& (spine::Timeline::*_171)(const class spine::Timeline&) = &spine::Timeline::operator=;
int (spine::AttachmentTimeline::*_172)() = &spine::AttachmentTimeline::getSlotIndex;
void (spine::AttachmentTimeline::*_173)(int) = &spine::AttachmentTimeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_AttachmentTimeline_AttachmentTimeline___1__N_spine_S_AttachmentTimeline(void* __instance, const spine::AttachmentTimeline& _0) { ::new (__instance) spine::AttachmentTimeline(_0); }
class spine::AttachmentTimeline& (spine::AttachmentTimeline::*_174)(const class spine::AttachmentTimeline&) = &spine::AttachmentTimeline::operator=;
class c__N_spine_S_Updatable_Updatable___1__N_spine_S_UpdatableUpdatable : public spine::Updatable { public: c__N_spine_S_Updatable_Updatable___1__N_spine_S_UpdatableUpdatable(const spine::Updatable& _0): spine::Updatable(_0) {}; void update() {} bool isActive() { return {}; } void setActive(bool) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_Updatable_Updatable___1__N_spine_S_Updatable(void* __instance, const spine::Updatable& _0) { ::new (__instance) c__N_spine_S_Updatable_Updatable___1__N_spine_S_UpdatableUpdatable(_0); }
class spine::Updatable& (spine::Updatable::*_175)(const class spine::Updatable&) = &spine::Updatable::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Bone_Bone___1__N_spine_S_Bone(void* __instance, const spine::Bone& _0) { ::new (__instance) spine::Bone(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_BoneData_BoneData___1__N_spine_S_BoneData(void* __instance, const spine::BoneData& _0) { ::new (__instance) spine::BoneData(_0); }
class c__N_spine_S_VertexAttachment_VertexAttachment___1__N_spine_S_VertexAttachmentVertexAttachment : public spine::VertexAttachment { public: c__N_spine_S_VertexAttachment_VertexAttachment___1__N_spine_S_VertexAttachmentVertexAttachment(const spine::VertexAttachment& _0): spine::VertexAttachment(_0) {}; spine::Attachment* copy() { return {}; }  };
extern "C" __declspec(dllexport) void c__N_spine_S_VertexAttachment_VertexAttachment___1__N_spine_S_VertexAttachment(void* __instance, const spine::VertexAttachment& _0) { ::new (__instance) c__N_spine_S_VertexAttachment_VertexAttachment___1__N_spine_S_VertexAttachmentVertexAttachment(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_BoundingBoxAttachment_BoundingBoxAttachment___1__N_spine_S_BoundingBoxAttachment(void* __instance, const spine::BoundingBoxAttachment& _0) { ::new (__instance) spine::BoundingBoxAttachment(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_ClippingAttachment_ClippingAttachment___1__N_spine_S_ClippingAttachment(void* __instance, const spine::ClippingAttachment& _0) { ::new (__instance) spine::ClippingAttachment(_0); }
class c__N_spine_S_CurveTimeline_CurveTimeline___1__N_spine_S_CurveTimelineCurveTimeline : public spine::CurveTimeline { public: c__N_spine_S_CurveTimeline_CurveTimeline___1__N_spine_S_CurveTimelineCurveTimeline(const spine::CurveTimeline& _0): spine::CurveTimeline(_0) {}; void apply(spine::Skeleton&, float, float, spine::Vector<spine::Event*>*, float, spine::MixBlend, spine::MixDirection) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_CurveTimeline_CurveTimeline___1__N_spine_S_CurveTimeline(void* __instance, const spine::CurveTimeline& _0) { ::new (__instance) c__N_spine_S_CurveTimeline_CurveTimeline___1__N_spine_S_CurveTimelineCurveTimeline(_0); }
class spine::CurveTimeline& (spine::CurveTimeline::*_176)(const class spine::CurveTimeline&) = &spine::CurveTimeline::operator=;
class c__N_spine_S_CurveTimeline1_CurveTimeline1___1__N_spine_S_CurveTimeline1CurveTimeline1 : public spine::CurveTimeline1 { public: c__N_spine_S_CurveTimeline1_CurveTimeline1___1__N_spine_S_CurveTimeline1CurveTimeline1(const spine::CurveTimeline1& _0): spine::CurveTimeline1(_0) {}; void apply(spine::Skeleton&, float, float, spine::Vector<spine::Event*>*, float, spine::MixBlend, spine::MixDirection) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_CurveTimeline1_CurveTimeline1___1__N_spine_S_CurveTimeline1(void* __instance, const spine::CurveTimeline1& _0) { ::new (__instance) c__N_spine_S_CurveTimeline1_CurveTimeline1___1__N_spine_S_CurveTimeline1CurveTimeline1(_0); }
class spine::CurveTimeline1& (spine::CurveTimeline1::*_177)(const class spine::CurveTimeline1&) = &spine::CurveTimeline1::operator=;
class c__N_spine_S_CurveTimeline2_CurveTimeline2___1__N_spine_S_CurveTimeline2CurveTimeline2 : public spine::CurveTimeline2 { public: c__N_spine_S_CurveTimeline2_CurveTimeline2___1__N_spine_S_CurveTimeline2CurveTimeline2(const spine::CurveTimeline2& _0): spine::CurveTimeline2(_0) {}; void apply(spine::Skeleton&, float, float, spine::Vector<spine::Event*>*, float, spine::MixBlend, spine::MixDirection) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_CurveTimeline2_CurveTimeline2___1__N_spine_S_CurveTimeline2(void* __instance, const spine::CurveTimeline2& _0) { ::new (__instance) c__N_spine_S_CurveTimeline2_CurveTimeline2___1__N_spine_S_CurveTimeline2CurveTimeline2(_0); }
class spine::CurveTimeline2& (spine::CurveTimeline2::*_178)(const class spine::CurveTimeline2&) = &spine::CurveTimeline2::operator=;
int (spine::RGBATimeline::*_179)() = &spine::RGBATimeline::getSlotIndex;
void (spine::RGBATimeline::*_180)(int) = &spine::RGBATimeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_RGBATimeline_RGBATimeline___1__N_spine_S_RGBATimeline(void* __instance, const spine::RGBATimeline& _0) { ::new (__instance) spine::RGBATimeline(_0); }
class spine::RGBATimeline& (spine::RGBATimeline::*_181)(const class spine::RGBATimeline&) = &spine::RGBATimeline::operator=;
int (spine::RGBTimeline::*_182)() = &spine::RGBTimeline::getSlotIndex;
void (spine::RGBTimeline::*_183)(int) = &spine::RGBTimeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_RGBTimeline_RGBTimeline___1__N_spine_S_RGBTimeline(void* __instance, const spine::RGBTimeline& _0) { ::new (__instance) spine::RGBTimeline(_0); }
class spine::RGBTimeline& (spine::RGBTimeline::*_184)(const class spine::RGBTimeline&) = &spine::RGBTimeline::operator=;
int (spine::AlphaTimeline::*_185)() = &spine::AlphaTimeline::getSlotIndex;
void (spine::AlphaTimeline::*_186)(int) = &spine::AlphaTimeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_AlphaTimeline_AlphaTimeline___1__N_spine_S_AlphaTimeline(void* __instance, const spine::AlphaTimeline& _0) { ::new (__instance) spine::AlphaTimeline(_0); }
class spine::AlphaTimeline& (spine::AlphaTimeline::*_187)(const class spine::AlphaTimeline&) = &spine::AlphaTimeline::operator=;
int (spine::RGBA2Timeline::*_188)() = &spine::RGBA2Timeline::getSlotIndex;
void (spine::RGBA2Timeline::*_189)(int) = &spine::RGBA2Timeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_RGBA2Timeline_RGBA2Timeline___1__N_spine_S_RGBA2Timeline(void* __instance, const spine::RGBA2Timeline& _0) { ::new (__instance) spine::RGBA2Timeline(_0); }
class spine::RGBA2Timeline& (spine::RGBA2Timeline::*_190)(const class spine::RGBA2Timeline&) = &spine::RGBA2Timeline::operator=;
int (spine::RGB2Timeline::*_191)() = &spine::RGB2Timeline::getSlotIndex;
void (spine::RGB2Timeline::*_192)(int) = &spine::RGB2Timeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_RGB2Timeline_RGB2Timeline___1__N_spine_S_RGB2Timeline(void* __instance, const spine::RGB2Timeline& _0) { ::new (__instance) spine::RGB2Timeline(_0); }
class spine::RGB2Timeline& (spine::RGB2Timeline::*_193)(const class spine::RGB2Timeline&) = &spine::RGB2Timeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_ConstraintData_ConstraintData___1__N_spine_S_ConstraintData(void* __instance, const spine::ConstraintData& _0) { ::new (__instance) spine::ConstraintData(_0); }
int (spine::DeformTimeline::*_194)() = &spine::DeformTimeline::getSlotIndex;
void (spine::DeformTimeline::*_195)(int) = &spine::DeformTimeline::setSlotIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_DeformTimeline_DeformTimeline___1__N_spine_S_DeformTimeline(void* __instance, const spine::DeformTimeline& _0) { ::new (__instance) spine::DeformTimeline(_0); }
class spine::DeformTimeline& (spine::DeformTimeline::*_196)(class spine::DeformTimeline&&) = &spine::DeformTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_DrawOrderTimeline_DrawOrderTimeline___1__N_spine_S_DrawOrderTimeline(void* __instance, const spine::DrawOrderTimeline& _0) { ::new (__instance) spine::DrawOrderTimeline(_0); }
class spine::DrawOrderTimeline& (spine::DrawOrderTimeline::*_197)(class spine::DrawOrderTimeline&&) = &spine::DrawOrderTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Event_Event___1__N_spine_S_Event(void* __instance, const spine::Event& _0) { ::new (__instance) spine::Event(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_EventData_EventData___1__N_spine_S_EventData(void* __instance, const spine::EventData& _0) { ::new (__instance) spine::EventData(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_EventTimeline_EventTimeline___1__N_spine_S_EventTimeline(void* __instance, const spine::EventTimeline& _0) { ::new (__instance) spine::EventTimeline(_0); }
class spine::EventTimeline& (spine::EventTimeline::*_198)(const class spine::EventTimeline&) = &spine::EventTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_IkConstraint_IkConstraint___1__N_spine_S_IkConstraint(void* __instance, const spine::IkConstraint& _0) { ::new (__instance) spine::IkConstraint(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_IkConstraintData_IkConstraintData___1__N_spine_S_IkConstraintData(void* __instance, const spine::IkConstraintData& _0) { ::new (__instance) spine::IkConstraintData(_0); }
int (spine::IkConstraintTimeline::*_199)() = &spine::IkConstraintTimeline::getIkConstraintIndex;
void (spine::IkConstraintTimeline::*_200)(int) = &spine::IkConstraintTimeline::setIkConstraintIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_IkConstraintTimeline_IkConstraintTimeline___1__N_spine_S_IkConstraintTimeline(void* __instance, const spine::IkConstraintTimeline& _0) { ::new (__instance) spine::IkConstraintTimeline(_0); }
class spine::IkConstraintTimeline& (spine::IkConstraintTimeline::*_201)(class spine::IkConstraintTimeline&&) = &spine::IkConstraintTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Json_Json___1__N_spine_S_Json(void* __instance, const spine::Json& _0) { ::new (__instance) spine::Json(_0); }
class spine::Json& (spine::Json::*_202)(const class spine::Json&) = &spine::Json::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_LinkedMesh_LinkedMesh___1__N_spine_S_LinkedMesh(void* __instance, const spine::LinkedMesh& _0) { ::new (__instance) spine::LinkedMesh(_0); }
class spine::LinkedMesh& (spine::LinkedMesh::*_203)(class spine::LinkedMesh&&) = &spine::LinkedMesh::operator=;
int (spine::Sequence::*_204)() = &spine::Sequence::getId;
void (spine::Sequence::*_205)(int) = &spine::Sequence::setId;
int (spine::Sequence::*_206)() = &spine::Sequence::getStart;
void (spine::Sequence::*_207)(int) = &spine::Sequence::setStart;
int (spine::Sequence::*_208)() = &spine::Sequence::getDigits;
void (spine::Sequence::*_209)(int) = &spine::Sequence::setDigits;
int (spine::Sequence::*_210)() = &spine::Sequence::getSetupIndex;
void (spine::Sequence::*_211)(int) = &spine::Sequence::setSetupIndex;
spine::Vector<class spine::TextureRegion*>& (spine::Sequence::*_212)() = &spine::Sequence::getRegions;
extern "C" __declspec(dllexport) void c__N_spine_S_Sequence_Sequence___1__N_spine_S_Sequence(void* __instance, const spine::Sequence& _0) { ::new (__instance) spine::Sequence(_0); }
class spine::Sequence& (spine::Sequence::*_213)(const class spine::Sequence&) = &spine::Sequence::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_MeshAttachment_MeshAttachment___1__N_spine_S_MeshAttachment(void* __instance, const spine::MeshAttachment& _0) { ::new (__instance) spine::MeshAttachment(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_PathAttachment_PathAttachment___1__N_spine_S_PathAttachment(void* __instance, const spine::PathAttachment& _0) { ::new (__instance) spine::PathAttachment(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_PathConstraint_PathConstraint___1__N_spine_S_PathConstraint(void* __instance, const spine::PathConstraint& _0) { ::new (__instance) spine::PathConstraint(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_PathConstraintData_PathConstraintData___1__N_spine_S_PathConstraintData(void* __instance, const spine::PathConstraintData& _0) { ::new (__instance) spine::PathConstraintData(_0); }
int (spine::PathConstraintMixTimeline::*_214)() = &spine::PathConstraintMixTimeline::getPathConstraintIndex;
void (spine::PathConstraintMixTimeline::*_215)(int) = &spine::PathConstraintMixTimeline::setPathConstraintIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_PathConstraintMixTimeline_PathConstraintMixTimeline___1__N_spine_S_PathConstraintMixTimeline(void* __instance, const spine::PathConstraintMixTimeline& _0) { ::new (__instance) spine::PathConstraintMixTimeline(_0); }
class spine::PathConstraintMixTimeline& (spine::PathConstraintMixTimeline::*_216)(class spine::PathConstraintMixTimeline&&) = &spine::PathConstraintMixTimeline::operator=;
int (spine::PathConstraintPositionTimeline::*_217)() = &spine::PathConstraintPositionTimeline::getPathConstraintIndex;
void (spine::PathConstraintPositionTimeline::*_218)(int) = &spine::PathConstraintPositionTimeline::setPathConstraintIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_PathConstraintPositionTimeline_PathConstraintPositionTimeline___1__N_spine_S_PathConstraintPositionTimeline(void* __instance, const spine::PathConstraintPositionTimeline& _0) { ::new (__instance) spine::PathConstraintPositionTimeline(_0); }
class spine::PathConstraintPositionTimeline& (spine::PathConstraintPositionTimeline::*_219)(const class spine::PathConstraintPositionTimeline&) = &spine::PathConstraintPositionTimeline::operator=;
int (spine::PathConstraintSpacingTimeline::*_220)() = &spine::PathConstraintSpacingTimeline::getPathConstraintIndex;
void (spine::PathConstraintSpacingTimeline::*_221)(int) = &spine::PathConstraintSpacingTimeline::setPathConstraintIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_PathConstraintSpacingTimeline_PathConstraintSpacingTimeline___1__N_spine_S_PathConstraintSpacingTimeline(void* __instance, const spine::PathConstraintSpacingTimeline& _0) { ::new (__instance) spine::PathConstraintSpacingTimeline(_0); }
class spine::PathConstraintSpacingTimeline& (spine::PathConstraintSpacingTimeline::*_222)(class spine::PathConstraintSpacingTimeline&&) = &spine::PathConstraintSpacingTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_PointAttachment_PointAttachment___1__N_spine_S_PointAttachment(void* __instance, const spine::PointAttachment& _0) { ::new (__instance) spine::PointAttachment(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_RegionAttachment_RegionAttachment___1__N_spine_S_RegionAttachment(void* __instance, const spine::RegionAttachment& _0) { ::new (__instance) spine::RegionAttachment(_0); }
int (spine::RotateTimeline::*_223)() = &spine::RotateTimeline::getBoneIndex;
void (spine::RotateTimeline::*_224)(int) = &spine::RotateTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_RotateTimeline_RotateTimeline___1__N_spine_S_RotateTimeline(void* __instance, const spine::RotateTimeline& _0) { ::new (__instance) spine::RotateTimeline(_0); }
class spine::RotateTimeline& (spine::RotateTimeline::*_225)(class spine::RotateTimeline&&) = &spine::RotateTimeline::operator=;
int (spine::TranslateTimeline::*_226)() = &spine::TranslateTimeline::getBoneIndex;
void (spine::TranslateTimeline::*_227)(int) = &spine::TranslateTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_TranslateTimeline_TranslateTimeline___1__N_spine_S_TranslateTimeline(void* __instance, const spine::TranslateTimeline& _0) { ::new (__instance) spine::TranslateTimeline(_0); }
class spine::TranslateTimeline& (spine::TranslateTimeline::*_228)(const class spine::TranslateTimeline&) = &spine::TranslateTimeline::operator=;
int (spine::TranslateXTimeline::*_229)() = &spine::TranslateXTimeline::getBoneIndex;
void (spine::TranslateXTimeline::*_230)(int) = &spine::TranslateXTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_TranslateXTimeline_TranslateXTimeline___1__N_spine_S_TranslateXTimeline(void* __instance, const spine::TranslateXTimeline& _0) { ::new (__instance) spine::TranslateXTimeline(_0); }
class spine::TranslateXTimeline& (spine::TranslateXTimeline::*_231)(const class spine::TranslateXTimeline&) = &spine::TranslateXTimeline::operator=;
int (spine::TranslateYTimeline::*_232)() = &spine::TranslateYTimeline::getBoneIndex;
void (spine::TranslateYTimeline::*_233)(int) = &spine::TranslateYTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_TranslateYTimeline_TranslateYTimeline___1__N_spine_S_TranslateYTimeline(void* __instance, const spine::TranslateYTimeline& _0) { ::new (__instance) spine::TranslateYTimeline(_0); }
class spine::TranslateYTimeline& (spine::TranslateYTimeline::*_234)(const class spine::TranslateYTimeline&) = &spine::TranslateYTimeline::operator=;
int (spine::ScaleTimeline::*_235)() = &spine::ScaleTimeline::getBoneIndex;
void (spine::ScaleTimeline::*_236)(int) = &spine::ScaleTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ScaleTimeline_ScaleTimeline___1__N_spine_S_ScaleTimeline(void* __instance, const spine::ScaleTimeline& _0) { ::new (__instance) spine::ScaleTimeline(_0); }
class spine::ScaleTimeline& (spine::ScaleTimeline::*_237)(const class spine::ScaleTimeline&) = &spine::ScaleTimeline::operator=;
int (spine::ScaleXTimeline::*_238)() = &spine::ScaleXTimeline::getBoneIndex;
void (spine::ScaleXTimeline::*_239)(int) = &spine::ScaleXTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ScaleXTimeline_ScaleXTimeline___1__N_spine_S_ScaleXTimeline(void* __instance, const spine::ScaleXTimeline& _0) { ::new (__instance) spine::ScaleXTimeline(_0); }
class spine::ScaleXTimeline& (spine::ScaleXTimeline::*_240)(const class spine::ScaleXTimeline&) = &spine::ScaleXTimeline::operator=;
int (spine::ScaleYTimeline::*_241)() = &spine::ScaleYTimeline::getBoneIndex;
void (spine::ScaleYTimeline::*_242)(int) = &spine::ScaleYTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ScaleYTimeline_ScaleYTimeline___1__N_spine_S_ScaleYTimeline(void* __instance, const spine::ScaleYTimeline& _0) { ::new (__instance) spine::ScaleYTimeline(_0); }
class spine::ScaleYTimeline& (spine::ScaleYTimeline::*_243)(const class spine::ScaleYTimeline&) = &spine::ScaleYTimeline::operator=;
int (spine::ShearTimeline::*_244)() = &spine::ShearTimeline::getBoneIndex;
void (spine::ShearTimeline::*_245)(int) = &spine::ShearTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ShearTimeline_ShearTimeline___1__N_spine_S_ShearTimeline(void* __instance, const spine::ShearTimeline& _0) { ::new (__instance) spine::ShearTimeline(_0); }
class spine::ShearTimeline& (spine::ShearTimeline::*_246)(const class spine::ShearTimeline&) = &spine::ShearTimeline::operator=;
int (spine::ShearXTimeline::*_247)() = &spine::ShearXTimeline::getBoneIndex;
void (spine::ShearXTimeline::*_248)(int) = &spine::ShearXTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ShearXTimeline_ShearXTimeline___1__N_spine_S_ShearXTimeline(void* __instance, const spine::ShearXTimeline& _0) { ::new (__instance) spine::ShearXTimeline(_0); }
class spine::ShearXTimeline& (spine::ShearXTimeline::*_249)(const class spine::ShearXTimeline&) = &spine::ShearXTimeline::operator=;
int (spine::ShearYTimeline::*_250)() = &spine::ShearYTimeline::getBoneIndex;
void (spine::ShearYTimeline::*_251)(int) = &spine::ShearYTimeline::setBoneIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_ShearYTimeline_ShearYTimeline___1__N_spine_S_ShearYTimeline(void* __instance, const spine::ShearYTimeline& _0) { ::new (__instance) spine::ShearYTimeline(_0); }
class spine::ShearYTimeline& (spine::ShearYTimeline::*_252)(const class spine::ShearYTimeline&) = &spine::ShearYTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Skeleton_Skeleton___1__N_spine_S_Skeleton(void* __instance, const spine::Skeleton& _0) { ::new (__instance) spine::Skeleton(_0); }
class spine::Skeleton& (spine::Skeleton::*_253)(const class spine::Skeleton&) = &spine::Skeleton::operator=;
void (spine::SkeletonBinary::*_254)(float) = &spine::SkeletonBinary::setScale;
class spine::String& (spine::SkeletonBinary::*_255)() = &spine::SkeletonBinary::getError;
extern "C" __declspec(dllexport) void c__N_spine_S_SkeletonBinary_SkeletonBinary___1__N_spine_S_SkeletonBinary(void* __instance, const spine::SkeletonBinary& _0) { ::new (__instance) spine::SkeletonBinary(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_SkeletonBounds_SkeletonBounds___1__N_spine_S_SkeletonBounds(void* __instance, const spine::SkeletonBounds& _0) { ::new (__instance) spine::SkeletonBounds(_0); }
class spine::SkeletonBounds& (spine::SkeletonBounds::*_256)(const class spine::SkeletonBounds&) = &spine::SkeletonBounds::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Polygon_Polygon(void* __instance) { ::new (__instance) spine::Polygon(); }
extern "C" __declspec(dllexport) void c__N_spine_S_Polygon_Polygon___1__N_spine_S_Polygon(void* __instance, const spine::Polygon& _0) { ::new (__instance) spine::Polygon(_0); }
class spine::Polygon& (spine::Polygon::*_257)(class spine::Polygon&&) = &spine::Polygon::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Triangulator_Triangulator___1__N_spine_S_Triangulator(void* __instance, const spine::Triangulator& _0) { ::new (__instance) spine::Triangulator(_0); }
class spine::Triangulator& (spine::Triangulator::*_258)(const class spine::Triangulator&) = &spine::Triangulator::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Triangulator_Triangulator(void* __instance) { ::new (__instance) spine::Triangulator(); }
extern "C" __declspec(dllexport) void c__N_spine_S_SkeletonClipping_SkeletonClipping___1__N_spine_S_SkeletonClipping(void* __instance, const spine::SkeletonClipping& _0) { ::new (__instance) spine::SkeletonClipping(_0); }
class spine::SkeletonClipping& (spine::SkeletonClipping::*_259)(class spine::SkeletonClipping&&) = &spine::SkeletonClipping::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_SkeletonData_SkeletonData___1__N_spine_S_SkeletonData(void* __instance, const spine::SkeletonData& _0) { ::new (__instance) spine::SkeletonData(_0); }
class spine::SkeletonData& (spine::SkeletonData::*_260)(const class spine::SkeletonData&) = &spine::SkeletonData::operator=;
void (spine::SkeletonJson::*_261)(float) = &spine::SkeletonJson::setScale;
class spine::String& (spine::SkeletonJson::*_262)() = &spine::SkeletonJson::getError;
extern "C" __declspec(dllexport) void c__N_spine_S_SkeletonJson_SkeletonJson___1__N_spine_S_SkeletonJson(void* __instance, const spine::SkeletonJson& _0) { ::new (__instance) spine::SkeletonJson(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_SkinEntry_SkinEntry_k___1__N_spine_S_String____N_spine_S_Attachment(void* __instance, unsigned long long slotIndex, const spine::String& name, spine::Attachment* attachment) { ::new (__instance) spine::SkinEntry(slotIndex, name, attachment); }
extern "C" __declspec(dllexport) void c__N_spine_S_SkinEntry_SkinEntry___1__N_spine_S_SkinEntry(void* __instance, const spine::SkinEntry& _0) { ::new (__instance) spine::SkinEntry(_0); }
struct spine::SkinEntry& (spine::SkinEntry::*_263)(struct spine::SkinEntry&&) = &spine::SkinEntry::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_SkinEntry__SkinEntry(spine::SkinEntry*__instance) { __instance->~SkinEntry(); }
bool (spine::SkinEntries::*_264)() = &spine::SkinEntries::hasNext;
struct spine::SkinEntry& (spine::SkinEntries::*_265)() = &spine::SkinEntries::next;
extern "C" __declspec(dllexport) void c__N_spine_S_SkinEntries_SkinEntries_____N_spine_S_Vector____N_spine_S_Vector____N_spine_S_SkinEntry(void* __instance, spine::Vector<spine::Vector<spine::SkinEntry>>& buckets) { ::new (__instance) spine::SkinEntries(buckets); }
extern "C" __declspec(dllexport) void c__N_spine_S_Skin_S_AttachmentMap_AttachmentMap___1__N_spine_S_Skin_S_AttachmentMap(void* __instance, const spine::Skin::AttachmentMap& _0) { ::new (__instance) spine::Skin::AttachmentMap(_0); }
class spine::Skin::AttachmentMap& (spine::Skin::AttachmentMap::*_266)(class spine::Skin::AttachmentMap&&) = &spine::Skin::AttachmentMap::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Skin_Skin___1__N_spine_S_Skin(void* __instance, const spine::Skin& _0) { ::new (__instance) spine::Skin(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_SlotData_SlotData___1__N_spine_S_SlotData(void* __instance, const spine::SlotData& _0) { ::new (__instance) spine::SlotData(_0); }
class c__N_spine_S_TextureLoader_TextureLoader___1__N_spine_S_TextureLoaderTextureLoader : public spine::TextureLoader { public: c__N_spine_S_TextureLoader_TextureLoader___1__N_spine_S_TextureLoaderTextureLoader(const spine::TextureLoader& _0): spine::TextureLoader(_0) {}; void load(spine::AtlasPage&, const spine::String&) {} void unload(void*) {}  };
extern "C" __declspec(dllexport) void c__N_spine_S_TextureLoader_TextureLoader___1__N_spine_S_TextureLoader(void* __instance, const spine::TextureLoader& _0) { ::new (__instance) c__N_spine_S_TextureLoader_TextureLoader___1__N_spine_S_TextureLoaderTextureLoader(_0); }
class spine::TextureLoader& (spine::TextureLoader::*_267)(const class spine::TextureLoader&) = &spine::TextureLoader::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_TransformConstraint_TransformConstraint___1__N_spine_S_TransformConstraint(void* __instance, const spine::TransformConstraint& _0) { ::new (__instance) spine::TransformConstraint(_0); }
extern "C" __declspec(dllexport) void c__N_spine_S_TransformConstraintData_TransformConstraintData___1__N_spine_S_TransformConstraintData(void* __instance, const spine::TransformConstraintData& _0) { ::new (__instance) spine::TransformConstraintData(_0); }
int (spine::TransformConstraintTimeline::*_268)() = &spine::TransformConstraintTimeline::getTransformConstraintIndex;
void (spine::TransformConstraintTimeline::*_269)(int) = &spine::TransformConstraintTimeline::setTransformConstraintIndex;
extern "C" __declspec(dllexport) void c__N_spine_S_TransformConstraintTimeline_TransformConstraintTimeline___1__N_spine_S_TransformConstraintTimeline(void* __instance, const spine::TransformConstraintTimeline& _0) { ::new (__instance) spine::TransformConstraintTimeline(_0); }
class spine::TransformConstraintTimeline& (spine::TransformConstraintTimeline::*_270)(class spine::TransformConstraintTimeline&&) = &spine::TransformConstraintTimeline::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vertices_Vertices___1__N_spine_S_Vertices(void* __instance, const spine::Vertices& _0) { ::new (__instance) spine::Vertices(_0); }
class spine::Vertices& (spine::Vertices::*_271)(class spine::Vertices&&) = &spine::Vertices::operator=;
extern "C" __declspec(dllexport) void c__N_spine_S_Vertices_Vertices(void* __instance) { ::new (__instance) spine::Vertices(); }
extern "C" __declspec(dllexport) void c__N_spine_S_UnitySpineCppTextureLoader_UnitySpineCppTextureLoader(void* __instance) { ::new (__instance) spine::UnitySpineCppTextureLoader(); }
extern "C" __declspec(dllexport) void c__N_spine_S_UnitySpineCppTextureLoader_UnitySpineCppTextureLoader___1__N_spine_S_UnitySpineCppTextureLoader(void* __instance, const spine::UnitySpineCppTextureLoader& _0) { ::new (__instance) spine::UnitySpineCppTextureLoader(_0); }
class spine::UnitySpineCppTextureLoader& (spine::UnitySpineCppTextureLoader::*_272)(const class spine::UnitySpineCppTextureLoader&) = &spine::UnitySpineCppTextureLoader::operator=;
class SpineUnity::SpineMesh& (SpineUnity::SpineMesh::*_273)(class SpineUnity::SpineMesh&&) = &SpineUnity::SpineMesh::operator=;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SubmeshInstruction_SubmeshInstruction(void* __instance) { ::new (__instance) SpineUnity::SubmeshInstruction(); }
int (SpineUnity::SubmeshInstruction::*_274)() = &SpineUnity::SubmeshInstruction::SlotCount;
struct SpineUnity::SubmeshInstruction (*_275)() = &SpineUnity::SubmeshInstruction::Default;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SubmeshInstruction_SubmeshInstruction___1__N_SpineUnity_S_SubmeshInstruction(void* __instance, const SpineUnity::SubmeshInstruction& _0) { ::new (__instance) SpineUnity::SubmeshInstruction(_0); }
struct SpineUnity::SubmeshInstruction& (SpineUnity::SubmeshInstruction::*_276)(struct SpineUnity::SubmeshInstruction&&) = &SpineUnity::SubmeshInstruction::operator=;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SubmeshInstruction__SubmeshInstruction(SpineUnity::SubmeshInstruction*__instance) { __instance->~SubmeshInstruction(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SkeletonRendererInstruction_SkeletonRendererInstruction___1__N_SpineUnity_S_SkeletonRendererInstruction(void* __instance, const SpineUnity::SkeletonRendererInstruction& _0) { ::new (__instance) SpineUnity::SkeletonRendererInstruction(_0); }
class SpineUnity::SkeletonRendererInstruction& (SpineUnity::SkeletonRendererInstruction::*_277)(class SpineUnity::SkeletonRendererInstruction&&) = &SpineUnity::SkeletonRendererInstruction::operator=;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SkeletonRendererInstruction__SkeletonRendererInstruction(SpineUnity::SkeletonRendererInstruction*__instance) { __instance->~SkeletonRendererInstruction(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SkeletonRendererInstruction_SkeletonRendererInstruction(void* __instance) { ::new (__instance) SpineUnity::SkeletonRendererInstruction(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SmartMesh_SmartMesh___1__N_SpineUnity_S_SmartMesh(void* __instance, const SpineUnity::SmartMesh& _0) { ::new (__instance) SpineUnity::SmartMesh(_0); }
class SpineUnity::SmartMesh& (SpineUnity::SmartMesh::*_278)(class SpineUnity::SmartMesh&&) = &SpineUnity::SmartMesh::operator=;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SmartMesh__SmartMesh(SpineUnity::SmartMesh*__instance) { __instance->~SmartMesh(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_SmartMesh_SmartMesh(void* __instance) { ::new (__instance) SpineUnity::SmartMesh(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_MeshRendererBuffers_MeshRendererBuffers___1__N_SpineUnity_S_MeshRendererBuffers(void* __instance, const SpineUnity::MeshRendererBuffers& _0) { ::new (__instance) SpineUnity::MeshRendererBuffers(_0); }
class SpineUnity::MeshRendererBuffers& (SpineUnity::MeshRendererBuffers::*_279)(class SpineUnity::MeshRendererBuffers&&) = &SpineUnity::MeshRendererBuffers::operator=;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_MeshRendererBuffers__MeshRendererBuffers(SpineUnity::MeshRendererBuffers*__instance) { __instance->~MeshRendererBuffers(); }
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_MeshRendererBuffers_MeshRendererBuffers(void* __instance) { ::new (__instance) SpineUnity::MeshRendererBuffers(); }
int (SpineUnity::MeshGenerator::*_280)() = &SpineUnity::MeshGenerator::VertexCount;
int (SpineUnity::MeshGenerator::*_281)(int) = &SpineUnity::MeshGenerator::SubmeshIndexCount;
extern "C" __declspec(dllexport) void c__N_SpineUnity_S_MeshGenerator__MeshGenerator(SpineUnity::MeshGenerator*__instance) { __instance->~MeshGenerator(); }
