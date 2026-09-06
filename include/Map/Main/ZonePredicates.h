#pragma once

// Zone-ID range checks used to classify a zone before its map archive is
// loaded. All three are pure range tests over the same block of IDs.
//
// The grotto block spans 0x9C41..0xA221 (40001..41505 decimal). IsGrottoZone
// covers the whole block; the other two cover disjoint sub-ranges of it:
//
//     0x9C41 .. 0x9CA0   IsGrottoZoneSubrangeA   (96 IDs)
//     0x9CA1 .. 0xA08C   neither                 (1004 IDs)
//     0xA08D .. 0xA221   IsGrottoZoneSubrangeB   (405 IDs)
//
// The map loader (func_0201403c / func_020145a8) branches on A and B to pick
// which archive name to build, so the sub-ranges select a map's file naming:
//
//     A        -> "Z0%dM01.ambl", environ clamped to 1..5
//     B        -> "Z0%dM99.ambl", environ unclamped
//     neither  -> "%s.ambl", named by the map code from maplist9.bin
//
// INFERRED: M01/M99 look like fixed templates rather than authored maps, and
// TreasureMapMetadata already distinguishes a legacy boss map, so B may be the
// legacy boss arenas. Not established - the naming above is what the loader
// provably does, the reason for it is not.

extern "C"
{

// USA: func_0201b588
bool IsGrottoZone(int zoneID);

// USA: func_0201b5b0
bool IsGrottoZoneSubrangeA(int zoneID);

// USA: func_0201b5d8
bool IsGrottoZoneSubrangeB(int zoneID);

}
