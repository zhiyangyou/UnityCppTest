#pragma once

#include <memory>
#include <string>

#include "Bindings.h"
#include <spine/Skeleton.h>
#include "SpineCppAdapterCore.h"

//完成
namespace SpineUnity {
	SP_API class SpineMesh
	{
	public:
		static UnityEngine::Mesh NewSkeletonMesh();
	};

	SP_API struct SubmeshInstruction
	{
	public:
		SubmeshInstruction() : material(nullptr)
		{
		}
	public:
		spine::Skeleton* skeleton;
		int startSlot;
		int endSlot;
		UnityEngine::Material material;
		bool forceSeparate;
		int preActiveClippingSlotSource;
		int rawTriangleCount;
		int rawVertexCount;
		int rawFirstVertexIndex;
		bool hasClipping;
		bool hasPMAAdditiveSlot;
	public:
		int SlotCount() { return endSlot - startSlot; }
		Ref<std::string >ToString();
	public:
		static SubmeshInstruction Default() { return { }; }
	};
}