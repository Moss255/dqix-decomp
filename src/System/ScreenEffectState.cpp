#include <globaldefs.h>
#include "System/ScreenEffectState.h"

#define REG_MASTER_BRIGHT_MAIN 0x400006c
#define REG_MASTER_BRIGHT_SUB  0x400106c

extern "C"
{
    void func_020c39a0(int reg, int value);
}

// USA: func_0203b498
ARM unsigned int GetMask0(struct ScreenEffectState* state)
{
    return state->masks[0];
}

// USA: func_0203b4a0
ARM void SetMask0(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[0] |= mask;
}

// USA: func_0203b4b0
ARM void ClearMask0(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[0] &= ~mask;
}

// USA: func_0203b4c4
ARM unsigned int TestMask0(struct ScreenEffectState* state, unsigned int mask)
{
    return state->masks[0] & mask;
}

// USA: func_0203b4d0
ARM unsigned int GetMask1(struct ScreenEffectState* state)
{
    return state->masks[1];
}

// USA: func_0203b4d8
ARM void SetMask1(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[1] |= mask;
}

// USA: func_0203b4e8
ARM void ClearMask1(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[1] &= ~mask;
}

// USA: func_0203b4fc
ARM unsigned int TestMask1(struct ScreenEffectState* state, unsigned int mask)
{
    return state->masks[1] & mask;
}

// USA: func_0203b508
ARM unsigned int GetMask2(struct ScreenEffectState* state)
{
    return state->masks[2];
}

// USA: func_0203b510
ARM void SetMask2(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[2] |= mask;
}

// USA: func_0203b520
ARM void ClearMask2(struct ScreenEffectState* state, unsigned int mask)
{
    state->masks[2] &= ~mask;
}

// USA: func_0203b534
ARM unsigned int TestMask2(struct ScreenEffectState* state, unsigned int mask)
{
    return state->masks[2] & mask;
}

// USA: func_0203b540
ARM void ApplyBrightness(struct ScreenEffectState* state)
{
    func_020c39a0(REG_MASTER_BRIGHT_MAIN, (int)state->mainBrightness);
    func_020c39a0(REG_MASTER_BRIGHT_SUB, (int)state->subBrightness);
}

// USA: func_0203b57c
ARM int GetBrightness(struct ScreenEffectState* state, int engine)
{
    if (engine == 0)
        return (int)state->mainBrightness;

    return (int)state->subBrightness;
}
