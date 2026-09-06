#include <globaldefs.h>
#include "Model/Main/ModelAttachConfig.h"

extern "C"
{
    // The same tagged-table reader the map list uses - constructed over the
    // caller's storage, pointed at a handler table, walked, torn down.
    void func_02030634(void* reader);
    void func_0203066c(void* reader, const void* handlers);
    void func_02030734(void* reader, void* data, unsigned int size);
    void func_02030774(void* reader);

    // The handler table for this file, at data_020efa48. Ten {tag, handler}
    // pairs terminated by a zero pair:
    //     0x64 0x65 0x66 0x6a 0x6b 0x6c 0x6d 0x6e 0x6f 0x71
    extern const char data_020efa48[];

    // Where the walk finds its destination and allocator. Set for the duration
    // of the walk and cleared afterwards, exactly as the map list reader does.
    extern void* data_02104b10[];

    extern const char data_020efaa0[]; // "waist"
}

// USA: func_0203461c
//
// Parses a model's attach config. If the file did not name a joint, the
// fallback names it "waist".
ARM void ReadModelAttachConfig(ModelAttachConfig* config, SafeAllocator* allocator,
                               void* data, unsigned int size)
{
    char reader[0x430];

    if (size == 0 || data == NULL)
        return;

    data_02104b10[1] = config;
    data_02104b10[0] = allocator;

    func_02030634(reader);
    func_0203066c(reader, data_020efa48);
    func_02030734(reader, data, size);
    func_02030774(reader);

    if (((ModelAttachConfig*)data_02104b10[1])->boneName == NULL)
        SetAttachBoneName((ModelAttachConfig*)data_02104b10[1], allocator, data_020efaa0);

    data_02104b10[1] = NULL;
    data_02104b10[0] = NULL;
}
