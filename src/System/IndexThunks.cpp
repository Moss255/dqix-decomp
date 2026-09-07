#include <globaldefs.h>
#include "System/IndexThunks.h"

extern "C"
{
    void func_020c69cc(int index);
    extern int data_027e0060[];
}

// USA: func_020c6a54
ARM void SelectIndex0()
{
    func_020c69cc(0);
}

// USA: func_020c6a64
ARM void SelectIndex1()
{
    func_020c69cc(1);
}

// USA: func_020c6a74
ARM void SelectIndex2()
{
    func_020c69cc(2);
}

// USA: func_020c6a84
ARM void SelectIndex3()
{
    func_020c69cc(3);
}

// USA: func_020c6a94
ARM void SelectIndex4()
{
    func_020c69cc(4);
}

// USA: func_020c6aa4
ARM void SelectIndex5()
{
    func_020c69cc(5);
}

// USA: func_020c6ab4
ARM void SelectIndex6()
{
    func_020c69cc(6);
}

// USA: func_020c6ac4
ARM void SelectIndex7()
{
    func_020c69cc(7);
}

// USA: func_020c6ad4
ARM void ClearDtcmPair()
{
    data_027e0060[1] = 0;
    data_027e0060[0] = 0;
}
