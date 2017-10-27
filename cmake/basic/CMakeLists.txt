cmake_minimum_required(VERSION 3.5)


project(text)


set(COMPONENT_VERSION 3.1.2)
SET(PACKAGE_VERSION "${COMPONENT_VERSION}")

add_executable(text test.cpp)
add_library(sqrt  SHARED sqrt.cpp)

# below line activates the DEBUG flag in all the compilation command
# it can be checked whether it works in subdirectory as well.
## from website: Adds definitions to the compiler command line for targets in the current directory and below.

OPTION(MYDEB " This is option to enable or disable flag" OFF)
#run the command as below to enable the flag which is disabled by default using above line;
#cmake -DMYDEB=ON ..   or
#cmake -D CMAKE_COMPILE_DEFINITIONS="DEB"  ..   or
# cmake -D CMAKE_CXX_FLAGS="-DDEB" ..     #but this will override the other default flags for your compiler.


if(${MYDEB})
    add_definitions(-DDEB)
endif()

# the below lines will set the version number to the executable and library
# the link will be made accordingly using the original name(without version number)
set_target_properties(text PROPERTIES  VERSION "${COMPONENT_VERSION}")
set_target_properties(sqrt PROPERTIES  VERSION "${COMPONENT_VERSION}")
#set_target_properties(sqrt PROPERTIES  SUFFIX "dynamic")

set(GHANSHAM "RAMRAM")
message(STATUS "GHANSHAM")
message(STATUS "GHANSHAM" ${GHANSHAM})
message(STATUS "cmake current source ==>" "${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "project source ==>" "${PROJECT_SOURCE_DIR}")
message(STATUS "cmake source ==>" "${CMAKE_SOURCE_DIR}")
message(STATUS "cmake binary ==>" "${CMAKE_BINARY_DIR}")
message(STATUS "cmake root ==>" "${CMAKE_ROOT}")

find_package(my_library)
message(STATUS "my library found? ==> " "${my_library_FOUND}")
message(STATUS "my library include ==>" "${my_library_INCLUDE_DIR}")
#include_directories("${my_library_INCLUDE_DIR}")

set(CMAKE_PREFIX_PATH "/home/ghansham/Programs/Git_Commands/cmake/foonathan.net/runtime/lib/my_library-1.0/")
find_package(BZip2)
message(STATUS "module_path ==>" "${CMAKE_MODULE_PATH}")
message(STATUS "config file path==>" "${BZIP2_CONFIG}")
message(STATUS "${BZIP2_FOUND}")
message(STATUS "${BZIP2_INCLUDE_DIR}")
message(STATUS "${BZIP2_LIBRARIES}")
message(STATUS "${BZIP2_NEED_PREFIX}")
message(STATUS "${BZIP2_VERSION_STRING}")

find_package(GTest)
message(STATUS "Gtest found: " "${GTest_FOUND}")
message(STATUS "GTest Include: " "${GTest_INCLUDE_DIR}")
message(STATUS "Gtest Libraries: " "${GTest_LIBRARIES}")


find_package(Boost)
message(STATUS "Boost found: " "${Boost_FOUND}")
message(STATUS "Boost Include: " "${Boost_INCLUDE_DIR}")
message(STATUS "Boost Libraries: " "${Boost_LIBRARIES}")
message(STATUS "Boost Libraries_Dir: " "${Boost_LIBRARY_DIRS}")

set(STRING_VARIABLE "value")
set(LIST_VARIABLE "value1 value2")

message("The string value is: ${STRING_VARIABLE}")
message("The list value is: ${LIST_VARIABLE}")
message("The lib is: ${LIBS}")

## cmake -DCMAKE_CXX_FLAGS_DEBUG=ON -DCMAKE_CXX_FLAGS_RELEASE=True .. <===  this line will override the below variables default value.
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")

add_subdirectory(subdir)
