using System;
using System.Runtime.InteropServices;
using UnityEngine;

public class Const {
    public const string PluginName = "DLLPlugin";
}

public class CSharpCallCpp {
    //C++侧的方法
    [DllImport(Const.PluginName)]
    static extern int CppFunction(int a, float b);

    public static void Foo() {
        int retVal = CppFunction(2, 2.7f);
        Debug.Log($"Hello Cpp!!! {retVal}");
    }
}

public class CppCallCSharp {
    //一个普通的C#方法
    static int CSharpFunction(int a, float b) {
        return a + (int)b;
    }

    //C++侧的方法，由C#调用，将C#的函数指针传递给C++
    [DllImport(Const.PluginName)]
    static extern void Init(IntPtr ptrCSharpFunction);


    public static void InitPlugin() {
        Func<int, float, int> del = CSharpFunction;
        IntPtr funcPtr = Marshal.GetFunctionPointerForDelegate(del);
        Init(funcPtr);
    }
}