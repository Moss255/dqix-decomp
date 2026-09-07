#pragma once

// The object behind the accessors at 0x02037a88..0x02037af8. Reached from ARM9
// main and from overlays 0 and 17; what it represents is not established, so it
// is named for the block that establishes its fields rather than for a guess.
//
// The same convention as AccessorObject in this directory - when a cluster of
// accessors pins down a struct but nothing says what the struct is, the name
// carries the address so it stays unambiguous against the next one.
// Eight bytes copied as four halfwords by CopyHalfword4.
struct Halfword4
{
    unsigned short values[4];
};

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
    /* 0xa8 */ char unknown_0xa8[0xc4 - 0xa8];
    /* 0xc4 */ unsigned short field15_0xc4 : 15;
               unsigned short unknown_0xc4_hi : 1;
    /* 0xc6 */ char unknown_0xc6[0xe0 - 0xc6];
    /* 0xe0 */ unsigned char unknown_bit0 : 1;
               unsigned char flag_bit1 : 1;
               unsigned char flag_bit2 : 1;
               unsigned char unknown_bits3 : 3;
               unsigned char flag_bit6 : 1;
               unsigned char flag_bit7 : 1;
    /* 0xe1 */ char unknown_0xe1[0xe4 - 0xe1];
    /* 0xe4 */ int value_0xe4;
    /* 0xe8 */ char unknown_0xe8[0x114 - 0xe8];
    /* 0x114 */ struct Halfword4 pair_0x114;
    /* 0x11c */ struct Halfword4 pair_0x11c;
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

// USA: func_02033f2c
void ClearBits6And7(struct Object_02037A88* object);
// USA: func_02033f44 - the field's address when bit 6 is set, else null
int* GetValue_0xe4IfBit6(struct Object_02037A88* object);
// USA: func_02033f5c
unsigned char GetBit6(struct Object_02037A88* object);
// USA: func_02033f6c / func_02033fa0
void SetPair_0x114(struct Object_02037A88* object, const struct Halfword4* src);
struct Halfword4* GetPair_0x114(struct Object_02037A88* object);
// USA: func_02033f7c
void CopyHalfword4(struct Halfword4* dst, const struct Halfword4* src);
// USA: func_02033fa8 / func_02033fc4 - the setter also raises bit 7
void SetPair_0x11c(struct Object_02037A88* object, const struct Halfword4* src);
struct Halfword4* GetPair_0x11c(struct Object_02037A88* object);
// USA: func_02033fcc / func_02033fdc
void SetBit2(struct Object_02037A88* object);
void ClearBit2(struct Object_02037A88* object);
// USA: func_02033fec / func_0203400c - also toggles flag 0x40000 in flags_0x6c
void SetBit1AndFlag(struct Object_02037A88* object);
void ClearBit1AndFlag(struct Object_02037A88* object);
// USA: func_0203402c
bool HasField15_0xc4(struct Object_02037A88* object);

}
