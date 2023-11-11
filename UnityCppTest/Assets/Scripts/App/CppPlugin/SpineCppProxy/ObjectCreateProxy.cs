using UnityEngine;

namespace App
{
    public class ObjectCreateProxy
    {
        public static Mesh CreateMesh()
        {
            return new Mesh();
        }

        public static GameObject CreateGo()
        {
            return new GameObject();
        }
    }
}