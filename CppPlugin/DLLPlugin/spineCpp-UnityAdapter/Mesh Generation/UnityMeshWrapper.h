#pragma once
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <spine/Color.h>

#include "Bindings.h"

namespace  SpineUnity
{
	class MeshWrapper
	{
	public:
		static void SetVertices(UnityEngine::Mesh& mesh, glm::vec3* arr, int arrayMemLength, int arrarSize);
		static void SetUVs(UnityEngine::Mesh& mesh, int channelId, glm::vec2* arr, int arrayMemLength, int arraySize);
		static void SetUVs0(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize);
		static void SetUVs2(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize);
		static void SetUVs3(UnityEngine::Mesh& mesh, glm::vec2* arr, int arrayMemLength, int arraySize);
		static void SetColor32(UnityEngine::Mesh& mesh, spine::Color32* arr, int arrayMemLength, int arraySize);
		static void SetNormals(UnityEngine::Mesh& mesh, glm::vec3* arr, int arrayMemLength, int arraySize);
		static void SetTangents(UnityEngine::Mesh& mesh, glm::vec4* arr, int arrayMemLength, int arraySize);
	};
}
