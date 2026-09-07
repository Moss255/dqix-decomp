#include <globaldefs.h>
#include "System/Object_02055080.h"

// USA: func_02055080
ARM struct Inner_02055080* GetInner(struct Object_02055080* object)
{
    return object->inner ? object->inner : NULL;
}
