#include <globaldefs.h>
#include "System/AccessorObject.h"

// USA: func_02039820
ARM unsigned char GetValue_0x252(struct AccessorObject* object)
{
    return object->value_0x252;
}

// USA: func_02039828
ARM unsigned char GetValue_0x253(struct AccessorObject* object)
{
    return object->value_0x253;
}

// USA: func_02039830
ARM void CopyValue_0x253_to_0x252(struct AccessorObject* object)
{
    object->value_0x252 = object->value_0x253;
}

// USA: func_0203983c
ARM void SetValue_0x254(struct AccessorObject* object, int value)
{
    object->value_0x254 = (value != 0);
}

// USA: func_02039850
ARM unsigned char GetValue_0x254(struct AccessorObject* object)
{
    return object->value_0x254;
}

// USA: func_02039858
ARM void SetValue_0x1c8(struct AccessorObject* object, signed char value)
{
    object->values_0x1c8[0] = value;
}

// USA: func_02039860
ARM signed char GetValue_0x1c8(struct AccessorObject* object)
{
    return object->values_0x1c8[0];
}

// USA: func_0203986c
ARM void SetValue_0x1c9(struct AccessorObject* object, signed char value)
{
    object->values_0x1c8[1] = value;
}

// USA: func_02039874
ARM signed char GetValue_0x1c9(struct AccessorObject* object)
{
    return object->values_0x1c8[1];
}

// USA: func_02039880
ARM void SetValue_0x1ca(struct AccessorObject* object, signed char value)
{
    object->values_0x1c8[2] = value;
}

// USA: func_02039888
ARM signed char GetValue_0x1ca(struct AccessorObject* object)
{
    return object->values_0x1c8[2];
}

// USA: func_02039894
ARM void SetFlag_0x1ce(struct AccessorObject* object)
{
    object->flags_0x1ce |= 1;
}

// USA: func_020398a4
ARM void ClearFlag_0x1ce(struct AccessorObject* object)
{
    object->flags_0x1ce &= ~1;
}
