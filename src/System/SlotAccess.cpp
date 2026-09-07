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

// USA: func_020c6f94
ARM void LockGbaSlotForArm7(void* context)
{
    func_020c6ea4(context, SHARED_GBA_LOCK, GiveGbaSlotToArm7, 1);
}
