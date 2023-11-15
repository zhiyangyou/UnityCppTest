#pragma once

#include <vector>

#include "Bindings.h"
#include "DoubleBuffered.h"
#include "SkeletonRendererInstruction.h"
#include "SpineCppAdapterCore.h"
#include "SpineMesh.h"

namespace SpineUnity
{

	SP_API class SmartMesh 
	{
	public:
		UnityEngine::Mesh mesh = SpineMesh::NewSkeletonMesh();

		int32_t GetMesh();
		Ref<SkeletonRendererInstruction> instructionUsed = CreateRef<SkeletonRendererInstruction>();
		void Clear();
		void DoDispose();
	};

	SP_API class MeshRendererBuffers
	{
	private:
		Ref <DoubleBuffered<SmartMesh>>doubleBufferedMesh = nullptr;
	public:
		Ref<spine::Vector<UnityEngine::Material>>submeshMaterials = CreateRef<spine::Vector<UnityEngine::Material>>();
		Ref<spine::Vector<UnityEngine::Material>>  sharedMaterials = CreateRef<spine::Vector<UnityEngine::Material>>();
	public:
		void Initialize();
		Ref<spine::Vector<UnityEngine::Material>> GetUpdatedSharedMaterialsArray();
		bool MaterialsChangedInLastUpdate();// 2023年11月12日15:43:33  处理这个方法的实现
	};

}

