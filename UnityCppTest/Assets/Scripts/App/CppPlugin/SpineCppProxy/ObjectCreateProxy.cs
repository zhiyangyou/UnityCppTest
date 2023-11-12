using System;
using System.Runtime.InteropServices;
using UnityEngine;

namespace App
{
    public static class ObjectCreateProxy
    {
        public static Mesh CreateMesh()
        {
            return new Mesh();
        }

        public static GameObject CreateGo()
        {
            return new GameObject();
        }

        public static IntPtr GetStringCStr(string str)
        {
            // return IntPtr.Zero;
            return Marshal.StringToHGlobalAnsi(str);
        }
    }
}