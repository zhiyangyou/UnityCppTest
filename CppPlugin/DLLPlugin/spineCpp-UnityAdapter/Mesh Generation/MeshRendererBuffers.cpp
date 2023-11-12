#include "MeshRendererBuffers.h"

namespace SpineUnity
{
	void SmartMesh::Clear()
	{
		mesh.Clear();
		instructionUsed->Clear();
	}

	void SmartMesh::DoDispose()
	{
		if (mesh.Handle != 0) {
			if (App::UnityUtils::IsUnityEditor()) {
				if (UnityEngine::Application::GetIsEditor() && !UnityEngine::Application::GetIsPlaying())
					UnityEngine::Object::DestroyImmediate(mesh);
				else
					UnityEngine::Object::Destroy(mesh);
			}
			else {
				UnityEngine::Object::Destroy(mesh);
			}
		}
		//mesh = null;
		mesh = {};		// replace this.mesh object , origin this.mesh struct's dctor will auto be called
	}

	void MeshRendererBuffers::Initialize() {
		if (doubleBufferedMesh != nullptr) {
			doubleBufferedMesh->GetNext()->Clear();
			doubleBufferedMesh->GetNext()->Clear();
			submeshMaterials->clear();
		}
		else {
			doubleBufferedMesh = CreateRef<DoubleBuffered<SmartMesh>>();
		}
	}

	Ref<spine::Vector<UnityEngine::Material>> MeshRendererBuffers::GetUpdatedSharedMaterialsArray()
	{
		sharedMaterials->clear();
		sharedMaterials->addAll((*submeshMaterials));
		return sharedMaterials;
	}

}

