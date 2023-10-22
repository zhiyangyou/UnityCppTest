using System;
using System.Runtime.InteropServices;
using UnityEngine;

public partial class Bridge {
    public static void CppFunction() {
        int retVal = _cppDele_CppFunction(2, 2.7f);
        Debug.Log($"Hello Cpp!!! ${retVal}");
    }

    public static IntPtr LoadAtlas(string atlasContent) {
        IntPtr atlasPointer = _cppDele_LoadAtlas(Marshal.StringToHGlobalAnsi(atlasContent), atlasContent.Length);
        return atlasPointer;
    }

    public static void DeleteAtlas(IntPtr pointer) {
        unsafe {
            if (pointer.ToPointer() != null) {
                _cppDele_DeleteAtlas(pointer);
            }
        }
    }
}