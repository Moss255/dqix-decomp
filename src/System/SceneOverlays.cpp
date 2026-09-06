#include <globaldefs.h>
#include "System/SceneOverlays.h"

extern "C"
{
    extern const SceneEntry data_020e8f20[];

    extern unsigned char data_01ffd340;  // an overlay operation is in flight
    extern unsigned char data_01ffd344;  // the guard below is in use
    extern int data_01ffd348;            // current slot bank
    extern char data_01ffd34c[];         // guard taken around a slot write
    extern signed char data_01ffd364[];  // six slots per bank
    extern char data_01ffd394[];         // 0x2c of overlay info per scene

    // Yields until the caller can make progress.
    void func_020d9834(int);

    // The same pair SafeAllocator brackets its work with.
    void func_020d970c();
    void func_020d974c();

    void func_020c8074(void* guard);
    void func_020c80f8(void* guard);

    void func_020cd27c(void* overlay); // load
    void func_020cd3a0(void* overlay); // start
    void func_020cd584(void* overlay); // release
}

// USA: func_020a18f4
ARM bool IsSceneLoaded(unsigned int scene)
{
    bool loaded = false;

    if (scene < SCENE_COUNT)
    {
        const signed char* slots = &data_01ffd364[data_01ffd348 * 6];
        loaded = slots[data_020e8f20[scene].group] == scene;
    }

    return loaded;
}
