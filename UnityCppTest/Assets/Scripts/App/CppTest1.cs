using System;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using App.Utils;
using Spine.Unity;
using Unity.Collections;
using UnityEngine;
using UnityEngine.Rendering;
using Object = UnityEngine.Object;

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
        private UnityEngine.Mesh _mesh;
        [SerializeField] public SkeletonDataAsset skeletonDataAsset;

        private Proxy_Atlas _proxyAtlas = null;
        private Proxy_SkeletonData _proxySkeletonData = null;


        private void OnGUI()
        {
            //使用这个来装换Unity的对象Handle
            // spine_cpp.SpineUnity.SmartMesh smartMesh =null;
            // var meshHandle = smartMesh.Mesh;
            // UnityEngine. (ObjectStore.Get(meshHandle) as UnityEngine.Mesh);

            // UnityEngine.Material mat = new Material();

            // UnityEngine.Object.Destroy();
            // UnityEngine.Object.DestroyImmediate();
            // UnityEngine.Application.isPlaying;

            // _mesh.hideFlags


            // _mesh.SetIndexBufferData(,,,,);
            // _mesh.SetVertexBufferData();
            // _mesh.SetUVs(,,,);
            if (GUI.Button(new Rect(100, 100, 100, 100), "Call Cpp"))
            {
                // var mesh = new Mesh();
                // UnityUtils.Mesh_SetVertices_SetArrayForChannelImpl_Injected();
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
            }
        }
    }
}