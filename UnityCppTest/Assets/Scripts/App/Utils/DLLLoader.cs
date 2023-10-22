using System;
using System.IO;
using System.Runtime.InteropServices;
using UnityEngine;


namespace App.Utils {
    public static class DLLLoader {
#if UNITY_EDITOR_WIN

        private static string _dllPath = "";
        private static IntPtr _dllHandle;

        private static string DllPath {
            get {
                if (string.IsNullOrEmpty(_dllPath)) {
                    string dllFullPath = Application.dataPath + "";
                    DirectoryInfo dir = new DirectoryInfo(dllFullPath);
                    FileInfo fileInfo = new FileInfo(dir.Parent.Parent.FullName + "/DLLExportDir/DLLPlugin.dll");
                    _dllPath = fileInfo.FullName;
                }

                return _dllPath;
            }
        }

        [DllImport("kernel32")]
        static extern IntPtr LoadLibrary(
            string path);

        [DllImport("kernel32")]
        static extern IntPtr GetProcAddress(
            IntPtr libraryHandle,
            string symbolName);

        [DllImport("kernel32")]
        static extern bool FreeLibrary(
            IntPtr libraryHandle);

        public static IntPtr OpenLibrary() {
            _dllHandle = LoadLibrary(DllPath);
            if (_dllHandle == IntPtr.Zero) {
                throw new Exception("Couldn't open native library: " + DllPath);
            }

            return _dllHandle;
        }

        public static void CloseLibrary() {
            FreeLibrary(_dllHandle);
        }

        public static T GetDelegate<T>(
            string functionName) where T : class {
            IntPtr symbol = GetProcAddress(_dllHandle, functionName);
            if (symbol == IntPtr.Zero) {
                throw new Exception("Couldn't get function: " + functionName);
            }

            return Marshal.GetDelegateForFunctionPointer(
                symbol,
                typeof(T)) as T;
        }
#endif
    }
}