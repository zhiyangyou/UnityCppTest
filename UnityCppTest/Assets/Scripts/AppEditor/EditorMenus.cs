using UnityEditor;
using UnityEngine;

namespace NativeScript.Editor
{
    /// <summary>
    /// Menus for the Unity Editor
    /// </summary>
    /// 
    /// <author>
    /// Jackson Dunstan, 2018, http://JacksonDunstan.com
    /// </author>
    /// 
    /// <license>
    /// MIT
    /// </license>
    public static class EditorMenus
    {
        [MenuItem("NativeScript/Generate Bindings #%g")]
        public static void Generate()
        {
            GenerateBindings.Generate();
        }

        private static bool hasOpen = false;

        [MenuItem("NativeScript/Reload Plugin #%r")]
        public static void Reload()
        {
            if (!hasOpen)
            {
                Bindings.Open(30 * 1024 * 1024); // 30MB
                hasOpen = true;
            }

            Bindings.Reload();
            // Bindings.Reload();
        }

        [MenuItem("NativeScript/ClosePlugin")]
        public static void Close()
        {
            if (hasOpen)
            {
                Debug.Log("Bindings.Close()");
                Bindings.Close();
                hasOpen = false;
            }
        }
    }
}