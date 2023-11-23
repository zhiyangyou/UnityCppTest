
#include "MeshGenerator.h"

#include <spine/spine.h>

namespace SpineUnity {

	MeshGenerator::MeshGenerator()
	{
		submeshes->add(new spine::Vector<int>()); // start with 1 submesh.
		float zero = 0.0f;
		tempVerts->addAll(8, zero);
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
			submeshes->setSizeWithFunc(newSubmeshCount, [](void* ptrAddress)
				{
					new (ptrAddress) spine::Vector<int>();
				});
		}

		spine::Vector<int>* submesh = (*submeshes)[submeshIndex];
		if (submesh == nullptr)
		{
			(*submeshes)[submeshIndex] = submesh = new spine::Vector<int>();
		}

		submesh->clear();

		Skeleton* skeleton = instruction.skeleton;
		Vector<Slot*>& drawOrderItems = skeleton->getDrawOrder();

		Color32 color = Color32::DefaultV();
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
			float tintBlackAlpha = 1.0f;
			if (pmaVertexColors) {
				float colorA = skeletonA * slot->getColor().a * c.a;
				color.a = (uint8_t)(colorA * 255.0f);
				color.r = (uint8_t)(skeletonR * slot->getColor().r * c.r * color.a);
				color.g = (uint8_t)(skeletonG * slot->getColor().g * c.g * color.a);
				color.b = (uint8_t)(skeletonB * slot->getColor().b * c.b * color.a);
				if (slot->getData().getBlendMode() == BlendMode::BlendMode_Additive) {
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
				color.a = (uint8_t)(skeletonA * slot->getColor().a * c.a * 255.0f);
				color.r = (uint8_t)(skeletonR * slot->getColor().r * c.r * 255.0f);
				color.g = (uint8_t)(skeletonG * slot->getColor().g * c.g * 255.0f);
				color.b = (uint8_t)(skeletonB * slot->getColor().b * c.b * 255.0f);
			}

			if (useClipping && clipper->isClipping()) {
				clipper->clipTriangles(*workingVerts, *attachmentTriangleIndices, *uvs, 2);
				workingVerts.reset(&(clipper->getClippedVertices()));
				attachmentVertexCount = clipper->getClippedVertices().size() >> 1;
				attachmentTriangleIndices.reset(&(clipper->getClippedTriangles()));
				attachmentIndexCount = clipper->getClippedTriangles().size();
				uvs = &(clipper->getClippedUVs());
			}

			// Actually add slot/attachment data into buffers.
			if (attachmentVertexCount != 0 && attachmentIndexCount != 0) {
				if (tintBlack) {
					float r2 = slot->getDarkColor().r;
					float g2 = slot->getDarkColor().g;
					float b2 = slot->getDarkColor().b;
					if (pmaVertexColors) {
						float alpha = skeletonA * slot->getColor().a * c.a;
						r2 *= alpha;
						g2 *= alpha;
						b2 *= alpha;
					}
					AddAttachmentTintBlack(r2, g2, b2, tintBlackAlpha, attachmentVertexCount);
				}

				//AddAttachment(workingVerts, uvs, color, attachmentTriangleIndices, attachmentVertexCount, attachmentIndexCount, ref meshBoundsMin, ref meshBoundsMax, z);
				int ovc = vertexBuffer->size();

				// Add data to vertex buffers
				int newVertexCount = ovc + attachmentVertexCount;
				int oldArraySize = vertexBuffer->size();
				if (newVertexCount > oldArraySize)
				{
					int newArraySize = (int)(oldArraySize * 1.3f);
					if (newArraySize < newVertexCount)
					{
						newArraySize = newVertexCount;
					}
					vertexBuffer->setSize(newArraySize, {});
					uvBuffer->setSize(newArraySize, {});
					colorBuffer->setSize(newArraySize, {});
				}

				glm::vec3* vbi = vertexBuffer->buffer();
				glm::vec2* ubi = uvBuffer->buffer();
				spine::Color32* cbi = colorBuffer->buffer();
				if (ovc == 0) {
					for (int i = 0; i < attachmentVertexCount; i++) {
						int vi = ovc + i;
						int i2 = i << 1; // i * 2
						float x = (*workingVerts)[i2];
						float y = (*workingVerts)[i2 + 1];

						vbi[vi].x = x;
						vbi[vi].y = y;
						vbi[vi].z = z;
						ubi[vi].x = (*uvs)[i2];
						ubi[vi].y = (*uvs)[i2 + 1];
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
						float x = (*workingVerts)[i2];
						float y = (*workingVerts)[i2 + 1];

						vbi[vi].x = x;
						vbi[vi].y = y;
						vbi[vi].z = z;
						ubi[vi].x = (*uvs)[i2];
						ubi[vi].y = (*uvs)[i2 + 1];
						cbi[vi] = color;

						// Calculate bounds.
						if (x < meshBoundsMin.x) meshBoundsMin.x = x;
						else if (x > meshBoundsMax.x) meshBoundsMax.x = x;
						if (y < meshBoundsMin.y) meshBoundsMin.y = y;
						else if (y > meshBoundsMax.y) meshBoundsMax.y = y;
					}
				}


				// Add data to triangle buffer
				if (updateTriangles)
				{
					int oldTriangleCount = submesh->size();
					{ //submesh.Resize(oldTriangleCount + attachmentIndexCount);
						int newTriangleCount = oldTriangleCount + attachmentIndexCount;
						if (newTriangleCount > submesh->size())
						{
							submesh->setSize(newTriangleCount, 0);
						}
					}
					//int[] submeshItems = submesh.Items;
					for (int i = 0; i < attachmentIndexCount; i++)
						(*submesh)[oldTriangleCount + i] = (*attachmentTriangleIndices)[i] + ovc;
				}
			}

			clipper->clipEnd(*slot);
		}
		clipper->clipEnd();

		this->meshBoundsMin = meshBoundsMin;
		this->meshBoundsMax = meshBoundsMax;
		meshBoundsThickness = instruction.endSlot * zSpacing;

		// Trim or zero submesh triangles.
		//int[] currentSubmeshItems = submesh.Items;
		for (int i = submesh->size(), n = submesh->size(); i < n; i++)
		{
			(*submesh)[i] = 0;
		}
		submeshIndex++; // Next AddSubmesh will use a new submeshIndex value.

	}

	void MeshGenerator::BuildMesh(SkeletonRendererInstruction& instruction, bool updateTriangles)
	{
		for (int i = 0, n = instruction.submeshInstructions->size(); i < n; i++)
			this->AddSubmesh((*instruction.submeshInstructions)[i], updateTriangles);
	}

	void MeshGenerator::BuildMeshWithArrays(SkeletonRendererInstruction& instruction, bool updateTriangles)
	{
		using namespace  spine;
		Settings settings = this->settings();
		bool canvasGroupTintBlack = settings.tintBlack && settings.canvasGroupTintBlack;
		int totalVertexCount = instruction.rawVertexCount;


		// Add data to vertex buffers

		if (totalVertexCount > vertexBuffer->size()) { // Manual ExposedList.Resize()
			vertexBuffer->setSize(totalVertexCount, {});
			uvBuffer->setSize(totalVertexCount, {});
			colorBuffer->setSize(totalVertexCount, {});
		}
		// Populate Verts
		Color32 color = Color32::DefaultV();

		int vertexIndex = 0;
		glm::vec2 bmin = this->meshBoundsMin;
		glm::vec2 bmax = this->meshBoundsMax;

		glm::vec3* vbi = vertexBuffer->buffer();
		glm::vec2* ubi = uvBuffer->buffer();
		Color32* cbi = colorBuffer->buffer();
		int lastSlotIndex = 0;

		// drawOrder[endSlot] is excluded
		for (int si = 0, n = instruction.submeshInstructions->size(); si < n; si++) {
			SubmeshInstruction submesh = (*instruction.submeshInstructions)[si];
			Skeleton* skeleton = submesh.skeleton;
			Vector<Slot*>& drawOrderItems = skeleton->getDrawOrder();
			float a = skeleton->getColor().a;
			float r = skeleton->getColor().r;
			float g = skeleton->getColor().g;
			float b = skeleton->getColor().b;

			int endSlot = submesh.endSlot;
			int startSlot = submesh.startSlot;
			lastSlotIndex = endSlot;

			if (settings.tintBlack) {
				glm::vec2  rg;
				glm::vec2  b2;
				int vi = vertexIndex;
				b2.y = 1.0f;

				if (totalVertexCount > uv2->size()) { // Manual ExposedList.Resize()
					uv2->setSize(totalVertexCount, {});
					uv3->setSize(totalVertexCount, {});
				}

				glm::vec2* uv2i = uv2->buffer();
				glm::vec2* uv3i = uv3->buffer();

				for (int slotIndex = startSlot; slotIndex < endSlot; slotIndex++)
				{
					Slot* slot = drawOrderItems[slotIndex];
					if (!slot->getBone().isActive())
					{
						continue;
					}
					Attachment* attachment = slot->getAttachment();

					rg.x = slot->getDarkColor().r; //r
					rg.y = slot->getDarkColor().g; //g
					b2.x = slot->getDarkColor().b; //b
					b2.y = 1.0f;

					if (IsThisAttachment<RegionAttachment>(attachment))
					{
						RegionAttachment* regionAttachment = static_cast<RegionAttachment*>(attachment);
						if (settings.pmaVertexColors) {
							float alpha = a * slot->getColor().a * regionAttachment->getColor().a;
							rg.x *= alpha;
							rg.y *= alpha;
							b2.x *= alpha;
							b2.y = slot->getData().getBlendMode() == BlendMode_Additive ? 0 : alpha;
						}
						uv2i[vi] = rg; uv2i[vi + 1] = rg; uv2i[vi + 2] = rg; uv2i[vi + 3] = rg;
						uv3i[vi] = b2; uv3i[vi + 1] = b2; uv3i[vi + 2] = b2; uv3i[vi + 3] = b2;
						vi += 4;
					}
					else  if (IsThisAttachment<MeshAttachment>(attachment)) {
						MeshAttachment* meshAttachment = static_cast<MeshAttachment*> (attachment);

						if (settings.pmaVertexColors) {
							float alpha = a * slot->getColor().a * meshAttachment->getColor().a;
							rg.x *= alpha;
							rg.y *= alpha;
							b2.x *= alpha;
							b2.y = slot->getData().getBlendMode() == BlendMode_Additive ? 0 : alpha;
						}
						int verticesArrayLength = meshAttachment->getWorldVerticesLength();
						for (int iii = 0; iii < verticesArrayLength; iii += 2) {
							uv2i[vi] = rg;
							uv3i[vi] = b2;
							vi++;
						}
					}
				}
			}

			for (int slotIndex = startSlot; slotIndex < endSlot; slotIndex++) {
				Slot* slot = drawOrderItems[slotIndex];
				if (!slot->getBone().isActive()) continue;
				Attachment* attachment = slot->getAttachment();
				float z = slotIndex * settings.zSpacing;

				if (IsThisAttachment<RegionAttachment>(attachment))
				{
					RegionAttachment* regionAttachment = static_cast<RegionAttachment*>(attachment);
					regionAttachment->computeWorldVertices(*slot, *tempVerts, 0);
					float x1 = (*tempVerts)[RegionAttachment::BLX], y1 = (*tempVerts)[RegionAttachment::BLY];
					float x2 = (*tempVerts)[RegionAttachment::ULX], y2 = (*tempVerts)[RegionAttachment::ULY];
					float x3 = (*tempVerts)[RegionAttachment::URX], y3 = (*tempVerts)[RegionAttachment::URY];
					float x4 = (*tempVerts)[RegionAttachment::BRX], y4 = (*tempVerts)[RegionAttachment::BRY];
					vbi[vertexIndex].x = x1; vbi[vertexIndex].y = y1; vbi[vertexIndex].z = z;
					vbi[vertexIndex + 1].x = x4; vbi[vertexIndex + 1].y = y4; vbi[vertexIndex + 1].z = z;
					vbi[vertexIndex + 2].x = x2; vbi[vertexIndex + 2].y = y2; vbi[vertexIndex + 2].z = z;
					vbi[vertexIndex + 3].x = x3; vbi[vertexIndex + 3].y = y3; vbi[vertexIndex + 3].z = z;

					if (settings.pmaVertexColors) {
						color.a = (uint8_t)(a * slot->getColor().a * regionAttachment->getColor().a * 255.0f);
						color.r = (uint8_t)(r * slot->getColor().r * regionAttachment->getColor().r * color.a);
						color.g = (uint8_t)(g * slot->getColor().g * regionAttachment->getColor().g * color.a);
						color.b = (uint8_t)(b * slot->getColor().b * regionAttachment->getColor().b * color.a);
						if (slot->getData().getBlendMode() == BlendMode_Additive && !canvasGroupTintBlack) color.a = 0;
					}
					else {
						color.a = (uint8_t)(a * slot->getColor().a * regionAttachment->getColor().a * 255.0f);
						color.r = (uint8_t)(r * slot->getColor().r * regionAttachment->getColor().r * 255.0f);
						color.g = (uint8_t)(g * slot->getColor().g * regionAttachment->getColor().g * 255.0f);
						color.b = (uint8_t)(b * slot->getColor().b * regionAttachment->getColor().b * 255.0f);
					}

					cbi[vertexIndex] = color; cbi[vertexIndex + 1] = color; cbi[vertexIndex + 2] = color; cbi[vertexIndex + 3] = color;

					Vector<float>& regionUVs = regionAttachment->getUVs();
					ubi[vertexIndex].x = regionUVs[RegionAttachment::BLX]; ubi[vertexIndex].y = regionUVs[RegionAttachment::BLY];
					ubi[vertexIndex + 1].x = regionUVs[RegionAttachment::BRX]; ubi[vertexIndex + 1].y = regionUVs[RegionAttachment::BRY];
					ubi[vertexIndex + 2].x = regionUVs[RegionAttachment::ULX]; ubi[vertexIndex + 2].y = regionUVs[RegionAttachment::ULY];
					ubi[vertexIndex + 3].x = regionUVs[RegionAttachment::URX]; ubi[vertexIndex + 3].y = regionUVs[RegionAttachment::URY];

					if (x1 < bmin.x) bmin.x = x1; // Potential first attachment bounds initialization. Initial min should not block initial max. Same for Y below.
					if (x1 > bmax.x) bmax.x = x1;
					if (x2 < bmin.x) bmin.x = x2;
					else if (x2 > bmax.x) bmax.x = x2;
					if (x3 < bmin.x) bmin.x = x3;
					else if (x3 > bmax.x) bmax.x = x3;
					if (x4 < bmin.x) bmin.x = x4;
					else if (x4 > bmax.x) bmax.x = x4;

					if (y1 < bmin.y) bmin.y = y1;
					if (y1 > bmax.y) bmax.y = y1;
					if (y2 < bmin.y) bmin.y = y2;
					else if (y2 > bmax.y) bmax.y = y2;
					if (y3 < bmin.y) bmin.y = y3;
					else if (y3 > bmax.y) bmax.y = y3;
					if (y4 < bmin.y) bmin.y = y4;
					else if (y4 > bmax.y) bmax.y = y4;

					vertexIndex += 4;
				}
				else if (IsThisAttachment<MeshAttachment>(attachment))
				{ //if (settings.renderMeshes) {
					MeshAttachment* meshAttachment = static_cast<MeshAttachment*>(attachment);

					int verticesArrayLength = meshAttachment->getWorldVerticesLength();
					if (tempVerts->size() < verticesArrayLength)
					{
						this->tempVerts->setSize(verticesArrayLength, 0);
					}
					meshAttachment->computeWorldVertices(*slot, *tempVerts);

					if (settings.pmaVertexColors) {
						color.a = (uint8_t)(a * slot->getColor().a * meshAttachment->getColor().a * 255.0f);
						color.r = (uint8_t)(r * slot->getColor().r * meshAttachment->getColor().r * color.a);
						color.g = (uint8_t)(g * slot->getColor().g * meshAttachment->getColor().g * color.a);
						color.b = (uint8_t)(b * slot->getColor().b * meshAttachment->getColor().b * color.a);
						if (slot->getData().getBlendMode() == BlendMode_Additive && !canvasGroupTintBlack) color.a = 0;
					}
					else {
						color.a = (uint8_t)(a * slot->getColor().a * meshAttachment->getColor().a * 255.0f);
						color.r = (uint8_t)(r * slot->getColor().r * meshAttachment->getColor().r * 255.0f);
						color.g = (uint8_t)(g * slot->getColor().g * meshAttachment->getColor().g * 255.0f);
						color.b = (uint8_t)(b * slot->getColor().b * meshAttachment->getColor().b * 255.0f);
					}

					Vector<float>& attachmentUVs = meshAttachment->getUVs();

					// Potential first attachment bounds initialization. See conditions in RegionAttachment logic.
					if (vertexIndex == 0) {
						// Initial min should not block initial max.
						// vi == vertexIndex does not always mean the bounds are fresh. It could be a submesh. Do not nuke old values by omitting the check.
						// Should know that this is the first attachment in the submesh. slotIndex == startSlot could be an empty slot.
						float fx = (*tempVerts)[0];
						float fy = (*tempVerts)[1];
						if (fx < bmin.x) bmin.x = fx;
						if (fx > bmax.x) bmax.x = fx;
						if (fy < bmin.y) bmin.y = fy;
						if (fy > bmax.y) bmax.y = fy;
					}

					for (int iii = 0; iii < verticesArrayLength; iii += 2) {
						float x = (*tempVerts)[iii], y = (*tempVerts)[iii + 1];
						vbi[vertexIndex].x = x; vbi[vertexIndex].y = y; vbi[vertexIndex].z = z;
						cbi[vertexIndex] = color; ubi[vertexIndex].x = attachmentUVs[iii]; ubi[vertexIndex].y = attachmentUVs[iii + 1];

						if (x < bmin.x) bmin.x = x;
						else if (x > bmax.x) bmax.x = x;

						if (y < bmin.y) bmin.y = y;
						else if (y > bmax.y) bmax.y = y;

						vertexIndex++;
					}
				}
			}
		}

		meshBoundsMin = bmin;
		meshBoundsMax = bmax;
		meshBoundsThickness = lastSlotIndex * settings.zSpacing;

		int submeshInstructionCount = instruction.submeshInstructions->size();
		submeshes->setSizeWithFunc(submeshInstructionCount, [](void* ptrAddress)
			{
				new(ptrAddress) spine::Vector<int>();
			}
		);

		// Add triangles
		if (updateTriangles) {
			// Match submesh buffers count with submeshInstruction count.
			if (submeshes->size() < submeshInstructionCount) {
				submeshes->setSizeWithFunc(submeshInstructionCount, [](void* ptr)
					{
						new(ptr) spine::Vector<int>();
					}
				);
				for (int i = 0, n = submeshInstructionCount; i < n; i++) {
					spine::Vector<int>* submeshBuffer = (*submeshes)[i];
					if (submeshBuffer == nullptr)
					{
						(*submeshes)[i] = new spine::Vector<int>();
					}
					else
					{
						submeshBuffer->clear();
					}
				}
			}

			Ref<spine::Vector<SubmeshInstruction>> submeshInstructionsItems = instruction.submeshInstructions; // This relies on the resize above.

			// Fill the buffers.
			int attachmentFirstVertex = 0;
			for (int smbi = 0; smbi < submeshInstructionCount; smbi++) {
				SubmeshInstruction& submeshInstruction = (*submeshInstructionsItems)[smbi];
				spine::Vector<int>* currentSubmeshBuffer = (*submeshes)[smbi];
				{ //submesh.Resize(submesh.rawTriangleCount);
					int newTriangleCount = submeshInstruction.rawTriangleCount;
					if (newTriangleCount > currentSubmeshBuffer->size())
					{
						currentSubmeshBuffer->setSize(newTriangleCount, 0);
					}
					else if (newTriangleCount < currentSubmeshBuffer->size()) {
						int sbiLen = currentSubmeshBuffer->size();
						int* sbi = currentSubmeshBuffer->buffer();
						for (int ei = newTriangleCount, nn = sbiLen; ei < nn; ei++)
							sbi[ei] = 0;
					}
				}

				int* tris = currentSubmeshBuffer->buffer();
				int triangleIndex = 0;
				Skeleton* skeleton = submeshInstruction.skeleton;
				Vector<Slot*>& drawOrderItems = skeleton->getDrawOrder();
				for (int slotIndex = submeshInstruction.startSlot, endSlot = submeshInstruction.endSlot; slotIndex < endSlot; slotIndex++) {
					Slot* slot = drawOrderItems[slotIndex];
					if (!slot->getBone().isActive()) continue;

					Attachment* attachment = drawOrderItems[slotIndex]->getAttachment();
					if (IsThisAttachment<RegionAttachment>(attachment))
					{
						tris[triangleIndex] = attachmentFirstVertex;
						tris[triangleIndex + 1] = attachmentFirstVertex + 2;
						tris[triangleIndex + 2] = attachmentFirstVertex + 1;
						tris[triangleIndex + 3] = attachmentFirstVertex + 2;
						tris[triangleIndex + 4] = attachmentFirstVertex + 3;
						tris[triangleIndex + 5] = attachmentFirstVertex + 1;
						triangleIndex += 6;
						attachmentFirstVertex += 4;
						continue;
					}
					else if (IsThisAttachment<MeshAttachment>(attachment))
					{
						MeshAttachment* meshAttachment = static_cast<MeshAttachment*> (attachment);
						Vector<unsigned short>& attachmentTriangles = meshAttachment->getTriangles();
						for (int ii = 0, nn = attachmentTriangles.size(); ii < nn; ii++, triangleIndex++)
							tris[triangleIndex] = attachmentFirstVertex + attachmentTriangles[ii];
						attachmentFirstVertex += (meshAttachment->getWorldVerticesLength() >> 1); // length/2;
					}
				}
			}
		}
	}

	void MeshGenerator::ScaleVertexData(float scale)
	{
		glm::vec3* vertBuffer = vertexBuffer->buffer();
		for (int i = 0, n = vertexBuffer->size(); i < n; i++) {
			(*(vertBuffer + i)) *= scale; // vbi[i].x *= scale; vbi[i].y *= scale;
		}

		meshBoundsMin *= scale;
		meshBoundsMax *= scale;
		meshBoundsThickness *= scale;
	}

	SpineUnity::Bounds MeshGenerator::GetMeshBounds()
	{
		if ((meshBoundsMin.x) >= std::numeric_limits<float>::max() * 0.5f) { // meshBoundsMin.x == BoundsMinDefault // == doesn't work on float Infinity constants.
			return Bounds::Default();
		}
		float halfWidth = (meshBoundsMax.x - meshBoundsMin.x) * 0.5f;
		float halfHeight = (meshBoundsMax.y - meshBoundsMin.y) * 0.5f;
		return
		{
			{meshBoundsMin.x + halfWidth, meshBoundsMin.y + halfHeight,0.0f},
			{halfWidth, halfHeight, meshBoundsThickness * 0.5f}
		};
	}

	void MeshGenerator::AddAttachmentTintBlack(float r2, float g2, float b2, float a, int vertexCount)
	{
		glm::vec2 rg(r2, g2);
		glm::vec2  bo(b2, a);
		int ovc = vertexBuffer->size();
		int newVertexCount = ovc + vertexCount;
		{
			if (uv2 == nullptr) {
				uv2 = CreateRef<spine::Vector<glm::vec2>>();
				uv3 = CreateRef<spine::Vector<glm::vec2>>();
			}
			if (newVertexCount > uv2->size()) { // Manual ExposedList.Resize()
				uv2->setSize(newVertexCount, {});
				uv3->setSize(newVertexCount, {});
			}
		}
		for (int i = 0; i < vertexCount; i++) {
			(*uv2)[ovc + i] = rg;
			(*uv3)[ovc + i] = bo;
		}
	}

}