#include <globaldefs.h>
#include "System/VramRelease.h"

extern "C"
{
    void func_020c490c(unsigned short* slot);
    extern unsigned short data_02111226;
    extern unsigned short data_02111228;
    extern unsigned short data_02111232;
    extern unsigned short data_02111234;
    extern unsigned short data_0211122c;
    extern unsigned short data_0211122e;
    extern unsigned short data_02111230;
    extern unsigned short data_0211122a;
    extern unsigned short data_02111224;
    extern unsigned short data_02111236;
    extern unsigned short data_02111238;
    extern unsigned short data_0211123a;
    extern unsigned short data_0211123c;
}

// USA: func_020c49ec
ARM void Release_02111226()
{
    func_020c490c(&data_02111226);
}

// USA: func_020c4a00
ARM void Release_02111228()
{
    func_020c490c(&data_02111228);
}

// USA: func_020c4a14
ARM void Release_02111232()
{
    *(volatile unsigned int*)0x4000000 &= ~0x40000000;
    func_020c490c(&data_02111232);
}

// USA: func_020c4a38
ARM void Release_02111234()
{
    *(volatile unsigned int*)0x4000000 &= ~0x80000000;
    func_020c490c(&data_02111234);
}

// USA: func_020c4a5c
ARM void Release_0211122c()
{
    func_020c490c(&data_0211122c);
}

// USA: func_020c4a70
ARM void Release_0211122e()
{
    func_020c490c(&data_0211122e);
}

// USA: func_020c4a84
ARM void Release_02111230()
{
    func_020c490c(&data_02111230);
}

// USA: func_020c4a98
ARM void Release_0211122a()
{
    func_020c490c(&data_0211122a);
}

// USA: func_020c4aac
ARM void Release_02111224()
{
    func_020c490c(&data_02111224);
}

// USA: func_020c4ac0
ARM void Release_02111236()
{
    func_020c490c(&data_02111236);
}

// USA: func_020c4ad4
ARM void Release_02111238()
{
    func_020c490c(&data_02111238);
}

// USA: func_020c4ae8
ARM void Release_0211123a()
{
    *(volatile unsigned int*)0x4001000 &= ~0x40000000;
    func_020c490c(&data_0211123a);
}

// USA: func_020c4b10
ARM void Release_0211123c()
{
    *(volatile unsigned int*)0x4001000 &= ~0x80000000;
    func_020c490c(&data_0211123c);
}
