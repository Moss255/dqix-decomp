#include <globaldefs.h>
#include "std_library_functions.h"
#include "Model/Main/ModelAttachConfig.h"

// USA: func_02034980
//
// Copies the name onto the allocator. A failed allocation leaves the field
// NULL and is not reported to the caller.
ARM void SetAttachBoneName(ModelAttachConfig* config, SafeAllocator* allocator,
                           const char* name)
{
    config->boneName = (char*)allocator->Allocate(strlen(name) + 1);
    if (!config->boneName)
        return;

    strcpy(config->boneName, name);
}
