#pragma once

// Ten halfword readers at 0x020c4b38..0x020c4bd8, all indexing the same block
// at 0x02111224 - the block the release routines in VramRelease.cpp hand to
// func_020c490c one entry at a time.
//
// Note the two views of the same memory: those routines reference each entry
// as its own symbol, while these load the base and offset into it. The names
// here carry the byte offset.

extern "C"
{

// USA: func_020c4b38
unsigned short GetSlot_0x02();

// USA: func_020c4b48
unsigned short GetSlot_0x04();

// USA: func_020c4b58
unsigned short GetSlot_0x0e();

// USA: func_020c4b68
unsigned short GetSlot_0x10();

// USA: func_020c4b78
unsigned short GetSlot_0x08();

// USA: func_020c4b88
unsigned short GetSlot_0x0a();

// USA: func_020c4b98
unsigned short GetSlot_0x12();

// USA: func_020c4ba8
unsigned short GetSlot_0x14();

// USA: func_020c4bb8
unsigned short GetSlot_0x16();

// USA: func_020c4bc8
unsigned short GetSlot_0x18();

}
