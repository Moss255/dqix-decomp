#include <globaldefs.h>
#include "Map/Main/ZonePredicates.h"
#include "Map/Main/MapArchiveLoader.h"
#include "Map/Main/MapListReader.h"

extern "C"
{
    // Returns the handle the archive functions take as their first argument.
    // Probably the mounted filesystem or an archive cache.
    void* func_0202f798();

    // sprintf. Formats into the buffer in r0.
    int func_02003ce8(char* buffer, const char* format, ...);

    // Begins loading a file by path and returns its handle, or a negative
    // value on failure. Third argument is always 0 here.
    int func_0202fcfc(void* fileSystem, const char* path, int);

    // String literals still owned by the un-delinked .rodata:
    extern const char data_020ef106[]; // "%s/Z0%dM01.ambl"
    extern const char data_020ef116[]; // "data/map"
    extern const char data_020ef11f[]; // "%s/Z0%dM99.ambl"
    extern const char data_020ef12f[]; // "%s/%s.ambl"
    extern const char data_020ef0f0[]; // "data/map/maplist9.bin"

    // True once the handle's data is resident.
    bool func_0202fdd0(void* fileSystem, int handle);

    // Hands back the loaded buffer and its length through the two out
    // parameters.
    void func_0202fec8(void* fileSystem, int handle, void** data, unsigned int* size);

    // Releases the handle and whatever it holds.
    void func_020301c8(void* fileSystem, int handle);
}

// USA: func_02013fb4
ARM bool PollMapListLoad(MapLoadContext* context)
{
    if (context->archives[0] < 0)
        return true;

    void* fileSystem = func_0202f798();
    if (!func_0202fdd0(fileSystem, context->archives[0]))
        return false;

    void* data;
    unsigned int size;
    func_0202fec8(fileSystem, context->archives[0], &data, &size);
    ReadMapListEntry(context->zoneID, &context->mapEntry, data, size);
    func_020301c8(fileSystem, context->archives[0]);

    context->archives[0] = -1;
    LoadAmblArchive(context);
    return true;
}

// USA: func_0201403c
ARM void LoadAmblArchive(MapLoadContext* context)
{
    void* fileSystem = func_0202f798();
    char path[0x14];

    if (IsGrottoZoneSubrangeA(context->zoneID))
    {
        int environ = context->activeGrotto.GetActiveGrottoEnviron();
        if (environ == 0)
            environ = 1;
        if (environ > 5)
            environ = 5;
        func_02003ce8(path, data_020ef106, data_020ef116, environ);
    }
    else if (IsGrottoZoneSubrangeB(context->zoneID))
    {
        func_02003ce8(path, data_020ef11f, data_020ef116,
                      context->activeGrotto.GetActiveGrottoEnviron());
    }
    else
    {
        func_02003ce8(path, data_020ef12f, data_020ef116, context->record->code);
    }

    context->archives[2] = func_0202fcfc(fileSystem, path, 0);
}
