#pragma once

#include "Combat/Main/BattleList.h"

// A second block of combatant status accessors, at 0x020890a4..0x020891cc.
// Same shape as the ones at 0x02088840: the test reads bit 0 of statusFlags
// as a shared precondition, applying writes a duration and zeroes its
// counter, and clearing zeroes both. These set bits in stateFlags.

extern "C"
{

// USA: func_020890a4 - no apply for this bit appears in this block
void ClearState_0x40(struct CombatantStruct* combatant);

// USA: func_020890c0 / func_020890d4 / func_020890f4
bool CanApplyState_0x200(struct CombatantStruct* combatant);
void ApplyState_0x200(struct CombatantStruct* combatant);
void ClearState_0x200(struct CombatantStruct* combatant);

// USA: func_02089110 / func_02089124 / func_02089144
bool CanApplyState_0x400(struct CombatantStruct* combatant);
void ApplyState_0x400(struct CombatantStruct* combatant);
void ClearState_0x400(struct CombatantStruct* combatant);

// USA: func_02089160 / func_02089174 / func_02089194
bool CanApplyState_0x800(struct CombatantStruct* combatant);
void ApplyState_0x800(struct CombatantStruct* combatant);
void ClearState_0x800(struct CombatantStruct* combatant);

}
