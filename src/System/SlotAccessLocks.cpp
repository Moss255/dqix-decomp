#include <globaldefs.h>
#include "System/SlotAccess.h"

#define REG_EXMEMCNT 0x4000204

#define SHARED_GBA_LOCK  ((void*)0x27fffe8)
#define SHARED_CARD_LOCK ((void*)0x27fffe0)

extern "C"
{
    void func_020c6ea4(void* context, void* lock, void (*apply)(), int flag);
    void func_020c6f28(void* context, void* lock, void (*apply)(), int flag);
    void func_020c6e94(void* context, void* lock, void (*apply)());
    void func_020c6f18(void* context, void* lock, void (*apply)());
}

// USA: func_020c6fc0
ARM void LockGbaSlotForArm9(void* context)
{
    func_020c6f28(context, SHARED_GBA_LOCK, GiveGbaSlotToArm9, 1);
}

// USA: func_020c6fe0
ARM void GiveGbaSlotToArm9()
{
    *(volatile unsigned short*)REG_EXMEMCNT &= ~0x80;
}

// USA: func_020c6ff8
ARM void GiveGbaSlotToArm7()
{
    *(volatile unsigned short*)REG_EXMEMCNT |= 0x80;
}

// USA: func_020c7010
ARM void LockCardSlotForArm9(void* context)
{
    func_020c6e94(context, SHARED_CARD_LOCK, GiveCardSlotToArm9);
}

// USA: func_020c702c
ARM void LockCardSlotForArm7(void* context)
{
    func_020c6f18(context, SHARED_CARD_LOCK, GiveCardSlotToArm7);
}

// USA: func_020c7048
ARM void GiveCardSlotToArm9()
{
    *(volatile unsigned short*)REG_EXMEMCNT &= ~0x800;
}

// USA: func_020c7060
ARM void GiveCardSlotToArm7()
{
    *(volatile unsigned short*)REG_EXMEMCNT |= 0x800;
}

// USA: func_020c7078
ARM unsigned short GetHalfword_0x4(void* object)
{
    return ((unsigned short*)object)[2];
}
