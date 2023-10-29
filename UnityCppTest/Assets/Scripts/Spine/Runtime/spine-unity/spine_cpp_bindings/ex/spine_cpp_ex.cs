using System;
using System.Collections.Generic;

namespace spine_cpp
{
    namespace Spine
    {
        public static class SpineCppUtils
        {
            static spine_cpp.Spine.String Convert2SpineString(string str)
            {
                return new spine_cpp.Spine.String(str, true, false);
            }
        }
        public unsafe partial class Skin
        {
            public void getAttachments(ulong slotIndex, List<spine_cpp.Spine.SkinEntry> listEntries)
            {
                if (slotIndex < 0) throw new ArgumentException("slotIndex must be >= 0.");
                if (Attachments == null) throw new ArgumentNullException("attachments", "attachments cannot be null.");
                while (this.Attachments.HasNext)
                {
                    spine_cpp.Spine.SkinEntry entry = this.Attachments.Next;
                    if (entry.SlotIndex == slotIndex)
                    {
                        listEntries.Add(entry);
                    }
                }
            }
        }

        public unsafe partial class AtlasPage
        {
            public object rendererObject { get; set; }

            public AtlasPage Clone()
            {
                AtlasPage pageRet = new AtlasPage(this.Name);
                pageRet.Name = this.Name;
                pageRet.TexturePath = this.TexturePath;
                pageRet.Format = this.Format;
                pageRet.MinFilter = this.MinFilter;
                pageRet.MagFilter = this.MagFilter;
                pageRet.UWrap = this.UWrap;
                pageRet.VWrap = this.VWrap;
                pageRet.Texture = this.Texture;
                pageRet.Height = this.Height;
                pageRet.Width = this.Width;
                pageRet.Index = this.Index;
                pageRet.Pma = this.Pma;
                return pageRet;
            }
        }

        public unsafe partial class AtlasRegion
        {
            public AtlasRegion Clone()
            {
                AtlasRegion atlasRegion = new AtlasRegion(this);
                atlasRegion.RendererObject = RendererObject;
                atlasRegion.U = U;
                atlasRegion.V = V;
                atlasRegion.U2 = U2;
                atlasRegion.V2 = V2;
                atlasRegion.Degrees = Degrees;
                atlasRegion.OffsetX = OffsetX;
                atlasRegion.OffsetY = OffsetY;
                atlasRegion.Width = Width;
                atlasRegion.Height = Height;
                atlasRegion.OriginalWidth = OriginalWidth;
                atlasRegion.OriginalHeight = OriginalHeight;

                atlasRegion.Page = Page;
                atlasRegion.Name = Name;
                atlasRegion.Index = Index;
                atlasRegion.X = X;
                atlasRegion.Y = Y;
                
                //浅克隆
                atlasRegion.Splits = Splits;
                atlasRegion.Pads = Pads;
                atlasRegion.Names = Names;
                atlasRegion.Values = Values;

                return atlasRegion;
            }
        }
    }
}