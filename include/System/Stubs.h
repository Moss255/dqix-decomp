#pragma once

// Nine stubs at 0x02094b2c..0x02094b5c: six that do nothing and three that
// return a constant. None is referenced from a table, so they are called
// directly rather than being vtable slots. ReturnOne_02094b4c has 57 callers;
// the rest have one each.
//
// Nothing says what any of them stands in for, so the names carry the address.

extern "C"
{

// USA: func_02094b2c
void Nop_02094b2c();

// USA: func_02094b30
void Nop_02094b30();

// USA: func_02094b34
void Nop_02094b34();

// USA: func_02094b38
void Nop_02094b38();

// USA: func_02094b3c
void Nop_02094b3c();

// USA: func_02094b40
void Nop_02094b40();

// USA: func_02094b44
int ReturnZero_02094b44();

// USA: func_02094b4c
int ReturnOne_02094b4c();

// USA: func_02094b54
int ReturnZero_02094b54();

}
