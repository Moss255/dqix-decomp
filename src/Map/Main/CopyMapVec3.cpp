#include <globaldefs.h>
#include "Map/Main/MapArchiveLoader.h"

// USA: func_02013b54
ARM void CopyMapVec3(MapVec3* dst, const MapVec3* src)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
