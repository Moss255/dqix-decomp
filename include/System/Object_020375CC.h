#pragma once

// The object behind the accessors at 0x020375cc..0x02037640. Its fields do not
// overlap those of Object_02037A88 a kilobyte further on, and the two families
// share no callers, so they are kept separate rather than assumed to be one.

struct ListNode_020375CC
{
    /* 0x00 */ char unknown_0x00[0x28];
    /* 0x28 */ struct ListNode_020375CC* next;
};

struct Object_020375CC
{
    /* 0x00 */ char unknown_0x00[0x6];
    /* 0x06 */ unsigned short value_0x06;
    /* 0x08 */ char unknown_0x08[0xc - 0x8];
    /* 0x0c */ struct ListNode_020375CC* list;
    /* 0x10 */ char unknown_0x10[0x78 - 0x10];
    /* 0x78 */ unsigned short value_0x78;
    /* 0x7a */ unsigned short value_0x7a;
    /* 0x7c */ unsigned short value_0x7c;
    /* 0x7e */ unsigned short value_0x7e;
    /* 0x80 */ unsigned short value_0x80;
};

extern "C"
{

// USA: func_020375cc - the index'th node, or null if the list is shorter
struct ListNode_020375CC* GetNode(struct Object_020375CC* object, int index);

// USA: func_020375f0 / func_020375f8
void SetValue_0x06(struct Object_020375CC* object, unsigned short value);
unsigned short GetValue_0x06(struct Object_020375CC* object);

// USA: func_02037600 / func_02037608
void SetValue_0x78(struct Object_020375CC* object, unsigned short value);
unsigned short GetValue_0x78(struct Object_020375CC* object);

// USA: func_02037610 / func_02037618
void SetValue_0x7a(struct Object_020375CC* object, unsigned short value);
unsigned short GetValue_0x7a(struct Object_020375CC* object);

// USA: func_02037620 - a count of zero also seeds 0x7c and zeroes 0x80
void SetSpan(struct Object_020375CC* object, unsigned short value, unsigned short count);

}
