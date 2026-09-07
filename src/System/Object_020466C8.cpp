#include <globaldefs.h>
#include "System/Object_020466C8.h"

// USA: func_020466c8
ARM void SetValue_0x38(struct Object_020466C8* object, int value)
{
    object->value_0x38 = value;
}

// USA: func_020466d0
ARM SafeAllocator* ConstructAllocator(SafeAllocator* allocator)
{
    allocator->ResetAllocatorPointer();
    return allocator;
}

// USA: func_020466e4
ARM void SetFlags(struct Object_020466C8* object, unsigned int mask)
{
    object->flags |= mask;
}

// USA: func_020466f4
ARM void ClearFlags(struct Object_020466C8* object, unsigned int mask)
{
    object->flags &= ~mask;
}

// USA: func_02046708
ARM bool TestFlags(struct Object_020466C8* object, unsigned int mask)
{
    return (object->flags & mask) != 0;
}

// USA: func_0204671c
ARM unsigned int GetFlags(struct Object_020466C8* object)
{
    return object->flags;
}

// USA: func_02046724
ARM void ClearAllFlags(struct Object_020466C8* object)
{
    object->flags = 0;
}

// USA: func_02046730
ARM void ClearAllFlags2(struct Object_020466C8* object)
{
    object->flags = 0;
}
