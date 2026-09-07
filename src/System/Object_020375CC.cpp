#include <globaldefs.h>
#include "System/Object_020375CC.h"

// USA: func_020375cc
ARM struct ListNode_020375CC* GetNode(struct Object_020375CC* object, int index)
{
    struct ListNode_020375CC* node = object->list;

    while (node != NULL)
    {
        if (index == 0)
            break;

        node = node->next;
        index--;
    }

    return node;
}

// USA: func_020375f0
ARM void SetValue_0x06(struct Object_020375CC* object, unsigned short value)
{
    object->value_0x06 = value;
}

// USA: func_020375f8
ARM unsigned short GetValue_0x06(struct Object_020375CC* object)
{
    return object->value_0x06;
}

// USA: func_02037600
ARM void SetValue_0x78(struct Object_020375CC* object, unsigned short value)
{
    object->value_0x78 = value;
}

// USA: func_02037608
ARM unsigned short GetValue_0x78(struct Object_020375CC* object)
{
    return object->value_0x78;
}

// USA: func_02037610
ARM void SetValue_0x7a(struct Object_020375CC* object, unsigned short value)
{
    object->value_0x7a = value;
}

// USA: func_02037618
ARM unsigned short GetValue_0x7a(struct Object_020375CC* object)
{
    return object->value_0x7a;
}

// USA: func_02037620
ARM void SetSpan(struct Object_020375CC* object, unsigned short value, unsigned short count)
{
    if (count == 0)
    {
        object->value_0x7c = value;
        object->value_0x7e = value;
        object->value_0x80 = 0;
    }
    else
    {
        object->value_0x7e = value;
        object->value_0x80 = count;
    }
}
