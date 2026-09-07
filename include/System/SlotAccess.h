#pragma once

// Cartridge and GBA slot access rights, at 0x020c6f94..0x020c7080.
//
// The four leaf routines set or clear a bit of EXMEMCNT (0x04000204): bit 7
// (0x80) is the GBA slot's access rights and bit 11 (0x800) is the DS card
// slot's, each choosing whether the ARM9 or the ARM7 owns the slot.
//
// The rest are tail calls into a lock helper, handing it a word in the shared
// ARM7/ARM9 area (0x027FFFE8 for the GBA slot, 0x027FFFE0 for the card) and
// the leaf routine to run once the lock is held.

extern "C"
{

// USA: func_020c6fe0 / func_020c6ff8 - GBA slot rights
void GiveGbaSlotToArm9();
void GiveGbaSlotToArm7();

// USA: func_020c7048 / func_020c7060 - card slot rights
void GiveCardSlotToArm9();
void GiveCardSlotToArm7();

// USA: func_020c6f94 / func_020c6fb4 / func_020c6fc0
void LockGbaSlotForArm7(void* context);
void LockGbaSlotForArm9(void* context);

// USA: func_020c7010 / func_020c702c
void LockCardSlotForArm9(void* context);
void LockCardSlotForArm7(void* context);

// USA: func_020c7078
unsigned short GetHalfword_0x4(void* object);

}
