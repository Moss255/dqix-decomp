#include <globaldefs.h>
#include "System/Object_02037A88.h"

// USA: func_02033f2c
ARM void ClearBits6And7(struct Object_02037A88* object)
{
    object->flag_bit6 = 0;
    object->flag_bit7 = 0;
}

// USA: func_02033f44
ARM int* GetValue_0xe4IfBit6(struct Object_02037A88* object)
{
    return object->flag_bit6 ? &object->value_0xe4 : NULL;
}

// USA: func_02033f5c
ARM unsigned char GetBit6(struct Object_02037A88* object)
{
    return object->flag_bit6;
}

// USA: func_02033f6c
ARM void SetPair_0x114(struct Object_02037A88* object, const struct Halfword4* src)
{
    CopyHalfword4(&object->pair_0x114, src);
}

// USA: func_02033f7c
ARM void CopyHalfword4(struct Halfword4* dst, const struct Halfword4* src)
{
    dst->values[0] = src->values[0];
    dst->values[1] = src->values[1];
    dst->values[2] = src->values[2];
    dst->values[3] = src->values[3];
}

// USA: func_02033fa0
ARM struct Halfword4* GetPair_0x114(struct Object_02037A88* object)
{
    return &object->pair_0x114;
}

// USA: func_02033fa8
ARM void SetPair_0x11c(struct Object_02037A88* object, const struct Halfword4* src)
{
    object->flag_bit7 = 1;
    CopyHalfword4(&object->pair_0x11c, src);
}

// USA: func_02033fc4
ARM struct Halfword4* GetPair_0x11c(struct Object_02037A88* object)
{
    return &object->pair_0x11c;
}

// USA: func_02033fcc
ARM void SetBit2(struct Object_02037A88* object)
{
    object->flag_bit2 = 1;
}

// USA: func_02033fdc
ARM void ClearBit2(struct Object_02037A88* object)
{
    object->flag_bit2 = 0;
}

// USA: func_02033fec
ARM void SetBit1AndFlag(struct Object_02037A88* object)
{
    SetFlags_0x6c(object, 0x40000);
    object->flag_bit1 = 1;
}

// USA: func_0203400c
ARM void ClearBit1AndFlag(struct Object_02037A88* object)
{
    ClearFlags_0x6c(object, 0x40000);
    object->flag_bit1 = 0;
}

// USA: func_0203402c
ARM bool HasField15_0xc4(struct Object_02037A88* object)
{
    return object->field15_0xc4 != 0;
}
