
#include "MeshGenerator.h"

#include <spine/spine.h>

namespace SpineUnity {





	MeshGenerator::MeshGenerator()
	{
		submeshes->add(CreateRef<spine::Vector<int>>()); // start with 1 submesh.
	}


	template<typename   T>
	static bool IsThisAttachment(spine::Attachment* att)
	{
		return att->getRTTI().instanceOf(T::rtti);
	}

	void MeshGenerator::GenerateSingleSubmeshInstruction(SkeletonRendererInstruction& instructionOutput, spine::Skeleton& skeleton, UnityEngine::Material& material)
	{
		using namespace spine;
		Vector<Slot*>& drawOrder = skeleton.getDrawOrder();
		int drawOrderCount = drawOrder.size();

		// Clear last state of attachments and submeshes
		instructionOutput.Clear(); // submeshInstructions.Clear(); attachments.Clear();
		Ref<Vector<SubmeshInstruction>> workingSubmeshInstructions = instructionOutput.submeshInstructions;

		instructionOutput.attachments->setSize(drawOrderCount, nullptr);

		Ref<Vector<Attachment*>> workingAttachmentsItems = instructionOutput.attachments;
		int totalRawVertexCount = 0;
		SubmeshInstruction current;
		current.skeleton = &skeleton;
		current.preActiveClippingSlotSource = -1;
		current.startSlot = 0;
		current.rawFirstVertexIndex = 0;
		current.material = material;
		current.forceSeparate = false;
		current.endSlot = drawOrderCount;

		void* rendererObject = nullptr;
		bool skeletonHasClipping = false;

		for (int i = 0; i < drawOrderCount; i++) {
			Slot* slot = drawOrder[i];
			if (!slot->getBone().isActive()) {
				(*workingAttachmentsItems)[i] = nullptr;
				continue;
			}
			if (slot->getData().getBlendMode() == BlendMode_Additive) current.hasPMAAdditiveSlot = true;
			Attachment* attachment = slot->getAttachment();

			(*workingAttachmentsItems)[i] = attachment;
			int attachmentTriangleCount = 0;
			int attachmentVertexCount = 0;

			if (IsThisAttachment<RegionAttachment>(attachment))
			{
				RegionAttachment* regionAttachment = static_cast<RegionAttachment*>(attachment);
				if (regionAttachment->getSequence() != nullptr)
				{
					regionAttachment->getSequence()->apply(slot, regionAttachment);
				}
				rendererObject = regionAttachment->getRegion();
				attachmentVertexCount = 4;
				attachmentTriangleCount = 6;
			}
			else if (IsThisAttachment<MeshAttachment>(attachment))
			{
				MeshAttachment* meshAttachment = static_cast<MeshAttachment*>(attachment);
				if (meshAttachment->getSequence() != nullptr)
				{
					meshAttachment->getSequence()->apply(slot, meshAttachment);
				}
				rendererObject = meshAttachment->getRegion();
				attachmentVertexCount = meshAttachment->getWorldVerticesLength() >> 1;
				attachmentTriangleCount = meshAttachment->getTriangles().size();
			}
			else if (IsThisAttachment<ClippingAttachment>(attachment))
			{
				ClippingAttachment* clippingAttachment = static_cast<ClippingAttachment*>(attachment);
				current.hasClipping = true;
				skeletonHasClipping = true;
				attachmentVertexCount = 0;
				attachmentTriangleCount = 0;
			}
			current.rawTriangleCount += attachmentTriangleCount;
			current.rawVertexCount += attachmentVertexCount;
			totalRawVertexCount += attachmentVertexCount;
		}

		if (material.Handle == 0 && rendererObject != nullptr)
		{
			//current.material = (Material)((AtlasRegion)rendererObject).page.rendererObject;
			current.material = UnityEngine::Material(Plugin::InternalUse::Only, ((AtlasRegion*)rendererObject)->page->ConvertTexture2Handle());
		}

		instructionOutput.hasActiveClipping = skeletonHasClipping;
		instructionOutput.rawVertexCount = totalRawVertexCount;


		if (totalRawVertexCount > 0) {
			workingSubmeshInstructions->setSize(1, SubmeshInstruction::Default());
			(*workingSubmeshInstructions)[0] = current;
		}
		else {
			workingSubmeshInstructions->setSize(0, SubmeshInstruction::Default());
		}
	}



	bool MeshGenerator::RequiresMultipleSubmeshesByDrawOrder(spine::Skeleton& skeleton)
	{
		using namespace spine;
		Vector<Slot*>& drawOrder = skeleton.getDrawOrder();
		int drawOrderCount = drawOrder.size();

		UnityEngine::Material lastRendererMaterial(Plugin::InternalUse::Only, 0);
		for (int i = 0; i < drawOrderCount; i++) {
			Slot* slot = drawOrder[i];
			if (!slot->getBone().isActive()) continue;
			Attachment* attachment = slot->getAttachment();
			//
			if (attachment->getRTTI().instanceOf(MeshAttachment::rtti))
			{
				MeshAttachment* rendererAttachment = static_cast<MeshAttachment*>(attachment);
				if (rendererAttachment->getSequence() != nullptr) rendererAttachment->getSequence()->apply(slot, rendererAttachment);
				AtlasRegion* atlasRegion = (AtlasRegion*)rendererAttachment->getRegion();
				UnityEngine::Material material = UnityEngine::Material(Plugin::InternalUse::Only, atlasRegion->page->ConvertTexture2Handle());

				if (lastRendererMaterial.Handle != material.Handle) {
					if (lastRendererMaterial.Handle != 0)
					{
						return true;
					}
					lastRendererMaterial = material;
				}
			}
			else if (attachment->getRTTI().instanceOf(RegionAttachment::rtti))
			{
				RegionAttachment* rendererAttachment = static_cast<RegionAttachment*>(attachment);
				if (rendererAttachment->getSequence() != nullptr) rendererAttachment->getSequence()->apply(slot, rendererAttachment);
				AtlasRegion* atlasRegion = (AtlasRegion*)rendererAttachment->getRegion();
				UnityEngine::Material material = UnityEngine::Material(Plugin::InternalUse::Only, atlasRegion->page->ConvertTexture2Handle());
				if (lastRendererMaterial.Handle != material.Handle) {
					if (lastRendererMaterial.Handle != 0)
					{
						return true;
					}
					lastRendererMaterial = material;
				}
			}

		}
		return false;
	}

	void MeshGenerator::GenerateSkeletonRendererInstruction(
		SkeletonRendererInstruction& instructionOutput,
		spine::Skeleton* skeleton,
		spine::HashMap<spine::Slot*, UnityEngine::Material>* customSlotMaterials,
		spine::Vector<spine::Slot*>* separatorSlots,
		bool generateMeshOverride,
		bool immutableTriangles /*= false*/
	)
	{
		using namespace spine;
		Vector<Slot*>& drawOrder = skeleton->getDrawOrder();
		int drawOrderCount = drawOrder.size();

		// Clear last state of attachments and submeshes
		instructionOutput.Clear(); // submeshInstructions.Clear(); attachments.Clear();
		Ref<Vector<SubmeshInstruction>> workingSubmeshInstructions = instructionOutput.submeshInstructions;

		//instructionOutput.attachments.Resize(drawOrderCount);
		instructionOutput.attachments->setSize(drawOrderCount, nullptr);
		//Attachment[] workingAttachmentsItems = instructionOutput.attachments.Items;
		int totalRawVertexCount = 0;
		bool skeletonHasClipping = false;


		SubmeshInstruction current;
		current.skeleton = skeleton;
		current.preActiveClippingSlotSource = -1;

		bool isCustomSlotMaterialsPopulated = customSlotMaterials != nullptr && customSlotMaterials->size() > 0;

		int separatorCount = separatorSlots == nullptr ? 0 : separatorSlots->size();
		bool hasSeparators = separatorCount > 0;

		int clippingAttachmentSource = -1;
		int lastPreActiveClipping = -1; // The index of the last slot that had an active ClippingAttachment.
		SlotData* clippingEndSlot = nullptr;
		int submeshIndex = 0;
		//Slot[] drawOrderItems = drawOrder.Items;
		for (int i = 0; i < drawOrderCount; i++)
		{
			Slot* slot = drawOrder[i];
			if (!slot->getBone().isActive()) {
				(*instructionOutput.attachments)[i] = nullptr;
				continue;
			}
			if (slot->getData().getBlendMode() == BlendMode_Additive) current.hasPMAAdditiveSlot = true;
			Attachment* attachment = slot->getAttachment();

			(*instructionOutput.attachments)[i] = attachment;
			int attachmentVertexCount = 0, attachmentTriangleCount = 0;

			TextureRegion* region = nullptr;
			bool noRender = false;			// Using this allows empty slots as separators, and keeps separated parts more stable despite slots being reordered

			if (IsThisAttachment<RegionAttachment>(attachment))
			{
				RegionAttachment* regionAttachment = static_cast<RegionAttachment*>(attachment);
				if (regionAttachment->getSequence() != nullptr)
				{
					regionAttachment->getSequence()->apply(slot, regionAttachment);
				}
				region = regionAttachment->getRegion();
				attachmentVertexCount = 4;
				attachmentTriangleCount = 6;
			}
			else if (IsThisAttachment<MeshAttachment>(attachment))
			{
				MeshAttachment* meshAttachment = static_cast<MeshAttachment*>(attachment);
				if (meshAttachment->getSequence() != nullptr) meshAttachment->getSequence()->apply(slot, meshAttachment);
				region = meshAttachment->getRegion();
				attachmentVertexCount = meshAttachment->getWorldVerticesLength() >> 1;
				attachmentTriangleCount = meshAttachment->getTriangles().size();
			}
			else if (IsThisAttachment<ClippingAttachment>(attachment))
			{
				ClippingAttachment* clippingAttachment = static_cast<ClippingAttachment*>(attachment);
				clippingEndSlot = clippingAttachment->getEndSlot();
				clippingAttachmentSource = i;
				current.hasClipping = true;
				skeletonHasClipping = true;
				noRender = true;
			}


			// Create a new SubmeshInstruction when material changes. (or when forced to separate by a submeshSeparator)
			// Slot with a separator/new material will become the starting slot of the next new instruction.
			if (hasSeparators) //current.forceSeparate = hasSeparators && separatorSlots.Contains(slot);
			{
				current.forceSeparate = false;
				for (int s = 0; s < separatorCount; s++)
				{
					if ((*separatorSlots)[s] == slot)
					{
						current.forceSeparate = true;
						break;
					}
				}
			}

			if (noRender)
			{
				if (current.forceSeparate && generateMeshOverride) { // && current.rawVertexCount > 0) {
					{ // Add
						current.endSlot = i;
						current.preActiveClippingSlotSource = lastPreActiveClipping;

						workingSubmeshInstructions->setSize(submeshIndex + 1, SubmeshInstruction::Default());
						(*workingSubmeshInstructions)[submeshIndex] = current;
						submeshIndex++;
					}

					current.startSlot = i;
					lastPreActiveClipping = clippingAttachmentSource;

					current.rawTriangleCount = 0;
					current.rawVertexCount = 0;
					current.rawFirstVertexIndex = totalRawVertexCount;
					current.hasClipping = clippingAttachmentSource >= 0;

				}
			}
			else
			{
				UnityEngine::Material material(Plugin::InternalUse::Only, 0);
				if (isCustomSlotMaterialsPopulated)
				{
					if (customSlotMaterials->containsKey(slot))
					{
						material = (*customSlotMaterials)[slot];
					}
					else
					{
						material = UnityEngine::Material(Plugin::InternalUse::Only, ((AtlasRegion*)region)->page->ConvertTexture2Handle());
					}
				}
				else
				{
					material = UnityEngine::Material(Plugin::InternalUse::Only, ((AtlasRegion*)region)->page->ConvertTexture2Handle());
				}

				if (current.forceSeparate || (current.rawVertexCount > 0 && !(current.material.Handle == material.Handle))) { // Material changed. Add the previous submesh.
					{ // Add
						current.endSlot = i;
						current.preActiveClippingSlotSource = lastPreActiveClipping;

						workingSubmeshInstructions->setSize(submeshIndex + 1, SubmeshInstruction::Default());
						(*workingSubmeshInstructions)[submeshIndex] = current;
						submeshIndex++;
					}
					current.startSlot = i;
					lastPreActiveClipping = clippingAttachmentSource;

					current.rawTriangleCount = 0;
					current.rawVertexCount = 0;
					current.rawFirstVertexIndex = totalRawVertexCount;
					current.hasClipping = clippingAttachmentSource >= 0;
				}

				// Update state for the next Attachment.
				current.material = material;

				current.rawTriangleCount += attachmentTriangleCount;
				current.rawVertexCount += attachmentVertexCount;
				current.rawFirstVertexIndex = totalRawVertexCount;
				totalRawVertexCount += attachmentVertexCount;

			}

			if (clippingEndSlot != nullptr && (&(slot->getData())) == clippingEndSlot && i != clippingAttachmentSource) {
				clippingEndSlot = nullptr;
				clippingAttachmentSource = -1;
			}
		}

		if (current.rawVertexCount > 0) {
			{ // Add last or only submesh.
				current.endSlot = drawOrderCount;
				current.preActiveClippingSlotSource = lastPreActiveClipping;
				current.forceSeparate = false;

				workingSubmeshInstructions->setSize(submeshIndex + 1, SubmeshInstruction::Default());
				(*workingSubmeshInstructions)[submeshIndex] = current;
				//submeshIndex++;
			}
		}

		instructionOutput.hasActiveClipping = skeletonHasClipping;
		instructionOutput.rawVertexCount = totalRawVertexCount;

		instructionOutput.immutableTriangles = immutableTriangles;
	}

	void MeshGenerator::TryReplaceMaterials(spine::Vector<SubmeshInstruction>* workingSubmeshInstructions, spine::HashMap<UnityEngine::Material, UnityEngine::Material>* customMaterialOverride)
	{
		// Material overrides are done here so they can be applied per submesh instead of per slot
		// but they will still be passed through the GenerateMeshOverride delegate,
		// and will still go through the normal material match check step in STEP 3.
		//SubmeshInstruction[] wsii = workingSubmeshInstructions.Items;
		for (int i = 0; i < workingSubmeshInstructions->size(); i++) {
			//Material material = wsii[i].material;
			UnityEngine::Material& material = (*workingSubmeshInstructions)[i].material;
			if (customMaterialOverride->containsKey(material))
			{
				(*workingSubmeshInstructions)[i].material = (*customMaterialOverride)[material];
			}
		}
	}

}