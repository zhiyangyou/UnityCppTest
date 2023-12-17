
#include "UnityMeshWrapper.h"

#include <glm/vec3.hpp>

#include "Bindings.h"

using namespace  App;
namespace SpineUnity
{
	typedef  void (*Mesh_SetArrayForChannelImpl_Injected)(void* unitySelf, int vertexAttr, int vertexAttrFormat, int dim, void* arrayPtr, int arrayMemLen, int arrayStartIndex, int arrayValueCount, int meshUpdtaeFlag);
	Mesh_SetArrayForChannelImpl_Injected* mesh_set_array_for_channel_impl = nullptr;


	Mesh_SetArrayForChannelImpl_Injected* GetMeshFuncPtr()
	{
		if (!mesh_set_array_for_channel_impl)
		{
			mesh_set_array_for_channel_impl = static_cast<Mesh_SetArrayForChannelImpl_Injected*>(App::UnityUtils::GetMeshSetArrayForChannelImplFuncPtr());
		}
		return mesh_set_array_for_channel_impl;
	}

	void MeshWrapper::SetVertices(UnityEngine::Mesh& mesh, glm::vec3* arr, int arrayMemLength, int arrarSize)
	{
		//TODO safe check ...
		GetMeshFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Position),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			3,
			arr,
			arrayMemLength,
			0,
			arrarSize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetUVs(UnityEngine::Mesh& mesh, int channelId, glm::vec2* arr, int arrayMemLength, int arraySize)
	{
		//TODO safe check ...
		GetMeshFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			channelId,
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			2,
			arr,
			arrayMemLength,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetUVs0(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord0), arr, arrayMemLength, arraySize);
	}

	void MeshWrapper::SetUVs2(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord1), arr, arrayMemLength, arraySize);
	}

	void MeshWrapper::SetUVs3(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize)
	{
		SetUVs(mesh, static_cast<int>(UnityEngine::Rendering::VertexAttribute::TexCoord2), arr, arrayMemLength, arraySize);
	}

	void MeshWrapper::SetColor32(UnityEngine::Mesh& mesh, spine::Color32* arr, int arrayMemLength, int arraySize)
	{
		GetMeshFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Color),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::UNorm8),
			4,
			arr,
			arrayMemLength,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetNormals(UnityEngine::Mesh& mesh, glm::vec3* arr, int arrayMemLength, int arraySize)
	{
		GetMeshFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Normal),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32) ,
			3,		// C# : Mesh.DefaultDimensionForChannel(channel) 
			arr,
			arrayMemLength,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

	void MeshWrapper::SetTangents(UnityEngine::Mesh& mesh, glm::vec4* arr, int arrayMemLength, int arraySize)
	{
		GetMeshFuncPtr()(UnityUtils::GetMeshUnitySelfIntPtr(UnityUtils::GetUnityObjectInstanceId(mesh.Handle).Value),
			static_cast<int>(UnityEngine::Rendering::VertexAttribute::Tangent),
			static_cast<int>(UnityEngine::Rendering::VertexAttributeFormat::Float32),
			4,		 // C#:  Mesh.DefaultDimensionForChannel(channel)
			arr,
			arrayMemLength,
			0,
			arraySize,
			static_cast<int>(UnityEngine::Rendering::MeshUpdateFlags::Default)
			);
	}

}

