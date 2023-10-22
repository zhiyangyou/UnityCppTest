using System;
using System.Runtime.InteropServices;
using App.Utils;
using UnityEngine;

public partial class Bridge {
    public static void CppFunction() {
        int retVal = _cppDele_CppFunction(2, 2.7f);
        Debug.Log($"Hello Cpp!!! ${retVal}");
    }

    public static IntPtr LoadSkeletonData(IntPtr pAtlas, string jsonContent) {
        IntPtr pSkeletonData = _cppDele_LoadSkeletonData(pAtlas, Marshal.StringToHGlobalAnsi(jsonContent));
        return pSkeletonData;
    }

    public static void DeleteSkeletonData(IntPtr pointer) {
        if (!DLLLoader.HasLoaded) {
            if (pointer != IntPtr.Zero && Application.isPlaying) {
                Debug.LogError("DeleteSkeletonData 可能存在非托管对象泄露");
            }

            return;
        }

        _cppDele_DeleteSkeletonData(pointer);
    }

    public static IntPtr LoadAtlas(string atlasContent) {
        IntPtr atlasPointer = _cppDele_LoadAtlas(Marshal.StringToHGlobalAnsi(atlasContent), atlasContent.Length);
        return atlasPointer;
    }

    public static void DeleteAtlas(IntPtr pointer) {
        if (!DLLLoader.HasLoaded) {
            if (pointer != IntPtr.Zero && Application.isPlaying) {
                Debug.LogError("DeleteAtlas 可能存在非托管对象泄露");
            }

            return;
        }

        if (pointer != IntPtr.Zero) {
            _cppDele_DeleteAtlas(pointer);
        }
    }
}