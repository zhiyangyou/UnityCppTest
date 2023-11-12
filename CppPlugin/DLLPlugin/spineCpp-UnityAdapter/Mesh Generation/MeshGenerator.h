#pragma once
#include <limits>
#include <memory>
#include <vector>

#include <spine/Vector.h>
#include <spine/Color.h>
#include <spine/SkeletonClipping.h>

#include "Bindings.h"
#include "SpineCppAdapterCore.h"
#include "unity_spinecpp_plugin.h"
namespace SpineUnity {

	SP_API class MeshGenerator {
		struct Settings {
			bool useClipping;
			float zSpacing;
			bool pmaVertexColors;
			bool tintBlack;
			bool canvasGroupTintBlack;
			bool calculateTangents;
			bool addNormals;
			bool immutableTriangles;
			static Settings Default() {
				return { true,0.0,true,false,false,false,false };
			}
		};

	public:
		Settings settings() { return MeshGenerator::Settings::Default(); }
		const float BoundsMinDefault = std::numeric_limits<float>::min();
		const float BoundsMaxDefault = std::numeric_limits<float>::max();
		MeshGenerator();
		MeshGenerator(const MeshGenerator&) = delete;
		MeshGenerator(const MeshGenerator&&) = delete;
	private:

		Ref<spine::Vector<UnityEngine::Vector3>> vertexBuffer = CreateRef<spine::Vector<UnityEngine::Vector3>>();
		Ref<spine::Vector<UnityEngine::Vector2>> uvBuffer = CreateRef<spine::Vector<UnityEngine::Vector2>>();
		Ref<spine::Vector<spine::Color32>> colorBuffer = CreateRef<spine::Vector<spine::Color32>>();
		Ref<spine::Vector<Ref< spine::Vector<int>>>> submeshes = CreateRef<spine::Vector<Ref< spine::Vector<int>>>>();

		UnityEngine::Vector2 meshBoundsMin;
		UnityEngine::Vector2 meshBoundsMax;
		float meshBoundsThickness = 0;
		int submeshIndex = 0;


		Ref <spine::SkeletonClipping> clipper = CreateRef<spine::SkeletonClipping>();
		Ref <std::vector<float>>tempVerts = CreateRef<std::vector<float>>();
		Ref <std::vector<int>>regionTriangles = CreateRef<std::vector<int>>(std::initializer_list<int>{0, 1, 2, 2, 3, 0 });

		Ref<std::vector<UnityEngine::Vector3>> normals = CreateRef<std::vector<UnityEngine::Vector3>>();
		Ref<std::vector<UnityEngine::Vector4>> tangents = CreateRef<std::vector<UnityEngine::Vector4>>();
		Ref<std::vector<UnityEngine::Vector2>> tempTanBuffer = CreateRef<std::vector<UnityEngine::Vector2>>();

		Ref<spine::Vector<UnityEngine::Vector2>> uv2 = CreateRef<spine::Vector<UnityEngine::Vector2>>();
		Ref<spine::Vector<UnityEngine::Vector2>> uv3 = CreateRef<spine::Vector<UnityEngine::Vector2>>();

	public:
		inline int VertexCount() {
			return  vertexBuffer->size();
		}
		inline int SubmeshIndexCount(int submeshIndex)
		{
			if (submeshIndex >= submeshes->size() || submeshIndex < 0)
			{
				UnityDebugLog("MeshGenerator::SubmeshIndexCount error index out of range !!!");
				return 0;
			}
			return  (*submeshes)[submeshIndex]->size();
		}
	public:
		static void GenerateSingleSubmeshInstruction();  

	};


};