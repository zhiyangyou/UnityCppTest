using System;
using System.Reflection;
using NativeScript;
using UnityEngine;
using UnityEngine.Rendering;
using Object = System.Object;

namespace App
{
    public static class UnityUtils
    {
        public static bool IsUnityEditor()
        {
#if UNITY_EDITOR
            return true;
#else
            return false;
#endif
        }

        private static MethodInfo s_MiSetArrayForChannelImpl_Injected = null;
        private static MethodInfo s_MiObj2Ptr = null;

        static UnityUtils()
        {
            Type meshType = typeof(Mesh);

            s_MiSetArrayForChannelImpl_Injected = meshType.GetMethod("SetArrayForChannelImpl_Injected", BindingFlags.Static | BindingFlags.NonPublic);
            s_MiObj2Ptr = typeof(Object).GetMethod("GetPtrFromInstanceID", BindingFlags.Static | BindingFlags.NonPublic);
        }

        public static int GetUnityObjectInstanceId(int objectHandle)
        {
            var obj = Bindings.ObjectStore.Get(objectHandle);
            if (obj is UnityEngine.Object unityObj)
            {
                return unityObj.GetInstanceID();
            }
            return -1;
        }

        public static IntPtr GetMeshUnitySelfIntPtr(int instanceId)
        {
            var param = new object[3];
            param[0] = instanceId; // m.GetInstanceID();
            param[1] = typeof(Mesh);
            param[2] = null;
            IntPtr unitySelf = (IntPtr)s_MiObj2Ptr.Invoke(null, param);
            return unitySelf;
        }

        public static IntPtr GetMeshSetArrayForChannelImplFuncPtr()
        {
            return s_MiSetArrayForChannelImpl_Injected.MethodHandle.Value;
        }


        /// <summary>
        /// Mesh.SetVertices()的反射平替方法
        /// </summary>
        public static void Mesh_SetVertices_SetArrayForChannelImpl_Injected(
            int meshInstanceId,
            IntPtr arrayPointer,
            int arraySize,
            int valueStartIndex,
            int valueCount
        )
        {
            // IntPtr ptr = mi_SetArrayForChannelImpl_Injected.MethodHandle.Value;
            var param = new object[3];
            param[0] = meshInstanceId; // m.GetInstanceID();
            param[1] = typeof(Mesh);
            param[2] = null;
            IntPtr _unity_self = (IntPtr)s_MiObj2Ptr.Invoke(null, param);

            var param2 = new object[9];
            param2[0] = _unity_self;
            param2[1] = VertexAttribute.Position;
            param2[2] = VertexAttributeFormat.Float32;
            param2[3] = 3; //SetVertices with NativeArray should use struct type that is 12 bytes (3x float) in size 
            param2[4] = arrayPointer;
            param2[5] = arraySize;
            param2[6] = valueStartIndex;
            param2[7] = valueCount;
            param2[8] = MeshUpdateFlags.Default;

            s_MiSetArrayForChannelImpl_Injected.Invoke(null, param2);

            // Mesh.SetArrayForChannelImpl_Injected(
            //     _unity_self,
            //     VertexAttribute.Position,
            //     VertexAttributeFormat.Float32,
            //     2, 
            //     values,
            //     arraySize, //内存字节长度，并非元素个数
            //     valuesStart,
            //     valuesCount, // 元素个数
            //     MeshUpdateFlags.Default
            // );
        }

        public static void Mesh_SetUV0_XX(  )
        {
            Mesh m = new Mesh();
            m.subMeshCount = 1;
            m.SetTriangles();
            // m.uv2


        }
    }
}