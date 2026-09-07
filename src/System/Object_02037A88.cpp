#include <globaldefs.h>
#include "System/Object_02037A88.h"

// USA: func_02037a88
ARM unsigned int TestFlags_0x6c(struct Object_02037A88* object, unsigned int mask)
{
    return object->flags_0x6c & mask;
}

// USA: func_02037a94
ARM void SetFlags_0x6c(struct Object_02037A88* object, unsigned int mask)
{
    object->flags_0x6c |= mask;
}

// USA: func_02037aa4
ARM void ClearFlags_0x6c(struct Object_02037A88* object, unsigned int mask)
{
    object->flags_0x6c &= ~mask;
}

// USA: func_02037ab8
ARM unsigned int GetFlags_0x6c(struct Object_02037A88* object)
{
    return object->flags_0x6c;
}

// USA: func_02037ac0
ARM void SetValue_0x42(struct Object_02037A88* object, unsigned char value)
{
    object->value_0x42 = value;
}

// USA: func_02037ac8
ARM void SetValue_0xa4(struct Object_02037A88* object, int value)
{
    object->value_0xa4 = value;
}

// USA: func_02037ad0
ARM int GetValue_0xa4(struct Object_02037A88* object)
{
    return object->value_0xa4;
}

// USA: func_02037ad8
ARM void SetValue_0xa0(struct Object_02037A88* object, short value)
{
    object->value_0xa0 = value;
}

// USA: func_02037ae0
ARM short GetValue_0xa0(struct Object_02037A88* object)
{
    return object->value_0xa0;
}

// USA: func_02037ae8
ARM void SetValue_0x9e(struct Object_02037A88* object, unsigned char value)
{
    object->value_0x9e = value;
}

// USA: func_02037af0
ARM unsigned char GetValue_0x9e(struct Object_02037A88* object)
{
    return object->value_0x9e;
}
