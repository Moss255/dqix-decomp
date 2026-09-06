#include <globaldefs.h>
#include "Map/Main/MapArchiveLoader.h"

extern "C"
{
    void func_02013454(MapObjectNode* node);
    void* func_02075608(SafeAllocator* allocator, void* member, void** size);
    void func_0201f040(void* object, SafeAllocator* allocator, void* data, void* size);
}

// USA: func_02014900
//
// Called once per archive member whose name matches a resource in the map's
// manifest. Allocates the node, carries the resource's position onto it, loads
// the member's bytes into it, and pushes it onto the context's object list.
//
// Both failure paths leak: the node is already allocated when the member load
// is attempted, and nothing releases it when that returns NULL.
ARM int AddMapObject(MapLoadContext* context, void* member, void* unused,
                     const MapResource* resource)
{
    SafeAllocator* allocator = context->activeAllocator;

    MapObjectNode* node = (MapObjectNode*)allocator->Allocate(0x58);
    if (!node)
        return 0;

    func_02013454(node);
    node->unknown_0x00 = resource->unknown_0x00;
    CopyMapVec3(&node->position, &resource->position);

    void* size;
    void* data = func_02075608(allocator, member, &size);
    if (!data)
        return 0;

    func_0201f040(&node->unknown_0x04, allocator, data, size);

    node->next = context->objectList;
    context->objectList = node;
    return 1;
}
