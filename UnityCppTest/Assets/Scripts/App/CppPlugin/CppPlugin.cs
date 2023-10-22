using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using App.Utils;
using UnityEngine;


public class Bridge {
    //一个普通的C#方法
    static int CSharpFunction(int a, float b) {
        return a + (int)b;
    }

    private delegate void InitCppFuncPointerDele(IntPtr funcPointer);


    private delegate int CppFunctionDele(int a, float b);

    private static CppFunctionDele _cppFunctionDele = null;

    private static Dictionary<string, IntPtr> _listCS2CppFuncPointers = new Dictionary<string, IntPtr>() {
        { "InitCSDebugLog", Marshal.GetFunctionPointerForDelegate((Action<IntPtr>)LogSharp) }
    };


    public static void InitPlugin() {
        foreach (var kv in _listCS2CppFuncPointers) {
            var deleFromCpp = DLLLoader.GetDelegate<InitCppFuncPointerDele>(kv.Key);
            deleFromCpp.Invoke(kv.Value);
        }

        _cppFunctionDele = DLLLoader.GetDelegate<CppFunctionDele>("CppFunction");
    }

    public static void CppFunction() {
        int retVal = _cppFunctionDele.Invoke(2, 2.7f);
        Debug.Log($"Hello Cpp!!! {retVal}");
    }


    public static void LogSharp(IntPtr cChar) {
        var strFromCpp = Marshal.PtrToStringAnsi(cChar);
        Debug.Log(strFromCpp);
    }
}