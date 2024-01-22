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

using System;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.Assertions;
using SpineCpp = spine_cpp.Spine;
using CompatibilityProblemInfo = Spine.Unity.SkeletonDataCompatibility.CompatibilityProblemInfo;

namespace Spine.Unity
{
    [CreateAssetMenu(fileName = "New SkeletonDataAsset", menuName = "Spine/SkeletonData Asset")]
    public class SkeletonDataAsset : ScriptableObject
    {
        #region Inspector

        [SerializeField] public bool useCpp = false;

        public AtlasAssetBase[] atlasAssets = new AtlasAssetBase[0];

#if SPINE_TK2D
		public tk2dSpriteCollectionData spriteCollection;
		public float scale = 1f;
#else
        public float scale = 0.01f;
#endif
        public TextAsset skeletonJSON;

        public bool isUpgradingBlendModeMaterials = false;
        public BlendModeMaterials blendModeMaterials = new BlendModeMaterials();

        [Tooltip(
            "Use SkeletonDataModifierAssets to apply changes to the SkeletonData after being loaded, such as apply blend mode Materials to Attachments under slots with special blend modes.")]
        public List<SkeletonDataModifierAsset> skeletonDataModifiers = new List<SkeletonDataModifierAsset>();

        [SpineAnimation(includeNone: false)] public string[] fromAnimation = new string[0];
        [SpineAnimation(includeNone: false)] public string[] toAnimation = new string[0];
        public float[] duration = new float[0];
        public float defaultMix;
        public RuntimeAnimatorController controller;

#if UNITY_EDITOR
        public static bool errorIfSkeletonFileNullGlobal = true;
#endif

        public bool IsLoaded
        {
            get { return this.skeletonData != null; }
        }

        void Reset()
        {
            Clear();
        }

        #endregion

        SkeletonData skeletonData;
        SpineCpp.SkeletonData skeletonData_Cpp;
        AnimationStateData stateData;
        SpineCpp.AnimationStateData stateData_Cpp;

        #region Runtime Instantiation

        /// <summary>
        /// Creates a runtime SkeletonDataAsset.</summary>
        public static SkeletonDataAsset CreateRuntimeInstance(TextAsset skeletonDataFile, AtlasAssetBase atlasAsset, bool initialize, float scale = 0.01f)
        {
            return CreateRuntimeInstance(skeletonDataFile, new[] { atlasAsset }, initialize, scale);
        }

        /// <summary>
        /// Creates a runtime SkeletonDataAsset.</summary>
        public static SkeletonDataAsset CreateRuntimeInstance(TextAsset skeletonDataFile, AtlasAssetBase[] atlasAssets, bool initialize, float scale = 0.01f)
        {
            SkeletonDataAsset skeletonDataAsset = ScriptableObject.CreateInstance<SkeletonDataAsset>();
            skeletonDataAsset.Clear();
            skeletonDataAsset.skeletonJSON = skeletonDataFile;
            skeletonDataAsset.atlasAssets = atlasAssets;
            skeletonDataAsset.scale = scale;

            if (initialize)
                skeletonDataAsset.GetSkeletonData(true);

            return skeletonDataAsset;
        }

        #endregion

        /// <summary>Clears the loaded SkeletonData and AnimationStateData. Use this to force a reload for the next time GetSkeletonData is called.</summary>
        public void Clear()
        {
            skeletonData = null;
            skeletonData_Cpp?.Dispose();
            skeletonData_Cpp = null;

            stateData_Cpp?.Dispose();
            stateData_Cpp = null;
            stateData = null;
        }

        public AnimationStateData GetAnimationStateData()
        {
            if (stateData != null)
                return stateData;
            GetSkeletonData(false);
            return stateData;
        }

        public SpineCpp.AnimationStateData GetAnimationStateData_Cpp()
        {
            if (stateData_Cpp != null)
                return stateData_Cpp;
            GetSkeletonData_Cpp(false);
            return stateData_Cpp;
        }

        /// <summary>Loads, caches and returns the SkeletonData from the skeleton data file. Returns the cached SkeletonData after the first time it is called. Pass false to prevent direct errors from being logged.</summary>
        public SkeletonData GetSkeletonData(bool quiet)
        {
            if (skeletonJSON == null)
            {
#if UNITY_EDITOR
                if (!errorIfSkeletonFileNullGlobal) quiet = true;
#endif
                if (!quiet)
                    Debug.LogError("Skeleton JSON file not set for SkeletonData asset: " + name, this);
                Clear();
                return null;
            }

            if (skeletonData != null)
                return skeletonData;

            AttachmentLoader attachmentLoader = null;
            float skeletonDataScale;
            Atlas[] atlasArray = this.GetAtlasArray();

#if !SPINE_TK2D

            attachmentLoader = (atlasArray.Length == 0)
                ? (AttachmentLoader)new RegionlessAttachmentLoader()
                : (AttachmentLoader)new AtlasAttachmentLoader(atlasArray);
            skeletonDataScale = scale;
#else
			if (spriteCollection != null) {
				attachmentLoader = new Spine.Unity.TK2D.SpriteCollectionAttachmentLoader(spriteCollection);
				skeletonDataScale = (1.0f / (spriteCollection.invOrthoSize * spriteCollection.halfTargetHeight) * scale);
			} else {
				if (atlasArray.Length == 0) {
					Reset();
					if (!quiet) Debug.LogError("Atlas not set for SkeletonData asset: " + name, this);
					return null;
				}
				attachmentLoader = new AtlasAttachmentLoader(atlasArray);
				skeletonDataScale = scale;
			}
#endif

            bool hasBinaryExtension = skeletonJSON.name.ToLower().Contains(".skel");
            SkeletonData loadedSkeletonData = null;

            try
            {
                if (hasBinaryExtension)
                    loadedSkeletonData = SkeletonDataAsset.ReadSkeletonData(skeletonJSON.bytes, attachmentLoader, skeletonDataScale);
                else
                {
                    loadedSkeletonData = SkeletonDataAsset.ReadSkeletonData(skeletonJSON.text, attachmentLoader, skeletonDataScale);
                }
            }
            catch (Exception ex)
            {
                if (!quiet)
                    Debug.LogError("Error reading skeleton JSON file for SkeletonData asset: " + name + "\n" + ex.Message + "\n" + ex.StackTrace, skeletonJSON);
            }

#if UNITY_EDITOR
            if (loadedSkeletonData == null && !quiet && skeletonJSON != null)
            {
                string problemDescription = null;
                bool isSpineSkeletonData;
                SkeletonDataCompatibility.VersionInfo fileVersion =
                    SkeletonDataCompatibility.GetVersionInfo(skeletonJSON, out isSpineSkeletonData, ref problemDescription);
                if (problemDescription != null)
                {
                    if (!quiet)
                        Debug.LogError(problemDescription, skeletonJSON);
                    return null;
                }

                CompatibilityProblemInfo compatibilityProblemInfo = SkeletonDataCompatibility.GetCompatibilityProblemInfo(fileVersion);
                if (compatibilityProblemInfo != null)
                {
                    SkeletonDataCompatibility.DisplayCompatibilityProblem(compatibilityProblemInfo.DescriptionString(), skeletonJSON);
                    return null;
                }
            }
#endif
            if (loadedSkeletonData == null)
                return null;

            if (skeletonDataModifiers != null)
            {
                foreach (SkeletonDataModifierAsset modifier in skeletonDataModifiers)
                {
                    if (modifier != null && !(isUpgradingBlendModeMaterials && modifier is BlendModeMaterialsAsset))
                    {
                        modifier.Apply(loadedSkeletonData);
                    }
                }
            }

            if (!isUpgradingBlendModeMaterials)
                blendModeMaterials.ApplyMaterials(loadedSkeletonData);

            this.InitializeWithData(loadedSkeletonData);

            return skeletonData;
        }

        public spine_cpp.Spine.SkeletonData GetSkeletonData_Cpp(bool quiet)
        {
            if (skeletonJSON == null)
            {
#if UNITY_EDITOR
                if (!errorIfSkeletonFileNullGlobal) quiet = true;
#endif
                if (!quiet)
                    Debug.LogError("Skeleton JSON file not set for SkeletonData asset: " + name, this);
                Clear();
                return null;
            }

            if (skeletonData_Cpp != null)
                return skeletonData_Cpp;

            float skeletonDataScale = scale;
            List<SpineCpp.Atlas> atlasArray = this.GetAtlasArray_Cpp();
            
            Assert.IsTrue(atlasArray.Count == 1, "仅支持1个atlas");
            //TODO 记得释放！
            if (atlasArray[0].__Instance == IntPtr.Zero)
            {
                Debug.LogError("错误！ atlas 是空");
                return null;
            }
            SpineCpp.AtlasAttachmentLoader attachmentLoader = (atlasArray.Count == 0) ? null : new SpineCpp.AtlasAttachmentLoader(atlasArray[0]);
            if (attachmentLoader == null)
            {
                throw new Exception("attachmentLoader 是 null");
            }

            // SpineCpp.SpineCppUtils.DisposeList(atlasArray);
            skeletonDataScale = scale;

            bool hasBinaryExtension = skeletonJSON.name.ToLower().Contains(".skel");
            Assert.IsFalse(hasBinaryExtension, "目前仅支持json");
            SpineCpp.SkeletonData loadedSkeletonData = null;
            SpineCpp.SkeletonJson skJson = null;
            try
            {
                //TODO 暂时不理解这边的atlas为什么是多个！
                // SpineAtlasAsset atlasAsset = atlasAssets[0] as SpineAtlasAsset;
                //TODO 注意把控 SpineCpp的生命周期!!
                skJson = new SpineCpp.SkeletonJson(attachmentLoader, false); //TODO 注意把控 SpineCpp的生命周期!!
                skJson.SetScale(skeletonDataScale);
                // return null;
                if (true)
                { 
                    loadedSkeletonData = skJson.ReadSkeletonData(skeletonJSON.text);
                }


            }
            catch (Exception ex)
            {
                if (!quiet)
                    Debug.LogError("Error reading skeleton JSON file for SkeletonData asset: " + name + "\n" + ex.Message + "\n" + ex.StackTrace, skeletonJSON);
            }
            finally
            {
                attachmentLoader?.Dispose();
                skJson.Dispose();
                SpineCpp.SpineCppUtils.DisposeList(atlasArray);
            }

#if UNITY_EDITOR
            if (loadedSkeletonData == null && !quiet && skeletonJSON != null)
            {
                string problemDescription = null;
                bool isSpineSkeletonData;
                SkeletonDataCompatibility.VersionInfo fileVersion =
                    SkeletonDataCompatibility.GetVersionInfo(skeletonJSON, out isSpineSkeletonData, ref problemDescription);
                if (problemDescription != null)
                {
                    if (!quiet)
                        Debug.LogError(problemDescription, skeletonJSON);
                    return null;
                }

                CompatibilityProblemInfo compatibilityProblemInfo = SkeletonDataCompatibility.GetCompatibilityProblemInfo(fileVersion);
                if (compatibilityProblemInfo != null)
                {
                    SkeletonDataCompatibility.DisplayCompatibilityProblem(compatibilityProblemInfo.DescriptionString(), skeletonJSON);
                    return null;
                }
            }
#endif
            if (loadedSkeletonData == null)
                return null;

            if (skeletonDataModifiers != null)
            {
                foreach (SkeletonDataModifierAsset modifier in skeletonDataModifiers)
                {
                    if (modifier != null && !(isUpgradingBlendModeMaterials && modifier is BlendModeMaterialsAsset))
                    {
                        modifier.Apply(loadedSkeletonData);
                    }
                }
            }

            if (!isUpgradingBlendModeMaterials)
                blendModeMaterials.ApplyMaterials_Cpp(loadedSkeletonData);

            this.InitializeWithDataCpp(loadedSkeletonData);

            return skeletonData_Cpp;
        }


        internal void InitializeWithData(SkeletonData sd)
        {
            this.skeletonData = sd;
            this.stateData = new AnimationStateData(skeletonData);
            FillStateData();
        }

        internal void InitializeWithDataCpp(spine_cpp.Spine.SkeletonData sd)
        {
            this.skeletonData_Cpp = sd;
            this.stateData_Cpp = new spine_cpp.Spine.AnimationStateData(skeletonData_Cpp);
            FillStateData_Cpp();
        }

        public void FillStateData_Cpp(bool quiet = false)
        {
            if (stateData_Cpp != null)
            {
                stateData_Cpp.DefaultMix = defaultMix;
                // Debug.LogError("TODO 用于测试");
                // return ;
                for (int i = 0, n = fromAnimation.Length; i < n; i++)
                {
                    using SpineCpp.String fromAnimationName = SpineCpp.SpineCppUtils.CreateSpineString(fromAnimation[i]);
                    using SpineCpp.String toAnimationName = SpineCpp.SpineCppUtils.CreateSpineString(toAnimation[i]);
                    if (fromAnimationName.Length == 0 || toAnimationName.Length == 0)
                        continue;
#if UNITY_EDITOR 
                    if (skeletonData_Cpp.FindAnimation(fromAnimationName) == null)
                    {
                        if (!quiet)
                            Debug.LogError(
                                string.Format("Custom Mix Durations: Animation '{0}' not found, was it renamed?",
                                    fromAnimation[i]), this);
                        continue; 
                    }

                    if (skeletonData_Cpp.FindAnimation(toAnimationName) == null)
                    {
                        if (!quiet)
                            Debug.LogError(
                                string.Format("Custom Mix Durations: Animation '{0}' not found, was it renamed?",
                                    toAnimation[i]), this);
                        continue;
                    }
#endif
                    Debug.LogError("TODO 用于测试");
                    continue;
                    stateData_Cpp.SetMix(fromAnimationName, toAnimationName, duration[i]);
                }
            }
        }

        public void FillStateData(bool quiet = false)
        {
            if (stateData != null)
            {
                stateData.DefaultMix = defaultMix;

                for (int i = 0, n = fromAnimation.Length; i < n; i++)
                {
                    string fromAnimationName = fromAnimation[i];
                    string toAnimationName = toAnimation[i];
                    if (fromAnimationName.Length == 0 || toAnimationName.Length == 0)
                        continue;
#if UNITY_EDITOR
                    if (skeletonData.FindAnimation(fromAnimationName) == null)
                    {
                        if (!quiet)
                            Debug.LogError(
                                string.Format("Custom Mix Durations: Animation '{0}' not found, was it renamed?",
                                    fromAnimationName), this);
                        continue;
                    }

                    if (skeletonData.FindAnimation(toAnimationName) == null)
                    {
                        if (!quiet)
                            Debug.LogError(
                                string.Format("Custom Mix Durations: Animation '{0}' not found, was it renamed?",
                                    toAnimationName), this);
                        continue;
                    }
#endif
                    stateData.SetMix(fromAnimationName, toAnimationName, duration[i]);
                }
            }
        }

        internal Atlas[] GetAtlasArray()
        {
            List<Atlas> returnList = new System.Collections.Generic.List<Atlas>(atlasAssets.Length);
            for (int i = 0; i < atlasAssets.Length; i++)
            {
                AtlasAssetBase aa = atlasAssets[i];
                if (aa == null) continue;
                Atlas a = aa.GetAtlas();
                if (a == null) continue;
                returnList.Add(a);
            }

            return returnList.ToArray();
        }

        internal List<SpineCpp.Atlas> GetAtlasArray_Cpp()
        {
            List<SpineCpp.Atlas> returnList = new System.Collections.Generic.List<SpineCpp.Atlas>(atlasAssets.Length);
            for (int i = 0; i < atlasAssets.Length; i++)
            {
                AtlasAssetBase aa = atlasAssets[i];
                if (aa == null) continue;
                SpineCpp.Atlas a = aa.GetAtlas_Cpp();
                if (a == null) continue;
                returnList.Add(a);
            }

            return returnList;
        }


        internal static SkeletonData ReadSkeletonData(byte[] bytes, AttachmentLoader attachmentLoader, float scale)
        {
            using (MemoryStream input = new MemoryStream(bytes))
            {
                SkeletonBinary binary = new SkeletonBinary(attachmentLoader)
                {
                    Scale = scale
                };
                return binary.ReadSkeletonData(input);
            }
        }

        internal static SkeletonData ReadSkeletonData(string text, AttachmentLoader attachmentLoader, float scale)
        {
            StringReader input = new StringReader(text);
            SkeletonJson json = new SkeletonJson(attachmentLoader)
            {
                Scale = scale
            };
            return json.ReadSkeletonData(input);
        }
    }
}