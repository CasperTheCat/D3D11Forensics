#include <iostream>
#include <fstream>

void PrintWindowAsFloat(char * data, unsigned long long window)
{
    std::cout << std::endl << "Window As Float" << std::endl;
    std::cout << "--=--=--=--=-==-=--=--=--=--" << std::endl;
    // Only cast once
    const float * fDat = reinterpret_cast<float *>(data);
    for(uint64_t i = 0; i < window / sizeof(float); ++i)
    {
        std::cout << fDat[i] << " ";
        if((i + 1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintWindowAsInt(char * data, unsigned long long window)
{
    std::cout << std::endl << "Window As Int" << std::endl;
    std::cout << "--=--=--=--=-==-=--=--=--=--" << std::endl;
    // Only cast once
    const auto iDat = reinterpret_cast<int *>(data);
    for(uint64_t i = 0; i < window / sizeof(int); ++i)
    {
        std::cout << iDat[i] << " ";
        if((i + 1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintWindowAsShort(char * data, unsigned long long window)
{
    std::cout << std::endl << "Window As Short" << std::endl;
    std::cout << "--=--=--=--=-==-=--=--=--=--" << std::endl;
    // Only cast once
    const auto sDat = reinterpret_cast<short *>(data);
    for(uint64_t i = 0; i < window / sizeof(short); ++i)
    {
        std::cout << sDat[i] << " ";
        if((i + 1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

void PrintWindowAsUInt8(char * data, unsigned long long window)
{
    std::cout << std::endl << "Window As UInt8" << std::endl;
    std::cout << "--=--=--=--=-==-=--=--=--=--" << std::endl;
    // Only cast once
    const auto sDat = reinterpret_cast<uint8_t *>(data);
    for(uint64_t i = 0; i < window / sizeof(uint8_t); ++i)
    {
        std::cout << static_cast<short>(sDat[i]) << " ";
        if((i + 1) % 4 == 0) std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    unsigned long long offset = 0;
    unsigned long long window = 0;
    unsigned long long nWindows = 1;
    if(argc < 2) return 1;
    if(argc > 2)
        offset = std::stoull(argv[2]);
    if(argc > 3)
        window = std::stoull(argv[3]);
    if(argc > 4)
        nWindows = std::stoull(argv[4]);


    std::ifstream buffer(argv[1], std::ifstream::binary | std::ios::ate);
    

    size_t bufferSize = buffer.tellg();
    buffer.seekg(0);

    // Allocate
    auto data = new char[bufferSize];

    buffer.read(data, bufferSize);
    buffer.close();

    // Cast Data and skip
    // Sanity Check
    for(uint64_t i = 0; i < nWindows; ++i)
    {
        if((offset + i * window) > bufferSize)
        {
            std::cout << "[WARN] Some of the window is off the end of the buffer" << std::endl;
        }
        else if(window % sizeof(float) != 0)
        {
            std::cout << "[WARN] Window size is not a multiple of single precision size" << std::endl;
        }
        else
            PrintWindowAsFloat(data + offset + (i * window), window);
    }



    // Cast Data and skip
    // Sanity Check
    for(uint64_t i = 0; i < nWindows; ++i)
    {
        if((offset + i * window) > bufferSize)
        {
            std::cout << "[WARN] Some of the window is off the end of the buffer" << std::endl;
        }
        else if(window % sizeof(int) != 0)
        {
            std::cout << "[WARN] Window size is not a multiple of integer size" << std::endl;
        }
        else if(offset + window % sizeof(float) != 0)
        {
            std::cout << "[WARN] Buffer may be misaligned" << std::endl;
        }
        else
            PrintWindowAsInt(data + offset + (i * window), window);
    }

    // Cast Data and skip
    // Sanity Check
    for(uint64_t i = 0; i < nWindows; ++i)
    {
        if((offset + i * window) > bufferSize)
        {
            std::cout << "[WARN] Some of the window is off the end of the buffer" << std::endl;
        }
        else if(window % sizeof(short) != 0)
        {
            std::cout << "[WARN] Window size is not a multiple of short size" << std::endl;
        }
        else
            PrintWindowAsShort(data + offset + (i * window), window);
    }

        for(uint64_t i = 0; i < nWindows; ++i)
    {
        if((offset + i * window) > bufferSize)
        {
            std::cout << "[WARN] Some of the window is off the end of the buffer" << std::endl;
        }
        else if(window % sizeof(unsigned char) != 0)
        {
            std::cout << "[WARN] Window size is not a multiple of short size" << std::endl;
        }
        else
            PrintWindowAsUInt8(data + offset + (i * window), window);
    }

    return 0;


    // Cast Data and skip
    // Sanity Check
    if(offset + window > bufferSize)
    {
        std::cout << "[WARN] Some of the window is off the end of the buffer" << std::endl;
    }
    else if(window % sizeof(float) != 0)
    {
        std::cout << "[WARN] Window size is not a multiple of single precision size" << std::endl;

    }
    else
        PrintWindowAsFloat(data + offset, window);
}