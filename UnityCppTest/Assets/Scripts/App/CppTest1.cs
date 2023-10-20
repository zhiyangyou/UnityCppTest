using System.Runtime.InteropServices;
using App.Utils;
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
        // Start is called before the first frame update
        void Start() {
            CppCallCSharp.InitPlugin();
            CSharpCallCpp.Foo();

            unsafe {
                Enemy* enemies = (Enemy*)Marshal.AllocHGlobal(sizeof(Enemy) * 1000);
            }
        }

        // Update is called once per frame
        void Update() {
        }
    }
}