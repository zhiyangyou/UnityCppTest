#include "SkeletonRendererInstruction.h"
#include <spine/spine.h>
namespace SpineUnity
{
	void SkeletonRendererInstruction::Clear()
	{
		attachments->clear();
		rawVertexCount = -1;
		hasActiveClipping = false;
		submeshInstructions->clear();
	}

	void SkeletonRendererInstruction::DoDispose()
	{
		attachments->clear();
	}

	void SkeletonRendererInstruction::SetWithSubset(spine::Vector<SubmeshInstruction>& instructions, int startSubmesh, int endSubmesh)
	{
		int runningVertexCount = 0;
		Ref<spine::Vector<SubmeshInstruction>> submeshes = submeshInstructions;
		submeshes->clear();
		int submeshCount = endSubmesh - startSubmesh;
		auto defualtSubmeshInstruction = SubmeshInstruction::Default();
		submeshes->setSize(submeshCount, defualtSubmeshInstruction);
		SubmeshInstruction* submeshesItems = submeshes->buffer();
		//SubmeshInstruction* instructionsItems = instructions.buffer();
		for (int i = 0; i < submeshCount; i++) {
			SubmeshInstruction& instruction = instructions[startSubmesh + i];
			(*(submeshesItems + i)) = instruction;

			hasActiveClipping |= instruction.hasClipping;
			(*submeshes)[i].rawFirstVertexIndex = runningVertexCount; // Ensure current instructions have correct cached values.
			runningVertexCount += instruction.rawVertexCount; // vertexCount will also be used for the rest of this method.
		}

		rawVertexCount = runningVertexCount;

		// assumption: instructions are contiguous. start and end are valid within instructions.

		int startSlot = instructions[startSubmesh].startSlot;
		int endSlot = instructions[endSubmesh - 1].endSlot;
		attachments->clear();
		int attachmentCount = endSlot - startSlot;
		attachments->setSize(attachmentCount, nullptr);
		//Attachment[] attachmentsItems = attachments.Items;

		//Slot[] drawOrderItems = instructionsItems[0].skeleton.DrawOrder.Items;
		spine::Vector<spine::Slot*>& drawOrderItems = instructions[0].skeleton->getDrawOrder();
		for (int i = 0; i < attachmentCount; i++) {
			spine::Slot* slot = drawOrderItems[startSlot + i];
			//if (!slot.Bone.Active) continue;
			if (!slot->getBone().isActive()) continue;
			(*attachments)[i] = slot->getAttachment();
		}
	}

	void SkeletonRendererInstruction::Set(SkeletonRendererInstruction& other)
	{
		immutableTriangles = other.immutableTriangles;

		hasActiveClipping = other.hasActiveClipping;
		rawVertexCount = other.rawVertexCount;

		attachments->clear();
		attachments->ensureCapacity(other.attachments->size());
		attachments->addAll(*(other.attachments));

		submeshInstructions->clear();
		submeshInstructions->ensureCapacity(other.submeshInstructions->size());
		submeshInstructions->addAll(*(other.submeshInstructions));
	}

	bool SkeletonRendererInstruction::GeometryNotEqual(SkeletonRendererInstruction& a, SkeletonRendererInstruction& b)
	{
		if (!UnityEngine::Application::GetIsPlaying())
			return true;

		if (a.hasActiveClipping || b.hasActiveClipping) return true; // Triangles are unpredictable when clipping is active.

		// Everything below assumes the raw vertex and triangle counts were used. (ie, no clipping was done)
		if (a.rawVertexCount != b.rawVertexCount) return true;

		if (a.immutableTriangles != b.immutableTriangles) return true;

		int attachmentCountB = b.attachments->size();
		if (a.attachments->size() != attachmentCountB) return true; // Bounds check for the looped storedAttachments count below.

		// Submesh count changed
		int submeshCountA = a.submeshInstructions->size();
		int submeshCountB = b.submeshInstructions->size();
		if (submeshCountA != submeshCountB) return true;

		// Submesh Instruction mismatch


		//Attachment[] attachmentsA = a.attachments.Items;
		//Attachment[] attachmentsB = b.attachments.Items;
		for (int i = 0; i < attachmentCountB; i++) {
			if ((*(a.attachments))[i] != (*(b.attachments))[i]) {
				return true;
			}
		}

		for (int i = 0; i < submeshCountB; i++) {
			SubmeshInstruction& submeshA = (*(a.submeshInstructions))[i];
			SubmeshInstruction& submeshB = (*(b.submeshInstructions))[i];

			if (!(
				submeshA.rawVertexCount == submeshB.rawVertexCount &&
				submeshA.startSlot == submeshB.startSlot &&
				submeshA.endSlot == submeshB.endSlot
				&& submeshA.rawTriangleCount == submeshB.rawTriangleCount &&
				submeshA.rawFirstVertexIndex == submeshB.rawFirstVertexIndex
				))
				return true;
		}

		return false;

	}

}

