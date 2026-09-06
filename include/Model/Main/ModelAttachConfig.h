#pragma once

#include "Memory/SafeAllocator.h"

// The object a model's attach config is parsed into. Only the field the parse
// falls back on is identified.
//
// INFERRED: the field at +0x1c is the name of a joint to attach to. The
// evidence is the fallback - when the parse leaves it empty the reader fills it
// with "waist", which is a rig's root joint by convention. The field is a
// heap-allocated NUL-terminated copy, not a pointer into the parsed bytes.
struct ModelAttachConfig
{
    /* 0x00 */ char unknown_0x00[0x1c];
    /* 0x1c */ char* boneName;
};

extern "C"
{

// USA: func_02034980
void SetAttachBoneName(ModelAttachConfig* config, SafeAllocator* allocator,
                       const char* name);

// USA: func_0203461c
void ReadModelAttachConfig(ModelAttachConfig* config, SafeAllocator* allocator,
                           void* data, unsigned int size);

}
