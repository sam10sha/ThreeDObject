#ifndef THREEDOBJECT_H
#define THREEDOBJECT_H

namespace ThreeD
{
    template <typename T>
    struct ThreeDObject
    {
    // Public structures
    public:
        struct OneDObject
        {
        // Public instance variables
        public:
            int Height;
            
        // Public consruction
        public:
            OneDObject(const int ObjHeight, T* DefaultObj, T* const ObjMem):
                Height(ObjHeight), DefaultObject(DefaultObj), ObjectMemory(ObjMem)
		    { }
            
        // Public operator overloads
        public:
            T& operator[](const int ZHeightCoord)
            {
                if(ZHeightCoord < Height && ObjectMemory)
                {
                    return ObjectMemory[ZHeightCoord];
                }
                else
                {
                    return *DefaultObject;
                }
            }
            
        // Private instance variables
        private:
            T* ObjectMemory;
            T* DefaultObject;
        };
        
        struct TwoDObject
        {
        // Public instance variables
        public:
            int Width;
            int Height;
            
        // Public consruction
        public:
            TwoDObject(const int ObjWidth, const int ObjHeight, T* DefaultObj, T* const ObjMem):
                Width(ObjWidth), Height(ObjHeight), DefaultObject(DefaultObj), ObjectMemory(ObjMem)
		    { }
            
        // Public operator overloads
        public:
            OneDObject operator[](const int YWidthCoord)
            {
                if(YWidthCoord < Width && ObjectMemory)
                {
                    return OneDObject(Height, DefaultObject, ObjectMemory + YWidthCoord * Height);
                }
                else
                {
                    return OneDObject(Height, DefaultObject, nullptr);
                }
            }
            
        // Private instance variables
        private:
            T* ObjectMemory;
            T* DefaultObject;
        };
    
    // Public instance variables
    public:
        int Depth;
        int Width;
        int Height;
    
    // Public construction/destruction
    public:
        ThreeDObject(const int ObjDepth, const int ObjWidth, const int ObjHeight, T* DefaultObj):
            Depth(ObjDepth),
            Width(ObjWidth),
            Height(ObjHeight),
            ObjectMemory(
			    ObjDepth > 0 && ObjWidth > 0 && ObjHeight > 0
			    ? new T[ObjDepth * ObjWidth * ObjHeight]
			    : nullptr
			),
			DefaultObject(DefaultObj) { }
        ThreeDObject(const ThreeDObject& Ref):
            Depth(Ref.Depth),
            Width(Ref.Width),
            Height(Ref.Height),
            ObjectMemory(
			    Ref.Depth > 0 && Ref.Width > 0 && Ref.Height > 0
			    ? new T[Ref.Depth * Ref.Width * Ref.Height]
			    : nullptr
			) { }
        ~ThreeDObject()
        {
            if(ObjectMemory)
            {
                delete[] ObjectMemory;
            }
        }
        
    // Public operator overloads
    public:
        ThreeDObject operator=(const ThreeDObject& Ref)
        {
            return ThreeDObject(Ref);
        }
        TwoDObject operator[](const int XDepthCoord)
        {
			if(XDepthCoord < Depth && ObjectMemory)
			{
			    return TwoDObject(Width, Height, DefaultObject, ObjectMemory + XDepthCoord * Width * Height);
			}
            else
			{
			    return TwoDObject(Width, Height, DefaultObject, nullptr);
			}
        }
        
    // Private instance variables
    private:
        T* ObjectMemory;
        T* DefaultObject;
    };
}

#endif // THREEDOBJECT_H