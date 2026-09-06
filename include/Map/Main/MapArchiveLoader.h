#pragma once

#include "Grotto/Main/ActiveGrottoClass.h"

// The context the map loader threads through the archive functions. Only the
// fields the decompiled code touches are named; the rest is carried as opaque
// bytes at its observed offset.
// One record out of the map table func_02099950 indexes. Its map code - the
// archive stem, per maplist9.bin - sits at +5. The bitfields at +2 and +0xc are
// read as bitfields by the code, not masked, so the widths are from the shifts.
struct MapListRecord
{
    /* 0x00 */ unsigned short zoneID;
    /* 0x02 */ unsigned short unknown_0x02 : 15;
    /* 0x02 */ unsigned short unknown_0x02_hi : 1;
    /* 0x04 */ char unknown_0x04;
    /* 0x05 */ char code[0x7];
    /* 0x0c */ unsigned char unknown_0x0c : 4;
    /* 0x0c */ unsigned char unknown_0x0c_bit4 : 1;
};

// The maplist9.bin entry, as the context holds it. func_0201383c defaults the
// fields below before the load; the parser fills the rest.
struct MapListEntry
{
    // Three string buffers. func_0201383c empties each by writing a NUL to
    // byte 0; the tag 0x67 handler strcpy's the map code into the first. The
    // lengths are from the spacing between them, not from a bounds check.
    /* 0x00 */ char code[0xa];
    /* 0x0a */ char unknown_0x0a[0x10];
    /* 0x1a */ char unknown_0x1a[0x10];
    /* 0x2a */ short unknown_0x2a;
    /* 0x2c */ short unknown_0x2c;
    /* 0x2e */ char unknown_0x2e[0x2];
    /* 0x30 */ int unknown_0x30;
    /* 0x34 */ short unknown_0x34;
    /* 0x36 */ char unknown_0x36[0x2];
    /* 0x38 */ int unknown_0x38;
    /* 0x3c */ int unknown_0x3c;
};

// Twelve bytes, copied three words at a time by CopyMapVec3. INFERRED as a
// position from where it is copied to and from - not established.
struct MapVec3
{
    int x;
    int y;
    int z;
};

// One entry of the map's resource manifest, as the loader holds it in memory.
// The .amdj walker matches each archive member against these names with strstr
// and builds a MapObjectNode for every hit.
struct MapResource
{
    /* 0x00 */ int unknown_0x00;
    /* 0x04 */ MapVec3 position;
    /* 0x10 */ char name[1]; // NUL-terminated; the length is not established
};

// A placed object. Built one per matched resource and pushed onto the list the
// context holds at +0x41c, so the list ends up in reverse match order.
struct MapObjectNode
{
    /* 0x00 */ int unknown_0x00;
    /* 0x04 */ char unknown_0x04[0x48 - 0x04];
    /* 0x48 */ MapVec3 position;
    /* 0x54 */ MapObjectNode* next;
};

struct MapLoadContext
{
    /* 0x0000 */ unsigned short zoneID;
    // func_0201383c copies the outgoing zone here before writing the new one.
    /* 0x0002 */ unsigned short previousZoneID;
    // The low 15 bits of the map record's halfword at +2.
    /* 0x0004 */ unsigned short unknown_0x04;
    /* 0x0006 */ char unknown_0x06[0x2];
    // The record func_02099950 returns for this zone. Its map code - the
    // archive stem - begins 5 bytes in. What the first 5 bytes are is not
    // established.
    /* 0x0008 */ MapListRecord* record;
    // Destination for the maplist9.bin entry. func_02013fb4 hands the address
    // of this field to the parser; func_0201383c clears bytes across it before
    // the load. Its layout is not established - see MapArchive.h for what the
    // file holds.
    /* 0x000c */ MapListEntry mapEntry;
    /* 0x004c */ SafeAllocator* allocator;
    /* 0x0050 */ void* unknown_0x50;
    /* 0x0054 */ char unknown_0x54[0x68 - 0x54];
    /* 0x0068 */ SafeAllocator* activeAllocator;
    /* 0x006c */ char unknown_0x6c[0xf4 - 0x6c];
    /* 0x00f4 */ char unknown_0xf4[0x10c - 0xf4];
    /* 0x010c */ char unknown_0x10c[0x418 - 0x10c];
    /* 0x0418 */ int unknown_0x418;
    /* 0x041c */ MapObjectNode* objectList;
    /* 0x0420 */ void* pFloorEntries;
    /* 0x0424 */ int unknown_0x424;
    /* 0x0428 */ char unknown_0x428[0x4];
    /* 0x042c */ unsigned char unknown_0x42c;
    /* 0x042d */ char unknown_0x42d[0x3];
    // Five file handles, all set to -1 by func_0201383c. A handle is a signed
    // int and -1 means "not loading" - func_02013fb4 tests it with a signed
    // comparison. Two slots are identified:
    //     [0]   data/map/maplist9.bin, opened at the end of func_0201383c
    //     [2]   the .ambl archive, opened by LoadAmblArchive
    /* 0x0430 */ int archives[5];
    /* 0x0444 */ char unknown_0x444[0x474 - 0x444];
    /* 0x0474 */ short unknown_0x474;
    /* 0x0476 */ unsigned char unknown_0x476;
    /* 0x0477 */ unsigned char unknown_0x477;
    /* 0x0478 */ int unknown_0x478;
    /* 0x047c */ int unknown_0x47c;
    /* 0x0480 */ char unknown_0x480[0x82c - 0x480];
    /* 0x082c */ int unknown_0x82c;
    /* 0x0830 */ char unknown_0x830[0x4];
    /* 0x0834 */ unsigned char unknown_0x834;
    /* 0x0835 */ char unknown_0x835[0x3];
    /* 0x0838 */ int unknown_0x838;
    /* 0x083c */ int unknown_0x83c;
    /* 0x0840 */ char unknown_0x840[0x23b8 - 0x840];
    /* 0x23b8 */ unsigned char unknown_0x23b8;
    /* 0x23b9 */ char unknown_0x23b9;
    /* 0x23ba */ signed char floor;
    /* 0x23bb */ signed char unknown_0x23bb;
    /* 0x23bc */ char unknown_0x23bc[0x4];
    /* 0x23c0 */ char unknown_0x23c0[0xc];
    /* 0x23cc */ short unknown_0x23cc;
    /* 0x23ce */ char unknown_0x23ce[0x23ec - 0x23ce];
    /* 0x23ec */ ActiveGrottoClass activeGrotto;
    /* 0x2664 */ char unknown_0x2664[0x2724 - 0x2664];
    /* 0x2724 */ char unknown_0x2724[0x2754 - 0x2724];
    /* 0x2754 */ char unknown_0x2754[0x2820 - 0x2754];
    /* 0x2820 */ unsigned char unknown_0x2820;
};

extern "C"
{

// USA: func_0201403c
void LoadAmblArchive(MapLoadContext* context);

// USA: func_02013fb4
bool PollMapListLoad(MapLoadContext* context);

// USA: func_020145a8
void LoadAmdjArchive(MapLoadContext* context);

// USA: func_02014390
int LoadBmblMember(MapLoadContext* context, void* member, void* unused);

// USA: func_020143d8
int LoadBposMember(MapLoadContext* context, void* member, void* unused);

// USA: func_02013b54
void CopyMapVec3(MapVec3* dst, const MapVec3* src);

// USA: func_02014d18
void BuildArcMemberPath(const char* stem, const char* extension, char* path);

// USA: func_0201498c
int AccumulateResourceSizes(MapLoadContext* context);

// USA: func_02014900
int AddMapObject(MapLoadContext* context, void* member, void* unused,
                 const MapResource* resource);


}
