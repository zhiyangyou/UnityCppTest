using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using App.Utils;
using UnityEngine;
using UnityEngine.Diagnostics;

public partial class Bridge
{
    private delegate void InitCppFuncPointerDele(IntPtr funcPointer);

    private static Dictionary<string, IntPtr> _listCS2CppFuncPointers = new()
    {
        { "InitCSDebugLog", Marshal.GetFunctionPointerForDelegate((Action<IntPtr>)LogSharp) }
    };

    private delegate void GenBindingsFunc();

    private static GenBindingsFunc _genBindingsFunc = null;
    
    public static void InitPlugin()
    {
        foreach (var kv in _listCS2CppFuncPointers)
        {
            var deleFromCpp = DLLLoader.GetDelegate<InitCppFuncPointerDele>(kv.Key);
            deleFromCpp.Invoke(kv.Value);
        }

        if (_genBindingsFunc != null)
        {
            _genBindingsFunc();
        }
    }

    public static void LogSharp(IntPtr cChar)
    {
        var strFromCpp = Marshal.PtrToStringAnsi(cChar);
        Debug.Log(strFromCpp);
    }
}