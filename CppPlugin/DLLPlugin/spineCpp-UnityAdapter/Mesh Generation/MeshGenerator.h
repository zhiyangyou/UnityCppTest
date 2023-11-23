#pragma once
#include <limits>
#include <memory>
#include <vector>
#include <initializer_list>
#include <glm/glm.hpp> 

#include <spine/Vector.h>
#include <spine/Color.h>
#include <spine/SkeletonClipping.h>

#include "Bindings.h"
#include "SkeletonRendererInstruction.h"
#include "SpineCppAdapterCore.h"
#include "unity_spinecpp_plugin.h"

namespace SpineUnity {
	struct Bounds
	{
		glm::vec3 Center;
		glm::vec3  Extents;

		static Bounds Default()
		{
			return { {0.0f,0.0f,0.0f}, {0.0f,0.0f,0.0f} };
		}
	};

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
		Ref<spine::Vector<glm::vec3>> vertexBuffer = CreateRef<spine::Vector<glm::vec3>>();
		Ref<spine::Vector<glm::vec2>> uvBuffer = CreateRef<spine::Vector<glm::vec2>>();
		Ref<spine::Vector<spine::Color32>> colorBuffer = CreateRef<spine::Vector<spine::Color32>>();

		Ref<spine::Vector<spine::Vector<int>*>> submeshes = CreateRef<spine::Vector< spine::Vector<int>*>>();

		glm::vec2 meshBoundsMin;
		glm::vec2 meshBoundsMax;
		float meshBoundsThickness = 0;
		int submeshIndex = 0;


		Ref <spine::SkeletonClipping> clipper = CreateRef<spine::SkeletonClipping>();
		Ref <spine::Vector<float>>tempVerts = CreateRef<spine::Vector<float>>();
		Ref <spine::Vector<unsigned short>>regionTriangles = CreateRef<spine::Vector<unsigned short>>(std::initializer_list<unsigned short>{0, 1, 2, 2, 3, 0 });

		Ref<spine::Vector<glm::vec3>> normals = CreateRef<spine::Vector<glm::vec3>>();
		Ref<spine::Vector<glm::vec4>> tangents = CreateRef<spine::Vector<glm::vec4>>();
		Ref<spine::Vector<glm::vec2>> tempTanBuffer = CreateRef<spine::Vector<glm::vec2>>();

		Ref<spine::Vector<glm::vec2>> uv2 = CreateRef<spine::Vector<glm::vec2>>();
		Ref<spine::Vector<glm::vec2>> uv3 = CreateRef<spine::Vector<glm::vec2>>();

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
		//Step 1 : Generate Instructions
		static void GenerateSingleSubmeshInstruction(SkeletonRendererInstruction& instructionOutput, spine::Skeleton& skeleton, UnityEngine::Material& material);
		static bool RequiresMultipleSubmeshesByDrawOrder(spine::Skeleton& skeleton);
		static void GenerateSkeletonRendererInstruction(SkeletonRendererInstruction& instructionOutput,
			spine::Skeleton* skeleton,
			spine::HashMap<spine::Slot*, UnityEngine::Material>* customSlotMaterials,
			spine::Vector<spine::Slot*>* separatorSlots,
			bool generateMeshOverride,
			bool immutableTriangles = false);
		static void TryReplaceMaterials(
			spine::Vector<SubmeshInstruction>* workingSubmeshInstructions,
			spine::HashMap<UnityEngine::Material, UnityEngine::Material>* customMaterialOverride);
	public:
		// Step 2 : Populate vertex data and triangle index buffers.
		void Begin();
		void AddSubmesh(SubmeshInstruction& instruction, bool updateTriangles = true);
		void BuildMesh(SkeletonRendererInstruction& instruction, bool updateTriangles);
		void BuildMeshWithArrays(SkeletonRendererInstruction& instruction, bool updateTriangles);
		void ScaleVertexData(float scale);
		SpineUnity::Bounds GetMeshBounds();
		void AddAttachmentTintBlack(float r2, float g2, float b2, float a, int vertexCount);
	public:
		// Step 3 : Transfer vertex and triangle data to UnityEngine.Mesh
		2023年11月23日23:47:10 
	};


};