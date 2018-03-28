cmake_minimum_required(VERSION 2.8)

project(boost_program)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR/bin})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++11 -Wall -Wextra")

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")
#include_directories("$ENV{ROS2_INCLUDE_PATH}")
#include_directories("$ENV{THREAD_POOL_PATH}")

#LINK_DIRECTORIES("$ENV{ROS2_LIB_PATH}")

add_executable(boost_test chrono.cpp)
set(LIBS
  boost_thread
  boost_system
  pthread)
TARGET_LINK_LIBRARIES( boost_test ${LIBS})

#TARGET_LINK_LIBRARIES(daisychain_single daisychain_multi
#  rclcpp
#  rcutils
#  rcl
#  sensor_msgs__rosidl_typesupport_cpp
#  sensor_msgs__rosidl_typesupport_introspection_cpp
#  rosidl_typesupport_cpp
#  std_msgs__rosidl_typesupport_cpp
#  boost_thread
#  boost_system
#  pthread)

