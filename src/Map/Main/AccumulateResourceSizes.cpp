#include <globaldefs.h>
#include "Map/Main/MapArchiveLoader.h"

extern "C"
{
    int func_0207a6a4(void* object);
    void func_0207a734(void* object, void* self, SafeAllocator* allocator, void* arg);
    void* func_0207b000(void* object);
    void* func_0207ecc4(void* handle);
    int func_020b2e3c(void* resource);
    int func_020b2f30(void* resource);
}

// A node in the list func_0207b000 hands back. Only the field the walk reads
// and the link are known; everything between is carried as opaque bytes.
struct LoadedResource
{
    /* 0x000 */ char unknown_0x00[0x8];
    /* 0x008 */ void* handle;
    /* 0x00c */ char unknown_0x0c[0x100 - 0xc];
    /* 0x100 */ LoadedResource* next;
};

// USA: func_0201498c
//
// Walks everything loaded into the object at context +0xf4 and adds up two
// sizes per entry, into context +0x838 and +0x83c. Entries with no handle, and
// handles func_0207ecc4 rejects, contribute nothing.
ARM int AccumulateResourceSizes(MapLoadContext* context)
{
    if (!func_0207a6a4(context->unknown_0xf4))
        return 0;

    func_0207a734(context->unknown_0xf4, context->unknown_0xf4,
                  context->activeAllocator, context->unknown_0x50);

    LoadedResource* entry = (LoadedResource*)func_0207b000(context->unknown_0xf4);
    while (entry)
    {
        if (entry->handle)
        {
            void* resource = func_0207ecc4(entry->handle);
            if (resource)
            {
                context->unknown_0x838 += func_020b2e3c(resource);
                context->unknown_0x83c += func_020b2f30(resource);
            }
        }
        entry = entry->next;
    }

    return 1;
}
