#include <globaldefs.h>
#include "System/BackgroundControl.h"

extern "C"
{
    extern int data_020f01f8[][4];
    extern int data_020f0218[][4];
}

// USA: func_0204a5d4
ARM void SetValue_0x260(struct BackgroundOwner* owner, int value)
{
    owner->value_0x260 = value;
}

// USA: func_0204a5dc
ARM void SetValue_0x220(struct BackgroundOwner* owner, int value)
{
    owner->value_0x220 = value;
}

// USA: func_0204a5e4
ARM int GetTableEntry_020f01f8(int row, int column)
{
    return data_020f01f8[row][column];
}

// USA: func_0204a5f8
ARM int GetTableEntry_020f0218(int row, int column)
{
    return data_020f0218[row][column];
}

// USA: func_0204a60c
ARM void SetSubBg3Priority(int priority)
{
    *(volatile unsigned short*)0x400100e =
        (*(volatile unsigned short*)0x400100e & ~3) | priority;
}

// USA: func_0204a628
ARM void SetSubBg2Priority(int priority)
{
    *(volatile unsigned short*)0x400100c =
        (*(volatile unsigned short*)0x400100c & ~3) | priority;
}

// USA: func_0204a644
ARM void SetSubBg1Priority(int priority)
{
    *(volatile unsigned short*)0x400100a =
        (*(volatile unsigned short*)0x400100a & ~3) | priority;
}

// USA: func_0204a660
ARM void SetSubBg0Priority(int priority)
{
    *(volatile unsigned short*)0x4001008 =
        (*(volatile unsigned short*)0x4001008 & ~3) | priority;
}

// USA: func_0204a67c
ARM void SetMainBg3Priority(int priority)
{
    *(volatile unsigned short*)0x400000e =
        (*(volatile unsigned short*)0x400000e & ~3) | priority;
}

// USA: func_0204a698
ARM void SetMainBg2Priority(int priority)
{
    *(volatile unsigned short*)0x400000c =
        (*(volatile unsigned short*)0x400000c & ~3) | priority;
}

// USA: func_0204a6b4
ARM void SetMainBg1Priority(int priority)
{
    *(volatile unsigned short*)0x400000a =
        (*(volatile unsigned short*)0x400000a & ~3) | priority;
}

// USA: func_0204a6d0
ARM void SetMainBg0Priority(int priority)
{
    *(volatile unsigned short*)0x4000008 =
        (*(volatile unsigned short*)0x4000008 & ~3) | priority;
}

// USA: func_0204a6ec
ARM void SetSubBg3Offset(int hofs, int vofs)
{
    *(volatile unsigned int*)0x400101c = (hofs & 0x1ff) | ((vofs << 16) & (0x1ff << 16));
}

// USA: func_0204a714
ARM void SetSubBg2Offset(int hofs, int vofs)
{
    *(volatile unsigned int*)0x4001018 = (hofs & 0x1ff) | ((vofs << 16) & (0x1ff << 16));
}

// USA: func_0204a73c
ARM void SetSubBg1Offset(int hofs, int vofs)
{
    *(volatile unsigned int*)0x4001014 = (hofs & 0x1ff) | ((vofs << 16) & (0x1ff << 16));
}
