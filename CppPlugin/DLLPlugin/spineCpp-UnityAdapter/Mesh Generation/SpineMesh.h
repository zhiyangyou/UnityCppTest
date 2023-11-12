#pragma once

#include <memory>
#include <string>

#include "Bindings.h"
#include <spine/Skeleton.h>
#include "SpineCppAdapterCore.h"

namespace SpineUnity {
	SP_API class SpineMesh
	{
	public:
		static UnityEngine::Mesh NewSkeletonMesh();
	};

	SP_API struct SubmeshInstruction
	{
	public:
		SubmeshInstruction(): material(nullptr)
		{
		}

		Ref<spine::Skeleton>skeleton;
		int startSlot;
		int endSlot;
		UnityEngine::Material material ;
		bool forceSeparate;
		int preActiveClippingSlotSource;

		int rawTriangleCount;
		int rawVertexCount;
		int rawFirstVertexIndex;
		bool hasClipping;

		bool hasPMAAdditiveSlot;

		int SlotCount() { return endSlot - startSlot; }

		Ref<std::string >ToString();
		static SubmeshInstruction Default() { return { }; }
	};
}