#pragma once

#include "Bindings.h"
#include "SpineCppAdapterCore.h"

namespace SpineUnity {
	class SpineMesh
	{
	public:
		static UnityEngine::HideFlags MeshHideflags = static_cast<UnityEngine::HideFlags>(UnityEngine::HideFlags::DontSaveInBuild | UnityEngine::HideFlags::DontSaveInEditor);
		static UnityEngine::Mesh NewSkeletonMesh() {
			UnityEngine::Mesh m = new UnityEngine::Mesh(nullptr);
			m.MarkDynamic();
			m.name = "Skeleton Mesh";
			m.hideFlags = SpineMesh.MeshHideflags;
			return m;
		}

	};
}