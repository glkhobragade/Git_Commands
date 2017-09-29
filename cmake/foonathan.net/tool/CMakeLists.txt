cmake_minimum_required(VERSION 3.0)
project(MY_LIBRARY)

add_executable(my_library_tool tool.cpp)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	SET(CMAKE_INSTALL_PREFIX ../runtime/ CACHE PATH "this is new path" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

# in tool/CMakeLists.txt
install(TARGETS my_library_tool DESTINATION "${tool_dest}")


