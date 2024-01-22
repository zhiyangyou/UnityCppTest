// using System;
// using App.Utils;
//
// namespace App {
//     public class Proxy_Atlas : BaseProxy {
//         public Proxy_Atlas(string atlasContent)
//             : base(Bridge.LoadAtlas(atlasContent)) {
//         }
//
//         ~Proxy_Atlas() {
//             DisposePtr();
//         }
//
//         public override void DisposePtr() {
//             Bridge.DeleteAtlas(pCpp);
//             pCpp = IntPtr.Zero;
//         }
//     }
// }