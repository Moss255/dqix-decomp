#pragma once

#include "Memory/SafeAllocator.h"

// The accessors at 0x020466c8..0x0204673c.
//
// func_020466d0 calls SafeAllocator::ResetAllocatorPointer on its argument and
// hands it back, which is what a constructor compiles to, so that one is typed
// as a SafeAllocator. The rest work on a flag word at offset 0 and a value at
// 0x38; whether that is the same object is not established, so it is modelled
// separately.
struct Object_020466C8
{
    /* 0x00 */ unsigned int flags;
    /* 0x04 */ char unknown_0x04[0x38 - 0x4];
    /* 0x38 */ int value_0x38;
};

extern "C"
{

// USA: func_020466c8
void SetValue_0x38(struct Object_020466C8* object, int value);

// USA: func_020466d0
SafeAllocator* ConstructAllocator(SafeAllocator* allocator);

// USA: func_020466e4 / func_020466f4 / func_02046708 / func_0204671c
void SetFlags(struct Object_020466C8* object, unsigned int mask);
void ClearFlags(struct Object_020466C8* object, unsigned int mask);
bool TestFlags(struct Object_020466C8* object, unsigned int mask);
unsigned int GetFlags(struct Object_020466C8* object);

// USA: func_02046724 / func_02046730 - two symbols, identical bodies
void ClearAllFlags(struct Object_020466C8* object);
void ClearAllFlags2(struct Object_020466C8* object);

}
