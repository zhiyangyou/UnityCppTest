using System;
using UnityEngine;
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

        public static void Mesh_set_vertices(UnityEngine.Mesh mesh )
        {
            // mesh.SetVertices();
            // IntPtr _unity_self = Object.MarshalledUnityObject.MarshalNotNull<Mesh>(this);
            // UnityEngine.Mesh.SetNativeArrayForChannelImpl_Injected(_unity_self, channel, format, dim, values, arraySize, valuesStart, valuesCount, flags);
        }
    }
}