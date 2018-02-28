#include "VertexBuffer.h"
#include <iostream>

NIER_AUTOMATA_NS_START

int CastToSkeletalVB
(
    char *pArray,
    uint64_t bufferLength,
    NierAutomataSkeletalVB * &pReturn
)
{
    pReturn = nullptr; // Safety
    
    if(bufferLength % sizeof(NierAutomataSkeletalVB) != 0) return EXIT_FAILURE;

    pReturn = reinterpret_cast<NierAutomataSkeletalVB*>(pArray);

    return EXIT_SUCCESS;
}

void PrintPrettySkeletalVBElement
(
    NierAutomataSkeletalVB * pArray,
    uint64_t elementIdx
)
{
    std::cout << "X\t\tY\t\tZ" << std::endl;
    std::cout << pArray[elementIdx].x << "\t" <<
        pArray[elementIdx].y << "\t" <<
        pArray[elementIdx].z << std::endl;
    
    std::cout << "U\t\tV" << std::endl;
    std::cout << pArray[elementIdx].u << "\t" << 
        pArray[elementIdx].v << std::endl;
}
NIER_AUTOMATA_NS_END
