#include <globaldefs.h>
#include "Map/Main/MapArchiveLoader.h"
#include "Map/Main/ZonePredicates.h"

extern "C"
{
    void* func_0202f798();
    int func_02003ce8(char* buffer, const char* format, ...);
    int func_0202fcfc(void* fileSystem, const char* path, int);

    extern const char data_020ef116[]; // "data/map"
    extern const char data_020ef156[]; // "%s/Z0%dM01.amdj"
    extern const char data_020ef166[]; // "%s/Z0%dM99.amdj"
    extern const char data_020ef176[]; // "%s/%sb.amdj"
    extern const char data_020ef182[]; // "%s/%sa.amdj"
    extern const char data_020ef18e[]; // "%s/%s.amdj"
}

// USA: func_020145a8
//
// The .amdj counterpart of LoadAmblArchive, with one extra case: zones 10000
// and 10100 load a 'b' archive and then an 'a' archive on successive calls,
// stepping a counter in the context. A third call for those zones builds no
// path at all and hands whatever the buffer already held to the open.
ARM void LoadAmdjArchive(MapLoadContext* context)
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
        func_02003ce8(path, data_020ef156, data_020ef116, environ);
    }
    else if (IsGrottoZoneSubrangeB(context->zoneID))
    {
        func_02003ce8(path, data_020ef166, data_020ef116,
                      context->activeGrotto.GetActiveGrottoEnviron());
    }
    else if (context->zoneID == 10000 || context->zoneID == 10100)
    {
        if (context->unknown_0x42c == 0)
        {
            func_02003ce8(path, data_020ef176, data_020ef116, context->record->code);
            context->unknown_0x42c++;
        }
        else if (context->unknown_0x42c == 1)
        {
            func_02003ce8(path, data_020ef182, data_020ef116, context->record->code);
            context->unknown_0x42c++;
        }
    }
    else
    {
        func_02003ce8(path, data_020ef18e, data_020ef116, context->record->code);
    }

    context->archives[3] = func_0202fcfc(fileSystem, path, 0);
}
