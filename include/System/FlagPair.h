#pragma once

// Flag predicates at 0x0201238c..0x0201248c, called from overlay 1.
//
// The object carries two halfword masks side by side. Eight predicates test a
// fixed bit of the first, one takes the bit as an argument, and the last two
// compare the two words against the same bit.

struct FlagPair
{
    /* 0x00 */ unsigned short first;
    /* 0x02 */ unsigned short second;
};

extern "C"
{

// USA: func_0201238c - does nothing
void FlagPairNop();

// USA: func_02012390
bool HasFirst_0x20(struct FlagPair* flags);

// USA: func_020123a4
bool HasFirst_0x10(struct FlagPair* flags);

// USA: func_020123b8
bool HasFirst_0x40(struct FlagPair* flags);

// USA: func_020123cc
bool HasFirst_0x80(struct FlagPair* flags);

// USA: func_020123e0
bool HasFirst_0x1(struct FlagPair* flags);

// USA: func_020123f4
bool HasFirst_0x2(struct FlagPair* flags);

// USA: func_02012408
bool HasFirst_0x400(struct FlagPair* flags);

// USA: func_0201241c
bool HasFirst_0x800(struct FlagPair* flags);

// USA: func_02012430
bool HasFirst(struct FlagPair* flags, unsigned int mask);

// USA: func_02012444 - set in the first word and clear in the second
bool HasFirstOnly(struct FlagPair* flags, unsigned int mask);

// USA: func_02012468 - clear in the first word and set in the second
bool HasSecondOnly(struct FlagPair* flags, unsigned int mask);

}
