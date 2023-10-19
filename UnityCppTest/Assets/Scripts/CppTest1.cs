using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CppTest1 : MonoBehaviour {
    // Start is called before the first frame update
    void Start() {
        CppCallCSharp.InitPlugin();
        CSharpCallCpp.Foo();
    }

    // Update is called once per frame
    void Update() {
    }
}