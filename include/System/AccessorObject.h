#pragma once

// The object the accessors at 0x02039820..0x020398b4 operate on. It is reached
// from overlays 0, 17 and 26; what it represents is not established, so it is
// named for the block that establishes its fields rather than for a guess.
//
// Note the three signed bytes at 0x1c8: their setters reach the field with a
// plain strb, but their getters need "add r0, #0x100" first, because LDRSB
// takes only an 8-bit offset where STRB takes twelve. That split is what shows
// the reads are signed.
struct AccessorObject
{
    /* 0x000 */ char unknown_0x000[0x1c8];
    /* 0x1c8 */ signed char values_0x1c8[3];
    /* 0x1cb */ char unknown_0x1cb[0x1ce - 0x1cb];
    /* 0x1ce */ unsigned char flags_0x1ce;
    /* 0x1cf */ char unknown_0x1cf[0x252 - 0x1cf];
    /* 0x252 */ unsigned char value_0x252;
    /* 0x253 */ unsigned char value_0x253;
    /* 0x254 */ unsigned char value_0x254;
};

extern "C"
{

// USA: func_02039820 / func_02039828 / func_02039830
unsigned char GetValue_0x252(struct AccessorObject* object);
unsigned char GetValue_0x253(struct AccessorObject* object);
void CopyValue_0x253_to_0x252(struct AccessorObject* object);

// USA: func_0203983c / func_02039850 - the setter coerces to 0 or 1
void SetValue_0x254(struct AccessorObject* object, int value);
unsigned char GetValue_0x254(struct AccessorObject* object);

// USA: func_02039858 / func_02039860
void SetValue_0x1c8(struct AccessorObject* object, signed char value);
signed char GetValue_0x1c8(struct AccessorObject* object);

// USA: func_0203986c / func_02039874
void SetValue_0x1c9(struct AccessorObject* object, signed char value);
signed char GetValue_0x1c9(struct AccessorObject* object);

// USA: func_02039880 / func_02039888
void SetValue_0x1ca(struct AccessorObject* object, signed char value);
signed char GetValue_0x1ca(struct AccessorObject* object);

// USA: func_02039894 / func_020398a4
void SetFlag_0x1ce(struct AccessorObject* object);
void ClearFlag_0x1ce(struct AccessorObject* object);

}
