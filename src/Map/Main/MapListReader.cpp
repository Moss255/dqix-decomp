#include <globaldefs.h>
#include "std_library_functions.h"
#include "Map/Main/MapListReader.h"
#include "Map/Main/MapArchiveLoader.h"

extern "C"
{
    // The tagged-table reader. func_02030634 constructs one over the caller's
    // storage, func_0203066c gives it the handler table to dispatch through,
    // func_02030734 walks a buffer, and func_02030774 tears it down.
    void func_02030634(void* reader);
    void func_0203066c(void* reader, const void* handlers);
    void func_02030734(void* reader, void* data, unsigned int size);
    void func_02030774(void* reader);

    // Pull one value out of a record, by type. The string accessor returns
    // NULL for an unset field.
    int func_02030b0c(const TaggedValue* value);
    float func_02030b44(const TaggedValue* value);
    char* func_02030b7c(const TaggedValue* value);

    // Applied to the first of the three fixed-point values before it is
    // narrowed to 16 bits. Not established - an angle normalisation would fit.
    int func_02030f30(int value);

    // The zone the walk is looking for, and the entry it writes into. Set for
    // the duration of the walk and reset to -1 / NULL afterwards.
    extern int data_020ef2bc;
    extern MapListEntry* data_020fdc14[];

    // The handler table for maplist9.bin, at data_020ef2c0. Four {tag, handler}
    // pairs terminated by a zero pair:
    //     0x66 -> OnMapListCount    0x67 -> OnMapListEntry
    //     0x68 -> OnMapListTag68    0x69 -> OnMapListTag69
    // Two more tables follow it in .data, for other files.
    extern const char data_020ef2c0[];
}

// A record is 22 of these; the accessors above take the address of one. What
// the eight bytes hold is not established - a type tag beside the value fits
// the three accessors, but has not been confirmed.

// USA: func_0201c5f4 - tag 0x66, the number of entries. Ignored.
ARM int OnMapListCount(const TaggedValue* values)
{
    return 1;
}

// USA: func_0201c5fc - tag 0x67, called once per map entry.
//
// Slot 0 is the zone ID and is the filter: every entry for another zone is
// skipped. The 16 slots read below are of the 22 an entry carries, so six are
// never touched here. Ten are read and discarded - the accessor is called for
// its side effect on the reader, or the result is simply unused.
ARM int OnMapListEntry(const TaggedValue* values)
{
    if (data_020ef2bc != func_02030b0c(&values[0]))
        return 1;

    func_02030b0c(&values[1]);
    func_02030b7c(&values[2]);
    func_02030b0c(&values[3]);
    func_02030b7c(&values[4]);
    func_02030b7c(&values[5]);
    func_02030b0c(&values[6]);
    func_02030b7c(&values[7]);
    func_02030b0c(&values[8]);
    func_02030b0c(&values[9]);
    func_02030b0c(&values[10]);

    char* code = func_02030b7c(&values[11]);
    if (code)
        strcpy(data_020fdc14[1]->code, code);

    func_02030b0c(&values[12]);

    // Three floats, each scaled by 4096 and truncated - the DS's 20.12 fixed
    // point. The first is narrowed to 16 bits after func_02030f30.
    data_020fdc14[1]->unknown_0x34 =
        func_02030f30((int)(4096.0f * func_02030b44(&values[13])));
    data_020fdc14[1]->unknown_0x38 = (int)(4096.0f * func_02030b44(&values[14]));
    data_020fdc14[1]->unknown_0x3c = (int)(4096.0f * func_02030b44(&values[15]));

    return 1;
}

// USA: func_0201c714 - tag 0x68. Ignored.
ARM int OnMapListTag68(const TaggedValue* values)
{
    return 1;
}

// USA: func_0201c71c - tag 0x69. Ignored.
ARM int OnMapListTag69(const TaggedValue* values)
{
    return 1;
}

// USA: func_0201c724
ARM void ReadMapListEntry(int zoneID, MapListEntry* entry, void* data, unsigned int size)
{
    char reader[0x430];

    data_020fdc14[1] = entry;
    data_020ef2bc = zoneID;

    func_02030634(reader);
    func_0203066c(reader, data_020ef2c0);
    func_02030734(reader, data, size);
    func_02030774(reader);

    data_020fdc14[1] = NULL;
    data_020ef2bc = -1;
}
