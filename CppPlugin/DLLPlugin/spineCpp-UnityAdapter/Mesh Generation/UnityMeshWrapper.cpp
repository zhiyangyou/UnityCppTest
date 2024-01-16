
#include "UnityMeshWrapper.h"

#include <glm/vec3.hpp>

#include "Bindings.h"

using namespace  App;

namespace SpineUnity
{
	//ValueCount same witarrayValueCount
	typedef   void (*Mesh_SetArrayForChannelImpl_Injected)(void* unitySelf, \
		int vertexAttr, \
		int vertexAttrFormat, \
		int dim, \
		void* arrayPtr, \
		int ValueCount, \
		int arrayStartIndex, \
		int arrayValueCount, \
		int meshUpdtaeFlag\
		);

	typedef  void (*Mesh_SetIndicesNativeArrayImpl_Injected)(
		void* _unity_self,
		int submesh,
		int topology,
		int indicesFormat,
		void* indices,
		int arrayStart,
		int arraySize,
		bool calculateBounds,
		int baseVertex
		);


	Mesh_SetArrayForChannelImpl_Injected funcPtr_mesh_SetArrayForChannelImpl_Injected = nullptr;
	Mesh_SetIndicesNativeArrayImpl_Injected ptr_mesh_SetIndicesNativeArrayImpl_Injected = nullptr;

	Mesh_SetArrayForChannelImpl_Injected GetMeshSetArraryForChannelFuncPtr()
	{
		if (!funcPtr_mesh_SetArrayForChannelImpl_Injected)
		{
			funcPtr_mesh_SetArrayForChannelImpl_Injected = static_cast<Mesh_SetArrayForChannelImpl_Injected>(App::UnityUtils::GetMeshSetArrayForChannelImplFuncPtr());
		}
		return funcPtr_mesh_SetArrayForChannelImpl_Injected;
	}

	Mesh_SetIndicesNativeArrayImpl_Injected GetMeshSetIndicesFuncPtr()
	{
		if (!ptr_mesh_SetIndicesNativeArrayImpl_Injected)
		{
			ptr_mesh_SetIndicesNativeArrayImpl_Injected = static_cast<Mesh_SetIndicesNativeArrayImpl_Injected>(App::UnityUtils::GetMeshSetIndicesImplFuncPtr());
		}
		return ptr_mesh_SetIndicesNativeArrayImpl_Injected;
	}


	void MeshWrapper::SetVertices(UnityEngine::Mesh& mesh, glm::vec3* arr, int arraySize)
	{
		GetMeshSetArraryForChannelFuncPtr()(
			UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Position),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			3,
			static_cast<void*>(arr),
			arraySize,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetUVs(UnityEngine::Mesh& mesh, int channelId, glm::vec2* arr, int arraySize)
	{
		GetMeshSetArraryForChannelFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			channelId,
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			2,
			static_cast<void*>(arr),
			arraySize,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetUVs0(UnityEngine::Mesh& mesh, glm::vec2* arr, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord0), arr, arraySize);
	}

	void MeshWrapper::SetUVs2(UnityEngine::Mesh& mesh, glm::vec2* arr, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord1), arr, arraySize);
	}

	void MeshWrapper::SetUVs3(UnityEngine::Mesh& mesh, glm::vec2* arr, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord2), arr, arraySize);
	}

	void MeshWrapper::SetColor32(UnityEngine::Mesh& mesh, spine::Color32* arr, int arraySize)
	{
		GetMeshSetArraryForChannelFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Color),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::UNorm8),
			4,
			static_cast<void*>(arr),
			arraySize,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetNormals(UnityEngine::Mesh& mesh, glm::vec3* arr, int arraySize)
	{
		GetMeshSetArraryForChannelFuncPtr()
			(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
				static_cast<int>(UnityEngine::Rendering::VertexAttribute::Normal),
				static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
				3,		// C# : Mesh.DefaultDimensionForChannel(channel) 
				static_cast<void*>(arr),
				arraySize,
				0,
				arraySize,
				static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
				);
	}

	void MeshWrapper::SetTangents(UnityEngine::Mesh& mesh, glm::vec4* arr, int arraySize)
	{

		GetMeshSetArraryForChannelFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Tangent),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			4,		 // C#:  Mesh.DefaultDimensionForChannel(channel)
			static_cast<void*>(arr),
			arraySize,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default));
	}

	void MeshWrapper::SetTriangle(UnityEngine::Mesh& mesh, int* indexArr, int arrayLen, int subMeshIndex, bool needCaculateBounds)
	{
		GetMeshSetIndicesFuncPtr()(
			UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			subMeshIndex,
			static_cast<int>(UnityEngine::MeshTopology::Triangles),
			static_cast<int>(UnityEngine::Rendering::IndexFormat::UInt32),
			static_cast<void*>(indexArr),
			0,
			arrayLen,
			needCaculateBounds,
			0
			);
	}

}

