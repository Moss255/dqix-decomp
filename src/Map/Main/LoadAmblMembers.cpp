#include <globaldefs.h>
#include "Map/Main/MapArchiveLoader.h"

extern "C"
{
    // Hands back a member's data, and its length through the out parameter.
    void* func_02075608(SafeAllocator* allocator, void* member, void** size);

    // The pair the .bmbl path uses: func_0201e248 resets the object at
    // context +0x6c, func_0201e2b4 fills it from a member's bytes. The .bpos
    // path calls only the second, so the reset is specific to .bmbl.
    void func_0201e248(void* object);
    void func_0201e2b4(void* object, SafeAllocator* allocator, void* data, void* size);
}

// The .ambl archive is walked member by member and dispatched on the member's
// extension. The two handlers below are reached from that dispatch:
//
//     .nsbtx  -> func_0201445c
//     .bmbl   -> LoadBmblMember
//     .dat    -> handled inline, into the map entry at context +0xc
//     .bpos   -> LoadBposMember
//
// Both take a third argument from the walker that they never read.
//
// Both also save context->record across the call and write it back. Whatever
// func_0201e2b4 reaches must clobber it, which is worth knowing before that
// field is trusted across a load.

// USA: func_02014390
ARM int LoadBmblMember(MapLoadContext* context, void* member, void* unused)
{
    SafeAllocator* allocator = context->activeAllocator;

    void* size;
    void* data = func_02075608(allocator, member, &size);

    MapListRecord* record = context->record;
    func_0201e248(context->unknown_0x6c);
    func_0201e2b4(context->unknown_0x6c, allocator, data, size);
    context->record = record;
    return 1;
}

// USA: func_020143d8
ARM int LoadBposMember(MapLoadContext* context, void* member, void* unused)
{
    SafeAllocator* allocator = context->activeAllocator;

    void* size;
    void* data = func_02075608(allocator, member, &size);

    MapListRecord* record = context->record;
    func_0201e2b4(context->unknown_0x6c, allocator, data, size);
    context->record = record;
    return 1;
}
