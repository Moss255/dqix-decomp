#pragma once

// Thirteen release routines at 0x020c49ec..0x020c4b38. Each tail-calls
// func_020c490c on one halfword of the block at 0x02111224.
//
// Four of them first clear a DISPCNT bit: 0x40000000 and 0x80000000 are the
// BG and OBJ extended-palette enables, cleared on the main engine (0x4000000)
// and the sub (0x4001000) respectively. That pairing suggests these release
// VRAM banks, but nothing here establishes it, so the names carry the
// variable each one touches.

extern "C"
{

// USA: func_020c49ec
void Release_02111226();

// USA: func_020c4a00
void Release_02111228();

// USA: func_020c4a14
void Release_02111232();

// USA: func_020c4a38
void Release_02111234();

// USA: func_020c4a5c
void Release_0211122c();

// USA: func_020c4a70
void Release_0211122e();

// USA: func_020c4a84
void Release_02111230();

// USA: func_020c4a98
void Release_0211122a();

// USA: func_020c4aac
void Release_02111224();

// USA: func_020c4ac0
void Release_02111236();

// USA: func_020c4ad4
void Release_02111238();

// USA: func_020c4ae8
void Release_0211123a();

// USA: func_020c4b10
void Release_0211123c();

}
