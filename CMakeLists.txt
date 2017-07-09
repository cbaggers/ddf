cmake_minimum_required(VERSION 3.0)

project(dump_dump_fbx)

# -pedantic
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# {TODO} this is bad practice. look int find_library and how
#        we can use this with fbx. Maybe this link will help:
#        https://gist.github.com/bundai223/5238322
LINK_DIRECTORIES(/usr/local/lib/fbx/lib/gcc4/x64/debug/)

# Source fles for the binary
set(binary_SOURCES
  exporters.cpp
  enumConversion.cpp
  node.cpp
  attribute.cpp
  character.cpp
  surfacematerial.cpp
  controlSet.cpp
  layer.cpp
  main.cpp
)

# Add an executable with the above sources
add_executable(dumbdump ${binary_SOURCES})

target_include_directories(dumbdump
  SYSTEM
  PUBLIC /usr/local/lib/fbx/include/
)

target_include_directories(dumbdump
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# link the new hello_library target with the dumbdump target
target_link_libraries( dumbdump
    PRIVATE -lfbxsdk -ldl
)
