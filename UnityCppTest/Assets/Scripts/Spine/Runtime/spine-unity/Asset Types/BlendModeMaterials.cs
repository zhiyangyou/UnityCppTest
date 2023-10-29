/******************************************************************************
 * Spine Runtimes License Agreement
 * Last updated July 28, 2023. Replaces all prior versions.
 *
 * Copyright (c) 2013-2023, Esoteric Software LLC
 *
 * Integration of the Spine Runtimes into software or otherwise creating
 * derivative works of the Spine Runtimes is permitted under the terms and
 * conditions of Section 2 of the Spine Editor License Agreement:
 * http://esotericsoftware.com/spine-editor-license
 *
 * Otherwise, it is permitted to integrate the Spine Runtimes into software or
 * otherwise create derivative works of the Spine Runtimes (collectively,
 * "Products"), provided that each user of the Products must obtain their own
 * Spine Editor license and redistribution of the Products in any form must
 * include this license and copyright notice.
 *
 * THE SPINE RUNTIMES ARE PROVIDED BY ESOTERIC SOFTWARE LLC "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE LLC BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES,
 * BUSINESS INTERRUPTION, OR LOSS OF USE, DATA, OR PROFITS) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THE
 * SPINE RUNTIMES, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

using Spine;
using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using SpineCpp = spine_cpp.Spine;
namespace Spine.Unity {
	[System.Serializable]
	public class BlendModeMaterials {

		[System.Serializable]
		public class ReplacementMaterial {
			public string pageName;
			public Material material;
		}

		[SerializeField, HideInInspector] protected bool requiresBlendModeMaterials = false;
		public bool applyAdditiveMaterial = false;

		public List<ReplacementMaterial> additiveMaterials = new List<ReplacementMaterial>();
		public List<ReplacementMaterial> multiplyMaterials = new List<ReplacementMaterial>();
		public List<ReplacementMaterial> screenMaterials = new List<ReplacementMaterial>();

		public bool RequiresBlendModeMaterials { get { return requiresBlendModeMaterials; } set { requiresBlendModeMaterials = value; } }

		public BlendMode BlendModeForMaterial (Material material) {
			foreach (ReplacementMaterial pair in multiplyMaterials)
				if (pair.material == material) return BlendMode.Multiply;
			foreach (ReplacementMaterial pair in additiveMaterials)
				if (pair.material == material) return BlendMode.Additive;
			foreach (ReplacementMaterial pair in screenMaterials)
				if (pair.material == material) return BlendMode.Screen;
			return BlendMode.Normal;
		}

#if UNITY_EDITOR
		public void TransferSettingsFrom (BlendModeMaterialsAsset modifierAsset) {
			applyAdditiveMaterial = modifierAsset.applyAdditiveMaterial;
		}

		public bool UpdateBlendmodeMaterialsRequiredState (SkeletonData skeletonData) {
			requiresBlendModeMaterials = false;

			if (skeletonData == null) return false;

			List<Skin.SkinEntry> skinEntries = new List<Skin.SkinEntry>();
			SlotData[] slotsItems = skeletonData.Slots.Items;
			for (int slotIndex = 0, slotCount = skeletonData.Slots.Count; slotIndex < slotCount; slotIndex++) {
				SlotData slot = slotsItems[slotIndex];
				if (slot.BlendMode == BlendMode.Normal) continue;
				if (!applyAdditiveMaterial && slot.BlendMode == BlendMode.Additive) continue;

				skinEntries.Clear();
				foreach (Skin skin in skeletonData.Skins)
					skin.GetAttachments(slotIndex, skinEntries);

				foreach (Skin.SkinEntry entry in skinEntries) {
					if (entry.Attachment is IHasTextureRegion) {
						requiresBlendModeMaterials = true;
						return true;
					}
				}
			}
			return false;
		}
#endif
		public void ApplyMaterials (SkeletonData skeletonData) {
			if (skeletonData == null) throw new ArgumentNullException("skeletonData");
			if (!requiresBlendModeMaterials)
				return;

			List<Skin.SkinEntry> skinEntries = new List<Skin.SkinEntry>();
			SlotData[] slotsItems = skeletonData.Slots.Items;
			for (int slotIndex = 0, slotCount = skeletonData.Slots.Count; slotIndex < slotCount; slotIndex++) {
				SlotData slot = slotsItems[slotIndex];
				if (slot.BlendMode == BlendMode.Normal) continue;
				if (!applyAdditiveMaterial && slot.BlendMode == BlendMode.Additive) continue;

				List<ReplacementMaterial> replacementMaterials = null;
				switch (slot.BlendMode) {
				case BlendMode.Multiply:
					replacementMaterials = multiplyMaterials;
					break;
				case BlendMode.Screen:
					replacementMaterials = screenMaterials;
					break;
				case BlendMode.Additive:
					replacementMaterials = additiveMaterials;
					break;
				}
				if (replacementMaterials == null)
					continue;

				skinEntries.Clear();
				foreach (Skin skin in skeletonData.Skins)
					skin.GetAttachments(slotIndex, skinEntries);

				foreach (Skin.SkinEntry entry in skinEntries) {
					IHasTextureRegion renderableAttachment = entry.Attachment as IHasTextureRegion;
					if (renderableAttachment != null) {
						if (renderableAttachment.Region != null) {
							renderableAttachment.Region = CloneAtlasRegionWithMaterial(
							(AtlasRegion)renderableAttachment.Region, replacementMaterials);
						} else {
							if (renderableAttachment.Sequence != null) {
								TextureRegion[] regions = renderableAttachment.Sequence.Regions;
								for (int i = 0; i < regions.Length; ++i) {
									regions[i] = CloneAtlasRegionWithMaterial(
										(AtlasRegion)regions[i], replacementMaterials);
								}
							}
						}
					}
				}
			}
		}
		
		
		public void ApplyMaterials_Cpp (SpineCpp.SkeletonData skeletonData) {
			if (skeletonData == null) throw new ArgumentNullException("skeletonData");
			if (!requiresBlendModeMaterials)
				return;

			List<SpineCpp.SkinEntry> skinEntries = new List<SpineCpp.SkinEntry>();
			var slotsItems = skeletonData.Slots;
			for (ulong slotIndex = 0, slotCount = skeletonData.Slots.Size; slotIndex < slotCount; slotIndex++) {
				SpineCpp.SlotData slot = slotsItems[slotIndex];
				if (slot.BlendMode == SpineCpp.BlendMode.BlendModeNormal) continue;
				if (!applyAdditiveMaterial && slot.BlendMode == SpineCpp.BlendMode.BlendModeAdditive) continue;

				List<ReplacementMaterial> replacementMaterials = null;
				switch (slot.BlendMode) {
					case SpineCpp.BlendMode.BlendModeMultiply:
						replacementMaterials = multiplyMaterials;
						break;
					case SpineCpp.BlendMode.BlendModeScreen:
						replacementMaterials = screenMaterials;
						break;
					case SpineCpp.BlendMode.BlendModeAdditive:
						replacementMaterials = additiveMaterials;
						break;
				}
				if (replacementMaterials == null)
					continue;

				skinEntries.Clear();
				for (ulong i = 0; i < skeletonData.Skins.Size; i++)
				{
					SpineCpp.Skin skin = skeletonData.Skins[i];
					skin.getAttachments(slotIndex, skinEntries);
				}
				
				foreach (SpineCpp.SkinEntry entry in skinEntries) {
					SpineCpp.Attachment renderableAttachment = entry.Attachment;
					var className = renderableAttachment.RTTI.ClassName;
					if (className == "MeshAttachment" || className == "RegionAttachment")
					{
						SpineCpp.TextureRegion region = null;
						SpineCpp.Sequence sequence = null;
						if (renderableAttachment is SpineCpp.MeshAttachment meshAtt1)
						{
							region = meshAtt1.Region;
							sequence = meshAtt1.Sequence;
						}
						else if (renderableAttachment is SpineCpp.RegionAttachment regionAtt1)
						{
							region = regionAtt1.Region;
							sequence = regionAtt1.Sequence;
						}

						if (region != null)
						{
							if (renderableAttachment is SpineCpp.MeshAttachment meshAtt2)
							{
								meshAtt2.Region = CloneAtlasRegionWithMaterial_Cpp(
									(SpineCpp.AtlasRegion)meshAtt2.Region, replacementMaterials);
							}
							else if (renderableAttachment is SpineCpp.RegionAttachment regionAttachment2)
							{
								regionAttachment2.Region = CloneAtlasRegionWithMaterial_Cpp(
									(SpineCpp.AtlasRegion)regionAttachment2.Region, replacementMaterials);
							}
						}
						else
						{
							if (sequence != null) {
								var regions = sequence.Regions;
								for (ulong i = 0; i < regions.Size; ++i) {
									regions[i] = CloneAtlasRegionWithMaterial_Cpp(
										(SpineCpp.AtlasRegion)regions[i], replacementMaterials);
								}
							}
						}
					}
				}
			}
		}

		protected AtlasRegion CloneAtlasRegionWithMaterial (AtlasRegion originalRegion, List<ReplacementMaterial> replacementMaterials) {
			AtlasRegion newRegion = originalRegion.Clone();
			Material material = null;
			foreach (ReplacementMaterial replacement in replacementMaterials) {
				if (replacement.pageName == originalRegion.page.name) {
					material = replacement.material;
					break;
				}
			}

			AtlasPage originalPage = originalRegion.page;
			AtlasPage newPage = originalPage.Clone();
			newPage.rendererObject = material;
			newRegion.page = newPage;
			return newRegion;
		}
		
		protected SpineCpp.AtlasRegion CloneAtlasRegionWithMaterial_Cpp (SpineCpp.AtlasRegion originalRegion, List<ReplacementMaterial> replacementMaterials) {
			SpineCpp.AtlasRegion newRegion = originalRegion.Clone();
			Material material = null;
			foreach (ReplacementMaterial replacement in replacementMaterials) {
				if (replacement.pageName == originalRegion.Page.Name.Buffer) {
					material = replacement.material;
					break;
				}
			}

			SpineCpp.AtlasPage originalPage = originalRegion.Page;
			SpineCpp.AtlasPage newPage = originalPage.Clone();
			newPage.rendererObject = material;
			newRegion.Page = newPage;
			return newRegion;
		}
	}
}
