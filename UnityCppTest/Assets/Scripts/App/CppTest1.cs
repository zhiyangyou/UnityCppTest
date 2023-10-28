using System;
using System.Runtime.InteropServices;
using App.Utils;
using Spine.Unity;
using UnityEngine;

namespace App
{
    struct Enemy
    {
        public Vector3 Position;
        private int _nameHandle; //初始化的时候必须是null

        public string Name
        {
            get => (string)ObjectStore.Get(_nameHandle);
            set
            {
                if (_nameHandle != 0)
                {
                    ObjectStore.Remove(_nameHandle);
                }

                if (value != null)
                {
                    _nameHandle = ObjectStore.Store(value);
                }
            }
        }
    }


    public class CppTest1 : MonoBehaviour
    {
        [SerializeField] public SkeletonDataAsset skeletonDataAsset;

        private Proxy_Atlas _proxyAtlas = null;
        private Proxy_SkeletonData _proxySkeletonData = null;

        private void Awake()
        {
            Utils.DLLLoader.OpenLibrary();
            Bridge.InitPlugin();
        }

        unsafe void DestoryPointers()
        {
        }

        private void OnGUI()
        {
            if (GUI.Button(new Rect(100, 100, 100, 100), "Call Cpp"))
            {
                DestoryPointers();
                string atlasContent = (skeletonDataAsset.atlasAssets[0] as SpineAtlasAsset).atlasFile.text;
                string jsonContent = skeletonDataAsset.skeletonJSON.text;
                _proxyAtlas = new Proxy_Atlas(atlasContent);
                _proxySkeletonData = new Proxy_SkeletonData(_proxyAtlas, jsonContent);
            }

            if (GUI.Button(new Rect(100, 200, 100, 100), "GC"))
            {
                GC.Collect();
            }

            if (GUI.Button(new Rect(100, 300, 100, 100), "LoadSpineCppBySharp"))
            {
                string atlasContent = (skeletonDataAsset.atlasAssets[0] as SpineAtlasAsset).atlasFile.text;
                
                var atlas = new spine_cpp.Spine.Atlas(atlasContent, atlasContent.Length, "", null, true);
                int a = 0;
            }
        }

        private void OnDestroy()
        {
            DestoryPointers();
            Utils.DLLLoader.CloseLibrary();
        }
    }
}