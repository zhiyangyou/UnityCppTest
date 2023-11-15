#pragma once
#include <spine/Vector.h>
#include <spine/Skeleton.h>

#include "SpineMesh.h"
#include "SpineCppAdapterCore.h"

//完成
namespace SpineUnity
{
	SP_API class SkeletonRendererInstruction
	{
	public:
		Ref<spine::Vector<SubmeshInstruction>> submeshInstructions = CreateRef<spine::Vector<SubmeshInstruction>>();
		bool immutableTriangles;

		bool hasActiveClipping;
		int rawVertexCount = -1;
		Ref<spine::Vector<spine::Attachment*>>attachments = CreateRef<spine::Vector<spine::Attachment*>>();

		void Clear();
		void DoDispose();
		void SetWithSubset(spine::Vector<SubmeshInstruction>& instructions, int startSubmesh, int endSubmesh);
		void Set(SkeletonRendererInstruction& other);
	public:
		static bool GeometryNotEqual(SkeletonRendererInstruction& a, SkeletonRendererInstruction& b);
	};
}

