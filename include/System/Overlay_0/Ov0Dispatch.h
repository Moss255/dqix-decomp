#pragma once

// Thirty-five dispatch wrappers in overlay 0, contiguous at
// 0x02181d4c..0x021820bc, plus one that just reports a constant.
//
// Each takes three arguments, discards the first - which is what a C++ member
// function does with an unused this - and tail-calls one of three targets
// with a fixed pair of constants. The names carry those constants.

extern "C"
{

// USA: func_ov000_02181d4c
void DispatchA_1_0(void* self, int b, int c);

// USA: func_ov000_02181d68
void DispatchA_1_1(void* self, int b, int c);

// USA: func_ov000_02181d88
void DispatchA_1_2(void* self, int b, int c);

// USA: func_ov000_02181da4
void DispatchA_1_3(void* self, int b, int c);

// USA: func_ov000_02181dc0
void DispatchA_1_4(void* self, int b, int c);

// USA: func_ov000_02181ddc
void DispatchA_1_5(void* self, int b, int c);

// USA: func_ov000_02181df8
void DispatchA_1_6(void* self, int b, int c);

// USA: func_ov000_02181e14
void DispatchA_1_7(void* self, int b, int c);

// USA: func_ov000_02181e30
void DispatchA_0_0(void* self, int b, int c);

// USA: func_ov000_02181e50
void DispatchA_0_1(void* self, int b, int c);

// USA: func_ov000_02181e6c
void DispatchA_0_2(void* self, int b, int c);

// USA: func_ov000_02181e88
void DispatchA_0_3(void* self, int b, int c);

// USA: func_ov000_02181ea4
void DispatchA_0_4(void* self, int b, int c);

// USA: func_ov000_02181ec0
void DispatchA_0_5(void* self, int b, int c);

// USA: func_ov000_02181edc
void DispatchA_0_6(void* self, int b, int c);

// USA: func_ov000_02181ef8
void DispatchA_0_7(void* self, int b, int c);

// USA: func_ov000_02181f14
void DispatchA_2_0(void* self, int b, int c);

// USA: func_ov000_02181f30
void DispatchA_2_1(void* self, int b, int c);

// USA: func_ov000_02181f4c
void DispatchB_0(void* self, int b, int c);

// USA: func_ov000_02181f60
void DispatchB_1(void* self, int b, int c);

// USA: func_ov000_02181f74
void DispatchB_2(void* self, int b, int c);

// USA: func_ov000_02181f88
void DispatchB_3(void* self, int b, int c);

// USA: func_ov000_02181f9c
void DispatchB_4(void* self, int b, int c);

// USA: func_ov000_02181fb0
void DispatchB_5(void* self, int b, int c);

// USA: func_ov000_02181fc4
void DispatchB_6(void* self, int b, int c);

// USA: func_ov000_02181fd8
void DispatchB_7(void* self, int b, int c);

// USA: func_ov000_02181fec
void DispatchC_0_0(void* self, int b, int c);

// USA: func_ov000_02182004
void DispatchC_1_0(void* self, int b, int c);

// USA: func_ov000_0218201c
void DispatchC_2_0(void* self, int b, int c);

// USA: func_ov000_02182034
void DispatchC_3_0(void* self, int b, int c);

// USA: func_ov000_0218204c
void DispatchC_0_1(void* self, int b, int c);

// USA: func_ov000_02182064
void DispatchC_1_1(void* self, int b, int c);

// USA: func_ov000_0218207c
void DispatchC_2_1(void* self, int b, int c);

// USA: func_ov000_02182094
void DispatchC_3_1(void* self, int b, int c);

// USA: func_ov000_021820ac - writes 200 through the third argument
int ReportConstant200(void* self, int b, int* out);

}
