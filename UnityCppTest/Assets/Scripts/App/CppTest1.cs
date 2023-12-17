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

        static void ReflectMesh_SetArrayForChannelImpl_Injected()
        {
            Type meshType = typeof(Mesh);

            // 获取SetSizedNativeArrayForChannel方法
            MethodInfo mi_SetArrayForChannelImpl_Injected = meshType.GetMethod("SetArrayForChannelImpl_Injected", BindingFlags.Static | BindingFlags.NonPublic);
            MethodInfo mi_Obj2Ptr = typeof(Object).GetMethod("GetPtrFromInstanceID", BindingFlags.Static | BindingFlags.NonPublic);
            IntPtr ptr = mi_SetArrayForChannelImpl_Injected.MethodHandle.Value;
            int a = 0;
            Mesh m = new Mesh();
            var param = new object[3];
            param[0] = m.GetInstanceID();
            param[1] = typeof(Mesh);
            param[2] = null;
            IntPtr _unity_self = (IntPtr)mi_Obj2Ptr.Invoke(null, param);
            Debug.Log(_unity_self);
            Debug.Log($"is mono {param[2]}");

            Mesh.SetVertices();  //的反射平替方法
            
            
            
            // IntPtr _unity_self = Object.MarshalledUnityObject.MarshalNotNull(m);
            //SetVertices with NativeArray should use struct type that is 8 bytes (2x float) in size 
            Mesh.SetArrayForChannelImpl_Injected(
                _unity_self,
                VertexAttribute.Position,
                VertexAttributeFormat.Float32,
                2,
                values,
                arraySize,      //内存字节长度，并非元素个数
                valuesStart,    
                valuesCount,    // 元素个数
                MeshUpdateFlags.Default
            );
        }

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
                ReflectMesh_SetArrayForChannelImpl_Injected();
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