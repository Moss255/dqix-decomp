#pragma once

// Accessors at 0x0204936c..0x02049468, all reached through a pointer the outer
// object holds at 0x13c. Every one checks it: setters do nothing when it is
// null, and getters return a default - 0xff for the byte fields at 0x1c..0x1f
// and 0 for the rest.

struct Inner_0204936C
{
    /* 0x00 */ char unknown_0x00[0x1c];
    /* 0x1c */ unsigned char value_0x1c;
    /* 0x1d */ unsigned char value_0x1d;
    /* 0x1e */ unsigned char value_0x1e;
    /* 0x1f */ unsigned char value_0x1f;
    /* 0x20 */ unsigned int flags_0x20;
    /* 0x24 */ char buffer_0x24[0x34 - 0x24];
    /* 0x34 */ unsigned char length_0x34;
    /* 0x35 */ char unknown_0x35[0x4c - 0x35];
    /* 0x4c */ unsigned char value_0x4c;
};

struct Object_0204936C
{
    /* 0x000 */ char unknown_0x000[0x13c];
    /* 0x13c */ struct Inner_0204936C* inner;
};

extern "C"
{

// USA: func_0204936c
bool HasFlag_0x10(struct Object_0204936C* object);

// USA: func_02049390 / func_020493a4 - the setter also rejects 0xff
void SetValue_0x1c(struct Object_0204936C* object, unsigned char value);
int GetValue_0x1c(struct Object_0204936C* object);

// USA: func_020493b8 / func_020493c8
void SetValue_0x1d(struct Object_0204936C* object, unsigned char value);
int GetValue_0x1d(struct Object_0204936C* object);

// USA: func_020493dc / func_020493ec
void SetValue_0x1e(struct Object_0204936C* object, unsigned char value);
int GetValue_0x1e(struct Object_0204936C* object);

// USA: func_02049400
void SetValue_0x1f(struct Object_0204936C* object, unsigned char value);

// USA: func_02049410 - copies at most 0xf bytes and records the length
void SetBuffer(struct Object_0204936C* object, void* src, unsigned int length);

// USA: func_02049444
int GetBufferLength(struct Object_0204936C* object);

// USA: func_02049458
void SetValue_0x4c(struct Object_0204936C* object, unsigned char value);

}
