using System.Collections.Generic;
using System.Text;
using UnityEditor;
using UnityEngine;
using UnityEngine.Windows;

struct GenFuncInfo {
    public GenFuncInfo(string name, string delegateName, string delegateDef) {
        this.Name = name;
        this.DelegateName = delegateName;
        this.DelegateDef = delegateDef;
    }

    public string Name;
    public string DelegateName;
    public string DelegateDef;
}

public static class GenCppBindings {
    private static string genPath = "/Scripts/App/CppPlugin/CppPlugin_Gen.cs";

    private static string genCSFileTemplate = @"
using System;
using App.Utils;
public partial class Bridge {
##defs
    
    static Bridge() {
        _genBindingsFunc = () => {
##initFuncs
        };
    }
}
";

    private static List<GenFuncInfo> _dicBindingFuncNames = new() {
        new GenFuncInfo("CppFunction", "CppDele_CppFunction", "int CppDele_CppFunction(int a, float b)"),
        new GenFuncInfo("LoadAtlas", "CppDele_LoadAtlas", "IntPtr CppDele_LoadAtlas(IntPtr cChar, int dataLen)"),
        new GenFuncInfo("DeleteAtlas", "CppDele_DeleteAtlas", "void CppDele_DeleteAtlas(IntPtr cChar)"),
    };

    [MenuItem("Cpp/GenCppPluginFuncBinding")]
    public static void GenCppPluginFuncBinding() {
        var genFullPath = Application.dataPath + genPath;

        StringBuilder sbDefs = new StringBuilder();
        StringBuilder sbInitFuncs = new StringBuilder();
        foreach (var info in _dicBindingFuncNames) {
            var funcName = info.Name;
            var delegateName = info.DelegateName;
            var delegateDef = info.DelegateDef;
            var delegateDefVariableName = $"_cppDele_{funcName}";
            string strDelegate = $"    private delegate {delegateDef};\n";
            string strDelegateDef = $"    private static {delegateName} {delegateDefVariableName} = null;\n";
            sbDefs.Append(strDelegate);
            sbDefs.Append(strDelegateDef);
            sbInitFuncs.Append($"            {delegateDefVariableName} = DLLLoader.GetDelegate<{delegateName}>(\"{funcName}\");\n");
        }

        var csFileContent = genCSFileTemplate
                .Replace("##defs", sbDefs.ToString())
                .Replace("##initFuncs", sbInitFuncs.ToString())
            ;
        System.IO.File.WriteAllText(genFullPath, csFileContent);
    }
}