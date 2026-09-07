#pragma once

// Background control, at 0x0204a5d4..0x0204a764.
//
// Most of this writes the 2D engines' registers directly. Priority goes into
// the low two bits of BGxCNT (0x04000008.. for the main engine, 0x04001008..
// for the sub); scroll is written as one 32-bit store covering the HOFS/VOFS
// pair, nine bits each.
//
// The two setters at the start take an object instead, and what that object is
// has not been established.
struct BackgroundOwner
{
    /* 0x000 */ char unknown_0x000[0x220];
    /* 0x220 */ int value_0x220;
    /* 0x224 */ char unknown_0x224[0x260 - 0x224];
    /* 0x260 */ int value_0x260;
};

extern "C"
{

// USA: func_0204a5d4 / func_0204a5dc
void SetValue_0x260(struct BackgroundOwner* owner, int value);
void SetValue_0x220(struct BackgroundOwner* owner, int value);

// USA: func_0204a5e4 / func_0204a5f8 - two tables of four words per row
int GetTableEntry_020f01f8(int row, int column);
int GetTableEntry_020f0218(int row, int column);

// USA: func_0204a60c .. func_0204a6d0 - BGxCNT priority, sub engine then main
void SetSubBg3Priority(int priority);
void SetSubBg2Priority(int priority);
void SetSubBg1Priority(int priority);
void SetSubBg0Priority(int priority);
void SetMainBg3Priority(int priority);
void SetMainBg2Priority(int priority);
void SetMainBg1Priority(int priority);
void SetMainBg0Priority(int priority);

// USA: func_0204a6ec / func_0204a714 / func_0204a73c - sub engine scroll
void SetSubBg3Offset(int hofs, int vofs);
void SetSubBg2Offset(int hofs, int vofs);
void SetSubBg1Offset(int hofs, int vofs);

}
