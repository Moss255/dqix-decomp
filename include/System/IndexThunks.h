#pragma once

// Nine routines at 0x020c6a54..0x020c6aec.
//
// Eight are index thunks: each tail-calls func_020c69cc with a fixed index 0
// to 7. That function scales its argument by 12, so the index selects one
// entry of a table of twelve-byte records.
//
// The ninth clears two words at the start of the DTCM block at 0x027e0060.

extern "C"
{

// USA: func_020c6a54
void SelectIndex0();

// USA: func_020c6a64
void SelectIndex1();

// USA: func_020c6a74
void SelectIndex2();

// USA: func_020c6a84
void SelectIndex3();

// USA: func_020c6a94
void SelectIndex4();

// USA: func_020c6aa4
void SelectIndex5();

// USA: func_020c6ab4
void SelectIndex6();

// USA: func_020c6ac4
void SelectIndex7();

// USA: func_020c6ad4
void ClearDtcmPair();

}
