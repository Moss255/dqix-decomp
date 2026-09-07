#pragma once

// Twenty-eight forwarding thunks and four short sequences, contiguous at
// 0x020bba38..0x020bbc38.
//
// A thunk is one tail call passing its arguments through untouched, so it
// compiles to ldr ip, =target / bx ip and its arity is the target's. The
// three-argument ones reach a family at 0x020c5xxx that all open by saving
// r0, r1 and r2; the rest take one.
//
// Four targets are reached by two thunks each: func_020c5c58, func_020c5d18,
// func_020c5cb8 and func_020c5d78.
//
// Each sequence saves its three arguments, calls a no-argument routine that
// would clobber them, restores them for the middle call, then calls another
// no-argument routine.

extern "C"
{

// USA: func_020bba38 -> func_020c5dd8
void Forward_020bba38(void* a, void* b, void* c);

// USA: func_020bba44 -> func_020c5e98
void Forward_020bba44(void* a, void* b, void* c);

// USA: func_020bba50 -> func_020c5f58
void Forward_020bba50(void* a, void* b, void* c);

// USA: func_020bba5c -> func_020c6018
void Forward_020bba5c(void* a, void* b, void* c);

// USA: func_020bba68 -> func_020c5ad8
void Forward_020bba68(void* a, void* b, void* c);

// USA: func_020bba74 -> func_020c5b98
void Forward_020bba74(void* a, void* b, void* c);

// USA: func_020bba80 -> func_020c5c58
void Forward_020bba80(void* a, void* b, void* c);

// USA: func_020bba8c -> func_020c5d18
void Forward_020bba8c(void* a, void* b, void* c);

// USA: func_020bba98 -> func_020c5c58
void Forward_020bba98(void* a, void* b, void* c);

// USA: func_020bbaa4 -> func_020c5d18
void Forward_020bbaa4(void* a, void* b, void* c);

// USA: func_020bbab0 -> func_020c58cc
void Forward_020bbab0(void* a);

// USA: func_020bbabc -> func_020c5820
void Forward_020bbabc(void* a);

// USA: func_020bbac8
void Sequence_020bbac8(void* a, void* b, void* c);

// USA: func_020bbaf4
void Sequence_020bbaf4(void* a, void* b, void* c);

// USA: func_020bbb20 -> func_020c597c
void Forward_020bbb20(void* a);

// USA: func_020bbb2c -> func_020c5a28
void Forward_020bbb2c(void* a);

// USA: func_020bbb38 -> func_020c5e38
void Forward_020bbb38(void* a, void* b, void* c);

// USA: func_020bbb44 -> func_020c5ef8
void Forward_020bbb44(void* a, void* b, void* c);

// USA: func_020bbb50 -> func_020c5fb8
void Forward_020bbb50(void* a, void* b, void* c);

// USA: func_020bbb5c -> func_020c6078
void Forward_020bbb5c(void* a, void* b, void* c);

// USA: func_020bbb68 -> func_020c5b38
void Forward_020bbb68(void* a, void* b, void* c);

// USA: func_020bbb74 -> func_020c5bf8
void Forward_020bbb74(void* a, void* b, void* c);

// USA: func_020bbb80 -> func_020c5cb8
void Forward_020bbb80(void* a, void* b, void* c);

// USA: func_020bbb8c -> func_020c5d78
void Forward_020bbb8c(void* a, void* b, void* c);

// USA: func_020bbb98 -> func_020c5cb8
void Forward_020bbb98(void* a, void* b, void* c);

// USA: func_020bbba4 -> func_020c5d78
void Forward_020bbba4(void* a, void* b, void* c);

// USA: func_020bbbb0 -> func_020c5924
void Forward_020bbbb0(void* a);

// USA: func_020bbbbc -> func_020c5874
void Forward_020bbbbc(void* a);

// USA: func_020bbbc8
void Sequence_020bbbc8(void* a, void* b, void* c);

// USA: func_020bbbf4
void Sequence_020bbbf4(void* a, void* b, void* c);

// USA: func_020bbc20 -> func_020c59d0
void Forward_020bbc20(void* a);

// USA: func_020bbc2c -> func_020c5a80
void Forward_020bbc2c(void* a);

}
