#include <globaldefs.h>
#include "std_library_functions.h"
#include "System/Object_0204936C.h"

// USA: func_0204936c
ARM bool HasFlag_0x10(struct Object_0204936C* object)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner == NULL)
        return false;

    return (inner->flags_0x20 & 0x10) != 0;
}

// USA: func_02049390
ARM void SetValue_0x1c(struct Object_0204936C* object, unsigned char value)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner != NULL && value != 0xff)
        inner->value_0x1c = value;
}

// USA: func_020493a4
ARM int GetValue_0x1c(struct Object_0204936C* object)
{
    struct Inner_0204936C* inner = object->inner;

    return inner ? inner->value_0x1c : 0xff;
}

// USA: func_020493b8
ARM void SetValue_0x1d(struct Object_0204936C* object, unsigned char value)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner != NULL)
        inner->value_0x1d = value;
}

// USA: func_020493c8
ARM int GetValue_0x1d(struct Object_0204936C* object)
{
    struct Inner_0204936C* inner = object->inner;

    return inner ? inner->value_0x1d : 0xff;
}

// USA: func_020493dc
ARM void SetValue_0x1e(struct Object_0204936C* object, unsigned char value)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner != NULL)
        inner->value_0x1e = value;
}

// USA: func_020493ec
ARM int GetValue_0x1e(struct Object_0204936C* object)
{
    struct Inner_0204936C* inner = object->inner;

    return inner ? inner->value_0x1e : 0xff;
}

// USA: func_02049400
ARM void SetValue_0x1f(struct Object_0204936C* object, unsigned char value)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner != NULL)
        inner->value_0x1f = value;
}

// USA: func_02049410
ARM void SetBuffer(struct Object_0204936C* object, void* src, unsigned int length)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner == NULL)
        return;

    if (length >= 0x10)
        return;

    memcpy(inner->buffer_0x24, src, length);
    object->inner->length_0x34 = length;
}

// USA: func_02049444
ARM int GetBufferLength(struct Object_0204936C* object)
{
    struct Inner_0204936C* inner = object->inner;

    return inner ? inner->length_0x34 : 0;
}

// USA: func_02049458
ARM void SetValue_0x4c(struct Object_0204936C* object, unsigned char value)
{
    struct Inner_0204936C* inner = object->inner;

    if (inner != NULL)
        inner->value_0x4c = value;
}
