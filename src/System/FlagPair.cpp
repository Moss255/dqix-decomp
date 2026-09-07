#include <globaldefs.h>
#include "System/FlagPair.h"

// USA: func_0201238c
ARM void FlagPairNop()
{
}

// USA: func_02012390
ARM bool HasFirst_0x20(struct FlagPair* flags)
{
    return (flags->first & 0x20) != 0;
}

// USA: func_020123a4
ARM bool HasFirst_0x10(struct FlagPair* flags)
{
    return (flags->first & 0x10) != 0;
}

// USA: func_020123b8
ARM bool HasFirst_0x40(struct FlagPair* flags)
{
    return (flags->first & 0x40) != 0;
}

// USA: func_020123cc
ARM bool HasFirst_0x80(struct FlagPair* flags)
{
    return (flags->first & 0x80) != 0;
}

// USA: func_020123e0
ARM bool HasFirst_0x1(struct FlagPair* flags)
{
    return (flags->first & 0x1) != 0;
}

// USA: func_020123f4
ARM bool HasFirst_0x2(struct FlagPair* flags)
{
    return (flags->first & 0x2) != 0;
}

// USA: func_02012408
ARM bool HasFirst_0x400(struct FlagPair* flags)
{
    return (flags->first & 0x400) != 0;
}

// USA: func_0201241c
ARM bool HasFirst_0x800(struct FlagPair* flags)
{
    return (flags->first & 0x800) != 0;
}

// USA: func_02012430
ARM bool HasFirst(struct FlagPair* flags, unsigned int mask)
{
    return (flags->first & mask) != 0;
}

// USA: func_02012444
ARM bool HasFirstOnly(struct FlagPair* flags, unsigned int mask)
{
    if ((flags->first & mask) && !(flags->second & mask))
        return true;

    return false;
}

// USA: func_02012468
ARM bool HasSecondOnly(struct FlagPair* flags, unsigned int mask)
{
    if (!(flags->first & mask) && (flags->second & mask))
        return true;

    return false;
}
