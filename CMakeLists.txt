cmake_minimum_required (VERSION 3.1)
set (CMAKE_CXX_STANDARD 11)


project (D3D11Forensics)
include (CTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Make the VBF executable
link_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(VBF VBForensic.cpp)
target_link_libraries(VBF)



set(CBFSourceFiles
    Const/ConstBuffer.cpp
    CBForensic.cpp
)

set(CBFHeaderFiles
    Const/ConstBuffer.h
)

# Make the CBF executable
add_executable(CBF ${CBFHeaderFiles} ${CBFSourceFiles})
target_link_libraries(CBF)


set(VBFSourceFiles
    Vertex/VertexBuffer.cpp
    VBConvert.cpp
)

set(VBFHeaderFiles
    Vertex/VertexBuffer.h
)
add_executable(VBConverter ${VBFHeaderFiles} ${VBFSourceFiles})
target_link_libraries(VBConverter)
