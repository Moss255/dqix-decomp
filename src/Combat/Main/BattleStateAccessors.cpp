#include <globaldefs.h>
#include "std_library_functions.h"
#include "Combat/Main/BattleStateAccessors.h"

extern "C"
{
    struct BattleOwner* func_020108f0();
    struct BattleOwner* func_0208e0a8();
}

// USA: func_02011ff0
ARM unsigned char GetNibble_0x56b(struct BattleStruct* battle)
{
    struct BattleOwner* owner = func_020108f0();
    if (owner)
        return owner->value_0x56b;

    return 0;
}

// USA: func_02012010
ARM void SetValue_0x7f6c(struct BattleStruct* battle, int value)
{
    battle->value_0x7f6c = value;
}

// USA: func_0201201c
ARM int GetValue_0x7f6c(struct BattleStruct* battle)
{
    return battle->value_0x7f6c;
}

// USA: func_02012028
ARM void SetValue_0x7f70(struct BattleStruct* battle, unsigned char value)
{
    battle->value_0x7f70 = value;
}

// USA: func_02012034
ARM unsigned char GetValue_0x7f70(struct BattleStruct* battle)
{
    return battle->value_0x7f70;
}

// USA: func_02012040
ARM void SetFlag_0x63d5(struct BattleStruct* battle)
{
    battle->value_0x63d5 = 1;
}

// USA: func_02012050
ARM void ClearFlag_0x63d5(struct BattleStruct* battle)
{
    battle->value_0x63d5 = 0;
}

// USA: func_02012060
ARM unsigned char GetFlag_0x63d5(struct BattleStruct* battle)
{
    return battle->value_0x63d5;
}

// USA: func_0201206c
ARM void SetValue_0x71f8(struct BattleStruct* battle, int value)
{
    battle->value_0x71f8 = value;
}

// USA: func_02012078
ARM int GetValue_0x71f8(struct BattleStruct* battle)
{
    return battle->value_0x71f8;
}

// USA: func_02012084
ARM void ClearSlots_0x74de(struct BattleStruct* battle)
{
    memset(battle->slots_0x74de, 0, sizeof(battle->slots_0x74de));
}

// USA: func_020120a0
ARM void* GetSlot_0x74de(struct BattleStruct* battle, unsigned int index)
{
    if (index < 4)
        return battle->slots_0x74de[index];

    return NULL;
}

// USA: func_020120b8
ARM unsigned int* GetFlagged_0x5cdc(struct BattleStruct* battle, unsigned int index)
{
    unsigned int* entries = battle->flagged_0x5cdc;
    unsigned int* entry = &entries[index];

    if ((entries[index] >> 31) == 0)
        entry = NULL;

    return entry;
}

// USA: func_020120d4
ARM void SetValue_0x5cda(struct BattleStruct* battle, unsigned char value)
{
    battle->value_0x5cda = value;
    func_0208e0a8()->unknown_0x00[0xa] = 0;
}
