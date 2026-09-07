#pragma once

#include "Combat/Main/BattleList.h"

// The object func_020108f0 hands back. Only the field read through it is known.
struct BattleOwner
{
    /* 0x000 */ char unknown_0x00[0x56b];
    /* 0x56b */ unsigned char value_0x56b : 4;
};

// Fourteen more accessors on BattleStruct, contiguous at
// 0x02011ff0..0x020120f0. Names carry the offset where the meaning is not
// established.

extern "C"
{

// USA: func_02011ff0 - reads through func_020108f0, 0 when it returns null
unsigned char GetNibble_0x56b(struct BattleStruct* battle);

// USA: func_02012010 / func_0201201c
void SetValue_0x7f6c(struct BattleStruct* battle, int value);
int GetValue_0x7f6c(struct BattleStruct* battle);

// USA: func_02012028 / func_02012034
void SetValue_0x7f70(struct BattleStruct* battle, unsigned char value);
unsigned char GetValue_0x7f70(struct BattleStruct* battle);

// USA: func_02012040 / func_02012050 / func_02012060
void SetFlag_0x63d5(struct BattleStruct* battle);
void ClearFlag_0x63d5(struct BattleStruct* battle);
unsigned char GetFlag_0x63d5(struct BattleStruct* battle);

// USA: func_0201206c / func_02012078
void SetValue_0x71f8(struct BattleStruct* battle, int value);
int GetValue_0x71f8(struct BattleStruct* battle);

// USA: func_02012084 / func_020120a0
void ClearSlots_0x74de(struct BattleStruct* battle);
void* GetSlot_0x74de(struct BattleStruct* battle, unsigned int index);

// USA: func_020120b8 - null unless the entry's sign bit is set
unsigned int* GetFlagged_0x5cdc(struct BattleStruct* battle, unsigned int index);

// USA: func_020120d4
void SetValue_0x5cda(struct BattleStruct* battle, unsigned char value);

}
