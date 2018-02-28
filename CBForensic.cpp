#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
    if(argc < 3) return 1;
    uint64_t convertCode = std::stoull(argv[2]);

    std::ifstream buffer(argv[1], std::ifstream::binary | std::ios::ate);

    size_t bufferSize = buffer.tellg();
    buffer.seekg(0);

    // Allocate
    auto data = new char[bufferSize];

    buffer.read(data, bufferSize);
    buffer.close();
    
}