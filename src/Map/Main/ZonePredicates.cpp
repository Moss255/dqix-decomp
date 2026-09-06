#include <globaldefs.h>
#include "Map/Main/ZonePredicates.h"

// USA: func_0201b588
ARM bool IsGrottoZone(int zoneID)
{
    return zoneID >= 0x9c41 && zoneID <= 0x9c41 + 0x5e0;
}

// USA: func_0201b5b0
ARM bool IsGrottoZoneSubrangeA(int zoneID)
{
    return zoneID >= 0x9c41 && zoneID <= 0x9c41 + 0x5f;
}

// USA: func_0201b5d8
ARM bool IsGrottoZoneSubrangeB(int zoneID)
{
    return zoneID >= 0xa08d && zoneID <= 0xa08d + 0x194;
}
