#include <globaldefs.h>
#include "std_library_functions.h"
#include "Map/Main/MapArchiveLoader.h"

extern "C"
{
    int func_02003ce8(char* buffer, const char* format, ...);

    extern const char data_020ef1de[]; // "ARC:/%s"
    extern const char data_020ef1e6[]; // "."
}

// USA: func_02014d18
//
// Names a member inside an already-open archive: "ARC:/" plus the stem, with
// the extension replaced. A stem that carries no dot gets one appended, so the
// caller can pass either an authored name or a bare stem.
ARM void BuildArcMemberPath(const char* stem, const char* extension, char* path)
{
    func_02003ce8(path, data_020ef1de, stem);

    char* dot = strrchr(path, '.');
    if (dot)
    {
        strcpy(dot + 1, extension);
    }
    else
    {
        strcat(path, data_020ef1e6);
        strcat(path, extension);
    }
}
