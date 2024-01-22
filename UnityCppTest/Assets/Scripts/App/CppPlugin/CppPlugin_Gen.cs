// using System;
// using App.Utils;
//
// public partial class Bridge
// {
//     private delegate int CppDele_CppFunction(int a, float b);
//
//     private static CppDele_CppFunction _cppDele_CppFunction = null;
//
//     private delegate IntPtr CppDele_LoadAtlas(IntPtr cChar, int dataLen);
//
//     private static CppDele_LoadAtlas _cppDele_LoadAtlas = null;
//
//     private delegate void CppDele_DeleteAtlas(IntPtr cChar);
//
//     private static CppDele_DeleteAtlas _cppDele_DeleteAtlas = null;
//
//     private delegate IntPtr CppDele_LoadSkeletonData(IntPtr pAtlas, IntPtr cChar);
//
//     private static CppDele_LoadSkeletonData _cppDele_LoadSkeletonData = null;
//
//     private delegate void CppDele_DeleteSkeletonData(IntPtr pSkeletonData);
//
//     private static CppDele_DeleteSkeletonData _cppDele_DeleteSkeletonData = null;
//
//
//     static Bridge()
//     {
//         _genBindingsFunc = () =>
//         {
//             _cppDele_CppFunction = DLLLoader.GetDelegate<CppDele_CppFunction>("CppFunction");
//             _cppDele_LoadAtlas = DLLLoader.GetDelegate<CppDele_LoadAtlas>("LoadAtlas");
//             _cppDele_DeleteAtlas = DLLLoader.GetDelegate<CppDele_DeleteAtlas>("DeleteAtlas");
//             _cppDele_LoadSkeletonData = DLLLoader.GetDelegate<CppDele_LoadSkeletonData>("LoadSkeletonData");
//             _cppDele_DeleteSkeletonData = DLLLoader.GetDelegate<CppDele_DeleteSkeletonData>("DeleteSkeletonData");
//
//             DLLLoader.OpenLibrary();
//             InitPlugin();
//         };
//     }
// }