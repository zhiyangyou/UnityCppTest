
using System;
using App.Utils;
public partial class Bridge {
    private delegate int CppDele_CppFunction(int a, float b);
    private static CppDele_CppFunction _cppDele_CppFunction = null;
    private delegate IntPtr CppDele_LoadAtlas(IntPtr cChar, int dataLen);
    private static CppDele_LoadAtlas _cppDele_LoadAtlas = null;
    private delegate void CppDele_DeleteAtlas(IntPtr cChar);
    private static CppDele_DeleteAtlas _cppDele_DeleteAtlas = null;

    
    static Bridge() {
        _genBindingsFunc = () => {
            _cppDele_CppFunction = DLLLoader.GetDelegate<CppDele_CppFunction>("CppFunction");
            _cppDele_LoadAtlas = DLLLoader.GetDelegate<CppDele_LoadAtlas>("LoadAtlas");
            _cppDele_DeleteAtlas = DLLLoader.GetDelegate<CppDele_DeleteAtlas>("DeleteAtlas");

        };
    }
}
