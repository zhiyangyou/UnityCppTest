using System;
using Codice.Client.Commands;
using UnityEngine;

namespace App {
    public abstract class BaseProxy {
        protected IntPtr pCpp;

        public IntPtr GetPtr() {
            return pCpp;
        }

        public BaseProxy(IntPtr ptr) {
            pCpp = ptr;
        }

        public bool HasDispose => pCpp == IntPtr.Zero;

        ~BaseProxy() {
            if (!HasDispose) {
                Debug.LogError("忘记释放C++指针");
            }
        }

        public abstract void DisposePtr();
    }
}