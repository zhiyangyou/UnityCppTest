#include "MeshRendererBuffers.h"

namespace SpineUnity
{



	int32_t SmartMesh::GetMesh()
	{
		return mesh.Handle;
	}

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

	spine::Vector<int32_t> MeshRendererBuffers::GetUpdatedSharedMaterialsArray_Handles()
	{
		auto mats = GetUpdatedSharedMaterialsArray();
		spine::Vector<int32_t> v;
		for (int i = 0; i < mats->size(); i++)
		{
			v.add(((mats->buffer() + i))->Handle);
		}
		return v;
	}

	bool MeshRendererBuffers::MaterialsChangedInLastUpdate()
	{
		int newSubmeshMaterials = submeshMaterials->size();

		if (newSubmeshMaterials != sharedMaterials->size()) return true;

		//Material[] submeshMaterialsItems = submeshMaterials.Items;
		for (int i = 0; i < newSubmeshMaterials; i++)
		{
			if ((*submeshMaterials)[i].Handle == (*sharedMaterials)[i].Handle)
			{
				return true;
			}
		}
		return false;
	}

	void MeshRendererBuffers::UpdateSharedMaterials(spine::Vector<SubmeshInstruction>& instructions)
	{
		int newSize = instructions.size();
		{
			if (newSize > submeshMaterials->size())
			{
				submeshMaterials->ensureCapacity(newSize);
			}
		}

		UnityEngine::Material* submeshMaterialsItems = submeshMaterials->buffer();
		for (int i = 0; i < newSize; i++)
		{
			*(submeshMaterialsItems + i) = instructions[i].material;
		}
	}

	SpineUnity::SmartMesh& MeshRendererBuffers::GetNextMesh_CSharp()
	{
		return  *(doubleBufferedMesh->GetNext());
	}

	Ref<SpineUnity::SmartMesh> MeshRendererBuffers::GetNextMesh2()
	{
		return  doubleBufferedMesh->GetNext();
	}

	void MeshRendererBuffers::Clear()
	{
		sharedMaterials->clear();
		submeshMaterials->clear();
	}

	void MeshRendererBuffers::DoDispose()
	{
		if (doubleBufferedMesh == nullptr ) return;
		doubleBufferedMesh->GetNext()->DoDispose();
		doubleBufferedMesh->GetNext()->DoDispose();
		doubleBufferedMesh = nullptr;
	}

}

