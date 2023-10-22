using System;
using System.Runtime.InteropServices;
using App.Utils;
using UnityEngine;

    
    

public class Bridge {
    //一个普通的C#方法
    static int CSharpFunction(int a, float b) {
        return a + (int)b;
    }

    private delegate void InitDele(IntPtr funcPointer);

    private static InitDele _initDele = null;

    private delegate int CppFunctionDele(int a, float b);

    private static CppFunctionDele _cppFunctionDele = null;
    
    static void Init(IntPtr ptrCSharpFunction) {
        _initDele.Invoke(ptrCSharpFunction);
    }


    public static void InitPlugin() {
        _initDele = DLLLoader.GetDelegate<InitDele>("Init");
        _cppFunctionDele = DLLLoader.GetDelegate<CppFunctionDele>("CppFunction");
    }
    
    public static void Foo() {
        int retVal = _cppFunctionDele.Invoke(2, 2.7f);
        Debug.Log($"Hello Cpp!!! {retVal}");
    }
}