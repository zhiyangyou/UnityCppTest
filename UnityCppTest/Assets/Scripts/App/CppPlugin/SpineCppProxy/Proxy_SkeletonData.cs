using System;

namespace App {
    public class Proxy_SkeletonData : BaseProxy {
        public Proxy_SkeletonData(Proxy_Atlas proxyAtlas, string jsonContent) : base(
            Bridge.LoadSkeletonData(proxyAtlas.GetPtr(), jsonContent)) {
        }
        
        ~Proxy_SkeletonData() {
            DisposePtr();
        }

        public override void DisposePtr() {
            Bridge.DeleteSkeletonData(pCpp);
            pCpp = IntPtr.Zero;
        }
    }
}