#pragma once

struct MapListEntry;

// One value in a tagged record. The accessors read through its address; what
// the eight bytes hold is not established.
struct TaggedValue
{
    char opaque[0x8];
};

// Reads the entry for one zone out of a loaded data/map/maplist9.bin image.
// See MapArchive.h for what the file holds.
extern "C"
{

// USA: func_0201c5f4
int OnMapListCount(const TaggedValue* values);

// USA: func_0201c5fc
int OnMapListEntry(const TaggedValue* values);

// USA: func_0201c714
int OnMapListTag68(const TaggedValue* values);

// USA: func_0201c71c
int OnMapListTag69(const TaggedValue* values);

// USA: func_0201c724
void ReadMapListEntry(int zoneID, MapListEntry* entry, void* data, unsigned int size);

}
