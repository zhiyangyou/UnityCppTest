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

}
