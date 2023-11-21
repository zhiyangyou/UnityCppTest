
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

	void MeshGenerator::Begin()
	{
		vertexBuffer->clear();
		colorBuffer->clear();
		uvBuffer->clear();
		clipper->clipEnd();

		meshBoundsMin.x = BoundsMinDefault;
		meshBoundsMin.y = BoundsMinDefault;
		meshBoundsMax.x = BoundsMaxDefault;
		meshBoundsMax.y = BoundsMaxDefault;
		meshBoundsThickness = 0.0f;
		submeshIndex = 0;
		submeshes->clear();
	}

	void MeshGenerator::AddSubmesh(SubmeshInstruction& instruction, bool updateTriangles /*= true*/)
	{

		using namespace  spine;
		Settings settings = this->settings();

		int newSubmeshCount = submeshIndex + 1;
		if (submeshes->size() < newSubmeshCount)
		{
			submeshes->setSize(newSubmeshCount, CreateRef<spine::Vector<int>>());
		}

		Ref<spine::Vector<int>> submesh = (*submeshes)[submeshIndex];
		if (submesh == nullptr)
		{
			(*submeshes)[submeshIndex] = submesh = CreateRef<spine::Vector<int>>();
		}

		submesh->clear();

		Skeleton* skeleton = instruction.skeleton;
		Vector<Slot*>& drawOrderItems = skeleton->getDrawOrder();

		Color32 color = Color32::default();
		float skeletonA = skeleton->getColor().a;
		float skeletonR = skeleton->getColor().r;
		float skeletonG = skeleton->getColor().g;
		float skeletonB = skeleton->getColor().b;
		glm::vec2 meshBoundsMin = this->meshBoundsMin;
		glm::vec2 meshBoundsMax = this->meshBoundsMax;

		// Settings
		float zSpacing = settings.zSpacing;
		bool pmaVertexColors = settings.pmaVertexColors;
		bool tintBlack = settings.tintBlack;
		bool useClipping = settings.useClipping && instruction.hasClipping;
		bool canvasGroupTintBlack = settings.tintBlack && settings.canvasGroupTintBlack;

		if (useClipping)
		{
			if (instruction.preActiveClippingSlotSource >= 0)
			{
				Slot* slot = drawOrderItems[instruction.preActiveClippingSlotSource];
				clipper->clipStart(*slot, static_cast<ClippingAttachment*> (slot->getAttachment()));
			}
		}

		for (int slotIndex = instruction.startSlot; slotIndex < instruction.endSlot; slotIndex++) {
			Slot* slot = drawOrderItems[slotIndex];
			if (!slot->getBone().isActive()) {
				clipper->clipEnd(*slot);
				continue;
			}
			Attachment* attachment = slot->getAttachment();
			float z = zSpacing * slotIndex;

			Ref <spine::Vector<float>> workingVerts = this->tempVerts;
			Vector<float>* uvs = nullptr;
			Ref <spine::Vector<unsigned short>> attachmentTriangleIndices = nullptr;

			int attachmentVertexCount;
			int attachmentIndexCount;

			Color c = Color();

			// Identify and prepare values.
			//RegionAttachment region = attachment as RegionAttachment;
			if (IsThisAttachment<RegionAttachment>(attachment))
			{
				RegionAttachment* region = static_cast<RegionAttachment*>(attachment);
				region->computeWorldVertices(*slot, *workingVerts, 0);
				uvs = &(region->getUVs());
				attachmentTriangleIndices = regionTriangles;
				c.r = region->getColor().r;
				c.g = region->getColor().g;
				c.b = region->getColor().b;
				c.a = region->getColor().a;
				attachmentVertexCount = 4;
				attachmentIndexCount = 6;
			}
			else if (IsThisAttachment<MeshAttachment>(attachment)) {
				MeshAttachment* mesh = static_cast<MeshAttachment*>(attachment);

				int meshVerticesLength = mesh->getWorldVerticesLength();
				if (workingVerts->getCapacity() < meshVerticesLength) {
					this->tempVerts->ensureCapacity(meshVerticesLength);
				}
				mesh->computeWorldVertices(*slot, 0, meshVerticesLength, *workingVerts, 0); //meshAttachment.ComputeWorldVertices(slot, tempVerts);
				uvs = &(mesh->getUVs());
				attachmentTriangleIndices.reset(&(mesh->getTriangles()));
				c.r = mesh->getColor().r;
				c.g = mesh->getColor().g;
				c.b = mesh->getColor().b;
				c.a = mesh->getColor().a;
				attachmentVertexCount = meshVerticesLength >> 1; // meshVertexCount / 2;
				attachmentIndexCount = mesh->getTriangles().size();
			}
			else {
				if (useClipping) {
					if (IsThisAttachment<ClippingAttachment>(attachment))
					{
						ClippingAttachment* clippingAttachment = static_cast<ClippingAttachment*>(attachment);
						clipper->clipStart(*slot, clippingAttachment);
						continue;
					}
				}
				// If not any renderable attachment.
				clipper->clipEnd(*slot);
				continue;
			}
		}
		2023年11月21日23:47:27  工作断点
		float tintBlackAlpha = 1.0f;
		if (pmaVertexColors) {
			float colorA = skeletonA * slot.A * c.a;
			color.a = (byte)(colorA * 255);
			color.r = (byte)(skeletonR * slot.R * c.r * color.a);
			color.g = (byte)(skeletonG * slot.G * c.g * color.a);
			color.b = (byte)(skeletonB * slot.B * c.b * color.a);
			if (slot.Data.BlendMode == BlendMode.Additive) {
				if (canvasGroupTintBlack)
					tintBlackAlpha = 0;
				else
					color.a = 0;
			}
			else if (canvasGroupTintBlack) { // other blend modes
				tintBlackAlpha = colorA;
			}
		}
		else {
			color.a = (byte)(skeletonA * slot.A * c.a * 255);
			color.r = (byte)(skeletonR * slot.R * c.r * 255);
			color.g = (byte)(skeletonG * slot.G * c.g * 255);
			color.b = (byte)(skeletonB * slot.B * c.b * 255);
		}

		if (useClipping && clipper.IsClipping) {
			clipper.ClipTriangles(workingVerts, attachmentVertexCount << 1, attachmentTriangleIndices, attachmentIndexCount, uvs);
			workingVerts = clipper.ClippedVertices.Items;
			attachmentVertexCount = clipper.ClippedVertices.Count >> 1;
			attachmentTriangleIndices = clipper.ClippedTriangles.Items;
			attachmentIndexCount = clipper.ClippedTriangles.Count;
			uvs = clipper.ClippedUVs.Items;
		}

		// Actually add slot/attachment data into buffers.
		if (attachmentVertexCount != 0 && attachmentIndexCount != 0) {
			if (tintBlack) {
				float r2 = slot.R2;
				float g2 = slot.G2;
				float b2 = slot.B2;
				if (pmaVertexColors) {
					float alpha = skeletonA * slot.A * c.a;
					r2 *= alpha;
					g2 *= alpha;
					b2 *= alpha;
				}
				AddAttachmentTintBlack(r2, g2, b2, tintBlackAlpha, attachmentVertexCount);
			}

			//AddAttachment(workingVerts, uvs, color, attachmentTriangleIndices, attachmentVertexCount, attachmentIndexCount, ref meshBoundsMin, ref meshBoundsMax, z);
			int ovc = vertexBuffer.Count;
			// Add data to vertex buffers
			{
				int newVertexCount = ovc + attachmentVertexCount;
				int oldArraySize = vertexBuffer.Items.Length;
				if (newVertexCount > oldArraySize) {
					int newArraySize = (int)(oldArraySize * 1.3f);
					if (newArraySize < newVertexCount) newArraySize = newVertexCount;
					Array.Resize(ref vertexBuffer.Items, newArraySize);
					Array.Resize(ref uvBuffer.Items, newArraySize);
					Array.Resize(ref colorBuffer.Items, newArraySize);
				}
				vertexBuffer.Count = uvBuffer.Count = colorBuffer.Count = newVertexCount;
			}

			Vector3[] vbi = vertexBuffer.Items;
			Vector2[] ubi = uvBuffer.Items;
			Color32[] cbi = colorBuffer.Items;
			if (ovc == 0) {
				for (int i = 0; i < attachmentVertexCount; i++) {
					int vi = ovc + i;
					int i2 = i << 1; // i * 2
					float x = workingVerts[i2];
					float y = workingVerts[i2 + 1];

					vbi[vi].x = x;
					vbi[vi].y = y;
					vbi[vi].z = z;
					ubi[vi].x = uvs[i2];
					ubi[vi].y = uvs[i2 + 1];
					cbi[vi] = color;

					// Calculate bounds.
					if (x < meshBoundsMin.x) meshBoundsMin.x = x;
					if (x > meshBoundsMax.x) meshBoundsMax.x = x;
					if (y < meshBoundsMin.y) meshBoundsMin.y = y;
					if (y > meshBoundsMax.y) meshBoundsMax.y = y;
				}
			}
			else {
				for (int i = 0; i < attachmentVertexCount; i++) {
					int vi = ovc + i;
					int i2 = i << 1; // i * 2
					float x = workingVerts[i2];
					float y = workingVerts[i2 + 1];

					vbi[vi].x = x;
					vbi[vi].y = y;
					vbi[vi].z = z;
					ubi[vi].x = uvs[i2];
					ubi[vi].y = uvs[i2 + 1];
					cbi[vi] = color;

					// Calculate bounds.
					if (x < meshBoundsMin.x) meshBoundsMin.x = x;
					else if (x > meshBoundsMax.x) meshBoundsMax.x = x;
					if (y < meshBoundsMin.y) meshBoundsMin.y = y;
					else if (y > meshBoundsMax.y) meshBoundsMax.y = y;
				}
			}


			// Add data to triangle buffer
			if (updateTriangles) {
				int oldTriangleCount = submesh.Count;
				{ //submesh.Resize(oldTriangleCount + attachmentIndexCount);
					int newTriangleCount = oldTriangleCount + attachmentIndexCount;
					if (newTriangleCount > submesh.Items.Length) Array.Resize(ref submesh.Items, newTriangleCount);
					submesh.Count = newTriangleCount;
				}
				int[] submeshItems = submesh.Items;
				for (int i = 0; i < attachmentIndexCount; i++)
					submeshItems[oldTriangleCount + i] = attachmentTriangleIndices[i] + ovc;
			}
		}

		clipper.ClipEnd(slot);
	}
	clipper.ClipEnd();

	this.meshBoundsMin = meshBoundsMin;
	this.meshBoundsMax = meshBoundsMax;
	meshBoundsThickness = instruction.endSlot * zSpacing;

	// Trim or zero submesh triangles.
	int[] currentSubmeshItems = submesh.Items;
	for (int i = submesh.Count, n = currentSubmeshItems.Length; i < n; i++)
		currentSubmeshItems[i] = 0;

	submeshIndex++; // Next AddSubmesh will use a new submeshIndex value.

}

}