cmake_minimum_required(VERSION 3.8)
project(xib2nib)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(external/PlistCpp)
include_directories(stubs/xib2nib/)

file(GLOB xib2nib_SRC "src/*.cpp")
set(SOURCE_FILES ${xib2nib_SRC})


#include_directories(src src/nsplist src/plistcpp src/pugixml src/includes)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-write-strings")

add_executable(xib2nib ${SOURCE_FILES})
target_link_libraries(xib2nib PlistCpp)
install(TARGETS xib2nib RUNTIME DESTINATION bin)
