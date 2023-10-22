using System;
using System.Runtime.InteropServices;
using App.Utils;
using Spine.Unity;
using UnityEngine;

namespace App {
    struct Enemy {
        public Vector3 Position;
        private int _nameHandle; //初始化的时候必须是null

        public string Name {
            get => (string)ObjectStore.Get(_nameHandle);
            set {
                if (_nameHandle != 0) {
                    ObjectStore.Remove(_nameHandle);
                }

                if (value != null) {
                    _nameHandle = ObjectStore.Store(value);
                }
            }
        }
    }


    public class CppTest1 : MonoBehaviour {
        [SerializeField] public SkeletonDataAsset skeletonDataAsset;

        private IntPtr atlasPointer;

        private void Awake() {
            Utils.DLLLoader.OpenLibrary();
            Bridge.InitPlugin();
            Bridge.CppFunction();
        }

        unsafe void DestoryPointers() {
            if (atlasPointer.ToPointer() != null) {
                Bridge.DeleteAtlas(atlasPointer);
            }
        }

        private void OnGUI() {
            if (GUI.Button(new Rect(100, 100, 300, 300), "Call Cpp")) {
                DestoryPointers();
                string atlasFileContent = (skeletonDataAsset.atlasAssets[0] as SpineAtlasAsset).atlasFile.text;
                atlasPointer = Bridge.LoadAtlas(atlasFileContent);
            }
        }

        private void OnDestroy() {
            DestoryPointers();
            Utils.DLLLoader.CloseLibrary();
        }
    }
}