cmake_minimum_required(VERSION 3.5)


project(text)
add_executable(text test.cpp)

message(STATUS "GHANSHAM")
message(STATUS "cmake current source ==>" "${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "project source ==>" "${PROJECT_SOURCE_DIR}")
message(STATUS "cmake source ==>" "${CMAKE_SOURCE_DIR}")
message(STATUS "cmake binary ==>" "${CMAKE_BINARY_DIR}")
message(STATUS "cmake root ==>" "${CMAKE_ROOT}")

find_package(BZip2)
message(STATUS "${CMAKE_MODULE_PATH}")
message(STATUS "${BZIP2_FOUND}")
message(STATUS "${BZIP2_INCLUDE_DIR}")
message(STATUS "${BZIP2_LIBRARIES}")
message(STATUS "${BZIP2_NEED_PREFIX}")
message(STATUS "${BZIP2_VERSION_STRING}")

find_package(GTest)
message(STATUS "Gtest found: " "${GTest_FOUND}")
message(STATUS "GTest Include: " "${GTest_INCLUDE_DIR}")
message(STATUS "Gtest Libraries: " "${GTest_LIBRARIES}")

set(STRING_VARIABLE "value")
set(LIST_VARIABLE "value1 value2")

message("The string value is: ${STRING_VARIABLE}")
message("The list value is: ${LIST_VARIABLE}")

## cmake -DCMAKE_CXX_FLAGS_DEBUG=ON -DCMAKE_CXX_FLAGS_RELEASE=True .. <===  this line will override the below variables default value.
message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")

