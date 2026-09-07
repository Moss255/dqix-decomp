#pragma once

// The object behind the accessors at 0x02037a88..0x02037af8. Reached from ARM9
// main and from overlays 0 and 17; what it represents is not established, so it
// is named for the block that establishes its fields rather than for a guess.
//
// The same convention as AccessorObject in this directory - when a cluster of
// accessors pins down a struct but nothing says what the struct is, the name
// carries the address so it stays unambiguous against the next one.
struct Object_02037A88
{
    /* 0x00 */ char unknown_0x00[0x42];
    /* 0x42 */ unsigned char value_0x42;
    /* 0x43 */ char unknown_0x43[0x6c - 0x43];
    /* 0x6c */ unsigned int flags_0x6c;
    /* 0x70 */ char unknown_0x70[0x9e - 0x70];
    /* 0x9e */ unsigned char value_0x9e;
    /* 0x9f */ char unknown_0x9f;
    /* 0xa0 */ short value_0xa0;
    /* 0xa2 */ char unknown_0xa2[0xa4 - 0xa2];
    /* 0xa4 */ int value_0xa4;
};

extern "C"
{

// USA: func_02037a88 / func_02037a94 / func_02037aa4 / func_02037ab8
unsigned int TestFlags_0x6c(struct Object_02037A88* object, unsigned int mask);
void SetFlags_0x6c(struct Object_02037A88* object, unsigned int mask);
void ClearFlags_0x6c(struct Object_02037A88* object, unsigned int mask);
unsigned int GetFlags_0x6c(struct Object_02037A88* object);

// USA: func_02037ac0
void SetValue_0x42(struct Object_02037A88* object, unsigned char value);

// USA: func_02037ac8 / func_02037ad0
void SetValue_0xa4(struct Object_02037A88* object, int value);
int GetValue_0xa4(struct Object_02037A88* object);

// USA: func_02037ad8 / func_02037ae0 - stored as a halfword, read back signed
void SetValue_0xa0(struct Object_02037A88* object, short value);
short GetValue_0xa0(struct Object_02037A88* object);

// USA: func_02037ae8 / func_02037af0
void SetValue_0x9e(struct Object_02037A88* object, unsigned char value);
unsigned char GetValue_0x9e(struct Object_02037A88* object);

}
