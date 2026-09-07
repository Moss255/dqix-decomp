#include <globaldefs.h>
#include "Combat/Main/CombatantStatus2.h"

// USA: func_020890a4
ARM void ClearState_0x40(struct CombatantStruct* combatant)
{
    combatant->stateFlags &= ~0x40;
    combatant->statusDurations[0x1b] = 0;
    combatant->statusCounters[0x1b] = 0;
}

// USA: func_020890c0
ARM bool CanApplyState_0x200(struct CombatantStruct* combatant)
{
    return (combatant->statusFlags & 1) == 0;
}

// USA: func_020890d4
ARM void ApplyState_0x200(struct CombatantStruct* combatant)
{
    combatant->statusDurations[0x19] = 5;
    combatant->statusCounters[0x19] = 0;
    combatant->stateFlags |= 0x200;
}

// USA: func_020890f4
ARM void ClearState_0x200(struct CombatantStruct* combatant)
{
    combatant->stateFlags &= ~0x200;
    combatant->statusDurations[0x19] = 0;
    combatant->statusCounters[0x19] = 0;
}

// USA: func_02089110
ARM bool CanApplyState_0x400(struct CombatantStruct* combatant)
{
    return (combatant->statusFlags & 1) == 0;
}

// USA: func_02089124
ARM void ApplyState_0x400(struct CombatantStruct* combatant)
{
    combatant->statusDurations[0x1a] = 5;
    combatant->statusCounters[0x1a] = 0;
    combatant->stateFlags |= 0x400;
}

// USA: func_02089144
ARM void ClearState_0x400(struct CombatantStruct* combatant)
{
    combatant->stateFlags &= ~0x400;
    combatant->statusDurations[0x1a] = 0;
    combatant->statusCounters[0x1a] = 0;
}

// USA: func_02089160
ARM bool CanApplyState_0x800(struct CombatantStruct* combatant)
{
    return (combatant->statusFlags & 1) == 0;
}

// USA: func_02089174
ARM void ApplyState_0x800(struct CombatantStruct* combatant)
{
    combatant->statusDurations[0x1d] = 3;
    combatant->statusCounters[0x1d] = 0;
    combatant->stateFlags |= 0x800;
}

// USA: func_02089194
ARM void ClearState_0x800(struct CombatantStruct* combatant)
{
    combatant->stateFlags &= ~0x800;
    combatant->statusDurations[0x1d] = 0;
    combatant->statusCounters[0x1d] = 0;
}
