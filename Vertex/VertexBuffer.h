#include "Macro.h"
#include <stdlib.h>
#include <stdint.h>

/////////////////////////////////////////////////////////////////////
// Nier Automata
//
NIER_AUTOMATA_NS_START
    ///////
    // Skeletal Meshes
    /////
    struct NierAutomataSkeletalVB
    {
        float x;
        float y;
        float z;
        uint8_t unknown1[4];
        float u;
        float v;
        uint8_t unknown2[4];
    };

    int CastToSkeletalVB(char *pArray, uint64_t bufferLength, NierAutomataSkeletalVB * &pReturn);
    void PrintPrettySkeletalVBElement(NierAutomataSkeletalVB * pArray, uint64_t elementIdx);

NIER_AUTOMATA_NS_END

