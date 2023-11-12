#include "SpineMesh.h"

namespace SpineUnity {
	UnityEngine::Mesh SpineUnity::SpineMesh::NewSkeletonMesh()
	{
		UnityEngine::Mesh m = App::ObjectCreateProxy::CreateMesh();
		System::String sName("Skeleton Mesh CreateByCpp");
		m.SetName(sName);
		m.MarkDynamic();
		m.SetHideFlags(UnityEngine::HideFlags(UnityEngine::HideFlags::DontSaveInBuild.Value | UnityEngine::HideFlags::DontSaveInEditor.Value));
		return m;
	}

	Ref<std::string > SubmeshInstruction::ToString()
	{
		auto strMatName = material.Handle == 0 ? System::String("<none>") : material.GetName();
		return string_sprintf("[SubmeshInstruction: slots %d to %d. (Material)%s. preActiveClippingSlotSource:%d]\n",
			startSlot,
			endSlot - 1,
			Convert2StringAndFreePtr(App::ObjectCreateProxy::GetStringCStr(strMatName))->c_str(),
			preActiveClippingSlotSource
		);
	}
	

}
