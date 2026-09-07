#include <globaldefs.h>
#include "System/Object_02055080.h"

// USA: func_02055090
ARM int* GetInnerValue_0x00(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return NULL;

    return inner->value_0x00;
}

// USA: func_020550a8
ARM int GetInnerValue_0x04(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x04;
}

// USA: func_020550c0
ARM int GetInnerValue_0x08(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x08;
}

// USA: func_020550d8
ARM int GetInnerValue_0x0c(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x0c;
}

// USA: func_020550f0
ARM int GetInnerValue_0x10(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x10;
}

// USA: func_02055108
ARM int GetInnerValue_0x14(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x14;
}

// USA: func_02055120
ARM int GetInnerValue_0x18(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x18;
}

// USA: func_02055138
ARM int GetInnerValue_0x1c(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x1c;
}

// USA: func_02055150
ARM int GetInnerValue_0x20(struct Object_02055080* object)
{
    struct Inner_02055080* inner = GetInner(object);

    if (inner == NULL)
        return 0;

    return inner->value_0x20;
}

// USA: func_02055168
ARM int GetInnerTarget_0x00(struct Object_02055080* object)
{
    int* target = GetInnerValue_0x00(object);

    if (target == NULL)
        return 0;

    return *target;
}
