#pragma once

// The accessors at 0x02055080..0x02055180. Every one of the field readers
// fetches the inner pointer first and returns 0 when it is null, so the whole
// block is null-safe by construction.
//
// What the object represents is not established; it is named for the block
// that establishes it.

struct Inner_02055080
{
    /* 0x00 */ int* value_0x00;
    /* 0x04 */ int value_0x04;
    /* 0x08 */ int value_0x08;
    /* 0x0c */ int value_0x0c;
    /* 0x10 */ int value_0x10;
    /* 0x14 */ int value_0x14;
    /* 0x18 */ int value_0x18;
    /* 0x1c */ int value_0x1c;
    /* 0x20 */ int value_0x20;
};

struct Object_02055080
{
    /* 0x00 */ char unknown_0x00[0x4];
    /* 0x04 */ struct Inner_02055080* inner;
};

extern "C"
{

// USA: func_02055080
struct Inner_02055080* GetInner(struct Object_02055080* object);

// USA: func_02055090
int* GetInnerValue_0x00(struct Object_02055080* object);

// USA: func_020550a8
int GetInnerValue_0x04(struct Object_02055080* object);

// USA: func_020550c0
int GetInnerValue_0x08(struct Object_02055080* object);

// USA: func_020550d8
int GetInnerValue_0x0c(struct Object_02055080* object);

// USA: func_020550f0
int GetInnerValue_0x10(struct Object_02055080* object);

// USA: func_02055108
int GetInnerValue_0x14(struct Object_02055080* object);

// USA: func_02055120
int GetInnerValue_0x18(struct Object_02055080* object);

// USA: func_02055138
int GetInnerValue_0x1c(struct Object_02055080* object);

// USA: func_02055150
int GetInnerValue_0x20(struct Object_02055080* object);

// USA: func_02055168 - dereferences what GetInnerValue_0x00 returns
int GetInnerTarget_0x00(struct Object_02055080* object);

}
