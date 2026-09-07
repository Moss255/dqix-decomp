#include <globaldefs.h>
#include "System/VramSlots.h"

extern "C"
{
    extern unsigned short data_02111224[];
}

// USA: func_020c4b38
ARM unsigned short GetSlot_0x02()
{
    return data_02111224[0x1];
}

// USA: func_020c4b48
ARM unsigned short GetSlot_0x04()
{
    return data_02111224[0x2];
}

// USA: func_020c4b58
ARM unsigned short GetSlot_0x0e()
{
    return data_02111224[0x7];
}

// USA: func_020c4b68
ARM unsigned short GetSlot_0x10()
{
    return data_02111224[0x8];
}

// USA: func_020c4b78
ARM unsigned short GetSlot_0x08()
{
    return data_02111224[0x4];
}

// USA: func_020c4b88
ARM unsigned short GetSlot_0x0a()
{
    return data_02111224[0x5];
}

// USA: func_020c4b98
ARM unsigned short GetSlot_0x12()
{
    return data_02111224[0x9];
}

// USA: func_020c4ba8
ARM unsigned short GetSlot_0x14()
{
    return data_02111224[0xa];
}

// USA: func_020c4bb8
ARM unsigned short GetSlot_0x16()
{
    return data_02111224[0xb];
}

// USA: func_020c4bc8
ARM unsigned short GetSlot_0x18()
{
    return data_02111224[0xc];
}
