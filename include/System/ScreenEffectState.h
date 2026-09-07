#pragma once

// The object behind the accessors at 0x0203b498..0x0203b5a0.
//
// The two floats are converted to integers and written to MASTER_BRIGHT on the
// two 2D engines - 0x0400006C for the main engine and 0x0400106C for the sub -
// so this carries screen brightness. What the three bit masks at the start
// select is not established; they are only ever set, cleared and tested
// against a caller-supplied mask.
struct ScreenEffectState
{
    /* 0x00 */ unsigned int masks[3];
    /* 0x0c */ float mainBrightness;
    /* 0x10 */ char unknown_0x10[0x18 - 0x10];
    /* 0x18 */ float subBrightness;
};

extern "C"
{

// USA: func_0203b498 / func_0203b4a0 / func_0203b4b0 / func_0203b4c4
unsigned int GetMask0(struct ScreenEffectState* state);
void SetMask0(struct ScreenEffectState* state, unsigned int mask);
void ClearMask0(struct ScreenEffectState* state, unsigned int mask);
unsigned int TestMask0(struct ScreenEffectState* state, unsigned int mask);

// USA: func_0203b4d0 / func_0203b4d8 / func_0203b4e8 / func_0203b4fc
unsigned int GetMask1(struct ScreenEffectState* state);
void SetMask1(struct ScreenEffectState* state, unsigned int mask);
void ClearMask1(struct ScreenEffectState* state, unsigned int mask);
unsigned int TestMask1(struct ScreenEffectState* state, unsigned int mask);

// USA: func_0203b508 / func_0203b510 / func_0203b520 / func_0203b534
unsigned int GetMask2(struct ScreenEffectState* state);
void SetMask2(struct ScreenEffectState* state, unsigned int mask);
void ClearMask2(struct ScreenEffectState* state, unsigned int mask);
unsigned int TestMask2(struct ScreenEffectState* state, unsigned int mask);

// USA: func_0203b540 - pushes both brightnesses to the hardware
void ApplyBrightness(struct ScreenEffectState* state);

// USA: func_0203b57c - 0 selects the main engine, anything else the sub
int GetBrightness(struct ScreenEffectState* state, int engine);

}
