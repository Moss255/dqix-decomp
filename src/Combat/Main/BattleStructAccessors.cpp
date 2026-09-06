#include <globaldefs.h>
#include "Combat/Main/BattleStructAccessors.h"

// USA: func_02011518
ARM int GetRosterId(struct BattleStruct* battle, unsigned int index)
{
    if (index < battle->rosterCount)
        return battle->rosterIds[index];

    return -1;
}

// USA: func_02011538
ARM unsigned char GetRosterCount(struct BattleStruct* battle)
{
    return battle->rosterCount;
}

// USA: func_02011544
ARM void SetFlag_0x5ccc(struct BattleStruct* battle)
{
    battle->flag_0x5ccc = 1;
}

// USA: func_0201155c
ARM void ClearFlag_0x5ccc(struct BattleStruct* battle)
{
    battle->flag_0x5ccc = 0;
}

// USA: func_02011570
ARM int GetFlag_0x5ccc(struct BattleStruct* battle)
{
    return battle->flag_0x5ccc;
}

// USA: func_02011584
ARM void* GetBlock_0x468(struct BattleStruct* battle)
{
    return battle->block_0x468;
}

// USA: func_02011590
ARM bool HasValue_0x63d6(struct BattleStruct* battle)
{
    return battle->value_0x63d6 != 0;
}

// USA: func_020115a8
ARM unsigned char GetValue_0x63d6(struct BattleStruct* battle)
{
    return battle->value_0x63d6;
}

// USA: func_020115b4
ARM void SetValue_0x63d6(struct BattleStruct* battle, unsigned char value)
{
    battle->value_0x63d6 = value;
}

// USA: func_020115c0
ARM void ClearValue_0x63d6(struct BattleStruct* battle)
{
    battle->value_0x63d6 = 0;
}

// USA: func_020115d0
ARM bool HasValue_0x63d8(struct BattleStruct* battle)
{
    return battle->value_0x63d8 != 0;
}

// USA: func_020115e8
ARM unsigned short GetValue_0x63d8(struct BattleStruct* battle)
{
    return battle->value_0x63d8;
}

// USA: func_020115f4
ARM void SetValue_0x63d8(struct BattleStruct* battle, unsigned short value)
{
    battle->value_0x63d8 = value;
}

// USA: func_02011600
ARM void ClearValue_0x63d8(struct BattleStruct* battle)
{
    battle->value_0x63d8 = 0;
}

// USA: func_02011610
ARM bool HasValue_0x63da(struct BattleStruct* battle)
{
    return battle->value_0x63da != 0;
}

// USA: func_02011628
ARM unsigned short GetValue_0x63da(struct BattleStruct* battle)
{
    return battle->value_0x63da;
}

// USA: func_02011634
ARM void ClearValue_0x63da(struct BattleStruct* battle)
{
    battle->value_0x63da = 0;
}

// USA: func_02011644
ARM int GetValue_0x63e0(struct BattleStruct* battle)
{
    return battle->value_0x63e0;
}

// USA: func_02011650
ARM void SetValue_0x63e0(struct BattleStruct* battle, int value)
{
    battle->value_0x63e0 = value;
}
